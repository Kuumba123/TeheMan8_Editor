// ID 56, STAGE0D.BIN, handler 0x801F1580. Ghidra output with the object struct applied; not matching C.
// ---- 801f1580 FUN_801f1580

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f1580(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8f34)[obj->state])();
  return;
}


// ---- 801f15bc FUN_801f15bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f15bc(MM8Obj *obj)

{
  short sVar1;
  
  Enemy_InitFromTable();
  obj->field_0x49 = 0xb;
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
  obj->x = DAT_801d2928 + 0xa0;
  sVar1 = DAT_801d292a;
  obj->draw_list = 7;
  obj->field_0x51 = 0x83;
  obj->flip = 0;
  obj->field_0x52 = 0;
  obj->field_0x5f = 0;
  obj->field_0x53 = 0;
  obj->field_0x59 = 0;
  obj->field_0x5a = 0;
  obj->field_0x5b = 0;
  obj->field_0x5c = 0;
  obj->y = sVar1 + 0x78;
  DAT_801b29a5 = 0;
  obj->hitbox = &DAT_801f8e94;
  obj->box2 = &DAT_801f8e9c;
  Anim_Set(obj,1);
  FUN_80103224(obj);
  obj->state = 1;
  return;
}


// ---- 801f1680 FUN_801f1680

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f1680(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801f8f44)[obj->sub2])();
  return;
}


// ---- 801f1c80 FUN_801f1c80

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f1c80(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801f8f60)[obj->sub2])();
  bVar1 = DAT_8015a003;
  obj->on_screen = 1;
  obj->clut = bVar1;
  if (obj->field_0x59 == '\0') {
    obj->invuln = 0;
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (iVar2 == 4) {
      FUN_8010544c(obj,0x1a5);
      FUN_8010544c(obj,0x10);
      obj->state = 3;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      DAT_8015e2af = 1;
      return;
    }
    if (iVar2 == 2) {
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x59 = 0x3c;
      if (DAT_80158f5c == '\f') {
        obj->sub2 = 5;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
      }
      else {
        FUN_8010544c(obj,0x1a5);
      }
      FUN_8010544c(obj,0x10);
    }
  }
  else {
    bVar1 = obj->hp;
                    /* Possible PsyQ macro: setPolyF4() */
    obj->hp = 0x28;
    obj->invuln = 0;
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (iVar2 == 2) {
      FUN_8010544c(obj,0x4f);
    }
    obj->hp = bVar1;
    bVar1 = obj->field_0x59 - 1;
    obj->field_0x59 = bVar1;
    if ((bVar1 & 1) != 0) {
      obj->clut = 0;
    }
  }
  if ((obj->field_0x5c & 1) == 0) {
    Enemy_ContactDamage(obj);
  }
  FUN_80103184(obj);
  if (obj->field_0x53 != '\0') {
    Obj_CullAndQueueDraw(obj);
  }
  if (((DAT_801b1ecc == '\0') || (DAT_801b1ece._1_1_ == '\0')) || ((obj->field_0x5c & 2) != 0)) {
    obj->invuln = 1;
  }
  else {
    obj->invuln = 0;
  }
  return;
}


// ---- 801f1e60 FUN_801f1e60

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f1e60(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  undefined *puVar6;
  
  if (obj->sub3 == 0) {
    obj->hitbox = &DAT_801f8e94;
    Anim_Set();
    obj->field_0x53 = 1;
    obj->field_0x51 = 1;
    obj->field_0x50 = 0x1e;
    obj->sub3 = 1;
  }
  else {
    Anim_Step(obj,1);
    if (obj->field_0x50 == '\x0f') {
      FUN_8010910c(obj);
    }
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      iVar3 = (int)DAT_8015e248._2_2_ - (int)obj->x;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if ((short)iVar3 < 0x40) {
        puVar6 = &DAT_801f8ea4;
      }
      else {
        puVar6 = &DAT_801f8ec4;
        if ((short)iVar3 < 0xa0) {
          puVar6 = &UNK_801f8eb4;
        }
      }
      uVar4 = Rand();
      bVar5 = puVar6[uVar4 & 0xf];
      if ((obj->field_0x5a == bVar5) &&
         (bVar2 = obj->field_0x5b + 1, obj->field_0x5b = bVar2, 2 < bVar2)) {
        cVar1 = '\0';
        do {
          uVar4 = Rand();
          bVar5 = puVar6[uVar4 & 0xf];
          cVar1 = cVar1 + '\x01';
          if (obj->field_0x5a != bVar5) {
            obj->field_0x5b = 0;
            break;
          }
        } while (cVar1 != -1);
        if ((obj->field_0x5b != '\0') && (bVar5 != 1)) {
          bVar5 = 1;
        }
      }
      obj->sub2 = bVar5;
      obj->field_0x5a = bVar5;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
    FUN_801f2dac(obj);
    FUN_801f2dd8(obj);
  }
  return;
}


