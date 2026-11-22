// ID 17, STAGE03.BIN, handler 0x801DC7D8. Ghidra output with the object struct applied; not matching C.
// ---- 801dc7d8 FUN_801dc7d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc7d8(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e9b9c)[obj->state])();
  if (DAT_801d2915 == '\x01') {
    obj->x = obj->x + DAT_801d293a;
  }
  if ((((obj->field_0x59 != '\0') && (obj->active != 0)) &&
      (Obj_CullAndQueueDraw(obj), obj->field_0x5a != '\0')) &&
     (iVar1 = Obj_InActiveArea(obj), iVar1 == 0)) {
    Obj_FreeDespawn(obj);
  }
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801dc89c FUN_801dc89c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc89c(MM8Obj *obj)

{
  undefined1 uVar1;
  short sVar2;
  word wVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  
  obj->bank = 0x35;
  wVar3 = DAT_801703b2;
  obj->draw_list = 6;
  obj->dmg_table = 2;
  uVar5._0_2_ = obj->x_frac;
  uVar5._2_2_ = obj->x;
  obj->field_0x43 = 1;
  obj->field_0x59 = 1;
  obj->invuln = 1;
  obj->flip = 0;
  obj->field_0x5a = 0;
  obj->vram_base = wVar3;
  obj->x_frac = (short)(uVar5 & 0xffff0000);
  obj->x = (short)((uVar5 & 0xffff0000) >> 0x10);
  uVar6._0_2_ = obj->y_frac;
  uVar6._2_2_ = obj->y;
  obj->y_frac = (short)(uVar6 & 0xffff0000);
  obj->y = (short)((uVar6 & 0xffff0000) >> 0x10);
  switch(obj->var & 0xf) {
  case 0:
    bVar4 = 1;
    break;
  case 1:
    obj->state = 2;
    obj->sub2 = 2;
    goto LAB_801dc958;
  case 2:
    bVar4 = 2;
    break;
  case 3:
    obj->state = 2;
    sVar2 = obj->x;
    obj->field_0x50 = 0;
    sVar7 = obj->y + 0x40;
    goto LAB_801dc9b4;
  case 4:
    obj->state = 2;
    obj->field_0x50 = 0x80;
    sVar2 = obj->x;
    sVar7 = obj->y + -0x40;
LAB_801dc9b4:
    obj->x = sVar2 + -0x80;
    obj->y = sVar7;
    FUN_801dca38();
    return;
  case 5:
  case 6:
    obj->state = 3;
    obj->hitbox = &DAT_801e9b48;
    obj->hp = 4;
    obj->contact_dmg = 6;
    obj->clut = obj->field_0x5b;
    *(undefined2 *)&obj->field_0x4a = *(undefined2 *)(*(int *)&obj->field_0x5c + 0x4a);
    obj->field_0x55 = *(undefined1 *)(*(int *)&obj->field_0x5c + 0x55);
    uVar1 = *(undefined1 *)(*(int *)&obj->field_0x5c + 0x54);
    obj->field_0x53 = 1;
    obj->field_0x57 = 0;
    obj->field_0x58 = 0;
    obj->field_0x54 = uVar1;
  default:
    goto switchD_801dc924_default;
  }
  obj->state = bVar4;
LAB_801dc958:
  obj->field_0x50 = 0xc0;
  FUN_801dca38();
switchD_801dc924_default:
  return;
}


// ---- 801dca38 FUN_801dca38

