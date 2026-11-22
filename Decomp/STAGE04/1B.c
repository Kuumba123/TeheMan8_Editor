// ID 1B, STAGE04.BIN, handler 0x801DC008. Ghidra output with the object struct applied; not matching C.
// ---- 801dc008 FUN_801dc008

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc008(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e6e10)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    iVar1 = Obj_InActiveArea(obj);
    if ((iVar1 == 0) && (iVar1 = FUN_80109430(obj,&g_player,0x140,0xf0), iVar1 == 0)) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801dc09c FUN_801dc09c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc09c(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 5;
  obj->flip = 0;
  obj->hitbox = &DAT_801e6e20;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x50 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  obj->state = obj->state + 1;
  Anim_Set(obj,0);
  return;
}


// ---- 801dc108 FUN_801dc108

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc108(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (uint)obj->var * 6;
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
  }
  iVar3 = FUN_801dc564(obj);
  if (iVar3 != 0) goto LAB_801dc24c;
  if (obj->field_0x53 != '\0') {
    FUN_801dc6b4(obj);
    goto LAB_801dc24c;
  }
  iVar3 = (uint)DAT_8015e248._2_2_ - (uint)(ushort)obj->x;
  if ((&DAT_801e6e3d)[iVar2] == '\0') {
    if (((char)(&DAT_801e6e3b)[iVar2] != 0) &&
       ((int)(char)(&DAT_801e6e3b)[iVar2] < iVar3 * 0x10000 >> 0x10)) {
      obj->field_0x53 = obj->field_0x53 | 1;
    }
    if (((char)(&DAT_801e6e3c)[iVar2] != 0) &&
       ((int)(short)iVar3 < (int)(char)(&DAT_801e6e3c)[iVar2])) {
      bVar1 = obj->field_0x53 | 2;
LAB_801dc234:
      obj->field_0x53 = bVar1;
    }
  }
  else {
    iVar3 = iVar3 * 0x10000 >> 0x10;
    if ((iVar3 <= (char)(&DAT_801e6e3b)[iVar2]) && ((char)(&DAT_801e6e3c)[iVar2] <= iVar3)) {
      bVar1 = obj->field_0x53 | 3;
      goto LAB_801dc234;
    }
  }
  if (obj->field_0x53 != '\0') {
    obj->field_0x50 = 1;
  }
LAB_801dc24c:
  FUN_801dc634(obj);
  return;
}


// ---- 801dc26c FUN_801dc26c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc26c(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,4);
    obj->field_0x52 = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
  }
  cVar1 = obj->field_0x52 + -1;
  obj->field_0x52 = cVar1;
  if (cVar1 == '\0') {
    obj->state = 1;
    obj->sub2 = 0;
  }
  FUN_801dc5c0(obj);
  FUN_801dc634(obj);
  return;
}


// ---- 801dc2f8 FUN_801dc2f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc2f8(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e6e44)[obj->sub2])();
                    /* Possible PsyQ macro: setPolyGT4() */
  if (4 < obj->sub2) {
    obj->state = 1;
    obj->sub2 = 0;
  }
  FUN_801dc634(obj);
  return;
}


// ---- 801dc364 FUN_801dc364

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc364(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  bVar1 = obj->sub3;
  if (bVar1 == 0) {
    uVar3 = 3;
LAB_801dc3c4:
    Anim_Set(obj,uVar3);
  }
  else {
    if (bVar1 != 1) {
      if (bVar1 != 2) {
        if (bVar1 == 3) {
          Anim_Step(obj);
          iVar2 = Anim_AtLoopMarker(obj);
          if (iVar2 != 0) {
            obj->sub3 = 0;
            obj->sub2 = obj->sub2 + 1;
          }
        }
        goto LAB_801dc410;
      }
      uVar3 = 1;
      goto LAB_801dc3c4;
    }
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 == 0) goto LAB_801dc410;
  }
  obj->sub3 = obj->sub3 + 1;
LAB_801dc410:
  FUN_801dc564(obj);
  return;
}


