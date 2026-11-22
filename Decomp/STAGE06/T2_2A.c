// T2_2A, STAGE06.BIN, handler 0x801E3D54. Ghidra output with the object struct applied; not matching C.
// ---- 801e3d54 FUN_801e3d54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3d54(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  if (obj->state == 0) {
    obj->bank = 0x8b;
    obj->vram_base = DAT_8017045e;
    bVar1 = (&DAT_80159f64)[obj->bank];
    obj->draw_list = 6;
    obj->box2 = &DAT_801e5c40;
    obj->flip = 0;
    obj->hitbox = &DAT_801e5c48;
    obj->clut = bVar1;
                    /* Possible PsyQ macro: setPolyGT4() */
    if (((int)(uint)DAT_801b29a0 >> (obj->var & 0x1f) & 1U) == 0) {
      Anim_Set(obj,0);
      obj->sub2 = 0;
    }
    else {
      Anim_SetAtStep(obj,0,0xb);
      obj->sub2 = 4;
    }
    obj->state = 1;
  }
  switch(obj->sub2) {
  case 0:
    iVar3 = (int)(((uint)(ushort)obj->x - (uint)DAT_8015e248._2_2_) * 0x10000) >> 0x10;
    if ((-1 < iVar3) && (iVar3 < 0x22)) {
      DAT_801d2917 = 2;
      DAT_801d292a = g_cam_y;
      DAT_801d292c = g_cam_y;
      DAT_801d2926 = obj->x + -0x10;
      DAT_801d2928 = obj->x + -0x10;
      FUN_80105bec();
      obj->sub2 = 1;
      FUN_801119e0(obj->x + 0x30,0x40);
    }
    break;
  case 1:
    if (DAT_801d2918._2_2_ == DAT_801d2926) {
      FUN_8011c5d4((int)*(short *)(&DAT_801e5c4c + (uint)obj->var * 2));
      DAT_801d2917 = 0;
      obj->sub2 = 2;
    }
    break;
  case 2:
    if (obj->x + 0x30 <= (int)(short)DAT_8015e248._2_2_) {
      obj->sub2 = 3;
      obj->dmg_table = 0x1e;
      DAT_801b29a0 = DAT_801b29a0 | (byte)(1 << (obj->var & 0x1f));
      FUN_8010544c(obj,0x10d);
    }
    break;
  case 3:
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->sub2 = 4;
      FUN_80111918();
    }
    Anim_Step(obj);
    break;
  default:
    FUN_8010976c(obj);
    FUN_80107bf4(obj,&g_player,6);
  }
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    cVar2 = Obj_InActiveArea(obj);
    if (cVar2 == '\0') {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


