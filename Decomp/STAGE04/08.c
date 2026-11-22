// ID 08, STAGE04.BIN, handler 0x801D8528. Ghidra output with the object struct applied; not matching C.
// ---- 801d8528 FUN_801d8528

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8528(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e6c98)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    if (obj->var < 2) {
      if (obj->field_0x52 == '\0') {
        Obj_FreeDespawn(obj);
      }
    }
    else {
      FUN_801d8be4(obj);
    }
  }
  return;
}


// ---- 801d85c4 FUN_801d85c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d85c4(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  
  Enemy_InitFromTable();
  obj->box2 = &DAT_801e6c84;
  bVar1 = obj->var;
  obj->var = obj->var & 0xf;
  bVar2 = obj->var;
  obj->field_0x53 = bVar1 & 0xf0;
  if (bVar2 == 2) {
    obj->state = 2;
    FUN_8010910c(obj);
    Anim_Set(obj,0);
    obj->draw_list = 7;
    obj->field_0x51 = 0;
    *(undefined4 *)&obj->field_0x54 = 0;
  }
  else if (bVar2 < 3) {
    obj->state = 4;
    obj->invuln = 1;
    obj->field_0x50 = 0x14;
    obj->field_0x52 = 0;
    obj->draw_list = 6;
    obj->flip = 0;
    *(undefined4 *)&obj->field_0x54 = 0;
    Anim_Set(obj,4);
  }
  else if (bVar2 == 3) {
    obj->state = 1;
    obj->hitbox = &DAT_801e6c94;
    FUN_8010910c(obj);
    Anim_Set(obj,1);
    obj->draw_list = 7;
    obj->field_0x51 = 1;
  }
  return;
}


// ---- 801d86e4 FUN_801d86e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d86e4(MM8Obj *obj)

{
  char cVar1;
  
  if ((short)obj->frame < 0) {
    obj->speed_y_up = -0x10000;
    obj->gravity = 0x4000;
    obj->state = 2;
    obj->speed_x = 0;
    obj->sub2 = 1;
    obj->sub3 = 1;
    obj->field_0x43 = 1;
  }
  Anim_Step(obj);
  if ((obj->anim_extra != 0) && (cVar1 = Enemy_CheckWeaponHits(obj), cVar1 == '\x04')) {
    obj->state = 3;
  }
  return;
}


// ---- 801d8774 FUN_801d8774

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8774(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e6cac)[obj->sub2])();
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x04') {
    obj->state = 3;
  }
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801d87e0 FUN_801d87e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d87e0(MM8Obj *obj)

{
  (**(code **)(&DAT_801e6cb4 + (uint)obj->sub3 * 4))();
  return;
}


// ---- 801d881c FUN_801d881c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d881c(MM8Obj *obj)

{
  int iVar1;
  
  obj->sub3 = 1;
  if (obj->field_0x51 != '\0') {
    iVar1._0_2_ = obj->x_frac;
    iVar1._2_2_ = obj->x;
    if ((byte)((iVar1 <= DAT_8015e248) << 6) != obj->flip) {
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
    obj->field_0x51 = 0;
  }
  obj->speed_y_up = 0;
  Anim_Set(obj,0);
  FUN_801d889c(obj);
  return;
}


// ---- 801d889c FUN_801d889c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d889c(MM8Obj *obj)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  
  bVar1 = obj->anim_extra;
  Anim_Step();
  if (bVar1 != 0) {
    if ((bVar1 & 0x40) == 0) {
      obj->hitbox = &DAT_801e6c90;
    }
    else {
      obj->hitbox = &DAT_801e6c8c;
    }
    uVar2 = bVar1 & 0xf;
    if ((obj->flip & 0x40) == 0) {
      uVar2 = -uVar2;
    }
    obj->x = obj->x + uVar2;
    obj->anim_extra = 0;
  }
  FUN_80106214(obj);
  FUN_801d8d48(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  else {
    iVar3 = FUN_801d8a5c(obj);
    if (iVar3 != 0) {
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801d8970 FUN_801d8970

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8970(MM8Obj *obj)

{
  short sVar1;
  
  if (obj->field_0x4 == '\0') {
    if ((obj->anim_extra & 0x80) != 0) {
      obj->field_0x4 = obj->field_0x4 + '\x01';
      Anim_Set(obj,2);
    }
    Anim_Step(obj);
  }
  else if ((short)obj->frame < 0) {
    obj->sub3 = 1;
    obj->flip = obj->flip ^ 0x40;
    Anim_Set(obj,0);
  }
  else {
    Anim_Step(obj);
    if (obj->anim_extra != 0) {
      if ((obj->flip & 0x40) == 0) {
        sVar1 = (short)(char)obj->anim_extra;
      }
      else {
        sVar1 = -(short)(char)obj->anim_extra;
      }
      obj->x = obj->x + sVar1;
      obj->anim_extra = 0;
    }
  }
  return;
}


// ---- 801d8a5c FUN_801d8a5c

undefined4 FUN_801d8a5c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*(byte *)(param_1 + 0x33) & 0x30) == 0) &&
      (uVar1 = 1, 9 < *(byte *)(param_1 + 0x41) - 0x11)) &&
     (uVar1 = 1, 9 < *(byte *)(param_1 + 0x42) - 0x11)) {
    uVar1 = FUN_801d8d48();
  }
  return uVar1;
}


