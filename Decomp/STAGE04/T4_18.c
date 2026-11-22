// T4_18, STAGE04.BIN, handler 0x801E688C. Ghidra output with the object struct applied; not matching C.
// ---- 801e688c FUN_801e688c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e688c(MM8Obj *obj)

{
  char cVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  MM8Obj *pMVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  
  if (obj->state == 0) {
    pMVar4 = (MM8Obj *)&DAT_801cf540;
    pbVar5 = (byte *)((int)&DAT_801cf544 + 3);
    do {
      if ((((pMVar4->active != 0) && (pbVar5[-1] == 0x18)) && (pMVar4 != obj)) &&
         (*pbVar5 == obj->var)) {
        Obj_Free(obj);
        return;
      }
      pMVar4 = (MM8Obj *)&pMVar4->speed_y_up;
      pbVar5 = pbVar5 + 0x18;
    } while (pMVar4 < &DAT_801cf840);
    iVar7 = 0;
    while (iVar6 = iVar7 * 4, *(short *)((&PTR_DAT_801e7560)[obj->var] + iVar6) != 0) {
      puVar3 = (undefined1 *)Obj_AllocMain();
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        cVar1 = (&DAT_801e756c)[obj->var];
        puVar3[6] = 0x24;
        *(undefined4 *)(puVar3 + 0xc) = 0;
        *(undefined4 *)(puVar3 + 0x10) = 0;
        puVar3[7] = (char)iVar7 + cVar1;
        *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)((&PTR_DAT_801e7560)[obj->var] + iVar6);
        uVar2 = *(undefined2 *)((&PTR_DAT_801e7560)[obj->var] + iVar6 + 2);
        iVar7 = iVar7 + 1;
        puVar3[1] = 0;
        *(undefined2 *)(puVar3 + 0x12) = uVar2;
      }
    }
    obj->state = 1;
  }
  return;
}


