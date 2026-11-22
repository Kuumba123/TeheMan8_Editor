// ID 27, STAGE0D.BIN, handler 0x801DCA2C. Ghidra output with the object struct applied; not matching C.
// ---- 801dca2c FUN_801dca2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dca2c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f831c)[obj->state])();
  FUN_80103184(obj);
  return;
}


// ---- 801dca7c FUN_801dca7c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dca7c(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined4 uVar6;
  
                    /* Probable PsyQ macro: setPolyGT4() */
  Enemy_InitFromTable();
  uVar3 = 0x2a;
  if ((obj->var & 0x80) == 0) {
    FUN_80103794(0x20,0,3);
    uVar3 = 0x30;
                    /* Probable PsyQ macro: setLineF2() */
    uVar4 = 0x1b;
    uVar6 = 1;
  }
  else {
    uVar4 = 0x41;
    uVar6 = 3;
  }
  FUN_80103794(uVar3,uVar4,uVar6);
                    /* Possible PsyQ macro: setLineF2() */
  obj->field_0x49 = 2;
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
  obj->hitbox = &DAT_801f82e4;
  *(short *)&obj->field_0x52 = obj->x + 0x50;
  *(ushort *)&obj->field_0x54 = obj->y & 0x1f00;
  if ((obj->var & 0x80) == 0) {
    sVar1 = DAT_801d2928 + 0x180;
  }
  else {
    sVar1 = DAT_801d2928 + 0x140;
  }
  obj->x = sVar1;
  sVar1 = DAT_801d292a;
  bVar5 = 0x20;
  obj->field_0x58 = 0;
  obj->field_0x59 = 0;
  obj->field_0x5c = 0;
  obj->field_0x51 = 0;
  obj->field_0x5b = 0;
  obj->state = 1;
  obj->y = sVar1 + -0x70;
  if ((obj->var & 0x80) != 0) {
    bVar5 = 0x2a;
  }
  obj->draw_list = 7;
  obj->clut = bVar5;
  obj->box2 = &DAT_801f82f4;
  obj->flip = 0;
  Anim_Set(obj,0);
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    puVar2[6] = 0x1e;
    *puVar2 = 1;
    puVar2[7] = 5;
    *(MM8Obj **)(puVar2 + 0x1c) = obj;
  }
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    puVar2[6] = 0x1e;
                    /* Possible PsyQ macro: setPolyGT4() */
    *puVar2 = 1;
    puVar2[7] = 6;
    *(MM8Obj **)(puVar2 + 0x1c) = obj;
  }
  return;
}


// ---- 801dcc0c FUN_801dcc0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcc0c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f832c)[obj->sub2])();
  Anim_Step(obj);
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801dcc6c FUN_801dcc6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcc6c(MM8Obj *obj)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  
  if (obj->sub3 == 0) {
    if ((DAT_801d2918._2_2_ == DAT_801d2928) && (DAT_801b299e == '\0')) {
      if ((obj->var & 0x80) == 0) {
        DAT_801d2928 = 0x18a0;
      }
      DAT_801b2992 = 1;
      DAT_801b2993 = 1;
      DAT_801b2994 = 1;
      if ((DAT_801b1ec0 == '\0') || ((obj->var & 0x80) != 0)) {
        FUN_800fcb80(0xb);
        FUN_801119e0(DAT_801d2928 + 0xe0,0x40);
        obj->sub3 = 1;
      }
      else {
        FUN_80111e10();
        Obj_Free(obj);
      }
    }
  }
  else if ((DAT_8015e2b0 == '\x01') && (DAT_801cf53c == '\0')) {
    if ((obj->var & 0x80) == 0) {
      sVar3 = 0;
      do {
        iVar2 = FUN_80108ed8(obj,0,0);
        if (iVar2 != 0) {
          *(short *)(iVar2 + 0xe) = DAT_801d2928 + sVar3 + 4;
          uVar1 = Rand();
          *(ushort *)(iVar2 + 0x12) = DAT_801d292a + (uVar1 & 0xf) + 0xb8;
        }
        sVar3 = sVar3 + 0x10;
      } while (sVar3 < 0x40);
      FUN_80102ef4(1,0x1880,0x18a0);
    }
    obj->sub2 = 1;
    obj->sub3 = 0;
    DAT_801d2917 = 2;
    DAT_8015e2af = 1;
  }
  return;
}


