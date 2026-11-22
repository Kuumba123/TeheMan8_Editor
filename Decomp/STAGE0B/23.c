// ID 23, STAGE0B.BIN, handler 0x801D9AB0. Ghidra output with the object struct applied; not matching C.
// ---- 801d9ab0 FUN_801d9ab0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ab0(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = DAT_80159f86;
  obj->field_0x56 = 0;
  obj->field_0x53 = 0;
  obj->field_0x54 = 0;
  obj->field_0x58 = 5;
                    /* Possible PsyQ macro: setTile8() */
  obj->clut = bVar1;
  (*(code *)(&PTR_FUN_801e8320)[obj->state])(obj);
  if (obj->active != 0) {
    if (obj->state < 0xc) {
      FUN_801dae84(obj);
      FUN_801daf24(obj,0xc);
    }
    else {
      iVar4 = (int)DAT_801d293a;
      obj->speed_x = iVar4 * 0x10000;
      if ((obj->var & 0x80) == 0) {
        iVar2 = -0x10000;
      }
      else {
        iVar2 = 0x10000;
      }
      obj->speed_x = iVar4 * 0x10000 + iVar2;
      obj->accel_x = 0;
      FUN_801dad78(obj);
      FUN_801dacc0(obj);
    }
    if ((obj->var & 0x40) == 0) {
      uVar3 = FUN_801daa74(obj);
      uVar3 = uVar3 & 0xe0;
    }
    else {
      uVar3 = FUN_801daa74(obj);
      if ((obj->var & 0x80) == 0) {
        uVar3 = uVar3 & 0x60;
      }
      else {
        uVar3 = uVar3 & 0x50;
      }
    }
    if (uVar3 == 0) {
      if (obj->field_0x56 == '\0') {
        Obj_CullAndQueueDrawMargin(obj,0x80);
      }
    }
    else {
      obj->field_0x53 = 2;
      obj->field_0x54 = 2;
      obj->field_0x58 = 2;
      Obj_Free();
    }
  }
  return;
}


// ---- 801d9c24 FUN_801d9c24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9c24(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
                    /* Possible PsyQ macro: setPolyF4() */
  Enemy_InitFromTable();
  obj->field_0x58 = 5;
  bVar1 = obj->var;
  obj->hitbox = (byte *)0x0;
  obj->box2 = (byte *)0x0;
  obj->draw_list = 8;
  obj->field_0x50 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  obj->field_0x54 = 0;
  obj->field_0x55 = 0;
  obj->field_0x56 = 0;
  obj->field_0x57 = 0;
  *(undefined4 *)&obj->field_0x4c = 0;
  obj->field_0x5f = 0;
  *(undefined2 *)&obj->field_0x4a = 0;
  obj->flip = (obj->var >> 7) << 6;
  sVar2 = g_cam_y;
  if ((bVar1 & 0x40) == 0) {
    iVar3 = FUN_801dad20(obj,9);
    if (iVar3 != 0) {
      *(undefined1 *)(iVar3 + 0x26) = 8;
      *(undefined1 **)(iVar3 + 0x14) = &obj->field_0x58;
      *(int *)&obj->field_0x4c = iVar3;
    }
                    /* Possible PsyQ macro: setLineF2() */
                    /* Probable PsyQ macro: setTile16() */
    if ((bVar1 & 3) == 0) {
      bVar1 = Rand();
    }
    else {
      bVar1 = (bVar1 & 3) == 1;
    }
    if ((bVar1 & 1) == 0) {
      obj->field_0x51 = 0x80;
      sVar2 = g_cam_y + 0x103;
    }
    else {
                    /* Possible PsyQ macro: setLineF2() */
      obj->field_0x51 = 0x40;
      sVar2 = g_cam_y + -0x13;
    }
    obj->y = sVar2;
    sVar2 = DAT_801d2918._2_2_;
    uVar4 = 10;
    uVar5 = 0xb;
    obj->state = 1;
    obj->sub2 = 0;
    obj->x = sVar2 + 0xf0;
  }
  else {
    if ((bVar1 & 0x20) == 0) {
      obj->field_0x51 = 0;
      obj->y = sVar2 + 0x20;
      if ((obj->var & 0x80) == 0) {
        uVar4 = 0xac;
        sVar2 = DAT_801d2918._2_2_ + 0x1bf;
      }
      else {
        uVar4 = 0xffffff54;
                    /* Possible PsyQ macro: setLineF2() */
        sVar2 = DAT_801d2918._2_2_ + -0x7f;
      }
      obj->x = sVar2;
      FUN_801daaec(obj,uVar4,0,2);
    }
    uVar4 = 4;
    uVar5 = 5;
    obj->state = 10;
    obj->sub2 = 0;
  }
  FUN_801dad20(obj,uVar4);
  iVar3 = FUN_801dad20(obj,3);
  if (iVar3 != 0) {
    *(undefined1 **)(iVar3 + 0x14) = &obj->field_0x54;
  }
  iVar3 = FUN_801dad20(obj,uVar5);
  if (iVar3 != 0) {
    *(undefined1 *)(iVar3 + 0x26) = 8;
  }
  Anim_Set(obj,0);
  return;
}


