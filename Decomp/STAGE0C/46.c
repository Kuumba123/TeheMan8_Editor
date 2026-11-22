// ID 46, STAGE0C.BIN, handler 0x801DD4B8. Ghidra output with the object struct applied; not matching C.
// ---- 801dd4b8 FUN_801dd4b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd4b8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  
  bVar1 = DAT_80159fe3;
  bVar3 = obj->var;
  obj->clut = DAT_80159fe3;
  if (obj->var == 1) {
    bVar1 = bVar1 + 2;
LAB_801dd4fc:
    obj->clut = bVar1;
  }
  else {
    bVar1 = bVar1 + 3;
    if (obj->var == 2) goto LAB_801dd4fc;
  }
  (*(code *)(&PTR_FUN_801eab48)[obj->state])(obj);
  if (obj->active == 0) {
    return;
  }
                    /* Possible PsyQ macro: setPolyF3() */
  if ((obj->var < 3) && ((obj->anim_extra & 0x40) != 0)) {
    obj->clut = DAT_80159fe3;
  }
  obj->invuln = 7 < obj->state;
  cVar2 = FUN_801ddfdc(obj);
  if (cVar2 == '\0') {
    if (bVar3 < 3) {
      cVar2 = switchD_801de6c0::caseD_1(obj,0x80,0x38);
      if (cVar2 != '\0') goto LAB_801dd648;
    }
    else {
      bVar3 = switchD_801de6c0::caseD_1(obj,0x38,0x38);
      if ((bVar3 != 0) &&
         (((bVar3 & 0x40) == 0 || (iVar4 = FUN_80104820(obj,0x38,0x100), iVar4 == 0))))
      goto LAB_801dd620;
    }
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  else {
    if (bVar3 != 5) {
      FUN_80108e84(obj);
    }
    if (2 < bVar3) {
      FUN_801de68c(obj);
LAB_801dd620:
                    /* Possible PsyQ macro: setLineF2() */
      Obj_Free(obj);
      return;
    }
    FUN_8012a5fc(obj,8);
    FUN_80108fd8(obj,0);
LAB_801dd648:
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801dd67c FUN_801dd67c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd67c(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->box2 = &DAT_801eabcc;
  obj->draw_list = 8;
  FUN_8010910c(obj);
  obj->field_0x50 = 0;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  *(undefined2 *)&obj->field_0x54 = 0;
  *(undefined2 *)&obj->field_0x4a = 0;
  obj->field_0x56 = obj->var & 0xf0;
  obj->var = obj->var & 0xf;
  if ((obj->field_0x56 & 0x40) == 0) {
    obj->state = 1;
  }
  else {
    obj->state = 8;
  }
  obj->sub2 = 0;
  Anim_Set(obj,0x10);
  return;
}


// ---- 801dd724 FUN_801dd724

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd724(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0x10);
    obj->field_0x50 = 0x3c;
    obj->sub2 = obj->sub2 + 1;
  }
  else if (((obj->field_0x50 == '\0') ||
           (cVar1 = obj->field_0x50 + -1, obj->field_0x50 = cVar1, cVar1 == '\0')) &&
          ((ushort)((obj->x - DAT_8015e248._2_2_) + 0xb0U) < 0x161)) {
    obj->state = 2;
    obj->sub2 = 0;
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->state = 5;
    obj->sub2 = 0;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801dd7f8 FUN_801dd7f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd7f8(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  
  sVar2 = DAT_8015e248._2_2_;
  bVar3 = obj->sub2;
  sVar1 = obj->x;
  if (bVar3 == 0) {
    Anim_Set(obj,0x10);
    bVar3 = obj->sub2;
    obj->field_0x50 = 0;
  }
  else {
    if (bVar3 != 1) {
      if (bVar3 != 2) {
        return;
      }
      cVar4 = obj->field_0x50 + -1;
      obj->field_0x50 = cVar4;
      if (cVar4 != '\0') {
        return;
      }
      FUN_8010910c(obj);
      FUN_8010544c(obj,0x124);
      FUN_801de5dc(obj,6);
      obj->state = 5;
      obj->sub2 = 0;
      return;
    }
                    /* Possible PsyQ macro: setTile8() */
    if ((int)DAT_8015e248._2_2_ - (int)sVar1 < 0x10) {
                    /* Possible PsyQ macro: setPolyF3() */
      cVar4 = obj->field_0x50 + -1;
      obj->field_0x50 = cVar4;
      if (cVar4 != '\0') {
        return;
      }
      uVar5 = Rand(obj);
      if ((uVar5 & 3) != 0) {
        return;
      }
      if ((ushort)((sVar2 - sVar1) + 0x60U) < 0xc0) {
        return;
      }
      FUN_801de5dc(obj,3);
      return;
    }
    FUN_801de5dc(obj,4);
    bVar3 = obj->sub2;
    obj->field_0x50 = 0xf;
  }
  obj->sub2 = bVar3 + 1;
  return;
}


// ---- 801dd944 FUN_801dd944

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd944(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  
  bVar1 = obj->sub2;
  if (bVar1 == 0) {
    Anim_Set(obj,2);
    FUN_8010544c(obj,0x122);
    bVar1 = obj->sub2;
  }
  else {
    if (bVar1 != 1) {
      if (bVar1 == 2) {
        if (obj->field_0x50 == '\0') {
          Anim_Step(obj);
        }
        else {
          obj->field_0x50 = obj->field_0x50 + -1;
        }
        iVar2 = Anim_AtLoopMarker(obj);
        if (iVar2 != 0) {
          obj->state = 3;
          obj->sub2 = 0;
        }
      }
      goto LAB_801dda4c;
    }
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 == 0) goto LAB_801dda4c;
    if (obj->var == 2) {
      iVar2 = FUN_801de534(obj);
                    /* Possible PsyQ macro: setLineF2() */
      cVar3 = '\x03';
      if (iVar2 == 0) goto LAB_801dd9c4;
      obj->field_0x52 = 1;
    }
    else {
LAB_801dd9c4:
      obj->field_0x52 = 0;
      cVar3 = obj->var + 3;
    }
    obj->field_0x53 = cVar3;
    FUN_801ddeb8(obj);
    bVar1 = obj->sub2;
    obj->field_0x50 = 0x20;
  }
  obj->sub2 = bVar1 + 1;
LAB_801dda4c:
  if ((obj->anim_extra & 0x80) != 0) {
    FUN_8010544c(obj,0x123);
    iVar2 = ((byte)obj->field_0x53 - 3) * 4;
    FUN_801de0f8(obj,(uint)(byte)obj->field_0x53,(int)*(short *)(&DAT_801eabf4 + iVar2),
                 (int)*(short *)(&DAT_801eabf6 + iVar2));
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->state = 5;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801ddad0 FUN_801ddad0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddad0(MM8Obj *obj)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0x10);
    uVar1 = switchD_801ddf1c::switchD(obj);
    obj->field_0x50 = uVar1;
    obj->field_0x51 = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 == '\0') {
      iVar4 = FUN_801ddf8c(obj);
      bVar3 = 4;
      if ((iVar4 == 0) && (bVar3 = 2, 0x160 < (ushort)((obj->x - DAT_8015e248._2_2_) + 0xb0U))) {
                    /* Possible PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
        obj->field_0x50 = 1;
      }
      else {
        obj->state = bVar3;
        obj->sub2 = 0;
      }
    }
  }
  if (obj->field_0x51 == '\0') {
    iVar4 = FUN_801ddf8c(obj);
    if (iVar4 != 0) {
      obj->field_0x51 = 0x1e;
    }
  }
  else {
    cVar2 = obj->field_0x51 + -1;
    obj->field_0x51 = cVar2;
    if (cVar2 == '\0') {
      obj->state = 4;
                    /* Possible PsyQ macro: setPolyGT4() */
      obj->sub2 = 0;
    }
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->state = 5;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801ddc04 FUN_801ddc04

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddc04(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar1 = obj->sub2;
  if (bVar1 == 0) {
    Anim_Set(obj,0x11);
    FUN_8010544c(obj,0x126);
    bVar2 = obj->sub2;
    obj->speed_y_up = 0;
    obj->gravity = 0;
  }
  else {
    if (bVar1 != 1) {
      if (bVar1 == 2) {
        if ((obj->y == obj->prev_y) && (obj->speed_y_up == 0)) {
          obj->flip = obj->flip ^ 0x40;
                    /* Possible PsyQ macro: setLineF2() */
          obj->sub2 = obj->sub2 + 1;
        }
      }
      else if (bVar1 == 4) {
        Anim_Step(obj);
        iVar3 = Anim_AtLoopMarker(obj);
        if (iVar3 != 0) {
          obj->state = 2;
          obj->sub2 = 0;
        }
      }
      goto LAB_801ddcfc;
    }
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    if (iVar3 == 0) goto LAB_801ddcfc;
    obj->speed_y_up = 0x40000;
    bVar2 = obj->sub2;
    obj->gravity = 0x4000;
  }
  obj->sub2 = bVar2 + 1;
LAB_801ddcfc:
  FUN_80104ccc(obj);
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  if ((bVar1 == 3) && ((obj->field_0x33 & 0x80) != 0)) {
    Anim_Set(obj,1);
                    /* Possible PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
    FUN_8010544c(obj,0x125);
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  return;
}


// ---- 801ddd8c FUN_801ddd8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddd8c(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->field_0x43 = 1;
    obj->speed_y_up = 0;
    obj->gravity = 0x4000;
    obj->sub2 = obj->sub2 + 1;
  }
  FUN_80104ccc(obj);
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x43 = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->state = 6;
    obj->sub2 = 0;
  }
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  return;
}


// ---- 801dde3c FUN_801dde3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dde3c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,1);
    FUN_8010544c(obj,0x125);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      obj->state = 3;
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801ddeb8 FUN_801ddeb8

void FUN_801ddeb8(int param_1,undefined1 param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 7);
  if (cVar1 == '\0') {
    param_2 = 4;
  }
  else if (cVar1 == '\x01') {
    param_2 = 3;
  }
  else if ((cVar1 == '\x02') && (param_2 = 5, *(char *)(param_1 + 0x52) != '\0')) {
    param_2 = 0x1a;
  }
  Anim_Set(param_1,param_2);
  return;
}


// ---- 801ddf1c switchD

undefined1 switchD_801ddf1c::switchD(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Rand();
  uVar1 = uVar1 & 0xf;
  iVar2 = 0;
  do {
    uVar1 = uVar1 - (byte)(&DAT_801eab6c)[iVar2];
    if ((int)(uVar1 * 0x10000) < 0) {
      return (&DAT_801eab70)[iVar2];
                    /* Possible PsyQ macro: setPolyGT4() */
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0;
}


// ---- 801ddf8c FUN_801ddf8c

bool FUN_801ddf8c(int param_1)

{
  short sVar1;
  short sVar2;
  
  sVar2 = *(short *)(param_1 + 0xe);
  sVar1 = DAT_8015e248._2_2_;
  if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
    sVar2 = DAT_8015e248._2_2_;
    sVar1 = *(short *)(param_1 + 0xe);
  }
  return sVar2 < sVar1;
}


// ---- 801ddfdc FUN_801ddfdc

char FUN_801ddfdc(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  cVar2 = '\0';
  uVar5 = (*(byte *)(param_1 + 0x32) & 0x30) >> 4;
  iVar4 = 0;
  if (uVar5 != 0) {
    do {
      *(undefined **)(param_1 + 0x3c) =
           (&PTR_DAT_801eab9c)[(*(byte *)(param_1 + 0x32) & 0xf) + iVar4];
      cVar1 = Enemy_CheckWeaponHits(param_1);
      if (*(char *)(param_1 + 7) == '\x05') {
        cVar2 = FUN_80109490(param_1);
        if ((*(char *)(param_1 + 0x43) != '\0') &&
           (iVar3 = Enemy_ContactDamage(param_1), iVar3 != 0)) {
          cVar2 = -1;
        }
      }
      else {
        Enemy_ContactDamage(param_1);
      }
      if (cVar1 != '\0') {
        if (cVar1 == '\x04') {
          return '\x01';
        }
        *(undefined1 *)(param_1 + 0x24) = 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar5);
  }
  return -(cVar2 != '\0');
}


// ---- 801de0f8 FUN_801de0f8

void FUN_801de0f8(int param_1,byte param_2,short param_3,short param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)FUN_801055e4();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x46;
    puVar2[7] = param_2;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
                    /* Possible PsyQ macro: setLineF2() */
      param_3 = param_3 + *(short *)(param_1 + 0xe);
    }
    else {
      param_3 = *(short *)(param_1 + 0xe) - param_3;
    }
    *(short *)(puVar2 + 0xe) = param_3;
    *(short *)(puVar2 + 0x12) = param_4 + *(short *)(param_1 + 0x12);
    Enemy_InitFromTable(puVar2);
    puVar2[0x25] = *(undefined1 *)(param_1 + 0x25);
    puVar2[0x26] = *(char *)(param_1 + 0x26) + -1;
    iVar3 = (param_2 - 3) * 2;
    puVar2[0x47] = (&DAT_801eabec)[iVar3];
    uVar1 = (&DAT_801eabed)[iVar3];
    puVar2[0x44] = 2;
    puVar2[1] = 7;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[0x45] = uVar1;
  }
  return;
}


