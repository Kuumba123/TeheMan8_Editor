// T2_09, STAGE03.BIN, handler 0x801E45B0. Ghidra output with the object struct applied; not matching C.
// ---- 801e45b0 FUN_801e45b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e45b0(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e9e84)[obj->state])();
  if (obj->contact_dmg < 2) {
    Obj_CullAndQueueDraw(obj);
  }
  iVar1 = Obj_InActiveArea(obj);
  if ((iVar1 == 0) && (obj->invuln == 0)) {
    if (((obj->var & 0x7f) == 1) && (g_player != '\0')) {
      FUN_80111918();
    }
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e466c FUN_801e466c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e466c(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  obj->bank = 0x26;
  obj->vram_base = DAT_80170394;
  bVar1 = DAT_80159f8a;
  bVar2 = obj->var & 0x7f;
  obj->invuln = 0;
  obj->hp = 0;
  obj->contact_dmg = 0;
  obj->clut = bVar1;
  if (bVar2 == 1) {
    obj->state = 2;
    obj->draw_list = 5;
    obj->box2 = &DAT_801e9e64;
    obj->speed_y_up = 0x8000;
    obj->hitbox = (byte *)0x0;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->gravity = 0;
    obj->field_0x43 = 1;
    obj->field_0x4e = 0;
    FUN_800fd100(0x8c);
    uVar3 = 3;
  }
  else if (bVar2 < 2) {
    if ((obj->var & 0x7f) != 0) {
      return;
    }
    uVar3 = 0;
    obj->draw_list = 7;
    obj->state = 1;
    obj->flip = 0;
    obj->field_0x43 = 0;
    obj->hitbox = (byte *)0x0;
    obj->box2 = &DAT_801e9e5c;
    obj->invuln = 1;
  }
  else {
    if (bVar2 != 2) {
      return;
    }
    uVar3 = 9;
    obj->state = 3;
    obj->draw_list = 6;
    obj->hitbox = (byte *)0x0;
    obj->box2 = (byte *)0x0;
    obj->field_0x43 = 1;
  }
  Anim_Set(obj,uVar3);
  return;
}


// ---- 801e47b0 FUN_801e47b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e47b0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9e94)[obj->sub2])();
  Anim_Step(obj);
  if (DAT_8015e24c._2_2_ <= *(short *)(&DAT_801e9e7a + (uint)(obj->var >> 7) * 6)) {
    obj->invuln = 0;
  }
  return;
}


// ---- 801e483c FUN_801e483c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e483c(MM8Obj *obj)

{
  byte bVar1;
  
  if (obj->sub3 == 0) {
    if ((short)obj->frame < 0) {
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
      obj->dmg_table = 0x2d;
      obj->sub3 = obj->sub3 + 1;
    }
  }
  else {
    bVar1 = obj->dmg_table - 1;
    obj->dmg_table = bVar1;
    if (bVar1 == 0) {
      obj->sub2 = 1;
      obj->sub3 = 0;
      Anim_Set(obj,1);
    }
  }
  FUN_80107bf4(obj,&g_player,1);
  return;
}


// ---- 801e48dc FUN_801e48dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e48dc(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    obj->sub2 = 2;
    obj->dmg_table = 0xb4;
  }
  FUN_80107bf4(obj,&g_player,1);
  return;
}


// ---- 801e4920 FUN_801e4920

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4920(MM8Obj *obj)

{
  uint uVar1;
  
  uVar1 = FUN_80107bf4(obj,&g_player,1);
  if ((((uVar1 & 0x80) != 0) && (g_player != '\0')) &&
     (((int)obj->x - (int)DAT_8015e248._2_2_) + 0x18U < 0x31)) {
    obj->sub2 = 3;
    uVar1 = (int)obj->x - (int)DAT_8015e248._2_2_;
    if (uVar1 == 0) {
      uVar1 = (uint)DAT_8015e261;
    }
    else {
      uVar1 = (int)~uVar1 >> 0x1f & 0x40;
    }
    obj->invuln = 1;
    DAT_8015e2af = 1;
    DAT_801b2994 = 1;
    FUN_801119e0((int)obj->x,uVar1);
    Anim_Set(obj,2);
  }
  return;
}


// ---- 801e49f8 FUN_801e49f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e49f8(MM8Obj *obj)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_80107bf4(obj,&g_player,1);
  if (obj->sub3 == 0) {
    if (DAT_8015e2b0 != '\x01') {
      return;
    }
    if ((uVar1 & 0x80) == 0) {
      return;
    }
    obj->sub3 = 1;
    iVar2 = FUN_801e4b44(obj);
    if (iVar2 != 0) {
      return;
    }
    DAT_8015e2af = 0;
    uVar3 = 10;
  }
  else {
    if (-1 < (short)obj->frame) {
      return;
    }
    uVar3 = 4;
    obj->sub2 = 4;
    obj->sub3 = 0;
    obj->invuln = 0;
  }
  Anim_Set(obj,uVar3);
  return;
}


// ---- 801e4aa8 FUN_801e4aa8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4aa8(MM8Obj *obj)

