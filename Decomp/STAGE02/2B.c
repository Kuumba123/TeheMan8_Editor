// ID 2B, STAGE02.BIN, handler 0x801DD2E0. Ghidra output with the object struct applied; not matching C.
// ---- 801dd2e0 FUN_801dd2e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd2e0(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e871c)[obj->state])();
  iVar1 = FUN_80104820(obj,0x38,0xf0);
  if (iVar1 == 0) {
    Obj_FreeDespawn(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801dd358 FUN_801dd358

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd358(MM8Obj *obj)

{
  undefined4 uVar1;
  
  Enemy_InitFromTable();
  obj->hitbox = &DAT_801e872c;
  obj->box2 = &DAT_801e8730;
  obj->draw_list = 9;
  obj->flip = 0;
  obj->field_0x58 = 0;
  obj->field_0x59 = 0;
  obj->field_0x5a = 0;
  obj->field_0x5b = 0;
  *(word *)&obj->field_0x50 = obj->y_frac;
  *(short *)&obj->field_0x52 = obj->y;
  if (obj->var == 0) {
    obj->state = 1;
    uVar1 = 3;
  }
  else if (obj->var == 1) {
    obj->state = 2;
    uVar1 = 0;
  }
  else {
    obj->state = 3;
    uVar1 = 4;
  }
  Anim_Set(obj,uVar1);
  obj->sub2 = 0;
  obj->sub3 = 0;
  return;
}


// ---- 801dd408 FUN_801dd408

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd408(MM8Obj *obj)

{
  FUN_80107bf4(obj,&g_player,1);
  FUN_80109804(obj);
  return;
}


// ---- 801dd444 FUN_801dd444

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd444(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  
  bVar1 = obj->sub2;
  obj->y_frac = *(undefined2 *)&obj->field_0x50;
  obj->y = *(undefined2 *)&obj->field_0x52;
  if (bVar1 == 0) {
    bVar1 = FUN_80107bf4(obj,&g_player,1);
    FUN_80109804(obj);
    if (bVar1 != 0) {
      FUN_80106214(&g_player);
    }
    if (obj->field_0x59 == '\0') {
      if ((bVar1 & 0x80) != 0) {
        FUN_8010544c(obj,499);
        obj->field_0x59 = 0x1e;
        return;
      }
      obj->field_0x59 = 0;
      return;
    }
    bVar1 = obj->field_0x59;
    cVar3 = obj->field_0x59 + -1;
    obj->field_0x59 = cVar3;
    obj->y = (bVar1 & 2) + *(short *)&obj->field_0x52;
    if (cVar3 != '\0') {
      return;
    }
    uVar4 = 1;
  }
  else {
    if (bVar1 == 1) {
      Anim_Step(obj);
      iVar2 = Anim_AtLoopMarker(obj);
      if (iVar2 == 0) {
        return;
      }
      bVar1 = obj->sub2;
      obj->field_0x59 = 0x14;
      goto code_r0x801dd578;
    }
    if (bVar1 != 2) {
      if (bVar1 != 3) {
        return;
      }
      Anim_Step(obj);
      iVar2 = Anim_AtLoopMarker(obj);
      if (iVar2 == 0) {
        return;
      }
      obj->sub2 = 0;
      return;
    }
    cVar3 = obj->field_0x59 + -1;
    obj->field_0x59 = cVar3;
    if (cVar3 != '\0') {
      return;
    }
    uVar4 = 2;
  }
  Anim_Set(obj,uVar4);
  bVar1 = obj->sub2;
code_r0x801dd578:
  obj->sub2 = bVar1 + 1;
  return;
}


// ---- 801dd5c4 FUN_801dd5c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd5c4(MM8Obj *obj)

{
  undefined1 uVar1;
  
  if (obj->field_0x5b != '\0') {
    FUN_80104ccc();
    obj->field_0x5b = 0;
  }
  uVar1 = FUN_80107bf4(obj,&g_player,6);
  obj->field_0x5a = uVar1;
  FUN_80109804(obj);
  if (obj->field_0x5a != '\0') {
    FUN_80106214(&g_player);
  }
  (*(code *)(&PTR_LAB_801e8738)[obj->sub2])(obj);
  return;
}


