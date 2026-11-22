// ID 57, STAGE07.BIN, handler 0x801DD1E0. Ghidra output with the object struct applied; not matching C.
// ---- 801dd1e0 FUN_801dd1e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd1e0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e0aec)[obj->state])();
  return;
}


// ---- 801dd21c FUN_801dd21c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd21c(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  iVar1 = (uint)obj->var * 8;
                    /* Possible PsyQ macro: setPolyGT3() */
  obj->dmg_table = (&DAT_801e0a9d)[iVar1];
  obj->contact_dmg = (&DAT_801e0a9e)[iVar1];
  obj->hp = (&DAT_801e0a9f)[iVar1];
  obj->draw_list = (&DAT_801e0aa0)[iVar1];
  obj->hitbox = &UNK_801e0ac4 + (uint)(byte)(&DAT_801e0aa1)[iVar1] * 4;
  obj->box2 = &UNK_801e0ad0 + (uint)(byte)(&DAT_801e0aa2)[iVar1] * 5;
  obj->clut = obj->clut + (&DAT_801e0aa3)[iVar1];
  (*(code *)(&PTR_FUN_801e0b00)[obj->var])(obj);
  obj->state = (&DAT_801e0a9c)[iVar1];
  return;
}


// ---- 801dd304 FUN_801dd304

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd304(MM8Obj *obj)

{
  obj->invuln = 1;
  obj->field_0x51 = 0;
  Anim_Set(obj,9);
  return;
}


// ---- 801dd330 FUN_801dd330

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd330(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  obj->speed_y_up = -0x10000;
  obj->speed_x = 0;
  obj->gravity = 0x4000;
  Anim_Set(obj,5);
  FUN_8010544c(obj,0x1a0);
  return;
}


// ---- 801dd37c FUN_801dd37c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd37c(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  
  uVar3 = (uint)(byte)(obj->var - 2);
  *(undefined **)&obj->field_0x54 = &DAT_801e0ad8 + uVar3 * 10;
  Anim_SetAtStep(obj,obj->var + 1,uVar3 * 6 & 0xfe);
  obj->anim_timer = 2;
  cVar1 = (&DAT_801e0ad8)[uVar3 * 10];
  sVar2 = *(short *)(*(int *)&obj->field_0x4c + 0xe);
  obj->speed_y_up = 0x5c000;
  obj->gravity = 0x4000;
  obj->speed_x = (((int)sVar2 + (int)cVar1) * 0x10000 - *(int *)&obj->x_frac) / 0x30;
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801dd448 FUN_801dd448

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd448(MM8Obj *obj)

{
  undefined1 uVar1;
  
  uVar1 = FUN_80104db0((int)obj->x,(int)obj->y,(int)DAT_801d2928 + (int)*(short *)&obj->field_0x4a,
                       DAT_801d292a + 0xd0);
  FUN_80105120(obj,0x400,uVar1);
  obj->field_0x43 = 1;
  Anim_Set(obj,0xb);
  FUN_8010544c(obj,0x1a9);
  return;
}


// ---- 801dd4c4 FUN_801dd4c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd4c4(MM8Obj *obj)

{
  if ((**(char **)&obj->field_0x4c == '\0') || ((*(char **)&obj->field_0x4c)[6] != 'V')) {
    Obj_Free(obj);
  }
  else {
    if (obj->sub2 == 0) {
      FUN_801dd560(obj);
    }
    else {
      FUN_801dd5b4(obj);
    }
    if (obj->field_0x51 == '\0') {
      Obj_CullAndQueueDraw(obj);
    }
  }
                    /* Possible PsyQ macro: setPolyF3() */
  return;
}


// ---- 801dd560 FUN_801dd560

