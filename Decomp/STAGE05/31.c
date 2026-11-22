// ID 31, STAGE05.BIN, handler 0x801DBE40. Ghidra output with the object struct applied; not matching C.
// ---- 801dbe40 FUN_801dbe40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbe40(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801ea3f8)[obj->state])();
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    FUN_80108fd8(obj,0);
    FUN_801dcad0(obj);
    if (obj->var != 0) goto LAB_801dbf88;
    goto LAB_801dbf4c;
  }
  Enemy_ContactDamage(obj);
  Obj_CullAndQueueDraw(obj);
  if (obj->state == 0) {
    return;
  }
  if (obj->var != 0) {
    if (obj->sub2 == 5) {
      return;
    }
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 != '\0') {
      return;
    }
    FUN_801dcad0(obj);
LAB_801dbf88:
    Obj_Free(obj);
    return;
  }
  if (obj->sub2 == 0) {
    return;
  }
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    return;
  }
  FUN_801dcad0(obj);
LAB_801dbf4c:
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801dbfa4 FUN_801dbfa4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbfa4(MM8Obj *obj)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  Enemy_InitFromTable();
  obj->flip = 0;
  obj->draw_list = 5;
  obj->hitbox = &UNK_801ea3e4 + (uint)obj->var * 4;
  obj->box2 = &UNK_801ea3ec + (uint)obj->var * 5;
  if (obj->var == 0) {
    puVar1 = (undefined1 *)FUN_801055e4(obj);
    if (puVar1 != (undefined1 *)0x0) {
      *(undefined1 **)&obj->field_0x58 = puVar1;
      *puVar1 = 1;
      puVar1[6] = 0x31;
      puVar1[7] = 1;
      *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)&obj->x_frac;
      uVar3 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar1 + 0x4c) = obj;
      *(undefined4 *)(puVar1 + 0x10) = uVar3;
      *(short *)(puVar1 + 0xe) = *(short *)(puVar1 + 0xe) + 0x10;
      *(undefined1 **)&obj->field_0x4c = puVar1;
      *(MM8Obj **)(puVar1 + 0x54) = obj;
      *(undefined4 *)(puVar1 + 0x58) = 0;
      puVar2 = (undefined1 *)FUN_801055e4(puVar1);
      if (puVar2 != (undefined1 *)0x0) {
        *(undefined1 **)(puVar1 + 0x58) = puVar2;
        *puVar2 = 1;
        puVar2[6] = 0x31;
        puVar2[7] = 1;
        *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
        uVar3 = *(undefined4 *)&obj->y_frac;
        *(MM8Obj **)(puVar2 + 0x4c) = obj;
        *(undefined1 **)(puVar2 + 0x54) = puVar1;
        *(undefined4 *)(puVar2 + 0x58) = 0;
        *(undefined4 *)(puVar2 + 0x10) = uVar3;
        *(short *)(puVar2 + 0xe) = *(short *)(puVar2 + 0xe) + 0x10;
        puVar1 = (undefined1 *)FUN_801055e4(puVar2);
        if (puVar1 != (undefined1 *)0x0) {
          *(undefined1 **)(puVar2 + 0x58) = puVar1;
          *puVar1 = 1;
          puVar1[6] = 0x31;
          puVar1[7] = 1;
          *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)&obj->x_frac;
          uVar3 = *(undefined4 *)&obj->y_frac;
          *(MM8Obj **)(puVar1 + 0x4c) = obj;
          *(undefined1 **)(puVar1 + 0x54) = puVar2;
          *(undefined4 *)(puVar1 + 0x58) = 0;
          *(undefined4 *)(puVar1 + 0x10) = uVar3;
          *(short *)(puVar1 + 0xe) = *(short *)(puVar1 + 0xe) + 0x10;
        }
      }
      Anim_Set(obj,1);
      obj->state = 1;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x51 = 0;
      obj->field_0x52 = 0;
      obj->dmg_table = 0;
      obj->field_0x50 = 0x50;
      *(undefined4 *)&obj->field_0x54 = 0;
    }
  }
  else {
    Anim_Set(obj,8);
    obj->state = 1;
    obj->sub2 = 5;
    obj->sub3 = 0;
    obj->field_0x51 = 0;
    obj->field_0x52 = 0;
    obj->dmg_table = 0;
  }
  return;
}


// ---- 801dc188 FUN_801dc188

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc188(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea404)[obj->sub2])();
  return;
}


