// ID 0C, STAGE01.BIN, handler 0x801DBDE4. Ghidra output with the object struct applied; not matching C.
// ---- 801dbde4 FUN_801dbde4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbde4(MM8Obj *obj)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (obj->state != 0) {
    if (((obj->var & 0x10) != 0) && (iVar1 = FUN_80109430(obj,&g_player,0x400,0x400), iVar1 == 0)) {
      return;
    }
    uVar2 = (uint)obj->state;
  }
  (*(code *)(&PTR_FUN_801e68b0)[uVar2])(obj);
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    iVar1 = Obj_InActiveArea(obj);
    if ((iVar1 == 0) && (obj->field_0x58 == '\0')) {
      if (obj->speed_x == 0) {
        Obj_FreeDespawn(obj);
      }
      else {
        Obj_Free(obj);
      }
    }
  }
  return;
}


// ---- 801dbec8 FUN_801dbec8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbec8(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  Enemy_InitFromTable();
  obj->hitbox = &DAT_801e68cc;
  obj->box2 = &DAT_801e68d0;
  obj->state = 1;
  obj->draw_list = 7;
  obj->flip = 0;
  if (2 < (obj->var & 0xf)) {
    obj->dmg_table = 0x12;
  }
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
    obj->box2 = &DAT_801e68d8;
    obj->draw_list = 6;
    iVar2 = FUN_801dc940(obj);
    if (iVar2 != 0) {
      obj->var = 3;
    }
  }
  Anim_Set(obj,(&DAT_801e68bc)[obj->var]);
  FUN_801dc898(obj,1);
  FUN_801dc898(obj,0);
  FUN_801dc174(obj);
  return;
}


// ---- 801dbfdc FUN_801dbfdc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbfdc(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = obj->field_0x53;
  Anim_Step();
  FUN_801dc174(obj);
  if (((obj->field_0x53 == '\0') && (cVar1 != '\0')) && (obj->speed_x == 0)) {
    obj->field_0x59 = 4;
    obj->field_0x5a = (char)obj->y;
    obj->field_0x5b = (char)((ushort)obj->y >> 8);
    FUN_801dc904(obj,1);
  }
  if (obj->field_0x59 != '\0') {
    cVar1 = obj->field_0x59 + -1;
    obj->field_0x59 = cVar1;
    obj->y = *(short *)&obj->field_0x5a;
    if (cVar1 == '\0') {
      obj->field_0x51 = 8;
      FUN_801dc898(obj,2);
    }
    else if (((byte)obj->field_0x59 >> 1 & 1) == 0) {
      obj->y = obj->y + 2;
    }
  }
  FUN_801dc7f0(obj);
  return;
}


// ---- 801dc0e8 FUN_801dc0e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc0e8(MM8Obj *obj)

{
  int iVar1;
  
  if ((&DAT_801e68c4)[obj->var] != '\0') {
    FUN_801dc6f4();
  }
  FUN_8012ae08(obj,5);
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 != 0) {
    FUN_8010544c(obj,0x2c);
  }
  FUN_801dc898(obj,4);
  obj->field_0x50 = 2;
  Obj_Free(obj);
  return;
}


// ---- 801dc174 FUN_801dc174

void FUN_801dc174(int param_1)

{
  int iVar1;
  
  DAT_801e70d4 = *(undefined2 *)(param_1 + 0xe);
  DAT_801e70d8 = *(undefined2 *)(param_1 + 0x12);
  Obj_ApplySpeed();
  FUN_801dc680(param_1);
  iVar1 = FUN_801dc204(param_1);
  if (iVar1 != 4) {
    FUN_80106214(param_1);
    FUN_801dc604(param_1);
    FUN_801dc5cc(param_1);
    FUN_801dc2dc(param_1);
    FUN_801dc3f0(param_1);
    FUN_801dc428(param_1);
  }
  return;
}


// ---- 801dc204 FUN_801dc204

undefined4 FUN_801dc204(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((*(char *)(param_1 + 0x51) != '\0') &&
      (cVar1 = *(char *)(param_1 + 0x51) + -1, *(char *)(param_1 + 0x51) = cVar1, cVar1 == '\0')) &&
     (99 < *(byte *)(*(int *)(param_1 + 0x28) + 2))) {
    Anim_Set(param_1,(&DAT_801e68bc)[*(byte *)(param_1 + 7)]);
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


// ---- 801dc2dc FUN_801dc2dc

void FUN_801dc2dc(char *param_1)

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
            (&UNK_8015b175)[iVar5] = 2;
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


// ---- 801dc3f0 FUN_801dc3f0

void FUN_801dc3f0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80109490();
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 1) = 2;
    *(undefined1 *)(param_1 + 0x50) = 2;
  }
  return;
}


// ---- 801dc428 FUN_801dc428

