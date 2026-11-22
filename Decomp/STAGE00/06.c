// ID 06, STAGE00.BIN, handler 0x801D93EC. Ghidra output with the object struct applied; not matching C.
// ---- 801d93ec FUN_801d93ec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d93ec(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e26a0)[obj->state])();
  if (((obj->field_0x53 & 1) != 0) && (obj->active != 0)) {
    if (obj->var == 3) {
      Obj_CullAndQueueDraw(obj);
      iVar1 = Obj_InActiveArea(obj);
      if (iVar1 == 0) {
        Obj_Free(obj);
      }
    }
    else {
      Obj_CullAndQueueDrawMargin(obj,0x60);
    }
  }
  return;
}


// ---- 801d9498 FUN_801d9498

/* WARNING: Removing unreachable block (ram,0x801d94f4) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9498(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  
  obj->bank = 0xe;
  bVar2 = obj->var;
  obj->vram_base = DAT_80170364;
  bVar1 = DAT_80159f72;
  obj->field_0x53 = 1;
  obj->field_0x43 = 0;
  obj->clut = bVar1;
  if (bVar2 < 3) {
    if (bVar2 == 0) {
      obj->box2 = &DAT_801e25bc;
      obj->hitbox = &DAT_801e25d8;
                    /* Possible PsyQ macro: setPolyF4() */
      obj->hp = 0x28;
      obj->contact_dmg = 3;
      obj->draw_list = 7;
      obj->field_0x50 = 0x1e;
      obj->state = 1;
      obj->dmg_table = 0;
      obj->invuln = 0;
      obj->field_0x59 = 10;
      obj->field_0x5a = 0;
      obj->flip = 0;
      obj->field_0x5d = 0;
      obj->field_0x55 = 0;
      obj->field_0x54 = 0;
      bVar2 = Rand();
      cVar3 = '\0';
      obj->field_0x5c = (bVar2 & 7) + 2;
    }
    else {
      obj->state = 2;
      obj->contact_dmg = 3;
                    /* Possible PsyQ macro: setPolyF4() */
      obj->dmg_table = 0;
      obj->invuln = 1;
      obj->hp = 1;
      obj->box2 = &UNK_801e25bf + (uint)obj->var * 5;
      bVar2 = 5;
      if (obj->var == 1) {
        bVar2 = 6;
      }
      obj->draw_list = bVar2;
      cVar3 = obj->var + 0x11;
    }
  }
  else {
    if (bVar2 != 3) {
      return;
    }
    obj->state = 3;
    obj->box2 = &DAT_801e25d0;
    obj->hitbox = &DAT_801e2604;
    obj->gravity = 0x4000;
    obj->speed_y_up = 0x6e000;
    obj->dmg_table = 2;
    obj->hp = 1;
    obj->contact_dmg = 2;
    if ((obj->flip & 0x40) == 0) {
      obj->speed_x = -obj->speed_x;
    }
    obj->draw_list = 5;
    cVar3 = '\x11';
  }
  Anim_Set(obj,cVar3);
  return;
}


// ---- 801d9678 FUN_801d9678

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9678(MM8Obj *obj)

{
  obj->field_0x53 = obj->field_0x53 & 0xfd;
  (*(code *)(&PTR_FUN_801e26b0)[obj->sub2])();
  if ((obj->field_0x53 & 2) == 0) {
    obj->clut = DAT_80159f72;
  }
  else {
    obj->clut = 0;
  }
  return;
}


// ---- 801d96f4 FUN_801d96f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d96f4(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  if (obj->sub3 == 0) {
    if (0x13ff < DAT_801d2918._2_2_) {
      obj->field_0x51 = 0xb4;
      obj->sub3 = obj->sub3 + 1;
    }
  }
  else {
    cVar1 = obj->field_0x51 + -1;
    obj->field_0x51 = cVar1;
    if (cVar1 == '\0') {
      obj->sub3 = 0;
      obj->sub2 = obj->sub2 + 1;
      FUN_800fcb80(2);
    }
  }
  if (obj->field_0x50 == '\0') {
    if ((short)obj->frame < 0) {
      Anim_Set(obj,1);
      bVar2 = Rand();
      obj->field_0x50 = (bVar2 & 3) * '\x1e' + 'x';
    }
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  Anim_Step(obj);
  Enemy_CheckWeaponHits(obj);
  return;
}


