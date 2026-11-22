// ID 2A, STAGE04.BIN, handler 0x801DEB8C. Ghidra output with the object struct applied; not matching C.
// ---- 801deb8c FUN_801deb8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deb8c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e70f0)[obj->state])();
  if ((obj->active != 0) && (obj->field_0x54 != '\0')) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801debfc FUN_801debfc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801debfc(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->flip = 0;
  obj->field_0x54 = 1;
  (*(code *)(&PTR_FUN_801e7110)[obj->var])(obj);
  return;
}


// ---- 801dec50 FUN_801dec50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dec50(MM8Obj *obj)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  obj->draw_list = 6;
  obj->speed_y_up = 0x20000;
  obj->hitbox = &DAT_801e70b0;
  obj->speed_x = 0;
  obj->field_0x5e = 0;
  obj->field_0x5f = 0;
  obj->field_0x55 = 0;
  obj->field_0x5a = 0;
  obj->dmg_table = 0x18;
  obj->invuln = 1;
  *(undefined4 *)&obj->field_0x4c = 0;
  Anim_Set(obj,0xd);
  uVar6 = 0;
  obj->anim_timer = 1;
  obj->field_0x5b = 0;
  uVar5 = 0;
  do {
    iVar2 = FUN_801e0e60(obj,1,uVar5 & 0xe0,0xe);
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + *(int *)&obj->x_frac;
      iVar4 = *(int *)&obj->y_frac;
      *(MM8Obj **)(iVar2 + 0x4c) = obj;
      *(char *)(iVar2 + 0x53) = (char)uVar6;
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + iVar4;
      obj->field_0x5b = obj->field_0x5b + '\x01';
    }
    uVar6 = uVar6 + 1;
    uVar5 = uVar6 * 0x20;
  } while (uVar6 < 8);
                    /* Possible PsyQ macro: setPolyF4() */
  iVar2 = FUN_8012c108(obj,&obj->field_0x5c,0,0,0,4);
  if (iVar2 != 0) {
                    /* Probable PsyQ macro: setTile() */
    *(undefined1 *)(iVar2 + 7) = 0x60;
    *(undefined1 *)(iVar2 + 0x26) = 5;
  }
  puVar3 = (undefined1 *)Obj_AllocType2();
  uVar5 = 0;
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 1;
    puVar3[6] = 0x33;
    uVar1 = DAT_8016d300;
    *(undefined2 *)(puVar3 + 0xe) = 0x1b80;
    *(undefined2 *)(puVar3 + 0x12) = 0x3b0;
    *(MM8Obj **)(puVar3 + 0x1c) = obj;
    puVar3[7] = uVar1;
  }
  DAT_801c3376 = 6;
  do {
    FUN_8010373c(uVar5);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 4);
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->field_0x50 = 0x3c;
  DAT_801b29a0 = 0;
  obj->state = 1;
  obj->field_0x4 = 0;
  obj->active = obj->active | 0x80;
  return;
}


// ---- 801dee10 FUN_801dee10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dee10(MM8Obj *obj)

{
  byte bVar1;
  
  FUN_801df038();
  bVar1 = 5;
  if ((obj->field_0x53 & 1) != 0) {
    bVar1 = 7;
  }
  obj->draw_list = bVar1;
  obj->state = 2;
  return;
}


// ---- 801dee5c FUN_801dee5c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dee5c(MM8Obj *obj)

{
  FUN_801df038();
  obj->draw_list = 5;
                    /* Possible PsyQ macro: setLineF2() */
  obj->speed_x = 0;
  obj->speed_y_up = 0x20000;
  FUN_8012a5fc(obj,4);
  obj->state = 3;
  return;
}


// ---- 801deeac FUN_801deeac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deeac(MM8Obj *obj)

{
  FUN_801df038();
  obj->hp = 6;
  obj->contact_dmg = 4;
  obj->draw_list = 4;
  obj->speed_x = 0;
  obj->speed_y_up = 0x408b0;
  obj->field_0x57 = 0;
  FUN_8012a5fc(obj,4);
                    /* Possible PsyQ macro: setPolyGT4() */
  if (obj->var == 3) {
    FUN_8010544c(obj,0x183);
  }
  obj->state = 4;
  return;
}


