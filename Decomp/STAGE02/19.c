// ID 19, STAGE02.BIN, handler 0x801DB1BC. Ghidra output with the object struct applied; not matching C.
// ---- 801db1bc FUN_801db1bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db1bc(MM8Obj *obj)

{
  char cVar1;
  
  obj->invuln = 0;
  (*(code *)(&PTR_FUN_801e8684)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801db238 FUN_801db238

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db238(MM8Obj *obj)

{
  byte bVar1;
  
  Enemy_InitFromTable();
  bVar1 = obj->var;
  obj->state = 1;
  obj->field_0x51 = obj->dmg_table;
  if (bVar1 == 1) {
    Anim_Set(obj,0);
    FUN_8010910c(obj);
    obj->sub2 = 2;
    obj->field_0x50 = 0x14;
    obj->draw_list = 6;
    obj->box2 = &DAT_801e8600;
    obj->sub3 = 0;
    obj->hitbox = &DAT_801e8640;
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      Anim_Set(obj,4);
      FUN_8010910c(obj);
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->draw_list = 6;
      obj->box2 = &DAT_801e8600 + (obj->anim_extra & 0x7f) * 5;
      obj->hitbox = &DAT_801e8640 + (obj->anim_extra & 0x7f) * 4;
    }
  }
  else if (bVar1 == 2) {
    Anim_Set(obj,8);
    obj->speed_y_up = -0x20000;
    obj->draw_list = 5;
    obj->box2 = &DAT_801e8638;
    obj->hitbox = &DAT_801e866c;
    obj->contact_dmg = 3;
    obj->sub3 = 0;
    obj->hp = 1;
    obj->dmg_table = 2;
  }
  return;
}


// ---- 801db3a8 FUN_801db3a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db3a8(MM8Obj *obj)

{
  if (obj->clut == 0) {
    obj->clut = (&DAT_80159f64)[obj->bank];
  }
  (*(code *)(&PTR_FUN_801e8690)[obj->sub2])(obj);
  Enemy_ContactDamage(obj);
  if (obj->sub2 == 0) {
    obj->invuln = 1;
  }
  return;
}


// ---- 801db434 FUN_801db434

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db434(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 == '\x02') {
    obj->clut = 0;
    if ((obj->flip & 0x40) == 0) {
      obj->x = (short)(char)(&DAT_801e8670)[(obj->anim_extra & 0x7f) * 2] + obj->x;
    }
    else {
      obj->x = obj->x - (short)(char)(&DAT_801e8670)[(obj->anim_extra & 0x7f) * 2];
    }
    obj->y = (short)(char)(&DAT_801e8671)[(obj->anim_extra & 0x7f) * 2] + obj->y;
    Anim_Set(obj,5);
    obj->gravity = 0x4000;
    obj->sub2 = 1;
    obj->box2 = &DAT_801e8600;
    obj->sub3 = 0;
    obj->hitbox = &DAT_801e8640;
  }
  else if (cVar1 == '\x04') {
    obj->state = 2;
  }
  else {
    Anim_Step(obj);
    if (obj->sub3 == 0) {
      uVar5._0_1_ = obj->anim;
      uVar5._1_1_ = obj->anim_timer;
      uVar5._2_1_ = obj->anim_extra;
      uVar5._3_1_ = obj->field_0x33;
      if (((uVar5 & 0xffff00) == 0x70c00) &&
         (bVar2 = (obj->x < DAT_8015e248._2_2_) << 6, obj->flip != bVar2)) {
        obj->flip = bVar2;
        Anim_Set(obj,4);
      }
      uVar4._0_1_ = obj->anim;
      uVar4._1_1_ = obj->anim_timer;
      uVar4._2_1_ = obj->anim_extra;
      uVar4._3_1_ = obj->field_0x33;
      if (((uVar4 & 0xffff00) == 0x10c00) && (uVar5 = Rand(), (uVar5 & 1) != 0)) {
        Anim_Set(obj,7);
        obj->sub3 = 1;
        obj->field_0x4 = 0;
      }
      bVar2 = obj->anim_extra;
    }
    else {
      if (((obj->field_0x4 == '\0') && ((obj->anim_extra & 0x80) != 0)) &&
         (puVar6 = (undefined1 *)FUN_801055e4(obj), puVar6 != (undefined1 *)0x0)) {
        *puVar6 = 1;
        puVar6[6] = 0x19;
        puVar6[7] = 2;
        bVar2 = obj->flip;
        puVar6[1] = 0;
        puVar6[2] = 3;
        puVar6[0x25] = bVar2;
        *(undefined4 *)(puVar6 + 0xc) = *(undefined4 *)&obj->x_frac;
        *(undefined4 *)(puVar6 + 0x10) = *(undefined4 *)&obj->y_frac;
        if ((obj->flip & 0x40) == 0) {
          sVar3 = (short)DAT_801e8680;
        }
        else {
          sVar3 = -(short)DAT_801e8680;
        }
        *(short *)(puVar6 + 0xe) = *(short *)(puVar6 + 0xe) + sVar3;
        *(short *)(puVar6 + 0x12) = (short)DAT_801e8681 + *(short *)(puVar6 + 0x12);
        obj->field_0x4 = 1;
        FUN_8010544c(obj,500);
      }
      if (((int)(short)obj->frame & 0x8000U) == 0) {
        return;
      }
      Anim_SetAtStep(obj,4,1);
      bVar2 = obj->anim_extra;
      obj->sub3 = 0;
    }
    obj->box2 = &DAT_801e8600 + (uint)bVar2 * 5;
    obj->hitbox = &DAT_801e8640 + (uint)obj->anim_extra * 4;
  }
  return;
}


