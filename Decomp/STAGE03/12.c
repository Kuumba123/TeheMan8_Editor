// ID 12, STAGE03.BIN, handler 0x801DB864. Ghidra output with the object struct applied; not matching C.
// ---- 801db864 FUN_801db864

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db864(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e9b04)[obj->state])();
  Obj_CullAndQueueDrawMargin(obj,0x40);
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801db8d0 FUN_801db8d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db8d0(MM8Obj *obj)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  
  Enemy_InitFromTable();
  obj->state = 1;
  obj->draw_list = 6;
  obj->hp = 0x10;
  obj->flip = 0;
  obj->invuln = 0;
  obj->contact_dmg = 0;
  obj->dmg_table = 2;
  if (obj->var < 2) {
    obj->hitbox = &DAT_801e9aec;
  }
  else {
    obj->hitbox = &DAT_801e9af0;
  }
  bVar2 = obj->var;
  bVar3 = obj->var & 0xf;
  obj->var = bVar3;
  obj->field_0x53 = bVar2 >> 6;
  obj->sub2 = bVar3;
  obj->field_0x54 = (&DAT_801e9af4)[(uint)obj->var * 2];
  uVar1 = (&DAT_801e9af5)[(uint)obj->var * 2];
  obj->field_0x50 = 1;
  obj->field_0x52 = 0x78;
  obj->field_0x56 = 0;
  obj->field_0x55 = uVar1;
                    /* Possible PsyQ macro: setTile8() */
  switch(obj->var) {
  case 0:
  case 1:
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x52 = 0x78;
    uVar4 = 0xd;
    goto LAB_801db9ec;
  case 2:
    goto switchD_801db9b8_caseD_2;
  case 3:
  case 4:
    bVar2 = 3;
    break;
  case 5:
    bVar2 = 4;
    break;
  default:
    goto switchD_801db9b8_default;
  }
  obj->sub2 = bVar2;
switchD_801db9b8_caseD_2:
  uVar4 = 0x13;
LAB_801db9ec:
  Anim_Set(obj,uVar4);
switchD_801db9b8_default:
  return;
}


// ---- 801dba08 FUN_801dba08

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba08(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e9b10)[obj->sub2])();
  if (DAT_801b29a1 == '\0') {
    obj->field_0x56 = 1;
  }
  if ((obj->field_0x52 == '\0') &&
     ((iVar1 = Enemy_CheckWeaponHits(obj), iVar1 == 4 ||
      ((obj->field_0x56 != '\0' && (DAT_801b29a1 != '\0')))))) {
    obj->state = 2;
    obj->sub3 = 0;
    obj->sub2 = 1 < obj->var;
  }
  return;
}


// ---- 801dbad4 FUN_801dbad4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbad4(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub3 == 0) {
    FUN_801dbda0();
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x50 = 0x3c;
      FUN_801dc09c(obj,0xffe80000,0x80000);
      FUN_801dc09c(obj,0x180000,0x80000);
    }
  }
  return;
}


// ---- 801dbb58 FUN_801dbb58

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbb58(MM8Obj *obj)

{
  char cVar1;
  undefined4 uVar2;
  
  if (obj->sub3 == 0) {
    FUN_801dbda0();
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    uVar2 = 0x180000;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0x2d;
      if (obj->field_0x4 == '\0') {
        uVar2 = 0xffe80000;
      }
      FUN_801dc09c(obj,uVar2,0x80000);
      obj->field_0x4 = obj->field_0x4 ^ 1;
    }
  }
  return;
}


// ---- 801dbbe8 FUN_801dbbe8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbbe8(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub3 == 0) {
    FUN_801dbe18();
  }
  else if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x4 = 1;
      obj->field_0x51 = 5;
      obj->field_0x50 = 1;
    }
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0x14;
      cVar1 = obj->field_0x51 + -1;
      obj->field_0x51 = cVar1;
      if (cVar1 == '\0') {
        obj->field_0x4 = 0;
        obj->field_0x50 = 0xb4;
      }
      FUN_801dc09c(obj,0x120000,0x180000);
    }
  }
  return;
}


// ---- 801dbcac FUN_801dbcac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbcac(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  
  if (obj->sub3 == 0) {
    FUN_801dbe18();
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0xb4;
      uVar2 = 0;
      do {
        FUN_801dc09c(obj,0x20000,0x170000);
        uVar2 = uVar2 + 1;
      } while (uVar2 < 3);
    }
  }
  return;
}


