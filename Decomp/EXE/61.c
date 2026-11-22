// ID 61 handler in PSX.EXE at 0x80128568 (same code in every stage that uses it)
// ---- 80128568 FUN_80128568

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80128568(MM8Obj *obj)

{
  if (obj->var < 4) {
    FUN_801285f0();
  }
  else {
    FUN_801287dc();
  }
  return;
}


