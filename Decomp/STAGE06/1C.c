// ID 1C, STAGE06.BIN, handler 0x801D970C. Ghidra output with the object struct applied; not matching C.
// ---- 801d970c FUN_801d970c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d970c(MM8Obj *obj)

{
  int iVar1;
  
  obj->field_0x4 = 0;
  (*(code *)(&PTR_FUN_801e5708)[obj->state])();
  if (obj->active != 0) {
    FUN_801da3f8(obj);
    if (obj->field_0x4 == '\0') {
      Obj_CullAndQueueDraw(obj);
    }
    iVar1 = Obj_InActiveArea(obj);
    if ((iVar1 == 0) && (*(short *)&obj->field_0x50 != 4)) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801d97ac FUN_801d97ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d97ac(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  obj->draw_list = 8;
  obj->hitbox = &DAT_801e5740;
  obj->box2 = &DAT_801e5728;
  obj->flip = 0;
  obj->field_0x43 = 1;
  obj->field_0x50 = 4;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  obj->field_0x58 = 0;
  obj->field_0x59 = 0;
  obj->field_0x5a = 0;
  obj->field_0x5b = 0;
  obj->field_0x5c = 0;
  if ((obj->var & 1) == 0) {
    obj->state = 1;
  }
  else {
    obj->state = 2;
  }
  obj->sub2 = 0;
  iVar1 = FUN_8012c108(obj,&obj->field_0x52,0,0,0,8);
  if (iVar1 != 0) {
                    /* Probable PsyQ macro: setTile16() */
    *(undefined1 *)(iVar1 + 7) = 0x70;
    *(byte *)(iVar1 + 0x26) = obj->draw_list - 1;
  }
  FUN_801093d4(iVar1,&obj->field_0x54);
  Anim_Set(obj,0);
                    /* Possible PsyQ macro: setTile8() */
  return;
}


// ---- 801d989c FUN_801d989c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d989c(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_80107bf4(obj,&g_player,1);
  Enemy_CheckWeaponHits(obj);
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801da260(obj);
  obj->field_0x53 = cVar2;
  if (cVar1 != cVar2) {
    if (obj->field_0x53 == '\0') {
      obj->sub2 = 0;
    }
    else {
      iVar3 = FUN_801da4b0(obj);
      if (iVar3 != 0) {
        uVar4 = FUN_801093fc(&obj->field_0x54);
        FUN_801da5b8(obj,uVar4);
      }
      obj->sub2 = 1;
    }
  }
  if (obj->sub2 == 0) {
    uVar4 = 0;
  }
  else {
    if (obj->sub2 != 1) {
      return;
    }
    uVar4 = 1;
  }
  Anim_Set(obj,uVar4);
  obj->sub2 = 2;
  return;
}


// ---- 801d9978 FUN_801d9978

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9978(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (obj->sub2 == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 3;
    if (obj->sub2 != 1) goto LAB_801d99c0;
  }
  Anim_Set(obj,uVar3);
  obj->sub2 = 2;
LAB_801d99c0:
  FUN_80107bf4(obj,&g_player,1);
  Enemy_CheckWeaponHits(obj);
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801da260(obj);
  obj->field_0x53 = cVar2;
  if ((cVar1 != cVar2) && (obj->field_0x53 != '\0')) {
    if (obj->field_0x50 == '\x04') {
      obj->field_0x51 = 0x21;
      obj->state = 3;
      obj->sub2 = 0;
    }
    FUN_8010544c(obj,0x92);
  }
  return;
}


// ---- 801d9a4c FUN_801d9a4c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9a4c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  
  bVar2 = obj->sub2;
  if (bVar2 == 0) {
    Anim_Set(obj,3);
    bVar2 = obj->sub2;
    obj->field_0x43 = 1;
  }
  else {
    if (bVar2 != 1) {
      if (bVar2 == 2) {
        Anim_Set(obj,4);
        obj->gravity = 0x4000;
        obj->speed_y_up = 0;
        obj->sub2 = obj->sub2 + 1;
      }
      else {
        Anim_Step(obj);
      }
      goto LAB_801d9b1c;
    }
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->hitbox = &DAT_801e5744;
      obj->box2 = &DAT_801e5730;
    }
    iVar4 = Anim_AtLoopMarker(obj);
    if (iVar4 == 0) goto LAB_801d9b1c;
    bVar2 = obj->sub2;
  }
  obj->sub2 = bVar2 + 1;
