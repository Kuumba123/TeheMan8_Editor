// ID 48, STAGE0D.BIN, handler 0x801EA5E4. Ghidra output with the object struct applied; not matching C.
// ---- 801ea5e4 FUN_801ea5e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea5e4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8b14)[obj->state])();
  return;
}


// ---- 801ea620 FUN_801ea620

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea620(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
  if ((obj->var & 0x80) != 0) {
    FUN_80103794(0x2a,0x44,6);
  }
  Enemy_InitFromTable(obj);
  obj->field_0x49 = 8;
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
  obj->draw_list = 7;
  obj->hitbox = &DAT_801f8ac0;
  obj->flip = 0;
  obj->box2 = &DAT_801f8ac9;
  obj->x = DAT_801d2928 + 0xa0;
  sVar1 = DAT_801d292a;
  obj->field_0x53 = 0;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  obj->field_0x56 = 0;
  obj->field_0x54 = 0;
  obj->field_0x5a = 0;
  obj->field_0x5b = 0;
  obj->field_0x5c = 0xff;
  obj->field_0x5d = 0;
  obj->field_0x5e = 0xff;
  obj->field_0x5f = 0xff;
  obj->y = sVar1 + 0xae;
  Anim_Set(obj,0);
  FUN_80103224(obj);
  if (((DAT_801b1ecc == '\0') || ((obj->var & 0x80) != 0)) &&
     (iVar2 = FUN_801ecf10(obj,0,0,0), iVar2 != 0)) {
    *(MM8Obj **)(iVar2 + 0x1c) = obj;
  }
  obj->field_0x51 = 10;
  obj->state = 1;
  return;
}


// ---- 801ea758 FUN_801ea758

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ea758(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801f8b24)[obj->sub2])();
  return;
}


// ---- 801eafe4 FUN_801eafe4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eafe4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  
  (*(code *)(&PTR_FUN_801f8b4c)[obj->sub2])();
  bVar3 = 0x19;
  obj->clut = DAT_80159fed;
  if ((obj->field_0x53 & 1) == 0) {
    bVar3 = 0x10;
  }
  obj->dmg_table = bVar3;
  if (obj->field_0x54 == '\0') {
    bVar3 = obj->hp;
    bVar1 = obj->on_screen;
    obj->on_screen = 1;
    iVar2 = Enemy_CheckWeaponHits(obj);
    obj->on_screen = bVar1;
    if (iVar2 == 2) {
      obj->field_0x54 = 0x3c;
      FUN_8010544c(obj,0x10);
      if ((*(uint *)&obj->field_0x50 & 0x1ff0000) == 0x1000000) {
        obj->sub2 = 2;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
      }
      else if ((uint)bVar3 != (uint)obj->hp) {
        if ((uint)bVar3 - (uint)obj->hp < 2) {
          uVar4 = 0x165;
        }
        else {
          uVar4 = 0x164;
        }
        FUN_8010544c(obj,uVar4);
      }
    }
    if (iVar2 == 4) {
      DAT_8015e2af = 1;
      obj->state = 3;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      return;
    }
  }
  else {
    bVar3 = obj->hp;
    obj->hp = 0x28;
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (iVar2 == 2) {
      FUN_8010544c(obj,0x4f);
    }
    obj->hp = bVar3;
    bVar3 = obj->field_0x54 - 1;
    obj->field_0x54 = bVar3;
    if ((bVar3 & 1) != 0) {
      obj->clut = 0;
    }
  }
  if ((obj->field_0x53 & 2) == 0) {
    Enemy_ContactDamage(obj);
  }
  FUN_80103184(obj);
  obj->on_screen = 0;
  if ((obj->active & 0x80) == 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801eb1bc FUN_801eb1bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eb1bc(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  undefined *puVar4;
  
  puVar4 = &DAT_801f8ae0;
  if (0xf < obj->hp) {
    puVar4 = &DAT_801f8ad0;
  }
  uVar2 = Rand();
  bVar3 = puVar4[uVar2 & 0xf];
  if ((bVar3 == obj->field_0x5a) &&
     (bVar1 = obj->field_0x5b + 1, obj->field_0x5b = bVar1, 2 < bVar1)) {
    bVar1 = 0;
    do {
      uVar2 = Rand();
      bVar3 = puVar4[uVar2 & 0xf];
      if (bVar3 != obj->field_0x5a) {
        obj->field_0x5b = 0;
        break;
      }
      bVar1 = bVar1 + 1;
    } while (bVar1 < 0x40);
  }
  obj->hitbox = &DAT_801f8abc;
  obj->sub2 = bVar3;
  obj->field_0x5a = bVar3;
  obj->field_0x53 = 0;
  obj->box2 = &DAT_801f8ac4;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801eb2c4 FUN_801eb2c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eb2c4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8b70)[obj->sub3])();
  return;
}


