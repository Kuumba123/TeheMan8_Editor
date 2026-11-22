// ID 5B, STAGE0D.BIN, handler 0x801F4844. Ghidra output with the object struct applied; not matching C.
// ---- 801f4844 FUN_801f4844

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4844(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f9088)[obj->state])();
  if (obj->active != 0) {
    FUN_80103184(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801f48ac FUN_801f48ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f48ac(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->state = 1;
                    /* Possible PsyQ macro: setLineF2() */
  obj->flip = 0x40;
  obj->draw_list = 7;
  obj->field_0x49 = 7;
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
  obj->box2 = &DAT_801f9080;
  obj->x = 0x890;
  obj->y = 0xca7;
  obj->speed_x = 0x80000;
  Anim_Set(obj,0x12);
  FUN_80103224(obj);
  return;
}


// ---- 801f4930 FUN_801f4930

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4930(MM8Obj *obj)

{
  undefined1 *puVar1;
  
  Anim_Step();
  FUN_80104d00(obj);
  if (0x910 < obj->x) {
    obj->state = 2;
    FUN_801f4dd4(obj);
    puVar1 = (undefined1 *)FUN_801055e4(obj);
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar1[6] = 0x5c;
      puVar1[7] = 0x12;
      *(MM8Obj **)(puVar1 + 0x50) = obj;
      FUN_8010544c(obj,0x1e8);
    }
    FUN_801037e0(0x16);
  }
  return;
}


// ---- 801f49c0 FUN_801f49c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f49c0(MM8Obj *obj)

{
  FUN_801f4dd4();
  Anim_Step(obj);
  if (DAT_801c73e8 == '\0') {
    obj->state = 3;
    obj->speed_x = 0x60000;
  }
  return;
}


// ---- 801f4a10 FUN_801f4a10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4a10(MM8Obj *obj)

{
  undefined1 *puVar1;
  
  Anim_Step();
  FUN_80104d00(obj);
  FUN_801f4dd4(obj);
  if (DAT_801d2918._2_2_ + 0x130 < (int)obj->x) {
    obj->state = 4;
    Anim_Set(obj,0x14);
    FUN_8010544c(obj,0x1ea);
    DAT_801b29a2 = 0;
    FUN_8010bb88(0,0);
                    /* Possible PsyQ macro: setPolyF3() */
    obj->field_0x55 = 0x20;
    FUN_8010bbe4(0x20);
    FUN_800fcd84();
    obj->speed_y_up = 0x412d2;
    obj->speed_x = -0x68000;
    obj->gravity = 0x4000;
    puVar1 = (undefined1 *)FUN_801055e4(obj);
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar1[6] = 0x5c;
      puVar1[7] = 0xf;
      *(short *)(puVar1 + 0xe) = obj->x;
      *(short *)(puVar1 + 0x12) = obj->y;
    }
  }
  return;
}


// ---- 801f4b0c FUN_801f4b0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4b0c(MM8Obj *obj)

{
  FUN_801f4d74();
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->state = 5;
    Anim_Set(obj,0x15);
    FUN_8010544c(obj,0x1e9);
  }
  return;
}


// ---- 801f4b74 FUN_801f4b74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4b74(MM8Obj *obj)

{
  FUN_801f4d74();
  Anim_Step(obj);
  if ((short)obj->frame < 0) {
    obj->state = 6;
    Anim_Set(obj,0x16);
    FUN_801037e0(0x17);
  }
  return;
}


// ---- 801f4bcc FUN_801f4bcc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4bcc(MM8Obj *obj)

{
  Anim_Step();
  if (obj->sub2 == 0) {
    if (DAT_801c73e8 == '\0') {
      obj->sub2 = 1;
      FUN_801037e0(0x18);
    }
  }
  else if (DAT_801c73e8 == '\0') {
    obj->state = 7;
    obj->sub2 = 0;
    DAT_801b29a1 = 0;
  }
  return;
}


// ---- 801f4c50 FUN_801f4c50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4c50(MM8Obj *obj)

{
  Anim_Step();
  if (DAT_801b29a1 != '\0') {
    obj->state = 8;
    obj->field_0x54 = 0x3c;
  }
  return;
}


// ---- 801f4c98 FUN_801f4c98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4c98(MM8Obj *obj)

{
  if (obj->field_0x54 == '\0') {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->state = 9;
      obj->speed_y_up = 0x80000;
      Anim_Set(obj,0x18);
    }
  }
  else {
    obj->field_0x54 = obj->field_0x54 + -1;
    if (obj->field_0x54 == '\0') {
      Anim_Set(obj,0x17);
      FUN_800fd100(6);
    }
  }
  return;
}


// ---- 801f4d34 FUN_801f4d34

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4d34(MM8Obj *obj)

{
  FUN_80104d18();
  if (obj->on_screen == 0) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801f4d74 FUN_801f4d74

void FUN_801f4d74(int param_1)

{
  if (*(char *)(param_1 + 0x55) != '\0') {
    *(char *)(param_1 + 0x55) = *(char *)(param_1 + 0x55) + -1;
    if (*(char *)(param_1 + 0x55) == '\0') {
      FUN_8010bbb8();
    }
    else {
      FUN_8010bbe4();
    }
  }
  return;
}


// ---- 801f4dd4 FUN_801f4dd4

void FUN_801f4dd4(int param_1)

{
  int iVar1;
  
  iVar1 = *(short *)(param_1 + 0xe) + -0x860;
  if (iVar1 < 0) {
    iVar1 = *(short *)(param_1 + 0xe) + -0x851;
  }
  DAT_801b29a1 = (char)(iVar1 >> 4);
  return;
}


