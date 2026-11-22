// ID 41, STAGE07.BIN, handler 0x801D9470. Ghidra output with the object struct applied; not matching C.
// ---- 801d9470 FUN_801d9470

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9470(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  obj->invuln = 0;
  (*(code *)(&PTR_FUN_801e08c4)[obj->state])();
  if (obj->active == 0) {
    return;
  }
  if (((obj->var & 0x7f) == 0) || (obj->var == 4)) {
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 != '\0') goto LAB_801d9530;
    if ((obj->var & 0x7f) == 0) {
      Obj_FreeDespawn(obj);
      return;
    }
  }
  else {
    iVar2 = FUN_801da324(obj);
                    /* Possible PsyQ macro: setLineF2() */
    if (iVar2 != 0) {
LAB_801d9530:
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


// ---- 801d9560 FUN_801d9560

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9560(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  
                    /* Probable PsyQ macro: setTile16() */
  Enemy_InitFromTable();
  obj->field_0x43 = 0;
  obj->flip = 0;
  obj->state = 1;
  obj->sub3 = 0;
  if ((obj->var & 0x7f) == 0) {
    obj->draw_list = 6;
                    /* Possible PsyQ macro: setPolyF4() */
    obj->hitbox = &DAT_801e0870;
    obj->box2 = &DAT_801e0890;
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
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x41;
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
      obj->hitbox = &DAT_801e0874;
      obj->box2 = &DAT_801e0898;
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


// ---- 801d972c FUN_801d972c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d972c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e08d0)[obj->var & 0x7f])();
  return;
}


// ---- 801d976c FUN_801d976c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d976c(MM8Obj *obj)

{
  char cVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_FUN_801e08e4;
  if ((obj->var & 0x80) != 0) {
    ppuVar2 = &PTR_FUN_801e08e8;
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
                    /* Probable PsyQ macro: setTile() */
  return;
}


// ---- 801d9830 FUN_801d9830

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9830(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
                    /* Probable PsyQ macro: setTile16() */
  switch(obj->sub2) {
  case 0:
    iVar3 = (int)DAT_8015e248._2_2_ - (int)obj->x;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
                    /* Possible PsyQ macro: setTile8() */
    if (((iVar3 < 0x20) && (obj->y < DAT_8015e24c._2_2_)) && (iVar3 = FUN_801da324(obj), iVar3 == 0)
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
        goto LAB_801d99bc;
      }
      Anim_Set(obj,1);
    }
    goto LAB_801d99c0;
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
LAB_801d99bc:
      obj->sub2 = bVar1;
    }
LAB_801d99c0:
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


// ---- 801d9a10 FUN_801d9a10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9a10(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
  switch(obj->sub2) {
  case 0:
    iVar3 = FUN_801da324(obj);
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
        iVar3 = FUN_801da49c(obj,1);
        if (iVar3 == 0) {
          obj->speed_x = 0;
        }
        FUN_80104d00(obj);
        obj->box2 = &DAT_801e0890;
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
        goto LAB_801d9bfc;
      }
      Anim_Set(obj,1);
    }
    goto LAB_801d9c00;
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
LAB_801d9bfc:
      obj->sub2 = bVar1;
    }
LAB_801d9c00:
    Anim_Step(obj);
    break;
  case 4:
    sVar2 = *(short *)&obj->field_0x54 + -1;
    *(short *)&obj->field_0x54 = sVar2;
                    /* Possible PsyQ macro: setPolyF4() */
    if (sVar2 == -1) {
      Anim_Set(obj,0x11);
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801d9c50 FUN_801d9c50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9c50(MM8Obj *obj)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_801da324();
  if (iVar1 != 0) {
    obj->clut = *(byte *)(iVar1 + 0x24);
    uVar2 = *(undefined4 *)(iVar1 + 0xc);
    obj->x_frac = (short)uVar2;
    obj->x = (short)((uint)uVar2 >> 0x10);
  }
  return;
}


// ---- 801d9c9c FUN_801d9c9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9c9c(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_801da324();
  if (iVar2 != 0) {
    obj->clut = *(byte *)(iVar2 + 0x24);
                    /* Probable PsyQ macro: setTile16() */
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


// ---- 801d9d48 FUN_801d9d48

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9d48(MM8Obj *obj)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_801da324();
  if (iVar1 != 0) {
    obj->clut = *(byte *)(iVar1 + 0x24);
    uVar2 = *(undefined4 *)(iVar1 + 0xc);
    obj->x_frac = (short)uVar2;
    obj->x = (short)((uint)uVar2 >> 0x10);
  }
  return;
}


// ---- 801d9d94 FUN_801d9d94

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9d94(MM8Obj *obj)

{
  char cVar1;
  
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801e08ec)[obj->sub2])();
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


// ---- 801d9ee8 FUN_801d9ee8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ee8(MM8Obj *obj)

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
      obj->hitbox = &DAT_801e088c;
      obj->box2 = &DAT_801e08bc;
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
                    /* Possible PsyQ macro: setPolyF4() */
      obj->hitbox = &DAT_801e0874 + (uint)obj->anim_extra * 4;
      obj->box2 = &DAT_801e0898 + (uint)obj->anim_extra * 5;
      if (((int)(short)obj->frame & 0x8000U) != 0) {
        Anim_Set(obj,0xc);
        obj->hitbox = &DAT_801e0888;
        obj->box2 = &DAT_801e08b4;
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
        obj->sub3 = 0;
        *(undefined2 *)&obj->field_0x54 = 0x78;
      }
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801da07c FUN_801da07c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da07c(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  
  bVar1 = obj->sub3;
  if (bVar1 == 1) {
LAB_801da0e8:
    iVar4 = FUN_801da3e0(obj);
    if (iVar4 == 0) goto LAB_801da170;
    obj->sub3 = 2;
    sVar2 = 0x78;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) goto LAB_801da170;
      Anim_Set(obj,4);
      obj->sub3 = 1;
      obj->field_0x56 = 0;
      FUN_801da440(obj);
      goto LAB_801da0e8;
    }
    if (bVar1 != 2) goto LAB_801da170;
    if (DAT_8015e2a3 == '\0') {
      obj->sub2 = 2;
      obj->sub3 = 0;
      goto LAB_801da170;
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
LAB_801da170:
                    /* Possible PsyQ macro: setPolyGT3() */
  uVar3 = *(short *)&obj->field_0x54 - 1;
  *(ushort *)&obj->field_0x54 = uVar3;
  if ((int)((uint)uVar3 << 0x10) < 1) {
    obj->sub2 = 2;
    obj->sub3 = 0;
  }
                    /* Probable PsyQ macro: setLineF2() */
  return;
}


// ---- 801da324 FUN_801da324

char * FUN_801da324(int param_1)

{
  char *pcVar1;
  
  if (((*(byte *)(param_1 + 7) & 0x7f) == 0) && (*(char *)(param_1 + 0x58) == '\0')) {
    return (char *)0x0;
  }
  pcVar1 = *(char **)(param_1 + 0x50);
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


// ---- 801da3e0 FUN_801da3e0

undefined4 FUN_801da3e0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((g_player != '\0') || (uVar1 = 0, DAT_8015e27f == '\0')) {
    iVar2 = Obj_HitboxOverlap(&g_player,param_1);
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = FUN_80111bb0();
    }
  }
  return uVar1;
}


// ---- 801da440 FUN_801da440

void FUN_801da440(int param_1)

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
                    /* Possible PsyQ macro: setPolyF3() */
  return;
}


// ---- 801da49c FUN_801da49c

undefined4 FUN_801da49c(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar4 = *(char **)(param_1 + 0x38);
  iVar5 = (int)pcVar4[2] + (uint)*(ushort *)(param_1 + 0xe);
  if (*(char *)(param_1 + 0x57) == '\0') {
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


