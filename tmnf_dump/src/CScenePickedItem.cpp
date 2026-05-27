// Class implementation: CScenePickedItem

// =================================================
// Function: CScenePickedItem::CScenePickedItem
// =================================================
void __thiscall CScenePickedItem::CScenePickedItem(CScenePickedItem *this,CScenePickedItem *param_1)
{
{
  CMwNod *unaff_ESI;
  void *unaff_retaddr;
  undefined1 uStack00000008;
  CScenePickedItem *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ace193;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec),unaff_ESI);
  *(undefined ***)this = vftable;
  CHmsPicker::CHmsPicker((CHmsPicker *)(this + 0x18),(CHmsPicker *)pCVar1);
  uStack00000008 = 1;
  *(undefined4 *)(this + 0x158) = 0;
  *(undefined4 *)(this + 0x15c) = 0;
  Reset(this,(GmFrustumIso4 *)0x0);
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CScenePickedItem::Reset
// =================================================
void __thiscall CScenePickedItem::Reset(CScenePickedItem *this,GmFrustumIso4 *param_1)
{
{
  GmMat43 *unaff_ESI;
  CScenePickedItem *unaff_EDI;
  
  if (param_1 != (GmFrustumIso4 *)0x0) {
    SubDependences(this,unaff_EDI);
  }
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined4 *)(this + 0xf0) = 0;
  *(undefined4 *)(this + 0x124) = 0;
  GmIso4::SetIdentity(this + 0x128,unaff_ESI);
  return;
}
}

// =================================================
// Function: CScenePickedItem::SetKilledCallBack
// =================================================
void __thiscall
CScenePickedItem::SetKilledCallBack
          (CScenePickedItem *this,CScenePickedItem *param_1,CMwNod *param_2,
          _func___cdecl_void_CScenePickedItem_ptr *param_3)
{
{
  *(CScenePickedItem **)(this + 0x158) = param_1;
  *(CMwNod **)(this + 0x15c) = param_2;
  return;
}
}

// =================================================
// Function: CScenePickedItem::SubDependences
// =================================================
void __thiscall CScenePickedItem::SubDependences(CScenePickedItem *this,CScenePickedItem *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  if (*(CMwNod **)(this + 0xec) != (CMwNod *)0x0) {
    CMwNod::MwSubDependantSafe(*(CMwNod **)(this + 0xec),(CMwNod *)this,unaff_ESI);
  }
  if (*(CMwNod **)(this + 0xf0) != (CMwNod *)0x0) {
    CMwNod::MwSubDependantSafe(*(CMwNod **)(this + 0xf0),(CMwNod *)this,unaff_retaddr);
  }
  return;
}
}

