// ID 0A, STAGE01.BIN, handler 0x801D9BC8. Ghidra output with the object struct applied; not matching C.
// ---- 801d9bc8 FUN_801d9bc8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9bc8(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e67ec)[obj->state])();
  if ((obj->state != 3) || ((obj->field_0x51 & 1) == 0)) {
    Obj_CullAndQueueDraw(obj);
                    /* Possible PsyQ macro: setPolyF4() */
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801d9c54 FUN_801d9c54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9c54(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  obj->bank = 0x18;
  obj->vram_base = DAT_80170378;
  bVar1 = DAT_80159f7c;
  obj->hitbox = &DAT_801e6798;
  obj->box2 = &DAT_801e67a4;
  obj->state = 1;
  obj->draw_list = 6;
  obj->contact_dmg = 3;
  obj->dmg_table = 2;
  obj->hp = 6;
  obj->invuln = 0;
  obj->clut = bVar1;
  bVar1 = Rand();
  obj->field_0x55 = (bVar1 & 1) + 3;
  obj->field_0x43 = 0;
  obj->field_0x56 = 0;
  obj->field_0x57 = 2;
  *(undefined **)&obj->field_0x58 = &UNK_801e6728 + (uint)(obj->var >> 4) * 0x1c;
  obj->var = obj->var & 0xf;
  bVar1 = obj->var;
  if (bVar1 == 1) {
    obj->x = obj->x + -0x17c;
    iVar2 = *(int *)(*(int *)&obj->field_0x58 + 8);
    obj->speed_y_up = 0;
    obj->field_0x53 = 1;
  }
  else {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      obj->draw_list = 7;
      obj->gravity = 0x4000;
      obj->accel_x = -0x2000;
      obj->hitbox = &DAT_801e67ac;
      obj->state = 2;
      obj->speed_y_up = 0;
      obj->box2 = &DAT_801e67b0;
      obj->field_0x51 = 3;
      Anim_Set(obj,10);
      FUN_8012c854(obj,&obj->field_0x57,6,4);
      obj->field_0x57 = 0;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    iVar2 = *(int *)(*(int *)&obj->field_0x58 + 4);
    obj->speed_y_up = 0;
    obj->field_0x53 = 0;
  }
                    /* Possible PsyQ macro: setLineF2() */
  obj->flip = 0x40;
  obj->speed_x = iVar2;
  Anim_Set(obj,9);
  return;
}


// ---- 801d9e2c FUN_801d9e2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9e2c(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e67fc)[obj->sub2])();
  Enemy_ContactDamage(obj);
  iVar1 = Enemy_CheckWeaponHits(obj);
  if (iVar1 == 2) {
    obj->clut = 0;
  }
  else {
    obj->clut = DAT_80159f7c;
  }
  if (iVar1 == 4) {
    obj->state = 3;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801d9ec0 FUN_801d9ec0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ec0(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80104ccc();
  if (obj->field_0x53 == '\0') {
    if (0x121 < (int)obj->x - (int)DAT_801d2918._2_2_) goto LAB_801d9f3c;
    iVar1 = 0x1000;
  }
  else {
    if ((int)obj->x - (int)DAT_801d2918._2_2_ < 0x29) goto LAB_801d9f3c;
    iVar1 = -0x1000;
  }
  obj->sub2 = 1;
  obj->accel_x = iVar1;
  obj->field_0x50 = 1;
LAB_801d9f3c:
  Anim_Step(obj);
  FUN_801db2f8(obj,0);
  FUN_801db394(obj,0);
  FUN_801db4cc(obj);
  return;
}


// ---- 801d9f78 FUN_801d9f78

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9f78(MM8Obj *obj)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined1 uVar5;
  
  Obj_ApplySpeed();
  bVar1 = false;
  if ((*(int *)(*(int *)&obj->field_0x58 + 8) < obj->speed_x) ||
     (obj->speed_x < *(int *)(*(int *)&obj->field_0x58 + 4))) {
    bVar1 = true;
    obj->accel_x = -obj->accel_x;
  }
  Anim_Step(obj);
  FUN_801db2f8(obj,0);
  FUN_801db394(obj,1);
  FUN_801db4cc(obj);
  if (obj->sub3 == 0) {
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 != '\0') {
      return;
    }
    obj->sub3 = obj->sub3 + 1;
    if (obj->field_0x55 == '\0') {
      uVar5 = 4;
      if (obj->field_0x53 == '\0') {
        uVar5 = 3;
      }
      obj->field_0x54 = uVar5;
    }
    else {
      if (obj->field_0x53 == '\0') {
        uVar4 = Rand();
        obj->field_0x54 = (&DAT_801e67b8)[uVar4 & 0xf];
      }
      else {
        uVar4 = Rand();
        obj->field_0x54 = (&DAT_801e67c8)[uVar4 & 0xf];
      }
      obj->field_0x55 = obj->field_0x55 + -1;
    }
  }
  obj->field_0x4 = 0;
  switch(obj->field_0x54) {
  case 0:
    if (!bVar1) {
      return;
    }
    if (obj->field_0x53 == '\0') {
      bVar3 = 2;
      if (-1 < obj->accel_x) {
        return;
      }
      goto LAB_801da174;
    }
    if (obj->accel_x < 1) {
      return;
    }
    obj->sub2 = 2;
    break;
  case 1:
    if (!bVar1) {
      return;
    }
    if (obj->accel_x < 1) {
      return;
    }
    if (obj->field_0x56 != '\0') {
      return;
    }
    obj->sub2 = 3;
    break;
  case 2:
    if (!bVar1) {
      return;
    }
    bVar3 = 4;
    if (obj->accel_x < 1) {
      return;
    }
LAB_801da174:
    obj->sub2 = bVar3;
    break;
  case 3:
    obj->sub2 = 5;
    obj->accel_x = 0x2000;
    return;
  case 4:
    obj->sub2 = 6;
    obj->sub3 = 0;
    obj->field_0x53 = 0;
    Anim_Set(obj,8);
  default:
    goto switchD_801da0dc_default;
  }
  obj->sub3 = 0;
switchD_801da0dc_default:
  return;
}


