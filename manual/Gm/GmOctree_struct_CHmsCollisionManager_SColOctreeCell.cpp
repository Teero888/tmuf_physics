// Class implementation: GmOctree_struct_CHmsCollisionManager_SColOctreeCell

// =================================================
// Function: GmOctree<struct_CHmsCollisionManager::SColOctreeCell>::Build
// =================================================
void __thiscall
GmOctree<struct_CHmsCollisionManager::SColOctreeCell>::Build
          (void *this,NvStripInfo *param_1,
          vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> *param_2,
          vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *param_3)
{
{
  SLoadedLight *pSVar1;
  SCasterCat *pSVar2;
  ulong uVar3;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  SMeshOctreeCell *unaff_retaddr;
  ulong in_stack_00000010;
  int in_stack_00000014;
  ulong in_stack_00000018;
  ulong in_stack_0000001c;
  ulong in_stack_00000020;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_EDI);
  pSVar1 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem(this,unaff_ESI);
  *(undefined4 *)(pSVar1 + 0x4c) = 0;
  if (in_stack_00000014 == 0) {
    BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)param_3,in_stack_00000010,
                       unaff_retaddr);
  }
  else {
    BuildBintreeRecurse(this,(GmQuadTree<struct_SQuadTreeMeshUv> *)param_3,in_stack_00000010,
                        (SQuadTreeMeshUv *)0x0,in_stack_00000018,in_stack_0000001c,in_stack_00000020
                        ,(float)unaff_retaddr);
  }
  pSVar2 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)param_1);
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this,(CFastBuffer<class_CCrystalFace*> *)param_2);
  *(ulong *)pSVar2 = uVar3;
  return;
}
}

