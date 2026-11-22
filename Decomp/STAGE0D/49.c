// ID 49, STAGE0D.BIN, handler 0x801ED0D8. Ghidra output with the object struct applied; not matching C.
// ---- 801ed0d8 FUN_801ed0d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed0d8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8c84)[obj->state])();
  return;
}


// ---- 801ed114 FUN_801ed114

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed114(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  iVar1 = (uint)obj->var * 8;
  obj->dmg_table = (&DAT_801f8bfd)[iVar1];
  obj->contact_dmg = (&DAT_801f8bfe)[iVar1];
  obj->hp = (&DAT_801f8bff)[iVar1];
  obj->draw_list = (&DAT_801f8c00)[iVar1];
  obj->hitbox = &UNK_801f8c5c + (uint)(byte)(&DAT_801f8c01)[iVar1] * 4;
  obj->box2 = &UNK_801f8c70 + (uint)(byte)(&DAT_801f8c02)[iVar1] * 5;
  (*(code *)(&PTR_FUN_801f8cb4)[obj->var])(obj);
  obj->state = (&DAT_801f8bfc)[iVar1];
  return;
}


// ---- 801ed1e8 FUN_801ed1e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed1e8(MM8Obj *obj)

{
  obj->field_0x53 = 0;
  obj->invuln = 1;
  Anim_Set(obj,obj->var);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801ed228 FUN_801ed228

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed228(MM8Obj *obj)

{
  obj->speed_y_up = -0x60000;
  obj->speed_x = 0;
  obj->gravity = 0;
  obj->field_0x50 = 2;
  Anim_Set(obj,0xb);
  return;
}


// ---- 801ed260 FUN_801ed260

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed260(MM8Obj *obj)

{
  undefined1 uVar1;
  
  *(ushort *)&obj->field_0x54 = DAT_801d2928 + (ushort)(byte)obj->field_0x51 * 0x40 + 0x48;
  *(short *)&obj->field_0x56 = DAT_801d292a + 0x30;
  if ((obj->flip & 0x40) == 0) {
    uVar1 = 0xc0;
  }
  else {
    uVar1 = 0x40;
  }
  obj->field_0x52 = uVar1;
  obj->accel_x = 0x400;
  FUN_801ed4e4(obj,(int)(short)obj->accel_x);
  obj->field_0x59 = obj->clut + 5;
  FUN_801ee688(obj,obj->field_0x52);
  return;
}


// ---- 801ed2f8 FUN_801ed2f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed2f8(MM8Obj *obj)

{
  undefined1 uVar1;
  
  if (*(char *)(*(int *)&obj->field_0x4c + 0x57) == '\0') {
    uVar1 = 1;
    if ((obj->flip & 0x40) != 0) {
      uVar1 = 0x1e;
    }
  }
  else {
    uVar1 = 0x1e;
    if ((obj->flip & 0x40) != 0) {
      uVar1 = 1;
    }
  }
  obj->field_0x50 = uVar1;
  Anim_Set(obj,0x1c);
  return;
}


// ---- 801ed368 FUN_801ed368

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed368(MM8Obj *obj)

{
  undefined1 uVar1;
  
  FUN_801ed4e4(obj,0);
  obj->field_0x59 = obj->clut + 5;
  *(ushort *)&obj->field_0x56 = (ushort)(byte)(&DAT_801f8c80)[(byte)obj->field_0x51] + DAT_801d292a;
  if ((obj->flip & 0x40) == 0) {
    obj->speed_x = -0x40000;
    uVar1 = 0xc0;
  }
  else {
    obj->speed_x = 0x60000;
    uVar1 = 0x40;
  }
  obj->field_0x52 = uVar1;
  obj->speed_y_up = 0;
  FUN_801ee688(obj,obj->field_0x52);
  return;
}


// ---- 801ed3fc FUN_801ed3fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed3fc(MM8Obj *obj)

{
  FUN_8010910c();
  obj->invuln = 1;
  obj->field_0x50 = 0x78;
  obj->y = DAT_801d292a + 0xb4;
  Anim_Set(obj,0x18);
  return;
}


// ---- 801ed450 FUN_801ed450

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed450(MM8Obj *obj)

{
  char cVar1;
  
  if ((obj->flip & 0x40) == 0) {
    cVar1 = obj->field_0x51 * -8 + -0x20;
  }
  else {
    cVar1 = obj->field_0x51 * '\b' + ' ';
  }
  obj->field_0x52 = cVar1;
  obj->field_0x58 = 0x14;
  obj->field_0x53 = 0xb4;
  obj->field_0x50 = 8;
  FUN_801ed4e4(obj,0x380);
  obj->field_0x59 = obj->clut + 4;
  return;
}


// ---- 801ed4e4 FUN_801ed4e4

void FUN_801ed4e4(int param_1,undefined2 param_2)

{
  *(undefined1 *)(param_1 + 0x27) = 9;
  *(undefined2 *)(param_1 + 0x2c) = DAT_8017035a;
  FUN_80105120(param_1,param_2,*(undefined1 *)(param_1 + 0x52));
  FUN_8010544c(param_1,0xc);
  return;
}


// ---- 801ed534 FUN_801ed534

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed534(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = -0x80000;
  if ((obj->flip & 0x40) != 0) {
    iVar1 = 0x80000;
  }
  obj->speed_x = iVar1;
  obj->speed_y_up = -0xc000;
  Anim_Set(obj,0x1a);
  return;
}


// ---- 801ed57c FUN_801ed57c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed57c(MM8Obj *obj)

{
  obj->field_0x50 = 0x14;
  FUN_801ed4e4(obj,0x380);
  obj->clut = obj->clut + 4;
  return;
}


// ---- 801ed5c0 FUN_801ed5c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed5c0(MM8Obj *obj)

{
  obj->invuln = 1;
  Anim_Set(obj,9);
  return;
}


// ---- 801ed5e8 FUN_801ed5e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed5e8(MM8Obj *obj)

{
  undefined4 uVar1;
  char *pcVar2;
  byte *pbVar3;
  
  pcVar2 = *(char **)&obj->field_0x4c;
  if ((*pcVar2 == '\0') || (pcVar2[6] != 'H')) {
    Obj_Free(obj);
    return;
  }
  obj->clut = pcVar2[0x24];
  uVar1 = *(undefined4 *)(pcVar2 + 0xc);
  obj->x_frac = (short)uVar1;
  obj->x = (short)((uint)uVar1 >> 0x10);
  uVar1 = *(undefined4 *)(pcVar2 + 0x10);
  obj->y_frac = (short)uVar1;
  obj->y = (short)((uint)uVar1 >> 0x10);
  obj->flip = pcVar2[0x25];
  if (obj->var == 0) {
    pbVar3 = (byte *)(pcVar2 + 0x5e);
  }
  else {
    pbVar3 = (byte *)(pcVar2 + 0x5f);
  }
  if (*pbVar3 == 0xff) {
    Anim_Step(obj);
    goto LAB_801ed6dc;
  }
  if (*pbVar3 < 0x80) {
    Anim_Set(obj);
    obj->field_0x53 = 0;
  }
  else {
    if ((*pbVar3 & 0xf) != 0) {
      if ((*pbVar3 & 0xf) != 1) goto LAB_801ed6cc;
      obj->draw_list = 7;
    }
    obj->field_0x53 = 1;
  }
LAB_801ed6cc:
  *pbVar3 = 0xff;
LAB_801ed6dc:
  if ((pcVar2[5] != '\0') && (obj->field_0x53 == '\0')) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801ed720 FUN_801ed720

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ed720(MM8Obj *obj)

{
  Anim_Step();
  if (obj->sub2 == 0) {
    FUN_801ed788(obj);
  }
  else {
    FUN_801ed92c(obj);
  }
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801ed788 FUN_801ed788

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801ed788(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x4c);
  if (*(char *)(param_1 + 3) == '\0') {
    FUN_80104ccc();
    FUN_80106214(param_1);
    if (((*(byte *)(param_1 + 0x33) & 0x80) != 0) && (*(int *)(param_1 + 0x18) < 0)) {
      cVar1 = *(char *)(param_1 + 0x50) + -1;
      *(char *)(param_1 + 0x50) = cVar1;
      if (cVar1 == '\0') {
        Anim_Set(param_1,0xc);
        *(undefined1 *)(param_1 + 3) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x18) = 0x2e000;
        *(undefined4 *)(param_1 + 0x20) = 0x4000;
      }
    }
    if (((int)*(short *)(param_1 + 0x12) < DAT_801d292a + 0x20) && ((_DAT_80170574 & 2) != 0)) {
      uVar2 = Rand();
      uVar3 = Rand();
      FUN_801eee4c(param_1,uVar2 & 0xf,uVar3 & 3,2);
    }
  }
  uVar2 = 0;
  if ((*(byte *)(iVar4 + 0x52) & 0x80) == 0) {
    if ((*(char *)(iVar4 + 0x52) == '\0') && (iVar4 = Enemy_CheckWeaponHits(param_1), iVar4 != 0)) {
      Anim_Set(param_1,0x20);
      *(undefined1 *)(param_1 + 2) = 1;
    }
  }
  else {
    do {
      uVar2 = uVar2 + 1;
      uVar3 = Rand();
      FUN_801eee4c(param_1,(int)(((uVar3 & 0x1f) - 0xf) * 0x1000000) >> 0x18,0xffffffe0,2);
    } while (uVar2 < 4);
    FUN_8012ae08(param_1,0x2e);
    Obj_Free(param_1);
  }
  return;
}


// ---- 801ed92c FUN_801ed92c

void FUN_801ed92c(int param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  int unaff_s2;
  
  if ((*(short *)(param_1 + 0x2e) < 0) && (*(char *)(param_1 + 0x31) == '\x01')) {
    puVar1 = (undefined1 *)Obj_AllocMain();
    uVar3 = 0;
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 1;
      puVar1[6] = 0x49;
      puVar1[7] = 6;
      *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    }
    do {
      uVar3 = uVar3 + 1;
      uVar2 = Rand();
      FUN_801eee4c(param_1,(int)(((uVar2 & 0x1f) - 0xf) * 0x1000000) >> 0x18,0xfffffff0,3);
    } while (uVar3 < 4);
    uVar3 = 0;
    do {
      FUN_801eee4c(param_1,0,0,4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < 6);
    *(undefined1 *)(unaff_s2 + 0x52) = 2;
    Obj_Free(param_1);
  }
  return;
}


// ---- 801eda2c FUN_801eda2c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eda2c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    FUN_801edb18(obj);
  }
  else if (obj->sub2 == 1) {
    FUN_801edbac(obj);
  }
  FUN_80105120(obj,(short)obj->accel_x,obj->field_0x52);
  FUN_80104c34(obj);
  if (_DAT_80170574 == (_DAT_80170574 / 3) * 3) {
    FUN_801091a4((int)obj->x,(int)obj->y,0);
  }
  FUN_801ee688(obj,obj->field_0x52);
  iVar1 = FUN_801ee5f8(obj);
  if (iVar1 == 0) {
    Obj_CullAndQueueDraw(obj);
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801edb18 FUN_801edb18

void FUN_801edb18(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_80104db0((int)*(short *)(param_1 + 0xe),(int)*(short *)(param_1 + 0x12),
                       (int)*(short *)(param_1 + 0x54),(int)*(short *)(param_1 + 0x56));
  uVar3 = (uint)*(byte *)(param_1 + 0x52) - iVar2;
  if ((uVar3 & 0xff) != 0) {
    cVar1 = *(char *)(param_1 + 0x52) + -0x10;
    if ((int)(uVar3 * 0x1000000) < 1) {
      cVar1 = *(char *)(param_1 + 0x52) + '\x10';
    }
    *(char *)(param_1 + 0x52) = cVar1;
  }
  iVar2 = (int)*(short *)(param_1 + 0xe) - (int)*(short *)(param_1 + 0x54);
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (iVar2 < 8) {
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return;
}


// ---- 801edbac FUN_801edbac

void FUN_801edbac(int param_1)

{
  char cVar1;
  
  cVar1 = -0x70;
  if (*(char *)(param_1 + 0x52) != -0x80) {
    cVar1 = *(char *)(param_1 + 0x52) + -0x10;
  }
  *(char *)(param_1 + 0x52) = cVar1;
  if (*(char *)(param_1 + 0x52) == -0x80) {
    *(undefined1 *)(param_1 + 2) = 2;
  }
  return;
}


// ---- 801edbe0 FUN_801edbe0

void FUN_801edbe0(undefined4 param_1)

{
  FUN_80108e84();
  Obj_Free(param_1);
  return;
}


// ---- 801edc10 FUN_801edc10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801edc10(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8ce4)[obj->sub2])();
  if (obj->active != 0) {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801edc78 FUN_801edc78

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801edc78(MM8Obj *obj)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->field_0x4c;
  if (obj->sub3 == 0) {
    if ((short)obj->frame < 0) {
      Anim_Set(obj,0x1d);
      FUN_8010544c(obj,0x15e);
      obj->sub3 = 1;
    }
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x52 = 0;
      FUN_80105120(obj,0x500,0);
      obj->sub2 = 1;
      obj->sub3 = 0;
    }
  }
  if (((pcVar2[0x56] & 0x80U) != 0) || (*pcVar2 == '\0')) {
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801edd4c FUN_801edd4c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801edd4c(MM8Obj *obj)

{
  undefined2 uVar1;
  char cVar2;
  
  FUN_80104c34();
  cVar2 = obj->field_0x52 + '\x10';
  if ((obj->flip & 0x40) == 0) {
    cVar2 = obj->field_0x52 + -0x10;
  }
  obj->field_0x52 = cVar2;
  FUN_80105120(obj,0x600,obj->field_0x52);
  if (obj->field_0x52 == '\0') {
    *(undefined2 *)&obj->field_0x54 = DAT_8015e248._2_2_;
    uVar1 = DAT_8015e24c._2_2_;
    obj->sub2 = 2;
    obj->sub3 = 0;
    *(undefined2 *)&obj->field_0x56 = uVar1;
  }
  FUN_801ee12c(obj);
  return;
}


// ---- 801edde0 FUN_801edde0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801edde0(MM8Obj *obj)

{
  code *pcVar1;
  
  if ((obj->flip & 0x40) == *(byte *)(*(int *)&obj->field_0x4c + 0x57)) {
    pcVar1 = (code *)(&PTR_FUN_801f8cf8)[obj->sub3];
  }
  else {
    pcVar1 = (code *)(&PTR_FUN_801f8d04)[obj->sub3];
  }
  (*pcVar1)(obj);
  FUN_801ee12c(obj);
  return;
}


// ---- 801ede68 FUN_801ede68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ede68(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = 0x50000;
  obj->speed_x = 0;
  if (obj->y < *(short *)&obj->field_0x56) {
    iVar1 = -0x50000;
  }
  obj->speed_y_up = iVar1;
  FUN_80104c34(obj);
  iVar1 = (int)obj->y - (int)*(short *)&obj->field_0x56;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 6) {
    obj->y = *(short *)&obj->field_0x56;
    obj->field_0x4 = 0;
    obj->sub3 = obj->sub3 + 1;
  }
  return;
}


// ---- 801edef0 FUN_801edef0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801edef0(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = -0x50000;
  if (obj->x < *(short *)&obj->field_0x54) {
    iVar1 = 0x50000;
  }
  obj->speed_x = iVar1;
  obj->speed_y_up = 0;
  FUN_80104c34(obj);
  iVar1 = (int)obj->x - (int)*(short *)&obj->field_0x54;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 6) {
    obj->x = *(short *)&obj->field_0x54;
    obj->field_0x4 = 0;
    obj->sub3 = obj->sub3 + 1;
  }
  return;
}


