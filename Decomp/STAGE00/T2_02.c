// T2_02, STAGE00.BIN, handler 0x801DDD0C. Ghidra output with the object struct applied; not matching C.
// ---- 801ddd0c FUN_801ddd0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddd0c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  obj->field_0x4d = obj->field_0x4d + '\x01';
  (*(code *)(&PTR_FUN_801e2880)[obj->state])();
  if ((obj->var == 1) || (obj->var == 3)) {
    if ((DAT_801b29a0 & 0x80) == 0) {
      obj->box2 = &DAT_801e2850;
      FUN_80107bf4(obj,&g_player,1);
      obj->box2 = &DAT_801e2858;
      FUN_80107bf4(obj,&g_player,1);
    }
    cVar1 = FUN_801dea08(obj);
    bVar2 = 6;
    if (cVar1 == '\0') {
      bVar2 = 2;
    }
    obj->draw_list = bVar2;
    obj->hitbox = &DAT_801e2848;
    FUN_8010976c(obj);
    obj->hitbox = &DAT_801e284c;
    FUN_8010976c(obj);
  }
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    bVar2 = obj->var;
    if ((bVar2 == 1) || (bVar2 == 4)) {
      FUN_800fce30(0x59);
      if (obj->var == 4) {
        FUN_800fd100(0x5b);
      }
      DAT_801d2936 = 0;
      bVar2 = obj->var;
    }
    if ((bVar2 == 2) || (obj->var - 4 < 2)) {
      Obj_Free(obj);
    }
    else {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801ddeac FUN_801ddeac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddeac(MM8Obj *obj)

{
  short sVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
  obj->bank = 7;
  obj->vram_base = DAT_80170356;
  bVar2 = DAT_80159f6b;
  obj->box2 = (byte *)0x0;
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->clut = bVar2;
  switch(obj->var) {
  case 0:
    obj->flip = 0;
    obj->draw_list = 8;
    Anim_Set(obj,4);
    obj->hitbox = &DAT_801e2844;
    obj->state = 1;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->box2 = &UNK_801e2870 + (uint)obj->anim_extra * 5;
    return;
  case 1:
    obj->flip = 0;
    obj->draw_list = 2;
    if ((DAT_801b29a0 & 0xf) == 0) {
      Anim_Set(obj,7);
      sVar1 = obj->y;
      obj->state = 2;
      obj->sub2 = 0;
      obj->sub3 = 0;
      *(short *)&obj->target_prio = obj->y;
      obj->y = sVar1 + 0x71;
      *(short *)&obj->field_0x4a = sVar1 + 0x51;
    }
    else {
      Anim_Set(obj,6);
      obj->state = 2;
      obj->sub2 = 2;
      obj->sub3 = 0;
    }
    puVar4 = (undefined1 *)FUN_80105734(obj);
    if (puVar4 == (undefined1 *)0x0) {
      obj->state = 0;
      obj->sub2 = 0;
    }
    else {
      *puVar4 = 1;
      puVar4[6] = 2;
      puVar4[7] = 2;
      puVar4[0x25] = 0;
      *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&obj->x_frac;
      uVar5 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar4 + 0x44) = obj;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[0x4c] = 0;
      *(undefined4 *)(puVar4 + 0x10) = uVar5;
    }
    break;
  case 2:
    uVar5 = 8;
    obj->draw_list = 7;
    if (obj->field_0x4c == '\0') {
      uVar5 = 5;
    }
    goto LAB_801de1b8;
  case 3:
    puVar4 = (undefined1 *)FUN_80105734(obj);
    if (puVar4 == (undefined1 *)0x0) {
      return;
    }
    *puVar4 = 1;
    puVar4[6] = 2;
    puVar4[7] = 2;
    puVar4[0x25] = 0;
    *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&obj->x_frac;
    uVar5 = *(undefined4 *)&obj->y_frac;
    *(MM8Obj **)(puVar4 + 0x44) = obj;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[0x4c] = 1;
    *(undefined4 *)(puVar4 + 0x10) = uVar5;
    puVar3 = (undefined1 *)FUN_80105734(obj);
    if (puVar3 == (undefined1 *)0x0) {
      Obj_Free(puVar4);
      return;
    }
    *puVar3 = 1;
    puVar3[6] = 2;
    puVar3[7] = 5;
    puVar3[0x25] = 0;
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
    uVar5 = *(undefined4 *)&obj->y_frac;
    puVar3[1] = 0;
    puVar3[2] = 0;
    *(undefined4 *)(puVar3 + 0x10) = uVar5;
    obj->sub3 = 0;
    obj->flip = 0;
    obj->draw_list = 2;
    Anim_Set(obj,6);
    obj->state = 2;
    obj->sub2 = 2;
    break;
  case 4:
    puVar4 = (undefined1 *)FUN_80105734(obj);
    if (puVar4 == (undefined1 *)0x0) {
      return;
    }
    *puVar4 = 1;
    puVar4[6] = 2;
    puVar4[7] = 2;
    puVar4[0x25] = 0x40;
    *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&obj->x_frac;
    uVar5 = *(undefined4 *)&obj->y_frac;
    *(MM8Obj **)(puVar4 + 0x44) = obj;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[0x4c] = 0;
    *(undefined4 *)(puVar4 + 0x10) = uVar5;
                    /* Possible PsyQ macro: setLineF2() */
    obj->flip = 0x40;
    obj->draw_list = 2;
    Anim_Set(obj,7);
    sVar1 = obj->y;
    obj->state = 2;
    obj->sub2 = 0;
    obj->sub3 = 0;
    *(short *)&obj->target_prio = obj->y;
    obj->y = sVar1 + 0x71;
    *(short *)&obj->field_0x4a = sVar1 + 0x51;
    return;
  case 5:
    uVar5 = 0xb;
    obj->draw_list = 6;
LAB_801de1b8:
    Anim_Set(obj,uVar5);
    obj->state = 2;
    obj->sub2 = 2;
    break;
  default:
    goto switchD_801ddf1c_default;
  }
  obj->sub3 = 0;
switchD_801ddf1c_default:
  return;
}