// ---- 801d97f0 FUN_801d97f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d97f0(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e26c4)[obj->sub3])();
  Anim_Step(obj);
  Enemy_CheckWeaponHits(obj);
  return;
}


// ---- 801d9cac FUN_801d9cac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9cac(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  (*(code *)(&PTR_LAB_801e26d4)[obj->sub3])();
  FUN_801dc484(obj,7,2);
  iVar3 = FUN_801dc150(obj,&DAT_801e25dc);
  if (iVar3 != 0) {
    if (iVar3 == 5) {
      obj->sub2 = 4;
      obj->field_0x5e = 0x80;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      DAT_8015e282 = 1;
    }
    else {
      if (iVar3 == 1) {
        if (obj->field_0x43 != '\0') {
          return;
        }
        cVar1 = obj->field_0x5c + -1;
        obj->field_0x5c = cVar1;
        if (cVar1 != '\0') {
          return;
        }
        bVar2 = Rand();
        obj->field_0x5c = (bVar2 & 3) + 3;
      }
      obj->sub2 = 3;
      obj->sub3 = 0;
                    /* Possible PsyQ macro: setLineF2() */
      obj->field_0x4 = 0;
      obj->field_0x52 = (char)iVar3;
      obj->field_0x5e = 0x40;
    }
  }
  return;
}


// ---- 801dab30 FUN_801dab30

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dab30(MM8Obj *obj)

{
  int iVar1;
  undefined *puVar2;
  
  (*(code *)(&PTR_FUN_801e272c)[obj->sub3])();
  FUN_801dc3e8(obj,0x3c);
  Anim_Step(obj);
  obj->field_0x5d = obj->anim_extra;
  FUN_801dc484(obj,7,2);
  if (obj->field_0x58 == '\0') {
    puVar2 = &DAT_801e25dc;
  }
  else {
    puVar2 = &DAT_801e25e8;
  }
  iVar1 = FUN_801dc150(obj,puVar2);
  if (iVar1 == 5) {
    obj->sub2 = 4;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->field_0x5e = 0x80;
  }
  return;
}


// ---- 801dabf8 FUN_801dabf8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dabf8(MM8Obj *obj)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = obj->field_0x52;
  obj->field_0x57 = 2;
  obj->field_0x58 = 1;
  obj->field_0x4 = 0;
  if (bVar1 == 2) {
LAB_801dac74:
    uVar2 = 10;
    obj->sub3 = 1;
    obj->field_0x55 = 0;
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 != 1) goto LAB_801dac90;
    }
    else {
      if (bVar1 == 3) {
        obj->field_0x57 = 4;
        goto LAB_801dac74;
      }
      if (bVar1 != 4) goto LAB_801dac90;
    }
    uVar2 = 0x33;
    obj->sub3 = 4;
    obj->field_0x58 = 0;
  }
  Anim_Set(obj,uVar2);
LAB_801dac90:
  if ((obj->field_0x54 & 2) != 0) {
    FUN_80111c28();
    obj->field_0x54 = obj->field_0x54 & 0xfd;
  }
  return;
}


// ---- 801dacd0 FUN_801dacd0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dacd0(MM8Obj *obj)

{
  undefined1 uVar1;
  
  if ((char)obj->field_0x57 < '\x01') {
    obj->field_0x58 = 0;
  }
  if ((short)obj->frame < 0) {
    if (obj->field_0x58 == '\0') {
      obj->field_0x5e = 1;
      obj->sub3 = 3;
    }
    else {
      obj->sub3 = obj->sub3 + 1;
      uVar1 = 0x3c;
      if (obj->field_0x52 == '\x03') {
        uVar1 = 0xb4;
      }
      obj->field_0x50 = uVar1;
      obj->field_0x5e = 1;
      Anim_Set(obj,0xb);
    }
  }
  return;
}


