// T2_03, STAGE01.BIN, handler 0x801E31D8. Ghidra output with the object struct applied; not matching C.
// ---- 801e31d8 FUN_801e31d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e31d8(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e6cb4)[obj->state])();
  Obj_CullAndQueueDraw(obj);
  if (obj->on_screen == 0) {
    Anim_Set(obj,DAT_801c336e == '\n');
    obj->state = 1;
    obj->dmg_table = 0;
    obj->contact_dmg = 0;
    obj->invuln = 0;
    iVar1 = FUN_80109430(obj,&g_player,900,0xf0);
    if (iVar1 == 0) {
      if ((obj->var & 0x80) == 0) {
        Obj_FreeDespawn(obj);
      }
      else {
        Obj_Free(obj);
      }
    }
  }
  return;
}


// ---- 801e32b0 FUN_801e32b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e32b0(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  puVar2 = (undefined1 *)0x0;
  obj->bank = 0x1e;
  obj->vram_base = DAT_80170384;
  bVar1 = DAT_80159f82;
  obj->draw_list = 6;
  obj->speed_y_up = -0x8000;
  obj->gravity = 0x4000;
  bVar3 = obj->var & 0xf;
  obj->box2 = &DAT_801e6cac;
  obj->field_0x43 = 0;
  obj->field_0x33 = 0;
  obj->flip = 0;
  obj->speed_x = 0;
  obj->accel_x = 0;
  obj->dmg_table = 0;
  obj->contact_dmg = 0;
  obj->invuln = 0;
  obj->field_0x4c = (char)obj->x;
  obj->field_0x4d = (char)((ushort)obj->x >> 8);
  obj->field_0x4e = (char)obj->y;
  obj->field_0x4f = (char)((ushort)obj->y >> 8);
  obj->clut = bVar1;
  if ((1 < bVar3) && (puVar2 = (undefined1 *)Obj_AllocType2(), puVar2 != (undefined1 *)0x0)) {
    *puVar2 = 1;
    puVar2[6] = 3;
    puVar2[1] = 0;
    puVar2[7] = bVar3 - 1 | 0x80;
    *(short *)(puVar2 + 0xe) = obj->x + 0x40;
    *(short *)(puVar2 + 0x12) = obj->y;
  }
  FUN_801093d4(puVar2,&obj->target_prio);
  Anim_Set(obj,DAT_801c336e == '\n');
  obj->state = 1;
  return;
}


// ---- 801e33f4 FUN_801e33f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e33f4(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  obj->speed_y_up = -0x8000;
  obj->gravity = 0x4000;
  cVar1 = FUN_801e364c();
  if ((cVar1 != '\0') && (obj->dmg_table == 0)) {
    obj->dmg_table = 4;
  }
  if (obj->contact_dmg == 0) {
    if (obj->dmg_table == 0) {
      return;
    }
    bVar2 = obj->dmg_table - 1;
    obj->dmg_table = bVar2;
    if (bVar2 != 0) {
      obj->x = *(short *)&obj->field_0x4c + (obj->dmg_table >> 1 & 1);
      return;
    }
  }
  obj->state = 2;
  obj->dmg_table = 1;
  obj->x = CONCAT11(obj->field_0x4d,obj->field_0x4c);
  if (obj->contact_dmg == 0) {
    bVar2 = 9;
  }
  else {
    bVar2 = 0xb;
  }
  obj->invuln = bVar2;
  FUN_8010544c(obj,0x74);
  return;
}


// ---- 801e34f8 FUN_801e34f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e34f8(MM8Obj *obj)

{
  byte bVar1;
  
  FUN_801e35f0();
  if (obj->dmg_table == 0) {
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      if (0x20000 < obj->speed_y_up) {
        obj->speed_y_up = 0x20000;
        obj->gravity = 0;
      }
      FUN_80102ef4((uint)(DAT_801c336e == '\n') << 2,(int)obj->x,(int)obj->y);
      obj->state = 3;
    }
  }
  else {
    bVar1 = obj->dmg_table - 1;
    obj->dmg_table = bVar1;
    if (bVar1 == 0) {
      Anim_StepN(obj,1);
    }
  }
  return;
}


// ---- 801e35b8 FUN_801e35b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e35b8(MM8Obj *obj)

{
  FUN_80104ccc();
  FUN_801e35f0(obj);
  return;
}


// ---- 801e35f0 FUN_801e35f0

void FUN_801e35f0(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (((*(char *)(param_1 + 0x46) != '\0') &&
      (cVar1 = *(char *)(param_1 + 0x46) + -1, *(char *)(param_1 + 0x46) = cVar1, cVar1 == '\0')) &&
     (iVar2 = FUN_801093fc(param_1 + 0x48), iVar2 != 0)) {
    *(undefined1 *)(iVar2 + 0x45) = 1;
  }
  return;
}


// ---- 801e364c FUN_801e364c

uint FUN_801e364c(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar1 = *(undefined2 *)(param_1 + 0x12);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_1 + 0x4e);
  uVar2 = FUN_80107bf4(param_1,&g_player,0);
  uVar2 = uVar2 & 0x80;
  if (uVar2 != 0) {
    if (7 < (ushort)(DAT_8015e234 + 8U)) {
      uVar2 = 0;
    }
    if (DAT_8015e24c._2_2_ < DAT_8015e272) {
      uVar2 = 0;
    }
  }
  *(undefined2 *)(param_1 + 0x12) = uVar1;
  return uVar2;
}


