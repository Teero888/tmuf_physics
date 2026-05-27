// Class implementation: GmQuadTree_struct_SQuadTreeMeshUv

// =================================================
// Function: GmQuadTree<struct_SQuadTreeMeshUv>::BuildBintreeRecurse
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
GmQuadTree<struct_SQuadTreeMeshUv>::BuildBintreeRecurse
          (void *this,GmQuadTree<struct_SQuadTreeMeshUv> *param_1,ulong param_2,
          SQuadTreeMeshUv *param_3,ulong param_4,ulong param_5,ulong param_6,float param_7)
{
{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  void *pvVar4;
  ulong uVar5;
  SCasterCat *pSVar6;
  SLoadedLight *pSVar7;
  uint uVar8;
  int iVar9;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  GmQuadTree<struct_SQuadTreeMeshUv> *pGVar10;
  ulong unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  undefined4 *puVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  float *pfVar13;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CFastBuffer<class_CCrystalFace*> *pCVar15;
  ulong unaff_EDI;
  GmQuadTree<struct_SQuadTreeMeshUv> *pGVar16;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar17;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000020;
  ulong in_stack_00000024;
  int in_stack_0000002c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000030;
  ulong in_stack_00000034;
  ulong in_stack_00000038;
  int in_stack_00000040;
  GmQuadTree<struct_SQuadTreeMeshUv> *in_stack_00000044;
  ulong in_stack_00000048;
  void *in_stack_0000004c;
  int in_stack_00000054;
  ulong in_stack_00000058;
  ulong in_stack_0000005c;
  ulong in_stack_00000060;
  GmFrustumIso4 *in_stack_ffffffbc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffc0;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar18;
  float in_stack_ffffffc8;
  ulong in_stack_ffffffcc;
  GmFrustumIso4 *pGVar19;
  TiXmlAttributeSet *pTVar20;
  float *pfVar21;
  float fVar22;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffe8;
  TiXmlAttributeSet *in_stack_ffffffec;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffff0;
  void *pvVar23;
  GmQuadTree<struct_SQuadTreeMeshUv> *pGVar24;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar25;
  
  puVar11 = (undefined4 *)param_2;
  pGVar16 = param_1;
  pCVar25 = (CFastBuffer<class_CPlugFileGPUV*> *)0xffffffff;
  pGVar24 = (GmQuadTree<struct_SQuadTreeMeshUv> *)&LAB_00adbed0;
  if (param_1 == (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
    pGVar10 = (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0;
  }
  else {
    pfVar21 = *(float **)(param_2 + 8);
    pTVar20 = *(TiXmlAttributeSet **)(param_2 + 4);
    fVar22 = *(float *)(param_2 + 0xc);
    pCVar15 = *(CFastBuffer<class_CCrystalFace*> **)(param_2 + 0x10);
    pGVar10 = (GmQuadTree<struct_SQuadTreeMeshUv> *)0x1;
    if (3 < (int)(param_1 + -1)) {
      iVar9 = ((uint)(param_1 + -5) >> 2) + 1;
      pfVar13 = (float *)(param_2 + 0x40);
      pGVar10 = (GmQuadTree<struct_SQuadTreeMeshUv> *)(iVar9 * 4 + 1);
      do {
        if (pfVar13[-9] < (float)pTVar20) {
          pTVar20 = (TiXmlAttributeSet *)pfVar13[-9];
        }
        if (pfVar13[-8] < (float)pfVar21) {
          pfVar21 = (float *)pfVar13[-8];
        }
        if (fVar22 < pfVar13[-7]) {
          fVar22 = pfVar13[-7];
        }
        if ((float)pCVar15 < pfVar13[-6]) {
          pCVar15 = (CFastBuffer<class_CCrystalFace*> *)pfVar13[-6];
        }
        if (pfVar13[-3] < (float)pTVar20) {
          pTVar20 = (TiXmlAttributeSet *)pfVar13[-3];
        }
        if (pfVar13[-2] < (float)pfVar21) {
          pfVar21 = (float *)pfVar13[-2];
        }
        if (fVar22 < pfVar13[-1]) {
          fVar22 = pfVar13[-1];
        }
        if ((float)pCVar15 < *pfVar13) {
          pCVar15 = (CFastBuffer<class_CCrystalFace*> *)*pfVar13;
        }
        if (pfVar13[3] < (float)pTVar20) {
          pTVar20 = (TiXmlAttributeSet *)pfVar13[3];
        }
        if (pfVar13[4] < (float)pfVar21) {
          pfVar21 = (float *)pfVar13[4];
        }
        if (fVar22 < pfVar13[5]) {
          fVar22 = pfVar13[5];
        }
        if ((float)pCVar15 < pfVar13[6]) {
          pCVar15 = (CFastBuffer<class_CCrystalFace*> *)pfVar13[6];
        }
        if (pfVar13[9] < (float)pTVar20) {
          pTVar20 = (TiXmlAttributeSet *)pfVar13[9];
        }
        if (pfVar13[10] < (float)pfVar21) {
          pfVar21 = (float *)pfVar13[10];
        }
        if (fVar22 < pfVar13[0xb]) {
          fVar22 = pfVar13[0xb];
        }
        if ((float)pCVar15 < pfVar13[0xc]) {
          pCVar15 = (CFastBuffer<class_CCrystalFace*> *)pfVar13[0xc];
        }
        pfVar13 = pfVar13 + 0x18;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    if (pGVar10 < param_1) {
      pfVar13 = (float *)(param_2 + 8 + (int)pGVar10 * 0x18);
      iVar9 = (int)param_1 - (int)pGVar10;
      do {
        if (pfVar13[-1] < (float)pTVar20) {
          pTVar20 = (TiXmlAttributeSet *)pfVar13[-1];
        }
        if (*pfVar13 < (float)pfVar21) {
          pfVar21 = (float *)*pfVar13;
        }
        if (fVar22 < pfVar13[1]) {
          fVar22 = pfVar13[1];
        }
        if ((float)pCVar15 < pfVar13[2]) {
          pCVar15 = (CFastBuffer<class_CCrystalFace*> *)pfVar13[2];
        }
        pfVar13 = pfVar13 + 6;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    pvVar23 = ExceptionList;
    ExceptionList = &stack0xfffffff4;
    uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this,(CFastBuffer<class_CCrystalFace*> *)
                            (DAT_00cca150 ^ (uint)&stack0xffffffac));
    if (uVar5 != 0) {
      pSVar6 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                         (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar5 - 1),
                          unaff_EDI);
      *(float *)(pSVar6 + 4) = fVar22;
      *(CFastBuffer<class_CCrystalFace*> **)(pSVar6 + 8) = pCVar15;
      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar6 + 0xc) = in_stack_ffffffe8;
      *(TiXmlAttributeSet **)(pSVar6 + 0x10) = in_stack_ffffffec;
    }
    pGVar10 = (GmQuadTree<struct_SQuadTreeMeshUv> *)0x1;
    pCVar18 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x1;
    if ((((param_6 != 0) && (param_6 <= param_5)) ||
        ((param_7 != 0.0 && (pGVar16 <= (uint)param_7)))) ||
       ((_DAT_00bb98f8 < (float)in_stack_00000020 &&
        (in_stack_ffffffc8 = (float)in_stack_ffffffe8 - fVar22,
        ((float)in_stack_ffffffec - (float)pCVar15) * in_stack_ffffffc8 < (float)in_stack_00000020))
       )) {
      if (pGVar16 != (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
        pGVar10 = pGVar16 + 1;
        do {
          pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>
                   ::AddNewElem(this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                                     unaff_ESI);
          *(undefined4 *)pSVar7 = *puVar11;
          *(undefined4 *)(pSVar7 + 4) = puVar11[1];
          *(undefined4 *)(pSVar7 + 8) = puVar11[2];
          *(undefined4 *)(pSVar7 + 0xc) = puVar11[3];
          *(undefined4 *)(pSVar7 + 0x10) = puVar11[4];
          puVar1 = puVar11 + 5;
          puVar11 = puVar11 + 6;
          pGVar16 = pGVar16 + -1;
          *(undefined4 *)(pSVar7 + 0x14) = *puVar1;
          *(undefined4 *)pSVar7 = 1;
        } while (pGVar16 != (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0);
      }
    }
    else {
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&stack0xfffffff0,unaff_ESI);
      param_2 = 0;
      CFastBuffer<struct_CPlugModelMesh::SPoly>::AllocSetCount
                (&stack0xfffffff4,(CFastBuffer<class_GxVertex2> *)pGVar16,unaff_EBP);
      pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pGVar16 != (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
        do {
          pSVar6 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0xfffffff8,pCVar12,(ulong)unaff_EBX);
          *(undefined4 *)pSVar6 = 0;
          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar6 + 4) = pCVar12;
          pCVar12 = pCVar12 + 1;
        } while (pCVar12 < pGVar16);
      }
      pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                ((float)in_stack_fffffff0 - (float)in_stack_ffffffe8);
      uVar8 = (uint)((float)pCVar12 < (float)pvVar23 - (float)in_stack_ffffffec);
      pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      fVar3 = (float)_DAT_00b313b8;
      pGVar19 = (GmFrustumIso4 *)
                ((*(float *)(&stack0xfffffff0 + uVar8 * 4) +
                 *(float *)(&stack0xffffffe8 + uVar8 * 4)) * fVar3);
      if (param_5 != 0) {
        pfVar21 = (float *)(&stack0xffffffe0 + uVar8 * 4);
        pfVar13 = (float *)(param_6 + 0x10);
        do {
          pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                    ((pfVar13[-3] + pfVar13[-1]) * fVar3);
          pTVar20 = (TiXmlAttributeSet *)((*pfVar13 + pfVar13[-2]) * fVar3);
          fVar22 = (pfVar13[-1] - pfVar13[-3]) * fVar3;
          pCVar15 = (CFastBuffer<class_CCrystalFace*> *)((*pfVar13 - pfVar13[-2]) * fVar3);
          fVar2 = *pfVar21 + *(float *)(&stack0xffffffe8 + uVar8 * 4);
          in_stack_ffffffe8 = pCVar12;
          in_stack_ffffffec = pTVar20;
          if (fVar2 < (float)pGVar19 == (fVar2 == (float)pGVar19)) {
            if ((float)pGVar19 <= *(float *)(&stack0xffffffe8 + uVar8 * 4) - *pfVar21) {
              pSVar6 = CFastBuffer<struct_SFastCat>::operator[]
                                 (&stack0xfffffff8,pCVar17,(ulong)unaff_EBX);
              *(uint *)pSVar6 = *(uint *)pSVar6 | 2;
              goto LAB_008c3282;
            }
          }
          else {
            pSVar6 = CFastBuffer<struct_SFastCat>::operator[]
                               (&stack0xfffffff8,pCVar17,(ulong)unaff_EBX);
            *(uint *)pSVar6 = *(uint *)pSVar6 | 1;
LAB_008c3282:
            fVar3 = (float)_DAT_00b313b8;
          }
          pCVar17 = pCVar17 + 1;
          pfVar13 = pfVar13 + 6;
        } while (pCVar17 < param_5);
      }
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&stack0xffffffe8,unaff_EBX);
      param_4 = CONCAT31(param_4._1_3_,1);
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                (&stack0xffffffec,in_stack_ffffffbc);
      pCVar17 = in_stack_00000020;
      pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (unaff_retaddr != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar6 = CFastBuffer<struct_SFastCat>::operator[]
                             (&stack0x00000000,pCVar14,(ulong)in_stack_ffffffc0);
          if (*(int *)pSVar6 == 1) {
            CFastBuffer<struct_SQuadTreeMeshUv>::Add
                      (&stack0xfffffff4,(TiXmlAttributeSet *)(pCVar17 + *(int *)(pSVar6 + 4) * 0x18)
                       ,(TiXmlAttribute *)pCVar18);
            pCVar18 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x1;
            in_stack_ffffffc0 = pCVar14;
            CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                      (&param_2,(CFastBufferRef<class_CGameMobil> *)pCVar14,1,
                       (ulong)in_stack_ffffffc8);
            unaff_retaddr = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3;
          }
          else {
            pCVar14 = pCVar14 + 1;
          }
        } while (pCVar14 < unaff_retaddr);
      }
      uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (&stack0xfffffff0,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffc0);
      if (uVar5 != 0) {
        if (uVar5 == 1) {
          pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>
                   ::AddNewElem(this,pCVar18);
          pSVar6 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                             (&stack0xfffffff8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                              ,(ulong)in_stack_ffffffc8);
          *(undefined4 *)pSVar7 = *(undefined4 *)pSVar6;
          *(undefined4 *)(pSVar7 + 4) = *(undefined4 *)(pSVar6 + 4);
          *(undefined4 *)(pSVar7 + 8) = *(undefined4 *)(pSVar6 + 8);
          *(undefined4 *)(pSVar7 + 0xc) = *(undefined4 *)(pSVar6 + 0xc);
          *(undefined4 *)(pSVar7 + 0x10) = *(undefined4 *)(pSVar6 + 0x10);
          *(undefined4 *)(pSVar7 + 0x14) = *(undefined4 *)(pSVar6 + 0x14);
          *(undefined4 *)pSVar7 = 1;
          fVar22 = 2.8026e-45;
        }
        else {
          pCVar17 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
          pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>
                   ::AddNewElem(this,pCVar18);
          *(undefined4 *)(pSVar7 + 0x14) = 0xffffffff;
          uVar5 = BuildBintreeRecurse(this,pGVar24,(ulong)pCVar25,
                                      (SQuadTreeMeshUv *)(in_stack_0000002c + 1),
                                      (ulong)in_stack_00000030,in_stack_00000034,in_stack_00000038,
                                      in_stack_ffffffc8);
          pSVar6 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                             (this,pCVar17,in_stack_ffffffcc);
          *(ulong *)pSVar6 = uVar5;
          pCVar15 = (CFastBuffer<class_CCrystalFace*> *)(uVar5 + 1);
          pCVar17 = in_stack_00000030;
        }
      }
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&stack0x00000000,pGVar19);
      pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (unaff_retaddr != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar6 = CFastBuffer<struct_SFastCat>::operator[](&param_5,pCVar14,(ulong)pCVar12);
          if (*(int *)pSVar6 == 2) {
            CFastBuffer<struct_SQuadTreeMeshUv>::Add
                      (&param_2,(TiXmlAttributeSet *)(pCVar17 + *(int *)(pSVar6 + 4) * 0x18),
                       (TiXmlAttribute *)pTVar20);
            pTVar20 = (TiXmlAttributeSet *)0x1;
            pCVar12 = pCVar14;
            CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
                      (&param_7,(CFastBufferRef<class_CGameMobil> *)pCVar14,1,(ulong)pfVar21);
            unaff_retaddr = in_stack_00000020;
          }
          else {
            pCVar14 = pCVar14 + 1;
          }
        } while (pCVar14 < unaff_retaddr);
      }
      uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (&param_1,(CFastBuffer<class_CCrystalFace*> *)pCVar12);
      if (uVar5 != 0) {
        if (uVar5 == 1) {
          pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>
                   ::AddNewElem(this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pTVar20
                               );
          pSVar6 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                             (&param_3,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              (ulong)pfVar21);
          pvVar23 = (void *)((int)pvVar23 + 1);
          *(undefined4 *)pSVar7 = *(undefined4 *)pSVar6;
          *(undefined4 *)(pSVar7 + 4) = *(undefined4 *)(pSVar6 + 4);
          *(undefined4 *)(pSVar7 + 8) = *(undefined4 *)(pSVar6 + 8);
          *(undefined4 *)(pSVar7 + 0xc) = *(undefined4 *)(pSVar6 + 0xc);
          *(undefined4 *)(pSVar7 + 0x10) = *(undefined4 *)(pSVar6 + 0x10);
          *(undefined4 *)(pSVar7 + 0x14) = *(undefined4 *)(pSVar6 + 0x14);
          *(undefined4 *)pSVar7 = 1;
        }
        else {
          pCVar12 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
          pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>
                   ::AddNewElem(this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pTVar20
                               );
          *(undefined4 *)(pSVar7 + 0x14) = 0xffffffff;
          uVar5 = BuildBintreeRecurse(this,(GmQuadTree<struct_SQuadTreeMeshUv> *)param_3,param_4,
                                      (SQuadTreeMeshUv *)(in_stack_00000040 + 1),
                                      (ulong)in_stack_00000044,in_stack_00000048,
                                      (ulong)in_stack_0000004c,(float)pfVar21);
          pSVar6 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                             (this,pCVar12,(ulong)fVar22);
          pGVar24 = pGVar24 + uVar5;
          *(ulong *)pSVar6 = uVar5;
        }
      }
      pGVar16 = (GmQuadTree<struct_SQuadTreeMeshUv> *)
                CFastBuffer<class_CCrystalFace*>::GetCount(&stack0x00000024,pCVar15);
      if ((pGVar16 == in_stack_00000044) || (pGVar16 < (GmQuadTree<struct_SQuadTreeMeshUv> *)0x2)) {
        pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pGVar16 != (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
          pCVar25 = pCVar25 + (int)pGVar16;
          do {
            pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>
                     ::AddNewElem(this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                                       in_stack_fffffff0);
            in_stack_fffffff0 = pCVar12;
            pSVar6 = CFastBuffer<struct_SFastCat>::operator[]
                               (&stack0x00000034,pCVar12,(ulong)pvVar23);
            iVar9 = *(int *)(pSVar6 + 4);
            *(undefined4 *)pSVar7 = *(undefined4 *)(in_stack_00000058 + iVar9 * 0x18);
            iVar9 = in_stack_00000058 + iVar9 * 0x18;
            *(undefined4 *)(pSVar7 + 4) = *(undefined4 *)(iVar9 + 4);
            *(undefined4 *)(pSVar7 + 8) = *(undefined4 *)(iVar9 + 8);
            *(undefined4 *)(pSVar7 + 0xc) = *(undefined4 *)(iVar9 + 0xc);
            *(undefined4 *)(pSVar7 + 0x10) = *(undefined4 *)(iVar9 + 0x10);
            pCVar12 = pCVar12 + 1;
            *(undefined4 *)(pSVar7 + 0x14) = *(undefined4 *)(iVar9 + 0x14);
            *(undefined4 *)pSVar7 = 1;
          } while (pCVar12 < pGVar16);
        }
      }
      else {
        CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                  (&param_6,(GmFrustumIso4 *)in_stack_ffffffe8);
        pvVar4 = in_stack_0000004c;
        pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pGVar16 != (GmQuadTree<struct_SQuadTreeMeshUv> *)0x0) {
          do {
            pSVar6 = CFastBuffer<struct_SFastCat>::operator[]
                               (&stack0x0000002c,pCVar12,(ulong)in_stack_ffffffec);
            in_stack_ffffffec = (TiXmlAttributeSet *)((int)pvVar4 + *(int *)(pSVar6 + 4) * 0x18);
            CFastBuffer<struct_SQuadTreeMeshUv>::Add
                      (&stack0x00000020,in_stack_ffffffec,(TiXmlAttribute *)in_stack_fffffff0);
            pCVar12 = pCVar12 + 1;
          } while (pCVar12 < pGVar16);
        }
        pCVar12 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this;
        pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>::
                 AddNewElem(this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                                 in_stack_ffffffec);
        *(undefined4 *)(pSVar7 + 0x14) = 0xffffffff;
        uVar5 = BuildBintreeRecurse(this,pGVar16,in_stack_00000024,
                                    (SQuadTreeMeshUv *)(in_stack_00000054 + 1),in_stack_00000058,
                                    in_stack_0000005c,in_stack_00000060,(float)in_stack_fffffff0);
        pSVar6 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                           (this,pCVar12,(ulong)pvVar23);
        param_3 = param_3 + uVar5;
        *(ulong *)pSVar6 = uVar5;
      }
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (&stack0x00000028,(CFastBuffer<class_CPlugFileGPUV*> *)pGVar24);
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (&stack0x0000003c,pCVar25);
      pGVar10 = (GmQuadTree<struct_SQuadTreeMeshUv> *)param_5;
    }
  }
  ExceptionList = in_stack_0000004c;
  return (ulong)pGVar10;
}
}