// ---- 801dc42c FUN_801dc42c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc42c(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub3 == 0) {
    obj->field_0x52 = 0x18;
    obj->sub3 = obj->sub3 + 1;
  }
  cVar1 = obj->field_0x52 + -1;
  obj->field_0x52 = cVar1;
  if (cVar1 == '\0') {
    obj->sub3 = 0;
    obj->sub2 = obj->sub2 + 1;
  }
  FUN_801dc5c0();
  return;
}


// ---- 801dc498 FUN_801dc498

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc498(MM8Obj *obj)

{
                    /* Possible PsyQ macro: setLineF2() */
  FUN_801dc730();
  FUN_801dc5c0(obj);
  obj->sub2 = obj->sub2 + 1;
  return;
}


// ---- 801dc4d8 FUN_801dc4d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc4d8(MM8Obj *obj)

{
  int iVar1;
  
                    /* Probable PsyQ macro: setTile16() */
  if (obj->sub3 == 0) {
    Anim_Set(obj,2);
    obj->sub3 = obj->sub3 + 1;
  }
  if (obj->sub3 == 1) {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      obj->sub3 = 0;
      obj->sub2 = obj->sub2 + 1;
    }
  }
  FUN_801dc564(obj);
                    /* Possible PsyQ macro: setPolyF3() */
  return;
}


// ---- 801dc564 FUN_801dc564

undefined4 FUN_801dc564(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_801dc5c0();
                    /* Possible PsyQ macro: setTile16() */
  uVar2 = 0;
  if ((cVar1 == '\x03') && (uVar2 = 0, DAT_80158f5c == '\v')) {
    uVar2 = 1;
    *(undefined1 *)(param_1 + 1) = 2;
    *(undefined1 *)(param_1 + 2) = 0;
  }
  return uVar2;
}


// ---- 801dc5c0 FUN_801dc5c0

undefined1 FUN_801dc5c0(int param_1)

{
  undefined1 uVar1;
  undefined *puVar2;
  ushort uVar3;
  
  uVar3 = *(ushort *)(param_1 + 0x2e) & 0x7fff;
  if (1 < uVar3) {
    if (uVar3 == 2) {
      puVar2 = &DAT_801e6e28;
      goto LAB_801dc618;
    }
    if (uVar3 == 3) {
      puVar2 = &DAT_801e6e30;
      goto LAB_801dc618;
    }
  }
  puVar2 = &DAT_801e6e20;
LAB_801dc618:
  *(undefined **)(param_1 + 0x3c) = puVar2;
  uVar1 = Enemy_CheckWeaponHits();
  return uVar1;
}


// ---- 801dc634 FUN_801dc634

undefined1 FUN_801dc634(int param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)(param_1 + 0x2e) & 0x7fff;
  if (1 < uVar2) {
    if (uVar2 == 2) {
      *(undefined **)(param_1 + 0x38) = &DAT_801e6e28;
      goto LAB_801dc690;
    }
    if (uVar2 == 3) {
      *(undefined **)(param_1 + 0x38) = &DAT_801e6e30;
      goto LAB_801dc690;
    }
  }
  *(undefined **)(param_1 + 0x38) = &DAT_801e6e20;
LAB_801dc690:
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
  uVar1 = FUN_80107bf4(param_1,&g_player,1);
  return uVar1;
}


// ---- 801dc6b4 FUN_801dc6b4

undefined4 FUN_801dc6b4(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((*(char *)(param_1 + 0x53) != '\0') && (uVar3 = 0, *(char *)(param_1 + 0x50) != '\0')) {
    cVar2 = *(char *)(param_1 + 0x50) + -1;
    *(char *)(param_1 + 0x50) = cVar2;
    uVar3 = 0;
    if (cVar2 == '\0') {
      uVar3 = 1;
      uVar1 = (&DAT_801e6e3a)[(uint)*(byte *)(param_1 + 7) * 6];
      *(undefined1 *)(param_1 + 1) = 3;
      *(undefined1 *)(param_1 + 2) = 0;
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 0x50) = uVar1;
    }
  }
  return uVar3;
}


// ---- 801dc730 FUN_801dc730