// ---- 801d9e34 FUN_801d9e34

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9e34(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    uVar2 = 8;
    if ((obj->var & 0x20) != 0) {
      uVar2 = 0xd;
    }
    iVar3 = 0x80000;
    obj->field_0x50 = uVar2;
    if ((obj->field_0x51 & 0x40) != 0) {
      iVar3 = -0x80000;
    }
    obj->speed_y_up = iVar3;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->sub2 = 0;
      obj->state = obj->state + 1;
    }
  }
  obj->speed_x = (int)DAT_801d293a << 0x10;
  FUN_80104c34();
  return;
}


// ---- 801d9f00 FUN_801d9f00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9f00(MM8Obj *obj)

{
  int iVar1;
  uint uVar2;
  
  if (obj->sub2 == 0) {
    iVar1 = 0x10000;
    if (obj->field_0x51 == '@') {
      iVar1 = -0x10000;
    }
    obj->gravity = iVar1;
                    /* Possible PsyQ macro: setPolyF4() */
    obj->sub2 = obj->sub2 + 1;
  }
  obj->speed_x = (int)DAT_801d293a << 0x10;
  FUN_80104ccc(obj);
  uVar2 = 0;
  if (obj->field_0x51 == '@') {
    uVar2 = (uint)~obj->speed_y_up >> 0x1f;
  }
  else if (obj->speed_y_up < 1) {
    uVar2 = 1;
  }
  if (uVar2 != 0) {
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->sub2 = 0;
    obj->state = obj->state + 1;
  }
  return;
}


// ---- 801d9fcc FUN_801d9fcc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9fcc(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,6);
    if (*(int *)&obj->field_0x4c != 0) {
      Anim_Set(*(int *)&obj->field_0x4c,8);
      *(char *)(*(int *)&obj->field_0x4c + 0x31) =
           *(char *)(*(int *)&obj->field_0x4c + 0x31) + '\x01';
    }
    obj->speed_y_up = 0;
    obj->accel_x = 0;
    obj->gravity = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      obj->sub2 = 0;
      obj->state = obj->state + 1;
    }
  }
  if (*(int *)&obj->field_0x4c != 0) {
    obj->field_0x58 = 0;
  }
  obj->speed_x = (int)DAT_801d293a << 0x10;
  FUN_80104c34();
  return;
}


// ---- 801da0b0 FUN_801da0b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da0b0(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  
  bVar1 = obj->sub2;
  if (bVar1 == 0) {
    obj->field_0x52 = 5;
    bVar1 = obj->sub2;
    uVar3 = 0xf;
LAB_801da154:
    obj->field_0x50 = uVar3;
  }
  else {
    if (bVar1 != 1) {
      uVar3 = 0x3c;
      if (bVar1 != 2) {
        cVar2 = obj->field_0x50 + -1;
        obj->field_0x50 = cVar2;
                    /* Possible PsyQ macro: setPolyGT3() */
        if (cVar2 == '\0') {
          obj->sub2 = 0;
          obj->state = obj->state + 1;
        }
        goto LAB_801da190;
      }
      bVar1 = obj->sub2;
      goto LAB_801da154;
    }
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 != '\0') goto LAB_801da190;
    FUN_801daa04(obj);
    cVar2 = obj->field_0x52 + -1;
    obj->field_0x52 = cVar2;
    if (cVar2 != '\0') {
      obj->field_0x50 = 0xf;
      goto LAB_801da190;
    }
    bVar1 = obj->sub2;
  }
  obj->sub2 = bVar1 + 1;
