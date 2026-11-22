// T2_12, STAGE05.BIN, handler 0x801E32E4. Ghidra output with the object struct applied; not matching C.
// ---- 801e32e4 FUN_801e32e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e32e4(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801ea824)[obj->var])();
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if ((cVar1 == '\0') && ((obj->var == 0 || (DAT_801b29a0 != '\x01')))) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e3374 FUN_801e3374

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3374(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea82c)[obj->state])();
  return;
}


// ---- 801e33b0 FUN_801e33b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e33b0(MM8Obj *obj)

{
  byte bVar1;
  
                    /* Possible PsyQ macro: setLineF2() */
  obj->bank = 0x40;
  obj->vram_base = DAT_801703c8;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->draw_list = 7;
  obj->speed_x = 0;
                    /* Possible PsyQ macro: setLineF2() + setSemiTrans(lineF2, 1) */
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->state = 1;
  obj->clut = bVar1;
  if (DAT_801b29a0 == '\0') {
    Anim_Set(obj,2);
    obj->sub2 = 0;
  }
  else {
    Anim_SetAtStep(obj,3,2);
    obj->sub2 = 2;
  }
  obj->sub3 = 0;
  obj->hitbox = &DAT_801ea7f0;
  obj->box2 = &UNK_801ea7f4 + (uint)obj->anim_extra * 5;
  return;
}


// ---- 801e3484 FUN_801e3484

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3484(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  
  obj->box2 = &UNK_801ea7f4 + (uint)obj->anim_extra * 5;
  bVar2 = FUN_80107bf4(obj,&g_player,5);
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      FUN_8010544c(obj,0x2b);
      DAT_801b29a0 = 1;
      obj->sub2 = 2;
    }
  }
  else if (((bVar1 < 2) && (bVar1 == 0)) && ((DAT_8015e27c & bVar2) == 0x80)) {
    obj->sub2 = 1;
    Anim_Set(obj,3);
  }
  Anim_Step(obj);
  return;
}


// ---- 801e3560 FUN_801e3560

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3560(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea834)[obj->state])();
  obj->hitbox = &DAT_801ea81c;
  obj->box2 = &UNK_801ea80c + (uint)(byte)obj->field_0x4c * 5;
  FUN_80107bf4(obj,&g_player,1);
  FUN_8010976c(obj);
  obj->box2 = &DAT_801ea811;
  obj->hitbox = &DAT_801ea820;
  FUN_80107bf4(obj,&g_player,1);
  FUN_8010976c(obj);
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801e3630 FUN_801e3630

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3630(MM8Obj *obj)

{
  byte bVar1;
  
                    /* Possible PsyQ macro: setLineF2() */
  obj->bank = 0x40;
  obj->vram_base = DAT_801703c8;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
                    /* Probable PsyQ macro: setTile8() */
  obj->flip = 0;
  obj->draw_list = 7;
  obj->clut = bVar1;
  if (DAT_801b29a0 == '\0') {
    Anim_Set(obj,0);
    obj->state = 1;
    obj->sub2 = 0;
    obj->field_0x4c = 2;
    *(short *)&obj->target_prio = obj->x;
  }
  else {
    Anim_Set(obj,1);
    obj->state = 2;
    obj->sub2 = 2;
    obj->field_0x4c = 0;
    obj->y = obj->y + -0x40;
  }
  obj->sub3 = 0;
  obj->hitbox = &DAT_801ea808;
  obj->box2 = &UNK_801ea80c + (uint)(byte)obj->field_0x4c * 5;
  return;
}


