// T2_1F, STAGE05.BIN, handler 0x801E65AC. Ghidra output with the object struct applied; not matching C.
// ---- 801e65ac FUN_801e65ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e65ac(MM8Obj *obj)

{
  char cVar1;
  
  obj->field_0x41 = 0;
  obj->contact_dmg = obj->contact_dmg & 0xdf;
  obj->invuln = obj->invuln & 0xdf;
  (*(code *)(&PTR_FUN_801ea9a0)[obj->state])();
  if (obj->active != 0) {
    cVar1 = FUN_801e72fc(obj);
    if (cVar1 == '\0') {
      Obj_CullAndQueueDraw(obj);
    }
    else {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801e6648 FUN_801e6648

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6648(MM8Obj *obj)

{
  word wVar1;
  
  obj->bank = 0x51;
  obj->clut = DAT_80159fb5;
  wVar1 = DAT_801703ea;
  obj->box2 = &DAT_801ea9b0;
  obj->draw_list = 9;
                    /* Possible PsyQ macro: setPolyFT3() */
  obj->contact_dmg = 0x24;
  obj->field_0x43 = 0;
  obj->field_0x33 = 0;
  obj->field_0x40 = 0;
  obj->speed_x = 0;
  obj->speed_y_up = 0;
  obj->accel_x = 0;
  obj->gravity = 0;
  obj->hitbox = (byte *)0x0;
  obj->flip = 0;
  obj->dmg_table = 0;
  obj->invuln = 0x25;
  obj->hp = 0;
  obj->field_0x4a = 0;
  obj->target_prio = 0;
  obj->hitbox = (byte *)0x0;
  obj->field_0x49 = 0;
  obj->field_0x4b = 0;
  obj->vram_base = wVar1;
  FUN_801e6c90(obj,&DAT_801ea9d0);
  Anim_Set(obj,0);
  obj->sub2 = 0;
  obj->state = obj->state + 1;
  return;
}


// ---- 801e6718 FUN_801e6718

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e6718(MM8Obj *obj)

{
  short sVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (obj->sub2 == 0) {
    obj->speed_y_up = 0;
    obj->gravity = 0;
    obj->field_0x49 = 0;
    obj->field_0x43 = 0;
    *(word *)&obj->field_0x4c = obj->y_frac;
    *(short *)&obj->field_0x4e = obj->y;
    obj->sub2 = obj->sub2 + 1;
  }
  Anim_Step(obj);
  uVar3 = *(undefined4 *)&obj->field_0x4c;
  sVar1 = obj->prev_y;
  obj->y_frac = (short)uVar3;
  obj->y = (short)((uint)uVar3 >> 0x10);
  obj->prev_y = (short)((uint)uVar3 >> 0x10);
  if (obj->target_prio == 2) {
    cVar2 = obj->field_0x4b + -1;
    obj->field_0x4b = cVar2;
    if (cVar2 == '\0') {
      obj->target_prio = 0;
    }
  }
  else {
    FUN_801e7280(obj);
  }
  FUN_80106214(obj);
  cVar2 = FUN_801e6b00(obj);
  if (cVar2 == '\0') {
    obj->state = 2;
    obj->sub2 = 0;
  }
  else if (cVar2 == '\x04') {
    obj->state = 3;
  }
  else if (((byte)(cVar2 - 1U) < 2) && (obj->field_0x41 = 1, cVar2 == '\x02')) {
    obj->speed_y_up = 0x20000;
  }
  *(word *)&obj->field_0x4c = obj->y_frac;
  *(short *)&obj->field_0x4e = obj->y;
  FUN_801e71e4(obj);
  FUN_801e7468(obj);
  obj->prev_y = sVar1;
  obj->y_frac = *(undefined2 *)&obj->field_0x4c;
  obj->y = *(undefined2 *)&obj->field_0x4e;
  if (obj->target_prio == 3) {
    cVar2 = (&DAT_801eaa04)[(byte)obj->field_0x49 >> 3];
  }
  else {
    cVar2 = (&DAT_801ea9f4)[(byte)obj->field_0x49 >> 3];
  }
  obj->y = (short)cVar2 + obj->y;
  FUN_80107bf4(obj,&g_player,6);
  uVar3 = DAT_8015e248;
  if (obj->dmg_table != 0) {
    DAT_8015e248 = CONCAT22(DAT_8015e248._2_2_ + (obj->x - obj->prev_x),(undefined2)DAT_8015e248);
  }
  FUN_801e6e14(obj);
  FUN_801e7080(obj);
  DAT_8015e248 = uVar3;
  FUN_801e7120(obj);
  return;
}


// ---- 801e692c FUN_801e692c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e692c(MM8Obj *obj)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (obj->sub2 == 0) {
    obj->gravity = 0x4000;
    obj->field_0x43 = 1;
    uVar2 = *(undefined4 *)&obj->field_0x4c;
    obj->target_prio = 0;
    obj->y_frac = (short)uVar2;
    obj->y = (short)((uint)uVar2 >> 0x10);
    obj->prev_y = (short)((uint)uVar2 >> 0x10);
    obj->sub2 = obj->sub2 + 1;
  }
  Anim_Step(obj);
  FUN_801e7280(obj);
  FUN_80106214(obj);
  bVar1 = FUN_801e6b00(obj);
  if (bVar1 != 0) {
    if (bVar1 == 4) {
      obj->state = 3;
    }
    else {
      if (1 < (byte)(bVar1 - 1)) {
        if (bVar1 != 3) goto LAB_801e6a44;
        obj->contact_dmg = 4;
        obj->invuln = 5;
                    /* Possible PsyQ macro: setPolyF3() */
        obj->field_0x4b = 0x20;
                    /* Possible PsyQ macro: setLineF2() */
        obj->field_0x49 = 0x40;
        obj->accel_x = 0;
        obj->hitbox = (byte *)0x0;
        obj->hp = 0;
        obj->target_prio = 2;
        FUN_8010544c(obj,0x105);
        FUN_801e6d30(obj,&DAT_801ea9c0);
      }
      obj->state = 1;
      obj->sub2 = 0;
    }
  }
LAB_801e6a44:
  *(word *)&obj->field_0x4c = obj->y_frac;
  *(short *)&obj->field_0x4e = obj->y;
  FUN_801e71e4(obj);
  FUN_80107bf4(obj,&g_player,6);
  uVar2 = DAT_8015e248;
  if (obj->dmg_table != 0) {
    DAT_8015e248 = CONCAT22(DAT_8015e248._2_2_ + (obj->x - obj->prev_x),(undefined2)DAT_8015e248);
  }
  FUN_801e6e14(obj);
  DAT_8015e248 = uVar2;
  if ((bVar1 & 0x30) != 0) {
    obj->hitbox = (byte *)0x0;
    obj->speed_x = -obj->speed_x >> 3;
    obj->accel_x = -obj->accel_x >> 3;
  }
  FUN_801e7120(obj);
  return;
}


// ---- 801e6b00 FUN_801e6b00

undefined4 FUN_801e6b00(int param_1)

{
  char cVar1;
  short sVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
                    /* Possible PsyQ macro: setPolyF4() */
  iVar8 = (int)*(short *)(param_1 + 0xe);
  sVar2 = *(short *)(param_1 + 0x12);
  cVar1 = *(char *)(param_1 + 0x42);
  iVar7 = (int)**(char **)(param_1 + 0x38);
  iVar9 = (int)(*(char **)(param_1 + 0x38))[1];
  iVar6 = sVar2 - iVar9;
  cVar3 = FUN_80107204(iVar8 + iVar7 + -4,iVar6);
  if (cVar3 != '?') {
    cVar3 = FUN_80107204((iVar8 - iVar7) + 4,iVar6);
  }
  if ((cVar1 == '?') || (cVar3 == '?')) {
    uVar5 = 4;
  }
  else {
    bVar4 = FUN_801e7364(param_1);
    if (bVar4 == 0) {
      if (*(char *)(param_1 + 0x48) == '\x03') {
        *(undefined1 *)(param_1 + 0x48) = 0;
      }
      iVar9 = sVar2 + iVar9;
      cVar3 = FUN_80107204(iVar8 + iVar7,iVar9);
      if (cVar3 != '\x04') {
        cVar3 = FUN_80107204(iVar8 - iVar7,iVar9);
      }
      if ((cVar1 == '\x04') || (uVar5 = 0, cVar3 == '\x04')) {
        *(byte *)(param_1 + 0x33) = *(byte *)(param_1 + 0x33) | 0x80;
        uVar5 = 3;
        *(ushort *)(param_1 + 0x12) =
             *(short *)(param_1 + 0x12) -
             ((short)*(char *)(*(int *)(param_1 + 0x38) + 1) + *(short *)(param_1 + 0x12) & 0xfU);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x48) = 3;
      *(byte *)(param_1 + 0x33) = *(byte *)(param_1 + 0x33) | 0x80;
      uVar5 = 2;
      if ((bVar4 & 1) == 0) {
        uVar5 = 1;
      }
    }
  }
  return uVar5;
}


// ---- 801e6c90 FUN_801e6c90

void FUN_801e6c90(int param_1,short *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = (undefined1 *)((int)param_2 + 5);
  do {
    iVar1 = param_1 + 0x45;
    if (1 < (byte)puVar2[-1]) {
      iVar1 = param_1 + 0x46;
    }
    iVar1 = FUN_801e7cac(param_1,iVar1,(int)*param_2,(int)*(short *)(puVar2 + -3),puVar2[-1]);
    param_2 = param_2 + 3;
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0x26) = *puVar2;
    }
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 6;
  } while (iVar3 < 6);
  return;
}