// ---- 801dce68 FUN_801dce68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce68(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  
  FUN_801deed4();
  if (obj->sub3 == 0) {
    g_cam_y = g_cam_y + -4;
    if (DAT_801d292a + -0xe0 == (int)g_cam_y) {
      uVar2 = Rand();
      FUN_800fd100((uVar2 & 3) + 0x9f);
      obj->sub3 = 1;
      obj->field_0x50 = 0xb4;
      obj->hp = 0;
    }
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->speed_y_up = -0x60000;
      obj->speed_x = 0;
      obj->field_0x50 = 8;
      Anim_Set(obj,1);
      obj->sub2 = 2;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801dcf40 FUN_801dcf40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcf40(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_80104c34();
  if (obj->sub3 == 0) {
    g_cam_y = g_cam_y + 6;
                    /* Possible PsyQ macro: setPolyGT4() */
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 8;
      obj->sub3 = 1;
    }
  }
  else {
    g_cam_y = (ushort)(byte)obj->field_0x50 + g_cam_y;
    obj->field_0x50 = obj->field_0x50 + '\x02';
                    /* Possible PsyQ macro: setTile8() */
    if (0x20 < (byte)obj->field_0x50) {
      obj->field_0x50 = 0x20;
    }
  }
  cVar1 = DAT_801d292a <= g_cam_y;
  if ((bool)cVar1) {
    g_cam_y = DAT_801d292a;
  }
  uVar3 = 0x28;
  if (DAT_801d292a + 0x98 < (int)obj->y) {
    obj->y = DAT_801d292a + 0x98;
    if ((obj->var & 0x80) != 0) {
      uVar3 = 0x18;
    }
    FUN_801df190(obj,10,0x18,uVar3);
    uVar3 = 0x28;
    if ((obj->var & 0x80) != 0) {
      uVar3 = 0x18;
    }
    iVar2 = FUN_801df190(obj,10,0xffffffe8,uVar3);
    cVar1 = cVar1 + '\x01';
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0x25) = obj->flip ^ 0x40;
    }
  }
  if (cVar1 == '\x02') {
                    /* Possible PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
    Anim_Set(obj,2);
    FUN_8010544c(obj,0xaf);
    obj->hp = 0;
    DAT_801b297c = obj;
    obj->field_0x50 = 0x14;
    obj->sub2 = 3;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801dd104 FUN_801dd104

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd104(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (obj->sub3 == 0) {
    if ((obj->field_0x50 & 7) == 0) {
      uVar3 = 0x28;
      if ((obj->var & 0x80) != 0) {
        uVar3 = 0x18;
      }
      iVar2 = FUN_801df190(obj,10,0xffffffe8,uVar3);
      if (iVar2 != 0) {
        *(byte *)(iVar2 + 0x25) = obj->flip ^ 0x40;
      }
    }
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0x1e;
      obj->speed_y_up = 0x8000;
      Anim_Set(obj,0);
      obj->sub3 = 1;
    }
  }
  else {
    FUN_80104c34(obj);
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      Anim_Set(obj,4);
      obj->sub2 = 4;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801dd208 FUN_801dd208

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd208(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801deed4();
  if (obj->sub3 == 0) {
    if (obj->anim_extra != 0) {
      FUN_8010544c(obj,obj->anim_extra + 0xb3);
                    /* Possible PsyQ macro: setPolyGT3() */
      obj->anim_extra = 0;
    }
    if ((short)obj->frame < 0) {
      Anim_Set(obj,5);
      FUN_8010544c(obj,0xb7);
      FUN_801df190(obj,0xf,0,0);
                    /* Possible PsyQ macro: setLineF2() */
      FUN_801df190(obj,0x10,0,0);
      FUN_801df190(obj,0x11,0xfffffff8,0);
      obj->field_0x50 = 0x50;
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
  }
  else if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      FUN_8010544c(obj,0x13e);
      obj->field_0x4 = 1;
    }
  }
  else {
    obj->hp = obj->hp + ((byte)DAT_80170574 & 1);
    if (0x28 < obj->hp) {
                    /* Possible PsyQ macro: setPolyF4() */
      obj->hp = 0x28;
      Anim_Set(obj,0x15);
                    /* Possible PsyQ macro: setLineF2() */
      FUN_800fcb80(0xc);
      obj->sub2 = 5;
    }
  }
  return;
}


// ---- 801dd360 FUN_801dd360

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd360(MM8Obj *obj)

