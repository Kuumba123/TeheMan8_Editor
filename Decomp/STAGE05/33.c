// ID 33, STAGE05.BIN, handler 0x801DD7E0. Ghidra output with the object struct applied; not matching C.
// ---- 801dd7e0 FUN_801dd7e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd7e0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea464)[obj->state])();
  return;
}


// ---- 801dd81c FUN_801dd81c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd81c(MM8Obj *obj)

{
  Enemy_InitFromTable();
  DAT_801b29a6 = 0;
  DAT_801b29a7 = 0;
  obj->field_0x50 = 0;
  obj->field_0x54 = 0;
  obj->field_0x55 = 0;
  obj->field_0x56 = 0;
  obj->field_0x57 = 0;
  obj->field_0x58 = 0;
  obj->field_0x5d = 0;
  obj->field_0x59 = 0;
  obj->field_0x5a = 0;
  obj->field_0x5b = 0;
  obj->field_0x5c = 0;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->state = obj->var + 1;
  return;
}


// ---- 801dd898 FUN_801dd898

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd898(MM8Obj *obj)

{
  if (((obj->field_0x5b & 0x80) != 0) && (obj->sub2 != 7)) {
    obj->sub2 = 7;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  obj->field_0x5b = obj->field_0x5b & 0xbf;
  (*(code *)(&PTR_FUN_801ea5b8)[obj->sub2])();
  return;
}


// ---- 801dd90c FUN_801dd90c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd90c(MM8Obj *obj)

{
  obj->field_0x55 = 4;
  obj->field_0x56 = 4;
  *(word *)&obj->field_0x50 = obj->y_frac;
  *(short *)&obj->field_0x52 = obj->y;
  obj->y = obj->y + 0xd0;
  FUN_801df85c(obj);
  obj->hitbox = (byte *)0x0;
  obj->box2 = (byte *)0x0;
  obj->flip = 0;
  obj->field_0x54 = 0;
  obj->field_0x59 = 0;
  obj->field_0x58 = 0;
  obj->field_0x57 = 0;
  *(undefined2 *)&obj->field_0x5e = 0;
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  obj->sub2 = 8;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801dd9a4 FUN_801dd9a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd9a4(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  
  uVar5._0_2_ = obj->y_frac;
  uVar5._2_2_ = obj->y;
  obj->y_frac = (short)(uVar5 & 0xffff0000);
  obj->y = (short)((uVar5 & 0xffff0000) >> 0x10);
  bVar1 = obj->field_0x5b;
  if (obj->sub3 != 0) {
    cVar2 = obj->field_0x54 + -1;
    obj->field_0x54 = cVar2;
    if (cVar2 != '\0') {
      return;
    }
    obj->sub3 = 0;
    return;
  }
  if (((bVar1 & 3) == 0) || ((bVar1 & 3) != 1)) {
    cVar2 = FUN_801dfa54(obj);
  }
  else {
    if ((bVar1 & 8) == 0) {
      obj->field_0x58 = 0;
      if (DAT_801b29a6 >> 4 == 0) {
        DAT_801b29a6 = DAT_801b29a6 + 0x10;
        sVar4 = *(short *)&obj->field_0x52 + -0x30;
        if (obj->y <= *(short *)&obj->field_0x52) {
          sVar4 = *(short *)&obj->field_0x52 + 0x30;
        }
        *(short *)&obj->field_0x5e = sVar4;
      }
      else {
        obj->field_0x5b = obj->field_0x5b | 8;
        iVar6 = *(int *)&obj->field_0x50 + 0x1a0000;
        *(int *)&obj->field_0x50 = iVar6;
        *(short *)&obj->field_0x5e = (short)((uint)iVar6 >> 0x10);
      }
      if (*(short *)&obj->field_0x5e < obj->y) {
        obj->field_0x57 = 1;
        iVar6 = 0x10000;
      }
      else {
        obj->field_0x57 = 2;
        iVar6 = -0x10000;
      }
      obj->speed_y_up = iVar6;
      obj->sub2 = 3;
      obj->sub3 = 0;
      pcVar7 = (code *)(&PTR_FUN_801ea5b8)[obj->sub2];
      goto code_r0x801ddbc0;
    }
    DAT_801b29a7 = DAT_801b29a7 + 1;
    cVar2 = '\x04';
    if (1 < DAT_801b29a7) {
      obj->field_0x5b = obj->field_0x5b | 2;
    }
  }
  obj->field_0x57 = cVar2;
  if (cVar2 == '\0') {
    obj->field_0x58 = 0;
    obj->field_0x5d = 0;
    obj->field_0x54 = 0x3c;
    obj->sub3 = obj->sub3 + 1;
    return;
  }
  if (1 < (byte)(cVar2 - 1U)) {
    if (cVar2 == '\x03') {
      obj->field_0x5d = 0;
      uVar3 = FUN_801df960(obj);
      obj->field_0x5a = uVar3;
      obj->sub2 = 2;
      obj->sub3 = 0;
      obj->field_0x58 = obj->field_0x58 + 1 & 0xf | obj->field_0x58 & 0xf0;
      return;
    }
    if (cVar2 != '\x04') {
      return;
    }
    obj->field_0x58 = 0;
    obj->sub2 = 6;
    obj->sub3 = 0;
    obj->field_0x5d = (obj->field_0x5d & 0xf0) + 0x10;
    return;
  }
  if (cVar2 == '\x01') {
    obj->speed_y_up = 0x10000;
    sVar4 = obj->y + -0x10;
  }
  else {
    obj->speed_y_up = -0x10000;
    sVar4 = obj->y + 0x10;
  }
  *(short *)&obj->field_0x5e = sVar4;
  obj->sub2 = 3;
  obj->field_0x58 = 0;
  obj->sub3 = 0;
  obj->field_0x5d = obj->field_0x5d | obj->field_0x5d + 1 & 0xf;
  pcVar7 = (code *)(&PTR_FUN_801ea5b8)[obj->sub2];
code_r0x801ddbc0:
  (*pcVar7)(obj);
  return;
}


// ---- 801ddce4 FUN_801ddce4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddce4(MM8Obj *obj)

{
  ushort uVar1;
  bool bVar2;
  
  uVar1 = *(ushort *)&obj->field_0x5e;
  if (obj->sub3 == 0) {
    FUN_8010544c(obj,0x109);
    obj->sub3 = obj->sub3 + 1;
  }
  FUN_80104c34(obj);
  if (obj->speed_y_up < 1) {
    bVar2 = false;
    if (obj->y < (short)uVar1) goto LAB_801ddd74;
  }
  else {
    bVar2 = false;
    if ((short)uVar1 < obj->y) goto LAB_801ddd74;
  }
  bVar2 = true;
LAB_801ddd74:
  if (bVar2) {
    obj->y_frac = (short)((uint)uVar1 << 0x10);
    obj->y = (short)(((uint)uVar1 << 0x10) >> 0x10);
    obj->speed_y_up = 0;
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  else {
    FUN_801dfc74(obj,obj->speed_y_up);
  }
  return;
}


// ---- 801ddf74 FUN_801ddf74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddf74(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  bVar1 = obj->sub3;
  if (bVar1 == 0) {
    DAT_801d2936 = 1;
    if (obj->field_0x4 == '\0') {
      DAT_801b2992 = 1;
      DAT_801b2993 = 1;
                    /* Possible PsyQ macro: setLineF2() */
      DAT_801b2994 = 1;
      obj->field_0x5c = 0x33;
      FUN_8010544c(obj,0x10b);
      obj->field_0x54 = 0xb4;
      obj->field_0x58 = 0;
      obj->field_0x4 = obj->field_0x4 + '\x01';
    }
    else {
      cVar2 = obj->field_0x54 + -1;
      obj->field_0x54 = cVar2;
      if (cVar2 == '\0') {
        obj->field_0x4 = 0;
        obj->sub3 = obj->sub3 + 1;
      }
    }
  }
  else if (bVar1 == 1) {
    DAT_801d2936 = 1;
    if (obj->y == 0x440) {
      obj->field_0x5c = 0x10;
      obj->field_0x5b = obj->field_0x5b & 0xef;
      obj->sub3 = obj->sub3 + 1;
    }
    else {
      iVar5 = 0x8000;
      if (obj->y < 0x441) {
        iVar3._0_2_ = obj->y_frac;
        iVar3._2_2_ = obj->y;
      }
      else {
        iVar3._0_2_ = obj->y_frac;
        iVar3._2_2_ = obj->y;
        iVar5 = -0x8000;
      }
      *(int *)&obj->y_frac = iVar3 + iVar5;
    }
    bVar1 = obj->field_0x54;
    obj->field_0x54 = bVar1 + 1;
    if ((byte)obj->field_0x58 < 5) {
      if ((bVar1 & 0xf) == 0) {
        uVar4 = Rand();
        FUN_80108ed8(obj,(int)*(short *)(&DAT_801ea5b0 + ((uint)(bVar1 >> 4) % 3) * 2),
                     ((uVar4 & 7) - 1) * 0x14);
        obj->field_0x58 = obj->field_0x58 + '\x01';
      }
    }
    else if ((bVar1 & 7) == 0) {
      uVar4 = Rand();
                    /* Possible PsyQ macro: setLineF2() */
      iVar5 = ((uVar4 & 7) - 1) * 0x14;
      FUN_80108ed8(obj,(int)*(short *)(&DAT_801ea5b0 + ((uint)(bVar1 >> 3) % 3) * 2),iVar5);
      FUN_8012a724(obj,4,(int)*(short *)(&DAT_801ea5b0 + ((uint)(bVar1 >> 3) % 3) * 2),iVar5);
      uVar4 = Rand();
      iVar5 = ((uVar4 & 7) - 1) * 0x14;
      FUN_80108ed8(obj,(int)*(short *)(&DAT_801ea5b0 + (((bVar1 >> 3) + 1) % 3) * 2),iVar5);
      FUN_8012a724(obj,4,(int)*(short *)(&DAT_801ea5b0 + (((bVar1 >> 3) + 1) % 3) * 2),iVar5);
      FUN_8010544c(obj,10);
    }
  }
  else if (bVar1 == 2) {
    DAT_801d2936 = 1;
    if ((obj->field_0x5b & 0x10) != 0) {
      DAT_801d2936 = 0x10;
      obj->field_0x55 = 2;
      obj->field_0x56 = 2;
      obj->field_0x5c = obj->field_0x5c;
      obj->field_0x5b = obj->field_0x5b & 0x7f | 0x20;
      obj->sub3 = obj->sub3 + 1;
    }
  }
  else if (bVar1 == 3) {
    DAT_801b2992 = 0;
    DAT_801b2993 = 0;
    DAT_801b2994 = 0;
    obj->sub2 = 5;
    obj->sub3 = 0;
  }
  FUN_801dfc74(obj,(int)(((uint)(ushort)obj->prev_y - (uint)(ushort)obj->y) * 0x10000) >> 0x10);
  if (((DAT_801d2936 != 0) && (obj->y != obj->prev_y)) && ((uint)(byte)obj->field_0x59 % 0xc == 0))
  {
    FUN_8010544c(obj,0xcb);
  }
  return;
}


// ---- 801de360 FUN_801de360

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de360(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
                    /* Possible PsyQ macro: setLineF2() */
  bVar1 = obj->sub3;
  if (bVar1 == 0) {
    *(short *)&obj->field_0x4a = DAT_8015e248._2_2_;
    obj->sub3 = obj->sub3 + 1;
    return;
  }
  if (bVar1 == 1) {
                    /* Possible PsyQ macro: setPolyF4() */
    FUN_801119e0((int)*(short *)&obj->field_0x4a,DAT_8015e261);
    if ((DAT_8015e26f & 0x80) == 0) {
      return;
    }
    FUN_800fcb80(0x13);
    bVar1 = obj->sub3 + 1;
  }
  else if (bVar1 == 2) {
    FUN_801119e0((int)*(short *)&obj->field_0x4a,DAT_8015e261);
    if (g_cam_y != DAT_801d292a) {
      g_cam_y = g_cam_y + 1;
      return;
    }
    DAT_801d2928 = 0xa00;
    DAT_801d2926 = 0xa00;
    DAT_801d292c = 0x400;
    DAT_801d292a = 0x400;
    bVar1 = obj->sub3 + 1;
  }
  else {
    if (bVar1 != 3) {
      FUN_801119e0(0xa80,0x40);
      cVar2 = obj->field_0x54 + -1;
      obj->field_0x54 = cVar2;
      if (cVar2 != '\0') {
        return;
      }
      obj->sub2 = 9;
      obj->sub3 = 0;
      return;
    }
    FUN_801119e0(0xa80,0x40);
    if (DAT_8015e248._2_2_ != 0xa80) {
      return;
    }
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x54 = 0x3c;
    bVar1 = obj->sub3 + 1;
  }
  obj->sub3 = bVar1;
  return;
}


// ---- 801de4dc FUN_801de4dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de4dc(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  
  bVar1 = obj->sub3;
  FUN_801119e0(0xa80,0x40);
  if (bVar1 == 0) {
    uVar4 = *(uint *)&obj->field_0x50;
    if ((int)(uVar4 >> 0x10) < (int)obj->y) {
      *(int *)&obj->y_frac = *(int *)&obj->y_frac + -0x10000;
      DAT_801d2936 = 1;
      goto LAB_801de680;
    }
    bVar1 = obj->sub3;
    uVar3 = 6;
    obj->y_frac = (short)uVar4;
    obj->y = (short)(uVar4 >> 0x10);
  }
  else {
    if (bVar1 != 1) {
      if (bVar1 == 2) {
        cVar2 = obj->field_0x54 + -1;
        obj->field_0x54 = cVar2;
        if (cVar2 == '\0') {
          obj->field_0x55 = 4;
          obj->field_0x56 = 4;
          obj->field_0x54 = 0x3c;
          obj->y_frac = *(undefined2 *)&obj->field_0x50;
          obj->y = *(undefined2 *)&obj->field_0x52;
          obj->sub3 = obj->sub3 + 1;
        }
        else {
          obj->field_0x55 = 0;
          obj->field_0x56 = 0;
        }
      }
      else if ((bVar1 == 3) &&
              (cVar2 = obj->field_0x54 + -1, obj->field_0x54 = cVar2, cVar2 == '\0')) {
        FUN_80111918();
        DAT_801b2992 = 0;
        DAT_801b2993 = 0;
        DAT_801b2994 = 0;
        obj->sub2 = 1;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
      }
      goto LAB_801de680;
    }
    cVar2 = obj->field_0x54 + -1;
    obj->field_0x54 = cVar2;
    if (cVar2 != '\0') {
      if ((DAT_80170574 & 2) == 0) {
        obj->y_frac = *(undefined2 *)&obj->field_0x50;
        obj->y = *(undefined2 *)&obj->field_0x52;
      }
      else {
        *(int *)&obj->y_frac = *(int *)&obj->field_0x50 + -0x20000;
      }
      goto LAB_801de680;
    }
                    /* Possible PsyQ macro: setPolyF3() */
    obj->field_0x55 = 0x20;
    obj->field_0x56 = 0x20;
    bVar1 = obj->sub3;
    uVar3 = 0x1b;
  }
  obj->field_0x54 = uVar3;
  obj->sub3 = bVar1 + 1;
LAB_801de680:
  FUN_801dfc74(obj,(int)(((uint)(ushort)obj->prev_y - (uint)(ushort)obj->y) * 0x10000) >> 0x10);
  if (((DAT_801d2936 != 0) && (obj->y != obj->prev_y)) && ((uint)(byte)obj->field_0x59 % 0x18 == 0))
  {
    FUN_8010544c(obj,0xcb);
  }
  return;
}


// ---- 801de714 FUN_801de714

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de714(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea5e0)[obj->sub3])();
  return;
}


