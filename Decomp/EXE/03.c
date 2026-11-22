// ID 03 handler in PSX.EXE at 0x80123FA8 (same code in every stage that uses it)
// ---- 80123fa8 FUN_80123fa8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_80123fa8(MM8Obj *obj)

{
  char cVar1;
  
  obj->clut = obj->field_0x50;
  (*(code *)(&PTR_LAB_80150a08)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  if ((obj->field_0x52 == '\x01') && (DAT_801d2918._2_2_ == 0xec0)) {
    obj->speed_x = -0x8000;
  }
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_FreeDespawn(obj);
  }
  else if (obj->field_0x54 != '\0') {
    Obj_Free(obj);
  }
  return;
}


