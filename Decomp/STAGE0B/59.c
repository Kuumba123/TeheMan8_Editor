// ID 59, STAGE0B.BIN, handler 0x801E0218. Ghidra output with the object struct applied; not matching C.
// ---- 801e0218 FUN_801e0218

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0218(MM8Obj *obj)

{
  obj->invuln = 0;
  (*(code *)(&PTR_FUN_801e8644)[obj->state])();
  obj->invuln = 1;
  if ((obj->active != 0) && (obj->field_0x51 == '\0')) {
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  return;
}


// ---- 801e0288 FUN_801e0288

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0288(MM8Obj *obj)

{
  byte bVar1;
  undefined4 uVar2;
  
  Enemy_InitFromTable();
  obj->field_0x57 = 0;
  obj->draw_list = 7;
  bVar1 = obj->var & 0x7f;
  if (bVar1 == 1) {
    obj->state = 2;
                    /* Possible PsyQ macro: setPolyF4() */
    obj->hp = 0x28;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->contact_dmg = 3;
    FUN_801e3450(obj);
    if ((obj->var & 0x80) == 0) {
      DAT_801b29a5 = obj->hp;
      obj->flip = 0;
    }
    else {
      DAT_801b29a6 = obj->hp;
      obj->flip = 0x80;
    }
    uVar2 = 1;
    obj->hitbox = &DAT_801e8584;
    obj->dmg_table = 0;
    obj->contact_dmg = 3;
    obj->field_0x51 = 0;
    obj->field_0x52 = 0;
  }
  else {
    if (bVar1 < 2) {
      if ((obj->var & 0x7f) != 0) {
        return;
      }
      obj->state = 1;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      obj->flip = 0;
      obj->hitbox = &DAT_801e8580;
      obj->dmg_table = 0;
      obj->field_0x51 = 0;
      obj->field_0x52 = 0;
      obj->field_0x53 = 0;
      obj->field_0x54 = 0;
      obj->field_0x55 = 0;
      obj->field_0x58 = 0;
      obj->field_0x59 = 0;
      obj->field_0x5a = 0;
      Anim_Set(obj,0x15);
      FUN_801e33b0(obj);
      obj->hp = 0;
      return;
    }
    if (bVar1 != 2) {
      return;
    }
    obj->state = 3;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    FUN_801e3450(obj);
    if ((obj->var & 0x80) == 0) {
      obj->flip = 0x80;
    }
    else {
      obj->flip = 0;
    }
    uVar2 = 0x12;
    obj->hp = 0x14;
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
    obj->contact_dmg = 3;
    obj->dmg_table = 0;
    obj->field_0x51 = 0;
    obj->hitbox = &UNK_801e8598 + (uint)obj->anim_extra * 4;
  }
  Anim_Set(obj,uVar2);
  return;
}


// ---- 801e0468 FUN_801e0468

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0468(MM8Obj *obj)

{
  undefined1 uVar1;
  short sVar2;
  
  (*(code *)(&PTR_FUN_801e8654)[obj->sub2])();
  if (obj->sub2 != 2) {
    Enemy_ContactDamage(obj);
    Enemy_CheckWeaponHits(obj);
    obj->x = obj->x + DAT_801d293a;
  }
  obj->field_0x58 = obj->field_0x58 ^ 1;
  obj->field_0x59 = obj->field_0x59 ^ 1;
  if (obj->sub2 == 2) goto switchD_801e0520_default;
  switch(obj->field_0x5a) {
  case 0:
    if ((DAT_801b29a3 & 0x88) != 0) {
      if ((DAT_801b29a3 & 0x80) == 0) {
        obj->field_0x5a = 2;
      }
      else {
        obj->field_0x5a = 1;
      }
    }
    goto switchD_801e0520_default;
  case 1:
    sVar2 = obj->y + -1;
    obj->y = sVar2;
    if ((int)sVar2 < g_cam_y + 0x3c) {
      obj->y = g_cam_y + 0x3c;
      uVar1 = 3;
LAB_801e0598:
      obj->field_0x5a = uVar1;
    }
    break;
  case 2:
    sVar2 = obj->y + 1;
    obj->y = sVar2;
    if (g_cam_y + 0xb4 < (int)sVar2) {
      obj->y = g_cam_y + 0xb4;
      uVar1 = 4;
      goto LAB_801e0598;
    }
    break;
  case 3:
    break;
  case 4:
    sVar2 = obj->x + 1;
    if (obj->field_0x58 == '\0') {
      sVar2 = obj->x + -1;
    }
    goto LAB_801e0608;
  default:
    goto switchD_801e0520_default;
  }
  sVar2 = obj->x + 1;
  if (obj->field_0x58 == '\0') {
    sVar2 = obj->x + -1;
  }
LAB_801e0608:
  obj->x = sVar2;
switchD_801e0520_default:
  sVar2 = 1;
  if (obj->field_0x59 == '\0') {
    sVar2 = -1;
  }
  obj->y = obj->y + sVar2;
  return;
}


// ---- 801e063c FUN_801e063c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e063c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8660)[obj->sub3])();
  return;
}


// ---- 801e0678 FUN_801e0678

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0678(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  
  bVar1 = obj->field_0x4;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        cVar2 = obj->field_0x50;
        obj->field_0x50 = cVar2 + -1;
        if (cVar2 != '\0') {
          return;
        }
        obj->field_0x4 = 3;
        obj->field_0x50 = 0x14;
        DAT_801b29a1 = 0;
        return;
                    /* Possible PsyQ macro: setLineF2() */
      }
      if (bVar1 != 3) {
        return;
      }
      cVar2 = obj->field_0x50;
      obj->field_0x50 = cVar2 + -1;
      if (cVar2 != '\0') {
        return;
      }
      uVar3 = 0x1c2;
      obj->sub3 = 1;
      obj->field_0x4 = 0;
      goto LAB_801e07a8;
    }
    if (bVar1 != 0) {
      return;
    }
    if (DAT_801b29a7 == '\x01') {
      obj->speed_y_up = 0x20000;
      obj->field_0x4 = 1;
      FUN_8010544c(obj,0x1c1);
      DAT_801b29a1 = 0;
    }
  }
  FUN_80104d18(obj);
  if (g_cam_y + 0x78 <= (int)obj->y) {
    return;
  }
  uVar3 = 0x1c1;
  obj->y = g_cam_y + 0x78;
  obj->field_0x4 = 2;
  obj->field_0x50 = 0x14;
LAB_801e07a8:
  DAT_801b29a1 = 1;
  FUN_8010544c(obj,uVar3);
  return;
}


