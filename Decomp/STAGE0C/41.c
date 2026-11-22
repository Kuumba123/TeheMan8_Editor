// ID 41, STAGE0C.BIN, handler 0x801DC3A8. Ghidra output with the object struct applied; not matching C.
// ---- 801dc3a8 FUN_801dc3a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc3a8(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  obj->invuln = 0;
  (*(code *)(&PTR_FUN_801eab10)[obj->state])();
  if (obj->active == 0) {
    return;
  }
  if (((obj->var & 0x7f) == 0) || (obj->var == 4)) {
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 != '\0') goto LAB_801dc468;
    if ((obj->var & 0x7f) == 0) {
      Obj_FreeDespawn(obj);
      return;
    }
  }
  else {
    iVar2 = FUN_801dd25c(obj);
    if (iVar2 != 0) {
LAB_801dc468:
      Obj_CullAndQueueDraw(obj);
      if (obj->var != 4) {
        return;
      }
      obj->invuln = 1;
      return;
    }
  }
  Obj_Free(obj);
  return;
}


// ---- 801dc498 FUN_801dc498

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc498(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  
                    /* Possible PsyQ macro: setLineF2() */
  Enemy_InitFromTable();
  obj->field_0x43 = 0;
  obj->flip = 0;
  obj->state = 1;
  obj->sub3 = 0;
  if ((obj->var & 0x7f) == 0) {
    obj->draw_list = 6;
    obj->hitbox = &DAT_801eaabc;
                    /* Probable PsyQ macro: setTile16() */
    obj->box2 = &DAT_801eaadc;
    obj->field_0x57 = 0;
    obj->field_0x58 = 0;
    *(MM8Obj **)&obj->field_0x50 = obj;
    puVar2 = (undefined1 *)FUN_801055e4(obj);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x41;
      uVar4 = 1;
      if ((obj->var & 0x80) != 0) {
        uVar4 = 2;
      }
      puVar2[7] = uVar4;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
      uVar3 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar2 + 0x50) = obj;
      *(undefined4 *)(puVar2 + 0x10) = uVar3;
    }
    puVar2 = (undefined1 *)FUN_801055e4(obj);
                    /* Possible PsyQ macro: setPolyF3() */
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x41;
                    /* Possible PsyQ macro: setTile16() */
      puVar2[7] = 3;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
      uVar3 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar2 + 0x50) = obj;
      *(undefined4 *)(puVar2 + 0x10) = uVar3;
    }
    Anim_Set(obj,0x11);
    obj->sub2 = 0;
  }
  else {
    bVar1 = obj->var;
    if (bVar1 == 4) {
      obj->draw_list = 7;
      obj->hitbox = &DAT_801eaac0;
      obj->box2 = &DAT_801eaae4;
      Anim_Set(obj,2);
      FUN_8010544c(obj,0x116);
      obj->sub2 = 0;
    }
    else {
      obj->draw_list = 6;
      obj->hitbox = (byte *)0x0;
      obj->box2 = (byte *)0x0;
      obj->invuln = 1;
      obj->sub2 = 0;
      if (bVar1 == 2) {
        Anim_Set(obj,0x12);
        obj->field_0x57 = 0;
      }
      else {
        if ((bVar1 < 3) && (bVar1 == 1)) {
          uVar3 = 0xf;
        }
        else {
          uVar3 = 0x10;
        }
        Anim_Set(obj,uVar3);
      }
    }
  }
  return;
}


// ---- 801dc664 FUN_801dc664

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc664(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eab1c)[obj->var & 0x7f])();
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  return;
}


// ---- 801dc6a4 FUN_801dc6a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc6a4(MM8Obj *obj)

