// T2_16, STAGE03.BIN, handler 0x801E8674. Ghidra output with the object struct applied; not matching C.
// ---- 801e8674 FUN_801e8674

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8674(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->state == 0) {
    iVar1 = FUN_80105dbc(obj,0x16);
    if (iVar1 != 0) {
      Obj_Free(obj);
      return;
    }
    obj->state = 1;
    obj->contact_dmg = 1;
  }
  FUN_801e86e0(obj);
  FUN_801e886c(obj);
  return;
}


// ---- 801e86e0 FUN_801e86e0

void FUN_801e86e0(int param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined1 *puVar3;
  short sVar4;
  int iVar5;
  
  bVar1 = 3;
  iVar5 = 0x18;
  do {
    if ((((*(short *)(&UNK_801e9fc8 + iVar5) < DAT_8015e248._2_2_) &&
         (DAT_8015e248._2_2_ < *(short *)(&UNK_801e9fca + iVar5))) &&
        (*(short *)(&UNK_801e9fcc + iVar5) < DAT_8015e24c._2_2_)) &&
       (DAT_8015e24c._2_2_ < *(short *)(&UNK_801e9fce + iVar5))) break;
    bVar1 = bVar1 - 1;
    iVar5 = (uint)bVar1 << 3;
  } while (bVar1 != 0);
  *(byte *)(param_1 + 0x44) = bVar1;
  if ((bVar1 != 0) &&
     (*(char *)(param_1 + 0x45) = *(char *)(param_1 + 0x45) + -1, *(char *)(param_1 + 0x45) == '\0')
     ) {
    *(undefined1 *)(param_1 + 0x45) = 5;
    bVar1 = FUN_80105e30(param_1,0x1c);
    if ((bVar1 < 10) && (puVar3 = (undefined1 *)Obj_AllocType3(), puVar3 != (undefined1 *)0x0)) {
      *puVar3 = 1;
      puVar3[6] = 0x1c;
      bVar1 = Rand();
      puVar3[7] = bVar1 & 1;
      *(short *)(puVar3 + 0xe) = DAT_801d2918._2_2_ + -0x10;
      if (puVar3[7] == '\0') {
        uVar2 = Rand();
        sVar4 = g_cam_y + (uVar2 & 0x3f) + 0x40;
      }
      else {
        uVar2 = Rand();
        sVar4 = g_cam_y + (uVar2 & 0x3f) + 0x70;
      }
      *(short *)(puVar3 + 0x12) = sVar4;
    }
  }
  return;
}


// ---- 801e886c FUN_801e886c

void FUN_801e886c(int param_1)

{
  DAT_8015e248 = DAT_8015e248 +
                 *(int *)(&UNK_801e9fe8 +
                         (uint)(DAT_8015e27f != '\0') * 4 + (uint)*(byte *)(param_1 + 0x44) * 8);
  return;
}