// ---- 801e07cc FUN_801e07cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e07cc(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = obj->field_0x4;
                    /* Possible PsyQ macro: setPolyG3() */
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      FUN_80104c9c(obj);
      if (obj->speed_x < -0x40000) {
        obj->speed_x = -0x40000;
        obj->accel_x = 0;
      }
                    /* Possible PsyQ macro: setPolyF3() */
      if (DAT_801d2918._2_2_ + 0xe8 <= (int)obj->x) {
        return;
      }
      obj->x = DAT_801d2918._2_2_ + 0xe8;
      obj->sub3 = 2;
      obj->field_0x4 = 0;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    obj->accel_x = 0x2000;
    obj->speed_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->field_0x4 = 1;
  }
  FUN_80104c9c(obj);
                    /* Probable PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  if (0x40000 < obj->speed_x) {
    obj->speed_x = 0x40000;
    obj->accel_x = 0;
  }
  if (DAT_801d2918._2_2_ + 0xe8 < (int)obj->x) {
    obj->accel_x = -0x2000;
                    /* Probable PsyQ macro: setTile() */
    obj->field_0x4 = 2;
    DAT_801b29a1 = 0;
  }
  return;
}


// ---- 801e08f4 FUN_801e08f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e08f4(MM8Obj *obj)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  
  bVar1 = obj->field_0x4;
  if (bVar1 == 1) {
                    /* Possible PsyQ macro: setPolyGT3() */
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      if (obj->field_0x50 == '\0') {
        Anim_Set(obj,0);
        FUN_800fd100(0x13e);
        DAT_801b29a1 = 0;
        obj->field_0x4 = 2;
      }
      else {
        Anim_Set(obj,0x1d);
        FUN_8010544c(obj,0x1c3);
        if (obj->anim_extra == 0) {
          DAT_801b29a1 = 0;
        }
        else {
          DAT_801b29a1 = 2;
        }
        obj->field_0x50 = obj->field_0x50 + -1;
      }
    }
    else {
      Anim_Step(obj);
      if (obj->anim_extra == 0) {
        DAT_801b29a1 = 0;
      }
      else {
        DAT_801b29a1 = 2;
      }
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
        Anim_Set(obj,0x1d);
                    /* Possible PsyQ macro: setPolyG3() */
        FUN_8010544c(obj,0x1c3);
        if (obj->anim_extra == 0) {
          DAT_801b29a1 = 0;
        }
        else {
          DAT_801b29a1 = 2;
        }
        obj->field_0x4 = 1;
        obj->field_0x50 = 5;
      }
      else {
        Anim_Step(obj);
      }
    }
  }
  else if (bVar1 == 2) {
    if ((DAT_80170574 & 1) != 0) {
      obj->hp = obj->hp + 1;
    }
    if (0x27 < obj->hp) {
                    /* Possible PsyQ macro: setPolyF4() */
      obj->hp = 0x28;
      DAT_801b29a7 = '\x02';
      obj->field_0x4 = 3;
    }
  }
  else {
                    /* Possible PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setPolyGT4() */
    if ((bVar1 == 3) && (DAT_801b29a7 == '\x03')) {
      obj->sub2 = 1;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      uVar3 = Rand();
      uVar2 = (&DAT_801e85d0)[uVar3 & 0xf];
      obj->field_0x53 = 0;
      obj->field_0x54 = 0;
      obj->field_0x52 = uVar2;
    }
  }
  return;
}


// ---- 801e0b50 FUN_801e0b50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0b50(MM8Obj *obj)

{
  uint uVar1;
  byte bVar2;
  
  (*(code *)(&PTR_FUN_801e866c)[obj->sub3])();
  uVar1 = (uint)DAT_801b29a5 + (uint)DAT_801b29a6 & 0xff;
  if ((uVar1 == 0) || (uVar1 >> 1 != 0)) {
    bVar2 = (byte)(((uint)DAT_801b29a5 + (uint)DAT_801b29a6 & 0xff) >> 1);
  }
  else {
    bVar2 = 1;
                    /* Possible PsyQ macro: setPolyGT4() */
  }
  obj->hp = bVar2;
  if ((obj->hp == 0) || ((DAT_801b29a3 & 0x88) == 0x88)) {
    DAT_801b2992 = 1;
                    /* Possible PsyQ macro: setTile8() */
    DAT_801b2993 = 1;
    FUN_800fcd84();
    DAT_8015e2af = 1;
    Anim_Set(obj,0x13);
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  else if (obj->field_0x55 == '\0') {
    FUN_801e37e0(obj);
  }
  return;
}


// ---- 801e0c64 FUN_801e0c64

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0c64(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  if (obj->field_0x4 == '\0') {
    obj->speed_x = 0x8000;
    obj->speed_y_up = 0x10000;
    obj->field_0x50 = 0x80;
    obj->accel_x = 0;
    obj->gravity = 0;
    obj->field_0x4 = 1;
    FUN_8010544c(obj,0x1c1);
  }
  cVar1 = obj->field_0x50;
  obj->field_0x50 = cVar1 + -1;
  if (cVar1 == '\0') {
    FUN_801e39d0(obj);
    obj->field_0x4 = 0;
    obj->sub3 = (byte)obj->field_0x56 >> 4;
  }
  bVar2 = obj->field_0x5a;
  if (bVar2 == 3) {
    FUN_80104d18(obj);
    iVar4 = (obj->y + -0x3c) - (int)g_cam_y;
    iVar3 = iVar4;
    if (iVar4 < 0) {
      iVar3 = -iVar4;
    }
    if (iVar3 < 0x11) {
      return;
    }
    iVar3 = 0x10000;
    if (iVar4 < 0) {
      iVar3 = -0x10000;
    }
  }
  else if (bVar2 < 4) {
    if (bVar2 != 0) {
      return;
    }
    FUN_80104d18(obj);
    iVar4 = (obj->y + -0x78) - (int)g_cam_y;
    iVar3 = iVar4;
    if (iVar4 < 0) {
      iVar3 = -iVar4;
    }
    if (iVar3 < 0x61) {
      return;
    }
    iVar3 = 0x10000;
    if (iVar4 < 0) {
      iVar3 = -0x10000;
    }
  }
  else {
    if (bVar2 != 4) {
      return;
    }
    FUN_80104d18(obj);
    iVar4 = (obj->y + -0xb4) - (int)g_cam_y;
    iVar3 = iVar4;
    if (iVar4 < 0) {
      iVar3 = -iVar4;
    }
    if (iVar3 < 0x11) {
      return;
    }
    iVar3 = 0x10000;
    if (iVar4 < 0) {
      iVar3 = -0x10000;
    }
  }
  obj->speed_y_up = iVar3;
  FUN_8010544c(obj,0x1c1);
  return;
}


// ---- 801e0e04 FUN_801e0e04

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0e04(MM8Obj *obj)

{
  char cVar1;
  
  switch(obj->field_0x4) {
  case 0:
    if ((DAT_801b29a3 & 0x88) == 0) {
      if (obj->field_0x54 != '\0') {
        return;
      }
      obj->field_0x55 = 1;
      obj->field_0x50 = 2;
      Anim_Set(obj,0x1d);
      FUN_8010544c(obj,0x1c3);
      if (obj->anim_extra == 0) {
        DAT_801b29a1 = 0;
      }
      else {
        DAT_801b29a1 = 2;
      }
      obj->field_0x4 = 1;
      return;
    }
    goto LAB_801e0f90;
  case 1:
    Anim_Step(obj);
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      Anim_Set(obj,0x1d);
      FUN_8010544c(obj,0x1c3);
      obj->field_0x50 = obj->field_0x50 + -1;
    }
                    /* Possible PsyQ macro: setTile8() */
    if (obj->field_0x50 == '\0') {
      Anim_Set(obj,0);
      obj->field_0x50 = 0xf;
      obj->field_0x4 = 2;
    }
    if (obj->anim_extra == 0) {
      DAT_801b29a1 = 0;
    }
    else {
      DAT_801b29a1 = 2;
    }
    break;
  case 2:
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 != '\0') {
      return;
    }
LAB_801e0f90:
    if ((DAT_801b29a3 & 0x80) == 0) {
      DAT_801b29a3 = DAT_801b29a3 & 0xf | 0x40;
    }
    if ((DAT_801b29a3 & 8) == 0) {
      DAT_801b29a3 = DAT_801b29a3 & 0xf0 | 4;
    }
    obj->field_0x4 = 3;
    break;
  case 3:
    if ((DAT_801b29a3 & 0x44) == 0) {
      obj->field_0x50 = 0xf;
      obj->field_0x4 = 4;
    }
    break;
  case 4:
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0x80;
      obj->sub3 = 0;
      obj->field_0x4 = 1;
      obj->field_0x55 = 0;
      FUN_8010544c(obj,0x1c1);
    }
  }
  return;
}


