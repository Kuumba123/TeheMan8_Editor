// T2_25 handler in PSX.EXE at 0x80129684 (same code in every stage)
// ---- 80129684 FUN_80129684

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80129684(MM8Obj *obj)

{
  byte bVar1;
  word wVar2;
  int iVar3;
  
  if (obj->state == 0) {
    obj->dmg_table = obj->var >> 3;
    bVar1 = (&DAT_80139548)[obj->var & 7];
    obj->contact_dmg = bVar1;
    if ((*(byte *)((int)&DAT_8016d2f8 + obj->dmg_table + 3) & bVar1) != 0) {
      Obj_Free();
      return;
    }
    obj->state = 1;
    obj->bank = 2;
    obj->clut = DAT_80159f66;
    wVar2 = DAT_8017034c;
    obj->draw_list = 6;
    obj->flip = 0;
    obj->hitbox = &DAT_80150d04;
    obj->box2 = &DAT_80150d04;
    obj->vram_base = wVar2;
    Anim_Set(obj,0x16);
    obj->speed_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0x4000;
    obj->field_0x43 = 0;
  }
  FUN_80129814(obj);
  iVar3 = Obj_HitboxOverlap(obj,&g_player);
  if (iVar3 == 0) {
    iVar3 = Obj_InActiveArea(obj);
    if (iVar3 == 0) {
      Obj_FreeDespawn(obj);
    }
    else {
      Anim_Step(obj);
      Obj_CullAndQueueDraw(obj);
    }
  }
  else {
    DAT_8016d2f0 = DAT_8016d2f0 + 1;
    *(byte *)((int)&DAT_8016d2f8 + obj->dmg_table + 3) =
         *(byte *)((int)&DAT_8016d2f8 + obj->dmg_table + 3) | obj->contact_dmg;
    FUN_800fd100(0x17);
    Obj_Free(obj);
  }
  return;
}


