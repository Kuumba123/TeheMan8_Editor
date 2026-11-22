// ID 28, STAGE0D.BIN, handler 0x801DF2E4. Ghidra output with the object struct applied; not matching C.
// ---- 801df2e4 FUN_801df2e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df2e4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8400)[obj->state])();
  return;
}


// ---- 801df320 FUN_801df320

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df320(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  Enemy_InitFromTable();
  if (obj->var == 0) {
    puVar2 = (undefined1 *)Obj_AllocType3();
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x1e;
      puVar2[7] = 1;
      bVar1 = obj->flip;
      *(MM8Obj **)(puVar2 + 0x1c) = obj;
      puVar2[0x25] = bVar1;
    }
    obj->contact_dmg = 1;
    obj->state = 1;
    obj->clut = 0x14;
    obj->draw_list = 5;
    obj->hitbox = &DAT_801f83ec;
    obj->field_0x52 = 0;
    obj->field_0x5b = 0;
    obj->speed_y_up = -0x40000;
    obj->gravity = -0x3000;
    if (obj->flip == 0) {
      obj->speed_x = -0x40000;
    }
    else {
      obj->speed_x = 0x40000;
    }
    uVar3 = 0xb;
  }
  else {
    obj->state = 2;
    obj->draw_list = 9;
    obj->field_0x43 = 1;
    obj->hitbox = &DAT_801f83f0;
    obj->box2 = &DAT_801f83f8;
    obj->field_0x52 = 0;
    obj->field_0x59 = 0;
    obj->field_0x5a = 0;
    obj->speed_y_up = -0x40000;
    obj->gravity = 0x2000;
    if (obj->flip == 0) {
      obj->speed_x = -0x40000;
    }
    else {
      obj->speed_x = 0x40000;
    }
    uVar3 = 6;
  }
  Anim_Set(obj,uVar3);
  return;
}


// ---- 801df45c FUN_801df45c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df45c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  
  FUN_80104ccc();
  if (0 < obj->speed_y_up) {
    obj->gravity = -0xc00;
  }
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  if (obj->on_screen == 0) {
    if (obj->field_0x52 == '\x01') {
      FUN_80111c28();
    }
    Obj_Free(obj);
  }
  else if (obj->field_0x52 == '\0') {
    iVar2 = Obj_HitboxOverlap(obj,&g_player);
    if ((iVar2 != 0) && (iVar2 = FUN_80111b28(), iVar2 != 0)) {
      obj->field_0x52 = 1;
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x53 = 0x3c;
      obj->field_0x58 = 1;
    }
  }
  else if (obj->field_0x52 == '\x01') {
    DAT_8015e248._2_2_ = obj->x;
    DAT_8015e24c._2_2_ = obj->y;
    cVar1 = FUN_80111858();
    iVar2 = (uint)DAT_801d2918._2_2_ - ((ushort)obj->x - 0xa0);
    sVar4 = (short)iVar2;
    if (iVar2 * 0x10000 < 0) {
      sVar4 = -sVar4;
    }
    if (((byte)(cVar1 + 1U) < (byte)obj->field_0x53) && (sVar4 < 0x90)) {
      cVar3 = obj->field_0x58 + -1;
      obj->field_0x58 = cVar3;
      obj->field_0x53 = obj->field_0x53 - (cVar1 + 1U);
      if ((cVar3 == '\0') && (g_player != '\0')) {
        FUN_80111cb4(1);
        obj->field_0x58 = 10;
        FUN_801dfc24(obj,(obj->field_0x5b & 1) + 0xd,0,0);
        obj->field_0x5b = obj->field_0x5b + '\x01';
      }
    }
    else {
      FUN_80111c28();
      obj->field_0x52 = 2;
    }
  }
  return;
}


// ---- 801df628 FUN_801df628

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df628(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f840c)[obj->sub2])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801df688 FUN_801df688

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df688(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80104ccc();
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->sub2 = 1;
    obj->field_0x43 = 0;
    obj->field_0x58 = 0x3c;
    obj->speed_y_up = 0;
    if (obj->flip == 0) {
      iVar1 = -0x20000;
    }
    else {
      iVar1 = 0x20000;
    }
    obj->speed_x = iVar1;
    Anim_Set(obj,7);
                    /* Possible PsyQ macro: setPolyGT3() */
    iVar1 = FUN_801dfc24(obj,10,0x20,0);
    if (iVar1 != 0) {
      *(byte *)(iVar1 + 0x25) = obj->flip;
    }
    iVar1 = FUN_801dfc24(obj,10,0xffffffe0,0);
    if (iVar1 != 0) {
      *(byte *)(iVar1 + 0x25) = obj->flip ^ 0x40;
    }
    FUN_800fd100(0x25);
  }
  FUN_801dfbcc(obj);
  return;
}


// ---- 801df76c FUN_801df76c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df76c(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  FUN_80104d00(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->sub2 = 3;
  }
  else {
    if (obj->sub3 == 0) {
      FUN_801dfaf4(obj);
      obj->field_0x58 = obj->field_0x58 + -1;
      if ((byte)obj->field_0x59 < 0xf9) {
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
        obj->field_0x59 = obj->field_0x59 + '\x06';
      }
      if (obj->field_0x58 == '\0') {
        obj->sub3 = 1;
        obj->field_0x58 = 0x28;
        FUN_80108e84(obj);
        Obj_Free(obj);
        return;
      }
    }
    else {
      obj->field_0x58 = obj->field_0x58 + -1;
      if ((byte)obj->field_0x5a < 0xf9) {
        obj->field_0x5a = obj->field_0x5a + '\x06';
      }
      if (obj->field_0x58 == '\0') {
        obj->sub3 = 0;
        obj->field_0x58 = 0x3c;
        obj->field_0x59 = 0;
        obj->field_0x5a = 0;
      }
    }
    FUN_801dfa90(obj);
  }
  iVar1 = FUN_801dfbcc(obj);
  if (iVar1 == 0) {
    FUN_801dfb70(obj);
  }
  return;
}


