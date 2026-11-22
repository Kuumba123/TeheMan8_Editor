// T3_11, STAGE06.BIN, handler 0x801E50D0. Ghidra output with the object struct applied; not matching C.
// ---- 801e50d0 FUN_801e50d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e50d0(MM8Obj *obj)

{
  if (0x500 < DAT_8015e24c._2_2_) {
    obj->state = obj->state + 1;
    FUN_80111918();
    *(undefined1 *)&obj->speed_x = 0x3c;
    DAT_801b2992 = 0;
    DAT_801b2993 = 0;
    DAT_801b2994 = 0;
  }
  return;
}


