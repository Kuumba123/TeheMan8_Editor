// ID 16, STAGE04.BIN, handler 0x801DB460. Ghidra output with the object struct applied; not matching C.
// ---- 801db460 FUN_801db460

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db460(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6dd0)[obj->state])();
  FUN_80107bf4(obj,&g_player,5);
  FUN_80106214(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801db4cc FUN_801db4cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db4cc(MM8Obj *obj)

{
  byte bVar1;
  
  obj->state = 1;
                    /* Possible PsyQ macro: setPolyG3() + setSemiTrans(polyG3, 1) */
  obj->bank = 0x32;
  obj->vram_base = DAT_801703ac;
  bVar1 = DAT_80159f96;
  obj->draw_list = 6;
  obj->hitbox = &DAT_801e6dcc;
  obj->box2 = &DAT_801e6dc4;
  obj->field_0x43 = 1;
  obj->flip = 0;
  obj->dmg_table = 1;
  obj->hp = 1;
  obj->field_0x50 = 0x27;
  obj->clut = bVar1;
  Anim_Set(obj,0);
  if (obj->var == 0) {
    obj->speed_x = 0xd100;
    obj->sub2 = 0;
    obj->accel_x = -0x400;
    obj->speed_y_up = 0;
    obj->gravity = 0;
  }
  else {
    obj->sub2 = 2;
    obj->speed_y_up = 0xd100;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->gravity = 0x400;
  }
  return;
}


// ---- 801db5a8 FUN_801db5a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db5a8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6ddc)[obj->sub2])();
  Anim_Step(obj);
  Enemy_CheckWeaponHits(obj);
  return;
}


// ---- 801db600 FUN_801db600

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db600(MM8Obj *obj)

{
  char cVar1;
  
  FUN_80104c34();
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 1;
    obj->sub3 = 0;
    obj->field_0x50 = 0;
  }
  return;
}


// ---- 801db650 FUN_801db650

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db650(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (obj->field_0x50 == '\0') {
    Obj_ApplySpeed(obj);
    if (obj->sub3 == 0) {
      if ((obj->speed_x == 0) || ((obj->speed_x & 0x80000000U) == (obj->accel_x & 0x80000000U))) {
        obj->field_0x50 = 0x1e;
      }
    }
    else {
      iVar3 = obj->speed_x;
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = -iVar3;
      }
      if (0xd0ff < iVar2) {
        iVar2 = -0xd100;
        if (0 < iVar3) {
          iVar2 = 0xd100;
        }
        obj->speed_x = iVar2;
        obj->field_0x50 = 0x4e;
        obj->sub2 = 0;
        obj->accel_x = -obj->accel_x;
      }
    }
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->sub3 = 1;
    }
  }
  return;
}


// ---- 801db738 FUN_801db738

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db738(MM8Obj *obj)

{
  char cVar1;
  
  FUN_80104c34();
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->field_0x50 = 0;
  }
  return;
}


// ---- 801db788 FUN_801db788

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db788(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (obj->field_0x50 == '\0') {
    Obj_ApplySpeed(obj);
    if (obj->sub3 == 0) {
      if ((obj->speed_y_up == 0) ||
         ((obj->speed_y_up & 0x80000000U) != (obj->gravity & 0x80000000U))) {
        obj->field_0x50 = 0x1e;
      }
    }
    else {
      iVar3 = obj->speed_y_up;
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = -iVar3;
      }
      if (0xd0ff < iVar2) {
        iVar2 = -0xd100;
        if (0 < iVar3) {
          iVar2 = 0xd100;
        }
        obj->speed_y_up = iVar2;
        obj->field_0x50 = 0x4e;
        obj->sub2 = 2;
        obj->gravity = -obj->gravity;
      }
    }
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->sub3 = 1;
    }
  }
  return;
}


