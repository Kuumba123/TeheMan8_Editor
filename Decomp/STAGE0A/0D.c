// ID 0D, STAGE0A.BIN, handler 0x801DAAE8. Ghidra output with the object struct applied; not matching C.
// ---- 801daae8 FUN_801daae8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daae8(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e1d6c)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801dab50 FUN_801dab50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dab50(MM8Obj *obj)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  
  Enemy_InitFromTable();
  obj->state = 1;
  obj->field_0x5f = 0;
  obj->field_0x5d = obj->var >> 4;
  obj->var = obj->var & 0xf;
  bVar3 = Rand();
  cVar2 = DAT_80159f85;
  bVar3 = bVar3 & 3;
  if ((1 < obj->var) && (bVar3 == 3)) {
    bVar3 = 2;
  }
  obj->draw_list = 5;
  obj->hitbox = &DAT_801e1d58;
  obj->box2 = (byte *)0x0;
  obj->field_0x55 = cVar2 + bVar3;
  obj->clut = cVar2 + bVar3;
  Anim_Set(obj,2);
  if (obj->var < 2) {
    obj->field_0x59 = 0x14;
    obj->sub2 = 0;
    obj->field_0x5b = 1;
    uVar4 = FUN_801db7e8();
    obj->field_0x5a = uVar4;
                    /* Probable PsyQ macro: setLineF2() */
    obj->field_0x5c = 0x40;
    if (obj->var == 0) {
      FUN_8010910c(obj);
    }
    else {
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
      obj->x = obj->x + -0x17c;
    }
    uVar4 = 1;
    if ((obj->flip & 0x40) == 0) {
      obj->field_0x56 = 3;
      uVar4 = 0xff;
    }
    else {
      obj->field_0x56 = 0;
    }
    obj->field_0x58 = uVar4;
    if ((int)obj->y - (int)g_cam_y < 0x79) {
      obj->field_0x57 = 1;
      obj->field_0x51 = 0;
    }
    else {
      obj->field_0x57 = 3;
      obj->field_0x51 = 0x80;
    }
    *(undefined2 *)&obj->field_0x52 =
         *(undefined2 *)
          (&DAT_801e1c9c + ((uint)(byte)obj->field_0x56 * 2 + (uint)(byte)obj->field_0x57 * 8) * 2);
    uVar4 = (&DAT_801e1c9e)[((uint)(byte)obj->field_0x56 * 2 + (uint)(byte)obj->field_0x57 * 8) * 2]
    ;
    obj->field_0x50 = 1;
    obj->field_0x54 = uVar4;
  }
  else {
    obj->sub2 = 1;
    obj->draw_list = 7;
                    /* Possible PsyQ macro: setTile8() */
    obj->flip = 0;
    if (obj->var == 2) {
      uVar5 = Rand(obj);
      obj->field_0x58 = (&DAT_801e1d5c)[uVar5 & 7];
    }
    else {
      uVar5 = Rand(obj);
      obj->field_0x58 = (&DAT_801e1d64)[uVar5 & 7];
    }
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->speed_x = -0x10000;
    obj->speed_y_up = 0x8000;
    obj->accel_x = (int)*(short *)(&DAT_801e1d0e + (uint)(byte)obj->field_0x58 * 8) << 8;
    sVar1 = *(short *)(&DAT_801e1d12 + (uint)(byte)obj->field_0x58 * 8);
    obj->field_0x50 = 0x30;
    obj->field_0x5e = 0;
    obj->gravity = (int)sVar1 << 8;
  }
  return;
}


// ---- 801dadd4 FUN_801dadd4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dadd4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    FUN_801daeac();
  }
  else {
    FUN_801db2f8(obj);
  }
  iVar2 = Enemy_CheckWeaponHits(obj);
  if (iVar2 == 2) {
    obj->clut = 0;
  }
  else {
    obj->clut = obj->field_0x55;
  }
  if (iVar2 == 4) {
    obj->state = 2;
    obj->sub2 = 0;
    obj->sub3 = 0;
  }
  else {
    if (obj->var < 2) {
      if ((0 < obj->speed_x) || (bVar1 = 0, obj->var != 0)) {
        bVar1 = 0x40;
      }
      obj->flip = bVar1;
    }
    FUN_801db574(obj);
    Anim_Step(obj);
  }
  return;
}


