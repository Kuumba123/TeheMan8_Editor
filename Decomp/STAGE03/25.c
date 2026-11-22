// ID 25, STAGE03.BIN, handler 0x801DFCE0. Ghidra output with the object struct applied; not matching C.
// ---- 801dfce0 FUN_801dfce0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfce0(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e9c98)[obj->state])();
  if ((obj->field_0x51 != '\0') && (obj->active != 0)) {
    Obj_CullAndQueueDraw(obj);
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801dfd68 FUN_801dfd68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfd68(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  
  Enemy_InitFromTable();
  obj->flip = 0;
  obj->field_0x51 = 1;
  switch(obj->var) {
  case 0:
    obj->state = 1;
    DAT_801b29a1 = 0;
    obj->draw_list = 7;
    obj->hitbox = &DAT_801e9c7c;
    obj->gravity = 0x200;
    obj->field_0x52 = 4;
    obj->field_0x53 = 0;
    obj->field_0x55 = 0x96;
    obj->field_0x50 = 0x96;
    puVar3 = (undefined1 *)FUN_801055e4(obj);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 0x25;
      puVar3[7] = 1;
      *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
      uVar4 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar3 + 0x4c) = obj;
      *(undefined4 *)(puVar3 + 0x10) = uVar4;
    }
    uVar5 = 0;
    break;
  case 1:
    uVar5 = 1;
    obj->state = 2;
    obj->draw_list = 6;
    obj->hp = 0xc;
    obj->invuln = 1;
    obj->field_0x52 = 0;
    break;
  case 2:
    FUN_800fd100(0x91);
  case 3:
    obj->state = 3;
    obj->draw_list = 5;
    obj->invuln = 1;
    obj->contact_dmg = 0x10;
    uVar5 = obj->var + 1 & 0xff;
    obj->hitbox = &UNK_801e9c80 + (obj->var - 2) * 4;
    break;
  case 4:
    obj->state = 4;
    obj->draw_list = 5;
    obj->invuln = 1;
    obj->contact_dmg = 3;
    obj->hitbox = &DAT_801e9c88;
    obj->field_0x57 = 0xc0;
    uVar5 = FUN_801050e4(obj,&g_player);
    cVar1 = (char)(uVar5 & 0xfe);
    cVar2 = cVar1 + -8;
    if (0x7f < (uVar5 & 0xfe) - 0x40) {
      cVar2 = cVar1 + '\b';
    }
    obj->field_0x58 = cVar2;
                    /* Possible PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x59 = 0x78;
    FUN_80105120(obj,0x380,0xc0);
    uVar5 = 0x1d;
    break;
  default:
    goto switchD_801dfdac_default;
  }
  Anim_Set(obj,uVar5);
switchD_801dfdac_default:
  return;
}


// ---- 801dff60 FUN_801dff60

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dff60(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801e9cb0)[obj->sub2])();
  Anim_Step(obj);
  obj->field_0x54 = 0;
  if (obj->field_0x53 == '\0') {
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (obj->field_0x52 == '\0') {
      if (iVar2 == 4) {
        obj->state = 5;
        obj->sub2 = 0;
        obj->sub3 = 0;
      }
    }
    else if (iVar2 == 4) {
      obj->hp = 0xc;
      obj->field_0x53 = 0x3d;
      obj->field_0x54 = 1;
      cVar1 = obj->field_0x52 + -1;
      obj->field_0x52 = cVar1;
      if (cVar1 == '\0') {
        obj->hitbox = &DAT_801e9c78;
      }
      obj->field_0x55 = (&DAT_801e9c8c)[(byte)obj->field_0x52];
    }
    if (iVar2 == 2) {
      obj->field_0x53 = 0x15;
    }
  }
  else {
    obj->field_0x53 = obj->field_0x53 + -1;
  }
  if ((obj->field_0x53 & 1) == 0) {
    obj->clut = DAT_80159fab;
  }
  else {
    obj->clut = 0;
  }
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801e00ac FUN_801e00ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e00ac(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x52 == '\0') {
    if (0x7288 < obj->speed_y_up + 0x3944U) {
      obj->gravity = -obj->gravity;
    }
    FUN_80104ccc(obj);
  }
  if ((0xebf < DAT_801d2918._2_2_) &&
     ((cVar1 = obj->field_0x50 + -1, obj->field_0x50 = cVar1, cVar1 == '\0' ||
      (obj->field_0x54 != '\0')))) {
    obj->sub2 = 1;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e0160 FUN_801e0160

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0160(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9cb8)[obj->sub3])();
  return;
}


// ---- 801e019c FUN_801e019c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e019c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  if (obj->field_0x52 == '\0') {
    if (0x7288 < obj->speed_y_up + 0x3944U) {
      obj->gravity = -obj->gravity;
    }
    FUN_80104ccc(obj);
  }
  if (obj->field_0x4 == '\0') {
    iVar2 = FUN_801e082c(obj);
    if (iVar2 != 0) {
      obj->field_0x4 = 1;
      obj->field_0x5f = 0;
      obj->field_0x50 = 0x3c;
    }
  }
  else {
    if (obj->field_0x50 == '\x06') {
      Anim_Set(obj,0x1b);
    }
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      uVar3 = Rand();
      if (((uVar3 & 1) == 0) && (obj->field_0x52 != '\x04')) {
        obj->sub3 = 2;
        Anim_Set(obj,0x1c);
        obj->field_0x56 = 3;
        obj->field_0x50 = 1;
      }
      else {
        obj->sub3 = 1;
      }
      obj->field_0x4 = 0;
      obj->field_0x5f = 2;
    }
  }
  return;
}


// ---- 801e02c4 FUN_801e02c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e02c4(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x4 = 1;
    iVar2 = FUN_801e089c();
    if (iVar2 == 0) {
      obj->field_0x50 = 1;
    }
    else {
      obj->field_0x50 = 0x28;
      Anim_Set(obj,0x1c);
    }
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 0;
    obj->field_0x50 = obj->field_0x55;
    Anim_Set(obj,0);
  }
  return;
}


// ---- 801e0358 FUN_801e0358

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0358(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_801e0950();
    obj->field_0x50 = 8;
    cVar1 = obj->field_0x56 + -1;
    obj->field_0x56 = cVar1;
    if (cVar1 == '\0') {
      obj->sub2 = 0;
      obj->field_0x50 = obj->field_0x55;
      Anim_Set(obj,0);
    }
  }
  return;
}


// ---- 801e03d4 FUN_801e03d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e03d4(MM8Obj *obj)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)&obj->field_0x4c;
  if (obj->sub2 == 0) {
    if ((*pcVar4 == '\0') || (pcVar4[6] != '%')) {
      Obj_Free(obj);
    }
    else {
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
      obj->clut = pcVar4[0x24];
      uVar2 = *(undefined4 *)(pcVar4 + 0xc);
      obj->x_frac = (short)uVar2;
      obj->x = (short)((uint)uVar2 >> 0x10);
      uVar2 = *(undefined4 *)(pcVar4 + 0x10);
      obj->y_frac = (short)uVar2;
      obj->y = (short)((uint)uVar2 >> 0x10);
      if (pcVar4[0x54] != '\0') {
        iVar3 = (uint)(byte)obj->field_0x52 * 2;
        FUN_80108ed8(obj,(int)(char)(&DAT_801e9c90)[iVar3],(int)(char)(&DAT_801e9c91)[iVar3]);
        FUN_8012ae08(obj,(byte)obj->field_0x52 + 0x12);
        bVar1 = obj->field_0x52 + 1;
        obj->field_0x52 = bVar1;
        if (3 < bVar1) {
          obj->sub2 = 1;
          bVar1 = DAT_80159fab;
          obj->draw_list = 7;
          obj->invuln = 1;
          obj->clut = bVar1;
        }
        Anim_SetAtStep(obj,1,obj->field_0x52);
      }
    }
  }
  return;
}


// ---- 801e04f0 FUN_801e04f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e04f0(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    Obj_Free(obj);
  }
  else if (obj->anim_extra == 0) {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801e0550 FUN_801e0550

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0550(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  if (obj->field_0x59 != '\0') {
    bVar1 = obj->field_0x57;
    if ((uint)(byte)obj->field_0x58 != (uint)bVar1) {
      cVar2 = '\x02';
      if ((int)((uint)(byte)obj->field_0x58 - (uint)bVar1) < 1) {
        cVar2 = -2;
      }
      obj->field_0x57 = bVar1 + cVar2;
      FUN_80105120(obj,0x380,obj->field_0x57);
    }
    obj->field_0x59 = obj->field_0x59 + -1;
  }
  FUN_80104c34(obj);
  Enemy_ContactDamage(obj);
  Anim_Step(obj);
  return;
}


// ---- 801e05e4 FUN_801e05e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e05e4(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    FUN_801e0624();
  }
  else {
    FUN_801e079c();
  }
  return;
}


// ---- 801e0624 FUN_801e0624

void FUN_801e0624(int param_1)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  
  if (*(char *)(param_1 + 3) == '\0') {
    *(undefined1 *)(param_1 + 3) = 1;
    *(undefined1 *)(param_1 + 0x50) = 0xf0;
    DAT_801d2936 = 300;
    *(undefined1 *)(param_1 + 0x5f) = 2;
    *(undefined1 *)(param_1 + 0x52) = 0;
    Anim_Set(param_1,8);
    FUN_801e09c4(param_1,3,8);
  }
  bVar1 = *(byte *)(param_1 + 0x50);
  if ((bVar1 & 2) == 0) {
    sVar2 = 1;
    if ((bVar1 & 1) == 0) {
      sVar2 = -1;
    }
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + sVar2;
  }
  else {
    sVar2 = 1;
    if ((bVar1 & 1) == 0) {
      sVar2 = -1;
    }
    *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + sVar2;
  }
  if (((*(byte *)(param_1 + 0x50) & 3) == 0) &&
     (FUN_801091a4((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),1),
     *(byte *)(param_1 + 0x50) < 0xb4)) {
    FUN_801e09c4(param_1,0,1);
    FUN_801e09c4(param_1,1,1);
    if ((*(byte *)(param_1 + 0x50) & 7) == 0) {
      FUN_8010544c(param_1,9);
    }
  }
  if ((*(byte *)(param_1 + 0x50) & 0xf) == 0) {
    FUN_801e09c4(param_1,2,1);
  }
  cVar3 = *(char *)(param_1 + 0x50) + -1;
  *(char *)(param_1 + 0x50) = cVar3;
  if (cVar3 == '\0') {
    *(undefined1 *)(param_1 + 2) = 1;
  }
  *(byte *)(param_1 + 0x51) = *(byte *)(param_1 + 0x51) ^ 1;
  Anim_Step();
  return;
}


// ---- 801e079c FUN_801e079c

void FUN_801e079c(undefined4 param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar3 = &DAT_801e9c90;
  iVar4 = 0;
  do {
    cVar2 = *pcVar3;
    pcVar1 = pcVar3 + 1;
    pcVar3 = pcVar3 + 2;
    FUN_80108ed8(param_1,(int)cVar2,(int)*pcVar1);
    FUN_8012ae08(param_1,0x16);
                    /* Possible PsyQ macro: setPolyG3() */
    iVar4 = iVar4 + 1;
  } while (iVar4 * 0x1000000 >> 0x18 < 4);
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  DAT_801b29a1 = 1;
  Obj_Free(param_1);
  return;
}


