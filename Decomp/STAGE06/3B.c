// ID 3B, STAGE06.BIN, handler 0x801DDC80. Ghidra output with the object struct applied; not matching C.
// ---- 801ddc80 FUN_801ddc80

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddc80(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5998)[obj->state])();
  return;
}


// ---- 801ddcbc FUN_801ddcbc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddcbc(MM8Obj *obj)

{
  int iVar1;
  
                    /* Possible PsyQ macro: setLineF2() */
  Enemy_InitFromTable();
  iVar1 = (uint)obj->var * 8;
  obj->dmg_table = (&DAT_801e5920)[iVar1];
  obj->contact_dmg = (&DAT_801e5921)[iVar1];
  obj->hp = (&DAT_801e5922)[iVar1];
  obj->draw_list = (&DAT_801e5923)[iVar1];
  obj->hitbox = &UNK_801e58f8 + (uint)(byte)(&DAT_801e5926)[iVar1] * 4;
  obj->box2 = &UNK_801e5910 + (uint)(byte)(&DAT_801e5927)[iVar1] * 5;
  Anim_Set(obj,(&DAT_801e5924)[iVar1]);
  if ((byte)(&DAT_801e5925)[iVar1] != 0) {
    (*(code *)(&PTR_FUN_801e59ac)[(byte)(&DAT_801e5925)[iVar1]])(obj);
  }
  obj->state = (&DAT_801e5925)[iVar1];
  return;
}


// ---- 801ddda8 FUN_801ddda8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddda8(MM8Obj *obj)

{
  short sVar1;
  
  obj->speed_x = (int)*(short *)(&DAT_801e5958 + (uint)(byte)obj->field_0x5f * 4) << 8;
  sVar1 = *(short *)(&DAT_801e595a + (uint)(byte)obj->field_0x5f * 4);
  obj->gravity = 0x4000;
  obj->speed_y_up = (int)sVar1 << 8;
  if ((obj->flip & 0x40) == 0) {
    obj->speed_x = -obj->speed_x;
  }
  FUN_8010544c(obj,0x14e);
  obj->field_0x51 = 0;
  return;
}


// ---- 801dde38 FUN_801dde38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dde38(MM8Obj *obj)

{
  int iVar1;
  
  obj->field_0x51 = 0;
  obj->field_0x58 = 1;
  obj->field_0x59 = 0;
  *(short *)&obj->field_0x54 = obj->x;
  *(short *)&obj->field_0x56 = obj->x;
  if ((obj->flip & 0x40) == 0) {
    obj->speed_x = -0x30000;
    obj->field_0x52 = 0;
  }
  else {
    obj->speed_x = 0x30000;
    obj->field_0x52 = 2;
  }
  obj->speed_y_up = 0;
  iVar1 = FUN_801df304(obj,0,0,1);
  if (iVar1 != 0) {
    *(MM8Obj **)(iVar1 + 0x3c) = obj;
    *(undefined1 *)(iVar1 + 0x3a) = obj->field_0x52;
  }
  return;
}


// ---- 801ddedc FUN_801ddedc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddedc(MM8Obj *obj)

{
  obj->hitbox = &DAT_801e58fc + ((byte)obj->field_0x52 & 1) * 4;
  FUN_8010544c(obj,0x14e);
  return;
}


// ---- 801ddf18 FUN_801ddf18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddf18(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = FUN_801df304(obj,(iVar3 * 0x10 + -0x20) * 0x1000000 >> 0x18,
                         (int)(char)(&DAT_801e59c4)[(char)iVar3],7);
    if (iVar2 != 0) {
      *(MM8Obj **)(iVar2 + 0x3c) = obj;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 * 0x1000000 >> 0x18 < 5);
  sVar1 = obj->y;
  obj->y = sVar1 + 0x10;
  *(short *)&obj->field_0x54 = sVar1 + 8;
  *(short *)&obj->field_0x56 = obj->y;
  iVar3 = FUN_801df304(obj,0,8,5);
  if (iVar3 != 0) {
    *(MM8Obj **)(iVar3 + 0x3c) = obj;
    *(undefined1 *)(iVar3 + 0x39) = 0;
  }
  obj->speed_y_up = 0x80000;
  obj->speed_x = 0;
  obj->field_0x51 = 0;
                    /* Possible PsyQ macro: setLineF2() */
  obj->field_0x50 = 0x2d;
  return;
}


