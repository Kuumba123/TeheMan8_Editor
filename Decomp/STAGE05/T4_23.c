// T4_23, STAGE05.BIN, handler 0x801E99E0. Ghidra output with the object struct applied; not matching C.
// ---- 801e99e0 FUN_801e99e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e99e0(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801eadfc)[obj->state])();
  return;
}


