// T2_1B, STAGE05.BIN, handler 0x801E4800. Ghidra output with the object struct applied; not matching C.
// ---- 801e4800 FUN_801e4800

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4800(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  
                    /* Possible PsyQ macro: setPolyGT3() */
  bVar1 = obj->var;
  if ((bVar1 & 3) == 3) {
    if ((bVar1 & 0x80) == 0) {
      switchD_801e5160::caseD_4(obj);
    }
    else {
      FUN_801e5428(obj);
    }
    if (obj->active != 0) {
      pcVar3 = *(char **)&obj->target_prio;
      if (((*pcVar3 == '\0') || (pcVar3[6] != '\x1b')) || (*(MM8Obj **)(pcVar3 + 0x48) != obj)) {
        Obj_Free(obj);
      }
      else {
        Obj_CullAndQueueDraw(obj);
      }
    }
  }
  else {
    if ((bVar1 & 0x80) == 0) {
      FUN_801e4928(obj);
    }
    else {
      FUN_801e4fd4(obj);
    }
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
    if (((obj->active != 0) && (Obj_CullAndQueueDraw(obj), (obj->var & 0x80) != 0)) &&
       (cVar2 = Obj_InActiveArea(obj), cVar2 == '\0')) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801e4928 FUN_801e4928

void FUN_801e4928(int param_1)

{
  (*(code *)(&PTR_FUN_801ea8d4)[*(byte *)(param_1 + 1)])();
  return;
}


// ---- 801e4964 FUN_801e4964

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4964(MM8Obj *obj)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
  obj->bank = 0x53;
  obj->vram_base = DAT_801703ee;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->draw_list = 6;
  obj->field_0x43 = 1;
  obj->clut = bVar1;
  if (((int)(uint)DAT_801b29a4 >> (obj->var & 0x1f) & 1U) == 0) {
    puVar4 = (undefined1 *)FUN_80105734();
    if (puVar4 != (undefined1 *)0x0) {
      puVar4[6] = 0x1b;
      *puVar4 = 1;
      puVar4[7] = 3;
      puVar4[1] = 0;
      *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&obj->x_frac;
      uVar5 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar4 + 0x48) = obj;
      *(undefined4 *)(puVar4 + 0x10) = uVar5;
      *(undefined1 **)&obj->target_prio = puVar4;
      Anim_Set(obj,6);
      uVar2 = *(undefined1 *)&obj->y;
      uVar3 = *(undefined1 *)((int)&obj->y + 1);
      obj->speed_y_up = -0x4000;
      obj->state = 1;
      obj->field_0x4e = 0;
      obj->field_0x33 = 0;
      obj->gravity = -0x400;
      obj->invuln = uVar2;
      obj->hp = uVar3;
    }
  }
  else {
    Obj_Free(obj);
  }
  obj->hitbox = &DAT_801ea8c0;
  obj->box2 = &DAT_801ea8cc;
  return;
}


