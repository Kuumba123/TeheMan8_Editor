// ID 0B, STAGE01.BIN, handler 0x801DB5AC. Ghidra output with the object struct applied; not matching C.
// ---- 801db5ac FUN_801db5ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db5ac(MM8Obj *obj)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (obj->state != 0) {
    if (((obj->var & 1) == 0) && (iVar2 = FUN_80109430(obj,&g_player,0x400,0x400), iVar2 == 0)) {
      return;
    }
    uVar3 = (uint)obj->state;
  }
  (*(code *)(&PTR_FUN_801e6860)[uVar3])(obj);
  sVar1 = obj->x;
  obj->x = CONCAT11(obj->field_0x52,obj->field_0x53);
  FUN_801dbc28(obj);
  FUN_801dbc70(obj);
  if (obj->state == 4) {
    FUN_801dbd10(obj);
  }
  FUN_801dbbc8(obj);
  obj->x = sVar1;
  Obj_CullAndQueueDraw(obj);
  iVar2 = Obj_InActiveArea(obj);
  if ((iVar2 == 0) && ((obj->var & 1) != 0)) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801db6b8 FUN_801db6b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db6b8(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->state = 1;
  obj->draw_list = 8;
  obj->flip = obj->var & 0x40;
  obj->sub2 = 0;
  obj->field_0x50 = 0;
  obj->field_0x51 = 0;
  obj->field_0x54 = 0;
  obj->field_0x5f = 0;
  obj->field_0x53 = (char)obj->x;
  obj->field_0x52 = (char)((ushort)obj->x >> 8);
  obj->var = obj->var & 1;
  (*(code *)(&PTR_FUN_801e6860)[obj->state])(obj);
  return;
}


// ---- 801db750 FUN_801db750

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db750(MM8Obj *obj)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (obj->sub2 == 0) {
    uVar4 = 0xc;
    if ((obj->var & 0xf) != 0) {
      uVar4 = 7;
    }
    Anim_Set(obj,uVar4);
    obj->sub2 = obj->sub2 + 1;
  }
  sVar2 = DAT_8015e272;
  sVar1 = DAT_8015e24c._2_2_;
  if ((obj->var & 0xf) == 0) {
    if (obj->field_0x54 != '\0') {
      obj->field_0x54 = 0;
      obj->state = 3;
      obj->sub2 = 0;
    }
  }
  else {
    obj->box2 = &DAT_801e6880;
    if (sVar2 < sVar1) {
      iVar3 = FUN_80107bf4(obj,&g_player,0);
      if ((iVar3 != 0) && (FUN_801082e0(obj,&g_player), (DAT_801c3360 & 0x80) != 0)) {
        obj->state = 2;
        obj->sub2 = 0;
        FUN_8010544c(obj,0x2b);
      }
    }
    else if (sVar1 == sVar2) {
      FUN_80107bf4(obj,&g_player,5);
    }
  }
  return;
}


// ---- 801db894 FUN_801db894

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db894(MM8Obj *obj)

{
  if (obj->sub2 == 0) {
    Anim_Set(obj,8);
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    if (((short)obj->frame < 0) && (obj->anim_timer == 1)) {
      obj->state = 3;
      obj->sub2 = 0;
    }
  }
  return;
}


// ---- 801db914 FUN_801db914

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db914(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,0xc);
    if ((obj->var & 1) == 0) {
      obj->state = 4;
      obj->sub2 = 0;
      return;
    }
    obj->field_0x50 = 0xc;
    obj->field_0x51 = 0;
    obj->sub2 = obj->sub2 + 1;
    FUN_8010544c(obj,0xfe);
  }
  else {
    cVar1 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar1;
    if (cVar1 == '\0') {
      obj->state = 4;
      obj->sub2 = 0;
    }
  }
  if ((&DAT_801e6878)[(byte)obj->field_0x51 >> 1] != '\x7f') {
    if ((obj->field_0x51 & 1) == 0) {
      obj->x = obj->x + (short)(char)(&DAT_801e6878)[(byte)obj->field_0x51 >> 1];
    }
    obj->field_0x51 = obj->field_0x51 + '\x01';
  }
  return;
}