// ---- 801d8ac0 FUN_801d8ac0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8ac0(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = -0x10000;
  if (obj->sub3 == 0) {
    obj->sub3 = obj->sub3 + 1;
    if ((obj->flip & 0x40) != 0) {
      iVar1 = 0x10000;
    }
    obj->speed_y_up = 0x20000;
    obj->gravity = 0x4000;
                    /* Possible PsyQ macro: setPolyF4() */
    obj->field_0x43 = 1;
    obj->speed_x = iVar1;
    obj->hitbox = &DAT_801e6c90;
    Anim_Set(obj,5);
  }
  if (obj->speed_y_up < -0x5ffff) {
    obj->speed_y_up = -0x60000;
  }
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  FUN_801d8d48(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x43 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801d8b9c FUN_801d8b9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8b9c(MM8Obj *obj)

{
  FUN_80108e84();
  FUN_8012a5fc(obj,3);
  FUN_80108fd8(obj,4);
  FUN_801d8be4(obj);
  return;
}


// ---- 801d8be4 FUN_801d8be4

void FUN_801d8be4(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x54);
  if ((((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) &&
      ((*(uint *)(pcVar2 + 4) & 0xffff0000) == 0x1080000)) &&
     (cVar1 = pcVar2[0x52], pcVar2[0x52] = cVar1 - 1U, (int)((uint)(byte)(cVar1 - 1U) << 0x18) < 0))
  {
    pcVar2[0x52] = '\0';
  }
  Obj_FreeDespawn();
  return;
}


// ---- 801d8c5c FUN_801d8c5c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8c5c(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  if ((((obj->sub2 == 0) && (uVar2 = FUN_801d8df0(), uVar2 < 8)) &&
      (cVar1 = obj->field_0x50 + -1, obj->field_0x50 = cVar1, cVar1 == '\0')) &&
     (puVar3 = (undefined1 *)Obj_AllocMain(), puVar3 != (undefined1 *)0x0)) {
    *puVar3 = 1;
    puVar3[6] = 8;
    puVar3[7] = 3;
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
    *(int *)(puVar3 + 0x10) = *(int *)&obj->y_frac + 0x2a0000;
    if (obj->var == 1) {
      obj->field_0x52 = obj->field_0x52 + '\x01';
      *(MM8Obj **)(puVar3 + 0x54) = obj;
      obj->field_0x50 = 0x80;
    }
    else {
      obj->sub2 = obj->sub2 + 1;
      *(undefined4 *)(puVar3 + 0x54) = 0;
    }
  }
  return;
}


// ---- 801d8d48 FUN_801d8d48

undefined4 FUN_801d8d48(int param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(char *)(param_1 + 0x53) != '\0') {
    pcVar2 = &DAT_801b1eec;
    do {
      uVar3 = uVar3 + 1;
      if (((*pcVar2 != '\0') && (pcVar2[6] == '\a')) &&
         (iVar1 = FUN_80107bf4(param_1,pcVar2,1), iVar1 != 0)) {
        return 1;
      }
      pcVar2 = pcVar2 + 0x50;
    } while (uVar3 < 0x20);
  }
  return 0;
}


// ---- 801d8df0 FUN_801d8df0

int FUN_801d8df0(void)

{
  char cVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar3 = &g_main_pool;
  iVar4 = 0;
  pbVar2 = &DAT_8015b1c6;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 0x60;
    if ((cVar1 == '\x01') && ((*(uint *)(pbVar2 + -0x4e) & 0xffff0000) == 0x1080000)) {
      iVar4 = iVar4 + (uint)*pbVar2;
    }
    pbVar2 = pbVar2 + 0x60;
  } while (pcVar3 <= "");
  return iVar4;
}


