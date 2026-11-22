// ID 4F, STAGE09.BIN, handler 0x801D9210. Ghidra output with the object struct applied; not matching C.
// ---- 801d9210 FUN_801d9210

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9210(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801dba34)[obj->state])();
  if (obj->active != 0) {
    FUN_80103184(obj);
  }
  return;
}


// ---- 801d9270 FUN_801d9270

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9270(MM8Obj *obj)

{
  undefined1 *puVar1;
  
                    /* Probable PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setLineF2() */
  if ((DAT_801c336c == '\x03') && (DAT_801c3372 != '\0')) {
    puVar1 = &DAT_801d184c;
    do {
      Obj_Free(puVar1);
      puVar1 = puVar1 + 0x40;
    } while (puVar1 < &DAT_801d284c);
    Enemy_InitFromTable(obj);
    obj->state = 1;
                    /* Possible PsyQ macro: setSprt16() + setShadeTex(sprt16, 1) */
    obj->bank = 0x7d;
                    /* Possible PsyQ macro: setLineF2() */
    obj->flip = 0x40;
    obj->draw_list = 4;
    obj->field_0x49 = 7;
    *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
    obj->field_0x50 = 0;
    Anim_Set(obj,0x11);
    FUN_80103224(obj);
  }
  else {
    FUN_80102ecc(0);
    Obj_Free(obj);
  }
  return;
}


