// ID 04, STAGE00.BIN, handler 0x801D86D8. Ghidra output with the object struct applied; not matching C.
// ---- 801d86d8 FUN_801d86d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d86d8(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e2590)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDrawMargin(obj,0x38);
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801d8750 FUN_801d8750

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8750(MM8Obj *obj)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  
  obj->bank = 8;
  obj->vram_base = DAT_80170358;
  bVar2 = obj->var & 0x7f;
  obj->clut = DAT_80159f6c;
  if (bVar2 == 2) {
    uVar3 = 0xc;
    obj->dmg_table = 2;
    obj->hitbox = &DAT_801e2564;
    obj->box2 = &DAT_801e2570;
    obj->hp = 5;
    obj->contact_dmg = 4;
    obj->state = 1;
    obj->field_0x56 = 0;
    obj->invuln = 1;
    obj->draw_list = 7;
    obj->field_0x55 = 1;
  }
  else {
    if (bVar2 < 3) {
      obj->draw_list = 7;
      obj->hitbox = &DAT_801e2568;
      obj->box2 = &DAT_801e2575;
      obj->state = 2;
      obj->field_0x56 = 0;
      obj->dmg_table = 2;
      obj->invuln = 0;
      obj->hp = 0xc;
      obj->field_0x55 = 0;
      obj->field_0x57 = 0;
      obj->field_0x58 = 0;
      obj->field_0x59 = 0;
      obj->flip = 0;
      Anim_Set(obj,0);
      puVar1 = (undefined1 *)FUN_801055e4(obj);
      if (puVar1 == (undefined1 *)0x0) {
        return;
      }
      if (obj->var != 0) {
        return;
      }
      *puVar1 = 1;
      puVar1[6] = 4;
      puVar1[7] = 2;
      *(short *)(puVar1 + 0xe) = obj->x;
      *(short *)(puVar1 + 0x12) = obj->y + -2;
      *(undefined1 **)&obj->field_0x50 = puVar1;
      *(MM8Obj **)(puVar1 + 0x50) = obj;
      obj->field_0x55 = 1;
      return;
    }
    iVar4 = -0x30000;
    if (bVar2 != 3) {
      return;
    }
    obj->draw_list = 5;
    obj->field_0x56 = 1;
    obj->hitbox = &DAT_801e256c;
    obj->box2 = &DAT_801e257a;
    obj->state = 3;
    obj->invuln = 0;
    obj->dmg_table = 2;
    obj->hp = 2;
    obj->contact_dmg = 3;
    if (obj->flip != 0) {
      iVar4 = 0x30000;
    }
    uVar3 = 0x13;
    obj->speed_y_up = 0x8000;
    obj->speed_x = iVar4;
    obj->gravity = 0x400;
  }
  Anim_Set(obj,uVar3);
  return;
}


// ---- 801d8960 FUN_801d8960

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8960(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e25a0)[obj->sub2])();
  iVar1 = Enemy_CheckWeaponHits(obj);
  if (iVar1 == 2) {
    obj->clut = 0;
  }
  else {
    obj->clut = DAT_80159f6c;
  }
  if (iVar1 == 4) {
    obj->sub2 = 2;
    obj->sub3 = 0;
  }
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801d89f4 FUN_801d89f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d89f4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  if (obj->sub3 == 0) {
    Anim_Set(obj,0xc);
    iVar2 = (int)DAT_8015e248._2_2_ - (int)obj->x;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 < 0x6a) {
      obj->sub3 = 1;
      FUN_8010910c(obj);
      if (obj->field_0x55 == '\x01') {
        *(undefined1 *)(*(int *)&obj->field_0x50 + 0x57) = 3;
      }
      obj->field_0x54 = 0;
      FUN_801d9330(obj);
      FUN_8010544c(obj,0x55);
    }
  }
  else {
    if ((obj->anim_extra != 0) && (obj->field_0x55 != '\0')) {
      bVar1 = obj->field_0x54;
      obj->field_0x54 = bVar1 + 1;
      *(short *)(*(int *)&obj->field_0x50 + 0x12) =
           *(short *)(*(int *)&obj->field_0x50 + 0x12) + *(short *)(&DAT_801e2538 + (uint)bVar1 * 2)
      ;
      obj->anim_extra = 0;
    }
    if ((short)obj->frame < 0) {
      obj->sub2 = 1;
      obj->sub3 = 0;
      obj->invuln = 0;
      obj->field_0x56 = 1;
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801d8b20 FUN_801d8b20

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8b20(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e25ac)[obj->sub3])();
  Anim_Step(obj);
  FUN_80107bf4(obj,&g_player,1);
  return;
}


