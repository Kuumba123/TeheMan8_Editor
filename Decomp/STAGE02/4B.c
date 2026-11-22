// ID 4B, STAGE02.BIN, handler 0x801E2184. Ghidra output with the object struct applied; not matching C.
// ---- 801e2184 FUN_801e2184

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2184(MM8Obj *obj)

{
  char cVar1;
  
  obj->invuln = 0;
  (*(code *)(&PTR_FUN_801e897c)[obj->state])();
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
LAB_801e2228:
    if (obj->active != 0) {
      Obj_CullAndQueueDraw(obj);
      cVar1 = Obj_InActiveArea(obj);
      if (cVar1 == '\0') goto LAB_801e2254;
    }
    if (obj->var != 0) {
      obj->invuln = 1;
    }
  }
  else {
    if (cVar1 != '\x04') goto LAB_801e2228;
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    if (obj->var == 0) {
      FUN_80108fd8(obj,0);
    }
LAB_801e2254:
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e228c FUN_801e228c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e228c(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->state = obj->var + 1;
  if (obj->var == 0) {
    Anim_Set(obj,0);
    FUN_8010910c(obj);
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x54 = 0x3c;
    obj->draw_list = 6;
    obj->hitbox = &DAT_801e8950;
                    /* Probable PsyQ macro: setPolyFT4() */
    obj->box2 = &DAT_801e8964;
  }
  else {
    Anim_Set(obj,0xb);
    iVar1 = -0x14000;
    obj->dmg_table = 2;
    obj->hp = 2;
    obj->hitbox = &DAT_801e8960;
    obj->draw_list = 5;
    obj->contact_dmg = 5;
    obj->box2 = &DAT_801e896c;
    if ((obj->flip & 0x40) != 0) {
      iVar1 = 0x14000;
    }
    obj->speed_y_up = 0x40000;
    obj->gravity = 0x4000;
    obj->field_0x54 = 0xa0;
    obj->speed_x = iVar1;
    obj->field_0x43 = 1;
  }
  return;
}


// ---- 801e2390 FUN_801e2390

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2390(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8988)[obj->sub2])();
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801e23e0 FUN_801e23e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e23e0(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    FUN_80106214();
    obj->sub3 = 1;
  }
  else {
    iVar1 = FUN_801e2bf0(obj);
    if (iVar1 != 0) {
      return;
    }
    if ((short)obj->frame < 0) {
      obj->sub2 = 2;
      obj->field_0x43 = 0;
      obj->sub3 = 0;
      obj->field_0x54 = 0x3c;
      Anim_Set(obj,1);
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801e2470 FUN_801e2470

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2470(MM8Obj *obj)

{
  FUN_80104ccc();
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
  }
  FUN_80106214(obj);
  if (obj->sub3 == 0) {
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->speed_y_up = 0;
      obj->gravity = 0;
      Anim_Set(obj,4);
      obj->sub3 = 1;
      obj->field_0x43 = 0;
    }
  }
  else if ((obj->field_0x33 & 0x80) == 0) {
    Anim_Set(obj,3);
    obj->gravity = 0x4000;
    obj->sub3 = 0;
    obj->field_0x43 = 1;
  }
  else {
    if ((short)obj->frame < 0) {
      Anim_Set(obj,1);
      obj->sub2 = 2;
      obj->field_0x54 = 0x3c;
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801e2560 FUN_801e2560

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2560(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_801e2bf0();
  if (iVar2 != 0) {
    return;
  }
  if (obj->field_0x54 == '\0') {
    if ((-1 < (short)obj->frame) || (iVar2 = FUN_801e2aa0(obj), iVar2 != 0)) goto LAB_801e25d0;
    FUN_8010910c(obj);
    cVar1 = '<';
  }
  else {
    cVar1 = obj->field_0x54 + -1;
  }
  obj->field_0x54 = cVar1;
LAB_801e25d0:
  obj->hitbox = &DAT_801e8954;
  Enemy_ContactDamage(obj);
  obj->dmg_table = 0;
  iVar2 = Enemy_CheckWeaponHits(obj);
  if (iVar2 == 3) {
    obj->sub2 = 7;
    obj->sub3 = 0;
    Anim_Set(obj,5);
    obj->field_0x54 = 0x14;
  }
  obj->hitbox = &DAT_801e8950;
  obj->dmg_table = 2;
  Anim_Step();
  return;
}


// ---- 801e2644 FUN_801e2644

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2644(MM8Obj *obj)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  pcVar3 = &UNK_801e8974;
  if ((obj->flip & 0x40) != 0) {
    pcVar3 = &DAT_801e8976;
  }
  iVar1 = FUN_801e2bf0(obj);
  if (iVar1 == 0) {
    if (((short)obj->frame < 0) && (obj->anim_timer < 2)) {
      Anim_Set(obj,1);
      obj->sub2 = 2;
      obj->sub3 = 0;
      obj->field_0x54 = 0x3c;
    }
    else if ((obj->sub3 == 0) && (obj->anim_extra == 1)) {
      uVar2 = 0xc0;
      if ((obj->flip & 0x40) != 0) {
        uVar2 = 0x40;
      }
      FUN_8010913c(obj,uVar2,(short)*pcVar3 + obj->x,(short)pcVar3[1] + obj->y);
      obj->sub3 = 1;
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801e2750 FUN_801e2750

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2750(MM8Obj *obj)

{
  FUN_80104ccc();
  FUN_80106214(obj);
  if (((obj->field_0x33 & 0x40) != 0) || (obj->speed_y_up < 1)) {
    obj->speed_y_up = 0;
    Anim_Set(obj,3);
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e27c4 FUN_801e27c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e27c4(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = FUN_801e2bf0();
  if (iVar1 == 0) {
    if (((short)obj->frame < 0) && (obj->anim_timer < 2)) {
      if (obj->field_0x4 == '\0') {
        Anim_Set(obj,1);
        obj->sub2 = 2;
        obj->sub3 = 0;
        obj->field_0x54 = 0x3c;
      }
      else {
        obj->sub2 = 6;
        obj->sub3 = 0;
        Anim_Set(obj,0xd);
        obj->field_0x54 = 0x3c;
        obj->hitbox = &UNK_801e8958 + (uint)obj->anim_extra * 4;
      }
    }
    else if ((obj->sub3 == 0) && ((obj->anim_extra == 1 && (iVar1 = FUN_801e2d88(obj), iVar1 != 0)))
            ) {
      obj->field_0x4 = 1;
      obj->sub3 = 1;
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801e28c0 FUN_801e28c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e28c0(MM8Obj *obj)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->field_0x50;
  iVar1 = FUN_801e2bf0();
  if (iVar1 == 0) {
    if (obj->sub3 == 0) {
      if (obj->anim_extra == 0) {
        Anim_Step(obj);
      }
      else if (((*pcVar2 == '\0') || ((*(uint *)(pcVar2 + 4) & 0xffff0000) != 0x14b0000)) ||
              (obj != *(MM8Obj **)(pcVar2 + 0x50))) {
        obj->sub3 = 1;
      }
      obj->hitbox = &UNK_801e8958 + (uint)obj->anim_extra * 4;
    }
    else {
      if (((short)obj->frame < 0) && (obj->anim_timer < 2)) {
        Anim_Set(obj,1);
        obj->sub2 = 2;
        obj->field_0x54 = 0x3c;
        obj->sub3 = 0;
        obj->hitbox = &DAT_801e8950;
      }
      Anim_Step(obj);
    }
  }
  else {
    obj->hitbox = &DAT_801e8950;
  }
  return;
}


// ---- 801e29ec FUN_801e29ec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e29ec(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_801e2bf0();
  if (iVar2 == 0) {
    cVar1 = obj->field_0x54;
    obj->field_0x54 = cVar1 + -1;
    if (cVar1 == '\0') {
      Anim_Set(obj,1);
      obj->sub2 = 2;
      obj->sub3 = 0;
      obj->field_0x54 = 0x3c;
    }
    else {
      obj->hitbox = &DAT_801e8954;
      obj->dmg_table = 0;
      Enemy_ContactDamage(obj);
      iVar2 = Enemy_CheckWeaponHits(obj);
      if (iVar2 == 3) {
        obj->field_0x54 = 0x14;
      }
      obj->hitbox = &DAT_801e8950;
      obj->dmg_table = 2;
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801e2aa0 FUN_801e2aa0

undefined4 FUN_801e2aa0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = Rand();
  if ((uVar1 & 3) == 3) {
    *(undefined1 *)(param_1 + 2) = 3;
    *(undefined4 *)(param_1 + 0x18) = 0x60000;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0x4000;
    Anim_Set(param_1,2);
    uVar2 = 0;
    *(undefined1 *)(param_1 + 0x43) = 1;
  }
  else {
    if (DAT_8015e248._2_2_ < *(short *)(param_1 + 0xe)) {
      if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
        return 0;
      }
    }
    else if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      return 0;
    }
    iVar3 = (int)DAT_8015e248._2_2_ - (int)*(short *)(param_1 + 0xe);
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if ((short)iVar3 < 0x79) {
      if (((short)iVar3 < 0x50) || (uVar1 = Rand(param_1), (uVar1 & 1) == 0)) {
        *(undefined1 *)(param_1 + 2) = 5;
        uVar2 = 8;
      }
      else {
        *(undefined1 *)(param_1 + 2) = 4;
        uVar2 = 0xc;
      }
    }
    else {
      *(undefined1 *)(param_1 + 2) = 4;
      uVar2 = 0xc;
    }
    Anim_Set(param_1,uVar2);
    uVar2 = 1;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
  }
  return uVar2;
}


// ---- 801e2bf0 FUN_801e2bf0

bool FUN_801e2bf0(int param_1)

{
  bool bVar1;
  
  FUN_80106214();
  bVar1 = (*(byte *)(param_1 + 0x33) & 0x80) == 0;
  if (bVar1) {
    *(undefined1 *)(param_1 + 0x43) = 1;
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 3) = 0;
    Anim_Set(param_1,3);
    *(undefined4 *)(param_1 + 0x20) = 0x4000;
  }
  return bVar1;
}


// ---- 801e2c54 FUN_801e2c54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2c54(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  cVar1 = obj->field_0x54;
  obj->field_0x54 = cVar1 + -1;
  if (cVar1 == '\0') {
    Enemy_ContactDamage();
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    Obj_Free(obj);
    return;
  }
  Obj_ApplySpeed(obj);
  iVar2 = Obj_HitboxOverlap(&g_player,obj);
  if (iVar2 != 0) {
    obj->speed_x = 0;
  }
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
  if (((obj->field_0x33 & 0x40) != 0) && (0 < obj->speed_y_up)) {
    obj->speed_y_up = -obj->speed_y_up;
  }
  if ((obj->field_0x33 & 0x80) == 0) {
    if ((obj->field_0x33 & 0x30) == 0) goto LAB_801e2d6c;
    iVar2 = -obj->speed_x;
  }
  else {
    if (-1 < obj->speed_y_up) goto LAB_801e2d6c;
    obj->speed_y_up = -(obj->speed_y_up >> 1);
    obj->gravity = 0x4000;
    iVar2 = obj->speed_x >> 1;
  }
  obj->speed_x = iVar2;
LAB_801e2d6c:
  Anim_Step(obj);
  return;
}


// ---- 801e2d88 FUN_801e2d88

bool FUN_801e2d88(int param_1)

{
  undefined1 *puVar1;
  char *pcVar2;
  
  pcVar2 = &UNK_801e8978;
  if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
    pcVar2 = &DAT_801e897a;
  }
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x4b;
    puVar1[7] = 1;
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(short *)(puVar1 + 0xe) = (short)*pcVar2 + *(short *)(puVar1 + 0xe);
    *(short *)(puVar1 + 0x12) = (short)pcVar2[1] + *(short *)(puVar1 + 0x12);
    puVar1[0x25] = *(undefined1 *)(param_1 + 0x25);
    *(undefined1 **)(param_1 + 0x50) = puVar1;
    *(int *)(puVar1 + 0x50) = param_1;
  }
  return puVar1 != (undefined1 *)0x0;
}


