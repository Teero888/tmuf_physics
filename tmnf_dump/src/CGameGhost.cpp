// Class implementation: CGameGhost

// =================================================
// Function: CGameGhost::ClearNotSimulatedData
// =================================================
void __thiscall CGameGhost::ClearNotSimulatedData(CGameGhost *this,CGameGhost *param_1)
{
{
  CClassicBufferMemory *unaff_ESI;
  GmFrustumIso4 *unaff_retaddr;
  GmFrustumIso4 *in_stack_0000000c;
  
  CClassicBufferMemory::Empty((CClassicBufferMemory *)(this + 0x24),unaff_ESI);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x50,unaff_retaddr);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x5c,in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CGameGhost::GetDuration
// =================================================
ulong __thiscall CGameGhost::GetDuration(CGameGhost *this,CPlugFileAvi *param_1)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  SNewTriangleVert *pSVar3;
  ulong unaff_ESI;
  CGameGhost *this_00;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_retaddr;
  
  if (*(int *)(this + 0x68) != 0) {
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x50,unaff_EDI);
    return uVar1 * *(int *)(this + 0x44);
  }
  this_00 = this + 0x5c;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
    pSVar3 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(this_00,unaff_retaddr);
    return *(int *)pSVar3 - *(int *)pSVar2;
  }
  return 0;
}
}

// =================================================
// Function: CGameGhost::IsFixedTimeStep
// =================================================
int __thiscall CGameGhost::IsFixedTimeStep(CGameGhost *this,CGameGhost *param_1)
{
{
  return *(int *)(this + 0x68);
}
}

