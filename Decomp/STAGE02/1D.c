// ID 1D, STAGE02.BIN, handler 0x801DBDC0. Ghidra output with the object struct applied; not matching C.
// ---- 801dbdc0 FUN_801dbdc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbdc0(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801e86c4)[obj->state])();
  if (obj->active == 0) {
    return;
  }
  obj->clut = (&DAT_80159f64)[obj->bank] + (obj->var & 1);
  if (((obj->field_0x5a & 0x80) == 0) && (obj->field_0x59 != -0x80)) {
    iVar2 = Enemy_CheckWeaponHits(obj);
    if (iVar2 == 2) {
      obj->clut = 0;
    }
    else if (iVar2 < 3) {
      if (iVar2 == 1) {
        obj->field_0x5a = 0x80;
        obj->state = 5;
        obj->sub2 = 0;
        Anim_Set(obj,0x13);
        obj->field_0x58 = 0x1e;
        obj->speed_x = 0;
        obj->accel_x = 0;
        obj->speed_y_up = 0x20000;
        obj->gravity = 0;
        if (((obj->field_0x59 & 0x40) != 0) &&
           (DAT_801b29a0 = DAT_801b29a0 & ~(byte)(1 << ((byte)obj->field_0x54 & 0x1f)),
           obj->field_0x55 != '\0')) {
          FUN_80111c28();
          DAT_801b29a0 = 0;
        }
        obj->dmg_table = 3;
        obj->field_0x59 = obj->field_0x59 & 0xf7;
        *(undefined2 *)&obj->field_0x54 = *(undefined2 *)(DAT_8016d404 + 0xe);
      }
    }
    else if (iVar2 == 4) {
      if (((obj->field_0x59 & 0x40) != 0) &&
         (DAT_801b29a0 = DAT_801b29a0 & ~(byte)(1 << ((byte)obj->field_0x54 & 0x1f)),
         obj->field_0x55 != '\0')) {
        FUN_80111c28();
        DAT_801b29a0 = 0;
      }
      FUN_80108e84(obj);
      FUN_8012a5fc(obj,0);
      FUN_80108fd8(obj,4);
      goto LAB_801dc024;
    }
  }
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    return;
  }
  if (((obj->field_0x59 & 0x40) != 0) &&
     (DAT_801b29a0 = DAT_801b29a0 & ~(byte)(1 << ((byte)obj->field_0x54 & 0x1f)),
     obj->field_0x55 != '\0')) {
    FUN_80111c28();
    DAT_801b29a0 = 0;
  }
LAB_801dc024:
  Obj_Free(obj);
  return;
}


// ---- 801dc048 FUN_801dc048

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc048(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  Enemy_InitFromTable();
  iVar2 = -0x10000;
  cVar1 = (&DAT_80159f64)[obj->bank];
  obj->draw_list = (obj->var & 1) * '\x02' + 5;
  obj->state = 1;
  obj->sub2 = 0;
  obj->box2 = &UNK_801e86a8 + (obj->var & 1) * 5;
  obj->hitbox = &DAT_801e86a4;
  obj->clut = cVar1 + (obj->var & 1);
  if ((obj->flip & 0x40) != 0) {
    iVar2 = 0x10000;
  }
  obj->speed_y_up = 0x40000;
  obj->speed_x = iVar2;
  obj->gravity = 0x4000;
  obj->field_0x43 = 1;
  obj->field_0x59 = 0;
  obj->field_0x5a = 0;
  *(undefined4 *)&obj->field_0x50 = 0;
  Anim_Set(obj,1);
  FUN_8010544c(obj,0x9b);
  return;
}


// ---- 801dc12c FUN_801dc12c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc12c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e86e0)[obj->sub2])();
  return;
}


// ---- 801dc168 FUN_801dc168

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc168(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e86ec)[obj->sub2])();
  return;
}


// ---- 801dc1a4 FUN_801dc1a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc1a4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8704)[obj->sub2])();
  return;
}


// ---- 801dc1e0 FUN_801dc1e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc1e0(MM8Obj *obj)

