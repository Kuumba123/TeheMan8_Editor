// T3_17, STAGE02.BIN, handler 0x801E5A24. Ghidra output with the object struct applied; not matching C.
// ---- 801e5a24 FUN_801e5a24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5a24(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  (*(code *)(&PTR_FUN_801e8ad4)[obj->state])();
  if (obj->var - 5 < 2) {
    if ((int)obj->y < g_cam_y + -0x38) {
      uVar2 = 1;
    }
  }
  else {
    cVar1 = Obj_InActiveArea(obj);
    if ((cVar1 == '\0') && (uVar2 = 0xffffffff, obj->var == 0xff)) {
      uVar2 = (uint)(obj->sub3 != 0);
    }
  }
  if (uVar2 == 0) {
    Obj_CullAndQueueDraw(obj);
  }
  else if ((int)uVar2 < 0) {
    Obj_FreeDespawn(obj);
  }
  else {
    Obj_Free(obj);
  }
  return;
}


// ---- 801e5b14 FUN_801e5b14

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5b14(MM8Obj *obj)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  word *unaff_s5;
  
  if (obj->var == 0xff) {
    uVar3 = Rand();
    iVar6 = ((uint)(int)(short)(uVar3 & 0xf) % 5) * 0x10000;
    uVar7 = iVar6 >> 0x10;
    bVar2 = Rand();
    unaff_s5 = obj->anim_step;
    obj->flip = bVar2 & 0x40;
    obj->gravity = 0x4000;
    *(char *)((int)&obj->box2 + 1) = (char)((uint)iVar6 >> 0x10);
    obj->state = 2;
    uVar5 = uVar7;
  }
  else {
    bVar2 = obj->var;
    obj->state = 1;
    bVar1 = obj->var;
    *(undefined1 *)((int)&obj->box2 + 1) = 0;
    uVar7 = (bVar2 & 0x70) >> 4;
    obj->var = bVar1 & 0xf;
    uVar5 = (uint)obj->var;
    obj->flip = (bVar2 >> 7) << 6;
  }
  iVar6 = uVar5 * 4;
  obj->bank = (&DAT_801e8a94)[iVar6];
  obj->vram_base = (&DAT_80170348)[(byte)(&DAT_801e8a94)[iVar6]];
  bVar2 = (&DAT_80159f64)[(byte)(&DAT_801e8a95)[iVar6]];
  puVar8 = &DAT_801e8a96 + iVar6;
  obj->speed_x = 0;
  obj->speed_y_up = 0;
  obj->accel_x = 0;
  obj->clut = bVar2;
  if (obj->var == 0) {
    obj->speed_x = 0x8000;
    *(undefined1 *)&obj->box2 = 0x80;
  }
  uVar5 = (uint)obj->var;
  if (uVar5 == 4) {
    obj->speed_x = 0x4000;
    *(undefined1 *)&obj->box2 = 0xa0;
    uVar5 = (uint)obj->var;
  }
  if (uVar5 < 5) {
    obj->y = obj->y + (short)(char)(&DAT_801e8ab8)[uVar7] + (short)(char)(&DAT_801e8ac0)[uVar5];
    obj->draw_list = (&DAT_801e8ab0)[uVar7];
  }
  if (obj->var - 5 < 2) {
    bVar2 = Rand();
    obj->flip = bVar2 & 0x40;
    obj->draw_list = 0;
    uVar5 = Rand();
    obj->accel_x = uVar5 & 0x1ff;
    uVar5 = Rand();
    obj->speed_x = uVar5 & 0x7ff;
    uVar5 = Rand();
    obj->speed_y_up = (uVar5 & 0xffff) + 0x10000;
    bVar2 = Rand();
    *(byte *)&obj->box2 = (bVar2 & 0xf) + 0x30;
    uVar3 = Rand();
    uVar5 = (int)(((uint)(int)(short)(uVar3 & 0x7fff) % 5) * 0x10000) >> 0x10;
    if (uVar5 == 0) {
      uVar5 = Rand();
      uVar5 = uVar5 & 3;
    }
    obj->clut = (&DAT_801e8ac8)[uVar5 * 2];
    puVar8 = &DAT_801e8ac9 + uVar5 * 2;
    if (obj->var == 5) {
      iVar6 = 0;
      do {
        puVar4 = (undefined1 *)Obj_AllocType3();
        iVar6 = iVar6 + 1;
        if (puVar4 != (undefined1 *)0x0) {
          puVar4[6] = 0x17;
          *puVar4 = 1;
          puVar4[7] = 6;
          uVar3 = Rand();
          *(ushort *)(puVar4 + 0xe) = (obj->x + 0x8f) - (uVar3 & 0x1ff);
          uVar3 = Rand();
          *(ushort *)(puVar4 + 0x12) = obj->y + (uVar3 & 0x7f) + 0x80;
        }
      } while (iVar6 < 0x20);
      obj->y = obj->y + 0xc0;
    }
  }
  if ((obj->flip == 0) && (obj->var != 0xff)) {
    obj->speed_x = -obj->speed_x;
    obj->accel_x = -obj->accel_x;
  }
  Anim_Set(obj,*puVar8);
  if (obj->var == 0xff) {
    obj->anim_step = unaff_s5;
  }
  return;
}


