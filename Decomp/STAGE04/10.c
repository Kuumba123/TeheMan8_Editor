// ID 10, STAGE04.BIN, handler 0x801DA568. Ghidra output with the object struct applied; not matching C.
// ---- 801da568 FUN_801da568

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da568(MM8Obj *obj)

{
  int iVar1;
  
  obj->clut = DAT_80159f8e;
  (*(code *)(&PTR_FUN_801e6d80)[obj->state])();
  if (obj->active != 0) {
    if (obj->field_0x51 == '\0') {
      FUN_801dadd8(obj);
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


// ---- 801da63c FUN_801da63c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da63c(MM8Obj *obj)

{
  byte bVar1;
  
  Enemy_InitFromTable();
  obj->draw_list = 6;
  obj->box2 = &DAT_801e6da4;
  obj->hitbox = &DAT_801e6da0;
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
  (*(code *)(&PTR_FUN_801e6d80)[obj->state])(obj);
  return;
}


// ---- 801da70c FUN_801da70c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da70c(MM8Obj *obj)

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
  iVar2 = FUN_801dad0c(obj);
  if (iVar2 == 0) {
    iVar2 = FUN_801dac24(obj);
    if (iVar2 != 0) {
      obj->state = 2;
      obj->sub2 = 0;
    }
    FUN_801dad38(obj);
  }
  return;
}


// ---- 801da7d0 FUN_801da7d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da7d0(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = obj->sub2;
  if (bVar1 == 3) {
    Anim_Step();
    goto LAB_801da894;
  }
  if (bVar1 == 2) {
    Anim_Set(obj,3);
    bVar1 = obj->sub2 + 1;
  }
  else if (bVar1 == 1) {
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 == 0) goto LAB_801da894;
    bVar1 = obj->sub2 + 1;
  }
  else {
    if (bVar1 != 0) goto LAB_801da894;
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
LAB_801da894:
  FUN_80104c34(obj);
  FUN_801dadb4(obj);
  FUN_80106214(obj);
  iVar2 = FUN_801dad0c(obj);
  if (iVar2 == 0) {
    FUN_801dad38(obj);
  }
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->flip = obj->flip ^ 0x40;
    obj->speed_x = -obj->speed_x;
  }
  iVar2 = FUN_801dacac(obj);
  if (iVar2 != 0) {
    obj->state = 3;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801da91c FUN_801da91c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da91c(MM8Obj *obj)

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
  FUN_801dad0c(obj);
  return;
}


// ---- 801da9ac FUN_801da9ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da9ac(MM8Obj *obj)

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


// ---- 801daa90 FUN_801daa90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daa90(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,6);
    obj->field_0x43 = 1;
    obj->sub2 = 2;
  }
  else {
    Anim_Step(obj);
  }
  FUN_80104ccc(obj);
  FUN_801dadb4(obj);
  FUN_80106214(obj);
  iVar1 = FUN_801dad00(obj);
  if (iVar1 != 0) {
    obj->state = 6;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801dab18 FUN_801dab18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dab18(MM8Obj *obj)

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


// ---- 801dab98 FUN_801dab98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dab98(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    FUN_8012a5fc(obj,0);
    Anim_Set(obj,8);
  }
  else {
    if (obj->sub2 != 1) {
      FUN_801dae5c(obj);
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


// ---- 801dac24 FUN_801dac24

undefined4 FUN_801dac24(int param_1)

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


// ---- 801dacac FUN_801dacac

bool FUN_801dacac(int param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = Obj_InActiveArea();
  if ((iVar2 == 0) || (bVar1 = true, (DAT_801b2960 & 8) == 0)) {
    bVar1 = *(char *)(param_1 + 0x51) != '\0';
  }
  return bVar1;
}


// ---- 801dad00 FUN_801dad00

byte FUN_801dad00(int param_1)

{
  return *(byte *)(param_1 + 0x33) >> 7;
}


// ---- 801dad0c FUN_801dad0c

bool FUN_801dad0c(int param_1)

{
  bool bVar1;
  
  bVar1 = (*(byte *)(param_1 + 0x33) & 0x80) == 0;
  if (bVar1) {
                    /* Possible PsyQ macro: setTile8() */
    *(undefined1 *)(param_1 + 1) = 4;
    *(undefined1 *)(param_1 + 2) = 0;
  }
  return bVar1;
}


// ---- 801dad38 FUN_801dad38

bool FUN_801dad38(int param_1)

{
  int iVar1;
  short sVar2;
  
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    sVar2 = *(short *)(param_1 + 0xe) + -10;
  }
  else {
    sVar2 = *(short *)(param_1 + 0xe) + 10;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  iVar1 = FUN_80107204((int)sVar2,(int)((*(ushort *)(param_1 + 0x12) + 0xc) * 0x10000) >> 0x10);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 1) = 4;
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return iVar1 == 0;
}


// ---- 801dadb4 FUN_801dadb4

void FUN_801dadb4(int param_1)

{
  if (*(int *)(param_1 + 0x18) < -0x60000) {
    *(undefined4 *)(param_1 + 0x18) = 0xfffa0000;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


// ---- 801dadd8 FUN_801dadd8

void FUN_801dadd8(int param_1)

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
      FUN_801daf94(param_1);
      FUN_80105888(param_1);
    }
    else {
      *(undefined1 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// ---- 801dae5c FUN_801dae5c

void FUN_801dae5c(int param_1)

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
          sVar1 = *(short *)((int)&DAT_801e6d74 + iVar4);
        }
        else {
          sVar1 = -*(short *)((int)&DAT_801e6d74 + iVar4);
        }
        iVar3 = FUN_801091a4((int)(short)(*(short *)(param_1 + 0xe) + sVar1),
                             (int)(((uint)*(ushort *)(param_1 + 0x12) +
                                   (uint)*(ushort *)((int)&DAT_801e6d76 + iVar4)) * 0x10000) >> 0x10
                             ,1);
        iVar4 = iVar4 + 4;
        if (iVar3 != 0) {
          *(undefined1 *)(iVar3 + 0x26) = 6;
        }
        iVar5 = iVar5 + 1;
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


// ---- 801daf94 FUN_801daf94

void FUN_801daf94(int param_1)

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


