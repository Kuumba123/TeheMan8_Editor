#!/usr/bin/env python3
"""Copy one enemy from one Mega Man 8 stage into another, working on the extracted disc files.

    mm8_inject.py <files dir> <closures.json> <source stage> <target stage> <id> <out dir> [--spawn X,Y[,VAR]]

<files dir> holds SLUS_004.53, OVL/ and STDATA/ as on the disc. Stages are 00..0D. <id> is the main-pool
enemy ID in hex. Writes OVL/STAGEtt.BIN, STDATA/STAGEtt.PAC (and STAGEttB.PAC when it exists) and
SLUS_004.53 into <out dir>:

- the enemy's code and its overlay's data blocks are appended to the target overlay, relocated to their new
  address, and the target's handler table slot for <id> points at the copy;
- the enemy's sprite bank (from the property table in PSX.EXE) gets the source stage's frames appended to
  PAC entry 5, its entry 6/7/8 slots filled, its tiles copied into free tiles of entry 0x102 (remapped) and
  its palettes into free palette slots of entry 9;
- the overlay and PAC sizes in PSX.EXE's file table are updated. The LBAs are not: putting the bigger files
  on the disc and fixing the LBAs is the disc rebuild's job;
- with --spawn, a record for the enemy is added to the target's enemy list (PAC entry 0x0A).

Stops with an error rather than guessing when something does not fit or cannot be relocated.
"""
import sys, os, json, struct

OB = 0x801D8000
OVL_LIMIT = 0x801F923C        # end of STAGE0D.BIN, the largest overlay the game loads
E5_LIMIT = 0x8009E000 - 0x80078000   # entry 5 lives at 0x80078000, the next PAC destination is 0x8009E000
EXE_TEXT = 0x800C0000
PROPS = 0x801393B4            # per-ID {bank, hp, contact damage, damage table}
FILE_TABLE = 0x80136F7C       # 12 bytes per disc file: LBA, size, ?
NEWBASE = 0xC00               # tile base given to the injected bank (tiles 0xC00..0xFFF of entry 0x102)

class InjectError(Exception): pass

# ---------------------------------------------------------------- PAC files
def pac_read(path):
    d = open(path, 'rb').read()
    n = struct.unpack_from('<I', d, 0)[0]
    out, o = [], 0x800
    for i in range(n):
        t, s = struct.unpack_from('<II', d, 8 + i * 8)
        out.append([t, bytearray(d[o:o + s])]); o += (s + 0x7FF) & ~0x7FF
    return out

def pac_write(path, entries):
    body = b''.join(bytes(e[1]) + b'\0' * (-len(e[1]) % 0x800) for e in entries)
    hdr = struct.pack('<II', len(entries), 0x800 + len(body)) + b''.join(struct.pack('<II', t, len(d)) for t, d in entries)
    open(path, 'wb').write(hdr + b'\0' * (0x800 - len(hdr)) + body)

def pac_get(entries, t):
    for e in entries:
        if e[0] == t: return e[1]
    raise InjectError('PAC has no entry %X' % t)

# ---------------------------------------------------------------- relocation
def sx(v): return v - 0x10000 if v & 0x8000 else v
BRANCH = (1, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17)

