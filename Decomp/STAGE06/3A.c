// ID 3A, STAGE06.BIN, handler 0x801DB7E0. Ghidra output with the object struct applied; not matching C.
// ---- 801db7e0 FUN_801db7e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db7e0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e57f8)[obj->state])();
  return;
}


// ---- 801db81c FUN_801db81c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db81c(MM8Obj *obj)

{
  short sVar1;
  byte bVar2;
  
  Enemy_InitFromTable();
  obj->field_0x49 = 5;
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
  if ((obj->var & 0x7f) == 0) {
    if ((obj->var & 0x80) != 0) {
      FUN_80103794(0x2a,0x4e,5);
    }
    obj->x = DAT_801d2928 + 0xe0;
    sVar1 = DAT_801d292a;
    obj->draw_list = 6;
    obj->hitbox = &DAT_801e57a8;
    obj->box2 = &DAT_801e57bc;
    obj->flip = 0;
    obj->field_0x53 = 0;
    obj->field_0x52 = 0;
    obj->field_0x56 = 0;
    obj->field_0x54 = 0;
    obj->field_0x57 = 0;
    obj->field_0x55 = 0;
    obj->field_0x58 = 0;
    obj->field_0x5a = 0;
    obj->field_0x59 = 2;
    obj->y = sVar1 + 0xe0;
    Anim_Set(obj,0);
    FUN_80103224(obj);
    bVar2 = 1;
  }
  else {
    obj->hitbox = &DAT_801e57a8;
    obj->draw_list = 5;
    obj->box2 = &DAT_801e57bc;
    Anim_Set(obj,0x10);
    obj->speed_x = 0x20000;
    if ((obj->flip & 0x40) != 0) {
      obj->speed_x = -0x20000;
    }
    obj->speed_y_up = 0x5c000;
    obj->gravity = 0x4000;
    obj->field_0x50 = 0x30;
    obj->field_0x43 = 1;
    FUN_80103224(obj);
    Obj_CullAndQueueDraw(obj);
    bVar2 = 4;
  }
  obj->state = bVar2;
  return;
}


// ---- 801db980 FUN_801db980

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db980(MM8Obj *obj)

{
                    /* Probable PsyQ macro: setTile16() */
  (*(code *)(&PTR_LAB_801e5810)[obj->sub2])();
                    /* Possible PsyQ macro: setTile8() */
  return;
}


// ---- 801dc19c FUN_801dc19c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc19c(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801e583c)[obj->sub2])();
  obj->clut = DAT_80159fc8;
  if (obj->field_0x53 == '\0') {
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (iVar2 == 2) {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x53 = 0x3c;
      FUN_8010544c(obj,0x10);
      if ((obj->field_0x58 & 0xf) == 0) {
        if (DAT_80158f5c == '\r') {
          obj->sub2 = 8;
          obj->sub3 = 0;
          obj->field_0x4 = 0;
        }
        else {
          FUN_8010544c(obj,0x154);
        }
      }
    }
    if (iVar2 == 4) {
      FUN_8010544c(obj,0x10);
      bVar1 = 5;
      if (obj->field_0x5a == '\0') {
        bVar1 = 3;
      }
      obj->state = bVar1;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      DAT_8015e2af = 1;
      goto LAB_801dc30c;
    }
  }
  else {
    bVar1 = obj->hp;
                    /* Possible PsyQ macro: setPolyF4() */
    obj->hp = 0x28;
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (iVar2 == 2) {
      FUN_8010544c(obj,0x4f);
    }
    obj->hp = bVar1;
    obj->field_0x53 = obj->field_0x53 + -1;
    if ((DAT_80170574 & 1) != 0) {
      obj->clut = 0;
    }
  }
  Enemy_ContactDamage(obj);
