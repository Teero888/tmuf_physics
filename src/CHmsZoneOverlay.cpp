// Class implementation: CHmsZoneOverlay

// =================================================
// Function: CHmsZoneOverlay::CHmsZoneOverlay
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsZoneOverlay::CHmsZoneOverlay(CHmsZoneOverlay *this,CHmsZoneOverlay *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  void *in_stack_00000008;
  CHmsZoneOverlay *pCVar1;
  GmBoxAligned *in_stack_ffffffc4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [4];
  GmFrustum local_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a96b04;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CHmsZone::CHmsZone((CHmsZone *)this,(CHmsZone *)(DAT_00cca150 ^ (uint)&stack0xffffffb8));
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x174,unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x180,unaff_ESI);
  local_30 = _DAT_00b2c060;
  in_stack_00000008 = (void *)CONCAT31(in_stack_00000008._1_3_,2);
  *(undefined4 *)(this + 0x13c) = _DAT_00b2c060;
  local_24 = 0x3f800000;
  *(undefined4 *)(this + 0x140) = local_30;
  local_20 = 0x3f800000;
  *(undefined4 *)(this + 0x144) = 0x3f800000;
  local_1c = 0x3f800000;
  *(undefined4 *)(this + 0x148) = 0x3f800000;
  *(undefined4 *)(this + 0x16c) = 2;
  local_2c = local_30;
  local_28 = local_30;
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined4 *)(this + 0x168) = 0;
  *(undefined4 *)(this + 0x170) = 0;
  GmBoxAligned::SetMinMax(local_18,(GmBoxAligned *)&local_30,(GmVec3 *)&local_24,(GmVec3 *)pCVar1);
  GmFrustum::SetOrtho(this + 0x11c,local_14,in_stack_ffffffc4);
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = 0;
  *(undefined4 *)(this + 0x15c) = 0;
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined4 *)(this + 0x164) = 0x3f800000;
  ExceptionList = in_stack_00000008;
  return;
}
}

