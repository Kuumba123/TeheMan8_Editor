// ID 5D, STAGE0C.BIN, handler 0x801E5BC4. Ghidra output with the object struct applied; not matching C.
// ---- 801e5bc4 FUN_801e5bc4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5bc4(MM8Obj *obj)

{
  char cVar1;
  
  obj->clut = DAT_8015a008;
  (*(code *)(&PTR_FUN_801eafd8)[obj->state])();
  if (obj->active != 0) {
    cVar1 = FUN_801e86f8(obj);
    if (cVar1 == '\x04') {
      obj->state = 8;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
    FUN_80103184(obj);
    if (obj->field_0x5e != '\0') {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801e5c6c FUN_801e5c6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5c6c(MM8Obj *obj)

{
  Enemy_InitFromTable();
  FUN_8010910c(obj);
  obj->field_0x50 = 0x78;
  obj->field_0x49 = 0xc;
  obj->draw_list = 9;
  obj->field_0x51 = 0;
  obj->field_0x54 = 0;
  obj->field_0x5e = 0;
  obj->field_0x50 = 0;
  obj->field_0x58 = 0;
  obj->field_0x59 = 0;
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
  Anim_Set(obj,10);
  FUN_80103224(obj);
  FUN_801e8c58();
  DAT_801b29a0 = 0;
  DAT_801b29a1 = 0;
  DAT_801b29a2 = 0;
  DAT_801b29a3 = 0;
  DAT_801b29a4 = 0;
  DAT_801b29a6 = 0;
  FUN_801e8a78(obj);
  if (DAT_801c3378 == '\0') {
    DAT_801c3378 = '\x01';
  }
  obj->state = 9;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801e5d5c FUN_801e5d5c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5d5c(MM8Obj *obj)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  
  obj->field_0x51 = obj->field_0x51 | 1;
  if (obj->sub2 == 0) {
    Anim_Set(obj,0x12);
    obj->field_0x50 = 0x5a;
    obj->field_0x58 = 0;
    obj->field_0x59 = 0x1e;
    sVar1 = DAT_8015e248._2_2_;
    obj->speed_x = 0x20000;
    obj->field_0x5a = obj->x < sVar1;
    iVar4 = FUN_801e8980(obj);
    if (iVar4 == 0) {
      obj->speed_x = -obj->speed_x;
    }
    FUN_8010910c(obj);
                    /* Possible PsyQ macro: setPolyFT4() + setSemiTrans(polyFT4, 1) +
                       setShadeTex(polyFT4, 1) */
    obj->speed_y_up = 0x3c00;
    obj->gravity = -0x400;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
  }
  cVar2 = obj->field_0x59 + -1;
  obj->field_0x59 = cVar2;
  if (cVar2 == '\0') {
    obj->speed_x = 0x20000;
    iVar4 = FUN_801e8980(obj);
    if (iVar4 == 0) {
      obj->speed_x = -obj->speed_x;
    }
  }
  FUN_80104ccc(obj);
  FUN_801e8520(obj);
  obj->box2 = &DAT_801eaf90;
  FUN_80106214(obj);
  obj->box2 = (&PTR_DAT_801eafb0)[obj->anim_extra & 0xf];
  if ((bool)obj->field_0x5a != obj->x < DAT_8015e248._2_2_) {
    obj->field_0x58 = 0x10;
  }
                    /* Probable PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
                    /* Possible PsyQ macro: setTile8() */
  if ((obj->field_0x58 != '\0') &&
     (cVar2 = obj->field_0x58 + -1, obj->field_0x58 = cVar2, cVar2 == '\0')) {
    FUN_8010910c(obj);
  }
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->speed_x = -obj->speed_x;
    if ((obj->field_0x33 & 0x10) == 0) {
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
    }
    else {
      obj->flip = 0;
    }
  }
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
    bVar3 = FUN_801e85a0(obj);
    obj->state = bVar3;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e8520 FUN_801e8520

void FUN_801e8520(int param_1)

{
  if (0x7ffe < *(int *)(param_1 + 0x18) + 0x3fffU) {
    *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
  }
  return;
}


// ---- 801e85a0 FUN_801e85a0

uint FUN_801e85a0(int param_1)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  uVar2 = Rand();
  uVar2 = uVar2 & 0xf;
  uVar4 = 0;
  do {
    uVar2 = uVar2 - (byte)(&DAT_801eafd0)[uVar4];
    if ((int)(uVar2 * 0x10000) < 1) break;
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 3);
  cVar1 = (char)(uVar4 << 4);
  if (*(byte *)(param_1 + 0x5f) >> 4 == uVar4) {
    bVar3 = *(byte *)(param_1 + 0x5f) + 1 & 0xf;
    *(byte *)(param_1 + 0x5f) = *(byte *)(param_1 + 0x5f) & 0xf0 | bVar3;
    if (bVar3 < 3) goto LAB_801e8660;
    uVar4 = (int)(uVar4 + 1) % 3;
    cVar1 = (char)uVar4 * '\x10';
  }
  *(char *)(param_1 + 0x5f) = cVar1;
LAB_801e8660:
  return uVar4 + 3 & 0xff;
}


// ---- 801e86f8 FUN_801e86f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_801e86f8(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(param_1 + 0x54);
  if ((*(byte *)(param_1 + 0x51) & 1) == 0) {
    cVar2 = '\0';
  }
  else {
    if ((*(byte *)(param_1 + 0x51) & 2) == 0) {
      *(undefined1 *)(param_1 + 0x44) = 0x24;
    }
    else {
      *(undefined1 *)(param_1 + 0x44) = 0;
    }
    *(undefined **)(param_1 + 0x3c) = (&PTR_DAT_801eafb0)[*(byte *)(param_1 + 0x32) & 0xf];
    bVar1 = *(byte *)(param_1 + 0x47);
    if (*pcVar4 == '\0') {
      cVar2 = Enemy_CheckWeaponHits(param_1);
      if (((cVar2 == '\x02') || (cVar2 == '\x04')) && (*(byte *)(param_1 + 0x47) < 2)) {
        *(undefined1 *)(param_1 + 0x47) = 1;
        cVar2 = '\x04';
      }
      if ((cVar2 != '\0') && (cVar2 == '\x02')) {
        if ((int)(((uint)bVar1 - (uint)*(byte *)(param_1 + 0x47)) * 0x1000000) >> 0x18 < 2) {
          uVar3 = 0x10;
        }
        else {
          uVar3 = 0x1da;
        }
        FUN_8010544c(param_1,uVar3);
        *pcVar4 = '\x1e';
      }
    }
    else {
                    /* Possible PsyQ macro: setPolyF4() */
      *(undefined1 *)(param_1 + 0x47) = 0x28;
      cVar2 = Enemy_CheckWeaponHits(param_1);
      *(byte *)(param_1 + 0x47) = bVar1;
      *pcVar4 = *pcVar4 + -1;
      if (cVar2 == '\x04') {
        cVar2 = '\x02';
      }
      if (cVar2 == '\x02') {
        FUN_8010544c(param_1,0x4f);
      }
    }
    if (cVar2 == '\x04') {
      FUN_8010544c(param_1,0x1d9);
      DAT_8015e2af = 1;
      *pcVar4 = '\0';
    }
    else {
      if ((*pcVar4 != '\0') && ((_DAT_80170574 & 1) != 0)) {
        *(undefined1 *)(param_1 + 0x24) = 0;
      }
      Enemy_ContactDamage(param_1);
    }
  }
  return cVar2;
}


// ---- 801e8980 FUN_801e8980

bool FUN_801e8980(int param_1)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = Rand();
  bVar1 = *(short *)(param_1 + 0xe) < DAT_8015e248._2_2_;
  if ((uVar2 & 0xf) < 10) {
    bVar1 = !bVar1;
  }
  return bVar1;
}


// ---- 801e8a78 FUN_801e8a78

void FUN_801e8a78(undefined4 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocType2();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x33;
    puVar1[7] = 2;
    *(undefined2 *)(puVar1 + 0xe) = 0x1070;
    *(undefined2 *)(puVar1 + 0x12) = 0xba0;
    *(undefined4 *)(puVar1 + 0x1c) = param_1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
  }
  return;
}


// ---- 801e8c58 FUN_801e8c58

void FUN_801e8c58(void)

{
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  return;
}


