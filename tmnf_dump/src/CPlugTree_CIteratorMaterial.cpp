// Class implementation: CPlugTree_CIteratorMaterial

// =================================================
// Function: CPlugTree::CIteratorMaterial::CIteratorMaterial
// =================================================
void __thiscall
CPlugTree::CIteratorMaterial::CIteratorMaterial
          (void *this,CIteratorMaterial *param_1,CPlugTree *param_2,EMode param_3)
{
{
  EMode unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a98ab8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined4 *)((int)this + 0xc) = 0;
  ResetItMaterial(this,(CIteratorMaterial *)param_2,(CPlugTree *)param_3,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CPlugTree::CIteratorMaterial::GetNextMaterial
// =================================================
CPlugMaterial * __thiscall
CPlugTree::CIteratorMaterial::GetNextMaterial
          (void *this,CIteratorMaterial *param_1,CPlugTree **param_2)
{
{
  int iVar1;
  CPlugModelTree *pCVar2;
  CPlugModelTree_ItTree *unaff_ESI;
  CPlugModelTree_ItTree *unaff_EDI;
  
  pCVar2 = CIteratorTree::GetNextTree(this,unaff_EDI);
  iVar1 = *(int *)((int)this + 0xc);
  while ((iVar1 != 0 && (*(int *)(iVar1 + 0x98) == 0))) {
    CIteratorTree::GetNextTree(this,unaff_ESI);
    iVar1 = *(int *)((int)this + 0xc);
  }
  if (param_2 != (CPlugTree **)0x0) {
    *param_2 = (CPlugTree *)pCVar2;
  }
  return *(CPlugMaterial **)(pCVar2 + 0x98);
}
}

// =================================================
// Function: CPlugTree::CIteratorMaterial::ResetItMaterial
// =================================================
void __thiscall
CPlugTree::CIteratorMaterial::ResetItMaterial
          (void *this,CIteratorMaterial *param_1,CPlugTree *param_2,EMode param_3)
{
{
  int iVar1;
  EMode unaff_ESI;
  CPlugModelTree_ItTree *unaff_retaddr;
  
  CIteratorTree::ResetItTree(this,(CIteratorTree *)param_1,param_2,unaff_ESI);
  iVar1 = *(int *)((int)this + 0xc);
  while ((iVar1 != 0 && (*(int *)(iVar1 + 0x98) == 0))) {
    CIteratorTree::GetNextTree(this,unaff_retaddr);
    iVar1 = *(int *)((int)this + 0xc);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::CIteratorMaterial::~CIteratorMaterial
// =================================================
void __thiscall
CPlugTree::CIteratorMaterial::~CIteratorMaterial(void *this,CIteratorMaterial *param_1)
{
{
  operator_delete__(*(void **)((int)this + 4));
  return;
}
}