// =================================================
// Function: GmOctree<struct_CHmsCollisionManager::SColOctreeCell>::BuildBintreeRecurse
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
GmOctree<struct_CHmsCollisionManager::SColOctreeCell>::BuildBintreeRecurse
          (void *this,GmQuadTree<struct_SQuadTreeMeshUv> *param_1,ulong param_2,
          SQuadTreeMeshUv *param_3,ulong param_4,ulong param_5,ulong param_6,float param_7)
{
{
  bool bVar1;
  GmVec2 *pGVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  SLoadedLight *pSVar5;
  GmQuadTree<struct_SQuadTreeMeshUv> *pGVar6;
  SLoadedLight *pSVar7;
  int iVar8;
  uint uVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  GmQuadTree<struct_SQuadTreeMeshUv> *unaff_EBP;
  undefined4 *puVar10;
  GmRectAligned *pGVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  undefined4 *puVar13;
  TiXmlAttributeSet *pTVar14;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar15;
  ulong in_stack_ffffff5c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffff60;
  GmFrustumIso4 *in_stack_ffffff64;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff68;
  TiXmlAttribute *in_stack_ffffff6c;
  float in_stack_ffffff70;
  ulong in_stack_ffffff74;
  float fVar16;
  TiXmlAttribute *pTVar17;
  float fVar18;
  float fVar19;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffff8c;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffff90;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar20;
  TiXmlAttributeSet *pTVar21;
  TiXmlAttribute *pTVar22;
  float fVar23;
  GmQuadTree<struct_SQuadTreeMeshUv> *pGStack_54;
  GmQuadTree<struct_SQuadTreeMeshUv> *local_50;
  float local_4c;
  float local_48;
  ulong local_44;
  float fStack_40;
  float fStack_3c;
  undefined1 local_38 [4];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_34;
  int local_30;
  float local_2c;
  int local_24;
  undefined4 local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  void *local_c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_8;
  GmQuadTree<struct_SQuadTreeMeshUv> *local_4;
  
  puVar10 = (undefined4 *)param_2;
  local_4 = (GmQuadTree<struct_SQuadTreeMeshUv> *)0xffffffff;
  local_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&LAB_00a95580;
  local_c = ExceptionList;
  pGVar2 = (GmVec2 *)(DAT_00cca150 ^ (uint)&stack0xffffff9c);
  if (param_1 == (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
    return 0;
  }
  local_24 = *(int *)(param_2 + 4);
  local_20 = *(undefined4 *)(param_2 + 8);
  local_1c = *(int *)(param_2 + 0xc);
  local_18 = *(float *)(param_2 + 0x10);
  local_14 = *(float *)(param_2 + 0x14);
  local_10 = *(float *)(param_2 + 0x18);
  ExceptionList = &local_c;
  if ((GmQuadTree<struct_SQuadTreeMeshUv> *)0x1 < param_1) {
    local_50 = param_1 + -1;
    pGVar11 = (GmRectAligned *)(param_2 + 0x5c);
    do {
      in_stack_ffffff90 = (CFastBuffer<class_CPlugFileGPUV*> *)0x53925f;
      GmBoxAligned::Union(&local_24,pGVar11,pGVar2);
      pGVar11 = pGVar11 + 0x58;
      local_4c = (float)((int)local_4c + -1);
    } while (local_4c != 0.0);
  }
  pCVar20 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x539270;
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this,(CFastBuffer<class_CCrystalFace*> *)pGVar2);
  pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uVar3 != 0) {
    pGVar2 = (GmVec2 *)(uVar3 - 1);
    pCVar20 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x539281;
    pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                       (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar2,unaff_EDI);
    *(int *)(pSVar4 + 4) = local_1c;
    *(float *)(pSVar4 + 8) = local_18;
    *(float *)(pSVar4 + 0xc) = local_14;
    *(float *)(pSVar4 + 0x10) = local_10;
    *(void **)(pSVar4 + 0x14) = local_c;
    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x18) = local_8;
  }
  pGStack_54 = (GmQuadTree<struct_SQuadTreeMeshUv> *)0x1;
  if (((param_4 == 0) || (param_3 < param_4)) && ((param_5 == 0 || (param_5 < param_1)))) {
    if (_DAT_00b55d98 < (float)param_6) {
      fStack_40 = (float)_DAT_00b33a58;
      fStack_3c = local_18 * fStack_40;
      local_2c = local_14 * fStack_40;
      fStack_40 = fStack_40 * local_10;
      if (local_2c * fStack_3c * fStack_40 < (float)param_6) goto LAB_0053932f;
    }
    local_50 = (GmQuadTree<struct_SQuadTreeMeshUv> *)
               (local_10 * local_10 + local_14 * local_14 + local_18 * local_18);
    if ((float)local_50 != _DAT_00c418e0) {
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&fStack_3c,(CFastBuffer<class_CPlugFileSndGen*> *)pGVar2);
      pTVar21 = (TiXmlAttributeSet *)0x5393a3;
      CFastBuffer<struct_CPlugModelMesh::SPoly>::AllocSetCount
                (local_38,(CFastBuffer<class_GxVertex2> *)param_1,unaff_EDI);
      if (param_1 != (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
        do {
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xffffff88,pCVar12,in_stack_ffffff5c);
          *(undefined4 *)pSVar4 = 0;
          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 4) = pCVar12;
          pCVar12 = pCVar12 + 1;
        } while (pCVar12 < param_1);
      }
      pTVar22 = (TiXmlAttribute *)((float)unaff_EBP + (float)local_50);
      pTVar17 = (TiXmlAttribute *)((float)unaff_EBP - (float)local_50);
      fVar16 = (float)pTVar22 - (float)pTVar17;
      fVar23 = (float)unaff_EBX + local_4c;
      fVar18 = (float)unaff_EBX - local_4c;
      fVar19 = fVar23 - fVar18;
      bVar1 = fVar16 < fVar19;
      if (bVar1) {
        fVar16 = fVar19;
      }
      uVar9 = (uint)bVar1;
      fVar19 = 1.4013e-45 - local_48;
      pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((local_48 + 1.4013e-45) - fVar19)
      ;
      if (fVar16 < (float)pCVar12) {
        uVar9 = 2;
      }
      pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pCVar20 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                ((*(float *)(&stack0xffffff80 + uVar9 * 4) +
                 *(float *)(&stack0xffffff98 + uVar9 * 4)) * (float)_DAT_00b313b8);
      if (local_34 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(&stack0xffffff80 + uVar9 * 4);
        iVar8 = local_30 + 0xc;
        do {
          pTVar22 = *(TiXmlAttribute **)(iVar8 + -8);
          fVar23 = *(float *)(iVar8 + -4);
          pTVar17 = *(TiXmlAttribute **)(iVar8 + 4);
          fVar18 = *(float *)(iVar8 + 8);
          fVar19 = *(float *)(iVar8 + 0xc);
          fVar16 = *(float *)pCVar12 + *(float *)(&stack0xffffff98 + uVar9 * 4);
          if (fVar16 < (float)pCVar20 == (fVar16 == (float)pCVar20)) {
            if ((float)pCVar20 <= *(float *)(&stack0xffffff98 + uVar9 * 4) - *(float *)pCVar12) {
              pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                                 (&stack0xffffff8c,pCVar15,(ulong)in_stack_ffffff60);
              *(uint *)pSVar4 = *(uint *)pSVar4 | 2;
            }
          }
          else {
            pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                               (&stack0xffffff8c,pCVar15,(ulong)in_stack_ffffff60);
            *(uint *)pSVar4 = *(uint *)pSVar4 | 1;
          }
          pCVar15 = pCVar15 + 1;
          iVar8 = iVar8 + 0x58;
        } while (pCVar15 < local_34);
      }
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&stack0xffffff80,in_stack_ffffff60);
      local_38[0] = 1;
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                (&stack0xffffff84,in_stack_ffffff64);
      pTVar14 = (TiXmlAttributeSet *)0x0;
      if (pTVar21 != (TiXmlAttributeSet *)0x0) {
        do {
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xffffff94,
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pTVar14,
                              (ulong)in_stack_ffffff68);
          if (*(int *)pSVar4 == 1) {
            CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                      (&stack0xffffff8c,
                       (TiXmlAttributeSet *)(*(int *)(pSVar4 + 4) * 0x58 + local_24),
                       in_stack_ffffff6c);
            in_stack_ffffff6c = (TiXmlAttribute *)0x1;
            in_stack_ffffff68 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pTVar14;
            CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                      (&stack0xffffff9c,(CFastBufferRef<class_CGameMobil> *)pTVar14,1,
                       (ulong)in_stack_ffffff70);
          }
          else {
            pTVar14 = pTVar14 + 1;
          }
        } while (pTVar14 < pTVar21);
      }
      uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (&stack0xffffff88,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff68);
      if (uVar3 != 0) {
        if (uVar3 == 1) {
          pSVar5 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                             (this,pCVar20);
          pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                             (&stack0xffffff90,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                              ,(ulong)in_stack_ffffff70);
          pSVar7 = pSVar5;
          for (iVar8 = 0x16; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined4 *)pSVar7 = *(undefined4 *)pSVar4;
            pSVar4 = pSVar4 + 4;
            pSVar7 = pSVar7 + 4;
          }
          *(undefined4 *)pSVar5 = 1;
          fVar19 = 2.8026e-45;
        }
        else {
          pCVar15 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
          pSVar7 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                             (this,pCVar20);
          *(undefined4 *)(pSVar7 + 0x4c) = 0;
          uVar3 = BuildBintreeRecurse(this,(GmQuadTree<struct_SQuadTreeMeshUv> *)in_stack_ffffff90,
                                      (ulong)pTVar21,(SQuadTreeMeshUv *)(local_1c + 1),
                                      (ulong)local_18,(ulong)local_14,(ulong)local_10,
                                      in_stack_ffffff70);
          pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                             (this,pCVar15,in_stack_ffffff74);
          *(ulong *)pSVar4 = uVar3;
          in_stack_ffffff8c = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)(uVar3 + 1);
        }
      }
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                (&stack0xffffff98,(GmFrustumIso4 *)pCVar20);
      pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (unaff_EBX != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[](&stack0xffffffa8,pCVar15,(ulong)pCVar12)
          ;
          if (*(int *)pSVar4 == 2) {
            CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                      (&stack0xffffffa0,
                       (TiXmlAttributeSet *)(*(int *)(pSVar4 + 4) * 0x58 + (int)local_10),pTVar17);
            pTVar17 = (TiXmlAttribute *)0x1;
            pCVar12 = pCVar15;
            CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                      (&local_50,(CFastBufferRef<class_CGameMobil> *)pCVar15,1,(ulong)fVar18);
          }
          else {
            pCVar15 = pCVar15 + 1;
          }
        } while (pCVar15 < unaff_EBX);
      }
      uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (&stack0xffffff9c,(CFastBuffer<class_CCrystalFace*> *)pCVar12);
      if (uVar3 != 0) {
        if (uVar3 == 1) {
          pSVar5 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                             (this,in_stack_ffffff8c);
          pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                             (&stack0xffffffa4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                              ,(ulong)fVar18);
          fVar23 = (float)((int)fVar23 + 1);
          pSVar7 = pSVar5;
          for (iVar8 = 0x16; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined4 *)pSVar7 = *(undefined4 *)pSVar4;
            pSVar4 = pSVar4 + 4;
            pSVar7 = pSVar7 + 4;
          }
          *(undefined4 *)pSVar5 = 1;
        }
        else {
          pCVar12 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
          pSVar7 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                             (this,in_stack_ffffff8c);
          *(undefined4 *)(pSVar7 + 0x4c) = 0;
          uVar3 = BuildBintreeRecurse(this,unaff_EBP,(ulong)unaff_EBX,
                                      (SQuadTreeMeshUv *)(local_8 + 1),(ulong)local_4,0,
                                      (ulong)param_1,fVar18);
          pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                             (this,pCVar12,(ulong)fVar19);
          *(ulong *)pSVar4 = uVar3;
        }
      }
      pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x539758;
      pGVar6 = (GmQuadTree<struct_SQuadTreeMeshUv> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (&local_48,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff8c);
      if ((pGVar6 == local_4) || (pGVar6 < (GmQuadTree<struct_SQuadTreeMeshUv> *)0x2)) {
        local_4 = (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0;
        if (pGVar6 != (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
          do {
            pSVar7 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                               (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar12
                               );
            pCVar12 = local_8;
            pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                               (&local_48,local_8,(ulong)in_stack_ffffff8c);
            puVar10 = (undefined4 *)(*(int *)(pSVar4 + 4) * 0x58);
            for (iVar8 = 0x16; iVar8 != 0; iVar8 = iVar8 + -1) {
              *(undefined4 *)pSVar7 = *puVar10;
              puVar10 = puVar10 + 1;
              pSVar7 = pSVar7 + 4;
            }
            local_4 = local_4 + 1;
            *(undefined4 *)param_4 = 1;
          } while (local_4 < pGVar6);
        }
      }
      else {
        CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                  (&local_50,(GmFrustumIso4 *)in_stack_ffffff90);
        pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pGVar6 != (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
          do {
            pSVar4 = CFastBuffer<struct_SFastCat>::operator[](&fStack_40,pCVar12,(ulong)pTVar21);
            pTVar21 = (TiXmlAttributeSet *)(*(int *)(pSVar4 + 4) * 0x58 + param_2);
            CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add(&local_48,pTVar21,pTVar22)
            ;
            pCVar12 = pCVar12 + 1;
          } while (pCVar12 < pGVar6);
        }
        pCVar12 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
        pSVar7 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                           (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pTVar21);
        *(undefined4 *)(pSVar7 + 0x4c) = 0;
        uVar3 = BuildBintreeRecurse(this,pGVar6,local_44,param_3 + 1,param_4,param_5,param_6,
                                    (float)pTVar22);
        pTVar21 = (TiXmlAttributeSet *)0x5397ec;
        pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                           (this,pCVar12,(ulong)fVar23);
        local_4c = (float)((int)local_4c + uVar3);
        *(ulong *)pSVar4 = uVar3;
        in_stack_ffffff90 = (CFastBuffer<class_CPlugFileGPUV*> *)param_5;
      }
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (&local_50,in_stack_ffffff90);
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (&fStack_40,(CFastBuffer<class_CPlugFileGPUV*> *)pTVar21);
      ExceptionList = local_c;
      return 1;
    }
  }
LAB_0053932f:
  if (param_1 != (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
    param_2 = (ulong)param_1;
    pGStack_54 = param_1 + 1;
    do {
      pSVar5 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem(this,pCVar20);
      param_2 = param_2 - 1;
      puVar13 = puVar10;
      pSVar7 = pSVar5;
      for (iVar8 = 0x16; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined4 *)pSVar7 = *puVar13;
        puVar13 = puVar13 + 1;
        pSVar7 = pSVar7 + 4;
      }
      *(undefined4 *)pSVar5 = 1;
      puVar10 = puVar10 + 0x16;
    } while (param_2 != 0);
  }
  ExceptionList = local_c;
  return (ulong)pGStack_54;
}
}

