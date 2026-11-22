// T2_08, STAGE01.BIN, handler 0x801E4948. Ghidra output with the object struct applied; not matching C.
// ---- 801e4948 FUN_801e4948

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4948(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e6f58)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      if (obj->field_0x4 == '\0') {
        Obj_FreeDespawn(obj);
      }
      else {
        Obj_Free(obj);
      }
    }
  }
  return;
}


// ---- 801e49e4 FUN_801e49e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e49e4(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->bank = 0x23;
  obj->vram_base = DAT_8017038e;
  bVar1 = DAT_80159f87;
  obj->draw_list = 6;
  obj->clut = bVar1;
  bVar1 = obj->field_0x4;
  obj->box2 = (byte *)0x0;
  obj->hitbox = (byte *)0x0;
  obj->flip = 0;
  if (bVar1 == 1) {
    if ((obj->var & 0x80) != 0) {
      obj->state = 1;
      uVar6 = *(undefined4 *)(*(int *)&obj->dmg_table + 0xc);
      obj->x_frac = (short)uVar6;
      obj->x = (short)((uint)uVar6 >> 0x10);
      iVar5 = *(int *)(*(int *)&obj->dmg_table + 0x10);
      obj->speed_y_up = 0x48000;
      *(int *)&obj->y_frac = iVar5 + 0xf80000;
      Anim_Set(obj,6);
      obj->box2 = &DAT_801e6f28;
      obj->hitbox = &DAT_801e6f48;
      return;
    }
    puVar2 = (undefined1 *)FUN_80105734(*(undefined4 *)(*(int *)&obj->dmg_table + 0x48));
    if (puVar2 == (undefined1 *)0x0) {
      return;
    }
    *puVar2 = 1;
    puVar2[6] = 8;
    bVar1 = obj->var;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 3;
    *(MM8Obj **)(puVar2 + 0x44) = obj;
    puVar2[7] = bVar1;
    *(undefined1 **)&obj->target_prio = puVar2;
    obj->state = 1;
    uVar6 = *(undefined4 *)(*(int *)&obj->dmg_table + 0xc);
    obj->x_frac = (short)uVar6;
    obj->x = (short)((uint)uVar6 >> 0x10);
    iVar5 = *(int *)(*(int *)&obj->dmg_table + 0x10);
    obj->speed_y_up = 0x48000;
    *(int *)&obj->y_frac = iVar5 + 0xf80000;
    Anim_Set(obj,3);
    obj->box2 = &DAT_801e6f28;
    obj->hitbox = &DAT_801e6f40;
    return;
  }
  if (bVar1 < 2) {
    if (bVar1 != 0) {
      return;
    }
    puVar2 = (undefined1 *)FUN_80105734(obj);
    if (puVar2 == (undefined1 *)0x0) {
      return;
    }
    *puVar2 = 1;
    puVar2[6] = 8;
    bVar1 = obj->var;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 1;
    *(MM8Obj **)(puVar2 + 0x44) = obj;
    puVar2[7] = bVar1;
    *(undefined1 **)&obj->dmg_table = puVar2;
    puVar3 = (undefined1 *)FUN_80105734(puVar2);
    if (puVar3 == (undefined1 *)0x0) {
      Obj_Free(puVar2);
      return;
    }
    *puVar3 = 1;
    puVar3[6] = 8;
    bVar1 = obj->var;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 2;
    *(MM8Obj **)(puVar3 + 0x44) = obj;
    puVar3[7] = bVar1;
    *(undefined1 **)&obj->target_prio = puVar3;
    obj->state = 1;
    obj->speed_y_up = -0x48000;
    obj->box2 = &DAT_801e6f20;
    if ((obj->var & 0x80) == 0) {
      uVar6 = 4;
    }
    else {
      uVar6 = 7;
    }
  }
  else if (bVar1 == 2) {
    uVar6 = *(undefined4 *)(*(int *)&obj->dmg_table + 0xc);
    obj->x_frac = (short)uVar6;
    obj->x = (short)((uint)uVar6 >> 0x10);
    uVar6 = *(undefined4 *)(*(int *)&obj->dmg_table + 0x10);
    obj->state = 1;
    obj->y_frac = (short)uVar6;
    obj->y = (short)((uint)uVar6 >> 0x10);
    if ((obj->var & 0x80) == 0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 5;
    }
  }
  else {
    if (bVar1 != 3) {
      return;
    }
    uVar4 = *(undefined4 *)(*(int *)&obj->dmg_table + 0xc);
    uVar6 = 1;
    obj->x_frac = (short)uVar4;
    obj->x = (short)((uint)uVar4 >> 0x10);
    uVar4 = *(undefined4 *)(*(int *)&obj->dmg_table + 0x10);
    obj->state = 1;
    obj->y_frac = (short)uVar4;
    obj->y = (short)((uint)uVar4 >> 0x10);
  }
  Anim_Set(obj,uVar6);
  return;
}


