// ID 31, STAGE04.BIN, handler 0x801DBE40. Ghidra output with the object struct applied; not matching C.
// ---- 801dbe40 FUN_801dbe40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_801dbe40(MM8Obj *obj)

{
  int unaff_s1;
  int unaff_s3;
  
  if (unaff_s3 != 0) {
    FUN_80109804();
    if ((*(byte *)(unaff_s1 + 0x50) & 1) != 0) {
      *(short *)(unaff_s1 + 0x12) = *(short *)(unaff_s1 + 0x12) + 2;
    }
    Obj_CullAndQueueDraw();
  }
  return;
}


