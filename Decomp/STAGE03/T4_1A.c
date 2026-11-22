// T4_1A, STAGE03.BIN, handler 0x801E9470. Ghidra output with the object struct applied; not matching C.
// ---- 801e9470 FUN_801e9470

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9470(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea124)[obj->state])();
  return;
}


// ---- 801e94ac FUN_801e94ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e94ac(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  undefined1 *puVar3;
  MM8Obj *pMVar4;
  char cVar5;
  int iVar6;
  
  pMVar4 = (MM8Obj *)&DAT_801cf540;
  while (((pMVar4->active == 0 || (pMVar4->id != 0x1a)) || (pMVar4 == obj))) {
    pMVar4 = (MM8Obj *)&pMVar4->speed_y_up;
    if (&DAT_801cf840 <= pMVar4) {
      iVar6 = 0;
      do {
        bVar1 = Rand();
        cVar5 = '\0';
        if ((bVar1 & 2) == 0) {
          cVar5 = (bVar1 & 1) + 1;
        }
        puVar3 = (undefined1 *)Obj_AllocType3();
        if (puVar3 != (undefined1 *)0x0) {
          *puVar3 = 1;
          puVar3[6] = 0x1b;
          puVar3[7] = cVar5;
          puVar3[1] = 0;
          *(short *)(puVar3 + 0xe) = DAT_801d2918._2_2_ + (short)iVar6;
          sVar2 = FUN_801e95f4(puVar3[7]);
          *(short *)(puVar3 + 0x12) = g_cam_y + sVar2;
        }
        sVar2 = DAT_801d2918._2_2_;
        iVar6 = iVar6 + 0x40;
      } while (iVar6 < 0x140);
      *(undefined1 *)((int)&obj->speed_x + 2) = 0;
      obj->state = 1;
      *(short *)&obj->speed_x = sVar2;
      return;
    }
  }
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801e95f4 FUN_801e95f4

int FUN_801e95f4(byte param_1)

{
  int iVar1;
  uint uVar2;
  int in_v1;
  
  if (param_1 == 1) {
    uVar2 = Rand();
    iVar1 = (uVar2 & 0x1f) + 0x88;
  }
  else if (param_1 < 2) {
    iVar1 = in_v1 << 0x10;
    if (param_1 != 0) goto LAB_801e9674;
    uVar2 = Rand();
    iVar1 = (uVar2 & 0x3f) + 0xa8;
  }
  else {
    iVar1 = in_v1 << 0x10;
    if (param_1 != 2) goto LAB_801e9674;
    uVar2 = Rand();
    iVar1 = (uVar2 & 0x1f) + 0x78;
  }
  iVar1 = iVar1 << 0x10;
LAB_801e9674:
  return iVar1 >> 0x10;
}