// ---- 801de1f0 FUN_801de1f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de1f0(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  obj->box2 = &UNK_801e2870 + (uint)obj->anim_extra * 5;
  bVar1 = FUN_80107bf4(obj,&g_player,5);
  if ((DAT_801b29a0 & 0xf) == 1) {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      FUN_8010544c(obj,0x2b);
      DAT_801b29a0 = DAT_801b29a0 & 0xf0 | 2;
    }
  }
  else if (((DAT_801b29a0 & 0xf) < 2) && ((DAT_801b29a0 & 0xf) == 0)) {
    pcVar3 = &g_main_pool;
    pcVar4 = "";
    while ((((*pcVar3 == '\0' || (pcVar4[5] != '\a')) ||
            (iVar2 = Obj_HitboxOverlap(pcVar3,obj), iVar2 == 0)) || (*pcVar4 != '\x04'))) {
      pcVar3 = pcVar3 + 0x60;
      pcVar4 = pcVar4 + 0x60;
      if (&DAT_8015c974 <= pcVar3) {
LAB_801de310:
        if ((DAT_8015e27c & bVar1) != 0x80) {
          return;
        }
        DAT_801b29a0 = DAT_801b29a0 | 1;
        return;
      }
    }
    DAT_801b29a0 = DAT_801b29a0 | 1;
    goto LAB_801de310;
  }
  Anim_Step(obj);
  return;
}


// ---- 801de3a8 FUN_801de3a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de3a8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e2890)[obj->sub2])();
  return;
}


