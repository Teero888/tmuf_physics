// Class implementation: GmSurfMesh

// =================================================
// Function: GmSurfMesh::Archive
// =================================================
void __thiscall
GmSurfMesh::Archive(GmSurfMesh *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2)
{
{
  CClassicArchive *unaff_ESI;
  int unaff_EDI;
  CClassicArchive *unaff_retaddr;
  CClassicArchive *pCVar1;
  
  pCVar1 = (CClassicArchive *)0x3;
  CClassicArchive::DoNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffffc,(ulong *)0x1,0,unaff_EDI
            );
  if ((unaff_retaddr == (CClassicArchive *)0x1) || (unaff_retaddr == (CClassicArchive *)0x2)) {
    CFastArray<struct_CPlugVisual::SSubVisual>::ArchiveCountAndElems
              (this + 8,(CFastArray<struct_SOldLetter> *)param_1,unaff_ESI);
    CFastArray<struct_GmSurfMesh::STriangle>::ArchiveCountAndElems
              (this + 0x10,(CFastArray<struct_SOldLetter> *)param_1,pCVar1);
    GmOctree<struct_SMeshOctreeCell>::Archive(this + 0x20,param_1,unaff_retaddr);
    if (*(int *)(param_1 + 8) == 0) {
      BuildOctree(this,(GmSurfMesh *)param_1);
    }
  }
  else if (unaff_retaddr == (CClassicArchive *)0x3) {
    CFastArray<struct_CPlugVisual::SSubVisual>::ArchiveCountAndElems
              (this + 8,(CFastArray<struct_SOldLetter> *)param_1,unaff_ESI);
    CFastArray<struct_GmSurfMesh::STriangle>::ArchiveCountAndElems
              (this + 0x10,(CFastArray<struct_SOldLetter> *)param_1,pCVar1);
    GmOctree<struct_SMeshOctreeCell>::Archive(this + 0x20,param_1,unaff_retaddr);
    return;
  }
  return;
}
}