// ---- 801dae9c FUN_801dae9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dae9c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e2740)[obj->sub3])();
  Anim_Step(obj);
  return;
}


// ---- 801daeec FUN_801daeec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daeec(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x50 = 0x5a;
    obj->field_0x4 = obj->field_0x4 + '\x01';
    Anim_Set(obj,0xd);
    if ((obj->field_0x54 & 2) != 0) {
      FUN_80111c28();
      obj->field_0x54 = obj->field_0x54 & 0xfd;
    }
    DAT_801b2993 = 1;
  }
  else {
    if ((obj->field_0x43 == '\0') &&
       (cVar1 = obj->field_0x50 + -1, obj->field_0x50 = cVar1, cVar1 == '\0')) {
      obj->field_0x4 = 0;
      obj->sub3 = obj->sub3 + 1;
    }
    FUN_801dc3e8(obj,0x3c);
  }
  FUN_801dc484(obj,7,4);
  return;
}


// ---- 801dafcc FUN_801dafcc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dafcc(MM8Obj *obj)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 uVar4;
  
  bVar1 = obj->field_0x4;
  uVar4 = 4;
  if (bVar1 == 1) {
    cVar3 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar3;
    uVar4 = 5;
    if (cVar3 != '\0') goto LAB_801db0d8;
    obj->field_0x4 = obj->field_0x4 + '\x01';
    FUN_801dc584(obj,0xffffffe5,0xffffffde,3);
    uVar2 = 1;
  }
  else {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        cVar3 = obj->field_0x50 + -1;
        obj->field_0x50 = cVar3;
        uVar4 = 6;
        if (cVar3 == '\0') {
          obj->field_0x50 = 0x14;
          obj->field_0x4 = 0;
          obj->field_0x51 = 1;
          obj->sub3 = obj->sub3 + 1;
        }
      }
      goto LAB_801db0d8;
    }
    if (bVar1 != 0) goto LAB_801db0d8;
    obj->field_0x4 = obj->field_0x4 + '\x01';
    FUN_801dc584(obj,1,0xffffffe0,3);
    uVar2 = 2;
  }
  obj->field_0x5e = uVar2;
  obj->field_0x50 = 0x2d;
LAB_801db0d8:
  FUN_801dc484(obj,7,uVar4);
  return;
}


// ---- 801db0f8 FUN_801db0f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db0f8(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  obj->field_0x53 = obj->field_0x53 ^ 1;
  FUN_801dc484(obj,3,6);
  cVar1 = obj->field_0x51 + -1;
  obj->field_0x51 = cVar1;
  if (cVar1 == '\0') {
    uVar2 = Rand();
    iVar3 = (uVar2 & 7) * 2;
    FUN_801dc584(obj,(int)(char)(&DAT_801e2674)[iVar3],(int)(char)(&DAT_801e2675)[iVar3],2);
    obj->field_0x51 = 6;
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->field_0x4 = 0;
      obj->sub3 = obj->sub3 + 1;
    }
  }
  return;
}


// ---- 801db1b4 FUN_801db1b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db1b4(MM8Obj *obj)

