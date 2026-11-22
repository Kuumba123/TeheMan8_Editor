// ID 1B, STAGE0A.BIN, handler 0x801DC35C. Ghidra output with the object struct applied; not matching C.
// ---- 801dc35c FUN_801dc35c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc35c(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e1dbc)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
    iVar1 = Obj_InActiveArea(obj);
    if ((iVar1 == 0) && (iVar1 = FUN_80109430(obj,&g_player,0x140,0xf0), iVar1 == 0)) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801dc3f0 FUN_801dc3f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc3f0(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 5;
  obj->flip = 0;
  obj->hitbox = &DAT_801e1dcc;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x50 = 0;
  obj->field_0x52 = 0;
  obj->field_0x53 = 0;
  obj->state = obj->state + 1;
  Anim_Set(obj,0);
  return;
}


// ---- 801dc45c FUN_801dc45c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc45c(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (uint)obj->var * 6;
  if (obj->sub2 == 0) {
    Anim_Set(obj,0);
  }
  iVar3 = FUN_801dc8b8(obj);
  if (iVar3 != 0) goto LAB_801dc5a0;
  if (obj->field_0x53 != '\0') {
    FUN_801dca08(obj);
    goto LAB_801dc5a0;
  }
  iVar3 = (uint)DAT_8015e248._2_2_ - (uint)(ushort)obj->x;
                    /* Probable PsyQ macro: setTile16() */
  if ((&DAT_801e1de9)[iVar2] == '\0') {
    if (((char)(&DAT_801e1de7)[iVar2] != 0) &&
       ((int)(char)(&DAT_801e1de7)[iVar2] < iVar3 * 0x10000 >> 0x10)) {
      obj->field_0x53 = obj->field_0x53 | 1;
    }
    if (((char)(&DAT_801e1de8)[iVar2] != 0) &&
       ((int)(short)iVar3 < (int)(char)(&DAT_801e1de8)[iVar2])) {
      bVar1 = obj->field_0x53 | 2;
LAB_801dc588:
      obj->field_0x53 = bVar1;
    }
  }
  else {
                    /* Possible PsyQ macro: setPolyF3() */
    iVar3 = iVar3 * 0x10000 >> 0x10;
                    /* Possible PsyQ macro: setTile16() */
    if ((iVar3 <= (char)(&DAT_801e1de7)[iVar2]) && ((char)(&DAT_801e1de8)[iVar2] <= iVar3)) {
      bVar1 = obj->field_0x53 | 3;
      goto LAB_801dc588;
    }
  }
  if (obj->field_0x53 != '\0') {
    obj->field_0x50 = 1;
  }
LAB_801dc5a0:
  FUN_801dc988(obj);
  return;
}


// ---- 801dc5c0 FUN_801dc5c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc5c0(MM8Obj *obj)

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
  FUN_801dc914(obj);
  FUN_801dc988(obj);
  return;
}


// ---- 801dc64c FUN_801dc64c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc64c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e1df0)[obj->sub2])();
  if (4 < obj->sub2) {
    obj->state = 1;
    obj->sub2 = 0;
  }
  FUN_801dc988(obj);
  return;
}


// ---- 801dc6b8 FUN_801dc6b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc6b8(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  bVar1 = obj->sub3;
  if (bVar1 == 0) {
    uVar3 = 3;
LAB_801dc718:
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
        goto LAB_801dc764;
      }
      uVar3 = 1;
      goto LAB_801dc718;
    }
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 == 0) goto LAB_801dc764;
  }
  obj->sub3 = obj->sub3 + 1;
LAB_801dc764:
  FUN_801dc8b8(obj);
  return;
}


// ---- 801dc780 FUN_801dc780

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc780(MM8Obj *obj)

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
  FUN_801dc914();
  return;
}


// ---- 801dc7ec FUN_801dc7ec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc7ec(MM8Obj *obj)

{
  FUN_801dca84();
  FUN_801dc914(obj);
  obj->sub2 = obj->sub2 + 1;
  return;
}


// ---- 801dc82c FUN_801dc82c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dc82c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    Anim_Set(obj,2);
    obj->sub3 = obj->sub3 + 1;
  }
  if (obj->sub3 == 1) {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
                    /* Possible PsyQ macro: setLineF2() */
      obj->sub3 = 0;
      obj->sub2 = obj->sub2 + 1;
    }
  }
  FUN_801dc8b8(obj);
  return;
}


// ---- 801dc8b8 FUN_801dc8b8

undefined4 FUN_801dc8b8(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_801dc914();
  uVar2 = 0;
  if ((cVar1 == '\x03') && (uVar2 = 0, DAT_80158f5c == '\v')) {
    uVar2 = 1;
    *(undefined1 *)(param_1 + 1) = 2;
    *(undefined1 *)(param_1 + 2) = 0;
  }
  return uVar2;
}


// ---- 801dc914 FUN_801dc914

undefined1 FUN_801dc914(int param_1)

{
  undefined1 uVar1;
  undefined *puVar2;
  ushort uVar3;
  
  uVar3 = *(ushort *)(param_1 + 0x2e) & 0x7fff;
                    /* Probable PsyQ macro: setTile16() */
  if (1 < uVar3) {
    if (uVar3 == 2) {
      puVar2 = &DAT_801e1dd4;
      goto switchD_801dc924_caseD_3;
    }
    if (uVar3 == 3) {
      puVar2 = &DAT_801e1ddc;
      goto switchD_801dc924_caseD_3;
    }
  }
  puVar2 = &DAT_801e1dcc;
switchD_801dc924_caseD_3:
  *(undefined **)(param_1 + 0x3c) = puVar2;
  uVar1 = Enemy_CheckWeaponHits();
  return uVar1;
}


// ---- 801dc988 FUN_801dc988

