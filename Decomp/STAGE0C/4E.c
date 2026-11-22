// ID 4E, STAGE0C.BIN, handler 0x801DF454. Ghidra output with the object struct applied; not matching C.
// ---- 801df454 FUN_801df454

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df454(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->invuln = 0;
  obj->clut = bVar1;
  (*(code *)(&PTR_FUN_801eadbc)[obj->state])();
  obj->invuln = 1;
  if (obj->active != 0) {
    if (DAT_801b29a7 != '\0') {
      obj->clut = 0;
    }
    if (obj->field_0x51 == '\0') {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801df4f0 FUN_801df4f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df4f0(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  undefined1 *puVar4;
  char cVar5;
  int iVar6;
  
  Enemy_InitFromTable();
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->dmg_table = 0x20;
  switch(obj->var) {
  case 0:
    iVar6 = 0;
    obj->draw_list = 9;
    obj->field_0x51 = 1;
    obj->hitbox = (byte *)0x0;
    obj->flip = 0;
    obj->field_0x55 = 0;
    obj->field_0x5a = 5;
    obj->x = (obj->x & 0xfff0U) - 4;
    do {
      puVar4 = (undefined1 *)FUN_801055e4(obj);
      if (puVar4 != (undefined1 *)0x0) {
        puVar4[6] = 0x4e;
        *puVar4 = 1;
        puVar4[7] = 1;
        puVar4[0x52] = (char)iVar6;
        puVar4[0x53] = (char)(iVar6 / 3);
        cVar5 = (&DAT_801ead2c)[iVar6 % 3];
        sVar2 = obj->x;
        *(undefined2 *)(puVar4 + 0x12) = 0xcb8;
        *(short *)(puVar4 + 0xe) = cVar5 + sVar2;
        bVar1 = obj->flip;
        iVar6 = iVar6 + 1;
        *(MM8Obj **)(puVar4 + 0x5c) = obj;
        puVar4[2] = 0;
        puVar4[0x57] = 0;
        puVar4[0x25] = bVar1;
      }
    } while (iVar6 < 0xc);
    do {
      do {
        puVar4 = (undefined1 *)FUN_801055e4(obj);
      } while (puVar4 == (undefined1 *)0x0);
      *puVar4 = 1;
      puVar4[6] = 0x4e;
      puVar4[7] = 3;
      *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&obj->x_frac;
      *(undefined4 *)(puVar4 + 0x10) = *(undefined4 *)&obj->y_frac;
      bVar1 = obj->flip;
      *(MM8Obj **)(puVar4 + 0x5c) = obj;
      puVar4[0x25] = bVar1;
    } while (puVar4 == (undefined1 *)0x0);
    obj->state = 1;
    obj->sub2 = 0;
    DAT_801b29a0 = 0;
    DAT_801b29a1 = 0;
    DAT_801b29a2 = 0;
    DAT_801b29a4 = 0;
    DAT_801b29a5 = 0;
    DAT_801b29a7 = 0;
    Anim_Set(obj,3);
    obj->contact_dmg = 4;
    obj->hp = 0;
    return;
  case 1:
    obj->state = 2;
    obj->hitbox = &DAT_801eacc0;
    obj->hp = 1;
    obj->contact_dmg = 4;
                    /* Possible PsyQ macro: setPolyGT3() */
    switch(obj->sub2) {
    case 0:
      cVar5 = '\x0e';
      obj->field_0x51 = 1;
      obj->draw_list = 9;
      break;
    case 1:
      cVar5 = ' ';
      obj->field_0x51 = 1;
      obj->draw_list = obj->field_0x50 + 8;
      break;
    case 2:
      cVar5 = '\v';
      obj->field_0x51 = 0;
      obj->draw_list = obj->field_0x50 + 8;
      obj->y = obj->y + -0x14;
      break;
    case 3:
      obj->field_0x51 = 0;
      if (obj->field_0x55 == '\0') {
        obj->draw_list = 9;
        cVar5 = '\v';
      }
      else {
        obj->draw_list = 8;
        cVar5 = '\x10';
      }
      break;
    default:
      goto switchD_801df540_default;
    case 5:
      cVar5 = '\v';
      obj->field_0x51 = 0;
      obj->draw_list = 4;
    }
    break;
  case 2:
    bVar1 = obj->sub2;
    obj->hp = 1;
    obj->contact_dmg = 3;
    obj->state = 3;
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
    obj->dmg_table = 0;
    obj->hitbox = (byte *)0x0;
    if (bVar1 == 1) {
      obj->field_0x51 = 0;
      obj->draw_list = 7;
      Anim_SetAtStep(obj,0x18,2);
      return;
    }
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      cVar5 = '\x15';
      obj->field_0x51 = 0;
      obj->draw_list = 7;
    }
    else {
      if (6 < bVar1) {
        return;
      }
      if (bVar1 < 4) {
        return;
      }
      cVar5 = '\x15';
      obj->field_0x51 = 0;
      obj->draw_list = 7;
    }
    break;
  case 3:
    cVar5 = '/';
    obj->state = 4;
    obj->field_0x51 = 1;
    obj->hitbox = (byte *)0x0;
    obj->sub2 = 0;
    obj->draw_list = 6;
    break;
  case 4:
    obj->field_0x51 = 1;
    obj->hp = 1;
    obj->contact_dmg = 6;
    obj->state = 5;
    obj->sub2 = 0;
    if (obj->field_0x53 == '\0') {
      obj->draw_list = 7;
    }
    else {
      obj->draw_list = 5;
    }
    uVar3 = obj->x;
    obj->hitbox = (byte *)0x0;
    cVar5 = obj->field_0x53 + '&';
    goto LAB_801df928;
  case 5:
    cVar5 = '!';
    obj->field_0x51 = 1;
    obj->hp = 1;
    obj->contact_dmg = 5;
    obj->state = 6;
    uVar3 = obj->x;
    obj->sub2 = 0;
    obj->draw_list = 9;
    obj->hitbox = (byte *)0x0;
LAB_801df928:
    obj->x = (uVar3 & 0xfff0) + 4;
    break;
  default:
    goto switchD_801df540_default;
  }
  Anim_Set(obj,cVar5);
switchD_801df540_default:
  return;
}


// ---- 801df95c FUN_801df95c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df95c(MM8Obj *obj)

{
  DAT_801b29a7 = 0;
  (**(code **)(&DAT_801eadd8 + (uint)obj->sub2 * 4))();
  return;
}


// ---- 801df9a0 FUN_801df9a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df9a0(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801eadf8)[obj->sub3])();
  return;
}


// ---- 801dff34 FUN_801dff34

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dff34(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyF4() */
  (*(code *)(&PTR_FUN_801eae14)[obj->sub3])();
  return;
}


// ---- 801dff70 FUN_801dff70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dff70(MM8Obj *obj)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  if (obj->field_0x4 == '\0') {
    Anim_Set(obj,0);
    obj->field_0x4 = 1;
    if (obj->flip == 0) {
      uVar1 = 10;
      if (DAT_8015e248._2_2_ <= obj->x) {
        uVar1 = 0xff;
      }
    }
    else {
      uVar1 = 10;
      if (obj->x <= DAT_8015e248._2_2_) {
        uVar1 = 0xff;
      }
    }
    obj->field_0x59 = uVar1;
    obj->field_0x56 = 0;
    DAT_801b29a4 = 0x81;
    DAT_801b29a5 = 0;
  }
  obj->hitbox = &UNK_801eac58 + (uint)DAT_801b29a0 * 4;
  iVar2 = FUN_801e5380(obj);
  if (iVar2 != 0) {
    Anim_Set(obj,2);
    DAT_801b29a4 = 0x83;
    obj->field_0x56 = obj->field_0x56 + (char)iVar2;
    obj->field_0x54 = 0;
    obj->field_0x50 = 0x30;
    if (0xc < (byte)obj->field_0x56) {
      obj->field_0x56 = 0xc;
    }
  }
  obj->hitbox = &DAT_801eac8c + (uint)DAT_801b29a0 * 4;
  iVar2 = FUN_801e5380(obj);
  obj->hitbox = &DAT_801ead28;
  iVar3 = FUN_801e5380(obj);
  if (iVar2 + iVar3 != 0) {
    Anim_Set(obj,2);
    DAT_801b29a4 = 0x83;
  }
  if (obj->field_0x56 != '\0') {
    if ((obj->field_0x4 == '\x01') && (DAT_801b29a0 == 0xc)) {
      obj->sub3 = 1;
      obj->field_0x50 = 0x40;
      obj->field_0x4 = 0;
      obj->field_0x58 = 4;
      return;
    }
    if (DAT_801b29a0 < (byte)obj->field_0x56) {
      if (obj->field_0x54 == '\0') {
        DAT_801b29a0 = DAT_801b29a0 + 1;
        obj->field_0x54 = 5;
      }
      else {
        obj->field_0x54 = obj->field_0x54 + -1;
      }
    }
    else if (obj->field_0x50 == '\0') {
      DAT_801b29a0 = DAT_801b29a0 - 1;
      obj->field_0x56 = DAT_801b29a0;
      obj->field_0x50 = 5;
      if (obj->field_0x4 == '\x02') {
        obj->field_0x4 = 1;
      }
      if (DAT_801b29a0 == 0) {
        Anim_Set(obj,0);
        DAT_801b29a4 = 0x81;
      }
    }
    else {
      obj->field_0x50 = obj->field_0x50 + -1;
    }
  }
  if (obj->field_0x59 == '\0') {
    if (DAT_801b29a0 == 0) {
      obj->sub2 = 2;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      DAT_801b29a0 = 0;
      DAT_801b29a1 = 1;
      DAT_801b29a4 = 0;
    }
    else {
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
  }
  else {
    obj->field_0x59 = obj->field_0x59 + -1;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e02a0 FUN_801e02a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e02a0(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if ((obj->field_0x59 == '\0') || (obj->field_0x58 == '\0')) {
    if (DAT_801b29a2 == '\0') {
      obj->sub3 = 3;
      obj->field_0x4 = 0;
      DAT_801b29a5 = 1;
      return;
    }
  }
  else {
    obj->field_0x59 = obj->field_0x59 + -1;
    if ((DAT_801b29a2 == '\0') &&
       (obj->hitbox = &UNK_801eac58 + (uint)DAT_801b29a0 * 4, g_player != '\0')) {
      cVar1 = Enemy_CheckWeaponHits(obj);
      if (cVar1 == '\x02') {
        DAT_801b29a2 = '\x01';
        DAT_801b29a7 = 1;
        DAT_801b29a1 = DAT_80158f5c;
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
        obj->field_0x58 = obj->field_0x58 + -1;
      }
      else if (cVar1 == '\x04') {
        Anim_Set(obj,0x28);
        DAT_801b29a0 = 0;
        DAT_801b29a1 = 0;
        DAT_801b29a2 = '\0';
        DAT_801b29a4 = 0;
        DAT_801b29a5 = 0;
        obj->sub2 = 7;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
        FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
        FUN_800fcd84();
        DAT_8015e2af = 1;
        DAT_801b2992 = 1;
        DAT_801b2993 = 1;
        DAT_801b2994 = 1;
        goto LAB_801e0494;
      }
    }
  }
  obj->hitbox = &DAT_801eac8c + (uint)DAT_801b29a0 * 4;
  iVar2 = FUN_801e5380(obj);
  obj->hitbox = &DAT_801ead28;
  iVar3 = FUN_801e5380(obj);
  if (iVar2 + iVar3 != 0) {
    Anim_Set(obj,2);
    DAT_801b29a4 = 0x83;
  }
LAB_801e0494:
  Anim_Step(obj);
  return;
}


// ---- 801e04b4 FUN_801e04b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e04b4(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  obj->hitbox = &DAT_801eac8c + (uint)DAT_801b29a0 * 4;
  iVar1 = FUN_801e5380();
  obj->hitbox = &DAT_801ead28;
  iVar2 = FUN_801e5380(obj);
  if (iVar1 + iVar2 != 0) {
    Anim_Set(obj,2);
    DAT_801b29a4 = 0x83;
  }
  if (obj->field_0x50 == '\0') {
    DAT_801b29a0 = DAT_801b29a0 - 1;
    obj->field_0x56 = DAT_801b29a0;
    obj->field_0x50 = 3;
    if (obj->field_0x4 == '\x02') {
      obj->field_0x4 = 1;
    }
    if (DAT_801b29a0 == 0) {
      Anim_Set(obj,0);
      obj->sub2 = 2;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      DAT_801b29a0 = 0;
      DAT_801b29a1 = 1;
      DAT_801b29a4 = 0;
    }
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e05e4 FUN_801e05e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e05e4(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  obj->hitbox = &DAT_801eac8c;
  iVar1 = FUN_801e5380();
  obj->hitbox = &DAT_801ead28;
  iVar2 = FUN_801e5380(obj);
  if (iVar1 + iVar2 != 0) {
    Anim_Set(obj,2);
    DAT_801b29a4 = 0x83;
  }
  if (DAT_801b29a5 == '\0') {
    Anim_Set(obj,0);
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    DAT_801b29a0 = 0;
    DAT_801b29a1 = 1;
    DAT_801b29a4 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e06a8 FUN_801e06a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e06a8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eae24)[obj->sub3])();
  return;
}


// ---- 801e06e4 FUN_801e06e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e06e4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  obj->hitbox = &DAT_801eac8c;
  iVar2 = FUN_801e5380();
  obj->hitbox = &DAT_801ead28;
  iVar3 = FUN_801e5380(obj);
  if (obj->field_0x4 == '\0') {
    if (iVar2 + iVar3 != 0) {
      Anim_Set(obj,2);
    }
    if (DAT_801b29a0 == '\x01') {
      DAT_801b29a1 = 0;
      Anim_Set(obj,1);
      obj->field_0x50 = 0;
      obj->field_0x4 = 1;
    }
  }
  else if (((short)obj->frame < 0) &&
          (bVar1 = obj->field_0x50 + 1, obj->field_0x50 = bVar1, 2 < bVar1)) {
    DAT_801b29a0 = '\x02';
    obj->y = obj->y + -0x14;
    Anim_Set(obj,8);
    obj->sub3 = 1;
    obj->field_0x50 = 5;
    obj->field_0x4 = 0;
                    /* Possible PsyQ macro: setPolyG3() */
    obj->hitbox = &DAT_801ead24;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e0804 FUN_801e0804

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0804(MM8Obj *obj)

{
  FUN_801e5380();
  if (obj->field_0x4 == '\0') {
    if (obj->field_0x50 != '\0') {
                    /* Probable PsyQ macro: setTile() */
      obj->field_0x50 = obj->field_0x50 + -1;
      return;
    }
                    /* Probable PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      Anim_Set(obj,7);
      obj->field_0x4 = 1;
    }
  }
  else if (obj->field_0x4 == '\x01') {
    if (((short)obj->frame < 0) && (obj->anim_timer != 0)) {
      Anim_Set(obj,5);
                    /* Possible PsyQ macro: setPolyF3() */
      FUN_8010544c(obj,0x1bd);
      DAT_801b29a5 = '\x01';
      obj->field_0x4 = 2;
    }
  }
  else if (DAT_801b29a5 == '\0') {
    Anim_Set(obj,9);
    obj->field_0x50 = 0xf;
    obj->sub3 = 2;
    obj->field_0x4 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e0920 FUN_801e0920

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0920(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  undefined1 *puVar3;
  int iVar4;
  
  cVar1 = obj->field_0x50;
  obj->field_0x50 = cVar1 + -1;
  if (cVar1 == '\0') {
    iVar4 = 0;
                    /* Possible PsyQ macro: setPolyG3() */
    DAT_801b29a0 = 0;
    DAT_801b29a1 = 0;
    DAT_801b29a2 = 0;
    DAT_801b29a5 = 1;
    do {
      puVar3 = (undefined1 *)FUN_801055e4(obj);
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        puVar3[6] = 0x4e;
        puVar3[7] = 1;
        puVar3[0x52] = (char)iVar4;
        puVar3[0x53] = (char)((ulonglong)((longlong)iVar4 * 0x55555556) >> 0x20) -
                       (char)(iVar4 >> 0x1f);
        if (iVar4 == 3) {
          puVar3[0x55] = 1;
        }
        else {
          puVar3[0x55] = 0;
        }
                    /* Possible PsyQ macro: setPolyGT3() */
        *(short *)(puVar3 + 0xe) = (short)(char)(&DAT_801ead2c)[iVar4 % 3] + obj->x;
        *(undefined2 *)(puVar3 + 0x12) =
             *(undefined2 *)(&DAT_801ead30 + (uint)(byte)puVar3[0x53] * 2);
        bVar2 = obj->flip;
        iVar4 = iVar4 + 1;
        *(MM8Obj **)(puVar3 + 0x5c) = obj;
        puVar3[2] = 3;
        puVar3[0x25] = bVar2;
      }
    } while (iVar4 < 0xc);
    obj->sub3 = 3;
    obj->field_0x4 = 0;
    obj->field_0x51 = 1;
    FUN_8010544c(obj,0x1b4);
  }
  else {
    FUN_801e5380(obj);
    Anim_Step(obj);
  }
  return;
}


// ---- 801e0aa4 FUN_801e0aa4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0aa4(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  int iVar7;
  
  if (obj->field_0x4 == '\0') {
    if (DAT_801b29a5 != '\0') {
                    /* Possible PsyQ macro: setPolyF4() */
      iVar4 = (int)DAT_8015e248._2_2_ - (int)obj->x;
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
                    /* Possible PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setPolyGT4() */
      if ((short)iVar4 < 0x60) {
        iVar7 = 0;
      }
      else {
        iVar7 = 2;
        if ((short)iVar4 < 0xc0) {
          iVar7 = 1;
        }
      }
      bVar6 = obj->field_0x55;
      do {
        uVar5 = Rand();
        if (bVar6 >> 4 != (&DAT_801ead64)[(uVar5 & 0xf) + iVar7 * 0x10]) {
          obj->field_0x55 = (&DAT_801ead64)[(uVar5 & 0xf) + iVar7 * 0x10] << 4 | 1;
          goto LAB_801e0b88;
        }
      } while (2 < (obj->field_0x55 & 0xf));
      obj->field_0x55 = obj->field_0x55 + 1;
LAB_801e0b88:
      if ((obj->field_0x55 & 0xf0) == 0x10) {
        DAT_801b29a2 = 1;
        DAT_801b29a5 = '\f';
                    /* Possible PsyQ macro: setPolyGT4() */
        DAT_801b29a0 = 0;
        DAT_801b29a1 = '\0';
        DAT_801b29a4 = 0;
        if (DAT_8015e248._2_2_ < obj->x) {
          obj->flip = 0;
          obj->field_0x5a = 0;
        }
        else {
                    /* Possible PsyQ macro: setLineF2() */
          obj->flip = 0x40;
          obj->field_0x5a = 5;
        }
                    /* Possible PsyQ macro: setTile8() */
        uVar3 = (&DAT_801ead58)[(byte)obj->field_0x5a];
        obj->sub2 = 4;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
      }
      else {
        if (((0x13 < obj->hp) || (uVar5 = Rand(), (uVar5 & 3) != 3)) ||
           ((obj->field_0x5a != '\0' && (obj->field_0x5a != '\x05')))) {
          obj->field_0x50 = 5;
          obj->field_0x53 = 0;
          obj->field_0x4 = 1;
          DAT_801b29a0 = 0;
          DAT_801b29a1 = 0;
          return;
        }
        DAT_801b29a2 = 1;
        DAT_801b29a0 = 0;
        DAT_801b29a1 = '\0';
        DAT_801b29a4 = 0;
        DAT_801b29a5 = '\f';
        if (obj->field_0x5a == '\x05') {
          obj->flip = 0;
          obj->field_0x5a = 0;
        }
        else {
                    /* Possible PsyQ macro: setLineF2() */
          obj->flip = 0x40;
          obj->field_0x5a = 5;
        }
        uVar3 = (&DAT_801ead58)[(byte)obj->field_0x5a];
        obj->sub2 = 4;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
        obj->field_0x55 = 0x11;
      }
      obj->x = (uVar3 & 0xfff0) - 4;
    }
  }
  else if (obj->field_0x4 == '\x01') {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      DAT_801b29a0 = DAT_801b29a0 | '\x01' << ((byte)obj->field_0x53 & 0x1f);
      obj->field_0x53 = obj->field_0x53 + '\x01';
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x50 = 5;
      if (3 < (byte)obj->field_0x53) {
        obj->field_0x4 = 2;
      }
    }
  }
  else if (DAT_801b29a1 == '\f') {
    DAT_801b29a0 = 0;
    DAT_801b29a1 = '\0';
    DAT_801b29a2 = 0;
    DAT_801b29a4 = 0;
    DAT_801b29a5 = '\0';
    bVar6 = obj->field_0x55 & 0xf0;
    if (bVar6 == 0x20) {
      obj->sub2 = 5;
      obj->sub3 = 0;
      uVar5 = Rand();
      uVar2 = (&DAT_801eadac)[uVar5 & 0xf];
      obj->field_0x4 = 0;
      obj->field_0x58 = uVar2;
    }
    else if (bVar6 == 0x30) {
      obj->sub2 = 6;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
    else {
      FUN_801e5234(obj);
    }
  }
  return;
}


// ---- 801e0e54 FUN_801e0e54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0e54(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eae34)[obj->sub3])();
  return;
}


// ---- 801e0e90 FUN_801e0e90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0e90(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    puVar4 = (undefined1 *)FUN_801055e4(obj);
    if (puVar4 != (undefined1 *)0x0) {
      puVar4[6] = 0x4e;
      *puVar4 = 1;
      puVar4[7] = 1;
      puVar4[0x52] = (char)iVar5;
      puVar4[0x53] = (char)(iVar5 / 3);
      cVar1 = (&DAT_801ead2c)[iVar5 % 3];
      sVar3 = obj->x;
                    /* Possible PsyQ macro: setTile8() */
      *(undefined2 *)(puVar4 + 0x12) = 0xcb8;
      *(short *)(puVar4 + 0xe) = cVar1 + sVar3;
      bVar2 = obj->flip;
      iVar5 = iVar5 + 1;
      *(MM8Obj **)(puVar4 + 0x5c) = obj;
      puVar4[2] = 0;
      puVar4[0x57] = 1;
      puVar4[0x25] = bVar2;
    }
  } while (iVar5 < 0xc);
  obj->sub3 = 1;
  return;
}


