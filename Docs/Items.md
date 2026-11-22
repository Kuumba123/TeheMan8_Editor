# Items, effects and the other spawnable objects

The enemy list can spawn into three more pools besides the main one (the type byte, see
[Objects.md](Objects.md)). In the editor's Lua overlay these are the blue (type 2, `0x801B1EEC`), purple
(type 3, `0x801CF848`) and pink (type 4, `0x801CF540`) boxes. Each one dispatches on the object ID at
`+0x06`, like the main pool.

## Type 2: items (`0x801B1EEC`, 0x20 slots of 0x50 bytes)

The handler table is the overlay's second table (addresses in [Overlays.md](Overlays.md)), so like
enemies the code can change per stage. It has 0x34 entries in most overlays and 0x30 in STAGE02 and
STAGE03, where data follows it. IDs without code in a stage all point at one stub function.

IDs with code anywhere, and where that code is (PSX.EXE means the same handler in every stage):

| ID | Name (editor) | Code |
|---|---|---|
| 00 | Item | PSX.EXE |
| 01 |  | STAGE00 |
| 02 |  | STAGE00 |
| 03 | Falling Platform | STAGE01, STAGE0A |
| 04 |  | STAGE01, STAGE0A |
| 05 | Snow Board | STAGE01, STAGE0A |
| 06 |  | STAGE00 |
| 07 |  | STAGE01 |
| 08 |  | STAGE01 |
| 09 |  | STAGE03 |
| 0A | Swinging Hammer | STAGE04 |
| 0B |  | STAGE02 |
| 0C |  | STAGE03, STAGE0B |
| 0D |  | STAGE04 |
| 0E |  | STAGE03, STAGE0B |
| 0F |  | STAGE03, STAGE0B |
| 10 |  | STAGE03, STAGE0B |
| 11 |  | STAGE02 |
| 12 |  | STAGE05 |
| 13 |  | STAGE03 |
| 14 |  | STAGE03 |
| 15 |  | STAGE02 |
| 16 |  | STAGE03 |
| 17 |  | STAGE02 |
| 18 |  | STAGE05 |
| 19 |  | STAGE05 |
| 1A |  | STAGE05 |
| 1B |  | STAGE05 |
| 1C |  | STAGE05 |
| 1D |  | STAGE05 |
| 1E |  | STAGE05 |
| 1F |  | STAGE05 |
| 20 |  | STAGE05 |
| 21 |  | STAGE05 |
| 22 | Boss Door | PSX.EXE |
| 23 |  | STAGE00 |
| 24 |  | STAGE05 |
| 25 | Bolt | PSX.EXE |
| 26 |  | PSX.EXE |
| 27 |  | STAGE06 |
| 28 |  | STAGE02, STAGE0D |
| 29 |  | STAGE07 |
| 2A |  | STAGE06 |
| 2B |  | STAGE07 |
| 2C |  | STAGE02 |
| 2D |  | STAGE07 |
| 2E |  | STAGE06 |
| 2F |  | PSX.EXE |
| 30 |  | STAGE08 |
| 31 |  | STAGE0B |
| 32 |  | STAGE0D |
| 33 |  | PSX.EXE |

## Type 4: effects (`0x801CF540`, 0x20 slots of 0x18 bytes)

The handler table is in PSX.EXE at `0x8015039C`, 0x34 entries. Some entries are not PSX.EXE code but
fixed addresses inside the overlay area: those handlers only exist while the overlay that has code at
that address is loaded, so an effect like that only works in the stages listed. "No function start
found" means no overlay has a normal function entry at that address; I did not dig further.

