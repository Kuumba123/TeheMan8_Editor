// ID 5F, STAGE0C.BIN, handler 0x801E97D8. Ghidra output with the object struct applied; not matching C.
// ---- 801e97d8 FUN_801e97d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e97d8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eb07c)[obj->state])();
  return;
}


// ---- 801e9814 FUN_801e9814

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9814(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->field_0x55 = 0;
  obj->flip = 0;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->state = obj->var + 1;
  obj->draw_list = 7;
  (*(code *)(&PTR_FUN_801eb07c)[obj->state])(obj);
  return;
}


// ---- 801e9884 FUN_801e9884

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9884(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = DAT_801b29a5 & 0x7f;
  bVar1 = obj->sub2;
  if ((DAT_801b29a5 & 0x80) != 0) {
    DAT_801b29a5 = bVar2;
    obj->sub2 = bVar2;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    bVar1 = DAT_801b29a5;
  }
  (*(code *)(&PTR_LAB_801eb094)[bVar1])(obj);
  if ((obj->active != 0) && (obj->field_0x55 != '\0')) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e9ea4 FUN_801e9ea4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Possible GS_106.OBJ/GsSetProjection
   Possible _OP_VDEL.OBJ/__builtin_vec_delete
   Possible _OP_VNEW.OBJ/__builtin_vec_new
   Possible SCNOFF.OBJ/SsSetNoiseOff
   Possible SSQUIT.OBJ/SsQuit */

void FUN_801e9ea4(MM8Obj *obj)

{
  Obj_Free();
  return;
}