// ---- 801e1044 FUN_801e1044

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1044(MM8Obj *obj)

{
  char cVar1;
  
                    /* Possible PsyQ macro: setTile8() */
  switch(obj->field_0x4) {
  case 0:
    if ((DAT_801b29a3 & 0x88) == 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
      if (obj->field_0x54 != '\0') {
        return;
      }
      obj->field_0x55 = 1;
      obj->field_0x50 = 2;
      Anim_Set(obj,0x1e);
      FUN_8010544c(obj,0x1c3);
      if (obj->anim_extra == 0) {
        DAT_801b29a1 = 0;
      }
      else {
        DAT_801b29a1 = 2;
      }
      obj->field_0x4 = 1;
      return;
    }
    goto LAB_801e11d0;
  case 1:
                    /* Possible PsyQ macro: setPolyF4() */
    Anim_Step(obj);
                    /* Probable PsyQ macro: setTile8() */
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      Anim_Set(obj,0x1e);
      FUN_8010544c(obj,0x1c3);
      obj->field_0x50 = obj->field_0x50 + -1;
    }
    if (obj->field_0x50 == '\0') {
      Anim_Set(obj,0);
      obj->field_0x50 = 0xf;
      obj->field_0x4 = 2;
    }
    if (obj->anim_extra == 0) {
      DAT_801b29a1 = 0;
    }
    else {
      DAT_801b29a1 = 2;
    }
    break;
  case 2:
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 != '\0') {
      return;
    }
LAB_801e11d0:
    if ((DAT_801b29a3 & 0x80) == 0) {
      DAT_801b29a3 = DAT_801b29a3 & 0xf | 0x20;
    }
    if ((DAT_801b29a3 & 8) == 0) {
      DAT_801b29a3 = DAT_801b29a3 & 0xf0 | 2;
    }
    obj->field_0x4 = 3;
    break;
  case 3:
    if ((DAT_801b29a3 & 0x22) == 0) {
      obj->field_0x50 = 0xf;
      obj->field_0x4 = 4;
    }
    break;
  case 4:
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0x80;
      obj->sub3 = 0;
      obj->field_0x4 = 1;
      obj->field_0x55 = 0;
      FUN_8010544c(obj,0x1c1);
    }
  }
  return;
}


// ---- 801e1284 FUN_801e1284

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1284(MM8Obj *obj)

{
  char cVar1;
  
  switch(obj->field_0x4) {
  case 0:
                    /* Possible PsyQ macro: setPolyF4() */
    if ((DAT_801b29a3 & 0x88) == 0) {
      if (obj->field_0x54 != '\0') {
        return;
      }
      obj->field_0x55 = 1;
      obj->field_0x50 = 2;
      Anim_Set(obj,0x1d);
      FUN_8010544c(obj,0x1c3);
      if (obj->anim_extra == 0) {
        DAT_801b29a1 = 0;
      }
      else {
        DAT_801b29a1 = 2;
      }
      obj->field_0x4 = 1;
      return;
    }
    if ((DAT_801b29a4 & 0x80) == 0) {
      DAT_801b29a4 = DAT_801b29a4 & 0xf | 0x40;
    }
    if ((DAT_801b29a4 & 8) == 0) {
      DAT_801b29a4 = DAT_801b29a4 & 0xf0 | 4;
    }
    goto LAB_801e149c;
  case 1:
    Anim_Step(obj);
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      Anim_Set(obj,0x1d);
      FUN_8010544c(obj,0x1c3);
      obj->field_0x50 = obj->field_0x50 + -1;
    }
    if (obj->field_0x50 == '\0') {
      Anim_Set(obj,0);
      obj->field_0x50 = 0xf;
      obj->field_0x4 = 2;
    }
    if (obj->anim_extra == 0) {
      DAT_801b29a1 = 0;
    }
    else {
                    /* Possible PsyQ macro: setPolyGT3() */
      DAT_801b29a1 = 2;
    }
    break;
  case 2:
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 != '\0') {
      return;
    }
    if ((DAT_801b29a4 & 0x80) == 0) {
      DAT_801b29a4 = DAT_801b29a4 & 0xf | 0x40;
    }
    if ((DAT_801b29a4 & 8) == 0) {
      DAT_801b29a4 = DAT_801b29a4 & 0xf0 | 4;
    }
LAB_801e149c:
    obj->field_0x4 = 3;
    break;
  case 3:
    if ((DAT_801b29a4 & 0x44) == 0) {
      obj->field_0x50 = 0xf;
      obj->field_0x4 = 4;
    }
    break;
  case 4:
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0x80;
      obj->sub3 = 0;
      obj->field_0x4 = 1;
      obj->field_0x55 = 0;
      FUN_8010544c(obj,0x1c1);
    }
  }
  return;
}


// ---- 801e151c FUN_801e151c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e151c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8680)[(byte)obj->field_0x4])();
  return;
}


// ---- 801e1558 FUN_801e1558

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1558(MM8Obj *obj)

{
  if (obj->field_0x54 == '\0') {
    obj->field_0x55 = 1;
  }
  if (obj->field_0x55 != '\0') {
    obj->field_0x50 = 0xf;
    obj->field_0x4 = 1;
    DAT_801b29a1 = 1;
    FUN_8010544c(obj,0x1c1);
  }
  return;
}


// ---- 801e1a44 FUN_801e1a44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1a44(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e86ac)[obj->sub3])();
  FUN_801e3de0(obj);
  return;
}


