// T4_09, STAGE01.BIN, handler 0x801E5290. Ghidra output with the object struct applied; not matching C.
// ---- 801e5290 FUN_801e5290

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5290(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6fa4)[obj->state])();
  return;
}


// ---- 801e52cc FUN_801e52cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e52cc(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = FUN_80104d30(obj,&g_player,0x18);
  if (iVar1 != 0) {
    if (obj->var == 1) {
      DAT_801b2995 = 0x80;
      Obj_Free(obj);
    }
    else {
      obj->state = 1;
      FUN_801119e0(obj->x + 0x28,0x40);
      FUN_80105bec();
      DAT_801d2926 = obj->x + 0x60;
      DAT_801d2928 = obj->x;
      DAT_801d2917 = 2;
    }
  }
  return;
}


