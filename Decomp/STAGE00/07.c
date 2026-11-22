// ID 07, STAGE00.BIN, handler 0x801DC84C. Ghidra output with the object struct applied; not matching C.
// ---- 801dc84c FUN_801dc84c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc84c(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  obj->clut = (&DAT_80159f64)[obj->bank];
  if (obj->state != 0) {
    FUN_801dd340();
  }
  (*(code *)(&PTR_FUN_801e2818)[obj->state])(obj);
  if (obj->active != 0) {
    if (obj->state != 0) {
      if ((obj->field_0x33 & 0x80) == 0) {
        if ((obj->state != 7) && (obj->speed_y_up == 0)) {
          obj->speed_y_up = 0;
          if (obj->var == 0) {
            iVar1 = 0x4000;
          }
          else {
            iVar1 = 0x3000;
          }
          obj->gravity = iVar1;
        }
        obj->field_0x43 = 1;
      }
      else {
        obj->speed_y_up = 0;
        obj->gravity = 0;
        obj->field_0x43 = 0;
      }
    }
    iVar1 = *(int *)&obj->x_frac;
    *(int *)&obj->field_0x58 = obj->speed_x;
    Obj_ApplySpeed(obj);
    FUN_80106214(obj);
    iVar3 = -0x40000;
    if (obj->var == 0) {
      iVar2 = obj->speed_y_up;
      iVar3 = -0x60000;
    }
    else {
      iVar2 = obj->speed_y_up;
    }
    if (iVar2 < iVar3) {
      obj->speed_y_up = iVar3;
      obj->gravity = 0;
    }
    iVar1 = *(int *)&obj->x_frac - iVar1;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    *(short *)&obj->field_0x54 = *(short *)&obj->field_0x54 + (short)((uint)iVar1 >> 8);
    obj->dmg_table = obj->field_0x5d;
    obj->hitbox = &UNK_801e27a8 + (uint)(byte)(&DAT_801e27f8)[obj->frame & 0x7fff] * 4;
    Enemy_ContactDamage(obj);
    obj->hitbox = &DAT_801e27a4;
    Enemy_ContactDamage(obj);
    Obj_CullAndQueueDraw(obj);
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801dca28 FUN_801dca28

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dca28(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  
  Enemy_InitFromTable();
  obj->draw_list = 6;
  obj->box2 = &DAT_801e279c;
  obj->invuln = 0;
  obj->hitbox = &DAT_801e27a4;
  obj->field_0x53 = 0;
  obj->field_0x5c = 0;
  obj->field_0x5d = obj->dmg_table;
  Anim_Set(obj,0);
  if (obj->var == 1) {
    FUN_8010910c(obj);
    puVar2 = (undefined1 *)FUN_80105628();
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 3;
      puVar2[7] = 0;
      bVar1 = obj->flip;
      puVar2[0x46] = 1;
      *(MM8Obj **)(puVar2 + 0x54) = obj;
      puVar2[0x25] = bVar1;
      obj->state = 7;
      obj->field_0x52 = 10;
    }
  }
  else {
                    /* Probable PsyQ macro: setPolyGT4() */
    obj->field_0x52 = 0x3c;
    puVar2 = (undefined1 *)FUN_80105628();
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 3;
      puVar2[7] = 0;
      bVar1 = obj->flip;
      puVar2[0x46] = 1;
      *(MM8Obj **)(puVar2 + 0x54) = obj;
                    /* Probable PsyQ macro: setLineF2() */
      puVar2[0x25] = bVar1;
      obj->state = 1;
      if ((obj->var & 2) == 0) {
        FUN_8010910c(obj);
                    /* Possible PsyQ macro: setLineF2() */
        obj->sub2 = 0;
        goto LAB_801dcb48;
      }
      obj->flip = (obj->var & 1) << 6;
      obj->var = 0;
    }
  }
  obj->sub2 = 0;