| ID | Name (editor) | Handler | Code |
|---|---|---|---|
| 00 |  | 0x80131B48 | PSX.EXE |
| 01 |  | 0x80131BDC | PSX.EXE |
| 02 |  | 0x80131C70 | PSX.EXE |
| 03 |  | 0x80131D28 | PSX.EXE |
| 04 | Checkpoint | 0x80131DE0 | PSX.EXE |
| 05 |  | 0x801E073C | overlay address, code in STAGE00 |
| 06 |  | 0x801E09F8 | overlay address, code in STAGE00 |
| 07 |  | 0x801E0B64 | overlay address, code in STAGE00 |
| 08 |  | 0x801E64B0 | overlay address, code in STAGE02 |
| 09 |  | 0x801E5290 | overlay address, code in STAGE01 |
| 0A |  | 0x80131F1C | PSX.EXE |
| 0B |  | 0x80131FAC | PSX.EXE |
| 0C |  | 0x801E589C | overlay address, code in STAGE01 |
| 0D |  | 0x8013203C | PSX.EXE |
| 0E |  | 0x801E5B3C | overlay address, code in STAGE01 |
| 0F |  | 0x801E5EE4 | overlay address, code in STAGE01 |
| 10 | Transition-H | 0x80132164 | PSX.EXE |
| 11 | Transition-V | 0x80132404 | PSX.EXE |
| 12 |  | 0x801E6664 | overlay address, code in STAGE02 |
| 13 |  | 0x801E91BC | overlay address, code in STAGE03 |
| 14 |  | 0x801E7760 | overlay address, code in STAGE02 |
| 15 |  | 0x80132718 | PSX.EXE |
| 16 |  | 0x80132750 | PSX.EXE |
| 17 |  | 0x80132900 | PSX.EXE |
| 18 |  | 0x801E688C | overlay address, code in STAGE04 |
| 19 |  | 0x80132A2C | PSX.EXE |
| 1A |  | 0x801E9470 | overlay address, code in STAGE03 |
| 1B |  | 0x801E8A78 | overlay address, code in STAGE05, STAGE0C |
| 1C |  | 0x801E90B8 | overlay address, code in STAGE05 |
| 1D |  | 0x80132A58 | PSX.EXE |
| 1E |  | 0x801E9598 | overlay address, code in STAGE05 |
| 1F |  | 0x801E4D38 | overlay address, code in STAGE06 |
| 20 |  | 0x80132D58 | PSX.EXE |
| 21 |  | 0x80133250 | PSX.EXE |
| 22 |  | 0x801E97AC | overlay address, code in STAGE05 |
| 23 |  | 0x801E99E0 | overlay address, code in STAGE05, STAGE0C |
| 24 |  | 0x801E12CC | overlay address, code in STAGE00 |
| 25 |  | 0x801E0A70 | overlay address, code in STAGE08 |
| 26 |  | 0x801E9E54 | overlay address, no function start found |
| 27 |  | 0x801335FC | PSX.EXE |
| 28 |  | 0x801E9ECC | overlay address, code in STAGE05 |
| 29 |  | 0x801E17A8 | overlay address, no function start found |
| 2A |  | 0x801E17B0 | overlay address, code in STAGE00, STAGE0D |
| 2B |  | 0x801E4E90 | overlay address, code in STAGE06 |
| 2C |  | 0x801DF1A4 | overlay address, code in STAGE07 |
| 2D |  | 0x801E18A0 | overlay address, code in STAGE00 |
| 2E |  | 0x801E7E14 | overlay address, code in STAGE02 |
| 2F |  | 0x80133708 | PSX.EXE |
| 30 |  | 0x801E0C6C | overlay address, code in STAGE05 |
| 31 |  | 0x801339DC | PSX.EXE |
| 32 |  | 0x801E7B30 | overlay address, code in STAGE0B |
| 33 |  | 0x80133D98 | PSX.EXE |

## Type 3 (`0x801CF848`, 0x80 slots of 0x40 bytes)

The handler table is in PSX.EXE at `0x8015029C`, 0x40 entries, with the same mix of PSX.EXE handlers and
fixed overlay addresses. The effect table above starts right where this one ends. The editor has no
names for these yet and I have not identified them.

