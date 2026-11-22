// ID 39, STAGE07.BIN, handler 0x801D8EF4. Ghidra output with the object struct applied; not matching C.
// ---- 801d8ef4 FUN_801d8ef4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8ef4(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e0864)[obj->state])();
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    goto LAB_801d8fc8;
  }
  if ((byte)(cVar1 - 2U) < 2) {
    obj->field_0x52 = 1;
  }
  else {
                    /* Possible PsyQ macro: setLineF2() */
    obj->field_0x52 = 0;
  }
  Enemy_ContactDamage(obj);
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    return;
  }
LAB_801d8fc8:
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801d8fe4 FUN_801d8fe4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8fe4(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 7;
  obj->hitbox = &DAT_801e0858;
  obj->box2 = &DAT_801e085c;
  obj->state = 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->flip = 0;
  obj->field_0x52 = 0;
  if (obj->x < DAT_8015e248._2_2_) {
    obj->field_0x51 = 1;
  }
  else {
    obj->field_0x51 = 0;
  }
  obj->speed_x = 0;
  Anim_Set(obj,obj->field_0x51);
  return;
}


// ---- 801d907c FUN_801d907c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d907c(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  byte bVar4;
  
  bVar4 = obj->sub2;
  if (bVar4 == 1) {
    Obj_ApplySpeed(obj);
    FUN_80106214(obj);
    if (obj->speed_y_up < -0x60000) {
      obj->speed_y_up = -0x60000;
      obj->gravity = 0;
    }
    if ((obj->field_0x33 & 0x80) != 0) {
                    /* Probable PsyQ macro: setLineF2() */
      if (obj->sub3 == 0) {
        obj->gravity = 0x4000;
                    /* Possible PsyQ macro: setLineF2() */
        obj->sub3 = 1;
        obj->speed_y_up = -(obj->speed_y_up >> 1);
      }
      else {
        obj->field_0x50 = 8;
        obj->sub2 = 2;
        obj->speed_y_up = 0;
        obj->gravity = 0;
        obj->field_0x4 = 1;
      }
    }
    if (obj->field_0x52 == '\0') {
      return;
    }
    obj->field_0x50 = 0x40;
    return;
  }
  if (bVar4 < 2) {
    if (bVar4 != 0) {
      return;
    }
    iVar3 = 0x10000;
    if ((ushort)((obj->y - DAT_8015e24c._2_2_) - 1U) < 0x1f) {
      iVar3 = 0x30000;
    }
    if (obj->field_0x51 == '\0') {
      obj->speed_x = -iVar3;
    }
    else {
      obj->speed_x = iVar3;
    }
    FUN_80104c34(obj);
    FUN_80106214(obj);
    if (obj->field_0x52 != '\0') {
                    /* Possible PsyQ macro: setLineF2() */
      obj->field_0x50 = 0x40;
      Anim_SetAtStep(obj,obj->field_0x51 + '\x02',obj->anim_extra & 0xf);
      obj->sub2 = 2;
      obj->field_0x4 = 1;
      return;
    }
    if ((obj->field_0x33 & 0x80) != 0) {
      iVar3 = FUN_801d9394(obj);
      if ((iVar3 != 0) || ((obj->field_0x33 & 0x30) != 0)) {
        obj->field_0x50 = 8;
        Anim_SetAtStep(obj,obj->field_0x51 + '\x02',obj->anim_extra & 0xf);
        obj->sub2 = 2;
        obj->field_0x4 = 0;
        return;
      }
      Anim_Step(obj);
      iVar3 = obj->speed_x;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (iVar3 != 0x30000) {
        return;
      }
      Anim_Step(obj);
      return;
    }
    obj->speed_x = 0;
    obj->speed_y_up = 0;
    obj->gravity = 0x4000;
    Anim_SetAtStep(obj,obj->field_0x51 + '\x02',obj->anim_extra & 0xf);
  }
  else {
    if (bVar4 != 2) {
      return;
    }
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      if (obj->field_0x52 != '\0') {
        obj->field_0x50 = 0x40;
      }
      cVar1 = obj->field_0x50;
      obj->field_0x50 = cVar1 + -1;
      if (cVar1 != '\0') {
        return;
      }
      if (obj->field_0x4 == '\0') {
        obj->field_0x51 = obj->field_0x51 ^ 1;
        uVar2 = obj->field_0x51;
        bVar4 = obj->anim_extra >> 4;
      }
      else {
        uVar2 = obj->field_0x51;
        bVar4 = obj->anim_extra & 0xf;
      }
      Anim_SetAtStep(obj,uVar2,bVar4);
      obj->sub2 = 0;
      return;
    }
    obj->gravity = 0x4000;
    obj->speed_x = 0;
    obj->speed_y_up = 0;
  }
  obj->sub2 = 1;
  obj->sub3 = 0;
  return;
}


// ---- 801d9394 FUN_801d9394

bool FUN_801d9394(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)(param_1 + 0x38);
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    sVar2 = (short)pcVar4[2];
  }
  else {
    sVar2 = -(short)pcVar4[2];
  }
  sVar2 = *(short *)(param_1 + 0xe) + sVar2;
  if ((*(byte *)(param_1 + 0x25) & 0x80) == 0) {
    iVar3 = (int)pcVar4[3];
  }
  else {
    iVar3 = -(int)pcVar4[3];
  }
  if (*(char *)(param_1 + 0x51) == '\0') {
    sVar2 = (sVar2 + -1) - (short)*pcVar4;
  }
  else {
    sVar2 = sVar2 + 1 + (short)*pcVar4;
  }
  cVar1 = FUN_80107204((int)sVar2,
                       ((int)pcVar4[1] + *(short *)(param_1 + 0x12) + iVar3 + 1) * 0x10000 >> 0x10);
  return cVar1 == '\0';
}