// ---- 801de750 FUN_801de750

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de750(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  
  sVar2 = *(short *)&obj->field_0x52;
  uVar4 = (uint)(byte)obj->field_0x5a;
  if (obj->field_0x4 == '\0') {
    obj->field_0x5c = 0x11;
    obj->field_0x54 = 0x14;
    obj->field_0x5b = obj->field_0x5b | 4;
    obj->field_0x4 = obj->field_0x4 + '\x01';
  }
  else {
    cVar3 = obj->field_0x54 + -1;
    obj->field_0x54 = cVar3;
    if (cVar3 == '\0') {
      FUN_8010544c(obj,0x10b);
      sVar1 = obj->y;
      if ((int)sVar1 < sVar2 + 0x10) {
        if (sVar2 + -0x10 < (int)sVar1) {
          *(short *)&obj->field_0x5e = sVar1;
          obj->speed_y_up = 0;
        }
        else {
          *(short *)&obj->field_0x5e = sVar1 + *(short *)(&DAT_801ea5a8 + uVar4 * 2);
          obj->speed_y_up = -*(int *)(&DAT_801ea59c + uVar4 * 4);
        }
      }
      else {
        *(short *)&obj->field_0x5e = sVar1 - *(short *)(&DAT_801ea5a8 + uVar4 * 2);
        obj->speed_y_up = *(int *)(&DAT_801ea59c + uVar4 * 4);
      }
      obj->field_0x5c = 0x33;
      obj->field_0x4 = 0;
      obj->field_0x58 = obj->field_0x58 & 0xf;
      obj->sub3 = obj->sub3 + 1;
    }
  }
  return;
}


