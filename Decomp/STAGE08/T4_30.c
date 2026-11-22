// T4_30, STAGE08.BIN, handler 0x801E0C6C. Ghidra output with the object struct applied; not matching C.
// ---- 801e0c6c FUN_801e0c6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0c6c(MM8Obj *obj)

{
  char cVar1;
  
  if (DAT_8015e248._2_2_ < obj->x) {
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      Obj_FreeDespawn(obj);
    }
  }
  else {
    DAT_801b2995 = 0x80;
    DAT_8015e2af = 1;
    Obj_Free();
  }
  return;
}


