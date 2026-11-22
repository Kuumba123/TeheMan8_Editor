// ID 3B, STAGE0D.BIN, handler 0x801E5928. Ghidra output with the object struct applied; not matching C.
// ---- 801e5928 FUN_801e5928

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5928(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f88b4)[obj->state])();
  return;
}


// ---- 801e5964 FUN_801e5964

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5964(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  iVar1 = (uint)obj->var * 8;
  obj->dmg_table = (&DAT_801f883c)[iVar1];
  obj->contact_dmg = (&DAT_801f883d)[iVar1];
  obj->hp = (&DAT_801f883e)[iVar1];
  obj->draw_list = (&DAT_801f883f)[iVar1];
  obj->hitbox = &UNK_801f8814 + (uint)(byte)(&DAT_801f8842)[iVar1] * 4;
  obj->box2 = &UNK_801f882c + (uint)(byte)(&DAT_801f8843)[iVar1] * 5;
  Anim_Set(obj,(&DAT_801f8840)[iVar1]);
  if ((byte)(&DAT_801f8841)[iVar1] != 0) {
    (*(code *)(&PTR_caseD_10_801f88c8)[(byte)(&DAT_801f8841)[iVar1]])(obj);
  }
  obj->state = (&DAT_801f8841)[iVar1];
  return;
}


// ---- 801e5a50 FUN_801e5a50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5a50(MM8Obj *obj)

{
  short sVar1;
  
  obj->speed_x = (int)*(short *)(&DAT_801f8874 + (uint)(byte)obj->field_0x5f * 4) << 8;
  sVar1 = *(short *)(&DAT_801f8876 + (uint)(byte)obj->field_0x5f * 4);
  obj->gravity = 0x4000;
  obj->speed_y_up = (int)sVar1 << 8;
  if ((obj->flip & 0x40) == 0) {
    obj->speed_x = -obj->speed_x;
  }
  FUN_8010544c(obj,0x14e);
  obj->field_0x51 = 0;
  return;
}


// ---- 801e5ae0 FUN_801e5ae0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5ae0(MM8Obj *obj)

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
  iVar1 = FUN_801e6fac(obj,0,0,1);
  if (iVar1 != 0) {
    *(MM8Obj **)(iVar1 + 0x3c) = obj;
    *(undefined1 *)(iVar1 + 0x3a) = obj->field_0x52;
  }
  return;
}


// ---- 801e5b84 FUN_801e5b84

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5b84(MM8Obj *obj)

{
  obj->hitbox = &DAT_801f8818 + ((byte)obj->field_0x52 & 1) * 4;
  FUN_8010544c(obj,0x14e);
  return;
}


// ---- 801e5bc0 FUN_801e5bc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5bc0(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = FUN_801e6fac(obj,(iVar3 * 0x10 + -0x20) * 0x1000000 >> 0x18,
                         (int)(char)(&DAT_801f88e0)[(char)iVar3],7);
    if (iVar2 != 0) {
      *(MM8Obj **)(iVar2 + 0x3c) = obj;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 * 0x1000000 >> 0x18 < 5);
  sVar1 = obj->y;
  obj->y = sVar1 + 0x10;
  *(short *)&obj->field_0x54 = sVar1 + 8;
  *(short *)&obj->field_0x56 = obj->y;
  iVar3 = FUN_801e6fac(obj,0,8,5);
  if (iVar3 != 0) {
    *(MM8Obj **)(iVar3 + 0x3c) = obj;
    *(undefined1 *)(iVar3 + 0x39) = 0;
  }
  obj->speed_y_up = 0x80000;
  obj->speed_x = 0;
  obj->field_0x51 = 0;
  obj->field_0x50 = 0x2d;
  return;
}


// ---- 801e5c9c FUN_801e5c9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5c9c(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  iVar6 = 0;
  do {
    iVar4 = FUN_801e6fac(obj,(iVar6 * 0x10 + -0x20) * 0x1000000 >> 0x18,
                         (int)(char)(&DAT_801f88e0)[(char)iVar6],0xe);
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
  iVar6 = FUN_801e6fac(obj,0,8,9);
  if (iVar6 != 0) {
    *(MM8Obj **)(iVar6 + 0x3c) = obj;
    *(undefined1 *)(iVar6 + 0x39) = 0;
    cVar2 = obj->field_0x5a;
    obj->field_0x5a = cVar2 + '\x01';
    *(char *)(iVar6 + 0x3b) = cVar2;
  }
                    /* Possible PsyQ macro: setPolyFT4() + setSemiTrans(polyFT4, 1) +
                       setShadeTex(polyFT4, 1) */
  return;
}


