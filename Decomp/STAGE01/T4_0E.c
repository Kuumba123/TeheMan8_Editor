// T4_0E, STAGE01.BIN, handler 0x801E5B3C. Ghidra output with the object struct applied; not matching C.
// ---- 801e5b3c FUN_801e5b3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5b3c(MM8Obj *obj)

{
  if (obj->state == 0) {
    FUN_801e5b7c();
  }
  else {
    FUN_801e5c7c();
  }
  return;
}


// ---- 801e5b7c FUN_801e5b7c

void FUN_801e5b7c(char *param_1)

{
  byte bVar1;
  char *pcVar2;
  
  pcVar2 = &DAT_801cf540;
  do {
    if (((*pcVar2 != '\0') && (pcVar2[6] == '\x0e')) && (pcVar2 != param_1)) goto LAB_801e5bec;
    pcVar2 = pcVar2 + 0x18;
  } while (pcVar2 < &DAT_801cf840);
  if (param_1[7] == '\x04') {
LAB_801e5bec:
    Obj_Free();
  }
  else {
    bVar1 = Rand(param_1);
    param_1[0x14] = bVar1 & 0x7f;
    if ((param_1[7] & 0x80U) == 0) {
      DAT_801d2948._1_1_ = 1;
      param_1[0x15] = '\0';
    }
    else {
      DAT_801d2948._1_1_ = 0;
      param_1[7] = param_1[7] & 0xf;
      param_1[0x15] = '\x01';
      param_1[0x16] = (1U < (byte)param_1[7]) << 1;
    }
    param_1[1] = '\x01';
  }
  return;
}


// ---- 801e5c7c FUN_801e5c7c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801e5c7c(int param_1)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  short sVar8;
  
  if (*(char *)(param_1 + 0x14) == '\0') {
    uVar4 = Rand();
    sVar8 = _g_cam_y;
    iVar7 = (uint)DAT_801d2918._2_2_ + (uVar4 & 0x1ff);
    sVar2 = (short)iVar7;
    bVar1 = Rand();
    *(byte *)(param_1 + 0x14) = bVar1 & 7;
    if (DAT_801d2915 == '\x01') {
      iVar7 = iVar7 + DAT_801d293a * 0x20;
      sVar2 = (short)iVar7;
      if ((short)DAT_801d2918._2_2_ + 0x150 < iVar7 * 0x10000 >> 0x10) {
        uVar3 = Rand();
        sVar8 = sVar8 + (uVar3 & 0x7f);
      }
    }
    else {
      *(byte *)(param_1 + 0x14) = (bVar1 & 7) + 1;
    }
    iVar7 = (uint)*(byte *)(param_1 + 7) * 8;
    uVar4 = 1;
    if ((((*(short *)(&DAT_801e6fdc + iVar7) < sVar2) && (sVar2 < *(short *)(&DAT_801e6fde + iVar7))
         ) && (*(short *)(&DAT_801e6fe0 + iVar7) < sVar8)) &&
       (sVar8 < *(short *)(&DAT_801e6fe2 + iVar7))) {
      uVar4 = (uint)(byte)(&DAT_801e7004)[*(byte *)(param_1 + 7)];
    }
    iVar5 = uVar4 << 0x18;
    if ((*(char *)(param_1 + 7) == '\x03') &&
       (iVar5 = uVar4 << 0x18, *(short *)(&DAT_801e6fde + iVar7) < sVar2)) {
      iVar5 = -0x1000000;
    }
    if ((iVar5 >> 0x18 != 0) &&
       (puVar6 = (undefined1 *)Obj_AllocType3(), puVar6 != (undefined1 *)0x0)) {
      puVar6[6] = 0x11;
      *puVar6 = 1;
      puVar6[1] = 0;
      puVar6[0x38] = iVar5 >> 0x18 < 1;
      *(short *)(puVar6 + 0xe) = sVar2;
      *(short *)(puVar6 + 0x12) = sVar8;
      if (((*(char *)(param_1 + 7) == '\0') || (*(char *)(param_1 + 7) == '\x02')) &&
         (puVar6[0x38] != '\0')) {
        puVar6[0x39] = 1;
      }
      else {
        puVar6[0x39] = 0;
      }
    }
  }
  else {
    *(char *)(param_1 + 0x14) = *(char *)(param_1 + 0x14) + -1;
  }
  if ((*(char *)(param_1 + 0x15) != '\0') &&
     (iVar7 = (uint)*(byte *)(param_1 + 0x16) * 2, _g_cam_y == *(short *)(&DAT_801e700e + iVar7))) {
    DAT_801d2948._1_1_ = *(short *)(&DAT_801e700c + iVar7) <= (short)DAT_801d2918._2_2_;
  }
  return;
}


