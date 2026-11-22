// T2_2F handler in PSX.EXE at 0x80129B7C (same code in every stage)
// ---- 80129b7c FUN_80129b7c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80129b7c(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_80150d34)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