// ---- 801da1c8 FUN_801da1c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da1c8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e681c)[obj->sub3])();
  FUN_801db2f8(obj,0);
  FUN_801db394(obj,1);
  return;
}


// ---- 801da228 FUN_801da228

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da228(MM8Obj *obj)

{
  if (obj->field_0x53 == '\0') {
    obj->sub3 = 2;
    Anim_Set(obj,8);
  }
  else {
    obj->sub3 = obj->sub3 + 1;
    if (0 < obj->accel_x) {
      obj->accel_x = -obj->accel_x;
    }
    Anim_Set(obj,9);
    FUN_801da2a4(obj);
  }
  return;
}


// ---- 801da2a4 FUN_801da2a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da2a4(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    FUN_801db228(obj,*(undefined4 *)(*(int *)&obj->field_0x58 + 4));
    if ((int)obj->x - (int)DAT_801d2918._2_2_ < 0x1e) {
      obj->field_0x51 = 0x1e;
      obj->accel_x = 0x2000;
      obj->field_0x4 = obj->field_0x4 + '\x01';
      Anim_Set(obj,9);
    }
  }
  else {
    FUN_801db228(obj,*(undefined4 *)(*(int *)&obj->field_0x58 + 4));
    cVar1 = obj->field_0x51 + -1;
    obj->field_0x51 = cVar1;
    if (cVar1 == '\0') {
      obj->sub3 = 3;
      obj->field_0x4 = 0;
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801da368 FUN_801da368

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da368(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x4 = obj->field_0x4 + '\x01';
    iVar1 = *(int *)(*(int *)&obj->field_0x58 + 0xc);
    if (obj->field_0x53 == '\0') {
      iVar1 = -iVar1;
    }
    obj->accel_x = iVar1;
    FUN_801db56c(obj,0x7b);
  }
  else {
    Anim_Step(obj);
    if ((char)obj->anim_extra != 0) {
      FUN_801db440(obj,(int)(char)obj->anim_extra - 1U & 0xff,2);
    }
    if ((short)obj->frame < 0) {
      obj->field_0x4 = 0;
      obj->flip = obj->flip ^ 0x40;
      obj->sub3 = obj->sub3 + 1;
    }
  }
  Obj_ApplySpeed(obj);
  return;
}


// ---- 801da434 FUN_801da434

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da434(MM8Obj *obj)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x58;
  if (obj->field_0x4 == '\0') {
    obj->hitbox = &DAT_801e67a0;
    obj->field_0x4 = obj->field_0x4 + '\x01';
    Anim_Set(obj,0);
    FUN_8012c854(obj,&obj->field_0x57,0x1a,0xe);
    obj->field_0x57 = 0;
  }
  if (obj->field_0x53 == '\0') {
    uVar1 = *(undefined4 *)(iVar2 + 0x10);
  }
  else {
    uVar1 = *(undefined4 *)(iVar2 + 0x14);
  }
  FUN_801db228(obj,uVar1);
  Anim_Step(obj);
  FUN_801db440(obj,8,4);
  if (obj->field_0x55 != '\0') {
    if (((int)*(short *)(iVar2 + 0x18) < (int)obj->x - (int)DAT_801d2918._2_2_) ||
       (obj->field_0x53 != '\0')) {
      if (((int)*(short *)(iVar2 + 0x1a) <= (int)obj->x - (int)DAT_801d2918._2_2_) &&
         (obj->field_0x53 != '\0')) {
        obj->hitbox = &DAT_801e6798;
        obj->field_0x4 = 0;
        obj->field_0x53 = 0;
        obj->field_0x57 = 2;
        obj->sub3 = obj->sub3 + 1;
      }
    }
    else {
      obj->sub3 = 5;
      obj->field_0x53 = 1;
      obj->hitbox = &DAT_801e6798;
      obj->field_0x4 = 0;
      obj->field_0x57 = 2;
      Anim_Set(obj,8);
    }
  }
  return;
}


