// ID 35, STAGE04.BIN, handler 0x801E1094. Ghidra output with the object struct applied; not matching C.
// ---- 801e1094 FUN_801e1094

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1094(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  (*(code *)(&PTR_FUN_801e723c)[obj->state])();
  return;
}


// ---- 801e10d0 FUN_801e10d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e10d0(MM8Obj *obj)

{
  short sVar1;
  
  Enemy_InitFromTable();
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
  obj->field_0x49 = 4;
  obj->draw_list = 6;
  if ((obj->var & 0x7f) == 0) {
                    /* Probable PsyQ macro: setTile8() */
    if ((obj->var & 0x80) == 0) {
      FUN_80103794(0x30,0xfe,1);
    }
    obj->x = DAT_801d2928 + 0xd0;
    sVar1 = DAT_801d292c;
    obj->hitbox = &DAT_801e71a8;
    obj->flip = 0;
    obj->box2 = &DAT_801e71b4;
    obj->field_0x51 = 0;
    obj->field_0x54 = 0;
    obj->field_0x5c = 0;
    obj->field_0x55 = 0;
    obj->field_0x5f = 0;
    obj->field_0x5d = 0;
    obj->field_0x57 = 1;
    obj->field_0x58 = 0;
    obj->y = sVar1 + 0xb4;
    Anim_Set(obj,1);
    FUN_8010bb88(0,0);
    obj->state = 1;
  }
  else {
    obj->invuln = 1;
    obj->hp = 0;
    obj->field_0x56 = 1;
    Anim_Set(obj,0xc);
    obj->state = 4;
  }
  FUN_80103224(obj);
  return;
}


// ---- 801e11e8 FUN_801e11e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e11e8(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e7250)[obj->sub2])();
  return;
}