LAB_801dcb48:
  obj->sub3 = 0;
  return;
}


// ---- 801dcb60 FUN_801dcb60

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcb60(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  FUN_801dd6e4();
  if (obj->field_0x53 == '\0') {
    cVar2 = obj->field_0x52;
    obj->field_0x52 = cVar2 + -1;
    if ((cVar2 != '\0') || (cVar2 = FUN_801dd2dc(obj,0x60), cVar2 == '\0')) goto LAB_801dcbd0;
    Anim_Set(obj,3);
    bVar1 = 5;
  }
  else {
    Anim_Set(obj,1);
    bVar1 = 2;
  }
  obj->state = bVar1;
LAB_801dcbd0:
  Anim_Step(obj);
  return;
}


// ---- 801dcbec FUN_801dcbec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcbec(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  
  FUN_801dd6e4();
  if ((obj->field_0x53 & 0x80) == 0) {
    if (obj->field_0x53 == '\0') {
      Anim_Set(obj,5);
      obj->state = 3;
    }
  }
  else {
    cVar1 = obj->field_0x52;
    obj->field_0x52 = cVar1 + -1;
    if (cVar1 == '\0') {
      if ((obj->flip & 0x40) == 0) {
        uVar2 = (uint)(byte)obj->field_0x51;
      }
      else {
        uVar2 = (byte)obj->field_0x51 ^ 1;
      }
      Anim_Set(obj,uVar2 + 6);
      *(undefined2 *)&obj->field_0x54 = 0;
      obj->state = 6;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x53 = 0;
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801dccb8 FUN_801dccb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dccb8(MM8Obj *obj)

{
  FUN_801dd6e4();
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,0);
    obj->state = 1;
    obj->field_0x52 = 0x3c;
  }
  if (obj->field_0x53 != '\0') {
    Anim_SetAtStep(obj,1,obj->anim_extra);
    obj->state = 2;
  }
  Anim_Step(obj);
  return;
}


// ---- 801dcd44 FUN_801dcd44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcd44(MM8Obj *obj)

