// ID 44, STAGE05.BIN, handler 0x801E079C. Ghidra output with the object struct applied; not matching C.
// ---- 801e079c FUN_801e079c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e079c(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  
  if (obj->state == 0) {
    Enemy_InitFromTable();
                    /* Possible PsyQ macro: setPolyG3() */
    obj->flip = 0;
    obj->on_screen = 1;
    obj->box2 = (byte *)0x0;
    obj->field_0x50 = 0;
    iVar5 = FUN_80105d48(obj,0x44);
    if (iVar5 != 0) goto LAB_801e0844;
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
    obj->state = obj->state + 1;
  }
  if (obj->field_0x50 == '\0') {
    if (obj->var == 0) {
      obj->hitbox = &DAT_801ea644;
      cVar3 = Enemy_CheckWeaponHits(obj);
                    /* Probable PsyQ macro: setTile() */
      pbVar6 = &DAT_801ea648;
    }
    else {
      obj->hitbox = &DAT_801ea64c;
      cVar3 = Enemy_CheckWeaponHits(obj);
      pbVar6 = &DAT_801ea650;
    }
    obj->hitbox = pbVar6;
    cVar4 = Enemy_CheckWeaponHits(obj);
    if (((cVar3 == '\x03') || (cVar4 == '\x03')) && (DAT_80158f5c == '\x06')) {
      sVar1 = obj->x;
      sVar2 = obj->y;
      FUN_8010544c(obj,9);
      uVar7 = 0;
      iVar5 = 0;
      do {
        obj->x = *(short *)((int)&DAT_801ea654 + iVar5);
        obj->y = *(short *)((int)&DAT_801ea656 + iVar5);
        FUN_8012ae08(obj,0x27);
        iVar5 = iVar5 + 4;
        if ((uVar7 & 3) == 0) {
          FUN_8010544c(obj,10);
        }
        FUN_801e09a4(obj);
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 8);
      obj->x = sVar1;
      obj->y = sVar2;
      obj->field_0x50 = 10;
    }
    iVar5 = FUN_80104820(obj,0xb8,0x38);
                    /* Possible PsyQ macro: setPolyG3() */
    if (iVar5 != 0) {
      return;
    }
    Obj_FreeDespawn(obj);
    return;
  }
  cVar3 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar3;
  if (cVar3 != '\0') {
    return;
  }
                    /* Probable PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  FUN_80102ef4(0x40,0,0);
LAB_801e0844:
  Obj_Free(obj);
  return;
}


// ---- 801e09a4 FUN_801e09a4

int FUN_801e09a4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_8012c108(param_1,0,0,0,0,0);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 7) = 0x10;
                    /* Possible PsyQ macro: setPolyGT3() */
    *(undefined1 *)(iVar1 + 0x27) = 0x34;
  }
  return iVar1;
}


