// ID 11, STAGE0B.BIN, handler 0x801DB04C. Ghidra output with the object struct applied; not matching C.
// ---- 801db04c FUN_801db04c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db04c(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e8394)[obj->state])();
  if ((((obj->var & 0x80) != 0) && (DAT_801d2915 == '\x01')) && (DAT_801d293a != 1)) {
    obj->x = obj->x + DAT_801d293a;
  }
  Obj_CullAndQueueDraw(obj);
  iVar1 = Obj_InActiveArea(obj);
  if ((iVar1 == 0) && (obj->field_0x53 == '\0')) {
    if ((obj->var & 0x80) == 0) {
      Obj_FreeDespawn(obj);
    }
    else {
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801db134 FUN_801db134

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db134(MM8Obj *obj)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = obj->speed_x;
  Enemy_InitFromTable();
  obj->field_0x43 = 1;
  obj->hitbox = &DAT_801e8374;
  obj->box2 = (byte *)0x0;
  if ((obj->var & 0x40) == 0) {
    obj->draw_list = 7;
  }
  obj->field_0x53 = 0;
  if ((obj->var & 0x80) != 0) {
    obj->contact_dmg = 6;
  }
  switch(obj->var & 0xf) {
  case 4:
  case 5:
    uVar3 = 0;
    obj->state = 3;
    obj->speed_y_up = 0x30000;
    obj->sub2 = 0;
    obj->flip = 0;
    obj->speed_x = 0;
    obj->field_0x51 = 0;
    obj->field_0x50 = 0x1e;
    *(short *)&obj->field_0x4a = obj->y;
    break;
  case 6:
  case 7:
    uVar3 = 1;
    obj->state = 3;
    obj->sub2 = 1;
    obj->speed_x = -0x20000;
    obj->flip = 0;
    obj->field_0x51 = 0;
    obj->field_0x50 = 0x30;
    obj->speed_y_up = (uint)((obj->var & 0xf) != 6) << 0xf;
    break;
  case 8:
    bVar2 = 2;
    obj->state = 2;
    obj->draw_list = 5;
    obj->hp = 2;
    if ((obj->var & 0x80) != 0) {
      bVar2 = 4;
    }
    uVar1 = 0xc0;
    obj->hitbox = &DAT_801e8378;
    obj->contact_dmg = bVar2;
    obj->box2 = &DAT_801e837c;
    obj->speed_x = iVar4;
    if ((obj->flip & 0x40) != 0) {
      uVar1 = 0x40;
    }
    obj->field_0x51 = uVar1;
    uVar3 = 2;
    break;
  default:
    FUN_8010910c(obj);
    FUN_801db37c(obj);
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x53 = 0x78;
    if ((obj->var & 0x10) == 0) {
      uVar5 = 0;
      obj->field_0x51 = 0;
      if ((obj->var & 0xf) != 0xfffffffd) {
        do {
          uVar5 = uVar5 + 1;
          FUN_801dbbd8(obj,uVar5 & 0xff,(int)(uVar5 * 0x180000) >> 0x10);
        } while ((int)uVar5 < (int)((obj->var & 0xf) + 3));
      }
    }
    iVar4 = FUN_801dbb1c(obj);
    uVar3 = 0;
    *(int *)&obj->field_0x54 = iVar4;
    *(int *)&obj->y_frac = *(int *)&obj->y_frac + iVar4;
  }
  Anim_Set(obj,uVar3);
  return;
}


// ---- 801db37c FUN_801db37c

void FUN_801db37c(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = -0x10000;
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(param_1 + 0x12);
  if ((*(byte *)(param_1 + 7) & 0x80) != 0) {
    iVar3 = -0x20000;
  }
  if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
    iVar3 = -iVar3;
  }
  *(int *)(param_1 + 0x14) = iVar3;
  *(undefined4 *)(param_1 + 0x18) = 0;
  if ((*(byte *)(param_1 + 7) & 0x80) == 0) {
    uVar1 = 0x78;
  }
  else {
    uVar2 = Rand();
    uVar1 = (&DAT_801e8384)[uVar2 & 0xf];
  }
  *(undefined1 *)(param_1 + 0x50) = uVar1;
  return;
}


// ---- 801db41c FUN_801db41c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db41c(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e83a8)[obj->sub2])();
  Anim_Step(obj);
  if (obj->field_0x53 != '\0') {
    obj->field_0x53 = obj->field_0x53 + -1;
  }
  iVar1 = Enemy_CheckWeaponHits(obj);
  if (iVar1 == 4) {
    obj->state = 4;
    obj->sub2 = 0;
  }
  else {
    Enemy_ContactDamage(obj);
  }
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801db4b4 FUN_801db4b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db4b4(MM8Obj *obj)