{
  char cVar1;
  undefined1 *puVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = 0;
  if (obj->field_0x4 == '\0') {
    do {
      sVar3 = (short)iVar4;
      FUN_801dc584(obj,(int)(char)(&DAT_801e2674)[sVar3],(int)(char)(&DAT_801e2675)[sVar3],1);
      FUN_801dc584(obj,(int)(char)(&DAT_801e2674)[sVar3],(char)(&DAT_801e2675)[sVar3] + 0x20,1);
      iVar4 = iVar4 + 1;
    } while (iVar4 * 0x10000 >> 0x10 < 8);
    FUN_8012ae08(obj,0xe);
    obj->field_0x50 = 0x96;
    obj->field_0x4 = obj->field_0x4 + '\x01';
    DAT_801d2936 = 0x5a;
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      puVar2 = (undefined1 *)Obj_AllocType4();
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 1;
        puVar2[6] = 0x2d;
        puVar2[7] = 0;
      }
      DAT_801b297c = 0;
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801db2f0 FUN_801db2f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db2f0(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = *(int *)&obj->field_0x54;
  if ((obj->sub2 != 3) || (*(char *)(iVar1 + 0x43) != '\0')) {
    obj->x = *(short *)(iVar1 + 0xe);
    obj->y = (short)*(char *)(iVar1 + 0x5d) + *(short *)(iVar1 + 0x12);
    obj->flip = *(byte *)(*(int *)&obj->field_0x54 + 0x25);
  }
  (*(code *)(&PTR_FUN_801e2750)[obj->sub2])(obj);
  if ((*(byte *)(*(int *)&obj->field_0x54 + 0x53) & 2) == 0) {
    obj->clut = DAT_80159f72;
  }
  else {
    obj->clut = 0;
  }
  return;
}


// ---- 801db3c4 FUN_801db3c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db3c4(MM8Obj *obj)

{
  char cVar1;
  
  switch(obj->sub3) {
  case 0:
    if (obj->anim_extra != 0) {
      FUN_8010544c(obj,100);
      obj->anim_extra = 0;
    }
    if (-1 < (short)obj->frame) goto switchD_801db3f8_default;
    cVar1 = obj->var + 0x13;
    obj->sub3 = obj->sub3 + 1;
    break;
  case 1:
    if (obj->anim_extra != 0) {
      FUN_801dc6f8(obj,0x65);
      obj->anim_extra = 0;
    }
    if ((short)obj->frame < 0) {
      obj->field_0x50 = 0xf;
      obj->sub3 = obj->sub3 + 1;
    }
    goto switchD_801db3f8_default;
  case 2:
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->sub3 = obj->sub3 + 1;
      *(char *)(*(int *)&obj->field_0x54 + 0x5f) =
           *(char *)(*(int *)&obj->field_0x54 + 0x5f) + '\x01';
    }
    goto switchD_801db3f8_default;
  case 3:
    if (*(char *)(*(int *)&obj->field_0x54 + 0x5e) == '\0') goto switchD_801db3f8_default;
    cVar1 = obj->var + 0x15;
    obj->sub3 = obj->sub3 + 1;
    break;
  case 4:
    if (*(char *)(*(int *)&obj->field_0x54 + 0x5e) != '\0') goto switchD_801db3f8_default;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    cVar1 = obj->var + 0x2d;
    obj->sub2 = obj->sub2 + 1;
    break;
  default:
    goto switchD_801db3f8_default;
  }
  Anim_Set(obj,cVar1);
switchD_801db3f8_default:
  Anim_Step(obj);
  return;
}


// ---- 801db558 FUN_801db558

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db558(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = *(char *)(*(int *)&obj->field_0x54 + 0x5e);
  if (cVar1 == -0x80) {
    bVar2 = 3;
  }
  else {
    bVar2 = 2;
    if (cVar1 != '@') {
      (*(code *)(&PTR_FUN_801e2760)[obj->sub3])(obj);
      if (2 < obj->sub3) {
        return;
      }
      Anim_Step(obj);
      return;
    }
  }
  obj->sub2 = bVar2;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801db5f4 FUN_801db5f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db5f4(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x4 = obj->field_0x4 + '\x01';
    Anim_Set(obj,obj->var + 0x2d);
  }
  bVar1 = *(byte *)(*(int *)&obj->field_0x54 + 0x5e);
  if (bVar1 == 0) {
    return;
  }
  obj->sub3 = bVar1;
  obj->field_0x4 = 0;
  if (bVar1 == 2) {
    cVar2 = obj->var + 0x1f;
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 != 1) {
        return;
      }
      obj->hitbox = &DAT_801e2600;
      Anim_Set(obj,obj->var + 0x29);
      FUN_801dc6f8(obj,0x68);
      return;
    }
    if (bVar1 != 3) {
      return;
    }
    obj->field_0x50 = 1;
    obj->field_0x58 = 0;
    cVar2 = obj->var + 0x13;
    obj->hitbox = &UNK_801e25f0 + (uint)obj->var * 4;
  }
  Anim_Set(obj,cVar2);
  return;
}