LAB_801da190:
                    /* Probable PsyQ macro: setLineF2() */
  if (*(int *)&obj->field_0x4c != 0) {
    obj->field_0x58 = 0;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->speed_x = (int)DAT_801d293a << 0x10;
  Obj_ApplySpeed();
  return;
}


// ---- 801da1d0 FUN_801da1d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da1d0(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,7);
    if (*(int *)&obj->field_0x4c != 0) {
      Anim_Set(*(int *)&obj->field_0x4c,9);
      *(char *)(*(int *)&obj->field_0x4c + 0x31) =
           *(char *)(*(int *)&obj->field_0x4c + 0x31) + '\x01';
      obj->field_0x58 = 0;
    }
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x50 = 0x3c;
      obj->field_0x5f = 7;
      obj->sub2 = 0;
      obj->state = obj->state + 1;
    }
  }
  if (*(int *)&obj->field_0x4c != 0) {
    obj->field_0x58 = 0;
  }
  obj->speed_x = (int)DAT_801d293a << 0x10;
  Obj_ApplySpeed();
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801da2bc FUN_801da2bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da2bc(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->field_0x58 = 5;
    obj->speed_y_up = -0x2f00;
                    /* Possible PsyQ macro: setLineF2() */
    obj->accel_x = 0;
    obj->gravity = 0x100;
    obj->sub2 = obj->sub2 + 1;
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 0;
    obj->state = obj->field_0x5f;
  }
  obj->speed_x = (int)DAT_801d293a << 0x10;
  FUN_801dacc0();
  return;
}


// ---- 801da360 FUN_801da360

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da360(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_801d293a;
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->field_0x58 = 5;
    obj->speed_x = uVar2 * 0x10000 + 0x30000;
    obj->accel_x = -0x2000;
    obj->speed_y_up = 0;
    obj->gravity = 0x100;
    obj->sub2 = obj->sub2 + 1;
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 0;
    obj->state = obj->field_0x5f;
  }
  FUN_80104c9c(obj);
  if (obj->speed_x == uVar2 << 0x10) {
    obj->sub2 = 0;
    obj->state = obj->state + 1;
  }
  return;
}


// ---- 801da430 FUN_801da430

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da430(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
  sVar1 = DAT_8015e24c._2_2_;
  if (obj->sub2 == 0) {
    iVar2 = (int)DAT_801d293a;
    obj->accel_x = -0x8000;
    obj->speed_y_up = 0;
                    /* Possible PsyQ macro: setPolyF3() */
    obj->speed_x = iVar2 * 0x10000 + 0x10000;
    if ((ushort)((obj->y - sVar1) + 0x30U) < 0x31) {
      obj->gravity = 0;
    }
    else {
      iVar2 = -0x800;
      if (obj->y <= sVar1) {
        iVar2 = 0x800;
      }
      obj->gravity = iVar2;
    }
    obj->sub2 = obj->sub2 + 1;
  }
  Obj_ApplySpeed(obj);
  iVar2 = DAT_801d293a * 0x10000 + -0x60000;
  if (obj->speed_x <= iVar2) {
    obj->speed_x = iVar2;
    obj->accel_x = 0;
  }
  return;
}


// ---- 801da51c FUN_801da51c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da51c(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    sVar2 = 0xac;
    if ((obj->var & 0x80) != 0) {
      sVar2 = -0xac;
    }
    iVar3 = -0x28000;
    *(short *)&obj->field_0x4a = obj->x;
    *(ushort *)&obj->field_0x4a = obj->x + (ushort)(byte)obj->field_0x51 * sVar2;
    if ((obj->var & 0x80) != 0) {
      iVar3 = 0x40000;
    }
    bVar1 = obj->sub2;
    obj->speed_x = iVar3;
    obj->speed_y_up = 0;
    obj->accel_x = 0;
    obj->gravity = 0;
  }
  else {
    if (obj->sub2 != 1) {
      Anim_Step(obj);
      iVar3 = Anim_AtLoopMarker(obj);
      if (iVar3 != 0) {
        obj->field_0x50 = 0xf;
        obj->sub2 = 0;
        obj->state = obj->state + 1;
      }
      goto LAB_801da650;
    }
    Anim_Step(obj);
    if ((obj->var & 0x80) == 0) {
      sVar2 = *(short *)&obj->field_0x4a - obj->x;
    }
    else {
      sVar2 = obj->x - *(short *)&obj->field_0x4a;
    }
    if (sVar2 < 0x10) goto LAB_801da650;
    Anim_Set(obj,1);
    bVar1 = obj->sub2;
  }
  obj->sub2 = bVar1 + 1;
