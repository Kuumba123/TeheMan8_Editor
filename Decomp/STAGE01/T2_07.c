// T2_07, STAGE01.BIN, handler 0x801E43B4. Ghidra output with the object struct applied; not matching C.
// ---- 801e43b4 FUN_801e43b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e43b4(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e6ec0)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_FreeDespawn(obj);
  }
  obj->hitbox = &DAT_801e6e88;
  obj->box2 = &DAT_801e6e90;
  return;
}


// ---- 801e4438 FUN_801e4438

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4438(MM8Obj *obj)

{
  byte bVar1;
  
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->bank = 0x23;
  obj->vram_base = DAT_8017038e;
  bVar1 = DAT_80159f87;
  obj->box2 = &DAT_801e6e90;
  obj->hitbox = &DAT_801e6e88;
  obj->flip = 0;
  obj->draw_list = 6;
  obj->clut = bVar1;
  Anim_Set(obj,0);
  obj->state = 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801e44cc FUN_801e44cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e44cc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6ec8)[obj->var])();
  return;
}


// ---- 801e4508 FUN_801e4508

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4508(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6ed8)[obj->sub2])();
  return;
}


// ---- 801e4544 FUN_801e4544

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4544(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6ee4)[obj->sub2])();
  return;
}


// ---- 801e4580 FUN_801e4580

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4580(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6ef8)[obj->sub2])();
  return;
}


// ---- 801e45bc FUN_801e45bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e45bc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6f0c)[obj->sub2])();
  return;
}


// ---- 801e45f8 FUN_801e45f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e45f8(MM8Obj *obj)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  
  FUN_801e4870(obj,0);
  if (obj->sub3 == 0) {
    obj->invuln = (&DAT_801e6ea8)[obj->var];
    uVar2 = *(undefined1 *)&obj->y;
    uVar3 = *(undefined1 *)((int)&obj->y + 1);
    iVar4 = *(int *)(&DAT_801e6eb0 + (uint)obj->var * 4);
    obj->sub3 = 1;
    obj->dmg_table = uVar2;
    obj->contact_dmg = uVar3;
    obj->speed_y_up = iVar4;
  }
  else {
    bVar1 = obj->invuln;
    obj->invuln = bVar1 - 1;
    if (bVar1 == 0) {
      obj->sub2 = 1;
      obj->sub3 = 0;
      FUN_8010544c(obj,0x140);
    }
  }
  return;
}


// ---- 801e46a4 FUN_801e46a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e46a4(MM8Obj *obj)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  
  FUN_801e4870(obj,0);
  if (obj->sub3 == 0) {
    uVar2 = *(undefined1 *)&obj->y;
    uVar3 = *(undefined1 *)((int)&obj->y + 1);
    obj->invuln = (&DAT_801e6eac)[obj->var];
    iVar4 = *(int *)(&DAT_801e6eb0 + (uint)obj->var * 4);
    obj->dmg_table = uVar2;
    obj->contact_dmg = uVar3;
    obj->sub3 = 1;
    obj->speed_y_up = -iVar4;
  }
  else {
    bVar1 = obj->invuln;
    obj->invuln = bVar1 - 1;
    if (bVar1 == 0) {
      obj->sub2 = 3;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801e4744 FUN_801e4744

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4744(MM8Obj *obj)

{
  FUN_801e4870(obj,0);
  return;
}


// ---- 801e4764 FUN_801e4764

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4764(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
  FUN_80104d18();
  FUN_801e4870(obj,0);
  sVar1._0_1_ = obj->dmg_table;
  sVar1._1_1_ = obj->contact_dmg;
  iVar2 = (int)sVar1 - (int)obj->y;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (*(short *)(&DAT_801e6ea0 + (uint)obj->var * 2) <= iVar2) {
    obj->sub2 = obj->sub2 + 1;
  }
  return;
}


// ---- 801e47e0 FUN_801e47e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e47e0(MM8Obj *obj)

{
  FUN_80104d18();
  FUN_801e4870(obj,1);
  obj->box2 = &DAT_801e6e90;
  FUN_80106214(obj);
  if (obj->field_0x4 == '\0') {
    if (obj->field_0x42 == '\0') {
      obj->field_0x4 = 1;
    }
  }
  else if (obj->field_0x42 != '\0') {
    obj->field_0x4 = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  return;
}


// ---- 801e4870 FUN_801e4870

void FUN_801e4870(int param_1,char param_2)

{
  int iVar1;
  
  if ((param_2 == '\x01') && ((DAT_8015e26f & 0x80) != 0)) {
    *(undefined **)(param_1 + 0x3c) = &DAT_801e6e8c;
    iVar1 = Obj_HitboxOverlap(&g_player,param_1);
    if (iVar1 != 0) {
      DAT_8015e283 = '\0';
    }
  }
  *(undefined **)(param_1 + 0x38) = &DAT_801e6e98;
  if (DAT_8015e283 != '\0') {
    FUN_80107bf4(param_1,&g_player,1);
    FUN_80107bf4(param_1,&g_player,1);
    FUN_80107bf4(param_1,&g_player,1);
  }
  *(undefined **)(param_1 + 0x3c) = &DAT_801e6e88;
  FUN_8010976c(param_1);
  return;
}