// ---- 801ddff4 FUN_801ddff4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddff4(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  iVar6 = 0;
  do {
    iVar4 = FUN_801df304(obj,(iVar6 * 0x10 + -0x20) * 0x1000000 >> 0x18,
                         (int)(char)(&DAT_801e59c4)[(char)iVar6],0xe);
    if (iVar4 != 0) {
      *(MM8Obj **)(iVar4 + 0x3c) = obj;
      puVar5 = (undefined1 *)FUN_801057b0(iVar4);
      if (puVar5 != (undefined1 *)0x0) {
        *puVar5 = 1;
        puVar5[6] = 0x2a;
        puVar5[7] = 0xd;
        *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)(iVar4 + 0xc);
        *(undefined4 *)(puVar5 + 0x10) = *(undefined4 *)(iVar4 + 0x10);
        bVar1 = obj->flip;
        *(MM8Obj **)(puVar5 + 0x3c) = obj;
        puVar5[0x25] = bVar1;
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 * 0x1000000 >> 0x18 < 5);
  sVar3 = obj->y;
  obj->speed_y_up = 0x80000;
  obj->speed_x = 0;
  obj->field_0x58 = 0;
  obj->field_0x5a = 0;
  obj->field_0x51 = 0;
  obj->field_0x50 = 5;
  obj->field_0x52 = 0;
  obj->y = sVar3 + 0x10;
  *(short *)&obj->field_0x54 = sVar3 + 8;
  *(short *)&obj->field_0x56 = obj->y;
  iVar6 = FUN_801df304(obj,0,8,9);
  if (iVar6 != 0) {
    *(MM8Obj **)(iVar6 + 0x3c) = obj;
    *(undefined1 *)(iVar6 + 0x39) = 0;
    cVar2 = obj->field_0x5a;
    obj->field_0x5a = cVar2 + '\x01';
    *(char *)(iVar6 + 0x3b) = cVar2;
  }
  return;
}


// ---- 801de150 FUN_801de150

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de150(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  (*(code *)(&PTR_FUN_801e59cc)[obj->sub2])();
  return;
}


// ---- 801de18c FUN_801de18c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de18c(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80104ccc();
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  obj->clut = DAT_80159fd1;
  iVar1 = Enemy_CheckWeaponHits(obj);
  if (iVar1 == 2) {
    obj->clut = 0;
  }
  if (iVar1 != 4) {
    FUN_80106214(obj);
    if (obj->field_0x33 != '\0') {
      obj->field_0x51 = obj->field_0x33 & 0x80;
      FUN_801de45c();
      return;
    }
    iVar1 = Enemy_ContactDamage(obj);
    if (iVar1 == 0) {
      iVar1 = Obj_InActiveArea(obj);
      if (iVar1 != 0) {
        return;
      }
      Obj_Free(obj);
      return;
    }
  }
  FUN_801de45c(obj);
  return;
}


