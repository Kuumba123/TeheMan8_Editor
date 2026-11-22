// ID 48, STAGE08.BIN, handler 0x801DB9C4. Ghidra output with the object struct applied; not matching C.
// ---- 801db9c4 FUN_801db9c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db9c4(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setTile8() */
  (*(code *)(&PTR_FUN_801e112c)[obj->state])();
  return;
}


// ---- 801dba00 FUN_801dba00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba00(MM8Obj *obj)

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
  obj->hitbox = &DAT_801e10d8;
  obj->flip = 0;
  obj->box2 = &DAT_801e10e1;
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
     (iVar2 = FUN_801de2f0(obj,0,0,0), iVar2 != 0)) {
    *(MM8Obj **)(iVar2 + 0x1c) = obj;
  }
  obj->field_0x51 = 10;
                    /* Possible PsyQ macro: setPolyGT3() */
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->state = 1;
  return;
}


// ---- 801dbb38 FUN_801dbb38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbb38(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT3() */
  (*(code *)(&PTR_LAB_801e113c)[obj->sub2])();
  return;
}


// ---- 801dc3c4 FUN_801dc3c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc3c4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  
  (*(code *)(&PTR_FUN_801e1164)[obj->sub2])();
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
      else {
                    /* Possible PsyQ macro: setLineF2() */
        if ((uint)bVar3 != (uint)obj->hp) {
          if ((uint)bVar3 - (uint)obj->hp < 2) {
            uVar4 = 0x165;
          }
          else {
            uVar4 = 0x164;
          }
          FUN_8010544c(obj,uVar4);
        }
      }
    }
    if (iVar2 == 4) {
      DAT_8015e2af = 1;
      obj->state = 3;
      obj->sub2 = 0;
      obj->sub3 = 0;
                    /* Probable PsyQ macro: setTile16() */
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
                    /* Possible PsyQ macro: setTile16() */
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801dc59c FUN_801dc59c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc59c(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  undefined *puVar4;
  
  puVar4 = &DAT_801e10f8;
  if (0xf < obj->hp) {
    puVar4 = &DAT_801e10e8;
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
  obj->hitbox = &DAT_801e10d4;
  obj->sub2 = bVar3;
  obj->field_0x5a = bVar3;
  obj->field_0x53 = 0;
  obj->box2 = &DAT_801e10dc;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  return;
}


// ---- 801dc6a4 FUN_801dc6a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc6a4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e1188)[obj->sub3])();
  return;
}


// ---- 801dc6e0 FUN_801dc6e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc6e0(MM8Obj *obj)

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
  FUN_801de1b0(obj);
  return;
}


// ---- 801dc75c FUN_801dc75c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc75c(MM8Obj *obj)

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
    obj->hitbox = &DAT_801e10d8;
    obj->box2 = &DAT_801e10e1;
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
    obj->speed_x = 0;
    obj->field_0x51 = 0;
    obj->field_0x53 = 3;
    obj->active = obj->active | 0x80;
    uVar5 = Rand();
    uVar5 = (uint)(byte)(&DAT_801e1110)[uVar5 & 0xf];
    if ((uVar5 == (byte)obj->field_0x5c) &&
       (bVar4 = obj->field_0x5d + 1, obj->field_0x5d = bVar4, 2 < bVar4)) {
      iVar7 = 0;
      do {
        uVar5 = Rand();
        uVar5 = (uint)(byte)(&DAT_801e1110)[uVar5 & 0xf];
        iVar7 = iVar7 + 1;
        if (uVar5 != (byte)obj->field_0x5c) {
          obj->field_0x5d = 0;
          break;
        }
      } while (iVar7 * 0x10000 >> 0x10 < 0x40);
    }
                    /* Possible PsyQ macro: setLineF2() */
    sVar1 = (&DAT_801e1108)[uVar5];
    obj->y = sVar3;
    obj->field_0x5c = (char)uVar5;
    obj->x = sVar2 + sVar1;
    iVar7 = FUN_801de2f0(obj,0,0,0);
    iVar8 = 0;
    if (iVar7 != 0) {
      *(MM8Obj **)(iVar7 + 0x1c) = obj;
      FUN_800fd100(0x168);
    }
    iVar7 = 0;
    do {
      if ((iVar7 >> 0x10 != uVar5) && (iVar6 = FUN_801de218(obj,0,0,2), iVar6 != 0)) {
        *(short *)(iVar6 + 0xe) = sVar2 + (&DAT_801e1108)[iVar7 >> 0x10];
      }
      iVar8 = iVar8 + 1;
                    /* Probable PsyQ macro: setTile16() */
      iVar7 = iVar8 * 0x10000;
    } while (iVar8 * 0x10000 >> 0x10 < 3);
    obj->field_0x50 = 2;
    obj->sub3 = 2;
  }
  return;
}