// ---- 801e14a8 FUN_801e14a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e14a8(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801eae54)[obj->sub3])();
  return;
}


// ---- 801e161c FUN_801e161c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e161c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eae60)[obj->sub3])();
  return;
}


// ---- 801e1658 FUN_801e1658

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1658(MM8Obj *obj)

{
  undefined1 *puVar1;
  
  do {
    do {
      puVar1 = (undefined1 *)FUN_801055e4(obj);
    } while (puVar1 == (undefined1 *)0x0);
    puVar1[6] = 0x4e;
    puVar1[7] = 2;
    *puVar1 = 1;
    puVar1[2] = 5;
    if ((obj->field_0x58 & 0x80) == 0) {
      obj->field_0x58 = obj->field_0x58 | 0x80;
      if (DAT_8015e248._2_2_ < 0x1ab8) {
        *(undefined2 *)(puVar1 + 0xe) = 0x1a10;
        puVar1[0x25] = 0x40;
      }
      else {
        *(undefined2 *)(puVar1 + 0xe) = 0x1b50;
        puVar1[0x25] = 0;
      }
      *(undefined2 *)(puVar1 + 0x12) = 0xbf0;
      puVar1[0x57] = 0;
      obj->flip = puVar1[0x25];
    }
    else {
      if (obj->flip == 0) {
        *(undefined2 *)(puVar1 + 0xe) = 0x19e0;
        puVar1[0x25] = 0x40;
                    /* Possible PsyQ macro: setLineF2() */
        obj->flip = 0x40;
      }
      else {
        *(undefined2 *)(puVar1 + 0xe) = 0x1b80;
        puVar1[0x25] = 0;
        obj->flip = 0;
      }
      *(undefined2 *)(puVar1 + 0x12) = 0xc40;
      puVar1[0x57] = 1;
    }
    obj->field_0x58 = obj->field_0x58 + -1;
    *(MM8Obj **)(puVar1 + 0x5c) = obj;
    *(ushort *)(puVar1 + 0xe) = (*(ushort *)(puVar1 + 0xe) & 0xfff0) + 4;
    obj->sub3 = 1;
  } while (puVar1 == (undefined1 *)0x0);
  return;
}