// ---- 801eb300 FUN_801eb300

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eb300(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_8010910c();
    obj->speed_y_up = 0x80000;
    obj->speed_x = 0;
    obj->field_0x51 = 0;
    obj->field_0x52 = 0;
    obj->field_0x53 = 0;
    obj->field_0x5f = 0x80;
    obj->field_0x5e = 0x80;
    Anim_Set(obj,1);
    obj->field_0x4 = 1;
  }
  FUN_801ecdd0(obj);
  return;
}


// ---- 801eb37c FUN_801eb37c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eb37c(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  short sVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  sVar3 = DAT_801d292a;
  sVar2 = DAT_801d2928;
  FUN_80104c34();
  if (obj->y < DAT_801d292a) {
    obj->hitbox = &DAT_801f8ac0;
    obj->box2 = &DAT_801f8ac9;
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
    obj->speed_x = 0;
    obj->field_0x51 = 0;
    obj->field_0x53 = 3;
    obj->active = obj->active | 0x80;
    uVar5 = Rand();
    uVar5 = (uint)(byte)(&DAT_801f8af8)[uVar5 & 0xf];
    if ((uVar5 == (byte)obj->field_0x5c) &&
       (bVar4 = obj->field_0x5d + 1, obj->field_0x5d = bVar4, 2 < bVar4)) {
      iVar7 = 0;
      do {
        uVar5 = Rand();
        uVar5 = (uint)(byte)(&DAT_801f8af8)[uVar5 & 0xf];
        iVar7 = iVar7 + 1;
        if (uVar5 != (byte)obj->field_0x5c) {
          obj->field_0x5d = 0;
          break;
        }
      } while (iVar7 * 0x10000 >> 0x10 < 0x40);
    }
    sVar1 = (&DAT_801f8af0)[uVar5];
    obj->y = sVar3;
    obj->field_0x5c = (char)uVar5;
    obj->x = sVar2 + sVar1;
    iVar7 = FUN_801ecf10(obj,0,0,0);
    iVar8 = 0;
    if (iVar7 != 0) {
      *(MM8Obj **)(iVar7 + 0x1c) = obj;
      FUN_800fd100(0x168);
    }
    iVar7 = 0;
    do {
      if ((iVar7 >> 0x10 != uVar5) && (iVar6 = FUN_801ece38(obj,0,0,2), iVar6 != 0)) {
        *(short *)(iVar6 + 0xe) = sVar2 + (&DAT_801f8af0)[iVar7 >> 0x10];
      }
      iVar8 = iVar8 + 1;
      iVar7 = iVar8 * 0x10000;
    } while (iVar8 * 0x10000 >> 0x10 < 3);
    obj->field_0x50 = 2;
    obj->sub3 = 2;
  }
  return;
}


// ---- 801eb58c FUN_801eb58c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eb58c(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_80104ccc();
  FUN_80106214(obj);
  if (((obj->field_0x33 & 0x80) != 0) && (obj->speed_y_up < 0)) {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x51 = 0xc;
      obj->field_0x43 = 0;
      obj->sub3 = 3;
    }
    else {
      obj->speed_y_up = 0x2e000;
      obj->gravity = 0x4000;
    }
  }
  if (((int)obj->y < DAT_801d292a + 0x20) && ((_DAT_80170574 & 2) != 0)) {
    uVar2 = Rand();
    uVar3 = Rand();
    FUN_801ecf10(obj,uVar2 & 0xf,uVar3 & 3,2);
  }
  FUN_801ece30(obj);
  return;
}


// ---- 801eb68c FUN_801eb68c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eb68c(MM8Obj *obj)

{
  obj->sub2 = 4;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  FUN_801ece30();
  return;
}


// ---- 801eb6b8 FUN_801eb6b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eb6b8(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801f8b80)[obj->sub3])();
  return;
}


// ---- 801eb9e0 FUN_801eb9e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eb9e0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8b94)[obj->sub3])();
  return;
}


