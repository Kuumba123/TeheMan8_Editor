// ID 2F, STAGE05.BIN, handler 0x801DA5AC. Ghidra output with the object struct applied; not matching C.
// ---- 801da5ac FUN_801da5ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da5ac(MM8Obj *obj)

{
  char cVar1;
  char *pcVar2;
  
  obj->invuln = 0;
  (*(code *)(&PTR_FUN_801ea37c)[obj->state])();
  if (obj->active == 0) {
    return;
  }
  pcVar2 = *(char **)&obj->field_0x4c;
  if (obj->var != 3) {
    obj->clut = (&DAT_80159f64)[obj->bank];
    cVar1 = Enemy_CheckWeaponHits(obj);
    if (cVar1 == '\x02') {
      obj->clut = 0;
      if (DAT_80158f5c == '\x04') {
        if (obj->sub2 != 4) {
          obj->sub2 = 4;
          goto LAB_801da67c;
        }
      }
      else if ((DAT_80158f5c == '\x0e') && (obj->sub2 != 3)) {
        obj->sub2 = 3;
LAB_801da67c:
        obj->sub3 = 0;
        obj->field_0x4 = 0;
      }
    }
    else if (cVar1 == '\x04') {
      FUN_80108e84(obj);
      FUN_8012a5fc(obj,0);
      if ((obj->var & 2) == 0) {
        FUN_80108fd8(obj,1);
        goto LAB_801da750;
      }
      goto LAB_801da740;
    }
  }
  if ((((obj->var & 2) != 0) || (FUN_80107bf4(obj,&g_player,1), (obj->var & 2) != 0)) ||
     (obj->sub2 != 4)) {
    Enemy_ContactDamage(obj);
  }
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    if ((obj->var != 3) || (obj->field_0x52 == '\0')) {
      Obj_CullAndQueueDraw(obj);
    }
    obj->invuln = 1;
    return;
  }
  if ((obj->var & 2) == 0) {
LAB_801da750:
    if (((*pcVar2 != '\0') && (pcVar2[6] == '#')) && (*(MM8Obj **)(pcVar2 + 0x38) == obj)) {
      pcVar2[0x3c] = '\0';
    }
    Obj_FreeDespawn(obj);
    return;
  }
LAB_801da740:
  Obj_Free(obj);
  return;
}


// ---- 801da7e0 FUN_801da7e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da7e0(MM8Obj *obj)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  Enemy_InitFromTable();
  bVar1 = obj->var & 0xf;
  if (bVar1 == 2) {
    obj->contact_dmg = 4;
    obj->dmg_table = 0x1b;
    obj->draw_list = 8;
    obj->hp = 1;
    obj->state = 1;
    obj->sub2 = 0;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    obj->field_0x51 = 0xf;
    Anim_Set(obj,0xf);
    iVar4 = -0x20000;
    obj->hitbox = &DAT_801ea364;
    obj->box2 = &DAT_801ea371;
    if ((obj->flip & 0x40) != 0) {
      iVar4 = 0x20000;
    }
    obj->speed_x = iVar4;
    FUN_8010544c(obj,0x101);
  }
  else if (bVar1 < 3) {
    puVar2 = (undefined1 *)Obj_AllocType3();
    if (puVar2 != (undefined1 *)0x0) {
      obj->flip = 0;
      obj->draw_list = 9;
      if ((obj->var & 1) == 0) {
        bVar1 = 0x13;
      }
      else {
        bVar1 = 0x21;
      }
      obj->dmg_table = bVar1;
      obj->field_0x51 = 0;
      Anim_Set(obj,0);
      obj->hitbox = &DAT_801ea360;
      obj->box2 = &DAT_801ea36c;
      *(undefined1 **)&obj->field_0x4c = puVar2;
      *puVar2 = 1;
      puVar2[6] = 0x23;
      bVar1 = obj->var;
      puVar2[0x25] = 0;
      puVar2[1] = 0;
      puVar2[7] = bVar1;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)&obj->x_frac;
      uVar3 = *(undefined4 *)&obj->y_frac;
      *(MM8Obj **)(puVar2 + 0x38) = obj;
      puVar2[0x3c] = 1;
      *(undefined4 *)(puVar2 + 0x10) = uVar3;
      obj->state = 1;
      obj->sub2 = 0;
      if (obj->var == 0) {
        obj->field_0x50 = 0x40;
        obj->sub3 = 1;
      }
      else {
        obj->sub3 = 0;
      }
      obj->field_0x4 = 0;
    }
  }
  else if (bVar1 == 3) {
    bVar1 = obj->field_0x4;
    obj->dmg_table = 3;
                    /* Possible PsyQ macro: setSprt16() + setSemiTrans(sprt16, 1) +
                       setShadeTex(sprt16, 1) */
    obj->contact_dmg = 0x7f;
    obj->hp = 1;
    obj->state = 1;
    obj->sub2 = 0;
    obj->sub3 = 0;
    if (bVar1 == 1) {
      obj->draw_list = 6;
      Anim_Set(obj,6);
      obj->field_0x53 = 0;
      *(short *)&obj->field_0x56 = obj->y + -0x10;
    }
    else if (bVar1 < 2) {
      if (bVar1 == 0) {
        obj->draw_list = 7;
        Anim_Set(obj,5);
        obj->field_0x53 = 0;
      }
    }
    else if (bVar1 == 2) {
      obj->draw_list = 7;
      Anim_Set(obj,4);
    }
    obj->hitbox = &DAT_801ea368;
    obj->field_0x52 = 0;
    obj->box2 = &DAT_801ea376;
  }
  return;
}


