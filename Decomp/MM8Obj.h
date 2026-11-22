/* The 0x60-byte main-pool object (enemies) as used by the decompiled handlers in this folder.
   Only the fields the shared engine code uses are named; every enemy also uses the gaps for its own
   state, which show up as field_0xNN in the .c files. Positions are 16.16 fixed point: x is the 32-bit
   value at +0x0C, so +0x0E is the pixel part. */

#include <stdint.h>

typedef struct MM8Obj {
    uint8_t  active;        /* 0x00 nonzero while the slot is in use */
    uint8_t  state;         /* 0x01 index into the enemy's state table; state 0 is the init */
    uint8_t  sub2;          /* 0x02 sub-state */
    uint8_t  sub3;          /* 0x03 sub-state */
    uint8_t  field_0x04;
    uint8_t  on_screen;     /* 0x05 set by the draw cull */
    uint8_t  id;            /* 0x06 object ID (enemy-list ID) */
    uint8_t  var;           /* 0x07 enemy-list Var */
    uint8_t *spawn_record;  /* 0x08 enemy-list record it came from, or 0 */
    uint16_t x_frac;        /* 0x0C */
    int16_t  x;             /* 0x0E */
    uint16_t y_frac;        /* 0x10 */
    int16_t  y;             /* 0x12 */
    int32_t  speed_x;       /* 0x14 added to the 32-bit x every frame by Obj_ApplySpeed */
    int32_t  speed_y_up;    /* 0x18 subtracted from the 32-bit y (positive moves up) */
    int32_t  accel_x;       /* 0x1C added to speed_x */
    int32_t  gravity;       /* 0x20 subtracted from speed_y_up */
    uint8_t  clut;          /* 0x24 CLUT byte (see Docs/Sprites.md) */
    uint8_t  flip;          /* 0x25 bit 6 flip horizontally, bit 7 vertically */
    uint8_t  draw_list;     /* 0x26 */
    uint8_t  bank;          /* 0x27 sprite bank */
    uint16_t *anim_step;    /* 0x28 current animation step */
    uint16_t vram_base;     /* 0x2C tile base */
    uint16_t frame;         /* 0x2E current frame, bit 15 = loop marker */
    uint8_t  anim;          /* 0x30 */
    uint8_t  anim_timer;    /* 0x31 */
    uint8_t  anim_extra;    /* 0x32 */
    uint8_t  field_0x33;    /* 0x33 terrain contact flags; the Penguin stops falling on bit 7 and turns on bits 4-5. Not traced. */
    int16_t  prev_x;        /* 0x34 */
    int16_t  prev_y;        /* 0x36 */
    uint8_t *box2;          /* 0x38 second box, not traced */
    uint8_t *hitbox;        /* 0x3C {s8 half width, s8 half height, s8 x offset, s8 y offset} */
    uint8_t  field_0x40[4];
    uint8_t  dmg_table;     /* 0x44 */
    uint8_t  contact_dmg;   /* 0x45 */
    uint8_t  invuln;        /* 0x46 */
    uint8_t  hp;            /* 0x47 */
    uint8_t  target_prio;   /* 0x48 compared by the homing-target picker */
    uint8_t  field_0x49[0x17];
} MM8Obj;

/* PSX.EXE helpers, by the names used in the .c files */
void    Enemy_InitFromTable(MM8Obj *obj);          /* 0x80109080 bank/HP/damage from the table at 0x801393B4 */
void    Anim_Set(MM8Obj *obj, uint8_t anim);       /* 0x8010488C */
void    Anim_SetAtStep(MM8Obj *obj, uint8_t anim, uint8_t step); /* 0x801048DC */
void    Anim_Step(MM8Obj *obj);                     /* 0x801049C0 */
void    Anim_StepN(MM8Obj *obj, int n);             /* 0x80104960 */
int     Anim_AtLoopMarker(MM8Obj *obj);             /* 0x80104A40 */
void    Obj_ApplySpeed(MM8Obj *obj);                /* 0x80104C58 speed += accel, position += speed */
int     Enemy_CheckWeaponHits(MM8Obj *obj);         /* 0x8010757C 0 none, 1 touched, 2 hurt, 3 deflected, 4 killed */
int     Enemy_ApplyWeaponHit(MM8Obj *obj, int weapon); /* 0x80107400 */
int     Enemy_ContactDamage(MM8Obj *obj);           /* 0x801072A0 */
int     Obj_HitboxOverlap(MM8Obj *a, MM8Obj *b);    /* 0x801076CC */
void    Obj_CullAndQueueDraw(MM8Obj *obj);          /* 0x80104A68 */
void    Obj_CullAndQueueDrawMargin(MM8Obj *obj, int margin); /* 0x80104AEC */
void    Obj_QueueDraw(MM8Obj *obj);                 /* 0x80104B84 */
int     Obj_InActiveArea(MM8Obj *obj);              /* 0x801047C8 */
MM8Obj *Obj_AllocMain(void);                        /* 0x8010559C main pool, 0x60-byte slots */
void   *Obj_AllocType2(void);                       /* 0x801056F4 0x50-byte slots */
void   *Obj_AllocType3(void);                       /* 0x80105770 0x40-byte slots */
void   *Obj_AllocType4(void);                       /* 0x801057EC 0x18-byte slots */
void   *Obj_AllocByType(uint8_t type);              /* 0x8010582C */
void    Obj_Free(MM8Obj *obj);                      /* 0x80105864 */
void    Obj_FreeKilled(MM8Obj *obj);                /* 0x80105888 spawn record state = 0x10 */
void    Obj_FreeDespawn(MM8Obj *obj);               /* 0x801058BC spawn record state = 0 */
int     Rand(void);                                 /* 0x80104D68 */

/* globals: g_player 0x8015E23C (Mega Man's object), g_cam_x 0x801D291A, g_cam_y 0x801D291C,
   g_enemy_props 0x801393B4, g_dmg_tables 0x801399BC, g_main_pool 0x8015B174 */
