// T3_11, STAGE01.BIN, handler 0x801E50D0. Ghidra output with the object struct applied; not matching C.
// ---- 801e50d0 FUN_801e50d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e50d0(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  if (obj->state == 0) {
    uVar3 = Rand();
    bVar1 = (&DAT_801e6f7c)[uVar3 & 0xf];
    uVar3 = (uint)bVar1;
    obj->bank = 0x1b;
    obj->vram_base = DAT_8017037e;
    bVar2 = DAT_80159f7f;
    obj->draw_list = bVar1;
    obj->clut = bVar2;
    if (*(char *)&obj->box2 != '\0') {
      uVar3 = Rand();
      uVar3 = (uVar3 & 1) + 1;
      obj->var = (byte)uVar3;
      obj->draw_list = (DAT_801b291c & 1) + 10;
    }
    obj->speed_x = 0;
    uVar4 = Rand();
    obj->speed_y_up = *(int *)(&DAT_801e6f8c + uVar3 * 4) + (uVar4 & 3) * -0x8000;
    uVar4 = Rand();
    obj->gravity = uVar4 & 0xff;
    if ((uVar3 == 2) && (uVar4 = Rand(obj), (uVar4 & 0x8000) != 0)) {
      obj->draw_list = 10;
      obj->speed_y_up = obj->speed_y_up >> 1;
    }
    Anim_SetAtStep(obj,2,uVar3);
    obj->state = 1;
  }
  FUN_80104ccc(obj);
  if ((*(char *)((int)&obj->box2 + 1) != '\0') && (DAT_801d2936 != 0)) {
    obj->y = obj->y + 1;
  }
  if (((int)obj->x < DAT_801d2918._2_2_ + -0x38) || (_g_cam_y + 0x178 < (int)obj->y)) {
    Obj_Free(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


