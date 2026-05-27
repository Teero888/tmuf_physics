// Class implementation: SStateSplit

// =================================================
// Function: SStateSplit::Allocate
// =================================================
void __thiscall SStateSplit::Allocate(void *this,SStateSplit *param_1,ulong param_2)
{
{
  ulong unaff_EBX;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  void *this_00;
  ulong unaff_EBP;
  int iVar2;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  ulong in_stack_0000000c;
  ulong in_stack_00000010;
  ulong in_stack_00000014;
  
  pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)((int)param_1 * 2 + 7U >> 3);
  CFastBuffer<unsigned_char>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(pCVar1 + 3),unaff_EDI);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount(this,pCVar1,unaff_ESI);
  pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)((int)param_1 * 3 + 7U >> 3);
  CFastBuffer<unsigned_char>::SetSizeAtLeast
            ((void *)((int)this + 0x30),
             (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(pCVar1 + 3),unaff_EBP);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount((void *)((int)this + 0x30),pCVar1,unaff_EBX);
  CFastBuffer<struct_CPlugVisual::SSkinIndex>::AllocSetCount
            ((void *)((int)this + 0x3c),(CFastBuffer<class_GxVertex2> *)param_1,unaff_retaddr);
  this_00 = (void *)((int)this + 0x60);
  iVar2 = 4;
  do {
    CFastBuffer<struct_CPlugVisual::SSkinIndex>::AllocSetCount
              (this_00,(CFastBuffer<class_GxVertex2> *)param_1,(ulong)param_1);
    this_00 = (void *)((int)this_00 + 0xc);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  CFastBuffer<unsigned_char>::SetSizeAtLeast
            ((void *)((int)this + 0x90),
             (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)
             ((CFastBuffer<class_CSystemFidsFolder*> *)((uint)(param_1 + 7) >> 3) + 3),param_2);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            ((void *)((int)this + 0x90),
             (CFastBuffer<class_CSystemFidsFolder*> *)((uint)(param_1 + 7) >> 3),in_stack_0000000c);
  pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)(((uint)(param_1 + 3) & 0xfffffffc) + 7 >> 3);
  CFastBuffer<unsigned_char>::SetSizeAtLeast
            ((void *)((int)this + 0x9c),
             (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(pCVar1 + 3),in_stack_00000010);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            ((void *)((int)this + 0x9c),pCVar1,in_stack_00000014);
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(undefined4 *)((int)this + 0xac) = 0;
  return;
}
}