// ---- 801db754 FUN_801db754

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db754(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    obj->state = 2;
    return;
  }
  Anim_Step(obj);
  if (obj->sub3 == 0) {
    Obj_ApplySpeed(obj);
    if (obj->speed_y_up < -0x60000) {
      obj->speed_y_up = -0x60000;
      obj->gravity = 0;
    }
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      Anim_Set(obj,6);
      obj->sub3 = 1;
      obj->speed_y_up = 0;
      obj->gravity = 0;
    }
  }
  else if (((int)(short)obj->frame & 0x8000U) != 0) {
    Anim_Set(obj,0);
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->field_0x50 = 0x14;
  }
  return;
}


// ---- 801db844 FUN_801db844

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db844(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    obj->state = 2;
  }
  Anim_Step(obj);
  if (obj->sub3 == 0) {
    if (obj->field_0x50 == '\0') {
      Anim_Set(obj,1);
      iVar3 = 0x20000;
      obj->sub3 = 1;
      if ((obj->flip & 0x40) == 0) {
        iVar3 = -0x20000;
      }
      obj->field_0x50 = 0x78;
      obj->speed_x = iVar3;
      obj->field_0x54 = 10;
    }
    else {
      obj->field_0x50 = obj->field_0x50 + -1;
    }
  }
  else {
    FUN_80104c34(obj);
    FUN_80106214(obj);
    cVar1 = obj->field_0x54;
    obj->field_0x54 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->field_0x54 = 10;
      FUN_8010544c(obj,0x9c);
    }
    if ((obj->field_0x33 & 0x80) == 0) {
      Anim_Set(obj,5);
      obj->gravity = 0x4000;
      obj->speed_x = 0;
      obj->sub2 = 1;
      obj->sub3 = 0;
      return;
    }
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      bVar2 = (obj->x < DAT_8015e248._2_2_) << 6;
      if (obj->flip == bVar2) {
                    /* Possible PsyQ macro: setTile8() */
        obj->field_0x50 = 0x78;
        goto LAB_801db9e4;
      }
    }
    else {
      if ((obj->field_0x33 & 0x30) == 0) goto LAB_801db9e4;
      bVar2 = obj->flip ^ 0x40;
    }
    obj->flip = bVar2;
    Anim_Set(obj,0);
    obj->field_0x50 = 10;
    obj->sub3 = 0;
  }