// ---- 801da5b0 FUN_801da5b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da5b0(MM8Obj *obj)

{
  byte bVar1;
  int *piVar2;
  
  bVar1 = obj->field_0x4;
  piVar2 = *(int **)&obj->field_0x58;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if ((bVar1 == 2) &&
         (FUN_801db228(obj,piVar2[1]), (int)obj->x - (int)DAT_801d2918._2_2_ < 0x123)) {
        obj->sub2 = 1;
        obj->field_0x50 = 1;
        obj->sub3 = 0;
        obj->accel_x = -0x1000;
      }
      goto LAB_801da6a0;
    }
    if (bVar1 != 0) goto LAB_801da6a0;
    obj->field_0x4 = 1;
    obj->accel_x = -0x2000;
    obj->x = obj->x + 0x10;
    Anim_Set(obj,9);
  }
  Obj_ApplySpeed(obj);
  if (obj->speed_x <= *piVar2) {
    obj->field_0x4 = 2;
    Anim_Set(obj,9);
  }
LAB_801da6a0:
  Anim_Step(obj);
  FUN_801db4cc(obj);
  return;
}


// ---- 801da6c8 FUN_801da6c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da6c8(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->accel_x = 0x1000;
    obj->field_0x4 = obj->field_0x4 + '\x01';
    Anim_Set(obj,9);
  }
  FUN_801db228(obj,*(undefined4 *)(*(int *)&obj->field_0x58 + 8));
  if (0x28 < (int)obj->x - (int)DAT_801d2918._2_2_) {
    obj->sub2 = 1;
    obj->sub3 = 0;
    obj->field_0x50 = 1;
    iVar1 = *(int *)(*(int *)&obj->field_0x58 + 8);
    obj->accel_x = -0x1000;
    obj->speed_x = iVar1;
  }
  FUN_801db4cc(obj);
  return;
}


// ---- 801da770 FUN_801da770

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da770(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6838)[obj->sub3])();
  return;
}


// ---- 801da7ac FUN_801da7ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da7ac(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x4 = obj->field_0x4 + '\x01';
    iVar1 = *(int *)(*(int *)&obj->field_0x58 + 8);
    obj->accel_x = 0x2000;
    obj->speed_x = iVar1;
    Anim_Set(obj,2);
  }
  FUN_80104ccc(obj);
  Anim_Step(obj);
  if (obj->anim_extra != 0) {
    obj->anim_extra = 0;
    obj->y = obj->y + -0x10;
  }
  FUN_801db2f8(obj,0);
  FUN_801db394(obj,0);
  if ((short)obj->frame < 0) {
    obj->speed_y_up = 0x2e000;
    obj->gravity = 0x4000;
    obj->field_0x56 = 0;
    obj->field_0x43 = 1;
    obj->sub3 = obj->sub3 + 1;
    Anim_Set(obj,3);
    FUN_8010544c(obj,0x7c);
  }
  return;
}


