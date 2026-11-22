// ID 5E, STAGE0C.BIN, handler 0x801E8C9C. Ghidra output with the object struct applied; not matching C.
// ---- 801e8c9c FUN_801e8c9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8c9c(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = obj->state;
  if (((obj->var < 3) || (5 < obj->var)) ||
     ((**(char **)&obj->field_0x4c != '\0' && (DAT_801b29a6 == '\0')))) {
    (*(code *)(&PTR_FUN_801eb060)[bVar1])(obj);
    if (obj->active != 0) {
      if ((obj->anim_extra & 0xf) != 0) {
        Enemy_ContactDamage(obj);
      }
      if ((bVar1 != 0) && (obj->field_0x51 != '\0')) {
        Obj_CullAndQueueDraw(obj);
      }
    }
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e8d88 FUN_801e8d88

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8d88(MM8Obj *obj)

{
  byte bVar1;
  
  Enemy_InitFromTable();
  obj->field_0x43 = 1;
  obj->field_0x51 = 1;
  obj->hitbox = (byte *)0x0;
  obj->box2 = (byte *)0x0;
  obj->draw_list = 8;
  obj->hp = (&DAT_801eb050)[obj->var];
  bVar1 = (&DAT_801eb058)[obj->var];
  obj->state = obj->var + 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->contact_dmg = bVar1;
  (*(code *)(&PTR_FUN_801eb060)[obj->state])(obj);
  return;
}


// ---- 801e8e30 FUN_801e8e30

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8e30(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    FUN_801e9640(*(undefined4 *)&obj->field_0x4c);
    Anim_Set(obj,2);
    iVar1 = 0x30000;
    if ((obj->flip & 0x40) == 0) {
      iVar1 = -0x30000;
    }
    obj->speed_x = iVar1;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->field_0x51 = 1;
    obj->sub2 = obj->sub2 + 1;
  }
  else if (obj->sub2 == 1) {
    Anim_Step(obj);
  }
  FUN_80104c34(obj);
  FUN_801e92dc(obj);
  if ((obj->active != 0) && (iVar1 = Obj_InActiveArea(obj), iVar1 == 0)) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e8f04 FUN_801e8f04

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8f04(MM8Obj *obj)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  short sVar4;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,4);
    obj->field_0x51 = 1;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    pbVar2 = *(byte **)(&DAT_801eb034 + (obj->anim_extra & 0xf) * 4);
    obj->sub2 = obj->sub2 + 1;
    obj->box2 = pbVar2;
  }
  else {
    Anim_Step(obj);
    if ((int)obj->y < DAT_801d292c + -0x80) {
      iVar3 = 0;
      if (obj->field_0x53 == '\0') {
        sVar4 = 0x20;
        do {
          iVar1 = FUN_801e93d0(obj,2,0);
          iVar3 = iVar3 + 1;
          if (iVar1 != 0) {
            *(short *)(iVar1 + 0xe) = DAT_801d2928 + sVar4;
          }
          sVar4 = sVar4 + 0x40;
        } while (iVar3 < 5);
      }
      else {
        sVar4 = 0x40;
        do {
          iVar1 = FUN_801e93d0(obj,2,0);
          iVar3 = iVar3 + 1;
          if (iVar1 != 0) {
            *(short *)(iVar1 + 0xe) = DAT_801d2928 + sVar4;
          }
          sVar4 = sVar4 + 0x40;
        } while (iVar3 < 4);
      }
      Obj_Free(obj);
      return;
    }
  }
  if ((obj->anim_extra & 0x10) != 0) {
    obj->speed_y_up = 0x30000;
    obj->gravity = 0;
  }
  FUN_80104c34(obj);
  FUN_801e92dc(obj);
  return;
}


// ---- 801e908c FUN_801e908c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e908c(MM8Obj *obj)

{
  byte *pbVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,5);
    obj->speed_y_up = -0x50000;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->gravity = 0;
    pbVar1 = *(byte **)(&DAT_801eb034 + (obj->anim_extra & 0xf) * 4);
    obj->field_0x51 = 1;
    obj->sub2 = obj->sub2 + 1;
    obj->box2 = pbVar1;
  }
  else if ((obj->sub2 == 1) && (Anim_Step(obj), (obj->field_0x33 & 0x80) != 0)) {
    obj->hitbox = (byte *)0x0;
    FUN_801e9534(obj);
    Obj_Free(obj);
    return;
  }
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  FUN_801e92dc(obj);
  return;
}