LAB_801dc30c:
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801dc334 FUN_801dc334

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc334(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  
  obj->field_0x55 = 0;
  obj->hitbox = &DAT_801e57a8;
  Anim_Set(obj,0);
  if (obj->field_0x54 == '\0') {
    uVar2 = Rand();
    bVar4 = (&DAT_801e57c8)[uVar2 & 0xf];
    obj->field_0x54 = 1;
  }
  else {
    uVar2 = Rand();
    bVar4 = (&DAT_801e57d8)[uVar2 & 0xf];
    if ((obj->field_0x56 == bVar4) &&
       (obj->field_0x57 = obj->field_0x57 + '\x01', 3 < (byte)obj->field_0x57)) {
      iVar3 = 0;
      do {
        uVar2 = Rand();
        bVar4 = (&DAT_801e57d8)[uVar2 & 0xf];
        iVar3 = iVar3 + 1;
        if (obj->field_0x56 != bVar4) {
          obj->field_0x57 = 0;
          break;
        }
      } while (iVar3 < 0x20);
    }
    if (obj->field_0x56 == '\x05') {
      uVar2 = Rand();
      bVar4 = (&DAT_801e57e8)[uVar2 & 0xf];
    }
  }
  if ((DAT_8015e283 < 6) && (0x13 < obj->hp)) {
    iVar3 = (int)DAT_8015e248._2_2_ - (int)obj->x;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
                    /* Possible PsyQ macro: setLineF2() */
    if ((iVar3 < 0x40) && (obj->field_0x59 != '\0')) {
      bVar4 = 9;
      obj->field_0x55 = 0;
      obj->field_0x59 = 0;
    }
  }
  if (obj->field_0x58 != '\0') {
    bVar4 = 2;
    obj->field_0x58 = 0x80;
  }
  if (bVar4 == 2) {
    bVar1 = obj->flip;
    FUN_8010910c(obj);
                    /* Possible PsyQ macro: setPolyF3() */
    iVar3 = FUN_801ddc3c(obj);
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
                    /* Possible PsyQ macro: setTile16() */
    if (iVar3 < 0xa00000) {
      obj->field_0x55 = 2;
      bVar4 = 7;
    }
    obj->flip = bVar1;
  }
  else if (bVar4 < 3) {
    if (bVar4 != 1) {
      obj->field_0x56 = bVar4;
      goto LAB_801dc5c0;
    }
    FUN_8010910c(obj);
    iVar3 = FUN_801ddc3c(obj);
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 >> 0x10 < 0x66) {
      obj->field_0x55 = 1;
LAB_801dc5b8:
      bVar4 = 3;
    }
  }
  else {
    if (bVar4 != 4) {
      obj->field_0x56 = bVar4;
      goto LAB_801dc5c0;
    }
    iVar3 = (int)DAT_8015e248._2_2_ - (int)obj->x;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 0x40) goto LAB_801dc5b8;
  }
  obj->field_0x56 = bVar4;
LAB_801dc5c0:
  obj->sub2 = bVar4;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801dc5ec FUN_801dc5ec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc5ec(MM8Obj *obj)

{
  Anim_Step();
  (*(code *)(&PTR_FUN_801e5864)[obj->sub3])(obj);
  return;
}


// ---- 801dc638 FUN_801dc638

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc638(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_8010910c();
    obj->field_0x51 = 0;
    Anim_Set(obj,9);
    FUN_8010544c(obj,0x14f);
    obj->field_0x4 = 1;
  }
  if ((short)obj->frame < 0) {
    obj->hitbox = &DAT_801e57ac;
    Anim_Set(obj,10);
    obj->sub3 = 1;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801dc6c8 FUN_801dc6c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc6c8(MM8Obj *obj)

{
  short sVar1;
  byte bVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  
  if (obj->anim_extra != 0) {
    puVar3 = (undefined1 *)Obj_AllocMain();
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 0x3b;
      puVar3[7] = 0;
      sVar1 = 0x35;
      if ((obj->flip & 0x40) == 0) {
        sVar1 = -0x35;
      }
      *(short *)(puVar3 + 0xe) = obj->x + sVar1;
      *(short *)(puVar3 + 0x12) = obj->y + -0x17;
      puVar3[0x25] = obj->flip;
      puVar3[0x5f] = obj->field_0x51;
    }
    uVar5 = 0;
    do {
      iVar4 = FUN_801ddb84(obj,0xffffffcb,0xffffffe9,8);
      uVar5 = uVar5 + 1;
      if (iVar4 != 0) {
        bVar2 = Rand();
        *(byte *)(iVar4 + 0x3a) = bVar2 % 3 + 3;
      }
    } while (uVar5 < 2);
    obj->anim_extra = 0;
  }
  if ((short)obj->frame < 0) {
    bVar2 = obj->field_0x51 + 1;
    obj->field_0x51 = bVar2;
    if (bVar2 < 6) {
      Anim_Set(obj,10);
    }
    else {
      obj->field_0x50 = 0x1e;
      obj->sub3 = 2;
    }
  }
  return;
}