// ---- 801da898 FUN_801da898

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da898(MM8Obj *obj)

{
  FUN_80104ccc();
  Anim_Step(obj);
  FUN_801db2f8(obj,0);
  if ((obj->field_0x33 & 0x80) != 0) {
    if ((int)DAT_8015e248._2_2_ < obj->x + 0x78) {
      obj->accel_x = 0x800;
      obj->speed_y_up = 0x2e000;
      obj->sub3 = obj->sub3 + 1;
    }
    else {
      obj->speed_y_up = 0x2e000;
      FUN_8010544c(obj,0x7c);
    }
  }
  return;
}


// ---- 801da93c FUN_801da93c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da93c(MM8Obj *obj)

{
  Obj_ApplySpeed();
  Anim_Step(obj);
  FUN_801db2f8(obj,0);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->speed_y_up = 0;
    obj->field_0x43 = 0;
    obj->hitbox = &DAT_801e679c;
    obj->sub3 = obj->sub3 + 1;
    Anim_Set(obj,4);
    FUN_801db56c(obj,0x7b);
  }
  return;
}


// ---- 801da9c0 FUN_801da9c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da9c0(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)&obj->field_0x58 + 4);
  if (iVar1 < obj->speed_x) {
    Obj_ApplySpeed();
  }
  else {
    obj->speed_x = iVar1;
    FUN_80104ccc(obj);
  }
  Anim_Step(obj);
  if ((obj->anim_extra & 0x80) != 0) {
    obj->hitbox = &DAT_801e6798;
    obj->accel_x = -0x8000;
    obj->anim_extra = obj->anim_extra & 0x7f;
  }
  if (((short)obj->frame < 0) && (obj->speed_y_up == 0)) {
    obj->field_0x4 = 0;
    obj->field_0x51 = 0x1e;
    obj->sub3 = obj->sub3 + 1;
    Anim_Set(obj,9);
  }
  FUN_801db440(obj,0,3);
  FUN_801db2f8(obj,0);
  FUN_801db394(obj,0);
  return;
}


// ---- 801daac0 FUN_801daac0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daac0(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x51 == '\0') {
    if ((short)obj->frame < 0) {
      Anim_Set(obj,9);
      obj->field_0x51 = 0x1e;
    }
  }
  else {
    cVar1 = obj->field_0x51 + -1;
    obj->field_0x51 = cVar1;
    if (cVar1 == '\0') {
      Anim_Set(obj,9);
    }
  }
  FUN_80104ccc(obj);
  Anim_Step(obj);
  if ((int)obj->x - (int)DAT_801d2918._2_2_ < 0x28) {
    obj->sub2 = 1;
    obj->field_0x50 = 1;
    obj->sub3 = 0;
    obj->accel_x = 0x1000;
    Anim_Set(obj,9);
  }
  FUN_801db2f8(obj,0);
  FUN_801db394(obj,0);
  return;
}


// ---- 801daba8 FUN_801daba8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daba8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e684c)[obj->sub3])();
  Anim_Step(obj);
  FUN_801db2f8(obj,0);
  FUN_801db394(obj,1);
  return;
}


// ---- 801dac10 FUN_801dac10

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dac10(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = obj->field_0x4;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      Obj_ApplySpeed(obj);
      if (**(int **)&obj->field_0x58 < obj->speed_x) {
        return;
      }
      obj->sub3 = 1;
      obj->field_0x4 = 0;
      obj->speed_x = **(int **)&obj->field_0x58;
      Anim_Set(obj,5);
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    obj->field_0x4 = 1;
    obj->accel_x = 0x1000;
  }
  FUN_801db228(obj,*(undefined4 *)(*(int *)&obj->field_0x58 + 8));
  if (299 < (int)obj->x - (int)DAT_801d2918._2_2_) {
    obj->field_0x4 = 2;
    obj->accel_x = -0x1000;
  }
  return;
}


