// T3_15, STAGE05.BIN, handler 0x801E7DB8. Ghidra output with the object struct applied; not matching C.
// ---- 801e7db8 FUN_801e7db8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7db8(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = obj->speed_y_up;
  uVar4 = obj->var & 0xf;
  (*(code *)(&PTR_FUN_801eaa3c)[obj->state])();
  if (obj->active != 0) {
    iVar2 = FUN_801e8298(obj,obj->speed_y_up);
    if (iVar2 != 0) {
      FUN_801e81a0(obj);
      bVar3 = *(byte *)obj->speed_x;
      if ((bVar3 & 2) == 0) {
        if ((bVar3 & 0x20) != 0) {
          Anim_Set(obj,(&DAT_801eaa48)[uVar4]);
          *(undefined1 *)&obj->hitbox = 0;
          *(undefined1 *)&obj->box2 = 0;
        }
        bVar3 = bVar3 & 0x1f;
        if (bVar3 == 1) {
          return;
        }
        if (bVar3 == 5) {
          return;
        }
        if (uVar4 - 2 < 2) {
          if (bVar3 == 4) {
            return;
          }
          if ((*(byte *)(iVar5 + 0x33) & 0x80) == 0) {
            return;
          }
          cVar1 = FUN_801e822c(obj);
          if (cVar1 == '\0') {
            return;
          }
        }
        Obj_CullAndQueueDrawMargin(obj,0x60);
        return;
      }
    }
    Obj_Free(obj);
  }
  return;
}


// ---- 801e7f00 FUN_801e7f00

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7f00(MM8Obj *obj)

{
  uint uVar1;
  
  uVar1 = obj->var & 0xf;
  if (uVar1 - 4 < 2) {
    obj->clut = (&DAT_80159f64)[obj->bank];
    obj->vram_base = (&DAT_80170348)[obj->bank];
  }
  else {
    if (uVar1 < 2) {
      obj->bank = 0x51;
      obj->clut = DAT_80159fb5;
    }
    else {
      obj->bank = 0x51;
      obj->clut = DAT_80159fb8;
    }
    obj->vram_base = DAT_801703ea;
  }
  *(undefined1 *)&obj->box2 = 0;
  obj->sub2 = 0;
  Anim_Set(obj,(&DAT_801eaa48)[uVar1]);
  *(undefined1 *)&obj->hitbox = 0;
  obj->state = obj->state + 1;
  return;
}


// ---- 801e7fe0 FUN_801e7fe0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7fe0(MM8Obj *obj)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = obj->var & 0xf;
  if (1 < (*(byte *)obj->speed_x & 0x1f) - 4) {
    if (uVar3 == 5) {
      *(undefined1 *)&obj->box2 = 0;
    }
    else if (*(char *)&obj->box2 == '\0') {
      FUN_801e8200(obj);
    }
    else {
      cVar1 = *(char *)&obj->box2 + -1;
      *(char *)&obj->box2 = cVar1;
      if (cVar1 != '\0') {
        return;
      }
      FUN_801e8200();
    }
    iVar2 = Anim_AtLoopMarker(obj);
    if ((iVar2 == 0) || ((&DAT_801eaa50)[uVar3] == '\0')) {
      Anim_Step(obj);
      if (uVar3 < 2) {
        if ((*(byte *)obj->speed_x & 0x40) == 0) {
          cVar1 = *(char *)&obj->hitbox + '\x01';
        }
        else {
          cVar1 = *(char *)&obj->hitbox + -1;
        }
        *(char *)&obj->hitbox = cVar1;
        *(byte *)&obj->hitbox = *(byte *)&obj->hitbox & 7;
        obj->frame = (ushort)(byte)(&DAT_801eaa58)[*(byte *)&obj->hitbox >> 1];
      }
    }
    else {
      *(undefined *)&obj->box2 = (&DAT_801eaa50)[uVar3];
      obj->state = obj->state + 1;
    }
  }
  return;
}


// ---- 801e81a0 FUN_801e81a0

void FUN_801e81a0(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 7) & 0xf;
  bVar1 = **(byte **)(param_1 + 0x14);
  if (bVar2 != 5) {
    *(short *)(param_1 + 0xe) =
         *(short *)(*(int *)(param_1 + 0x18) + 0xe) + *(short *)(param_1 + 0x1c);
    *(short *)(param_1 + 0x12) =
         *(short *)(*(int *)(param_1 + 0x18) + 0x12) + *(short *)(param_1 + 0x20);
    if (1 < bVar2) {
      *(byte *)(param_1 + 0x25) = bVar1 & 0xc0;
    }
  }
  return;
}


// ---- 801e8200 FUN_801e8200

void FUN_801e8200(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 0x3c);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  *(char *)(param_1 + 0x38) = '\x02' - (char)((uint)iVar1 >> 0x10);
  return;
}


// ---- 801e822c FUN_801e822c

bool FUN_801e822c(int param_1)

{
  char cVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 0x25) & 0x40) == 0) {
    iVar2 = *(short *)(param_1 + 0xe) + -0x10;
  }
  else {
    iVar2 = *(short *)(param_1 + 0xe) + 0x10;
  }
  cVar1 = FUN_80107204(iVar2,*(short *)(*(int *)(param_1 + 0x18) + 0x4e) + 0x10);
  return cVar1 == '\x04';
}


// ---- 801e8298 FUN_801e8298

bool FUN_801e8298(int param_1,char *param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) &&
     (*(char *)(param_1 + 0x39) == param_2[0x27])) {
    bVar1 = *(char *)(param_1 + 0x3a) == param_2[7];
  }
  return bVar1;
}


