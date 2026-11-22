// ID 09, STAGE04.BIN, handler 0x801D9A00. Ghidra output with the object struct applied; not matching C.
// ---- 801d9a00 FUN_801d9a00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9a00(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6d34)[obj->state])();
  return;
}


// ---- 801d9a3c FUN_801d9a3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9a3c(MM8Obj *obj)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  
  obj->bank = 0x17;
  obj->vram_base = DAT_80170376;
  bVar2 = DAT_80159f7b;
  iVar3 = (uint)obj->var * 8;
  obj->dmg_table = 2;
  obj->invuln = 0;
  obj->field_0x57 = bVar2;
  obj->clut = bVar2;
  obj->draw_list = (&DAT_801e6d06)[iVar3];
  obj->hp = (&DAT_801e6d04)[iVar3];
  obj->contact_dmg = (&DAT_801e6d05)[iVar3];
  obj->hitbox = (&PTR_DAT_801e6d08)[(uint)obj->var * 2];
  uVar1 = (&DAT_801e6d07)[iVar3];
  obj->speed_y_up = 0;
  obj->field_0x50 = uVar1;
  if (obj->var < 2) {
    FUN_8010910c(obj);
    iVar3 = -0x1d000;
    if (obj->flip != 0) {
      iVar3 = 0x1d000;
    }
    obj->speed_x = iVar3;
    obj->field_0x53 = 3;
    obj->field_0x52 = 0;
    obj->field_0x54 = 0;
    *(undefined4 *)&obj->field_0x5c = 0;
    *(undefined4 *)&obj->field_0x58 = 0;
  }
  bVar2 = obj->var;
  if (bVar2 == 2) {
    FUN_8010910c(obj);
    obj->speed_x = -1;
    obj->field_0x51 = 10;
    *(short *)&obj->field_0x58 = obj->x - DAT_801d2918._2_2_;
    *(short *)&obj->field_0x5c = obj->y - g_cam_y;
    bVar2 = obj->var;
  }
  if (bVar2 == 4) {
    obj->invuln = 1;
    obj->speed_x = 0;
    obj->gravity = 0x3000;
    obj->box2 = obj->hitbox;
  }
  Anim_Set(obj,(&DAT_801e6d40)[obj->var]);
  if (obj->var == 5) {
    obj->speed_y_up = -0x10000;
    obj->speed_x = 0;
    obj->var = 3;
  }
  obj->state = 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  return;
}


// ---- 801d9bf8 FUN_801d9bf8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9bf8(MM8Obj *obj)

{
  char cVar1;
  
  obj->clut = obj->field_0x57;
                    /* Possible PsyQ macro: setPolyF4() */
  (*(code *)(&PTR_FUN_801e6d48)[obj->var])();
  if (obj->var != 4) {
    cVar1 = Enemy_CheckWeaponHits(obj);
    if (cVar1 != '\0') {
      obj->clut = 0;
    }
    if (cVar1 == '\x04') {
      FUN_80108e84(obj);
      FUN_8012a5fc(obj,(uint)(obj->var != 3) << 3);
      FUN_80108fd8(obj,obj->var != 3);
      goto LAB_801d9cbc;
    }
    Enemy_ContactDamage(obj);
  }
  cVar1 = Obj_InActiveArea(obj);
  if (cVar1 != '\0') {
    Obj_CullAndQueueDraw(obj);
    return;
  }
LAB_801d9cbc:
  obj->state = 2;
  return;
}


// ---- 801d9ce4 FUN_801d9ce4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ce4(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6d5c)[obj->sub2])();
  if (obj->sub2 != 3) {
    FUN_80104c34(obj);
    Anim_Step(obj);
  }
  return;
}


