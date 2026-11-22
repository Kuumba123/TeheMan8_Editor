// T2_00 handler in PSX.EXE at 0x801288E8 (same code in every stage)
// ---- 801288e8 FUN_801288e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801288e8(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_LAB_80150c14)[obj->state])();
  if (obj->active != 0) {
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_FreeDespawn(obj);
    }
    else if ((0x3b < obj->dmg_table) || ((obj->dmg_table & 1) == 0)) {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


