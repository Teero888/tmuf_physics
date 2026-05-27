// Class implementation: CHmsCollisionManager_SGroup

// =================================================
// Function: CHmsCollisionManager::SGroup::AddCorpus
// =================================================
void __thiscall
CHmsCollisionManager::SGroup::AddCorpus(void *this,SZone *param_1,CHmsCorpus *param_2)
{
{
  TiXmlAttribute *unaff_ESI;
  CHmsCorpus *unaff_retaddr;
  
  CFastBuffer<class_CDx9TextureKeeper*>::Add(this,(TiXmlAttributeSet *)&param_1,unaff_ESI);
  AddNonStaticCorpus(this,(SGroup *)param_2,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::AddNonStaticCorpus
// =================================================
void __thiscall
CHmsCollisionManager::SGroup::AddNonStaticCorpus(void *this,SGroup *param_1,CHmsCorpus *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  ulong uVar2;
  GxColor *pGVar3;
  SCasterCat *pSVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  TiXmlAttribute *unaff_EBX;
  CPlugVisualLines2D *unaff_EBP;
  TiXmlAttribute *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *pCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  GxColor *pGVar8;
  CFastRectTable<int> *in_stack_00000018;
  CFastBuffer<class_CCrystalFace*> *pCVar9;
  
  pCVar9 = this;
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            ((void *)((int)this + 0xc),(TiXmlAttributeSet *)&param_1,unaff_ESI);
  pCVar7 = (CFastBuffer<class_CCrystalFace*> *)0x0;
  CFastBuffer<float>::Add
            ((void *)((int)this + 0x18),(TiXmlAttributeSet *)&stack0x00000000,unaff_EBX);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0xc),pCVar9);
  *(ulong *)(in_stack_00000010 + 0x54) = uVar2 - 1;
  pGVar3 = (GxColor *)CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x24),pCVar7);
  pGVar8 = (GxColor *)0x0;
  if (pGVar3 != (GxColor *)0x0) {
    do {
      pSVar4 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                         ((void *)((int)this + 0x24),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar8,unaff_EDI);
      unaff_EDI = 0x5377a9;
      CFastRectTable<int>::AddLine(pSVar4 + 8,unaff_EBP,(GmVec2 *)param_1,(GmVec2 *)param_2,pGVar3);
      pGVar3 = (GxColor *)0x5377b3;
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         ((void *)(*(int *)pSVar4 + 0x24),
                          (CFastBuffer<class_CCrystalFace*> *)in_stack_00000010);
      pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          in_stack_00000010 = pCVar1;
          pGVar3 = (GxColor *)0x5377cb;
          pSVar6 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                             ((void *)(*(int *)pSVar4 + 0x24),in_stack_00000010,(ulong)pGVar8);
          if (*(void **)pSVar6 == this) {
            pGVar8 = (GxColor *)0x5377d7;
            CFastRectTable<int>::AddColumn(pSVar6 + 8,in_stack_00000018);
          }
          pCVar1 = in_stack_00000010 + 1;
        } while (in_stack_00000010 + 1 < pCVar5);
      }
      pGVar8 = pGVar8 + 1;
    } while (pGVar8 < pGVar3);
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::AddStaticSurfacesFromTree
// =================================================
void __thiscall
CHmsCollisionManager::SGroup::AddStaticSurfacesFromTree
          (void *this,SGroup *param_1,CHmsCorpus *param_2,CPlugTree *param_3,GmIso4 *param_4,
          CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell> *param_5)
{
{
  CPlugTree *pCVar1;
  CHmsCorpus *pCVar2;
  int iVar3;
  undefined *puVar4;
  SLoadedLight *pSVar5;
  int iVar6;
  undefined *puVar7;
  void *unaff_EBX;
  CPlugTree *pCVar8;
  undefined4 *puVar9;
  GmIso4 *unaff_EDI;
  GmIso4 *pGVar10;
  SLoadedLight *pSVar11;
  SGroup *unaff_retaddr;
  CPlugTree *pCVar12;
  GmIso4 *pGVar13;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar14;
  undefined *local_44;
  undefined *puStack_40;
  GmIso4 local_3c [4];
  SPlugFaceCull aSStack_38 [4];
  undefined4 auStack_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a955a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((char)*(uint *)(param_2 + 0x9c) < '\0') {
    local_44 = this;
    if ((*(uint *)(param_2 + 0x9c) & 4) == 0) {
      pCVar1 = param_3;
      pGVar10 = local_3c;
      for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined4 *)pGVar10 = *(undefined4 *)pCVar1;
        pCVar1 = pCVar1 + 4;
        pGVar10 = pGVar10 + 4;
      }
    }
    else {
      GmIso4::SetMult(local_3c,(SPlugFaceCull *)(param_2 + 0x5c),(SPlugFaceCull *)param_3,
                      (GmIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffffac));
    }
    pCVar14 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x53994d;
    pCVar1 = (CPlugTree *)(**(code **)(*(int *)param_2 + 0x7c))();
    pCVar8 = (CPlugTree *)0x0;
    if (pCVar1 != (CPlugTree *)0x0) {
      do {
        pGVar10 = local_3c;
        pCVar12 = pCVar8;
        pGVar13 = param_4;
        pCVar2 = (CHmsCorpus *)(**(code **)(*(int *)param_2 + 0x80))();
        AddStaticSurfacesFromTree
                  (unaff_EBX,unaff_retaddr,pCVar2,pCVar12,pGVar10,
                   (CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell> *)pGVar13);
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < pCVar1);
    }
    iVar6 = *(int *)(param_2 + 0x8c);
    if (iVar6 != 0) {
      if (0.0 <= *(float *)(*(int *)(iVar6 + 0x14) + 0x28)) {
        pSVar5 = CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
                           (param_4,pCVar14);
        GmBoxAligned::SetMult
                  (pSVar5 + 4,(SPlugFaceCull *)(*(int *)(iVar6 + 0x14) + 0x1c),aSStack_38,unaff_EDI)
        ;
        *(int *)(pSVar5 + 0x4c) = iVar6;
        puVar9 = auStack_34;
        pSVar11 = pSVar5 + 0x1c;
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined4 *)pSVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          pSVar11 = pSVar11 + 4;
        }
        *(CPlugTree **)(pSVar5 + 0x54) = param_3;
        *(CHmsCorpus **)(pSVar5 + 0x50) = param_2;
      }
      else {
        DAT_00d71d8c = DAT_00d71d8c + 1;
        local_44 = (undefined *)0x0;
        puStack_40 = PTR_DAT_00bbf7dc;
        uStack_4 = 0;
        iVar6 = *(int *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x68);
        iVar3 = *(int *)(*(int *)(param_1 + 0x48) + 0x14);
        if (iVar6 != 0) {
          iVar3 = iVar6;
        }
        puVar7 = PTR_DAT_00bbf7dc;
        if (*(CSystemFidFile **)(iVar3 + 8) != (CSystemFidFile *)0x0) {
          CSystemFidFile::GetFullName
                    (*(CSystemFidFile **)(iVar3 + 8),(CPlugFile *)&local_44,(CFastStringInt *)0x0);
          puVar7 = local_44;
        }
        DAT_00d71d8c = DAT_00d71d8c + -1;
        if (puVar7 != PTR_DAT_00bbf7dc) {
          puVar4 = puVar7 + -4;
          if ((puVar7[-1] & 0x80) == 0) {
            puVar4 = puVar7 + -2;
          }
          operator_delete__(puVar4);
        }
      }
    }
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::ClearAllStatic
// =================================================
void __thiscall CHmsCollisionManager::SGroup::ClearAllStatic(void *this,SGroup *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CHmsCorpus *unaff_EBX;
  SGroup *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  GmFrustumIso4 *in_stack_00000008;
  SGroup *pSVar4;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this,pCVar3,(ulong)unaff_ESI);
      pSVar4 = *(SGroup **)pSVar2;
      if (*(int *)(pSVar4 + 0x54) == -1) {
        AddNonStaticCorpus(this,pSVar4,unaff_EBX);
        unaff_ESI = pSVar4;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            ((void *)((int)this + 0x30),in_stack_00000008);
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::ComputeIsToPerformCollisions
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsCollisionManager::SGroup::ComputeIsToPerformCollisions(void *this,SGroup *param_1)
{
{
  CSystemFid *pCVar1;
  int iVar2;
  uint uVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  SCasterCat *pSVar6;
  CMwNod *pCVar7;
  SCasterCat *pSVar8;
  SCasterCat *pSVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CSystemData *pCVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CSystemFid *pCVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  CSystemFid *unaff_EDI;
  undefined4 uVar14;
  SCasterCat *in_stack_00000010;
  CSystemFid *pCVar15;
  ulong *in_stack_ffffffe8;
  int local_14;
  SCasterCat *local_c;
  int local_8;
  SCasterCat *local_4;
  
  if (*(int *)((int)this + 0x40) == 0) {
    pCVar15 = this;
    pSVar5 = (SCasterCat *)
             CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x24),unaff_ESI);
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pSVar5 != (SCasterCat *)0x0) {
      do {
        pSVar6 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                           ((ulong *)((int)this + 0x24),pCVar10,(ulong)unaff_EDI);
        pSVar8 = *(SCasterCat **)(pSVar6 + 0xc);
        this = in_stack_ffffffe8;
        if (*(int *)(*(int *)pSVar6 + 0x40) == 0) {
          local_c = *(SCasterCat **)(pSVar6 + 0x10);
          pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          pSVar9 = pSVar8;
          pSVar5 = pSVar8;
          if (pSVar8 != (SCasterCat *)0x0) {
            do {
              pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              if (local_c != (SCasterCat *)0x0) {
                do {
                  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     ((void *)(local_14 + 0x18),pCVar10,(ulong)unaff_EBP);
                  iVar2 = *(int *)pSVar6;
                  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     ((void *)(iVar2 + 0x18),pCVar13,(ulong)unaff_EBX);
                  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                           (*(float *)pSVar9 - *(float *)pSVar6);
                  if (_DAT_00b55d98 < (float)pCVar4) {
LAB_0053803c:
                    uVar14 = 1;
                  }
                  else {
                    if ((float)pCVar4 < _DAT_00b55d98 != ((float)pCVar4 == _DAT_00b55d98)) {
                      uVar3 = *(uint *)(iVar2 + 0x3c);
                      if (((*(uint *)(local_c + 0x3c) == uVar3) && (pCVar13 != pCVar10)) ||
                         (*(uint *)(local_c + 0x3c) < uVar3)) goto LAB_0053803c;
                    }
                    uVar14 = 0;
                  }
                  unaff_EDI = (CSystemFid *)0x53804f;
                  unaff_EBP = pCVar10;
                  unaff_EBX = pCVar13;
                  pCVar7 = CFastRectTable<int>::Get
                                     ((void *)(local_8 + 8),(CSystemData *)pCVar10,
                                      (CSystemFid *)pCVar13,pCVar15,this);
                  pCVar13 = pCVar13 + 1;
                  *(undefined4 *)pCVar7 = uVar14;
                  pSVar9 = in_stack_00000010;
                  pSVar6 = pSVar8;
                } while (pCVar13 < pCVar4);
              }
              pCVar10 = pCVar10 + 1;
            } while (pCVar10 < pSVar9);
          }
        }
        else {
          pCVar1 = *(CSystemFid **)(pSVar6 + 0x10);
          pCVar11 = (CSystemData *)0x0;
          local_c = pSVar8;
          if (pSVar8 != (SCasterCat *)0x0) {
            do {
              pCVar12 = (CSystemFid *)0x0;
              if (pCVar1 != (CSystemFid *)0x0) {
                do {
                  unaff_EDI = pCVar12;
                  pCVar7 = CFastRectTable<int>::Get
                                     (pSVar6 + 8,pCVar11,pCVar12,(CSystemFid *)unaff_EBP,
                                      (ulong *)unaff_EBX);
                  pCVar12 = pCVar12 + 1;
                  *(undefined4 *)pCVar7 = 1;
                  pSVar8 = local_4;
                } while (pCVar12 < pCVar1);
              }
              pCVar11 = pCVar11 + 1;
            } while (pCVar11 < pSVar8);
          }
        }
        pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(local_c + 1);
        in_stack_ffffffe8 = this;
      } while (pCVar10 < pSVar5);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::ComputeNonStaticCorpusInfos
// =================================================
void __thiscall
CHmsCollisionManager::SGroup::ComputeNonStaticCorpusInfos(void *this,SGroup *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  float unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 local_c;
  float local_8;
  
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&stack0xfffffffc;
  if (*(int *)((int)this + 0x40) == 0) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x18),unaff_EDI);
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)((int)this + 0xc),pCVar3,unaff_ESI);
        if (*(void **)(*(int *)pSVar2 + 0x58) == (void *)0x0) {
          unaff_EBP = 0.0;
          local_8 = 0.0;
          local_c = 0;
        }
        else {
          CHmsDyna::GetLinearSpeed
                    (*(void **)(*(int *)pSVar2 + 0x58),(CHmsItem *)&local_c,(GmVec3 *)pCVar4);
        }
        local_1c = SUB84((double)local_8,0);
        uStack_18 = (undefined4)((ulonglong)(double)local_8 >> 0x20);
        uStack_20 = (undefined4)((ulonglong)(double)unaff_EBP >> 0x20);
        local_14 = SUB84((double)unaff_retaddr,0);
        uStack_10 = (undefined4)((ulonglong)(double)unaff_retaddr >> 0x20);
        unaff_ESI = 0x537efb;
        pCVar4 = pCVar3;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)((int)this + 0x18),pCVar3,unaff_EBX);
        pCVar3 = pCVar3 + 1;
        *(float *)pSVar2 =
             (float)((float10)(double)CONCAT44(local_c,uStack_10) *
                     (float10)(double)CONCAT44(local_c,uStack_10) +
                    (float10)(double)CONCAT44(local_14,uStack_18) *
                    (float10)(double)CONCAT44(local_14,uStack_18) +
                    (float10)(double)CONCAT44(local_1c,uStack_20) *
                    (float10)(double)CONCAT44(local_1c,uStack_20));
      } while (pCVar3 < pCVar1);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::RemoveCorpus
