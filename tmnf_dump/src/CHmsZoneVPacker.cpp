// Class implementation: CHmsZoneVPacker

// =================================================
// Function: CHmsZoneVPacker::AddInteractLights
// =================================================
void __thiscall
CHmsZoneVPacker::AddInteractLights
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,
          CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc> *param_2,
          CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc> *param_3,CHmsVPackerCell *param_4,
          SFlags *param_5,ERadius param_6)
{
{
  CHmsZoneVPacker *unaff_retaddr;
  
  *(CHmsZoneVPacker **)(this + 0x188) = param_1;
  *(undefined4 *)(this + 400) = 0;
  *(undefined4 *)(this + 0x194) = 0;
  *(CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc> **)(this + 0x18c) = param_2;
  *(CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc> **)(this + 0x198) = param_3;
  *(CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc> **)(this + 0x19c) = param_3;
  *(CHmsVPackerCell **)(this + 0x1a0) = param_4;
  *(SFlags **)(this + 0x1a4) = param_5;
  AddInteractLightsInternal(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::AddInteractLightsInternal
// =================================================
void __thiscall
CHmsZoneVPacker::AddInteractLightsInternal(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1)
{
{
  CHmsZoneVPacker *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CHmsVPackerCell *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  CHmsVPackerCell *unaff_retaddr;
  
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 100,unaff_ESI);
  if ((CHmsZoneVPacker *)0x1 < *(CHmsZoneVPacker **)(this + 0x60)) {
    AddInteractLightsWithCell(this,*(CHmsZoneVPacker **)(this + 0x60),unaff_EBP);
  }
  if (uVar2 != 0) {
    pSVar3 = CFastArray<class_CHmsVPackerLevel>::operator[]
                       (this + 100,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 - 1),
                        unaff_EDI);
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x58,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar3,
                        unaff_EBX);
    pCVar1 = *(CHmsZoneVPacker **)pSVar3;
    if (((CHmsZoneVPacker *)0x1 < pCVar1) && (0.0 <= *(float *)(pCVar1 + 0x80))) {
      AddInteractLightsWithCell(this,pCVar1,unaff_retaddr);
    }
    if (1 < uVar2) {
      AddInteractLightsRecur(this,(CHmsZoneVPacker *)(uVar2 - 1),0,0,0,(ulong)param_1);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::AddInteractLightsRecur
// =================================================
void __thiscall
CHmsZoneVPacker::AddInteractLightsRecur
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,ulong param_2,ulong param_3,ulong param_4,
          ulong param_5)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  GmBoxAligned *pGVar6;
  SCasterCat *pSVar7;
  uint uVar8;
  uint uVar9;
  SCasterCat *pSVar10;
  int iVar11;
  int iVar12;
  CHmsZoneVPacker *unaff_EBX;
  GmBoxAligned *unaff_EBP;
  CPlugVolumeProjector *unaff_ESI;
  ulong unaff_EDI;
  uint in_stack_00000018;
  CHmsVPackerCell *in_stack_0000001c;
  CHmsZoneVPacker *in_stack_00000020;
  CHmsZoneVPacker *pCVar13;
  CHmsVPackerCell *in_stack_ffffffe4;
  CHmsZoneVPacker *local_8;
  
  pSVar7 = CFastArray<class_CHmsVPackerLevel>::operator[]
                     (this + 100,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_1 + -1),
                      unaff_EDI);
  uVar1 = *(undefined4 *)(pSVar7 + 0x14);
  uVar2 = *(undefined4 *)(pSVar7 + 0x18);
  uVar3 = *(undefined4 *)(pSVar7 + 0x1c);
  uVar8 = param_4 << ((byte)uVar2 & 0x1f);
  uVar9 = param_5 << ((byte)uVar3 & 0x1f);
  iVar12 = *(int *)(pSVar7 + 0x10) * uVar9 + *(int *)(pSVar7 + 4) * uVar8 + *(int *)pSVar7;
  do {
    uVar4 = uVar8;
    iVar5 = iVar12;
    if (param_5 + 1 << ((byte)uVar3 & 0x1f) <= uVar9) {
      return;
    }
    for (; pGVar6 = (GmBoxAligned *)(param_3 << ((byte)uVar1 & 0x1f)),
        uVar4 < param_4 + 1 << ((byte)uVar2 & 0x1f); uVar4 = uVar4 + 1) {
      for (; pGVar6 < (GmBoxAligned *)(param_3 + 1 << ((byte)uVar1 & 0x1f)); pGVar6 = pGVar6 + 1) {
        pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (local_8 + 0x58,
                             (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pGVar6 + iVar5),
                             (ulong)unaff_ESI);
        pCVar13 = *(CHmsZoneVPacker **)pSVar10;
        if (pCVar13 != (CHmsZoneVPacker *)0x0) {
          if ((CHmsZoneVPacker *)0x1 < pCVar13) {
            if (0.0 <= *(float *)(pCVar13 + 0x80)) {
              unaff_ESI = *(CPlugVolumeProjector **)(local_8 + 0x198);
              iVar11 = GmBoxAligned::TestInter
                                 (pCVar13 + 0x74,unaff_ESI,unaff_EBP,(GmIso4 *)unaff_EBX);
              if (iVar11 == 0) goto LAB_0055e414;
            }
            unaff_EBP = (GmBoxAligned *)0x55e3f5;
            AddInteractLightsWithCell(local_8,pCVar13,in_stack_ffffffe4);
            unaff_EBX = pCVar13;
          }
          if (1 < in_stack_00000018) {
            unaff_ESI = (CPlugVolumeProjector *)(in_stack_00000018 - 1);
            unaff_EBP = pGVar6;
            unaff_EBX = in_stack_00000020;
            in_stack_ffffffe4 = in_stack_0000001c;
            AddInteractLightsRecur
                      (local_8,(CHmsZoneVPacker *)unaff_ESI,(ulong)pGVar6,(ulong)in_stack_00000020,
                       (ulong)in_stack_0000001c,uVar8);
          }
        }
LAB_0055e414:
      }
      iVar5 = iVar5 + *(int *)(pSVar7 + 4);
    }
    iVar12 = iVar12 + *(int *)(pSVar7 + 0x10);
    uVar9 = uVar9 + 1;
  } while( true );
}
}

