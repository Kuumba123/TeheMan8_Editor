// T3_2C, STAGE06.BIN, handler 0x801E4354. Ghidra output with the object struct applied; not matching C.
// ---- 801e4354 FUN_801e4354

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4354(MM8Obj *obj)

{
  byte *pbVar1;
  
  pbVar1 = obj->box2;
  (*(code *)(&PTR_FUN_801e5c70)[obj->state])();
  obj->x = *(short *)(pbVar1 + 0xe);
  obj->y = *(short *)(pbVar1 + 0x12);
  if ((pbVar1[1] == 4) || (pbVar1[0x5b] != 0)) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e43e4 FUN_801e43e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e43e4(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  word wVar3;
  
  bVar1 = obj->var;
  obj->speed_x = 0;
  obj->speed_y_up = 0;
  obj->accel_x = 0;
  obj->gravity = 0;
  obj->state = obj->state + 1;
  bVar2 = DAT_80159fcd;
  obj->flip = 0;
  obj->bank = 0x69;
  obj->clut = bVar2;
  wVar3 = DAT_8017041a;
  obj->draw_list = 9;
  *(undefined1 *)&obj->hitbox = 0;
  obj->vram_base = wVar3;
  bVar2 = obj->box2[0x57];
  *(undefined1 *)((int)&obj->hitbox + 2) = 1;
  *(undefined1 *)((int)&obj->hitbox + 3) = 0;
  *(byte *)((int)&obj->hitbox + 1) = bVar2;
  Anim_Set(obj,bVar1 * -4 + '\x15');
  Obj_CullAndQueueDrawMargin(obj,0x40);
  return;
}


// ---- 801e4490 FUN_801e4490

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4490(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5c78)[obj->var])();
  return;
}


// ---- 801e44cc FUN_801e44cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e44cc(MM8Obj *obj)

{
  byte bVar1;
  byte *pbVar2;
  
  bVar1 = DAT_80159fcd;
  pbVar2 = obj->box2;
  if (pbVar2[0x5a] == 0) {
    if ((pbVar2[0x5d] & 1) == 0) {
      obj->clut = DAT_80159fcd;
    }
    else {
      obj->clut = 0;
    }
    if ((*(byte *)((int)&obj->hitbox + 1) == pbVar2[0x57]) && (pbVar2[0x5a] == 0)) {
      Anim_Step(obj);
      *(undefined1 *)&obj->hitbox = 0;
    }
    else {
      bVar1 = pbVar2[0x57];
      *(byte *)((int)&obj->hitbox + 1) = bVar1;
      Anim_Set(obj,bVar1 + 1);
      *(undefined1 *)&obj->hitbox = 0;
    }
  }
  else if (*(char *)&obj->hitbox == '\0') {
    *(undefined1 *)&obj->hitbox = 1;
    obj->clut = bVar1;
    Anim_Set();
  }
  else {
    Anim_Step(obj,0x15);
  }
  if (((pbVar2[0x51] == 0) || (pbVar2[3] < 2)) && ((pbVar2[1] < 3 || ((DAT_80170574 & 1) != 0)))) {
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  return;
}


// ---- 801e4624 FUN_801e4624

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4624(MM8Obj *obj)

{
  char cVar1;
  byte *pbVar2;
  
  pbVar2 = obj->box2;
  Anim_Step();
  if ((pbVar2[0x51] == 0) || (pbVar2[3] < 2)) {
    if (*(char *)((int)&obj->hitbox + 2) == '\0') {
      *(undefined1 *)((int)&obj->hitbox + 2) = 1;
      *(undefined1 *)((int)&obj->hitbox + 3) = 0;
      Anim_Set(obj,0x11);
    }
    else {
      Anim_Step(obj);
      cVar1 = *(char *)((int)&obj->hitbox + 2) + '\x01';
      *(char *)((int)&obj->hitbox + 2) = cVar1;
      if (cVar1 != '\x1e') goto LAB_801e4704;
      *(undefined1 *)((int)&obj->hitbox + 2) = 1;
    }
    FUN_8010544c(obj,0x12a);
  }
  else if (*(char *)((int)&obj->hitbox + 3) == '\0') {
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
    *(undefined1 *)((int)&obj->hitbox + 2) = 0;
    *(undefined1 *)((int)&obj->hitbox + 3) = 1;
    Anim_Set(obj,0x12);
  }
  else {
    Anim_Step(obj);
  }
LAB_801e4704:
  if (obj->anim_extra != 1) {
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  return;
}