{
  if (((short)obj->frame < 0) && (DAT_801cf53c == '\0')) {
    obj->speed_y_up = -0x60000;
    obj->speed_x = 0;
    obj->field_0x50 = 8;
    Anim_Set(obj,0);
    obj->sub2 = 6;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801dd3cc FUN_801dd3cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd3cc(MM8Obj *obj)

{
  DAT_801d2917 = 0;
  obj->state = 2;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  DAT_801b2992 = 0;
  DAT_801b2993 = 0;
  DAT_801b2994 = 0;
  DAT_8015e2af = 0;
  FUN_80111918();
  return;
}


// ---- 801dd428 FUN_801dd428

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd428(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_default_801f8348)[obj->sub2])();
  Obj_CullAndQueueDraw(obj);
  if (obj->field_0x5c == '\0') {
    cVar2 = Enemy_CheckWeaponHits(obj);
    if (cVar2 == '\x04') {
      FUN_8010544c(obj,0x10);
      obj->state = 3;
      obj->sub2 = 0;
      DAT_8015e282 = 1;
      return;
    }
    if (cVar2 == '\x02') {
      FUN_8010544c(obj,0xb3);
      FUN_8010544c(obj,0x10);
      obj->field_0x5c = 0x3c;
    }
  }
  else {
    bVar1 = obj->hp;
    obj->hp = 0x3f;
    iVar3 = Enemy_CheckWeaponHits(obj);
    if (iVar3 == 2) {
      FUN_8010544c(obj,0x4f);
    }
    obj->hp = bVar1;
    bVar1 = obj->field_0x5c - 1;
    obj->field_0x5c = bVar1;
    if ((bVar1 & 1) == 0) {
      obj->clut = DAT_80159fae;
    }
    else {
      obj->clut = 0;
    }
  }
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801dd558 default

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801dd454::default(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8364)[obj->sub3])();
  Anim_Step(obj);
  FUN_801df14c(obj);
  return;
}


// ---- 801dd5b0 FUN_801dd5b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd5b0(MM8Obj *obj)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (int)obj->y - (int)DAT_801d292a;
  if (iVar3 < 0x34) {
    obj->speed_y_up = -0x40000;
    obj->gravity = -0x6000;
    *(int *)&obj->y_frac = *(int *)&obj->y_frac + 0x40000;
  }
  else if (iVar3 < 0x3d) {
    uVar2 = Rand();
    uVar1 = (&DAT_801f830c)[uVar2 & 0xf];
    obj->sub3 = 1;
    obj->field_0x4 = 0;
    obj->field_0x5d = uVar1;
  }
  else {
    obj->speed_y_up = 0x40000;
    obj->gravity = 0x6000;
                    /* Possible PsyQ macro: setLineF2() */
    *(int *)&obj->y_frac = *(int *)&obj->y_frac + -0x40000;
  }
  return;
}


// ---- 801dd664 FUN_801dd664

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd664(MM8Obj *obj)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_801df25c();
  if (obj->field_0x4 == '\0') {
    FUN_8010910c(obj);
    iVar1 = 0x4000;
    if ((obj->flip & 0x40) == 0) {
      iVar1 = -0x4000;
    }
    obj->accel_x = iVar1;
    obj->field_0x4 = 1;
  }
  iVar1 = obj->speed_x;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 0x60000) {
    Obj_ApplySpeed(obj);
  }
  else {
    FUN_80104ccc(obj);
    uVar3 = (DAT_801d2928 + 0x140) * 0x10000 - *(int *)&obj->x_frac;
    uVar2 = uVar3;
    if ((int)uVar3 < 0) {
      uVar2 = -uVar3;
    }
    if ((0x500000 < (int)uVar2) && ((uVar3 & 0x80000000) != (obj->speed_x & 0x80000000U))) {
      obj->sub3 = 2;
      obj->flip = obj->flip ^ 0x40;
      obj->accel_x = -obj->accel_x;
    }
  }
  return;
}


// ---- 801dd76c FUN_801dd76c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd76c(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801df25c();
  Obj_ApplySpeed(obj);
  if ((obj->speed_x == 0) || ((obj->speed_x & 0x80000000U) == (obj->accel_x & 0x80000000U))) {
    obj->sub3 = 1;
    obj->field_0x4 = 0;
    cVar1 = obj->field_0x5d + -1;
    obj->field_0x5d = cVar1;
    if (cVar1 == '\0') {
      FUN_801df040(obj);
    }
  }
  return;
}


// ---- 801dd7ec FUN_801dd7ec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd7ec(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  (*(code *)(&PTR_FUN_801f8370)[obj->sub3])();
  return;
}


// ---- 801dd828 FUN_801dd828

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd828(MM8Obj *obj)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  
                    /* Possible PsyQ macro: setTile8() */
  if ((obj->flip & 0x40) == 0) {
                    /* Possible PsyQ macro: setPolyF3() */
    iVar3 = (int)DAT_8015e248._2_2_ - (int)obj->x;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    sVar2 = DAT_801d2928 + 0x260;
    if (0x6f < iVar3) {
      sVar2 = DAT_8015e248._2_2_ + 0x70;
    }
  }
  else {
    iVar3 = (int)DAT_8015e248._2_2_ - (int)obj->x;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    sVar2 = DAT_8015e248._2_2_ + -0x70;
    if (iVar3 < 0x70) {
      *(short *)&obj->field_0x56 = DAT_801d2928;
      goto LAB_801dd8b8;
    }
  }
  *(short *)&obj->field_0x56 = sVar2;
LAB_801dd8b8:
  obj->sub3 = 1;
  uVar1 = FUN_80104db0((int)obj->x,(int)obj->y,(int)*(short *)&obj->field_0x56,DAT_801d292a + 0x70);
  FUN_80105120(obj,0x800,uVar1);
  return;
}


