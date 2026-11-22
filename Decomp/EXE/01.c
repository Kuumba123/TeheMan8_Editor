// ID 01 handler in PSX.EXE at 0x801228E8 (same code in every stage that uses it)
// ---- 801228e8 FUN_801228e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801228e8(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_LAB_80150958)[obj->state])();
  if (obj->field_0x53 == '\0') {
    obj->dmg_table = 2;
    obj->hitbox = &DAT_80150950;
  }
  else {
    obj->dmg_table = 1;
    obj->hitbox = &DAT_80150954;
  }
  iVar1 = Enemy_CheckWeaponHits(obj);
  if (iVar1 == 4) {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    FUN_80108fd8(obj,0);
    FUN_80105888(obj);
  }
  else {
    Enemy_ContactDamage(obj);
    Obj_CullAndQueueDraw(obj);
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