// ---- 801e6d30 FUN_801e6d30

void FUN_801e6d30(int param_1,short *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = (undefined1 *)((int)param_2 + 5);
  do {
    iVar1 = FUN_8012c108(param_1,param_1 + 0x46,(int)*param_2,(int)*(short *)(puVar2 + -3),0,
                         puVar2[1]);
    param_2 = param_2 + 4;
    if (iVar1 != 0) {
      *(undefined2 *)(iVar1 + 0x3a) = 0x60;
      *(undefined1 *)(iVar1 + 7) = puVar2[-1];
      *(undefined1 *)(iVar1 + 0x26) = puVar2[2];
      *(undefined1 *)(iVar1 + 0x3c) = *puVar2;
      *(undefined1 *)(iVar1 + 0x24) = DAT_80159fb8;
      *(undefined1 *)(iVar1 + 0x33) = DAT_80159fb8;
    }
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 8;
  } while (iVar3 < 2);
  FUN_801e8768(param_1,0);
  return;
}


// ---- 801e6e14 FUN_801e6e14

void FUN_801e6e14(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  char cVar7;
  char cVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  
  uVar6 = DAT_801c3360;
  uVar5 = DAT_8015e24c;
  uVar4 = DAT_8015e248;
  uVar3 = DAT_8015e234;
  uVar2 = DAT_8015e230;
  uVar10 = *(undefined4 *)(param_1 + 0x38);
  uVar1 = *(undefined1 *)(param_1 + 0x40);
  *(undefined **)(param_1 + 0x38) = &DAT_801ea9b8;
  cVar7 = FUN_80108cd4(param_1,(uint)((*(byte *)(param_1 + 0x44) & 0x30) != 0) << 7);
  *(byte *)(param_1 + 0x25) = *(byte *)(param_1 + 0x25) ^ 0x40;
  DAT_8015e248 = uVar4;
  DAT_8015e24c = uVar5;
  cVar8 = FUN_80108cd4(param_1,(uint)((*(byte *)(param_1 + 0x44) & 3) != 0) << 7);
  *(byte *)(param_1 + 0x25) = *(byte *)(param_1 + 0x25) ^ 0x40;
  if (cVar8 == '\0') {
    if (cVar7 != '\0') {
      if ((*(byte *)(param_1 + 0x4a) & 1) == 0) goto LAB_801e6f30;
      goto LAB_801e6f4c;
    }
    DAT_8015e248 = uVar4;
    DAT_8015e24c = uVar5;
    if (*(char *)(param_1 + 0x44) != '\0') goto LAB_801e6f4c;
  }
  else {
LAB_801e6f30:
    if ((cVar7 != '\0') || ((*(byte *)(param_1 + 0x4a) & 0x10) == 0)) {
      if ((cVar8 == -0x80) && (cVar7 == -0x80)) {
        if ((DAT_8015e261 & 0x40) == 0) {
          cVar8 = '\0';
        }
        else {
          cVar7 = '\0';
        }
      }
      uVar9 = 0;
      if (((*(byte *)(param_1 + 0x44) & 0x20) != 0) &&
         (DAT_8015e248 = uVar4, DAT_8015e24c = uVar5, cVar7 == '\x7f')) goto LAB_801e7024;
      if (cVar8 == '\x7f') {
        uVar9 = 2;
        DAT_8015e248 = uVar4;
        DAT_8015e24c = uVar5;
      }
      else if (cVar7 == '\x7f') {
        uVar9 = 0x20;
        DAT_8015e248 = uVar4;
        DAT_8015e24c = uVar5;
      }
      else {
        if (cVar8 == -0x80) {
          DAT_8015e248 = uVar4;
          DAT_8015e24c = uVar5;
          Anim_Set(param_1,1);
          uVar9 = 1;
        }
        else {
          DAT_8015e248 = uVar4;
          DAT_8015e24c = uVar5;
          if (cVar7 != -0x80) goto LAB_801e7020;
          if (cVar8 == '\x7f') goto LAB_801e7024;
          Anim_Set(param_1,2);
          uVar9 = 0x10;
        }
        *(undefined1 *)(param_1 + 0x4a) = uVar9;
      }
LAB_801e7020:
      *(undefined1 *)(param_1 + 0x44) = uVar9;
      goto LAB_801e7024;
    }
LAB_801e6f4c:
    DAT_8015e248 = uVar4;
    DAT_8015e24c = uVar5;
    Anim_Set(param_1,0);
  }
  *(undefined1 *)(param_1 + 0x44) = 0;
  *(undefined1 *)(param_1 + 0x4a) = 0;
LAB_801e7024:
  *(undefined4 *)(param_1 + 0x38) = uVar10;
  *(undefined1 *)(param_1 + 0x40) = uVar1;
  DAT_801c3360 = uVar6;
  DAT_8015e230 = uVar2;
  DAT_8015e234 = uVar3;
  return;
}


