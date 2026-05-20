// Class implementation: CControlBase_CStyleSheetElem_class_CControlStyle

// =================================================
// Function: CControlBase::CStyleSheetElem<class_CControlStyle>::Get
// =================================================
CMwNod * __thiscall
CControlBase::CStyleSheetElem<class_CControlStyle>::Get
          (void *this,CSystemData *param_1,CSystemFid *param_2,CSystemFid *param_3,ulong *param_4)
{
{
  int iVar1;
  int iVar2;
  CMwNod *pCVar3;
  CControlStyle *this_00;
  int extraout_EDX;
  CMwNod *unaff_EBP;
  CControlBase *unaff_ESI;
  CMwId *unaff_EDI;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x1c8))();
  if ((*(int *)((int)this + 4) == -1) || (iVar1 == 0)) {
    return *(CMwNod **)this;
  }
  if (*(int **)this != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)this + 0x10))(0x7017000);
    pCVar3 = *(CMwNod **)this;
    if (iVar2 == 0) {
      return pCVar3;
    }
    if (*(int *)(pCVar3 + 0x180) == iVar1) {
      return pCVar3;
    }
  }
  pCVar3 = GetStyleSheetElem((CControlBase *)param_1,(CControlStyleSheet *)((int)this + 4),unaff_EDI
                             ,unaff_ESI);
  if (pCVar3 != (CMwNod *)0x0) {
    unaff_EBP = (CMwNod *)CControlStyle::GetMwClassId(this_00,(CControlStyle *)unaff_EBP);
    iVar1 = (**(code **)(extraout_EDX + 0x10))();
    if (iVar1 == 0) {
      pCVar3 = (CMwNod *)0x0;
    }
    else {
      CMwNod::MwAddRef(pCVar3,unaff_EBP);
    }
  }
  if (*(CMwNod **)this != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)this,unaff_EBP);
  }
  *(CMwNod **)this = pCVar3;
  return pCVar3;
}
}

// =================================================
// Function: CControlBase::CStyleSheetElem<class_CControlStyle>::Set
// =================================================
void __thiscall
CControlBase::CStyleSheetElem<class_CControlStyle>::Set
          (void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  int in_stack_00000010;
  
  if (param_2 != *(int *)this) {
    if (param_2 != 0) {
      CMwNod::MwAddRef((CMwNod *)param_2,unaff_EDI);
    }
    if (*(CMwNod **)this != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)this,unaff_ESI);
    }
    *(int *)this = param_2;
    if (in_stack_00000010 == 0) {
      *(undefined4 *)((int)this + 4) = 0xffffffff;
    }
  }
  return;
}
}