// ---- 801dd900 FUN_801dd900

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd900(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  FUN_80104c34();
  sVar1 = DAT_801d2928;
  iVar3 = (int)obj->x;
  iVar2 = iVar3 - *(short *)&obj->field_0x56;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (7 < iVar2) {
    return;
  }
  obj->sub3 = 2;
  obj->speed_x = 0;
  obj->speed_y_up = 0;
  Anim_Set(obj,7);
  if ((obj->flip & 0x40) == 0) {
    if (iVar3 < sVar1 + 0xe0) goto LAB_801dd9a4;
  }
  else if (sVar1 + 0x180 < iVar3) {
LAB_801dd9a4:
    obj->sub3 = 4;
    Anim_Set(obj,0xb);
    return;
  }
  FUN_8010910c(obj);
  return;
}


// ---- 801dd9e0 FUN_801dd9e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd9e0(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  
  Anim_Step();
  if ((obj->anim_extra & 0x80) != 0) {
    FUN_8010544c(obj,0xae);
    obj->anim_extra = obj->anim_extra & 0x7f;
  }
  if ((obj->anim_extra & 1) != 0) {
    puVar2 = (undefined1 *)FUN_801055e4(obj);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x28;
      puVar2[7] = 1;
      puVar2[0x25] = obj->flip;
      if (puVar2[0x25] == '\0') {
        sVar1 = obj->x + -0x1a;
      }
      else {
        sVar1 = obj->x + 0x1a;
      }
      *(short *)(puVar2 + 0xe) = sVar1;
      sVar1 = obj->y;
      *(MM8Obj **)(puVar2 + 0x54) = obj;
      *(short *)(puVar2 + 0x12) = sVar1;
    }
    FUN_800fd100(0xa6);
    obj->speed_y_up = 0x20000;
    obj->speed_x = 0x20000;
    if ((obj->flip & 0x40) != 0) {
      obj->speed_x = -0x20000;
    }
    obj->sub3 = 3;
    obj->field_0x50 = 8;
  }
  return;
}


// ---- 801ddae8 FUN_801ddae8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddae8(MM8Obj *obj)

{
  char cVar1;
  
  FUN_80104c34();
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 4;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  FUN_801df14c(obj);
  return;
}


// ---- 801ddb40 FUN_801ddb40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddb40(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  
  Anim_Step();
  if ((obj->anim_extra != 0) &&
     (puVar2 = (undefined1 *)FUN_801055e4(obj), puVar2 != (undefined1 *)0x0)) {
    *puVar2 = 1;
                    /* Possible PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
    puVar2[6] = 0x28;
    puVar2[7] = 0;
    puVar2[0x25] = obj->flip;
    *(short *)(puVar2 + 0x12) = obj->y + 0x15;
    if (obj->flip == 0) {
      sVar1 = obj->x + -0x30;
    }
    else {
      sVar1 = obj->x + 0x30;
    }
    *(short *)(puVar2 + 0xe) = sVar1;
    FUN_800fd100(0xa4);
  }
  if ((short)obj->frame < 0) {
    obj->sub2 = 4;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801ddc08 FUN_801ddc08

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddc08(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801f8384)[obj->sub3])();
  return;
}


// ---- 801dde34 FUN_801dde34

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dde34(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  (*(code *)(&PTR_FUN_801f8394)[obj->sub3])();
  FUN_801df14c(obj);
  return;
}


// ---- 801dde84 FUN_801dde84

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dde84(MM8Obj *obj)

{
  obj->sub3 = 1;
  obj->field_0x4 = 0;
  FUN_800fd100(0xa3);
  obj->sub3 = 2;
  return;
}


// ---- 801ddec4 FUN_801ddec4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddec4(MM8Obj *obj)

{
  int iVar1;
  
  FUN_801df25c();
  iVar1 = obj->speed_x;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 0x60000) {
    Obj_ApplySpeed(obj);
  }
  else {
    FUN_80104ccc(obj);
  }
  if (((obj->accel_x < 0) && (obj->x <= *(short *)&obj->field_0x56)) ||
     ((0 < obj->accel_x && (*(short *)&obj->field_0x56 <= obj->x)))) {
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
                    /* Possible PsyQ macro: setPolyF4() */
  return;
}


// ---- 801ddf78 caseD_1

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801ddf1c::caseD_1(MM8Obj *obj)

