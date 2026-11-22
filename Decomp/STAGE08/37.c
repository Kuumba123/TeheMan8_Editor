// ID 37, STAGE08.BIN, handler 0x801D9270. Ghidra output with the object struct applied; not matching C.
// ---- 801d9270 FUN_801d9270

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9270(MM8Obj *obj)

{
  char cVar1;
  
                    /* Probable PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801e0fc8)[obj->state])();
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    FUN_80108fd8(obj,4);
    goto LAB_801d932c;
  }
  Enemy_ContactDamage(obj);
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    return;
  }
LAB_801d932c:
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801d9348 FUN_801d9348

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9348(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  iVar1 = -0x20000;
  obj->draw_list = 5;
  obj->hitbox = &DAT_801e0fbc;
  obj->box2 = &DAT_801e0fc0;
  obj->state = 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x52 = 0;
  if ((obj->flip & 0x40) != 0) {
    iVar1 = 0x20000;
  }
  obj->speed_x = iVar1;
  *(short *)&obj->field_0x50 = obj->y;
  Anim_Set(obj,0);
  return;
}


// ---- 801d93d0 FUN_801d93d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d93d0(MM8Obj *obj)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = (uint)(byte)obj->field_0x52;
  cVar2 = obj->field_0x52 + 1;
  if ((uVar3 & 0x7f) < 0x40) {
    obj->field_0x52 = cVar2;
    uVar3 = uVar3 & 0x3f;
  }
  else {
    obj->field_0x52 = cVar2;
    uVar3 = 0x40 - (uVar3 & 0x3f);
  }
  uVar1 = *(ushort *)(&DAT_801395f0 + uVar3 * 2);
  obj->y = *(short *)&obj->field_0x50;
  *(uint *)&obj->y_frac = (uint)uVar1 * 0x40 + *(int *)&obj->y_frac;
  FUN_80104c34(obj);
  Anim_Step(obj);
  return;
}


