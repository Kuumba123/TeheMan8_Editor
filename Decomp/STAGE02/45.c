// ID 45, STAGE02.BIN, handler 0x801E1130. Ghidra output with the object struct applied; not matching C.
// ---- 801e1130 FUN_801e1130

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1130(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e892c)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801e11ac FUN_801e11ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e11ac(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 6;
  obj->flip = 0;
  obj->field_0x43 = 1;
  obj->hitbox = &UNK_801e88ec + (uint)obj->var * 4;
  obj->box2 = &UNK_801e88f4 + (uint)obj->var * 5;
  if (obj->var == 0) {
    Anim_Set(obj,0);
    obj->state = 1;
    obj->field_0x51 = 0;
    obj->field_0x56 = 0;
    obj->contact_dmg = 4;
  }
  else {
    obj->dmg_table = 2;
    Anim_Set(obj,7);
    obj->hp = 6;
    obj->contact_dmg = 3;
    FUN_80105120(obj,*(undefined2 *)(&DAT_801e8910 + (uint)(byte)obj->field_0x55 * 2),
                 obj->field_0x53);
    obj->state = 3;
    obj->field_0x51 = 0;
    obj->field_0x56 = 0;
  }
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801e12b0 FUN_801e12b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e12b0(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    cVar2 = obj->field_0x50;
    obj->field_0x50 = cVar2 + -1;
    if (cVar2 == '\0') {
      Anim_Set(obj,1);
      obj->sub2 = 2;
      obj->field_0x50 = 0x40;
      return;
    }
    if (obj->sub3 != 0) goto LAB_801e13d8;
    uVar3 = Rand();
    if ((uVar3 & 7) != 7) {
      return;
    }
  }
  else {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        Anim_Step(obj);
        if (obj->field_0x50 != '\0') {
          obj->field_0x50 = obj->field_0x50 + -1;
          return;
        }
        if ((obj->anim_extra & 0x80) == 0) {
          return;
        }
        Anim_Set(obj,2);
        obj->sub2 = 3;
        obj->field_0x51 = 0;
        return;
      }
      if (bVar1 != 3) {
        return;
      }
      Anim_Step(obj);
      if (((int)(short)obj->frame & 0x8000U) == 0) {
        return;
      }
      bVar1 = obj->field_0x51;
      obj->field_0x51 = bVar1 + 1;
      if (bVar1 < 0xb) {
        return;
      }
      Anim_Set(obj,1);
      obj->field_0x53 = 0;
      obj->field_0x52 = 0;
      DAT_801b29a3 = 2;
      obj->state = 2;
      obj->sub2 = 0;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    if (DAT_801b29a3 == '\x01') {
      obj->field_0x50 = 0x3c;
      obj->sub2 = 1;
      obj->sub3 = 0;
      return;
    }
    if (obj->sub3 != 0) {
LAB_801e13d8:
      Anim_Step(obj);
      if (((int)(short)obj->frame & 0x8000U) == 0) {
        return;
      }
      Anim_Set(obj,0);
      obj->sub3 = 0;
      return;
    }
    uVar3 = Rand();
    if ((uVar3 & 7) != 7) {
      Anim_Set(obj,0);
      return;
    }
  }
  Anim_Set(obj,3);
  obj->sub3 = 1;
  return;
}


// ---- 801e14cc FUN_801e14cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e14cc(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_LAB_801e8940)[obj->sub2])();
  if (obj->field_0x56 == '\0') {
    Enemy_ContactDamage(obj);
  }
  obj->field_0x57 = obj->hp;
  cVar1 = Enemy_CheckWeaponHits(obj);
  if ((obj->field_0x52 == '\0') && (obj->field_0x56 == '\0')) {
    obj->clut = (&DAT_80159f64)[obj->bank];
    if (cVar1 == '\x04') {
      obj->field_0x56 = 1;
      FUN_801e208c(obj);
      FUN_80111c28();
    }
    else if (cVar1 == '\x02') {
      obj->clut = 0;
      obj->field_0x52 = 0x3c;
      FUN_8010544c(obj,0x10);
    }
  }
  else {
    if ((obj->field_0x52 & 1) == 0) {
      obj->clut = (&DAT_80159f64)[obj->bank];
    }
    else {
      obj->clut = 0;
    }
    obj->field_0x52 = obj->field_0x52 + -1;
    if ((cVar1 == '\x02') || (cVar1 == '\x04')) {
      FUN_8010544c(obj,0x4f);
    }
    obj->hp = obj->field_0x57;
  }
  return;
}


