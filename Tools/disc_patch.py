#!/usr/bin/env python3
"""Write mm8_inject.py output onto a copy of the Mega Man 8 (USA) track 1 image, without rebuilding the
filesystem.

    disc_patch.py <original track 1 .bin> <new track 1 .bin> <injector out dir> <closures.json>

The game finds its files through the table in PSX.EXE (0x80136F7C, 12 bytes per file: LBA, size, ?),
not through the ISO9660 directory, so:
- a file that still fits in its old sectors is written in place;
- a file that grew is written into the free sectors between the last data file and the end of track 1
  (150 sectors on the USA disc), and its LBA in the PSX.EXE table is changed;
- PSX.EXE itself (same size) is written in place.
The ISO9660 directory keeps the old LBA/size; the game never reads it for these files.
Each written sector gets its EDC/ECC recomputed (checked first against an untouched sector).
"""
import sys, os, json, struct, shutil

orig, outp, inj, clp = sys.argv[1:5]
names = json.load(open(clp))['disc_files']
TABLE, TEXT = 0x80136F7C, 0x800C0000
def exe_off(addr): return addr - TEXT + 0x800

# ---- EDC / ECC for Mode 2 Form 1 sectors (ECMA-130)
EDC = []
for i in range(256):
    e = i
    for _ in range(8): e = (e >> 1) ^ (0xD8018001 if e & 1 else 0)
    EDC.append(e)
F = [0] * 256; B = [0] * 256
for i in range(256):
    j = (i << 1) ^ (0x11D if i & 0x80 else 0); F[i] = j; B[i ^ j] = i
def edc(b):
    e = 0
    for x in b: e = (e >> 8) ^ EDC[(e ^ x) & 0xFF]
    return e
def ecc_block(sec, major, minor, mmult, step, out):
    size = major * minor
    for m in range(major):
        idx = (m >> 1) * mmult + (m & 1); a = b = 0
        for n in range(minor):
            t = sec[0xC + idx]; idx += step
            if idx >= size: idx -= size
            a ^= t; b ^= t; a = F[a]
        a = B[F[a] ^ b]; sec[out + m] = a; sec[out + m + major] = a ^ b
def fix_sector(sec):
    struct.pack_into('<I', sec, 0x818, edc(bytes(sec[0x10:0x818])))
    hdr = bytes(sec[0xC:0x10]); sec[0xC:0x10] = b'\0\0\0\0'      # Mode 2 ECC is computed with a zero header
    ecc_block(sec, 86, 24, 2, 86, 0x81C); ecc_block(sec, 52, 43, 86, 88, 0x8C8)
    sec[0xC:0x10] = hdr

shutil.copyfile(orig, outp)
f = open(outp, 'r+b')
nsec = os.path.getsize(orig) // 2352
def read_file(lba, size):
    f.seek(lba * 2352); raw = f.read(2352 * ((size + 2047) // 2048))
    return b''.join(raw[i * 2352 + 24:i * 2352 + 24 + 2048] for i in range(len(raw) // 2352))[:size]
def write_file(lba, data):
    for i in range(0, len(data), 2048):
        f.seek((lba + i // 2048) * 2352); sec = bytearray(f.read(2352))
        chunk = data[i:i + 2048]; sec[24:24 + 2048] = chunk + b'\0' * (2048 - len(chunk))
        fix_sector(sec); f.seek((lba + i // 2048) * 2352); f.write(sec)

exe_lba = 23   # SLUS_004.53, and the first entry of its own table
f.seek(exe_lba * 2352); s0 = bytearray(f.read(2352)); s1 = bytearray(s0); fix_sector(s1)
assert s0 == s1, 'EDC/ECC code does not reproduce an original sector'
old_exe = read_file(exe_lba, struct.unpack_from('<I', read_file(exe_lba, 0x800 + 0x100000), exe_off(TABLE) + 4)[0])
assert old_exe[:8] == b'PS-X EXE'
table = [struct.unpack_from('<III', old_exe, exe_off(TABLE) + k * 12) for k in range(len(names))]
free = max(l + (s + 2047) // 2048 for l, s, _ in table if l < nsec)
exe = bytearray(open(os.path.join(inj, 'SLUS_004.53'), 'rb').read())
assert len(exe) == len(old_exe)
for sub in ('OVL', 'STDATA'):
    d = os.path.join(inj, sub)
    if not os.path.isdir(d): continue
    for fn in sorted(os.listdir(d)):
        base, ext = fn.split('.')
        k = names.index('LBA_%s_%s' % (base, ext)); lba, size, _ = table[k]
        data = open(os.path.join(d, fn), 'rb').read()
        if (len(data) + 2047) // 2048 > (size + 2047) // 2048:
            need = (len(data) + 2047) // 2048
            if free + need > nsec: sys.exit('not enough free sectors at the end of track 1')
            lba = free; free += need
            struct.pack_into('<I', exe, exe_off(TABLE) + k * 12, lba)
        write_file(lba, data)
        assert read_file(lba, len(data)) == data
        print('%s/%s: %d bytes at LBA %d' % (sub, fn, len(data), lba))
write_file(exe_lba, bytes(exe))
assert read_file(exe_lba, len(exe)) == bytes(exe)
print('SLUS_004.53 written in place')