// ---- 801edfd0 FUN_801edfd0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801edfd0(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    Anim_Set(obj,0x1f);
    obj->sub3 = 1;
  }
  else if ((short)obj->frame < 0) {
    if (**(char **)&obj->field_0x4c != '\0') {
      (*(char **)&obj->field_0x4c)[0x56] = '\x04';
    }
    Obj_Free(obj);
  }
  return;
}


// ---- 801ee044 FUN_801ee044

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ee044(MM8Obj *obj)

{
  undefined2 uVar1;
  char cVar2;
  
  if (obj->sub3 == 0) {
    cVar2 = '\x01';
    if ((obj->flip & 0x40) != 0) {
      cVar2 = '\x02';
    }
    if (*(char *)(*(int *)&obj->field_0x4c + 0x56) == cVar2) {
      *(undefined2 *)&obj->field_0x54 = 0;
    }
    else {
      uVar1 = 0xffe8;
      if ((obj->flip & 0x40) != 0) {
        uVar1 = 0x18;
      }
      *(undefined2 *)&obj->field_0x54 = uVar1;
    }
    Anim_Set(obj,0x1e);
    FUN_8010544c(obj,0x15f);
    obj->sub3 = 1;
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      Obj_Free(obj);
      return;
    }
  }
  obj->x = DAT_8015e248._2_2_ + *(short *)&obj->field_0x54;
  obj->y = DAT_8015e24c._2_2_;
  return;
}