// ---- 801dc86c FUN_801dc86c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc86c(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801e5870)[obj->sub3])();
  return;
}


// ---- 801dc8a8 FUN_801dc8a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc8a8(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = FUN_801ddb84(obj,0,0x40,0);
  if (iVar1 != 0) {
    *(MM8Obj **)(iVar1 + 0x3c) = obj;
  }
  iVar1 = FUN_801ddb84(obj,0,0x40,6);
  if (iVar1 != 0) {
    *(MM8Obj **)(iVar1 + 0x3c) = obj;
  }
  obj->field_0x52 = 0;
  obj->field_0x50 = 0x3c;
  if ((obj->field_0x58 & 0x80) == 0) {
    Anim_Set(obj,0xb);
  }
  else {
    Anim_Set(obj,0x14);
    obj->field_0x58 = 0;
  }
  FUN_8010544c(obj,0x153);
                    /* Probable PsyQ macro: setTile16() */
  obj->sub3 = 1;
  obj->field_0x4 = 0;
  return;
}


// ---- 801dc950 FUN_801dc950

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc950(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    Anim_Step();
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x52 = 1;
      obj->field_0x50 = 1;
      obj->field_0x4 = 1;
    }
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      FUN_8010910c(obj);
      Anim_Set(obj,0xc);
      FUN_8010544c(obj,0x157);
      obj->sub3 = 2;
    }
  }
  return;
}


// ---- 801dc9fc FUN_801dc9fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc9fc(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    FUN_801ddacc(obj,0xffffffc6,3,1);
    obj->field_0x52 = 0;
    Anim_Set(obj,0xd);
    FUN_8010544c(obj,0x14b);
    obj->hitbox = &DAT_801e57b0;
    obj->sub3 = 3;
  }
  return;
}


// ---- 801dca74 FUN_801dca74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dca74(MM8Obj *obj)