// ---- 801eba1c FUN_801eba1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eba1c(MM8Obj *obj)

{
  short sVar1;
  
  if (obj->field_0x4 == '\0') {
    FUN_8010910c();
    obj->speed_y_up = 0x7069e;
    obj->field_0x53 = 0;
    obj->speed_x = 0;
    obj->gravity = 0x4000;
    obj->field_0x56 = obj->field_0x56 | 0x80;
    Anim_Set(obj,1);
    obj->field_0x5f = 0x80;
    obj->field_0x5e = 0x80;
    sVar1 = DAT_801d292a;
    obj->field_0x4 = 1;
    *(short *)&obj->field_0x58 = sVar1 + 0x60;
  }
  FUN_801ecdd0(obj);
  return;
}


// ---- 801ebab8 FUN_801ebab8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ebab8(MM8Obj *obj)

{
  Anim_Step();
  FUN_80104ccc(obj);
  if (obj->speed_y_up < 0) {
    obj->field_0x53 = 0;
    obj->field_0x4 = 0;
    obj->sub3 = obj->sub3 + 1;
  }
  FUN_80106214(obj);
  return;
}


// ---- 801ebb14 FUN_801ebb14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ebb14(MM8Obj *obj)

{
  FUN_80104c34();
  if (obj->field_0x4 == '\0') {
    FUN_8010910c(obj);
    Anim_Set(obj,8);
    FUN_8010544c(obj,0x161);
    obj->field_0x5e = 0x22;
    obj->field_0x5f = 0x21;
    obj->field_0x4 = 1;
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->field_0x50 = 1;
      obj->field_0x55 = 0;
      Anim_Set(obj,9);
      obj->field_0x5e = 0x24;
      obj->field_0x5f = 0x23;
      obj->sub3 = 3;
      obj->field_0x4 = 0;
    }
  }
  FUN_80106214(obj);
  return;
}


// ---- 801ebbd8 FUN_801ebbd8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ebbd8(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    *(int *)&obj->y_frac = *(int *)&obj->y_frac + -0x8000;
    if (cVar2 == '\0') {
      uVar4 = Rand();
      uVar5 = Rand();
      iVar6 = ((uVar4 & 3) + (uVar5 & 1)) * 2;
      cVar2 = (&DAT_801f8b08)[iVar6];
      cVar1 = (&DAT_801f8b09)[iVar6];
      iVar6 = FUN_801ece38(obj,(int)cVar2,(int)cVar1,3);
      if (iVar6 != 0) {
        *(undefined1 *)(iVar6 + 0x51) = obj->field_0x55;
      }
      FUN_801ed03c(obj,(int)cVar2,(int)cVar1);
      obj->field_0x50 = 4;
      bVar3 = obj->field_0x55 + 1;
      obj->field_0x55 = bVar3;
      if (3 < bVar3) {
        obj->speed_y_up = 0x20000;
        Anim_Set(obj,10);
        obj->field_0x5e = 0x26;
                    /* Possible PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
        obj->field_0x5f = 0x25;
        obj->field_0x4 = 1;
      }
    }
  }
  else {
    FUN_801eccf0(obj);
    if ((short)obj->frame < 0) {
      obj->speed_y_up = 0x4000;
      obj->gravity = 0x4000;
      obj->sub3 = 4;
      obj->field_0x4 = 0;
      obj->field_0x52 = obj->field_0x52 | 0x80;
    }
  }
  FUN_80106214(obj);
  return;
}


// ---- 801ebdd8 FUN_801ebdd8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ebdd8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8ba8)[obj->sub3])();
  FUN_801ece30(obj);
  return;
}


// ---- 801ebe28 FUN_801ebe28

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ebe28(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  
  sVar2 = DAT_801d292a;
  sVar1 = DAT_801d2928;
  iVar3 = FUN_801ece38(obj,0,0,0x84);
  if (iVar3 != 0) {
    *(short *)(iVar3 + 0xe) = sVar1 + 0x50;
    *(short *)(iVar3 + 0x12) = sVar2 + 0x50;
    *(undefined1 *)(iVar3 + 0x25) = 0;
  }
  iVar3 = FUN_801ece38(obj,0,0,0x84);
  if (iVar3 != 0) {
    *(short *)(iVar3 + 0xe) = sVar1 + 0xf0;
    *(short *)(iVar3 + 0x12) = sVar2 + 0x50;
                    /* Possible PsyQ macro: setLineF2() */
    *(undefined1 *)(iVar3 + 0x25) = 0x40;
  }
  obj->field_0x56 = 0;
  uVar4 = Rand();
  obj->field_0x57 = (7 < (uVar4 & 0xf)) << 6;
  obj->sub3 = 1;
  return;
}


