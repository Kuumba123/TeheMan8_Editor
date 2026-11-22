// ID 58, STAGE0D.BIN, handler 0x801F4370. Ghidra output with the object struct applied; not matching C.
// ---- 801f4370 FUN_801f4370

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4370(MM8Obj *obj)

{
  byte bVar1;
  
  (*(code *)(&PTR_FUN_801f9064)[obj->state])();
  if ((obj->active != 0) && (obj->var == 0)) {
    bVar1 = 0x1a;
    if (obj->anim_extra == 0) {
      bVar1 = DAT_8015a005;
    }
    obj->clut = bVar1;
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801f4400 FUN_801f4400

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4400(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  
  Enemy_InitFromTable();
  if (obj->var == 0) {
    obj->draw_list = 7;
    obj->state = 1;
    obj->flip = 0;
    obj->speed_y_up = -0x80000;
    sVar1 = DAT_801d2918._2_2_;
    obj->box2 = &DAT_801f905c;
    obj->x = sVar1 + -0x40;
    Anim_Set(obj,0);
    puVar2 = (undefined1 *)Obj_AllocMain();
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x58;
      puVar2[7] = 1;
      *(MM8Obj **)(puVar2 + 0x54) = obj;
    }
  }
  else {
    obj->state = 6;
    obj->flip = 0;
    obj->draw_list = 6;
    Anim_Set(obj,5);
  }
  return;
}


// ---- 801f44c4 FUN_801f44c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f44c4(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    if (DAT_801cf53c == '\0') {
      obj->sub2 = 1;
      obj->field_0x50 = 0xfa;
      FUN_800fd100(0x198);
    }
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
    if (obj->field_0x50 == '\0') {
      obj->state = 2;
      obj->sub2 = 0;
      obj->field_0x50 = 8;
      FUN_800fd100(0);
      obj->x = DAT_801d2918._2_2_ + 0xa0;
      obj->y = g_cam_y;
    }
  }
  return;
}


// ---- 801f4584 FUN_801f4584

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4584(MM8Obj *obj)

{
  undefined4 uVar1;
  
  if (obj->sub2 == 0) {
    FUN_80104d18();
    if (obj->field_0x50 != '\0') {
      obj->field_0x50 = obj->field_0x50 + -1;
      return;
    }
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) == 0) {
      return;
    }
    obj->sub2 = 1;
    uVar1 = 1;
  }
  else {
    Anim_Step(obj);
    if (-1 < (short)obj->frame) {
      return;
    }
    uVar1 = 3;
    obj->state = 3;
    obj->sub2 = 0;
    DAT_801b29a7 = 1;
  }
  Anim_Set(obj,uVar1);
  return;
}


// ---- 801f464c FUN_801f464c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f464c(MM8Obj *obj)

{
  Anim_Step();
  if (DAT_801c73e8 == '\x06') {
    obj->state = 4;
    Anim_Set(obj,4);
  }
  if (DAT_801b29a7 == '\0') {
    obj->state = 5;
    Anim_Set(obj,2);
    FUN_800fd100(6);
  }
  return;
}


// ---- 801f46c4 FUN_801f46c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f46c4(MM8Obj *obj)

{
  Anim_Step();
  if (DAT_801c73e8 != '\x06') {
    obj->state = 3;
    Anim_Set(obj,3);
  }
  return;
}


// ---- 801f4710 FUN_801f4710

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4710(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    Anim_Step();
    if ((short)obj->frame < 0) {
      obj->sub2 = 1;
      obj->field_0x43 = 1;
      Anim_Set(obj,0);
      obj->speed_y_up = 0x80000;
    }
  }
  else {
    Anim_Step(obj);
    FUN_80104d18(obj);
    if (obj->y < g_cam_y) {
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801f47b0 FUN_801f47b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f47b0(MM8Obj *obj)

{
  char *pcVar1;
  
  Anim_Step();
  pcVar1 = *(char **)&obj->field_0x54;
  if (*pcVar1 == '\0') {
    Obj_Free(obj);
  }
  obj->x = *(short *)(pcVar1 + 0xe);
  obj->y = *(short *)(pcVar1 + 0x12);
  obj->flip = pcVar1[0x25];
  if ((*(ushort *)(pcVar1 + 0x2e) & 0x7fff) < 2) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


