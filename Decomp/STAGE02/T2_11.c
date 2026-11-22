// T2_11, STAGE02.BIN, handler 0x801E3394. Ghidra output with the object struct applied; not matching C.
// ---- 801e3394 FUN_801e3394

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3394(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e89f0)[obj->state])(obj,&g_player);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e33e8 FUN_801e33e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e33e8(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  
                    /* Possible PsyQ macro: setLineF2() + setSemiTrans(lineF2, 1) */
  obj->bank = 0x42;
  obj->vram_base = DAT_801703cc;
  obj->clut = DAT_80159fa6;
  bVar2 = 9;
  if (obj->var == 3) {
    bVar2 = 5;
  }
  bVar1 = 4;
  obj->draw_list = bVar2;
  obj->dmg_table = 0;
  obj->contact_dmg = 0;
  if (obj->var == 0) {
    bVar1 = 1;
  }
  obj->state = bVar1;
  Anim_Set(obj,obj->var);
  return;
}


