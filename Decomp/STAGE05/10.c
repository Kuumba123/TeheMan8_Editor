// ID 10, STAGE05.BIN, handler 0x801D85CC. Ghidra output with the object struct applied; not matching C.
// ---- 801d85cc FUN_801d85cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d85cc(MM8Obj *obj)

{
  int iVar1;
  
  obj->clut = DAT_80159f8e;
  (*(code *)(&PTR_FUN_801ea240)[obj->state])();
  if (obj->active != 0) {
    if (obj->field_0x51 == '\0') {
      FUN_801d8e3c(obj);
      Enemy_ContactDamage(obj);
    }
    if ((obj->active != 0) && ((obj->state != 7 || (obj->sub2 < 2)))) {
      Obj_CullAndQueueDraw(obj);
    }
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801d86a0 FUN_801d86a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d86a0(MM8Obj *obj)

{
  byte bVar1;
  
  Enemy_InitFromTable();
  obj->draw_list = 6;
  obj->box2 = &DAT_801ea264;
  obj->hitbox = &DAT_801ea260;
  bVar1 = obj->var;
  obj->sub2 = 0;
  obj->field_0x50 = 0;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  obj->var = obj->var & 0xbf;
  obj->flip = bVar1 & 0x40;
  if ((obj->var & 0xf) == 1) {
    obj->gravity = 0x4000;
    obj->field_0x43 = 1;
    bVar1 = 5;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
  }
  else {
    bVar1 = 1;
  }
  obj->state = bVar1;
  (*(code *)(&PTR_FUN_801ea240)[obj->state])(obj);
  return;
}


// ---- 801d8770 FUN_801d8770

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8770(MM8Obj *obj)

{
  ushort uVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    uVar1 = Rand();
    Anim_Set(obj,uVar1 < 0x2000);
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->field_0x43 = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 != 0) {
      obj->sub2 = 0;
    }
  }
  FUN_80106214(obj);
  iVar2 = FUN_801d8d70(obj);
  if (iVar2 == 0) {
    iVar2 = FUN_801d8c88(obj);
    if (iVar2 != 0) {
      obj->state = 2;
      obj->sub2 = 0;
    }
    FUN_801d8d9c(obj);
  }
  return;
}


// ---- 801d8834 FUN_801d8834

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8834(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = obj->sub2;
  if (bVar1 == 3) {
    Anim_Step();
    goto LAB_801d88f8;
  }
  if (bVar1 == 2) {
    Anim_Set(obj,3);
    bVar1 = obj->sub2 + 1;
  }
  else if (bVar1 == 1) {
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 == 0) goto LAB_801d88f8;
    bVar1 = obj->sub2 + 1;
  }
  else {
    if (bVar1 != 0) goto LAB_801d88f8;
    Anim_Set(obj,2);
    iVar2 = -0xc000;
    if ((obj->flip & 0x40) != 0) {
      iVar2 = 0xc000;
    }
    obj->speed_x = iVar2;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    bVar1 = obj->sub2 + 1;
  }
  obj->sub2 = bVar1;
LAB_801d88f8:
  FUN_80104c34(obj);
  FUN_801d8e18(obj);
  FUN_80106214(obj);
  iVar2 = FUN_801d8d70(obj);
  if (iVar2 == 0) {
    FUN_801d8d9c(obj);
  }
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->flip = obj->flip ^ 0x40;
    obj->speed_x = -obj->speed_x;
  }
  iVar2 = FUN_801d8d10(obj);
  if (iVar2 != 0) {
    obj->state = 3;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801d8980 FUN_801d8980

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8980(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,4);
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->field_0x43 = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      obj->state = 1;
      obj->sub2 = 0;
    }
  }
  FUN_80106214(obj);
  FUN_801d8d70(obj);
  return;
}


// ---- 801d8a10 FUN_801d8a10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8a10(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,5);
    obj->gravity = 0x4000;
    obj->field_0x43 = 1;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->sub2 = 2;
  }
  else if (obj->sub2 == 1) {
    Anim_Set(obj,5);
    iVar1 = -0x10000;
    if ((obj->flip & 0x40) != 0) {
      iVar1 = 0x10000;
    }
    obj->speed_y_up = 0x38000;
    obj->gravity = 0x4000;
    obj->field_0x43 = 1;
    obj->speed_x = iVar1;
    obj->accel_x = 0;
    obj->sub2 = 2;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      obj->state = 5;
      obj->sub2 = 0;
    }
  }
  FUN_80106214(obj);
  return;
}


// ---- 801d8af4 FUN_801d8af4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8af4(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
                    /* Possible PsyQ macro: setPolyF4() */
    Anim_Set(obj,6);
    obj->field_0x43 = 1;
    obj->sub2 = 2;
  }
  else {
    Anim_Step(obj);
  }
  FUN_80104ccc(obj);
  FUN_801d8e18(obj);
  FUN_80106214(obj);
  iVar1 = FUN_801d8d64(obj);
  if (iVar1 != 0) {
    obj->state = 6;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801d8b7c FUN_801d8b7c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8b7c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,7);
    obj->field_0x43 = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      obj->field_0x50 = 0x1e;
      obj->state = 1;
      obj->sub2 = 0;
    }
  }
  FUN_80106214(obj);
  return;
}


