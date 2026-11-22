// T4_2C, STAGE07.BIN, handler 0x801DF1A4. Ghidra output with the object struct applied; not matching C.
// ---- 801df1a4 FUN_801df1a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df1a4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e0c08)[obj->state])();
  return;
}


// ---- 801df1e0 FUN_801df1e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df1e0(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = FUN_80105ea4(obj,0x2c);
  if (iVar1 == 0) {
    obj->state = DAT_801c3371 + 1;
    FUN_801061dc(&DAT_801e0c70,&DAT_80159824,0x40);
    if ((DAT_801c3371 == '\x01') || (DAT_801c3371 == '\x04')) {
      FUN_801e045c();
    }
    if (DAT_801c3371 == '\x02') {
      FUN_801e0518();
    }
    (*(code *)(&PTR_FUN_801e0c08)[obj->state])(obj);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801df2b8 FUN_801df2b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df2b8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e0c50)[obj->sub2])();
  return;
}


// ---- 801df2f4 FUN_801df2f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df2f4(MM8Obj *obj)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocType3();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x31;
    obj->sub2 = 1;
  }
  return;
}


// ---- 801df4cc FUN_801df4cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df4cc(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    FUN_801dfef8();
    FUN_801dffec();
    iVar1 = 0x1808;
    if (DAT_801c3371 == '\x01') {
      iVar1 = 0x1828;
      iVar2 = 0x7b0;
    }
    else {
      iVar2 = 0x17b0;
    }
    if ((iVar1 < DAT_8015e248._2_2_) && ((int)DAT_8015e248._2_2_ < iVar1 + 0x10)) {
      if ((iVar2 < DAT_8015e24c._2_2_) &&
         (((int)DAT_8015e24c._2_2_ < iVar2 + 0x40 && (DAT_8015e27f == '\0')))) {
        obj->sub2 = 1;
        FUN_801dfb98(obj);
      }
    }
  }
  else {
    FUN_801dfbf4(obj);
  }
  return;
}


// ---- 801df5ac FUN_801df5ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df5ac(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e0c5c)[obj->sub2])();
  return;
}


// ---- 801df9cc FUN_801df9cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Possible GS_106.OBJ/GsSetProjection
   Possible _OP_VDEL.OBJ/__builtin_vec_delete
   Possible _OP_VNEW.OBJ/__builtin_vec_new
   Possible SCNOFF.OBJ/SsSetNoiseOff
   Possible SSQUIT.OBJ/SsQuit */

void FUN_801df9cc(MM8Obj *obj)

{
  Obj_Free();
  return;
}


// ---- 801dfb98 FUN_801dfb98

void FUN_801dfb98(int param_1)

{
  DAT_8015e2af = 1;
  DAT_8015e2b9 = 1;
  *(undefined1 *)(param_1 + 0x16) = 0;
  DAT_801d292a = g_cam_y & 0x1f00;
  DAT_801d292c = DAT_801d292a;
  FUN_8010bb88(0,0);
  return;
}


// ---- 801dfbf4 FUN_801dfbf4

void FUN_801dfbf4(int param_1)

{
  if (*(char *)(param_1 + 4) == '\0') {
    FUN_80111904();
    if (*(byte *)(param_1 + 0x16) < 0x20) {
      *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + '\x01';
    }
    FUN_8010bbe4(*(undefined1 *)(param_1 + 0x16));
    if ((*(char *)(param_1 + 0x16) == ' ') && (g_cam_y == DAT_801d292a)) {
      FUN_801dfda8();
      DAT_801c3377 = (&DAT_801e0c48)[DAT_801c3371];
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
      FUN_8011c504();
      if ((DAT_801c3371 == 0) || (DAT_801c3371 == 3)) {
        FUN_801e045c();
      }
      if (DAT_801c3371 == 1) {
        FUN_801e0518();
      }
      *(undefined1 *)(param_1 + 4) = 1;
      DAT_801c3371 = DAT_801c3371 + 1;
    }
  }
  else {
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + -1;
    FUN_8010bbe4(*(undefined1 *)(param_1 + 0x16));
    if (*(char *)(param_1 + 0x16) == '\0') {
      DAT_8015e2af = 0;
      DAT_8015e2b9 = 0;
      FUN_80111918();
      FUN_8011c5d4((int)*(short *)(&DAT_801e0c3a + (uint)DAT_801c3371 * 2));
      FUN_8010bbb8();
      *(undefined1 *)(param_1 + 2) = 0;
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
    }
  }
  return;
}


// ---- 801dfda8 FUN_801dfda8

