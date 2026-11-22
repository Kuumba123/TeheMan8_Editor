// T2_2B, STAGE07.BIN, handler 0x801DE688. Ghidra output with the object struct applied; not matching C.
// ---- 801de688 FUN_801de688

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de688(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e0bc0)[obj->state])();
  if ((DAT_801c3371 == '\x01') || (DAT_801c3371 == '\x04')) {
    FUN_801debcc(obj);
    Obj_CullAndQueueDraw(obj);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801de70c FUN_801de70c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de70c(MM8Obj *obj)

{
  byte bVar1;
  word wVar2;
  uint uVar3;
  
                    /* Possible PsyQ macro: setTile1() + setSemiTrans(tile1, 1) */
  obj->bank = 0x6a;
  bVar1 = DAT_80159fce;
  obj->clut = DAT_80159fce;
  if ((obj->var & 1) != 0) {
    obj->clut = bVar1 + 1;
  }
  wVar2 = DAT_8017041c;
  obj->draw_list = 8;
  obj->flip = 0;
  uVar3 = obj->var & 0xf;
  obj->vram_base = wVar2;
  *(undefined1 **)&obj->dmg_table = &DAT_801b29a1 + (obj->var & 0xf);
  if (DAT_801c3371 != '\x01') {
    uVar3 = uVar3 + 4;
  }
  if ((obj->var & 0x80) == 0) {
    obj->state = 1;
    Anim_Set(obj,4);
    obj->x = *(short *)(&DAT_801e0b98 + uVar3 * 2);
    obj->y = *(short *)(&DAT_801e0ba8 + uVar3 * 2);
  }
  else {
    obj->state = 2;
    obj->field_0x43 = 1;
    Anim_Set(obj,2);
    obj->x = *(short *)(&DAT_801e0b78 + uVar3 * 2);
    obj->y = *(short *)(&DAT_801e0b88 + uVar3 * 2);
    obj->sub2 = (&DAT_801e0bb8)[uVar3];
    obj->hitbox = &UNK_801e0b70 + (obj->sub2 & 2) * 2;
  }
  return;
}


// ---- 801de874 FUN_801de874

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de874(MM8Obj *obj)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->dmg_table;
  if (obj->sub2 == 0) {
    Anim_Step();
    obj->box2 = &DAT_801e0b69;
    FUN_80107bf4(obj,&g_player,6);
    if (((obj->field_0x40 & 0x40) == 0) || (obj->target_prio != 0)) goto LAB_801de92c;
    obj->sub2 = 1;
    *pcVar2 = '\x01';
    FUN_800fd100(0x2b);
    uVar1 = 5;
  }
  else {
    Anim_Step(obj);
    if (*pcVar2 != '\0') goto LAB_801de92c;
    obj->sub2 = 0;
    uVar1 = 4;
  }
  Anim_Set(obj,uVar1);
LAB_801de92c:
  obj->box2 = &DAT_801e0b64;
  obj->target_prio = obj->field_0x40 & 0x40;
  FUN_80107bf4(obj,&g_player,1);
  return;
}


// ---- 801de96c FUN_801de96c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de96c(MM8Obj *obj)

{
  int iVar1;
  
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801e0bcc)[obj->sub2])();
  obj->box2 = &DAT_801e0b5d;
  FUN_80106214(obj);
  obj->box2 = &DAT_801e0b58;
  FUN_80107bf4(obj,&g_player,6);
  obj->hitbox = &UNK_801e0b70 + (obj->sub2 & 2) * 2;
  if (((obj->y != obj->prev_y) && (g_player != '\0')) &&
     (iVar1 = Obj_HitboxOverlap(&g_player,obj), iVar1 != 0)) {
    DAT_8015e283 = 0;
  }
  return;
}


// ---- 801dea48 FUN_801dea48

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dea48(MM8Obj *obj)

{
  if (**(char **)&obj->dmg_table != '\0') {
    obj->sub2 = 1;
    obj->speed_x = 0;
    obj->speed_y_up = 0x20000;
    Anim_Set(obj,3);
    FUN_8010544c(obj,0x11e);
  }
  return;
}


// ---- 801deaa8 FUN_801deaa8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deaa8(MM8Obj *obj)

{
  if ((obj->field_0x33 & 0x40) == 0) {
    Anim_Step(obj);
    FUN_80104d18(obj);
  }
  else {
    obj->sub2 = 2;
    **(undefined1 **)&obj->dmg_table = 0;
    Anim_Set(obj,2);
  }
  return;
}


// ---- 801deb0c FUN_801deb0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deb0c(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT3() */
  if (**(char **)&obj->dmg_table != '\0') {
    obj->sub2 = 3;
    obj->speed_x = 0;
    obj->speed_y_up = -0x20000;
    Anim_Set(obj,3);
    FUN_8010544c(obj,0x11e);
  }
  return;
}


// ---- 801deb6c FUN_801deb6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deb6c(MM8Obj *obj)

{
  if ((obj->field_0x33 & 0x80) == 0) {
    Anim_Step(obj,2);
    FUN_80104d18(obj);
  }
  else {
    obj->sub2 = 0;
    **(undefined1 **)&obj->dmg_table = 0;
    Anim_Set();
  }
  return;
}


// ---- 801debcc FUN_801debcc

void FUN_801debcc(int param_1)

{
  short sVar1;
  short sVar2;
  
  sVar1 = *(short *)(param_1 + 0xe);
  if (sVar1 + 0x280 < (int)DAT_801d2918._2_2_) {
    sVar2 = 0x400;
  }
  else {
    sVar2 = -0x400;
    if (sVar1 + -0x380 <= (int)DAT_801d2918._2_2_) goto LAB_801dec10;
  }
  *(short *)(param_1 + 0xe) = sVar1 + sVar2;
LAB_801dec10:
  sVar1 = *(short *)(param_1 + 0x12);
  if (sVar1 + 0x180 < (int)g_cam_y) {
    sVar2 = 0x300;
  }
  else {
    sVar2 = -0x300;
    if (sVar1 + -0x280 <= (int)g_cam_y) {
      return;
    }
  }
                    /* Probable PsyQ macro: setTile16() */
  *(short *)(param_1 + 0x12) = sVar1 + sVar2;
  return;
}