// ---- 801ee12c FUN_801ee12c

undefined4 FUN_801ee12c(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  char cVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)(param_1 + 0x4c);
  uVar2 = 3;
  if (((pcVar4[0x56] & 0x80U) == 0) && (*pcVar4 != '\0')) {
    iVar1 = Obj_HitboxOverlap(&g_player,param_1);
    if (iVar1 == 0) {
      if (pcVar4[0x56] == '\0') {
        return 0;
      }
    }
    else {
      if (pcVar4[0x56] != '\0') {
        return 0;
      }
      cVar3 = '\x01';
      if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
        cVar3 = '\x02';
      }
      pcVar4[0x56] = cVar3;
    }
    uVar2 = 4;
  }
  *(undefined1 *)(param_1 + 2) = uVar2;
  *(undefined1 *)(param_1 + 3) = 0;
  return 1;
}


// ---- 801ee1fc FUN_801ee1fc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ee1fc(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  FUN_80104c34();
  uVar3 = (uint)*(ushort *)&obj->field_0x56 - (uint)(ushort)obj->y;
  if ((uVar3 & 0xfc) != 0) {
    sVar1 = 4;
    if ((int)(uVar3 * 0x10000) < 1) {
      sVar1 = -4;
    }
    obj->y = obj->y + sVar1;
  }
  if (_DAT_80170574 == (_DAT_80170574 / 3) * 3) {
    FUN_801091a4((int)obj->x,(int)obj->y,0);
  }
  iVar2 = FUN_801ee5f8(obj);
  if (iVar2 == 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801ee2ac FUN_801ee2ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ee2ac(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->sub2 == 0) {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      iVar2 = FUN_801eeddc((int)obj->x,(int)obj->y,0,obj->draw_list);
      if (iVar2 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
        *(undefined1 *)(iVar2 + 0x27) = 0x34;
        *(undefined1 *)(iVar2 + 0x24) = DAT_80159f98;
        FUN_8010544c(obj,10);
      }
      FUN_8012a5fc(obj,2);
      FUN_8012ae08(obj,0x2f);
      obj->field_0x50 = 6;
      obj->sub2 = 1;
    }
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      Obj_Free(obj);
      return;
    }
    Enemy_ContactDamage(obj);
  }
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801ee3a0 FUN_801ee3a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ee3a0(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    FUN_801ee464(obj);
  }
  else if (obj->sub2 == 1) {
    FUN_801ee530(obj);
  }
  FUN_80104c34(obj);
  FUN_801ee688(obj,obj->field_0x52);
  if (_DAT_80170574 == (_DAT_80170574 / 3) * 3) {
    FUN_801091a4((int)obj->x,(int)obj->y,0);
  }
  iVar1 = FUN_801ee5f8(obj);
  if (iVar1 == 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801ee464 FUN_801ee464

void FUN_801ee464(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  cVar1 = *(char *)(param_1 + 0x50) + -1;
  *(char *)(param_1 + 0x50) = cVar1;
  if ((cVar1 == '\0') && (g_player != '\0')) {
    iVar2 = FUN_801050e4();
    uVar3 = (uint)*(byte *)(param_1 + 0x52) - iVar2;
    if ((uVar3 & 0xff) != 0) {
      cVar1 = *(char *)(param_1 + 0x52) + '\x10';
      if ((int)(uVar3 * 0x1000000) < 1) {
        cVar1 = *(char *)(param_1 + 0x52) + -0x10;
      }
      *(char *)(param_1 + 0x52) = cVar1;
    }
    FUN_80105120(param_1,0x380,*(undefined1 *)(param_1 + 0x52));
    *(undefined1 *)(param_1 + 0x50) = 8;
  }
  cVar1 = *(char *)(param_1 + 0x58) + -1;
  *(char *)(param_1 + 0x58) = cVar1;
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x50) = 1;
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 3) = 0;
  }
  return;
}


