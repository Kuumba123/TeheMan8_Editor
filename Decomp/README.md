# Decompiled enemy code

One `.c` file per enemy handler: `STAGExx/ID.c` for code that lives in that stage's overlay, `EXE/ID.c`
for the few handlers in PSX.EXE (for those only the main handler function is included).
Each overlay file holds the handler and every overlay function it reaches (its state functions and
helpers), in address order.

This is Ghidra output with the object struct from [MM8Obj.h](MM8Obj.h) applied to the handler and its
state functions and the shared PSX.EXE helpers named. It is not matching C and has not been compiled. It
is meant for reading what an enemy does and which fields it uses. Helper functions that take the object
too still show raw `param_1 + 0x..` offsets; the offsets are the same struct. `FUN_801dxxxx` names are
overlay addresses, so the same function has a different name in each overlay it appears in.

[Penguin.md](Penguin.md) goes through one enemy end to end, including moving it into another stage.
How to do that for any enemy is in [../Docs/Injection.md](../Docs/Injection.md).

## Same enemy, several overlays

41 IDs have code in more than one overlay. For 34 of them the copies are the same code: comparing them
word by word, the only differences are addresses that moved with the overlay (`j`/`jal` targets, `lui`
high halves into the overlay, and low halves that moved by exactly the distance between the two copies of
the code or data they point at). That includes every boss rematch in STAGE0D. The other 7 have
different versions of different sizes:

| ID | Versions |
|---|---|
| 07 | STAGE00, STAGE06 |
| 08 | STAGE02 and 0B, STAGE04 |
| 0A | STAGE01, STAGE0A |
| 1B | STAGE04, STAGE0A |
| 2B | STAGE02, STAGE05 |
| 31 | STAGE04, STAGE05 |
| 4B | STAGE09; STAGE02, 04, 06, 0B and 0C are the same |

## Every overlay enemy

"Code+data to copy" is what [Tools/mm8_inject.py](../Tools/mm8_inject.py) appends to the target overlay:
the enemy's functions plus its overlay's two data blocks. "Child objects" are the other objects its code
creates (pool and ID). A `main` child needs its own handler in the target stage too, unless it is the
same ID. A `type3`/`type4` child whose PSX.EXE table entry is a fixed overlay address only works in the
stage that has code at that address. "Injector" is whether the tool can relocate the code with every
reference accounted for. That was checked statically for all of them; only the Penguin has been run.