// ---- 801e1a94 FUN_801e1a94

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1a94(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x50 = 0;
                    /* Possible PsyQ macro: setLineF2() */
    obj->field_0x4 = 1;
  }
  if (obj->field_0x50 == '\0') {
    if ((DAT_801b29a2 & 0xf) == 0xf) {
      obj->sub3 = 1;
      obj->field_0x4 = 0;
      goto LAB_801e1b3c;
    }
    FUN_8010544c(obj,10);
    FUN_8012ae08(obj,0x3b);
    DAT_801b29a2 = DAT_801b29a2 << 1 | 1;
    cVar1 = '\x1e';
  }
  else {
    cVar1 = obj->field_0x50 + -1;
  }
  obj->field_0x50 = cVar1;
LAB_801e1b3c:
  obj->x = obj->x + DAT_801d293a;
  Anim_Step();
  return;
}


// ---- 801e1b70 FUN_801e1b70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1b70(MM8Obj *obj)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  obj->clut = (&DAT_80159f64)[obj->bank];
  if ((DAT_80170574 & 1) != 0) {
    obj->clut = 0;
  }
  uVar2 = DAT_80170574 & 7;
  obj->y = obj->y + 1;
  if (uVar2 == 7) {
    uVar2 = Rand();
    uVar1 = Rand();
                    /* Possible PsyQ macro: setPolyF4() */
    FUN_8012ae08(obj,0x3b);
    iVar4 = (int)(((uVar2 & 0x3f) - 0x1f) * 0x10000) >> 0x10;
    iVar3 = (int)(((uVar1 & 0x3f) - 0x1f) * 0x10000) >> 0x10;
    FUN_80108ed8(obj,iVar4,iVar3);
    FUN_801091a4(obj->x + iVar4,obj->y + iVar3,1);
  }
  if (g_cam_y + 0x168 < (int)obj->y) {
    DAT_801b29a7 = 4;
    Obj_Free(obj);
  }
  return;
}


// ---- 801e1c88 FUN_801e1c88

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1c88(MM8Obj *obj)

{
  byte bVar1;
  undefined4 uVar2;
  
  FUN_801e3450();
  if ((obj->var & 0x80) == 0) {
    if ((DAT_801b29a2 & 4) != 0) {
      uVar2 = 0x37;
LAB_801e1cec:
      FUN_8012ae08(obj,uVar2);
      FUN_801e3ee8(obj);
      Obj_Free(obj);
      return;
    }
  }
  else if ((DAT_801b29a2 & 8) != 0) {
    uVar2 = 0x38;
    goto LAB_801e1cec;
  }
  (*(code *)(&PTR_FUN_801e86b4)[obj->sub2])(obj);
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  if (obj->sub2 == 4) goto LAB_801e1db4;
  if (DAT_801b29a1 == 1) {
    uVar2 = 1;
  }
  else {
    if (1 < DAT_801b29a1) {
      if (DAT_801b29a1 == 2) {
        FUN_801e3688(obj);
        obj->field_0x51 = 1;
      }
      goto LAB_801e1db4;
    }
    if (DAT_801b29a1 != 0) goto LAB_801e1db4;
    uVar2 = 0;
  }
  FUN_801e3518(obj,uVar2);
  obj->field_0x51 = 0;
LAB_801e1db4:
  if (obj->field_0x51 == '\0') {
    obj->dmg_table = 0;
    obj->hitbox = &DAT_801e8584 + (uint)obj->anim_extra * 4;
    Enemy_ContactDamage(obj);
    Enemy_CheckWeaponHits(obj);
  }
  obj->clut = (&DAT_80159f64)[obj->bank];
  if ((obj->field_0x57 != '\0') &&
     (bVar1 = obj->field_0x57 - 1, obj->field_0x57 = bVar1, (bVar1 & 1) != 0)) {
    obj->clut = 0;
  }
  if ((obj->var & 0x80) != 0) {
    DAT_801b29a6 = obj->hp;
    return;
  }
  DAT_801b29a5 = obj->hp;
  return;
}


// ---- 801e1e74 FUN_801e1e74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1e74(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e86c8)[obj->sub3])();
  return;
}


// ---- 801e1fb0 FUN_801e1fb0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1fb0(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e86cc)[obj->sub3])();
  if (obj->anim_extra == 4) {
    cVar1 = FUN_801e3704(obj,0);
    if (cVar1 == '\x02') {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x57 = 0x3c;
    }
    else if (cVar1 == '\x04') {
      if ((obj->var & 0x80) == 0) {
        DAT_801b29a3 = DAT_801b29a3 & 0xf | 0x80;
      }
      else {
        DAT_801b29a3 = DAT_801b29a3 & 0xf0 | 8;
      }
      Anim_Set(obj,3);
      obj->sub2 = 4;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      FUN_801e3688(obj);
      obj->field_0x51 = 0;
      FUN_8010544c(obj,9);
    }
  }
  return;
}


// ---- 801e20b8 FUN_801e20b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e20b8(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,2);
    FUN_8010544c(obj,0x1c5);
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,3);
    FUN_801e3a6c(obj);
    obj->sub3 = 1;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e214c FUN_801e214c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e214c(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    Anim_Step();
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
                    /* Possible PsyQ macro: setTile8() */
      obj->field_0x50 = 0x78;
      obj->field_0x4 = 1;
    }
  }
  else if (obj->field_0x50 == '\0') {
    Anim_Set(obj,4);
    FUN_8010544c(obj,0x1c5);
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  return;
}


// ---- 801e21fc FUN_801e21fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e21fc(MM8Obj *obj)

{
  Anim_Step();
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,1);
    if ((obj->var & 0x80) == 0) {
      DAT_801b29a3 = DAT_801b29a3 & 0xf;
    }
    else {
      DAT_801b29a3 = DAT_801b29a3 & 0xf0;
    }
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e2298 FUN_801e2298

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2298(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e86d8)[obj->sub3])();
                    /* Possible PsyQ macro: setPolyGT4() */
  if (obj->anim_extra == 4) {
    cVar1 = FUN_801e3704(obj,0);
                    /* Probable PsyQ macro: setPolyFT4() */
    if (cVar1 == '\x02') {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x57 = 0x3c;
    }
    else if (cVar1 == '\x04') {
      if ((obj->var & 0x80) == 0) {
        DAT_801b29a3 = DAT_801b29a3 & 0xf | 0x80;
      }
      else {
        DAT_801b29a3 = DAT_801b29a3 & 0xf0 | 8;
      }
      Anim_SetAtStep(obj,6,3);
      obj->sub2 = 4;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      FUN_801e3688(obj);
      FUN_8010544c(obj,9);
      obj->field_0x51 = 0;
    }
  }
  return;
}


// ---- 801e23a4 FUN_801e23a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e23a4(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,5);
    FUN_8010544c(obj,0x1c5);
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,6);
    FUN_8010544c(obj,0x1c6);
    obj->sub3 = 1;
    obj->field_0x4 = 0;
    obj->field_0x50 = 0x3c;
  }
  return;
}


// ---- 801e2444 FUN_801e2444

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2444(MM8Obj *obj)