{
  char cVar1;
  
                    /* Possible PsyQ macro: setPolyG3() + setSemiTrans(polyG3, 1) */
  if ((((obj->var & 0x80) == 0) || (obj->field_0x50 != -1)) &&
     (cVar1 = obj->field_0x50 + -1, obj->field_0x50 = cVar1, cVar1 == '\0')) {
    obj->sub2 = 1;
    Anim_Set(obj,1);
  }
  FUN_801dbb98(obj);
  FUN_80104c34(obj);
  obj->field_0x51 = obj->field_0x51 + '\x03';
  return;
}


// ---- 801db548 FUN_801db548

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db548(MM8Obj *obj)

{
  if (obj->anim_extra != 0) {
    switchD_801dba60::default();
    obj->anim_extra = 0;
  }
  if ((short)obj->frame < 0) {
    if ((obj->var & 0x80) == 0) {
      obj->sub2 = 2;
      obj->sub3 = 0;
    }
    Anim_Set(obj,0);
  }
  FUN_801dbb98(obj);
  FUN_80104c34(obj);
  obj->field_0x51 = obj->field_0x51 + '\x03';
  return;
}


// ---- 801db5e0 FUN_801db5e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db5e0(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    obj->speed_y_up = -0x1000;
    obj->gravity = -0x1000;
    obj->field_0x53 = 0;
    obj->sub3 = obj->sub3 + 1;
  }
  FUN_80104ccc();
  return;
}


// ---- 801db628 FUN_801db628

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db628(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801e83b4)[obj->sub2])();
  FUN_80106214(obj);
  bVar1 = obj->field_0x33;
  iVar2 = Enemy_CheckWeaponHits(obj);
  if (((iVar2 == 4) || (iVar2 = Enemy_ContactDamage(obj), iVar2 != 0)) || ((bVar1 & 0xf0) != 0)) {
    obj->state = 4;
    obj->sub2 = 1;
  }
  return;
}


// ---- 801db6c4 FUN_801db6c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db6c4(MM8Obj *obj)

{
  undefined1 uVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->field_0x54;
  if ((short)obj->frame < 0) {
    obj->sub2 = 1;
    obj->sub3 = 0;
    uVar1 = FUN_801050e4(obj,&g_player);
    obj->field_0x58 = uVar1;
    FUN_8010544c(obj,0x8f);
  }
  if (((*pcVar2 != '\0') && (pcVar2[6] == '\x11')) && ((pcVar2[7] & 0xfU) != 8)) {
    obj->y = *(short *)(pcVar2 + 0x12) + -5;
  }
  FUN_80104c34(obj);
  Anim_Step(obj);
  return;
}


// ---- 801db778 FUN_801db778

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db778(MM8Obj *obj)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (obj->sub3 == 0) {
    uVar1 = (uint)(byte)obj->field_0x58 - (uint)(byte)obj->field_0x51;
    if ((int)(uVar1 * 0x1000000) < 0) {
      iVar2 = (byte)obj->field_0x51 - 8;
    }
    else {
      iVar2 = (byte)obj->field_0x51 + 8;
    }
    obj->field_0x51 = (char)iVar2;
    if (((uVar1 & 0x80) != ((uint)(byte)obj->field_0x58 - iVar2 & 0x80)) ||
       (obj->field_0x58 == obj->field_0x51)) {
      obj->sub3 = obj->sub3 + 1;
      obj->field_0x51 = obj->field_0x58;
    }
  }
  uVar3 = 0x380;
  if ((obj->var & 0x80) == 0) {
    uVar3 = 0x200;
  }
  FUN_80105120(obj,uVar3,obj->field_0x51);
  FUN_80104c34(obj);
  obj->flip = 0;
  Anim_SetAtStep(obj,3,((byte)obj->field_0x51 + 0x40 & 0xff) >> 4);
  return;
}


// ---- 801db864 FUN_801db864

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db864(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e83bc)[obj->sub2])();
  iVar1 = Enemy_CheckWeaponHits(obj);
  if (iVar1 == 4) {
    obj->state = 4;
    obj->sub2 = 0;
  }
  else {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801db8d4 FUN_801db8d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db8d4(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80104c34();
  iVar1 = (uint)*(ushort *)&obj->field_0x4a - (uint)(ushort)obj->y;
  if ((obj->var & 0xf) == 4) {
    if (iVar1 * 0x10000 >> 0x10 < 0x90) goto LAB_801db9bc;
  }
  else {
    if (iVar1 * 0x10000 >> 0x10 < 0x40) goto LAB_801db9bc;
    if (obj->sub3 == 0) {
      if (obj->y <= DAT_8015e24c._2_2_) {
        obj->sub2 = 2;
        return;
      }
      obj->sub3 = obj->sub3 + 1;
    }
                    /* Probable PsyQ macro: setTile16() */
                    /* Possible PsyQ macro: setTile8() */
    if (((short)iVar1 < 0xa0) && (5 < (ushort)((DAT_8015e24c._2_2_ - obj->y) + 3U)))
    goto LAB_801db9bc;
  }
  obj->sub2 = 2;
LAB_801db9bc:
  Anim_Step(obj);
                    /* Possible PsyQ macro: setTile8() */
  return;
}


// ---- 801db9d8 FUN_801db9d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db9d8(MM8Obj *obj)

{
  char cVar1;
  
  FUN_80104c34();
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 2;
    obj->field_0x50 = 1;
    Anim_Set(obj,0);
  }
                    /* Probable PsyQ macro: setTile16() */
  return;
}


