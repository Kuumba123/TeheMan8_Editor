// T2_21, STAGE05.BIN, handler 0x801E7800. Ghidra output with the object struct applied; not matching C.
// ---- 801e7800 FUN_801e7800

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e7800(MM8Obj *obj)

{
  byte bVar1;
  word wVar2;
  char cVar3;
  byte bVar4;
  short sVar5;
  
  bVar4 = obj->var;
  bVar1 = obj->state;
  obj->var = bVar4 & 0xf;
  if (bVar1 == 0) {
    if ((bVar4 & 1) == 0) {
      sVar5 = obj->x + 0x60;
    }
    else {
      sVar5 = obj->x + -0x60;
    }
    obj->x = sVar5;
    cVar3 = FUN_801e7a60(obj);
    if (cVar3 != '\0') {
      Obj_Free(obj);
      return;
    }
                    /* Possible PsyQ macro: setLineG4() */
    obj->bank = 0x5c;
    obj->clut = DAT_80159fbf;
    wVar2 = (&DAT_80170348)[obj->bank];
    obj->box2 = &DAT_801eaa1c;
    obj->hitbox = (byte *)0x0;
    obj->draw_list = 8;
    obj->flip = 0;
    obj->field_0x43 = 0;
    obj->field_0x33 = 0;
    obj->field_0x40 = 0;
    obj->field_0x4c = 0;
    obj->dmg_table = 0;
    obj->var = obj->var & 0xf;
    obj->vram_base = wVar2;
    Anim_Set(obj,0xc);
    bVar4 = obj->state;
    obj->sub2 = 0;
  }
  else if (bVar1 == 1) {
    cVar3 = FUN_801e7a4c(obj);
    if (cVar3 == '\0') goto LAB_801e7a04;
    Anim_Set(obj,0xd);
    FUN_801e8768(obj,3);
    FUN_801e8768(obj,4);
    FUN_801e8768(obj,5);
    DAT_801d2938 = 8;
    bVar4 = obj->state;
    obj->dmg_table = 0x1e;
  }
  else {
    if (bVar1 != 2) {
      if (bVar1 != 3) {
        obj->field_0x40 = 0;
        obj->on_screen = 0;
        return;
      }
      cVar3 = FUN_801e7a4c(obj);
      if (cVar3 != '\0') {
        FUN_80102ef4(0x30,(int)obj->x,(int)obj->y);
        FUN_801e8768(obj,1);
        FUN_801e8768(obj,2);
        obj->box2 = (byte *)0x0;
        obj->field_0x40 = 0;
        obj->field_0x4c = 0;
        obj->state = obj->state + 1;
        return;
      }
      goto LAB_801e7a04;
    }
    bVar4 = obj->dmg_table - 1;
    obj->dmg_table = bVar4;
    if (bVar4 != 0) goto LAB_801e7a04;
    FUN_801e7a58(obj);
    bVar4 = obj->state;
    obj->field_0x4c = 0;
  }
  obj->state = bVar4 + 1;
LAB_801e7a04:
  FUN_80107bf4(obj,&g_player,5);
  bVar4 = obj->var;
  if ((obj->field_0x40 & 0x40) != 0) {
    bVar4 = bVar4 | 0x80;
  }
  obj->var = bVar4;
  Obj_CullAndQueueDrawMargin(obj,0x60);
  return;
}


// ---- 801e7a4c FUN_801e7a4c

int FUN_801e7a4c(int param_1)

{
  return (int)*(char *)(param_1 + 0x4c);
}


// ---- 801e7a58 FUN_801e7a58

void FUN_801e7a58(int param_1)

{
  *(undefined1 *)(param_1 + 0x4c) = 0;
  return;
}


// ---- 801e7a60 FUN_801e7a60

undefined4 FUN_801e7a60(char *param_1)

{
  short *psVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  pcVar2 = &DAT_801b1eec;
  psVar1 = &DAT_801b1efa;
  while ((((*pcVar2 == '\0' || ((char)psVar1[-4] != '!')) || (param_1 == pcVar2)) ||
         (*psVar1 != *(short *)(param_1 + 0xe)))) {
    iVar3 = iVar3 + 1;
    psVar1 = psVar1 + 0x28;
    pcVar2 = pcVar2 + 0x50;
    if (0x1f < iVar3) {
      return 0;
    }
  }
  return 1;
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