void FUN_801dca38(undefined1 *param_1)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  short sVar4;
  undefined1 *puVar5;
  short sVar6;
  undefined1 *puVar7;
  uint uVar8;
  
  param_1[0x53] = 1;
  param_1[0x56] = 0;
  cVar2 = DAT_80159f99;
  param_1[0x24] = DAT_80159f99;
  if ((param_1[7] & 0xf) != 0) {
    param_1[0x24] = cVar2 + '\x01';
  }
                    /* Probable PsyQ macro: setPolyGT4() */
  *(undefined **)(param_1 + 0x3c) = &DAT_801e9b44;
  param_1[0x47] = 0x12;
  param_1[0x45] = 6;
  param_1[0x55] = 2;
                    /* Probable PsyQ macro: setLineF2() */
  param_1[0x52] = 0;
  param_1[0x5b] = param_1[0x24];
  param_1[0x51] = param_1[0x50];
  if ((param_1[7] & 0xf) == 3) {
    sVar6 = 0;
    sVar4 = 0x12;
  }
  else {
                    /* Possible PsyQ macro: setLineF2() */
    sVar6 = 0;
    if ((param_1[7] & 0xf) == 4) {
      sVar4 = -0x12;
    }
    else {
      sVar6 = 0x12;
      sVar4 = 0;
    }
  }
  uVar8 = 0;
  bVar1 = param_1[7];
  puVar7 = param_1;
  do {
    puVar5 = (undefined1 *)FUN_801055e4(puVar7);
    uVar8 = uVar8 + 1;
    if (puVar5 == (undefined1 *)0x0) break;
    *puVar5 = 1;
    puVar5[6] = 0x17;
    puVar5[7] = bVar1 & 0xf0 | 5;
    puVar5[0x5b] = param_1[0x5b];
    *(short *)(puVar5 + 0xe) = *(short *)(param_1 + 0xe) + (short)uVar8 * sVar6;
    *(short *)(puVar5 + 0x12) = *(short *)(param_1 + 0x12) + (short)uVar8 * sVar4;
    uVar3 = param_1[0x50];
    puVar5[0x56] = 0;
    puVar5[0x51] = uVar3;
    uVar3 = FUN_801050e4(puVar5,puVar7);
    puVar5[0x50] = uVar3;
    *(undefined1 **)(puVar7 + 0x4c) = puVar5;
    *(undefined1 **)(puVar5 + 0x5c) = puVar7;
    param_1[0x5c] = param_1[0x5c] + '\x01';
    puVar7 = puVar5;
  } while (uVar8 < 8);
  puVar5[7] = bVar1 & 0xf0 | 6;
  puVar5[0x56] = 1;
  *(undefined4 *)(puVar5 + 0x4c) = 0;
  *(undefined2 *)(param_1 + 0x4a) = 0x140;
  FUN_80105120(param_1,0x140,param_1[0x50]);
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801dcc14 FUN_801dcc14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcc14(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9bb0)[obj->sub2])();
  FUN_801ddb0c(obj);
  Enemy_ContactDamage(obj);
  FUN_801ddce8(obj);
  return;
}


// ---- 801dcc74 FUN_801dcc74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcc74(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = obj->field_0x53 + -1;
  obj->field_0x53 = cVar1;
  if (cVar1 == '\0') {
    FUN_801ddc38();
    obj->field_0x53 = obj->field_0x55;
    cVar1 = (&DAT_801e9b4c)[(byte)obj->field_0x52 >> 1];
    obj->field_0x52 = obj->field_0x52 + 1 & 0xf;
    obj->field_0x50 = obj->field_0x50 + cVar1;
  }
  FUN_80105120(obj,*(undefined2 *)&obj->field_0x4a,obj->field_0x50);
  FUN_80104c34(obj);
  if ((int)obj->x - (int)DAT_801d2918._2_2_ < 0xb4) {
    obj->sub2 = 1;
    obj->field_0x5d = 0x4b;
    obj->field_0x55 = 2;
    obj->field_0x52 = 0;
    obj->field_0x51 = obj->field_0x50;
  }
  uVar2 = FUN_801ddc14(obj->field_0x50);
  Anim_SetAtStep(obj,0,uVar2);
  return;
}


// ---- 801dcd68 FUN_801dcd68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcd68(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  
  if (obj->sub3 == 0) {
    FUN_801dce44();
  }
  else {
    FUN_801dcf10(obj);
  }
  FUN_80105120(obj,*(undefined2 *)&obj->field_0x4a,obj->field_0x50);
  FUN_80104c34(obj);
  if ((DAT_80170574 & 3) == 0) {
    cVar1 = obj->field_0x5d + -1;
    obj->field_0x5d = cVar1;
    uVar2 = 0xff;
    if (cVar1 == '\0') {
      obj->sub2 = 2;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      obj->field_0x53 = 0xb4;
      if ((char)obj->field_0x51 < '\0') {
        uVar2 = 1;
      }
      obj->field_0x51 = uVar2;
    }
  }
  uVar2 = FUN_801ddc14(obj->field_0x50);
  Anim_SetAtStep(obj,0,uVar2);
  return;
}


