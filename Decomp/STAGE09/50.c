// ID 50, STAGE09.BIN, handler 0x801D9684. Ghidra output with the object struct applied; not matching C.
// ---- 801d9684 FUN_801d9684

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9684(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&switchD_801dba60::switchD)[obj->state])();
  if ((obj->active != 0) && (DAT_801c336c == '\x03')) {
    FUN_80103184(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801d9700 FUN_801d9700

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9700(MM8Obj *obj)

{
  if (DAT_801c336c == '\x03') {
    Enemy_InitFromTable();
    obj->state = 1;
                    /* Possible PsyQ macro: setSprt16() + setShadeTex(sprt16, 1) */
    obj->bank = 0x7d;
    if (DAT_801c337f == '\0') {
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
    }
    else {
      obj->flip = 0;
    }
    obj->draw_list = 7;
    obj->field_0x49 = 7;
    *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
    obj->dmg_table = 0x1d;
    obj->box2 = &DAT_801dba48;
    obj->hitbox = &DAT_801dba54;
    obj->field_0x54 = 0;
    obj->field_0x55 = 0;
    obj->field_0x56 = 0;
    obj->contact_dmg = 4;
    Anim_Set(obj,2);
    FUN_80103224(obj);
    FUN_801dad94(obj);
  }
  else if (obj->sub2 == 0) {
    obj->sub2 = 1;
    FUN_80102ecc(1);
  }
  else if (DAT_801b299e == '\0') {
    FUN_80111918();
    FUN_80111e10();
    Obj_Free(obj);
  }
  return;
}


// ---- 801d9828 FUN_801d9828

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9828(MM8Obj *obj)

{
  (*(code *)(&PTR_switchD_801dba70)[obj->sub2])();
  return;
}


// ---- 801d9864 switchD

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801d9864::switchD(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
                    /* Possible PsyQ macro: setTile8() */
    if (DAT_801b299e == '\0') {
      if (DAT_801c337f == '\0') {
        DAT_801c337f = '\x01';
        FUN_801dae08();
        obj->sub3 = 1;
        FUN_800fcb80(0x33);
      }
      else {
        obj->sub2 = 3;
        obj->sub3 = 0;
        Anim_Set(obj,0xf);
        obj->speed_y_up = 0x4000;
                    /* Possible PsyQ macro: setPolyGT4() */
        obj->field_0x51 = 0x3c;
        FUN_801dae54();
        obj->field_0x50 = 0;
        FUN_800fcb80(0x33);
      }
    }
  }
  else if (DAT_801cf53c == '\0') {
    obj->sub2 = 1;
    obj->sub3 = 0;
    FUN_801037e0(0x12);
    FUN_801dad20(obj,4,0x40);
    obj->field_0x50 = 1;
  }
  return;
}


// ---- 801d9960 FUN_801d9960

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9960(MM8Obj *obj)

{
  FUN_801daf5c();
  if (obj->sub3 == 3) {
    obj->sub2 = 2;
    obj->sub3 = 0;
    FUN_801037e0(0x13);
    FUN_801dad20(obj,5,0);
    obj->flip = 0;
  }
  return;
}


// ---- 801d99bc FUN_801d99bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d99bc(MM8Obj *obj)

{
  Anim_Step();
  if (obj->sub3 == 3) {
    obj->field_0x51 = obj->field_0x51 + -1;
    if (obj->field_0x51 == '\0') {
      obj->sub2 = 3;
      obj->sub3 = 0;
      Anim_Set(obj,0xf);
      obj->speed_y_up = 0x4000;
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x51 = 0x3c;
      FUN_801dae54();
      obj->field_0x50 = 0;
    }
  }
  else {
    FUN_801dae90(obj);
    if (obj->sub3 == 3) {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x51 = 0x3c;
    }
  }
  return;
}


// ---- 801d9a68 FUN_801d9a68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9a68(MM8Obj *obj)

{
  switch(obj->sub3) {
  case 0:
    FUN_80104d18(obj);
    obj->field_0x51 = obj->field_0x51 + -1;
    if (obj->field_0x51 == '\0') {
      obj->sub3 = 1;
                    /* Possible PsyQ macro: setTile8() */
      obj->field_0x51 = 0x78;
      Anim_Set(obj,0xf);
      FUN_8010544c(obj,0x191);
      FUN_8010544c(obj,0x195);
      obj->field_0x54 = 1;
    }
    break;
  case 1:
    Anim_Step(obj);
    obj->field_0x51 = obj->field_0x51 + -1;
    if (obj->field_0x51 == '\0') {
      obj->sub3 = 2;
      obj->gravity = 0x4000;
      obj->speed_x = 0;
      obj->speed_y_up = 0;
      obj->field_0x43 = 1;
      Anim_Set(obj,4);
      obj->field_0x54 = 0;
    }
    break;
  case 2:
    Anim_Step(obj);
    FUN_80104ccc(obj);
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->sub3 = 3;
      obj->field_0x43 = 0;
      Anim_Set(obj,6);
    }
    break;
  case 3:
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->sub3 = 4;
      Anim_Set(obj,2);
      FUN_800fcb80(0x34);
    }
    break;
  case 4:
    Anim_Step(obj);
    if (DAT_801cf53c == '\0') {
      FUN_80111918();
      obj->state = 2;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x52 = 0;
      obj->field_0x53 = 0;
      obj->hp = 0xf;
      obj->field_0x5a = 0;
                    /* Possible PsyQ macro: setPolyF4() */
      obj->field_0x5b = 0;
    }
  }
  return;
}


