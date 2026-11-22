# Items, effects and the other spawnable objects

The enemy list can spawn into three more pools besides the main one (the type byte, see
[Objects.md](Objects.md)). In the editor's Lua overlay these are the blue (type 2, `0x801B1EEC`), purple
(type 3, `0x801CF848`) and pink (type 4, `0x801CF540`) boxes. Each one dispatches on the object ID at
`+0x06`, like the main pool.

## Type 2: items (`0x801B1EEC`, 0x20 slots of 0x50 bytes)

The handler table is the overlay's second table (addresses in [Overlays.md](Overlays.md)), so like
enemies the code can change per stage. It has 0x34 entries in most overlays and 0x30 in STAGE02 and
STAGE03, where data follows it. IDs without code in a stage all point at one stub function.

IDs with code anywhere, and where that code is (PSX.EXE means the same handler in every stage). "Stages it
can be moved into" counts the other stages [../Tools/mm8_inject.py](../Tools/mm8_inject.py) can copy it into
(see [Injection.md](Injection.md)); [object-handlers.json](object-handlers.json) names them and gives the
reason for each one it cannot. The decompiled code is in `../Decomp/STAGExx/T2_ID.c`.

| ID | Name | Code | Stages it can be moved into | Notes |
|---|---|---|---|---|
| 00 | Item | PSX.EXE | any stage |  |
| 01 |  | STAGE00 | 12 of 13 |  |
| 02 |  | STAGE00 | 12 of 13 | spawns effect 07; spawns type3 0E |
| 03 | Falling Platform | STAGE01, STAGE0A | 01: 12 of 13; 0A: 12 of 13 | edits the stage map from a per-stage list (PSX.EXE 0x80102EF4); reads the stage number (0x801C336E); spawns item 03 |
| 04 |  | STAGE01, STAGE0A | 01: 12 of 13; 0A: 12 of 13 |  |
| 05 | Snow Board | STAGE01, STAGE0A | 01: 12 of 13; 0A: 12 of 13 |  |
| 06 |  | STAGE00 | 12 of 13 | spawns item 23 |
| 07 |  | STAGE01 | 12 of 13 |  |
| 08 |  | STAGE01 | 12 of 13 |  |
| 09 |  | STAGE03 | 12 of 13 |  |
| 0A | Swinging Hammer | STAGE04 | 12 of 13 |  |
| 0B |  | STAGE02 | 12 of 13 |  |
| 0C |  | STAGE03, STAGE0B | 03: 12 of 13; 0B: 12 of 13 | reads the stage number (0x801C336E); spawns main 03 |
| 0D |  | STAGE04 | 12 of 13 |  |
| 0E |  | STAGE03, STAGE0B | 03: 12 of 13; 0B: 12 of 13 | spawns item 0F; spawns item 10 |
| 0F |  | STAGE03, STAGE0B | 03: 12 of 13; 0B: 12 of 13 |  |
| 10 |  | STAGE03, STAGE0B | 03: 12 of 13; 0B: 12 of 13 |  |
| 11 |  | STAGE02 | 12 of 13 |  |
| 12 |  | STAGE05 | 12 of 13 | spawns effect 1C; spawns main 4A; spawns type3 21 |
| 13 |  | STAGE03 | 12 of 13 |  |
| 14 |  | STAGE03 | 12 of 13 | edits the stage map from a per-stage list (PSX.EXE 0x80102EF4) |
| 15 |  | STAGE02 | 12 of 13 | spawns main 0F |
| 16 |  | STAGE03 | 12 of 13 | spawns type3 1C |
| 17 |  | STAGE02 | 12 of 13 |  |
| 18 |  | STAGE05 | 12 of 13 |  |
| 19 |  | STAGE05 | 12 of 13 |  |
| 1A |  | STAGE05 | 12 of 13 |  |
| 1B |  | STAGE05 | 12 of 13 |  |
| 1C |  | STAGE05 | 12 of 13 | spawns main ? |
| 1D |  | STAGE05 | 12 of 13 |  |
| 1E |  | STAGE05 | 12 of 13 |  |
| 1F |  | STAGE05 | 12 of 13 | spawns type3 15; spawns type3 27 |
| 20 |  | STAGE05 | 12 of 13 |  |
| 21 |  | STAGE05 | 12 of 13 | edits the stage map from a per-stage list (PSX.EXE 0x80102EF4); spawns type3 27 |
| 22 | Boss Door | PSX.EXE | any stage |  |
| 23 |  | STAGE00 | 12 of 13 | spawns item 23 |
| 24 |  | STAGE05 | 12 of 13 |  |
| 25 | Bolt | PSX.EXE | any stage |  |
| 26 |  | PSX.EXE | any stage |  |
| 27 |  | STAGE06 | 12 of 13 |  |
| 28 |  | STAGE02, STAGE0D | 02: 12 of 13; 0D: 13 of 13 |  |
| 29 |  | STAGE07 | 12 of 13 |  |
| 2A |  | STAGE06 | 12 of 13 |  |
| 2B |  | STAGE07 | 12 of 13 |  |
| 2C |  | STAGE02 | 12 of 13 | spawns item 2C |
| 2D |  | STAGE07 | 12 of 13 |  |
| 2E |  | STAGE06 | 12 of 13 | spawns type3 34 |
| 2F |  | PSX.EXE | any stage |  |
| 30 |  | STAGE08 | 10 of 13 |  |
| 31 |  | STAGE0B | 10 of 13 | edits the stage map from a per-stage list (PSX.EXE 0x80102EF4) |
| 32 |  | STAGE0D | 11 of 13 |  |
| 33 |  | PSX.EXE | any stage |  |

