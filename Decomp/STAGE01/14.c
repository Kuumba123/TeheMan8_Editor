// ID 14, STAGE01.BIN, handler 0x801DE2DC. Ghidra output with the object struct applied; not matching C.
// ---- 801de2dc FUN_801de2dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de2dc(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  char cVar3;
  
  if (obj->state == 0) {
    Enemy_InitFromTable();
    obj->hitbox = &DAT_801e6a2c;
    obj->box2 = (byte *)0x0;
    obj->draw_list = 9;
    obj->flip = 0;
    obj->x = obj->x + 0x40;
    Anim_Set(obj,0xf);
    obj->state = obj->state + 1;
  }
  cVar3 = Enemy_CheckWeaponHits(obj);
  if ((cVar3 == '\x01') && (DAT_80158f5c == '\r')) {
    sVar1 = obj->x;
    sVar2 = obj->y;
    FUN_8012ae08(obj,5);
    FUN_8010544c(obj,0x74);
    obj->x = sVar1 + -0x20;
    FUN_8012ae08(obj,5);
    FUN_8010544c(obj,0x74);
    obj->x = sVar1 + 0x20;
    FUN_8012ae08(obj,5);
    FUN_8010544c(obj,0x74);
    obj->x = sVar1;
    FUN_80102ef4(1,(int)sVar1,(int)sVar2);
    Obj_Free(obj);
  }
  else {
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  return;
}