{
  Anim_Step();
                    /* Probable PsyQ macro: setPolyGT4() */
  if (obj->field_0x52 != '\0') {
    obj->field_0x54 = 0;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801dcabc FUN_801dcabc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcabc(MM8Obj *obj)

{
                    /* Probable PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801e5880)[obj->sub3])();
  return;
}


// ---- 801dcaf8 FUN_801dcaf8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcaf8(MM8Obj *obj)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  sVar2 = DAT_801d2928;
  FUN_8010910c();
  if ((obj->flip & 0x40) == 0) {
    iVar3 = DAT_8015e248._2_2_ + -0x30;
    iVar4 = sVar2 + 0x10;
    bVar1 = iVar3 < iVar4;
  }
  else {
    iVar3 = DAT_8015e248._2_2_ + 0x30;
    iVar4 = sVar2 + 0x130;
    bVar1 = iVar4 < iVar3;
  }
  if (bVar1) {
    iVar3 = iVar4;
  }
  obj->field_0x4 = 0;
  obj->speed_y_up = 0x70690;
  obj->sub3 = 1;
  obj->speed_x = (iVar3 * 0x10000 - *(int *)&obj->x_frac) / 0x3a;
  return;
}


// ---- 801dcbdc FUN_801dcbdc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcbdc(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,1);
    obj->field_0x43 = 1;
    obj->field_0x4 = 1;
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->gravity = 0x4000;
      Anim_Set(obj,2);
      FUN_8010544c(obj,0x14d);
      obj->hitbox = &DAT_801e57b4;
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801dcc74 FUN_801dcc74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcc74(MM8Obj *obj)

{
  Anim_Step();
  if (obj->speed_y_up < -0x5bfff) {
    obj->speed_y_up = -0x60000;
    FUN_80104c34(obj);
  }
  else {
    FUN_80104ccc(obj);
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    Anim_Set(obj,3);
    FUN_8010544c(obj,0x14c);
    obj->hitbox = &DAT_801e57a8;
    obj->field_0x43 = 0;
    obj->sub3 = 3;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801dcd1c FUN_801dcd1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcd1c(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    FUN_8010910c(obj);
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->sub2 = obj->field_0x55;
    if (obj->field_0x55 != '\0') {
      obj->field_0x56 = obj->field_0x55;
    }
  }
  return;
}


// ---- 801dcd80 FUN_801dcd80

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcd80(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5890)[obj->sub3])();
  return;
}


// ---- 801dcdbc FUN_801dcdbc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcdbc(MM8Obj *obj)

{
  int iVar1;
  
  FUN_8010910c();
  iVar1 = DAT_8015e248 - *(int *)&obj->x_frac;
  obj->field_0x4 = 0;
  obj->speed_y_up = 0x5c000;
  obj->sub3 = 1;
  obj->speed_x = iVar1 / 0x60;
  return;
}


// ---- 801dce2c FUN_801dce2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce2c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e58a0)[obj->sub3])();
  return;
}


// ---- 801dce68 FUN_801dce68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce68(MM8Obj *obj)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_801d2928;
  FUN_8010910c();
  if ((obj->flip & 0x40) == 0) {
    iVar1 = 0x100000;
  }
  else {
    iVar1 = 0x1300000;
  }
  obj->speed_x = (int)((uVar2 * 0x10000 + iVar1) - *(int *)&obj->x_frac) / 0x50;
  obj->speed_y_up = 0x9e666;
  obj->sub3 = 1;
  return;
}


// ---- 801dcf08 FUN_801dcf08

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcf08(MM8Obj *obj)

{
  int iVar1;
  short sVar2;
  
  DAT_801d2936 = 0x46;
  obj->field_0x52 = 0;
  FUN_8010544c(obj,0x151);
  iVar1 = FUN_801ddacc(obj,0,0,3);
  if (iVar1 != 0) {
    if ((int)DAT_8015e248._2_2_ < DAT_801d2928 + 0x38) {
      sVar2 = DAT_801d2928 + 0x38;
    }
    else {
      sVar2 = DAT_8015e248._2_2_;
      if (DAT_801d2928 + 0x108 < (int)DAT_8015e248._2_2_) {
        sVar2 = DAT_801d2928 + 0x108;
      }
    }
    *(short *)(iVar1 + 0xe) = sVar2;
    sVar2 = DAT_801d292a;
    *(undefined1 *)(iVar1 + 0x25) = 0;
    *(short *)(iVar1 + 0x12) = sVar2 + 0xe0;
  }
  obj->field_0x50 = 0x3c;
  obj->sub3 = 4;
  obj->field_0x4 = 0;
  Anim_Step();
  return;
}


// ---- 801dcfdc FUN_801dcfdc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcfdc(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  Anim_Step();
  if ((obj->field_0x4 == '\0') && ((short)obj->frame < 0)) {
    FUN_8010910c(obj);
    Anim_Set(obj,0);
    obj->field_0x4 = 1;
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  bVar2 = 5;
  if (cVar1 == '\0') {
    obj->sub2 = 6;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    if (obj->field_0x59 == '\x02') {
      bVar2 = 0x14;
    }
    if (((DAT_8015e283 < bVar2) && (0x1e < obj->hp)) && (obj->field_0x59 != '\0')) {
      obj->field_0x55 = 6;
      obj->sub2 = 9;
      obj->field_0x59 = obj->field_0x59 + -1;
    }
  }
  return;
}


// ---- 801dd0c4 FUN_801dd0c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd0c4(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e58b4)[obj->sub3])();
  return;
}


// ---- 801dd194 FUN_801dd194

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd194(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e58c4)[obj->sub3])();
  return;
}


// ---- 801dd1d0 FUN_801dd1d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd1d0(MM8Obj *obj)

{
  int iVar1;
  byte bVar2;
  
  FUN_8010910c();
  iVar1 = FUN_801ddc3c(obj);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  bVar2 = obj->flip ^ 0x40;
  obj->flip = bVar2;
  iVar1 = (0xa00000 - iVar1) / 0x3a;
  if ((bVar2 & 0x40) == 0) {
    iVar1 = -iVar1;
  }
                    /* Possible PsyQ macro: setPolyGT3() */
  obj->speed_y_up = 0x70690;
  obj->speed_x = iVar1;
  obj->sub3 = 1;
  obj->field_0x4 = 0;
  return;
}


// ---- 801dd26c FUN_801dd26c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd26c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e58d4)[obj->sub3])();
  return;
}


// ---- 801dd2a8 FUN_801dd2a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd2a8(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  obj->field_0x50 = 0x1e;
  obj->field_0x58 = 1;
  obj->speed_y_up = -0x4000;
  obj->gravity = 0x4000;
  Anim_Set(obj,0xe);
  obj->hitbox = &DAT_801e57b8;
  FUN_8012ae08(obj,0x30);
  iVar2 = -0x18;
  do {
    iVar1 = FUN_801ddb84(obj,(iVar2 + 10) * 0x1000000 >> 0x18,2,0xf);
    if (iVar1 != 0) {
      if (iVar2 << 0x18 < 1) {
                    /* Possible PsyQ macro: setLineF2() */
        *(undefined1 *)(iVar1 + 0x25) = 0x40;
      }
      else {
        *(undefined1 *)(iVar1 + 0x25) = 0;
      }
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 * 0x1000000 >> 0x18 < 0x18);
  obj->sub3 = 1;
  obj->field_0x4 = 0;
  return;
}


// ---- 801dd38c FUN_801dd38c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd38c(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  if (obj->field_0x50 != '\0') {
    obj->field_0x50 = obj->field_0x50 + -1;
    if ((uint)(byte)obj->field_0x50 % 6 == 0) {
      uVar2 = Rand();
      iVar3 = FUN_801ddb84(obj,(int)(((uVar2 & 0x1f) - 5) * 0x1000000) >> 0x18,2,0xf);
      if (iVar3 != 0) {
        if ((int)(((uVar2 & 0x1f) - 0xf) * 0x1000000) < 1) {
                    /* Possible PsyQ macro: setLineF2() */
          *(undefined1 *)(iVar3 + 0x25) = 0x40;
        }
        else {
          *(undefined1 *)(iVar3 + 0x25) = 0;
        }
      }
    }
  }
  Anim_Step(obj);
  if (obj->field_0x4 == '\0') {
    if (obj->speed_y_up < -0x5bfff) {
      obj->speed_y_up = -0x60000;
      FUN_80104c34(obj);
    }
    else {
      FUN_80104ccc(obj);
    }
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->field_0x4 = 1;
    }
  }
  else if (obj->field_0x50 == '\0') {
    obj->field_0x50 = 0x30;
    puVar4 = (undefined1 *)FUN_801055e4(obj);
    if (puVar4 != (undefined1 *)0x0) {
      *puVar4 = 1;
      puVar4[6] = 0x3a;
      puVar4[7] = 1;
      *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&obj->x_frac;
      *(undefined4 *)(puVar4 + 0x10) = *(undefined4 *)&obj->y_frac;
      bVar1 = obj->flip;
      *(MM8Obj **)(puVar4 + 0x5c) = obj;
      puVar4[0x25] = bVar1;
    }
    obj->field_0x5a = 1;
    obj->speed_x = 0x20000;
    if ((obj->flip & 0x40) != 0) {
      obj->speed_x = -0x20000;
    }
    obj->speed_y_up = 0;
    Anim_Set(obj,0xf);
    FUN_8010544c(obj,0x155);
    obj->sub3 = 2;
  }
                    /* Possible PsyQ macro: setPolyF3() */
  return;
}


