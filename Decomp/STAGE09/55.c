// ID 55, STAGE09.BIN, handler 0x801DB0D0. Ghidra output with the object struct applied; not matching C.
// ---- 801db0d0 FUN_801db0d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db0d0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801dbb10)[obj->state])();
  return;
}


// ---- 801db10c FUN_801db10c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db10c(MM8Obj *obj)

{
  byte bVar1;
  
  Enemy_InitFromTable();
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  obj->state = obj->var + 1;
  bVar1 = (&DAT_801dbb08)[obj->var];
  obj->invuln = 1;
  obj->hitbox = &DAT_801dbb0c;
  obj->field_0x54 = 0;
  obj->contact_dmg = 6;
  obj->draw_list = bVar1;
  Anim_Set(obj,(&DAT_801dbb04)[obj->var]);
  return;
}


// ---- 801db18c FUN_801db18c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db18c(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  iVar1 = *(int *)&obj->field_0x50;
  obj->x = *(short *)(iVar1 + 0xe);
  obj->y = *(short *)(iVar1 + 0x12) + 0x28;
  if (*(char *)(iVar1 + 0x54) != '\0') {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