undefined1 FUN_801dc988(int param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)(param_1 + 0x2e) & 0x7fff;
  if (1 < uVar2) {
    if (uVar2 == 2) {
      *(undefined **)(param_1 + 0x38) = &DAT_801e1dd4;
      goto LAB_801dc9e4;
    }
    if (uVar2 == 3) {
      *(undefined **)(param_1 + 0x38) = &DAT_801e1ddc;
      goto LAB_801dc9e4;
    }
  }
  *(undefined **)(param_1 + 0x38) = &DAT_801e1dcc;
LAB_801dc9e4:
  uVar1 = FUN_80107bf4(param_1,&g_player,1);
  return uVar1;
}


// ---- 801dca08 FUN_801dca08

undefined4 FUN_801dca08(int param_1)

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
      uVar1 = (&DAT_801e1de6)[(uint)*(byte *)(param_1 + 7) * 6];
      *(undefined1 *)(param_1 + 1) = 3;
      *(undefined1 *)(param_1 + 2) = 0;
      *(undefined1 *)(param_1 + 3) = 0;
      *(undefined1 *)(param_1 + 0x50) = uVar1;
    }
  }
  return uVar3;
}


// ---- 801dca84 FUN_801dca84

undefined1 * FUN_801dca84(int param_1)

{
  undefined1 *puVar1;
  
                    /* Probable PsyQ macro: setPolyGT4() */
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
                    /* Probable PsyQ macro: setLineF2() */
    puVar1[6] = (&DAT_801e1de4)[(uint)*(byte *)(param_1 + 7) * 6];
                    /* Possible PsyQ macro: setLineF2() */
    puVar1[7] = (&DAT_801e1de5)[(uint)*(byte *)(param_1 + 7) * 6];
    *(undefined2 *)(puVar1 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    *(short *)(puVar1 + 0x12) = *(short *)(param_1 + 0x12) + 2;
  }
  return puVar1;
}


// ---- 801dcb7c FUN_801dcb7c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcb7c(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  bVar1 = obj->var;
  cVar2 = (&DAT_801e1e38)[bVar1];
  Enemy_InitFromTable();
  obj->draw_list = 9;
  obj->field_0x43 = 1;
  iVar3 = (uint)bVar1 * 3;
  obj->hp = (&DAT_801e1e40)[iVar3];
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->contact_dmg = (&DAT_801e1e41)[iVar3];
  obj->dmg_table = (&DAT_801e1e42)[iVar3];
  if (cVar2 != -1) {
    Anim_Set(obj);
  }
  obj->state = bVar1 + 1;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  return;
}


// ---- 801dcc54 FUN_801dcc54

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcc54(MM8Obj *obj)

{
  obj->field_0x51 = obj->field_0x51 & 0x3f;
  obj->field_0x59 = obj->field_0x59 & 0x3f;
  obj->field_0x58 = obj->field_0x58 & 0x3f;
  obj->field_0x5b = obj->field_0x5b & 0x3f;
  obj->field_0x5a = obj->field_0x5a & 0x3f;
  if ((obj->sub2 != 7) && ((obj->field_0x53 & 0x40) != 0)) {
    obj->sub2 = 7;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  (*(code *)(&PTR_FUN_801e1e80)[obj->sub2])();
  return;
}


// ---- 801dccfc FUN_801dccfc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dccfc(MM8Obj *obj)

{
  obj->hitbox = (byte *)0x0;
  obj->box2 = (byte *)0x0;
  obj->field_0x50 = 0;
  obj->field_0x51 = 0;
  obj->field_0x53 = 0;
  obj->field_0x5d = 3;
  obj->field_0x54 = 4;
  obj->field_0x55 = 3;
  obj->field_0x56 = 1;
  obj->field_0x57 = 4;
  obj->field_0x5c = 0;
  FUN_801df540();
  FUN_801df3ac(obj,4,0);
  FUN_801df3ac(obj,3,1);
  FUN_801df3ac(obj,1,2);
  FUN_801df3ac(obj,4,3);
  FUN_801dfc2c();
  obj->sub2 = 1;
  obj->sub3 = 0;
  return;
}


// ---- 801dcdb4 FUN_801dcdb4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcdb4(MM8Obj *obj)

{
  if ((obj->sub3 == 0) && (DAT_801b299e == '\0')) {
    FUN_800fcb80(0x36);
    obj->sub2 = 2;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801dce14 FUN_801dce14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dce14(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  
  switch(obj->sub3) {
  case 0:
    obj->field_0x5d = 2;
    obj->field_0x51 = 0x83;
    FUN_801df540(obj);
    bVar1 = obj->sub3;
    uVar3 = 0x78;
    break;
  case 1:
    iVar4 = FUN_801df4ac(obj);
    if (iVar4 == 0) {
      return;
    }
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 != '\0') {
      return;
    }
    obj->field_0x51 = 0x47;
    obj->field_0x5a = 0x47;
    obj->field_0x53 = obj->field_0x53 | 0x10;
    goto LAB_801dcf08;
  case 2:
    iVar4 = FUN_801df4ac(obj);
    if (iVar4 == 0) {
      return;
    }
    if (DAT_801cf53c != '\0') {
      return;
    }
    uVar3 = 0x88;
    goto LAB_801dcf04;
  case 3:
    iVar4 = FUN_801df4ac(obj);
    if (iVar4 == 0) {
      return;
    }
    uVar3 = 0x82;
LAB_801dcf04:
    obj->field_0x51 = uVar3;
LAB_801dcf08:
    FUN_801df540(obj);
    obj->field_0x4 = 0;
    obj->sub3 = obj->sub3 + 1;
    return;
  case 4:
    iVar4 = FUN_801df4ac(obj);
    if (iVar4 == 0) {
      return;
    }
    DAT_801b2992 = 0;
    FUN_800fcb80(0x37);
    bVar1 = obj->sub3;
    uVar3 = 0xf;
    break;
  case 5:
                    /* Possible PsyQ macro: setPolyGT4() */
    if (((obj->field_0x50 == '\0') ||
        (obj->field_0x50 = obj->field_0x50 + -1, obj->field_0x50 == '\0')) && (DAT_801cf53c == '\0')
       ) {
      FUN_801dfc50();
      FUN_80111918();
      obj->field_0x5d = 1;
      obj->sub2 = 5;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      FUN_801df540();
    }
  default:
    goto switchD_801dce50_default;
  }
  obj->field_0x50 = uVar3;
  obj->field_0x4 = 0;
  obj->sub3 = bVar1 + 1;
switchD_801dce50_default:
                    /* Possible PsyQ macro: setTile8() */
  return;
}


// ---- 801dcfec FUN_801dcfec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dcfec(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  if (obj->sub3 == 0) {
    obj->field_0x51 = 0x83;
    FUN_800fd100(0x1aa);
    FUN_801df540(obj);
    bVar1 = obj->sub3;
  }
  else {
    if (obj->sub3 != 1) {
      cVar2 = obj->field_0x50 + -1;
      obj->field_0x50 = cVar2;
      if (cVar2 != '\0') {
        return;
      }
      obj->sub2 = 4;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      return;
    }
    iVar3 = FUN_801df4ac(obj);
    if (iVar3 == 0) {
      return;
    }
    obj->field_0x51 = 0x82;
    FUN_801df540(obj);
    bVar1 = obj->sub3;
    obj->field_0x50 = 0x46;
  }
  obj->sub3 = bVar1 + 1;
  return;
}


