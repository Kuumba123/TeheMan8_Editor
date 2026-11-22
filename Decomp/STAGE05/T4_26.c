// T4_26, STAGE05.BIN, handler 0x801E9E54. Ghidra output with the object struct applied; not matching C.
// ---- 801e9e54 FUN_801e9e54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9e54(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->state == 0) {
    *(undefined1 *)&obj->speed_x = 0;
    *(undefined1 *)((int)&obj->speed_x + 1) = 0;
    obj->state = 1;
  }
  DAT_801b29a0 = 0;
  if ((char)obj->speed_x == '\0') {
    cVar1 = *(char *)((int)&obj->speed_x + 1);
                    /* Possible PsyQ macro: setPolyGT4() */
    *(undefined1 *)&obj->speed_x = 0x3c;
    *(byte *)((int)&obj->speed_x + 1) = cVar1 - 1U & 3;
    DAT_801b29a0 = (undefined1)(1 << (*(byte *)((int)&obj->speed_x + 1) & 0x1f));
  }
  else {
    *(char *)&obj->speed_x = (char)obj->speed_x + -1;
  }
  return;
}


