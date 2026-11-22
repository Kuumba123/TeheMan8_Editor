// ID 29, STAGE05.BIN, handler 0x801D9064. Ghidra output with the object struct applied; not matching C.
// ---- 801d9064 FUN_801d9064

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9064(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea2b8)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  return;
}


// ---- 801d90c4 FUN_801d90c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d90c4(MM8Obj *obj)

{
  Enemy_InitFromTable();
  (*(code *)(&PTR_FUN_801ea2c8)[obj->var & 0xf])(obj);
  return;
}


// ---- 801d9114 FUN_801d9114

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9114(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  byte bVar3;
  byte bVar4;
  MM8Obj *pMVar5;
  int iVar6;
  byte *pbVar7;
  MM8Obj *pMVar8;
  byte *pbVar9;
  uint uVar10;
  
  obj->draw_list = 7;
  obj->hitbox = &DAT_801ea270;
  obj->state = 1;
  obj->sub3 = 0;
  obj->dmg_table = 1;
  obj->field_0x51 = 0;
  obj->field_0x50 = 0;
  uVar10 = (obj->var & 0xf0) >> 3;
  iVar6 = uVar10 * 2;
  obj->x = *(short *)(&DAT_801ea278 + iVar6);
  sVar2 = *(short *)(&DAT_801ea27a + iVar6);
  obj->flip = ((obj->var & 0xf0) != 0) << 6;
  obj->y = sVar2;
  pbVar9 = *(byte **)((int)&PTR_DAT_801ea2ac + uVar10 * 2);
  pbVar7 = pbVar9 + 6;
  pMVar8 = obj;
  do {
    bVar1 = *pbVar9;
    pMVar5 = (MM8Obj *)FUN_801055e4(pMVar8);
    pbVar9 = pbVar9 + 8;
    if (pMVar5 != (MM8Obj *)0x0) {
      pMVar5->id = 0x29;
      pMVar5->active = 1;
      pMVar5->var = bVar1 & 0x7f;
      pMVar5->field_0x52 = pbVar7[-5];
      pMVar5->x = *(short *)(pbVar7 + -4);
      pMVar5->y = *(short *)(pbVar7 + -2);
      bVar3 = pbVar7[0];
      bVar4 = pbVar7[1];
      *(MM8Obj **)&pMVar5->field_0x4c = obj;
      pMVar5->field_0x4a = bVar3;
      pMVar5->field_0x4b = bVar4;
      pMVar8 = pMVar5;
    }
    pbVar7 = pbVar7 + 8;
  } while ((bVar1 & 0x80) == 0);
  Anim_Set(obj,2);
  DAT_801c3376 = 1;
  uVar10 = 0;
  do {
    FUN_80103638(uVar10,uVar10);
    uVar10 = uVar10 + 1;
  } while (uVar10 < 4);
                    /* Probable PsyQ macro: setLineF2() */
  return;
}


// ---- 801d9290 FUN_801d9290

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9290(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  
  obj->state = 2;
  obj->hitbox = &DAT_801ea26c;
  obj->flip = 0x80;
  obj->draw_list = 1;
  obj->speed_y_up = 0x3333;
  if ((obj->var & 1) != 0) {
    obj->flip = 0;
    obj->speed_y_up = -0x3333;
  }
  obj->field_0x50 = 0x78;
  puVar2 = (undefined1 *)FUN_801055e4(obj);
  if (puVar2 != (undefined1 *)0x0) {
    puVar2[6] = 0x29;
    *puVar2 = 1;
    puVar2[7] = 5;
    *(short *)(puVar2 + 0xe) = obj->x + 0x80;
    *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)&obj->y_frac;
    bVar1 = obj->flip;
    *(MM8Obj **)(puVar2 + 0x4c) = obj;
    puVar2[0x25] = bVar1;
  }
  puVar2 = (undefined1 *)FUN_80105628();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 3;
    puVar2[7] = 3;
    bVar1 = obj->flip;
    puVar2[0x46] = 1;
    *(MM8Obj **)(puVar2 + 0x54) = obj;
    puVar2[0x25] = bVar1;
  }
  FUN_801d9b58(obj);
  obj->var = 1;
  Anim_Set(obj,0);
  return;
}