// ---- 801ee530 FUN_801ee530

void FUN_801ee530(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  cVar1 = *(char *)(param_1 + 0x50) + -1;
  *(char *)(param_1 + 0x50) = cVar1;
  if ((cVar1 == '\0') && (g_player != '\0')) {
    iVar2 = FUN_801050e4();
    uVar3 = (uint)*(byte *)(param_1 + 0x52) - iVar2;
    if ((uVar3 & 0xff) != 0) {
      cVar1 = *(char *)(param_1 + 0x52) + -0x10;
      if ((int)(uVar3 * 0x1000000) < 1) {
        cVar1 = *(char *)(param_1 + 0x52) + '\x10';
      }
      *(char *)(param_1 + 0x52) = cVar1;
    }
    FUN_80105120(param_1,0x380,*(undefined1 *)(param_1 + 0x52));
    *(undefined1 *)(param_1 + 0x50) = 8;
  }
  cVar1 = *(char *)(param_1 + 0x53) + -1;
  *(char *)(param_1 + 0x53) = cVar1;
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 2) = 2;
    *(undefined1 *)(param_1 + 3) = 0;
  }
  return;
}


// ---- 801ee5f8 FUN_801ee5f8

undefined4 FUN_801ee5f8(int param_1)

{
  int iVar1;
  
  FUN_80106214();
  if ((*(byte *)(param_1 + 0x33) & 0xf0) == 0) {
    iVar1 = Enemy_CheckWeaponHits(param_1);
    *(undefined1 *)(param_1 + 0x24) = *(undefined1 *)(param_1 + 0x59);
    if (iVar1 == 2) {
      *(undefined1 *)(param_1 + 0x24) = 0;
    }
    else if (iVar1 == 4) goto LAB_801ee668;
    iVar1 = Enemy_ContactDamage(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
LAB_801ee668:
  FUN_801edbe0(param_1);
  return 1;
}


// ---- 801ee688 FUN_801ee688

void FUN_801ee688(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff;
  *(byte *)(param_1 + 0x25) = (byte)((param_2 & 0x80 ^ 0x80) >> 1) | (char)param_2 + 0x40U & 0x80;
  if ((uVar1 + 0x40 & 0x40) == 0) {
    uVar1 = uVar1 >> 4 & 3;
  }
  else {
    uVar1 = 4 - (uVar1 >> 4 & 3);
  }
  Anim_Set(param_1,uVar1 + 0x2c & 0xff);
  return;
}


// ---- 801ee700 FUN_801ee700

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ee700(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    FUN_801ee740();
  }
  else {
    FUN_801ee820();
  }
  return;
}


// ---- 801ee740 FUN_801ee740

void FUN_801ee740(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  Anim_Step();
  FUN_80104c34(param_1);
  FUN_80106214(param_1);
  if ((*(byte *)(param_1 + 0x33) & 0x30) != 0) {
    *(int *)(param_1 + 0x14) = -*(int *)(param_1 + 0x14);
    FUN_8010544c(param_1,0x169);
  }
  if ((*(byte *)(param_1 + 0x33) & 0x80) != 0) {
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 3) = 0;
  }
  pcVar2 = *(char **)(param_1 + 0x4c);
  iVar1 = Enemy_CheckWeaponHits(param_1);
  if ((((iVar1 == 4) || (iVar1 = Enemy_ContactDamage(param_1), iVar1 != 0)) || (*pcVar2 == '\0')) ||
     (pcVar2[1] == '\x03')) {
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 3) = 0;
  }
  Obj_CullAndQueueDraw(param_1);
  return;
}