// =================================================
// Function: GmSurfMesh::BuildOctree
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmSurfMesh::BuildOctree(GmSurfMesh *this,GmSurfMesh *param_1)
{
{
  float fVar1;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar2;
  SCasterCat *pSVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  ulong unaff_EBP;
  int iVar7;
  ulong unaff_ESI;
  NvStripInfo *pNVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastArray<class_CFuncShader*> *pCVar9;
  ulong uVar10;
  GmSurfMesh *pGVar11;
  int iStack_30;
  CFastBuffer<class_CSystemFidsFolder*> *local_2c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_28;
  float local_24;
  undefined1 local_20 [4];
  vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> *local_1c;
  float local_18;
  float local_14;
  float fStack_10;
  void *local_c;
  undefined1 *local_8;
  float local_4;
  
  local_4 = -NAN;
  local_8 = &LAB_00ade6b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pGVar11 = this;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (&local_2c,(CFastArray<class_CManoeuvre*> *)(DAT_00cca150 ^ (uint)&stack0xffffffb8));
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar2 = (CFastBuffer<class_CSystemFidsFolder*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x10,unaff_EDI);
  local_2c = pCVar2;
  CFastArray<struct_SMeshOctreeCell>::SetCount(&local_24,pCVar2,unaff_ESI);
  pNVar8 = (NvStripInfo *)0x0;
  if (pCVar2 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (local_20,pCVar6,unaff_EBP);
      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar3 + 0x1c) = pCVar6;
      uVar10 = 0x8f3c58;
      pSVar4 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         ((CFastBuffer<class_CSystemFidsFolder*> *)(this + 0x10),pCVar6,
                          (ulong)unaff_EBX);
      unaff_EBX = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x10);
      unaff_EBP = 0x8f3c66;
      pSVar5 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         ((CFastBuffer<class_CSystemFidsFolder*> *)(this + 8),unaff_EBX,
                          (ulong)pGVar11);
      local_c = *(void **)pSVar5;
      pSVar4 = pSVar4 + 0x14;
      local_8 = *(undefined1 **)(pSVar5 + 4);
      iVar7 = 2;
      local_4 = *(float *)(pSVar5 + 8);
      do {
        pSVar5 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           ((void *)(iStack_30 + 8),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar4,uVar10);
        if (*(float *)pSVar5 < local_18) {
          local_18 = *(float *)pSVar5;
        }
        if (*(float *)(pSVar5 + 4) < local_14) {
          local_14 = *(float *)(pSVar5 + 4);
        }
        if (*(float *)(pSVar5 + 8) < fStack_10) {
          fStack_10 = *(float *)(pSVar5 + 8);
        }
        if ((float)local_c < *(float *)pSVar5) {
          local_c = *(void **)pSVar5;
        }
        if ((float)local_8 < *(float *)(pSVar5 + 4)) {
          local_8 = *(undefined1 **)(pSVar5 + 4);
        }
        if (local_4 < *(float *)(pSVar5 + 8)) {
          local_4 = *(float *)(pSVar5 + 8);
        }
        pSVar4 = pSVar4 + 4;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      pCVar6 = pCVar6 + 1;
      fVar1 = (float)_DAT_00b313b8;
      *(float *)(pSVar3 + 4) = ((float)local_c + local_18) * fVar1;
      *(float *)(pSVar3 + 8) = (local_14 + (float)local_8) * fVar1;
      local_24 = fStack_10 + local_4;
      *(float *)(pSVar3 + 0xc) = local_24 * fVar1;
      *(float *)(pSVar3 + 0x10) = (float)local_c - local_18;
      *(float *)(pSVar3 + 0x14) = (float)local_8 - local_14;
      *(float *)(pSVar3 + 0x18) = local_4 - fStack_10;
      *(float *)(pSVar3 + 0x10) = *(float *)(pSVar3 + 0x10) * fVar1;
      *(float *)(pSVar3 + 0x14) = *(float *)(pSVar3 + 0x14) * fVar1;
      *(float *)(pSVar3 + 0x18) = fVar1 * *(float *)(pSVar3 + 0x18);
      this = (GmSurfMesh *)local_2c;
      pNVar8 = (NvStripInfo *)pCStack_28;
    } while (pCVar6 < pCStack_28);
  }
  pCVar9 = (CFastArray<class_CFuncShader*> *)0x0;
  GmOctree<struct_SMeshOctreeCell>::Build
            ((CFastBuffer<class_CSystemFidsFolder*> *)(this + 0x20),pNVar8,local_1c,
             (vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *)0x1);
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(&local_2c,pCVar9);
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: GmSurfMesh::ClipSegment
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
GmSurfMesh::ClipSegment
          (GmSurfMesh *this,GmSurfSphere *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,
          float *param_5)
{
{
  ulong uVar1;
  int iVar2;
  GmVec3 *unaff_ESI;
  int *piVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  GmVec3 *pGVar4;
  float local_8;
  float local_4;
  
  pGVar4 = (GmVec3 *)0x1;
  local_8 = *(float *)(param_1 + 4) + *(float *)(param_2 + 4) * (float)_DAT_00b313b8;
  local_4 = *(float *)(param_1 + 8) + (float)_DAT_00b313b8 * *(float *)(param_2 + 8);
  *(undefined4 *)param_3 = _DAT_00b313ac;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  if (1 < uVar1) {
    do {
      piVar3 = (int *)((int)pGVar4 * 0x20 + *(int *)(this + 0x24));
      if ((GmVec3 *)piVar3[7] == (GmVec3 *)0xffffffff) {
        iVar2 = GmBoxAligned::TestInterSegment_MiddleVectAB
                          (piVar3 + 1,(GmBoxAligned *)&local_8,param_2,unaff_ESI);
        if (iVar2 != 0) goto LAB_008f1f6b;
        pGVar4 = pGVar4 + *piVar3;
      }
      else {
        TriangleClipSegmentNearerThanT
                  (this,(GmSurfMesh *)param_2,param_2,(GmVec3 *)piVar3[7],(ulong)param_4,param_5,
                   (SPointInTri *)unaff_ESI);
LAB_008f1f6b:
        pGVar4 = pGVar4 + 1;
      }
    } while (pGVar4 < param_4);
    if (*param_5 < 1.0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmSurfMesh::ClipSegment2
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
GmSurfMesh::ClipSegment2
          (GmSurfMesh *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,int param_4,
          float *param_5,GmVec3 *param_6)
{
{
  ulong uVar1;
  int iVar2;
  SCasterCat *pSVar3;
  uint uVar4;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  int *piVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *in_stack_00000020;
  float local_8;
  float local_4;
  
  uVar4 = 1;
  local_8 = *(float *)(param_1 + 4) + *(float *)(param_2 + 4) * (float)_DAT_00b313b8;
  local_4 = *(float *)(param_1 + 8) + (float)_DAT_00b313b8 * *(float *)(param_2 + 8);
  *(undefined4 *)param_4 = _DAT_00b313ac;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  if (1 < uVar1) {
    do {
      piVar5 = (int *)(uVar4 * 0x20 + *(int *)(this + 0x24));
      if ((GmVec3 *)piVar5[7] == (GmVec3 *)0xffffffff) {
        iVar2 = GmBoxAligned::TestInterSegment_MiddleVectAB
                          (piVar5 + 1,(GmBoxAligned *)&local_8,param_2,(GmVec3 *)unaff_ESI);
        if (iVar2 != 0) goto LAB_008f2183;
        uVar4 = uVar4 + *piVar5;
      }
      else {
        iVar2 = TriangleClipSegment2NearerThanT
                          (this,(GmSurfMesh *)param_2,param_2,(GmVec3 *)piVar5[7],param_4,
                           (int)param_5,(float *)unaff_ESI);
        if (iVar2 != 0) {
          unaff_ESI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)piVar5[7];
          pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                             (this + 0x10,unaff_ESI,unaff_EBP);
          *in_stack_00000020 = *(undefined4 *)pSVar3;
          in_stack_00000020[1] = *(undefined4 *)(pSVar3 + 4);
          in_stack_00000020[2] = *(undefined4 *)(pSVar3 + 8);
        }
LAB_008f2183:
        uVar4 = uVar4 + 1;
      }
    } while (uVar4 < uVar1);
    if (*param_5 < 1.0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmSurfMesh::ClipSegment3
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
GmSurfMesh::ClipSegment3
          (GmSurfMesh *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,float *param_4,
          ushort *param_5)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  int iVar3;
  GmVec3 *unaff_ESI;
  int *piVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float *pfVar5;
  undefined2 *in_stack_0000001c;
  float local_14;
  float local_10;
  float local_8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_4;
  
  pfVar5 = (float *)0x1;
  local_14 = *(float *)(param_1 + 4) + *(float *)(param_2 + 4) * (float)_DAT_00b313b8;
  local_10 = *(float *)(param_1 + 8) + (float)_DAT_00b313b8 * *(float *)(param_2 + 8);
  *(undefined4 *)param_3 = _DAT_00b313ac;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  if (1 < uVar1) {
    do {
      piVar4 = (int *)((int)pfVar5 * 0x20 + *(int *)(this + 0x24));
      if ((GmVec3 *)piVar4[7] == (GmVec3 *)0xffffffff) {
        iVar3 = GmBoxAligned::TestInterSegment_MiddleVectAB
                          (piVar4 + 1,(GmBoxAligned *)&local_14,param_2,unaff_ESI);
        if (iVar3 != 0) goto LAB_008f205b;
        pfVar5 = (float *)((int)pfVar5 + *piVar4);
      }
      else {
        TriangleClipSegmentNearerThanT
                  (this,(GmSurfMesh *)param_2,param_2,(GmVec3 *)piVar4[7],(ulong)param_4,&local_8,
                   (SPointInTri *)unaff_ESI);
LAB_008f205b:
        pfVar5 = (float *)((int)pfVar5 + 1);
      }
    } while (pfVar5 < param_4);
    if (*(float *)param_5 < 1.0) {
      pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this + 0x10,local_4,(ulong)local_4);
      *in_stack_0000001c = *(undefined2 *)(pSVar2 + 0x1c);
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmSurfMesh::GetMeshBoundingBox
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmSurfMesh::GetMeshBoundingBox(GmSurfMesh *this,GmSurfMesh *param_1,GmBoxAligned *param_2)
{
{
  undefined4 uVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  undefined4 *in_stack_0000000c;
  
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x10,unaff_ESI);
  if (uVar2 != 0) {
    pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                       (this + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        unaff_retaddr);
    *in_stack_0000000c = *(undefined4 *)(pSVar3 + 4);
    in_stack_0000000c[1] = *(undefined4 *)(pSVar3 + 8);
    in_stack_0000000c[2] = *(undefined4 *)(pSVar3 + 0xc);
    in_stack_0000000c[3] = *(undefined4 *)(pSVar3 + 0x10);
    in_stack_0000000c[4] = *(undefined4 *)(pSVar3 + 0x14);
    in_stack_0000000c[5] = *(undefined4 *)(pSVar3 + 0x18);
    return;
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(param_2 + 0xc) = _DAT_00b2c060;
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  *(undefined4 *)(param_2 + 0x14) = uVar1;
  return;
}
}

// =================================================
// Function: GmSurfMesh::GmSurfMesh
// =================================================
void __thiscall GmSurfMesh::GmSurfMesh(GmSurfMesh *this,GmSurfMesh *param_1)
{
{
  GmSurf *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  CFastArray<class_CManoeuvre*> *in_stack_00000008;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000000c;
  
  GmSurf::GmSurf((GmSurf *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 8,unaff_retaddr);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0x10,(CFastArray<class_CManoeuvre*> *)param_1);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x18,in_stack_00000008);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x20,in_stack_0000000c);
  this[6] = (GmSurfMesh)0x7;
  return;
}
}

// =================================================
// Function: GmSurfMesh::TransformByNOMat
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmSurfMesh::TransformByNOMat(GmSurfMesh *this,GmSurfMesh *param_1,GmIso4 *param_2)
{
{
  GmSurfMesh *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  ulong uVar8;
  SCasterCat *pSVar9;
  SCasterCat *pSVar10;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  GmIso3 *unaff_EBP;
  GmIso3 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float10 fVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000010;
  float in_stack_00000018;
  GmSurfMesh *pGVar13;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffd4;
  ulong in_stack_ffffffd8;
  GmSurfMesh *pGStack_24;
  float fStack_18;
  float local_14;
  
  this_00 = this + 8;
  pGVar13 = this;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar7 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar11,(ulong)param_2);
      GmVec3::Mult(pSVar7,unaff_ESI,unaff_EBP);
      pCVar11 = pCVar11 + 1;
    } while (pCVar11 < pCVar6);
  }
  uVar8 = GmMat3::IsIndirect(param_2,(GmMat3 *)unaff_ESI);
  if (uVar8 != 0) {
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this + 0x10,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
    pCStack00000010 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar7 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                           (this + 0x10,pCStack00000010,(ulong)unaff_EBX);
        pCVar11 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar7 + 0x14);
        *(undefined4 *)(pSVar7 + 0x14) = *(undefined4 *)(pSVar7 + 0x18);
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar7 + 0x18) = pCVar11;
        pSVar9 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (pSVar7 + 0x10),(ulong)pGVar13);
        unaff_EBX = (CFastBuffer<class_CCrystalFace*> *)0x8f3f3b;
        pSVar10 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                            (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                      (pSVar7 + 0x14),(ulong)in_stack_ffffffd4);
        fVar3 = *(float *)(pSVar10 + 4) - *(float *)(pSVar9 + 4);
        fVar1 = *(float *)(pSVar10 + 8);
        fVar2 = *(float *)(pSVar9 + 8);
        pGVar13 = (GmSurfMesh *)0x8f3f5f;
        pSVar10 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                            (this_00,pCVar11,in_stack_ffffffd8);
        fVar5 = (fVar1 - fVar2) * (*(float *)(pSVar10 + 8) - *(float *)(pSVar9 + 8)) -
                (*(float *)(pSVar10 + 4) - *(float *)(pSVar9 + 4)) * in_stack_00000018;
        fVar4 = (*(float *)pSVar10 - *(float *)pSVar9) * in_stack_00000018 -
                fVar3 * (*(float *)(pSVar10 + 8) - *(float *)(pSVar9 + 8));
        fVar1 = fVar3 * (*(float *)(pSVar10 + 4) - *(float *)(pSVar9 + 4)) -
                (fVar1 - fVar2) * (*(float *)pSVar10 - *(float *)pSVar9);
        fVar2 = fVar5 * fVar5 + fVar4 * fVar4 + fVar1 * fVar1;
        if (_DAT_00d1fb48 < fVar2) {
          in_stack_ffffffd8 = 0x8f400f;
          fVar12 = (float10)func_0x009c1b40();
          fVar1 = 1.0 / (float)fVar12;
          fVar5 = fVar1 * fStack_18;
          fVar4 = local_14 * fVar1;
          fVar1 = fVar1 * fVar2;
          fStack_18 = fVar5;
          local_14 = fVar4;
        }
        *(float *)pSVar7 = fVar5;
        pCStack00000010 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)fVar3 + 1);
        *(float *)(pSVar7 + 4) = fVar4;
        *(float *)(pSVar7 + 8) = fVar1;
        *(float *)(pSVar7 + 0xc) =
             (-fVar5 * *(float *)pSVar9 - *(float *)(pSVar9 + 4) * fVar4) -
             *(float *)(pSVar9 + 8) * fVar1;
        this = pGStack_24;
        in_stack_ffffffd4 = pCVar11;
      } while (pCStack00000010 < pCVar6);
    }
  }
  uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EBX);
  if (uVar8 != 0) {
    BuildOctree(this,pGVar13);
  }
  return;
}
}