// ---- 801d8f44 FUN_801d8f44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8f44(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  Enemy_InitFromTable();
  obj->hitbox = &DAT_801e6cdc;
  obj->box2 = &DAT_801e6ce0;
  obj->state = 1;
  obj->draw_list = 7;
  obj->flip = 0;
  if (2 < (obj->var & 0xf)) {
    obj->dmg_table = 0x12;
  }
                    /* Possible PsyQ macro: setLineF2() */
  obj->field_0x50 = 1;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  obj->field_0x59 = 0;
  obj->field_0x58 = obj->var & 0x10;
  bVar1 = obj->var;
  obj->var = obj->var & 0xf;
  obj->field_0x5c = bVar1 >> 5;
  if (obj->var == 4) {
    obj->box2 = &DAT_801e6ce8;
    obj->draw_list = 6;
    iVar2 = FUN_801d99bc(obj);
    if (iVar2 != 0) {
      obj->var = 3;
    }
  }
  Anim_Set(obj,(&DAT_801e6ccc)[obj->var]);
  FUN_801d9914(obj,1);
  FUN_801d9914(obj,0);
  FUN_801d91f0(obj);
  return;
}


// ---- 801d9058 FUN_801d9058

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9058(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = obj->field_0x53;
  Anim_Step();
  FUN_801d91f0(obj);
  if (((obj->field_0x53 == '\0') && (cVar1 != '\0')) && (obj->speed_x == 0)) {
    obj->field_0x59 = 4;
    obj->field_0x5a = (char)obj->y;
    obj->field_0x5b = (char)((ushort)obj->y >> 8);
    FUN_801d9980(obj,1);
  }
  if (obj->field_0x59 != '\0') {
    cVar1 = obj->field_0x59 + -1;
    obj->field_0x59 = cVar1;
    obj->y = *(short *)&obj->field_0x5a;
    if (cVar1 == '\0') {
      obj->field_0x51 = 8;
      FUN_801d9914(obj,2);
    }
    else if (((byte)obj->field_0x59 >> 1 & 1) == 0) {
      obj->y = obj->y + 2;
    }
  }
  FUN_801d986c(obj);
  return;
}


// ---- 801d9164 FUN_801d9164

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9164(MM8Obj *obj)

{
  int iVar1;
  
  if ((&DAT_801e6cd4)[obj->var] != '\0') {
    FUN_801d9770();
  }
  FUN_8012ae08(obj,5);
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 != 0) {
    FUN_8010544c(obj,0x2c);
  }
  FUN_801d9914(obj,4);
  obj->field_0x50 = 2;
  Obj_Free(obj);
  return;
}


// ---- 801d91f0 FUN_801d91f0

void FUN_801d91f0(int param_1)

{
  int iVar1;
  
  DAT_801e7574 = *(undefined2 *)(param_1 + 0xe);
  DAT_801e7578 = *(undefined2 *)(param_1 + 0x12);
  Obj_ApplySpeed();
  FUN_801d96fc(param_1);
  iVar1 = FUN_801d9280(param_1);
  if (iVar1 != 4) {
    FUN_80106214(param_1);
    FUN_801d9680(param_1);
    FUN_801d9648(param_1);
    FUN_801d9358(param_1);
    FUN_801d946c(param_1);
    FUN_801d94a4(param_1);
  }
                    /* Probable PsyQ macro: setLineF2() */
  return;
}


// ---- 801d9280 FUN_801d9280

undefined4 FUN_801d9280(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* Possible PsyQ macro: setLineF2() */
  if (((*(char *)(param_1 + 0x51) != '\0') &&
      (cVar1 = *(char *)(param_1 + 0x51) + -1, *(char *)(param_1 + 0x51) = cVar1, cVar1 == '\0')) &&
     (99 < *(byte *)(*(int *)(param_1 + 0x28) + 2))) {
    Anim_Set(param_1,(&DAT_801e6ccc)[*(byte *)(param_1 + 7)]);
    *(undefined1 *)(param_1 + 0x31) = 1;
    Anim_StepN(param_1,1);
  }
  iVar2 = Enemy_CheckWeaponHits(param_1);
  if (iVar2 == 3) {
    *(undefined1 *)(param_1 + 0x51) = 0x10;
    uVar3 = 3;
  }
  else {
    uVar3 = 0;
    if (iVar2 == 4) {
      uVar3 = 4;
      *(undefined1 *)(param_1 + 1) = 2;
      *(undefined1 *)(param_1 + 0x50) = 2;
    }
  }
  return uVar3;
}