// ---- 801daa5c FUN_801daa5c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daa5c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea388)[obj->var & 0xf])();
  return;
}


// ---- 801daa9c FUN_801daa9c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daa9c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea398)[obj->sub2])();
  return;
}


// ---- 801daad8 FUN_801daad8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daad8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = obj->sub3;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        if (((int)(short)obj->frame & 0x8000U) != 0) {
          obj->field_0x51 = 0xd;
          Anim_Set(obj,0xd);
          obj->sub3 = 3;
        }
      }
      else if ((bVar1 == 3) && (((int)(short)obj->frame & 0x8000U) != 0)) {
        obj->sub2 = 1;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
      }
      goto LAB_801dabc4;
    }
    if (bVar1 != 0) goto LAB_801dabc4;
    obj->field_0x50 = 0x80;
    obj->sub3 = 1;
  }
  cVar2 = obj->field_0x50;
  obj->field_0x50 = cVar2 + -1;
  if (cVar2 == '\0') {
    FUN_8010910c(obj);
    obj->field_0x51 = 0xc;
    Anim_Set(obj,0xc);
    obj->sub3 = 2;
  }
LAB_801dabc4:
  Anim_Step(obj);
  return;
}


// ---- 801dabe0 FUN_801dabe0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dabe0(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = obj->sub3;
  if (bVar1 == 1) {
    cVar2 = obj->field_0x50;
    obj->field_0x50 = cVar2 + -1;
    if (cVar2 == '\0') {
      obj->field_0x51 = 0xe;
      Anim_Set(obj,0xe);
      obj->sub3 = 2;
      obj->field_0x4 = obj->field_0x4 + '\x01';
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      obj->field_0x50 = 0x1e;
      obj->sub3 = 1;
    }
  }
  else if ((bVar1 == 2) && (((int)(short)obj->frame & 0x8000U) != 0)) {
    FUN_801dbca8(obj);
    if (obj->field_0x4 == '\0') {
      obj->sub3 = 0;
    }
    else {
      obj->sub2 = 2;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801dacd8 FUN_801dacd8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dacd8(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = obj->sub3;
  if (bVar1 == 1) {
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->field_0x51 = 0x12;
      Anim_Set(obj,0x12);
      obj->sub3 = 2;
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
                    /* Possible PsyQ macro: setTile8() */
      obj->field_0x51 = 0x13;
      Anim_Set(obj,0x13);
      obj->sub3 = 1;
    }
  }
  else {
                    /* Possible PsyQ macro: setPolyGT4() */
    if ((bVar1 == 2) && (((int)(short)obj->frame & 0x8000U) != 0)) {
      obj->field_0x51 = 0;
      Anim_Set(obj,0);
      obj->flip = 0;
      obj->sub2 = 0;
      obj->sub3 = 0;
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801dadb8 FUN_801dadb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dadb8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  
  if (obj->field_0x4 != '\0') {
    cVar2 = obj->field_0x50;
    obj->field_0x50 = cVar2 + -1;
    if (cVar2 == '\0') {
      pcVar3 = *(char **)&obj->field_0x4c;
      if (((*pcVar3 != '\0') && (pcVar3[6] == '#')) && (*(MM8Obj **)(pcVar3 + 0x38) == obj)) {
        pcVar3[0x3c] = '\x01';
      }
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
    goto LAB_801daf64;
  }
  bVar1 = obj->sub3;
  if (bVar1 == 1) {
    if (((int)(short)obj->frame & 0x8000U) == 0) goto LAB_801daf64;
    Anim_Set(obj,0x12);
  }
  else {
    if (1 < bVar1) {
      if ((bVar1 == 2) && (((int)(short)obj->frame & 0x8000U) != 0)) {
        obj->flip = 0;
        obj->field_0x51 = 0;
        Anim_Set(obj,0);
        pcVar3 = *(char **)&obj->field_0x4c;
        obj->field_0x50 = 0xf0;
        obj->field_0x4 = 1;
        if ((*pcVar3 != '\0') && ((pcVar3[6] == '#' && (*(MM8Obj **)(pcVar3 + 0x38) == obj)))) {
          pcVar3[0x3c] = '\x02';
        }
      }
      goto LAB_801daf64;
    }
    if (bVar1 != 0) goto LAB_801daf64;
    bVar1 = obj->field_0x51;
    if (bVar1 == 0xc) {
      Anim_SetAtStep(obj,0x12,obj->anim_extra & 0xf);
    }
    else if ((0xb < bVar1) && (bVar1 < 0xf)) {
      Anim_SetAtStep(obj,0x13,obj->anim_extra & 0xf);
      obj->sub3 = 1;
      goto LAB_801daf64;
    }
  }
  obj->sub3 = 2;
LAB_801daf64:
  Anim_Step(obj);
  return;
}


// ---- 801daf80 FUN_801daf80

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daf80(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  
  switch(obj->sub3) {
  case 0:
    obj->field_0x50 = 0x1e;
    obj->dmg_table = 3;
    obj->field_0x52 = obj->anim_extra & 0xf;
    *(word *)&obj->field_0x54 = obj->frame;
    Anim_Set(obj,0x10);
    FUN_8010544c(obj,0x2d);
    pcVar3 = *(char **)&obj->field_0x4c;
    if (((*pcVar3 != '\0') && (pcVar3[6] == '#')) && (*(MM8Obj **)(pcVar3 + 0x38) == obj)) {
      pcVar3[0x3c] = '\x02';
    }
    obj->sub3 = 1;
    break;
  case 1:
    cVar1 = obj->field_0x50;
    bVar2 = cVar1 - 1;
    obj->field_0x50 = bVar2;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0x78;
      Anim_Set(obj,0x10);
      obj->sub3 = 2;
    }
    else if ((bVar2 & 1) == 0) {
      Anim_Set(obj,0x10);
    }
    else {
      Anim_Set(obj,obj->field_0x51);
      if (obj->frame != *(word *)&obj->field_0x54) {
        do {
          Anim_StepN(obj,1);
        } while (obj->frame != *(word *)&obj->field_0x54);
      }
    }
    break;
  case 2:
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      FUN_8012ae08(obj,0x1c);
      FUN_8010544c(obj,0x2c);
      obj->sub3 = 3;
      if ((obj->var & 1) == 0) {
        obj->dmg_table = 0x13;
      }
      else {
        obj->dmg_table = 0x21;
      }
    }
    break;
  case 3:
    bVar2 = obj->field_0x51;
    if (bVar2 == 0xc) {
      obj->field_0x51 = 0x12;
      Anim_SetAtStep(obj,0x12,obj->field_0x52);
    }
    else if ((0xb < bVar2) && (bVar2 < 0xf)) {
      obj->field_0x51 = 0x13;
      Anim_SetAtStep(obj,0x13,obj->field_0x52);
      obj->sub3 = 4;
      return;
    }
    obj->sub3 = 5;
    break;
  case 4:
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->field_0x51 = 0x12;
      Anim_Set(obj,0x12);
      obj->sub3 = 5;
    }
    goto LAB_801db234;
  case 5:
    if (((int)(short)obj->frame & 0x8000U) != 0) {
      obj->flip = 0;
      obj->field_0x51 = 0;
      Anim_Set(obj,0);
      pcVar3 = *(char **)&obj->field_0x4c;
      if (((*pcVar3 != '\0') && (pcVar3[6] == '#')) && (*(MM8Obj **)(pcVar3 + 0x38) == obj)) {
        pcVar3[0x3c] = '\x01';
      }
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
    }
LAB_801db234:
    Anim_Step(obj);
  }
  return;
}


// ---- 801db250 FUN_801db250

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db250(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea3ac)[obj->sub2])();
  return;
}


