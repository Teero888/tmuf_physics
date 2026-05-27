// Class implementation: CControlStyleSheet

// =================================================
// Function: CControlStyleSheet::GetStyleSheetElem
// =================================================
CMwNod * __thiscall
CControlStyleSheet::GetStyleSheetElem
          (CControlStyleSheet *this,CControlStyleSheet *param_1,CMwId *param_2,CControlBase *param_3
          )
{
{
  CMwNod *pCVar1;
  int iVar2;
  CMwId *unaff_ESI;
  
  if (*(CMwRefBuffer **)(this + 0x28) != (CMwRefBuffer *)0x0) {
    pCVar1 = CMwRefBuffer::GetFromId
                       (*(CMwRefBuffer **)(this + 0x28),(CMwRefBuffer *)param_1,unaff_ESI);
    if (pCVar1 != (CMwNod *)0x0) {
      iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(0x7017000);
      if (iVar2 != 0) {
        *(CControlStyleSheet **)(pCVar1 + 0x180) = this;
      }
    }
    return pCVar1;
  }
  return (CMwNod *)0x0;
}
}

