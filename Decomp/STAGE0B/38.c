// ID 38, STAGE0B.BIN, handler 0x801DE678. Ghidra output with the object struct applied; not matching C.
// ---- 801de678 FUN_801de678

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de678(MM8Obj *obj)

{
  char cVar1;
  
  (**(code **)(&DAT_801e84dc + (uint)obj->state * 4))();
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar1 = Enemy_CheckWeaponHits(obj);
  if (cVar1 == '\x02') {
    obj->clut = 0;
  }
  else if (cVar1 == '\x04') {
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    goto LAB_801de728;
  }
  Enemy_ContactDamage(obj);
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    return;
  }
LAB_801de728:
  Obj_Free(obj);
  return;
}


// ---- 801de744 caseD_2

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801de6c0::caseD_2(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
  iVar1 = 0xa0000;
  obj->draw_list = 5;
  obj->hitbox = &DAT_801e84d0;
  obj->box2 = &DAT_801e84d4;
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


// ---- 801de7d4 FUN_801de7d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de7d4(MM8Obj *obj)

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
      iVar2 = FUN_801de880(obj);
      if (iVar2 == 0) goto LAB_801de85c;
      bVar1 = obj->anim_extra;
      obj->speed_y_up = 0;
    }
    Anim_SetAtStep(obj,1,bVar1);
    obj->sub2 = 1;
  }
LAB_801de85c:
  Anim_Step(obj);
  return;
}


// ---- 801de880 FUN_801de880

int FUN_801de880(int param_1)

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
  return -(uint)((uVar3 & 0x30) == 0x30);
}


