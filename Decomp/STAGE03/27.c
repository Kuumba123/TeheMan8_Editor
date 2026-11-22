// ID 27, STAGE03.BIN, handler 0x801E12EC. Ghidra output with the object struct applied; not matching C.
// ---- 801e12ec FUN_801e12ec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e12ec(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9d58)[obj->state])();
  FUN_80103184(obj);
  return;
}


// ---- 801e133c FUN_801e133c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e133c(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined4 uVar6;
  
  Enemy_InitFromTable();
  uVar3 = 0x2a;
  if ((obj->var & 0x80) == 0) {
    FUN_80103794(0x20,0,3);
    uVar3 = 0x30;
    uVar4 = 0x1b;
    uVar6 = 1;
  }
  else {
    uVar4 = 0x41;
    uVar6 = 3;
  }
  FUN_80103794(uVar3,uVar4,uVar6);
  obj->field_0x49 = 2;
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
  obj->hitbox = &DAT_801e9d20;
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
  obj->box2 = &DAT_801e9d30;
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
    *puVar2 = 1;
    puVar2[7] = 6;
    *(MM8Obj **)(puVar2 + 0x1c) = obj;
  }
  return;
}


// ---- 801e14cc FUN_801e14cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e14cc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9d68)[obj->sub2])();
  Anim_Step(obj);
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e152c FUN_801e152c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e152c(MM8Obj *obj)

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


// ---- 801e1728 FUN_801e1728

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1728(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  
  FUN_801e3794();
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


// ---- 801e1800 FUN_801e1800

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1800(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_80104c34();
  if (obj->sub3 == 0) {
    g_cam_y = g_cam_y + 6;
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
    FUN_801e3a50(obj,10,0x18,uVar3);
    uVar3 = 0x28;
    if ((obj->var & 0x80) != 0) {
      uVar3 = 0x18;
    }
    iVar2 = FUN_801e3a50(obj,10,0xffffffe8,uVar3);
    cVar1 = cVar1 + '\x01';
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0x25) = obj->flip ^ 0x40;
    }
  }
  if (cVar1 == '\x02') {
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


// ---- 801e19c4 caseD_2

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801e1970::caseD_2(MM8Obj *obj)

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
      iVar2 = FUN_801e3a50(obj,10,0xffffffe8,uVar3);
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


// ---- 801e1ac8 FUN_801e1ac8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1ac8(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801e3794();
  if (obj->sub3 == 0) {
    if (obj->anim_extra != 0) {
      FUN_8010544c(obj,obj->anim_extra + 0xb3);
      obj->anim_extra = 0;
    }
    if ((short)obj->frame < 0) {
      Anim_Set(obj,5);
      FUN_8010544c(obj,0xb7);
      FUN_801e3a50(obj,0xf,0,0);
      FUN_801e3a50(obj,0x10,0,0);
      FUN_801e3a50(obj,0x11,0xfffffff8,0);
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
      FUN_800fcb80(0xc);
      obj->sub2 = 5;
    }
  }
  return;
}


// ---- 801e1c20 FUN_801e1c20

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1c20(MM8Obj *obj)

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


// ---- 801e1c8c FUN_801e1c8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1c8c(MM8Obj *obj)

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


// ---- 801e1ce8 FUN_801e1ce8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1ce8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  (*(code *)(&PTR_FUN_801e9d84)[obj->sub2])();
  Obj_CullAndQueueDraw(obj);
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
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


// ---- 801e1e18 FUN_801e1e18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1e18(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9da0)[obj->sub3])();
  Anim_Step(obj);
  FUN_801e3a0c(obj);
  return;
}


// ---- 801e1e70 FUN_801e1e70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1e70(MM8Obj *obj)

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
    uVar1 = (&DAT_801e9d48)[uVar2 & 0xf];
    obj->sub3 = 1;
    obj->field_0x4 = 0;
    obj->field_0x5d = uVar1;
  }
  else {
    obj->speed_y_up = 0x40000;
    obj->gravity = 0x6000;
    *(int *)&obj->y_frac = *(int *)&obj->y_frac + -0x40000;
  }
  return;
}


