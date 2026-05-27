// Class implementation: CControlButton

// =================================================
// Function: CControlButton::CControlButton
// =================================================
void __thiscall CControlButton::CControlButton(CControlButton *this,CControlButton *param_1)
{
{
  CMwId *unaff_ESI;
  CMwId *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ac6fb2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CControlText::CControlText
            ((CControlText *)this,(CControlText *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = 0;
  CMwId::CMwId(this + 0x15c,unaff_EDI);
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined **)(this + 0x164) = PTR_DAT_00bbf7dc;
  CMwId::CMwId(this + 0x174,unaff_ESI);
  *(undefined4 *)(this + 0x168) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x16c) = 0;
  *(undefined4 *)(this + 0x170) = 0;
  ExceptionList = (void *)0x1;
  return;
}
}

// =================================================
// Function: CControlButton::InitFuncEnum
// =================================================
void __cdecl CControlButton::InitFuncEnum(CFuncEnum *param_1)
{
{
  ulong unaff_retaddr;
  
  CFuncEnum::SetWantedCount(param_1,(CFuncEnum *)&DAT_00000006,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CControlButton::SetIcons
// =================================================
void __thiscall
CControlButton::SetIcons(CControlButton *this,CControlButton *param_1,CFuncEnum *param_2)
{
{
  CControlBase::CStyleSheetElem<class_CControlStyle>::Set
            (this + 0x158,(CMwCmdScriptVarBool *)this,(int)param_1);
  return;
}
}

// =================================================
// Function: CControlButton::SetLabel
// =================================================
void __thiscall
CControlButton::SetLabel(CControlButton *this,CControlButton *param_1,CFastStringInt *param_2)
{
{
  int extraout_EAX;
  int *unaff_ESI;
  int *unaff_EDI;
  SStringParam *pSVar1;
  undefined4 local_4;
  
  pSVar1 = *(SStringParam **)(param_1 + 4);
  local_4 = 0;
  if ((*(int *)param_1 == *(int *)(this + 0x160)) &&
     (CFastStringInt::Compare
                (this + 0x160,(SParam_Fids *)&stack0xfffffff4,(SParam *)0x0,unaff_EDI,unaff_ESI),
     extraout_EAX == 0)) {
    return;
  }
  local_4 = *(undefined4 *)(param_1 + 4);
  CFastStringInt::SetString(this + 0x160,(CFastStringInt *)&local_4,pSVar1);
  return;
}
}

