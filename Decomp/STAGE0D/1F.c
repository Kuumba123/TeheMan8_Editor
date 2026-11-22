// ID 1F, STAGE0D.BIN, handler 0x801D856C. Ghidra output with the object struct applied; not matching C.
// ---- 801d856c FUN_801d856c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d856c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8140)[obj->state])();
  return;
}


// ---- 801d85a8 FUN_801d85a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d85a8(MM8Obj *obj)

{
  Enemy_InitFromTable();
  if ((obj->var & 0x7f) == 0) {
    FUN_801d85fc(obj);
  }
  else {
    FUN_801d87dc(obj);
  }
  return;
}


// ---- 801d85fc FUN_801d85fc

void FUN_801d85fc(undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  *(short *)(param_1 + 0xe) = DAT_801d2928 + 0x110;
  *(short *)(param_1 + 0x12) = DAT_801d292a + -0x80;
  if ((param_1[7] & 0x80) == 0) {
    FUN_80103794(0x20,0xab,6);
    uVar3 = 0x30;
    uVar4 = 0xb1;
    uVar5 = 1;
  }
  else {
    uVar3 = 0x2a;
    uVar4 = 0x37;
    uVar5 = 6;
  }
  FUN_80103794(uVar3,uVar4,uVar5);
  param_1[0x49] = 3;
                    /* Possible PsyQ macro: setPolyGT4() */
  *(undefined1 **)(param_1 + 0x4c) = &DAT_80060000;
  *(undefined **)(param_1 + 0x3c) = &DAT_801f8090;
  *(undefined **)(param_1 + 0x38) = &DAT_801f80d4;
  param_1[0x57] = 0;
  param_1[0x26] = 7;
  param_1[0x25] = 0;
  param_1[0x55] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x56] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x54] = 0;
  Anim_Set(param_1,0x19);
  FUN_80103224(param_1);
  uVar6 = 0;
  puVar2 = param_1;
  do {
    puVar1 = (undefined1 *)FUN_801055e4(puVar2);
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar1[6] = 0x1f;
      puVar1[7] = (char)uVar6 + '\x01';
      *(undefined1 **)(puVar1 + 0x4c) = param_1;
      *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      puVar1[0x25] = param_1[0x25];
      puVar2 = puVar1;
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 2);
  if ((DAT_801b1ebc == '\0') || ((param_1[7] & 0x80) != 0)) {
    puVar2 = (undefined1 *)Obj_AllocType4();
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x20;
      *(undefined1 **)(param_1 + 0x58) = puVar2;
    }
    FUN_801db77c(param_1,1,(int)*(short *)(param_1 + 0xe),2);
  }
  param_1[1] = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ---- 801d87dc FUN_801d87dc

void FUN_801d87dc(int param_1)

{
  int iVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 0x27) = 0x56;
  iVar1 = *(int *)(param_1 + 0x4c);
  *(undefined2 *)(param_1 + 0x2c) = DAT_801703f4;
  *(undefined1 *)(param_1 + 0x24) = DAT_80159fba;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined1 *)(param_1 + 0x5e) = 0;
  if (*(char *)(param_1 + 7) == '\x01') {
    *(undefined1 *)(param_1 + 0x26) = 7;
    Anim_Set(param_1,0x33);
  }
  else {
    *(undefined1 *)(param_1 + 0x26) = 6;
    Anim_Set(param_1,0x34);
    uVar2 = (uint)*(ushort *)(param_1 + 0xe);
    if ((DAT_801b1ebc == '\0') || ((*(byte *)(iVar1 + 7) & 0x80) != 0)) {
                    /* Probable PsyQ macro: setPolyGT4() */
      iVar1 = (int)((uVar2 - 0x5c) * 0x10000) >> 0x10;
      FUN_801db77c(param_1,6,iVar1,2);
      FUN_801db77c(param_1,0x86,iVar1,2);
      iVar1 = (int)((uVar2 - 0x1b) * 0x10000) >> 0x10;
      FUN_801db77c(param_1,7,iVar1,2);
      FUN_801db77c(param_1,0x87,iVar1,2);
      FUN_801db77c(param_1,0x88,(int)((uVar2 - 0x3c) * 0x10000) >> 0x10,2);
    }
  }
  *(undefined1 *)(param_1 + 1) = 3;
  return;
}


// ---- 801d892c FUN_801d892c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d892c(MM8Obj *obj)

{
  undefined1 uVar1;
  
  uVar1 = obj->field_0x51;
  obj->field_0x51 = 0;
  obj->field_0x53 = uVar1;
                    /* Possible PsyQ macro: setTile16() */
  (*(code *)(&PTR_FUN_801f8154)[obj->sub2])();
  FUN_80103184(obj);
  Obj_CullAndQueueDrawMargin(obj,0x40);
  return;
}


// ---- 801d8990 FUN_801d8990

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8990(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    if ((DAT_801d2918._2_2_ == DAT_801d2928) && (DAT_801b299e == '\0')) {
      DAT_801b2992 = 1;
      DAT_801b2993 = 1;
      DAT_801b2994 = 1;
      if (((obj->var & 0x80) == 0) && (DAT_801b1ebc != '\0')) {
        FUN_80111e10();
        Obj_Free(obj);
      }
      else {
        FUN_801119e0(DAT_801d2928 + 0x70,0x40);
        FUN_800fcb80(7);
        obj->sub3 = 1;
      }
    }
  }
  else {
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
    if ((DAT_8015e2b0 == '\x01') && (DAT_801cf53c == '\0')) {
      obj->sub2 = 1;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801d8aa4 FUN_801d8aa4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8aa4(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801f8160)[obj->sub3])();
  return;
}


