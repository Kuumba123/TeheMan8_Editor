// ID 21 handler in PSX.EXE at 0x80124E10 (same code in every stage that uses it)
// ---- 80124e10 FUN_80124e10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80124e10(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_LAB_80150aac)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  if ((obj->var != 3) && (iVar1 = Obj_InActiveArea(obj), iVar1 == 0)) {
    Obj_FreeDespawn(obj);
  }
  return;
}