{
  char cVar1;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      FUN_801e3cc4(obj);
      FUN_8010544c(obj,0x1c7);
      obj->field_0x4 = 1;
      obj->field_0x50 = 0x78;
    }
  }
  else {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      Anim_Set(obj,8);
      FUN_8010544c(obj,0x1c5);
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e24f0 FUN_801e24f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e24f0(MM8Obj *obj)

{
  Anim_Step();
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,1);
    if ((obj->var & 0x80) == 0) {
      DAT_801b29a3 = DAT_801b29a3 & 0xf;
    }
    else {
      DAT_801b29a3 = DAT_801b29a3 & 0xf0;
    }
                    /* Possible PsyQ macro: setLineF2() */
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801e258c FUN_801e258c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e258c(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e86e4)[obj->sub3])();
  if (obj->anim_extra == 4) {
    cVar1 = FUN_801e3704(obj,0);
    if (cVar1 == '\x02') {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x57 = 0x3c;
    }
    else if (cVar1 == '\x04') {
      if ((obj->var & 0x80) == 0) {
        DAT_801b29a3 = DAT_801b29a3 & 0xf | 0x80;
      }
      else {
                    /* Possible PsyQ macro: setPolyGT4() */
        DAT_801b29a3 = DAT_801b29a3 & 0xf0 | 8;
      }
      Anim_Set(obj,3);
      obj->sub2 = 4;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      FUN_801e3688(obj);
      FUN_8010544c(obj,9);
      obj->field_0x51 = 0;
    }
  }
                    /* Possible PsyQ macro: setTile8() */
  return;
}


// ---- 801e2694 FUN_801e2694

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2694(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,2);
    FUN_8010544c(obj,0x1c5);
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (obj->anim_extra == 4) {
    Anim_Set(obj,3);
    obj->sub3 = 1;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e2710 FUN_801e2710

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2710(MM8Obj *obj)

{
  byte bVar1;
  
  if ((obj->var & 0x80) == 0) {
    bVar1 = DAT_801b29a3 & 0x10;
  }
  else {
    bVar1 = DAT_801b29a3 & 1;
  }
  if (bVar1 == 0) {
    Anim_Set(obj,4);
    FUN_8010544c(obj,0x1c5);
    obj->sub3 = 2;
  }
  return;
}


// ---- 801e279c FUN_801e279c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e279c(MM8Obj *obj)

{
  Anim_Step();
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,1);
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e27f8 FUN_801e27f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e27f8(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801e86f0)[obj->sub3])();
  obj->hp = 1;
  obj->dmg_table = 0;
  obj->hitbox = &DAT_801e8584 + (uint)obj->anim_extra * 4;
  Enemy_ContactDamage(obj);
  Enemy_CheckWeaponHits(obj);
  obj->hp = 0;
  if ((DAT_80170574 & 1) != 0) {
    obj->x = obj->x + 2;
  }
  return;
}


// ---- 801e28a0 FUN_801e28a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e28a0(MM8Obj *obj)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  if (obj->field_0x4 == '\0') {
    bVar5 = Rand();
    obj->field_0x50 = (bVar5 & 3) + 3;
    obj->field_0x4 = 1;
  }
  iVar4 = (uint)obj->anim_extra * 3;
  if (obj->field_0x50 == '\0') {
    bVar5 = obj->flip;
    iVar9 = 0;
    iVar8 = iVar4;
    do {
      iVar8 = iVar8 * 2;
      uVar2 = obj->x;
      cVar1 = (&DAT_801e85f8)[iVar8];
      uVar3 = obj->y;
      if ((char)bVar5 < '\0') {
        iVar8 = -(int)(char)(&DAT_801e85f9)[iVar8];
      }
      else {
        iVar8 = (int)(char)(&DAT_801e85f9)[iVar8];
      }
      uVar6 = Rand();
      uVar7 = Rand();
      FUN_801091a4(((int)(((int)cVar1 + (uint)uVar2) * 0x10000) >> 0x10) + (uVar6 & 7),
                   ((int)(((uint)uVar3 + iVar8) * 0x10000) >> 0x10) + (uVar7 & 7),1);
      iVar9 = iVar9 + 1;
      iVar8 = iVar9 + iVar4;
    } while (iVar9 < 3);
    obj->field_0x4 = 0;
  }
  else {
    uVar6 = Rand();
    if ((uVar6 & 3) != 0) {
      obj->field_0x50 = obj->field_0x50 + -1;
    }
  }
  return;
}


// ---- 801e29f4 FUN_801e29f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e29f4(MM8Obj *obj)

{
  byte bVar1;
  undefined4 uVar2;
  
  FUN_801e3450();
  if ((obj->var & 0x80) == 0) {
    if ((DAT_801b29a2 & 1) == 0) {
LAB_801e2a78:
      if ((obj->sub2 != 3) && ((DAT_801b29a3 & 0x88) == 0x88)) {
        obj->sub2 = 3;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
        obj->field_0x51 = 0;
        FUN_8010544c(obj,9);
      }
      (*(code *)(&PTR_FUN_801e86f4)[obj->sub2])(obj);
      if (obj->sub2 == 3) {
        return;
      }
      if (obj->field_0x51 == '\0') {
        obj->dmg_table = 0;
        obj->hitbox = &UNK_801e8598 + (uint)obj->anim_extra * 4;
        Enemy_ContactDamage(obj);
        Enemy_CheckWeaponHits(obj);
      }
      obj->clut = (&DAT_80159f64)[obj->bank];
      if (obj->field_0x57 == '\0') {
        return;
      }
      bVar1 = obj->field_0x57 - 1;
      obj->field_0x57 = bVar1;
      if ((bVar1 & 1) == 0) {
        return;
      }
      obj->clut = 0;
      return;
    }
    uVar2 = 0x39;
  }
  else {
    if ((DAT_801b29a2 & 2) == 0) goto LAB_801e2a78;
    uVar2 = 0x3a;
  }
  FUN_8012ae08(obj,uVar2);
  FUN_801e4020(obj);
  Obj_Free(obj);
  return;
}


// ---- 801e2b7c FUN_801e2b7c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2b7c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8704)[obj->sub3])();
  return;
}


// ---- 801e2bb8 FUN_801e2bb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2bb8(MM8Obj *obj)

{
  byte bVar1;
  
  obj->field_0x51 = 0;
  if ((obj->var & 0x80) == 0) {
    bVar1 = 1;
                    /* Possible PsyQ macro: setPolyGT4() */
    if (((DAT_801b29a4 & 0x40) == 0) && (bVar1 = 2, (DAT_801b29a4 & 0x10) == 0)) {
      if ((obj->var & 0x80) == 0) goto LAB_801e2c5c;
      goto LAB_801e2c40;
    }
  }
  else {
    if ((DAT_801b29a4 & 4) != 0) {
      obj->sub2 = 1;
      goto LAB_801e2c5c;
    }
LAB_801e2c40:
    bVar1 = 2;
    if ((DAT_801b29a4 & 1) == 0) goto LAB_801e2c5c;
  }
  obj->sub2 = bVar1;
LAB_801e2c5c:
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  Anim_Step();
  return;
}


