// T2_0A, STAGE04.BIN, handler 0x801E5D3C. Ghidra output with the object struct applied; not matching C.
// ---- 801e5d3c FUN_801e5d3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5d3c(MM8Obj *obj)

{
  if (obj->state == 0) {
    FUN_801e5dcc(obj);
  }
  else {
    FUN_801e5e78();
  }
  if (((int)obj->x < DAT_801d2918._2_2_ + -0x38) || (DAT_801d2918._2_2_ + 0x178 < (int)obj->x)) {
    Obj_FreeDespawn(obj);
  }
  else {
    obj->on_screen = 1;
    Obj_QueueDraw(obj);
  }
  return;
}


// ---- 801e5dcc FUN_801e5dcc

void FUN_801e5dcc(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
                    /* Possible PsyQ macro: setPolyFT4() + setSemiTrans(polyFT4, 1) +
                       setShadeTex(polyFT4, 1) */
  *(undefined1 *)(param_1 + 0x27) = 0x2f;
  *(undefined2 *)(param_1 + 0x2c) = DAT_801703a6;
  uVar1 = (&DAT_80159f64)[*(byte *)(param_1 + 0x27)];
  *(undefined1 *)(param_1 + 0x44) = 1;
  *(undefined1 *)(param_1 + 0x45) = 8;
  *(undefined1 *)(param_1 + 0x47) = 1;
  *(undefined1 *)(param_1 + 0x46) = 0;
  *(undefined1 *)(param_1 + 0x24) = uVar1;
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 0x26) = 7;
    uVar2 = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x26) = 5;
    uVar2 = 0x10;
  }
  Anim_SetAtStep(param_1,0,uVar2);
  uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x28) + 2);
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)(param_1 + 0x31) = uVar1;
  return;
}


// ---- 801e5e78 FUN_801e5e78

void FUN_801e5e78(int param_1)

{
  uint uVar1;
  
  Anim_Step();
  if ((*(byte *)(param_1 + 0x32) & 0x70) != 0) {
    *(byte *)(param_1 + 0x26) = *(byte *)(param_1 + 0x32) >> 4;
    *(byte *)(param_1 + 0x32) = *(byte *)(param_1 + 0x32) & 0xf;
  }
  uVar1 = (uint)*(byte *)(param_1 + 0x32);
  if ((uVar1 != 0) && (uVar1 < 3)) {
    *(undefined ***)(param_1 + 0x3c) = &PTR_FUN_801e74d0 + uVar1;
    Enemy_CheckWeaponHits(param_1);
    Enemy_ContactDamage(param_1);
  }
  return;
}