// =================================================
// Function: GmOctree<struct_CHmsCollisionManager::SColOctreeCell>::BuildOctreeRecurse
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
GmOctree<struct_CHmsCollisionManager::SColOctreeCell>::BuildOctreeRecurse
          (void *this,GmOctree<struct_SMeshOctreeCell> *param_1,ulong param_2,
          SMeshOctreeCell *param_3)
{
{
  float fVar1;
  GmVec2 *pGVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  int iVar5;
  SLoadedLight *pSVar6;
  SLoadedLight *pSVar7;
  ulong unaff_EBX;
  GmOctree<struct_SMeshOctreeCell> *unaff_EBP;
  GmOctree<struct_SMeshOctreeCell> *pGVar8;
  void *pvVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  undefined4 *puVar11;
  ulong unaff_EDI;
  GmRectAligned *pGVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar15;
  int unaff_retaddr;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffeb0;
  ulong in_stack_fffffeb4;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffeb8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffebc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffec0;
  TiXmlAttribute *in_stack_fffffec4;
  SMeshOctreeCell *in_stack_fffffec8;
  ulong in_stack_fffffecc;
  GmFrustumIso4 *pGVar16;
  SMeshOctreeCell *in_stack_fffffedc;
  float in_stack_fffffee0;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_fffffee4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffee8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffeec;
  SMeshOctreeCell *pSVar17;
  ulong in_stack_fffffef4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffefc;
  TiXmlAttribute *pTVar18;
  SMeshOctreeCell *in_stack_ffffff04;
  float fVar19;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff0c;
  TiXmlAttribute *pTVar20;
  SMeshOctreeCell *pSVar21;
  float fVar22;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar23;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar24;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff28;
  TiXmlAttribute *pTVar25;
  TiXmlAttribute *in_stack_ffffff2c;
  TiXmlAttribute *pTVar26;
  float in_stack_ffffff30;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff34;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff38;
  TiXmlAttribute *in_stack_ffffff3c;
  SMeshOctreeCell *in_stack_ffffff40;
  ulong in_stack_ffffff44;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar27;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff4c;
  undefined4 in_stack_ffffff50;
  TiXmlAttribute *pTVar28;
  SMeshOctreeCell *in_stack_ffffff54;
  ulong in_stack_ffffff58;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff5c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff60;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar29;
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
  local_8 = &LAB_00a95540;
  local_c = ExceptionList;
  pGVar2 = (GmVec2 *)(DAT_00cca150 ^ (uint)&stack0xffffff6c);
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
      pGVar12 = (GmRectAligned *)(param_2 + 0x5c);
      pGVar8 = param_1 + -1;
      do {
        in_stack_ffffff60 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x5383fb;
        GmBoxAligned::Union(&local_24,pGVar12,pGVar2);
        pGVar12 = pGVar12 + 0x58;
        pGVar8 = pGVar8 + -1;
      } while (pGVar8 != (GmOctree<struct_SMeshOctreeCell> *)0x0);
    }
    pCVar30 = (CFastBuffer<class_CPlugFileGPUV*> *)0x53840a;
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this,(CFastBuffer<class_CCrystalFace*> *)pGVar2);
    if (uVar3 != 0) {
      pCVar30 = (CFastBuffer<class_CPlugFileGPUV*> *)0x538419;
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                         (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - 1),
                          unaff_EDI);
      *(undefined4 *)(pSVar4 + 4) = local_1c;
      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 8) = local_18;
      *(undefined4 *)(pSVar4 + 0xc) = local_14;
      *(undefined4 *)(pSVar4 + 0x10) = local_10;
      *(void **)(pSVar4 + 0x14) = local_c;
      *(undefined1 **)(pSVar4 + 0x18) = local_8;
    }
    pTVar26 = in_stack_ffffff2c;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&stack0xfffffedc,in_stack_fffffeb0);
    pCVar27 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    CFastBuffer<struct_CPlugModelMesh::SPoly>::AllocSetCount
              (&stack0xfffffee0,(CFastBuffer<class_GxVertex2> *)param_1,in_stack_fffffeb4);
    pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xfffffee0,pCVar13,in_stack_fffffeb4);
        *(undefined4 *)pSVar4 = 0;
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 4) = pCVar13;
        pCVar13 = pCVar13 + 1;
      } while (pCVar13 < param_1);
    }
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              ((float)in_stack_ffffff34 - (float)in_stack_ffffff40);
    pSVar17 = (SMeshOctreeCell *)((float)pTVar26 - (float)in_stack_ffffff38);
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pvVar9 = (void *)(in_stack_ffffff58 + 4);
      do {
        iVar5 = GmBoxAligned::TestInter
                          (pvVar9,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar5 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x5385aa;
          in_stack_fffffebc = pCVar14;
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar14,(ulong)in_stack_fffffec0);
          *(uint *)pSVar4 = *(uint *)pSVar4 | 1;
        }
        pCVar14 = pCVar14 + 1;
        pvVar9 = (void *)((int)pvVar9 + 0x58);
      } while (pCVar14 < param_1);
    }
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pvVar9 = (void *)(in_stack_ffffff58 + 4);
      do {
        iVar5 = GmBoxAligned::TestInter
                          (pvVar9,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar5 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x5386aa;
          in_stack_fffffebc = pCVar14;
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar14,(ulong)in_stack_fffffec0);
          *(uint *)pSVar4 = *(uint *)pSVar4 | 2;
        }
        pCVar14 = pCVar14 + 1;
        pvVar9 = (void *)((int)pvVar9 + 0x58);
      } while (pCVar14 < param_1);
    }
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pvVar9 = (void *)(in_stack_ffffff58 + 4);
      do {
        iVar5 = GmBoxAligned::TestInter
                          (pvVar9,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar5 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x5387aa;
          in_stack_fffffebc = pCVar14;
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar14,(ulong)in_stack_fffffec0);
          *(uint *)pSVar4 = *(uint *)pSVar4 | 4;
        }
        pCVar14 = pCVar14 + 1;
        pvVar9 = (void *)((int)pvVar9 + 0x58);
      } while (pCVar14 < param_1);
    }
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pvVar9 = (void *)(in_stack_ffffff58 + 4);
      do {
        iVar5 = GmBoxAligned::TestInter
                          (pvVar9,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar5 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x5388aa;
          in_stack_fffffebc = pCVar14;
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar14,(ulong)in_stack_fffffec0);
          *(uint *)pSVar4 = *(uint *)pSVar4 | 8;
        }
        pCVar14 = pCVar14 + 1;
        pvVar9 = (void *)((int)pvVar9 + 0x58);
      } while (pCVar14 < param_1);
    }
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pvVar9 = (void *)(in_stack_ffffff58 + 4);
      do {
        iVar5 = GmBoxAligned::TestInter
                          (pvVar9,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar5 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x5389aa;
          in_stack_fffffebc = pCVar14;
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar14,(ulong)in_stack_fffffec0);
          *(uint *)pSVar4 = *(uint *)pSVar4 | 0x10;
        }
        pCVar14 = pCVar14 + 1;
        pvVar9 = (void *)((int)pvVar9 + 0x58);
      } while (pCVar14 < param_1);
    }
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pvVar9 = (void *)(in_stack_ffffff58 + 4);
      do {
        iVar5 = GmBoxAligned::TestInter
                          (pvVar9,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar5 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x538aaa;
          in_stack_fffffebc = pCVar14;
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar14,(ulong)in_stack_fffffec0);
          *(uint *)pSVar4 = *(uint *)pSVar4 | 0x20;
        }
        pCVar14 = pCVar14 + 1;
        pvVar9 = (void *)((int)pvVar9 + 0x58);
      } while (pCVar14 < param_1);
    }
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pvVar9 = (void *)(in_stack_ffffff58 + 4);
      do {
        iVar5 = GmBoxAligned::TestInter
                          (pvVar9,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar5 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x538baa;
          in_stack_fffffebc = pCVar14;
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar14,(ulong)in_stack_fffffec0);
          *(uint *)pSVar4 = *(uint *)pSVar4 | 0x40;
        }
        pCVar14 = pCVar14 + 1;
        pvVar9 = (void *)((int)pvVar9 + 0x58);
      } while (pCVar14 < param_1);
    }
    fVar1 = (float)_DAT_00b313b8;
    pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              ((float)in_stack_ffffff40 + (float)in_stack_ffffff34);
    pTVar18 = (TiXmlAttribute *)((float)in_stack_ffffff3c + in_stack_ffffff30);
    fVar19 = (float)in_stack_ffffff38 + (float)pTVar26;
    pTVar20 = (TiXmlAttribute *)((fVar19 + (float)in_stack_ffffff2c) * fVar1);
    pSVar21 = (SMeshOctreeCell *)(((float)pTVar18 + (float)in_stack_fffffedc) * fVar1);
    fVar22 = ((float)pCVar14 + in_stack_fffffee0) * fVar1;
    pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              ((fVar19 - (float)in_stack_ffffff2c) * fVar1);
    pCVar24 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              (((float)pTVar18 - (float)in_stack_fffffedc) * fVar1);
    pTVar25 = (TiXmlAttribute *)(fVar1 * ((float)pCVar14 - in_stack_fffffee0));
    if (param_1 != (GmOctree<struct_SMeshOctreeCell> *)0x0) {
      pvVar9 = (void *)(in_stack_ffffff58 + 4);
      do {
        iVar5 = GmBoxAligned::TestInter
                          (pvVar9,(CPlugVolumeProjector *)&stack0xffffff14,
                           (GmBoxAligned *)in_stack_fffffeb8,(GmIso4 *)in_stack_fffffebc);
        if (iVar5 != 0) {
          in_stack_fffffeb8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x538c9a;
          in_stack_fffffebc = pCVar15;
          pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffeec,pCVar15,(ulong)in_stack_fffffec0);
          *(uint *)pSVar4 = *(uint *)pSVar4 | 0x80;
        }
        pCVar15 = pCVar15 + 1;
        pvVar9 = (void *)((int)pvVar9 + 0x58);
      } while (pCVar15 < param_1);
    }
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&stack0xfffffed8,in_stack_fffffeb8);
    pTVar28 = (TiXmlAttribute *)CONCAT31((int3)((uint)in_stack_ffffff50 >> 8),1);
    pGVar16 = (GmFrustumIso4 *)0x1;
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xfffffedc,(GmFrustumIso4 *)in_stack_fffffebc);
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCVar15 = in_stack_fffffeec;
    pCVar29 = in_stack_ffffff60;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xfffffeec,pCVar10,(ulong)in_stack_fffffec0);
        if (*(int *)pSVar4 == 1) {
          CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                    (&stack0xfffffee4,
                     (TiXmlAttributeSet *)(in_stack_ffffff60 + *(int *)(pSVar4 + 4) * 0x58),
                     in_stack_fffffec4);
          in_stack_fffffec4 = (TiXmlAttribute *)0x1;
          in_stack_fffffec0 = pCVar10;
          in_stack_fffffeec = pCVar14;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xfffffef4,(CFastBufferRef<class_CGameMobil> *)pCVar10,1,
                     (ulong)in_stack_fffffec8);
          pCVar14 = in_stack_fffffeec;
        }
        else {
          pCVar10 = pCVar10 + 1;
        }
      } while (pCVar10 < in_stack_fffffeec);
    }
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xfffffee0,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffec0);
    if (uVar3 != 0) {
      pCVar10 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar6 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pGVar16);
      *(undefined4 *)(pSVar6 + 0x4c) = 0;
      uVar3 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)in_stack_fffffee8,
                                 (ulong)pCVar15,in_stack_fffffec8);
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                         (this,pCVar10,in_stack_fffffecc);
      *(ulong *)pSVar4 = uVar3;
      in_stack_fffffee4 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)(uVar3 + 1);
      in_stack_ffffff60 = unaff_ESI;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&stack0xfffffef0,pGVar16);
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff00,pCVar10,(ulong)in_stack_ffffff28);
        if (*(int *)pSVar4 == 2) {
          CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                    (&stack0xfffffef8,
                     (TiXmlAttributeSet *)(in_stack_ffffff60 + *(int *)(pSVar4 + 4) * 0x58),
                     in_stack_ffffff2c);
          in_stack_ffffff2c = (TiXmlAttribute *)0x1;
          in_stack_ffffff28 = pCVar10;
          in_stack_fffffeec = in_stack_ffffff0c;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff08,(CFastBufferRef<class_CGameMobil> *)pCVar10,1,
                     (ulong)in_stack_fffffedc);
          in_stack_ffffff0c = in_stack_fffffeec;
        }
        else {
          pCVar10 = pCVar10 + 1;
        }
      } while (pCVar10 < in_stack_fffffeec);
    }
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xfffffef4,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff28);
    if (uVar3 != 0) {
      pCVar10 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar6 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                         (this,in_stack_fffffee4);
      *(undefined4 *)(pSVar6 + 0x4c) = 0;
      uVar3 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)in_stack_fffffefc,
                                 (ulong)pTVar18,in_stack_fffffedc);
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                         (this,pCVar10,(ulong)in_stack_fffffee0);
      pCVar14 = pCVar14 + uVar3;
      *(ulong *)pSVar4 = uVar3;
      in_stack_ffffff60 = local_7c;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff04,(GmFrustumIso4 *)in_stack_fffffee4);
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff14,pCVar10,(ulong)in_stack_fffffee8);
        if (*(int *)pSVar4 == 4) {
          CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                    (&stack0xffffff0c,
                     (TiXmlAttributeSet *)(in_stack_ffffff60 + *(int *)(pSVar4 + 4) * 0x58),
                     (TiXmlAttribute *)pCVar15);
          pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
          in_stack_fffffee8 = pCVar10;
          in_stack_fffffeec = pCVar23;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff1c,(CFastBufferRef<class_CGameMobil> *)pCVar10,1,(ulong)pSVar17);
          pCVar23 = in_stack_fffffeec;
        }
        else {
          pCVar10 = pCVar10 + 1;
        }
      } while (pCVar10 < in_stack_fffffeec);
    }
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff08,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffee8);
    if (uVar3 != 0) {
      pCVar15 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar6 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar14);
      *(undefined4 *)(pSVar6 + 0x4c) = 0;
      uVar3 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)pCVar13,(ulong)pTVar20,
                                 pSVar17);
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                         (this,pCVar15,in_stack_fffffef4);
      in_stack_ffffff0c = in_stack_ffffff0c + uVar3;
      *(ulong *)pSVar4 = uVar3;
      in_stack_ffffff60 = local_68;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff18,(GmFrustumIso4 *)pCVar14);
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff28,pCVar14,(ulong)in_stack_fffffefc);
        if (*(int *)pSVar4 == 8) {
          CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                    (&stack0xffffff20,
                     (TiXmlAttributeSet *)(in_stack_ffffff60 + *(int *)(pSVar4 + 4) * 0x58),pTVar18)
          ;
          pTVar18 = (TiXmlAttribute *)0x1;
          in_stack_fffffefc = pCVar14;
          in_stack_fffffeec = in_stack_ffffff34;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff30,(CFastBufferRef<class_CGameMobil> *)pCVar14,1,
                     (ulong)in_stack_ffffff04);
          in_stack_ffffff34 = in_stack_fffffeec;
        }
        else {
          pCVar14 = pCVar14 + 1;
        }
      } while (pCVar14 < in_stack_fffffeec);
    }
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff1c,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffefc);
    if (uVar3 != 0) {
      pCVar14 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar6 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                               in_stack_ffffff0c);
      *(undefined4 *)(pSVar6 + 0x4c) = 0;
      uVar3 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)pCVar24,(ulong)pTVar25,
                                 in_stack_ffffff04);
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                         (this,pCVar14,(ulong)fVar19);
      pCVar23 = pCVar23 + uVar3;
      *(ulong *)pSVar4 = uVar3;
      in_stack_ffffff60 = local_54;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff2c,(GmFrustumIso4 *)in_stack_ffffff0c);
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[](&stack0xffffff3c,pCVar14,(ulong)pCVar13);
        if (*(int *)pSVar4 == 0x10) {
          CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                    (&stack0xffffff34,
                     (TiXmlAttributeSet *)(in_stack_ffffff60 + *(int *)(pSVar4 + 4) * 0x58),pTVar20)
          ;
          pTVar20 = (TiXmlAttribute *)0x1;
          pCVar13 = pCVar14;
          in_stack_fffffeec = pCVar27;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff44,(CFastBufferRef<class_CGameMobil> *)pCVar14,1,(ulong)pSVar21);
          pCVar27 = in_stack_fffffeec;
        }
        else {
          pCVar14 = pCVar14 + 1;
        }
      } while (pCVar14 < in_stack_fffffeec);
    }
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff30,(CFastBuffer<class_CCrystalFace*> *)pCVar13);
    if (uVar3 != 0) {
      pCVar13 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar6 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar23);
      *(undefined4 *)(pSVar6 + 0x4c) = 0;
      uVar3 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)in_stack_ffffff38,
                                 (ulong)in_stack_ffffff3c,pSVar21);
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                         (this,pCVar13,(ulong)fVar22);
      in_stack_ffffff34 = in_stack_ffffff34 + uVar3;
      *(ulong *)pSVar4 = uVar3;
      in_stack_ffffff60 = local_40;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff40,(GmFrustumIso4 *)pCVar23);
    pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[](&stack0xffffff50,pCVar13,(ulong)pCVar24);
        if (*(int *)pSVar4 == 0x20) {
          CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                    (&stack0xffffff48,
                     (TiXmlAttributeSet *)(in_stack_ffffff60 + *(int *)(pSVar4 + 4) * 0x58),pTVar25)
          ;
          pTVar25 = (TiXmlAttribute *)0x1;
          pCVar24 = pCVar13;
          in_stack_fffffeec = in_stack_ffffff5c;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff58,(CFastBufferRef<class_CGameMobil> *)pCVar13,1,(ulong)pTVar26);
          in_stack_ffffff5c = in_stack_fffffeec;
        }
        else {
          pCVar13 = pCVar13 + 1;
        }
      } while (pCVar13 < in_stack_fffffeec);
    }
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff44,(CFastBuffer<class_CCrystalFace*> *)pCVar24);
    if (uVar3 != 0) {
      pCVar13 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar6 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                               in_stack_ffffff34);
      *(undefined4 *)(pSVar6 + 0x4c) = 0;
      uVar3 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)in_stack_ffffff4c,
                                 (ulong)pTVar28,(SMeshOctreeCell *)pTVar26);
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                         (this,pCVar13,(ulong)in_stack_ffffff30);
      pCVar27 = pCVar27 + uVar3;
      *(ulong *)pSVar4 = uVar3;
      in_stack_ffffff60 = local_2c;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff54,(GmFrustumIso4 *)in_stack_ffffff34);
    pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff64,pCVar13,(ulong)in_stack_ffffff38);
        if (*(int *)pSVar4 == 0x40) {
          CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                    (&stack0xffffff5c,
                     (TiXmlAttributeSet *)(in_stack_ffffff60 + *(int *)(pSVar4 + 4) * 0x58),
                     in_stack_ffffff3c);
          in_stack_ffffff3c = (TiXmlAttribute *)0x1;
          in_stack_ffffff38 = pCVar13;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (&stack0xffffff6c,(CFastBufferRef<class_CGameMobil> *)pCVar13,1,
                     (ulong)in_stack_ffffff40);
          in_stack_fffffeec = unaff_ESI;
        }
        else {
          pCVar13 = pCVar13 + 1;
        }
      } while (pCVar13 < in_stack_fffffeec);
    }
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff58,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff38);
    if (uVar3 != 0) {
      pCVar13 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar6 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar27);
      *(undefined4 *)(pSVar6 + 0x4c) = 0;
      uVar3 = BuildOctreeRecurse(this,(GmOctree<struct_SMeshOctreeCell> *)pCVar29,(ulong)pCVar30,
                                 in_stack_ffffff40);
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                         (this,pCVar13,in_stack_ffffff44);
      in_stack_ffffff5c = in_stack_ffffff5c + uVar3;
      *(ulong *)pSVar4 = uVar3;
      in_stack_ffffff60 = local_18;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&stack0xffffff68,(GmFrustumIso4 *)pCVar27);
    pCVar27 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_fffffeec != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           (&stack0xffffff78,pCVar27,(ulong)in_stack_ffffff4c);
        if (*(int *)pSVar4 == 0x80) {
          CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
                    (&stack0xffffff70,
                     (TiXmlAttributeSet *)(in_stack_ffffff60 + *(int *)(pSVar4 + 4) * 0x58),pTVar28)
          ;
          pTVar28 = (TiXmlAttribute *)0x1;
          in_stack_ffffff4c = pCVar27;
          CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                    (local_80,(CFastBufferRef<class_CGameMobil> *)pCVar27,1,(ulong)in_stack_ffffff54
                    );
          in_stack_fffffeec = local_7c;
        }
        else {
          pCVar27 = pCVar27 + 1;
        }
      } while (pCVar27 < in_stack_fffffeec);
    }
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff6c,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff4c);
    if (uVar3 != 0) {
      pCVar27 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
      pSVar6 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                               in_stack_ffffff5c);
      *(undefined4 *)(pSVar6 + 0x4c) = 0;
      uVar3 = BuildOctreeRecurse(this,unaff_EBP,unaff_EBX,in_stack_ffffff54);
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::operator[]
                         (this,pCVar27,in_stack_ffffff58);
      *(ulong *)pSVar4 = uVar3;
    }
    pCVar27 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x539154;
    pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (auStack_78,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff5c);
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar13 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar7 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                           (unaff_EBP + (int)pCVar13,
                            (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar27);
        pCVar27 = pCVar14;
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           (auStack_78,pCVar14,(ulong)in_stack_ffffff5c);
        pCVar14 = pCVar14 + 1;
        puVar11 = (undefined4 *)(*(int *)(pSVar4 + 4) * 0x58 + unaff_retaddr);
        pSVar6 = pSVar7;
        for (iVar5 = 0x16; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined4 *)pSVar6 = *puVar11;
          puVar11 = puVar11 + 1;
          pSVar6 = pSVar6 + 4;
        }
        *(undefined4 *)pSVar7 = 1;
      } while (pCVar14 < pCVar13);
    }
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (local_80,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar29);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(auStack_70,pCVar30);
  }
  ExceptionList = local_c;
  return uStack_84;
}
}

