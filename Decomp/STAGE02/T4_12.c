// T4_12, STAGE02.BIN, handler 0x801E6664. Ghidra output with the object struct applied; not matching C.
// ---- 801e6664 FUN_801e6664

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6664(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8d60)[obj->state])();
  return;
}


// ---- 801e66a0 FUN_801e66a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e66a0(MM8Obj *obj)

{
  short *psVar1;
  byte *pbVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  undefined1 *puVar12;
  ushort *puVar13;
  int iVar14;
  
  iVar9 = 0;
  if (obj->var == 3) {
    puVar12 = &DAT_801cf540;
    do {
      iVar9 = iVar9 + 1;
      if ((*(uint *)(puVar12 + 4) & 0xffff0000) == 0x120000) goto LAB_801e6888;
      puVar12 = puVar12 + 0x18;
    } while (iVar9 < 0x20);
    FUN_801e7670((int)((DAT_801e8d58 + 1000) * 0x10000) >> 0x10,
                 (int)((DAT_801e8d5a + 0x388) * 0x10000) >> 0x10,
                 (ushort)DAT_801e8d5d << 8 | (short)DAT_801e8d5c,obj);
LAB_801e6888:
    Obj_Free(obj);
  }
  else {
    if ((obj->var & 0x80) == 0) {
      puVar12 = (undefined1 *)Obj_AllocType4();
      if (puVar12 != (undefined1 *)0x0) {
        *puVar12 = 1;
        puVar12[6] = 0x12;
        puVar12[7] = 0x80;
        *(MM8Obj **)(puVar12 + 0x10) = obj;
      }
      obj->state = 1;
      DAT_8015e2ba = 1;
    }
    else {
      iVar9 = *(int *)&obj->y_frac;
      uVar7 = (uint)*(byte *)(iVar9 + 7);
      puVar13 = (ushort *)(&DAT_801e8cf8 + (char)(&DAT_801e8ce9)[uVar7 * 6] * 4);
      iVar14 = 6;
      if (uVar7 != 2) {
        iVar14 = 9;
      }
      while( true ) {
        uVar6 = *puVar13;
        if ((short)*puVar13 < 1) break;
        uVar4 = puVar13[1];
        puVar13 = puVar13 + 2;
        if ((*(char *)(iVar9 + 7) == '\x02') && ((short)uVar4 < 0x1300)) {
          iVar14 = 4;
        }
        puVar11 = &DAT_801e8d28;
        iVar10 = 0;
        if (iVar14 != 0) {
          pcVar8 = "\x05";
          do {
            psVar1 = (short *)(pcVar8 + -2);
            pbVar2 = (byte *)(pcVar8 + 1);
            cVar3 = *pcVar8;
            pcVar8 = pcVar8 + 6;
            uVar5 = *puVar11;
            puVar11 = puVar11 + 3;
            iVar10 = iVar10 + 1;
            FUN_801e7670((int)(((uint)uVar6 + (uint)uVar5) * 0x10000) >> 0x10,
                         (int)(short)(uVar4 + *psVar1),(ushort)*pbVar2 << 8 | (short)cVar3,obj);
          } while (iVar10 < iVar14);
        }
      }
      obj->state = 6;
    }
    obj->x = 0;
    *(undefined1 *)((int)&obj->speed_x + 3) = 0;
  }
  return;
}


// ---- 801e6910 FUN_801e6910

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6910(MM8Obj *obj)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  byte *pbVar5;
  short *psVar6;
  int iVar7;
  
  if (*(char *)((int)&obj->speed_x + 3) != '\0') {
    if (obj->sub3 == 0) {
      cVar2 = (&DAT_801e8ce8)[(uint)obj->var * 6];
      psVar6 = (short *)(&PTR_DAT_801e8cd8)[obj->var];
      iVar7 = 0;
      if (0 < cVar2) {
        pbVar5 = (byte *)(psVar6 + 2);
        do {
          bVar3 = *pbVar5;
          pbVar1 = pbVar5 + -2;
          pbVar5 = pbVar5 + 6;
          sVar4 = *psVar6;
          psVar6 = psVar6 + 3;
          iVar7 = iVar7 + 1;
          FUN_801e7670((int)sVar4,(int)*(short *)pbVar1,(uint)bVar3 << 8,obj);
        } while (iVar7 < cVar2);
      }
      obj->x = 0xc;
      obj->sub3 = 1;
    }
    else if (obj->x == 0) {
      obj->state = 2;
      obj->sub3 = 0;
      *(undefined1 *)((int)&obj->speed_x + 3) = 0;
    }
    else {
      obj->x = obj->x + -1;
    }
  }
  return;
}