{
  byte bVar1;
  
  if (obj->sub3 == 0) {
    if ((short)obj->frame < 0) {
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
      obj->dmg_table = 0x2d;
      obj->sub3 = obj->sub3 + 1;
    }
  }
  else {
    bVar1 = obj->dmg_table - 1;
    obj->dmg_table = bVar1;
    if (bVar1 == 0) {
      obj->sub2 = 0;
      obj->sub3 = 0;
      Anim_Set(obj,0);
    }
  }
  FUN_80107bf4(obj,&g_player,1);
  return;
}


// ---- 801e4b44 FUN_801e4b44

undefined4 FUN_801e4b44(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined1 *)FUN_80105734();
  if (puVar2 == (undefined1 *)0x0) {
    uVar4 = 1;
    if (g_player != '\0') {
      FUN_80111918();
      uVar4 = 1;
    }
  }
  else {
    *puVar2 = 1;
    puVar2[6] = 9;
    puVar2[7] = *(byte *)(param_1 + 7) & 0x80 | 1;
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    puVar2[0x25] = *(undefined1 *)(param_1 + 0x25);
    puVar3 = (undefined1 *)FUN_80105734(puVar2);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 9;
      puVar3[7] = *(byte *)(param_1 + 7) & 0x80 | 2;
      *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      uVar1 = *(undefined1 *)(param_1 + 0x25);
      *(undefined1 **)(puVar3 + 0x48) = puVar2;
      puVar3[0x25] = uVar1;
    }
    *(undefined1 **)(puVar2 + 0x48) = puVar3;
    uVar4 = 0;
  }
  return uVar4;
}


// ---- 801e4c48 FUN_801e4c48

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4c48(MM8Obj *obj)

