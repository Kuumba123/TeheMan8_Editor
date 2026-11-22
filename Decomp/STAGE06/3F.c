// ID 3F, STAGE06.BIN, handler 0x801DFB9C. Ghidra output with the object struct applied; not matching C.
// ---- 801dfb9c FUN_801dfb9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfb9c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5a74)[obj->var])();
  return;
}


// ---- 801dfbd8 FUN_801dfbd8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfbd8(MM8Obj *obj)

{
  obj->clut = obj->field_0x5c;
  (*(code *)(&PTR_FUN_801e5a80)[obj->state])();
  if (obj->state < 3) {
    if ((obj->field_0x51 != '\0') && (obj->sub3 - 3 < 2)) goto LAB_801dfc7c;
  }
  else if ((obj->state != 3) || ((DAT_80170574 & 1) == 0)) goto LAB_801dfc7c;
  Obj_CullAndQueueDrawMargin(obj,0x40);
LAB_801dfc7c:
  if (obj->field_0x5b != '\0') {
    Obj_Free(obj);
  }
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  return;
}


// ---- 801dfca8 FUN_801dfca8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfca8(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->speed_y_up = -0x80000;
  obj->box2 = &DAT_801e5a4c;
  obj->hitbox = &DAT_801e5a40;
  obj->field_0x5a = 1;
  obj->draw_list = 8;
  obj->field_0x57 = 8;
  obj->field_0x56 = 8;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->flip = 0;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  obj->field_0x54 = 0;
  obj->field_0x5b = 0;
  obj->field_0x5d = 0;
  obj->state = obj->state + 1;
  obj->field_0x5c = obj->clut;
  FUN_801e146c(obj,0);
  FUN_801e146c(obj,1);
  Anim_SetAtStep(obj,0,obj->field_0x56);
  return;
}


// ---- 801dfd68 FUN_801dfd68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfd68(MM8Obj *obj)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  
  FUN_80104d18();
  if (obj->sub2 == 0) {
    if (g_cam_y + 0x130 <= (int)obj->y) {
      obj->x = 0xda0;
      obj->y = 0x800;
      obj->speed_x = 0x8000;
      obj->accel_x = 0x400;
      obj->speed_y_up = 0;
      obj->sub2 = obj->sub2 + 1;
      uVar3 = FUN_801050e4(obj,&g_player);
      uVar1 = (undefined1)((uVar3 & 0xff) >> 4);
      obj->field_0x57 = uVar1;
      obj->field_0x56 = uVar1;
      obj->field_0x5a = 0;
      Anim_SetAtStep(obj,0,obj->field_0x57);
    }
  }
  else {
    cVar2 = Obj_InActiveArea(obj);
    if (cVar2 != '\0') {
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->state = obj->state + 1;
    }
  }
  return;
}


// ---- 801dfe4c FUN_801dfe4c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfe4c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  (*(code *)(&PTR_LAB_801e5a94)[obj->sub2])();
  if ((int)obj->x < DAT_801d2918._2_2_ + 0x40) {
    obj->speed_x = 0x8000;
    iVar3 = 0x400;
  }
  else {
    if ((int)obj->x <= DAT_801d2918._2_2_ + 0x100) goto LAB_801dfec4;
    obj->speed_x = -0x8000;
    iVar3 = -0x400;
  }
  obj->accel_x = iVar3;
LAB_801dfec4:
  if (obj->field_0x51 == '\0') {
    if (obj->field_0x5d == '\0') {
      cVar1 = Enemy_CheckWeaponHits(obj);
      if (cVar1 == '\x02') {
                    /* Possible PsyQ macro: setPolyGT4() */
        obj->field_0x5d = 0x3c;
        FUN_8010544c(obj,0x10);
      }
      else if (cVar1 == '\x04') {
                    /* Possible PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setTile8() */
        obj->sub2 = 0;
        obj->sub3 = 0;
        obj->field_0x5a = 0;
        obj->state = obj->state + 1;
        return;
      }
    }
    else {
      bVar2 = obj->hp;
                    /* Possible PsyQ macro: setPolyF4() */
      obj->hp = 0x28;
      obj->field_0x5e = bVar2;
      cVar1 = Enemy_CheckWeaponHits(obj);
      if (cVar1 == '\x02') {
        FUN_8010544c(obj,0x4f);
      }
      bVar2 = obj->field_0x5d - 1;
      obj->field_0x5d = bVar2;
      obj->hp = obj->field_0x5e;
      if ((bVar2 & 1) == 0) {
        obj->clut = obj->field_0x5c;
      }
      else {
        obj->clut = 0;
      }
    }
    Enemy_ContactDamage(obj);
    FUN_801e14d4(obj);
  }
  else {
    obj->field_0x5d = 0;
  }
  return;
}


