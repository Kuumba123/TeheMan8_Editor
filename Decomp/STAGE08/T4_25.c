// T4_25, STAGE08.BIN, handler 0x801E0A70. Ghidra output with the object struct applied; not matching C.
// ---- 801e0a70 FUN_801e0a70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0a70(MM8Obj *obj)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  MM8Obj *pMVar5;
  uint uVar6;
  undefined1 *puVar7;
  char cVar8;
  int iVar9;
  uint *puVar10;
  
  obj->sub2 = 0;
  iVar4 = FUN_80105ea4(obj,0x25);
  if ((iVar4 != 0) && (iVar9 = 0, 0 < iVar4)) {
    puVar10 = &DAT_801b1040;
    do {
      pMVar5 = (MM8Obj *)*puVar10;
      puVar10 = puVar10 + 1;
      if (pMVar5 < obj) {
        obj->sub2 = 1;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar4);
  }
  if (obj->sub2 == 0) {
    if (obj->state == 0) {
      if (iVar4 == 0) {
        uVar6 = Rand();
                    /* Possible PsyQ macro: setPolyGT4() */
        DAT_801b29a0 = (&DAT_801e1390)[(byte)(&DAT_801e1380)[uVar6 & 0xf]];
      }
      obj->state = 1;
    }
    cVar8 = DAT_801b29a0 + -1;
    bVar1 = DAT_801b29a0 == '\0';
    DAT_801b29a0 = cVar8;
    if (bVar1) {
      uVar6 = FUN_80105d48(obj,0x37);
      if ((uVar6 < 3) && (puVar7 = (undefined1 *)Obj_AllocMain(), puVar7 != (undefined1 *)0x0)) {
        *puVar7 = 1;
        puVar7[6] = 0x37;
        puVar7[7] = 0;
        uVar6 = Rand();
        puVar7[0x25] = ((uVar6 & 1) == 0) << 6;
        sVar3 = DAT_801d2918._2_2_;
        *(short *)(puVar7 + 0xe) = DAT_801d2918._2_2_;
                    /* Possible PsyQ macro: setPolyGT4() */
        if ((puVar7[0x25] & 0x40) == 0) {
          sVar2 = 0x150;
        }
        else {
          sVar2 = -0x10;
        }
        *(short *)(puVar7 + 0xe) = sVar3 + sVar2;
        *(undefined2 *)(puVar7 + 0x12) = g_cam_y;
        uVar6 = Rand();
                    /* Possible PsyQ macro: setTile8() */
        *(ushort *)(puVar7 + 0x12) =
             (ushort)(byte)(&DAT_801e1368)[(byte)(&DAT_801e1370)[uVar6 & 0xf]] +
             *(short *)(puVar7 + 0x12);
      }
      uVar6 = Rand();
      DAT_801b29a0 = (&DAT_801e1390)[(byte)(&DAT_801e1380)[uVar6 & 0xf]];
    }
  }
  cVar8 = Obj_InActiveArea(obj);
  if (cVar8 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


