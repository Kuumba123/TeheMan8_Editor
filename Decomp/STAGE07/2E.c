// ID 2E, STAGE07.BIN, handler 0x801D8580. Ghidra output with the object struct applied; not matching C.
// ---- 801d8580 FUN_801d8580

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8580(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  char *pcVar5;
  
  (*(code *)(&PTR_FUN_801e082c)[obj->state])();
  obj->clut = (&DAT_80159f64)[obj->bank];
  cVar2 = Enemy_CheckWeaponHits(obj);
  if (cVar2 == '\x02') {
    obj->clut = 0;
    if (obj->var == 0) {
      obj->var = 1;
      Anim_SetAtStep(obj,obj->field_0x4 + '\x03',obj->anim_extra & 0x1f);
      puVar3 = (undefined1 *)FUN_801055e4(obj);
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        puVar3[6] = 0x2e;
        puVar3[1] = 0;
        bVar1 = obj->flip;
        puVar3[7] = 2;
        puVar3[0x25] = ((bVar1 & 0x40) == 0) << 6;
        *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
        *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)&obj->y_frac;
        pbVar4 = obj->spawn_record;
        *(MM8Obj **)(puVar3 + 0x50) = obj;
        *(byte **)(puVar3 + 8) = pbVar4;
        *(undefined1 **)&obj->field_0x50 = puVar3;
      }
    }
LAB_801d8700:
    obj->hitbox = &UNK_801e07e0 + ((uint)(obj->anim_extra >> 5) + (uint)obj->var * 3) * 4;
    obj->box2 = &UNK_801e0804 + (uint)obj->var * 5;
    Enemy_ContactDamage(obj);
    Obj_CullAndQueueDraw(obj);
    cVar2 = Obj_InActiveArea(obj);
    if (cVar2 != '\0') {
      return;
    }
    if (((obj->var == 0) || (pcVar5 = *(char **)&obj->field_0x50, *pcVar5 == '\0')) ||
       (pcVar5[6] != obj->id)) goto LAB_801d87c4;
    cVar2 = pcVar5[7];
  }
  else {
    if (cVar2 != '\x04') goto LAB_801d8700;
    FUN_80108e84(obj);
    FUN_8012a5fc(obj,0);
    FUN_80108fd8(obj,0);
    if (((obj->var == 0) || (pcVar5 = *(char **)&obj->field_0x50, *pcVar5 == '\0')) ||
       (pcVar5[6] != obj->id)) goto LAB_801d87c4;
    cVar2 = pcVar5[7];
  }
  if (cVar2 != '\0') {
    Obj_Free(obj);
    return;
  }
LAB_801d87c4:
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801d87e4 FUN_801d87e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d87e4(MM8Obj *obj)

{
  Enemy_InitFromTable();
  if (obj->var == 2) {
    obj->hp = 1;
  }
  if (obj->var == 0) {
    FUN_8010910c(obj);
  }
  obj->draw_list = 5;
  obj->state = 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  Anim_Set(obj,obj->var * '\x03');
  obj->hitbox = &UNK_801e07e0 + ((uint)(obj->anim_extra >> 5) + (uint)obj->var * 3) * 4;
                    /* Probable PsyQ macro: setPolyGT4() */
  obj->box2 = &UNK_801e0804 + (uint)obj->var * 5;
  return;
}


// ---- 801d88b4 FUN_801d88b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d88b4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e0838)[obj->sub2])();
  return;
}


// ---- 801d88f0 FUN_801d88f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d88f0(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    if ((obj->anim_extra & 0x1f) == 2) {
      iVar1 = *(int *)(&DAT_801e0818 + (uint)obj->var * 8);
      obj->gravity = 0x4000;
      obj->speed_y_up = iVar1;
      iVar1 = *(int *)(&DAT_801e0814 + (uint)obj->var * 8);
      if ((obj->flip & 0x40) == 0) {
        iVar1 = -iVar1;
      }
      obj->speed_x = iVar1;
      obj->sub3 = 1;
      if ((obj->var & 2) == 0) {
        FUN_8010544c(obj,0x113);
      }
      else {
        FUN_8010544c(obj,0x114);
      }
    }
  }
  else {
    Obj_ApplySpeed(obj);
    if (obj->speed_y_up < -0x60000) {
      obj->speed_y_up = -0x60000;
      obj->gravity = 0;
    }
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x30) != 0) {
      obj->speed_x = -obj->speed_x;
      obj->flip = ((obj->flip & 0x40) == 0) << 6;
    }
    if ((obj->field_0x33 & 0x40) != 0) {
      obj->speed_y_up = 0;
    }
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->sub2 = 1;
      obj->speed_x = 0;
      obj->speed_y_up = 0;
      obj->gravity = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 2;
      obj->field_0x55 = 0;
      Anim_Set(obj,obj->var * '\x03' + '\x02');
      return;
    }
  }
  if (((obj->field_0x4 == '\0') && (obj->speed_y_up < 0)) &&
     (((int)(short)obj->frame & 0x8000U) != 0)) {
    obj->field_0x4 = 1;
    Anim_Set(obj,obj->var * '\x03' + '\x01');
  }
  Anim_Step(obj);
  return;
}


// ---- 801d8aec FUN_801d8aec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d8aec(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  undefined1 uVar3;
  
  if (obj->field_0x55 == '\0') {
    FUN_80106214(obj);
    if (obj->sub3 == 0) {
      if (((int)(short)obj->frame & 0x8000U) != 0) {
        obj->sub3 = 1;
        uVar2 = Rand();
        uVar3 = 0x78;
        if ((uVar2 & 1) != 0) {
          uVar3 = 0x28;
        }
        obj->field_0x54 = uVar3;
      }
      Anim_Step(obj);
    }
    else {
      cVar1 = obj->field_0x54;
      obj->field_0x54 = cVar1 + -1;
      if (cVar1 == '\0') {
        Anim_Set(obj,obj->var * '\x03');
        obj->sub2 = 0;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
        FUN_8010910c(obj);
      }
    }
    if ((obj->field_0x33 & 0x80) == 0) {
      obj->field_0x55 = 1;
      obj->gravity = 0x4000;
      obj->speed_y_up = 0;
    }
  }
  else {
    Obj_ApplySpeed();
                    /* Possible PsyQ macro: setPolyF4() */
    if (obj->speed_y_up < -0x60000) {
      obj->speed_y_up = -0x60000;
      obj->gravity = 0;
    }
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0x80) != 0) {
      obj->speed_y_up = 0;
      obj->gravity = 0;
      obj->field_0x55 = 0;
    }
  }
  return;
}


