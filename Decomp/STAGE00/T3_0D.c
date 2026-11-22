// T3_0D, STAGE00.BIN, handler 0x801DFE58. Ghidra output with the object struct applied; not matching C.
// ---- 801dfe58 FUN_801dfe58

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfe58(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e2928)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801dfec0 FUN_801dfec0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfec0(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = (&DAT_801e2920)[obj->var];
  obj->bank = 0xd;
  obj->draw_list = bVar1;
  obj->vram_base = DAT_80170362;
  obj->clut = DAT_80159f71;
  if (obj->var == 6) {
                    /* Possible PsyQ macro: setLineF2() */
    obj->flip = 0x40;
  }
  else {
    obj->flip = 0;
  }
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  *(byte *)&obj->box2 = DAT_801b29a1 >> 3 & 0xf;
  Anim_Set(obj,(&DAT_801e2918)[obj->var]);
  obj->state = 1;
  obj->anim_timer = *(char *)&obj->box2 + 4;
  return;
}


// ---- 801dff88 FUN_801dff88

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dff88(MM8Obj *obj)

{
  if ((DAT_801b29a1 & 0x80) != 0) {
    *(byte *)&obj->box2 = DAT_801b29a1 >> 3 & 0xf;
    FUN_801dffd4();
  }
  return;
}


// ---- 801dffd4 FUN_801dffd4

void FUN_801dffd4(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  *(char *)(param_1 + 0x31) = *(char *)(param_1 + 0x31) + -1;
  if (*(char *)(param_1 + 0x31) == '\0') {
    iVar3 = *(int *)(param_1 + 0x28);
    iVar2 = iVar3 + 4;
    *(int *)(param_1 + 0x28) = iVar2;
    if (((int)*(short *)(param_1 + 0x2e) & 0x8000U) != 0) {
      *(int *)(param_1 + 0x28) = iVar2 + *(short *)(iVar3 + 4) * -4;
    }
    uVar1 = **(undefined2 **)(param_1 + 0x28);
    *(char *)(param_1 + 0x31) = *(char *)(param_1 + 0x38) + '\x04';
    *(undefined2 *)(param_1 + 0x2e) = uVar1;
    *(undefined1 *)(param_1 + 0x32) = *(undefined1 *)(*(int *)(param_1 + 0x28) + 3);
  }
  return;
}


// ---- 801e01e8 FUN_801e01e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e01e8(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = 0x6b;
  if (obj->var != 0) {
    bVar1 = 0x6c;
  }
  obj->bank = bVar1;
  obj->vram_base = (&DAT_80170348)[obj->bank];
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->draw_list = 6;
  obj->flip = 0;
  obj->speed_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0x200;
  obj->clut = bVar1;
  Anim_Set(obj,0);
  if (obj->var == 1) {
    obj->speed_x = -0x10000;
  }
  bVar1 = 1;
  if (obj->var != 0) {
    bVar1 = 5;
  }
  obj->state = bVar1;
  return;
}


// ---- 801e02a4 FUN_801e02a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e02a4(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = obj->accel_x;
  Anim_Step();
  switch(obj->sub2) {
  case 0:
    if (*(char *)(iVar1 + 1) == '\x02') {
      Anim_Set(obj,1);
      FUN_800fd100(0x186);
      obj->sub2 = 1;
    }
    break;
  case 1:
    iVar1 = FUN_801e06c0(obj);
    if (iVar1 != 0) {
      Anim_Set(obj,4);
      *(undefined1 *)&obj->box2 = 0x20;
      obj->sub2 = 2;
    }
    break;
  case 2:
    *(char *)&obj->box2 = *(char *)&obj->box2 + -1;
    if (*(char *)&obj->box2 != '\0') break;
    FUN_801e05e8(obj,1,4,3);
    FUN_800fd100(0x189);
    obj->sub2 = 3;
    goto LAB_801e03f8;
  case 3:
    if (obj->sub3 == 0) {
      obj->sub3 = 1;
      *(undefined1 *)(iVar1 + 0x15) = 2;
    }
    else if (*(char *)(iVar1 + 0x15) == '\x03') {
      FUN_801e05e8(obj,1,4,3);
      FUN_800fd100(0x189);
      obj->sub2 = 4;
    }
    break;
  case 4:
    *(undefined1 *)(iVar1 + 0x15) = 4;
    obj->state = 2;
    obj->sub2 = 0;
LAB_801e03f8:
    obj->sub3 = 0;
  }
  FUN_801e06e8(obj);
  return;
}


