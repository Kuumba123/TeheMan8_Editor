// T3_27, STAGE05.BIN, handler 0x801E8A00. Ghidra output with the object struct applied; not matching C.
// ---- 801e8a00 FUN_801e8a00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8a00(MM8Obj *obj)

{
  int iVar1;
  
  Obj_ApplySpeed();
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_Free(obj);
  }
  else if ((*(char *)&obj->box2 == '\0') || ((DAT_80170574 & 1) != 0)) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