// ---- 801def2c FUN_801def2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801def2c(MM8Obj *obj)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_801df038();
  obj->speed_y_up = 0x794a0;
  iVar1._0_2_ = obj->x_frac;
  iVar1._2_2_ = obj->x;
  obj->hp = 6;
  obj->contact_dmg = 4;
  obj->draw_list = 4;
  obj->speed_x = 0x20000;
  obj->gravity = 0x4000;
  uVar3 = 0;
  if (DAT_8015e248 < iVar1) {
    obj->speed_x = -0x20000;
  }
  uVar2 = 0;
  do {
    iVar1 = FUN_801e0e60(obj,6,uVar2 & 0xc0,4);
    uVar3 = uVar3 + 1;
    if (iVar1 != 0) {
      *(MM8Obj **)(iVar1 + 0x4c) = obj;
    }
    uVar2 = uVar3 * 0x40;
  } while (uVar3 < 4);
  FUN_8012a5fc(obj,4);
  obj->state = 5;
  return;
}


// ---- 801deff4 FUN_801deff4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deff4(MM8Obj *obj)

{
  int iVar1;
  
  FUN_801df038();
  obj->draw_list = 4;
  iVar1 = *(int *)(*(int *)&obj->field_0x4c + 0x14);
  obj->state = 5;
  obj->speed_x = iVar1;
  return;
}


// ---- 801df038 FUN_801df038

void FUN_801df038(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = Rand();
  uVar2 = 0xb235 >> (uVar1 & 0xf) & 1;
  *(undefined **)(param_1 + 0x3c) = &UNK_801e70b4 + uVar2 * 4;
  *(undefined1 *)(param_1 + 0x47) = 6;
  *(undefined **)(param_1 + 0x38) = &UNK_801e70bc + uVar2 * 5;
  *(undefined1 *)(param_1 + 0x45) = 3;
  *(undefined1 *)(param_1 + 0x55) = 0;
  uVar1 = Rand();
  Anim_SetAtStep(param_1,uVar2 | 2,uVar1 & 0xf);
  *(undefined1 *)(param_1 + 0x31) = 1;
  return;
}


// ---- 801df0d0 FUN_801df0d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df0d0(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  (*(code *)(&PTR_FUN_801e712c)[obj->sub2])();
  obj->clut = DAT_80159fb1;
  if (obj->field_0x5a == '\0') {
    cVar1 = Enemy_CheckWeaponHits(obj);
    obj->field_0x5d = cVar1;
    if (cVar1 == '\x04') {
      obj->state = 7;
      obj->sub2 = 0;
      obj->sub3 = 0;
      DAT_8015e282 = 1;
      return;
    }
    if (cVar1 == '\x02') {
      obj->field_0x5a = 0x3c;
      FUN_8010544c(obj,0x10);
    }
  }
  else {
    bVar2 = obj->hp;
    obj->field_0x5d = 0;
                    /* Possible PsyQ macro: setPolyF4() */
    obj->hp = 0x28;
    iVar3 = Enemy_CheckWeaponHits(obj);
    if (iVar3 == 2) {
      FUN_8010544c(obj,0x4f);
    }
    obj->hp = bVar2;
    obj->field_0x5c = 0;
    bVar2 = obj->field_0x5a - 1;
    obj->field_0x5a = bVar2;
    if ((bVar2 & 1) != 0) {
      obj->clut = 0;
      obj->field_0x5c = 3;
    }
  }
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801df1f4 FUN_801df1f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df1f4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e713c)[obj->sub3])();
  return;
}


// ---- 801df230 FUN_801df230

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df230(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  
  if (obj->field_0x4 == '\0') {
    if (DAT_801b299e != '\0') {
      return;
    }
    FUN_800fcb80(0x2f);
    DAT_801b2992 = 1;
    DAT_801b2993 = 1;
    DAT_801b2994 = 1;
    obj->field_0x4 = 1;
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    cVar1 = '\x02' - obj->field_0x4;
    FUN_80103638(cVar1,cVar1);
    cVar1 = obj->field_0x4 + '\x01';
    obj->field_0x4 = cVar1;
    if (cVar1 == '\x03') {
      obj->sub3 = 1;
      obj->field_0x4 = 0;
      DAT_801d2938 = 0x78;
      obj->field_0x50 = 0x1e;
    }
    else {
      uVar2 = 0xa8;
      if (obj->field_0x4 == '\x01') {
        uVar2 = 0x96;
      }
      obj->field_0x50 = uVar2;
    }
  }
  return;
}


