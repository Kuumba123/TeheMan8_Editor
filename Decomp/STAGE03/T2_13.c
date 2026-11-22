// T2_13, STAGE03.BIN, handler 0x801E7AE4. Ghidra output with the object struct applied; not matching C.
// ---- 801e7ae4 FUN_801e7ae4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7ae4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9f88)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  if (0x1ae < ((int)obj->x - (int)DAT_801d2918._2_2_) + 0x37U) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e7b60 FUN_801e7b60

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7b60(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  obj->bank = 0x41;
  obj->vram_base = DAT_801703ca;
  bVar2 = DAT_80159fa5;
  obj->contact_dmg = obj->var << 4;
  obj->draw_list = 6;
  obj->box2 = &DAT_801e9f80;
  obj->var = obj->var & 0xf0;
  bVar1 = obj->var;
  obj->clut = bVar2;
  if (bVar1 == 0x10) {
    uVar4 = 2;
    uVar5 = 0;
    obj->state = 2;
    obj->dmg_table = 1;
    obj->field_0x4b = 0;
  }
  else {
    if (bVar1 < 0x11) {
      if (bVar1 != 0) {
        return;
      }
      obj->state = 1;
      obj->speed_x = 0;
      obj->accel_x = 0x10000;
      obj->speed_y_up = 0;
      obj->gravity = 0;
      obj->accel_x = 0;
      obj->y = g_cam_y + 0x120;
      sVar3 = g_cam_y;
      obj->target_prio = 0;
      obj->field_0x4a = 1;
      obj->field_0x49 = 1;
      *(short *)&obj->invuln = sVar3 + 0xe8;
      FUN_801e83cc(obj);
      obj->dmg_table = 0x3c;
      Anim_Set(obj,0);
      return;
    }
    if (bVar1 != 0x20) {
      return;
    }
    uVar4 = 3;
    uVar5 = 6;
    obj->state = 3;
    obj->field_0x4c = 0;
  }
  Anim_SetAtStep(obj,uVar4,uVar5);
  return;
}


// ---- 801e7cc0 FUN_801e7cc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7cc0(MM8Obj *obj)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  (*(code *)(&PTR_LAB_801e9f98)[obj->sub2])();
  if (obj->speed_y_up == obj->accel_x) {
    FUN_80104c34(obj);
  }
  else {
    FUN_80104ccc(obj);
    if (obj->gravity < 1) {
      iVar3 = obj->accel_x;
      bVar1 = obj->speed_y_up < iVar3;
    }
    else {
      iVar3 = obj->accel_x;
      bVar1 = iVar3 < obj->speed_y_up;
    }
    if (!bVar1) {
      obj->speed_y_up = iVar3;
    }
  }
  Anim_Step(obj);
  uVar2 = FUN_80107bf4(obj,&g_player,5);
  if ((uVar2 & 0x80) == 0) {
    obj->target_prio = 0;
  }
  else if (obj->target_prio == 0) {
    obj->target_prio = 1;
    Anim_Set(obj,1);
  }
  if ((obj->dmg_table < 0xb) && ('\0' < (char)obj->field_0x49)) {
    obj->field_0x4a = obj->field_0x4a + '\x01';
  }
  return;
}


// ---- 801e829c FUN_801e829c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e829c(MM8Obj *obj)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = FUN_801e8464();
  if (iVar3 == 0) {
    Obj_Free(obj);
  }
  else {
    if (obj->field_0x49 != *(char *)(iVar3 + 0x49)) {
      obj->dmg_table = 1;
    }
    obj->field_0x49 = *(undefined1 *)(iVar3 + 0x49);
    uVar1 = *(undefined1 *)(iVar3 + 0x4a);
    bVar2 = obj->dmg_table - 1;
    obj->dmg_table = bVar2;
    obj->field_0x4a = uVar1;
    if (bVar2 == 0) {
      Anim_SetAtStep(obj,2,obj->field_0x4b);
      obj->dmg_table = obj->field_0x4a;
      obj->field_0x4b = obj->field_0x4b + obj->field_0x49 & 7;
    }
  }
  return;
}


// ---- 801e8348 FUN_801e8348

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8348(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = FUN_801e8464();
  if (iVar1 == 0) {
    Obj_Free(obj);
  }
  else {
    if (*(char *)(iVar1 + 0x48) == '\0') {
      obj->field_0x4c = 0;
    }
    else if (obj->field_0x4c == '\0') {
      obj->field_0x4c = 1;
      Anim_Set(obj,3);
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801e83cc FUN_801e83cc

void FUN_801e83cc(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  
  uVar4 = 0;
  cVar3 = '\x10';
  do {
    puVar1 = (undefined1 *)FUN_80105734();
    uVar4 = uVar4 + 1;
    if (puVar1 == (undefined1 *)0x0) {
      return;
    }
    *puVar1 = 1;
    puVar1[6] = 0x13;
    puVar1[7] = cVar3;
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    *(int *)(puVar1 + 0x1c) = param_1;
    *(undefined4 *)(puVar1 + 0x10) = uVar2;
    cVar3 = cVar3 + '\x10';
  } while (uVar4 < 2);
  return;
}


// ---- 801e8464 FUN_801e8464

char * FUN_801e8464(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x1c);
  if (*pcVar2 == '\0') {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (char *)0x0;
    if ((*(uint *)(pcVar2 + 4) & 0xf0ff0000) == 0x130000) {
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(pcVar2 + 0xc);
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(pcVar2 + 0x10);
      pcVar1 = pcVar2;
    }
  }
  return pcVar1;
}


