// T3_3C, STAGE0C.BIN, handler 0x801E9FD4. Ghidra output with the object struct applied; not matching C.
// ---- 801e9fd4 FUN_801e9fd4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e9fd4(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  undefined1 *puVar3;
  byte bVar4;
  
  if (obj->state == 0) {
    obj->bank = 0x99;
    obj->vram_base = DAT_8017047a;
    bVar4 = (&DAT_80159f64)[obj->bank];
    obj->accel_x = 0;
    obj->gravity = 0;
    obj->draw_list = 1;
    obj->clut = bVar4;
    Anim_Set(obj,0x2c);
    obj->state = 1;
  }
  if (obj->var != 0) goto LAB_801ea2b0;
  if (obj->sub2 == 0) {
    *(undefined1 *)&obj->box2 = 3;
    *(undefined1 *)((int)&obj->box2 + 1) = 0;
    obj->sub2 = 1;
LAB_801ea07c:
    if (*(char *)&obj->box2 == '\0') {
      if (*(byte *)((int)&obj->box2 + 1) < 3) {
        puVar3 = (undefined1 *)Obj_AllocType3();
        if (puVar3 != (undefined1 *)0x0) {
          *puVar3 = 1;
          puVar3[6] = 0x3c;
          puVar3[7] = 1;
          *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
          *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)&obj->y_frac;
          puVar3[0x25] = obj->flip;
          puVar3[0x39] = *(undefined1 *)((int)&obj->box2 + 1);
          if (puVar3[0x25] == '\0') {
            bVar4 = puVar3[0x39] * -0x20 - 0x10;
            sVar2 = (short)(char)(&DAT_801eb0b4)[(uint)(byte)puVar3[0x39] * 2] +
                    *(short *)(puVar3 + 0xe);
          }
          else {
            bVar4 = puVar3[0x39] << 5 | 0x10;
            sVar2 = *(short *)(puVar3 + 0xe) -
                    (short)(char)(&DAT_801eb0b4)[(uint)(byte)puVar3[0x39] * 2];
          }
          *(short *)(puVar3 + 0xe) = sVar2;
          FUN_80105120(puVar3,0x100,bVar4);
          *(short *)(puVar3 + 0x12) =
               (short)(char)(&DAT_801eb0b5)[(uint)(byte)puVar3[0x39] * 2] +
               *(short *)(puVar3 + 0x12);
          cVar1 = *(char *)((int)&obj->box2 + 1);
          *(undefined1 *)&obj->box2 = 3;
          *(char *)((int)&obj->box2 + 1) = cVar1 + '\x01';
        }
      }
      else {
        obj->var = 1;
        if (obj->flip == 0) {
          bVar4 = *(char *)((int)&obj->box2 + 1) * -0x20 - 0x10;
          sVar2 = (short)(char)(&DAT_801eb0b4)[(uint)*(byte *)((int)&obj->box2 + 1) * 2] + obj->x;
        }
        else {
          bVar4 = *(char *)((int)&obj->box2 + 1) << 5 | 0x10;
          sVar2 = obj->x - (short)(char)(&DAT_801eb0b4)[(uint)*(byte *)((int)&obj->box2 + 1) * 2];
        }
        obj->x = sVar2;
        FUN_80105120(obj,0x100,bVar4);
        obj->y = (short)(char)(&DAT_801eb0b5)[(uint)*(byte *)((int)&obj->box2 + 1) * 2] + obj->y;
      }
    }
    else {
      *(char *)&obj->box2 = *(char *)&obj->box2 + -1;
    }
  }
  else if (obj->sub2 == 1) goto LAB_801ea07c;
  if (obj->var == 0) {
    return;
  }
LAB_801ea2b0:
  FUN_80104c34(obj);
  if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
    Obj_Free(obj);
  }
  else {
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