// =================================================
// Function: GmSurfMesh::TriangleClipSegment2NearerThanT
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
GmSurfMesh::TriangleClipSegment2NearerThanT
          (GmSurfMesh *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4,
          int param_5,float *param_6)
{
{
  GmSurfMesh *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  float fVar2;
  GmVec3 *pGVar3;
  SCasterCat *pSVar4;
  ulong uVar5;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  uint uVar8;
  uint uVar9;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  float fStack0000001c;
  undefined4 in_stack_00000020;
  float fStack00000024;
  undefined4 *in_stack_0000002c;
  ulong in_stack_ffffffd0;
  float fVar10;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float afStack_c [3];
  
  pSVar4 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this + 0x10,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3,
                      unaff_EDI);
  pGVar3 = param_3;
  param_4 = (ulong)(*(float *)(pSVar4 + 8) * *(float *)(param_2 + 8) +
                    *(float *)pSVar4 * *(float *)param_2 +
                    *(float *)(pSVar4 + 4) * *(float *)(param_2 + 4) + *(float *)(pSVar4 + 0xc));
  if (param_5 == 0) {
    if ((float)param_4 < 0.0) {
      return 0;
    }
    param_3 = (GmVec3 *)
              -(*(float *)(pSVar4 + 8) * *(float *)(param_3 + 8) +
               *(float *)pSVar4 * *(float *)param_3 +
               *(float *)(pSVar4 + 4) * *(float *)(param_3 + 4));
    if ((float)param_3 < (float)param_4) {
      return 0;
    }
    uVar5 = GmFunc::Div((float *)&param_3,(float)param_4,(float)param_3);
    if (uVar5 == 0) {
      return 0;
    }
  }
  else {
    fVar10 = *(float *)(pSVar4 + 8) * (*(float *)(param_2 + 8) + *(float *)(param_3 + 8)) +
             *(float *)(pSVar4 + 4) * (*(float *)(param_2 + 4) + *(float *)(param_3 + 4)) +
             *(float *)pSVar4 * (*(float *)param_2 + *(float *)param_3) + *(float *)(pSVar4 + 0xc);
    if (-1 < (int)((uint)fVar10 ^ param_4)) {
      return 0;
    }
    param_3 = (GmVec3 *)(fVar10 - (float)param_4);
    uVar5 = GmFunc::Div((float *)&param_3,(float)param_4,(float)param_3);
    if (uVar5 == 0) {
      return 0;
    }
    param_3 = (GmVec3 *)ABS((float)param_3);
  }
  if ((float)param_3 <= *param_6) {
    pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x10);
    fVar10 = *(float *)param_2 + *(float *)pGVar3 * (float)param_3;
    this_00 = this + 8;
    CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this_00,pCVar1,unaff_ESI);
    CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
              (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x14),unaff_EBP
              );
    pSVar6 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this_00,pCVar1,unaff_EBX);
    pSVar7 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x18),
                        in_stack_ffffffd0);
    afStack_c[2] = *(float *)pSVar7 - *(float *)pSVar6;
    pSVar6 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this_00,pCVar1,(ulong)fVar10);
    afStack_c[0] = fStack_18 - *(float *)pSVar6;
    afStack_c[1] = fStack_14 - *(float *)(pSVar6 + 4);
    afStack_c[2] = fStack_10 - *(float *)(pSVar6 + 8);
    fVar10 = ABS(*(float *)pSVar4);
    fStack00000024 = fVar10;
    fVar2 = ABS(*(float *)(pSVar4 + 4));
    if (fVar10 < fVar2) {
      fStack00000024 = fVar2;
    }
    uVar8 = (uint)(fVar10 < fVar2);
    fStack0000001c = ABS(*(float *)(pSVar4 + 8));
    if (fStack00000024 < ABS(*(float *)(pSVar4 + 8))) {
      uVar8 = 2;
    }
    uVar9 = (uVar8 + 1) % 3;
    uVar8 = (uVar8 + 2) % 3;
    GmFunc::SolveLinearSystem2
              (&stack0x00000024,&stack0x0000001c,(float)(&param_3)[uVar9],
               *(float *)(&stack0x00000000 + uVar9 * 4),afStack_c[uVar9],(float)(&param_3)[uVar8],
               *(float *)(&stack0x00000000 + uVar8 * 4),afStack_c[uVar8]);
    if (((0.0 <= fStack00000024) && (0.0 <= fStack0000001c)) &&
       (fStack00000024 + fStack0000001c < (float)_DAT_00b2c188 !=
        (fStack00000024 + fStack0000001c == (float)_DAT_00b2c188))) {
      *in_stack_0000002c = in_stack_00000020;
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmSurfMesh::TriangleClipSegmentNearerThanT
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
GmSurfMesh::TriangleClipSegmentNearerThanT
          (GmSurfMesh *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4,
          float *param_5,SPointInTri *param_6)
{
{
  GmSurfMesh *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  float fVar2;
  float fVar3;
  SCasterCat *pSVar4;
  ulong uVar5;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  uint uVar8;
  uint uVar9;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  float fStack0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 *in_stack_00000028;
  undefined4 *in_stack_0000002c;
  ulong in_stack_ffffffcc;
  ulong in_stack_ffffffd0;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float afStack_c [3];
  
  pSVar4 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this + 0x10,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3,
                      unaff_EDI);
  fVar2 = *(float *)(pSVar4 + 8) * *(float *)(param_2 + 8) +
          *(float *)pSVar4 * *(float *)param_2 + *(float *)(pSVar4 + 4) * *(float *)(param_2 + 4) +
          *(float *)(pSVar4 + 0xc);
  if (fVar2 < 0.0) {
    return 0;
  }
  fVar3 = -(*(float *)(pSVar4 + 8) * *(float *)(param_3 + 8) +
           *(float *)pSVar4 * *(float *)param_3 + *(float *)(param_3 + 4) * *(float *)(pSVar4 + 4));
  if (((fVar2 <= fVar3) && (uVar5 = GmFunc::Div((float *)&param_3,fVar2,fVar3), uVar5 != 0)) &&
     ((float)param_3 <= *param_5)) {
    pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x10);
    this_00 = this + 8;
    CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this_00,pCVar1,unaff_EBX);
    CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
              (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x14),unaff_ESI
              );
    pSVar6 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this_00,pCVar1,unaff_EBP);
    pSVar7 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x18),
                        in_stack_ffffffcc);
    afStack_c[2] = *(float *)pSVar7 - *(float *)pSVar6;
    pSVar6 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this_00,pCVar1,in_stack_ffffffd0);
    afStack_c[0] = fStack_18 - *(float *)pSVar6;
    afStack_c[1] = fStack_14 - *(float *)(pSVar6 + 4);
    afStack_c[2] = fStack_10 - *(float *)(pSVar6 + 8);
    fVar2 = ABS(*(float *)pSVar4);
    fStack0000001c = fVar2;
    fVar3 = ABS(*(float *)(pSVar4 + 4));
    if (fVar2 < fVar3) {
      fStack0000001c = fVar3;
    }
    uVar8 = (uint)(fVar2 < fVar3);
    fStack_1c = ABS(*(float *)(pSVar4 + 8));
    if (fStack0000001c < fStack_1c) {
      uVar8 = 2;
    }
    uVar9 = (uVar8 + 1) % 3;
    uVar8 = (uVar8 + 2) % 3;
    uVar5 = GmFunc::SolveLinearSystem2
                      (&stack0x0000001c,&fStack_1c,(float)(&param_3)[uVar9],
                       *(float *)(&stack0x00000000 + uVar9 * 4),afStack_c[uVar9],
                       (float)(&param_3)[uVar8],*(float *)(&stack0x00000000 + uVar8 * 4),
                       afStack_c[uVar8]);
    if (((uVar5 != 0) && (0.0 <= fStack0000001c)) &&
       ((0.0 <= fStack_1c &&
        (fStack0000001c + fStack_1c < (float)_DAT_00b2c188 !=
         (fStack0000001c + fStack_1c == (float)_DAT_00b2c188))))) {
      if (in_stack_0000002c == (undefined4 *)0x0) {
        *in_stack_00000028 = in_stack_00000020;
        return 1;
      }
      in_stack_0000002c[1] = fStack0000001c;
      in_stack_0000002c[2] = fStack_1c;
      *in_stack_0000002c = in_stack_00000024;
      *in_stack_00000028 = in_stack_00000020;
      return 1;
    }
  }
  return 0;
}
}