// ---- 801d8c70 FUN_801d8c70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8c70(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f816c)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801d8cc0 FUN_801d8cc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8cc0(MM8Obj *obj)

{
  obj->speed_y_up = -0x80000;
  obj->speed_x = 0;
  obj->field_0x51 = 1;
  obj->field_0x52 = 0x29;
  Anim_Set(obj,0x14);
  FUN_8010544c(obj,0xb8);
  obj->sub3 = 1;
  return;
}


// ---- 801d8d20 FUN_801d8d20

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8d20(MM8Obj *obj)

{
  FUN_80104c34();
  if ((DAT_801d292a + 0x50 < (int)obj->y) && (FUN_80106214(obj), (obj->field_0x33 & 0x80) != 0)) {
    DAT_801d2936 = 0x78;
    obj->sub3 = 2;
    obj->field_0x51 = 8;
    obj->field_0x5e = 1;
    FUN_8010544c(obj,0xbe);
    obj->hp = 0;
    DAT_801b297c = obj;
    Anim_Set(obj,0x15);
  }
  return;
}


// ---- 801d8dc4 FUN_801d8dc4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8dc4(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x2d;
    Anim_Set(obj,0x16);
    FUN_800fd100(0x13e);
    obj->sub3 = 3;
  }
  return;
}


// ---- 801d8e1c FUN_801d8e1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8e1c(MM8Obj *obj)

{
  if (obj->anim_extra != 0) {
    FUN_8010544c(obj,0xb9);
  }
  obj->hp = obj->hp + ((byte)DAT_80170574 & 1);
  if (0x27 < obj->hp) {
                    /* Possible PsyQ macro: setPolyF4() */
    obj->hp = 0x28;
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x2f;
    Anim_Set(obj,0x17);
    obj->sub3 = 4;
  }
  return;
}


// ---- 801d8eac FUN_801d8eac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8eac(MM8Obj *obj)

{
  byte bVar1;
  
  if (((short)obj->frame < 0) && (DAT_801cf53c == '\0')) {
    bVar1 = Rand();
    obj->sub3 = (bVar1 & 1) + 5;
    obj->field_0x51 = 1;
    obj->field_0x4 = 0;
    obj->field_0x52 = 0x33;
    Anim_Set(obj,0x19);
  }
  return;
}


// ---- 801d8f28 FUN_801d8f28

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8f28(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    FUN_8010544c(obj,0xba);
    obj->field_0x50 = 0xaa;
    obj->field_0x4 = 1;
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_800fcb80(8);
    obj->sub3 = 7;
  }
  return;
}


// ---- 801d8fa0 FUN_801d8fa0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8fa0(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
                    /* Possible PsyQ macro: setLineF2() */
  bVar1 = obj->field_0x4;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      cVar2 = obj->field_0x50 + -1;
      obj->field_0x50 = cVar2;
      if (cVar2 != '\0') {
        return;
      }
      FUN_800fcb80(8);
      obj->sub3 = 7;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    FUN_8010544c(obj,0xbb);
    obj->field_0x50 = 0x3c;
    obj->field_0x4 = 1;
  }
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
    FUN_8010544c(obj,0xbc);
    obj->field_0x50 = 0x50;
    obj->field_0x4 = 2;
  }
  return;
}


// ---- 801d90d4 FUN_801d90d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d90d4(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  obj->field_0x53 = obj->field_0x51;
  (*(code *)(&PTR_FUN_801f818c)[obj->sub2])();
  bVar2 = 0x20;
  if ((obj->var & 0x80) != 0) {
    bVar2 = 0x2a;
  }
  obj->clut = bVar2;
  if (obj->field_0x57 == '\0') {
    cVar1 = FUN_801db370(obj);
                    /* Possible PsyQ macro: setLineF2() */
    if (cVar1 == '\x04') {
      DAT_8015e2af = 1;
      obj->state = 4;
      obj->sub2 = 0;
      obj->sub3 = 0;
      return;
    }
    if (cVar1 == '\x02') {
      obj->field_0x57 = 0x3c;
      FUN_8010544c(obj,0xc9);
      FUN_8010544c(obj,0x10);
      if ((DAT_80158f5c == '\x06') && ((obj->active & 0x80) != 0)) {
        obj->sub2 = 8;
        obj->sub3 = 0;
      }
    }
  }
  else {
    bVar2 = obj->hp;
    obj->hp = 0x3f;
    cVar1 = FUN_801db370(obj);
    if (cVar1 == '\x02') {
      FUN_8010544c(obj,0x4f);
    }
    obj->hp = bVar2;
    bVar2 = obj->field_0x57 - 1;
    obj->field_0x57 = bVar2;
    if ((bVar2 & 1) != 0) {
      obj->clut = 0;
    }
  }
  switchD_801db3f8::caseD_0(obj);
  FUN_80103184(obj);
  Obj_CullAndQueueDrawMargin(obj,0x40);
  FUN_801db5e8(obj);
  return;
}