// ---- 801df89c caseD_4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801df540::caseD_4(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x54;
  if (*(char *)(iVar2 + 0x47) == '\0') {
    FUN_80108e84();
    FUN_80111c28();
  }
  else {
    if (obj->sub3 == 0) {
      *(undefined1 *)(iVar2 + 0x51) = 1;
      obj->sub3 = 1;
    }
    if (*(char *)(iVar2 + 0x51) != '\0') {
      DAT_8015e248._2_2_ = obj->x;
      iVar2 = *(int *)&obj->y_frac - (DAT_8015e24c + 0x1600000);
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0x1f;
      }
      iVar2 = (iVar2 >> 5) + DAT_8015e24c;
      DAT_8015e24c = iVar2;
      if ((_DAT_80170574 & 7) != 0) {
        DAT_8015e24c._2_2_ = (short)((uint)iVar2 >> 0x10);
        if ((_DAT_80170574 & 0x10) == 0) {
          DAT_8015e261 = 0;
          sVar1 = DAT_8015e24c._2_2_ + -1;
        }
        else {
          DAT_8015e261 = 0x40;
          sVar1 = DAT_8015e24c._2_2_ + 1;
        }
        DAT_8015e24c = CONCAT22(sVar1,(short)iVar2);
      }
      Anim_Step(obj);
      FUN_801dfaf4(obj);
      return;
    }
  }
  Obj_Free(obj);
  return;
}


// ---- 801df9c8 FUN_801df9c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df9c8(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  FUN_80104ccc(obj);
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801dfa10 FUN_801dfa10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfa10(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    Anim_Set(obj,0x18);
    obj->sub3 = 1;
  }
  else {
    Anim_Step(obj);
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      FUN_80108e84(obj);
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801dfa90 FUN_801dfa90

void FUN_801dfa90(int param_1)

{
  int iVar1;
  
  if ((DAT_8015e283 != '\0') && (*(char *)(param_1 + 0x52) != '\0')) {
    iVar1 = FUN_80111b28();
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x52) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 2) = 2;
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801dfaf4 FUN_801dfaf4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801dfaf4(int param_1)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  
  if (((_DAT_80170574 & 3) == 0) &&
     (puVar2 = (undefined1 *)Obj_AllocType3(), puVar2 != (undefined1 *)0x0)) {
    *puVar2 = 1;
    puVar2[6] = 0x1e;
    puVar2[7] = 0;
    puVar2[0x25] = *(undefined1 *)(param_1 + 0x25);
    *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    uVar1 = *(undefined2 *)(param_1 + 0x12);
    *(int *)(puVar2 + 0x1c) = param_1;
    *(undefined2 *)(puVar2 + 0x12) = uVar1;
  }
  return;
}


// ---- 801dfb70 FUN_801dfb70

void FUN_801dfb70(int param_1)

{
  DAT_801f83f5 = (char)((int)((uint)*(byte *)(param_1 + 0x59) - (uint)*(byte *)(param_1 + 0x5a)) >>
                       1);
  DAT_801f83f7 = -(DAT_801f83f5 + *(char *)(param_1 + 0x5a));
  *(undefined **)(param_1 + 0x3c) = &DAT_801f83f4;
  *(undefined1 *)(param_1 + 0x44) = 1;
  Enemy_CheckWeaponHits();
  return;
}


// ---- 801dfbcc FUN_801dfbcc

bool FUN_801dfbcc(int param_1)

{
  int iVar1;
  
  *(undefined **)(param_1 + 0x3c) = &DAT_801f83f0;
  *(undefined1 *)(param_1 + 0x44) = 7;
  iVar1 = Enemy_CheckWeaponHits();
  if (iVar1 == 1) {
    *(undefined1 *)(param_1 + 2) = 4;
    *(undefined1 *)(param_1 + 3) = 0;
  }
  return iVar1 == 1;
}


// ---- 801dfc24 FUN_801dfc24

undefined1 * FUN_801dfc24(int param_1,undefined1 param_2,char param_3,char param_4)

{
  undefined1 uVar1;
  short sVar2;
  undefined1 *puVar3;
  
                    /* Possible PsyQ macro: setPolyGT3() */
  puVar3 = (undefined1 *)Obj_AllocType3();
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 1;
    puVar3[6] = 0x1e;
    puVar3[7] = param_2;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar2 = (short)param_3;
    }
    else {
      sVar2 = -(short)param_3;
    }
    *(short *)(puVar3 + 0xe) = *(short *)(param_1 + 0xe) + sVar2;
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
    *(short *)(puVar3 + 0x12) = (short)param_4 + *(short *)(param_1 + 0x12);
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    puVar3[0x3b] = param_3;
    puVar3[0x3c] = param_4;
    *(int *)(puVar3 + 0x1c) = param_1;
    puVar3[0x25] = uVar1;
  }
  return puVar3;
}


