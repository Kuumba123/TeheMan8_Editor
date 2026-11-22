// T4_1B, STAGE05.BIN, handler 0x801E8A78. Ghidra output with the object struct applied; not matching C.
// ---- 801e8a78 FUN_801e8a78

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8a78(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  bool bVar3;
  undefined1 uVar4;
  
  uVar4 = 0x40;
  switch(obj->state) {
  case 0:
    if ((DAT_8015e26f & 0x80) != 0) {
      if (((obj->var & 0x80) == 0) && ((obj->var & 1) == 0)) {
        uVar4 = 0;
      }
      *(undefined1 *)((int)&obj->speed_x + 3) = 0x1e;
      DAT_8015e2af = 1;
      DAT_8015e2b9 = 1;
      DAT_8015e2ba = 1;
      DAT_801b2992 = 1;
      DAT_801b2993 = 1;
      FUN_801119e0((int)obj->x,uVar4);
      sVar2 = obj->x;
      *(undefined1 *)((int)&obj->speed_x + 2) = uVar4;
      obj->state = 1;
      *(short *)&obj->speed_x = sVar2;
    }
    break;
  case 1:
    if (*(char *)((int)&obj->speed_x + 2) == '\0') {
      bVar3 = (short)obj->speed_x < DAT_8015e248._2_2_;
    }
    else {
      bVar3 = DAT_8015e248._2_2_ < (short)obj->speed_x;
    }
    if (!bVar3) {
      *(undefined1 *)((int)&obj->speed_x + 3) = 0x1e;
      obj->state = 2;
      FUN_801e9024(obj,0x40);
    }
    break;
  case 2:
    DAT_8015e241 = 0;
    cVar1 = *(char *)((int)&obj->speed_x + 3);
    *(char *)((int)&obj->speed_x + 3) = cVar1 + -1;
    if (cVar1 == '\0') {
      FUN_80102e84(7);
      obj->state = 3;
    }
    break;
  case 3:
    if (DAT_8015d226 == '\0') {
      FUN_801e8c9c(obj->var);
      FUN_80102e84(6);
      FUN_801119e0((int)DAT_8015e248._2_2_,0x40);
      DAT_8015e241 = 1;
      obj->state = 4;
    }
    break;
  case 4:
    if (DAT_8015d226 == '\0') {
      FUN_80111918();
      DAT_8015e2af = 0;
      DAT_8015e2b9 = 0;
      DAT_8015e2ba = 0;
      DAT_801b2993 = 0;
      DAT_801b2992 = 0;
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801e8c9c FUN_801e8c9c

void FUN_801e8c9c(byte param_1)

{
  int iVar1;
  undefined1 *puVar2;
  byte bVar3;
  char *pcVar4;
  
  if (param_1 == 0xff) {
    bVar3 = 5;
  }
  else {
    bVar3 = param_1;
    if ((param_1 & 0x80) != 0) {
      bVar3 = 4;
    }
  }
  iVar1 = (uint)bVar3 * 0x18;
  DAT_801b29a0 = 0;
  DAT_801b29a1 = 0;
  DAT_801b29a2 = 0;
  DAT_801b29a3 = 0;
  DAT_801b29a4 = 0;
  DAT_801b29a5 = 0;
  DAT_801b29a6 = 1;
  DAT_801d2918._1_1_ = (&UNK_801ead01)[iVar1];
  DAT_801d2915 = (&UNK_801ead02)[iVar1];
  DAT_801d2944 = (&UNK_801ead03)[iVar1];
  DAT_801d2974 = (&UNK_801ead04)[iVar1];
  DAT_801c3375 = (&UNK_801ead05)[iVar1];
  DAT_801c3376 = (&UNK_801ead06)[iVar1];
  DAT_801c3377 = (&UNK_801ead07)[iVar1];
  DAT_8015e248._2_2_ = *(undefined2 *)(&UNK_801ead08 + iVar1);
  DAT_8015e24c._2_2_ = *(undefined2 *)(&UNK_801ead0a + iVar1);
  DAT_801d2918._2_2_ = *(undefined2 *)(&UNK_801ead0c + iVar1);
  g_cam_y = *(undefined2 *)(&UNK_801ead0e + iVar1);
  DAT_801d2928 = *(undefined2 *)(&UNK_801ead10 + iVar1);
  DAT_801d2930 = *(undefined2 *)(&UNK_801ead10 + iVar1);
  DAT_801d2926 = *(undefined2 *)(&UNK_801ead12 + iVar1);
  DAT_801d292e = *(undefined2 *)(&UNK_801ead12 + iVar1);
  DAT_801d292c = *(undefined2 *)(&UNK_801ead14 + iVar1);
  DAT_801d2934 = *(undefined2 *)(&UNK_801ead14 + iVar1);
  DAT_801d292a = *(undefined2 *)(&UNK_801ead16 + iVar1);
  DAT_801d2932 = *(undefined2 *)(&UNK_801ead16 + iVar1);
  if (param_1 == 0x81) {
    pcVar4 = &DAT_801cf540;
    do {
      if ((*pcVar4 != '\0') && (pcVar4[6] == '&')) {
        Obj_Free(pcVar4);
      }
      pcVar4 = pcVar4 + 0x18;
    } while (pcVar4 < &DAT_801cf840);
    goto LAB_801e8fcc;
  }
  if (param_1 < 0x82) {
    if (param_1 == 1) {
      puVar2 = (undefined1 *)Obj_AllocType4();
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x26;
        puVar2[7] = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        puVar2[4] = 0;
      }
      goto LAB_801e8fcc;
    }
    if (param_1 != 3) goto LAB_801e8fcc;
    FUN_80102ef4((byte)(&DAT_801eacf4)[(uint)DAT_801c337a * 2] + 0x2d,0xd80,0xa50);
    FUN_80102ef4((byte)(&DAT_801eacf5)[(uint)DAT_801c337a * 2] + 0x2d,0xee0,0xa50);
    FUN_80102ef4(0x30 - ((uint)(byte)(&DAT_801eacf4)[(uint)DAT_801c337a * 2] +
                        (uint)(byte)(&DAT_801eacf5)[(uint)DAT_801c337a * 2]),0xff0,0xa50);
    FUN_8010bb88(0,0xffffffe4);
  }
  else {
    if (param_1 == 0x82) {
      FUN_801061dc(&DAT_80171c3c,&DAT_80190040,0x1e000);
      goto LAB_801e8fcc;
    }
    if (param_1 != 0x83) goto LAB_801e8fcc;
    FUN_8010bbb8();
  }
  DAT_801b29a7 = 0;
LAB_801e8fcc:
  iVar1 = 0;
  do {
    FUN_80103638(iVar1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  FUN_80101dbc();
  FUN_80101bf0();
  FUN_801032b0();
  FUN_8011c504();
  return;
}


// ---- 801e9024 FUN_801e9024

void FUN_801e9024(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_8012c108(param_1,0,0,0,0,1);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x27) = 0x91;
    *(undefined1 *)(iVar1 + 0x33) = 9;
    *(undefined1 *)(iVar1 + 7) = 0;
    *(undefined1 *)(iVar1 + 0x26) = 5;
    *(undefined4 *)(iVar1 + 0xc) = DAT_8015e248;
    *(undefined4 *)(iVar1 + 0x10) = DAT_8015e24c;
    *(undefined1 *)(iVar1 + 0x25) = *(undefined1 *)(param_1 + 0x16);
    FUN_800fd100(0x11f);
  }
  return;
}


