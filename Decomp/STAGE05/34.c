// ID 34, STAGE05.BIN, handler 0x801DFD1C. Ghidra output with the object struct applied; not matching C.
// ---- 801dfd1c FUN_801dfd1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfd1c(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  obj->clut = DAT_80159fc9;
  bVar1 = obj->state;
  (*(code *)(&PTR_FUN_801ea60c)[obj->state])();
  if (obj->active != 0) {
    Enemy_ContactDamage(obj);
    cVar2 = Enemy_CheckWeaponHits(obj);
    if (cVar2 == '\x04') {
      obj->state = 7;
      obj->sub2 = 0;
    }
    else if (cVar2 == '\x02') {
      obj->clut = 0;
    }
    iVar3 = Obj_InActiveArea(obj);
    if (iVar3 == 0) {
      if (obj->var == 0) {
        FUN_80105888(obj);
      }
      else {
        Obj_Free(obj);
      }
    }
    else {
      obj->field_0x51 = bVar1;
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801dfe0c FUN_801dfe0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfe0c(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 6;
  obj->hitbox = &DAT_801ea62c;
  obj->box2 = &DAT_801ea630;
  FUN_801e0730(obj);
  obj->field_0x50 = 0;
  if ((obj->var & 0x7f) == 0) {
    obj->state = 1;
    obj->field_0x50 = 2;
  }
  else {
    obj->state = 3;
  }
  obj->sub2 = 0;
  Anim_Set(obj,0);
  return;
}


// ---- 801dfe9c FUN_801dfe9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfe9c(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->gravity = 0x4000;
    obj->speed_y_up = 0;
    obj->field_0x43 = 1;
    obj->sub2 = obj->sub2 + 1;
  }
  FUN_80104ccc(obj);
  if (obj->field_0x50 == '\0') {
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->state = 2;
      obj->sub2 = 0;
    }
  }
  else {
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  if (obj->speed_y_up < 0x60001) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  return;
}


// ---- 801dff64 FUN_801dff64

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dff64(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    FUN_8010544c(obj,0xd0);
    obj->speed_y_up = 0x18000;
    obj->gravity = 0x4000;
    obj->sub2 = obj->sub2 + 1;
  }
  else if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x43 = 0;
    obj->state = 3;
    obj->sub2 = 0;
  }
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if (obj->speed_y_up < -0x5ffff) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  return;
}


// ---- 801e0010 FUN_801e0010

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0010(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->field_0x50 = 0x1e;
    obj->sub2 = obj->sub2 + 1;
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    cVar1 = FUN_801e0450(obj);
    bVar2 = 5;
    if (cVar1 == '\0') {
      FUN_8010544c(obj,0xd);
      bVar2 = 4;
    }
    obj->state = bVar2;
    obj->sub2 = 0;
  }
  FUN_80106214(obj);
  FUN_801e0428(obj);
  return;
}


// ---- 801e00c8 FUN_801e00c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e00c8(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,1);
    if (obj->field_0x51 == '\x05') {
      if ((obj->flip & 0x40) == 0) {
        sVar2 = obj->x + 4;
      }
      else {
        sVar2 = obj->x + -4;
      }
      obj->x = sVar2;
      obj->flip = obj->flip ^ 0x40;
    }
    iVar3 = 0x10000;
    if (obj->flip == 0) {
      iVar3 = -0x10000;
    }
    obj->speed_x = iVar3;
    obj->accel_x = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
  }
  FUN_80104c34(obj);
  FUN_80106214(obj);
  FUN_801e0428(obj);
  cVar1 = FUN_801e0450(obj);
  if (cVar1 != '\0') {
    obj->state = 5;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801e01bc FUN_801e01bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e01bc(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,2);
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
  }
  iVar1 = Anim_AtLoopMarker(obj);
  if (iVar1 != 0) {
    FUN_8010544c(obj,0xd);
    obj->state = 4;
    obj->sub2 = 0;
  }
  FUN_80106214(obj);
  FUN_801e0428(obj);
  return;
}


// ---- 801e024c FUN_801e024c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e024c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,3);
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
  }
  iVar1 = Anim_AtLoopMarker(obj);
  if (iVar1 != 0) {
    obj->state = 3;
    obj->sub2 = 0;
  }
  FUN_80106214(obj);
  FUN_801e0428(obj);
  return;
}


// ---- 801e02d0 FUN_801e02d0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e02d0(MM8Obj *obj)

