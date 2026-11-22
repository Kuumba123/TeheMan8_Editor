// ID 18, STAGE02.BIN, handler 0x801D9E40. Ghidra output with the object struct applied; not matching C.
// ---- 801d9e40 FUN_801d9e40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9e40(MM8Obj *obj)

{
  char cVar1;
  uint uVar2;
  
  (*(code *)(&PTR_FUN_801e859c)[obj->state])();
  if (obj->active != 0) {
    uVar2._0_1_ = obj->active;
    uVar2._1_1_ = obj->state;
    uVar2._2_1_ = obj->sub2;
    uVar2._3_1_ = obj->sub3;
    if ((uVar2 & 0xffff00) != 0x20600) {
      Obj_CullAndQueueDraw(obj);
    }
    if (((obj->var == 0) || (obj->var == 2)) && (cVar1 = Obj_InActiveArea(obj), cVar1 == '\0')) {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801d9ef0 FUN_801d9ef0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801d9ef0(MM8Obj *obj)

{
  byte bVar1;
  short sVar2;
  word wVar3;
  MM8Obj *pMVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  char cVar8;
  
  Enemy_InitFromTable();
  bVar1 = obj->var;
  if (bVar1 == 1) {
    obj->state = 4;
    obj->sub2 = 0;
    if ((obj->field_0x54 & 2) == 0) {
      obj->draw_list = 4;
    }
    else {
      obj->draw_list = 5;
    }
    obj->x = (short)(char)(&DAT_801e8548)[(uint)(byte)obj->field_0x54 * 2] + obj->x;
    cVar8 = (&DAT_801e8549)[(uint)(byte)obj->field_0x54 * 2];
    obj->hp = 10;
    obj->dmg_table = 2;
    obj->contact_dmg = 4;
    obj->flip = 0;
    obj->y = (short)cVar8 + obj->y;
    Anim_Set(obj,0x1b);
    obj->hitbox = &DAT_801e8554;
    obj->box2 = (byte *)0x0;
    obj->dmg_table = 8;
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      cVar8 = '\0';
      pMVar4 = obj;
      do {
        pMVar4 = (MM8Obj *)FUN_801055e4(pMVar4);
        if (pMVar4 == (MM8Obj *)0x0) break;
        pMVar4->active = 1;
        pMVar4->var = 1;
        pMVar4->field_0x54 = cVar8;
        sVar2 = obj->x;
        pMVar4->x_frac = obj->x_frac;
        pMVar4->x = sVar2;
        cVar8 = cVar8 + '\x01';
        wVar3 = obj->y_frac;
        sVar2 = obj->y;
        pMVar4->id = 0x18;
        pMVar4->state = 0;
        *(MM8Obj **)&pMVar4->field_0x50 = obj;
        pMVar4->y_frac = wVar3;
        pMVar4->y = sVar2;
      } while (cVar8 < '\x04');
      obj->field_0x54 = cVar8;
      cVar8 = '\0';
      obj->field_0x5a = 0;
      do {
        puVar5 = (undefined1 *)Obj_AllocType3();
        if (puVar5 == (undefined1 *)0x0) break;
        *puVar5 = 1;
        puVar5[7] = cVar8;
        puVar5[6] = 0x14;
        puVar5[1] = 0;
        *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)&obj->x_frac;
        cVar8 = cVar8 + '\x01';
        uVar7 = *(undefined4 *)&obj->y_frac;
        *(MM8Obj **)(puVar5 + 0x38) = obj;
        *(undefined4 *)(puVar5 + 0x10) = uVar7;
      } while (cVar8 < '\x02');
      obj->state = 1;
      obj->field_0x58 = 5;
      obj->draw_list = 5;
      obj->hp = 10;
      obj->dmg_table = 2;
      obj->field_0x55 = cVar8;
      obj->sub2 = 0;
      obj->sub3 = 0;
      obj->field_0x4 = 0;
      obj->field_0x59 = 0;
      obj->contact_dmg = 3;
      obj->flip = 0;
      Anim_Set(obj,0x19);
      *(short *)&obj->field_0x56 = obj->y;
      iVar6 = 0x400;
      if ((int)DAT_8015e248._2_2_ - (int)obj->x < 0) {
        iVar6 = -0x400;
      }
      obj->accel_x = iVar6;
      obj->gravity = 0x100;
      obj->box2 = &DAT_801e8560;
      obj->hitbox = &DAT_801e8550;
      obj->field_0x5f = 0;
    }
  }
  else if (bVar1 == 2) {
    obj->state = 6;
    obj->draw_list = 7;
    obj->hp = 10;
    obj->dmg_table = 0;
    obj->contact_dmg = 3;
    obj->flip = 0;
    Anim_Set(obj,0x24);
    obj->box2 = &DAT_801e8568;
    obj->hitbox = &DAT_801e8558;
  }
  obj->field_0x43 = 1;
  return;
}


// ---- 801da1e4 FUN_801da1e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da1e4(MM8Obj *obj)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  obj->clut = DAT_80159f9a;
  (*(code *)(&PTR_FUN_801e85c4)[obj->sub2])();
  if ((obj->field_0x54 & 0xc0) != 0) {
    (*(code *)(&PTR_LAB_801e85d0)[obj->sub3])(obj);
  }
  sVar2 = Enemy_CheckWeaponHits(obj);
  if (sVar2 == 4) {
    obj->state = 3;
    if ((obj->field_0x54 & 0x80) != 0) {
      return;
    }
    obj->field_0x5f = 0xff;
    return;
  }
  if (sVar2 == 2) {
    obj->clut = 0;
  }
  if ((obj->field_0x54 & 0x7f) == 0) {
    obj->state = 2;
    obj->gravity = 0x4000;
    obj->dmg_table = 0;
    obj->speed_x = 0;
    obj->accel_x = 0;
    obj->speed_y_up = 0;
    obj->field_0x59 = 4;
    obj->clut = DAT_80159f9a;
    return;
  }
  iVar4 = (int)(((uint)DAT_8015e248._2_2_ - (uint)(ushort)obj->x) * 0x10000) >> 0x10;
  iVar3 = iVar4;
  if (iVar4 < 0) {
    iVar3 = -iVar4;
  }
  if (0x30 < iVar3) {
    iVar3 = 0x400;
    if (iVar4 < 0) {
      iVar3 = -0x400;
    }
    obj->accel_x = iVar3;
  }
  iVar3 = obj->speed_x + obj->accel_x;
  obj->speed_x = iVar3;
  if (obj->accel_x < 0) {
    iVar4 = -0x10000;
    bVar1 = iVar3 < -0x10000;
  }
  else {
    iVar4 = 0x10000;
    bVar1 = 0x10000 < iVar3;
  }
  if (bVar1) {
    obj->speed_x = iVar4;
    obj->accel_x = 0;
  }
  iVar4 = (int)(((uint)(ushort)obj->y - (uint)*(ushort *)&obj->field_0x56) * 0x10000) >> 0x10;
  iVar3 = iVar4;
  if (iVar4 < 0) {
    iVar3 = -iVar4;
  }
  if (8 < iVar3) {
    iVar3 = -0x100;
    if (iVar4 < 0) {
      iVar3 = 0x100;
    }
    obj->gravity = iVar3;
  }
  iVar3 = obj->speed_y_up - obj->gravity;
  obj->speed_y_up = iVar3;
  if (obj->gravity < 0) {
    if (-0x4001 < iVar3) goto LAB_801da3ec;
    obj->speed_y_up = -0x4000;
  }
  else {
    if (iVar3 < 0x4001) goto LAB_801da3ec;
    obj->speed_y_up = 0x4000;
  }
  obj->gravity = 0;
LAB_801da3ec:
  FUN_80104c34(obj);
  FUN_80106214(obj);
  if (((obj->field_0x33 & 0x30) != 0) &&
     ((obj->speed_x & 0x80000000U) != (obj->accel_x & 0x80000000U))) {
    obj->accel_x = -obj->accel_x;
  }
  if (((obj->field_0x33 & 0xc0) != 0) &&
     ((obj->speed_y_up & 0x80000000U) == (obj->gravity & 0x80000000U))) {
    obj->gravity = -obj->gravity;
  }
  Enemy_ContactDamage(obj);
  Anim_Step(obj);
  return;
}


