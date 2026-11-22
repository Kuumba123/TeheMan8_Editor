// ID 24, STAGE04.BIN, handler 0x801DE12C. Ghidra output with the object struct applied; not matching C.
// ---- 801de12c FUN_801de12c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de12c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e70a4)[obj->state])();
  return;
}


// ---- 801de168 FUN_801de168

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de168(MM8Obj *obj)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
                    /* Possible PsyQ macro: setLineF2() */
  Enemy_InitFromTable();
  obj->state = 1;
  obj->hitbox = &DAT_801e6edc;
  obj->accel_x = 0xc;
  obj->hp = obj->hp & 0xf;
  uVar5._0_2_ = obj->x_frac;
  uVar5._2_2_ = obj->x;
  obj->flip = 0;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->box2 = (byte *)0x0;
  obj->speed_x = uVar5 & 0xfff00000;
  uVar2._0_2_ = obj->y_frac;
  uVar2._2_2_ = obj->y;
  obj->speed_y_up = uVar2 & 0xfff00000;
  uVar5 = 0;
  if (*(short *)(&DAT_801e6fec + (uint)obj->var * 8) != 0) {
    uVar2 = 0;
    do {
      iVar4 = (int)uVar5 >> 1;
      if (uVar2 == 0) {
        bVar3 = (&obj->field_0x50)[iVar4] & 0xf;
        (&obj->field_0x50)[iVar4] = bVar3;
        bVar1 = obj->hp << 4;
      }
      else {
        bVar3 = (&obj->field_0x50)[iVar4] & 0xf0;
        (&obj->field_0x50)[iVar4] = bVar3;
        bVar1 = obj->hp & 0xf;
      }
      (&obj->field_0x50)[iVar4] = bVar3 | bVar1;
      uVar5 = uVar5 + 1;
      uVar2 = uVar5 & 1;
    } while ((int)uVar5 < (int)(uint)*(ushort *)(&DAT_801e6fec + (uint)obj->var * 8));
  }
  return;
}