// ---- 801ee820 FUN_801ee820

void FUN_801ee820(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 3) == '\0') {
    iVar2 = FUN_801eeddc((int)*(short *)(param_1 + 0xe),
                         (int)((*(ushort *)(param_1 + 0x12) - 0x10) * 0x10000) >> 0x10,0,
                         *(undefined1 *)(param_1 + 0x26));
    if (iVar2 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
      *(undefined1 *)(iVar2 + 0x27) = 0x34;
      *(undefined1 *)(iVar2 + 0x24) = DAT_80159f98;
      FUN_8010544c(param_1,10);
      *(undefined **)(param_1 + 0x3c) = &DAT_801f8c6c;
    }
    *(undefined1 *)(param_1 + 0x50) = 6;
    *(undefined1 *)(param_1 + 0x46) = 1;
    *(undefined1 *)(param_1 + 3) = 1;
  }
  cVar1 = *(char *)(param_1 + 0x50) + -1;
  *(char *)(param_1 + 0x50) = cVar1;
  if (cVar1 == '\0') {
    Obj_Free(param_1);
  }
  return;
}


// ---- 801ee8dc FUN_801ee8dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ee8dc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8d10)[obj->sub2])();
  if (obj->active != 0) {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801ee944 FUN_801ee944

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ee944(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  
  if (obj->sub3 == 0) {
    if ((short)obj->frame < 0) {
      Anim_Set(obj,0x1d);
      FUN_8010544c(obj,0x15e);
      FUN_801eeb6c(obj,1);
      obj->sub3 = 1;
    }
  }
  else {
    cVar1 = FUN_801eeb40(obj);
    if (cVar1 == '\x02') {
      uVar2 = FUN_80104db0((int)obj->x,(int)obj->y,(int)*(short *)&obj->field_0x54,
                           (int)*(short *)&obj->field_0x56);
      FUN_80105120(obj,0x800,uVar2);
      obj->sub2 = 1;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801eea00 FUN_801eea00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eea00(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  
  if (obj->sub3 == 0) {
    FUN_80104c34();
    iVar2 = (int)obj->x - (int)*(short *)&obj->field_0x54;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    cVar1 = iVar2 < 9;
    if ((bool)cVar1) {
      obj->x = *(short *)&obj->field_0x54;
    }
    iVar2 = (int)obj->y - (int)*(short *)&obj->field_0x56;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 < 9) {
      obj->y = *(short *)&obj->field_0x56;
      cVar1 = cVar1 + '\x01';
    }
    if (cVar1 == '\x02') {
      FUN_801eeb6c(obj,1);
      obj->sub3 = 1;
    }
  }
  else {
    cVar1 = FUN_801eeb40(obj);
    if (cVar1 == '\x02') {
      Anim_Set(obj,0x1e);
      FUN_8010544c(obj,0x15f);
      obj->sub2 = 2;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801eeafc FUN_801eeafc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eeafc(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    FUN_801eeb6c(obj,1);
    Obj_Free(obj);
  }
  return;
}


// ---- 801eeb40 FUN_801eeb40

undefined1 FUN_801eeb40(int param_1)

{
  undefined1 uVar1;
  
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x4c) + 0x56);
  }
  else {
    uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x4c) + 0x57);
  }
  return uVar1;
}


