// T2_2D, STAGE07.BIN, handler 0x801DEC50. Ghidra output with the object struct applied; not matching C.
// ---- 801dec50 FUN_801dec50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dec50(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  if (obj->state == 0) {
    obj->state = 1;
    obj->bank = 0x8d;
    obj->vram_base = DAT_80170462;
    bVar1 = DAT_80159ff1;
    obj->clut = DAT_80159ff1;
    if (DAT_801c3371 == '\x04') {
      obj->clut = bVar1 + 1;
    }
    obj->draw_list = 7;
    obj->flip = 0;
    obj->frame = *(word *)(&DAT_801e0bdc + (uint)obj->var * 2);
  }
  iVar2 = Obj_InActiveArea(obj);
  if (iVar2 == 0) {
    Obj_FreeDespawn(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


