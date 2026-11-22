// T2_15, STAGE02.BIN, handler 0x801E37DC. Ghidra output with the object struct applied; not matching C.
// ---- 801e37dc FUN_801e37dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e37dc(MM8Obj *obj)

{
  if ((obj->var & 0x80) == 0) {
    (*(code *)(&PTR_LAB_801e8a14)[obj->state])();
  }
  else {
    (*(code *)(&PTR_FUN_801e8a0c)[obj->state])(obj);
    if (obj->contact_dmg == 0) {
      Obj_CullAndQueueDraw(obj);
    }
  }
  return;
}


// ---- 801e387c FUN_801e387c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e387c(MM8Obj *obj)

{
  word wVar1;
  byte bVar2;
  
  obj->state = 1;
  obj->speed_x = 0;
  obj->speed_y_up = 0;
  obj->accel_x = 0;
  bVar2 = DAT_80159f8c;
  obj->draw_list = 8;
  obj->flip = 0;
                    /* Possible PsyQ macro: setPolyF4() */
  obj->bank = 0x28;
  obj->clut = bVar2;
  wVar1 = DAT_80170398;
  obj->field_0x33 = 0;
  obj->field_0x40 = 0;
  obj->field_0x43 = 0;
  obj->vram_base = wVar1;
  if ((obj->var == 0xc3) || (obj->var == 0x83)) {
    bVar2 = 0x80;
  }
  else {
    bVar2 = Rand();
    bVar2 = (bVar2 & 0x7f) + 0x40;
  }
  obj->invuln = bVar2;
  obj->dmg_table = 1;
  obj->contact_dmg = 0;
  Anim_Set(obj,9);
  return;
}


// ---- 801e3938 FUN_801e3938

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3938(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e8a1c)[obj->sub2])();
  return;
}


// ---- 801e3974 FUN_801e3974

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3974(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = FUN_801e3c54();
  if (iVar2 == 0) {
    bVar1 = obj->invuln - 1;
    obj->invuln = bVar1;
    if (bVar1 == 0) {
      if (obj->var == 0xff) {
        obj->invuln = 1;
      }
      else if (obj->dmg_table == 1) {
        obj->sub2 = 1;
        obj->invuln = 0x40;
        obj->dmg_table = 0;
        Anim_Set(obj,10);
        puVar3 = (undefined1 *)Obj_AllocMain();
        if (puVar3 != (undefined1 *)0x0) {
          *puVar3 = 1;
          puVar3[6] = 0xf;
          puVar3[7] = obj->var;
          *(short *)(puVar3 + 0xe) = obj->x + -3;
          *(short *)(puVar3 + 0x12) = obj->y + 0xe;
        }
      }
    }
    else {
      Anim_Step(obj);
    }
  }
  else {
    obj->sub2 = 1;
    bVar1 = 0x3a;
    if ((*(int *)(iVar2 + 0x50) < 0x30000) && (bVar1 = 0x42, *(int *)(iVar2 + 0x50) < 0x20000)) {
      bVar1 = 0x4a;
    }
    obj->invuln = bVar1;
                    /* Possible PsyQ macro: setLineF2() */
    if (*(int *)(iVar2 + 0x18) != 0x20000) {
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 0x50);
    }
    *(undefined1 *)(iVar2 + 0x5a) = 1;
    obj->dmg_table = 0;
    Anim_Set(obj,10);
  }
  return;
}


// ---- 801e3ad8 FUN_801e3ad8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3ad8(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = obj->invuln - 1;
  obj->invuln = bVar1;
  if (bVar1 == 0) {
    iVar2 = FUN_801e3c54();
    if (iVar2 == 0) {
      obj->sub2 = 2;
      obj->invuln = 0x13;
      obj->contact_dmg = 0;
      Anim_Set(obj,0xb);
    }
    else {
      bVar1 = 0x3a;
      if ((*(int *)(iVar2 + 0x50) < 0x30000) && (bVar1 = 0x42, *(int *)(iVar2 + 0x50) < 0x20000)) {
        bVar1 = 0x4a;
      }
      obj->invuln = bVar1;
      if (*(int *)(iVar2 + 0x18) != 0x20000) {
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 0x50);
      }
      *(undefined1 *)(iVar2 + 0x5a) = 1;
    }
  }
  else {
    if (obj->anim_extra == 1) {
      obj->contact_dmg = 1;
    }
    Anim_Step(obj);
  }
  return;
}


// ---- 801e3bc8 FUN_801e3bc8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e3bc8(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = obj->invuln - 1;
  obj->invuln = bVar1;
  if (bVar1 == 0) {
    obj->sub2 = 0;
    if ((obj->var == 0xc3) || (obj->var == 0x83)) {
      bVar1 = 0x80;
    }
    else {
      bVar1 = Rand();
      bVar1 = (bVar1 & 0x7f) + 0x40;
    }
    obj->invuln = bVar1;
    obj->dmg_table = 1;
  }
  else {
    Anim_Step(obj);
  }
  return;
}


// ---- 801e3c54 FUN_801e3c54

char * FUN_801e3c54(int param_1)

{
  ushort uVar1;
  short *psVar2;
  char *pcVar3;
  
  pcVar3 = &g_main_pool;
  psVar2 = &DAT_8015b182;
  do {
    if ((*pcVar3 != '\0') && ((char)psVar2[-4] == '\x0f')) {
      if (*(char *)((int)psVar2 + 0x17) == '\0') {
        uVar1 = *psVar2 - *(short *)(param_1 + 0xe);
      }
      else {
        uVar1 = *(short *)(param_1 + 0xe) - *psVar2;
      }
      if (uVar1 < 0x30) {
        return pcVar3;
      }
    }
    pcVar3 = pcVar3 + 0x60;
    psVar2 = psVar2 + 0x30;
    if (&DAT_8015c974 <= pcVar3) {
      return (char *)0x0;
    }
  } while( true );
}