undefined1 * FUN_801dc730(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = (&DAT_801e6e38)[(uint)*(byte *)(param_1 + 7) * 6];
    puVar1[7] = (&DAT_801e6e39)[(uint)*(byte *)(param_1 + 7) * 6];
    *(undefined2 *)(puVar1 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    *(short *)(puVar1 + 0x12) = *(short *)(param_1 + 0x12) + 2;
  }
  return puVar1;
}


// ---- 801dc878 FUN_801dc878

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc878(MM8Obj *obj)

{
  int iVar1;
  
  Enemy_InitFromTable();
                    /* Possible PsyQ macro: setLineF2() */
  obj->draw_list = 8;
  obj->hitbox = &DAT_801e6e90;
  obj->box2 = &DAT_801e6e78;
  obj->flip = 0;
  obj->field_0x43 = 1;
  obj->field_0x50 = 4;
  obj->field_0x51 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  obj->field_0x58 = 0;
  obj->field_0x59 = 0;
  obj->field_0x5a = 0;
  obj->field_0x5b = 0;
  obj->field_0x5c = 0;
  if ((obj->var & 1) == 0) {
    obj->state = 1;
  }
  else {
    obj->state = 2;
  }
  obj->sub2 = 0;
  iVar1 = FUN_8012c108(obj,&obj->field_0x52,0,0,0,8);
  if (iVar1 != 0) {
                    /* Probable PsyQ macro: setTile16() */
    *(undefined1 *)(iVar1 + 7) = 0x70;
    *(byte *)(iVar1 + 0x26) = obj->draw_list - 1;
  }
  FUN_801093d4(iVar1,&obj->field_0x54);
  Anim_Set(obj,0);
  return;
}


// ---- 801dc968 FUN_801dc968

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc968(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_80107bf4(obj,&g_player,1);
  Enemy_CheckWeaponHits(obj);
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801dd32c(obj);
  obj->field_0x53 = cVar2;
  if (cVar1 != cVar2) {
    if (obj->field_0x53 == '\0') {
      obj->sub2 = 0;
    }
    else {
      iVar3 = FUN_801dd57c(obj);
      if (iVar3 != 0) {
        uVar4 = FUN_801093fc(&obj->field_0x54);
        FUN_801dd684(obj,uVar4);
      }
      obj->sub2 = 1;
    }
  }
  if (obj->sub2 == 0) {
    uVar4 = 0;
  }
  else {
    if (obj->sub2 != 1) {
      return;
    }
    uVar4 = 1;
  }
  Anim_Set(obj,uVar4);
  obj->sub2 = 2;
  return;
}


// ---- 801dca44 FUN_801dca44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dca44(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (obj->sub2 == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 3;
    if (obj->sub2 != 1) goto LAB_801dca8c;
  }
  Anim_Set(obj,uVar3);
  obj->sub2 = 2;
LAB_801dca8c:
                    /* Probable PsyQ macro: setPolyGT4() */
  FUN_80107bf4(obj,&g_player,1);
  Enemy_CheckWeaponHits(obj);
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801dd32c(obj);
                    /* Probable PsyQ macro: setLineF2() */
  obj->field_0x53 = cVar2;
  if ((cVar1 != cVar2) && (obj->field_0x53 != '\0')) {
                    /* Possible PsyQ macro: setLineF2() */
    if (obj->field_0x50 == '\x04') {
      obj->field_0x51 = 0x21;
      obj->state = 3;
      obj->sub2 = 0;
    }
    FUN_8010544c(obj,0x92);
  }
  return;
}


// ---- 801dcb18 FUN_801dcb18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcb18(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  
  bVar2 = obj->sub2;
  if (bVar2 == 0) {
    Anim_Set(obj,3);
    bVar2 = obj->sub2;
    obj->field_0x43 = 1;
  }
  else {
    if (bVar2 != 1) {
      if (bVar2 == 2) {
        Anim_Set(obj,4);
        obj->gravity = 0x4000;
        obj->speed_y_up = 0;
        obj->sub2 = obj->sub2 + 1;
      }
      else {
        Anim_Step(obj);
      }
      goto LAB_801dcbe8;
    }
    Anim_Step(obj);
    if ((short)obj->frame < 0) {
      obj->hitbox = &DAT_801e6e94;
      obj->box2 = &DAT_801e6e80;
    }
    iVar4 = Anim_AtLoopMarker(obj);
    if (iVar4 == 0) goto LAB_801dcbe8;
    bVar2 = obj->sub2;
  }
  obj->sub2 = bVar2 + 1;