// ---- 801e2c78 caseD_1

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801e2c70::caseD_1(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e8708)[obj->sub3])();
  if (obj->anim_extra == 3) {
    cVar1 = FUN_801e3704(obj,1);
    if (cVar1 == '\x02') {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x57 = 0x3c;
    }
    else if (cVar1 == '\x04') {
      if ((obj->var & 0x80) == 0) {
        DAT_801b29a4 = DAT_801b29a4 & 0xf | 0x80;
      }
      else {
        DAT_801b29a4 = DAT_801b29a4 & 0xf0 | 8;
      }
      Anim_Set(obj,0xe);
      obj->sub2 = 3;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      FUN_8010544c(obj,9);
      obj->field_0x51 = 0;
    }
  }
  return;
}


// ---- 801e2d74 FUN_801e2d74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2d74(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,0xd);
    FUN_8010544c(obj,0x1c5);
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,0xe);
    FUN_801e3b90(obj);
    obj->sub3 = 1;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e2e08 FUN_801e2e08

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2e08(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    Anim_Step();
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
                    /* Possible PsyQ macro: setTile8() */
      obj->field_0x50 = 0x78;
      obj->field_0x4 = 1;
    }
  }
  else if (obj->field_0x50 == '\0') {
    Anim_Set(obj,0xf);
    FUN_8010544c(obj,0x1c5);
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  return;
}


// ---- 801e2eb8 FUN_801e2eb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2eb8(MM8Obj *obj)

{
  Anim_Step();
                    /* Possible PsyQ macro: setPolyFT4() + setSemiTrans(polyFT4, 1) */
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,0x12);
    if ((obj->var & 0x80) == 0) {
      DAT_801b29a4 = DAT_801b29a4 & 0xf;
    }
    else {
      DAT_801b29a4 = DAT_801b29a4 & 0xf0;
    }
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e2f54 FUN_801e2f54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2f54(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e8714)[obj->sub3])();
  if (obj->anim_extra == 3) {
    cVar1 = FUN_801e3704(obj,1);
    if (cVar1 == '\x02') {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x57 = 0x3c;
    }
    else if (cVar1 == '\x04') {
      if ((obj->var & 0x80) == 0) {
        DAT_801b29a4 = DAT_801b29a4 & 0xf | 0x80;
      }
      else {
        DAT_801b29a4 = DAT_801b29a4 & 0xf0 | 8;
      }
      Anim_Set(obj,0xe);
      obj->sub2 = 3;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      FUN_8010544c(obj,9);
      obj->field_0x51 = 0;
    }
  }
  return;
}


// ---- 801e3050 FUN_801e3050

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3050(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,0xd);
    FUN_8010544c(obj,0x1c5);
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (obj->anim_extra == 3) {
    Anim_Set(obj,0xe);
    obj->sub3 = 1;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e30cc FUN_801e30cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e30cc(MM8Obj *obj)

{
  byte bVar1;
  
  if ((obj->var & 0x80) == 0) {
    bVar1 = DAT_801b29a4 & 0x10;
  }
  else {
    bVar1 = DAT_801b29a4 & 1;
  }
  if (bVar1 == 0) {
    Anim_Set(obj,0xf);
    FUN_8010544c(obj,0x1c5);
    obj->sub3 = 2;
  }
  return;
}


// ---- 801e3158 FUN_801e3158

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3158(MM8Obj *obj)

{
  Anim_Step();
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,0x12);
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e31b4 FUN_801e31b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e31b4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8720)[obj->sub3])();
  obj->hp = 1;
  obj->dmg_table = 0;
  obj->hitbox = &UNK_801e8598 + (uint)obj->anim_extra * 4;
  Enemy_ContactDamage(obj);
  Enemy_CheckWeaponHits(obj);
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->hp = 0;
  if ((DAT_80170574 & 1) != 0) {
    obj->y = obj->y + 2;
  }
  return;
}


// ---- 801e325c FUN_801e325c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e325c(MM8Obj *obj)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
                    /* Possible PsyQ macro: setTile8() */
  if (obj->field_0x4 == '\0') {
    bVar5 = Rand();
    obj->field_0x50 = (bVar5 & 3) + 3;
    obj->field_0x4 = 1;
  }
  iVar4 = (uint)obj->anim_extra * 3;
  if (obj->field_0x50 == '\0') {
    bVar5 = obj->flip;
    iVar9 = 0;
    iVar8 = iVar4;
    do {
      iVar8 = iVar8 * 2;
      uVar2 = obj->x;
      cVar1 = (&DAT_801e8618)[iVar8];
      uVar3 = obj->y;
      if ((char)bVar5 < '\0') {
        iVar8 = -(int)(char)(&DAT_801e8619)[iVar8];
      }
      else {
        iVar8 = (int)(char)(&DAT_801e8619)[iVar8];
      }
      uVar6 = Rand();
      uVar7 = Rand();
      FUN_801091a4(((int)(((int)cVar1 + (uint)uVar2) * 0x10000) >> 0x10) + (uVar6 & 7),
                   ((int)(((uint)uVar3 + iVar8) * 0x10000) >> 0x10) + (uVar7 & 7),1);
      iVar9 = iVar9 + 1;
      iVar8 = iVar9 + iVar4;
    } while (iVar9 < 3);
    obj->field_0x4 = 0;
  }
  else {
    uVar6 = Rand();
    if ((uVar6 & 3) != 0) {
      obj->field_0x50 = obj->field_0x50 + -1;
    }
  }
  return;
}


// ---- 801e33b0 FUN_801e33b0

void FUN_801e33b0(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = 0;
                    /* Possible PsyQ macro: setLineF2() */
  do {
    puVar2 = (undefined1 *)FUN_801055e4(param_1);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x59;
                    /* Possible PsyQ macro: setLineF2() + setSemiTrans(lineF2, 1) */
      bVar1 = (byte)((uVar4 & 1) << 7);
      if ((uVar4 & 2) == 0) {
        bVar1 = bVar1 | 1;
      }
      else {
        bVar1 = bVar1 | 2;
      }
      puVar2[7] = bVar1;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      uVar3 = *(undefined4 *)(param_1 + 0x10);
      uVar4 = uVar4 + 1;
      puVar2[1] = 0;
      *(int *)(puVar2 + 0x4c) = param_1;
      *(undefined4 *)(puVar2 + 0x10) = uVar3;
    }
  } while ((int)uVar4 < 4);
  return;
}


// ---- 801e3450 FUN_801e3450

void FUN_801e3450(int param_1)

{
  char cVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x10);
  uVar2 = (uint)(*(byte *)(param_1 + 7) >> 7);
  if ((*(byte *)(param_1 + 7) & 1) == 0) {
    *(short *)(param_1 + 0xe) = (short)(char)(&DAT_801e85f4)[uVar2 * 2] + *(short *)(param_1 + 0xe);
    cVar1 = (&DAT_801e85f5)[(uint)(*(byte *)(param_1 + 7) >> 7) * 2];
  }
  else {
    *(short *)(param_1 + 0xe) = (short)(char)(&DAT_801e85f0)[uVar2 * 2] + *(short *)(param_1 + 0xe);
    cVar1 = (&DAT_801e85f1)[(uint)(*(byte *)(param_1 + 7) >> 7) * 2];
  }
  *(short *)(param_1 + 0x12) = (short)cVar1 + *(short *)(param_1 + 0x12);
  return;
}


