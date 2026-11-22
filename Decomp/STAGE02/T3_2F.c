// T3_2F, STAGE02.BIN, handler 0x801E63B8. Ghidra output with the object struct applied; not matching C.
// ---- 801e63b8 FUN_801e63b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e63b8(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  
  if (obj->state == 0) {
    obj->bank = 0x71;
    obj->vram_base = DAT_8017042a;
    bVar1 = (&DAT_80159f64)[obj->bank];
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->flip = 0;
    obj->draw_list = 1;
    obj->state = 1;
    obj->box2 = *(byte **)&obj->x_frac;
    obj->clut = bVar1;
    Anim_Set(obj,obj->var);
  }
  *(byte **)&obj->x_frac = obj->box2;
  if (obj->var == 0) {
    sVar2 = obj->x - (ushort)DAT_801b29a2;
  }
  else {
    sVar2 = (ushort)DAT_801b29a2 + obj->x;
  }
  obj->x = sVar2;
  if (DAT_801b29a2 < 0xa1) {
    Obj_CullAndQueueDraw(obj);
  }
  else {
    Obj_FreeDespawn(obj);
  }
  return;
}


