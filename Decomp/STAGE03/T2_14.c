// T2_14, STAGE03.BIN, handler 0x801E84BC. Ghidra output with the object struct applied; not matching C.
// ---- 801e84bc FUN_801e84bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e84bc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9fbc)[obj->state])();
  Obj_CullAndQueueDrawMargin(obj,0x40);
  return;
}


// ---- 801e8510 FUN_801e8510

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8510(MM8Obj *obj)

{
  byte bVar1;
  
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  obj->bank = 0x26;
  obj->vram_base = DAT_80170394;
  bVar1 = DAT_80159f8a;
  obj->draw_list = 7;
  obj->flip = 0;
  obj->clut = bVar1;
  if (obj->y < DAT_8015e24c._2_2_) {
    obj->state = 1;
    Anim_Set(obj,0xc);
  }
  else {
    obj->state = 2;
    Anim_SetAtStep(obj,0xc,9);
  }
  return;
}


// ---- 801e859c FUN_801e859c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e859c(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    if ((int)DAT_8015e24c._2_2_ <= obj->y + -0x40) {
      obj->sub2 = 1;
    }
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->state = 2;
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801e8614 FUN_801e8614

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8614(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    obj->sub2 = 1;
    FUN_80102ef4(0,(int)obj->x,(int)obj->y);
  }
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_FreeDespawn(obj);
  }
  return;
}