// ---- 801de288 FUN_801de288

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801de288(MM8Obj *obj)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  byte bVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  char *pcVar14;
  uint uVar15;
  uint uVar16;
  
  uVar1 = *(undefined2 *)((int)&obj->speed_x + 2);
  uVar2 = *(undefined2 *)&obj->speed_y_up;
  uVar3 = *(undefined2 *)((int)&obj->speed_y_up + 2);
  iVar10 = (uint)obj->var * 8;
  obj->x_frac = *(undefined2 *)&obj->speed_x;
  obj->x = uVar1;
  obj->y_frac = uVar2;
  obj->y = uVar3;
  uVar16 = (uint)*(ushort *)(&DAT_801e6fec + iVar10);
  uVar1 = *(undefined2 *)(&DAT_801e6fee + iVar10);
  iVar10 = *(int *)(&LAB_801e6ff0 + iVar10);
  uVar15 = 0;
  if (uVar16 != 0) {
    do {
      if ((uVar15 & 1) == 0) {
        bVar6 = (byte)(&obj->field_0x50)[(uVar15 & 0xff) >> 1] >> 4;
      }
      else {
        bVar6 = (&obj->field_0x50)[(uVar15 & 0xff) >> 1] & 0xf;
      }
      obj->hp = bVar6;
      if ((bVar6 != 0) && (obj->hp != 0xf)) {
        uVar2 = *(undefined2 *)((int)&obj->speed_x + 2);
        uVar3 = *(undefined2 *)&obj->speed_y_up;
        uVar4 = *(undefined2 *)((int)&obj->speed_y_up + 2);
        pcVar14 = (char *)((uVar15 & 0xff) * 2 + iVar10);
        obj->x_frac = *(undefined2 *)&obj->speed_x;
        obj->x = uVar2;
        obj->y_frac = uVar3;
        obj->y = uVar4;
        obj->x = obj->x + *pcVar14 * 0x20;
                    /* Possible PsyQ macro: setLineF2() */
        sVar9 = obj->y + pcVar14[1] * 0x20;
        obj->y = sVar9;
        cVar5 = FUN_80107204((int)obj->x,(int)(short)(sVar9 + 0x10));
                    /* Possible PsyQ macro: setPolyF4() */
        if ((cVar5 == '\0') ||
           (cVar5 = FUN_80107204((int)obj->x,(int)(((ushort)obj->y + 0x10) * 0x10000) >> 0x10),
           cVar5 == '?')) {
          uVar11 = (uVar15 & 0xff) >> 1;
          if ((uVar15 & 1) == 0) {
            bVar6 = (&obj->field_0x50)[uVar11] | 0xf0;
          }
          else {
            bVar6 = (&obj->field_0x50)[uVar11] | 0xf;
          }
          (&obj->field_0x50)[uVar11] = bVar6;
        }
      }
      uVar15 = uVar15 + 1;
    } while ((uVar15 & 0xff) < uVar16);
    uVar15 = 0;
    if (uVar16 != 0) {
      uVar11 = 0;
      do {
        if (uVar11 == 0) {
          bVar6 = (byte)(&obj->field_0x50)[(uVar15 & 0xff) >> 1] >> 4;
        }
        else {
          bVar6 = (&obj->field_0x50)[(uVar15 & 0xff) >> 1] & 0xf;
        }
        obj->hp = bVar6;
        if (bVar6 != 0xf) {
          uVar11 = uVar15 & 0xff;
          uVar2 = *(undefined2 *)((int)&obj->speed_x + 2);
          uVar3 = *(undefined2 *)&obj->speed_y_up;
          uVar4 = *(undefined2 *)((int)&obj->speed_y_up + 2);
          pcVar14 = (char *)(uVar11 * 2 + iVar10);
          obj->x_frac = *(undefined2 *)&obj->speed_x;
          obj->x = uVar2;
          obj->y_frac = uVar3;
          obj->y = uVar4;
          obj->x = obj->x + *pcVar14 * 0x20;
          obj->y = obj->y + pcVar14[1] * 0x20;
          cVar5 = Obj_InActiveArea(obj);
          if (cVar5 != '\0') {
            obj->on_screen = 1;
            cVar5 = Enemy_CheckWeaponHits(obj);
            obj->on_screen = 0;
            if ((uVar15 & 1) == 0) {
              pbVar12 = &obj->active + (uVar11 >> 1);
              bVar8 = pbVar12[0x50] & 0xf;
              pbVar12[0x50] = bVar8;
              bVar6 = obj->hp << 4;
            }
            else {
              pbVar12 = &obj->active + (uVar11 >> 1);
              bVar8 = pbVar12[0x50] & 0xf0;
              pbVar12[0x50] = bVar8;
              bVar6 = obj->hp & 0xf;
            }
            pbVar12[0x50] = bVar8 | bVar6;
            if (cVar5 == '\x04') {
              FUN_801de808(obj,(int)obj->x,(int)obj->y,uVar1);
              if ((uVar15 & 1) == 0) {
                pbVar12 = &obj->active + ((uVar15 & 0xff) >> 1);
                bVar6 = pbVar12[0x50] | 0xf0;
              }
              else {
                pbVar12 = &obj->active + ((uVar15 & 0xff) >> 1);
                bVar6 = pbVar12[0x50] | 0xf;
              }
              pbVar12[0x50] = bVar6;
              obj->accel_x = 0xc;
            }
          }
        }
        uVar15 = uVar15 + 1;
        uVar11 = uVar15 & 1;
      } while ((uVar15 & 0xff) < uVar16);
    }
  }
  iVar13 = obj->accel_x;
  obj->accel_x = iVar13 + -1;
  if (iVar13 == 0) {
    obj->accel_x = 0xc;
    uVar15 = 0;
    if (uVar16 != 0) {
      uVar11 = 0;
      do {
        if (uVar11 == 0) {
          bVar6 = (byte)(&obj->field_0x50)[(uVar15 & 0xff) >> 1] >> 4;
        }
        else {
          bVar6 = (&obj->field_0x50)[(uVar15 & 0xff) >> 1] & 0xf;
        }
        obj->hp = bVar6;
        if (obj->hp == 0xf) {
          uVar1 = *(undefined2 *)((int)&obj->speed_x + 2);
          uVar2 = *(undefined2 *)&obj->speed_y_up;
          uVar3 = *(undefined2 *)((int)&obj->speed_y_up + 2);
          pcVar14 = (char *)((uVar15 & 0xff) * 2 + iVar10);
          obj->x_frac = *(undefined2 *)&obj->speed_x;
          obj->x = uVar1;
          obj->y_frac = uVar2;
          obj->y = uVar3;
          obj->x = obj->x + *pcVar14 * 0x20;
          obj->y = obj->y + pcVar14[1] * 0x20;
          FUN_801de73c(obj);
          uVar11 = (uVar15 & 0xff) >> 1;
          if ((uVar15 & 1) == 0) {
            bVar6 = (&obj->field_0x50)[uVar11] & 0xf;
          }
          else {
            bVar6 = (&obj->field_0x50)[uVar11] & 0xf0;
          }
          (&obj->field_0x50)[uVar11] = bVar6;
        }
        uVar15 = uVar15 + 1;
        uVar11 = uVar15 & 1;
      } while ((uVar15 & 0xff) < uVar16);
    }
  }
  uVar15 = 0;
  uVar11 = 0;
  if (uVar16 != 0) {
    uVar7 = 0;
    do {
      if (uVar7 == 0) {
        bVar6 = (byte)(&obj->field_0x50)[(uVar11 & 0xff) >> 1] >> 4;
      }
      else {
        bVar6 = (&obj->field_0x50)[(uVar11 & 0xff) >> 1] & 0xf;
      }
      uVar11 = uVar11 + 1;
      if (bVar6 == 0) {
        uVar15 = uVar15 + 1;
      }
      uVar7 = uVar11 & 1;
    } while ((uVar11 & 0xff) < uVar16);
  }
  if ((uVar15 & 0xff) == uVar16) {
    Obj_Free(obj);
  }
  else {
    uVar1 = *(undefined2 *)((int)&obj->speed_x + 2);
    uVar2 = *(undefined2 *)&obj->speed_y_up;
    uVar3 = *(undefined2 *)((int)&obj->speed_y_up + 2);
    obj->x_frac = *(undefined2 *)&obj->speed_x;
    obj->x = uVar1;
    obj->y_frac = uVar2;
    obj->y = uVar3;
  }
  return;
}