// ---- 801dce44 FUN_801dce44

void FUN_801dce44(int param_1)

{
  byte bVar1;
  char cVar2;
  
  cVar2 = *(char *)(param_1 + 0x53) + -1;
  *(char *)(param_1 + 0x53) = cVar2;
  if (cVar2 == '\0') {
    FUN_801ddc38();
    *(undefined1 *)(param_1 + 0x53) = *(undefined1 *)(param_1 + 0x55);
    if (*(char *)(param_1 + 0x51) < '\0') {
      cVar2 = *(char *)(param_1 + 0x50) - (&DAT_801e9b4c)[*(byte *)(param_1 + 0x52) >> 1];
    }
    else {
      cVar2 = *(char *)(param_1 + 0x50) + (&DAT_801e9b4c)[*(byte *)(param_1 + 0x52) >> 1];
    }
    *(char *)(param_1 + 0x50) = cVar2;
    bVar1 = *(char *)(param_1 + 0x52) + 1;
    *(byte *)(param_1 + 0x52) = bVar1;
    if (0xf < bVar1) {
      *(undefined1 *)(param_1 + 3) = 1;
      *(undefined1 *)(param_1 + 0x52) = *(undefined1 *)(param_1 + 0x54);
    }
  }
  return;
}


// ---- 801dcf10 FUN_801dcf10

void FUN_801dcf10(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  cVar1 = *(char *)(param_1 + 0x53) + -1;
  *(char *)(param_1 + 0x53) = cVar1;
  if (cVar1 == '\0') {
    FUN_801ddc38();
    *(undefined1 *)(param_1 + 0x53) = *(undefined1 *)(param_1 + 0x55);
    iVar2 = FUN_801050e4(param_1,&g_player);
    uVar3 = (uint)*(byte *)(param_1 + 0x50) - iVar2;
    if ((uVar3 & 0xff) != 0) {
      cVar1 = *(char *)(param_1 + 0x50) + -8;
      if ((int)(uVar3 * 0x1000000) < 0) {
        cVar1 = *(char *)(param_1 + 0x50) + '\b';
      }
      *(char *)(param_1 + 0x50) = cVar1;
    }
    *(char *)(param_1 + 0x51) = (char)uVar3;
    cVar1 = *(char *)(param_1 + 0x52) + -1;
    *(char *)(param_1 + 0x52) = cVar1;
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 0x52) = 0;
    }
  }
  return;
}


// ---- 801dcfc4 FUN_801dcfc4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcfc4(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_801dd004();
  }
  else {
    FUN_801dd144();
  }
  return;
}


// ---- 801dd004 FUN_801dd004

void FUN_801dd004(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  
  *(char *)(param_1 + 0x50) = *(char *)(param_1 + 0x50) + *(char *)(param_1 + 0x51) * '\x04';
  FUN_80105120(param_1,*(undefined2 *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x50));
  FUN_80104c34(param_1);
  if (*(char *)(param_1 + 4) == '\0') {
    cVar1 = *(char *)(param_1 + 0x53) + -1;
    *(char *)(param_1 + 0x53) = cVar1;
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x53) = 4;
      bVar2 = FUN_801050e4(param_1,&g_player);
      *(byte *)(param_1 + 0x52) = bVar2 & 0xf0;
    }
  }
  else {
    cVar1 = *(char *)(param_1 + 0x53) + -1;
    *(char *)(param_1 + 0x53) = cVar1;
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 0x53) = 4;
      iVar5 = *(int *)(param_1 + 0x4c);
      if ((*(char *)(param_1 + 0x56) == '\0') && (iVar4 = FUN_801ddbd0(param_1,iVar5), iVar4 != 0))
      {
        *(undefined1 *)(iVar5 + 0x57) = 2;
        *(undefined1 *)(iVar5 + 0x58) = *(undefined1 *)(param_1 + 0x52);
        *(char *)(param_1 + 0x52) = *(char *)(param_1 + 0x52) + *(char *)(param_1 + 0x51);
      }
      else {
        *(undefined1 *)(param_1 + 3) = 1;
        *(undefined1 *)(param_1 + 4) = 0;
      }
    }
  }
  uVar3 = FUN_801ddc14(*(undefined1 *)(param_1 + 0x50));
  Anim_SetAtStep(param_1,0,uVar3);
  return;
}