// ---- 801e6a20 FUN_801e6a20

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6a20(MM8Obj *obj)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = FUN_801e76f8();
  if (iVar1 != 0) {
    psVar2 = (short *)FUN_801e73e0(obj,obj->var);
    if (psVar2 == (short *)0x0) {
      obj->state = 4;
    }
    else {
      obj->x = 1;
      obj->state = 3;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      *(undefined1 *)((int)&obj->speed_x + 3) = 0;
      FUN_801e7670((int)*psVar2,(int)psVar2[1],(uint)*(byte *)(psVar2 + 2) << 8 | 1,obj);
      FUN_801e6ab4(obj);
    }
  }
  return;
}


// ---- 801e6ab4 FUN_801e6ab4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6ab4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8d7c)[*(byte *)((int)&obj->speed_x + 1)])(obj,&g_player);
  return;
}


// ---- 801e6b50 FUN_801e6b50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6b50(MM8Obj *obj)

{
  FUN_800fd100(0x87);
  obj->x = 0x20;
  obj->state = 5;
  return;
}


// ---- 801e6b8c FUN_801e6b8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6b8c(MM8Obj *obj)

{
  short sVar1;
  byte bVar2;
  uint uVar3;
  undefined1 *puVar4;
  int in_a1;
  int iVar5;
  int iVar6;
  short *psVar7;
  short sVar8;
  
  psVar7 = (short *)((&PTR_DAT_801e8cd8)[obj->var] + (uint)*(byte *)((int)&obj->speed_x + 2) * 6);
  sVar8 = g_cam_y + -0x20;
  if (*(char *)((int)psVar7 + 5) == '\0') {
    uVar3 = Rand();
    iVar5 = (int)(char)(&DAT_801e8d90)[uVar3 & 7];
    uVar3 = FUN_80105d48(obj,1);
    if (uVar3 < 0x19) goto LAB_801e6c48;
  }
  else {
    iVar5 = 0;
    if (*(char *)((int)psVar7 + 5) != '\x01') goto LAB_801e6c48;
  }
  uVar3 = Rand();
  iVar5 = (uVar3 & 1) + 2;
LAB_801e6c48:
  if (iVar5 == 0) {
    puVar4 = (undefined1 *)Obj_AllocMain();
    if (puVar4 != (undefined1 *)0x0) {
      *puVar4 = 1;
      puVar4[6] = 0x21;
      puVar4[7] = 0x80;
      *(short *)(puVar4 + 0xe) = *psVar7 + 0x18;
      *(short *)(puVar4 + 0x12) = psVar7[1] + 0x18;
      iVar5 = (int)(((ushort)psVar7[1] + 0xe) * 0x10000) >> 0x10;
      FUN_801e759c((int)*psVar7,iVar5,obj,&DAT_80000005);
      FUN_801e7670((int)*psVar7,iVar5,(uint)*(byte *)(psVar7 + 2) << 8 | 2,obj);
      obj->x = 0x30;
    }
    bVar2 = 5;
  }
  else {
    iVar6 = iVar5 + -2;
    if (iVar5 == 1) {
      FUN_800fd100(0x88);
      iVar5 = 0;
      do {
        puVar4 = (undefined1 *)Obj_AllocMain();
        if (puVar4 != (undefined1 *)0x0) {
          *puVar4 = 1;
          puVar4[6] = 1;
          puVar4[7] = 0;
          if (iVar5 == 0) {
            sVar1 = -0x20;
          }
          else {
            sVar1 = 0x20;
          }
          *(short *)(puVar4 + 0xe) = *(short *)(in_a1 + 0xe) + sVar1;
          *(short *)(puVar4 + 0x12) = sVar8;
          obj->x = 0x30;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
      obj->state = 5;
      return;
    }
    if (iVar6 == 0) {
      iVar6 = -0x80000000;
      sVar8 = psVar7[1] + 0xe;
    }
    FUN_801e759c((int)*psVar7,(int)sVar8,obj,iVar6);
    bVar2 = 4;
  }
  obj->state = bVar2;
  return;
}


// ---- 801e6db4 FUN_801e6db4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6db4(MM8Obj *obj)

{
  ushort uVar1;
  int iVar2;
  int in_a1;
  ushort *puVar3;
  
  puVar3 = (ushort *)((&PTR_DAT_801e8cd8)[obj->var] + (uint)*(byte *)((int)&obj->speed_x + 2) * 6);
  uVar1 = *puVar3;
  if (obj->sub2 == 0) {
    obj->sub2 = 1;
    *(undefined1 *)(in_a1 + 0x73) = 1;
    *(undefined1 *)(in_a1 + 0x7d) = 1;
    FUN_801119e0((int)((uVar1 + 0x18) * 0x10000) >> 0x10,*(undefined1 *)(in_a1 + 0x25));
    FUN_800fd100(0x88);
  }
  else if ((((int)*(short *)(in_a1 + 0xe) == (int)((uVar1 + 0x18) * 0x10000) >> 0x10) ||
           (*(char *)(in_a1 + 0x74) != '\0')) && (iVar2 = FUN_801e76f8(), iVar2 != 0)) {
    FUN_801e759c((int)(short)*puVar3,(int)((puVar3[1] + 0xe) * 0x10000) >> 0x10,obj,&DAT_80000004);
    FUN_801e7670((int)(short)*puVar3,(int)((puVar3[1] + 0xe) * 0x10000) >> 0x10,0x202,obj);
    obj->state = 4;
  }
  return;
}


// ---- 801e6ecc FUN_801e6ecc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6ecc(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  int in_a1;
  short *psVar8;
  int iVar9;
  
  psVar8 = (short *)((&PTR_DAT_801e8cd8)[obj->var] + (uint)*(byte *)((int)&obj->speed_x + 2) * 6);
  iVar9 = *psVar8 + 0x18;
  if (obj->sub3 == 0) {
    if (obj->field_0x4 == '\0') {
      FUN_801119e0(iVar9 * 0x10000 >> 0x10,*(undefined1 *)(in_a1 + 0x25));
      *(undefined1 *)(in_a1 + 0x73) = 1;
      *(undefined1 *)(in_a1 + 0x7d) = 1;
      obj->field_0x4 = 1;
    }
    else if (((*(short *)(in_a1 + 0xe) == iVar9) || (*(char *)(in_a1 + 0x74) != '\0')) &&
            (iVar9 = FUN_801e76f8(), iVar9 != 0)) {
      iVar9 = (psVar8[1] + 0xe) * 0x10000 >> 0x10;
      FUN_801e759c((int)*psVar8,iVar9,obj,&DAT_80000002);
      FUN_801e7670((int)*psVar8,iVar9,(uint)*(byte *)(psVar8 + 2) << 8 | 2,obj);
      obj->sub3 = 1;
      obj->field_0x4 = 0;
      *(undefined1 *)((int)&obj->speed_x + 3) = 0;
    }
  }
  else {
    if (obj->field_0x4 == '\0') {
      obj->field_0x4 = *(undefined1 *)((int)&obj->speed_x + 3);
    }
    cVar5 = obj->field_0x4;
    if (cVar5 == '\x01') {
      FUN_80111904();
      DAT_801b2998 = 1;
      bVar1 = obj->var;
      *(undefined1 *)((int)&obj->speed_x + 2) = *(undefined1 *)((int)psVar8 + 5);
      psVar8 = (short *)((&PTR_DAT_801e8cd8)[bVar1] + (uint)*(byte *)((int)&obj->speed_x + 2) * 6);
      sVar2 = psVar8[1];
      iVar9 = *psVar8 + 0x18;
      iVar3 = iVar9 * 0x10000 - *(int *)(in_a1 + 0xc);
      iVar6 = iVar3;
      if (iVar3 < 0) {
        iVar6 = -iVar3;
      }
      *(int *)(in_a1 + 0x14) = iVar3;
      iVar4 = (sVar2 + 0x18) * 0x10000 - *(int *)(in_a1 + 0x10);
      iVar3 = iVar4;
      if (iVar4 < 0) {
        iVar3 = -iVar4;
      }
      *(int *)(in_a1 + 0x18) = iVar4;
      if (iVar6 < iVar3) {
        iVar6 = iVar3;
      }
      if (iVar6 >> 0x12 < 0x101) {
        *(char *)&obj->speed_x = (char)(iVar6 >> 0x12);
      }
      else {
        *(undefined1 *)&obj->speed_x = 0xff;
      }
      uVar7 = (uint)(byte)obj->speed_x;
      if (uVar7 == 0) {
        trap(0x1c00);
      }
      if ((uVar7 == 0xffffffff) && (*(int *)(in_a1 + 0x14) == -0x80000000)) {
        trap(0x1800);
      }
      *(int *)(in_a1 + 0x14) = *(int *)(in_a1 + 0x14) / (int)uVar7;
      iVar6 = -(uint)(byte)obj->speed_x;
      if (iVar6 == 0) {
        trap(0x1c00);
      }
      if ((iVar6 == -1) && (*(int *)(in_a1 + 0x18) == -0x80000000)) {
        trap(0x1800);
      }
      *(int *)(in_a1 + 0x18) = *(int *)(in_a1 + 0x18) / iVar6;
      obj->field_0x4 = 2;
      cVar5 = obj->field_0x4;
    }
    if (cVar5 == '\x02') {
      if ((char)obj->speed_x == '\0') {
        obj->field_0x4 = 3;
      }
      else {
        *(char *)&obj->speed_x = (char)obj->speed_x + -1;
        FUN_80104c34();
      }
    }
    cVar5 = obj->field_0x4;
    if (cVar5 == '\x03') {
      sVar2 = psVar8[1];
      *(short *)(in_a1 + 0xe) = (short)iVar9;
      *(short *)(in_a1 + 0x12) = sVar2 + 0x18;
      iVar9 = (sVar2 + 0xe) * 0x10000 >> 0x10;
      FUN_801e759c((int)*psVar8,iVar9,obj,0x80000003);
      FUN_801e7670((int)*psVar8,iVar9,0x502,obj);
      FUN_801e7670((int)*psVar8,(int)psVar8[1],0x501,obj);
      obj->field_0x4 = 4;
      cVar5 = obj->field_0x4;
    }
    if (((cVar5 == '\x04') && (*(char *)((int)&obj->speed_x + 3) == '\x02')) &&
       (*(char *)(in_a1 + 2) == '\x0e')) {
      FUN_80111918();
      *(undefined1 *)(in_a1 + 0x73) = 0;
      *(undefined1 *)(in_a1 + 0x7d) = 0;
      obj->x = 0;
      obj->state = 4;
    }
  }
  return;
}


// ---- 801e73e0 FUN_801e73e0

short * FUN_801e73e0(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  short sVar6;
  int iVar7;
  
  sVar3 = DAT_8015e248._2_2_;
  iVar1 = param_2 * 6;
  iVar7 = (int)DAT_8015e248._2_2_;
  uVar4 = (uint)DAT_8015e24c._2_2_;
  if (*(short *)(&DAT_801e8ce4 + iVar1) <= iVar7) {
    if (*(short *)(&DAT_801e8ce6 + iVar1) < iVar7) {
      return (short *)0x0;
    }
    iVar7 = FUN_80107204(iVar7,(int)((uVar4 + 0x18) * 0x10000) >> 0x10);
    sVar6 = (short)(uVar4 + 0x18);
    if (iVar7 == 0) {
      sVar2 = 0x10;
      if (DAT_8015e261 == '\0') {
        sVar2 = -0x10;
      }
      sVar3 = sVar3 + sVar2;
      iVar7 = FUN_80107204((int)sVar3,(int)sVar6);
      if (iVar7 == 0) {
        sVar2 = -0x20;
        if (DAT_8015e261 == '\0') {
          sVar2 = 0x20;
        }
        sVar3 = sVar3 + sVar2;
      }
    }
    psVar5 = (short *)(&PTR_DAT_801e8cd8)[param_2];
    iVar7 = 0;
    if (0 < (char)(&DAT_801e8ce8)[iVar1]) {
      do {
        if (((((int)*psVar5 <= (int)sVar3) && ((int)sVar3 < *psVar5 + 0x30)) &&
            ((int)psVar5[1] < (int)sVar6)) && ((int)sVar6 < psVar5[1] + 0x18)) {
          sVar3 = psVar5[2];
          *(char *)(param_1 + 0x16) = (char)iVar7;
          *(char *)(param_1 + 0x15) = (char)sVar3;
          return psVar5;
        }
        iVar7 = iVar7 + 1;
        psVar5 = psVar5 + 3;
      } while (iVar7 < (char)(&DAT_801e8ce8)[iVar1]);
    }
  }
  return (short *)0x0;
}


// ---- 801e759c FUN_801e759c

undefined1 * FUN_801e759c(short param_1,short param_2,undefined4 param_3,int param_4)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocType2();
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[7] = (char)param_4;
    *puVar1 = 1;
    puVar1[6] = 0xb;
    *(short *)(puVar1 + 0xe) = param_1 + 0x18;
    *(short *)(puVar1 + 0x12) = param_2;
    *(undefined4 *)(puVar1 + 0x4c) = param_3;
    if (puVar1[7] == '\x01') {
      *(int *)(puVar1 + 0x1c) = DAT_8015e24c._2_2_ + 0x13;
    }
    if (param_4 < 0) {
      FUN_801e7670((int)param_1,(int)param_2,3,puVar1);
    }
  }
  return puVar1;
}


// ---- 801e7670 FUN_801e7670

undefined1 * FUN_801e7670(short param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocType3();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x13;
    puVar1[0x38] = (byte)((uint)param_3 >> 8) & 0xf;
    puVar1[7] = (char)param_3;
    *(short *)(puVar1 + 0xe) = param_1 + 0x18;
    *(undefined2 *)(puVar1 + 0x12) = param_2;
    *(undefined4 *)(puVar1 + 0x3c) = param_4;
  }
  return puVar1;
}


// ---- 801e76f8 FUN_801e76f8

byte FUN_801e76f8(void)

{
  byte bVar1;
  
  bVar1 = 0;
  if ((((DAT_8015e27f == '\0') && (DAT_8015e2a3 == '\0')) && (DAT_8015e2b6 == '\0')) &&
     (DAT_8015e2bb == '\0')) {
    bVar1 = DAT_8015e26f >> 7;
  }
  return bVar1;
}


