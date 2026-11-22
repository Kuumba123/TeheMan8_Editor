// T4_2E, STAGE02.BIN, handler 0x801E7E14. Ghidra output with the object struct applied; not matching C.
// ---- 801e7e14 FUN_801e7e14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7e14(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8db0)[obj->state])();
  return;
}


// ---- 801e7e50 FUN_801e7e50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7e50(MM8Obj *obj)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_801b29a2 = 0;
  DAT_801b29a3 = 0;
  do {
    puVar1 = (undefined1 *)Obj_AllocType3();
    if (puVar1 != (undefined1 *)0x0) {
      puVar1[7] = (char)iVar2;
      iVar2 = iVar2 + 1;
      *puVar1 = 1;
      puVar1[6] = 0x2f;
      *(undefined4 *)(puVar1 + 0xc) = 0x17a00000;
      *(undefined4 *)(puVar1 + 0x10) = 0x5680000;
      puVar1[1] = 0;
    }
  } while (iVar2 < 2);
  do {
    do {
      puVar1 = (undefined1 *)Obj_AllocMain();
    } while (puVar1 == (undefined1 *)0x0);
    *puVar1 = 1;
    puVar1[6] = 0x45;
    *(undefined4 *)(puVar1 + 0xc) = 0x18000000;
    *(undefined4 *)(puVar1 + 0x10) = 0x5a00000;
    puVar1[7] = 0;
    puVar1[1] = 0;
  } while (puVar1 == (undefined1 *)0x0);
  obj->state = 1;
  obj->sub2 = 0;
  *(undefined1 *)&obj->speed_x = 0x1e;
  FUN_800fcb80(0x2e);
  DAT_8015e2af = 1;
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  return;
}


// ---- 801e7f70 FUN_801e7f70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7f70(MM8Obj *obj)

{
  byte bVar1;
  
  if ((char)obj->speed_x == '\0') {
    DAT_801b29a2 = DAT_801b29a2 + 1;
    bVar1 = obj->sub2;
    if (bVar1 == 1) {
      if (0x5f < DAT_801b29a2) {
        FUN_80102ecc(3);
        obj->sub2 = 2;
      }
    }
    else if (bVar1 < 2) {
      if ((bVar1 == 0) && (0x2f < DAT_801b29a2)) {
        FUN_80102ecc(2);
        obj->sub2 = 1;
      }
    }
    else if (bVar1 == 2) {
      if (0x8f < DAT_801b29a2) {
        FUN_80102ecc(4);
        obj->sub2 = 3;
      }
    }
    else if ((bVar1 == 3) && (0xbe < DAT_801b29a2)) {
      DAT_801b29a2 = 0;
      obj->state = 2;
      obj->sub2 = 0;
    }
  }
  else {
    *(char *)&obj->speed_x = (char)obj->speed_x + -1;
  }
  return;
}