// ---- 801e1f24 FUN_801e1f24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1f24(MM8Obj *obj)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_801e3b1c();
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


// ---- 801e202c FUN_801e202c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e202c(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801e3b1c();
  Obj_ApplySpeed(obj);
  if ((obj->speed_x == 0) || ((obj->speed_x & 0x80000000U) == (obj->accel_x & 0x80000000U))) {
    obj->sub3 = 1;
    obj->field_0x4 = 0;
    cVar1 = obj->field_0x5d + -1;
    obj->field_0x5d = cVar1;
    if (cVar1 == '\0') {
      FUN_801e3900(obj);
    }
  }
  return;
}


// ---- 801e20ac FUN_801e20ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e20ac(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9dac)[obj->sub3])();
  return;
}


// ---- 801e20e8 FUN_801e20e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e20e8(MM8Obj *obj)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  
  if ((obj->flip & 0x40) == 0) {
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
      goto LAB_801e2178;
    }
  }
  *(short *)&obj->field_0x56 = sVar2;
LAB_801e2178:
  obj->sub3 = 1;
  uVar1 = FUN_80104db0((int)obj->x,(int)obj->y,(int)*(short *)&obj->field_0x56,DAT_801d292a + 0x70);
  FUN_80105120(obj,0x800,uVar1);
  return;
}


// ---- 801e21c0 FUN_801e21c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e21c0(MM8Obj *obj)

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
    if (iVar3 < sVar1 + 0xe0) goto LAB_801e2264;
  }
  else if (sVar1 + 0x180 < iVar3) {
LAB_801e2264:
    obj->sub3 = 4;
    Anim_Set(obj,0xb);
    return;
  }
  FUN_8010910c(obj);
  return;
}


// ---- 801e22a0 FUN_801e22a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e22a0(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  
  Anim_Step();
  if ((obj->anim_extra & 0x80) != 0) {
    FUN_8010544c(obj,0xae);
                    /* Possible PsyQ macro: setPolyGT4() */
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


// ---- 801e23a8 FUN_801e23a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e23a8(MM8Obj *obj)

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
  FUN_801e3a0c(obj);
  return;
}


// ---- 801e2400 FUN_801e2400

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2400(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  
  Anim_Step();
  if ((obj->anim_extra != 0) &&
     (puVar2 = (undefined1 *)FUN_801055e4(obj), puVar2 != (undefined1 *)0x0)) {
    *puVar2 = 1;
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


// ---- 801e24c8 FUN_801e24c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e24c8(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e9dc0)[obj->sub3])();
  return;
}


// ---- 801e26f4 FUN_801e26f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e26f4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9dd0)[obj->sub3])();
  FUN_801e3a0c(obj);
  return;
}


// ---- 801e2744 FUN_801e2744

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2744(MM8Obj *obj)

{
  obj->sub3 = 1;
  obj->field_0x4 = 0;
  FUN_800fd100(0xa3);
  obj->sub3 = 2;
  return;
}


// ---- 801e2784 FUN_801e2784

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2784(MM8Obj *obj)

{
  int iVar1;
  
  FUN_801e3b1c();
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
  return;
}


// ---- 801e2838 FUN_801e2838

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2838(MM8Obj *obj)

{
  ushort uVar1;
  
  if (obj->field_0x4 == '\0') {
    uVar1 = DAT_801d292a + 0xb0;
    obj->speed_x = 0;
    *(ushort *)&obj->field_0x56 = uVar1;
    obj->accel_x = -0x4000;
    obj->speed_y_up = (int)(*(int *)&obj->y_frac + (uint)uVar1 * -0x10000) / 0x1d;
    if ((obj->flip & 0x40) != 0) {
      obj->accel_x = 0x4000;
    }
    obj->field_0x50 = 0x3c;
    Anim_Set(obj,0xc);
    obj->field_0x4 = 1;
  }
  FUN_801e3794(obj);
  Anim_Step(obj);
  if (obj->anim_extra != 0) {
    obj->sub3 = 3;
    obj->field_0x4 = 0;
    obj->hitbox = &DAT_801e9d24;
  }
  return;
}