// ---- 801d9358 FUN_801d9358

void FUN_801d9358(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0x3f;
  iVar5 = 0x17a0;
  do {
    pcVar4 = &g_main_pool + iVar5;
    if (*pcVar4 != '\0') {
      cVar1 = *(char *)((int)&DAT_8015b178 + iVar5 + 2);
      if (cVar1 == '\f') {
        if (param_1 != pcVar4) {
          FUN_80107bf4(param_1,pcVar4,0);
          uVar2 = FUN_801082e0(param_1,pcVar4);
          if ((uVar2 & 0x70) != 0) {
            param_1[1] = '\x02';
            param_1[0x50] = '\x02';
            (&DAT_8015b175)[iVar5] = 2;
            (&UNK_8015b1c4)[iVar5] = 2;
            return;
          }
        }
      }
      else if (cVar1 == '\x05') {
        FUN_80107bf4(param_1,pcVar4,0);
        iVar3 = FUN_801082e0(param_1,pcVar4);
        if (iVar3 != 0) {
          (&UNK_8015b1cc)[iVar5] = 0xff;
        }
      }
    }
    iVar6 = iVar6 + -1;
    iVar5 = iVar5 + -0x60;
  } while (-1 < iVar6);
  return;
}


// ---- 801d946c FUN_801d946c

void FUN_801d946c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80109490();
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 1) = 2;
    *(undefined1 *)(param_1 + 0x50) = 2;
  }
  return;
}


// ---- 801d94a4 FUN_801d94a4

void FUN_801d94a4(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  short sVar4;
  undefined2 uVar5;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    return;
  }
  if (*(char *)(param_1 + 0x52) == '\0') {
    return;
  }
  if (*(char *)(param_1 + 0x52) < '\x01') {
                    /* Possible PsyQ macro: setPolyF4() */
    *(undefined4 *)(param_1 + 0x14) = 0xfffe0000;
    *(undefined4 *)(param_1 + 0x1c) = 0xffff8000;
    iVar2 = FUN_8012c108(param_1,param_1 + 0x50,0x18,0xe,0,0);
    if (iVar2 != 0) {
      *(undefined1 *)(iVar2 + 0x25) = 0;
      goto LAB_801d9558;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x20000;
    *(undefined4 *)(param_1 + 0x1c) = 0x8000;
    iVar2 = FUN_8012c108(param_1,param_1 + 0x50,0xffffffec,0xe,0,0);
    if (iVar2 != 0) {
                    /* Possible PsyQ macro: setLineF2() */
      *(undefined1 *)(iVar2 + 0x25) = 0x40;
LAB_801d9558:
      if (iVar2 != 0) {
        uVar5 = *(undefined2 *)(iVar2 + 0xe);
        sVar4 = *(short *)(iVar2 + 0x12);
                    /* Probable PsyQ macro: setTile16() */
        *(undefined1 *)(iVar2 + 7) = 0x70;
        *(undefined1 *)(iVar2 + 0x27) = 0x1b;
        *(undefined1 *)(iVar2 + 0x26) = 6;
        goto LAB_801d9588;
      }
    }
  }
  uVar5 = 0;
  sVar4 = 0;
LAB_801d9588:
  *(undefined1 *)(param_1 + 0x52) = 0;
  puVar3 = (undefined1 *)Obj_AllocType3();
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 1;
                    /* Possible PsyQ macro: setPolyF4() */
    puVar3[6] = 10;
    puVar3[7] = 1;
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    puVar3[0x26] = 7;
    *(undefined2 *)(puVar3 + 0xe) = uVar5;
    *(short *)(puVar3 + 0x12) = sVar4 + -0x12;
    puVar3[0x25] = uVar1;
  }
  iVar2 = Obj_InActiveArea(puVar3);
  if (iVar2 != 0) {
    FUN_8010544c(puVar3,0x7d);
  }
  iVar2 = FUN_80109430(param_1,&g_player,0x1c0,0x1c0);
  if (iVar2 != 0) {
    FUN_8010544c(param_1,0x7e);
  }
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_1 + 0x5a);
  FUN_801d9914(param_1,3);
  return;
}


// ---- 801d9648 FUN_801d9648

void FUN_801d9648(int param_1)

{
  if ((*(byte *)(param_1 + 7) < 3) && ((*(byte *)(param_1 + 0x33) & 0x30) != 0)) {
    *(undefined1 *)(param_1 + 1) = 2;
    *(undefined1 *)(param_1 + 0x50) = 2;
  }
  return;
}


