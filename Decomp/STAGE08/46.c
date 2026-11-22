// ID 46, STAGE08.BIN, handler 0x801DA6FC. Ghidra output with the object struct applied; not matching C.
// ---- 801da6fc FUN_801da6fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da6fc(MM8Obj *obj)

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
LAB_801da740:
    obj->clut = bVar1;
  }
  else {
    bVar1 = bVar1 + 3;
    if (obj->var == 2) goto LAB_801da740;
  }
  (*(code *)(&PTR_FUN_801e101c)[obj->state])(obj);
  if (obj->active == 0) {
    return;
  }
  if ((obj->var < 3) && ((obj->anim_extra & 0x40) != 0)) {
    obj->clut = DAT_80159fe3;
  }
  obj->invuln = 7 < obj->state;
  cVar2 = FUN_801db220(obj);
  if (cVar2 == '\0') {
    if (bVar3 < 3) {
      cVar2 = FUN_801db938(obj,0x80,0x38);
      if (cVar2 != '\0') goto LAB_801da88c;
    }
    else {
      bVar3 = FUN_801db938(obj,0x38,0x38);
      if ((bVar3 != 0) &&
         (((bVar3 & 0x40) == 0 || (iVar4 = FUN_80104820(obj,0x38,0x100), iVar4 == 0))))
      goto LAB_801da864;
    }
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  else {
    if (bVar3 != 5) {
      FUN_80108e84(obj);
    }
    if (2 < bVar3) {
      FUN_801db8d0(obj);
LAB_801da864:
      Obj_Free(obj);
      return;
    }
    FUN_8012a5fc(obj,8);
    FUN_80108fd8(obj,0);
LAB_801da88c:
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801da8c0 FUN_801da8c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da8c0(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->box2 = &DAT_801e10a0;
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


// ---- 801da968 FUN_801da968

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da968(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0x10);
                    /* Possible PsyQ macro: setSprt16() + setSemiTrans(sprt16, 1) +
                       setShadeTex(sprt16, 1) */
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
  return;
}


// ---- 801daa3c FUN_801daa3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daa3c(MM8Obj *obj)

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
      FUN_801db820(obj,6);
      obj->state = 5;
      obj->sub2 = 0;
      return;
    }
    if ((int)DAT_8015e248._2_2_ - (int)sVar1 < 0x10) {
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
      FUN_801db820(obj,3);
      return;
    }
    FUN_801db820(obj,4);
    bVar3 = obj->sub2;
    obj->field_0x50 = 0xf;
  }
  obj->sub2 = bVar3 + 1;
  return;
}


// ---- 801dab88 FUN_801dab88

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dab88(MM8Obj *obj)

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
      goto LAB_801dac90;
    }
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 == 0) goto LAB_801dac90;
    if (obj->var == 2) {
      iVar2 = FUN_801db778(obj);
      cVar3 = '\x03';
      if (iVar2 == 0) goto LAB_801dac08;
      obj->field_0x52 = 1;
    }
    else {
LAB_801dac08:
      obj->field_0x52 = 0;
      cVar3 = obj->var + 3;
    }
    obj->field_0x53 = cVar3;
    FUN_801db0fc(obj);
    bVar1 = obj->sub2;
    obj->field_0x50 = 0x20;
  }
  obj->sub2 = bVar1 + 1;
LAB_801dac90:
  if ((obj->anim_extra & 0x80) != 0) {
    FUN_8010544c(obj,0x123);
    iVar2 = ((byte)obj->field_0x53 - 3) * 4;
    FUN_801db33c(obj,(uint)(byte)obj->field_0x53,(int)*(short *)(&DAT_801e10c8 + iVar2),
                 (int)*(short *)(&DAT_801e10ca + iVar2));
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->state = 5;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801dad14 FUN_801dad14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dad14(MM8Obj *obj)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  
                    /* Possible PsyQ macro: setTile8() */
  if (obj->sub2 == 0) {
    Anim_Set(obj,0x10);
    uVar1 = FUN_801db160(obj);
    obj->field_0x50 = uVar1;
    obj->field_0x51 = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
                    /* Possible PsyQ macro: setPolyGT4() */
    if (cVar2 == '\0') {
      iVar4 = FUN_801db1d0(obj);
      bVar3 = 4;
      if ((iVar4 == 0) && (bVar3 = 2, 0x160 < (ushort)((obj->x - DAT_8015e248._2_2_) + 0xb0U))) {
        obj->field_0x50 = 1;
      }
      else {
        obj->state = bVar3;
        obj->sub2 = 0;
      }
    }
  }
  if (obj->field_0x51 == '\0') {
    iVar4 = FUN_801db1d0(obj);
    if (iVar4 != 0) {
      obj->field_0x51 = 0x1e;
    }
  }
  else {
    cVar2 = obj->field_0x51 + -1;
    obj->field_0x51 = cVar2;
    if (cVar2 == '\0') {
      obj->state = 4;
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


// ---- 801dae48 FUN_801dae48

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dae48(MM8Obj *obj)

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
      goto LAB_801daf40;
    }
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    if (iVar3 == 0) goto LAB_801daf40;
    obj->speed_y_up = 0x40000;
    bVar2 = obj->sub2;
    obj->gravity = 0x4000;
  }
  obj->sub2 = bVar2 + 1;
LAB_801daf40:
  FUN_80104ccc(obj);
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
  if ((bVar1 == 3) && ((obj->field_0x33 & 0x80) != 0)) {
    Anim_Set(obj,1);
    FUN_8010544c(obj,0x125);
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  return;
}


// ---- 801dafd0 FUN_801dafd0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dafd0(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->field_0x43 = 1;
                    /* Possible PsyQ macro: setTile16() */
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
  return;
}