LAB_801da650:
  FUN_80104c34(obj);
  return;
}


// ---- 801da66c FUN_801da66c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da66c(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,1);
    Anim_StepN(obj,3);
    iVar3 = -0x28000;
    if ((obj->var & 0x80) != 0) {
      iVar3 = 0x40000;
    }
    sVar2 = -0xac;
    obj->speed_x = iVar3;
    obj->speed_y_up = 0;
    obj->accel_x = 0;
    obj->gravity = 0;
    if ((obj->var & 0x80) != 0) {
      sVar2 = 0xac;
    }
    obj->field_0x50 = 0xf;
    *(short *)&obj->field_0x4a = obj->x;
    obj->sub2 = obj->sub2 + 1;
    *(ushort *)&obj->field_0x4a = obj->x + (ushort)(byte)obj->field_0x51 * sVar2;
  }
  if ((obj->field_0x50 != '\0') &&
     (cVar1 = obj->field_0x50 + -1, obj->field_0x50 = cVar1, cVar1 == '\0')) {
    FUN_801dabec(obj);
    obj->field_0x50 = 0xf;
  }
  FUN_80104c34(obj);
  iVar3 = FUN_801dac78(obj);
  if (iVar3 != 0) {
    obj->sub2 = 0;
    obj->state = obj->state + 1;
  }
  return;
}


// ---- 801da790 FUN_801da790

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da790(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = obj->sub2;
  if (bVar1 == 0) {
    iVar2 = -0x800;
    if ((obj->var & 0x80) == 0) {
      iVar2 = 0x800;
    }
    obj->accel_x = iVar2;
    bVar1 = obj->sub2;
    obj->gravity = -0x1000;
  }
  else if (bVar1 == 1) {
    if (obj->speed_x != 0) goto LAB_801da840;
    Anim_Set(obj,2);
    bVar1 = obj->sub2;
    obj->accel_x = 0;
  }
  else {
    if (bVar1 != 2) goto LAB_801da840;
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 == 0) goto LAB_801da840;
    Anim_Set(obj,0);
    bVar1 = obj->sub2;
  }
  obj->sub2 = bVar1 + 1;
LAB_801da840:
  Obj_ApplySpeed(obj);
  return;
}


// ---- 801da85c FUN_801da85c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da85c(MM8Obj *obj)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  
  if (obj->sub2 == 0) {
    obj->field_0x50 = 0x49;
    obj->field_0x57 = 6;
    obj->sub2 = obj->sub2 + 1;
  }
  bVar4 = obj->field_0x50 - 1;
  uVar2 = (uint)bVar4;
  obj->field_0x50 = bVar4;
  if (uVar2 == 0) {
    uVar2 = 7;
    iVar3 = 0x7000000;
    do {
                    /* Possible PsyQ macro: setSprt16() + setSemiTrans(sprt16, 1) +
                       setShadeTex(sprt16, 1) */
      FUN_80108ed8(obj,(int)(char)(&DAT_801e8364)[iVar3 >> 0x17],
                   (int)(char)(&DAT_801e8365)[iVar3 >> 0x17]);
      if ((uVar2 & 3) != 0) {
        FUN_8010544c(obj,9);
      }
      uVar2 = uVar2 - 1;
      iVar3 = uVar2 * 0x1000000;
    } while (-1 < (int)(uVar2 * 0x1000000));
    obj->field_0x56 = 1;
    obj->field_0x53 = 2;
    obj->field_0x54 = 2;
    obj->field_0x58 = 2;
    FUN_80108fd8(obj,1);
    Obj_Free(obj);
  }
  else {
    if (uVar2 % 6 == 1) {
      iVar3 = ((uVar2 / 6) % 6) * 2;
      FUN_80108ed8(obj,(int)(char)(&DAT_801e8364)[iVar3],(int)(char)(&DAT_801e8365)[iVar3]);
      FUN_8010544c(obj,9);
    }
    if ((bVar4 & 1) == 0) {
      obj->field_0x56 = 1;
      uVar1 = 5;
    }
    else {
      uVar1 = 4;
      obj->field_0x56 = 0;
    }
    obj->field_0x53 = uVar1;
    obj->field_0x54 = uVar1;
    obj->field_0x58 = uVar1;
  }
  return;
}