// ---- 801d9d4c FUN_801d9d4c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9d4c(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = obj->field_0x50;
  obj->field_0x50 = cVar1 + -1;
  if (cVar1 != '\0') goto LAB_801d9de8;
  bVar2 = obj->field_0x54;
  if (bVar2 == 1) {
    obj->field_0x51 = 8;
    bVar2 = 1;
    obj->speed_y_up = 0;
    obj->field_0x50 = 0;
  }
  else {
    if (bVar2 < 2) {
      if (bVar2 == 0) {
        obj->speed_y_up = -0x10000;
        obj->field_0x50 = 0x20;
        obj->field_0x54 = 1;
      }
      goto LAB_801d9de8;
    }
    if (bVar2 != 2) goto LAB_801d9de8;
    obj->field_0x50 = 0x40;
    bVar2 = 2;
    obj->speed_x = 0;
    obj->speed_y_up = 0;
  }
  obj->sub2 = bVar2;
LAB_801d9de8:
  FUN_801da3c0();
  return;
}


// ---- 801d9e00 FUN_801d9e00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9e00(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  undefined1 *puVar4;
  
  cVar1 = obj->field_0x50;
  obj->field_0x50 = cVar1 + -1;
  if (cVar1 == '\0') {
    puVar4 = (undefined1 *)FUN_801055e4();
    if (puVar4 != (undefined1 *)0x0) {
      *puVar4 = 1;
      puVar4[6] = 9;
      puVar4[7] = 4;
      sVar3 = 10;
      if (obj->flip == 0) {
        sVar3 = -10;
      }
      *(short *)(puVar4 + 0xe) = obj->x + sVar3;
      *(short *)(puVar4 + 0x12) = obj->y + 0x18;
      bVar2 = obj->var;
      puVar4[1] = 0;
      puVar4[0x51] = bVar2;
      FUN_800fd100(0x13f);
    }
    obj->field_0x50 = 0xc;
    obj->field_0x51 = obj->field_0x51 + -1;
  }
  if (obj->field_0x51 == '\0') {
    obj->speed_y_up = 0x10000;
    obj->field_0x50 = 0x20;
    obj->field_0x54 = 2;
    obj->sub2 = 0;
  }
  FUN_801da3c0(obj);
  return;
}


// ---- 801d9ee0 FUN_801d9ee0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ee0(MM8Obj *obj)

{
  uint uVar1;
  int iVar2;
  
  if (obj->field_0x50 == '\0') {
    if (obj->frame == 0) {
      if ((obj->field_0x53 == '\0') || (uVar1 = Rand(), (uVar1 & 0x8000) != 0)) {
        obj->field_0x50 = 0xff;
      }
      else {
                    /* Possible PsyQ macro: setPolyF4() */
        obj->field_0x50 = 0x28;
        obj->flip = obj->flip ^ 0x40;
        obj->field_0x53 = obj->field_0x53 + -1;
      }
      iVar2 = -0x1d000;
      if (obj->flip != 0) {
        iVar2 = 0x1d000;
      }
      obj->speed_x = iVar2;
      obj->field_0x54 = 0;
      obj->sub2 = 0;
    }
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  FUN_801da3c0(obj);
  return;
}


// ---- 801d9fdc FUN_801d9fdc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9fdc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6d6c)[obj->sub2])();
  Anim_Step(obj);
  return;
}


