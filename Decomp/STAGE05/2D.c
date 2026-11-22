// ID 2D, STAGE05.BIN, handler 0x801D9BBC. Ghidra output with the object struct applied; not matching C.
// ---- 801d9bbc FUN_801d9bbc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9bbc(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_caseD_1_801ea30c)[obj->state])();
  if (obj->active != 0) {
    iVar1 = FUN_80104820(obj,0x280,0x38);
    if (iVar1 == 0) {
      Obj_FreeDespawn(obj);
    }
    else {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801d9c40 caseD_1

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801d9c08::caseD_1(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  obj->hitbox = (byte *)0x0;
  obj->box2 = (byte *)0x0;
  obj->draw_list = 9;
  obj->flip = 0;
  obj->field_0x4 = 0;
  obj->field_0x51 = 5;
  obj->field_0x52 = 1;
  *(undefined4 *)&obj->field_0x58 = 0;
  *(undefined4 *)&obj->field_0x54 = 0;
  *(undefined4 *)&obj->field_0x5c = 0;
  DAT_801b29a6 = DAT_801b29a6 & 0xfe;
  iVar1 = FUN_8012c108(obj,&obj->field_0x50,0,0x26,0,4);
  if (iVar1 != 0) {
                    /* Probable PsyQ macro: setTile16() */
    *(undefined1 *)(iVar1 + 7) = 0x70;
    *(undefined1 *)(iVar1 + 0x26) = 9;
  }
  iVar1 = FUN_801e7cac(obj,&obj->field_0x51,0,0,8);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 7) = 4;
    *(undefined1 *)(iVar1 + 0x26) = 6;
  }
  *(int *)&obj->field_0x4c = iVar1;
  if (obj->var == 0) {
    obj->field_0x50 = 0;
    obj->state = 1;
  }
  else {
    obj->field_0x50 = 4;
    obj->state = 5;
  }
  obj->sub2 = 0;
  Anim_Set(obj,0);
  return;
}


// ---- 801d9d68 FUN_801d9d68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9d68(MM8Obj *obj)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    *(word *)&obj->field_0x54 = obj->y_frac;
    iVar1 = DAT_801ea308;
    iVar3 = DAT_801ea304;
    *(short *)&obj->field_0x56 = obj->y;
                    /* Possible PsyQ macro: setLineF2() */
    obj->sub2 = obj->sub2 + 1;
    obj->speed_y_up = iVar3;
    obj->gravity = iVar1;
  }
  FUN_80104ccc(obj);
  FUN_801da2ac(obj);
  iVar3 = FUN_801da2ec(obj);
  bVar2 = 3;
  if (iVar3 == 0) {
    if (obj->var == 0) {
      return;
    }
    if ((DAT_801b29a6 & 1) != 0) {
      return;
    }
    obj->field_0x50 = 4;
    bVar2 = 5;
  }
  obj->state = bVar2;
  obj->sub2 = 0;
  return;
}


// ---- 801d9e2c FUN_801d9e2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9e2c(MM8Obj *obj)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  
  bVar2 = obj->sub2;
  if (bVar2 == 0) {
    *(word *)&obj->field_0x58 = obj->x_frac;
    *(short *)&obj->field_0x5a = obj->x;
    obj->y_frac = *(undefined2 *)&obj->field_0x54;
    obj->y = *(undefined2 *)&obj->field_0x56;
    obj->sub2 = obj->sub2 + 1;
  }
  else if (bVar2 == 1) {
    if ((int)DAT_8015e248._2_2_ < obj->x + -0x20) {
      bVar2 = 2;
    }
    else {
      bVar2 = 6;
      if (obj->x + 0x20 < (int)DAT_8015e248._2_2_) {
        bVar2 = 4;
      }
    }
    obj->sub2 = bVar2;
  }
  if (bVar2 == 2) {
    uVar3 = 2;
  }
  else {
    if (bVar2 == 3) {
      Anim_Step(obj);
      iVar1 = Anim_AtLoopMarker(obj);
      if (iVar1 == 0) {
        return;
      }
      Anim_Set(obj,3);
      obj->sub2 = 6;
      return;
    }
    if (bVar2 == 4) {
      Anim_Step(obj);
      iVar1 = Anim_AtLoopMarker(obj);
      if (iVar1 == 0) {
        return;
      }
      uVar3 = 5;
    }
    else {
      if (bVar2 != 5) {
        if (bVar2 != 6) {
          return;
        }
        Anim_Step(obj);
        iVar1 = Anim_AtLoopMarker(obj);
        if (iVar1 == 0) {
          return;
        }
        obj->state = 3;
        obj->sub2 = 0;
        return;
      }
      Anim_Step(obj);
      iVar1 = Anim_AtLoopMarker(obj);
      if (iVar1 == 0) {
        return;
      }
      uVar3 = 6;
    }
  }
  Anim_Set(obj,uVar3);
  obj->sub2 = obj->sub2 + 1;
  return;
}