// ---- 801e1788 FUN_801e1788

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1788(MM8Obj *obj)

{
  int iVar1;
  
  if (DAT_801b29a0 != '\0') {
    DAT_801b29a0 = '\0';
    DAT_801b29a1 = 0;
    DAT_801b29a2 = 0;
    DAT_801b29a4 = 0;
    DAT_801b29a5 = 0;
    if ((obj->field_0x58 & 0x7f) == 0) {
      iVar1 = 5;
      if (DAT_8015e248._2_2_ < 0x1ab8) {
        obj->flip = 0;
      }
      else {
        iVar1 = 0;
                    /* Possible PsyQ macro: setLineF2() */
        obj->flip = 0x40;
      }
      obj->field_0x5a = (char)iVar1;
      obj->x = (&DAT_801ead58)[iVar1];
      obj->y = 0xc68;
      obj->x = (obj->x & 0xfff0U) - 4;
      Anim_Set(obj,3);
      obj->sub2 = 3;
    }
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e1870 FUN_801e1870

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1870(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eae68)[obj->sub3])();
  return;
}


// ---- 801e18ac FUN_801e18ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e18ac(MM8Obj *obj)

{
  undefined1 *puVar1;
  
  do {
    do {
      puVar1 = (undefined1 *)FUN_801055e4(obj);
    } while (puVar1 == (undefined1 *)0x0);
    puVar1[6] = 0x4e;
    puVar1[7] = 2;
    puVar1[2] = 6;
    *puVar1 = 1;
    *(undefined2 *)(puVar1 + 0xe) = 0x1ab8;
    FUN_8010910c(puVar1);
    *(undefined2 *)(puVar1 + 0x12) = 0xbf0;
    *(MM8Obj **)(puVar1 + 0x5c) = obj;
    *(ushort *)(puVar1 + 0xe) = (*(ushort *)(puVar1 + 0xe) & 0xfff0) - 4;
    obj->sub3 = 1;
  } while (puVar1 == (undefined1 *)0x0);
  Anim_Set(obj,0x22);
  DAT_801b29a2 = obj->anim_extra;
  return;
}


// ---- 801e195c FUN_801e195c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e195c(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  DAT_801b29a2 = obj->anim_extra;
  if (DAT_801b29a0 != '\0') {
    DAT_801b29a0 = '\0';
    DAT_801b29a1 = 0;
    DAT_801b29a2 = 0;
    DAT_801b29a4 = 0;
    DAT_801b29a5 = 0;
    iVar1 = 0;
    if (DAT_8015e248._2_2_ < 0x1ab8) {
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
    }
    else {
      iVar1 = 5;
      obj->flip = 0;
    }
    obj->field_0x5a = (char)iVar1;
    obj->x = (&DAT_801ead58)[iVar1];
    obj->y = 0xc68;
    obj->x = (obj->x & 0xfff0U) - 4;
    Anim_Set(obj,3);
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e1a38 FUN_801e1a38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1a38(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eae70)[obj->sub3])();
  return;
}


// ---- 801e1a74 FUN_801e1a74

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1a74(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  
  switch(obj->field_0x4) {
  case 0:
    if ((-1 < (short)obj->frame) || (obj->anim_timer != 1)) break;
    Anim_Set(obj,0x29);
    FUN_8010544c(obj,0x1b5);
    obj->field_0x50 = 0x78;
    uVar3 = 1;
    goto LAB_801e1cf0;
  case 1:
    cVar2 = obj->field_0x50;
    obj->field_0x50 = cVar2 + -1;
    if (cVar2 == '\0') {
      obj->field_0x50 = 0x78;
      obj->field_0x4 = 2;
      DAT_801b29a7 = 0;
    }
    break;
  case 2:
    iVar7 = 0;
    if (obj->field_0x50 == '\0') {
      obj->field_0x51 = 1;
      obj->field_0x4 = 3;
      obj->field_0x50 = 0x78;
      DAT_801b29a7 = 0;
      do {
        puVar5 = (undefined1 *)FUN_801055e4(obj);
        if (puVar5 != (undefined1 *)0x0) {
          puVar5[6] = 0x4e;
          *puVar5 = 1;
          puVar5[7] = 1;
          puVar5[0x52] = (char)iVar7;
          puVar5[0x53] = (char)(iVar7 / 3);
          *(short *)(puVar5 + 0xe) = (short)(char)(&DAT_801ead2c)[iVar7 % 3] + obj->x;
          iVar7 = iVar7 + 1;
                    /* Possible PsyQ macro: setPolyF4() */
          *(undefined2 *)(puVar5 + 0x12) =
               *(undefined2 *)(&DAT_801ead30 + (uint)(byte)puVar5[0x53] * 2);
          bVar1 = obj->flip;
          *(MM8Obj **)(puVar5 + 0x5c) = obj;
          puVar5[2] = 5;
          puVar5[0x25] = bVar1;
        }
      } while (iVar7 < 0xc);
    }
    else {
      obj->field_0x50 = obj->field_0x50 + -1;
      DAT_801b29a7 = DAT_80170574 & 1;
      iVar7 = Obj_AllocMain();
      if (iVar7 != 0) {
        *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)&obj->x_frac;
        *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)&obj->y_frac;
        uVar4 = Rand();
        *(ushort *)(iVar7 + 0xe) = *(short *)(iVar7 + 0xe) + -0x20 + (uVar4 & 0x3f);
        uVar4 = Rand();
        uVar6 = _DAT_80170574 & 7;
        *(ushort *)(iVar7 + 0x12) = *(short *)(iVar7 + 0x12) + -0x20 + (uVar4 & 0x3f);
        if (uVar6 == 7) {
          FUN_80108e84(iVar7);
          FUN_8012ae08(iVar7,0x35);
        }
      }
    }
    break;
  case 3:
    cVar2 = obj->field_0x50;
    obj->field_0x50 = cVar2 + -1;
    if (cVar2 != '\0') break;
    uVar3 = 4;
    DAT_801b29a3 = 4;
LAB_801e1cf0:
    obj->field_0x4 = uVar3;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e1d20 FUN_801e1d20

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1d20(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  (*(code *)(&PTR_FUN_801eae74)[obj->sub2])();
  return;
}


// ---- 801e1d5c FUN_801e1d5c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1d5c(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801eae8c)[obj->sub3])();
  return;
}


// ---- 801e213c FUN_801e213c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e213c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eae98)[obj->sub3])();
  return;
}


