// Class implementation: CHmsShadowGroup

// =================================================
// Function: CHmsShadowGroup::CHmsShadowGroup
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsShadowGroup::CHmsShadowGroup(CHmsShadowGroup *this,CHmsShadowGroup *param_1)
{
{
  undefined4 uVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_EDI,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x84,unaff_retaddr);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x90,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  *(undefined4 *)(this + 0x24) = 0x3f800000;
  uVar1 = _DAT_00b2c05c;
  *(undefined4 *)(this + 0x14) = 0x100;
  *(undefined4 *)(this + 0x28) = uVar1;
  *(undefined4 *)(this + 0x18) = 0x100;
  uVar1 = _DAT_00b313ac;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x5c) = 0x500;
  *(undefined4 *)(this + 0x1c) = 0x3f800000;
  *(undefined4 *)(this + 0x60) = 6;
  *(undefined4 *)(this + 0x20) = 0x3f800000;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x30) = 0x20005;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = _DAT_00b58724;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x68) = _DAT_00b3cd40;
  *(undefined4 *)(this + 0x6c) = _DAT_00b313a8;
  *(undefined4 *)(this + 0x70) = _DAT_00b36194;
  *(undefined4 *)(this + 0x74) = _DAT_00b59068;
  *(undefined4 *)(this + 0x78) = _DAT_00b36154;
  *(undefined4 *)(this + 0x7c) = _DAT_00b59064;
  *(undefined4 *)(this + 0x80) = 0x3f800000;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  return;
}
}

