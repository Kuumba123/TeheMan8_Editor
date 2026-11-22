// ID 3E, STAGE06.BIN, handler 0x801DF3BC. Ghidra output with the object struct applied; not matching C.
// ---- 801df3bc FUN_801df3bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df3bc(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e5a20)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801df438 FUN_801df438

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df438(MM8Obj *obj)

{
  bool bVar1;
  
  Enemy_InitFromTable();
  obj->draw_list = 7;
  obj->hitbox = &DAT_801e5a10;
  obj->box2 = &DAT_801e5a18;
  obj->field_0x43 = 1;
  obj->state = 1;
  bVar1 = obj->y + -0x10 < (int)DAT_801b2988;
  if (bVar1) {
    obj->sub2 = 1;
  }
  else {
    obj->sub2 = 0;
  }
  obj->sub3 = 0;
  Anim_Set(obj,bVar1);
  obj->flip = 0;
  return;
}


// ---- 801df4c8 FUN_801df4c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df4c8(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e5a2c)[obj->sub2])();
  obj->hitbox = &DAT_801e5a10 + (uint)obj->anim_extra * 4;
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    FUN_80108e84(obj);
    FUN_80108fd8(obj,0);
    FUN_8012a5fc(obj,0);
    Obj_FreeDespawn(obj);
    return;
  }
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801df59c FUN_801df59c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df59c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = obj->sub3;
  if (bVar2 != 1) {
    if (1 < bVar2) {
      if ((bVar2 == 2) && (cVar1 = obj->field_0x50, obj->field_0x50 = cVar1 + -1, cVar1 == '\0')) {
        Anim_Set(obj,3);
        FUN_8010544c(obj,0x10e);
        obj->sub2 = 3;
        obj->sub3 = 0;
      }
      goto LAB_801df7d4;
    }
    if (bVar2 != 0) goto LAB_801df7d4;
    bVar2 = Rand();
    obj->field_0x50 = (bVar2 & 0x3f) + 0xb4;
    obj->accel_x = 0x200;
    obj->gravity = 0x400;
    obj->field_0x51 = 0;
    obj->speed_x = 0;
    obj->speed_y_up = 0;
    obj->sub3 = 1;
  }
  Obj_ApplySpeed(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0xf0) == 0) {
    iVar3 = obj->speed_x;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (0x7fff < iVar3) {
      obj->accel_x = -obj->accel_x;
    }
    iVar3 = obj->speed_y_up;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (0x3fff < iVar3) {
      obj->gravity = -obj->gravity;
    }
  }
  else {
    if (((obj->field_0x33 & 0x30) != 0) && (obj->speed_x != 0)) {
      if (-1 < (obj->speed_x ^ obj->accel_x)) {
        obj->accel_x = -obj->accel_x;
      }
      obj->speed_x = 0;
    }
    if (((obj->field_0x33 & 0xc0) != 0) && (obj->speed_y_up != 0)) {
      if ((obj->speed_y_up ^ obj->gravity) < 0) {
        obj->gravity = -obj->gravity;
      }
      obj->speed_y_up = 0;
    }
  }
  if (obj->y + -0x10 < (int)DAT_801b2988) {
    if (-1 < obj->speed_y_up) {
      obj->speed_y_up = 0;
    }
    if ((obj->gravity & 0x80000000U) != 0) {
      obj->gravity = 0x400;
    }
  }
  cVar1 = obj->field_0x50;
  obj->field_0x50 = cVar1 + -1;
  if (cVar1 == '\0') {
    obj->field_0x50 = 0xf;
    obj->sub3 = 2;
    obj->speed_x = 0;
    obj->speed_y_up = 0;
    obj->accel_x = 0;
    obj->gravity = 0;
  }
LAB_801df7d4:
  Anim_Step(obj);
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  return;
}


// ---- 801df7f0 FUN_801df7f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df7f0(MM8Obj *obj)

{
  uint uVar1;
  int iVar2;
  
  if (obj->sub3 == 0) {
    obj->gravity = 0x4000;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->sub3 = 1;
  }
  Obj_ApplySpeed(obj);
  FUN_80106214(obj);
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->field_0x43 = 1;
  }
  else {
    obj->gravity = 0x4000;
    obj->field_0x43 = 0;
    obj->speed_y_up = 0x30000;
    uVar1 = Rand();
    iVar2 = 0x8000;
    if ((uVar1 & 1) != 0) {
      iVar2 = -0x8000;
    }
    obj->speed_x = iVar2;
    FUN_8010544c(obj,0x10f);
  }
  if ((obj->field_0x33 & 0x40) != 0) {
    obj->speed_y_up = 0;
    obj->gravity = 0x4000;
  }
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->speed_x = 0;
  }
  if ((int)DAT_801b2988 <= obj->y + -0x10) {
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x43 = 1;
    Anim_Set(obj,0);
  }
  Anim_Step(obj);
  return;
}


