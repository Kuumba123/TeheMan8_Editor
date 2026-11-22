// T2_01, STAGE00.BIN, handler 0x801DD90C. Ghidra output with the object struct applied; not matching C.
// ---- 801dd90c FUN_801dd90c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd90c(MM8Obj *obj)

{
  if (obj->state == 0) {
    FUN_801dd980(obj);
  }
  else {
    FUN_801dda38();
  }
  if (obj->state == 2) {
    Obj_Free(obj);
  }
  else {
    Obj_QueueDraw(obj);
  }
  return;
}


// ---- 801dd980 FUN_801dd980

void FUN_801dd980(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  
  *(undefined1 *)(param_1 + 0x27) = 10;
  *(undefined2 *)(param_1 + 0x2c) = DAT_8017035c;
  uVar1 = DAT_80159f6e;
  uVar3 = 0x10000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x24) = uVar1;
  if (*(char *)(param_1 + 7) != '\0') {
    uVar3 = 0xffff0000;
  }
  *(undefined1 *)(param_1 + 0x26) = 7;
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  *(undefined **)(param_1 + 0x38) = &DAT_801e283c;
  bVar2 = 2;
  if (DAT_801b2988 < *(short *)(param_1 + 0x12)) {
    bVar2 = 1;
  }
  bVar4 = 0;
  *(byte *)(param_1 + 0x44) = bVar2;
  if (*(char *)(param_1 + 7) == '\0') {
    bVar4 = bVar2 & 2;
  }
  Anim_Set(param_1,bVar4);
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)(param_1 + 2) = 0;
  return;
}


// ---- 801dda38 FUN_801dda38

void FUN_801dda38(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    FUN_801ddb28(param_1,(int)g_cam_y);
  }
  else {
    FUN_801ddc64(param_1,(int)g_cam_y);
  }
  FUN_80104c34(param_1);
  Anim_Step(param_1);
  iVar1 = 0;
  if (0x340 < *(short *)(param_1 + 0x12)) {
    iVar1 = FUN_80107bf4(param_1,&g_player,5);
  }
  if (iVar1 == 0) {
    *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) & 7;
  }
  else if ((*(byte *)(param_1 + 0x44) & 8) == 0) {
    *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x80;
  }
  if (DAT_801d2918._2_2_ + 0x178 < (int)*(short *)(param_1 + 0xe)) {
    *(undefined1 *)(param_1 + 1) = 2;
  }
  return;
}


// ---- 801ddb28 FUN_801ddb28

void FUN_801ddb28(int param_1)

{
  byte bVar1;
  short sVar2;
  
  sVar2 = *(short *)(param_1 + 0x12);
  if (((*(byte *)(param_1 + 0x44) & 1) != 0) && (sVar2 + -0x18 < (int)DAT_801b2988)) {
    *(undefined1 *)(param_1 + 0x44) = 4;
    Anim_Set(param_1,1);
    FUN_80109318(param_1,0xffffffe8);
  }
  if (((*(byte *)(param_1 + 0x44) & 4) != 0) && (*(short *)(param_1 + 0x2e) < 0)) {
    *(undefined1 *)(param_1 + 0x44) = 2;
    Anim_Set(param_1,2);
  }
  if ((((*(uint *)(param_1 + 0x44) & 10) == 10) && (*(char *)(param_1 + 2) != '\0')) &&
     (*(short *)(param_1 + 0x2e) < 0)) {
    Anim_Set(param_1,2);
    *(undefined1 *)(param_1 + 2) = 0;
  }
  bVar1 = *(byte *)(param_1 + 0x44);
  if (((bVar1 & 0x80) != 0) && (*(byte *)(param_1 + 0x44) = bVar1 & 0x7f | 8, (bVar1 & 4) == 0)) {
    Anim_Set(param_1,3);
    *(undefined1 *)(param_1 + 2) = 1;
  }
  if (sVar2 < 0x288) {
    *(undefined1 *)(param_1 + 1) = 2;
  }
  return;
}


// ---- 801ddc64 FUN_801ddc64

void FUN_801ddc64(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x12);
  if (((*(byte *)(param_1 + 0x44) & 2) != 0) && ((int)DAT_801b2988 < sVar1 + 0x10)) {
    *(undefined1 *)(param_1 + 0x44) = 1;
    FUN_80109318(param_1,0xe);
  }
  if ((*(byte *)(param_1 + 0x44) & 0x80) != 0) {
    *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) & 0x7f | 8;
    Anim_Set(param_1,3);
  }
  if (0x598 < sVar1) {
    *(undefined1 *)(param_1 + 1) = 2;
  }
  return;
}


