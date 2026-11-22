// T3_3F, STAGE0C.BIN, handler 0x801EA310. Ghidra output with the object struct applied; not matching C.
// ---- 801ea310 FUN_801ea310

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea310(MM8Obj *obj)

{
  if (*obj->hitbox == 2) {
    *(undefined1 *)&obj->box2 = 0;
  }
  else if ((obj->var == 1) || (*(char *)obj->accel_x != '\0')) {
    (*(code *)(&PTR_FUN_801eb0cc)[obj->state])(obj);
    if (obj->active == 0) {
      return;
    }
    if (*(char *)&obj->box2 == '\0') {
      return;
    }
    Obj_CullAndQueueDraw(obj);
    return;
  }
  Obj_Free(obj);
  return;
}


// ---- 801ea3c8 FUN_801ea3c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea3c8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  word wVar3;
  
  *(undefined1 *)&obj->box2 = 0;
  bVar1 = (&DAT_801eb0bc)[obj->var];
  obj->bank = bVar1;
  wVar3 = (&DAT_80170348)[bVar1];
  obj->flip = 0;
  obj->vram_base = wVar3;
  if ((&DAT_801eb0c0)[obj->var] == -1) {
    obj->clut = (&DAT_80159f64)[bVar1];
  }
  else {
    obj->clut = (&DAT_801eb0c0)[obj->var] + obj->clut;
  }
  cVar2 = *(char *)(obj->accel_x + 0x26);
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->state = obj->var + 1;
  obj->draw_list = cVar2 - 1;
  (*(code *)(&PTR_FUN_801eb0cc)[obj->state])();
  return;
}


// ---- 801ea4a0 FUN_801ea4a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea4a0(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = obj->accel_x;
  if (obj->sub2 == 0) {
    Anim_Set(obj,0x11);
    *(undefined1 *)&obj->box2 = 1;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
  }
  obj->x = (ushort)(byte)(&DAT_801eb0c4)[(uint)obj->var * 2] + *(short *)(iVar1 + 0xe);
  obj->y = (ushort)(byte)(&DAT_801eb0c5)[(uint)obj->var * 2] + *(short *)(iVar1 + 0x12);
  if ((obj->anim_extra & 0x10) != 0) {
    FUN_8010544c(obj,0x199);
  }
  return;
}


// ---- 801ea55c FUN_801ea55c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea55c(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = obj->accel_x;
  if (obj->sub2 == 0) {
    Anim_Set(obj,0xe);
    *(undefined1 *)&obj->box2 = 1;
    obj->speed_y_up = 0x1000;
    obj->gravity = -0x1000;
    obj->speed_x = 0;
    obj->draw_list = *(byte *)(iVar3 + 0x26);
    obj->x = (ushort)(byte)(&DAT_801eb0c4)[(uint)obj->var * 2] + *(short *)(iVar3 + 0xe);
    bVar1 = (&DAT_801eb0c5)[(uint)obj->var * 2];
    sVar2 = *(short *)(iVar3 + 0x12);
    obj->sub2 = obj->sub2 + 1;
    obj->y = (ushort)bVar1 + sVar2;
  }
  else {
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    if (iVar3 != 0) {
      Obj_Free(obj);
      return;
    }
  }
  FUN_80104ccc(obj);
  return;
}


// ---- 801ea644 FUN_801ea644

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea644(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = obj->accel_x;
  if (obj->sub2 == 0) {
    Anim_Set(obj,1);
    obj->clut = 0x10;
    *(undefined1 *)&obj->box2 = 1;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
  }
  obj->x = (ushort)(byte)(&DAT_801eb0c4)[(uint)obj->var * 2] + *(short *)(iVar1 + 0xe);
  obj->y = (ushort)(byte)(&DAT_801eb0c5)[(uint)obj->var * 2] + *(short *)(iVar1 + 0x12);
  return;
}


