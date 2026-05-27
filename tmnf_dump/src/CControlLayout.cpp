// Class implementation: CControlLayout

// =================================================
// Function: CControlLayout::CControlLayout
// =================================================
void __thiscall CControlLayout::CControlLayout(CControlLayout *this,CControlLayout *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x14) = 1;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0x3f800000;
  *(undefined4 *)(this + 0x28) = 0x3f800000;
  return;
}
}

