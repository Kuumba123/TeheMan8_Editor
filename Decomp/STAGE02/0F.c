// ID 0F, STAGE02.BIN, handler 0x801D8EB0. Ghidra output with the object struct applied; not matching C.
// ---- 801d8eb0 FUN_801d8eb0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8eb0(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e8514)[obj->state])();
  if ((obj->state != 4) && (obj->active != 0)) {
    cVar1 = FUN_801d9cc8(obj);
    if (cVar1 != '\0') {
      obj->state = 4;
      obj->sub2 = 0;
    }
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801d8f3c FUN_801d8f3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8f3c(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  
  Enemy_InitFromTable();
  iVar3 = (obj->var & 3) << 0x10;
  if ((obj->var & 3) == 0) {
    uVar4 = Rand();
    iVar3 = (uVar4 & 3) << 0x10;
    if ((uVar4 & 3) == 0) {
      iVar3 = 0x10000;
    }
  }
  obj->speed_x = iVar3;
  if ((obj->var & 0x40) == 0) {
    obj->accel_x = -0x1000;
    obj->flip = 0;
    obj->speed_x = -obj->speed_x;
  }
  else {
    obj->accel_x = 0x1000;
                    /* Possible PsyQ macro: setLineF2() */
    obj->flip = 0x40;
  }
  *(int *)&obj->field_0x50 = obj->speed_x;
  if ((obj->var & 0x40) == 0) {
    iVar3 = -0x10000;
  }
  else {
    iVar3 = 0x10000;
  }
  obj->speed_x = iVar3;
  obj->draw_list = 9;
  obj->box2 = (byte *)0x0;
  obj->field_0x43 = 0;
  obj->field_0x57 = 2;
  obj->field_0x58 = 0;
  obj->field_0x59 = 0x10;
  obj->field_0x5a = 0;
  if ((obj->var & 0x80) == 0) {
    obj->draw_list = 6;
    obj->hitbox = &DAT_801e84e8;
    obj->state = 2;
    obj->box2 = &DAT_801e84f4;
    obj->field_0x54 = 0;
    puVar5 = (undefined1 *)FUN_80105628();
    if (puVar5 != (undefined1 *)0x0) {
      *puVar5 = 1;
      puVar5[6] = 3;
      puVar5[7] = 2;
      puVar5[0x46] = 1;
      bVar1 = obj->flip;
      *(MM8Obj **)(puVar5 + 0x54) = obj;
      puVar5[0x25] = bVar1;
    }
    Anim_Set(obj,0);
    cVar2 = Obj_InActiveArea(obj);
    if (cVar2 != '\0') {
      FUN_8010544c(obj,0x85);
    }
  }
  else {
    obj->state = 1;
    obj->speed_y_up = -0x8000;
    obj->hitbox = &DAT_801e84ec;
    obj->field_0x54 = 10;
    obj->field_0x56 = 3;
    *(int *)&obj->y_frac = *(int *)&obj->y_frac + -0xf0000;
    obj->clut = obj->clut + 6;
    Anim_Set(obj,1);
  }
  return;
}


// ---- 801d910c FUN_801d910c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d910c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8528)[obj->sub2])();
  return;
}


// ---- 801d9148 FUN_801d9148

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9148(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  cVar1 = obj->field_0x54 + -1;
  obj->field_0x54 = cVar1;
  if (cVar1 == '\0') {
    obj->field_0x54 = 10;
    if ((byte)obj->field_0x56 < 3) {
      obj->clut = obj->clut - 3;
    }
    obj->field_0x56 = obj->field_0x56 + -1;
    if (obj->field_0x56 == '\0') {
      obj->sub2 = obj->sub2 + 1;
      if ((obj->var & 0x40) == 0) {
        iVar2 = -0xc0000;
      }
      else {
        iVar2 = 0xc0000;
      }
      obj->speed_x = iVar2;
      obj->field_0x54 = 8;
      obj->draw_list = 6;
    }
  }
  FUN_80104d18();
  return;
}