// ---- 801e7080 FUN_801e7080

void FUN_801e7080(int param_1)

{
  undefined1 uVar1;
  
  if ((*(char *)(param_1 + 0x41) == '\0') ||
     (*(short *)(param_1 + 0x12) == *(short *)(param_1 + 0x36))) {
    if ((*(byte *)(param_1 + 0x44) & 0x10) == 0) {
      if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x1c) = 0x4000;
      *(undefined1 *)(param_1 + 0x47) = 1;
      uVar1 = 0x20;
      *(undefined4 *)(param_1 + 0x3c) = 0;
      *(undefined1 *)(param_1 + 0x45) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = 0xffffc000;
      *(undefined1 *)(param_1 + 0x47) = 1;
                    /* Possible PsyQ macro: setLineF2() */
      *(undefined1 *)(param_1 + 0x45) = 0x40;
      uVar1 = 0x60;
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    *(undefined1 *)(param_1 + 0x46) = uVar1;
    FUN_8010544c(param_1,0x104);
  }
  return;
}


// ---- 801e7120 FUN_801e7120

void FUN_801e7120(int param_1)

{
  if (*(int *)(param_1 + 0x3c) < 0x20000) {
    if (-0x20000 < *(int *)(param_1 + 0x3c)) goto LAB_801e716c;
    *(undefined4 *)(param_1 + 0x1c) = 0x1000;
    *(undefined4 *)(param_1 + 0x3c) = 0xfffe0000;
  }
  else {
    *(undefined4 *)(param_1 + 0x3c) = 0x20000;
    *(undefined4 *)(param_1 + 0x1c) = 0xfffff000;
  }
  *(undefined1 *)(param_1 + 0x47) = 2;
LAB_801e716c:
  if (*(int *)(param_1 + 0x18) < -0x5ffff) {
    *(undefined4 *)(param_1 + 0x18) = 0xfffa0000;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else if (0x5ffff < *(int *)(param_1 + 0x18)) {
    *(undefined4 *)(param_1 + 0x18) = 0x60000;
    *(undefined4 *)(param_1 + 0x20) = 0x4000;
  }
  if ((*(int *)(param_1 + 0x3c) == 0) && (*(char *)(param_1 + 0x47) == '\x02')) {
    *(undefined1 *)(param_1 + 0x45) = 4;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined1 *)(param_1 + 0x47) = 0;
    *(undefined1 *)(param_1 + 0x46) = 5;
  }
  return;
}


