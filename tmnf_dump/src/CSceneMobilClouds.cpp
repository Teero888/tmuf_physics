// Class implementation: CSceneMobilClouds

// =================================================
// Function: CSceneMobilClouds::BitmapOccAttach
// =================================================
void __thiscall
CSceneMobilClouds::BitmapOccAttach(CSceneMobilClouds *this,CSceneMobilClouds *param_1,int param_2)
{
{
  CPlugBitmapRender *this_00;
  
  if (*(int *)(this + 0x98) == 0) {
    return;
  }
  this_00 = *(CPlugBitmapRender **)(*(int *)(this + 0x98) + 0x74);
  if (param_1 != (CSceneMobilClouds *)0x0) {
    CPlugBitmapRender::DepObjectAddSafe_IsAdded
              (this_00,*(CPlugBitmapRender **)(this + 0x28),(CMwNod *)param_2);
    return;
  }
  CPlugBitmapRenderLightOcc::ItemOccSub
            ((CPlugBitmapRenderLightOcc *)this_00,*(CPlugBitmapRenderLightOcc **)(this + 0x28),
             (CHmsItem *)param_2);
  return;
}
}

// =================================================
// Function: CSceneMobilClouds::BuildInstances
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneMobilClouds::BuildInstances(CSceneMobilClouds *this,CSceneMobilClouds *param_1)
{
{
  float fVar1;
  CPlugVisualSprite *this_00;
  uint uVar2;
  CPlugShader *this_01;
  float fVar3;
  CMwNod *pCVar4;
  CPlugTree *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  CPlugTree *this_02;
  int iVar8;
  CPlugBitmapRender *pCVar9;
  GmMat43 *pGVar10;
  undefined *puVar11;
  CSystemFidParameters *unaff_EBX;
  GmRectAligned *unaff_ESI;
  CSceneMobilClouds *pCVar12;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  undefined1 uStack00000008;
  int iVar14;
  CFastArray<class_GxTexCoordSet> *pCVar15;
  CSystemFidParameters *this_03;
  GmRectAligned *pGVar16;
  TiXmlAttribute *pTVar17;
  SParam *pSVar18;
  GmVec2 *pGVar19;
  CPlugBitmapAddress **ppCVar20;
  SParam_Id *in_stack_ffffff18;
  CFastString *this_04;
  char *in_stack_ffffff1c;
  CPlugTree *pCVar21;
  CPlugShader *pCStack_dc;
  CPlugShader *local_d8;
  GmMat43 *in_stack_ffffff2c;
  int iVar22;
  CPlugTree *pCVar23;
  CPlugTree *pCVar24;
  CSceneMobilClouds *pCStack_c4;
  CSceneMobilClouds *pCStack_c0;
  float fStack_bc;
  float fStack_b8;
  CMwNod *pCStack_b4;
  CPlugTree *pCStack_b0;
  SParam_Id aSStack_ac [4];
  uint uStack_a8;
  undefined *puStack_a4;
  undefined4 uStack_a0;
  undefined *puStack_9c;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  undefined4 auStack_7c [2];
  undefined4 uStack_74;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  CSystemFidParameters aCStack_48 [4];
  CPlugTree aCStack_44 [4];
  CSystemFidParameters aCStack_40 [4];
  CSystemFidParameters aCStack_3c [4];
  CSystemFidParameters aCStack_38 [8];
  CSystemFidParameters aCStack_30 [12];
  float fStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  void *pvStack_c;
  
  pGVar19 = (GmVec2 *)&stack0xfffffffc;
  pvStack_c = (void *)0xffffffff;
  puStack_10 = &LAB_00acdcf6;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar14 = 0x7d362e;
  local_d8 = (CPlugShader *)this;
  pCVar5 = CSceneMobil::GetTree
                     ((CSceneMobil *)this,
                      (SVolatileTreePointer *)(DAT_00cca150 ^ (uint)&stack0xffffff08));
  local_d8 = (CPlugShader *)pCVar5;
  (**(code **)(*(int *)pCVar5 + 0x94))();
  *(uint *)(pCVar5 + 0x9c) = *(uint *)(pCVar5 + 0x9c) & 0xffffbf77;
  pCVar15 = (CFastArray<class_GxTexCoordSet> *)0x7d3653;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x48,unaff_EDI);
  pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if ((pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) &&
     (*(int *)(this + 0x88) * *(int *)(this + 0x84) != 0)) {
    pCVar21 = (CPlugTree *)0x0;
    pGVar16 = unaff_ESI;
    if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pCVar15 = (CFastArray<class_GxTexCoordSet> *)0x7d3689;
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x48,pCVar13,(ulong)pGVar16);
        iVar22 = *(int *)(*(int *)pSVar7 + 100);
        unaff_ESI = pGVar16;
        if ((*(byte *)(iVar22 + 0x9c) & 8) != 0) {
          unaff_ESI = (GmRectAligned *)(iVar22 + 0x34);
          if (pCStack_dc == (CPlugShader *)0x0) {
            fStack_90 = *(float *)unaff_ESI;
            fStack_8c = *(float *)(iVar22 + 0x38);
            fStack_88 = *(float *)(iVar22 + 0x3c);
            fStack_84 = *(float *)(iVar22 + 0x40);
            fStack_80 = *(float *)(iVar22 + 0x44);
            auStack_7c[0] = *(undefined4 *)(iVar22 + 0x48);
            unaff_ESI = pGVar16;
          }
          else {
            GmBoxAligned::Union(&fStack_90,unaff_ESI,pGVar19);
          }
          pCVar21 = pCVar21 + 1;
        }
        pCVar13 = pCVar13 + 1;
        pGVar16 = unaff_ESI;
      } while (pCVar13 < pCVar6);
    }
    *(float *)(this + 0x80) = fStack_90 - fStack_84;
    if (*(int *)(this + 0x68) == 0) {
      fStack_b8 = fStack_88 * (float)_DAT_00b33a58;
      pCVar24 = (CPlugTree *)((float)_DAT_00b33a58 * fStack_80);
      pCStack_b0 = pCVar24;
    }
    else {
      pCVar24 = *(CPlugTree **)(this + 0x78);
    }
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (auStack_7c,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_ESI);
    this_03 = (CSystemFidParameters *)0x7d374a;
    BitmapOccAttach(this,(CSceneMobilClouds *)0x0,(int)pGVar19);
    pTVar17 = (TiXmlAttribute *)0x7d375b;
    CSystemFidParameters::CSystemFidParameters
              (aCStack_38,(CSystemFidParameters *)&DAT_00d55500,unaff_EBX);
    uStack00000008 = 1;
    if (*(int *)(this + 0x70) != 0) {
      pSVar18 = (SParam *)0x1;
      CSystemFidParameters::SParam_Id::SParam_Id(aSStack_ac,(SParam_Id *)&DAT_00d6ecf8);
      CSystemFidParameters::AddParam(aCStack_40,(CSystemFidParameters *)&fStack_b8,pSVar18);
      this_03 = aCStack_3c;
      pTVar17 = (TiXmlAttribute *)0x1;
      pCVar15 = (CFastArray<class_GxTexCoordSet> *)0x7d37a6;
      CSystemFidParameters::Push(this_03,(CFastBufferWheel<float> *)this_03,(float *)0x1);
      uStack00000008 = 1;
      CSystemFidParameters::SParam_Id::~SParam_Id((SParam_Id *)aSStack_ac,in_stack_ffffff18);
    }
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCStack_b0 = (CPlugTree *)0x0;
    if (*(int *)(this + 0x88) != 0) {
      do {
        pCStack_b4 = (CMwNod *)0x0;
        if (*(int *)(this + 0x84) != 0) {
          fStack_88 = (float)((uint)pCStack_b0 & 1);
          fStack_8c = (float)(int)pCStack_b0;
          if ((int)pCStack_b0 < 0) {
            fStack_8c = fStack_8c + _DAT_00c418d0;
          }
          fStack_8c = fStack_8c * fStack_b8;
          pCVar12 = this;
          pCVar23 = pCStack_b0;
          do {
            fVar1 = fStack_88;
            pCVar4 = pCStack_b4;
            pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (pCVar12 + 0x48,pCVar6,(ulong)in_stack_ffffff1c);
            this_02 = CPlugTree::DuplicateRecursive(*(CPlugTree **)(*(int *)pSVar7 + 100),pCVar21);
            uStack_a0 = 0;
            puStack_9c = PTR_DAT_00bbf7d8;
            pCVar21 = (CPlugTree *)(**(code **)(*(int *)pCVar5 + 0x7c))();
            this_04 = (CFastString *)&uStack_a0;
            in_stack_ffffff1c = "Inst%02d";
            CFastString::Format(this_04,this_04,"Inst%02d");
            fVar1 = (float)((int)fVar1 + ((uint)pCVar4 & 1) * 2);
            local_d8 = (CPlugShader *)0x7d387f;
            GmMat3::SetIdentity(auStack_50,in_stack_ffffff2c);
            fVar3 = (float)(int)fVar1;
            if ((int)fVar1 < 0) {
              fVar3 = fVar3 + _DAT_00c418d0;
            }
            pCStack_b4 = (CMwNod *)(fVar3 * (float)_DAT_00b36110 * (float)_DAT_00b313b8);
            local_d8 = (CPlugShader *)0x7d38b5;
            fStack_b8 = fVar1;
            GmMat3::RotateY(auStack_4c,(GmIso4 *)pCStack_b4,(float)pCVar6);
            fStack_24 = (float)(int)pCVar4;
            if ((int)pCVar4 < 0) {
              fStack_24 = fStack_24 + _DAT_00c418d0;
            }
            fStack_24 = fStack_24 * (float)puStack_a4;
            uStack_20 = 0;
            uStack_1c = uStack_74;
            iVar22 = 0x7d38ef;
            pCStack_b4 = pCVar4;
            CPlugTree::SetUseLocation(this_02,(CPlugTree *)0x1,(int)pCVar23);
            CPlugTree::SetLocation(this_02,aCStack_44,(GmIso4 *)pCVar24);
            pCVar24 = this_02;
            (**(code **)(*(int *)pCVar5 + 0x88))();
            pCVar23 = (CPlugTree *)0x7d3915;
            pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     (**(code **)(*(int *)this_02 + 0x7c))();
            pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              do {
                ppCVar20 = (CPlugBitmapAddress **)0x7d3930;
                pCVar5 = (CPlugTree *)(**(code **)(*(int *)this_02 + 0x80))();
                CPlugTree::SetUseLocation(pCVar5,(CPlugTree *)0x1,iVar14);
                this_00 = *(CPlugVisualSprite **)(pCVar5 + 0x90);
                uStack_a8 = *(uint *)(this_00 + 0xb0) | 0x10;
                CPlugVisualSprite::SetSpriteFlags
                          (this_00,(CPlugVisualSprite *)&uStack_a8,(SSpriteF *)pCVar15);
                uVar2 = *(uint *)(this_00 + 0x1c);
                if ((((uVar2 & 8) == 0) &&
                    (*(uint *)(this_00 + 0x1c) = uVar2 | 8, (uVar2 & 0x400) == 0)) &&
                   (*(uint *)(this_00 + 0x1c) = uVar2 | 0x408, DAT_00d6eb04 != (undefined4 *)0x0)) {
                  (**(code **)*DAT_00d6eb04)(this_00);
                }
                this_01 = *(CPlugShader **)(pCVar5 + 0x94);
                pCVar15 = (CFastArray<class_GxTexCoordSet> *)&pCStack_dc;
                iVar14 = 0x7d399f;
                pCStack_dc = this_01;
                iVar8 = CFastArray<class_CGameMenuFrame*>::Find
                                  (&fStack_80,pCVar15,(GxTexCoordSet *)this_03);
                pCVar5 = pCVar24;
                if (iVar8 == -1) {
                  local_d8 = this_01;
                  CFastBuffer<class_CDx9TextureKeeper*>::Add
                            (auStack_7c,(TiXmlAttributeSet *)&local_d8,pTVar17);
                  pTVar17 = (TiXmlAttribute *)0x0;
                  this_03 = (CSystemFidParameters *)&fStack_b8;
                  pCVar15 = (CFastArray<class_GxTexCoordSet> *)0x909f000;
                  fStack_b8 = 0.0;
                  iVar14 = 0x7d39d1;
                  pCVar9 = CPlugShader::FindBitmapRenderByClassId
                                     (this_01,(CPlugShader *)0x909f000,(ulong)this_03,
                                      (CPlugBitmap **)0x0,ppCVar20);
                  pCVar4 = pCStack_b4;
                  pCVar5 = pCVar24;
                  if ((pCVar9 != (CPlugBitmapRender *)0x0) &&
                     (pCStack_b4 != *(CMwNod **)(pCVar24 + 0x98))) {
                    if (pCStack_b4 != (CMwNod *)0x0) {
                      CMwNod::MwAddRef(pCStack_b4,(CMwNod *)this_04);
                    }
                    if (*(CMwNod **)(pCVar24 + 0x98) != (CMwNod *)0x0) {
                      CMwNod::MwRelease(*(CMwNod **)(pCVar24 + 0x98),(CMwNod *)this_04);
                    }
                    *(CMwNod **)(pCVar24 + 0x98) = pCVar4;
                  }
                }
                pCVar13 = pCVar13 + 1;
                pCVar24 = pCVar5;
              } while (pCVar13 < pCVar6);
            }
            in_stack_ffffff2c = (GmMat43 *)(iVar22 + 1U);
            pGVar10 = (GmMat43 *)
                      CFastBuffer<class_CCrystalFace*>::GetCount
                                (pCStack_c4 + 0x48,(CFastBuffer<class_CCrystalFace*> *)this_04);
            if ((GmMat43 *)(iVar22 + 1U) == pGVar10) {
              pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            }
            if (puStack_a4 != PTR_DAT_00bbf7d8) {
              puVar11 = puStack_a4 + -1;
              if ((puStack_a4[-1] & 0x80) != 0) {
                puVar11 = puStack_a4 + -4;
              }
              operator_delete__(puVar11);
              uStack_a8 = 0;
              puStack_a4 = PTR_DAT_00bbf7d8;
            }
            pCStack_b4 = pCStack_b4 + 1;
            this = pCStack_c4;
            pCVar12 = pCStack_c0;
          } while (pCStack_b4 < *(CMwNod **)(pCStack_c4 + 0x84));
        }
        pCStack_b0 = (CPlugTree *)((int)pCStack_b0 + 1);
      } while (pCStack_b0 < *(uint *)(this + 0x88));
    }
    *(uint *)(pCVar5 + 0x9c) = *(uint *)(pCVar5 + 0x9c) | 8;
    if (*(int *)(this + 0x70) != 0) {
      CSystemFidParameters::Pop(aCStack_30,(SCharStyle *)aCStack_30);
    }
    fVar1 = (float)*(int *)(this + 0x84);
    if (*(int *)(this + 0x84) < 0) {
      fVar1 = fVar1 + _DAT_00c418d0;
    }
    fVar3 = (float)*(int *)(this + 0x88);
    if (*(int *)(this + 0x88) < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    *(float *)(this + 0x8c) = fVar1 * fStack_bc;
    *(float *)(this + 0x90) = fVar3 * fStack_b8;
    iVar14 = (**(code **)(*(int *)this + 0x78))();
    if (iVar14 != 0) {
      BitmapOccAttach(this,(CSceneMobilClouds *)0x1,(int)pCVar15);
    }
    pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
    CSystemFidParameters::~CSystemFidParameters(aCStack_48,(CSystemFidParameters *)pCVar15);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&fStack_80,(CFastBuffer<class_CPlugFileGPUV*> *)this_03);
  }
  ExceptionList = pvStack_c;
  return;
}
}