// ---- 801da484 FUN_801da484

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da484(MM8Obj *obj)

{
  FUN_80104ccc();
  if (obj->speed_y_up < -0x60000) {
    obj->speed_y_up = -0x60000;
    obj->gravity = 0;
  }
  FUN_80106214(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    FUN_80108e84(obj);
    FUN_8012ae08(obj,9);
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801da9a8 FUN_801da9a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801da9a8(MM8Obj *obj)

{
  if (((obj->field_0x54 & 0x80) == 0) || ((obj->field_0x54 & 0x3f) == 0)) {
    FUN_80108e84(obj);
    FUN_8012ae08(obj,9);
    if (obj->var == 0) {
      FUN_80108fd8(obj,1);
    }
    Obj_FreeDespawn(obj);
  }
  else {
    obj->clut = DAT_80159f9a;
    if ((_DAT_80170574 & 1) != 0) {
      obj->clut = 0;
    }
    (*(code *)(&PTR_LAB_801e85e8)[obj->sub3])(obj);
  }
  return;
}


// ---- 801daa74 FUN_801daa74

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801daa74(MM8Obj *obj)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *puVar5;
  
  bVar1 = obj->field_0x4;
  if (bVar1 == 1) {
    if ((obj->field_0x59 != '\x02') &&
       (cVar2 = obj->field_0x58, obj->field_0x58 = cVar2 + -1, cVar2 != '\0')) {
      return;
    }
    Anim_Set(obj,0x1a);
    puVar5 = (undefined1 *)FUN_801055e4(obj);
    if (puVar5 != (undefined1 *)0x0) {
      *puVar5 = 1;
      puVar5[7] = 2;
      *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)&obj->x_frac;
      iVar4 = *(int *)&obj->y_frac;
      puVar5[6] = 0x18;
      puVar5[1] = 0;
      *(MM8Obj **)(puVar5 + 0x50) = obj;
      *(int *)(puVar5 + 0x10) = iVar4 + 0x80000;
    }
    obj->field_0x4 = 2;
    return;
  }
  if (bVar1 < 2) {
    if (bVar1 != 0) {
      return;
    }
    iVar4 = FUN_80105d48(obj,0x1d);
    if (5 < iVar4) {
      return;
    }
    cVar2 = obj->field_0x58;
    obj->field_0x58 = cVar2 + -1;
    if (cVar2 != '\0') {
      return;
    }
    obj->field_0x58 = 0xb4;
    uVar3 = 1;
  }
  else {
    if (bVar1 != 2) {
      if (bVar1 != 3) {
        return;
      }
      if (((int)(short)obj->frame & 0x8000U) == 0) {
        return;
      }
      obj->field_0x58 = 0x5a;
      obj->field_0x4 = 0;
      obj->field_0x59 = 0;
      Anim_Set(obj,0x19);
      return;
    }
    uVar3 = 3;
    if (obj->anim_extra == 0) {
      return;
    }
  }
  obj->field_0x59 = uVar3;
  obj->field_0x4 = uVar3;
  return;
}