// ---- 801dc96c caseD_3

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801dc924::caseD_3(MM8Obj *obj)

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
  if (((int)obj->y < DAT_801d292a + 0x20) && ((DAT_80170574 & 2) != 0)) {
    uVar2 = Rand();
    uVar3 = Rand();
    FUN_801de2f0(obj,uVar2 & 0xf,uVar3 & 3,2);
  }
  FUN_801de210(obj);
  return;
}


// ---- 801dca6c FUN_801dca6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dca6c(MM8Obj *obj)

{
  obj->sub2 = 4;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  FUN_801de210();
                    /* Probable PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801dca98 FUN_801dca98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dca98(MM8Obj *obj)

{
                    /* Probable PsyQ macro: setLineF2() */
  (*(code *)(&PTR_LAB_801e1198)[obj->sub3])();
  return;
}


// ---- 801dcdc0 FUN_801dcdc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcdc0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e11ac)[obj->sub3])();
  return;
}


// ---- 801dcdfc FUN_801dcdfc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcdfc(MM8Obj *obj)

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
  FUN_801de1b0(obj);
  return;
}


// ---- 801dce98 FUN_801dce98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce98(MM8Obj *obj)

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


// ---- 801dcef4 FUN_801dcef4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcef4(MM8Obj *obj)

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
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->sub3 = 3;
      obj->field_0x4 = 0;
    }
  }
  FUN_80106214(obj);
  return;
}


// ---- 801dcfb8 FUN_801dcfb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcfb8(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
                    /* Possible PsyQ macro: setTile8() */
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    *(int *)&obj->y_frac = *(int *)&obj->y_frac + -0x8000;
    if (cVar2 == '\0') {
      uVar4 = Rand();
      uVar5 = Rand();
      iVar6 = ((uVar4 & 3) + (uVar5 & 1)) * 2;
      cVar2 = (&DAT_801e1120)[iVar6];
      cVar1 = (&DAT_801e1121)[iVar6];
      iVar6 = FUN_801de218(obj,(int)cVar2,(int)cVar1,3);
      if (iVar6 != 0) {
        *(undefined1 *)(iVar6 + 0x51) = obj->field_0x55;
      }
      FUN_801de41c(obj,(int)cVar2,(int)cVar1);
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
    FUN_801de0d0(obj);
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


// ---- 801dd1b8 FUN_801dd1b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd1b8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e11c0)[obj->sub3])();
  FUN_801de210(obj);
  return;
}


// ---- 801dd208 FUN_801dd208

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd208(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  
  sVar2 = DAT_801d292a;
  sVar1 = DAT_801d2928;
  iVar3 = FUN_801de218(obj,0,0,0x84);
                    /* Possible PsyQ macro: setPolyGT3() */
  if (iVar3 != 0) {
    *(short *)(iVar3 + 0xe) = sVar1 + 0x50;
    *(short *)(iVar3 + 0x12) = sVar2 + 0x50;
    *(undefined1 *)(iVar3 + 0x25) = 0;
  }
  iVar3 = FUN_801de218(obj,0,0,0x84);
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


// ---- 801dd458 FUN_801dd458

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd458(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e11d0)[obj->sub3])();
  return;
}


// ---- 801dd494 FUN_801dd494

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd494(MM8Obj *obj)

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
  FUN_801de1b0(obj);
  return;
}


// ---- 801dd544 FUN_801dd544

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd544(MM8Obj *obj)

{
  Anim_Step();
                    /* Possible PsyQ macro: setPolyF3() */
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


// ---- 801dd5f8 FUN_801dd5f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd5f8(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_801de218(obj,2,0xffffffed,8);
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


// ---- 801dd670 FUN_801dd670

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd670(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e11e0)[obj->sub3])();
  return;
}


// ---- 801dd6ac FUN_801dd6ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd6ac(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_8010910c();
    obj->field_0x53 = 2;
    obj->hitbox = &DAT_801e10d4;
    obj->box2 = &DAT_801e10dc;
    obj->field_0x51 = 1;
    obj->field_0x56 = obj->field_0x56 | 0x80;
    obj->active = obj->active & 0x7f;
    obj->field_0x52 = obj->field_0x52 | 0x80;
    obj->y = (DAT_801d292a - (DAT_801e10df + -0xd0)) - (short)DAT_801e10dd;
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


