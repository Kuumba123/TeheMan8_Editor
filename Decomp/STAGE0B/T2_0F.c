// T2_0F, STAGE0B.BIN, handler 0x801E6BA0. Ghidra output with the object struct applied; not matching C.
// ---- 801e6ba0 FUN_801e6ba0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6ba0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e883c)[obj->state])();
  return;
}


// ---- 801e6bdc FUN_801e6bdc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6bdc(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  obj->bank = 0x29;
  obj->vram_base = DAT_8017039a;
  bVar1 = DAT_80159f8d;
                    /* Possible PsyQ macro: setLineF2() */
  obj->flip = 0x40;
  obj->draw_list = 5;
  obj->clut = bVar1;
  bVar1 = obj->var;
  if (bVar1 == 1) {
    obj->state = 2;
    uVar4 = 1;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      puVar2 = (undefined1 *)FUN_80105734(obj);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar3 = (undefined1 *)FUN_80105734(obj);
        if (puVar3 != (undefined1 *)0x0) {
          *puVar2 = 1;
          puVar2[6] = 0xf;
          puVar2[7] = 1;
          *(MM8Obj **)(puVar2 + 0x44) = obj;
          puVar3[6] = 0xf;
          *puVar3 = 1;
          puVar3[7] = 2;
          *(MM8Obj **)(puVar3 + 0x44) = obj;
          obj->state = 1;
          obj->x = DAT_801d2918._2_2_ + 0xa0;
          obj->y = g_cam_y + -0x40;
          Anim_Set(obj,0);
          FUN_800fd100(0x17a);
          return;
        }
        *puVar2 = 0;
      }
      Obj_Free(obj);
      return;
    }
    if (bVar1 != 2) {
      return;
    }
    uVar4 = 2;
    obj->state = 3;
    obj->target_prio = 0;
  }
  Anim_Set(obj,uVar4);
  return;
}


// ---- 801e6d50 FUN_801e6d50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6d50(MM8Obj *obj)

{
  FUN_80111ff4();
  FUN_801e6fe8(obj);
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  if (DAT_801b29a0 == '\0') {
    obj->state = 4;
    obj->speed_y_up = 0x20000;
    obj->speed_x = 0;
    obj->gravity = -0x1000;
  }
  return;
}


// ---- 801e6dbc FUN_801e6dbc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6dbc(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = FUN_801e6fb0();
  if (iVar1 == 0) {
    Obj_Free(obj);
  }
  else {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e6e0c FUN_801e6e0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6e0c(MM8Obj *obj)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_801e6fb0();
  if (iVar1 == 0) {
    Obj_Free(obj);
    return;
  }
  Anim_Step(obj);
  if (obj->sub2 == 0) {
    if (obj->target_prio != 0) {
      obj->target_prio = obj->target_prio - 1;
      goto LAB_801e6f00;
    }
    if (((DAT_8015e294 & 0x90) == 0) ||
       (puVar2 = (undefined1 *)FUN_80105628(), puVar2 == (undefined1 *)0x0)) goto LAB_801e6f00;
    *puVar2 = 1;
    puVar2[6] = 7;
    puVar2[7] = 0;
    *(short *)(puVar2 + 0xe) = obj->x + 0x1f;
    uVar3 = 3;
    *(short *)(puVar2 + 0x12) = obj->y + -0x14;
    obj->sub2 = 1;
  }
  else {
    if (-1 < (short)obj->frame) goto LAB_801e6f00;
    uVar3 = 2;
    obj->sub2 = 0;
    obj->target_prio = 0x3c;
  }
  Anim_Set(obj,uVar3);
LAB_801e6f00:
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e6f1c FUN_801e6f1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6f1c(MM8Obj *obj)

{
  short sVar1;
  
  FUN_80104ccc();
  if ((DAT_80170574 & 1) != 0) {
    if ((DAT_80170574 & 0x10) == 0) {
      sVar1 = obj->y + 1;
    }
    else {
      sVar1 = obj->y + -1;
    }
    obj->y = sVar1;
  }
  FUN_80111ff4(obj);
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  if (obj->on_screen == 0) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e6fb0 FUN_801e6fb0

bool FUN_801e6fb0(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x44);
  cVar1 = *pcVar2;
  if (cVar1 != '\0') {
    *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(pcVar2 + 0xe);
    *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(pcVar2 + 0x12);
  }
  return cVar1 != '\0';
}


// ---- 801e6fe8 FUN_801e6fe8

void FUN_801e6fe8(int param_1)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  
  sVar2 = FUN_801054b4((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),
                       DAT_8015e248._2_2_ + -0x30,(int)DAT_8015e24c._2_2_);
  iVar3 = (int)sVar2;
  if (8 < iVar3) {
    sVar2 = (short)(iVar3 << 4);
    if (0x400 < (iVar3 << 0x14) >> 0x10) {
      sVar2 = 0x400;
    }
    uVar1 = FUN_80104db0((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),
                         DAT_8015e248._2_2_ + -0x30,(int)DAT_8015e24c._2_2_);
    FUN_80105120(param_1,(int)sVar2,uVar1);
    FUN_80104c34(param_1);
  }
  if ((DAT_80170574 & 1) != 0) {
    if ((DAT_80170574 & 0x10) == 0) {
      sVar2 = *(short *)(param_1 + 0x12) + 1;
    }
    else {
      sVar2 = *(short *)(param_1 + 0x12) + -1;
    }
    *(short *)(param_1 + 0x12) = sVar2;
  }
  return;
}