// ---- 801e3518 FUN_801e3518

void FUN_801e3518(int param_1,char param_2)

{
  undefined1 *puVar1;
  char *pcVar2;
  
  if (*(char *)(param_1 + 0x52) == '\0') {
    puVar1 = (undefined1 *)Obj_AllocType3();
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar1[6] = 0x3e;
      puVar1[7] = param_2;
      *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      *(short *)(puVar1 + 0xe) =
           (short)(char)(&DAT_801e8630)[(uint)*(byte *)(param_1 + 0x32) * 2] +
           *(short *)(puVar1 + 0xe);
      if ((*(byte *)(param_1 + 0x25) & 0x80) == 0) {
        *(short *)(puVar1 + 0x12) =
             (short)(char)(&DAT_801e8631)[(uint)*(byte *)(param_1 + 0x32) * 2] +
             *(short *)(puVar1 + 0x12);
      }
      else {
                    /* Possible PsyQ macro: setPolyGT4() */
        *(short *)(puVar1 + 0x12) =
             *(short *)(puVar1 + 0x12) -
             (short)(char)(&DAT_801e8631)[(uint)*(byte *)(param_1 + 0x32) * 2];
      }
      *(int *)(puVar1 + 0x1c) = param_1;
      *(undefined1 **)(param_1 + 0x14) = puVar1;
      *(undefined1 *)(param_1 + 0x52) = 1;
      return;
    }
  }
  else {
    pcVar2 = *(char **)(param_1 + 0x14);
                    /* Possible PsyQ macro: setLineF2() */
    if (((*pcVar2 != '\0') && (pcVar2[6] == '>')) && (*(int *)(pcVar2 + 0x1c) == param_1)) {
      pcVar2[7] = param_2;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x52) = 0;
                    /* Probable PsyQ macro: setTile8() */
  return;
}


// ---- 801e3688 FUN_801e3688

void FUN_801e3688(int param_1)

{
  char *pcVar1;
  
  if (*(char *)(param_1 + 0x52) != '\0') {
    pcVar1 = *(char **)(param_1 + 0x14);
    if (((*pcVar1 != '\0') && (pcVar1[6] == '>')) && (*(int *)(pcVar1 + 0x1c) == param_1)) {
      Obj_Free();
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 0x52) = 0;
  }
  return;
}


// ---- 801e3704 FUN_801e3704

undefined1 FUN_801e3704(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  if (*(char *)(param_1 + 0x57) == '\0') {
    uVar4 = 0;
    *(undefined1 *)(param_1 + 0x44) = 0x25;
    iVar3 = 0;
    if (g_player != '\0') {
      iVar2 = param_2 * 3;
      do {
        *(undefined **)(param_1 + 0x3c) = &UNK_801e85a8 + iVar2 * 4;
        cVar1 = Enemy_CheckWeaponHits(param_1);
                    /* Possible PsyQ macro: setPolyF3() */
        if (cVar1 == '\x02') {
          uVar4 = 2;
        }
        iVar3 = iVar3 + 1;
        if (cVar1 == '\x04') {
          return 4;
        }
        iVar2 = iVar3 + param_2 * 3;
      } while (iVar3 < 3);
    }
  }
  return uVar4;
}


// ---- 801e37e0 FUN_801e37e0

void FUN_801e37e0(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(param_1 + 0x54);
  if (bVar1 == 1) {
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
    Anim_Step(param_1);
                    /* Possible PsyQ macro: setPolyGT4() */
    if ((*(short *)(param_1 + 0x2e) < 0) && (*(char *)(param_1 + 0x31) == '\x01')) {
      Anim_Set(param_1,0x14);
      uVar4 = Rand();
      uVar2 = (&DAT_801e85c0)[uVar4 & 0xf];
                    /* Possible PsyQ macro: setPolyF4() */
      *(undefined1 *)(param_1 + 0x54) = 2;
      *(undefined1 *)(param_1 + 0x53) = uVar2;
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      if (*(char *)(param_1 + 0x52) == '\0') {
        Anim_Set(param_1,0x13);
        *(undefined1 *)(param_1 + 0x54) = 1;
      }
      else {
        *(char *)(param_1 + 0x52) = *(char *)(param_1 + 0x52) + -1;
      }
    }
  }
  else if (bVar1 == 2) {
    Anim_Step(param_1);
    if ((*(short *)(param_1 + 0x2e) < 0) && (*(char *)(param_1 + 0x31) == '\x01')) {
      puVar3 = (undefined1 *)FUN_801055e4(param_1);
      if (puVar3 != (undefined1 *)0x0) {
                    /* Possible PsyQ macro: setPolyF4() */
        *puVar3 = 1;
        puVar3[6] = 0x60;
        puVar3[7] = 2;
        FUN_8010544c(param_1,0x1c4);
      }
      *(char *)(param_1 + 0x53) = *(char *)(param_1 + 0x53) + -1;
      if (*(char *)(param_1 + 0x53) == '\0') {
        Anim_Set(param_1,0x15);
        uVar4 = Rand();
        uVar2 = (&DAT_801e85d0)[uVar4 & 0xf];
        *(undefined1 *)(param_1 + 0x54) = 3;
        *(undefined1 *)(param_1 + 0x52) = uVar2;
      }
      else {
        Anim_Set(param_1,0x14);
      }
    }
  }
  else if (((bVar1 == 3) && (Anim_Step(param_1), *(short *)(param_1 + 0x2e) < 0)) &&
          (*(char *)(param_1 + 0x31) == '\x01')) {
    Anim_Set(param_1,0);
    *(undefined1 *)(param_1 + 0x54) = 0;
  }
  return;
}


// ---- 801e39d0 FUN_801e39d0

void FUN_801e39d0(int param_1)

{
  byte bVar1;
  uint uVar2;
  
LAB_801e39e0:
  do {
    uVar2 = Rand();
    if (*(byte *)(param_1 + 0x56) >> 4 == (&DAT_801e85e0)[uVar2 & 0xf]) {
      bVar1 = *(byte *)(param_1 + 0x56) + 1;
      if (2 < (*(byte *)(param_1 + 0x56) & 0xf)) goto LAB_801e39e0;
    }
    else {
      bVar1 = (&DAT_801e85e0)[uVar2 & 0xf] << 4 | 1;
    }
    *(byte *)(param_1 + 0x56) = bVar1;
    if ((*(byte *)(param_1 + 0x56) >> 4 != 4) || ((DAT_801b29a4 & 0x88) != 0x88)) {
      return;
    }
  } while( true );
}


// ---- 801e3a6c FUN_801e3a6c

