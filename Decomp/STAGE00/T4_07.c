// T4_07, STAGE00.BIN, handler 0x801E0B64. Ghidra output with the object struct applied; not matching C.
// ---- 801e0b64 FUN_801e0b64

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0b64(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e2948)[obj->var])();
  return;
}


// ---- 801e0ba0 FUN_801e0ba0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0ba0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e2950)[obj->state])();
  return;
}


// ---- 801e0bdc FUN_801e0bdc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0bdc(MM8Obj *obj)

{
  FUN_801119e0(0x9e0,0x40);
                    /* Possible PsyQ macro: setTile8() */
  *(undefined1 *)((int)&obj->speed_x + 1) = 0x78;
  DAT_8015e2af = 1;
  DAT_8015e2b9 = 1;
  DAT_8015e2ba = 1;
  DAT_801b2993 = 1;
  DAT_801b2992 = 1;
  DAT_801b29a0 = DAT_801b29a0 | 0x80;
  *(undefined1 *)&obj->speed_x = DAT_8015e241;
  obj->state = 1;
  return;
}


// ---- 801e0c64 FUN_801e0c64

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0c64(MM8Obj *obj)

{
  if (*(char *)((int)&obj->speed_x + 1) != '\0') {
    *(char *)((int)&obj->speed_x + 1) = *(char *)((int)&obj->speed_x + 1) + -1;
  }
  if ((DAT_8015e248._2_2_ == 0x9e0) && (DAT_8015e241 = 0, *(char *)((int)&obj->speed_x + 1) == '\0')
     ) {
    FUN_80102e84(7);
    FUN_800fd2c4(0x100,1);
    obj->state = 2;
  }
  return;
}


// ---- 801e0ea0 FUN_801e0ea0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0ea0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e2960)[obj->state])();
  return;
}


// ---- 801e0edc FUN_801e0edc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0edc(MM8Obj *obj)

{
  FUN_801119e0(0xdf6,0x40);
  DAT_8015e2af = 1;
  DAT_8015e2b9 = 1;
                    /* Possible PsyQ macro: setTile8() */
  *(undefined1 *)((int)&obj->speed_x + 1) = 0x78;
  DAT_801b2993 = 1;
  DAT_801b2992 = 1;
  DAT_801b29a0 = DAT_801b29a0 | 0x80;
  *(undefined1 *)&obj->speed_x = DAT_8015e241;
  obj->state = 1;
  return;
}


