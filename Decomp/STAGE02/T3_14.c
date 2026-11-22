// T3_14, STAGE02.BIN, handler 0x801E54AC. Ghidra output with the object struct applied; not matching C.
// ---- 801e54ac FUN_801e54ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e54ac(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8a84)[obj->state])();
  return;
}


// ---- 801e54e8 FUN_801e54e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e54e8(MM8Obj *obj)

{
  byte bVar1;
  
  obj->draw_list = 3;
                    /* Possible PsyQ macro: setPolyGT3() + setSemiTrans(polyGT3, 1) */
  obj->bank = 0x36;
  obj->vram_base = DAT_801703b4;
  bVar1 = DAT_80159f9a;
  obj->flip = 0;
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->gravity = 0;
  obj->clut = bVar1;
  if (obj->var == 2) {
    obj->state = 2;
    *(undefined1 *)((int)&obj->hitbox + 1) = 3;
    *(undefined1 *)&obj->hitbox = 0xf;
    *(undefined1 *)((int)&obj->hitbox + 3) = 0;
  }
  else {
    Anim_Set(obj,obj->var * '\x02' + '\x16');
    obj->state = 1;
    obj->sub2 = 0;
    obj->sub3 = 0;
    if (obj->var == 0) {
      *(undefined1 *)&obj->hitbox = 0x3c;
    }
  }
  return;
}


// ---- 801e55a8 FUN_801e55a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e55a8(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = obj->box2;
  uVar3 = *(undefined4 *)(pbVar5 + 0xc);
  obj->x_frac = (short)uVar3;
  obj->x = (short)((uint)uVar3 >> 0x10);
  uVar3 = *(undefined4 *)(pbVar5 + 0x10);
  obj->y_frac = (short)uVar3;
  obj->y = (short)((uint)uVar3 >> 0x10);
  if (obj->sub3 == 0) {
    if (pbVar5[0x59] == 4) {
      Anim_Set(obj,6);
      obj->x = (short)(char)(&DAT_801e8a80)[(uint)obj->var * 2] + obj->x;
      obj->y = (short)(char)(&DAT_801e8a81)[(uint)obj->var * 2] + obj->y;
      bVar2 = Rand();
      obj->flip = (bVar2 & 1) << 6;
      obj->sub3 = 1;
    }
    else {
      if (obj->var == 0) {
        if (obj->sub2 != 0) {
          if (((int)(short)obj->frame & 0x8000U) != 0) {
            obj->box2[0x59] = 2;
            obj->sub2 = 0;
          }
          goto LAB_801e5794;
        }
        if (obj->box2[0x59] != 1) goto LAB_801e5794;
        Anim_Set(obj,0x17);
      }
      else {
        if (obj->sub2 != 0) {
          cVar1 = *(char *)&obj->hitbox;
          *(char *)&obj->hitbox = cVar1 + -1;
          if (cVar1 == '\0') {
            bVar2 = Rand(obj);
            *(byte *)&obj->hitbox = (bVar2 & 0x3f) * '\x02' + '<';
            obj->sub2 = 0;
            Anim_Set(obj,0x18);
          }
          goto LAB_801e5794;
        }
        if (((int)(short)obj->frame & 0x8000U) == 0) goto LAB_801e5794;
      }
      obj->sub2 = 1;
    }
  }
  else if (obj->sub3 == 1) {
    obj->x = (short)(char)(&DAT_801e8a80)[(uint)obj->var * 2] + obj->x;
    obj->y = (short)(char)(&DAT_801e8a81)[(uint)obj->var * 2] + obj->y;
  }
LAB_801e5794:
  if ((obj->sub3 == 0) || (uVar4 = Rand(), (uVar4 & 1) != 0)) {
    Anim_Step(obj);
  }
  pbVar5 = obj->box2;
  if (((*pbVar5 == 0) || (pbVar5[6] != 0x18)) || (pbVar5[7] != 0)) {
    if (obj->sub3 != 0) {
      FUN_80108e84(obj);
    }
    Obj_Free(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e583c FUN_801e583c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e583c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  
  cVar1 = *(char *)&obj->hitbox;
  *(char *)&obj->hitbox = cVar1 + -1;
  if (cVar1 == '\0') {
    bVar2 = *(byte *)((int)&obj->hitbox + 3);
    *(undefined1 *)&obj->hitbox = 0xf;
    if ((bVar2 < 4) && (puVar5 = (undefined1 *)Obj_AllocMain(), puVar5 != (undefined1 *)0x0)) {
      *puVar5 = 1;
      puVar5[6] = 0x1d;
      *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)&obj->x_frac;
      *(undefined4 *)(puVar5 + 0x10) = *(undefined4 *)&obj->y_frac;
      puVar5[1] = 0;
      *(short *)(puVar5 + 0x12) = *(short *)(puVar5 + 0x12) + -8;
      puVar5[7] = *(byte *)((int)&obj->hitbox + 3) >> 1 & 1;
      puVar5[0x25] = (*(byte *)((int)&obj->hitbox + 3) & 1) << 6;
      *(char *)((int)&obj->hitbox + 3) = *(char *)((int)&obj->hitbox + 3) + '\x01';
    }
    bVar2 = *(byte *)((int)&obj->hitbox + 1);
    bVar2 = bVar2 | bVar2 << 1;
    *(byte *)((int)&obj->hitbox + 1) = bVar2;
    if ((bVar2 & 0x3f) == 0x3f) {
      Obj_Free(obj);
      return;
    }
  }
  if ((((uint)obj->hitbox & 3) == 3) &&
     (puVar5 = (undefined1 *)Obj_AllocType3(), puVar5 != (undefined1 *)0x0)) {
    *puVar5 = 1;
    puVar5[6] = 6;
    puVar5[7] = 0;
    puVar5[0x38] = 0;
    puVar5[0x26] = 5;
    puVar5[1] = 0;
    *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)&obj->x_frac;
    *(undefined4 *)(puVar5 + 0x10) = *(undefined4 *)&obj->y_frac;
    uVar3 = Rand();
    uVar4 = Rand();
    *(ushort *)(puVar5 + 0xe) =
         *(short *)(puVar5 + 0xe) +
         (uVar3 & *(byte *)((int)&obj->hitbox + 1)) * ((uVar4 & 1) * -2 + 1);
    uVar3 = Rand();
    uVar4 = Rand();
    *(ushort *)(puVar5 + 0x12) =
         *(short *)(puVar5 + 0x12) +
         (uVar3 & *(byte *)((int)&obj->hitbox + 1)) * ((uVar4 & 1) * -2 + 1);
  }
  return;
}