// ---- 801dd144 FUN_801dd144

void FUN_801dd144(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  
  if (*(char *)(param_1 + 4) == '\0') {
    *(undefined1 *)(param_1 + 4) = 1;
    FUN_80105120(param_1,0x300,*(undefined1 *)(param_1 + 0x52));
    *(undefined1 *)(param_1 + 0x5a) = 1;
    *(undefined1 *)(param_1 + 0x31) = 1;
  }
  else {
    uVar2 = FUN_801ddc14(*(undefined1 *)(param_1 + 0x50),0x300);
    Anim_SetAtStep(param_1,0,uVar2);
    if (*(char *)(param_1 + 0x52) == '\0') {
      bVar1 = *(byte *)(param_1 + 0x51);
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x52);
    }
    cVar3 = *(char *)(param_1 + 0x50) + '\x10';
    if ((int)((uint)bVar1 << 0x18) < 0) {
      cVar3 = *(char *)(param_1 + 0x50) + -0x10;
    }
    *(char *)(param_1 + 0x50) = cVar3;
  }
  FUN_80104c34(param_1);
  return;
}


// ---- 801dd1f8 FUN_801dd1f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd1f8(MM8Obj *obj)

{
  undefined1 uVar1;
  
  (*(code *)(&PTR_FUN_801e9bbc)[obj->sub2])();
  uVar1 = FUN_801ddc14(obj->field_0x50);
  Anim_SetAtStep(obj,0,uVar1);
  FUN_801ddb0c(obj);
  Enemy_ContactDamage(obj);
  FUN_801ddce8(obj);
  return;
}


// ---- 801dd274 FUN_801dd274

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd274(MM8Obj *obj)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  
  FUN_801dd4d4();
  bVar2 = obj->var & 0xf;
  if (bVar2 == 3) {
    if (0x3f < (int)obj->y - (int)g_cam_y) {
      return;
    }
  }
  else {
    if (bVar2 < 4) {
      if (bVar2 != 2) {
        return;
      }
      if (0x5f < (int)obj->x - (int)DAT_801d2918._2_2_) {
        return;
      }
      iVar3._0_2_ = obj->y_frac;
      iVar3._2_2_ = obj->y;
      obj->sub2 = 1;
      obj->field_0x53 = 6;
      uVar1 = 0x80;
      if (DAT_8015e24c < iVar3) {
        obj->field_0x51 = 0;
        return;
      }
      goto LAB_801dd374;
    }
    if (bVar2 != 4) {
      return;
    }
    if ((int)obj->y - (int)g_cam_y < 0x91) {
      return;
    }
  }
  obj->sub2 = 1;
  obj->field_0x53 = 6;
  uVar1 = 0xc0;
LAB_801dd374:
  obj->field_0x51 = uVar1;
  return;
}


// ---- 801dd38c FUN_801dd38c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd38c(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = obj->field_0x53 + -1;
  obj->field_0x53 = cVar1;
  if (cVar1 == '\0') {
    obj->field_0x53 = 6;
    uVar2 = (uint)(byte)obj->field_0x50 - (uint)(byte)obj->field_0x51;
    if ((uVar2 & 0xf0) == 0) {
      obj->sub2 = 2;
      obj->field_0x52 = 0;
      obj->field_0x50 = obj->field_0x51;
      obj->field_0x53 = obj->field_0x55;
    }
    else {
      cVar1 = obj->field_0x50 + -0x10;
      if ((int)(uVar2 * 0x1000000) < 1) {
        cVar1 = obj->field_0x50 + '\x10';
      }
      obj->field_0x50 = cVar1;
    }
  }
  FUN_80105120(obj,*(undefined2 *)&obj->field_0x4a,obj->field_0x50);
  FUN_80104c34(obj);
  return;
}


