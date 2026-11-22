// ID 42, STAGE06.BIN, handler 0x801E16A8. Ghidra output with the object struct applied; not matching C.
// ---- 801e16a8 FUN_801e16a8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801e16a8(MM8Obj *obj)

{
  char cVar1;
  short sVar2;
  int iVar3;
  
  if (obj->state == 0) {
    Enemy_InitFromTable();
    obj->draw_list = 8;
    obj->hitbox = &DAT_801e5b10;
    obj->box2 = &DAT_801e5b14;
    obj->flip = 0;
    obj->field_0x43 = 0;
    obj->state = obj->state + 1;
    if ((((obj->var & 0x80) != 0) && (obj->y < DAT_801b2988)) ||
       (((obj->var & 0x40) != 0 && ((int)DAT_801b2988 < obj->y + -0x20)))) goto LAB_801e1880;
    Anim_Set(obj,0);
  }
  FUN_80104ccc(obj);
  cVar1 = FUN_801e18e0(obj);
  if (cVar1 != '\0') {
    if (obj->var == 0) {
      sVar2 = obj->y + 1;
    }
    else {
      iVar3 = switchD_801e1970::caseD_2(obj);
      if ((iVar3 == 0) || ((obj->field_0x33 & 0x40) != 0)) goto LAB_801e17d8;
      sVar2 = obj->y + -1;
    }
    obj->y = sVar2;
  }
LAB_801e17d8:
  FUN_80106214(obj);
  obj->field_0x43 = (byte)obj->field_0x33 >> 7 ^ 1;
  FUN_80107bf4(obj,&g_player,6);
  Enemy_ContactDamage(obj);
  if ((cVar1 == '\0') && ((obj->field_0x33 & 0xc0) == 0)) {
    if ((obj->speed_y_up == 0) && (obj->gravity == 0)) {
      obj->speed_y_up = 0x2000;
      obj->gravity = 0x100;
    }
    FUN_801e18b0(obj);
  }
  else {
    obj->speed_y_up = 0;
    obj->gravity = 0;
  }
  iVar3 = Obj_InActiveArea(obj);
  if (iVar3 != 0) {
    Obj_CullAndQueueDraw(obj);
    return;
  }
LAB_801e1880:
  Obj_FreeDespawn(obj);
  return;
}


// ---- 801e18b0 FUN_801e18b0

void FUN_801e18b0(int param_1)

{
  if (0x4000 < *(int *)(param_1 + 0x18) + 0x2000U) {
    *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
  }
  return;
}


// ---- 801e18e0 FUN_801e18e0

bool FUN_801e18e0(void)

{
  char cVar1;
  
  cVar1 = Enemy_CheckWeaponHits();
  return cVar1 == '\x01' && DAT_80158f5c == '\x05';
}


// ---- 801e19c4 caseD_2

bool switchD_801e1970::caseD_2(int param_1)

{
  return DAT_801b2988 <= *(short *)(param_1 + 0x12);
}


