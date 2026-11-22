// T2_10, STAGE0B.BIN, handler 0x801E70D4. Ghidra output with the object struct applied; not matching C.
// ---- 801e70d4 FUN_801e70d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e70d4(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801e8850)[obj->state])();
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