void FUN_801dd560(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  Anim_Step();
  if (*(short *)(param_1 + 0x2e) < 0) {
    *(undefined1 *)(iVar1 + 0x51) = 0xff;
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return;
}


// ---- 801dd5b4 FUN_801dd5b4

void FUN_801dd5b4(int param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
  *(undefined1 *)(param_1 + 0x25) = *(undefined1 *)(iVar2 + 0x25);
  *(undefined1 *)(param_1 + 0x24) = *(undefined1 *)(iVar2 + 0x24);
  Anim_Step();
  bVar1 = *(byte *)(iVar2 + 0x51);
  if (bVar1 == 0xff) {
    return;
  }
  if ((*(byte *)(iVar2 + 0x51) & 0x80) == 0) {
    Anim_Set(param_1);
  }
  else {
    if (bVar1 == 0x81) {
      *(undefined1 *)(param_1 + 0x51) = 1;
      return;
    }
    if (0x81 < bVar1) {
      if (bVar1 != 0x82) {
        return;
      }
      Obj_Free(param_1);
      return;
    }
    if (bVar1 != 0x80) {
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x51) = 0;
  return;
}


// ---- 801dd694 FUN_801dd694

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd694(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->speed_y_up < -0x5bfff) {
    obj->speed_y_up = -0x60000;
    FUN_80104c34();
  }
  else {
    FUN_80104ccc(obj);
  }
  Anim_Step(obj);
  Enemy_CheckWeaponHits(obj);
  iVar2 = Enemy_ContactDamage(obj);
  if (iVar2 == 0) {
    Obj_CullAndQueueDraw(obj);
    iVar2 = Obj_InActiveArea(obj);
    if (iVar2 != 0) {
      return;
    }
  }
  else {
    iVar2 = FUN_801091a4((int)obj->x,(int)obj->y,0x80);
    if (iVar2 != 0) {
      *(undefined1 *)(iVar2 + 0x27) = 9;
      cVar1 = DAT_8015a004;
      *(undefined1 *)(iVar2 + 0x38) = 0x36;
      *(char *)(iVar2 + 0x24) = cVar1 + '\x02';
      *(byte *)(iVar2 + 0x26) = obj->draw_list;
    }
  }
  Obj_Free(obj);
  return;
}


// ---- 801dd76c FUN_801dd76c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd76c(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x4c;
  (*(code *)(&PTR_FUN_801e0b14)[obj->sub2])();
  if (*(char *)(iVar2 + 0x52) != '\0') {
    bVar1 = *(byte *)(iVar2 + 0x52);
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->sub2 = bVar1;
    if (obj->var == 3) {
      *(undefined1 *)(iVar2 + 0x52) = 0;
    }
  }
  obj->dmg_table = 1;
  Enemy_CheckWeaponHits(obj);
  obj->dmg_table = 2;
  Enemy_ContactDamage(obj);
                    /* Possible PsyQ macro: setPolyGT4() */
  if ((obj->active != 0) && (*(char *)(iVar2 + 0x53) != '\0')) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801dd834 FUN_801dd834

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd834(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
                    /* Possible PsyQ macro: setTile8() */
  iVar2 = *(int *)&obj->field_0x4c;
  Anim_Step();
  FUN_80104ccc(obj);
  sVar1 = *(short *)(iVar2 + 0x12);
  if (sVar1 <= obj->y) {
    obj->y = sVar1;
    obj->sub2 = 2;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801dd89c FUN_801dd89c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd89c(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_801dd8f0();
  }
  else {
    FUN_801dd9b0(obj);
  }
  Anim_Step(obj);
  return;
}


// ---- 801dd8f0 FUN_801dd8f0

void FUN_801dd8f0(int param_1)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  char cVar4;
  undefined1 uVar5;
  
  cVar1 = **(char **)(param_1 + 0x54);
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x4c) + 0xe);
  sVar3 = *(short *)(*(int *)(param_1 + 0x4c) + 0x12);
  if (*(char *)(param_1 + 4) == '\0') {
    *(undefined1 *)(param_1 + 0x50) = 0x10;
    *(undefined1 *)(param_1 + 4) = 1;
  }
  cVar4 = *(char *)(param_1 + 0x50) + -1;
  *(char *)(param_1 + 0x50) = cVar4;
  if (cVar4 == '\0') {
    uVar5 = FUN_80104db0((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),
                         (int)(((int)cVar1 + (uint)uVar2) * 0x10000) >> 0x10,(int)sVar3);
    *(undefined1 *)(param_1 + 0x58) = uVar5;
    FUN_80105120(param_1,0x200,*(undefined1 *)(param_1 + 0x58));
    *(undefined1 *)(param_1 + 3) = 1;
    *(undefined1 *)(param_1 + 4) = 0;
  }
  return;
}


// ---- 801dd9b0 FUN_801dd9b0

void FUN_801dd9b0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_801ddf80();
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 2) = 2;
    *(undefined1 *)(param_1 + 3) = 0;
  }
  return;
}