void FUN_801dfda8(void)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  
  uVar3 = (uint)DAT_801c3371;
  sVar1 = *(short *)(&DAT_801e0c24 + uVar3 * 4);
  sVar2 = *(short *)(&DAT_801e0c26 + uVar3 * 4);
  if ((uVar3 == 1) || (uVar3 == 4)) {
    DAT_8015e248._2_2_ = sVar1 + 0xa0;
    DAT_8015e270 = DAT_8015e248._2_2_;
    DAT_801d2918._2_2_ = sVar1;
    DAT_801d291e = sVar1;
  }
  else {
    DAT_801d2918._2_2_ = sVar1 + DAT_801d2918._2_2_;
    DAT_801d291e = sVar1 + DAT_801d291e;
    DAT_8015e248._2_2_ = sVar1 + DAT_8015e248._2_2_;
    DAT_8015e270 = sVar1 + DAT_8015e270;
  }
  g_cam_y = sVar2 + g_cam_y;
  DAT_801d2928 = DAT_801d2918._2_2_;
  DAT_801d2926 = DAT_801d2918._2_2_;
  DAT_801d2920 = sVar2 + DAT_801d2920;
  DAT_8015e24c._2_2_ = sVar2 + DAT_8015e24c._2_2_;
  DAT_8015e272 = sVar2 + DAT_8015e272;
  DAT_801d292e = DAT_801d2918._2_2_;
  DAT_801d2930 = DAT_801d2918._2_2_;
  DAT_801d292a = g_cam_y;
  DAT_801d292c = g_cam_y;
  DAT_801d2932 = g_cam_y;
  DAT_801d2934 = g_cam_y;
  FUN_80101bf0();
  return;
}


// ---- 801dfef8 FUN_801dfef8

void FUN_801dfef8(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  
  sVar2 = 0x1600;
                    /* Possible PsyQ macro: setPolyGT4() */
  if (DAT_801c3371 == '\x01') {
    sVar2 = 0x600;
  }
                    /* Possible PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setTile8() */
  if (DAT_8015e248._2_2_ < 0x1901) {
    sVar1 = (ushort)(DAT_8015e248._2_2_ < 0x1500) << 10;
  }
  else {
    sVar1 = -0x400;
  }
                    /* Possible PsyQ macro: setPolyF4() */
  uVar3 = 0xfd00;
  if ((int)DAT_8015e24c._2_2_ <= sVar2 + 0x300) {
    uVar3 = -(ushort)((int)DAT_8015e24c._2_2_ < (int)sVar2) & 0x300;
  }
  if (sVar1 != 0 || uVar3 != 0) {
    DAT_801d2918._2_2_ = sVar1 + DAT_801d2918._2_2_;
    g_cam_y = uVar3 + g_cam_y;
    DAT_801d291e = sVar1 + DAT_801d291e;
    DAT_801d2920 = uVar3 + DAT_801d2920;
    FUN_80105f18((int)sVar1,(int)(short)uVar3);
  }
  return;
}


// ---- 801dffec FUN_801dffec

void FUN_801dffec(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  
  iVar2 = (int)(short)DAT_801d2918._2_2_;
  if (iVar2 != DAT_801d291e) {
    iVar3 = g_cam_y - 0x30;
    iVar4 = g_cam_y + 0x120;
    iVar1 = iVar2 + 0x150;
    if (iVar2 <= DAT_801d291e) {
      iVar1 = iVar2 + -0x30;
    }
    iVar2 = (int)(short)iVar1;
    if (iVar2 < 0x1500) {
      iVar1 = (iVar1 + 0x20) * 0x10000 >> 0x10;
      if (iVar1 < 0x1500) {
LAB_801e0104:
        iVar3 = iVar3 * 0x10000 >> 0x10;
        iVar4 = iVar4 * 0x10000 >> 0x10;
      }
      else {
        iVar3 = iVar3 * 0x10000 >> 0x10;
        iVar4 = iVar4 * 0x10000 >> 0x10;
        FUN_801e0244(iVar2,0x14ff,iVar3,iVar4);
        iVar2 = 0x1500;
      }
    }
    else {
      iVar1 = (iVar1 + 0x20) * 0x10000 >> 0x10;
      if ((iVar1 < 0x1900) || (0x18ff < iVar2)) goto LAB_801e0104;
      iVar3 = iVar3 * 0x10000 >> 0x10;
      iVar4 = iVar4 * 0x10000 >> 0x10;
      FUN_801e0244(0x1900,iVar1,iVar3,iVar4);
      iVar1 = 0x18ff;
    }
    FUN_801e0244(iVar2,iVar1,iVar3,iVar4);
  }
  iVar2 = (int)(short)g_cam_y;
  if (iVar2 == DAT_801d2920) {
    return;
  }
  iVar3 = DAT_801d2918._2_2_ + 0x170;
  iVar1 = iVar2 + 0x100;
  if (iVar2 <= DAT_801d2920) {
    iVar1 = iVar2 + -0x30;
  }
  iVar2 = (int)((DAT_801d2918._2_2_ - 0x30) * 0x10000) >> 0x10;
  iVar4 = iVar1 + 0x20;
  sVar5 = (short)iVar1;
  if (iVar2 < 0x1500) {
    iVar1 = iVar3 * 0x10000 >> 0x10;
    if (0x14ff < iVar1) {
      iVar3 = iVar4 * 0x10000 >> 0x10;
      FUN_801e0244(iVar2,0x14ff,(int)sVar5,iVar3);
      iVar2 = 0x1500;
      goto LAB_801e0218;
    }
  }
  else {
    iVar1 = iVar3 * 0x10000 >> 0x10;
    if ((0x18ff < iVar1) && (iVar2 < 0x1900)) {
      iVar3 = iVar4 * 0x10000 >> 0x10;
      FUN_801e0244(0x1900,iVar1,(int)sVar5,iVar3);
      iVar1 = 0x18ff;
      goto LAB_801e0218;
    }
  }
  iVar3 = iVar4 * 0x10000 >> 0x10;
LAB_801e0218:
  FUN_801e0244(iVar2,iVar1,(int)sVar5,iVar3);
  return;
}


