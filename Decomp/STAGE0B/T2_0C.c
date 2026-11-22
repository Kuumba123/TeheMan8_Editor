// T2_0C, STAGE0B.BIN, handler 0x801E4E7C. Ghidra output with the object struct applied; not matching C.
// ---- 801e4e7c FUN_801e4e7c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4e7c(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e87b8)[obj->state])();
  return;
}


// ---- 801e4eb8 FUN_801e4eb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e4eb8(MM8Obj *obj)

{
  byte bVar1;
  int iVar2;
  
                    /* Possible PsyQ macro: setPolyFT4() */
  obj->bank = 0x2c;
  obj->vram_base = DAT_801703a0;
  bVar1 = DAT_80159f90;
  obj->field_0x4a = 0;
                    /* Possible PsyQ macro: setPolyGT4() */
  obj->field_0x4b = 0;
  obj->clut = bVar1;
  if ((obj->var & 0x80) == 0) {
    iVar2 = FUN_80105dbc(obj,0xc);
    if (iVar2 == 0) {
      obj->draw_list = 5;
                    /* Possible PsyQ macro: setLineF2() */
      obj->flip = 0x40;
      obj->state = 1;
      obj->contact_dmg = 0;
      obj->box2 = &DAT_801e87b0;
      obj->invuln = 0;
      if (obj->var != 0) {
        Anim_Set(obj,5);
        FUN_80111ea0();
        if (DAT_801c336e == '\v') {
          DAT_801d2915 = 1;
          DAT_801d293a = 1;
          DAT_801d293c = 0;
          obj->invuln = 1;
          DAT_801d2975 = 3;
          DAT_801d298e = 3;
          DAT_801d2986 = 0x1e00;
          DAT_801d2988 = 0x200;
          DAT_801d298a = 0x1c00;
          DAT_801d298c = 0x1c00;
          DAT_801d2984 = DAT_801d297c;
        }
      }
      DAT_801b2994 = 1;
    }
    else {
      Obj_Free(obj);
    }
  }
  else if (obj->var == 0xff) {
    obj->state = 6;
    obj->draw_list = 6;
                    /* Possible PsyQ macro: setLineF2() */
    obj->flip = 0x40;
    Anim_Set(obj,4);
    Obj_CullAndQueueDraw(obj);
  }
  else {
    obj->state = 7;
    obj->draw_list = 4;
                    /* Possible PsyQ macro: setLineF2() */
    obj->flip = 0x40;
    Anim_Set(obj,10);
  }
  return;
}


// ---- 801e507c FUN_801e507c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e507c(MM8Obj *obj)

{
  int iVar1;
  
  if (obj->var == 0) {
    iVar1 = 0xf28;
    if (DAT_801c336e == '\v') {
      iVar1 = 0xb58;
    }
    if (iVar1 < DAT_8015e248._2_2_) {
      FUN_801119e0((int)DAT_8015e248._2_2_,0x40);
      obj->state = 2;
      obj->y = g_cam_y + -0x20;
    }
  }
  else if (DAT_8015e241 != '\0') {
    obj->state = 4;
    FUN_801e60c4();
  }
  return;
}


// ---- 801e5128 FUN_801e5128

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5128(MM8Obj *obj)

{
  (*(code *)(&PTR_LAB_801e87d8)[obj->sub2])();
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e5334 FUN_801e5334

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5334(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e87e8)[obj->sub2])();
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e5384 FUN_801e5384

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5384(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80107bf4(obj,&g_player,6);
  if (DAT_8015e2b0 != '\0') {
    Anim_Set(obj,5);
    obj->sub2 = 1;
    iVar1 = 0x20000;
    if (DAT_801c336e == '\v') {
      iVar1 = 0x10000;
    }
    obj->speed_x = iVar1;
    obj->speed_y_up = 0;
    obj->dmg_table = 0x78;
  }
  return;
}


// ---- 801e5404 FUN_801e5404

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5404(MM8Obj *obj)

{
  FUN_801e5b40();
  FUN_80104c34(obj);
  FUN_80107bf4(obj,&g_player,6);
  Anim_Step(obj);
                    /* Possible PsyQ macro: setPolyFT4() */
  if (0xa0 < (int)obj->x - (int)DAT_801d2918._2_2_) {
    obj->sub2 = 2;
    obj->dmg_table = 0x1e;
    if (DAT_801c336e != '\v') {
      DAT_801d2975 = 3;
      DAT_801d298e = 1;
                    /* Possible PsyQ macro: setLineF2() */
      DAT_801d2986 = 0x1d00;
      DAT_801d2988 = 0x100;
      DAT_801d298a = 0x1c00;
      DAT_801d298c = 0x1c00;
                    /* Possible PsyQ macro: setLineF2() */
      DAT_801d2984 = DAT_801d297c;
    }
  }
  return;
}