// ---- 801dd434 FUN_801dd434

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd434(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  FUN_801dd4d4();
  if ((0x360 < ((int)obj->y - (int)g_cam_y) + 0x138U) ||
     ((int)obj->x - (int)DAT_801d2918._2_2_ < -0x164)) {
    iVar2 = *(int *)&obj->field_0x4c;
    if ((obj->field_0x56 == '\0') && (iVar1 = FUN_801ddbd0(obj,iVar2), iVar1 != 0)) {
      *(undefined1 *)(iVar2 + 0x57) = 3;
    }
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801dd4d4 FUN_801dd4d4

void FUN_801dd4d4(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x53) + -1;
  *(char *)(param_1 + 0x53) = cVar1;
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x53) = *(undefined1 *)(param_1 + 0x55);
    cVar1 = (&DAT_801e9b4c)[*(byte *)(param_1 + 0x52) >> 1];
    *(byte *)(param_1 + 0x52) = *(char *)(param_1 + 0x52) + 1U & 0xf;
    *(char *)(param_1 + 0x50) = *(char *)(param_1 + 0x50) + cVar1;
  }
  FUN_80105120(param_1,*(undefined2 *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x50));
  FUN_80104c34(param_1);
  return;
}


// ---- 801dd564 FUN_801dd564

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd564(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    FUN_801dd60c();
  }
  else {
    FUN_801dd838(obj);
  }
  FUN_801ddb0c(obj);
  if (obj->field_0x57 == '\x03') {
    iVar2 = *(int *)&obj->field_0x4c;
    if ((obj->field_0x56 == '\0') && (iVar1 = FUN_801ddbd0(obj,iVar2), iVar1 != 0)) {
      *(undefined1 *)(iVar2 + 0x57) = 3;
    }
    Obj_Free(obj);
  }
  else {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801dd60c FUN_801dd60c

void FUN_801dd60c(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x5c);
  iVar3 = FUN_801ddbd0(param_1,iVar7);
  if (iVar3 != 0) {
    *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(iVar7 + 0x4a);
    *(undefined1 *)(param_1 + 0x55) = *(undefined1 *)(iVar7 + 0x55);
    *(undefined1 *)(param_1 + 0x54) = *(undefined1 *)(iVar7 + 0x54);
  }
  cVar1 = *(char *)(param_1 + 0x53) + -1;
  *(char *)(param_1 + 0x53) = cVar1;
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x53) = *(undefined1 *)(param_1 + 0x55);
    iVar3 = FUN_801ddbd0(param_1,iVar7);
    if (iVar3 != 0) {
      cVar1 = *(char *)(iVar7 + 0x50);
      iVar3 = 0;
      if (DAT_801d2915 == '\x01') {
        iVar3 = (int)DAT_801d293a << 0x10;
      }
      iVar4 = FUN_801ddb7c(cVar1,10);
      iVar5 = FUN_801ddb7c(cVar1 + '@',10);
      uVar2 = FUN_80104db0((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),
                           (iVar4 - iVar3) + *(int *)(iVar7 + 0xc) >> 0x10,
                           *(int *)(iVar7 + 0x10) - iVar5 >> 0x10);
      *(undefined1 *)(param_1 + 0x50) = uVar2;
    }
  }
  FUN_80105120(param_1,*(undefined2 *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x50));
  FUN_80104c34(param_1);
  uVar2 = FUN_801ddc14(*(undefined1 *)(param_1 + 0x50));
  uVar6 = 2;
  if ((*(byte *)(param_1 + 7) & 0xf) == 5) {
    uVar6 = 1;
  }
  Anim_SetAtStep(param_1,uVar6,uVar2);
  cVar1 = *(char *)(param_1 + 0x57);
  if (cVar1 == '\x02') {
    iVar3 = *(int *)(param_1 + 0x4c);
    if ((*(char *)(param_1 + 0x56) != '\0') || (iVar7 = FUN_801ddbd0(param_1,iVar3), iVar7 == 0)) {
      iVar7 = *(int *)(param_1 + 0x5c);
      *(undefined1 *)(param_1 + 2) = 1;
      *(undefined1 *)(param_1 + 3) = 0;
      iVar3 = FUN_801ddbd0(param_1,iVar7);
      if (iVar3 == 0) {
        return;
      }
      *(undefined1 *)(iVar7 + 0x56) = 1;
      return;
    }
    *(undefined1 *)(iVar3 + 0x57) = 2;
    *(undefined1 *)(iVar3 + 0x58) = *(undefined1 *)(param_1 + 0x58);
    *(undefined1 *)(param_1 + 0x57) = 0;
    cVar1 = *(char *)(param_1 + 0x57);
  }
  if (cVar1 == '\x01') {
    iVar3 = *(int *)(param_1 + 0x4c);
    *(undefined1 *)(param_1 + 1) = 4;
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 0x53) = *(undefined1 *)(param_1 + 0x58);
    if ((*(char *)(param_1 + 0x56) == '\0') && (iVar7 = FUN_801ddbd0(param_1,iVar3), iVar7 != 0)) {
      *(undefined1 *)(iVar3 + 0x57) = 1;
      *(char *)(iVar3 + 0x58) = *(char *)(param_1 + 0x58) + '\x02';
    }
  }
  return;
}


