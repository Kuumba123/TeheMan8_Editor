// T4_0F, STAGE01.BIN, handler 0x801E5EE4. Ghidra output with the object struct applied; not matching C.
// ---- 801e5ee4 FUN_801e5ee4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5ee4(MM8Obj *obj)

{
  if (obj->state == 0) {
    FUN_801e5f84();
  }
  else {
    FUN_801e6014(obj);
  }
  if ((*(short *)(&DAT_801e7016 + (uint)obj->var * 0xc) <= DAT_801d2918._2_2_) || (g_player == '\0')
     ) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e5f84 FUN_801e5f84

void FUN_801e5f84(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80105ea4(param_1,0xf);
  if (iVar1 == 0) {
    if (*(short *)(&DAT_801e7014 + (uint)*(byte *)(param_1 + 7) * 0xc) <= DAT_8015e248._2_2_) {
      *(undefined1 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 0x15) = 1;
      *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
    }
  }
  else {
    Obj_FreeDespawn(param_1);
  }
  return;
}


// ---- 801e6014 FUN_801e6014

void FUN_801e6014(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  iVar6 = (int)DAT_8015e248._2_2_;
  iVar3 = (uint)*(byte *)(param_1 + 7) * 0xc;
  iVar4 = (int)DAT_8015e24c._2_2_;
  iVar11 = iVar6 + -0x10;
  iVar12 = iVar4 + -0x10;
  if (iVar11 < *(short *)(&DAT_801e7018 + iVar3)) {
    puVar9 = &DAT_801e7050;
  }
  else {
    puVar9 = &UNK_801e702c;
    if (*(short *)(&DAT_801e701a + iVar3) <= iVar11) {
      puVar9 = &UNK_801e7074;
    }
  }
  uVar10 = 0;
  if (iVar12 < *(short *)(&DAT_801e701c + iVar3)) {
    puVar9 = puVar9 + 0x12;
  }
  do {
    uVar8 = 0;
    iVar7 = iVar11;
    do {
      uVar1 = *puVar9;
      puVar9 = puVar9 + 2;
      sVar5 = (short)iVar7;
      iVar7 = iVar7 + 0x10;
      uVar8 = uVar8 + 1;
      FUN_801e6304((int)sVar5,(int)(short)iVar12,uVar1);
    } while (uVar8 < 3);
    uVar10 = uVar10 + 1;
    iVar12 = iVar12 + 0x10;
  } while (uVar10 < 3);
  *(char *)(param_1 + 0x14) = *(char *)(param_1 + 0x14) - (*(char *)(param_1 + 0x14) != '\0');
  cVar2 = FUN_80107204((iVar6 + 0x10) * 0x10000 >> 0x10,(iVar4 + -0x20) * 0x10000 >> 0x10);
  if (cVar2 == '\x01') {
    cVar2 = *(char *)(param_1 + 0x15) + -1;
    *(char *)(param_1 + 0x15) = cVar2;
    if (cVar2 == '\0') {
      uVar10 = 0;
      DAT_801e7101 = 0x40;
      DAT_801e70ea = DAT_8015e248._2_2_ + 8;
      DAT_801e70ee = DAT_8015e24c._2_2_ + -8;
      do {
        FUN_8012ae08(&DAT_801e70dc,4);
        uVar10 = uVar10 + 1;
        DAT_801e70ee = DAT_801e70ee + 0x10;
      } while (uVar10 < 4);
      *(undefined1 *)(param_1 + 0x15) = 6;
    }
    if (*(char *)(param_1 + 0x14) == '\0') {
      FUN_800fd100(0x78);
      *(undefined1 *)(param_1 + 0x14) = 0x14;
    }
  }
  if ((*(char *)(param_1 + 3) == '\0') && (*(short *)(&DAT_801e701e + iVar3) <= DAT_8015e248._2_2_))
  {
    *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + '\x01';
    FUN_80105bec();
  }
  return;
}


// ---- 801e6294 FUN_801e6294

undefined * FUN_801e6294(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (param_1 << 0x10) >> 0x14;
  uVar4 = (param_2 << 0x10) >> 0x14;
  uVar3 = uVar2;
  if ((int)uVar2 < 0) {
    uVar3 = uVar2 + 0xf;
  }
  uVar1 = uVar4;
  if ((int)uVar4 < 0) {
    uVar1 = uVar4 + 0xf;
  }
  return &DAT_80171c3c +
         (uint)(byte)(&DAT_8016ef34)[((int)uVar1 >> 4) * 0x20 + ((int)uVar3 >> 4)] * 0x200 +
         ((uVar4 & 0xf) * 0x10 + (uVar2 & 0xf)) * 2;
}


// ---- 801e6304 FUN_801e6304

void FUN_801e6304(uint param_1,short param_2,byte param_3)

{
  char cVar1;
  ushort *puVar2;
  ushort uVar3;
  uint uVar4;
  
  cVar1 = FUN_80107204((int)(short)param_1,(int)param_2);
  puVar2 = (ushort *)FUN_801e6294((int)(short)param_1,(int)param_2);
  uVar4 = (uint)(byte)*puVar2;
  if (cVar1 == '\x01') {
    uVar4 = 0xf;
  }
  else {
    if (uVar4 == 0) {
      return;
    }
    if (0x22 < (int)(uVar4 - 1)) {
      return;
    }
    uVar4 = (uint)(byte)(&DAT_801e7098)[uVar4];
  }
  uVar3 = *(ushort *)(&DAT_801e70ac + (uVar4 & (byte)(&DAT_801e7098)[param_3]) * 2);
  if ((uVar3 == 5) || (uVar3 == 7)) {
    if ((byte)(param_3 - 0xb) < 2) {
      uVar3 = (ushort)param_3;
    }
    else {
      uVar3 = uVar3 + ((ushort)(param_1 >> 4) & 1);
    }
  }
  *puVar2 = uVar3 | 0x1000;
  return;
}


