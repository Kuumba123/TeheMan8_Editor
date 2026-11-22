// T2_1C, STAGE05.BIN, handler 0x801E556C. Ghidra output with the object struct applied; not matching C.
// ---- 801e556c FUN_801e556c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e556c(MM8Obj *obj)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  bVar2 = obj->var;
  uVar5 = bVar2 & 0x1f;
  uVar4 = bVar2 & 0xe0;
  if (obj->state == 0) {
    obj->bank = 0x84;
    obj->flip = 0;
    obj->draw_list = 1;
    obj->hitbox = (byte *)0x0;
    obj->box2 = (byte *)0x0;
    obj->dmg_table = 0;
    obj->contact_dmg = 1;
    obj->hp = 0;
    obj->invuln = 0;
    if ((bVar2 & 0xe0) != 0) {
      if ((DAT_801b29a5 & uVar4) == 0) goto LAB_801e573c;
      DAT_801b29a5 = DAT_801b29a5 & ~(byte)uVar4;
    }
    obj->state = obj->state + 1;
  }
  else if (obj->state == 1) {
    iVar3 = FUN_801e5770(obj);
    if (iVar3 != 0) {
      if (((&PTR_DAT_801ea944)[uVar5][(uint)obj->dmg_table * 8 + 4] != -1) &&
         ((&PTR_DAT_801ea944)[uVar5][(uint)obj->dmg_table * 8 + 4] != '\0')) {
        if ((bVar2 & 0xe0) == 0) {
          iVar3 = FUN_801e5850();
          bVar1 = iVar3 < 3;
        }
        else {
          iVar3 = FUN_801e5850();
          bVar1 = iVar3 < 6;
        }
        if (bVar1) {
          FUN_801e58f0(obj);
          obj->hp = 0x16;
          obj->invuln = obj->dmg_table;
        }
      }
      obj->contact_dmg = (&PTR_DAT_801ea944)[uVar5][(uint)obj->dmg_table * 8 + 6];
      if ((&PTR_DAT_801ea944)[uVar5][(uint)obj->dmg_table * 8 + 4] == -1) {
        if ((bVar2 & 0xe0) != 0) {
          obj->state = 0;
        }
        obj->dmg_table = 0;
      }
      else {
        obj->dmg_table = obj->dmg_table + 1;
      }
    }
    if ((obj->hp != 0) && (bVar2 = obj->hp - 1, obj->hp = bVar2, bVar2 == 0)) {
      FUN_801e57a0(obj,obj->invuln);
    }
  }
LAB_801e573c:
  iVar3 = Obj_InActiveArea(obj);
  if (iVar3 == 0) {
    Obj_FreeDespawn(obj);
  }
  return;
}


// ---- 801e5770 FUN_801e5770

bool FUN_801e5770(int param_1)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_1 + 0x45) != '\0';
  if (bVar1) {
    *(char *)(param_1 + 0x45) = *(char *)(param_1 + 0x45) + -1;
  }
  return !bVar1;
}


// ---- 801e57a0 FUN_801e57a0

undefined1 * FUN_801e57a0(int param_1,uint param_2)

{
  undefined1 *puVar1;
  short *psVar2;
  
  psVar2 = (short *)((&PTR_DAT_801ea944)[*(byte *)(param_1 + 7) & 0x1f] + (param_2 & 0xff) * 8);
  puVar1 = (undefined1 *)Obj_AllocMain();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[6] = (char)psVar2[2];
    puVar1[7] = *(undefined1 *)((int)psVar2 + 5);
    *(short *)(puVar1 + 0xe) = *(short *)(param_1 + 0xe) + *psVar2;
    *(short *)(puVar1 + 0x12) = *(short *)(param_1 + 0x12) + psVar2[1];
  }
  return puVar1;
}


// ---- 801e5850 FUN_801e5850

int FUN_801e5850(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar3 = 0x3f;
  pcVar2 = "";
  iVar4 = 0;
  do {
    iVar3 = iVar3 + -1;
    if ((*pcVar2 != '\0') && (pcVar2[6] == '4')) {
      iVar4 = iVar4 + 1;
    }
    pcVar2 = pcVar2 + -0x60;
  } while (-1 < iVar3);
  iVar3 = 0x1f;
  pcVar5 = "";
  pcVar2 = "";
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + -0x50;
    if (((cVar1 != '\0') && (pcVar2[-0x41] == '\x1c')) && (*pcVar2 != '\0')) {
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + -1;
    pcVar2 = pcVar2 + -0x50;
  } while (-1 < iVar3);
  return iVar4;
}


// ---- 801e58f0 FUN_801e58f0

void FUN_801e58f0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_8012c108(param_1,0,0xc,0xfffffff8,0,0);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 7) = 0x10;
    *(char *)(iVar1 + 0x33) = DAT_80159fb8 + '\x01';
  }
  iVar1 = FUN_8012c108(param_1,0,0xfffffff4,0xfffffff8,0,0);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 7) = 0x10;
    *(char *)(iVar1 + 0x33) = DAT_80159fb8 + '\x01';
  }
  return;
}


