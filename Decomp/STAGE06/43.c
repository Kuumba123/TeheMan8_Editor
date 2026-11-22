// ID 43, STAGE06.BIN, handler 0x801E19E0. Ghidra output with the object struct applied; not matching C.
// ---- 801e19e0 FUN_801e19e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e19e0(MM8Obj *obj)

{
  int iVar1;
  int iVar2;
  
  obj->clut = DAT_80159fde;
  (*(code *)(&PTR_FUN_801e5b58)[obj->state])();
  if (obj->active != 0) {
    if (obj->state < 6) {
      iVar1 = FUN_801e1ef8(obj);
      if ((iVar1 == 3) && (obj->state == 1)) {
        obj->state = 5;
        obj->sub2 = 0;
      }
      iVar2 = FUN_801e1ff8(obj);
      if ((iVar2 < 0) || (iVar1 == 4)) {
        obj->state = 6;
        obj->sub2 = 0;
      }
    }
    iVar1 = Obj_InActiveArea(obj);
    if (iVar1 == 0) {
      if (obj->var == 0) {
        FUN_80105888(obj);
                    /* Possible PsyQ macro: setLineF2() */
      }
      else {
        Obj_Free(obj);
      }
    }
    else {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801e1af8 FUN_801e1af8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1af8(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 8;
  obj->hitbox = &DAT_801e5b1c;
  obj->flip = 0;
  obj->state = 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->field_0x50 = 0;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  Anim_Set(obj,0);
  return;
}


// ---- 801e1b64 FUN_801e1b64

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1b64(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    obj->dmg_table = 1;
    obj->field_0x50 = 0x78;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->state = 2;
      obj->sub2 = 0;
    }
  }
  FUN_8010910c();
  return;
}


// ---- 801e1bd4 FUN_801e1bd4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1bd4(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
                    /* Possible PsyQ macro: setPolyF4() */
    Anim_Set(obj,1);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      obj->state = 3;
      obj->sub2 = 0;
    }
  }
  if ((obj->anim_extra & 0x80) != 0) {
    FUN_8010544c(obj,0x110);
  }
  return;
}


// ---- 801e1c60 FUN_801e1c60

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1c60(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  bVar1 = obj->sub2;
  if (bVar1 == 0) {
    Anim_Set(obj,3);
    obj->sub2 = 1;
  }
  else if (bVar1 == 1) {
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    if (iVar3 != 0) {
      FUN_801e2070(obj,0);
      FUN_801e2070(obj,1);
      FUN_801e2070(obj,2);
      obj->field_0x50 = 0x78;
      obj->field_0x52 = 0;
      obj->sub2 = obj->sub2 + 1;
    }
  }
  else if ((bVar1 == 2) && (cVar2 = obj->field_0x50 + -1, obj->field_0x50 = cVar2, cVar2 == '\0')) {
    obj->state = 4;
    obj->sub2 = 0;
  }
  if ((obj->anim_extra & 0x80) != 0) {
    FUN_8010544c(obj,0x111);
  }
  return;
}


// ---- 801e1d4c FUN_801e1d4c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1d4c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,2);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      obj->state = 1;
      obj->sub2 = 0;
    }
  }
  if ((obj->anim_extra & 0x80) != 0) {
    FUN_8010544c(obj,0x112);
  }
  return;
}


// ---- 801e1dd8 FUN_801e1dd8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1dd8(MM8Obj *obj)

{
  int iVar1;
  undefined4 uVar2;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,4);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      obj->state = 1;
      obj->sub2 = 0;
    }
  }
  if ((obj->anim_extra & 0x80) == 0) {
    uVar2 = 0x112;
    if ((obj->anim_extra & 0x40) == 0) {
      return;
    }
  }
  else {
    uVar2 = 0x110;
  }
  FUN_8010544c(obj,uVar2);
  return;
}


// ---- 801e1e78 FUN_801e1e78

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e1e78(MM8Obj *obj)

{
  undefined4 uVar1;
  
  if (obj->sub2 == 0) {
    FUN_80108e84();
    if ((obj->flip & 0x40) == 0) {
      uVar1 = 0x24;
    }
    else {
      uVar1 = 0x25;
    }
    FUN_8012ae08(obj,uVar1);
    Anim_Set(obj,6);
    obj->sub2 = obj->sub2 + 1;
  }
  return;
}


// ---- 801e1ef8 FUN_801e1ef8

int FUN_801e1ef8(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x44) = 1;
  piVar2 = (int *)(&PTR_PTR_801e5b44)[*(byte *)(param_1 + 0x32) & 0xf];
  iVar3 = *piVar2;
  do {
    *(int *)(param_1 + 0x3c) = iVar3;
    Enemy_ContactDamage(param_1);
    cVar1 = Enemy_CheckWeaponHits(param_1);
                    /* Possible PsyQ macro: setTile8() */
    if ((byte)(cVar1 - 3U) < 2) break;
    piVar2 = piVar2 + 1;
    iVar3 = *piVar2;
  } while (iVar3 != 0);
  if (cVar1 == '\x03') {
    if ((DAT_80158f5c == '\x01') && (*(char *)(DAT_8016d404 + 7) != '\0')) {
      return 3;
    }
    if (DAT_80158f5c == '\x02') {
      return 3;
    }
  }
  return (uint)(cVar1 == '\x04') << 2;
}