// ---- 801d9200 FUN_801d9200

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9200(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  
  cVar2 = obj->field_0x54 + -1;
  obj->field_0x54 = cVar2;
  if (cVar2 == '\0') {
    if (obj->anim_extra == 1) {
      obj->state = 2;
      obj->sub2 = 0;
      if ((obj->var & 0x40) == 0) {
        iVar3 = -0x10000;
      }
      else {
        iVar3 = 0x10000;
      }
      obj->speed_x = iVar3;
      obj->hitbox = &DAT_801e84e8;
      obj->speed_y_up = 0;
      obj->box2 = &DAT_801e84f4;
      obj->field_0x54 = 0;
      Anim_Set(obj,0);
      puVar4 = (undefined1 *)FUN_80105628();
      if (puVar4 != (undefined1 *)0x0) {
        puVar4[6] = 3;
        *puVar4 = 1;
        puVar4[7] = 2;
        puVar4[0x46] = 1;
        bVar1 = obj->flip;
        *(MM8Obj **)(puVar4 + 0x54) = obj;
        puVar4[0x25] = bVar1;
      }
      cVar2 = Obj_InActiveArea(obj);
      if (cVar2 != '\0') {
        FUN_8010544c(obj,0x85);
      }
    }
    else {
      obj->field_0x54 = 8;
      FUN_80104c34(obj);
      Anim_Step(obj);
    }
  }
  return;
}


