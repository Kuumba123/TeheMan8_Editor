// T4_14, STAGE02.BIN, handler 0x801E7760. Ghidra output with the object struct applied; not matching C.
// ---- 801e7760 FUN_801e7760

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7760(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8d98)[obj->state])();
  return;
}


// ---- 801e779c FUN_801e779c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e779c(MM8Obj *obj)

{
  if (obj->var != 0) {
    FUN_801096b4(2,0x13);
    FUN_801096b4(1,0xb);
    FUN_801096b4(3,0x12);
    FUN_801096b4(2,0x17);
  }
  *(undefined1 *)((int)&obj->speed_x + 3) = 0;
  obj->state = 1;
  return;
}


// ---- 801e7808 FUN_801e7808

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7808(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    if (((int)(((ushort)obj->x - 0x30) * 0x10000) >> 0x10 < (int)(short)DAT_8015e248._2_2_) &&
       (DAT_8015e27f == '\0')) {
      DAT_8015e2ba = 0;
      DAT_8015e2af = 1;
      FUN_801119e0((int)obj->x,0x40);
      obj->sub2 = 1;
    }
  }
  else if (DAT_8015e248._2_2_ == obj->x) {
    *(undefined1 *)((int)&obj->speed_x + 2) = 0x10;
    *(undefined1 *)((int)&obj->speed_x + 1) = 0;
    obj->state = 2;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801e78c8 FUN_801e78c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e78c8(MM8Obj *obj)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  undefined1 *puVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  
  if (obj->sub2 == 0) {
    if ((char)obj->speed_x == '\0') {
      iVar7 = 0;
      if (*(char *)((int)&obj->speed_x + 2) != '\0') {
        do {
          puVar4 = (undefined1 *)Obj_AllocType3();
          if (puVar4 != (undefined1 *)0x0) {
            *puVar4 = 1;
            puVar4[6] = 0x17;
            puVar4[7] = 0xff;
            puVar4[0x26] = *(char *)((int)&obj->speed_x + 1) + '\x05';
            uVar3 = Rand();
            *(ushort *)(puVar4 + 0x12) = -(uVar3 & 0x7f) + 0x2e0;
            uVar6 = ((uint)*(byte *)((int)&obj->speed_x + 1) * -0x14 + 0x4c0) * 0x10000;
            if (obj->var != 0) {
              *(ushort *)(puVar4 + 0x12) = -(uVar3 & 0x7f) + 0x11e0;
              uVar6 = uVar6 + 0xf000000;
            }
            *(uint *)(puVar4 + 0x28) =
                 uVar6 | (int)obj->y + (uint)*(byte *)((int)&obj->speed_x + 1) * -0x14;
            uVar3 = Rand();
            sVar5 = (uVar3 & 0x1f) + (ushort)*(byte *)((int)&obj->speed_x + 1) * -4;
            uVar6 = Rand();
            if ((uVar6 & 0x40) != 0) {
              sVar5 = -sVar5;
            }
            *(short *)(puVar4 + 0xe) = obj->x + sVar5;
            uVar6 = Rand();
            *(uint *)(puVar4 + 0x18) = uVar6 & 0x7fff;
            uVar1 = *(undefined1 *)((int)&obj->speed_x + 1);
            *(MM8Obj **)(puVar4 + 0x3c) = obj;
            puVar4[0x38] = uVar1;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)(uint)*(byte *)((int)&obj->speed_x + 2));
      }
      FUN_800fd100(0x8b);
      bVar2 = *(byte *)((int)&obj->speed_x + 2);
      *(undefined1 *)&obj->speed_x = 0x10;
      *(byte *)((int)&obj->speed_x + 2) = bVar2 >> 1;
      *(char *)((int)&obj->speed_x + 1) = *(char *)((int)&obj->speed_x + 1) + '\x01';
      if (*(char *)((int)&obj->speed_x + 2) == '\0') {
        obj->sub2 = 1;
      }
    }
    else {
      *(char *)&obj->speed_x = (char)obj->speed_x + -1;
    }
  }
  else if (*(char *)((int)&obj->speed_x + 3) != '\0') {
    obj->state = 3;
    obj->sub2 = 0;
  }
  DAT_801d2936 = (ushort)(*(char *)((int)&obj->speed_x + 3) == '\0');
  return;
}


// ---- 801e7ac0 FUN_801e7ac0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7ac0(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  short sVar8;
  
  iVar7 = 0;
  sVar1 = obj->x;
  sVar8 = obj->y + -0x18;
  do {
    iVar5 = 0;
    sVar4 = sVar1 + -0x30;
    do {
      FUN_80103134((int)sVar4,(int)sVar8,0);
      iVar5 = iVar5 + 1;
      sVar4 = sVar4 + 0x10;
    } while (iVar5 < 6);
    iVar7 = iVar7 + 1;
    sVar8 = sVar8 + 0x10;
  } while (iVar7 < 8);
  iVar7 = 0;
  sVar4 = 8;
  sVar1 = obj->x;
  sVar8 = obj->y;
  do {
    uVar6 = 0;
    obj->x = sVar1 + -0x20;
    obj->y = sVar8 + sVar4;
    do {
      sVar2 = -0x10;
      if ((uVar6 & 1) == 0) {
        sVar2 = 0x10;
      }
      obj->y = obj->y + sVar2;
      if ((iVar7 == 0) || ((uVar6 & 1) == 0)) {
        FUN_80108e84(obj);
        FUN_8012ae08(obj,0x11);
      }
      uVar6 = uVar6 + 1;
      obj->x = obj->x + 0x10;
    } while ((int)uVar6 < 5);
    iVar7 = iVar7 + 1;
    sVar4 = sVar4 + 0x10;
  } while (iVar7 < 6);
  bVar3 = 5;
  obj->x = sVar1;
  obj->y = sVar8;
  if (obj->var != 0) {
    bVar3 = 4;
  }
  obj->state = bVar3;
  return;
}


