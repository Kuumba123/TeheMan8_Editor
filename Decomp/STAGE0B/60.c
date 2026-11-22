// ID 60, STAGE0B.BIN, handler 0x801E4158. Ghidra output with the object struct applied; not matching C.
// ---- 801e4158 FUN_801e4158

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4158(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e8754)[obj->state])();
  if (obj->active != 0) {
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      Obj_Free(obj);
    }
    else {
      Obj_CullAndQueueDrawMargin(obj,0x20);
    }
  }
  return;
}


// ---- 801e41dc FUN_801e41dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e41dc(MM8Obj *obj)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  Enemy_InitFromTable();
  switch(obj->var) {
  case 0:
  case 1:
    obj->draw_list = 5;
    obj->contact_dmg = 4;
    obj->state = 1;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->flip = 0;
    obj->dmg_table = 0;
    obj->hp = 1;
    obj->hitbox = &UNK_801e8724 + (uint)obj->var * 4;
    if (obj->var == 0) {
      Anim_Set(obj,0x18);
      puVar1 = (undefined1 *)FUN_801055e4(obj);
      if (puVar1 == (undefined1 *)0x0) {
        return;
      }
      *puVar1 = 1;
                    /* Possible PsyQ macro: setTile16() + setSemiTrans(tile16, 1) */
      puVar1[6] = 0x60;
      puVar1[7] = 1;
      puVar1[0x55] = obj->field_0x55;
      *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)&obj->x_frac;
      *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)&obj->y_frac;
      *(short *)(puVar1 + 0xe) = *(short *)(puVar1 + 0xe) + -0x100;
      *(undefined4 *)(puVar1 + 0x4c) = *(undefined4 *)&obj->field_0x4c;
      return;
    }
    uVar3 = 7;
    break;
  case 2:
    obj->state = 2;
    obj->dmg_table = 0x26;
    obj->hp = 4;
    obj->draw_list = 5;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->flip = 0;
    obj->contact_dmg = 5;
    obj->x_frac = 0;
    obj->x = 0;
    obj->y_frac = 0;
    obj->y = 0;
    obj->hitbox = &UNK_801e8724 + (uint)obj->var * 4;
    obj->x = DAT_801d2918._2_2_ + 0x160;
    obj->y = g_cam_y;
    uVar2 = Rand();
    uVar3 = 0xb;
    obj->y = obj->y + (ushort)(byte)(&DAT_801e8738)[uVar2 & 0xf] * 0x20;
    break;
  case 3:
    uVar3 = 9;
    obj->draw_list = 8;
    obj->state = 3;
    obj->dmg_table = 0x26;
    obj->hp = 2;
    obj->contact_dmg = 4;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->flip = 0;
    obj->hitbox = &UNK_801e8724 + (uint)obj->var * 4;
    break;
  case 4:
    uVar3 = 10;
    obj->draw_list = 8;
    obj->dmg_table = 0x26;
    obj->hp = 2;
    obj->state = 4;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->contact_dmg = 4;
    obj->hitbox = &UNK_801e8724 + (uint)obj->var * 4;
    break;
  default:
    goto switchD_801e4218_default;
  }
  Anim_Set(obj,uVar3);
switchD_801e4218_default:
  return;
}


// ---- 801e4450 FUN_801e4450

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4450(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_801e4cf8();
  if (iVar2 == 0) {
    if ((*(byte *)(*(int *)&obj->field_0x4c + 7) & 0x80) == 0) {
      bVar1 = DAT_801b29a3 & 0x20;
    }
    else {
      bVar1 = DAT_801b29a3 & 2;
    }
    if (bVar1 != 0) {
      FUN_801e4d98(obj);
      (*(code *)(&PTR_FUN_801e8768)[obj->sub2])(obj);
      if (obj->active == 0) {
        return;
      }
      obj->x = obj->x + DAT_801d293a;
      return;
    }
  }
  Obj_Free(obj);
  return;
}