LAB_801dcbe8:
  FUN_80104ccc(obj);
  FUN_801dd714(obj);
  FUN_80106214(obj);
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  cVar1 = obj->field_0x53;
  cVar3 = FUN_801dd32c(obj);
  obj->field_0x53 = cVar3;
  if (((cVar1 != cVar3) && (obj->field_0x53 != '\0')) && (iVar4 = FUN_801dd57c(obj), iVar4 != 0)) {
    uVar5 = FUN_801093fc(&obj->field_0x54);
    FUN_801dd684(obj,uVar5);
  }
  pbVar6 = obj->hitbox;
  obj->hitbox = &DAT_801e6e9c;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar6;
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->field_0x43 = 0;
    obj->state = 4;
    obj->sub2 = 0;
  }
  return;
}


// ---- 801dccc0 FUN_801dccc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dccc0(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
  if (obj->sub2 == 0) {
    if ((obj->field_0x50 == '\x04') && (iVar3 = FUN_801dd57c(), iVar3 != 0)) {
      uVar4 = FUN_801093fc(&obj->field_0x54);
      FUN_801dd684(obj,uVar4);
    }
    Anim_Set(obj,5);
    obj->field_0x43 = 0;
    obj->accel_x = 0;
    obj->speed_x = 0;
    obj->gravity = 0;
    obj->speed_y_up = 0;
    obj->field_0x58 = (char)obj->frame;
    obj->field_0x5b = (char)obj->y;
    obj->field_0x5c = (char)((ushort)obj->y >> 8);
    obj->sub2 = obj->sub2 + 1;
  }
  else if (obj->sub2 == 1) {
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    if (iVar3 != 0) {
      obj->state = 5;
      obj->sub2 = 0;
    }
  }
  obj->y = *(short *)&obj->field_0x5b;
  FUN_80106214(obj);
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801dd3f8(obj);
  obj->field_0x53 = cVar2;
  if (((cVar1 != cVar2) && (obj->field_0x53 != '\0')) && (iVar3 = FUN_801dd57c(obj), iVar3 != 0)) {
    uVar4 = FUN_801093fc(&obj->field_0x54);
    FUN_801dd684(obj,uVar4);
  }
  obj->y = *(short *)&obj->field_0x5b;
  obj->y = *(short *)&obj->field_0x5b + ((obj->frame & 0x7fff) - (ushort)(byte)obj->field_0x58);
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  pbVar5 = obj->hitbox;
  obj->hitbox = &DAT_801e6e9c;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar5;
  return;
}


// ---- 801dce74 FUN_801dce74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce74(MM8Obj *obj)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,6);
    obj->field_0x5d = 0xf;
    obj->y = (ushort)(byte)obj->field_0x5b;
    obj->y = CONCAT11(obj->field_0x5c,obj->field_0x5b);
    obj->sub2 = obj->sub2 + 1;
  }
  else if ((obj->sub2 == 1) &&
          (cVar1 = obj->field_0x5d + -1, obj->field_0x5d = cVar1, cVar1 == '\0')) {
    obj->state = 6;
    obj->sub2 = 0;
  }
  FUN_80106214(obj);
  cVar1 = obj->field_0x53;
  cVar2 = FUN_801dd3f8(obj);
  obj->field_0x53 = cVar2;
  if (((cVar1 != cVar2) && (obj->field_0x53 != '\0')) && (iVar3 = FUN_801dd57c(obj), iVar3 != 0)) {
    uVar4 = FUN_801093fc(&obj->field_0x54);
    FUN_801dd684(obj,uVar4);
    obj->state = 4;
    obj->sub2 = 0;
  }
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  pbVar5 = obj->hitbox;
  obj->hitbox = &DAT_801e6e9c;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar5;
  return;
}