// ---- 801e5df8 FUN_801e5df8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5df8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f88e8)[obj->sub2])();
  return;
}


// ---- 801e5e34 FUN_801e5e34

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5e34(MM8Obj *obj)

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
      FUN_801e6104();
      return;
                    /* Probable PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
    }
    iVar1 = Enemy_ContactDamage(obj);
                    /* Possible PsyQ macro: setTile8() */
    if (iVar1 == 0) {
      iVar1 = Obj_InActiveArea(obj);
      if (iVar1 != 0) {
        return;
      }
      Obj_Free(obj);
      return;
    }
  }
  FUN_801e6104(obj);
  return;
}


// ---- 801e5f08 FUN_801e5f08

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5f08(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  
                    /* Possible PsyQ macro: setLineF2() */
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
      FUN_801e6dcc((int)obj->x,(int)(((ushort)obj->y + 0x28) * 0x10000) >> 0x10,3,obj->draw_list);
      obj->field_0x50 = 6;
      obj->sub3 = 2;
      return;
    }
    if (bVar5 < 2) {
      if (bVar5 != 0) {
        return;
      }
      FUN_801e6dcc((int)obj->x,(int)obj->y,2,obj->draw_list);
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
    FUN_801e6dcc((int)(((ushort)obj->x + 0xc) * 0x10000) >> 0x10,
                 (int)(((ushort)obj->y + 0x28) * 0x10000) >> 0x10,3,obj->draw_list - 1);
    uVar4 = 4;
    iVar2 = (int)(((ushort)obj->x - 0xc) * 0x10000) >> 0x10;
    iVar3 = (int)(((ushort)obj->y + 0x28) * 0x10000) >> 0x10;
    bVar5 = obj->draw_list + 1;
  }
  FUN_801e6dcc(iVar2,iVar3,uVar4,bVar5);
  Obj_Free(obj);
  return;
}


// ---- 801e608c FUN_801e608c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e608c(MM8Obj *obj)

{
  if (obj->field_0x51 == '\0') {
    FUN_801e6dcc((int)obj->x,(int)obj->y,0x1b,obj->draw_list);
  }
  else {
    FUN_801e6dcc((int)obj->x,(int)obj->y,0x1c,obj->draw_list);
    FUN_8010544c(obj,0x159);
  }
  Obj_Free(obj);
  return;
}


// ---- 801e6104 FUN_801e6104

void FUN_801e6104(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = 2;
  if (*(char *)(param_1 + 7) == '\0') {
    uVar1 = 1;
  }
  *(undefined1 *)(param_1 + 2) = uVar1;
  return;
}


// ---- 801e6120 FUN_801e6120

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6120(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f88f4)[obj->sub2])();
  if (obj->active != 0) {
    if (*(char *)(*(int *)&obj->field_0x4c + 0x58) != '\0') {
      obj->sub2 = 5;
    }
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e61a4 FUN_801e61a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e61a4(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  FUN_80104c34();
  FUN_801e6794(obj);
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
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
      sVar2 = -0x10;
    }
    sVar2 = *(short *)&obj->field_0x54 + sVar2;
    iVar3 = FUN_801e6fac(obj,0,0,2);
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
      FUN_801e6dcc((int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_,1,obj->draw_list);
    }
  }
  return;
}