{
  char *pcVar1;
  
  pcVar1 = *(char **)&obj->target_prio;
  (*(code *)(&PTR_FUN_801e9ea8)[obj->sub2])();
  if (((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) ||
     ((*(uint *)(pcVar1 + 4) & 0x7fff0000) != 0x2090000)) {
    *(undefined4 *)&obj->target_prio = 0;
  }
  else {
    *(undefined4 *)(pcVar1 + 0xc) = *(undefined4 *)&obj->x_frac;
    *(undefined4 *)(pcVar1 + 0x10) = *(undefined4 *)&obj->y_frac;
    pcVar1[0x25] = obj->flip;
  }
  return;
}


// ---- 801e4cf0 FUN_801e4cf0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4cf0(MM8Obj *obj)

{
  if ((obj->frame == 0x27) && (obj->field_0x4e == '\0')) {
    obj->field_0x4e = 1;
    FUN_800fd100(0x8d);
  }
  if ((short)obj->frame < 0) {
    obj->sub2 = 1;
    obj->box2 = &DAT_801e9e69;
    obj->y = obj->y + -0x40;
    Anim_Set(obj,6);
  }
  else {
    Anim_Step(obj);
    obj->box2[3] = obj->anim_extra;
  }
  FUN_80107bf4(obj,&g_player,1);
  return;
}


// ---- 801e4dac FUN_801e4dac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4dac(MM8Obj *obj)

{
  int iVar1;
  
  obj->field_0x4d = 0;
  if ((DAT_8015e294 & 0xa000) == 0) {
    iVar1 = obj->speed_x;
    obj->field_0x4c = 0;
  }
  else {
    if ((DAT_8015e294 & 0x8000) == 0) {
      obj->accel_x = 0x1800;
      DAT_8015e261 = DAT_8015e261 | 0x40;
    }
    else {
      obj->accel_x = -0x1800;
      DAT_8015e261 = DAT_8015e261 & 0xbf;
    }
    FUN_801119e0((int)obj->x,DAT_8015e261);
    obj->field_0x4 = 0;
    if (obj->accel_x < 0) {
      iVar1 = -0x40000;
      obj->field_0x4c = -0x40000 < obj->speed_x;
    }
    else {
      iVar1 = 0x40000;
      obj->field_0x4c = obj->speed_x < 0x40000;
    }
  }
  iVar1 = FUN_801e4ef0(obj,iVar1);
  if ((iVar1 == 0) && (obj->y <= *(short *)(&DAT_801e9e78 + (uint)(obj->var >> 7) * 6))) {
    obj->sub2 = 2;
    obj->gravity = -0x800;
    obj->sub3 = 0;
    obj->field_0x4d = 1;
    obj->hp = 1;
  }
  return;
}


// ---- 801e4ef0 FUN_801e4ef0

undefined4 FUN_801e4ef0(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  if (*(char *)(param_1 + 0x4d) != '\0') {
    if ((*(char *)(param_1 + 4) == '\0') && (uVar3 = 0xfffffa00, *(int *)(param_1 + 0x14) != 0)) {
      *(undefined1 *)(param_1 + 4) = 1;
      if (*(int *)(param_1 + 0x14) < 0) {
        uVar3 = 0x600;
      }
      *(undefined4 *)(param_1 + 0x1c) = uVar3;
    }
    param_2 = 0;
    *(byte *)(param_1 + 0x4c) =
         (byte)((uint)*(undefined4 *)(param_1 + 0x14) >> 0x18) & 0x80 ^
         (byte)((uint)*(undefined4 *)(param_1 + 0x1c) >> 0x18) & 0x80;
  }
  if (*(char *)(param_1 + 0x4c) == '\0') {
    *(undefined4 *)(param_1 + 0x14) = param_2;
    FUN_80104ccc(param_1);
  }
  else {
    Obj_ApplySpeed(param_1);
  }
  Anim_Step(param_1);
  iVar6 = 2;
  do {
    *(undefined **)(param_1 + 0x38) = &DAT_801e9e64 + iVar6 * 5;
    FUN_80106214(param_1);
    if ((*(byte *)(param_1 + 0x33) & 0x30) != 0) {
      *(int *)(param_1 + 0x14) = -(*(int *)(param_1 + 0x14) >> 2);
      *(int *)(param_1 + 0x1c) = -*(int *)(param_1 + 0x1c);
    }
    if (*(char *)(param_1 + 0x47) == '\0') {
      if ((*(char *)(param_1 + 0x42) == '?') || (iVar5 = 0, g_player == '\0')) {
        uVar7 = 1;
        *(undefined1 *)(param_1 + 2) = 3;
        *(undefined1 *)(param_1 + 3) = 0;
        goto LAB_801e50c8;
      }
      pcVar4 = &g_main_pool;
      do {
        iVar5 = iVar5 + 1;
        if (((*pcVar4 != '\0') && (pcVar4[6] == '\x13')) &&
           (iVar1 = FUN_80107d00(param_1,pcVar4), iVar1 != 0)) {
          iVar6 = 4;
          uVar7 = 1;
          *(undefined1 *)(param_1 + 2) = 3;
          *(undefined1 *)(param_1 + 3) = 0;
          break;
        }
        pcVar4 = pcVar4 + 0x60;
      } while (iVar5 < 0x40);
    }
    iVar6 = iVar6 + 1;
    if (3 < iVar6) {
LAB_801e50c8:
      *(undefined **)(param_1 + 0x38) = &DAT_801e9e69;
      uVar2 = FUN_80107bf4(param_1,&g_player,1);
      if ((uVar2 & 0x80) == 0) {
        uVar7 = 1;
        *(undefined1 *)(param_1 + 2) = 3;
        *(undefined1 *)(param_1 + 3) = 0;
      }
      DAT_8015e248 = *(undefined4 *)(param_1 + 0xc);
      return uVar7;
    }
  } while( true );
}


// ---- 801e5138 FUN_801e5138

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5138(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (obj->sub3 == 0) {
    if (0x2ffff < obj->speed_y_up) {
      obj->speed_y_up = 0x30000;
      obj->gravity = 0;
    }
    iVar4._0_2_ = obj->y_frac;
    iVar4._2_2_ = obj->y;
    iVar2 = FUN_801e4ef0(obj,0);
    if (iVar2 == 0) {
      iVar3._0_2_ = obj->y_frac;
      iVar3._2_2_ = obj->y;
      iVar2 = (uint)(obj->var >> 7) * 6;
      if (iVar3 == iVar4) {
        *(int *)&obj->x_frac = *(int *)&obj->x_frac - obj->speed_x;
        sVar1 = -1;
        if (obj->x <= *(short *)(&DAT_801e9e7c + iVar2)) {
          sVar1 = 1;
        }
        obj->x = obj->x + sVar1;
      }
      if (obj->y <= *(short *)(&DAT_801e9e7a + iVar2)) {
        obj->sub3 = 1;
        obj->contact_dmg = 1;
        Anim_Set(obj,8);
        FUN_8012ae08(obj,6);
        FUN_800fd100(0x8e);
        FUN_80111918();
        FUN_80111aa0(DAT_8015e261);
      }
    }
  }
  else {
    if ((short)obj->frame < 0) {
      obj->contact_dmg = 2;
    }
    if (DAT_8015e23e == '\x0e') {
      FUN_80111918();
                    /* Possible PsyQ macro: setPolyGT3() */
      DAT_801b2994 = 0;
      Obj_Free(obj);
    }
    else {
      Anim_Step(obj);
    }
  }
  return;
}


// ---- 801e52bc FUN_801e52bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e52bc(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    obj->sub3 = 1;
    obj->contact_dmg = 1;
    Anim_Set(obj,8);
    FUN_8012ae08(obj,6);
    FUN_800fd100(0x8e);
    if (g_player != '\0') {
      DAT_801b2994 = 0;
      FUN_80111918();
    }
  }
  if ((short)obj->frame < 0) {
    Obj_Free(obj);
  }
  else {
    Anim_Step(obj);
  }
  return;
}


// ---- 801e5368 FUN_801e5368

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5368(MM8Obj *obj)

{
  if ((obj->sub2 == 0) && ((short)obj->frame < 0)) {
    obj->sub2 = obj->sub2 + 1;
    Anim_Set(obj,5);
  }
  else if (*(char *)(*(int *)&obj->target_prio + 0x45) == '\0') {
    Anim_Step();
  }
  else {
    Obj_Free();
  }
  return;
}