// ---- 801de73c FUN_801de73c

void FUN_801de73c(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 0xe);
  iVar3 = (int)*(short *)(param_1 + 0x12);
  uVar2 = *(undefined2 *)(&DAT_801e6fee + (uint)*(byte *)(param_1 + 7) * 8);
  FUN_801de808(param_1,(int)((uVar1 - 0x20) * 0x10000) >> 0x10,iVar3,uVar2);
  FUN_801de808(param_1,(int)((uVar1 + 0x20) * 0x10000) >> 0x10,iVar3,uVar2);
  FUN_801de808(param_1,(int)(short)uVar1,(iVar3 + -0x20) * 0x10000 >> 0x10,uVar2);
  FUN_801de808(param_1,(int)(short)uVar1,(iVar3 + 0x20) * 0x10000 >> 0x10,uVar2);
  return;
}


// ---- 801de808 FUN_801de808

void FUN_801de808(int param_1,short param_2,int param_3,ushort param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char cVar9;
  char local_40;
  
  if (param_4 == 2) {
    local_40 = ':';
    cVar9 = '9';
  }
  else {
    local_40 = '9';
    cVar9 = ':';
  }
  iVar6 = (int)param_2;
  cVar1 = FUN_80107204(iVar6,(param_3 + 0x10) * 0x10000 >> 0x10);
  if (cVar1 != local_40) {
    return;
  }
  iVar8 = (param_3 + -0x10) * 0x10000 >> 0x10;
  cVar2 = FUN_80107204(iVar6,iVar8);
  cVar3 = FUN_80107204(iVar6,(param_3 + 0x30) * 0x10000 >> 0x10);
  cVar4 = FUN_80107204(iVar6,(param_3 + 0x40) * 0x10000 >> 0x10);
  if (cVar2 == '\0') {
    FUN_80102ef4(0xb,iVar6,iVar8);
LAB_801de9c0:
    uVar5 = 0xb;
    iVar8 = param_3 << 0x10;
LAB_801de9c8:
    FUN_80102ef4(uVar5,iVar6,iVar8 >> 0x10);
  }
  else {
    if (cVar2 != cVar1) {
      if (cVar2 != cVar9) goto LAB_801de9c0;
      if (param_4 == 1) {
        uVar5 = 0xf;
        iVar8 = (param_3 + -0x20) * 0x10000;
      }
      else {
        uVar5 = 0x10;
        if (param_4 != 2) goto LAB_801de9d0;
        iVar8 = (param_3 + -0x20) * 0x10000;
      }
      goto LAB_801de9c8;
    }
    if (param_4 == 1) {
      uVar5 = 0x10;
      iVar8 = (param_3 + -0x20) * 0x10000;
      goto LAB_801de9c8;
    }
    if (param_4 < 2) {
      uVar5 = 0x12;
      if (param_4 == 0) {
        iVar8 = (param_3 + -0x20) * 0x10000;
        goto LAB_801de9c8;
      }
    }
    else {
      uVar5 = 0xf;
      if (param_4 == 2) {
        iVar8 = (param_3 + -0x20) * 0x10000;
        goto LAB_801de9c8;
      }
    }
  }
LAB_801de9d0:
  if (cVar4 == '?') {
    uVar5 = 0x13;
LAB_801deab0:
    FUN_80102ef4(uVar5,(int)param_2,(param_3 + 0x10) * 0x10000 >> 0x10);
    uVar5 = 0xb;
    iVar6 = (param_3 + 0x20) * 0x10000;
  }
  else if (cVar3 == local_40) {
    if (param_4 == 1) {
      uVar5 = 0xe;
      iVar6 = param_3 << 0x10;
    }
    else if (param_4 < 2) {
      uVar5 = 0x11;
      if (param_4 != 0) goto LAB_801deae8;
      iVar6 = param_3 << 0x10;
    }
    else {
      uVar5 = 0xd;
      if (param_4 != 2) goto LAB_801deae8;
      iVar6 = param_3 << 0x10;
    }
  }
  else if (cVar3 == cVar9) {
    uVar5 = 0xd;
    iVar6 = param_3 << 0x10;
  }
  else {
    if (cVar3 != '=') {
      if ((cVar3 != '\0') && (cVar3 != '?')) goto LAB_801deae8;
      uVar5 = 0xb;
      goto LAB_801deab0;
    }
    uVar5 = 0xc;
    iVar6 = param_3 << 0x10;
  }
  FUN_80102ef4(uVar5,(int)param_2,iVar6 >> 0x10);
LAB_801deae8:
  uVar5 = *(undefined4 *)(param_1 + 0xc);
  uVar7 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(short *)(param_1 + 0xe) = param_2;
  *(short *)(param_1 + 0x12) = (short)param_3;
  iVar6 = FUN_8012c108(param_1,0,0x10,0x10,10,0);
  if (iVar6 != 0) {
                    /* Possible PsyQ macro: setPolyGT3() */
    *(undefined1 *)(iVar6 + 0x27) = 0x34;
    *(undefined1 *)(iVar6 + 0x26) = 6;
    *(undefined1 *)(iVar6 + 7) = 0x10;
  }
  FUN_8012a5fc(param_1,0);
  *(undefined4 *)(param_1 + 0xc) = uVar5;
  *(undefined4 *)(param_1 + 0x10) = uVar7;
  return;
}