// ---- 801d9314 FUN_801d9314

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9314(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  cVar1 = Obj_InActiveArea();
  if ((cVar1 != '\0') && (obj->field_0x5a == '\0')) {
    cVar1 = Enemy_CheckWeaponHits(obj);
    if (cVar1 == '\x03') {
      if (DAT_80158f5c == '\n') {
        obj->state = 4;
        obj->sub2 = 0;
        FUN_80108fd8(obj,1);
      }
      else {
        obj->sub2 = 1;
        if ((obj->var & 0x40) == 0) {
          iVar2 = -0x1000;
        }
        else {
          iVar2 = 0x1000;
        }
        obj->accel_x = iVar2;
        *(short *)&obj->field_0x54 = *(short *)&obj->field_0x54 + 0x3c;
      }
    }
    cVar1 = obj->field_0x59 + -1;
    obj->field_0x59 = cVar1;
    if (cVar1 == '\0') {
      FUN_8010544c(obj,0x86);
      obj->field_0x59 = 0x10;
    }
  }
  (*(code *)(&PTR_FUN_801e8530)[obj->sub2])(obj);
  cVar1 = FUN_801d9bdc(obj);
  if (cVar1 != '\0') {
    obj->state = 3;
    obj->sub2 = (byte)((obj->var & 0x20) >> 5);
    obj->field_0x57 = 2;
    if (obj->sub2 == 0) {
      iVar2 = 0x80000;
      if ((obj->var & 0x40) == 0) {
        iVar2 = -0x80000;
      }
      obj->speed_x = iVar2;
      obj->speed_y_up = 0x20000;
      obj->hitbox = &DAT_801e84f0;
      obj->field_0x54 = 8;
      Anim_Set(obj,2);
    }
  }
  Anim_Step(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    if ((DAT_8015e27c & 0x80) == 0) {
      FUN_80107bf4(obj,&g_player,6);
    }
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801d94f0 FUN_801d94f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d94f0(MM8Obj *obj)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if ((obj->var & 0x40) == 0) {
    iVar7 = (ushort)obj->x - 0x1c;
  }
  else {
    iVar7 = (ushort)obj->x + 0x1c;
  }
  iVar6 = (ushort)obj->y - 0x18;
  uVar1 = Rand();
  uVar1 = uVar1 & 7;
  iVar2 = obj->speed_x;
  iVar3 = *(int *)&obj->field_0x50;
  if (iVar2 == iVar3) {
    obj->field_0x57 = 2;
    if ((uVar1 == 0) && (obj->field_0x58 == '\0')) {
      FUN_801091a4((int)(short)iVar7,iVar6 * 0x10000 >> 0x10,2);
    }
    FUN_80104d00(obj);
    return;
  }
                    /* Possible PsyQ macro: setPolyF4() */
  if ((obj->var & 0x40) == 0) {
    iVar2 = -iVar2;
    iVar3 = -iVar3;
  }
  sVar4 = (short)iVar6;
  if (iVar2 < iVar3 + -0x1000) {
    iVar2 = 0x1000;
    if ((obj->var & 0x40) == 0) {
      iVar2 = -0x1000;
    }
    obj->accel_x = iVar2;
    if ((obj->field_0x57 != '\0') &&
       (iVar2 = FUN_8012c108(obj,&obj->field_0x57,0,0,0,4), iVar2 != 0)) {
                    /* Probable PsyQ macro: setTile() */
      *(undefined1 *)(iVar2 + 7) = 0x60;
      *(byte *)(iVar2 + 0x26) = obj->draw_list - 1;
      obj->field_0x57 = 0;
    }
    if (obj->field_0x58 != '\0') goto LAB_801d9704;
    if (uVar1 < 2) {
      FUN_801091a4((int)((iVar7 + uVar1 + -6) * 0x10000) >> 0x10,(int)sVar4,3);
    }
    if (uVar1 < 6) goto LAB_801d9704;
    iVar7 = (int)(((iVar7 - uVar1) + 6) * 0x10000) >> 0x10;
    uVar5 = 3;
  }
  else {
    if (iVar3 + -0x1000 < iVar2) {
      if ((obj->var & 0x40) == 0) {
        obj->accel_x = 0x1000;
      }
      else {
        obj->accel_x = -0x1000;
      }
      goto LAB_801d9704;
    }
    obj->accel_x = 0;
    obj->speed_x = *(int *)&obj->field_0x50;
    if ((uVar1 != 0) || (obj->field_0x58 != '\0')) goto LAB_801d9704;
    iVar7 = (int)(short)iVar7;
    uVar5 = 2;
  }
  FUN_801091a4(iVar7,(int)sVar4,uVar5);
LAB_801d9704:
  FUN_80104c9c(obj);
  return;
}


// ---- 801d9730 FUN_801d9730

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9730(MM8Obj *obj)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if ((obj->var & 0x40) == 0) {
    iVar3 = (ushort)obj->x - 0x1c;
  }
  else {
    iVar3 = (ushort)obj->x + 0x1c;
  }
  iVar4 = (ushort)obj->y - 0x18;
  uVar2 = Rand();
  uVar2 = uVar2 & 7;
  if (obj->field_0x58 == '\0') {
    if (uVar2 < 2) {
      FUN_801091a4((int)((iVar3 + uVar2 + -6) * 0x10000) >> 0x10,iVar4 * 0x10000 >> 0x10,4);
    }
    if (5 < uVar2) {
      FUN_801091a4((int)(((iVar3 - uVar2) + 6) * 0x10000) >> 0x10,iVar4 * 0x10000 >> 0x10,4);
    }
  }
  if (obj->field_0x57 != '\0') {
    iVar3 = FUN_8012c108(obj,&obj->field_0x57,0,0,0,4);
    if (iVar3 != 0) {
                    /* Probable PsyQ macro: setTile() */
      *(undefined1 *)(iVar3 + 7) = 0x60;
      *(byte *)(iVar3 + 0x26) = obj->draw_list - 1;
      obj->field_0x57 = 0;
    }
  }
  sVar1 = *(short *)&obj->field_0x54;
  *(short *)&obj->field_0x54 = sVar1 + -1;
  if (sVar1 == 1) {
    obj->sub2 = 0;
    if ((obj->var & 0x40) == 0) {
      iVar3 = 0x1000;
    }
    else {
      iVar3 = -0x1000;
    }
    obj->accel_x = iVar3;
    obj->field_0x57 = 2;
  }
  else {
                    /* Possible PsyQ macro: setTile8() */
    if ((obj->var & 0x40) == 0) {
      iVar3 = -obj->speed_x;
      iVar4 = -*(int *)&obj->field_0x50;
    }
    else {
      iVar3 = obj->speed_x;
      iVar4 = *(int *)&obj->field_0x50;
    }
    if (iVar3 < iVar4 + 0x10000) {
      FUN_80104c9c(obj);
    }
    else {
      FUN_80104d00(obj);
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801d9914 FUN_801d9914

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9914(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8538)[obj->sub2])();
  return;
}


// ---- 801d9950 FUN_801d9950

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Possible GS_106.OBJ/GsSetProjection
   Possible _OP_VDEL.OBJ/__builtin_vec_delete
   Possible _OP_VNEW.OBJ/__builtin_vec_new
   Possible SCNOFF.OBJ/SsSetNoiseOff
   Possible SSQUIT.OBJ/SsQuit */

void FUN_801d9950(MM8Obj *obj)

{
  Obj_Free();
  return;
}


// ---- 801d9970 FUN_801d9970

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9970(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8540)[obj->sub3])();
  return;
}


// ---- 801d99ac FUN_801d99ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d99ac(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = obj->field_0x54 + -1;
  obj->field_0x54 = cVar1;
  if (cVar1 == '\0') {
    if (obj->anim_extra == 1) {
      obj->speed_y_up = 0x8000;
      obj->field_0x54 = 10;
      obj->speed_x = 0;
      obj->field_0x56 = 0;
      obj->draw_list = 9;
      obj->sub3 = obj->sub3 + 1;
    }
    else {
      obj->field_0x54 = 8;
      FUN_80104c34(obj);
      Anim_Step(obj);
    }
  }
  return;
}


// ---- 801d9a40 FUN_801d9a40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9a40(MM8Obj *obj)

