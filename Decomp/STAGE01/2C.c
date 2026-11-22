// ID 2C, STAGE01.BIN, handler 0x801E2024. Ghidra output with the object struct applied; not matching C.
// ---- 801e2024 FUN_801e2024

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2024(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6c4c)[obj->state])();
  return;
}


// ---- 801e2060 FUN_801e2060

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2060(MM8Obj *obj)

{
  if (obj->var != 3) {
    Enemy_InitFromTable();
  }
  (*(code *)(&PTR_FUN_801e6c5c)[obj->var])(obj);
  return;
}


// ---- 801e20c0 FUN_801e20c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e20c0(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  
  if (obj->var == 0) {
    obj->draw_list = 5;
    bVar1 = obj->clut + 5;
  }
  else {
    obj->draw_list = 4;
    bVar1 = obj->clut + 4;
  }
  obj->clut = bVar1;
  bVar1 = Rand();
  obj->flip = (bVar1 & 1) << 6;
  uVar2 = Rand();
  uVar2 = uVar2 & 1;
  obj->hitbox = &UNK_801e6c2c + uVar2 * 4;
  obj->box2 = &UNK_801e6c3c + uVar2 * 5;
  Anim_Set(obj,uVar2 | 0x3c);
  obj->field_0x50 = 0x1c;
  obj->field_0x52 = 0;
  obj->state = 1;
  return;
}


// ---- 801e2178 FUN_801e2178

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2178(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0x1c;
  obj->vram_base = DAT_80170380;
  bVar1 = DAT_80159f80;
  obj->draw_list = 4;
  obj->hitbox = &DAT_801e6c34;
  obj->dmg_table = 0;
  obj->box2 = &DAT_801e6c46;
  obj->flip = 0;
  obj->field_0x53 = 0;
  obj->field_0x55 = 0;
  obj->clut = bVar1;
  Anim_Set(obj,0);
  obj->state = 2;
  obj->sub2 = 0;
  return;
}


// ---- 801e2200 FUN_801e2200

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2200(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  
  obj->bank = 0x56;
  obj->vram_base = DAT_801703f4;
  bVar1 = DAT_80159fba;
  obj->flip = 0;
  obj->speed_x = -0x20000;
  obj->draw_list = 1;
  obj->invuln = 1;
  obj->hp = 0;
  obj->dmg_table = 1;
  obj->clut = bVar1;
  Anim_Set(obj,0x36);
  obj->field_0x52 = 0;
  FUN_801e30f8(obj);
  obj->state = 3;
  if (DAT_801d2928 + 0x150 < (int)obj->x) {
    obj->sub3 = 0;
    obj->speed_y_up = -0x20000;
  }
  else if (DAT_801d2928 + 0x60 < (int)obj->x) {
    obj->sub3 = 1;
    obj->speed_y_up = 0;
  }
  else {
    obj->sub3 = 2;
    obj->speed_y_up = 0x20000;
  }
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
    puVar2[6] = 0x22;
    puVar2[7] = 2;
    bVar1 = obj->var;
                    /* Probable PsyQ macro: setPolyFT4() */
    puVar2[0x3a] = 0x2c;
    *(MM8Obj **)(puVar2 + 0x20) = obj;
    puVar2[0x3b] = bVar1;
  }
  return;
}


// ---- 801e2318 FUN_801e2318

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2318(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  if (obj->sub2 == 0) {
    FUN_801e23b8(obj);
  }
  else {
    FUN_801e2614(obj);
  }
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_Free(obj);
  }
  else if ((obj->sub2 == 0) || ((DAT_80170574 & 1) != 0)) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e23b8 FUN_801e23b8