// ---- 801d9dac FUN_801d9dac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9dac(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  
  if (obj->sub3 == 0) {
    obj->sub3 = 1;
    bVar1 = Rand();
    obj->field_0x51 = (bVar1 & 0x1f) + 0x14;
    Anim_Set(obj,2);
  }
  FUN_8010910c(obj);
  Anim_Step(obj);
  obj->field_0x51 = obj->field_0x51 + -1;
  if (obj->field_0x51 != '\0') {
    return;
  }
  uVar2 = Rand();
  bVar1 = 1;
  if ((uVar2 & 1) != 0) {
    bVar1 = 4;
  }
  if (bVar1 == obj->field_0x5a) {
    if ((byte)obj->field_0x5b < 2) goto LAB_801d9e60;
    bVar1 = 1;
  }
  obj->field_0x5b = 0;
LAB_801d9e60:
  obj->field_0x5a = bVar1;
  obj->sub2 = bVar1;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->field_0x5b = obj->field_0x5b + '\x01';
  return;
}


// ---- 801d9e90 FUN_801d9e90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9e90(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801dba94)[obj->sub3])();
  return;
}


// ---- 801d9ecc FUN_801d9ecc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ecc(MM8Obj *obj)

{
  int iVar1;
  
  obj->sub3 = 1;
  obj->field_0x43 = 1;
  obj->speed_y_up = 0x59943;
  obj->gravity = 0x3000;
  iVar1 = DAT_8015e248 - *(int *)&obj->x_frac;
  obj->box2 = &DAT_801dba48;
  obj->speed_x = iVar1 / 0x3a;
  FUN_8010910c(obj);
                    /* Possible PsyQ macro: setPolyF4() */
  Anim_Set(obj,3);
  FUN_8010544c(obj,0x193);
  return;
}


// ---- 801d9f70 FUN_801d9f70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9f70(MM8Obj *obj)

{
  Anim_Step();
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if (obj->speed_y_up < 0) {
    obj->sub3 = 2;
    FUN_8010910c(obj);
    Anim_Set(obj,4);
  }
  return;
}


// ---- 801d9fd0 FUN_801d9fd0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9fd0(MM8Obj *obj)

{
  Anim_Step();
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->sub3 = 3;
    obj->field_0x43 = 0;
    FUN_8010910c(obj);
    Anim_Set(obj,6);
    FUN_8010544c(obj,0x194);
  }
  return;
}


