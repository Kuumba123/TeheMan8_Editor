// T2_1D, STAGE05.BIN, handler 0x801E5990. Ghidra output with the object struct applied; not matching C.
// ---- 801e5990 FUN_801e5990

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5990(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801e59dc();
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e59dc FUN_801e59dc

void FUN_801e59dc(int param_1)

{
  (*(code *)(&PTR_FUN_801ea964)[*(byte *)(param_1 + 1)])();
  return;
}


// ---- 801e5a18 FUN_801e5a18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5a18(MM8Obj *obj)

{
  byte bVar1;
  
  obj->bank = 0x53;
  obj->vram_base = DAT_801703ee;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->draw_list = 7;
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->flip = 0;
  obj->state = 1;
  obj->clut = bVar1;
  if (((int)(uint)DAT_801b29a3 >> (obj->var & 0x1f) & 1U) == 0) {
    Anim_Set(obj,9);
    obj->sub2 = 0;
  }
  else {
    Anim_SetAtStep(obj,9,6);
    obj->sub2 = 2;
  }
  obj->sub3 = 0;
  obj->hitbox = &DAT_801ea950;
  obj->box2 = &UNK_801ea954 + (obj->anim_extra & 0x7f) * 5;
  return;
}


// ---- 801e5afc FUN_801e5afc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5afc(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  
  obj->box2 = &UNK_801ea954 + (obj->anim_extra & 0x7f) * 5;
  bVar2 = FUN_80107bf4(obj,&g_player,5);
  bVar1 = obj->sub2;
  if (bVar1 == 1) {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      DAT_801b29a4 = DAT_801b29a4 + '\x01';
      DAT_801b29a3 = DAT_801b29a3 | '\x01' << (obj->var & 0x1f);
      obj->sub2 = 2;
    }
    Anim_Step(obj);
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && ((DAT_8015e27c & bVar2) == 0x80)) {
      obj->sub2 = 1;
    }
  }
  else if (((bVar1 == 2) && (((int)(uint)DAT_801b29a3 >> (obj->var & 0x1f) & 1U) == 0)) &&
          ((DAT_8015e27c & bVar2) != 0x80)) {
    Anim_Set(obj,9);
    obj->sub2 = 0;
    obj->sub3 = 0;
  }
  if ((obj->sub3 == 0) && ((obj->anim_extra & 0x80) != 0)) {
    FUN_8010544c(obj,0x2b);
    obj->sub3 = 1;
  }
  return;
}


