// T2_19, STAGE05.BIN, handler 0x801E4174. Ghidra output with the object struct applied; not matching C.
// ---- 801e4174 FUN_801e4174

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4174(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801e4200();
  cVar1 = FUN_80104820(obj,0x38,0x78);
  if ((cVar1 == '\0') &&
     (((obj->var & 0x80) == 0 || (((int)(uint)DAT_801b29a2 >> (obj->var & 0x1f) & 1U) == 0)))) {
    Obj_FreeDespawn(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e4200 FUN_801e4200

void FUN_801e4200(int param_1)

{
  (*(code *)(&PTR_FUN_801ea898)[*(byte *)(param_1 + 1)])();
  *(undefined **)(param_1 + 0x38) = &DAT_801ea890;
  *(undefined **)(param_1 + 0x3c) = &DAT_801ea888;
  FUN_80107bf4(param_1,&g_player,1);
  FUN_8010976c(param_1);
  *(undefined **)(param_1 + 0x3c) = &DAT_801ea88c;
  return;
}


// ---- 801e428c FUN_801e428c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e428c(MM8Obj *obj)

{
  byte bVar1;
  char *pcVar2;
  
                    /* Possible PsyQ macro: setTile16() + setSemiTrans(tile16, 1) */
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
  Anim_Set(obj,1);
  if ((obj->var & 0x80) == 0) {
    pcVar2 = &DAT_801b29a3;
    if (obj->var == 0) {
      pcVar2 = &DAT_801b29a0;
    }
    if (*pcVar2 == '\0') {
      obj->state = 1;
      obj->sub2 = 0;
    }
    else {
      obj->state = 3;
      obj->y = obj->y + -0x40;
    }
  }
  else if (((int)(uint)DAT_801b29a1 >> (obj->var & 0x1f) & 1U) == 0) {
    obj->dmg_table = 0x78;
    obj->state = 2;
    obj->sub2 = 0;
    obj->y = obj->y + -0x40;
  }
  else {
    obj->state = 3;
  }
  return;
}


// ---- 801e43a0 FUN_801e43a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e43a0(MM8Obj *obj)

{
  char *pcVar1;
  
  pcVar1 = &DAT_801b29a3;
  if (obj->var == 0) {
    pcVar1 = &DAT_801b29a0;
  }
  if (obj->sub2 == 0) {
    if (*pcVar1 != '\0') {
      obj->speed_y_up = 0x10000;
      obj->sub2 = 1;
      *(short *)&obj->target_prio = obj->y;
      FUN_8010544c(obj,0xcf);
    }
  }
  else if (obj->sub2 == 1) {
    FUN_80104d18(obj);
    if ((int)obj->y <= *(short *)&obj->target_prio + -0x40) {
      obj->y = *(short *)&obj->target_prio + -0x40;
      obj->state = 3;
    }
  }
  return;
}


// ---- 801e4464 FUN_801e4464

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4464(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    bVar1 = obj->dmg_table;
    obj->dmg_table = bVar1 - 1;
    if (bVar1 == 0) {
      obj->speed_y_up = -0x10000;
      obj->sub2 = 2;
      *(short *)&obj->target_prio = obj->y;
      FUN_8010544c(obj,0xcf);
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && (((int)(uint)DAT_801b29a2 >> (obj->var & 0x1f) & 1U) != 0)) {
      obj->sub2 = 1;
    }
  }
  else if (bVar1 == 2) {
    FUN_80104d18(obj);
    obj->hitbox = &DAT_801ea88c;
    iVar2 = Obj_HitboxOverlap(&g_player,obj);
    if (iVar2 != 0) {
      DAT_8015e283 = 0;
    }
    if (*(short *)&obj->target_prio + 0x40 <= (int)obj->y) {
      obj->y = *(short *)&obj->target_prio + 0x40;
      obj->state = 3;
      DAT_801b29a1 = DAT_801b29a1 | (byte)(1 << (obj->var & 0x1f));
      DAT_801b29a2 = DAT_801b29a2 & ~(byte)(1 << (obj->var & 0x1f));
    }
  }
  return;
}