// ---- 801e71e4 FUN_801e71e4

void FUN_801e71e4(int param_1)

{
  short sVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  
  sVar1 = *(short *)(param_1 + 0xe);
  sVar2 = *(short *)(param_1 + 0x12);
  if (*(byte *)(param_1 + 0x48) < 2) {
    cVar3 = FUN_80107204(sVar1 + -0x20,(int)sVar2);
    cVar4 = FUN_80107204(sVar1 + 0x20,(int)sVar2);
    if ((cVar3 == '\x03') || (cVar4 == '\x03')) {
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x48) = 0;
    }
  }
  return;
}


// ---- 801e7280 FUN_801e7280

void FUN_801e7280(int param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = -(uint)(*(char *)(param_1 + 0x48) == '\x01') & 0x18000;
  if (*(char *)(param_1 + 0x43) == '\0') {
    iVar1 = *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x1c);
    uVar2 = uVar2 + iVar1;
    *(int *)(param_1 + 0x3c) = iVar1;
  }
  *(uint *)(param_1 + 0x14) = uVar2;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x20);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x18);
  return;
}


// ---- 801e72fc FUN_801e72fc

bool FUN_801e72fc(int param_1)

{
  bool bVar1;
  
  bVar1 = true;
  if ((DAT_801d2918._2_2_ + -0x60 < (int)*(short *)(param_1 + 0xe)) &&
     ((int)*(short *)(param_1 + 0xe) < DAT_801d2918._2_2_ + 0x1a0)) {
    if (g_cam_y + -0xf0 < (int)*(short *)(param_1 + 0x12)) {
      bVar1 = g_cam_y + 0x1e0 <= (int)*(short *)(param_1 + 0x12);
    }
  }
  return bVar1;
}