// ---- 801e9168 FUN_801e9168

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9168(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = obj->sub2;
  iVar4 = *(int *)&obj->field_0x4c;
  if (bVar1 == 0) {
    Anim_Set(obj,0x12);
    obj->field_0x50 = 0x24;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->field_0x51 = 1;
    obj->field_0x54 = 0;
    obj->field_0x52 = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else if (bVar1 == 1) {
    Anim_Step(obj);
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 == '\0') {
      Anim_Set(obj,0x14);
      obj->sub2 = obj->sub2 + 1;
    }
    else if (((obj->field_0x50 & 3) == 0) && (obj->field_0x54 != '\0')) {
      FUN_801e9740(obj,1,0);
    }
  }
  else if (bVar1 == 2) {
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    if (iVar3 != 0) {
      obj->field_0x52 = 2;
      Obj_Free(obj);
      return;
    }
  }
  if ((obj->anim_extra & 0x10) != 0) {
    FUN_801e95a0(obj);
    obj->field_0x54 = 1;
  }
  obj->x = obj->x + (*(short *)(iVar4 + 0xe) - *(short *)(iVar4 + 0x34));
  FUN_801e92dc();
  return;
}


// ---- 801e92dc FUN_801e92dc

void FUN_801e92dc(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  
  if ((*(byte *)(param_1 + 0x32) & 0xf) != 0) {
    *(undefined4 *)(param_1 + 0x3c) =
         *(undefined4 *)(&DAT_801eb034 + (*(byte *)(param_1 + 0x32) & 0xf) * 4);
    iVar3 = Enemy_ContactDamage();
    if ((iVar3 == 2) && (*(char *)(param_1 + 7) == '\0')) {
      FUN_801078c0(&g_player,param_1);
      iVar3 = FUN_8012c108(param_1,0,0,0,0,2);
      if (iVar3 != 0) {
        *(undefined1 *)(iVar3 + 0x26) = 5;
        uVar1 = *(undefined1 *)(param_1 + 0x25);
        *(undefined1 *)(iVar3 + 0x27) = 9;
        *(undefined1 *)(iVar3 + 0x25) = uVar1;
        *(char *)(iVar3 + 0x33) = *(char *)(param_1 + 0x24) + '\x03';
        uVar2 = DAT_801b1248;
        *(undefined2 *)(iVar3 + 0xe) = DAT_801b1244;
        *(undefined2 *)(iVar3 + 0x12) = uVar2;
      }
      Obj_Free(param_1);
    }
  }
  return;
}


// ---- 801e93d0 FUN_801e93d0

undefined1 * FUN_801e93d0(int param_1,byte param_2,byte param_3)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)FUN_801055e4();
  if (puVar2 == (undefined1 *)0x0) {
    return (undefined1 *)0x0;
  }
  *puVar2 = 1;
  puVar2[6] = 0x5e;
  puVar2[7] = param_2;
  *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_1 + 0xe);
  *(undefined2 *)(puVar2 + 0x12) = *(undefined2 *)(param_1 + 0x12);
  if (param_2 == 0) {
    if ((param_3 & 0x40) == 0) {
      sVar1 = *(short *)(puVar2 + 0xe) + -0x2c;
    }
    else {
      sVar1 = *(short *)(puVar2 + 0xe) + 0x2c;
    }
    *(short *)(puVar2 + 0xe) = sVar1;
    sVar1 = *(short *)(puVar2 + 0x12) + -6;
  }
  else {
    if (param_2 == 1) {
      if ((param_3 & 0x40) == 0) {
        sVar1 = *(short *)(puVar2 + 0xe) + -4;
      }
      else {
        sVar1 = *(short *)(puVar2 + 0xe) + 4;
      }
      *(short *)(puVar2 + 0xe) = sVar1;
      *(short *)(puVar2 + 0x12) = *(short *)(puVar2 + 0x12) + -0x30;
      puVar2[0x53] = *(undefined1 *)(param_1 + 0x56);
      goto LAB_801e94f8;
    }
    if (param_2 < 3) goto LAB_801e94f8;
    if ((param_3 & 0x40) == 0) {
      sVar1 = *(short *)(puVar2 + 0xe) + -0xc;
    }
    else {
      sVar1 = *(short *)(puVar2 + 0xe) + 0xc;
    }
    *(short *)(puVar2 + 0xe) = sVar1;
    sVar1 = DAT_801d292c + 0xa0;
  }
  *(short *)(puVar2 + 0x12) = sVar1;
