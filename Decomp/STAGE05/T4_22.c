// T4_22, STAGE05.BIN, handler 0x801E97AC. Ghidra output with the object struct applied; not matching C.
// ---- 801e97ac FUN_801e97ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e97ac(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  switch(obj->state) {
  case 0:
    *(byte *)((int)&obj->speed_x + 1) = DAT_801b29a3;
    obj->state = DAT_801b29a6;
    break;
  case 1:
    if (DAT_801b29a4 != 0) {
      bVar1 = 2;
      if (((int)(uint)DAT_801b29a3 >> ((byte)(&DAT_801eade4)[(uint)DAT_801c337a * 2] & 0x1f) & 1U)
          == 0) goto LAB_801e98b0;
      *(byte *)((int)&obj->speed_x + 1) = DAT_801b29a3;
LAB_801e98a8:
      obj->state = bVar1;
    }
    break;
  case 2:
    if (1 < DAT_801b29a4) {
      bVar1 = 3;
      if (((int)(uint)DAT_801b29a3 >> ((byte)(&DAT_801eade5)[(uint)DAT_801c337a * 2] & 0x1f) & 1U)
          != 0) {
        *(byte *)((int)&obj->speed_x + 1) = DAT_801b29a3;
        goto LAB_801e98a8;
      }
LAB_801e98b0:
      obj->state = 4;
    }
    break;
  case 3:
    if (DAT_801b29a4 < 3) break;
    DAT_801b29a0 = 1;
    goto LAB_801e99c4;
  case 4:
    DAT_801b29a5 = DAT_801b29a5 | (DAT_801b29a3 ^ *(byte *)((int)&obj->speed_x + 1)) << 5;
    *(byte *)((int)&obj->speed_x + 1) = DAT_801b29a3;
    if (2 < DAT_801b29a4) {
      *(undefined1 *)&obj->speed_x = 0x78;
      obj->state = 5;
    }
    break;
  case 5:
    cVar2 = (char)obj->speed_x;
    *(char *)&obj->speed_x = cVar2 + -1;
    if (cVar2 == '\0') {
      obj->state = 0;
      DAT_801b29a3 = 0;
      DAT_801b29a4 = 0;
      DAT_801b29a6 = 1;
    }
  }
  cVar2 = Obj_InActiveArea(obj);
  if (((cVar2 == '\0') || (DAT_801d2918._2_2_ < DAT_801d291e)) && (obj->state != 5)) {
    if (obj->state != 0) {
      DAT_801b29a6 = obj->state;
    }
LAB_801e99c4:
    Obj_FreeDespawn(obj);
  }
  return;
}