// ---- 801de260 FUN_801de260

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de260(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  
  if (obj->field_0x51 == '\0') {
    iVar2 = (int)obj->x;
    iVar3 = (int)obj->y;
    bVar5 = obj->draw_list;
    uVar4 = 1;
  }
  else {
    bVar5 = obj->sub3;
    if (bVar5 == 1) {
      cVar1 = obj->field_0x50 + -1;
      obj->field_0x50 = cVar1;
      if (cVar1 != '\0') {
        return;
      }
      FUN_801df124((int)obj->x,(int)(((ushort)obj->y + 0x28) * 0x10000) >> 0x10,3,obj->draw_list);
      obj->field_0x50 = 6;
      obj->sub3 = 2;
      return;
    }
    if (bVar5 < 2) {
      if (bVar5 != 0) {
        return;
      }
      FUN_801df124((int)obj->x,(int)obj->y,2,obj->draw_list);
      obj->field_0x50 = 6;
      obj->sub3 = 1;
      return;
    }
    if (bVar5 != 2) {
      return;
    }
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 != '\0') {
      return;
    }
                    /* Possible PsyQ macro: setLineF2() */
    FUN_801df124((int)(((ushort)obj->x + 0xc) * 0x10000) >> 0x10,
                 (int)(((ushort)obj->y + 0x28) * 0x10000) >> 0x10,3,obj->draw_list - 1);
    uVar4 = 4;
    iVar2 = (int)(((ushort)obj->x - 0xc) * 0x10000) >> 0x10;
                    /* Possible PsyQ macro: setPolyF4() */
    iVar3 = (int)(((ushort)obj->y + 0x28) * 0x10000) >> 0x10;
    bVar5 = obj->draw_list + 1;
  }
  FUN_801df124(iVar2,iVar3,uVar4,bVar5);
  Obj_Free(obj);
  return;
}


// ---- 801de3e4 FUN_801de3e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de3e4(MM8Obj *obj)

{
  if (obj->field_0x51 == '\0') {
    FUN_801df124((int)obj->x,(int)obj->y,0x1b,obj->draw_list);
  }
  else {
    FUN_801df124((int)obj->x,(int)obj->y,0x1c,obj->draw_list);
    FUN_8010544c(obj,0x159);
  }
  Obj_Free(obj);
  return;
}


// ---- 801de45c FUN_801de45c

void FUN_801de45c(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = 2;
  if (*(char *)(param_1 + 7) == '\0') {
    uVar1 = 1;
  }
  *(undefined1 *)(param_1 + 2) = uVar1;
  return;
}


// ---- 801de478 FUN_801de478

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de478(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  (*(code *)(&PTR_FUN_801e59d8)[obj->sub2])();
  if (obj->active != 0) {
    if (*(char *)(*(int *)&obj->field_0x4c + 0x58) != '\0') {
      obj->sub2 = 5;
    }
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801de4fc FUN_801de4fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de4fc(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  FUN_80104c34();
  FUN_801deaec(obj);
  bVar1 = obj->field_0x51 + 1;
  obj->field_0x51 = bVar1;
  if (0x47 < bVar1) {
    obj->field_0x51 = 0;
  }
  iVar3 = (int)obj->x - (int)*(short *)&obj->field_0x54;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (0xf < iVar3) {
    sVar2 = 0x10;
    if ((obj->field_0x52 & 2) == 0) {
                    /* Possible PsyQ macro: setPolyF3() */
      sVar2 = -0x10;
    }
    sVar2 = *(short *)&obj->field_0x54 + sVar2;
    iVar3 = FUN_801df304(obj,0,0,2);
    if (iVar3 != 0) {
      *(short *)(iVar3 + 0xe) = sVar2;
      *(MM8Obj **)(iVar3 + 0x3c) = obj;
      *(undefined1 *)(iVar3 + 0x39) = obj->field_0x51;
      *(undefined1 *)(iVar3 + 0x3a) = obj->field_0x52;
    }
    *(short *)&obj->field_0x54 = sVar2;
  }
  iVar3 = (int)obj->x;
  if ((iVar3 < DAT_801d2928 + 0x10) || (DAT_801d2928 + 0x130 < iVar3)) {
    obj->sub2 = 5;
  }
  else {
    iVar3 = *(short *)&obj->field_0x56 - iVar3;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (0x3f < iVar3) {
      sVar2 = 0x40;
      if ((obj->field_0x52 & 2) == 0) {
        sVar2 = -0x40;
      }
      obj->x = *(short *)&obj->field_0x56 + sVar2;
      obj->sub2 = 1;
    }
    iVar3 = Enemy_ContactDamage(obj);
    if (iVar3 != 0) {
      FUN_8010544c(obj,0x150);
      FUN_801df124((int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_,1,obj->draw_list);
    }
  }
  return;
}


// ---- 801de690 FUN_801de690

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de690(MM8Obj *obj)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  
  iVar2 = FUN_801df194(obj,0,0,2);
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 0x56) = *(undefined2 *)&obj->field_0x56;
    uVar1 = obj->field_0x52;
    *(MM8Obj **)(iVar2 + 0x4c) = obj;
    *(undefined1 *)(iVar2 + 0x52) = uVar1;
  }
  obj->hitbox = &DAT_801e5900;
  obj->sub2 = 2;
  *(short *)&obj->field_0x54 = obj->y;
  *(short *)&obj->field_0x56 = obj->y;
  if (obj->field_0x58 == '\0') {
    iVar2._0_2_ = obj->y_frac;
    iVar2._2_2_ = obj->y;
    bVar4 = 3;
    if (DAT_8015e24c < iVar2) {
      bVar4 = 1;
    }
    uVar3 = Rand();
    if ((&DAT_801e5988)[uVar3 & 0xf] != '\0') {
      bVar4 = bVar4 ^ 2;
    }
  }
  else {
    uVar3 = Rand();
    bVar4 = (&DAT_801e5978)[uVar3 & 0xf];
    obj->field_0x58 = 0;
  }
  if (bVar4 == 1) {
    iVar2 = 0x30000;
  }
  else {
    if (bVar4 == 0) {
      obj->sub2 = 0;
      obj->hitbox = &DAT_801e58fc;
      *(short *)&obj->field_0x54 = obj->x;
      *(short *)&obj->field_0x56 = obj->x;
      obj->field_0x59 = obj->field_0x59 + '\x01';
      FUN_801de4fc(obj);
      return;
    }
    iVar2 = -0x30000;
    if (bVar4 != 3) {
      obj->field_0x52 = bVar4;
      goto LAB_801de7dc;
    }
  }
  obj->speed_y_up = iVar2;
  obj->speed_x = 0;
  obj->field_0x52 = bVar4;
LAB_801de7dc:
  FUN_801de7fc(obj);
  return;
}