// ---- 801db28c FUN_801db28c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db28c(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  word wVar8;
  short sVar9;
  MM8Obj *pMVar10;
  int iVar11;
  byte *pbVar12;
  char *pcVar13;
  MM8Obj *pMVar14;
  MM8Obj *pMVar15;
  
  if (((int)(uint)DAT_801b29a0 >> (uint)(obj->var >> 4) & 1U) == 0) {
    Anim_Step(obj);
  }
  else {
    pMVar10 = (MM8Obj *)Obj_AllocMain();
    pMVar14 = obj;
    if ((pMVar10 != (MM8Obj *)0x0) && (pMVar10 < obj)) {
      pMVar15 = pMVar10;
      do {
        bVar1 = pMVar14->state;
        bVar2 = pMVar14->sub2;
        bVar3 = pMVar14->sub3;
        uVar4 = pMVar14->field_0x4;
        bVar5 = pMVar14->on_screen;
        bVar6 = pMVar14->id;
        bVar7 = pMVar14->var;
        pbVar12 = pMVar14->spawn_record;
        wVar8 = pMVar14->x_frac;
        sVar9 = pMVar14->x;
        pMVar15->active = pMVar14->active;
        pMVar15->state = bVar1;
        pMVar15->sub2 = bVar2;
        pMVar15->sub3 = bVar3;
        pMVar15->field_0x4 = uVar4;
        pMVar15->on_screen = bVar5;
        pMVar15->id = bVar6;
        pMVar15->var = bVar7;
        pMVar15->spawn_record = pbVar12;
        pMVar15->x_frac = wVar8;
        pMVar15->x = sVar9;
        pMVar14 = (MM8Obj *)&pMVar14->y_frac;
        pMVar15 = (MM8Obj *)&pMVar15->y_frac;
      } while (pMVar14 != obj + 1);
      pcVar13 = *(char **)&pMVar10->field_0x4c;
      pMVar14 = pMVar10;
      if (((*pcVar13 != '\0') && (pcVar13[6] == '#')) && (*(MM8Obj **)(pcVar13 + 0x38) == obj)) {
        *(MM8Obj **)(pcVar13 + 0x38) = pMVar10;
      }
    }
    iVar11 = FUN_801dbd14(pMVar14);
    if (iVar11 != 0) {
      pcVar13 = *(char **)&pMVar14->field_0x4c;
      *(int *)&pMVar14->field_0x58 = iVar11;
      pMVar14->sub2 = 1;
      pMVar14->sub3 = 0;
      if (((*pcVar13 != '\0') && (pcVar13[6] == '#')) && (*(MM8Obj **)(pcVar13 + 0x38) == pMVar14))
      {
        pcVar13[0x3c] = '\x02';
      }
    }
    if (obj != pMVar14) {
      Obj_Free(obj);
      Obj_CullAndQueueDraw(pMVar14);
      pMVar14->invuln = 1;
    }
  }
  return;
}