// ---- 801eeb6c FUN_801eeb6c

void FUN_801eeb6c(int param_1,undefined1 param_2)

{
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x4c) + 0x56) = param_2;
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 0x4c) + 0x57) = param_2;
  }
  return;
}


// ---- 801eeb94 FUN_801eeb94

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eeb94(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8d1c)[obj->sub2])();
  if (obj->active != 0) {
    FUN_801ee688(obj,obj->field_0x52);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801eec00 FUN_801eec00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eec00(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)&obj->field_0x4c;
  FUN_80104c34();
  if ((obj->sub3 == 0) && (iVar2 = Obj_HitboxOverlap(obj,uVar3), iVar2 == 0)) {
    FUN_801091a4((int)obj->x,(int)obj->y,0);
    obj->sub3 = 1;
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    obj->sub2 = 1;
    obj->field_0x50 = 0x80;
  }
  return;
}


// ---- 801eec98 FUN_801eec98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eec98(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)&obj->field_0x4c;
  iVar2 = FUN_801050e4(obj,iVar4);
  uVar3 = (uint)(byte)obj->field_0x52 - iVar2;
  if ((uVar3 & 0xff) != 0) {
    cVar1 = obj->field_0x52 + -4;
    if ((int)(uVar3 * 0x1000000) < 1) {
      cVar1 = obj->field_0x52 + '\x04';
    }
    obj->field_0x52 = cVar1;
  }
  FUN_80105120(obj,0x380,obj->field_0x52);
  FUN_80104c34(obj);
  iVar2 = Obj_HitboxOverlap(iVar4,obj);
  if (iVar2 != 0) {
    *(undefined1 *)(iVar4 + 0x56) = 1;
    FUN_80108e84(obj);
    Obj_Free(obj);
  }
  return;
}


