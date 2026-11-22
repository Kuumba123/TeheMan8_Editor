// T3_0E, STAGE00.BIN, handler 0x801E0058. Ghidra output with the object struct applied; not matching C.
// ---- 801e0058 FUN_801e0058

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0058(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = obj->state;
  if (bVar1 == 1) {
LAB_801e00d8:
    if ((DAT_801b29a0 & 4) != 0) {
      obj->state = 2;
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        obj->bank = 7;
        obj->vram_base = DAT_80170356;
        bVar1 = DAT_80159f6c;
        obj->flip = 0;
        obj->clut = bVar1;
        Anim_Set(obj,obj->var);
        obj->state = 1;
        goto LAB_801e00d8;
      }
    }
    else if (bVar1 == 2) {
      if (((int)(short)obj->frame & 0x8000U) != 0) {
        Anim_Set(obj,obj->var + 2);
        obj->state = 3;
      }
      goto LAB_801e0148;
    }
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      Obj_Free(obj);
      return;
    }
  }
LAB_801e0148:
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  cVar2 = Obj_InActiveArea(obj);
  if (cVar2 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