// ---- 801dcfb0 FUN_801dcfb0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcfb0(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  short sVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  byte *pbVar7;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,7);
    FUN_801dd734(obj);
    obj->field_0x5d = 0x1e;
    obj->field_0x58 = 0;
    obj->field_0x5b = (char)obj->y;
    obj->field_0x5c = (char)((ushort)obj->y >> 8);
    obj->sub2 = obj->sub2 + 1;
  }
  else if (obj->sub2 == 1) {
    Anim_Step(obj);
    obj->field_0x58 = obj->field_0x58 + '\x01';
  }
  if (0x17 < (byte)obj->field_0x58) {
    obj->field_0x58 = 0;
  }
  sVar3 = *(short *)&obj->field_0x5b;
  sVar2 = obj->prev_y;
  obj->y = sVar3;
  obj->prev_y = sVar3;
  FUN_80104c34(obj);
  FUN_80106214(obj);
  cVar1 = obj->field_0x53;
  cVar4 = FUN_801dd3f8(obj);
  obj->field_0x53 = cVar4;
  if ((cVar1 != cVar4) && (obj->field_0x53 != '\0')) {
    iVar5 = FUN_801dd57c(obj);
    if (iVar5 != 0) {
      uVar6 = FUN_801093fc(&obj->field_0x54);
      FUN_801dd684(obj,uVar6);
    }
    obj->state = 4;
    obj->sub2 = 0;
  }
  obj->prev_y = sVar2;
  obj->y = sVar3;
  obj->y = (char)(&DAT_801e6eac)[(byte)obj->field_0x58 / 3] + sVar3;
  FUN_80107bf4(obj,&g_player,5);
  Enemy_CheckWeaponHits(obj);
  pbVar7 = obj->hitbox;
  obj->hitbox = &DAT_801e6e9c;
  Enemy_ContactDamage(obj);
  obj->hitbox = pbVar7;
  if ((obj->field_0x33 & 0x30) != 0) {
    obj->speed_x = -obj->speed_x;
  }
  iVar5 = FUN_801dd76c(obj);
  if (iVar5 != 0) {
    obj->speed_x = -obj->speed_x;
  }
  if ((obj->field_0x33 & 0x80) == 0) {
    obj->state = 3;
    obj->sub2 = 2;
  }
  if (obj->state == 4) {
    obj->y = (ushort)(byte)obj->field_0x5b;
    obj->y = *(short *)&obj->field_0x5b;
  }
  return;
}


// ---- 801dd1f8 FUN_801dd1f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd1f8(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = obj->sub2;
  if (bVar2 == 0) {
    iVar3 = FUN_8012c108(obj,0,0,0,0,0);
    if (iVar3 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
      *(undefined1 *)(iVar3 + 0x27) = 0x34;
      *(undefined1 *)(iVar3 + 0x26) = 8;
      *(undefined1 *)(iVar3 + 7) = 0x10;
    }
    FUN_8010544c(obj,9);
    FUN_8012a5fc(obj,3);
    obj->field_0x52 = 2;
    bVar2 = obj->sub2;
    obj->field_0x5d = 0;
    obj->field_0x4 = 1;
  }
  else if (bVar2 == 1) {
    obj->field_0x4 = 1;
    cVar1 = obj->field_0x5d + '\x01';
    obj->field_0x5d = cVar1;
    if (cVar1 != '\x01') {
      return;
    }
    bVar2 = obj->sub2;
    obj->contact_dmg = 6;
  }
  else {
    if (bVar2 != 2) {
      Obj_FreeDespawn(obj);
      return;
    }
    obj->field_0x4 = 1;
    obj->hitbox = &DAT_801e6ea0;
    Enemy_ContactDamage(obj);
    bVar2 = obj->field_0x5d + 1;
    obj->field_0x5d = bVar2;
    if (bVar2 < 6) {
      return;
    }
    bVar2 = obj->sub2;
  }
  obj->sub2 = bVar2 + 1;
  return;
}


// ---- 801dd32c FUN_801dd32c

undefined1 FUN_801dd32c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  *(undefined **)(param_1 + 0x38) = &DAT_801e6e88;
  FUN_80107bf4(param_1,&g_player,0);
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  if (DAT_8015e24c._2_2_ < DAT_8015e272) {
    DAT_801c3360 = 0;
  }
  if ((DAT_8015e26f & 0x80) != 0) {
    DAT_801c3360 = 0;
  }
  if (DAT_8015e230 == 0) {
    DAT_801c3360 = 0;
  }
  *(byte *)(param_1 + 0x53) = DAT_801c3360 & 0x80;
  return *(undefined1 *)(param_1 + 0x53);
}