// ---- 801e7110 FUN_801e7110

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7110(MM8Obj *obj)

{
  char cVar1;
  undefined1 *puVar2;
  
  obj->bank = 0x29;
  obj->vram_base = DAT_8017039a;
  cVar1 = DAT_80159f8d;
                    /* Possible PsyQ macro: setLineF2() */
  obj->flip = 0x40;
  obj->draw_list = 5;
  obj->clut = cVar1 + 4;
  if (obj->var == 0) {
    puVar2 = (undefined1 *)FUN_80105734();
    if (puVar2 != (undefined1 *)0x0) {
      puVar2[6] = 0x10;
      *puVar2 = 1;
      puVar2[7] = 1;
                    /* Possible PsyQ macro: setLineF2() */
      *(MM8Obj **)(puVar2 + 0x44) = obj;
      obj->state = 1;
      obj->field_0x49 = 7;
      obj->x = DAT_801d2918._2_2_ + -0x20;
      obj->y = g_cam_y + 0x80;
      Anim_Set(obj,7);
      FUN_800fd100(0x17c);
    }
  }
  else {
    obj->state = 2;
    obj->field_0x49 = 7;
    Anim_Set(obj,8);
  }
  return;
}


// ---- 801e7200 FUN_801e7200

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7200(MM8Obj *obj)

{
  FUN_80111ff4();
  FUN_801e73d8(obj);
  FUN_801e749c(obj);
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  if ((obj->field_0x49 == '\a') && (DAT_801b29a0 == '\0')) {
    obj->state = 3;
    obj->speed_y_up = 0x30000;
    obj->speed_x = 0;
    obj->gravity = -0x1000;
  }
  return;
}


// ---- 801e7284 FUN_801e7284

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7284(MM8Obj *obj)

{
  FUN_801e7378();
  Anim_Step(obj);
  if (**(char **)&obj->dmg_table == '\0') {
    Obj_Free(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e72e4 FUN_801e72e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e72e4(MM8Obj *obj)

{
  short sVar1;
  
  FUN_80104ccc();
  if ((DAT_80170574 & 1) != 0) {
    if ((DAT_80170574 & 0x10) == 0) {
      sVar1 = obj->y + 1;
    }
    else {
      sVar1 = obj->y + -1;
    }
    obj->y = sVar1;
  }
  FUN_80111ff4(obj);
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  if (obj->on_screen == 0) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e7378 FUN_801e7378

void FUN_801e7378(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x44);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(iVar1 + 0xe);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(iVar1 + 0x12);
  if (*(char *)(param_1 + 0x49) != *(char *)(iVar1 + 0x49)) {
    *(undefined1 *)(param_1 + 0x49) = *(undefined1 *)(iVar1 + 0x49);
    Anim_Set(param_1,*(byte *)(param_1 + 0x49) + 1);
  }
  return;
}


// ---- 801e73d8 FUN_801e73d8

void FUN_801e73d8(int param_1)

{
  undefined1 uVar1;
  short sVar2;
  short sVar3;
  
  sVar2 = FUN_801054b4((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),
                       DAT_8015e248._2_2_ + 0x30,DAT_8015e24c._2_2_ + 0x10);
  if (4 < sVar2) {
    sVar3 = sVar2 * 0x18;
    if (0x500 < sVar2 * 0x180000 >> 0x10) {
      sVar3 = 0x500;
    }
    uVar1 = FUN_80104db0((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),
                         DAT_8015e248._2_2_ + 0x30,DAT_8015e24c._2_2_ + 0x10);
    FUN_80105120(param_1,(int)sVar3,uVar1);
    FUN_80104c34(param_1);
  }
  return;
}


// ---- 801e749c FUN_801e749c

void FUN_801e749c(int param_1)

{
  undefined1 *puVar1;
  
  if (*(char *)(param_1 + 0x49) == '\a') {
    if ((DAT_8015e294 & 0x90) != 0) {
      *(undefined1 *)(param_1 + 0x49) = 9;
      Anim_Set(param_1,9);
    }
  }
  else if (*(short *)(param_1 + 0x2e) < 0) {
    *(undefined1 *)(param_1 + 0x49) = 7;
    Anim_Set(param_1,7);
  }
  else if ((*(char *)(param_1 + 0x32) != '\0') &&
          (puVar1 = (undefined1 *)FUN_80105628(), puVar1 != (undefined1 *)0x0)) {
    *puVar1 = 1;
    puVar1[6] = 8;
    *(short *)(puVar1 + 0xe) = *(short *)(param_1 + 0xe) + 4;
    *(short *)(puVar1 + 0x12) = *(short *)(param_1 + 0x12) + -7;
  }
  return;
}