// ---- 801d9250 FUN_801d9250

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9250(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  obj->field_0x51 = 0;
  obj->field_0x5e = 0;
  obj->field_0x54 = 0;
  FUN_8010910c();
                    /* Probable PsyQ macro: setLineF2() */
  iVar2 = (int)obj->x - (int)DAT_8015e248._2_2_;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (obj->field_0x55 == '\0') {
    bVar1 = 2;
    if (0xb3 < iVar2) {
      bVar1 = 1;
    }
    obj->sub2 = bVar1;
    obj->field_0x55 = 1;
    goto LAB_801d9400;
  }
  if (obj->hp < 0x14) {
    uVar3 = Rand();
    bVar1 = (&DAT_801f80ec)[uVar3 & 0xf];
  }
  else {
    uVar3 = Rand();
                    /* Possible PsyQ macro: setLineF2() */
    bVar1 = (&DAT_801f80dc)[uVar3 & 0xf];
  }
  if (bVar1 == 6) goto LAB_801d9368;
                    /* Possible PsyQ macro: setSprt16() + setShadeTex(sprt16, 1) */
  if (bVar1 == 7) {
                    /* Possible PsyQ macro: setLineF2() */
    if (obj->flip == 0) {
      if (DAT_801d2928 + 0xb0 < (int)obj->x) {
LAB_801d9368:
        if (5 < DAT_801b29a0) goto LAB_801d939c;
      }
    }
    else if ((int)obj->x < DAT_801d2928 + 0x100) goto LAB_801d9368;
    uVar3 = Rand();
                    /* Probable PsyQ macro: setTile16() */
    bVar1 = (&DAT_801f80fc)[uVar3 & 0xf];
  }
LAB_801d939c:
  if (bVar1 == 3) {
    if (obj->flip != 0) {
      if (DAT_801d2928 + 0x120 <= (int)obj->x) goto LAB_801d93f4;
      goto LAB_801d93f8;
    }
    if ((int)obj->x <= DAT_801d2928 + 0x90) {
LAB_801d93f4:
      bVar1 = 5;
      goto LAB_801d93f8;
    }
    obj->sub2 = 3;
  }
  else {
LAB_801d93f8:
    obj->sub2 = bVar1;
  }
  obj->field_0x55 = 0;
LAB_801d9400:
  if (obj->field_0x5f != '\0') {
    obj->sub2 = 4;
  }
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801d9430 FUN_801d9430

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9430(MM8Obj *obj)

{
  obj->field_0x51 = 0;
  (*(code *)(&PTR_FUN_801f81b0)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801d9480 FUN_801d9480

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9480(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,5);
    obj->field_0x52 = 10;
    obj->field_0x51 = 1;
    obj->hitbox = &DAT_801f8094;
    obj->field_0x4 = 1;
  }
  else if ((short)obj->frame < 0) {
    if ((obj->flip & 0x40) == 0) {
                    /* Possible PsyQ macro: setLineF2() */
      iVar2._0_2_ = obj->x_frac;
      iVar2._2_2_ = obj->x;
      iVar1 = DAT_801d2928 + 0x60;
    }
    else {
      iVar2._0_2_ = obj->x_frac;
      iVar2._2_2_ = obj->x;
      iVar1 = DAT_801d2928 + 0x130;
    }
                    /* Possible PsyQ macro: setPolyF4() */
    obj->speed_x = (iVar1 * 0x10000 - iVar2) / 0x36;
    obj->speed_y_up = 0x4f555;
    obj->gravity = 0x3000;
    obj->field_0x43 = 1;
    obj->field_0x54 = 1;
    FUN_8010544c(obj,0xc3);
                    /* Probable PsyQ macro: setTile16() */
    obj->field_0x51 = 1;
    obj->field_0x52 = 0xc;
    Anim_Set(obj,6);
    obj->sub3 = 1;
  }
  return;
}


// ---- 801d95a0 FUN_801d95a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d95a0(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyF4() */
  FUN_80104ccc();
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x27;
    Anim_Set(obj,0x13);
    FUN_8010544c(obj,0xbe);
    obj->speed_y_up = 0;
    obj->field_0x43 = 0;
    obj->field_0x54 = 0;
    DAT_801d2936 = 0x3c;
    obj->sub3 = 2;
  }
  return;
}


