// Class implementation: CSceneMobilSnow

// =================================================
// Function: CSceneMobilSnow::CSceneMobilSnow
// =================================================
void __thiscall CSceneMobilSnow::CSceneMobilSnow(CSceneMobilSnow *this,CSceneMobilSnow *param_1)
{
{
  CSceneMobil *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  
  CSceneMobil::CSceneMobil((CSceneMobil *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x54,unaff_retaddr);
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x60) = 0x3f800000;
  *(undefined4 *)(this + 0x5c) = 6;
  *(undefined4 *)(this + 100) = 5;
  *(undefined4 *)(this + 0x6c) = 100;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  return;
}
}

// =================================================
// Function: CSceneMobilSnow::Init
// =================================================
void __thiscall
CSceneMobilSnow::Init
          (CSceneMobilSnow *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
          CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  CPlugVisualSprite *pCVar1;
  CPlugVisualSprite *pCVar2;
  CPlugVisualSprite *extraout_EAX;
  CPlugShader *this_00;
  SCasterCat *pSVar3;
  ulong uVar4;
  CPlugTree *this_01;
  GmVec3 *extraout_EAX_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CPlugVisualSprite *extraout_EAX_01;
  CPlugAudio *this_02;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  int unaff_EBX;
  uint uVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  ulong unaff_EBP;
  GxColor *unaff_ESI;
  SSpriteF *unaff_EDI;
  void *this_03;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  void *in_stack_00000020;
  void *in_stack_0000002c;
  void *in_stack_00000034;
  undefined4 in_stack_00000038;
  void *in_stack_0000003c;
  undefined4 in_stack_00000040;
  void *in_stack_00000044;
  void *in_stack_00000050;
  void *in_stack_00000058;
  void *in_stack_00000060;
  ulong uVar9;
  CPlugShaderPass *pCVar10;
  EGxBlendFactor EVar11;
  EGxBlendFactor in_stack_ffffffa4;
  ulong uVar12;
  CSceneMobilSnow *pCVar13;
  ulong in_stack_ffffffb8;
  GxColor *pGVar14;
  CPlugVisualSprite *in_stack_ffffffc0;
  CPlugShaderApply *in_stack_ffffffc4;
  CPlugVisualSprite *in_stack_ffffffc8;
  GmVec3 *in_stack_ffffffcc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffd0;
  CPlugTree *in_stack_ffffffd4;
  GmVec3 *in_stack_ffffffd8;
  void *in_stack_ffffffdc;
  ulong in_stack_ffffffe4;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  CPlugVisualSprite *pCStack_8;
  GmVec3 *local_4;
  
  local_4 = (GmVec3 *)0xffffffff;
  pCStack_8 = (CPlugVisualSprite *)&LAB_00acde81;
  local_c = ExceptionList;
  pCVar1 = (CPlugVisualSprite *)(DAT_00cca150 ^ (uint)&stack0xffffff94);
  ExceptionList = &local_c;
  *(CLoadGeomDynaSprite **)(this + 0x5c) = param_1;
  uVar4 = *(ulong *)(&DAT_00d07340 + (int)param_1 * 0x18);
  uVar12 = *(ulong *)(&DAT_00d07344 + (int)param_1 * 0x18);
  pCVar13 = this;
  pCVar2 = operator_new(0xc0);
  local_4 = (GmVec3 *)0x0;
  if (pCVar2 == (CPlugVisualSprite *)0x0) {
    pCVar1 = (CPlugVisualSprite *)0x0;
  }
  else {
    CPlugVisualSprite::CPlugVisualSprite(pCVar2,pCVar1);
    pCVar1 = extraout_EAX;
  }
  pCVar6 = (CFastBuffer<class_CCrystalFace*> *)
           ((uint)(param_1 == (CLoadGeomDynaSprite *)0x1) << 5 | 1);
  uVar7 = *(uint *)(pCVar1 + 0x1c);
  if ((uVar7 & 8) != 0) {
    *(uint *)(pCVar1 + 0x1c) = uVar7 & 0xfffffff7;
    if (((uVar7 & 0x400) == 0) &&
       (*(uint *)(pCVar1 + 0x1c) = uVar7 & 0xfffffff7 | 0x400, DAT_00d6eb04 != (undefined4 *)0x0)) {
      (**(code **)*DAT_00d6eb04)(pCVar1);
    }
  }
  CPlugVisualSprite::SetSpriteFlags(pCVar1,(CPlugVisualSprite *)&stack0xffffffbc,unaff_EDI);
  uVar9 = 0;
  CSceneMobil::SetVisual((CSceneMobil *)this,(CVisionVisualKeeper *)pCVar1,(CPlugVisual *)0x0);
  this_00 = CPlugTree::ChangeShaderClass
                      (*(CPlugTree **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 100),
                       (CPlugTree *)0x9026000,uVar9);
  CPlugShaderGeneric::SetVertexColor
            ((CPlugShaderGeneric *)this_00,(CPlugShaderGeneric *)0x1,0,unaff_ESI);
  CPlugShader::SetReceiverShadowGroupMask(this_00,(CPlugShader *)0x0,unaff_EBP);
  CHmsItem::SetIsForcePointDynamicCollisionResponse((CHmsItem *)this_00,(CHmsItem *)0x0,unaff_EBX);
  if (param_1 == (CLoadGeomDynaSprite *)0x3) {
    EVar11 = 1;
    pCVar10 = (CPlugShaderPass *)0x1;
  }
  else {
    EVar11 = 5;
    pCVar10 = (CPlugShaderPass *)&DAT_00000004;
  }
  CPlugShaderApply::SetBlending((CPlugShaderApply *)this_00,pCVar10,EVar11,in_stack_ffffffa4);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (in_stack_00000020,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar12
                     );
  CPlugShaderApply::AddTextureApply
            ((CPlugShaderApply *)this_00,*(CPlugShaderApply **)pSVar3,(CPlugBitmap *)0x1,0,uVar4);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (in_stack_0000002c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      (ulong)pCVar2);
  pCVar2 = *(CPlugVisualSprite **)pSVar3;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            (pCVar1 + 0x78,(GmFrustumIso4 *)pCVar13);
  uVar7 = 0;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (in_stack_00000034,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_ffffffb8);
  if (*(int *)pSVar3 != 0) {
    do {
      param_1 = (CLoadGeomDynaSprite *)0x3f800000;
      uStack_18 = 0;
      uStack_14 = 0;
      uStack_10 = 0;
      CPlugVisualSprite::AddSprite
                (pCVar1,(CPlugVisualSprite *)&uStack_18,in_stack_ffffffd8,(float)&stack0x00000000,
                 (GxColor *)0x0,(float)in_stack_ffffffd4,0.0,(ulong)pCVar6);
      pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x0;
      uVar7 = uVar7 + 1;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (in_stack_0000003c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)in_stack_ffffffc0);
    } while (uVar7 < *(uint *)pSVar3);
  }
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(in_stack_00000034,pCVar6);
  if (1 < uVar4) {
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
    do {
      this_01 = operator_new(0xac);
      pCVar1 = (CPlugVisualSprite *)0x0;
      in_stack_0000002c = (void *)0x1;
      if (this_01 == (CPlugTree *)0x0) {
        in_stack_ffffffd4 = (CPlugTree *)0x0;
      }
      else {
        CPlugTree::CPlugTree(this_01,(CPlugTree *)in_stack_ffffffc0);
        in_stack_ffffffd8 = extraout_EAX_00;
      }
      in_stack_0000002c = (void *)0xffffffff;
      pCVar5 = operator_new(0xc0);
      in_stack_0000002c = (void *)0x2;
      if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        CPlugVisualSprite::CPlugVisualSprite((CPlugVisualSprite *)pCVar5,in_stack_ffffffc0);
        pCVar1 = extraout_EAX_01;
      }
      uVar7 = *(uint *)(pCVar1 + 0x1c);
      in_stack_0000002c = (void *)0xffffffff;
      if ((uVar7 & 8) != 0) {
        *(uint *)(pCVar1 + 0x1c) = uVar7 & 0xfffffff7;
        if (((uVar7 & 0x400) == 0) &&
           (*(uint *)(pCVar1 + 0x1c) = uVar7 & 0xfffffff7 | 0x400, DAT_00d6eb04 != (undefined4 *)0x0
           )) {
          (**(code **)*DAT_00d6eb04)();
        }
      }
      CPlugVisualSprite::SetRenderMode(pCVar1,(CPlugVisualIndexedLines *)0x1,0);
      pGVar14 = (GxColor *)0x0;
      uVar4 = 0;
      CPlugTree::SetVisual(in_stack_ffffffd4,(CVisionVisualKeeper *)pCVar1,(CPlugVisual *)0x0);
      CPlugTree::ChangeShaderClass((CPlugTree *)in_stack_ffffffcc,(CPlugTree *)0x9026000,uVar4);
      CPlugShaderGeneric::SetVertexColor
                ((CPlugShaderGeneric *)this_00,(CPlugShaderGeneric *)0x1,0,pGVar14);
      CPlugShader::SetReceiverShadowGroupMask(this_00,(CPlugShader *)0x0,(ulong)in_stack_ffffffc0);
      CHmsItem::SetIsForcePointDynamicCollisionResponse
                ((CHmsItem *)this_00,(CHmsItem *)0x0,(int)in_stack_ffffffc4);
      if (in_stack_0000003c == (void *)0x3) {
        EVar11 = 1;
        pCVar10 = (CPlugShaderPass *)0x1;
      }
      else {
        EVar11 = 5;
        pCVar10 = (CPlugShaderPass *)&DAT_00000004;
      }
      pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x7d55c7;
      CPlugShaderApply::SetBlending
                ((CPlugShaderApply *)this_00,pCVar10,EVar11,(EGxBlendFactor)in_stack_ffffffc8);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (in_stack_00000044,pCVar8,(ulong)in_stack_ffffffcc);
      in_stack_ffffffc4 = *(CPlugShaderApply **)pSVar3;
      in_stack_ffffffc8 = (CPlugVisualSprite *)0x1;
      in_stack_ffffffc0 = (CPlugVisualSprite *)0x7d55df;
      CPlugShaderApply::AddTextureApply
                ((CPlugShaderApply *)this_00,in_stack_ffffffc4,(CPlugBitmap *)0x1,0,
                 (ulong)in_stack_ffffffd0);
      in_stack_ffffffcc = (GmVec3 *)0x7d55e9;
      in_stack_ffffffd0 = pCVar8;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (in_stack_00000050,pCVar8,(ulong)in_stack_ffffffd4);
      pCStack_8 = pCVar2 + *(int *)pSVar3;
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                (pCVar1 + 0x78,(GmFrustumIso4 *)in_stack_ffffffd8);
      uVar7 = 0;
      in_stack_ffffffd4 = (CPlugTree *)0x7d5603;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (in_stack_00000058,pCVar8,(ulong)in_stack_ffffffdc);
      pCVar2 = (CPlugVisualSprite *)pCVar5;
      if (*(int *)pSVar3 != 0) {
        do {
          in_stack_00000034 = (void *)0x3f800000;
          in_stack_ffffffd0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&stack0x00000034;
          in_stack_00000038 = 0;
          in_stack_ffffffc8 = (CPlugVisualSprite *)&stack0x00000018;
          in_stack_0000003c = (void *)0x0;
          in_stack_00000018 = 0;
          in_stack_0000001c = 0;
          in_stack_00000020 = (void *)0x0;
          in_stack_00000040 = 0x3f800000;
          in_stack_ffffffd4 = (CPlugTree *)0x0;
          in_stack_ffffffc4 = (CPlugShaderApply *)0x7d5652;
          in_stack_ffffffcc = local_4;
          CPlugVisualSprite::AddSprite
                    (pCVar1,in_stack_ffffffc8,local_4,(float)in_stack_ffffffd0,(GxColor *)0x0,
                     (float)pCStack_8,0.0,(ulong)pCVar5);
          uVar7 = uVar7 + 1;
          pCVar5 = pCVar8;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (in_stack_00000060,pCVar8,in_stack_ffffffe4);
          pCVar2 = (CPlugVisualSprite *)pCVar5;
        } while (uVar7 < *(uint *)pSVar3);
      }
      in_stack_ffffffd8 = (GmVec3 *)0x7d567f;
      in_stack_ffffffdc = local_c;
      (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0x28) + 0x14) + 100) + 0x88))();
      pCVar8 = pCVar8 + 1;
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(in_stack_00000034,pCVar6);
    } while (pCVar8 < pCVar5);
  }
  this_03 = (void *)(in_stack_ffffffe4 + 0x54);
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
            (this_03,(CFastBuffer<class_CSystemFidsFolder*> *)pCVar2,(ulong)in_stack_ffffffc0);
  this_02 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_02 == (CPlugAudio *)0x0) {
    this_02 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  CPlugAudio::MwGetId(this_02,(CPlugAudio *)in_stack_ffffffc4);
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CPlugVisualSprite *)0x0) {
    local_c = (void *)0x0;
    pCStack_8 = (CPlugVisualSprite *)0x0;
    local_4 = (GmVec3 *)0x0;
    do {
      pSVar3 = CFastBuffer<class_GxColor>::operator[](this_03,pCVar8,(ulong)in_stack_ffffffc8);
      *(CPlugVisualSprite **)(pSVar3 + 4) = pCStack_8;
      *(GmVec3 **)(pSVar3 + 8) = local_4;
      *(undefined4 *)(pSVar3 + 0xc) = 0;
      in_stack_ffffffc8 = (CPlugVisualSprite *)pCVar8;
      pSVar3 = CFastBuffer<class_GxColor>::operator[](this_03,pCVar8,(ulong)in_stack_ffffffcc);
      pCVar8 = pCVar8 + 1;
      *(undefined4 *)pSVar3 = 0;
    } while (pCVar8 < pCVar2);
  }
  ExceptionList = in_stack_0000002c;
  return;
}
}

