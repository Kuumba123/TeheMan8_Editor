// ID 38, STAGE04.BIN, handler 0x801E482C. Ghidra output with the object struct applied; not matching C.
// ---- 801e482c FUN_801e482c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e482c(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e7458)[obj->state])();
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    goto LAB_801e48dc;
  }
  Enemy_ContactDamage(obj);
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    return;
  }
LAB_801e48dc:
  Obj_Free(obj);
  return;
}


// ---- 801e48f8 FUN_801e48f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e48f8(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  iVar1 = 0xa0000;
  obj->draw_list = 5;
  obj->hitbox = &DAT_801e744c;
  obj->box2 = &DAT_801e7450;
  obj->state = 1;
  obj->sub2 = 0;
  if (obj->var == 0) {
    iVar1 = 0x90000;
  }
  obj->speed_y_up = iVar1;
  obj->gravity = 0x4000;
  Anim_Set(obj,0);
  FUN_8010910c(obj);
  FUN_8010544c(obj,0x11d);
  return;
}


// ---- 801e4988 FUN_801e4988

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4988(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  Obj_ApplySpeed();
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  if (obj->sub2 == 0) {
    if (obj->speed_y_up < 1) {
      bVar1 = obj->anim_extra;
    }
    else {
      iVar2 = FUN_801e4a34(obj);
      if (iVar2 == 0) goto LAB_801e4a10;
      bVar1 = obj->anim_extra;
      obj->speed_y_up = 0;
    }
    Anim_SetAtStep(obj,1,bVar1);
    obj->sub2 = 1;
  }
LAB_801e4a10:
  Anim_Step(obj);
  return;
}


// ---- 801e4a34 FUN_801e4a34

int FUN_801e4a34(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x38);
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    sVar1 = (short)*(char *)(iVar4 + 2);
  }
  else {
    sVar1 = -(short)*(char *)(iVar4 + 2);
  }
  if ((*(byte *)(param_1 + 0x25) & 0x80) == 0) {
    iVar2 = -(int)*(char *)(iVar4 + 3);
  }
  else {
    iVar2 = (int)*(char *)(iVar4 + 3);
  }
  uVar3 = FUN_80107204((int)(short)(*(short *)(param_1 + 0xe) + sVar1),
                       ((*(short *)(param_1 + 0x12) + iVar2) -
                       ((int)*(char *)(iVar4 + 1) + (int)*(char *)(iVar4 + 4))) * 0x10000 >> 0x10);
                    /* Possible PsyQ macro: setPolyFT4() + setShadeTex(polyFT4, 1) */
  return -(uint)((uVar3 & 0x30) == 0x30);
}


