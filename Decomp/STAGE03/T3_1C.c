// T3_1C, STAGE03.BIN, handler 0x801E8B6C. Ghidra output with the object struct applied; not matching C.
// ---- 801e8b6c FUN_801e8b6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8b6c(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  if (obj->state == 0) {
    obj->state = 1;
    obj->bank = 0x45;
    obj->vram_base = DAT_801703d2;
    obj->clut = DAT_80159fa9;
    do {
      while( true ) {
        uVar2 = Rand(obj);
        uVar2 = uVar2 & 7;
        if (obj->var != 0) break;
        if (uVar2 < 4) {
          obj->draw_list = 10;
          iVar3 = uVar2 + 3;
          goto LAB_801e8c08;
        }
      }
    } while (2 < uVar2);
    obj->draw_list = 0;
    iVar3 = uVar2 + 7;
LAB_801e8c08:
    Anim_Set(obj,iVar3);
    bVar1 = Rand();
    obj->flip = bVar1 & 0xc0;
    if (obj->var == 0) {
      uVar2 = Rand();
      obj->speed_x = (uVar2 & 0x1fff) * 0x10 + 0x28000;
      obj->speed_y_up = -0x10000;
      iVar3 = -0x800;
    }
    else {
      uVar2 = Rand();
      obj->speed_x = (uVar2 & 0x1fff) * 0x10 + 0x50000;
      obj->speed_y_up = -0x20000;
      iVar3 = -0x1000;
    }
    obj->gravity = iVar3;
    obj->accel_x = 0;
  }
  Obj_ApplySpeed(obj);
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  if (obj->on_screen == 0) {
    Obj_Free(obj);
  }
  return;
}