| ID | Name | Overlay | Code+data to copy | Same code as | Child objects | Injector |
|---|---|---|---|---|---|---|
| 04 | Palm Tree | STAGE00 | 4928 bytes |  |  | yes |
| 05 | Penguin | STAGE01 | 5596 bytes |  |  | yes |
| 06 | Yadokargo | STAGE00 | 8496 bytes |  | type3 ?, type4 2D (overlay address) | code yes, child needs manual work |
| 07 | Ammoner | STAGE00 | 5868 bytes |  |  | yes |
| 07 | Ammoner | STAGE06 | 10076 bytes |  |  | yes |
| 08 | Metrenger Spawner (Snakes) | STAGE02 | 4776 bytes | 0B |  | yes |
| 08 | Metrenger Spawner (Snakes) | STAGE04 | 7408 bytes |  | type2 00 | yes |
| 08 | Metrenger Spawner (Snakes) | STAGE0B | 4112 bytes | 02 |  | yes |
| 09 | Telly | STAGE01 | 5420 bytes | 03, 04, 0A, 0C |  | yes |
| 09 | Telly | STAGE03 | 4956 bytes | 01, 04, 0A, 0C |  | yes |
| 09 | Telly | STAGE04 | 4956 bytes | 01, 03, 0A, 0C |  | yes |
| 09 | Telly | STAGE0A | 4532 bytes | 01, 03, 04, 0C |  | yes |
| 09 | Telly | STAGE0C | 5004 bytes | 01, 03, 04, 0A |  | yes |
| 0A | Chungus | STAGE01 | 10688 bytes |  |  | yes |
| 0A | Chungus | STAGE0A | 8504 bytes |  |  | yes |
| 0B | Ice Cube Launcher | STAGE01 | 4868 bytes |  |  | yes |
| 0C | Ice Cube | STAGE01 | 5740 bytes |  | type2 00 | yes |
| 0D |  | STAGE01 | 5972 bytes | 03, 0A |  | yes |
| 0D |  | STAGE03 | 5508 bytes | 01, 0A |  | yes |
| 0D |  | STAGE0A | 5084 bytes | 01, 03 |  | yes |
| 0E | Ice Dropper Hogale | STAGE01 | 5544 bytes | 03, 0B |  | yes |
| 0E | Ice Dropper Hogale | STAGE03 | 5080 bytes | 01, 0B |  | yes |
| 0E | Ice Dropper Hogale | STAGE0B | 4532 bytes | 01, 03 |  | yes |
| 0F |  | STAGE02 | - |  |  | no: reference to 801d9c7c is outside the copied code and data |
| 10 | Fire Metal | STAGE04 | 5012 bytes | 05, 0A |  | yes |
| 10 | Fire Metal | STAGE05 | 5916 bytes | 04, 0A |  | yes |
| 10 | Fire Metal | STAGE0A | 4588 bytes | 04, 05 |  | yes |
| 11 | Tencrow | STAGE03 | 5840 bytes | 0B |  | yes |
| 11 | Tencrow | STAGE0B | 5292 bytes | 03 |  | yes |
| 12 |  | STAGE03 | 4620 bytes |  | main 00 | yes |
| 13 | Floating Spike | STAGE03 | 3936 bytes | 06, 08, 0C |  | yes |
| 13 | Floating Spike | STAGE06 | 3568 bytes | 03, 08, 0C |  | yes |
| 13 | Floating Spike | STAGE08 | 2792 bytes | 03, 06, 0C |  | yes |
| 13 | Floating Spike | STAGE0C | 3984 bytes | 03, 06, 08 |  | yes |
| 14 |  | STAGE01 | 3100 bytes |  |  | yes |
| 15 |  | STAGE04 | 3420 bytes |  | type2 0D | yes |
| 16 |  | STAGE04 | 5184 bytes |  |  | yes |
| 17 | Cline (Muli-Part Dragon) | STAGE03 | 7968 bytes | 0B |  | yes |
| 17 | Cline (Muli-Part Dragon) | STAGE0B | 7420 bytes | 03 |  | yes |
| 18 |  | STAGE02 | 4712 bytes |  | type3 14 (overlay address) | code yes, child needs manual work |
| 19 | Kaizock | STAGE02 | 5492 bytes |  |  | yes |
| 1A |  | STAGE04 | 4200 bytes |  |  | yes |
| 1B | Fire Metal Spawner | STAGE04 | 8156 bytes |  | main ? | code yes, child needs manual work |
| 1B | Fire Metal Spawner | STAGE0A | 12276 bytes |  | main ?, type3 3B (overlay address) | code yes, child needs manual work |
| 1C | Count Bomb | STAGE04 | 6500 bytes | 06, 0C |  | yes |
| 1C | Count Bomb | STAGE06 | 6132 bytes | 04, 0C |  | yes |
| 1C | Count Bomb | STAGE0C | 6548 bytes | 04, 06 |  | yes |
| 1D |  | STAGE02 | 7824 bytes |  |  | yes |
| 1E | Hannya Attacker | STAGE03 | 4196 bytes | 0B |  | yes |
| 1E | Hannya Attacker | STAGE0B | 3648 bytes | 03 |  | yes |
| 1F | Frost Man | STAGE01 | 14260 bytes | 0D | main 2C | yes |
| 1F | Frost Man | STAGE0D | 16092 bytes | 01 | main 2C | yes |
| 22 | Bats | STAGE01 | 3228 bytes | 04, 0B, 0C |  | yes |
| 22 | Bats | STAGE04 | 2764 bytes | 01, 0B, 0C |  | yes |
| 22 | Bats | STAGE0B | 2216 bytes | 01, 04, 0C |  | yes |
| 22 | Bats | STAGE0C | 2812 bytes | 01, 04, 0B |  | yes |
| 23 | Hogale | STAGE03 | 7832 bytes | 0B |  | yes |
| 23 | Hogale | STAGE0B | 7284 bytes | 03 |  | yes |
| 24 |  | STAGE04 | 4948 bytes |  |  | yes |
| 25 |  | STAGE03 | 5768 bytes |  | type3 1D (overlay address) | code yes, child needs manual work |
| 26 |  | STAGE03 | 2944 bytes |  |  | yes |
| 27 | Tengu Man | STAGE03 | 12188 bytes | 0D |  | yes |
| 27 | Tengu Man | STAGE0D | 14484 bytes | 03 |  | yes |
| 28 |  | STAGE03 | 4664 bytes | 0D |  | yes |
| 28 |  | STAGE0D | 6960 bytes | 03 |  | yes |
| 29 | Lever | STAGE05 | 5060 bytes |  | type3 1F (overlay address) | code yes, child needs manual work |
| 2A | Ururuun | STAGE04 | 8728 bytes |  | type2 33 | yes |
| 2B |  | STAGE02 | 3324 bytes |  |  | yes |
| 2B |  | STAGE05 | 3376 bytes |  |  | yes |
| 2C | Ice Cube Carrier | STAGE01 | 5576 bytes | 0D |  | yes |
| 2C | Ice Cube Carrier | STAGE0D | 7408 bytes | 01 |  | yes |
| 2D |  | STAGE05 | 6016 bytes |  | type3 15 (overlay address) | code yes, child needs manual work |
| 2E | Onbuubattan | STAGE07 | - | 08 |  | no: reference to 801e07e0 is outside the copied code and data |
| 2E | Onbuubattan | STAGE08 | 2864 bytes | 07 |  | yes |
| 2F | Kao na Gahna | STAGE05 | 9288 bytes |  | main ? | code yes, child needs manual work |
| 30 |  | STAGE06 | 3096 bytes |  | type3 36 (overlay address) | code yes, child needs manual work |
| 31 |  | STAGE04 | 2392 bytes |  |  | yes |
| 31 |  | STAGE05 | 5116 bytes |  |  | yes |
| 32 | Green Bats | STAGE05 | 3756 bytes | 0C |  | yes |
| 32 | Green Bats | STAGE0C | 2900 bytes | 05 |  | yes |
| 33 |  | STAGE05 | 8280 bytes |  |  | yes |
| 34 | Kao de Kahna | STAGE05 | 5892 bytes |  |  | yes |
| 35 | Grenade Man | STAGE04 | 10660 bytes | 0D | main 36 | yes |
| 35 | Grenade Man | STAGE0D | 12956 bytes | 04 | main 36 | yes |
| 36 |  | STAGE04 | 6300 bytes | 0D |  | yes |
| 36 |  | STAGE0D | 8596 bytes | 04 |  | yes |
| 37 | Muragattori | STAGE08 | 1652 bytes |  |  | yes |
| 38 |  | STAGE04 | 3004 bytes | 07, 0B |  | yes |
| 38 |  | STAGE07 | 1988 bytes | 04, 0B |  | yes |
| 38 |  | STAGE0B | 2456 bytes | 04, 07 |  | yes |
| 39 | MM1 Floor Enemies | STAGE04 | 3704 bytes | 06, 07, 08, 0B, 0C |  | yes |
| 39 | MM1 Floor Enemies | STAGE06 | 3336 bytes | 04, 07, 08, 0B, 0C |  | yes |
| 39 | MM1 Floor Enemies | STAGE07 | 2688 bytes | 04, 06, 08, 0B, 0C |  | yes |
| 39 | MM1 Floor Enemies | STAGE08 | 2560 bytes | 04, 06, 07, 0B, 0C |  | yes |
| 39 | MM1 Floor Enemies | STAGE0B | 3156 bytes | 04, 06, 07, 08, 0C |  | yes |
| 39 | MM1 Floor Enemies | STAGE0C | 3752 bytes | 04, 06, 07, 08, 0B |  | yes |
| 3A |  | STAGE06 | 9088 bytes | 0D | main 3B | yes |
| 3A |  | STAGE0D | 11752 bytes | 06 | main 3B | yes |
| 3B |  | STAGE06 | 7636 bytes | 0D |  | yes |
| 3B |  | STAGE0D | 10300 bytes | 06 |  | yes |
| 3C | Sydecka | STAGE08 | 8440 bytes |  |  | yes |
| 3D |  | STAGE02 | 2828 bytes |  |  | yes |
| 3E | Surumaker | STAGE06 | 3344 bytes |  |  | yes |
| 3F |  | STAGE06 | 5184 bytes |  | type3 2C (overlay address) | code yes, child needs manual work |
| 40 | Clown Man | STAGE02 | 14092 bytes | 0D | type2 28 | yes |
| 40 | Clown Man | STAGE0D | 16272 bytes | 02 | type2 28 | yes |
| 41 | Vertical Wall Teck | STAGE07 | 5276 bytes | 0C |  | yes |
| 41 | Vertical Wall Teck | STAGE0C | 6340 bytes | 07 |  | yes |
| 42 |  | STAGE06 | 2596 bytes |  |  | yes |
| 43 | Shell'n | STAGE06 | 4568 bytes |  |  | yes |
| 44 |  | STAGE05 | 3800 bytes |  |  | yes |
| 45 | Sisi Roll | STAGE02 | 4780 bytes |  |  | yes |
| 46 | Gorilla | STAGE08 | 1164 bytes | 0C |  | yes |
| 46 | Gorilla | STAGE0C | 2356 bytes | 08 |  | yes |
| 47 | Crunchran | STAGE07 | 1604 bytes |  |  | yes |
| 48 | Search Man | STAGE08 | 8620 bytes | 0D | main 49 | yes |
| 48 | Search Man | STAGE0D | 12060 bytes | 08 | main 49 | yes |
| 49 |  | STAGE08 | 8800 bytes | 0D |  | yes |
| 49 |  | STAGE0D | 12240 bytes | 08 |  | yes |
| 4A |  | STAGE05 | 3840 bytes |  |  | yes |
| 4B | Sniper Joe | STAGE02 | 5700 bytes | 04, 06, 0B, 0C |  | yes |
| 4B | Sniper Joe | STAGE04 | 5584 bytes | 02, 06, 0B, 0C |  | yes |
| 4B | Sniper Joe | STAGE06 | 5216 bytes | 02, 04, 0B, 0C |  | yes |
| 4B | Sniper Joe | STAGE09 | 3912 bytes |  |  | yes |
| 4B | Sniper Joe | STAGE0B | 5036 bytes | 02, 04, 06, 0C |  | yes |
| 4B | Sniper Joe | STAGE0C | 5632 bytes | 02, 04, 06, 0B |  | yes |
| 4C | Sword Man | STAGE05 | 5632 bytes | 0D | main 4D | yes |
| 4C | Sword Man | STAGE0D | 7024 bytes | 05 | main 4D | yes |
| 4D |  | STAGE05 | 5412 bytes | 0D |  | yes |
| 4D |  | STAGE0D | 6804 bytes | 05 |  | yes |
| 4E |  | STAGE0C | 22892 bytes |  | type3 3C (overlay address) | code yes, child needs manual work |
| 4F |  | STAGE09 | 724 bytes |  |  | yes |
| 50 |  | STAGE09 | 5676 bytes |  | main 55 | yes |
| 51 |  | STAGE0A | 10356 bytes |  | type3 3B (overlay address) | code yes, child needs manual work |
| 52 |  | STAGE0A | 3560 bytes |  |  | yes |
| 53 | Wall Teck | STAGE06 | 3612 bytes | 07, 0B, 0C |  | yes |
| 53 | Wall Teck | STAGE07 | 2964 bytes | 06, 0B, 0C |  | yes |
| 53 | Wall Teck | STAGE0B | 3432 bytes | 06, 07, 0C |  | yes |
| 53 | Wall Teck | STAGE0C | 4028 bytes | 06, 07, 0B |  | yes |
| 54 | Thorn Vine | STAGE08 | 2632 bytes |  |  | yes |
| 55 |  | STAGE09 | 672 bytes |  |  | yes |
| 56 | Astro Man | STAGE07 | 6860 bytes | 0D | main 57 | yes |
| 56 | Astro Man | STAGE0D | 10172 bytes | 07 | main 57 | yes |
| 57 |  | STAGE07 | 5396 bytes | 0D |  | yes |
| 57 |  | STAGE0D | 8708 bytes | 07 |  | yes |
| 58 |  | STAGE09 | 1620 bytes | 0D |  | yes |
| 58 |  | STAGE0D | 5832 bytes | 09 |  | yes |
| 59 |  | STAGE0B | 16516 bytes |  | type3 3E (overlay address) | code yes, child needs manual work |
| 5B |  | STAGE0D | 6064 bytes |  |  | yes |
| 5C |  | STAGE0D | 13708 bytes |  |  | yes |
| 5D |  | STAGE0C | 4264 bytes |  | type2 33 | yes |
| 5E |  | STAGE0C | 5412 bytes |  | type3 3F (overlay address) | code yes, child needs manual work |
| 5F |  | STAGE0C | 2708 bytes |  |  | yes |
| 60 |  | STAGE0A | - |  |  | no: no overlay functions |
| 60 |  | STAGE0B | 4884 bytes |  |  | yes |
