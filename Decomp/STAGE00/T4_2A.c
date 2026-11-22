// T4_2A, STAGE00.BIN, handler 0x801E17B0. Ghidra output with the object struct applied; not matching C.
// ---- 801e17b0 FUN_801e17b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e17b0(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->state == 0) {
    if ((DAT_801b29a1 & 0x80) == 0) {
      obj->sub2 = 0;
    }
    else {
      obj->sub2 = 1;
      *(undefined1 *)&obj->speed_x = 0x32;
    }
    obj->state = 1;
  }
  if (obj->sub2 == 0) {
    if ((DAT_801b29a1 & 0x80) != 0) {
      FUN_8010544c(obj,0x5c);
      obj->sub2 = 1;
      *(undefined1 *)&obj->speed_x = 0x5a;
    }
  }
  else {
    cVar1 = (char)obj->speed_x;
    *(char *)&obj->speed_x = cVar1 + -1;
    if (cVar1 == '\0') {
      *(undefined1 *)&obj->speed_x = 0x32;
      FUN_8010544c(obj,0x5d);
    }
  }
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