// ---- 801dd0a8 FUN_801dd0a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd0a8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
                    /* Possible PsyQ macro: setPolyFT3() + setShadeTex(polyFT3, 1) */
  bVar1 = obj->sub3;
  if (bVar1 == 0) {
    if (obj->field_0x4 == '\0') {
      obj->field_0x53 = obj->field_0x53 & 0xc3;
    }
    obj->field_0x51 = 0x47;
    FUN_801df540(obj);
    bVar1 = FUN_801dfa94(obj);
    if (bVar1 == 0xff) {
      obj->sub3 = 2;
      obj->field_0x52 = 0xf;
    }
    (&obj->field_0x58)[bVar1] = 0x47;
    obj->field_0x50 = 0x20;
    obj->sub3 = 1;
    bVar1 = obj->field_0x53 | (byte)(1 << (bVar1 + 2 & 0x1f));
  }
  else {
    if (bVar1 == 1) {
      cVar2 = obj->field_0x50 + -1;
      obj->field_0x50 = cVar2;
      if (cVar2 != '\0') {
        return;
      }
      if ((obj->field_0x53 & 0x3c) != 0x3c) {
        obj->field_0x4 = 1;
        obj->sub3 = 0;
        return;
      }
      obj->sub3 = 2;
      return;
    }
    if (bVar1 != 2) {
      return;
    }
    iVar3 = FUN_801df4ac(obj);
    if (iVar3 == 0) {
      return;
    }
    obj->sub2 = 5;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
    bVar1 = obj->field_0x53 & 0xc3;
  }
  obj->field_0x53 = bVar1;
  return;
}


// ---- 801dd1fc FUN_801dd1fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd1fc(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  
  sVar1 = DAT_801d292c;
  if (obj->sub3 == 0) {
    obj->speed_y_up = 0x40000;
    obj->field_0x51 = 0x85;
    obj->y = sVar1 + 0xf0;
    FUN_801df540();
                    /* Possible PsyQ macro: setPolyGT3() */
    obj->sub3 = 1;
  }
  else {
    iVar2 = FUN_801df4ac(obj);
    if (iVar2 != 0) {
      obj->sub2 = 6;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      return;
    }
  }
  FUN_80104c34(obj);
  return;
}


// ---- 801dd28c FUN_801dd28c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd28c(MM8Obj *obj)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  
                    /* Possible PsyQ macro: setLineF2() */
  bVar1 = obj->sub3;
  if (bVar1 == 0) {
    FUN_800fd100(0x1ab);
    uVar2 = 0x89;
  }
  else {
    if (bVar1 == 1) {
      iVar4 = FUN_801df4ac(obj);
      if (iVar4 == 0) {
        return;
      }
      iVar4 = Rand();
      obj->sub3 = obj->sub3 + 1;
      obj->field_0x50 =
           ((char)iVar4 +
           ((char)((ulonglong)((longlong)iVar4 * 0x55555556) >> 0x20) - (char)(iVar4 >> 0x1f)) * -3)
           * '\x1e' + 'Z';
      return;
    }
    if (bVar1 != 2) {
      if (bVar1 != 3) {
        return;
      }
      iVar4 = FUN_801df4ac(obj);
      if (iVar4 == 0) {
        return;
      }
      obj->sub2 = 3;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      return;
    }
                    /* Possible PsyQ macro: setLineF2() */
    cVar3 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar3;
    if (cVar3 != '\0') {
      return;
    }
    FUN_800fd100(0x1ab);
    FUN_801df740(obj);
    uVar2 = 0x80;
  }
  obj->field_0x51 = uVar2;
  FUN_801df540(obj);
  obj->sub3 = obj->sub3 + 1;
  return;
}