// ---- 801de3e4 FUN_801de3e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de3e4(MM8Obj *obj)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (((DAT_801b29a0 & 0xf) == 2) &&
     (puVar1 = (undefined1 *)Obj_AllocType3(), puVar1 != (undefined1 *)0x0)) {
    *puVar1 = 1;
    puVar1[6] = 0xe;
    puVar1[7] = 0;
    puVar1[0x26] = 8;
    *(short *)(puVar1 + 0xe) = obj->x + -2;
    *(short *)(puVar1 + 0x12) = obj->y + -0x4b;
    puVar2 = (undefined1 *)Obj_AllocType3();
    if (puVar2 == (undefined1 *)0x0) {
      Obj_Free(puVar1);
    }
    else {
      *puVar2 = 1;
      puVar2[6] = 0xe;
      puVar2[7] = 1;
      puVar2[0x26] = 1;
      *(short *)(puVar2 + 0xe) = obj->x + -2;
      *(short *)(puVar2 + 0x12) = obj->y + -0x4b;
      DAT_801b29a0 = DAT_801b29a0 & 0xf0 | 3;
      obj->sub2 = 1;
      obj->sub3 = 0;
      DAT_801d2936 = 0xfa;
      obj->speed_y_up = 0x8000;
      obj->field_0x4d = 0;
    }
  }
  return;
}


// ---- 801de50c FUN_801de50c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de50c(MM8Obj *obj)

{
  byte bVar1;
  
  FUN_80104d18();
  if ((obj->field_0x4d & 0x1f) == 0x1f) {
    FUN_800fd100(0x59);
  }
  bVar1 = obj->sub3;
  if (bVar1 == 1) {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      Anim_Set(obj,6);
      obj->sub3 = 2;
    }
  }
  else {
    if ((bVar1 < 2) && (bVar1 == 0)) {
      if (*(short *)&obj->field_0x4a < obj->y) {
        return;
      }
      obj->sub3 = 1;
      return;
    }
    if ((obj->y <= *(short *)&obj->target_prio) &&
       (obj->y = *(short *)&obj->target_prio, ((int)(short)obj->frame & 0x8000U) != 0)) {
      FUN_800fce30(0x59);
      FUN_800fd100(0x5b);
      obj->sub2 = 2;
      obj->sub3 = 0;
      DAT_801b29a0 = DAT_801b29a0 & 0xf0 | 4;
    }
  }
  Anim_Step(obj);
  if (obj->var == 1) {
    obj->box2 = &DAT_801e2868;
    FUN_80107bf4(obj,&g_player,1);
  }
  return;
}