// ---- 801db714 FUN_801db714

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db714(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = obj->field_0x4;
  if (bVar1 == 1) {
    if (obj->anim_extra != 0) {
      Enemy_ContactDamage(obj);
    }
    if ((short)obj->frame < 0) {
      obj->field_0x50 = 0x1e;
      obj->field_0x4 = obj->field_0x4 + '\x01';
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && ((short)obj->frame < 0)) {
      obj->field_0x50 = 0xf;
      obj->field_0x4 = obj->field_0x4 + '\x01';
      Anim_Set(obj,obj->var + 0x2b);
      FUN_801dc6f8(obj,0x6b);
    }
  }
  else if ((bVar1 == 2) && (cVar2 = obj->field_0x50 + -1, obj->field_0x50 = cVar2, cVar2 == '\0')) {
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    *(char *)(*(int *)&obj->field_0x54 + 0x5f) = *(char *)(*(int *)&obj->field_0x54 + 0x5f) + '\x01'
    ;
  }
  return;
}


// ---- 801dbd30 FUN_801dbd30

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbd30(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e2784)[obj->sub3])();
  Anim_Step(obj);
  if (*(char *)(*(int *)&obj->field_0x54 + 0x5e) == -0x80) {
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801dbda4 FUN_801dbda4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbda4(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(*(int *)&obj->field_0x54 + 0x52);
  if (bVar1 < 4) {
    if (1 < bVar1) {
      obj->sub3 = 1;
      cVar2 = obj->var + 0x21;
      goto LAB_801dbe10;
    }
    if (bVar1 != 1) {
      return;
    }
  }
  else if (bVar1 != 4) {
    return;
  }
  obj->sub3 = 3;
  cVar2 = obj->var + 0x33;
LAB_801dbe10:
  Anim_Set(obj,cVar2);
  return;
}


// ---- 801dbe28 FUN_801dbe28

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbe28(MM8Obj *obj)

{
  if (*(char *)(*(int *)&obj->field_0x54 + 0x5e) == '\x01') {
    obj->sub3 = obj->sub3 + 1;
    Anim_Set(obj,obj->var + 0x23);
  }
  return;
}


// ---- 801dbe74 FUN_801dbe74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbe74(MM8Obj *obj)

{
  if (*(char *)(*(int *)&obj->field_0x54 + 0x5e) == '\x02') {
    obj->sub3 = obj->sub3 + 1;
    Anim_Set(obj,obj->var + 0x25);
  }
  return;
}


// ---- 801dbefc FUN_801dbefc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbefc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e2794)[obj->sub3])();
  return;
}


// ---- 801dbf38 FUN_801dbf38

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbf38(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->field_0x4 == '\0') {
    obj->field_0x4 = obj->field_0x4 + '\x01';
    Anim_Set(obj,obj->var + 0x27);
  }
  if (obj->var == *(byte *)(*(int *)&obj->field_0x54 + 0x5e)) {
    obj->speed_y_up = -0x4000;
    obj->field_0x4 = 0;
    obj->speed_x = 0;
    obj->gravity = 0x4000;
    obj->sub3 = obj->sub3 + 1;
  }
  iVar1 = *(int *)&obj->field_0x54;
  obj->x = *(short *)(iVar1 + 0xe);
  obj->y = *(short *)(iVar1 + 0x12);
  obj->flip = *(byte *)(iVar1 + 0x25);
  Anim_Step();
  return;
}