// ---- 801dad04 FUN_801dad04

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dad04(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = obj->field_0x4;
  if (bVar1 == 1) {
    if (obj->field_0x51 == '\x1e') {
      FUN_801db278(obj);
    }
    cVar2 = obj->field_0x51 + -1;
    obj->field_0x51 = cVar2;
    if (cVar2 != '\0') goto LAB_801dae10;
    obj->field_0x4 = 2;
    uVar4 = 7;
  }
  else {
    if (bVar1 < 2) {
      if ((bVar1 == 0) && ((short)obj->frame < 0)) {
        obj->field_0x4 = 1;
                    /* Possible PsyQ macro: setPolyGT4() */
        obj->field_0x51 = 0x3c;
        Anim_Set(obj,6);
        FUN_8012c854(obj,&obj->field_0x57,0x1a,0xe);
        obj->field_0x57 = 0;
      }
      goto LAB_801dae10;
    }
    if ((bVar1 != 2) || (-1 < (short)obj->frame)) goto LAB_801dae10;
    obj->sub3 = 2;
    obj->field_0x4 = 2;
    iVar3 = *(int *)(*(int *)&obj->field_0x58 + 4);
    uVar4 = 9;
    obj->field_0x57 = 2;
    obj->speed_x = iVar3;
  }
  Anim_Set(obj,uVar4);
LAB_801dae10:
  FUN_80104ccc(obj);
  return;
}


// ---- 801dae2c FUN_801dae2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dae2c(MM8Obj *obj)

{
  FUN_80104c9c();
  Anim_Step(obj);
  FUN_801db2f8(obj,1);
  FUN_801db394(obj,0);
  return;
}


// ---- 801dae74 FUN_801dae74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dae74(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_801da368(obj);
  }
  else {
    obj->field_0x53 = 0;
    FUN_801da434(obj);
  }
  FUN_801db2f8(obj,1);
  FUN_801db394(obj,0);
  return;
}


// ---- 801daedc FUN_801daedc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daedc(MM8Obj *obj)

{
  int *piVar1;
  
  if (obj->sub3 == 0) {
    obj->field_0x43 = 1;
    piVar1 = *(int **)&obj->field_0x58;
    obj->gravity = 0x4000;
    obj->sub3 = obj->sub3 + 1;
    if (*piVar1 < obj->speed_x) {
      obj->speed_x = piVar1[1];
    }
    else {
      obj->speed_x = piVar1[2];
    }
    Anim_Set(obj,0xc);
  }
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if (((obj->field_0x33 & 0x40) != 0) && (0 < obj->speed_y_up)) {
    obj->speed_y_up = -0x400;
  }
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->sub2 = 1;
    obj->field_0x50 = 1;
    obj->gravity = 0;
    obj->speed_y_up = 0;
    obj->field_0x56 = 0;
    obj->field_0x43 = 0;
    obj->sub3 = 0;
    obj->accel_x = 0x1000;
    Anim_Set(obj,9);
  }
  Anim_Step(obj);
  return;
}


// ---- 801dafe4 FUN_801dafe4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dafe4(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e6858)[obj->sub3])();
  Anim_Step(obj);
  Enemy_ContactDamage(obj);
  iVar1 = Enemy_CheckWeaponHits(obj);
  if (iVar1 == 4) {
    obj->state = 3;
  }
  return;
}


// ---- 801db054 FUN_801db054

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db054(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  Obj_ApplySpeed();
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    return;
  }
  bVar1 = obj->field_0x51 - 1;
  obj->field_0x51 = bVar1;
  if (bVar1 == 1) {
    iVar2 = 0x16d00;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      obj->speed_y_up = 0;
      obj->sub3 = obj->sub3 + 1;
      Anim_Set(obj,0xb);
      return;
    }
    if (bVar1 != 2) {
      return;
    }
    iVar2 = 0x20700;
  }
  obj->speed_y_up = iVar2;
  return;
}


// ---- 801db118 FUN_801db118

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db118(MM8Obj *obj)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)&obj->field_0x58;
  FUN_801db2f8(obj,1);
  FUN_801db394(obj,0);
  if (((((byte)obj->field_0x41 - 0x14 < 3) || (obj->field_0x41 == '\x1a')) ||
      ((byte)obj->field_0x42 - 0x14 < 3)) || (obj->field_0x42 == '\x1a')) {
    obj->accel_x = 0x2000;
  }
  if (obj->accel_x < 1) {
    uVar1 = *(undefined4 *)(iVar2 + 4);
  }
  else {
    uVar1 = *(undefined4 *)(iVar2 + 8);
  }
  FUN_801db228(obj,uVar1);
  Anim_Step(obj);
  return;
}