// ---- 801e5ecc FUN_801e5ecc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5ecc(MM8Obj *obj)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  
  if ((obj->var < 5) || (DAT_8015e241 != '\0')) {
    FUN_80104c34(obj);
    Anim_Step(obj);
    *(char *)&obj->box2 = *(char *)&obj->box2 + -1;
  }
  bVar2 = obj->var;
  if (bVar2 == 4) {
    if (obj->sub2 == 0) {
      if (*(char *)&obj->box2 == '\0') {
        iVar3 = obj->speed_x;
        obj->speed_x = 0;
        obj->sub2 = 1;
        obj->accel_x = iVar3;
        Anim_Set(obj,1);
      }
    }
    else if ((short)obj->frame < 0) {
      *(undefined1 *)&obj->box2 = 0xa0;
      obj->sub2 = 0;
      obj->flip = obj->flip ^ 0x40;
      obj->speed_x = -obj->accel_x;
      Anim_Set(obj,0);
    }
  }
  else if (bVar2 < 5) {
    if ((bVar2 == 0) && (*(char *)&obj->box2 == '\0')) {
      if (obj->sub2 == 0) {
        iVar3 = obj->speed_x;
        bVar2 = *(byte *)((int)&obj->box2 + 1);
        obj->speed_x = 0;
        *(undefined1 *)&obj->box2 = 0x20;
        *(byte *)((int)&obj->box2 + 1) = bVar2 ^ 1;
        uVar1 = *(undefined1 *)((int)&obj->box2 + 1);
        obj->sub2 = 1;
        obj->accel_x = iVar3;
        Anim_Set(obj,uVar1);
      }
      else {
        *(undefined1 *)&obj->box2 = 0x80;
        obj->sub2 = 0;
        obj->speed_x = -obj->accel_x;
      }
    }
  }
  else if ((bVar2 < 7) && (DAT_8015e241 != '\0')) {
    if (*(char *)&obj->box2 == '\0') {
      obj->accel_x = -obj->accel_x;
      bVar2 = Rand();
      *(byte *)&obj->box2 = (bVar2 & 0xf) + 0x30;
    }
    else {
      obj->speed_x = obj->speed_x + obj->accel_x;
    }
  }
  return;
}


// ---- 801e60cc FUN_801e60cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e60cc(MM8Obj *obj)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  word *pwVar10;
  short sVar11;
  byte *pbVar12;
  
  bVar2 = false;
  pwVar10 = obj->anim_step;
  pbVar12 = obj->hitbox;
  iVar9 = (int)pwVar10 + (int)(char)(&DAT_801e8ac0)[*(byte *)((int)&obj->box2 + 1)];
  sVar11 = (short)iVar9;
  if (obj->sub2 == 0) {
    FUN_80104ccc();
    iVar8 = (int)obj->y;
    if (iVar9 * 0x10000 >> 0x10 < iVar8) {
      iVar8 = obj->speed_y_up;
      obj->y = sVar11;
      if (iVar8 < 0) {
        iVar8 = iVar8 + 3;
      }
      obj->speed_y_up = -(iVar8 >> 2);
      bVar2 = true;
      iVar8 = (int)obj->y;
    }
    if ((iVar8 == iVar9 * 0x10000 >> 0x10) && ((obj->speed_y_up & 0x7fffffffU) < 0x8000)) {
      obj->speed_y_up = 0;
      uVar5 = Rand();
      iVar8 = (uVar5 & 0x7f) * (4 - (uint)*(byte *)&obj->box2);
      if (obj->x < DAT_8015e248._2_2_) {
        iVar8 = -iVar8;
      }
      obj->accel_x = iVar8;
      obj->y = sVar11;
      obj->sub2 = 1;
      bVar3 = Rand();
      cVar1 = *(char *)&obj->box2;
      *(byte *)((int)&obj->box2 + 2) = *(char *)&obj->box2 * '\b' + (bVar3 & 0x1f);
      if (cVar1 == '\x04') {
        pbVar12[0x17] = 1;
      }
    }
  }
  else if (obj->sub3 == 0) {
    if (pbVar12[0x17] != 0) {
      if (*(char *)((int)&obj->box2 + 2) == '\0') {
        Obj_ApplySpeed(obj);
      }
      else {
        *(char *)((int)&obj->box2 + 2) = *(char *)((int)&obj->box2 + 2) + -1;
      }
    }
    if (obj->field_0x4 == '\0') {
      if (pbVar12[0x17] != 0) {
        obj->anim_step = (word *)((int)pwVar10 >> 0x10);
        obj->field_0x4 = 1;
      }
    }
    else {
      iVar8 = (int)obj->y;
      if (sVar11 < iVar8) {
        iVar8 = obj->speed_y_up;
        obj->y = sVar11;
        if (iVar8 < 0) {
          iVar8 = iVar8 + 3;
        }
        bVar2 = true;
        obj->speed_y_up = -(iVar8 >> 2);
        obj->gravity = 0x4000;
        iVar8 = (int)obj->y;
      }
      if ((iVar8 == iVar9 * 0x10000 >> 0x10) && ((obj->speed_y_up & 0x7fffffffU) < 0x8000)) {
        obj->speed_y_up = 0;
        obj->gravity = 0;
        obj->y = sVar11;
        obj->sub3 = 1;
      }
    }
  }
  if (bVar2) {
    iVar8 = 0;
    uVar5 = Rand();
    if ((uVar5 & 3) != 0) {
      do {
        puVar6 = (undefined1 *)Obj_AllocType3();
        iVar8 = iVar8 + 1;
        if (puVar6 != (undefined1 *)0x0) {
          *puVar6 = 1;
          puVar6[6] = 6;
          puVar6[7] = 0;
          uVar4 = Rand();
          *(ushort *)(puVar6 + 0x12) = (short)iVar9 - ((uVar4 & 3) - 2);
          uVar7 = Rand();
          iVar9 = (uVar7 & 0xf) - 8;
          *(short *)(puVar6 + 0xe) = (short)iVar9 + obj->x;
        }
      } while (iVar8 < (int)(uVar5 & 3));
    }
  }
  return;
}