// ---- 801d9fa4 FUN_801d9fa4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9fa4(MM8Obj *obj)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)&obj->field_0x5c;
  if (obj->sub2 == 0) {
    iVar2._0_2_ = obj->x_frac;
    iVar2._2_2_ = obj->x;
    if (iVar2 == iVar5) {
      obj->speed_x = 0;
    }
    else {
      iVar3 = -0x30000;
      if (iVar2 <= iVar5) {
        iVar3 = 0x30000;
      }
      obj->speed_x = iVar3;
    }
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  FUN_80104d00(obj);
  if (obj->speed_x < 1) {
    iVar3._0_2_ = obj->x_frac;
    iVar3._2_2_ = obj->x;
    bVar1 = iVar5 < iVar3;
  }
  else {
    iVar4._0_2_ = obj->x_frac;
    iVar4._2_2_ = obj->x;
    bVar1 = iVar4 < iVar5;
  }
  if (!bVar1) {
    obj->x_frac = (short)iVar5;
    obj->x = (short)((uint)iVar5 >> 0x10);
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->state = 4;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801da070 FUN_801da070

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da070(MM8Obj *obj)

{
  byte bVar1;
  word wVar2;
  byte bVar3;
  char cVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  
  bVar1 = obj->sub2;
  if (bVar1 == 0) {
    obj->field_0x52 = 8;
    *(word *)&obj->field_0x58 = obj->x_frac;
    *(short *)&obj->field_0x5a = obj->x;
    obj->y_frac = *(undefined2 *)&obj->field_0x54;
    obj->y = *(undefined2 *)&obj->field_0x56;
    obj->sub2 = obj->sub2 + 1;
    FUN_8010544c(obj,0x106);
    goto LAB_801da200;
  }
  if (bVar1 == 1) {
    uVar7 = (byte)obj->field_0x52 + 0xff;
    obj->field_0x52 = (char)uVar7;
    if ((uVar7 & 0xff) != 0) {
      *(uint *)&obj->x_frac = (uVar7 & 2) * 0x8000 + *(int *)&obj->field_0x58;
      goto LAB_801da200;
    }
    bVar3 = obj->sub2 + 1;
    obj->x_frac = *(undefined2 *)&obj->field_0x58;
    obj->x = *(undefined2 *)&obj->field_0x5a;
  }
  else if (bVar1 == 2) {
    Anim_Set(obj,1);
    FUN_8010544c(obj,0x107);
    bVar3 = obj->sub2 + 1;
  }
  else {
    if (bVar1 == 3) {
      Anim_Step(obj);
      iVar6 = Anim_AtLoopMarker(obj);
      if (iVar6 != 0) {
        if (obj->var != 0) {
          DAT_801b29a6 = DAT_801b29a6 & 0xfe;
        }
                    /* Probable PsyQ macro: setLineF2() */
        obj->field_0x52 = 0x40;
        obj->box2 = (byte *)0x0;
        obj->hitbox = (byte *)0x0;
        obj->field_0x4 = 0;
        obj->state = 1;
        obj->sub2 = 0;
      }
      goto LAB_801da200;
    }
    if ((bVar1 != 4) || (cVar4 = obj->field_0x52 + -1, obj->field_0x52 = cVar4, cVar4 != '\0'))
    goto LAB_801da200;
    wVar2 = obj->frame;
    do {
      Anim_StepN(obj,1);
    } while (obj->frame != wVar2);
    bVar3 = 3;
  }
  obj->sub2 = bVar3;
LAB_801da200:
  if ((obj->anim_extra & 0x7f) == 0) {
    obj->field_0x51 = 5;
  }
  else {
    pbVar5 = *(byte **)(&DAT_801ea348 + (obj->anim_extra & 0x7f) * 4);
    obj->field_0x51 = 4;
    obj->box2 = pbVar5;
    obj->hitbox = pbVar5;
    FUN_801da4e4(obj);
    if ((((bVar1 < 4) && (obj->field_0x4 == '\0')) && (iVar6 = FUN_801da3ec(obj), iVar6 != 0)) &&
       (*(char *)(iVar6 + 6) == '!')) {
      obj->field_0x52 = 0x1e;
      obj->field_0x4 = 1;
      obj->sub2 = 4;
    }
  }
  return;
}


// ---- 801da2ac FUN_801da2ac

void FUN_801da2ac(int param_1)

{
  if ((DAT_801ea304 < *(int *)(param_1 + 0x18)) || (*(int *)(param_1 + 0x18) < -DAT_801ea304)) {
    *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
  }
  return;
}


// ---- 801da2ec FUN_801da2ec

undefined4 FUN_801da2ec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x52) == '\0') {
    iVar1 = FUN_801da380();
    if (iVar1 == 0) {
      return 0;
    }
    if ((ushort)((*(short *)(param_1 + 0xe) - *(short *)(iVar1 + 0xe)) + 0x100U) < 0x201) {
      uVar2 = *(undefined4 *)(iVar1 + 0xc);
      *(undefined1 *)(param_1 + 0x52) = 0x40;
      *(undefined4 *)(param_1 + 0x5c) = uVar2;
      return 1;
    }
  }
  else {
    *(char *)(param_1 + 0x52) = *(char *)(param_1 + 0x52) + -1;
  }
  return 0;
}


