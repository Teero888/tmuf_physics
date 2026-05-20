// Class implementation: CFastArray_struct_GmSurfMesh_STriangle

// =================================================
// Function: CFastArray<struct_GmSurfMesh::STriangle>::AllocateLess
// =================================================
void __thiscall
CFastArray<struct_GmSurfMesh::STriangle>::AllocateLess
          (void *this,CFastArray<struct_CHmsWaterRegion::SCell> *param_1,ulong param_2)
{
{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  CFastArray<struct_CHmsWaterRegion::SCell> *pCVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  pCVar5 = (CFastArray<struct_CHmsWaterRegion::SCell> *)(*(int *)this - (int)param_1);
  pvVar2 = operator_new__(-(uint)((int)(ZEXT48(pCVar5) * 0x20 >> 0x20) != 0) |
                          (uint)(ZEXT48(pCVar5) * 0x20));
  if (pCVar5 != (CFastArray<struct_CHmsWaterRegion::SCell> *)0x0) {
    iVar4 = 0;
    param_1 = pCVar5;
    do {
      puVar6 = (undefined4 *)(*(int *)((int)this + 4) + iVar4);
      puVar7 = (undefined4 *)(iVar4 + (int)pvVar2);
      iVar4 = iVar4 + 0x20;
      param_1 = param_1 + -1;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
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
// Function: CFastArray<struct_GmSurfMesh::STriangle>::AllocateMore
// =================================================
void __thiscall
CFastArray<struct_GmSurfMesh::STriangle>::AllocateMore
          (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,ulong param_2)
{
{
  CFastArray<struct_CDx9DeviceCaps::SFormat> *pCVar1;
  void *pvVar2;
  longlong lVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  iVar7 = *(int *)this;
  pCVar1 = param_1 + iVar7;
  lVar3 = ZEXT48(pCVar1) * 0x20;
  pvVar4 = operator_new__(-(uint)((int)((ulonglong)lVar3 >> 0x20) != 0) | (uint)lVar3);
  if (iVar7 != 0) {
    iVar6 = 0;
    do {
      puVar8 = (undefined4 *)(*(int *)((int)this + 4) + iVar6);
      puVar9 = (undefined4 *)(iVar6 + (int)pvVar4);
      iVar6 = iVar6 + 0x20;
      iVar7 = iVar7 + -1;
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
    } while (iVar7 != 0);
  }
  pvVar2 = *(void **)((int)this + 4);
  *(void **)((int)this + 4) = pvVar4;
  *(CFastArray<struct_CDx9DeviceCaps::SFormat> **)this = pCVar1;
  operator_delete__(pvVar2);
  return;
}
}

// =================================================
// Function: CFastArray<struct_GmSurfMesh::STriangle>::ArchiveCountAndElems
// =================================================
void __thiscall
CFastArray<struct_GmSurfMesh::STriangle>::ArchiveCountAndElems
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
               (void *)(*(int *)this << 5),unaff_ESI);
    return;
  }
  CClassicArchive::ReadNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(ulong *)0x1,0,unaff_EDI);
  if (((CClassicArchive *)0x10000000 < param_2) && (DAT_00d72e8c != (code *)0x0)) {
    (*DAT_00d72e8c)();
  }
  CFastArray<struct_SMeshOctreeCell>::SetCount
            (this,(CFastBuffer<class_CSystemFidsFolder*> *)param_2,unaff_ESI);
  CClassicArchive::ReadData
            ((CClassicArchive *)this_00,*(CClassicArchive **)((int)this + 4),
             (void *)(*(int *)this << 5),unaff_retaddr);
  return;
}
}