// ---- 801e16e4 FUN_801e16e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e16e4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801e7268)[obj->sub2])();
  obj->clut = DAT_80159fc2;
  if (obj->field_0x51 == '\0') {
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (iVar2 == 4) {
      FUN_8010544c(obj,0xe2);
      FUN_8010544c(obj,0x10);
      obj->state = 3;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      DAT_8015e2af = 1;
      return;
    }
    if (iVar2 == 2) {
      obj->field_0x51 = 0x3c;
      FUN_8010544c(obj,0xe2);
      FUN_8010544c(obj,0x10);
    }
  }
  else {
    bVar1 = obj->hp;
    obj->hp = 0x28;
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (iVar2 == 2) {
      FUN_8010544c(obj,0x4f);
    }
    obj->hp = bVar1;
    bVar1 = obj->field_0x51 - 1;
    obj->field_0x51 = bVar1;
    if ((bVar1 & 1) != 0) {
      obj->clut = 0;
    }
  }
  Enemy_ContactDamage(obj);
  if (obj->active != 0) {
    FUN_80103184(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e1840 FUN_801e1840

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1840(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  
  sVar2 = DAT_801d2928;
  sVar1 = DAT_8015e248._2_2_;
  if (obj->sub3 == 0) {
    obj->hitbox = &DAT_801e71a8;
    obj->box2 = &DAT_801e71b4;
    obj->field_0x50 = 0x1e;
    if ((obj->field_0x55 != '\0') || ((byte)obj->field_0x57 < 2)) {
      obj->field_0x50 = 10;
    }
    Anim_Set(obj,0);
    obj->sub3 = 1;
  }
  cVar3 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar3;
  if (cVar3 == '\0') {
    obj->sub3 = 0;
    iVar4 = (int)sVar1 - (int)obj->x;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    obj->field_0x4 = 0;
    if (obj->field_0x55 == '\0') {
      if (obj->field_0x57 == '\x02') {
        bVar6 = 1;
        obj->field_0x57 = 0;
      }
      else {
        if ((short)iVar4 < 0x80) {
          uVar5 = Rand();
          bVar6 = (&DAT_801e71d0)[uVar5 & 0xf];
        }
        else {
          uVar5 = Rand();
          bVar6 = (&DAT_801e71c0)[uVar5 & 0xf];
        }
        obj->field_0x57 = obj->field_0x57 + '\x01';
      }
      if (obj->hp < 0xb) {
        bVar6 = 5;
      }
    }
    else if ((int)obj->x < sVar2 + 0xf0) {
      uVar5 = Rand();
      bVar6 = (&DAT_801e71e0)[uVar5 & 0xf];
    }
    else {
      uVar5 = Rand();
      bVar6 = (&DAT_801e71f0)[uVar5 & 0xf];
    }
    obj->field_0x54 = bVar6;
    obj->sub2 = bVar6;
  }
  FUN_801e3518(obj);
  return;
}


// ---- 801e1a24 FUN_801e1a24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1a24(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e728c)[obj->sub3])();
  FUN_801e3518(obj);
  return;
}


// ---- 801e1a74 FUN_801e1a74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1a74(MM8Obj *obj)

{
  short sVar1;
  
  FUN_8010910c();
  if ((obj->flip & 0x40) == 0) {
    if ((int)obj->x <= DAT_801d2928 + 0x4a) {
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
    }
  }
  else if (DAT_801d2928 + 0xf6 <= (int)obj->x) {
    obj->flip = 0;
  }
  sVar1 = DAT_801d2928;
  if ((obj->flip & 0x40) == 0) {
    obj->speed_x = -0x50000;
    obj->accel_x = 0x4000;
    sVar1 = sVar1 + 0x20;
  }
  else {
    obj->speed_x = 0x50000;
    obj->accel_x = -0x4000;
    sVar1 = sVar1 + 0x120;
  }
  *(short *)&obj->field_0x52 = sVar1;
  obj->hitbox = &DAT_801e71ac;
  obj->speed_y_up = 0;
  obj->box2 = &DAT_801e71b9;
  obj->field_0x56 = 1;
  Anim_Set(obj,10);
  if (obj->field_0x58 == '\0') {
    FUN_8010544c(obj,0xdb);
  }
  obj->field_0x58 = 0;
  obj->sub3 = 1;
  obj->field_0x4 = 0;
  return;
}


// ---- 801e1b9c FUN_801e1b9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1b9c(MM8Obj *obj)

{
  short sVar1;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    if ((short)obj->frame < 0) {
      obj->contact_dmg = 5;
      Anim_Set(obj,0xb);
      FUN_801e35d8(obj,0xc,4);
                    /* Possible PsyQ macro: setPolyF4() */
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104c34(obj);
    FUN_80106214(obj);
    if ((((0 < obj->speed_x) && (*(short *)&obj->field_0x52 < obj->x)) ||
        ((obj->speed_x < 0 && (obj->x < *(short *)&obj->field_0x52)))) ||
       ((obj->field_0x33 & 0x30) != 0)) {
      obj->hitbox = &DAT_801e71a8;
      obj->box2 = &DAT_801e71b4;
      obj->contact_dmg = 4;
      Anim_Set(obj,0xd);
      obj->field_0x56 = 0;
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
    if (DAT_80170574 == (DAT_80170574 / 3) * 3) {
      if ((obj->flip & 0x40) == 0) {
        sVar1 = 0xd;
      }
      else {
        sVar1 = -0xd;
      }
      FUN_801091a4((int)(short)(obj->x + sVar1),(int)(((ushort)obj->y + 0x1b) * 0x10000) >> 0x10,1);
    }
  }
  return;
}


// ---- 801e1d24 FUN_801e1d24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1d24(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  if (obj->field_0x4 == '\0') {
    FUN_80104c9c();
    if ((obj->speed_x == 0) || ((obj->speed_x & 0x80000000U) == (obj->accel_x & 0x80000000U))) {
      obj->field_0x4 = 1;
    }
  }
  Anim_Step(obj);
  FUN_80106214(obj);
  if (((short)obj->frame < 0) && (obj->field_0x4 != '\0')) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->field_0x57 = 0;
  }
  return;
}


