// Class implementation: CFastArray_struct_CPlugVisual_SSubVisual

// =================================================
// Function: CFastArray<struct_CPlugVisual::SSubVisual>::AllocateLess
// =================================================
void __thiscall
CFastArray<struct_CPlugVisual::SSubVisual>::AllocateLess
          (void *this,CFastArray<struct_CHmsWaterRegion::SCell> *param_1,ulong param_2)
{
{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  CFastArray<struct_CHmsWaterRegion::SCell> *pCVar5;
  
  pCVar5 = (CFastArray<struct_CHmsWaterRegion::SCell> *)(*(int *)this - (int)param_1);
  pvVar2 = operator_new__(-(uint)((int)(ZEXT48(pCVar5) * 0xc >> 0x20) != 0) |
                          (uint)(ZEXT48(pCVar5) * 0xc));
  if (pCVar5 != (CFastArray<struct_CHmsWaterRegion::SCell> *)0x0) {
    iVar4 = 0;
    param_1 = pCVar5;
    do {
      iVar3 = *(int *)((int)this + 4) + iVar4;
      *(undefined4 *)(iVar4 + (int)pvVar2) = *(undefined4 *)(*(int *)((int)this + 4) + iVar4);
      *(undefined4 *)(iVar4 + 4 + (int)pvVar2) = *(undefined4 *)(iVar3 + 4);
      *(undefined4 *)(iVar4 + 8 + (int)pvVar2) = *(undefined4 *)(iVar3 + 8);
      iVar4 = iVar4 + 0xc;
      param_1 = param_1 + -1;
    } while (param_1 != (CFastArray<struct_CHmsWaterRegion::SCell> *)0x0);
  }
  pvVar1 = *(void **)((int)this + 4);
  *(void **)((int)this + 4) = pvVar2;
  *(CFastArray<struct_CHmsWaterRegion::SCell> **)this = pCVar5;
  operator_delete__(pvVar1);
  return;
}
}

// =================================================
// Function: CFastArray<struct_CPlugVisual::SSubVisual>::ArchiveCountAndElems
// =================================================
void __thiscall
CFastArray<struct_CPlugVisual::SSubVisual>::ArchiveCountAndElems
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
              ((CClassicArchive *)this_00,*(CClassicArchive **)((int)this + 4),
               (void *)(*(int *)this * 0xc),unaff_ESI);
    return;
  }
  CClassicArchive::ReadNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(ulong *)0x1,0,unaff_EDI);
  if (((CClassicArchive *)0x10000000 < param_2) && (DAT_00d72e8c != (code *)0x0)) {
    (*DAT_00d72e8c)();
  }
  CFastArray<class_GmVec3>::SetCount
            (this,(CFastBuffer<class_CSystemFidsFolder*> *)param_2,unaff_ESI);
  CClassicArchive::ReadData
            ((CClassicArchive *)this_00,*(CClassicArchive **)((int)this + 4),
             (void *)(*(int *)this * 0xc),unaff_retaddr);
  return;
}
}

