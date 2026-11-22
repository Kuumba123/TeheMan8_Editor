// T2_33 handler in PSX.EXE at 0x80129E04 (same code in every stage)
// ---- 80129e04 FUN_80129e04

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80129e04(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_80150d48)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


