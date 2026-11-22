# Stage overlays

The stage-specific enemy code lives in the 15 files under `OVL/` on the disc.
Only a handful of enemies that appear everywhere (Mets, Bunby Tank and a few others) have their code in
PSX.EXE.

All addresses are for the NTSC-U disc (SLUS-004.53).

## How an overlay gets loaded

`FUN_800fc648(n)` loads overlay number `n`:

- the disc file comes from the table at `0x8013761C` (one u32 per `n`), which is an index into the same
  12-byte-per-file LBA table at `0x80136F7C` that the editor already patches (`Const.FileDataAddress`).
  For `n` = 0..14 the indices are 8..22, i.e. `DEMO.BIN`, then `STAGE00.BIN` to `STAGE0D.BIN` in order.
- the file is always read to **`0x801D8000`**.
- `n` is stored in the byte at `0x801C738C`.
- the u32 at `0x80137658 + n*4` is copied to `0x801C73D0`. That is the overlay's per-frame entry point,
  which the main loop calls every frame through that pointer (see [Objects.md](Objects.md)).

So `STAGExx.BIN` is overlay `n = xx + 1`, and `DEMO.BIN` is `n = 0`.

Checked in PCSX-Redux: on the title screen attract mode `0x801D8000` holds `DEMO.BIN` byte for byte with
`0x801C738C` = 0, and in the intro highway stage it holds `STAGE00.BIN` byte for byte with `0x801C738C` = 1.
The other overlays were only checked statically (their internal `jal` targets only line up with their
function starts at base `0x801D8000`).

## Layout of an overlay file

There is no real header. The file is a raw memory image for `0x801D8000`. The first few words are
data (a small count followed by pointers into the overlay; I have not traced what reads them), and code
starts at the entry point given by the EXE table above. The two enemy dispatch tables
are near the end of the file.

## Per-overlay summary

"Main table" is the 98-entry (`0x62`) table of handlers for the main object pool, indexed by the object
ID (the `id` byte of an enemy-list entry with type 0 or 1). "Second table" is the matching table for the
type 2 pool. Both live inside the overlay, so the same ID can run completely different code in
different stages. Every ID with no code in a stage points to a small stub that just deletes the object.

IDs 00 and 03 have a handler in every overlay; 01, 02 and 61 in almost all of them. The last column
lists the rest.

| Overlay | n | Entry | Main table | Second table | Other IDs with code |
|---|---|---|---|---|---|
| STAGE00.BIN | 1 | 0x801D81B4 | 0x801E22E0 | 0x801E2468 | 01 02 04 06 07 61 |
| STAGE01.BIN | 2 | 0x801D802C | 0x801E6424 | 0x801E65AC | 01 02 05 09 0A 0B 0C 0D 0E 14 1F 22 2C 61 |
| STAGE02.BIN | 3 | 0x801D8054 | 0x801E8264 | 0x801E83EC | 01 02 08 0F 18 19 1D 20 21 2B 3D 40 45 4B 61 |
| STAGE03.BIN | 4 | 0x801D80AC | 0x801E9688 | 0x801E9810 | 01 02 09 0D 0E 11 12 13 17 1E 20 21 23 25 26 27 28 61 |
| STAGE04.BIN | 5 | 0x801D8004 | 0x801E6A2C | 0x801E6BB4 | 01 08 09 10 15 16 1A 1B 1C 20 21 22 24 2A 31 35 36 38 39 4B 61 |
| STAGE05.BIN | 6 | 0x801D80A8 | 0x801E9FDC | 0x801EA164 | 01 02 10 21 29 2B 2D 2F 31 32 33 34 44 4A 4C 4D 61 |
| STAGE06.BIN | 7 | 0x801D8128 | 0x801E5410 | 0x801E5598 | 01 02 07 13 1C 20 30 39 3A 3B 3E 3F 42 43 4B 53 61 |
| STAGE07.BIN | 8 | 0x801D805C | 0x801E0588 | 0x801E0710 | 01 02 20 2E 38 39 41 47 53 56 57 61 |
| STAGE08.BIN | 9 | 0x801D8034 | 0x801E0CEC | 0x801E0E74 | 01 02 13 2E 37 39 3C 46 48 49 54 61 |
| STAGE09.BIN | 10 | 0x801D8018 | 0x801DB784 | 0x801DB90C | 01 02 20 21 4B 4F 50 55 58 61 |
| STAGE0A.BIN | 11 | 0x801D8078 | 0x801E188C | 0x801E1A14 | 02 09 0A 0D 10 1B 20 21 51 52 60 61 |
| STAGE0B.BIN | 12 | 0x801D80D8 | 0x801E802C | 0x801E81B4 | 02 08 0E 11 17 1E 20 21 22 23 38 39 4B 53 59 60 61 |
| STAGE0C.BIN | 13 | 0x801D81AC | 0x801EA6F4 | 0x801EA87C | 01 02 09 13 1C 22 32 39 41 46 4B 4E 53 5D 5E 5F 61 |
| STAGE0D.BIN | 14 | 0x801D8048 | 0x801F7E38 | 0x801F7FC0 | 01 02 1F 27 28 2C 35 36 3A 3B 40 48 49 4C 4D 56 57 58 5A 5B 5C |

The boss IDs from the editor's list show which stage each overlay belongs to: Frost Man (1F) is in
STAGE01, Clown Man (40) in STAGE02, Tengu Man (27) in STAGE03, Grenade Man (35) in STAGE04, Sword Man
(4C) in STAGE05, Astro Man (56) in STAGE07, Search Man (48) in STAGE08, and STAGE0D has all of them
(the rematches).

[enemy-handlers.json](enemy-handlers.json) has the full per-overlay ID -> handler address list, including
each handler's state table where the code has one.

## Finding the tables in an overlay

If you need to find them in a modified overlay: the entry function loads each pool address followed by
its table address, as two `lui`/`addiu` pairs. For the main pool that is
`lui s1,0x8016 / addiu s1,s1,0xB174 / lui s2,hi / addiu s2,s2,lo`, and the table is `(hi << 16) + lo`
(sign-extended `lo`). The second table follows the same pattern with `0x801B1EEC` and is always
`0x188` bytes after the main one.
