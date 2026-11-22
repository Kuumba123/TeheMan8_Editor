// ID 32, STAGE05.BIN, handler 0x801DCBA4. Ghidra output with the object struct applied; not matching C.
// ---- 801dcba4 FUN_801dcba4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcba4(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  (*(code *)(&PTR_FUN_801ea440)[obj->state])();
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar2 = Enemy_CheckWeaponHits(obj);
  if (cVar2 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar2 == '\x04') {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    FUN_80108fd8(obj,0);
    bVar1 = obj->sub2;
    goto joined_r0x801dcc40;
  }
  if (((obj->field_0x4 == '\x01') && (DAT_8015e27f != '\0')) || (obj->field_0x4 == '\0')) {
    Enemy_ContactDamage(obj);
  }
  Obj_CullAndQueueDraw(obj);
  cVar2 = Obj_InActiveArea(obj);
  if (cVar2 != '\0') {
    return;
  }
  bVar1 = obj->sub2;
joined_r0x801dcc40:
  if (bVar1 == 4) {
    FUN_80111c28();
  }
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801dccd8 FUN_801dccd8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dccd8(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 5;
  obj->hitbox = &DAT_801ea428;
  obj->flip = 0;
  obj->state = 1;
  obj->box2 = &DAT_801ea430;
  if (obj->var == 0) {
    Anim_Set(obj,1);
    obj->dmg_table = 1;
    *(undefined2 *)&obj->field_0x54 = 0x50;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  else {
    Anim_Set(obj,0);
    obj->dmg_table = 2;
    obj->sub2 = 2;
    obj->sub3 = 3;
    obj->field_0x4 = 0;
    *(undefined2 *)&obj->field_0x54 = 0x50;
  }
  return;
}


// ---- 801dcd90 FUN_801dcd90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcd90(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801ea44c)[obj->sub2])();
  return;
}