// ---- 801e1ff8 FUN_801e1ff8

undefined4 FUN_801e1ff8(int param_1)

{
  char cVar1;
  
  if ((*(byte *)(param_1 + 0x32) & 0xf) != 0) {
    *(undefined1 *)(param_1 + 0x44) = 2;
    *(undefined **)(param_1 + 0x3c) = &DAT_801e5b24;
    cVar1 = Enemy_CheckWeaponHits(param_1);
    if (cVar1 != '\0') {
      if (cVar1 != '\x04') {
        *(undefined1 *)(param_1 + 0x24) = 0;
        return 1;
      }
      return 0xffffffff;
    }
  }
  return 0;
}


// ---- 801e2070 FUN_801e2070

void FUN_801e2070(int param_1,byte param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocMain();
  if (puVar2 != (undefined1 *)0x0) {
    puVar2[6] = 0x43;
    *puVar2 = 1;
    puVar2[7] = param_2 + 1;
    *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    *(undefined2 *)(puVar2 + 0x12) = *(undefined2 *)(param_1 + 0x12);
    Enemy_InitFromTable(puVar2);
    puVar2[0x47] = 2;
    puVar2[0x45] = 3;
    puVar2[0x44] = 2;
    puVar2[0x43] = 1;
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    puVar2[0x26] = 7;
    *(undefined **)(puVar2 + 0x3c) = &DAT_801e5b28;
    puVar2[0x25] = uVar1;
    *(undefined **)(puVar2 + 0x38) = &DAT_801e5b2c;
    if ((puVar2[0x25] & 0x40) == 0) {
      *(undefined4 *)(puVar2 + 0x14) = 0xfffc0000;
      *(int *)(puVar2 + 0x1c) = -*(int *)(&DAT_801e5b4c + (uint)param_2 * 4);
    }
    else {
      *(undefined4 *)(puVar2 + 0x14) = 0x40000;
      *(undefined4 *)(puVar2 + 0x1c) = *(undefined4 *)(&DAT_801e5b4c + (uint)param_2 * 4);
    }
    *(undefined4 *)(puVar2 + 0x18) = 0;
    *(undefined4 *)(puVar2 + 0x20) = 0;
    puVar2[0x53] = param_2;
    puVar2[1] = 7;
    puVar2[2] = 0;
    Anim_Set(puVar2,7);
  }
  return;
}


// ---- 801e21b8 FUN_801e21b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e21b8(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  
  bVar1 = obj->sub2;
  if (bVar1 == 0) {
    Anim_Set(obj,7);
    bVar2 = obj->sub2;
    obj->field_0x50 = 6;
LAB_801e2280:
    obj->sub2 = bVar2 + 1;
  }
  else if (bVar1 == 1) {
    Anim_Step(obj);
    cVar4 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar4;
    if (cVar4 == '\0') {
      bVar2 = obj->sub2;
      goto LAB_801e2280;
    }
  }
  else if (bVar1 == 2) {
    Anim_Step(obj);
    if ((obj->flip & 0x40) == 0) {
      bVar3 = obj->speed_x < -0x30000;
    }
    else {
      bVar3 = 0x30000 < obj->speed_x;
    }
    if (!bVar3) {
      bVar2 = obj->sub2;
      obj->gravity = -0x1800;
      goto LAB_801e2280;
    }
  }
  else {
    Anim_Step(obj);
  }
  if ((obj->flip & 0x40) == 0) {
    if (obj->speed_x < 0) goto LAB_801e22d8;
    obj->speed_x = 0;
  }
  else {
    if (0 < obj->speed_x) goto LAB_801e22d8;
    obj->speed_x = 0;
  }
  obj->accel_x = 0;
LAB_801e22d8:
                    /* Possible PsyQ macro: setPolyGT4() */
  if (0x3ffff < obj->speed_y_up) {
    obj->speed_y_up = 0x40000;
                    /* Probable PsyQ macro: setPolyFT4() */
    obj->gravity = 0;
  }
  if (bVar1 < 2) {
    FUN_80104c34(obj);
  }
  else {
    Obj_ApplySpeed(obj);
  }
  iVar5 = FUN_801e23b8(obj);
  if (iVar5 != 0) {
    obj->state = 8;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801e2348 FUN_801e2348

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2348(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,8);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801e23b8 FUN_801e23b8

bool FUN_801e23b8(int param_1)

{
  char cVar1;
  bool bVar2;
  
  FUN_80106214();
  Enemy_ContactDamage(param_1);
  cVar1 = Enemy_CheckWeaponHits(param_1);
  if ((*(char *)(param_1 + 0x33) == '\0') && ((int)DAT_801b2988 < *(short *)(param_1 + 0x12) + -4))
  {
    bVar2 = cVar1 == '\x04';
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}