// ---- 801d9628 FUN_801d9628

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9628(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  iVar2 = obj->speed_x;
  iVar1 = iVar2;
  if (iVar2 < 0) {
    iVar1 = -iVar2;
  }
  if (iVar1 < 0x10000) {
    iVar1 = -0x10000;
    if (0 < iVar2) {
      iVar1 = 0x10000;
    }
    obj->speed_x = iVar1;
  }
  FUN_80104c34(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x33;
    obj->flip = obj->flip ^ 0x40;
    Anim_Set(obj,0x19);
                    /* Possible PsyQ macro: setLineF2() */
    obj->hitbox = &DAT_801f8090;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801d96dc FUN_801d96dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d96dc(MM8Obj *obj)

{
  obj->field_0x51 = 0;
  (*(code *)(&PTR_FUN_801f81bc)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801d972c FUN_801d972c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d972c(MM8Obj *obj)

{
  int iVar1;
  
                    /* Possible PsyQ macro: setSprt16() + setShadeTex(sprt16, 1) */
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,0x11);
                    /* Possible PsyQ macro: setLineF2() */
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x23;
    obj->field_0x4 = 1;
  }
  else if ((short)obj->frame < 0) {
    iVar1 = *(int *)&obj->x_frac - DAT_8015e248;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    obj->speed_x = iVar1 / 0x42;
    if ((obj->flip & 0x40) == 0) {
      obj->speed_x = -(iVar1 / 0x42);
    }
    obj->speed_y_up = 0x610f8;
    obj->gravity = 0x3000;
    obj->field_0x43 = 1;
    obj->field_0x54 = 2;
    FUN_8010544c(obj,0xc3);
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x25;
    Anim_Set(obj,0x12);
    obj->sub3 = 1;
  }
                    /* Probable PsyQ macro: setTile() */
  return;
}


// ---- 801d9830 FUN_801d9830

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9830(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_8015e248;
  if ((short)obj->frame < 0) {
    obj->field_0x51 = 1;
                    /* Probable PsyQ macro: setTile16() */
    iVar2._0_2_ = obj->x_frac;
    iVar2._2_2_ = obj->x;
    obj->field_0x52 = 0x33;
    obj->flip = (iVar2 <= iVar1) << 6;
    Anim_Set(obj,0x19);
    obj->sub2 = 0;
    obj->sub3 = 0;
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801d98a4 FUN_801d98a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d98a4(MM8Obj *obj)

{
  obj->field_0x51 = 0;
  (*(code *)(&PTR_FUN_801f81c8)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801d98f4 FUN_801d98f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d98f4(MM8Obj *obj)

{
  byte bVar1;
  
                    /* Possible PsyQ macro: setPolyGT4() */
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,0);
    obj->field_0x51 = 1;
    obj->field_0x52 = 0;
    obj->field_0x56 = 0;
    obj->field_0x4 = 1;
    obj->field_0x50 = 0;
    obj->field_0x5e = 0;
  }
  if (obj->anim_extra != 0) {
    bVar1 = obj->field_0x50 + 1;
    obj->field_0x54 = 3;
    obj->field_0x50 = bVar1;
    obj->active = obj->active | 0x80;
    if ((uint)bVar1 % 0xc == 0) {
      FUN_801db668(obj,&DAT_801f8120,6);
    }
  }
  if ((short)obj->frame < 0) {
    obj->sub3 = 1;
    obj->field_0x51 = 1;
    obj->field_0x4 = 0;
    obj->field_0x52 = 2;
    Anim_Set(obj,1);
  }
  return;
}


// ---- 801d99ec FUN_801d99ec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d99ec(MM8Obj *obj)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
                    /* Possible PsyQ macro: setPolyGT4() */
  if ((short)obj->frame < 0) {
    obj->sub3 = 2;
    obj->field_0x51 = 1;
    obj->field_0x52 = 4;
    obj->active = 1;
    obj->field_0x54 = 0;
    Anim_Set(obj,2);
    FUN_8010544c(obj,0xc0);
                    /* Possible PsyQ macro: setPolyGT4() */
  }
  bVar1 = obj->field_0x50 + 1;
  obj->field_0x50 = bVar1;
  if ((uint)bVar1 % 0xc == 0) {
    uVar4 = 6;
    if (obj->anim_extra != 0) {
      uVar4 = 10;
    }
    FUN_801db668(obj,&DAT_801f8120,uVar4);
  }
  if (obj->anim_extra != 0) {
    iVar5 = 0;
    if (obj->field_0x4 == '\0') {
      FUN_8010544c(obj,0xc6);
      obj->field_0x4 = 1;
    }
    do {
      iVar3 = switchD_801db3f8::default(obj,3,0xffffffed,0xffffffa7);
      iVar5 = iVar5 + 1;
      if (iVar3 != 0) {
        uVar2 = Rand();
        *(ushort *)(iVar3 + 0xc) = (uVar2 & 3) + 0x20;
        uVar2 = Rand();
        *(ushort *)(iVar3 + 0x10) = uVar2 & 0xff;
        *(MM8Obj **)(iVar3 + 0x20) = obj;
      }
    } while (iVar5 < 2);
  }
  return;
}


// ---- 801d9b4c FUN_801d9b4c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9b4c(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (obj->anim_extra != 0) {
    DAT_801d2936 = 0x28;
    FUN_8010544c(obj,0xc1);
    cVar3 = -0x48;
    uVar5 = 0x1c;
    uVar6 = 0;
    obj->anim_extra = 0;
    do {
      iVar2 = FUN_801db490(obj,uVar6 & 0xff,(int)cVar3,uVar5);
      cVar3 = -0x3c;
      if (iVar2 != 0) {
        bVar1 = obj->flip;
        *(MM8Obj **)(iVar2 + 0x4c) = obj;
        *(byte *)(iVar2 + 0x51) = bVar1;
      }
      uVar6 = uVar6 + 1;
      uVar5 = 0x24;
    } while (uVar6 < 2);
  }
  if ((short)obj->frame < 0) {
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x33;
    Anim_Set(obj,0x19);
    if ((obj->flip & 0x40) == 0) {
      sVar4 = DAT_801d2928 + 0x10;
    }
    else {
      sVar4 = DAT_801d2928 + 400;
    }
                    /* Possible PsyQ macro: setPolyF4() */
    iVar2 = (int)obj->x - (int)sVar4;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    obj->sub3 = 3;
    obj->field_0x50 = (char)(iVar2 / 0x18) + '\x1e';
  }
  FUN_801db6cc(obj);
  return;
}


// ---- 801d9c90 FUN_801d9c90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9c90(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801db6cc();
                    /* Possible PsyQ macro: setPolyGT3() */
  if (obj->field_0x56 == '\x02') {
    obj->sub2 = 4;
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 != '\0') {
      return;
    }
                    /* Probable PsyQ macro: setTile16() */
    obj->sub2 = 0;
  }
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801d9cf8 FUN_801d9cf8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9cf8(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  obj->field_0x51 = 0;
  (*(code *)(&PTR_FUN_801f81d8)[obj->sub3])();
  return;
}


// ---- 801d9d34 FUN_801d9d34

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9d34(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = -0x60000;
  if ((obj->flip & 0x40) != 0) {
    iVar1 = 0x60000;
  }
  obj->speed_y_up = 0x20700;
  obj->gravity = 0x3000;
  obj->field_0x51 = 2;
  obj->speed_x = iVar1;
  obj->field_0x52 = 0x1a;
  Anim_Set(obj,0xc);
  FUN_8010544c(obj,200);
                    /* Possible PsyQ macro: setLineF2() */
  obj->sub3 = 1;
  Anim_Step();
  return;
}