void FUN_801dc428(int param_1)

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
    *(undefined4 *)(param_1 + 0x14) = 0xfffe0000;
    *(undefined4 *)(param_1 + 0x1c) = 0xffff8000;
    iVar2 = FUN_8012c108(param_1,param_1 + 0x50,0x18,0xe,0,0);
    if (iVar2 != 0) {
      *(undefined1 *)(iVar2 + 0x25) = 0;
      goto LAB_801dc4dc;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x20000;
    *(undefined4 *)(param_1 + 0x1c) = 0x8000;
    iVar2 = FUN_8012c108(param_1,param_1 + 0x50,0xffffffec,0xe,0,0);
    if (iVar2 != 0) {
                    /* Possible PsyQ macro: setLineF2() */
      *(undefined1 *)(iVar2 + 0x25) = 0x40;
LAB_801dc4dc:
      if (iVar2 != 0) {
        uVar5 = *(undefined2 *)(iVar2 + 0xe);
        sVar4 = *(short *)(iVar2 + 0x12);
                    /* Probable PsyQ macro: setTile16() */
        *(undefined1 *)(iVar2 + 7) = 0x70;
        *(undefined1 *)(iVar2 + 0x27) = 0x1b;
        *(undefined1 *)(iVar2 + 0x26) = 6;
        goto LAB_801dc50c;
      }
    }
  }
  uVar5 = 0;
  sVar4 = 0;
LAB_801dc50c:
  *(undefined1 *)(param_1 + 0x52) = 0;
  puVar3 = (undefined1 *)Obj_AllocType3();
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 1;
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
  FUN_801dc898(param_1,3);
  return;
}


// ---- 801dc5cc FUN_801dc5cc

void FUN_801dc5cc(int param_1)

{
  if ((*(byte *)(param_1 + 7) < 3) && ((*(byte *)(param_1 + 0x33) & 0x30) != 0)) {
    *(undefined1 *)(param_1 + 1) = 2;
    *(undefined1 *)(param_1 + 0x50) = 2;
  }
  return;
}


// ---- 801dc604 FUN_801dc604

void FUN_801dc604(int param_1)

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


// ---- 801dc680 FUN_801dc680

void FUN_801dc680(int param_1)

{
  if (*(int *)(param_1 + 0x14) < 0x58000) {
    if (-0x58000 < *(int *)(param_1 + 0x14)) goto LAB_801dc6c0;
    *(undefined4 *)(param_1 + 0x14) = 0xfffa8000;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x58000;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
LAB_801dc6c0:
  if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x18) < -0x4ffff)) {
    *(undefined4 *)(param_1 + 0x18) = 0xfffb0000;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


// ---- 801dc6f4 FUN_801dc6f4

void FUN_801dc6f4(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  
  bVar1 = (&DAT_801e68c4)[*(byte *)(param_1 + 7)];
  if (bVar1 == 1) {
    puVar3 = (undefined1 *)Obj_AllocType2();
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 0;
      puVar3[7] = (&DAT_801e68c4)[*(byte *)(param_1 + 7)];
      *(short *)(puVar3 + 0xe) = *(short *)(param_1 + 0xe) + 4;
      *(undefined2 *)(puVar3 + 0x12) = *(undefined2 *)(param_1 + 0x12);
    }
  }
  else if ((((1 < bVar1) && (bVar1 != 4)) && (bVar1 == 5)) &&
          (puVar3 = (undefined1 *)FUN_801055e4(), puVar3 != (undefined1 *)0x0)) {
    *puVar3 = 1;
    uVar2 = (&DAT_801e68c4)[*(byte *)(param_1 + 7)];
    puVar3[7] = 0;
    puVar3[6] = uVar2;
    *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    *(short *)(puVar3 + 0x12) = *(short *)(param_1 + 0x12) + -3;
  }
  return;
}


// ---- 801dc7f0 FUN_801dc7f0

void FUN_801dc7f0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if ((iVar1 != 0) && ((*(byte *)(param_1 + 0x33) & 0x80) != 0)) {
    iVar2 = (int)*(short *)(param_1 + 0xe) + (uint)(iVar1 < 1) * 4;
    if ((iVar2 == (iVar2 / 3) * 3) && (iVar2 = FUN_8012c8ec(param_1,0,0xe), iVar2 != 0)) {
      *(ushort *)(iVar2 + 0xe) = (ushort)(iVar1 < 1) * 4 + *(short *)(iVar2 + 0xe);
    }
  }
  return;
}


// ---- 801dc898 FUN_801dc898

void FUN_801dc898(int param_1,char param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_801093fc(param_1 + 0x54);
  if (((*(char *)(param_1 + 0x58) != '\0') && (*pcVar1 != '\0')) && (pcVar1[6] == '\x0e')) {
    pcVar1[0x52] = param_2;
  }
  return;
}


// ---- 801dc904 FUN_801dc904

void FUN_801dc904(int param_1,char param_2)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 0x4c);
  if (((*(char *)(param_1 + 0x58) != '\0') && (*pcVar1 != '\0')) && (pcVar1[6] == '\v')) {
    pcVar1[0x54] = param_2;
  }
  return;
}


// ---- 801dc940 FUN_801dc940

bool FUN_801dc940(int param_1)

{
  return ((&DAT_80139548)[(byte)(&DAT_801e68e0)[*(byte *)(param_1 + 0x5c)] & 7] &
         *(byte *)((int)&DAT_8016d2f8 + ((byte)(&DAT_801e68e0)[*(byte *)(param_1 + 0x5c)] >> 3) + 3)
         ) != 0;
}