// ---- 801dc1c4 FUN_801dc1c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc1c4(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub3 == 0) {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->dmg_table = 2;
      obj->sub3 = 1;
    }
  }
  else {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      Anim_Set(obj,0);
      obj->field_0x51 = 2;
      obj->sub2 = 1;
      obj->sub3 = 0;
      obj->field_0x50 = 0;
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801dc25c FUN_801dc25c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc25c(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  
  if (((int)(short)obj->frame & 0x8000U) != 0) {
    uVar4 = Rand();
    if ((uVar4 & 3) == 3) {
      uVar6 = 3;
    }
    else {
      uVar6 = 0;
    }
    Anim_Set(obj,uVar6);
  }
  if (obj->field_0x50 == '\0') {
    if (obj->x < DAT_8015e248._2_2_) {
      uVar3 = Rand();
      sVar7 = (DAT_8015e248._2_2_ + -0x60) - (uVar3 & 0xf);
    }
    else {
      uVar3 = Rand();
      sVar7 = DAT_8015e248._2_2_ + 0x60 + (uVar3 & 0xf);
    }
    uVar4 = Rand();
                    /* Possible PsyQ macro: setPolyGT4() */
    iVar5 = FUN_80104db0((int)obj->x,(int)obj->y,(int)sVar7,
                         (int)(((uint)DAT_8015e24c._2_2_ - (uVar4 & 0xf)) * 0x10000) >> 0x10);
    FUN_80105120(obj,0xc0,iVar5 + 8U & 0xf0);
    cVar2 = '\x14';
  }
  else {
    cVar2 = obj->field_0x50 + -1;
  }
  obj->field_0x50 = cVar2;
  FUN_80104c34(obj);
  bVar1 = obj->sub3;
  if (bVar1 == 1) {
    if (obj->field_0x50 != '\0') goto LAB_801dc44c;
    obj->sub3 = 2;
    obj->field_0x51 = 3;
    cVar2 = 'n';
  }
  else {
    if (bVar1 < 2) {
      if ((bVar1 == 0) && (obj->y == DAT_8015e24c._2_2_)) {
        obj->sub3 = 1;
      }
      goto LAB_801dc44c;
    }
    if (bVar1 != 2) goto LAB_801dc44c;
    if (obj->field_0x5c == '\0') {
      FUN_8010910c(obj);
      Anim_Set(obj,0xc);
      obj->sub2 = 2;
      obj->sub3 = 0;
      obj->speed_x = 0;
      obj->speed_y_up = 0;
      goto LAB_801dc44c;
    }
    cVar2 = obj->field_0x5c + -1;
  }
  obj->field_0x5c = cVar2;
LAB_801dc44c:
  Anim_Step(obj);
  return;
}


// ---- 801dc46c FUN_801dc46c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc46c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    iVar1 = -0x30000;
    if (((int)(short)obj->frame & 0x8000U) != 0) {
                    /* Possible PsyQ macro: setLineF2() */
      obj->dmg_table = 0;
      if ((obj->flip & 0x40) != 0) {
        iVar1 = 0x30000;
      }
      obj->speed_x = iVar1;
      obj->sub3 = 1;
    }
    Anim_Step();
  }
  else {
    FUN_80104c34();
  }
  return;
}


// ---- 801dcad0 FUN_801dcad0

void FUN_801dcad0(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = *(char **)(param_1 + 0x54);
  pcVar2 = *(char **)(param_1 + 0x58);
                    /* Possible PsyQ macro: setLineF2() */
  if (pcVar1 == (char *)0x0) {
    if ((((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) && (pcVar2[6] == '1')) &&
       (*(int *)(pcVar2 + 0x54) == param_1)) {
      pcVar2[0x54] = '\0';
      pcVar2[0x55] = '\0';
      pcVar2[0x56] = '\0';
      pcVar2[0x57] = '\0';
      pcVar2[0x52] = '\x01';
    }
  }
  else if (((*pcVar1 != '\0') && (pcVar1[6] == '1')) && (*(int *)(pcVar1 + 0x58) == param_1)) {
    if (((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) ||
       ((pcVar2[6] != '1' || (*(int *)(pcVar2 + 0x54) != param_1)))) {
      pcVar1[0x58] = '\0';
      pcVar1[0x59] = '\0';
      pcVar1[0x5a] = '\0';
      pcVar1[0x5b] = '\0';
    }
    else {
      *(char **)(pcVar1 + 0x58) = pcVar2;
      *(char **)(pcVar2 + 0x54) = pcVar1;
    }
  }
  return;
}


