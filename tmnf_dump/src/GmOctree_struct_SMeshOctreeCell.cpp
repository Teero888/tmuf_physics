// Class implementation: GmOctree_struct_SMeshOctreeCell

// =================================================
// Function: GmOctree<struct_SMeshOctreeCell>::Archive
// =================================================
void __thiscall
GmOctree<struct_SMeshOctreeCell>::Archive
          (void *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2)
{
{
  ulong uVar1;
  CClassicArchive *unaff_ESI;
  int unaff_EDI;
  ulong unaff_retaddr;
  CFastBuffer<class_CCrystalFace*> *pCVar2;
  
  pCVar2 = (CFastBuffer<class_CCrystalFace*> *)0x3;
  CClassicArchive::DoNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffffc,(ulong *)0x1,0,unaff_EDI
            );
  if (unaff_retaddr == 1) {
    CFastBuffer<struct_SMeshOctreeCell>::ArchiveFastBuffer
              (this,(CFastBuffer<class_CGameCtnChallengeGroup*> *)param_1,unaff_ESI);
  }
  else {
    if (unaff_retaddr == 2) {
      CFastBuffer<struct_SMeshOctreeCell>::ArchiveCount
                (this,(CFastArray<class_CPlugFileSnd*> *)param_1,unaff_ESI);
      uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this,pCVar2);
      CClassicArchive::DoData
                ((CClassicArchive *)param_1,*(CNetNod_CheckedArchive **)((int)this + 4),
                 (void *)(uVar1 << 5),unaff_retaddr);
      return;
    }
    if (unaff_retaddr == 3) {
      CFastBuffer<struct_CPlugModelMesh::SLineColor>::ArchiveCountAndElems
                (this,(CFastArray<struct_SOldLetter> *)param_1,unaff_ESI);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: GmOctree<struct_SMeshOctreeCell>::Build
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmOctree<struct_SMeshOctreeCell>::Build
          (void *this,NvStripInfo *param_1,
          vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> *param_2,
          vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *param_3)
{
{
  undefined4 uVar1;
  SLoadedLight *pSVar2;
  SCasterCat *pSVar3;
  ulong uVar4;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  SMeshOctreeCell *unaff_retaddr;
  ulong in_stack_00000010;
  int in_stack_00000014;
  ulong in_stack_00000018;
  ulong in_stack_0000001c;
  ulong in_stack_00000020;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_EDI);
  pSVar2 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem(this,unaff_ESI);
  *(undefined4 *)(pSVar2 + 0x1c) = 0xffffffff;
  *(undefined4 *)pSVar2 = 0xffffffff;
  *(undefined4 *)(pSVar2 + 0xc) = 0;
  *(undefined4 *)(pSVar2 + 8) = 0;
  *(undefined4 *)(pSVar2 + 4) = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(pSVar2 + 0x10) = _DAT_00b2c060;
  *(undefined4 *)(pSVar2 + 0x14) = uVar1;
  *(undefined4 *)(pSVar2 + 0x18) = uVar1;
  if (in_stack_00000014 == 0) {
    BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)param_3,in_stack_00000010,
                       unaff_retaddr);
  }
  else {
    BuildBintreeRecurse(this,(GmQuadTree<struct_SQuadTreeMeshUv> *)param_3,in_stack_00000010,
                        (SQuadTreeMeshUv *)0x0,in_stack_00000018,in_stack_0000001c,in_stack_00000020
                        ,(float)unaff_retaddr);
  }
  pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)param_1);
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this,(CFastBuffer<class_CCrystalFace*> *)param_2);
  *(ulong *)pSVar3 = uVar4;
  return;
}
}