// ---- 801e0d00 FUN_801e0d00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0d00(MM8Obj *obj)

{
  uint uVar1;
  uint uVar2;
  
  (*(code *)(&PTR_FUN_801e5af4)[obj->sub2])();
  if ((DAT_80170574 & 7) == 0) {
    uVar1 = Rand();
    uVar2 = Rand();
    FUN_80108ed8(obj,(int)((0x1f - (uVar1 & 0x3f)) * 0x10000) >> 0x10,
                 (int)((0x1f - (uVar2 & 0x3f)) * 0x10000) >> 0x10);
    FUN_8012a5fc(obj,0);
  }
  return;
}


// ---- 801e0db4 FUN_801e0db4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0db4(MM8Obj *obj)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = &DAT_801cf540;
  pcVar2 = &DAT_801cf541;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 0x18;
    if ((cVar1 != '\0') && (pcVar2[5] == '+')) {
      *pcVar2 = *pcVar2 + '\x01';
      obj->speed_y_up = -0x40000;
      obj->gravity = 0;
      obj->field_0x55 = 0;
      obj->sub2 = obj->sub2 + 1;
      Anim_Set(obj,0);
      FUN_801119e0(0xd30,0x40);
      DAT_801b2992 = 1;
      DAT_801b2993 = 1;
      DAT_801b2994 = 1;
    }
    pcVar2 = pcVar2 + 0x18;
  } while (pcVar3 < &DAT_801cf840);
  return;
}


// ---- 801e0e94 FUN_801e0e94

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0e94(MM8Obj *obj)

{
  int iVar1;
  
  obj->field_0x57 = obj->field_0x57 + '\x01';
  if (0xf < (byte)obj->field_0x57) {
    obj->field_0x57 = 0;
  }
  Anim_SetAtStep(obj,0,obj->field_0x57);
  if ((int)obj->x < DAT_801d2918._2_2_ + 0x40) {
    obj->speed_x = 0x8000;
    iVar1 = 0x400;
  }
  else {
    if ((int)obj->x <= DAT_801d2918._2_2_ + 0x100) goto LAB_801e0f1c;
                    /* Possible PsyQ macro: setTile8() */
    obj->speed_x = -0x8000;
    iVar1 = -0x400;
  }
  obj->accel_x = iVar1;
LAB_801e0f1c:
  Obj_ApplySpeed(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x50 = 8;
    obj->sub2 = obj->sub2 + 1;
    DAT_801d2938 = 0x3c;
  }
  return;
}


// ---- 801e0f70 FUN_801e0f70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0f70(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  iVar5 = 0;
  if (cVar1 == '\0') {
    do {
      iVar5 = iVar5 + 1;
      uVar2 = Rand();
      uVar3 = Rand();
      FUN_80108ed8(obj,(int)((0x1f - (uVar2 & 0x3f)) * 0x10000) >> 0x10,
                   (int)((0x1f - (uVar3 & 0x3f)) * 0x10000) >> 0x10);
      FUN_8012a5fc(obj,0);
    } while (iVar5 < 8);
    if ((DAT_8016d303 == '\0') &&
       (puVar4 = (undefined1 *)Obj_AllocType2(), puVar4 != (undefined1 *)0x0)) {
      puVar4[6] = 0x26;
      *puVar4 = 1;
      puVar4[7] = 3;
                    /* Possible PsyQ macro: setPolyG4() */
      *(short *)(puVar4 + 0xe) = obj->x;
      *(short *)(puVar4 + 0x12) = obj->y + -0x10;
      obj->field_0x5b = 1;
      FUN_80111918();
      DAT_801b2992 = 0;
                    /* Possible PsyQ macro: setTile8() */
      DAT_801b2993 = 0;
      DAT_801b2994 = 0;
    }
    obj->sub2 = 0;
    obj->state = obj->state + 1;
  }
  return;
}