// ---- 801de7fc FUN_801de7fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de7fc(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  FUN_80104c34();
  FUN_801deb20(obj);
  bVar1 = obj->field_0x51 + 1;
  obj->field_0x51 = bVar1;
  if (0x47 < bVar1) {
    obj->field_0x51 = 0;
  }
  iVar3 = (int)obj->y - (int)*(short *)&obj->field_0x54;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (0xf < iVar3) {
    sVar2 = 0x10;
    if ((obj->field_0x52 & 2) == 0) {
      sVar2 = -0x10;
    }
    sVar2 = *(short *)&obj->field_0x54 + sVar2;
    iVar3 = FUN_801df304(obj,0,0,3);
    if (iVar3 != 0) {
      *(short *)(iVar3 + 0x12) = sVar2;
      *(MM8Obj **)(iVar3 + 0x3c) = obj;
      *(undefined1 *)(iVar3 + 0x39) = obj->field_0x51;
      *(undefined1 *)(iVar3 + 0x3a) = obj->field_0x52;
    }
    *(short *)&obj->field_0x54 = sVar2;
  }
  iVar3 = (int)*(short *)&obj->field_0x56 - (int)obj->y;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (0x3f < iVar3) {
    sVar2 = 0x40;
    if ((obj->field_0x52 & 2) == 0) {
      sVar2 = -0x40;
    }
    obj->y = *(short *)&obj->field_0x56 + sVar2;
    obj->sub2 = 3;
  }
  iVar3 = Enemy_ContactDamage(obj);
  if (iVar3 != 0) {
    FUN_801df124((int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_,1,obj->draw_list);
  }
  return;
}


