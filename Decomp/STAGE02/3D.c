// ID 3D, STAGE02.BIN, handler 0x801DDA0C. Ghidra output with the object struct applied; not matching C.
// ---- 801dda0c FUN_801dda0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dda0c(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e8750)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801dda78 FUN_801dda78

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dda78(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->hitbox = &DAT_801e8744;
  obj->box2 = &DAT_801e8748;
  obj->state = 1;
  obj->flip = 0;
  if (DAT_801b29a0 == '\0') {
    Anim_Set(obj,1);
    obj->draw_list = 6;
    obj->sub2 = 0;
  }
  else {
    Anim_Set(obj,2);
    obj->draw_list = 7;
    obj->sub2 = 1;
  }
  return;
}


// ---- 801ddb0c FUN_801ddb0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddb0c(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    FUN_80107bf4(obj,&g_player,1);
    cVar1 = Enemy_CheckWeaponHits(obj);
    if ((cVar1 != '\x02') && (cVar1 == '\x04')) {
      FUN_80108e84(obj);
      FUN_8012ae08(obj,0x20);
      obj->sub2 = 1;
      obj->draw_list = 7;
      Anim_Set(obj,2);
      DAT_801b29a0 = 1;
    }
  }
  return;
}


