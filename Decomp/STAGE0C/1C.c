// ID 1C, STAGE0C.BIN, handler 0x801D9238. Ghidra output with the object struct applied; not matching C.
// ---- 801d9238 FUN_801d9238

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9238(MM8Obj *obj)

{
  int iVar1;
  
  obj->field_0x4 = 0;
  (*(code *)(&PTR_FUN_801ea9cc)[obj->state])();
                    /* Probable PsyQ macro: setLineF2() */
  if (obj->active != 0) {
    FUN_801d9f24(obj);
                    /* Possible PsyQ macro: setLineF2() */
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


// ---- 801d92d8 FUN_801d92d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d92d8(MM8Obj *obj)

{
  int iVar1;
  
                    /* Possible PsyQ macro: setLineF2() */
  Enemy_InitFromTable();
  obj->draw_list = 8;
  obj->hitbox = &DAT_801eaa04;
                    /* Possible PsyQ macro: setSprt16() + setShadeTex(sprt16, 1) */
  obj->box2 = &DAT_801ea9ec;
                    /* Possible PsyQ macro: setLineF2() */
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
  return;
}


// ---- 801d93c8 FUN_801d93c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d93c8(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_80107bf4(obj,&g_player,1);
  Enemy_CheckWeaponHits(obj);
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801d9d8c(obj);
  obj->field_0x53 = cVar2;
  if (cVar1 != cVar2) {
    if (obj->field_0x53 == '\0') {
      obj->sub2 = 0;
    }
    else {
      iVar3 = FUN_801d9fdc(obj);
      if (iVar3 != 0) {
        uVar4 = FUN_801093fc(&obj->field_0x54);
        switchD_801da0dc::caseD_0(obj,uVar4);
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


// ---- 801d94a4 FUN_801d94a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d94a4(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (obj->sub2 == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 3;
    if (obj->sub2 != 1) goto LAB_801d94ec;
  }
  Anim_Set(obj,uVar3);
  obj->sub2 = 2;
LAB_801d94ec:
  FUN_80107bf4(obj,&g_player,1);
  Enemy_CheckWeaponHits(obj);
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801d9d8c(obj);
                    /* Possible PsyQ macro: setLineF2() */
  obj->field_0x53 = cVar2;
                    /* Possible PsyQ macro: setPolyF4() */
  if ((cVar1 != cVar2) && (obj->field_0x53 != '\0')) {
    if (obj->field_0x50 == '\x04') {
      obj->field_0x51 = 0x21;
      obj->state = 3;
      obj->sub2 = 0;
    }
    FUN_8010544c(obj,0x92);
  }
                    /* Probable PsyQ macro: setTile16() */
  return;
}


// ---- 801d9578 FUN_801d9578

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9578(MM8Obj *obj)

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
                    /* Possible PsyQ macro: setPolyF4() */
    bVar2 = obj->sub2;
    obj->field_0x43 = 1;
  }
  else {
    if (bVar2 != 1) {
      if (bVar2 == 2) {
        Anim_Set(obj,4);
                    /* Probable PsyQ macro: setTile() */
        obj->gravity = 0x4000;
        obj->speed_y_up = 0;
        obj->sub2 = obj->sub2 + 1;
      }
      else {
        Anim_Step(obj);
      }
      goto LAB_801d9648;
    }
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->hitbox = &DAT_801eaa08;
      obj->box2 = &DAT_801ea9f4;
    }
    iVar4 = Anim_AtLoopMarker(obj);
    if (iVar4 == 0) goto LAB_801d9648;
    bVar2 = obj->sub2;
  }
  obj->sub2 = bVar2 + 1;
LAB_801d9648:
  FUN_80104ccc(obj);
  FUN_801da174(obj);
  FUN_80106214(obj);
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  cVar1 = obj->field_0x53;
  cVar3 = FUN_801d9d8c(obj);
  obj->field_0x53 = cVar3;
                    /* Possible PsyQ macro: setLineF2() */
  if (((cVar1 != cVar3) && (obj->field_0x53 != '\0')) && (iVar4 = FUN_801d9fdc(obj), iVar4 != 0)) {
    uVar5 = FUN_801093fc(&obj->field_0x54);
    switchD_801da0dc::caseD_0(obj,uVar5);
  }
  pbVar6 = obj->hitbox;
  obj->hitbox = &DAT_801eaa10;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar6;
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x43 = 0;
    obj->state = 4;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801d9720 FUN_801d9720

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9720(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
                    /* Possible PsyQ macro: setSprt16() + setShadeTex(sprt16, 1) */
  if (obj->sub2 == 0) {
                    /* Possible PsyQ macro: setLineF2() */
    if ((obj->field_0x50 == '\x04') && (iVar3 = FUN_801d9fdc(), iVar3 != 0)) {
      uVar4 = FUN_801093fc(&obj->field_0x54);
      switchD_801da0dc::caseD_0(obj,uVar4);
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
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801d9e58(obj);
  obj->field_0x53 = cVar2;
                    /* Probable PsyQ macro: setTile() */
  if (((cVar1 != cVar2) && (obj->field_0x53 != '\0')) && (iVar3 = FUN_801d9fdc(obj), iVar3 != 0)) {
    uVar4 = FUN_801093fc(&obj->field_0x54);
    switchD_801da0dc::caseD_0(obj,uVar4);
  }
                    /* Probable PsyQ macro: setTile16() */
  obj->y = *(short *)&obj->field_0x5b;
                    /* Possible PsyQ macro: setTile8() */
  obj->y = *(short *)&obj->field_0x5b + ((obj->frame & 0x7fff) - (ushort)(byte)obj->field_0x58);
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  pbVar5 = obj->hitbox;
  obj->hitbox = &DAT_801eaa10;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar5;
  return;
}


// ---- 801d98d4 FUN_801d98d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d98d4(MM8Obj *obj)

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
  cVar2 = FUN_801d9e58(obj);
  obj->field_0x53 = cVar2;
  if (((cVar1 != cVar2) && (obj->field_0x53 != '\0')) && (iVar3 = FUN_801d9fdc(obj), iVar3 != 0)) {
    uVar4 = FUN_801093fc(&obj->field_0x54);
    switchD_801da0dc::caseD_0(obj,uVar4);
    obj->state = 4;
    obj->sub2 = 0;
  }
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  pbVar5 = obj->hitbox;
  obj->hitbox = &DAT_801eaa10;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar5;
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801d9a10 FUN_801d9a10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9a10(MM8Obj *obj)

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
                    /* Possible PsyQ macro: setPolyGT4() */
    switchD_801da0dc::caseD_4(obj);
    obj->field_0x5d = 0x1e;
    obj->field_0x58 = 0;
    obj->field_0x5b = (char)obj->y;
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
                    /* Possible PsyQ macro: setTile8() */
  cVar4 = FUN_801d9e58(obj);
  obj->field_0x53 = cVar4;
  if ((cVar1 != cVar4) && (obj->field_0x53 != '\0')) {
    iVar5 = FUN_801d9fdc(obj);
    if (iVar5 != 0) {
      uVar6 = FUN_801093fc(&obj->field_0x54);
      switchD_801da0dc::caseD_0(obj,uVar6);
    }
    obj->state = 4;
    obj->sub2 = 0;
  }
  obj->prev_y = sVar2;
  obj->y = sVar3;
  obj->y = (char)(&DAT_801eaa20)[(byte)obj->field_0x58 / 3] + sVar3;
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  pbVar7 = obj->hitbox;
  obj->hitbox = &DAT_801eaa10;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar7;
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->speed_x = -obj->speed_x;
  }
  iVar5 = FUN_801da1cc(obj);
  if (iVar5 != 0) {
    obj->speed_x = -obj->speed_x;
  }
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->state = 3;
    obj->sub2 = 2;
  }
  if (obj->state == 4) {
                    /* Possible PsyQ macro: setPolyF4() */
    obj->y = (ushort)(byte)obj->field_0x5b;
    obj->y = *(short *)&obj->field_0x5b;
  }
  return;
}


