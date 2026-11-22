// ID 26, STAGE03.BIN, handler 0x801E0A6C. Ghidra output with the object struct applied; not matching C.
// ---- 801e0a6c FUN_801e0a6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0a6c(MM8Obj *obj)

{
  obj->clut = obj->field_0x52;
  (*(code *)(&PTR_FUN_801e9ce4)[obj->state])();
  if (obj->active != 0) {
    if (obj->state != 7) {
      FUN_801e129c(obj);
    }
    FUN_80107bf4(obj,&g_player,1);
    if ((int)obj->x < DAT_801d2918._2_2_ + -0x40) {
      Obj_Free(obj);
    }
    else {
      Obj_CullAndQueueDrawMargin(obj,0x38);
    }
  }
  return;
}


// ---- 801e0b28 FUN_801e0b28

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0b28(MM8Obj *obj)

{
  short sVar1;
  byte bVar2;
  undefined1 *puVar3;
  
  obj->bank = 0x47;
  obj->vram_base = DAT_801703d6;
  bVar2 = DAT_80159fab;
  obj->draw_list = 9;
  obj->hp = 0x14;
  obj->dmg_table = 2;
  obj->flip = 0;
  obj->invuln = 0;
  obj->contact_dmg = 0;
  obj->field_0x51 = 0;
  obj->box2 = &DAT_801e9cc4 + (uint)obj->var * 5;
  obj->hitbox = &DAT_801e9cc4 + (uint)obj->var * 5;
  obj->field_0x52 = bVar2;
  obj->clut = bVar2;
  if (obj->var < 3) {
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->x = obj->x + 0x10;
    if (obj->var < 2) {
      obj->invuln = 1;
    }
    else {
      obj->dmg_table = 0x15;
    }
  }
  if (obj->var < 2) {
    puVar3 = (undefined1 *)Obj_AllocMain();
                    /* Possible PsyQ macro: setTile8() */
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
      puVar3[6] = 0x26;
      puVar3[7] = obj->var + 3;
      *(short *)(puVar3 + 0xe) = obj->x;
      sVar1 = obj->y;
      *(short *)(puVar3 + 0x12) = sVar1;
      if (obj->var == 1) {
        *(short *)(puVar3 + 0x12) = sVar1 + 0x14;
      }
      *(MM8Obj **)(puVar3 + 0x4c) = obj;
      *(undefined4 *)(puVar3 + 0x1c) = 1;
      puVar3[1] = 0;
    }
    obj->field_0x50 = 0;
  }
  Anim_Set(obj,(&DAT_801e9d04)[obj->var]);
  obj->state = (&DAT_801e9d0c)[obj->var];
  return;
}


// ---- 801e129c FUN_801e129c

void FUN_801e129c(int param_1)

{
  if (*(char *)(param_1 + 0x51) == '\0') {
    if (DAT_801b29a1 == '\0') {
      *(undefined1 *)(param_1 + 0x51) = 1;
    }
  }
  else if (DAT_801b29a1 != '\0') {
    *(undefined1 *)(param_1 + 1) = 7;
    *(undefined1 *)(param_1 + 2) = 0;
  }
  return;
}


