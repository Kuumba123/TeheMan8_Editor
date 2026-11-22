// T3_34, STAGE06.BIN, handler 0x801E4734. Ghidra output with the object struct applied; not matching C.
// ---- 801e4734 FUN_801e4734

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4734(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  
  uVar3 = FUN_80105e30(obj,0x34);
  if (0x14 < uVar3) goto LAB_801e4980;
  bVar1 = obj->state;
                    /* Possible PsyQ macro: setPolyGT3() */
  if (bVar1 == 1) {
LAB_801e483c:
    if ((int)obj->hitbox < obj->speed_x) {
      obj->speed_x = (int)obj->hitbox;
      obj->accel_x = 0;
    }
    if (obj->speed_y_up < -0x4000) {
      obj->speed_y_up = -0x4000;
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
      obj->gravity = 0;
    }
    pbVar5 = obj->box2;
    if ((obj->var == 0) &&
       (((*pbVar5 == 0 || (pbVar5[6] != 0x2e)) || (obj->x < *(short *)(pbVar5 + 0x44))))) {
      uVar3 = Rand();
      iVar4 = *(int *)(&DAT_801e5c80 + (uVar3 & 3) * 4);
      obj->accel_x = 0x2000;
      obj->state = 2;
      obj->gravity = -(iVar4 + 0x2000);
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      obj->bank = 6;
      obj->vram_base = DAT_80170354;
      bVar1 = (&DAT_80159f64)[obj->bank];
      obj->flip = 0;
      obj->draw_list = 5;
      obj->clut = bVar1;
      uVar3 = Rand();
      iVar4 = *(int *)(&DAT_801e5c80 + (uVar3 & 3) * 4);
      obj->speed_y_up = -0x4000;
      obj->gravity = 0x800;
      obj->accel_x = 0x4000;
                    /* Possible PsyQ macro: setPolyGT3() */
      obj->speed_x = -(iVar4 + 0x80000);
      Anim_Set(obj,2);
      uVar3 = Rand();
      obj->hitbox = (byte *)-((0x4000 << (uVar3 & 3)) + 0x40000);
      obj->state = 1;
      goto LAB_801e483c;
    }
  }
  else if (bVar1 == 2) {
    if (0 < obj->speed_x) {
      obj->speed_x = 0;
      obj->accel_x = 0;
    }
    if (0x40000 < obj->speed_y_up) {
      obj->gravity = 0;
      obj->speed_y_up = 0x40000;
    }
    Anim_Step(obj);
  }
  if (obj->active == 0) {
    return;
  }
  Obj_ApplySpeed(obj);
  cVar2 = Obj_InActiveArea(obj);
  if ((cVar2 != '\0') && (DAT_801b2988 + 10 <= (int)obj->y)) {
    Obj_CullAndQueueDraw(obj);
    return;
  }
LAB_801e4980:
  Obj_Free(obj);
  return;
}


