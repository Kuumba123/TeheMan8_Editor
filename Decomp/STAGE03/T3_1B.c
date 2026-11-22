// T3_1B, STAGE03.BIN, handler 0x801E88B8. Ghidra output with the object struct applied; not matching C.
// ---- 801e88b8 FUN_801e88b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e88b8(MM8Obj *obj)

{
  short sVar1;
  
  (*(code *)(&PTR_FUN_801ea008)[obj->state])();
  Obj_CullAndQueueDrawMargin(obj,0x40);
  if (obj->on_screen == 0) {
    sVar1 = 0x170;
    if (DAT_801d2918._2_2_ + 0xa0 <= (int)obj->x) {
      sVar1 = -0x30;
    }
    obj->x = DAT_801d2918._2_2_ + sVar1;
    sVar1 = FUN_801e8ad8(obj->var);
    obj->y = g_cam_y + sVar1;
  }
  return;
}


// ---- 801e8964 FUN_801e8964

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8964(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* Possible PsyQ macro: setLineF3() */
  obj->bank = 0x48;
  obj->vram_base = DAT_801703d8;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->draw_list = 0xb;
  obj->clut = bVar1;
  bVar1 = obj->var;
  obj->flip = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  if (bVar1 == 1) {
    iVar2 = 0x800;
LAB_801e8a08:
    obj->speed_x = iVar2;
    uVar3 = 2;
  }
  else {
    if (1 < bVar1) {
      iVar2 = 0x400;
      if (bVar1 != 2) goto LAB_801e8a24;
      goto LAB_801e8a08;
    }
    if (bVar1 != 0) goto LAB_801e8a24;
    obj->speed_x = 0x1000;
    uVar3 = 0;
  }
  Anim_SetAtStep(obj,0,uVar3);
LAB_801e8a24:
  obj->state = 1;
  return;
}


// ---- 801e8ad8 FUN_801e8ad8

int FUN_801e8ad8(byte param_1)

{
  int iVar1;
  uint uVar2;
  int in_v1;
  
  if (param_1 == 1) {
    uVar2 = Rand();
    iVar1 = (uVar2 & 0x1f) + 0x88;
  }
  else if (param_1 < 2) {
    iVar1 = in_v1 << 0x10;
    if (param_1 != 0) goto LAB_801e8b58;
    uVar2 = Rand();
    iVar1 = (uVar2 & 0x3f) + 0xa8;
  }
  else {
    iVar1 = in_v1 << 0x10;
    if (param_1 != 2) goto LAB_801e8b58;
    uVar2 = Rand();
    iVar1 = (uVar2 & 0x1f) + 0x78;
  }
  iVar1 = iVar1 << 0x10;
LAB_801e8b58:
  return iVar1 >> 0x10;
}


