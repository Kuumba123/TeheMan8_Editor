// ID 0E, STAGE03.BIN, handler 0x801D9F14. Ghidra output with the object struct applied; not matching C.
// ---- 801d9f14 FUN_801d9f14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9f14(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  obj->invuln = 0;
  if ((obj->state == 0) || (iVar2 = FUN_801daa34(), iVar2 != 0)) {
    obj->field_0x56 = 0;
    bVar1 = DAT_80159f86;
    obj->field_0x53 = 0;
    obj->field_0x54 = 0;
    obj->field_0x58 = 5;
    obj->clut = bVar1;
    (*(code *)(&PTR_FUN_801e9a3c)[obj->state])(obj);
    if (obj->active != 0) {
      FUN_801da808(obj);
      if (obj->state < 5) {
        FUN_801da65c(obj);
        FUN_801da86c(obj,5);
      }
      else {
        FUN_801da6fc(obj);
      }
      if ((obj->field_0x56 == '\0') && (Obj_CullAndQueueDrawMargin(obj,0x50), obj->on_screen == 0))
      {
        obj->invuln = 1;
      }
      iVar2 = Obj_InActiveArea(obj);
      if ((iVar2 == 0) && ((obj->var & 0x10) == 0)) {
        obj->field_0x53 = 2;
        obj->field_0x54 = 2;
        obj->field_0x58 = 2;
        Obj_FreeDespawn();
      }
    }
  }
  return;
}


// ---- 801da04c FUN_801da04c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da04c(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  obj->state = 1;
  obj->draw_list = 7;
  obj->speed_y_up = -0x2f00;
  obj->gravity = 0x100;
  obj->sub2 = 0;
  obj->hitbox = (byte *)0x0;
  obj->box2 = (byte *)0x0;
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->field_0x50 = 0;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  obj->field_0x54 = 0;
  obj->field_0x58 = 2;
  obj->field_0x55 = 0;
  obj->field_0x56 = 0;
  obj->field_0x57 = 0;
  obj->flip = (obj->var >> 7) << 6;
  FUN_801da604(obj,4);
  iVar1 = FUN_801da604(obj,3);
  if (iVar1 != 0) {
    *(undefined1 **)(iVar1 + 0x14) = &obj->field_0x54;
  }
  iVar1 = FUN_801da604(obj,5);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x26) = 8;
  }
  (*(code *)(&PTR_FUN_801e9a3c)[obj->state])(obj);
  return;
}


// ---- 801da148 FUN_801da148

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da148(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    iVar1 = FUN_801da5d4(obj);
    if (iVar1 != 0) {
      obj->state = 2;
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801da1b0 default

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801da0dc::default(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    Anim_Set(obj,1);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      obj->sub2 = 0;
      obj->state = obj->state + 1;
    }
  }
  return;
}


// ---- 801da238 FUN_801da238

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da238(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  undefined1 *puVar4;
  
  bVar1 = obj->sub2;
  if (bVar1 != 0) {
    if (bVar1 != 1) {
      if (bVar1 != 2) {
        return;
      }
      cVar3 = obj->field_0x50 + -1;
      obj->field_0x50 = cVar3;
      if (cVar3 != '\0') {
        return;
      }
      obj->state = 4;
      obj->sub2 = 0;
      obj->field_0x50 = (&UNK_801e9a70)[((byte)obj->field_0x51 & 3) + (obj->var >> 3 & 4)];
      return;
    }
    cVar3 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar3;
    if (cVar3 != '\0') {
      return;
    }
    puVar4 = (undefined1 *)FUN_801055e4();
    if (puVar4 != (undefined1 *)0x0) {
      *puVar4 = 1;
      puVar4[6] = 0xc;
      puVar4[7] = (&UNK_801e9a68)[((byte)obj->field_0x51 & 3) + (obj->var >> 3 & 4)] | 0x10;
      *(short *)(puVar4 + 0xe) = obj->x + -2;
      sVar2 = obj->y;
      puVar4[1] = 0;
      *(short *)(puVar4 + 0x12) = sVar2 + 0xc;
      *(undefined4 *)(puVar4 + 0x4c) = *(undefined4 *)&obj->field_0x4c;
      FUN_801093d4(obj,puVar4 + 0x54);
      obj->field_0x52 = 1;
      obj->field_0x51 = obj->field_0x51 + '\x01';
    }
  }
  obj->field_0x50 = 0x14;
  obj->sub2 = obj->sub2 + 1;
  return;
}


// ---- 801da3a4 FUN_801da3a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da3a4(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    Anim_Set(obj,2);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      obj->state = 1;
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801da424 FUN_801da424

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da424(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  
  cVar1 = DAT_801e9a38;
  if (obj->sub2 == 0) {
    obj->field_0x57 = 6;
    obj->field_0x50 = cVar1 + '\x01';
    obj->sub2 = obj->sub2 + 1;
  }
  bVar5 = obj->field_0x50 - 1;
  uVar3 = (uint)bVar5;
  obj->field_0x50 = bVar5;
  if (uVar3 == 0) {
    uVar3 = 7;
    iVar4 = 0x7000000;
    do {
      FUN_80108ed8(obj,(int)(char)(&DAT_801e9a88)[iVar4 >> 0x17],
                   (int)(char)(&DAT_801e9a89)[iVar4 >> 0x17]);
      if ((uVar3 & 3) != 0) {
        FUN_8010544c(obj,9);
      }
      uVar3 = uVar3 - 1;
      iVar4 = uVar3 * 0x1000000;
    } while (-1 < (int)(uVar3 * 0x1000000));
    obj->field_0x56 = 1;
    obj->field_0x53 = 2;
    obj->field_0x54 = 2;
    obj->field_0x58 = 2;
    FUN_80108fd8(obj,1);
    Obj_Free(obj);
  }
  else {
    if (uVar3 % 6 == 1) {
      iVar4 = ((uVar3 / 6) % 6) * 2;
      FUN_80108ed8(obj,(int)(char)(&DAT_801e9a88)[iVar4],(int)(char)(&DAT_801e9a89)[iVar4]);
      FUN_8010544c(obj,9);
    }
    if ((bVar5 & 1) == 0) {
      obj->field_0x56 = 1;
      uVar2 = 5;
    }
    else {
      uVar2 = 4;
      obj->field_0x56 = 0;
    }
    obj->field_0x53 = uVar2;
    obj->field_0x54 = uVar2;
    obj->field_0x58 = uVar2;
  }
  return;
}