// ---- 801e6338 FUN_801e6338

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6338(MM8Obj *obj)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  
  iVar2 = FUN_801e6e3c(obj,0,0,2);
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 0x56) = *(undefined2 *)&obj->field_0x56;
    uVar1 = obj->field_0x52;
    *(MM8Obj **)(iVar2 + 0x4c) = obj;
    *(undefined1 *)(iVar2 + 0x52) = uVar1;
  }
  obj->hitbox = &DAT_801f881c;
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
    if ((&DAT_801f88a4)[uVar3 & 0xf] != '\0') {
      bVar4 = bVar4 ^ 2;
    }
  }
  else {
    uVar3 = Rand();
    bVar4 = (&DAT_801f8894)[uVar3 & 0xf];
    obj->field_0x58 = 0;
  }
  if (bVar4 == 1) {
    iVar2 = 0x30000;
  }
  else {
    if (bVar4 == 0) {
      obj->sub2 = 0;
      obj->hitbox = &DAT_801f8818;
      *(short *)&obj->field_0x54 = obj->x;
      *(short *)&obj->field_0x56 = obj->x;
      obj->field_0x59 = obj->field_0x59 + '\x01';
      FUN_801e61a4(obj);
      return;
    }
    iVar2 = -0x30000;
    if (bVar4 != 3) {
      obj->field_0x52 = bVar4;
      goto LAB_801e6484;
    }
  }
  obj->speed_y_up = iVar2;
  obj->speed_x = 0;
  obj->field_0x52 = bVar4;
LAB_801e6484:
  FUN_801e64a4(obj);
  return;
}


// ---- 801e64a4 FUN_801e64a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e64a4(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  FUN_80104c34();
  FUN_801e67c8(obj);
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
                    /* Possible PsyQ macro: setPolyG4() */
      sVar2 = -0x10;
    }
    sVar2 = *(short *)&obj->field_0x54 + sVar2;
    iVar3 = FUN_801e6fac(obj,0,0,3);
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
                    /* Possible PsyQ macro: setPolyF4() */
    sVar2 = 0x40;
    if ((obj->field_0x52 & 2) == 0) {
      sVar2 = -0x40;
    }
    obj->y = *(short *)&obj->field_0x56 + sVar2;
    obj->sub2 = 3;
  }
  iVar3 = Enemy_ContactDamage(obj);
  if (iVar3 != 0) {
    FUN_801e6dcc((int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_,1,obj->draw_list);
  }
  return;
}


// ---- 801e6600 FUN_801e6600

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6600(MM8Obj *obj)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_801e6e3c(obj,0,0,2);
  if (iVar3 != 0) {
    *(undefined2 *)(iVar3 + 0x56) = *(undefined2 *)&obj->field_0x56;
    uVar1 = obj->field_0x52;
    *(MM8Obj **)(iVar3 + 0x4c) = obj;
    *(undefined1 *)(iVar3 + 0x52) = uVar1;
  }
  obj->hitbox = &DAT_801f8818;
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
                    /* Possible PsyQ macro: setPolyFT3() */
  obj->speed_y_up = 0;
  cVar2 = obj->field_0x59 + '\x01';
  obj->field_0x59 = cVar2;
  if (cVar2 == '\x03') {
    obj->sub2 = 5;
  }
  else {
    obj->sub2 = 0;
    FUN_801e61a4(obj);
  }
  return;
}


// ---- 801e66d4 FUN_801e66d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e66d4(MM8Obj *obj)

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
      FUN_801e6dcc((int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_,1,obj->draw_list);
    }
  }
  return;
}


// ---- 801e6748 FUN_801e6748

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6748(MM8Obj *obj)

{
  FUN_801e6dcc((int)obj->x,(int)obj->y,0x1b,obj->draw_list);
  *(undefined1 *)(*(int *)&obj->field_0x4c + 0x52) = 1;
  Obj_Free();
  return;
}


// ---- 801e6794 FUN_801e6794

void FUN_801e6794(int param_1)

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


// ---- 801e67c8 FUN_801e67c8