{
  short sVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  
  uVar2 = Rand();
  uVar2 = uVar2 & 0xff;
  uVar7 = 0;
  iVar4 = 0;
  iVar5 = 0;
  do {
    uVar2 = uVar2 - (byte)(&DAT_801ea638)[iVar5];
    if ((int)(uVar2 * 0x10000) < 0) {
      uVar7 = (&UNK_801ea639)[iVar5];
      break;
    }
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 2;
  } while (iVar4 < 5);
  if ((iVar4 != 0) && (puVar3 = (undefined1 *)Obj_AllocType2(obj), puVar3 != (undefined1 *)0x0)) {
    *puVar3 = 1;
    puVar3[6] = 0;
    puVar3[7] = uVar7;
    if (obj->flip == 0) {
      sVar1 = obj->x + 2;
    }
    else {
      sVar1 = obj->x + -2;
    }
    *(short *)(puVar3 + 0xe) = sVar1;
    *(short *)(puVar3 + 0x12) = obj->y + 8;
  }
  FUN_80108ed8(obj,2,8);
  uVar6 = 2;
  if (obj->flip != 0) {
    uVar6 = 0xfffffffe;
  }
  FUN_8012a724(obj,6,uVar6,8);
  FUN_8010544c(obj,10);
  if (obj->var == 0) {
    FUN_80105888(obj);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e0428 FUN_801e0428

void FUN_801e0428(int param_1)

{
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  if ((*(byte *)(param_1 + 0x33) & 0x80) == 0) {
    *(undefined1 *)(param_1 + 0x50) = 0;
    *(undefined1 *)(param_1 + 1) = 1;
    *(undefined1 *)(param_1 + 2) = 0;
  }
  return;
}


// ---- 801e0450 FUN_801e0450

undefined4 FUN_801e0450(int param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  short *psVar5;
  char *pcVar6;
  int iVar7;
  
  cVar2 = FUN_801e0560();
  uVar3 = 1;
  if (cVar2 != '\0') {
    cVar2 = FUN_801e063c(param_1);
    iVar7 = 0;
    if (cVar2 == '\0') {
      uVar3 = 1;
    }
    else {
      pcVar6 = &DAT_801b1eec;
      psVar5 = &DAT_801b1efa;
      do {
        if ((*pcVar6 != '\0') && ((char)psVar5[-4] == '\x19')) {
          if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
            bVar1 = false;
            if (*psVar5 < *(short *)(param_1 + 0xe)) {
              bVar1 = true;
            }
          }
          else {
            bVar1 = *(short *)(param_1 + 0xe) < *psVar5;
          }
          if ((bVar1) && (iVar4 = Obj_HitboxOverlap(param_1,pcVar6), iVar4 != 0)) {
            return 1;
          }
        }
        psVar5 = psVar5 + 0x28;
        iVar7 = iVar7 + 1;
        pcVar6 = pcVar6 + 0x50;
      } while (iVar7 < 0x20);
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ---- 801e0560 FUN_801e0560

bool FUN_801e0560(int param_1)

{
  char cVar1;
  char cVar2;
  short sVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  pcVar4 = *(char **)(param_1 + 0x38);
  sVar3 = *pcVar4 + 1;
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    sVar3 = -sVar3;
  }
  iVar6 = (int)(short)(*(short *)(param_1 + 0xe) + (short)pcVar4[2] + sVar3);
  iVar5 = (int)(((int)pcVar4[1] + (uint)*(ushort *)(param_1 + 0x12) + (int)pcVar4[3] + 1) * 0x10000)
          >> 0x10;
  cVar1 = FUN_80107204(iVar6,iVar5);
  cVar2 = FUN_80107204(iVar6,iVar5 + -8);
  return cVar1 != '\0' && cVar2 != '=';
}


// ---- 801e063c FUN_801e063c

bool FUN_801e063c(int param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(param_1 + 0x38);
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    iVar2 = -(int)*pcVar3;
  }
  else {
    iVar2 = (int)*pcVar3;
  }
  iVar2 = (int)(((int)pcVar3[2] + (uint)*(ushort *)(param_1 + 0xe) + iVar2) * 0x10000) >> 0x10;
  bVar1 = false;
  if ((int)((DAT_801d2928 + 0x20) * 0x10000) >> 0x10 < iVar2) {
    if ((iVar2 < (int)((DAT_801d2926 + 0x120) * 0x10000) >> 0x10) &&
       (iVar2 = (int)(((int)*(char *)(*(int *)(param_1 + 0x38) + 3) +
                      (uint)*(ushort *)(param_1 + 0x12)) * 0x10000) >> 0x10, DAT_801d292c < iVar2))
    {
      bVar1 = iVar2 < (int)((DAT_801d292a + 0xf0) * 0x10000) >> 0x10;
    }
    else {
      bVar1 = false;
    }
  }
  return bVar1;
}


// ---- 801e0730 FUN_801e0730

void FUN_801e0730(int param_1)

{
  byte bVar1;
  
  *(undefined1 *)(param_1 + 0x25) = 0;
  if ((*(byte *)(param_1 + 7) & 1) == 0) {
    if (*(short *)(param_1 + 0xe) <= DAT_8015e248._2_2_) {
                    /* Possible PsyQ macro: setLineF2() */
      *(undefined1 *)(param_1 + 0x25) = 0x40;
    }
  }
  else {
    bVar1 = Rand();
    *(byte *)(param_1 + 0x25) = bVar1 & 0x40;
  }
  return;
}