// ---- 801ec078 FUN_801ec078

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec078(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8bb8)[obj->sub3])();
  return;
}


// ---- 801ec0b4 FUN_801ec0b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec0b4(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x4 == '\0') {
    FUN_8010910c();
    iVar1 = DAT_8015e248 - *(int *)&obj->x_frac;
    obj->field_0x51 = 0;
    obj->speed_y_up = 0x794a0;
    obj->gravity = 0x4000;
    obj->speed_x = iVar1 / 0x1f;
    Anim_Set(obj,1);
    obj->field_0x5f = 0x80;
    obj->field_0x5e = 0x80;
    obj->field_0x4 = 1;
  }
  FUN_801ecdd0(obj);
  return;
}


// ---- 801ec164 FUN_801ec164

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec164(MM8Obj *obj)

{
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    FUN_80104ccc(obj);
    if ((obj->speed_y_up == 0) || (obj->speed_y_up < 0)) {
      obj->flip = ((int)obj->x < DAT_801d2928 + 0xa0) << 6;
      Anim_Set(obj,0xf);
      FUN_8010544c(obj,0x160);
      obj->field_0x4 = 1;
    }
  }
  else if (obj->anim_extra != 0) {
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  FUN_80106214(obj);
  return;
}


// ---- 801ec218 FUN_801ec218

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec218(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_801ece38(obj,2,0xffffffed,8);
    obj->speed_x = 0;
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if ((short)obj->frame < 0) {
    Anim_Set(obj,2);
    obj->sub3 = 3;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801ec290 FUN_801ec290

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec290(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8bc8)[obj->sub3])();
  return;
}


// ---- 801ec2cc FUN_801ec2cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec2cc(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_8010910c();
    obj->field_0x53 = 2;
    obj->hitbox = &DAT_801f8abc;
    obj->box2 = &DAT_801f8ac4;
    obj->field_0x51 = 1;
    obj->field_0x56 = obj->field_0x56 | 0x80;
    obj->active = obj->active & 0x7f;
    obj->field_0x52 = obj->field_0x52 | 0x80;
    obj->y = (DAT_801d292a - (DAT_801f8ac7 + -0xd0)) - (short)DAT_801f8ac5;
    Anim_Set(obj,5);
    FUN_8010544c(obj,0x162);
    obj->field_0x4 = 1;
  }
  Anim_Step(obj);
  if (obj->anim_extra != 0) {
    obj->field_0x53 = 0;
  }
  if ((short)obj->frame < 0) {
    obj->field_0x55 = 0;
    obj->field_0x50 = 1;
    Anim_Set(obj,6);
    obj->sub3 = 1;
    obj->field_0x4 = 0;
  }
  FUN_80106214(obj);
  return;
}


// ---- 801ec3fc FUN_801ec3fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec3fc(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  if (obj->field_0x4 == '\0') {
    Anim_Step();
    if ((obj->anim_extra != 0) && (iVar3 = FUN_801ece38(obj,0xffffffd5,0xfffffff1,7), iVar3 != 0)) {
      *(undefined1 *)(iVar3 + 0x51) = obj->field_0x55;
    }
    if (-1 < (short)obj->frame) {
      return;
    }
    obj->field_0x50 = 4;
    obj->field_0x4 = 1;
    bVar1 = obj->field_0x55 + 1;
    obj->field_0x55 = bVar1;
    if (bVar1 < 4) {
      return;
    }
    Anim_Set(obj,7);
    obj->field_0x50 = 0xf;
    obj->sub3 = 2;
  }
  else {
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 != '\0') {
      return;
    }
    Anim_Set(obj,6);
  }
  obj->field_0x4 = 0;
  return;
}


// ---- 801ec520 FUN_801ec520

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec520(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub3 == 0) {
    obj->field_0x53 = 0;
    obj->field_0x50 = 0x20;
    Anim_Set(obj,0);
    obj->field_0x5f = 1;
    obj->field_0x5e = 0;
    obj->sub3 = 1;
  }
  else {
    Anim_Step(obj);
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801ec5a8 FUN_801ec5a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec5a8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8bd4)[obj->sub3])();
  return;
}


