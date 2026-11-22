// ID 52, STAGE0A.BIN, handler 0x801DFC70. Ghidra output with the object struct applied; not matching C.
// ---- 801dfc70 FUN_801dfc70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfc70(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e1f98)[obj->state])();
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  if (obj->active != 0) {
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_Free(obj);
    }
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801dfce8 FUN_801dfce8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfce8(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar1 = obj->var;
  Enemy_InitFromTable();
  obj->draw_list = 9;
  obj->field_0x43 = 1;
  iVar3 = (uint)bVar1 * 3;
  obj->hp = (&DAT_801e1fd0)[iVar3];
  obj->contact_dmg = (&DAT_801e1fd1)[iVar3];
  bVar2 = (&DAT_801e1fd2)[iVar3];
  obj->field_0x50 = 0;
  obj->dmg_table = bVar2;
  if (bVar1 == 0) {
    *(short *)&obj->field_0x4a = obj->y;
  }
  else {
    *(short *)&obj->field_0x4a = obj->x;
  }
  Anim_Set(obj,(&DAT_801e1fcc)[bVar1]);
  obj->state = bVar1 + 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  (*(code *)(&PTR_FUN_801e1f98)[obj->state])(obj);
  return;
}


// ---- 801dfde0 FUN_801dfde0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfde0(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    obj->hitbox = &DAT_801e1fac;
    obj->box2 = &DAT_801e1fac;
    obj->draw_list = 9;
    obj->speed_y_up = -0x10000;
    bVar1 = obj->sub2;
    iVar3 = 0x4000;
  }
  else {
    if ((obj->sub2 != 1) || (bVar1 = FUN_80107204((int)obj->x,obj->y + 0x18), bVar1 < 0x30))
    goto LAB_801dfe9c;
    obj->draw_list = 8;
    FUN_8010910c(obj);
    iVar3 = 0x20000;
    if ((obj->flip & 0x40) == 0) {
      iVar3 = -0x20000;
    }
    obj->speed_x = iVar3;
    obj->speed_y_up = -0x1e00;
    bVar1 = obj->sub2;
    iVar3 = 0x200;
    obj->accel_x = 0;
  }
  obj->gravity = iVar3;
  obj->sub2 = bVar1 + 1;
LAB_801dfe9c:
  Anim_Step(obj);
  FUN_80104ccc(obj);
  if (obj->sub2 < 2) {
    if (obj->speed_y_up < -0x4ffff) {
      obj->speed_y_up = -0x50000;
    }
  }
  else if (0x3ffe < obj->speed_y_up + 0x1fffU) {
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->gravity = -obj->gravity;
  }
  FUN_80106214(obj);
  cVar2 = Enemy_CheckWeaponHits(obj);
                    /* Possible PsyQ macro: setTile8() */
  if ((cVar2 == '\x04') || ((obj->field_0x33 & 0x30) != 0)) {
    FUN_8012a5fc(obj,4);
    FUN_80108e84(obj);
                    /* Possible PsyQ macro: setPolyF4() */
    Obj_Free(obj);
  }
  else {
    Enemy_ContactDamage(obj);
    if ((obj->anim_extra & 1) != 0) {
      FUN_8010544c(obj,0xf);
    }
  }
  return;
}


// ---- 801dff90 FUN_801dff90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dff90(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  obj->field_0x50 = obj->field_0x50 + '\x01';
  if (obj->sub2 == 0) {
    FUN_8010544c(obj,0x32);
    obj->hitbox = &DAT_801e1fb4;
    obj->box2 = &DAT_801e1fb4;
    obj->draw_list = 9;
    obj->clut = obj->clut + 5;
    if ((obj->flip & 0x40) == 0) {
      iVar2 = -0x30000;
    }
    else {
      iVar2 = 0x30000;
    }
    obj->speed_x = iVar2;
    obj->sub2 = obj->sub2 + 1;
  }
  Anim_Step(obj);
  FUN_80104c34(obj);
  FUN_80106214(obj);
  cVar1 = Enemy_CheckWeaponHits(obj);
  if ((cVar1 == '\x04') || (obj->field_0x33 != '\0')) {
    FUN_80108e84(obj);
    Obj_Free(obj);
  }
  else {
    if (0x30 < (ushort)((obj->x - *(short *)&obj->field_0x4a) + 0x18U)) {
      obj->draw_list = 7;
    }
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801e00a8 FUN_801e00a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e00a8(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    obj->hitbox = &DAT_801e1fbc;
    obj->box2 = &DAT_801e1fbc;
    obj->draw_list = 9;
    if ((obj->flip & 0x40) == 0) {
      iVar2 = -0x30000;
    }
    else {
      iVar2 = 0x30000;
    }
    obj->speed_x = iVar2;
    obj->speed_y_up = 0;
    obj->gravity = 0x4000;
    obj->sub2 = obj->sub2 + 1;
  }
  Anim_Step(obj);
  FUN_80104ccc(obj);
  if (obj->speed_y_up < -0x5ffff) {
    obj->speed_y_up = -0x60000;
  }
  FUN_80106214(obj);
  cVar1 = Enemy_CheckWeaponHits(obj);
  if ((cVar1 == '\x04') || ((obj->field_0x33 & 0x30) != 0)) {
    FUN_80108e84(obj);
    Obj_Free(obj);
  }
  else {
    if (0x40 < (ushort)((obj->x - *(short *)&obj->field_0x4a) + 0x20U)) {
      obj->draw_list = 8;
    }
    if ((obj->field_0x33 & 0xc0) == 0) {
      obj->field_0x43 = 1;
    }
    else {
      FUN_8010544c(obj,0x1b0);
      Anim_Set(obj,0xc);
      if ((obj->field_0x33 & 0x80) == 0) {
        obj->speed_y_up = -obj->speed_y_up;
      }
      else {
        obj->field_0x43 = 0;
        obj->speed_y_up = 0x60000;
      }
    }
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801e0230 FUN_801e0230

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0230(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    obj->hitbox = &DAT_801e1fc4;
    obj->draw_list = 6;
    obj->flip = obj->flip ^ 0x40;
    obj->clut = obj->clut + 4;
    if ((obj->flip & 0x40) == 0) {
      iVar1 = 0x60000;
    }
    else {
      iVar1 = -0x60000;
    }
    obj->speed_x = iVar1;
  }
  else {
    if (obj->sub2 != 1) {
      Anim_Step(obj);
      goto LAB_801e02e0;
    }
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 == 0) goto LAB_801e02e0;
    Anim_Set(obj,0x19);
  }
  obj->sub2 = obj->sub2 + 1;
LAB_801e02e0:
  FUN_80104c34(obj);
  Enemy_ContactDamage(obj);
  return;
}