// ---- 801d9dc0 FUN_801d9dc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9dc0(MM8Obj *obj)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  if (obj->anim_extra != 0) {
    FUN_80104ccc();
  }
  if (obj->field_0x5f != '\0') {
    FUN_80107bf4(obj,&g_player,1);
    uVar2 = 0x20;
    if (obj->speed_x < 1) {
      uVar2 = 0x10;
      bVar3 = 0x20;
    }
    else {
      bVar3 = 0x10;
    }
    uVar1 = FUN_80107bf4(obj,&g_player,1);
    if (((uVar1 & uVar2) != 0) && ((DAT_8015e26f & bVar3) != 0)) {
      FUN_801db740(obj);
    }
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->speed_y_up = 0;
    obj->gravity = 0;
  }
  if (((obj->field_0x33 & 0x30) != 0) && (obj->speed_y_up == 0)) {
    DAT_801d2936 = 0x1e;
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  if (obj->anim_extra == 0) {
    Anim_Step(obj);
  }
  return;
}


// ---- 801d9ef4 FUN_801d9ef4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ef4(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -0x1800;
  if (obj->field_0x4 == '\0') {
    iVar1 = obj->speed_x;
    obj->speed_x = -iVar1;
    if (-iVar1 < 0) {
      iVar2 = 0x1800;
    }
    obj->accel_x = iVar2;
    obj->field_0x51 = 3;
    if (obj->field_0x5f != '\0') {
      FUN_801db740(obj);
    }
    obj->field_0x4 = 1;
  }
  FUN_80104c9c(obj);
  FUN_80106214(obj);
  if ((obj->speed_x == 0) || ((obj->speed_x & 0x80000000U) == (obj->accel_x & 0x80000000U))) {
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x2d;
    Anim_Set(obj,0x16);
    obj->field_0x50 = 0x5a;
    obj->field_0x54 = 3;
    obj->sub3 = 3;
                    /* Possible PsyQ macro: setPolyF3() */
    obj->field_0x4 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801d9fd4 FUN_801d9fd4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9fd4(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x51 = 1;
      obj->field_0x52 = 0x2f;
      Anim_Set(obj,0x17);
      obj->field_0x4 = 1;
    }
  }
  else if ((short)obj->frame < 0) {
    obj->field_0x54 = 0;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801da070 FUN_801da070

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da070(MM8Obj *obj)

{
  obj->field_0x51 = 0;
  (*(code *)(&PTR_FUN_801f81e8)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801da0c0 FUN_801da0c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da0c0(MM8Obj *obj)

{
  obj->field_0x51 = 1;
  obj->field_0x52 = 0x16;
  Anim_Set(obj,10);
  obj->field_0x50 = 0;
  obj->field_0x5e = 0;
  obj->speed_y_up = 0;
  obj->sub3 = 1;
  obj->field_0x4 = 0;
  return;
}


// ---- 801da118 FUN_801da118

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da118(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  if (((obj->anim_extra & 0x80) != 0) &&
     (bVar1 = obj->field_0x50 + 1, obj->field_0x50 = bVar1, (uint)bVar1 % 6 == 0)) {
                    /* Possible PsyQ macro: setPolyGT3() */
    FUN_801db668(obj,&DAT_801f8134,3);
  }
  if (obj->field_0x4 == '\0') {
                    /* Probable PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setPolyGT4() */
    if ((obj->anim_extra & 0x7f) == 0) {
      return;
    }
    iVar2 = switchD_801db3f8::default(obj,4,0,0);
    if (iVar2 != 0) {
      *(MM8Obj **)(iVar2 + 0x20) = obj;
    }
    obj->field_0x4 = 1;
    return;
  }
  if (-1 < (short)obj->frame) {
    return;
  }
  obj->field_0x51 = 4;
  obj->field_0x52 = 0x18;
  Anim_Set(obj,0xb);
  FUN_8010544c(obj,0xc2);
  iVar2 = 0x500000;
  if ((obj->flip & 0x40) == 0) {
    iVar2 = -0x500000;
  }
  iVar2 = (DAT_8015e248 - (*(int *)&obj->x_frac + iVar2)) / 0x18;
  obj->speed_x = iVar2;
  if (obj->flip == 0) {
    if (iVar2 < 1) goto LAB_801da280;
  }
  else if (-1 < iVar2) goto LAB_801da280;
  obj->speed_x = 0;
  obj->field_0x50 = 1;
LAB_801da280:
  obj->field_0x50 = 0x1c;
  obj->sub3 = 2;
  obj->active = obj->active | 0x80;
  return;
}


// ---- 801da2ac FUN_801da2ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da2ac(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  FUN_80104c34();
  FUN_80106214(obj);
  if ((((obj->field_0x50 == '\0') ||
       (obj->field_0x50 = obj->field_0x50 + -1, obj->field_0x50 == '\0')) ||
      ((obj->field_0x33 & 0x30) != 0)) && ((short)obj->frame < 0)) {
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x44;
    Anim_Set(obj,0x1b);
    obj->active = 1;
    obj->sub3 = 3;
  }
  return;
}


// ---- 801da39c FUN_801da39c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da39c(MM8Obj *obj)

{
  obj->field_0x51 = 0;
  (*(code *)(&PTR_FUN_801f81f8)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801da3ec FUN_801da3ec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da3ec(MM8Obj *obj)

{
  *(undefined1 *)(*(int *)&obj->field_0x58 + 0x15) = 1;
  obj->field_0x51 = 1;
  obj->field_0x52 = 6;
  Anim_Set(obj,3);
  obj->speed_y_up = 0x20710;
  obj->speed_x = 0;
  obj->gravity = 0x3000;
  obj->field_0x50 = 6;
  obj->sub3 = 1;
  return;
}


// ---- 801da460 FUN_801da460

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da460(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    obj->field_0x51 = 4;
                    /* Possible PsyQ macro: setPolyF3() */
    obj->field_0x52 = 8;
    Anim_Set(obj,4);
    obj->field_0x43 = 1;
    obj->sub3 = 2;
  }
  return;
}


// ---- 801da4b8 FUN_801da4b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da4b8(MM8Obj *obj)

{
  char cVar1;
  
  FUN_80104ccc();
  FUN_80106214(obj);
  if (((obj->field_0x33 & 0x80) != 0) && (obj->gravity != 0)) {
    FUN_8010544c(obj,0xbe);
    obj->gravity = 0;
    obj->field_0x43 = 0;
    DAT_801d2936 = 0x1e;
    obj->field_0x5c = 1;
  }
  cVar1 = obj->field_0x5c + -1;
  obj->field_0x5c = cVar1;
  if (cVar1 == '\0') {
    if (obj->field_0x50 != '\0') {
      *(char *)(*(int *)&obj->field_0x58 + 0x15) = obj->field_0x50 + '\x01';
      obj->field_0x50 = obj->field_0x50 + -1;
    }
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
    obj->field_0x5c = 0x26;
    obj->anim_extra = 0;
  }
  if ((obj->anim_extra & 0xf0) != 0) {
    FUN_8010544c(obj,(&DAT_801f813b)[obj->anim_extra >> 4]);
    obj->anim_extra = obj->anim_extra & 0xf;
  }
  if ((obj->anim_extra & 0xf) != 0) {
    DAT_801d2936 = 0x1e;
    FUN_8010544c(obj,0xc1);
    obj->anim_extra = 0;
  }
  if (((short)obj->frame < 0) && (DAT_801d2936 = 1, obj->field_0x50 == '\0')) {
    obj->field_0x50 = 0x1e;
    obj->sub3 = 3;
  }
  return;
}


// ---- 801da668 FUN_801da668

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da668(MM8Obj *obj)

{
  obj->field_0x51 = 0;
  (*(code *)(&PTR_FUN_801f8208)[obj->sub3])();
  return;
}


// ---- 801da6a4 FUN_801da6a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da6a4(MM8Obj *obj)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = Rand();
  uVar1 = (&DAT_801f810c)[uVar2 & 7];
  obj->sub3 = 1;
  obj->field_0x50 = uVar1;
  return;
}


// ---- 801da6e8 FUN_801da6e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da6e8(MM8Obj *obj)

{
  undefined1 uVar1;
  
  uVar1 = 0x11;
  if ((obj->flip & 0x40) != 0) {
    uVar1 = 0x12;
  }
  *(undefined1 *)(*(int *)&obj->field_0x58 + 0x15) = uVar1;
  *(short *)(*(int *)&obj->field_0x58 + 0x16) = obj->x;
  obj->field_0x51 = 1;
  obj->field_0x52 = 0xe;
  Anim_Set(obj,7);
  obj->sub3 = 2;
  return;
}


// ---- 801da758 FUN_801da758

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da758(MM8Obj *obj)

{
  undefined1 uVar1;
  uint uVar2;
  
  if ((short)obj->frame < 0) {
    if (obj->field_0x50 == '\x01') {
      obj->field_0x5d = 0;
    }
    else {
      uVar2 = Rand();
      obj->field_0x5d = (&DAT_801f8114)[uVar2 & 7];
    }
    uVar1 = (&DAT_801f811c)[(byte)obj->field_0x5d];
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
    obj->sub3 = 3;
    obj->field_0x5c = uVar1;
  }
  Anim_Step(obj);
  return;
}


// ---- 801da7e4 FUN_801da7e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da7e4(MM8Obj *obj)

{
  if (((byte)obj->field_0x5c <= DAT_801b29a1) || (DAT_801b29a1 == 0xff)) {
    obj->field_0x51 = 5;
    obj->field_0x52 = obj->field_0x5d;
    Anim_Set(obj,8);
    FUN_8010544c(obj,0xc2);
    obj->sub3 = 4;
  }
  return;
}


// ---- 801da85c FUN_801da85c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da85c(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    obj->field_0x51 = 1;
    obj->field_0x52 = 0x14;
    Anim_Set(obj,9);
    obj->sub3 = 5;
  }
  Anim_Step(obj);
  return;
}