LAB_801d9b1c:
  FUN_80104ccc(obj);
  FUN_801da648(obj);
  FUN_80106214(obj);
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  cVar1 = obj->field_0x53;
  cVar3 = FUN_801da260(obj);
  obj->field_0x53 = cVar3;
  if (((cVar1 != cVar3) && (obj->field_0x53 != '\0')) && (iVar4 = FUN_801da4b0(obj), iVar4 != 0)) {
    uVar5 = FUN_801093fc(&obj->field_0x54);
    FUN_801da5b8(obj,uVar5);
  }
  pbVar6 = obj->hitbox;
  obj->hitbox = &DAT_801e574c;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar6;
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x43 = 0;
    obj->state = 4;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801d9bf4 FUN_801d9bf4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9bf4(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
  if (obj->sub2 == 0) {
                    /* Possible PsyQ macro: setPolyF4() */
    if ((obj->field_0x50 == '\x04') && (iVar3 = FUN_801da4b0(), iVar3 != 0)) {
      uVar4 = FUN_801093fc(&obj->field_0x54);
      FUN_801da5b8(obj,uVar4);
    }
    Anim_Set(obj,5);
    obj->field_0x43 = 0;
    obj->accel_x = 0;
    obj->speed_x = 0;
    obj->gravity = 0;
    obj->speed_y_up = 0;
    obj->field_0x58 = (char)obj->frame;
    obj->field_0x5b = (char)obj->y;
    obj->field_0x5c = (char)((ushort)obj->y >> 8);
    obj->sub2 = obj->sub2 + 1;
  }
  else if (obj->sub2 == 1) {
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    if (iVar3 != 0) {
      obj->state = 5;
      obj->sub2 = 0;
    }
  }
  obj->y = *(short *)&obj->field_0x5b;
  FUN_80106214(obj);
                    /* Probable PsyQ macro: setTile16() */
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801da32c(obj);
  obj->field_0x53 = cVar2;
  if (((cVar1 != cVar2) && (obj->field_0x53 != '\0')) && (iVar3 = FUN_801da4b0(obj), iVar3 != 0)) {
    uVar4 = FUN_801093fc(&obj->field_0x54);
    FUN_801da5b8(obj,uVar4);
  }
  obj->y = *(short *)&obj->field_0x5b;
  obj->y = *(short *)&obj->field_0x5b + ((obj->frame & 0x7fff) - (ushort)(byte)obj->field_0x58);
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  pbVar5 = obj->hitbox;
  obj->hitbox = &DAT_801e574c;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar5;
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801d9da8 FUN_801d9da8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9da8(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,6);
    obj->field_0x5d = 0xf;
    obj->y = (ushort)(byte)obj->field_0x5b;
    obj->y = CONCAT11(obj->field_0x5c,obj->field_0x5b);
    obj->sub2 = obj->sub2 + 1;
  }
  else if ((obj->sub2 == 1) &&
          (cVar1 = obj->field_0x5d + -1, obj->field_0x5d = cVar1, cVar1 == '\0')) {
    obj->state = 6;
    obj->sub2 = 0;
  }
  FUN_80106214(obj);
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801da32c(obj);
  obj->field_0x53 = cVar2;
  if (((cVar1 != cVar2) && (obj->field_0x53 != '\0')) && (iVar3 = FUN_801da4b0(obj), iVar3 != 0)) {
    uVar4 = FUN_801093fc(&obj->field_0x54);
    FUN_801da5b8(obj,uVar4);
    obj->state = 4;
    obj->sub2 = 0;
  }
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  pbVar5 = obj->hitbox;
  obj->hitbox = &DAT_801e574c;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar5;
  return;
}


