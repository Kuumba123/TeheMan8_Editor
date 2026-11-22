// ID 2B, STAGE05.BIN, handler 0x801DD2E0. Ghidra output with the object struct applied; not matching C.
// ---- 801dd2e0 FUN_801dd2e0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dd2e0(MM8Obj *obj)

{
  byte bVar1;
  uint in_v0;
  int iVar2;
  short in_v1;
  int unaff_s0;
  
  *(short *)(unaff_s0 + 0x54) = in_v1 + -1;
  if (0x1d < in_v0) {
    *(undefined1 *)(unaff_s0 + 0x57) = 0;
    iVar2 = FUN_80111cb4(2);
    if ((iVar2 == 0) || (DAT_8015e2a3 == '\0')) {
      *(undefined1 *)(unaff_s0 + 2) = 5;
      *(undefined1 *)(unaff_s0 + 3) = 0;
      FUN_80111c28();
      Anim_Set();
      goto LAB_801dd36c;
    }
  }
  bVar1 = FUN_80111858();
  if (bVar1 != 0) {
    FUN_80111c90();
    *(ushort *)(unaff_s0 + 0x54) = *(short *)(unaff_s0 + 0x54) - (ushort)bVar1;
  }
LAB_801dd36c:
  Anim_Step();
  return;
}


