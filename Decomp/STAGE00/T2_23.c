// T2_23, STAGE00.BIN, handler 0x801DF09C. Ghidra output with the object struct applied; not matching C.
// ---- 801df09c FUN_801df09c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df09c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e28c8)[obj->state])();
  if (obj->active != 0) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801df0fc FUN_801df0fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df0fc(MM8Obj *obj)

{
  byte bVar1;
  
  bVar1 = 0x19;
  if ((obj->var & 1) != 0) {
    bVar1 = 0x68;
  }
  obj->bank = bVar1;
  obj->vram_base = (&DAT_80170348)[obj->bank];
  bVar1 = (&DAT_80159f64)[obj->bank];
  obj->flip = (1 < obj->var) << 6;
  obj->draw_list = 6;
  obj->clut = bVar1;
  if ((obj->var == 0) || (obj->var == 2)) {
    bVar1 = obj->clut;
    obj->clut = 0x1a;
    obj->speed_y_up = -0x100000;
    obj->field_0x49 = 1;
    *(undefined **)&obj->field_0x4c = &DAT_80054000;
    obj->invuln = bVar1;
    Anim_Set(obj,0x11);
    FUN_80103224(obj);
    FUN_800fd100(0);
  }
  else {
    Anim_Set(obj,5);
  }
  obj->state = obj->var + 1;
  return;
}


// ---- 801df204 FUN_801df204

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df204(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e28dc)[obj->sub2])(obj,obj->box2);
  FUN_80103184(obj);
  return;
}


// ---- 801df254 FUN_801df254

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df254(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    FUN_80104d18();
    if (0x1c2 < obj->y) {
      obj->y = 0x1c2;
      obj->sub3 = 1;
    }
  }
  else {
    iVar1 = FUN_801dfe30(obj);
    if (iVar1 != 0) {
      Anim_Set(obj,2);
      obj->sub2 = 1;
      obj->dmg_table = 0;
    }
    Anim_Step(obj);
    if (obj->anim_extra != 0) {
      obj->anim_extra = 0;
      obj->clut = obj->invuln;
    }
  }
  return;
}


// ---- 801df2fc FUN_801df2fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df2fc(MM8Obj *obj)

{
  int iVar1;
  
  Anim_Step();
  if (obj->sub3 == 0) {
    Anim_Set(obj,1);
    FUN_800fd100(0x37);
    obj->sub3 = 1;
    obj->dmg_table = obj->dmg_table + 1;
  }
  iVar1 = FUN_801dfe30(obj);
  if (iVar1 != 0) {
    if (obj->dmg_table < 2) {
      obj->sub3 = 0;
      if (obj->var != 0) {
        DAT_8015e261 = 0;
      }
    }
    else {
      obj->sub2 = 2;
      obj->sub3 = 0;
      Anim_Set(obj,0xb);
    }
  }
  return;
}