// ---- 801e2178 FUN_801e2178

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2178(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x4 == '\0') {
    if (((int)(uint)DAT_801b29a0 >> ((byte)obj->field_0x52 & 0x1f) & 1U) != 0) {
      obj->field_0x51 = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    if (obj->field_0x4 == '\x01') {
      if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
        Anim_Set(obj,0xd);
        FUN_8010544c(obj,0x1b3);
        obj->field_0x4 = 2;
      }
    }
    else {
      iVar1 = FUN_801e5380(obj);
      if (iVar1 != 0) {
        Anim_Set(obj,0xb);
      }
    }
    if (DAT_801b29a0 == 0) {
      Anim_Set(obj,0x2d);
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801e2268 FUN_801e2268

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2268(MM8Obj *obj)

{
  FUN_801e5380();
  if (DAT_801b29a0 == '\0') {
    Anim_Step(obj);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e22bc FUN_801e22bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e22bc(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  (*(code *)(&PTR_FUN_801eaea0)[obj->sub3])();
                    /* Probable PsyQ macro: setPolyFT4() */
  return;
}


// ---- 801e22f8 FUN_801e22f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e22f8(MM8Obj *obj)

{
  int iVar1;
  
                    /* Possible PsyQ macro: setPolyGT4() */
  if (obj->field_0x4 == '\0') {
    if (((int)(uint)DAT_801b29a0 >> ((byte)obj->field_0x52 & 0x1f) & 1U) == 0) {
      Anim_Set(obj,0x2e);
      obj->field_0x4 = 1;
    }
    else {
      iVar1 = FUN_801e5380(obj);
      if (iVar1 != 0) {
        Anim_Set(obj,0xb);
      }
    }
  }
  else if ((short)obj->frame < 0) {
    Obj_Free(obj);
  }
  Anim_Step(obj);
  return;
}


// ---- 801e23a0 FUN_801e23a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e23a0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaea4)[obj->sub3])();
  return;
}


// ---- 801e23dc FUN_801e23dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e23dc(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
  if (obj->field_0x55 == '\0') {
    iVar3 = FUN_801e5380(obj);
    if (iVar3 == 0) goto LAB_801e2588;
    uVar5 = 0xb;
  }
  else {
    bVar2 = obj->field_0x4;
    if (bVar2 != 1) {
      if (1 < bVar2) {
        if (bVar2 == 2) {
          FUN_801e5380(obj);
          if (((obj->anim_extra != 0) && (obj->anim_timer == 1)) &&
             (puVar4 = (undefined1 *)FUN_801055e4(obj), puVar4 != (undefined1 *)0x0)) {
            *puVar4 = 1;
            puVar4[6] = 0x4e;
            puVar4[7] = 2;
            *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&obj->x_frac;
            *(undefined4 *)(puVar4 + 0x10) = *(undefined4 *)&obj->y_frac;
            puVar4[2] = 4;
            *(short *)(puVar4 + 0x12) = *(short *)(puVar4 + 0x12) + -0x2c;
            bVar2 = obj->flip;
            *(MM8Obj **)(puVar4 + 0x5c) = obj;
            puVar4[0x25] = bVar2;
            obj->field_0x4 = 3;
            FUN_8010544c(obj,0x1be);
          }
        }
        else if (((bVar2 == 3) && (FUN_801e5380(obj), (short)obj->frame < 0)) &&
                (obj->anim_timer == 1)) {
          obj->draw_list = 9;
          obj->field_0x55 = 0;
          obj->field_0x4 = 0;
        }
        goto LAB_801e2588;
      }
      if (bVar2 != 0) goto LAB_801e2588;
      obj->field_0x50 = 0xf;
      obj->field_0x4 = 1;
    }
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      Anim_Set(obj,0x13);
      obj->field_0x4 = 2;
      goto LAB_801e2588;
    }
    iVar3 = FUN_801e5380(obj);
    if (iVar3 == 0) goto LAB_801e2588;
    uVar5 = 0x10;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  Anim_Set(obj,uVar5);
LAB_801e2588:
  if (DAT_801b29a2 == '\0') {
    if (((int)(uint)DAT_801b29a0 >> ((byte)obj->field_0x53 & 0x1f) & 1U) != 0) {
      obj->sub3 = 1;
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->field_0x4 = 0;
      obj->speed_x = 0;
      obj->accel_x = 0;
      obj->speed_y_up = 0;
      obj->gravity = 0x2000;
      bVar2 = Rand();
      obj->field_0x50 = (bVar2 & 0x1f) + 5;
    }
    Anim_Step(obj);
  }
  else {
    obj->sub2 = 4;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    DAT_801b29a5 = DAT_801b29a5 + -1;
  }
  return;
}


// ---- 801e2634 FUN_801e2634

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2634(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x4 == '\0') {
    if (obj->field_0x50 == '\0') {
      FUN_80104ccc();
      if (obj->speed_y_up < -0x30000) {
        obj->speed_y_up = -0x30000;
      }
                    /* Possible PsyQ macro: setTile8() */
      iVar1 = FUN_801e5380(obj);
      if (iVar1 != 0) {
        Anim_Set(obj,0xb);
      }
      if (0xcab < obj->y) {
        obj->y = 0xcb8;
        Anim_Set(obj,0x14);
        FUN_8010544c(obj,0x1b9);
        obj->field_0x4 = 1;
      }
    }
    else {
      obj->field_0x50 = obj->field_0x50 + -1;
      iVar1 = FUN_801e5380(obj);
      if ((iVar1 != 0) || (obj->field_0x50 == '\0')) {
        Anim_Set(obj,0xb);
      }
    }
  }
  else if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    DAT_801b29a1 = DAT_801b29a1 + '\x01';
    Obj_Free(obj);
  }
  Anim_Step(obj);
  return;
}


// ---- 801e276c FUN_801e276c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e276c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaeac)[obj->sub3])();
  return;
}


// ---- 801e27a8 FUN_801e27a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e27a8(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar1 = FUN_801e5380();
  if (iVar1 != 0) {
    Anim_Set(obj,0xb);
  }
  if (obj->field_0x4 == '\0') {
    obj->speed_y_up = -0x10000;
    FUN_80104d18(obj);
    iVar1 = (uint)*(ushort *)(&DAT_801ead30 + (uint)(byte)obj->field_0x53 * 2) +
            (3 - (uint)(byte)obj->field_0x53) * 4 + 0x14;
                    /* Possible PsyQ macro: setLineF2() */
    if (iVar1 * 0x10000 >> 0x10 < (int)obj->y) {
      obj->y = (short)iVar1;
      DAT_801b29a5 = DAT_801b29a5 + '\x01';
      Anim_Set(obj,0xb);
      obj->field_0x4 = 1;
    }
  }
  if ((DAT_801b29a0 & 0x80) != 0) {
    puVar3 = &DAT_801ead94;
    iVar1 = *(int *)&obj->field_0x5c;
    if (*(char *)(iVar1 + 0x25) == '@') {
      puVar3 = &DAT_801eada0;
    }
    if ((byte)obj->field_0x52 + 1 == (uint)(byte)puVar3[DAT_801b29a0 & 0xf]) {
      Anim_Set(obj,0xb);
      iVar2 = 0x30000;
      if ((DAT_801b29a0 & 1) != 0) {
        iVar2 = 0x40000;
      }
      if (*(char *)(iVar1 + 0x25) == '\0') {
        iVar2 = -iVar2;
      }
      obj->speed_x = iVar2;
      obj->accel_x = 0;
      obj->speed_y_up = 0;
      obj->gravity = 0;
      obj->sub3 = 1;
      obj->field_0x4 = 0;
      FUN_8010544c(obj,0x1b3);
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801e2930 FUN_801e2930

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2930(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x5c;
  iVar1 = FUN_801e5380();
  if (iVar1 != 0) {
    Anim_Set(obj,0xb);
  }
  if (obj->field_0x4 == '\0') {
    FUN_80104d00(obj);
    iVar1 = (int)*(short *)(iVar2 + 0xe) +
            (int)(char)(&DAT_801ead2c)[(uint)(byte)obj->field_0x52 % 3];
    if (*(char *)(iVar2 + 0x25) == '\0') {
      if (iVar1 < obj->x) goto LAB_801e2acc;
      obj->x = (short)iVar1;
      Anim_Set(obj,0xb);
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
    }
    else {
      if (obj->x < iVar1) goto LAB_801e2acc;
      obj->x = (short)iVar1;
      Anim_Set(obj,0xb);
      obj->flip = 0;
    }
    DAT_801b29a1 = DAT_801b29a1 + '\x01';
    obj->field_0x4 = 1;
  }
  else if (DAT_801b29a1 == '\f') {
    obj->speed_y_up = 0x10000;
    FUN_80104d18(obj);
    if (obj->y < *(short *)(&DAT_801ead30 + (uint)(byte)obj->field_0x53 * 2)) {
      obj->y = *(short *)(&DAT_801ead30 + (uint)(byte)obj->field_0x53 * 2);
      obj->sub3 = 2;
      obj->field_0x4 = 0;
      Anim_Set(obj,0xb);
      DAT_801b29a5 = DAT_801b29a5 + -1;
    }
  }
LAB_801e2acc:
  Anim_Step(obj);
  return;
}


// ---- 801e2aec FUN_801e2aec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2aec(MM8Obj *obj)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_801e5380();
  if (iVar2 != 0) {
    Anim_Set(obj,0xb);
  }
  if (DAT_801b29a1 == '\0') {
    Anim_Set(obj,0xc);
    obj->sub3 = 2;
    obj->field_0x57 = 1;
    obj->field_0x54 = 1;
    obj->sub2 = 0;
    obj->field_0x4 = 0;
    obj->field_0x50 = 10;
    uVar1 = FUN_80104db0((int)obj->x,(int)obj->y,
                         ((int)obj->x - (int)(char)(&DAT_801ead2c)[(uint)(byte)obj->field_0x52 % 3])
                         * 0x10000 >> 0x10,0xc68);
    if (((obj->field_0x53 != '\0') && (obj->field_0x53 != '\x03')) ||
       (uVar3 = 0x200, (uint)(byte)obj->field_0x52 % 3 == 0)) {
      uVar3 = 0x100;
    }
    FUN_80105120(obj,uVar3,uVar1);
  }
  Anim_Step(obj);
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801e2c2c FUN_801e2c2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2c2c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaeb8)[obj->sub3])();
  return;
}