// ---- 801db8d8 FUN_801db8d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db8d8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  
  Enemy_InitFromTable();
  obj->hitbox = &DAT_801e6dfc;
  obj->flip = 0;
  obj->box2 = (byte *)0x0;
  obj->field_0x50 = 0;
  obj->field_0x51 = (char)obj->y;
  obj->field_0x52 = (char)((ushort)obj->y >> 8);
  *(short *)&obj->field_0x4a = obj->y;
  if (obj->var == 0) {
    sVar3 = FUN_80107204((int)obj->x,obj->y + 0x20);
    bVar1 = 1;
    if (sVar3 == 0x3a) {
      iVar4 = FUN_8012c108(obj,&obj->field_0x53,0,0x10,0,2);
      if (iVar4 != 0) {
        *(undefined1 *)(iVar4 + 0x26) = 10;
                    /* Probable PsyQ macro: setTile16() */
        *(undefined1 *)(iVar4 + 7) = 0x70;
        cVar2 = DAT_80159fa3 + '\x01';
        *(char *)(iVar4 + 0x24) = cVar2;
        *(char *)(iVar4 + 0x33) = cVar2;
        *(char *)(iVar4 + 0x31) = *(char *)(iVar4 + 0x31) + '\x01';
                    /* Possible PsyQ macro: setTile8() */
        obj->field_0x53 = 4;
      }
      bVar1 = 1;
    }
  }
  else if (obj->var == 1) {
                    /* Possible PsyQ macro: setTile8() */
    obj->box2 = &DAT_801e6e00;
    obj->draw_list = 0xb;
    bVar1 = 2;
    obj->dmg_table = 0;
  }
  else {
    uVar5 = FUN_8010724c((int)obj->x,(int)obj->y);
    if ((uVar5 & 0x1000) != 0) {
      iVar4 = FUN_8012c108(obj,&obj->field_0x53,0,0xfffffff8,0,1);
      if (iVar4 != 0) {
        *(undefined1 *)(iVar4 + 0x26) = 10;
                    /* Probable PsyQ macro: setTile16() */
        *(undefined1 *)(iVar4 + 7) = 0x70;
        *(char *)(iVar4 + 0x31) = *(char *)(iVar4 + 0x31) + '\x01';
        obj->field_0x53 = 4;
      }
    }
    bVar1 = 3;
  }
  obj->state = bVar1;
  obj->sub2 = 0;
  return;
}


// ---- 801dba64 FUN_801dba64

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba64(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    iVar3 = Obj_InActiveArea();
    if (iVar3 != 0) {
      bVar1 = obj->hp;
      cVar2 = Enemy_CheckWeaponHits(obj);
      if ((((cVar2 != '\0') && (DAT_80158f5c != 0x11)) && (1 < DAT_80158f5c)) &&
         (DAT_80158f5c != 0xf)) {
        cVar2 = '\x03';
        obj->hp = bVar1;
      }
      if (cVar2 == '\x04') {
        iVar3 = FUN_8012c108(obj,0,0xfffffff0,0xffffffe0,0,0);
        if (iVar3 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
          *(undefined1 *)(iVar3 + 0x27) = 0x34;
                    /* Possible PsyQ macro: setPolyGT4() */
          *(undefined1 *)(iVar3 + 0x26) = 6;
          *(undefined1 *)(iVar3 + 7) = 0x10;
        }
        iVar3 = FUN_8012c108(obj,0,0xfffffff0,0x10,0,0);
        if (iVar3 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
          *(undefined1 *)(iVar3 + 0x27) = 0x34;
          *(undefined1 *)(iVar3 + 0x26) = 6;
          *(undefined1 *)(iVar3 + 7) = 0x10;
        }
        iVar3 = FUN_8012c108(obj,0,0x10,0xffffffe0,0,0);
        if (iVar3 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
          *(undefined1 *)(iVar3 + 0x27) = 0x34;
          *(undefined1 *)(iVar3 + 0x26) = 6;
          *(undefined1 *)(iVar3 + 7) = 0x10;
        }
        iVar3 = FUN_8012c108(obj,0,0x10,0x10,0,0);
        if (iVar3 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
          *(undefined1 *)(iVar3 + 0x27) = 0x34;
          *(undefined1 *)(iVar3 + 0x26) = 6;
          *(undefined1 *)(iVar3 + 7) = 0x10;
        }
        FUN_8012ae08(obj,8);
        FUN_8010544c(obj,10);
        obj->field_0x50 = 6;
        obj->sub2 = obj->sub2 + 1;
      }
    }
  }
  else {
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 == '\0') {
      FUN_801dbed8(obj);
      obj->field_0x53 = 2;
      Obj_Free(obj);
    }
  }
  obj->on_screen = 1;
  return;
}


