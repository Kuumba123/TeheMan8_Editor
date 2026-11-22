// T4_1C, STAGE05.BIN, handler 0x801E90B8. Ghidra output with the object struct applied; not matching C.
// ---- 801e90b8 FUN_801e90b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e90b8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ead94)[obj->var])();
  return;
}


// ---- 801e90f4 FUN_801e90f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e90f4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ead9c)[obj->state])();
  return;
}


// ---- 801e9130 FUN_801e9130

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9130(MM8Obj *obj)

{
  undefined1 uVar1;
  
  FUN_801119e0(0x4d3,0x40);
  *(undefined1 *)&obj->speed_x = 0x3c;
  uVar1 = DAT_8015e241;
  DAT_8015e2af = 1;
  DAT_801b2993 = 1;
  DAT_801b2992 = 1;
  obj->state = 1;
  *(undefined1 *)((int)&obj->speed_x + 1) = uVar1;
  return;
}


// ---- 801e9194 FUN_801e9194

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9194(MM8Obj *obj)

{
  if ((char)obj->speed_x != '\0') {
    *(char *)&obj->speed_x = (char)obj->speed_x + -1;
  }
  if ((DAT_8015e248._2_2_ == 0x4d3) && (DAT_8015e241 = 0, (char)obj->speed_x == '\0')) {
    FUN_80102e84(0xb);
    obj->state = 2;
  }
  return;
}


// ---- 801e9214 FUN_801e9214

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9214(MM8Obj *obj)

{
  if (DAT_8015d226 == '\0') {
    obj->state = 3;
    obj->sub2 = 0;
    DAT_801d2926 = 0x8c0;
    DAT_801d292e = 0x8c0;
    DAT_801d292c = 0x200;
    DAT_801d2934 = 0x200;
    DAT_801d2918._2_2_ = 0x800;
    g_cam_y = 0x300;
    DAT_801d2928 = 0x800;
    DAT_801d2930 = 0x800;
    DAT_801d292a = 0x300;
    DAT_801d2932 = 0x300;
    DAT_8015e248._2_2_ = 0x800;
    DAT_8015e24c._2_2_ = 0x3a9;
    DAT_8015e241 = *(undefined1 *)((int)&obj->speed_x + 1);
    DAT_801c3377 = 1;
    FUN_8011c504();
    FUN_801119e0(0x840,0x40);
    FUN_80101bf0();
    FUN_80102e84(10);
  }
  return;
}


// ---- 801e92f8 FUN_801e92f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e92f8(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    if (DAT_8015d226 == '\0') {
      obj->sub2 = 1;
    }
  }
  else if (0x83f < DAT_8015e248._2_2_) {
    FUN_80111918();
    DAT_8015e2af = 0;
    DAT_801b2993 = 0;
    DAT_801b2992 = 0;
    obj->state = 4;
    obj->sub2 = 0;
    DAT_801d2936 = 0;
  }
  return;
}


// ---- 801e9394 FUN_801e9394

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9394(MM8Obj *obj)

{
  byte bVar1;
  
  DAT_801b29a0 = 0;
  DAT_801b29a1 = 0;
  DAT_801b29a2 = 0;
  DAT_801b29a3 = 0;
  DAT_801b29a4 = 0;
  DAT_801b29a5 = 0;
  DAT_801b29a6 = 1;
  do {
    bVar1 = Rand();
    DAT_801c337a = bVar1 & 7;
  } while (5 < DAT_801c337a);
  Obj_Free(obj);
  return;
}


// ---- 801e9430 FUN_801e9430

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9430(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801eadb0)[obj->state])();
  return;
}


