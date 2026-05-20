// Class implementation: CControlEntry

// =================================================
// Function: CControlEntry::CControlEntry
// =================================================
void __thiscall CControlEntry::CControlEntry(CControlEntry *this,CControlEntry *param_1)
{
{
  CControlText *unaff_ESI;
  
  CControlText::CControlText((CControlText *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined **)(this + 0x14c) = PTR_DAT_00bbf7dc;
  *(uint *)(this + 0xfc) = *(uint *)(this + 0xfc) | 0x100;
  *(undefined4 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x15c) = 0;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  return;
}
}

// =================================================
// Function: CControlEntry::SetEditedStringAndGiveFocus
// =================================================
void __thiscall
CControlEntry::SetEditedStringAndGiveFocus
          (CControlEntry *this,CControlEntry *param_1,CFastStringInt *param_2,ulong param_3)
{
{
  SStringParam *unaff_ESI;
  
  CControlBase::GiveFocus((CControlBase *)this,0);
  if (*(CControlKeyboardInterface **)(this + 0x15c) != (CControlKeyboardInterface *)0x0) {
    CControlKeyboardInterface::SetString
              (*(CControlKeyboardInterface **)(this + 0x15c),(CFastStringInt *)param_1,unaff_ESI);
    *(ulong *)(*(int *)(this + 0x15c) + 0x14) = param_3;
  }
  return;
}
}

