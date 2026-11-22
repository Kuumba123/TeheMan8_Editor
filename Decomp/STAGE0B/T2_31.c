// T2_31, STAGE0B.BIN, handler 0x801E7574. Ghidra output with the object struct applied; not matching C.
// ---- 801e7574 FUN_801e7574

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7574(MM8Obj *obj)

{
  int iVar1;
  
  obj->hitbox = &UNK_801e8860 + (uint)obj->var * 4;
  iVar1 = FUN_801e75e4();
  if ((iVar1 != 0) || (iVar1 = FUN_801e7684(obj), iVar1 != 0)) {
    FUN_801e787c(obj);
    FUN_801e776c(obj);
    Obj_Free(obj);
  }
  return;
}


// ---- 801e75e4 FUN_801e75e4

undefined4 FUN_801e75e4(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = &g_main_pool;
  while (((*pcVar2 == '\0' || (pcVar2[6] != '\0')) ||
         (iVar1 = Obj_HitboxOverlap(param_1,pcVar2), iVar1 == 0))) {
    pcVar2 = pcVar2 + 0x60;
    if ("" < pcVar2) {
      return 0;
    }
  }
  Obj_Free(pcVar2);
  return 1;
}


// ---- 801e7684 FUN_801e7684

undefined4 FUN_801e7684(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  
  pcVar3 = &DAT_801b12ac;
  pbVar4 = (byte *)((int)&DAT_801b12b0 + 2);
  do {
                    /* Possible PsyQ macro: setLineF2() */
    if ((*pcVar3 != '\0') && (pbVar4[0x40] == 0)) {
      bVar1 = *pbVar4;
      if (bVar1 != 6) {
        if (bVar1 < 7) {
          if (bVar1 != 4) goto LAB_801e7710;
        }
        else if ((0xd < bVar1) || (bVar1 < 0xc)) {
LAB_801e7710:
          iVar2 = Obj_HitboxOverlap(param_1,pcVar3);
          if (iVar2 != 0) {
            FUN_801074f0(param_1,pcVar3,2);
            return 1;
          }
        }
      }
    }
    pcVar3 = pcVar3 + 0x60;
    pbVar4 = pbVar4 + 0x60;
    if ("" < pcVar3) {
      return 0;
    }
  } while( true );
}


// ---- 801e776c FUN_801e776c

void FUN_801e776c(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 6;
  if (*(char *)(param_1 + 7) != '\0') {
    iVar5 = 8;
  }
  uVar4 = 0;
  do {
    uVar3 = 0;
    if (iVar5 != 0) {
      uVar1 = 0;
      do {
        if ((uVar1 != 0) && ((uVar4 & 1) != 0)) {
          iVar2 = FUN_8012c108(param_1,0,(int)(uVar4 << 0x14) >> 0x10,(int)(uVar3 << 0x14) >> 0x10,0
                               ,0);
          if (iVar2 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
            *(undefined1 *)(iVar2 + 0x27) = 0x34;
            *(undefined1 *)(iVar2 + 0x26) = 6;
            *(undefined1 *)(iVar2 + 7) = 0x10;
          }
          FUN_8012a724(param_1,1,uVar4 << 4,uVar3 << 4);
        }
        uVar3 = uVar3 + 1;
        uVar1 = uVar3 & 1;
      } while ((int)uVar3 < iVar5);
    }
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 6);
  FUN_8010544c(param_1,10);
  return;
}


// ---- 801e787c FUN_801e787c

void FUN_801e787c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 7;
  if (*(char *)(param_1 + 7) != '\0') {
    iVar4 = 9;
  }
  iVar3 = 0;
  do {
    iVar2 = -1;
    do {
      iVar1 = iVar2 * 0x10;
      iVar2 = iVar2 + 1;
      FUN_80103134((int)*(short *)(param_1 + 0xe) + iVar3 * 0x10,*(short *)(param_1 + 0x12) + iVar1,
                   0);
    } while (iVar2 < iVar4);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  if (*(char *)(param_1 + 7) == '\x02') {
    FUN_80102ef4(0,(int)*(short *)(param_1 + 0xe),*(short *)(param_1 + 0x12) + 0x80);
  }
  return;
}