// ---- 801dd3bc FUN_801dd3bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd3bc(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    FUN_801dfc2c();
    FUN_800fcd84();
    FUN_801119e0((int)DAT_8015e248._2_2_,DAT_8015e261);
    obj->field_0x51 = 0x8a;
    FUN_801df540(obj);
    obj->sub3 = obj->sub3 + 1;
  }
  else {
                    /* Possible PsyQ macro: setLineF2() */
    if ((obj->sub3 == 1) && (iVar1 = FUN_801df4ac(obj), iVar1 != 0)) {
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801dd45c caseD_0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801dd454::caseD_0(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = *(int *)&obj->field_0x4c;
  FUN_801df584();
  (*(code *)(&PTR_FUN_801e1ea0)[obj->sub2])(obj);
  if (obj->active != 0) {
    if (obj->field_0x53 == '\0') {
      cVar1 = FUN_801df994(obj);
      if ((cVar1 != '\0') && (cVar1 == '\x02')) {
        FUN_8010544c(obj,0x10);
        obj->field_0x53 = 0x28;
      }
    }
    else {
      bVar2 = obj->hp;
      obj->hp = 0x28;
      cVar1 = FUN_801df994(obj);
      obj->field_0x53 = obj->field_0x53 + -1;
      obj->hp = bVar2;
      if ((cVar1 != '\0') && (cVar1 != -0x7f)) {
        FUN_8010544c(obj,0x4f);
        cVar1 = '\x02';
      }
    }
    if (cVar1 == '\x04') {
      *(byte *)(iVar3 + 0x53) = *(byte *)(iVar3 + 0x53) | 0x40;
      DAT_8015e2af = 1;
      obj->field_0x54 = 0;
    }
    else {
                    /* Possible PsyQ macro: setPolyF3() */
      Enemy_ContactDamage(obj);
      if ((obj->field_0x53 != '\0') && ((DAT_80170574 & 1) != 0)) {
        obj->clut = 0;
      }
      if ((*(byte *)(iVar3 + 0x53) & 0x40) == 0) {
        Obj_CullAndQueueDraw(obj);
      }
      if ((cVar1 == '\x02') && (obj->sub2 < 0xb)) {
        obj->sub2 = 0xc;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
      }
    }
    if (((*(byte *)(iVar3 + 0x53) & 0x40) != 0) && (obj->field_0x5e != '\0')) {
      Obj_CullAndQueueDraw(obj);
    }
    if (obj->hp < 0x1e) {
      if (obj->hp < 0xc) {
        bVar2 = *(byte *)(iVar3 + 0x53) | 3;
      }
      else {
        bVar2 = *(byte *)(iVar3 + 0x53) & 0xfd | 1;
      }
    }
    else {
      bVar2 = *(byte *)(iVar3 + 0x53) & 0xfc;
    }
    *(byte *)(iVar3 + 0x53) = bVar2;
  }
  return;
}


// ---- 801dd694 FUN_801dd694

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd694(MM8Obj *obj)

{
  obj->hitbox = &DAT_801e1e20;
  obj->box2 = &DAT_801e1e20;
  obj->field_0x50 = 0;
  obj->field_0x53 = 0;
  obj->field_0x54 = 0;
  obj->field_0x5e = 0;
  obj->sub2 = 1;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  FUN_801df50c();
  FUN_801e14e0(obj,0);
  return;
}


// ---- 801dd6f8 FUN_801dd6f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd6f8(MM8Obj *obj)

{
  if (obj->field_0x50 == '\0') {
    FUN_801df50c();
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  return;
}


// ---- 801dd73c FUN_801dd73c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd73c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    Anim_Set(obj,0x1a);
    obj->sub3 = obj->sub3 + 1;
  }
  else {
    Anim_Step(obj);
    iVar1 = Anim_AtLoopMarker(obj);
    if (iVar1 != 0) {
      FUN_801df50c(obj);
      obj->sub2 = 1;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801dd7b8 FUN_801dd7b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd7b8(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    obj->speed_y_up = -0x20000;
    obj->sub3 = obj->sub3 + 1;
  }
                    /* Possible PsyQ macro: setPolyGT4() */
  if ((int)obj->y < DAT_801d292c + 0x38) {
    FUN_80104c34(obj);
  }
  else {
    FUN_801df50c(obj);
    iVar1 = (int)DAT_801d292c;
    obj->speed_y_up = 0;
    obj->sub2 = 1;
    obj->sub3 = 0;
    *(int *)&obj->y_frac = (iVar1 + 0x38) * 0x10000;
  }
                    /* Possible PsyQ macro: setTile8() */
  return;
}


// ---- 801dd85c FUN_801dd85c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd85c(MM8Obj *obj)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined1 *puVar5;
  
  bVar3 = obj->sub3;
  if (bVar3 == 0) {
    bVar3 = obj->sub3;
                    /* Possible PsyQ macro: setPolyF3() */
    obj->field_0x50 = 0x20;
  }
  else {
    if (bVar3 == 1) {
      cVar2 = obj->field_0x50 + -1;
      obj->field_0x50 = cVar2;
      if (cVar2 != '\0') goto LAB_801dd914;
    }
    else {
      if (bVar3 != 2) {
        if (bVar3 == 3) {
          Anim_Step(obj);
          iVar4 = Anim_AtLoopMarker(obj);
          if (iVar4 != 0) {
            obj->sub2 = 6;
            obj->sub3 = 0;
          }
        }
        goto LAB_801dd914;
      }
      Anim_Set(obj,0xf);
      FUN_8010544c(obj,0x1ac);
    }
    bVar3 = obj->sub3;
  }
  obj->sub3 = bVar3 + 1;
LAB_801dd914:
  if ((obj->anim_extra != 0) &&
     (puVar5 = (undefined1 *)FUN_801055e4(obj), puVar5 != (undefined1 *)0x0)) {
    *puVar5 = 1;
    puVar5[6] = 0x52;
    puVar5[7] = 0;
    *(short *)(puVar5 + 0xe) = obj->x;
    sVar1 = obj->y;
    puVar5[0x25] = 0;
    *(short *)(puVar5 + 0x12) = sVar1 + 8;
  }
  return;
}


// ---- 801dd978 FUN_801dd978

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd978(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  sVar1 = *(short *)(*(int *)&obj->field_0x4c + 0x12);
  sVar2 = *(short *)(&DAT_801e1e56 + (uint)(byte)obj->field_0x51 * 4);
  if (sVar1 <= obj->y) {
    obj->y = sVar1;
  }
  if ((int)obj->y <= (int)sVar2) {
    FUN_801df50c(obj);
    iVar3 = (int)sVar2 << 0x10;
    obj->y_frac = (short)iVar3;
    obj->y = (short)((uint)iVar3 >> 0x10);
    obj->speed_y_up = 0;
    obj->sub2 = 1;
    obj->sub3 = 0;
  }
  return;
}


// ---- 801dda0c FUN_801dda0c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dda0c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    Anim_Set(obj,0);
    obj->speed_y_up = 0x40000;
    obj->sub3 = obj->sub3 + 1;
  }
  if (DAT_801d292c + 0x38 < (int)obj->y) {
    FUN_80104c34(obj);
  }
  else {
    FUN_801df50c(obj);
    iVar1 = (int)DAT_801d292c;
    obj->speed_y_up = 0;
    obj->sub2 = 1;
    obj->sub3 = 0;
    *(int *)&obj->y_frac = (iVar1 + 0x38) * 0x10000;
  }
  return;
}