// ---- 801e2918 FUN_801e2918

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2918(MM8Obj *obj)

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
  FUN_801e3b50(obj);
  return;
}


// ---- 801e2998 FUN_801e2998

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2998(MM8Obj *obj)

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
    obj->hitbox = &DAT_801e9d20;
    if ((DAT_8015e261 & 0x40) == 0) {
      sVar1 = DAT_8015e248._2_2_ + -0x28;
    }
    else {
      sVar1 = DAT_8015e248._2_2_ + 0x28;
    }
    obj->x = sVar1;
    FUN_8010910c(obj);
    sVar1 = g_cam_y;
    obj->speed_y_up = -0x60000;
    obj->speed_x = 0;
    obj->sub3 = 5;
    obj->field_0x4 = 0;
    obj->y = sVar1 + -0xd0;
    Anim_Set(obj,2);
  }
  else {
    if (((int)*(short *)&obj->field_0x56 == DAT_801d292a + 0xb0) &&
       (((iVar4 + 0x40 < iVar2 && (iVar2 < iVar4 + 0x220)) && ((DAT_80170574 & 3) == 0)))) {
      uVar3 = 0x10;
      if ((obj->var & 0x80) != 0) {
        uVar3 = 8;
      }
      FUN_801e3a50(obj,10,0x20,uVar3);
    }
    FUN_801e3b50(obj);
  }
  return;
}


// ---- 801e2afc FUN_801e2afc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2afc(MM8Obj *obj)

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
        FUN_801e3a50(obj,10,0x18,uVar3);
        uVar3 = 0x28;
        if ((obj->var & 0x80) != 0) {
          uVar3 = 0x18;
        }
        iVar2 = FUN_801e3a50(obj,10,0xffffffe8,uVar3);
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
    FUN_801e3794(obj);
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
    FUN_801e2f74(obj);
  }
  return;
}


// ---- 801e2c54 FUN_801e2c54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2c54(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9de8)[obj->sub3])();
  return;
}


// ---- 801e2c90 FUN_801e2c90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2c90(MM8Obj *obj)

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
  FUN_801e3a0c(obj);
  return;
}


// ---- 801e2d2c FUN_801e2d2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2d2c(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80104ccc();
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    iVar1 = FUN_801e3a50(obj,10,0x18,0);
    if (iVar1 != 0) {
      *(byte *)(iVar1 + 0x25) = obj->flip;
    }
    iVar1 = FUN_801e3a50(obj,10,0xffffffe8,0);
    if (iVar1 != 0) {
      *(byte *)(iVar1 + 0x25) = obj->flip ^ 0x40;
    }
    FUN_8010544c(obj,0xb0);
    obj->sub3 = 2;
    obj->field_0x43 = 0;
    Anim_Set(obj,0xf);
  }
  Anim_Step(obj);
  FUN_801e3a0c(obj);
  return;
}


// ---- 801e2e10 FUN_801e2e10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2e10(MM8Obj *obj)

{
  char cVar1;
  
  Anim_Step();
  obj->field_0x50 = obj->field_0x50 + -1;
  if (obj->field_0x50 == '\0') {
    obj->sub3 = 3;
    obj->field_0x43 = 1;
    obj->speed_y_up = 0x85800;
    obj->gravity = 0x4000;
    Anim_Set(obj,6);
  }
  cVar1 = FUN_801e2f74(obj);
  if (cVar1 == '\0') {
    FUN_801e3a0c(obj);
  }
  return;
}


// ---- 801e2ea0 FUN_801e2ea0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2ea0(MM8Obj *obj)

{
  FUN_801e38d0();
  FUN_80104ccc(obj);
                    /* Possible PsyQ macro: setPolyFT4() + setSemiTrans(polyFT4, 1) */
  if ((obj->speed_y_up == 0) || ((obj->speed_y_up & 0x80000000U) != (obj->gravity & 0x80000000U))) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    Anim_Set(obj,0);
  }
  FUN_801e3a0c(obj);
  return;
}