// ---- 801de8a8 FUN_801de8a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de8a8(MM8Obj *obj)

{
  undefined1 uVar1;
  bool bVar2;
  char cVar3;
  undefined1 *puVar4;
  
  cVar3 = obj->field_0x4;
  puVar4 = &obj->field_0x5e;
  if (cVar3 == '\0') {
    obj->field_0x5c = 0xb3;
    obj->field_0x58 = obj->field_0x58 + '\x10';
    uVar1 = (&DAT_801ea580)[(byte)obj->field_0x5a];
    obj->field_0x4 = 1;
    obj->field_0x54 = uVar1;
    if ((byte)obj->field_0x58 >> 4 < (byte)(&DAT_801ea57c)[(byte)obj->field_0x5a])
    goto LAB_801de994;
    obj->field_0x54 = 0x5a;
    cVar3 = '\x02';
  }
  else if (cVar3 == '\x01') {
    obj->field_0x5c = 0x33;
    cVar3 = obj->field_0x54 + -1;
    obj->field_0x54 = cVar3;
    if (cVar3 != '\0') goto LAB_801de994;
    cVar3 = obj->field_0x4 + -1;
  }
  else {
    if (cVar3 != '\x02') goto LAB_801de994;
    obj->field_0x5c = 0x33;
    cVar3 = obj->field_0x54 + -1;
    obj->field_0x54 = cVar3;
    if (cVar3 != '\0') goto LAB_801de994;
    cVar3 = obj->field_0x4 + '\x01';
  }
                    /* Possible PsyQ macro: setLineF2() */
  obj->field_0x4 = cVar3;
LAB_801de994:
  FUN_80104d18(obj);
  if (obj->speed_y_up < 1) {
    bVar2 = false;
    if (*(short *)puVar4 <= obj->y) {
      bVar2 = true;
    }
  }
  else {
    bVar2 = obj->y <= *(short *)puVar4;
  }
  if (bVar2) {
    obj->speed_y_up = 0;
    obj->y_frac = (short)((int)*(short *)puVar4 << 0x10);
    obj->y = (short)((uint)((int)*(short *)puVar4 << 0x10) >> 0x10);
    if (obj->field_0x4 == '\x03') {
      obj->field_0x4 = 0;
      obj->sub3 = obj->sub3 + 1;
    }
  }
  else {
    FUN_801dfc74(obj,obj->speed_y_up);
  }
  return;
}