// ---- 801e4a90 FUN_801e4a90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4a90(MM8Obj *obj)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint unaff_s4;
  
  iVar6 = FUN_801e5240();
  if (iVar6 != 0) {
    obj->state = 2;
    obj->sub2 = 0;
    return;
  }
  bVar3 = false;
  obj->hitbox = &DAT_801ea8c0;
  iVar6 = FUN_801e51b0(obj);
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
  if (iVar6 == 0) {
LAB_801e4c04:
    uVar8 = 0;
    do {
      uVar1._0_1_ = obj->invuln;
      uVar1._1_1_ = obj->hp;
      cVar4 = FUN_80107204((int)obj->x,(int)((uVar1 + uVar8) * 0x10000) >> 0x10);
      if (cVar4 != '\0') {
        cVar4 = FUN_80107204((int)obj->x,
                             (int)((((uint)(ushort)obj->y + (char)obj->box2[3] + -1) -
                                   (int)(char)obj->box2[1]) * 0x10000) >> 0x10);
        bVar3 = true;
        if (cVar4 == '\0') {
          sVar5 = obj->y + -1;
          obj->y = sVar5;
          *(short *)&obj->invuln = sVar5;
        }
        obj->speed_y_up = 0;
        obj->gravity = 0;
        break;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x48);
    if (!bVar3) {
      uVar2._0_1_ = obj->invuln;
      uVar2._1_1_ = obj->hp;
      cVar4 = FUN_80107204((int)obj->x,(int)((uVar2 + 0x48) * 0x10000) >> 0x10);
      if (cVar4 == '\0') {
        cVar4 = FUN_80107204((int)obj->x,
                             (int)(((int)(char)obj->box2[1] +
                                   (uint)(ushort)obj->y + (char)obj->box2[3] + 1) * 0x10000) >> 0x10
                            );
        bVar3 = true;
        if (cVar4 == '\0') {
          sVar5 = obj->y + 1;
          obj->y = sVar5;
          *(short *)&obj->invuln = sVar5;
        }
        obj->speed_y_up = 0;
        obj->gravity = 0;
      }
      goto LAB_801e4d34;
    }
  }
  else {
    if (*(char *)(iVar6 + 6) == '\x05') {
      cVar4 = FUN_80107204((int)obj->x,
                           (int)((((uint)(ushort)obj->y + (char)obj->box2[3] + -2) -
                                 (int)(char)obj->box2[1]) * 0x10000) >> 0x10);
      bVar3 = true;
      if (cVar4 == '\0') {
        sVar5 = obj->y + -2;
        obj->y = sVar5;
        *(short *)&obj->invuln = sVar5;
      }
    }
    else {
      iVar7 = 0;
      switch(*(char *)(iVar6 + 6)) {
      case '\0':
        break;
      case '\x01':
      case '\x02':
      case '\x03':
      case '\x04':
      case '\n':
      case '\v':
      case '\f':
      case '\r':
        iVar7 = 0x10000;
        break;
      default:
        goto switchD_801e4b78_caseD_5;
      }
      FUN_8010544c(obj,7);
      uVar8 = FUN_80108d78(obj,iVar6);
      if ((uVar8 & 0x20) == 0) {
        if ((uVar8 & 0x10) != 0) {
          iVar7 = obj->speed_x - (iVar7 + 0x10000);
          goto LAB_801e4bd8;
        }
      }
      else {
        iVar7 = iVar7 + 0x10000 + obj->speed_x;
LAB_801e4bd8:
        obj->speed_x = iVar7;
      }
      FUN_801074f0(obj,iVar6,3);
    }
switchD_801e4b78_caseD_5:
    if ((iVar6 == 0) || (*(char *)(iVar6 + 6) != '\x05')) goto LAB_801e4c04;
LAB_801e4d34:
                    /* Possible PsyQ macro: setLineF2() */
    if ((!bVar3) && (obj->gravity == 0)) {
      obj->speed_y_up = -0x4000;
    }
  }
  if (obj->speed_y_up == -0x4000) {
    iVar6 = -0x400;
  }
  else {
    iVar6 = 0x400;
    if (obj->speed_y_up != 0x4000) goto LAB_801e4d74;
  }
  obj->gravity = iVar6;
LAB_801e4d74:
  if (((obj->field_0x33 & 0xc0) == 0) && ((obj->field_0x33 & 0x30) != 0)) {
    obj->accel_x = 0;
    obj->speed_x = -obj->speed_x;
  }
  iVar6 = obj->speed_x;
  if (iVar6 != 0) {
    iVar7 = iVar6;
    if (iVar6 < 0) {
      iVar7 = -iVar6;
    }
    if (0x40000 < iVar7) {
      iVar7 = 0x40000;
      if (iVar6 < 0) {
        iVar7 = -0x40000;
      }
      obj->speed_x = iVar7;
    }
    iVar6 = -0x400;
    uVar8 = obj->speed_x;
    if ((int)uVar8 < 0) {
      iVar6 = 0x400;
      uVar8 = obj->speed_x;
    }
    obj->accel_x = iVar6;
    unaff_s4 = uVar8 & 0x80000000;
  }
  Obj_ApplySpeed(obj);
  FUN_80106214(obj);
  if ((obj->speed_x & 0x80000000U) != unaff_s4) {
    obj->speed_x = 0;
    obj->accel_x = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e4e54 FUN_801e4e54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4e54(MM8Obj *obj)

{
  short sVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char *pcVar4;
  bool bVar5;
  bool bVar6;
  
  pcVar4 = *(char **)&obj->dmg_table;
  if (((*pcVar4 == '\0') || (pcVar4[6] != '\x1b')) ||
     (bVar5 = false, (pcVar4[7] & 0x7fU) != obj->var)) {
    uVar2 = *(undefined1 *)&obj->y;
    uVar3 = *(undefined1 *)((int)&obj->y + 1);
    obj->state = 1;
    obj->invuln = uVar2;
    obj->hp = uVar3;
  }
  else {
    bVar6 = false;
    sVar1 = obj->x;
    if (*(short *)(pcVar4 + 0xe) < sVar1) {
      obj->x = sVar1 + -1;
    }
    else if (sVar1 < *(short *)(pcVar4 + 0xe)) {
      obj->x = sVar1 + 1;
    }
    else {
      bVar5 = true;
    }
    sVar1 = obj->y;
    if (*(short *)(pcVar4 + 0x12) + 0x22 < (int)sVar1) {
      obj->y = sVar1 + -1;
    }
    else if ((int)sVar1 < *(short *)(pcVar4 + 0x12) + 0x22) {
      obj->y = sVar1 + 1;
    }
    else {
      bVar6 = true;
    }
    if ((bVar5) && (bVar6)) {
      DAT_801b29a4 = DAT_801b29a4 | (byte)(1 << (obj->var & 0x1f));
      if ((obj->var & 1) == 0) {
        DAT_801b29a0 = 1;
      }
      else {
        DAT_801b29a3 = 1;
      }
      FUN_8010544c(obj,0xd2);
      Obj_FreeDespawn(obj);
    }
    else {
      Anim_Step(obj);
    }
  }
  return;
}


// ---- 801e4fd4 FUN_801e4fd4

void FUN_801e4fd4(int param_1)

{
  (*(code *)(&PTR_FUN_801ea8e4)[*(byte *)(param_1 + 1)])();
  return;
}


// ---- 801e5010 FUN_801e5010

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5010(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  obj->bank = 0x53;
  obj->vram_base = DAT_801703ee;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->draw_list = 5;
  obj->clut = bVar1;
  Anim_Set(obj,7);
  if (((int)(uint)DAT_801b29a4 >> (obj->var & 0x1f) & 1U) == 0) {
    puVar2 = (undefined1 *)FUN_80105734(obj);
    if (puVar2 != (undefined1 *)0x0) {
      puVar2[6] = 0x1b;
      *puVar2 = 1;
      puVar2[7] = 0x83;
      puVar2[1] = 0;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
      uVar3 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar2 + 0x48) = obj;
      *(undefined4 *)(puVar2 + 0x10) = uVar3;
      *(undefined1 **)&obj->target_prio = puVar2;
      obj->state = 1;
    }
  }
  else {
    Anim_SetAtStep(obj,8,6);
    obj->state = 3;
  }
  obj->hitbox = &DAT_801ea8c8;
  obj->box2 = (byte *)0x0;
  return;
}


// ---- 801e51b0 FUN_801e51b0

char * FUN_801e51b0(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  
                    /* Possible PsyQ macro: setPolyGT4() */
  pcVar2 = &DAT_801b12ac;
  while (((*pcVar2 == '\0' || (pcVar2[0x46] != '\0')) ||
         (iVar1 = Obj_HitboxOverlap(param_1,pcVar2), iVar1 == 0))) {
    pcVar2 = pcVar2 + 0x60;
    if (&DAT_801b1eac <= pcVar2) {
      return (char *)0x0;
    }
  }
  return pcVar2;
}


// ---- 801e5240 FUN_801e5240

undefined4 FUN_801e5240(char *param_1)

{
  int iVar1;
  char *pcVar2;
  byte *pbVar3;
  
  pcVar2 = &DAT_801b1eec;
  pbVar3 = (byte *)((int)&DAT_801b1ef0 + 3);
                    /* Possible PsyQ macro: setPolyGT3() */
  while ((((*pcVar2 == '\0' || (pcVar2 == param_1)) || (pbVar3[-1] != 0x1b)) ||
         (((*pbVar3 & 0x7f) != param_1[7] || (iVar1 = Obj_HitboxOverlap(pcVar2,param_1), iVar1 == 0)
          )))) {
    pcVar2 = pcVar2 + 0x50;
    pbVar3 = pbVar3 + 0x50;
    if (&DAT_801b28ec <= pcVar2) {
      return 0;
    }
  }
  *(char **)(param_1 + 0x44) = pcVar2;
  return 1;
}


// ---- 801e5304 caseD_4

void switchD_801e5160::caseD_4(int param_1)

{
  (*(code *)(&PTR_FUN_801ea8f4)[*(byte *)(param_1 + 1)])();
  return;
}


// ---- 801e5340 FUN_801e5340

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5340(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0x53;
  obj->vram_base = DAT_801703ee;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->draw_list = 6;
  obj->clut = bVar1;
  Anim_Set(obj,5);
  obj->state = 1;
  obj->hitbox = (byte *)0x0;
  obj->box2 = (byte *)0x0;
  return;
}


// ---- 801e53c0 FUN_801e53c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e53c0(MM8Obj *obj)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->target_prio;
  if (((*pcVar2 != '\0') && (pcVar2[6] == '\x1b')) || (*(MM8Obj **)(pcVar2 + 0x48) == obj)) {
    uVar1 = *(undefined4 *)(pcVar2 + 0xc);
    obj->x_frac = (short)uVar1;
    obj->x = (short)((uint)uVar1 >> 0x10);
    uVar1 = *(undefined4 *)(pcVar2 + 0x10);
    obj->y_frac = (short)uVar1;
    obj->y = (short)((uint)uVar1 >> 0x10);
    Anim_Step();
  }
  return;
}


