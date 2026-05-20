// Class implementation: CFastBuffer_struct_CPlugVisual_SSkinIndex

// =================================================
// Function: CFastBuffer<struct_CPlugVisual::SSkinIndex>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CPlugVisual::SSkinIndex>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  CFastBuffer<unsigned_char>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_CPlugVisual::SSkinIndex>::ArchiveCountAndElems
// =================================================
void __thiscall
CFastBuffer<struct_CPlugVisual::SSkinIndex>::ArchiveCountAndElems
          (void *this,CFastArray<struct_SOldLetter> *param_1,CClassicArchive *param_2)
{
{
  CFastArray<struct_SOldLetter> *this_00;
  ulong unaff_ESI;
  int unaff_EDI;
  ulong unaff_retaddr;
  
  this_00 = param_1;
  if (*(int *)(param_1 + 8) != 0) {
    CClassicArchive::WriteNatural((CClassicArchive *)param_1,this,(ulong *)0x1,0,unaff_EDI);
    CClassicArchive::WriteData
              ((CClassicArchive *)this_00,*(CClassicArchive **)((int)this + 4),*(void **)this,
               unaff_ESI);
    return;
  }
  CClassicArchive::ReadNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(ulong *)0x1,0,unaff_EDI);
  if (((CClassicArchive *)0x10000000 < param_2) && (DAT_00d72e8c != (code *)0x0)) {
    (*DAT_00d72e8c)();
  }
  AllocSetCount(this,(CFastBuffer<class_GxVertex2> *)param_2,unaff_ESI);
  CClassicArchive::ReadData
            ((CClassicArchive *)this_00,*(CClassicArchive **)((int)this + 4),*(void **)this,
             unaff_retaddr);
  return;
}
}