// ---- 801e1dcc FUN_801e1dcc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1dcc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e7298)[obj->sub3])();
  FUN_801e3518(obj);
  return;
}


// ---- 801e1e1c FUN_801e1e1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1e1c(MM8Obj *obj)

{
  short sVar1;
  ushort *puVar2;
  short sVar3;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  int iVar4;
  
  if (obj->field_0x4 == '\0') {
    obj->hitbox = &DAT_801e71b0;
    if (obj->field_0x55 == '\0') {
      iVar5._0_2_ = obj->x_frac;
      iVar5._2_2_ = obj->x;
      if (iVar5 < DAT_8015e248) {
        iVar5 = DAT_8015e248 + -0x100000;
      }
      else {
        iVar5 = DAT_8015e248 + 0x100000;
      }
    }
    else {
      uVar6 = 0;
      puVar2 = &DAT_801e7228;
      puVar7 = &DAT_801e722a;
      do {
        iVar5 = (uint)DAT_801d2928 + (uint)*puVar2;
        sVar1 = (short)iVar5;
        iVar4 = (uint)DAT_801d2928 + (uint)*puVar7;
        sVar3 = (short)iVar4;
        if ((iVar5 * 0x10000 >> 0x10 <= (int)DAT_8015e248._2_2_) &&
           (uVar8 = uVar6, (int)DAT_8015e248._2_2_ < iVar4 * 0x10000 >> 0x10)) break;
        puVar7 = puVar7 + 2;
        uVar6 = uVar6 + 1;
        puVar2 = puVar2 + 2;
        uVar8 = 0;
      } while ((int)uVar6 < 4);
      if ((byte)obj->field_0x5c == uVar8) {
        uVar6 = Rand();
        if ((uVar6 & 1) == 0) {
          uVar8 = uVar8 + 1;
        }
        else {
          uVar8 = uVar8 - 1;
        }
        if ((int)uVar8 < 0) {
          uVar8 = 4;
        }
        else if (4 < (int)uVar8) {
          uVar8 = 0;
        }
        sVar1 = DAT_801d2928 + (&DAT_801e7228)[uVar8 * 2];
        sVar3 = DAT_801d2928 + (&DAT_801e722a)[uVar8 * 2];
      }
      iVar5 = ((int)sVar1 + ((int)sVar3 - (int)sVar1 >> 1)) * 0x10000;
      obj->field_0x5c = (char)uVar8;
    }
    obj->speed_y_up = 0x66900;
    obj->gravity = 0x4000;
    obj->speed_x = (iVar5 - *(int *)&obj->x_frac) / 0x34;
    FUN_8010910c(obj);
    Anim_Set(obj,3);
    obj->field_0x43 = 1;
    obj->field_0x4 = 1;
  }
  else {
    Anim_Step(obj);
    if (obj->anim_extra != 0) {
      FUN_8010544c(obj,0xd9);
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e204c FUN_801e204c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e204c(MM8Obj *obj)

{
  FUN_80104ccc();
  FUN_80106214(obj);
  Anim_Step(obj);
  if (obj->field_0x4 == '\0') {
    if (obj->speed_y_up < 0x3d000) {
      Anim_Set(obj,4);
      obj->field_0x4 = 1;
    }
  }
  else if ((short)obj->frame < 0) {
    Anim_Set(obj,5);
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e20e0 FUN_801e20e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e20e0(MM8Obj *obj)

{
  FUN_801e3590();
  FUN_80106214(obj);
  Anim_Step(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x43 = 0;
    Anim_Set(obj,6);
    FUN_8010544c(obj,0xda);
    obj->sub3 = 3;
  }
  return;
}


// ---- 801e214c FUN_801e214c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e214c(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    obj->hitbox = &DAT_801e71a8;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e219c FUN_801e219c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e219c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e72a8)[obj->sub3])();
  FUN_801e3518(obj);
  return;
}


// ---- 801e21ec FUN_801e21ec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e21ec(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  
  if (obj->field_0x4 == '\0') {
    FUN_8010910c();
    Anim_Set(obj,7);
    obj->field_0x5e = 0;
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (obj->anim_extra != 0) {
    puVar3 = (undefined1 *)Obj_AllocMain();
    if (puVar3 == (undefined1 *)0x0) {
      obj->field_0x5e = 1;
    }
    else {
      *puVar3 = 1;
      puVar3[6] = 0x36;
      puVar3[7] = 0;
      sVar2 = 0x1d;
      if ((obj->flip & 0x40) == 0) {
        sVar2 = -0x1d;
      }
      *(short *)(puVar3 + 0xe) = obj->x + sVar2;
      *(short *)(puVar3 + 0x12) = obj->y + -6;
      bVar1 = obj->flip;
      *(MM8Obj **)(puVar3 + 0x4c) = obj;
      puVar3[0x25] = bVar1;
      uVar4 = 0xc0;
      if ((obj->flip & 0x40) != 0) {
        uVar4 = 0x40;
      }
      puVar3[0x56] = uVar4;
    }
    FUN_8010544c(obj,0xdc);
    obj->sub3 = 1;
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e22f0 FUN_801e22f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e22f0(MM8Obj *obj)

{
                    /* Probable PsyQ macro: setPolyFT4() */
  Anim_Step();
  if (obj->field_0x5e == '\x02') {
    Anim_Set(obj,2);
    FUN_8010544c(obj,0xe1);
    obj->sub3 = 2;
    obj->field_0x4 = 0;
    obj->field_0x50 = 0;
  }
  else {
    FUN_801e247c(obj);
  }
  return;
}


// ---- 801e2358 FUN_801e2358

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2358(MM8Obj *obj)

{
  byte bVar1;
  ushort uVar2;
  undefined1 *puVar3;
  uint uVar4;
  short sVar5;
  
  Anim_Step();
  DAT_801d2936 = 1;
  if (obj->field_0x5e == '\x01') {
    obj->sub3 = 3;
  }
  else if ((DAT_80170574 == (DAT_80170574 / 0x18) * 0x18) &&
          (puVar3 = (undefined1 *)Obj_AllocMain(), puVar3 != (undefined1 *)0x0)) {
    *puVar3 = 1;
    puVar3[6] = 0x36;
    puVar3[7] = 1;
    bVar1 = obj->field_0x50;
    obj->field_0x50 = bVar1 + 1;
    if ((bVar1 & 1) == 0) {
      uVar4 = Rand();
      uVar2 = *(ushort *)(&DAT_801e7208 + (uVar4 & 0xf) * 2);
      sVar5 = DAT_801d2928;
    }
    else {
      uVar2 = Rand();
      uVar2 = uVar2 & 0x1f;
      sVar5 = DAT_8015e248._2_2_ + -0xf;
    }
    *(ushort *)(puVar3 + 0xe) = sVar5 + uVar2;
    *(undefined2 *)(puVar3 + 0x12) = DAT_801d292a;
  }
  return;
}


// ---- 801e247c FUN_801e247c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e247c(MM8Obj *obj)

{
  Anim_Step();
  if ((obj->field_0x5e == '\x01') && ((short)obj->frame < 0)) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e24d0 FUN_801e24d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e24d0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e72b8)[obj->sub3])();
  FUN_801e3518(obj);
  return;
}


// ---- 801e2520 FUN_801e2520

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2520(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->hitbox = &DAT_801e71b0;
    iVar1 = (int)DAT_801d2928;
    if ((int)obj->x < iVar1 + 0xa0) {
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
      iVar1 = iVar1 + 0x120;
    }
    else {
      obj->flip = 0;
      iVar1 = iVar1 + 0x20;
    }
    obj->speed_y_up = 0x81930;
    obj->gravity = 0x4000;
    obj->speed_x = (iVar1 * 0x10000 - *(int *)&obj->x_frac) / 0x3a;
    Anim_Set(obj,3);
    obj->field_0x43 = 1;
    obj->field_0x4 = 1;
  }
  else {
    Anim_Step(obj);
    if (obj->anim_extra != 0) {
      FUN_8010544c(obj,0xd9);
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e261c FUN_801e261c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e261c(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  undefined1 *puVar3;
  int iVar4;
  
  FUN_80104ccc();
  FUN_80106214(obj);
  Anim_Step(obj);
  if (obj->field_0x4 == '\0') {
    if ((obj->speed_y_up == 0) || ((obj->speed_y_up & 0x80000000U) != (obj->gravity & 0x80000000U)))
    {
      obj->flip = obj->flip ^ 0x40;
      Anim_Set(obj,8);
      obj->field_0x4 = 1;
    }
  }
  else {
    bVar1 = obj->anim_extra;
    if ((char)bVar1 != 0) {
      puVar3 = (undefined1 *)Obj_AllocMain();
      iVar4 = (char)bVar1 + -1;
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        puVar3[6] = 0x36;
        puVar3[7] = bVar1 + 1;
        if ((obj->flip & 0x40) == 0) {
          sVar2 = (short)(char)(&DAT_801e7200)[iVar4 * 0x1000000 >> 0x17];
        }
        else {
          sVar2 = -(short)(char)(&DAT_801e7200)[iVar4 * 0x1000000 >> 0x17];
        }
        *(short *)(puVar3 + 0xe) = obj->x + sVar2;
        *(short *)(puVar3 + 0x12) = (short)(char)(&DAT_801e7201)[iVar4 * 0x1000000 >> 0x17] + obj->y
        ;
        puVar3[0x25] = obj->flip;
      }
      FUN_8010544c(obj,0xde);
    }
    if ((short)obj->frame < 0) {
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e2798 FUN_801e2798

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2798(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e72c8)[obj->sub3])();
  return;
}


// ---- 801e27d4 FUN_801e27d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e27d4(MM8Obj *obj)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = DAT_801d2928;
  uVar3 = (uint)DAT_801d2928;
  if (obj->field_0x4 == '\0') {
    obj->hitbox = &DAT_801e71b0;
    if ((int)obj->x < (short)uVar1 + 0xa0) {
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
      iVar2 = uVar3 + 0x130;
    }
    else {
      obj->flip = 0;
      iVar2 = uVar3 + 0x10;
    }
    obj->field_0x5e = 0;
    obj->speed_y_up = 0x81930;
    obj->gravity = 0x4000;
    obj->speed_x = (iVar2 * 0x10000 - *(int *)&obj->x_frac) / 0x21;
    Anim_Set(obj,3);
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (obj->anim_extra != 0) {
    FUN_8010544c(obj,0xd9);
    obj->sub3 = 1;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e28cc FUN_801e28cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e28cc(MM8Obj *obj)

{
  FUN_80104ccc();
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->flip = obj->flip ^ 0x40;
    Anim_Set(obj,8);
    obj->sub3 = 2;
  }
  return;
}


// ---- 801e292c FUN_801e292c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e292c(MM8Obj *obj)

{
  short sVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  
  Anim_Step();
  iVar4 = 0;
  if (obj->anim_extra == 3) {
    do {
      puVar3 = (undefined1 *)Obj_AllocMain();
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        puVar3[6] = 0x36;
        puVar3[7] = (char)iVar4 + '\t';
        puVar3[0x25] = obj->flip;
        if ((obj->flip & 0x40) == 0) {
          sVar1 = (short)DAT_801e7204;
        }
        else {
          sVar1 = -(short)DAT_801e7204;
        }
        *(short *)(puVar3 + 0xe) = obj->x + sVar1;
        cVar2 = DAT_801e7205;
        sVar1 = obj->y;
        *(MM8Obj **)(puVar3 + 0x4c) = obj;
        *(short *)(puVar3 + 0x12) = cVar2 + sVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 * 0x10000 >> 0x10 < 4);
    FUN_8010544c(obj,0xdf);
    obj->sub3 = 3;
  }
  return;
}


// ---- 801e2a24 FUN_801e2a24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2a24(MM8Obj *obj)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  Anim_Step();
  if (obj->field_0x5e != '\0') {
    if ((obj->var & 0x80) == 0) {
      FUN_80102ecc(0x20);
      DAT_801d292a = 0xb00;
    }
    else {
      FUN_80102ecc(0xc);
      DAT_801d292a = 0x600;
    }
    uVar4 = 0x10;
    DAT_801d2938 = 0x5a;
    DAT_801d292c = DAT_801d292a;
    do {
      uVar1 = Rand();
      iVar3 = DAT_801d2928 + uVar4;
      uVar2 = Rand();
      uVar4 = uVar4 + 0x10;
      FUN_801e36ac((int)((iVar3 + (uVar1 & 7) + 0xfffc) * 0x10000) >> 0x10,
                   (int)(((DAT_801d292a - 0xf) + (uVar2 & 0x1f)) * 0x10000) >> 0x10,2);
    } while (uVar4 < 0x130);
    iVar3 = -0x4000;
    if ((obj->flip & 0x40) != 0) {
      iVar3 = 0x4000;
    }
    obj->speed_x = iVar3;
    obj->speed_y_up = -0x4000;
    Anim_Set(obj,5);
    obj->sub3 = 4;
  }
  return;
}


// ---- 801e2b54 FUN_801e2b54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2b54(MM8Obj *obj)

{
  FUN_801e3590();
  FUN_80106214(obj);
  Anim_Step(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x43 = 0;
    obj->field_0x55 = 1;
    Anim_Set(obj,6);
    obj->sub3 = 5;
  }
  return;
}


// ---- 801e2bbc FUN_801e2bbc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2bbc(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_801e2bfc();
  }
  else {
    FUN_801e2c7c();
  }
  return;
}


// ---- 801e2bfc FUN_801e2bfc

void FUN_801e2bfc(int param_1)

{
  Anim_Set(param_1,9);
                    /* Possible PsyQ macro: setPolyGT4() */
  *(undefined1 *)(param_1 + 0x51) = 0x3c;
  *(undefined **)(param_1 + 0x3c) = &DAT_801e71a8;
  *(undefined1 *)(param_1 + 0x45) = 4;
  *(undefined4 *)(param_1 + 0x18) = 0xffffc000;
  *(undefined4 *)(param_1 + 0x20) = 0x4000;
  *(undefined1 *)(param_1 + 0x54) = 6;
  *(undefined1 *)(param_1 + 0x5f) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 3) = 1;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_8010544c(param_1,0xe3);
  return;
}


// ---- 801e2c7c FUN_801e2c7c

void FUN_801e2c7c(int param_1)

{
  if (*(char *)(param_1 + 4) == '\0') {
    FUN_801e3590();
    if (*(char *)(param_1 + 0x32) == '\0') {
      Anim_Step(param_1);
    }
    FUN_80106214(param_1);
    if ((*(byte *)(param_1 + 0x33) & 0x80) != 0) {
      *(undefined1 *)(param_1 + 4) = 1;
    }
  }
  else {
    Anim_Step(param_1);
    if (*(short *)(param_1 + 0x2e) < 0) {
      if (*(char *)(param_1 + 0x55) == '\0') {
        *(undefined1 *)(param_1 + 2) = 1;
        *(undefined1 *)(param_1 + 0x58) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 2) = 0;
        *(undefined1 *)(param_1 + 0x57) = 0;
      }
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
  return;
}


// ---- 801e2d38 FUN_801e2d38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2d38(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e72e0)[obj->sub3])();
  FUN_801e3518(obj);
  return;
}


// ---- 801e2d88 FUN_801e2d88

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2d88(MM8Obj *obj)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_801d2928;
  if (obj->field_0x4 == '\0') {
    obj->hitbox = &DAT_801e71b0;
    if (obj->x < DAT_8015e248._2_2_) {
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
      iVar1 = uVar2 + 0x130;
    }
    else {
      obj->flip = 0;
      iVar1 = uVar2 + 0x10;
    }
    obj->speed_y_up = 0x70690;
    obj->gravity = 0x4000;
    obj->speed_x = (iVar1 * 0x10000 - *(int *)&obj->x_frac) / 0x1d;
    Anim_Set(obj,3);
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (obj->anim_extra != 0) {
    obj->sub3 = 1;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e2e74 FUN_801e2e74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2e74(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  
  if (obj->field_0x4 == '\0') {
    cVar3 = FUN_80104db0((int)obj->x,(int)obj->y,(int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_);
                    /* Possible PsyQ macro: setPolyFT4() + setSemiTrans(polyFT4, 1) */
    if ((obj->flip & 0x40) != 0) {
      cVar3 = -cVar3;
    }
    uVar4 = 1;
    if (0x1f < (byte)(cVar3 + 0x80U)) {
      uVar4 = 2;
    }
    obj->field_0x56 = uVar4;
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (obj->anim_extra == obj->field_0x56) {
    puVar5 = (undefined1 *)Obj_AllocMain();
    if (puVar5 != (undefined1 *)0x0) {
      *puVar5 = 1;
      puVar5[6] = 0x36;
      puVar5[7] = 0xd;
      sVar2 = 0x1d;
      if ((obj->flip & 0x40) == 0) {
        sVar2 = -0x1d;
      }
      *(short *)(puVar5 + 0xe) = obj->x + sVar2;
      *(short *)(puVar5 + 0x12) = obj->y + -6;
      bVar1 = obj->flip;
      *(MM8Obj **)(puVar5 + 0x4c) = obj;
      puVar5[0x25] = bVar1;
      uVar4 = FUN_80104db0((int)*(short *)(puVar5 + 0xe),(int)*(short *)(puVar5 + 0x12),
                           (int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_);
      puVar5[0x56] = uVar4;
      obj->field_0x5d = obj->field_0x5d + '\x01';
    }
    FUN_8010544c(obj,0xdc);
    obj->sub3 = 3;
    obj->field_0x4 = 0;
    obj->field_0x50 = 0x14;
  }
  return;
}


// ---- 801e2fe4 FUN_801e2fe4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2fe4(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 != '\0') {
      return;
    }
    Anim_Set(obj,5);
    obj->field_0x4 = 1;
  }
  FUN_801e3590(obj);
  Anim_Step(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x43 = 0;
    Anim_Set(obj,6);
    obj->sub3 = 4;
  }
  return;
}


// ---- 801e3084 FUN_801e3084

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3084(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_8010910c();
    Anim_Set(obj,2);
    obj->sub3 = 1;
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
  }
  FUN_801e3518(obj);
  return;
}


// ---- 801e3150 FUN_801e3150

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3150(MM8Obj *obj)

{
  Anim_Set(obj,9);
  FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  FUN_800fcd84();
  FUN_8010bbb8();
  obj->field_0x50 = 0x78;
  obj->sub2 = 1;
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e31e0 FUN_801e31e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e31e0(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  if (obj->anim_extra == 0) {
    Anim_Step();
  }
  if (obj->sub3 == 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x50 = 0x3c;
    obj->sub3 = 1;
  }
  if ((obj->field_0x50 & 1) == 0) {
    obj->clut = DAT_80159fc2;
  }
  else {
    obj->clut = 0;
  }
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x50 = 0x78;
    bVar1 = DAT_80159fc2;
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->clut = bVar1;
  }
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e32ac FUN_801e32ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e32ac(MM8Obj *obj)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  byte bVar8;
  
  if ((obj->field_0x50 & 7) == 0) {
    uVar3 = Rand();
    uVar4 = Rand();
    FUN_80108ed8(obj,(int)(((uVar3 & 0x3f) - 0x1f) * 0x10000) >> 0x10,
                 (int)(((uVar4 & 0x1f) - 0xf) * 0x10000) >> 0x10);
  }
  if ((obj->field_0x50 & 1) != 0) {
    FUN_80103184(obj);
    Obj_CullAndQueueDraw(obj);
  }
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
    if ((obj->var & 0x80) == 0) {
      FUN_80102ecc(0x22);
      uVar7 = 0xbc0;
    }
    else {
      FUN_80102ecc(0xe);
      uVar7 = 0x6c0;
    }
    iVar6 = (int)((DAT_801d2928 + 0xa0) * 0x10000) >> 0x10;
    iVar5 = FUN_801091a4(iVar6,uVar7,0x80);
    bVar8 = 0;
    if (iVar5 != 0) {
      *(undefined1 *)(iVar5 + 0x26) = 3;
                    /* Possible PsyQ macro: setPolyGT3() */
      *(undefined1 *)(iVar5 + 0x27) = 0x34;
      uVar1 = DAT_80159f98;
      *(undefined1 *)(iVar5 + 0x38) = 0;
      *(undefined1 *)(iVar5 + 0x24) = uVar1;
    }
    do {
      FUN_801e36ac(iVar6,uVar7,1);
      bVar8 = bVar8 + 1;
                    /* Possible PsyQ macro: setLineF2() + setSemiTrans(lineF2, 1) */
    } while (bVar8 < 8);
    FUN_8010544c(obj,0xe4);
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->on_screen = 0;
    obj->field_0x50 = 1;
  }
  return;
}


// ---- 801e3518 FUN_801e3518

void FUN_801e3518(int param_1)

{
  byte bVar1;
  
  if ((*(char *)(param_1 + 0x51) == '\0') && (*(char *)(param_1 + 0x5f) != '\0')) {
    bVar1 = *(char *)(param_1 + 0x47) - 4;
    *(byte *)(param_1 + 0x47) = bVar1;
    if ((int)((uint)bVar1 << 0x18) < 1) {
      *(undefined1 *)(param_1 + 1) = 3;
      *(undefined1 *)(param_1 + 0x47) = 0;
      *(undefined1 *)(param_1 + 2) = 0;
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      DAT_8015e282 = 1;
    }
    else {
      *(undefined1 *)(param_1 + 2) = 6;
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
  return;
}


// ---- 801e3590 FUN_801e3590

void FUN_801e3590(int param_1)

{
  if (*(int *)(param_1 + 0x18) < -0x5bfff) {
    *(undefined4 *)(param_1 + 0x18) = 0xfffa0000;
    FUN_80104c34();
  }
  else {
    FUN_80104ccc();
  }
  return;
}


// ---- 801e35d8 FUN_801e35d8

void FUN_801e35d8(undefined1 *param_1,int param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = param_1;
  for (; param_2 != 0; param_2 = param_2 + -1) {
                    /* Possible PsyQ macro: setPolyGT4() */
    puVar2 = (undefined1 *)FUN_801055e4(puVar3);
    if (puVar2 != (undefined1 *)0x0) {
      if (param_3 == 0) {
        trap(0x1c00);
      }
      *puVar2 = 1;
      puVar2[6] = 0x35;
      if ((param_2 - 1U) % param_3 == 0) {
        puVar2[7] = 1;
      }
      else {
        puVar2[7] = 2;
      }
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      uVar1 = param_1[0x25];
      *(undefined1 **)(puVar2 + 0x58) = puVar3;
                    /* Probable PsyQ macro: setTile8() */
      puVar2[0x25] = uVar1;
      puVar3 = puVar2;
    }
  }
  return;
}


// ---- 801e36ac FUN_801e36ac

void FUN_801e36ac(undefined2 param_1,undefined2 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocType3();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x28;
    puVar1[7] = param_3;
    *(undefined2 *)(puVar1 + 0xe) = param_1;
    *(undefined2 *)(puVar1 + 0x12) = param_2;
  }
  return;
}