// ---- 801e2f14 FUN_801e2f14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2f14(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801e38d0();
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    Anim_Set(obj,0);
  }
  FUN_801e3a0c(obj);
  return;
}


// ---- 801e2f74 FUN_801e2f74

undefined4 FUN_801e2f74(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(char *)(param_1 + 0x43) == '\0') && (uVar2 = 0, *(char *)(param_1 + 0x5c) == '\0')) {
    *(undefined **)(param_1 + 0x3c) = &DAT_801e9d28;
    *(undefined1 *)(param_1 + 0x44) = 7;
    cVar1 = Enemy_CheckWeaponHits(param_1);
    *(undefined1 *)(param_1 + 0x44) = 10;
    *(undefined **)(param_1 + 0x3c) = &DAT_801e9d20;
    if (cVar1 == '\x01') {
      cVar1 = Enemy_CheckWeaponHits(param_1);
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


// ---- 801e3058 FUN_801e3058

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3058(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9dfc)[obj->sub3])();
  return;
}


// ---- 801e3094 FUN_801e3094

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3094(MM8Obj *obj)

{
  obj->sub3 = 1;
  obj->speed_y_up = -0x4000;
  obj->speed_x = 0;
  obj->gravity = 0x4000;
  Anim_Set(obj,0x11);
  FUN_800fd100(0xa8);
  return;
}


// ---- 801e30d8 FUN_801e30d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e30d8(MM8Obj *obj)

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


// ---- 801e3170 FUN_801e3170

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3170(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  Anim_Step();
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
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
    iVar2 = FUN_801e3a50(obj,uVar3,0,0);
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0x25) = obj->flip;
    }
    FUN_8010544c(obj,0x2c);
    FUN_8010544c(obj,0xa9);
    FUN_8012ae08(obj,0x1f);
    obj->sub3 = 3;
  }
  return;
}


// ---- 801e3258 FUN_801e3258

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3258(MM8Obj *obj)

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


// ---- 801e32bc FUN_801e32bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e32bc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e9e0c)[obj->sub3])();
  return;
}


// ---- 801e32f8 FUN_801e32f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e32f8(MM8Obj *obj)

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
  cVar2 = FUN_801e37dc(obj,(int)(short)(DAT_8015e248._2_2_ + sVar1),(int)DAT_8015e24c._2_2_,0x800);
  FUN_8010910c(obj);
  if (cVar2 == '\0') {
    obj->sub3 = 1;
    obj->field_0x4 = 0;
    Anim_Set(obj,9);
  }
  return;
}


// ---- 801e33bc FUN_801e33bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e33bc(MM8Obj *obj)

{
  Anim_Step();
  if (obj->anim_extra != 0) {
    obj->field_0x51 = 0;
    FUN_8010544c(obj,0xa7);
    FUN_80111ef8(3,3);
  }
  if ((short)obj->frame < 0) {
    obj->sub3 = 2;
    obj->field_0x50 = 0x3c;
  }
  return;
}


// ---- 801e3428 FUN_801e3428

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3428(MM8Obj *obj)

{
  FUN_801e3794();
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


// ---- 801e3490 FUN_801e3490

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3490(MM8Obj *obj)

{
  int iVar1;
  undefined4 *puVar2;
  
  DAT_8015e282 = 1;
  DAT_801d292c = g_cam_y;
  (*(code *)(&PTR_FUN_801e9e18)[obj->sub2])();
  iVar1 = FUN_80105ea4(obj,0xd);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(&DAT_801b103c + iVar1 * 4);
    do {
      iVar1 = iVar1 + -1;
      Obj_Free(*puVar2);
      puVar2 = puVar2 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ---- 801e3538 FUN_801e3538

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3538(MM8Obj *obj)

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


// ---- 801e35e8 FUN_801e35e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e35e8(MM8Obj *obj)

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
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e36b8 FUN_801e36b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e36b8(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if ((obj->field_0x50 & 7) == 0) {
    uVar2 = Rand();
    uVar3 = Rand();
    FUN_80108ed8(obj,(int)(((uVar2 & 0x3f) - 0x1f) * 0x10000) >> 0x10,
                 (int)(((uVar3 & 0x3f) - 0x1f) * 0x10000) >> 0x10);
  }
  if ((obj->field_0x50 & 1) != 0) {
    FUN_80103184(obj);
    Obj_CullAndQueueDraw(obj);
  }
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
                    /* Possible PsyQ macro: setPolyF3() */
  return;
}


// ---- 801e3794 FUN_801e3794

void FUN_801e3794(int param_1)

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
      sVar1 = *(short *)(param_1 + 0x12) + 1;
    }
    *(short *)(param_1 + 0x12) = sVar1;
  }
  return;
}


