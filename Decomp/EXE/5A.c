// ID 5A handler in PSX.EXE at 0x80125A64 (same code in every stage that uses it)
// ---- 80125a64 FUN_80125a64

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80125a64(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_80150ae8)[obj->state])();
  return;
}


