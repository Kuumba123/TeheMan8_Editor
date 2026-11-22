// ID 13, STAGE0C.BIN, handler 0x801DA2A0. Ghidra output with the object struct applied; not matching C.
// ---- 801da2a0 FUN_801da2a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da2a0(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  if (obj->state == 0) {
    FUN_801da2f4();
  }
  else {
    FUN_801da4e0(obj);
  }
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801da2f4 FUN_801da2f4

void FUN_801da2f4(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
                    /* Possible PsyQ macro: setLineF2() */
  Enemy_InitFromTable();
  *(undefined1 *)(param_1 + 0x26) = 7;
  *(undefined4 *)(param_1 + 0x20) = 0xfffffc00;
  *(undefined **)(param_1 + 0x3c) = &DAT_801eaa30;
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)(param_1 + 0x25) = 0;
  *(undefined **)(param_1 + 0x38) = &DAT_801eaa28;
  *(undefined1 *)(param_1 + 0x43) = 1;
  cVar1 = Rand();
  *(byte *)(param_1 + 0x51) = cVar1 + 0x5aU & 0xf;
  Anim_Set(param_1,0);
  bVar4 = *(byte *)(param_1 + 7) & 0xf;
  if (bVar4 < 4) {
    *(undefined1 *)(param_1 + 0x58) = 1;
    *(undefined1 *)(param_1 + 0x52) = 0;
  }
  switch(bVar4) {
  case 0:
    *(undefined1 *)(param_1 + 2) = 0;
    break;
  case 1:
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined4 *)(param_1 + 0x1c) = 0xffffe600;
    *(undefined4 *)(param_1 + 0x14) = 0x14300;
    *(undefined1 *)(param_1 + 0x50) = 0x38;
    break;
  case 2:
    uVar5 = 0;
    *(undefined1 *)(param_1 + 2) = 0;
    iVar3 = param_1;
    if (*(byte *)(param_1 + 7) >> 4 != 0) {
      do {
        iVar2 = FUN_801da84c(param_1,iVar3,0x18,0);
        uVar5 = uVar5 + 1;
        if (iVar2 == 0) break;
        *(char *)(iVar2 + 0x50) = (char)uVar5 * '\b';
        iVar3 = iVar2;
      } while (uVar5 < *(byte *)(param_1 + 7) >> 4);
    }
    if ((iVar3 != param_1) && (iVar3 != 0)) {
      *(undefined1 *)(iVar3 + 0x58) = 1;
    }
    break;
  case 3:
    uVar5 = 0;
    *(undefined1 *)(param_1 + 2) = 0;
    iVar3 = param_1;
    if (*(byte *)(param_1 + 7) >> 4 != 0) {
      do {
        iVar3 = FUN_801da84c(param_1,iVar3,0,0x18);
        if (iVar3 == 0) {
          return;
        }
        *(undefined1 *)(iVar3 + 0x50) = 1;
                    /* Possible PsyQ macro: setPolyF3() */
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(byte *)(param_1 + 7) >> 4);
    }
    break;
  case 4:
  case 5:
    *(undefined1 *)(param_1 + 2) = 2;
    if (*(char *)(param_1 + 0x58) == '\0') {
      Anim_Set(param_1,2);
    }
  }
  return;
}


// ---- 801da4e0 FUN_801da4e0

void FUN_801da4e0(int param_1)

{
  (*(code *)(&PTR_FUN_801eaa34)[*(byte *)(param_1 + 2)])();
  Enemy_ContactDamage(param_1);
  return;
}


// ---- 801da530 FUN_801da530

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da530(MM8Obj *obj)

{
  int iVar1;
  
  if (0xa400 < obj->speed_y_up + 0x5200U) {
    iVar1 = -0x5200;
    if (0 < obj->speed_y_up) {
      iVar1 = 0x5200;
    }
    obj->speed_y_up = iVar1;
    obj->gravity = -obj->gravity;
  }
  FUN_80104ccc(obj);
  FUN_801da748(obj);
  return;
}


// ---- 801da598 FUN_801da598

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da598(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (0xa400 < obj->speed_y_up + 0x5200U) {
    iVar2 = -0x5200;
    if (0 < obj->speed_y_up) {
      iVar2 = 0x5200;
    }
    obj->speed_y_up = iVar2;
    obj->gravity = -obj->gravity;
  }
  if (obj->sub3 == 0) {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->sub3 = 1;
    }
    FUN_80104ccc(obj);
  }
  else if (obj->speed_x + 0x14300U < 0x28601) {
    Obj_ApplySpeed(obj);
  }
  else {
    iVar2 = -0x14300;
    if (0 < obj->speed_x) {
      iVar2 = 0x14300;
    }
    obj->speed_x = iVar2;
    obj->sub3 = 0;
    obj->field_0x50 = 0x70;
    obj->accel_x = -obj->accel_x;
    FUN_80104ccc(obj);
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x30) != 0) {
                    /* Possible PsyQ macro: setTile16() */
    obj->field_0x50 = 0x70;
    obj->speed_x = -0x14300;
    obj->sub3 = 0;
    obj->accel_x = -0x1a00;
    if ((obj->field_0x33 & 0x20) != 0) {
      obj->speed_x = -obj->speed_x;
      obj->accel_x = -obj->accel_x;
    }
  }
  FUN_801da748(obj);
  return;
}


// ---- 801da6f8 FUN_801da6f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da6f8(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub3 == 0) {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 != '\0') {
      return;
    }
    obj->sub3 = 1;
  }
  FUN_801da530(obj);
  return;
}


// ---- 801da748 FUN_801da748

void FUN_801da748(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  Anim_Step();
  bVar1 = *(byte *)(param_1 + 4);
  if (bVar1 == 1) {
    if (-1 < *(short *)(param_1 + 0x2e)) {
      return;
    }
    iVar3 = 3;
    if (*(char *)(param_1 + 0x31) != '\x01') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 2;
    if (*(char *)(param_1 + 0x58) != '\0') {
      iVar3 = 1;
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      cVar2 = *(char *)(param_1 + 0x51) + -1;
      *(char *)(param_1 + 0x51) = cVar2;
      if (cVar2 != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 4) = 1;
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
      *(undefined1 *)(param_1 + 0x51) = 0x5a;
      return;
    }
    if (bVar1 != 2) {
      return;
    }
    if (-1 < *(short *)(param_1 + 0x2e)) {
      return;
    }
    if (*(char *)(param_1 + 0x31) != '\x01') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 0;
    iVar3 = (uint)(*(char *)(param_1 + 0x58) == '\0') << 1;
  }
  Anim_Set(param_1,iVar3);
  return;
}


// ---- 801da84c FUN_801da84c

undefined1 * FUN_801da84c(int param_1,int param_2,short param_3,short param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)FUN_801055e4(param_2);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x13;
    uVar1 = 4;
    if (param_3 == 0) {
      uVar1 = 5;
    }
    puVar2[7] = uVar1;
    *(short *)(puVar2 + 0xe) = param_3 + *(short *)(param_2 + 0xe);
    *(short *)(puVar2 + 0x12) = param_4 + *(short *)(param_2 + 0x12);
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    puVar2[0x58] = 0;
    puVar2[0x25] = uVar1;
  }
  return puVar2;
}