// ---- 801de218 FUN_801de218

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de218(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined1 in_a1;
  undefined4 uVar4;
  undefined1 *puVar5;
  
  puVar5 = &obj->field_0x4a;
  if (obj->sub2 == 0) {
    bVar1 = obj->var;
    if (bVar1 == 3) {
      uVar4 = 0x50000;
      if (0xa0 < (ushort)((*(short *)&obj->field_0x54 - DAT_8015e248._2_2_) + 0x50U)) {
        uVar4 = 0x60000;
      }
      FUN_801051d8(obj,&g_player,uVar4,0x4000);
      if ((obj->flip & 0x40) == 0) {
        if (-0x8000 < obj->speed_x) {
          obj->speed_x = -0x8000;
        }
      }
      else if (obj->speed_x < 0x8000) {
        obj->speed_x = 0x8000;
      }
      obj->box2 = &DAT_801eabd4;
      in_a1 = 8;
    }
    else {
      if (bVar1 == 4) {
        iVar2 = 0x40000;
        if ((obj->flip & 0x40) == 0) {
          iVar2 = -0x40000;
        }
        obj->speed_x = iVar2;
        in_a1 = 10;
        pbVar3 = &DAT_801eabdc;
        obj->accel_x = 0;
        obj->speed_y_up = 0;
        obj->gravity = 0;
      }
      else {
        if (bVar1 != 5) goto LAB_801de378;
        iVar2 = 0x30000;
        if ((obj->flip & 0x40) == 0) {
          iVar2 = -0x30000;
        }
        obj->speed_x = iVar2;
        in_a1 = 6;
        obj->gravity = 0x4000;
        pbVar3 = &DAT_801eabe4;
      }
                    /* Possible PsyQ macro: setLineF2() */
      obj->box2 = pbVar3;
    }
LAB_801de378:
    Anim_Set(obj,in_a1);
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
    *(short *)&obj->field_0x54 = obj->x;
    *(short *)puVar5 = obj->y;
    bVar1 = obj->sub2;
  }
  else {
                    /* Possible PsyQ macro: setPolyF4() */
    if ((obj->sub2 != 1) || (obj->var != 4)) goto LAB_801de410;
    if ((obj->flip & 0x40) == 0) {
      iVar2 = (int)*(short *)&obj->field_0x54 - (int)obj->x;
    }
    else {
      iVar2 = (int)obj->x - (int)*(short *)&obj->field_0x54;
    }
    if (iVar2 < 0x10) goto LAB_801de410;
    bVar1 = obj->sub2;
    obj->gravity = 0x1000;
  }
  obj->sub2 = bVar1 + 1;
LAB_801de410:
  Obj_ApplySpeed(obj);
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
  if (obj->field_0x33 == '\0') {
    obj->field_0x43 = 1;
  }
  else {
                    /* Possible PsyQ macro: setTile1() + setSemiTrans(tile1, 1) */
    if ((obj->field_0x33 & 0x80) != 0) {
      if (obj->var == 5) {
        if (obj->field_0x43 != '\0') {
          FUN_8010544c(obj,0x127);
                    /* Possible PsyQ macro: setPolyGT4() */
          obj->field_0x50 = 8;
                    /* Possible PsyQ macro: setLineF2() */
          *(short *)puVar5 = obj->y;
        }
        obj->y = *(short *)puVar5;
        if ((obj->field_0x50 != '\0') &&
           (bVar1 = obj->field_0x50 - 1, obj->field_0x50 = bVar1, (bVar1 & 2) != 0)) {
          obj->y = obj->y + 2;
        }
      }
      obj->field_0x43 = 0;
      obj->speed_x = 0;
      obj->gravity = 0;
    }
    if (obj->var != 5) {
      FUN_801de68c(obj);
      FUN_80108e84(obj);
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801de534 FUN_801de534

undefined4 FUN_801de534(int param_1)

{
  ushort uVar1;
  short *psVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar3 = &g_main_pool;
  iVar4 = 0;
  psVar2 = &DAT_8015b182;
  do {
    if (((*pcVar3 != '\0') && ((char)psVar2[-4] == 'F')) && (*(char *)((int)psVar2 + -7) == '\x05'))
    {
      if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
        uVar1 = *(short *)(param_1 + 0xe) - *psVar2;
      }
      else {
        uVar1 = *psVar2 - *(short *)(param_1 + 0xe);
      }
      if (uVar1 < 0xc1) {
        return 1;
      }
    }
    psVar2 = psVar2 + 0x30;
    iVar4 = iVar4 + 1;
    pcVar3 = pcVar3 + 0x60;
    if (0x3f < iVar4) {
      return 0;
    }
  } while( true );
}


// ---- 801de5dc FUN_801de5dc

void FUN_801de5dc(int param_1,uint param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((param_2 & 0xff) != 0) {
    do {
      puVar2 = (undefined1 *)Obj_AllocType3();
      iVar3 = iVar3 + 1;
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x37;
        bVar1 = Rand();
        puVar2[7] = bVar1 & 0x40;
        *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
        *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      }
    } while (iVar3 < (int)(param_2 & 0xff));
  }
  return;
}


// ---- 801de68c FUN_801de68c

void FUN_801de68c(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(param_1 + 7);
  if (cVar1 == '\x03') {
    uVar2 = 0x29;
  }
  else if (cVar1 == '\x05') {
    uVar2 = 0x28;
  }
  else {
    if (cVar1 != '\x04') {
      return;
    }
    uVar2 = 0x2b;
    if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
      uVar2 = 0x2a;
    }
  }
  FUN_8012ae08(param_1,uVar2);
  return;
}


// ---- 801de6f4 caseD_1

uint switchD_801de6c0::caseD_1(int param_1,short param_2,short param_3)

{
  uint uVar1;
  
  if ((int)DAT_801d2918._2_2_ - (int)param_2 < (int)*(short *)(param_1 + 0xe)) {
                    /* Possible PsyQ macro: setTile1() + setSemiTrans(tile1, 1) */
                    /* Possible PsyQ macro: setLineF2() */
    uVar1 = ((int)*(short *)(param_1 + 0xe) < (int)DAT_801d2918._2_2_ + param_2 + 0x140 ^ 1) << 4;
  }
  else {
    uVar1 = 0x20;
  }
  if ((int)g_cam_y - (int)param_3 < (int)*(short *)(param_1 + 0x12)) {
    if ((int)g_cam_y + param_3 + 0xf0 <= (int)*(short *)(param_1 + 0x12)) {
      uVar1 = uVar1 | 0x80;
    }
  }
  else {
    uVar1 = uVar1 | 0x40;
  }
  return uVar1;
}


