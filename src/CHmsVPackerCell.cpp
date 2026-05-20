// Class implementation: CHmsVPackerCell

// =================================================
// Function: CHmsVPackerCell::AddTreeMip
// =================================================
void __thiscall
CHmsVPackerCell::AddTreeMip
          (void *this,CHmsVPackerCell *param_1,SHmsVPackerObject *param_2,GmBoxAligned *param_3,
          ulong *param_4)
{
{
  AddTreeMip(this,*(CHmsVPackerCell **)(param_1 + 0x60),param_2,*(GmBoxAligned **)(param_1 + 0x5c),
             *(ulong **)(param_1 + 100));
  return;
}
}

// =================================================
// Function: CHmsVPackerCell::BBoxHasChanged
// =================================================
void __thiscall CHmsVPackerCell::BBoxHasChanged(void *this,CHmsVPackerCell *param_1)
{
{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)func_0x009c1b40();
  *(float *)((int)this + 0x28) = (float)fVar2;
  fVar1 = *(float *)((int)this + 0x14);
  if (*(float *)((int)this + 0x10) <= fVar1) {
    fVar1 = *(float *)((int)this + 0x10);
  }
  if (fVar1 < *(float *)((int)this + 0xc)) {
    *(float *)((int)this + 0x2c) = fVar1;
    return;
  }
  *(float *)((int)this + 0x2c) = *(float *)((int)this + 0xc);
  return;
}
}

// =================================================
// Function: CHmsVPackerCell::CHmsVPackerCell
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsVPackerCell::CHmsVPackerCell(void *this,CHmsVPackerCell *param_1)
{
{
  undefined4 uVar1;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000008;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000000c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000010;
  
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x18),unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x30),unaff_retaddr);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x3c),(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x4c),in_stack_00000008);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x5c),in_stack_0000000c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x68),in_stack_00000010);
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)((int)this + 0xc) = _DAT_00b2c060;
  *(undefined4 *)((int)this + 0x10) = uVar1;
  *(undefined4 *)((int)this + 0x14) = uVar1;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x80) = uVar1;
  *(undefined4 *)((int)this + 0x84) = uVar1;
  *(undefined4 *)((int)this + 0x88) = uVar1;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined2 *)((int)this + 0x24) = 0;
  return;
}
}