// ---- 801db1e0 FUN_801db1e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db1e0(MM8Obj *obj)

{
  FUN_80108e84();
  if (obj->var != 2) {
    FUN_8012a5fc(obj,6);
  }
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801db228 FUN_801db228

void FUN_801db228(int param_1,int param_2)

{
  if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == (param_2 - *(int *)(param_1 + 0x14) & 0x80000000U)
     ) {
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + *(uint *)(param_1 + 0x1c);
  }
  else {
    *(int *)(param_1 + 0x14) = param_2;
  }
  FUN_80104ccc(param_1);
  return;
}


// ---- 801db278 FUN_801db278

void FUN_801db278(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 10;
    puVar1[7] = 2;
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(int *)(puVar1 + 0x10) = *(int *)(param_1 + 0x10) + -0x80000;
    *(undefined4 *)(puVar1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
    puVar1[0x25] = *(byte *)(param_1 + 0x25) ^ 0x40;
  }
  return;
}


// ---- 801db2f8 FUN_801db2f8

byte FUN_801db2f8(int param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  FUN_80106214();
  bVar1 = *(byte *)(param_1 + 0x33);
  if ((bVar1 & 0x30) != 0) {
    if (param_2 == 0) {
      *(undefined1 *)(param_1 + 2) = 7;
      *(undefined1 *)(param_1 + 3) = 0;
      if ((bVar1 & 0x80) == 0) {
        uVar2 = 0xfffffc00;
      }
      else {
        uVar2 = 0x38800;
      }
      *(undefined4 *)(param_1 + 0x18) = uVar2;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 3;
    }
    FUN_801db440(param_1,6,2);
    bVar1 = 0;
  }
  return bVar1;
}


// ---- 801db394 FUN_801db394

void FUN_801db394(int param_1,int param_2)

{
  if ((*(byte *)(param_1 + 0x33) & 0x80) == 0) {
    if (*(char *)(param_1 + 0x56) == '\0') {
      *(undefined4 *)(param_1 + 0x20) = 0x4000;
      if (param_2 == 0) {
        *(undefined4 *)(param_1 + 0x18) = 0xfffffc00;
      }
      else {
        *(undefined4 *)(param_1 + 0x18) = 0x2e000;
        FUN_8010544c(param_1,0x7c);
      }
      *(char *)(param_1 + 0x56) = *(char *)(param_1 + 0x56) + '\x01';
      if (*(char *)(param_1 + 0x57) == '\0') {
        *(undefined1 *)(param_1 + 0x57) = 1;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined1 *)(param_1 + 0x56) = 0;
    if (*(char *)(param_1 + 0x57) == '\x01') {
      *(undefined1 *)(param_1 + 0x57) = 0;
    }
  }
  return;
}


// ---- 801db440 FUN_801db440

void FUN_801db440(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    if (param_3 == 0) {
      trap(0x1c00);
    }
    if (DAT_80170574 % param_3 != 0) {
      return;
    }
  }
  if ((*(char *)(param_1 + 0x56) == '\0') && (*(char *)(param_1 + 0x43) == '\0')) {
    iVar1 = (param_2 & 0xff) * 2;
    FUN_8012c8ec(param_1,(int)(char)(&DAT_801e67d8)[iVar1],(int)(char)(&DAT_801e67d9)[iVar1]);
  }
  return;
}


// ---- 801db4cc FUN_801db4cc

void FUN_801db4cc(int param_1)

{
  byte bVar1;
  
  if (*(char *)(param_1 + 0x30) == '\t') {
    bVar1 = *(byte *)(param_1 + 0x32);
    if ((bVar1 & 0x7f) != 0) {
      FUN_801db440(param_1,(bVar1 & 0x7f) - 1,2);
    }
    if ((((bVar1 & 0x80) != 0) && (*(char *)(param_1 + 0x56) == '\0')) &&
       (*(char *)(param_1 + 0x43) == '\0')) {
      FUN_801db56c(param_1,0x7b);
      *(byte *)(param_1 + 0x32) = *(byte *)(param_1 + 0x32) & 0x7f;
    }
  }
  return;
}


// ---- 801db56c FUN_801db56c

void FUN_801db56c(int param_1,undefined1 param_2)

{
  if ((*(char *)(param_1 + 0x56) == '\0') && (*(char *)(param_1 + 0x43) == '\0')) {
    FUN_8010544c(param_1,param_2);
  }
  return;
}


