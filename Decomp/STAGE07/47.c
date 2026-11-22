// ID 47, STAGE07.BIN, handler 0x801DA580. Ghidra output with the object struct applied; not matching C.
// ---- 801da580 FUN_801da580

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da580(MM8Obj *obj)

{
  char cVar1;
  
  obj->invuln = 0;
  (*(code *)(&PTR_FUN_801e0930)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    obj->clut = (&DAT_80159f64)[obj->bank];
    cVar1 = Enemy_CheckWeaponHits(obj);
    if (cVar1 != '\0') {
      if (cVar1 == '\x04') {
        obj->state = 6;
        obj->sub2 = 0;
      }
      else {
        obj->clut = 0;
      }
    }
    obj->invuln = 1;
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801da644 FUN_801da644

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da644(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 7;
  obj->state = 1;
  obj->hitbox = &DAT_801e08fc;
  obj->box2 = &DAT_801e0928;
  obj->field_0x43 = 0;
  obj->flip = 0;
  obj->sub2 = 0;
  obj->field_0x54 = 0;
  obj->field_0x52 = 0x1e;
  Anim_Set(obj,0);
  FUN_80106214(obj);
  return;
}


