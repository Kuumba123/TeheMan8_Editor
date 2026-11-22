// ID 5C, STAGE0D.BIN, handler 0x801F4E00. Ghidra output with the object struct applied; not matching C.
// ---- 801f4e00 FUN_801f4e00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4e00(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f90dc)[obj->var])();
  return;
}


// ---- 801f4e3c FUN_801f4e3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4e3c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f9130)[obj->state])();
  if (DAT_801b29a0 == -1) {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,3);
    Obj_Free(obj);
  }
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    Enemy_ContactDamage(obj);
    Enemy_CheckWeaponHits(obj);
  }
  return;
}


// ---- 801f4edc FUN_801f4edc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4edc(MM8Obj *obj)

{
  FUN_801f72b4();
  Enemy_InitFromTable(obj);
  obj->draw_list = 6;
  obj->contact_dmg = 4;
  obj->hitbox = &DAT_801f90b0;
  obj->state = 1;
  obj->flip = 0;
  obj->hp = 1;
  obj->box2 = &DAT_801f90c4;
  Anim_Set(obj,0x16);
  return;
}


// ---- 801f4f50 FUN_801f4f50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4f50(MM8Obj *obj)

{
  FUN_801f72b4();
  if (DAT_801b29a0 != '\0') {
    obj->state = 2;
    obj->field_0x54 = 1;
  }
  return;
}


// ---- 801f4f98 FUN_801f4f98

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4f98(MM8Obj *obj)

{
  byte bVar1;
  
  FUN_801f72b4();
  obj->field_0x54 = obj->field_0x54 + -1;
  if (obj->field_0x54 == '\0') {
    bVar1 = Rand();
    obj->state = (bVar1 & 3) + 3;
  }
  return;
}


// ---- 801f4ff4 FUN_801f4ff4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f4ff4(MM8Obj *obj)

{
  FUN_801f72b4();
  (*(code *)(&PTR_FUN_801f914c)[obj->sub2])(obj);
  return;
}


// ---- 801f5040 FUN_801f5040

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5040(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    obj->sub3 = 1;
    obj->field_0x54 = 0x50;
    Anim_Set();
    FUN_8010544c(obj,0x1c8);
  }
  else {
    Anim_Step(obj,0x17);
    obj->field_0x54 = obj->field_0x54 + -1;
    if (obj->field_0x54 == '\0') {
      obj->sub2 = 1;
      obj->sub3 = 0;
      obj->field_0x54 = 0xb4;
    }
  }
  return;
}


// ---- 801f50d4 FUN_801f50d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f50d4(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  byte unaff_s2;
  int iVar3;
  
  Anim_Step();
  bVar1 = obj->field_0x54 - 1;
  obj->field_0x54 = bVar1;
  if (obj->field_0x54 == '\0') {
    obj->sub2 = 2;
    Anim_Set(obj,0x19);
  }
  else if ((bVar1 & 0x1f) == 0) {
    puVar2 = (undefined1 *)FUN_801055e4(obj);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x5c;
      puVar2[7] = 1;
      bVar1 = Rand();
      unaff_s2 = (bVar1 & 0xf) + 0xb8;
      puVar2[4] = unaff_s2;
      *(MM8Obj **)(puVar2 + 0x50) = obj;
    }
    if (unaff_s2 < 0xc4) {
      iVar3 = 2;
      if (0xbc < unaff_s2) {
        iVar3 = 1;
      }
    }
    else {
      iVar3 = 0;
    }
    puVar2 = (undefined1 *)FUN_801055e4(obj);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 1;
      puVar2[6] = 0x5c;
      puVar2[7] = 9;
      iVar3 = iVar3 * 4;
      puVar2[0x26] = 5;
      puVar2[4] = (&DAT_801f90d3)[iVar3];
      puVar2[0x25] = (&DAT_801f90d2)[iVar3];
      *(short *)(puVar2 + 0xe) = (short)(char)(&DAT_801f90d0)[iVar3] + obj->x;
      *(short *)(puVar2 + 0x12) = (short)(char)(&DAT_801f90d1)[iVar3] + obj->y;
    }
  }
  return;
}


