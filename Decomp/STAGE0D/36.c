// ID 36, STAGE0D.BIN, handler 0x801E2370. Ghidra output with the object struct applied; not matching C.
// ---- 801e2370 FUN_801e2370

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2370(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8670)[obj->state])();
  return;
}


// ---- 801e23ac FUN_801e23ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e23ac(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  obj->field_0x43 = 1;
  iVar1 = (uint)obj->var * 8;
  obj->draw_list = (&DAT_801f857d)[iVar1];
  Anim_Set(obj,(&DAT_801f857c)[iVar1]);
  obj->contact_dmg = (&DAT_801f8580)[iVar1];
  obj->dmg_table = (&DAT_801f857f)[iVar1];
  obj->hitbox = &UNK_801f85ec + (uint)(byte)(&DAT_801f8581)[iVar1] * 4;
  obj->box2 = &UNK_801f8610 + (uint)(byte)(&DAT_801f8582)[iVar1] * 5;
  (*(code *)(&PTR_FUN_801f8684)[(byte)(&DAT_801f857e)[iVar1]])(obj);
  obj->state = (&DAT_801f857e)[iVar1];
  return;
}


// ---- 801e2490 FUN_801e2490

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2490(MM8Obj *obj)

{
  FUN_80105120(obj,(int)((uint)(byte)(&DAT_801f8583)[(uint)obj->var * 8] << 0x18) >> 0x14,
               obj->field_0x56);
  obj->field_0x50 = 0x30;
  obj->field_0x54 = 1;
  obj->field_0x51 = 0;
  obj->field_0x55 = 0;
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->field_0x57 = 0x3c;
  return;
}


// ---- 801e24fc FUN_801e24fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e24fc(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = Rand();
  uVar2 = (uint)(byte)(&DAT_801f8650)[uVar2 & 0xf];
  Anim_Set(obj,uVar2 + 7 & 0xff);
  bVar1 = Rand();
  obj->flip = (bVar1 & 1) << 6;
  obj->hitbox = &UNK_801f85f4 + uVar2 * 4;
                    /* Possible PsyQ macro: setLineF2() */
  obj->speed_y_up = 0x4000;
  obj->gravity = 0x4000;
  obj->box2 = &UNK_801f8615 + uVar2 * 5;
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->speed_x = 0;
  obj->field_0x52 = 0;
  obj->field_0x43 = 1;
  return;
}


// ---- 801e25a4 FUN_801e25a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e25a4(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = (&DAT_801f8583)[(uint)obj->var * 8];
  if ((obj->flip & 0x40) != 0) {
    cVar1 = -cVar1;
  }
  FUN_80105120(obj,0x400,cVar1 + 0x80);
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->gravity = 0x4000;
  obj->hp = 2;
  return;
}


// ---- 801e266c FUN_801e266c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e266c(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setTile8() */
  (*(code *)(&PTR_FUN_801f869c)[obj->sub2])();
  return;
}