// ---- 801da044 FUN_801da044

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da044(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    obj->sub2 = 2;
    obj->sub3 = 0;
    FUN_8010544c(obj,0x195);
  }
  return;
}


// ---- 801da090 FUN_801da090

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da090(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  
  if (obj->sub3 == 0) {
    obj->sub3 = 1;
    obj->field_0x51 = 0x14;
    Anim_Set(obj,0xb);
    FUN_8010910c(obj);
    iVar2 = 0x40000;
    if (obj->flip == 0) {
      iVar2 = -0x40000;
    }
    obj->speed_x = iVar2;
    iVar2 = (uint)(ushort)obj->x - (uint)DAT_8015e248._2_2_;
    sVar4 = (short)iVar2;
    if (iVar2 * 0x10000 < 0) {
      sVar4 = -sVar4;
    }
    iVar2 = (int)sVar4;
    cVar1 = '\x01';
    if (0x37 < iVar2) {
      iVar3 = iVar2 + -0x38;
      if (iVar3 < 0) {
        iVar3 = iVar2 + -0x35;
      }
      cVar1 = (char)(iVar3 >> 2) + '\x01';
    }
    obj->field_0x4 = cVar1;
  }
  Anim_Step(obj);
  if (obj->field_0x51 == '\0') {
    FUN_80104d00(obj);
                    /* Possible PsyQ macro: setPolyGT3() */
    obj->field_0x4 = obj->field_0x4 + -1;
    if (obj->field_0x4 == '\0') {
      obj->sub2 = 3;
                    /* Probable PsyQ macro: setLineF2() */
      obj->sub3 = 0;
      obj->field_0x4 = 0;
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x51 = 0x3c;
      Anim_Set(obj,0xc);
    }
  }
  else {
    obj->field_0x51 = obj->field_0x51 + -1;
  }
  FUN_80106214(obj);
  return;
}


// ---- 801da1c8 FUN_801da1c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da1c8(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    Anim_Step();
    if (obj->anim_extra != 0) {
      obj->field_0x55 = 1;
      DAT_801d2936 = 0x3c;
      FUN_8010544c(obj,0x192);
    }
    obj->field_0x51 = obj->field_0x51 + -1;
    if (obj->field_0x51 == '\0') {
      obj->sub3 = 1;
      Anim_Set(obj,0xd);
      obj->field_0x55 = 0;
    }
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->sub2 = 0;
      obj->sub3 = 0;
    }
  }
  FUN_80106214(obj);
  return;
}


// ---- 801da290 FUN_801da290

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da290(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801dbaa4)[obj->sub3])();
  return;
}


// ---- 801da2cc FUN_801da2cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da2cc(MM8Obj *obj)

{
  obj->sub3 = 1;
  obj->field_0x43 = 1;
  obj->field_0x54 = 1;
  obj->dmg_table = 0;
                    /* Possible PsyQ macro: setLineF2() */
  obj->field_0x51 = 0x40;
  Anim_Set(obj,0xf);
  FUN_8010544c(obj,0x191);
  FUN_8010544c(obj,0x196);
  return;
}


// ---- 801da32c FUN_801da32c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da32c(MM8Obj *obj)

{
  FUN_8010910c();
  Anim_Step(obj);
  obj->field_0x51 = obj->field_0x51 + -1;
  obj->y = obj->y + -1;
  if (obj->field_0x51 == '\0') {
    obj->sub3 = 2;
    obj->field_0x54 = 0;
    Anim_Set(obj,7);
  }
  return;
}


// ---- 801da398 FUN_801da398

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da398(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  Anim_Step();
  if ((short)obj->frame < 0) {
    obj->sub3 = 3;
    obj->box2 = &DAT_801dba4d;
    obj->hitbox = &DAT_801dba58;
    cVar1 = Rand();
    obj->field_0x51 = cVar1 + 0x78U & 0x7f;
    Anim_Set(obj,9);
    FUN_8010910c(obj);
    iVar2 = 0x60000;
    if (obj->flip == 0) {
      iVar2 = -0x60000;
    }
    obj->speed_x = iVar2;
    obj->speed_y_up = 0x60000;
    FUN_8010544c(obj,400);
  }
  return;
}