// ---- 801db6b8 FUN_801db6b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db6b8(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->state = 1;
  obj->draw_list = 8;
  obj->flip = obj->var & 0x40;
  obj->sub2 = 0;
  obj->field_0x50 = 0;
  obj->field_0x51 = 0;
  obj->field_0x54 = 0;
  obj->field_0x5f = 0;
  obj->field_0x53 = (char)obj->x;
  obj->field_0x52 = (char)((ushort)obj->x >> 8);
  obj->var = obj->var & 1;
  (*(code *)(&PTR_FUN_801e6860)[obj->state])(obj);
  return;
}


// ---- 801db750 FUN_801db750

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db750(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (obj->sub2 == 0) {
    uVar4 = 0xc;
    if ((obj->var & 0xf) != 0) {
      uVar4 = 7;
    }
    Anim_Set(obj,uVar4);
    obj->sub2 = obj->sub2 + 1;
  }
  sVar2 = DAT_8015e272;
  sVar1 = DAT_8015e24c._2_2_;
  if ((obj->var & 0xf) == 0) {
    if (obj->field_0x54 != '\0') {
      obj->field_0x54 = 0;
      obj->state = 3;
      obj->sub2 = 0;
    }
  }
  else {
    obj->box2 = &DAT_801e6880;
    if (sVar2 < sVar1) {
      iVar3 = FUN_80107bf4(obj,&g_player,0);
      if ((iVar3 != 0) && (FUN_801082e0(obj,&g_player), (DAT_801c3360 & 0x80) != 0)) {
        obj->state = 2;
        obj->sub2 = 0;
        FUN_8010544c(obj,0x2b);
      }
    }
    else if (sVar1 == sVar2) {
      FUN_80107bf4(obj,&g_player,5);
    }
  }
  return;
}


// ---- 801db894 FUN_801db894

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db894(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    Anim_Set(obj,8);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      obj->state = 3;
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801db914 FUN_801db914

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db914(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0xc);
    if ((obj->var & 1) == 0) {
      obj->state = 4;
      obj->sub2 = 0;
      return;
    }
    obj->field_0x50 = 0xc;
    obj->field_0x51 = 0;
    obj->sub2 = obj->sub2 + 1;
    FUN_8010544c(obj,0xfe);
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->state = 4;
      obj->sub2 = 0;
    }
  }
  if ((&DAT_801e6878)[(byte)obj->field_0x51 >> 1] != '\x7f') {
    if ((obj->field_0x51 & 1) == 0) {
      obj->x = obj->x + (short)(char)(&DAT_801e6878)[(byte)obj->field_0x51 >> 1];
    }
    obj->field_0x51 = obj->field_0x51 + '\x01';
  }
  return;
}


// ---- 801dba18 FUN_801dba18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba18(MM8Obj *obj)

{
  undefined1 *puVar1;
  char cVar2;
  byte bVar3;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,9);
    obj->field_0x50 = 0x32;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 == '\0') {
      bVar3 = 5;
      if ((obj->var & 1) == 0) {
        bVar3 = 1;
      }
      obj->state = bVar3;
      obj->sub2 = 0;
    }
  }
  if ((obj->frame == 0x17) && (obj->anim_timer == 1)) {
    DAT_801e70cc = (undefined1 *)Obj_AllocType3();
    if (DAT_801e70cc != (undefined1 *)0x0) {
      DAT_801e70cc[1] = 0;
      DAT_801e70cc[0x27] = 0x1c;
      DAT_801e70cc[0x25] = obj->flip;
      DAT_801e70cc[0x38] = 0;
      DAT_801e70cc[0x39] = 10;
      DAT_801e70cc[7] = 0;
      *DAT_801e70cc = 1;
      DAT_801e70cc[6] = 0xf;
      DAT_801e70cc[0x26] = 7;
      puVar1 = DAT_801e70cc;
      *(short *)(DAT_801e70cc + 0xe) = obj->x;
      *(short *)(puVar1 + 0x12) = obj->y;
    }
  }
  return;
}


// ---- 801dbb90 FUN_801dbb90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbb90(MM8Obj *obj)

{
  Anim_Set(obj,0xb);
  obj->state = 1;
  obj->sub2 = 0;
  return;
}