void FUN_801e3a6c(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = *(byte *)(param_1 + 0x32);
  iVar4 = 0;
  do {
    puVar2 = (undefined1 *)FUN_801055e4(param_1);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x60;
      puVar2[7] = 3;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      iVar3 = (iVar4 + (uint)bVar1 * 3) * 2;
      *(short *)(puVar2 + 0xe) =
           (short)(char)(&DAT_801e85f8)[iVar3] + *(short *)(puVar2 + 0xe) + -0xc;
      if ((*(byte *)(param_1 + 7) & 0x80) == 0) {
        *(short *)(puVar2 + 0x12) = (short)(char)(&DAT_801e85f9)[iVar3] + *(short *)(puVar2 + 0x12);
      }
      else {
        *(short *)(puVar2 + 0x12) = *(short *)(puVar2 + 0x12) - (short)(char)(&DAT_801e85f9)[iVar3];
      }
      *(int *)(puVar2 + 0x4c) = param_1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  FUN_8010544c(param_1,0xc);
  return;
}


// ---- 801e3b90 FUN_801e3b90

void FUN_801e3b90(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = *(byte *)(param_1 + 0x32);
  iVar5 = 0;
  do {
    puVar3 = (undefined1 *)FUN_801055e4(param_1);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 0x60;
      puVar3[7] = 4;
      puVar3[0x55] = (char)iVar5;
                    /* Probable PsyQ macro: setTile16() */
      *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      iVar4 = (iVar5 + (uint)bVar1 * 3) * 2;
      *(short *)(puVar3 + 0xe) = (short)(char)(&DAT_801e8618)[iVar4] + *(short *)(puVar3 + 0xe);
                    /* Possible PsyQ macro: setPolyGT4() */
      if ((*(byte *)(param_1 + 0x25) & 0x80) == 0) {
        *(short *)(puVar3 + 0x12) =
             (short)(char)(&DAT_801e8619)[iVar4] + *(short *)(puVar3 + 0x12) + -8;
      }
      else {
                    /* Possible PsyQ macro: setPolyGT4() */
        *(short *)(puVar3 + 0x12) =
             (*(short *)(puVar3 + 0x12) - (short)(char)(&DAT_801e8619)[iVar4]) + 8;
      }
      uVar2 = *(undefined1 *)(param_1 + 0x25);
      *(int *)(puVar3 + 0x4c) = param_1;
      puVar3[0x25] = uVar2;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  FUN_8010544c(param_1,0xc);
  return;
}


// ---- 801e3cc4 FUN_801e3cc4

void FUN_801e3cc4(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = *(byte *)(param_1 + 0x32);
  iVar4 = 0;
  do {
    puVar2 = (undefined1 *)FUN_801055e4(param_1);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x60;
      puVar2[7] = 0;
      puVar2[0x55] = (char)iVar4;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      iVar3 = (iVar4 + (uint)bVar1 * 3) * 2;
      *(short *)(puVar2 + 0xe) = (short)(char)(&DAT_801e85f8)[iVar3] + *(short *)(puVar2 + 0xe) + -4
      ;
      if ((*(byte *)(param_1 + 7) & 0x80) == 0) {
        *(short *)(puVar2 + 0x12) = (short)(char)(&DAT_801e85f9)[iVar3] + *(short *)(puVar2 + 0x12);
      }
      else {
        *(short *)(puVar2 + 0x12) = *(short *)(puVar2 + 0x12) - (short)(char)(&DAT_801e85f9)[iVar3];
      }
      *(int *)(puVar2 + 0x4c) = param_1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801e3de0 FUN_801e3de0

/* WARNING: Removing unreachable block (ram,0x801e3e88) */

void FUN_801e3de0(int param_1)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  
  uVar6 = 0;
  pcVar4 = &DAT_801e863d;
  pcVar5 = &DAT_801e863c;
  sVar1 = *(short *)(param_1 + 0xe);
  sVar2 = *(short *)(param_1 + 0x12);
  do {
    if ((((uint)DAT_801b29a2 & 1 << (uVar6 & 0x1f)) != 0) && (uVar3 = Rand(), (uVar3 & 7) == 7)) {
      uVar3 = Rand();
      FUN_801091a4((int)sVar1 + (int)*pcVar5,
                   (int)sVar2 + (int)*pcVar4 + ((int)(((uVar3 & 0xf) - 8) * 0x10000) >> 0x10),1);
    }
    pcVar4 = pcVar4 + 2;
    uVar6 = uVar6 + 1;
    pcVar5 = pcVar5 + 2;
  } while ((int)uVar6 < 4);
  return;
}


// ---- 801e3ee8 FUN_801e3ee8

void FUN_801e3ee8(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  cVar1 = *(char *)(param_1 + 0x25);
  iVar2 = (uint)*(byte *)(param_1 + 0x32) * 3;
  iVar5 = iVar2;
  do {
    iVar5 = iVar5 * 2;
    iVar6 = (int)(char)(&DAT_801e85f8)[iVar5] + (uint)*(ushort *)(param_1 + 0xe);
    if (cVar1 < '\0') {
      iVar5 = -(int)(char)(&DAT_801e85f9)[iVar5];
    }
    else {
      iVar5 = (int)(char)(&DAT_801e85f9)[iVar5];
    }
    iVar5 = (uint)*(ushort *)(param_1 + 0x12) + iVar5;
    iVar7 = iVar7 + 1;
    uVar3 = Rand();
    uVar4 = Rand();
    FUN_80108ed8(param_1,(int)((iVar6 + (uVar3 & 7)) * 0x10000) >> 0x10,
                 (int)((iVar5 + (uVar4 & 7)) * 0x10000) >> 0x10);
    uVar3 = Rand();
    uVar4 = Rand();
    FUN_8012a724(param_1,1,(int)((iVar6 + (uVar3 & 7)) * 0x10000) >> 0x10,
                 (int)((iVar5 + (uVar4 & 7)) * 0x10000) >> 0x10);
    iVar5 = iVar7 + iVar2;
  } while (iVar7 < 3);
  return;
}


// ---- 801e4020 FUN_801e4020

void FUN_801e4020(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  cVar1 = *(char *)(param_1 + 0x25);
  iVar2 = (uint)*(byte *)(param_1 + 0x32) * 3;
  iVar5 = iVar2;
  do {
    iVar5 = iVar5 * 2;
    iVar6 = (int)(char)(&DAT_801e8618)[iVar5] + (uint)*(ushort *)(param_1 + 0xe);
    if (cVar1 < '\0') {
      iVar5 = -(int)(char)(&DAT_801e8619)[iVar5];
    }
    else {
      iVar5 = (int)(char)(&DAT_801e8619)[iVar5];
    }
    iVar5 = (uint)*(ushort *)(param_1 + 0x12) + iVar5;
    iVar7 = iVar7 + 1;
    uVar3 = Rand();
    uVar4 = Rand();
    FUN_80108ed8(param_1,(int)((iVar6 + (uVar3 & 7)) * 0x10000) >> 0x10,
                 (int)((iVar5 + (uVar4 & 7)) * 0x10000) >> 0x10);
    uVar3 = Rand();
                    /* Possible PsyQ macro: setTile16() */
    uVar4 = Rand();
    FUN_8012a724(param_1,1,(int)((iVar6 + (uVar3 & 7)) * 0x10000) >> 0x10,
                 (int)((iVar5 + (uVar4 & 7)) * 0x10000) >> 0x10);
    iVar5 = iVar7 + iVar2;
  } while (iVar7 < 3);
  return;
}


