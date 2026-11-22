// T2_29, STAGE07.BIN, handler 0x801DE3B8. Ghidra output with the object struct applied; not matching C.
// ---- 801de3b8 FUN_801de3b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de3b8(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e0b44)[obj->state])();
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_FreeDespawn(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
    FUN_80107bf4(obj,&g_player,5);
  }
  return;
}


// ---- 801de43c FUN_801de43c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de43c(MM8Obj *obj)

{
  byte bVar1;
  
  obj->state = 1;
                    /* Possible PsyQ macro: setTile1() + setSemiTrans(tile1, 1) */
  obj->bank = 0x6a;
  obj->vram_base = DAT_8017041c;
  bVar1 = DAT_80159fce;
  obj->draw_list = 9;
  obj->box2 = &DAT_801e0b3c;
  obj->clut = bVar1;
  if (obj->var == 0) {
    obj->flip = 0;
  }
  else {
                    /* Possible PsyQ macro: setLineF2() */
    obj->flip = 0x40;
  }
  Anim_Set(obj,0);
  obj->dmg_table = 0x20;
  obj->contact_dmg = 2;
  return;
}


// ---- 801de4d0 FUN_801de4d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de4d0(MM8Obj *obj)

{
  short sVar1;
  
  Anim_Step();
  obj->contact_dmg = obj->contact_dmg - 1;
  if (obj->contact_dmg == 0) {
    obj->contact_dmg = 2;
    if (obj->flip == 0) {
      sVar1 = obj->x + -1;
    }
    else {
      sVar1 = obj->x + 1;
    }
    obj->x = sVar1;
    obj->dmg_table = obj->dmg_table - 1;
    if (obj->dmg_table == 0) {
      obj->state = 2;
      obj->dmg_table = 0x3c;
    }
  }
  return;
}