// ---- 801d8b84 FUN_801d8b84

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8b84(MM8Obj *obj)

{
  obj->sub3 = 1;
  obj->field_0x54 = 0x14;
  Anim_Set(obj,0xb);
  return;
}


// ---- 801d8bb4 FUN_801d8bb4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8bb4(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = obj->field_0x54 + -1;
  obj->field_0x54 = cVar1;
  if (cVar1 == '\0') {
    obj->sub3 = 3;
    FUN_801d8e14();
    uVar3 = 0xe;
  }
  else {
    iVar2._0_2_ = obj->x_frac;
    iVar2._2_2_ = obj->x;
    obj->field_0x57 = (iVar2 <= DAT_8015e248) << 6;
    if (obj->flip == obj->field_0x57) {
      return;
    }
    obj->sub3 = 2;
    uVar3 = 0xd;
  }
  Anim_Set(obj,uVar3);
  return;
}


// ---- 801d8c50 FUN_801d8c50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8c50(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    obj->flip = obj->field_0x57;
    Anim_Set(obj,0xb);
    obj->sub3 = 1;
  }
  return;
}


// ---- 801d8c98 FUN_801d8c98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8c98(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    Anim_Set(obj,0xb);
    obj->sub3 = 1;
    obj->field_0x54 = 0x5a;
  }
  return;
}


// ---- 801d8ce4 FUN_801d8ce4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8ce4(MM8Obj *obj)

{
  byte bVar1;
  
  if (obj->sub3 == 0) {
    obj->sub3 = 1;
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    FUN_8012ae08(obj,2);
    obj->field_0x54 = 0;
    Anim_Set(obj,0xf);
    if (obj->field_0x55 == '\x01') {
      *(undefined1 *)(*(int *)&obj->field_0x50 + 0x57) = 0x19;
    }
  }
  else if (obj->sub3 == 1) {
    Anim_Step(obj);
    if ((obj->anim_extra != 0) && (obj->field_0x55 != '\0')) {
      bVar1 = obj->field_0x54;
      obj->field_0x54 = bVar1 + 1;
      *(short *)(*(int *)&obj->field_0x50 + 0x12) =
           *(short *)(*(int *)&obj->field_0x50 + 0x12) + *(short *)(&DAT_801e2540 + (uint)bVar1 * 2)
      ;
      obj->anim_extra = 0;
    }
    if ((short)obj->frame < 0) {
      if (obj->field_0x55 != '\0') {
        *(undefined1 *)(*(int *)&obj->field_0x50 + 0x55) = 0;
      }
      obj->sub3 = 2;
    }
    obj->invuln = 1;
  }
  return;
}


// ---- 801d8e14 FUN_801d8e14

void FUN_801d8e14(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 4;
    puVar1[7] = 3;
    iVar2 = 0x140000;
    if (*(char *)(param_1 + 0x25) == '\0') {
      iVar2 = -0x140000;
    }
    *(int *)(puVar1 + 0xc) = *(int *)(param_1 + 0xc) + iVar2;
    *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    puVar1[0x25] = *(undefined1 *)(param_1 + 0x25);
    FUN_8010544c(param_1,0xc);
  }
  return;
}


// ---- 801d8e94 FUN_801d8e94

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8e94(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    FUN_801d8f10(obj);
  }
  else if (obj->sub2 == 1) {
    FUN_801d9108(obj);
  }
  Anim_Step(obj);
  if ((short)obj->frame < 0) {
    obj->field_0x59 = 0;
    obj->field_0x57 = 0;
  }
  return;
}


// ---- 801d8f10 FUN_801d8f10