// ---- 801db4a8 FUN_801db4a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db4a8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea3c0)[obj->sub2])();
  return;
}


// ---- 801db4e4 FUN_801db4e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db4e4(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setPolyG3() + setSemiTrans(polyG3, 1) */
  FUN_80104d00();
  FUN_80106214(obj);
  Anim_Step(obj);
  if ((obj->field_0x33 & 0x30) != 0) {
    FUN_80108e84(obj);
    Obj_Free(obj);
  }
  return;
}


// ---- 801db558 FUN_801db558

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db558(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea3cc)[obj->sub2])();
  return;
}


// ---- 801db594 FUN_801db594

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db594(MM8Obj *obj)

{
  char *pcVar1;
  
  if (obj->field_0x4 == '\x01') {
    pcVar1 = *(char **)&obj->field_0x4c;
    if (((*pcVar1 == '\0') || ((*(uint *)(pcVar1 + 4) & 0x1ff0000) != 0x12f0000)) ||
       (*(short *)(pcVar1 + 0xe) != obj->x)) {
LAB_801db64c:
      Obj_Free();
      return;
    }
    if (pcVar1[2] != '\x04') {
LAB_801db678:
      (*(code *)(&PTR_FUN_801ea3d8)[(byte)obj->field_0x4])();
      return;
    }
  }
  else {
    pcVar1 = *(char **)&obj->field_0x4c;
    if (((*pcVar1 == '\0') || ((*(uint *)(pcVar1 + 4) & 0xffff0000) != 0x32f0000)) ||
       (*(short *)(pcVar1 + 0xe) != obj->x)) goto LAB_801db64c;
    if (pcVar1[2] != '\x01') goto LAB_801db678;
  }
  obj->sub2 = 1;
  obj->sub3 = 0;
  return;
}


