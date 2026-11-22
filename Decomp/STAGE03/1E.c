// ID 1E, STAGE03.BIN, handler 0x801DDDFC. Ghidra output with the object struct applied; not matching C.
// ---- 801dddfc FUN_801dddfc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dddfc(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e9bf8)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  iVar1 = Obj_InActiveArea(obj);
  if (((obj->var == 0) && (((int)obj->x - (int)DAT_801d2918._2_2_) + 99U < 0x207)) &&
     (((int)obj->y - (int)g_cam_y) - 1U < 0xef)) {
    iVar1 = 1;
  }
  if (iVar1 == 0) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801ddec0 FUN_801ddec0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddec0(MM8Obj *obj)

{
  byte bVar1;
  
  Enemy_InitFromTable();
  switch(obj->var) {
  case 0:
    obj->state = 1;
    obj->speed_x = -0x20000;
    obj->accel_x = 0x1800;
    obj->field_0x50 = 0x1d;
    FUN_8010910c(obj);
    if ((obj->flip & 0x40) != 0) {
      obj->speed_x = -obj->speed_x;
      obj->accel_x = -obj->accel_x;
    }
    goto LAB_801de008;
  case 1:
  case 2:
  case 3:
    obj->state = 2;
    obj->speed_x = -0x30000;
    obj->accel_x = 0x1800;
    obj->flip = 0;
    goto LAB_801de008;
  case 4:
  case 5:
  case 6:
  case 7:
    bVar1 = obj->var;
    obj->state = 3;
    obj->contact_dmg = 6;
    obj->speed_x = -0x48000;
    obj->flip = 0;
    break;
  default:
    bVar1 = obj->var;
    obj->state = 3;
    obj->contact_dmg = 6;
    obj->speed_x = 0x30000;
                    /* Possible PsyQ macro: setLineF2() */
    obj->flip = 0x40;
    obj->x = obj->x + -0x160;
  }
  *(uint *)&obj->field_0x4c = (int)&PTR_FUN_801e9bbc + (uint)bVar1 * 6;
LAB_801de008:
  Anim_Set(obj,0);
  obj->draw_list = 6;
  obj->field_0x51 = 0;
  return;
}


// ---- 801de030 FUN_801de030

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de030(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    FUN_801de09c();
  }
  else {
    FUN_801de0f4(obj);
  }
  Anim_Step(obj);
  iVar1 = switchD_801de694::switchD(obj);
  if (iVar1 == 4) {
    obj->state = 4;
  }
  return;
}


// ---- 801de09c FUN_801de09c

void FUN_801de09c(int param_1)

{
  char cVar1;
  
  FUN_80104c34();
  cVar1 = *(char *)(param_1 + 0x50) + -1;
  *(char *)(param_1 + 0x50) = cVar1;
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 3) = 0;
    Anim_Set(param_1,1);
  }
  return;
}


// ---- 801de0f4 FUN_801de0f4

void FUN_801de0f4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((*(char *)(param_1 + 3) == '\0') &&
     (*(undefined1 *)(param_1 + 0x51) = *(undefined1 *)(param_1 + 0x32),
     *(short *)(param_1 + 0x2e) < 0)) {
    *(undefined1 *)(param_1 + 3) = 1;
    *(undefined1 *)(param_1 + 0x51) = 0;
    *(byte *)(param_1 + 0x25) = *(byte *)(param_1 + 0x25) ^ 0x40;
    Anim_Set(param_1,0);
  }
  FUN_80104c9c(param_1);
  uVar2 = *(uint *)(param_1 + 0x14);
  if ((uVar2 & 0x80000000) == (*(uint *)(param_1 + 0x1c) & 0x80000000)) {
                    /* Possible PsyQ macro: setLineF2() */
    if ((int)uVar2 < 0) {
      uVar2 = -uVar2;
    }
    uVar1 = 0xfffe0000;
    if (0x1ffff < (int)uVar2) {
      *(undefined1 *)(param_1 + 2) = 0;
      if (0 < *(int *)(param_1 + 0x14)) {
        uVar1 = 0x20000;
      }
      *(undefined4 *)(param_1 + 0x14) = uVar1;
      *(undefined1 *)(param_1 + 0x50) = 0x3a;
      *(int *)(param_1 + 0x1c) = -*(int *)(param_1 + 0x1c);
    }
  }
  return;
}


// ---- 801de1c8 FUN_801de1c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de1c8(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e9c0c)[obj->sub2])();
  if (DAT_801d2915 == '\x01') {
    obj->x = obj->x + DAT_801d293a;
    obj->y = obj->y + DAT_801d293c;
  }
  Anim_Step(obj);
  iVar1 = switchD_801de694::switchD(obj);
  if (iVar1 == 4) {
    obj->state = 4;
  }
  return;
}


// ---- 801de274 FUN_801de274

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de274(MM8Obj *obj)

{
  FUN_80104c34();
  if ((int)obj->x - (int)DAT_801d2918._2_2_ <= (int)((uint)obj->var * 0x28 + 0x58)) {
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801de2d4 FUN_801de2d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de2d4(MM8Obj *obj)

{
  FUN_80104c9c();
  if ((obj->speed_x & 0x80000000U) == (obj->accel_x & 0x80000000U)) {
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->speed_x = 0;
    Anim_Set(obj,1);
  }
  return;
}


// ---- 801de330 FUN_801de330

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de330(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    obj->field_0x51 = obj->anim_extra;
    if ((short)obj->frame < 0) {
      obj->sub3 = 1;
      obj->field_0x51 = 0;
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
      Anim_Set(obj,0);
    }
  }
  else {
    if (0x2ffff < obj->speed_x) {
      obj->accel_x = 0;
    }
    FUN_80104c9c();
  }
  return;
}


// ---- 801de3b0 FUN_801de3b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de3b0(MM8Obj *obj)

{
  int iVar1;
  
                    /* Possible PsyQ macro: setPolyF4() */
  (*(code *)(&PTR_LAB_801e9c18)[obj->sub2])();
  Obj_ApplySpeed(obj);
  if (DAT_801d2915 == '\x01') {
    obj->x = obj->x + DAT_801d293a;
    obj->y = obj->y + DAT_801d293c;
  }
  Anim_Step(obj);
  obj->field_0x51 = obj->anim_extra;
  iVar1 = switchD_801de694::switchD(obj);
  if (iVar1 == 4) {
    obj->state = 4;
  }
  return;
}


// ---- 801de64c FUN_801de64c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de64c(MM8Obj *obj)

{
  FUN_80108e84();
  FUN_8012a5fc(obj,3);
  FUN_80108fd8(obj,0);
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801de694 switchD

int switchD_801de694::switchD(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x51) == '\0') {
    *(undefined **)(param_1 + 0x3c) = &DAT_801e9bc8;
    *(undefined1 *)(param_1 + 0x44) = 1;
    Enemy_CheckWeaponHits();
    Enemy_ContactDamage(param_1);
    *(undefined **)(param_1 + 0x3c) = &DAT_801e9bcc;
  }
  else {
    *(undefined **)(param_1 + 0x3c) = &DAT_801e9bd0;
  }
  *(undefined1 *)(param_1 + 0x44) = 2;
  Enemy_ContactDamage(param_1);
  iVar1 = Enemy_CheckWeaponHits(param_1);
  if (iVar1 == 2) {
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x24) = DAT_80159f9e;
  }
  return iVar1;
}