// =================================================
// Function: CSceneMobilClouds::CSceneMobilClouds
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneMobilClouds::CSceneMobilClouds(CSceneMobilClouds *this,CSceneMobilClouds *param_1)
{
{
  undefined4 uVar1;
  CMwNod *extraout_EAX;
  CMwNod *unaff_EBX;
  CPlugGpuFxLocator *unaff_EBP;
  CMwNod *this_00;
  CSceneMobil *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  undefined1 uStack00000008;
  undefined1 uStack0000000c;
  void *local_c;
  undefined1 *puStack_8;
  CPlugGpuFxLocator *local_4;
  
  local_4 = (CPlugGpuFxLocator *)0xffffffff;
  puStack_8 = &LAB_00acddb5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSceneMobil::CSceneMobil
            ((CSceneMobil *)this,(CSceneMobil *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x48,unaff_EDI);
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  param_1 = (CSceneMobilClouds *)CONCAT31(param_1._1_3_,4);
  CSceneMobil::InstallRenderBeforeMechanism((CSceneMobil *)this,unaff_ESI);
  *(undefined4 *)(this + 0x84) = 4;
  *(undefined4 *)(this + 0x88) = 4;
  *(undefined4 *)(this + 0x58) = 0x3f800000;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 1;
  uVar1 = _DAT_00b9fd28;
  *(undefined4 *)(this + 0x68) = 1;
  *(undefined4 *)(this + 0x6c) = 1;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x74) = uVar1;
  *(undefined4 *)(this + 0x78) = uVar1;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x8c) = *(undefined4 *)(this + 0x74);
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(this + 0x78);
  local_4 = operator_new(0x30);
  uStack00000008 = 5;
  if (local_4 == (CPlugGpuFxLocator *)0x0) {
    this_00 = (CMwNod *)0x0;
  }
  else {
    CPlugGpuFxLocator::CPlugGpuFxLocator(local_4,unaff_EBP);
    this_00 = extraout_EAX;
  }
  uStack0000000c = 4;
  if (this_00 != *(CMwNod **)(this + 0x94)) {
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_00,unaff_EBX);
    }
    if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x94),unaff_EBX);
    }
    *(CMwNod **)(this + 0x94) = this_00;
  }
  CPlugGpuFxLocator::Reset(*(CPlugGpuFxLocator **)(this + 0x94),(GmFrustumIso4 *)"Opacity");
  *(undefined4 *)(this + 0x70) = 0;
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CSceneMobilClouds::Init
// =================================================
void __thiscall
CSceneMobilClouds::Init
          (CSceneMobilClouds *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
          CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  CPlugSolid *extraout_EAX;
  CPlugSolid *extraout_EAX_00;
  CPlugSolid *pCVar1;
  CPlugSolid *unaff_ESI;
  CMwNod *unaff_EDI;
  CPlugSolid *this_00;
  CSceneMobilClouds *pCVar2;
  CPlugSolid *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00acdca6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar2 = this;
  if (param_1 != *(CLoadGeomDynaSprite **)(this + 0x54)) {
    if (param_1 != (CLoadGeomDynaSprite *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
    }
    if (*(CMwNod **)(this + 0x54) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x54),unaff_EDI);
    }
    *(CLoadGeomDynaSprite **)(this + 0x54) = param_1;
  }
  local_c = operator_new(0x74);
  if (local_c == (CPlugSolid *)0x0) {
    this_00 = (CPlugSolid *)0x0;
  }
  else {
    CPlugSolid::CPlugSolid(local_c,(CPlugSolid *)unaff_EDI);
    this_00 = extraout_EAX;
  }
  local_c = operator_new(0xac);
  if (local_c == (CPlugSolid *)0x0) {
    pCVar1 = (CPlugSolid *)0x0;
  }
  else {
    CPlugTree::CPlugTree((CPlugTree *)local_c,(CPlugTree *)unaff_EDI);
    pCVar1 = extraout_EAX_00;
  }
  *(uint *)(pCVar1 + 0x9c) = *(uint *)(pCVar1 + 0x9c) & 0xffffff77;
  CPlugSolid::SetTree(this_00,pCVar1,(CPlugTree *)0x1,(int)unaff_EDI);
  CHmsItem::SetSolid(*(CHmsItem **)(this + 0x28),(CSceneToyMotorbike *)this_00,unaff_ESI);
  param_4 = (ESpriteColor0 *)
            (CONCAT22(param_4._2_2_,*(undefined2 *)(*(CHmsItem **)(this + 0x28) + 0x20)) | 1);
  CHmsItem::VisibleIdSet(*(CHmsItem **)(this + 0x28),(CHmsItem *)&param_4,(SPlugVisibleId *)pCVar2);
  ExceptionList = param_1;
  return;
}
}

