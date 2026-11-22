// T4_28, STAGE05.BIN, handler 0x801E9ECC. Ghidra output with the object struct applied; not matching C.
// ---- 801e9ecc FUN_801e9ecc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9ecc(MM8Obj *obj)

{
  undefined1 uVar1;
  int iVar2;
  
  if (obj->state == 0) {
    DAT_801b29a7 = 0;
    *(undefined1 *)&obj->speed_x = 0;
    *(undefined1 *)((int)&obj->speed_x + 1) = 0;
    obj->state = obj->state + 1;
  }
  else if (obj->state == 1) {
    if (*(char *)((int)&obj->speed_x + 1) == '\0') {
      if ((&DAT_801eae08)[(uint)(byte)obj->speed_x * 2] == 0xff) {
        *(undefined1 *)((int)&obj->speed_x + 1) = 1;
        *(undefined1 *)&obj->speed_x = 0;
      }
      else {
        DAT_801b29a7 = (&DAT_801eae08)[(uint)(byte)obj->speed_x * 2] | DAT_801b29a7;
        uVar1 = (&DAT_801eae09)[(uint)(byte)obj->speed_x * 2];
        *(char *)&obj->speed_x = (char)obj->speed_x + '\x01';
        *(undefined1 *)((int)&obj->speed_x + 1) = uVar1;
      }
    }
    else {
      *(char *)((int)&obj->speed_x + 1) = *(char *)((int)&obj->speed_x + 1) + -1;
    }
  }
  iVar2 = FUN_80104820(obj,0x40,0x1e0);
  if (iVar2 == 0) {
    Obj_FreeDespawn(obj);
  }
  return;
}


