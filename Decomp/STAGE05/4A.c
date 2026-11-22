// ID 4A, STAGE05.BIN, handler 0x801E09F0. Ghidra output with the object struct applied; not matching C.
// ---- 801e09f0 FUN_801e09f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e09f0(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801ea678)[obj->state])();
  obj->clut = (&DAT_80159f64)[obj->bank];
  Enemy_ContactDamage(obj);
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    FUN_80108fd8(obj,0);
    goto LAB_801e0aac;
  }
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    return;
  }
LAB_801e0aac:
  Obj_Free(obj);
  return;
}


// ---- 801e0ac8 FUN_801e0ac8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0ac8(MM8Obj *obj)

{
  byte bVar1;
  
  Enemy_InitFromTable();
  obj->draw_list = 5;
  obj->state = 1;
  obj->flip = 0;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->hitbox = &DAT_801ea674;
  obj->box2 = (byte *)0x0;
  Anim_Set(obj,0);
  obj->field_0x50 = 0x3c;
  bVar1 = Rand();
  obj->field_0x51 = bVar1 & 3;
  obj->gravity = -0x1000;
  obj->accel_x = -((uint)(byte)obj->field_0x51 * 0x400 + 0x2000);
  return;
}


// ---- 801e0b58 FUN_801e0b58

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0b58(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  Obj_ApplySpeed();
  if (obj->sub3 == 0) {
    iVar2 = -((uint)(byte)obj->field_0x51 * 0x4000 + 0x20000);
    if (obj->speed_x < iVar2) {
      obj->speed_x = iVar2;
      obj->accel_x = 0;
    }
  }
  else {
    if (0 < obj->speed_x) {
      obj->speed_x = 0;
      obj->accel_x = 0;
    }
    if (0x3000 < obj->speed_y_up) {
      obj->speed_y_up = 0x3000;
      obj->gravity = 0;
    }
  }
  if (((int)(short)obj->frame & 0x8000U) != 0) {
    uVar3 = Rand();
                    /* Possible PsyQ macro: setTile8() */
    if ((uVar3 & 3) == 3) {
      uVar4 = 3;
    }
    else {
      uVar4 = 0;
    }
    Anim_Set(obj,uVar4);
  }
  cVar1 = obj->field_0x50;
  obj->field_0x50 = cVar1 + -1;
  if (cVar1 == '\0') {
    obj->sub3 = 1;
    uVar3 = Rand();
    obj->accel_x = (uVar3 & 3) * 0x400 + 0x2000;
  }
  Anim_Step(obj);
  return;
}


