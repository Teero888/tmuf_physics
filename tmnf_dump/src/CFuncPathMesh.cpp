// Class implementation: CFuncPathMesh

// =================================================
// Function: CFuncPathMesh::BuildMesh
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CFuncPathMesh::BuildMesh(CFuncPathMesh *this,CFuncPathMesh *param_1)
{
{
  void *this_00;
  float fVar1;
  float fVar2;
  uint uVar3;
  SCasterCat *this_01;
  SCasterCat *pSVar4;
  SCasterCat *this_02;
  ulong uVar5;
  SCasterCat *unaff_EBX;
  int iVar6;
  SCasterCat *unaff_ESI;
  ulong unaff_EDI;
  float10 fVar7;
  CPfmMesh *pCVar8;
  SCasterCat *pSVar9;
  SCasterCat *pSVar10;
  CFuncPathMesh *pCVar11;
  float local_4c;
  float fStack_48;
  
  pSVar9 = (SCasterCat *)&stack0xfffffffc;
  iVar6 = 0;
  if (*(int *)(this + 0x28) != 0) {
    pCVar11 = (CFuncPathMesh *)0x0;
    pCVar8 = (CPfmMesh *)&stack0xffffffa8;
    local_4c = 0.0;
    uVar3 = (**(code **)(**(int **)(this + 0x28) + 0xcc))();
    if (unaff_EBX == (SCasterCat *)0x0) {
      unaff_EBX = operator_new__(-(uint)((int)((ulonglong)uVar3 * 2 >> 0x20) != 0) |
                                 (uint)((ulonglong)uVar3 * 2));
    }
    pSVar4 = unaff_EBX;
    (**(code **)(**(int **)(this + 0x28) + 0xd0))();
    CPfmMeshInterface::Clear(*(CPfmMeshInterface **)(this + 0x2c),(TiXmlNode *)unaff_EBX);
    for (uVar3 = uVar3 / 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      this_00 = (void *)(*(int *)(this + 0x28) + 0x78);
      pSVar10 = pSVar4;
      this_01 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                          (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                   (uint)*(ushort *)(pSVar4 + iVar6),(ulong)pCVar8);
      pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                  (uint)*(ushort *)(pSVar4 + iVar6 + 2),unaff_EDI);
      pCVar8 = (CPfmMesh *)0x58dc08;
      this_02 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                          (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                   (uint)*(ushort *)(uVar3 + 4 + iVar6),(ulong)unaff_ESI);
      unaff_EDI = 0x58dc12;
      unaff_ESI = pSVar4;
      uVar5 = GmVec3::IsNearlyEqual(this_01,(GmVec2 *)pSVar4,(GmVec2 *)pSVar9);
      if (uVar5 == 0) {
        unaff_ESI = (SCasterCat *)0x58dc22;
        pSVar9 = this_02;
        uVar5 = GmVec3::IsNearlyEqual(pSVar4,(GmVec2 *)this_02,(GmVec2 *)pSVar10);
        if (uVar5 == 0) {
          pSVar9 = (SCasterCat *)0x58dc32;
          pSVar10 = this_01;
          uVar5 = GmVec3::IsNearlyEqual(this_02,(GmVec2 *)this_01,(GmVec2 *)pCVar11);
          if (uVar5 == 0) {
            fVar1 = *(float *)this_02;
            fVar2 = *(float *)this_01;
            func_0x009c1b40();
            pCVar11 = (CFuncPathMesh *)0x58dd0c;
            fVar7 = (float10)func_0x009c1b40();
            local_4c = (float)fVar7;
            if (fStack_48 <= local_4c * (fVar1 - fVar2)) {
              CPfmMeshInterface::AddCell
                        (*(CPfmMeshInterface **)(pCVar11 + 0x2c),(CPfmMesh *)this_01,
                         (GmVec3 *)pSVar4,(GmVec3 *)this_02,(GmVec3 *)pCVar8);
            }
          }
        }
      }
      iVar6 = iVar6 + 6;
      this = pCVar11;
      pSVar4 = pSVar10;
    }
    CPfmMeshInterface::LinkCells(*(CPfmMeshInterface **)(this + 0x2c),pCVar8);
    if (local_4c != 0.0) {
      operator_delete(pCVar11);
    }
  }
  return;
}
}

// =================================================
// Function: CFuncPathMesh::SetVisual
// =================================================
void __thiscall
CFuncPathMesh::SetVisual(CFuncPathMesh *this,CVisionVisualKeeper *param_1,CPlugVisual *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != (CVisionVisualKeeper *)0x0) {
    CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
  }
  if (*(CMwNod **)(this + 0x28) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x28),unaff_ESI);
  }
  *(CVisionVisualKeeper **)(this + 0x28) = param_1;
  if (param_1 != (CVisionVisualKeeper *)0x0) {
    BuildMesh(this,(CFuncPathMesh *)unaff_ESI);
  }
  return;
}
}

