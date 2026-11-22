// T4_05, STAGE00.BIN, handler 0x801E073C. Ghidra output with the object struct applied; not matching C.
// ---- 801e073c FUN_801e073c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e073c(MM8Obj *obj)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  ushort *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  sVar4 = g_cam_y;
  sVar3 = DAT_801d2918._2_2_;
  if (obj->state == 0) {
    iVar10 = 0;
    uVar5 = obj->y;
    *(short *)((int)&obj->speed_x + 2) = obj->y;
    puVar7 = (ushort *)((int)&obj->speed_x + 2);
                    /* Probable PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
    *(undefined1 *)&obj->speed_x = 0x77;
    if (obj->var == 0) {
      for (; (int)(short)uVar5 < sVar4 + 0x168; uVar5 = uVar5 + 0x78) {
      }
      *puVar7 = uVar5;
      for (; sVar4 + -0x78 < (int)(short)uVar5; uVar5 = uVar5 - 0x78) {
        iVar10 = iVar10 + 1;
      }
    }
    else {
      do {
        uVar6 = uVar5;
        uVar5 = uVar6 - 0x78;
      } while (0x288 < (short)uVar6);
      *puVar7 = uVar6;
      for (; (int)(short)uVar6 < sVar4 + 0x168; uVar6 = uVar6 + 0x78) {
        iVar10 = iVar10 + 1;
      }
    }
    uVar8 = (uint)*puVar7;
    while (bVar1 = iVar10 != 0, iVar10 = iVar10 + -1, bVar1) {
      iVar9 = (int)(short)uVar8;
      FUN_801e0998(obj,iVar9);
      uVar8 = iVar9 + 0x78;
      if (obj->var == 0) {
        uVar8 = iVar9 - 0x78;
      }
    }
                    /* Possible PsyQ macro: setPolyG3() */
    *(undefined1 *)((int)&obj->speed_x + 1) = 0x30;
    obj->state = 1;
  }
  else {
    cVar2 = (char)obj->speed_x;
    *(char *)&obj->speed_x = cVar2 + -1;
    if (cVar2 == '\0') {
      FUN_801e0998(obj,(int)*(short *)((int)&obj->speed_x + 2));
      *(undefined1 *)&obj->speed_x = 0x77;
    }
    if (((obj->var != 0) && (sVar3 + -0x80 < (int)obj->x)) &&
       (cVar2 = *(char *)((int)&obj->speed_x + 1), *(char *)((int)&obj->speed_x + 1) = cVar2 + -1,
       cVar2 == '\0')) {
      FUN_800fd100(0x5e);
                    /* Possible PsyQ macro: setPolyG3() */
      *(undefined1 *)((int)&obj->speed_x + 1) = 0x30;
    }
    if ((sVar3 + 0x178 < (int)obj->x) || (sVar4 < 0x200)) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801e0998 FUN_801e0998

void FUN_801e0998(int param_1,undefined2 param_2)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType2();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 1;
    puVar2[7] = *(undefined1 *)(param_1 + 7);
    uVar1 = *(undefined2 *)(param_1 + 0xe);
    *(undefined2 *)(puVar2 + 0x12) = param_2;
    *(undefined2 *)(puVar2 + 0xe) = uVar1;
  }
  return;
}