{
  ushort uVar1;
  
  if (obj->field_0x4 == '\0') {
    uVar1 = DAT_801d292a + 0xb0;
                    /* Possible PsyQ macro: setTile8() */
    obj->speed_x = 0;
    *(ushort *)&obj->field_0x56 = uVar1;
    obj->accel_x = -0x4000;
                    /* Possible PsyQ macro: setLineF2() */
    obj->speed_y_up = (int)(*(int *)&obj->y_frac + (uint)uVar1 * -0x10000) / 0x1d;
    if ((obj->flip & 0x40) != 0) {
      obj->accel_x = 0x4000;
    }
    obj->field_0x50 = 0x3c;
    Anim_Set(obj,0xc);
    obj->field_0x4 = 1;
  }
  FUN_801deed4(obj);
  Anim_Step(obj);
  if (obj->anim_extra != 0) {
    obj->sub3 = 3;
    obj->field_0x4 = 0;
    obj->hitbox = &DAT_801f82e8;
  }
  return;
}


// ---- 801de058 FUN_801de058

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de058(MM8Obj *obj)

{
  FUN_80104c9c();
  Anim_Step(obj);
  if (*(short *)&obj->field_0x56 <= obj->y) {
    obj->y = *(short *)&obj->field_0x56;
    obj->speed_y_up = 0;
    obj->field_0x50 = 0x14;
    Anim_Set(obj,0xd);
    FUN_8010544c(obj,0xb1);
    obj->sub3 = 4;
  }
  FUN_801df290(obj);
  return;
}


// ---- 801de0d8 FUN_801de0d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de0d8(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  sVar1 = DAT_801d2928;
  FUN_80104c34();
  iVar2 = (int)obj->x;
  iVar4 = (int)sVar1;
  if ((iVar2 < iVar4 + -0x30) || (iVar4 + 0x280 < iVar2)) {
    obj->hitbox = &DAT_801f82e4;
    if ((DAT_8015e261 & 0x40) == 0) {
      sVar1 = DAT_8015e248._2_2_ + -0x28;
    }
    else {
      sVar1 = DAT_8015e248._2_2_ + 0x28;
    }
    obj->x = sVar1;
    FUN_8010910c(obj);
    sVar1 = g_cam_y;
                    /* Possible PsyQ macro: setLineF2() */
    obj->speed_y_up = -0x60000;
    obj->speed_x = 0;
    obj->sub3 = 5;
    obj->field_0x4 = 0;
    obj->y = sVar1 + -0xd0;
    Anim_Set(obj,2);
  }
  else {
    if (((int)*(short *)&obj->field_0x56 == DAT_801d292a + 0xb0) &&
       (((iVar4 + 0x40 < iVar2 && (iVar2 < iVar4 + 0x220)) && ((_DAT_80170574 & 3) == 0)))) {
      uVar3 = 0x10;
      if ((obj->var & 0x80) != 0) {
        uVar3 = 8;
      }
      FUN_801df190(obj,10,0x20,uVar3);
    }
    FUN_801df290(obj);
  }
  return;
}


// ---- 801de23c FUN_801de23c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de23c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    FUN_80104c34(obj);
    if (DAT_801d292a + 0xa0 < (int)obj->y) {
      if ((DAT_801d2928 + 0x50 < (int)obj->x) && (uVar3 = 0x28, (int)obj->x < DAT_801d2928 + 0x210))
      {
        obj->field_0x43 = 0;
        if ((obj->var & 0x80) != 0) {
          uVar3 = 0x18;
        }
        FUN_801df190(obj,10,0x18,uVar3);
        uVar3 = 0x28;
        if ((obj->var & 0x80) != 0) {
          uVar3 = 0x18;
        }
        iVar2 = FUN_801df190(obj,10,0xffffffe8,uVar3);
        if (iVar2 != 0) {
          *(byte *)(iVar2 + 0x25) = obj->flip ^ 0x40;
        }
        FUN_8010544c(obj,0xb0);
      }
      FUN_8010910c(obj);
      Anim_Set(obj,0);
      obj->field_0x50 = 0x28;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_801deed4(obj);
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->sub2 = 0;
                    /* Possible PsyQ macro: setLineF2() */
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
    FUN_801de6b4(obj);
  }
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  return;
}


// ---- 801de394 FUN_801de394

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de394(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyF4() */
  (*(code *)(&PTR_FUN_801f83ac)[obj->sub3])();
  return;
}


// ---- 801de3d0 FUN_801de3d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de3d0(MM8Obj *obj)

{
  obj->sub3 = 1;
  obj->field_0x43 = 1;
  obj->speed_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0x4000;
  FUN_8010910c();
  obj->field_0x50 = 0x1e;
  if (((int)obj->x <= DAT_801d2928 + 0x40) || (DAT_801d2928 + 0x220 <= (int)obj->x)) {
    obj->sub3 = 4;
    obj->field_0x4 = 0;
    obj->field_0x50 = 10;
    Anim_Set(obj,0);
  }
  FUN_801df14c(obj);
                    /* Possible PsyQ macro: setTile1() + setSemiTrans(tile1, 1) */
  return;
}


