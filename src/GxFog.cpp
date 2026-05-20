// Class implementation: GxFog

// =================================================
// Function: GxFog::GxFog
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GxFog::GxFog(GxFog *this,GxFog *param_1)
{
{
  undefined4 uVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined ***)this = vftable;
  uVar1 = _DAT_00b3d268;
  *(undefined4 *)(this + 0x14) = 1;
  *(undefined4 *)(this + 0x20) = uVar1;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0x3f800000;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = _DAT_00b58724;
  *(undefined4 *)(this + 0x30) = 0x3f800000;
  *(undefined4 *)(this + 0x34) = 0x3f800000;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  *(undefined4 *)(this + 0x38) = 0;
  return;
}
}

