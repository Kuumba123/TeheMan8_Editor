// ID 05, STAGE01.BIN, handler 0x801D8550. Ghidra output with the object struct applied; not matching C.
// ---- 801d8550 FUN_801d8550

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8550(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  obj->field_0x57 = 0;
  if (obj->state != 0) {
    cVar2 = Enemy_CheckWeaponHits();
    if (cVar2 == '\x04') {
      FUN_80108e84(obj);
      FUN_8012a5fc(obj,0);
      goto LAB_801d8788;
    }
    if (cVar2 == '\x02') {
      obj->clut = 0;
      uVar3 = 2;
      if (DAT_80158f5c == '\0') {
        uVar3 = 1;
      }
      obj->field_0x59 = uVar3;
    }
    else {
      bVar1 = (&DAT_80159f64)[obj->bank];
      obj->field_0x59 = 0;
      obj->clut = bVar1;
    }
  }
  (*(code *)(&PTR_FUN_801e6694)[obj->state])(obj);
  if (obj->field_0x58 == '\0') {
    if ((obj->field_0x33 & 0x80) == 0) {
      if (obj->speed_y_up == 0) {
        obj->speed_y_up = 0;
        obj->gravity = 0x4000;
      }
    }
    else {
      obj->speed_y_up = 0;
      obj->gravity = 0;
    }
    uVar6 = obj->speed_x;
    if ((int)uVar6 < 1) {
      if ((int)uVar6 < 0) {
        obj->accel_x = 0x800;
      }
      else {
        obj->accel_x = 0;
      }
    }
    else {
      obj->accel_x = -0x800;
    }
    if (((obj->field_0x33 & 0x30) != 0) || (cVar2 = FUN_801d8f20(obj), cVar2 != '\0')) {
      obj->speed_x = -obj->speed_x;
      uVar6 = obj->speed_x;
      obj->accel_x = -obj->accel_x;
    }
    Obj_ApplySpeed(obj);
    if (obj->speed_y_up < -0x60000) {
      obj->speed_y_up = -0x60000;
      obj->gravity = 0;
    }
    if ((uVar6 & 0x80000000) != (obj->speed_x & 0x80000000U)) {
      obj->speed_x = 0;
      obj->accel_x = 0;
    }
    uVar5 = obj->speed_x;
    uVar6 = uVar5;
    if ((int)uVar5 < 0) {
      uVar6 = -uVar5;
    }
    if (0x80000 < (int)uVar6) {
      iVar4 = 0x80000;
      if ((uVar5 & 0x80000000) != 0) {
        iVar4 = -0x80000;
      }
      obj->speed_x = iVar4;
    }
    FUN_801d8df8(obj);
    FUN_80106214(obj);
    Enemy_ContactDamage(obj);
    Obj_CullAndQueueDraw(obj);
    iVar4 = Obj_InActiveArea(obj);
    if (iVar4 != 0) {
      return;
    }
  }
  else {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
  }
LAB_801d8788:
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801d87a8 FUN_801d87a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d87a8(MM8Obj *obj)

{
  byte bVar1;
  
  Enemy_InitFromTable();
  obj->state = 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->draw_list = 6;
  bVar1 = Rand();
  obj->field_0x55 = bVar1 & 1;
  obj->flip = 0;
  Anim_Set(obj,(byte)obj->field_0x55 + 4);
  obj->box2 = &DAT_801e667c;
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->hitbox = &DAT_801e668c;
  obj->field_0x58 = 0;
  obj->field_0x59 = 0;
  return;
}


// ---- 801d8838 FUN_801d8838

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8838(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    obj->field_0x51 = 0x1e;
    obj->sub2 = 1;
    obj->box2 = &DAT_801e667c;
    obj->hitbox = &DAT_801e668c;
    obj->field_0x54 = 3;
  }
  cVar1 = FUN_801d8d84(obj);
  iVar2 = (int)cVar1;
  if (iVar2 != 0) {
    obj->sub3 = 0;
    obj->field_0x51 = 0x1e;
    obj->speed_x = (iVar2 * -2 + 3) * (uint)(byte)obj->field_0x59 * 0x10000 + (obj->speed_x >> 1) +
                   obj->speed_x;
    if ((uint)(byte)obj->field_0x55 != iVar2 - 1U) {
      obj->field_0x55 = cVar1 + -1;
      Anim_SetAtStep(obj,(byte)obj->field_0x55 + 4,obj->anim_extra);
    }
    cVar1 = '\x01';
    if (obj->field_0x59 == '\x01') {
      if ((byte)obj->field_0x54 < 2) goto LAB_801d8934;
      cVar1 = obj->field_0x54 + -1;
    }
    obj->field_0x54 = cVar1;
  }
LAB_801d8934:
  if (obj->field_0x51 == '\0') {
    if (4 < (byte)obj->field_0x54) {
      FUN_801d8dc8(obj);
      if (((word)(obj->frame & 0x7fff) == (word)(((byte)obj->field_0x56 >> 3) + 2)) &&
         (obj->anim_timer == 1)) {
        obj->field_0x51 = 0x1e;
        obj->flip = obj->field_0x56;
        Anim_Set(obj,0);
        obj->state = 2;
        obj->sub2 = 0;
      }
      goto LAB_801d8a0c;
    }
    if (obj->sub3 == 0) {
      cVar1 = obj->field_0x54 + '\x01';
LAB_801d89f0:
      obj->field_0x54 = cVar1;
    }
    else {
      if (3 < (byte)obj->field_0x54) {
        cVar1 = obj->field_0x54 + -1;
        goto LAB_801d89f0;
      }
      obj->sub3 = 0;
    }
    cVar1 = '\x1e';
  }
  else {
    cVar1 = obj->field_0x51 + -1;
  }
  obj->field_0x51 = cVar1;
LAB_801d8a0c:
  FUN_801d8d08(obj);
  return;
}


