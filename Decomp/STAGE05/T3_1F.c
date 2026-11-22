// T3_1F, STAGE05.BIN, handler 0x801E82E4. Ghidra output with the object struct applied; not matching C.
// ---- 801e82e4 FUN_801e82e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e82e4(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801eaa5c)[obj->state])();
  return;
}


