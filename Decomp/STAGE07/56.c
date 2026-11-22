// ID 56, STAGE07.BIN, handler 0x801DB5C8. Ghidra output with the object struct applied; not matching C.
// ---- 801db5c8 FUN_801db5c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db5c8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e0a14)[obj->state])();
  return;
}


// ---- 801db604 FUN_801db604

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db604(MM8Obj *obj)

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
  obj->hitbox = &DAT_801e0974;
  obj->box2 = &DAT_801e097c;
  Anim_Set(obj,1);
  FUN_80103224(obj);
  obj->state = 1;
  return;
}


// ---- 801db6c8 FUN_801db6c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db6c8(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e0a24)[obj->sub2])();
  return;
}


// ---- 801dbcc8 FUN_801dbcc8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbcc8(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801e0a40)[obj->sub2])();
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


// ---- 801dbea8 FUN_801dbea8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbea8(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  undefined *puVar6;
  
  if (obj->sub3 == 0) {
    obj->hitbox = &DAT_801e0974;
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
        puVar6 = &DAT_801e0984;
      }
      else {
        puVar6 = &DAT_801e09a4;
        if ((short)iVar3 < 0xa0) {
          puVar6 = &UNK_801e0994;
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
    FUN_801dcdf4(obj);
    FUN_801dce20(obj);
  }
  return;
}


// ---- 801dc074 FUN_801dc074

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc074(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyF4() */
  (*(code *)(&PTR_FUN_801e0a58)[obj->sub3])();
  FUN_801dce20(obj);
  return;
}


// ---- 801dc0c4 FUN_801dc0c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc0c4(MM8Obj *obj)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = Rand();
  iVar3 = (int)DAT_801d2928;
  sVar1 = *(short *)(&DAT_801e09b4 + (uVar2 & 0xf) * 2);
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


// ---- 801dc198 FUN_801dc198

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc198(MM8Obj *obj)

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


// ---- 801dc1f8 FUN_801dc1f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc1f8(MM8Obj *obj)

{
  Anim_Step();
                    /* Possible PsyQ macro: setPolyGT4() */
  if ((short)obj->frame < 0) {
    FUN_801dcde4(obj);
  }
  FUN_801dcdf4(obj);
  return;
}


// ---- 801dc240 FUN_801dc240

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc240(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e0a64)[obj->sub3])();
  FUN_801dce20(obj);
  return;
}


// ---- 801dc290 FUN_801dc290

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc290(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
                    /* Possible PsyQ macro: setPolyF4() */
    obj->hitbox = &DAT_801e0978;
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
                    /* Possible PsyQ macro: setPolyGT4() */
    FUN_801dcdf4(obj);
  }
  return;
}


// ---- 801dc344 FUN_801dc344

/* WARNING: Removing unreachable block (ram,0x801dc438) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc344(MM8Obj *obj)

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
      sVar1 = *(short *)(&DAT_801e09d4 + (uVar4 & 0xf) * 2);
      obj->field_0x4 = 0;
      obj->x = sVar2 + sVar1;
      obj->field_0x50 = obj->field_0x56;
    }
  }
  FUN_801dcdf4(obj);
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801dc4a8 FUN_801dc4a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc4a8(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x50 = 0x1e;
    obj->field_0x56 = 0x10;
    obj->field_0x53 = 0;
    obj->field_0x57 = 0xff;
                    /* Probable PsyQ macro: setTile16() */
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