// =================================================
// Function: CHmsVPackerCell::PrecalcLighting
// =================================================
void __thiscall CHmsVPackerCell::PrecalcLighting(void *this,CHmsZoneVPacker *param_1)
{
{
  int iVar1;
  SCasterCat *pSVar2;
  void *this_00;
  CIteratorVisual *pCVar3;
  ulong uVar4;
  CHmsZoneVPacker *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ERadius unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  GmFrustumIso4 *unaff_EDI;
  void *in_stack_0000000c;
  int in_stack_00000014;
  void *pvStack0000001c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000020;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000024;
  void *in_stack_00000028;
  CHmsZoneVPacker *in_stack_00000034;
  CHmsZoneVPacker *in_stack_ffffff9c;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar6;
  CPlugTree *in_stack_ffffffa4;
  CIteratorVisual *in_stack_ffffffa8;
  CPlugTree **in_stack_ffffffac;
  CPlugTree *in_stack_ffffffb0;
  GmIso3 *in_stack_ffffffb4;
  void *pvStack_48;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_40;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_3c;
  SCasterCat *pSStack_38;
  CHmsZoneVPacker *local_34;
  GmIso3 *local_30;
  undefined1 local_2c [8];
  undefined4 uStack_24;
  int local_20;
  CPlugTree local_14 [4];
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a97a80;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar3 = this;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            (param_1 + 0x84,(GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffff8c));
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            ((CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc> *)(param_1 + 0x90),unaff_EDI);
  if (in_stack_00000014 != 0) {
    CHmsZoneVPacker::AddInteractLights
              (param_1,param_1 + 0x84,
               (CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc> *)(param_1 + 0x90),this,
               (CHmsVPackerCell *)&DAT_00d6e348,(SFlags *)0x0,unaff_ESI);
  }
  pvStack0000001c =
       (void *)CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x30),unaff_EBP);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pvStack0000001c != (void *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                         ((void *)((int)this + 0x30),pCVar5,(ulong)unaff_EBX);
      in_stack_ffffff9c =
           (CHmsZoneVPacker *)
           CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>::
           operator[](pvStack0000001c,
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar2 + 0x54),
                      (ulong)in_stack_ffffff9c);
      unaff_EBX = *(CHmsZoneVPacker **)(pSVar2 + 0x58);
      CHmsZoneVPacker::PrecalcLighting(param_1,unaff_EBX);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < in_stack_00000020);
  }
  this_00 = (void *)CFastBuffer<class_CCrystalFace*>::GetCount
                              ((void *)((int)this + 0x3c),
                               (CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (this_00 != (void *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CControlDisplayGraph::SGraph>::operator[]
                         ((void *)((int)this + 0x3c),pCVar5,(ulong)in_stack_ffffff9c);
      pCVar3 = (CIteratorVisual *)
               CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (pSVar2 + 0x54),(ulong)pCVar3);
      in_stack_ffffff9c = *(CHmsZoneVPacker **)(pSVar2 + 0x58);
      CHmsZoneVPacker::PrecalcLighting(param_1,in_stack_ffffff9c);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < in_stack_00000024);
  }
  pCStack_3c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         ((void *)((int)this + 0x4c),
                          (CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff9c);
  in_stack_00000024 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack_3c == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    *(undefined4 *)((int)this + 0x58) = 0;
  }
  else {
    do {
      pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         ((void *)((int)this + 0x4c),in_stack_00000024,(ulong)pCVar3);
      iVar1 = *(int *)(pSVar2 + 4);
      uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                        ((void *)(iVar1 + 0xac),
                         (CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffa4);
      in_stack_ffffffa4 = *(CPlugTree **)(pSVar2 + 8);
      pCVar3 = (CIteratorVisual *)0x5620f2;
      pSStack_38 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
                   ::operator[](in_stack_00000028,
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_ffffffa4,
                                (ulong)in_stack_ffffffa8);
      if (1 < uVar4) {
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        local_34 = (CHmsZoneVPacker *)(uVar4 - 1);
        this = pvStack_48;
        if (local_34 != (CHmsZoneVPacker *)0x0) {
          do {
            pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar1 + 0xac),pCVar5,(ulong)pCVar3);
            pCVar3 = *(CIteratorVisual **)pSVar2;
            CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                      (&local_34,(CFastBuffer<class_CPlugFileSndGen*> *)in_stack_ffffffa4);
            uStack_24 = 0;
            in_stack_ffffffa4 = (CPlugTree *)0x0;
            pvStack0000001c = (void *)0x0;
            pCVar6 = (CFastBuffer<class_CPlugFileGPUV*> *)0x56213c;
            CPlugTree::CIteratorVisual::ResetItVisual
                      (&local_30,pCVar3,(CPlugTree *)0x0,(EMode)in_stack_ffffffa8);
            while (local_20 != 0) {
              in_stack_ffffffa8 = (CIteratorVisual *)&pCStack_40;
              in_stack_ffffffa4 = (CPlugTree *)0x56215e;
              CPlugTree::CIteratorVisual::GetNextVisual
                        (local_2c,in_stack_ffffffa8,in_stack_ffffffac);
              if (*(int *)(pCStack_3c + 0x94) != 0) {
                in_stack_ffffffa8 = (CIteratorVisual *)0x1;
                in_stack_ffffffa4 = local_14;
                pCVar3 = (CIteratorVisual *)0x562177;
                CPlugTree::GetThisToRootTransfo
                          ((CPlugTree *)pCStack_3c,in_stack_ffffffa4,(GmIso4 *)0x1,iVar1,
                           in_stack_ffffffb0);
                GmIso4::Mult(local_10,local_30,in_stack_ffffffb4);
                in_stack_ffffffb4 = (GmIso3 *)&local_c;
                in_stack_ffffffac = (CPlugTree **)0x56219b;
                in_stack_ffffffb0 = (CPlugTree *)local_34;
                CHmsZoneVPacker::PrecalcLighting(in_stack_00000034,local_34);
              }
            }
            CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                      (&pCStack_3c,pCVar6);
            pCVar5 = pCVar5 + 1;
          } while (pCVar5 < pCStack_40);
        }
      }
      in_stack_00000024 = in_stack_00000024 + 1;
    } while (in_stack_00000024 < pCStack_3c);
    *(undefined4 *)((int)this + 0x58) = 0;
  }
  ExceptionList = in_stack_0000000c;
  return;
}
}

