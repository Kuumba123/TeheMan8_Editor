// T2_27, STAGE06.BIN, handler 0x801E3790. Ghidra output with the object struct applied; not matching C.
// ---- 801e3790 FUN_801e3790

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3790(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5c14)[obj->dmg_table])();
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e37e0 FUN_801e37e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e37e0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5c1c)[obj->state])();
  return;
}


// ---- 801e381c FUN_801e381c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e381c(MM8Obj *obj)

{
  byte bVar1;
  word wVar2;
  
  obj->speed_x = 0;
  obj->speed_y_up = 0;
  obj->accel_x = 0;
  obj->gravity = 0;
  obj->state = obj->state + 1;
  bVar1 = DAT_80159fdb;
  obj->flip = (obj->var == 0x12) << 6;
  obj->draw_list = 6;
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  obj->bank = 0x77;
  obj->clut = bVar1;
  wVar2 = DAT_80170436;
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->field_0x33 = 0;
  obj->box2 = &DAT_801e5bfc;
  obj->field_0x40 = 0;
  obj->field_0x43 = 0;
  obj->vram_base = wVar2;
  Anim_Set(obj,obj->var != 0 && obj->var != 0x12);
                    /* Possible PsyQ macro: setPolyF4() */
  return;
}


// ---- 801e38c0 FUN_801e38c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e38c0(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_80107bf4(obj,&g_player,5);
  sVar1 = 0x381;
  if (iVar2 == 0) {
    sVar1 = 0x380;
  }
  obj->y = sVar1;
  if (DAT_8015e248._2_2_ == 0xda0) {
                    /* Possible PsyQ macro: setPolyF4() */
    obj->contact_dmg = 0x28;
    obj->state = obj->state + 1;
  }
  return;
}


// ---- 801e3928 FUN_801e3928

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3928(MM8Obj *obj)

{
  ushort uVar1;
  byte bVar2;
  
  FUN_80107bf4(obj,&g_player,5);
  uVar1 = Rand();
  bVar2 = obj->contact_dmg - 1;
  obj->contact_dmg = bVar2;
  obj->x = (ushort)obj->var * 0x10 + (uVar1 & 1) + 0xd18;
  if (bVar2 == 0) {
    obj->state = obj->state + 1;
  }
  return;
}


// ---- 801e3acc FUN_801e3acc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3acc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5c34)[obj->state])();
  return;
}


// ---- 801e3b08 FUN_801e3b08

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3b08(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  word wVar3;
  uint uVar4;
  int iVar5;
  
  obj->speed_x = 0;
  obj->state = obj->state + 1;
  uVar4 = Rand();
  iVar5 = -0x20000 - (uVar4 & 0x1fff);
  *(int *)&obj->target_prio = iVar5;
  obj->speed_y_up = iVar5;
  obj->accel_x = 0;
  obj->gravity = 0;
  bVar2 = DAT_80159fdb;
  obj->draw_list = 7;
  obj->flip = 0;
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  obj->bank = 0x77;
  obj->clut = bVar2;
  wVar3 = DAT_80170436;
  obj->field_0x33 = 0;
  obj->field_0x40 = 0;
  obj->field_0x43 = 0;
  obj->box2 = &UNK_801e5c01 + (uint)obj->var * 5;
  obj->vram_base = wVar3;
  obj->hitbox = &UNK_801e5c0c + (uint)obj->var * 4;
  iVar5 = FUN_8012c108(obj,&obj->field_0x4c,0,3,0,obj->var + 6);
  if (iVar5 != 0) {
                    /* Probable PsyQ macro: setTile16() */
    *(undefined1 *)(iVar5 + 7) = 0x70;
    cVar1 = DAT_80159fcd;
    *(undefined1 *)(iVar5 + 0x26) = 6;
    *(char *)(iVar5 + 0x33) = cVar1 + '\x01';
    obj->field_0x4c = 0;
  }
  Anim_Set(obj,obj->var + 4);
  return;
}


// ---- 801e3c30 FUN_801e3c30

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3c30(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  FUN_80104d18();
                    /* Possible PsyQ macro: setPolyGT4() */
  if ((DAT_8015e27c & 0x80) == 0) {
    iVar2 = FUN_80107bf4(obj,&g_player,5);
    if (iVar2 == 0) {
      iVar2 = *(int *)&obj->target_prio;
    }
    else {
      iVar2 = *(int *)&obj->target_prio + -0x10000;
    }
    obj->speed_y_up = iVar2;
  }
  if ((obj->sub2 != 0) && (FUN_80106214(obj), (obj->field_0x33 & 0x80) != 0)) {
    obj->state = obj->state + 1;
  }
  Anim_Step(obj);
  cVar1 = FUN_80104820(obj,0x38,0x60);
  if (cVar1 == '\0') {
    obj->field_0x4c = 2;
    Obj_Free(obj);
  }
  return;
}


// ---- 801e3d0c FUN_801e3d0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3d0c(MM8Obj *obj)

{
  FUN_80108e84();
  FUN_8012ae08(obj,obj->var + 0x31);
  obj->field_0x4c = 2;
  Obj_Free();
  return;
}