// ---- 801dd838 FUN_801dd838

void FUN_801dd838(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 3) == '\0') {
    *(char *)(param_1 + 0x51) = *(char *)(param_1 + 0x58) << 5;
    *(undefined1 *)(param_1 + 3) = 1;
    FUN_80105120(param_1,0x300,*(undefined1 *)(param_1 + 0x51));
    *(undefined1 *)(param_1 + 0x5a) = 1;
    *(undefined1 *)(param_1 + 0x31) = 1;
  }
  else {
    uVar1 = FUN_801ddc14(*(undefined1 *)(param_1 + 0x50),0x300);
    uVar3 = 2;
    if ((*(byte *)(param_1 + 7) & 0xf) == 5) {
      uVar3 = 1;
    }
    Anim_SetAtStep(param_1,uVar3,uVar1);
    cVar2 = *(char *)(param_1 + 0x50) + '\x10';
    if (*(char *)(param_1 + 0x58) < '\0') {
      cVar2 = *(char *)(param_1 + 0x50) + -0x10;
    }
    *(char *)(param_1 + 0x50) = cVar2;
  }
  FUN_80104c34(param_1);
  return;
}


// ---- 801dd8f0 FUN_801dd8f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd8f0(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    FUN_801dd930();
  }
  else {
    FUN_801dda00();
  }
  return;
}


// ---- 801dd930 FUN_801dd930

void FUN_801dd930(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_80108e84();
  FUN_8012a5fc(param_1,3);
  if ((*(byte *)(param_1 + 7) & 0xf) < 5) {
    FUN_80108fd8(param_1,1);
  }
  if (*(char *)(param_1 + 0x56) == '\0') {
    if ((4 < (*(byte *)(param_1 + 7) & 0xf)) &&
       (iVar1 = FUN_801ddbd0(param_1,*(undefined4 *)(param_1 + 0x5c)), iVar1 != 0)) {
      *(undefined1 *)(*(int *)(param_1 + 0x5c) + 0x56) = 1;
    }
    iVar2 = *(int *)(param_1 + 0x4c);
    iVar1 = FUN_801ddbd0(param_1,iVar2);
    if (iVar1 != 0) {
      *(undefined1 *)(iVar2 + 0x57) = 1;
      *(undefined1 *)(iVar2 + 0x58) = 2;
    }
  }
  Obj_FreeDespawn(param_1);
  return;
}


// ---- 801dda00 FUN_801dda00

void FUN_801dda00(int param_1)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 3);
  if (bVar1 == 1) {
    cVar2 = *(char *)(param_1 + 0x53) + -1;
    *(char *)(param_1 + 0x53) = cVar2;
    if (cVar2 == '\0') {
      *(undefined1 *)(param_1 + 3) = 2;
      *(undefined4 *)(param_1 + 0x20) = 0x4000;
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      cVar2 = *(char *)(param_1 + 0x53) + -1;
      *(char *)(param_1 + 0x53) = cVar2;
      if (cVar2 != '\0') {
        return;
      }
      *(char *)(param_1 + 0x50) = *(char *)(param_1 + 0x50) + '@';
      *(undefined1 *)(param_1 + 3) = 1;
      FUN_80105120(param_1,0x300,*(undefined1 *)(param_1 + 0x50));
      *(undefined1 *)(param_1 + 0x5a) = 1;
      *(undefined1 *)(param_1 + 0x31) = 1;
      *(undefined1 *)(param_1 + 0x46) = 1;
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(undefined1 *)(param_1 + 0x53) = 0x1e;
      *(undefined1 *)(param_1 + 0x24) = *(undefined1 *)(param_1 + 0x5b);
      return;
    }
    if (bVar1 != 2) {
      return;
    }
  }
  *(byte *)(param_1 + 0x59) = *(byte *)(param_1 + 0x59) ^ 1;
  Anim_Step(param_1);
  FUN_80104ccc(param_1);
  return;
}