// ---- 801df3b0 FUN_801df3b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df3b0(MM8Obj *obj)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if (obj->sub3 == 0) {
    iVar2 = FUN_801dfe30();
    if (iVar2 != 0) {
      Anim_Set(obj,0xc);
      FUN_800fd100(0x18c);
      obj->sub3 = 1;
      obj->dmg_table = 0x10;
    }
  }
  else {
    obj->dmg_table = obj->dmg_table - 1;
    if (obj->dmg_table == 0) {
      obj->sub2 = 3;
      obj->sub3 = 0;
      Anim_Set(obj,0xd);
      FUN_800fd100(0x18d);
      puVar3 = (undefined1 *)Obj_AllocType2();
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 1;
        puVar3[6] = 0x23;
        uVar1 = 0x1522;
        if (obj->var == 0) {
          uVar1 = 0x8fe;
          puVar3[7] = 1;
        }
        else {
          puVar3[7] = 3;
        }
        *(undefined2 *)(puVar3 + 0xe) = uVar1;
        *(undefined2 *)(puVar3 + 0x12) = 0x193;
        *(byte **)(puVar3 + 0x38) = obj->box2;
      }
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801df4bc FUN_801df4bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df4bc(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  int in_a1;
  
  if (obj->sub3 == 0) {
    if (((obj->var == 0) && (*(char *)(in_a1 + 0x15) == '\x03')) ||
       ((obj->var == 2 && (*(char *)(in_a1 + 0x15) == '\x04')))) {
      Anim_Set(obj,0xe);
      FUN_800fd100(0x18e);
      obj->dmg_table = 8;
      obj->sub3 = 1;
    }
  }
  else {
    iVar2 = FUN_801dfe30(obj);
    if (iVar2 != 0) {
      Anim_Set(obj,0);
      obj->dmg_table = obj->dmg_table - 1;
      if (obj->dmg_table == 0) {
        bVar1 = 5;
        if (obj->var == 0) {
          Anim_Set(obj,0xf);
          bVar1 = 4;
        }
        obj->sub2 = bVar1;
        obj->sub3 = 0;
      }
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801df5b8 FUN_801df5b8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df5b8(MM8Obj *obj)

{
  short sVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  int in_a1;
  
  iVar3 = FUN_801dfe30();
  if (iVar3 != 0) {
    pbVar4 = (byte *)FUN_80105628();
    if (pbVar4 != (byte *)0x0) {
      pbVar4[1] = 1;
      *pbVar4 = 1;
      pbVar4[6] = 2;
      pbVar4[7] = 0;
      pbVar4[0x26] = 4;
      pbVar4[0x25] = 0;
      pbVar4[0x27] = 9;
      *(undefined2 *)(pbVar4 + 0x2c) = DAT_8017035a;
      cVar2 = DAT_80159f6d;
      pbVar4[0x5c] = 0xb4;
      pbVar4[0x14] = 0;
      pbVar4[0x15] = 0;
      pbVar4[0x16] = 0xfe;
      pbVar4[0x17] = 0xff;
      pbVar4[0x18] = 0;
      pbVar4[0x19] = 0;
      pbVar4[0x1a] = 6;
      pbVar4[0x1b] = 0;
      pbVar4[0x43] = 1;
      pbVar4[0x47] = 2;
      pbVar4[0x44] = 4;
      pbVar4[0x46] = 0;
      pbVar4[0x54] = 0;
      pbVar4[0x55] = 0;
      pbVar4[0x56] = 0;
      pbVar4[0x1c] = 0;
      pbVar4[0x1d] = 0;
      pbVar4[0x1e] = 0;
      pbVar4[0x1f] = 0;
      pbVar4[0x20] = 0;
      pbVar4[0x21] = 0x40;
      pbVar4[0x22] = 0;
      pbVar4[0x23] = 0;
      pbVar4[0x24] = cVar2 + 2;
      sVar1 = obj->x;
      *(short *)(pbVar4 + 0xe) = sVar1;
      *(short *)(pbVar4 + 0x34) = sVar1;
      sVar1 = obj->y;
      *(undefined **)(pbVar4 + 0x3c) = &DAT_801e28f8;
      *(undefined **)(pbVar4 + 0x38) = &DAT_801e28f8;
      *(short *)(pbVar4 + 0x12) = sVar1;
      *(short *)(pbVar4 + 0x36) = sVar1;
      obj->hitbox = pbVar4;
      DAT_801b2980 = pbVar4;
      Anim_Set(pbVar4,7);
      FUN_800fd100(0x1d);
    }
    obj->sub2 = 5;
    obj->sub3 = 0;
    *(undefined1 *)(in_a1 + 0x15) = 4;
    Anim_Set(obj,0x10);
  }
  Anim_Step(obj);
  return;
}


// ---- 801df700 FUN_801df700

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df700(MM8Obj *obj)

{
  int iVar1;
  int in_a1;
  
  if (obj->var == 0) {
    obj->hitbox[0x5c] = 0xf0;
  }
  if (obj->sub3 == 0) {
    iVar1 = FUN_801dfe30(obj);
    if (iVar1 != 0) {
      Anim_Set(obj,2);
      obj->sub3 = 1;
    }
  }
  else if (((obj->var == 0) && (*(char *)(in_a1 + 0x15) == '\x05')) ||
          ((obj->var == 2 && (*(char *)(in_a1 + 0x15) == '\x04')))) {
    Anim_Set(obj,1);
    FUN_800fd100(0x37);
    obj->sub2 = 6;
    obj->sub3 = 0;
  }
  Anim_Step(obj);
  return;
}


// ---- 801df7d4 FUN_801df7d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df7d4(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  int in_a1;
  
  if (obj->sub3 == 0) {
    iVar2 = FUN_801dfe30();
    if (iVar2 != 0) {
      if (obj->anim == 1) {
        Anim_Set(obj,0x12);
      }
      else {
        obj->sub3 = 1;
      }
    }
    Anim_Step(obj);
    if (obj->anim_extra != 0) {
      obj->anim_extra = 0;
      obj->clut = 0x1a;
      obj->speed_y_up = -obj->speed_y_up;
      FUN_800fd100(6);
    }
  }
  else {
    FUN_80104d18(obj);
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      if (obj->var != 0) {
        *(undefined1 *)(in_a1 + 0x15) = 5;
      }
      Obj_Free(obj);
    }
  }
  return;
}


// ---- 801df8bc FUN_801df8bc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df8bc(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e2900)[obj->sub2])(obj,obj->box2);
  return;
}


// ---- 801df8f8 FUN_801df8f8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801df8f8(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->sub3 == 0) {
    iVar1 = FUN_801dfe30();
    if (iVar1 != 0) {
      Anim_Set(obj,1);
      obj->dmg_table = 0x40;
      obj->contact_dmg = 1;
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
  }
  else if (obj->field_0x4 == '\0') {
    obj->dmg_table = obj->dmg_table - 1;
    if (obj->dmg_table == 0) {
      Anim_Set(obj,2);
      obj->field_0x4 = 1;
    }
  }
  else {
    iVar1 = FUN_801dfe30(obj);
    if (iVar1 != 0) {
      if (obj->contact_dmg == 0) {
        Anim_Set(obj,1);
        obj->sub2 = 1;
        obj->sub3 = 0;
        obj->field_0x4 = 0;
        obj->dmg_table = 0x60;
      }
      else {
        Anim_Set(obj,2);
        obj->contact_dmg = obj->contact_dmg - 1;
      }
    }
  }
  Anim_Step(obj);
  return;
}