// ---- 801dbd3c FUN_801dbd3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbd3c(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub3 == 0) {
    FUN_801dbe18();
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0xb4;
      FUN_801dc09c(obj,0x100000,0x120000);
    }
  }
  return;
}


// ---- 801dbda0 FUN_801dbda0

void FUN_801dbda0(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 4) == '\0') {
    cVar1 = *(char *)(param_1 + 0x52) + -1;
    *(char *)(param_1 + 0x52) = cVar1;
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 4) = 1;
      Anim_Set(param_1,9);
    }
  }
  else {
    if (*(short *)(param_1 + 0x2e) < 0) {
      *(undefined1 *)(param_1 + 3) = 1;
      *(undefined1 *)(param_1 + 4) = 0;
    }
    Anim_Step();
  }
  return;
}


// ---- 801dbe18 FUN_801dbe18

void FUN_801dbe18(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 4) == '\0') {
    cVar1 = *(char *)(param_1 + 0x52) + -1;
    *(char *)(param_1 + 0x52) = cVar1;
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 4) = 1;
      Anim_Set(param_1,0x14);
    }
  }
  else {
    if (*(short *)(param_1 + 0x2e) < 0) {
      Anim_Set(param_1,(&DAT_801e9b00)[*(byte *)(param_1 + 0x53)]);
      *(undefined1 *)(param_1 + 3) = 1;
      *(undefined1 *)(param_1 + 4) = 0;
    }
    Anim_Step(param_1);
  }
  return;
}


// ---- 801dbeb8 FUN_801dbeb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbeb8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9b24)[obj->sub2])();
  return;
}


// ---- 801dbef4 FUN_801dbef4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbef4(MM8Obj *obj)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = -0x20;
  if (obj->sub3 == 0) {
    do {
      uVar1 = Rand(obj);
      iVar3 = (uint)(ushort)obj->x + iVar4;
      uVar2 = Rand();
      iVar4 = iVar4 + 0x18;
      FUN_801dc124((int)((iVar3 + -3 + (uVar1 & 7)) * 0x10000) >> 0x10,
                   (int)(((uint)(ushort)obj->y + ((uVar2 & 7) - 0x13)) * 0x10000) >> 0x10);
    } while (iVar4 < 0x30);
    Anim_Set(obj,0xb);
    obj->sub3 = 1;
    obj->draw_list = 7;
    obj->invuln = 1;
  }
  return;
}


// ---- 801dbfac FUN_801dbfac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbfac(MM8Obj *obj)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0x10;
  if (obj->sub3 == 0) {
    do {
      iVar5 = -0x10;
      do {
        uVar1 = Rand();
        iVar4 = (uint)(ushort)obj->x + iVar5;
        uVar2 = Rand();
        iVar5 = iVar5 + 0x18;
        FUN_801dc124((int)((iVar4 + -3 + (uVar1 & 7)) * 0x10000) >> 0x10,
                     (int)(((uint)(ushort)obj->y + iVar6 + -3 + (uVar2 & 7)) * 0x10000) >> 0x10);
      } while (iVar5 < 0x10);
      iVar6 = iVar6 + 0x18;
    } while (iVar6 < 0x30);
    uVar3 = 0x1a;
    if ((byte)obj->field_0x53 < 3) {
      uVar3 = 0x17;
    }
    Anim_Set(obj,uVar3);
    obj->sub3 = 1;
    obj->draw_list = 7;
    obj->invuln = 1;
  }
  return;
}


// ---- 801dc09c FUN_801dc09c

void FUN_801dc09c(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = *(undefined1 *)(param_1 + 0x54);
    puVar1[7] = *(undefined1 *)(param_1 + 0x55);
    *(int *)(puVar1 + 0xc) = param_2 + *(int *)(param_1 + 0xc);
    *(int *)(puVar1 + 0x10) = param_3 + *(int *)(param_1 + 0x10);
  }
  return;
}


// ---- 801dc124 FUN_801dc124

void FUN_801dc124(undefined2 param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocType3();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0;
    *(undefined2 *)(puVar1 + 0xe) = param_1;
    *(undefined2 *)(puVar1 + 0x12) = param_2;
  }
  return;
}