// ---- 801dbff0 FUN_801dbff0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbff0(MM8Obj *obj)

{
  undefined1 *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined1 auStack_18 [4];
  undefined4 uStack_14;
  
  puVar1 = auStack_18 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | DAT_801d8040 >> (3 - uVar2) * 8;
  auStack_18 = (undefined1  [4])DAT_801d8040;
  uVar2 = (int)&uStack_14 + 3U & 3;
  puVar3 = (uint *)(((int)&uStack_14 + 3U) - uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | DAT_801d8044 >> (3 - uVar2) * 8;
  uStack_14 = DAT_801d8044;
  obj->field_0x53 = obj->field_0x53 ^ 1;
  FUN_80104ccc(obj);
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    iVar4 = (obj->var - 1) * 4;
    FUN_801dc584(obj,(int)*(short *)(auStack_18 + iVar4),(int)*(short *)(auStack_18 + iVar4 + 2),3);
    Obj_Free(obj);
  }
  return;
}


// ---- 801dc0a0 FUN_801dc0a0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc0a0(MM8Obj *obj)

{
  ushort uVar1;
  int iVar2;
  
  FUN_80104ccc();
  Anim_Step(obj);
  iVar2 = Enemy_CheckWeaponHits(obj);
  if (iVar2 == 4) {
    FUN_80108e84(obj);
    FUN_80108fd8(obj,4);
  }
  else {
    Enemy_ContactDamage(obj);
    FUN_80106214(obj);
    if ((obj->field_0x33 & 0xf0) == 0) {
      return;
    }
    uVar1 = Rand();
    obj->y = obj->y + -7 + (uVar1 & 0xf);
    FUN_80108e84(obj);
  }
  Obj_Free(obj);
  return;
}


// ---- 801dc150 FUN_801dc150

