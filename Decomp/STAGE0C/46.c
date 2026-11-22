// ID 46, STAGE0C.BIN, handler 0x801DD4B8. Ghidra output with the object struct applied; not matching C.
// ---- 801dd4b8 FUN_801dd4b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd4b8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  
  bVar1 = DAT_80159fe3;
  bVar3 = obj->var;
  obj->clut = DAT_80159fe3;
  if (obj->var == 1) {
    bVar1 = bVar1 + 2;
LAB_801dd4fc:
    obj->clut = bVar1;
  }
  else {
    bVar1 = bVar1 + 3;
    if (obj->var == 2) goto LAB_801dd4fc;
  }
  (*(code *)(&PTR_FUN_801eab48)[obj->state])(obj);
  if (obj->active == 0) {
    return;
  }
  if ((obj->var < 3) && ((obj->anim_extra & 0x40) != 0)) {
    obj->clut = DAT_80159fe3;
  }
  obj->invuln = 7 < obj->state;
  cVar2 = FUN_801ddfdc(obj);
  if (cVar2 == '\0') {
    if (bVar3 < 3) {
      cVar2 = switchD_801de6c0::caseD_1(obj,0x80,0x38);
      if (cVar2 != '\0') goto LAB_801dd648;
    }
    else {
      bVar3 = switchD_801de6c0::caseD_1(obj,0x38,0x38);
      if ((bVar3 != 0) &&
         (((bVar3 & 0x40) == 0 || (iVar4 = FUN_80104820(obj,0x38,0x100), iVar4 == 0))))
      goto LAB_801dd620;
    }
    Obj_CullAndQueueDrawMargin(obj,0x40);
  }
  else {
    if (bVar3 != 5) {
      FUN_80108e84(obj);
    }
    if (2 < bVar3) {
      FUN_801de68c(obj);
LAB_801dd620:
      Obj_Free(obj);
      return;
    }
    FUN_8012a5fc(obj,8);
    FUN_80108fd8(obj,0);
LAB_801dd648:
    Obj_FreeDespawn(obj);
  }
  return;
}


