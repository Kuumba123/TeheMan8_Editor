// T2_1A, STAGE05.BIN, handler 0x801E45D4. Ghidra output with the object struct applied; not matching C.
// ---- 801e45d4 FUN_801e45d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e45d4(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801ea8b4)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    cVar1 = Obj_InActiveArea(obj);
    if ((cVar1 == '\0') && (obj->state != 2)) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801e4660 FUN_801e4660

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4660(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0x91;
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  obj->vram_base = DAT_8017046a;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->draw_list = 6;
  obj->box2 = &DAT_801ea8ac;
  obj->hitbox = &DAT_801ea8a8;
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->state = 1;
  obj->clut = bVar1;
  Anim_Set(obj,0);
  if (((obj->var & 0x80) == 0) && (((uint)DAT_801c3378 & 0x10 << (obj->var & 0xf)) != 0)) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e4728 FUN_801e4728

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4728(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = Obj_HitboxOverlap(obj,&g_player);
  if (iVar1 != 0) {
    obj->state = 2;
  }
  Anim_Step(obj);
                    /* Possible PsyQ macro: setPolyGT3() */
  return;
}