// ---- 801dba34 FUN_801dba34

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba34(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_801db37c();
    iVar2 = FUN_801dbb1c(obj);
    *(int *)&obj->field_0x54 = iVar2;
    *(int *)&obj->y_frac = *(int *)&obj->y_frac + iVar2;
  }
  Anim_Step(obj);
  return;
}


// ---- 801dba9c FUN_801dba9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba9c(MM8Obj *obj)

{
  FUN_80108e84();
  if (obj->sub2 == 0) {
    FUN_8012a5fc(obj,0);
    FUN_801dbd84(obj);
    FUN_80108fd8(obj,0);
  }
  if ((obj->var & 0x80) == 0) {
    Obj_FreeDespawn(obj);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801dbb1c FUN_801dbb1c

int FUN_801dbb1c(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
                    /* Possible PsyQ macro: setPolyGT3() */
  bVar1 = *(byte *)(param_1 + 0x51);
                    /* Possible PsyQ macro: setPolyGT4() */
  if ((bVar1 & 0x40) == 0) {
    iVar2 = (bVar1 & 0x3f) << 1;
  }
  else {
    iVar2 = (0x40 - (bVar1 & 0x3f)) * 2;
  }
  uVar3 = (uint)*(ushort *)(&DAT_801395f0 + iVar2);
  if ((bVar1 & 0x80) != 0) {
    uVar3 = -uVar3;
  }
  if ((*(byte *)(param_1 + 7) & 0x80) == 0) {
    iVar2 = uVar3 * 0x30;
  }
  else {
    iVar2 = uVar3 * 0x18;
  }
  return iVar2;
}


// ---- 801dbb98 FUN_801dbb98

void FUN_801dbb98(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_801dbb1c();
  iVar2 = *(int *)(param_1 + 0x54);
  *(int *)(param_1 + 0x54) = iVar1;
  *(int *)(param_1 + 0x10) = (iVar1 - iVar2) + *(int *)(param_1 + 0x10);
                    /* Possible PsyQ macro: setPolyGT3() */
  return;
}


// ---- 801dbbd8 FUN_801dbbd8

void FUN_801dbbd8(int param_1,char param_2,short param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocMain();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x11;
    puVar2[7] = *(byte *)(param_1 + 7) | 0x10;
    if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
      param_3 = -param_3;
    }
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + param_3;
    *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    puVar2[0x51] = param_2 * -0x20;
    puVar2[0x25] = uVar1;
  }
  return;
}


// ---- 801dbc8c default

void switchD_801dba60::default(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  short sVar5;
  
  bVar1 = *(byte *)(param_1 + 0x25);
  puVar2 = (undefined1 *)Obj_AllocMain();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x11;
    puVar2[7] = *(byte *)(param_1 + 7) & 0x80 | 8;
    if ((bVar1 & 0x40) == 0) {
      sVar5 = -0x10;
    }
    else {
      sVar5 = 0x10;
    }
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + sVar5;
    *(short *)(puVar2 + 0x12) = *(short *)(param_1 + 0x12) + -5;
    puVar2[0x25] = *(undefined1 *)(param_1 + 0x25);
    uVar3 = *(undefined4 *)(param_1 + 0x14);
                    /* Possible PsyQ macro: setLineF2() */
    *(int *)(puVar2 + 0x54) = param_1;
    *(undefined4 *)(puVar2 + 0x14) = uVar3;
    if ((bVar1 & 0x40) == 0) {
      sVar5 = *(short *)(param_1 + 0xe) + -0xe;
    }
    else {
      sVar5 = *(short *)(param_1 + 0xe) + 0xe;
    }
    iVar4 = FUN_801091a4((int)sVar5,(int)((*(ushort *)(param_1 + 0x12) - 5) * 0x10000) >> 0x10,0);
    if (iVar4 != 0) {
      *(undefined1 *)(iVar4 + 0x26) = 4;
      *(undefined1 *)(iVar4 + 0x39) = 1;
    }
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801dbd84 FUN_801dbd84

void FUN_801dbd84(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    puVar2 = (undefined1 *)Obj_AllocType3();
    uVar3 = uVar3 + 1;
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x12;
      bVar1 = Rand();
                    /* Possible PsyQ macro: setPolyF4() */
      puVar2[7] = bVar1 & 1;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    }
  } while (uVar3 < 2);
  return;
}