{
  undefined2 uVar1;
  
  (*(code *)(&PTR_FUN_801e8710)[obj->sub2])();
  uVar1 = DAT_8015e248._2_2_;
  obj->x_frac = (undefined2)DAT_8015e248;
  obj->x = uVar1;
  uVar1 = DAT_8015e24c._2_2_;
  obj->y_frac = (undefined2)DAT_8015e24c;
  obj->y = uVar1;
  obj->x = (short)(char)(&DAT_801e86bc)[(uint)(byte)obj->field_0x54 * 2] + obj->x;
  obj->y = (short)(char)(&DAT_801e86bd)[(uint)(byte)obj->field_0x54 * 2] + obj->y;
  Anim_Step();
  return;
}


// ---- 801dc29c FUN_801dc29c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc29c(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (DAT_801b29a0 == '\0') {
    obj->field_0x59 = 0x80;
    obj->state = 6;
    obj->sub2 = 0;
    Anim_Set(obj,obj->var * '\x02' + '\x10');
    iVar2 = 0x10000;
    if ((obj->flip & 0x40) != 0) {
      iVar2 = -0x10000;
    }
    obj->speed_y_up = 0x40000;
    obj->gravity = 0x4000;
    obj->speed_x = iVar2;
    obj->accel_x = 0;
    obj->field_0x43 = 1;
  }
  else {
    if (DAT_8015e2a3 == '\0') {
      DAT_801b29a0 = '\0';
    }
    if (obj->sub3 == 0) {
      Anim_Set(obj,obj->var * '\x02' + '\x0f');
      DAT_801b29a1 = DAT_801b29a1 + 0x14;
      if (obj->field_0x55 != '\0') {
                    /* Possible PsyQ macro: setPolyGT4() */
        obj->field_0x58 = 0x3c;
      }
      obj->sub3 = 1;
    }
    if (obj->field_0x55 != '\0') {
      cVar1 = obj->field_0x58;
      obj->field_0x58 = cVar1 + -1;
      if (cVar1 == '\0') {
        obj->field_0x58 = 0x3c;
        iVar2 = FUN_80111cb4(1);
        if (iVar2 == 0) {
          DAT_801b29a0 = 0;
          return;
        }
      }
      uVar3 = FUN_80111858();
      if ((uVar3 & 0xff) != 0) {
        FUN_80111c90();
      }
      uVar4 = (uint)DAT_801b29a1;
      DAT_801b29a1 = (byte)(uVar4 - uVar3);
      if ((int)((uVar4 - uVar3) * 0x1000000) < 1) {
        FUN_80111c28();
        DAT_801b29a0 = '\0';
      }
    }
  }
  return;
}


// ---- 801dc464 FUN_801dc464

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc464(MM8Obj *obj)

{
  Obj_ApplySpeed();
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
                    /* Possible PsyQ macro: setLineF2() */
  if ((obj->field_0x33 & 0x80) != 0) {
    Anim_Set(obj,2);
    obj->field_0x43 = 0;
    obj->sub2 = 1;
  }
  return;
}


// ---- 801dc4d8 FUN_801dc4d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc4d8(MM8Obj *obj)

{
                    /* Probable PsyQ macro: setTile16() */
  if (((int)(short)obj->frame & 0x8000U) == 0) {
    Anim_Step();
  }
  else {
    obj->sub2 = 2;
  }
  return;
}


// ---- 801dc514 FUN_801dc514

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc514(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Set(obj,3);
  iVar1 = -0x8000;
  obj->state = 2;
  obj->sub2 = 0;
  if ((obj->flip & 0x40) != 0) {
    iVar1 = 0x8000;
  }
                    /* Possible PsyQ macro: setPolyF3() */
  obj->field_0x59 = 0x20;
  obj->speed_x = iVar1;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->field_0x58 = 0xff;
  Anim_Step();
  return;
}