// ---- 801f524c FUN_801f524c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f524c(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    obj->state = 2;
    obj->sub2 = 0;
    obj->field_0x54 = 0x3c;
  }
  return;
}


// ---- 801f5294 FUN_801f5294

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5294(MM8Obj *obj)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  FUN_801f72b4();
  switch(obj->sub2) {
  case 0:
    obj->sub2 = 1;
    uVar1 = 0x14;
    goto LAB_801f542c;
  case 1:
    Anim_Step(obj);
    obj->field_0x54 = obj->field_0x54 + -1;
    if (obj->field_0x54 != '\0') {
      return;
    }
    uVar3 = 0x18;
    obj->sub2 = 2;
    uVar1 = 0x14;
    goto LAB_801f547c;
  case 2:
    Anim_Step(obj);
    obj->field_0x54 = obj->field_0x54 + -1;
    if (obj->field_0x54 == '\0') {
      obj->sub2 = 3;
      obj->field_0x54 = 0x14;
      puVar2 = (undefined1 *)FUN_801055e4(obj);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x5c;
        puVar2[7] = 2;
        *(short *)(puVar2 + 0xe) = obj->x + -2;
        *(short *)(puVar2 + 0x12) = obj->y + -0x20;
      }
      puVar2 = (undefined1 *)FUN_801055e4(obj);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x5c;
        puVar2[7] = 9;
        puVar2[4] = 0x47;
        puVar2[0x25] = 0;
        *(short *)(puVar2 + 0xe) = obj->x + -2;
        *(short *)(puVar2 + 0x12) = obj->y + -0x20;
      }
    }
    break;
  case 3:
    obj->field_0x54 = obj->field_0x54 + -1;
    if (obj->field_0x54 != '\0') {
      return;
    }
    obj->sub2 = 4;
    uVar1 = 10;
LAB_801f542c:
    obj->field_0x54 = uVar1;
    Anim_Set(obj,0x17);
    FUN_8010544c(obj,0x1c8);
    break;
  case 4:
    obj->field_0x54 = obj->field_0x54 + -1;
    Anim_Step(obj);
    if (obj->field_0x54 != '\0') {
      return;
    }
    uVar3 = 0x19;
    obj->sub2 = 5;
    uVar1 = 10;
LAB_801f547c:
    obj->field_0x54 = uVar1;
    Anim_Set(obj,uVar3);
    break;
  case 5:
    obj->field_0x54 = obj->field_0x54 + -1;
    Anim_Step(obj);
    if (obj->field_0x54 == '\0') {
      obj->state = 2;
      obj->sub2 = 0;
      obj->field_0x54 = 1;
    }
  }
  return;
}


// ---- 801f54d4 FUN_801f54d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f54d4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f9158)[obj->sub2])();
  return;
}


// ---- 801f5510 FUN_801f5510

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5510(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    obj->sub3 = 1;
    obj->field_0x54 = 0x3c;
    Anim_Set(obj,0x1a);
    FUN_8010544c(obj,0x1c8);
  }
  Anim_Step(obj);
  FUN_801f72b4(obj);
  obj->field_0x54 = obj->field_0x54 + -1;
  if (obj->field_0x54 == '\0') {
    obj->speed_y_up = 0x4fcf3;
    obj->sub2 = 1;
    obj->sub3 = 0;
    obj->speed_x = 0;
    obj->gravity = 0x4000;
    FUN_8010544c(obj,0x1c9);
  }
  return;
}


// ---- 801f55c0 FUN_801f55c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f55c0(MM8Obj *obj)

{
  Anim_Step();
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->sub2 = 2;
    obj->field_0x54 = 0x14;
    Anim_Set(obj,0x1b);
    FUN_8010544c(obj,0x1ca);
  }
  return;
}


// ---- 801f5630 FUN_801f5630

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5630(MM8Obj *obj)

{
  Anim_Step();
  obj->field_0x54 = obj->field_0x54 + -1;
  if (obj->field_0x54 == '\0') {
    obj->sub2 = 3;
    obj->speed_x = 0;
    obj->speed_y_up = 0;
    obj->accel_x = -0x4000;
  }
  return;
}


