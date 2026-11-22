// T2_05, STAGE01.BIN, handler 0x801E38F8. Ghidra output with the object struct applied; not matching C.
// ---- 801e38f8 FUN_801e38f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e38f8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6e6c)[obj->state])();
  if ((obj->field_0x4a != '\0') && (DAT_8015e283 == '\0')) {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,6);
    obj->field_0x49 = 1;
  }
  obj->field_0x4a = DAT_8015e283;
  return;
}


// ---- 801e3990 FUN_801e3990

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3990(MM8Obj *obj)

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


// ---- 801e3a70 FUN_801e3a70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3a70(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6e7c)[obj->sub2])();
  if (obj->field_0x49 == '\0') {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e3ad0 FUN_801e3ad0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3ad0(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = FUN_80104d30(obj,&g_player,0x20);
  if (iVar1 != 0) {
    obj->sub2 = 1;
    FUN_801119e0((int)obj->x,0x40);
  }
  return;
}