// ---- 801d9c58 FUN_801d9c58

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9c58(MM8Obj *obj)

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
    FUN_8012a5fc(obj,3);
    obj->field_0x52 = 2;
                    /* Possible PsyQ macro: setLineF2() */
    bVar2 = obj->sub2;
                    /* Probable PsyQ macro: setTile16() */
    obj->field_0x5d = 0;
    obj->field_0x4 = 1;
  }
  else if (bVar2 == 1) {
    obj->field_0x4 = 1;
                    /* Possible PsyQ macro: setLineF2() */
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
    obj->hitbox = &DAT_801eaa14;
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


// ---- 801d9d8c FUN_801d9d8c

undefined1 FUN_801d9d8c(int param_1)

{
  undefined4 uVar1;
  
                    /* Possible PsyQ macro: setLineF2() */
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  *(undefined **)(param_1 + 0x38) = &DAT_801ea9fc;
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


// ---- 801d9e58 FUN_801d9e58

undefined1 FUN_801d9e58(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  *(undefined **)(param_1 + 0x38) = &DAT_801ea9fc;
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


// ---- 801d9f24 FUN_801d9f24

int FUN_801d9f24(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
                    /* Possible PsyQ macro: setPolyF4() */
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


// ---- 801d9fdc FUN_801d9fdc

undefined4 FUN_801d9fdc(int param_1)

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
LAB_801da034:
    FUN_8010544c(param_1,uVar2);
LAB_801da03c:
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
          goto LAB_801da034;
        }
        *(undefined1 *)(param_1 + 0x51) = 1;
        goto LAB_801da03c;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 801da0e4 caseD_0

void switchD_801da0dc::caseD_0(int param_1,char *param_2)

{
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    if (*(char *)(param_1 + 0x50) == '\x04') {
      Anim_Set(param_2,8);
    }
    else {
      Anim_SetAtStep(param_2,9,(&DAT_801eaa19)[*(char *)(param_1 + 0x50)]);
      param_2[0x31] = *(char *)(*(int *)(param_2 + 0x28) + 2) + '\x01';
    }
  }
  return;
}


// ---- 801da174 FUN_801da174

void FUN_801da174(int param_1)

{
                    /* Possible PsyQ macro: setPolyGT3() */
  if (*(int *)(param_1 + 0x18) < -0x5ffff) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


// ---- 801da194 caseD_4

void switchD_801da0dc::caseD_4(int param_1)

{
  undefined4 uVar1;
  
                    /* Probable PsyQ macro: setLineF2() */
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


// ---- 801da1cc FUN_801da1cc

undefined4 FUN_801da1cc(char *param_1)

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
                    /* Possible PsyQ macro: setPolyGT4() */
    pcVar3 = pcVar3 + 0x60;
    if (0x3f < iVar5) {
      return 0;
    }
  }
  return 1;
}