// ---- 801dd7dc FUN_801dd7dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd7dc(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
                    /* Possible PsyQ macro: setPolyGT4() */
  if (obj->field_0x4 == '\0') {
    Anim_Step();
    if ((obj->anim_extra != 0) && (iVar3 = FUN_801de218(obj,0xffffffd5,0xfffffff1,7), iVar3 != 0)) {
      *(undefined1 *)(iVar3 + 0x51) = obj->field_0x55;
    }
                    /* Possible PsyQ macro: setTile8() */
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


// ---- 801dd900 FUN_801dd900

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd900(MM8Obj *obj)

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


// ---- 801dd988 FUN_801dd988

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd988(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e11ec)[obj->sub3])();
  return;
}


// ---- 801dd9c4 FUN_801dd9c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd9c4(MM8Obj *obj)

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
  FUN_801de1b0(obj);
  return;
}


// ---- 801dda30 FUN_801dda30

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dda30(MM8Obj *obj)

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


// ---- 801ddaec FUN_801ddaec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddaec(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    if ((DAT_80170574 & 1) == 0) {
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
    FUN_801de0d0(obj);
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


// ---- 801ddc5c FUN_801ddc5c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddc5c(MM8Obj *obj)

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
                    /* Possible PsyQ macro: setLineF2() */
      cVar2 = (&DAT_801e1120)[iVar6];
      cVar1 = (&DAT_801e1121)[iVar6];
      iVar6 = FUN_801de218(obj,(int)cVar2,(int)cVar1,5);
      if (iVar6 != 0) {
        *(byte *)(iVar6 + 0x51) = obj->field_0x55 & 3;
      }
      FUN_801de41c(obj,(int)cVar2,(int)cVar1);
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
  if ((DAT_80170574 & 0x40) == 0) {
    iVar6 = *(int *)&obj->y_frac + -0x4000;
  }
  obj->y_frac = (short)iVar6;
  obj->y = (short)((uint)iVar6 >> 0x10);
  FUN_80106214(obj);
  return;
}


// ---- 801dde04 FUN_801dde04

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dde04(MM8Obj *obj)

{
  FUN_801de118(obj);
  if (obj->sub2 == 0) {
    obj->sub2 = 7;
  }
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  return;
}


// ---- 801dde40 FUN_801dde40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dde40(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e1204)[obj->sub2])();
  return;
}


// ---- 801dde7c FUN_801dde7c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dde7c(MM8Obj *obj)

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


// ---- 801ddf40 FUN_801ddf40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddf40(MM8Obj *obj)

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
                    /* Possible PsyQ macro: setLineF2() */
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801ddff8 FUN_801ddff8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddff8(MM8Obj *obj)

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


// ---- 801de0d0 FUN_801de0d0

void FUN_801de0d0(int param_1)

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


// ---- 801de118 FUN_801de118

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de118(MM8Obj *obj)

{
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    FUN_801de0d0(obj);
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->field_0x43 = 0;
      Anim_Set(obj,3);
                    /* Possible PsyQ macro: setLineF2() */
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


// ---- 801de1b0 FUN_801de1b0

void FUN_801de1b0(int param_1)

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


// ---- 801de210 FUN_801de210

void FUN_801de210(void)

{
  return;
}


// ---- 801de218 FUN_801de218

undefined1 * FUN_801de218(int param_1,char param_2,char param_3,byte param_4)

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


// ---- 801de2f0 FUN_801de2f0

undefined1 * FUN_801de2f0(int param_1,char param_2,char param_3,undefined1 param_4)

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
                    /* Possible PsyQ macro: setLineF2() */
    *(short *)(puVar2 + 0x12) = (short)param_3 + *(short *)(param_1 + 0x12);
  }
  return puVar2;
}


// ---- 801de3ac FUN_801de3ac

int FUN_801de3ac(short param_1,short param_2,undefined1 param_3,undefined1 param_4)

{
  undefined1 uVar1;
  int iVar2;
  
                    /* Possible PsyQ macro: setPolyF4() */
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


// ---- 801de41c FUN_801de41c

void FUN_801de41c(int param_1,char param_2,char param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = (int)param_2;
  if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
    iVar2 = -iVar2;
  }
                    /* Possible PsyQ macro: setTile1() + setSemiTrans(tile1, 1) */
  iVar2 = FUN_801de3ac((*(short *)(param_1 + 0xe) + iVar2) * 0x10000 >> 0x10,
                       (int)(((int)param_3 + (uint)*(ushort *)(param_1 + 0x12)) * 0x10000) >> 0x10,
                       0x1b,*(char *)(param_1 + 0x26) + -1);
                    /* Possible PsyQ macro: setPolyGT4() */
  if (iVar2 != 0) {
                    /* Possible PsyQ macro: setLineF2() */
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    *(undefined1 *)(iVar2 + 0x24) = 4;
    *(undefined1 *)(iVar2 + 0x25) = uVar1;
  }
  return;
}


