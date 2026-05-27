// Class implementation: CPlugTree_SVolatileTreePointer

// =================================================
// Function: CPlugTree::SVolatileTreePointer::Archive
// =================================================
void __thiscall
CPlugTree::SVolatileTreePointer::Archive
          (void *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2)
{
{
  CClassicArchive *unaff_ESI;
  int unaff_EDI;
  CClassicArchive *unaff_retaddr;
  undefined4 in_stack_0000000c;
  
  CClassicArchive::DoNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 8),(ulong *)0x1,0,unaff_EDI)
  ;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)this = in_stack_0000000c;
  }
  CMwId::Archive((void *)((int)this + 4),param_1,unaff_ESI);
  CMwId::Archive((void *)((int)this + 0xc),param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugTree::SVolatileTreePointer::GetTree
// =================================================
CPlugTree * __thiscall
CPlugTree::SVolatileTreePointer::GetTree(void *this,SVolatileTreePointer *param_1)
{
{
  CPlugTree *pCVar1;
  CPlugTree *unaff_retaddr;
  
  if (*(CPlugSolid **)this == (CPlugSolid *)0x0) {
    return (CPlugTree *)0x0;
  }
  pCVar1 = CPlugSolid::GetPlugFromId(*(CPlugSolid **)this,(CPlugSolid *)((int)this + 4),this);
  pCVar1 = InternalGetChildFromPointer(pCVar1,unaff_retaddr,param_1);
  return pCVar1;
}
}

// =================================================
// Function: CPlugTree::SVolatileTreePointer::SVolatileTreePointer
// =================================================
void __thiscall
CPlugTree::SVolatileTreePointer::SVolatileTreePointer(void *this,SVolatileTreePointer *param_1)
{
{
  CMwId *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a9651b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwId::CMwId((void *)((int)this + 4),(CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  CMwId::CMwId((void *)((int)this + 0xc),unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CPlugTree::SVolatileTreePointer::~SVolatileTreePointer
// =================================================
void __thiscall
CPlugTree::SVolatileTreePointer::~SVolatileTreePointer(void *this,SVolatileTreePointer *param_1)
{
{
  CFastStringInt *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a9654b;
  local_c = ExceptionList;
  pCVar1 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  local_4 = 0;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  local_4 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  ExceptionList = local_c;
  return;
}
}