void FUN_801d8f10(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  
  *(undefined **)(param_1 + 0x38) = &UNK_801e257f + (uint)*(byte *)(param_1 + 0x32) * 5;
  iVar2 = FUN_80107bf4(param_1,&g_player,5);
  if (((iVar2 != 0) && ((~*(byte *)(param_1 + 0x58) & 2) != 0)) &&
     (*(char *)(param_1 + 0x59) == '\0')) {
    *(undefined1 *)(param_1 + 0x57) = 0x1a;
    *(undefined1 *)(param_1 + 0x59) = 1;
    FUN_8010544c(param_1,0x54);
  }
  bVar1 = *(byte *)(param_1 + 0x58) & 0xfd;
  if (iVar2 != 0) {
    bVar1 = bVar1 | 2;
  }
  *(byte *)(param_1 + 0x58) = bVar1;
  *(undefined **)(param_1 + 0x38) = &DAT_801e2575;
  iVar2 = FUN_80107bf4(param_1,&g_player,1);
  if (((iVar2 != 0) && ((~*(byte *)(param_1 + 0x58) & 1) != 0)) &&
     (*(char *)(param_1 + 0x59) == '\0')) {
    uVar3 = 2;
    if (DAT_8015e248 < *(int *)(param_1 + 0xc)) {
      uVar3 = 1;
    }
    *(undefined1 *)(param_1 + 0x57) = uVar3;
    *(undefined1 *)(param_1 + 0x59) = 0;
    FUN_8010544c(param_1,0x54);
  }
  *(byte *)(param_1 + 0x58) = *(byte *)(param_1 + 0x58) & 0xfe | iVar2 != 0;
  iVar2 = Enemy_CheckWeaponHits(param_1);
  if (iVar2 == 4) {
    *(undefined1 *)(param_1 + 2) = 1;
  }
  if (iVar2 == 2) {
    uVar3 = 2;
    if (DAT_8015e248 < *(int *)(param_1 + 0xc)) {
      uVar3 = 1;
    }
    *(undefined1 *)(param_1 + 0x57) = uVar3;
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x24) = DAT_80159f6c;
  }
  if ((*(char *)(param_1 + 0x57) != '\0') && (*(byte *)(param_1 + 0x59) < 2)) {
    Anim_Set(param_1);
    *(undefined1 *)(param_1 + 0x57) = 0;
    *(char *)(param_1 + 0x59) = *(char *)(param_1 + 0x59) + '\x01';
  }
  return;
}


// ---- 801d9108 FUN_801d9108

void FUN_801d9108(int param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  
  uVar4 = 0;
  psVar3 = &DAT_801e254c;
  *(undefined1 *)(param_1 + 0x57) = 0;
  *(undefined1 *)(param_1 + 0x46) = 1;
  do {
    puVar1 = (undefined1 *)Obj_AllocType3();
    uVar4 = uVar4 + 1;
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar1[6] = 0;
      uVar2 = Rand();
      *(short *)(puVar1 + 0xe) =
           *(short *)(param_1 + 0xe) + *(short *)(&DAT_801e2554 + (uVar2 & 7) * 2);
      uVar2 = Rand();
      *(short *)(puVar1 + 0x12) =
           *(short *)(param_1 + 0x12) + *psVar3 + *(short *)(&DAT_801e2554 + (uVar2 & 7) * 2);
    }
    psVar3 = psVar3 + 1;
  } while (uVar4 < 3);
  FUN_8012ae08(param_1,1);
  Anim_Set(param_1,10);
  *(undefined1 *)(param_1 + 2) = 2;
  return;
}


// ---- 801d9204 FUN_801d9204

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9204(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (obj->sub3 == 0) {
    obj->sub3 = 1;
    obj->field_0x54 = 0x18;
  }
  FUN_80104ccc(obj);
  Anim_Step(obj);
  if (obj->field_0x54 != '\0') {
    bVar1 = obj->field_0x54 - 1;
    obj->field_0x54 = bVar1;
    if ((uint)bVar1 % 3 != 0) {
      uVar2 = Rand();
      FUN_801091a4((int)obj->x,(int)((((ushort)obj->y + 3) - (uVar2 & 7)) * 0x10000) >> 0x10,1);
    }
  }
  iVar3 = Enemy_CheckWeaponHits(obj);
  iVar4 = Enemy_ContactDamage(obj);
  FUN_80106214(obj);
  if (((iVar4 == 2) || (iVar3 == 4)) || ((obj->field_0x33 & 0xf0) != 0)) {
    FUN_80108e84(obj);
    Obj_Free(obj);
  }
  return;
}


// ---- 801d9330 FUN_801d9330

void FUN_801d9330(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0x10;
  do {
    puVar2 = (undefined1 *)Obj_AllocType3();
    if (puVar2 == (undefined1 *)0x0) {
      return;
    }
    puVar2[6] = 0xf;
    *puVar2 = 1;
    puVar2[7] = 0;
    puVar2[0x27] = 8;
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    puVar2[0x25] = *(undefined1 *)(param_1 + 0x25);
    uVar1 = (&UNK_801e257c)[iVar3];
    uVar4 = uVar4 + 1;
    puVar2[0x39] = (char)iVar3;
    puVar2[0x38] = 0;
    puVar2[0x26] = uVar1;
    iVar3 = iVar3 + 1;
  } while (uVar4 < 3);
  return;
}