// ---- 801db6ac FUN_801db6ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db6ac(MM8Obj *obj)

{
  char *pcVar1;
  
  pcVar1 = *(char **)&obj->field_0x4c;
  if (obj->sub3 == 0) {
    Anim_Set(obj,5);
    obj->sub3 = 1;
  }
  if (((*pcVar1 == '\0') || ((*(uint *)(pcVar1 + 4) & 0xffff0000) != 0x32f0000)) ||
     (obj->x != *(short *)(pcVar1 + 0xe))) {
    Obj_Free(obj);
  }
  else {
    Anim_SetAtStep(obj,5,pcVar1[0x32]);
  }
  return;
}


// ---- 801db750 FUN_801db750

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db750(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  bVar1 = obj->sub3;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        cVar2 = obj->field_0x50;
        obj->field_0x50 = cVar2 + -1;
        if (cVar2 == '\0') {
          obj->sub3 = 3;
          obj->speed_y_up = -0x20000;
        }
      }
      else if (bVar1 == 3) {
        FUN_80104c34(obj);
        obj->field_0x54 = obj->field_0x54 + ((char)obj->y - (char)obj->prev_y);
        if (0xf < (byte)obj->field_0x54) {
          obj->field_0x54 = 0;
          if ((char)obj->field_0x53 < '\x01') {
            obj->field_0x53 = 0;
            Obj_Free(obj);
            return;
          }
          *(short *)&obj->field_0x56 = obj->y;
          obj->field_0x53 = obj->field_0x53 + -1;
        }
      }
      goto LAB_801db930;
    }
    if (bVar1 != 0) goto LAB_801db930;
    Anim_Set(obj,6);
    obj->sub3 = 1;
    obj->speed_y_up = 0x20000;
  }
  FUN_80104c34(obj);
  obj->field_0x54 = obj->field_0x54 + ((char)obj->prev_y - (char)obj->y);
  if (0xf < (byte)obj->field_0x54) {
    obj->field_0x54 = 0;
    if ((byte)obj->field_0x53 < 8) {
      obj->field_0x53 = obj->field_0x53 + '\x01';
      puVar3 = (undefined1 *)FUN_801055e4(obj);
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        puVar3[6] = 0x2f;
        puVar3[7] = 3;
        puVar3[0x25] = 0;
        *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)&obj->x_frac;
        uVar4 = *(undefined4 *)&obj->y_frac;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[4] = 2;
        *(MM8Obj **)(puVar3 + 0x4c) = obj;
        *(undefined4 *)(puVar3 + 0x10) = uVar4;
        puVar3[0x53] = obj->field_0x53;
        *(short *)&obj->field_0x56 = obj->y + -0x10;
      }
    }
    else {
      obj->field_0x50 = 0x1e;
      obj->sub3 = 2;
    }
  }
LAB_801db930:
  Anim_Step(obj);
  return;
}


// ---- 801db94c FUN_801db94c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db94c(MM8Obj *obj)