// ---- 801dc588 FUN_801dc588

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc588(MM8Obj *obj)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  FUN_80104d00();
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    *(short *)&obj->field_0x54 = obj->x;
    *(short *)&obj->field_0x56 = obj->y;
    Anim_Set(obj,7);
    if ((obj->flip & 0x40) == 0) {
      sVar4 = (short)(char)(&DAT_801e86b4)[(uint)obj->anim_extra * 2];
    }
    else {
      sVar4 = -(short)(char)(&DAT_801e86b4)[(uint)obj->anim_extra * 2];
    }
    obj->x = *(short *)&obj->field_0x54 + sVar4;
    cVar1 = (&DAT_801e86b5)[(uint)obj->anim_extra * 2];
    obj->sub2 = 1;
    obj->field_0x59 = 4;
    obj->sub3 = 0;
    obj->y = (short)cVar1 + *(short *)&obj->field_0x56;
  }
  else if ((obj->field_0x33 & 0x30) == 0) {
    iVar5 = FUN_801dd208(obj);
    if (iVar5 != 0) {
      bVar3 = *(byte *)(iVar5 + 0x59);
      if (((bVar3 & 0x10) != 0) && ((bVar3 & 8) == 0)) {
        *(byte *)(iVar5 + 0x59) = bVar3 | 8;
        obj->sub2 = 3;
        obj->field_0x59 = 8;
        *(undefined1 *)(iVar5 + 0x58) = 0xf0;
        Anim_Set(obj,10);
        *(MM8Obj **)(iVar5 + 0x50) = obj;
        *(int *)&obj->field_0x50 = iVar5;
        return;
      }
      if (((bVar3 & 1) != 0) && ((bVar3 & 2) == 0)) {
        *(byte *)(iVar5 + 0x59) = bVar3 | 2;
        *(MM8Obj **)(iVar5 + 0x50) = obj;
        obj->sub2 = 4;
        *(int *)&obj->field_0x50 = iVar5;
        obj->sub3 = 0;
        obj->field_0x59 = 2;
        Anim_Set(obj,5);
        return;
      }
    }
    if ((DAT_801b29a0 & 0xf) != 0xf) {
      if ((obj->flip & 0x40) == 0) {
        bVar2 = DAT_8015e248._2_2_ < obj->x;
      }
      else {
        bVar2 = false;
        if (obj->x < DAT_8015e248._2_2_) {
          bVar2 = true;
        }
      }
      if (bVar2) {
        uVar9 = 0;
        do {
          uVar7 = obj->flip >> 6 & 1;
          uVar6 = (obj->var ^ uVar9) << 1;
          uVar8 = 1 << (uVar7 | uVar6 & 0x1f);
          if (((DAT_801b29a0 & uVar8) == 0) &&
             (iVar5 = Obj_HitboxOverlap(&g_player,obj), iVar5 != 0)) {
            if ((DAT_801b29a0 & 0xf) == 0) {
              if ((DAT_8015e27f != '\0') || (iVar5 = FUN_80111bb0(), iVar5 == 0)) break;
              obj->field_0x55 = 1;
              DAT_801b29a1 = 0;
            }
            else {
              obj->field_0x55 = 0;
            }
            DAT_801b29a0 = (byte)uVar8 | DAT_801b29a0;
                    /* Possible PsyQ macro: setLineF2() */
            obj->field_0x59 = 0x40;
            obj->field_0x54 = (byte)uVar7 | (byte)uVar6;
            obj->state = 4;
            obj->sub2 = 0;
            obj->sub3 = 0;
            bVar3 = obj->var ^ (byte)uVar9;
            obj->var = bVar3;
            obj->draw_list = (bVar3 & 1) + 5;
            return;
          }
          uVar9 = uVar9 + 1;
        } while ((int)uVar9 < 2);
      }
    }
    cVar1 = obj->field_0x58;
    obj->field_0x58 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->field_0x58 = 0xff;
      uVar9 = Rand();
      if ((uVar9 & 1) != 0) {
        FUN_8010910c(obj);
      }
      iVar5 = -0x8000;
      if ((obj->flip & 0x40) != 0) {
        iVar5 = 0x8000;
      }
      obj->speed_x = iVar5;
      obj->accel_x = 0;
      obj->speed_y_up = 0;
      obj->gravity = 0;
    }
    Anim_Step(obj);
  }
  else {
    Anim_Set(obj,4);
    obj->field_0x58 = 0x3c;
    obj->sub2 = 2;
    obj->field_0x59 = 1;
  }
  return;
}


// ---- 801dc964 FUN_801dc964

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc964(MM8Obj *obj)