// ---- 801ddca8 FUN_801ddca8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddca8(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = obj->sub3;
  if (bVar1 == 0) {
    obj->field_0x5e = 1;
    obj->dmg_table = 3;
    obj->hp = 0;
    obj->field_0x53 = 0x1e;
    obj->field_0x50 = 0x1e;
    obj->sub3 = obj->sub3 + 1;
    Obj_CullAndQueueDraw();
  }
  else if (bVar1 == 1) {
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 == '\0') {
      Anim_Set(obj,0x10);
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
      obj->field_0x50 = 0x5a;
      obj->sub3 = obj->sub3 + 1;
    }
    Obj_CullAndQueueDraw(obj);
  }
  else if (bVar1 == 2) {
    Anim_Step(obj);
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 == '\0') {
      obj->field_0x5e = 0;
      obj->field_0x50 = 0xf0;
      obj->field_0x4 = 0;
      obj->sub3 = obj->sub3 + 1;
    }
    else if ((uint)(byte)obj->field_0x50 % 6 == 0) {
      FUN_80108ed8(obj,((uint)((byte)obj->field_0x50 >> 2) % 3) * 0x14 + -0xc,0xffffffec);
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
      FUN_80108ed8(obj,(2 - (uint)((byte)obj->field_0x50 >> 2) % 3) * 0x14 + -0x1c,0x14);
    }
  }
  else if (bVar1 == 3) {
    obj->sub2 = 0xd;
    obj->sub3 = 0;
    obj->field_0x4 = 0;
  }
  return;
}


// ---- 801dde8c FUN_801dde8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dde8c(MM8Obj *obj)

{
  int iVar1;
  
  iVar1 = *(int *)&obj->field_0x4c;
  FUN_8010995c();
  if (obj->active == 0) {
    FUN_801df50c(obj);
    *(undefined1 *)(iVar1 + 0x52) = 0xf;
    *(undefined1 *)(iVar1 + 0x53) = 0xff;
  }
  return;
}


// ---- 801ddeec FUN_801ddeec

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddeec(MM8Obj *obj)

{
  if (obj->sub3 == 0) {
    FUN_800fd100(0x13e);
    DAT_801b297c = obj;
    obj->hp = 0;
    obj->sub3 = obj->sub3 + 1;
  }
  else {
    obj->hp = obj->hp + ((byte)DAT_80170574 & 1);
    if (0x27 < obj->hp) {
      FUN_801df50c(obj);
                    /* Possible PsyQ macro: setPolyGT4() */
                    /* Possible PsyQ macro: setPolyF4() */
      obj->hp = 0x28;
      obj->sub2 = 1;
      obj->sub3 = 0;
    }
  }
  return;
}


// ---- 801ddf8c FUN_801ddf8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddf8c(MM8Obj *obj)

{
  FUN_801df50c();
  FUN_801df69c(obj);
  return;
}


// ---- 801ddfdc FUN_801ddfdc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ddfdc(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  if (obj->sub3 == 0) {
    Anim_Set(obj,0x10);
    FUN_801df548(obj);
    obj->field_0x54 = 1;
    bVar1 = obj->sub3;
    obj->speed_y_up = 0x40000;
  }
  else {
    if (obj->sub3 != 1) {
      Anim_Step(obj);
      if (obj->y <= *(short *)(&DAT_801e1e56 + (uint)(byte)obj->field_0x51 * 4)) {
        Anim_Set(obj,0);
        obj->y = *(short *)(&DAT_801e1e56 + (uint)(byte)obj->field_0x51 * 4);
        FUN_801df50c(obj);
        obj->sub2 = 1;
        obj->sub3 = 0;
      }
      goto LAB_801de0c0;
    }
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    if (iVar2 == 0) goto LAB_801de0c0;
    bVar1 = obj->sub3;
  }
  obj->sub3 = bVar1 + 1;
LAB_801de0c0:
  FUN_80104c34(obj);
  return;
}


