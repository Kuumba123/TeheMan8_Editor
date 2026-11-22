// ID 08, STAGE0B.BIN, handler 0x801D85FC. Ghidra output with the object struct applied; not matching C.
// ---- 801d85fc FUN_801d85fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d85fc(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e8298)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    if (obj->var < 2) {
      if (obj->field_0x52 == '\0') {
        Obj_FreeDespawn(obj);
      }
    }
    else {
      FUN_801d8cb8(obj);
    }
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  return;
}


// ---- 801d8698 FUN_801d8698

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Possible GS_106.OBJ/GsSetProjection
   Possible _OP_VDEL.OBJ/__builtin_vec_delete
   Possible _OP_VNEW.OBJ/__builtin_vec_new
   Possible SCNOFF.OBJ/SsSetNoiseOff
   Possible SSQUIT.OBJ/SsQuit */

void FUN_801d8698(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  
  Enemy_InitFromTable();
  obj->box2 = &DAT_801e8284;
  bVar1 = obj->var;
  obj->var = obj->var & 0xf;
  bVar2 = obj->var;
  obj->field_0x53 = bVar1 & 0xf0;
  if (bVar2 == 2) {
    obj->state = 2;
    FUN_8010910c(obj);
    Anim_Set(obj,0);
    obj->draw_list = 7;
    obj->field_0x51 = 0;
    *(undefined4 *)&obj->field_0x54 = 0;
  }
  else if (bVar2 < 3) {
    obj->state = 4;
    obj->invuln = 1;
    obj->field_0x50 = 0x14;
    obj->field_0x52 = 0;
    obj->draw_list = 6;
    obj->flip = 0;
    *(undefined4 *)&obj->field_0x54 = 0;
    Anim_Set(obj,4);
  }
  else if (bVar2 == 3) {
    obj->state = 1;
    obj->hitbox = &DAT_801e8294;
    FUN_8010910c(obj);
    Anim_Set(obj,1);
    obj->draw_list = 7;
    obj->field_0x51 = 1;
  }
  return;
}


// ---- 801d87b8 FUN_801d87b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d87b8(MM8Obj *obj)

{
  char cVar1;
  
  if ((short)obj->frame < 0) {
    obj->speed_y_up = -0x10000;
    obj->gravity = 0x4000;
    obj->state = 2;
    obj->speed_x = 0;
    obj->sub2 = 1;
    obj->sub3 = 1;
    obj->field_0x43 = 1;
  }
  Anim_Step(obj);
  if ((obj->anim_extra != 0) && (cVar1 = Enemy_CheckWeaponHits(obj), cVar1 == '\x04')) {
    obj->state = 3;
  }
  return;
}


// ---- 801d8848 FUN_801d8848

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8848(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e82ac)[obj->sub2])();
  cVar1 = Enemy_CheckWeaponHits(obj);
                    /* Probable PsyQ macro: setPolyGT4() */
  if (cVar1 == '\x04') {
    obj->state = 3;
  }
  Enemy_ContactDamage(obj);
  return;
}


// ---- 801d88b4 FUN_801d88b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d88b4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e82b4)[obj->sub3])();
  return;
}


// ---- 801d88f0 FUN_801d88f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d88f0(MM8Obj *obj)

{
  int iVar1;
  
  obj->sub3 = 1;
  if (obj->field_0x51 != '\0') {
    iVar1._0_2_ = obj->x_frac;
    iVar1._2_2_ = obj->x;
    if ((byte)((iVar1 <= DAT_8015e248) << 6) != obj->flip) {
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
    obj->field_0x51 = 0;
  }
  obj->speed_y_up = 0;
  Anim_Set(obj,0);
  FUN_801d8970(obj);
                    /* Possible PsyQ macro: setTile16() */
  return;
}


// ---- 801d8970 FUN_801d8970

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8970(MM8Obj *obj)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  
  bVar1 = obj->anim_extra;
  Anim_Step();
  if (bVar1 != 0) {
    if ((bVar1 & 0x40) == 0) {
      obj->hitbox = &DAT_801e8290;
    }
    else {
      obj->hitbox = &DAT_801e828c;
    }
    uVar2 = bVar1 & 0xf;
    if ((obj->flip & 0x40) == 0) {
      uVar2 = -uVar2;
    }
    obj->x = obj->x + uVar2;
    obj->anim_extra = 0;
  }
  FUN_80106214(obj);
  FUN_801d8e1c(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  else {
    iVar3 = FUN_801d8b30(obj);
    if (iVar3 != 0) {
      obj->sub3 = 2;
      obj->field_0x4 = 0;
    }
  }
  return;
}


// ---- 801d8a44 FUN_801d8a44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8a44(MM8Obj *obj)

{
  short sVar1;
  
  if (obj->field_0x4 == '\0') {
    if ((obj->anim_extra & 0x80) != 0) {
      obj->field_0x4 = obj->field_0x4 + '\x01';
      Anim_Set(obj,2);
    }
    Anim_Step(obj);
  }
  else if ((short)obj->frame < 0) {
    obj->sub3 = 1;
    obj->flip = obj->flip ^ 0x40;
    Anim_Set(obj,0);
  }
  else {
    Anim_Step(obj);
                    /* Possible PsyQ macro: setPolyF4() */
    if (obj->anim_extra != 0) {
      if ((obj->flip & 0x40) == 0) {
        sVar1 = (short)(char)obj->anim_extra;
      }
      else {
        sVar1 = -(short)(char)obj->anim_extra;
      }
                    /* Possible PsyQ macro: setPolyF4() */
      obj->x = obj->x + sVar1;
      obj->anim_extra = 0;
    }
  }
  return;
}


// ---- 801d8b30 FUN_801d8b30

undefined4 FUN_801d8b30(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*(byte *)(param_1 + 0x33) & 0x30) == 0) &&
      (uVar1 = 1, 9 < *(byte *)(param_1 + 0x41) - 0x11)) &&
     (uVar1 = 1, 9 < *(byte *)(param_1 + 0x42) - 0x11)) {
    uVar1 = FUN_801d8e1c();
  }
  return uVar1;
}