// ---- 801f568c FUN_801f568c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f568c(MM8Obj *obj)

{
  Anim_Step();
  FUN_80104c9c(obj);
  if (obj->speed_x < -0x7ffff) {
    obj->accel_x = 0;
  }
  if (obj->x < DAT_801d2918._2_2_) {
    obj->sub2 = 4;
    obj->field_0x54 = 0x3c;
  }
  return;
}


// ---- 801f56fc FUN_801f56fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f56fc(MM8Obj *obj)

{
  Anim_Step();
  obj->field_0x54 = obj->field_0x54 + -1;
  if (obj->field_0x54 == '\0') {
    obj->sub2 = 5;
    obj->accel_x = 0x2000;
    obj->speed_x = 0;
                    /* Possible PsyQ macro: setLineF2() */
    obj->flip = 0x40;
  }
  return;
}


// ---- 801f575c FUN_801f575c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f575c(MM8Obj *obj)

{
  short sVar1;
  
  Anim_Step();
  FUN_80104c9c(obj);
  if (DAT_801d2918._2_2_ + 0x200 < (int)obj->x) {
    obj->sub2 = obj->sub2 + 1;
    obj->x = *(short *)(*(int *)&obj->field_0x50 + 0xe);
    sVar1 = g_cam_y;
    obj->speed_y_up = -0x60000;
    obj->y = sVar1 + -0x40;
  }
  return;
}


// ---- 801f57dc FUN_801f57dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f57dc(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = *(int *)&obj->field_0x50;
  Anim_Step();
  FUN_80104d18(obj);
  if (*(short *)(iVar1 + 0x12) < obj->y) {
    obj->flip = 0;
    obj->sub2 = obj->sub2 + 1;
    obj->y = *(short *)(iVar1 + 0x12);
    Anim_Set(obj,0x19);
    FUN_8010544c(obj,0x1cb);
  }
  return;
}


// ---- 801f5860 FUN_801f5860

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5860(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    obj->state = 2;
    obj->sub2 = 0;
    obj->field_0x54 = 0x3c;
  }
  return;
}


// ---- 801f58a8 FUN_801f58a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f58a8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f9178)[obj->sub2])();
  return;
}


// ---- 801f58e4 FUN_801f58e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f58e4(MM8Obj *obj)

{
  Anim_Step();
  if ((short)obj->frame < 0) {
    obj->sub2 = 3;
    obj->speed_x = -0x30000;
    obj->speed_y_up = 0x4fcf3;
    obj->gravity = 0x4000;
    FUN_8010544c(obj,0x1c9);
  }
  return;
}


// ---- 801f5948 FUN_801f5948

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5948(MM8Obj *obj)

{
  short sVar1;
  
  Anim_Step();
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) == 0) {
    if ((int)obj->x < DAT_801d2918._2_2_ + -0x40) {
      obj->sub2 = 4;
      obj->x = *(short *)(*(int *)&obj->field_0x50 + 0xe);
      sVar1 = g_cam_y;
      obj->speed_y_up = -0x60000;
      obj->y = sVar1 + -0x40;
    }
  }
  else {
    obj->sub2 = 2;
    Anim_Set(obj,0x1b);
    FUN_8010544c(obj,0x1ca);
  }
  return;
}


// ---- 801f5a00 FUN_801f5a00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5a00(MM8Obj *obj)

