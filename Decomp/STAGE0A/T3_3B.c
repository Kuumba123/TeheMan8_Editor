// T3_3B, STAGE0A.BIN, handler 0x801E15B8. Ghidra output with the object struct applied; not matching C.
// ---- 801e15b8 FUN_801e15b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e15b8(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = FUN_801e1818();
                    /* Possible PsyQ macro: setPolyF4() */
  if (iVar1 == 0) {
    Obj_Free(obj);
  }
  else {
    (*(code *)(&PTR_LAB_801e21b8)[obj->state])(obj);
  }
  return;
}


// ---- 801e1818 FUN_801e1818

byte FUN_801e1818(int param_1)

{
  byte bVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x14);
  bVar1 = 0;
  if (((*pcVar2 != '\0') && (pcVar2[0x55] == *(char *)(param_1 + 0x3a))) &&
     (pcVar2[6] == *(char *)(param_1 + 0x38))) {
    bVar1 = **(byte **)(param_1 + 0x18) & -(pcVar2[7] == *(char *)(param_1 + 0x39));
  }
  return bVar1;
}


