// T3_21, STAGE05.BIN, handler 0x801E8454. Ghidra output with the object struct applied; not matching C.
// ---- 801e8454 FUN_801e8454

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8454(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801eaa68)[obj->state])();
  return;
}


// ---- 801e8490 FUN_801e8490

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8490(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
                    /* Possible PsyQ macro: setLineF2() */
  obj->bank = 0x40;
  obj->vram_base = DAT_801703c8;
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->speed_y_up = 0;
  obj->draw_list = 7;
  obj->clut = bVar1;
  Anim_Set(obj,obj->var + 4);
  if (obj->var == 2) {
    obj->gravity = 0;
  }
  else {
    obj->gravity = 0x4000;
    *(undefined1 *)&obj->box2 = 1;
  }
  obj->state = 1;
  cVar2 = Obj_InActiveArea(obj);
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  if (cVar2 == '\0') {
    Obj_Free(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e8558 FUN_801e8558

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e8558(MM8Obj *obj)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (obj->var == 2) {
    Anim_Step();
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->state = 2;
    }
  }
  else {
    Obj_ApplySpeed(obj);
    if (obj->speed_y_up < -0x60000) {
      obj->speed_y_up = -0x60000;
      obj->gravity = 0;
    }
    if (obj->sub2 == 0) {
      cVar1 = *(char *)&obj->box2;
      *(char *)&obj->box2 = cVar1 + -1;
      if (cVar1 == '\0') {
        *(undefined1 *)&obj->box2 = 1;
        puVar2 = (undefined1 *)FUN_801057b0(obj);
        if (puVar2 != (undefined1 *)0x0) {
          puVar2[6] = 0x21;
          *puVar2 = 1;
          puVar2[7] = 2;
          puVar2[1] = 0;
          *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
          *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)&obj->y_frac;
          uVar3 = Rand();
          if ((uVar3 & 1) != 0) {
            *(ushort *)(puVar2 + 0xe) = *(ushort *)(puVar2 + 0xe) ^ 1;
          }
        }
      }
      cVar1 = FUN_80107204((int)obj->x,(int)(((ushort)obj->y + 7) * 0x10000) >> 0x10);
      if (cVar1 != '\0') {
        obj->sub2 = 1;
        obj->speed_y_up = 0x30000;
        uVar3 = Rand();
        uVar3 = uVar3 & 3;
        uVar4 = Rand();
        if ((uVar4 & 1) == 0) {
          uVar3 = -uVar3;
        }
        obj->speed_x = uVar3 << 0x10;
        obj->gravity = 0x4000;
      }
      cVar1 = Obj_InActiveArea(obj);
    }
    else {
      cVar1 = FUN_80107204((int)obj->x,(int)obj->y);
      if (cVar1 != '\0') {
        obj->state = 2;
      }
      if ((DAT_80170574 & 1) == 0) {
        return;
      }
      cVar1 = Obj_InActiveArea(obj);
    }
    if (cVar1 == '\0') {
      Obj_Free(obj);
      return;
    }
  }
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e8748 FUN_801e8748

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Possible GS_106.OBJ/GsSetProjection
   Possible _OP_VDEL.OBJ/__builtin_vec_delete
   Possible _OP_VNEW.OBJ/__builtin_vec_new
   Possible SCNOFF.OBJ/SsSetNoiseOff
   Possible SSQUIT.OBJ/SsQuit */

void FUN_801e8748(MM8Obj *obj)

{
  Obj_Free();
  return;
}