// ---- 801d8bfc FUN_801d8bfc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8bfc(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    FUN_8012a5fc(obj,0);
    Anim_Set(obj,8);
  }
  else {
    if (obj->sub2 != 1) {
      FUN_801d8ec0(obj);
      return;
    }
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 == 0) {
      return;
    }
  }
  obj->sub2 = obj->sub2 + 1;
  return;
}


// ---- 801d8c88 FUN_801d8c88

undefined4 FUN_801d8c88(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = Obj_InActiveArea();
  if ((((iVar2 == 0) || (uVar3 = 1, (DAT_801b2960 & 8) == 0)) &&
      (uVar3 = 0, *(char *)(param_1 + 0x51) == '\0')) &&
     (uVar3 = 1, *(char *)(param_1 + 0x50) != '\0')) {
    cVar1 = *(char *)(param_1 + 0x50) + -1;
    *(char *)(param_1 + 0x50) = cVar1;
    uVar3 = 0;
    if (cVar1 == '\0') {
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ---- 801d8d10 FUN_801d8d10

bool FUN_801d8d10(int param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = Obj_InActiveArea();
  if ((iVar2 == 0) || (bVar1 = true, (DAT_801b2960 & 8) == 0)) {
    bVar1 = *(char *)(param_1 + 0x51) != '\0';
  }
  return bVar1;
}


// ---- 801d8d64 FUN_801d8d64

byte FUN_801d8d64(int param_1)

{
  return *(byte *)(param_1 + 0x33) >> 7;
}


// ---- 801d8d70 FUN_801d8d70

bool FUN_801d8d70(int param_1)

{
  bool bVar1;
  
  bVar1 = (*(byte *)(param_1 + 0x33) & 0x80) == 0;
  if (bVar1) {
    *(undefined1 *)(param_1 + 1) = 4;
    *(undefined1 *)(param_1 + 2) = 0;
  }
  return bVar1;
}


// ---- 801d8d9c FUN_801d8d9c

bool FUN_801d8d9c(int param_1)

{
  int iVar1;
  short sVar2;
  
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    sVar2 = *(short *)(param_1 + 0xe) + -10;
  }
  else {
    sVar2 = *(short *)(param_1 + 0xe) + 10;
  }
  iVar1 = FUN_80107204((int)sVar2,(int)((*(ushort *)(param_1 + 0x12) + 0xc) * 0x10000) >> 0x10);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 1) = 4;
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return iVar1 == 0;
}


// ---- 801d8e18 FUN_801d8e18

void FUN_801d8e18(int param_1)

{
  if (*(int *)(param_1 + 0x18) < -0x60000) {
    *(undefined4 *)(param_1 + 0x18) = 0xfffa0000;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


// ---- 801d8e3c FUN_801d8e3c

void FUN_801d8e3c(int param_1)

{
  char cVar1;
  
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 != '\0') {
    if (DAT_80158f5c == '\x0e') {
      *(undefined1 *)(param_1 + 0x51) = 0x1e;
      *(undefined1 *)(param_1 + 1) = 7;
      *(undefined1 *)(param_1 + 2) = 0;
    }
    if (cVar1 == '\x04') {
      FUN_801d8ff8(param_1);
      FUN_80105888(param_1);
    }
    else {
      *(undefined1 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// ---- 801d8ec0 FUN_801d8ec0

void FUN_801d8ec0(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(byte *)(param_1 + 0x51) != 0) {
    if ((uint)*(byte *)(param_1 + 0x51) % 0xc == 0) {
      iVar5 = 0;
      iVar4 = 0;
      do {
        if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
          sVar1 = *(short *)((int)&DAT_801ea234 + iVar4);
        }
        else {
          sVar1 = -*(short *)((int)&DAT_801ea234 + iVar4);
        }
        iVar3 = FUN_801091a4((int)(short)(*(short *)(param_1 + 0xe) + sVar1),
                             (int)(((uint)*(ushort *)(param_1 + 0x12) +
                                   (uint)*(ushort *)((int)&DAT_801ea236 + iVar4)) * 0x10000) >> 0x10
                             ,1);
        iVar4 = iVar4 + 4;
        if (iVar3 != 0) {
          *(undefined1 *)(iVar3 + 0x26) = 6;
        }
        iVar5 = iVar5 + 1;
                    /* Possible PsyQ macro: setLineF2() */
      } while (iVar5 < 3);
    }
    cVar2 = *(char *)(param_1 + 0x51) + -1;
    *(char *)(param_1 + 0x51) = cVar2;
    if (cVar2 == '\x01') {
      FUN_80108fd8(param_1,4);
      Obj_FreeDespawn(param_1);
    }
  }
  return;
}


// ---- 801d8ff8 FUN_801d8ff8

void FUN_801d8ff8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_8012c108(param_1,param_1 + 0x52,0,0,0,8);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 7) = 0;
  }
  FUN_80108e84(param_1);
  FUN_80108fd8(param_1,4);
  FUN_8012a5fc(param_1,0);
  return;
}