// ---- 801da02c FUN_801da02c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da02c(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = obj->speed_x;
  if (DAT_801d2915 == '\x01') {
    iVar5 = iVar5 - DAT_801d293a;
  }
  iVar3 = (uint)*(ushort *)&obj->field_0x58 + iVar5;
  *(short *)&obj->field_0x58 = (short)iVar3;
  iVar3 = iVar3 + (uint)DAT_801d2918._2_2_;
  obj->x = (short)iVar3;
  iVar3 = (iVar3 * 0x10000 >> 0x10) - (int)DAT_8015e248._2_2_;
  if (obj->sub3 == 0) {
    if ((obj->field_0x51 != '\0') && (iVar3 < 0x50)) {
      uVar4 = Rand();
      iVar5 = -iVar5;
      if (iVar5 == 0) {
        trap(0x1c00);
      }
      if ((iVar5 == -1) && ((uVar4 & 0x7f) == 0x80000000)) {
        trap(0x1800);
      }
      obj->sub3 = 1;
      obj->field_0x52 = (char)((int)(uVar4 & 0x7f) / iVar5);
    }
  }
  else {
    cVar1 = obj->field_0x52;
    obj->field_0x52 = cVar1 + -1;
    if ((cVar1 == '\0') || ((iVar3 < 0 && (sVar2 = Rand(), sVar2 < 0x4000)))) {
      obj->field_0x50 = 0x14;
      obj->sub2 = 1;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801da24c FUN_801da24c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da24c(MM8Obj *obj)

{
  char cVar1;
  undefined1 uVar2;
  
  if (obj->sub2 == 0) {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      obj->field_0x50 = 0;
      obj->sub2 = 1;
    }
  }
  else {
    cVar1 = obj->field_0x50;
    obj->field_0x50 = cVar1 + -1;
    if (cVar1 == '\0') {
      uVar2 = FUN_801050e4(obj,&g_player);
      FUN_80105120(obj,0x80,uVar2);
      obj->field_0x50 = 4;
    }
  }
  FUN_80104c34(obj);
  Anim_Step(obj);
  return;
}


// ---- 801da2f0 FUN_801da2f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da2f0(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80104ccc();
  if (obj->field_0x51 == '\x02') {
    obj->x = DAT_801d2918._2_2_ + *(short *)&obj->field_0x58;
  }
  FUN_80106214(obj);
  if (((obj->field_0x33 & 0x80) != 0) || (iVar1 = Enemy_ContactDamage(obj), iVar1 != 0)) {
    FUN_80108e84(obj);
    obj->state = 2;
  }
  return;
}


// ---- 801da37c FUN_801da37c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da37c(MM8Obj *obj)

{
  if (obj->var < 2) {
    Obj_FreeDespawn();
  }
  else {
    Obj_Free();
  }
  return;
}


// ---- 801da3c0 FUN_801da3c0

void FUN_801da3c0(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  
  if (*(char *)(param_1 + 7) != '\0') {
    puVar8 = (undefined4 *)(param_1 + 0x58);
    if ((*(char *)(param_1 + 0x52) == '\0') && (*(short *)(param_1 + 0x2e) == 0)) {
      if (((int)DAT_8015e248._2_2_ - (int)*(short *)(param_1 + 0xe)) + 0x60U < 0xc1) {
        iVar7 = 0;
        do {
          puVar4 = (undefined1 *)FUN_801055e4(param_1);
          if (puVar4 != (undefined1 *)0x0) {
            *puVar4 = 1;
            puVar4[6] = 9;
            puVar4[7] = 3;
            if (iVar7 == 0) {
              puVar4[0x25] = 0x40;
            }
            else {
              puVar4[0x25] = 0;
            }
            uVar5 = 0xfffd0000;
            if (iVar7 == 0) {
              uVar5 = 0x30000;
            }
            *(undefined4 *)(puVar4 + 0x14) = uVar5;
            if (iVar7 == 0) {
              sVar3 = 8;
            }
            else {
              sVar3 = -8;
            }
            *(short *)(puVar4 + 0xe) = *(short *)(param_1 + 0xe) + sVar3;
            uVar2 = *(undefined2 *)(param_1 + 0x12);
            puVar4[1] = 0;
            *(undefined2 *)(puVar4 + 0x12) = uVar2;
            *puVar8 = puVar4;
            puVar8 = puVar8 + 1;
            *(char *)(param_1 + 0x52) = *(char *)(param_1 + 0x52) + '\x01';
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 2);
      }
      if (*(char *)(param_1 + 0x52) != '\0') {
        uVar1 = *(undefined1 *)(param_1 + 2);
        *(undefined1 *)(param_1 + 0x56) = 8;
        *(undefined1 *)(param_1 + 2) = 3;
        *(undefined1 *)(param_1 + 0x55) = uVar1;
      }
    }
    else {
      iVar7 = 0;
      do {
        pcVar6 = (char *)*puVar8;
        if ((pcVar6 != (char *)0x0) && ((*pcVar6 == '\0' || (pcVar6[6] != '\t')))) {
          *puVar8 = 0;
          *(char *)(param_1 + 0x52) = *(char *)(param_1 + 0x52) + -1;
        }
        iVar7 = iVar7 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar7 < 2);
    }
  }
  return;
}


