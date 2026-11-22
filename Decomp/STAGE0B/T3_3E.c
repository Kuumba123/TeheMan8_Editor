// T3_3E, STAGE0B.BIN, handler 0x801E7950. Ghidra output with the object struct applied; not matching C.
// ---- 801e7950 FUN_801e7950

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7950(MM8Obj *obj)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  pcVar3 = (char *)obj->accel_x;
  if (((*pcVar3 == '\0') || (pcVar3[6] != 'Y')) || (*(MM8Obj **)(pcVar3 + 0x14) != obj)) {
    Obj_Free(obj);
  }
  else {
    uVar2 = *(undefined4 *)(pcVar3 + 0xc);
    obj->x_frac = (short)uVar2;
    obj->x = (short)((uint)uVar2 >> 0x10);
    uVar2 = *(undefined4 *)(pcVar3 + 0x10);
    obj->y_frac = (short)uVar2;
    obj->y = (short)((uint)uVar2 >> 0x10);
    obj->x = (short)(char)(&DAT_801e886c)[(uint)(byte)pcVar3[0x32] * 2] + obj->x;
    if ((pcVar3[0x25] & 0x80U) == 0) {
      obj->y = (short)(char)(&DAT_801e886d)[(uint)(byte)pcVar3[0x32] * 2] + obj->y;
    }
    else {
      obj->y = obj->y - (short)(char)(&DAT_801e886d)[(uint)(byte)pcVar3[0x32] * 2];
    }
    if (obj->state == 0) {
      obj->bank = 0x96;
      obj->vram_base = DAT_80170474;
      bVar1 = (&DAT_80159f64)[obj->bank];
      obj->draw_list = 7;
      obj->flip = 0;
      obj->state = 1;
      *(byte *)&obj->box2 = obj->var;
      obj->clut = bVar1;
      if (obj->var == 0) {
        uVar2 = 0x11;
      }
      else {
        uVar2 = 0x1c;
      }
      Anim_Set(obj,uVar2);
    }
    if (*(byte *)&obj->box2 != obj->var) {
      *(byte *)&obj->box2 = obj->var;
      if (obj->var == 0) {
        uVar2 = 0x11;
      }
      else {
        uVar2 = 0x1c;
      }
      Anim_Set(obj,uVar2);
    }
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