// =================================================
void __thiscall
CHmsCollisionManager::SGroup::RemoveCorpus(void *this,CHmsZoneOverlay *param_1,CHmsCorpus *param_2)
{
{
  ulong unaff_ESI;
  SGroup *unaff_retaddr;
  
  CFastBuffer<class_CGameCtnBlock*>::Remove
            (this,(CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)&param_1,
             unaff_ESI);
  if (*(int *)(param_2 + 0x54) != -1) {
    RemoveNonStaticCorpus(this,(SGroup *)param_2,(CHmsCorpus *)unaff_retaddr);
    return;
  }
  ClearAllStatic(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::RemoveNonStaticCorpus
// =================================================
void __thiscall
CHmsCollisionManager::SGroup::RemoveNonStaticCorpus(void *this,SGroup *param_1,CHmsCorpus *param_2)
{
{
  void *this_00;
  CFastBufferRef<class_CGameMobil> *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_retaddr;
  ulong in_stack_0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000010;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000018;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff8;
  CFastBufferRef<class_CGameMobil> *in_stack_fffffffc;
  
  pCVar1 = *(CFastBufferRef<class_CGameMobil> **)(param_1 + 0x54);
  this_00 = (void *)((int)this + 0xc);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 - 1),
                      unaff_ESI);
  *(CFastBufferRef<class_CGameMobil> **)(*(int *)pSVar3 + 0x54) = pCVar1;
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt(this_00,pCVar1,1,unaff_EBP);
  CFastBuffer<float>::ReplaceByLastAt((void *)((int)this + 0x18),pCVar1,1,unaff_EBX);
  pCStack00000010 =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
       CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x24),in_stack_fffffff8);
  pCStack00000018 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack00000010 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                         ((void *)((int)this + 0x24),pCStack00000018,(ulong)in_stack_fffffffc);
      in_stack_fffffffc = pCVar1;
      CFastRectTable<int>::ReplaceLineByLastAt
                (pSVar3 + 8,(CFastRectTable<int> *)pCVar1,unaff_retaddr);
      unaff_retaddr = 0x5378a2;
      pCStack00000018 =
           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(*(int *)pSVar3 + 0x24),(CFastBuffer<class_CCrystalFace*> *)param_1);
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCStack00000018 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          unaff_retaddr = 0x5378bb;
          pSVar4 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                             ((void *)(*(int *)pSVar3 + 0x24),pCVar5,(ulong)param_2);
          param_1 = (SGroup *)pCVar5;
          if (*(void **)pSVar4 == this) {
            param_1 = (SGroup *)0x5378c8;
            CFastRectTable<int>::ReplaceColumnByLastAt
                      (pSVar4 + 8,(CFastRectTable<int> *)pCVar1,in_stack_0000000c);
            param_2 = (CHmsCorpus *)pCVar1;
          }
          pCVar5 = pCVar5 + 1;
        } while (pCVar5 < pCStack00000018);
      }
      pCStack00000018 = pCStack00000018 + 1;
    } while (pCStack00000018 < pCStack00000010);
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::SGroup
// =================================================
void __thiscall CHmsCollisionManager::SGroup::SGroup(void *this,SGroup *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000008;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000000c;
  
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0xc),unaff_retaddr);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x18),(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x24),in_stack_00000008);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x30),in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::UpdateStaticCollisionTrees
// =================================================
void __thiscall
CHmsCollisionManager::SGroup::UpdateStaticCollisionTrees(void *this,CHmsCollisionManager *param_1)
{
{
  SGroup *pSVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  undefined4 *puVar4;
  NvStripInfo *pNVar5;
  int iVar6;
  CHmsCorpus *unaff_EBX;
  SGroup *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CPlugTree *pCVar8;
  vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> *pvVar9;
  vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *pvVar10;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar11;
  CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell> *pCVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_44;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_40;
  undefined1 auStack_3c [4];
  CFastBuffer<class_CCrystalFace*> *local_38;
  CPlugTree local_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a956d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  ClearAllStatic(this,(SGroup *)(DAT_00cca150 ^ (uint)&stack0xffffffa0));
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_44,unaff_EDI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_ESI);
  local_44 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_40 = pCVar2;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pCVar7 = local_44;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this,local_44,(ulong)unaff_EBP);
      pSVar1 = *(SGroup **)pSVar3;
      if ((*(uint *)(*(int *)(pSVar1 + 0x48) + 0x18) & 0x80000) != 0) {
        pCVar12 = (CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell> *)0x53aec0;
        unaff_EBP = pSVar1;
        RemoveNonStaticCorpus(this,pSVar1,unaff_EBX);
        unaff_EBX = (CHmsCorpus *)0x53aec9;
        puVar4 = (undefined4 *)(**(code **)(*(int *)pSVar1 + 0x78))();
        pCVar8 = local_34;
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined4 *)pCVar8 = *puVar4;
          puVar4 = puVar4 + 1;
          pCVar8 = pCVar8 + 4;
        }
        AddStaticSurfacesFromTree
                  (this,pSVar1,*(CHmsCorpus **)(*(int *)(*(int *)(pSVar1 + 0x48) + 0x14) + 100),
                   local_34,(GmIso4 *)&local_40,pCVar12);
        pCVar7 = local_44;
        pCVar2 = local_40;
      }
      local_44 = pCVar7 + 1;
    } while (local_44 < pCVar2);
  }
  pCVar11 = (CFastBuffer<class_CPlugFileGPUV*> *)0x0;
  pvVar10 = (vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *)0x0;
  pvVar9 = (vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> *)0x1;
  pNVar5 = (NvStripInfo *)CFastBuffer<class_CCrystalFace*>::GetCount(auStack_3c,local_38);
  GmOctree<struct_CHmsCollisionManager::SColOctreeCell>::Build
            ((void *)((int)this + 0x30),pNVar5,pvVar9,pvVar10);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_44,pCVar11);
  ExceptionList = pvStack_4;
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SGroup::~SGroup
// =================================================
void __thiscall CHmsCollisionManager::SGroup::~SGroup(void *this,SGroup *param_1)
{
{
  CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup> *unaff_ESI;
  void *in_stack_00000008;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar1;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar2;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar3;
  
  pCVar3 = (CFastBuffer<class_CPlugFileGPUV*> *)&LAB_00a956ae;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x30),
             (CFastBuffer<class_CPlugFileGPUV*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>::
  ~CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>
            ((void *)((int)this + 0x24),unaff_ESI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x18),pCVar1);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0xc),pCVar2);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this,pCVar3);
  ExceptionList = in_stack_00000008;
  return;
}
}

