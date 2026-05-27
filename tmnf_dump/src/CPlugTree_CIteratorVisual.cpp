// Class implementation: CPlugTree_CIteratorVisual

// =================================================
// Function: CPlugTree::CIteratorVisual::CIteratorVisual
// =================================================
void __thiscall
CPlugTree::CIteratorVisual::CIteratorVisual
          (void *this,CIteratorVisual *param_1,CPlugTree *param_2,EMode param_3)
{
{
  EMode unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a8b908;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined4 *)((int)this + 0xc) = 0;
  ResetItVisual(this,(CIteratorVisual *)param_2,(CPlugTree *)param_3,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CPlugTree::CIteratorVisual::GetNextVisual
// =================================================
CPlugVisual * __thiscall
CPlugTree::CIteratorVisual::GetNextVisual(void *this,CIteratorVisual *param_1,CPlugTree **param_2)
{
{
  int iVar1;
  CPlugModelTree *pCVar2;
  CPlugModelTree_ItTree *unaff_ESI;
  CPlugModelTree_ItTree *unaff_EDI;
  
  pCVar2 = CIteratorTree::GetNextTree(this,unaff_EDI);
  iVar1 = *(int *)((int)this + 0xc);
  while ((iVar1 != 0 && (*(int *)(iVar1 + 0x90) == 0))) {
    CIteratorTree::GetNextTree(this,unaff_ESI);
    iVar1 = *(int *)((int)this + 0xc);
  }
  if (param_2 != (CPlugTree **)0x0) {
    *param_2 = (CPlugTree *)pCVar2;
  }
  return *(CPlugVisual **)(pCVar2 + 0x90);
}
}

// =================================================
// Function: CPlugTree::CIteratorVisual::ResetItVisual
// =================================================
void __thiscall
CPlugTree::CIteratorVisual::ResetItVisual
          (void *this,CIteratorVisual *param_1,CPlugTree *param_2,EMode param_3)
{
{
  int iVar1;
  EMode unaff_ESI;
  CPlugModelTree_ItTree *unaff_retaddr;
  
  CIteratorTree::ResetItTree(this,(CIteratorTree *)param_1,param_2,unaff_ESI);
  iVar1 = *(int *)((int)this + 0xc);
  while ((iVar1 != 0 && (*(int *)(iVar1 + 0x90) == 0))) {
    CIteratorTree::GetNextTree(this,unaff_retaddr);
    iVar1 = *(int *)((int)this + 0xc);
  }
  return;
}
}

