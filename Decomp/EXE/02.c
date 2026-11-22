// ID 02 handler in PSX.EXE at 0x80123164 (same code in every stage that uses it)
// ---- 80123164 FUN_80123164

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80123164(MM8Obj *obj)

{
  int iVar1;
  
  obj->clut = obj->field_0x55;
  (*(code *)(&PTR_LAB_801509ac)[obj->state])();
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_FreeDespawn(obj);
  }
  else if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