{
  short sVar1;
  uint uVar2;
  char *pcVar3;
  
  if (((obj->field_0x59 & 8) != 0) &&
     ((((pcVar3 = *(char **)&obj->field_0x50, *pcVar3 == '\0' || (pcVar3[6] != '\x1d')) ||
       (obj->var != pcVar3[7])) ||
      ((*(MM8Obj **)(pcVar3 + 0x50) != obj || ((pcVar3[0x59] & 8U) == 0)))))) {
    obj->field_0x58 = 0;
    obj->field_0x59 = obj->field_0x59 & 0xf7;
  }
  if (obj->sub3 == 0) {
    if ((obj->flip & 0x40) == 0) {
      sVar1 = (short)(char)(&DAT_801e86b4)[(uint)obj->anim_extra * 2];
    }
    else {
      sVar1 = -(short)(char)(&DAT_801e86b4)[(uint)obj->anim_extra * 2];
    }
    obj->x = *(short *)&obj->field_0x54 + sVar1;
                    /* Probable PsyQ macro: setPolyGT4() */
    obj->y = (short)(char)(&DAT_801e86b5)[(uint)obj->anim_extra * 2] + *(short *)&obj->field_0x56;
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      if ((obj->flip & 0x40) == 0) {
                    /* Probable PsyQ macro: setLineF2() */
        sVar1 = (short)DAT_801e86ba;
      }
      else {
        sVar1 = -(short)DAT_801e86ba;
      }
      obj->x = *(short *)&obj->field_0x54 + sVar1;
                    /* Possible PsyQ macro: setLineF2() */
      obj->y = (short)DAT_801e86bb + *(short *)&obj->field_0x56;
      Anim_Set(obj,8);
      obj->field_0x58 = 0x78;
      obj->sub3 = 1;
      obj->field_0x59 = obj->field_0x59 | 0x10;
    }
  }
  else {
    if (obj->field_0x58 == '\0') {
      uVar2 = Rand();
      if (((obj->field_0x59 & 8) == 0) && ((uVar2 & 1) != 0)) {
        obj->field_0x58 = 0xe;
        obj->sub3 = 0;
      }
      else {
        obj->sub3 = 2;
      }
      Anim_Set(obj,9);
      obj->gravity = 0x4000;
      obj->field_0x43 = 1;
      obj->state = 3;
      obj->speed_y_up = 0;
      obj->speed_x = 0;
      obj->accel_x = 0;
      obj->sub2 = 0;
      obj->field_0x59 = 4;
      return;
    }
    obj->field_0x58 = obj->field_0x58 + -1;
  }
  Anim_Step(obj);
  return;
}


// ---- 801dcbc8 FUN_801dcbc8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcbc8(MM8Obj *obj)

{
  char cVar1;
  
  if ((obj->field_0x59 & 2) == 0) {
    cVar1 = obj->field_0x58;
    obj->field_0x58 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->state = 1;
      obj->sub2 = 2;
      obj->flip = obj->flip ^ 0x40;
    }
    else {
      Anim_Step();
    }
  }
  else {
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x58 = 0x3c;
    obj->sub2 = 5;
  }
  return;
}


// ---- 801dcc40 FUN_801dcc40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcc40(MM8Obj *obj)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)&obj->field_0x50;
  if ((((*pcVar3 == '\0') || (pcVar3[6] != '\x1d')) || (pcVar3[7] != obj->var)) ||
     (*(MM8Obj **)(pcVar3 + 0x50) != obj)) {
    bVar1 = obj->sub3;
    if (bVar1 != 2) {
      obj->state = 1;
      obj->sub2 = 2;
      return;
    }
  }
  else {
    bVar1 = obj->sub3;
  }
  if (bVar1 == 1) {
    if ((pcVar3[0x59] & 0x10U) == 0) {
      Anim_Set(obj,0xc);
      obj->sub3 = 2;
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && (((int)(short)obj->frame & 0x8000U) != 0)) {
      Anim_Set(obj,0xb);
      obj->sub3 = 1;
    }
  }
  else if ((bVar1 == 2) && (((int)(short)obj->frame & 0x8000U) != 0)) {
    uVar2 = *(undefined4 *)(pcVar3 + 0xc);
    obj->gravity = 0x4000;
    obj->field_0x43 = 1;
    obj->state = 3;
    obj->field_0x59 = 4;
    obj->speed_y_up = 0;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->sub2 = 0;
    obj->sub3 = 2;
    obj->x_frac = (short)uVar2;
    obj->x = (short)((uint)uVar2 >> 0x10);
  }
  Anim_Step(obj);
  return;
}


