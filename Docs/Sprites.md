# Object sprites and animation

Enemy graphics come from three places: the frame data and per-bank tables in the stage PAC, the
textures in the PAC's VRAM entries, and the animation scripts in PSX.EXE.

## Where PAC entries go

`FUN_800fbd40` sends each PAC entry to RAM through a table at `0x80137850`, indexed by `type & 0x7F`:

| Type | RAM | Contents |
|---|---|---|
| 0, 1, 2 | `0x8016EF34`, `0x8016F334`, `0x8016F734` | Layouts (as in the editor) |
| 3 | `0x80190040` | Screens |
| 4 | `0x8015EA88` | Tile info |
| **5** | **`0x80078000`** | **Sprite frame data for every bank** |
| **6** | **`0x8015CE08`** | **u32 per bank: offset of the bank's frames inside entry 5** |
| **7** | **`0x80170348`** | **u16 per bank: VRAM tile base** |
| **8** | **`0x80159F64`** | **u8 per bank: CLUT byte** |
| 9 | `0x8015A064` | Palettes |
| 0x0A | `0x801C2B3C` | Enemy list |
| 0x0B | `0x801AE840` | CLUT animation |
| 0x0C .. 0x15 | `0x8016D408`, `0x8016DC0C`, `0x8016E40C`, `0x801AE040`, `0x801C3384`, `0x80060000`, `0x800A0000`, `0x8009E000`, `0x8015B06C`, `0x8005E000` | Not looked at |

Entries 6, 7 and 8 have one element per bank, so their lengths give the bank count of the stage
(0x98 banks in STAGE01.PAC, 0xA8 in STAGE0D.PAC). A bank that a stage does not use has an empty frame
list and a tile base of 0.

Entries with bit `0x100` set are textures and go to VRAM, at the position from the table at
`0x801378A8` (again indexed by `type & 0x7F`): 0x100 at (320,0), 0x101 at (320,256), 0x102 at (512,0),
0x103 at (512,256), 0x104 at (384,256). Those match the editor's `Const.CordTabe`. They are uploaded in
0x800-byte chunks of 64 halfwords x 16 lines, down a 256-line column and then on to the next 64-halfword
column, which is why the editor can treat 0x102 as eight 0x8000-byte pages. Object textures are 0x102
in the stage PAC plus 0x100/0x101/0x104 from COMNCHAR.PAC.

## Frame format

The renderer is `FUN_800f90d4`. For an object with bank `b` (`+0x27`) showing frame `f` (`+0x2E & 0x7FFF`):

```
bank  = entry5 + entry6[b]
frame = bank + f * 4          : u16 quadCount, u16 quadOffset
quads = bank + quadOffset     : quadCount x 4 bytes
quad                          : u16 w, s8 x, s8 y
```

The frame list of a bank ends where its first frame's quads start, so the frame count of bank `b` is
`quadOffset_of_frame0 / 4`.

Every quad is a 16x16 tile drawn at (object X + x, object Y + y):

- `tile = obj+0x2C + (w & 0x3FF)`. `obj+0x2C` is `entry7[b]` for nearly every object.
- texture page = `tile >> 8` (bits 0-3 = X / 64, bit 4 = Y / 256), u = `(tile & 0xF) * 16`,
  v = `tile & 0xF0`. 4bpp. So tile base 0x800 is VRAM (512,0), the start of the stage's 0x102 entry.
- `w` bit 14 flips the tile horizontally, bit 15 vertically; they are XORed with the object's flip bits
  (`+0x25` bits 6 and 7), and an object flip also mirrors the x/y offsets.
- `w` bits 11-12 are added to the CLUT X.

CLUT: with `c = obj+0x24` (which is `entry8[b]` for nearly every object), the CLUT is X = `(c & 0x0F) + ((w >> 11) & 3)`
(in units of 16 colours) and Y = `480 + ((c >> 4) & 3)`. `c = 0` always uses CLUT (0,480). I put the palette
entry (type 9, 0x1000 bytes) at (0,480) to (255,487) in VRAM and the colours came out right, but I did
not trace its upload. With that layout, in the editor's palette array CLUT
(X, Y) is index `(Y - 480) * 16 + X`. Bit 7 of `+0x24` switches the polygon to 8bpp; I did not see an
enemy use it.

Decoding bank 1 out of STAGE01.PAC with these rules draws all 44 Mets frames in their proper colours. In Redux the live objects in the intro stage had `+0x2C` and `+0x24`
equal to `entry7[bank]` and `entry8[bank]` of STAGE00.PAC.

## Animation

`FUN_8010488c(obj, anim)` starts an animation. The scripts are in PSX.EXE: `0x8014FF74` is an array of
pointers, one per bank, each to an array of pointers, one per animation. A script is a list of 4-byte
steps:

```
u16 frame      bit 15 = loop marker
u8  duration   in frames
u8  extra      copied to +0x32, used by some enemies
```

After a step with the loop marker, the next step's first halfword is a count: the script jumps back
that many steps (`1` means "hold this frame"). For Mets, animation 3 is frame 0x1C with the marker and
a duration of 255 followed by a count of 1, which holds the frame.

## Drawing an enemy in the editor

For an enemy-list entry with type 0/1 and ID `i` in a stage:

1. `b` = bank byte of row `i` of the table at `0x801393B4` ([EnemyTable.md](EnemyTable.md)).
2. Read `entry6[b]`, `entry7[b]`, `entry8[b]` from the stage PAC, take frame 0 of the bank (or the first
   frame of animation 0 from the EXE scripts), and draw its quads with the rules above, using the stage
   PAC's 0x102 texture and COMNCHAR's 0x100/0x101/0x104 for any tile outside the stage area.

## Not solved

- Every boss bank (Frost Man, Tengu Man, and so on) uses tile base 0x5D0, i.e. VRAM (320,208), which
  COMNCHAR fills with placeholder tiles. Each `BOSSxxx.PAC` has a 0x8000-byte 0x102 entry that must end
  up there when the fight starts, but putting it at (320,208) with the chunk order above gives a scrambled
  image, so the boss upload path is different and I have not found it yet.
- The type 2 pool's second table uses the same frame format, but I did not check whether its IDs have a
  property table like `0x801393B4`.