// ---- 801eed3c FUN_801eed3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801eed3c(MM8Obj *obj)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)&obj->field_0x4c;
  if ((*pcVar2 == '\0') || (pcVar2[6] != 'H')) {
    Obj_Free(obj);
  }
  else {
    uVar1 = *(undefined4 *)(pcVar2 + 0xc);
    obj->x_frac = (short)uVar1;
    obj->x = (short)((uint)uVar1 >> 0x10);
    uVar1 = *(undefined4 *)(pcVar2 + 0x10);
    obj->y_frac = (short)uVar1;
    obj->y = (short)((uint)uVar1 >> 0x10);
    obj->flip = pcVar2[0x25];
    Anim_Step(obj);
    if (pcVar2[0x2e] == '\x02') {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801eeddc FUN_801eeddc

int FUN_801eeddc(short param_1,short param_2,undefined1 param_3,undefined1 param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_801091a4((int)param_1,(int)param_2,0x80);
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 0x27) = 0x8a;
    uVar1 = DAT_80159fee;
    *(undefined1 *)(iVar2 + 0x38) = param_3;
    *(undefined1 *)(iVar2 + 0x26) = param_4;
    *(undefined1 *)(iVar2 + 0x24) = uVar1;
  }
  return iVar2;
}


// ---- 801eee4c FUN_801eee4c

undefined1 * FUN_801eee4c(int param_1,char param_2,char param_3,undefined1 param_4)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x35;
    puVar2[7] = param_4;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar1 = (short)param_3;
    }
    else {
      sVar1 = -(short)param_2;
    }
    *(short *)(puVar2 + 0xe) = *(short *)(param_1 + 0xe) + sVar1;
    *(short *)(puVar2 + 0x12) = (short)param_3 + *(short *)(param_1 + 0x12);
  }
  return puVar2;
}