// ---- 801df32c FUN_801df32c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df32c(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    if ((uint)(byte)obj->field_0x50 % 10 == 0) {
      FUN_8012a5fc(obj,0x10);
    }
    if (((obj->field_0x50 == '\0') ||
        (obj->field_0x50 = obj->field_0x50 + -1, obj->field_0x50 == '\0')) && (DAT_801cf53c == '\0')
       ) {
      obj->field_0x4 = 1;
      obj->field_0x59 = 1;
    }
  }
  else {
    FUN_80104c34(obj);
    if ((obj->field_0x59 != '\0') && (obj->y < 0x3d1)) {
      FUN_8010544c(obj,0x181);
      obj->field_0x59 = 0;
    }
    if (obj->y < 0x36f) {
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801df43c FUN_801df43c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df43c(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    obj->field_0x5e = 2;
    obj->field_0x50 = 0x1e;
    if (obj->anim != 0xd) {
      obj->invuln = 0;
    }
    obj->field_0x4 = 1;
  }
  else if (obj->field_0x50 == '\0') {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->sub2 = 1;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      obj->speed_y_up = 0;
      obj->invuln = 0;
      obj->gravity = 0x200;
      Anim_Set(obj,0);
      if ((obj->active & 0x80) != 0) {
        FUN_80111918(obj);
        DAT_801b2992 = 0;
        DAT_801b2993 = 0;
        DAT_801b2994 = 0;
        obj->active = 1;
      }
    }
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  return;
}


// ---- 801df53c FUN_801df53c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df53c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e7148)[obj->sub3])();
  if (0x7289 < obj->speed_y_up + 0x3945U) {
    obj->gravity = -obj->gravity;
  }
  FUN_80104ccc(obj);
  Anim_Step(obj);
  FUN_801e1020(obj);
  return;
}


// ---- 801df5c4 FUN_801df5c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df5c4(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  if (obj->field_0x4 == '\0') {
    if (obj->hp < 10) {
      cVar2 = '\x1e';
    }
    else {
      bVar1 = Rand();
      cVar2 = (bVar1 & 7) * '\x04' + 'Z';
    }
    obj->field_0x50 = cVar2;
    obj->field_0x4 = 1;
  }
  if (obj->field_0x5d == '\x02') {
    Anim_Set(obj,1);
    obj->field_0x55 = 0;
  }
  cVar2 = obj->field_0x50 + -1;
  iVar3 = (int)obj->x - (int)DAT_8015e248._2_2_;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  obj->field_0x50 = cVar2;
  if (cVar2 != '\0') {
    return;
  }
  obj->field_0x4 = 0;
  if ((short)iVar3 < 0x80) {
    uVar4 = Rand();
    cVar2 = (&DAT_801e70e0)[uVar4 & 7];
  }
  else {
    uVar4 = Rand();
    cVar2 = (&DAT_801e70d8)[uVar4 & 7];
  }
  iVar3._0_2_ = obj->x_frac;
  iVar3._2_2_ = obj->x;
  if ((byte)((iVar3 <= DAT_8015e248) << 6) != (obj->flip & 0x40)) {
    uVar4 = Rand();
    cVar2 = (&DAT_801e70e8)[uVar4 & 7];
  }
  if (cVar2 == '\x01') {
    bVar1 = 2;
  }
  else {
    if (cVar2 < '\x02') {
      if (cVar2 != '\0') {
        return;
      }
      obj->sub3 = 2;
      return;
    }
    bVar1 = 3;
    if (cVar2 != '\x02') {
      return;
    }
  }
  obj->sub2 = bVar1;
  obj->sub3 = 0;
  return;
}


// ---- 801df950 FUN_801df950

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df950(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e7154)[obj->sub3])();
  Anim_Step(obj);
  FUN_801e1020(obj);
  return;
}


// ---- 801dfbf0 FUN_801dfbf0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfbf0(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e7164)[obj->sub3])();
  Anim_Step(obj);
  FUN_801e1020(obj);
  return;
}


