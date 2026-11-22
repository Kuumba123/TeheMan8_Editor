// T4_24, STAGE00.BIN, handler 0x801E12CC. Ghidra output with the object struct applied; not matching C.
// ---- 801e12cc FUN_801e12cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e12cc(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e2980)[obj->state])();
  return;
}