// ---- 801e3728 FUN_801e3728

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3728(MM8Obj *obj)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  byte bVar7;
  undefined4 uVar8;
  
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    if ((obj->dmg_table & 0x1f) == 0x1f) {
      FUN_800fd100(0xcb);
    }
    bVar1 = obj->dmg_table;
    obj->dmg_table = bVar1 - 1;
    if (bVar1 == 0) {
      obj->dmg_table = 0x3c;
      puVar5 = (undefined1 *)Obj_AllocType4();
      if (puVar5 != (undefined1 *)0x0) {
        *puVar5 = 1;
        puVar5[6] = 0x1c;
        puVar5[7] = 1;
        puVar5[1] = 0;
        *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)&obj->x_frac;
        *(undefined4 *)(puVar5 + 0x10) = *(undefined4 *)&obj->y_frac;
      }
      obj->sub2 = 2;
    }
    goto LAB_801e3a68;
  }
  if (bVar1 < 2) {
                    /* Possible PsyQ macro: setPolyF3() */
    if ((bVar1 == 0) && (DAT_801b29a0 != '\0')) {
      Anim_Set(obj,1);
      obj->dmg_table = 0x3c;
      DAT_801d2936 = 0x80;
      obj->sub2 = 1;
      obj->invuln = 0;
      obj->hp = 0;
      obj->field_0x4c = 2;
      *(short *)&obj->field_0x4a = obj->y;
    }
    goto LAB_801e3a68;
  }
  if (bVar1 == 2) {
    if ((obj->dmg_table & 0x1f) == 0x1f) {
      FUN_800fd100(0xcb);
    }
    if (obj->dmg_table == 0) {
      obj->sub2 = 3;
      obj->dmg_table = 0;
      DAT_801d2936 = 0xff;
      obj->speed_y_up = 0x4000;
      goto LAB_801e3a68;
    }
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->dmg_table = obj->dmg_table - 1;
    if (obj->hp == 0) {
      sVar3 = obj->x + 1;
    }
    else {
      sVar3 = obj->x + -1;
    }
    obj->x = sVar3;
                    /* Possible PsyQ macro: setPolyF4() */
    bVar1 = obj->invuln + 1;
    obj->invuln = bVar1;
    bVar7 = 0x1f;
    if ((bVar1 & 1) != 0) {
      obj->hp = obj->hp ^ 1;
    }
    bVar1 = obj->dmg_table & 0x1f;
LAB_801e3a54:
    if (bVar7 != bVar1) goto LAB_801e3a68;
    uVar8 = 0xcc;
  }
  else {
    if (bVar1 != 3) goto LAB_801e3a68;
    if ((obj->dmg_table & 0x1f) == 0x1f) {
      FUN_800fd100(0xcb);
    }
    if ((DAT_801d2936 < 0xc0) && (uVar4 = Rand(), (uVar4 & 0xf) == 0xf)) {
      FUN_801e3b48();
    }
    if (((obj->dmg_table & 0x3f) == 0x3f) &&
       (puVar5 = (undefined1 *)Obj_AllocType3(), puVar5 != (undefined1 *)0x0)) {
      *puVar5 = 1;
      puVar5[6] = 0x21;
      puVar5[7] = 0;
      puVar5[1] = 0;
      uVar8 = *(undefined4 *)&obj->x_frac;
      *(undefined2 *)(puVar5 + 0x12) = 0x300;
      *(undefined4 *)(puVar5 + 0xc) = uVar8;
      uVar2 = Rand();
      uVar4 = Rand();
      if ((uVar4 & 1) == 0) {
                    /* Possible PsyQ macro: setLineF2() */
        sVar3 = *(short *)(puVar5 + 0xe) - (uVar2 & 0xf);
      }
      else {
        sVar3 = (uVar2 & 0xf) + *(short *)(puVar5 + 0xe);
      }
      *(short *)(puVar5 + 0xe) = sVar3;
    }
    bVar1 = obj->dmg_table - 1;
    obj->dmg_table = bVar1;
    if (bVar1 != 0) {
      FUN_80104d18(obj);
      bVar7 = obj->dmg_table & 0x1f;
      obj->x = obj->x ^ 1;
      bVar1 = 0x1f;
      goto LAB_801e3a54;
    }
    obj->speed_y_up = 0;
    obj->state = 2;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->x = *(short *)&obj->target_prio;
    DAT_801b29a0 = '\x02';
    DAT_801d2936 = 0x1e;
    uVar8 = 0xcd;
  }
  FUN_8010544c(obj,uVar8);
LAB_801e3a68:
  Anim_Step(obj);
  if (obj->field_0x4c != '\0') {
    iVar6 = (int)*(short *)&obj->field_0x4a - (int)obj->y;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if (0x30 < iVar6) {
      obj->field_0x4c = 0;
    }
  }
  return;
}


// ---- 801e3ac8 FUN_801e3ac8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3ac8(MM8Obj *obj)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (obj->sub3 == 0) {
    obj->hitbox = &DAT_801ea808;
    iVar1 = Obj_HitboxOverlap(obj,&g_player);
    if ((iVar1 != 0) && (puVar2 = (undefined1 *)Obj_AllocType4(), puVar2 != (undefined1 *)0x0)) {
      obj->sub3 = 1;
      *puVar2 = 1;
      puVar2[6] = 0x1c;
      puVar2[7] = 0;
      puVar2[1] = 0;
    }
  }
  return;
}


// ---- 801e3b48 FUN_801e3b48

void FUN_801e3b48(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocMain();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x4a;
    puVar2[7] = 0;
    *(undefined2 *)(puVar2 + 0xe) = 0x4d0;
    uVar1 = Rand();
    *(ushort *)(puVar2 + 0x12) = (uVar1 & 0xf) + 0x360;
  }
  return;
}