{
  char cVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_FUN_801eab30;
  if ((obj->var & 0x80) != 0) {
    ppuVar2 = &PTR_FUN_801eab34;
  }
  (*(code *)*ppuVar2)(obj);
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    FUN_80108e84(obj);
    FUN_80108fd8(obj,1);
    FUN_8012ae08(obj,0x23);
    Obj_FreeDespawn(obj);
    return;
  }
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801dc768 FUN_801dc768

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc768(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
  switch(obj->sub2) {
  case 0:
    iVar3 = (int)DAT_8015e248._2_2_ - (int)obj->x;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (((iVar3 < 0x20) && (obj->y < DAT_8015e24c._2_2_)) && (iVar3 = FUN_801dd25c(obj), iVar3 == 0)
       ) {
      obj->field_0x56 = 0;
      Anim_Set(obj,1);
      obj->sub2 = 1;
    }
    break;
  case 1:
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->field_0x56 = obj->field_0x56 + '\x01';
      if (2 < (byte)obj->field_0x56) {
        bVar1 = 2;
        goto LAB_801dc8f4;
      }
      Anim_Set(obj,1);
    }
    goto LAB_801dc8f8;
  case 2:
    puVar4 = (undefined1 *)FUN_801055e4(obj);
    if (puVar4 == (undefined1 *)0x0) {
      *(undefined2 *)&obj->field_0x54 = 0x3c;
      obj->sub2 = 4;
    }
    else {
      puVar4[6] = 0x41;
      *puVar4 = 1;
      puVar4[7] = 4;
                    /* Possible PsyQ macro: setLineF2() */
      *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&obj->x_frac;
      uVar5 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar4 + 0x50) = obj;
      *(undefined4 *)(puVar4 + 0x10) = uVar5;
      *(undefined1 **)&obj->field_0x50 = puVar4;
      obj->field_0x58 = 1;
      obj->sub2 = 3;
      Anim_Set(obj,0xd);
    }
    break;
  case 3:
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      *(undefined2 *)&obj->field_0x54 = 0x3c;
      bVar1 = 4;
LAB_801dc8f4:
      obj->sub2 = bVar1;
    }
LAB_801dc8f8:
    Anim_Step(obj);
    break;
  case 4:
    sVar2 = *(short *)&obj->field_0x54 + -1;
    *(short *)&obj->field_0x54 = sVar2;
    if (sVar2 == -1) {
      Anim_Set(obj,0x11);
                    /* Probable PsyQ macro: setTile16() */
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801dc948 FUN_801dc948

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc948(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
  switch(obj->sub2) {
  case 0:
    iVar3 = FUN_801dd25c(obj);
    if (iVar3 == 0) {
      iVar3 = (int)DAT_8015e248._2_2_ - (int)obj->x;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (iVar3 < 0x40) {
        obj->field_0x56 = 0;
        Anim_Set(obj);
        obj->sub2 = 1;
      }
      else {
        if ((int)DAT_8015e248._2_2_ < (int)obj->x) {
          obj->field_0x57 = 0;
          obj->speed_x = -0x18000;
        }
        else {
          obj->field_0x57 = 1;
          obj->speed_x = 0x18000;
        }
        iVar3 = FUN_801dd3d4(obj,1);
        if (iVar3 == 0) {
          obj->speed_x = 0;
        }
        FUN_80104d00(obj);
        obj->box2 = &DAT_801eaadc;
        FUN_80106214(obj);
        if ((obj->field_0x33 & 0x30) != 0) {
          obj->speed_x = 0;
        }
      }
    }
    break;
  case 1:
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->field_0x56 = obj->field_0x56 + '\x01';
      if (2 < (byte)obj->field_0x56) {
        bVar1 = 2;
                    /* Probable PsyQ macro: setPolyGT4() */
        goto LAB_801dcb34;
      }
      Anim_Set(obj,1);
    }
    goto LAB_801dcb38;
  case 2:
    puVar4 = (undefined1 *)FUN_801055e4(obj);
    if (puVar4 == (undefined1 *)0x0) {
      *(undefined2 *)&obj->field_0x54 = 0x3c;
      obj->sub2 = 4;
    }
    else {
                    /* Probable PsyQ macro: setLineF2() */
      puVar4[6] = 0x41;
      *puVar4 = 1;
      puVar4[7] = 4;
      *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&obj->x_frac;
                    /* Possible PsyQ macro: setLineF2() */
      uVar5 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar4 + 0x50) = obj;
      *(undefined4 *)(puVar4 + 0x10) = uVar5;
      *(undefined1 **)&obj->field_0x50 = puVar4;
      obj->field_0x58 = 1;
      obj->sub2 = 3;
      Anim_Set(obj,0xd);
    }
    break;
  case 3:
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      *(undefined2 *)&obj->field_0x54 = 0x3c;
      bVar1 = 4;
LAB_801dcb34:
      obj->sub2 = bVar1;
    }