// ---- 801e10a4 FUN_801e10a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e10a4(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  if (obj->sub2 == 0) {
    if ((g_cam_y == 0xbf9) && (DAT_8015e248._2_2_ == 0xd30)) {
      obj->sub2 = obj->sub2 + 1;
      DAT_801d2926 = 0xd60;
                    /* Possible PsyQ macro: setPolyF4() */
      DAT_801d292e = 0xd60;
      FUN_801119e0(0xe90,0x40);
    }
  }
  else if (0xe60 < DAT_8015e248._2_2_) {
    DAT_801b2995 = 0x80;
    obj->field_0x5b = 1;
  }
  return;
}


// ---- 801e1150 FUN_801e1150

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1150(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5b00)[obj->state])();
  Obj_CullAndQueueDrawMargin(obj,0x40);
  if (obj->field_0x5b != '\0') {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e11bc FUN_801e11bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e11bc(MM8Obj *obj)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x50;
  Enemy_InitFromTable();
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->state = obj->state + 1;
  uVar1 = *(undefined4 *)(iVar2 + 0xc);
  obj->x_frac = (short)uVar1;
  obj->x = (short)((uint)uVar1 >> 0x10);
  uVar1 = *(undefined4 *)(iVar2 + 0x10);
  obj->draw_list = 8;
  obj->hitbox = &DAT_801e5a44;
  obj->invuln = 1;
  obj->field_0x5b = 0;
  obj->y_frac = (short)uVar1;
  obj->y = (short)((uint)uVar1 >> 0x10);
  Anim_Set(obj,0x16);
  return;
}


// ---- 801e1244 FUN_801e1244

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1244(MM8Obj *obj)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = *(int *)&obj->field_0x50;
  uVar1 = *(undefined4 *)(iVar3 + 0xc);
  obj->x_frac = (short)uVar1;
  obj->x = (short)((uint)uVar1 >> 0x10);
  uVar1 = *(undefined4 *)(iVar3 + 0x10);
  obj->y_frac = (short)uVar1;
  obj->y = (short)((uint)uVar1 >> 0x10);
  if ((*(byte *)(iVar3 + 0x5d) & 1) == 0) {
    obj->clut = DAT_80159fcd;
  }
  else {
    obj->clut = 0;
  }
  Anim_Step(obj);
  bVar2 = obj->anim_extra;
  if (bVar2 == 1) {
    Enemy_ContactDamage(obj);
    FUN_801e14d4(obj);
                    /* Possible PsyQ macro: setPolyF4() */
    bVar2 = obj->anim_extra;
  }
  if ((bVar2 == 2) || (*(char *)(iVar3 + 1) == '\x03')) {
    obj->field_0x5b = 1;
  }
  return;
}


// ---- 801e130c FUN_801e130c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e130c(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e5b08)[obj->state])();
  Obj_CullAndQueueDrawMargin(obj,0x40);
  cVar1 = FUN_80104820(obj,0,0x40);
  if (cVar1 == '\0') {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e1384 FUN_801e1384

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1384(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->speed_y_up = -0x40000;
  obj->gravity = 0x4000;
  obj->draw_list = 8;
  obj->hitbox = &DAT_801e5a48;
  obj->invuln = 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->flip = 0;
  obj->contact_dmg = 4;
  obj->state = obj->state + 1;
  Anim_Set(obj,0x17);
  return;
}


// ---- 801e1404 FUN_801e1404

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1404(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT3() */
  if (obj->speed_y_up < -0x9ffff) {
    FUN_80104d18(obj);
  }
  else {
    Obj_ApplySpeed();
  }
  Anim_Step(obj);
  Enemy_ContactDamage(obj);
  FUN_801e14d4(obj);
  return;
}


// ---- 801e146c FUN_801e146c

void FUN_801e146c(int param_1,undefined1 param_2)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x2c;
    puVar2[7] = param_2;
    *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    uVar1 = *(undefined2 *)(param_1 + 0x12);
    *(int *)(puVar2 + 0x38) = param_1;
    *(undefined2 *)(puVar2 + 0x12) = uVar1;
  }
  return;
}


// ---- 801e14d4 FUN_801e14d4

void FUN_801e14d4(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 *puVar3;
  
  pcVar2 = &DAT_801b1eec;
  puVar3 = &DAT_801b1eed;
  do {
    if (((*pcVar2 != '\0') && (puVar3[5] == '\'')) &&
       (iVar1 = Obj_HitboxOverlap(param_1,pcVar2), iVar1 != 0)) {
      *puVar3 = 2;
    }
    pcVar2 = pcVar2 + 0x50;
    puVar3 = puVar3 + 0x50;
  } while (pcVar2 < &DAT_801b28ec);
  return;
}


