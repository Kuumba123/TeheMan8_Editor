// ID 22, STAGE0C.BIN, handler 0x801DA904. Ghidra output with the object struct applied; not matching C.
// ---- 801da904 FUN_801da904

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da904(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801eaa4c)[obj->state])();
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
                    /* Possible PsyQ macro: setSprt16() + setSemiTrans(sprt16, 1) +
                       setShadeTex(sprt16, 1) */
    FUN_80108fd8(obj,0);
    goto LAB_801da9c0;
  }
  Enemy_ContactDamage(obj);
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    return;
  }
LAB_801da9c0:
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801da9dc FUN_801da9dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da9dc(MM8Obj *obj)

{
  uint uVar1;
  undefined1 uVar2;
  
  Enemy_InitFromTable();
  obj->draw_list = 5;
  obj->hitbox = &DAT_801eaa40;
  obj->flip = 0;
  obj->state = 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->box2 = &DAT_801eaa44;
  if (obj->var == 0) {
    Anim_Set(obj,1);
    obj->dmg_table = 1;
    uVar1 = Rand();
    uVar2 = 0x78;
    if ((uVar1 & 1) != 0) {
      uVar2 = 0x3c;
    }
    obj->field_0x50 = uVar2;
  }
  else {
    obj->sub2 = 2;
    obj->sub3 = 3;
    Anim_Set(obj,0);
    obj->dmg_table = 2;
    obj->field_0x50 = 0;
  }
  return;
}


// ---- 801daa98 FUN_801daa98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daa98(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801eaa58)[obj->sub2])();
  return;
}


