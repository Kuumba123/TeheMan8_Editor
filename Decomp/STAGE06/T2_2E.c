// T2_2E, STAGE06.BIN, handler 0x801E400C. Ghidra output with the object struct applied; not matching C.
// ---- 801e400c FUN_801e400c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e400c(MM8Obj *obj)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  MM8Obj *pMVar7;
  byte *pbVar8;
  short *psVar9;
  
  psVar9 = (short *)(&DAT_801e5c50 + (uint)obj->var * 8);
  if (obj->var == 2) {
    pMVar7 = (MM8Obj *)&DAT_801b1eec;
    pbVar8 = (byte *)((int)&DAT_801b1ef0 + 3);
    do {
      if ((((pMVar7->active != 0) && (pbVar8[-1] == 0x2e)) && (pMVar7 < obj)) &&
         (*pbVar8 == obj->var)) {
        return;
      }
      pMVar7 = (MM8Obj *)&pMVar7->field_0x50;
      pbVar8 = pbVar8 + 0x50;
    } while (pMVar7 < &DAT_801b28ec);
  }
  if ((int)*psVar9 <= DAT_801d2918._2_2_ + 0x140) {
    iVar6 = 0;
    for (pMVar7 = (MM8Obj *)&DAT_801b1eec; pMVar7 < obj; pMVar7 = (MM8Obj *)&pMVar7->field_0x50) {
                    /* Possible PsyQ macro: setTile16() */
      if ((pMVar7->active != 0) && (pMVar7->id == 0x2e)) {
        iVar6 = iVar6 + 1;
      }
    }
    if (iVar6 == 0) {
      DAT_801b29a1 = '\0';
    }
    if (obj->state == 0) {
      sVar1 = *psVar9;
      obj->state = 1;
      obj->dmg_table = (char)sVar1;
      obj->contact_dmg = (char)((ushort)sVar1 >> 8);
    }
    if ((obj->var == 2) && (DAT_8015e248._2_2_ < *psVar9)) {
      psVar9 = &DAT_801e5c68;
    }
    if ((((g_player != '\0') && (*psVar9 <= DAT_8015e248._2_2_)) && (DAT_8015e248._2_2_ < psVar9[2])
        ) && (((psVar9[1] <= DAT_8015e24c._2_2_ && (DAT_8015e24c._2_2_ < psVar9[3])) &&
              (DAT_801b29a1 == '\0')))) {
      DAT_801b29a1 = '\x01';
      DAT_8015e248 = DAT_8015e248 + -0x10000;
    }
    bVar2 = obj->on_screen + 1;
    obj->on_screen = bVar2;
    if ((((bVar2 & 3) == 3) && (DAT_801d2918._2_2_ + 0x140 <= (int)psVar9[2])) &&
       (puVar4 = (undefined1 *)Obj_AllocType3(), puVar4 != (undefined1 *)0x0)) {
      *puVar4 = 1;
      puVar4[6] = 0x34;
      if (obj->var == 0) {
        puVar4[7] = 0;
      }
      else {
        puVar4[7] = 1;
      }
      iVar6 = (int)psVar9[3] - (int)psVar9[1];
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      *(short *)(puVar4 + 0xe) = DAT_801d2918._2_2_ + 0x140;
      uVar5 = Rand();
      iVar6 = (iVar6 + -0x10) * 0x10000 >> 0x10;
      if (iVar6 == 0) {
        trap(0x1c00);
      }
      if ((iVar6 == -1) && ((uVar5 & 0xffff) == 0x80000000)) {
        trap(0x1800);
      }
      sVar1 = psVar9[1];
      puVar4[1] = 0;
      *(MM8Obj **)(puVar4 + 0x38) = obj;
      *(short *)(puVar4 + 0x12) = sVar1 + (short)((int)(uVar5 & 0xffff) % iVar6);
    }
    cVar3 = Obj_InActiveArea(obj);
    if (cVar3 == '\0') {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