// ---- 801db080 FUN_801db080

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db080(MM8Obj *obj)

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


// ---- 801db0fc FUN_801db0fc

void FUN_801db0fc(int param_1,undefined1 param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 7);
  if (cVar1 == '\0') {
    param_2 = 4;
  }
  else {
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
    if (cVar1 == '\x01') {
      param_2 = 3;
    }
    else if ((cVar1 == '\x02') && (param_2 = 5, *(char *)(param_1 + 0x52) != '\0')) {
      param_2 = 0x1a;
    }
  }
  Anim_Set(param_1,param_2);
  return;
}


// ---- 801db160 FUN_801db160

undefined1 FUN_801db160(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Rand();
  uVar1 = uVar1 & 0xf;
  iVar2 = 0;
  do {
    uVar1 = uVar1 - (byte)(&DAT_801e1040)[iVar2];
    if ((int)(uVar1 * 0x10000) < 0) {
      return (&DAT_801e1044)[iVar2];
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0;
}


// ---- 801db1d0 FUN_801db1d0

bool FUN_801db1d0(int param_1)

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


// ---- 801db220 FUN_801db220

char FUN_801db220(int param_1)

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
           (&PTR_DAT_801e1070)[(*(byte *)(param_1 + 0x32) & 0xf) + iVar4];
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


// ---- 801db33c FUN_801db33c

void FUN_801db33c(int param_1,byte param_2,short param_3,short param_4)

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
    puVar2[0x47] = (&DAT_801e10c0)[iVar3];
    uVar1 = (&DAT_801e10c1)[iVar3];
    puVar2[0x44] = 2;
    puVar2[1] = 7;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[0x45] = uVar1;
  }
  return;
}


// ---- 801db45c FUN_801db45c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db45c(MM8Obj *obj)

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
                    /* Possible PsyQ macro: setLineF2() */
      uVar4 = 0x50000;
      if (0xa0 < (ushort)((*(short *)&obj->field_0x54 - DAT_8015e248._2_2_) + 0x50U)) {
        uVar4 = 0x60000;
      }
      FUN_801051d8(obj,&g_player,uVar4,0x4000);
                    /* Possible PsyQ macro: setPolyG3() + setSemiTrans(polyG3, 1) */
      if ((obj->flip & 0x40) == 0) {
        if (-0x8000 < obj->speed_x) {
          obj->speed_x = -0x8000;
        }
      }
      else if (obj->speed_x < 0x8000) {
        obj->speed_x = 0x8000;
      }
      obj->box2 = &DAT_801e10a8;
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
        pbVar3 = &DAT_801e10b0;
        obj->accel_x = 0;
        obj->speed_y_up = 0;
        obj->gravity = 0;
      }
      else {
        if (bVar1 != 5) goto LAB_801db5bc;
        iVar2 = 0x30000;
        if ((obj->flip & 0x40) == 0) {
          iVar2 = -0x30000;
        }
        obj->speed_x = iVar2;
        in_a1 = 6;
        obj->gravity = 0x4000;
        pbVar3 = &DAT_801e10b8;
      }
      obj->box2 = pbVar3;
    }
LAB_801db5bc:
    Anim_Set(obj,in_a1);
    *(short *)&obj->field_0x54 = obj->x;
    *(short *)puVar5 = obj->y;
    bVar1 = obj->sub2;
  }
  else {
    if ((obj->sub2 != 1) || (obj->var != 4)) goto LAB_801db654;
    if ((obj->flip & 0x40) == 0) {
      iVar2 = (int)*(short *)&obj->field_0x54 - (int)obj->x;
    }
    else {
      iVar2 = (int)obj->x - (int)*(short *)&obj->field_0x54;
    }
    if (iVar2 < 0x10) goto LAB_801db654;
    bVar1 = obj->sub2;
    obj->gravity = 0x1000;
  }
  obj->sub2 = bVar1 + 1;
LAB_801db654:
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
    if ((obj->field_0x33 & 0x80) != 0) {
      if (obj->var == 5) {
        if (obj->field_0x43 != '\0') {
          FUN_8010544c(obj,0x127);
          obj->field_0x50 = 8;
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
      FUN_801db8d0(obj);
      FUN_80108e84(obj);
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801db778 FUN_801db778

undefined4 FUN_801db778(int param_1)

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


// ---- 801db820 FUN_801db820

void FUN_801db820(int param_1,uint param_2)

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


// ---- 801db8d0 FUN_801db8d0

void FUN_801db8d0(int param_1)

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


// ---- 801db938 FUN_801db938

uint FUN_801db938(int param_1,short param_2,short param_3)

{
  uint uVar1;
  
  if ((int)DAT_801d2918._2_2_ - (int)param_2 < (int)*(short *)(param_1 + 0xe)) {
    uVar1 = ((int)*(short *)(param_1 + 0xe) < (int)DAT_801d2918._2_2_ + param_2 + 0x140 ^ 1) << 4;
  }
  else {
    uVar1 = 0x20;
  }
                    /* Probable PsyQ macro: setTile16() */
  if ((int)g_cam_y - (int)param_3 < (int)*(short *)(param_1 + 0x12)) {
                    /* Possible PsyQ macro: setTile8() */
    if ((int)g_cam_y + param_3 + 0xf0 <= (int)*(short *)(param_1 + 0x12)) {
      uVar1 = uVar1 | 0x80;
    }
  }
  else {
    uVar1 = uVar1 | 0x40;
  }
  return uVar1;
}


