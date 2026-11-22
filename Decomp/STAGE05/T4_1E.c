// T4_1E, STAGE05.BIN, handler 0x801E9598. Ghidra output with the object struct applied; not matching C.
// ---- 801e9598 FUN_801e9598

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9598(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eadd8)[obj->state])();
  return;
}


// ---- 801e95d4 FUN_801e95d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e95d4(MM8Obj *obj)

{
  obj->state = 1;
  obj->sub2 = 0;
  if (obj->x < DAT_8015e248._2_2_) {
    Obj_FreeDespawn();
  }
  return;
}


// ---- 801e961c FUN_801e961c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e961c(MM8Obj *obj)

{
  int iVar1;
  
  if ((int)(((uint)(ushort)obj->x - (uint)DAT_8015e248._2_2_) * 0x10000) >> 0x10 < 0x12) {
    DAT_801b29a2 = DAT_801b29a2 | (&DAT_801eadd0)[obj->var];
    obj->state = 2;
    DAT_801d2917 = 2;
    DAT_801d292a = g_cam_y;
    DAT_801d292c = g_cam_y;
    DAT_801d2926 = obj->x;
    DAT_801d2928 = obj->x;
    if (DAT_8015e2a3 != '\0') {
      FUN_80111c28();
    }
    FUN_80111904();
    FUN_80105bec();
  }
  else {
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


