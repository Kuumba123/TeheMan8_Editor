// T4_13, STAGE03.BIN, handler 0x801E91BC. Ghidra output with the object struct applied; not matching C.
// ---- 801e91bc FUN_801e91bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e91bc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea118)[obj->state])();
  return;
}


// ---- 801e91f8 FUN_801e91f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e91f8(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    obj->sub2 = 1;
    *(undefined **)&obj->y_frac = &UNK_801ea100 + (uint)obj->var * 0xc;
  }
  if (obj->x <= DAT_8015e248._2_2_) {
    obj->state = 1;
    obj->sub2 = 0;
    FUN_801e93b4();
  }
  return;
}


// ---- 801e93b4 FUN_801e93b4

void FUN_801e93b4(int param_1)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  int *piVar4;
  
  piVar4 = (int *)**(undefined4 **)(param_1 + 0x10);
  if (*piVar4 != 0xff) {
    puVar3 = (undefined2 *)((int)piVar4 + 6);
    do {
      puVar2 = (undefined1 *)Obj_AllocMain();
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x13;
        puVar2[7] = (char)*piVar4;
        piVar4 = piVar4 + 2;
        *(undefined2 *)(puVar2 + 0xe) = puVar3[-1];
        uVar1 = *puVar3;
        puVar3 = puVar3 + 4;
        *(undefined2 *)(puVar2 + 0x12) = uVar1;
      }
    } while (*piVar4 != 0xff);
  }
  return;
}