// ---- 801e2c68 FUN_801e2c68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2c68(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  
  if (obj->field_0x4 == '\0') {
    uVar3 = Rand();
    uVar4 = Rand();
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x55 =
         (char)(uVar3 & 0xf) + (char)((uVar3 & 0xf) / 0xe) * -0xe +
         (char)(uVar4 & 0xf) + (char)((uVar4 & 0xf) / 6) * -6 + '\x01';
    bVar1 = obj->field_0x55;
    iVar5 = Obj_AllocType3();
    if (iVar5 != 0) {
      *(ushort *)(iVar5 + 0xe) = (ushort)bVar1 * 0x10 + 0x1a0c;
      *(undefined2 *)(iVar5 + 0x12) = 0xcac;
      FUN_801051d8(obj,iVar5,0x60000,0x4000);
      obj->field_0x4 = 1;
    }
  }
  else if (obj->field_0x4 == '\x01') {
    Obj_ApplySpeed(obj);
    if (0xcac < obj->y) {
      obj->y = 0xcb8;
      uVar6 = obj->x + 4;
      if ((uVar6 & 0xf) < 8) {
        sVar2 = (uVar6 & 0xfff0) - 4;
      }
      else {
        sVar2 = (uVar6 & 0xfff0) + 0xc;
      }
      obj->x = sVar2;
      Anim_Set(obj,0x14);
      FUN_8010544c(obj,0x1b9);
      obj->field_0x4 = 2;
    }
  }
  else if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Obj_Free(obj);
    return;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e2e18 FUN_801e2e18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2e18(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaebc)[obj->sub2])();
                    /* Possible PsyQ macro: setTile8() */
  if ((obj->field_0x51 == '\0') &&
     (obj->hitbox = &UNK_801eacc4 + (uint)obj->anim_extra * 4, obj->anim_extra != 0)) {
    Enemy_ContactDamage(obj);
    Enemy_CheckWeaponHits(obj);
  }
  return;
}


// ---- 801e2ea0 FUN_801e2ea0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2ea0(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyFT4() + setSemiTrans(polyFT4, 1) */
  (*(code *)(&PTR_FUN_801eaed8)[obj->sub3])();
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801e2ef0 FUN_801e2ef0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2ef0(MM8Obj *obj)

{
  undefined1 uVar1;
  int iVar2;
  
  obj->gravity = 0x2000 << ((byte)obj->field_0x57 & 0x1f);
  FUN_80104ccc();
  iVar2 = -0x20000 << ((byte)obj->field_0x57 & 0x1f);
  if (obj->speed_y_up < iVar2) {
    obj->speed_y_up = iVar2;
  }
  if (0xc67 < obj->y) {
    uVar1 = 1;
    if (obj->field_0x57 == '\0') {
      uVar1 = 4;
    }
    obj->field_0x54 = uVar1;
    obj->sub3 = 1;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801e2f84 FUN_801e2f84

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2f84(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  if (obj->field_0x4 != '\0') {
    if (obj->field_0x4 == '\x01') {
      if (DAT_801b29a0 == 0xff) {
        uVar2 = 0x19;
        if (obj->field_0x57 == '\0') {
          uVar2 = 0x32;
        }
        obj->field_0x50 = uVar2;
        obj->field_0x4 = 2;
      }
      cVar1 = obj->field_0x50;
      obj->field_0x50 = cVar1 + -1;
      if (cVar1 == '\0') {
        DAT_801b29a0 = DAT_801b29a0 | (byte)(1 << ((byte)obj->field_0x54 & 0x1f));
        obj->field_0x50 = (char)(0x19 >> ((byte)obj->field_0x57 & 0x1f));
        obj->field_0x54 = obj->field_0x54 + '\x01';
        if (DAT_801b29a0 != 0xff) {
          Anim_Set(obj,0x16);
          FUN_8010544c(obj,0x1b6);
        }
      }
    }
    else {
      cVar1 = obj->field_0x50;
      obj->field_0x50 = cVar1 + -1;
      if (cVar1 == '\0') {
        DAT_801b29a0 = 0;
        DAT_801b29a2 = 0;
        Anim_Set(obj,0x15);
        obj->sub3 = 2;
        obj->field_0x4 = 0;
      }
    }
    Anim_Step(obj);
    return;
  }
  FUN_80104ccc();
  iVar3 = obj->speed_y_up;
                    /* Possible PsyQ macro: setPolyGT4() */
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (0x20000 << ((byte)obj->field_0x57 & 0x1f) < iVar3) {
    obj->gravity = -obj->gravity;
    if (obj->field_0x54 == '\0') goto LAB_801e3008;
    obj->field_0x54 = obj->field_0x54 + -1;
  }
  if (obj->field_0x54 != '\0') {
    return;
  }
LAB_801e3008:
  iVar3 = obj->y + -0xc68;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (iVar3 < 3) {
    obj->y = 0xc68;
    obj->field_0x54 = 0;
    obj->field_0x4 = 1;
    obj->field_0x50 = (char)(0x19 >> ((byte)obj->field_0x57 & 0x1f));
    DAT_801b29a2 = 1;
    Anim_Set(obj,0x16);
    FUN_8010544c(obj,0x1b6);
  }
  return;
}


// ---- 801e3184 FUN_801e3184

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3184(MM8Obj *obj)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  
  iVar3 = *(int *)&obj->field_0x5c;
  sVar4 = *(short *)(iVar3 + 0xe) + 0x34;
  if ((*(byte *)(iVar3 + 0x25) & 0x40) == 0) {
    sVar4 = *(short *)(iVar3 + 0xe) + -0x34;
  }
  if (DAT_801b29a0 != '\0') {
    if (obj->field_0x4 == '\0') {
      obj->speed_y_up = 0;
      obj->gravity = 0;
      iVar2 = -0x40000;
      if ((*(byte *)(iVar3 + 0x25) & 0x40) != 0) {
        iVar2 = 0x40000;
      }
      obj->speed_x = iVar2;
      iVar2 = 0x4000;
      if ((*(byte *)(iVar3 + 0x25) & 0x40) != 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
        iVar2 = -0x4000;
      }
      obj->field_0x4 = 1;
      obj->accel_x = iVar2;
      obj->speed_x = obj->speed_x >> ((byte)obj->field_0x57 & 0x1f);
      obj->accel_x = obj->accel_x << ((byte)obj->field_0x57 & 0x1f);
    }
    else {
      FUN_80104c9c(obj);
                    /* Possible PsyQ macro: setTile8() */
      if ((((*(byte *)(iVar3 + 0x25) & 0x40) != 0) && (obj->x < sVar4)) ||
         ((*(char *)(iVar3 + 0x25) == '\0' && (sVar4 < obj->x)))) {
        uVar1 = *(undefined4 *)(iVar3 + 0xc);
        obj->x_frac = (short)uVar1;
        obj->x = (short)((uint)uVar1 >> 0x10);
        uVar1 = *(undefined4 *)(iVar3 + 0x10);
        obj->y_frac = (short)uVar1;
        obj->y = (short)((uint)uVar1 >> 0x10);
        obj->flip = *(byte *)(iVar3 + 0x25);
        Anim_Set(obj,0x17);
        DAT_801b29a1 = 1;
        obj->sub3 = 3;
        obj->field_0x4 = 0;
      }
    }
  }
  return;
}


// ---- 801e32fc FUN_801e32fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e32fc(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)&obj->field_0x5c;
  if (obj->field_0x4 == '\0') {
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      obj->flip = *(byte *)(iVar4 + 0x25);
      if (obj->field_0x57 == '\0') {
        uVar3 = 0x1a;
      }
      else {
        uVar3 = 0x18;
      }
      Anim_Set(obj,uVar3);
      obj->field_0x4 = 1;
    }
    goto LAB_801e34d0;
  }
  if (obj->field_0x4 != '\x01') {
    if (DAT_801b29a2 == '\0') {
      do {
        do {
          puVar2 = (undefined1 *)FUN_801055e4(obj);
        } while (puVar2 == (undefined1 *)0x0);
        *puVar2 = 1;
        puVar2[6] = 0x4e;
        puVar2[7] = 2;
        puVar2[0x25] = *(undefined1 *)(iVar4 + 0x25);
        *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
        uVar3 = *(undefined4 *)&obj->y_frac;
        *(int *)(puVar2 + 0x5c) = iVar4;
        puVar2[2] = 1;
        *(undefined4 *)(puVar2 + 0x10) = uVar3;
      } while (puVar2 == (undefined1 *)0x0);
      obj->sub2 = 2;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      uVar3 = *(undefined4 *)(iVar4 + 0xc);
      obj->x_frac = (short)uVar3;
      obj->x = (short)((uint)uVar3 >> 0x10);
      uVar3 = *(undefined4 *)(iVar4 + 0x10);
      obj->y_frac = (short)uVar3;
      obj->y = (short)((uint)uVar3 >> 0x10);
      bVar1 = *(byte *)(iVar4 + 0x25);
      obj->field_0x51 = 1;
      obj->field_0x54 = 0;
      obj->flip = bVar1;
      Anim_Set(obj,0x1b);
    }
    goto LAB_801e34d0;
  }
  if (DAT_801b29a2 != '\0') goto LAB_801e34d0;
  if (obj->field_0x57 == '\0') {
    if (obj->anim_extra != 0) {
      FUN_8010544c(obj,0x1b8);
    }
    if (obj->field_0x57 != '\0') goto LAB_801e33f0;
    if (obj->anim_extra == 0) goto LAB_801e34d0;
  }
  else {
LAB_801e33f0:
                    /* Possible PsyQ macro: setLineF2() + setSemiTrans(lineF2, 1) */
    if ((-1 < (short)obj->frame) || (obj->anim_timer != 1)) goto LAB_801e34d0;
  }
  DAT_801b29a2 = '\x01';
  obj->field_0x4 = 2;
LAB_801e34d0:
  Anim_Step(obj);
  return;
}


// ---- 801e34fc FUN_801e34fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e34fc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaee8)[obj->sub3])();
  return;
}


