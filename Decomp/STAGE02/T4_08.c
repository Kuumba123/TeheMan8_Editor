// T4_08, STAGE02.BIN, handler 0x801E64B0. Ghidra output with the object struct applied; not matching C.
// ---- 801e64b0 FUN_801e64b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e64b0(MM8Obj *obj)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined2 *puVar6;
  
  iVar5 = 0;
  if (obj->state == 0) {
    puVar3 = &DAT_801e8ae0;
    puVar6 = &DAT_801e8ae2;
    obj->state = obj->state + 1;
    do {
      puVar2 = (undefined1 *)Obj_AllocType2();
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x15;
        *(undefined2 *)(puVar2 + 0xe) = *puVar3;
        *(undefined2 *)(puVar2 + 0x12) = *puVar6;
        uVar1 = (&DAT_801e8b04)[iVar5 * 2];
        puVar2[0x44] = (char)iVar5;
        puVar2[7] = uVar1;
      }
      puVar6 = puVar6 + 2;
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 2;
    } while (iVar5 < 9);
  }
  else if (0x13ff < DAT_8015e248._2_2_) {
    pcVar4 = &DAT_801b1eec;
    do {
      if ((*pcVar4 != '\0') && (pcVar4[6] == '\x15')) {
        Obj_Free(pcVar4);
      }
      pcVar4 = pcVar4 + 0x50;
    } while (pcVar4 < &DAT_801b28ec);
    pcVar4 = &g_main_pool;
    do {
      if ((*pcVar4 != '\0') && (pcVar4[6] == '\x0f')) {
        Obj_Free(pcVar4);
      }
      pcVar4 = pcVar4 + 0x60;
    } while (pcVar4 < &DAT_8015c974);
    Obj_Free(obj);
  }
  return;
}