// ---- 801da8b4 FUN_801da8b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da8b4(MM8Obj *obj)

{
  char cVar1;
  
  if ((short)obj->frame < 0) {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
    else {
      obj->sub3 = 1;
    }
  }
  Anim_Step();
  return;
}


// ---- 801da914 FUN_801da914

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da914(MM8Obj *obj)

{
  obj->field_0x51 = 0;
  (*(code *)(&PTR_LAB_801f8220)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801dab4c FUN_801dab4c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dab4c(MM8Obj *obj)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->field_0x4c;
  if ((*pcVar2 == '\0') || (pcVar2[6] != '\x1f')) {
    Obj_Free(obj);
  }
  else {
    uVar1 = *(undefined4 *)(pcVar2 + 0xc);
    obj->x_frac = (short)uVar1;
    obj->x = (short)((uint)uVar1 >> 0x10);
    uVar1 = *(undefined4 *)(pcVar2 + 0x10);
    obj->y_frac = (short)uVar1;
    obj->y = (short)((uint)uVar1 >> 0x10);
    obj->flip = pcVar2[0x25];
    obj->clut = pcVar2[0x24];
    FUN_801dac4c(obj);
    (*(code *)(&PTR_FUN_801f8234)[obj->sub2])(obj);
                    /* Probable PsyQ macro: setLineF2() */
    if (((obj->var != 2) || (obj->sub2 != 5)) && ((pcVar2[5] != '\0' || (pcVar2[1] != '\x04')))) {
      Obj_CullAndQueueDrawMargin(obj,0x40);
    }
  }
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801dac4c FUN_801dac4c

void FUN_801dac4c(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4c);
  if ((*(char *)(iVar2 + 0x51) != '\0') && (*(char *)(iVar2 + 0x51) != *(char *)(iVar2 + 0x53))) {
    cVar1 = *(char *)(iVar2 + 0x51);
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    *(char *)(param_1 + 2) = cVar1 + -1;
  }
  return;
}


// ---- 801dac90 FUN_801dac90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dac90(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    Anim_Set(obj,*(char *)(*(int *)&obj->field_0x4c + 0x52) + obj->var + -1);
    obj->sub3 = 1;
  }
  if (((short)obj->frame < 0) && (obj->sub2 == 0)) {
    obj->sub2 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801dad14 FUN_801dad14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dad14(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setTile8() */
  if (obj->sub3 == 0) {
    Anim_Set(obj,*(char *)(*(int *)&obj->field_0x4c + 0x52) + obj->var + -1);
    obj->sub3 = 1;
  }
  if ((short)obj->frame < 0) {
    obj->sub2 = 0;
  }
  else {
                    /* Possible PsyQ macro: setPolyGT4() */
    if (obj->anim_extra == 0) {
      Anim_Step(obj);
    }
  }
  return;
}


// ---- 801dad9c FUN_801dad9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dad9c(MM8Obj *obj)

{
  obj->sub2 = 0;
  obj->sub3 = 1;
  obj->anim_extra = 0;
  FUN_801dad14(obj);
  return;
}


// ---- 801dadc8 FUN_801dadc8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dadc8(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x4c;
  if (obj->sub3 == 0) {
    Anim_Set(obj,*(char *)(iVar2 + 0x52) + obj->var + -1);
    obj->sub3 = 1;
  }
  Anim_Step(obj);
  if (obj->anim_extra != 0) {
    obj->hitbox = &UNK_801f80b8 + (uint)obj->anim_extra * 4;
    obj->contact_dmg = 5;
    iVar1 = Enemy_ContactDamage();
    if (iVar1 != 0) {
      *(undefined1 *)(iVar2 + 0x5e) = 6;
    }
  }
  return;
}