// =================================================
// Function: SStateSplit::Archive
// =================================================
void __thiscall
SStateSplit::Archive(void *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2)
{
{
  CClassicArchive *unaff_EBX;
  CFastBuffer<unsigned_char> *pCVar1;
  CFastCrypt<unsigned_long> *unaff_EBP;
  int iVar2;
  int unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CClassicArchive *unaff_retaddr;
  CFastBuffer<class_GxVertex2> *in_stack_0000000c;
  
  CFastBuffer_ArchiveElems<unsigned_char>(this,(CClassicArchive *)param_1);
  CFastBuffer_ArchiveElems<unsigned_char>
            ((CFastBuffer<unsigned_char> *)((int)this + 0x30),(CClassicArchive *)param_1);
  pCVar1 = (CFastBuffer<unsigned_char> *)((int)this + 0xc);
  param_2 = (CClassicArchive *)CFastBuffer<class_CCrystalFace*>::GetCount(pCVar1,unaff_EDI);
  CClassicArchive::DoNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,(ulong *)0x1,0,unaff_ESI);
  iVar2 = 3;
  do {
    CFastBuffer<struct_CPlugVisual::SSkinIndex>::AllocSetCount
              (pCVar1,in_stack_0000000c,(ulong)unaff_EBP);
    unaff_EBP = param_1;
    CFastBuffer_ArchiveElems<unsigned_char>(pCVar1,(CClassicArchive *)param_1);
    pCVar1 = pCVar1 + 0xc;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  CFastBuffer_ArchiveElems<unsigned_char>
            ((CFastBuffer<unsigned_char> *)((int)this + 0x3c),(CClassicArchive *)param_1);
  CFastBuffer<struct_CPlugVisual::SSkinIndex>::ArchiveCountAndElems
            ((void *)((int)this + 0x48),(CFastArray<struct_SOldLetter> *)param_1,unaff_EBX);
  CFastBuffer<struct_CPlugVisual::SSkinIndex>::ArchiveCountAndElems
            ((void *)((int)this + 0x54),(CFastArray<struct_SOldLetter> *)param_1,unaff_retaddr);
  pCVar1 = (CFastBuffer<unsigned_char> *)((int)this + 0x60);
  iVar2 = 4;
  do {
    CFastBuffer_ArchiveElems<unsigned_char>(pCVar1,(CClassicArchive *)param_1);
    pCVar1 = pCVar1 + 0xc;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  CFastBuffer_ArchiveElems<unsigned_char>
            ((CFastBuffer<unsigned_char> *)((int)this + 0x90),(CClassicArchive *)param_1);
  CFastBuffer_ArchiveElems<unsigned_char>
            ((CFastBuffer<unsigned_char> *)((int)this + 0x9c),(CClassicArchive *)param_1);
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(undefined4 *)((int)this + 0xac) = 0;
  return;
}
}

// =================================================
// Function: SStateSplit::SStateSplit
// =================================================
void __thiscall SStateSplit::SStateSplit(void *this,SStateSplit *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *pCVar1;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar2;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar3;
  code *pcVar4;
  code *pcVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acfb2f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  pcVar5 = CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>;
  pcVar4 = CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>;
  pCVar3 = (CFastBuffer<class_CPlugFileSndGen*> *)0x3;
  pCVar1 = (CFastBuffer<class_CPlugFileSndGen*> *)((int)this + 0xc);
  pCVar2 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_0000000c;
  _eh_vector_constructor_iterator_
            (pCVar1,0xc,3,CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>,
             CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x30),pCVar1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x3c),pCVar2);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x48),pCVar3);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x54),(CFastBuffer<class_CPlugFileSndGen*> *)pcVar4);
  pCVar2 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_0000000c;
  pCVar1 = (CFastBuffer<class_CPlugFileSndGen*> *)((int)this + 0x60);
  local_4 = CONCAT31(local_4._1_3_,5);
  _eh_vector_constructor_iterator_
            (pCVar1,0xc,4,CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>,
             CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x90),pCVar1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x9c),pCVar2);
  ExceptionList = pcVar5;
  return;
}
}

// =================================================
// Function: SStateSplit::~SStateSplit
// =================================================
void __thiscall SStateSplit::~SStateSplit(void *this,SStateSplit *param_1)
{
{
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar1;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar2;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar3;
  code *pcVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00acfb8f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 5;
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x9c),
             (CFastBuffer<class_CPlugFileGPUV*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x90),unaff_ESI);
  pcVar4 = CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>;
  pCVar3 = (CFastBuffer<class_CPlugFileGPUV*> *)&DAT_00000004;
  pCVar1 = (CFastBuffer<class_CPlugFileGPUV*> *)((int)this + 0x60);
  pCVar2 = (CFastBuffer<class_CPlugFileGPUV*> *)&DAT_0000000c;
  _eh_vector_destructor_iterator_
            (pCVar1,0xc,4,CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x54),pCVar1);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x48),pCVar2);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x3c),pCVar3);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x30),(CFastBuffer<class_CPlugFileGPUV*> *)pcVar4);
  pCVar1 = (CFastBuffer<class_CPlugFileGPUV*> *)((int)this + 0xc);
  _eh_vector_destructor_iterator_
            (pCVar1,0xc,3,CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this,pCVar1);
  ExceptionList = this;
  return;
}
}