| ID | Handler | Code |
|---|---|---|
| 00 | 0x8012A1F0 | PSX.EXE |
| 01 | 0x8012A2A8 | PSX.EXE |
| 02 | 0x8012A888 | PSX.EXE |
| 03 | 0x8012AFCC | PSX.EXE |
| 04 | 0x8012B33C | PSX.EXE |
| 05 | 0x8012B6E4 | PSX.EXE |
| 06 | 0x8012B89C | PSX.EXE |
| 07 | 0x8012BA4C | PSX.EXE |
| 08 | 0x8012BB74 | PSX.EXE |
| 09 | 0x801D8378 | overlay address, no function start found |
| 0A | 0x8012BE4C | PSX.EXE |
| 0B | 0x801348E4 | PSX.EXE |
| 0C | 0x8012BF48 | PSX.EXE |
| 0D | 0x801DFE58 | overlay address, code in STAGE00 |
| 0E | 0x801E0058 | overlay address, code in STAGE00 |
| 0F | 0x8012C218 | PSX.EXE |
| 10 | 0x8012C5C8 | PSX.EXE |
| 11 | 0x801E50D0 | overlay address, code in STAGE01 |
| 12 | 0x8012C998 | PSX.EXE |
| 13 | 0x801E4BC8 | overlay address, code in STAGE02 |
| 14 | 0x801E54AC | overlay address, code in STAGE02 |
| 15 | 0x801E7DB8 | overlay address, code in STAGE05 |
| 16 | 0x801E63D0 | overlay address, code in STAGE04 |
| 17 | 0x801E5A24 | overlay address, code in STAGE02 |
| 18 | 0x8012CB0C | PSX.EXE |
| 19 | 0x8012CD28 | PSX.EXE |
| 1A | 0x8012CFF4 | PSX.EXE |
| 1B | 0x801E88B8 | overlay address, code in STAGE03 |
| 1C | 0x801E8B6C | overlay address, code in STAGE03 |
| 1D | 0x801E8CD0 | overlay address, code in STAGE03 |
| 1E | 0x8012D2D8 | PSX.EXE |
| 1F | 0x801E82E4 | overlay address, code in STAGE05, STAGE0D |
| 20 | 0x8012DAAC | PSX.EXE |
| 21 | 0x801E8454 | overlay address, code in STAGE05 |
| 22 | 0x8012E304 | PSX.EXE |
| 23 | 0x8012EBE8 | PSX.EXE |
| 24 | 0x801D8FD8 | overlay address, no function start found |
| 25 | 0x801D9350 | overlay address, no function start found |
| 26 | 0x801D9B9C | overlay address, no function start found |
| 27 | 0x801E8A00 | overlay address, code in STAGE05 |
| 28 | 0x8012EDF4 | PSX.EXE |
| 29 | 0x801DA450 | overlay address, no function start found |
| 2A | 0x8012F1D4 | PSX.EXE |
| 2B | 0x8012FEC0 | PSX.EXE |
| 2C | 0x801E4354 | overlay address, code in STAGE06 |
| 2D | 0x801E0188 | overlay address, code in STAGE00 |
| 2E | 0x80130184 | PSX.EXE |
| 2F | 0x801E63B8 | overlay address, code in STAGE02 |
| 30 | 0x8013028C | PSX.EXE |
| 31 | 0x801DED18 | overlay address, code in STAGE06 |
| 32 | 0x8013059C | PSX.EXE |
| 33 | 0x801DF078 | overlay address, code in STAGE07 |
| 34 | 0x801E4734 | overlay address, code in STAGE06 |
| 35 | 0x80130644 | PSX.EXE |
| 36 | 0x801E49B0 | overlay address, code in STAGE06 |
| 37 | 0x80130D60 | PSX.EXE |
| 38 | 0x801DADB0 | overlay address, no function start found |
| 39 | 0x80130F70 | PSX.EXE |
| 3A | 0x801DB2C4 | overlay address, no function start found |
| 3B | 0x801E15B8 | overlay address, code in STAGE0A |
| 3C | 0x801E9FD4 | overlay address, code in STAGE0C |
| 3D | 0x801316CC | PSX.EXE |
| 3E | 0x801E7950 | overlay address, code in STAGE0B |
| 3F | 0x801EA310 | overlay address, code in STAGE0C |