LAB_801e94f8:
  puVar2[0x25] = param_3;
  *(int *)(puVar2 + 0x4c) = param_1;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  return puVar2;
}


// ---- 801e9534 FUN_801e9534

int FUN_801e9534(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_8012c108(param_1,0,0,0,0,6);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 7) = 0;
    *(undefined1 *)(iVar1 + 0x26) = 5;
  }
  FUN_8010544c(param_1,0x1d7);
  return iVar1;
}


// ---- 801e95a0 FUN_801e95a0

int FUN_801e95a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_8012c108(param_1,param_1 + 0x52,0,0,0,0xd);
  if (iVar1 != 0) {
                    /* Probable PsyQ macro: setTile() */
    *(undefined1 *)(iVar1 + 7) = 0x60;
    *(undefined1 *)(iVar1 + 0x26) = 8;
  }
  iVar1 = FUN_8012c108(param_1,param_1 + 0x52,0,0,0,0xe);
  if (iVar1 != 0) {
                    /* Probable PsyQ macro: setTile() */
    *(undefined1 *)(iVar1 + 7) = 0x60;
    *(undefined1 *)(iVar1 + 0x26) = 7;
  }
  return iVar1;
}


// ---- 801e9640 FUN_801e9640

int FUN_801e9640(int param_1)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 0x24;
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    sVar2 = -0x24;
  }
  iVar1 = FUN_8012c108(param_1,0,(int)sVar2,0xfffffffa,0,3);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x26) = 6;
    *(undefined1 *)(iVar1 + 7) = 0;
    *(undefined1 *)(iVar1 + 0x27) = 9;
    *(char *)(iVar1 + 0x33) = *(char *)(param_1 + 0x24) + '\x04';
  }
  return iVar1;
}


// ---- 801e9740 FUN_801e9740

undefined1 * FUN_801e9740(int param_1,undefined1 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x3f;
    puVar2[7] = param_2;
    puVar2[0x24] = *(undefined1 *)(param_1 + 0x24);
    *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    uVar1 = *(undefined2 *)(param_1 + 0x12);
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    *(int *)(puVar2 + 0x1c) = param_1;
    *(undefined4 *)(puVar2 + 0x3c) = param_3;
    *(undefined2 *)(puVar2 + 0x12) = uVar1;
  }
  return puVar2;
}


// ---- 801e9814 FUN_801e9814

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9814(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->field_0x55 = 0;
  obj->flip = 0;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->state = obj->var + 1;
  obj->draw_list = 7;
  (*(code *)(&PTR_FUN_801eb07c)[obj->state])(obj);
  return;
}


// ---- 801e9884 FUN_801e9884

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9884(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = DAT_801b29a5 & 0x7f;
  bVar1 = obj->sub2;
  if ((DAT_801b29a5 & 0x80) != 0) {
    DAT_801b29a5 = bVar2;
    obj->sub2 = bVar2;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    bVar1 = DAT_801b29a5;
  }
  (*(code *)(&PTR_LAB_801eb094)[bVar1])(obj);
  if ((obj->active != 0) && (obj->field_0x55 != '\0')) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e9ea4 FUN_801e9ea4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Possible GS_106.OBJ/GsSetProjection
   Possible _OP_VDEL.OBJ/__builtin_vec_delete
   Possible _OP_VNEW.OBJ/__builtin_vec_new
   Possible SCNOFF.OBJ/SsSetNoiseOff
   Possible SSQUIT.OBJ/SsQuit */

void FUN_801e9ea4(MM8Obj *obj)

{
  Obj_Free();
  return;
}


