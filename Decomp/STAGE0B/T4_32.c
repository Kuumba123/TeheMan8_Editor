// T4_32, STAGE0B.BIN, handler 0x801E7B30. Ghidra output with the object struct applied; not matching C.
// ---- 801e7b30 FUN_801e7b30

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7b30(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8878)[obj->state])();
  return;
}


// ---- 801e7b6c FUN_801e7b6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7b6c(MM8Obj *obj)

{
  short sVar1;
  undefined1 *puVar2;
  
  DAT_801b29a1 = 0;
  DAT_801b29a2 = 0;
  DAT_801b29a3 = 0;
  DAT_801b29a4 = 0;
  DAT_801b29a7 = 0;
  puVar2 = (undefined1 *)Obj_AllocMain();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x59;
    *(undefined4 *)(puVar2 + 0xc) = 0;
    sVar1 = DAT_801d2918._2_2_;
    *(undefined4 *)(puVar2 + 0x10) = 0;
    *(short *)(puVar2 + 0xe) = sVar1 + 0xa0;
    sVar1 = g_cam_y;
    puVar2[7] = 0;
    puVar2[1] = 0;
    *(short *)(puVar2 + 0x12) = sVar1 + 0x1e0;
    DAT_801b297c = puVar2;
    obj->state = 1;
    obj->sub2 = 0;
    DAT_801b2992 = 1;
    DAT_801b2993 = 1;
    DAT_8015e2af = 1;
    FUN_800fcb80(0x38);
    FUN_801119e0((int)DAT_8015e248._2_2_,0x40);
  }
  return;
}


// ---- 801e7c44 FUN_801e7c44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7c44(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  bVar5 = false;
  iVar4 = (int)DAT_8015e248._2_2_;
  iVar3 = (iVar4 + -0x20) - (int)DAT_801d2918._2_2_;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (iVar3 < 9) {
    bVar5 = true;
    sVar2 = DAT_8015e248._2_2_;
  }
  else {
    iVar3 = DAT_801d2918._2_2_ + 0x20;
    sVar2 = DAT_8015e248._2_2_ + 1;
    if ((iVar3 <= iVar4) && (sVar2 = DAT_8015e248._2_2_, iVar3 < iVar4)) {
      sVar2 = DAT_8015e248._2_2_ + -1;
    }
  }
  DAT_8015e248._2_2_ = sVar2;
  iVar4 = (int)DAT_8015e24c._2_2_;
  iVar3 = (iVar4 + -0x80) - (int)g_cam_y;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (8 < iVar3) {
    iVar3 = g_cam_y + 0x80;
    sVar2 = 1;
    if ((iVar4 < iVar3) || (sVar2 = -1, iVar3 < iVar4)) {
      DAT_8015e24c._2_2_ = DAT_8015e24c._2_2_ + sVar2;
    }
    bVar5 = false;
  }
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    if (DAT_801b29a7 == '\x02') {
      FUN_800fcb80(0x39);
      obj->sub2 = 2;
    }
  }
  else if (bVar1 < 2) {
    if (((bVar1 == 0) && (DAT_801cf53c == '\0')) && (bVar5)) {
      DAT_801b29a7 = '\x01';
      obj->sub2 = 1;
    }
  }
  else if ((bVar1 == 2) && (DAT_801cf53c == '\0')) {
    DAT_801b29a7 = '\x03';
    obj->state = 2;
    obj->sub2 = 0;
    DAT_801b2992 = 0;
    DAT_801b2993 = 0;
    DAT_8015e2af = 0;
    FUN_80111918();
  }
  return;
}


// ---- 801e7e00 FUN_801e7e00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7e00(MM8Obj *obj)

{
  char cVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  switch(obj->sub2) {
  case 0:
    if (DAT_801b29a7 == '\x04') {
      DAT_8015e2af = 1;
      DAT_801b2992 = 1;
      DAT_801b2993 = 1;
      FUN_801119e0((int)DAT_8015e248._2_2_,0x40);
      FUN_800fcb80(0x19);
      obj->sub2 = 1;
    }
    break;
  case 1:
    bVar2 = false;
    iVar5 = (int)DAT_8015e248._2_2_;
    iVar4 = (iVar5 + -0x40) - (int)DAT_801d2918._2_2_;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    if (iVar4 < 9) {
      bVar2 = true;
    }
    else {
      iVar4 = DAT_801d2918._2_2_ + 0x40;
      if (iVar5 < iVar4) {
        DAT_8015e248 = CONCAT22(DAT_8015e248._2_2_ + 1,(undefined2)DAT_8015e248);
      }
      else if (iVar4 < iVar5) {
        DAT_8015e248 = CONCAT22(DAT_8015e248._2_2_ + -1,(undefined2)DAT_8015e248);
      }
    }
    iVar5 = (int)DAT_8015e24c._2_2_;
    iVar4 = (iVar5 + -0x80) - (int)g_cam_y;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    if (8 < iVar4) {
      iVar4 = g_cam_y + 0x80;
      sVar3 = 1;
      if ((iVar5 < iVar4) || (sVar3 = -1, iVar4 < iVar5)) {
        DAT_8015e24c._2_2_ = DAT_8015e24c._2_2_ + sVar3;
      }
      bVar2 = false;
    }
    if ((bVar2) && (DAT_801cf53c == '\0')) {
      obj->sub2 = 2;
      *(undefined1 *)&obj->speed_x = 0xb4;
    }
    break;
  case 2:
    DAT_8015e248 = DAT_8015e248 + -0x20000;
    cVar1 = (char)obj->speed_x;
    *(char *)&obj->speed_x = cVar1 + -1;
    if (cVar1 == '\0') {
      *(undefined1 *)&obj->speed_x = 0x78;
      obj->sub2 = 3;
    }
    break;
  case 3:
    DAT_8015e248 = DAT_8015e248 + 0x20000;
    cVar1 = (char)obj->speed_x;
    *(char *)&obj->speed_x = cVar1 + -1;
    if (cVar1 == '\0') {
      DAT_801b2995 = 1;
      obj->sub2 = 4;
    }
    break;
  case 4:
    DAT_8015e248 = DAT_8015e248 + 0x20000;
  }
  return;
}