// ---- 801df85c FUN_801df85c

void FUN_801df85c(int param_1)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)FUN_801055e4();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x33;
    puVar2[7] = 3;
    puVar2[0x26] = 8;
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + 8;
    sVar1 = *(short *)(param_1 + 0x12);
    *(int *)(puVar2 + 0x4c) = param_1;
    *(short *)(puVar2 + 0x12) = sVar1 + -0x16;
  }
  puVar2 = (undefined1 *)FUN_801055e4(param_1);
  if (puVar2 != (undefined1 *)0x0) {
    puVar2[6] = 0x33;
    *puVar2 = 1;
    puVar2[7] = 1;
    puVar2[0x26] = 7;
    *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    sVar1 = *(short *)(param_1 + 0x12);
    *(int *)(puVar2 + 0x4c) = param_1;
    *(short *)(puVar2 + 0x12) = sVar1 + -0x20;
  }
  puVar2 = (undefined1 *)FUN_801055e4(param_1);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x33;
    puVar2[7] = 2;
    puVar2[0x26] = 9;
    *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    sVar1 = *(short *)(param_1 + 0x12);
    *(int *)(puVar2 + 0x4c) = param_1;
    *(short *)(puVar2 + 0x12) = sVar1 + 0x10;
  }
  return;
}