// ---- 801daeac FUN_801daeac

void FUN_801daeac(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  
  (*(code *)(&PTR_FUN_801e1d78)[*(byte *)(param_1 + 3)])();
  cVar1 = *(char *)(param_1 + 0x59) + -1;
  *(char *)(param_1 + 0x59) = cVar1;
  if (cVar1 == '\0') {
    if (*(char *)(param_1 + 0x5b) != '\0') {
      FUN_801db6d0(param_1);
    }
    cVar1 = *(char *)(param_1 + 0x5a) + -1;
    *(char *)(param_1 + 0x5a) = cVar1;
    if (cVar1 == '\0') {
      *(byte *)(param_1 + 0x5b) = *(byte *)(param_1 + 0x5b) ^ 1;
      if (*(char *)(param_1 + 0x5b) == '\0') {
        uVar3 = Rand();
        cVar1 = (&DAT_801e1d48)[uVar3 & 7];
        if (*(char *)(param_1 + 7) != '\0') {
          cVar1 = cVar1 + '\x02';
        }
        *(char *)(param_1 + 0x5a) = cVar1;
      }
      else {
        uVar2 = FUN_801db7e8(param_1);
        *(undefined1 *)(param_1 + 0x5a) = uVar2;
      }
    }
    uVar2 = 0x14;
    if (*(char *)(param_1 + 7) != '\0') {
      uVar2 = (&DAT_801e1d2c)[*(byte *)(param_1 + 0x5d)];
    }
    *(undefined1 *)(param_1 + 0x59) = uVar2;
    cVar1 = *(char *)(param_1 + 0x5c) + -1;
    *(char *)(param_1 + 0x5c) = cVar1;
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 3) = 2;
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
  return;
}


// ---- 801dafe4 FUN_801dafe4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dafe4(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  FUN_80104c34();
                    /* Possible PsyQ macro: setTile16() */
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    iVar2 = (uint)DAT_801d2918._2_2_ + (uint)*(ushort *)&obj->field_0x52;
    iVar3 = FUN_80104db0((int)obj->x,(int)obj->y,iVar2 * 0x10000 >> 0x10,
                         (int)(((uint)(byte)obj->field_0x54 + (uint)g_cam_y) * 0x10000) >> 0x10);
    cVar1 = obj->var * '\b' + '\b';
    if ((int)((iVar3 - (uint)(byte)obj->field_0x51) * 0x1000000) < 0) {
      cVar1 = -cVar1;
    }
    obj->field_0x51 = obj->field_0x51 + cVar1;
    FUN_80105120(obj,0x200,obj->field_0x51);
    if (obj->var != 0) {
      obj->speed_x = *(short *)(&DAT_801e1cfc + (uint)(byte)obj->field_0x5d * 2) * 0x100 +
                     obj->speed_x;
    }
    obj->field_0x50 = 6;
    iVar2 = (int)obj->x - (int)(short)iVar2;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 < 0x10) {
      obj->sub3 = 1;
    }
  }
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  return;
}


// ---- 801db124 FUN_801db124

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db124(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  byte bVar5;
  
  cVar1 = obj->field_0x56;
  cVar2 = obj->field_0x57;
  obj->sub3 = 0;
  uVar4 = Rand();
  bVar5 = (&DAT_801e1cec)[uVar4 & 0xf];
  if ('\x02' < cVar1) {
    obj->field_0x58 = 0xff;
  }
  if (obj->var == 0) {
    if (cVar1 != '\0') goto LAB_801db1b0;
  }
  else if (('\x02' < cVar1) || (-1 < (char)obj->field_0x58)) goto LAB_801db1b0;
  obj->field_0x58 = 1;
LAB_801db1b0:
  if ((cVar2 == '\0') && ((int)((uint)bVar5 << 0x18) < 0)) {
    bVar5 = 1;
  }
  if (('\x03' < cVar2) && (0 < (int)((uint)bVar5 << 0x18))) {
    bVar5 = 0xff;
  }
  obj->field_0x56 = obj->field_0x56 + obj->field_0x58;
  obj->field_0x57 = bVar5 + obj->field_0x57;
  *(undefined2 *)&obj->field_0x52 =
       *(undefined2 *)
        (&DAT_801e1c9c + ((uint)(byte)obj->field_0x56 * 2 + (uint)(byte)obj->field_0x57 * 8) * 2);
  uVar3 = (&DAT_801e1c9e)[((uint)(byte)obj->field_0x56 * 2 + (uint)(byte)obj->field_0x57 * 8) * 2];
  obj->field_0x50 = 6;
  obj->field_0x54 = uVar3;
  return;
}