// ---- 801e3538 FUN_801e3538

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3538(MM8Obj *obj)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x5c;
  uVar1 = *(undefined4 *)(iVar2 + 0xc);
  obj->x_frac = (short)uVar1;
  obj->x = (short)((uint)uVar1 >> 0x10);
  uVar1 = *(undefined4 *)(iVar2 + 0x10);
  obj->y_frac = (short)uVar1;
  obj->y = (short)((uint)uVar1 >> 0x10);
  obj->flip = *(byte *)(iVar2 + 0x25);
  if (*(char *)(iVar2 + 0x47) == '\0') {
    Obj_Free();
  }
  else {
    if (obj->field_0x4 == '\0') {
      Anim_SetAtStep(obj,0x18,2);
      obj->field_0x4 = 1;
    }
    if ((DAT_801b29a0 == '\0') && (DAT_801b29a1 == '\x01')) {
      obj->sub2 = 3;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801e3600 FUN_801e3600

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3600(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  (*(code *)(&PTR_FUN_801eaeec)[obj->sub3])();
  return;
}


// ---- 801e363c FUN_801e363c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e363c(MM8Obj *obj)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
                    /* Possible PsyQ macro: setLineF2() */
  iVar3 = *(int *)&obj->field_0x5c;
  uVar1 = *(undefined4 *)(iVar3 + 0xc);
  obj->x_frac = (short)uVar1;
  obj->x = (short)((uint)uVar1 >> 0x10);
  uVar1 = *(undefined4 *)(iVar3 + 0x10);
  obj->y_frac = (short)uVar1;
  obj->y = (short)((uint)uVar1 >> 0x10);
  obj->flip = *(byte *)(iVar3 + 0x25);
                    /* Probable PsyQ macro: setTile8() */
  if (*(char *)(iVar3 + 0x47) == '\0') {
    obj->y = obj->y + -0x14;
    FUN_80108e84();
    FUN_8012a5fc(obj,0);
  }
  else {
    uVar4 = (uint)DAT_801b29a0;
    if (uVar4 != 0) {
      if (DAT_801b29a5 != '\0') {
        if (obj->field_0x4 == '\0') {
          Anim_Set(obj,0x1f);
          Anim_Step(obj);
          obj->field_0x4 = 1;
          obj->field_0x51 = 0;
          return;
        }
        if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
          DAT_801b29a5 = 0;
          obj->field_0x51 = 1;
          obj->field_0x4 = 0;
          return;
        }
        Anim_Step(obj);
        return;
      }
      if (DAT_801b29a2 != '\0') {
        if (DAT_801b29a2 == '\x01') {
          if (DAT_801b29a1 == '\v') {
            Anim_Set(obj,0x1e);
            puVar2 = (undefined1 *)Obj_AllocType3();
            if (puVar2 != (undefined1 *)0x0) {
              *puVar2 = 1;
              puVar2[6] = 0x3c;
              puVar2[7] = 0;
              puVar2[0x25] = obj->flip;
                    /* Possible PsyQ macro: setPolyF3() */
              *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
              uVar1 = *(undefined4 *)&obj->y_frac;
              puVar2[1] = 0;
              puVar2[2] = 0;
              *(undefined4 *)(puVar2 + 0x10) = uVar1;
            }
          }
          else {
            Anim_Set(obj,0x1d);
          }
          DAT_801b29a2 = '\x02';
        }
        else if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
          DAT_801b29a2 = '\0';
        }
        Anim_Step(obj);
        obj->field_0x51 = 0;
        return;
      }
      if (0xc < uVar4) {
        return;
      }
      Anim_SetAtStep(obj,0x1b,uVar4 - 1);
      obj->field_0x51 = 0;
      return;
    }
    obj->field_0x51 = 1;
    if (DAT_801b29a1 == '\0') {
      return;
    }
  }
  Obj_Free(obj);
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
  return;
}


// ---- 801e387c FUN_801e387c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e387c(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyGT4() */
  (*(code *)(&PTR_FUN_801eaef0)[obj->sub3])();
  return;
}


// ---- 801e38b8 FUN_801e38b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e38b8(MM8Obj *obj)

{
  undefined4 uVar1;
  int iVar2;
  
                    /* Possible PsyQ macro: setPolyF4() */
  iVar2 = *(int *)&obj->field_0x5c;
  uVar1 = *(undefined4 *)(iVar2 + 0xc);
  obj->x_frac = (short)uVar1;
  obj->x = (short)((uint)uVar1 >> 0x10);
  uVar1 = *(undefined4 *)(iVar2 + 0x10);
  obj->y_frac = (short)uVar1;
  obj->y = (short)((uint)uVar1 >> 0x10);
  obj->flip = *(byte *)(iVar2 + 0x25);
  if (DAT_801b29a0 == '\0') {
    if (obj->field_0x4 == '\0') {
      Anim_Set(obj,0x19);
      FUN_8010544c(obj,0x1b8);
      obj->field_0x4 = 1;
    }
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      DAT_801b29a0 = '\x01';
    }
    Anim_Step(obj);
  }
  else if (DAT_801b29a0 == '\x02') {
    obj->sub3 = 1;
    obj->field_0x4 = 0;
    obj->y = obj->y + 0x14;
    FUN_801e4e44(obj,1);
    DAT_801b29a0 = -1;
    DAT_801b29a5 = 0;
    obj->field_0x50 = 0;
  }
  return;
}


// ---- 801e3aec FUN_801e3aec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3aec(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaefc)[obj->sub3])();
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801e3b3c FUN_801e3b3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3b3c(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    obj->speed_y_up = 0x40000;
    obj->gravity = 0;
    obj->speed_x = 0;
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
    obj->accel_x = 0;
    obj->field_0x4 = 1;
  }
  FUN_80104d18(obj);
  if ((int)obj->y < g_cam_y + -0x20) {
    DAT_801b29a5 = 1;
    Obj_Free(obj);
  }
  return;
}


// ---- 801e3bbc FUN_801e3bbc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3bbc(MM8Obj *obj)

{
                    /* Probable PsyQ macro: setTile16() */
  (*(code *)(&PTR_FUN_801eaf00)[obj->sub3])();
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801e3c0c FUN_801e3c0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3c0c(MM8Obj *obj)

{
  short sVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  short sVar6;
  
  iVar5 = 0;
                    /* Possible PsyQ macro: setPolyGT4() */
  sVar6 = 0x1a10;
  do {
                    /* Possible PsyQ macro: setPolyGT4() */
    puVar3 = (undefined1 *)FUN_801055e4(obj);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar4 = (undefined1 *)FUN_801055e4(obj);
      if (puVar4 == (undefined1 *)0x0) {
        Obj_Free(puVar3);
      }
      else {
        puVar3[6] = 0x4e;
        puVar3[7] = 4;
        puVar3[0x25] = 0;
        *(short *)(puVar3 + 0xe) = sVar6;
        sVar1 = (short)iVar5 * 0x10;
        if (obj->flip == 0) {
          *(short *)(puVar3 + 0xe) = sVar1 + 0x1a30;
        }
        *(undefined2 *)(puVar3 + 0x12) = 0xcb8;
        puVar3[0x52] = (char)iVar5;
        puVar3[0x53] = 0;
        *(MM8Obj **)(puVar3 + 0x5c) = obj;
        *puVar4 = 1;
        puVar4[6] = 0x4e;
        puVar4[7] = 4;
        puVar4[0x25] = 0;
        *(short *)(puVar4 + 0xe) = sVar6;
        sVar6 = sVar6 + 0x10;
        if (obj->flip == 0) {
          *(short *)(puVar4 + 0xe) = sVar1 + 0x1a30;
        }
        puVar4[0x52] = (char)iVar5;
        iVar5 = iVar5 + 1;
        *(undefined2 *)(puVar4 + 0x12) = 0xcb8;
        puVar4[0x53] = 1;
        *(MM8Obj **)(puVar4 + 0x5c) = obj;
      }
    }
  } while (iVar5 < 0x13);
  if (obj->field_0x57 == '\0') {
    obj->sub3 = 1;
    uVar2 = 0x30;
  }
  else {
    obj->sub3 = 3;
    uVar2 = 1;
  }
  obj->field_0x50 = uVar2;
  obj->field_0x4 = 0;
  return;
}


// ---- 801e3d6c FUN_801e3d6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3d6c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->gravity = 0x4000;
      obj->speed_x = 0;
      obj->speed_y_up = 0;
      obj->accel_x = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104ccc(obj);
                    /* Possible PsyQ macro: setPolyGT4() */
    if (obj->field_0x4 == '\x01') {
      if (obj->speed_y_up < -0x60000) {
        obj->speed_y_up = -0x60000;
      }
      if (0xc40 < obj->y) {
        obj->gravity = -0x4000;
        obj->field_0x4 = 2;
      }
    }
    else if (obj->y < 0xc41) {
      obj->y = 0xc40;
      Anim_Set(obj,0x16);
      FUN_8010544c(obj,0x1b6);
      iVar3 = 0x40000;
      obj->sub3 = 2;
      obj->field_0x4 = 0;
      obj->speed_y_up = 0;
      obj->gravity = 0;
      if ((obj->flip & 0x40) != 0) {
        iVar3 = -0x40000;
      }
      iVar2 = -0x4000;
      obj->speed_x = iVar3;
      if ((obj->flip & 0x40) != 0) {
        iVar2 = 0x4000;
      }
      obj->accel_x = iVar2;
      obj->field_0x50 = 0;
      obj->field_0x54 = 0;
      FUN_8010544c(obj,0x1bc);
    }
  }
  return;
}


// ---- 801e3eb0 FUN_801e3eb0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3eb0(MM8Obj *obj)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  
  if (obj->field_0x4 == '\0') {
    if ((byte)obj->field_0x54 < 0x13) {
      if (obj->field_0x50 == '\0') {
        if ((obj->flip & 0x40) == 0) {
          bVar2 = 0x12 - obj->field_0x54;
        }
        else {
          bVar2 = obj->field_0x54;
        }
        DAT_801b29a1 = bVar2 | 0x80;
        obj->field_0x50 = 3;
        obj->field_0x54 = obj->field_0x54 + '\x01';
      }
      else {
        obj->field_0x50 = obj->field_0x50 + -1;
      }
    }
    else {
      obj->field_0x4 = 1;
    }
  }
  else {
    if (obj->field_0x4 != '\x01') {
      if (obj->field_0x50 == '\0') {
        DAT_801b29a0 = 1;
        Obj_Free(obj);
        return;
      }
      obj->field_0x50 = obj->field_0x50 + -1;
      return;
    }
    cVar3 = Obj_InActiveArea(obj);
    if ((cVar3 == '\0') && (0x12 < DAT_801b29a5)) {
      if ((*(byte *)(*(int *)&obj->field_0x5c + 0x58) & 0x7f) == 0) {
        obj->field_0x50 = 0x30;
      }
      else {
        obj->field_0x50 = 0;
      }
      obj->field_0x4 = 2;
    }
  }
  FUN_80104c9c(obj);
  iVar4 = 0x40000;
  if (obj->flip == 0) {
    iVar4 = -0x40000;
    bVar1 = obj->speed_x < -0x40000;
  }
  else {
    bVar1 = 0x40000 < obj->speed_x;
  }
  if (bVar1) {
    obj->speed_x = iVar4;
  }
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Anim_Set(obj,0x16);
    FUN_8010544c(obj,0x1b6);
  }
  else {
    Anim_Step(obj);
  }
  return;
}


// ---- 801e409c FUN_801e409c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e409c(MM8Obj *obj)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      iVar3 = -0x40000;
      obj->speed_y_up = 0;
      obj->gravity = 0;
      if ((obj->flip & 0x40) != 0) {
        iVar3 = 0x40000;
      }
                    /* Possible PsyQ macro: setTile16() */
      obj->speed_x = iVar3;
      obj->accel_x = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104d00(obj);
    bVar2 = false;
    if (obj->flip == 0) {
      bVar2 = obj->x < 0x1b54;
    }
    else if (0x1a14 < obj->x) {
      bVar2 = true;
    }
    if (bVar2) {
      Anim_Set(obj,0x16);
      FUN_8010544c(obj,0x1b6);
      obj->sub3 = 2;
      obj->field_0x4 = 0;
      obj->field_0x50 = 0;
      obj->field_0x54 = 0;
    }
  }
  return;
}