// ---- 801da43c FUN_801da43c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da43c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x51 != '\0') {
    obj->field_0x51 = obj->field_0x51 + -1;
  }
  Anim_Step(obj);
  FUN_80104c34(obj);
  FUN_80106214(obj);
                    /* Possible PsyQ macro: setPolyF3() */
  if (obj->field_0x33 != '\0') {
    FUN_8010544c(obj,0x197);
    obj->sub3 = 4;
    obj->field_0x58 = obj->field_0x33;
    Anim_Set(obj,10);
    if ((obj->field_0x58 & 0x30) != 0) {
      DAT_801d2938 = 10;
    }
    if ((((obj->field_0x58 & 0xc0) != 0) && (DAT_801d2936 = 10, obj->field_0x51 == '\0')) &&
       ((obj->field_0x33 & 0x80) != 0)) {
      iVar1 = obj->speed_x;
      obj->sub3 = 5;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 3;
      }
      obj->speed_x = iVar1 >> 2;
      obj->gravity = 0x3000;
      obj->hitbox = &DAT_801dba54;
      obj->speed_y_up = 0x43e2a;
      obj->dmg_table = 0x1d;
      Anim_Set(obj,8);
    }
  }
  return;
}


// ---- 801da578 FUN_801da578

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da578(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    obj->sub3 = 3;
    Anim_Set(obj,9);
    if ((obj->field_0x58 & 0x30) != 0) {
      obj->speed_x = -obj->speed_x;
      obj->flip = obj->flip ^ 0x40;
    }
    if ((obj->field_0x58 & 0xc0) != 0) {
      obj->speed_y_up = -obj->speed_y_up;
      obj->flip = obj->flip ^ 0x80;
    }
  }
  return;
}


// ---- 801da618 FUN_801da618

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da618(MM8Obj *obj)

{
  FUN_80104ccc();
  if (obj->speed_y_up < 1) {
    obj->box2 = &DAT_801dba48;
  }
  else {
    obj->box2 = &DAT_801dba4d;
  }
  FUN_8010910c(obj);
  Anim_Step(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->sub3 = 6;
    obj->field_0x43 = 0;
    Anim_Set(obj,6);
  }
  return;
}


// ---- 801da6ac FUN_801da6ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da6ac(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801da72c FUN_801da72c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da72c(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    obj->flip = 0;
    obj->speed_y_up = 0x59943;
    obj->sub3 = 1;
    obj->field_0x43 = 1;
    obj->gravity = 0x3000;
    obj->speed_x = (0x9a00000 - *(int *)&obj->x_frac) / 0x3a;
    FUN_800fcb80(0x35);
    Anim_Set(obj,3);
    FUN_801119e0(0x8e0,0x40);
  }
  Anim_Step(obj);
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if (obj->field_0x4 == '\0') {
    if (obj->speed_y_up < 0) {
      obj->field_0x4 = 1;
      Anim_Set(obj,4);
    }
  }
  else if ((obj->field_0x33 & 0x80) != 0) {
    obj->sub2 = 1;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->field_0x43 = 0;
    Anim_Set(obj,6);
    FUN_801dae08();
  }
  return;
}


// ---- 801da858 FUN_801da858

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da858(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    obj->sub2 = 2;
    Anim_Set(obj,2);
  }
  return;
}


// ---- 801da8a0 FUN_801da8a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da8a0(MM8Obj *obj)

{
  Anim_Step();
  if (DAT_8015e2b0 != '\0') {
    obj->sub2 = 3;
    obj->sub3 = 0;
    FUN_801dad20(obj,4,0x40);
    FUN_801dad20(obj,5,0);
    FUN_801dad20(obj,6,0);
    FUN_801dad20(obj,7,0);
    obj->field_0x50 = 1;
    FUN_801037e0(0x14);
  }
  return;
}