void FUN_801e23b8(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  short sVar5;
  char *pcVar6;
  
  pcVar6 = *(char **)(param_1 + 0x4c);
  if ((*(uint *)(param_1 + 0x50) & 0xff00ff) == 0x17) {
    sVar5 = 0x18;
    if (*(char *)(param_1 + 0x51) == '\0') {
      sVar5 = -0x18;
    }
    iVar3 = FUN_80107204((int)*(short *)(param_1 + 0xe) + (int)sVar5,(int)*(short *)(param_1 + 0x12)
                        );
    if ((iVar3 == 0) && (puVar4 = (undefined1 *)Obj_AllocMain(), puVar4 != (undefined1 *)0x0)) {
      *puVar4 = 1;
      puVar4[6] = 0x2c;
      puVar4[7] = *(undefined1 *)(param_1 + 7);
      *(undefined4 *)(puVar4 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      *(short *)(puVar4 + 0xe) = sVar5 + *(short *)(param_1 + 0xe);
      puVar4[0x51] = *(undefined1 *)(param_1 + 0x51);
      *(undefined4 *)(puVar4 + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
    }
  }
  if (DAT_80170574 == (DAT_80170574 / 0xf) * 0xf) {
    FUN_8010544c(param_1,0x23);
  }
  if (((((*pcVar6 != '\0') && ((*(uint *)(pcVar6 + 4) & 0x7fff0000) == 0x1f0000)) &&
       (*(char *)(param_1 + 0x32) != '\0')) && ((DAT_8015e283 != '\0' && (DAT_8015e2ad == '\0'))))
     && ((iVar3 = Obj_HitboxOverlap(&g_player,param_1), iVar3 != 0 && (pcVar6[0x56] == '\0')))) {
    pcVar6[0x56] = '\x01';
  }
  iVar3 = Enemy_CheckWeaponHits(param_1);
  if ((iVar3 != 0) && (DAT_80158f5c == '\x06')) {
    *(undefined1 *)(param_1 + 0x52) = 1;
  }
  cVar2 = *(char *)(param_1 + 0x50) + -1;
  *(char *)(param_1 + 0x50) = cVar2;
  if ((cVar2 == '\0') || (*(char *)(param_1 + 0x52) != '\0')) {
    puVar4 = (undefined1 *)Obj_AllocType3();
    if (puVar4 != (undefined1 *)0x0) {
      *puVar4 = 1;
      puVar4[6] = 0x22;
      puVar4[7] = *(char *)(param_1 + 0x30) + -0x37;
      uVar1 = *(undefined1 *)(param_1 + 0x26);
      puVar4[0x3a] = 0x2c;
      puVar4[0x26] = uVar1;
      uVar1 = *(undefined1 *)(param_1 + 7);
      *(int *)(puVar4 + 0x20) = param_1;
      puVar4[0x3b] = uVar1;
    }
    Anim_Set(param_1,0x42);
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return;
}


// ---- 801e2614 FUN_801e2614

void FUN_801e2614(int param_1)

{
  if (*(short *)(param_1 + 0x2e) < 0) {
    Obj_Free();
  }
  return;
}


// ---- 801e2644 FUN_801e2644

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2644(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e6c6c)[obj->sub2])();
  if (obj->active != 0) {
    Enemy_CheckWeaponHits(obj);
    Anim_Step(obj);
    if ((obj->field_0x55 == '\0') || ((DAT_80170574 & 1) != 0)) {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801e2c58 FUN_801e2c58

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2c58(MM8Obj *obj)

{
  char *pcVar1;
  
  (*(code *)(&PTR_FUN_801e6c94)[obj->sub2])();
  pcVar1 = (char *)obj->accel_x;
  if (((obj->field_0x51 != '\0') && (*pcVar1 != '\0')) &&
     ((*(uint *)(pcVar1 + 4) & 0xffff0000) == 0x22c0000)) {
    *(undefined4 *)(pcVar1 + 0xc) = *(undefined4 *)&obj->x_frac;
    *(undefined4 *)(pcVar1 + 0x10) = *(undefined4 *)&obj->y_frac;
  }
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e2cf8 FUN_801e2cf8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2cf8(MM8Obj *obj)

{
  char cVar1;
  char *pcVar2;
  
  FUN_80104c34();
  (*(code *)(&PTR_LAB_801e6ca0)[obj->sub3])(obj);
  Anim_Step(obj);
  pcVar2 = *(char **)&obj->field_0x4c;
  FUN_801e309c(obj);
  if (((*pcVar2 != '\0') && (pcVar2[6] == ' ')) && (cVar1 = obj->field_0x52, cVar1 != '\0')) {
    if (cVar1 == '\x01') {
      obj->sub2 = 1;
    }
    else if (cVar1 == '\x04') {
      if (obj->field_0x51 != '\0') {
        FUN_801e3178(obj,2);
      }
      obj->field_0x52 = 0;
    }
  }
  return;
}


// ---- 801e2f0c FUN_801e2f0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2f0c(MM8Obj *obj)

{
  FUN_801e309c();
  if (obj->field_0x52 == '\x03') {
    obj->sub2 = 0;
  }
  else if ((obj->field_0x52 == '\x02') && (obj->field_0x51 != '\0')) {
    FUN_801e3178(obj,1);
  }
  return;
}


// ---- 801e2f6c FUN_801e2f6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2f6c(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_801e2fac();
  }
  else {
    FUN_801e304c();
  }
  return;
}


// ---- 801e2fac FUN_801e2fac

void FUN_801e2fac(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x50) + -1;
  *(char *)(param_1 + 0x50) = cVar1;
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x27) = 2;
    *(undefined2 *)(param_1 + 0x2c) = DAT_8017034c;
    *(undefined1 *)(param_1 + 0x24) = DAT_80159f66;
    Anim_Set(param_1,0);
    FUN_8010544c(param_1,9);
    FUN_8012a5fc(param_1,2);
    if (*(char *)(param_1 + 0x51) != '\0') {
      FUN_801e3178(param_1,3);
    }
    *(undefined1 *)(param_1 + 4) = 1;
  }
  return;
}