// ---- 801dfd8c FUN_801dfd8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfd8c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801e7170)[obj->sub2])();
  iVar2 = FUN_801e0fd8(obj,0);
  if (iVar2 == 0) {
    Obj_Free(obj);
  }
  else {
    cVar1 = FUN_801e0f80(obj);
    if (cVar1 == '\x04') {
      obj->sub2 = 3;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
    else if (*(char *)(*(int *)&obj->field_0x4c + 0x5e) == '\x04') {
      obj->state = 6;
      obj->sub2 = 0;
      obj->sub3 = 0;
    }
    else {
      Enemy_ContactDamage(obj);
    }
  }
  return;
}


// ---- 801dfe50 FUN_801dfe50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfe50(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    if (*(char *)(*(int *)&obj->field_0x4c + 0x5e) == '\x02') {
      obj->sub3 = 1;
    }
  }
  else {
    obj->field_0x51 = obj->field_0x51 + '\x01';
    if (0x2f < (byte)obj->field_0x51) {
      obj->sub2 = 1;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
  }
  FUN_801e0ee0(obj,*(undefined4 *)&obj->field_0x4c,0);
  return;
}


// ---- 801dfed4 FUN_801dfed4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfed4(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x4c;
  cVar1 = obj->field_0x52 + '\x01';
  if (*(char *)(iVar2 + 0x5e) == '\x05') {
    cVar1 = obj->field_0x52 + -4;
  }
  obj->field_0x52 = cVar1;
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_LAB_801e7180)[obj->sub3])(obj);
                    /* Possible PsyQ macro: setTile8() */
  FUN_801e0ee0(obj,*(undefined4 *)&obj->field_0x4c,obj->field_0x55);
  Anim_Step(obj);
  if ((*(char *)(iVar2 + 0x5e) == '\x05') && (0x3cf < obj->y)) {
    FUN_8012a5fc(obj,0);
  }
  return;
}


// ---- 801e0288 FUN_801e0288

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0288(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    FUN_801e0354();
  }
  else {
    FUN_801e03f8(obj);
  }
  cVar1 = FUN_801e0f80(obj);
  if (cVar1 == '\x04') {
    obj->state = 2;
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  else {
    if (*(char *)(*(int *)&obj->field_0x4c + 0x5e) == '\x04') {
      obj->state = 6;
      obj->sub2 = 0;
      obj->sub3 = 0;
    }
    iVar2 = FUN_801e0fd8(obj,0);
    if (iVar2 == 0) {
      Obj_Free(obj);
    }
    else {
      Enemy_ContactDamage(obj);
    }
  }
  return;
}


// ---- 801e0354 FUN_801e0354

void FUN_801e0354(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  FUN_80104c34();
  if (*(int *)(param_1 + 0x10) <= *(int *)(*(int *)(param_1 + 0x4c) + 0x10)) {
    iVar2 = ((uint)*(ushort *)(param_1 + 0xe) - (uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 0xe)) *
            0x10000;
    iVar3 = iVar2 >> 0x10;
    cVar4 = (char)((uint)iVar2 >> 0x10);
    if (iVar3 < 0) {
      cVar4 = -cVar4;
    }
    *(char *)(param_1 + 0x51) = cVar4;
    if (iVar3 < 1) {
      uVar1 = 0xc0;
    }
    else {
      uVar1 = 0x40;
    }
    *(undefined1 *)(param_1 + 0x56) = uVar1;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    *(undefined1 *)(param_1 + 0x52) = *(undefined1 *)(param_1 + 0x56);
    *(char *)(param_1 + 2) = *(char *)(param_1 + 2) + '\x01';
  }
  Anim_Step(param_1);
  return;
}


// ---- 801e03f8 FUN_801e03f8

void FUN_801e03f8(int param_1)

{
  char cVar1;
  int iVar2;
  
  *(char *)(param_1 + 0x52) = *(char *)(param_1 + 0x52) + '\x01';
  if (*(char *)(param_1 + 3) == '\0') {
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
    iVar2 = (int)((*(byte *)(param_1 + 0x51) + 0xd0) * 0x1000000) >> 0x18;
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 3) = 1;
    }
    else {
      cVar1 = *(char *)(param_1 + 0x51) + -1;
      if (iVar2 < 1) {
        cVar1 = *(char *)(param_1 + 0x51) + '\x01';
      }
      *(char *)(param_1 + 0x51) = cVar1;
    }
  }
  else if (*(char *)(*(int *)(param_1 + 0x4c) + 0x5e) == '\0') {
    *(undefined1 *)(param_1 + 1) = 2;
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    *(char *)(*(int *)(param_1 + 0x4c) + 0x5b) = *(char *)(*(int *)(param_1 + 0x4c) + 0x5b) + '\x01'
    ;
  }
  FUN_801e0ee0(param_1,*(undefined4 *)(param_1 + 0x4c),0);
  Anim_Step(param_1);
  return;
}


