// T4_1F, STAGE06.BIN, handler 0x801E4D38. Ghidra output with the object struct applied; not matching C.
// ---- 801e4d38 FUN_801e4d38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4d38(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  
  if ((obj->var & 0x80) == 0) {
    sVar1 = obj->x;
    sVar2 = DAT_8015e248._2_2_;
  }
  else {
    sVar1 = obj->y;
    sVar2 = DAT_8015e24c._2_2_;
  }
  if (sVar1 < sVar2) {
    *(undefined1 *)&obj->speed_x = 1;
  }
  else {
    *(undefined1 *)&obj->speed_x = 0;
  }
  if (obj->state == 0) {
    obj->state = obj->state + 1;
    if (sVar1 < sVar2) {
      *(undefined1 *)((int)&obj->speed_x + 1) = 1;
    }
    else {
      *(undefined1 *)((int)&obj->speed_x + 1) = 0;
    }
    DAT_801b2988 = *(undefined2 *)
                    (&UNK_801e5ca0 + (uint)(byte)obj->speed_x * 2 + (obj->var & 0x7f) * 4);
  }
  uVar4 = (uint)(byte)obj->speed_x;
  if (uVar4 != *(byte *)((int)&obj->speed_x + 1)) {
    DAT_801b2988 = *(undefined2 *)(&UNK_801e5ca0 + uVar4 * 2 + (obj->var & 0x7f) * 4);
    *(char *)((int)&obj->speed_x + 1) = (char)obj->speed_x;
  }
  cVar3 = Obj_InActiveArea(obj);
  if (cVar3 == '\0') {
    Obj_FreeDespawn(obj);
  }
  return;
}


