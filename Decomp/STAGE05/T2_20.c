// T2_20, STAGE05.BIN, handler 0x801E752C. Ghidra output with the object struct applied; not matching C.
// ---- 801e752c FUN_801e752c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e752c(MM8Obj *obj)

{
  word wVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  
  obj->var = obj->var & 0xf;
  if (obj->state == 0) {
    obj->bank = 0x5b;
    obj->clut = DAT_80159fbf;
    wVar1 = DAT_801703fe;
    obj->speed_y_up = 0x2000;
    obj->gravity = 0x100;
    obj->box2 = &DAT_801eaa14;
    obj->field_0x43 = 0;
    obj->field_0x33 = 0;
    obj->field_0x40 = 0;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->hitbox = (byte *)0x0;
    obj->draw_list = 8;
    obj->flip = 0;
    obj->target_prio = 0;
    obj->field_0x49 = 0;
    *(short *)&obj->field_0x4a = obj->y;
    obj->field_0x4c = 0;
    obj->var = 0;
    obj->vram_base = wVar1;
    Anim_Set(obj,0);
    obj->sub2 = 0;
    obj->state = obj->state + 1;
  }
  FUN_80104ccc(obj);
  FUN_80107bf4(obj,&g_player,6);
  bVar4 = obj->var;
  if ((obj->field_0x40 & 0x40) != 0) {
    bVar4 = bVar4 | 0x80;
  }
  obj->var = bVar4;
  if (obj->target_prio == 0) {
    if (obj->field_0x4c == '\0') {
      FUN_801e77d0(obj);
    }
    else {
      obj->speed_y_up = -0x50000;
      obj->gravity = 0;
      obj->target_prio = 1;
      obj->sub2 = 0;
    }
  }
  else {
    bVar4 = obj->sub2;
    if (bVar4 == 0) {
      if (0x5b < (int)obj->y - (int)*(short *)&obj->field_0x4a) {
        obj->field_0x49 = 0x14;
        obj->speed_y_up = 0;
        obj->gravity = 0;
        obj->field_0x4c = 0;
        obj->sub2 = 1;
        *(int *)&obj->y_frac = (*(short *)&obj->field_0x4a + 0x5c) * 0x10000;
      }
    }
    else if (bVar4 == 1) {
      cVar2 = obj->field_0x49 + -1;
      obj->field_0x49 = cVar2;
      if (cVar2 == '\0') {
        obj->speed_y_up = 0x20000;
        obj->sub2 = 2;
      }
    }
    else if (bVar4 == 2) {
      if (obj->y <= *(short *)&obj->field_0x4a) {
        obj->gravity = 0x4000;
        obj->sub2 = 3;
      }
    }
    else if (bVar4 == 3) {
      if (obj->speed_y_up < -0x1fff) {
        obj->speed_y_up = -0x2000;
      }
      if (((int)*(short *)&obj->field_0x4a < (int)obj->y) && (obj->speed_y_up < 0)) {
        iVar3 = (int)*(short *)&obj->field_0x4a << 0x10;
        obj->y_frac = (short)iVar3;
        obj->y = (short)((uint)iVar3 >> 0x10);
        obj->speed_y_up = -0x2000;
        obj->gravity = -0x100;
        obj->field_0x4c = 0;
        obj->target_prio = 0;
      }
    }
  }
  iVar3 = FUN_80104820(obj,0x38,100);
  if (iVar3 == 0) {
    Obj_FreeDespawn(obj);
  }
  else {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e77d0 FUN_801e77d0

void FUN_801e77d0(int param_1)

{
  if (0x4000 < *(int *)(param_1 + 0x18) + 0x2000U) {
    *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
  }
  return;
}