// ---- 801e54e0 FUN_801e54e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e54e0(MM8Obj *obj)

{
  short sVar1;
  undefined2 uVar2;
  
  if (DAT_801c336e == '\v') {
    sVar1 = 0xbb0;
    uVar2 = 1;
                    /* Possible PsyQ macro: setLineF2() */
  }
  else {
    sVar1 = 0xf80;
    uVar2 = 4;
  }
  FUN_80104c34(obj);
  FUN_801e5b40(obj);
  FUN_80107bf4(obj,&g_player,6);
  Anim_Step(obj);
  if (sVar1 < DAT_801d2918._2_2_) {
    obj->state = 4;
    obj->sub2 = 0;
    FUN_80111ea0();
    DAT_801d2915 = 1;
    DAT_801d293c = 0;
    DAT_801b2996 = 1;
    DAT_801d293a = uVar2;
  }
  return;
}


// ---- 801e55ac FUN_801e55ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e55ac(MM8Obj *obj)

{
  FUN_801e5b40(&g_player);
  obj->x = DAT_8015e248._2_2_ + 8;
  obj->y = DAT_8015e24c._2_2_ + 0x12;
  FUN_801e6434(obj);
  if (DAT_801c336e == '\v') {
    FUN_801e611c(obj);
  }
  else if (obj->var == 2) {
    FUN_801e5c90(obj);
  }
  else {
    FUN_801e5bc0(obj);
  }
  FUN_801e5a6c(obj);
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e5670 FUN_801e5670

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5670(MM8Obj *obj)

{
  (*(code *)(&PTR_FUN_801e87f4)[obj->sub2])();
  Anim_Step(obj);
  Obj_CullAndQueueDraw(obj);
  return;
}


// ---- 801e56c8 FUN_801e56c8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e56c8(MM8Obj *obj)

{
  obj->sub2 = 1;
  DAT_8015e2cf = 1;
  FUN_801e5b90();
  DAT_801d293a = 2;
  obj->speed_x = 0x20000;
  obj->speed_y_up = 0;
  return;
}


// ---- 801e571c FUN_801e571c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e571c(MM8Obj *obj)

{
  int iVar1;
  
  FUN_80104c34();
  FUN_801e5b40(obj);
  iVar1 = (int)(((uint)(ushort)obj->x - (uint)DAT_801d2918._2_2_) * 0x10000) >> 0x10;
  if (0xa0 < iVar1) {
    obj->x = obj->x - 1;
  }
  if (iVar1 < 0x90) {
    obj->x = obj->x + 1;
  }
  iVar1 = (int)(((uint)(ushort)obj->y - (uint)g_cam_y) * 0x10000) >> 0x10;
  if (0x80 < iVar1) {
    obj->y = obj->y - 1;
  }
  if (iVar1 < 0x70) {
    obj->y = obj->y + 1;
  }
  FUN_801e5b90(obj);
  if (DAT_801d2918._2_2_ == DAT_801d2926) {
    obj->sub2 = 2;
    DAT_801d2915 = 0;
    DAT_801d293a = 0;
    DAT_801d295e = 0xffff;
    DAT_801d2928 = DAT_801d2926;
    DAT_801d2930 = DAT_801d2926;
  }
  return;
}


// ---- 801e5840 FUN_801e5840

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e5840(MM8Obj *obj)

{
  FUN_80104c34();
  FUN_801e5b40(obj);
  FUN_801e5b90(obj);
  if (*(short *)&obj->target_prio < obj->x) {
    obj->sub2 = 3;
    obj->speed_y_up = -0x20000;
    obj->box2 = &DAT_801e87b0;
    obj->speed_x = 0;
    obj->field_0x43 = 1;
  }
  return;
}


// ---- 801e58b4 FUN_801e58b4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e58b4(MM8Obj *obj)

{
  FUN_80104c34();
  FUN_801e5b40(obj);
  FUN_80106214(obj);
  FUN_801e5b90(obj);
  if ((obj->field_0x33 & 0x80) != 0) {
    obj->sub2 = 4;
    FUN_80111af0();
    FUN_801119e0((int)DAT_8015e248._2_2_,0x40);
    Anim_Set(obj,7);
    Obj_Free(*(undefined4 *)&obj->field_0x4c);
    FUN_8010544c(obj,6);
  }
  return;
}


// ---- 801e59c4 FUN_801e59c4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e59c4(MM8Obj *obj)

{
  obj->x = *(short *)(*(int *)&obj->field_0x4c + 0xe);
  obj->y = *(short *)(*(int *)&obj->field_0x4c + 0x12);
  Obj_CullAndQueueDraw();
  return;
}


// ---- 801e59fc FUN_801e59fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e59fc(MM8Obj *obj)

{
  if ((short)obj->frame < 0) {
    Obj_Free();
  }
  else {
    obj->x = *(short *)(*(int *)&obj->field_0x4c + 0xe);
    obj->y = *(short *)(*(int *)&obj->field_0x4c + 0x12);
    Anim_Step(obj);
    Obj_CullAndQueueDraw(obj);
  }
  return;
}


// ---- 801e5a6c FUN_801e5a6c

void FUN_801e5a6c(int param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  
  if ((*(byte *)(param_1 + 0x45) < 2) && (DAT_8015e23d == '\x02')) {
    if (*(byte *)(param_1 + 0x45) == 0) {
      bVar1 = DAT_8015e283 < 0x15;
    }
    else {
      bVar1 = DAT_8015e283 < 0xb;
    }
    if ((bVar1) && (puVar2 = (undefined1 *)Obj_AllocMain(), puVar2 != (undefined1 *)0x0)) {
      *(char *)(param_1 + 0x45) = *(char *)(param_1 + 0x45) + '\x01';
      *puVar2 = 1;
      puVar2[6] = 3;
      puVar2[7] = 0x11;
      *(short *)(puVar2 + 0xe) = DAT_801d2918._2_2_ + 0x160;
      *(short *)(puVar2 + 0x12) = g_cam_y + 0x68;
    }
  }
  return;
}


// ---- 801e5b40 FUN_801e5b40

void FUN_801e5b40(int param_1)

{
  if ((DAT_80170574 & 7) == 0) {
    if ((DAT_80170574 & 0x10) == 0) {
      *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + -1;
    }
    else {
      *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 1;
    }
  }
  return;
}


// ---- 801e5b90 FUN_801e5b90

void FUN_801e5b90(int param_1)

{
  DAT_8015e248._2_2_ = *(short *)(param_1 + 0xe) + -8;
  DAT_8015e24c._2_2_ = *(short *)(param_1 + 0x12) + -0x12;
  return;
}


// ---- 801e5bc0 FUN_801e5bc0

void FUN_801e5bc0(void)

{
  short sVar1;
  short sVar2;
  
  if (0x1d00 < DAT_801d2918._2_2_) {
    sVar2 = -0x1c00;
    if (g_cam_y < 0xc00) {
      sVar1 = 0x600;
    }
    else {
      sVar2 = -0x800;
      sVar1 = 0;
    }
    DAT_801d2928 = 0x100;
    DAT_801d2930 = 0x100;
    DAT_801d2926 = 0x1f00;
    DAT_801d292e = 0x1f00;
    DAT_801d2918._2_2_ = sVar2 + DAT_801d2918._2_2_;
    g_cam_y = sVar1 + g_cam_y;
    DAT_801d291e = sVar2 + DAT_801d291e;
    DAT_801d292a = sVar1 + DAT_801d292a;
    DAT_801d2920 = sVar1 + DAT_801d2920;
    DAT_801d292c = DAT_801d292a;
    DAT_801d2932 = DAT_801d292a;
    DAT_801d2934 = DAT_801d292a;
    FUN_80105f18((int)sVar2,sVar1);
  }
  return;
}


// ---- 801e5c90 FUN_801e5c90

void FUN_801e5c90(int param_1)

{
  if ((DAT_80170574 & 1) == 0) {
    DAT_801d293a = 1;
  }
  else {
    DAT_801d293a = 0;
    *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + -1;
  }
  (*(code *)(&PTR_LAB_801e880c)[*(byte *)(param_1 + 4)])();
  return;
}


// ---- 801e60c4 FUN_801e60c4

void FUN_801e60c4(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_80105734();
  if (puVar1 == (undefined1 *)0x0) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  else {
    *puVar1 = 1;
    puVar1[6] = 0xc;
    puVar1[7] = 0xff;
    *(int *)(puVar1 + 0x4c) = param_1;
    *(undefined1 **)(param_1 + 0x4c) = puVar1;
  }
  return;
}


// ---- 801e611c FUN_801e611c

void FUN_801e611c(int param_1)

{
  short sVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = (uint)*(byte *)(param_1 + 0x46) * 2;
  if (*(short *)(&DAT_801e8798 + iVar4) < DAT_801d2918._2_2_) {
    sVar1 = *(short *)(&DAT_801e87a0 + iVar4);
    sVar2 = *(short *)(&DAT_801e87a8 + iVar4);
    DAT_801d2926 = 0x1f00;
    DAT_801d292e = 0x1f00;
    DAT_801d2928 = 0x100;
    DAT_801d2930 = 0x100;
    DAT_801d2918._2_2_ = sVar1 + DAT_801d2918._2_2_;
    DAT_801d291e = sVar1 + DAT_801d291e;
    g_cam_y = sVar2 + g_cam_y;
    DAT_801d2920 = sVar2 + DAT_801d2920;
    DAT_801d292a = sVar2 + DAT_801d292a;
    DAT_801d292c = DAT_801d292a;
    DAT_801d2932 = DAT_801d292a;
    DAT_801d2934 = DAT_801d292a;
    FUN_80105f18((int)sVar1,(int)sVar2);
    if (*(byte *)(param_1 + 0x46) < 2) {
      DAT_801c3377 = *(char *)(param_1 + 0x46) + '\x03';
      FUN_8011c504();
      *(char *)(param_1 + 0x46) = *(char *)(param_1 + 0x46) + '\x01';
      FUN_80101dbc();
      FUN_80101bf0();
      cVar3 = *(char *)(param_1 + 0x46);
      if (cVar3 != '\x02') goto LAB_801e6330;
      DAT_801d2958 = 0x200;
      DAT_801d2988 = 0x200;
      DAT_801d2945 = 3;
      DAT_801d2975 = 3;
      DAT_801d295e = 8;
      DAT_801d2956 = 0x1d00;
      DAT_801d295a = 0x1b00;
      DAT_801d295c = 0x1b00;
      DAT_801d298e = 4;
      DAT_801d2986 = 0x1e00;
      DAT_801d298a = 0x1c00;
      DAT_801d298c = 0x1c00;
      DAT_801d2954 = DAT_801d294c;
      DAT_801d2984 = DAT_801d297c;
    }
  }
  cVar3 = *(char *)(param_1 + 0x46);
LAB_801e6330:
  if ((cVar3 == '\x01') && (0x15ff < DAT_801d2918._2_2_)) {
    iVar4 = (DAT_801d2918._2_2_ + -0x1600) * 0x10000 >> 0x10;
    if (iVar4 < 0x301) {
      if (iVar4 < 0x201) {
        if (iVar4 < 0x101) {
          if (iVar4 < 0) {
            return;
          }
          DAT_801d298e = 1;
        }
        else {
          DAT_801d298e = 2;
        }
      }
      else {
        DAT_801d298e = 3;
      }
    }
    else {
      DAT_801d298e = 4;
    }
    DAT_801d2975 = 3;
    DAT_801d2986 = 0x1e00;
    DAT_801d2988 = 0x200;
    DAT_801d298a = 0x1c00;
    DAT_801d298c = 0x1c00;
    DAT_801d2984 = DAT_801d297c;
  }
  return;
}


// ---- 801e6434 FUN_801e6434

void FUN_801e6434(int param_1)

{
  undefined1 *puVar1;
  byte bVar2;
  
  if (*(char *)(param_1 + 0x4a) == '\0') {
    if (*(char *)(param_1 + 0x4b) == '\0') {
      if ((DAT_801b29a0 & DAT_80139549) != 0) {
        *(undefined1 *)(param_1 + 0x4b) = 5;
        puVar1 = (undefined1 *)FUN_80105734();
        if (puVar1 != (undefined1 *)0x0) {
          *puVar1 = 1;
          puVar1[6] = 0xc;
          puVar1[7] = 0x80;
          *(int *)(puVar1 + 0x4c) = param_1;
          FUN_800fd100(0x4c);
        }
      }
    }
    else {
      *(char *)(param_1 + 0x4b) = *(char *)(param_1 + 0x4b) + -1;
      if (*(char *)(param_1 + 0x4b) == '\0') {
        *(undefined1 *)(param_1 + 0x4a) = 1;
        Anim_Set(param_1,8);
        if (*(int *)(param_1 + 0x4c) != 0) {
          Anim_Set(*(int *)(param_1 + 0x4c),9);
        }
      }
    }
  }
  else {
                    /* Possible PsyQ macro: setPolyG4() */
    if (*(char *)(param_1 + 0x4b) == '\0') {
      bVar2 = 0;
      if ((DAT_8015e294 & 0x90) != 0) {
        do {
          puVar1 = (undefined1 *)FUN_80105628();
          if (puVar1 != (undefined1 *)0x0) {
            *puVar1 = 1;
            puVar1[6] = 0x13;
            puVar1[7] = bVar2;
            *(short *)(puVar1 + 0xe) = *(short *)(param_1 + 0xe) + 0x17;
            *(short *)(puVar1 + 0x12) = *(short *)(param_1 + 0x12) + 0xd;
          }
          bVar2 = bVar2 + 1;
        } while (bVar2 < 3);
                    /* Possible PsyQ macro: setPolyF4() */
        *(undefined1 *)(param_1 + 0x4b) = 0x28;
      }
    }
    else {
      *(char *)(param_1 + 0x4b) = *(char *)(param_1 + 0x4b) + -1;
    }
  }
  return;
}