// =================================================
// Function: GmOctree<struct_SMeshOctreeCell>::BuildOctreeRecurse
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
GmOctree<struct_SMeshOctreeCell>::BuildOctreeRecurse
          (void *this,GmOctree<struct_SMeshOctreeCell> *param_1,ulong param_2,
          SMeshOctreeCell *param_3)
{
{
  float fVar1;
  undefined4 uVar2;
  GmVec2 *pGVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  int iVar6;
  SLoadedLight *pSVar7;
  SLoadedLight *pSVar8;
  ulong unaff_EBX;
  GmOctree<struct_SMeshOctreeCell> *unaff_EBP;
  GmOctree<struct_SMeshOctreeCell> *pGVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  undefined4 *puVar13;
  ulong unaff_EDI;
  GmRectAligned *pGVar14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar15;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar17;
  int unaff_retaddr;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffeb0;
  ulong in_stack_fffffeb4;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffeb8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffebc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffec0;
  TiXmlAttribute *in_stack_fffffec4;
  SMeshOctreeCell *in_stack_fffffec8;
  ulong in_stack_fffffecc;
  GmFrustumIso4 *pGVar18;
  SMeshOctreeCell *in_stack_fffffedc;
  float in_stack_fffffee0;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_fffffee4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffee8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffeec;
  SMeshOctreeCell *pSVar19;
  ulong in_stack_fffffef4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffefc;
  TiXmlAttribute *pTVar20;
  SMeshOctreeCell *in_stack_ffffff04;
  float fVar21;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff0c;
  TiXmlAttribute *pTVar22;
  SMeshOctreeCell *pSVar23;
  float fVar24;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar25;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff28;
  TiXmlAttribute *pTVar26;
  TiXmlAttribute *in_stack_ffffff2c;
  TiXmlAttribute *pTVar27;
  float in_stack_ffffff30;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff34;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff38;
  TiXmlAttribute *in_stack_ffffff3c;
  SMeshOctreeCell *in_stack_ffffff40;
  ulong in_stack_ffffff44;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar28;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff4c;
  undefined4 in_stack_ffffff50;
  TiXmlAttribute *pTVar29;
  SMeshOctreeCell *in_stack_ffffff54;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff58;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff5c;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffff60;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar30;
  ulong uStack_84;
  undefined1 local_80 [4];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_7c;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [8];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_68;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_54;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_40;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ade650;
  local_c = ExceptionList;
  pGVar3 = (GmVec2 *)(DAT_00cca150 ^ (uint)&stack0xffffff6c);
  ExceptionList = &local_c;
  if (param_1 == (GmOctree<struct_SMeshOctreeCell> *)0x0) {
    uStack_84 = 0;
  }
  else {
    local_24 = *(undefined4 *)(param_2 + 4);
    local_20 = *(undefined4 *)(param_2 + 8);
    local_1c = *(undefined4 *)(param_2 + 0xc);
    local_18 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_2 + 0x10);
    local_14 = *(undefined4 *)(param_2 + 0x14);
    local_10 = *(undefined4 *)(param_2 + 0x18);
    local_7c = this;
    if ((GmOctree<struct_SMeshOctreeCell> *)0x1 < param_1) {
      pGVar14 = (GmRectAligned *)(param_2 + 0x24);
      pGVar9 = param_1 + -1;
      do {
        in_stack_ffffff60 = (CFastBuffer<class_CPlugFileGPUV*> *)0x8f250b;
        GmBoxAligned::Union(&local_24,pGVar14,pGVar3);
        pGVar14 = pGVar14 + 0x20;
        pGVar9 = pGVar9 + -1;
      } while (pGVar9 != (GmOctree<struct_SMeshOctreeCell> *)0x0);
    }
    pCVar30 = (CFastBuffer<class_CPlugFileGPUV*> *)0x8f251a;
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this,(CFastBuffer<class_CCrystalFace*> *)pGVar3);
    if (uVar4 != 0) {
      pCVar30 = (CFastBuffer<class_CPlugFileGPUV*> *)0x8f2529;
      pSVar5 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar4 - 1),
                          unaff_EDI);
      *(undefined4 *)(pSVar5 + 4) = local_1c;
      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar5 + 8) = local_18;
      *(undefined4 *)(pSVar5 + 0xc) = local_14;
      *(undefined4 *)(pSVar5 + 0x10) = local_10;
      *(void **)(pSVar5 + 0x14) = local_c;
      *(undefined1 **)(pSVar5 + 0x18) = local_8;
    }
    pTVar27 = in_stack_ffffff2c;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&stack0xfffffedc,in_stack_fffffeb0);
    pCVar28 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    CFastBuffer<struct_CPlugModelMesh::SPoly>::AllocSetCount
              (&stack0xfffffee0,(CFastBuffer<class_GxVertex2> *)param_1,in_stack_fffffeb4);
    pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xfffffee0,pCVar15,in_stack_fffffeb4);
        *(undefined4 *)pSVar5 = 0;
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar5 + 4) = pCVar15;
        pCVar15 = pCVar15 + 1;
      } while (pCVar15 < param_1);
    }
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              ((float)in_stack_ffffff34 - (float)in_stack_ffffff40);
    pSVar19 = (SMeshOctreeCell *)((float)pTVar27 - (float)in_stack_ffffff38);
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pCVar10 = in_stack_ffffff58 + 4;
      do {
        iVar6 = GmBoxAligned::TestInter
                          (pCVar10,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar6 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x8f26ba;
          in_stack_fffffebc = pCVar16;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar16,(ulong)in_stack_fffffec0);
          *(uint *)pSVar5 = *(uint *)pSVar5 | 1;
        }
        pCVar16 = pCVar16 + 1;
        pCVar10 = pCVar10 + 0x20;
      } while (pCVar16 < param_1);
    }
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pCVar10 = in_stack_ffffff58 + 4;
      do {
        iVar6 = GmBoxAligned::TestInter
                          (pCVar10,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar6 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x8f27b0;
          in_stack_fffffebc = pCVar16;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar16,(ulong)in_stack_fffffec0);
          *(uint *)pSVar5 = *(uint *)pSVar5 | 2;
        }
        pCVar16 = pCVar16 + 1;
        pCVar10 = pCVar10 + 0x20;
      } while (pCVar16 < param_1);
    }
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pCVar10 = in_stack_ffffff58 + 4;
      do {
        iVar6 = GmBoxAligned::TestInter
                          (pCVar10,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar6 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x8f28aa;
          in_stack_fffffebc = pCVar16;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar16,(ulong)in_stack_fffffec0);
          *(uint *)pSVar5 = *(uint *)pSVar5 | 4;
        }
        pCVar16 = pCVar16 + 1;
        pCVar10 = pCVar10 + 0x20;
      } while (pCVar16 < param_1);
    }
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pCVar10 = in_stack_ffffff58 + 4;
      do {
        iVar6 = GmBoxAligned::TestInter
                          (pCVar10,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar6 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x8f29a0;
          in_stack_fffffebc = pCVar16;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar16,(ulong)in_stack_fffffec0);
          *(uint *)pSVar5 = *(uint *)pSVar5 | 8;
        }
        pCVar16 = pCVar16 + 1;
        pCVar10 = pCVar10 + 0x20;
      } while (pCVar16 < param_1);
    }
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pCVar10 = in_stack_ffffff58 + 4;
      do {
        iVar6 = GmBoxAligned::TestInter
                          (pCVar10,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar6 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x8f2a9a;
          in_stack_fffffebc = pCVar16;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar16,(ulong)in_stack_fffffec0);
          *(uint *)pSVar5 = *(uint *)pSVar5 | 0x10;
        }
        pCVar16 = pCVar16 + 1;
        pCVar10 = pCVar10 + 0x20;
      } while (pCVar16 < param_1);
    }
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pCVar10 = in_stack_ffffff58 + 4;
      do {
        iVar6 = GmBoxAligned::TestInter
                          (pCVar10,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar6 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x8f2b90;
          in_stack_fffffebc = pCVar16;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar16,(ulong)in_stack_fffffec0);
          *(uint *)pSVar5 = *(uint *)pSVar5 | 0x20;
        }
        pCVar16 = pCVar16 + 1;
        pCVar10 = pCVar10 + 0x20;
      } while (pCVar16 < param_1);
    }
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pCVar10 = in_stack_ffffff58 + 4;
      do {
        iVar6 = GmBoxAligned::TestInter
                          (pCVar10,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar6 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x8f2c8a;
          in_stack_fffffebc = pCVar16;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar16,(ulong)in_stack_fffffec0);
          *(uint *)pSVar5 = *(uint *)pSVar5 | 0x40;
        }
        pCVar16 = pCVar16 + 1;
        pCVar10 = pCVar10 + 0x20;
      } while (pCVar16 < param_1);
    }
    fVar1 = (float)_DAT_00b313b8;
    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              ((float)in_stack_ffffff34 + (float)in_stack_ffffff40);
    pTVar20 = (TiXmlAttribute *)(in_stack_ffffff30 + (float)in_stack_ffffff3c);
    fVar21 = (float)pTVar27 + (float)in_stack_ffffff38;
    pTVar22 = (TiXmlAttribute *)((fVar21 + (float)in_stack_ffffff2c) * fVar1);
    pSVar23 = (SMeshOctreeCell *)(((float)pTVar20 + (float)in_stack_fffffedc) * fVar1);
    fVar24 = ((float)pCVar16 + in_stack_fffffee0) * fVar1;
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              ((fVar21 - (float)in_stack_ffffff2c) * fVar1);
    pCVar25 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              (((float)pTVar20 - (float)in_stack_fffffedc) * fVar1);
    pTVar26 = (TiXmlAttribute *)(fVar1 * ((float)pCVar16 - in_stack_fffffee0));
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pCVar11 = in_stack_ffffff58 + 4;
      do {
        iVar6 = GmBoxAligned::TestInter
                          (pCVar11,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar6 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x8f2d7a;
          in_stack_fffffebc = pCVar17;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar17,(ulong)in_stack_fffffec0);
          *(uint *)pSVar5 = *(uint *)pSVar5 | 0x80;
        }
        pCVar17 = pCVar17 + 1;
        pCVar11 = pCVar11 + 0x20;
      } while (pCVar17 < param_1);
    }
    pCVar11 = in_stack_ffffff58;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&stack0xfffffed8,in_stack_fffffeb8);
    pTVar29 = (TiXmlAttribute *)CONCAT31((int3)((uint)in_stack_ffffff50 >> 8),1);
    pGVar18 = (GmFrustumIso4 *)0x1;
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xfffffedc,(GmFrustumIso4 *)in_stack_fffffebc);
    pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCVar17 = in_stack_fffffeec;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xfffffeec,pCVar12,(ulong)in_stack_fffffec0);
        if (*(int *)pSVar5 == 1) {
          CFastBuffer<class_GmReal4_64>::Add
                    (&stack0xfffffee4,
                     (TiXmlAttributeSet *)(in_stack_ffffff58 + *(int *)(pSVar5 + 4) * 0x20),
                     in_stack_fffffec4);
          in_stack_fffffec4 = (TiXmlAttribute *)0x1;
          in_stack_fffffec0 = pCVar12;
          in_stack_fffffeec = pCVar16;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xfffffef4,(CFastBufferRef<class_CGameMobil> *)pCVar12,1,
                     (ulong)in_stack_fffffec8);
          pCVar16 = in_stack_fffffeec;
        }
        else {
          pCVar12 = pCVar12 + 1;
        }
      } while (pCVar12 < in_stack_fffffeec);
    }
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xfffffee0,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffec0);
    if (uVar4 != 0) {
      pCVar12 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar7 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pGVar18);
      *(undefined4 *)(pSVar7 + 0x1c) = 0xffffffff;
      *(undefined4 *)pSVar7 = 0xffffffff;
      *(undefined4 *)(pSVar7 + 0xc) = 0;
      *(undefined4 *)(pSVar7 + 8) = 0;
      *(undefined4 *)(pSVar7 + 4) = 0;
      uVar2 = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x10) = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x14) = uVar2;
      *(undefined4 *)(pSVar7 + 0x18) = uVar2;
      uVar4 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)in_stack_fffffee8,
                                 (ulong)pCVar17,in_stack_fffffec8);
      pSVar5 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this,pCVar12,in_stack_fffffecc);
      *(ulong *)pSVar5 = uVar4;
      in_stack_fffffee4 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)(uVar4 + 1);
      in_stack_ffffff58 = unaff_ESI;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&stack0xfffffef0,pGVar18);
    pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff00,pCVar12,(ulong)in_stack_ffffff28);
        if (*(int *)pSVar5 == 2) {
          CFastBuffer<class_GmReal4_64>::Add
                    (&stack0xfffffef8,
                     (TiXmlAttributeSet *)(in_stack_ffffff58 + *(int *)(pSVar5 + 4) * 0x20),
                     in_stack_ffffff2c);
          in_stack_ffffff2c = (TiXmlAttribute *)0x1;
          in_stack_ffffff28 = pCVar12;
          in_stack_fffffeec = in_stack_ffffff0c;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff08,(CFastBufferRef<class_CGameMobil> *)pCVar12,1,
                     (ulong)in_stack_fffffedc);
          in_stack_ffffff0c = in_stack_fffffeec;
        }
        else {
          pCVar12 = pCVar12 + 1;
        }
      } while (pCVar12 < in_stack_fffffeec);
    }
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xfffffef4,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff28);
    if (uVar4 != 0) {
      pCVar12 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar7 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                         (this,in_stack_fffffee4);
      *(undefined4 *)(pSVar7 + 0x1c) = 0xffffffff;
      *(undefined4 *)pSVar7 = 0xffffffff;
      *(undefined4 *)(pSVar7 + 0xc) = 0;
      *(undefined4 *)(pSVar7 + 8) = 0;
      *(undefined4 *)(pSVar7 + 4) = 0;
      uVar2 = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x10) = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x14) = uVar2;
      *(undefined4 *)(pSVar7 + 0x18) = uVar2;
      uVar4 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)in_stack_fffffefc,
                                 (ulong)pTVar20,in_stack_fffffedc);
      pSVar5 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this,pCVar12,(ulong)in_stack_fffffee0);
      pCVar16 = pCVar16 + uVar4;
      *(ulong *)pSVar5 = uVar4;
      in_stack_ffffff58 = local_7c;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff04,(GmFrustumIso4 *)in_stack_fffffee4);
    pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff14,pCVar12,(ulong)in_stack_fffffee8);
        if (*(int *)pSVar5 == 4) {
          CFastBuffer<class_GmReal4_64>::Add
                    (&stack0xffffff0c,
                     (TiXmlAttributeSet *)(in_stack_ffffff58 + *(int *)(pSVar5 + 4) * 0x20),
                     (TiXmlAttribute *)pCVar17);
          pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
          in_stack_fffffee8 = pCVar12;
          in_stack_fffffeec = pCVar10;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff1c,(CFastBufferRef<class_CGameMobil> *)pCVar12,1,(ulong)pSVar19);
          pCVar10 = in_stack_fffffeec;
        }
        else {
          pCVar12 = pCVar12 + 1;
        }
      } while (pCVar12 < in_stack_fffffeec);
    }
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff08,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffee8);
    if (uVar4 != 0) {
      pCVar17 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar7 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar16);
      *(undefined4 *)(pSVar7 + 0x1c) = 0xffffffff;
      *(undefined4 *)pSVar7 = 0xffffffff;
      *(undefined4 *)(pSVar7 + 0xc) = 0;
      *(undefined4 *)(pSVar7 + 8) = 0;
      *(undefined4 *)(pSVar7 + 4) = 0;
      uVar2 = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x10) = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x14) = uVar2;
      *(undefined4 *)(pSVar7 + 0x18) = uVar2;
      uVar4 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)pCVar15,(ulong)pTVar22,
                                 pSVar19);
      pSVar5 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this,pCVar17,in_stack_fffffef4);
      in_stack_ffffff0c = in_stack_ffffff0c + uVar4;
      *(ulong *)pSVar5 = uVar4;
      in_stack_ffffff58 = local_68;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff18,(GmFrustumIso4 *)pCVar16);
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff28,pCVar16,(ulong)in_stack_fffffefc);
        if (*(int *)pSVar5 == 8) {
          CFastBuffer<class_GmReal4_64>::Add
                    (&stack0xffffff20,
                     (TiXmlAttributeSet *)(in_stack_ffffff58 + *(int *)(pSVar5 + 4) * 0x20),pTVar20)
          ;
          pTVar20 = (TiXmlAttribute *)0x1;
          in_stack_fffffefc = pCVar16;
          in_stack_fffffeec = in_stack_ffffff34;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff30,(CFastBufferRef<class_CGameMobil> *)pCVar16,1,
                     (ulong)in_stack_ffffff04);
          in_stack_ffffff34 = in_stack_fffffeec;
        }
        else {
          pCVar16 = pCVar16 + 1;
        }
      } while (pCVar16 < in_stack_fffffeec);
    }
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff1c,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffefc);
    if (uVar4 != 0) {
      pCVar16 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar7 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                               in_stack_ffffff0c);
      *(undefined4 *)(pSVar7 + 0x1c) = 0xffffffff;
      *(undefined4 *)pSVar7 = 0xffffffff;
      *(undefined4 *)(pSVar7 + 0xc) = 0;
      *(undefined4 *)(pSVar7 + 8) = 0;
      *(undefined4 *)(pSVar7 + 4) = 0;
      uVar2 = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x10) = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x14) = uVar2;
      *(undefined4 *)(pSVar7 + 0x18) = uVar2;
      uVar4 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)pCVar25,(ulong)pTVar26,
                                 in_stack_ffffff04);
      pSVar5 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this,pCVar16,(ulong)fVar21);
      pCVar10 = pCVar10 + uVar4;
      *(ulong *)pSVar5 = uVar4;
      in_stack_ffffff58 = local_54;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff2c,(GmFrustumIso4 *)in_stack_ffffff0c);
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[](&stack0xffffff3c,pCVar16,(ulong)pCVar15);
        if (*(int *)pSVar5 == 0x10) {
          CFastBuffer<class_GmReal4_64>::Add
                    (&stack0xffffff34,
                     (TiXmlAttributeSet *)(in_stack_ffffff58 + *(int *)(pSVar5 + 4) * 0x20),pTVar22)
          ;
          pTVar22 = (TiXmlAttribute *)0x1;
          pCVar15 = pCVar16;
          in_stack_fffffeec = pCVar28;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff44,(CFastBufferRef<class_CGameMobil> *)pCVar16,1,(ulong)pSVar23);
          pCVar28 = in_stack_fffffeec;
        }
        else {
          pCVar16 = pCVar16 + 1;
        }
      } while (pCVar16 < in_stack_fffffeec);
    }
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff30,(CFastBuffer<class_CCrystalFace*> *)pCVar15);
    if (uVar4 != 0) {
      pCVar15 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar7 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar10);
      *(undefined4 *)(pSVar7 + 0x1c) = 0xffffffff;
      *(undefined4 *)pSVar7 = 0xffffffff;
      *(undefined4 *)(pSVar7 + 0xc) = 0;
      *(undefined4 *)(pSVar7 + 8) = 0;
      *(undefined4 *)(pSVar7 + 4) = 0;
      uVar2 = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x10) = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x14) = uVar2;
      *(undefined4 *)(pSVar7 + 0x18) = uVar2;
      uVar4 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)in_stack_ffffff38,
                                 (ulong)in_stack_ffffff3c,pSVar23);
      pSVar5 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this,pCVar15,(ulong)fVar24);
      in_stack_ffffff34 = in_stack_ffffff34 + uVar4;
      *(ulong *)pSVar5 = uVar4;
      in_stack_ffffff58 = local_40;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff40,(GmFrustumIso4 *)pCVar10);
    pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[](&stack0xffffff50,pCVar15,(ulong)pCVar25);
        if (*(int *)pSVar5 == 0x20) {
          CFastBuffer<class_GmReal4_64>::Add
                    (&stack0xffffff48,
                     (TiXmlAttributeSet *)(in_stack_ffffff58 + *(int *)(pSVar5 + 4) * 0x20),pTVar26)
          ;
          pTVar26 = (TiXmlAttribute *)0x1;
          pCVar25 = pCVar15;
          in_stack_fffffeec = in_stack_ffffff5c;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff58,(CFastBufferRef<class_CGameMobil> *)pCVar15,1,(ulong)pTVar27);
          in_stack_ffffff5c = in_stack_fffffeec;
        }
        else {
          pCVar15 = pCVar15 + 1;
        }
      } while (pCVar15 < in_stack_fffffeec);
    }
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff44,(CFastBuffer<class_CCrystalFace*> *)pCVar25);
    if (uVar4 != 0) {
      pCVar15 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar7 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                               in_stack_ffffff34);
      *(undefined4 *)(pSVar7 + 0x1c) = 0xffffffff;
      *(undefined4 *)pSVar7 = 0xffffffff;
      *(undefined4 *)(pSVar7 + 0xc) = 0;
      *(undefined4 *)(pSVar7 + 8) = 0;
      *(undefined4 *)(pSVar7 + 4) = 0;
      uVar2 = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x10) = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x14) = uVar2;
      *(undefined4 *)(pSVar7 + 0x18) = uVar2;
      uVar4 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)in_stack_ffffff4c,
                                 (ulong)pTVar29,(SMeshOctreeCell *)pTVar27);
      pSVar5 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this,pCVar15,(ulong)in_stack_ffffff30);
      pCVar28 = pCVar28 + uVar4;
      *(ulong *)pSVar5 = uVar4;
      in_stack_ffffff58 = local_2c;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff54,(GmFrustumIso4 *)in_stack_ffffff34);
    pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff64,pCVar15,(ulong)in_stack_ffffff38);
        if (*(int *)pSVar5 == 0x40) {
          CFastBuffer<class_GmReal4_64>::Add
                    (&stack0xffffff5c,
                     (TiXmlAttributeSet *)(in_stack_ffffff58 + *(int *)(pSVar5 + 4) * 0x20),
                     in_stack_ffffff3c);
          in_stack_ffffff3c = (TiXmlAttribute *)0x1;
          in_stack_ffffff38 = pCVar15;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff6c,(CFastBufferRef<class_CGameMobil> *)pCVar15,1,
                     (ulong)in_stack_ffffff40);
          in_stack_fffffeec = unaff_ESI;
        }
        else {
          pCVar15 = pCVar15 + 1;
        }
      } while (pCVar15 < in_stack_fffffeec);
    }
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff58,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff38);
    if (uVar4 != 0) {
      pCVar15 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar7 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar28);
      *(undefined4 *)(pSVar7 + 0x1c) = 0xffffffff;
      *(undefined4 *)pSVar7 = 0xffffffff;
      *(undefined4 *)(pSVar7 + 0xc) = 0;
      *(undefined4 *)(pSVar7 + 8) = 0;
      *(undefined4 *)(pSVar7 + 4) = 0;
      uVar2 = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x10) = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x14) = uVar2;
      *(undefined4 *)(pSVar7 + 0x18) = uVar2;
      uVar4 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)in_stack_ffffff60,
                                 (ulong)pCVar30,in_stack_ffffff40);
      pSVar5 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this,pCVar15,in_stack_ffffff44);
      in_stack_ffffff5c = in_stack_ffffff5c + uVar4;
      *(ulong *)pSVar5 = uVar4;
      in_stack_ffffff58 = local_18;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff68,(GmFrustumIso4 *)pCVar28);
    pCVar28 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff78,pCVar28,(ulong)in_stack_ffffff4c);
        if (*(int *)pSVar5 == 0x80) {
          CFastBuffer<class_GmReal4_64>::Add
                    (&stack0xffffff70,
                     (TiXmlAttributeSet *)(in_stack_ffffff58 + *(int *)(pSVar5 + 4) * 0x20),pTVar29)
          ;
          pTVar29 = (TiXmlAttribute *)0x1;
          in_stack_ffffff4c = pCVar28;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (local_80,(CFastBufferRef<class_CGameMobil> *)pCVar28,1,(ulong)in_stack_ffffff54
                    );
          in_stack_fffffeec = local_7c;
        }
        else {
          pCVar28 = pCVar28 + 1;
        }
      } while (pCVar28 < in_stack_fffffeec);
    }
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff6c,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff4c);
    if (uVar4 != 0) {
      pCVar28 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar7 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                               in_stack_ffffff5c);
      *(undefined4 *)(pSVar7 + 0x1c) = 0xffffffff;
      *(undefined4 *)pSVar7 = 0xffffffff;
      *(undefined4 *)(pSVar7 + 0xc) = 0;
      *(undefined4 *)(pSVar7 + 8) = 0;
      *(undefined4 *)(pSVar7 + 4) = 0;
      uVar2 = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x10) = _DAT_00b2c060;
      *(undefined4 *)(pSVar7 + 0x14) = uVar2;
      *(undefined4 *)(pSVar7 + 0x18) = uVar2;
      uVar4 = BuildOctreeRecurse(this,unaff_EBP,unaff_EBX,in_stack_ffffff54);
      pSVar5 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this,pCVar28,(ulong)pCVar11);
      *(ulong *)pSVar5 = uVar4;
    }
    pCVar28 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x8f3334;
    pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (auStack_78,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff5c);
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar15 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar8 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                           (unaff_EBP + (int)pCVar15,
                            (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar28);
        pCVar28 = pCVar16;
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           (auStack_78,pCVar16,(ulong)in_stack_ffffff5c);
        pCVar16 = pCVar16 + 1;
        puVar13 = (undefined4 *)(*(int *)(pSVar5 + 4) * 0x20 + unaff_retaddr);
        pSVar7 = pSVar8;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined4 *)pSVar7 = *puVar13;
          puVar13 = puVar13 + 1;
          pSVar7 = pSVar7 + 4;
        }
        *(undefined4 *)pSVar8 = 1;
      } while (pCVar16 < pCVar15);
    }
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (local_80,in_stack_ffffff60);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(auStack_70,pCVar30);
  }
  ExceptionList = local_c;
  return uStack_84;
}
}