void FUN_801e67c8(int param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  
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


// ---- 801e67fc FUN_801e67fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e67fc(MM8Obj *obj)

{
  int iVar1;
  char *pcVar2;
  
  Anim_Step();
  if ((obj->field_0x52 & 1) == 0) {
    FUN_801e6794(obj);
  }
  else {
    FUN_801e67c8(obj);
  }
  pcVar2 = *(char **)&obj->field_0x4c;
  if (((*pcVar2 == '\0') || ((*(uint *)(pcVar2 + 4) & 0xffff0000) != 0x13b0000)) ||
     (pcVar2[2] == '\x05')) {
    FUN_801e6dcc((int)obj->x,(int)obj->y,1,obj->draw_list);
    Obj_Free(obj);
  }
  else {
    iVar1 = Enemy_ContactDamage(obj);
    if (iVar1 != 0) {
      FUN_8010544c(obj,0x150);
      FUN_801e6dcc((int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_,1,obj->draw_list);
    }
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e68f0 FUN_801e68f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e68f0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f890c)[obj->sub2])();
  if ((obj->sub2 != 0) && (obj->active != 0)) {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e6968 FUN_801e6968

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6968(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_8010544c(obj,0x14a);
    obj->sub2 = 1;
  }
  FUN_801e6c2c(obj);
  return;
}


// ---- 801e69c0 FUN_801e69c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e69c0(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  short sVar5;
  
  FUN_80104c34();
  FUN_801e67c8(obj);
  bVar2 = obj->field_0x51 + 1;
  obj->field_0x51 = bVar2;
  if (0x17 < bVar2) {
    obj->field_0x51 = 0;
  }
                    /* Possible PsyQ macro: setPolyF3() */
                    /* Possible PsyQ macro: setLineF2() */
  if (0xf < (*(short *)&obj->field_0x54 + 8) - (int)obj->y) {
    sVar5 = *(short *)&obj->field_0x54 + -0x10;
    uVar4 = 9;
    if (obj->var == 3) {
      uVar4 = 5;
    }
    iVar3 = FUN_801e6fac(obj,0,0,uVar4);
    if (iVar3 != 0) {
      *(short *)(iVar3 + 0x12) = sVar5;
      *(MM8Obj **)(iVar3 + 0x3c) = obj;
      *(undefined1 *)(iVar3 + 0x39) = obj->field_0x51;
      cVar1 = obj->field_0x5a;
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
    FUN_801e67c8(obj);
  }
  Enemy_CheckWeaponHits(obj);
  Enemy_ContactDamage(obj);
  FUN_801e6c2c(obj);
  return;
}


// ---- 801e6b04 FUN_801e6b04

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6b04(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyF4() */
  if (*(char *)(*(int *)&obj->field_0x4c + 0x52) == '\0') {
    Enemy_CheckWeaponHits(obj);
    Enemy_ContactDamage(obj);
    FUN_801e6c2c(obj);
  }
  else {
    obj->sub2 = 3;
  }
  return;
}


// ---- 801e6b60 FUN_801e6b60

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6b60(MM8Obj *obj)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_801e6ef4(obj,0,0,0);
  uVar4 = 0;
  if (iVar1 != 0) {
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
    *(undefined1 *)(iVar1 + 0x5f) = 6;
  }
  do {
    uVar2 = Rand();
    uVar3 = Rand();
    iVar1 = FUN_801e6ef4(obj,(int)(((uVar2 & 0x3f) - 0x20) * 0x1000000) >> 0x18,
                         (int)(((uVar3 & 0xf) - 7) * 0x1000000) >> 0x18,0);
    uVar4 = uVar4 + 1;
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0x5f) = 6;
    }
  } while (uVar4 < 2);
  FUN_8010544c(obj,0x152);
  Obj_Free(obj);
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801e6c2c FUN_801e6c2c

void FUN_801e6c2c(int param_1)

{
  if ((**(char **)(param_1 + 0x4c) == '\0') || ((*(char **)(param_1 + 0x4c))[0x58] != '\0')) {
    *(undefined1 *)(param_1 + 2) = 3;
  }
  return;
}


// ---- 801e6c60 caseD_10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801e6638::caseD_10(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f891c)[obj->sub2])();
  if ((obj->sub2 != 0) && (obj->active != 0)) {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e6dcc FUN_801e6dcc

int FUN_801e6dcc(short param_1,short param_2,undefined1 param_3,undefined1 param_4)

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


// ---- 801e6e3c FUN_801e6e3c

undefined1 * FUN_801e6e3c(int param_1,char param_2,char param_3,undefined1 param_4)

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


// ---- 801e6ef4 FUN_801e6ef4

undefined1 * FUN_801e6ef4(int param_1,char param_2,char param_3,undefined1 param_4)

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


// ---- 801e6fac FUN_801e6fac

undefined1 * FUN_801e6fac(int param_1,char param_2,char param_3,undefined1 param_4)

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