// ---- 801daa04 FUN_801daa04

void FUN_801daa04(int param_1)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)FUN_801055e4();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x11;
    puVar2[7] = 0xd6;
    puVar2[0x26] = 8;
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + -3;
    sVar1 = *(short *)(param_1 + 0x12);
    puVar2[1] = 0;
    *(short *)(puVar2 + 0x12) = sVar1 + 6;
  }
  return;
}


// ---- 801daa74 FUN_801daa74

int FUN_801daa74(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)((DAT_801d2918._2_2_ - 0x80) * 0x10000) >> 0x10;
  if (iVar2 < *(short *)(param_1 + 0xe)) {
    iVar1 = 0x10;
    if ((int)*(short *)(param_1 + 0xe) < iVar2 + 0x240) {
      iVar2 = (int)((g_cam_y - 0x40) * 0x10000) >> 0x10;
      if (iVar2 < *(short *)(param_1 + 0x12)) {
        iVar1 = ((int)*(short *)(param_1 + 0x12) < iVar2 + 0x170 ^ 1) << 7;
      }
      else {
        iVar1 = 0x40;
      }
    }
  }
  else {
    iVar1 = 0x20;
  }
  return iVar1;
}


// ---- 801daaec FUN_801daaec

void FUN_801daaec(int param_1,short param_2,short param_3,uint param_4)

{
  byte bVar1;
  undefined1 *puVar2;
  char cVar3;
  short sVar4;
  short sVar5;
  
  sVar5 = *(short *)(param_1 + 0xe);
  sVar4 = *(short *)(param_1 + 0x12);
  cVar3 = *(char *)(param_1 + 0x51);
  if ((((*(byte *)(param_1 + 7) & 0x20) == 0) && ((param_4 & 0xff) != 0)) && (cVar3 == '\0')) {
    do {
      puVar2 = (undefined1 *)FUN_801055e4();
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x23;
        Enemy_InitFromTable(puVar2);
        sVar5 = sVar5 + param_2;
        sVar4 = sVar4 + param_3;
        bVar1 = *(byte *)(param_1 + 7);
        cVar3 = cVar3 + '\x01';
        *(short *)(puVar2 + 0xe) = sVar5;
        *(short *)(puVar2 + 0x12) = sVar4;
        puVar2[0x51] = cVar3;
        puVar2[7] = bVar1 & 0x80 | 0x60;
      }
      param_4 = param_4 - 1;
    } while (0 < (int)(param_4 * 0x1000000));
  }
  return;
}


// ---- 801dabec FUN_801dabec

void FUN_801dabec(int param_1)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)FUN_801055e4();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 1;
    puVar2[7] = 0;
    puVar2[0x26] = 8;
                    /* Probable PsyQ macro: setLineF2() */
    if ((*(byte *)(param_1 + 7) & 0x80) == 0) {
      sVar1 = *(short *)(param_1 + 0xe) + 2;
    }
    else {
      sVar1 = *(short *)(param_1 + 0xe) + -2;
    }
    *(short *)(puVar2 + 0xe) = sVar1;
    sVar1 = *(short *)(param_1 + 0x12);
    puVar2[1] = 0;
    puVar2[2] = 0;
    *(short *)(puVar2 + 0x12) = sVar1 + 0x1c;
  }
  return;
}


// ---- 801dac78 FUN_801dac78

bool FUN_801dac78(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  if ((*(byte *)(param_1 + 7) & 0x80) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x4a);
    uVar2 = *(ushort *)(param_1 + 0xe);
    iVar3 = 0x330;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0xe);
    uVar2 = *(ushort *)(param_1 + 0x4a);
    iVar3 = 0x230;
  }
  return iVar3 <= (int)(((uint)uVar1 - (uint)uVar2) * 0x10000) >> 0x10;
}


// ---- 801dacc0 FUN_801dacc0