// ---- 801ec5e4 FUN_801ec5e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec5e4(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    obj->speed_y_up = 0x5c000;
    obj->speed_x = 0;
    obj->gravity = 0x4000;
    Anim_Set(obj,1);
    obj->field_0x5f = 0x80;
    obj->field_0x5e = 0x80;
    obj->field_0x4 = 1;
  }
  FUN_801ecdd0(obj);
  return;
}


// ---- 801ec650 FUN_801ec650

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec650(MM8Obj *obj)

{
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    FUN_80104ccc(obj);
    if (obj->speed_y_up < 0) {
      FUN_8010910c(obj);
      Anim_Set(obj,8);
      obj->field_0x5e = 0x22;
      obj->field_0x5f = 0x21;
      obj->field_0x4 = 1;
    }
  }
  else if ((short)obj->frame < 0) {
    obj->field_0x50 = 0x46;
    obj->field_0x55 = obj->hp;
    FUN_8010544c(obj,0x163);
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  FUN_80106214(obj);
  return;
}


// ---- 801ec70c FUN_801ec70c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec70c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    if ((_DAT_80170574 & 1) == 0) {
      sVar3 = obj->x + 1;
    }
    else {
      sVar3 = obj->x + -1;
    }
    obj->x = sVar3;
    *(int *)&obj->y_frac = *(int *)&obj->y_frac + 0x4000;
    FUN_80106214(obj);
    if ((int)((uint)(byte)obj->field_0x55 - (uint)obj->hp) < 2) {
      cVar1 = obj->field_0x50 + -1;
      obj->field_0x50 = cVar1;
      if (cVar1 == '\0') {
        obj->field_0x4 = 1;
        obj->field_0x55 = 0;
      }
    }
    else {
      Anim_Set(obj,10);
      obj->field_0x5e = 0x26;
                    /* Possible PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
      obj->field_0x5f = 0x25;
      obj->field_0x4 = 1;
      obj->field_0x55 = 0xff;
    }
  }
  else {
    FUN_801eccf0(obj);
    FUN_80106214(obj);
    if (obj->field_0x55 == '\0') {
      if ((int)obj->y < DAT_801d292a + 0xb0) {
        return;
      }
      obj->y = DAT_801d292a + 0xb0;
      obj->field_0x55 = 0;
      obj->field_0x50 = 1;
      Anim_Set(obj,9);
      obj->field_0x5e = 0x24;
      obj->field_0x5f = 0x23;
      bVar2 = 3;
    }
    else {
      bVar2 = 5;
      if (-1 < (short)obj->frame) {
        return;
      }
    }
    obj->sub3 = bVar2;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801ec87c FUN_801ec87c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ec87c(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 == '\0') {
      uVar4 = Rand();
      uVar5 = Rand();
      iVar6 = ((uVar4 & 3) + (uVar5 & 1)) * 2;
      cVar2 = (&DAT_801f8b08)[iVar6];
      cVar1 = (&DAT_801f8b09)[iVar6];
      iVar6 = FUN_801ece38(obj,(int)cVar2,(int)cVar1,5);
      if (iVar6 != 0) {
        *(byte *)(iVar6 + 0x51) = obj->field_0x55 & 3;
      }
      FUN_801ed03c(obj,(int)cVar2,(int)cVar1);
      bVar3 = obj->field_0x55 + 1;
      obj->field_0x55 = bVar3;
      if (bVar3 < 0xf) {
        obj->field_0x50 = 0x14;
      }
      else {
        obj->field_0x55 = 0;
        Anim_Set(obj,10);
        obj->field_0x5e = 0x26;
                    /* Possible PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
        obj->field_0x5f = 0x25;
        obj->field_0x4 = 1;
      }
    }
  }
  else if ((short)obj->frame < 0) {
    obj->sub3 = 4;
    obj->field_0x4 = 0;
  }
  iVar6 = *(int *)&obj->y_frac + 0x4000;
  if ((_DAT_80170574 & 0x40) == 0) {
    iVar6 = *(int *)&obj->y_frac + -0x4000;
  }
  obj->y_frac = (short)iVar6;
  obj->y = (short)((uint)iVar6 >> 0x10);
  FUN_80106214(obj);
  return;
}


// ---- 801eca24 FUN_801eca24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eca24(MM8Obj *obj)

{
  FUN_801ecd38(obj);
  if (obj->sub2 == 0) {
    obj->sub2 = 7;
  }
  return;
}


// ---- 801eca60 FUN_801eca60

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eca60(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8bec)[obj->sub2])();
  return;
}


// ---- 801eca9c FUN_801eca9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eca9c(MM8Obj *obj)

{
  FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  FUN_800fcd84();
  obj->field_0x5e = 0x80;
  obj->field_0x5f = 0x80;
  obj->var = obj->var & 0xfe;
  obj->field_0x51 = obj->field_0x51 | 0x80;
  obj->field_0x52 = obj->field_0x52 | 0x80;
  obj->field_0x56 = obj->field_0x56 | 0x80;
  Anim_Set(obj,0xc);
  obj->sub2 = 1;
  obj->sub3 = 0;
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801ecb60 FUN_801ecb60

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ecb60(MM8Obj *obj)

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
    obj->clut = DAT_80159fed;
  }
  else {
    obj->clut = 0;
  }
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x50 = 0x78;
    bVar1 = DAT_80159fed;
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->clut = bVar1;
  }
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801ecc18 FUN_801ecc18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ecc18(MM8Obj *obj)

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
    FUN_8010544c(obj,0x167);
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->on_screen = 0;
    obj->field_0x50 = 1;
  }
  return;
}


// ---- 801eccf0 FUN_801eccf0

void FUN_801eccf0(int param_1)

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


// ---- 801ecd38 FUN_801ecd38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ecd38(MM8Obj *obj)

{
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    FUN_801eccf0(obj);
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->field_0x43 = 0;
      Anim_Set(obj,3);
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


// ---- 801ecdd0 FUN_801ecdd0

void FUN_801ecdd0(int param_1)

{
  Anim_Step();
  if (*(short *)(param_1 + 0x2e) < 0) {
    *(undefined1 *)(param_1 + 0x43) = 1;
    Anim_Set(param_1,2);
    *(undefined1 *)(param_1 + 4) = 0;
    *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + '\x01';
  }
  FUN_80106214(param_1);
  return;
}


// ---- 801ece30 FUN_801ece30

void FUN_801ece30(void)

{
  return;
}


// ---- 801ece38 FUN_801ece38

undefined1 * FUN_801ece38(int param_1,char param_2,char param_3,byte param_4)

{
  undefined1 uVar1;
  short sVar2;
  undefined1 *puVar3;
  
  if ((param_4 & 0x80) == 0) {
    puVar3 = (undefined1 *)Obj_AllocMain();
  }
  else {
    puVar3 = (undefined1 *)FUN_801055e4();
  }
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 1;
    puVar3[6] = 0x49;
    puVar3[7] = param_4 & 0x7f;
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


// ---- 801ecf10 FUN_801ecf10

undefined1 * FUN_801ecf10(int param_1,char param_2,char param_3,undefined1 param_4)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x35;
    puVar2[7] = param_4;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar1 = (short)param_3;
    }
    else {
      sVar1 = -(short)param_2;
    }
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + sVar1;
    *(short *)(puVar2 + 0x12) = (short)param_3 + *(short *)(param_1 + 0x12);
  }
  return puVar2;
}


// ---- 801ecfcc FUN_801ecfcc

int FUN_801ecfcc(short param_1,short param_2,undefined1 param_3,undefined1 param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_801091a4((int)param_1,(int)param_2,0x80);
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 0x27) = 0x8a;
    uVar1 = DAT_80159fee;
    *(undefined1 *)(iVar2 + 0x38) = param_3;
    *(undefined1 *)(iVar2 + 0x26) = param_4;
    *(undefined1 *)(iVar2 + 0x24) = uVar1;
  }
  return iVar2;
}


// ---- 801ed03c FUN_801ed03c

void FUN_801ed03c(int param_1,char param_2,char param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = (int)param_2;
  if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
    iVar2 = -iVar2;
  }
  iVar2 = FUN_801ecfcc((*(short *)(param_1 + 0xe) + iVar2) * 0x10000 >> 0x10,
                       (int)(((int)param_3 + (uint)*(ushort *)(param_1 + 0x12)) * 0x10000) >> 0x10,
                       0x1b,*(char *)(param_1 + 0x26) + -1);
  if (iVar2 != 0) {
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    *(undefined1 *)(iVar2 + 0x24) = 4;
    *(undefined1 *)(iVar2 + 0x25) = uVar1;
  }
  return;
}