// ---- 801dae6c FUN_801dae6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dae6c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x4c;
  if (obj->sub3 == 0) {
    cVar1 = '\x10';
    if (obj->var != 1) {
      cVar1 = *(char *)(iVar2 + 0x52) + '\x11';
    }
    Anim_Set(obj,cVar1);
    obj->sub3 = 1;
  }
  if ((short)obj->frame < 0) {
    obj->sub2 = 0;
  }
  else {
    Anim_Step(obj);
    if (obj->anim_extra == 0) {
      obj->hitbox = (byte *)0x0;
    }
    else {
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
      obj->hitbox = &UNK_801f80bc + (uint)*(byte *)(iVar2 + 0x52) * 4;
      Enemy_ContactDamage();
    }
  }
  return;
}


// ---- 801daf30 FUN_801daf30

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daf30(MM8Obj *obj)

{
  if ((obj->sub3 == 0) && (obj->var == 1)) {
    Anim_Set(obj,0x20);
    obj->sub3 = 1;
  }
  Anim_Step(obj);
  return;
}


// ---- 801daf8c FUN_801daf8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daf8c(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    obj->field_0x5e = 0;
    Anim_Set(obj,obj->var + 0x2a);
    obj->sub3 = 1;
  }
  if ((short)obj->frame < 0) {
    obj->sub2 = 0;
  }
  else {
    Anim_Step(obj);
    if ((obj->anim_extra & 0xf0) != 0) {
                    /* Possible PsyQ macro: setTile16() */
      FUN_8010544c(obj,(&DAT_801f813b)[obj->anim_extra >> 4]);
      obj->anim_extra = obj->anim_extra & 0xf;
    }
    if ((obj->anim_extra & 0xf) == 0) {
      obj->hitbox = (byte *)0x0;
    }
    else {
      FUN_8010544c(obj,0x2c);
      obj->field_0x5e = obj->anim_extra & 0xf;
      DAT_801d2936 = 0x1e;
      obj->anim_extra = 0;
    }
  }
  return;
}


// ---- 801db084 FUN_801db084

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db084(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8254)[obj->sub2])();
  return;
}


// ---- 801db0c0 FUN_801db0c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db0c0(MM8Obj *obj)

{
  obj->field_0x53 = 0;
  obj->field_0x51 = 1;
  obj->field_0x52 = 0x31;
  Anim_Set(obj,0x18);
  if (obj->field_0x5f != '\0') {
    FUN_80111c28();
    obj->field_0x5f = 0;
  }
  if ((obj->var & 0x80) == 0) {
    DAT_801d2926 = DAT_801d2918._2_2_;
    DAT_801d2928 = DAT_801d2918._2_2_;
  }
  DAT_801d292a = g_cam_y;
  DAT_801d292c = g_cam_y;
  FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  *(undefined1 *)(*(int *)&obj->field_0x58 + 0x15) = 0x13;
  FUN_800fcd84();
  obj->sub2 = 1;
  obj->sub3 = 0;
  FUN_80103184(obj);
  Obj_CullAndQueueDrawMargin(obj,0x40);
  return;
}


// ---- 801db1c4 FUN_801db1c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db1c4(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  Anim_Step();
  if (obj->sub3 == 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x50 = 0x3c;
    obj->sub3 = 1;
  }
  if ((obj->field_0x50 & 1) == 0) {
    bVar2 = 0x20;
    if ((obj->var & 0x80) != 0) {
      bVar2 = 0x2a;
    }
    obj->clut = bVar2;
  }
  else {
    obj->clut = 0;
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  bVar2 = 0x20;
  if (cVar1 == '\0') {
                    /* Probable PsyQ macro: setTile8() */
    obj->field_0x50 = 0x78;
    if ((obj->var & 0x80) != 0) {
      bVar2 = 0x2a;
    }
    obj->clut = bVar2;
    obj->sub2 = 2;
    obj->sub3 = 0;
  }
  FUN_80103184(obj);
  Obj_CullAndQueueDrawMargin(obj,0x40);
  return;
}