// ---- 801d8b94 FUN_801d8b94

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8b94(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = -0x10000;
  if (obj->sub3 == 0) {
    obj->sub3 = obj->sub3 + 1;
    if ((obj->flip & 0x40) != 0) {
      iVar1 = 0x10000;
    }
    obj->speed_y_up = 0x20000;
    obj->gravity = 0x4000;
    obj->field_0x43 = 1;
    obj->speed_x = iVar1;
    obj->hitbox = &DAT_801e8290;
    Anim_Set(obj,5);
  }
  if (obj->speed_y_up < -0x5ffff) {
    obj->speed_y_up = -0x60000;
  }
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  FUN_801d8e1c(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x43 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801d8c70 FUN_801d8c70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8c70(MM8Obj *obj)

{
  FUN_80108e84();
  FUN_8012a5fc(obj,3);
  FUN_80108fd8(obj,4);
  FUN_801d8cb8(obj);
  return;
}


// ---- 801d8cb8 FUN_801d8cb8

void FUN_801d8cb8(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x54);
  if ((((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) &&
      ((*(uint *)(pcVar2 + 4) & 0xffff0000) == 0x1080000)) &&
     (cVar1 = pcVar2[0x52], pcVar2[0x52] = cVar1 - 1U, (int)((uint)(byte)(cVar1 - 1U) << 0x18) < 0))
  {
    pcVar2[0x52] = '\0';
  }
  Obj_FreeDespawn();
  return;
}


// ---- 801d8d30 FUN_801d8d30

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8d30(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  if ((((obj->sub2 == 0) && (uVar2 = FUN_801d8ec4(), uVar2 < 8)) &&
      (cVar1 = obj->field_0x50 + -1, obj->field_0x50 = cVar1, cVar1 == '\0')) &&
     (puVar3 = (undefined1 *)Obj_AllocMain(), puVar3 != (undefined1 *)0x0)) {
    *puVar3 = 1;
    puVar3[6] = 8;
    puVar3[7] = 3;
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
    *(int *)(puVar3 + 0x10) = *(int *)&obj->y_frac + 0x2a0000;
    if (obj->var == 1) {
      obj->field_0x52 = obj->field_0x52 + '\x01';
      *(MM8Obj **)(puVar3 + 0x54) = obj;
      obj->field_0x50 = 0x80;
    }
    else {
      obj->sub2 = obj->sub2 + 1;
      *(undefined4 *)(puVar3 + 0x54) = 0;
    }
  }
  return;
}


// ---- 801d8e1c FUN_801d8e1c

undefined4 FUN_801d8e1c(int param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(char *)(param_1 + 0x53) != '\0') {
    pcVar2 = &DAT_801b1eec;
    do {
      uVar3 = uVar3 + 1;
      if (((*pcVar2 != '\0') && (pcVar2[6] == '\a')) &&
         (iVar1 = FUN_80107bf4(param_1,pcVar2,1), iVar1 != 0)) {
        return 1;
      }
      pcVar2 = pcVar2 + 0x50;
    } while (uVar3 < 0x20);
  }
  return 0;
}


// ---- 801d8ec4 FUN_801d8ec4

int FUN_801d8ec4(void)

{
  char cVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar3 = &g_main_pool;
  iVar4 = 0;
  pbVar2 = &DAT_8015b1c6;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 0x60;
    if ((cVar1 == '\x01') && ((*(uint *)(pbVar2 + -0x4e) & 0xffff0000) == 0x1080000)) {
      iVar4 = iVar4 + (uint)*pbVar2;
    }
    pbVar2 = pbVar2 + 0x60;
  } while (pcVar3 <= "");
  return iVar4;
}


