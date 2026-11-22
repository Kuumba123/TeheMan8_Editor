// T2_17, STAGE02.BIN, handler 0x801E3DF4. Ghidra output with the object struct applied; not matching C.
// ---- 801e3df4 FUN_801e3df4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3df4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8a30)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDrawMargin(obj,0x38);
    FUN_80107bf4(obj,&g_player,1);
    if (obj->field_0x4a != '\x02') {
      if (obj->field_0x49 != '\0') {
        if ((obj->field_0x49 & 0x80) == 0) {
          FUN_800fd100();
          if (obj->field_0x4a != '\0') {
            obj->field_0x4a = 2;
          }
        }
        else {
          obj->target_prio = obj->target_prio - 1;
          if (obj->target_prio == 0) {
            obj->target_prio = 8;
            FUN_800fd100(0x71);
            obj->field_0x49 = 0;
            return;
          }
        }
      }
      obj->field_0x49 = 0;
    }
  }
  return;
}


// ---- 801e3ef0 FUN_801e3ef0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3ef0(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0x44;
  obj->vram_base = DAT_801703d0;
  bVar1 = DAT_80159fa8;
  obj->draw_list = 9;
  obj->box2 = &DAT_801e8a28;
  obj->speed_y_up = 0x10000;
  obj->state = 1;
  obj->target_prio = 8;
  obj->accel_x = 0;
  obj->gravity = 0;
  obj->dmg_table = 0;
  obj->field_0x4b = 0x10;
  obj->field_0x49 = 0;
  obj->field_0x4a = 0;
  obj->clut = bVar1;
  Anim_Set(obj,0);
  return;
}


// ---- 801e3f78 FUN_801e3f78

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3f78(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    if (((obj->x + -0x30 < (int)DAT_8015e248._2_2_) && (DAT_8015e27f == '\0')) &&
       ((DAT_8015e26f & 0x80) != 0)) {
      DAT_8015e2ba = 0;
      obj->sub2 = 1;
      DAT_8015e2af = 1;
      FUN_801119e0((int)obj->x,0x40);
    }
  }
  else if (obj->sub3 == 0) {
    iVar2 = 0x16b8;
    if (DAT_8015e248._2_2_ == obj->x) {
      do {
        iVar1 = 0x698;
        do {
          FUN_80103134((int)(short)iVar1,(int)(short)iVar2,0);
          iVar1 = iVar1 + 0x10;
        } while (iVar1 * 0x10000 >> 0x10 < 0x6f8);
        iVar2 = iVar2 + 0x10;
      } while (iVar2 * 0x10000 >> 0x10 < 0x1708);
      obj->accel_x = 0x20;
      obj->sub3 = 1;
      DAT_801d2926 = 0x6c0;
    }
  }
  else if (obj->accel_x == 0) {
    obj->accel_x = 0x58;
    obj->contact_dmg = 2;
    obj->state = 4;
    obj->sub2 = 0;
                    /* Possible PsyQ macro: setTile16() */
    obj->field_0x49 = 0x70;
  }
  else {
    obj->accel_x = obj->accel_x + -1;
  }
  return;
}


// ---- 801e4110 FUN_801e4110

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4110(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if (obj->field_0x4b == '\0') {
    obj->field_0x49 = 0xf1;
  }
  else {
    obj->field_0x4b = obj->field_0x4b + -1;
  }
  if (obj->accel_x == 0) {
    bVar1 = obj->dmg_table;
    obj->dmg_table = bVar1 + 1;
    if (bVar1 == 4) {
      FUN_801096b4(2,0x13);
      FUN_801096b4(1,0xb);
      FUN_801096b4(3,0x12);
      FUN_801096b4(2,0x17);
      iVar3 = 0x698;
      FUN_80111918();
      DAT_8015e2af = 0;
      iVar2 = 0x6980000;
      do {
        FUN_80103134(iVar2 >> 0x10,0x1588,1);
        iVar3 = iVar3 + 0x10;
        iVar2 = iVar3 * 0x10000;
      } while (iVar3 * 0x10000 >> 0x10 < 0x6f8);
      obj->state = 3;
    }
  }
  else {
    obj->accel_x = obj->accel_x + -1;
    FUN_80104d18(obj);
  }
  if (obj->gravity != 0) {
    obj->gravity = obj->gravity + -1;
    DAT_801d292c = DAT_801d292c + -1;
    DAT_801d292a = DAT_801d292a + -1;
  }
  bVar1 = obj->dmg_table;
  if (bVar1 == 1) {
    obj->gravity = 0x100;
    obj->accel_x = 0x100;
    obj->dmg_table = 2;
    bVar1 = obj->dmg_table;
  }
  if ((bVar1 == 2) && (obj->accel_x == 0x28)) {
    obj->dmg_table = 3;
    obj->contact_dmg = 2;
    obj->state = 4;
                    /* Possible PsyQ macro: setTile16() + setSemiTrans(tile16, 1) */
    obj->field_0x49 = 0x72;
    obj->sub2 = 0;
    obj->speed_y_up = 0;
    obj->field_0x4a = 1;
  }
  return;
}