// ---- 801dfbe0 FUN_801dfbe0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfbe0(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e290c)[obj->sub2])(obj,obj->box2);
  return;
}


// ---- 801dfc1c FUN_801dfc1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dfc1c(MM8Obj *obj)

{
  int iVar1;
  int in_a1;
  
  if (obj->sub3 == 0) {
    iVar1 = FUN_801dfe30();
    if (iVar1 != 0) {
      Anim_Set(obj,1);
      obj->dmg_table = 0x40;
      obj->contact_dmg = 0;
      obj->sub3 = 1;
      obj->field_0x4 = 0;
    }
  }
  else if (obj->dmg_table == 0) {
    if (obj->field_0x4 == '\0') {
      Anim_Set(obj,2);
      obj->field_0x4 = 1;
    }
    else {
      iVar1 = FUN_801dfe30(obj);
      if (iVar1 != 0) {
        if (obj->contact_dmg == 0) {
          Anim_Set(obj,2);
          obj->contact_dmg = obj->contact_dmg + 1;
        }
        else {
          Anim_Set(obj,1);
          obj->sub2 = 1;
          obj->dmg_table = 0x60;
          obj->sub3 = 0;
          *(undefined1 *)(in_a1 + 0x15) = 2;
        }
      }
    }
  }
  else {
    obj->dmg_table = obj->dmg_table - 1;
  }
  Anim_Step(obj);
  return;
}


// ---- 801dfe30 FUN_801dfe30

bool FUN_801dfe30(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (*(short *)(param_1 + 0x2e) < 0) {
    bVar1 = *(char *)(param_1 + 0x31) == '\x01';
  }
  return bVar1;
}