// ---- 801dc54c FUN_801dc54c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc54c(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
                    /* Possible PsyQ macro: setPolyF3() */
  Anim_Step();
                    /* Possible PsyQ macro: setTile16() */
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
    sVar2 = DAT_801d2928 + *(short *)(&DAT_801e09f4 + (uVar3 & 0xf) * 2);
    iVar6 = (int)sVar2 - (int)obj->x;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if ((0x1f < iVar6) && (iVar6 = FUN_801dd108(obj,0,0,1), iVar6 != 0)) {
      *(short *)(iVar6 + 0xe) = sVar2;
      *(short *)(iVar6 + 0x12) = DAT_801d292a + -0x14;
    }
    obj->field_0x50 = 8;
    cVar1 = obj->field_0x56 + -1;
    obj->field_0x56 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0x3c;
      Anim_Set(obj,4);
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
      obj->sub3 = 4;
      obj->field_0x4 = 0;
    }
  }
  if ((DAT_80170574 & 7) == 0) {
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
  FUN_801dcdf4(obj);
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


// ---- 801dc790 FUN_801dc790

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc790(MM8Obj *obj)

{
  char cVar1;
  
  obj->field_0x53 = obj->field_0x53 ^ 1;
  DAT_801d2936 = 1;
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->field_0x53 = 1;
    FUN_801dcde4();
  }
  return;
}


// ---- 801dc874 FUN_801dc874

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc874(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801e0a78)[obj->sub3])();
  FUN_801dcdf4(obj);
  FUN_801dce20(obj);
  return;
}


// ---- 801dc8cc FUN_801dc8cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc8cc(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->hitbox = &DAT_801e0978;
    Anim_Set(obj,4);
    obj->field_0x50 = 0xf;
    obj->field_0x51 = 0x81;
    obj->field_0x58 = 0;
    obj->field_0x4 = 1;
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
                    /* Probable PsyQ macro: setTile16() */
    if (cVar1 == '\0') {
      Anim_Set(obj,5);
      FUN_8010544c(obj,0x1a2);
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801dc96c caseD_3

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801dc924::caseD_3(MM8Obj *obj)

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


// ---- 801dca04 FUN_801dca04

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dca04(MM8Obj *obj)

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


// ---- 801dca8c FUN_801dca8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dca8c(MM8Obj *obj)

{
                    /* Probable PsyQ macro: setPolyGT4() */
  if ((obj->field_0x4 == '\0') && (1 < (byte)obj->field_0x58)) {
    obj->field_0x58 = 0;
    obj->field_0x52 = 5;
    Anim_Set(obj,4);
    obj->speed_y_up = 0x20000;
                    /* Possible PsyQ macro: setLineF2() */
    obj->sub3 = 4;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801dcaf8 FUN_801dcaf8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcaf8(MM8Obj *obj)

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
    FUN_801dcde4();
  }
  return;
}


// ---- 801dcb8c FUN_801dcb8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcb8c(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_801dcbcc();
  }
  else {
    FUN_801dcd40();
  }
  return;
}


// ---- 801dcbcc FUN_801dcbcc

void FUN_801dcbcc(int param_1)

{
                    /* Possible PsyQ macro: setPolyGT4() */
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


// ---- 801dcc50 FUN_801dcc50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcc50(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_801dcc90();
  }
  else {
    FUN_801dcd40();
  }
  return;
}


// ---- 801dcc90 FUN_801dcc90

void FUN_801dcc90(int param_1)

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


// ---- 801dcd40 FUN_801dcd40

void FUN_801dcd40(int param_1)

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
      FUN_801dcde4();
    }
  }
  return;
}


// ---- 801dcde4 FUN_801dcde4

void FUN_801dcde4(int param_1)

{
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}


// ---- 801dcdf4 FUN_801dcdf4

void FUN_801dcdf4(int param_1)

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


// ---- 801dce20 FUN_801dce20

void FUN_801dce20(int param_1)

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


// ---- 801dce98 FUN_801dce98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce98(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e0a8c)[obj->sub2])();
  return;
}


// ---- 801dced4 FUN_801dced4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dced4(MM8Obj *obj)

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


// ---- 801dcf6c FUN_801dcf6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcf6c(MM8Obj *obj)

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


// ---- 801dd024 FUN_801dd024

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd024(MM8Obj *obj)

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


// ---- 801dd108 FUN_801dd108

undefined1 * FUN_801dd108(int param_1,char param_2,char param_3,byte param_4)

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


