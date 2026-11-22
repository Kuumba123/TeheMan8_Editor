// T2_32, STAGE0D.BIN, handler 0x801F7744. Ghidra output with the object struct applied; not matching C.
// ---- 801f7744 FUN_801f7744

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f7744(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801f9208)[obj->state])();
  if ((obj->invuln == 0) && (iVar1 = Obj_InActiveArea(obj), iVar1 == 0)) {
    Obj_FreeDespawn(obj);
  }
  else if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801f77d4 FUN_801f77d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f77d4(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0xa7;
  obj->vram_base = DAT_80170496;
  bVar1 = DAT_8015a00b;
  obj->draw_list = 6;
  obj->flip = 0;
  obj->field_0x43 = 1;
  obj->invuln = 0;
  obj->clut = bVar1;
  if (obj->var == 0) {
    obj->box2 = &DAT_801f91fc;
    Anim_Set(obj,4);
    obj->state = 1;
  }
  else {
    obj->box2 = &DAT_801f9201;
    obj->invuln = 1;
    Anim_Set(obj,3);
    obj->draw_list = 5;
    obj->state = 3;
  }
  return;
}


// ---- 801f788c FUN_801f788c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f788c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f9218)[obj->sub2])();
  return;
}


// ---- 801f78c8 FUN_801f78c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f78c8(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  
  if (DAT_801c3378 == -1) {
    Anim_Set(obj,2);
    puVar2 = (undefined1 *)FUN_80105734(obj);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x32;
      puVar2[7] = 1;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
      sVar1 = DAT_801d292a;
      *(MM8Obj **)(puVar2 + 0x1c) = obj;
      *(short *)(puVar2 + 0x12) = sVar1 + -0x20;
    }
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801f7954 FUN_801f7954

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f7954(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  if (obj->sub3 == 0) {
    iVar1 = (int)obj->x - (int)DAT_8015e248._2_2_;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar1 < 0x14) {
      DAT_801b2993 = 1;
      DAT_801b2992 = 1;
      DAT_801b2994 = 1;
      FUN_801119e0((int)obj->x,DAT_8015e261);
      obj->sub3 = 1;
    }
  }
  else if (DAT_8015e2b0 == '\x01') {
    FUN_8010544c(obj,0x70);
    DAT_8015e2b9 = 1;
    obj->contact_dmg = 1;
    obj->sub2 = 2;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801f7a2c FUN_801f7a2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f7a2c(MM8Obj *obj)

{
  byte bVar1;
  
  Anim_Step();
  if (obj->sub3 == 0) {
    if (obj->contact_dmg == 2) {
      obj->dmg_table = 0xf;
      obj->sub3 = 1;
    }
  }
  else {
    bVar1 = obj->dmg_table - 1;
    obj->dmg_table = bVar1;
    if (bVar1 == 0) {
      obj->state = 2;
      obj->sub2 = 0;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801f7aac FUN_801f7aac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f7aac(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801f9224)[obj->sub2])();
  Anim_Step(obj);
  FUN_80107bf4(obj,&g_player,5);
  return;
}


// ---- 801f7cf0 FUN_801f7cf0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f7cf0(MM8Obj *obj)

{
  if ((*(char *)obj->accel_x == '\0') || (((char *)obj->accel_x)[6] != '2')) {
    Obj_Free(obj);
  }
  else {
    (*(code *)(&PTR_LAB_801f9230)[obj->sub2])(obj);
    FUN_80107bf4(obj,&g_player,1);
    Anim_Step(obj);
  }
  return;
}