// ---- 801db274 FUN_801db274

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db274(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    obj->gravity = 0;
    obj->field_0x4 = obj->field_0x4 + '\x01';
    obj->accel_x = (uint)(obj->var != 0) << 0xe;
  }
  FUN_80104c9c(obj);
  if ((obj->var != 0) && (0xa0000 < obj->speed_x)) {
    obj->accel_x = 0;
  }
  return;
}


// ---- 801db2f8 FUN_801db2f8

void FUN_801db2f8(int param_1)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  
  bVar1 = *(byte *)(param_1 + 3);
  if (bVar1 == 1) {
    cVar3 = *(char *)(param_1 + 0x50) + -1;
    *(char *)(param_1 + 0x50) = cVar3;
    if (cVar3 == '\0') {
      *(undefined1 *)(param_1 + 0x26) = 5;
      *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + '\x01';
      *(int *)(param_1 + 0x14) =
           (int)*(short *)(&DAT_801e1d0c + (uint)*(byte *)(param_1 + 0x58) * 8) << 8;
      sVar2 = *(short *)(&DAT_801e1d10 + (uint)*(byte *)(param_1 + 0x58) * 8);
      *(undefined1 *)(param_1 + 0x59) = 10;
      *(int *)(param_1 + 0x18) = (int)sVar2 << 8;
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      FUN_80104c34(param_1);
      cVar3 = *(char *)(param_1 + 0x50) + -1;
      *(char *)(param_1 + 0x50) = cVar3;
      if (cVar3 == '\0') {
        *(undefined1 *)(param_1 + 0x50) = 0xf;
        *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + '\x01';
      }
    }
  }
  else if (bVar1 == 2) {
    if (*(int *)(param_1 + 0x14) < -0x5ffff) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    if (*(int *)(param_1 + 0x18) < -0x5ffff) {
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
    Obj_ApplySpeed(param_1);
    cVar3 = *(char *)(param_1 + 0x59) + -1;
    *(char *)(param_1 + 0x59) = cVar3;
    if (cVar3 == '\0') {
      FUN_801db6d0(param_1);
      *(undefined1 *)(param_1 + 0x59) = 10;
    }
  }
  return;
}


// ---- 801db464 FUN_801db464

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db464(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    iVar2 = -0x20000;
    obj->sub2 = obj->sub2 + 1;
    if ((obj->flip & 0x40) != 0) {
      iVar2 = 0x20000;
    }
    obj->speed_y_up = -0x20000;
    obj->speed_x = iVar2;
    obj->field_0x50 = 0x2d;
    Anim_Set(obj,5);
    FUN_80108fd8(obj,0);
  }
  else if (obj->sub2 != 1) goto LAB_801db558;
  FUN_80104c34(obj);
                    /* Possible PsyQ macro: setPolyG3() + setSemiTrans(polyG3, 1) */
  if ((uint)(byte)obj->field_0x50 % 5 == 0) {
    FUN_801db774(obj);
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,4);
    Obj_FreeDespawn(obj);
  }
LAB_801db558:
  Anim_Step(obj);
  return;
}


// ---- 801db574 FUN_801db574

