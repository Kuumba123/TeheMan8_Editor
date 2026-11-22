// T4_2B, STAGE06.BIN, handler 0x801E4E90. Ghidra output with the object struct applied; not matching C.
// ---- 801e4e90 FUN_801e4e90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4e90(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e5cb4)[obj->state])();
  if ((1 < obj->state) &&
     (cVar1 = *(char *)((int)&obj->speed_x + 1) + -1, *(char *)((int)&obj->speed_x + 1) = cVar1,
     cVar1 == '\0')) {
                    /* Possible PsyQ macro: setPolyGT4() */
    *(undefined1 *)((int)&obj->speed_x + 1) = 0x3c;
    FUN_800fd100(0x129);
  }
  return;
}


// ---- 801e4f14 FUN_801e4f14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4f14(MM8Obj *obj)

{
  undefined1 *puVar1;
  int iVar2;
  short sVar3;
  
  iVar2 = 0;
  sVar3 = 0xd18;
  obj->sub2 = 0;
  *(undefined1 *)((int)&obj->speed_x + 1) = 0x1e;
  obj->state = obj->state + 1;
  do {
    puVar1 = (undefined1 *)Obj_AllocType2();
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar1[6] = 0x27;
      puVar1[7] = (char)iVar2;
      *(short *)(puVar1 + 0xe) = sVar3;
      *(undefined2 *)(puVar1 + 0x12) = 0x380;
      puVar1[0x44] = 0;
    }
    iVar2 = iVar2 + 1;
    sVar3 = sVar3 + 0x10;
  } while (iVar2 < 0x13);
  return;
}


// ---- 801e4fb8 FUN_801e4fb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4fb8(MM8Obj *obj)

{
  undefined1 *puVar1;
  
  if (obj->sub2 == 0) {
    if (((DAT_8015e23d == '\x02') && (DAT_801d2917 == '\0')) && (0xd0f < DAT_8015e248._2_2_)) {
      obj->sub2 = obj->sub2 + 1;
      FUN_800fcb80(0x18);
      FUN_801119e0(0xda0,0x40);
      DAT_801b2992 = 1;
      DAT_801b2993 = 1;
      DAT_801b2994 = 1;
    }
  }
  else if (DAT_8015e248._2_2_ == 0xda0) {
    puVar1 = (undefined1 *)Obj_AllocMain();
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar1[6] = 0x3f;
      *(undefined2 *)(puVar1 + 0xe) = 0xda0;
      *(undefined2 *)(puVar1 + 0x12) = 0x2c0;
      puVar1[7] = 0;
    }
    obj->sub2 = 0;
    *(undefined1 *)&obj->speed_x = 0x78;
    obj->state = obj->state + 1;
  }
  return;
}


// ---- 801e50d0 FUN_801e50d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e50d0(MM8Obj *obj)

{
  if (0x500 < DAT_8015e24c._2_2_) {
    obj->state = obj->state + 1;
    FUN_80111918();
    *(undefined1 *)&obj->speed_x = 0x3c;
    DAT_801b2992 = 0;
    DAT_801b2993 = 0;
    DAT_801b2994 = 0;
  }
  return;
}


// ---- 801e5138 FUN_801e5138

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5138(MM8Obj *obj)

{
  undefined4 uVar1;
  
  if (g_cam_y < 0x901) {
    if (0x4ff < g_cam_y) goto LAB_801e51c4;
    uVar1 = 0x400;
    g_cam_y = g_cam_y + 0x400;
    DAT_801d2920 = DAT_801d2920 + 0x400;
  }
  else {
    uVar1 = 0xfffffc00;
    g_cam_y = g_cam_y + -0x400;
    DAT_801d2920 = DAT_801d2920 + -0x400;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  FUN_80105f18(0,uVar1);
LAB_801e51c4:
  DAT_801d292c = g_cam_y;
  DAT_801d2934 = g_cam_y;
  (*(code *)(&PTR_FUN_801e5cc8)[obj->sub2])(obj);
  return;
}


// ---- 801e5210 FUN_801e5210

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5210(MM8Obj *obj)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  undefined1 *puVar6;
  
  cVar3 = (char)obj->speed_x + -1;
  *(char *)&obj->speed_x = cVar3;
  if (cVar3 == '\0') {
    if ((DAT_8015e27c & 0x80) == 0) {
      bVar2 = Rand();
      cVar3 = (bVar2 & 0xf) + 10;
    }
    else {
      bVar2 = Rand();
      cVar3 = (bVar2 & 0x1f) + 0x50;
    }
                    /* Possible PsyQ macro: setPolyGT3() */
    *(char *)&obj->speed_x = cVar3;
    iVar5 = FUN_801e53a0(obj);
    if ((iVar5 < 6) && (puVar6 = (undefined1 *)Obj_AllocType2(), puVar6 != (undefined1 *)0x0)) {
      *puVar6 = 1;
      puVar6[6] = 0x27;
      puVar6[7] = (byte)DAT_80170574 & 1;
      uVar4 = Rand();
      *(ushort *)(puVar6 + 0xe) = (uVar4 & 0xff) + 0xd20;
      sVar1 = g_cam_y;
      puVar6[0x44] = 1;
      *(short *)(puVar6 + 0x12) = sVar1 + 0x100;
    }
  }
  return;
}


// ---- 801e53a0 FUN_801e53a0

int FUN_801e53a0(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar3 = &DAT_801b1eec;
  iVar4 = 0;
  pcVar2 = "";
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 0x50;
    if (((cVar1 != '\0') && (pcVar2[-0x3e] == '\'')) && (*pcVar2 == '\x01')) {
      iVar4 = iVar4 + 1;
    }
    pcVar2 = pcVar2 + 0x50;
  } while (pcVar3 <= "");
  return iVar4;
}


