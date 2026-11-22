// T3_16, STAGE04.BIN, handler 0x801E63D0. Ghidra output with the object struct applied; not matching C.
// ---- 801e63d0 FUN_801e63d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e63d0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e74f0)[obj->state])();
  return;
}


// ---- 801e640c FUN_801e640c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e640c(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = FUN_801e6810();
  if (iVar4 == 0) {
    obj->state = obj->state + 1;
    if (obj->var == 0) {
      obj->x = (DAT_801d2918._2_2_ - DAT_801d2948._2_2_) + 0x380;
      sVar3 = (g_cam_y - DAT_801d294c) + 0x5a8;
    }
    else if (obj->var == 1) {
      obj->x = (DAT_801d2918._2_2_ - DAT_801d2948._2_2_) + 0x380;
      sVar3 = (g_cam_y - DAT_801d294c) + 0x1258;
    }
    else {
      obj->x = (DAT_801d2918._2_2_ - DAT_801d2948._2_2_) + 0x380;
      sVar3 = (g_cam_y - DAT_801d294c) + 0x17a8;
    }
    obj->y = sVar3;
    bVar1 = DAT_80159f9c;
    obj->draw_list = 0xb;
    obj->flip = 0;
                    /* Possible PsyQ macro: setPolyG4() */
    obj->bank = 0x38;
    obj->clut = bVar1;
    obj->vram_base = DAT_801703b8;
    Anim_Set(obj,0);
    FUN_801e66a0(obj);
    cVar2 = FUN_801e6724(obj);
    if (cVar2 != '\0') {
      return;
    }
  }
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801e6578 FUN_801e6578

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6578(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  
  Anim_Step();
  if (obj->var == 0) {
    obj->x = (DAT_801d2918._2_2_ - DAT_801d2948._2_2_) + 0x380;
    sVar2 = (g_cam_y - DAT_801d294c) + 0x5a8;
  }
  else if (obj->var == 1) {
    obj->x = (DAT_801d2918._2_2_ - DAT_801d2948._2_2_) + 0x380;
    sVar2 = (g_cam_y - DAT_801d294c) + 0x1258;
  }
  else {
    obj->x = (DAT_801d2918._2_2_ - DAT_801d2948._2_2_) + 0x380;
    sVar2 = (g_cam_y - DAT_801d294c) + 0x17a8;
  }
  obj->y = sVar2;
  FUN_801e66a0(obj);
  cVar1 = FUN_801e6724(obj);
  if (cVar1 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e66a0 FUN_801e66a0

void FUN_801e66a0(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 5) = 0;
  iVar1 = (int)((DAT_801d2918._2_2_ - 0x80) * 0x10000) >> 0x10;
  if ((iVar1 < *(short *)(param_1 + 0xe)) && ((int)*(short *)(param_1 + 0xe) < iVar1 + 0x240)) {
    iVar1 = (int)((g_cam_y - 0x80) * 0x10000) >> 0x10;
    if ((iVar1 < *(short *)(param_1 + 0x12)) && ((int)*(short *)(param_1 + 0x12) < iVar1 + 0x240)) {
      *(undefined1 *)(param_1 + 5) = 1;
      Obj_QueueDraw();
    }
  }
  return;
}


// ---- 801e6724 FUN_801e6724

bool FUN_801e6724(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  
  if (*(char *)(param_1 + 7) == '\0') {
    sVar4 = *(short *)(param_1 + 0xe) + DAT_801d2948._2_2_ + -0x380;
    uVar3 = (uint)*(ushort *)(param_1 + 0x12);
    iVar2 = DAT_801d294c - 0x5a8;
  }
  else if (*(char *)(param_1 + 7) == '\x01') {
    sVar4 = *(short *)(param_1 + 0xe) + DAT_801d2948._2_2_ + -0x380;
    uVar3 = (uint)*(ushort *)(param_1 + 0x12);
    iVar2 = DAT_801d294c - 0x1258;
  }
  else {
    sVar4 = *(short *)(param_1 + 0xe) + DAT_801d2948._2_2_ + -0x380;
    uVar3 = (uint)*(ushort *)(param_1 + 0x12);
    iVar2 = DAT_801d294c - 0x17a8;
  }
  bVar1 = false;
  if ((DAT_801d2918._2_2_ + -0x80 < (int)sVar4) && ((int)sVar4 < DAT_801d2918._2_2_ + 0x1c0)) {
    iVar2 = (int)((uVar3 + iVar2) * 0x10000) >> 0x10;
    if (g_cam_y + -0x80 < iVar2) {
      bVar1 = iVar2 < g_cam_y + 0x170;
    }
  }
  return bVar1;
}


// ---- 801e6810 FUN_801e6810

undefined4 FUN_801e6810(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = &DAT_801cf848;
  pcVar2 = (char *)((int)&DAT_801cf84c + 3);
  while ((((*pcVar1 == '\0' || (pcVar2[-1] != param_1[6])) || (param_1 == pcVar1)) ||
         (*pcVar2 != param_1[7]))) {
    pcVar1 = pcVar1 + 0x40;
    pcVar2 = pcVar2 + 0x40;
    if (&DAT_801d1848 <= pcVar1) {
      return 0;
    }
  }
  return 1;
}