// ---- 801dd564 FUN_801dd564

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd564(MM8Obj *obj)

{
  char cVar1;
  
  FUN_80104c34();
  FUN_80106214(obj);
  Anim_Step(obj);
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->field_0x5a = 0;
    Anim_Set(obj,0x11);
    obj->hitbox = &DAT_801e57a8;
    obj->field_0x50 = 0x46;
    obj->sub3 = 3;
  }
  return;
}


// ---- 801dd5e0 FUN_801dd5e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd5e0(MM8Obj *obj)

{
  char cVar1;
  
  Anim_Step();
  if (((short)obj->frame < 0) &&
     (cVar1 = obj->field_0x50 + -1, obj->field_0x50 = cVar1, cVar1 == '\0')) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801dd640 FUN_801dd640

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd640(MM8Obj *obj)

{
  short sVar1;
  
  if (obj->sub3 == 0) {
    Anim_Set(obj,0x12);
    FUN_8010544c(obj,0x156);
    obj->sub3 = 1;
  }
  else {
    Anim_Step(obj);
    if (obj->anim_extra != 0) {
      if ((obj->flip & 0x40) == 0) {
        sVar1 = (short)(char)obj->anim_extra;
      }
      else {
        sVar1 = -(short)(char)obj->anim_extra;
      }
      obj->x = obj->x + sVar1;
      obj->anim_extra = 0;
    }
    FUN_80106214(obj);
    if ((short)obj->frame < 0) {
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      obj->sub2 = obj->field_0x55;
    }
  }
  return;
}


// ---- 801dd708 FUN_801dd708

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd708(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e58e4)[obj->sub2])();
  return;
}