// ---- 801d9680 FUN_801d9680

void FUN_801d9680(int param_1)

{
  if (((*(byte *)(param_1 + 0x33) | *(byte *)(param_1 + 0x40)) & 0x80) == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0x4000;
    *(undefined1 *)(param_1 + 0x53) = 1;
    *(undefined1 *)(param_1 + 0x43) = 1;
    *(undefined1 *)(param_1 + 0x50) = 1;
    *(char *)(param_1 + 0x5b) = (char)((ushort)*(undefined2 *)(param_1 + 0x12) >> 8);
    *(undefined1 *)(param_1 + 0x5a) = *(undefined1 *)(param_1 + 0x12);
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined1 *)(param_1 + 0x53) = 0;
    *(undefined1 *)(param_1 + 0x43) = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      if (*(int *)(param_1 + 0x14) < 0) {
        *(undefined1 *)(param_1 + 0x50) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x50) = 0x40;
      }
    }
  }
  return;
}


// ---- 801d96fc FUN_801d96fc

void FUN_801d96fc(int param_1)

{
  if (*(int *)(param_1 + 0x14) < 0x58000) {
    if (-0x58000 < *(int *)(param_1 + 0x14)) goto LAB_801d973c;
    *(undefined4 *)(param_1 + 0x14) = 0xfffa8000;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x58000;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
LAB_801d973c:
  if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x18) < -0x4ffff)) {
    *(undefined4 *)(param_1 + 0x18) = 0xfffb0000;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


// ---- 801d9770 FUN_801d9770

void FUN_801d9770(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  
  bVar1 = (&DAT_801e6cd4)[*(byte *)(param_1 + 7)];
  if (bVar1 == 1) {
    puVar3 = (undefined1 *)Obj_AllocType2();
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 0;
      puVar3[7] = (&DAT_801e6cd4)[*(byte *)(param_1 + 7)];
      *(short *)(puVar3 + 0xe) = *(short *)(param_1 + 0xe) + 4;
      *(undefined2 *)(puVar3 + 0x12) = *(undefined2 *)(param_1 + 0x12);
    }
  }
  else if ((((1 < bVar1) && (bVar1 != 4)) && (bVar1 == 5)) &&
          (puVar3 = (undefined1 *)FUN_801055e4(), puVar3 != (undefined1 *)0x0)) {
    *puVar3 = 1;
                    /* Probable PsyQ macro: setTile() */
    uVar2 = (&DAT_801e6cd4)[*(byte *)(param_1 + 7)];
    puVar3[7] = 0;
    puVar3[6] = uVar2;
    *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    *(short *)(puVar3 + 0x12) = *(short *)(param_1 + 0x12) + -3;
  }
  return;
}


// ---- 801d986c FUN_801d986c

void FUN_801d986c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
                    /* Possible PsyQ macro: setTile8() */
  if ((iVar1 != 0) && ((*(byte *)(param_1 + 0x33) & 0x80) != 0)) {
    iVar2 = (int)*(short *)(param_1 + 0xe) + (uint)(iVar1 < 1) * 4;
    if ((iVar2 == (iVar2 / 3) * 3) && (iVar2 = FUN_8012c8ec(param_1,0,0xe), iVar2 != 0)) {
      *(ushort *)(iVar2 + 0xe) = (ushort)(iVar1 < 1) * 4 + *(short *)(iVar2 + 0xe);
    }
  }
  return;
}


// ---- 801d9914 FUN_801d9914

void FUN_801d9914(int param_1,char param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_801093fc(param_1 + 0x54);
  if (((*(char *)(param_1 + 0x58) != '\0') && (*pcVar1 != '\0')) && (pcVar1[6] == '\x0e')) {
    pcVar1[0x52] = param_2;
  }
  return;
}


// ---- 801d9980 FUN_801d9980

void FUN_801d9980(int param_1,char param_2)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 0x4c);
  if (((*(char *)(param_1 + 0x58) != '\0') && (*pcVar1 != '\0')) && (pcVar1[6] == '\v')) {
    pcVar1[0x54] = param_2;
  }
  return;
}


// ---- 801d99bc FUN_801d99bc

bool FUN_801d99bc(int param_1)

{
  return ((&DAT_80139548)[(byte)(&DAT_801e6cf0)[*(byte *)(param_1 + 0x5c)] & 7] &
         *(byte *)((int)&DAT_8016d2f8 + ((byte)(&DAT_801e6cf0)[*(byte *)(param_1 + 0x5c)] >> 3) + 3)
         ) != 0;
}


