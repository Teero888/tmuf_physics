// Class implementation: CPlugTree_CIteratorSurface

// =================================================
// Function: CPlugTree::CIteratorSurface::GetNextSurface
// =================================================
CPlugSurface * __thiscall
CPlugTree::CIteratorSurface::GetNextSurface
          (void *this,CIteratorSurface *param_1,CPlugTree **param_2)
{
{
  int iVar1;
  CPlugModelTree *pCVar2;
  CPlugModelTree_ItTree *unaff_ESI;
  CPlugModelTree_ItTree *unaff_EDI;
  
  pCVar2 = CIteratorTree::GetNextTree(this,unaff_EDI);
  iVar1 = *(int *)((int)this + 0xc);
  while ((iVar1 != 0 && (*(int *)(iVar1 + 0x8c) == 0))) {
    CIteratorTree::GetNextTree(this,unaff_ESI);
    iVar1 = *(int *)((int)this + 0xc);
  }
  if (param_2 != (CPlugTree **)0x0) {
    *param_2 = (CPlugTree *)pCVar2;
  }
  return *(CPlugSurface **)(pCVar2 + 0x8c);
}
}

// =================================================
// Function: CPlugTree::CIteratorSurface::ResetItSurface
// =================================================
void __thiscall
CPlugTree::CIteratorSurface::ResetItSurface
          (void *this,CIteratorSurface *param_1,CPlugTree *param_2,EMode param_3)
{
{
  int iVar1;
  EMode unaff_ESI;
  CPlugModelTree_ItTree *unaff_retaddr;
  
  CIteratorTree::ResetItTree(this,(CIteratorTree *)param_1,param_2,unaff_ESI);
  iVar1 = *(int *)((int)this + 0xc);
  while ((iVar1 != 0 && (*(int *)(iVar1 + 0x8c) == 0))) {
    CIteratorTree::GetNextTree(this,unaff_retaddr);
    iVar1 = *(int *)((int)this + 0xc);
  }
  return;
}
}