// ---- 801d9ee4 FUN_801d9ee4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ee4(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  short sVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  byte *pbVar7;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,7);
    FUN_801da668(obj);
    obj->field_0x5d = 0x1e;
    obj->field_0x58 = 0;
    obj->field_0x5b = (char)obj->y;
                    /* Possible PsyQ macro: setPolyF4() */
    obj->field_0x5c = (char)((ushort)obj->y >> 8);
    obj->sub2 = obj->sub2 + 1;
  }
  else if (obj->sub2 == 1) {
    Anim_Step(obj);
    obj->field_0x58 = obj->field_0x58 + '\x01';
  }
  if (0x17 < (byte)obj->field_0x58) {
    obj->field_0x58 = 0;
  }
  sVar3 = *(short *)&obj->field_0x5b;
  sVar2 = obj->prev_y;
  obj->y = sVar3;
  obj->prev_y = sVar3;
  FUN_80104c34(obj);
  FUN_80106214(obj);
  cVar1 = obj->field_0x53;
  cVar4 = FUN_801da32c(obj);
  obj->field_0x53 = cVar4;
  if ((cVar1 != cVar4) && (obj->field_0x53 != '\0')) {
    iVar5 = FUN_801da4b0(obj);
    if (iVar5 != 0) {
      uVar6 = FUN_801093fc(&obj->field_0x54);
      FUN_801da5b8(obj,uVar6);
    }
    obj->state = 4;
    obj->sub2 = 0;
  }
  obj->prev_y = sVar2;
  obj->y = sVar3;
  obj->y = (char)(&DAT_801e575c)[(byte)obj->field_0x58 / 3] + sVar3;
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  pbVar7 = obj->hitbox;
  obj->hitbox = &DAT_801e574c;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar7;
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->speed_x = -obj->speed_x;
  }
  iVar5 = FUN_801da6a0(obj);
  if (iVar5 != 0) {
    obj->speed_x = -obj->speed_x;
  }
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->state = 3;
    obj->sub2 = 2;
  }
  if (obj->state == 4) {
    obj->y = (ushort)(byte)obj->field_0x5b;
    obj->y = *(short *)&obj->field_0x5b;
  }
  return;
}


// ---- 801da12c caseD_1

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801da0dc::caseD_1(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = obj->sub2;
  if (bVar2 == 0) {
    iVar3 = FUN_8012c108(obj,0,0,0,0,0);
    if (iVar3 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
      *(undefined1 *)(iVar3 + 0x27) = 0x34;
      *(undefined1 *)(iVar3 + 0x26) = 8;
      *(undefined1 *)(iVar3 + 7) = 0x10;
    }
    FUN_8010544c(obj,9);
                    /* Probable PsyQ macro: setLineF2() */
    FUN_8012a5fc(obj,3);
    obj->field_0x52 = 2;
    bVar2 = obj->sub2;
    obj->field_0x5d = 0;
    obj->field_0x4 = 1;
  }
  else if (bVar2 == 1) {
    obj->field_0x4 = 1;
    cVar1 = obj->field_0x5d + '\x01';
    obj->field_0x5d = cVar1;
    if (cVar1 != '\x01') {
      return;
    }
    bVar2 = obj->sub2;
    obj->contact_dmg = 6;
  }
  else {
    if (bVar2 != 2) {
      Obj_FreeDespawn(obj);
      return;
    }
    obj->field_0x4 = 1;
    obj->hitbox = &DAT_801e5750;
    Enemy_ContactDamage(obj);
    bVar2 = obj->field_0x5d + 1;
    obj->field_0x5d = bVar2;
    if (bVar2 < 6) {
      return;
    }
    bVar2 = obj->sub2;
  }
  obj->sub2 = bVar2 + 1;
  return;
}


// ---- 801da260 FUN_801da260

undefined1 FUN_801da260(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  *(undefined **)(param_1 + 0x38) = &DAT_801e5738;
  FUN_80107bf4(param_1,&g_player,0);
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  if (DAT_8015e24c._2_2_ < DAT_8015e272) {
    DAT_801c3360 = 0;
  }
  if ((DAT_8015e26f & 0x80) != 0) {
    DAT_801c3360 = 0;
  }
  if (DAT_8015e230 == 0) {
    DAT_801c3360 = 0;
  }
  *(byte *)(param_1 + 0x53) = DAT_801c3360 & 0x80;
  return *(undefined1 *)(param_1 + 0x53);
}


// ---- 801da32c FUN_801da32c

undefined1 FUN_801da32c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  *(undefined **)(param_1 + 0x38) = &DAT_801e5738;
  FUN_80107bf4(param_1,&g_player,0);
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  if (DAT_8015e24c._2_2_ <= DAT_8015e272) {
    DAT_801c3360 = 0;
  }
  if ((DAT_8015e26f & 0x80) != 0) {
    DAT_801c3360 = 0;
  }
  if (DAT_8015e230 == 0) {
    DAT_801c3360 = 0;
  }
  *(byte *)(param_1 + 0x53) = DAT_801c3360 & 0x80;
  return *(undefined1 *)(param_1 + 0x53);
}


