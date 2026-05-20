// Class implementation: CControlLabel

// =================================================
// Function: CControlLabel::CControlLabel
// =================================================
void __thiscall CControlLabel::CControlLabel(CControlLabel *this,CControlLabel *param_1)
{
{
  CControlText *unaff_ESI;
  
  CControlText::CControlText((CControlText *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x130) = 0;
  *(undefined **)(this + 0x134) = PTR_DAT_00bbf7dc;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  *(uint *)(this + 0xfc) = *(uint *)(this + 0xfc) & 0xffffffd7 | 2;
  return;
}
}

// =================================================
// Function: CControlLabel::SetLabel
// =================================================
void __thiscall
CControlLabel::SetLabel(CControlLabel *this,CControlButton *param_1,CFastStringInt *param_2)
{
{
  int extraout_EAX;
  int *unaff_ESI;
  int *unaff_EDI;
  SStringParam *pSVar1;
  undefined4 local_4;
  
  pSVar1 = *(SStringParam **)(param_1 + 4);
  local_4 = 0;
  if (*(int *)param_1 == *(int *)(this + 0x130)) {
    CFastStringInt::Compare
              (this + 0x130,(SParam_Fids *)&stack0xfffffff4,(SParam *)0x0,unaff_EDI,unaff_ESI);
    if (extraout_EAX == 0) {
      return;
    }
  }
  local_4 = *(undefined4 *)(param_1 + 4);
  CFastStringInt::SetString(this + 0x130,(CFastStringInt *)&local_4,pSVar1);
  return;
}
}

