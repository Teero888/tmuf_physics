
/* public: virtual void * __thiscall GmSurfMesh::`vector deleting
 * destructor'(unsigned int) */

void *__thiscall GmSurfMesh::`vector_deleting_destructor'(GmSurfMesh *this,uint param_1)

{
  ~GmSurfMesh(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: void __thiscall GmSurfMesh::Archive(class CClassicArchive &) */

void __thiscall GmSurfMesh::Archive(GmSurfMesh *this, CClassicArchive *param_1)

{
  ulong local_4;

  local_4 = 3;
  CClassicArchive::DoNatural(param_1, &local_4, 1, 0);
  if ((local_4 == 1) || (local_4 == 2)) {
    CFastArray<>::ArchiveCountAndElems((CFastArray<> *)(this + 8), param_1);
    CFastArray<>::ArchiveCountAndElems((CFastArray<> *)(this + 0x10), param_1);
    GmOctree<>::Archive((GmOctree<> *)(this + 0x20), param_1);
    if (*(int *)(param_1 + 8) == 0) {
      BuildOctree(this);
    }
  } else if (local_4 == 3) {
    CFastArray<>::ArchiveCountAndElems((CFastArray<> *)(this + 8), param_1);
    CFastArray<>::ArchiveCountAndElems((CFastArray<> *)(this + 0x10), param_1);
    GmOctree<>::Archive((GmOctree<> *)(this + 0x20), param_1);
    return;
  }
  return;
}

/* public: void __thiscall GmSurfMesh::BuildOctree(void) */

void __thiscall GmSurfMesh::BuildOctree(GmSurfMesh *this)

{
  ulong uVar1;
  SRpcSkinInfo *pSVar2;
  SRpcSkinInfo *pSVar3;
  float *pfVar4;
  ulong uVar5;
  int iVar6;
  ulong *puVar7;
  CFastArray<> local_2c[4];
  SMeshOctreeCell *local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ade6b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastArray<>::CFastArray<>(local_2c);
  uVar5 = 0;
  local_4 = 0;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x10));
  CFastArray<>::SetCount((CFastArray<> *)local_2c, uVar1);
  if (uVar1 != 0) {
    do {
      pSVar2 = CFastBuffer<>::operator[]((CFastBuffer<> *)local_2c, uVar5);
      *(ulong *)(pSVar2 + 0x1c) = uVar5;
      pSVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x10), uVar5);
      pfVar4 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 8),
                                                  *(ulong *)(pSVar3 + 0x10));
      local_24 = *pfVar4;
      puVar7 = (ulong *)(pSVar3 + 0x14);
      local_20 = pfVar4[1];
      iVar6 = 2;
      local_1c = pfVar4[2];
      local_18 = *pfVar4;
      local_14 = pfVar4[1];
      local_10 = pfVar4[2];
      do {
        pfVar4 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 8),
                                                    *puVar7);
        if (*pfVar4 < local_24) {
          local_24 = *pfVar4;
        }
        if (pfVar4[1] < local_20) {
          local_20 = pfVar4[1];
        }
        if (pfVar4[2] < local_1c) {
          local_1c = pfVar4[2];
        }
        if (local_18 < *pfVar4 != (NAN(local_18) || NAN(*pfVar4))) {
          local_18 = *pfVar4;
        }
        if (local_14 < pfVar4[1] != (NAN(local_14) || NAN(pfVar4[1]))) {
          local_14 = pfVar4[1];
        }
        if (local_10 < pfVar4[2] != (NAN(local_10) || NAN(pfVar4[2]))) {
          local_10 = pfVar4[2];
        }
        puVar7 = puVar7 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      uVar5 = uVar5 + 1;
      *(float *)(pSVar2 + 4) = (local_18 + local_24) * 0.5;
      *(float *)(pSVar2 + 8) = (local_20 + local_14) * 0.5;
      *(float *)(pSVar2 + 0xc) = (local_1c + local_10) * 0.5;
      *(float *)(pSVar2 + 0x10) = local_18 - local_24;
      *(float *)(pSVar2 + 0x14) = local_14 - local_20;
      *(float *)(pSVar2 + 0x18) = local_10 - local_1c;
      *(float *)(pSVar2 + 0x10) = *(float *)(pSVar2 + 0x10) * 0.5;
      *(float *)(pSVar2 + 0x14) = *(float *)(pSVar2 + 0x14) * 0.5;
      *(float *)(pSVar2 + 0x18) = *(float *)(pSVar2 + 0x18) * 0.5;
    } while (uVar5 < uVar1);
  }
  GmOctree<>::Build((GmOctree<> *)(this + 0x20), uVar1, local_28, 1, 0, 0, 0.0);
  CFastArray<>::~CFastArray<>((CFastArray<> *)local_2c);
  ExceptionList = local_c;
  return;
}

/* public: int __thiscall GmSurfMesh::ClipSegment(class GmVec3 const &,class
   GmVec3 const &,float
   &,struct GmSurfMesh::SPointInTri *)const  */

int __thiscall GmSurfMesh::ClipSegment(GmSurfMesh *this, GmVec3 *param_1,
                                       GmVec3 *param_2, float *param_3,
                                       SPointInTri *param_4)

{
  ulong uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  float local_c;
  float local_8;
  float local_4;

  uVar4 = 1;
  local_c = *(float *)param_1 + *(float *)param_2 * 0.5;
  local_8 = *(float *)(param_1 + 4) + *(float *)(param_2 + 4) * 0.5;
  local_4 = *(float *)(param_1 + 8) + *(float *)(param_2 + 8) * 0.5;
  *param_3 = 2.0;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x20));
  if (1 < uVar1) {
    do {
      piVar3 = (int *)(uVar4 * 0x20 + *(int *)(this + 0x24));
      if (piVar3[7] == 0xffffffff) {
        iVar2 = GmBoxAligned::TestInterSegment_MiddleVectAB(
            (GmBoxAligned *)(piVar3 + 1), (GmVec3 *)&local_c, param_2);
        if (iVar2 != 0)
          goto LAB_008f1f6b;
        uVar4 = uVar4 + *piVar3;
      } else {
        TriangleClipSegmentNearerThanT(this, param_1, param_2, piVar3[7],
                                       param_3, param_4);
      LAB_008f1f6b:
        uVar4 = uVar4 + 1;
      }
    } while (uVar4 < uVar1);
    if (*param_3 < 1.0) {
      return 1;
    }
  }
  return 0;
}

/* public: int __thiscall GmSurfMesh::ClipSegment2(class GmVec3 const &,class
   GmVec3 const
   &,int,float &,class GmVec3 &)const  */

int __thiscall GmSurfMesh::ClipSegment2(GmSurfMesh *this, GmVec3 *param_1,
                                        GmVec3 *param_2, int param_3,
                                        float *param_4, GmVec3 *param_5)

{
  ulong uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  float local_c;
  float local_8;
  float local_4;

  uVar4 = 1;
  local_c = *(float *)param_1 + *(float *)param_2 * 0.5;
  local_8 = *(float *)(param_1 + 4) + *(float *)(param_2 + 4) * 0.5;
  local_4 = *(float *)(param_1 + 8) + *(float *)(param_2 + 8) * 0.5;
  *param_4 = 2.0;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x20));
  if (1 < uVar1) {
    do {
      piVar5 = (int *)(uVar4 * 0x20 + *(int *)(this + 0x24));
      if (piVar5[7] == 0xffffffff) {
        iVar2 = GmBoxAligned::TestInterSegment_MiddleVectAB(
            (GmBoxAligned *)(piVar5 + 1), (GmVec3 *)&local_c, param_2);
        if (iVar2 != 0)
          goto LAB_008f2183;
        uVar4 = uVar4 + *piVar5;
      } else {
        iVar2 = TriangleClipSegment2NearerThanT(this, param_1, param_2,
                                                piVar5[7], param_3, param_4);
        if (iVar2 != 0) {
          puVar3 = (undefined4 *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(this + 0x10), piVar5[7]);
          *(undefined4 *)param_5 = *puVar3;
          *(undefined4 *)(param_5 + 4) = puVar3[1];
          *(undefined4 *)(param_5 + 8) = puVar3[2];
        }
      LAB_008f2183:
        uVar4 = uVar4 + 1;
      }
    } while (uVar4 < uVar1);
    if (*param_4 < 1.0) {
      return 1;
    }
  }
  return 0;
}

/* public: int __thiscall GmSurfMesh::ClipSegment3(class GmVec3 const &,class
   GmVec3 const &,float
   &,unsigned short &)const  */

int __thiscall GmSurfMesh::ClipSegment3(GmSurfMesh *this, GmVec3 *param_1,
                                        GmVec3 *param_2, float *param_3,
                                        ushort *param_4)

{
  ulong uVar1;
  SRpcSkinInfo *pSVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  float local_18;
  float local_14;
  float local_10;
  ulong local_c[3];

  uVar5 = 1;
  local_18 = *(float *)param_1 + *(float *)param_2 * 0.5;
  local_14 = *(float *)(param_1 + 4) + *(float *)(param_2 + 4) * 0.5;
  local_10 = *(float *)(param_1 + 8) + *(float *)(param_2 + 8) * 0.5;
  *param_3 = 2.0;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x20));
  if (1 < uVar1) {
    do {
      piVar4 = (int *)(uVar5 * 0x20 + *(int *)(this + 0x24));
      if (piVar4[7] == 0xffffffff) {
        iVar3 = GmBoxAligned::TestInterSegment_MiddleVectAB(
            (GmBoxAligned *)(piVar4 + 1), (GmVec3 *)&local_18, param_2);
        if (iVar3 != 0)
          goto LAB_008f205b;
        uVar5 = uVar5 + *piVar4;
      } else {
        TriangleClipSegmentNearerThanT(this, param_1, param_2, piVar4[7],
                                       param_3, (SPointInTri *)local_c);
      LAB_008f205b:
        uVar5 = uVar5 + 1;
      }
    } while (uVar5 < uVar1);
    if (*param_3 < 1.0) {
      pSVar2 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x10), local_c[0]);
      *param_4 = *(ushort *)(pSVar2 + 0x1c);
      return 1;
    }
  }
  return 0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmSurfMesh::ComputePlane(unsigned long) */

void __thiscall GmSurfMesh::ComputePlane(GmSurfMesh *this, ulong param_1)

{
  CFastBuffer<> *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float10 fVar11;

  pfVar8 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x10),
                                              param_1);
  this_00 = (CFastBuffer<> *)(this + 8);
  pfVar9 = (float *)CFastBuffer<>::operator[](this_00, (ulong)pfVar8[4]);
  pfVar10 = (float *)CFastBuffer<>::operator[](this_00, (ulong)pfVar8[5]);
  fVar1 = *pfVar10;
  fVar2 = *pfVar9;
  fVar3 = pfVar10[1];
  fVar4 = pfVar9[1];
  fVar5 = pfVar10[2];
  fVar6 = pfVar9[2];
  pfVar10 = (float *)CFastBuffer<>::operator[](this_00, (ulong)pfVar8[6]);
  fVar7 = (fVar3 - fVar4) * (pfVar10[2] - pfVar9[2]) -
          (pfVar10[1] - pfVar9[1]) * (fVar5 - fVar6);
  fVar5 = (*pfVar10 - *pfVar9) * (fVar5 - fVar6) -
          (fVar1 - fVar2) * (pfVar10[2] - pfVar9[2]);
  fVar1 = (fVar1 - fVar2) * (pfVar10[1] - pfVar9[1]) -
          (fVar3 - fVar4) * (*pfVar10 - *pfVar9);
  fVar2 = fVar7 * fVar7 + fVar5 * fVar5 + fVar1 * fVar1;
  if (_DAT_00d1fb48 < fVar2 != (NAN(_DAT_00d1fb48) || NAN(fVar2))) {
    fVar11 = (float10)__CIsqrt();
    fVar2 = 1.0 / (float)fVar11;
    fVar7 = fVar2 * fVar7;
    fVar5 = fVar5 * fVar2;
    fVar1 = fVar2 * fVar1;
  }
  *pfVar8 = fVar7;
  pfVar8[1] = fVar5;
  pfVar8[2] = fVar1;
  pfVar8[3] = (-fVar7 * *pfVar9 - pfVar9[1] * fVar5) - pfVar9[2] * fVar1;
  return;
}

/* public: void __thiscall GmSurfMesh::GetMeshBoundingBox(class GmBoxAligned
 * &)const  */

void __thiscall GmSurfMesh::GetMeshBoundingBox(GmSurfMesh *this,
                                               GmBoxAligned *param_1)

{
  ulong uVar1;
  SRpcSkinInfo *pSVar2;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x10));
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x20), 0);
    *(undefined4 *)param_1 = *(undefined4 *)(pSVar2 + 4);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(pSVar2 + 8);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(pSVar2 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(pSVar2 + 0x10);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(pSVar2 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(pSVar2 + 0x18);
    return;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 0xc) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x10) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x14) = 0xbf800000;
  return;
}

/* public: __thiscall GmSurfMesh::GmSurfMesh(void) */

GmSurfMesh *__thiscall GmSurfMesh::GmSurfMesh(GmSurfMesh *this)

{
  GmSurf::GmSurf((GmSurf *)this);
  *(undefined ***)this = vftable;
  CFastArray<>::CFastArray<>((CFastArray<> *)(this + 8));
  CFastArray<>::CFastArray<>((CFastArray<> *)(this + 0x10));
  CFastArray<>::CFastArray<>((CFastArray<> *)(this + 0x18));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x20));
  this[6] = (GmSurfMesh)0x7;
  return this;
}

/* public: void __thiscall GmSurfMesh::MergeVertexes(float) */

void __thiscall GmSurfMesh::MergeVertexes(GmSurfMesh *this, float param_1)

{
  CFastArray<> *this_00;
  int iVar1;
  ulong uVar2;
  STexStageCat *pSVar3;
  float *pfVar4;
  ulong uVar5;
  float *pfVar6;
  uint *puVar7;
  ulong *puVar8;
  SRpcSkinInfo *pSVar9;
  undefined4 *puVar10;
  int *piVar11;
  ulong uVar12;
  CFastBuffer<> *this_01;
  uint uVar13;
  uint local_50;
  CFastArray<> local_38[8];
  CFastBuffer<> local_30[12];
  float local_24;
  float local_20;
  float local_1c;
  void *local_14;
  undefined *puStack_10;
  undefined4 local_c;

  local_c = 0xffffffff;
  puStack_10 = &LAB_00ade620;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  this_00 = (CFastArray<> *)(this + 8);
  iVar1 = CFastArray<>::IsEmpty(this_00);
  if (iVar1 == 0) {
    CFastBuffer<>::CFastBuffer<>(local_30);
    local_c = 0;
    CFastArray<>::CFastArray<>(local_38);
    local_c = CONCAT31(local_c._1_3_, 1);
    uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_00);
    CFastArray<>::SetCount((CFastArray<> *)local_38, uVar2);
    pSVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 0);
    CFastBuffer<>::Add((CFastBuffer<> *)local_30, (SCachedValue *)pSVar3);
    uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_00);
    local_50 = 0;
    if (uVar2 != 0) {
      do {
        pfVar4 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00,
                                                    local_50);
        uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_30);
        uVar13 = 0;
        if (uVar5 != 0) {
        LAB_008f22a0:
          pfVar6 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_30,
                                                      uVar13);
          local_24 = *pfVar4 - *pfVar6;
          local_20 = pfVar4[1] - pfVar6[1];
          local_1c = pfVar4[2] - pfVar6[2];
          if (local_1c * local_1c + local_20 * local_20 + local_24 * local_24 <=
              param_1) {
            puVar7 = (uint *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)local_38, local_50);
          } else {
            if (*pfVar6 < *pfVar4 == (NAN(*pfVar6) || NAN(*pfVar4)))
              goto code_r0x008f2305;
            CFastBuffer<>::InsertElemAt((CFastBuffer<> *)local_30, uVar13,
                                        (SRumble *)pfVar4);
            uVar12 = 0;
            if (local_50 != 0) {
              do {
                puVar7 = (uint *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)local_38, uVar12);
                if (uVar13 <= *puVar7) {
                  *puVar7 = *puVar7 + 1;
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < local_50);
            }
            puVar7 = (uint *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)local_38, local_50);
          }
          *puVar7 = uVar13;
          if (uVar5 <= uVar13)
            goto LAB_008f2363;
          goto LAB_008f237d;
        }
      LAB_008f2363:
        CFastBuffer<>::Add((CFastBuffer<> *)local_30, (SCachedValue *)pfVar4);
        puVar8 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_38,
                                                    local_50);
        *puVar8 = uVar5;
      LAB_008f237d:
        local_50 = local_50 + 1;
      } while (local_50 < uVar2);
    }
    this_01 = (CFastBuffer<> *)(this + 0x10);
    local_50 = CFastBuffer<>::GetCount(this_01);
    if (local_50 != 0) {
      uVar2 = 0;
      do {
        pSVar9 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_01, uVar2);
        puVar10 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)local_38, *(ulong *)(pSVar9 + 0x10));
        *(undefined4 *)(pSVar9 + 0x10) = *puVar10;
        puVar10 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)local_38, *(ulong *)(pSVar9 + 0x14));
        *(undefined4 *)(pSVar9 + 0x14) = *puVar10;
        piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_38,
                                                   *(ulong *)(pSVar9 + 0x18));
        iVar1 = *piVar11;
        *(int *)(pSVar9 + 0x18) = iVar1;
        if (((*(int *)(pSVar9 + 0x10) == *(int *)(pSVar9 + 0x14)) ||
             (*(int *)(pSVar9 + 0x10) == iVar1)) ||
            (iVar1 == *(int *)(pSVar9 + 0x14))) {
          CFastArray<>::RemoveAt((CFastArray<> *)this_01, uVar2, 1);
          uVar2 = uVar2 - 1;
          local_50 = local_50 - 1;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_50);
    }
    uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_30);
    CFastArray<>::SetCount((CFastArray<> *)this_00, uVar2);
    CFastArray<>::CopyFromFastArray((CFastArray<> *)this_00,
                                    (CFastArray<> *)local_30);
    CFastArray<>::~CFastArray<>((CFastArray<> *)local_38);
    CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_30);
  }
  ExceptionList = local_14;
  return;
code_r0x008f2305:
  uVar13 = uVar13 + 1;
  if (uVar5 <= uVar13)
    goto LAB_008f2363;
  goto LAB_008f22a0;
}

/* public: void __thiscall GmSurfMesh::SetMerge(class CFastBuffer<struct
   GmSurfMesh::SMeshToMerge> const &) */

void __thiscall GmSurfMesh::SetMerge(GmSurfMesh *this, CFastBuffer<> *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  CFastBuffer<> *this_00;
  ulong uVar22;
  int *piVar23;
  ulong uVar24;
  SSolid *pSVar25;
  float *pfVar26;
  float *pfVar27;
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  uint local_24;
  int local_20;

  this_00 = param_1;
  uVar28 = 0;
  uVar29 = 0;
  uVar22 = CFastBuffer<>::GetCount((CFastBuffer<> *)param_1);
  uVar30 = 0;
  if (uVar22 != 0) {
    do {
      piVar23 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)param_1, uVar30);
      uVar24 = CFastBuffer<>::GetCount((CFastBuffer<> *)(*piVar23 + 0x10));
      uVar28 = uVar28 + uVar24;
      piVar23 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)param_1, uVar30);
      uVar24 = CFastBuffer<>::GetCount((CFastBuffer<> *)(*piVar23 + 8));
      uVar30 = uVar30 + 1;
      uVar29 = uVar29 + uVar24;
    } while (uVar30 < uVar22);
  }
  CFastArray<>::SetCount((CFastArray<> *)(this + 0x10), uVar28);
  CFastArray<>::SetCount((CFastArray<> *)(this + 8), uVar29);
  uVar28 = 0;
  param_1 = (CFastBuffer<> *)0x0;
  local_20 = 0;
  if (uVar22 != 0) {
    do {
      piVar23 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar28);
      uVar29 = CFastBuffer<>::GetCount((CFastBuffer<> *)(*piVar23 + 8));
      uVar30 = 0;
      if (uVar29 != 0) {
        do {
          pSVar25 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar28);
          piVar23 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00,
                                                     uVar28);
          pfVar26 = (float *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(*piVar23 + 8), uVar30);
          fVar1 = *(float *)(pSVar25 + 8);
          fVar2 = pfVar26[1];
          fVar3 = *pfVar26;
          fVar4 = *(float *)(pSVar25 + 4);
          fVar5 = *(float *)(pSVar25 + 0xc);
          fVar6 = pfVar26[2];
          fVar7 = *(float *)(pSVar25 + 0x28);
          fVar8 = *(float *)(pSVar25 + 0x10);
          fVar9 = *pfVar26;
          fVar10 = *(float *)(pSVar25 + 0x14);
          fVar11 = pfVar26[1];
          fVar12 = *(float *)(pSVar25 + 0x18);
          fVar13 = pfVar26[2];
          fVar14 = *(float *)(pSVar25 + 0x2c);
          fVar15 = *(float *)(pSVar25 + 0x1c);
          fVar16 = *pfVar26;
          fVar17 = *(float *)(pSVar25 + 0x20);
          fVar18 = pfVar26[1];
          fVar19 = *(float *)(pSVar25 + 0x24);
          fVar20 = pfVar26[2];
          fVar21 = *(float *)(pSVar25 + 0x30);
          pfVar26 = (float *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(this + 8), (ulong)(param_1 + uVar30));
          uVar30 = uVar30 + 1;
          *pfVar26 = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2 + fVar7;
          pfVar26[1] =
              fVar12 * fVar13 + fVar10 * fVar11 + fVar8 * fVar9 + fVar14;
          pfVar26[2] =
              fVar19 * fVar20 + fVar17 * fVar18 + fVar15 * fVar16 + fVar21;
        } while (uVar30 < uVar29);
      }
      piVar23 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar28);
      uVar30 = CFastBuffer<>::GetCount((CFastBuffer<> *)(*piVar23 + 0x10));
      local_24 = 0;
      if (uVar30 != 0) {
        do {
          piVar23 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00,
                                                     uVar28);
          pfVar26 = (float *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(*piVar23 + 0x10), local_24);
          pfVar27 = (float *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(this + 0x10), local_24 + local_20);
          *(undefined2 *)(pfVar27 + 7) = *(undefined2 *)(pfVar26 + 7);
          pSVar25 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar28);
          *pfVar27 = *(float *)(pSVar25 + 0xc) * pfVar26[2] +
                     *(float *)(pSVar25 + 4) * *pfVar26 +
                     *(float *)(pSVar25 + 8) * pfVar26[1];
          pfVar27[1] = *(float *)(pSVar25 + 0x18) * pfVar26[2] +
                       *(float *)(pSVar25 + 0x14) * pfVar26[1] +
                       *(float *)(pSVar25 + 0x10) * *pfVar26;
          fVar1 = *(float *)(pSVar25 + 0x24) * pfVar26[2] +
                  *(float *)(pSVar25 + 0x20) * pfVar26[1] +
                  *(float *)(pSVar25 + 0x1c) * *pfVar26;
          pfVar27[2] = fVar1;
          pfVar27[3] = pfVar26[3] - (*pfVar27 * *(float *)(pSVar25 + 0x28) +
                                     *(float *)(pSVar25 + 0x2c) * pfVar27[1] +
                                     *(float *)(pSVar25 + 0x30) * fVar1);
          pfVar27[4] = (float)(param_1 + (int)pfVar26[4]);
          pfVar27[5] = (float)(param_1 + (int)pfVar26[5]);
          local_24 = local_24 + 1;
          pfVar27[6] = (float)(param_1 + (int)pfVar26[6]);
        } while (local_24 < uVar30);
      }
      param_1 = param_1 + uVar29;
      local_20 = local_20 + uVar30;
      uVar28 = uVar28 + 1;
    } while (uVar28 < uVar22);
  }
  BuildOctree(this);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmSurfMesh::TransformByNOMat(class GmIso4 const &) */

void __thiscall GmSurfMesh::TransformByNOMat(GmSurfMesh *this, GmIso4 *param_1)

{
  CFastBuffer<> *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  ulong uVar8;
  STexStageCat *this_01;
  GmIso4 *pGVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  ulong uVar13;
  float10 fVar14;

  this_00 = (CFastBuffer<> *)(this + 8);
  uVar8 = CFastBuffer<>::GetCount(this_00);
  uVar13 = 0;
  if (uVar8 != 0) {
    do {
      pGVar9 = param_1;
      this_01 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar13);
      GmVec3::Mult((GmVec3 *)this_01, pGVar9);
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar8);
  }
  uVar8 = GmMat3::IsIndirect((GmMat3 *)param_1);
  if (uVar8 != 0) {
    pGVar9 = (GmIso4 *)CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x10));
    param_1 = (GmIso4 *)0x0;
    if (pGVar9 != (GmIso4 *)0x0) {
      do {
        pfVar10 = (float *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x10), (ulong)param_1);
        fVar7 = pfVar10[5];
        pfVar10[5] = pfVar10[6];
        pfVar10[6] = fVar7;
        pfVar11 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00,
                                                     (ulong)pfVar10[4]);
        pfVar12 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00,
                                                     (ulong)pfVar10[5]);
        fVar1 = *pfVar12;
        fVar2 = *pfVar11;
        fVar3 = pfVar12[1];
        fVar4 = pfVar11[1];
        fVar5 = pfVar12[2];
        fVar6 = pfVar11[2];
        pfVar12 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00,
                                                     (ulong)fVar7);
        fVar7 = (fVar3 - fVar4) * (pfVar12[2] - pfVar11[2]) -
                (pfVar12[1] - pfVar11[1]) * (fVar5 - fVar6);
        fVar5 = (*pfVar12 - *pfVar11) * (fVar5 - fVar6) -
                (fVar1 - fVar2) * (pfVar12[2] - pfVar11[2]);
        fVar1 = (fVar1 - fVar2) * (pfVar12[1] - pfVar11[1]) -
                (fVar3 - fVar4) * (*pfVar12 - *pfVar11);
        fVar2 = fVar7 * fVar7 + fVar5 * fVar5 + fVar1 * fVar1;
        if (_DAT_00d1fb48 < fVar2 != (NAN(_DAT_00d1fb48) || NAN(fVar2))) {
          fVar14 = (float10)__CIsqrt();
          fVar2 = 1.0 / (float)fVar14;
          fVar7 = fVar2 * fVar7;
          fVar5 = fVar5 * fVar2;
          fVar1 = fVar2 * fVar1;
        }
        *pfVar10 = fVar7;
        param_1 = param_1 + 1;
        pfVar10[1] = fVar5;
        pfVar10[2] = fVar1;
        pfVar10[3] =
            (-fVar7 * *pfVar11 - pfVar11[1] * fVar5) - pfVar11[2] * fVar1;
      } while (param_1 < pGVar9);
    }
  }
  uVar8 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x20));
  if (uVar8 != 0) {
    BuildOctree(this);
  }
  return;
}

/* private: int __thiscall GmSurfMesh::TriangleClipSegment2NearerThanT(class
   GmVec3 const &,class GmVec3 const &,unsigned long,int,float &)const  */

int __thiscall GmSurfMesh::TriangleClipSegment2NearerThanT(
    GmSurfMesh *this, GmVec3 *param_1, GmVec3 *param_2, ulong param_3,
    int param_4, float *param_5)

{
  CFastBuffer<> *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  GmVec3 *pGVar9;
  GmVec3 *pGVar10;
  float *pfVar11;
  ulong uVar12;
  float *pfVar13;
  float *pfVar14;
  uint uVar15;
  uint uVar16;
  float afStack_24[4];
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;

  pfVar11 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x10),
                                               param_3);
  pGVar10 = param_2;
  pGVar9 = param_1;
  param_3 = (ulong)(pfVar11[2] * *(float *)(param_1 + 8) +
                    *pfVar11 * *(float *)param_1 +
                    pfVar11[1] * *(float *)(param_1 + 4) + pfVar11[3]);
  if (param_4 == 0) {
    if ((float)param_3 < 0.0 != NAN((float)param_3)) {
      return 0;
    }
    param_2 = (GmVec3 *)-(pfVar11[2] * *(float *)(param_2 + 8) +
                          *pfVar11 * *(float *)param_2 +
                          pfVar11[1] * *(float *)(param_2 + 4));
    if ((float)param_2 < (float)param_3 !=
        (NAN((float)param_2) || NAN((float)param_3))) {
      return 0;
    }
    uVar12 = GmFunc::Div((float *)&param_2, (float)param_3, (float)param_2);
    if (uVar12 == 0) {
      return 0;
    }
  } else {
    fVar1 = pfVar11[2] * (*(float *)(param_1 + 8) + *(float *)(param_2 + 8)) +
            pfVar11[1] * (*(float *)(param_1 + 4) + *(float *)(param_2 + 4)) +
            *pfVar11 * (*(float *)param_1 + *(float *)param_2) + pfVar11[3];
    if (-1 < (int)((uint)fVar1 ^ param_3)) {
      return 0;
    }
    param_2 = (GmVec3 *)(fVar1 - (float)param_3);
    uVar12 = GmFunc::Div((float *)&param_2, (float)param_3, (float)param_2);
    if (uVar12 == 0) {
      return 0;
    }
    param_2 = (GmVec3 *)ABS((float)param_2);
  }
  if (*param_5 < (float)param_2 == (NAN(*param_5) || NAN((float)param_2))) {
    fVar6 = *(float *)pGVar10 * (float)param_2;
    fVar8 = (float)param_2 * *(float *)(pGVar10 + 4);
    fVar7 = (float)param_2 * *(float *)(pGVar10 + 8);
    fVar4 = pfVar11[4];
    fVar1 = *(float *)pGVar9;
    fVar2 = *(float *)(pGVar9 + 4);
    fVar3 = *(float *)(pGVar9 + 8);
    this_00 = (CFastBuffer<> *)(this + 8);
    pfVar13 = (float *)CFastBuffer<>::operator[](this_00, (ulong)fVar4);
    pfVar14 = (float *)CFastBuffer<>::operator[](this_00, (ulong)pfVar11[5]);
    fStack_c = *pfVar14 - *pfVar13;
    fStack_8 = pfVar14[1] - pfVar13[1];
    fStack_4 = pfVar14[2] - pfVar13[2];
    pfVar13 = (float *)CFastBuffer<>::operator[](this_00, (ulong)fVar4);
    pfVar14 = (float *)CFastBuffer<>::operator[](this_00, (ulong)pfVar11[6]);
    afStack_24[3] = *pfVar14 - *pfVar13;
    fStack_14 = pfVar14[1] - pfVar13[1];
    fStack_10 = pfVar14[2] - pfVar13[2];
    pfVar13 = (float *)CFastBuffer<>::operator[](this_00, (ulong)fVar4);
    afStack_24[0] = (fVar1 + fVar6) - *pfVar13;
    afStack_24[1] = (fVar2 + fVar8) - pfVar13[1];
    afStack_24[2] = (fVar3 + fVar7) - pfVar13[2];
    param_3 = (ulong)ABS(*pfVar11);
    fVar1 = ABS(pfVar11[1]);
    bVar5 = (float)param_3 < fVar1 != (NAN((float)param_3) || NAN(fVar1));
    if (bVar5) {
      param_3 = (ulong)fVar1;
    }
    uVar15 = (uint)bVar5;
    param_1 = (GmVec3 *)ABS(pfVar11[2]);
    if ((float)param_3 < (float)param_1 !=
        (NAN((float)param_3) || NAN((float)param_1))) {
      uVar15 = 2;
    }
    uVar16 = (uVar15 + 1) % 3;
    uVar15 = (uVar15 + 2) % 3;
    GmFunc::SolveLinearSystem2((float *)&param_3, (float *)&param_1,
                               afStack_24[uVar16 + 6], afStack_24[uVar16 + 3],
                               afStack_24[uVar16], afStack_24[uVar15 + 6],
                               afStack_24[uVar15 + 3], afStack_24[uVar15]);
    if (((0.0 <= (float)param_3) && (0.0 <= (float)param_1)) &&
        ((float)param_3 + (float)param_1 < 1.0 !=
         ((float)param_3 + (float)param_1 == 1.0))) {
      *param_5 = (float)param_2;
      return 1;
    }
  }
  return 0;
}

/* private: int __thiscall GmSurfMesh::TriangleClipSegmentNearerThanT(class
   GmVec3 const &,class GmVec3 const &,unsigned long,float &,struct
   GmSurfMesh::SPointInTri *)const  */

int __thiscall GmSurfMesh::TriangleClipSegmentNearerThanT(
    GmSurfMesh *this, GmVec3 *param_1, GmVec3 *param_2, ulong param_3,
    float *param_4, SPointInTri *param_5)

{
  CFastBuffer<> *this_00;
  float fVar1;
  bool bVar2;
  GmVec3 *pGVar3;
  GmVec3 *pGVar4;
  float *pfVar5;
  ulong uVar6;
  float *pfVar7;
  float *pfVar8;
  uint uVar9;
  uint uVar10;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float afStack_24[4];
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;

  pfVar5 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x10),
                                              param_3);
  pGVar4 = param_2;
  pGVar3 = param_1;
  fVar1 = pfVar5[2] * *(float *)(param_1 + 8) + *pfVar5 * *(float *)param_1 +
          pfVar5[1] * *(float *)(param_1 + 4) + pfVar5[3];
  if (fVar1 < 0.0 != NAN(fVar1)) {
    return 0;
  }
  param_1 = (GmVec3 *)-(pfVar5[2] * *(float *)(param_2 + 8) +
                        *pfVar5 * *(float *)param_2 +
                        *(float *)(param_2 + 4) * pfVar5[1]);
  if ((((float)param_1 < fVar1 == (NAN((float)param_1) || NAN(fVar1))) &&
       (uVar6 = GmFunc::Div((float *)&param_2, fVar1, (float)param_1),
        uVar6 != 0)) &&
      (*param_4 < (float)param_2 == (NAN(*param_4) || NAN((float)param_2)))) {
    fVar1 = pfVar5[4];
    fStack_30 = *(float *)pGVar3 + *(float *)pGVar4 * (float)param_2;
    fStack_2c =
        *(float *)(pGVar3 + 4) + *(float *)(pGVar4 + 4) * (float)param_2;
    this_00 = (CFastBuffer<> *)(this + 8);
    fStack_28 =
        *(float *)(pGVar3 + 8) + (float)param_2 * *(float *)(pGVar4 + 8);
    pfVar7 = (float *)CFastBuffer<>::operator[](this_00, (ulong)fVar1);
    pfVar8 = (float *)CFastBuffer<>::operator[](this_00, (ulong)pfVar5[5]);
    fStack_c = *pfVar8 - *pfVar7;
    fStack_8 = pfVar8[1] - pfVar7[1];
    fStack_4 = pfVar8[2] - pfVar7[2];
    pfVar7 = (float *)CFastBuffer<>::operator[](this_00, (ulong)fVar1);
    pfVar8 = (float *)CFastBuffer<>::operator[](this_00, (ulong)pfVar5[6]);
    afStack_24[3] = *pfVar8 - *pfVar7;
    fStack_14 = pfVar8[1] - pfVar7[1];
    fStack_10 = pfVar8[2] - pfVar7[2];
    pfVar7 = (float *)CFastBuffer<>::operator[](this_00, (ulong)fVar1);
    afStack_24[0] = fStack_30 - *pfVar7;
    afStack_24[1] = fStack_2c - pfVar7[1];
    afStack_24[2] = fStack_28 - pfVar7[2];
    param_1 = (GmVec3 *)ABS(*pfVar5);
    pGVar3 = (GmVec3 *)ABS(pfVar5[1]);
    bVar2 = (float)param_1 < (float)pGVar3 !=
            (NAN((float)param_1) || NAN((float)pGVar3));
    if (bVar2) {
      param_1 = pGVar3;
    }
    uVar9 = (uint)bVar2;
    fStack_34 = ABS(pfVar5[2]);
    if ((float)param_1 < fStack_34 != (NAN((float)param_1) || NAN(fStack_34))) {
      uVar9 = 2;
    }
    uVar10 = (uVar9 + 1) % 3;
    uVar9 = (uVar9 + 2) % 3;
    uVar6 = GmFunc::SolveLinearSystem2(
        (float *)&param_1, &fStack_34, afStack_24[uVar10 + 6],
        afStack_24[uVar10 + 3], afStack_24[uVar10], afStack_24[uVar9 + 6],
        afStack_24[uVar9 + 3], afStack_24[uVar9]);
    if (((uVar6 != 0) && (0.0 <= (float)param_1)) &&
        ((0.0 <= fStack_34 && ((float)param_1 + fStack_34 < 1.0 !=
                               ((float)param_1 + fStack_34 == 1.0))))) {
      if (param_5 == (SPointInTri *)0x0) {
        *param_4 = (float)param_2;
        return 1;
      }
      *(GmVec3 **)(param_5 + 4) = param_1;
      *(float *)(param_5 + 8) = fStack_34;
      *(ulong *)param_5 = param_3;
      *param_4 = (float)param_2;
      return 1;
    }
  }
  return 0;
}

/* public: virtual __thiscall GmSurfMesh::~GmSurfMesh(void) */

void __thiscall GmSurfMesh::~GmSurfMesh(GmSurfMesh *this)

{
  *(undefined ***)this = vftable;
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x20));
  CFastArray<>::~CFastArray<>((CFastArray<> *)(this + 0x18));
  CFastArray<>::~CFastArray<>((CFastArray<> *)(this + 0x10));
  CFastArray<>::~CFastArray<>((CFastArray<> *)(this + 8));
  GmSurf::~GmSurf((GmSurf *)this);
  return;
}