// ---- 801e4cf0 FUN_801e4cf0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4cf0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6f60)[(byte)obj->field_0x4])();
  return;
}


// ---- 801e4d2c FUN_801e4d2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4d2c(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e6f70)[obj->sub2])();
  obj->hitbox = &DAT_801e6f30;
  FUN_8010976c(obj);
  if (DAT_8015e283 != '\0') {
    FUN_80107bf4(obj,&g_player,1);
    FUN_80107bf4(obj,&g_player,1);
    FUN_80107bf4(obj,&g_player,1);
  }
  if (obj->sub2 != 2) {
    FUN_801e5010(obj);
  }
  return;
}


// ---- 801e4ed8 FUN_801e4ed8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4ed8(MM8Obj *obj)

{
  char *pcVar1;
  
  pcVar1 = *(char **)&obj->dmg_table;
  if ((*pcVar1 == '\0') || (pcVar1[6] != '\b')) {
    Obj_Free(obj);
  }
  else if (pcVar1[2] == '\x01') {
    FUN_80104d18(obj);
  }
  obj->hitbox = &DAT_801e6f34;
  FUN_8010976c(obj);
  if (DAT_8015e283 != '\0') {
    FUN_80107bf4(obj,&g_player,1);
    FUN_80107bf4(obj,&g_player,1);
    FUN_80107bf4(obj,&g_player,1);
  }
  return;
}


// ---- 801e4fb0 FUN_801e4fb0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4fb0(MM8Obj *obj)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->dmg_table;
  if ((*pcVar2 == '\0') || (pcVar2[6] != '\b')) {
    Obj_Free();
  }
  else {
    uVar1 = *(undefined4 *)(pcVar2 + 0xc);
    obj->x_frac = (short)uVar1;
    obj->x = (short)((uint)uVar1 >> 0x10);
    uVar1 = *(undefined4 *)(pcVar2 + 0x10);
    obj->y_frac = (short)uVar1;
    obj->y = (short)((uint)uVar1 >> 0x10);
  }
  return;
}


// ---- 801e5010 FUN_801e5010

void FUN_801e5010(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  if ((*(byte *)(param_1 + 7) & 0x80) == 0) {
    *(undefined **)(param_1 + 0x3c) = &DAT_801e6f3c;
  }
  else {
    *(undefined **)(param_1 + 0x3c) = &DAT_801e6f44;
  }
  iVar1 = Obj_HitboxOverlap(&g_player,param_1);
  if (iVar1 == 0) {
    if ((*(byte *)(*(int *)(param_1 + 0x44) + 7) & 0x80) == 0) {
      puVar2 = &DAT_801e6f40;
    }
    else {
      puVar2 = &DAT_801e6f48;
    }
    *(undefined **)(*(int *)(param_1 + 0x44) + 0x3c) = puVar2;
    iVar1 = Obj_HitboxOverlap(&g_player);
    if (iVar1 == 0) {
      return;
    }
  }
  FUN_80111d34(0x7f);
  return;
}


