// T3_33, STAGE07.BIN, handler 0x801DF078. Ghidra output with the object struct applied; not matching C.
// ---- 801df078 FUN_801df078

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df078(MM8Obj *obj)

{
  bool bVar1;
  short sVar2;
  
  if (obj->state == 0) {
    obj->state = 1;
    obj->bank = 0x6e;
    obj->clut = DAT_80159fd2;
    obj->vram_base = DAT_80170424;
    if ((obj->var & 1) == 0) {
      obj->flip = 0;
    }
    else {
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
    }
    bVar1 = (obj->var & 2) == 0;
    if (bVar1) {
      obj->draw_list = 1;
    }
    else {
      obj->draw_list = 0;
    }
    Anim_Set(obj,!bVar1);
  }
                    /* Possible PsyQ macro: setPolyF4() */
  if ((obj->var & 1) == 0) {
    sVar2 = DAT_801d2918._2_2_ + 0x80;
  }
  else {
    sVar2 = DAT_801d2918._2_2_ + 0xc0;
  }
  obj->x = sVar2;
  if ((obj->var & 2) == 0) {
    sVar2 = g_cam_y + 0xf4;
  }
  else {
    sVar2 = g_cam_y + 0xec;
  }
  obj->y = sVar2;
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
                    /* Possible PsyQ macro: setPolyF4() */
  return;
}