// ---- 801e7364 FUN_801e7364

int FUN_801e7364(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  iVar6 = 0;
  iVar5 = 0;
  pcVar4 = &DAT_801b1eec;
  pcVar3 = "";
  do {
    if (((*pcVar4 != '\0') && (pcVar3[5] == '\x1e')) && ((pcVar3[6] & 0x80U) == 0)) {
      uVar1 = FUN_80107bf4(pcVar4,param_1,2);
      if ((uVar1 & 0x80) != 0) {
        iVar7 = 0x80;
        if (pcVar3[1] == '\0') {
          iVar2 = -0x80000000;
          if (*pcVar3 != '\x04') goto LAB_801e743c;
          iVar7 = 0x81;
        }
        break;
      }
      iVar5 = iVar5 + 1;
      iVar2 = 0;
      if (2 < iVar5) goto LAB_801e743c;
    }
    pcVar3 = pcVar3 + 0x50;
    iVar6 = iVar6 + 1;
    pcVar4 = pcVar4 + 0x50;
  } while (iVar6 < 0x20);
  iVar2 = iVar7 << 0x18;
LAB_801e743c:
  return iVar2 >> 0x18;
}


// ---- 801e7468 FUN_801e7468

void FUN_801e7468(int param_1)

{
  char cVar1;
  
  if ((*(short *)(param_1 + 0x12) == *(short *)(param_1 + 0x36)) && (*(int *)(param_1 + 0x3c) == 0))
  {
    if (*(char *)(param_1 + 0x48) == '\x02') {
      cVar1 = *(char *)(param_1 + 0x49) + '\x04';
    }
    else {
      cVar1 = *(char *)(param_1 + 0x49) + '\x01';
    }
    *(char *)(param_1 + 0x49) = cVar1;
    if (*(byte *)(param_1 + 0x49) < 0x80) {
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x49) = 0;
  return;
}


// ---- 801e74d8 FUN_801e74d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e74d8(MM8Obj *obj)

{
  FUN_80108ed8(obj,0x10,0);
  FUN_80108ed8(obj,0xfffffff0,0);
  FUN_8012a5fc(obj,0);
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801e7cac FUN_801e7cac

undefined1 * FUN_801e7cac(int param_1,undefined4 param_2,short param_3,short param_4,byte param_5)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Obj_AllocType3();
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    *puVar2 = 1;
    puVar2[1] = 0;
    puVar2[6] = 0x15;
    *(int *)(puVar2 + 0x18) = param_1;
    *(undefined4 *)(puVar2 + 0x14) = param_2;
    puVar2[0x39] = *(undefined1 *)(param_1 + 0x27);
    uVar1 = *(undefined1 *)(param_1 + 7);
    *(int *)(puVar2 + 0x1c) = (int)param_3;
    *(int *)(puVar2 + 0x20) = (int)param_4;
    puVar2[0x3a] = uVar1;
    uVar1 = (&DAT_801eaa48)[param_5];
    puVar2[7] = param_5;
    puVar2[0x3b] = uVar1;
    puVar2[0x27] = *(undefined1 *)(param_1 + 0x27);
    puVar2[0x25] = *(undefined1 *)(param_1 + 0x25);
    puVar2[0x26] = *(undefined1 *)(param_1 + 0x26);
    *(short *)(puVar2 + 0xe) = param_3 + *(short *)(param_1 + 0xe);
    *(short *)(puVar2 + 0x12) = param_4 + *(short *)(param_1 + 0x12);
  }
  return puVar2;
}