LAB_801db9e4:
  obj->box2 = &DAT_801e8600 + (uint)obj->anim_extra * 5;
  obj->hitbox = &DAT_801e8640 + (uint)obj->anim_extra * 4;
  return;
}


// ---- 801dba2c FUN_801dba2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba2c(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  
  Anim_Step();
  FUN_80104c34(obj);
  if (DAT_8015e24c._2_2_ + -8 < (int)obj->y) {
    obj->state = 1;
    obj->sub2 = 4;
    obj->sub3 = 0;
    *(short *)&obj->field_0x52 = obj->y;
    puVar3 = (undefined1 *)FUN_801055e4(obj);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      bVar1 = obj->id;
      puVar3[7] = 2;
      puVar3[6] = bVar1;
      bVar1 = obj->flip;
      puVar3[1] = 0;
      puVar3[2] = 4;
      puVar3[0x25] = bVar1;
      *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)&obj->y_frac;
      *(short *)(puVar3 + 0x52) = obj->y + 8;
      puVar3 = (undefined1 *)FUN_801055e4();
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        bVar1 = obj->id;
        puVar3[7] = 2;
        puVar3[6] = bVar1;
        bVar1 = obj->flip;
        puVar3[1] = 0;
        puVar3[2] = 4;
        puVar3[0x25] = bVar1;
        *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
        *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)&obj->y_frac;
        *(short *)(puVar3 + 0x52) = obj->y + 0x10;
      }
    }
  }
  cVar2 = Enemy_CheckWeaponHits(obj);
  if (cVar2 == '\x02') {
    obj->clut = 0;
  }
  else if ((cVar2 == '\x04') || (FUN_80106214(obj), obj->field_0x33 != '\0')) {
    obj->state = 2;
  }
  return;
}


// ---- 801dbba0 FUN_801dbba0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbba0(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  Anim_Step();
  FUN_80104c34(obj);
  if ((obj->sub3 == 0) && (iVar2 = 0x30000, *(short *)&obj->field_0x52 < obj->y)) {
    obj->speed_y_up = 0;
    if ((obj->flip & 0x40) == 0) {
      iVar2 = -0x30000;
    }
    obj->speed_x = iVar2;
    Anim_Set(obj,8);
    obj->sub3 = 1;
  }
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if ((cVar1 == '\x04') || (FUN_80106214(obj), obj->field_0x33 != '\0')) {
    obj->state = 2;
  }
  return;
}


// ---- 801dbc6c FUN_801dbc6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbc6c(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
  iVar2 = (obj->anim_extra & 0x7f) * 2;
  FUN_80108ed8(obj,(int)(char)(&DAT_801e8670)[iVar2],(int)(char)(&DAT_801e8671)[iVar2]);
  if (obj->var == 2) {
    Obj_Free(obj);
  }
  else {
    iVar2 = (obj->anim_extra & 0x7f) * 2;
    FUN_8012a724(obj,0,(int)(char)(&DAT_801e8670)[iVar2],(int)(char)(&DAT_801e8671)[iVar2]);
    iVar2 = FUN_80108fd8(obj,0);
    if (iVar2 != 0) {
      if ((obj->flip & 0x40) == 0) {
        sVar1 = (short)(char)(&DAT_801e8670)[(obj->anim_extra & 0x7f) * 2];
      }
      else {
        sVar1 = -(short)(char)(&DAT_801e8670)[(obj->anim_extra & 0x7f) * 2];
      }
      *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + sVar1;
      *(short *)(iVar2 + 0x12) =
           (short)(char)(&DAT_801e8671)[(obj->anim_extra & 0x7f) * 2] + *(short *)(iVar2 + 0x12);
    }
    Obj_FreeDespawn(obj);
  }
  return;
}


