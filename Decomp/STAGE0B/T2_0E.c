// T2_0E, STAGE0B.BIN, handler 0x801E65D8. Ghidra output with the object struct applied; not matching C.
// ---- 801e65d8 FUN_801e65d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e65d8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8824)[obj->state])();
  return;
}


// ---- 801e6614 FUN_801e6614

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6614(MM8Obj *obj)

{
  byte bVar1;
  word wVar2;
  int iVar3;
  undefined1 *puVar4;
  
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
  obj->bank = 0x2d;
  wVar2 = DAT_801703a2;
  obj->flip = 0;
  obj->draw_list = 6;
  obj->vram_base = wVar2;
  if (obj->var == 0) {
    if (((DAT_801b29a0 == '\x0f') || (iVar3 = FUN_80105dbc(obj,0xe), iVar3 != 0)) ||
       (puVar4 = (undefined1 *)FUN_80105734(obj), puVar4 == (undefined1 *)0x0)) {
      Obj_Free(obj);
      FUN_80108f6c(obj,1);
    }
    else {
      *puVar4 = 1;
      puVar4[6] = 0xe;
                    /* Possible PsyQ macro: setPolyFT3() */
      puVar4[7] = 1;
      *(MM8Obj **)(puVar4 + 0x44) = obj;
      obj->state = 1;
      bVar1 = DAT_80159f91;
      obj->hitbox = &DAT_801e8820;
      obj->target_prio = 0x3c;
      obj->speed_x = -0x10000;
      obj->speed_y_up = -0x40000;
      obj->accel_x = 0;
      obj->gravity = -0x2000;
      obj->clut = bVar1;
      FUN_801e694c(obj);
      obj->field_0x49 = obj->field_0x4a;
      Anim_Set(obj,0);
    }
  }
  else {
    obj->state = 2;
    obj->field_0x49 = 0xff;
    obj->field_0x4a = DAT_80159f8d;
    FUN_801e69b4();
  }
  return;
}


// ---- 801e6750 FUN_801e6750

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6750(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->gravity < 0) {
    if (0x30000 < obj->speed_y_up) {
      obj->gravity = 0x2000;
    }
  }
  else if (obj->speed_y_up < -0x30000) {
    obj->gravity = -0x2000;
  }
  FUN_80111ff4(obj);
  FUN_80104ccc(obj);
  Anim_Step(obj);
  if (obj->sub3 == 0) {
    Anim_Step(obj);
    obj->target_prio = obj->target_prio - 1;
    if (obj->target_prio == 0) {
      obj->target_prio = 0x3c;
      FUN_801e694c(obj);
      Anim_Set(obj,(&DAT_801e8830)[(byte)obj->field_0x4a]);
      obj->sub3 = 1;
    }
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->sub3 = 0;
    }
    if (obj->anim_extra != 0) {
      obj->field_0x49 = obj->field_0x4a;
    }
  }
  if (((DAT_8015e241 == '\0') || (DAT_8015e283 == '\0')) ||
     (iVar1 = Obj_HitboxOverlap(obj,&g_player), iVar1 == 0)) {
    Obj_CullAndQueueDraw(obj);
    if (obj->on_screen != 0) {
      return;
    }
  }
  else {
    FUN_801e6a5c(obj);
  }
  Obj_Free(obj);
  return;
}


// ---- 801e68d8 FUN_801e68d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e68d8(MM8Obj *obj)

{
  if ((**(char **)&obj->dmg_table == '\0') ||
     ((*(uint *)(*(char **)&obj->dmg_table + 4) & 0xffff0000) != 0xe0000)) {
    Obj_Free(obj);
  }
  else {
    FUN_801e69b4(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e694c FUN_801e694c

void FUN_801e694c(int param_1)

{
  uint uVar1;
  
  do {
    uVar1 = Rand();
  } while ((DAT_801b29a0 & (&DAT_80139548)[uVar1 & 3]) != 0);
  *(char *)(param_1 + 0x4a) = (char)(uVar1 & 3);
  return;
}


// ---- 801e69b4 FUN_801e69b4

void FUN_801e69b4(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x44);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(iVar1 + 0xe);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(iVar1 + 0x12);
  if (*(char *)(param_1 + 0x49) != *(char *)(iVar1 + 0x49)) {
    *(undefined1 *)(param_1 + 0x49) = *(undefined1 *)(iVar1 + 0x49);
                    /* Possible PsyQ macro: setPolyF3() */
                    /* Possible PsyQ macro: setLineF2() */
    if ((&DAT_801e8834)[*(byte *)(param_1 + 0x49)] == -1) {
      *(undefined1 *)(param_1 + 0x24) = DAT_80159f90;
    }
    else {
      *(char *)(param_1 + 0x24) =
           *(char *)(param_1 + 0x4a) + (&DAT_801e8834)[*(byte *)(param_1 + 0x49)];
    }
    Anim_Set(param_1,(&DAT_801e8838)[*(byte *)(param_1 + 0x49)]);
  }
  return;
}


// ---- 801e6a5c FUN_801e6a5c

void FUN_801e6a5c(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  
  bVar1 = *(byte *)(param_1 + 0x49);
  if (bVar1 == 1) {
    DAT_801b29a0 = DAT_801b29a0 | DAT_80139549;
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && (puVar2 = (undefined1 *)Obj_AllocType2(), puVar2 != (undefined1 *)0x0)) {
      *puVar2 = 1;
      puVar2[6] = 0xf;
      puVar2[7] = 0;
      DAT_801b29a0 = DAT_801b29a0 | DAT_80139548;
    }
  }
  else if (bVar1 == 2) {
    puVar2 = (undefined1 *)FUN_80105628();
                    /* Possible PsyQ macro: setPolyF4() */
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 9;
      puVar2[7] = 0;
      DAT_801b29a0 = DAT_801b29a0 | DAT_8013954a;
    }
  }
  else if ((bVar1 == 3) && (puVar2 = (undefined1 *)Obj_AllocType2(), puVar2 != (undefined1 *)0x0)) {
    *puVar2 = 1;
    puVar2[6] = 0x10;
    puVar2[7] = 0;
    DAT_801b29a0 = DAT_801b29a0 | DAT_8013954b;
  }
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
  return;
}


