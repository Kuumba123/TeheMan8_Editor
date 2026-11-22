// T2_2C, STAGE02.BIN, handler 0x801E47FC. Ghidra output with the object struct applied; not matching C.
// ---- 801e47fc FUN_801e47fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e47fc(MM8Obj *obj)

{
  byte bVar1;
  word wVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (obj->state == 0) {
    if (obj->var == 0) {
      obj->hitbox = &DAT_801e8a68;
      obj->flip = 0;
      obj->state = 1;
    }
    else {
      obj->bank = 2;
      obj->clut = 2;
      wVar2 = DAT_8017034c;
      obj->draw_list = 6;
      obj->hitbox = &DAT_801e8a6c;
      obj->box2 = &DAT_801e8a6c;
      obj->speed_x = -0x40000;
      obj->gravity = 0x4000;
      obj->state = 1;
      obj->field_0x43 = 1;
      obj->flip = 0;
      obj->accel_x = 0;
      obj->speed_y_up = 0;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->dmg_table = 0x3c;
      obj->vram_base = wVar2;
      Anim_Set(obj,0xd);
    }
  }
  if (obj->var == 0) {
    pcVar5 = &DAT_801b12ac;
    pcVar6 = (char *)((int)&DAT_801b12b0 + 2);
    do {
      if ((((*pcVar5 != '\0') && (pcVar6[0x40] == '\0')) && (*pcVar6 == '\x02')) &&
         (iVar4 = Obj_HitboxOverlap(obj,pcVar5), iVar4 != 0)) {
        FUN_801074f0(obj,pcVar5,3);
        FUN_8010544c(obj,0x27);
        FUN_801e4b7c();
        Obj_FreeDespawn(obj);
      }
      pcVar5 = pcVar5 + 0x60;
      pcVar6 = pcVar6 + 0x60;
    } while (pcVar5 < &DAT_801b1eac);
  }
  else {
    if (obj->sub3 == 0) {
      bVar1 = obj->dmg_table;
      obj->dmg_table = bVar1 - 1;
      if (bVar1 != 0) {
        return;
      }
      obj->dmg_table = 0x14;
      FUN_8010544c(obj,0xb);
      obj->sub3 = 1;
    }
    Anim_Step(obj);
    if (obj->field_0x43 == '\0') {
      FUN_80106214(obj);
      if ((obj->field_0x33 & 0x80) == 0) {
        obj->field_0x43 = 1;
        obj->sub2 = 0;
        obj->speed_y_up = 0;
        obj->speed_x = 0;
        obj->gravity = 0x4000;
      }
    }
    else {
      FUN_80104ccc(obj);
      if (obj->dmg_table == 0) {
        FUN_80106214(obj);
      }
      else {
        obj->dmg_table = obj->dmg_table - 1;
      }
      if (obj->speed_y_up < -0x60000) {
        obj->speed_y_up = -0x60000;
      }
      if ((obj->field_0x33 & 0x80) != 0) {
        if (obj->sub2 == 0) {
          obj->speed_y_up = 0x20000;
          obj->sub2 = 1;
          obj->speed_x = obj->speed_x / 2;
        }
        else {
          obj->sub2 = 0;
          obj->field_0x43 = 0;
          obj->speed_x = 0;
        }
      }
    }
    iVar4 = Obj_HitboxOverlap(obj,&g_player);
    if ((iVar4 != 0) && (g_player != '\0')) {
      DAT_801c3370 = DAT_801c3370 + 1;
      if (9 < DAT_801c3370) {
        DAT_801c3370 = 9;
      }
      FUN_800fd100(0x44);
      Obj_Free(obj);
    }
  }
  if (obj->active != 0) {
    if (obj->var != 0) {
      Obj_CullAndQueueDraw(obj);
    }
    cVar3 = Obj_InActiveArea(obj);
    if (cVar3 == '\0') {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801e4b7c FUN_801e4b7c

void FUN_801e4b7c(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocType2();
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[6] = 0x2c;
    *(undefined2 *)(puVar1 + 0xe) = 0x1f8;
    *puVar1 = 1;
    puVar1[7] = 1;
    *(undefined2 *)(puVar1 + 0x12) = 0x558;
  }
  return;
}


