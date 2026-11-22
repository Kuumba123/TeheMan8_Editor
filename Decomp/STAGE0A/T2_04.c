// T2_04, STAGE0A.BIN, handler 0x801E0828. Ghidra output with the object struct applied; not matching C.
// ---- 801e0828 FUN_801e0828

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0828(MM8Obj *obj)

{
  char cVar1;
  
                    /* Probable PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  if (obj->state == 0) {
    FUN_801e08a0(obj);
  }
  else {
    FUN_801e095c();
  }
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
                    /* Probable PsyQ macro: setTile() */
    Obj_FreeDespawn(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e08a0 FUN_801e08a0

void FUN_801e08a0(int param_1)

{
  undefined1 uVar1;
  
                    /* Possible PsyQ macro: setPolyF3() */
  *(undefined1 *)(param_1 + 0x27) = 0x20;
  *(undefined2 *)(param_1 + 0x2c) = DAT_80170388;
  uVar1 = DAT_80159f84;
  *(undefined1 *)(param_1 + 0x26) = 7;
  *(undefined **)(param_1 + 0x38) = &UNK_801e2000 + (uint)*(byte *)(param_1 + 7) * 5;
  *(undefined **)(param_1 + 0x3c) = &UNK_801e2000 + (uint)*(byte *)(param_1 + 7) * 5;
  *(undefined1 *)(param_1 + 0x44) = 2;
  *(undefined1 *)(param_1 + 0x49) = uVar1;
  *(undefined1 *)(param_1 + 0x24) = uVar1;
  *(undefined *)(param_1 + 0x47) = (&DAT_801e1ff8)[*(byte *)(param_1 + 7)];
  uVar1 = (&DAT_801e1ffc)[*(byte *)(param_1 + 7)];
  *(undefined1 *)(param_1 + 0x46) = 0;
  *(undefined1 *)(param_1 + 0x45) = uVar1;
  Anim_SetAtStep(param_1,0,*(undefined1 *)(param_1 + 7));
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ---- 801e095c FUN_801e095c

void FUN_801e095c(int param_1)

{
  char cVar1;
  int iVar2;
  
                    /* Possible PsyQ macro: setPolyG3() */
  *(undefined1 *)(param_1 + 0x24) = *(undefined1 *)(param_1 + 0x49);
  cVar1 = Enemy_CheckWeaponHits();
  if (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  if (((cVar1 == '\x04') || (cVar1 = Enemy_ContactDamage(param_1), cVar1 != '\0')) ||
     ((DAT_8015e282 != '\0' && (iVar2 = FUN_80107d00(param_1,&g_player), iVar2 != 0)))) {
    FUN_80108e84(param_1);
                    /* Possible PsyQ macro: setPolyGT3() */
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 0x28;
    FUN_80108e84(param_1);
    FUN_8012ae08(param_1,3);
    Obj_FreeDespawn(param_1);
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + -0x28;
  }
  return;
}