// ---- 801dcdb4 FUN_801dcdb4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcdb4(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub3 == 0) {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->sub3 = 1;
      obj->field_0x58 = 0x3c;
    }
  }
  else {
    cVar1 = obj->field_0x58;
    obj->field_0x58 = cVar1 + -1;
    if (cVar1 == '\0') {
      FUN_80108e84(obj);
      FUN_8012a5fc(obj,0);
      Obj_Free(obj);
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801dce44 FUN_801dce44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce44(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = obj->field_0x58;
  obj->field_0x58 = cVar1 + -1;
  if (cVar1 == '\0') {
    FUN_80108e84();
    FUN_8012a5fc(obj,0);
    Obj_Free(obj);
  }
  return;
}


// ---- 801dce98 FUN_801dce98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce98(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  Obj_ApplySpeed();
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
  bVar1 = obj->sub3;
  if (bVar1 == 1) {
    cVar2 = obj->field_0x58;
    obj->field_0x58 = cVar2 + -1;
    if (cVar2 == '\0') {
      Anim_Set(obj,0xe);
      obj->gravity = 0x4000;
      obj->speed_y_up = 0;
      obj->sub3 = 2;
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && (cVar2 = obj->field_0x58, obj->field_0x58 = cVar2 + -1, cVar2 == '\0')) {
      Anim_Set(obj,0xd);
      obj->field_0x58 = 0x5a;
      obj->speed_y_up = 0x1000;
      obj->gravity = 0;
      obj->sub3 = 1;
    }
  }
  else if ((bVar1 == 2) && ((obj->field_0x33 & 0x80) != 0)) {
    obj->flip = obj->flip ^ 0x40;
    Anim_Set(obj,2);
    obj->field_0x43 = 0;
    obj->state = 1;
    obj->sub2 = 1;
    obj->speed_y_up = 0;
    obj->gravity = 0;
    return;
  }
  Anim_Step(obj);
  return;
}


// ---- 801dcff4 FUN_801dcff4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcff4(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  
  FUN_80104c34();
  FUN_80106214(obj);
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      Anim_Set(obj,0x15);
      obj->sub2 = 2;
      obj->speed_x = 0;
      obj->speed_y_up = 0;
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      sVar3 = 2;
      if (*(short *)&obj->field_0x54 <= obj->x) {
        sVar3 = -2;
      }
      obj->x = obj->x + sVar3;
      cVar2 = obj->field_0x58;
      obj->field_0x58 = cVar2 + -1;
      if (cVar2 == '\0') {
        Anim_Set(obj,0x14);
        iVar4 = 0xc000;
        if ((obj->flip & 0x40) != 0) {
          iVar4 = -0xc000;
        }
        obj->speed_x = iVar4;
        obj->sub2 = 1;
      }
    }
  }
  else if ((bVar1 == 2) && (((int)(short)obj->frame & 0x8000U) != 0)) {
    Obj_Free(obj);
  }
  Anim_Step(obj);
  return;
}


// ---- 801dd120 FUN_801dd120

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd120(MM8Obj *obj)

{
  FUN_80104ccc();
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
  if (obj->sub2 == 0) {
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->speed_y_up = 0x20000;
      obj->gravity = 0x4000;
      obj->sub2 = 1;
      Anim_SetAtStep(obj,obj->var * '\x02' + '\x10',1);
    }
  }
  else if ((obj->sub2 == 1) && ((obj->field_0x33 & 0x80) != 0)) {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    Obj_Free(obj);
  }
  return;
}


// ---- 801dd208 FUN_801dd208

char * FUN_801dd208(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = &g_main_pool;
  pcVar3 = "";
  while ((((pcVar2 == param_1 || (*pcVar2 == '\0')) || (pcVar3[-0x1f] != '\x1d')) ||
         (((pcVar3[-0x1e] != param_1[7] || (*pcVar3 != param_1[0x25])) ||
          (iVar1 = Obj_HitboxOverlap(param_1,pcVar2), iVar1 == 0))))) {
    pcVar2 = pcVar2 + 0x60;
    pcVar3 = pcVar3 + 0x60;
    if (&DAT_8015c974 <= pcVar2) {
      return (char *)0x0;
    }
  }
  return pcVar2;
}