// ---- 801e304c FUN_801e304c

void FUN_801e304c(int param_1)

{
  Anim_Step();
  if ((*(short *)(param_1 + 0x2e) < 0) && (*(char *)(param_1 + 0x31) == '\x01')) {
    Obj_Free(param_1);
  }
  return;
}


// ---- 801e309c FUN_801e309c

void FUN_801e309c(int param_1)

{
  if ((((**(char **)(param_1 + 0x4c) != '\0') && ((*(char **)(param_1 + 0x4c))[6] == ' ')) &&
      (*(char *)(param_1 + 0x52) != '\0')) && (*(char *)(param_1 + 0x52) == '\x05')) {
    *(undefined1 *)(param_1 + 2) = 2;
    *(undefined1 *)(param_1 + 4) = 0;
    *(undefined1 *)(param_1 + 0x50) = 0x1e;
    *(undefined1 *)(param_1 + 0x52) = 0;
  }
  return;
}


// ---- 801e30f8 FUN_801e30f8

void FUN_801e30f8(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[6] = 0x2c;
    *puVar1 = 1;
    puVar1[7] = 2;
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined1 *)(param_1 + 0x51) = 1;
    *(undefined1 **)(param_1 + 0x1c) = puVar1;
    DAT_801b29a0 = DAT_801b29a0 + '\x01';
  }
  return;
}


// ---- 801e3178 FUN_801e3178

char * FUN_801e3178(int param_1,char param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x1c);
  if (*pcVar2 == '\0') {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (char *)0x0;
    if ((*(uint *)(pcVar2 + 4) & 0xffff0000) == 0x22c0000) {
      pcVar2[0x53] = param_2;
      *(undefined1 *)(param_1 + 0x51) = 0;
      DAT_801b29a0 = DAT_801b29a0 + -1;
      pcVar1 = pcVar2;
    }
  }
  return pcVar1;
}


