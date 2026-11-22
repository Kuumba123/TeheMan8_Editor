// T2_26 handler in PSX.EXE at 0x801298E4 (same code in every stage)
// ---- 801298e4 FUN_801298e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801298e4(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_80150d24)[obj->state])();
  if (obj->active != 0) {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