// ---- 801da3f8 FUN_801da3f8

int FUN_801da3f8(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (((*(char *)(param_1 + 0x50) != '\x04') && (*(char *)(param_1 + 0x51) != '\0')) &&
     (cVar1 = *(char *)(param_1 + 0x51) + -1, *(char *)(param_1 + 0x51) = cVar1, cVar1 == '\0')) {
    bVar2 = *(char *)(param_1 + 0x50) - 1;
    *(byte *)(param_1 + 0x50) = bVar2;
    if ((int)((uint)bVar2 << 0x18) < 0) {
      *(undefined1 *)(param_1 + 1) = 7;
      *(undefined1 *)(param_1 + 2) = 0;
    }
    else {
      uVar3 = 0x93;
      if (*(char *)(param_1 + 0x50) == '\0') {
        uVar3 = 0x94;
      }
      FUN_8010544c(param_1,uVar3);
                    /* Possible PsyQ macro: setPolyF3() */
      *(undefined1 *)(param_1 + 0x51) = 0x20;
    }
  }
  return (int)*(char *)(param_1 + 0x50);
}


// ---- 801da4b0 FUN_801da4b0

undefined4 FUN_801da4b0(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x50) == '\x04') {
    if (*(char *)(param_1 + 1) != '\x04') {
      FUN_8010544c(param_1,0x92);
    }
    uVar2 = 0x93;
    *(undefined1 *)(param_1 + 0x51) = 0x21;
    *(char *)(param_1 + 0x50) = *(char *)(param_1 + 0x50) + -1;
LAB_801da508:
    FUN_8010544c(param_1,uVar2);
LAB_801da510:
    uVar2 = 1;
  }
  else {
    if (-1 < *(char *)(param_1 + 0x50)) {
      bVar1 = *(byte *)(param_1 + 0x51);
      FUN_8010544c(param_1,0x92);
      if (bVar1 < 0x1b) {
        if (bVar1 < 5) {
          return 0;
        }
        bVar1 = *(char *)(param_1 + 0x50) - 1;
        *(byte *)(param_1 + 0x50) = bVar1;
        if (-1 < (int)((uint)bVar1 << 0x18)) {
          *(undefined1 *)(param_1 + 0x51) = 0x21;
          if (*(char *)(param_1 + 0x50) == '\0') {
            uVar2 = 0x94;
          }
          else {
            uVar2 = 0x93;
          }
          goto LAB_801da508;
        }
        *(undefined1 *)(param_1 + 0x51) = 1;
        goto LAB_801da510;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 801da5b8 FUN_801da5b8

void FUN_801da5b8(int param_1,char *param_2)

{
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    if (*(char *)(param_1 + 0x50) == '\x04') {
      Anim_Set(param_2,8);
    }
    else {
      Anim_SetAtStep(param_2,9,(&DAT_801e5755)[*(char *)(param_1 + 0x50)]);
      param_2[0x31] = *(char *)(*(int *)(param_2 + 0x28) + 2) + '\x01';
    }
  }
  return;
}


// ---- 801da648 FUN_801da648

void FUN_801da648(int param_1)

{
  if (*(int *)(param_1 + 0x18) < -0x5ffff) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


// ---- 801da668 FUN_801da668

void FUN_801da668(int param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 7) & 0x10) == 0) {
    uVar1 = 0xfffec000;
  }
  else {
    uVar1 = 0x14000;
  }
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ---- 801da6a0 FUN_801da6a0

undefined4 FUN_801da6a0(char *param_1)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  
  pcVar3 = &g_main_pool;
  iVar5 = 0;
  bVar1 = param_1[7];
  pbVar4 = (byte *)((int)&DAT_8015b178 + 3);
  while ((((iVar5 = iVar5 + 1, *pcVar3 == '\0' || (pbVar4[-1] != 0x1c)) || (pcVar3 == param_1)) ||
         (((*pbVar4 & 0xf) != (bVar1 & 0xf) ||
          (iVar2 = Obj_HitboxOverlap(param_1,pcVar3), iVar2 == 0))))) {
    pbVar4 = pbVar4 + 0x60;
    pcVar3 = pcVar3 + 0x60;
    if (0x3f < iVar5) {
      return 0;
    }
  }
  return 1;
}