// ---- 801dd9e8 FUN_801dd9e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd9e8(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  char *pcVar5;
  int iVar6;
  
  pcVar5 = *(char **)&obj->field_0x54;
  iVar6 = *(int *)&obj->field_0x4c;
  if (obj->sub3 == 0) {
    cVar1 = pcVar5[1];
    obj->field_0x5a = 0;
    obj->sub3 = 1;
    obj->field_0x58 = cVar1;
  }
  iVar2 = FUN_801de228(obj);
  if (iVar2 == 0) {
    if (obj->field_0x5a == '\0') goto LAB_801dda84;
    cVar1 = obj->field_0x5a + -1;
  }
  else {
    obj->field_0x5a = obj->field_0x5a + '\x02';
    if ((byte)obj->field_0x5a < 0x30) goto LAB_801dda84;
    cVar1 = '0';
  }
  obj->field_0x5a = cVar1;
LAB_801dda84:
  iVar2 = (int)*pcVar5;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  uVar3 = FUN_801098e8(obj->field_0x58,(int)(short)iVar2,0);
  obj->x_frac = (short)uVar3;
  obj->x = (short)((uint)uVar3 >> 0x10);
  uVar3 = FUN_801098e8((byte)obj->field_0x58 + 0x40,(int)(short)iVar2,0x30);
  bVar4 = 7;
  obj->y_frac = (short)uVar3;
  obj->y = (short)((uint)uVar3 >> 0x10);
  *(int *)&obj->x_frac = *(int *)&obj->x_frac + *(int *)(iVar6 + 0xc);
  obj->y = obj->y + (short)(char)obj->field_0x5a + *(short *)(iVar6 + 0x12);
  if ((obj->field_0x58 + 0x40 & 0x80) != 0) {
    bVar4 = 6;
  }
  obj->draw_list = bVar4;
  obj->field_0x58 = obj->field_0x58 + '\x04';
  Anim_Step();
  return;
}


// ---- 801ddb40 FUN_801ddb40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddb40(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_801ddb94();
  }
  else {
    FUN_801ddc14(obj);
  }
  Anim_Step(obj);
  return;
}


// ---- 801ddb94 FUN_801ddb94

void FUN_801ddb94(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)DAT_801d2928;
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x54) + 2);
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x54) + 4);
  uVar3 = (uint)DAT_801d292a;
  *(undefined1 *)(param_1 + 3) = 1;
  *(int *)(param_1 + 0x14) = (int)((uVar4 + uVar1) * 0x10000 - *(int *)(param_1 + 0xc)) / 0x14;
  *(int *)(param_1 + 0x18) = (int)(*(int *)(param_1 + 0x10) + (uVar3 + uVar2) * -0x10000) / 0x14;
  return;
}


// ---- 801ddc14 FUN_801ddc14

void FUN_801ddc14(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4c);
  sVar1 = DAT_801d2928 + *(short *)(*(int *)(param_1 + 0x54) + 2);
  sVar2 = DAT_801d292a + *(short *)(*(int *)(param_1 + 0x54) + 4);
  if (*(char *)(param_1 + 4) == '\0') {
    FUN_80104c34(param_1);
    if (*(int *)(param_1 + 0x18) < 1) {
      if (*(short *)(param_1 + 0x12) < sVar2) {
        return;
      }
    }
    else if (sVar2 < *(short *)(param_1 + 0x12)) {
      return;
    }
    *(short *)(param_1 + 0xe) = sVar1;
    *(short *)(param_1 + 0x12) = sVar2;
                    /* Possible PsyQ macro: setLineF2() */
    *(char *)(iVar3 + 0x58) = *(char *)(iVar3 + 0x58) + '\x01';
    *(undefined1 *)(param_1 + 4) = 1;
  }
  return;
}


// ---- 801ddcfc FUN_801ddcfc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddcfc(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e0b34)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801ddf14 FUN_801ddf14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddf14(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x4c;
  if ((obj->sub3 == 0) && (iVar1 = FUN_801ddf80(), iVar1 != 0)) {
    *(char *)(iVar2 + 0x58) = *(char *)(iVar2 + 0x58) + '\x01';
    obj->sub3 = 1;
  }
  Anim_Step(obj);
  return;
}


// ---- 801ddf80 FUN_801ddf80