int FUN_801dc150(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_801dc310();
  *(int *)(param_1 + 0x3c) = param_2;
  *(undefined1 *)(param_1 + 0x44) = 0;
  iVar2 = Enemy_CheckWeaponHits(param_1);
  if ((iVar2 != 0) && (iVar1 == 0)) {
    if ((DAT_80158f5c == 2) && (*(char *)(DAT_8016d404 + 7) != '\0')) {
      return 3;
    }
    if (DAT_80158f5c < 2) {
      if ((DAT_80158f5c == 1) && (*(char *)(DAT_8016d404 + 7) == '\0')) {
        return 4;
      }
      return DAT_80158f5c + 1;
    }
  }
  Enemy_ContactDamage(param_1);
  *(int *)(param_1 + 0x3c) = param_2 + 4;
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x44) = 2;
    iVar2 = Enemy_CheckWeaponHits(param_1);
    if (iVar2 == 2) {
      *(char *)(param_1 + 0x57) = *(char *)(param_1 + 0x57) + -1;
      *(byte *)(param_1 + 0x53) = *(byte *)(param_1 + 0x53) | 2;
    }
  }
  else {
    iVar2 = Enemy_CheckWeaponHits(param_1);
    Enemy_ContactDamage(param_1);
  }
  if (iVar2 == 4) {
    iVar1 = 5;
  }
  else {
    *(int *)(param_1 + 0x3c) = param_2 + 8;
    *(undefined1 *)(param_1 + 0x44) = 0;
    iVar2 = Enemy_CheckWeaponHits(param_1);
    if ((((iVar2 == 0) || (iVar1 != 0)) || (DAT_80158f5c != 2)) ||
       (iVar1 = 3, *(char *)(DAT_8016d404 + 7) == '\0')) {
      Enemy_ContactDamage(param_1);
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ---- 801dc310 FUN_801dc310

byte FUN_801dc310(int param_1)

{
  return (*(int *)(param_1 + 0xc) <= DAT_8015e248) << 6 ^ *(byte *)(param_1 + 0x25) & 0x40;
}


// ---- 801dc3e8 FUN_801dc3e8

void FUN_801dc3e8(int param_1,short param_2)

{
  if (*(char *)(param_1 + 0x43) != '\0') {
    FUN_80104ccc();
    FUN_80106214(param_1);
    if ((*(byte *)(param_1 + 0x33) & 0x80) != 0) {
      DAT_801d2936 = param_2;
      *(undefined1 *)(param_1 + 0x43) = 0;
      FUN_8010544c(param_1,0x6a);
      if (0x14 < param_2) {
        FUN_801dc65c(param_1);
      }
    }
  }
  return;
}


// ---- 801dc484 FUN_801dc484

void FUN_801dc484(int param_1,short param_2,uint param_3)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  
  uVar7 = 0;
                    /* Possible PsyQ macro: setLineF2() */
  bVar1 = *(byte *)(param_1 + 0x25);
  sVar2 = *(short *)(param_1 + 0xe);
  uVar3 = *(ushort *)(param_1 + 0x12);
  if ((param_3 & 0xff) != 0) {
    pcVar6 = &DAT_801e2668;
    do {
      uVar4 = Rand();
                    /* Probable PsyQ macro: setTile16() */
      if ((uVar4 & (int)param_2) == 0) {
        if ((bVar1 & 0x40) == 0) {
          iVar5 = (int)*pcVar6;
        }
        else {
          iVar5 = -(int)*pcVar6;
        }
        FUN_801091a4((sVar2 + iVar5) * 0x10000 >> 0x10,
                     (int)(((uint)uVar3 + (int)(char)(&DAT_801e2669)[uVar7]) * 0x10000) >> 0x10,1);
      }
      uVar7 = uVar7 + 2;
      pcVar6 = pcVar6 + 2;
    } while (uVar7 < (param_3 & 0xff) << 1);
  }
  return;
}


// ---- 801dc584 FUN_801dc584

void FUN_801dc584(undefined4 param_1,short param_2,short param_3,byte param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  FUN_801dc728(param_1,0,0,(int)param_2,(int)param_3);
  if ((param_4 != 0) && (uVar3 = 0, param_4 != 0)) {
    do {
      uVar1 = Rand();
      iVar2 = FUN_801dc728(param_1,1,(&DAT_801e2684)[uVar1 & 7],(int)param_2,(int)param_3);
      uVar3 = uVar3 + 1;
      if (iVar2 == 0) {
        uVar3 = 4;
      }
    } while (uVar3 < param_4);
  }
  return;
}


// ---- 801dc65c FUN_801dc65c

void FUN_801dc65c(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = FUN_801dc728(param_1,0xf,0x10,0,0x38);
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0x27) = 7;
      *(undefined1 *)(iVar1 + 0x38) = 0;
      *(char *)(iVar1 + 0x39) = (char)uVar2 + '\t';
      if (uVar2 == 0) {
        *(undefined1 *)(iVar1 + 0x26) = 7;
      }
      else {
        *(undefined1 *)(iVar1 + 0x26) = 5;
      }
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 2);
  return;
}


// ---- 801dc6f8 FUN_801dc6f8

void FUN_801dc6f8(int param_1,undefined1 param_2)

{
  if (*(char *)(param_1 + 7) == '\x01') {
    FUN_8010544c(param_1,param_2);
  }
  return;
}


// ---- 801dc728 FUN_801dc728

undefined1 *
FUN_801dc728(int param_1,undefined1 param_2,undefined1 param_3,short param_4,short param_5)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocType3();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = param_2;
    puVar1[7] = param_3;
    if ((*(byte *)(param_1 + 0x25) & 0x40) != 0) {
      param_4 = -param_4;
    }
    *(short *)(puVar1 + 0xe) = *(short *)(param_1 + 0xe) + param_4;
    *(short *)(puVar1 + 0x12) = param_5 + *(short *)(param_1 + 0x12);
    puVar1[0x25] = *(undefined1 *)(param_1 + 0x25);
  }
  return puVar1;
}


