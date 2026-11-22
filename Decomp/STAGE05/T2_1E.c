// T2_1E, STAGE05.BIN, handler 0x801E5C88. Ghidra output with the object struct applied; not matching C.
// ---- 801e5c88 FUN_801e5c88

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5c88(MM8Obj *obj)

{
  char cVar1;
  
  obj->on_screen = 0;
  (*(code *)(&PTR_LAB_801ea96c)[obj->state])();
  if ((obj->active != 0) && (cVar1 = FUN_801e62f0(obj), cVar1 != '\0')) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e62f0 FUN_801e62f0

bool FUN_801e62f0(int param_1)

{
  bool bVar1;
  
  bVar1 = true;
  if ((DAT_801d2918._2_2_ + -0x40 < (int)*(short *)(param_1 + 0xe)) &&
     ((int)*(short *)(param_1 + 0xe) < DAT_801d2918._2_2_ + 0x180)) {
    if (g_cam_y + -0x1e0 < (int)*(short *)(param_1 + 0x12)) {
      bVar1 = g_cam_y + 0x2d0 <= (int)*(short *)(param_1 + 0x12);
    }
  }
  return bVar1;
}