// ---- 801e4180 FUN_801e4180

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4180(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaf10)[obj->sub3])();
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801e41d0 FUN_801e41d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e41d0(MM8Obj *obj)

{
  undefined1 *puVar1;
  int iVar2;
  short sVar3;
  
  iVar2 = 0;
  sVar3 = 0x1a10;
  do {
    puVar1 = (undefined1 *)FUN_801055e4(obj);
    if (puVar1 != (undefined1 *)0x0) {
      *(short *)(puVar1 + 0xe) = sVar3;
      sVar3 = sVar3 + 0x10;
      puVar1[0x52] = (char)iVar2;
      iVar2 = iVar2 + 1;
      puVar1[7] = 5;
      *puVar1 = 1;
      puVar1[6] = 0x4e;
      puVar1[0x25] = 0;
      *(undefined2 *)(puVar1 + 0x12) = 0xcb8;
      *(MM8Obj **)(puVar1 + 0x5c) = obj;
    }
  } while (iVar2 < 0x15);
  obj->sub3 = 1;
  obj->field_0x4 = 0;
  obj->field_0x50 = 0x30;
  return;
}


// ---- 801e4280 FUN_801e4280

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4280(MM8Obj *obj)

{
  char cVar1;
  
                    /* Possible PsyQ macro: setTile16() + setSemiTrans(tile16, 1) */
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->gravity = 0x4000;
      obj->speed_x = 0;
      obj->speed_y_up = 0;
      obj->accel_x = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104ccc(obj);
    if (obj->field_0x4 == '\x01') {
      if (obj->speed_y_up < -0x60000) {
        obj->speed_y_up = -0x60000;
      }
      if (0xc40 < obj->y) {
        obj->gravity = -0x8000;
        obj->field_0x4 = 2;
      }
    }
    else if (obj->y < 0xc40) {
      obj->y = 0xc40;
      obj->sub3 = 2;
      obj->field_0x50 = 5;
      obj->field_0x54 = 6;
      obj->field_0x4 = 0;
      obj->speed_y_up = 0;
      obj->gravity = 0;
      obj->speed_x = 0;
      obj->accel_x = 0;
      obj->field_0x55 = 0x80;
      Anim_Set(obj,0x16);
      FUN_8010544c(obj,0x1b6);
      obj->speed_y_up = 0;
      obj->gravity = 0;
    }
  }
  return;
}


// ---- 801e43a8 FUN_801e43a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e43a8(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      if (obj->field_0x54 == '\x06') {
        DAT_801b29a5 = '\x15';
      }
      Anim_Set(obj,0x15);
      obj->field_0x4 = 1;
    }
  }
  else if (DAT_801b29a5 == '\0') {
    if (obj->field_0x54 == '\0') {
      if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
        obj->sub3 = 4;
        obj->field_0x4 = 0;
        obj->field_0x50 = 0x3c;
        Anim_Set(obj,0x15);
        return;
      }
    }
    else {
      cVar1 = obj->field_0x50;
      obj->field_0x50 = cVar1 + -1;
      if (cVar1 == '\0') {
        obj->field_0x50 = 5;
        obj->sub3 = 3;
        obj->field_0x4 = 0;
        obj->field_0x54 = obj->field_0x54 + -1;
      }
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801e44d0 FUN_801e44d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e44d0(MM8Obj *obj)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (obj->field_0x4 == '\0') {
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      do {
        iVar2 = FUN_801e54b0(obj);
        uVar3 = Rand();
        uVar3 = iVar2 + (uVar3 & 0xf) % 6;
        if ((obj->field_0x55 & 0x80) != 0) break;
      } while ((uVar3 & 0xff) == (uint)(byte)obj->field_0x55);
      obj->field_0x55 = (char)uVar3;
      if ((int)obj->x < (int)((uint)(byte)obj->field_0x55 * 0x10 + 0x1a14)) {
                    /* Possible PsyQ macro: setLineF2() */
        obj->flip = 0x40;
      }
      else {
        obj->flip = 0;
      }
      iVar2 = 0x10000;
      if ((obj->flip & 0x40) != 0) {
        iVar2 = -0x10000;
      }
      iVar4 = -0x4000;
      obj->speed_x = iVar2;
      if ((obj->flip & 0x40) != 0) {
        iVar4 = 0x4000;
      }
      obj->accel_x = iVar4;
      Anim_Set(obj,0x15);
      obj->field_0x4 = 1;
    }
  }
  else {
    FUN_80104c9c(obj);
    iVar2 = (uint)(byte)obj->field_0x55 * 0x10 + 0x1a14;
    if (obj->flip == 0) {
      if (obj->speed_x < -0x60000) {
        obj->speed_x = -0x60000;
      }
      bVar1 = obj->x < iVar2;
    }
    else {
      if (0x60000 < obj->speed_x) {
        obj->speed_x = 0x60000;
      }
      bVar1 = iVar2 < obj->x;
    }
    if (bVar1) {
      obj->x = (short)iVar2;
    }
    if (obj->x == iVar2) {
      Anim_Set(obj,0x16);
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
      FUN_8010544c(obj,0x1b6);
      obj->sub3 = 2;
      obj->field_0x4 = 1;
      DAT_801b29a1 = obj->field_0x55 | 0x80;
      FUN_8010544c(obj,0x1bb);
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801e46dc FUN_801e46dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e46dc(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (obj->field_0x4 == '\0') {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      Anim_Set(obj,0x16);
      FUN_8010544c(obj,0x1b6);
      DAT_801b29a2 = 0xff;
      DAT_801b29a5 = 0;
      obj->field_0x4 = 1;
    }
  }
  else if (obj->field_0x4 == '\x01') {
                    /* Possible PsyQ macro: setPolyGT3() */
    if (((0x14 < DAT_801b29a5) && ((short)obj->frame < 0)) && (obj->anim_timer == 1)) {
      Anim_Set(obj,0x15);
      iVar3 = 0x10000;
      if ((obj->flip & 0x40) != 0) {
        iVar3 = -0x10000;
      }
      iVar2 = -0x4000;
      obj->speed_x = iVar3;
      if ((obj->flip & 0x40) != 0) {
        iVar2 = 0x4000;
      }
      obj->accel_x = iVar2;
      obj->field_0x4 = 2;
    }
  }
  else {
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      DAT_801b29a0 = 1;
      Obj_Free(obj);
      return;
    }
    FUN_80104c9c(obj);
                    /* Possible PsyQ macro: setPolyGT3() */
    if ((obj->flip == 0) && (obj->speed_x < -0x60000)) {
      obj->speed_x = -0x60000;
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801e4844 FUN_801e4844

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4844(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaf24)[obj->sub2])();
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
  return;
}


// ---- 801e4880 FUN_801e4880

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4880(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaf28)[obj->sub3])();
  return;
}


// ---- 801e48bc FUN_801e48bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e48bc(MM8Obj *obj)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = *(int *)&obj->field_0x5c;
  uVar1 = *(undefined4 *)(iVar2 + 0xc);
  obj->x_frac = (short)uVar1;
  obj->x = (short)((uint)uVar1 >> 0x10);
  uVar1 = *(undefined4 *)(iVar2 + 0x10);
  obj->y_frac = (short)uVar1;
  obj->y = (short)((uint)uVar1 >> 0x10);
  obj->flip = *(byte *)(iVar2 + 0x25);
  if (DAT_801b29a4 == 0) {
    obj->field_0x51 = 1;
  }
  else {
    bVar3 = DAT_801b29a4 & 0x7f;
    if ((DAT_801b29a4 & 0x80) != 0) {
      DAT_801b29a4 = bVar3;
      Anim_Set(obj,bVar3 + 0x2e);
    }
    obj->field_0x51 = 0;
    Anim_Step(obj);
  }
  return;
}


// ---- 801e4958 FUN_801e4958

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4958(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaf2c)[obj->sub2])();
  return;
}


// ---- 801e4994 FUN_801e4994

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4994(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaf30)[obj->sub3])();
  if ((((obj->active != 0) && (obj->field_0x53 != '\0')) &&
      (obj->hitbox = &UNK_801eace8 + (uint)obj->anim_extra * 4, obj->field_0x51 == '\0')) &&
     (obj->anim_extra != 0)) {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801e4a34 FUN_801e4a34

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4a34(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    if (((DAT_801b29a1 & 0x80) != 0) && ((DAT_801b29a1 & 0x7f) == obj->field_0x52)) {
      obj->field_0x51 = 0;
      obj->field_0x4 = 1;
    }
  }
  else if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    if (obj->field_0x53 != '\0') {
      DAT_801b29a5 = DAT_801b29a5 + '\x01';
    }
    Obj_Free();
  }
  else {
    Anim_Step();
  }
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
  return;
}


// ---- 801e4af0 FUN_801e4af0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4af0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaf34)[obj->sub2])();
  return;
}


// ---- 801e4b2c FUN_801e4b2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4b2c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaf38)[obj->sub3])();
  return;
}


// ---- 801e4b68 FUN_801e4b68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4b68(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    if (DAT_801b29a5 != '\0') {
      obj->field_0x51 = 0;
      obj->field_0x4 = 1;
    }
  }
  else {
    Anim_Step(obj);
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      Anim_SetAtStep(obj,0x22,DAT_801b29a2);
      Anim_StepN(obj,obj->field_0x52);
      obj->sub3 = 1;
      obj->field_0x4 = 0;
      DAT_801b29a5 = DAT_801b29a5 + -1;
    }
  }
  return;
}


// ---- 801e4c24 FUN_801e4c24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4c24(MM8Obj *obj)

