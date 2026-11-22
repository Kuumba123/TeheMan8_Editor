# Objects, spawning and the enemy struct

## Object pools

The overlay entry point (see [Overlays.md](Overlays.md)) runs every object pool once per frame. Each
pool is a fixed array of slots; byte `+0x00` is nonzero when the slot is in use, and byte `+0x06` (the
object ID) picks the handler from the pool's dispatch table. Just before calling the handler the game
copies the position at `+0x0E`/`+0x12` to `+0x34`/`+0x36`, so those always hold the previous frame's
position.

| Pool | Slots x size | Handler table | Spawned from the enemy list as |
|---|---|---|---|
| `0x801B12AC` | 0x20 x 0x60 | EXE `0x8015022C` | - |
| `0x801D184C` | 0x40 x 0x40 | EXE `0x8015027C` | - |
| `0x8015B174` (main) | 0x40 x 0x60 | **overlay** main table | type 0 or 1 |
| `0x801B1EEC` | 0x20 x 0x50 | **overlay** second table | type 2 |
| `0x801CF848` | 0x80 x 0x40 | EXE `0x8015029C` | type 3 |
| `0x801CF540` | 0x20 x 0x18 | EXE `0x8015039C` | type 4 |

Run order: 0x801B12AC, 0x801D184C, main, 0x801B1EEC, then two engine updates (one of them moves the
background layers), then 0x801CF848 and
0x801CF540, then a second pass over 0x801B12AC and 0x801D184C for slots whose byte `+0x00` has bit 7
set. The 0x801B12AC pool holds Mega Man's shots: the weapon-vs-enemy check walks it and reads the
weapon type from each slot's `+0x44`.

Note for `MM8_Tools.lua`: the `0x801D184C` pool is 0x40 slots of 0x40 bytes and the `0x801CF540` pool is
0x20 slots of 0x18 bytes; the script has the slot count and size swapped on those two.

## The enemy list and the spawner

The stage's enemy list (PAC entry `0x0A`, the one the editor edits) is loaded to `0x801C2B3C`. The
spawner (`FUN_80101c54`, called with a window around the camera of -0x30..+0x170 in X and -0x30..+0x120
in Y) walks it until it hits a record whose type byte is `0xFF`:

| Offset | Meaning |
|---|---|
| +0 | State, owned by the game: 0 = can spawn, 0x80 = currently spawned, anything else = respawn delay |
| +1 | ID |
| +2 | Var |
| +3 | Type (pool, see above) |
| +4 | X (s16) |
| +6 | Y (s16) |

When a record with state 0 is inside the window it takes a free slot from the pool its type selects
(through the function table at `0x80138474`, one allocator per type), writes `+0x00 = 1`,
`+0x06 = ID`, `+0x07 = Var`, `+0x08 = pointer to the record`, `+0x0E = X`, `+0x12 = Y`, and sets the
record's state to `0x80`, so the same entry cannot spawn twice. A record whose state is between 1 and
0x7F counts down by one on every spawner pass.

What happens to the record when the object goes away:

- killed (`FUN_80105888`): state becomes `0x10`, so it can spawn again once that has counted down.
- despawned for leaving the screen area (`FUN_801058bc`): state becomes 0, it can respawn right away.
- objects spawned by other objects (shots, parts of a bigger enemy) have `+0x08 = 0` and no record.

Checked in Redux in the intro stage: live enemies carried the record pointer, ID and Var exactly as
above, and their records read `0x80` while alive.

## The main-pool object (0x60 bytes)

These are the fields the shared engine code uses. Individual enemies use the rest of the slot (and
some of these) for their own state, so treat anything not listed as per-enemy.