// ---- 801e082c FUN_801e082c

int FUN_801e082c(int param_1)

{
  int iVar1;
  
                    /* Probable PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  iVar1 = FUN_8012c108(param_1,param_1 + 0x5f,0,0,0,2);
  if (iVar1 != 0) {
    FUN_8010544c(param_1,0x90);
                    /* Probable PsyQ macro: setTile() */
    *(undefined1 *)(iVar1 + 7) = 0x60;
    *(undefined1 *)(iVar1 + 0x26) = 5;
  }
  return iVar1;
}


// ---- 801e089c FUN_801e089c

undefined4 FUN_801e089c(undefined1 *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = 0;
  puVar3 = param_1;
  do {
    puVar1 = (undefined1 *)FUN_801055e4(puVar3);
    if (puVar1 == (undefined1 *)0x0) {
      if (uVar2 == 0) {
        return 1;
      }
      Obj_Free(puVar3);
    }
    else {
      puVar1[6] = 0x25;
      *puVar1 = 1;
      puVar1[7] = (char)uVar2 + '\x02';
      *(short *)(puVar1 + 0xe) = *(short *)(param_1 + 0xe) + (short)uVar2 * -0x100;
      *(undefined2 *)(puVar1 + 0x12) = *(undefined2 *)(param_1 + 0x12);
    }
    uVar2 = uVar2 + 1;
    puVar3 = puVar1;
  } while (uVar2 < 2);
  return 1;
}


// ---- 801e0950 FUN_801e0950

undefined1 * FUN_801e0950(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x25;
    puVar1[7] = 4;
    *(short *)(puVar1 + 0xe) = *(short *)(param_1 + 0xe) + -0x1d;
    *(undefined2 *)(puVar1 + 0x12) = *(undefined2 *)(param_1 + 0x12);
    FUN_8010544c(param_1,0xb);
  }
  return puVar1;
}


// ---- 801e09c4 FUN_801e09c4

void FUN_801e09c4(int param_1,undefined1 param_2,uint param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      puVar1 = (undefined1 *)Obj_AllocType3();
      uVar2 = uVar2 + 1;
      if (puVar1 != (undefined1 *)0x0) {
        *puVar1 = 1;
        puVar1[6] = 0x1d;
        puVar1[7] = param_2;
        *(undefined2 *)(puVar1 + 0xe) = *(undefined2 *)(param_1 + 0xe);
        *(undefined2 *)(puVar1 + 0x12) = *(undefined2 *)(param_1 + 0x12);
      }
    } while (uVar2 < param_3);
  }
  return;
}