undefined4 FUN_801ddf80(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  
  sVar1 = *(short *)(param_1 + 0xe);
  sVar2 = *(short *)(param_1 + 0x12);
  sVar3 = *(short *)(*(int *)(param_1 + 0x4c) + 0x12);
  iVar6 = (int)**(char **)(param_1 + 0x54) + (uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 0xe);
                    /* Possible PsyQ macro: setLineF2() */
  iVar7 = FUN_80104db0((int)sVar1,(int)sVar2,iVar6 * 0x10000 >> 0x10);
  iVar7 = (int)((iVar7 - (uint)*(byte *)(param_1 + 0x58)) * 0x1000000) >> 0x18;
  if (iVar7 != 0) {
    cVar4 = *(char *)(param_1 + 0x58) + '\x04';
    if (iVar7 < 1) {
      cVar4 = *(char *)(param_1 + 0x58) + -4;
    }
    *(char *)(param_1 + 0x58) = cVar4;
    FUN_80105120(param_1,0x200,*(undefined1 *)(param_1 + 0x58));
  }
  FUN_80104c34(param_1);
  sVar5 = (short)iVar6;
  iVar6 = (int)sVar1 - (int)sVar5;
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  if (iVar6 < 4) {
    iVar6 = (int)sVar2 - (int)sVar3;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if (iVar6 < 4) {
      *(short *)(param_1 + 0xe) = sVar5;
      *(short *)(param_1 + 0x12) = sVar3;
      return 1;
    }
  }
  return 0;
}


// ---- 801de0a0 FUN_801de0a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de0a0(MM8Obj *obj)

{
  FUN_80108e84();
  FUN_8012a5fc(obj,4);
  Obj_Free(obj);
  return;
}


// ---- 801de0dc FUN_801de0dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de0dc(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    switchD_801ddf1c::caseD_4();
  }
  else {
    FUN_801de140();
  }
  return;
}


// ---- 801de11c caseD_4

void switchD_801ddf1c::caseD_4(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0xffffc000;
  *(undefined4 *)(param_1 + 0x20) = 0x4000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x58) = 0;
  *(undefined1 *)(param_1 + 3) = 1;
  return;
}


// ---- 801de140 FUN_801de140

void FUN_801de140(int param_1)

{
  short sVar1;
  
  if (*(byte *)(param_1 + 4) < 2) {
    sVar1 = *(short *)(param_1 + 0xe);
                    /* Possible PsyQ macro: setLineF2() */
    if ((int)sVar1 < DAT_801d2928 + 0x18) {
      *(short *)(param_1 + 0xe) = sVar1 + 4;
    }
    else if (DAT_801d2928 + 0x128 < (int)sVar1) {
      *(short *)(param_1 + 0xe) = sVar1 + -4;
    }
    else {
      if (*(int *)(param_1 + 0x18) < -0x5bfff) {
        *(undefined4 *)(param_1 + 0x18) = 0xfffa0000;
        FUN_80104c34(param_1);
      }
      else {
        FUN_80104ccc(param_1);
      }
      FUN_80106214(param_1);
      if ((*(byte *)(param_1 + 0x33) & 0x80) != 0) {
        FUN_8010544c(param_1,0x1a1);
        *(undefined4 *)(param_1 + 0x18) = 0x2e000;
        *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
      }
    }
  }
  return;
}


// ---- 801de228 FUN_801de228

undefined4 FUN_801de228(int param_1)

{
  int *piVar1;
  char *pcVar2;
  
  pcVar2 = &DAT_801d184c;
  piVar1 = &DAT_801d1868;
  while (((*pcVar2 == '\0' || (*(char *)((int)piVar1 + -0x16) != '\x06')) || (param_1 != *piVar1)))
  {
    pcVar2 = pcVar2 + 0x40;
    piVar1 = piVar1 + 0x10;
    if (&DAT_801d284c <= pcVar2) {
      return 0;
    }
  }
  return 1;
}


// ---- 801de298 FUN_801de298

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de298(MM8Obj *obj)

{
  FUN_80104c34();
  Anim_Step(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0xf0) == 0) {
    Enemy_ContactDamage(obj);
    if (DAT_80170574 == (DAT_80170574 / 3) * 3) {
      FUN_801de344((int)obj->x,(int)obj->y,0xc,obj->draw_list);
    }
    Obj_CullAndQueueDraw(obj);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801de344 FUN_801de344

int FUN_801de344(short param_1,short param_2,undefined1 param_3,undefined1 param_4)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_801091a4((int)param_1,(int)param_2,0x80);
                    /* Possible PsyQ macro: setLineF2() */
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 0x27) = 0xa0;
    cVar1 = DAT_8015a004;
    *(undefined1 *)(iVar2 + 0x38) = param_3;
    *(undefined1 *)(iVar2 + 0x26) = param_4;
    *(char *)(iVar2 + 0x24) = cVar1 + '\x01';
  }
                    /* Possible PsyQ macro: setPolyF4() */
  return iVar2;
}


