// T3_13, STAGE02.BIN, handler 0x801E4BC8. Ghidra output with the object struct applied; not matching C.
// ---- 801e4bc8 FUN_801e4bc8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4bc8(MM8Obj *obj)

{
  if (obj->state == 0) {
    FUN_801e4c9c(obj);
  }
  else {
    FUN_801e4e3c();
  }
  if ((obj->field_0x4 & 0x80) != 0) {
    Anim_Set(obj,obj->field_0x4 & 0x7f);
    obj->field_0x4 = 0;
  }
  if (obj->state == 2) {
    Obj_Free(obj);
  }
  else if (((obj->var != 3) || (obj->hitbox[5] != 0)) && ((obj->var != 4 || (obj->sub2 != 0)))) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e4c9c FUN_801e4c9c

void FUN_801e4c9c(int param_1,byte param_2)

{
  undefined1 uVar1;
  char cVar2;
  
  uVar1 = 0x2e;
  if (3 < *(byte *)(param_1 + 7)) {
    uVar1 = 0x39;
  }
  *(undefined1 *)(param_1 + 0x27) = uVar1;
  *(undefined2 *)(param_1 + 0x2c) = (&DAT_80170348)[*(byte *)(param_1 + 0x27)];
  uVar1 = (&DAT_80159f64)[*(byte *)(param_1 + 0x27)];
  *(undefined1 *)(param_1 + 0x25) = 0;
  *(undefined1 *)(param_1 + 0x24) = uVar1;
  if (*(byte *)(param_1 + 7) < 2) {
    *(undefined1 *)(param_1 + 0x26) = 4;
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 0xf;
    param_2 = (&DAT_801e8a74)[*(byte *)(param_1 + 0x38)];
  }
  cVar2 = *(char *)(param_1 + 7);
  if (cVar2 == '\x02') {
    *(undefined1 *)(param_1 + 0x26) = 5;
    param_2 = (&DAT_801e8a7a)[*(byte *)(param_1 + 0x38)];
    cVar2 = *(char *)(param_1 + 7);
  }
  if (cVar2 == '\x03') {
    *(undefined1 *)(param_1 + 0x26) = 9;
    param_2 = 0x10;
  }
  if (*(byte *)(param_1 + 7) - 4 < 4) {
    *(int *)(param_1 + 0x20) = (int)*(short *)(param_1 + 0x12);
    *(int *)(param_1 + 0x1c) = (int)*(short *)(param_1 + 0xe);
    if (*(char *)(param_1 + 7) == '\a') {
      *(undefined1 *)(param_1 + 0x26) = 0xb;
      param_2 = 0xb;
    }
    cVar2 = *(char *)(param_1 + 7);
    if (cVar2 == '\x05') {
      *(undefined1 *)(param_1 + 0x26) = 0xb;
      param_2 = 9;
      cVar2 = *(char *)(param_1 + 7);
    }
    if (cVar2 == '\x06') {
      uVar1 = 10;
      if (*(char *)(param_1 + 0x38) != '\0') {
        uVar1 = 0xb;
      }
      *(undefined1 *)(param_1 + 0x26) = uVar1;
      param_2 = 0xc;
    }
    if (*(char *)(param_1 + 7) == '\x04') {
      param_2 = 0;
      *(undefined1 *)(param_1 + 0x26) = 0xb;
      *(undefined4 *)(param_1 + 0x18) = 0x8000;
      *(undefined1 *)(param_1 + 0x33) = 0;
      *(undefined1 *)(param_1 + 0x38) = 0;
    }
  }
  *(undefined1 *)(param_1 + 0x3a) = *(undefined1 *)(*(int *)(param_1 + 0x3c) + 6);
  uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x3c) + 7);
  *(byte *)(param_1 + 4) = param_2 | 0x80;
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)(param_1 + 0x3b) = uVar1;
  return;
}


// ---- 801e4e3c FUN_801e4e3c

void FUN_801e4e3c(int param_1)

{
  uint uVar1;
  
  if (*(byte *)(param_1 + 7) - 4 < 4) {
    *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_1 + 0x1c);
    *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_1 + 0x20);
  }
  uVar1 = (uint)*(byte *)(param_1 + 7);
  if ((uVar1 < 2) || (uVar1 == 7)) {
    Anim_Step(param_1);
    uVar1 = (uint)*(byte *)(param_1 + 7);
  }
  if (uVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x801e4ec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(&DAT_801d801c + uVar1 * 4))();
    return;
  }
  if (*(byte *)(param_1 + 7) - 4 < 4) {
    *(int *)(param_1 + 0x1c) = (int)*(short *)(param_1 + 0xe);
    *(int *)(param_1 + 0x20) = (int)*(short *)(param_1 + 0x12);
    *(short *)(param_1 + 0xe) =
         *(short *)(param_1 + 0xe) + (DAT_801d2918._2_2_ - DAT_801d2948._2_2_);
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + (g_cam_y - DAT_801d294c);
  }
  return;
}