// ---- 801e1b34 FUN_801e1b34

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1b34(MM8Obj *obj)

{
  char cVar1;
  
  FUN_80104c34();
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0xc0) == 0) {
    if ((obj->field_0x33 & 0x30) == 0) goto LAB_801e1bac;
    obj->speed_x = -obj->speed_x;
  }
  else {
    obj->speed_y_up = -obj->speed_y_up;
  }
  Anim_Set(obj,8);
  obj->field_0x51 = obj->field_0x51 + '\x01';
LAB_801e1bac:
  Anim_Step(obj);
  if ((byte)obj->field_0x51 < 6) {
    Enemy_ContactDamage(obj);
    obj->clut = (&DAT_80159f64)[obj->bank];
    cVar1 = Enemy_CheckWeaponHits(obj);
    if (cVar1 != '\x04') {
      if (cVar1 != '\x02') {
        return;
      }
      obj->clut = 0;
      return;
    }
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    FUN_80108fd8(obj,0);
  }
  else {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
  }
  Obj_Free(obj);
  return;
}


// ---- 801e1c68 FUN_801e1c68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1c68(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  
  if ((obj->field_0x52 & 1) == 0) {
    obj->clut = (&DAT_80159f64)[obj->bank];
  }
  else {
    obj->clut = 0;
  }
  bVar2 = obj->sub2;
  obj->field_0x52 = obj->field_0x52 + -1;
  if (bVar2 == 1) {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      Anim_Set(obj,1);
      obj->field_0x50 = 0xc0;
      obj->sub2 = 2;
    }
    bVar5 = 7;
    bVar2 = obj->field_0x50 & 7;
  }
  else if (bVar2 < 2) {
    if (bVar2 != 0) {
      return;
    }
    if ((obj->anim_extra & 0x80) != 0) {
      Anim_Set(obj,3);
      obj->field_0x50 = 0x40;
      obj->sub2 = 1;
    }
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
    bVar5 = 7;
    bVar2 = obj->field_0x50 & 7;
  }
  else {
    if (bVar2 != 2) {
      return;
    }
    cVar1 = obj->field_0x50;
    bVar5 = cVar1 - 1;
    obj->field_0x50 = bVar5;
    if (cVar1 == '\0') {
      FUN_80108e84(obj);
      FUN_8012a5fc(obj,0);
      DAT_801b29a4 = obj->x;
      DAT_801b29a6 = obj->y;
      Obj_Free(obj);
      DAT_801b29a3 = 3;
      return;
    }
    bVar5 = bVar5 & 3;
    bVar2 = 3;
  }
  if (bVar5 == bVar2) {
    uVar3 = Rand();
    uVar4 = Rand();
    FUN_80108ed8(obj,(int)((0x1f - (uVar3 & 0x3f)) * 0x10000) >> 0x10,
                 (int)((0x1f - (uVar4 & 0x3f)) * 0x10000) >> 0x10);
    uVar3 = Rand();
    uVar4 = Rand();
    FUN_8012a724(obj,0,(int)((0x1f - (uVar3 & 0x3f)) * 0x10000) >> 0x10,
                 (int)((0x1f - (uVar4 & 0x3f)) * 0x10000) >> 0x10);
  }
  Anim_Step(obj);
  return;
}


// ---- 801e208c FUN_801e208c

void FUN_801e208c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_80105d48(param_1,0x45);
  if ((iVar1 != 0) && (iVar3 = 0, 0 < iVar1)) {
    puVar4 = &DAT_801b1040;
    do {
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + 1;
      FUN_80108e84(uVar2);
      FUN_8012a5fc(uVar2,0);
      Obj_Free(uVar2);
    } while (iVar3 < iVar1);
  }
  iVar1 = FUN_80105d48(param_1,0x1d);
  if ((iVar1 != 0) && (iVar3 = 0, 0 < iVar1)) {
    puVar4 = &DAT_801b1040;
    do {
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + 1;
      FUN_80108e84(uVar2);
      FUN_8012a5fc(uVar2,0);
      Obj_Free(uVar2);
    } while (iVar3 < iVar1);
  }
  return;
}