// ---- 801de0dc FUN_801de0dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de0dc(MM8Obj *obj)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar2 = 4;
  if ((*(byte *)(*(int *)&obj->field_0x4c + 0x5d) & 1) != 0) {
LAB_801de1d4:
    obj->sub2 = bVar2;
    obj->sub3 = 0;
    return;
  }
  switch(obj->sub3) {
  case 0:
    uVar4 = 0x20;
    goto LAB_801de1a0;
  case 1:
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    if (iVar3 == 0) {
      return;
    }
    bVar2 = obj->sub3;
    obj->field_0x50 = 0x10;
    goto code_r0x801de1b0;
  case 2:
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
                    /* Possible PsyQ macro: setLineF2() */
    if (cVar1 != '\0') {
      return;
    }
    break;
  case 3:
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    if (iVar3 == 0) {
      return;
    }
    break;
  case 4:
    Anim_Step(obj);
    iVar3 = Anim_AtLoopMarker(obj);
    bVar2 = 1;
    if (iVar3 == 0) {
      return;
    }
    goto LAB_801de1d4;
  default:
    goto switchD_801de128_default;
  }
  uVar4 = 0xf;
LAB_801de1a0:
  Anim_Set(obj,uVar4);
  bVar2 = obj->sub3;
code_r0x801de1b0:
  obj->sub3 = bVar2 + 1;
switchD_801de128_default:
  return;
}


// ---- 801de1f0 FUN_801de1f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de1f0(MM8Obj *obj)

