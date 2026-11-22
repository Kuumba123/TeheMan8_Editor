// T3_36, STAGE06.BIN, handler 0x801E49B0. Ghidra output with the object struct applied; not matching C.
// ---- 801e49b0 FUN_801e49b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e49b0(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e5c90)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e4a1c FUN_801e4a1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4a1c(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  word wVar4;
  ushort uVar5;
  undefined1 *puVar6;
  
  obj->sub2 = 0;
  obj->state = obj->state + 1;
  bVar3 = DAT_80159ff2;
  obj->flip = 0;
  obj->bank = 0x8e;
  obj->clut = bVar3;
  wVar4 = DAT_80170464;
  cVar1 = *(char *)&obj->box2;
  obj->draw_list = 0;
  *(undefined1 *)((int)&obj->box2 + 1) = 0;
  obj->vram_base = wVar4;
  if (cVar1 == '\0') {
    puVar6 = (undefined1 *)Obj_AllocType3();
    if (puVar6 != (undefined1 *)0x0) {
      *puVar6 = 1;
      puVar6[6] = 0x36;
      puVar6[7] = 0;
      uVar5 = Rand();
      *(ushort *)(puVar6 + 0xe) = obj->x - ((uVar5 & 3) + 10);
      uVar5 = Rand();
      sVar2 = obj->y;
      puVar6[0x38] = 1;
      *(ushort *)(puVar6 + 0x12) = sVar2 - ((uVar5 & 3) + 8);
    }
    puVar6 = (undefined1 *)Obj_AllocType3();
    if (puVar6 != (undefined1 *)0x0) {
      *puVar6 = 1;
      puVar6[6] = 0x36;
      puVar6[7] = 0;
      uVar5 = Rand();
      *(ushort *)(puVar6 + 0xe) = obj->x + (uVar5 & 3) + 10;
      uVar5 = Rand();
      sVar2 = obj->y;
      puVar6[0x38] = 1;
      *(ushort *)(puVar6 + 0x12) = sVar2 - ((uVar5 & 3) + 8);
    }
  }
  Anim_Set(obj,0);
  return;
}


// ---- 801e4b50 FUN_801e4b50

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4b50(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e5c98)[obj->var])();
  return;
}


// ---- 801e4b8c FUN_801e4b8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4b8c(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  
  if (obj->sub2 == 0) {
    obj->speed_x = 0;
    obj->sub2 = obj->sub2 + 1;
    uVar3 = Rand();
    obj->speed_y_up = (uVar3 & 0x7ff) - 0xc000;
    obj->accel_x = 0;
    obj->gravity = 0x4000;
  }
  Obj_ApplySpeed(obj);
  Anim_Step(obj);
  if (*(char *)&obj->box2 == '\0') {
    if (*(short *)((int)&obj->box2 + 2) + 8 <= (int)obj->y) {
      sVar1 = obj->x;
      sVar2 = obj->y;
      *(short *)((int)&obj->box2 + 2) = obj->y;
      FUN_80102ef4(9,(int)sVar1,(int)sVar2);
    }
  }
  if ((*(char *)((int)&obj->box2 + 1) == '\0') && ((int)DAT_801b2988 < obj->y + 0x10)) {
    if (*(char *)&obj->box2 == '\0') {
      sVar1 = obj->x;
      sVar2 = obj->y;
      obj->var = 1;
      *(undefined1 *)((int)&obj->box2 + 1) = 1;
      FUN_80102ef4(9,(int)sVar1,(int)sVar2);
      FUN_80102ef4(9,(int)obj->x,(int)(((ushort)obj->y + 0x10) * 0x10000) >> 0x10);
      FUN_80102ef4(9,(int)obj->x,(int)(((ushort)obj->y + 0x20) * 0x10000) >> 0x10);
      Anim_Set(obj,1);
    }
    else {
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801e4ce8 FUN_801e4ce8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4ce8(MM8Obj *obj)

{
  obj->y = DAT_801b2988;
  Anim_Step();
  if (DAT_801b2988 == 0xed0) {
    Obj_Free(obj);
  }
  return;
}