// ---- 801f202c FUN_801f202c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f202c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8f78)[obj->sub3])();
  FUN_801f2dd8(obj);
  return;
}


// ---- 801f207c FUN_801f207c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f207c(MM8Obj *obj)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = Rand();
  iVar3 = (int)DAT_801d2928;
  sVar1 = *(short *)(&DAT_801f8ed4 + (uVar2 & 0xf) * 2);
  obj->speed_y_up = -0x4f000;
  obj->speed_x = ((iVar3 + sVar1) * 0x10000 - *(int *)&obj->x_frac) / 0x50;
  obj->gravity = -0x2000;
  if (obj->speed_x == 0) {
    FUN_8010910c(obj);
  }
  else {
    obj->flip = (char)~(byte)((uint)obj->speed_x >> 0x18) >> 7 & 0x40;
  }
  obj->field_0x52 = 1;
  *(short *)&obj->field_0x54 = obj->y;
  Anim_Set(obj,2);
  obj->sub3 = 1;
  return;
}


// ---- 801f2150 FUN_801f2150

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2150(MM8Obj *obj)

{
  FUN_80104ccc();
  Anim_Step(obj);
  if ((int)obj->y < DAT_801d292a + 0x40) {
    obj->y = DAT_801d292a + 0x40;
    obj->field_0x5f = 0;
    obj->sub3 = 2;
  }
  return;
}


// ---- 801f21b0 FUN_801f21b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f21b0(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    FUN_801f2d9c(obj);
  }
  FUN_801f2dac(obj);
  return;
}


// ---- 801f21f8 FUN_801f21f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f21f8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8f84)[obj->sub3])();
  FUN_801f2dd8(obj);
  return;
}


// ---- 801f2248 FUN_801f2248

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2248(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->hitbox = &DAT_801f8e98;
    Anim_Set(obj,4);
    obj->field_0x50 = 0xf;
    obj->field_0x51 = 0x81;
    obj->field_0x4 = 1;
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x56 = 0x20;
      obj->field_0x50 = 0x20;
      obj->field_0x57 = 1;
      obj->sub3 = 1;
      obj->field_0x4 = 0;
      obj->field_0x5c = obj->field_0x5c | 1;
      FUN_8010544c(obj,0x19f);
    }
    FUN_801f2dac(obj);
  }
  return;
}


// ---- 801f22fc FUN_801f22fc