// ---- 801e041c FUN_801e041c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e041c(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  Anim_Step();
  if ((DAT_801c73e8 & 0x7f) == 2) {
    if (obj->sub3 == 0) {
      Anim_Set(obj,3);
      obj->sub3 = 1;
    }
  }
  else if (((DAT_801c73e8 & 0x7f) == 3) && (obj->sub3 != 0)) {
    Anim_Set(obj,4);
    obj->sub3 = 0;
  }
  if (DAT_801c73e8 == 0) {
    FUN_800fd100(0x18a);
    FUN_801e05e8(obj,3,4,4);
    obj->sub2 = 0;
    obj->sub3 = 0;
  }
  FUN_801e06e8(obj);
  return;
}


// ---- 801e04f0 FUN_801e04f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e04f0(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  iVar2 = obj->accel_x;
  Anim_Step();
  if (obj->sub2 == 0) {
    FUN_801e06e8(obj);
    if (obj->sub3 == 0) {
      Anim_Set(obj,5);
      obj->sub3 = 1;
    }
    else {
      iVar1 = FUN_801e06c0(obj);
      if (iVar1 != 0) {
        Anim_Set(obj,0);
        FUN_800fd100(0x188);
        obj->sub2 = 1;
        obj->gravity = -0x200;
        *(undefined1 *)(iVar2 + 5) = 1;
      }
    }
    if (obj->anim_extra != 0) {
      obj->anim_extra = 0;
      FUN_800fd100(0x187);
    }
  }
  else {
    FUN_80104ccc(obj);
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_Free(obj);
      *(undefined1 *)(iVar2 + 0x15) = 6;
    }
  }
  return;
}


// ---- 801e05e8 FUN_801e05e8

void FUN_801e05e8(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  *(undefined1 *)(param_1 + 0x39) = param_2;
  *(undefined1 *)(param_1 + 1) = 4;
  *(undefined1 *)(param_1 + 0x3a) = param_3;
  *(undefined1 *)(param_1 + 0x38) = param_4;
  Anim_Set(param_1,2);
  return;
}


// ---- 801e061c FUN_801e061c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e061c(MM8Obj *obj)

{
  undefined1 uVar1;
  int iVar2;
  
  Anim_Step();
  iVar2 = FUN_801e06c0(obj);
  if ((iVar2 != 0) && (*(char *)&obj->box2 = *(char *)&obj->box2 + -1, *(char *)&obj->box2 == '\0'))
  {
    uVar1 = *(undefined1 *)((int)&obj->box2 + 2);
    obj->state = *(byte *)((int)&obj->box2 + 1);
    Anim_Set(obj,uVar1);
    *(undefined1 *)((int)&obj->box2 + 1) = 0;
    *(undefined1 *)((int)&obj->box2 + 2) = 0;
  }
  FUN_801e06e8(obj);
  return;
}


// ---- 801e06c0 FUN_801e06c0

bool FUN_801e06c0(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (*(short *)(param_1 + 0x2e) < 0) {
    bVar1 = *(char *)(param_1 + 0x31) == '\x01';
  }
  return bVar1;
}


// ---- 801e06e8 FUN_801e06e8

void FUN_801e06e8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffc000;
  if (0x8000 < *(int *)(param_1 + 0x18) + 0x4000U) {
    *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
    if (0 < *(int *)(param_1 + 0x18)) {
      uVar1 = 0x4000;
    }
    *(undefined4 *)(param_1 + 0x18) = uVar1;
  }
  FUN_80104ccc();
  return;
}