{
  char cVar1;
  
  cVar1 = obj->field_0x54 + -1;
  obj->field_0x54 = cVar1;
  if (cVar1 == '\0') {
    obj->field_0x54 = 10;
    if ((byte)obj->field_0x56 < 2) {
      obj->clut = obj->clut + 3;
    }
    obj->field_0x56 = obj->field_0x56 + '\x01';
    if (3 < (byte)obj->field_0x56) {
      Obj_Free();
      return;
    }
  }
  FUN_80104d18();
  return;
}


// ---- 801d9ad4 FUN_801d9ad4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ad4(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  cVar1 = Obj_InActiveArea();
  if (cVar1 != '\0') {
    uVar2 = Rand();
    FUN_80108ed8(obj,0,(int)(((uVar2 & 0x1f) - 0x10) * 0x10000) >> 0x10);
    uVar2 = Rand();
    uVar3 = Rand();
    FUN_80108ed8(obj,uVar2 & 0xf | 0x10,(int)(((uVar3 & 0x1f) - 0x10) * 0x10000) >> 0x10);
    uVar2 = Rand();
    uVar3 = Rand();
    FUN_80108ed8(obj,(int)((-0x10 - (uVar2 & 0xf)) * 0x10000) >> 0x10,
                 (int)(((uVar3 & 0x1f) - 0x10) * 0x10000) >> 0x10);
    FUN_8012a5fc(obj,0);
    FUN_8012ae08(obj,0x18);
    FUN_801091a4((int)obj->x,(int)(((ushort)obj->y - 0x10) * 0x10000) >> 0x10,2);
  }
  Obj_Free(obj);
  return;
}


// ---- 801d9bdc FUN_801d9bdc

uint FUN_801d9bdc(int param_1,undefined4 param_2,int param_3,short *param_4)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  
  bVar1 = *(byte *)(param_1 + 7);
  if ((bVar1 & 0x20) == 0) {
    param_3 = 3;
    if ((bVar1 & 0x40) == 0) {
      param_4 = (short *)&UNK_801e8504;
    }
    else {
      param_4 = (short *)&UNK_801e84fc;
    }
  }
  else {
    iVar3 = 0;
    if ((bVar1 & 0x40) != 0) {
      param_4 = (short *)&UNK_801e850c;
      param_3 = 3;
    }
    if (0 < param_3) {
      psVar4 = param_4;
      do {
        sVar2 = *psVar4;
        psVar4 = psVar4 + 1;
        if ((ushort)(sVar2 - *(short *)(param_1 + 0xe)) < 0x40) {
          *(undefined1 *)(param_1 + 0x58) = 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_3);
    }
  }
  iVar3 = 0;
  if (0 < param_3) {
    do {
      if ((ushort)(*(short *)(param_1 + 0xe) - *param_4) < 4) {
        return iVar3 + 1U & 0xff;
      }
      iVar3 = iVar3 + 1;
      param_4 = param_4 + 1;
    } while (iVar3 < param_3);
  }
  return 0;
}


// ---- 801d9cc8 FUN_801d9cc8

undefined4 FUN_801d9cc8(char *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  
  pcVar3 = &g_main_pool;
  puVar2 = &DAT_8015b176;
  do {
    if ((((*pcVar3 != '\0') && (pcVar3 != param_1)) && (puVar2[4] == '\x0f')) &&
       (iVar1 = Obj_HitboxOverlap(pcVar3,param_1), iVar1 != 0)) {
      if (puVar2[0x23] != param_1[0x25]) {
        return 1;
      }
      if (param_1[1] == '\x02') {
        if (puVar2[-1] == '\x02') {
          if (*(short *)(puVar2 + 0xc) <= *(short *)(param_1 + 0xe)) {
            return 0;
          }
          iVar1 = *(int *)(puVar2 + 0x12);
          *(undefined4 *)(puVar2 + 0x12) = *(undefined4 *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar1;
          if (iVar1 < *(int *)(puVar2 + 0x12)) {
            *puVar2 = 1;
            *(undefined2 *)(puVar2 + 0x52) = 0x3c;
            param_1[2] = '\0';
            return 0;
          }
          *puVar2 = 0;
          param_1[2] = '\x01';
          param_1[0x54] = '<';
          param_1[0x55] = '\0';
          return 0;
        }
      }
      else if ((param_1[0x26] != '\t') && (puVar2[-1] == '\x02')) {
        return 1;
      }
    }
    pcVar3 = pcVar3 + 0x60;
    puVar2 = puVar2 + 0x60;
    if (&DAT_8015c974 <= pcVar3) {
      return 0;
    }
  } while( true );
}