| Offset | Size | Meaning |
|---|---|---|
| +0x00 | u8 | In use |
| +0x01 | u8 | State: index into the enemy's own state table (most handlers start with `table[obj+1](obj)`) |
| +0x02, +0x03 | u8 | Sub-states, also used as indexes into smaller per-state tables |
| +0x05 | u8 | On screen this frame (set by the draw-cull function) |
| +0x06 | u8 | ID |
| +0x07 | u8 | Var |
| +0x08 | ptr | Enemy-list record this object came from, or 0 |
| +0x0C, +0x0E | u16, s16 | X: fraction, pixels |
| +0x10, +0x12 | u16, s16 | Y: fraction, pixels |
| +0x14 .. +0x23 | | Speed/acceleration words, zeroed by the common init. Exact split not traced. |
| +0x24 | u8 | CLUT for the sprite (see [Sprites.md](Sprites.md)) |
| +0x25 | u8 | Bit 6 = flip horizontally (facing), bit 7 = flip vertically. Also flips the hitbox. |
| +0x26 | u8 | Draw list / priority (0xFF is treated as 0x0C) |
| +0x27 | u8 | Sprite bank |
| +0x28 | ptr | Current animation step |
| +0x2C | u16 | VRAM tile base for the sprite |
| +0x2E | u16 | Current sprite frame (bit 15 = loop marker from the animation) |
| +0x30 | u8 | Current animation number |
| +0x31 | u8 | Frames left on the current animation step |
| +0x32 | u8 | Extra byte of the current animation step |
| +0x34, +0x36 | s16 | Previous X, Y |
| +0x38 | ptr | Second box, set by many enemies next to `+0x3C`. Not traced. |
| +0x3C | ptr | Hitbox: `{s8 half width, s8 half height, s8 x offset, s8 y offset}` |
| +0x44 | u8 | Damage table index (which weapons hurt it and how much) |
| +0x45 | u8 | Contact damage to Mega Man |
| +0x46 | u8 | Invulnerable while nonzero |
| +0x47 | u8 | HP. Also gates contact damage: an object with 0 HP does not hurt Mega Man by touch. |
| +0x48 | u8 | Compared by the homing-target picker (`FUN_801120cc`); exact meaning not traced |

## What a typical enemy handler does

Most handlers follow the same shape (Mets, ID 01, `0x801228E8`, is a clean example):

1. call `state_table[obj+0x01](obj)`, where state 0 is the init,
2. update the hitbox pointer and damage table for the current pose (Mets switches `+0x44` to table 00,
   which deflects everything, while its helmet is down),
3. `FUN_8010757c(obj)`: check against Mega Man's shots; it returns 4 when the hit killed it, and then the
   handler makes a few calls (they look like explosion and item drop, not traced) and `FUN_80105888`,
4. otherwise `FUN_801072a0` (contact damage to Mega Man), `FUN_80104a68` (queue for drawing if on
   screen) and `FUN_801047c8`, which returns 0 once the object is far off screen; the handler then
   despawns it with `FUN_801058bc`.

The init state of most enemies calls `FUN_80109080(obj)`, which fills the bank, CLUT, VRAM base, HP,
contact damage and damage table from the per-ID table in PSX.EXE. That table is in
[EnemyTable.md](EnemyTable.md).

Useful shared helpers:

| Function | What it does |
|---|---|
| `FUN_80109080(obj)` | Common enemy init from the per-ID table at `0x801393B4` |
| `FUN_8010488c(obj, anim)` | Start animation `anim` of the object's bank |
| `FUN_801049c0(obj)` | Advance the animation by one frame |
| `FUN_80104a40(obj)` | True on the last tick of an animation step that carries the loop marker |
| `FUN_8010757c(obj)` | Weapon hits; 0 nothing, 1 touched but no damage, 2 damaged, 3 deflected, 4 killed |
| `FUN_801072a0(obj)` | Contact damage to Mega Man |
| `FUN_80104a68(obj)` | Draw-cull and queue the sprite |
| `FUN_801047c8(obj)` | Still in the active area |
| `FUN_8010559c()` | Allocate a main-pool slot (returns 0 if full) |
| `FUN_80105888(obj)` | Free after death (record state 0x10) |
| `FUN_801058bc(obj)` | Free after leaving the area (record state 0) |
| `FUN_80105864(obj)` | Free without touching the record |