// ---- 801e4528 FUN_801e4528

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4528(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x50 = 0x78;
  }
  else {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      Obj_Free(obj);
      return;
    }
  }
  Anim_Step(obj);
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801e45a8 FUN_801e45a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e45a8(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_LAB_801e8774)[obj->sub2])();
  if ((DAT_801b29a3 & 0x88) == 0x88) {
    FUN_80108e84(obj);
  }
  else {
    cVar1 = Enemy_ContactDamage(obj);
    if (cVar1 == '\x02') {
      FUN_80108e84(obj);
    }
    else {
      cVar1 = Enemy_CheckWeaponHits(obj);
      obj->clut = (&DAT_80159f64)[obj->bank];
      if (cVar1 == '\x02') {
        obj->clut = 0;
        return;
      }
      if (cVar1 != '\x04') {
        return;
      }
      FUN_80108e84(obj);
      FUN_80108fd8(obj,0);
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
    }
  }
  FUN_8012ae08(obj,0x36);
  Obj_Free(obj);
  return;
}


// ---- 801e4794 FUN_801e4794

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4794(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e8780)[obj->sub2])();
  obj->x = obj->x + DAT_801d293a;
                    /* Possible PsyQ macro: setPolyGT3() */
  if (((DAT_801b29a3 & 0x88) != 0x88) && (cVar1 = Enemy_ContactDamage(obj), cVar1 != '\x02')) {
    cVar1 = Enemy_CheckWeaponHits(obj);
    obj->clut = (&DAT_80159f64)[obj->bank];
    if (cVar1 == '\x02') {
      obj->clut = 0;
      return;
    }
    if (cVar1 != '\x04') {
      return;
    }
  }
  FUN_80108e84(obj);
  FUN_8012a5fc(obj,0);
  Obj_Free(obj);
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
  return;
}


// ---- 801e4884 FUN_801e4884

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4884(MM8Obj *obj)

{
  undefined1 uVar1;
  
  FUN_801091a4(obj->x + 0x10,(int)obj->y,1);
  obj->sub2 = 1;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->field_0x51 = 0xc0;
  if ((byte)(DAT_801b29a5 + DAT_801b29a6) < 0x29) {
    *(undefined2 *)&obj->field_0x52 = 0x500;
    uVar1 = 0x14;
  }
  else {
    *(undefined2 *)&obj->field_0x52 = 0x400;
    uVar1 = 0x28;
  }
  obj->field_0x54 = uVar1;
  FUN_80105120(obj,(int)*(short *)&obj->field_0x52,obj->field_0x51);
  obj->field_0x50 = obj->field_0x54;
  Anim_Step();
  return;
}


// ---- 801e4938 FUN_801e4938

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4938(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  FUN_80104c34();
  cVar1 = obj->field_0x50;
  obj->field_0x50 = cVar1 + -1;
  if (cVar1 == '\0') {
    iVar3 = FUN_801050e4(obj,&g_player);
    bVar2 = obj->field_0x51;
    iVar3 = (int)(((iVar3 + 8U & 0xfffffff0) - (uint)bVar2) * 0x1000000) >> 0x18;
    if (iVar3 < 1) {
      if ((iVar3 < 0) && (0xa0 < (byte)obj->field_0x51)) {
        obj->field_0x51 = bVar2 - 0x10;
        obj->flip = 0x80;
      }
    }
    else if ((byte)obj->field_0x51 < 0xe0) {
      obj->field_0x51 = bVar2 + 0x10;
      obj->flip = 0;
    }
    FUN_80105120(obj,(int)*(short *)&obj->field_0x52,obj->field_0x51);
    obj->field_0x50 = obj->field_0x54;
  }
  Anim_Step(obj);
  return;
}


// ---- 801e4a1c FUN_801e4a1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4a1c(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e878c)[obj->sub2])();
  obj->x = obj->x + DAT_801d293a;
  if ((DAT_801b29a3 & 0x88) == 0x88) {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
  }
  else {
    cVar1 = Enemy_ContactDamage(obj);
    if (cVar1 == '\x02') {
      FUN_80108e84(obj);
      FUN_8012a5fc(obj,0);
    }
    else {
      cVar1 = Enemy_CheckWeaponHits(obj);
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
      obj->clut = (&DAT_80159f64)[obj->bank];
      if (cVar1 == '\x02') {
        obj->clut = 0;
        return;
      }
      if (cVar1 != '\x04') {
        return;
      }
      FUN_80108e84(obj);
    }
  }
  Obj_Free(obj);
  return;
}