def relocate(src, funcs, blocks, new_base):
    """funcs: [[min, max_exclusive, entry]...] of the enemy's overlay functions; blocks: data blocks copied whole."""
    src_end = OB + len(src)
    entries = set(f[2] for f in funcs)
    code = []
    for a, b, _ in sorted(funcs):
        b = (b + 3) & ~3
        if code and a <= code[-1][1] + 0x10: code[-1][1] = max(code[-1][1], b)
        else: code.append([a, b])
    layout, cur = [], new_base
    for a, b in code + [list(x) for x in blocks]:
        layout.append((a, b, cur)); cur += (b - a + 3) & ~3
    def reloc(t, soft=False):
        for a, b, n in layout:
            if a <= t < b: return t - a + n
        if OB <= t < src_end and not soft: raise InjectError('reference to %08X is outside the copied code and data' % t)
        return t
    blobs = [bytearray(src[a - OB:b - OB]) for a, b, n in layout]
    for (a, b, n), blob in zip(layout[:len(code)], blobs):
        hi, pend, users = {}, {}, []
        for pc in range(a, b, 4):
            if pc in entries or pc == a: hi, pend = {}, {}
            o = pc - a; w = struct.unpack_from('<I', blob, o)[0]
            op, rs, rt, rd, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, w & 0xFFFF
            if op in (2, 3):                              # j / jal
                t = (pc & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
                if OB <= t < 0x80200000:
                    struct.pack_into('<I', blob, o, (w & 0xFC000000) | ((reloc(t) >> 2) & 0x3FFFFFF))
                continue
            if op == 0x0F: hi[rt] = imm; pend[rt] = pc; continue       # lui
            if op == 0 and (w & 0x3F) in (0x20, 0x21) and ((rs in hi) != (rt in hi)):   # addu of an index
                r = rs if rs in hi else rt; hi[rd] = hi[r]; pend[rd] = pend[r]; continue
            if (op in (0x08, 0x09, 0x0D) or 0x20 <= op <= 0x2E) and rs in hi:   # low half: addiu/ori/load/store
                t = ((hi[rs] << 16) + (imm if op == 0x0D else sx(imm))) & 0xFFFFFFFF
                if OB <= t < 0x80200000: users.append((pc, t, pend[rs]))
            if op == 0 and rd in hi: del hi[rd]
            elif op not in (0, 0x28, 0x29, 0x2A, 0x2B, 0x2E) + BRANCH and rt in hi: del hi[rt]
        by_lui = {}
        for pc, t, lp in users: by_lui.setdefault(lp, []).append((pc, t))
        for lp, us in by_lui.items():
            d = set(reloc(t) - t for _, t in us)
            if len(d) != 1: raise InjectError('lui at %08X feeds addresses that move differently' % lp)
            d = d.pop(); his = set()
            for pc, t in us:
                w = struct.unpack_from('<I', blob, pc - a)[0]
                struct.pack_into('<I', blob, pc - a, (w & 0xFFFF0000) | ((t + d) & 0xFFFF))
                his.add(((t + d + 0x8000) >> 16) & 0xFFFF)
            if len(his) != 1: raise InjectError('lui at %08X needs two different high halves' % lp)
            w = struct.unpack_from('<I', blob, lp - a)[0]
            struct.pack_into('<I', blob, lp - a, (w & 0xFFFF0000) | his.pop())
    for (a, b, n), blob in zip(layout[len(code):], blobs[len(code):]):
        for o in range(0, len(blob) - 3, 4):
            v = struct.unpack_from('<I', blob, o)[0]
            if OB <= v < src_end: struct.pack_into('<I', blob, o, reloc(v, soft=True))
    image = bytearray()
    for (a, b, n), blob in zip(layout, blobs):
        image += b'\0' * (n - new_base - len(image)) + blob
    return image, reloc

# ---------------------------------------------------------------- sprite bank
def bank_span(e5, e6, b):
    nb = len(e6) // 4
    offs = [struct.unpack_from('<I', e6, k * 4)[0] for k in range(nb)] + [len(e5)]
    return offs[b], min(o for o in offs if o > offs[b])

def used_tiles(e5, e6, e7):
    nb = len(e7) // 2; used = set()
    offs = [struct.unpack_from('<I', e6, b * 4)[0] for b in range(nb)] + [len(e5)]
    for b in range(nb):
        if offs[b + 1] <= offs[b]: continue
        tb = struct.unpack_from('<H', e7, b * 2)[0]
        for f in range(struct.unpack_from('<HH', e5, offs[b])[1] // 4):
            cnt, qo = struct.unpack_from('<HH', e5, offs[b] + f * 4)
            for q in range(cnt): used.add(tb + (struct.unpack_from('<H', e5, offs[b] + qo + q * 4)[0] & 0x3FF))
    return used

def tile_off(t, ln):        # entry 0x102 is VRAM (512,0): eight 64-halfword columns of 256 lines
    p, r, c = (t >> 8) - 8, (t >> 4) & 0xF, t & 0xF
    if not 0 <= p < 8: raise InjectError('tile %X is not in the stage texture (entry 0x102)' % t)
    return p * 0x8000 + (r * 16 + ln) * 128 + c * 8

def tile_get(tex, t): return b''.join(tex[tile_off(t, ln):tile_off(t, ln) + 8] for ln in range(16))
def tile_put(tex, t, px):
    for ln in range(16): tex[tile_off(t, ln):tile_off(t, ln) + 8] = px[ln * 8:ln * 8 + 8]

def clut(pal, row, x): return pal[(row * 256 + x * 16) * 2:(row * 256 + x * 16 + 16) * 2]

def copy_bank(sp, dp, bank, log):
    e5s, e6s, e7s, e8s, pals, texs = (pac_get(sp, t) for t in (5, 6, 7, 8, 9, 0x102))
    e5, e6, e7, e8, pal, tex = (pac_get(dp, t) for t in (5, 6, 7, 8, 9, 0x102))
    if bank * 4 >= len(e6): raise InjectError('target stage has no slot for bank %X' % bank)
    a, b = bank_span(e5s, e6s, bank)
    if b <= a: raise InjectError('source stage has no frames for bank %X' % bank)
    da, db = bank_span(e5, e6, bank)
    if db > da and struct.unpack_from('<H', e7, bank * 2)[0]:
        log.append('bank %X already in the target, graphics left alone' % bank); return
    frames = bytearray(e5s[a:b]); tb = struct.unpack_from('<H', e7s, bank * 2)[0]; c = e8s[bank]
    used = used_tiles(e5, e6, e7)
    free = [t for t in range(NEWBASE, 0x1000) if t not in used and not any(tile_get(tex, t))]
    remap, ncl = {}, 1
    for f in range(struct.unpack_from('<HH', frames, 0)[1] // 4):
        cnt, qo = struct.unpack_from('<HH', frames, f * 4)
        for q in range(cnt):
            w, = struct.unpack_from('<H', frames, qo + q * 4)
            st = tb + (w & 0x3FF)
            if st not in remap:
                if not free: raise InjectError('not enough free tiles in the target stage')
                remap[st] = free.pop(0)
            ncl = max(ncl, ((w >> 11) & 3) + 1)
            struct.pack_into('<H', frames, qo + q * 4, (w & ~0x3FF) | (remap[st] - NEWBASE))
    slot = None
    for row in range(4):
        for x in range(16 - ncl + 1):
            if all(not any(clut(pal, row, x + k)) for k in range(ncl)): slot = (row, x); break
        if slot: break
    if not slot: raise InjectError('no free palette slots in the target stage')
    if len(e5) + len(frames) > E5_LIMIT: raise InjectError('sprite frames would not fit in RAM')
    off = (len(e5) + 3) & ~3
    e5 += b'\0' * (off - len(e5)) + frames
    struct.pack_into('<I', e6, bank * 4, off)
    struct.pack_into('<H', e7, bank * 2, NEWBASE)
    e8[bank] = (slot[0] << 4) | slot[1]
    for k in range(ncl):
        o = (slot[0] * 256 + (slot[1] + k) * 16) * 2
        pal[o:o + 32] = clut(pals, (c >> 4) & 3, (c & 0xF) + k)
    for st, dt in remap.items(): tile_put(tex, dt, tile_get(texs, st))
    log.append('bank %X: %d frame bytes at entry 5 +0x%X, %d tiles, palette row %d x%d (%d)' %
               (bank, len(frames), off, len(remap), slot[0], slot[1], ncl))

# ---------------------------------------------------------------- main
def main():
    a = sys.argv[1:]
    spawn = None
    if '--spawn' in a:
        i = a.index('--spawn'); spawn = [int(x, 0) for x in a[i + 1].split(',')]; del a[i:i + 2]
    files, clpath, s, t, eid, out = a[0], a[1], a[2].upper(), a[3].upper(), int(a[4], 16), a[5]
    cl = json.load(open(clpath))
    exe = bytearray(open(os.path.join(files, 'SLUS_004.53'), 'rb').read())
    def exe_off(addr): return addr - EXE_TEXT + 0x800
    src = open(os.path.join(files, 'OVL', 'STAGE%s.BIN' % s), 'rb').read()
    dst = bytearray(open(os.path.join(files, 'OVL', 'STAGE%s.BIN' % t), 'rb').read())
    log = []
    ent = cl['STAGE' + s]['enemies'].get('%02X' % eid)
    tgt = cl['STAGE' + t]
    if ent is None: raise InjectError('ID %02X has no overlay code in STAGE%s' % (eid, s))
    if tgt['enemies'].get('%02X' % eid): log.append('note: STAGE%s already has its own code for ID %02X; replacing the slot' % (t, eid))
    funcs = [[int(f[0], 16), int(f[1], 16), int(f[2], 16)] for f in ent['funcs']]
    blocks = [[int(x, 16), int(y, 16)] for x, y in cl['STAGE' + s]['data_blocks']]
    new_base = (OB + len(dst) + 15) & ~15
    image, reloc = relocate(src, funcs, blocks, new_base)
    if new_base + len(image) > OVL_LIMIT: raise InjectError('target overlay would end at %08X, past %08X' % (new_base + len(image), OVL_LIMIT))
    dst += b'\0' * (new_base - OB - len(dst)) + image
    slot = int(tgt['main_table'], 16) - OB + eid * 4
    struct.pack_into('<I', dst, slot, reloc(int(ent['handler'], 16)))
    log.append('code+data: %d bytes at %08X, handler %08X' % (len(image), new_base, reloc(int(ent['handler'], 16))))
    bank = exe[exe_off(PROPS + eid * 4)]
    sp = pac_read(os.path.join(files, 'STDATA', 'STAGE%s.PAC' % s))
    pacs = ['STAGE%s.PAC' % t] + (['STAGE%sB.PAC' % t] if os.path.exists(os.path.join(files, 'STDATA', 'STAGE%sB.PAC' % t)) else [])
    os.makedirs(os.path.join(out, 'OVL'), exist_ok=True); os.makedirs(os.path.join(out, 'STDATA'), exist_ok=True)
    names = cl['disc_files']
    for pn in pacs:
        dp = pac_read(os.path.join(files, 'STDATA', pn))
        copy_bank(sp, dp, bank, log)
        if spawn:
            lst = pac_get(dp, 0x0A); i = 0
            while lst[i * 8 + 3] != 0xFF: i += 1
            if (i + 2) * 8 > len(lst): raise InjectError('enemy list is full')
            var = spawn[2] if len(spawn) > 2 else 0
            lst[i * 8:i * 8 + 16] = struct.pack('<BBBBhh', 0, eid, var, 1, spawn[0], spawn[1]) + struct.pack('<BBBBhh', 0, 0, 0, 0xFF, 0, 0)
            log.append('%s: spawn record %d at %d,%d' % (pn, i, spawn[0], spawn[1]))
        pac_write(os.path.join(out, 'STDATA', pn), dp)
        k = names.index('LBA_%s_PAC' % pn[:-4])
        struct.pack_into('<I', exe, exe_off(FILE_TABLE + k * 12 + 4), os.path.getsize(os.path.join(out, 'STDATA', pn)))
    open(os.path.join(out, 'OVL', 'STAGE%s.BIN' % t), 'wb').write(dst)
    k = names.index('LBA_STAGE%s_BIN' % t)
    struct.pack_into('<I', exe, exe_off(FILE_TABLE + k * 12 + 4), len(dst))
    open(os.path.join(out, 'SLUS_004.53'), 'wb').write(exe)
    print('\n'.join(log))

if __name__ == '__main__':
    try: main()
    except InjectError as e: sys.exit('error: %s' % e)