{
  char *pcVar1;
  
  pcVar1 = *(char **)&obj->field_0x4c;
  if (obj->sub3 == 0) {
    Anim_Set(obj,4);
    obj->sub3 = 1;
  }
                    /* Probable PsyQ macro: setTile16() */
                    /* Possible PsyQ macro: setTile8() */
                    /* Possible PsyQ macro: setTile8() */
  if ((((*pcVar1 == '\0') || ((*(uint *)(pcVar1 + 4) & 0xffff0000) != 0x32f0000)) ||
      (obj->x != *(short *)(pcVar1 + 0xe))) ||
     (((pcVar1[4] != '\x01' || (pcVar1[3] != '\x03')) || (*(short *)(pcVar1 + 0x12) < obj->y)))) {
    Anim_SetAtStep(obj,4,pcVar1[0x32]);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801dba2c FUN_801dba2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba2c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  char *pcVar5;
  
                    /* Probable PsyQ macro: setTile16() */
  switch(obj->sub3) {
  case 0:
    bVar2 = obj->field_0x4;
    obj->draw_list = 9;
    if (bVar2 == 1) {
      uVar4 = 9;
      obj->y = *(short *)&obj->field_0x56 + 8;
      if ((obj->field_0x53 & 1) == 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
        uVar4 = 10;
      }
                    /* Possible PsyQ macro: setPolyGT4() */
      Anim_Set(obj,uVar4);
      obj->field_0x51 = obj->field_0x53;
    }
    else if (bVar2 < 2) {
      if (bVar2 == 0) {
        pcVar5 = *(char **)&obj->field_0x4c;
        if (((*pcVar5 != '\0') && ((*(uint *)(pcVar5 + 4) & 0xffff0000) == 0x32f0000)) &&
           (obj->x == *(short *)(pcVar5 + 0xe))) {
          cVar1 = pcVar5[0x53];
          cVar3 = '\x14';
          goto LAB_801dbb8c;
        }
LAB_801dbba0:
        obj->sub3 = 4;
      }
    }
    else if (bVar2 == 2) {
      pcVar5 = *(char **)&obj->field_0x4c;
                    /* Possible PsyQ macro: setPolyGT3() */
      if (((*pcVar5 == '\0') || ((*(uint *)(pcVar5 + 4) & 0xffff0000) != 0x32f0000)) ||
         (obj->x != *(short *)(pcVar5 + 0xe))) goto LAB_801dbba0;
      cVar1 = pcVar5[0x53];
      cVar3 = (obj->field_0x53 & 1) + 7;
LAB_801dbb8c:
      obj->field_0x51 = cVar1;
      Anim_Set(obj,cVar3);
                    /* Possible PsyQ macro: setPolyGT3() */
    }
    obj->sub3 = 1;
    obj->hp = 0;
    obj->field_0x50 = 0x1e;
    break;
  case 1:
    cVar1 = obj->field_0x50;
    bVar2 = cVar1 - 1;
    obj->field_0x50 = bVar2;
    if (cVar1 == '\0') {
      obj->sub3 = 2;
      obj->field_0x52 = 0;
      obj->field_0x50 = obj->field_0x53 * -4 + '2';
    }
    else {
                    /* Possible PsyQ macro: setPolyGT3() */
      obj->field_0x52 = bVar2 & 1;
    }
    break;
  case 2:
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      if ((obj->field_0x53 & 1) == (obj->field_0x51 & 1)) {
        obj->draw_list = 7;
        obj->y = obj->y + 8;
        Anim_Set(obj,0xb);
        obj->sub3 = 3;
      }
      else {
        obj->sub3 = 4;
      }
    }
    break;
  case 3:
    if (((int)(short)obj->frame & 0x8000U) == 0) {
      Anim_Step(obj);
      return;
    }
  case 4:
    Obj_Free(obj);
  }
  return;
}


// ---- 801dbca8 FUN_801dbca8

void FUN_801dbca8(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x2f;
    puVar1[7] = 2;
    puVar1[0x25] = *(undefined1 *)(param_1 + 0x25);
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    puVar1[1] = 0;
    *(undefined4 *)(puVar1 + 0x10) = uVar2;
  }
  return;
}


// ---- 801dbd14 FUN_801dbd14

undefined1 * FUN_801dbd14(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined1 *)FUN_801055e4();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0x2f;
    puVar1[7] = 3;
    puVar1[0x25] = 0;
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    puVar1[0x54] = 0;
    puVar1[0x53] = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 1;
    *(int *)(puVar1 + 0x4c) = param_1;
    *(short *)(puVar1 + 0x12) = *(short *)(puVar1 + 0x12) + -0x28;
    puVar2 = (undefined1 *)FUN_801055e4(puVar1);
    if (puVar2 == (undefined1 *)0x0) {
      Obj_Free(puVar1);
      puVar1 = (undefined1 *)0x0;
    }
    else {
      *puVar2 = 1;
      puVar2[6] = 0x2f;
      puVar2[7] = 3;
      puVar2[0x25] = 0;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      *(undefined1 **)(puVar2 + 0x4c) = puVar1;
      *(short *)(puVar2 + 0x12) = *(short *)(puVar2 + 0x12) + -0x28;
      *(undefined1 **)(puVar1 + 0x58) = puVar2;
      FUN_8010544c(param_1,0xd1);
    }
  }
  return puVar1;
}