// ---- 801dd744 FUN_801dd744

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd744(MM8Obj *obj)

{
  FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  FUN_800fcd84();
  obj->field_0x58 = 1;
  Anim_Set(obj,0x13);
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  obj->sub2 = 1;
  return;
}


// ---- 801dd7cc FUN_801dd7cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd7cc(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  Anim_Step();
  if (obj->sub3 == 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x50 = 0x3c;
    obj->sub3 = 1;
  }
  if ((obj->field_0x50 & 1) == 0) {
    obj->clut = DAT_80159fc8;
  }
  else {
    obj->clut = 0;
  }
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x50 = 0x78;
    bVar1 = DAT_80159fc8;
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->clut = bVar1;
  }
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801dd884 FUN_801dd884

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd884(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if ((obj->field_0x50 & 7) == 0) {
    uVar2 = Rand();
    uVar3 = Rand();
    FUN_80108ed8(obj,(int)(((uVar2 & 0x3f) - 0x1f) * 0x10000) >> 0x10,
                 (int)(((uVar3 & 0x1f) - 0xf) * 0x10000) >> 0x10);
  }
  obj->on_screen = 0;
  if ((obj->field_0x50 & 1) != 0) {
    FUN_80103184(obj);
    Obj_CullAndQueueDraw(obj);
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_8010544c(obj,0x1bf);
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->on_screen = 0;
    obj->field_0x50 = 1;
  }
  return;
}


// ---- 801dd95c FUN_801dd95c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd95c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x5c;
  obj->clut = *(byte *)(iVar2 + 0x24);
  if (*(char *)(iVar2 + 1) == '\x05') {
    obj->speed_x = 0;
  }
  FUN_80104ccc(obj);
  Anim_Step(obj);
  FUN_80106214(obj);
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    Obj_Free(obj);
  }
  else if (*(char *)(iVar2 + 0x30) == '\x0f') {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801dda0c FUN_801dda0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dda0c(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    if (obj->field_0x50 == '\0') {
      obj->field_0x50 = 1;
    }
    obj->sub2 = 1;
  }
  Anim_Step(obj);
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->state = 3;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  if ((obj->field_0x50 & 1) == 0) {
    obj->clut = DAT_80159fc8;
  }
  else {
    obj->clut = 0;
  }
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801ddacc FUN_801ddacc

undefined1 * FUN_801ddacc(int param_1,char param_2,char param_3,undefined1 param_4)

{
  undefined1 uVar1;
  short sVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)FUN_801055e4();
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 1;
    puVar3[6] = 0x3b;
    puVar3[7] = param_4;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar2 = (short)param_2;
    }
    else {
      sVar2 = -(short)param_2;
    }
    *(short *)(puVar3 + 0xe) = *(short *)(param_1 + 0xe) + sVar2;
    *(short *)(puVar3 + 0x12) = (short)param_3 + *(short *)(param_1 + 0x12);
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    *(int *)(puVar3 + 0x4c) = param_1;
    puVar3[0x25] = uVar1;
  }
  return puVar3;
}


// ---- 801ddb84 FUN_801ddb84

undefined1 * FUN_801ddb84(int param_1,char param_2,char param_3,undefined1 param_4)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x2a;
    puVar2[7] = param_4;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar1 = (short)param_2;
    }
    else {
      sVar1 = -(short)param_2;
    }
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + sVar1;
    *(short *)(puVar2 + 0x12) = (short)param_3 + *(short *)(param_1 + 0x12);
    puVar2[0x25] = *(undefined1 *)(param_1 + 0x25);
  }
  return puVar2;
}


// ---- 801ddc3c FUN_801ddc3c

int FUN_801ddc3c(int param_1)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    iVar1 = DAT_801d2928 + 0x10;
  }
  else {
    iVar1 = DAT_801d2928 + 0x130;
  }
  return iVar1 * 0x10000 - *(int *)(param_1 + 0xc);
}