// ---- 801de46c FUN_801de46c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de46c(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80104ccc();
                    /* Possible PsyQ macro: setPolyGT4() */
  if (obj->speed_y_up < -0x60000) {
                    /* Possible PsyQ macro: setLineF2() */
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    iVar1 = FUN_801df190(obj,10,0x18,0);
    if (iVar1 != 0) {
      *(byte *)(iVar1 + 0x25) = obj->flip;
    }
    iVar1 = FUN_801df190(obj,10,0xffffffe8,0);
    if (iVar1 != 0) {
      *(byte *)(iVar1 + 0x25) = obj->flip ^ 0x40;
    }
    FUN_8010544c(obj,0xb0);
    obj->sub3 = 2;
    obj->field_0x43 = 0;
    Anim_Set(obj,0xf);
  }
  Anim_Step(obj);
  FUN_801df14c(obj);
  return;
}


// ---- 801de550 FUN_801de550

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de550(MM8Obj *obj)

{
  char cVar1;
  
  Anim_Step();
  obj->field_0x50 = obj->field_0x50 + -1;
                    /* Possible PsyQ macro: setPolyF3() */
  if (obj->field_0x50 == '\0') {
    obj->sub3 = 3;
    obj->field_0x43 = 1;
    obj->speed_y_up = 0x85800;
    obj->gravity = 0x4000;
    Anim_Set(obj,6);
  }
  cVar1 = FUN_801de6b4(obj);
  if (cVar1 == '\0') {
    FUN_801df14c(obj);
  }
  return;
}


// ---- 801de5e0 FUN_801de5e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de5e0(MM8Obj *obj)

{
  FUN_801df010();
  FUN_80104ccc(obj);
  if ((obj->speed_y_up == 0) || ((obj->speed_y_up & 0x80000000U) != (obj->gravity & 0x80000000U))) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    Anim_Set(obj,0);
  }
  FUN_801df14c(obj);
  return;
}


// ---- 801de654 FUN_801de654

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de654(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801df010();
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    Anim_Set(obj,0);
  }
  FUN_801df14c(obj);
  return;
}


// ---- 801de6b4 FUN_801de6b4

undefined4 FUN_801de6b4(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(char *)(param_1 + 0x43) == '\0') && (uVar2 = 0, *(char *)(param_1 + 0x5c) == '\0')) {
    *(undefined **)(param_1 + 0x3c) = &DAT_801f82ec;
    *(undefined1 *)(param_1 + 0x44) = 7;
    cVar1 = Enemy_CheckWeaponHits(param_1);
    *(undefined1 *)(param_1 + 0x44) = 10;
    *(undefined **)(param_1 + 0x3c) = &DAT_801f82e4;
    if (cVar1 == '\x01') {
      cVar1 = Enemy_CheckWeaponHits(param_1);
                    /* Possible PsyQ macro: setTile1() + setSemiTrans(tile1, 1) */
                    /* Possible PsyQ macro: setLineF2() */
      if (cVar1 == '\x02') {
        *(undefined1 *)(param_1 + 0x5c) = 0x3c;
      }
      else if (cVar1 == '\x04') {
        *(undefined1 *)(param_1 + 1) = 3;
        *(undefined1 *)(param_1 + 2) = 0;
        DAT_8015e282 = 1;
        return 1;
      }
      uVar2 = 1;
      *(undefined1 *)(param_1 + 2) = 5;
      *(undefined1 *)(param_1 + 3) = 0;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ---- 801de798 FUN_801de798

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de798(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f83c0)[obj->sub3])();
  return;
}


// ---- 801de7d4 FUN_801de7d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de7d4(MM8Obj *obj)

{
  obj->sub3 = 1;
  obj->speed_y_up = -0x4000;
  obj->speed_x = 0;
  obj->gravity = 0x4000;
  Anim_Set(obj,0x11);
  FUN_800fd100(0xa8);
  return;
}


// ---- 801de818 FUN_801de818

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de818(MM8Obj *obj)

{
  FUN_80104ccc();
  Anim_Step(obj);
  FUN_80106214(obj);
  if ((((obj->field_0x33 & 0x80) != 0) && ((short)obj->frame < 0)) && (obj->anim_timer == 1)) {
    Anim_Set(obj,0x13);
    obj->field_0x50 = 0xf0;
    obj->sub3 = 2;
    obj->field_0x5e = obj->hp;
    FUN_8010544c(obj,0xad);
  }
  return;
}