// ---- 801da380 FUN_801da380

char * FUN_801da380(void)

{
  byte *pbVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  pcVar2 = &DAT_801b1eec;
  pbVar1 = (byte *)((int)&DAT_801b1ef0 + 3);
  while (((*pcVar2 == '\0' || (1 < pbVar1[-1] - 0x20)) || ((*pbVar1 & 0xf0) == 0))) {
    pbVar1 = pbVar1 + 0x50;
    iVar3 = iVar3 + 1;
    pcVar2 = pcVar2 + 0x50;
    if (0x1f < iVar3) {
      return (char *)0x0;
    }
  }
  return pcVar2;
}


// ---- 801da3ec FUN_801da3ec

char * FUN_801da3ec(int param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  pcVar3 = &DAT_801b1eec;
  pcVar2 = &DAT_801b1f38;
  while ((((*pcVar3 == '\0' || (*(short *)(pcVar2 + -0x3e) != *(short *)(param_1 + 0xe))) ||
          ((pcVar2[-0x46] != ' ' && ((pcVar2[-0x46] != '!' || (*(int *)(pcVar2 + -0x14) == 0))))))
         || (iVar1 = FUN_80107bf4(pcVar3,param_1,0), iVar1 == 0))) {
    pcVar2 = pcVar2 + 0x50;
    iVar4 = iVar4 + 1;
    pcVar3 = pcVar3 + 0x50;
    if (0x1f < iVar4) {
      return (char *)0x0;
    }
  }
  if (*pcVar2 == '\x01') {
    return pcVar3;
  }
  FUN_8010544c(param_1,0x108);
  *pcVar2 = '\x01';
  return pcVar3;
}


// ---- 801da4e4 FUN_801da4e4

void FUN_801da4e4(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 0x4c);
  if (((*pcVar1 != '\0') && (pcVar1[6] == '\x15')) && (pcVar1[7] == '\x04')) {
    *(ushort *)(pcVar1 + 0x2e) = (*(ushort *)(param_1 + 0x2e) & 0x7fff) + 0x1a;
  }
  return;
}


// ---- 801da538 FUN_801da538

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da538(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->sub2 = obj->sub2 + 1;
  }
  if ((DAT_801b29a6 & 1) != 0) {
    obj->field_0x50 = 0;
    obj->field_0x52 = 1;
    obj->state = 1;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801e7cac FUN_801e7cac

undefined1 * FUN_801e7cac(int param_1,undefined4 param_2,short param_3,short param_4,byte param_5)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    *puVar2 = 1;
    puVar2[1] = 0;
    puVar2[6] = 0x15;
    *(int *)(puVar2 + 0x18) = param_1;
    *(undefined4 *)(puVar2 + 0x14) = param_2;
    puVar2[0x39] = *(undefined1 *)(param_1 + 0x27);
    uVar1 = *(undefined1 *)(param_1 + 7);
    *(int *)(puVar2 + 0x1c) = (int)param_3;
    *(int *)(puVar2 + 0x20) = (int)param_4;
    puVar2[0x3a] = uVar1;
    uVar1 = (&DAT_801eaa48)[param_5];
    puVar2[7] = param_5;
    puVar2[0x3b] = uVar1;
    puVar2[0x27] = *(undefined1 *)(param_1 + 0x27);
    puVar2[0x25] = *(undefined1 *)(param_1 + 0x25);
    puVar2[0x26] = *(undefined1 *)(param_1 + 0x26);
    *(short *)(puVar2 + 0xe) = param_3 + *(short *)(param_1 + 0xe);
    *(short *)(puVar2 + 0x12) = param_4 + *(short *)(param_1 + 0x12);
  }
  return puVar2;
}


