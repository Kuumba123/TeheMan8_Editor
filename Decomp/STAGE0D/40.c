// ID 40, STAGE0D.BIN, handler 0x801E7064. Ghidra output with the object struct applied; not matching C.
// ---- 801e7064 FUN_801e7064

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7064(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f89a4)[obj->state])();
  return;
}


// ---- 801e70a0 FUN_801e70a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e70a0(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->field_0x49 = 6;
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801f89bc)[obj->var & 0x7f])(obj);
  FUN_80103224(obj);
  return;
}


// ---- 801e7104 FUN_801e7104

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7104(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar3 = 0x2a;
  if ((obj->var & 0x80) == 0) {
    FUN_80103794(0x2a,0x28,4);
    uVar3 = 0x30;
    uVar4 = 0x2c;
    uVar5 = 1;
  }
  else {
                    /* Possible PsyQ macro: setLineF2() */
    uVar4 = 0x3d;
    uVar5 = 4;
  }
  FUN_80103794(uVar3,uVar4,uVar5);
  obj->x = DAT_801d2928 + 0xa0;
  sVar1 = DAT_801d292a;
  obj->draw_list = 6;
                    /* Possible PsyQ macro: setLineF2() */
  obj->flip = 0x40;
                    /* Possible PsyQ macro: setLineF2() */
  obj->hitbox = &DAT_801f8930;
  obj->box2 = &DAT_801f8948;
  obj->field_0x5e = 0xf;
  obj->field_0x5d = 0x80;
  obj->field_0x5f = 0;
  obj->field_0x56 = 0;
  obj->field_0x51 = 0;
  obj->y = sVar1 + -0x50;
  Anim_Set(obj,0x19);
  if (((DAT_801b1eb8 == '\0') || ((obj->var & 0x80) != 0)) &&
     (puVar2 = (undefined1 *)Obj_AllocType2(), puVar2 != (undefined1 *)0x0)) {
    *puVar2 = 1;
    puVar2[6] = 0x28;
    puVar2[7] = 0;
    *(MM8Obj **)(puVar2 + 0x44) = obj;
  }
  obj->state = 1;
  return;
}


// ---- 801e7230 FUN_801e7230

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7230(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  
  obj->draw_list = 5;
  obj->hitbox = &DAT_801f892c;
  puVar2 = (undefined1 *)FUN_801055e4();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x40;
    puVar2[7] = 2;
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
    *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)&obj->y_frac;
    bVar1 = obj->flip;
    *(MM8Obj **)(puVar2 + 0x58) = obj;
    puVar2[0x25] = bVar1;
  }
  Anim_Set(obj,8);
  FUN_8012ae08(obj,0x26);
  obj->field_0x5c = 0x24;
  obj->state = 3;
  return;
}


// ---- 801e72d8 FUN_801e72d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e72d8(MM8Obj *obj)

{
  obj->draw_list = 7;
  obj->invuln = 1;
  obj->hp = 0;
  Anim_Set(obj,0x24);
  obj->state = 5;
  return;
}


// ---- 801e7320 FUN_801e7320

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7320(MM8Obj *obj)