## Type 4: effects (`0x801CF540`, 0x20 slots of 0x18 bytes)

The handler table is in PSX.EXE at `0x8015039C`, 0x34 entries. Some entries are not PSX.EXE code but
fixed addresses inside the overlay area: those handlers only exist while the overlay that has code at
that address is loaded, so an effect like that only works in its own stage until it is moved. Where
several overlays happen to have a function at the same address, the stage listed is the one whose code
or enemy list spawns that ID. The decompiled code is in `../Decomp/STAGExx/T4_ID.c`.

| ID | Name | Table entry | Code | Stages it can be moved into | Notes |
|---|---|---|---|---|---|
| 00 |  | 0x80131B48 | PSX.EXE | any stage |  |
| 01 |  | 0x80131BDC | PSX.EXE | any stage |  |
| 02 |  | 0x80131C70 | PSX.EXE | any stage |  |
| 03 |  | 0x80131D28 | PSX.EXE | any stage |  |
| 04 | Checkpoint | 0x80131DE0 | PSX.EXE | any stage |  |
| 05 |  | 0x801E073C | STAGE00 | 1 of 13 | spawns item 01 |
| 06 |  | 0x801E09F8 | STAGE00 | 1 of 13 | spawns main 06 |
| 07 |  | 0x801E0B64 | STAGE00 | 1 of 13 |  |
| 08 |  | 0x801E64B0 | STAGE02 | 6 of 13 | spawns item 15 |
| 09 |  | 0x801E5290 | STAGE01 | 5 of 13 |  |
| 0A |  | 0x80131F1C | PSX.EXE | any stage |  |
| 0B |  | 0x80131FAC | PSX.EXE | any stage |  |
| 0C |  | 0x801E589C | STAGE01 | 5 of 13 | spawns main 0B; spawns main 0E |
| 0D |  | 0x8013203C | PSX.EXE | any stage |  |
| 0E |  | 0x801E5B3C | STAGE01 | 5 of 13 | spawns type3 11 |
| 0F |  | 0x801E5EE4 | STAGE01 | 6 of 13 |  |
| 10 | Transition-H | 0x80132164 | PSX.EXE | any stage |  |
| 11 | Transition-V | 0x80132404 | PSX.EXE | any stage |  |
| 12 |  | 0x801E6664 | STAGE02 | 6 of 13 | spawns effect 12; spawns item 0B; spawns main 01; spawns main 21; spawns type3 13 |
| 13 |  | 0x801E91BC | STAGE03 | 10 of 13 | spawns main 13 |
| 14 |  | 0x801E7760 | STAGE02 | 8 of 13 | spawns type3 17 |
| 15 |  | 0x80132718 | PSX.EXE | any stage |  |
| 16 |  | 0x80132750 | PSX.EXE | any stage |  |
| 17 |  | 0x80132900 | PSX.EXE | any stage |  |
| 18 |  | 0x801E688C | STAGE04 | 6 of 13 | spawns main 24 |
| 19 |  | 0x80132A2C | PSX.EXE | any stage |  |
| 1A |  | 0x801E9470 | STAGE03 | 10 of 13 | spawns type3 1B |
| 1B |  | 0x801E8A78 | STAGE05 | 9 of 13 | edits the stage map from a per-stage list (PSX.EXE 0x80102EF4); spawns effect 26 |
| 1C |  | 0x801E90B8 | STAGE05 | 10 of 13 |  |
| 1D |  | 0x80132A58 | PSX.EXE | any stage |  |
| 1E |  | 0x801E9598 | STAGE05 | 10 of 13 |  |
| 1F |  | 0x801E4D38 | STAGE06 | 5 of 13 |  |
| 20 |  | 0x80132D58 | PSX.EXE | any stage |  |
| 21 |  | 0x80133250 | PSX.EXE | any stage |  |
| 22 |  | 0x801E97AC | STAGE05 | 10 of 13 |  |
| 23 |  | 0x801E99E0 | STAGE05 | 10 of 13 |  |
| 24 |  | 0x801E12CC | STAGE00 | 2 of 13 |  |
| 25 |  | 0x801E0A70 | STAGE08 | 1 of 13 | spawns main 37 |
| 26 |  | 0x801E9E54 | STAGE05 | 10 of 13 |  |
| 27 |  | 0x801335FC | PSX.EXE | any stage |  |
| 28 |  | 0x801E9ECC | STAGE05 | 10 of 13 |  |
| 29 |  | 0x801E17A8 | STAGE00 | 3 of 13 |  |
| 2A |  | 0x801E17B0 | STAGE00 | 3 of 13 |  |
| 2B |  | 0x801E4E90 | STAGE06 | 5 of 13 | spawns item 27; spawns main 3F |
| 2C |  | 0x801DF1A4 | STAGE07 | 1 of 13 | spawns item 2B; spawns type3 31; spawns type3 33 |
| 2D |  | 0x801E18A0 | STAGE00 | 3 of 13 |  |
| 2E |  | 0x801E7E14 | STAGE02 | 8 of 13 | spawns main 45; spawns type3 2F |
| 2F |  | 0x80133708 | PSX.EXE | any stage |  |
| 30 |  | 0x801E0C6C | STAGE08 | 1 of 13 |  |
| 31 |  | 0x801339DC | PSX.EXE | any stage |  |
| 32 |  | 0x801E7B30 | STAGE0B | 8 of 13 | spawns main 59 |
| 33 |  | 0x80133D98 | PSX.EXE | any stage |  |

