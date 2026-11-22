// T3_1D, STAGE03.BIN, handler 0x801E8CD0. Ghidra output with the object struct applied; not matching C.
// ---- 801e8cd0 FUN_801e8cd0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8cd0(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801ea010)[obj->state])();
  if (*(char *)&obj->box2 != '\0') {
    Obj_CullAndQueueDraw(obj);
  }
  iVar1 = Obj_InActiveArea(obj);
  if ((iVar1 == 0) || (*(char *)((int)&obj->box2 + 1) != '\0')) {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e8d58 FUN_801e8d58

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8d58(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  
  bVar1 = obj->var;
  obj->flip = 0;
  *(undefined1 *)&obj->box2 = 1;
  *(undefined1 *)((int)&obj->box2 + 1) = 0;
  *(undefined1 *)((int)&obj->box2 + 2) = 0;
  if (bVar1 == 1) {
    obj->state = 1;
    obj->bank = 2;
    bVar1 = DAT_80159f66;
    obj->draw_list = 6;
    obj->clut = bVar1;
    uVar3 = Rand();
    obj->x = DAT_801d2918._2_2_ + (uVar3 & 0x1f) * 8;
    uVar3 = Rand();
    uVar4 = 0;
    obj->y = g_cam_y + (uVar3 & 0xf) * 0x10;
  }
  else if (bVar1 < 2) {
    if (bVar1 != 0) goto LAB_801e8f84;
    obj->bank = 9;
    obj->clut = 0x17;
    obj->state = 1;
    obj->draw_list = 4;
    uVar3 = Rand();
    obj->x = obj->x + ((uVar3 & 7) - 4) * 8;
    uVar3 = Rand();
    obj->y = obj->y + ((uVar3 & 7) - 4) * 8;
    uVar4 = Rand();
    uVar4 = uVar4 & 1 | 0x2a;
  }
  else {
    if (bVar1 == 2) {
      obj->state = 2;
      obj->bank = 0x47;
      obj->clut = DAT_80159fab;
      uVar4 = Rand();
      Anim_SetAtStep(obj,5,uVar4 & 1);
      obj->draw_list = 4;
      uVar3 = Rand();
      obj->x = DAT_801d2918._2_2_ + (uVar3 & 0xff);
      sVar2 = g_cam_y;
      obj->speed_y_up = -0x4000;
      obj->speed_x = 0;
      obj->gravity = 0x4000;
      obj->y = sVar2;
      iVar5 = Rand();
      obj->flip = (iVar5 < 1) << 6;
      goto LAB_801e8f84;
    }
    if (bVar1 != 3) goto LAB_801e8f84;
    obj->state = 3;
    obj->bank = 2;
    bVar1 = DAT_80159f66;
    obj->draw_list = 6;
    obj->clut = bVar1;
    uVar3 = Rand();
    obj->x = DAT_801d2918._2_2_ + (uVar3 & 0x1f) * 8 + 0x20;
    uVar3 = Rand();
    sVar2 = g_cam_y;
    uVar4 = 0;
    *(undefined1 *)&obj->box2 = 0;
    *(undefined1 *)((int)&obj->box2 + 2) = 0xf4;
    obj->y = sVar2 + (uVar3 & 0xf) * 0x10;
  }
  Anim_Set(obj,uVar4);
LAB_801e8f84:
  obj->vram_base = (&DAT_80170348)[obj->bank];
  return;
}


// ---- 801e8fb8 FUN_801e8fb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8fb8(MM8Obj *obj)

{
  Anim_Step();
  if (obj->var == 0) {
    *(byte *)&obj->box2 = *(byte *)&obj->box2 ^ 1;
  }
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    *(undefined1 *)((int)&obj->box2 + 1) = 1;
  }
  return;
}


// ---- 801e9024 FUN_801e9024

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9024(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if (obj->speed_y_up < -0x43fff) {
    obj->speed_y_up = -0x40000;
    FUN_80104c34();
  }
  else {
    FUN_80104ccc(obj);
  }
  if (obj->sub2 == 0) {
    if ((0x1250 < obj->y) && (iVar2 = FUN_80107204((int)obj->x), 0xf < iVar2)) {
      obj->sub2 = 1;
      obj->speed_y_up = -(obj->speed_y_up >> 1);
      uVar3 = Rand();
      obj->speed_x = (uVar3 & 0x7fff) << 3;
      iVar2 = Rand();
      if (iVar2 < 0) {
        obj->speed_x = -obj->speed_x;
      }
    }
    bVar1 = *(char *)((int)&obj->box2 + 2) + 1;
    *(byte *)((int)&obj->box2 + 2) = bVar1;
    if ((bVar1 & 3) == 0) {
      FUN_801091a4((int)obj->x,(int)obj->y,0);
    }
  }
  *(byte *)&obj->box2 = *(byte *)&obj->box2 ^ 1;
  return;
}


// ---- 801e9130 FUN_801e9130

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9130(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  if (obj->sub2 == 0) {
    cVar1 = *(char *)((int)&obj->box2 + 2) + -1;
    *(char *)((int)&obj->box2 + 2) = cVar1;
    if (cVar1 == '\0') {
      obj->sub2 = 1;
    }
  }
  else {
    bVar2 = *(char *)((int)&obj->box2 + 2) + 1;
    *(byte *)((int)&obj->box2 + 2) = bVar2;
    if (((bVar2 & 7) == 0) && (iVar3 = FUN_801091a4((int)obj->x,(int)obj->y,1), iVar3 != 0)) {
      *(undefined1 *)(iVar3 + 0x26) = 6;
    }
  }
  return;
}