// ---- 801de958 FUN_801de958

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de958(MM8Obj *obj)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_801df194(obj,0,0,2);
  if (iVar3 != 0) {
    *(undefined2 *)(iVar3 + 0x56) = *(undefined2 *)&obj->field_0x56;
                    /* Possible PsyQ macro: setLineF2() */
    uVar1 = obj->field_0x52;
    *(MM8Obj **)(iVar3 + 0x4c) = obj;
    *(undefined1 *)(iVar3 + 0x52) = uVar1;
  }
  obj->hitbox = &DAT_801e58fc;
  *(short *)&obj->field_0x54 = obj->x;
  *(short *)&obj->field_0x56 = obj->x;
  if ((obj->flip & 0x40) == 0) {
    obj->speed_x = -0x30000;
    obj->field_0x52 = 0;
  }
  else {
    obj->speed_x = 0x30000;
    obj->field_0x52 = 2;
  }
  obj->speed_y_up = 0;
  cVar2 = obj->field_0x59 + '\x01';
  obj->field_0x59 = cVar2;
  if (cVar2 == '\x03') {
    obj->sub2 = 5;
  }
  else {
    obj->sub2 = 0;
    FUN_801de4fc(obj);
  }
  return;
}


// ---- 801dea2c FUN_801dea2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dea2c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 5;
  }
  else {
    iVar2 = Enemy_ContactDamage(obj);
    if (iVar2 != 0) {
      FUN_801df124((int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_,1,obj->draw_list);
    }
  }
  return;
}


// ---- 801deaa0 FUN_801deaa0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deaa0(MM8Obj *obj)

{
  FUN_801df124((int)obj->x,(int)obj->y,0x1b,obj->draw_list);
  *(undefined1 *)(*(int *)&obj->field_0x4c + 0x52) = 1;
  Obj_Free();
  return;
}


// ---- 801deaec FUN_801deaec

void FUN_801deaec(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = (int)*(short *)(param_1 + 0x56) - (int)*(short *)(param_1 + 0xe);
  if ((int)uVar2 < 0) {
    uVar2 = -uVar2;
  }
  uVar1 = (undefined1)(uVar2 >> 1);
  **(undefined1 **)(param_1 + 0x3c) = uVar1;
  *(undefined1 *)(*(int *)(param_1 + 0x3c) + 2) = uVar1;
  return;
}


// ---- 801deb20 FUN_801deb20

void FUN_801deb20(int param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  
                    /* Possible PsyQ macro: setPolyGT3() */
  iVar1 = (int)(((uint)*(ushort *)(param_1 + 0x56) - (uint)*(ushort *)(param_1 + 0x12)) * 0x10000)
          >> 0x11;
  cVar2 = (char)iVar1;
  cVar3 = cVar2;
  if (iVar1 < 0) {
    cVar3 = -cVar2;
  }
  *(char *)(*(int *)(param_1 + 0x3c) + 1) = cVar3;
  *(char *)(*(int *)(param_1 + 0x3c) + 3) = cVar2;
  return;
}


// ---- 801deb54 FUN_801deb54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deb54(MM8Obj *obj)

{
  int iVar1;
  char *pcVar2;
  
  Anim_Step();
  if ((obj->field_0x52 & 1) == 0) {
    FUN_801deaec(obj);
  }
  else {
    FUN_801deb20(obj);
  }
  pcVar2 = *(char **)&obj->field_0x4c;
  if (((*pcVar2 == '\0') || ((*(uint *)(pcVar2 + 4) & 0xffff0000) != 0x13b0000)) ||
     (pcVar2[2] == '\x05')) {
    FUN_801df124((int)obj->x,(int)obj->y,1,obj->draw_list);
    Obj_Free(obj);
  }
  else {
    iVar1 = Enemy_ContactDamage(obj);
    if (iVar1 != 0) {
      FUN_8010544c(obj,0x150);
      FUN_801df124((int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_,1,obj->draw_list);
    }
    Obj_CullAndQueueDraw(obj);
  }
                    /* Probable PsyQ macro: setTile16() */
  return;
}


// ---- 801dec48 FUN_801dec48

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dec48(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e59f0)[obj->sub2])();
  if ((obj->sub2 != 0) && (obj->active != 0)) {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801decc0 FUN_801decc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801decc0(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_8010544c(obj,0x14a);
    obj->sub2 = 1;
  }
  FUN_801def84(obj);
  return;
}