{
  undefined1 uVar1;
  
  (*(code *)(&PTR_LAB_801f89c8)[obj->sub2])();
  uVar1 = FUN_80104db0((int)obj->x,(int)obj->y,(int)*(short *)&obj->field_0x5a,
                       (int)*(short *)&obj->field_0x58);
  obj->field_0x5c = uVar1;
  FUN_801ea58c(obj);
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e78d4 FUN_801e78d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e78d4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801f89e8)[obj->sub2])();
  obj->clut = 0x2a;
  if (obj->field_0x56 == '\0') {
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (iVar2 == 2) {
      FUN_8010544c(obj,0x10);
      obj->field_0x56 = 0x3c;
      if ((DAT_80158f5c == '\x05') && ((obj->active & 0x40) != 0)) {
        obj->sub2 = 6;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
        *(undefined2 *)&obj->field_0x52 = *(undefined2 *)(DAT_8016d404 + 0xe);
      }
      else {
        FUN_8010544c(obj,0xf5);
      }
    }
    if (iVar2 == 4) {
      obj->state = 4;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      DAT_8015e2af = 1;
      return;
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
    if ((_DAT_80170574 & 1) != 0) {
      obj->clut = 0;
    }
    obj->field_0x56 = obj->field_0x56 + -1;
  }
  if (obj->sub2 != 6) {
    if ((obj->active & 0x40) == 0) {
      Enemy_ContactDamage(obj);
    }
    else {
      FUN_801e9608(obj);
    }
  }
  FUN_80103184(obj);
  if ((obj->active & 0x80) == 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e7a9c FUN_801e7a9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7a9c(MM8Obj *obj)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  
                    /* Possible PsyQ macro: setPolyFT3() */
  Anim_Step();
  obj->hitbox = &DAT_801f8930;
  obj->box2 = &DAT_801f8948;
  obj->contact_dmg = 4;
  if ((obj->field_0x5d & 0x80) == 0) {
    uVar2 = Rand();
    obj->field_0x5d = obj->field_0x5d ^ (&DAT_801f8964)[uVar2 & 0xf];
  }
  else {
    obj->field_0x5d = 0;
  }
  if (obj->field_0x5d == '\0') {
    obj->sub2 = 3;
    uVar2 = Rand();
    bVar4 = (&DAT_801f8974)[uVar2 & 0xf];
    bVar5 = obj->field_0x5e & 0xf;
    if (bVar5 == bVar4) {
      uVar2 = 0;
      if ((obj->field_0x5e & 0x80) != 0) {
        do {
          uVar3 = Rand();
          bVar4 = (&DAT_801f8974)[uVar3 & 0xf];
          uVar2 = uVar2 + 1;
          if (bVar4 != bVar5) goto LAB_801e7b9c;
        } while (uVar2 < 0x80);
        obj->field_0x54 = bVar4;
        goto LAB_801e7be4;
      }
      obj->field_0x5e = bVar4 | 0x80;
    }
    else {
      obj->field_0x5e = bVar4;
    }
LAB_801e7b9c:
    obj->field_0x54 = bVar4;
  }
  else {
    uVar2 = Rand();
    bVar4 = (&DAT_801f8984)[uVar2 & 0xf];
    if ((obj->field_0x5e == bVar4) && (bVar1 = bVar4 == 1, bVar4 = 1, bVar1)) {
      bVar4 = 2;
    }
    obj->field_0x5e = bVar4;
    obj->sub2 = bVar4;
  }
LAB_801e7be4:
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801e7c08 FUN_801e7c08

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7c08(MM8Obj *obj)

{
  Anim_Step();
  (*(code *)(&PTR_FUN_801f8a04)[obj->sub3])(obj);
  return;
}


// ---- 801e7c54 FUN_801e7c54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7c54(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  short sVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
  sVar1 = DAT_801d2928;
  if (obj->field_0x4 == '\0') {
    FUN_8010910c();
    obj->field_0x51 = 0;
    Anim_Set(obj,7);
    FUN_8010544c(obj,0xf7);
    obj->field_0x4 = 1;
  }
  else {
    if (obj->anim_extra != 0) {
      pcVar4 = &DAT_801f8a20;
      iVar6 = 0;
      do {
        if ((obj->flip & 0x40) == 0) {
          iVar2 = (int)*pcVar4;
        }
        else {
          iVar2 = -(int)*pcVar4;
        }
        pcVar5 = pcVar4 + 1;
        pcVar4 = pcVar4 + 2;
        iVar2 = FUN_801ea520((obj->x + iVar2) * 0x10000 >> 0x10,
                             (int)(((int)*pcVar5 + (uint)(ushort)obj->y) * 0x10000) >> 0x10,0xd,
                             obj->draw_list - 1);
        if (iVar2 != 0) {
          *(byte *)(iVar2 + 0x25) = obj->flip;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 * 0x10000 >> 0x10 < 2);
    }
    if ((short)obj->frame < 0) {
      FUN_8012ae08(obj,0x26);
      if ((int)DAT_8015e248._2_2_ < sVar1 + 0x28) {
        sVar3 = sVar1 + 0x28;
      }
      else {
        sVar3 = DAT_8015e248._2_2_;
        if (sVar1 + 0x118 < (int)DAT_8015e248._2_2_) {
          sVar3 = sVar1 + 0x118;
        }
      }
      obj->field_0x50 = 0xf;
      *(short *)&obj->field_0x52 = sVar3;
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e7e00 FUN_801e7e00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7e00(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  
  if (obj->field_0x4 == '\0') {
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 == '\0') {
      puVar3 = (undefined1 *)FUN_801055e4();
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        puVar3[6] = 0x40;
        puVar3[7] = 1;
        *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)&obj->field_0x52;
        *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)&obj->y_frac;
        bVar1 = obj->flip;
        *(MM8Obj **)(puVar3 + 0x58) = obj;
        puVar3[0x25] = bVar1;
      }
      Anim_Set(obj,9);
      obj->field_0x4 = 1;
    }
  }
  else if ((short)obj->frame < 0) {
    obj->field_0x51 = 1;
    obj->field_0x50 = 0x3c;
    Anim_Set(obj,0xb);
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e7ee4 FUN_801e7ee4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7ee4(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->field_0x51 = 2;
    Anim_Set(obj,0xd);
    obj->sub3 = 3;
    obj->field_0x4 = 0;
  }
  else if (obj->field_0x51 == '\x03') {
    iVar2 = FUN_80111b28();
    if (iVar2 == 0) {
      obj->field_0x51 = 1;
    }
    else {
      Anim_Set(obj,0xf);
      obj->field_0x50 = 0x78;
      obj->field_0x54 = 0x78;
      obj->field_0x51 = 4;
      obj->field_0x5f = 1;
      obj->sub3 = 4;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e7f9c FUN_801e7f9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7f9c(MM8Obj *obj)

{
  int iVar1;
  
  if ((short)obj->frame < 0) {
    iVar1 = FUN_801ea520((int)obj->x,(int)obj->y,0xe,7);
    if (iVar1 != 0) {
      *(byte *)(iVar1 + 0x25) = obj->flip;
    }
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e8004 FUN_801e8004

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8004(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    if ((short)obj->frame < 0) {
      obj->field_0x55 = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    cVar1 = FUN_80111858();
    if (cVar1 != '\0') {
      obj->field_0x54 = obj->field_0x54 + cVar1 * -4;
    }
    if (((char)obj->field_0x50 < '\x01') || ((char)obj->field_0x54 < '\x01')) {
      Anim_Set(obj,0x13);
      obj->field_0x51 = 6;
      obj->field_0x55 = 1;
      obj->sub3 = 5;
      obj->field_0x4 = 0;
    }
    else {
      if ((uint)(byte)obj->field_0x50 % 10 == 0) {
        FUN_8010544c(obj,0xfa);
      }
      if ((uint)(byte)obj->field_0x50 % 0x1e == 0) {
        Anim_Set(obj,0x11);
        obj->field_0x51 = 5;
        FUN_80111cb4(1);
      }
      obj->field_0x50 = obj->field_0x50 + -1;
    }
  }
  return;
}


// ---- 801e8160 FUN_801e8160

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8160(MM8Obj *obj)

{
  int iVar1;
  short sVar2;
  
  if (obj->anim_extra != 0) {
    if (obj->field_0x5f != '\0') {
      sVar2 = -0xa00;
      if ((obj->flip & 0x40) != 0) {
        sVar2 = 0xa00;
      }
      FUN_80111f9c((int)sVar2,3,0xf2);
      obj->field_0x5f = 0;
    }
    obj->anim_extra = 0;
  }
  if ((short)obj->frame < 0) {
    Anim_Set(obj,0x14);
    iVar1 = FUN_801ea520((int)obj->x,(int)obj->y,0xe,7);
    if (iVar1 != 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
      *(byte *)(iVar1 + 0x25) = obj->flip;
    }
    obj->sub3 = 6;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e8228 FUN_801e8228

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8228(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    if ((short)obj->frame < 0) {
      Anim_Set(obj,0x15);
      FUN_8010544c(obj,0xf0);
      obj->field_0x4 = 1;
    }
  }
  else if ((short)obj->frame < 0) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e82a8 FUN_801e82a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e82a8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8a24)[obj->sub3])();
  return;
}


// ---- 801e82e4 FUN_801e82e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e82e4(MM8Obj *obj)

{
  undefined1 uVar1;
  uint uVar2;
  
                    /* Possible PsyQ macro: setLineF2() */
  if (obj->field_0x4 == '\0') {
    if ((int)obj->x < DAT_801d2928 + 0xa0) {
      obj->speed_x = 0x3c000;
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
    }
    else {
      obj->speed_x = -0x3c000;
      obj->flip = 0;
    }
    obj->speed_y_up = 0x669d0;
    obj->gravity = 0x4000;
    Anim_Set(obj,4);
    uVar2 = Rand();
    uVar1 = (&DAT_801f8994)[uVar2 & 0xf];
    obj->field_0x55 = 0;
    obj->field_0x4 = 1;
    obj->field_0x50 = uVar1;
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->hitbox = &DAT_801f8934;
      obj->box2 = &DAT_801f894d;
      obj->field_0x43 = 1;
      Anim_Set(obj,5);
      FUN_8010544c(obj,0xf6);
      obj->field_0x54 = 8;
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
  }
  FUN_80106214(obj);
  return;
}


// ---- 801e8410 FUN_801e8410

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8410(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  FUN_801ea2c4();
  Anim_Step(obj);
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x54 + -1;
    obj->field_0x54 = cVar1;
    if (cVar1 == '\0') {
      Anim_Set(obj,0x20);
      obj->field_0x4 = 1;
    }
  }
  else if ((short)obj->frame < 0) {
    iVar2 = FUN_801ea30c(obj,0,0,0);
    if (iVar2 != 0) {
      *(MM8Obj **)(iVar2 + 0x1c) = obj;
    }
    obj->contact_dmg = 5;
    obj->dmg_table = 1;
                    /* Possible PsyQ macro: setLineF2() */
    obj->field_0x55 = 0;
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  FUN_80106214(obj);
  return;
}


// ---- 801e84d4 FUN_801e84d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e84d4(MM8Obj *obj)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  obj->active = obj->active | 0x80;
  FUN_801ea2c4();
  FUN_80106214(obj);
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  if (((obj->field_0x50 == '\0') ||
      (obj->field_0x50 = obj->field_0x50 + -1, obj->field_0x50 == '\0')) && (0 < obj->speed_y_up)) {
    obj->hitbox = &DAT_801f8938;
    obj->box2 = &DAT_801f8952;
    obj->contact_dmg = 4;
    obj->active = 1;
    obj->dmg_table = 0xc;
    obj->field_0x55 = 1;
    Anim_Set(obj,0x2b);
    obj->sub3 = 3;
    obj->field_0x4 = 0;
  }
  else if ((obj->field_0x33 & 0x30) == 0) {
    if (((obj->field_0x33 & 0x80) != 0) && (obj->speed_y_up < 0)) {
      obj->speed_y_up = 0x669d0;
      FUN_8010544c(obj,0xfb);
    }
    if ((_DAT_80170574 & 3) == 0) {
      uVar3 = Rand();
      uVar1 = obj->x;
      uVar4 = Rand();
      FUN_801ea520((int)(((uVar1 - 0xf) + (uVar3 & 0x1f)) * 0x10000) >> 0x10,
                   (int)((((ushort)obj->y - 0xf) + (uVar4 & 0x1f)) * 0x10000) >> 0x10,10,
                   obj->draw_list - 1);
    }
    if (((_DAT_80170574 & 0xf) == 0) && (iVar5 = FUN_801ea30c(obj,0,0,1), iVar5 != 0)) {
      bVar2 = Rand();
      *(byte *)(iVar5 + 0x25) = bVar2 & 0x40;
      *(MM8Obj **)(iVar5 + 0x1c) = obj;
    }
  }
  else {
    obj->speed_x = -obj->speed_x;
    FUN_8010544c(obj,0xfb);
  }
  return;
}


// ---- 801e86b8 FUN_801e86b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e86b8(MM8Obj *obj)

{
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    if (((short)obj->frame < 0) && (obj->anim == 0x2b)) {
      Anim_Set(obj,5);
    }
    FUN_801ea2c4(obj);
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->hitbox = &DAT_801f8930;
      obj->box2 = &DAT_801f8948;
      Anim_Set(obj,6);
      FUN_8010544c(obj,0xef);
      obj->field_0x43 = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80106214(obj);
    if ((short)obj->frame < 0) {
      obj->sub2 = 0;
                    /* Possible PsyQ macro: setPolyF4() */
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e879c FUN_801e879c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e879c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8a34)[obj->sub3])();
  return;
}


// ---- 801e87d8 FUN_801e87d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e87d8(MM8Obj *obj)

{
  short sVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  
  sVar1 = DAT_801d2928;
  FUN_8010910c();
  sVar4 = sVar1 + 0x10;
  sVar3 = sVar1 + 0x130;
  if ((obj->flip & 0x40) == 0) {
    *(short *)&obj->field_0x52 = sVar4;
    if ((0x1f < (int)obj->x - (int)sVar4) && (sVar1 + 0x70 <= (int)DAT_8015e248._2_2_))
    goto LAB_801e88bc;
    bVar2 = obj->flip;
    *(short *)&obj->field_0x52 = sVar3;
  }
  else {
    *(short *)&obj->field_0x52 = sVar3;
    if ((0x1f < (int)sVar3 - (int)obj->x) && ((int)DAT_8015e248._2_2_ <= sVar1 + 0xd0))
    goto LAB_801e88bc;
    bVar2 = obj->flip;
    *(short *)&obj->field_0x52 = sVar4;
  }
  obj->flip = bVar2 ^ 0x40;
LAB_801e88bc:
  obj->sub3 = 1;
  FUN_801e88f0(obj);
  return;
}


// ---- 801e88f0 FUN_801e88f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e88f0(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,1);
    obj->field_0x4 = 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = -0x60000;
    if ((short)obj->frame < 0) {
      obj->contact_dmg = 4;
      if ((obj->flip & 0x40) != 0) {
        iVar1 = 0x60000;
      }
      obj->speed_x = iVar1;
      obj->speed_y_up = 0;
      Anim_Set(obj,2);
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
  }
  FUN_80106214(obj);
                    /* Possible PsyQ macro: setLineF3() */
  return;
}


// ---- 801e8990 FUN_801e8990

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8990(MM8Obj *obj)

{
  int iVar1;
  short sVar2;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    FUN_80104c34(obj);
    FUN_80106214(obj);
    iVar1 = (int)obj->x - (int)*(short *)&obj->field_0x52;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar1 < 0x31) {
      Anim_Set(obj,3);
      iVar1 = -0x8000;
      if ((obj->flip & 0x40) == 0) {
        iVar1 = 0x8000;
      }
      obj->accel_x = iVar1;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104c9c(obj);
    FUN_80106214(obj);
                    /* Possible PsyQ macro: setPolyF4() */
    if (((obj->speed_x == 0) || ((obj->speed_x & 0x80000000U) == (obj->accel_x & 0x80000000U))) ||
       ((obj->field_0x33 & 0x30) != 0)) {
      obj->accel_x = 0;
      obj->speed_x = 0;
    }
    if (_DAT_80170574 == (_DAT_80170574 / 6) * 6) {
      if ((obj->flip & 0x40) == 0) {
        sVar2 = obj->x + -0xc;
      }
      else {
        sVar2 = obj->x + 0xc;
      }
      FUN_801091a4((int)sVar2,(int)(((ushort)obj->y + 0x13) * 0x10000) >> 0x10,1);
    }
    if (obj->speed_x == 0) {
      obj->contact_dmg = 4;
      obj->flip = obj->flip ^ 0x40;
      Anim_Set(obj,0x23);
      obj->sub3 = 3;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e8b28 FUN_801e8b28

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8b28(MM8Obj *obj)

{
  short sVar1;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    if ((short)obj->frame < 0) {
      Anim_Set(obj,0x16);
      obj->field_0x43 = 1;
      obj->speed_y_up = 0x83400;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104c34(obj);
    if (((short)obj->frame < 0) && (obj->anim == 0x16)) {
      Anim_Set(obj,0x17);
    }
    if ((int)obj->y < DAT_801d292a + 0x60) {
      Anim_Set(obj,0x18);
      sVar1 = DAT_801d292a;
      obj->gravity = 0x8000;
      obj->sub3 = 4;
      obj->field_0x4 = 0;
      obj->y = sVar1 + 0x60;
    }
  }
  return;
}


// ---- 801e8c14 FUN_801e8c14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8c14(MM8Obj *obj)

{
  short sVar1;
  
  sVar1 = DAT_801d292a + 0x20;
  FUN_80104ccc();
  Anim_Step(obj);
  if ((obj->y <= sVar1) || ((obj->speed_y_up & 0x80000000U) != (obj->gravity & 0x80000000U))) {
    Anim_Set(obj,0x19);
    obj->y = sVar1;
    FUN_801ea3c4(obj);
    obj->field_0x51 = 2;
    obj->sub3 = 5;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e8cc0 FUN_801e8cc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8cc0(MM8Obj *obj)

{
  bool bVar1;
  short sVar2;
  undefined1 uVar3;
  byte bVar4;
  short sVar5;
  
  sVar2 = DAT_801d2928;
  bVar1 = false;
  if (obj->field_0x4 == '\0') {
    obj->hitbox = &DAT_801f893c;
    obj->box2 = &DAT_801f8957;
    obj->field_0x4 = 1;
    *(short *)&obj->field_0x5a = obj->x;
    *(short *)&obj->field_0x58 = obj->y;
    obj->active = obj->active | 0x40;
  }
  if ((obj->flip & 0x40) == 0) {
    sVar5 = *(short *)&obj->field_0x5a + -0x10;
    *(short *)&obj->field_0x5a = sVar5;
    if ((int)sVar5 <= sVar2 + 0xa0) {
      bVar1 = true;
    }
  }
  else {
    sVar5 = *(short *)&obj->field_0x5a + 0x10;
    *(short *)&obj->field_0x5a = sVar5;
    if (sVar2 + 0xa0 <= (int)sVar5) {
      bVar1 = true;
    }
  }
  uVar3 = FUN_80104db0((int)obj->x,(int)obj->y,(int)*(short *)&obj->field_0x5a,
                       (int)*(short *)&obj->field_0x58);
  obj->field_0x5c = uVar3;
  if (bVar1) {
    *(short *)&obj->field_0x5a = sVar2 + 0xa0;
    obj->field_0x51 = 0;
    if (obj->field_0x54 == '\x03') {
      bVar4 = 4;
    }
    else {
      bVar4 = 5;
    }
    obj->sub2 = bVar4;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e8e08 FUN_801e8e08

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8e08(MM8Obj *obj)

{
  undefined1 uVar1;
  
  (*(code *)(&PTR_FUN_801f8a4c)[obj->sub3])();
  uVar1 = FUN_80104db0((int)obj->x,(int)obj->y,(int)*(short *)&obj->field_0x5a,
                       (int)*(short *)&obj->field_0x58);
  obj->field_0x5c = uVar1;
  FUN_801ea58c();
  return;
}


// ---- 801e8e74 FUN_801e8e74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8e74(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = -0x3800;
  obj->accel_x = 0;
  if ((obj->flip & 0x40) != 0) {
    iVar1 = 0x3800;
  }
  obj->gravity = iVar1;
  obj->contact_dmg = 4;
  Anim_Set(obj,0x19);
  FUN_8010544c(obj,0xf1);
  FUN_800fd100(0xfc);
  if (obj->field_0x54 != '\x03') {
    obj->field_0x50 = obj->field_0x54 + -3;
  }
  obj->sub3 = 1;
  FUN_801e9504(obj);
  return;
}


// ---- 801e8ff4 FUN_801e8ff4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8ff4(MM8Obj *obj)

{
  int iVar1;
  short sVar2;
  
  sVar2 = -0x10;
  if (obj->field_0x4 == '\0') {
    obj->contact_dmg = 4;
    if (0 < (int)obj->x - (int)*(short *)&obj->field_0x5a) {
      sVar2 = 0x10;
    }
    *(short *)&obj->field_0x5a = sVar2 + *(short *)&obj->field_0x5a;
    iVar1 = (int)*(short *)&obj->field_0x5a - (int)obj->x;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    *(short *)&obj->field_0x58 = obj->y;
    if (iVar1 < 0x10) {
      obj->field_0x55 = 1;
      obj->active = obj->active & 0xbf;
      Anim_Set(obj,0x1a);
      if ((obj->flip & 0x40) == 0) {
        sVar2 = obj->x + -8;
      }
      else {
        sVar2 = obj->x + 8;
      }
      obj->speed_y_up = 0x16800;
      obj->gravity = 0x1000;
      obj->x = sVar2;
      obj->speed_x = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104ccc(obj);
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      sVar2 = obj->x + -8;
      if ((obj->flip & 0x40) == 0) {
        sVar2 = obj->x + 8;
      }
      obj->x = sVar2;
      obj->hitbox = &DAT_801f8938;
      obj->box2 = &DAT_801f8952;
      obj->speed_x = 0;
      obj->gravity = 0x4000;
      obj->flip = obj->flip ^ 0x40;
      Anim_Set(obj,5);
      obj->field_0x4 = 0;
      obj->sub3 = obj->sub3 + 1;
    }
  }
  FUN_80106214(obj);
  return;
}


// ---- 801e9174 FUN_801e9174

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9174(MM8Obj *obj)

{
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    FUN_801ea2c4(obj);
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->hitbox = &DAT_801f8930;
      obj->box2 = &DAT_801f8948;
      Anim_Set(obj,6);
      FUN_8010544c(obj,0xef);
      obj->field_0x43 = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80106214(obj);
    if ((short)obj->frame < 0) {
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e9230 FUN_801e9230

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9230(MM8Obj *obj)

{
  undefined1 uVar1;
  
  (*(code *)(&PTR_FUN_801f8a5c)[obj->sub3])();
  uVar1 = FUN_80104db0((int)obj->x,(int)obj->y,(int)*(short *)&obj->field_0x5a,
                       (int)*(short *)&obj->field_0x58);
  obj->field_0x5c = uVar1;
  FUN_801ea58c();
  return;
}


// ---- 801e929c FUN_801e929c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e929c(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
  sVar1 = DAT_801d2928;
  iVar2 = obj->accel_x + obj->gravity;
  obj->accel_x = iVar2;
  if (((0 < iVar2) && (sVar1 + 0xa0 <= (int)obj->x)) ||
     ((iVar2 < 0 && ((int)obj->x <= sVar1 + 0xa0)))) {
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  FUN_801ea468(obj);
  FUN_80106214(obj);
  FUN_801e9504(obj);
  return;
}


// ---- 801e9338 FUN_801e9338

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9338(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  if (obj->field_0x4 == '\0') {
    if ((int)obj->y < DAT_801d292a + 0x20) {
      obj->field_0x4 = 1;
    }
  }
  else if (DAT_801d292a + 0x20 < (int)obj->y) {
    FUN_800fd100(0xfc);
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    bVar2 = 1;
    if (cVar1 == '\0') {
      bVar2 = 3;
    }
    obj->sub3 = bVar2;
    obj->field_0x4 = 0;
  }
  FUN_801ea468(obj);
  FUN_80106214(obj);
  FUN_801e9504(obj);
  return;
}


// ---- 801e93f0 FUN_801e93f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e93f0(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  if (obj->field_0x4 == '\0') {
    if (((0 < obj->accel_x) && (DAT_801d2928 + 0xa0 <= (int)obj->x)) ||
       ((obj->accel_x < 0 && ((int)obj->x <= DAT_801d2928 + 0xa0)))) {
      iVar1 = obj->gravity;
      obj->gravity = -iVar1;
      if (obj->field_0x54 == '\x05') {
        obj->gravity = iVar1 * -2;
      }
      obj->field_0x4 = 1;
    }
  }
  else {
    iVar2 = 0x7000;
    iVar1 = obj->accel_x + obj->gravity;
    obj->accel_x = iVar1;
    if (obj->field_0x54 == '\x04') {
      iVar2 = 0x3800;
    }
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar1 < iVar2) {
      obj->field_0x51 = 1;
      obj->sub3 = 4;
      obj->field_0x4 = 0;
      return;
    }
  }
  FUN_801ea468(obj);
  FUN_80106214(obj);
  FUN_801e9504(obj);
  return;
}


// ---- 801e9504 FUN_801e9504

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801e9504(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  char unaff_s2;
  char unaff_s3;
  
  if ((_DAT_80170574 == (_DAT_80170574 / 3) * 3) &&
     (iVar1 = FUN_801ea30c(param_1,(int)unaff_s2,(int)unaff_s3,4), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    uVar2 = Rand();
    *(uint *)(iVar1 + 0x14) = ((uVar2 & 0x1f) - 0x2a) * 0x10000;
    uVar2 = Rand();
    *(uint *)(iVar1 + 0x18) = ((uVar2 & 0xf) + 0xb) * 0x10000;
  }
  if (((_DAT_80170574 & 7) == 0) &&
     (iVar1 = FUN_801ea30c(param_1,(int)unaff_s2,(int)unaff_s3,5), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + 0x14) = 0xffef0000;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
                    /* Probable PsyQ macro: setTile() */
    *(undefined4 *)(iVar1 + 0x18) = 0x70000;
  }
  return;
}


// ---- 801e9608 FUN_801e9608

void FUN_801e9608(int param_1)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  
                    /* Probable PsyQ macro: setTile() */
  sVar2 = -0xa00;
  if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
    sVar2 = 0xa00;
  }
  uVar3 = *(undefined4 *)(param_1 + 0x3c);
  *(undefined **)(param_1 + 0x3c) = &DAT_801f8944;
  iVar1 = Enemy_ContactDamage(param_1);
  if (iVar1 != 0) {
    FUN_80111f9c((int)sVar2,3,0xf2);
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  iVar1 = Enemy_ContactDamage(param_1);
  if (iVar1 != 0) {
    FUN_80111f9c((int)sVar2,3,0xf2);
  }
  return;
}


// ---- 801e96a8 FUN_801e96a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e96a8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8a74)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801e96f8 FUN_801e96f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e96f8(MM8Obj *obj)

{
  obj->speed_x = 0;
  obj->speed_y_up = 0x30000;
  obj->field_0x43 = 1;
  obj->invuln = 1;
  FUN_8010544c(obj,0xf3);
  obj->sub3 = 1;
  return;
}


// ---- 801e9748 FUN_801e9748

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9748(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_80104c34();
  if (obj->field_0x4 == '\0') {
    iVar2 = (uint)(ushort)obj->x - (uint)*(ushort *)&obj->field_0x52;
    iVar4 = iVar2 * 0x10000 >> 0x10;
    iVar3 = iVar4;
    if (iVar4 < 0) {
      iVar3 = -iVar4;
    }
    if (iVar3 < 2) {
      obj->x = *(ushort *)&obj->field_0x52;
    }
    else {
      if (iVar4 < 1) {
        sVar1 = 2;
      }
      else {
        sVar1 = -2;
      }
      obj->x = obj->x + sVar1;
    }
    FUN_80106214(obj);
    iVar3 = (int)(short)iVar2;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if ((iVar3 < 2) || ((obj->field_0x33 & 0x30) != 0)) {
      Anim_Set(obj,0x1c);
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80106214(obj);
    iVar3 = (int)(((uint)(ushort)obj->x - (uint)*(ushort *)&obj->field_0x5a) * 0x10000) >> 0x10;
    if (iVar3 != 0) {
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = -iVar3;
      }
      if (iVar2 < 4) {
        *(short *)&obj->field_0x5a = obj->x;
      }
      else {
        if (iVar3 < 1) {
          sVar1 = -4;
        }
        else {
          sVar1 = 4;
        }
        *(ushort *)&obj->field_0x5a = *(ushort *)&obj->field_0x5a + sVar1;
      }
    }
    iVar3 = (int)(((uint)(ushort)obj->y - (uint)*(ushort *)&obj->field_0x58) * 0x10000) >> 0x10;
    if (iVar3 != 0) {
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = -iVar3;
      }
      if (iVar2 < 4) {
        *(short *)&obj->field_0x58 = obj->y;
      }
      else {
        if (iVar3 < 1) {
          sVar1 = -4;
        }
        else {
          sVar1 = 4;
        }
        *(ushort *)&obj->field_0x58 = *(ushort *)&obj->field_0x58 + sVar1;
      }
    }
    if ((int)obj->y < DAT_801d292a + -0x40) {
      obj->speed_y_up = 0;
    }
    if (obj->speed_y_up == 0) {
      iVar3 = (int)obj->x - (int)*(short *)&obj->field_0x5a;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (iVar3 < 5) {
        iVar3 = (int)obj->y - (int)*(short *)&obj->field_0x58;
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 < 5) {
          obj->field_0x55 = 1;
          obj->field_0x50 = 0x14;
          obj->speed_y_up = -0x80000;
          obj->gravity = 0;
          Anim_Set(obj,0x1d);
          obj->sub3 = 2;
          obj->field_0x4 = 0;
        }
      }
    }
  }
  return;
}


// ---- 801e9994 FUN_801e9994

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9994(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->hitbox = &DAT_801f8940;
      obj->box2 = &DAT_801f895c;
      obj->field_0x56 = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104ccc(obj);
    FUN_80106214(obj);
    if (((obj->field_0x33 & 0x80) != 0) && (obj->speed_y_up < 0)) {
      DAT_801d2936 = 0x1e;
      if (obj->anim == 0x1d) {
        Anim_Set(obj,0x2a);
        obj->speed_y_up = 0x4fc00;
        obj->gravity = 0x4000;
      }
      else {
        Anim_Set(obj,0x1e);
        FUN_8010544c(obj,0xf8);
        obj->field_0x50 = 0x5a;
        obj->sub3 = 3;
                    /* Possible PsyQ macro: setPolyF3() */
        obj->field_0x4 = 0;
        obj->invuln = 0;
        obj->field_0x43 = 0;
        obj->active = 1;
        obj->field_0x54 = obj->hp;
      }
    }
  }
  return;
}


// ---- 801e9ab8 FUN_801e9ab8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9ab8(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      Anim_Set(obj,0x1f);
      FUN_8010544c(obj,0xf4);
      iVar2 = -0x20000;
      obj->speed_y_up = 0x4fc00;
      obj->gravity = 0x4000;
      if ((obj->flip & 0x40) != 0) {
        iVar2 = 0x20000;
      }
      obj->speed_x = iVar2;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104ccc(obj);
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->hitbox = &DAT_801f8930;
      obj->box2 = &DAT_801f8948;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      obj->field_0x5d = 0;
    }
  }
  return;
}


// ---- 801e9ba0 FUN_801e9ba0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9ba0(MM8Obj *obj)

{
  Anim_Step();
  (*(code *)(&PTR_FUN_801f8a84)[obj->sub2])(obj);
  if (*(char *)(*(int *)&obj->field_0x58 + 1) == '\x04') {
    Obj_Free(obj);
  }
  else {
    obj->clut = *(byte *)(*(int *)&obj->field_0x58 + 0x24);
    if (obj->active != 0) {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801e9c30 FUN_801e9c30

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9c30(MM8Obj *obj)

{
  if (*(char *)(*(int *)&obj->field_0x58 + 0x51) == '\x01') {
    Anim_Set(obj,10);
    obj->sub2 = 1;
  }
  return;
}


// ---- 801e9c7c FUN_801e9c7c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9c7c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)&obj->field_0x58;
  cVar1 = *(char *)(iVar3 + 0x51);
  if (cVar1 == '\x02') {
    Anim_Set(obj,0xc);
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
    obj->field_0x5c = 0x26;
    obj->sub2 = 2;
  }
  else if (cVar1 == '\x04') {
    Anim_Set(obj,0xe);
    obj->field_0x5c = 0x27;
    obj->sub2 = 3;
    obj->sub3 = 0;
  }
  else {
    iVar2 = Obj_HitboxOverlap(&g_player,obj);
    if (iVar2 != 0) {
      *(undefined1 *)(iVar3 + 0x51) = 3;
    }
  }
  return;
}


// ---- 801e9d20 FUN_801e9d20

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9d20(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    Obj_Free();
  }
  return;
}


// ---- 801e9f14 FUN_801e9f14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9f14(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8a9c)[obj->sub2])();
  return;
}


// ---- 801e9f50 FUN_801e9f50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9f50(MM8Obj *obj)

{
  if (obj->field_0x5f != '\0') {
    FUN_80111c28();
    obj->field_0x5f = 0;
  }
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  FUN_800fcd84();
  obj->field_0x55 = 1;
  obj->field_0x51 = 1;
  Anim_Set(obj,0x1b);
  obj->sub2 = 1;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e9fe8 FUN_801e9fe8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9fe8(MM8Obj *obj)

{
  if (((g_player != '\0') && (DAT_8015e23e != '\x1a')) && (obj->field_0x4 == '\0')) {
    FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (obj->sub3 == 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x50 = 0x3c;
    obj->sub3 = 1;
  }
  if ((_DAT_80170574 & 1) == 0) {
    obj->clut = 0x2a;
  }
  else {
    obj->clut = 0;
  }
  if (((obj->field_0x50 == '\0') ||
      (obj->field_0x50 = obj->field_0x50 + -1, obj->field_0x50 == '\0')) &&
     ((DAT_8015e2b0 == '\x01' || (g_player == '\0')))) {
    obj->field_0x50 = 0x78;
    obj->clut = 0x2a;
    obj->sub2 = 2;
    obj->sub3 = 0;
  }
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801ea12c FUN_801ea12c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea12c(MM8Obj *obj)

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
  if ((obj->field_0x50 & 1) != 0) {
    FUN_80103184(obj);
    Obj_CullAndQueueDraw(obj);
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_8010544c(obj,0xf9);
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->on_screen = 0;
    obj->field_0x50 = 1;
  }
  return;
}


// ---- 801ea204 FUN_801ea204

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea204(MM8Obj *obj)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->field_0x58;
  if ((*pcVar2 == '\0') || ((*(uint *)(pcVar2 + 4) & 0xffff0000) != 0x1400000)) {
    iVar1 = FUN_801ea520((int)obj->x,(int)obj->y,0xf,7);
    if (iVar1 != 0) {
      *(byte *)(iVar1 + 0x25) = obj->flip;
    }
    Obj_Free(obj);
  }
  else {
    if (pcVar2[0x5c] == obj->anim) {
      Anim_Step(obj,pcVar2[0x5c],0xf);
    }
    else {
      Anim_Set(obj);
    }
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801ea2c4 FUN_801ea2c4

void FUN_801ea2c4(int param_1)

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


// ---- 801ea30c FUN_801ea30c

undefined1 * FUN_801ea30c(int param_1,char param_2,char param_3,undefined1 param_4)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x2b;
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


// ---- 801ea3c4 FUN_801ea3c4

void FUN_801ea3c4(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 1;
  do {
    puVar2 = (undefined1 *)Obj_AllocType2();
    uVar4 = uVar4 + 1;
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x28;
      puVar2[7] = *(undefined1 *)((int)&PTR_FUN_801f8aa8 + iVar3 + 3);
      uVar1 = *(undefined1 *)(param_1 + 0x25);
      *(int *)(puVar2 + 0x44) = param_1;
      puVar2[0x48] = (char)iVar3;
      puVar2[0x25] = uVar1;
    }
    iVar3 = iVar3 + 1;
  } while (uVar4 < 0x10);
  *(undefined1 *)(param_1 + 0x55) = 0;
  return;
}


// ---- 801ea468 FUN_801ea468

void FUN_801ea468(int param_1)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  cVar1 = FUN_80104db0((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),
                       (int)*(short *)(param_1 + 0x5a),(int)*(short *)(param_1 + 0x58));
  uVar3 = *(int *)(param_1 + 0x20) >> 8;
  if ((int)uVar3 < 0) {
    uVar3 = -uVar3;
  }
  FUN_80105120(param_1,uVar3 & 0xffff,cVar1);
  FUN_80104c34(param_1);
  cVar2 = cVar1 + '@';
  if (*(int *)(param_1 + 0x1c) < 1) {
    cVar2 = cVar1 + -0x40;
  }
  uVar3 = *(int *)(param_1 + 0x1c) >> 8;
  if ((int)uVar3 < 0) {
    uVar3 = -uVar3;
  }
  FUN_80105120(param_1,uVar3 & 0xffff,cVar2);
  FUN_80104c34(param_1);
  return;
}


// ---- 801ea520 FUN_801ea520

int FUN_801ea520(short param_1,short param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  
  iVar1 = FUN_801091a4((int)param_1,(int)param_2,0x80);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x27) = 0x7b;
    *(undefined1 *)(iVar1 + 0x24) = 0x2a;
    *(undefined1 *)(iVar1 + 0x38) = param_3;
    *(undefined1 *)(iVar1 + 0x26) = param_4;
  }
  return iVar1;
}


// ---- 801ea58c FUN_801ea58c

void FUN_801ea58c(int param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x30) == '\x19') {
    uVar1 = (uint)*(byte *)(param_1 + 0x5c);
    if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
      uVar1 = -uVar1;
    }
    Anim_SetAtStep(param_1,0x19,(uVar1 + 0x48 & 0xff) >> 4);
  }
  return;
}