// =================================================
// Function: CHmsZoneVPacker::AddInteractLightsWithCell
// =================================================
void __thiscall
CHmsZoneVPacker::AddInteractLightsWithCell
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsVPackerCell *param_2)
{
{
  SCasterCat *pSVar1;
  int iVar2;
  GmIso4 *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CPlugVolumeProjector *unaff_EBP;
  CPlugVolumeProjector *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  GmIso4 *in_stack_ffffffe0;
  TiXmlAttribute *in_stack_ffffffe4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_18;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_4;
  
  local_18 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x5c,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (local_18 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (param_1 + 0x5c,pCVar3,(ulong)unaff_ESI);
      if ((*(uint *)(*(int *)(pSVar1 + 4) + 0x14) & **(uint **)(this + 0x1a0)) ==
          **(uint **)(this + 0x1a0)) {
        local_18 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                    (*(int *)(pSVar1 + 4) + 0x68 + *(int *)(this + 0x1a4) * 4);
        unaff_ESI = (CPlugVolumeProjector *)&local_10;
        local_10 = *(undefined4 *)(pSVar1 + 8);
        local_c = *(undefined4 *)(pSVar1 + 0xc);
        local_8 = *(undefined4 *)(pSVar1 + 0x10);
        local_4 = local_18;
        iVar2 = GmBoxAligned::TestInter
                          (*(void **)(this + 0x198),unaff_ESI,(GmBoxAligned *)unaff_EBP,unaff_EBX);
        if (iVar2 != 0) {
          if (*(void **)(this + 0x188) == (void *)0x0) {
            unaff_EBP = (CPlugVolumeProjector *)0x55e217;
            CFastBuffer<class_CDx9TextureKeeper*>::Add
                      (*(void **)(this + 400),(TiXmlAttributeSet *)pSVar1,
                       (TiXmlAttribute *)in_stack_ffffffe0);
            unaff_EBX = (GmIso4 *)pSVar1;
          }
          else {
            unaff_EBP = (CPlugVolumeProjector *)0x55e20a;
            CFastBuffer<struct_CPlugFont::SCharStyle::SStyle>::Add
                      (*(void **)(this + 0x188),(TiXmlAttributeSet *)pSVar1,
                       (TiXmlAttribute *)in_stack_ffffffe0);
            unaff_EBX = (GmIso4 *)pSVar1;
          }
        }
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < local_18);
  }
  if ((*(int *)(this + 0x18c) != 0) || (*(int *)(this + 0x194) != 0)) {
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (param_2 + 0x68,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar1 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                           (param_2 + 0x68,pCVar4,(ulong)unaff_EBP);
        if ((*(uint *)(*(int *)(pSVar1 + 4) + 0x14) & **(uint **)(this + 0x1a0)) ==
            **(uint **)(this + 0x1a0)) {
          unaff_EBP = (CPlugVolumeProjector *)&local_c;
          local_c = *(undefined4 *)(pSVar1 + 8);
          local_8 = *(undefined4 *)(pSVar1 + 0xc);
          local_4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar1 + 0x10);
          iVar2 = GmBoxAligned::TestInter
                            (*(void **)(this + 0x198),unaff_EBP,(GmBoxAligned *)unaff_EBX,
                             in_stack_ffffffe0);
          if (iVar2 != 0) {
            if (*(void **)(this + 0x18c) == (void *)0x0) {
              unaff_EBX = (GmIso4 *)0x55e2d8;
              CFastBuffer<class_CDx9TextureKeeper*>::Add
                        (*(void **)(this + 0x194),(TiXmlAttributeSet *)pSVar1,in_stack_ffffffe4);
              in_stack_ffffffe0 = (GmIso4 *)pSVar1;
            }
            else {
              unaff_EBX = (GmIso4 *)0x55e2cb;
              CFastBuffer<class_GmReal4_64>::Add
                        (*(void **)(this + 0x18c),(TiXmlAttributeSet *)pSVar1,in_stack_ffffffe4);
              in_stack_ffffffe0 = (GmIso4 *)pSVar1;
            }
          }
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar3);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::AddNewLight
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CHmsZoneVPacker::AddNewLight
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsCorpusLight *param_2)
{
{
  GmBoxAligned *pGVar1;
  CHmsZoneVPacker *pCVar2;
  uint uVar3;
  undefined4 uVar4;
  CHmsZoneVPacker *pCVar5;
  void *pvVar6;
  ERadius EVar7;
  int iVar8;
  CHmsVPackerCell **ppCVar9;
  CHmsVPackerCell *extraout_EAX;
  CHmsVPackerCell *pCVar10;
  SLoadedLight *pSVar11;
  void *pvVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  SCasterCat *pSVar14;
  SCasterCat *pSVar15;
  STravelParent *unaff_EBX;
  GmBoxAligned *unaff_EBP;
  uint uVar16;
  CHmsVPackerCell *unaff_ESI;
  GmRectAligned *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar17;
  undefined4 in_stack_00000014;
  GmMat3 *in_stack_ffffff8c;
  ulong in_stack_ffffff90;
  GmVec3 *in_stack_ffffff94;
  GmVec2 *pGVar18;
  SUserData *pSVar19;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar20;
  CFastBuffer<class_CCrystalFace*> *pCVar21;
  GmBoxAligned *pGVar22;
  GmVec2 *pGVar23;
  CHmsZoneVPacker *local_44;
  void *pvStack_40;
  int iStack_3c;
  void *pvStack_38;
  SCasterCat *pSStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  int iStack_24;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
  aGStack_20 [8];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  pCVar5 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a977ab;
  local_c = ExceptionList;
  EVar7 = DAT_00cca150 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_c;
  pCVar2 = *(CHmsZoneVPacker **)(*(int *)(param_1 + 0x48) + 0x88);
  local_44 = this;
  iVar8 = (**(code **)(*(int *)pCVar2 + 0x78))();
  if ((iVar8 == 3) || (iVar8 == 5)) {
    pGVar18 = (GmVec2 *)0x55e4d8;
    iVar8 = CHmsCorpusLight::ComputeBBoxInWorld
                      ((CHmsCorpusLight *)param_1,(CHmsCorpusLight *)&iStack_24,
                       (GmBoxAligned *)&DAT_00000004,EVar7);
    if (iVar8 != 0) {
      pGVar1 = (GmBoxAligned *)(param_1 + 0x60);
      pGVar20 = aGStack_20;
      pSVar19 = (SUserData *)0x55e4ec;
      pGVar22 = pGVar1;
      ppCVar9 = GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                ::GetContainingCell((GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                     *)this,pGVar20,pGVar1,(SUserData *)unaff_EDI);
      if (((byte)*pGVar1 & 0x1f) != 0) {
        param_1 = pCVar2;
        if (*ppCVar9 < (CHmsVPackerCell *)0x2) {
          unaff_EDI = (GmRectAligned *)&DAT_0000008c;
          pGVar22 = (GmBoxAligned *)0x55e507;
          pvStack_38 = operator_new(0x8c);
          param_1 = (CHmsZoneVPacker *)0x0;
          if (pvStack_38 == (void *)0x0) {
            pCVar10 = (CHmsVPackerCell *)0x0;
          }
          else {
            unaff_EDI = (GmRectAligned *)0x55e521;
            CHmsVPackerCell::CHmsVPackerCell(pvStack_38,unaff_ESI);
            pCVar10 = extraout_EAX;
          }
          *ppCVar9 = pCVar10;
          *(undefined4 *)(pCVar10 + 8) = 0;
          *(undefined4 *)(pCVar10 + 4) = 0;
          *(undefined4 *)pCVar10 = 0;
          uVar4 = _DAT_00b2c060;
          *(undefined4 *)(pCVar10 + 0xc) = _DAT_00b2c060;
          *(undefined4 *)(pCVar10 + 0x10) = uVar4;
          *(undefined4 *)(pCVar10 + 0x14) = uVar4;
          pCVar10 = *ppCVar9;
          *(undefined4 *)(pCVar10 + 0x74) = uStack_18;
          *(undefined4 *)(pCVar10 + 0x78) = uStack_14;
          *(undefined4 *)(pCVar10 + 0x7c) = uStack_10;
          *(void **)(pCVar10 + 0x80) = local_c;
          *(undefined1 **)(pCVar10 + 0x84) = puStack_8;
          *(undefined4 *)(pCVar10 + 0x88) = uStack_4;
          if (2 < ((byte)*(undefined4 *)pGVar1 & 0x1f)) {
            pCVar10 = *(CHmsVPackerCell **)pGVar1;
            pGVar22 = (GmBoxAligned *)0x55e592;
            (**(code **)(*(int *)this + 0xc))();
            unaff_EDI = (GmRectAligned *)0x55e599;
            CHmsVPackerCell::BBoxHasChanged(*ppCVar9,pCVar10);
          }
        }
        if (((byte)*(undefined4 *)(this + 0xf8) & 3) != 1) {
          unaff_EDI = (GmRectAligned *)0x55e5b3;
          LightBBoxSetDirtyCV(this,(CHmsZoneVPacker *)&uStack_18,unaff_EBP);
        }
        if (iStack_3c == 3) {
          pGVar23 = (GmVec2 *)0x55e5c4;
          pSVar11 = CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc>::AddNewElem
                              (*ppCVar9 + 0x5c,
                               (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_EBP);
          *(undefined4 *)(pSVar11 + 4) = in_stack_00000014;
          *(CHmsZoneVPacker **)pSVar11 = pCVar5;
          iVar8 = (**(code **)(*(int *)pCVar5 + 0x78))();
          *(undefined4 *)(pSVar11 + 8) = *(undefined4 *)(iVar8 + 0x24);
          *(undefined4 *)(pSVar11 + 0xc) = *(undefined4 *)(iVar8 + 0x28);
          *(undefined4 *)(pSVar11 + 0x10) = *(undefined4 *)(iVar8 + 0x2c);
        }
        else {
          pSVar11 = CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                              (*ppCVar9 + 0x68,
                               (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_EBP);
          *(undefined4 *)(pSVar11 + 4) = in_stack_00000014;
          *(CHmsZoneVPacker **)pSVar11 = pCVar5;
          iVar8 = (**(code **)(*(int *)pCVar5 + 0x78))();
          *(undefined4 *)(pSVar11 + 8) = *(undefined4 *)(iVar8 + 0x24);
          *(undefined4 *)(pSVar11 + 0xc) = *(undefined4 *)(iVar8 + 0x28);
          *(undefined4 *)(pSVar11 + 0x10) = *(undefined4 *)(iVar8 + 0x2c);
          pGVar23 = (GmVec2 *)0x2;
          unaff_EDI = (GmRectAligned *)0x55e631;
          pvVar12 = (void *)(**(code **)(*(int *)pCVar5 + 0x78))();
          GmMat3::GetLine(pvVar12,in_stack_ffffff8c,in_stack_ffffff90,in_stack_ffffff94);
          *(float *)(pSVar11 + 0x14) = -*(float *)(pSVar11 + 0x14);
          *(float *)(pSVar11 + 0x18) = -*(float *)(pSVar11 + 0x18);
          *(float *)(pSVar11 + 0x1c) = -*(float *)(pSVar11 + 0x1c);
        }
        GmBoxAligned::Union(*ppCVar9 + 0x74,(GmRectAligned *)&uStack_30,pGVar18);
        GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
        STravelParent::STravelParent
                  (&local_44,unaff_EBX,
                   (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                    *)pGVar1,pSVar19);
        pvVar6 = pvStack_40;
        pvVar12 = (void *)((int)pvStack_40 + 100);
        pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iStack_3c + 1);
        pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  CFastBuffer<class_CCrystalFace*>::GetCount
                            (pvVar12,(CFastBuffer<class_CCrystalFace*> *)pGVar20);
        if (pCVar17 < pCVar13) {
          local_44 = (CHmsZoneVPacker *)((int)pvVar6 + 0x58);
          uVar16 = uStack_30;
          pSVar14 = pSStack_34;
          do {
            uVar16 = uVar16 >> ((byte)*(undefined4 *)(pSVar14 + 0x14) & 0x1f);
            uStack_2c = uStack_2c >> ((byte)*(undefined4 *)(pSVar14 + 0x18) & 0x1f);
            uStack_28 = uStack_28 >> ((byte)*(undefined4 *)(pSVar14 + 0x1c) & 0x1f);
            pSVar14 = CFastArray<class_CHmsVPackerLevel>::operator[](param_1,pCVar17,(ulong)pGVar22)
            ;
            pGVar22 = (GmBoxAligned *)
                      (*(int *)(pSVar14 + 0x10) * iStack_24 + *(int *)(pSVar14 + 4) * uStack_28 +
                       *(int *)pSVar14 + uVar16);
            pCVar21 = (CFastBuffer<class_CCrystalFace*> *)0x55e6df;
            pSVar15 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                (pvStack_40,
                                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar22,
                                 (ulong)unaff_EDI);
            uVar3 = *(uint *)pSVar15;
            if (uVar3 < 2) {
              if (uVar3 == 0) {
                *(undefined4 *)pSVar15 = 1;
              }
            }
            else {
              unaff_EDI = (GmRectAligned *)(*ppCVar9 + 0x74);
              pGVar22 = (GmBoxAligned *)0x55e6f4;
              GmBoxAligned::Union((void *)(uVar3 + 0x74),unaff_EDI,pGVar23);
            }
            pCVar17 = pCVar17 + 1;
            pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      CFastBuffer<class_CCrystalFace*>::GetCount(pvVar12,pCVar21);
          } while (pCVar17 < pCVar13);
        }
        ExceptionList = local_c;
        return 1;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}
}

// =================================================
// Function: CHmsZoneVPacker::AddNewSolid
// =================================================
void __thiscall
CHmsZoneVPacker::AddNewSolid(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsCorpus *param_2)
{
{
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this_00;
  ushort uVar1;
  int *piVar2;
  CHmsPackLightMap *this_01;
  undefined4 *puVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  CHmsZoneVPacker *pCVar8;
  void *this_02;
  CHmsVPackerCell *extraout_EAX;
  CHmsVPackerCell *pCVar9;
  int iVar10;
  CHmsItem *this_03;
  SUserData *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  GmFrustumIso4 *in_stack_ffffff84;
  ulong in_stack_ffffff88;
  CPlugTree *pCVar12;
  ulong uVar13;
  SUserData *pSVar14;
  CIteratorTree *pCVar15;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  ulong uVar17;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar18;
  CHmsCorpus *pCVar19;
  GmBoxAligned *pGVar20;
  CHmsVPackerCell *pCVar21;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar22;
  CHmsItem *pCStack_54;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_50;
  CHmsItem *local_4c;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *local_48 [2]
  ;
  undefined1 local_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  CPlugTree local_28 [4];
  undefined1 auStack_24 [12];
  undefined1 local_18 [4];
  CHmsZoneVPacker *pCStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *local_8;
  GmBoxAligned *pGStack_4;
  
  pGStack_4 = (GmBoxAligned *)0xffffffff;
  local_8 = &LAB_00a97170;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_03 = *(CHmsItem **)(param_1 + 0x48);
  piVar2 = *(int **)(this_03 + 0x24);
  local_4c = this_03;
  if ((piVar2 == (int *)0x0) || ((piVar2[1] == 0 && ((piVar2 == (int *)0x0 || (*piVar2 == 0)))))) {
    local_48[0] = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                   *)CONCAT22(local_48[0]._2_2_,*(ushort *)(this_03 + 0x20));
    uVar1 = *(ushort *)(this + 0x9c);
    if ((uVar1 == 0) ||
       ((*(ushort *)(this + 0x9e) & uVar1) == (uVar1 & *(ushort *)(this_03 + 0x20)))) {
      pCVar15 = *(CIteratorTree **)(*(int *)(this_03 + 0x14) + 100);
      uVar17 = 0;
      uVar13 = 0x5591a6;
      CPlugTree::CIteratorTree::CIteratorTree
                (local_40,pCVar15,(CPlugTree *)0x0,
                 (EMode)((uint)DAT_00cca150 ^ (uint)&stack0xffffff9c));
      pCVar19 = (CHmsCorpus *)0x5591b7;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(local_28,unaff_EDI);
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(local_18,unaff_ESI);
      puVar3 = (undefined4 *)(**(code **)(*(int *)param_1 + 0x78))();
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&DAT_00d6790c,in_stack_ffffff84);
      CFastBuffer<struct_CHmsZoneVPacker::SStackLocation>::SetSizeAtLeast
                (auStack_30,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x1,in_stack_ffffff88);
      CFastBuffer<class_CSystemFidsFolder*>::SetCount
                (auStack_2c,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,uVar13);
      pSVar4 = CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid>::operator[]
                         (local_28,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)pCVar15);
      for (iVar10 = 0xc; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined4 *)pSVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        pSVar4 = pSVar4 + 4;
      }
      pSVar4 = CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid>::operator[]
                         (auStack_24,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar17);
      *(undefined4 *)(pSVar4 + 0x30) = 0xffffffff;
      this_01 = *(CHmsPackLightMap **)(this + 0xf0);
      uStack_10 = (uint)(this_01 == (CHmsPackLightMap *)0x0);
      pCStack_14 = param_1;
      if (this_01 != (CHmsPackLightMap *)0x0) {
        local_c = (void *)CHmsPackLightMap::BlockSkipLightMap
                                    (this_01,(CHmsPackLightMap *)param_1,pCVar19);
      }
      pSVar4 = *(SCasterCat **)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 100);
      pGVar20 = (GmBoxAligned *)0x0;
      pGVar18 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 *)0xffffffff;
      pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pCVar12 = local_28;
      AddTree(pCVar12);
      pCVar21 = (CHmsVPackerCell *)0x0;
      pGVar22 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 *)0x0;
      pCStack_50 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount
                             (auStack_3c,(CFastBuffer<class_CCrystalFace*> *)pCVar12);
      pCStack_54 = (CHmsItem *)0x0;
      if (pCStack_50 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar5 = CFastBuffer<struct_CControlDisplayGraph::SGraph>::operator[]
                             (auStack_38,
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_54,
                              (ulong)pSVar4);
          if (*(int *)(*(int *)(pSVar5 + 0x58) + 0x4c) == DAT_00d6e638) {
            if (*(int *)(pSVar5 + 0x60) == 0) {
              pSVar4 = (SCasterCat *)0x0;
              (**(code **)(*(int *)this + 4))(pSVar5);
            }
            else {
              pSVar4 = (SCasterCat *)0x5592ae;
              pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       CFastBuffer<class_CCrystalFace*>::GetCount
                                 (&DAT_00d6790c,(CFastBuffer<class_CCrystalFace*> *)0x5592ae);
              pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
                do {
                  pSVar4 = (SCasterCat *)0x5592cb;
                  pCVar16 = pCVar11;
                  pSVar7 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                                     (&DAT_00d6790c,pCVar11,(ulong)pGVar18);
                  if (*(int *)pSVar7 == *(int *)(pSVar5 + 0x60)) {
                    pGVar18 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                               *)(pSVar7 + 4);
                    pSVar4 = (SCasterCat *)0x5592ea;
                    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pSVar5;
                    (**(code **)(*(int *)this + 4))();
                    break;
                  }
                  pCVar11 = pCVar11 + 1;
                } while (pCVar11 < pCVar6);
              }
              this_03 = (CHmsItem *)pCStack_50;
              if (pCVar11 == pCVar6) {
                pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
                pSVar4 = pSVar5;
                (**(code **)(*(int *)this + 4))();
                this_03 = (CHmsItem *)pCStack_50;
              }
            }
            if (((byte)*(undefined4 *)(*(int *)(pSVar5 + 0x58) + 0x4c) & 0x1f) < 2) {
              unaff_EBP = unaff_EBP + 1;
            }
            else {
              pGVar22 = pGVar22 + 1;
            }
          }
          pCStack_54 = pCStack_54 + 1;
        } while (pCStack_54 < pCStack_50);
        if (((pCStack_50 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) &&
            (ShadowCasterStateAdd((EShadowCaster *)(this + 0x74),this_03),
            pGVar22 !=
            (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *)
            0x0)) && (unaff_EBP == (SUserData *)0x0)) {
          ShadowCasterStateAdd((EShadowCaster *)(this + 0x78),this_03);
        }
      }
      local_4c = (CHmsItem *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (&DAT_00d6790c,(CFastBuffer<class_CCrystalFace*> *)pSVar4);
      pCStack_50 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (local_4c != (CHmsItem *)0x0) {
        do {
          pSVar4 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                             (&DAT_00d6790c,pCStack_50,(ulong)pCVar16);
          if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x1c) !=
              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
            this_00 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                       *)(pSVar4 + 4);
            pSVar5 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
                     ::operator[](this + 0xa0,
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (pSVar4 + 0x1c),(ulong)pGVar18);
            GmBoxAligned::SetMult
                      (this_00,(SPlugFaceCull *)(*(int *)pSVar4 + 0x34),(SPlugFaceCull *)pSVar5,
                       (GmIso4 *)pGVar20);
            pGVar20 = (GmBoxAligned *)&pCStack_50;
            pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x5593ca;
            pGVar18 = this_00;
            pCVar8 = (CHmsZoneVPacker *)
                     GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                     ::GetContainingCell((GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                          *)this,this_00,pGVar20,(SUserData *)pCVar21);
            if (*(CHmsVPackerCell **)pCVar8 < (CHmsVPackerCell *)0x2) {
              pCVar21 = (CHmsVPackerCell *)&DAT_0000008c;
              pGVar20 = (GmBoxAligned *)0x5593db;
              this_02 = operator_new(0x8c);
              if (this_02 == (void *)0x0) {
                pCVar9 = (CHmsVPackerCell *)0x0;
              }
              else {
                pCVar21 = (CHmsVPackerCell *)0x5593e9;
                CHmsVPackerCell::CHmsVPackerCell(this_02,(CHmsVPackerCell *)pGVar22);
                pCVar9 = extraout_EAX;
              }
              *(CHmsVPackerCell **)pCVar8 = pCVar9;
              if (pCVar8 != this + 0x60) {
                *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + 1;
                pGVar22 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                           *)local_48;
                pCVar21 = (CHmsVPackerCell *)0x559406;
                GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                ::CellBecomeNotEmptyFlagParents
                          ((GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                            *)this,pGVar22,unaff_EBP);
              }
              if (2 < ((byte)local_48[0] & 0x1f)) {
                pCVar21 = *(CHmsVPackerCell **)pCVar8;
                pGVar20 = (GmBoxAligned *)0x559422;
                pGVar22 = local_48[0];
                (**(code **)(*(int *)this + 0xc))();
              }
            }
            *(SUserData **)(*(int *)pSVar4 + 0x4c) = unaff_EBP;
            pSVar14 = (SUserData *)&pCStack_54;
            CHmsVPackerCell::AddTreeMip
                      (*(CHmsVPackerCell **)pCVar8,*(CHmsVPackerCell **)pSVar4,
                       (SHmsVPackerObject *)this_00,pGStack_4,*(ulong **)(pSVar4 + 0x1c));
            if (1 < ((byte)pGVar22 & 0x1f)) {
              GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
              CellUpdateParentBBoxs
                        ((GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                          *)this,*(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                   **)pCVar8,(CHmsVPackerCell *)&stack0xffffffa0,pSVar14);
            }
          }
          pCStack_50 = pCStack_50 + 1;
        } while (pCStack_50 < local_4c);
      }
      if (*(CHmsPackLightMap **)(this + 0xf0) != (CHmsPackLightMap *)0x0) {
        CHmsPackLightMap::BlockAdd
                  (*(CHmsPackLightMap **)(this + 0xf0),(CHmsPackLightMap *)pGStack_4,
                   (CHmsCorpus *)pCVar16);
      }
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (local_28,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar16);
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (auStack_30,(CFastBuffer<class_CPlugFileGPUV*> *)pGVar18);
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (local_40,(CFastBuffer<class_CPlugFileGPUV*> *)pGVar20);
    }
  }
  else {
    CHmsItem::SetIsVisionStatic
              (this_03,(CHmsItem *)0x0,(int)((uint)DAT_00cca150 ^ (uint)&stack0xffffff9c));
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::CHmsZoneVPacker
// =================================================
void __thiscall CHmsZoneVPacker::CHmsZoneVPacker(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar1;
  CSceneToySeaHoule *in_stack_00000008;
  CPlugBitmap *in_stack_0000000c;
  float in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  float in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000030;
  CHmsZoneVPacker *pCVar2;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar3;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar4;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar5;
  
  pCVar5 = (CFastBuffer<class_CPlugFileSndGen*> *)0xffffffff;
  pCVar4 = (CFastBuffer<class_CPlugFileSndGen*> *)&LAB_00a9748a;
  pCVar3 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar2 = this;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
            ((GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *
             )this,(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                    *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  pCVar1 = (CFastBuffer<class_CPlugFileSndGen*> *)0x0;
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x84,unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x90,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0xa0,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar2);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0xac,pCVar3);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0xb8,pCVar4);
  *(undefined4 *)(this + 0xf0) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0xfc,pCVar5);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x108,pCVar1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x114,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  uStack00000020 = 7;
  Construct(this,in_stack_00000008,in_stack_0000000c,in_stack_00000010,in_stack_00000014,
            in_stack_00000018,in_stack_0000001c);
  ExceptionList = in_stack_00000030;
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::CellAndChildSetDirtyCV
// =================================================
void __thiscall
CHmsZoneVPacker::CellAndChildSetDirtyCV
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsVPackerCell *param_2,
          SUserData *param_3)
{
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  CHmsZoneVPacker *pCVar4;
  int iVar5;
  SCasterCat *pSVar6;
  uint uVar7;
  SCasterCat *pSVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  SUserData *unaff_EBX;
  CHmsVPackerCell *unaff_EBP;
  ulong unaff_ESI;
  CHmsZoneVPacker *this_00;
  uint uVar12;
  CHmsZoneVPacker *pCVar13;
  int local_1c;
  
  *(uint *)(this + 0xf8) = *(uint *)(this + 0xf8) & 0xfffffffe | 2;
  if (param_1 != (CHmsZoneVPacker *)0x0) {
    if (*(int *)(param_1 + 0x58) == 2) {
      return;
    }
    *(undefined4 *)(param_1 + 0x58) = 2;
  }
  uVar1 = *(uint *)param_2;
  if (2 < (uVar1 & 0x1f)) {
    pSVar6 = CFastArray<class_CHmsVPackerLevel>::operator[]
                       (this + 100,
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uVar1 & 0x1f) - 3),
                        unaff_ESI);
    uVar7 = uVar1 >> 5 & 0x1ff;
    uVar10 = uVar7 << ((byte)*(undefined4 *)(pSVar6 + 0x14) & 0x1f);
    uVar11 = uVar1 >> 0xe & 0x1ff;
    this_00 = (CHmsZoneVPacker *)(uVar11 << ((byte)*(undefined4 *)(pSVar6 + 0x18) & 0x1f));
    param_3 = (SUserData *)((uVar1 >> 0x17) << ((byte)*(undefined4 *)(pSVar6 + 0x1c) & 0x1f));
    uVar7 = uVar7 + 1 << ((byte)*(undefined4 *)(pSVar6 + 0x14) & 0x1f);
    uVar2 = *(undefined4 *)(pSVar6 + 0x18);
    uVar3 = *(undefined4 *)(pSVar6 + 0x1c);
    iVar9 = *(int *)(pSVar6 + 0x10) * (int)param_3 + *(int *)(pSVar6 + 4) * (int)this_00 +
            *(int *)pSVar6;
    for (; pCVar4 = this_00, iVar5 = iVar9,
        param_3 < (SUserData *)((uVar1 >> 0x17) + 1 << ((byte)uVar3 & 0x1f)); param_3 = param_3 + 1)
    {
      for (; pCVar4 < (CHmsZoneVPacker *)(uVar11 + 1 << ((byte)uVar2 & 0x1f)); pCVar4 = pCVar4 + 1)
      {
        if (uVar10 < uVar7) {
          uVar12 = uVar10;
          do {
            pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(local_1c + 0x58),
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar12 + iVar5),
                                (ulong)unaff_EBP);
            param_3 = (SUserData *)((uint)param_3 ^ (uVar12 << 5 ^ (uint)param_3) & 0x3fe0);
            pCVar13 = *(CHmsZoneVPacker **)pSVar8;
            if (pCVar13 != (CHmsZoneVPacker *)0x0) {
              if (pCVar13 < (CHmsZoneVPacker *)0x2) {
                pCVar13 = (CHmsZoneVPacker *)0x0;
              }
              unaff_EBP = (CHmsVPackerCell *)&param_3;
              CellAndChildSetDirtyCV(this_00,pCVar13,unaff_EBP,unaff_EBX);
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar7);
        }
        iVar5 = iVar5 + *(int *)(pSVar6 + 4);
      }
      iVar9 = iVar9 + *(int *)(pSVar6 + 0x10);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::CheckDirty
