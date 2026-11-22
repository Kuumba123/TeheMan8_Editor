// T4_0C, STAGE01.BIN, handler 0x801E589C. Ghidra output with the object struct applied; not matching C.
// ---- 801e589c FUN_801e589c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e589c(MM8Obj *obj)

{
  if (obj->state == 0) {
    if (obj->var == 0) {
      FUN_801e5908();
    }
    else {
      if (obj->var != 1) {
        return;
      }
      FUN_801e5950(obj);
    }
    Obj_Free(obj);
  }
  return;
}


// ---- 801e5908 FUN_801e5908

void FUN_801e5908(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = 4;
  do {
    FUN_801e59f4(param_1,iVar1);
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  return;
}


// ---- 801e5950 FUN_801e5950

void FUN_801e5950(undefined1 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = 0x1f;
  puVar2 = &DAT_801cf828;
  iVar1 = 0x2e8;
  do {
    iVar3 = iVar3 + -1;
    if ((((&DAT_801cf540)[iVar1] != '\0') && (*(char *)((int)&DAT_801cf544 + iVar1 + 2) == '\f')) &&
       (puVar2 != param_1)) {
      Obj_Free(puVar2);
    }
    puVar2 = puVar2 + -0x18;
    iVar1 = iVar1 + -0x18;
  } while (-1 < iVar3);
  return;
}


// ---- 801e59f4 FUN_801e59f4

void FUN_801e59f4(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  
  puVar4 = (undefined1 *)Obj_AllocMain();
  if (puVar4 != (undefined1 *)0x0) {
    *puVar4 = 1;
    iVar6 = param_2 * 6;
    puVar4[6] = 0xb;
    puVar4[7] = (byte)((ushort)*(undefined2 *)(&DAT_801e6fbc + iVar6) >> 9) & 0x40;
    *(undefined2 *)(puVar4 + 0xe) = *(undefined2 *)(&DAT_801e6fbe + iVar6);
    uVar2 = *(undefined2 *)(&DAT_801e6fc0 + iVar6);
    puVar4[1] = 0;
    *(undefined2 *)(puVar4 + 0x12) = uVar2;
  }
  puVar5 = (undefined1 *)Obj_AllocMain();
  if (puVar5 != (undefined1 *)0x0) {
    *puVar5 = 1;
    puVar5[6] = 0xe;
    puVar5[7] = (byte)((ushort)*(undefined2 *)(&DAT_801e6fbc + param_2 * 6) >> 8) | 0x10 |
                (byte)param_2;
    sVar3 = *(short *)(&DAT_801e6fbe + param_2 * 6);
    *(short *)(puVar5 + 0xe) = sVar3;
    if ((puVar5[7] & 0x80) == 0) {
      sVar3 = sVar3 + -0x35;
    }
    else {
      sVar3 = sVar3 + 0x35;
    }
    *(short *)(puVar5 + 0xe) = sVar3;
    bVar1 = (&DAT_801e6fbc)[param_2 * 6];
    sVar3 = *(short *)(&DAT_801e6fc0 + param_2 * 6);
    puVar5[1] = 0;
    *(undefined1 **)(puVar5 + 0x4c) = puVar4;
    *(ushort *)(puVar5 + 0x12) = sVar3 + (ushort)bVar1 * -2;
  }
  return;
}