// ---- 801dbc64 FUN_801dbc64

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbc64(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  
  sVar1 = obj->x;
  obj->y = *(short *)&obj->field_0x51;
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->draw_list = 0xb;
    obj->sub2 = obj->sub2 + 1;
  }
  FUN_80104ccc(obj);
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  if (obj->field_0x50 == '\0') {
    sVar2 = obj->y;
    obj->field_0x51 = (char)sVar2;
    obj->field_0x52 = (char)((ushort)sVar2 >> 8);
  }
  else {
    sVar2 = *(short *)&obj->field_0x51;
    obj->field_0x50 = obj->field_0x50 + -1;
    obj->y = sVar2;
  }
  FUN_80106214(obj);
  iVar3 = Obj_InActiveArea(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    if (obj->speed_y_up == 0) {
      iVar3 = FUN_80107204((int)sVar1,sVar2 + -0x20);
      uVar4 = 6;
      if (iVar3 == 0x3a) {
        uVar4 = 10;
      }
      FUN_80102ef4(uVar4,(int)sVar1,(int)sVar2);
      obj->field_0x43 = 1;
      obj->field_0x50 = 0;
      obj->speed_y_up = 0;
      obj->gravity = 0x4000;
      FUN_801dbe40();
      return;
    }
    if (iVar3 == 0) {
      return;
    }
  }
  else if (obj->speed_y_up != 0) {
    FUN_8010544c(obj,0x16a);
    obj->field_0x50 = 6;
    FUN_80102ef4(5,(int)sVar1,(int)sVar2);
    obj->field_0x43 = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
  }
  obj->box2 = &DAT_801e6e00;
  FUN_80109490(obj);
  obj->box2 = &DAT_801e6e08;
  FUN_80107bf4(obj,&g_player,6);
  obj->box2 = &DAT_801e6e00;
  if (iVar3 != 0) {
    FUN_80109804(obj);
    if ((obj->field_0x50 & 1) != 0) {
      obj->y = obj->y + 2;
    }
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801dbe40 FUN_801dbe40

void FUN_801dbe40(void)

{
  int unaff_s1;
  int unaff_s3;
  
  if (unaff_s3 != 0) {
    FUN_80109804();
    if ((*(byte *)(unaff_s1 + 0x50) & 1) != 0) {
      *(short *)(unaff_s1 + 0x12) = *(short *)(unaff_s1 + 0x12) + 2;
    }
    Obj_CullAndQueueDraw();
  }
  return;
}


// ---- 801dbe9c FUN_801dbe9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbe9c(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = Obj_InActiveArea();
  if (iVar1 == 0) {
    obj->field_0x53 = 2;
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801dbed8 FUN_801dbed8

void FUN_801dbed8(int param_1)

{
  short sVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  sVar1 = *(short *)(param_1 + 0xe);
  iVar7 = (int)sVar1;
  iVar6 = (int)*(short *)(param_1 + 0x12);
  cVar2 = FUN_80107204(iVar7,iVar6 + -0x20);
  cVar3 = FUN_80107204(iVar7,iVar6 + 0x20);
  if (cVar2 == '9') {
    uVar5 = 2;
  }
  else {
    if (cVar2 != ':') {
      iVar4 = FUN_80107204(iVar7,iVar6 + -0x30);
      if (iVar4 != 0) {
        iVar7 = FUN_8010724c(iVar7,iVar6 + -0x30);
        uVar5 = 7;
        if (iVar7 != 1) goto LAB_801dbf74;
      }
    }
    uVar5 = 1;
  }
LAB_801dbf74:
  FUN_80102ef4(uVar5,(int)sVar1,iVar6);
  if (cVar3 == '9') {
    uVar5 = 4;
  }
  else if (cVar3 == ':') {
    uVar5 = 9;
  }
  else {
    if (cVar3 == '=') {
      iVar7 = FUN_80107204((int)sVar1,iVar6 + 0x30);
      uVar5 = 8;
      if (iVar7 != 0) goto LAB_801dbfd0;
    }
    uVar5 = 3;
  }
LAB_801dbfd0:
  FUN_80102ef4(uVar5,(int)sVar1,iVar6);
  return;
}


