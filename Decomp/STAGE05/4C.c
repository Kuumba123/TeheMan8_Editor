// ID 4C, STAGE05.BIN, handler 0x801E0C6C. Ghidra output with the object struct applied; not matching C.
// ---- 801e0c6c FUN_801e0c6c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0c6c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea6f8)[obj->state])();
  return;
}


// ---- 801e0ca8 FUN_801e0ca8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0ca8(MM8Obj *obj)

{
  short sVar1;
  
  if ((obj->var & 0x80) != 0) {
    FUN_80103794(0x2a,0x4a,4);
  }
  Enemy_InitFromTable(obj);
  obj->field_0x49 = 9;
  *(undefined1 **)&obj->field_0x4c = &DAT_80060000;
  obj->x = DAT_801d2928 + 0xe0;
  sVar1 = DAT_801d292a;
  obj->hitbox = &DAT_801ea680;
  obj->flip = 0;
  obj->draw_list = 7;
  obj->box2 = &DAT_801ea6ac;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  obj->field_0x58 = 0;
  obj->field_0x5e = 0;
  obj->field_0x59 = 7;
  obj->y = sVar1 + 0x97;
  Anim_Set(obj,0);
  FUN_80103224(obj);
  FUN_801e296c(obj,0,0,0x80);
  obj->state = 1;
  return;
}


// ---- 801e0d90 FUN_801e0d90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0d90(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801ea708)[obj->sub2])();
  return;
}


// ---- 801e11c4 FUN_801e11c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e11c4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_801ea71c)[obj->sub2])();
  obj->clut = DAT_80159ff8;
  if (obj->field_0x58 == '\0') {
    iVar2 = FUN_801e279c(obj);
    if (iVar2 == 2) {
      obj->field_0x58 = 0x3c;
      if (DAT_80158f5c == '\x0e') {
        FUN_8010544c(obj,0x176);
        if (obj->sub2 == 3) {
          obj->sub2 = 5;
          obj->sub3 = 0;
          obj->field_0x4 = 0;
        }
      }
      else {
        FUN_8010544c(obj,0x175);
      }
      FUN_8010544c(obj,0x10);
    }
    else if (iVar2 == 4) {
      obj->state = 3;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      DAT_8015e2af = 1;
      return;
    }
  }
  else {
    bVar1 = obj->hp;
                    /* Possible PsyQ macro: setPolyF4() */
    obj->hp = 0x28;
    iVar2 = FUN_801e279c(obj);
    if (iVar2 == 2) {
      FUN_8010544c(obj,0x4f);
    }
    obj->hp = bVar1;
    if ((obj->field_0x58 & 1) != 0) {
      obj->clut = 0;
    }
    obj->field_0x58 = obj->field_0x58 + -1;
  }
  FUN_801e28a8(obj);
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e133c FUN_801e133c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e133c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  
  if (obj->sub3 == 0) {
    obj->field_0x50 = 0x1e;
    obj->field_0x53 = 0;
    obj->box2 = &DAT_801ea6ac;
    Anim_Set(obj,0);
    obj->sub3 = 1;
  }
  FUN_80106214(obj);
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 != '\0') {
    return;
  }
  uVar3 = Rand();
  bVar5 = (&DAT_801ea6e8)[uVar3 & 0xf];
  if ((obj->field_0x5a == bVar5) &&
     (bVar2 = obj->field_0x5c + 1, obj->field_0x5c = bVar2, 1 < bVar2)) {
    iVar4 = 0;
    do {
      uVar3 = Rand();
      bVar5 = (&DAT_801ea6e8)[uVar3 & 0xf];
      iVar4 = iVar4 + 1;
      if (obj->field_0x5a != bVar5) {
        obj->field_0x5c = 0;
        break;
      }
    } while (iVar4 * 0x10000 >> 0x10 < 0x100);
  }
  FUN_8010910c(obj);
  if (bVar5 == 1) {
    if ((obj->flip & 0x40) == 0) {
      if (DAT_801d2928 + 0x44 < (int)obj->x) {
        obj->sub2 = 1;
        goto LAB_801e14b0;
      }
    }
    else if ((int)obj->x < DAT_801d2928 + 0xfc) goto LAB_801e14ac;
    bVar5 = 2;
  }
LAB_801e14ac:
  obj->sub2 = bVar5;
LAB_801e14b0:
  obj->field_0x5a = bVar5;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801e253c FUN_801e253c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e253c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801ea778)[obj->sub2])();
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801e2578 FUN_801e2578

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e2578(MM8Obj *obj)