// ---- 801e4b38 FUN_801e4b38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4b38(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
  obj->sub2 = 1;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  if ((obj->flip & 0x80) == 0) {
    sVar1 = obj->x;
    obj->field_0x51 = 0;
    iVar2 = obj->y + 0x10;
  }
  else {
    sVar1 = obj->x;
    obj->field_0x51 = 0x80;
    iVar2 = obj->y + -0x10;
  }
  FUN_801091a4((int)sVar1,iVar2,1);
  if ((byte)(DAT_801b29a5 + DAT_801b29a6) < 0x29) {
    *(undefined2 *)&obj->field_0x52 = 0x400;
    obj->field_0x54 = (&DAT_801e8748)[(byte)obj->field_0x55];
  }
  else {
    *(undefined2 *)&obj->field_0x52 = 0x400;
    obj->field_0x54 = 0;
  }
  FUN_80105120(obj,(int)*(short *)&obj->field_0x52,obj->field_0x51);
  obj->field_0x50 = obj->field_0x54;
  Anim_Step();
  return;
}


// ---- 801e4c24 FUN_801e4c24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4c24(MM8Obj *obj)

{
  char cVar1;
  
  if ((obj->field_0x54 != '\0') &&
     (cVar1 = obj->field_0x50, obj->field_0x50 = cVar1 + -1, cVar1 == '\0')) {
    FUN_801091a4((int)obj->x,(int)obj->y,1);
    obj->field_0x51 = 0xc0;
    obj->flip = 0;
    FUN_80105120(obj,(int)*(short *)&obj->field_0x52,obj->field_0x51);
    FUN_8010544c(obj,0xc);
    Anim_Set(obj,9);
    obj->sub2 = 2;
  }
  FUN_80104c34(obj);
  Anim_Step(obj);
  return;
}


// ---- 801e4cc8 FUN_801e4cc8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4cc8(MM8Obj *obj)

{
  FUN_80104c34();
  Anim_Step(obj);
  return;
}


// ---- 801e4cf8 FUN_801e4cf8

undefined4 FUN_801e4cf8(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(param_1 + 0x4c);
  if (*pcVar3 != '\0') {
    if (pcVar3[6] != 'Y') {
      return 1;
    }
    if ((pcVar3[7] & 0xfU) == 1) {
      pbVar2 = &DAT_801b29a3;
    }
    else {
      if ((pcVar3[7] & 0xfU) != 2) {
        return 1;
      }
      pbVar2 = &DAT_801b29a4;
    }
    if ((pcVar3[7] & 0x80U) == 0) {
      bVar1 = *pbVar2 & 0x80;
    }
    else {
      bVar1 = *pbVar2 & 8;
    }
    if (bVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ---- 801e4d98 FUN_801e4d98

void FUN_801e4d98(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
  sVar1 = (short)(char)(&DAT_801e874c)[(uint)*(byte *)(param_1 + 0x55) * 2] +
          *(short *)(param_1 + 0xe);
  *(short *)(param_1 + 0xe) = sVar1;
  if ((*(byte *)(param_1 + 7) & 1) != 0) {
    *(short *)(param_1 + 0xe) = sVar1 + -0x100;
  }
  *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + -4;
  if ((*(byte *)(iVar2 + 7) & 0x80) == 0) {
    *(short *)(param_1 + 0x12) =
         (short)(char)(&DAT_801e874d)[(uint)*(byte *)(param_1 + 0x55) * 2] +
         *(short *)(param_1 + 0x12);
  }
  else {
    *(short *)(param_1 + 0x12) =
         *(short *)(param_1 + 0x12) -
         (short)(char)(&DAT_801e874d)[(uint)*(byte *)(param_1 + 0x55) * 2];
  }
  return;
}


