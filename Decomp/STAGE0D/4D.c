// ID 4D, STAGE0D.BIN, handler 0x801F0CE0. Ghidra output with the object struct applied; not matching C.
// ---- 801f0ce0 FUN_801f0ce0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f0ce0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8e80)[obj->state])();
  return;
}


// ---- 801f0d1c FUN_801f0d1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f0d1c(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  
  Enemy_InitFromTable();
  iVar2 = (uint)obj->var * 8;
  obj->dmg_table = (&DAT_801f8e2d)[iVar2];
  obj->contact_dmg = (&DAT_801f8e2e)[iVar2];
  obj->hp = (&DAT_801f8e2f)[iVar2];
  obj->draw_list = (&DAT_801f8e30)[iVar2];
  obj->hitbox = &DAT_801f8e5c + (uint)(byte)(&DAT_801f8e31)[iVar2] * 4;
  obj->box2 = &UNK_801f8e74 + (uint)(byte)(&DAT_801f8e32)[iVar2] * 5;
  Anim_Set(obj,(&DAT_801f8e33)[iVar2]);
  obj->field_0x51 = 0;
  obj->field_0x50 = 4;
  obj->field_0x52 = 0;
  obj->field_0x54 = 0;
  bVar1 = obj->var;
  obj->state = (&DAT_801f8e2c)[iVar2];
  if (bVar1 == 1) {
    obj->field_0x53 = 0;
    puVar3 = (undefined1 *)Obj_AllocType3();
    if (puVar3 == (undefined1 *)0x0) {
      return;
    }
    *puVar3 = 1;
  }
  else {
    if (bVar1 == 0) {
      return;
    }
    if (3 < bVar1) {
      return;
    }
    Anim_SetAtStep(obj,(&DAT_801f8e33)[iVar2],obj->field_0x53);
    obj->anim_timer = 3;
    obj->var = 1;
    puVar3 = (undefined1 *)Obj_AllocType3();
    if (puVar3 == (undefined1 *)0x0) {
      return;
    }
    *puVar3 = 1;
  }
  puVar3[6] = 0x39;
  puVar3[7] = 0;
  *(MM8Obj **)(puVar3 + 0x1c) = obj;
  return;
}


// ---- 801f0e70 FUN_801f0e70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f0e70(MM8Obj *obj)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)&obj->field_0x4c;
  if ((*pcVar4 == '\0') || (pcVar4[6] != 'L')) {
    Obj_Free(obj);
  }
  else {
    obj->flip = pcVar4[0x25];
    obj->clut = pcVar4[0x24];
    if (obj->sub2 != 0) {
      FUN_801f1058(obj);
    }
    if (pcVar4[0x51] != '\0') {
      switch(pcVar4[0x51]) {
      case '\x01':
        Anim_Set(obj,0);
        obj->sub2 = 0;
        obj->field_0x51 = 1;
        break;
      case '\x02':
        obj->sub2 = 0;
        obj->field_0x51 = 0;
        uVar2 = *(undefined4 *)(pcVar4 + 0xc);
        obj->x_frac = (short)uVar2;
        obj->x = (short)((uint)uVar2 >> 0x10);
        break;
      case '\x03':
        obj->sub2 = 1;
        obj->sub3 = 0;
        iVar1 = obj->speed_x >> 0xc;
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        iVar3 = (int)*(short *)(pcVar4 + 0x54) - (int)obj->x;
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 <= (short)iVar1) {
          obj->sub3 = 1;
        }
        iVar1 = *(int *)(pcVar4 + 0x14);
        obj->speed_y_up = 0;
        obj->speed_x = iVar1 << 1;
        if ((ushort)(byte)pcVar4[0x54] != obj->x) {
          Anim_Set(obj,1);
          obj->hitbox = &DAT_801f8e60;
        }
        obj->field_0x51 = 1;
        break;
      case '\x04':
        uVar2 = *(undefined4 *)(pcVar4 + 0xc);
        obj->x_frac = (short)uVar2;
        obj->x = (short)((uint)uVar2 >> 0x10);
        uVar2 = *(undefined4 *)(pcVar4 + 0x10);
        obj->y_frac = (short)uVar2;
        obj->y = (short)((uint)uVar2 >> 0x10);
        break;
      case '\x05':
        Obj_Free(obj);
        pcVar4[0x51] = '\0';
      }
      pcVar4[0x51] = '\0';
    }
    Enemy_CheckWeaponHits(obj);
    Enemy_ContactDamage(obj);
    FUN_80106214(obj);
    if ((obj->field_0x51 != '\0') && (obj->active != 0)) {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801f1058 FUN_801f1058

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801f1058(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x4c);
  sVar3 = *(short *)(iVar4 + 0x54);
  FUN_80104c34();
  Anim_Step(param_1);
  if (*(char *)(param_1 + 3) == '\0') {
    iVar1 = *(int *)(param_1 + 0x14) >> 0xc;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    iVar2 = (int)sVar3 - (int)*(short *)(param_1 + 0xe);
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 <= (short)iVar1) {
      Anim_Set(param_1,2);
      *(undefined1 *)(param_1 + 3) = 1;
    }
  }
  if (*(int *)(param_1 + 0x14) < 0) {
    if (sVar3 < *(short *)(param_1 + 0xe)) goto LAB_801f114c;
  }
  else if (*(short *)(param_1 + 0xe) < sVar3) goto LAB_801f114c;
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(iVar4 + 0x54);
  Anim_Set(param_1,0);
  *(undefined **)(param_1 + 0x3c) = &DAT_801f8e5c;
  *(undefined1 *)(param_1 + 2) = 0;