// ---- 801ddb0c FUN_801ddb0c

int FUN_801ddb0c(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x46) = 0;
  iVar1 = Enemy_CheckWeaponHits();
  *(undefined1 *)(param_1 + 0x46) = 1;
  if (iVar1 == 2) {
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x24) = *(undefined1 *)(param_1 + 0x5b);
  }
  if (iVar1 == 4) {
    *(undefined1 *)(param_1 + 1) = 4;
    *(undefined1 *)(param_1 + 2) = 0;
  }
  return iVar1;
}


// ---- 801ddb7c FUN_801ddb7c

int FUN_801ddb7c(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 & 0x40) == 0) {
    iVar1 = (param_1 & 0x3f) << 1;
  }
  else {
    iVar1 = (0x40 - (param_1 & 0x3f)) * 2;
  }
  uVar2 = (uint)*(ushort *)(&DAT_801395f0 + iVar1);
  if ((param_1 & 0x80) == 0) {
    uVar2 = -uVar2;
  }
  return uVar2 * ((param_2 << 0x10) >> 0xf);
}


// ---- 801ddbd0 FUN_801ddbd0

bool FUN_801ddbd0(int param_1,char *param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*param_2 != '\0') && (param_2[6] == '\x17')) {
    bVar1 = (*(byte *)(param_1 + 7) & 0xf0) == (param_2[7] & 0xf0U);
  }
  return bVar1;
}


// ---- 801ddc14 FUN_801ddc14

uint FUN_801ddc14(int param_1)

{
  return ((0xc0U - param_1 & 0xff) >> 4) + (uint)((0xc0U - param_1 & 8) != 0) & 0xf;
}


// ---- 801ddc38 FUN_801ddc38

void FUN_801ddc38(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x4c);
  uVar3 = 0;
  *(undefined1 *)(param_1 + 0x5c) = 0;
  do {
    if ((*(char *)(iVar2 + 0x56) != '\0') ||
       (iVar1 = FUN_801ddbd0(iVar2,*(undefined4 *)(param_1 + 0x4c)), iVar1 == 0)) break;
    uVar3 = uVar3 + 1;
    *(char *)(param_1 + 0x5c) = *(char *)(param_1 + 0x5c) + '\x01';
    iVar2 = *(int *)(iVar2 + 0x4c);
  } while (uVar3 < 8);
  *(ushort *)(param_1 + 0x4a) = (*(byte *)(param_1 + 0x5c) & 0xfe) * -0x10 + 0x1e0;
  *(undefined *)(param_1 + 0x54) = (&DAT_801e9b54)[*(byte *)(param_1 + 0x5c)];
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801ddce8 FUN_801ddce8

void FUN_801ddce8(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
  if (DAT_80170574 == (DAT_80170574 / 6) * 6) {
    iVar6 = 0;
    iVar3 = FUN_801ddc14(*(undefined1 *)(param_1 + 0x50));
    pcVar4 = &DAT_801e9b5c + iVar3 * 4;
    do {
      cVar1 = *pcVar4;
      pcVar5 = pcVar4 + 1;
      pcVar4 = pcVar4 + 2;
      iVar3 = FUN_801091a4((int)(((int)cVar1 + (uint)*(ushort *)(param_1 + 0xe)) * 0x10000) >> 0x10,
                           (int)(((int)*pcVar5 + (uint)*(ushort *)(param_1 + 0x12)) * 0x10000) >>
                           0x10,0x81);
      if (iVar3 != 0) {
        *(undefined1 *)(iVar3 + 0x27) = *(undefined1 *)(param_1 + 0x27);
        uVar2 = DAT_80159f99;
        *(undefined1 *)(iVar3 + 0x38) = 3;
        *(undefined1 *)(iVar3 + 0x39) = 1;
        *(undefined1 *)(iVar3 + 0x24) = uVar2;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 * 0x1000000 >> 0x18 < 2);
  }
  return;
}


