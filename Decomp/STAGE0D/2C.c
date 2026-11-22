// ID 2C, STAGE0D.BIN, handler 0x801DB878. Ghidra output with the object struct applied; not matching C.
// ---- 801db878 FUN_801db878

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db878(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f8284)[obj->state])();
  return;
}


// ---- 801db8b4 FUN_801db8b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db8b4(MM8Obj *obj)

{
  if (obj->var != 3) {
    Enemy_InitFromTable();
  }
  (*(code *)(&PTR_FUN_801f8294)[obj->var])(obj);
  return;
}


// ---- 801db914 FUN_801db914

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db914(MM8Obj *obj)

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
                    /* Probable PsyQ macro: setTile16() */
  obj->hitbox = &UNK_801f8264 + uVar2 * 4;
  obj->box2 = &UNK_801f8274 + uVar2 * 5;
  Anim_Set(obj,uVar2 | 0x3c);
                    /* Possible PsyQ macro: setTile8() */
  obj->field_0x50 = 0x1c;
  obj->field_0x52 = 0;
  obj->state = 1;
                    /* Possible PsyQ macro: setTile8() */
  return;
}


// ---- 801db9cc FUN_801db9cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db9cc(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0x1c;
  obj->vram_base = DAT_80170380;
  bVar1 = DAT_80159f80;
  obj->draw_list = 4;
  obj->hitbox = &DAT_801f826c;
  obj->dmg_table = 0;
  obj->box2 = &DAT_801f827e;
  obj->flip = 0;
  obj->field_0x53 = 0;
  obj->field_0x55 = 0;
                    /* Probable PsyQ macro: setTile16() */
  obj->clut = bVar1;
  Anim_Set(obj,0);
  obj->state = 2;
  obj->sub2 = 0;
  return;
}


// ---- 801dba54 FUN_801dba54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba54(MM8Obj *obj)

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
  switchD_801dc924::caseD_2(obj);
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
                    /* Possible PsyQ macro: setPolyGT3() */
                    /* Possible PsyQ macro: setPolyGT4() */
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
                    /* Possible PsyQ macro: setPolyGT3() */
  return;
}


// ---- 801dbb6c FUN_801dbb6c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbb6c(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  if (obj->sub2 == 0) {
    FUN_801dbc0c(obj);
                    /* Possible PsyQ macro: setPolyGT3() */
  }
  else {
    FUN_801dbe68(obj);
  }
  iVar1 = Obj_InActiveArea(obj);
  if (iVar1 == 0) {
    Obj_Free(obj);
  }
  else {
                    /* Possible PsyQ macro: setPolyGT3() */
    if ((obj->sub2 == 0) || ((_DAT_80170574 & 1) != 0)) {
      Obj_CullAndQueueDraw(obj);
    }
  }
                    /* Possible PsyQ macro: setPolyF4() */
  return;
}


// ---- 801dbc0c FUN_801dbc0c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801dbc0c(int param_1)

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
  if (_DAT_80170574 == (_DAT_80170574 / 0xf) * 0xf) {
    FUN_8010544c(param_1,0x23);
  }
                    /* Possible PsyQ macro: setLineF2() */
                    /* Possible PsyQ macro: setPolyGT4() */
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
                    /* Possible PsyQ macro: setPolyF4() */
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


// ---- 801dbe68 FUN_801dbe68

void FUN_801dbe68(int param_1)

{
  if (*(short *)(param_1 + 0x2e) < 0) {
    Obj_Free();
  }
  return;
}


// ---- 801dbe98 FUN_801dbe98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbe98(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801f82a4)[obj->sub2])();
  if (obj->active != 0) {
    Enemy_CheckWeaponHits(obj);
    Anim_Step(obj);
    if ((obj->field_0x55 == '\0') || ((_DAT_80170574 & 1) != 0)) {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801dc4ac FUN_801dc4ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc4ac(MM8Obj *obj)

{
  char *pcVar1;
  
  (*(code *)(&PTR_FUN_801f82cc)[obj->sub2])();
  pcVar1 = (char *)obj->accel_x;
  if (((obj->field_0x51 != '\0') && (*pcVar1 != '\0')) &&
     ((*(uint *)(pcVar1 + 4) & 0xffff0000) == 0x22c0000)) {
    *(undefined4 *)(pcVar1 + 0xc) = *(undefined4 *)&obj->x_frac;
    *(undefined4 *)(pcVar1 + 0x10) = *(undefined4 *)&obj->y_frac;
  }
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801dc54c FUN_801dc54c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc54c(MM8Obj *obj)

{
  char cVar1;
  char *pcVar2;
  
                    /* Possible PsyQ macro: setPolyF3() */
  FUN_80104c34();
                    /* Possible PsyQ macro: setTile16() */
  (*(code *)(&PTR_LAB_801f82d8)[obj->sub3])(obj);
  Anim_Step(obj);
  pcVar2 = *(char **)&obj->field_0x4c;
  FUN_801dc8f0(obj);
  if (((*pcVar2 != '\0') && (pcVar2[6] == ' ')) && (cVar1 = obj->field_0x52, cVar1 != '\0')) {
    if (cVar1 == '\x01') {
      obj->sub2 = 1;
    }
    else if (cVar1 == '\x04') {
      if (obj->field_0x51 != '\0') {
        FUN_801dc9cc(obj,2);
      }
      obj->field_0x52 = 0;
    }
  }
  return;
}


// ---- 801dc760 FUN_801dc760

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc760(MM8Obj *obj)

{
  FUN_801dc8f0();
  if (obj->field_0x52 == '\x03') {
    obj->sub2 = 0;
  }
  else if ((obj->field_0x52 == '\x02') && (obj->field_0x51 != '\0')) {
    FUN_801dc9cc(obj,1);
  }
  return;
}


// ---- 801dc7c0 FUN_801dc7c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc7c0(MM8Obj *obj)

{
  if (obj->field_0x4 == '\0') {
    FUN_801dc800();
  }
  else {
    FUN_801dc8a0();
  }
  return;
}


// ---- 801dc800 FUN_801dc800

void FUN_801dc800(int param_1)

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
      FUN_801dc9cc(param_1,3);
    }
    *(undefined1 *)(param_1 + 4) = 1;
  }
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801dc8a0 FUN_801dc8a0

void FUN_801dc8a0(int param_1)

{
  Anim_Step();
  if ((*(short *)(param_1 + 0x2e) < 0) && (*(char *)(param_1 + 0x31) == '\x01')) {
    Obj_Free(param_1);
  }
  return;
}


// ---- 801dc8f0 FUN_801dc8f0

void FUN_801dc8f0(int param_1)

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


// ---- 801dc94c caseD_2

void switchD_801dc924::caseD_2(int param_1)

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


// ---- 801dc9cc FUN_801dc9cc

char * FUN_801dc9cc(int param_1,char param_2)

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


