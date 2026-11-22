// T2_22 handler in PSX.EXE at 0x80129240 (same code in every stage)
// ---- 80129240 FUN_80129240

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80129240(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_LAB_80150cec)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