LAB_801dcb38:
    Anim_Step(obj);
    break;
  case 4:
    sVar2 = *(short *)&obj->field_0x54 + -1;
    *(short *)&obj->field_0x54 = sVar2;
    if (sVar2 == -1) {
      Anim_Set(obj,0x11);
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801dcb88 FUN_801dcb88

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcb88(MM8Obj *obj)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_801dd25c();
  if (iVar1 != 0) {
    obj->clut = *(byte *)(iVar1 + 0x24);
    uVar2 = *(undefined4 *)(iVar1 + 0xc);
    obj->x_frac = (short)uVar2;
    obj->x = (short)((uint)uVar2 >> 0x10);
  }
  return;
}


// ---- 801dcbd4 FUN_801dcbd4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcbd4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
                    /* Possible PsyQ macro: setPolyGT4() */
  iVar2 = FUN_801dd25c();
  if (iVar2 != 0) {
    obj->clut = *(byte *)(iVar2 + 0x24);
    if (obj->field_0x57 != *(char *)(iVar2 + 0x57)) {
      if (*(char *)(iVar2 + 0x57) == '\0') {
        bVar1 = obj->anim_extra;
        uVar4 = 0x12;
      }
      else {
        bVar1 = obj->anim_extra;
        uVar4 = 0;
      }
      Anim_SetAtStep(obj,uVar4,bVar1);
      obj->field_0x57 = *(undefined1 *)(iVar2 + 0x57);
    }
    iVar3._0_2_ = obj->x_frac;
    iVar3._2_2_ = obj->x;
    iVar2 = *(int *)(iVar2 + 0xc);
    if (iVar3 != iVar2) {
      obj->x_frac = (short)iVar2;
      obj->x = (short)((uint)iVar2 >> 0x10);
      Anim_Step(obj);
    }
  }
  return;
}


// ---- 801dcc80 FUN_801dcc80

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcc80(MM8Obj *obj)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_801dd25c();
  if (iVar1 != 0) {
    obj->clut = *(byte *)(iVar1 + 0x24);
    uVar2 = *(undefined4 *)(iVar1 + 0xc);
    obj->x_frac = (short)uVar2;
    obj->x = (short)((uint)uVar2 >> 0x10);
  }
  return;
}