// ---- 801d939c FUN_801d939c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d939c(MM8Obj *obj)

{
  obj->sub2 = 1;
  FUN_801d9290(obj);
  return;
}


// ---- 801d93c0 FUN_801d93c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d93c0(MM8Obj *obj)

{
  obj->state = 3;
  FUN_801d9b58();
  Anim_Set(obj,1);
  return;
}


// ---- 801d93fc FUN_801d93fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d93fc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea2e0)[obj->sub2])();
  return;
}


// ---- 801d9438 FUN_801d9438

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9438(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = Enemy_CheckWeaponHits();
  if (iVar2 != 0) {
    if (iVar2 == 4) {
      bVar1 = 3;
    }
    else if (DAT_80158f5c == 0xb) {
      bVar1 = 1;
    }
    else {
      bVar1 = 2;
      if (1 < DAT_80158f5c) {
        return;
      }
    }
    obj->sub2 = bVar1;
  }
  return;
}


// ---- 801d94a4 FUN_801d94a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d94a4(MM8Obj *obj)

{
  if ((obj->sub3 == 0) && (Anim_Step(), (short)obj->frame < 0)) {
    FUN_801d95c8(obj);
  }
  return;
}


// ---- 801d94f8 FUN_801d94f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d94f8(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
                    /* Possible PsyQ macro: setLineF2() */
    obj->field_0x50 = obj->field_0x50 + '\x01';
                    /* Possible PsyQ macro: setPolyF4() */
    if (2 < (byte)obj->field_0x50) {
      obj->hitbox = &DAT_801ea274;
    }
    Anim_SetAtStep(obj,2,obj->field_0x50);
    obj->anim_timer = 1;
    if ((short)obj->frame < 0) {
      FUN_801d95c8(obj);
                    /* Probable PsyQ macro: setTile16() */
    }
    else {
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801d958c FUN_801d958c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d958c(MM8Obj *obj)

{
  FUN_80108e84();
                    /* Possible PsyQ macro: setPolyF4() */
  FUN_8012a5fc(obj,0);
  Obj_Free(obj);
  return;
}


// ---- 801d95c8 FUN_801d95c8

void FUN_801d95c8(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  DAT_801c3376 = 0;
  do {
    FUN_80103638(uVar1,uVar1);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 4);
  *(undefined1 *)(param_1 + 0x51) = 1;
  DAT_801b29a0 = 1;
  *(undefined1 *)(param_1 + 3) = 1;
                    /* Probable PsyQ macro: setTile() */
  return;
}


// ---- 801d9630 FUN_801d9630

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9630(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801ea2f0)[obj->sub2])();
  if (obj->active != 0) {
    Enemy_ContactDamage(obj);
    Enemy_CheckWeaponHits(obj);
  }
  return;
}


// ---- 801d9a6c FUN_801d9a6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9a6c(MM8Obj *obj)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->field_0x4c;
  if ((*pcVar2 == '\0') || ((*(uint *)(pcVar2 + 4) & 0xffff0000) != 0x1290000)) {
    Obj_Free();
  }
  else {
    obj->x = *(short *)(pcVar2 + 0xe) + 0x80;
    uVar1 = *(undefined4 *)(pcVar2 + 0x10);
    obj->y_frac = (short)uVar1;
    obj->y = (short)((uint)uVar1 >> 0x10);
    if (obj->sub3 == 0) {
      if (pcVar2[2] == '\x03') {
        obj->sub3 = 1;
      }
    }
    else {
      if (pcVar2[2] != '\x03') {
        obj->sub3 = 0;
      }
      Anim_Step();
    }
  }
  return;
}


// ---- 801d9b58 FUN_801d9b58

void FUN_801d9b58(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x1f;
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    *(int *)(puVar2 + 0x38) = param_1;
    puVar2[0x25] = uVar1;
  }
  return;
}


