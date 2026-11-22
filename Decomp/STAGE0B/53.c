// ID 53, STAGE0B.BIN, handler 0x801DFB88. Ghidra output with the object struct applied; not matching C.
// ---- 801dfb88 FUN_801dfb88

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfb88(MM8Obj *obj)

{
  char cVar1;
  
  obj->clut = obj->field_0x52;
  (*(code *)(&PTR_FUN_801e8568)[obj->state])();
  if (obj->active != 0) {
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      Obj_FreeDespawn(obj);
    }
    else {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801dfc10 FUN_801dfc10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfc10(MM8Obj *obj)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  Enemy_InitFromTable();
  obj->field_0x52 = obj->clut;
  if ((obj->var & 0x80) == 0) {
    obj->draw_list = 6;
    obj->box2 = &DAT_801e8558;
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
    obj->hitbox = &DAT_801e8560;
    obj->field_0x55 = 0;
    obj->field_0x54 = 0;
    obj->field_0x43 = 1;
    obj->flip = (obj->var & 1) << 6;
    if ((obj->var & 2) == 0) {
      obj->state = 1;
      uVar1 = Rand();
      uVar3 = 6;
      if ((uVar1 & 0x80) == 0) {
        uVar3 = 0;
        iVar2 = -0xc000;
        obj->field_0x51 = 0;
      }
      else {
        iVar2 = 0xc000;
        obj->field_0x51 = 1;
      }
      obj->speed_y_up = iVar2;
    }
    else {
      obj->state = 5;
      uVar3 = 1;
    }
  }
  else {
    iVar2 = -0x28000;
                    /* Possible PsyQ macro: setPolyGT3() */
    obj->draw_list = 7;
    obj->dmg_table = 3;
    if (obj->flip != 0) {
      iVar2 = 0x28000;
    }
    uVar3 = 3;
    obj->field_0x50 = 0x78;
    obj->hitbox = &DAT_801e8564;
    obj->speed_x = iVar2;
    obj->state = 4;
  }
  Anim_Set(obj,uVar3);
  return;
}


// ---- 801dfd3c FUN_801dfd3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfd3c(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  
  Anim_Step();
  sVar3 = obj->x + -0x18;
  if ((obj->flip & 0x40) == 0) {
    sVar3 = obj->x + 0x18;
  }
  if (obj->field_0x51 == '\0') {
    sVar4 = obj->y + 0x14;
  }
  else {
    sVar4 = obj->y + -0x14;
  }
  cVar2 = FUN_80107204((int)sVar3,(int)sVar4);
  if (cVar2 == '\0') {
    if ((obj->anim_extra & 0x80) == 0) goto LAB_801dfe4c;
  }
  else {
    if (obj->anim_extra == 0) {
      FUN_80104d18(obj);
    }
    FUN_80106214(obj);
    if (obj->field_0x51 == '\0') {
      bVar1 = obj->field_0x33 & 0x80;
    }
    else {
      bVar1 = obj->field_0x33 & 0x40;
    }
    if (bVar1 != 0) {
      obj->field_0x55 = 1;
    }
    if (((obj->anim_extra & 0x80) == 0) || (obj->field_0x55 == '\0')) goto LAB_801dfe4c;
    obj->field_0x55 = 0;
  }
  obj->field_0x54 = 1;
LAB_801dfe4c:
  if (obj->field_0x54 != '\0') {
    obj->field_0x54 = 0;
    obj->field_0x51 = obj->field_0x51 ^ 1;
    obj->speed_y_up = -obj->speed_y_up;
    Anim_SetAtStep(obj,-(obj->field_0x51 != '\0') & 6,(int)(short)obj->frame);
  }
  if ((short)obj->frame < 0) {
    FUN_801e0168(obj);
  }
  FUN_801e00f0(obj);
  return;
}


// ---- 801dfec4 FUN_801dfec4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfec4(MM8Obj *obj)

{
  Anim_Step();
  obj->field_0x50 = obj->field_0x50 + -1;
  if (obj->field_0x50 == '\0') {
    obj->state = 3;
                    /* Possible PsyQ macro: setPolyGT4() */
    Anim_Set(obj,2);
  }
  FUN_801e00f0(obj);
  return;
}


// ---- 801dff24 FUN_801dff24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dff24(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  
                    /* Possible PsyQ macro: setTile8() */
  Anim_Step();
  if (obj->anim_extra != 0) {
    obj->anim_extra = 0;
    puVar2 = (undefined1 *)Obj_AllocMain();
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x53;
      puVar2[7] = 0x80;
      puVar2[0x25] = obj->flip;
      *(short *)(puVar2 + 0xe) = obj->x;
      *(short *)(puVar2 + 0x12) = obj->y;
      FUN_800fd100(0xb);
    }
  }
  if ((short)obj->frame < 0) {
    if ((obj->var & 2) == 0) {
      Anim_Set(obj,-(obj->field_0x51 != '\0') & 6);
      bVar1 = 1;
    }
    else {
      Anim_Set(obj,1);
      bVar1 = 5;
    }
    obj->state = bVar1;
  }
  FUN_801e00f0(obj);
  return;
}


// ---- 801e0008 FUN_801e0008

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0008(MM8Obj *obj)

{
  FUN_801e0168();
  FUN_801e00f0(obj);
  return;
}


// ---- 801e0038 FUN_801e0038

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0038(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  FUN_80104d00(obj);
  if (obj->sub2 == 0) {
    obj->field_0x50 = obj->field_0x50 + -1;
    if (obj->field_0x50 == '\0') {
      Anim_Set(obj,4);
      obj->sub2 = 1;
      return;
    }
    iVar1 = Enemy_CheckWeaponHits(obj);
    if ((iVar1 != 1) && (iVar1 = Enemy_ContactDamage(obj), iVar1 == 0)) {
      return;
    }
  }
  else if (-1 < (short)obj->frame) {
    return;
  }
  Obj_Free(obj);
  return;
}


// ---- 801e00f0 FUN_801e00f0

void FUN_801e00f0(int param_1)

{
  char cVar1;
  
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  if (cVar1 == '\x04') {
    FUN_80108e84(param_1);
    FUN_8012a5fc(param_1,0);
    FUN_8012ae08(param_1,0x33);
    Obj_FreeDespawn(param_1);
  }
  else {
    Enemy_ContactDamage(param_1);
  }
  return;
}


// ---- 801e0168 FUN_801e0168

void FUN_801e0168(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = (uint)*(ushort *)(param_1 + 0x12) - (uint)DAT_8015e24c._2_2_;
  sVar1 = (short)iVar2;
  if (iVar2 * 0x10000 < 0) {
    sVar1 = -sVar1;
  }
  if ((sVar1 < 0x14) &&
     (((iVar2 = (int)(((uint)*(ushort *)(param_1 + 0xe) - (uint)DAT_8015e248._2_2_) * 0x10000) >>
                0x10, 0 < iVar2 && (*(char *)(param_1 + 0x25) == '\0')) ||
      ((iVar2 < 0 && ((*(byte *)(param_1 + 0x25) & 0x40) != 0)))))) {
    *(undefined1 *)(param_1 + 1) = 2;
    *(undefined1 *)(param_1 + 0x50) = 8;
    Anim_Set(param_1,1);
  }
  return;
}