// ---- 801e5428 FUN_801e5428

void FUN_801e5428(int param_1)

{
                    /* Possible PsyQ macro: setPolyFT4() */
  (*(code *)(&PTR_FUN_801ea8fc)[*(byte *)(param_1 + 1)])();
  return;
}


// ---- 801e5464 FUN_801e5464

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5464(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0x53;
  obj->vram_base = DAT_801703ee;
                    /* Possible PsyQ macro: setLineF2() */
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->draw_list = 5;
  obj->clut = bVar1;
  Anim_Set(obj,4);
  obj->state = 1;
                    /* Possible PsyQ macro: setLineF2() */
  obj->hitbox = (byte *)0x0;
  obj->box2 = (byte *)0x0;
  return;
}


// ---- 801e54e4 FUN_801e54e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e54e4(MM8Obj *obj)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->target_prio;
                    /* Possible PsyQ macro: setPolyGT3() + setSemiTrans(polyGT3, 1) */
                    /* Possible PsyQ macro: setLineF2() */
  if (((*pcVar2 != '\0') && (pcVar2[6] == '\x1b')) || (*(MM8Obj **)(pcVar2 + 0x48) == obj)) {
    if (pcVar2[1] == '\x02') {
      Obj_Free();
    }
    else {
      uVar1 = *(undefined4 *)(pcVar2 + 0xc);
      obj->x_frac = (short)uVar1;
      obj->x = (short)((uint)uVar1 >> 0x10);
      uVar1 = *(undefined4 *)(pcVar2 + 0x10);
      obj->y_frac = (short)uVar1;
      obj->y = (short)((uint)uVar1 >> 0x10);
      Anim_Step();
    }
  }
  return;
}


