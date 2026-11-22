# Mega Man 8 enemy code notes

Notes on where Mega Man 8 (NTSC-U, SLUS-004.53) keeps its enemy code and data, written for the editor.

- [Overlays.md](Overlays.md): the `OVL/STAGExx.BIN` files, how and where they load, and the per-stage
  enemy handler tables.
- [Objects.md](Objects.md): the object pools, how the enemy list is spawned, and the fields of the
  0x60-byte enemy object.
- [EnemyTable.md](EnemyTable.md): the per-ID property table in PSX.EXE (sprite bank, HP, contact
  damage, damage table) and the weapon damage tables.
- [Items.md](Items.md): the item (type 2), type 3 and effect (type 4) handler tables.
- [Sprites.md](Sprites.md): which PAC entries hold the sprite data, the frame and animation formats, and
  how to draw an enemy from an ID.
- [enemy-handlers.json](enemy-handlers.json): for every stage overlay, the handler address of each ID
  that has code there (`in` says whether it is in PSX.EXE or the overlay) and, where the handler
  dispatches on `+0x01`, the address of its state table.

Function names like `FUN_80109080` are just the addresses of the functions in PSX.EXE (or in the loaded
overlay, for addresses from `0x801D8000` up).

Most of this comes from reading the code. The parts I also checked by running the game in PCSX-Redux,
or by decoding data with the rules described, say so where they appear. Anything marked "not traced" is
a guess from how the code uses it.