// ---- 801de8b0 FUN_801de8b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de8b0(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  Anim_Step();
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
                    /* Possible PsyQ macro: setPolyGT4() */
  if ((cVar1 == '\0') || (2 < (int)((uint)(byte)obj->field_0x5e - (uint)obj->hp))) {
    obj->speed_y_up = 0x60000;
    obj->speed_x = 0;
    obj->gravity = 0x3000;
    Anim_Set(obj,6);
    if ((obj->var & 0x80) == 0) {
      uVar3 = 0xc;
    }
    else {
      uVar3 = 0x12;
    }
    iVar2 = FUN_801df190(obj,uVar3,0,0);
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0x25) = obj->flip;
    }
    FUN_8010544c(obj,0x2c);
    FUN_8010544c(obj,0xa9);
    FUN_8012ae08(obj,0x1f);
    obj->sub3 = 3;
  }
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801de998 FUN_801de998

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de998(MM8Obj *obj)

{
  FUN_80104ccc();
  if ((obj->speed_y_up == 0) || ((obj->speed_y_up & 0x80000000U) != (obj->gravity & 0x80000000U))) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    Anim_Set(obj,0);
  }
  return;
}


// ---- 801de9fc FUN_801de9fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de9fc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f83d0)[obj->sub3])();
  return;
}


// ---- 801dea38 FUN_801dea38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dea38(MM8Obj *obj)

{
  short sVar1;
  char cVar2;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    obj->field_0x4 = 1;
    Anim_Set(obj,8);
  }
  if (obj->x < DAT_8015e248._2_2_) {
    sVar1 = -0x20;
  }
  else {
    sVar1 = 0x20;
  }
  cVar2 = FUN_801def1c(obj,(int)(short)(DAT_8015e248._2_2_ + sVar1),(int)DAT_8015e24c._2_2_,0x800);
  FUN_8010910c(obj);
  if (cVar2 == '\0') {
    obj->sub3 = 1;
    obj->field_0x4 = 0;
    Anim_Set(obj,9);
  }
  return;
}


// ---- 801deafc FUN_801deafc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deafc(MM8Obj *obj)

{
  Anim_Step();
  if (obj->anim_extra != 0) {
    obj->field_0x51 = 0;
    FUN_8010544c(obj,0xa7);
                    /* Possible PsyQ macro: setPolyGT3() */
    FUN_80111ef8(3,3);
  }
  if ((short)obj->frame < 0) {
    obj->sub3 = 2;
    obj->field_0x50 = 0x3c;
  }
                    /* Possible PsyQ macro: setTile() */
  return;
}


// ---- 801deb68 FUN_801deb68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deb68(MM8Obj *obj)

{
  FUN_801deed4();
                    /* Possible PsyQ macro: setLineF2() */
  obj->field_0x50 = obj->field_0x50 + -1;
  if (obj->field_0x50 == '\0') {
    FUN_8010544c(obj,0xac);
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    Anim_Set(obj,0);
  }
  return;
}


// ---- 801debd0 FUN_801debd0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801debd0(MM8Obj *obj)