// ---- 801db298 FUN_801db298

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db298(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if ((obj->field_0x50 & 7) == 0) {
    uVar2 = Rand();
    uVar3 = Rand();
                    /* Possible PsyQ macro: setTile8() */
    FUN_80108ed8(obj,(int)(((uVar2 & 0x7f) - 0x3f) * 0x10000) >> 0x10,
                 (int)(((uVar3 & 0x3f) - 0x1f) * 0x10000) >> 0x10);
  }
  obj->on_screen = 0;
  if ((obj->field_0x50 & 1) != 0) {
    FUN_80103184(obj);
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_8010544c(obj,199);
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->on_screen = 0;
  }
  return;
}


// ---- 801db370 FUN_801db370

char FUN_801db370(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (uint)*(byte *)(param_1 + 0x54) * 2;
  *(undefined **)(param_1 + 0x3c) = &DAT_801f8090 + (uint)(byte)(&DAT_801f80b0)[iVar2] * 4;
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 == '\0') {
    *(undefined **)(param_1 + 0x3c) = &DAT_801f8090 + (uint)(byte)(&DAT_801f80b1)[iVar2] * 4;
    cVar1 = Enemy_CheckWeaponHits();
  }
  return cVar1;
}


// ---- 801db400 caseD_0

char switchD_801db3f8::caseD_0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (uint)*(byte *)(param_1 + 0x54) * 2;
  *(undefined **)(param_1 + 0x3c) = &DAT_801f8090 + (uint)(byte)(&DAT_801f80b0)[iVar2] * 4;
  cVar1 = Enemy_ContactDamage();
  if (cVar1 == '\0') {
    *(undefined **)(param_1 + 0x3c) = &DAT_801f8090 + (uint)(byte)(&DAT_801f80b1)[iVar2] * 4;
    cVar1 = Enemy_ContactDamage();
  }
  return cVar1;
}


// ---- 801db490 FUN_801db490

undefined1 * FUN_801db490(int param_1,undefined1 param_2,char param_3,char param_4)

{
  short sVar1;
  undefined1 *puVar2;
  
                    /* Possible PsyQ macro: setLineF2() */
  puVar2 = (undefined1 *)Obj_AllocMain();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x2c;
    puVar2[7] = param_2;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar1 = (short)param_3;
    }
    else {
      sVar1 = -(short)param_3;
    }
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + sVar1;
    *(short *)(puVar2 + 0x12) = (short)param_4 + *(short *)(param_1 + 0x12);
  }
  return puVar2;
}


// ---- 801db53c default

undefined1 * switchD_801db3f8::default(int param_1,undefined1 param_2,char param_3,char param_4)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x22;
    puVar2[7] = param_2;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar1 = (short)param_3;
    }
    else {
      sVar1 = -(short)param_3;
    }
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + sVar1;
    *(short *)(puVar2 + 0x12) = (short)param_4 + *(short *)(param_1 + 0x12);
  }
  return puVar2;
}


// ---- 801db5e8 FUN_801db5e8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801db5e8(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (_DAT_80170574 == (_DAT_80170574 / 0xf) * 0xf) {
    uVar1 = Rand();
    uVar2 = Rand();
    switchD_801db3f8::default
              (param_1,0,(int)(((uVar1 & 0x3f) - 0x20) * 0x1000000) >> 0x18,uVar2 & 0xf);
  }
  return;
}


// ---- 801db668 FUN_801db668

void FUN_801db668(undefined4 param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    cVar2 = *param_2;
    pcVar1 = param_2 + 1;
    param_2 = param_2 + 2;
    switchD_801db3f8::default(param_1,0,(int)cVar2,(int)*pcVar1);
  }
  return;
}


// ---- 801db6cc FUN_801db6cc

undefined4 FUN_801db6cc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x56) == '\x01') {
    FUN_80111b28();
    FUN_80111cb4(2);
    iVar2 = switchD_801db3f8::default(param_1,8,0,0);
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x20) = param_1;
    }
    *(undefined1 *)(param_1 + 0x5f) = 1;
    uVar1 = 2;
    *(undefined1 *)(param_1 + 0x56) = 2;
  }
  return uVar1;
}


// ---- 801db740 FUN_801db740

void FUN_801db740(int param_1)

{
  FUN_80111c28();
  DAT_8015e2ad = 0;
  FUN_80111d34(4);
  *(undefined1 *)(param_1 + 0x5f) = 0;
  return;
}


// ---- 801db77c FUN_801db77c

void FUN_801db77c(undefined4 param_1,byte param_2,short param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  short sVar5;
  
  if ((param_2 & 0x80) == 0) {
    sVar5 = DAT_801d292a + 0xb0;
  }
  else {
    sVar5 = DAT_801d292a + 0xc0;
  }
  iVar4 = 0;
  if (param_4 != 0) {
    do {
      uVar3 = 9;
      if ((param_2 & 0x80) != 0) {
        uVar3 = 10;
      }
      iVar2 = switchD_801db3f8::default(param_1,uVar3,0,0);
      if (iVar2 != 0) {
        uVar1 = Rand();
        *(ushort *)(iVar2 + 0xe) = param_3 + -0xf + (uVar1 & 0x1f);
        *(short *)(iVar2 + 0x12) = sVar5;
        *(byte *)(iVar2 + 0x3c) = param_2 & 0x7f;
        *(undefined4 *)(iVar2 + 0x20) = param_1;
      }
      iVar4 = iVar4 + 1;
    } while ((uint)(iVar4 * 0x10000 >> 0x10) < param_4);
  }
  return;
}