void FUN_801db574(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_80170574 & 1) != 0) {
    return;
  }
  switch(*(undefined1 *)(param_1 + 0x5f)) {
  case 0:
    if (-1 < *(int *)(param_1 + 0x18)) {
      if (*(int *)(param_1 + 0x18) < 1) {
        return;
      }
      goto LAB_801db6a8;
    }
    *(undefined1 *)(param_1 + 0x5f) = 1;
    uVar1 = 1;
    goto LAB_801db6b4;
  case 1:
    if (*(short *)(param_1 + 0x2e) < 0) {
      *(char *)(param_1 + 0x5f) = *(char *)(param_1 + 0x5f) + '\x01';
      Anim_Set(param_1,0);
    }
switchD_801db5b8_caseD_2:
    if (-1 < *(int *)(param_1 + 0x18)) {
      if (*(char *)(param_1 + 0x5f) == '\x01') {
        *(undefined1 *)(param_1 + 0x5f) = 0;
        uVar1 = 2;
      }
      else {
        *(undefined1 *)(param_1 + 0x5f) = 1;
        uVar1 = 1;
      }
LAB_801db6b4:
      Anim_Set(param_1,uVar1);
    }
switchD_801db5b8_default:
    return;
  case 2:
    goto switchD_801db5b8_caseD_2;
  case 3:
    if (*(short *)(param_1 + 0x2e) < 0) {
      *(char *)(param_1 + 0x5f) = *(char *)(param_1 + 0x5f) + '\x01';
      Anim_Set(param_1,4);
    }
  case 4:
    if (0 < *(int *)(param_1 + 0x18)) {
      return;
    }
    if (*(char *)(param_1 + 0x5f) == '\x03') {
      *(undefined1 *)(param_1 + 0x5f) = 0;
      uVar1 = 2;
    }
    else {
LAB_801db6a8:
      *(undefined1 *)(param_1 + 0x5f) = 3;
      uVar1 = 3;
    }
    goto LAB_801db6b4;
  default:
    goto switchD_801db5b8_default;
  }
}


// ---- 801db6d0 FUN_801db6d0

void FUN_801db6d0(int param_1)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 5;
    puVar2[7] = 0;
    sVar1 = -8;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar1 = 8;
    }
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + sVar1;
    *(short *)(puVar2 + 0x12) = *(short *)(param_1 + 0x12) + 8;
    puVar2[7] = *(char *)(param_1 + 7) != '\0';
    puVar2[0x24] = *(undefined1 *)(param_1 + 0x55);
    puVar2[0x38] = (&DAT_801e1d50)[*(byte *)(param_1 + 0x5e)];
  }
  return;
}


// ---- 801db774 FUN_801db774

void FUN_801db774(int param_1)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0xf;
    puVar2[7] = 0;
    *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    sVar1 = *(short *)(param_1 + 0x12);
    puVar2[0x25] = 0;
    puVar2[0x27] = 2;
    puVar2[0x26] = 2;
    puVar2[0x38] = 0;
    puVar2[0x39] = 0;
    *(short *)(puVar2 + 0x12) = sVar1 + -8;
  }
  return;
}


// ---- 801db7e8 FUN_801db7e8

uint FUN_801db7e8(int param_1)

{
  uint uVar1;
  char *pcVar2;
  
  pcVar2 = &g_main_pool;
  *(undefined1 *)(param_1 + 0x5e) = 0xff;
  do {
    if ((*pcVar2 == '\x01') && (pcVar2[6] == '\r')) {
      *(char *)(param_1 + 0x5e) = *(char *)(param_1 + 0x5e) + '\x01';
    }
    pcVar2 = pcVar2 + 0x60;
  } while (pcVar2 < &DAT_8015c974);
  if (4 < *(byte *)(param_1 + 0x5e)) {
    *(undefined1 *)(param_1 + 0x5e) = 4;
  }
  uVar1 = Rand();
  uVar1 = (uint)(byte)(&DAT_801e1d30)[(uint)*(byte *)(param_1 + 0x5e) * 4 + (uVar1 & 7)];
  if (*(char *)(param_1 + 7) != '\0') {
    uVar1 = uVar1 - 2;
  }
  return uVar1;
}


