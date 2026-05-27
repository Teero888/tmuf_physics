// Class implementation: CControlText

// =================================================
// Function: CControlText::CControlText
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CControlText::CControlText(CControlText *this,CControlText *param_1)
{
{
  CControlBase *unaff_ESI;
  
  CControlBase::CControlBase((CControlBase *)this,unaff_ESI);
  *(undefined4 *)(this + 0x120) = _DAT_00b2c060;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x128) = 0xffffffff;
  *(undefined4 *)(this + 0x124) = 3;
  return;
}
}

// =================================================
// Function: CControlText::GetLineCount
// =================================================
ulong __thiscall CControlText::GetLineCount(CControlText *this,CControlText *param_1)
{
{
  CPlugTreeGenText *this_00;
  ulong uVar1;
  CControlText *unaff_retaddr;
  CPlugTreeGenText *in_stack_00000008;
  
  this_00 = GetTextGenerator(this,unaff_retaddr);
  if (this_00 == (CPlugTreeGenText *)0x0) {
    return 0xffffffff;
  }
  uVar1 = CPlugTreeGenText::ComputeLineCount(this_00,in_stack_00000008);
  return uVar1;
}
}

// =================================================
// Function: CControlText::GetTextGenerator
// =================================================
CPlugTreeGenText * __thiscall
CControlText::GetTextGenerator(CControlText *this,CControlText *param_1)
{
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(this + 300) != 0) &&
     (piVar1 = *(int **)(*(int *)(this + 300) + 0xa0), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0x10))(0x903f000);
    if (iVar2 != 0) {
      return *(CPlugTreeGenText **)(*(int *)(this + 300) + 0xa0);
    }
  }
  return (CPlugTreeGenText *)0x0;
}
}