{
  char cVar1;
  
  if (DAT_801b29a2 == -1) {
    Anim_Set(obj,0x25);
    obj->sub3 = 3;
    obj->field_0x4 = 0;
  }
  else if (obj->field_0x4 == '\0') {
    Anim_SetAtStep(obj,0x22);
    Anim_StepN(obj,obj->field_0x52);
    if (((DAT_801b29a1 & 0x80) != 0) && ((DAT_801b29a1 & 0x7f) == obj->field_0x52)) {
      DAT_801b29a1 = DAT_801b29a1 & 0x7f;
      Anim_Set(obj,0x23);
      obj->field_0x50 = 0x14;
      obj->field_0x4 = 1;
    }
  }
  else {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      Anim_Set(obj,0x24);
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801e4d14 FUN_801e4d14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4d14(MM8Obj *obj)

{
  byte bVar1;
  
                    /* Possible PsyQ macro: setLineF2() */
  if (DAT_801b29a2 == -1) {
    Anim_Set(obj,0x25);
    bVar1 = 3;
  }
  else {
    obj->hitbox = &UNK_801ead14 + (uint)obj->anim_extra * 4;
    if (obj->anim_extra != 0) {
      Enemy_ContactDamage(obj);
    }
    if ((-1 < (short)obj->frame) || (obj->anim_timer != 1)) {
      Anim_Step(obj);
      return;
    }
    Anim_SetAtStep(obj,0x22,DAT_801b29a2);
    Anim_StepN(obj,obj->field_0x52);
    bVar1 = 1;
    obj->hitbox = (byte *)0x0;
  }
  obj->sub3 = bVar1;
  obj->field_0x4 = 0;
  return;
}


// ---- 801e4de0 FUN_801e4de0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4de0(MM8Obj *obj)

{
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    DAT_801b29a5 = DAT_801b29a5 + '\x01';
    Obj_Free();
  }
  else {
    Anim_Step();
  }
  return;
}


// ---- 801e4e44 FUN_801e4e44

void FUN_801e4e44(int param_1,char param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  
  sVar6 = 1;
  if (*(char *)(param_1 + 0x25) != '\0') {
    sVar6 = -1;
  }
  iVar5 = 0;
  do {
    iVar4 = 0;
    do {
      puVar3 = (undefined1 *)FUN_801055e4(param_1);
      if (puVar3 != (undefined1 *)0x0) {
        puVar3[6] = 0x4e;
        *puVar3 = 1;
        puVar3[7] = 1;
        if (param_2 == '\0') {
          puVar3[2] = 1;
        }
        else {
          puVar3[2] = 2;
        }
                    /* Possible PsyQ macro: setPolyFT4() */
        puVar3[0x52] = '\x03' - (char)iVar4;
        *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
        *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
                    /* Possible PsyQ macro: setPolyGT4() */
        *(short *)(puVar3 + 0x12) = *(short *)(puVar3 + 0x12) + 0x20;
                    /* Possible PsyQ macro: setLineF2() */
        *(short *)(puVar3 + 0xe) =
             *(short *)(puVar3 + 0xe) +
             sVar6 * (char)(&DAT_801ead38)[(iVar5 * 8 + (uint)(byte)puVar3[0x52]) * 2];
        cVar1 = (&DAT_801ead39)[(iVar5 * 8 + (uint)(byte)puVar3[0x52]) * 2];
        puVar3[0x50] = (char)iVar5;
                    /* Possible PsyQ macro: setLineF2() */
        *(short *)(puVar3 + 0x12) = (short)cVar1 + *(short *)(puVar3 + 0x12);
        uVar2 = *(undefined1 *)(param_1 + 0x25);
        iVar4 = iVar4 + 1;
        *(int *)(puVar3 + 0x5c) = param_1;
        puVar3[0x25] = uVar2;
      }
    } while (iVar4 < 4);
    iVar5 = iVar5 + 1;
    iVar4 = 0;
  } while (iVar5 < 2);
  do {
    puVar3 = (undefined1 *)FUN_801055e4(param_1);
    if (puVar3 != (undefined1 *)0x0) {
      puVar3[6] = 0x4e;
      *puVar3 = 1;
      puVar3[7] = 1;
      if (param_2 == '\0') {
        puVar3[2] = 1;
      }
      else {
        puVar3[2] = 2;
      }
      puVar3[0x52] = '\a' - (char)iVar4;
      *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      *(short *)(puVar3 + 0x12) = *(short *)(puVar3 + 0x12) + 0x20;
      *(short *)(puVar3 + 0xe) =
           *(short *)(puVar3 + 0xe) + sVar6 * (char)(&DAT_801ead38)[(uint)(byte)puVar3[0x52] * 2];
      cVar1 = (&DAT_801ead39)[(uint)(byte)puVar3[0x52] * 2];
      puVar3[0x50] = 1;
      *(short *)(puVar3 + 0x12) = (short)cVar1 + *(short *)(puVar3 + 0x12);
      uVar2 = *(undefined1 *)(param_1 + 0x25);
      iVar4 = iVar4 + 1;
      *(int *)(puVar3 + 0x5c) = param_1;
      puVar3[0x25] = uVar2;
    }
  } while (iVar4 < 3);
  do {
    do {
      puVar3 = (undefined1 *)FUN_801055e4(param_1);
    } while (puVar3 == (undefined1 *)0x0);
    puVar3[6] = 0x4e;
    *puVar3 = 1;
    puVar3[7] = 1;
    if (param_2 == '\0') {
      puVar3[2] = 1;
    }
    else {
      puVar3[2] = 2;
    }
    puVar3[0x52] = 4;
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(short *)(puVar3 + 0x12) = *(short *)(puVar3 + 0x12) + 0x20;
    *(short *)(puVar3 + 0xe) = *(short *)(puVar3 + 0xe) + sVar6 * DAT_801ead40;
    cVar1 = DAT_801ead41;
    puVar3[0x50] = 1;
    *(short *)(puVar3 + 0x12) = (short)cVar1 + *(short *)(puVar3 + 0x12);
    uVar2 = *(undefined1 *)(param_1 + 0x25);
    *(int *)(puVar3 + 0x5c) = param_1;
    puVar3[0x25] = uVar2;
  } while (puVar3 == (undefined1 *)0x0);
  iVar5 = 0;
  do {
    puVar3 = (undefined1 *)FUN_801055e4(param_1);
    if (puVar3 != (undefined1 *)0x0) {
      puVar3[6] = 0x4e;
      *puVar3 = 1;
      puVar3[7] = 1;
      if (param_2 == '\0') {
        puVar3[2] = 1;
      }
      else {
        puVar3[2] = 2;
      }
      puVar3[0x52] = (char)iVar5 + '\x05';
      *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      *(short *)(puVar3 + 0x12) = *(short *)(puVar3 + 0x12) + 0x20;
                    /* Possible PsyQ macro: setPolyGT4() */
      *(short *)(puVar3 + 0xe) =
           *(short *)(puVar3 + 0xe) + sVar6 * (char)(&DAT_801ead38)[((byte)puVar3[0x52] + 8) * 2];
      cVar1 = (&DAT_801ead39)[((byte)puVar3[0x52] + 8) * 2];
      puVar3[0x50] = 1;
      *(short *)(puVar3 + 0x12) = (short)cVar1 + *(short *)(puVar3 + 0x12);
      uVar2 = *(undefined1 *)(param_1 + 0x25);
      iVar5 = iVar5 + 1;
      *(int *)(puVar3 + 0x5c) = param_1;
      puVar3[0x25] = uVar2;
    }
  } while (iVar5 < 3);
  return;
}


// ---- 801e5234 FUN_801e5234

void FUN_801e5234(int param_1)

{
  char cVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = (int)DAT_8015e248._2_2_;
  uVar6 = -(iVar4 < 0x1ab9 ^ 1) & 3;
  if (uVar6 == 0) {
    if (0x1a80 < iVar4) {
LAB_801e528c:
      uVar6 = uVar6 + 1;
    }
  }
  else if (0x1af0 < iVar4) goto LAB_801e528c;
  iVar5 = iVar4 - (short)(&DAT_801ead58)[uVar6];
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  iVar2 = iVar4 - *(short *)(&DAT_801ead5a + uVar6 * 2);
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (iVar2 < iVar5) {
    uVar6 = uVar6 + 1;
  }
  *(undefined2 *)(param_1 + 0xe) = (&DAT_801ead58)[uVar6];
  *(undefined2 *)(param_1 + 0x12) = 0xc68;
  sVar3 = (*(ushort *)(param_1 + 0xe) & 0xfff0) - 4;
  *(short *)(param_1 + 0xe) = sVar3;
  if (uVar6 == 0) {
    cVar1 = '@';
  }
  else {
    if (uVar6 == 5) {
      *(undefined1 *)(param_1 + 0x25) = 0;
      goto LAB_801e5348;
    }
    cVar1 = (sVar3 <= iVar4) << 6;
  }
  *(char *)(param_1 + 0x25) = cVar1;
LAB_801e5348:
  Anim_Set(param_1,3);
  *(undefined1 *)(param_1 + 2) = 3;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(char *)(param_1 + 0x5a) = (char)uVar6;
  return;
}


// ---- 801e5380 FUN_801e5380

int FUN_801e5380(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  Enemy_ContactDamage();
  pcVar3 = &DAT_801b12ac;
  pcVar4 = (char *)((int)&DAT_801b12b0 + 3);
  do {
    if ((*pcVar3 != '\0') && (pcVar4[0x3f] == '\0')) {
      switch(pcVar4[-1]) {
      case '\0':
        iVar2 = 1;
        break;
      case '\x01':
        iVar2 = 3;
        if (*pcVar4 == '\0') {
          iVar2 = 2;
        }
        break;
      case '\x02':
      case '\x06':
      case '\n':
      case '\v':
      case '\f':
      case '\x0f':
      case '\x10':
      case '\x11':
        iVar2 = 3;
        break;
      default:
        iVar2 = 0;
      }
                    /* Possible PsyQ macro: setPolyFT4() */
      if ((iVar2 != 0) && (iVar1 = Obj_HitboxOverlap(param_1,pcVar3), iVar1 != 0)) {
        FUN_8010544c(param_1,0x1ba);
        FUN_801074f0(param_1,pcVar3,3);
        return iVar2;
      }
    }
    pcVar3 = pcVar3 + 0x60;
    pcVar4 = pcVar4 + 0x60;
    if ("" < pcVar3) {
                    /* Possible PsyQ macro: setLineF2() */
      return 0;
    }
  } while( true );
}


// ---- 801e54b0 FUN_801e54b0

uint FUN_801e54b0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = (int)DAT_8015e248._2_2_;
  uVar1 = 0;
  if (0x1a3f < iVar3) {
                    /* Possible PsyQ macro: setLineF2() */
    uVar1 = 1;
    if (iVar3 < 0x1b30) {
      iVar5 = 0x1a500000;
      iVar2 = 0x1a50;
      do {
        iVar4 = iVar3 - iVar2;
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        iVar2 = (iVar3 + -0x10) - iVar2;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
                    /* Possible PsyQ macro: setPolyGT3() + setSemiTrans(polyGT3, 1) */
        if (iVar4 < iVar2) {
          return uVar1 & 0xff;
        }
        iVar5 = iVar5 + 0x100000;
        uVar1 = uVar1 + 1;
        iVar2 = iVar5 >> 0x10;
      } while ((int)uVar1 < 0xf);
    }
    uVar1 = 0xf;
  }
  return uVar1;
}