LAB_801f114c:
  if ((*(char *)(param_1 + 0x30) == '\x02') && ((_DAT_80170574 & 3) == 0)) {
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar3 = *(short *)(param_1 + 0xe) + -0x23;
    }
    else {
      sVar3 = *(short *)(param_1 + 0xe) + 0x23;
    }
    FUN_801091a4((int)sVar3,(int)((*(ushort *)(param_1 + 0x12) + 0x25) * 0x10000) >> 0x10,1);
  }
  return;
}


// ---- 801f11d0 FUN_801f11d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f11d0(MM8Obj *obj)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  
  iVar4 = *(int *)&obj->field_0x4c;
  Anim_Step();
  obj->y = obj->y + -4;
  if ((obj->field_0x50 == '\0') || (*(char *)(iVar4 + 0x5b) != '\0')) goto LAB_801f12b8;
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  uVar3 = 2;
  if (cVar1 != '\0') goto LAB_801f12b8;
  puVar2 = (undefined1 *)FUN_801055e4(obj);
  if (puVar2 == (undefined1 *)0x0) {
    uVar3 = 3;
    puVar2 = (undefined1 *)Obj_AllocMain();
    if (puVar2 != (undefined1 *)0x0) goto LAB_801f1258;
  }
  else {
LAB_801f1258:
    *puVar2 = 1;
    puVar2[6] = 0x4d;
    puVar2[7] = uVar3;
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
    *(short *)(puVar2 + 0x12) = obj->y + 0x10;
    puVar2[0x25] = obj->flip;
    puVar2[0x53] = obj->anim_extra + 1 & 7;
    *(undefined4 *)(puVar2 + 0x4c) = *(undefined4 *)&obj->field_0x4c;
  }
  obj->field_0x52 = 1;
LAB_801f12b8:
  if (obj->y < DAT_801d292a) {
    Obj_Free(obj);
  }
  else {
    obj->invuln = 0;
    Enemy_CheckWeaponHits(obj);
    obj->invuln = 1;
    iVar4 = Enemy_ContactDamage(obj);
    if ((iVar4 != 0) && (puVar2 = (undefined1 *)Obj_AllocType3(), puVar2 != (undefined1 *)0x0)) {
      puVar2[6] = 0x39;
      *puVar2 = 1;
      puVar2[7] = 7;
    }
    if (obj->active != 0) {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801f1358 FUN_801f1358

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f1358(MM8Obj *obj)

{
  undefined1 *puVar1;
  uint uVar2;
  
  if (obj->sub2 == 0) {
    obj->speed_y_up = -0x80000;
    obj->speed_x = 0;
    obj->sub2 = 1;
  }
  FUN_80104c34(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->hitbox = &DAT_801f8e68;
    Enemy_CheckWeaponHits(obj);
    Enemy_ContactDamage(obj);
    obj->hitbox = &DAT_801f8e6c;
    Enemy_CheckWeaponHits(obj);
    Enemy_ContactDamage(obj);
    Obj_CullAndQueueDraw(obj);
  }
  else {
    DAT_801d2936 = 0x3c;
    uVar2 = 0;
    do {
      puVar1 = (undefined1 *)Obj_AllocType3();
      if (puVar1 != (undefined1 *)0x0) {
        *puVar1 = 1;
        puVar1[6] = 0x39;
        puVar1[7] = (char)uVar2 + 2U | 0x80;
        *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)&obj->x_frac;
        *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)&obj->y_frac;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 5);
    FUN_8012ae08(obj,0x34);
    FUN_8010544c(obj,0x16c);
    Obj_Free(obj);
  }
  return;
}


// ---- 801f1498 FUN_801f1498

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f1498(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    bVar1 = obj->flip ^ 0x40;
    obj->flip = bVar1;
    iVar3 = 0x30000;
    if ((bVar1 & 0x40) != 0) {
      iVar3 = -0x30000;
    }
    obj->speed_x = iVar3;
    obj->speed_y_up = 0;
    obj->sub2 = 1;
  }
  FUN_80104c34(obj);
  Anim_Step(obj);
  if (((short)obj->frame < 0) || (iVar3 = Enemy_CheckWeaponHits(obj), iVar3 == 1)) {
    Obj_Free(obj);
  }
  else {
    iVar3 = Enemy_ContactDamage(obj);
    if ((iVar3 != 0) && (puVar2 = (undefined1 *)Obj_AllocType3(), puVar2 != (undefined1 *)0x0)) {
      *puVar2 = 1;
      puVar2[6] = 0x39;
      puVar2[7] = 7;
    }
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