{
  if (obj->state == 0) {
    Enemy_InitFromTable();
    obj->state = 1;
    obj->hitbox = &DAT_801f90b4;
    obj->contact_dmg = 3;
    obj->flip = 0;
    obj->draw_list = 6;
    Anim_Set(obj,0xb);
    FUN_8010544c(obj,0x1cc);
    FUN_801f72b4(obj);
    FUN_80105120(obj,0x400,obj->field_0x4);
    FUN_80104c34(obj);
    FUN_80104c34(obj);
    FUN_80104c34(obj);
    FUN_80104c34(obj);
  }
  FUN_80104c34(obj);
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  if (obj->on_screen == 0) {
    Obj_Free(obj);
  }
  else {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801f5af4 FUN_801f5af4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5af4(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  
  bVar1 = obj->state;
  if (bVar1 == 1) {
    Anim_Step(obj);
    FUN_80104d18(obj);
    if ((int)obj->y < g_cam_y + -0x80) {
      obj->state = 2;
      obj->speed_y_up = -0x60000;
      obj->x = DAT_8015e248._2_2_;
      obj->y = g_cam_y + -0x20;
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      Enemy_InitFromTable(obj);
      obj->state = 1;
      obj->draw_list = 6;
      obj->contact_dmg = 5;
      obj->hitbox = &DAT_801f90b8;
      obj->box2 = &DAT_801f90c9;
      obj->flip = 0;
      obj->speed_y_up = 0x80000;
      Anim_Set(obj,8);
      FUN_8010544c(obj,0x1cd);
    }
  }
  else if (bVar1 == 2) {
    Anim_Step(obj);
    FUN_80104d18(obj);
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->state = 3;
      Anim_Set(obj,9);
      puVar2 = (undefined1 *)FUN_801055e4(obj);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x5c;
        puVar2[7] = 3;
        puVar2[4] = 0;
        *(short *)(puVar2 + 0xe) = obj->x;
        *(short *)(puVar2 + 0x12) = obj->y;
      }
      puVar2 = (undefined1 *)FUN_801055e4(obj);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x5c;
        puVar2[7] = 3;
        puVar2[4] = 1;
        *(short *)(puVar2 + 0xe) = obj->x;
        *(short *)(puVar2 + 0x12) = obj->y;
      }
      FUN_8010544c(obj,0x1ce);
    }
  }
  else if ((bVar1 == 3) && (Anim_Step(obj), (short)obj->frame < 0)) {
    Obj_Free(obj);
  }
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801f5d38 FUN_801f5d38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5d38(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->state == 0) {
    Enemy_InitFromTable();
    obj->state = 1;
    obj->hitbox = &DAT_801f90b4;
    obj->draw_list = 7;
    obj->flip = 0;
    obj->contact_dmg = 5;
    if (obj->field_0x4 == '\0') {
      iVar1 = -0x60000;
    }
    else {
      iVar1 = 0x60000;
    }
    obj->speed_x = iVar1;
    Anim_Set(obj,10);
  }
  Anim_Step(obj);
  FUN_80104d00(obj);
  Obj_CullAndQueueDraw(obj);
  if (obj->on_screen == 0) {
    Obj_Free(obj);
  }
  else {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801f5e00 FUN_801f5e00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5e00(MM8Obj *obj)

{
  if (obj->state == 0) {
    Enemy_InitFromTable();
    obj->state = 1;
    obj->flip = 0;
    obj->draw_list = 7;
    obj->invuln = 1;
    Anim_Set(obj,0x1d);
  }
  FUN_801f72b4(obj);
  obj->x = obj->x + 0x34;
  obj->y = obj->y + 0x12;
  Anim_Step(obj);
  if (DAT_801b29a0 == -1) {
    Obj_Free(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801f5eb4 FUN_801f5eb4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f5eb4(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  
  FUN_801f72b4();
  obj->x = obj->x + -0x30;
  obj->y = obj->y + 6;
  if (DAT_801b29a0 == -1) {
LAB_801f6010:
    Obj_Free(obj);
  }
  else {
    bVar1 = obj->state;
    if (bVar1 == 1) {
      Anim_Step(obj);
      if (DAT_801b29a1 == '\0') goto LAB_801f6010;
      if (DAT_801b29a1 == '\x02') {
        obj->state = 2;
        Anim_Set(obj,0xd);
        puVar2 = (undefined1 *)FUN_801055e4(obj);
        if (puVar2 != (undefined1 *)0x0) {
          *puVar2 = 1;
          puVar2[6] = 0x5c;
          puVar2[7] = 6;
          *(undefined4 *)(puVar2 + 0x50) = *(undefined4 *)&obj->field_0x50;
        }
        puVar2 = (undefined1 *)FUN_801055e4(obj);
        if (puVar2 != (undefined1 *)0x0) {
          puVar2[6] = 0x5c;
          *puVar2 = 1;
          puVar2[7] = 6;
          puVar2[4] = 1;
          *(undefined4 *)(puVar2 + 0x50) = *(undefined4 *)&obj->field_0x50;
        }
      }
    }
    else if (bVar1 < 2) {
      if (bVar1 == 0) {
        Enemy_InitFromTable(obj);
        obj->state = 1;
        obj->flip = 0;
        Anim_Set(obj,0xc);
      }
    }
    else if ((bVar1 == 2) && (Anim_Step(obj), (short)obj->frame < 0)) goto LAB_801f6010;
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801f603c FUN_801f603c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f603c(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  
  FUN_801f72b4();
  if (obj->field_0x4 == '\0') {
    sVar2 = obj->x + -0x30;
  }
  else {
    sVar2 = obj->x + -0xf0;
  }
  obj->x = sVar2;
  bVar1 = obj->state;
  obj->y = obj->y + 6;
  if (bVar1 == 1) {
    Anim_Step(obj);
    if ((DAT_801b29a0 == -1) || (DAT_801b29a1 == '\0')) {
      obj->state = 2;
      Anim_Set(obj,(byte)obj->field_0x4 + 0x10);
    }
    else {
      Enemy_ContactDamage(obj);
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      Enemy_InitFromTable(obj);
      obj->state = 1;
      obj->draw_list = 6;
      obj->contact_dmg = 6;
      obj->flip = 0;
      obj->hitbox = &UNK_801f90bc + (uint)(byte)obj->field_0x4 * 4;
      Anim_Set(obj,(byte)obj->field_0x4 + 0xe);
    }
  }
  else if ((bVar1 == 2) && (Anim_Step(obj), (short)obj->frame < 0)) {
    Obj_Free(obj);
    return;
  }
  Obj_CullAndQueueDrawMargin(obj,0x60);
  return;
}


// ---- 801f61b4 FUN_801f61b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f61b4(MM8Obj *obj)

{
  if (DAT_801b29a0 == -1) {
    if (obj->state == 0) {
      Enemy_InitFromTable(obj);
      obj->state = 1;
      obj->draw_list = 6;
      Anim_Set(obj,0x1c);
    }
    else {
      Anim_Step(obj);
      Obj_CullAndQueueDraw(obj);
    }
  }
  else {
    Obj_Free();
  }
  return;
}


// ---- 801f6244 FUN_801f6244

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6244(MM8Obj *obj)

{
  if (DAT_801b29a0 == -1) {
    Obj_CullAndQueueDraw();
  }
  else {
    Obj_Free();
  }
  return;
}


// ---- 801f6284 FUN_801f6284

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6284(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 != 0) {
    iVar1 = *(int *)&obj->field_0x50;
    obj->x = *(short *)(iVar1 + 0xe);
    obj->y = *(short *)(iVar1 + 0x12);
    obj->flip = *(byte *)(iVar1 + 0x25);
  }
  if (obj->state == 0) {
    Enemy_InitFromTable(obj);
    obj->state = 1;
    obj->clut = obj->clut + obj->sub3;
    Anim_Set(obj,obj->field_0x4);
  }
  else {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      Obj_Free(obj);
      return;
    }
  }
  Obj_CullAndQueueDrawMargin(obj,0x30);
  return;
}


// ---- 801f6358 FUN_801f6358

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6358(MM8Obj *obj)

{
  if (DAT_801b29a0 == -1) {
    Obj_Free();
  }
  (*(code *)(&PTR_FUN_801f9190)[obj->state])(obj);
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  if ((obj->on_screen == 0) && (obj->state == 5)) {
    Obj_Free(obj);
  }
  else {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801f6400 FUN_801f6400

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6400(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->state = 1;
  obj->field_0x54 = 0xf;
  obj->draw_list = 7;
  obj->contact_dmg = 3;
  obj->hitbox = &DAT_801f90b4;
  FUN_80105120(obj,0x600,((byte)obj->field_0x4 & 3) << 6 | 0x20);
  Anim_Set(obj,10);
  return;
}


// ---- 801f647c FUN_801f647c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f647c(MM8Obj *obj)

{
  FUN_80104c34();
  obj->field_0x54 = obj->field_0x54 + -1;
  if (obj->field_0x54 == '\0') {
    obj->field_0x54 = 0x14;
    obj->state = obj->state + 1;
  }
  return;
}


// ---- 801f64d4 FUN_801f64d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Possible GS_106.OBJ/GsSetProjection
   Possible _OP_VDEL.OBJ/__builtin_vec_delete
   Possible _OP_VNEW.OBJ/__builtin_vec_new
   Possible SCNOFF.OBJ/SsSetNoiseOff
   Possible SSQUIT.OBJ/SsQuit */

void FUN_801f64d4(MM8Obj *obj)

{
  FUN_80104c34();
  return;
}


// ---- 801f64f4 FUN_801f64f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f64f4(MM8Obj *obj)

{
  undefined1 uVar1;
  
  obj->field_0x54 = obj->field_0x54 + -1;
  if (obj->field_0x54 == '\0') {
    obj->field_0x54 = 0xf;
    obj->state = obj->state + 1;
    uVar1 = FUN_801050e4(obj,&g_player);
    FUN_80105120(obj,0x600,uVar1);
    if (obj->field_0x4 == '\0') {
      FUN_800fd100(0x1e0);
    }
  }
  return;
}


// ---- 801f657c FUN_801f657c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f657c(MM8Obj *obj)

{
  if (obj->state == 0) {
    Enemy_InitFromTable();
    obj->state = 1;
    obj->draw_list = 7;
    obj->contact_dmg = 3;
    obj->field_0x4 = obj->field_0x4 << 6;
    obj->hitbox = &DAT_801f90b4;
    FUN_80105120(obj,0x1000,obj->field_0x4);
    FUN_80104c34(obj);
    Anim_Set(obj,10);
    obj->accel_x = 0x400;
  }
  obj->accel_x = obj->accel_x + 0x20;
  obj->field_0x4 = obj->field_0x4 + '\x03';
  FUN_80105120(obj,(short)obj->accel_x,obj->field_0x4);
  FUN_80104c34(obj);
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  if (obj->on_screen == 0) {
    Obj_Free(obj);
  }
  else {
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801f6680 FUN_801f6680

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6680(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f91a8)[obj->state])();
  if (obj->active != 0) {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
    Enemy_ContactDamage(obj);
  }
  return;
}


// ---- 801f66f0 FUN_801f66f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f66f0(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->state = 1;
  obj->draw_list = 7;
  obj->flip = 0;
  obj->accel_x = 0;
  obj->hitbox = &DAT_801f90b4;
  *(short *)&obj->field_0x56 = obj->x;
  *(short *)&obj->field_0x58 = obj->y;
  obj->sub2 = obj->field_0x4;
  obj->field_0x4 = obj->field_0x4 << 5;
  Anim_Set(obj,10);
  return;
}


// ---- 801f676c FUN_801f676c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f676c(MM8Obj *obj)

{
  obj->field_0x4 = obj->field_0x4 + '\x03';
  obj->accel_x = obj->accel_x + 0x100;
  obj->x = *(short *)&obj->field_0x56;
  obj->y = *(short *)&obj->field_0x58;
  FUN_80105120(obj,(short)obj->accel_x,obj->field_0x4);
  FUN_80104c34(obj);
  if (0x4000 < obj->accel_x) {
    obj->state = 2;
  }
  return;
}


// ---- 801f67e4 FUN_801f67e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f67e4(MM8Obj *obj)

{
  obj->field_0x4 = obj->field_0x4 + '\x03';
  obj->y = *(short *)&obj->field_0x58;
  obj->x = *(short *)&obj->field_0x56;
  FUN_80105120(obj,(short)obj->accel_x,obj->field_0x4);
  FUN_80104c34(obj);
  obj->sub3 = obj->sub3 - 1;
  if (obj->sub3 == 0) {
    obj->state = 3;
    obj->field_0x4 = obj->field_0x4 + -0x40;
    obj->field_0x54 = 0x1e;
    FUN_80105120(obj,0x800,obj->field_0x4);
  }
  return;
}


// ---- 801f6880 FUN_801f6880

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6880(MM8Obj *obj)

{
  if (obj->field_0x54 == '\0') {
    FUN_80104c34(obj);
    if (obj->on_screen == 0) {
      Obj_Free(obj);
    }
  }
  else {
    obj->field_0x54 = obj->field_0x54 + -1;
    if ((obj->field_0x54 == '\0') && (obj->sub2 == 0)) {
      FUN_800fd100(0x1e0);
    }
  }
  return;
}


// ---- 801f6914 FUN_801f6914

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6914(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801f91b8)[obj->state])();
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801f696c FUN_801f696c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f696c(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->state = 1;
  obj->draw_list = 9;
  obj->x = 0x9d0;
  obj->y = 0xcb8;
  obj->speed_x = -0x20000;
  obj->flip = 0;
  obj->speed_y_up = 0x20000;
  Anim_Set(obj,1);
  FUN_8010544c(obj,0x1ed);
  return;
}


// ---- 801f69e0 FUN_801f69e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f69e0(MM8Obj *obj)

{
  FUN_80104c34();
  if (obj->x < 0x960) {
    obj->state = 2;
    DAT_801b29a2 = 1;
  }
  return;
}


// ---- 801f6b68 FUN_801f6b68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6b68(MM8Obj *obj)

{
  byte bVar1;
  undefined1 uVar2;
  short sVar3;
  uint uVar4;
  
  bVar1 = obj->state;
  if (bVar1 == 1) {
    FUN_80104c34(obj);
    obj->field_0x54 = obj->field_0x54 + -1;
    if (obj->field_0x54 == '\0') {
      obj->state = 2;
      obj->x = DAT_8015e248._2_2_;
      obj->y = DAT_8015e24c._2_2_;
      DAT_801b29a2 = '\x01';
      FUN_80111f68(0x1e,0x40);
      FUN_8010544c(obj,0x1e3);
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      Enemy_InitFromTable(obj);
      obj->state = 1;
      obj->draw_list = 5;
      obj->x = DAT_801d2918._2_2_ + 0x100;
      obj->y = g_cam_y + -0x20;
      uVar2 = FUN_801050e4(obj,&g_player);
      FUN_80105120(obj,0x800,uVar2);
      sVar3 = FUN_801054b4((int)obj->x,(int)obj->y,(int)DAT_8015e248._2_2_,(int)DAT_8015e24c._2_2_);
      uVar4 = (uint)sVar3;
      if ((int)uVar4 < 0) {
        uVar4 = uVar4 + 7;
      }
      obj->field_0x54 = (char)(uVar4 >> 3);
      Anim_Set(obj,0);
      FUN_8010544c(obj,0x1e2);
    }
  }
  else if ((bVar1 == 2) && (DAT_801b29a2 == '\0')) {
    FUN_80111f68(2,0x40);
    Obj_Free(obj);
    return;
  }
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801f6d28 FUN_801f6d28

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6d28(MM8Obj *obj)

{
  byte bVar1;
  
  if (obj->state == 0) {
    obj->state = 1;
                    /* Possible PsyQ macro: setPolyGT3() */
    obj->bank = 0x34;
    obj->vram_base = DAT_801703b0;
    bVar1 = DAT_80159f98;
    obj->flip = 0;
    obj->draw_list = 0;
    obj->clut = bVar1;
    Anim_Set(obj,0);
    Obj_CullAndQueueDraw(obj);
  }
  Anim_Step(obj);
  if ((short)obj->frame < 0) {
    Obj_Free(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801f6dcc FUN_801f6dcc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6dcc(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  
  FUN_801f72b4();
  obj->y = obj->y + 0x1d;
  bVar1 = obj->state;
  obj->x = obj->x + -0x4c;
  if (bVar1 == 1) {
    Anim_Step(obj);
    if (DAT_801b29a1 != '\0') {
      obj->state = 2;
      Anim_Set(obj,3);
      FUN_8010544c(obj,0x1e7);
      puVar2 = (undefined1 *)FUN_801055e4(obj);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x5c;
        puVar2[7] = 0x11;
        *(undefined4 *)(puVar2 + 0x50) = *(undefined4 *)&obj->field_0x50;
      }
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      Enemy_InitFromTable(obj);
      obj->state = 1;
      obj->flip = 0;
      Anim_Set(obj,2);
      FUN_8010544c(obj,0x1e6);
    }
  }
  else if ((bVar1 == 2) && (Anim_Step(obj), (short)obj->frame < 0)) {
    Obj_Free(obj);
    return;
  }
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801f6f18 FUN_801f6f18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6f18(MM8Obj *obj)

{
  FUN_801f72b4();
  obj->x = obj->x + -0xcc;
  obj->y = obj->y + 0x1d;
  if (obj->state == 0) {
    Enemy_InitFromTable(obj);
    obj->state = 1;
    obj->draw_list = 5;
    obj->flip = 0;
    Anim_Set(obj,0x20);
  }
  if (DAT_801b29a1 < 0x10) {
    if (obj->field_0x4 != DAT_801b29a1) {
      obj->field_0x4 = DAT_801b29a1;
      Anim_Set(obj,(byte)obj->field_0x4 + 0x20);
    }
    Anim_Step(obj);
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801f6ff8 FUN_801f6ff8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f6ff8(MM8Obj *obj)

{
  FUN_801f72b4();
  obj->x = obj->x + 0x30;
  if (obj->state == 0) {
    Enemy_InitFromTable(obj);
    obj->state = 1;
    obj->flip = 0;
    obj->draw_list = 4;
    Anim_Set(obj,0x12);
  }
  Anim_Step(obj);
  if (DAT_801b29a1 < 0x11) {
    Obj_CullAndQueueDraw(obj);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801f7094 FUN_801f7094

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f7094(MM8Obj *obj)

{
  FUN_801f72b4();
  if (obj->state == 0) {
    Enemy_InitFromTable(obj);
    obj->state = 1;
    obj->flip = 0;
    obj->draw_list = 5;
    Anim_Set(obj,0x1e);
  }
  if (DAT_801c73e8 == '\b') {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  else if (DAT_801b29a0 != '\0') {
    Obj_Free(obj);
  }
  return;
}


// ---- 801f713c FUN_801f713c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801f713c(MM8Obj *obj)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  
  if (obj->state == 0) {
    Enemy_InitFromTable();
    obj->state = 1;
    obj->clut = obj->clut + 4;
    bVar1 = Rand();
    obj->flip = bVar1 & 0xc0;
    bVar1 = Rand();
    obj->draw_list = (bVar1 & 3) + 2;
    obj->gravity = 0x3000;
    obj->y = g_cam_y + -0x10;
    uVar2 = Rand();
    uVar3 = Rand();
    obj->x = DAT_801d2918._2_2_ + (uVar2 & 0xff) + (uVar3 & 0x3f);
    uVar4 = Rand();
    Anim_Set(obj,(&DAT_801f91c8)[uVar4 & 0xf]);
  }
  FUN_80104ccc(obj);
  if ((obj->sub3 == 0) && (0xcd0 < obj->y)) {
    obj->sub3 = 1;
    obj->y = 0xcd0;
    obj->speed_y_up = 0x381af;
    uVar4 = Rand();
    obj->speed_x = (uVar4 & 0x3ffff) - 0x20000;
  }
  if ((((uint)DAT_801b291c + _DAT_80170574 & 1) != 0) &&
     (Obj_CullAndQueueDraw(obj), obj->on_screen == 0)) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801f72b4 FUN_801f72b4

void FUN_801f72b4(int param_1)

{
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(*(int *)(param_1 + 0x50) + 0xe);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(*(int *)(param_1 + 0x50) + 0x12);
  return;
}