// ---- 801dcccc FUN_801dcccc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcccc(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801eab38)[obj->sub2])();
  if ((obj->active != 0) && (obj->clut = (&DAT_80159f64)[obj->bank], obj->sub2 != 3)) {
    cVar1 = Enemy_CheckWeaponHits(obj);
    if (((cVar1 == '\x02') || (cVar1 == '\x04')) && ((obj->sub2 == 1 && (DAT_80158f5c == '\x04'))))
    {
      Anim_Set(obj,5);
      FUN_8010544c(obj,0x2d);
      obj->field_0x54 = 0x3c;
      obj->sub2 = 3;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
    else if (cVar1 == '\x02') {
      obj->clut = 0;
    }
    else if (cVar1 == '\x04') {
      FUN_8012ae08(obj,0x22);
      if ((DAT_8015e2a3 != '\0') && (obj->sub2 == 1)) {
        FUN_80111c28();
      }
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801dce20 FUN_801dce20

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce20(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = obj->sub3;
  if (bVar1 == 1) {
    Obj_ApplySpeed(obj);
    if (obj->speed_y_up < -0x60000) {
      obj->speed_y_up = -0x60000;
      obj->gravity = 0;
    }
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->hitbox = &DAT_801eaad8;
      obj->box2 = &DAT_801eab08;
      Anim_Set(obj,3);
      FUN_8010544c(obj,0x117);
      obj->speed_y_up = 0;
      obj->gravity = 0;
      obj->sub3 = 2;
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      obj->hitbox = &DAT_801eaac0 + (uint)obj->anim_extra * 4;
      obj->box2 = &DAT_801eaae4 + (uint)obj->anim_extra * 5;
      if (((int)(short)obj->frame & 0x8000U) != 0) {
        Anim_Set(obj,0xc);
        obj->hitbox = &DAT_801eaad4;
        obj->box2 = &DAT_801eab00;
        obj->gravity = 0x4000;
        obj->speed_y_up = 0;
        obj->sub3 = 1;
        obj->y = obj->y + 0x2a;
      }
    }
    else {
      if (bVar1 != 2) {
        return;
      }
      if (((int)(short)obj->frame & 0x8000U) != 0) {
        obj->sub2 = 1;
                    /* Possible PsyQ macro: setPolyGT4() */
        obj->sub3 = 0;
        *(undefined2 *)&obj->field_0x54 = 0x78;
      }
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801dcfb4 FUN_801dcfb4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcfb4(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  
  bVar1 = obj->sub3;
  if (bVar1 == 1) {
LAB_801dd020:
    iVar4 = FUN_801dd318(obj);
    if (iVar4 == 0) goto LAB_801dd0a8;
    obj->sub3 = 2;
    sVar2 = 0x78;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) goto LAB_801dd0a8;
      Anim_Set(obj,4);
      obj->sub3 = 1;
      obj->field_0x56 = 0;
      FUN_801dd378(obj);
      goto LAB_801dd020;
    }
    if (bVar1 != 2) goto LAB_801dd0a8;
    if (DAT_8015e2a3 == '\0') {
      obj->sub2 = 2;
      obj->sub3 = 0;
      goto LAB_801dd0a8;
    }
    bVar1 = FUN_80111858();
    if (bVar1 != 0) {
      FUN_80111c90();
      obj->field_0x56 = obj->field_0x56 ^ 1;
      Anim_SetAtStep(obj,4,obj->field_0x56);
    }
    sVar2 = *(short *)&obj->field_0x54 - (ushort)bVar1;
  }
  *(short *)&obj->field_0x54 = sVar2;
LAB_801dd0a8:
  uVar3 = *(short *)&obj->field_0x54 - 1;
                    /* Possible PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
  *(ushort *)&obj->field_0x54 = uVar3;
  if ((int)((uint)uVar3 << 0x10) < 1) {
    obj->sub2 = 2;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801dd25c FUN_801dd25c

char * FUN_801dd25c(int param_1)

{
  char *pcVar1;
  
  if (((*(byte *)(param_1 + 7) & 0x7f) == 0) && (*(char *)(param_1 + 0x58) == '\0')) {
    return (char *)0x0;
  }
  pcVar1 = *(char **)(param_1 + 0x50);
                    /* Possible PsyQ macro: setLineF2() */
  if (*pcVar1 != '\0') {
    if (pcVar1[6] != 'A') {
      return (char *)0x0;
    }
    if ((*(byte *)(param_1 + 7) & 0x7f) == 0) {
      if (pcVar1[7] != '\x04') {
        return (char *)0x0;
      }
      if (param_1 != *(int *)(pcVar1 + 0x50)) {
        return (char *)0x0;
      }
      return pcVar1;
    }
    if (*(short *)(pcVar1 + 0x12) != *(short *)(param_1 + 0x12)) {
      return (char *)0x0;
    }
    if ((pcVar1[7] & 0x7fU) == 0) {
      return pcVar1;
    }
  }
  return (char *)0x0;
}


// ---- 801dd318 FUN_801dd318

undefined4 FUN_801dd318(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
                    /* Possible PsyQ macro: setLineF2() */
  if ((g_player != '\0') || (uVar1 = 0, DAT_8015e27f == '\0')) {
    iVar2 = Obj_HitboxOverlap(&g_player,param_1);
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = FUN_80111bb0();
    }
  }
  return uVar1;
}


// ---- 801dd378 FUN_801dd378

void FUN_801dd378(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined1 *)Obj_AllocType3();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x2e;
    puVar1[7] = 0;
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    *(int *)(puVar1 + 0x38) = param_1;
    *(undefined4 *)(puVar1 + 0x10) = uVar2;
  }
  return;
}


// ---- 801dd3d4 FUN_801dd3d4

undefined4 FUN_801dd3d4(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar4 = *(char **)(param_1 + 0x38);
  iVar5 = (int)pcVar4[2] + (uint)*(ushort *)(param_1 + 0xe);
  if (*(char *)(param_1 + 0x57) == '\0') {
                    /* Possible PsyQ macro: setLineF2() */
    iVar5 = (iVar5 + -1) - (int)*pcVar4;
    iVar3 = (int)pcVar4[1] + (int)pcVar4[4];
  }
  else {
    iVar5 = (int)*pcVar4 + iVar5 + 1;
    iVar3 = (int)pcVar4[1] + (int)pcVar4[4];
  }
  cVar1 = FUN_80107204(iVar5 * 0x10000 >> 0x10,
                       (int)((((int)pcVar4[3] + (uint)*(ushort *)(param_1 + 0x12)) - iVar3) *
                            0x10000) >> 0x10);
  uVar2 = 0xffffffff;
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  return uVar2;
}