// ---- 801e37dc FUN_801e37dc

undefined4 FUN_801e37dc(int param_1,short param_2,short param_3,short param_4)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  
  sVar2 = FUN_801054b4((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),(int)param_2,
                       (int)param_3);
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
                    /* Possible PsyQ macro: setPolyF4() */
  return uVar4;
}


// ---- 801e38d0 FUN_801e38d0

void FUN_801e38d0(void)

{
  if ((DAT_80170574 & 0xf) == 0) {
    FUN_8010910c();
  }
  return;
}


// ---- 801e3900 FUN_801e3900

void FUN_801e3900(int param_1)

{
  uint uVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  do {
    uVar1 = Rand();
    *(undefined *)(param_1 + 2) = (&DAT_801e9d38)[uVar1 & 0xf];
    if (*(char *)(param_1 + 2) != *(char *)(param_1 + 0x58)) {
      *(undefined1 *)(param_1 + 0x59) = 1;
      *(undefined1 *)(param_1 + 0x58) = *(undefined1 *)(param_1 + 2);
      goto LAB_801e398c;
    }
  } while (1 < *(byte *)(param_1 + 0x59));
  *(char *)(param_1 + 0x59) = *(char *)(param_1 + 0x59) + '\x01';
  *(undefined1 *)(param_1 + 0x58) = *(undefined1 *)(param_1 + 2);
LAB_801e398c:
  if ((uVar1 & 0xff) == 1) {
    iVar2 = (int)*(short *)(param_1 + 0xe);
                    /* Possible PsyQ macro: setLineF2() */
    if (((iVar2 < DAT_801d2918._2_2_ + 0x40) && (DAT_8015e248._2_2_ < iVar2)) ||
       ((DAT_801d2918._2_2_ + 0x220 < iVar2 && (iVar2 < DAT_8015e248._2_2_)))) {
      *(undefined1 *)(param_1 + 2) = 2;
    }
  }
  return;
}


// ---- 801e3a0c FUN_801e3a0c

void FUN_801e3a0c(int param_1)

{
  if (*(char *)(param_1 + 0x51) != '\0') {
    *(undefined **)(param_1 + 0x3c) = &DAT_801e9d20;
    *(undefined1 *)(param_1 + 0x44) = 10;
    *(undefined1 *)(param_1 + 2) = 6;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    *(undefined1 *)(param_1 + 0x43) = 1;
  }
  return;
}


// ---- 801e3a50 FUN_801e3a50

undefined1 * FUN_801e3a50(int param_1,undefined1 param_2,char param_3,char param_4)

{
  undefined1 uVar1;
  short sVar2;
  undefined1 *puVar3;
  
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


// ---- 801e3b1c FUN_801e3b1c

void FUN_801e3b1c(int param_1)

{
  if (0x80000 < *(int *)(param_1 + 0x18) + 0x40000U) {
    *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
  }
  return;
}


// ---- 801e3b50 FUN_801e3b50

void FUN_801e3b50(int param_1)

{
  *(undefined **)(param_1 + 0x3c) = &DAT_801e9d2c;
  *(undefined1 *)(param_1 + 0x44) = 1;
  Enemy_CheckWeaponHits();
  *(undefined **)(param_1 + 0x3c) = &DAT_801e9d24;
  *(undefined1 *)(param_1 + 0x44) = 10;
  return;
}