// ---- 801df960 FUN_801df960

undefined1 FUN_801df960(int param_1)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = Rand();
  uVar1 = uVar1 & 0xf;
  if (DAT_8015e248._2_2_ < 0x40) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
    if (0x80 < DAT_8015e248._2_2_) {
      iVar5 = 2;
    }
  }
  if ((*(byte *)(param_1 + 0x5b) & 1) != 0) {
    iVar5 = iVar5 + 3;
  }
  iVar2 = FUN_801dfb48(param_1);
  iVar4 = 0;
  pbVar3 = &DAT_801ea558 + iVar5 * 3;
  do {
    uVar1 = uVar1 - *pbVar3;
    if ((int)(uVar1 * 0x10000) < 0) {
      return (&UNK_801ea56c)[iVar4 + iVar2 * 3];
    }
    iVar4 = iVar4 + 1;
    pbVar3 = pbVar3 + 1;
  } while (iVar4 < 3);
  return 0;
}


// ---- 801dfa54 FUN_801dfa54

int FUN_801dfa54(int param_1)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = Rand();
  uVar1 = uVar1 & 0xf;
  iVar2 = FUN_801dfb48(param_1);
  if (1 < (*(byte *)(param_1 + 0x58) & 0xf)) {
    iVar2 = iVar2 + 5;
  }
  if (5 < (*(byte *)(param_1 + 0x5d) & 0xf)) {
    iVar2 = iVar2 + 10;
    *(byte *)(param_1 + 0x5d) = *(byte *)(param_1 + 0x5d) & 0xf0;
  }
  iVar4 = 0;
  iVar5 = iVar2;
  if (((*(byte *)(param_1 + 0x5b) & 1) != 0) &&
     (iVar5 = iVar2 + 0xf, 0x1f < (*(byte *)(param_1 + 0x5d) & 0xf0))) {
                    /* Possible PsyQ macro: setPolyGT4() */
    iVar5 = iVar2 + 0x1e;
  }
  pbVar3 = &DAT_801ea4a8 + iVar5 * 5;
  do {
    uVar1 = uVar1 - *pbVar3;
    if ((int)(uVar1 * 0x10000) < 0) {
      return (int)(char)iVar4;
    }
    iVar4 = iVar4 + 1;
    pbVar3 = pbVar3 + 1;
  } while (iVar4 < 5);
  return 0;
}