// ---- 801e8768 FUN_801e8768

void FUN_801e8768(int param_1,int param_2)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  iVar15 = 1;
  iVar11 = param_2 * 8;
  pbVar13 = (&PTR_DAT_801eacc4)[param_2 * 2];
  sVar4 = *(short *)(param_1 + 0xe);
  bVar1 = (&DAT_801eacc8)[iVar11];
  sVar5 = *(short *)(param_1 + 0x12);
  iVar16 = 0;
  if (bVar1 != 0) {
    do {
      iVar14 = 0;
      if ((*pbVar13 & 0x20) != 0) {
        uVar7 = Rand();
        iVar15 = (uVar7 & 3) + 1;
      }
      if (iVar15 != 0) {
        pbVar12 = pbVar13 + 2;
        do {
          puVar8 = (undefined1 *)Obj_AllocType3();
          if (puVar8 != (undefined1 *)0x0) {
            *puVar8 = 1;
            puVar8[6] = 0x27;
            puVar8[0x27] = (&DAT_801eacc9)[iVar11];
            *(undefined2 *)(puVar8 + 0x2c) = (&DAT_80170348)[(byte)(&DAT_801eacc9)[iVar11]];
            uVar2 = (&DAT_80159f64)[(byte)(&DAT_801eacca)[iVar11]];
            puVar8[0x25] = 0;
            puVar8[0x24] = uVar2;
            bVar3 = pbVar12[1];
            *(undefined4 *)(puVar8 + 0x1c) = 0;
            *(undefined4 *)(puVar8 + 0x20) = 0x4000;
            puVar8[0x26] = bVar3;
            puVar8[0x38] = *pbVar13 & 1;
            if ((*pbVar13 & 2) == 0) {
              *(short *)(puVar8 + 0xe) = sVar4 + *(short *)(pbVar12 + 2);
              *(short *)(puVar8 + 0x12) = sVar5 + *(short *)(pbVar12 + 4);
                    /* Possible PsyQ macro: setLineF3() */
              *(undefined4 *)(puVar8 + 0x14) = *(undefined4 *)(pbVar12 + 6);
              *(undefined4 *)(puVar8 + 0x18) = *(undefined4 *)(pbVar12 + 10);
              bVar3 = pbVar12[-1];
              uVar7 = (uint)*pbVar12;
            }
            else {
              uVar6 = Rand();
              *(ushort *)(puVar8 + 0xe) = sVar4 + *(short *)(pbVar12 + 2) + (uVar6 & 7);
              uVar6 = Rand();
              *(ushort *)(puVar8 + 0x12) = sVar5 + *(short *)(pbVar12 + 4) + (uVar6 & 7);
              uVar7 = Rand();
              *(uint *)(puVar8 + 0x14) = (uVar7 & 0x2f) * 0x1000 + *(int *)(pbVar12 + 6);
              uVar7 = Rand();
              *(uint *)(puVar8 + 0x18) = (uVar7 & 0x2f) * 0x1000 + *(int *)(pbVar12 + 10);
              if (*pbVar12 == 0) {
                *pbVar12 = 1;
              }
              uVar9 = Rand();
              uVar10 = *pbVar12 + 1;
              uVar7 = (uVar9 & 0xff) % uVar10;
              if (uVar10 == 0) {
                trap(0x1c00);
              }
              if ((uVar10 == 0xffffffff) && ((uVar9 & 0xff) == 0x80000000)) {
                trap(0x1800);
              }
              bVar3 = pbVar12[-1];
            }
            Anim_SetAtStep(puVar8,bVar3,uVar7);
            pbVar12 = pbVar12 + 0x10;
            pbVar13 = pbVar13 + 0x10;
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < iVar15);
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < (int)(uint)bVar1);
  }
  return;
}


