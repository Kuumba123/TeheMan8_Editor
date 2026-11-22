// T2_18, STAGE05.BIN, handler 0x801E3BA0. Ghidra output with the object struct applied; not matching C.
// ---- 801e3ba0 FUN_801e3ba0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3ba0(MM8Obj *obj)

{
  char cVar1;
  
  if ((obj->var & 0x80) == 0) {
    FUN_801e3c14(obj);
  }
  else {
    FUN_801e3e94();
  }
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e3c14 FUN_801e3c14

void FUN_801e3c14(int param_1)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  (*(code *)(&PTR_FUN_801ea874)[*(byte *)(param_1 + 1)])();
  return;
}


// ---- 801e3c50 FUN_801e3c50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3c50(MM8Obj *obj)

{
  byte bVar1;
  
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->bank = 0x53;
  obj->vram_base = DAT_801703ee;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->draw_list = 7;
  obj->state = 1;
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->clut = bVar1;
  if (((uint)DAT_801c3378 & 0x10 << (obj->var & 0xf)) == 0) {
    Anim_Set(obj,3);
    obj->sub2 = 0;
  }
  else {
    Anim_SetAtStep(obj,3,6);
    obj->sub2 = 2;
  }
  obj->sub3 = 0;
  obj->hitbox = &DAT_801ea840;
  obj->box2 = &UNK_801ea844 + (obj->anim_extra & 0x7f) * 5;
  return;
}


// ---- 801e3d38 FUN_801e3d38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3d38(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  
  obj->box2 = &UNK_801ea844 + (obj->anim_extra & 0x7f) * 5;
  bVar2 = FUN_80107bf4(obj,&g_player,5);
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      DAT_801c3378 = DAT_801c3378 + 1 | (byte)(0x10 << (obj->var & 0xf));
      obj->sub2 = 2;
    }
    Anim_Step(obj);
  }
  else if (((bVar1 < 2) && (bVar1 == 0)) && ((DAT_8015e27c & bVar2) == 0x80)) {
    obj->sub2 = 1;
  }
  if ((obj->sub3 == 0) && ((obj->anim_extra & 0x80) != 0)) {
    FUN_8010544c(obj,0x2b);
    DAT_801d2936 = 0x78;
    obj->sub3 = 1;
  }
  if (((short)DAT_801d2936 < 0x5b) && ((DAT_801d2936 & 0x1f) == 0x1f)) {
    FUN_800fd100(0xcb);
  }
  return;
}


// ---- 801e3e94 FUN_801e3e94

void FUN_801e3e94(int param_1)

{
  (*(code *)(&PTR_FUN_801ea87c)[*(byte *)(param_1 + 1)])();
  *(undefined **)(param_1 + 0x38) = &DAT_801ea860 + (uint)*(byte *)(param_1 + 3) * 5;
  *(undefined **)(param_1 + 0x3c) = &UNK_801ea854 + (uint)*(byte *)(param_1 + 3) * 4;
  FUN_80107bf4(param_1,&g_player,1);
  FUN_8010976c(param_1);
  *(undefined **)(param_1 + 0x38) = &DAT_801ea86c;
  *(undefined **)(param_1 + 0x3c) = &DAT_801ea85c;
  FUN_80107bf4(param_1,&g_player,1);
  FUN_8010976c(param_1);
  return;
}


// ---- 801e3f68 FUN_801e3f68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3f68(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0x53;
  obj->vram_base = DAT_801703ee;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->draw_list = 7;
  obj->clut = bVar1;
  if ((DAT_801c3378 & 0xf) < (obj->var & 0x7f) + 1) {
    Anim_Set(obj,0);
    obj->state = 2;
  }
  else {
    if (((int)(uint)DAT_801c3379 >> (obj->var & 0x1f) & 1U) != 0) {
      Anim_SetAtStep(obj,0,0x2e);
      obj->state = 2;
      obj->sub3 = 1;
      return;
    }
    Anim_Set(obj,0);
    obj->state = 1;
    obj->sub2 = 0;
  }
  obj->sub3 = 0;
  return;
}


// ---- 801e4060 FUN_801e4060

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4060(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    if ((DAT_80170574 & 0x1f) == 0x1f) {
      FUN_800fd100(0xcb);
    }
    DAT_801d2936 = 1;
                    /* Possible PsyQ macro: setTile16() */
    if ((obj->field_0x4 == '\0') && (obj->anim_extra == 1)) {
      obj->field_0x4 = 1;
      FUN_8010544c(obj,0xce);
    }
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->state = 2;
      obj->sub2 = 0;
      obj->sub3 = 1;
      obj->field_0x4 = 0;
      DAT_801d2936 = 0;
    }
    Anim_Step(obj);
  }
  else if ((bVar1 < 2) && (bVar1 == 0)) {
    DAT_801c3379 = DAT_801c3379 | (byte)(1 << (obj->var & 0x1f));
    obj->sub2 = 1;
    obj->field_0x4 = 0;
  }
  return;
}