// ---- 801da5d4 FUN_801da5d4

bool FUN_801da5d4(int param_1)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_1 + 0x50) != '\0';
  if (bVar1) {
    *(char *)(param_1 + 0x50) = *(char *)(param_1 + 0x50) + -1;
  }
  return !bVar1;
}


// ---- 801da604 FUN_801da604

int FUN_801da604(int param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_8012c108(param_1,param_1 + 0x53,0,0,0,param_2);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 7) = 0xf0;
    *(undefined1 *)(iVar1 + 0x26) = 6;
    *(undefined2 *)(iVar1 + 0x3a) = 0x80;
  }
  return iVar1;
}


// ---- 801da65c FUN_801da65c

void FUN_801da65c(int param_1)

{
  int iVar1;
  short sVar2;
  
  if ((*(byte *)(param_1 + 0x57) & 7) == 0) {
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar2 = *(short *)(param_1 + 0xe) + 6;
    }
    else {
      sVar2 = *(short *)(param_1 + 0xe) + -6;
    }
    iVar1 = FUN_801091a4((int)sVar2,(int)((*(ushort *)(param_1 + 0x12) - 0x2c) * 0x10000) >> 0x10,1)
    ;
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0x26) = 6;
      *(undefined1 *)(iVar1 + 0x39) = 1;
    }
  }
  *(char *)(param_1 + 0x57) = *(char *)(param_1 + 0x57) + '\x01';
  return;
}


// ---- 801da6fc FUN_801da6fc

void FUN_801da6fc(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 4;
  do {
    uVar1 = (uint)*(byte *)(param_1 + 0x57) % 6;
    if (uVar1 == (int)(char)iVar4) {
      iVar2 = uVar1 * 2;
      iVar3 = (int)(char)(&DAT_801e9a7c)[iVar2];
      if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
        iVar3 = -iVar3;
      }
      iVar3 = FUN_801091a4((int)((iVar3 + (uint)*(ushort *)(param_1 + 0xe)) * 0x10000) >> 0x10,
                           (int)(((int)(char)(&DAT_801e9a7d)[iVar2] +
                                 (uint)*(ushort *)(param_1 + 0x12)) * 0x10000) >> 0x10,1);
      if (iVar3 != 0) {
        *(undefined1 *)(iVar3 + 0x26) = 6;
        *(undefined1 *)(iVar3 + 0x39) = 1;
      }
    }
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4 * 0x1000000);
  *(char *)(param_1 + 0x57) = *(char *)(param_1 + 0x57) + '\x01';
  return;
}


// ---- 801da808 FUN_801da808

void FUN_801da808(int param_1)

{
  if (*(char *)(param_1 + 0x55) == '\x02') {
    *(undefined4 *)(param_1 + 0x18) = 0xffff8000;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else if (0x5ffe < *(int *)(param_1 + 0x18) + 0x2fffU) {
    *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
  }
  FUN_80104ccc();
  return;
}


// ---- 801da86c FUN_801da86c

void FUN_801da86c(int param_1,undefined1 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  *(undefined **)(param_1 + 0x3c) = &DAT_801e9a78;
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 == '\x02') {
    *(undefined1 *)(param_1 + 0x24) = 0;
    *(undefined1 *)(param_1 + 0x53) = 3;
    if (*(char *)(param_1 + 0x55) != '\x02') {
      *(undefined1 *)(param_1 + 0x54) = 3;
    }
    *(undefined1 *)(param_1 + 0x58) = 3;
    if ((*(char *)(param_1 + 0x55) == '\0') && (*(byte *)(param_1 + 0x47) < 6)) {
      FUN_80108ed8(param_1,0xe,6);
      FUN_8010544c(param_1,8);
      FUN_8012ae08(param_1,0xf);
      *(undefined1 *)(param_1 + 0x54) = 2;
      *(undefined1 *)(param_1 + 0x55) = 1;
    }
  }
  if (cVar1 == '\x04') {
    if (*(int *)(param_1 + 0x14) != 0) {
      uVar2 = 0xffff0000;
      if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
        uVar2 = 0x10000;
      }
      *(undefined4 *)(param_1 + 0x14) = uVar2;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    *(undefined1 *)(param_1 + 1) = param_2;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 0x55) = 2;
  }
  Enemy_ContactDamage(param_1);
  return;
}


// ---- 801daa34 FUN_801daa34

bool FUN_801daa34(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (*(byte *)(param_1 + 7) & 0xf) * 4;
  iVar3 = (int)(((uint)DAT_8015e248._2_2_ - (uint)*(ushort *)(param_1 + 0xe)) * 0x10000) >> 0x10;
  bVar1 = false;
  if (iVar3 <= *(short *)(&DAT_801e9a56 + iVar2)) {
    bVar1 = *(short *)(&DAT_801e9a54 + iVar2) <= iVar3;
  }
  return bVar1;
}