// ---- 801da934 FUN_801da934

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da934(MM8Obj *obj)

{
  undefined1 *puVar1;
  
  Anim_Step();
  FUN_801dae90(obj);
  if ((obj->sub3 == 3) && (puVar1 = (undefined1 *)Obj_AllocMain(), puVar1 != (undefined1 *)0x0)) {
    obj->sub2 = 4;
    obj->sub3 = 0;
    *puVar1 = 1;
    puVar1[6] = 0x58;
                    /* Possible PsyQ macro: setSprt16() + setSemiTrans(sprt16, 1) +
                       setShadeTex(sprt16, 1) */
    puVar1[7] = 0;
    obj->accel_x = (int)puVar1;
    DAT_801b29a7 = 0;
  }
  return;
}


// ---- 801dad20 FUN_801dad20

void FUN_801dad20(int param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
                    /* Possible PsyQ macro: setTile8() */
  puVar1 = (undefined1 *)Obj_AllocType3();
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[6] = 0x30;
    puVar1[0x39] = 3;
    *puVar1 = 1;
    puVar1[7] = param_2;
    puVar1[0x25] = param_3;
                    /* Possible PsyQ macro: setPolyGT4() */
    puVar1[0x38] = 1;
    *(int *)(puVar1 + 0x1c) = param_1 + 0x50;
  }
  return;
}


// ---- 801dad94 FUN_801dad94

void FUN_801dad94(undefined4 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x55;
    puVar1[7] = 0;
    *(undefined4 *)(puVar1 + 0x50) = param_1;
  }
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x55;
    puVar1[7] = 2;
    *(undefined4 *)(puVar1 + 0x50) = param_1;
  }
  return;
}


// ---- 801dae08 FUN_801dae08

void FUN_801dae08(void)

{
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  DAT_801b298b = 0;
  DAT_8015e2be = 1;
  DAT_8015e2b9 = 1;
  DAT_8015e2c5 = 1;
  DAT_8016dc08 = 0;
  return;
}


// ---- 801dae54 FUN_801dae54

void FUN_801dae54(void)

{
  DAT_801b2992 = 0;
  DAT_801b2993 = 0;
  DAT_801b2994 = 0;
  DAT_801b298b = 1;
  DAT_8015e2be = 0;
  DAT_8015e2b9 = 0;
  return;
}


// ---- 801dae90 FUN_801dae90

void FUN_801dae90(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 3);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      if (DAT_801c73e8 != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 3) = 3;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    if (DAT_801c73e8 == '\x04') {
      *(undefined1 *)(param_1 + 3) = 1;
      Anim_Set(param_1,1);
    }
  }
  if (DAT_801c73e8 == '\x05') {
    *(undefined1 *)(param_1 + 3) = 2;
    Anim_Set(param_1,2);
  }
  return;
}


// ---- 801daf5c FUN_801daf5c

void FUN_801daf5c(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(param_1 + 3);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
                    /* Possible PsyQ macro: setTile16() */
      if (DAT_801c73e8 == '\0') {
        *(undefined1 *)(param_1 + 3) = 3;
      }
      if (DAT_801c73e8 != '\x02') {
        return;
      }
      *(undefined1 *)(param_1 + 3) = 1;
      uVar2 = 0x4a;
      goto LAB_801db028;
    }
    if (bVar1 != 0) {
      return;
    }
    if (DAT_801c73e8 == '\x02') {
      *(undefined1 *)(param_1 + 3) = 1;
      FUN_80111f68(0x4a,0x40);
    }
  }
  if (DAT_801c73e8 != '\x03') {
    return;
  }
  *(undefined1 *)(param_1 + 3) = 2;
  uVar2 = 2;
LAB_801db028:
  FUN_80111f68(uVar2,0x40);
  return;
}


