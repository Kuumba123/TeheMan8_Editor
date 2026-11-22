// T2_28, STAGE02.BIN, handler 0x801E438C. Ghidra output with the object struct applied; not matching C.
// ---- 801e438c FUN_801e438c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e438c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8a58)[obj->state])();
  return;
}


// ---- 801e43c8 FUN_801e43c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e43c8(MM8Obj *obj)

{
  int iVar1;
  
  obj->bank = 0x7b;
  obj->vram_base = DAT_8017043e;
  iVar1 = (uint)obj->var * 4;
  obj->clut = DAT_80159fdf;
  obj->draw_list = (&DAT_801e8a45)[iVar1];
  Anim_Set(obj,(&DAT_801e8a44)[iVar1]);
  if ((byte)(&DAT_801e8a47)[iVar1] != 0xff) {
    (*(code *)(&PTR_LAB_801e8a64)[(byte)(&DAT_801e8a47)[iVar1]])(obj);
  }
  obj->state = (&DAT_801e8a46)[iVar1];
  return;
}


// ---- 801e44a4 FUN_801e44a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e44a4(MM8Obj *obj)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (obj->sub2 == 0) {
    pcVar2 = *(char **)&obj->dmg_table;
    if ((((*pcVar2 != '\0') && (pcVar2[6] == '@')) && (pcVar2[0x30] == '\x19')) &&
       (pcVar2[0x51] == '\x01')) {
      if ((pcVar2[0x25] & 0x40U) == 0) {
        uVar3 = 6;
      }
      else {
        uVar3 = 7;
      }
      Anim_Set(obj,uVar3);
      obj->sub2 = 1;
    }
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      Anim_Set(obj,5);
      obj->sub2 = 0;
    }
  }
  Obj_CullAndQueueDraw(obj);
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e4598 FUN_801e4598

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4598(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    FUN_801e45fc();
  }
  else {
    FUN_801e4764(obj);
  }
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e45fc FUN_801e45fc

void FUN_801e45fc(int param_1)

{
  byte bVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x44);
  *(short *)(param_1 + 0xe) =
       *(short *)(pcVar2 + 0xe) +
       ((short)((*(short *)(pcVar2 + 0x5a) - *(short *)(pcVar2 + 0xe)) *
               (ushort)*(byte *)(param_1 + 0x48)) >> 4);
  *(short *)(param_1 + 0x12) =
       *(short *)(pcVar2 + 0x12) +
       ((short)((*(short *)(pcVar2 + 0x58) - *(short *)(pcVar2 + 0x12)) *
               (ushort)*(byte *)(param_1 + 0x48)) >> 4);
  FUN_801e47b4(param_1,pcVar2[0x5c]);
  if (*(char *)(param_1 + 7) == '\x04') {
    bVar1 = pcVar2[0x51];
    if (bVar1 == 1) {
      *(byte *)(param_1 + 0x25) = *(byte *)(param_1 + 0x25) ^ 0xc0;
    }
    else {
      if (bVar1 < 2) {
        if (bVar1 != 0) goto LAB_801e46f8;
        *(undefined1 *)(param_1 + 0x30) = 3;
        goto LAB_801e46ec;
      }
      if (bVar1 != 2) goto LAB_801e46f8;
    }
    Anim_Set(param_1,4);
  }
  else {
LAB_801e46ec:
    FUN_801e47b4(param_1,pcVar2[0x5c]);
  }
LAB_801e46f8:
  if (((*pcVar2 == '\0') || ((*(uint *)(pcVar2 + 4) & 0x7fff0000) != 0x400000)) ||
     (pcVar2[0x55] == '\x01')) {
    Obj_Free(param_1);
  }
  else if (pcVar2[0x55] == '\x02') {
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return;
}


// ---- 801e4764 FUN_801e4764

void FUN_801e4764(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_801050e4(param_1,*(undefined4 *)(param_1 + 0x44));
  FUN_80105120(param_1,0x600,uVar1);
  FUN_80104c34(param_1);
  Obj_CullAndQueueDraw(param_1);
  return;
}


// ---- 801e47b4 FUN_801e47b4

void FUN_801e47b4(int param_1,int param_2)

{
  if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
    param_2 = -param_2;
  }
  Anim_SetAtStep(param_1,*(undefined1 *)(param_1 + 0x30),(param_2 + 0x48U & 0xff) >> 4);
  return;
}


