// ID 20 handler in PSX.EXE at 0x8012466C (same code in every stage that uses it)
// ---- 8012466c FUN_8012466c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_8012466c(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_LAB_80150a44)[obj->state])();
  if (obj->state != 2) {
    obj->clut = (&DAT_80159f64)[obj->bank];
    cVar1 = Enemy_CheckWeaponHits(obj);
    if (cVar1 == '\x02') {
      obj->clut = 0;
    }
    else if (cVar1 == '\x04') {
      obj->state = 2;
    }
    Enemy_ContactDamage(obj);
    Obj_CullAndQueueDraw(obj);
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