// ---- 801e04c8 FUN_801e04c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e04c8(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e718c)[obj->sub2])();
  cVar1 = FUN_801e0f80(obj);
  if (cVar1 == '\x04') {
    obj->state = 6;
    obj->sub2 = 1;
  }
  else {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801e0540 FUN_801e0540

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0540(MM8Obj *obj)

{
  uint uVar1;
  
  if (obj->sub3 == 0) {
    FUN_80104c34();
    if (obj->y < 0x365) {
      obj->sub3 = 1;
      obj->gravity = 0x2000;
      obj->speed_x = (int)((uint)(byte)obj->field_0x53 * 0x100000 -
                          (*(int *)&obj->x_frac + -0x1a400000)) / 0x21;
    }
  }
  else {
    uVar1 = obj->speed_y_up;
    FUN_80104ccc(obj);
    if ((obj->y < 0x321) || ((obj->speed_y_up & 0x80000000U) != (uVar1 & 0x80000000))) {
      obj->sub2 = 1;
      obj->sub3 = 0;
      obj->field_0x50 = 0x1e;
    }
    FUN_80106214(obj);
  }
  Anim_Step(obj);
  return;
}


// ---- 801e0640 FUN_801e0640

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0640(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  Anim_Step();
  if ((obj->var == 3) || (obj->sub3 != 0)) {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 != '\0') {
      return;
    }
    obj->field_0x57 = 1;
  }
  else {
    iVar3 = *(int *)&obj->field_0x4c;
    iVar2 = FUN_801e0fd8(obj,3);
    if (iVar2 == 0) {
      obj->sub3 = 1;
      return;
    }
    if (*(char *)(iVar3 + 0x57) == '\0') {
      return;
    }
  }
  obj->gravity = 0x4000;
  obj->speed_x = 0;
  obj->speed_y_up = 0;
  obj->sub2 = 2;
  return;
}


// ---- 801e06f8 FUN_801e06f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e06f8(MM8Obj *obj)

{
  if (obj->speed_y_up < -0x5bfff) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->state = 6;
    obj->sub2 = 1;
  }
  return;
}


// ---- 801e076c FUN_801e076c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e076c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->var == 5) {
    FUN_801e0800();
  }
  else {
    FUN_801e091c(obj);
  }
  Anim_Step(obj);
  cVar1 = FUN_801e0f80(obj);
  if ((cVar1 == '\x04') || (iVar2 = Obj_InActiveArea(obj), iVar2 == 0)) {
    obj->state = 6;
    obj->sub2 = 1;
  }
  else {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801e0800 FUN_801e0800

void FUN_801e0800(int param_1)

{
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  if (*(int *)(param_1 + 0x18) < -0x5bfff) {
    *(undefined4 *)(param_1 + 0x18) = 0xfffa0000;
    FUN_80104c34();
  }
  else {
    FUN_80104ccc(param_1);
  }
  if (*(char *)(param_1 + 2) == '\0') {
    if (0x3bf < *(short *)(param_1 + 0x12)) {
      return;
    }
  }
  else {
    FUN_80106214(param_1);
                    /* Probable PsyQ macro: setTile() */
    if ((*(int *)(param_1 + 0x18) < 0) && ((*(byte *)(param_1 + 0x33) & 0x80) != 0)) {
      FUN_8012a5fc(param_1,0);
      FUN_8010544c(param_1,0x182);
      *(undefined4 *)(param_1 + 0x18) = 0x70690;
      return;
    }
    if ((*(byte *)(param_1 + 0x33) & 0x30) == 0) {
      return;
    }
    *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + '\x01';
    *(int *)(param_1 + 0x14) = -*(int *)(param_1 + 0x14);
    if (*(byte *)(param_1 + 3) < 2) {
      FUN_8010544c(param_1,0x182);
      return;
    }
    *(undefined1 *)(param_1 + 1) = 6;
  }
  *(undefined1 *)(param_1 + 2) = 1;
  return;
}


// ---- 801e091c FUN_801e091c

void FUN_801e091c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_801e0fd8(param_1,5);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 1) = 6;
    *(undefined1 *)(param_1 + 2) = 1;
  }
  else {
    FUN_801e0ee0(param_1,*(undefined4 *)(param_1 + 0x4c),0);
  }
  return;
}