// ---- 801dfb48 FUN_801dfb48

int FUN_801dfb48(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)((((uint)*(ushort *)(param_1 + 0x12) - (uint)*(ushort *)(param_1 + 0x52)) + 0x10) *
               0x10000) >> 0x10;
  iVar1 = 3;
  if (-1 < iVar2) {
    if (iVar2 == 0) {
      iVar1 = 1;
    }
    else if (iVar2 == 0x20) {
      iVar1 = 2;
    }
    else {
      iVar1 = (iVar2 < 0x21 ^ 1) << 2;
    }
  }
  return iVar1;
}


// ---- 801dfc74 FUN_801dfc74

void FUN_801dfc74(int param_1,int param_2)

{
  char cVar1;
  
  if (param_2 != 0) {
    if (param_2 < 1) {
      cVar1 = *(char *)(param_1 + 0x59) + '\x01';
      *(char *)(param_1 + 0x59) = cVar1;
      if (cVar1 == 'x') {
        *(undefined1 *)(param_1 + 0x59) = 0;
      }
    }
    else {
      cVar1 = *(char *)(param_1 + 0x59) + -1;
      *(char *)(param_1 + 0x59) = cVar1;
      if (cVar1 == -1) {
                    /* Possible PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
        *(undefined1 *)(param_1 + 0x59) = 0x77;
      }
    }
  }
  return;
}


