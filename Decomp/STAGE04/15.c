// ID 15, STAGE04.BIN, handler 0x801DB000. Ghidra output with the object struct applied; not matching C.
// ---- 801db000 FUN_801db000

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db000(MM8Obj *obj)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_801e6db4)[obj->state])();
  if ((obj->active != 0) && (iVar1 = Obj_InActiveArea(obj), iVar1 != 0)) {
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801db070 FUN_801db070

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db070(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 9;
  obj->state = 1;
  obj->hitbox = &DAT_801e6dac;
  obj->box2 = &DAT_801e6dac;
  obj->field_0x50 = 0;
  obj->field_0x51 = 0;
  obj->sub2 = 0;
  (*(code *)(&PTR_FUN_801e6db4)[obj->state])(obj);
  return;
}


// ---- 801db0e4 FUN_801db0e4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db0e4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = obj->sub2;
  if (bVar1 == 0) {
    Anim_Set(obj,0);
    bVar1 = 3;
  }
  else if (bVar1 == 1) {
    Anim_Set(obj,(byte)obj->field_0x50 + 6);
    bVar1 = 2;
  }
  else {
    if (bVar1 != 2) goto LAB_801db158;
    Anim_Step(obj);
    iVar2 = Anim_AtLoopMarker(obj);
    bVar1 = 3;
    if (iVar2 == 0) goto LAB_801db158;
  }
  obj->sub2 = bVar1;
LAB_801db158:
  iVar2 = FUN_801db330(obj);
  if (iVar2 != 0) {
    obj->state = 2;
    if (iVar2 < 0) {
      obj->field_0x51 = 0x18;
      obj->sub2 = 0;
    }
    else {
      obj->field_0x51 = 0;
      obj->sub2 = 1;
    }
  }
  return;
}


// ---- 801db1a4 FUN_801db1a4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db1a4(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = obj->sub2;
  if (bVar1 == 0) {
    if (obj->field_0x51 != '\0') {
      obj->field_0x51 = obj->field_0x51 + -1;
      goto LAB_801db27c;
    }
  }
  else {
    if (bVar1 != 1) {
      if (bVar1 == 2) {
        Anim_Step(obj);
        iVar2 = Anim_AtLoopMarker(obj);
        if (iVar2 != 0) {
          if ((byte)obj->field_0x50 < 4) {
            obj->sub2 = 1;
            obj->field_0x50 = obj->field_0x50 + '\x01';
          }
          else {
            FUN_800fce30(0x95);
            obj->state = 3;
            obj->sub2 = 0;
          }
        }
      }
      goto LAB_801db27c;
    }
    Anim_Set(obj,(byte)obj->field_0x50 + 1);
    FUN_8010544c(obj,0x95);
  }
  obj->sub2 = obj->sub2 + 1;
LAB_801db27c:
  iVar2 = FUN_801db41c(obj);
  if ((iVar2 != 0) && ((byte)obj->field_0x50 < 4)) {
    FUN_800fce30(0x95);
    obj->state = 1;
    obj->sub2 = 1;
  }
  return;
}


// ---- 801db2c8 FUN_801db2c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801db2c8(MM8Obj *obj)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)Obj_AllocType2();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[6] = 0xd;
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)&obj->x_frac;
    iVar2 = *(int *)&obj->y_frac;
    puVar1[1] = 0;
    *(int *)(puVar1 + 0x10) = iVar2 + 0x180000;
  }
  Obj_Free(obj);
  return;
}


// ---- 801db330 FUN_801db330

undefined4 FUN_801db330(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  
  cVar1 = Enemy_CheckWeaponHits();
  if ((cVar1 != '\x01') || (uVar2 = 1, DAT_80158f5c != '\n')) {
    pcVar4 = &g_main_pool;
    pbVar5 = &DAT_8015b175;
    do {
      if ((((*pcVar4 != '\0') && (pbVar5[5] == 0x10)) &&
          (iVar3 = FUN_80107bf4(param_1,pcVar4,0), iVar3 != 0)) && (*pbVar5 < 7)) {
        return 0xffffffff;
      }
      pcVar4 = pcVar4 + 0x60;
      pbVar5 = pbVar5 + 0x60;
    } while (pcVar4 < &DAT_8015c915);
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 801db41c FUN_801db41c

bool FUN_801db41c(void)

{
  char cVar1;
  
  cVar1 = Enemy_CheckWeaponHits();
  return cVar1 == '\x01' && DAT_80158f5c == '\x0e';
}