{
  FUN_801df584();
  (*(code *)(&PTR_FUN_801e1ed8)[obj->sub2])(obj);
  if (obj->active != 0) {
    FUN_801df994(obj);
    Enemy_ContactDamage(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801de264 FUN_801de264

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de264(MM8Obj *obj)

{
  obj->hitbox = &DAT_801e1e20;
  obj->box2 = &DAT_801e1e20;
  obj->field_0x50 = 0;
  obj->field_0x53 = 0;
  obj->field_0x54 = 0;
  obj->sub2 = 1;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  FUN_801df50c();
  FUN_801e14e0(obj,0);
  return;
}


// ---- 801de2c4 FUN_801de2c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de2c4(MM8Obj *obj)

{
  if (obj->field_0x50 == '\0') {
    FUN_801df50c();
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  return;
}


// ---- 801de770 FUN_801de770

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de770(MM8Obj *obj)

{
  char cVar1;
  
  FUN_801df584();
  (*(code *)(&PTR_FUN_801e1f10)[obj->sub2])(obj);
  if ((obj->active != 0) && (cVar1 = FUN_801df994(obj), cVar1 != '\x04')) {
    Enemy_ContactDamage(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801de7f8 FUN_801de7f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de7f8(MM8Obj *obj)

{
  obj->hitbox = &DAT_801e1e28;
  obj->box2 = &DAT_801e1e28;
  obj->field_0x50 = 0;
  obj->field_0x53 = 0;
  obj->field_0x54 = 0;
  obj->sub2 = 1;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  FUN_801df50c();
  FUN_801e14e0(obj,0);
  return;
}


// ---- 801de858 FUN_801de858

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de858(MM8Obj *obj)

{
  if (obj->field_0x50 == '\0') {
    FUN_801df50c();
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
  return;
}


// ---- 801ded00 FUN_801ded00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801ded00(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->var == 4) {
    obj->clut = obj->clut + 4;
  }
  obj->field_0x57 = 0;
  FUN_801df584(obj);
                    /* Possible PsyQ macro: setPolyF4() */
  (*(code *)(&PTR_FUN_801e1f48)[obj->sub2])(obj);
                    /* Probable PsyQ macro: setTile() */
  if ((obj->active != 0) && (cVar1 = FUN_801df994(obj), cVar1 != '\x04')) {
    Enemy_ContactDamage(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801dedb0 FUN_801dedb0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dedb0(MM8Obj *obj)

{
  obj->hitbox = &DAT_801e1e30;
  obj->box2 = &DAT_801e1e30;
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->field_0x50 = 0;
  obj->field_0x53 = 0;
  obj->field_0x54 = 0;
  obj->sub2 = 1;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  FUN_801df50c();
  FUN_801e14e0(obj,0);
  if (obj->var == 4) {
    FUN_801e14e0(obj,1);
    obj->clut = obj->clut + 4;
  }
  else {
                    /* Probable PsyQ macro: setTile16() */
    FUN_801e14e0(obj,2);
  }
  return;
}


// ---- 801dee44 FUN_801dee44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dee44(MM8Obj *obj)

{
  if (obj->field_0x50 == '\0') {
    FUN_801df50c();
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
  }
                    /* Possible PsyQ macro: setLineF2() */
  return;
}


// ---- 801df3ac FUN_801df3ac

undefined1 * FUN_801df3ac(int param_1,char param_2,byte param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)0x0;
  if ((param_2 != '\0') &&
     (puVar3 = (undefined1 *)FUN_801055e4(param_1), puVar3 != (undefined1 *)0x0)) {
    *puVar3 = 1;
    puVar3[6] = 0x51;
    puVar3[7] = param_2;
    *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)(&DAT_801e1e54 + (uint)param_3 * 4);
    uVar2 = *(undefined2 *)(&DAT_801e1e56 + (uint)param_3 * 4);
    puVar3[0x51] = param_3;
    *(int *)(puVar3 + 0x4c) = param_1;
    *(undefined2 *)(puVar3 + 0x12) = uVar2;
    uVar1 = *(undefined1 *)(param_1 + 0x5c);
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[0x55] = uVar1;
    *(char *)(param_1 + 0x5c) = *(char *)(param_1 + 0x5c) + '\x01';
  }
  return puVar3;
}


// ---- 801df478 FUN_801df478

void FUN_801df478(int param_1)

{
  int iVar1;
  
  iVar1 = (uint)*(byte *)(param_1 + 0x51) * 4;
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(&DAT_801e1e54 + iVar1);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(&DAT_801e1e56 + iVar1);
  return;
}


// ---- 801df4ac FUN_801df4ac

/* Possible GS_106.OBJ/GsSetProjection
   Possible _OP_VDEL.OBJ/__builtin_vec_delete
   Possible _OP_VNEW.OBJ/__builtin_vec_new
   Possible SCNOFF.OBJ/SsSetNoiseOff
   Possible SSQUIT.OBJ/SsQuit */

bool FUN_801df4ac(int param_1)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = 0;
  pcVar2 = (char *)(param_1 + 0x54);
  do {
    uVar3 = uVar3 & 0xff;
    if (*pcVar2 == -1) {
      uVar3 = uVar3 | 1 << (uVar1 & 0x1f);
    }
    uVar1 = uVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while ((int)uVar1 < 4);
  return (uVar3 & 0xff | *(byte *)(param_1 + 0x52) & 0xf) == 0xf;
}


// ---- 801df50c FUN_801df50c

void FUN_801df50c(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 0x4c);
  if (*pcVar1 != '\0') {
    pcVar1[0x52] = pcVar1[0x52] | (byte)(1 << (*(byte *)(param_1 + 0x51) & 0x1f));
  }
  return;
}


// ---- 801df540 FUN_801df540

void FUN_801df540(int param_1)

{
  *(undefined1 *)(param_1 + 0x52) = 0;
  return;
}


// ---- 801df548 FUN_801df548

void FUN_801df548(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 0x4c);
  if (*pcVar1 != '\0') {
    pcVar1[0x52] = pcVar1[0x52] & ~(byte)(1 << (*(byte *)(param_1 + 0x51) & 0x1f));
  }
  return;
}


// ---- 801df584 FUN_801df584

void FUN_801df584(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  
  pcVar5 = *(char **)(param_1 + 0x4c);
  bVar1 = *(byte *)(param_1 + 2);
  bVar2 = pcVar5[0x51];
  if (bVar1 == 0) {
    return;
  }
  if (*pcVar5 == '\0') {
    return;
  }
  if ((bVar2 & 0x80) == 0) {
    if ((bVar2 & 0x40) == 0) {
      return;
    }
    bVar2 = pcVar5[*(byte *)(param_1 + 0x51) + 0x58];
    if ((bVar2 & 0x40) == 0) {
      return;
    }
    if (10 < bVar1) {
      return;
    }
    cVar3 = *(char *)(param_1 + 0x54);
  }
  else {
    if (10 < bVar1) {
      return;
    }
    cVar3 = *(char *)(param_1 + 0x54);
  }
  uVar4 = bVar2 & 0x3f;
  if (cVar3 != '\0') {
    if ((uVar4 != 9) && (uVar4 != 10)) {
      return;
    }
    *(undefined1 *)(param_1 + 0x54) = 0;
  }
  if (*(int *)(uVar4 * 4 + *(int *)(&DAT_801e1f80 + (uint)*(byte *)(param_1 + 7) * 4)) != 0) {
    *(char *)(param_1 + 2) = (char)uVar4;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
  }
  return;
}


// ---- 801df69c FUN_801df69c

void FUN_801df69c(int param_1)

{
  byte bVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x4c);
  if (*pcVar2 != '\0') {
    pcVar2[*(byte *)(param_1 + 0x51) + 0x54] = -1;
    if (*(char *)(param_1 + 7) == '\x01') {
      bVar1 = Rand();
                    /* Possible PsyQ macro: setPolyGT3() */
      *(byte *)(param_1 + 0x51) = bVar1 & 3;
      pcVar2[*(byte *)(param_1 + 0x51) + 0x54] = '\x01';
      FUN_801df478(param_1);
    }
    else {
      FUN_801dfa74(param_1);
      Obj_Free(param_1);
    }
  }
  return;
}


// ---- 801df740 FUN_801df740

void FUN_801df740(int param_1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  char cVar7;
  char *pcVar8;
  char *pcVar9;
  
  pcVar9 = (char *)(param_1 + 0x54);
  bVar1 = false;
  bVar2 = false;
  cVar7 = '\0';
  cVar6 = '\0';
  iVar4 = 0;
  pcVar8 = pcVar9;
  do {
    if (*pcVar8 == '\x01') goto LAB_801df868;
    cVar3 = FUN_801df8f4(param_1);
    if (cVar3 == '\x03') {
      if (bVar2) goto LAB_801df860;
      bVar2 = true;
LAB_801df864:
      *pcVar8 = cVar3;
    }
    else if (cVar3 < '\x04') {
      if (cVar3 == '\x02') {
        if (!bVar1) {
          bVar1 = true;
          goto LAB_801df864;
        }
LAB_801df860:
        iVar4 = iVar4 + -1;
        goto LAB_801df864;
      }
      *pcVar8 = cVar3;
    }
    else {
      if (cVar3 == '\x04') goto LAB_801df810;
                    /* Possible PsyQ macro: setLineG3() + setSemiTrans(lineG3, 1) */
      if (cVar3 == '\x05') {
        while (cVar6 < '\x02') {
          if (cVar7 == '\0') {
            cVar6 = cVar6 + '\x01';
            goto LAB_801df864;
          }
          cVar3 = '\x04';
LAB_801df810:
          if ('\x01' < cVar7) break;
          if (cVar6 == '\0') {
            cVar7 = cVar7 + '\x01';
            goto LAB_801df864;
          }
          cVar3 = '\x05';
        }
        goto LAB_801df860;
      }
      *pcVar8 = cVar3;
    }
LAB_801df868:
    iVar4 = iVar4 + 1;
    pcVar8 = pcVar9 + iVar4;
    if (3 < iVar4) {
      uVar5 = 0;
      do {
        if (*pcVar9 != '\x01') {
          FUN_801df3ac(param_1,*pcVar9,uVar5 & 0xff);
        }
        uVar5 = uVar5 + 1;
        pcVar9 = pcVar9 + 1;
      } while ((int)uVar5 < 4);
      *(undefined1 *)(param_1 + 0x52) = 0;
      *(byte *)(param_1 + 0x53) = *(byte *)(param_1 + 0x53) & 0xc3;
      return;
    }
  } while( true );
}


// ---- 801df8f4 FUN_801df8f4

int FUN_801df8f4(int param_1)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = Rand();
  uVar1 = uVar1 & 0xf;
  if ((*(byte *)(param_1 + 0x53) & 3) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 1;
    if ((*(byte *)(param_1 + 0x53) & 2) != 0) {
      iVar4 = 2;
    }
  }
  iVar3 = 0;
  pbVar2 = &DAT_801e1e64 + iVar4 * 6;
  do {
    uVar1 = uVar1 - *pbVar2;
    iVar4 = iVar3 << 0x18;
    if ((int)(uVar1 * 0x10000) < 0) goto LAB_801df97c;
    iVar3 = iVar3 + 1;
    pbVar2 = pbVar2 + 1;
  } while (iVar3 < 6);
  iVar4 = iVar3 * 0x1000000;
LAB_801df97c:
  return iVar4 >> 0x18;
}


// ---- 801df994 FUN_801df994

int FUN_801df994(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((DAT_801d292c + -0x18 <= (int)*(short *)(param_1 + 0x12)) &&
     (iVar2 = 0, (*(byte *)(*(int *)(param_1 + 0x4c) + 0x53) & 0x80) == 0)) {
    cVar1 = Enemy_CheckWeaponHits(param_1);
    if (cVar1 == '\x04') {
      FUN_801dfa74(param_1);
      *(undefined1 *)(param_1 + 2) = 0xb;
      *(undefined1 *)(param_1 + 3) = 0;
    }
    else if (cVar1 == '\x02') {
      *(undefined1 *)(param_1 + 0x24) = 0;
    }
    iVar2 = (int)cVar1;
  }
  return iVar2;
}


// ---- 801dfa74 FUN_801dfa74

void FUN_801dfa74(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x4c) + 0x5c);
  *(char *)(*(int *)(param_1 + 0x4c) + 0x5c) = cVar1 + '\x01';
  *(char *)(param_1 + 0x55) = cVar1;
  return;
}


// ---- 801dfa94 FUN_801dfa94

int FUN_801dfa94(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = 4;
  uVar7 = 0;
  uVar3 = 0;
  uVar5 = 2;
  pbVar6 = (byte *)(param_1 + 0x54);
  do {
                    /* Possible PsyQ macro: setPolyGT4() */
    if (*pbVar6 == 0xff) {
      *(byte *)(param_1 + 0x53) = *(byte *)(param_1 + 0x53) | (byte)(1 << (uVar5 & 0x1f));
    }
    else {
      if (((int)(uint)*(byte *)(param_1 + 0x53) >> (uVar5 & 0x1f) & 1U) == 0) {
        uVar7 = uVar7 | 1 << (uVar3 & 0x1f);
      }
      if (*pbVar6 - 1 < 2) {
        iVar8 = iVar8 + -1;
      }
    }
    uVar5 = uVar5 + 1;
    uVar3 = uVar3 + 1;
    pbVar6 = pbVar6 + 1;
  } while ((int)uVar3 < 4);
  uVar3 = uVar7 & 0xff;
  if (uVar3 != 0) {
    do {
      uVar5 = Rand();
      uVar5 = uVar5 & 0xf;
      uVar4 = 0;
      do {
        puVar1 = &DAT_801e1e78;
        if (iVar8 == 2) {
          puVar1 = &UNK_801e1e7c;
        }
        uVar5 = uVar5 - (byte)puVar1[uVar4];
      } while ((0 < (int)(uVar5 * 0x1000000)) && (uVar4 = uVar4 + 1, (int)uVar4 < 4));
    } while (((((int)uVar3 >> (uVar4 & 0x1f) & 1U) == 0) ||
             ((iVar2 = (int)(char)((byte *)(param_1 + 0x54))[uVar4], iVar2 == 1 &&
              ((uVar7 & ~(iVar2 << (uVar4 & 0x1f)) & 0xff) != 0)))) && (uVar3 != 0));
    if ((uVar7 & 0xff) != 0) {
      return (int)(char)uVar4;
    }
  }
  return -1;
}


// ---- 801dfc2c FUN_801dfc2c

void FUN_801dfc2c(void)

{
  DAT_801b2992 = 1;
  DAT_801b2993 = 1;
  DAT_801b2994 = 1;
  return;
}


// ---- 801dfc50 FUN_801dfc50

void FUN_801dfc50(void)

{
  DAT_801b2992 = 0;
  DAT_801b2993 = 0;
  DAT_801b2994 = 0;
  return;
}


// ---- 801e14e0 FUN_801e14e0

void FUN_801e14e0(int param_1,undefined1 param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)Obj_AllocType3();
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 1;
    puVar3[6] = 0x3b;
    puVar3[7] = param_2;
    *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)(param_1 + 0xe);
    uVar2 = *(undefined2 *)(param_1 + 0x12);
    puVar3[0x27] = 0x92;
    *(undefined2 *)(puVar3 + 0x12) = uVar2;
    puVar3[0x24] = DAT_80159ff6;
    uVar2 = DAT_8017046c;
    *(int *)(puVar3 + 0x14) = param_1;
    *(undefined2 *)(puVar3 + 0x2c) = uVar2;
    *(undefined4 *)(puVar3 + 0x18) = *(undefined4 *)(param_1 + 0x4c);
    puVar3[0x26] = *(undefined1 *)(param_1 + 0x26);
    puVar3[0x38] = *(undefined1 *)(param_1 + 6);
    puVar3[0x39] = *(undefined1 *)(param_1 + 7);
    uVar1 = *(undefined1 *)(param_1 + 0x55);
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[0x3a] = uVar1;
  }
  return;
}