// ---- 801de650 FUN_801de650

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de650(MM8Obj *obj)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  byte bVar5;
  
  switch(obj->var) {
  case 1:
  case 3:
    switch(obj->sub3) {
    case 0:
      obj->box2 = &DAT_801e2860;
      iVar1 = FUN_80107d00(obj,&g_player);
      if (iVar1 != 0) {
        obj->sub3 = 1;
      }
      break;
    case 1:
      puVar2 = (undefined1 *)Obj_AllocType4();
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 7;
        bVar5 = obj->var;
        puVar2[1] = 0;
        puVar2[7] = bVar5 != 1;
        bVar5 = 2;
        if (obj->var == 1) {
          bVar5 = 5;
        }
        obj->sub3 = bVar5;
      }
      break;
    case 2:
      if ((DAT_801b29a0 & 0x40) != 0) {
        obj->speed_y_up = 0x8000;
        DAT_801d2936 = 0xfa;
        obj->sub3 = 3;
        obj->field_0x4d = 0;
        *(short *)&obj->field_0x4a = obj->y + -0x30;
      }
      break;
    case 3:
      FUN_80104d18(obj);
      if ((obj->field_0x4d & 0x1f) == 0x1f) {
        FUN_800fd100(0x59);
      }
      if (obj->y <= *(short *)&obj->field_0x4a) {
        obj->sub3 = 4;
        DAT_801b29a0 = DAT_801b29a0 & 0xbf;
      }
      break;
    case 4:
      goto switchD_801de6c0_caseD_4;
    }
    break;
  case 2:
    uVar4 = *(undefined4 *)(*(int *)&obj->dmg_table + 0xc);
    obj->x_frac = (short)uVar4;
    obj->x = (short)((uint)uVar4 >> 0x10);
    uVar4 = *(undefined4 *)(*(int *)&obj->dmg_table + 0x10);
    obj->y_frac = (short)uVar4;
    obj->y = (short)((uint)uVar4 >> 0x10);
    break;
  case 4:
    bVar5 = obj->sub3;
    if (bVar5 == 1) {
      FUN_80104d18(obj);
      if ((obj->field_0x4d & 0x1f) == 0x1f) {
        FUN_800fd100(0x59);
      }
      if (obj->y < *(short *)&obj->target_prio) {
        return;
      }
      DAT_801b29a0 = DAT_801b29a0 & 0xf0 | 0x84;
      obj->sub3 = 2;
      obj->field_0x4d = 0;
      return;
    }
    if (bVar5 < 2) {
      if (bVar5 != 0) {
        return;
      }
      if ((DAT_801b29a0 & 4) == 0) {
        return;
      }
      puVar2 = (undefined1 *)Obj_AllocType3();
      if (puVar2 == (undefined1 *)0x0) {
        return;
      }
      *puVar2 = 1;
      puVar2[6] = 0xe;
      puVar2[7] = 0;
      puVar2[0x26] = 8;
      *(short *)(puVar2 + 0xe) = obj->x + -2;
      *(short *)(puVar2 + 0x12) = obj->y + 0x26;
      puVar3 = (undefined1 *)Obj_AllocType3();
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        puVar3[6] = 0xe;
        puVar3[7] = 1;
        puVar3[0x26] = 1;
        *(short *)(puVar3 + 0xe) = obj->x + -2;
        *(short *)(puVar3 + 0x12) = obj->y + 0x26;
        DAT_801b29a0 = DAT_801b29a0 & 0xf0 | 3;
        obj->speed_y_up = -0x8000;
        obj->sub3 = 1;
        DAT_801d2936 = 0xfa;
        obj->field_0x4d = 0;
        *(short *)&obj->target_prio = obj->y + 0x71;
        return;
      }
      Obj_Free(puVar2);
      return;
    }
    if (bVar5 != 2) {
      return;
    }
switchD_801de6c0_caseD_4:
    FUN_80104d18(obj);
    if ((obj->field_0x4d & 0x1f) == 0x1f) {
      FUN_800fd100(0x59);
    }
  }
  return;
}


// ---- 801de9e8 FUN_801de9e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Possible GS_106.OBJ/GsSetProjection
   Possible _OP_VDEL.OBJ/__builtin_vec_delete
   Possible _OP_VNEW.OBJ/__builtin_vec_new
   Possible SCNOFF.OBJ/SsSetNoiseOff
   Possible SSQUIT.OBJ/SsQuit */

void FUN_801de9e8(MM8Obj *obj)

{
  Obj_Free();
  return;
}


// ---- 801dea08 FUN_801dea08

bool FUN_801dea08(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  char *pcVar6;
  
  pcVar6 = *(char **)(param_1 + 0x38);
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    iVar3 = (int)*(short *)(param_1 + 0xe) + (int)pcVar6[2];
  }
  else {
    iVar3 = (*(short *)(param_1 + 0xe) + -1) - (int)pcVar6[2];
  }
  if ((DAT_8015e261 & 0x40) == 0) {
    uVar2 = (uint)DAT_8015e274[2];
  }
  else {
    uVar2 = ~(int)DAT_8015e274[2];
  }
  iVar3 = ((int)((iVar3 - (uint)DAT_8015e248._2_2_) * 0x10000) >> 0x10) - uVar2;
  sVar5 = (short)iVar3;
  if (iVar3 * 0x10000 < 0) {
    sVar5 = -sVar5;
  }
  bVar1 = false;
  if ((int)sVar5 <= (int)((int)*DAT_8015e274 + (int)*pcVar6 & 0xffffU)) {
    iVar3 = (int)DAT_8015e274[1];
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    iVar4 = (int)pcVar6[1];
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    bVar1 = (int)DAT_8015e24c._2_2_ + (int)DAT_8015e274[3] + iVar3 <=
            ((int)*(short *)(param_1 + 0x12) + (int)pcVar6[3]) - iVar4;
  }
  return bVar1;
}