// ---- 801d8a28 FUN_801d8a28

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8a28(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  Anim_Step();
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    if ((obj->frame & 0x7fff) == 0xd) {
      obj->sub2 = 2;
      obj->box2 = &DAT_801e6684;
      obj->hitbox = &DAT_801e6690;
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      cVar2 = obj->field_0x51;
      obj->field_0x51 = cVar2 + -1;
      if (cVar2 != '\0') {
        return;
      }
      obj->sub2 = 1;
      Anim_Set(obj,2);
      FUN_8010544c(obj,0x79);
      return;
    }
    if (bVar1 != 2) {
      return;
    }
  }
  if (((int)(short)obj->frame & 0x8000U) != 0) {
    obj->state = 3;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801d8b14 FUN_801d8b14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8b14(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  if (obj->sub2 == 0) {
    Anim_Set(obj,3);
    iVar1 = 0x50000;
    if (obj->flip == 0) {
      iVar1 = -0x50000;
    }
    obj->speed_x = iVar1;
    obj->sub2 = 1;
    FUN_8010544c(obj,0x7a);
  }
  if ((obj->field_0x33 & 0x30) == 0) {
    iVar1 = obj->speed_x;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (0x7fff < iVar1) goto LAB_801d8ba8;
  }
  Anim_Set(obj,6);
LAB_801d8ba8:
  if (obj->speed_x == 0) {
    Anim_Set(obj,7);
    FUN_800fce30(0x7a);
    obj->state = 4;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801d8be8 FUN_801d8be8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8be8(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  if (obj->sub2 == 0) {
    Anim_Step();
    if ((((int)(short)obj->frame & 0x8000U) != 0) && (obj->anim_timer == 1)) {
      obj->field_0x51 = 8;
      Anim_Set(obj,0);
      obj->sub2 = 1;
      obj->box2 = &DAT_801e667c;
      obj->hitbox = &DAT_801e668c;
    }
  }
  else {
    cVar1 = obj->field_0x51;
    obj->field_0x51 = cVar1 + -1;
    if (cVar1 == '\0') {
      bVar2 = Rand();
      obj->field_0x55 = bVar2 & 1;
      obj->flip = 0;
      Anim_SetAtStep(obj,(byte)obj->field_0x55 + 4,
                     ((uint)(byte)obj->field_0x55 * -4 + 8) * (uint)((byte)obj->field_0x56 >> 6));
      obj->state = 1;
      obj->sub2 = 1;
      obj->sub3 = 1;
      obj->field_0x51 = 0x1e;
      obj->field_0x54 = 4;
      FUN_801d8d08();
    }
    else {
      Anim_Step(obj);
    }
  }
  return;
}


// ---- 801d8d08 FUN_801d8d08

void FUN_801d8d08(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  *(char *)(param_1 + 0x31) = *(char *)(param_1 + 0x31) + -1;
  if (*(char *)(param_1 + 0x31) == '\0') {
    iVar3 = *(int *)(param_1 + 0x28);
    iVar2 = iVar3 + 4;
    *(int *)(param_1 + 0x28) = iVar2;
    if (((int)*(short *)(param_1 + 0x2e) & 0x8000U) != 0) {
      *(int *)(param_1 + 0x28) = iVar2 + *(short *)(iVar3 + 4) * -4;
    }
    uVar1 = **(undefined2 **)(param_1 + 0x28);
    *(undefined1 *)(param_1 + 0x31) = *(undefined1 *)(param_1 + 0x54);
    *(undefined2 *)(param_1 + 0x2e) = uVar1;
    *(undefined1 *)(param_1 + 0x32) = *(undefined1 *)(*(int *)(param_1 + 0x28) + 3);
  }
  return;
}


// ---- 801d8d84 FUN_801d8d84

undefined4 FUN_801d8d84(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x59) == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
    if (*(int *)(DAT_8016d404 + 0xc) < *(int *)(param_1 + 0xc)) {
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ---- 801d8dc8 FUN_801d8dc8

void FUN_801d8dc8(int param_1)

{
  if (DAT_8015e248 < *(int *)(param_1 + 0xc)) {
    *(undefined1 *)(param_1 + 0x56) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x56) = 0x40;
  }
  return;
}


// ---- 801d8df8 FUN_801d8df8

void FUN_801d8df8(char *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  
  pcVar5 = &g_main_pool;
  puVar6 = &DAT_8015b188;
  do {
    if ((((*pcVar5 != '\0') && (pcVar5 != param_1)) && (*(char *)((int)puVar6 + -0xe) == param_1[6])
        ) && (iVar2 = Obj_HitboxOverlap(pcVar5,param_1), iVar2 != 0)) {
      iVar3 = (int)DAT_801c7384;
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = -iVar3;
      }
      sVar1 = DAT_801c7384;
      if (1 < iVar2) {
        if (iVar2 == 0) {
          trap(0x1c00);
        }
        if ((iVar2 == -1) && (iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        sVar1 = (short)(iVar3 / iVar2) * 2;
      }
      *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + sVar1;
      if (*(char *)((int)puVar6 + 0x43) == '\0') {
        *(undefined1 *)((int)puVar6 + 0x43) = 1;
        uVar4 = *puVar6;
        *puVar6 = *(undefined4 *)(param_1 + 0x14);
        *(undefined4 *)(param_1 + 0x14) = uVar4;
      }
    }
    pcVar5 = pcVar5 + 0x60;
    puVar6 = puVar6 + 0x18;
  } while (pcVar5 < &DAT_8015c974);
  return;
}


// ---- 801d8f20 FUN_801d8f20

undefined4 FUN_801d8f20(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  
  pcVar2 = &DAT_801b1eec;
  piVar3 = &DAT_801b1f24;
  while ((((*pcVar2 == '\0' || (1 < *(byte *)((int)piVar3 + -0x32) - 7)) || (*piVar3 == 0)) ||
         (iVar1 = FUN_80107bf4(pcVar2,param_1,1), iVar1 == 0))) {
    pcVar2 = pcVar2 + 0x50;
    piVar3 = piVar3 + 0x14;
    if (&DAT_801b28ec <= pcVar2) {
      pcVar2 = &g_main_pool;
      piVar3 = &DAT_8015b1ac;
      while (((*pcVar2 == '\0' || (*(char *)((int)piVar3 + -0x32) != '\v')) ||
             ((*piVar3 == 0 || (iVar1 = FUN_80107bf4(pcVar2,param_1,1), iVar1 == 0))))) {
        pcVar2 = pcVar2 + 0x60;
        piVar3 = piVar3 + 0x18;
        if (&DAT_8015c974 <= pcVar2) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 1;
}


