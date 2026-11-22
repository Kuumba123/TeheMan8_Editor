// T2_0B, STAGE02.BIN, handler 0x801E2E58. Ghidra output with the object struct applied; not matching C.
// ---- 801e2e58 FUN_801e2e58

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2e58(MM8Obj *obj)

{
  byte bVar1;
  
  if (obj->state == 0) {
                    /* Possible PsyQ macro: setPolyFT4() + setSemiTrans(polyFT4, 1) */
    obj->bank = 0x2e;
    obj->vram_base = DAT_801703a4;
    bVar1 = DAT_80159f92;
    obj->draw_list = 8;
    obj->clut = bVar1;
    obj->flip = 0;
    if (obj->var == 1) {
      obj->speed_y_up = -0x50000;
      obj->gravity = 0x4000;
      obj->hitbox = &DAT_801e89a8;
      obj->contact_dmg = 10;
      obj->speed_x = 0;
      obj->dmg_table = 1;
      obj->hp = 1;
      obj->invuln = 0;
      obj->draw_list = 3;
      FUN_800fd100(0x8a);
    }
    if (obj->var == 0) {
      obj->dmg_table = 2;
      obj->contact_dmg = 5;
      obj->hp = 1;
      obj->invuln = 1;
      obj->draw_list = 6;
      FUN_800fd100(0x89);
    }
    obj->state = 1;
    obj->sub2 = 0;
    Anim_Set(obj,(&DAT_801e89e8)[obj->var]);
  }
  else {
    (*(code *)(&PTR_FUN_801e89d0)[obj->var])(obj,*(undefined4 *)&obj->field_0x4c);
    if (obj->state == 2) {
      Obj_Free(obj);
    }
    else {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801e2fbc FUN_801e2fbc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2fbc(MM8Obj *obj)

{
  int in_a1;
  
  if ((short)obj->frame < 0) {
    *(undefined2 *)(in_a1 + 0xe) = 0;
    obj->state = 2;
  }
  else {
    Anim_Step(obj);
    obj->hitbox = &UNK_801e89ac + (uint)obj->anim_extra * 4;
    Enemy_ContactDamage();
  }
  return;
}


// ---- 801e3024 FUN_801e3024

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3024(MM8Obj *obj)

{
  int in_a1;
  
  FUN_80104ccc();
  if (obj->y + 0x15 < obj->accel_x) {
    Enemy_ContactDamage(obj);
  }
  else {
    FUN_80108e84(obj);
    FUN_8012ae08(obj,7);
    if (*(char *)(in_a1 + 7) == '\x02') {
      DAT_801d2938 = 0x2e;
    }
    else {
      DAT_801d2936 = 0x2e;
    }
    *(undefined2 *)(in_a1 + 0xe) = 0;
    obj->state = 2;
  }
  return;
}


// ---- 801e30c4 FUN_801e30c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e30c4(MM8Obj *obj)

{
  int in_a1;
  
  if ((short)obj->frame < 0) {
    *(undefined1 *)(in_a1 + 0x17) = 1;
    obj->state = 2;
  }
  else {
    Anim_Step(obj);
    if (obj->anim_extra != 0) {
      obj->anim_extra = 0;
      DAT_801b2998 = 1;
      DAT_8015e26f = DAT_8015e26f ^ 0x80;
    }
    if (obj->y + 8 < (int)DAT_8015e24c._2_2_) {
      DAT_8015e241 = 0;
    }
    if (obj->y + 10 < (int)DAT_8015e24c._2_2_) {
      DAT_801b2998 = 0;
      DAT_8015e24c._2_2_ = obj->y + 10;
    }
  }
  return;
}


// ---- 801e3190 FUN_801e3190

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3190(MM8Obj *obj)

{
  int in_a1;
  
  if ((short)obj->frame < 0) {
    DAT_801b2998 = 0;
    *(undefined1 *)(in_a1 + 0x17) = 2;
    obj->state = 2;
  }
  else {
    Anim_Step(obj);
    if (obj->anim_extra != 0) {
      obj->anim_extra = 0;
      FUN_80111918();
      DAT_801b2998 = 1;
      DAT_8015e26f = DAT_8015e26f ^ 0x80;
      FUN_80111aa0(DAT_8015e261);
    }
    if ((int)DAT_8015e24c._2_2_ < obj->y + 8) {
      DAT_8015e241 = 1;
    }
  }
  return;
}


// ---- 801e324c FUN_801e324c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e324c(MM8Obj *obj)

{
  int in_a1;
  
  if ((short)obj->frame < 0) {
    *(undefined2 *)(in_a1 + 0xe) = 0;
    obj->state = 2;
  }
  else {
    Anim_Step(obj);
    if (obj->sub2 == 0) {
      if (obj->anim_extra != 0) {
        obj->anim_extra = 0;
        obj->invuln = 0x18;
        obj->sub2 = 1;
        DAT_801b2998 = 1;
        DAT_8015e26f = DAT_8015e26f & 0x7f;
      }
    }
    else if ((obj->sub3 == 0) && (obj->invuln = obj->invuln - 1, obj->invuln == 0)) {
      obj->sub3 = 1;
      DAT_801b2998 = 0;
      DAT_8015e2af = 0;
      DAT_8015e2b9 = 0;
      FUN_80111918();
    }
  }
  return;
}


// ---- 801e333c FUN_801e333c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e333c(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    obj->state = 2;
  }
  else {
    Anim_Step(obj);
    if (obj->anim_extra != 0) {
      obj->anim_extra = 0;
    }
  }
  return;
}