// ---- 801ded18 FUN_801ded18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ded18(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  short sVar5;
  
  FUN_80104c34();
  FUN_801deb20(obj);
                    /* Possible PsyQ macro: setPolyF4() */
  bVar2 = obj->field_0x51 + 1;
  obj->field_0x51 = bVar2;
  if (0x17 < bVar2) {
    obj->field_0x51 = 0;
  }
                    /* Probable PsyQ macro: setTile() */
  if (0xf < (*(short *)&obj->field_0x54 + 8) - (int)obj->y) {
    sVar5 = *(short *)&obj->field_0x54 + -0x10;
    uVar4 = 9;
    if (obj->var == 3) {
      uVar4 = 5;
    }
    iVar3 = FUN_801df304(obj,0,0,uVar4);
    if (iVar3 != 0) {
      *(short *)(iVar3 + 0x12) = sVar5;
      *(MM8Obj **)(iVar3 + 0x3c) = obj;
      *(undefined1 *)(iVar3 + 0x39) = obj->field_0x51;
      cVar1 = obj->field_0x5a;
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x5a = cVar1 + '\x01';
      *(char *)(iVar3 + 0x3b) = cVar1;
    }
    *(short *)&obj->field_0x54 = sVar5;
  }
  sVar5 = 0xfa;
  if (obj->var == 3) {
    sVar5 = 0xa0;
  }
  if ((int)sVar5 < (int)*(short *)&obj->field_0x56 - (int)obj->y) {
    obj->y = *(short *)&obj->field_0x56 - sVar5;
    obj->sub2 = 2;
    obj->sub3 = 0;
    FUN_801deb20(obj);
  }
  Enemy_CheckWeaponHits(obj);
  Enemy_ContactDamage(obj);
  FUN_801def84(obj);
  return;
}


// ---- 801dee5c FUN_801dee5c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dee5c(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  if (*(char *)(*(int *)&obj->field_0x4c + 0x52) == '\0') {
    Enemy_CheckWeaponHits(obj);
    Enemy_ContactDamage(obj);
    FUN_801def84(obj);
  }
  else {
    obj->sub2 = 3;
  }
  return;
}


// ---- 801deeb8 FUN_801deeb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801deeb8(MM8Obj *obj)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_801df24c(obj,0,0,0);
  uVar4 = 0;
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x5f) = 6;
  }
  do {
    uVar2 = Rand();
    uVar3 = Rand();
    iVar1 = FUN_801df24c(obj,(int)(((uVar2 & 0x3f) - 0x20) * 0x1000000) >> 0x18,
                         (int)(((uVar3 & 0xf) - 7) * 0x1000000) >> 0x18,0);
    uVar4 = uVar4 + 1;
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0x5f) = 6;
    }
  } while (uVar4 < 2);
  FUN_8010544c(obj,0x152);
  Obj_Free(obj);
  return;
}


// ---- 801def84 FUN_801def84

void FUN_801def84(int param_1)

{
  if ((**(char **)(param_1 + 0x4c) == '\0') || ((*(char **)(param_1 + 0x4c))[0x58] != '\0')) {
    *(undefined1 *)(param_1 + 2) = 3;
  }
  return;
}


// ---- 801defb8 FUN_801defb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801defb8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5a00)[obj->sub2])();
  if ((obj->sub2 != 0) && (obj->active != 0)) {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801df124 FUN_801df124

int FUN_801df124(short param_1,short param_2,undefined1 param_3,undefined1 param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_801091a4((int)param_1,(int)param_2,0x80);
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 0x27) = 0x6d;
    uVar1 = DAT_80159fd1;
    *(undefined1 *)(iVar2 + 0x38) = param_3;
    *(undefined1 *)(iVar2 + 0x26) = param_4;
    *(undefined1 *)(iVar2 + 0x24) = uVar1;
  }
  return iVar2;
}


// ---- 801df194 FUN_801df194

undefined1 * FUN_801df194(int param_1,char param_2,char param_3,undefined1 param_4)

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


// ---- 801df24c FUN_801df24c

undefined1 * FUN_801df24c(int param_1,char param_2,char param_3,undefined1 param_4)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocMain();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x3b;
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


// ---- 801df304 FUN_801df304

undefined1 * FUN_801df304(int param_1,char param_2,char param_3,undefined1 param_4)

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