// ---- 801dd3f8 FUN_801dd3f8

undefined1 FUN_801dd3f8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  *(undefined **)(param_1 + 0x38) = &DAT_801e6e88;
  FUN_80107bf4(param_1,&g_player,0);
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  if (DAT_8015e24c._2_2_ <= DAT_8015e272) {
    DAT_801c3360 = 0;
  }
  if ((DAT_8015e26f & 0x80) != 0) {
    DAT_801c3360 = 0;
  }
  if (DAT_8015e230 == 0) {
    DAT_801c3360 = 0;
  }
  *(byte *)(param_1 + 0x53) = DAT_801c3360 & 0x80;
  return *(undefined1 *)(param_1 + 0x53);
}


// ---- 801dd57c FUN_801dd57c

undefined4 FUN_801dd57c(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x50) == '\x04') {
    if (*(char *)(param_1 + 1) != '\x04') {
      FUN_8010544c(param_1,0x92);
    }
    uVar2 = 0x93;
    *(undefined1 *)(param_1 + 0x51) = 0x21;
    *(char *)(param_1 + 0x50) = *(char *)(param_1 + 0x50) + -1;
LAB_801dd5d4:
    FUN_8010544c(param_1,uVar2);
LAB_801dd5dc:
    uVar2 = 1;
  }
  else {
    if (-1 < *(char *)(param_1 + 0x50)) {
      bVar1 = *(byte *)(param_1 + 0x51);
      FUN_8010544c(param_1,0x92);
      if (bVar1 < 0x1b) {
        if (bVar1 < 5) {
          return 0;
        }
        bVar1 = *(char *)(param_1 + 0x50) - 1;
        *(byte *)(param_1 + 0x50) = bVar1;
        if (-1 < (int)((uint)bVar1 << 0x18)) {
          *(undefined1 *)(param_1 + 0x51) = 0x21;
          if (*(char *)(param_1 + 0x50) == '\0') {
            uVar2 = 0x94;
          }
          else {
            uVar2 = 0x93;
          }
          goto LAB_801dd5d4;
        }
        *(undefined1 *)(param_1 + 0x51) = 1;
        goto LAB_801dd5dc;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 801dd684 FUN_801dd684

void FUN_801dd684(int param_1,char *param_2)

{
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    if (*(char *)(param_1 + 0x50) == '\x04') {
      Anim_Set(param_2,8);
    }
    else {
      Anim_SetAtStep(param_2,9,(&DAT_801e6ea5)[*(char *)(param_1 + 0x50)]);
      param_2[0x31] = *(char *)(*(int *)(param_2 + 0x28) + 2) + '\x01';
    }
  }
  return;
}


// ---- 801dd714 FUN_801dd714

void FUN_801dd714(int param_1)

{
  if (*(int *)(param_1 + 0x18) < -0x5ffff) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


// ---- 801dd734 FUN_801dd734

void FUN_801dd734(int param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 7) & 0x10) == 0) {
    uVar1 = 0xfffec000;
  }
  else {
    uVar1 = 0x14000;
  }
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ---- 801dd76c FUN_801dd76c

undefined4 FUN_801dd76c(char *param_1)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  
  pcVar3 = &g_main_pool;
  iVar5 = 0;
  bVar1 = param_1[7];
  pbVar4 = (byte *)((int)&DAT_8015b178 + 3);
  while ((((iVar5 = iVar5 + 1, *pcVar3 == '\0' || (pbVar4[-1] != 0x1c)) || (pcVar3 == param_1)) ||
         (((*pbVar4 & 0xf) != (bVar1 & 0xf) ||
          (iVar2 = Obj_HitboxOverlap(param_1,pcVar3), iVar2 == 0))))) {
    pbVar4 = pbVar4 + 0x60;
    pcVar3 = pcVar3 + 0x60;
    if (0x3f < iVar5) {
      return 0;
    }
  }
  return 1;
}


