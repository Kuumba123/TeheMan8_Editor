// T4_06, STAGE00.BIN, handler 0x801E09F8. Ghidra output with the object struct applied; not matching C.
// ---- 801e09f8 FUN_801e09f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e09f8(MM8Obj *obj)

{
  if (obj->state == 0) {
    FUN_801e0a38();
  }
  else {
    FUN_801e0b08();
  }
  return;
}


// ---- 801e0a38 FUN_801e0a38

void FUN_801e0a38(int param_1)

{
  char *pcVar1;
  
  if (0x13ff < DAT_8015e248._2_2_) {
    *(undefined1 *)(param_1 + 1) = 1;
    DAT_801d2928 = 0x1400;
    DAT_801d2926 = 0x1400;
    DAT_8015e282 = 1;
    FUN_801119e0(0x1440,0x40);
    pcVar1 = &g_main_pool;
    DAT_801b2992 = 1;
    DAT_801b2993 = 1;
    do {
      if (*pcVar1 == '\x01') {
        FUN_80108e84(pcVar1);
        Obj_FreeDespawn(pcVar1);
      }
      pcVar1 = pcVar1 + 0x60;
    } while (pcVar1 < &DAT_8015c974);
  }
  return;
}


// ---- 801e0b08 FUN_801e0b08

void FUN_801e0b08(undefined4 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 6;
    *(undefined4 *)(puVar1 + 0xc) = 0x14f00000;
    puVar1[7] = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0x1980000;
    Obj_Free(param_1);
  }
  return;
}


