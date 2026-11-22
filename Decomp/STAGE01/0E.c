// ID 0E, STAGE01.BIN, handler 0x801DD760. Ghidra output with the object struct applied; not matching C.
// ---- 801dd760 FUN_801dd760

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd760(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  obj->invuln = 0;
  if ((obj->state == 0) || (iVar2 = FUN_801de280(), iVar2 != 0)) {
    obj->field_0x56 = 0;
    bVar1 = DAT_80159f86;
    obj->field_0x53 = 0;
    obj->field_0x54 = 0;
    obj->field_0x58 = 5;
    obj->clut = bVar1;
    (*(code *)(&PTR_FUN_801e69d0)[obj->state])(obj);
    if (obj->active != 0) {
      FUN_801de054(obj);
      if (obj->state < 5) {
        FUN_801ddea8(obj);
        FUN_801de0b8(obj,5);
      }
      else {
        FUN_801ddf48(obj);
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


// ---- 801dd898 FUN_801dd898

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd898(MM8Obj *obj)

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
  FUN_801dde50(obj,4);
  iVar1 = FUN_801dde50(obj,3);
  if (iVar1 != 0) {
    *(undefined1 **)(iVar1 + 0x14) = &obj->field_0x54;
  }
  iVar1 = FUN_801dde50(obj,5);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x26) = 8;
  }
  (*(code *)(&PTR_FUN_801e69d0)[obj->state])(obj);
  return;
}


// ---- 801dd994 FUN_801dd994

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd994(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    iVar1 = FUN_801dde20(obj);
    if (iVar1 != 0) {
      obj->state = 2;
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801dd9fc FUN_801dd9fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd9fc(MM8Obj *obj)

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


// ---- 801dda84 FUN_801dda84

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dda84(MM8Obj *obj)

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
      obj->field_0x50 = (&UNK_801e6a04)[((byte)obj->field_0x51 & 3) + (obj->var >> 3 & 4)];
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
      puVar4[7] = (&UNK_801e69fc)[((byte)obj->field_0x51 & 3) + (obj->var >> 3 & 4)] | 0x10;
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


// ---- 801ddbf0 FUN_801ddbf0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddbf0(MM8Obj *obj)

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


// ---- 801ddc70 FUN_801ddc70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddc70(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  
  cVar1 = DAT_801e69cc;
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
      FUN_80108ed8(obj,(int)(char)(&DAT_801e6a1c)[iVar4 >> 0x17],
                   (int)(char)(&DAT_801e6a1d)[iVar4 >> 0x17]);
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
      FUN_80108ed8(obj,(int)(char)(&DAT_801e6a1c)[iVar4],(int)(char)(&DAT_801e6a1d)[iVar4]);
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


// ---- 801dde20 FUN_801dde20

bool FUN_801dde20(int param_1)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_1 + 0x50) != '\0';
  if (bVar1) {
    *(char *)(param_1 + 0x50) = *(char *)(param_1 + 0x50) + -1;
  }
  return !bVar1;
}


// ---- 801dde50 FUN_801dde50

int FUN_801dde50(int param_1,undefined1 param_2)

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


// ---- 801ddea8 FUN_801ddea8

void FUN_801ddea8(int param_1)

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


// ---- 801ddf48 FUN_801ddf48

void FUN_801ddf48(int param_1)

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
      iVar3 = (int)(char)(&DAT_801e6a10)[iVar2];
      if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
        iVar3 = -iVar3;
      }
      iVar3 = FUN_801091a4((int)((iVar3 + (uint)*(ushort *)(param_1 + 0xe)) * 0x10000) >> 0x10,
                           (int)(((int)(char)(&DAT_801e6a11)[iVar2] +
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


// ---- 801de054 FUN_801de054

void FUN_801de054(int param_1)

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


// ---- 801de0b8 FUN_801de0b8

void FUN_801de0b8(int param_1,undefined1 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  *(undefined **)(param_1 + 0x3c) = &DAT_801e6a0c;
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
                    /* Possible PsyQ macro: setLineF2() */
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


// ---- 801de280 FUN_801de280

bool FUN_801de280(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (*(byte *)(param_1 + 7) & 0xf) * 4;
  iVar3 = (int)(((uint)DAT_8015e248._2_2_ - (uint)*(ushort *)(param_1 + 0xe)) * 0x10000) >> 0x10;
  bVar1 = false;
  if (iVar3 <= *(short *)(&DAT_801e69ea + iVar2)) {
    bVar1 = *(short *)(&DAT_801e69e8 + iVar2) <= iVar3;
  }
  return bVar1;
}