// =================================================
// Function: CHmsVPackerCell::PreloadVisionData
// =================================================
void __thiscall
CHmsVPackerCell::PreloadVisionData
          (void *this,CHmsZoneVPacker *param_1,CHmsViewport *param_2,CHmsCamera *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000010;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000018;
  CHmsCamera *pCVar5;
  undefined4 uVar6;
  CFastBuffer<class_CCrystalFace*> *pCVar7;
  CFastBuffer<class_CCrystalFace*> *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffffc;
  
  pCVar7 = this;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x30),unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      uVar6 = 0;
      pCVar5 = param_3;
      pSVar2 = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                         ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)this + 0x30),
                          pCVar3,1);
      this = in_stack_fffffffc;
      (**(code **)(*(int *)param_2 + 0xa0))(*(undefined4 *)(pSVar2 + 0x58),pCVar5,uVar6);
      pCVar3 = pCVar3 + 1;
      in_stack_fffffffc = this;
    } while (pCVar3 < pCVar1);
  }
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)this + 0x3c),unaff_ESI
                     );
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      uVar6 = 0;
      pCVar5 = param_3;
      pSVar2 = CFastBuffer<struct_CControlDisplayGraph::SGraph>::operator[]
                         ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)this + 0x3c),
                          pCVar4,1);
      (**(code **)(*(int *)param_2 + 0xa0))(*(undefined4 *)(pSVar2 + 0x58),pCVar5,uVar6);
      pCVar4 = pCVar4 + 1;
      this = pCVar1;
    } while (pCVar4 < pCVar3);
  }
  pCStack00000010 =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
       CFastBuffer<class_CCrystalFace*>::GetCount
                 ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)this + 0x4c),unaff_EBP);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack00000010 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      uVar6 = 0;
      pCVar5 = param_3;
      pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)this + 0x4c),
                          pCVar1,1);
      (**(code **)(*(int *)param_2 + 0xa0))(*(undefined4 *)(pSVar2 + 4),pCVar5,uVar6);
      pCVar1 = pCVar1 + 1;
      this = param_1;
    } while (pCVar1 < pCStack00000010);
  }
  pCStack00000018 =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
       CFastBuffer<class_CCrystalFace*>::GetCount
                 ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)this + 0x5c),unaff_EBX);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack00000018 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)this + 0x5c),
                          pCVar1,(ulong)pCVar7);
      pCVar8 = *(CFastBuffer<class_CCrystalFace*> **)(*(int *)(*(int *)pSVar2 + 0x48) + 0x68);
      if ((pCVar8 != (CFastBuffer<class_CCrystalFace*> *)0x0) && (*(int *)(pCVar8 + 0x14) == 0)) {
        (**(code **)(*(int *)param_2 + 0xb0))();
        pCVar7 = pCVar8;
      }
      pCVar1 = pCVar1 + 1;
    } while (pCVar1 < pCStack00000018);
  }
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)this + 0x68),pCVar7);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)this + 0x68),
                          pCVar3,(ulong)in_stack_fffffffc);
      pCVar4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                (*(int *)(*(int *)pSVar2 + 0x48) + 0x68);
      if ((pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) &&
         (*(int *)(pCVar4 + 0x14) == 0)) {
        (**(code **)(*(int *)param_2 + 0xb0))();
        in_stack_fffffffc = pCVar4;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsVPackerCell::RemoveAllTreeMip
// =================================================
void __thiscall
CHmsVPackerCell::RemoveAllTreeMip(void *this,CHmsVPackerCell *param_1,CHmsCorpus *param_2)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = (void *)((int)this + 0x4c);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this_00,pCVar3,(ulong)unaff_EBP);
      if (*(CHmsCorpus **)pSVar2 == param_2) {
        pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                           (this_00,pCVar3,unaff_ESI);
        unaff_ESI = 1;
        *(undefined4 *)(*(int *)(pSVar2 + 4) + 0x4c) = DAT_00d6e638;
        unaff_EBP = pCVar3;
        CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc>::ReplaceByLastAt
                  (this_00,(CFastBufferRef<class_CGameMobil> *)pCVar3,1,unaff_EBX);
        pCVar3 = pCVar3 + -1;
        pCVar1 = pCVar1 + -1;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsVPackerCell::SubTreeMip
// =================================================
void __thiscall
CHmsVPackerCell::SubTreeMip
          (void *this,CHmsVPackerCell *param_1,CPlugTreeVisualMip *param_2,ulong *param_3)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  undefined4 *in_stack_0000001c;
  
  this_00 = (void *)((int)this + 0x4c);
  *(undefined4 *)param_2 = 0xffffffff;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    while (pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                              (this_00,pCVar3,unaff_EBP),
          *(CPlugTreeVisualMip **)(pSVar2 + 4) != param_2) {
      pCVar3 = pCVar3 + 1;
      if (pCVar1 <= pCVar3) {
        return;
      }
    }
    pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                       (this_00,pCVar3,unaff_ESI);
    pSVar2 = pSVar2 + 0xc;
    *(int *)pSVar2 = *(int *)pSVar2 + -1;
    if (*(int *)pSVar2 == 0) {
      pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this_00,pCVar3,unaff_EBX);
      if (*(int *)(pSVar2 + 8) != -1) {
        pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                           (this_00,pCVar3,unaff_retaddr);
        *in_stack_0000001c = *(undefined4 *)(pSVar2 + 8);
        pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                           (this_00,pCVar3,(ulong)param_1);
        *(undefined4 *)(pSVar2 + 8) = 0xffffffff;
      }
      *(undefined4 *)(param_2 + 0x4c) = DAT_00d6e638;
      CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc>::ReplaceByLastAt
                (this_00,(CFastBufferRef<class_CGameMobil> *)pCVar3,1,(ulong)param_2);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsVPackerCell::~CHmsVPackerCell
// =================================================
void __thiscall CHmsVPackerCell::~CHmsVPackerCell(void *this,CHmsVPackerCell *param_1)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EBX;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EBP;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EDI;
  void *in_stack_00000010;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar4;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar5;
  
  this_00 = (void *)((int)this + 0x30);
  pCVar5 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar4 = this;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)
                              (DAT_00cca150 ^ (uint)&stack0xffffffe0));
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                         (this_00,pCVar3,(ulong)unaff_EDI);
      if (*(int **)(pSVar2 + 0x58) != (int *)0x0) {
        unaff_EDI = (CFastBuffer<class_CPlugFileGPUV*> *)0x1;
        (**(code **)(**(int **)(pSVar2 + 0x58) + 4))();
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x68),unaff_EDI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x5c),unaff_ESI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x4c),unaff_EBP);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x3c),unaff_EBX);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this_00,pCVar4);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x18),pCVar5);
  ExceptionList = in_stack_00000010;
  return;
}
}