// =================================================
int __thiscall
CHmsZoneVPacker::CheckDirty
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsViewport *param_2,CHmsCamera *param_3)
{
{
  CHmsZoneVPacker *unaff_ESI;
  CHmsCamera *unaff_retaddr;
  
  if ((*(uint *)(this + 0xf8) & 3) == 0) {
    return 0;
  }
  if ((*(uint *)(this + 0xf8) & 0xc) != 0) {
    PrecalcLighting(this,unaff_ESI);
  }
  if (*(void **)(this + 0x80) != (void *)0x0) {
    CHmsOcclusion::UpdateInput(*(void **)(this + 0x80),(CGameCtnPainter *)unaff_retaddr);
  }
  *(uint *)(this + 0xf8) = *(uint *)(this + 0xf8) & 0xfffffffc;
  PreloadVisionData(this,(CHmsZoneVPacker *)param_2,(CHmsViewport *)param_3,unaff_retaddr);
  *(uint *)(this + 0xf8) = *(uint *)(this + 0xf8) & 0xfffffffc;
  return 1;
}
}

// =================================================
// Function: CHmsZoneVPacker::Construct
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsZoneVPacker::Construct
          (CHmsZoneVPacker *this,CSceneToySeaHoule *param_1,CPlugBitmap *param_2,float param_3,
          float param_4,float param_5,float param_6)
{
{
  undefined4 uVar1;
  SCasterCat *this_00;
  GmMat43 *unaff_EBX;
  ulong unaff_ESI;
  SLocationAlloc *unaff_EDI;
  SPlugVisibleFilter *unaff_retaddr;
  
  *(undefined4 *)(this + 0x124) = _DAT_00b31460;
  *(undefined4 *)(this + 0x74) = 3;
  *(undefined4 *)(this + 0x78) = 3;
  *(undefined4 *)(this + 0xe4) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  SLocationAlloc::UseNew(this + 0xa0,unaff_EDI);
  this_00 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>::
            operator[](this + 0xa0,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  GmIso4::SetIdentity(this_00,unaff_EBX);
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0xcc) = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0xd8) = _DAT_00b2c060;
  *(undefined4 *)(this + 0xdc) = uVar1;
  *(undefined4 *)(this + 0xe0) = uVar1;
  SPlugVisibleFilter::SetDefaultValues(this + 0x9c,unaff_retaddr);
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 200) = 0;
  *(undefined4 *)(this + 0xe8) = 0;
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined4 *)(this + 0xf4) = 0;
  *(undefined4 *)(this + 0xf8) = 1;
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::LightBBoxSetDirtyCV
// =================================================
void __thiscall
CHmsZoneVPacker::LightBBoxSetDirtyCV
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,GmBoxAligned *param_2)
{
{
  void *this_00;
  int iVar1;
  ulong uVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  GmIso4 *unaff_ESI;
  GmBoxAligned *unaff_EDI;
  GmBoxAligned *unaff_retaddr;
  
  this_00 = *(void **)(this + 0x60);
  if (((void *)0x1 < this_00) && (0.0 <= *(float *)((int)this_00 + 0xc))) {
    iVar1 = GmBoxAligned::TestInter(this_00,(CPlugVolumeProjector *)param_1,unaff_EDI,unaff_ESI);
    if (iVar1 != 0) {
      *(undefined4 *)((int)this_00 + 0x58) = 1;
    }
  }
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 100,unaff_EBX);
  if (1 < uVar2) {
    LightBBoxSetDirtyCV_Recur
              (this,(CHmsZoneVPacker *)(uVar2 - 1),0,0,0,(ulong)param_1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::LightBBoxSetDirtyCV_Recur
// =================================================
void __thiscall
CHmsZoneVPacker::LightBBoxSetDirtyCV_Recur
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,ulong param_2,ulong param_3,ulong param_4,
          ulong param_5,GmBoxAligned *param_6)
{
{
  CHmsZoneVPacker *pCVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *this_00;
  SCasterCat *pSVar4;
  int iVar5;
  CHmsZoneVPacker *this_01;
  CPlugVolumeProjector *pCVar6;
  uint uVar7;
  uint uVar8;
  CHmsZoneVPacker *unaff_EBX;
  GmBoxAligned *unaff_EBP;
  CPlugVolumeProjector *pCVar9;
  CPlugVolumeProjector *unaff_ESI;
  uint uVar10;
  ulong unaff_EDI;
  CPlugVolumeProjector *pCVar11;
  CPlugVolumeProjector *in_stack_0000001c;
  CHmsZoneVPacker *in_stack_00000020;
  GmBoxAligned *in_stack_00000024;
  CHmsVPackerCell *in_stack_00000028;
  SUserData *in_stack_ffffffe0;
  uint local_18;
  CPlugVolumeProjector *local_14;
  SCasterCat *local_8;
  uint local_4;
  
  pSVar4 = CFastArray<class_CHmsVPackerLevel>::operator[]
                     (this + 100,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_1 + -1),
                      unaff_EDI);
  uVar2 = *(undefined4 *)(pSVar4 + 0x18);
  pCVar6 = (CPlugVolumeProjector *)(param_3 << ((byte)*(undefined4 *)(pSVar4 + 0x14) & 0x1f));
  local_4 = param_4 << ((byte)uVar2 & 0x1f);
  uVar7 = param_5 << ((byte)*(undefined4 *)(pSVar4 + 0x1c) & 0x1f);
  local_14 = (CPlugVolumeProjector *)(param_3 + 1 << ((byte)*(undefined4 *)(pSVar4 + 0x14) & 0x1f));
  uVar3 = *(undefined4 *)(pSVar4 + 0x1c);
  this_01 = (CHmsZoneVPacker *)
            (*(int *)(pSVar4 + 0x10) * uVar7 + *(int *)(pSVar4 + 4) * local_4 + *(int *)pSVar4);
  pCVar9 = (CPlugVolumeProjector *)(local_18 ^ (param_2 + 1 ^ local_18) & 0x1f);
  uVar8 = local_4;
  local_8 = pSVar4;
  do {
    if (param_5 + 1 << ((byte)uVar3 & 0x1f) <= uVar7) {
      return;
    }
    pCVar9 = (CPlugVolumeProjector *)((uint)pCVar9 & 0x7fffff | uVar7 << 0x17);
    pCVar1 = this_01;
    uVar10 = uVar8;
    for (; uVar8 < param_4 + 1 << ((byte)uVar2 & 0x1f); uVar8 = uVar8 + 1) {
      pCVar9 = (CPlugVolumeProjector *)((uint)pCVar9 ^ (uVar8 << 0xe ^ (uint)pCVar9) & 0x7fc000);
      pCVar11 = pCVar6;
      if (pCVar6 < local_14) {
        do {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (in_stack_ffffffe0 + 0x58,
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                              (pCVar11 + (int)pCVar1),(ulong)unaff_ESI);
          this_00 = *(void **)pSVar4;
          pCVar9 = (CPlugVolumeProjector *)
                   ((uint)pCVar9 ^ ((int)pCVar11 << 5 ^ (uint)pCVar9) & 0x3fe0);
          if (this_00 != (void *)0x0) {
            if ((this_00 < (void *)0x2) || (*(float *)((int)this_00 + 0xc) < 0.0)) {
LAB_00557af2:
              if ((GmBoxAligned *)0x1 < param_6) {
                unaff_ESI = pCVar11;
                unaff_EBP = in_stack_00000024;
                unaff_EBX = in_stack_00000020;
                this = (CHmsZoneVPacker *)in_stack_00000028;
                LightBBoxSetDirtyCV_Recur
                          (this_01,(CHmsZoneVPacker *)(param_6 + -1),(ulong)pCVar11,
                           (ulong)in_stack_00000024,(ulong)in_stack_00000020,
                           (ulong)in_stack_00000028,(GmBoxAligned *)in_stack_ffffffe0);
              }
            }
            else {
              unaff_ESI = in_stack_0000001c;
              iVar5 = GmBoxAligned::TestInter
                                (this_00,in_stack_0000001c,unaff_EBP,(GmIso4 *)unaff_EBX);
              if (iVar5 != 0) {
                unaff_EBP = (GmBoxAligned *)0x557acc;
                unaff_EBX = (CHmsZoneVPacker *)in_stack_00000024;
                iVar5 = GmBoxAligned::IsIncluded(this_00,in_stack_00000024,(GmBoxAligned *)this);
                if (iVar5 == 0) {
                  if (*(int *)(*(int *)pSVar4 + 0x58) == 0) {
                    *(undefined4 *)(*(int *)pSVar4 + 0x58) = 1;
                  }
                  goto LAB_00557af2;
                }
                unaff_EBX = *(CHmsZoneVPacker **)pSVar4;
                this = (CHmsZoneVPacker *)&local_8;
                unaff_EBP = (GmBoxAligned *)0x557ae1;
                CellAndChildSetDirtyCV(this_01,unaff_EBX,(CHmsVPackerCell *)this,in_stack_ffffffe0);
              }
            }
          }
          pCVar11 = pCVar11 + 1;
          pSVar4 = local_8;
          uVar10 = local_4;
          local_14 = pCVar9;
        } while (pCVar11 < pCVar9);
      }
      pCVar1 = pCVar1 + *(int *)(pSVar4 + 4);
    }
    this_01 = this_01 + *(int *)(pSVar4 + 0x10);
    uVar7 = uVar7 + 1;
    uVar8 = uVar10;
  } while( true );
}
}

// =================================================
// Function: CHmsZoneVPacker::PrecalcLighting
// =================================================
void __thiscall CHmsZoneVPacker::PrecalcLighting(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1)
{
{
  void *pvVar1;
  uint uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  int unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CMwCmdBufferCore *in_stack_00000010;
  CHmsZoneVPacker *pCVar6;
  
  CMwCmdBufferCore::HighFrequencyEnterSafeSection(DAT_00d731e0,(CMwCmdBufferCore *)0x1,unaff_EDI);
  SetDayTimeFactor(this,*(CHmsZoneVPacker **)(this + 0x124),1.4013e-45,unaff_ESI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x58,unaff_EBP);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x58,pCVar5,unaff_EBX);
      pvVar1 = *(void **)pSVar4;
      if (((pvVar1 != (void *)0x0) && (pvVar1 != (void *)0x1)) &&
         ((((byte)*(undefined4 *)(this + 0xf8) & 3) != 2 || (*(int *)((int)pvVar1 + 0x58) != 0)))) {
        unaff_EBX = 1;
        pCVar6 = this + 0xa0;
        CHmsVPackerCell::PrecalcLighting(pvVar1,this);
        CMwCmdBufferCore::HighFrequencyRun
                  (DAT_00d731e0,(CMwCmdBufferCore *)&DAT_00000032,(ulong)pCVar6);
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar3);
  }
  if (((-1 < (char)(byte)*(undefined4 *)(this + 0xf8)) &&
      (pvVar1 = *(void **)(this + 0x60), (void *)0x1 < pvVar1)) &&
     ((((byte)*(undefined4 *)(this + 0xf8) & 3) == 1 || (*(int *)((int)pvVar1 + 0x58) != 0)))) {
    pCVar6 = this + 0xa0;
    CHmsVPackerCell::PrecalcLighting(pvVar1,this);
    CMwCmdBufferCore::HighFrequencyRun(DAT_00d731e0,(CMwCmdBufferCore *)0x1,(ulong)pCVar6);
    uVar2 = *(uint *)(this + 0xf8);
    *(uint *)(this + 0xf8) = (uVar2 >> 1 ^ uVar2) & 0x80 ^ uVar2;
  }
  CMwCmdBufferCore::HighFrequencyLeaveSafeSection(DAT_00d731e0,in_stack_00000010);
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::RemoveLight
// =================================================
void __thiscall
CHmsZoneVPacker::RemoveLight
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsCorpusLight *param_2)
{
{
  int iVar1;
  CHmsVPackerCell **ppCVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  SUserData unaff_BL;
  CHmsVPackerCell *pCVar5;
  ulong unaff_EBP;
  GmBoxAligned *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CHmsZoneVPacker *unaff_EDI;
  CHmsCorpusLight aCStack_14 [4];
  CHmsZoneVPacker aCStack_10 [16];
  
  iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x48) + 0x88) + 0x78))();
  if (((byte)param_1[0x60] & 0x1f) != 0) {
    ppCVar2 = GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
              GetCellFromUserData((GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                   *)this,*(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                            **)(param_1 + 0x60),unaff_BL);
    pCVar5 = *ppCVar2;
    if (((byte)*(undefined4 *)(this + 0xf8) & 3) != 1) {
      CHmsCorpusLight::ComputeBBoxInWorld
                ((CHmsCorpusLight *)param_1,aCStack_14,(GmBoxAligned *)&DAT_00000004,
                 (ERadius)unaff_EDI);
      unaff_EDI = aCStack_10;
      LightBBoxSetDirtyCV(this,unaff_EDI,unaff_ESI);
    }
    if (iVar1 == 3) {
      pCVar5 = pCVar5 + 0x5c;
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (pCVar5,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar4 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                             (pCVar5,pCVar6,(ulong)unaff_ESI);
          if (*(CHmsZoneVPacker **)pSVar4 == param_1) {
            CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc>::ReplaceByLastAt
                      (pCVar5,(CFastBufferRef<class_CGameMobil> *)pCVar6,1,unaff_EBP);
            return;
          }
          pCVar6 = pCVar6 + 1;
        } while (pCVar6 < pCVar3);
        return;
      }
    }
    else {
      pCVar5 = pCVar5 + 0x68;
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (pCVar5,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        while (pSVar4 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                                  (pCVar5,pCVar6,(ulong)unaff_ESI),
              *(CHmsZoneVPacker **)pSVar4 != param_1) {
          pCVar6 = pCVar6 + 1;
          if (pCVar3 <= pCVar6) {
            return;
          }
        }
        CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc>::ReplaceByLastAt
                  (pCVar5,(CFastBufferRef<class_CGameMobil> *)pCVar6,1,unaff_EBP);
      }
    }
  }
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::RemoveSolid
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsZoneVPacker::RemoveSolid(CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsCorpus *param_2)
{
{
  CPlugModelTree *pCVar1;
  int iVar2;
  SLocationAlloc *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  undefined4 *puVar6;
  GmFrustumIso4 *unaff_EBX;
  code *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  EMode unaff_EDI;
  void *in_stack_00000014;
  TiXmlAttribute *pTVar8;
  CFastBuffer<class_CGamePlayerScore*> *in_stack_ffffff6c;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff70;
  CFastBuffer<class_CGamePlayerScore*> *in_stack_ffffff74;
  CHmsCorpus *in_stack_ffffff78;
  CPlugTreeVisualMip aCStack_80 [8];
  CPlugModelTree *pCStack_78;
  CHmsVPackerCell **local_74;
  undefined1 auStack_70 [4];
  int iStack_6c;
  CHmsZoneVPacker aCStack_5c [52];
  undefined4 auStack_28 [7];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a972eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(CHmsPackLightMap **)(this + 0xf0) != (CHmsPackLightMap *)0x0) {
    CHmsPackLightMap::BlockSub
              (*(CHmsPackLightMap **)(this + 0xf0),(CHmsPackLightMap *)param_1,
               (CHmsCorpus *)(DAT_00cca150 ^ (uint)&stack0xffffff5c));
  }
  CPlugTree::CIteratorTree::CIteratorTree
            (&stack0xffffff78,*(CIteratorTree **)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 100),
             (CPlugTree *)0x0,unaff_EDI);
  if ((_DAT_00d678f4 & 1) == 0) {
    _DAT_00d678f4 = _DAT_00d678f4 | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d678e8,unaff_ESI);
    _atexit(`public:_void___thiscall_CHmsZoneVPacker::RemoveSolid(class_CHmsCorpus*)'::__l4::
            _dynamic_atexit_destructor_for__CellSubs__);
  }
  if ((_DAT_00d678f4 & 2) == 0) {
    _DAT_00d678f4 = _DAT_00d678f4 | 2;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d678dc,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EBP);
    unaff_EBP = `public:_void___thiscall_CHmsZoneVPacker::RemoveSolid(class_CHmsCorpus*)'::__l4::
                _dynamic_atexit_destructor_for__TreeToSubs__;
    _atexit(`public:_void___thiscall_CHmsZoneVPacker::RemoveSolid(class_CHmsCorpus*)'::__l4::
            _dynamic_atexit_destructor_for__TreeToSubs__);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            (&DAT_00d678e8,(GmFrustumIso4 *)unaff_EBP);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&DAT_00d678dc,unaff_EBX);
  while (iStack_6c != 0) {
    pCVar1 = CPlugTree::CIteratorTree::GetNextTree
                       (&pCStack_78,(CPlugModelTree_ItTree *)in_stack_ffffff6c);
    pCStack_78 = pCVar1;
    if (*(int *)(pCVar1 + 0x4c) != DAT_00d6e638) {
      in_stack_ffffff6c = (CFastBuffer<class_CGamePlayerScore*> *)0x9015000;
      pTVar8 = (TiXmlAttribute *)0x55aabb;
      iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))();
      if (iVar2 == 0) {
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (&DAT_00d678dc,(TiXmlAttributeSet *)aCStack_80,pTVar8);
      }
      else {
        pSVar3 = (SLocationAlloc *)
                 GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 ::GetCellFromUserData
                           ((GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                             *)this,*(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                      **)(pCVar1 + 0x4c),SUB41(pTVar8,0));
        if ((CHmsVPackerCell *)0x1 < *(CHmsVPackerCell **)pSVar3) {
          CHmsVPackerCell::SubTreeMip
                    (*(CHmsVPackerCell **)pSVar3,(CHmsVPackerCell *)pCVar1,aCStack_80,
                     (ulong *)in_stack_ffffff6c);
          in_stack_ffffff6c = (CFastBuffer<class_CGamePlayerScore*> *)&pCStack_78;
          pCStack_78 = (CPlugModelTree *)pSVar3;
          CFastBuffer<class_CGamePlayerScore*>::FindOrAdd
                    (&DAT_00d678e8,in_stack_ffffff6c,(CGamePlayerScore **)in_stack_ffffff70);
          if (pCStack_78 != (CPlugModelTree *)0xffffffff) {
            in_stack_ffffff6c = (CFastBuffer<class_CGamePlayerScore*> *)0x55ab06;
            in_stack_ffffff70 = (CFastBuffer<class_CCrystalFace*> *)pCStack_78;
            SLocationAlloc::FreeAt
                      (this + 0xa0,(SLocationAlloc *)pCStack_78,(ulong)in_stack_ffffff74);
          }
        }
        *(int *)(pCVar1 + 0x4c) = DAT_00d6e638;
      }
    }
  }
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (&DAT_00d678dc,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff6c);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (&DAT_00d678dc,pCVar7,(ulong)in_stack_ffffff70);
      uStack_4 = *(undefined4 *)pSVar5;
      puVar6 = auStack_28;
      iVar2 = 2;
      do {
        *puVar6 = _DAT_00b313ac;
        puVar6 = puVar6 + 7;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      local_74 = SubObject(this,aCStack_5c,(SHmsVPackerObject *)in_stack_ffffff74);
      in_stack_ffffff74 = (CFastBuffer<class_CGamePlayerScore*> *)&local_74;
      in_stack_ffffff70 = (CFastBuffer<class_CCrystalFace*> *)0x55ab8e;
      CFastBuffer<class_CGamePlayerScore*>::FindOrAdd
                (&DAT_00d678e8,in_stack_ffffff74,(CGamePlayerScore **)in_stack_ffffff78);
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < pCVar4);
  }
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d678e8,in_stack_ffffff70);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (&DAT_00d678e8,pCVar7,(ulong)in_stack_ffffff74);
      if ((void *)0x1 < (void *)**(undefined4 **)pSVar5) {
        in_stack_ffffff74 = (CFastBuffer<class_CGamePlayerScore*> *)param_1;
        CHmsVPackerCell::RemoveAllTreeMip
                  ((void *)**(undefined4 **)pSVar5,(CHmsVPackerCell *)param_1,in_stack_ffffff78);
      }
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < pCVar4);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (auStack_70,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffff74);
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::SetCreateParams
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsZoneVPacker::SetCreateParams
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,SHmsVPackerCreate *param_2)
{
{
  int iVar1;
  CHmsPackLightMap *pCVar2;
  uint uVar3;
  int extraout_EDX;
  ulong unaff_ESI;
  int unaff_EDI;
  CHmsPackLightMap *pCVar4;
  CHmsZoneVPacker *pCVar5;
  
  pCVar5 = this;
  SetDayTimeFactor(this,*(CHmsZoneVPacker **)(param_1 + 0x14),0.0,unaff_EDI);
  *(uint *)(this + 0xf8) =
       *(uint *)(this + 0xf8) ^ (*(int *)(param_1 + 0xc) * 4 ^ *(uint *)(this + 0xf8)) & 0xc;
  uVar3 = ((uint)(*(int *)(param_1 + 0x10) != 0) << 6 ^ *(uint *)(this + 0xf8)) & 0x40 ^
          *(uint *)(this + 0xf8);
  *(uint *)(this + 0xf8) = uVar3;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    *(uint *)(this + 0xf8) = uVar3 & 0xffffffef;
    *(undefined4 *)(this + 0xf4) = 0;
  }
  else if (iVar1 == 1) {
    *(uint *)(this + 0xf8) = (extraout_EDX == 0 | 0x10) << 4 | uVar3 & 0xffffffef;
    *(uint *)(this + 0xf4) = (extraout_EDX != 0) + 1;
    DAT_00d1447c = 0;
  }
  else if (iVar1 == 2) {
    *(undefined4 *)(this + 0xf4) = 0;
    *(uint *)(this + 0xf8) = (uint)(extraout_EDX == 0) << 4 | uVar3 & 0xfffffeef;
    DAT_00d1447c = 1;
    if ((extraout_EDX != 0) && (DAT_00b3d2a0 < *(float *)(this + 0x124))) {
      *(uint *)(this + 0xf8) = *(uint *)(this + 0xf8) & 0xfffffff3;
    }
  }
  param_2 = *(SHmsVPackerCreate **)(param_1 + 0x1c);
  if ((float)param_2 < 0.0 == ((float)param_2 == 0.0)) {
    if (!NAN((float)param_2) && 1.0 < (float)param_2 != ((float)param_2 == 1.0)) {
      param_2 = (SHmsVPackerCreate *)0x3f800000;
    }
  }
  else {
    param_2 = (SHmsVPackerCreate *)0x0;
  }
  _DAT_00d6e730 = (CHmsPackLightMap *)0x3f800000;
  pCVar4 = *(CHmsPackLightMap **)(param_1 + 0x18);
  pCVar2 = (CHmsPackLightMap *)0x0;
  if (((float)pCVar4 < 0.0 != ((float)pCVar4 == 0.0)) || (pCVar2 = pCVar4, (float)pCVar4 < 1.0)) {
    _DAT_00d6e730 = pCVar2;
  }
  _DAT_00d11c2c = (float)param_2 - (float)_DAT_00d6e730;
  pCVar4 = _DAT_00d6e730;
  if (((byte)this[0xf8] & 0xc) != 0) {
    CFastBuffer<struct_CSystemArchiveNod::SExternalRef>::SetSizeAtLeast
              (this + 0x84,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0xc8,unaff_ESI);
    CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo>::SetSizeAtLeast
              (this + 0x90,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0xc8,(ulong)pCVar5);
  }
  if (*(CHmsZoneVPacker **)(param_1 + 0x24) != (CHmsZoneVPacker *)0x0) {
    SetPackLightMap(this,*(CHmsZoneVPacker **)(param_1 + 0x24),pCVar4);
  }
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::SetDayTimeFactor
// =================================================
void __thiscall
CHmsZoneVPacker::SetDayTimeFactor
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,float param_2,int param_3)
{
{
  *(CHmsZoneVPacker **)(this + 0x124) = param_1;
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::SetPackLightMap
// =================================================
void __thiscall
CHmsZoneVPacker::SetPackLightMap
          (CHmsZoneVPacker *this,CHmsZoneVPacker *param_1,CHmsPackLightMap *param_2)
{
{
  int iVar1;
  CMwNod *unaff_ESI;
  CHmsZoneVPacker *unaff_EDI;
  
  if (*(CHmsZoneVPacker **)(this + 0xf0) != param_1) {
    if ((param_1 != (CHmsZoneVPacker *)0x0) &&
       (iVar1 = CHmsPackLightMap::LmUsageIsSupported
                          ((CHmsPackLightMap *)param_1,(CHmsPackLightMap *)this,unaff_EDI),
       iVar1 == 0)) {
      return;
    }
    if (param_1 != *(CHmsZoneVPacker **)(this + 0xf0)) {
      if (param_1 != (CHmsZoneVPacker *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_1,unaff_ESI);
      }
      if (*(CMwNod **)(this + 0xf0) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0xf0),unaff_ESI);
      }
      *(CHmsZoneVPacker **)(this + 0xf0) = param_1;
    }
    if (*(CHmsPackLightMap **)(this + 0xf0) != (CHmsPackLightMap *)0x0) {
      CHmsPackLightMap::SetPacker
                (*(CHmsPackLightMap **)(this + 0xf0),(CHmsPackLightMap *)this,
                 (CHmsZoneVPacker *)unaff_ESI);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::SetZone
// =================================================
void __thiscall
CHmsZoneVPacker::SetZone(CHmsZoneVPacker *this,CSceneSector *param_1,CHmsZone *param_2)
{
{
  CHmsItem *pCVar1;
  CHmsItem *this_00;
  int *extraout_EAX;
  int *piVar2;
  CHmsCorpus *pCVar3;
  int in_stack_ffffffdc;
  int iVar4;
  EDynamicType EVar5;
  CHmsZone *pCVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a96f1b;
  local_c = ExceptionList;
  pCVar1 = (CHmsItem *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  if (*(CSceneSector **)(this + 0xe4) != param_1) {
    *(CSceneSector **)(this + 0xe4) = param_1;
    if (*(int *)(this + 0xec) == 0) {
      EVar5 = 0x58;
      iVar4 = 0x5558aa;
      this_00 = operator_new(0x58);
      local_4 = 0;
      if (this_00 == (CHmsItem *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        EVar5 = 0x5558c4;
        CHmsItem::CHmsItem(this_00,pCVar1);
        piVar2 = extraout_EAX;
      }
      *(int **)(this + 0xec) = piVar2;
      (**(code **)(*piVar2 + 0x4c))();
      CHmsItem::IsVisibleSet(*(CHmsItem **)(this + 0xec),(CHmsItem *)0x0,in_stack_ffffffdc);
      CHmsItem::SetIsVisionStatic(*(CHmsItem **)(this + 0xec),(CHmsItem *)0x0,iVar4);
      CHmsItem::SetDynamicType(*(CHmsItem **)(this + 0xec),(CHmsItem *)0x0,EVar5);
    }
    pCVar6 = (CHmsZone *)PTR_DAT_00cde0b4;
    (**(code **)(*(int *)param_1 + 0x78))(*(undefined4 *)(this + 0xec));
    pCVar3 = CHmsItem::GetCorpus(*(CHmsItem **)(this + 0xec),(CHmsItem *)param_1,pCVar6);
    *(CHmsCorpus **)(this + 0xe8) = pCVar3;
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::ShadowCasterStateAdd
// =================================================
void __cdecl CHmsZoneVPacker::ShadowCasterStateAdd(EShadowCaster *param_1,CHmsItem *param_2)
{
{
  EShadowCaster EVar1;
  bool bVar2;
  
  bVar2 = param_2[0x18] != (CHmsItem)0x0;
  EVar1 = *param_1;
  if (EVar1 == 0) {
    if (bVar2) {
      *param_1 = 2;
    }
  }
  else if (EVar1 == 1) {
    if (!bVar2) {
      *param_1 = 2;
      return;
    }
  }
  else if (EVar1 == 3) {
    *param_1 = (uint)bVar2;
    return;
  }
  return;
}
}

