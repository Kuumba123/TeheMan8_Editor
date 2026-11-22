// ID 54, STAGE08.BIN, handler 0x801E02E8. Ghidra output with the object struct applied; not matching C.
// ---- 801e02e8 switchD

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void switchD_801e02e8::switchD(MM8Obj *obj)

{
  char cVar1;
  
  (*(code *)(&PTR_FUN_801e1350)[obj->state])();
  if (obj->active != 0) {
    FUN_80107bf4(obj,&g_player,1);
    obj->clut = (&DAT_80159f64)[obj->bank];
    cVar1 = Enemy_CheckWeaponHits(obj);
    if (cVar1 == '\x02') {
      obj->clut = 0;
    }
    else if (cVar1 == '\x04') {
      obj->state = 2;
      obj->field_0x50 = 0x3c;
      Anim_Set(obj,obj->var * '\x03' + '\x02');
    }
    Obj_CullAndQueueDraw(obj);
    cVar1 = Obj_InActiveArea(obj);
    if (cVar1 == '\0') {
      Obj_FreeDespawn(obj);
    }
  }
  return;
}


// ---- 801e03d8 FUN_801e03d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e03d8(MM8Obj *obj)

{
  Enemy_InitFromTable();
  obj->draw_list = 7;
  obj->state = 1;
  obj->flip = 0;
  obj->sub2 = 0;
  obj->sub3 = 0;
  obj->field_0x4 = 0;
  obj->field_0x50 = 0x3c;
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
  obj->hitbox = &UNK_801e133c + (uint)obj->var * 4;
  obj->box2 = &DAT_801e1344 + (uint)obj->var * 5;
  Anim_Set(obj,obj->var * '\x03');
  obj->field_0x50 = 0x3c;
  return;
}


// ---- 801e0480 FUN_801e0480

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0480(MM8Obj *obj)

{
  char cVar1;
  
  if (obj->sub2 == 0) {
    cVar1 = Enemy_ContactDamage();
    if (cVar1 == '\x02') {
      obj->sub2 = 1;
      obj->sub3 = 0;
      obj->field_0x50 = 3;
      Anim_Set(obj,obj->var * '\x03' + '\x01');
      FUN_8010544c(obj,0x199);
      goto LAB_801e0638;
    }
    if (obj->sub3 == 0) {
      cVar1 = obj->field_0x50;
      obj->field_0x50 = cVar1 + -1;
      if (cVar1 == '\0') {
        Anim_Set(obj,obj->var * '\x03' + '\x01');
        FUN_8010544c(obj,0x199);
        obj->sub3 = 1;
      }
      goto LAB_801e0638;
    }
    if ((-1 < (short)obj->frame) || (obj->anim_timer != 1)) goto LAB_801e0638;
    Anim_Set(obj,obj->var * '\x03');
    cVar1 = '<';
    obj->sub3 = 0;
  }
  else {
    cVar1 = Enemy_ContactDamage(obj);
    if (cVar1 == '\x02') {
      obj->field_0x50 = 3;
    }
    if (obj->field_0x50 == '\0') {
      Anim_Set(obj,obj->var * '\x03');
      cVar1 = '<';
      obj->sub2 = 0;
    }
    else {
      if ((-1 < (short)obj->frame) || (obj->anim_timer != 1)) goto LAB_801e0638;
      Anim_Set(obj,obj->var * '\x03' + '\x01');
      FUN_8010544c(obj,0x199);
      cVar1 = obj->field_0x50 + -1;
    }
  }
  obj->field_0x50 = cVar1;
LAB_801e0638:
  Anim_Step(obj);
  return;
}


// ---- 801e0654 FUN_801e0654

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e0654(MM8Obj *obj)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  MM8Obj *pMVar7;
  
  iVar3 = (uint)obj->var * 5;
  if (obj->field_0x50 == '\0') {
    iVar4 = 0;
    pMVar7 = (MM8Obj *)0x0;
    if (obj->var != 0) goto LAB_801e07a0;
    while (pMVar7 = obj, iVar4 < 3) {
LAB_801e07a0:
      while( true ) {
        uVar1 = Rand(pMVar7);
        iVar5 = (int)(char)(&DAT_801e1344)[iVar3];
        iVar6 = iVar5 << 1;
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && ((uVar1 & 0xff) == 0x80000000)) {
          trap(0x1800);
        }
                    /* Possible PsyQ macro: setPolyG3() */
        iVar5 = (int)(uVar1 & 0xff) % iVar6 - iVar5;
        uVar1 = Rand();
        iVar6 = (int)(char)(&DAT_801e1345)[iVar3] << 1;
        if (iVar6 == 0) {
                    /* Possible PsyQ macro: setPolyFT3() + setSemiTrans(polyFT3, 1) */
          trap(0x1c00);
        }
        if ((iVar6 == -1) && ((uVar1 & 0xff) == 0x80000000)) {
          trap(0x1800);
        }
        iVar6 = (int)(char)(&DAT_801e1347)[iVar3] +
                ((int)(uVar1 & 0xff) % iVar6 - (int)(char)(&DAT_801e1345)[iVar3]);
                    /* Probable PsyQ macro: setSprt8() + setSemiTrans(sprt8, 1) + setShadeTex(sprt8,
                       1) */
        FUN_80108ed8(obj,iVar5,iVar6);
        FUN_8012a724(obj,0,iVar5,iVar6);
        iVar4 = iVar4 + 1;
        if (obj->var == 0) break;
        pMVar7 = obj;
        if (5 < iVar4) goto LAB_801e0878;
      }
    }
LAB_801e0878:
    FUN_80108fd8(obj,0);
    Obj_FreeDespawn(obj);
  }
  else {
    obj->field_0x50 = obj->field_0x50 + -1;
    uVar1 = Rand();
    if ((uVar1 & 7) == 7) {
      uVar1 = Rand();
      iVar6 = (int)(char)(&DAT_801e1344)[iVar3];
      iVar4 = iVar6 << 1;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && ((uVar1 & 0xff) == 0x80000000)) {
        trap(0x1800);
      }
      uVar2 = Rand();
      iVar5 = (int)(char)(&DAT_801e1345)[iVar3] << 1;
      if (iVar5 == 0) {
        trap(0x1c00);
      }
      if ((iVar5 == -1) && ((uVar2 & 0xff) == 0x80000000)) {
        trap(0x1800);
      }
      iVar3 = FUN_8012c108(obj,obj,(int)(uVar1 & 0xff) % iVar4 - iVar6,
                           (int)(char)(&DAT_801e1347)[iVar3] +
                           ((int)(uVar2 & 0xff) % iVar5 - (int)(char)(&DAT_801e1345)[iVar3]),0,6);
      if (iVar3 != 0) {
        *(undefined1 *)(iVar3 + 0x26) = 6;
      }
    }
    Anim_Step(obj);
  }
  return;
}