{
  if ((obj->field_0x33 & 0x80) != 0) {
    FUN_8010544c(obj,0x57);
    if (obj->field_0x42 == '=') {
      FUN_80108e84(obj);
      FUN_8012a5fc(obj,0);
      Obj_FreeDespawn(obj);
      return;
    }
    *(undefined2 *)&obj->field_0x54 = 0;
    obj->state = 6;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->accel_x = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801dcdd4 FUN_801dcdd4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcdd4(MM8Obj *obj)

{
  FUN_801dd6e4();
  if (obj->sub2 == 0) {
    if (obj->field_0x53 == '\0') {
      if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
        Anim_Set(obj,0);
        obj->state = 1;
        obj->sub2 = 0;
        obj->sub3 = 0;
        obj->field_0x52 = 0x3c;
      }
    }
    else {
      Anim_SetAtStep(obj,3,obj->anim_extra);
      obj->sub2 = 1;
    }
  }
  else if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,1);
    obj->state = 2;
    obj->sub2 = 0;
    obj->sub3 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801dceb8 FUN_801dceb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dceb8(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (obj->field_0x41 == '=') {
    FUN_8010544c(obj,0x57);
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    Obj_FreeDespawn(obj);
    return;
  }
  uVar3 = (uint)(byte)obj->field_0x42;
  if (uVar3 == 0x3c) {
    cVar1 = FUN_801dd828(obj);
    if (cVar1 != '\0') {
      obj->field_0x42 = cVar1;
    }
    uVar3 = (uint)(byte)obj->field_0x42;
  }
  if (uVar3 < 0x3e) {
                    /* WARNING: Could not recover jumptable at 0x801dcf58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&PTR_LAB_801d8048)[uVar3])();
    return;
  }
  iVar2 = obj->speed_x;
  if (iVar2 == 0) goto LAB_801dd0a8;
  if (iVar2 < 1) {
code_r0x801dd06c:
    if ((-1 < iVar2) || (uVar4 = 6, obj->field_0x51 == '\x01')) goto LAB_801dd0a8;
    obj->field_0x51 = 1;
    if ((obj->flip & 0x40) == 0) {
      uVar4 = 7;
    }
  }
  else {
    uVar4 = 7;
    if (obj->field_0x51 == '\0') {
      iVar2 = obj->speed_x;
      goto code_r0x801dd06c;
    }
    obj->field_0x51 = 0;
    if ((obj->flip & 0x40) == 0) {
      uVar4 = 6;
    }
  }
  Anim_SetAtStep(obj,uVar4,obj->anim_extra);
LAB_801dd0a8:
  iVar2 = (int)((uint)*(ushort *)&obj->field_0x54 << 0x10) >> 0x1a;
  Anim_StepN(obj,iVar2);
  if ((((int)(short)obj->frame & 0x8000U) != 0) && (iVar2 != 0)) {
    FUN_8010544c(obj,0x56);
  }
  *(ushort *)&obj->field_0x54 = *(ushort *)&obj->field_0x54 & 0x3ff;
  return;
}


// ---- 801dd10c FUN_801dd10c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd10c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    cVar1 = obj->field_0x52;
    obj->field_0x52 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->field_0x52 = 10;
      if (obj->field_0x53 == '\0') {
        bVar2 = obj->sub3 + 1;
        obj->sub3 = bVar2;
        if (1 < bVar2) {
          obj->sub3 = 0;
          obj->flip = obj->flip ^ 0x40;
        }
      }
      else {
        obj->field_0x53 = 0;
      }
      if ((obj->flip & 0x40) == 0) {
        obj->speed_x = 0x20000;
        iVar3 = -0x800;
      }
      else {
        obj->speed_x = -0x20000;
        iVar3 = 0x800;
      }
      obj->accel_x = iVar3;
      obj->sub2 = 1;
    }
  }
  else {
    if ((*(uint *)&obj->field_0x58 & 0x80000000) != (obj->speed_x & 0x80000000U)) {
      obj->speed_x = 0;
      obj->accel_x = 0;
    }
    if (obj->speed_x == 0) {
      obj->sub2 = 0;
    }
  }
  Anim_Step(obj);
  FUN_801dd6e4(obj);
  return;
}


// ---- 801dd220 FUN_801dd220

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd220(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = obj->field_0x42;
  if (bVar2 == 0x3c) {
    cVar1 = FUN_801dd828();
    if (cVar1 != '\0') {
      obj->field_0x42 = cVar1;
    }
    bVar2 = obj->field_0x42;
  }
  if (0xf < bVar2) {
    if (bVar2 < 0x1c) {
      *(undefined2 *)&obj->field_0x54 = 0;
      obj->state = 6;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->accel_x = 0;
    }
    else if (bVar2 == 0x3d) {
      FUN_80108e84(obj);
      FUN_8012a5fc(obj,0);
      Obj_FreeDespawn(obj);
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801dd2dc FUN_801dd2dc

bool FUN_801dd2dc(int param_1,short param_2)

{
  short sVar1;
  
  if (*(char *)(param_1 + 0x25) == '\0') {
    sVar1 = *(short *)(param_1 + 0xe) - DAT_8015e248._2_2_;
  }
  else {
    sVar1 = DAT_8015e248._2_2_ - *(short *)(param_1 + 0xe);
  }
  return -1 < sVar1 && sVar1 <= param_2;
}


// ---- 801dd340 FUN_801dd340

void FUN_801dd340(int param_1)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  *(undefined1 *)(param_1 + 0x44) = 5;
  *(undefined **)(param_1 + 0x3c) = &DAT_801e27a4;
  iVar6 = Enemy_CheckWeaponHits();
  if ((((iVar6 == 3) && (cVar4 = *(char *)(param_1 + 1), cVar4 != '\x06')) && (cVar4 != '\x04')) &&
     (cVar4 != '\b')) {
    iVar6 = 2;
    uVar7 = FUN_80108d78(param_1,DAT_8016d404);
    if ((uVar7 & 0x20) != 0) {
      iVar6 = 1;
    }
    if (1 < DAT_80158f5c) {
      uVar7 = iVar6 + 0xff;
      if (*(char *)(param_1 + 7) != '\0') {
        *(char *)(param_1 + 0x51) = (char)uVar7;
        if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
          uVar7 = (uint)*(byte *)(param_1 + 0x51);
        }
        else {
          uVar7 = (uVar7 ^ 1) & 0xff;
        }
        Anim_Set(param_1,uVar7 + 6);
        *(undefined1 *)(param_1 + 1) = 8;
        *(undefined1 *)(param_1 + 2) = 0;
        *(undefined1 *)(param_1 + 3) = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x1c) = 0;
        return;
      }
      *(char *)(param_1 + 0x51) = (char)uVar7;
      if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
        uVar7 = (uint)*(byte *)(param_1 + 0x51);
      }
      else {
        uVar7 = (uVar7 ^ 1) & 0xff;
      }
      Anim_Set(param_1,uVar7 + 6);
      *(undefined1 *)(param_1 + 1) = 6;
      *(undefined2 *)(param_1 + 0x54) = 0;
      *(undefined1 *)(param_1 + 2) = 0;
      *(undefined1 *)(param_1 + 3) = 0;
      *(int *)(param_1 + 0x14) = (iVar6 * -2 + 3) * 0x10000;
      goto LAB_801dd5ec;
    }
    if (*(char *)(param_1 + 7) != '\0') goto LAB_801dd66c;
    sVar5 = *(short *)(param_1 + 0xe);
    *(char *)(param_1 + 0x51) = (char)iVar6 + -1;
    if (sVar5 < 0) {
      sVar5 = -sVar5;
    }
    *(short *)(param_1 + 0x56) = sVar5;
    iVar8 = iVar6 * -2 + 3;
    if (DAT_80158f5c == 0) {
      iVar8 = iVar8 * 0xc000;
    }
    else {
      iVar8 = iVar8 * 0x10000;
    }
    *(int *)(param_1 + 0x14) = iVar8;
    *(byte *)(param_1 + 0x53) = *(byte *)(param_1 + 0x53) | 1;
    bVar2 = DAT_80158f5c;
    *(int *)(param_1 + 0x1c) = iVar6 * 0x800 + -0xc00;
    *(byte *)(param_1 + 0x5c) = bVar2;
  }
  if (*(char *)(param_1 + 7) != '\0') goto LAB_801dd66c;
  cVar4 = '\0';
  if (*(char *)(param_1 + 0x53) == '\0') {
code_r0x801dd664:
    if (cVar4 == '\0') {
      return;
    }
LAB_801dd66c:
    if (((*(char *)(param_1 + 0x53) == '\0') && (*(char *)(param_1 + 1) == '\a')) &&
       ((*(byte *)(param_1 + 0x33) & 0x30) != 0)) {
      *(undefined1 *)(param_1 + 0x53) = 1;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined1 *)(param_1 + 2) = 0;
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 0x52) = 10;
      *(byte *)(param_1 + 0x25) = *(byte *)(param_1 + 0x25) ^ 0x40;
    }
    return;
  }
  if ((*(byte *)(param_1 + 0x33) & 0x80) == 0) {
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      uVar7 = (uint)*(byte *)(param_1 + 0x51);
    }
    else {
      uVar7 = *(byte *)(param_1 + 0x51) ^ 1;
    }
    Anim_Set(param_1,uVar7 + 6);
    uVar3 = 4;
  }
  else {
    if (*(char *)(param_1 + 0x42) == '=') {
      if (*(char *)(param_1 + 0x53) == '\x01') {
        iVar6 = (int)*(short *)(param_1 + 0xe) - (uint)*(ushort *)(param_1 + 0x56);
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        if (*(char *)(param_1 + 0x5c) == '\0') {
          bVar1 = iVar6 < 8;
        }
        else {
          bVar1 = iVar6 < 0x18;
        }
        if ((!bVar1) || ((*(byte *)(param_1 + 0x33) & 0x30) != 0)) {
          *(undefined4 *)(param_1 + 0x14) = 0;
          *(undefined4 *)(param_1 + 0x1c) = 0;
          *(undefined1 *)(param_1 + 0x53) = 0;
        }
      }
      cVar4 = *(char *)(param_1 + 7);
      goto code_r0x801dd664;
    }
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      uVar7 = (uint)*(byte *)(param_1 + 0x51);
    }
    else {
      uVar7 = *(byte *)(param_1 + 0x51) ^ 1;
    }
    Anim_Set(param_1,uVar7 + 6);
    uVar3 = 6;
    *(undefined2 *)(param_1 + 0x54) = 0;
  }
  *(undefined1 *)(param_1 + 1) = uVar3;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
LAB_801dd5ec:
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x53) = 0;
  return;
}


// ---- 801dd6e4 FUN_801dd6e4

void FUN_801dd6e4(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x44) = *(undefined1 *)(param_1 + 0x5d);
  *(undefined **)(param_1 + 0x3c) =
       &UNK_801e27d0 + (uint)(byte)(&DAT_801e27f8)[*(ushort *)(param_1 + 0x2e) & 0x7fff] * 4;
  bVar1 = Enemy_CheckWeaponHits();
  uVar2 = FUN_80108d78(param_1,DAT_8016d404);
  iVar3 = 2;
  if ((uVar2 & 0x20) != 0) {
    iVar3 = 1;
  }
  if (*(char *)(param_1 + 7) == '\0') {
    if (bVar1 != 0) {
      *(char *)(param_1 + 0x51) = (char)iVar3 + -1;
      *(int *)(param_1 + 0x14) = (iVar3 * -2 + 3) * 0x10000;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined1 *)(param_1 + 0x52) = 10;
      *(undefined1 *)(param_1 + 0x24) = 0;
      *(byte *)(param_1 + 0x53) = *(byte *)(param_1 + 0x53) | 0x80;
    }
  }
  else if ((bVar1 == 2) || ((2 < bVar1 && (bVar1 == 4)))) {
    *(char *)(param_1 + 0x51) = (char)(iVar3 + 0xffU);
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      uVar2 = (uint)*(byte *)(param_1 + 0x51);
    }
    else {
      uVar2 = (iVar3 + 0xffU ^ 1) & 0xff;
    }
    Anim_Set(param_1,uVar2 + 6);
    *(undefined1 *)(param_1 + 1) = 8;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}


// ---- 801dd828 FUN_801dd828

char FUN_801dd828(int param_1)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  pcVar3 = *(char **)(param_1 + 0x38);
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    sVar2 = (short)pcVar3[2];
  }
  else {
    sVar2 = -(short)pcVar3[2];
  }
  if ((*(byte *)(param_1 + 0x25) & 0x80) == 0) {
    iVar4 = (int)pcVar3[3];
  }
  else {
    iVar4 = -(int)pcVar3[3];
  }
  iVar5 = (int)(short)(*(short *)(param_1 + 0xe) + sVar2);
  iVar4 = ((*(short *)(param_1 + 0x12) + iVar4) * 0x10000 >> 0x10) + -8;
  cVar1 = FUN_80107204(iVar5 - *pcVar3,iVar4 + pcVar3[1]);
  if (cVar1 == '\0') {
    cVar1 = FUN_80107204(iVar5 + *pcVar3,iVar4 + pcVar3[1]);
    if (cVar1 == '\0') {
      cVar1 = '\0';
    }
  }
  return cVar1;
}