// ---- 801e0970 FUN_801e0970

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0970(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyG3() */
  if (obj->sub2 == 0) {
    FUN_801e09b0();
  }
  else {
    FUN_801e0a74();
  }
  return;
}


// ---- 801e09b0 FUN_801e09b0

void FUN_801e09b0(int param_1)

{
  undefined1 uVar1;
  
  if (*(char *)(param_1 + 3) == '\0') {
    FUN_80105120(param_1,0x200,*(undefined1 *)(param_1 + 0x52));
    *(undefined4 *)(param_1 + 0x18) = 0x41200;
    uVar1 = DAT_80159fb1;
    *(undefined1 *)(param_1 + 3) = 1;
    *(undefined1 *)(param_1 + 0x24) = uVar1;
  }
  if (*(int *)(param_1 + 0x18) < -0x5bfff) {
    *(undefined4 *)(param_1 + 0x18) = 0xfffa0000;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 0x4000;
  }
  FUN_80104ccc(param_1);
  FUN_80106214(param_1);
  if ((*(byte *)(param_1 + 0x33) & 0x80) != 0) {
    *(undefined1 *)(param_1 + 2) = 1;
  }
  *(byte *)(param_1 + 0x54) = *(byte *)(param_1 + 0x54) ^ 1;
  return;
}


// ---- 801e0a74 FUN_801e0a74

void FUN_801e0a74(undefined4 param_1)

{
  FUN_80108e84();
  FUN_8012a5fc(param_1,0);
  Obj_Free(param_1);
  return;
}


// ---- 801e0ab0 FUN_801e0ab0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0ab0(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e7198)[obj->sub2])();
  return;
}


// ---- 801e0e60 FUN_801e0e60

undefined1 *
FUN_801e0e60(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_801055e4();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x2a;
    puVar1[7] = param_2;
    puVar1[0x51] = param_4;
    puVar1[0x52] = param_3;
    FUN_801e0ee0(puVar1,0,0);
  }
  return puVar1;
}


// ---- 801e0ee0 FUN_801e0ee0

void FUN_801e0ee0(int param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_801098e8(*(undefined1 *)(param_1 + 0x52),*(undefined1 *)(param_1 + 0x51),0);
                    /* Possible PsyQ macro: setTile8() */
  *(int *)(param_1 + 0xc) = -iVar1;
  uVar2 = FUN_801098e8(*(char *)(param_1 + 0x52) + '@',*(undefined1 *)(param_1 + 0x51),(int)param_3)
  ;
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  if (param_2 != 0) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + *(int *)(param_2 + 0xc);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + *(int *)(param_2 + 0x10);
  }
  return;
}


// ---- 801e0f80 FUN_801e0f80

char FUN_801e0f80(int param_1)

{
  char cVar1;
  
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 == '\x02') {
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x24) = DAT_80159fb1;
  }
  return cVar1;
}


// ---- 801e0fd8 FUN_801e0fd8

bool FUN_801e0fd8(int param_1,char param_2)

{
  bool bVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x4c);
  bVar1 = false;
  if (((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) && (pcVar2[6] == '*')) {
    bVar1 = pcVar2[7] == param_2;
  }
  return bVar1;
}


// ---- 801e1020 FUN_801e1020

undefined1 FUN_801e1020(int param_1)

{
                    /* Possible PsyQ macro: setPolyG4() */
  if ((*(short *)(param_1 + 0x2e) < 0) && (*(char *)(param_1 + 0x31) == '\x01')) {
    if (*(char *)(param_1 + 0x55) == '\0') {
      return 0;
    }
                    /* Possible PsyQ macro: setTile8() */
    Anim_Set(param_1,*(byte *)(param_1 + 0x55) & 0xf);
    *(byte *)(param_1 + 0x55) = *(byte *)(param_1 + 0x55) >> 4;
  }
  return *(undefined1 *)(param_1 + 0x55);
}


