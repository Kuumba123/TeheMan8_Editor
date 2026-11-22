// T2_24, STAGE05.BIN, handler 0x801E7AD0. Ghidra output with the object struct applied; not matching C.
// ---- 801e7ad0 FUN_801e7ad0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7ad0(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801e7b1c();
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e7b1c FUN_801e7b1c

void FUN_801e7b1c(int param_1)

{
  (*(code *)(&PTR_FUN_801eaa30)[*(byte *)(param_1 + 1)])();
  return;
}


// ---- 801e7b58 FUN_801e7b58

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7b58(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0x53;
  obj->vram_base = DAT_801703ee;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->draw_list = 5;
  obj->clut = bVar1;
  Anim_Set(obj,2);
  obj->state = 1;
  return;
}


// ---- 801e7bd0 FUN_801e7bd0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7bd0(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    bVar1 = obj->dmg_table;
    obj->dmg_table = bVar1 - 1;
    if (bVar1 == 0) {
      obj->sub2 = 2;
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && (obj->y < DAT_8015e24c._2_2_)) {
      obj->dmg_table = 10;
      obj->sub2 = 1;
    }
  }
  else if (bVar1 == 2) {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->sub2 = 3;
      FUN_80102ecc(0x3f);
    }
    Anim_Step(obj);
  }
  return;
}