void FUN_801dacc0(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x55) == '\x02') {
    *(undefined4 *)(param_1 + 0x18) = 0xffffc000;
    iVar1 = 0x20000;
  }
  else {
    if (*(int *)(param_1 + 0x18) + 0x2fffU < 0x5fff) goto switchD_801dac0c_default;
    iVar1 = -*(int *)(param_1 + 0x20);
  }
  *(int *)(param_1 + 0x20) = iVar1;
switchD_801dac0c_default:
  FUN_80104ccc();
  return;
}


// ---- 801dad20 FUN_801dad20

int FUN_801dad20(int param_1,undefined1 param_2)

{
  int iVar1;
  
                    /* Possible PsyQ macro: setTile8() */
  iVar1 = FUN_8012c108(param_1,param_1 + 0x53,0,0,0,param_2);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 7) = 0xf0;
    *(undefined1 *)(iVar1 + 0x26) = 7;
    *(undefined2 *)(iVar1 + 0x3a) = 0x80;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  return iVar1;
}


// ---- 801dad78 FUN_801dad78

void FUN_801dad78(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 4;
  do {
    uVar1 = (uint)*(byte *)(param_1 + 0x57) % 6;
    if (uVar1 == (int)(char)iVar4) {
      iVar2 = uVar1 * 2;
      iVar3 = (int)(char)(&DAT_801e8358)[iVar2];
      if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
        iVar3 = -iVar3;
      }
      iVar3 = FUN_801091a4((int)((iVar3 + (uint)*(ushort *)(param_1 + 0xe)) * 0x10000) >> 0x10,
                           (int)(((int)(char)(&DAT_801e8359)[iVar2] +
                                 (uint)*(ushort *)(param_1 + 0x12)) * 0x10000) >> 0x10,1);
      if (iVar3 != 0) {
        *(undefined1 *)(iVar3 + 0x26) = 7;
        *(undefined1 *)(iVar3 + 0x39) = 1;
      }
    }
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4 * 0x1000000);
  *(char *)(param_1 + 0x57) = *(char *)(param_1 + 0x57) + '\x01';
  return;
}


// ---- 801dae84 FUN_801dae84

void FUN_801dae84(int param_1)

{
  int iVar1;
  short sVar2;
  
  if ((*(byte *)(param_1 + 0x57) & 7) == 0) {
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar2 = *(short *)(param_1 + 0xe) + 6;
    }
    else {
      sVar2 = *(short *)(param_1 + 0xe) + -6;
    }
    iVar1 = FUN_801091a4((int)sVar2,(int)((*(ushort *)(param_1 + 0x12) - 0x2c) * 0x10000) >> 0x10,1)
    ;
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0x26) = 7;
      *(undefined1 *)(iVar1 + 0x39) = 1;
    }
  }
  *(char *)(param_1 + 0x57) = *(char *)(param_1 + 0x57) + '\x01';
  return;
}


// ---- 801daf24 FUN_801daf24

void FUN_801daf24(int param_1,undefined1 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  *(undefined **)(param_1 + 0x3c) = &DAT_801e8354;
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 == '\x02') {
    *(undefined1 *)(param_1 + 0x24) = 0;
    *(undefined1 *)(param_1 + 0x53) = 3;
    if (*(char *)(param_1 + 0x55) != '\x02') {
      *(undefined1 *)(param_1 + 0x54) = 3;
    }
    *(undefined1 *)(param_1 + 0x58) = 3;
    if ((*(char *)(param_1 + 0x55) == '\0') && (*(byte *)(param_1 + 0x47) < 6)) {
      FUN_80108ed8(param_1,0xe,6);
      FUN_8010544c(param_1,8);
      FUN_8012ae08(param_1,0x19);
      *(undefined1 *)(param_1 + 0x54) = 2;
      *(undefined1 *)(param_1 + 0x55) = 1;
    }
  }
  if (cVar1 == '\x04') {
    if (*(int *)(param_1 + 0x14) != 0) {
                    /* Possible PsyQ macro: setTile16() */
      uVar2 = 0xffff0000;
      if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
        uVar2 = 0x10000;
      }
      *(undefined4 *)(param_1 + 0x14) = uVar2;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    *(undefined1 *)(param_1 + 1) = param_2;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 0x55) = 2;
  }
  Enemy_ContactDamage(param_1);
  return;
}