// ---- 801e26a8 FUN_801e26a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e26a8(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  FUN_80104c34();
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  FUN_80106214(obj);
  if (obj->field_0x33 == '\0') {
    iVar1 = Enemy_CheckWeaponHits(obj);
    if ((iVar1 == 0) || (DAT_80158f5c != '\v')) {
      iVar1 = Enemy_ContactDamage(obj);
      if (iVar1 != 0) {
        obj->sub2 = 1;
        obj->sub3 = 0;
      }
      if ((byte)obj->field_0x57 != 0) {
        if (((uint)(byte)obj->field_0x57 % 3 == 0) &&
           (iVar1 = FUN_801091a4((int)obj->x,(int)obj->y,1), iVar1 != 0)) {
          *(byte *)(iVar1 + 0x26) = obj->draw_list - 1;
        }
        obj->field_0x57 = obj->field_0x57 + -1;
      }
    }
    else {
      iVar1._0_2_ = obj->x_frac;
      iVar1._2_2_ = obj->x;
      iVar2 = -0x60000;
      if (*(int *)(DAT_8016d404 + 0xc) <= iVar1) {
        iVar2 = 0x60000;
      }
      obj->speed_x = iVar2;
      obj->sub2 = 3;
      obj->speed_y_up = 0;
      obj->sub3 = 0;
      obj->field_0x55 = 1;
      obj->flip = obj->flip ^ 0x40;
    }
  }
  else {
    if ((obj->field_0x33 & 0x30) != 0) {
      obj->field_0x51 = 1;
    }
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801e2824 FUN_801e2824

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2824(MM8Obj *obj)

{
  word wVar1;
  char cVar2;
  undefined1 *puVar3;
  
  if (obj->sub3 == 0) {
    obj->bank = 9;
    obj->clut = obj->clut + 1;
    wVar1 = DAT_8017035a;
    obj->hitbox = &DAT_801f85f0;
    obj->vram_base = wVar1;
    Anim_Set(obj,0x28);
    FUN_8010544c(obj,0x21);
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x50 = 0x3c;
    if ((obj->field_0x51 != '\0') && (obj->field_0x53 = 1, obj->var != 0xd)) {
      *(undefined1 *)(*(int *)&obj->field_0x4c + 0x5e) = 2;
    }
    puVar3 = (undefined1 *)Obj_AllocMain();
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 0x36;
      puVar3[7] = 5;
      *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)&obj->y_frac;
    }
    obj->sub3 = 1;
  }
  Anim_Step(obj);
  if ((_DAT_80170574 & 3) == 0) {
    if (obj->field_0x55 == '\0') {
      Enemy_ContactDamage(obj);
    }
    else {
      FUN_801e2afc(obj);
    }
  }
  if (((_DAT_80170574 & 1) != 0) &&
     (puVar3 = (undefined1 *)Obj_AllocType3(), puVar3 != (undefined1 *)0x0)) {
    *puVar3 = 1;
    puVar3[6] = 0x28;
    puVar3[7] = 0;
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
    *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)&obj->y_frac;
  }
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
    Anim_Set(obj,0x29);
    obj->sub2 = 2;
  }
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e29e0 FUN_801e29e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e29e0(MM8Obj *obj)

