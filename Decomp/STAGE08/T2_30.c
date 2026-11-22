// T2_30, STAGE08.BIN, handler 0x801E08AC. Ghidra output with the object struct applied; not matching C.
// ---- 801e08ac FUN_801e08ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e08ac(MM8Obj *obj)

{
  word wVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (obj->state == 0) {
    Enemy_InitFromTable();
    obj->clut = DAT_80159fd7;
    wVar1 = DAT_8017042e;
    obj->bank = 0x73;
    obj->draw_list = 9;
    obj->hitbox = &DAT_801e135c;
    obj->flip = 0;
    obj->box2 = &DAT_801e1360;
    obj->state = obj->state + 1;
    obj->sub2 = 0;
    obj->vram_base = wVar1;
    Anim_Set(obj,0);
  }
  if (obj->sub2 != 0) {
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 != 0) {
      Anim_Set(obj,0);
      obj->sub2 = 0;
    }
  }
                    /* Possible PsyQ macro: setPolyG3() */
  if ((obj->anim_extra & 0xf) != 0) {
    FUN_80107bf4(obj,&g_player,1);
    iVar2 = FUN_80109804(obj);
    if (iVar2 == 3) {
      if ((obj->flip & 0x40) == 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
        if ((int)DAT_8015e248._2_2_ < obj->x + -0x18) goto LAB_801e09f4;
      }
      else if (obj->x + 0x18 < (int)DAT_8015e248._2_2_) {
LAB_801e09f4:
        obj->sub2 = 1;
      }
    }
  }
  iVar2 = FUN_80104820(obj,0x30,0x40);
  if (iVar2 == 0) {
    Obj_FreeDespawn(obj);
    return;
  }
  if ((obj->anim_extra & 0x10) == 0) {
    uVar3 = 0x121;
    if ((obj->anim_extra & 0x20) == 0) goto LAB_801e0a50;
  }
  else {
    uVar3 = 0x120;
  }
  FUN_8010544c(obj,uVar3);
LAB_801e0a50:
  Obj_CullAndQueueDrawMargin(obj,0x40);
  return;
}