// ---- 801e0244 FUN_801e0244

void FUN_801e0244(short param_1,ushort param_2,short param_3,short param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  
  if (DAT_801c3371 == '\x01') {
    iVar7 = 0x900;
    iVar5 = 0x600;
  }
  else {
    iVar7 = 0x1900;
    iVar5 = 0x1600;
  }
  sVar8 = -0x400;
  if (0x14ff < param_1) {
    sVar8 = (ushort)(0x18ff0000 < (int)((uint)param_2 << 0x10)) << 10;
  }
  iVar4 = (int)param_3;
  iVar6 = (int)param_4;
  if (iVar4 < iVar5) {
    if (iVar6 < iVar5) {
      iVar2 = (int)param_1 - (int)sVar8;
      iVar3 = (int)(short)param_2 - (int)sVar8;
      iVar4 = iVar4 + 0x300;
      iVar6 = iVar6 + 0x300;
      uVar1 = 0xfffffd00;
    }
    else {
      iVar7 = (int)sVar8;
      iVar2 = param_1 - iVar7;
      iVar3 = (short)param_2 - iVar7;
      Spawner_SpawnBox(iVar2,iVar3,iVar4 + 0x300,iVar5 + 0x2ff,iVar7,0xfffffd00);
      uVar1 = 0;
      iVar4 = iVar5;
    }
  }
  else if (iVar6 < iVar7) {
    iVar2 = (int)param_1 - (int)sVar8;
    iVar3 = (int)(short)param_2 - (int)sVar8;
    uVar1 = 0;
  }
  else if (iVar4 < iVar7) {
    iVar5 = (int)sVar8;
    iVar2 = param_1 - iVar5;
    iVar3 = (short)param_2 - iVar5;
    Spawner_SpawnBox(iVar2,iVar3,iVar4,iVar7 + -1,iVar5,0);
    iVar4 = iVar7 + -0x300;
    iVar6 = iVar6 + -0x300;
    uVar1 = 0x300;
  }
  else {
    iVar2 = (int)param_1 - (int)sVar8;
    iVar3 = (int)(short)param_2 - (int)sVar8;
    iVar4 = iVar4 + -0x300;
    iVar6 = iVar6 + -0x300;
    uVar1 = 0x300;
  }
  Spawner_SpawnBox(iVar2,iVar3,iVar4,iVar6,(int)sVar8,uVar1);
  return;
}


// ---- 801e045c FUN_801e045c

void FUN_801e045c(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  bVar3 = 0;
  do {
    puVar1 = (undefined1 *)Obj_AllocType2();
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar2 = (undefined1 *)Obj_AllocType2();
      if (puVar2 == (undefined1 *)0x0) {
        *puVar1 = 0;
      }
      else {
        *puVar2 = 1;
        puVar1[6] = 0x2b;
        puVar2[6] = 0x2b;
        puVar1[7] = bVar3;
        puVar2[7] = bVar3 | 0x80;
      }
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 4);
  DAT_801b29a1 = 0;
  DAT_801b29a2 = 0;
  DAT_801b29a3 = 0;
  DAT_801b29a4 = 0;
  return;
}


// ---- 801e0518 FUN_801e0518

void FUN_801e0518(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined1 *)Obj_AllocType3();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar2 = (undefined1 *)Obj_AllocType3();
    if (puVar2 == (undefined1 *)0x0) {
      *puVar1 = 0;
    }
    else {
      *puVar2 = 1;
      puVar1[6] = 0x33;
      puVar2[6] = 0x33;
      puVar1[7] = 2;
      puVar2[7] = 3;
    }
  }
  return;
}


