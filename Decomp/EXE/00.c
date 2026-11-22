// ID 00 handler in PSX.EXE at 0x80122734 (same code in every stage that uses it)
// ---- 80122734 FUN_80122734

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80122734(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_8015093c)[obj->state])();
  return;
}