// ---- 801dba18 FUN_801dba18

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dba18(MM8Obj *obj)

{
  undefined1 *puVar1;
  char cVar2;
  byte bVar3;
  
  if (obj->sub2 == 0) {
    Anim_Set(obj,9);
    obj->field_0x50 = 0x32;
    obj->sub2 = obj->sub2 + 1;
  }
  else {
    Anim_Step(obj);
    cVar2 = obj->field_0x50 + -1;
    obj->field_0x50 = cVar2;
    if (cVar2 == '\0') {
      bVar3 = 5;
      if ((obj->var & 1) == 0) {
        bVar3 = 1;
      }
      obj->state = bVar3;
      obj->sub2 = 0;
    }
  }
  if ((obj->frame == 0x17) && (obj->anim_timer == 1)) {
    DAT_801e70cc = (undefined1 *)Obj_AllocType3();
    if (DAT_801e70cc != (undefined1 *)0x0) {
      DAT_801e70cc[1] = 0;
      DAT_801e70cc[0x27] = 0x1c;
      DAT_801e70cc[0x25] = obj->flip;
      DAT_801e70cc[0x38] = 0;
      DAT_801e70cc[0x39] = 10;
      DAT_801e70cc[7] = 0;
      *DAT_801e70cc = 1;
      DAT_801e70cc[6] = 0xf;
      DAT_801e70cc[0x26] = 7;
      puVar1 = DAT_801e70cc;
      *(short *)(DAT_801e70cc + 0xe) = obj->x;
      *(short *)(puVar1 + 0x12) = obj->y;
    }
  }
  return;
}


// ---- 801dbb90 FUN_801dbb90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbb90(MM8Obj *obj)

{
  Anim_Set(obj,0xb);
  obj->state = 1;
  obj->sub2 = 0;
  return;
}


// ---- 801dbbc8 FUN_801dbbc8

void FUN_801dbbc8(int param_1)

{
  *(undefined **)(param_1 + 0x38) = &DAT_801e6890;
  while (FUN_80106214(param_1), (*(byte *)(param_1 + 0x33) & 0x80) == 0) {
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 1;
  }
  return;
}


// ---- 801dbc28 FUN_801dbc28

void FUN_801dbc28(int param_1)

{
  *(undefined **)(param_1 + 0x3c) = &DAT_801e6898;
  FUN_80109804();
  *(undefined **)(param_1 + 0x3c) = &DAT_801e6890;
  FUN_80109804();
  return;
}


// ---- 801dbc70 FUN_801dbc70

void FUN_801dbc70(int param_1)

{
  *(undefined **)(param_1 + 0x38) = &DAT_801e6890;
  FUN_80107bf4(param_1,&g_player,1);
  if (*(short *)(param_1 + 0x2e) == 0x18) {
    *(undefined **)(param_1 + 0x38) = &DAT_801e68a0;
  }
  else if ((int)*(short *)(param_1 + 0x2e) - 0x19U < 2) {
    *(undefined **)(param_1 + 0x38) = &DAT_801e68a8;
  }
  else {
    *(undefined **)(param_1 + 0x38) = &DAT_801e6898;
  }
  FUN_80107bf4(param_1,&g_player,1);
  return;
}


// ---- 801dbd10 FUN_801dbd10

void FUN_801dbd10(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0x3f;
  iVar4 = 0x17a0;
  do {
    pcVar3 = &g_main_pool + iVar4;
    if ((*(char *)((int)&DAT_8015b178 + iVar4 + 2) == '\f') && (*pcVar3 != '\0')) {
      FUN_80107bf4(param_1,pcVar3,0);
      iVar2 = FUN_801082e0(param_1,pcVar3);
      if ((iVar2 != 0) && (*(int *)((int)&DAT_8015b188 + iVar4) == 0)) {
        uVar1 = 1;
        if (((DAT_801c3360 & 0x20) != 0) || (uVar1 = 0xff, (DAT_801c3360 & 0x10) != 0)) {
          (&UNK_8015b1c6)[iVar4] = uVar1;
        }
      }
    }
    iVar5 = iVar5 + -1;
    iVar4 = iVar4 + -0x60;
  } while (-1 < iVar5);
  return;
}