## Type 3 (`0x801CF848`, 0x80 slots of 0x40 bytes)

The handler table is in PSX.EXE at `0x8015029C`, 0x40 entries, with the same mix of PSX.EXE handlers and
fixed overlay addresses. The effect table above starts right where this one ends. The editor has no
names for these yet and I have not identified them. DEMO.BIN is the attract-mode overlay; ID 11 has a
function at its address in both STAGE01 and STAGE06 and nothing spawns it in either, so its owner is not
settled. The decompiled code is in `../Decomp/STAGExx/T3_ID.c`.

| ID | Name | Table entry | Code | Stages it can be moved into | Notes |
|---|---|---|---|---|---|
| 00 |  | 0x8012A1F0 | PSX.EXE | any stage |  |
| 01 |  | 0x8012A2A8 | PSX.EXE | any stage |  |
| 02 |  | 0x8012A888 | PSX.EXE | any stage |  |
| 03 |  | 0x8012AFCC | PSX.EXE | any stage |  |
| 04 |  | 0x8012B33C | PSX.EXE | any stage |  |
| 05 |  | 0x8012B6E4 | PSX.EXE | any stage |  |
| 06 |  | 0x8012B89C | PSX.EXE | any stage |  |
| 07 |  | 0x8012BA4C | PSX.EXE | any stage |  |
| 08 |  | 0x8012BB74 | PSX.EXE | any stage |  |
| 09 |  | 0x801D8378 | DEMO.BIN | attract demo only |  |
| 0A |  | 0x8012BE4C | PSX.EXE | any stage |  |
| 0B |  | 0x801348E4 | PSX.EXE | any stage |  |
| 0C |  | 0x8012BF48 | PSX.EXE | any stage |  |
| 0D |  | 0x801DFE58 | STAGE00 | 1 of 13 |  |
| 0E |  | 0x801E0058 | STAGE00 | 1 of 13 |  |
| 0F |  | 0x8012C218 | PSX.EXE | any stage |  |
| 10 |  | 0x8012C5C8 | PSX.EXE | any stage |  |
| 11 |  | 0x801E50D0 | STAGE01, STAGE06 | 01: 5 of 13; 06: 5 of 13 | owner not settled |
| 12 |  | 0x8012C998 | PSX.EXE | any stage |  |
| 13 |  | 0x801E4BC8 | STAGE02 | 0 of 13 |  |
| 14 |  | 0x801E54AC | STAGE02 | 5 of 13 | spawns main 1D; spawns type3 06 |
| 15 |  | 0x801E7DB8 | STAGE05 | 8 of 13 |  |
| 16 |  | 0x801E63D0 | STAGE04 | 6 of 13 |  |
| 17 |  | 0x801E5A24 | STAGE02 | 5 of 13 | spawns type3 06; spawns type3 17 |
| 18 |  | 0x8012CB0C | PSX.EXE | any stage |  |
| 19 |  | 0x8012CD28 | PSX.EXE | any stage |  |
| 1A |  | 0x8012CFF4 | PSX.EXE | any stage |  |
| 1B |  | 0x801E88B8 | STAGE03 | 9 of 13 |  |
| 1C |  | 0x801E8B6C | STAGE03 | 9 of 13 |  |
| 1D |  | 0x801E8CD0 | STAGE03 | 9 of 13 |  |
| 1E |  | 0x8012D2D8 | PSX.EXE | any stage |  |
| 1F |  | 0x801E82E4 | STAGE05 | 8 of 13 |  |
| 20 |  | 0x8012DAAC | PSX.EXE | any stage |  |
| 21 |  | 0x801E8454 | STAGE05 | 8 of 13 |  |
| 22 |  | 0x8012E304 | PSX.EXE | any stage |  |
| 23 |  | 0x8012EBE8 | PSX.EXE | any stage |  |
| 24 |  | 0x801D8FD8 | DEMO.BIN | attract demo only |  |
| 25 |  | 0x801D9350 | DEMO.BIN | attract demo only |  |
| 26 |  | 0x801D9B9C | DEMO.BIN | attract demo only |  |
| 27 |  | 0x801E8A00 | STAGE05 | 9 of 13 |  |
| 28 |  | 0x8012EDF4 | PSX.EXE | any stage |  |
| 29 |  | 0x801DA450 | DEMO.BIN | attract demo only |  |
| 2A |  | 0x8012F1D4 | PSX.EXE | any stage |  |
| 2B |  | 0x8012FEC0 | PSX.EXE | any stage |  |
| 2C |  | 0x801E4354 | STAGE06 | 5 of 13 |  |
| 2D |  | 0x801E0188 | STAGE00 | 1 of 13 |  |
| 2E |  | 0x80130184 | PSX.EXE | any stage |  |
| 2F |  | 0x801E63B8 | STAGE02 | 6 of 13 |  |
| 30 |  | 0x8013028C | PSX.EXE | any stage |  |
| 31 |  | 0x801DED18 | STAGE07 | 1 of 13 | spawns item 2B; spawns type3 31; spawns type3 33 |
| 32 |  | 0x8013059C | PSX.EXE | any stage |  |
| 33 |  | 0x801DF078 | STAGE07 | 1 of 13 |  |
| 34 |  | 0x801E4734 | STAGE06 | 5 of 13 |  |
| 35 |  | 0x80130644 | PSX.EXE | any stage |  |
| 36 |  | 0x801E49B0 | STAGE06 | 5 of 13 | edits the stage map from a per-stage list (PSX.EXE 0x80102EF4); spawns type3 36 |
| 37 |  | 0x80130D60 | PSX.EXE | any stage |  |
| 38 |  | 0x801DADB0 | DEMO.BIN | attract demo only |  |
| 39 |  | 0x80130F70 | PSX.EXE | any stage |  |
| 3A |  | 0x801DB2C4 | DEMO.BIN | attract demo only |  |
| 3B |  | 0x801E15B8 | STAGE0A | 3 of 13 |  |
| 3C |  | 0x801E9FD4 | STAGE0C | 10 of 13 | spawns type3 3C |
| 3D |  | 0x801316CC | PSX.EXE | any stage |  |
| 3E |  | 0x801E7950 | STAGE0B | 8 of 13 |  |
| 3F |  | 0x801EA310 | STAGE0C | 11 of 13 |  |