{
  FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  FUN_800fcd84();
  obj->field_0x5b = 1;
  obj->field_0x51 = 5;
  Anim_Set(obj,0xf);
  obj->sub2 = 1;
  obj->sub3 = 0;
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e260c FUN_801e260c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e260c(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  Anim_Step();
  if (obj->sub3 == 0) {
                    /* Possible PsyQ macro: setPolyGT4() */
    obj->field_0x50 = 0x3c;
    obj->sub3 = 1;
  }
  if ((obj->field_0x50 & 1) == 0) {
    obj->clut = DAT_80159ff8;
  }
  else {
    obj->clut = 0;
  }
  cVar2 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar2;
  if (cVar2 == '\0') {
                    /* Possible PsyQ macro: setTile8() */
    obj->field_0x50 = 0x78;
    bVar1 = DAT_80159ff8;
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->clut = bVar1;
  }
  FUN_80103184(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e26c4 FUN_801e26c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e26c4(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if ((obj->field_0x50 & 7) == 0) {
    uVar2 = Rand();
    uVar3 = Rand();
    FUN_80108ed8(obj,(int)(((uVar2 & 0x3f) - 0x1f) * 0x10000) >> 0x10,
                 (int)(((uVar3 & 0x1f) - 0xf) * 0x10000) >> 0x10);
  }
  obj->on_screen = 0;
  if ((obj->field_0x50 & 1) != 0) {
    FUN_80103184(obj);
    Obj_CullAndQueueDraw(obj);
  }
  cVar1 = obj->field_0x50 + -1;
  obj->field_0x50 = cVar1;
  if (cVar1 == '\0') {
    FUN_8010544c(obj,0x177);
    obj->sub2 = 3;
    obj->sub3 = 0;
    obj->on_screen = 0;
    obj->field_0x50 = 1;
  }
  return;
}


// ---- 801e279c FUN_801e279c

int FUN_801e279c(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  
  pbVar4 = &DAT_801ea6b8 + (uint)*(byte *)(param_1 + 0x53) * 4;
  uVar1 = *(undefined1 *)(param_1 + 0x44);
  uVar5 = 0;
  if (*(char *)(param_1 + 0x52) != '\0') {
    *(undefined1 *)(param_1 + 0x44) = 1;
  }
  do {
    bVar2 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    if ((bVar2 & 0x80) == 0) {
      *(undefined **)(param_1 + 0x3c) = &DAT_801ea680 + (bVar2 & 0x3f) * 4;
      iVar3 = Enemy_CheckWeaponHits(param_1);
      if (iVar3 != 0) goto LAB_801e2878;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 2);
  iVar3 = 0;
  if ((*pbVar4 & 0x80) == 0) {
    *(undefined1 *)(param_1 + 0x44) = 1;
    *(undefined **)(param_1 + 0x3c) = &DAT_801ea680 + (*pbVar4 & 0x3f) * 4;
    Enemy_CheckWeaponHits(param_1);
    iVar3 = 0;
LAB_801e2878:
    *(undefined1 *)(param_1 + 0x44) = uVar1;
  }
  else {
    *(undefined1 *)(param_1 + 0x44) = uVar1;
  }
  return iVar3;
}


// ---- 801e28a8 FUN_801e28a8

int FUN_801e28a8(int param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = 0;
  pbVar3 = &DAT_801ea6b8 + (uint)*(byte *)(param_1 + 0x53) * 4;
  do {
    if ((*pbVar3 & 0x40) == 0) {
      *(undefined **)(param_1 + 0x3c) = &DAT_801ea680 + (*pbVar3 & 0x3f) * 4;
      if (uVar2 == 1) {
        *(undefined1 *)(param_1 + 0x45) = *(undefined1 *)(param_1 + 0x59);
      }
      else {
        *(undefined1 *)(param_1 + 0x45) = 7;
      }
      iVar1 = Enemy_ContactDamage(param_1);
      if (iVar1 != 0) {
        *(undefined1 *)(param_1 + 0x5e) = 1;
        return iVar1;
      }
    }
    uVar2 = uVar2 + 1;
    pbVar3 = pbVar3 + 1;
    if (2 < uVar2) {
      return 0;
    }
  } while( true );
}


// ---- 801e296c FUN_801e296c

undefined1 * FUN_801e296c(int param_1,char param_2,char param_3,byte param_4)

{
  undefined1 uVar1;
  short sVar2;
  undefined1 *puVar3;
  
  if ((param_4 & 0x80) == 0) {
    puVar3 = (undefined1 *)Obj_AllocMain();
  }
  else {
    puVar3 = (undefined1 *)FUN_801055e4();
  }
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 1;
    puVar3[6] = 0x4d;
    puVar3[7] = param_4 & 0x7f;
    if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
      sVar2 = (short)param_2;
    }
    else {
      sVar2 = -(short)param_2;
    }
    *(short *)(puVar3 + 0xe) = *(short *)(param_1 + 0xe) + sVar2;
    *(short *)(puVar3 + 0x12) = (short)param_3 + *(short *)(param_1 + 0x12);
    uVar1 = *(undefined1 *)(param_1 + 0x25);
    *(int *)(puVar3 + 0x4c) = param_1;
    puVar3[0x25] = uVar1;
  }
  return puVar3;
}