{
  int iVar1;
  undefined4 *puVar2;
  
  DAT_8015e282 = 1;
  DAT_801d292c = g_cam_y;
  (*(code *)(&PTR_FUN_801f83dc)[obj->sub2])();
  iVar1 = FUN_80105ea4(obj,0xd);
  if (iVar1 != 0) {
                    /* Probable PsyQ macro: setTile16() */
    puVar2 = (undefined4 *)(&DAT_801b103c + iVar1 * 4);
    do {
      iVar1 = iVar1 + -1;
      Obj_Free(*puVar2);
      puVar2 = puVar2 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ---- 801dec78 FUN_801dec78

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dec78(MM8Obj *obj)

{
  if ((obj->var & 0x80) == 0) {
    DAT_801d2926 = DAT_801d2918._2_2_;
    DAT_801d2928 = DAT_801d2918._2_2_;
  }
  Anim_Set(obj,0x16);
  FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  FUN_800fcd84();
  obj->sub2 = 1;
  obj->sub3 = 0;
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801ded28 FUN_801ded28

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ded28(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  Anim_Step();
                    /* Possible PsyQ macro: setPolyF4() */
  if (obj->sub3 == 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x50 = 0x3c;
    obj->sub3 = 1;
  }
                    /* Probable PsyQ macro: setTile() */
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
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->sub3 = 0;
  }
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801dedf8 FUN_801dedf8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dedf8(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if ((obj->field_0x50 & 7) == 0) {
    uVar2 = Rand();
                    /* Probable PsyQ macro: setTile16() */
    uVar3 = Rand();
    FUN_80108ed8(obj,(int)(((uVar2 & 0x3f) - 0x1f) * 0x10000) >> 0x10,
                 (int)(((uVar3 & 0x3f) - 0x1f) * 0x10000) >> 0x10);
  }
  if ((obj->field_0x50 & 1) != 0) {
    FUN_80103184(obj);
    Obj_CullAndQueueDraw(obj);
  }
                    /* Possible PsyQ macro: setLineF2() */
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_8010544c(obj,0xaa);
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->on_screen = 0;
    obj->field_0x50 = 1;
  }
  return;
}


// ---- 801deed4 FUN_801deed4

void FUN_801deed4(int param_1)

{
  short sVar1;
  byte bVar2;
  
  bVar2 = *(char *)(param_1 + 0x5a) + 1;
  *(byte *)(param_1 + 0x5a) = bVar2;
  if ((bVar2 & 7) == 0) {
    if ((bVar2 & 0x10) == 0) {
      sVar1 = *(short *)(param_1 + 0x12) + -1;
    }
    else {
                    /* Possible PsyQ macro: setPolyGT4() */
      sVar1 = *(short *)(param_1 + 0x12) + 1;
    }
    *(short *)(param_1 + 0x12) = sVar1;
  }
  return;
}


// ---- 801def1c FUN_801def1c

undefined4 FUN_801def1c(int param_1,short param_2,short param_3,short param_4)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  
  sVar2 = FUN_801054b4((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),(int)param_2,
                       (int)param_3);
                    /* Possible PsyQ macro: setLineF2() */
  if (sVar2 < 4) {
    uVar4 = 0;
  }
  else {
    iVar3 = sVar2 * 0x18 + 0x80;
    sVar2 = (short)iVar3;
    if ((int)param_4 < iVar3 * 0x10000 >> 0x10) {
      sVar2 = param_4;
    }
    uVar1 = FUN_80104db0((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),(int)param_2
                         ,(int)param_3);
    FUN_80105120(param_1,(int)sVar2,uVar1);
    FUN_80104c34(param_1);
    uVar4 = 1;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  return uVar4;
}


// ---- 801df010 FUN_801df010

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801df010(void)

{
  if ((_DAT_80170574 & 0xf) == 0) {
    FUN_8010910c();
  }
  return;
}


// ---- 801df040 FUN_801df040

void FUN_801df040(int param_1)

{
  uint uVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  do {
    uVar1 = Rand();
    *(undefined *)(param_1 + 2) = (&DAT_801f82fc)[uVar1 & 0xf];
    if (*(char *)(param_1 + 2) != *(char *)(param_1 + 0x58)) {
      *(undefined1 *)(param_1 + 0x59) = 1;
      *(undefined1 *)(param_1 + 0x58) = *(undefined1 *)(param_1 + 2);
      goto LAB_801df0cc;
    }
  } while (1 < *(byte *)(param_1 + 0x59));
  *(char *)(param_1 + 0x59) = *(char *)(param_1 + 0x59) + '\x01';
  *(undefined1 *)(param_1 + 0x58) = *(undefined1 *)(param_1 + 2);
LAB_801df0cc:
                    /* Possible PsyQ macro: setLineF2() */
  if ((uVar1 & 0xff) == 1) {
    iVar2 = (int)*(short *)(param_1 + 0xe);
                    /* Possible PsyQ macro: setPolyF4() */
    if (((iVar2 < DAT_801d2918._2_2_ + 0x40) && (DAT_8015e248._2_2_ < iVar2)) ||
       ((DAT_801d2918._2_2_ + 0x220 < iVar2 && (iVar2 < DAT_8015e248._2_2_)))) {
      *(undefined1 *)(param_1 + 2) = 2;
    }
  }
  return;
}


// ---- 801df14c FUN_801df14c

void FUN_801df14c(int param_1)

{
  if (*(char *)(param_1 + 0x51) != '\0') {
    *(undefined **)(param_1 + 0x3c) = &DAT_801f82e4;
    *(undefined1 *)(param_1 + 0x44) = 10;
    *(undefined1 *)(param_1 + 2) = 6;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    *(undefined1 *)(param_1 + 0x43) = 1;
  }
  return;
}


// ---- 801df190 FUN_801df190

undefined1 * FUN_801df190(int param_1,undefined1 param_2,char param_3,char param_4)

{
  undefined1 uVar1;
  short sVar2;
  undefined1 *puVar3;
  
                    /* Possible PsyQ macro: setPolyF4() */
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
    *(short *)(puVar3 + 0x12) = (short)param_4 + *(short *)(param_1 + 0x12);
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    puVar3[0x3b] = param_3;
    puVar3[0x3c] = param_4;
    *(int *)(puVar3 + 0x1c) = param_1;
    puVar3[0x25] = uVar1;
  }
  return puVar3;
}


// ---- 801df25c FUN_801df25c

void FUN_801df25c(int param_1)

{
  if (0x80000 < *(int *)(param_1 + 0x18) + 0x40000U) {
    *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
  }
  return;
}


// ---- 801df290 FUN_801df290

void FUN_801df290(int param_1)

{
  *(undefined **)(param_1 + 0x3c) = &DAT_801f82f0;
  *(undefined1 *)(param_1 + 0x44) = 1;
  Enemy_CheckWeaponHits();
  *(undefined **)(param_1 + 0x3c) = &DAT_801f82e8;
  *(undefined1 *)(param_1 + 0x44) = 10;
  return;
}