{
  char *pcVar1;
  
                    /* Possible PsyQ macro: setLineF2() */
  Anim_Step();
  if ((short)obj->frame < 0) {
    pcVar1 = *(char **)&obj->field_0x4c;
    if (((*pcVar1 != '\0') && (pcVar1[6] == '5')) && (obj->var == 0)) {
      pcVar1[0x5e] = '\x01';
    }
    Obj_Free(obj);
  }
  else if ((_DAT_80170574 & 1) != 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e2a84 FUN_801e2a84

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2a84(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80104c34();
  Anim_Step(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->field_0x51 = 1;
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  iVar1 = FUN_801e2afc(obj);
  if (0 < iVar1) {
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e2afc FUN_801e2afc

undefined4 FUN_801e2afc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(param_1 + 0x4c);
  if ((*pcVar3 == '\0') || (pcVar3[6] != '5')) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = Obj_HitboxOverlap(pcVar3);
    uVar1 = 0;
    if (iVar2 != 0) {
      if (pcVar3[0x51] == '\0') {
        pcVar3[0x5f] = '\x01';
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


// ---- 801e2ca0 FUN_801e2ca0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2ca0(MM8Obj *obj)

{
  Anim_Step();
  if (obj->sub2 == 0) {
    FUN_801e2cf0(obj);
  }
  else {
    FUN_801e2e68(obj);
  }
  return;
}


// ---- 801e2cf0 FUN_801e2cf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801e2cf0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x18) < -0x5c000) {
    *(undefined4 *)(param_1 + 0x18) = 0xfffa0000;
    FUN_80104c34();
  }
  else {
    FUN_80104ccc(param_1);
  }
  Obj_CullAndQueueDraw(param_1);
  if ((DAT_801d292a + 0x80 < (int)*(short *)(param_1 + 0x12)) &&
     (FUN_80106214(param_1), (*(byte *)(param_1 + 0x33) & 0x80) != 0)) {
    *(int *)(param_1 + 0x18) = -(*(int *)(param_1 + 0x18) >> 1);
    uVar1 = Rand();
    *(uint *)(param_1 + 0x14) = uVar1 & 0x1ffff;
    uVar1 = Rand();
    if ((uVar1 & 1) != 0) {
      *(int *)(param_1 + 0x14) = -*(int *)(param_1 + 0x14);
    }
    FUN_8010544c(param_1,0xdd);
    *(undefined1 *)(param_1 + 2) = 1;
  }
  else {
    Enemy_CheckWeaponHits(param_1);
                    /* Possible PsyQ macro: setLineF2() */
    Enemy_ContactDamage(param_1);
    if ((_DAT_80170574 & 3) == 0) {
      iVar2 = -0x15;
      if (*(char *)(param_1 + 0x30) == '\a') {
        iVar2 = 0xd;
        iVar3 = -0x17;
      }
      else {
        iVar3 = -5;
      }
      if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
        iVar2 = -iVar2;
      }
      FUN_801091a4((int)((iVar2 + (uint)*(ushort *)(param_1 + 0xe)) * 0x10000) >> 0x10,
                   (int)((iVar3 + (uint)*(ushort *)(param_1 + 0x12)) * 0x10000) >> 0x10,1);
    }
  }
  return;
}


// ---- 801e2e68 FUN_801e2e68

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801e2e68(undefined4 param_1)

{
  int iVar1;
  
  FUN_80104ccc();
  if ((_DAT_80170574 & 1) != 0) {
    Obj_CullAndQueueDraw(param_1);
    iVar1 = Obj_InActiveArea(param_1);
    if (iVar1 == 0) {
      Obj_Free(param_1);
    }
  }
  return;
}


// ---- 801e2ec8 FUN_801e2ec8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2ec8(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyFT4() + setSemiTrans(polyFT4, 1) */
  (*(code *)(&PTR_FUN_801f86ac)[obj->sub2])();
  return;
}


// ---- 801e2f04 FUN_801e2f04

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2f04(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  FUN_80104ccc();
  FUN_80106214(obj);
  iVar2 = Enemy_CheckWeaponHits(obj);
  if (iVar2 == 4) {
    FUN_801e342c((int)obj->x,(int)obj->y);
    FUN_8010544c(obj,9);
    Obj_Free(obj);
  }
  else if (((obj->field_0x33 & 0x30) == 0) && (iVar2 = Enemy_ContactDamage(obj), iVar2 == 0)) {
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->speed_y_up = 0x20000;
      if (obj->sub3 == 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
        obj->field_0x50 = 2;
        obj->sub3 = 1;
      }
      else {
        cVar1 = obj->field_0x50 + -1;
        obj->field_0x50 = cVar1;
        if (cVar1 == '\0') {
          obj->sub2 = 1;
          obj->sub3 = 0;
        }
      }
    }
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  else {
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801e3010 FUN_801e3010

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3010(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub3 == 0) {
    obj->field_0x50 = 0xc;
    obj->hitbox = &DAT_801f8600;
    FUN_801e342c((int)obj->x,(int)obj->y);
    FUN_8010544c(obj,9);
    obj->sub3 = 1;
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    Obj_Free(obj);
  }
  else {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801e30a8 FUN_801e30a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e30a8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    cVar2 = (&DAT_801f86b4)[(byte)obj->field_0x50 & 7];
    cVar4 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar4;
    obj->field_0x51 = cVar2 + '\b';
    if (cVar4 == '\0') {
      obj->field_0x51 = 8;
      obj->sub2 = 2;
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && (bVar1 = obj->field_0x51 + 1, obj->field_0x51 = bVar1, 8 < bVar1)) {
      obj->sub2 = 1;
      obj->field_0x50 = 0x3c;
    }
  }
  else if ((bVar1 == 2) &&
          (bVar1 = obj->field_0x51 - 1, obj->field_0x51 = bVar1, (int)((uint)bVar1 << 0x18) < 0)) {
LAB_801e3184:
    Obj_Free(obj);
    return;
  }
  FUN_8010bbe4((int)(char)obj->field_0x51);
  cVar2 = obj->field_0x52 + '\x01';
  obj->field_0x52 = cVar2;
  if (cVar2 == '\0') {
    obj->field_0x52 = 0xff;
  }
  iVar3 = FUN_80105d48(obj,0x36);
  if (iVar3 != 0) {
    piVar5 = (int *)(&DAT_801b103c + iVar3 * 4);
    do {
      iVar3 = iVar3 + -1;
      if ((*(char *)(*piVar5 + 7) == '\x05') && (*(byte *)(*piVar5 + 0x52) <= (byte)obj->field_0x52)
         ) goto LAB_801e3184;
      piVar5 = piVar5 + -1;
    } while (iVar3 != 0);
  }
  return;
}


// ---- 801e3238 FUN_801e3238

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3238(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f86bc)[obj->sub2])();
                    /* Possible PsyQ macro: setTile8() */
  if (obj->active != 0) {
    Enemy_CheckWeaponHits(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e32a0 FUN_801e32a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e32a0(MM8Obj *obj)

{
  if (obj->speed_y_up < -0x5bfff) {
    obj->speed_y_up = -0x60000;
    FUN_80104c34();
  }
  else {
    FUN_80104ccc(obj);
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x50 = 0x1e;
    Anim_Set(obj,2);
    FUN_800fd100(0xe0);
    obj->sub2 = 1;
  }
  return;
}


// ---- 801e3330 FUN_801e3330

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3330(MM8Obj *obj)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  Anim_Step();
  cVar4 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar4;
  iVar7 = 0;
  if (cVar4 == '\0') {
    uVar1 = obj->y;
    uVar2 = obj->x;
    do {
      uVar5 = Rand();
      iVar6 = FUN_801091a4((int)(((uint)uVar2 + iVar7 * 0x20) * 0x10000) >> 0x10,
                           (int)(((uVar1 - 8) + (uVar5 & 0xf)) * 0x10000) >> 0x10,0x80);
      if (iVar6 != 0) {
        *(undefined1 *)(iVar6 + 0x26) = 3;
                    /* Possible PsyQ macro: setPolyGT3() */
        *(undefined1 *)(iVar6 + 0x27) = 0x34;
        uVar3 = DAT_80159f98;
                    /* Possible PsyQ macro: setLineF2() */
        *(undefined1 *)(iVar6 + 0x38) = 0;
        *(undefined1 *)(iVar6 + 0x24) = uVar3;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 * 0x10000 >> 0x10 < 2);
    FUN_8010544c(obj,10);
                    /* Possible PsyQ macro: setLineF2() + setSemiTrans(lineF2, 1) */
    *(undefined1 *)(*(int *)&obj->field_0x4c + 0x5e) = 1;
    Obj_Free();
  }
  return;
}


// ---- 801e342c FUN_801e342c

int FUN_801e342c(short param_1,short param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_801091a4((int)param_1,(int)param_2,0x80);
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 0x26) = 3;
                    /* Possible PsyQ macro: setPolyGT3() */
    *(undefined1 *)(iVar2 + 0x27) = 0x34;
    uVar1 = DAT_80159f98;
    *(undefined1 *)(iVar2 + 0x38) = 0;
    *(undefined1 *)(iVar2 + 0x24) = uVar1;
  }
  return iVar2;
}


