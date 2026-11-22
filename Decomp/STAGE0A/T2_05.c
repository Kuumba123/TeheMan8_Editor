// T2_05, STAGE0A.BIN, handler 0x801E0A24. Ghidra output with the object struct applied; not matching C.
// ---- 801e0a24 FUN_801e0a24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0a24(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e219c)[obj->state])();
  if ((obj->field_0x4a != '\0') && (DAT_8015e283 == '\0')) {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,6);
    obj->field_0x49 = 1;
  }
  obj->field_0x4a = DAT_8015e283;
  return;
}


// ---- 801e0abc FUN_801e0abc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0abc(MM8Obj *obj)

{
  byte bVar1;
  
  obj->state = 1;
  obj->bank = 0x1d;
  obj->vram_base = DAT_80170382;
  bVar1 = DAT_80159f81;
  obj->draw_list = 6;
                    /* Possible PsyQ macro: setLineF2() */
  obj->flip = 0x40;
  obj->field_0x49 = 0;
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->clut = bVar1;
  obj->field_0x4a = DAT_8015e283;
  if (obj->var == 2) {
    obj->invuln = 10;
    obj->hp = 7;
    obj->target_prio = 10;
  }
  else if (obj->var == 1) {
    obj->invuln = 7;
    obj->hp = 4;
    obj->target_prio = 4;
  }
  else {
    obj->invuln = 0;
    obj->hp = 0;
    obj->target_prio = 0;
  }
  DAT_8015e2ba = 1;
  Anim_Set(obj,0);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e0b9c FUN_801e0b9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0b9c(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  (*(code *)(&PTR_FUN_801e21ac)[obj->sub2])();
  if (obj->field_0x49 == '\0') {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e0bfc FUN_801e0bfc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0bfc(MM8Obj *obj)

{
  int iVar1;
  
                    /* Possible PsyQ macro: setTile8() */
  iVar1 = FUN_80104d30(obj,&g_player,0x20);
  if (iVar1 != 0) {
    obj->sub2 = 1;
    FUN_801119e0((int)obj->x,0x40);
  }
  return;
}