/* WARNING: Removing unreachable block (ram,0x801f23f0) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f22fc(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  
  if (obj->field_0x4 == '\0') {
    cVar3 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar3;
    obj->field_0x53 = obj->field_0x53 ^ 1;
    if (cVar3 == '\0') {
      obj->field_0x53 = 0;
      obj->field_0x4 = 1;
      obj->field_0x50 = obj->field_0x56;
    }
  }
  else {
    cVar3 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar3;
    if (cVar3 == '\0') {
      if (obj->field_0x56 == ' ') {
        obj->field_0x52 = 2;
      }
      cVar3 = obj->field_0x57 + -1;
      obj->field_0x57 = cVar3;
      if (cVar3 == '\0') {
        obj->field_0x56 = (byte)obj->field_0x56 >> 1;
        uVar4 = (uint)(byte)obj->field_0x56;
        if (uVar4 == 2) {
          obj->sub3 = 2;
          obj->field_0x4 = 0;
          return;
        }
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        obj->field_0x57 = (char)(0x20 / uVar4);
      }
      FUN_8010544c(obj,0x19f);
      uVar4 = Rand();
      sVar2 = DAT_801d2928;
      sVar1 = *(short *)(&DAT_801f8ef4 + (uVar4 & 0xf) * 2);
      obj->field_0x4 = 0;
      obj->x = sVar2 + sVar1;
      obj->field_0x50 = obj->field_0x56;
    }
  }
  FUN_801f2dac(obj);
  return;
}


// ---- 801f2460 FUN_801f2460

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2460(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x50 = 0x1e;
    obj->field_0x56 = 0x10;
    obj->field_0x53 = 0;
    obj->field_0x57 = 0xff;
    obj->field_0x5c = obj->field_0x5c & 0xfe;
    FUN_8010544c(obj,0x1a3);
    obj->field_0x4 = 1;
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      Anim_Set(obj,6);
      obj->field_0x50 = 1;
      obj->sub3 = 3;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801f2504 FUN_801f2504

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2504(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  Anim_Step();
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    uVar3 = Rand();
    if (((byte)obj->field_0x57 & 7) == (uVar3 & 7)) {
      iVar6 = 0;
      do {
        uVar3 = Rand();
        iVar6 = iVar6 + 1;
        if (((byte)obj->field_0x57 & 7) != (uVar3 & 7)) break;
      } while (iVar6 * 0x10000 >> 0x10 < 0x80);
    }
    obj->field_0x57 = (char)(uVar3 & 0xf);
    sVar2 = DAT_801d2928 + *(short *)(&DAT_801f8f14 + (uVar3 & 0xf) * 2);
    iVar6 = (int)sVar2 - (int)obj->x;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if ((0x1f < iVar6) && (iVar6 = FUN_801f30c0(obj,0,0,1), iVar6 != 0)) {
      *(short *)(iVar6 + 0xe) = sVar2;
      *(short *)(iVar6 + 0x12) = DAT_801d292a + -0x14;
    }
    obj->field_0x50 = 8;
    cVar1 = obj->field_0x56 + -1;
    obj->field_0x56 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0x3c;
      Anim_Set(obj,4);
      obj->sub3 = 4;
      obj->field_0x4 = 0;
    }
  }
  if ((_DAT_80170574 & 7) == 0) {
    uVar3 = Rand();
    iVar4 = (uint)DAT_801d2928 + (uVar3 & 0x1f) * 10;
    iVar6 = (iVar4 * 0x10000 >> 0x10) - (int)obj->x;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if ((0x1f < iVar6) && (puVar5 = (undefined1 *)Obj_AllocType3(), puVar5 != (undefined1 *)0x0)) {
      *puVar5 = 1;
      puVar5[6] = 0x3d;
      puVar5[7] = 2;
      *(short *)(puVar5 + 0xe) = (short)iVar4;
      *(short *)(puVar5 + 0x12) = DAT_801d292a + -0x14;
    }
  }
  FUN_801f2dac(obj);
  DAT_801d2936 = 1;
  iVar6 = FUN_80105cd4(obj,4);
  if (iVar6 == 0) {
    obj->field_0x53 = 0;
  }
  else {
    obj->field_0x53 = (byte)iVar6 & 1;
  }
  return;
}


// ---- 801f2748 FUN_801f2748

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2748(MM8Obj *obj)

{
  char cVar1;
  
  obj->field_0x53 = obj->field_0x53 ^ 1;
  DAT_801d2936 = 1;
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->field_0x53 = 1;
    FUN_801f2d9c();
  }
  return;
}


// ---- 801f282c FUN_801f282c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f282c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8f98)[obj->sub3])();
  FUN_801f2dac(obj);
  FUN_801f2dd8(obj);
  return;
}


// ---- 801f2884 FUN_801f2884

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2884(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->hitbox = &DAT_801f8e98;
    Anim_Set(obj,4);
    obj->field_0x50 = 0xf;
    obj->field_0x51 = 0x81;
    obj->field_0x58 = 0;
    obj->field_0x4 = 1;
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      Anim_Set(obj,5);
      FUN_8010544c(obj,0x1a2);
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801f2924 FUN_801f2924

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2924(MM8Obj *obj)

{
  Anim_Step();
  if (obj->field_0x4 == '\0') {
    if (obj->anim_extra != 0) {
      obj->field_0x52 = 3;
      obj->speed_y_up = -0x20000;
      obj->speed_x = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104c34(obj);
    if (DAT_801d292a + 0x60 <= (int)obj->y) {
      obj->gravity = -0x4000;
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801f29bc FUN_801f29bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f29bc(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_80104ccc();
    if ((obj->speed_y_up == 0) || (-1 < obj->speed_y_up)) {
      obj->field_0x4 = 1;
    }
  }
  else if (1 < (byte)obj->field_0x58) {
    obj->field_0x52 = 4;
    obj->field_0x58 = 0;
    obj->sub3 = 3;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801f2a44 FUN_801f2a44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2a44(MM8Obj *obj)

{
  if ((obj->field_0x4 == '\0') && (1 < (byte)obj->field_0x58)) {
    obj->field_0x58 = 0;
    obj->field_0x52 = 5;
    Anim_Set(obj,4);
    obj->speed_y_up = 0x20000;
    obj->sub3 = 4;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801f2ab0 FUN_801f2ab0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2ab0(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_80104c34();
    if ((int)obj->y <= DAT_801d292a + 0x40) {
      obj->y = DAT_801d292a + 0x40;
      obj->field_0x5f = 0;
      obj->field_0x4 = 1;
    }
  }
  else if (1 < (byte)obj->field_0x58) {
    obj->field_0x58 = 0;
    obj->field_0x52 = 2;
    FUN_801f2d9c();
  }
  return;
}


// ---- 801f2b44 FUN_801f2b44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2b44(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_801f2b84();
  }
  else {
    FUN_801f2cf8();
  }
  return;
}


// ---- 801f2b84 FUN_801f2b84

void FUN_801f2b84(int param_1)

{
  if (*(char *)(param_1 + 4) == '\0') {
    *(undefined1 *)(param_1 + 0x53) = 1;
    *(undefined1 *)(param_1 + 0x51) = 0x81;
    Anim_Set();
    FUN_8010544c(param_1,0x1a6);
    *(undefined1 *)(param_1 + 4) = 1;
  }
  else {
    Anim_Step(param_1,3);
    if (*(short *)(param_1 + 0x2e) < 0) {
      *(undefined1 *)(param_1 + 3) = 1;
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
  return;
}


// ---- 801f2c08 FUN_801f2c08

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2c08(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_801f2c48();
  }
  else {
    FUN_801f2cf8();
  }
  return;
}


// ---- 801f2c48 FUN_801f2c48

void FUN_801f2c48(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 4) == '\0') {
    *(undefined1 *)(param_1 + 0x51) = 0x81;
    *(undefined1 *)(param_1 + 0x53) = 1;
    *(undefined1 *)(param_1 + 0x52) = 7;
    *(byte *)(param_1 + 0x5c) = *(byte *)(param_1 + 0x5c) | 2;
    Anim_Set(param_1,7);
    FUN_8010544c(param_1,0x1a7);
    *(undefined1 *)(param_1 + 0x50) = 0x46;
    *(undefined1 *)(param_1 + 4) = 1;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x50) + -1;
    *(char *)(param_1 + 0x50) = cVar1;
    if (cVar1 == '\0') {
      FUN_8010544c(param_1,0x1a4);
      *(undefined1 *)(param_1 + 3) = 1;
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
  return;
}


// ---- 801f2cf8 FUN_801f2cf8

void FUN_801f2cf8(int param_1)

{
  if (*(char *)(param_1 + 4) == '\0') {
    Anim_Set(param_1,2);
    *(undefined4 *)(param_1 + 0x18) = 0x1000;
    *(undefined4 *)(param_1 + 0x20) = 0xfffff000;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 0x51) = 1;
    *(undefined1 *)(param_1 + 0x52) = 1;
    *(undefined1 *)(param_1 + 4) = 1;
  }
  else {
    FUN_80104ccc(param_1);
    if ((int)*(short *)(param_1 + 0x12) <= DAT_801d292a + 0x40) {
      *(short *)(param_1 + 0x12) = DAT_801d292a + 0x40;
      *(byte *)(param_1 + 0x5c) = *(byte *)(param_1 + 0x5c) & 0xfd;
      FUN_801f2d9c();
    }
  }
  return;
}


// ---- 801f2d9c FUN_801f2d9c

void FUN_801f2d9c(int param_1)

{
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}


// ---- 801f2dac FUN_801f2dac

void FUN_801f2dac(int param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 0x5f);
  *(byte *)(param_1 + 0x5f) = bVar1 + 1;
  iVar2 = *(int *)(param_1 + 0x10) + 0x2000;
  if ((bVar1 & 0x20) == 0) {
    iVar2 = *(int *)(param_1 + 0x10) + -0x2000;
  }
  *(int *)(param_1 + 0x10) = iVar2;
  return;
}


// ---- 801f2dd8 FUN_801f2dd8

void FUN_801f2dd8(int param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  
  pcVar3 = &DAT_801d184c;
  piVar2 = &DAT_801d1868;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 0x40;
    if (((cVar1 != '\0') && (*(char *)((int)piVar2 + -0x16) == '\x06')) && (param_1 == *piVar2)) {
      *(undefined1 *)(param_1 + 2) = 4;
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
    }
    piVar2 = piVar2 + 0x10;
  } while (pcVar3 <= "");
  return;
}


// ---- 801f2e50 FUN_801f2e50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2e50(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8fac)[obj->sub2])();
  return;
}


// ---- 801f2e8c FUN_801f2e8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2e8c(MM8Obj *obj)

{
  FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  FUN_800fcd84();
  obj->field_0x51 = 0x82;
  obj->field_0x52 = 6;
  Anim_Set(obj,7);
  obj->sub2 = 1;
  obj->sub3 = 0;
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801f2f24 FUN_801f2f24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2f24(MM8Obj *obj)

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
    obj->clut = DAT_8015a003;
  }
  else {
    obj->clut = 0;
  }
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x50 = 0x78;
    bVar1 = DAT_8015a003;
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->clut = bVar1;
  }
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801f2fdc FUN_801f2fdc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f2fdc(MM8Obj *obj)

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
    FUN_8010544c(obj,0x1a8);
    obj->sub2 = 3;
    obj->field_0x50 = 1;
    obj->sub3 = 0;
    obj->on_screen = 0;
    DAT_801b29a5 = 2;
  }
  return;
}


// ---- 801f30c0 FUN_801f30c0

undefined1 * FUN_801f30c0(int param_1,char param_2,char param_3,byte param_4)

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
    puVar3[6] = 0x57;
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


