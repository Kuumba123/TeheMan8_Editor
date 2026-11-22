// ID 30, STAGE06.BIN, handler 0x801DA774. Ghidra output with the object struct applied; not matching C.
// ---- 801da774 FUN_801da774

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da774(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e5768)[obj->state])();
  if (0x46e < DAT_8015e248._2_2_) {
    DAT_801d2978._1_1_ = 2;
  }
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_Free(obj);
  }
  return;
}


// ---- 801da7f8 FUN_801da7f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da7f8(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->hitbox = &DAT_801e5764;
  obj->state = 1;
  obj->on_screen = 1;
  obj->box2 = (byte *)0x0;
  obj->field_0x50 = 4;
  obj->field_0x51 = 0;
  DAT_801d2978._1_1_ = 1;
  return;
}


// ---- 801da850 FUN_801da850

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da850(MM8Obj *obj)

{
  undefined1 *puVar1;
  
  Enemy_CheckWeaponHits();
  if (DAT_801b298a != '\0') {
    DAT_8015e2b9 = 1;
    obj->state = 2;
    obj->sub2 = 0;
    FUN_8012a5fc(obj,0);
    FUN_80108e84(obj);
    FUN_80102ef4(0,0x3e0,0xf30);
    FUN_80102ef4(9,0x3e0,0xf30);
    FUN_80102ef4(9,0x3e0,0xf20);
    puVar1 = (undefined1 *)Obj_AllocType3();
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar1[6] = 0x36;
      puVar1[7] = 0;
      *(short *)(puVar1 + 0xe) = obj->x;
      *(short *)(puVar1 + 0x12) = obj->y;
      puVar1[0x38] = 0;
      *(undefined2 *)(puVar1 + 0x3a) = *(undefined2 *)(puVar1 + 0x12);
    }
  }
  return;
}


// ---- 801da930 FUN_801da930

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da930(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
    obj->field_0x51 = obj->field_0x51 + '\x01';
    if ((byte)obj->field_0x51 < 4) {
      obj->field_0x50 = 4;
    }
    else {
                    /* Possible PsyQ macro: setSprt16() + setSemiTrans(sprt16, 1) +
                       setShadeTex(sprt16, 1) */
      obj->state = 3;
    }
    iVar4 = (uint)(byte)obj->field_0x51 * -0x20;
    FUN_8012a724(obj,0,iVar4,0);
    FUN_80108ed8(obj,iVar4,0);
    iVar4 = iVar4 + 0x3e0;
    FUN_80102ef4(0,iVar4,0xf30);
    FUN_80102ef4(9,iVar4,0xf30);
    FUN_80102ef4(9,iVar4,0xf20);
    puVar3 = (undefined1 *)Obj_AllocType3();
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 0x36;
      puVar3[7] = 0;
      *(short *)(puVar3 + 0xe) = (short)iVar4;
      *(short *)(puVar3 + 0x12) = obj->y;
      puVar3[0x38] = 0;
      *(undefined2 *)(puVar3 + 0x3a) = *(undefined2 *)(puVar3 + 0x12);
    }
    bVar1 = obj->field_0x51;
    iVar4 = (uint)bVar1 << 5;
    FUN_8012a724(obj,0,iVar4,0);
    FUN_80108ed8(obj,iVar4,0);
    iVar4 = (uint)bVar1 * 0x20 + 0x3e0;
    FUN_80102ef4(0,iVar4,0xf30);
    FUN_80102ef4(9,iVar4,0xf30);
    FUN_80102ef4(9,iVar4,0xf20);
    puVar3 = (undefined1 *)Obj_AllocType3();
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 0x36;
      puVar3[7] = 0;
      *(short *)(puVar3 + 0xe) = (short)iVar4;
      *(short *)(puVar3 + 0x12) = obj->y;
      puVar3[0x38] = 0;
      *(undefined2 *)(puVar3 + 0x3a) = *(undefined2 *)(puVar3 + 0x12);
    }
  }
  FUN_801dab0c(obj);
  return;
}


// ---- 801dab0c FUN_801dab0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dab0c(MM8Obj *obj)

{
  if ((obj->sub2 == 0) && (DAT_801b298a == '\0')) {
    FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
    obj->sub2 = obj->sub2 + 1;
  }
  DAT_801b2988 = DAT_801b2988 + -2;
  if (DAT_801b2988 < 0xed1) {
    DAT_801d2978._1_1_ = 2;
    DAT_801d2982 = 0x280;
    DAT_801d2984 = 0x90;
    FUN_80111918();
    DAT_8015e2b9 = 0;
    Obj_Free(obj);
  }
  else {
    DAT_801d2984 = DAT_801d2984 + 2;
  }
  return;
}


