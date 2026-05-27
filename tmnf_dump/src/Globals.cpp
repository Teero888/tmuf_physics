// Global Functions and Headers

// Extracted Physics Code from CTrackManiaRace::Validate

// =================================================
// Function: ::s_CollisionGroupPairs__
// =================================================
void __cdecl
`dynamic_atexit_destructor_for_'public:_static_class_CFastArray<struct_CHmsItem::SHmsCollisionGroupPair>_CHmsItem
::s_CollisionGroupPairs__(void)
{
{
  CFastArray<class_CFuncShader*> *in_stack_00000004;
  
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(&DAT_00d67590,in_stack_00000004);
  return;
}
}

// =================================================
// Function: ::s_MergeForceDecls__
// =================================================
void __cdecl
`dynamic_atexit_destructor_for_'public:_static_class_CFastBuffer<struct_CPlugVisual3D::SMergeForceDecl>_CPlugVisual3D
::s_MergeForceDecls__(void)
{
{
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_00000004;
  
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&DAT_00d6f380,in_stack_00000004);
  return;
}
}

// =================================================
// Function: AcquireFstMutex
// =================================================
void __cdecl AcquireFstMutex(ulong *param_1)
{
{
  while( true ) {
    LOCK();
    *param_1 = *param_1 + 1;
    UNLOCK();
    if (*param_1 == 0) break;
    LOCK();
    *param_1 = *param_1 - 1;
    UNLOCK();
    Sleep(0);
  }
  return;
}
}

// =================================================
// Function: ApplyMenuSortPriorities
// =================================================
void __cdecl ApplyMenuSortPriorities(CFastBuffer<class_CGameMenu*> *param_1,CHmsViewport *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CHmsViewport *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  CHmsZoneOverlay *pCVar5;
  CHmsZoneOverlay *pCVar6;
  CHmsViewport *pCVar7;
  CHmsViewport *pCVar8;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int iVar10;
  CHmsViewport *pCVar11;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  CHmsViewport *in_stack_00000014;
  CHmsViewport *in_stack_0000001c;
  CHmsViewport *in_stack_00000020;
  CHmsViewport *in_stack_00000024;
  CHmsViewport *in_stack_ffffffec;
  ulong uVar12;
  CFastArray<class_GxTexCoordSet> *in_stack_fffffff4;
  CHmsViewport *in_stack_fffffff8;
  CHmsZoneOverlay *in_stack_fffffffc;
  
  do {
    pCVar2 = (CHmsViewport *)CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EDI);
    pCVar7 = (CHmsViewport *)0x0;
    uVar12 = 0;
    pCVar11 = pCVar2;
    if (pCVar2 == (CHmsViewport *)0x0) {
      return;
    }
    do {
      pCVar8 = (CHmsViewport *)0x0;
      if (pCVar7 != (CHmsViewport *)0x0) {
        pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pCVar2 + -(int)pCVar7);
        pCVar1 = pCVar9 + -1;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_1,pCVar9,(ulong)unaff_ESI);
        iVar10 = *(int *)pSVar3;
        unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x59d032;
        unaff_ESI = pCVar1;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](param_1,pCVar1,unaff_EBP)
        ;
        iVar4 = *(int *)pSVar3;
        if (*(int *)(iVar10 + 100) < *(int *)(iVar4 + 100)) {
          in_stack_fffffffc = (CHmsZoneOverlay *)0x1;
          unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x59d04d;
          unaff_ESI = pCVar9;
          CFastBuffer<class_CGameFid*>::SwapElemsAt
                    (param_1,(CFastBuffer<struct_CVisionViewport::SDelayedToSort64b> *)pCVar9,
                     (ulong)pCVar1,unaff_EBX);
          unaff_EBP = 0x59d055;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (param_1,pCVar9,(ulong)in_stack_ffffffec);
          iVar10 = *(int *)pSVar3;
          unaff_EBX = 0x59d05f;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](param_1,pCVar1,uVar12);
          iVar4 = *(int *)pSVar3;
        }
        pCVar7 = in_stack_00000020;
        in_stack_0000000c = *(undefined4 *)(*(int *)(iVar10 + 0xa4) + 0xa0);
        iVar10 = *(int *)(in_stack_00000020 + 0x238);
        in_stack_00000010 = *(undefined4 *)(*(int *)(iVar4 + 0xa4) + 0xa0);
        pCVar5 = (CHmsZoneOverlay *)
                 CFastArray<class_CGameMenuFrame*>::Find
                           ((void *)(iVar10 + 0x18),
                            (CFastArray<class_GxTexCoordSet> *)&stack0x0000000c,
                            (GxTexCoordSet *)in_stack_fffffff4);
        in_stack_fffffff4 = (CFastArray<class_GxTexCoordSet> *)&stack0x00000014;
        uVar12 = 0x59d0a8;
        pCVar6 = (CHmsZoneOverlay *)
                 CFastArray<class_CGameMenuFrame*>::Find
                           ((void *)(iVar10 + 0x18),in_stack_fffffff4,
                            (GxTexCoordSet *)in_stack_fffffff8);
        pCVar2 = in_stack_00000024;
        pCVar8 = in_stack_00000014;
        if (((pCVar5 != (CHmsZoneOverlay *)0xffffffff) && (pCVar6 != (CHmsZoneOverlay *)0xffffffff))
           && (pCVar5 < pCVar6)) {
          in_stack_00000010 = 1;
          uVar12 = 0x59d0cb;
          CHmsViewport::OverlaySetIndex(pCVar7,in_stack_00000014,pCVar6,(ulong)in_stack_fffffffc);
          in_stack_fffffff4 = (CFastArray<class_GxTexCoordSet> *)0x59d0d8;
          in_stack_fffffff8 = in_stack_0000001c;
          CHmsViewport::OverlaySetIndex(pCVar7,in_stack_0000001c,pCVar5,(ulong)pCVar11);
          pCVar2 = in_stack_00000024;
          pCVar8 = in_stack_00000014;
          in_stack_fffffffc = pCVar5;
        }
      }
      pCVar7 = pCVar8 + 1;
      in_stack_ffffffec = pCVar7;
    } while (pCVar7 < pCVar2);
  } while (uVar12 != 0);
  return;
}
}

// =================================================
// Function: BlurHVCreateShader
// =================================================
CPlugShaderApply * __cdecl
BlurHVCreateShader(CVisionViewportDx9 *param_1,ulong param_2,ulong param_3,CPlugBitmap *param_4)
{
{
  int iVar1;
  CPlugFileGPUP *pCVar2;
  CPlugShaderApply *pCVar3;
  CPlugShaderApply *this;
  CMwNod *extraout_EAX;
  CPlugBitmapApply *this_00;
  uint uVar4;
  CVisionViewportDx9 *pCVar5;
  CPlugFileGPUV *pCVar6;
  SCasterCat *pSVar7;
  ulong unaff_EBX;
  uint uVar8;
  GxColor *unaff_EBP;
  int unaff_ESI;
  CMwNod *this_01;
  CMwNod *unaff_EDI;
  CPlugShaderPass *pCVar9;
  CVisionViewportDx9 *in_stack_00000020;
  CPlugShaderPass *in_stack_00000024;
  uint in_stack_00000028;
  CPlugShaderApply *in_stack_0000002c;
  uint in_stack_00000034;
  CPlugShader *in_stack_ffffffe4;
  ulong in_stack_ffffffe8;
  EGxBlendFactor in_stack_ffffffec;
  EGxTexAddress EVar10;
  void *local_c;
  undefined1 *local_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00aeaf3b;
  local_c = ExceptionList;
  pCVar3 = (CPlugShaderApply *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_c;
  this = operator_new(0xa8);
  local_4 = 0;
  if (this == (CPlugShaderApply *)0x0) {
    this_01 = (CMwNod *)0x0;
  }
  else {
    CPlugShaderApply::CPlugShaderApply(this,pCVar3);
    this_01 = extraout_EAX;
  }
  CMwNod::MwAddRef(this_01,unaff_EDI);
  CPlugShader::SetDoubleSided((CPlugShader *)this_01,(CPlugShader *)0x1,unaff_ESI);
  EVar10 = 0x3f800000;
  local_c = (void *)0x3f800000;
  local_8 = (undefined1 *)0x3f800000;
  local_4 = 0x3f800000;
  CPlugShaderGeneric::SetVertexColor
            ((CPlugShaderGeneric *)this_01,(CPlugShaderGeneric *)0x0,
             (EPlugShaderVertexColor)&stack0xfffffff0,unaff_EBP);
  CPlugShader::SetReceiverShadowGroupMask((CPlugShader *)this_01,(CPlugShader *)0x0,unaff_EBX);
  CHmsItem::SetIsForcePointDynamicCollisionResponse((CHmsItem *)this_01,(CHmsItem *)0x0,(int)this);
  (**(code **)(*(int *)this_01 + 0x94))();
  CPlugShader::RemovePasses((CPlugShader *)this_01,in_stack_ffffffe4);
  uVar4 = 0;
  for (uVar8 = in_stack_00000028; uVar8 != 0; uVar8 = uVar8 - 1) {
    this_00 = CPlugShaderApply::AddTextureApply
                        ((CPlugShaderApply *)this_01,in_stack_0000002c,(CPlugBitmap *)0x1,0,
                         in_stack_ffffffe8);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)this_00,(CPlugBitmapSampler *)0x0,in_stack_ffffffec);
    in_stack_ffffffec = 0;
    in_stack_ffffffe8 = 2;
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)this_00,(CPlugBitmapSampler *)0x2,2,0,EVar10);
    uVar4 = in_stack_00000034;
  }
  pCVar9 = (CPlugShaderPass *)0x0;
  if (in_stack_00000024 != (CPlugShaderPass *)0x0) {
    do {
      local_4 = uVar4;
      if (4 < uVar4) {
        local_4 = 4;
      }
      pCVar5 = (CVisionViewportDx9 *)(local_4 + 0x15);
      iVar1 = (int)pCVar5 * 4;
      if (((&DAT_00d77970)[(int)pCVar5] & DAT_00d77b0c) == DAT_00d77b0c) {
        if (*(int *)(in_stack_00000020 + iVar1 + 0x138c) == 0) {
          CVisionViewportDx9::StdGpuVLoad
                    (in_stack_00000020,pCVar5,DAT_00d77b0c,SUB41(in_stack_ffffffe8,0));
        }
        if (*(int *)(*(int *)(in_stack_00000020 + iVar1 + 0x138c) + 0x1c) == 0) {
          (**(code **)(*(int *)in_stack_00000020 + 0x1f0))();
        }
        pCVar6 = *(CPlugFileGPUV **)(in_stack_00000020 + iVar1 + 0x138c);
      }
      else {
        pCVar6 = (CPlugFileGPUV *)0x0;
      }
      pCVar2 = *(CPlugFileGPUP **)(in_stack_00000020 + local_4 * 4 + 0x14ec);
      CPlugShader::SetVertexShader((CPlugShader *)this_01,pCVar9,pCVar6);
      CPlugShader::SetPixelShader((CPlugShader *)this_01,pCVar9,pCVar2);
      if (pCVar9 != (CPlugShaderPass *)0x0) {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_01 + 0x2c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar9,
                            in_stack_ffffffe8);
        in_stack_ffffffe8 = 1;
        CPlugShaderPass::SetBlending
                  (*(CPlugShaderPass **)pSVar7,(CPlugShaderPass *)0x1,1,in_stack_ffffffec);
      }
      uVar4 = in_stack_00000028 - local_4;
      pCVar9 = pCVar9 + 1;
      in_stack_00000028 = uVar4;
    } while (pCVar9 < in_stack_00000024);
  }
  ExceptionList = param_4;
  return (CPlugShaderApply *)this_01;
}
}

// =================================================
// Function: BuildFrameRecurse
// =================================================
void __cdecl
BuildFrameRecurse(SBuildPageParams *param_1,CGameManialinkPage *param_2,TiXmlElement *param_3,
                 CControlFrame *param_4,SManialinkFormat *param_5,SDico *param_6)
{
{
  TiXmlNode *pTVar1;
  TiXmlElement *this;
  char *pcVar2;
  CControlFrame *pCVar3;
  CControlQuad *pCVar4;
  int iVar5;
  TiXmlElement *unaff_EBX;
  CControlBase *unaff_EBP;
  TiXmlElement *unaff_ESI;
  char *pcVar6;
  char *unaff_EDI;
  char *pcVar7;
  bool bVar8;
  CGameManialinkPage *in_stack_00000020;
  TiXmlElement *pTVar9;
  TiXmlElement *pTVar10;
  CControlStyleSheet *pCVar11;
  TiXmlElement *pTVar12;
  undefined4 local_44;
  undefined4 local_40;
  SManialinkFormat local_3c [48];
  void *local_c;
  CMwNod *pCStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  pCStack_8 = (CMwNod *)&LAB_00ac0db8;
  local_c = ExceptionList;
  pTVar1 = (TiXmlNode *)(DAT_00cca150 ^ (uint)&stack0xffffff8c);
  ExceptionList = &local_c;
  SManialinkFormat::SManialinkFormat(&local_44,param_5);
  local_4 = (void *)0x0;
  this = TiXmlNode::FirstChildElement((TiXmlNode *)param_3,pTVar1,unaff_EDI);
  do {
    if (this == (TiXmlElement *)0x0) {
      if (pCStack_8 != (CMwNod *)0x0) {
        CMwNod::MwRelease(pCStack_8,(CMwNod *)unaff_ESI);
      }
      ExceptionList = local_4;
      return;
    }
    pcVar2 = (char *)(*(int *)(this + 0x20) + 8);
    iVar5 = 6;
    bVar8 = true;
    pcVar6 = pcVar2;
    pcVar7 = "frame";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      pCVar3 = ElemCreateFrame(unaff_ESI);
      BuildFrameRecurse((SBuildPageParams *)param_3,(CGameManialinkPage *)param_4,this,pCVar3,
                        local_3c,(SDico *)in_stack_00000020);
      goto LAB_00720fa9;
    }
    iVar5 = 7;
    bVar8 = true;
    pcVar6 = pcVar2;
    pcVar7 = "format";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      ElemModifyManialinkFormat
                (this,*(CControlStyleSheet **)(param_3 + 0xc),(SManialinkFormat *)unaff_ESI);
    }
    else {
      iVar5 = 6;
      bVar8 = true;
      pcVar6 = pcVar2;
      pcVar7 = "label";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (bVar8) {
        pTVar12 = this;
        ElemCreateLabel(this,(SBuildPageParams *)param_3,(CGameManialinkPage *)param_4,
                        (SDico *)in_stack_00000020);
        pTVar9 = *(TiXmlElement **)(param_3 + 0xc);
        pCVar11 = (CControlStyleSheet *)local_3c;
        pTVar10 = this;
        ControlTextSetStyle((CControlBase *)this,pTVar9,pCVar11,(SManialinkFormat *)pTVar12);
        FrameAddControl((CControlFrame *)pTVar10,(CControlBase *)pTVar9,(TiXmlElement *)pCVar11);
        ControlSetSizeAndAlign
                  ((CControlBase *)this,(TiXmlElement *)0x0,(GmVec2 *)0x0,(EAlignHorizontal)pTVar10,
                   (EAlignVertical)pTVar9,(int)pCVar11);
      }
      else {
        iVar5 = 6;
        bVar8 = true;
        pcVar6 = pcVar2;
        pcVar7 = "entry";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar8 = *pcVar6 == *pcVar7;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar8);
        if (bVar8) {
          pCVar3 = param_4;
          ElemCreateEntry((TiXmlElement *)param_4,(CGameManialinkPage *)unaff_ESI);
          pTVar9 = *(TiXmlElement **)(param_3 + 0xc);
          pCVar11 = (CControlStyleSheet *)local_3c;
          pTVar10 = this;
          ControlTextSetStyle((CControlBase *)this,pTVar9,pCVar11,(SManialinkFormat *)pCVar3);
          ControlSetSizeAndAlign
                    ((CControlBase *)this,(TiXmlElement *)0x0,(GmVec2 *)0x0,
                     (EAlignHorizontal)pTVar10,(EAlignVertical)pTVar9,(int)pCVar11);
        }
        else {
          iVar5 = 10;
          bVar8 = true;
          pcVar6 = pcVar2;
          pcVar7 = "fileentry";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar8 = *pcVar6 == *pcVar7;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if (bVar8) {
            pTVar12 = this;
            ElemCreateFileEntry(this,(CGameManialinkPage *)param_4);
            pTVar9 = *(TiXmlElement **)(param_3 + 0xc);
            pCVar11 = (CControlStyleSheet *)local_3c;
            pTVar10 = this;
            ControlTextSetStyle((CControlBase *)this,pTVar9,pCVar11,(SManialinkFormat *)pTVar12);
            ControlSetSizeAndAlign
                      ((CControlBase *)this,(TiXmlElement *)0x0,(GmVec2 *)0x0,
                       (EAlignHorizontal)pTVar10,(EAlignVertical)pTVar9,(int)pCVar11);
          }
          else {
            iVar5 = 5;
            bVar8 = true;
            pcVar6 = pcVar2;
            pcVar7 = "quad";
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar8 = *pcVar6 == *pcVar7;
              pcVar6 = pcVar6 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar8);
            if (bVar8) {
              pCVar4 = ElemCreateQuad(this,(SBuildPageParams *)param_4,in_stack_00000020,
                                      (SDico *)unaff_ESI);
              pTVar9 = this;
              pTVar10 = param_3;
              QuadSetStyle(this,(CControlBase *)pCVar4,(SBuildPageParams *)param_3,local_3c,
                           (SDico *)in_stack_00000020);
              local_44 = 0x3f800000;
              local_40 = 0x3f800000;
              ControlSetSizeAndAlign
                        ((CControlBase *)this,(TiXmlElement *)0x0,(GmVec2 *)0x0,
                         (EAlignHorizontal)pTVar9,(EAlignVertical)pCVar4,(int)pTVar10);
            }
            else {
              if (*(int *)(param_3 + 0x10) == 0) goto LAB_00720fb7;
              iVar5 = 6;
              bVar8 = true;
              pcVar6 = pcVar2;
              pcVar7 = "audio";
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar8 = *pcVar6 == *pcVar7;
                pcVar6 = pcVar6 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar8);
              if (!bVar8) {
                iVar5 = 6;
                bVar8 = true;
                pcVar6 = "video";
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar8 = *pcVar2 == *pcVar6;
                  pcVar2 = pcVar2 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (bVar8);
                if (!bVar8) goto LAB_00720fb7;
              }
              ElemCreateMediaPlayer(this,(SBuildPageParams *)param_3,(SDico *)in_stack_00000020,0);
            }
          }
        }
LAB_00720fa9:
        FrameAddControl((CControlFrame *)unaff_ESI,unaff_EBP,unaff_EBX);
      }
    }
LAB_00720fb7:
    this = TiXmlNode::NextSiblingElement((TiXmlNode *)this,(TiXmlNode *)unaff_ESI,(char *)unaff_EBP)
    ;
  } while( true );
}
}

// =================================================
// Function: CFastBuffer_AddElems
// =================================================
uchar * __cdecl
CFastBuffer_AddElems(CFastBuffer<unsigned_char> *param_1,uchar *param_2,ulong param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  ulong unaff_EDI;
  int iVar5;
  int in_stack_00000010;
  ulong extraout_var;
  ulong uVar6;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_ESI);
  uVar6 = extraout_var;
  CFastBuffer<struct_CPlugVisual::SSkinIndex>::AllocSetCount
            (param_1,(CFastBuffer<class_GxVertex2> *)(pCVar1 + in_stack_00000010),unaff_EBP);
  pCVar4 = pCVar1;
  if (in_stack_00000010 != 0) {
    iVar5 = in_stack_00000010 - (int)pCVar1;
    do {
      pSVar2 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[](param_1,pCVar1,unaff_EDI);
      pSVar3 = (SCasterCat *)(pCVar1 + iVar5);
      pCVar1 = pCVar1 + 1;
      in_stack_00000010 = in_stack_00000010 + -1;
      *pSVar2 = *pSVar3;
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2;
    } while (in_stack_00000010 != 0);
  }
  pSVar3 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[](param_1,pCVar4,uVar6);
  return (uchar *)pSVar3;
}
}

// =================================================
// Function: CFastBuffer_ArchiveElems<unsigned_char>
// =================================================
void __cdecl
CFastBuffer_ArchiveElems<unsigned_char>
          (CFastBuffer<unsigned_char> *param_1,CClassicArchive *param_2)
{
{
  void *pvVar1;
  ulong unaff_ESI;
  
  pvVar1 = (void *)CFastBuffer_GetElemsByteSize<unsigned_char>(param_1);
  CClassicArchive::DoData(param_2,*(CNetNod_CheckedArchive **)(param_1 + 4),pvVar1,unaff_ESI);
  return;
}
}

// =================================================
// Function: CFastBuffer_GetElemsByteSize<unsigned_char>
// =================================================
ulong __cdecl CFastBuffer_GetElemsByteSize<unsigned_char>(CFastBuffer<unsigned_char> *param_1)
{
{
  ulong uVar1;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (param_1,(CFastBuffer<class_CCrystalFace*> *)param_1);
  return uVar1;
}
}

// =================================================
// Function: CFastBuffer_WriteElseRead
// =================================================
void __cdecl
CFastBuffer_WriteElseRead
          (CFastBuffer<unsigned_char> *param_1,int param_2,ulong param_3,uchar *param_4,
          ulong param_5)
{
{
  SCasterCat *pSVar1;
  uint unaff_retaddr;
  
  if (param_2 != 0) {
    CFastBuffer_AddElems(param_1,param_4,param_5);
    return;
  }
  pSVar1 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                     (param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3,param_5);
  _memcpy((void *)param_5,pSVar1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CFastBuffer_WriteElseRead<char>
// =================================================
void __cdecl
CFastBuffer_WriteElseRead<char>
          (CFastBuffer<unsigned_char> *param_1,int param_2,ulong param_3,char *param_4)
{
{
  CFastBuffer_WriteElseRead(param_1,param_2,param_3,(uchar *)param_4,1);
  return;
}
}

// =================================================
// Function: CFastBuffer_WriteElseRead<float>
// =================================================
void __cdecl
CFastBuffer_WriteElseRead<float>
          (CFastBuffer<unsigned_char> *param_1,int param_2,ulong param_3,float *param_4)
{
{
  CFastBuffer_WriteElseRead(param_1,param_2,param_3,(uchar *)param_4,4);
  return;
}
}

// =================================================
// Function: CFastBuffer_WriteElseRead<short>
// =================================================
void __cdecl
CFastBuffer_WriteElseRead<short>
          (CFastBuffer<unsigned_char> *param_1,int param_2,ulong param_3,short *param_4)
{
{
  CFastBuffer_WriteElseRead(param_1,param_2,param_3,(uchar *)param_4,2);
  return;
}
}

// =================================================
// Function: CFastString_GetDriverVersion
// =================================================
void __cdecl CFastString_GetDriverVersion(CFastString *param_1,uint64 *param_2)
{
{
  int in_ECX;
  
  CFastString::Format((CFastString *)(*(uint *)(in_ECX + 4) >> 0x10),param_1,"%d.%d.%d.%d");
  return;
}
}

// =================================================
// Function: CMwNod_MwCheckThisRelease
// =================================================
int __cdecl CMwNod_MwCheckThisRelease(CMwNod *param_1)
{
{
  int iVar1;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00cca150 ^ 0xcbd778;
  ExceptionList = &local_14;
  local_8 = 0;
  iVar1 = InternalMwCheckThis((CMwNod *)(DAT_00cca150 ^ (uint)&stack0xfffffffc));
  if (iVar1 == 0) {
    ExceptionList = local_14;
    return 0;
  }
  iVar1 = (**(code **)(*(int *)param_1 + 0xc))();
  if (iVar1 != -1) {
    iVar1 = (**(code **)(*(int *)param_1 + 0x10))(0x1001000);
    if (iVar1 != 0) {
      ExceptionList = local_14;
      return 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}
}

// =================================================
// Function: CMwTimer_CalibrateEnd_ShouldSwitchOff
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl CMwTimer_CalibrateEnd_ShouldSwitchOff(void)
{
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  DWORD DVar4;
  DWORD DVar5;
  CPlugFileGpuBuilder *pCVar6;
  CPlugFileGpuBuilder *pCVar7;
  undefined *puVar8;
  int iVar9;
  float fVar10;
  CPlugFileGpuBuilder *unaff_ESI;
  int iVar11;
  SSystemTime *unaff_EDI;
  int iVar12;
  undefined2 in_FPUControlWord;
  float10 fVar13;
  int64 iVar14;
  int64 iVar15;
  undefined4 uStack00000004;
  undefined *in_stack_00000008;
  void *in_stack_0000001c;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  char *pcVar19;
  char *pcVar20;
  char *pcVar21;
  char *in_stack_ffffffb4;
  CPlugFileGpuBuilder *in_stack_ffffffb8;
  undefined2 in_stack_ffffffbc;
  char *pcVar22;
  char *pcVar23;
  CPlugFileGpuBuilder *pCVar24;
  char *pcVar25;
  char *local_2c;
  float local_1c;
  undefined *local_18;
  LARGE_INTEGER local_14;
  void *local_c;
  undefined1 *puStack_8;
  float local_4;
  
  local_4 = -NAN;
  puStack_8 = &LAB_00a82fb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  SSystemTime::SSystemTime(&local_14,(SSystemTime *)(DAT_00cca150 ^ (uint)&stack0xffffffac));
  SSystemTime::SetFromSystemTime(&local_14.s.HighPart,unaff_EDI);
  DVar4 = timeGetTime();
  DVar5 = GetTickCount();
  QueryPerformanceCounter(&local_14);
  iVar9 = local_14.s.LowPart - (int)lpPerformanceCount_00d55720;
  fVar10 = (float)((local_14.s.HighPart - _DAT_00d55724) -
                  (uint)(local_14.s.LowPart < lpPerformanceCount_00d55720));
  iVar14 = SSystemTime::GetT2SubT1InMilliseconds
                     ((SSystemTime *)&DAT_00d5573c,(SSystemTime *)&local_c);
  iVar11 = DVar4 - _DAT_00d556d4;
  iVar12 = DVar5 - _DAT_00d556d0;
  iVar15 = CMwProfiler::GetCPUFrequency();
  local_1c = 0.0;
  local_18 = PTR_DAT_00bbf7d8;
  pCVar7 = (CPlugFileGpuBuilder *)(float)((float10)CONCAT44(fVar10,iVar9) / (float10)iVar15);
  fVar13 = (float10)_DAT_00b30a18;
  pCVar24 = (CPlugFileGpuBuilder *)(float)((float10)iVar11 * fVar13);
  pcVar23 = (char *)(float)(fVar13 * (float10)iVar12);
  uStack00000004 = 0;
  fVar3 = (float)_DAT_00c418d8;
  pcVar21 = (char *)(longlong)ROUND((float)pCVar7 * fVar3);
  pcVar20 = ", PerfCounter = ";
  pcVar19 = (char *)(longlong)ROUND((float)pCVar24 * fVar3);
  pcVar18 = ", Mulimedia = ";
  pcVar17 = (char *)(longlong)ROUND((float)pcVar23 * fVar3);
  pcVar16 = ", GetTickCount = ";
  pcVar22 = (char *)CONCAT22(in_FPUControlWord,in_stack_ffffffbc);
  local_2c = (char *)(longlong)ROUND(fVar3 * (float)((float10)iVar14 * fVar13));
  pcVar25 = pcVar17;
  pCVar6 = CFastString::operator<<
                     ((CFastString *)&local_1c,(CPlugFileGpuBuilder *)"[Timer] SystemTime = ",
                      local_2c);
  pCVar6 = CFastString::operator<<((CFastString *)pCVar6,(CPlugFileGpuBuilder *)pcVar16,pcVar17);
  pCVar6 = CFastString::operator<<((CFastString *)pCVar6,(CPlugFileGpuBuilder *)pcVar18,pcVar19);
  pCVar6 = CFastString::operator<<((CFastString *)pCVar6,(CPlugFileGpuBuilder *)pcVar20,pcVar21);
  pCVar6 = CFastString::operator<<((CFastString *)pCVar6,unaff_ESI,in_stack_ffffffb4);
  pCVar6 = CFastString::operator<<((CFastString *)pCVar6,in_stack_ffffffb8,pcVar22);
  pCVar7 = CFastString::operator<<((CFastString *)pCVar6,pCVar7,pcVar23);
  CFastString::operator<<((CFastString *)pCVar7,pCVar24,pcVar25);
  local_c = (void *)ABS(fVar10 - local_1c);
  if ((local_4 < (float)local_c) &&
     (fVar3 = ABS((float)local_18 - local_1c), bVar1 = fVar3 < local_4, bVar2 = fVar3 == local_4,
     local_4 = fVar3, bVar1 != bVar2)) {
    if (in_stack_00000008 != PTR_DAT_00bbf7d8) {
      puVar8 = in_stack_00000008 + -1;
      if ((in_stack_00000008[-1] & 0x80) != 0) {
        puVar8 = in_stack_00000008 + -4;
      }
      operator_delete__(puVar8);
    }
    ExceptionList = in_stack_0000001c;
    return 1;
  }
  if (in_stack_00000008 != PTR_DAT_00bbf7d8) {
    puVar8 = in_stack_00000008 + -1;
    if ((in_stack_00000008[-1] & 0x80) != 0) {
      puVar8 = in_stack_00000008 + -4;
    }
    operator_delete__(puVar8);
  }
  ExceptionList = in_stack_0000001c;
  return 0;
}
}

// =================================================
// Function: CMwTimer_CalibrateStart
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CMwTimer_CalibrateStart(void)
{
{
  BOOL BVar1;
  SSystemTime *unaff_retaddr;
  
  SSystemTime::SetFromSystemTime(&DAT_00d5573c,unaff_retaddr);
  _DAT_00d556d4 = timeGetTime();
  _DAT_00d556d0 = GetTickCount();
  BVar1 = QueryPerformanceCounter((LARGE_INTEGER *)&lpPerformanceCount_00d55720);
  if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  return;
}
}

// =================================================
// Function: CPlugTree_CanBePacked
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
CPlugTree_CanBePacked
          (CPlugTree *param_1,CPlugShader **param_2,CPlugMaterial **param_3,
          CPlugVisualIndexedTriangles **param_4,SFlags **param_5)
{
{
  int *piVar1;
  float fVar2;
  undefined4 *in_EAX;
  int iVar3;
  CPlugTree *this;
  int *in_ECX;
  int *in_EDX;
  CPlugTreeVisualMip *pCVar4;
  float unaff_EDI;
  ulong uVar5;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  
  iVar3 = *(int *)(param_1 + 0x94);
  *in_ECX = iVar3;
  if ((((iVar3 != 0) && ((*(uint *)(iVar3 + 0x20) & 0xc00000) == 0)) &&
      (iVar3 = *(int *)(param_1 + 0x98), *in_EDX = iVar3, iVar3 != 0)) &&
     (*param_2 = (CPlugShader *)(param_1 + 0x9c), (*(uint *)(param_1 + 0x9c) & 0x1000) == 0)) {
    piVar1 = *(int **)(param_1 + 0x90);
    *in_EAX = piVar1;
    pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x901e000;
    iVar3 = (**(code **)(*piVar1 + 0x10))();
    if (iVar3 != 0) {
      return 1;
    }
    if (DAT_00d6e924 != 0) {
      uVar5 = 0x9010000;
      iVar3 = (**(code **)(*(int *)*in_EAX + 0x10))();
      if ((iVar3 != 0) &&
         (this = CPlugTree::GetFirstParentOfClassId(param_1,(CPlugTree *)0x9015000,uVar5),
         this != (CPlugTree *)0x0)) {
        uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xac,pCVar6);
        for (pCVar4 = (CPlugTreeVisualMip *)(uVar5 - 1); pCVar4 != (CPlugTreeVisualMip *)0xffffffff;
            pCVar4 = pCVar4 + -1) {
          fVar2 = (float)(int)pCVar4;
          if ((int)pCVar4 < 0) {
            fVar2 = fVar2 + _DAT_00c418d0;
          }
          CPlugTreeVisualMip::SetLevelFarZ
                    ((CPlugTreeVisualMip *)this,pCVar4,
                     (ulong)((fVar2 * (float)_DAT_00b50898 + (float)_DAT_00b2c188) *
                            (float)_DAT_00b2f710),unaff_EDI);
        }
      }
    }
  }
  return 0;
}
}

// =================================================
// Function: CPlugTree_PackShaderRecur
// =================================================
void __cdecl CPlugTree_PackShaderRecur(CPlugTree *param_1,ulong *param_2)
{
{
  uint uVar1;
  uint uVar2;
  CPlugShader *pCVar3;
  CPlugShader *pCVar4;
  uint uVar5;
  int iVar6;
  CPlugTree *pCVar7;
  CPlugTree *pCVar8;
  GmMat43 *unaff_EBX;
  uint uVar9;
  undefined4 *puVar10;
  SFlags **unaff_EDI;
  GmIso3 *pGVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  GmFrustumIso4 *pGVar14;
  CPlugVisualIndexedTriangles **ppCVar15;
  uint uVar16;
  uint uStack_e0;
  CPlugTree *pCStack_d4;
  uint uStack_cc;
  CPlugShader *pCStack_c4;
  undefined4 uStack_c0;
  undefined4 *puStack_bc;
  uint uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  CPlugShader *pCStack_9c;
  CPlugTree *pCStack_98;
  undefined4 auStack_94 [12];
  undefined4 auStack_64 [12];
  GmIso3 aGStack_34 [52];
  
  uVar5 = (**(code **)(*(int *)param_1 + 0x7c))();
  ppCVar15 = (CPlugVisualIndexedTriangles **)0x9015000;
  iVar6 = (**(code **)(*(int *)param_1 + 0x10))();
  uVar9 = uVar5;
  if ((iVar6 == 0) && (uVar16 = 0, uVar5 != 0)) {
    do {
      pCVar7 = (CPlugTree *)(**(code **)(*(int *)param_1 + 0x80))(uVar16);
      iVar6 = CPlugTree_CanBePacked
                        (pCVar7,&pCStack_c4,(CPlugMaterial **)unaff_EBX,ppCVar15,unaff_EDI);
      pCVar3 = pCStack_c4;
      if ((iVar6 != 0) && (uVar9 = 0, uVar16 != 0)) {
LAB_00854320:
        pCVar8 = (CPlugTree *)(**(code **)(*(int *)param_1 + 0x80))(uVar9);
        iVar6 = CPlugTree_CanBePacked
                          (pCVar8,&pCStack_9c,(CPlugMaterial **)unaff_EBX,ppCVar15,unaff_EDI);
        pCVar4 = pCStack_9c;
        if (((iVar6 == 0) || (uStack_cc != uVar5)) || (pCStack_d4 == pCStack_98)) goto LAB_0085438e;
        uVar1 = *(uint *)pCStack_9c;
        uVar2 = *(uint *)pCVar3;
        if ((((((uVar1 ^ uVar2) & 8) != 0) || (((uVar1 ^ uVar2) & 0x4000) != 0)) ||
            ((uVar2 & 4) != 0)) || ((uVar1 & 4) != 0)) goto LAB_0085438e;
        *(int *)param_1 = *(int *)param_1 + 1;
        uStack_b4 = 0x3f800000;
        uStack_b0 = 0x3f800000;
        uStack_a8 = 0;
        uStack_a4 = 0;
        uStack_ac = 0;
        puStack_bc = auStack_94;
        uStack_c0 = uStack_a0;
        uStack_b8 = uVar5;
        if (((byte)*pCVar3 & 4) == 0) {
          if (((byte)*pCStack_9c & 4) == 0) {
            GmIso4::SetIdentity(puStack_bc,unaff_EBX);
            goto LAB_00854476;
          }
          if (((byte)*pCVar3 & 4) == 0) {
            GmIso4::SetIdentity(auStack_64,unaff_EBX);
            goto LAB_0085442b;
          }
        }
        pCVar7 = pCVar7 + 0x5c;
        puVar10 = auStack_64;
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar10 = *(undefined4 *)pCVar7;
          pCVar7 = pCVar7 + 4;
          puVar10 = puVar10 + 1;
        }
LAB_0085442b:
        if (((byte)*pCVar4 & 4) == 0) {
          GmIso4::SetIdentity(aGStack_34,unaff_EBX);
        }
        else {
          pCVar7 = pCVar8 + 0x5c;
          pGVar11 = aGStack_34;
          for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined4 *)pGVar11 = *(undefined4 *)pCVar7;
            pCVar7 = pCVar7 + 4;
            pGVar11 = pGVar11 + 4;
          }
        }
        puVar10 = auStack_64;
        puVar12 = auStack_94;
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        GmIso4::MultInverse(auStack_94,aGStack_34,(GmIso3 *)unaff_EBX);
LAB_00854476:
        pCVar3 = pCStack_c4;
        pGVar14 = (GmFrustumIso4 *)&puStack_bc;
        (**(code **)(*(uint *)pCStack_c4 + 0x144))();
        CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pCVar3 + 0x20,pGVar14);
        unaff_EBX = (GmMat43 *)0x0;
        uVar13 = 0;
        CPlugTree::SetVisual(pCStack_d4,(CVisionVisualKeeper *)0x0,(CPlugVisual *)0x0);
        iVar6 = (**(code **)(*(int *)pCStack_d4 + 0x7c))(uVar13);
        if (iVar6 == 0) {
          (**(code **)(*(int *)param_1 + 0x9c))(uVar16);
          uVar16 = uVar16 - 1;
          uStack_e0 = uStack_e0 - 1;
        }
      }
LAB_008544d5:
      uVar16 = uVar16 + 1;
      uVar9 = uStack_e0;
    } while (uVar16 < uStack_e0);
  }
  uVar5 = 0;
  if (uVar9 != 0) {
    do {
      pCVar7 = param_1;
      pCVar8 = (CPlugTree *)(**(code **)(*(int *)param_1 + 0x80))(uVar5);
      CPlugTree_PackShaderRecur(pCVar8,(ulong *)pCVar7);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar9);
  }
  return;
LAB_0085438e:
  uVar9 = uVar9 + 1;
  if (uVar16 <= uVar9) goto LAB_008544d5;
  goto LAB_00854320;
}
}

// =================================================
// Function: CSystemEngine__CheckCorruptedFiles
// =================================================
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl CSystemEngine__CheckCorruptedFiles(CSystemFids *param_1)
{
{
  CSystemFile *pCVar1;
  int iVar2;
  long lVar3;
  CFastStringBase<wchar_t> *extraout_EAX;
  CFastStringBase<wchar_t> *pCVar4;
  CPlugFileGpuBuilder *pCVar5;
  undefined *puVar6;
  CPlugFileGpuBuilder *pCVar7;
  int *in_ECX;
  CClassicBufferCrypted *unaff_EBX;
  void *in_stack_00000014;
  undefined1 uStack00000018;
  CPlugFileSnd *pCVar8;
  SOldChars *pSVar9;
  ulong uVar10;
  CClassicLog *pCVar11;
  SStringParam *pSVar12;
  SStringParam *pSVar13;
  char *pcVar14;
  wchar_t *pwVar15;
  char *pcVar16;
  CFastStringBase<wchar_t> *pCVar17;
  CPlugFileGpuBuilder *pCVar18;
  LPCSTR *ppCVar19;
  char *pcVar20;
  char *pcVar21;
  CPlugFileGpuBuilder *in_stack_ffffef90;
  char *pcVar22;
  char *in_stack_ffffef9c;
  CSystemFile *in_stack_ffffefa0;
  char *pcStack_105c;
  undefined4 uStack_1058;
  undefined4 local_1054;
  char *local_1050;
  CPlugFileGpuBuilder *pCStack_104c;
  undefined *puStack_1048;
  undefined *puStack_1044;
  CPlugFileGpuBuilder *pCStack_1040;
  LPCWSTR pWStack_103c;
  undefined *puStack_1038;
  LPCWSTR pWStack_1034;
  undefined *puStack_1028;
  CSystemFile aCStack_101c [4096];
  undefined4 uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  undefined1 uStack_8;
  
  puStack_10 = &LAB_00a81452;
  local_14 = ExceptionList;
  uStack_1c = 0x41d98f;
  pCVar1 = (CSystemFile *)(DAT_00cca150 ^ (uint)&stack0xffffef80);
  ExceptionList = &local_14;
  local_1054 = 0;
  local_1050 = PTR_DAT_00bbf7dc;
  pSVar12 = (SStringParam *)0x0;
  pSVar13 = (SStringParam *)&local_1054;
  local_c = 0;
  (**(code **)(*in_ECX + 0x98))();
  local_1054 = uStack_1058;
  local_14 = (void *)CONCAT31(local_14._1_3_,1);
  local_1050 = pcStack_105c;
  pCStack_104c = (CPlugFileGpuBuilder *)0x0;
  CFastStringInt::SetString(&stack0xffffef94,(CFastStringInt *)&local_1054,pSVar13);
  pcVar20 = "CorruptedFiles.txt";
  pcVar21 = &DAT_00000012;
  CFastStringInt::Concat(&stack0xffffef98,(CFastStringInt *)&stack0xffffef88,pSVar12);
  CSystemFile::CSystemFile((CSystemFile *)&pCStack_1040,pCVar1);
  uStack_8 = 2;
  iVar2 = CSystemManagerFile::IsFileExists((CFastStringInt *)&stack0xffffefa0);
  if (iVar2 != 0) {
    pSVar13 = (SStringParam *)0x0;
    pCVar11 = (CClassicLog *)0x1;
    uVar10 = 0;
    pSVar9 = (SOldChars *)0x1;
    pCVar8 = (CPlugFileSnd *)&stack0xffffefa0;
    lVar3 = CSystemFile::Open((_D3DXINCLUDE_TYPE)pCVar8,(char *)0x1,(void *)0x0,(void **)0x1,
                              (uint *)0x0);
    if (lVar3 != 0) {
      CSystemFile::GetLength((CSystemFile *)&local_1054,pCVar8);
      pCVar4 = (CFastStringBase<wchar_t> *)0x0;
      pwVar15 = (wchar_t *)0x0;
      uStack_1c = CONCAT31(uStack_1c._1_3_,3);
      pCVar17 = (CFastStringBase<wchar_t> *)PTR_DAT_00bbf7d8;
      if (extraout_EAX != (CFastStringBase<wchar_t> *)0x0) {
        CFastStringBase<char>::AllocAtLeast
                  ((CFastStringBase<char> *)&stack0xffffef7c,extraout_EAX,1,0,pSVar9);
        unaff_EBX[(int)extraout_EAX] = (CClassicBufferCrypted)0x0;
        pCVar4 = extraout_EAX;
        pCVar17 = extraout_EAX;
      }
      CSystemFile::Read((CSystemFile *)&pCStack_104c,unaff_EBX,pCVar4,uVar10);
      CSystemFile::Close((CSystemFile *)&puStack_1048,pCVar11);
      in_stack_ffffefa0 = (CSystemFile *)0x0;
      pcStack_105c = PTR_DAT_00bbf7dc;
      puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,4);
      local_1050 = pcVar21;
      pCStack_104c = (CPlugFileGpuBuilder *)pcVar20;
      CFastStringInt::SetString(&stack0xffffefa0,(CFastStringInt *)&local_1050,pSVar13);
      pcVar22 = (char *)0x0;
      local_c = CONCAT31(local_c._1_3_,5);
      pCVar7 = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7dc;
      iVar2 = CSystemManagerFile::IsFileExists((CFastStringInt *)&pcStack_105c);
      if (iVar2 != 0) {
        iVar2 = CSystemFileName::GetRelativeName
                          ((CFastStringInt *)&pcStack_105c,(CFastStringInt *)&local_1054,
                           (CFastStringInt *)&stack0xffffef94);
        if (iVar2 != 0) {
          SStringParamInt::SStringParamInt
                    (&pCStack_104c,(SStringParamInt *)L"CorruptedFiles\\",pwVar15);
          CFastStringInt::ConcatBefore
                    (&stack0xffffef98,(CFastStringInt *)&puStack_1048,(SStringParamInt *)pCVar17);
          puStack_1044 = puStack_1048;
          pCStack_1040 = pCStack_104c;
          pWStack_103c = (LPCWSTR)0x0;
          CFastStringInt::ConcatBefore
                    (&stack0xffffef9c,(CFastStringInt *)&puStack_1044,(SStringParamInt *)unaff_EBX);
          if (DAT_00d71e54 != 0) {
            DAT_00d71e54 = 0;
            *DAT_00d71e58 = 0;
          }
          ppCVar19 = &lpOutputString_00b2bcc4;
          pCVar18 = (CPlugFileGpuBuilder *)&DAT_00b2ec78;
          pcVar16 = &stack0xffffefa0;
          pcVar14 = "\" to \"";
          pCVar5 = CFastString::operator<<
                             ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"Moving \"",
                              (char *)&local_1050);
          pCVar5 = CFastString::operator<<
                             ((CFastString *)pCVar5,(CPlugFileGpuBuilder *)pcVar14,pcVar16);
          pCVar5 = CFastString::operator<<((CFastString *)pCVar5,pCVar18,(char *)ppCVar19);
          pCVar5 = CFastString::operator<<
                             ((CFastString *)pCVar5,(CPlugFileGpuBuilder *)pcVar20,pcVar21);
          pCVar5 = CFastString::operator<<((CFastString *)pCVar5,in_stack_ffffef90,pcVar22);
          CFastString::operator<<((CFastString *)pCVar5,pCVar7,in_stack_ffffef9c);
          CClassicLog::AddLogStringInFile();
          CSystemManagerFile::MakeDir((CFastStringInt *)&puStack_1048);
          SetFileAttributesW(pWStack_1034,0x80);
          iVar2 = CSystemManagerFile::MoveFileW
                            ((CFastStringInt *)&puStack_1038,(CFastStringInt *)&puStack_1048,0);
          if (iVar2 != 0) {
            SetFileAttributesW(pWStack_103c,0x80);
            DeleteFileW(pWStack_103c);
          }
        }
      }
      if (puStack_1044 != PTR_DAT_00bbf7dc) {
        if ((puStack_1044[-1] & 0x80) == 0) {
          puVar6 = puStack_1044 + -2;
        }
        else {
          puVar6 = puStack_1044 + -4;
        }
        operator_delete__(puVar6);
        puStack_1048 = (undefined *)0x0;
        puStack_1044 = PTR_DAT_00bbf7dc;
      }
      if (pWStack_1034 != (LPCWSTR)PTR_DAT_00bbf7dc) {
        if ((*(byte *)((int)pWStack_1034 + -1) & 0x80) == 0) {
          pWStack_1034 = pWStack_1034 + -1;
        }
        else {
          pWStack_1034 = pWStack_1034 + -2;
        }
        operator_delete__(pWStack_1034);
        puStack_1038 = (undefined *)0x0;
        pWStack_1034 = (LPCWSTR)PTR_DAT_00bbf7dc;
      }
      if (pCStack_104c != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
        pCVar7 = pCStack_104c + -1;
        if (((byte)pCStack_104c[-1] & 0x80) != 0) {
          pCVar7 = pCStack_104c + -4;
        }
        operator_delete__(pCVar7);
      }
    }
  }
  uStack00000018 = 1;
  CSystemFile::~CSystemFile(aCStack_101c,in_stack_ffffefa0);
  if (puStack_1038 != PTR_DAT_00bbf7dc) {
    if ((puStack_1038[-1] & 0x80) == 0) {
      puVar6 = puStack_1038 + -2;
    }
    else {
      puVar6 = puStack_1038 + -4;
    }
    operator_delete__(puVar6);
    pWStack_103c = (LPCWSTR)0x0;
    puStack_1038 = PTR_DAT_00bbf7dc;
  }
  if (puStack_1028 != PTR_DAT_00bbf7dc) {
    if ((puStack_1028[-1] & 0x80) == 0) {
      puStack_1028 = puStack_1028 + -2;
    }
    else {
      puStack_1028 = puStack_1028 + -4;
    }
    operator_delete__(puStack_1028);
  }
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CSystemEngine__LoadGraphicPerformance
// =================================================
/* WARNING: Type propagation algorithm not settling */

ELoadGfxPerfResult __cdecl
CSystemEngine__LoadGraphicPerformance
          (CFastString *param_1,ulong *param_2,ulong *param_3,SSysGraphicPerformance *param_4)
{
{
  uint uVar1;
  SFastToken *pSVar2;
  int iVar3;
  undefined *puVar4;
  float *unaff_EDI;
  uint local_30;
  uint local_2c [4];
  undefined *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00a81868;
  local_c = ExceptionList;
  pSVar2 = (SFastToken *)(DAT_00cca150 ^ (uint)&stack0xffffffc4);
  ExceptionList = &local_c;
  local_2c[3] = 0;
  local_1c = PTR_DAT_00bbf7d8;
  local_2c[1] = 2;
  local_2c[2] = 0xffffffff;
  local_18 = 0;
  local_14 = 0;
  local_10 = &DAT_00b2ee68;
  local_4 = 0;
  iVar3 = String_GetNextNaturalHexa((CFastString *)&local_30,pSVar2,(ulong *)unaff_EDI);
  if (iVar3 == 0) {
    if (local_1c != PTR_DAT_00bbf7d8) {
      puVar4 = local_1c + -1;
      if ((local_1c[-1] & 0x80) != 0) {
        puVar4 = local_1c + -4;
      }
      operator_delete__(puVar4);
    }
    ExceptionList = local_c;
    return 2;
  }
  uVar1 = *param_2;
  if (uVar1 == 0) {
    *param_2 = local_30;
  }
  else {
    if (local_30 < uVar1) goto LAB_0041feaf;
    if (uVar1 < local_30) goto LAB_0041fed6;
  }
  iVar3 = String_GetNextNaturalHexa((CFastString *)local_2c,pSVar2,(ulong *)unaff_EDI);
  if (iVar3 != 0) {
    uVar1 = *param_3;
    if (uVar1 == 0) {
      *param_3 = local_2c[0];
    }
    else {
      if (local_2c[0] < uVar1) {
LAB_0041feaf:
        CGameMasterServer::SCriteria::~SCriteria(local_2c + 1,(SCriteria *)pSVar2);
        ExceptionList = local_8;
        return 1;
      }
      if (uVar1 < local_2c[0]) {
        CGameMasterServer::SCriteria::~SCriteria(local_2c + 1,(SCriteria *)pSVar2);
        ExceptionList = local_8;
        return 2;
      }
    }
    iVar3 = String_GetNextReal((CFastString *)param_4,pSVar2,unaff_EDI);
    if ((((((iVar3 != 0) &&
           (iVar3 = String_GetNextReal((CFastString *)(param_4 + 0x10),pSVar2,unaff_EDI), iVar3 != 0
           )) && (iVar3 = String_GetNextReal((CFastString *)(param_4 + 0x14),pSVar2,unaff_EDI),
                 iVar3 != 0)) &&
         ((iVar3 = String_GetNextReal((CFastString *)(param_4 + 0x18),pSVar2,unaff_EDI), iVar3 != 0
          && (iVar3 = String_GetNextReal((CFastString *)(param_4 + 0x1c),pSVar2,unaff_EDI),
             iVar3 != 0)))) &&
        ((iVar3 = String_GetNextReal((CFastString *)(param_4 + 0x20),pSVar2,unaff_EDI), iVar3 != 0
         && ((iVar3 = String_GetNextReal((CFastString *)(param_4 + 4),pSVar2,unaff_EDI), iVar3 != 0
             && (iVar3 = String_GetNextReal((CFastString *)(param_4 + 0xc),pSVar2,unaff_EDI),
                iVar3 != 0)))))) &&
       (iVar3 = String_GetNextReal((CFastString *)(param_4 + 8),pSVar2,unaff_EDI), iVar3 != 0)) {
      CGameMasterServer::SCriteria::~SCriteria(local_2c + 1,(SCriteria *)pSVar2);
      ExceptionList = local_8;
      return 0;
    }
  }
LAB_0041fed6:
  CGameMasterServer::SCriteria::~SCriteria(local_2c + 1,(SCriteria *)pSVar2);
  ExceptionList = local_8;
  return 2;
}
}

// =================================================
// Function: CSystemEngine__LogSystemInfos_Win32
// =================================================
void __cdecl CSystemEngine__LogSystemInfos_Win32(void)
{
{
  undefined *puVar1;
  undefined1 *puVar2;
  undefined4 uStack00000004;
  char *in_stack_ffffffa4;
  CFastString local_58 [4];
  undefined *local_54;
  CFastString local_50 [4];
  CFastString local_4c [4];
  undefined1 local_48 [60];
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a82f90;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastString::CFastString
            ((CFastString *)&stack0xffffffa4,(CFastString *)"GlobalMemoryStatus(Startup)",
             (char *)(DAT_00cca150 ^ (uint)&stack0xffffffa4));
  LogGlobalMemoryStatus((_MEMORYSTATUSEX *)&lpBuffer_00d556d8,local_58);
  if (local_54 != PTR_DAT_00bbf7d8) {
    puVar1 = local_54 + -1;
    if ((local_54[-1] & 0x80) != 0) {
      puVar1 = local_54 + -4;
    }
    operator_delete__(puVar1);
  }
  _memset(local_48,0,0x40);
  local_48._0_4_ = &DAT_00000040;
  GlobalMemoryStatusEx((LPMEMORYSTATUSEX)local_48);
  CFastString::CFastString(local_50,(CFastString *)"GlobalMemoryStatus(Now)",in_stack_ffffffa4);
  uStack00000004 = 1;
  LogGlobalMemoryStatus((_MEMORYSTATUSEX *)(local_48 + 4),local_4c);
  if ((undefined *)local_48._0_4_ != PTR_DAT_00bbf7d8) {
    puVar2 = (undefined1 *)(local_48._0_4_ + -1);
    if ((*(byte *)(local_48._0_4_ + -1) & 0x80) != 0) {
      puVar2 = (undefined1 *)(local_48._0_4_ + -4);
    }
    operator_delete__(puVar2);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CSystemFileName_ConvertToSystemName_AndCreate
// =================================================
void __cdecl
CSystemFileName_ConvertToSystemName_AndCreate(CFastStringInt *param_1,CFastString *param_2)
{
{
  CSystemFileName::ConvertToSystemName(param_1,param_2,1,2);
  return;
}
}

// =================================================
// Function: CSystemFile_testerror
// =================================================
int __cdecl CSystemFile_testerror(void *param_1,void *param_2)
{
{
  return 0;
}
}

// =================================================
// Function: CanBeEnabled
// =================================================
int __cdecl CanBeEnabled(CGameApp *param_1)
{
{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 0x118))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*unaff_ESI + 0x118))();
      if ((*(int *)(iVar1 + 0x234) != 0) && (*(int *)(unaff_ESI[0x1e] + 0x1c8) == 0)) {
        return 1;
      }
    }
  }
  return 0;
}
}

// =================================================
// Function: CheckAntiAlias
// =================================================
int __cdecl CheckAntiAlias(IDirect3D9 *param_1,ulong param_2,_D3DMULTISAMPLE_TYPE param_3)
{
{
  int *in_EAX;
  int iVar1;
  
  iVar1 = (**(code **)(*in_EAX + 0x2c))();
  return (uint)(-1 < iVar1);
}
}

// =================================================
// Function: CheckInstance
// =================================================
int __cdecl CheckInstance(void *param_1,ulong param_2)
{
{
  undefined4 *lp;
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  if (BVar1 == 0) {
    lp = *(undefined4 **)param_1;
    BVar1 = IsBadReadPtr(lp,4);
    if (BVar1 == 0) {
      BVar1 = IsBadCodePtr((FARPROC)*lp);
      return (uint)(BVar1 == 0);
    }
  }
  return 0;
}
}

// =================================================
// Function: CheckSupportCPUID
// =================================================
/* WARNING: Removing unreachable block (ram,0x00431cc5) */

int __cdecl CheckSupportCPUID(char *param_1)
{
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = cpuid_basic_info(0);
  uVar3 = *(undefined4 *)(iVar1 + 8);
  uVar2 = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)param_1 = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)(param_1 + 4) = uVar3;
  *(undefined4 *)(param_1 + 8) = uVar2;
  return 1;
}
}

// =================================================
// Function: CheckedStrCpy<unsigned_char>
// =================================================
int __cdecl CheckedStrCpy<unsigned_char>(wchar_t *param_1,uchar *param_2,ulong param_3)
{
{
  byte bVar1;
  byte *in_EAX;
  ushort *in_ECX;
  wchar_t *pwVar2;
  int iVar3;
  
  iVar3 = 0;
  pwVar2 = (wchar_t *)0x0;
  if (param_1 == (wchar_t *)0x0) {
    return 0;
  }
  do {
    bVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
    if (bVar1 == 0) {
      return iVar3;
    }
    if (bVar1 < 0x20) {
      if (((bVar1 == 9) || (bVar1 == 10)) || (bVar1 == 0xd)) goto LAB_00902fff;
    }
    else if (bVar1 != 0x7f) {
LAB_00902fff:
      *in_ECX = (ushort)bVar1;
      in_ECX = in_ECX + 1;
      iVar3 = iVar3 + 1;
    }
    pwVar2 = (wchar_t *)((int)pwVar2 + 1);
    if (param_1 <= pwVar2) {
      return iVar3;
    }
  } while( true );
}
}

// =================================================
// Function: CheckedStrCpy<wchar_t>
// =================================================
int __cdecl CheckedStrCpy<wchar_t>(wchar_t *param_1,wchar_t *param_2,ulong param_3)
{
{
  ushort uVar1;
  ushort *in_EAX;
  ushort *in_ECX;
  wchar_t *pwVar2;
  int iVar3;
  
  iVar3 = 0;
  pwVar2 = (wchar_t *)0x0;
  if (param_1 == (wchar_t *)0x0) {
    return 0;
  }
  do {
    uVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
    if (uVar1 == 0) {
      return iVar3;
    }
    if (uVar1 < 0x20) {
      if (((uVar1 == 9) || (uVar1 == 10)) || (uVar1 == 0xd)) goto LAB_00902f91;
    }
    else if (uVar1 != 0x7f) {
LAB_00902f91:
      *in_ECX = uVar1;
      in_ECX = in_ECX + 1;
      iVar3 = iVar3 + 1;
    }
    pwVar2 = (wchar_t *)((int)pwVar2 + 1);
    if (param_1 <= pwVar2) {
      return iVar3;
    }
  } while( true );
}
}

// =================================================
// Function: ClipTriggerConditionOk
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl ClipTriggerConditionOk(SGameCtnMediaTriggerZone *param_1,CGamePlayer *param_2)
{
{
  float fVar1;
  int iVar2;
  int in_ECX;
  int unaff_ESI;
  undefined2 in_FPUControlWord;
  ushort uVar3;
  float10 fVar4;
  undefined4 in_stack_fffffff4;
  undefined2 uVar5;
  longlong local_8;
  
  uVar5 = (undefined2)((uint)in_stack_fffffff4 >> 0x10);
  switch(*(undefined4 *)(unaff_ESI + 0x34)) {
  case 0:
    goto switchD_005ddbaf_caseD_0;
  case 1:
    fVar1 = (float)*(int *)(in_ECX + 0x44) * (float)_DAT_00b30a18;
    uVar3 = (ushort)(*(float *)(unaff_ESI + 0x38) < fVar1) << 8 |
            (ushort)(*(float *)(unaff_ESI + 0x38) == fVar1) << 0xe;
    break;
  case 2:
    if ((float)*(int *)(in_ECX + 0x44) * (float)_DAT_00b30a18 <= *(float *)(unaff_ESI + 0x38)) {
      return 0;
    }
    return 1;
  case 3:
    local_8 = (longlong)ROUND(*(float *)(unaff_ESI + 0x38));
    iVar2 = CFastArray<class_CGameMenuFrame*>::Find
                      ((void *)(in_ECX + 0x38),(CFastArray<class_GxTexCoordSet> *)&local_8,
                       (GxTexCoordSet *)CONCAT22(uVar5,in_FPUControlWord));
    return (uint)(iVar2 != -1);
  case 4:
    fVar4 = (float10)(**(code **)(**(int **)(*(int *)(in_ECX + 0x28) + 0x14) + 0x134))();
    uVar3 = (ushort)((float10)*(float *)(unaff_ESI + 0x38) < fVar4) << 8 |
            (ushort)((float10)*(float *)(unaff_ESI + 0x38) == fVar4) << 0xe;
    break;
  case 5:
    fVar4 = (float10)(**(code **)(**(int **)(*(int *)(in_ECX + 0x28) + 0x14) + 0x134))();
    if ((float10)*(float *)(unaff_ESI + 0x38) < fVar4) {
      return 1;
    }
    return 0;
  case 6:
    local_8 = (longlong)ROUND(*(float *)(unaff_ESI + 0x38));
    iVar2 = CFastArray<class_CGameMenuFrame*>::Find
                      ((void *)(in_ECX + 0x38),(CFastArray<class_GxTexCoordSet> *)&local_8,
                       (GxTexCoordSet *)CONCAT22(uVar5,in_FPUControlWord));
    return (uint)(iVar2 == -1);
  default:
    goto switchD_005ddbaf_default;
  }
  if (uVar3 != 0) {
switchD_005ddbaf_default:
    return 0;
  }
switchD_005ddbaf_caseD_0:
  return 1;
}
}

// =================================================
// Function: CompileInternal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __cdecl
CompileInternal(CPlugFileGPU *param_1,ulong param_2,STarget *param_3,EPlugGpuPipeline param_4,
               ID3DXBuffer **param_5,ID3DXBuffer **param_6,ID3DXConstantTable **param_7,
               CFastBuffer<struct_CPlugFileGPU::SDxDefine> *param_8)
{
{
  int iVar1;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar2;
  ulong uVar3;
  SLoadedLight *pSVar4;
  long extraout_EAX;
  undefined *puVar5;
  void *in_ECX;
  int *in_EDX;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<class_GxVertex2> *pCVar6;
  undefined *in_stack_00000024;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffffdc;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffffe0;
  undefined **ppuVar7;
  undefined4 local_18;
  undefined *local_14;
  int local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ade448;
  local_c = ExceptionList;
  pCVar2 = (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffcc);
  ExceptionList = &local_c;
  if (DAT_00d6f024 == 0) {
    CPlugFileVHlsl::LoadCommonVHlsl();
  }
  iVar1 = DAT_00d6f024;
  if (DAT_00d6f824 == 0) {
    CPlugFilePHlsl::LoadCommonPHlsl();
  }
  ppuVar7 = CPlugFileGpuInclude::vftable;
  local_14 = (undefined *)iVar1;
  local_10 = DAT_00d6f824;
  if ((_DAT_00d706b0 & 1) == 0) {
    _DAT_00d706b0 = _DAT_00d706b0 | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&DAT_00d706a4,pCVar2);
    _atexit(`long___cdecl_CompileInternal(class_CPlugFileGPU*,unsigned_long,struct_CPlugGpuCompileCache::STarget_const&,enum_EPlugGpuPipeline,struct_ID3DXBuffer*&,struct_ID3DXBuffer*&,struct_ID3DXConstantTable*&,class_CFastBuffer<struct_CPlugFileGPU::SDxDefine>_const&)'
            ::__l2::_dynamic_atexit_destructor_for__DxDefines__);
  }
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(in_ECX,unaff_EDI);
  pCVar6 = (CFastBuffer<class_GxVertex2> *)(uVar3 - 1);
  CFastBuffer<struct_CPlugModelMesh::SPoly>::AllocSetCount(&DAT_00d706a4,pCVar6,unaff_ESI);
  if (pCVar6 != (CFastBuffer<class_GxVertex2> *)0x0) {
    _memcpy(DAT_00d706a8,*(void **)((int)in_ECX + 4),(int)pCVar6 * 8);
  }
  local_18 = 0;
  local_14 = PTR_DAT_00bbf7d8;
  CFastString::Format((CFastString *)(uint)*(ushort *)(param_5 + 1),(CFastString *)&local_18,
                      "(0x%04X)");
  if (param_8 == (CFastBuffer<struct_CPlugFileGPU::SDxDefine> *)0x0) {
    pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                       (&DAT_00d706a4,in_stack_ffffffdc);
    *(char **)pSVar4 = "DVersion_vs";
    *(undefined1 **)(pSVar4 + 4) = local_8;
    if (*(ushort *)(param_5 + 1) < 0x200) goto LAB_008dec5f;
    pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                       (&DAT_00d706a4,in_stack_ffffffe0);
    *(char **)pSVar4 = "DVersion_vs_2_0";
  }
  else {
    if (*(ushort *)(param_5 + 1) < 0x200) goto LAB_008dec5f;
    pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                       (&DAT_00d706a4,in_stack_ffffffdc);
    *(char **)pSVar4 = "DVersion_ps";
    *(undefined1 **)(pSVar4 + 4) = local_8;
    if (*(ushort *)(param_5 + 1) < 0x300) goto LAB_008dec5f;
    pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                       (&DAT_00d706a4,in_stack_ffffffe0);
    *(char **)pSVar4 = "DVersion_ps_3_0";
  }
  *(undefined1 **)(pSVar4 + 4) = &DAT_00b2c878;
LAB_008dec5f:
  pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                     (&DAT_00d706a4,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)ppuVar7)
  ;
  *(undefined4 *)pSVar4 = 0;
  *(undefined4 *)(pSVar4 + 4) = 0;
  (**(code **)(*in_EDX + 0xa0))();
  _D3DXCompileShader_40();
  if (in_stack_00000024 != PTR_DAT_00bbf7d8) {
    puVar5 = in_stack_00000024 + -1;
    if ((in_stack_00000024[-1] & 0x80) != 0) {
      puVar5 = in_stack_00000024 + -4;
    }
    operator_delete__(puVar5);
  }
  ExceptionList = local_14;
  return extraout_EAX;
}
}

// =================================================
// Function: CompressPosition
// =================================================
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
CompressPosition(SCompressPosition *param_1,SStateSplit *param_2,CClassicArchive *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  SCompressPosition *pSVar6;
  SStateSplit *pSVar7;
  SCasterCat *pSVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  CFastBuffer<unsigned_char> *pCVar14;
  ulong unaff_EDI;
  float unaff_retaddr;
  int in_stack_00000010;
  float local_34;
  float local_30 [4];
  float local_20 [5];
  float local_c [3];
  
  pSVar7 = param_2;
  pSVar6 = param_1;
  fVar2 = (float)_DAT_00ba1d88 / (*(float *)param_1 * (float)_DAT_00ba33b8);
  if (*(int *)(param_3 + 8) == 0) {
    bVar10 = (byte)(*(int *)(param_1 + 4) * 2) & 7;
    pSVar8 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                       (param_2,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                ((uint)(*(int *)(param_1 + 4) * 2) >> 3),unaff_EDI);
    local_c[1] = 0.0;
    local_c[2] = 0.0;
    param_2 = (SStateSplit *)((3 << bVar10 & (uint)*(ushort *)pSVar8) >> bVar10 & 0xff);
    unaff_retaddr = 0.0;
    local_20[0] = 0.0;
    local_20[1] = 0.0;
    local_20[2] = 0.0;
  }
  else {
    pfVar5 = *(float **)(param_1 + 0x14);
    param_1 = (SCompressPosition *)0x2;
    uVar11 = 0;
    local_20[0] = pfVar5[1] - *(float *)(pSVar6 + 0xc);
    local_20[1] = pfVar5[2] - *(float *)(pSVar6 + 0x10);
    local_20[2] = fVar2 * (*pfVar5 - *(float *)(pSVar6 + 8));
    local_20[3] = (pfVar5[1] - *(float *)(pSVar6 + 0xc)) * fVar2;
    local_20[4] = (pfVar5[2] - *(float *)(pSVar6 + 0x10)) * fVar2;
    while (local_34 = ABS(local_20[uVar11 + 2]), local_34 < _DAT_00ba33b0) {
      local_34 = local_20[uVar11 + 2];
      fVar1 = (float)(int)ROUND(local_34);
      local_c[uVar11] = fVar1;
      if ((0x400 < ((uint)fVar1 ^ (int)fVar1 >> 0x1f) - ((int)fVar1 >> 0x1f)) ||
         (uVar11 = uVar11 + 1, 2 < uVar11)) break;
    }
    if (uVar11 == 3) {
      param_1 = (SCompressPosition *)0x1;
    }
    local_30[3] = 0.0;
    local_20[0] = 0.0;
    local_20[1] = 0.0;
    if (param_1 == (SCompressPosition *)0x1) {
      pfVar5 = *(float **)(pSVar6 + 0x14);
      uVar11 = 0;
      local_20[2] = *(float *)(pSVar6 + 8) + *(float *)(pSVar6 + 0x18);
      local_20[3] = *(float *)(pSVar6 + 0xc) + *(float *)(pSVar6 + 0x1c);
      local_20[4] = *(float *)(pSVar6 + 0x10) + *(float *)(pSVar6 + 0x20);
      local_30[0] = (*pfVar5 - (*(float *)(pSVar6 + 8) + *(float *)(pSVar6 + 0x18))) * fVar2;
      local_30[1] = (pfVar5[1] - (*(float *)(pSVar6 + 0xc) + *(float *)(pSVar6 + 0x1c))) * fVar2;
      local_30[2] = fVar2 * (pfVar5[2] - (*(float *)(pSVar6 + 0x10) + *(float *)(pSVar6 + 0x20)));
      while (local_34 = ABS(local_30[uVar11]), local_34 < _DAT_00ba33ac) {
        local_34 = local_30[uVar11];
        fVar2 = (float)(int)ROUND(local_34);
        local_20[uVar11 - 1] = fVar2;
        if ((0x7f < ((uint)fVar2 ^ (int)fVar2 >> 0x1f) - ((int)fVar2 >> 0x1f)) ||
           (uVar11 = uVar11 + 1, 2 < uVar11)) break;
      }
    }
    bVar10 = (byte)(*(int *)(pSVar6 + 4) * 2) & 7;
    pSVar8 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                       (param_2,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                ((uint)(*(int *)(pSVar6 + 4) * 2) >> 3),unaff_EDI);
    uVar12 = (ushort)(3 << bVar10);
    *(ushort *)pSVar8 = (ushort)(byte)param_2 << bVar10 & uVar12 | ~uVar12 & *(ushort *)pSVar8;
  }
  uVar11 = 0;
  if (param_2 == (SStateSplit *)0x0) {
    uVar11 = 0;
    pCVar14 = (CFastBuffer<unsigned_char> *)pSVar7;
    do {
      pCVar14 = pCVar14 + 0xc;
      param_2 = (SStateSplit *)CONCAT31(param_2._1_3_,*(undefined1 *)((int)local_20 + uVar11));
      CFastBuffer_WriteElseRead<char>
                (pCVar14,*(int *)(in_stack_00000010 + 8),*(ulong *)(pSVar7 + 0xa8),(char *)&param_2)
      ;
      param_2 = (SStateSplit *)(int)(char)(byte)param_2;
      uVar13 = uVar11 + 4;
      *(float *)((int)local_c + uVar11 + 4) = (float)(int)param_2 * local_34;
      uVar11 = uVar13;
    } while (uVar13 < 0xc);
    pfVar5 = *(float **)(pSVar6 + 0x14);
    fVar2 = *(float *)(pSVar6 + 0xc);
    fVar1 = *(float *)(pSVar6 + 0x1c);
    fVar3 = *(float *)(pSVar6 + 0x10);
    fVar4 = *(float *)(pSVar6 + 0x20);
    *pfVar5 = local_c[1] + *(float *)(pSVar6 + 8) + *(float *)(pSVar6 + 0x18);
    pfVar5[1] = local_c[2] + fVar2 + fVar1;
    pfVar5[2] = unaff_retaddr + fVar3 + fVar4;
    pfVar5 = *(float **)(pSVar6 + 0x14);
    *(float *)(pSVar6 + 0x18) = *pfVar5 - *(float *)(pSVar6 + 8);
    *(float *)(pSVar6 + 0x1c) = pfVar5[1] - *(float *)(pSVar6 + 0xc);
    *(float *)(pSVar6 + 0x20) = pfVar5[2] - *(float *)(pSVar6 + 0x10);
    *(int *)(pSVar7 + 0xa8) = *(int *)(pSVar7 + 0xa8) + 1;
  }
  else {
    if (param_2 == (SStateSplit *)0x1) {
      iVar9 = *(int *)(in_stack_00000010 + 8);
      uVar11 = 0;
      pCVar14 = (CFastBuffer<unsigned_char> *)pSVar7;
      do {
        pCVar14 = pCVar14 + 0xc;
        param_2 = *(SStateSplit **)((int)local_c + uVar11 + 4);
        CFastBuffer_WriteElseRead(pCVar14,iVar9,*(ulong *)(pSVar7 + 0xa8),(uchar *)&param_2,2);
        iVar9 = *(int *)(in_stack_00000010 + 8);
        if (iVar9 == 0) {
          param_2 = (SStateSplit *)(int)(short)param_2;
        }
        uVar13 = uVar11 + 4;
        *(float *)((int)local_20 + uVar11) = (float)(int)param_2 * local_34;
        uVar11 = uVar13;
      } while (uVar13 < 0xc);
      pfVar5 = *(float **)(pSVar6 + 0x14);
      fVar2 = *(float *)(pSVar6 + 0xc);
      fVar1 = *(float *)(pSVar6 + 0x10);
      *pfVar5 = *(float *)(pSVar6 + 8) + local_20[0];
      pfVar5[1] = fVar2 + local_20[1];
      pfVar5[2] = fVar1 + local_20[2];
      pfVar5 = *(float **)(pSVar6 + 0x14);
      *(float *)(pSVar6 + 0x18) = *pfVar5 - *(float *)(pSVar6 + 8);
      *(float *)(pSVar6 + 0x1c) = pfVar5[1] - *(float *)(pSVar6 + 0xc);
      *(float *)(pSVar6 + 0x20) = pfVar5[2] - *(float *)(pSVar6 + 0x10);
      *(int *)(pSVar7 + 0xa8) = *(int *)(pSVar7 + 0xa8) + 2;
      return;
    }
    pCVar14 = (CFastBuffer<unsigned_char> *)pSVar7;
    if (param_2 == (SStateSplit *)0x2) {
      do {
        CFastBuffer_WriteElseRead<float>
                  (pCVar14 + 0xc,*(int *)(in_stack_00000010 + 8),*(ulong *)(pSVar7 + 0xa8),
                   (float *)(*(int *)(pSVar6 + 0x14) + uVar11));
        uVar11 = uVar11 + 4;
        pCVar14 = pCVar14 + 0xc;
      } while (uVar11 < 0xc);
      *(undefined4 *)(pSVar6 + 0x20) = 0;
      *(undefined4 *)(pSVar6 + 0x1c) = 0;
      *(undefined4 *)(pSVar6 + 0x18) = 0;
      *(int *)(pSVar7 + 0xa8) = *(int *)(pSVar7 + 0xa8) + 4;
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CompressRotation
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
CompressRotation(SCompressRotation *param_1,SStateSplit *param_2,CClassicArchive *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  uint uVar2;
  ushort uVar3;
  SStateSplit *pSVar4;
  SCasterCat *pSVar5;
  byte bVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  GmQuat *unaff_EBP;
  GmIso3 *unaff_ESI;
  GmScaleTrans2 *unaff_EDI;
  uint in_stack_00000010;
  byte bStack00000014;
  GmQuat *pGVar7;
  ulong in_stack_ffffffc4;
  byte bStack_31;
  ushort local_30;
  short sStack_2e;
  ushort local_2c [2];
  ushort local_28;
  ushort local_24 [2];
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  SQuat_6 local_8 [4];
  SPlugFaceCull aSStack_4 [4];
  
  if (*(int *)(param_3 + 8) == 0) {
    pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_1;
    uVar2 = (int)pCVar1 * 3;
    bVar6 = (byte)uVar2 & 7;
    CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
              (param_2 + 0x30,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 >> 3),
               (ulong)unaff_EDI);
    pSVar5 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                       (param_2 + 0x3c,pCVar1,(ulong)unaff_ESI);
    local_24[0] = (ushort)(byte)*pSVar5;
    bVar6 = (char)((7 << bVar6 & (uint)*(ushort *)param_3) >> bVar6) + 1;
  }
  else {
    pGVar7 = unaff_EBP;
    GmQuat::SetInverse(&uStack_20,(GmScaleTrans2 *)(param_1 + 0x14),unaff_EDI);
    GmQuat::Mult(&local_1c,(GmIso3 *)(param_1 + 4),unaff_ESI);
    SQuat_6::SetFromGmQuat(&local_30,(SQuat_6 *)&local_18,pGVar7);
    param_2 = _bStack00000014;
    in_stack_00000010 = in_stack_00000010 & 0xffffff00;
    if (local_2c[0] != 0) {
      uVar2 = 0x1f;
      if (local_2c[0] != 0) {
        for (; local_2c[0] >> uVar2 == 0; uVar2 = uVar2 - 1) {
        }
      }
      bVar6 = (byte)(local_2c[0] >> 8);
      if (uVar2 < 8) {
        in_stack_00000010 = (uint)bVar6 << 8;
      }
      else if (uVar2 == 8) {
        in_stack_00000010 = (uint)bVar6 << 8;
      }
      else {
        in_stack_00000010 = (uint)CONCAT11(bVar6,(char)uVar2 + -8);
      }
    }
    bVar6 = (byte)(*(int *)param_1 * 3) & 7;
    pSVar5 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                       (_bStack00000014 + 0x30,
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        ((uint)(*(int *)param_1 * 3) >> 3),(ulong)unaff_EBX);
    uVar2 = (uint)unaff_EBP >> 0x10;
    uVar3 = (ushort)(7 << bVar6);
    *(ushort *)pSVar5 = (ushort)bStack00000014 << bVar6 & uVar3 | ~uVar3 & *(ushort *)pSVar5;
    unaff_EBX = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_1;
    bVar6 = bStack00000014 + 1;
    local_28 = local_28 >> (bVar6 & 0x1f);
    unaff_EBP = (GmQuat *)0x7f2611;
    _bStack00000014 = (SStateSplit *)CONCAT22((short)uVar2,(ushort)bStack00000014);
    pSVar5 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                       (param_2 + 0x3c,unaff_EBX,in_stack_ffffffc4);
    *pSVar5 = local_24[0]._0_1_;
  }
  pSVar4 = _bStack00000014;
  local_30 = local_24[0] << (bVar6 & 0x1f);
  param_3 = (CClassicArchive *)(((float)local_30 / (float)_DAT_00b52a58) * (float)_DAT_00b36ab8);
  if ((float)param_3 <= _DAT_00b3618c) {
    if (local_30 == 0) {
      sStack_2e = 0;
      local_2c[0] = 0;
    }
    else {
      uVar2 = (uint)param_3 >> 8;
      param_3 = (CClassicArchive *)CONCAT31((int3)uVar2,(char)((ushort)sStack_2e >> 8));
      bStack_31 = (byte)(local_2c[0] >> 8);
      CFastBuffer_WriteElseRead<char>
                ((CFastBuffer<unsigned_char> *)(param_2 + 0x48),*(int *)(_bStack00000014 + 8),
                 *(ulong *)(param_2 + 0xac),(char *)&param_3);
      CFastBuffer_WriteElseRead<char>
                ((CFastBuffer<unsigned_char> *)(param_2 + 0x54),*(int *)(pSVar4 + 8),
                 *(ulong *)(param_2 + 0xac),(char *)&bStack_31);
      sStack_2e = (ushort)(byte)param_3 << 8;
      local_2c[0] = (ushort)bStack_31 << 8;
      *(int *)(param_2 + 0xac) = *(int *)(param_2 + 0xac) + 1;
    }
  }
  else {
    CFastBuffer_WriteElseRead<short>
              ((CFastBuffer<unsigned_char> *)(param_2 + 0x48),*(int *)(_bStack00000014 + 8),
               *(ulong *)(param_2 + 0xac),&sStack_2e);
    CFastBuffer_WriteElseRead<short>
              ((CFastBuffer<unsigned_char> *)(param_2 + 0x54),*(int *)(pSVar4 + 8),
               *(ulong *)(param_2 + 0xac),(short *)local_2c);
    *(int *)(param_2 + 0xac) = *(int *)(param_2 + 0xac) + 2;
  }
  SQuat_6::GetGmQuat(&local_30,local_8,unaff_EBP);
  GmQuat::SetMult(local_24,(SPlugFaceCull *)(param_1 + 0x14),aSStack_4,(GmIso4 *)unaff_EBX);
  *(undefined4 *)(param_1 + 4) = uStack_20;
  *(undefined4 *)(param_1 + 8) = local_1c;
  *(undefined4 *)(param_1 + 0xc) = local_18;
  *(undefined4 *)(param_1 + 0x10) = local_14;
  return;
}
}

// =================================================
// Function: ComputeMD5OnStr
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl ComputeMD5OnStr(char *param_1,SNat128 *param_2)
{
{
  md5_state_s mVar1;
  int iVar2;
  md5_state_s *in_ECX;
  int unaff_ESI;
  uchar *unaff_EDI;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)&local_5c;
  iVar2 = 0;
  mVar1 = *in_ECX;
  local_58 = 0;
  local_5c = 0;
  local_54 = 0x67452301;
  local_50 = 0xefcdab89;
  local_4c = 0x98badcfe;
  local_48 = 0x10325476;
  while (mVar1 != (md5_state_s)0x0) {
    iVar2 = iVar2 + 1;
    mVar1 = in_ECX[iVar2];
  }
  static_md5_append(in_ECX,unaff_EDI,unaff_ESI);
  static_md5_finish();
  return;
}
}

// =================================================
// Function: ComputeOutput
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall ComputeOutput(void *this,CFuncColor *param_1)
{
{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    __CIsin();
    return;
  case 1:
    break;
  case 2:
    if ((float)param_1 < _DAT_00b31460) {
      return;
    }
    return;
  default:
    return;
  case 4:
    return;
  }
  if ((float)param_1 < _DAT_00b31460) {
    return;
  }
  return;
}
}

// =================================================
// Function: ComputeStackAndParamInfo
// =================================================
int __cdecl
ComputeStackAndParamInfo(char *param_1,CMwNod *param_2,CMwStack *param_3,SMwParamInfo *param_4)
{
{
  CMwStack *pCVar1;
  undefined1 *puVar2;
  CFastString *unaff_EBX;
  CMwStack *unaff_ESI;
  SMwParamInfo *unaff_EDI;
  ulong uVar3;
  CMwNod *pCVar4;
  CMwNod *in_stack_ffffffec;
  CMwNod local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a82868;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastString::CFastString
            ((CFastString *)&stack0xffffffec,(CFastString *)param_1,
             (char *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  pCVar4 = local_10;
  uVar3 = 0;
  pCVar1 = (CMwStack *)(**(code **)(*(int *)unaff_EDI + 0xc))();
  uVar3 = CMwStack::FillIndexFromText(unaff_ESI,pCVar1,uVar3,pCVar4,unaff_EBX);
  if (puStack_8 != PTR_DAT_00bbf7d8) {
    puVar2 = puStack_8 + -1;
    if ((puStack_8[-1] & 0x80) != 0) {
      puVar2 = puStack_8 + -4;
    }
    operator_delete__(puVar2);
    local_c = (void *)0x0;
    puStack_8 = PTR_DAT_00bbf7d8;
  }
  if ((uVar3 == 0) && (*(int *)(unaff_ESI + 4) != 0)) {
    *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 4) + -1;
    uVar3 = CMwStack::MakeInfoFromStack(unaff_ESI,(CMwStack *)param_4,unaff_EDI,in_stack_ffffffec);
    ExceptionList = (void *)0x0;
    return (uint)(uVar3 == 0);
  }
  ExceptionList = pvStack_4;
  return 0;
}
}

// =================================================
// Function: ComputeTriangleTangentUV_Rotated
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl ComputeTriangleTangentUV_Rotated(STri_PosTexTgt *param_1,ulong param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  uint uVar16;
  
  pfVar5 = *(float **)(param_1 + *(int *)(&DAT_00d1a8c8 + param_2 * 0xc) * 4);
  pfVar6 = *(float **)(param_1 + *(int *)(&DAT_00d1a8c8 + param_2 * 0xc) * 4 + 0xc);
  pfVar7 = *(float **)(param_1 + *(int *)(&DAT_00d1a8cc + param_2 * 0xc) * 4);
  fVar1 = *pfVar7;
  fVar2 = *pfVar5;
  pfVar8 = *(float **)(param_1 + *(int *)(&DAT_00d1a8d0 + param_2 * 0xc) * 4);
  fVar10 = **(float **)(param_1 + *(int *)(&DAT_00d1a8cc + param_2 * 0xc) * 4 + 0xc) - *pfVar6;
  fVar11 = (*(float **)(param_1 + *(int *)(&DAT_00d1a8cc + param_2 * 0xc) * 4 + 0xc))[1] - pfVar6[1]
  ;
  fVar3 = *pfVar8;
  fVar4 = *pfVar5;
  fVar12 = **(float **)(param_1 + *(int *)(&DAT_00d1a8d0 + param_2 * 0xc) * 4 + 0xc) - *pfVar6;
  fVar13 = (*(float **)(param_1 + *(int *)(&DAT_00d1a8d0 + param_2 * 0xc) * 4 + 0xc))[1] - pfVar6[1]
  ;
  fVar14 = fVar10 * fVar13 - fVar11 * fVar12;
  bVar9 = ABS(fVar14) <= _DAT_00d1a8f0;
  if (bVar9) {
    fVar1 = 0.0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    *(float *)(param_1 + 0x18) = -(fVar11 * (fVar3 - fVar4) - fVar13 * (fVar1 - fVar2)) / fVar14;
    fVar1 = -(fVar12 * (fVar1 - fVar2) - fVar10 * (fVar3 - fVar4)) / fVar14;
  }
  uVar16 = (uint)!bVar9;
  *(float *)(param_1 + 0x24) = fVar1;
  fVar15 = _DAT_00d1a8f0;
  fVar1 = pfVar7[1];
  fVar2 = pfVar5[1];
  fVar3 = pfVar8[1];
  fVar4 = pfVar5[1];
  if (ABS(fVar14) <= _DAT_00d1a8f0) {
    fVar1 = 0.0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  else {
    uVar16 = uVar16 | 2;
    *(float *)(param_1 + 0x1c) = -(fVar11 * (fVar3 - fVar4) - fVar13 * (fVar1 - fVar2)) / fVar14;
    fVar1 = -(fVar12 * (fVar1 - fVar2) - fVar10 * (fVar3 - fVar4)) / fVar14;
  }
  *(float *)(param_1 + 0x28) = fVar1;
  fVar1 = pfVar7[2];
  fVar2 = pfVar5[2];
  fVar3 = pfVar8[2];
  fVar4 = pfVar5[2];
  if (fVar15 < ABS(fVar14)) {
    *(float *)(param_1 + 0x20) = -((fVar3 - fVar4) * fVar11 - (fVar1 - fVar2) * fVar13) / fVar14;
    *(float *)(param_1 + 0x2c) = -(fVar12 * (fVar1 - fVar2) - fVar10 * (fVar3 - fVar4)) / fVar14;
    return uVar16 | 4;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return uVar16;
}
}

// =================================================
// Function: ComputeVideoMemorySize_WithoutCurrentFB
// =================================================
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ulong __cdecl ComputeVideoMemorySize_WithoutCurrentFB(ulong *param_1)
{
{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  uint *******pppppppuVar3;
  uint *******pppppppuStack_5c;
  int **ppiStack_58;
  int *piStack_54;
  int ***pppiStack_50;
  uint *******pppppppuStack_4c;
  int **ppiStack_48;
  int *piStack_44;
  undefined1 *puStack_40;
  uint *******pppppppuStack_3c;
  int *piStack_38;
  int *piStack_34;
  int **ppiStack_30;
  uint *******pppppppuVar4;
  uint ******ppppppuStack_1c;
  int *local_18;
  int iStack_14;
  int *piStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pppppppuVar3 = (uint *******)0xffffffff;
  local_18 = (int *)0x0;
  hModule = LoadLibraryA("DDRAW.DLL");
  if (hModule != (HMODULE)0x0) {
    ppiStack_30 = (int **)0x43b711;
    pFVar1 = GetProcAddress(hModule,"DirectDrawCreateEx");
    if (pFVar1 != (FARPROC)0x0) {
      ppiStack_30 = &local_18;
      piStack_34 = (int *)0x0;
      piStack_38 = (int *)0x43b729;
      iVar2 = (*pFVar1)();
      if ((-1 < iVar2) && (local_18 != (int *)0x0)) {
        uStack_c = 0;
        uStack_8 = 0;
        uStack_4 = 0;
        piStack_44 = &iStack_14;
        pppppppuVar4 = &ppppppuStack_1c;
        ppiStack_30 = &piStack_10;
        piStack_10 = (int *)0x10007000;
        piStack_34 = local_18;
        piStack_38 = (int *)0x43b76e;
        iVar2 = (**(code **)(*local_18 + 0x5c))();
        if (((iVar2 == 0) && (pppppppuVar4 != (uint *******)0x0)) &&
           (pppppppuVar4 != (uint *******)0xffffffff)) {
          pppppppuVar3 = pppppppuVar4;
        }
        piStack_38 = (int *)&stack0xffffffdc;
        pppppppuStack_3c = (uint *******)&stack0xffffffd4;
        puStack_40 = &stack0xffffffe0;
        ppiStack_48 = (int **)0x43b7a4;
        iVar2 = (**(code **)(*piStack_44 + 0x5c))();
        if (((iVar2 == 0) && (pppppppuStack_3c != (uint *******)0x0)) &&
           (pppppppuStack_3c < pppppppuVar3)) {
          pppppppuVar3 = pppppppuStack_3c;
        }
        ppiStack_48 = &piStack_34;
        pppppppuStack_4c = (uint *******)&pppppppuStack_3c;
        pppiStack_50 = &ppiStack_30;
        ppiStack_30 = (int **)0x10004040;
        piStack_54 = piStack_38;
        ppiStack_58 = (int **)0x43b7d9;
        iVar2 = (**(code **)(*piStack_38 + 0x5c))();
        if (((iVar2 == 0) && (pppppppuStack_4c != (uint *******)0x0)) &&
           (pppppppuStack_4c < pppppppuVar3)) {
          pppppppuVar3 = pppppppuStack_4c;
        }
        ppiStack_58 = &piStack_44;
        pppppppuStack_5c = (uint *******)&pppppppuStack_4c;
        puStack_40 = (undefined1 *)0x10004000;
        iVar2 = (*(code *)(*ppiStack_48)[0x17])(ppiStack_48,&puStack_40);
        if (((iVar2 == 0) && (pppppppuStack_5c != (uint *******)0x0)) &&
           (pppppppuStack_5c < pppppppuVar3)) {
          pppppppuVar3 = pppppppuStack_5c;
        }
        pppiStack_50 = (int ***)0x20005000;
        iVar2 = (*(code *)(*ppiStack_58)[0x17])(ppiStack_58,&pppiStack_50);
        *pppppppuStack_4c = (uint ******)(~-(uint)(iVar2 != 0) & (uint)&pppppppuStack_5c);
        (*(code *)piStack_54[2])(&piStack_54);
        FreeLibrary(hModule);
        return -(uint)(pppppppuVar3 != (uint *******)0xffffffff) & (uint)pppppppuVar3;
      }
    }
    FreeLibrary(hModule);
  }
  return 0;
}
}

// =================================================
// Function: ConcatUtf8Char
// =================================================
ulong __cdecl ConcatUtf8Char(CFastString *param_1,ulong param_2)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  uint in_EAX;
  CFastStringBase<wchar_t> *pCVar2;
  ulong uVar3;
  SOldChars *unaff_EDI;
  
  if (in_EAX == 0) {
    return 0;
  }
  if (in_EAX < 0x80) {
    uVar3 = 1;
    goto LAB_00903117;
  }
  if (0x7ff < in_EAX) {
    if (in_EAX < 0x10000) {
      uVar3 = 3;
      goto LAB_00903117;
    }
    if (in_EAX < 0x200000) {
      uVar3 = 4;
      goto LAB_00903117;
    }
    if (in_EAX < 0x4000000) {
      uVar3 = 5;
      goto LAB_00903117;
    }
    if (in_EAX < 0x80000000) {
      uVar3 = 6;
      goto LAB_00903117;
    }
    in_EAX = 0xfffd;
  }
  uVar3 = 2;
LAB_00903117:
  pCVar2 = *(CFastStringBase<wchar_t> **)param_1;
  pCVar1 = pCVar2 + uVar3;
  if (pCVar1 != pCVar2) {
    CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)param_1,pCVar1,1,0,unaff_EDI);
    pCVar1[*(int *)(param_2 + 4)] = (CFastStringBase<wchar_t>)0x0;
    *(CFastStringBase<wchar_t> **)param_2 = pCVar1;
    param_1 = (CFastString *)param_2;
  }
  pCVar2 = pCVar2 + *(int *)(param_1 + 4);
  switch(uVar3) {
  case 6:
    pCVar2[5] = (CFastStringBase<wchar_t>)((byte)in_EAX & 0x3f | 0x80);
    in_EAX = in_EAX >> 6 | 0x4000000;
  case 5:
    pCVar2[4] = (CFastStringBase<wchar_t>)((byte)in_EAX & 0x3f | 0x80);
    in_EAX = (in_EAX | 0x8000000) >> 6;
  case 4:
    pCVar2[3] = (CFastStringBase<wchar_t>)((byte)in_EAX & 0x3f | 0x80);
    in_EAX = (in_EAX | 0x400000) >> 6;
  case 3:
    pCVar2[2] = (CFastStringBase<wchar_t>)((byte)in_EAX & 0x3f | 0x80);
    in_EAX = (in_EAX | 0x20000) >> 6;
  case 2:
    pCVar2[1] = (CFastStringBase<wchar_t>)((byte)in_EAX & 0x3f | 0x80);
    in_EAX = (in_EAX | 0x3000) >> 6;
  case 1:
    *pCVar2 = SUB41(in_EAX,0);
  default:
    pCVar2[uVar3] = (CFastStringBase<wchar_t>)0x0;
    return uVar3;
  }
}
}

// =================================================
// Function: ControlClampZRecurse
// =================================================
void __cdecl
ControlClampZRecurse(CControlContainer *param_1,float param_2,float param_3,float param_4)
{
{
  CControlContainer *pCVar1;
  ulong uVar2;
  int iVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  CControlBase *unaff_ESI;
  uint uVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  float in_stack_00000014;
  float in_stack_00000018;
  CControlContainer *pCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_34;
  undefined4 auStack_2c [11];
  
  if (param_1 != (CControlContainer *)0x0) {
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x144,unaff_EDI);
    pCVar7 = (CControlContainer *)0x7016000;
    iVar3 = (**(code **)(*(int *)param_1 + 0x10))();
    uVar5 = -(uint)(iVar3 != 0) & (uint)param_1;
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (uVar2 != 0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_1 + 0x144,pCVar6,(ulong)pCVar7);
        pCVar1 = *(CControlContainer **)pSVar4;
        pCVar7 = pCVar1;
        CControlContainer::GetRelativeLocation
                  (param_1,(CControlContainer *)auStack_2c,(GmIso4 *)pCVar1,unaff_ESI);
        param_3 = param_4 + (float)param_1;
        if (in_stack_00000014 < param_3) {
          if (in_stack_00000018 < param_3 != (in_stack_00000018 == param_3)) {
            param_3 = in_stack_00000018;
          }
        }
        else {
          param_3 = in_stack_00000014;
        }
        if (uVar5 != 0) {
          pCVar7 = (CControlContainer *)0x71dd5f;
          pSVar4 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
                   ::operator[]((void *)(uVar5 + 0x158),pCVar6,unaff_EBX);
          *(undefined4 *)(pSVar4 + 0x2c) = auStack_2c[0];
        }
        unaff_EBX = 0x7002000;
        unaff_ESI = (CControlBase *)0x71dd78;
        iVar3 = (**(code **)(*(int *)pCVar1 + 0x10))();
        if (iVar3 != 0) {
          ControlClampZRecurse(pCVar1,(float)param_1,param_3,param_4);
        }
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < pCStack_34);
    }
  }
  return;
}
}

// =================================================
// Function: ControlSetSizeAndAlign
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
ControlSetSizeAndAlign
          (CControlBase *param_1,TiXmlElement *param_2,GmVec2 *param_3,EAlignHorizontal param_4,
          EAlignVertical param_5,int param_6)
{
{
  float fVar1;
  undefined4 uVar2;
  EAlignVertical EVar3;
  CControlLayout *pCVar4;
  CMwNod *extraout_EAX;
  int iVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  float *in_ECX;
  float in_EDX;
  EAlignVertical unaff_EBX;
  CMwNod *this;
  CMwNod *unaff_EBP;
  CControlBase *pCVar8;
  CControlContainer *unaff_ESI;
  CMwNod *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  int unaff_retaddr;
  CFastBuffer<class_CCrystalFace*> *pCVar10;
  ulong uVar11;
  int *piVar12;
  float local_40;
  float fStack_3c;
  undefined4 uStack_38;
  float fStack_34;
  float local_30;
  float local_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  void *pvStack_1c;
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  CControlBase *local_4;
  
  local_4 = (CControlBase *)0xffffffff;
  puStack_8 = &LAB_00ac098b;
  local_c = ExceptionList;
  pCVar4 = (CControlLayout *)(DAT_00cca150 ^ (uint)&stack0xffffffb4);
  ExceptionList = &local_c;
  local_2c = in_ECX[1];
  local_30 = *in_ECX;
  local_40 = in_EDX;
  ElemSizeAndAlignGet((TiXmlElement *)&local_40,(GmVec2 *)&param_2,(EAlignHorizontal *)pCVar4,
                      (EAlignVertical *)unaff_EDI);
  fVar1 = local_40;
  if (param_3 == (GmVec2 *)0x0) {
    piVar12 = (int *)0x7031000;
    iVar5 = (**(code **)(*(int *)unaff_ESI + 0x10))();
    pCVar8 = param_1;
    if (iVar5 != 0) {
      if (0.0 < fStack_34) {
        *(float *)(unaff_ESI + 0x120) = fStack_34;
      }
      if (*(int *)(unaff_ESI + 0x128) == -1) {
        local_40 = 0.0;
        TiXmlElement::QueryIntAttribute
                  ((TiXmlElement *)param_1,(TiXmlElement *)"autonewline",(char *)&local_40,piVar12);
        *(uint *)(unaff_ESI + 0x128) = (fStack_3c != 0.0) - 1;
      }
    }
  }
  else {
    if ((param_2 != (TiXmlElement *)0x3) || (local_40 != 4.2039e-45)) {
      param_2 = operator_new(0x2c);
      this = (CMwNod *)0x0;
      local_4 = (CControlBase *)0x0;
      if (param_2 != (TiXmlElement *)0x0) {
        CControlLayout::CControlLayout((CControlLayout *)param_2,pCVar4);
        this = extraout_EAX;
      }
      *(float *)(this + 0x18) = fVar1;
      *(undefined4 *)(this + 0x14) = 1;
      unaff_retaddr = -1;
      if (this != *(CMwNod **)(unaff_ESI + 0x8c)) {
        CMwNod::MwAddRef(this,unaff_EDI);
        if (*(CMwNod **)(unaff_ESI + 0x8c) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(unaff_ESI + 0x8c),unaff_EBP);
        }
        *(CMwNod **)(unaff_ESI + 0x8c) = this;
      }
    }
    iVar5 = (**(code **)(*(int *)unaff_ESI + 0x10))(0x7006000);
    if (((iVar5 == 0) && (iVar5 = (**(code **)(*(int *)unaff_ESI + 0x10))(0x7009000), iVar5 == 0))
       && (iVar5 = (**(code **)(*(int *)unaff_ESI + 0x10))(0x7007000), iVar5 == 0)) {
      pCVar8 = (CControlBase *)0x3;
      unaff_EBX = 3;
    }
    else {
      pCVar8 = (CControlBase *)0x0;
      unaff_EBX = 0;
      if ((*(int *)(unaff_ESI + 0x8c) != 0) &&
         (EVar3 = *(EAlignVertical *)(*(int *)(unaff_ESI + 0x8c) + 0x18), EVar3 != 3)) {
        unaff_EBX = EVar3;
      }
    }
    iVar5 = (**(code **)(*(int *)unaff_ESI + 0x10))(0x7031000);
    if (iVar5 != 0) {
      if (*in_ECX <= 0.0) {
        *(undefined4 *)(unaff_ESI + 0x128) = 0xffffffff;
      }
      else {
        fVar1 = *in_ECX;
        *(undefined4 *)(unaff_ESI + 0x128) = 0;
        *(float *)(unaff_ESI + 0x120) = fVar1;
      }
    }
  }
  uVar11 = 0x702c000;
  iVar5 = (**(code **)(*(int *)unaff_ESI + 0x10))();
  if (iVar5 != 0) {
    *(undefined4 *)(unaff_ESI + 0x178) = uStack_38;
    *(float *)(unaff_ESI + 0x17c) = fStack_34;
    *(EAlignVertical *)(unaff_ESI + 0x180) = unaff_EBX;
    *(CControlBase **)(unaff_ESI + 0x184) = pCVar8;
LAB_0071e891:
    *(CControlBase **)(unaff_ESI + 0x118) = param_1;
    ExceptionList = pvStack_14;
    return;
  }
  pCVar10 = (CFastBuffer<class_CCrystalFace*> *)0x30bd000;
  iVar5 = (**(code **)(*(int *)unaff_ESI + 0x10))();
  if (iVar5 != 0) {
    CControlTools::ControlRetrieve<class_CControlBase>(unaff_ESI,"ButtonSelection",&local_4,1,0,1);
    if (local_4 != (CControlBase *)0x0) {
      local_30 = *(float *)(local_4 + 0x94);
      local_2c = *(float *)(local_4 + 0x98);
      fStack_28 = *(float *)(local_4 + 0x9c);
      fStack_24 = *(float *)(local_4 + 0xa0);
      fStack_20 = *(float *)(local_4 + 0xa4);
      pvStack_1c = *(void **)(local_4 + 0xa8);
      CControlBase::GetOffsetFromAlign
                ((GmVec2 *)&local_30,SUB41(fStack_24 * (float)_DAT_00b33a58,0),
                 (EAlignHorizontal)((float)_DAT_00b33a58 * fStack_20),unaff_EBX);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(unaff_ESI + 0x158,pCVar10);
      pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar6 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) goto LAB_0071e891;
      do {
        local_40 = fStack_28;
        pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
                 ::operator[](unaff_ESI + 0x158,pCVar9,uVar11);
        pCVar9 = pCVar9 + 1;
        *(float *)(pSVar7 + 0x24) = *(float *)(pSVar7 + 0x24) + fStack_28;
        *(float *)(pSVar7 + 0x28) = *(float *)(pSVar7 + 0x28) + fStack_3c;
        *(float *)(pSVar7 + 0x2c) = *(float *)(pSVar7 + 0x2c) + (float)_PTR_00b2c178;
      } while (pCVar9 < pCVar6);
    }
    *(CControlBase **)(unaff_ESI + 0x118) = param_1;
    ExceptionList = pvStack_14;
    return;
  }
  *(EAlignVertical *)(unaff_ESI + 0x10c) = unaff_EBX;
  *(CControlBase **)(unaff_ESI + 0x108) = pCVar8;
  if (unaff_retaddr == 0) {
    (**(code **)(*(int *)unaff_ESI + 0x1b8))(&fStack_3c);
    uVar2 = *(undefined4 *)(unaff_ESI + 0xa8);
    *(undefined4 *)(unaff_ESI + 0x94) = *(undefined4 *)(unaff_ESI + 0x94);
    *(undefined4 *)(unaff_ESI + 0x98) = *(undefined4 *)(unaff_ESI + 0x98);
    *(undefined4 *)(unaff_ESI + 0x9c) = 0;
    *(undefined4 *)(unaff_ESI + 0xa0) = *(undefined4 *)(unaff_ESI + 0xa0);
    *(undefined4 *)(unaff_ESI + 0xa4) = *(undefined4 *)(unaff_ESI + 0xa4);
  }
  else {
    iVar5 = (**(code **)(*(int *)unaff_ESI + 0x10))(0x701b000);
    if (iVar5 == 0) goto LAB_0071eaae;
    fVar1 = (float)_DAT_00b313b8;
    uVar2 = 0;
    *(undefined4 *)(unaff_ESI + 0x9c) = 0;
    *(undefined4 *)(unaff_ESI + 0x98) = 0;
    *(undefined4 *)(unaff_ESI + 0x94) = 0;
    *(float *)(unaff_ESI + 0xa0) = local_40 * fVar1;
    *(float *)(unaff_ESI + 0xa4) = fVar1 * fStack_3c;
  }
  *(undefined4 *)(unaff_ESI + 0xa8) = uVar2;
LAB_0071eaae:
  *(int *)(unaff_ESI + 0x118) = unaff_retaddr;
  ExceptionList = pvStack_1c;
  return;
}
}

// =================================================
// Function: ControlTextSetStyle
// =================================================
void __cdecl
ControlTextSetStyle(CControlBase *param_1,TiXmlElement *param_2,CControlStyleSheet *param_3,
                   SManialinkFormat *param_4)
{
{
  int iVar1;
  CMwCmdScriptVarBool *unaff_ESI;
  TiXmlElement *unaff_retaddr;
  CFastStringInt *pCVar2;
  undefined4 uVar3;
  CMwNod *pCVar4;
  int iStack_38;
  CMwNod *pCStack_14;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ac09b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar4 = (CMwNod *)0x30bd000;
  iVar1 = (**(code **)(*(int *)unaff_ESI + 0x10))(0x30bd000,DAT_00cca150 ^ (uint)&stack0xffffffb8);
  if (iVar1 == 0) {
    SManialinkFormat::SManialinkFormat(&stack0xffffffb8,(SManialinkFormat *)param_2);
    puStack_8 = (undefined1 *)0x0;
    ElemModifyManialinkFormat
              (unaff_retaddr,(CControlStyleSheet *)param_1,(SManialinkFormat *)pCVar4);
    uVar3 = 0;
    CControlBase::CStyleSheetElem<class_CControlStyle>::Set
              (unaff_ESI + 0x110,unaff_ESI,(int)pCStack_14);
    if (iStack_38 != 0) {
      pCVar2 = (CFastStringInt *)0x7006000;
      iVar1 = (**(code **)(*(int *)unaff_ESI + 0x10))(0x7006000,uVar3);
      if (iVar1 != 0) {
        RemoveLeadingSpaceFromXmlString(pCVar2);
      }
      iVar1 = (**(code **)(*(int *)unaff_ESI + 0x10))(0x7007000);
      if (iVar1 != 0) {
        RemoveLeadingSpaceFromXmlString((CFastStringInt *)pCVar4);
      }
    }
    puStack_8 = (undefined1 *)0xffffffff;
    if (pCStack_14 != (CMwNod *)0x0) {
      CMwNod::MwRelease(pCStack_14,pCVar4);
    }
  }
  ExceptionList = pvStack_10;
  return;
}
}

// =================================================
// Function: CorpusCat_IsStatic
// =================================================
int __cdecl CorpusCat_IsStatic(EHmsCorpusCat param_1)
{
{
  if ((param_1 != 0) && (param_1 != 1)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CpuExtCheckOsSupport
// =================================================
int __cdecl CpuExtCheckOsSupport(ECpuExt param_1)
{
{
  if ((param_1 != 1) && (param_1 == 2)) {
    return 1;
  }
  return 1;
}
}

// =================================================
// Function: D3DFormatGetBytePerPixel
// =================================================
ulong __cdecl D3DFormatGetBytePerPixel(_D3DFORMAT param_1)
{
{
  SStringParamInt *pSVar1;
  SHeaderCommunity *pSVar2;
  undefined *local_18;
  char *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00aead48;
  local_c = ExceptionList;
  pSVar1 = (SStringParamInt *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  if ((int)param_1 < 0x31495442) {
    if (param_1 == 0x31495441) {
      return 0;
    }
    switch(param_1) {
    case 0x14:
      return 3;
    case 0x15:
    case 0x16:
    case 0x1f:
    case 0x22:
    case 0x23:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x43:
    case 0x47:
    case 0x4b:
    case 0x4d:
    case 0x4f:
    case 0x70:
    case 0x72:
      return 4;
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1d:
    case 0x1e:
    case 0x28:
    case 0x33:
    case 0x3c:
    case 0x3d:
    case 0x49:
    case 0x50:
    case 0x51:
    case 0x6f:
    case 0x75:
      return 2;
    case 0x1b:
    case 0x1c:
    case 0x29:
    case 0x32:
    case 0x34:
      return 1;
    case 0x24:
    case 0x6e:
    case 0x71:
    case 0x73:
      return 8;
    case 0x74:
      return 0x10;
    }
  }
  else if ((int)param_1 < 0x34545845) {
    if (param_1 == 0x34545844) {
      return 0;
    }
    if ((int)param_1 < 0x32545845) {
      if (param_1 == 0x32545844) {
        return 0;
      }
      if (param_1 == 0x31545844) {
        return 0;
      }
      if (param_1 == 0x32495441) {
        return 0;
      }
    }
    else {
      if (param_1 == 0x33545844) {
        return 0;
      }
      if (param_1 == 0x34324644) {
        return 0;
      }
    }
  }
  else if ((int)param_1 < 0x4c4c554f) {
    if (param_1 == 0x4c4c554e) {
      return 0;
    }
    if (param_1 == 0x35545844) {
      return 0;
    }
    if (param_1 == 0x36314644) {
      return 0;
    }
  }
  else {
    if (param_1 == 0x5348564e) {
      return 4;
    }
    if (param_1 == 0x5548564e) {
      return 4;
    }
  }
  pSVar2 = (SHeaderCommunity *)0x0;
  local_18 = PTR_DAT_00bbf7d8;
  local_4 = (void *)0x0;
  ExceptionList = &local_c;
  D3DFormatGetString((CFastString *)&stack0xffffffe4,param_1);
  local_14 = "Unkowned pixel size of ";
  local_10 = 0x17;
  CFastString::ConcatBefore((CFastString *)&stack0xffffffe4,(CFastStringInt *)&local_14,pSVar1);
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_18,pSVar2);
  ExceptionList = local_4;
  return 0;
}
}

// =================================================
// Function: D3DFormatGetString
// =================================================
void __cdecl D3DFormatGetString(CFastString *param_1,_D3DFORMAT param_2)
{
{
  char cVar1;
  SStringParam *unaff_EBX;
  SStringParam *unaff_ESI;
  char *local_1b0;
  undefined4 local_1ac;
  undefined *local_1a8;
  undefined4 local_1a4;
  undefined1 local_1a0 [4];
  CFastStringInt local_19c [4];
  undefined1 local_198 [4];
  CFastStringInt local_194 [4];
  undefined1 local_190 [4];
  CFastStringInt local_18c [4];
  undefined1 local_188 [4];
  CFastStringInt local_184 [4];
  undefined1 local_180 [4];
  CFastStringInt local_17c [4];
  undefined1 local_178 [4];
  CFastStringInt local_174 [4];
  undefined1 local_170 [4];
  CFastStringInt local_16c [4];
  undefined1 local_168 [4];
  CFastStringInt local_164 [4];
  undefined1 local_160 [4];
  CFastStringInt local_15c [4];
  undefined1 local_158 [4];
  CFastStringInt local_154 [4];
  undefined1 local_150 [4];
  CFastStringInt local_14c [4];
  undefined1 local_148 [4];
  CFastStringInt local_144 [4];
  undefined1 local_140 [4];
  CFastStringInt local_13c [4];
  undefined1 local_138 [4];
  CFastStringInt local_134 [4];
  undefined1 local_130 [4];
  CFastStringInt local_12c [4];
  undefined1 local_128 [4];
  CFastStringInt local_124 [4];
  undefined1 local_120 [4];
  CFastStringInt local_11c [4];
  undefined1 local_118 [4];
  CFastStringInt local_114 [4];
  undefined1 local_110 [4];
  CFastStringInt local_10c [4];
  undefined1 local_108 [4];
  CFastStringInt local_104 [4];
  undefined1 local_100 [4];
  CFastStringInt local_fc [4];
  undefined1 local_f8 [4];
  CFastStringInt local_f4 [4];
  undefined1 local_f0 [4];
  CFastStringInt local_ec [4];
  undefined1 local_e8 [4];
  CFastStringInt local_e4 [4];
  undefined1 local_e0 [4];
  CFastStringInt local_dc [4];
  undefined1 local_d8 [4];
  CFastStringInt local_d4 [4];
  undefined1 local_d0 [4];
  CFastStringInt local_cc [4];
  undefined1 local_c8 [4];
  CFastStringInt local_c4 [4];
  undefined1 local_c0 [4];
  CFastStringInt local_bc [4];
  undefined1 local_b8 [4];
  CFastStringInt local_b4 [4];
  undefined1 local_b0 [4];
  CFastStringInt local_ac [4];
  undefined1 local_a8 [4];
  CFastStringInt local_a4 [4];
  undefined1 local_a0 [4];
  CFastStringInt local_9c [4];
  undefined1 local_98 [4];
  CFastStringInt local_94 [4];
  undefined1 local_90 [4];
  CFastStringInt local_8c [4];
  undefined1 local_88 [4];
  CFastStringInt local_84 [4];
  undefined1 local_80 [4];
  CFastStringInt local_7c [4];
  undefined1 local_78 [4];
  CFastStringInt local_74 [4];
  undefined1 local_70 [4];
  CFastStringInt local_6c [4];
  undefined1 local_68 [4];
  CFastStringInt local_64 [4];
  undefined1 local_60 [4];
  CFastStringInt local_5c [4];
  undefined1 local_58 [4];
  CFastStringInt local_54 [4];
  undefined1 local_50 [4];
  CFastStringInt local_4c [4];
  undefined1 local_48 [4];
  CFastStringInt local_44 [4];
  undefined1 local_40 [4];
  CFastStringInt local_3c [4];
  undefined1 local_38 [4];
  CFastStringInt local_34 [4];
  undefined1 local_30 [4];
  CFastStringInt local_2c [4];
  undefined1 local_28 [4];
  CFastStringInt local_24 [4];
  undefined1 local_20 [4];
  CFastStringInt local_1c [4];
  undefined1 local_18 [4];
  CFastStringInt local_14 [4];
  undefined1 local_10 [4];
  CFastStringInt local_c [8];
  
  if ((int)param_2 < 0x31495442) {
    if (param_2 == 0x31495441) {
      local_1b0 = "ATI1_Comp1N";
      local_1ac = 0xb;
      CFastString::SetString(param_1,(CFastStringInt *)&local_1b0,unaff_ESI);
      return;
    }
    switch(param_2) {
    case 0x14:
      SStringParam::SStringParam(local_78,(SStringParam *)"R8G8B8",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_74,unaff_EBX);
      return;
    case 0x15:
      SStringParam::SStringParam(local_28,(SStringParam *)"A8R8G8B8",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_24,unaff_EBX);
      return;
    case 0x16:
      SStringParam::SStringParam(local_188,(SStringParam *)"X8R8G8B8",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_184,unaff_EBX);
      return;
    case 0x17:
      SStringParam::SStringParam(local_c8,(SStringParam *)"R5G6B5",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_c4,unaff_EBX);
      return;
    case 0x18:
      SStringParam::SStringParam(local_178,(SStringParam *)"X1R5G5B5",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_174,unaff_EBX);
      return;
    case 0x19:
      SStringParam::SStringParam(local_68,(SStringParam *)"A1R5G5B5",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_64,unaff_EBX);
      return;
    case 0x1a:
      SStringParam::SStringParam(local_168,(SStringParam *)"A4R4G4B4",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_164,unaff_EBX);
      return;
    case 0x1b:
      SStringParam::SStringParam(local_b8,(SStringParam *)"R3G3B2",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_b4,unaff_EBX);
      return;
    case 0x1c:
      SStringParam::SStringParam(local_158,(SStringParam *)&DAT_00bd3d14,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_154,unaff_EBX);
      return;
    case 0x1d:
      SStringParam::SStringParam(local_38,(SStringParam *)"A8R3G3B2",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_34,unaff_EBX);
      return;
    case 0x1e:
      SStringParam::SStringParam(local_148,(SStringParam *)"X4R4G4B4",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_144,unaff_EBX);
      return;
    case 0x1f:
      SStringParam::SStringParam(local_a8,(SStringParam *)"A2B10G10R10",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_a4,unaff_EBX);
      return;
    case 0x22:
      SStringParam::SStringParam(local_138,(SStringParam *)"G16R16",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_134,unaff_EBX);
      return;
    case 0x23:
      SStringParam::SStringParam(local_58,(SStringParam *)"A2R10G10B10",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_54,unaff_EBX);
      return;
    case 0x24:
      SStringParam::SStringParam(local_128,(SStringParam *)"A16B16G16R16",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_124,unaff_EBX);
      return;
    case 0x28:
      SStringParam::SStringParam(local_98,(SStringParam *)&DAT_00bd3cc4,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_94,unaff_EBX);
      return;
    case 0x29:
      SStringParam::SStringParam(local_118,(SStringParam *)&DAT_00bd3cc0,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_114,unaff_EBX);
      return;
    case 0x32:
      SStringParam::SStringParam(local_18,(SStringParam *)&DAT_00bd3cbc,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_14,unaff_EBX);
      return;
    case 0x33:
      SStringParam::SStringParam(local_88,(SStringParam *)&DAT_00bd3cb0,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_84,unaff_EBX);
      return;
    case 0x34:
      SStringParam::SStringParam(local_f8,(SStringParam *)&DAT_00bd3ca8,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_f4,unaff_EBX);
      return;
    case 0x3c:
      SStringParam::SStringParam(local_48,(SStringParam *)&DAT_00bd3ca0,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_44,unaff_EBX);
      return;
    case 0x3d:
      SStringParam::SStringParam(local_190,(SStringParam *)"L6V5U5",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_18c,unaff_EBX);
      return;
    case 0x3e:
      SStringParam::SStringParam(local_180,(SStringParam *)"X8L8V8U8",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_17c,unaff_EBX);
      return;
    case 0x3f:
      SStringParam::SStringParam(local_e8,(SStringParam *)"Q8W8V8U8",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_e4,unaff_EBX);
      return;
    case 0x40:
      SStringParam::SStringParam(local_1a0,(SStringParam *)"V16U16",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_19c,unaff_EBX);
      return;
    case 0x43:
      SStringParam::SStringParam(local_170,(SStringParam *)"A2W10V10U10",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_16c,unaff_EBX);
      return;
    case 0x47:
      SStringParam::SStringParam(local_160,(SStringParam *)&DAT_00bd3c50,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_15c,unaff_EBX);
      return;
    case 0x49:
      SStringParam::SStringParam(local_150,(SStringParam *)"D15S1",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_14c,unaff_EBX);
      return;
    case 0x4b:
      SStringParam::SStringParam(local_140,(SStringParam *)"D24S8",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_13c,unaff_EBX);
      return;
    case 0x4d:
      SStringParam::SStringParam(local_130,(SStringParam *)"D24X8",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_12c,unaff_EBX);
      return;
    case 0x4f:
      SStringParam::SStringParam(local_120,(SStringParam *)"D24X4S4",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_11c,unaff_EBX);
      return;
    case 0x50:
      SStringParam::SStringParam(local_110,(SStringParam *)&DAT_00bd3c2c,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_10c,unaff_EBX);
      return;
    case 0x51:
      SStringParam::SStringParam(local_108,(SStringParam *)&DAT_00bd3cb8,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_104,unaff_EBX);
      return;
    case 0x6e:
      SStringParam::SStringParam(local_d8,(SStringParam *)"Q16W16V16U16",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_d4,unaff_EBX);
      return;
    case 0x6f:
      SStringParam::SStringParam(local_100,(SStringParam *)&DAT_00bd3c24,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_fc,unaff_EBX);
      return;
    case 0x70:
      SStringParam::SStringParam(local_f0,(SStringParam *)"G16R16F",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_ec,unaff_EBX);
      return;
    case 0x71:
      SStringParam::SStringParam(local_e0,(SStringParam *)"A16B16G16R16F",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_dc,unaff_EBX);
      return;
    case 0x72:
      SStringParam::SStringParam(local_d0,(SStringParam *)&DAT_00bd3c04,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_cc,unaff_EBX);
      return;
    case 0x73:
      SStringParam::SStringParam(local_c0,(SStringParam *)"G32R32F",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_bc,unaff_EBX);
      return;
    case 0x74:
      SStringParam::SStringParam(local_b0,(SStringParam *)"A32B32G32R32F",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_ac,unaff_EBX);
      return;
    case 0x75:
      SStringParam::SStringParam(local_198,(SStringParam *)"CxV8U8",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_194,unaff_EBX);
      return;
    }
  }
  else if ((int)param_2 < 0x34545845) {
    if (param_2 == 0x34545844) {
      local_1a8 = &DAT_00bad8a8;
      local_1a4 = 4;
      CFastString::SetString(param_1,(CFastStringInt *)&local_1a8,unaff_ESI);
      return;
    }
    if ((int)param_2 < 0x32545845) {
      if (param_2 == 0x32545844) {
        SStringParam::SStringParam(local_80,(SStringParam *)&DAT_00bad8b8,(char *)unaff_ESI);
        CFastString::SetString(param_1,local_7c,unaff_EBX);
        return;
      }
      if (param_2 == 0x31545844) {
        SStringParam::SStringParam(local_90,(SStringParam *)&DAT_00bad8c0,(char *)unaff_ESI);
        CFastString::SetString(param_1,local_8c,unaff_EBX);
        return;
      }
      if (param_2 == 0x32495441) {
        SStringParam::SStringParam(local_a0,(SStringParam *)"ATI2_Comp2N",(char *)unaff_ESI);
        CFastString::SetString(param_1,local_9c,unaff_EBX);
        return;
      }
    }
    else {
      if (param_2 == 0x33545844) {
        SStringParam::SStringParam(local_60,(SStringParam *)&DAT_00bad8b0,(char *)unaff_ESI);
        CFastString::SetString(param_1,local_5c,unaff_EBX);
        return;
      }
      if (param_2 == 0x34324644) {
        SStringParam::SStringParam(local_70,(SStringParam *)"DF24_ATI",(char *)unaff_ESI);
        CFastString::SetString(param_1,local_6c,unaff_EBX);
        return;
      }
    }
  }
  else if ((int)param_2 < 0x4c4c554f) {
    if (param_2 == 0x4c4c554e) {
      SStringParam::SStringParam(local_30,(SStringParam *)"NULL_RT",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_2c,unaff_EBX);
      return;
    }
    if (param_2 == 0x35545844) {
      SStringParam::SStringParam(local_40,(SStringParam *)&DAT_00bad8a0,(char *)unaff_ESI);
      CFastString::SetString(param_1,local_3c,unaff_EBX);
      return;
    }
    if (param_2 == 0x36314644) {
      SStringParam::SStringParam(local_50,(SStringParam *)"DF16_ATI",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_4c,unaff_EBX);
      return;
    }
  }
  else {
    if (param_2 == 0x5348564e) {
      SStringParam::SStringParam(local_10,(SStringParam *)"NVHS_HILO",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_c,unaff_EBX);
      return;
    }
    if (param_2 == 0x5548564e) {
      SStringParam::SStringParam(local_20,(SStringParam *)"NVHU_HILO",(char *)unaff_ESI);
      CFastString::SetString(param_1,local_1c,unaff_EBX);
      return;
    }
  }
  if ((((' ' < (char)param_2) && ((char)param_2 < '{')) &&
      (cVar1 = (char)(param_2 >> 8), (byte)(cVar1 - 0x21U) < 0x5a)) &&
     (((byte)((char)(param_2 >> 0x10) - 0x21U) < 0x5a &&
      ((byte)((char)(param_2 >> 0x18) - 0x21U) < 0x5a)))) {
    CFastString::Format((CFastString *)(int)cVar1,param_1,"4CC[%c%c%c%c]");
    return;
  }
  CFastString::Format(param_1,param_1,"Uknowned D3DFormat (0x%08X)");
  return;
}
}

// =================================================
// Function: DecomposeMwTime
// =================================================
void __cdecl
DecomposeMwTime(ulong param_1,int *param_2,ulong *param_3,ulong *param_4,ulong *param_5,
               ulong *param_6)
{
{
  int in_ECX;
  uint *in_EDX;
  uint uVar1;
  int iVar2;
  
  *in_EDX = (uint)(in_ECX < 0);
  if (in_ECX < 0 != 0) {
    in_ECX = -in_ECX;
  }
  *(int *)param_1 = in_ECX / 3600000;
  uVar1 = (uint)(in_ECX % 3600000) / 60000;
  *param_2 = uVar1;
  iVar2 = (in_ECX / 3600000) * 3600000 + uVar1 * 60000;
  uVar1 = (uint)(in_ECX - iVar2) / 1000;
  *param_3 = uVar1;
  *param_4 = ((in_ECX + uVar1 * -1000) - iVar2) / 10;
  return;
}
}

// =================================================
// Function: DecomposeMwTime_24h
// =================================================
void __cdecl
DecomposeMwTime_24h(ulong param_1,int *param_2,ulong *param_3,ulong *param_4,ulong *param_5,
                   ulong *param_6)
{
{
  ulong *in_EAX;
  ulong *in_ECX;
  int *in_EDX;
  uint *unaff_ESI;
  ulong *unaff_retaddr;
  
  DecomposeMwTime((ulong)unaff_ESI,in_EDX,in_ECX,in_EAX,unaff_retaddr,(ulong *)param_1);
  *unaff_ESI = *unaff_ESI % 0x18;
  return;
}
}

// =================================================
// Function: DetachHmsSoundFromAudio
// =================================================
void __cdecl DetachHmsSoundFromAudio(CHmsSoundSource *param_1,CAudioPort *param_2)
{
{
  CMwNod *in_ECX;
  CMwNod *in_EDX;
  CMwNod *unaff_retaddr;
  
  if (in_ECX != (CMwNod *)0x0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x9c) + 0x58) = 0;
    *(undefined4 *)(in_ECX + 0x9c) = 0;
    *(undefined4 *)(in_ECX + 0x94) = 0;
    *(undefined4 *)(in_ECX + 0x98) = 0;
    *(undefined4 *)(in_ECX + 0xa0) = 0;
    if (in_EDX != (CMwNod *)0x0) {
      CMwNod::MwSubDependant(in_ECX,in_EDX,unaff_retaddr);
    }
  }
  return;
}
}

// =================================================
// Function: DicoAddElem
// =================================================
void __cdecl DicoAddElem(SDico *param_1,TiXmlElement *param_2,char *param_3)
{
{
  char *pcVar1;
  char cVar2;
  SLoadedLight *pSVar3;
  CFastString *this;
  CFastString *extraout_EAX;
  CFastString *this_00;
  CFastStringInt *pCVar4;
  void *in_ECX;
  TiXmlElement *unaff_EBX;
  char *unaff_ESI;
  char *unaff_EDI;
  SStringParam *in_stack_ffffffe4;
  undefined *local_14;
  undefined4 local_10;
  void *local_c;
  char *local_4;
  
  local_4 = (char *)0xffffffff;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pSVar3 = CFastBuffer<struct_CGameManialink::SDicoEntry>::AddNewElem
                     (in_ECX,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                             (DAT_00cca150 ^ (uint)&stack0xffffffe0));
  this = operator_new(8);
  if (this == (CFastString *)0x0) {
    this_00 = (CFastString *)0x0;
  }
  else {
    CFastString::CFastString(this,(CFastString *)(*(int *)(unaff_EBX + 0x20) + 8),unaff_EDI);
    this_00 = extraout_EAX;
  }
  *(CFastString **)pSVar3 = this_00;
  if (unaff_ESI != (char *)0x0) {
    local_14 = &DAT_00b2c98c;
    local_10 = 1;
    CFastString::Concat(this_00,(CFastStringInt *)&local_14,in_stack_ffffffe4);
    pcVar1 = unaff_ESI + 1;
    do {
      cVar2 = *unaff_ESI;
      unaff_ESI = unaff_ESI + 1;
    } while (cVar2 != '\0');
    local_4 = unaff_ESI + -(int)pcVar1;
    CFastString::Concat(*(CFastString **)pSVar3,(CFastStringInt *)&stack0xfffffff8,
                        (SStringParam *)this);
  }
  pCVar4 = operator_new(8);
  if (pCVar4 == (CFastStringInt *)0x0) {
    pCVar4 = (CFastStringInt *)0x0;
  }
  else {
    *(undefined4 *)pCVar4 = 0;
    *(undefined **)(pCVar4 + 4) = PTR_DAT_00bbf7d8;
  }
  *(CFastStringInt **)(pSVar3 + 4) = pCVar4;
  CXmlEngine::ReadAssociatedText(unaff_EBX,pCVar4);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: DicoCopy
// =================================================
void __cdecl DicoCopy(SDico *param_1,SDico *param_2)
{
{
  CFastBuffer<class_GxVertex2> *pCVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  CFastString *pCVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 uVar5;
  char *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  SDico *this;
  CFastString *in_stack_ffffffec;
  char *in_stack_fffffff0;
  void *local_c;
  undefined1 *puStack_8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_4;
  
  local_4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff;
  puStack_8 = &LAB_00ac0cb6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            (param_2,(GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
  pCVar1 = (CFastBuffer<class_GxVertex2> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EDI);
  CFastBuffer<struct_CGameManialink::SDicoEntry>::AllocSetCount(param_2,pCVar1,unaff_ESI);
  local_4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
            CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EBP);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  this = param_2;
  if (local_4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    while( true ) {
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar6,(ulong)unaff_EBX);
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](param_2,pCVar6,(ulong)in_stack_ffffffec);
      in_stack_ffffffec = (CFastString *)&DAT_00000008;
      unaff_EBX = (char *)0x72036f;
      pCVar4 = operator_new(8);
      if (pCVar4 == (CFastString *)0x0) {
        uVar5 = 0;
      }
      else {
        in_stack_ffffffec = *(CFastString **)pSVar2;
        unaff_EBX = (char *)0x72038c;
        CFastString::CFastString(pCVar4,in_stack_ffffffec,in_stack_fffffff0);
        uVar5 = extraout_EAX;
      }
      *(undefined4 *)pSVar3 = uVar5;
      pCVar4 = operator_new(8);
      if (pCVar4 == (CFastString *)0x0) {
        uVar5 = 0;
      }
      else {
        CFastString::CFastString(pCVar4,*(CFastString **)(pSVar2 + 4),unaff_EBX);
        uVar5 = extraout_EAX_00;
      }
      pCVar6 = pCVar6 + 1;
      *(undefined4 *)(pSVar3 + 4) = uVar5;
      if (local_4 <= pCVar6) break;
      this = (SDico *)0x0;
    }
  }
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: DicoGetText
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl DicoGetText(SDico *param_1,char *param_2,CFastStringInt *param_3)
{
{
  int iVar1;
  CFastStringInt *unaff_EBX;
  
  if ((_DAT_00d6b074 & 1) == 0) {
    _DAT_00d6b074 = _DAT_00d6b074 | 1;
    DAT_00d6b06c = 0;
    DAT_00d6b070 = (SStringParam *)PTR_DAT_00bbf7d8;
    _atexit(`int___cdecl_DicoGetText(struct_CGameManialink::SDico_const&,char_const*,class_CFastStringInt&)'
            ::__l2::_dynamic_atexit_destructor_for__sTemp__);
  }
  if (DAT_00d6b06c != 0) {
    DAT_00d6b06c = 0;
    *DAT_00d6b070 = (SStringParam)0x0;
  }
  iVar1 = DicoGetText((SDico *)param_2,(char *)&DAT_00d6b06c,unaff_EBX);
  if (iVar1 != 0) {
    CFastStringInt::SetUtf8(param_3,(CFastStringInt *)&stack0xfffffff8,DAT_00d6b070);
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: Dx9Buffer_GetErrors
// =================================================
void __cdecl
Dx9Buffer_GetErrors(ID3DXBuffer *param_1,CFastString *param_2,CFastString *param_3,
                   CSystemFids *param_4)
{
{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  CSystemFids *extraout_EAX;
  CFastString *pCVar4;
  undefined *puVar5;
  undefined *puVar6;
  CFastString *pCVar7;
  CSystemFid *unaff_EBX;
  CFastStringInt *unaff_ESI;
  CFastString *unaff_EDI;
  SHeaderCommunity *in_stack_ffffff5c;
  CFastString *pCVar8;
  CSystemFid *pCVar9;
  SHeaderCommunity *pSVar10;
  SHeaderCommunity *pSVar11;
  ID3DXBuffer *pIVar12;
  CFastString *pCVar13;
  CPlugFileGpuBuilder *pCVar14;
  CPlugFileGpuBuilder *pCVar15;
  CFastString *in_stack_ffffff7c;
  undefined *in_stack_ffffff80;
  CFastString *pCStack_7c;
  CFastString aCStack_78 [4];
  ulong uStack_74;
  undefined *puStack_70;
  undefined *puStack_6c;
  undefined *local_68;
  undefined *local_64;
  undefined *puStack_60;
  CFastString local_5c [4];
  undefined4 uStack_58;
  undefined *puStack_54;
  CFastString *pCStack_50;
  undefined *puStack_48;
  undefined *apuStack_44 [2];
  undefined4 uStack_3c;
  undefined *puStack_38;
  ulong uStack_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined4 local_20;
  undefined *local_1c;
  undefined *local_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00addf88;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  CFastString::CFastString(local_5c,param_2,(char *)(DAT_00cca150 ^ (uint)&stack0xffffff70));
  local_68 = (undefined *)0x0;
  local_64 = PTR_DAT_00bbf7d8;
  local_28 = (undefined *)0x0;
  local_24 = PTR_DAT_00bbf7d8;
  local_30 = 2;
  local_2c = (undefined *)0xffffffff;
  local_20 = 0;
  local_1c = (undefined *)0x0;
  local_18 = PTR_lpOutputString_00b2bcc4_00d34104;
  local_8 = 2;
  pIVar12 = param_1;
  uVar2 = (**(code **)(*(int *)param_1 + 0xc))();
  puStack_54 = (undefined *)(**(code **)(*(int *)param_1 + 0x10))();
  pCVar8 = (CFastString *)0x8db57f;
  uStack_58 = uVar2;
  CFastString::SetString
            ((CFastString *)&puStack_70,(CFastStringInt *)&uStack_58,(SStringParam *)param_1);
  iVar3 = CFastString::GetNextToken
                    ((CFastString *)&puStack_6c,(CFastStringInt *)&uStack_34,
                     (SFastTokenInt *)pIVar12);
  puVar5 = puStack_48;
  puVar1 = apuStack_44[0];
  apuStack_44[0] = local_28;
  puStack_48 = local_24;
  do {
    local_24 = puStack_48;
    local_28 = apuStack_44[0];
    if (iVar3 == 0) {
      if (puStack_48 != PTR_DAT_00bbf7d8) {
        puVar6 = puStack_48 + -1;
        if ((puStack_48[-1] & 0x80) != 0) {
          puVar6 = puStack_48 + -4;
        }
        puStack_48 = puVar5;
        apuStack_44[0] = puVar1;
        operator_delete__(puVar6);
        local_28 = (undefined *)0x0;
        local_24 = PTR_DAT_00bbf7d8;
        puVar5 = puStack_48;
        puVar1 = apuStack_44[0];
      }
      apuStack_44[0] = puVar1;
      puStack_48 = puVar5;
      if (local_64 != PTR_DAT_00bbf7d8) {
        puVar5 = local_64 + -1;
        if ((local_64[-1] & 0x80) != 0) {
          puVar5 = local_64 + -4;
        }
        operator_delete__(puVar5);
        local_68 = (undefined *)0x0;
        local_64 = PTR_DAT_00bbf7d8;
      }
      if (puStack_54 != PTR_DAT_00bbf7d8) {
        puVar5 = puStack_54 + -1;
        if ((puStack_54[-1] & 0x80) != 0) {
          puVar5 = puStack_54 + -4;
        }
        operator_delete__(puVar5);
      }
      ExceptionList = puStack_10;
      return;
    }
    pCVar9 = (CSystemFid *)0x8db5c6;
    CFastString::ConcatAndNewLine
              (param_3,(CFastString *)&puStack_48,
               (SStringParam *)PTR_lpOutputString_00b2bcc4_00d34104,(char *)unaff_EDI);
    unaff_EDI = (CFastString *)0x0;
    pCVar13 = (CFastString *)&DAT_00000028;
    pSVar10 = (SHeaderCommunity *)0x8db5d2;
    uStack_74 = CFastString::FindFirst
                          ((CFastString *)&local_24,(CFastStringInt *)&DAT_00000028,0,
                           (ulong)unaff_ESI);
    pCVar15 = (CPlugFileGpuBuilder *)unaff_ESI;
    if (uStack_74 != 0xffffffff) {
      pCVar15 = (CPlugFileGpuBuilder *)0x0;
      if (uStack_74 == 0) {
LAB_008db74a:
        CFastString::CFastString
                  ((CFastString *)&stack0xffffff80,(CFastString *)(pCVar15 + uStack_34 + 1),
                   (char *)pCVar8);
        local_14 = (void *)CONCAT31(local_14._1_3_,5);
        CFastString::TruncAfterChar
                  ((CFastString *)&pCStack_7c,(CFastString *)&DAT_00000029,'\x01',(int)pCVar9);
        pCVar8 = (CFastString *)&stack0xffffff78;
        in_stack_ffffff5c = (SHeaderCommunity *)0x8db780;
        iVar3 = CFastString::GetInteger(aCStack_78,pCVar8,(int *)0x0,(ulong)pSVar10);
        pCVar15 = (CPlugFileGpuBuilder *)unaff_ESI;
        if (iVar3 == 0) {
          uStack_c = CONCAT31(uStack_c._1_3_,2);
          if (puStack_70 != PTR_DAT_00bbf7d8) {
            puVar5 = puStack_70 + -1;
            if ((puStack_70[-1] & 0x80) != 0) {
              puVar5 = puStack_70 + -4;
            }
            operator_delete__(puVar5);
            uStack_74 = 0;
            puStack_70 = PTR_DAT_00bbf7d8;
            pCVar15 = (CPlugFileGpuBuilder *)unaff_ESI;
          }
        }
        else {
          local_64 = (undefined *)0x0;
          puStack_60 = PTR_DAT_00bbf7d8;
          uStack_c = CONCAT31(uStack_c._1_3_,6);
          if (in_stack_ffffff7c == (CFastString *)0x0) {
            uStack_c = CONCAT31(uStack_c._1_3_,2);
            if (puStack_70 != PTR_DAT_00bbf7d8) {
              puVar5 = puStack_70 + -1;
              if ((puStack_70[-1] & 0x80) != 0) {
                puVar5 = puStack_70 + -4;
              }
              operator_delete__(puVar5);
              uStack_74 = 0;
              puStack_70 = PTR_DAT_00bbf7d8;
              pCVar15 = (CPlugFileGpuBuilder *)unaff_ESI;
            }
          }
          else {
            pCVar4 = in_stack_ffffff7c + -1;
            for (pCVar7 = (CFastString *)
                          (((int)(in_stack_ffffff7c + -2) < 1) - 1 & (uint)(in_stack_ffffff7c + -2))
                ; pCVar7 <= in_stack_ffffff7c; pCVar7 = pCVar7 + 1) {
              pCVar8 = (CFastString *)0x8db890;
              iVar3 = CFastString::GetLineAt(local_5c,pCVar7,(ulong)&local_64,pCVar13);
              if (iVar3 == 0) break;
              CFastString::operator<<
                        (param_3,(CPlugFileGpuBuilder *)&lpOutputString_00b2bcc4,(char *)unaff_EDI);
              if (pCVar7 == pCStack_7c) {
                pCVar14 = (CPlugFileGpuBuilder *)&DAT_00b2ce64;
              }
              else {
                pCVar14 = (CPlugFileGpuBuilder *)&DAT_00b2d0d4;
              }
              pCVar13 = (CFastString *)0x8db8b9;
              CFastString::operator<<(param_3,pCVar14,(char *)pCVar15);
              pCVar15 = (CPlugFileGpuBuilder *)&uStack_58;
              unaff_EDI = (CFastString *)0x8db8c5;
              CFastString::operator<<(param_3,pCVar15,(char *)unaff_EBX);
            }
            in_stack_ffffff7c = pCVar4;
            if ((uStack_34 & 1) == 0) {
              CFastString::operator<<(param_3,(CPlugFileGpuBuilder *)&DAT_00bbd078,(char *)pCVar13);
              in_stack_ffffff7c = pCVar4;
            }
            if (puStack_60 != PTR_DAT_00bbf7d8) {
              puVar5 = puStack_60 + -1;
              if ((puStack_60[-1] & 0x80) != 0) {
                puVar5 = puStack_60 + -4;
              }
              operator_delete__(puVar5);
              local_64 = (undefined *)0x0;
              puStack_60 = PTR_DAT_00bbf7d8;
            }
            uStack_c = CONCAT31(uStack_c._1_3_,2);
            if (puStack_70 != PTR_DAT_00bbf7d8) {
              puVar5 = puStack_70 + -1;
              if ((puStack_70[-1] & 0x80) != 0) {
                puVar5 = puStack_70 + -4;
              }
              operator_delete__(puVar5);
              uStack_74 = 0;
              puStack_70 = PTR_DAT_00bbf7d8;
            }
          }
        }
      }
      else {
        puStack_70 = (undefined *)0x0;
        puStack_6c = PTR_DAT_00bbf7d8;
        pCVar15 = (CPlugFileGpuBuilder *)&puStack_38;
        puStack_38 = local_1c;
        unaff_EDI = (CFastString *)0x8db617;
        uStack_34 = uStack_74;
        CFastString::SetString
                  ((CFastString *)&puStack_70,(CFastStringInt *)pCVar15,(SStringParam *)unaff_EBX);
        if (param_4 == (CSystemFids *)0x0) {
          if (local_68 != PTR_DAT_00bbf7d8) {
            unaff_EBX = (CSystemFid *)(local_68 + -1);
            if ((local_68[-1] & 0x80) != 0) {
              unaff_EBX = (CSystemFid *)(local_68 + -4);
            }
            pCVar15 = (CPlugFileGpuBuilder *)0x8db648;
            operator_delete__(unaff_EBX);
            puStack_6c = (undefined *)0x0;
            local_68 = PTR_DAT_00bbf7d8;
          }
        }
        else {
          local_2c = local_68;
          local_28 = puStack_6c;
          CFastStringInt::CFastStringInt
                    (apuStack_44,(CFastStringInt *)&local_2c,(SStringParam *)in_stack_ffffff7c);
          in_stack_ffffff7c = (CFastString *)0x0;
          unaff_EBX = (CSystemFid *)0x1;
          unaff_EDI = (CFastString *)0x8db68f;
          pCVar15 = (CPlugFileGpuBuilder *)extraout_EAX;
          pCVar9 = CSystemFids::FindFid
                             (param_4,extraout_EAX,(CFastStringInt *)0x1,0,
                              (EFindWay)in_stack_ffffff80);
          param_3._1_3_ = (undefined3)((uint)param_3 >> 8);
          param_3 = (CFastString *)CONCAT31(param_3._1_3_,3);
          pSVar11 = pSVar10;
          if (puStack_38 != PTR_DAT_00bbf7dc) {
            if ((puStack_38[-1] & 0x80) == 0) {
              in_stack_ffffff80 = puStack_38 + -2;
            }
            else {
              in_stack_ffffff80 = puStack_38 + -4;
            }
            in_stack_ffffff7c = (CFastString *)0x8db6b9;
            operator_delete__(in_stack_ffffff80);
            uStack_3c = 0;
            puStack_38 = PTR_DAT_00bbf7dc;
            pSVar11 = pSVar10;
          }
          if (pCVar9 == (CSystemFid *)0x0) {
            param_3 = (CFastString *)CONCAT31(param_3._1_3_,2);
            if (puStack_60 != PTR_DAT_00bbf7d8) {
              puVar5 = puStack_60 + -1;
              if ((puStack_60[-1] & 0x80) != 0) {
                puVar5 = puStack_60 + -4;
              }
              in_stack_ffffff7c = (CFastString *)0x8db7f2;
              operator_delete__(puVar5);
              local_64 = (undefined *)0x0;
              puStack_60 = PTR_DAT_00bbf7d8;
            }
          }
          else {
            in_stack_ffffff80 = (undefined *)0x0;
            in_stack_ffffff7c = (CFastString *)0x1;
            pCVar15 = (CPlugFileGpuBuilder *)0x8db6e4;
            unaff_EBX = pCVar9;
            pSVar10 = (SHeaderCommunity *)(**(code **)**(undefined4 **)(pCVar9 + 0x6c))();
            if (pSVar10 != (SHeaderCommunity *)0x0) {
              pCVar4 = (CFastString *)(**(code **)(*(int *)pSVar10 + 0x18))();
              CFastString::SetLength
                        ((CFastString *)&puStack_60,pCVar4,(ulong)pSVar11,(int)pCVar13,
                         (char)unaff_EDI);
              pCVar13 = pCStack_50;
              (**(code **)(*(int *)pSVar10 + 4))();
              pCVar8 = (CFastString *)0x8db730;
              (**(code **)(**(int **)(pCVar9 + 0x6c) + 4))();
              local_1c = (undefined *)CONCAT31(local_1c._1_3_,2);
              CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                        (&stack0xffffff74,in_stack_ffffff5c);
              unaff_EDI = pCVar4;
              unaff_ESI = (CFastStringInt *)pCVar15;
              goto LAB_008db74a;
            }
            puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,2);
            CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xffffff80,pSVar11);
          }
        }
      }
    }
    iVar3 = CFastString::GetNextToken
                      ((CFastString *)&puStack_6c,(CFastStringInt *)&uStack_34,
                       (SFastTokenInt *)pCVar13);
    unaff_ESI = (CFastStringInt *)pCVar15;
    puVar5 = puStack_48;
    puVar1 = apuStack_44[0];
    apuStack_44[0] = local_28;
    puStack_48 = local_24;
  } while( true );
}
}

// =================================================
// Function: Dx9StaticInit
// =================================================
void __cdecl Dx9StaticInit(void)
{
{
  SStringParam *pSVar1;
  LSTATUS LVar2;
  int iVar3;
  CPlugFileGpuBuilder *this;
  LPCWSTR pWVar4;
  CDx9DeviceCaps *extraout_EAX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  char *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CDx9DeviceCaps *pCVar9;
  IDirect3D9 *pIVar10;
  CFastBufferCat<char,struct_SFastCat> *pCVar11;
  CFastBufferCat<char,struct_SFastCat> *pCVar12;
  wchar_t *pwVar13;
  _D3DFORMAT _Var14;
  ulong in_stack_ffffffd4;
  LPCWSTR local_28;
  HKEY local_24;
  char *local_20;
  int local_1c;
  DWORD local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00aea7d8;
  local_10 = ExceptionList;
  pSVar1 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xffffffc4;
  ExceptionList = &local_10;
  Dx9VendorStaticInit();
  Dx9StdGpuStaticInit();
  local_8 = 0;
  DAT_00d75404 = 0;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\Direct3D",0,1,&local_24);
  if (LVar2 == 0) {
    local_28 = (LPCWSTR)&DAT_00000004;
    local_18 = 4;
    local_1c = 0;
    LVar2 = RegQueryValueExW(local_24,L"LoadDebugRuntime",(LPDWORD)0x0,(LPDWORD)&local_28,
                             (LPBYTE)&local_1c,&local_18);
    if (((LVar2 == 0) && (local_18 != 0)) && (local_1c != 0)) {
      DAT_00d75404 = 1;
    }
    RegCloseKey(local_24);
  }
  if (DAT_00d75404 != 0) {
    local_20 = "TmForever";
    local_1c = 9;
    CFastStringInt::CFastStringInt(&stack0xffffffd4,(CFastStringInt *)&local_20,pSVar1);
    pSVar1 = (SStringParam *)0x1;
    local_8._0_1_ = 1;
    pwVar13 = (wchar_t *)0x98416b;
    ShowCursor(1);
    pWVar4 = local_28;
    pwVar13 = CClassicI18n::GetTranslatedStringInternal
                        ((CClassicI18n *)&DAT_00d71d10,
                         (CClassicI18n *)
                         L"You\'re using DEBUG DirectX runtime, the game performance will be low.\nDo you still want to continue ?"
                         ,pwVar13);
    iVar3 = MessageBoxW((HWND)0x0,pwVar13,pWVar4,4);
    if (iVar3 == 7) {
      if (DAT_00d71e54 != 0) {
        DAT_00d71e54 = 0;
        *DAT_00d71e58 = 0;
      }
      this = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)
                        "[Dx9] exit(1) after user prompt on dx9 debug runtime",(char *)pSVar1);
      CFastString::operator<<
                ((CFastString *)this,(CPlugFileGpuBuilder *)&lpOutputString_00b2bcc4,unaff_EDI);
      CClassicLog::AddLogStringInFile();
      CClassicLog::FlushWhenTimeOut((CClassicLog *)&DAT_00d71e20,(CClassicLog *)0x1,unaff_ESI);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    ShowCursor(0);
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_28 != (LPCWSTR)PTR_DAT_00bbf7dc) {
      if ((*(byte *)((int)local_28 + -1) & 0x80) == 0) {
        pWVar4 = local_28 + -1;
      }
      else {
        pWVar4 = local_28 + -2;
      }
      operator_delete__(pWVar4);
      in_stack_ffffffd4 = 0;
      local_28 = (LPCWSTR)PTR_DAT_00bbf7dc;
    }
  }
  _Var14 = 0x20;
  DAT_00d770a0 = 0;
  DAT_00d770a8 = 0;
  _Direct3DCreate9_4();
  DAT_00d770a4 = extraout_EAX;
  if (extraout_EAX != (CDx9DeviceCaps *)0x0) {
    pCVar12 = (CFastBufferCat<char,struct_SFastCat> *)0x1;
    DAT_00d770ac = (IDirect3D9 *)0x0;
    DAT_00d770b0 = 1;
    _D3DPERF_SetOptions_4();
    pCVar11 = (CFastBufferCat<char,struct_SFastCat> *)&DAT_00d770b4;
    pCVar9 = DAT_00d770a4;
    pIVar10 = DAT_00d770ac;
    (**(code **)(*(int *)DAT_00d770a4 + 0x20))();
    CDx9DeviceCaps::BeforeCreateDevice
              ((CDx9DeviceCaps *)&DAT_00d770c4,DAT_00d770a4,DAT_00d770ac,DAT_00d770b0,
               (_D3DDEVTYPE)pCVar9);
    CFastArray<struct_CHmsViewport::SDisplayMode>::SetCount
              (&DAT_00d7782c,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,(ulong)pIVar10);
    CFastBufferCat<char,struct_SFastCat>::RemoveAll(&DAT_00d77834,pCVar11);
    CFastBufferCat<char,struct_SFastCat>::RemoveAll(&DAT_00d77858,pCVar12);
    SDx9Static::FullScreenRetrieveModes(&DAT_00d770a0,(SDx9Static *)&DAT_00000016,_Var14);
    SDx9Static::FullScreenRetrieveModes
              (&DAT_00d770a0,(SDx9Static *)&DAT_00000017,(_D3DFORMAT)pSVar1);
    CFastBufferCat<unsigned_long,struct_SFastCat>::QSortEachCatArithmetic
              (&DAT_00d77834,(CFastBufferCat<unsigned_long,struct_SFastCat> *)0x1,0,0xffffffff,
               (ulong)unaff_EDI);
    CFastBufferCat<unsigned_long,struct_SFastCat>::QSortEachCatArithmetic
              (&DAT_00d77858,(CFastBufferCat<unsigned_long,struct_SFastCat> *)0x1,0,0xffffffff,
               unaff_ESI);
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff;
    DAT_00d7787c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff;
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d7782c,unaff_EBX);
    for (pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0; pCVar7 < pCVar5;
        pCVar7 = pCVar7 + 1) {
      pSVar6 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                         (&DAT_00d7782c,pCVar7,in_stack_ffffffd4);
      if ((*(int *)pSVar6 == DAT_00d770b4) && (*(int *)(pSVar6 + 4) == DAT_00d770b8)) {
        pCVar8 = pCVar7;
        DAT_00d7787c = pCVar7;
        if ((DAT_00d770c0 == 0x16) || (DAT_00d77880 = 0, DAT_00d770c0 == 0x15)) {
          DAT_00d77880 = 1;
        }
      }
    }
    if (pCVar8 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      DAT_00d7787c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    }
  }
  ExceptionList = local_10;
  return;
}
}

// =================================================
// Function: Dx9StdGpuStaticInit
// =================================================
void __cdecl Dx9StdGpuStaticInit(void)
{
{
  DAT_00d77970 = 1;
  DAT_00d77974 = 0;
  DAT_00d77978 = 1;
  DAT_00d7797c = 1;
  DAT_00d77980 = 1;
  DAT_00d77984 = 1;
  DAT_00d77988 = 0;
  DAT_00d7798c = 1;
  DAT_00d77990 = 1;
  DAT_00d77994 = 1;
  DAT_00d77998 = 1;
  DAT_00d7799c = 1;
  DAT_00d779a0 = 1;
  DAT_00d779a4 = 1;
  DAT_00d779a8 = 0;
  DAT_00d779ac = 1;
  DAT_00d779b0 = 1;
  DAT_00d779b4 = 1;
  DAT_00d779b8 = 1;
  DAT_00d779bc = 1;
  DAT_00d779c0 = 1;
  DAT_00d779c4 = 0;
  DAT_00d779c8 = 0;
  DAT_00d779cc = 0;
  DAT_00d779d0 = 0;
  DAT_00d779d4 = 0;
  DAT_00d779d8 = 0;
  DAT_00d779dc = 0;
  DAT_00d779e0 = 0;
  DAT_00d778d0 = 0;
  DAT_00d778d4 = 0;
  DAT_00d778d8 = 1;
  DAT_00d778dc = 0;
  DAT_00d778e0 = 1;
  DAT_00d778e4 = 0;
  DAT_00d778e8 = 1;
  DAT_00d778ec = 0;
  DAT_00d778f0 = 1;
  DAT_00d778f4 = 0;
  DAT_00d778f8 = 1;
  DAT_00d778fc = 0;
  DAT_00d77900 = 1;
  DAT_00d77904 = 0;
  DAT_00d77908 = 0;
  DAT_00d7790c = 1;
  DAT_00d77910 = 0;
  DAT_00d77914 = 0;
  DAT_00d77918 = 1;
  DAT_00d7791c = 0;
  DAT_00d77920 = 1;
  DAT_00d77924 = 0;
  DAT_00d77928 = 0;
  DAT_00d7792c = 1;
  DAT_00d77930 = 0;
  DAT_00d77934 = 1;
  DAT_00d77938 = 0;
  DAT_00d7793c = 1;
  DAT_00d77940 = 0;
  DAT_00d77944 = 1;
  DAT_00d77948 = 0;
  DAT_00d7794c = 0;
  DAT_00d77950 = 0;
  DAT_00d77954 = 0;
  DAT_00d77958 = 0;
  DAT_00d7795c = 0;
  DAT_00d77960 = 0;
  DAT_00d77964 = 0;
  DAT_00d77968 = 0;
  return;
}
}

// =================================================
// Function: Dx9VendorStaticInit
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Dx9VendorStaticInit(void)
{
{
  _DAT_00d779e8 = &DAT_00bd3ef4;
  _DAT_00d779f0 = 0xa18d8;
  _DAT_00d779f4 = 0x6000e;
  _DAT_00d779f8 = "www.ati.com/support/driver.html";
  _DAT_00d77a00 = "Trident";
  _DAT_00d77a08 = 0;
  _DAT_00d77a0c = 0;
  _DAT_00d77a10 = &DAT_00bacf08;
  _DAT_00d77a18 = "Matrox";
  _DAT_00d77a20 = 0;
  _DAT_00d77a24 = 0;
  _DAT_00d77a28 = "www.matrox.com/mga/support/drivers/latest/home.cfm";
  _DAT_00d77a30 = &DAT_00bd3e8c;
  _DAT_00d77a38 = 0;
  _DAT_00d77a3c = 0;
  _DAT_00d77a40 = "download.sis.com/sisdlc/index.jsp";
  _DAT_00d77a48 = "PowerVR";
  _DAT_00d77a50 = 0;
  _DAT_00d77a54 = 0;
  _DAT_00d77a58 = "www.powervr.com/Downloads.asp";
  _DAT_00d77a60 = "DiamondMM";
  _DAT_00d77a68 = 0;
  _DAT_00d77a6c = 0;
  _DAT_00d77a70 = &DAT_00bacf08;
  _DAT_00d77a78 = "NVidia";
  _DAT_00d77a80 = 0xa14b7;
  _DAT_00d77a84 = 0x6000e;
  _DAT_00d77a88 = "www.nvidia.com/content/drivers/drivers.asp";
  _DAT_00d77a90 = "VIA_S3G";
  _DAT_00d77a98 = 0;
  _DAT_00d77a9c = 0;
  _DAT_00d77aa0 = &DAT_00bacf08;
  _DAT_00d77aa8 = &DAT_00bd3df8;
  _DAT_00d77ab0 = 0;
  _DAT_00d77ab4 = 0;
  _DAT_00d77ab8 = "www.3dfx.com";
  _DAT_00d77ac0 = "3DLabs";
  _DAT_00d77ac8 = 0;
  _DAT_00d77acc = 0;
  _DAT_00d77ad0 = &DAT_00bacf08;
  _DAT_00d77ad8 = &DAT_00bd3ddc;
  _DAT_00d77ae0 = 0;
  _DAT_00d77ae4 = 0;
  _DAT_00d77ae8 = "www.s3graphics.com/DRVVIEW.HTM";
  _DAT_00d77af0 = "Intel";
  _DAT_00d77af8 = 0;
  _DAT_00d77afc = 0;
  _DAT_00d77b00 = "downloadfinder.intel.com/scripts-df-external/Support_Intel.aspx#";
  return;
}
}

// =================================================
// Function: ElemCreateEntry
// =================================================
CControlEntry * __cdecl ElemCreateEntry(TiXmlElement *param_1,CGameManialinkPage *param_2)
{
{
  SStringParam SVar1;
  TiXmlElement TVar2;
  CGameManialinkEntry *pCVar3;
  CGameManialinkEntry *this;
  CMwNod *extraout_EAX;
  SStringParam *pSVar4;
  SStringParam *pSVar5;
  TiXmlElement *pTVar6;
  SLoadedLight *pSVar7;
  CControlBase *extraout_EAX_00;
  TiXmlElement *in_ECX;
  int *unaff_ESI;
  CControlBase *this_00;
  char *unaff_EDI;
  CMwNod *this_01;
  void *in_stack_0000001c;
  int in_stack_00000020;
  CControlEntry *pCStack00000028;
  char *in_stack_ffffffe8;
  int *in_stack_ffffffec;
  CMwNod *pCVar8;
  CControlEntry *pCVar9;
  
  pCVar8 = (CMwNod *)&LAB_00ac0b36;
  pCVar3 = (CGameManialinkEntry *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &stack0xfffffff4;
  this = operator_new(0x28);
  pCVar9 = (CControlEntry *)0x0;
  if (this == (CGameManialinkEntry *)0x0) {
    this_01 = (CMwNod *)0x0;
  }
  else {
    CGameManialinkEntry::CGameManialinkEntry(this,pCVar3);
    this_01 = extraout_EAX;
  }
  pSVar4 = (SStringParam *)
           TiXmlElement::Attribute(in_ECX,(TiXmlElement *)"default",unaff_EDI,unaff_ESI);
  if (pSVar4 == (SStringParam *)0x0) {
    pSVar5 = (SStringParam *)0x0;
  }
  else {
    pSVar5 = pSVar4;
    do {
      SVar1 = *pSVar5;
      pSVar5 = pSVar5 + 1;
    } while (SVar1 != (SStringParam)0x0);
    pSVar5 = pSVar5 + -(int)(pSVar4 + 1);
  }
  CFastStringInt::SetString(this_01 + 0x1c,(CFastStringInt *)&stack0xfffffff0,(SStringParam *)this);
  param_1 = (TiXmlElement *)
            TiXmlElement::Attribute
                      (in_ECX,(TiXmlElement *)&DAT_00b32cb4,in_stack_ffffffe8,in_stack_ffffffec);
  if (param_1 == (TiXmlElement *)0x0) {
    param_2 = (CGameManialinkPage *)0x0;
  }
  else {
    pTVar6 = param_1;
    do {
      TVar2 = *pTVar6;
      pTVar6 = pTVar6 + 1;
    } while (TVar2 != (TiXmlElement)0x0);
    param_2 = (CGameManialinkPage *)(pTVar6 + -(int)(param_1 + 1));
  }
  CFastString::SetString((CFastString *)(this_01 + 0x14),(CFastStringInt *)&param_1,pSVar4);
  pSVar7 = CFastBuffer<class_CMwNodRef<class_CGameManialinkEntry>_>::AddNewElem
                     ((void *)(in_stack_00000020 + 0x14),
                      (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pSVar5);
  if (this_01 != *(CMwNod **)pSVar7) {
    if (this_01 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_01,pCVar8);
    }
    if (*(CMwNod **)pSVar7 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)pSVar7,(CMwNod *)pCVar9);
    }
    *(CMwNod **)pSVar7 = this_01;
  }
  pCStack00000028 = operator_new(0x160);
  in_stack_00000020 = 1;
  if (pCStack00000028 == (CControlEntry *)0x0) {
    this_00 = (CControlBase *)0x0;
  }
  else {
    CControlEntry::CControlEntry(pCStack00000028,pCVar9);
    this_00 = extraout_EAX_00;
  }
  in_stack_00000020 = 0xffffffff;
  (**(code **)(*(int *)this_00 + 0x4c))();
  CControlBase::CreateStack(this_00,(CControlBase *)this_01,(CMwNod *)"Value",(char *)pCVar9);
  (**(code **)(*(int *)this_00 + 0x178))();
  ExceptionList = in_stack_0000001c;
  return (CControlEntry *)this_00;
}
}

// =================================================
// Function: ElemCreateFileEntry
// =================================================
CControlEntry * __cdecl ElemCreateFileEntry(TiXmlElement *param_1,CGameManialinkPage *param_2)
{
{
  CGameManialinkFileEntry *this;
  char cVar1;
  EEvent EVar2;
  CGameManialinkFileEntry *pCVar3;
  CGameManialinkFileEntry *this_00;
  CGameManialinkFileEntry *extraout_EAX;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  char *pcVar7;
  int *piVar8;
  SLoadedLight *pSVar9;
  CControlBase *extraout_EAX_00;
  undefined *puVar10;
  SStringParam *unaff_EBX;
  SStringParam *unaff_EBP;
  int *unaff_ESI;
  CControlBase *this_01;
  char *unaff_EDI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar11;
  CControlEntry *pCVar12;
  undefined *puVar13;
  char *in_stack_00000014;
  int in_stack_00000018;
  undefined4 uStack0000001c;
  char *pcStack00000024;
  int iStack00000028;
  undefined1 uStack0000002c;
  undefined4 in_stack_00000030;
  undefined *in_stack_00000034;
  undefined *in_stack_0000003c;
  undefined1 uStack00000048;
  undefined3 uStack00000049;
  CControlEntry *pCStack00000054;
  int *in_stack_ffffffd8;
  SStringParam *in_stack_ffffffdc;
  SStringParam *in_stack_ffffffe8;
  CFastStringInt *in_stack_ffffffec;
  SStringParam *pSVar14;
  CFastString *pCVar15;
  
  pSVar14 = (SStringParam *)&LAB_00ac0b86;
  pCVar3 = (CGameManialinkFileEntry *)(DAT_00cca150 ^ (uint)&stack0xffffffc4);
  ExceptionList = &stack0xfffffff4;
  this_00 = operator_new(0x3c);
  pCVar15 = (CFastString *)0x0;
  if (this_00 == (CGameManialinkFileEntry *)0x0) {
    pCVar3 = (CGameManialinkFileEntry *)0x0;
  }
  else {
    CGameManialinkFileEntry::CGameManialinkFileEntry(this_00,pCVar3);
    pCVar3 = extraout_EAX;
  }
  pCVar11 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0xffffffff;
  pcVar4 = TiXmlElement::Attribute(param_1,(TiXmlElement *)"default",unaff_EDI,unaff_ESI);
  if (pcVar4 == (char *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    pcVar5 = pcVar4;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    piVar6 = (int *)(pcVar5 + -(int)(pcVar4 + 1));
  }
  this = pCVar3 + 0x1c;
  CFastStringInt::SetString(this,(CFastStringInt *)&stack0xffffffe0,unaff_EBP);
  if (*(int *)this == 0) {
    piVar6 = (int *)&DAT_00b2c020;
    in_stack_ffffffe8 = (SStringParam *)0x3;
    CFastStringInt::SetString(this,(CFastStringInt *)&stack0xffffffe4,unaff_EBX);
  }
  pcVar5 = TiXmlElement::Attribute
                     (param_1,(TiXmlElement *)&DAT_00b32cb4,(char *)this_00,in_stack_ffffffd8);
  if (pcVar5 == (char *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    pcVar7 = pcVar5;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    piVar8 = (int *)(pcVar7 + -(int)(pcVar5 + 1));
  }
  CFastString::SetString
            ((CFastString *)(pCVar3 + 0x14),(CFastStringInt *)&stack0xfffffff0,in_stack_ffffffdc);
  puVar10 = PTR_DAT_00bbf7dc;
  uStack0000001c = 1;
  pcVar4 = TiXmlElement::Attribute(param_1,(TiXmlElement *)"folder",pcVar4,piVar6);
  if (pcVar4 != (char *)0x0) {
    pcVar7 = pcVar4;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    in_stack_00000018 = (int)pcVar7 - (int)(pcVar4 + 1);
    in_stack_00000014 = pcVar4;
    CFastStringInt::SetUtf8(&stack0x0000000c,(CFastStringInt *)&stack0x00000014,in_stack_ffffffe8);
  }
  CGameManialinkFileEntry::SetFolder
            (pCVar3,(CGameManialinkFileEntry *)&stack0x00000010,in_stack_ffffffec);
  pCVar12 = (CControlEntry *)0x0;
  uStack0000002c = 2;
  puVar13 = PTR_DAT_00bbf7d8;
  pcStack00000024 = TiXmlElement::Attribute(param_1,(TiXmlElement *)&DAT_00b64530,pcVar5,piVar8);
  if (pcStack00000024 == (char *)0x0) {
    iStack00000028 = 0;
  }
  else {
    pcVar4 = pcStack00000024;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    iStack00000028 = (int)pcVar4 - (int)(pcStack00000024 + 1);
  }
  CFastString::SetString((CFastString *)&stack0x00000014,(CFastStringInt *)&stack0x00000024,pSVar14)
  ;
  CGameManialinkFileEntry::SetFileType(pCVar3,(CGameManialinkFileEntry *)&stack0x00000018,pCVar15);
  EVar2 = (EEvent)_uStack00000048;
  pSVar9 = CFastBuffer<class_CMwNodRef<class_CGameManialinkEntry>_>::AddNewElem
                     ((void *)((int)_uStack00000048 + 0x14),pCVar11);
  if (pCVar3 != *(CGameManialinkFileEntry **)pSVar9) {
    CMwNod::MwAddRef((CMwNod *)pCVar3,(CMwNod *)0x0);
    if (*(CMwNod **)pSVar9 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)pSVar9,(CMwNod *)puVar10);
    }
    *(CGameManialinkFileEntry **)pSVar9 = pCVar3;
  }
  pCStack00000054 = operator_new(0x160);
  uStack00000048 = 3;
  if (pCStack00000054 == (CControlEntry *)0x0) {
    this_01 = (CControlBase *)0x0;
  }
  else {
    CControlEntry::CControlEntry(pCStack00000054,pCVar12);
    this_01 = extraout_EAX_00;
  }
  _uStack00000048 = (void *)CONCAT31(uStack00000049,2);
  (**(code **)(*(int *)this_01 + 0x4c))();
  CControlBase::CreateStack(this_01,(CControlBase *)pCVar3,(CMwNod *)"Value",(char *)pCVar12);
  *(undefined4 *)(this_01 + 0x140) = 1;
  CControlBase::BindEvent
            (this_01,(CControlBase *)0x0,EVar2,(CMwNod *)CGameManialinkPage::OnFileEntryAction,
             (_func___cdecl_void_ulong *)pCVar3,(ulong)puVar13);
  (**(code **)(*(int *)this_01 + 0x178))();
  if (in_stack_00000034 != PTR_DAT_00bbf7d8) {
    puVar10 = in_stack_00000034 + -1;
    if ((in_stack_00000034[-1] & 0x80) != 0) {
      puVar10 = in_stack_00000034 + -4;
    }
    operator_delete__(puVar10);
    in_stack_00000030 = 0;
    in_stack_00000034 = PTR_DAT_00bbf7d8;
  }
  if (in_stack_0000003c != PTR_DAT_00bbf7dc) {
    if ((in_stack_0000003c[-1] & 0x80) == 0) {
      in_stack_0000003c = in_stack_0000003c + -2;
    }
    else {
      in_stack_0000003c = in_stack_0000003c + -4;
    }
    operator_delete__(in_stack_0000003c);
  }
  ExceptionList = _uStack00000048;
  return (CControlEntry *)this_01;
}
}

// =================================================
// Function: ElemCreateFrame
// =================================================
CControlFrame * __cdecl ElemCreateFrame(TiXmlElement *param_1)
{
{
  CControlFrame *pCVar1;
  CControlFrame *this;
  CControlFrame *extraout_EAX;
  CControlFrame *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ac072b;
  local_c = ExceptionList;
  pCVar1 = (CControlFrame *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  this = operator_new(0x160);
  pCVar2 = (CControlFrame *)0x0;
  local_4 = 0;
  if (this != (CControlFrame *)0x0) {
    CControlFrame::CControlFrame(this,pCVar1);
    pCVar2 = extraout_EAX;
  }
  (**(code **)(*(int *)pCVar2 + 0x4c))();
  ExceptionList = puStack_8;
  return pCVar2;
}
}

// =================================================
// Function: ElemCreateLabel
// =================================================
CControlBase * __cdecl
ElemCreateLabel(TiXmlElement *param_1,SBuildPageParams *param_2,CGameManialinkPage *param_3,
               SDico *param_4)
{
{
  char cVar1;
  SBuildPageParams *pSVar2;
  CMwId CVar3;
  char *pcVar4;
  undefined3 extraout_var;
  CMwNod *pCVar5;
  int iVar6;
  CControlLabel *extraout_EAX;
  CControlBase *extraout_EAX_00;
  undefined *puVar7;
  SBuildPageParams *unaff_EBX;
  CControlLabel *pCVar8;
  int *unaff_EBP;
  TiXmlAttribute *unaff_ESI;
  int *unaff_EDI;
  CControlLabel *this;
  undefined *in_stack_00000014;
  undefined *in_stack_00000018;
  CControlBase *in_stack_0000001c;
  TiXmlElement *in_stack_00000020;
  TiXmlElement *in_stack_00000024;
  CControlLabel *in_stack_00000028;
  CControlBase *in_stack_0000002c;
  SDico *in_stack_00000040;
  SDico *in_stack_ffffffd0;
  CControlBase *in_stack_ffffffd4;
  CFastStringInt *in_stack_ffffffd8;
  CControlLabel *in_stack_ffffffdc;
  SDico *in_stack_ffffffe0;
  SStringParam *in_stack_ffffffe4;
  int *in_stack_ffffffe8;
  CFastStringInt *pCVar9;
  SStringParam *pSVar10;
  int local_10;
  void *local_c;
  CControlButton *pCStack_8;
  undefined4 uStack_4;
  
  pSVar2 = param_2;
  uStack_4 = 0xffffffff;
  pCStack_8 = (CControlButton *)&LAB_00ac0d56;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar8 = (CControlLabel *)0x0;
  this = (CControlLabel *)0x0;
  if ((*(int *)(param_2 + 0x14) != 0) && (*(int *)(param_2 + 0x18) != 0)) {
    param_2 = (SBuildPageParams *)0xffffffff;
    pcVar4 = TiXmlElement::Attribute
                       (param_1,(TiXmlElement *)"action",
                        (char *)(DAT_00cca150 ^ (uint)&stack0xffffffc0),unaff_EDI);
    if ((pcVar4 != (char *)0x0) && (_sscanf_s(pcVar4,"%d"), param_4 != (SDico *)0xffffffff)) {
      pCVar8 = operator_new(0xc);
      in_stack_ffffffdc = pCVar8;
      CFastBuffer<class_CDx9TextureKeeper*>::Add
                (in_stack_00000014 + 0x20,(TiXmlAttributeSet *)&stack0xffffffdc,unaff_ESI);
      *(undefined **)(pCVar8 + 8) = in_stack_00000018;
      *(undefined **)pCVar8 = in_stack_00000014;
      pcVar4 = TiXmlElement::Attribute
                         (param_1,(TiXmlElement *)"actionkey",&stack0xffffffe4,unaff_EBP);
      *(uint *)(pCVar8 + 4) = -(uint)(pcVar4 != (char *)0x0) & (uint)in_stack_ffffffe8;
    }
  }
  in_stack_00000018 = (undefined *)0x0;
  if (pCVar8 == (CControlLabel *)0x0) {
    in_stack_00000018 =
         (undefined *)
         ParseUrl((TiXmlElement *)0x0,in_stack_0000001c,(CGameManialinkPage *)pSVar2,unaff_EBX,
                  in_stack_ffffffd0);
  }
  pcVar4 = TiXmlElement::Attribute
                     (param_1,(TiXmlElement *)"style",(char *)unaff_EBX,(int *)in_stack_ffffffd0);
  if (pcVar4 != (char *)0x0) {
    CVar3 = CMwId::CreateFromLocalName((char *)&local_10);
    in_stack_00000014 = (undefined *)0x0;
    pCVar5 = CControlStyleSheet::GetStyleSheetElem
                       (*(CControlStyleSheet **)(pSVar2 + 0xc),
                        (CControlStyleSheet *)CONCAT31(extraout_var,CVar3),(CMwId *)0x0,
                        in_stack_ffffffd4);
    in_stack_00000018 = (undefined *)0xffffffff;
    OnAccessViolation_ConcatToCrashFileName(in_stack_ffffffd8);
    param_1 = in_stack_00000020;
    if ((pCVar5 != (CMwNod *)0x0) &&
       (iVar6 = (**(code **)(*(int *)pCVar5 + 0x10))(), param_1 = in_stack_00000020, iVar6 != 0)) {
      this = (CControlLabel *)(**(code **)(*(int *)pCVar5 + 0xac))();
      param_1 = in_stack_00000020;
    }
  }
  pSVar10 = (SStringParam *)0xffffffff;
  TiXmlElement::QueryIntAttribute
            (param_1,(TiXmlElement *)"maxline",&stack0xffffffec,(int *)in_stack_ffffffd8);
  if (this == (CControlLabel *)0x0) {
    if ((pCVar8 == (CControlLabel *)0x0) && (in_stack_00000028 == (CControlLabel *)0x0)) {
      in_stack_00000028 = operator_new(0x14c);
      in_stack_0000001c = (CControlBase *)0x2;
      if (in_stack_00000028 == (CControlLabel *)0x0) {
        this = (CControlLabel *)0x0;
      }
      else {
        CControlLabel::CControlLabel(in_stack_00000028,in_stack_ffffffdc);
        this = extraout_EAX;
      }
      in_stack_00000020 = (TiXmlElement *)0xffffffff;
      in_stack_ffffffdc = (CControlLabel *)0x7209ca;
      (**(code **)(*(int *)this + 0x4c))();
      param_1 = in_stack_00000024;
      if (local_10 != -1) {
        *(int *)(this + 0x128) = local_10;
      }
      goto LAB_00720a6a;
    }
    pCStack_8 = operator_new(0x178);
    in_stack_0000001c = (CControlBase *)0x1;
    if (pCStack_8 == (CControlButton *)0x0) {
      this = (CControlLabel *)0x0;
    }
    else {
      CControlButton::CControlButton(pCStack_8,(CControlButton *)in_stack_ffffffdc);
      this = (CControlLabel *)extraout_EAX_00;
    }
    in_stack_00000020 = (TiXmlElement *)0xffffffff;
    in_stack_ffffffdc = (CControlLabel *)0x720a1f;
    (**(code **)(*(int *)this + 0x4c))();
    param_1 = in_stack_00000024;
    if (local_10 != -1) {
      *(int *)(this + 0x128) = local_10;
    }
  }
  if (pCVar8 == (CControlLabel *)0x0) {
    if (in_stack_00000028 != (CControlLabel *)0x0) {
      ParseUrl((TiXmlElement *)this,in_stack_0000002c,(CGameManialinkPage *)pSVar2,
               (SBuildPageParams *)in_stack_ffffffdc,in_stack_ffffffe0);
    }
  }
  else {
    CControlTools::ControlBindEvent
              ((CControlBase *)this,0,*(CMwNod **)(pSVar2 + 0x14),
               *(_func___cdecl_void_ulong **)(pSVar2 + 0x18),(ulong)pCVar8);
  }
LAB_00720a6a:
  in_stack_0000001c = (CControlBase *)0x3;
  pcVar4 = TiXmlElement::Attribute
                     (param_1,(TiXmlElement *)&DAT_00b68648,(char *)in_stack_ffffffdc,
                      (int *)in_stack_ffffffe0);
  if (pcVar4 == (char *)0x0) {
    pcVar4 = TiXmlElement::Attribute
                       (param_1,(TiXmlElement *)"textid",(char *)in_stack_ffffffe4,in_stack_ffffffe8
                       );
    iVar6 = DicoGetText(in_stack_00000040,pcVar4,(CFastStringInt *)&param_4);
    if (iVar6 == 0) {
      CXmlEngine::ReadAssociatedText(param_1,(CFastStringInt *)&param_4);
    }
  }
  else {
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    CFastStringInt::SetUtf8(&param_2,(CFastStringInt *)&stack0x00000000,in_stack_ffffffe4);
  }
  pCVar9 = (CFastStringInt *)0x7006000;
  iVar6 = (**(code **)(*(int *)this + 0x10))();
  if (iVar6 == 0) {
    iVar6 = (**(code **)(*(int *)this + 0x10))();
    if (iVar6 == 0) {
      iVar6 = (**(code **)(*(int *)this + 0x10))();
      if (iVar6 != 0) {
        in_stack_00000018 = in_stack_00000014;
        in_stack_0000001c = (CControlBase *)param_4;
        in_stack_00000020 = (TiXmlElement *)0x0;
        if (*(int *)(this + 0x178) == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(this + 0x1cc);
        }
        CFastStringInt::SetString((void *)(iVar6 + 0x18),(CFastStringInt *)&stack0x00000018,pSVar10)
        ;
      }
    }
    else {
      CControlButton::SetLabel((CControlButton *)this,(CControlButton *)&param_3,pCVar9);
    }
  }
  else {
    CControlLabel::SetLabel(this,(CControlButton *)&param_3,pCVar9);
  }
  if (in_stack_00000014 != PTR_DAT_00bbf7dc) {
    if ((in_stack_00000014[-1] & 0x80) == 0) {
      puVar7 = in_stack_00000014 + -2;
    }
    else {
      puVar7 = in_stack_00000014 + -4;
    }
    operator_delete__(puVar7);
  }
  ExceptionList = in_stack_00000024;
  return (CControlBase *)this;
}
}

// =================================================
// Function: ElemCreateMediaPlayer
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CControlMediaPlayer * __cdecl
ElemCreateMediaPlayer(TiXmlElement *param_1,SBuildPageParams *param_2,SDico *param_3,int param_4)
{
{
  CControlBase CVar1;
  byte bVar2;
  undefined *puVar3;
  CMwId CVar4;
  CControlBase *pCVar5;
  CControlBase *pCVar6;
  SDico *pSVar7;
  CSystemData *pCVar8;
  CControlMediaPlayer *pCVar9;
  CControlMediaPlayer *extraout_EAX;
  undefined3 extraout_var;
  CMwNod *this;
  int iVar10;
  CFastStringInt *unaff_EBX;
  int *unaff_EBP;
  SStringParam *unaff_ESI;
  char *pcVar11;
  int *unaff_EDI;
  char *pcVar12;
  bool bVar13;
  CFastStringInt *unaff_retaddr;
  TiXmlElement *pTVar14;
  undefined1 uStack00000014;
  undefined1 uStack00000018;
  undefined4 in_stack_0000001c;
  TiXmlElement *in_stack_00000020;
  undefined4 uStack00000024;
  uint in_stack_00000028;
  int in_stack_0000002c;
  undefined *in_stack_00000034;
  void *in_stack_00000038;
  CControlBase *in_stack_00000044;
  int in_stack_00000050;
  char *in_stack_ffffffdc;
  CControlMediaPlayer *in_stack_ffffffe0;
  int *in_stack_ffffffe4;
  int *in_stack_ffffffe8;
  CControlBase *pCVar15;
  CFastStringInt *pCVar16;
  CFastStringInt *pCVar17;
  CFastStringInt *pCVar18;
  
  pTVar14 = param_1;
  pCVar15 = (CControlBase *)0x0;
  pCVar16 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar6 = (CControlBase *)PTR_DAT_00bbf7d8;
  pCVar5 = (CControlBase *)
           TiXmlElement::Attribute
                     (param_1,(TiXmlElement *)&DAT_00b32c4c,
                      (char *)(DAT_00cca150 ^ (uint)&stack0xffffffcc),unaff_EDI);
  if (pCVar5 == (CControlBase *)0x0) {
    pSVar7 = (SDico *)TiXmlElement::Attribute
                                (pTVar14,(TiXmlElement *)"dataid",(char *)unaff_ESI,unaff_EBP);
    iVar10 = DicoGetText(pSVar7,&stack0xfffffffc,unaff_EBX);
    if (iVar10 == 0) {
      CXmlEngine::ReadAssociatedText(pTVar14,(CFastStringInt *)&stack0xfffffffc);
    }
  }
  else {
    pCVar6 = pCVar5;
    do {
      CVar1 = *pCVar6;
      pCVar6 = pCVar6 + 1;
    } while (CVar1 != (CControlBase)0x0);
    pCVar6 = pCVar6 + -(int)(pCVar5 + 1);
    CFastString::SetString
              ((CFastString *)&stack0xfffffff4,(CFastStringInt *)&stack0xffffffec,unaff_ESI);
    pCVar15 = pCVar5;
  }
  puVar3 = PTR_DAT_00d34100;
  CFastString::TrimLeft
            ((CFastString *)&stack0xfffffffc,(CFastString *)PTR_DAT_00d34100,(char *)unaff_EBX);
  CFastString::TrimRight((CFastString *)&stack0x00000000,(CFastString *)puVar3,in_stack_ffffffdc);
  pCVar8 = MediaDataFindOrAdd((CFastString *)&param_1,(CFastString *)&DAT_00d71c9c,
                              (SBuildPageParams *)in_stack_ffffffe0);
  pCVar9 = operator_new(0x1ac);
  uStack00000014 = 1;
  if (pCVar9 == (CControlMediaPlayer *)0x0) {
    pCVar9 = (CControlMediaPlayer *)0x0;
  }
  else {
    CControlMediaPlayer::CControlMediaPlayer(pCVar9,in_stack_ffffffe0);
    pCVar9 = extraout_EAX;
  }
  uStack00000018 = 0;
  (**(code **)(*(int *)pCVar9 + 0x4c))();
  pTVar14 = in_stack_00000020;
  pCVar18 = (CFastStringInt *)0x0;
  pCVar17 = (CFastStringInt *)0x1;
  TiXmlElement::QueryIntAttribute
            (in_stack_00000020,(TiXmlElement *)&DAT_00b87340,&stack0xfffffffc,in_stack_ffffffe4);
  TiXmlElement::QueryIntAttribute
            (pTVar14,(TiXmlElement *)"looping",&stack0xfffffffc,in_stack_ffffffe8);
  iVar10 = 6;
  bVar13 = true;
  pcVar11 = (char *)(*(int *)(pTVar14 + 0x20) + 8);
  pcVar12 = "video";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar13 = *pcVar11 == *pcVar12;
    pcVar11 = pcVar11 + 1;
    pcVar12 = pcVar12 + 1;
  } while (bVar13);
  if (bVar13) {
    *(undefined4 *)(pCVar9 + 0x188) = 0;
    bVar2 = DAT_00ce9c2d;
  }
  else {
    *(undefined4 *)(pCVar9 + 0x188) = 1;
    bVar2 = DAT_00ce9c2e;
  }
  if (pCVar8 != (CSystemData *)0x0) {
    *(uint *)(pCVar8 + 0x24) = bVar2 + 1000;
  }
  CVar4 = CMwId::CreateFromLocalName((char *)&param_2);
  in_stack_00000020 = (TiXmlElement *)CONCAT31(in_stack_00000020._1_3_,2);
  this = CControlStyleSheet::GetStyleSheetElem
                   (*(CControlStyleSheet **)(in_stack_0000002c + 0xc),
                    (CControlStyleSheet *)CONCAT31(extraout_var,CVar4),(CMwId *)0x0,pCVar15);
  if (this != *(CMwNod **)(pCVar9 + 0x174)) {
    if (this != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this,(CMwNod *)pCVar6);
    }
    if (*(CMwNod **)(pCVar9 + 0x174) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar9 + 0x174),(CMwNod *)pCVar16);
    }
    *(CMwNod **)(pCVar9 + 0x174) = this;
  }
  in_stack_00000028 = in_stack_00000028 & 0xffffff00;
  OnAccessViolation_ConcatToCrashFileName(pCVar16);
  CMwId::SetLocalName(pCVar9 + 0x164,(CMwId *)"MediaPlay",pCVar16);
  CMwId::SetLocalName(pCVar9 + 0x168,(CMwId *)"MediaStop",pCVar17);
  CMwId::SetLocalName(pCVar9 + 0x16c,(CMwId *)"MediaAudioDownloading",pCVar18);
  CMwId::SetLocalName(pCVar9 + 0x170,(CMwId *)"MediaVideoDownloading",unaff_retaddr);
  CMwId::SetLocalName(pCVar9 + 0x160,(CMwId *)"MediaPlay",(CFastStringInt *)param_1);
  uStack00000024 = _DAT_00b3380c;
  in_stack_00000028 = _DAT_00b3380c;
  *(undefined4 *)(pCVar9 + 0x19c) = in_stack_0000001c;
  *(TiXmlElement **)(pCVar9 + 0x198) = in_stack_00000020;
  if (in_stack_00000050 == 0) {
    pTVar14 = (TiXmlElement *)0x0;
  }
  else {
    pTVar14 = (TiXmlElement *)0x3;
  }
  param_1 = (TiXmlElement *)(uint)(in_stack_00000050 != 0);
  ControlSetSizeAndAlign
            (in_stack_00000044,pTVar14,(GmVec2 *)param_1,(EAlignHorizontal)param_2,
             (EAlignVertical)param_3,param_4);
  param_1 = (TiXmlElement *)pCVar8;
  CControlMediaPlayer::SetMediaData(pCVar9,(CControlMediaPlayer *)pCVar8,(CSystemData *)param_2);
  if (in_stack_00000034 != PTR_DAT_00bbf7d8) {
    param_2 = (SBuildPageParams *)(in_stack_00000034 + -1);
    if ((in_stack_00000034[-1] & 0x80) != 0) {
      param_2 = (SBuildPageParams *)(in_stack_00000034 + -4);
    }
    param_1 = (TiXmlElement *)0x71f26f;
    operator_delete__(param_2);
  }
  ExceptionList = in_stack_00000038;
  return pCVar9;
}
}

// =================================================
// Function: ElemCreateQuad
// =================================================
CControlQuad * __cdecl
ElemCreateQuad(TiXmlElement *param_1,SBuildPageParams *param_2,CGameManialinkPage *param_3,
              SDico *param_4)
{
{
  CControlQuad *pCVar1;
  CControlQuad *this;
  TiXmlElement *extraout_EAX;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  CGameManialinkPage *unaff_EBX;
  TiXmlAttribute *unaff_EBP;
  SDico *unaff_ESI;
  TiXmlElement *pTVar5;
  SBuildPageParams *unaff_EDI;
  TiXmlElement *in_stack_00000014;
  int *in_stack_ffffffe8;
  void *local_c;
  undefined4 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = (undefined4 *)&LAB_00ac0d8b;
  local_c = ExceptionList;
  pCVar1 = (CControlQuad *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  this = operator_new(0x144);
  pTVar5 = (TiXmlElement *)0x0;
  local_4 = 0;
  if (this != (CControlQuad *)0x0) {
    CControlQuad::CControlQuad(this,pCVar1);
    pTVar5 = extraout_EAX;
  }
  (**(code **)(*(int *)pTVar5 + 0x4c))();
  *(undefined4 *)(pTVar5 + 0x140) = 0xffffffff;
  iVar2 = ParseUrl(pTVar5,(CControlBase *)param_2,unaff_EBX,unaff_EDI,unaff_ESI);
  if (((iVar2 == 0) && (*(int *)(unaff_EBX + 0x14) != 0)) && (*(int *)(unaff_EBX + 0x18) != 0)) {
    pcVar3 = TiXmlElement::Attribute
                       ((TiXmlElement *)param_2,(TiXmlElement *)"action",(char *)unaff_EDI,
                        (int *)unaff_ESI);
    if (pcVar3 != (char *)0x0) {
      _sscanf_s(pcVar3,"%d");
      if (local_c != (void *)0xffffffff) {
        puVar4 = operator_new(0xc);
        puStack_8 = puVar4;
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (param_2 + 0x20,(TiXmlAttributeSet *)&puStack_8,unaff_EBP);
        puVar4[2] = param_2;
        *puVar4 = puStack_8;
        pcVar3 = TiXmlElement::Attribute
                           (in_stack_00000014,(TiXmlElement *)"actionkey",&stack0x00000000,
                            in_stack_ffffffe8);
        puVar4[1] = -(uint)(pcVar3 != (char *)0x0) & (uint)param_1;
        CControlTools::ControlBindEvent
                  ((CControlBase *)pTVar5,0,*(CMwNod **)(unaff_EBX + 0x14),
                   *(_func___cdecl_void_ulong **)(unaff_EBX + 0x18),(ulong)puVar4);
        CControlTools::ControlSetReadOnlyAndDraw((CControlBase *)pTVar5,0,0);
      }
    }
  }
  ExceptionList = puStack_8;
  return (CControlQuad *)pTVar5;
}
}

// =================================================
// Function: ElemGetStyle
// =================================================
void __cdecl
ElemGetStyle(TiXmlElement *param_1,CControlStyleSheet *param_2,
            CMwNodRef<class_CControlStyle> *param_3)
{
{
  CMwId CVar1;
  char *pcVar2;
  CMwId *pCVar3;
  undefined3 extraout_var;
  CMwNod *this;
  int iVar4;
  CControlStyle *this_00;
  TiXmlElement *in_ECX;
  char *unaff_EBX;
  int *unaff_ESI;
  int *unaff_EDI;
  CControlStyleSheet *in_stack_00000014;
  TiXmlElement *pTVar5;
  CControlBase *pCVar6;
  CFastStringInt *pCVar7;
  
  pCVar7 = (CFastStringInt *)&LAB_00ac0758;
  pCVar6 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pTVar5 = in_ECX;
  pcVar2 = TiXmlElement::Attribute
                     (in_ECX,(TiXmlElement *)"style",(char *)(DAT_00cca150 ^ (uint)&stack0xffffffe8)
                      ,unaff_ESI);
  pCVar3 = (CMwId *)TiXmlElement::Attribute
                              (in_ECX,(TiXmlElement *)"substyle",unaff_EBX,(int *)pTVar5);
  if (pcVar2 != (char *)0x0) {
    CVar1 = CMwId::CreateFromLocalName(&stack0x00000000);
    this = CControlStyleSheet::GetStyleSheetElem
                     (in_stack_00000014,(CControlStyleSheet *)CONCAT31(extraout_var,CVar1),
                      (CMwId *)0x0,pCVar6);
    OnAccessViolation_ConcatToCrashFileName(pCVar7);
    if (this != (CMwNod *)0x0) {
      iVar4 = (**(code **)(*(int *)this + 0x10))();
      if ((iVar4 != 0) && (this != (CMwNod *)*unaff_EDI)) {
        CMwNod::MwAddRef(this,(CMwNod *)pCVar7);
        if ((CMwNod *)*unaff_EDI != (CMwNod *)0x0) {
          pCVar7 = (CFastStringInt *)0x71d304;
          CMwNod::MwRelease((CMwNod *)*unaff_EDI,(CMwNod *)0x71d304);
        }
        *unaff_EDI = (int)this;
      }
    }
  }
  if ((pCVar3 != (CMwId *)0x0) && ((CControlStyle *)*unaff_EDI != (CControlStyle *)0x0)) {
    this_00 = CControlStyle::Fork((CControlStyle *)*unaff_EDI);
    if (this_00 != (CControlStyle *)*unaff_EDI) {
      if (this_00 != (CControlStyle *)0x0) {
        CMwNod::MwAddRef((CMwNod *)this_00,(CMwNod *)pCVar7);
      }
      if ((CMwNod *)*unaff_EDI != (CMwNod *)0x0) {
        CMwNod::MwRelease((CMwNod *)*unaff_EDI,(CMwNod *)pCVar7);
      }
      *unaff_EDI = (int)this_00;
    }
    CMwId::SetLocalName((void *)(*unaff_EDI + 0xc4),pCVar3,pCVar7);
  }
  ExceptionList = param_2;
  return;
}
}

// =================================================
// Function: ElemModifyManialinkFormat
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
ElemModifyManialinkFormat
          (TiXmlElement *param_1,CControlStyleSheet *param_2,SManialinkFormat *param_3)
{
{
  int *piVar1;
  float fVar2;
  CMwNod *pCVar3;
  CControlStyle *this;
  char *pcVar4;
  int iVar5;
  CPlugShaderGeneric *extraout_EAX;
  CMwNod *extraout_EAX_00;
  CPlugShaderGeneric *extraout_EAX_01;
  CPlugMaterial *this_00;
  CMwNod *extraout_EAX_02;
  undefined4 *in_ECX;
  int *unaff_EBX;
  CPlugShaderGeneric *pCVar6;
  int *piVar7;
  GxColor *unaff_EBP;
  CControlStyleSheet *this_01;
  int *unaff_ESI;
  CMwNod *unaff_EDI;
  int *unaff_retaddr;
  TiXmlElement *in_stack_00000010;
  CPlugShader *in_stack_00000014;
  CPlugShaderApply *in_stack_00000018;
  TiXmlElement *in_stack_0000001c;
  char *in_stack_00000020;
  int *in_stack_00000024;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  TiXmlElement *in_stack_00000044;
  undefined4 in_stack_00000048;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  TiXmlElement *in_stack_00000060;
  CControlStyleSheet *in_stack_ffffffd0;
  CMwNodRef<class_CControlStyle> *in_stack_ffffffd4;
  char *in_stack_ffffffd8;
  int *in_stack_ffffffdc;
  GxColor *in_stack_ffffffe0;
  int *in_stack_ffffffe4;
  CPlugShaderApply *in_stack_ffffffe8;
  GxColor *in_stack_ffffffec;
  EGxBlendFactor in_stack_fffffff0;
  void *pvVar8;
  CPlugShader *pCVar9;
  CPlugShaderApply *this_02;
  
  this_02 = (CPlugShaderApply *)0xffffffff;
  pCVar9 = (CPlugShader *)&LAB_00ac07dc;
  pCVar3 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffc0);
  piVar1 = in_ECX + 0xd;
  pvVar8 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  this = CControlStyle::Fork((CControlStyle *)in_ECX[0xd]);
  if (this != (CControlStyle *)*piVar1) {
    if (this != (CControlStyle *)0x0) {
      CMwNod::MwAddRef((CMwNod *)this,pCVar3);
    }
    if ((CMwNod *)*piVar1 != (CMwNod *)0x0) {
      CMwNod::MwRelease((CMwNod *)*piVar1,unaff_EDI);
    }
    *piVar1 = (int)this;
  }
  this_01 = param_2;
  pcVar4 = TiXmlElement::Attribute
                     ((TiXmlElement *)param_2,(TiXmlElement *)"textcolor",(char *)unaff_EDI,
                      unaff_ESI);
  if (pcVar4 != (char *)0x0) {
    iVar5 = GetGxColorFromString(&stack0xffffffe0,unaff_EBP);
    if (iVar5 != 0) {
      iVar5 = *piVar1;
      *in_ECX = in_stack_ffffffe0;
      in_ECX[1] = in_stack_ffffffe4;
      in_ECX[2] = in_stack_ffffffe8;
      in_ECX[3] = in_stack_ffffffec;
      *(GxColor **)(iVar5 + 0x60) = in_stack_ffffffe0;
      *(int **)(iVar5 + 100) = in_stack_ffffffe4;
      *(CPlugShaderApply **)(iVar5 + 0x68) = in_stack_ffffffe8;
      *(GxColor **)(iVar5 + 0x6c) = in_stack_ffffffec;
      iVar5 = *piVar1;
      *(undefined4 *)(iVar5 + 0x7c) = *in_ECX;
      *(undefined4 *)(iVar5 + 0x80) = in_ECX[1];
      *(undefined4 *)(iVar5 + 0x84) = in_ECX[2];
      *(undefined4 *)(iVar5 + 0x88) = in_ECX[3];
      iVar5 = *piVar1;
      *(undefined4 *)(iVar5 + 0x98) = *in_ECX;
      *(undefined4 *)(iVar5 + 0x9c) = in_ECX[1];
      *(undefined4 *)(iVar5 + 0xa0) = in_ECX[2];
      *(undefined4 *)(iVar5 + 0xa4) = in_ECX[3];
      this_01 = (CControlStyleSheet *)in_stack_00000010;
    }
  }
  pcVar4 = TiXmlElement::Attribute
                     ((TiXmlElement *)this_01,(TiXmlElement *)0xb87268,(char *)unaff_EBP,unaff_EBX);
  if (pcVar4 != (char *)0x0) {
    _sscanf_s(pcVar4,"%d");
    fVar2 = (float)(int)in_ECX[4];
    if ((int)in_ECX[4] < 0) {
      fVar2 = fVar2 + _DAT_00c418d0;
    }
    *(float *)(*piVar1 + 0x54) = fVar2 * (float)_DAT_00b50898 + (float)_DAT_00b87260;
  }
  ElemGetStyle(in_stack_0000001c,in_stack_ffffffd0,in_stack_ffffffd4);
  pcVar4 = TiXmlElement::Attribute
                     ((TiXmlElement *)this_01,(TiXmlElement *)"textfilter",(char *)in_stack_ffffffd0
                      ,(int *)in_stack_ffffffd4);
  pCVar6 = (CPlugShaderGeneric *)0x0;
  if (pcVar4 != (char *)0x0) {
    _sscanf_s(pcVar4,"%d");
  }
  pcVar4 = TiXmlElement::Attribute
                     ((TiXmlElement *)this_01,(TiXmlElement *)"bgcolor",in_stack_ffffffd8,
                      in_stack_ffffffdc);
  if (pcVar4 != (char *)0x0) {
    iVar5 = GetGxColorFromString(&stack0xfffffff8,in_stack_ffffffe0);
    if (iVar5 != 0) {
      in_ECX[6] = pCVar9;
      in_ECX[7] = this_02;
      in_ECX[8] = unaff_retaddr;
      in_ECX[9] = param_1;
    }
  }
  pcVar4 = TiXmlElement::Attribute
                     ((TiXmlElement *)this_01,(TiXmlElement *)"focusareacolor1",
                      (char *)in_stack_ffffffe0,in_stack_ffffffe4);
  if (pcVar4 != (char *)0x0) {
    iVar5 = GetGxColorFromString(&stack0x00000000,(GxColor *)in_stack_ffffffe8);
    if (iVar5 != 0) {
      this_02 = operator_new(0xa8);
      if (this_02 != (CPlugShaderApply *)0x0) {
        CPlugShaderApply::CPlugShaderApply(this_02,in_stack_ffffffe8);
        pCVar6 = extraout_EAX;
      }
      in_stack_0000002c = 0xffffffff;
      CPlugShaderGeneric::SetVertexColor
                (pCVar6,(CPlugShaderGeneric *)0x0,(EPlugShaderVertexColor)&param_1,in_stack_ffffffec
                );
      CPlugShaderApply::SetBlending
                ((CPlugShaderApply *)pCVar6,(CPlugShaderPass *)0x1,in_stack_fffffff0,
                 (EGxBlendFactor)pvVar8);
      param_3 = operator_new(0x38);
      in_stack_00000038 = 1;
      if (param_3 == (SManialinkFormat *)0x0) {
        pCVar3 = (CMwNod *)0x0;
      }
      else {
        CPlugMaterial::CPlugMaterial((CPlugMaterial *)param_3,(CPlugMaterial *)pCVar6,pCVar9);
        pCVar3 = extraout_EAX_00;
      }
      in_stack_0000003c = 0xffffffff;
      iVar5 = *piVar1;
      if (pCVar3 != *(CMwNod **)(iVar5 + 0x28)) {
        if (pCVar3 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(pCVar3,(CMwNod *)this_02);
        }
        if (*(CMwNod **)(iVar5 + 0x28) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(iVar5 + 0x28),(CMwNod *)this_02);
        }
        *(CMwNod **)(iVar5 + 0x28) = pCVar3;
      }
      iVar5 = *piVar1;
      if (pCVar3 != *(CMwNod **)(iVar5 + 0x2c)) {
        if (pCVar3 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(pCVar3,(CMwNod *)this_02);
        }
        if (*(CMwNod **)(iVar5 + 0x2c) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(iVar5 + 0x2c),(CMwNod *)this_02);
        }
        *(CMwNod **)(iVar5 + 0x2c) = pCVar3;
      }
      *(undefined4 *)(*piVar1 + 0x48) = _DAT_00b37b60;
      this_01 = (CControlStyleSheet *)in_stack_00000044;
    }
  }
  pcVar4 = TiXmlElement::Attribute
                     ((TiXmlElement *)this_01,(TiXmlElement *)"focusareacolor2",(char *)this_02,
                      unaff_retaddr);
  if (pcVar4 != (char *)0x0) {
    iVar5 = GetGxColorFromString((char *)&stack0x0000002c,(GxColor *)param_1);
    if (iVar5 != 0) {
      in_stack_00000018 = operator_new(0xa8);
      in_stack_00000044 = (TiXmlElement *)0x2;
      if (in_stack_00000018 == (CPlugShaderApply *)0x0) {
        pCVar6 = (CPlugShaderGeneric *)0x0;
      }
      else {
        CPlugShaderApply::CPlugShaderApply(in_stack_00000018,(CPlugShaderApply *)param_1);
        pCVar6 = extraout_EAX_01;
      }
      param_1 = (TiXmlElement *)&stack0x00000030;
      in_stack_00000048 = 0xffffffff;
      CPlugShaderGeneric::SetVertexColor
                (pCVar6,(CPlugShaderGeneric *)0x0,(EPlugShaderVertexColor)param_1,(GxColor *)param_2
                );
      param_2 = (CControlStyleSheet *)0x1;
      param_1 = (TiXmlElement *)0x71d72c;
      CPlugShaderApply::SetBlending
                ((CPlugShaderApply *)pCVar6,(CPlugShaderPass *)0x1,(EGxBlendFactor)param_3,
                 (EGxBlendFactor)in_stack_00000010);
      param_3 = (SManialinkFormat *)0x71d733;
      this_00 = operator_new(0x38);
      in_stack_00000054 = 3;
      if (this_00 == (CPlugMaterial *)0x0) {
        pCVar3 = (CMwNod *)0x0;
      }
      else {
        param_3 = (SManialinkFormat *)0x71d74e;
        CPlugMaterial::CPlugMaterial(this_00,(CPlugMaterial *)pCVar6,in_stack_00000014);
        pCVar3 = extraout_EAX_02;
      }
      piVar7 = (int *)(*piVar1 + 0x34);
      in_stack_00000058 = 0xffffffff;
      if (pCVar3 != (CMwNod *)*piVar7) {
        if (pCVar3 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(pCVar3,(CMwNod *)in_stack_00000018);
        }
        if ((CMwNod *)*piVar7 != (CMwNod *)0x0) {
          CMwNod::MwRelease((CMwNod *)*piVar7,(CMwNod *)in_stack_00000018);
        }
        *piVar7 = (int)pCVar3;
      }
      *(undefined4 *)(*piVar1 + 0x48) = _DAT_00b37b60;
      this_01 = (CControlStyleSheet *)in_stack_00000060;
    }
  }
  pcVar4 = TiXmlElement::Attribute
                     ((TiXmlElement *)this_01,(TiXmlElement *)"bgborderx",(char *)in_stack_00000018,
                      (int *)in_stack_0000001c);
  if (pcVar4 != (char *)0x0) {
    _sscanf_s(pcVar4,"%f");
  }
  pcVar4 = TiXmlElement::Attribute
                     ((TiXmlElement *)this_01,(TiXmlElement *)"bgbordery",in_stack_00000020,
                      in_stack_00000024);
  if (pcVar4 != (char *)0x0) {
    _sscanf_s(pcVar4,"%f");
  }
  ExceptionList = in_stack_00000060;
  return;
}
}

// =================================================
// Function: ElemSizeAndAlignGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
ElemSizeAndAlignGet(TiXmlElement *param_1,GmVec2 *param_2,EAlignHorizontal *param_3,
                   EAlignVertical *param_4)
{
{
  float fVar1;
  float *in_EAX;
  char *pcVar2;
  int iVar3;
  TiXmlElement *unaff_EBX;
  char *unaff_EBP;
  int *unaff_ESI;
  char *pcVar4;
  char *unaff_EDI;
  char *pcVar5;
  bool bVar6;
  double *unaff_retaddr;
  undefined4 in_stack_00000014;
  undefined4 *in_stack_00000030;
  int *in_stack_fffffff8;
  double *in_stack_fffffffc;
  
  pcVar2 = TiXmlElement::Attribute(unaff_EBX,(TiXmlElement *)&DAT_00b32c8c,unaff_EDI,unaff_ESI);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = TiXmlElement::Attribute(unaff_EBX,(TiXmlElement *)"sizen",unaff_EBP,in_stack_fffffff8);
    if (pcVar2 == (char *)0x0) {
      iVar3 = TiXmlElement::QueryDoubleAttribute
                        (unaff_EBX,(TiXmlElement *)"width",(char *)&param_2,in_stack_fffffffc);
      if (iVar3 == 0) {
        *in_EAX = (float)(double)CONCAT44(param_4,param_3);
      }
      iVar3 = TiXmlElement::QueryDoubleAttribute
                        (unaff_EBX,(TiXmlElement *)"height",(char *)&param_3,unaff_retaddr);
      if (iVar3 == 0) {
        in_EAX[1] = (float)(double)CONCAT44(in_stack_00000014,param_4);
      }
    }
    else {
      _sscanf_s(pcVar2,"%f %f");
      fVar1 = (float)_DAT_00b33a48;
      *in_EAX = *in_EAX * fVar1;
      in_EAX[1] = fVar1 * in_EAX[1];
    }
  }
  else {
    _sscanf_s(pcVar2,"%f %f");
  }
  pcVar2 = TiXmlElement::Attribute
                     (unaff_EBX,(TiXmlElement *)"halign",(char *)param_1,(int *)param_2);
  if (pcVar2 != (char *)0x0) {
    iVar3 = 5;
    bVar6 = true;
    pcVar4 = pcVar2;
    pcVar5 = "left";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      *(undefined4 *)param_1 = 0;
    }
    else {
      iVar3 = 6;
      bVar6 = true;
      pcVar4 = pcVar2;
      pcVar5 = "right";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        *(undefined4 *)param_1 = 2;
      }
      else {
        iVar3 = 7;
        bVar6 = true;
        pcVar4 = "center";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *pcVar2 == *pcVar4;
          pcVar2 = pcVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar6);
        if (bVar6) {
          *(undefined4 *)param_1 = 1;
        }
      }
    }
  }
  param_2 = (GmVec2 *)s_valign_00b871b4;
  pcVar2 = TiXmlElement::Attribute
                     (unaff_EBX,(TiXmlElement *)"valign",(char *)param_3,(int *)param_4);
  if (pcVar2 != (char *)0x0) {
    iVar3 = 4;
    bVar6 = true;
    pcVar4 = pcVar2;
    pcVar5 = "top";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      *in_stack_00000030 = 0;
      return;
    }
    iVar3 = 7;
    bVar6 = true;
    pcVar4 = pcVar2;
    pcVar5 = "bottom";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      *in_stack_00000030 = 2;
      return;
    }
    iVar3 = 7;
    bVar6 = true;
    pcVar4 = pcVar2;
    pcVar5 = "center";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      *in_stack_00000030 = 1;
      return;
    }
    iVar3 = 8;
    bVar6 = true;
    pcVar4 = "center2";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar6);
    if (bVar6) {
      *in_stack_00000030 = 4;
    }
  }
  return;
}
}

// =================================================
// Function: EventControlGet
// =================================================
CControlBase * __cdecl EventControlGet(CControlBase *param_1)
{
{
  int iVar1;
  CControlBase *unaff_ESI;
  
  if (unaff_ESI == (CControlBase *)0x0) {
    return (CControlBase *)0x0;
  }
  iVar1 = (**(code **)(*(int *)unaff_ESI + 0x10))(0x309a000);
  if (iVar1 != 0) {
    if (*(CControlBase **)(unaff_ESI + 0x1a8) != (CControlBase *)0x0) {
      return *(CControlBase **)(unaff_ESI + 0x1a8);
    }
    (**(code **)(*(int *)unaff_ESI + 0x178))();
    unaff_ESI = *(CControlBase **)(unaff_ESI + 0x1a8);
  }
  if (unaff_ESI != (CControlBase *)0x0) {
    return unaff_ESI;
  }
  return (CControlBase *)0x0;
}
}

// =================================================
// Function: FUN_0040318c
// =================================================
void __cdecl FUN_0040318c(void)
{
{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func___cdecl_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}
}

// =================================================
// Function: FUN_004032c2
// =================================================
void __cdecl FUN_004032c2(void)
{
{
  __unlockexit();
  return;
}
}

// =================================================
// Function: FUN_00405022
// =================================================
void __cdecl FUN_00405022(void)
{
{
  __unlock(0xc);
  return;
}
}

// =================================================
// Function: FUN_00405bac
// =================================================
void __cdecl FUN_00405bac(void)
{
{
  __unlock(4);
  return;
}
}

// =================================================
// Function: FUN_00407a04
// =================================================
void __cdecl FUN_00407a04(void)
{
{
  __unlock(4);
  return;
}
}

// =================================================
// Function: FUN_00407f33
// =================================================
void __cdecl FUN_00407f33(void)
{
{
  __unlock(4);
  return;
}
}

// =================================================
// Function: FUN_004081b7
// =================================================
void __cdecl FUN_004081b7(void)
{
{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + 0x10) != 0) {
    __unlock(8);
  }
  return;
}
}

// =================================================
// Function: FUN_00408f76
// =================================================
void __cdecl FUN_00408f76(void)
{
{
  __unlock(0xd);
  return;
}
}

// =================================================
// Function: FUN_004096a8
// =================================================
void __cdecl FUN_004096a8(void)
{
{
  __unlock(0xc);
  return;
}
}

// =================================================
// Function: FUN_0040b279
// =================================================
void __cdecl FUN_0040b279(void)
{
{
  __unlock(10);
  return;
}
}

// =================================================
// Function: FUN_0040d2a7
// =================================================
void __cdecl FUN_0040d2a7(void)
{
{
  __unlock(4);
  return;
}
}

// =================================================
// Function: FUN_0040d44c
// =================================================
void __cdecl FUN_0040d44c(void)
{
{
  __unlock(4);
  return;
}
}

// =================================================
// Function: FUN_0041a7ae
// =================================================
void __cdecl FUN_0041a7ae(void)
{
{
  int iVar1;
  SCallStackFidContext *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DAT_00d72e8c = 0;
  }
  (**(code **)(**(int **)(unaff_EBX + 0x6c) + 4))();
  iVar1 = *(int *)(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_ESI + 4) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (iVar1 == 0) {
    *unaff_EDI = 0;
    CSystemFid::SCallStackFidContext::~SCallStackFidContext((void *)(unaff_EBP + -0x2c),unaff_EBX);
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;
  }
  CSystemFid::SCallStackFidContext::~SCallStackFidContext((void *)(unaff_EBP + -0x2c),unaff_EBX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}
}

// =================================================
// Function: FUN_009ab8d2
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009ab9ba) overlaps instruction at (ram,0x009ab9b7)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009aba98) */
/* WARNING: Removing unreachable block (ram,0x009aba9a) */
/* WARNING: Removing unreachable block (ram,0x009ab958) */
/* WARNING: Removing unreachable block (ram,0x009ab980) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_009ab8d2(void)
{
{
  unkbyte10 Var1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  longlong lVar5;
  code *pcVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  char cVar14;
  uint in_EAX;
  uint uVar10;
  ushort uVar17;
  int iVar11;
  uint3 uVar15;
  undefined3 uVar16;
  uint *puVar13;
  int in_ECX;
  int *piVar18;
  undefined4 extraout_ECX;
  int iVar19;
  undefined4 in_EDX;
  byte *pbVar20;
  byte bVar21;
  undefined4 unaff_EBX;
  undefined4 *puVar23;
  uint unaff_EBP;
  uint *unaff_ESI;
  byte *pbVar24;
  byte *pbVar25;
  uint uVar26;
  undefined1 *puVar27;
  undefined4 *unaff_EDI;
  uint *puVar28;
  undefined2 in_ES;
  undefined2 in_SS;
  int in_GS_OFFSET;
  bool in_CF;
  bool bVar29;
  byte in_AF;
  byte bVar30;
  bool bVar31;
  unkbyte10 in_ST0;
  float10 extraout_ST0;
  float10 fVar32;
  unkbyte10 extraout_ST1;
  undefined8 uVar33;
  int unaff_retaddr;
  char *pcVar12;
  byte *pbVar22;
  
  bVar31 = false;
  if (in_CF) {
    uVar10 = in_EAX ^ 0x356735ea;
    _DAT_31342b13 = (int)unaff_ESI + *unaff_ESI;
    _DAT_31342b0f = unaff_EDI + 1;
    uVar2 = in((short)in_EDX);
    _DAT_31342b2f = in_SS;
    *unaff_EDI = uVar2;
    bVar30 = 9 < ((byte)uVar10 & 0xf) | in_AF;
    uVar26 = CONCAT31((int3)(uVar10 >> 8),(byte)uVar10 + bVar30 * '\x06') & 0xffffff0f;
    uVar17 = (ushort)(uVar26 >> 0x10);
    bVar7 = (byte)uVar26;
    cVar14 = (char)(uVar10 >> 8) + bVar30;
    _DAT_31342b2b = CONCAT22(uVar17,CONCAT11(cVar14,bVar7));
    _DAT_31342b1b = &DAT_31342b2f;
    bVar30 = 9 < bVar7 | bVar30;
    bVar7 = bVar7 + bVar30 * '\x06' & 0xf;
    in_AF = 9 < bVar7 | bVar30;
    uVar10 = CONCAT31((int3)(((uint)uVar17 << 0x10) >> 8),bVar7 + in_AF * '\x06') & 0xffffff0f;
    Var1 = to_bcd(in_ST0);
    _DAT_31342b17 = unaff_EBP;
    _DAT_31342b1f = unaff_EBX;
    _DAT_31342b23 = in_EDX;
    _DAT_31342b27 = in_ECX;
    *(unkbyte10 *)_DAT_31342b0f = Var1;
    unaff_EBX = CONCAT22((short)((uint)unaff_EBX >> 0x10),
                         CONCAT11(((char)((uint)unaff_EBX >> 8) -
                                  *(char *)CONCAT22((short)(uVar10 >> 0x10),
                                                    CONCAT11(cVar14 + bVar30 + in_AF,(char)uVar10)))
                                  - in_AF,(char)unaff_EBX));
    unaff_ESI = _DAT_31342b0f;
  }
  bVar7 = in_AF * -6 + 0x39 & 0xf;
  _DAT_3e803e0b = _DAT_3e803e0b >> 3;
  bVar30 = 9 < bVar7 | in_AF;
  uVar10 = CONCAT31(0x2839f0,bVar7 + bVar30 * -6) & 0xffff000f;
  iVar11 = CONCAT22((short)(uVar10 >> 0x10),CONCAT11((-0x10 - in_AF) - bVar30,(char)uVar10)) +
           0x6c3f2d3f + (uint)bVar30;
  bVar30 = 9 < ((byte)iVar11 & 0xf) | bVar30;
  uVar10 = CONCAT31((int3)((uint)iVar11 >> 8),(byte)iVar11 + bVar30 * -6) & 0xffffff0f;
  bVar7 = (byte)uVar10;
  pbVar20 = (byte *)CONCAT22((short)(uVar10 >> 0x10),
                             CONCAT11((char)((uint)iVar11 >> 8) - bVar30,bVar7));
  piVar18 = (int *)(in_ECX + -1);
  if (piVar18 != (int *)0x0 && bVar7 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *pbVar20 = *pbVar20 + (char)in_EDX;
  uVar15 = (uint3)((uint)pbVar20 >> 8);
  bVar7 = bVar7 & *pbVar20;
  puVar28 = (uint *)CONCAT31(uVar15,bVar7);
  *(undefined2 *)puVar28 = in_ES;
  *(byte *)puVar28 = (char)*puVar28 + bVar7;
  *puVar28 = *puVar28 ^ 0xffffff94;
  *(byte *)((int)(puVar28 + 0xc58cc3a) + (int)unaff_ESI) =
       *(byte *)((int)(puVar28 + 0xc58cc3a) + (int)unaff_ESI) ^ (byte)((uint)piVar18 >> 8);
  bVar30 = 9 < bVar7 | bVar30;
  iVar11 = *piVar18;
  puVar28 = (uint *)((longlong)iVar11 * 0x39d539c3);
  cVar14 = *(char *)((int)((uint)(uVar15 >> 8) << 0x10) >> 0x1f);
  pcVar6 = (code *)swi(0x3a);
  uVar33 = (*pcVar6)();
  pbVar20 = (byte *)((ulonglong)uVar33 >> 0x20);
  iVar11 = CONCAT22((short)((uint)unaff_EBX >> 0x10),
                    CONCAT11((char)((uint)unaff_EBX >> 8) + cVar14 +
                             ((longlong)(int)puVar28 != (longlong)iVar11 * 0x39d539c3),
                             (char)unaff_EBX)) + 1;
  if (-1 < (int)uVar33 + -0x3d723d4f) {
    *unaff_ESI = *unaff_ESI & (uint)puVar28;
    uVar10 = in((short)((ulonglong)uVar33 >> 0x20));
    *puVar28 = uVar10;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(uint *)((int)unaff_ESI + 0x38323131) = *(uint *)((int)unaff_ESI + 0x38323131) ^ (uint)puVar28;
  bVar8 = (byte)((ulonglong)uVar33 >> 0x28);
  bVar21 = (byte)iVar11 ^ bVar8;
  pbVar22 = (byte *)CONCAT31((int3)((uint)iVar11 >> 8),bVar21);
  bVar7 = (byte)extraout_ECX ^ *(byte *)((int)unaff_ESI + -0x17cb28cd);
  iVar19 = CONCAT31((int3)((uint)extraout_ECX >> 8),bVar7);
  pbVar24 = (byte *)_DAT_35cc35c8;
  bVar29 = DAT_35d835d4 < '\0';
  DAT_35d835d4 = DAT_35d835d4 << 1;
  fVar32 = extraout_ST0 / (float10)_DAT_36543650;
  *(uint **)(unaff_retaddr + -4) = unaff_ESI;
  *(int *)(unaff_retaddr + -8) = iVar19;
  *(byte **)(unaff_retaddr + -0xc) = pbVar20;
  *(byte **)(unaff_retaddr + -0x10) = pbVar22;
  *(int *)(unaff_retaddr + -0x14) = unaff_retaddr;
  *(uint *)(unaff_retaddr + -0x18) = unaff_EBP;
  *(byte **)(unaff_retaddr + -0x1c) = pbVar24;
  *(uint **)(unaff_retaddr + -0x20) = puVar28;
  bVar9 = (byte)((uint)iVar11 >> 8);
  puVar23 = (undefined4 *)(unaff_retaddr + -0x20);
  if (bVar29) {
    LOCK();
    bVar30 = *pbVar24;
    *pbVar24 = bVar8;
    pbVar20 = (byte *)CONCAT22((short)((ulonglong)uVar33 >> 0x30),
                               CONCAT11(bVar30,(char)((ulonglong)uVar33 >> 0x20)));
    UNLOCK();
    uVar16 = (undefined3)((uint)unaff_ESI >> 8);
    bVar8 = pbVar22[(uint)unaff_ESI & 0xff];
    pcVar12 = (char *)CONCAT31(uVar16,bVar8);
    fVar32 = fVar32 / (float10)*(short *)pbVar24;
    puVar28 = (uint *)((int)puVar28 + -1);
    *pcVar12 = *pcVar12 >> 7;
    bVar31 = (*(uint *)(unaff_retaddr + -0x20) & 0x400) != 0;
    bVar30 = (*(uint *)(unaff_retaddr + -0x20) & 0x10) != 0;
    *pbVar22 = *pbVar22 - bVar9;
    *pbVar22 = *pbVar22 ^ bVar9;
    unaff_ESI = (uint *)(CONCAT31(uVar16,bVar8 - 0x3b) ^ 0x3b);
    puVar23 = (undefined4 *)(unaff_retaddr + -0x1c);
  }
  *(undefined2 *)(puVar23 + -1) = in_SS;
  pbVar25 = pbVar24 + (uint)bVar31 * -8 + 4;
  out(*(undefined4 *)pbVar24,(short)pbVar20);
  if (unaff_ESI == (uint *)0x3e033dce) {
    *pbVar25 = *pbVar25 + 1;
    bVar8 = (byte)((uint)pbVar20 >> 8);
    bRam3e033dcf = bRam3e033dcf + bVar8;
    puVar13 = (uint *)(int)(short)CONCAT31(0x3e033d,bRam3e033dcf & 0xcf);
    *(byte *)puVar13 = (char)*puVar13 + (bRam3e033dcf & 0xcf);
    *(byte *)puVar13 = (char)*puVar13 + bVar7;
    pbVar22[0x30] = pbVar22[0x30] ^ bVar8;
    *puVar13 = *puVar13 ^ 0x31133103;
    pbVar20 = pbVar20 + -1;
    *(uint *)(unaff_EBP + 0x31) = *(uint *)(unaff_EBP + 0x31) ^ unaff_EBP;
    puVar23 = puVar23 + -1;
  }
  else {
    iVar19 = iVar19 + 1;
    puVar28 = (uint *)((int)puVar28 + -1);
    pbVar25 = (byte *)*puVar23;
    *puVar23 = 0x80367636;
  }
  uVar10 = CONCAT31(0xb36f9,bVar30 * '\x06' + '6') & 0xffffff0f;
  bVar7 = (byte)uVar10;
  uVar26 = *(int *)pbVar25 + 4 + (uint)bVar31 * -8 & *puVar28;
  *(char *)puVar28 = (char)*puVar28 - (char)((uint)pbVar20 >> 8);
  *(uint *)((int)puVar23 + -4) = CONCAT22((short)(uVar10 >> 0x10),CONCAT11(bVar30 - 7,bVar7));
  *(int *)((int)puVar23 + -8) = iVar19;
  *(byte **)((int)puVar23 + -0xc) = pbVar20;
  *(byte **)((int)puVar23 + -0x10) = pbVar22;
  *(undefined4 **)((int)puVar23 + -0x14) = puVar23;
  *(uint *)((int)puVar23 + -0x18) = unaff_EBP;
  *(uint *)((int)puVar23 + -0x1c) = uVar26;
  *(uint **)((int)puVar23 + -0x20) = puVar28;
  bVar30 = 9 < bVar7 | bVar30;
  bVar7 = bVar7 + bVar30 * '\x06' & 0xf;
  uVar10 = in((short)pbVar20);
  *puVar28 = uVar10;
  bVar30 = 9 < bVar7 | bVar30;
  bVar8 = bVar7 + bVar30 * '\x06' & 0xf;
  LOCK();
  bVar7 = *pbVar20;
  DAT_6c380b37 = bVar8;
  *pbVar20 = bVar9;
  UNLOCK();
  bVar30 = 9 < bVar8 | bVar30;
  bVar8 = bVar8 + bVar30 * -6 & 0xf;
  bVar30 = 9 < bVar8 | bVar30;
  puVar27 = (undefined1 *)(uVar26 + 1);
  uVar2 = *(undefined4 *)((int)puVar23 + -0x20);
  bVar8 = 9 < ((byte)uVar2 & 0xf) | 9 < (bVar8 + bVar30 * -6 & 0xf) | bVar30;
  bVar9 = (byte)uVar2 + bVar8 * -6 & 0xf;
  out(*puVar27,(short)pbVar20);
  bVar30 = 9 < bVar9 | bVar8;
  uVar10 = CONCAT31((int3)((uint)uVar2 >> 8),bVar9 + bVar30 * -6) & 0xffff000f;
  bVar9 = (byte)uVar10;
  uVar10 = CONCAT22((short)(uVar10 >> 0x10),
                    CONCAT11(((char)((uint)uVar2 >> 8) - bVar8) - bVar30,bVar9));
  bVar8 = (byte)iVar19;
  uVar15 = (uint3)((uint)iVar19 >> 8);
  if ((POPCOUNT((uint)puVar27 & 0xff) & 1U) == 0) {
    bVar3 = *(byte *)(unaff_EBP + 0xe032cf32);
    bVar4 = *pbVar20;
    uVar10 = uVar10 ^ *(uint *)(in_GS_OFFSET +
                               CONCAT31(uVar15,bVar8 ^ *(byte *)(uVar10 + 0xab329a32)) + 0x1b33dd33)
    ;
    uVar26 = uVar10 ^ 0x5500b2;
    DAT_36003592 = DAT_36003592 ^ 0x2b;
    bVar8 = (byte)uVar26;
    bVar30 = 9 < (bVar8 & 0xf) | bVar30;
    uVar26 = CONCAT31((int3)(uVar26 >> 8),bVar8 + bVar30 * '\x06') & 0xffffff0f;
    pbVar20 = (byte *)CONCAT22((short)(uVar26 >> 0x10),
                               CONCAT11((char)(uVar10 >> 8) + bVar30,(char)uVar26));
    *(int *)((int)puVar23 + -0x20) = _DAT_133eef3e;
    *pbVar20 = *pbVar20 | (byte)(CONCAT11(bVar7 ^ bVar3 ^ bVar9,bVar21 ^ bVar4) - 1 >> 8);
    return;
  }
  bVar30 = 9 < (bVar8 & 0xf) | bVar30;
  bVar8 = bVar8 + bVar30 * -6 & 0xf;
  bVar31 = 9 < bVar8 || (*(uint *)((int)puVar23 + -0x1c) & 0x10) != 0;
  uVar10 = CONCAT31((int3)(((uint)(uVar15 >> 8) << 0x10) >> 8),bVar8 + bVar31 * -6) & 0xffffff0f;
  _DAT_133eef3e = (longlong)ROUND(fVar32);
  lVar5 = CONCAT44(pbVar20,CONCAT22((short)(uVar10 >> 0x10),
                                    CONCAT11(((char)((uint)iVar19 >> 8) - bVar30) - bVar31,
                                             (char)uVar10))) / (longlong)_DAT_133eef3e;
  pcVar12 = (char *)((int)lVar5 + 0x22);
  *pcVar12 = *pcVar12 + (char)lVar5;
  pcVar12 = (char *)((int)lVar5 * 2 + 0x30080000);
  *pcVar12 = *pcVar12 + bVar7;
  Var1 = to_bcd(extraout_ST1);
  *(unkbyte10 *)CONCAT31((int3)((ulonglong)lVar5 >> 8),(char)lVar5 + -0x30) = Var1;
  pcVar6 = (code *)swi(1);
  (*pcVar6)();
  return;
}
}

// =================================================
// Function: FUN_009c2270
// =================================================
/* WARNING: Instruction at (ram,0x009c233b) overlaps instruction at (ram,0x009c233a)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_009c2270(uint param_1,undefined4 param_2)
{
{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  short sVar4;
  code *pcVar5;
  ushort uVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  char cVar14;
  undefined4 in_EAX;
  char *pcVar10;
  undefined4 uVar11;
  ushort *puVar12;
  uint uVar13;
  uint uVar15;
  int *piVar16;
  undefined1 uVar17;
  int iVar18;
  byte *pbVar19;
  undefined2 uVar20;
  uint *unaff_EBX;
  byte *unaff_EBP;
  byte *unaff_ESI;
  uint *unaff_EDI;
  uint *puVar21;
  byte in_AF;
  byte bVar22;
  byte abStack_28 [4];
  uint uStack_4;
  
  uStack_4 = param_1;
  _DAT_3f233dda = _DAT_3f233dda >> 0x10;
  bVar22 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar15 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar22 * -6) & 0xffffff0f;
  bVar7 = (byte)uVar15;
  pcVar10 = (char *)CONCAT22((short)(uVar15 >> 0x10),
                             CONCAT11((char)((uint)in_EAX >> 8) - bVar22,bVar7));
  *pcVar10 = *pcVar10 + bVar7;
  *pcVar10 = *pcVar10 + bVar7;
  bVar8 = (byte)((uint)param_2 >> 8);
  *(char *)((int)pcVar10 * 2) = *(char *)((int)pcVar10 * 2) + bVar8;
  *(char *)(param_1 + 0xd130c330) = *(char *)(param_1 + 0xd130c330) + bVar8;
  *(byte *)unaff_EBX = (byte)*unaff_EBX ^ bVar8;
  *(uint *)(param_1 + 0x31) = *(uint *)(param_1 + 0x31) ^ (uint)pcVar10;
  *unaff_EBX = *unaff_EBX ^ (uint)unaff_ESI;
  bVar7 = bVar7 ^ pcVar10[0x32] ^ *(byte *)((int)unaff_EBX + (int)unaff_ESI);
  pbVar19 = (byte *)CONCAT31((int3)((uint)pcVar10 >> 8),bVar7);
  uVar15 = param_1 - 1;
  bVar8 = (byte)unaff_EBP;
  cVar14 = (char)((uint)unaff_EBP >> 8);
  if (uVar15 == 0 || bVar7 != 0) {
    unaff_EDI = unaff_EDI + 1;
    unaff_ESI = unaff_ESI + 4;
    piVar16 = (int *)CONCAT31((int3)(uVar15 >> 8),0x36);
    uVar11 = in(0x36);
    bVar7 = (byte)uVar11;
    out((short)unaff_EBP,bVar7);
    iVar18 = CONCAT22((short)((uint)unaff_EBP >> 0x10),CONCAT11(cVar14 + (char)*unaff_EDI,bVar8));
    *unaff_EDI = *unaff_EDI & (uint)unaff_ESI;
    pbVar19 = (byte *)(iVar18 + 1);
    bVar22 = 9 < (bVar7 & 0xf) | bVar22;
    uVar15 = CONCAT31((int3)((uint)uVar11 >> 8),bVar7 + bVar22 * '\x06') & 0xffffff0f;
    puVar12 = (ushort *)
              CONCAT22((short)(uVar15 >> 0x10),
                       CONCAT11((char)((uint)uVar11 >> 8) + bVar22,(char)uVar15));
    *(ushort *)unaff_EDI =
         (short)*unaff_EDI + (ushort)bVar22 * (((ushort)unaff_ESI & 3) - ((ushort)*unaff_EDI & 3));
    if (!SCARRY4(iVar18,1)) {
      pcVar5 = (code *)swi(1);
      uVar11 = (*pcVar5)();
      return uVar11;
    }
LAB_009c22f7:
    pcVar10 = (char *)((int)puVar12 * 2 + 0x30010000);
    *pcVar10 = *pcVar10 + (char)unaff_EBX;
    bVar7 = (byte)((uint)pbVar19 >> 8);
    uVar6 = *puVar12;
    uVar20 = (undefined2)((uint)pbVar19 >> 0x10);
    uVar17 = SUB41(pbVar19,0);
    pbVar19 = (byte *)CONCAT22(uVar20,CONCAT11(bVar7 - (byte)*puVar12,uVar17));
    sVar4 = ((ushort)unaff_ESI & 3) - (*puVar12 & 3);
    *puVar12 = *puVar12 + (ushort)(bVar7 < (byte)*puVar12) * sVar4;
    if (!SBORROW1(bVar7,(byte)uVar6)) goto LAB_009c2334;
    pbVar19 = (byte *)CONCAT22(uVar20,CONCAT11((byte)*puVar12,uVar17));
    *piVar16 = *piVar16 << ((byte)piVar16 & 0x1f);
    bVar2 = ((uint)piVar16 & 0x1f) == 0;
    uVar15 = (int)piVar16 - 1;
    if (uVar15 == 0 || (bVar2 && 0 < sVar4 || !bVar2 && *piVar16 == 0)) goto code_r0x009c230a;
    bVar7 = 9 < (byte)puVar12 | bVar22;
    uVar13 = CONCAT31((int3)((uint)puVar12 >> 8),(byte)puVar12 + bVar7 * '\x06') & 0xffffff0f;
    pcVar10 = (char *)CONCAT22((short)(uVar13 >> 0x10),
                               CONCAT11((char)((uint)puVar12 >> 8) + bVar7,(char)uVar13));
    puVar21 = unaff_EDI;
code_r0x009c233c:
    _DAT_3c393834 = 0x3c393838;
    unaff_EDI = (uint *)((int)puVar21 + 1);
    cVar14 = in((short)pbVar19);
    *(char *)puVar21 = cVar14;
    pbVar1 = *(byte **)(pcVar10 + 0x39);
    if (pbVar1 == unaff_ESI) goto LAB_009c2397;
    if (-1 < (int)pbVar1 - (int)unaff_ESI) {
      if ((int)pbVar1 < (int)unaff_ESI) goto LAB_009c239b;
      goto LAB_009c2373;
    }
  }
  else {
    if (unaff_EBP < *(byte **)(param_1 + 0x3b)) {
      puVar12 = (ushort *)((int)(short)pbVar19 ^ *(uint *)((int)&uStack_4 + (int)unaff_ESI));
      pbVar19 = unaff_EBP;
code_r0x009c230a:
      unaff_EBX = (uint *)CONCAT22((short)((uint)unaff_EBX >> 0x10),
                                   CONCAT11((byte)((uint)unaff_EBX >> 8) ^ (byte)uVar15,
                                            (char)unaff_EBX));
      piVar16 = (int *)(uVar15 ^ *(uint *)((int)puVar12 + -0x6fcc73cd));
      pbVar19 = (byte *)(CONCAT31((int3)((uint)pbVar19 >> 8),
                                  (byte)pbVar19 ^ ((byte *)((int)unaff_EBX + 0x5b))[(int)unaff_ESI])
                        ^ *(uint *)((int)(unaff_EBX + 0xd010ce6) + (int)unaff_ESI));
      abStack_28[(int)piVar16] = abStack_28[(int)piVar16] | (byte)((uint)pbVar19 >> 8);
      uVar15 = (uint)puVar12 ^ 0x2b;
    }
    else {
      bVar3 = 9 < (bVar8 & 0xf) | bVar22;
      bVar8 = bVar8 + bVar3 * -6 & 0xf;
      bVar22 = 9 < bVar8 | bVar3;
      uVar15 = CONCAT31((int3)((uint)unaff_EBP >> 8),bVar8 + bVar22 * -6) & 0xffff000f;
      bVar8 = (byte)uVar15;
      cVar14 = (cVar14 - bVar3) - bVar22;
      uVar15 = CONCAT22((short)(uVar15 >> 0x10),CONCAT11(cVar14,bVar8));
      piVar16 = (int *)(param_1 - 2);
      if (piVar16 == (int *)0x0 || *unaff_ESI != 0x53) {
        bVar22 = 9 < bVar8 | bVar22;
        uVar15 = CONCAT31((int3)(uVar15 >> 8),bVar8 + bVar22 * -6) & 0xffffff0f;
        cVar9 = (char)uVar15;
        puVar12 = (ushort *)CONCAT22((short)(uVar15 >> 0x10),CONCAT11(cVar14 - bVar22,cVar9));
        *(byte *)puVar12 = (byte)*puVar12 + cVar9;
        *(byte *)puVar12 = (byte)*puVar12 + bVar7;
        goto LAB_009c22f7;
      }
    }
    puVar12 = (ushort *)(uVar15 ^ 0x3673351a);
LAB_009c2334:
    *unaff_ESI = *unaff_ESI ^ 0x33;
    bVar22 = 9 < ((byte)puVar12 & 0xf) | bVar22;
    bVar8 = (byte)puVar12 + bVar22 * '\x06' & 0xf;
    bVar7 = 9 < bVar8 | bVar22;
    uVar15 = CONCAT31((int3)((uint)puVar12 >> 8),bVar8 + bVar7 * '\x06') & 0xffff000f;
    pcVar10 = (char *)CONCAT22((short)(uVar15 >> 0x10),
                               CONCAT11((char)((uint)puVar12 >> 8) + bVar22 + bVar7,(char)uVar15));
    uVar15 = (int)piVar16 - 1;
    puVar21 = unaff_EDI;
    if (uVar15 == 0 || &stack0x00000000 == (undefined1 *)0x27) goto code_r0x009c233c;
LAB_009c2373:
    bVar22 = *unaff_ESI;
    *(int *)unaff_ESI = *(int *)unaff_ESI >> 0x1a;
    unaff_EBX = (uint *)CONCAT31(CONCAT21((short)((uint)unaff_EBX >> 0x10),bVar22),0x3f);
    *(char *)unaff_EDI = (char)*unaff_EDI;
    *unaff_EBP = *unaff_EBP & (byte)pbVar19;
    *pcVar10 = *pcVar10 + (char)pcVar10;
LAB_009c2397:
    uVar15 = CONCAT31((int3)(uVar15 >> 8),(char)uVar15 + (char)((uint)pcVar10 >> 8));
  }
  pbVar19 = (byte *)CONCAT31((int3)((uint)pbVar19 >> 8),(byte)pbVar19 ^ (byte)((uint)unaff_EBX >> 8)
                            );
LAB_009c239b:
  *pbVar19 = *pbVar19 ^ (byte)((uint)pcVar10 >> 8);
  *unaff_EBX = *unaff_EBX ^ (uint)pcVar10;
  *(byte *)unaff_EDI =
       (char)*unaff_EDI +
       (((byte)((uint)pbVar19 >> 8) ^ *(byte *)((int)unaff_EBX + 0x4133c033) | *unaff_ESI) ^
       *unaff_ESI) + CARRY4((uint)unaff_ESI,*unaff_EDI);
  bVar7 = 9 < ((byte)uVar15 & 0xf) | bVar7;
  bVar8 = (byte)uVar15 + bVar7 * '\x06' & 0xf;
  bVar22 = 9 < bVar8 | bVar7;
  uVar13 = CONCAT31((int3)(uVar15 >> 8),bVar8 + bVar22 * '\x06') & 0xffff000f;
  return CONCAT22((short)(uVar13 >> 0x10),
                  CONCAT11((char)(uVar15 >> 8) + bVar7 + bVar22,(char)uVar13));
}
}

// =================================================
// Function: FastCall_SetDevNameFromObjectClass
// =================================================
void __cdecl FastCall_SetDevNameFromObjectClass(CMwCmdFastCall *param_1)
{
{
  int in_EAX;
  
  if (*(int **)(in_EAX + 0x20) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x009255bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_EAX + 0x20) + 8))();
    return;
  }
  return;
}
}

// =================================================
// Function: FindAutoBalanceSound
// =================================================
ulong __cdecl
FindAutoBalanceSound
          (CFastBuffer<struct_CAudioPort::SAutoBalancedSound> *param_1,CAudioSound *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  void *unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(unaff_EBX,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GxColor>::operator[](unaff_EBX,pCVar3,unaff_ESI);
      if (*(CFastBuffer<struct_CAudioPort::SAutoBalancedSound> **)pSVar2 == param_1) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: FindFadingSound
// =================================================
ulong __cdecl
FindFadingSound(CFastBuffer<struct_CAudioPort::SFadingSound> *param_1,CAudioSound *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  void *unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(unaff_EBX,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                         (unaff_EBX,pCVar3,unaff_ESI);
      if (*(CFastBuffer<struct_CAudioPort::SFadingSound> **)pSVar2 == param_1) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: FindOrAdd
// =================================================
ulong __thiscall
FindOrAdd(void *this,CFastBuffer<class_CGamePlayerScore*> *param_1,CGamePlayerScore **param_2)
{
{
  CFastString *this_00;
  CFastBuffer<class_CGamePlayerScore*> CVar1;
  char cVar2;
  CFastBuffer<class_CCrystalFace*> *pCVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CGamePlayerScore*> *pCVar5;
  SCasterCat *pSVar6;
  int extraout_EAX;
  ulong extraout_EAX_00;
  ulong uVar7;
  char *pcVar8;
  ulong uVar9;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  TiXmlAttribute *unaff_ESI;
  COalDevice *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  void *unaff_retaddr;
  undefined4 *in_stack_0000000c;
  char *in_stack_00000014;
  COalDevice *local_18 [2];
  CFastBuffer<class_CGamePlayerScore*> *local_10;
  CFastBuffer<class_CGamePlayerScore*> *local_c;
  char *local_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  local_8 = &LAB_00acaffb;
  local_c = ExceptionList;
  pCVar3 = (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_c;
  *in_stack_0000000c = 0;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,pCVar3);
  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      local_10 = param_1;
      if (param_1 == (CFastBuffer<class_CGamePlayerScore*> *)0x0) {
        pCVar5 = (CFastBuffer<class_CGamePlayerScore*> *)0x0;
      }
      else {
        pCVar5 = param_1;
        do {
          CVar1 = *pCVar5;
          pCVar5 = pCVar5 + 1;
        } while (CVar1 != (CFastBuffer<class_CGamePlayerScore*>)0x0);
        pCVar5 = pCVar5 + -(int)(param_1 + 1);
      }
      local_c = pCVar5;
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this,pCVar10,(ulong)unaff_EDI);
      if (pCVar5 == *(CFastBuffer<class_CGamePlayerScore*> **)(*(int *)pSVar6 + 0x14)) {
        unaff_EDI = (COalDevice *)0x0;
        CFastString::Compare
                  ((CFastString *)(*(int *)pSVar6 + 0x14),(SParam_Fids *)&local_c,(SParam *)0x0,
                   (int *)unaff_ESI,(int *)unaff_EBP);
        if (extraout_EAX == 0) {
          unaff_ESI = (TiXmlAttribute *)0x7a446f;
          pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this,pCVar10,unaff_EBX)
          ;
          uVar7 = *(ulong *)pSVar6;
          unaff_EBP = pCVar10;
          if (uVar7 != 0) goto LAB_007a44eb;
          break;
        }
      }
      pCVar10 = pCVar10 + 1;
    } while (pCVar10 < pCVar4);
  }
  local_18[0] = operator_new(0x68);
  if (local_18[0] == (COalDevice *)0x0) {
    uVar7 = 0;
    pCVar10 = unaff_EBP;
  }
  else {
    COalDevice::COalDevice(local_18[0],unaff_EDI);
    uVar7 = extraout_EAX_00;
    pCVar10 = unaff_EBP;
  }
  unaff_retaddr = (void *)0xffffffff;
  local_10 = param_1;
  if (param_1 == (CFastBuffer<class_CGamePlayerScore*> *)0x0) {
    local_c = (CFastBuffer<class_CGamePlayerScore*> *)0x0;
  }
  else {
    pCVar5 = param_1 + 1;
    do {
      CVar1 = *param_1;
      param_1 = param_1 + 1;
    } while (CVar1 != (CFastBuffer<class_CGamePlayerScore*>)0x0);
    local_c = param_1 + -(int)pCVar5;
  }
  CFastString::SetString
            ((CFastString *)(uVar7 + 0x14),(CFastStringInt *)&local_10,(SStringParam *)unaff_EDI);
  in_stack_00000014[0] = '\x01';
  in_stack_00000014[1] = '\0';
  in_stack_00000014[2] = '\0';
  in_stack_00000014[3] = '\0';
  CFastBuffer<class_CDx9TextureKeeper*>::Add(this,(TiXmlAttributeSet *)local_18,unaff_ESI);
LAB_007a44eb:
  if (in_stack_00000014 != (char *)0x0) {
    local_8 = in_stack_00000014;
    pcVar8 = in_stack_00000014;
    do {
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    iStack_4 = (int)pcVar8 - (int)(in_stack_00000014 + 1);
    this_00 = (CFastString *)(uVar7 + 0x1c);
    uVar9 = CFastString::FindFirst(this_00,(CFastStringInt *)&local_8,0,1);
    if (uVar9 == 0xffffffff) {
      if (*(int *)this_00 != 0) {
        local_8 = "; ";
        iStack_4 = 2;
        CFastString::Concat(this_00,(CFastStringInt *)&local_8,(SStringParam *)pCVar10);
      }
      pcVar8 = in_stack_00000014 + 1;
      do {
        cVar2 = *in_stack_00000014;
        in_stack_00000014 = in_stack_00000014 + 1;
      } while (cVar2 != '\0');
      local_c = (CFastBuffer<class_CGamePlayerScore*> *)(in_stack_00000014 + -(int)pcVar8);
      CFastString::Concat(this_00,(CFastStringInt *)&local_10,(SStringParam *)pCVar10);
    }
  }
  ExceptionList = unaff_retaddr;
  return uVar7;
}
}

// =================================================
// Function: FrameAddControl
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FrameAddControl(CControlFrame *param_1,CControlBase *param_2,TiXmlElement *param_3)
{
{
  CMwId *pCVar1;
  char *pcVar2;
  int iVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *this;
  float unaff_EBX;
  TiXmlElement *unaff_ESI;
  int *unaff_EDI;
  int *piVar5;
  float in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  char *in_stack_ffffffe8;
  int *in_stack_ffffffec;
  CFastStringInt *in_stack_fffffff0;
  char *in_stack_fffffff4;
  int *in_stack_fffffff8;
  char *in_stack_fffffffc;
  GmIso4 *pGVar6;
  
  pCVar1 = (CMwId *)TiXmlElement::Attribute
                              (unaff_ESI,(TiXmlElement *)&DAT_00b3d3d8,in_stack_ffffffe8,
                               in_stack_ffffffec);
  CMwId::SetLocalName((void *)((int)unaff_EBX + 0x18),pCVar1,in_stack_fffffff0);
  piVar5 = (int *)0x0;
  param_2 = (CControlBase *)0x0;
  pcVar2 = TiXmlElement::Attribute
                     (unaff_ESI,(TiXmlElement *)&DAT_00b872a0,in_stack_fffffff4,in_stack_fffffff8);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = TiXmlElement::Attribute
                       (unaff_ESI,(TiXmlElement *)&DAT_00b87298,in_stack_fffffffc,piVar5);
    if (pcVar2 != (char *)0x0) {
      _sscanf_s(pcVar2,"%f %f %f");
      in_stack_00000010 = in_stack_00000010 * (float)_DAT_00b87290;
      in_stack_00000014 = in_stack_00000014 * (float)_DAT_00b33a48;
      in_stack_00000018 = (float)_DAT_00b87290 * in_stack_00000018;
    }
  }
  else {
    _sscanf_s(pcVar2,"%f %f %f");
  }
  iVar3 = TiXmlElement::QueryDoubleAttribute
                    (unaff_ESI,(TiXmlElement *)"scale",(char *)&param_2,(double *)0x3f800000);
  if (iVar3 == 0) {
    param_2 = (CControlBase *)(float)(double)CONCAT44(in_stack_00000010,param_3);
  }
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(**(code **)(*unaff_EDI + 0x1f8))();
  pGVar6 = (GmIso4 *)&param_3;
  this = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>::
         operator[](unaff_EDI + 0x56,pCVar4,(ulong)unaff_EBX);
  GmIso4::SetUScaleTrans(this,pGVar6,unaff_EBX,(GmVec3 *)&stack0x00000014);
  return;
}
}

// =================================================
// Function: GetANSIPathName
// =================================================
void __cdecl GetANSIPathName(CFastStringInt *param_1,CFastString *param_2)
{
{
  longlong lVar1;
  int *in_EAX;
  CFastStringBase<wchar_t> *pCVar2;
  DWORD DVar3;
  LPWSTR lpszShortPath;
  CFastStringBase<char> *unaff_ESI;
  SOldChars *unaff_EDI;
  BOOL local_4;
  
  local_4 = 0;
  pCVar2 = (CFastStringBase<wchar_t> *)
           WideCharToMultiByte(0,0x400,(LPCWSTR)in_EAX[1],*in_EAX,(LPSTR)0x0,0,(LPCSTR)0x0,
                               (LPBOOL)0x0);
  if (pCVar2 != *(CFastStringBase<wchar_t> **)unaff_ESI) {
    CFastStringBase<char>::AllocAtLeast(unaff_ESI,pCVar2,1,0,unaff_EDI);
    pCVar2[*(int *)(unaff_ESI + 4)] = (CFastStringBase<wchar_t>)0x0;
    *(CFastStringBase<wchar_t> **)unaff_ESI = pCVar2;
  }
  WideCharToMultiByte(0,0x400,(LPCWSTR)in_EAX[1],*in_EAX,*(LPSTR *)(unaff_ESI + 4),(int)pCVar2,
                      (LPCSTR)0x0,&local_4);
  if (local_4 != 0) {
    DVar3 = GetShortPathNameW((LPCWSTR)in_EAX[1],(LPWSTR)0x0,0);
    if (DVar3 != 0) {
      lVar1 = (ulonglong)(DVar3 + 1) * 2;
      lpszShortPath = operator_new__(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
      DVar3 = GetShortPathNameW((LPCWSTR)in_EAX[1],lpszShortPath,DVar3);
      pCVar2 = (CFastStringBase<wchar_t> *)
               WideCharToMultiByte(0,0x400,lpszShortPath,DVar3 + 1,(LPSTR)0x0,0,(LPCSTR)0x0,
                                   (LPBOOL)0x0);
      if (pCVar2 != *(CFastStringBase<wchar_t> **)unaff_ESI) {
        CFastStringBase<char>::AllocAtLeast(unaff_ESI,pCVar2,1,0,unaff_EDI);
        pCVar2[*(int *)(unaff_ESI + 4)] = (CFastStringBase<wchar_t>)0x0;
        *(CFastStringBase<wchar_t> **)unaff_ESI = pCVar2;
      }
      WideCharToMultiByte(0,0x400,lpszShortPath,DVar3 + 1,*(LPSTR *)(unaff_ESI + 4),(int)pCVar2,
                          (LPCSTR)0x0,(LPBOOL)0x0);
      operator_delete__(lpszShortPath);
    }
  }
  return;
}
}

// =================================================
// Function: GetCurrentCounter0
// =================================================
int64 __cdecl GetCurrentCounter0(void)
{
{
  int64 local_8;
  
  CMwProfiler::GetTimeStamp(&local_8);
  return local_8;
}
}

// =================================================
// Function: GetCurrentCounter0Frequency
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint64 __cdecl GetCurrentCounter0Frequency(void)
{
{
  BOOL BVar1;
  LARGE_INTEGER LStack_10;
  LARGE_INTEGER LStack_8;
  
  if (DAT_00d73320 == 0 && DAT_00d73324 == 0) {
    BVar1 = QueryPerformanceFrequency(&LStack_10);
    if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      _exit(-1);
    }
    DAT_00d73320 = LStack_10.s.LowPart;
    DAT_00d73324 = LStack_10.s.HighPart;
    BVar1 = QueryPerformanceCounter(&LStack_8);
    if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      _exit(-1);
    }
    _DAT_00d73310 = LStack_8.s.LowPart;
    _DAT_00d73314 = LStack_8.s.HighPart;
  }
  return CONCAT44(DAT_00d73324,DAT_00d73320);
}
}

// =================================================
// Function: GetCurrentCounter1
// =================================================
DWORD GetCurrentCounter1(void)
{
{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00939e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = timeGetTime();
  return DVar1;
}
}

// =================================================
// Function: GetCurrentCounter1Frequency
// =================================================
ulong __cdecl GetCurrentCounter1Frequency(void)
{
{
  return 1000;
}
}

// =================================================
// Function: GetDx9Color
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl GetDx9Color(GmVec3 *param_1,float param_2)
{
{
  float fVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int local_8;
  
  fVar1 = (float)_DAT_00b55d50;
  local_8._0_1_ = (byte)(longlong)ROUND(*(float *)param_1 * fVar1);
  uVar4 = (uint)(byte)local_8;
  local_8 = (int)(longlong)ROUND(param_2 * fVar1);
  uVar2 = local_8 << 8;
  local_8._0_1_ = (byte)(longlong)ROUND(*(float *)(param_1 + 4) * fVar1);
  uVar3 = (uint)(byte)local_8;
  local_8._0_1_ = (byte)(longlong)ROUND(fVar1 * *(float *)(param_1 + 8));
  return ((uVar4 | uVar2) << 8 | uVar3) << 8 | (uint)(byte)local_8;
}
}

// =================================================
// Function: GetDx9VendorFromId
// =================================================
EDx9Vendor __cdecl GetDx9VendorFromId(ulong param_1)
{
{
  if (param_1 < 0x10df) {
    if (param_1 == 0x10de) {
      return 6;
    }
    switch(param_1) {
    case 0x1002:
      return 0;
    case 0x1023:
      return 1;
    case 0x102b:
      return 2;
    case 0x1039:
      return 3;
    case 0x104a:
      return 4;
    case 0x104c:
      return 5;
    }
  }
  else if (param_1 < 0x3d3e) {
    if (param_1 == 0x3d3d) {
      return 9;
    }
    if (param_1 == 0x1106) {
      return 7;
    }
    if (param_1 == 0x121a) {
      return 8;
    }
  }
  else {
    if (param_1 == 0x5333) {
      return 10;
    }
    if (param_1 == 0x8086) {
      return 0xb;
    }
  }
  return 0xc;
}
}

// =================================================
// Function: GetGlobalTime
// =================================================
ulong __cdecl GetGlobalTime(void)
{
{
  ulong uVar1;
  CMwTimerAdapter *in_stack_00000004;
  
  uVar1 = CMwTimerAdapter::GetTime((void *)(DAT_00d731e0 + 0xa0),in_stack_00000004);
  return uVar1;
}
}

// =================================================
// Function: GetGlobalTimeSpeed
// =================================================
float __cdecl GetGlobalTimeSpeed(void)
{
{
  float fVar1;
  CMwTimerAdapter *in_stack_00000004;
  
  fVar1 = CMwTimerAdapter::GetRelativeSpeed((void *)(DAT_00d731e0 + 0xa0),in_stack_00000004);
  return fVar1;
}
}

// =================================================
// Function: GetGxColorFromString
// =================================================
int __cdecl GetGxColorFromString(char *param_1,GxColor *param_2)
{
{
  char *in_EAX;
  uint uVar1;
  uint in_ECX;
  int iVar2;
  char cVar3;
  uchar *unaff_ESI;
  uint uVar4;
  ulong unaff_EDI;
  char *pcVar5;
  uint local_4;
  
  if (in_EAX != (char *)0x0) {
    cVar3 = *in_EAX;
    pcVar5 = in_EAX + 1;
    switch(cVar3) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
      uVar4 = 0;
      local_4 = in_ECX;
      do {
        if (uVar4 != 0) {
          cVar3 = *pcVar5;
          if (cVar3 == '\0') {
            if (uVar4 < 3) {
              return 0;
            }
            cVar3 = 'f';
          }
          else {
            pcVar5 = pcVar5 + 1;
          }
        }
        iVar2 = (int)cVar3;
        uVar1 = iVar2 - 0x30;
        if (9 < uVar1) {
          if (iVar2 - 0x61U < 6) {
            uVar1 = iVar2 - 0x57;
          }
          else if (iVar2 - 0x41U < 6) {
            uVar1 = iVar2 - 0x37;
          }
          else {
            uVar1 = 0;
          }
        }
        *(byte *)((int)&local_4 + uVar4) = (byte)uVar1 << 4 | (byte)uVar1;
        uVar4 = uVar4 + 1;
      } while (uVar4 < 4);
      GxColor::SetFromBGRA
                (param_1,(GmVec3 *)
                         (((local_4 >> 0x18) << 8 | local_4 & 0xff) << 0x10 |
                         (local_4 >> 8 & 0xff) << 8 | local_4 >> 0x10 & 0xff),unaff_ESI,unaff_EDI);
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GetHlslSamplers
// =================================================
void __cdecl
GetHlslSamplers(ulong *param_1,ID3DXConstantTable *param_2,
               CFastBuffer<struct_CPlugFileGPU::SSampler> *param_3)
{
{
  undefined4 uVar1;
  undefined4 *puVar2;
  CFastBuffer<struct_CPlugFileGPU::SSampler> *unaff_retaddr;
  undefined1 *puStack_88;
  undefined4 *local_84;
  undefined4 local_78 [11];
  undefined4 auStack_4c [3];
  undefined1 local_40 [60];
  int *local_4;
  
  local_84 = local_78;
  puStack_88 = local_40;
  puVar2 = (undefined4 *)0x0;
  local_78[0] = 0;
  _D3DXGetShaderSamplers_12();
  if (local_84 != (undefined4 *)0x0) {
    do {
      uVar1 = (**(code **)(*local_4 + 0x24))(local_4,0,auStack_4c[(int)puVar2]);
      param_1 = (ulong *)0x1;
      (**(code **)(*local_4 + 0x18))(local_4,uVar1,&puStack_88,&stack0xffffff74);
      ParseHlslSampler((_D3DXCONSTANT_DESC *)&stack0xffffff84,unaff_retaddr);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    } while (puVar2 < local_84);
  }
  CFastArray<struct_CPlugVertexStream::SDataDecl>::QSort
            (unaff_retaddr,
             (CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *)Sampler_Sort,
             (_func___cdecl_int_SKey_ptr_SKey_ptr *)param_1);
  return;
}
}

// =================================================
// Function: GetKindOS
// =================================================
EKindOS __cdecl GetKindOS(void)
{
{
  if (DAT_00ccc508 == 1) {
    if (0x59 < DAT_00ccc500) {
      return 3;
    }
    return 2 - (DAT_00ccc500 < 10);
  }
  if (DAT_00ccc508 != 2) {
    return 0;
  }
  if (DAT_00ccc4fc < 4) {
    return 4;
  }
  if (DAT_00ccc4fc == 4) {
    return 5;
  }
  if (DAT_00ccc4fc != 5) {
    return (DAT_00ccc4fc != 6) + 10;
  }
  if (1 < DAT_00ccc500) {
    return 8;
  }
  return 7 - (DAT_00ccc500 != 1);
}
}

// =================================================
// Function: GetLocalTime
// =================================================
ulong __cdecl GetLocalTime(void)
{
{
  ulong uVar1;
  CMwTimer *in_stack_00000004;
  
  uVar1 = CMwTimer::GetElapsedTimeSinceInit((void *)(DAT_00d731e0 + 0x70),in_stack_00000004);
  return uVar1;
}
}

// =================================================
// Function: GetMaxDiameter
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl GetMaxDiameter(GmVec3 *param_1)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 8);
  if ((float)_DAT_00b99c50 <= fVar2) {
    return fVar2 * fVar1;
  }
  if ((!NAN(_DAT_00b37b60) && !NAN(fVar2)) && _DAT_00b37b60 < fVar2 != (_DAT_00b37b60 == fVar2)) {
    return fVar1 / fVar2;
  }
  return fVar1;
}
}

// =================================================
// Function: GetParametrizedNodFromModel
// =================================================
CMwNod * __cdecl GetParametrizedNodFromModel(CMwNod *param_1,CPlugTree *param_2)
{
{
  CMwNod *in_ECX;
  CMwNod *local_4;
  
  if (in_ECX == (CMwNod *)0x0) {
    return (CMwNod *)0x0;
  }
  local_4 = (CMwNod *)0x0;
  if (*(CSystemFid **)(in_ECX + 8) != (CSystemFid *)0x0) {
    CSystemFidParameters::RemappedLoadFromFid(&local_4,*(CSystemFid **)(in_ECX + 8),param_1);
    return local_4;
  }
  return in_ECX;
}
}

// =================================================
// Function: GetUsageIndexFromSampler
// =================================================
ulong __cdecl
GetUsageIndexFromSampler
          (CMwId *param_1,CFastBuffer<struct_CPlugFileGPU::SSampler> *param_2,CFastString *param_3,
          SLoadDesc *param_4)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  uint uVar4;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastStringInt *unaff_EDI;
  uint *in_stack_00000018;
  
  CMwId::SetLocalName(param_1,*(CMwId **)(param_3 + 4),unaff_EDI);
  if (param_3 != (CFastString *)0x0) {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(param_3,unaff_ESI);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      iVar1 = *(int *)param_1;
      do {
        pSVar3 = CFastBuffer<struct_SFastCat>::operator[](param_3,pCVar5,unaff_EBP);
        if (*(int *)pSVar3 == iVar1) {
          pSVar3 = CFastBuffer<struct_SFastCat>::operator[](param_3,pCVar5,unaff_EBX);
          return *(uint *)(pSVar3 + 4) >> 2;
        }
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar2);
    }
  }
  uVar4 = *in_stack_00000018 >> 1 & 0x7fff;
  if ((((uVar4 != 0x98) && (uVar4 != 0x99)) && (uVar4 != 0x9c)) &&
     (((uVar4 != 0x9d && (uVar4 != 0x95)) && (uVar4 != 0x96)))) {
    return 0xffffffff;
  }
  *in_stack_00000018 = *in_stack_00000018 | 0x10000;
  return 0;
}
}

// =================================================
// Function: GetUvsFromAtlas
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
GetUvsFromAtlas(ulong param_1,ulong param_2,ulong param_3,GmVec2 *param_4,GmVec2 *param_5)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_3 / param_1;
  uVar5 = param_3 % param_1;
  fVar1 = (float)(int)param_1;
  if ((int)param_1 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  fVar2 = (float)(int)uVar5;
  if ((int)uVar5 < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  *(float *)param_4 = fVar2 / fVar1;
  fVar2 = (float)(int)param_2;
  if ((int)param_2 < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar3 = (float)(int)(uVar4 + 1);
  if ((int)(uVar4 + 1) < 0) {
    fVar3 = fVar3 + _DAT_00c418d0;
  }
  *(float *)(param_4 + 4) = fVar3 / fVar2;
  fVar3 = (float)(int)(uVar5 + 1);
  if ((int)(uVar5 + 1) < 0) {
    fVar3 = fVar3 + _DAT_00c418d0;
  }
  *(float *)param_5 = fVar3 / fVar1;
  fVar1 = (float)(int)uVar4;
  if ((int)uVar4 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  *(float *)(param_5 + 4) = fVar1 / fVar2;
  return;
}
}

// =================================================
// Function: GetVisualExtents
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
GetVisualExtents(CPlugVisual *param_1,float param_2,GmVec3 *param_3,GmVec3 *param_4,GmVec3 *param_5,
                float *param_6)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  float *in_ECX;
  float *in_EDX;
  float *unaff_EDI;
  
  fVar1 = *(float *)(in_EAX + 0x38);
  fVar2 = *(float *)(in_EAX + 0x44);
  fVar3 = *(float *)(in_EAX + 0x3c);
  fVar4 = *(float *)(in_EAX + 0x48);
  *(float *)param_2 = *(float *)(in_EAX + 0x34) - *(float *)(in_EAX + 0x40);
  *(float *)((int)param_2 + 4) = fVar1 - fVar2;
  *(float *)((int)param_2 + 8) = fVar3 - fVar4;
  fVar1 = *(float *)(in_EAX + 0x44);
  fVar2 = *(float *)(in_EAX + 0x38);
  fVar3 = *(float *)(in_EAX + 0x48);
  fVar4 = *(float *)(in_EAX + 0x3c);
  *in_EDX = *(float *)(in_EAX + 0x34) + *(float *)(in_EAX + 0x40);
  in_EDX[1] = fVar1 + fVar2;
  in_EDX[2] = fVar3 + fVar4;
  *in_ECX = *(float *)(in_EAX + 0x40);
  in_ECX[1] = *(float *)(in_EAX + 0x44);
  in_ECX[2] = *(float *)(in_EAX + 0x48);
  fVar2 = (float)_DAT_00b33a58;
  *in_ECX = *in_ECX * fVar2;
  in_ECX[1] = in_ECX[1] * fVar2;
  fVar1 = in_ECX[2];
  in_ECX[2] = fVar1 * fVar2;
  fVar2 = (float)param_1 * (float)param_1 * fVar1 * fVar2 * fVar2 * fVar2;
  *unaff_EDI = fVar2;
  if ((float)param_1 <= 0.0) {
    *unaff_EDI = -fVar2;
    return;
  }
  return;
}
}

// =================================================
// Function: GmVec2_SetScaleTransFromMinMax
// =================================================
void __cdecl GmVec2_SetScaleTransFromMinMax(GmVec2 *param_1,GmVec2 *param_2)
{
{
  float fVar1;
  
  fVar1 = 1.0 / (*(float *)(param_2 + 4) - *(float *)param_2);
  *(float *)param_1 = fVar1;
  *(float *)(param_1 + 4) = -fVar1 * *(float *)param_2;
  return;
}
}

// =================================================
// Function: GmVec3_SetRandomDir
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmVec3_SetRandomDir(GmVec3 *param_1,GmVec3 *param_2,float param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  ulong unaff_EDI;
  float10 fVar6;
  float unaff_retaddr;
  float fStack00000010;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  do {
    iVar5 = _rand();
    fVar1 = ((float)iVar5 / (float)_DAT_00b530f8 + (float)iVar5 / (float)_DAT_00b530f8) -
            (float)_DAT_00b2c188;
    iVar5 = _rand();
    fVar2 = ((float)iVar5 / (float)_DAT_00b530f8 + (float)iVar5 / (float)_DAT_00b530f8) - 1.0;
  } while (1.0 < fVar1 * fVar1 + fVar2 * fVar2);
  fVar2 = fVar2 * param_3;
  fVar4 = param_3 * (float)_PTR_00b2c178;
  GmMat3::SetDOV(&local_24,(GmMat3 *)param_2,(GmVec3 *)0x1,unaff_EDI);
  fVar1 = fVar4 * local_1c + fVar2 * local_20 + local_24 * local_18;
  *(float *)param_2 = fVar1;
  fVar3 = local_c * local_24 + local_14 * fVar2 + local_10 * fVar4;
  *(float *)(param_2 + 4) = fVar3;
  fVar2 = local_4 * fVar4 + local_8 * fVar2 + unaff_retaddr * local_24;
  *(float *)(param_2 + 8) = fVar2;
  *(float *)param_2 = *(float *)param_2 + fVar1;
  *(float *)(param_2 + 4) = fVar3 + *(float *)(param_2 + 4);
  fVar2 = fVar2 + *(float *)(param_2 + 8);
  *(float *)(param_2 + 8) = fVar2;
  fStack00000010 =
       *(float *)param_2 * *(float *)param_2 + *(float *)(param_2 + 4) * *(float *)(param_2 + 4) +
       fVar2 * fVar2;
  if (fStack00000010 <= _DAT_00d0ca90) {
    return;
  }
  fVar6 = (float10)func_0x009c1b40();
  fVar1 = 1.0 / (float)fVar6;
  *(float *)param_2 = fVar1 * *(float *)param_2;
  *(float *)(param_2 + 4) = *(float *)(param_2 + 4) * fVar1;
  *(float *)(param_2 + 8) = fVar1 * *(float *)(param_2 + 8);
  return;
}
}

// =================================================
// Function: GpuPerfFile_ReadContent
// =================================================
int __cdecl
GpuPerfFile_ReadContent(CFastString *param_1,SFastToken *param_2,CFastStringInt *param_3)
{
{
  CSystemEngine *extraout_EAX;
  SCasterCat *pSVar1;
  CSystemFidFile *this;
  int iVar2;
  CClassicBuffer *this_00;
  CFastString *pCVar3;
  CSystemFidFile *unaff_EBX;
  char *unaff_EBP;
  int unaff_ESI;
  uint uVar4;
  ulong unaff_EDI;
  char *pcStack00000010;
  char *pcStack00000014;
  undefined4 uStack00000024;
  CFastStringInt *pCVar5;
  char *pcVar6;
  ulong uVar7;
  ulong in_stack_ffffff84;
  int in_stack_ffffff88;
  char in_stack_ffffff8c;
  ulong in_stack_ffffff90;
  CClassicBuffer *in_stack_ffffff94;
  CFastString *pCVar8;
  ulong in_stack_ffffff9c;
  SFastTokenInt *in_stack_ffffffa0;
  void *pvStack_5c;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  CFastString aCStack_4c [4];
  int iStack_48;
  undefined *apuStack_40 [11];
  char *local_14;
  char *pcStack_10;
  undefined *puStack_c;
  char *local_8;
  
  puStack_c = (undefined *)0xffffffff;
  pcStack_10 = &LAB_00a81840;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  CFastStringInt::CFastStringInt
            (&stack0xffffff90,(CFastStringInt *)L"GfxDevicePerfs.txt",
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffff78));
  local_8 = (char *)0x0;
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,unaff_EDI);
  this = CSystemEngine::GetConfigFile
                   (*(CSystemEngine **)pSVar1,extraout_EAX,(CFastStringInt *)0x1,0,unaff_ESI);
  if (in_stack_ffffffa0 != (SFastTokenInt *)PTR_DAT_00bbf7dc) {
    if (((byte)in_stack_ffffffa0[-1] & 0x80) == 0) {
      in_stack_ffffffa0 = in_stack_ffffffa0 + -2;
    }
    else {
      in_stack_ffffffa0 = in_stack_ffffffa0 + -4;
    }
    operator_delete__(in_stack_ffffffa0);
    in_stack_ffffff9c = 0;
    in_stack_ffffffa0 = (SFastTokenInt *)PTR_DAT_00bbf7dc;
  }
  if (this != (CSystemFidFile *)0x0) {
    iVar2 = CSystemFidFile::OSCheckIfExists(this,unaff_EBX);
    if (iVar2 != 0) {
      CSystemFidFile::GetFullName(this,(CPlugFile *)param_3,(CFastStringInt *)0x0);
      pcVar6 = (char *)0x1;
      pCVar5 = (CFastStringInt *)this;
      this_00 = (CClassicBuffer *)(**(code **)**(undefined4 **)(this + 0x6c))();
      if (this_00 != (CClassicBuffer *)0x0) {
        pCVar3 = (CFastString *)(**(code **)(*(int *)this_00 + 0x18))();
        if ((CFastString *)&DAT_00000004 < pCVar3) {
          uVar7 = 0x41fc6b;
          pCVar8 = pCVar3;
          CFastString::SetLength
                    (param_1,pCVar3,in_stack_ffffff84,in_stack_ffffff88,in_stack_ffffff8c);
          iVar2 = CClassicBuffer::ReadAll
                            (this_00,*(CClassicBuffer **)(param_1 + 4),pvStack_5c,in_stack_ffffff90)
          ;
          if (iVar2 != 0) {
            CSystemFid::BufferClose((CSystemFid *)this,(CSystemFid *)this_00,in_stack_ffffff94);
            iVar2 = CFastString::GetNextToken
                              (param_1,(CFastStringInt *)param_2,(SFastTokenInt *)pCVar8);
            if (iVar2 != 0) {
              iVar2 = CFastString::GetNatural
                                ((CFastString *)(param_2 + 8),aCStack_4c,(ulong *)0x0,0,
                                 in_stack_ffffff9c);
              if ((iVar2 != 0) && (iStack_48 == 1)) {
                iVar2 = CFastString::GetNextToken
                                  (param_1,(CFastStringInt *)param_2,in_stack_ffffffa0);
                if (iVar2 != 0) {
                  local_14 = "Vendor";
                  pcStack_10 = "Device";
                  puStack_c = &DAT_00b2eeb8;
                  local_8 = "Aniso1";
                  unaff_EBP = "Aniso2";
                  pcStack00000010 = "PTexD11";
                  pcStack00000014 = "PArith20";
                  apuStack_40[6] = (undefined *)0x0;
                  apuStack_40[7] = PTR_DAT_00bbf7d8;
                  apuStack_40[4] = (undefined *)0x2;
                  apuStack_40[5] = (undefined *)0xffffffff;
                  apuStack_40[8] = (undefined *)0x0;
                  apuStack_40[9] = (undefined *)0x0;
                  apuStack_40[10] = &DAT_00b2ee68;
                  uStack00000024 = 1;
                  uVar4 = 0;
                  while( true ) {
                    iVar2 = CFastString::GetNextToken
                                      ((CFastString *)(param_2 + 8),
                                       (CFastStringInt *)&stack0xffffffa0,(SFastTokenInt *)pCVar5);
                    if (iVar2 == 0) break;
                    SStringParam::SStringParam
                              (&stack0xffffff9c,(SStringParam *)apuStack_40[uVar4],pcVar6);
                    if (pvStack_5c != pvStack_50) break;
                    pcVar6 = (char *)0x0;
                    pCVar5 = (CFastStringInt *)&stack0xffffffa0;
                    iVar2 = CFastString::CompareNoCase
                                      ((CFastString *)&pvStack_50,pCVar5,(SStringParam *)0x0,uVar7);
                    if (iVar2 != 0) break;
                    uVar4 = uVar4 + 1;
                    if (10 < uVar4) {
                      CGameMasterServer::SCriteria::~SCriteria(auStack_54,(SCriteria *)pCVar3);
                      ExceptionList = s_Aniso2_00b2eea8;
                      return 1;
                    }
                  }
                  CGameMasterServer::SCriteria::~SCriteria(auStack_54,(SCriteria *)pCVar3);
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = unaff_EBP;
  return 0;
}
}

// =================================================
// Function: GxLight_SetColorFromImage
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GxLight_SetColorFromImage(GxLight *param_1,CPlugFileImg *param_2,float param_3)
{
{
  int iVar1;
  CPlugFileImg *unaff_ESI;
  GxLight *unaff_EDI;
  CPlugFileImg *in_stack_ffffffe0;
  EGxTexAddress in_stack_ffffffe4;
  float fVar2;
  float fStack_4;
  
  iVar1 = CPlugFileImg::IsInSystemMemory(unaff_ESI,in_stack_ffffffe0);
  if (iVar1 == 0) {
    DAT_00d6e6c0 = DAT_00d6e6c0 + 1;
    iVar1 = (**(code **)(*(int *)unaff_ESI + 0x80))();
    DAT_00d6e6c0 = DAT_00d6e6c0 + -1;
    if (iVar1 == 0) {
      param_2 = (CPlugFileImg *)0x3f800000;
      fVar2 = 1.0;
      GxBGRAColor::Set(&stack0xffffffe4,(CMwCmdScriptVarBool *)&stack0xffffffe8,in_stack_ffffffe4);
      goto LAB_00572087;
    }
  }
  fVar2 = 0.0;
  CPlugFileImg::FilterWrappedPixel
            (unaff_ESI,(CPlugFileImg *)&stack0xffffffe4,(GxBGRAColor_conflict *)&stack0xffffffe8,
             (GxTexCoord *)0x1,4,0,0,0,in_stack_ffffffe4);
LAB_00572087:
  fStack_4 = (float)((uint)param_2 >> 0x10 & 0xff) * (float)_DAT_00b3d080;
  GxLight::SetBaseRGB(unaff_EDI,(GxLight *)&fStack_4,(GmVec3 *)((uint)param_2 & 0xff));
  GxLight::SetIntensity(unaff_EDI,(GxLight *)0x3f800000,fVar2);
  return;
}
}

// =================================================
// Function: InstallPack
// =================================================
void __cdecl
InstallPack(CSystemFids *param_1,char *param_2,char *param_3,int param_4,CSystemFids *param_5,
           CFastBuffer<class_CPlugFilePack*> *param_6,int param_7,int param_8)
{
{
  char cVar1;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined *puVar2;
  CSystemFid *pCVar3;
  char *in_ECX;
  int unaff_EBX;
  EFindWay unaff_ESI;
  SStringParam *unaff_EDI;
  undefined4 unaff_retaddr;
  char *in_stack_00000024;
  char *in_stack_00000028;
  CSystemFids *pCVar4;
  CFastBuffer<class_CPlugFilePack*> *pCVar5;
  int in_stack_ffffffb4;
  char *local_44;
  undefined1 local_40 [4];
  undefined *local_3c;
  undefined *local_38;
  char *local_2c;
  undefined4 local_28;
  undefined *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00ad6518;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar4 = (CSystemFids *)0x0;
  local_4 = 0;
  local_3c = &DAT_00baedd0;
  local_38 = (undefined *)0x2;
  pCVar5 = (CFastBuffer<class_CPlugFilePack*> *)PTR_DAT_00bbf7dc;
  CFastStringInt::CFastStringInt
            (&local_2c,(CFastStringInt *)&local_3c,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffa0));
  local_20 = (undefined *)extraout_EAX[1];
  local_1c = *extraout_EAX;
  local_18 = 0;
  if (in_ECX == (char *)0x0) {
    local_44 = (char *)0x0;
  }
  else {
    local_44 = in_ECX;
    do {
      cVar1 = *local_44;
      local_44 = local_44 + 1;
    } while (cVar1 != '\0');
    local_44 = local_44 + -(int)(in_ECX + 1);
  }
  CFastStringInt::CFastStringInt(local_40,(CFastStringInt *)&stack0xffffffb8,unaff_EDI);
  local_10 = extraout_EAX_00[1];
  local_c = (void *)*extraout_EAX_00;
  local_8 = (undefined1 *)0x0;
  local_2c = "%1.%2k";
  local_28 = 6;
  CFastStringInt::SetCompose
            (&stack0xffffffb4,(CFastStringInt *)&local_2c,(SStringParam *)&local_10,
             (SStringParamInt *)&local_1c);
  if (local_38 != PTR_DAT_00bbf7dc) {
    puVar2 = local_38 + -4;
    if ((local_38[-1] & 0x80) == 0) {
      puVar2 = local_38 + -2;
    }
    operator_delete__(puVar2);
    local_3c = (undefined *)0x0;
    local_38 = PTR_DAT_00bbf7dc;
  }
  if (local_20 != PTR_DAT_00bbf7dc) {
    puVar2 = local_20 + -4;
    if ((local_20[-1] & 0x80) == 0) {
      puVar2 = local_20 + -2;
    }
    operator_delete__(puVar2);
  }
  pCVar3 = CSystemFids::FindFid
                     ((CSystemFids *)param_3,(CSystemFids *)&stack0xffffffb4,(CFastStringInt *)0x1,0
                      ,unaff_ESI);
  if (pCVar3 != (CSystemFid *)0x0) {
    InstallPack((CSystemFids *)param_6,in_stack_00000024,in_stack_00000028,unaff_EBX,pCVar4,pCVar5,
                in_stack_ffffffb4,(int)in_ECX);
  }
  if (local_44 != PTR_DAT_00bbf7dc) {
    if ((local_44[-1] & 0x80U) == 0) {
      local_44 = local_44 + -2;
    }
    else {
      local_44 = local_44 + -4;
    }
    operator_delete__(local_44);
  }
  ExceptionList = (void *)CONCAT31((int3)((uint)unaff_retaddr >> 8),1);
  return;
}
}

// =================================================
// Function: InternalApplyFidParameters
// =================================================
void __cdecl
InternalApplyFidParameters
          (CMwNod *param_1,ulong param_2,CSystemFidParameters *param_3,CSystemFidParameters *param_4
          ,CFastBuffer<class_CSystemFid*> *param_5,CFastBuffer<class_CSystemFid*> *param_6)
{
{
  CSystemFid *this;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int *in_ECX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  GmFrustumIso4 *unaff_EDI;
  CSystemFid *pCVar4;
  CSystemFidParameters *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CGamePlayerScore **ppCVar7;
  undefined1 auStack_1c [4];
  CSystemFid *local_18;
  undefined1 local_14 [4];
  CGamePlayerScore *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a80bf8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (&local_18,
             (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd4));
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(local_14,unaff_EDI);
  ppCVar7 = &local_10;
  pCVar5 = param_3;
  (**(code **)(*in_ECX + 0x54))();
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (auStack_1c,(CFastBuffer<class_CCrystalFace*> *)pCVar5);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pCVar4 = (CSystemFid *)0x417c5a;
      pCVar6 = pCVar3;
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](&local_18,pCVar3,(ulong)param_4);
      this = *(CSystemFid **)pSVar2;
      local_18 = this;
      if (*(int *)(pSVar2 + 4) == 0) {
        param_4 = (CSystemFidParameters *)&local_18;
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x417c74;
        CFastBuffer<class_CGamePlayerScore*>::FindOrAdd
                  (param_5,(CFastBuffer<class_CGamePlayerScore*> *)param_4,ppCVar7);
      }
      CSystemFid::ParametrizedGetLoadableFid(this,pCVar4);
      CFastBuffer<struct_CGameRemoteBuffer::SUser*>::ReplaceByLastIfFound
                (param_3,(CFastBuffer<struct_CGameRemoteBuffer::SUser*> *)&stack0xffffffe0,
                 (SUser **)pCVar6);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&local_18,(CFastBuffer<class_CPlugFileGPUV*> *)param_4);
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: InternalComputePaths
// =================================================
void __cdecl
InternalComputePaths
          (CFastString *param_1,CFastStringInt *param_2,CFastStringInt *param_3,
          CFastStringInt *param_4,CFastStringInt *param_5,CFastStringInt *param_6,
          CFastStringInt *param_7)
{
{
  CFastStringInt *pCVar1;
  SStringParam *pSVar2;
  CFastStringInt *extraout_EAX;
  undefined *puVar3;
  undefined4 *extraout_EAX_00;
  int iVar4;
  CFastStringInt *in_ECX;
  SStringParam *unaff_EBX;
  uint unaff_EBP;
  SStringParam *unaff_ESI;
  CFastStringInt *unaff_EDI;
  SStringParam *in_stack_ffffffb8;
  SStringParam *in_stack_ffffffbc;
  SStringParam *in_stack_ffffffc0;
  SStringParam *in_stack_ffffffc4;
  SStringParam *pSVar5;
  SStringParam *pSVar6;
  SStringParam *pSVar7;
  ulong uVar8;
  SStringParam *local_24;
  undefined *local_20;
  undefined *local_1c;
  int local_18;
  void *local_14;
  undefined1 *local_10;
  undefined *local_c;
  undefined *local_8;
  undefined *puVar9;
  
  local_10 = &LAB_00a81590;
  local_14 = ExceptionList;
  pSVar2 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffb0);
  ExceptionList = &local_14;
  pSVar5 = (SStringParam *)0x0;
  local_c = (undefined *)0x0;
  pSVar6 = (SStringParam *)PTR_DAT_00bbf7dc;
  CSystemEngine::GetRunDir((CFastStringInt *)&stack0xffffffc8);
  pSVar7 = pSVar6;
  CFastStringInt::SetString(in_ECX,(CFastStringInt *)&stack0xffffffd0,pSVar2);
  CFastStringInt::CFastStringInt(&stack0xffffffd4,(CFastStringInt *)L"Resource\\",unaff_ESI);
  CSystemFileName::ConcatDirectory(in_ECX,extraout_EAX);
  puVar9 = (undefined *)(unaff_EBP & 0xffffff00);
  if (local_24 != (SStringParam *)PTR_DAT_00bbf7dc) {
    if ((*(byte *)(local_24 + -1) & 0x80) == 0) {
      puVar3 = local_24 + -2;
    }
    else {
      puVar3 = local_24 + -4;
    }
    operator_delete__(puVar3);
  }
  local_20 = (undefined *)0x0;
  local_24 = pSVar7;
  CFastStringInt::SetString(param_4,(CFastStringInt *)&stack0xffffffd8,unaff_EBX);
  local_24 = (SStringParam *)DAT_00d71d5c;
  local_20 = DAT_00d71d58;
  local_1c = (undefined *)0x0;
  CFastStringInt::SetString(unaff_EDI,(CFastStringInt *)&local_24,in_stack_ffffffb8);
  local_20 = (undefined *)DAT_00d71d5c;
  local_1c = DAT_00d71d58;
  local_18 = 0;
  CFastStringInt::SetString(param_5,(CFastStringInt *)&local_20,in_stack_ffffffbc);
  uVar8 = 0;
  param_2 = (CFastStringInt *)CONCAT31(param_2._1_3_,2);
  pSVar2 = (SStringParam *)PTR_DAT_00bbf7dc;
  CFastStringInt::CFastStringInt(&stack0xffffffcc,(CFastStringInt *)&local_24,in_stack_ffffffc0);
  param_3 = (CFastStringInt *)CONCAT31(param_3._1_3_,3);
  if (*(void **)param_2 == (void *)0x0) {
    CFastStringInt::CFastStringInt(&local_18,(CFastStringInt *)L"Nadeo.ini",in_stack_ffffffc4);
    local_8 = (undefined *)extraout_EAX_00[1];
    puVar9 = (undefined *)*extraout_EAX_00;
    param_4 = (CFastStringInt *)CONCAT31(param_4._1_3_,4);
    CFastStringInt::Concat(&stack0xffffffd4,(CFastStringInt *)&local_8,pSVar5);
    param_5 = (CFastStringInt *)CONCAT31(param_5._1_3_,3);
    if (local_c != PTR_DAT_00bbf7dc) {
      if ((local_c[-1] & 0x80) == 0) {
        puVar3 = local_c + -2;
      }
      else {
        puVar3 = local_c + -4;
      }
      operator_delete__(puVar3);
    }
  }
  else {
    local_18 = *(int *)(param_2 + 4);
    local_10 = (undefined1 *)0x0;
    local_14 = *(void **)param_2;
    CFastStringInt::Concat(&stack0xffffffd0,(CFastStringInt *)&local_18,in_stack_ffffffc4);
  }
  CSystemEngine::FileIniSetFullName((CFastStringInt *)&stack0xffffffd8);
  CSystemEngine::FileIniSetSection(param_1);
  CFastString::CFastString((CFastString *)&local_10,(CFastString *)"UserSubDir",(char *)pSVar6);
  param_6 = (CFastStringInt *)CONCAT31(param_6._1_3_,5);
  CSystemEngine::FileIniRead((CFastString *)&local_c,(CFastString *)&DAT_00d71ca4,param_1);
  param_6 = (CFastStringInt *)CONCAT31(param_6._1_3_,3);
  if (local_8 != PTR_DAT_00bbf7d8) {
    puVar3 = local_8 + -1;
    if ((local_8[-1] & 0x80) != 0) {
      puVar3 = local_8 + -4;
    }
    operator_delete__(puVar3);
  }
  local_8 = DAT_00d71ca4;
  local_c = DAT_00d71ca8;
  CFastStringInt::SetUtf8(&local_1c,(CFastStringInt *)&local_c,pSVar7);
  param_7 = (CFastStringInt *)CONCAT31(param_7._1_3_,2);
  if (local_1c != PTR_DAT_00bbf7dc) {
    if ((local_1c[-1] & 0x80) == 0) {
      puVar3 = local_1c + -2;
    }
    else {
      puVar3 = local_1c + -4;
    }
    operator_delete__(puVar3);
  }
  if (local_18 != 0) {
    CSystemEngine::GetMyDocumentsDir(unaff_EDI);
    CSystemFileName::ConcatDirectory(unaff_EDI,(CFastStringInt *)&local_18);
    pCVar1 = param_5;
    CSystemEngine::GetSharedAppDir(param_5);
    CSystemFileName::ConcatDirectory(pCVar1,(CFastStringInt *)&local_18);
    pCVar1 = param_3;
    if (*(int *)param_3 != 0) {
      local_8 = &DAT_00b2ecd0;
      puVar9 = (undefined *)0x3;
      if ((*(int *)param_3 == 3) &&
         (iVar4 = CFastStringInt::CompareNoCase
                            (param_3,(CFastStringInt *)&local_8,(SStringParam *)0x0,uVar8),
         iVar4 == 0)) {
        param_2 = *(CFastStringInt **)(param_4 + 4);
        param_3 = *(CFastStringInt **)param_4;
        param_4 = (CFastStringInt *)0x0;
        CFastStringInt::SetString(unaff_EDI,(CFastStringInt *)&param_2,pSVar2);
        CSystemFileName::ConcatDirectory(unaff_EDI,(CFastStringInt *)&local_10);
      }
      else {
        param_2 = *(CFastStringInt **)(pCVar1 + 4);
        param_3 = *(CFastStringInt **)pCVar1;
        param_4 = (CFastStringInt *)0x0;
        CFastStringInt::SetString(unaff_EDI,(CFastStringInt *)&param_2,pSVar2);
        CSystemFileName::FixFileName(unaff_EDI,0x27);
      }
    }
  }
  if (local_c != PTR_DAT_00bbf7dc) {
    if ((local_c[-1] & 0x80) == 0) {
      puVar3 = local_c + -2;
    }
    else {
      puVar3 = local_c + -4;
    }
    operator_delete__(puVar3);
    local_10 = (undefined1 *)0x0;
    local_c = PTR_DAT_00bbf7dc;
  }
  if (puVar9 != PTR_DAT_00bbf7dc) {
    if ((puVar9[-1] & 0x80) == 0) {
      puVar9 = puVar9 + -2;
    }
    else {
      puVar9 = puVar9 + -4;
    }
    operator_delete__(puVar9);
  }
  ExceptionList = param_7;
  return;
}
}

// =================================================
// Function: InternalDoMobilPtr
// =================================================
void __cdecl InternalDoMobilPtr(CSceneMobil **param_1,CClassicArchive *param_2)
{
{
  undefined4 uVar1;
  int *unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (unaff_ESI[2] != 0) {
    CSceneMobil::GetModel((CSceneMobil *)*unaff_EDI,(CSceneMobil *)0x0);
  }
  (**(code **)(*unaff_ESI + 4))();
  if ((int *)register0x00000010 != (int *)0x0) {
    if (unaff_ESI[2] == 0) {
      uVar1 = (**(code **)(*(int *)register0x00000010 + 0xac))();
      *unaff_EDI = uVar1;
    }
    (**(code **)(*(int *)*unaff_EDI + 200))();
    return;
  }
  (**(code **)(*unaff_ESI + 4))();
  return;
}
}

// =================================================
// Function: InternalFindAnchorPoints
// =================================================
void __cdecl
InternalFindAnchorPoints
          (CFastBuffer<class_CControlContainer*> *param_1,CControlContainer *param_2,int param_3)
{
{
  CSceneMobil *this;
  SCasterCat *pSVar1;
  CSceneMobil *pCVar2;
  int iVar3;
  CSceneMobil *unaff_EBX;
  TiXmlAttribute *unaff_EBP;
  CControlContainer *this_00;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  int in_stack_00000010;
  
  if (*(int *)(param_2 + 300) != 0) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add(param_1,(TiXmlAttributeSet *)&param_2,unaff_EBP);
    return;
  }
  this_00 = param_2 + 0x144;
  param_3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (param_3 != 0) {
    do {
      pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
      this = *(CSceneMobil **)pSVar1;
      if (in_stack_00000010 == 0) {
        unaff_ESI = 0x766e65;
        pCVar2 = CSceneMobil::GetModel(this,unaff_EBX);
        if (pCVar2 == (CSceneMobil *)0x0) goto LAB_00766e69;
      }
      else {
LAB_00766e69:
        unaff_EBX = (CSceneMobil *)0x7002000;
        unaff_ESI = 0x766e77;
        iVar3 = (**(code **)(*(int *)this + 0x10))();
        if (iVar3 != 0) {
          InternalFindAnchorPoints
                    ((CFastBuffer<class_CControlContainer*> *)param_2,(CControlContainer *)this,
                     in_stack_00000010);
        }
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < (uint)param_3);
  }
  return;
}
}

// =================================================
// Function: InternalGetSpawnLoc
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
InternalGetSpawnLoc(GmIso4 *param_1,GmNat3 *param_2,ECardinalDir param_3,GmNat3 *param_4,
                   GmIso4 *param_5,ulong param_6,ulong param_7)
{
{
  float fVar1;
  float fVar2;
  CGameCtnBlock *in_ECX;
  GmIso4 *in_EDX;
  void *unaff_ESI;
  GmIso4 *in_stack_ffffffc8;
  GmVec3 *in_stack_ffffffcc;
  CGameCtnBlock local_30 [4];
  float local_2c;
  float local_28;
  float local_24;
  
  CGameCtnBlock::GetMobilLoc(in_ECX,local_30,in_EDX);
  GmIso4::SetMult(unaff_ESI,(SPlugFaceCull *)param_3,(SPlugFaceCull *)&local_28,in_stack_ffffffc8);
  if (param_2 != (GmNat3 *)0x0) {
    GmMat3::GetLine(unaff_ESI,(GmMat3 *)0x0,(ulong)local_30,in_stack_ffffffcc);
    fVar1 = (float)(int)param_7;
    if ((int)param_7 < 0) {
      fVar1 = fVar1 + _DAT_00c418d0;
    }
    fVar2 = (float)(int)(param_2 + -1);
    if ((int)(param_2 + -1) < 0) {
      fVar2 = fVar2 + _DAT_00c418d0;
    }
    fVar1 = (fVar1 - fVar2 * (float)_DAT_00b313b8) * (float)_DAT_00b508a0;
    *(float *)((int)unaff_ESI + 0x24) = *(float *)((int)unaff_ESI + 0x24) + fVar1 * local_2c;
    *(float *)((int)unaff_ESI + 0x28) = *(float *)((int)unaff_ESI + 0x28) + local_28 * fVar1;
    *(float *)((int)unaff_ESI + 0x2c) = *(float *)((int)unaff_ESI + 0x2c) + fVar1 * local_24;
  }
  return;
}
}

// =================================================
// Function: InternalMwCheckThis
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl InternalMwCheckThis(CMwNod *param_1)
{
{
  int iVar1;
  undefined4 *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    iVar1 = CheckInstance(unaff_ESI,0x14);
    if (iVar1 != 0) {
      if ((_DAT_00d733cc & 1) == 0) {
        _DAT_00d733cc = _DAT_00d733cc | 1;
        CMwNod::CMwNod((CMwNod *)&DAT_00d733b8,unaff_retaddr,param_1);
        _atexit(`int___cdecl_InternalMwCheckThis(class_CMwNod_const*)'::__l8::
                _dynamic_atexit_destructor_for__s_NodToGetVtableFrom__);
      }
      if ((_DAT_00d733cc & 2) == 0) {
        _DAT_00d733cc = _DAT_00d733cc | 2;
        DAT_00d733b4 = DAT_00d733b8;
      }
      return (uint)(*(int *)*unaff_ESI == *DAT_00d733b4);
    }
  }
  return 0;
}
}

// =================================================
// Function: Internal_VirtualParam_AddOrSub
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl
Internal_VirtualParam_AddOrSub(CMwNod *param_1,CMwStack *param_2,void *param_3,int param_4)
{
{
  CMwStack *pCVar1;
  ulong uVar2;
  void *unaff_EBX;
  CMwValueStd *unaff_ESI;
  ulong unaff_EDI;
  void *unaff_retaddr;
  CMwStack *in_stack_00000018;
  int in_stack_0000001c;
  CMwStack local_48 [4];
  CMwNod *local_44;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae2f5e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = *(CMwStack **)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18) * 4);
  if (((*(int *)pCVar1 == 5) && (((byte)pCVar1[0x14] & 1) != 0)) && (0 < *(int *)(param_2 + 0x18)))
  {
    if ((DAT_00d733b0 & 1) == 0) {
      DAT_00d733b0 = DAT_00d733b0 | 1;
      local_4 = 0;
      CMwStack::CMwStack((CMwStack *)&DAT_00d73394,(CMwStack *)0x1,
                         DAT_00cca150 ^ (uint)&stack0xffffffa4);
      _atexit(`unsigned_long___cdecl_Internal_VirtualParam_AddOrSub(class_CMwNod*,class_CMwStack*,void*,int)'
              ::__l5::_dynamic_atexit_destructor_for__StackForGetNod__);
      unaff_retaddr = (void *)0xffffffff;
    }
    DAT_00d73398 = 1;
    CMwStack::ChangeBaseVal((CMwStack *)&DAT_00d73394,pCVar1,unaff_EDI);
    *DAT_00d733a8 = 0;
    _DAT_00d733ac = DAT_00d73398 + -1;
    uVar2 = CMwNod::Param_Get(param_3,(CMwNod *)&DAT_00d73394,local_48,unaff_ESI);
    if (uVar2 == 0) {
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
      if (in_stack_0000001c != 0) {
        uVar2 = CMwNod::Param_Add(local_44,(CMwNod *)param_2,in_stack_00000018,unaff_EBX);
        ExceptionList = param_1;
        return uVar2;
      }
      uVar2 = CMwNod::Param_Sub(local_44,(CMwNod *)param_2,in_stack_00000018,unaff_EBX);
      ExceptionList = param_1;
      return uVar2;
    }
  }
  else {
    uVar2 = 0;
  }
  ExceptionList = unaff_retaddr;
  return uVar2;
}
}

// =================================================
// Function: IsChatCommandBis
// =================================================
int __cdecl IsChatCommandBis(CFastStringInt *param_1,CFastStringInt *param_2)
{
{
  int *in_EAX;
  int extraout_EAX;
  int *unaff_ESI;
  int *unaff_EDI;
  
  CFastStringInt::Compare
            (in_EAX,(SParam_Fids *)&stack0xfffffff4,(SParam *)*in_EAX,unaff_EDI,(int *)unaff_ESI[1])
  ;
  if ((extraout_EAX == 0) &&
     ((*unaff_ESI == *in_EAX || (*(short *)(unaff_ESI[1] + *in_EAX * 2) == 0x20)))) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: IsNull
// =================================================
int __thiscall IsNull(void *this,CSysFidNodRef<class_CPlugBitmap> *param_1)
{
{
  char cVar1;
  uint uVar2;
  uint unaff_ESI;
  
  uVar2 = 0;
  if (unaff_ESI != 0) {
    do {
      cVar1 = *(char *)this;
      this = (void *)((int)this + 1);
      if (cVar1 != '\0') {
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < unaff_ESI);
  }
  return 1;
}
}

// =================================================
// Function: IsPrime
// =================================================
int __cdecl IsPrime(ulong param_1)
{
{
  uint uVar1;
  uint uVar2;
  uint unaff_EDI;
  
  if (unaff_EDI < 0xb) {
    return 0;
  }
  uVar2 = 9;
  uVar1 = 3;
  if (9 < unaff_EDI) {
    do {
      if (unaff_EDI % uVar1 == 0) break;
      uVar2 = uVar2 + (uVar1 + 1) * 4;
      uVar1 = uVar1 + 2;
    } while (uVar2 < unaff_EDI);
  }
  return (uint)(unaff_EDI % uVar1 != 0);
}
}

// =================================================
// Function: LightTrailAddPartVerts
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
LightTrailAddPartVerts
          (CMotionParticleType *param_1,CFastBuffer<class_GxVertex> *param_2,GxTexCoord *param_3,
          SPart *param_4,SPartState *param_5,ulong param_6,GmVec3 *param_7,GmVec3 *param_8,
          GmVec3 *param_9)
{
{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  ulong uVar9;
  float fVar10;
  SLoadedLight *pSVar11;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBP;
  uint uVar12;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  uint in_stack_00000028;
  float *in_stack_0000002c;
  float *in_stack_00000030;
  int in_stack_00000034;
  float *local_40;
  float local_34;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  fVar1 = *(float *)(param_4 + 0x20);
  fVar2 = *(float *)(param_4 + 0x2c);
  local_34 = *(float *)(param_4 + 0x30);
  uVar9 = CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EDI);
  uVar12 = 0;
  if (param_7 != (GmVec3 *)0x0) {
    do {
      CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EBX);
      unaff_EBX = (CFastBuffer<class_CCrystalFace*> *)0x5666d6;
      fVar10 = (float)CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize
                                (param_2,unaff_ESI);
      if ((uint)fVar10 <= (uint)local_34) {
        return;
      }
      unaff_ESI = (CFastBuffer<struct_SCtnForcedMods::SEnvMod> *)0x5666eb;
      pSVar11 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(param_4 + uVar9 * 8,unaff_EBP);
      if (*(int *)(param_4 + uVar9 * 8 + 0x24) == 7) {
        uVar3 = *(undefined4 *)(param_4 + 0x20);
        uVar4 = *(undefined4 *)(param_4 + 0x2c);
        *(undefined4 *)pSVar11 = *(undefined4 *)(param_4 + 0x14);
        *(undefined4 *)(pSVar11 + 4) = uVar3;
        *(undefined4 *)(pSVar11 + 8) = uVar4;
        fVar10 = (float)(int)((-(uint)((uVar12 & 1) != 0) & 0xfffffffe) + 1) *
                 *(float *)(param_6 + 0x40);
        *(float *)pSVar11 = fVar10 * *(float *)pSVar11;
        *(float *)(pSVar11 + 4) = fVar10 * *(float *)(pSVar11 + 4);
        *(float *)(pSVar11 + 8) = fVar10 * *(float *)(pSVar11 + 8);
        uVar3 = *(undefined4 *)(param_4 + 0x24);
        uVar4 = *(undefined4 *)(param_4 + 0x30);
        *(undefined4 *)(pSVar11 + 0xc) = *(undefined4 *)(param_4 + 0x18);
        fVar10 = (float)(int)uVar12;
        *(undefined4 *)(pSVar11 + 0x10) = uVar3;
        *(undefined4 *)(pSVar11 + 0x14) = uVar4;
        if ((int)uVar12 < 0) {
          fVar10 = fVar10 + _DAT_00c418d0;
        }
        fVar8 = (float)(int)(in_stack_00000028 - 1);
        if ((int)(in_stack_00000028 - 1) < 0) {
          fVar8 = fVar8 + _DAT_00c418d0;
        }
        *(float *)param_8 = fVar10 / fVar8;
      }
      else {
        fVar10 = (float)(int)uVar12;
        if ((int)uVar12 < 0) {
          fVar10 = fVar10 + _DAT_00c418d0;
        }
        fVar8 = (float)(int)in_stack_00000028;
        if ((int)in_stack_00000028 < 0) {
          fVar8 = fVar8 + _DAT_00c418d0;
        }
        __CIcos();
        fVar5 = (float)extraout_ST0;
        *(float *)(pSVar11 + 0xc) = fVar5 * local_20;
        unaff_EBP = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x566843;
        __CIsin();
        fVar6 = (float)extraout_ST0_00;
        fVar7 = fVar5 * local_20 + fVar1 * fVar6;
        *(float *)(pSVar11 + 0xc) = fVar7;
        *(float *)(pSVar11 + 0x10) = fVar5 * local_1c + fVar2 * fVar6;
        *(float *)(pSVar11 + 0x14) = local_18 * fVar5 + local_24 * fVar6;
        local_34 = *(float *)(param_6 + 0x40);
        *(float *)pSVar11 = local_34 * fVar7;
        *(float *)(pSVar11 + 4) = *(float *)(pSVar11 + 0x10) * local_34;
        *(float *)(pSVar11 + 8) = *(float *)(pSVar11 + 0x14) * local_34;
        *(float *)param_8 = fVar10 / fVar8;
      }
      *(float *)pSVar11 = *(float *)pSVar11 + *(float *)(param_6 + 0x28);
      *(float *)(pSVar11 + 4) = *(float *)(param_6 + 0x2c) + *(float *)(pSVar11 + 4);
      *(float *)(pSVar11 + 8) = *(float *)(param_6 + 0x30) + *(float *)(pSVar11 + 8);
      *(undefined4 *)(param_8 + 4) = *(undefined4 *)(param_4 + 0x90);
      *(undefined4 *)(pSVar11 + 0x18) = *(undefined4 *)(param_6 + 0x4c);
      *(undefined4 *)(pSVar11 + 0x1c) = *(undefined4 *)(param_6 + 0x50);
      *(undefined4 *)(pSVar11 + 0x20) = *(undefined4 *)(param_6 + 0x54);
      *(undefined4 *)(pSVar11 + 0x24) = *(undefined4 *)(param_6 + 0x58);
      if (*(float *)pSVar11 < *in_stack_0000002c) {
        *in_stack_0000002c = *(float *)pSVar11;
      }
      if (*(float *)(pSVar11 + 4) < in_stack_0000002c[1]) {
        in_stack_0000002c[1] = *(float *)(pSVar11 + 4);
      }
      if (*(float *)(pSVar11 + 8) < in_stack_0000002c[2]) {
        in_stack_0000002c[2] = *(float *)(pSVar11 + 8);
      }
      if (*in_stack_00000030 < *(float *)pSVar11) {
        *in_stack_00000030 = *(float *)pSVar11;
      }
      if (in_stack_00000030[1] < *(float *)(pSVar11 + 4)) {
        in_stack_00000030[1] = *(float *)(pSVar11 + 4);
      }
      if (in_stack_00000030[2] < *(float *)(pSVar11 + 8)) {
        in_stack_00000030[2] = *(float *)(pSVar11 + 8);
      }
      if (in_stack_00000034 != 0) {
        local_40[-2] = local_24 * local_1c - local_18 * fVar2;
        local_40[-1] = fVar1 * local_18 - local_20 * local_24;
        *local_40 = fVar2 * local_20 - local_1c * fVar1;
      }
      param_8 = param_8 + 8;
      uVar12 = uVar12 + 1;
      local_40 = local_40 + 3;
      param_2 = (CFastBuffer<class_GxVertex> *)param_6;
    } while (uVar12 < in_stack_00000028);
  }
  return;
}
}

// =================================================
// Function: LoadAvatarVariant
// =================================================
CPlugBitmap * __cdecl
LoadAvatarVariant(CPlugBitmap *param_1,CSystemPackDesc *param_2,char *param_3,CGameAvatar *param_4)
{
{
  CSystemFidParameters *extraout_EAX;
  CMwNod *pCVar1;
  int iVar2;
  CSystemFid *in_ECX;
  undefined *puVar3;
  char *unaff_ESI;
  int unaff_EDI;
  CMwNod *in_stack_00000018;
  undefined4 uStack0000001c;
  SParam *pSVar4;
  SParam *pSVar5;
  int in_stack_ffffff98;
  EGxTexAddress in_stack_ffffff9c;
  CMwNod *in_stack_ffffffa0;
  CSystemFidParameters *in_stack_ffffffa4;
  CPlugBitmap *pCStack_58;
  CPlugBitmap *pCStack_54;
  CPlugBitmap *pCStack_50;
  undefined *local_44;
  CSystemFidParameters local_3c [8];
  CSystemFidParameters local_34 [8];
  CSystemFidParameters local_2c [16];
  CSystemFidParameters aCStack_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00aa1318;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemFidParameters::CSystemFidParameters
            (local_3c,(CSystemFidParameters *)&DAT_00d55500,
             (CSystemFidParameters *)(DAT_00cca150 ^ (uint)&stack0xffffff88));
  if (in_ECX != (CSystemFid *)0x0) {
    CFastString::CFastString((CFastString *)&stack0xffffff98,(CFastString *)param_2,unaff_ESI);
    pSVar5 = (SParam *)0x9025000;
    pSVar4 = (SParam *)&stack0xffffff9c;
    CSystemFidParameters::SParam_Fid::SParam_Fid
              ((SParam_Fid *)&stack0xffffffa4,*(SParam_Fid **)(*(int *)(unaff_EDI + 0x48) + 8),
               in_ECX);
    local_4 = CONCAT31(local_4._1_3_,2);
    CSystemFidParameters::AddParam(local_3c,extraout_EAX,pSVar4);
    if (local_44 != PTR_DAT_00bbf7d8) {
      puVar3 = local_44 + -1;
      if ((local_44[-1] & 0x80) != 0) {
        puVar3 = local_44 + -4;
      }
      operator_delete__(puVar3);
    }
    CSystemFidParameters::SParam::~SParam((SParam *)&stack0xffffffa0,pSVar5);
    if (in_stack_ffffffa0 != (CMwNod *)PTR_DAT_00bbf7d8) {
      pCVar1 = in_stack_ffffffa0 + -1;
      if (((byte)in_stack_ffffffa0[-1] & 0x80) != 0) {
        pCVar1 = in_stack_ffffffa0 + -4;
      }
      operator_delete__(pCVar1);
      in_stack_ffffff9c = 0;
      in_stack_ffffffa0 = (CMwNod *)PTR_DAT_00bbf7d8;
    }
  }
  CSystemFidParameters::Push(local_34,(CFastBufferWheel<float> *)local_34,(float *)0x1);
  DAT_00d133cc = 0;
  iVar2 = CSystemFidParameters::RemappedLoadFromFid
                    ((CMwNod **)&stack0xffffffa0,*(CSystemFid **)(unaff_EDI + 8),in_stack_00000018);
  if ((iVar2 != 0) && (in_stack_ffffffa0 != (CMwNod *)0x0)) {
    (**(code **)(*(int *)in_stack_ffffffa0 + 0x10))();
  }
  DAT_00d133cc = 1;
  CSystemFidParameters::Pop(local_2c,(SCharStyle *)local_2c);
  CPlugBitmap::SetMipMapping((CPlugBitmap *)in_stack_ffffffa4,(CPlugBitmap *)0x0,in_stack_ffffff98);
  CPlugBitmap::SetDefaultTexAddress(pCStack_58,(CPlugBitmap *)0x2,2,0,in_stack_ffffff9c);
  CPlugBitmap::SetMipLevelSkipCountMax(pCStack_54,(CPlugBitmap *)0x1,(ulong)in_stack_ffffffa0);
  uStack0000001c = 0xffffffff;
  CSystemFidParameters::~CSystemFidParameters(aCStack_1c,in_stack_ffffffa4);
  ExceptionList = in_stack_00000018;
  return pCStack_50;
}
}

// =================================================
// Function: LogGlobalMemoryStatus
// =================================================
/* WARNING: Variable defined which should be unmapped: param_2 */

void __cdecl LogGlobalMemoryStatus(_MEMORYSTATUSEX *param_1,CFastString *param_2)
{
{
  CPlugFileGpuBuilder *pCVar1;
  CPlugFileGpuBuilder *unaff_EBX;
  CPlugFileGpuBuilder *unaff_ESI;
  char *unaff_retaddr;
  CPlugFileGpuBuilder *pCVar2;
  char *in_stack_0000000c;
  CPlugFileGpuBuilder *in_stack_00000010;
  char *in_stack_00000014;
  CPlugFileGpuBuilder *in_stack_00000018;
  char *in_stack_0000001c;
  CPlugFileGpuBuilder *in_stack_00000020;
  char *in_stack_00000024;
  CPlugFileGpuBuilder *in_stack_00000028;
  char *in_stack_0000002c;
  CPlugFileGpuBuilder *in_stack_00000030;
  char *in_stack_00000034;
  CPlugFileGpuBuilder *in_stack_00000038;
  char *in_stack_0000003c;
  CPlugFileGpuBuilder *in_stack_00000040;
  char *in_stack_00000044;
  CPlugFileGpuBuilder *in_stack_00000048;
  char *in_stack_0000004c;
  CPlugFileGpuBuilder *in_stack_00000050;
  char *in_stack_00000054;
  CPlugFileGpuBuilder *in_stack_00000058;
  char *in_stack_0000005c;
  CPlugFileGpuBuilder *in_stack_00000060;
  char *in_stack_00000064;
  CPlugFileGpuBuilder *in_stack_00000068;
  char *in_stack_0000006c;
  CPlugFileGpuBuilder *in_stack_00000070;
  char *in_stack_00000074;
  CPlugFileGpuBuilder *in_stack_0000007c;
  char *in_stack_00000080;
  char *pcVar3;
  LPCSTR *ppCVar4;
  
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  ppCVar4 = &lpOutputString_00b2bcc4;
  pcVar3 = " ----";
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] ---- ",
                      (char *)param_2);
  pCVar1 = CFastString::operator<<
                     ((CFastString *)pCVar1,(CPlugFileGpuBuilder *)pcVar3,(char *)ppCVar4);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,unaff_EBX,unaff_retaddr);
  CFastString::operator<<((CFastString *)pCVar1,(CPlugFileGpuBuilder *)param_1,(char *)param_2);
  CClassicLog::AddLogStringInFile();
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  pCVar2 = (CPlugFileGpuBuilder *)&DAT_00b2ce70;
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] MemoryLoad = ",
                      *(char **)(in_stack_00000014 + 4));
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,pCVar2,(char *)&lpOutputString_00b2bcc4);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,unaff_ESI,in_stack_0000000c);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_00000010,in_stack_00000014);
  CClassicLog::AddLogStringInFile();
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] TotalPhys = ",
                      (char *)(*(uint *)(in_stack_00000014 + 8) + 0xfffff >> 0x14 |
                              (*(int *)(in_stack_00000014 + 0xc) +
                              (uint)(0xfff00000 < *(uint *)(in_stack_00000014 + 8))) * 0x1000));
  pCVar1 = CFastString::operator<<
                     ((CFastString *)pCVar1,(CPlugFileGpuBuilder *)&DAT_00b2edec,
                      (char *)&lpOutputString_00b2bcc4);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,in_stack_00000018,in_stack_0000001c);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_00000020,in_stack_00000024);
  CClassicLog::AddLogStringInFile();
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] AvailPhys = ",
                      (char *)(*(uint *)(in_stack_00000014 + 0x10) + 0xfffff >> 0x14 |
                              (*(int *)(in_stack_00000014 + 0x14) +
                              (uint)(0xfff00000 < *(uint *)(in_stack_00000014 + 0x10))) * 0x1000));
  pCVar1 = CFastString::operator<<
                     ((CFastString *)pCVar1,(CPlugFileGpuBuilder *)&DAT_00b2edec,
                      (char *)&lpOutputString_00b2bcc4);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,in_stack_00000028,in_stack_0000002c);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_00000030,in_stack_00000034);
  CClassicLog::AddLogStringInFile();
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] TotalPageFile = ",
                      (char *)(*(uint *)(in_stack_00000014 + 0x18) + 0xfffff >> 0x14 |
                              (*(int *)(in_stack_00000014 + 0x1c) +
                              (uint)(0xfff00000 < *(uint *)(in_stack_00000014 + 0x18))) * 0x1000));
  pCVar1 = CFastString::operator<<
                     ((CFastString *)pCVar1,(CPlugFileGpuBuilder *)&DAT_00b2edec,
                      (char *)&lpOutputString_00b2bcc4);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,in_stack_00000038,in_stack_0000003c);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_00000040,in_stack_00000044);
  CClassicLog::AddLogStringInFile();
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] AvailPageFile = ",
                      (char *)(*(uint *)(in_stack_00000014 + 0x20) + 0xfffff >> 0x14 |
                              (*(int *)(in_stack_00000014 + 0x24) +
                              (uint)(0xfff00000 < *(uint *)(in_stack_00000014 + 0x20))) * 0x1000));
  pCVar1 = CFastString::operator<<
                     ((CFastString *)pCVar1,(CPlugFileGpuBuilder *)&DAT_00b2edec,
                      (char *)&lpOutputString_00b2bcc4);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,in_stack_00000048,in_stack_0000004c);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_00000050,in_stack_00000054);
  CClassicLog::AddLogStringInFile();
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] TotalVirtual = ",
                      (char *)(*(uint *)(in_stack_00000014 + 0x28) + 0xfffff >> 0x14 |
                              (*(int *)(in_stack_00000014 + 0x2c) +
                              (uint)(0xfff00000 < *(uint *)(in_stack_00000014 + 0x28))) * 0x1000));
  pCVar1 = CFastString::operator<<
                     ((CFastString *)pCVar1,(CPlugFileGpuBuilder *)&DAT_00b2edec,
                      (char *)&lpOutputString_00b2bcc4);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,in_stack_00000058,in_stack_0000005c);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_00000060,in_stack_00000064);
  CClassicLog::AddLogStringInFile();
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] AvailVirtual = ",
                      (char *)(*(uint *)(in_stack_00000014 + 0x30) + 0xfffff >> 0x14 |
                              (*(int *)(in_stack_00000014 + 0x34) +
                              (uint)(0xfff00000 < *(uint *)(in_stack_00000014 + 0x30))) * 0x1000));
  pCVar1 = CFastString::operator<<
                     ((CFastString *)pCVar1,(CPlugFileGpuBuilder *)&DAT_00b2edec,
                      (char *)&lpOutputString_00b2bcc4);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,in_stack_00000068,in_stack_0000006c);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_00000070,in_stack_00000074);
  CClassicLog::AddLogStringInFile();
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,
                      (CPlugFileGpuBuilder *)"[Sys] ----------------------------",
                      (char *)&lpOutputString_00b2bcc4);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_0000007c,in_stack_00000080);
  CClassicLog::AddLogStringInFile();
  return;
}
}

// =================================================
// Function: LogSocketError
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl LogSocketError(int param_1)
{
{
  char acStack_184 [128];
  char acStack_104 [256];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)acStack_184;
  if (param_1 == 0) {
    param_1 = Ordinal_111();
  }
  if (param_1 < 0x2afa) {
    if (param_1 == 0x2af9) goto LAB_00506818;
    switch(param_1) {
    case 0x2714:
      break;
    default:
      goto switchD_005065ac_caseD_2715;
    case 0x2719:
      break;
    case 0x271d:
      break;
    case 0x271e:
      break;
    case 0x2726:
      break;
    case 0x2728:
      break;
    case 0x2733:
      break;
    case 0x2734:
      break;
    case 0x2735:
      break;
    case 0x2736:
      break;
    case 0x2737:
      break;
    case 0x2738:
      break;
    case 0x2739:
      break;
    case 0x273a:
      break;
    case 0x273b:
      break;
    case 0x273c:
      break;
    case 0x273d:
      break;
    case 0x273e:
      break;
    case 0x273f:
      break;
    case 0x2740:
      break;
    case 0x2741:
      break;
    case 0x2742:
      break;
    case 0x2743:
      break;
    case 0x2744:
      break;
    case 0x2745:
      break;
    case 0x2746:
      break;
    case 0x2747:
      break;
    case 0x2748:
      break;
    case 0x2749:
      break;
    case 0x274a:
      break;
    case 0x274b:
      break;
    case 0x274c:
      break;
    case 0x274d:
      break;
    case 0x274e:
      break;
    case 0x274f:
      break;
    case 0x2750:
      break;
    case 0x2751:
      break;
    case 0x2752:
      break;
    case 0x2753:
      break;
    case 0x2754:
      break;
    case 0x2755:
      break;
    case 0x2756:
      break;
    case 0x2757:
      break;
    case 0x276b:
      break;
    case 0x276c:
      break;
    case 0x276d:
      break;
    case 0x2775:
      break;
    case 0x2776:
      break;
    case 0x2777:
      break;
    case 0x2778:
      break;
    case 0x2779:
      break;
    case 0x277b:
      break;
    case 0x277c:
      break;
    case 0x277d:
      break;
    case 0x277e:
      break;
    case 0x277f:
      break;
    case 0x2780:
    }
  }
  else {
    if (((param_1 == 0x2afa) || (param_1 == 0x2afb)) || (param_1 == 0x2afc)) goto LAB_00506818;
switchD_005065ac_caseD_2715:
    sprintf_s<128>(acStack_184,&DAT_00b50f78);
  }
LAB_00506818:
  sprintf_s<256>(acStack_104,"WinSock error %s\n");
  return;
}
}

// =================================================
// Function: MainGridCreate
// =================================================
CControlGrid * __cdecl MainGridCreate(SBuildPageParams *param_1)
{
{
  CControlGrid *pCVar1;
  CControlGrid *this;
  CControlGrid *extraout_EAX;
  CMwNod *extraout_EAX_00;
  CMwNod *extraout_EAX_01;
  int unaff_EBX;
  CMwNod *unaff_ESI;
  CMwNod *pCVar2;
  CControlLayout *unaff_EDI;
  CControlLayout *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ac08a1;
  local_c = ExceptionList;
  pCVar1 = (CControlGrid *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  this = operator_new(0x1c0);
  pCVar2 = (CMwNod *)0x0;
  local_4 = 0;
  if (this == (CControlGrid *)0x0) {
    pCVar1 = (CControlGrid *)0x0;
  }
  else {
    CControlGrid::CControlGrid(this,pCVar1);
    pCVar1 = extraout_EAX;
  }
  (**(code **)(*(int *)pCVar1 + 0x4c))();
  if (*(int *)(unaff_EBX + 0x28) == 0) {
    local_c = operator_new(0x2c);
    if (local_c != (CControlLayout *)0x0) {
      CControlLayout::CControlLayout(local_c,unaff_EDI);
      pCVar2 = extraout_EAX_00;
    }
    (**(code **)(*(int *)pCVar2 + 0x4c))();
    *(undefined4 *)(pCVar2 + 0x1c) = 0;
    *(undefined4 *)(pCVar2 + 0x20) = 0;
    *(undefined4 *)(pCVar2 + 0x14) = *(undefined4 *)(unaff_EBX + 0x3c);
    *(undefined4 *)(pCVar2 + 0x18) = 1;
    if (pCVar2 != *(CMwNod **)(pCVar1 + 0x8c)) {
      CMwNod::MwAddRef(pCVar2,(CMwNod *)unaff_EDI);
      if (*(CMwNod **)(pCVar1 + 0x8c) != (CMwNod *)0x0) {
        unaff_EDI = (CControlLayout *)0x71de8a;
        CMwNod::MwRelease(*(CMwNod **)(pCVar1 + 0x8c),unaff_ESI);
      }
      *(CMwNod **)(pCVar1 + 0x8c) = pCVar2;
    }
    local_c = operator_new(0x2c);
    if (local_c == (CControlLayout *)0x0) {
      pCVar2 = (CMwNod *)0x0;
    }
    else {
      CControlLayout::CControlLayout(local_c,unaff_EDI);
      pCVar2 = extraout_EAX_01;
    }
    (**(code **)(*(int *)pCVar2 + 0x4c))();
    *(undefined4 *)(pCVar2 + 0x1c) = 0;
    *(undefined4 *)(pCVar2 + 0x14) = 1;
    *(undefined4 *)(pCVar2 + 0x20) = 0;
    *(undefined4 *)(pCVar2 + 0x18) = 1;
    if (pCVar2 != *(CMwNod **)(pCVar1 + 0x180)) {
      CMwNod::MwAddRef(pCVar2,(CMwNod *)unaff_EDI);
      if (*(CMwNod **)(pCVar1 + 0x180) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(pCVar1 + 0x180),(CMwNod *)0x71def4);
      }
      *(CMwNod **)(pCVar1 + 0x180) = pCVar2;
    }
  }
  ExceptionList = puStack_8;
  return pCVar1;
}
}

// =================================================
// Function: Manialink_GetClientUpdateIdForSubPage
// =================================================
uchar * __cdecl
Manialink_GetClientUpdateIdForSubPage
          (CFastBuffer<struct_CGameNetPlayerInfo::SPagesOnClient> *param_1,CMwId *param_2,
          int param_3)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  SLoadedLight *pSVar4;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  void *unaff_EDI;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(unaff_EDI,unaff_ESI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](unaff_EDI,pCVar5,(ulong)unaff_EBP);
      if (*(int *)pSVar3 == iVar1) {
        pSVar3 = CFastBuffer<struct_SFastCat>::operator[](unaff_EDI,pCVar5,unaff_EBX);
        return (uchar *)(pSVar3 + 4);
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  if (param_3 != 0) {
    pSVar4 = CFastBuffer<struct_CGameNetPlayerInfo::SPagesOnClient>::AddNewElem(unaff_EDI,unaff_EBP)
    ;
    *(undefined4 *)pSVar4 = *(undefined4 *)param_3;
    pSVar4[4] = (SLoadedLight)0x0;
    return (uchar *)(pSVar4 + 4);
  }
  return &DAT_00d696e0;
}
}

// =================================================
// Function: MaterialCreateFromSystemData
// =================================================
CPlugMaterial * __cdecl MaterialCreateFromSystemData(CSystemData *param_1)
{
{
  CMwNod *this;
  CPlugShaderApply *this_00;
  CPlugShaderApply *extraout_EAX;
  CPlugMaterial *extraout_EAX_00;
  CSystemData *in_ECX;
  ulong *unaff_ESI;
  CSystemFid *unaff_EDI;
  GxColor *unaff_retaddr;
  int in_stack_00000008;
  EGxBlendFactor in_stack_0000000c;
  CPlugShader *pCVar1;
  undefined4 uStack00000014;
  CPlugMaterial *pCStack0000001c;
  void *in_stack_00000020;
  void *in_stack_00000024;
  undefined4 uStack00000028;
  void *pvVar2;
  CPlugShaderApply *pCVar3;
  ulong uVar4;
  
  uVar4 = 0xffffffff;
  pCVar3 = (CPlugShaderApply *)&LAB_00ac0856;
  pvVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  this = CSystemData::Get(in_ECX,DAT_00d6b13c,(CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xffffffe8),
                          unaff_EDI,unaff_ESI);
  CPlugBitmap::SetDefaultTexAddress
            ((CPlugBitmap *)this,(CPlugBitmap *)0x2,2,0,(EGxTexAddress)in_ECX);
  *(uint *)(this + 0x4c) = *(uint *)(this + 0x4c) & 0xffdfffff;
  *(uint *)(this + 0x50) = *(uint *)(this + 0x50) | 2;
  CPlugBitmap::SetMipLevelSkipCountMax((CPlugBitmap *)this,(CPlugBitmap *)0x1,(ulong)pvVar2);
  this_00 = operator_new(0xa8);
  pCVar1 = (CPlugShader *)0x0;
  if (this_00 == (CPlugShaderApply *)0x0) {
    pCVar3 = (CPlugShaderApply *)0x0;
  }
  else {
    CPlugShaderApply::CPlugShaderApply(this_00,pCVar3);
    pCVar3 = extraout_EAX;
  }
  uStack00000014 = 0xffffffff;
  CPlugShaderApply::AddTextureApply(pCVar3,(CPlugShaderApply *)this,(CPlugBitmap *)0x1,0,uVar4);
  CPlugShaderGeneric::SetVertexColor
            ((CPlugShaderGeneric *)pCVar3,(CPlugShaderGeneric *)0x1,0,unaff_retaddr);
  CPlugShader::SetReceiverShadowGroupMask((CPlugShader *)pCVar3,(CPlugShader *)0x0,(ulong)this_00);
  CHmsItem::SetIsForcePointDynamicCollisionResponse
            ((CHmsItem *)pCVar3,(CHmsItem *)0x0,in_stack_00000008);
  CPlugShaderApply::SetBlending(pCVar3,(CPlugShaderPass *)&DAT_00000004,5,in_stack_0000000c);
  pCStack0000001c = operator_new(0x38);
  uStack00000028 = 1;
  if (pCStack0000001c != (CPlugMaterial *)0x0) {
    CPlugMaterial::CPlugMaterial(pCStack0000001c,(CPlugMaterial *)pCVar3,pCVar1);
    ExceptionList = in_stack_00000024;
    return extraout_EAX_00;
  }
  ExceptionList = in_stack_00000020;
  return (CPlugMaterial *)0x0;
}
}

// =================================================
// Function: MediaDataFindOrAdd
// =================================================
CSystemData * __cdecl
MediaDataFindOrAdd(CFastString *param_1,CFastString *param_2,SBuildPageParams *param_3)
{
{
  CSystemData *this;
  CSystemData *extraout_EAX;
  void *pvVar1;
  CFastString *unaff_ESI;
  CFastString *unaff_EDI;
  CFastString *in_stack_00000010;
  CFastString *in_stack_ffffffe8;
  CSystemData *in_stack_ffffffec;
  CSystemData *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ac0963;
  local_c = ExceptionList;
  if ((*(int *)(unaff_EDI + 0x10) != 0) && (*(int *)param_1 != 0)) {
    ExceptionList = &local_c;
    CFastString::CFastString
              ((CFastString *)&stack0xffffffec,param_1,
               (char *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
    CControlTools::FixLocalUrl(unaff_EDI,(CFastStringInt *)&local_10);
    this = CGameNetwork::FindManiaNetData
                     (*(CGameNetwork **)(unaff_EDI + 0x10),(CGameNetwork *)&local_10,unaff_ESI);
    if (this == (CSystemData *)0x0) {
      local_10 = operator_new(0x28);
      if (local_10 == (CSystemData *)0x0) {
        this = (CSystemData *)0x0;
      }
      else {
        CSystemData::CSystemData(local_10,(CSystemData *)in_stack_ffffffe8);
        this = extraout_EAX;
      }
      param_1 = (CFastString *)((uint)param_1 & 0xffffff00);
      CSystemData::SetUrl(this,(CSystemData *)&local_c,in_stack_00000010,in_stack_ffffffe8);
      CGameNetwork::AddManiaNetData
                (*(CGameNetwork **)(unaff_EDI + 0x10),(CGameNetwork *)this,in_stack_ffffffec);
    }
    else if (*(int *)(unaff_EDI + 0x2c) == 0) {
      CSystemData::SetUpToDate(this,(CSystemData *)0x0,(int)in_stack_ffffffe8);
      CSystemData::Set(this,(CMwCmdScriptVarBool *)0x0,(int)in_stack_ffffffec);
    }
    if (PTR_DAT_00bbf7d8 != (undefined *)0x0) {
      pvVar1 = (void *)0xffffffff;
      if ((bRamffffffff & 0x80) != 0) {
        pvVar1 = (void *)0xfffffffc;
      }
      operator_delete__(pvVar1);
    }
    ExceptionList = param_1;
    return this;
  }
  return (CSystemData *)0x0;
}
}

// =================================================
// Function: Min
// =================================================
void __thiscall Min(void *this,GmVector3<unsigned_long> *param_1,GmVector3<unsigned_long> *param_2)
{
{
  return;
}
}

// =================================================
// Function: MoveVertexFrontSail
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
MoveVertexFrontSail(GxVertex *param_1,float param_2,float param_3,float param_4,float param_5,
                   float param_6,float param_7)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float *unaff_ESI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar4;
  
  __CIcos();
  fVar1 = param_2 * param_2 * param_2;
  __CIsin();
  fVar2 = (float)_DAT_00baac10;
  *unaff_ESI = param_4 * (param_2 * fVar1 - param_2 * fVar2) * (float)_DAT_00b313b8 +
               (float)extraout_ST0_00 * param_6 * param_5 * param_2;
  fVar3 = _DAT_00b2c060;
  if (-1 < (int)unaff_ESI[3]) {
    fVar3 = 1.0;
  }
  unaff_ESI[3] = fVar3;
  unaff_ESI[4] = 0.0;
  unaff_ESI[5] = fVar3 * (float)param_1 *
                         ((param_4 + param_4) * (fVar1 - fVar2) +
                         (float)extraout_ST0 * param_5 * param_6);
  if (unaff_ESI[5] * unaff_ESI[5] + unaff_ESI[3] * unaff_ESI[3] + unaff_ESI[4] * unaff_ESI[4] <=
      _DAT_00d0f8c8) {
    return;
  }
  fVar4 = (float10)func_0x009c1b40();
  fVar1 = 1.0 / (float)fVar4;
  unaff_ESI[3] = fVar1 * unaff_ESI[3];
  unaff_ESI[4] = unaff_ESI[4] * fVar1;
  unaff_ESI[5] = fVar1 * unaff_ESI[5];
  return;
}
}

// =================================================
// Function: MultiStateAddLinkVisual
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
MultiStateAddLinkVisual
          (ulong param_1,CMotionParticleType *param_2,SPart *param_3,SPart *param_4,
          CPlugVisual *param_5,GmVec3 *param_6,GmVec3 *param_7)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  SLoadedLight *pSVar10;
  SCasterCat *pSVar11;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBX;
  CPlugVisual *this;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  int unaff_retaddr;
  int in_stack_00000038;
  float *in_stack_00000040;
  float *in_stack_00000044;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffffd4;
  ulong in_stack_ffffffd8;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  iVar5 = *(int *)(param_2 + 0x24);
  if (((-1 < iVar5) && (2 < iVar5)) && (iVar5 == 3)) {
    fVar1 = *(float *)(param_3 + 0x2c);
    fVar12 = *(float *)(param_4 + 0x14);
    fVar13 = *(float *)(param_4 + 0x20);
    fVar14 = *(float *)(param_4 + 0x2c);
    if (*(float *)(param_3 + 0x20) * fVar13 + *(float *)(param_3 + 0x14) * fVar12 + fVar1 * fVar14 <
        _DAT_00c418e0) {
      fVar12 = -fVar12;
      fVar13 = -fVar13;
      fVar14 = -fVar14;
    }
    fVar2 = *(float *)(param_3 + 0x50);
    this = param_5 + 0x78;
    fVar15 = fVar2 * *(float *)(param_3 + 0x14);
    fVar3 = *(float *)(param_4 + 0x50);
    fVar8 = fVar3 * fVar12;
    fVar6 = fVar13 * fVar3;
    fVar7 = fVar3 * fVar14;
    pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EBP);
    pSVar10 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(this,unaff_EBX);
    *(float *)pSVar10 = fVar1 * fVar2 + *(float *)(param_3 + 0x38);
    *(float *)(pSVar10 + 4) = *(float *)(param_3 + 0x3c) + fVar8;
    *(float *)(pSVar10 + 8) = *(float *)(param_3 + 0x40) + fVar6;
    pSVar10 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(this,unaff_EDI);
    *(float *)pSVar10 = *(float *)(param_3 + 0x38) - fVar8;
    *(float *)(pSVar10 + 4) = *(float *)(param_3 + 0x3c) - fVar6;
    *(float *)(pSVar10 + 8) = *(float *)(param_3 + 0x40) - fVar7;
    pSVar10 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(this,unaff_ESI);
    *(float *)pSVar10 = *(float *)(param_4 + 0x38) + (float)param_1;
    *(float *)(pSVar10 + 4) = *(float *)(param_4 + 0x3c) + fVar3;
    *(float *)(pSVar10 + 8) = *(float *)(param_4 + 0x40) + (float)param_3;
    pSVar10 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(this,in_stack_ffffffd4);
    *(float *)pSVar10 = *(float *)(param_4 + 0x38) - fVar3;
    *(float *)(pSVar10 + 4) = *(float *)(param_4 + 0x3c) - (float)param_3;
    *(float *)(pSVar10 + 8) = *(float *)(param_4 + 0x40) - (float)param_4;
    pSVar11 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[](this,pCVar9,in_stack_ffffffd8);
    *(undefined4 *)(pSVar11 + 0x18) = *(undefined4 *)(param_3 + 0x5c);
    *(undefined4 *)(pSVar11 + 0x1c) = *(undefined4 *)(param_3 + 0x60);
    *(undefined4 *)(pSVar11 + 0x20) = *(undefined4 *)(param_3 + 100);
    pSVar11 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[](this,pCVar9 + 1,(ulong)fVar12);
    *(undefined4 *)(pSVar11 + 0x18) = *(undefined4 *)(param_3 + 0x5c);
    *(undefined4 *)(pSVar11 + 0x1c) = *(undefined4 *)(param_3 + 0x60);
    *(undefined4 *)(pSVar11 + 0x20) = *(undefined4 *)(param_3 + 100);
    pSVar11 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[](this,pCVar9 + 2,(ulong)fVar13);
    *(undefined4 *)(pSVar11 + 0x18) = *(undefined4 *)(param_4 + 0x5c);
    *(undefined4 *)(pSVar11 + 0x1c) = *(undefined4 *)(param_4 + 0x60);
    *(undefined4 *)(pSVar11 + 0x20) = *(undefined4 *)(param_4 + 100);
    pSVar11 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[](this,pCVar9 + 3,(ulong)fVar14);
    *(undefined4 *)(pSVar11 + 0x18) = *(undefined4 *)(param_4 + 0x5c);
    *(undefined4 *)(pSVar11 + 0x1c) = *(undefined4 *)(param_4 + 0x60);
    *(undefined4 *)(pSVar11 + 0x20) = *(undefined4 *)(param_4 + 100);
    pSVar11 = CFastBuffer<struct_SFastCat>::operator[]
                        ((void *)(in_stack_00000038 + 0x5c),
                         (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)fVar15);
    uVar4 = *(undefined4 *)(param_3 + 0x90);
    iVar5 = *(int *)(pSVar11 + 4);
    *(undefined4 *)(iVar5 + (int)pCVar9 * 8) = 0;
    *(undefined4 *)(iVar5 + 4 + (int)pCVar9 * 8) = uVar4;
    uVar4 = *(undefined4 *)(param_3 + 0x90);
    *(undefined4 *)(iVar5 + 8 + (int)pCVar9 * 8) = 0x3f800000;
    *(undefined4 *)(iVar5 + 0xc + (int)pCVar9 * 8) = uVar4;
    uVar4 = *(undefined4 *)(param_4 + 0x90);
    *(undefined4 *)(iVar5 + (int)fVar7 * 8) = 0;
    *(undefined4 *)(iVar5 + 4 + (int)fVar7 * 8) = uVar4;
    uVar4 = *(undefined4 *)(param_4 + 0x90);
    *(undefined4 *)(iVar5 + unaff_retaddr * 8) = 0x3f800000;
    *(undefined4 *)(iVar5 + 4 + unaff_retaddr * 8) = uVar4;
    if (*(float *)(param_3 + 0x38) < *in_stack_00000040) {
      *in_stack_00000040 = *(float *)(param_3 + 0x38);
    }
    if (*(float *)(param_3 + 0x3c) < in_stack_00000040[1]) {
      in_stack_00000040[1] = *(float *)(param_3 + 0x3c);
    }
    if (*(float *)(param_3 + 0x40) < in_stack_00000040[2]) {
      in_stack_00000040[2] = *(float *)(param_3 + 0x40);
    }
    if (*in_stack_00000044 < *(float *)(param_3 + 0x38)) {
      *in_stack_00000044 = *(float *)(param_3 + 0x38);
    }
    if (in_stack_00000044[1] < *(float *)(param_3 + 0x3c)) {
      in_stack_00000044[1] = *(float *)(param_3 + 0x3c);
    }
    if (in_stack_00000044[2] < *(float *)(param_3 + 0x40)) {
      in_stack_00000044[2] = *(float *)(param_3 + 0x40);
    }
  }
  return;
}
}

// =================================================
// Function: MwGetSchemeTimedPattern
// =================================================
EMwSchemeTimedPatterns __cdecl MwGetSchemeTimedPattern(ulong param_1)
{
{
  return (EMwSchemeTimedPatterns)(&PTR_VirtualParam_Add_00bc5ce0)[param_1];
}
}

// =================================================
// Function: MwSystemTimerDestroy
// =================================================
void __cdecl MwSystemTimerDestroy(void)
{
{
  MMRESULT MVar1;
  timecaps_tag local_8;
  
  if (DAT_00d73ab0 != 0) {
    MVar1 = timeGetDevCaps(&local_8,8);
    if (MVar1 == 0) {
      timeEndPeriod(local_8.wPeriodMin);
    }
    DAT_00d73ab0 = 0;
  }
  return;
}
}

// =================================================
// Function: MwSystemTimerInit
// =================================================
void __cdecl MwSystemTimerInit(void)
{
{
  MMRESULT MVar1;
  timecaps_tag local_8;
  
  MVar1 = timeGetDevCaps(&local_8,8);
  if (MVar1 == 0) {
    MVar1 = timeBeginPeriod(local_8.wPeriodMin);
    if (MVar1 == 0) {
      DAT_00d73ab0 = 1;
    }
  }
  return;
}
}

// =================================================
// Function: OnAccessViolation_ConcatToCrashFileName
// =================================================
void __cdecl OnAccessViolation_ConcatToCrashFileName(CFastStringInt *param_1)
{
{
  return;
}
}

// =================================================
// Function: OnCrashCheckTreeRecursive
// =================================================
void __cdecl OnCrashCheckTreeRecursive(CFastString *param_1,CPlugTree *param_2)
{
{
  CPlugFileGpuBuilder *pCVar1;
  int iVar2;
  CFastString *pCVar3;
  CPlugFileGpuBuilder *pCVar4;
  CFastString *pCVar5;
  CPlugTree *pCVar6;
  undefined *puVar7;
  char *unaff_ESI;
  char *unaff_EDI;
  char *pcVar8;
  CFastString *unaff_retaddr;
  char *pcVar9;
  CGameScoresVersion *pCVar10;
  CGameScoresVersion *pCVar11;
  CGameScoresVersion *pCVar12;
  CSystemCrashDump *pCVar13;
  undefined4 uStack_14;
  undefined *puStack_10;
  void *local_c;
  CSystemCrashDump *pCStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pCStack_8 = (CSystemCrashDump *)&LAB_00ad5438;
  local_c = ExceptionList;
  pCVar1 = (CPlugFileGpuBuilder *)(DAT_00cca150 ^ (uint)&stack0xffffffd8);
  ExceptionList = &local_c;
  iVar2 = CSystemCrashDump::IsValid((CSystemCrashDump *)&DAT_00d5546c,(CGameScoresVersion *)param_2)
  ;
  if (iVar2 != 0) {
    (**(code **)(DAT_00d5546c + 0x14))();
    pCVar10 = *(CGameScoresVersion **)(param_2 + 0x90);
    pCVar11 = *(CGameScoresVersion **)(param_2 + 0x94);
    pCVar12 = *(CGameScoresVersion **)(param_2 + 0x98);
    if ((pCVar10 != (CGameScoresVersion *)0x0) &&
       (iVar2 = CSystemCrashDump::IsValid((CSystemCrashDump *)&DAT_00d5546c,pCVar10), iVar2 == 0)) {
      pcVar9 = "!! Invalid PlugVisual pointer :";
      pCVar4 = (CPlugFileGpuBuilder *)0x85475c;
      pCVar3 = param_1;
      pCVar5 = (CFastString *)(**(code **)(DAT_00d5546c + 0x1c))();
      pCVar4 = CFastString::operator<<(pCVar5,pCVar4,(char *)pCVar3);
      CFastString::operator<<((CFastString *)pCVar4,(CPlugFileGpuBuilder *)pcVar9,(char *)pCVar10);
    }
    if ((pCVar11 != (CGameScoresVersion *)0x0) &&
       (iVar2 = CSystemCrashDump::IsValid((CSystemCrashDump *)&DAT_00d5546c,pCVar11), iVar2 == 0)) {
      pcVar9 = "!! Invalid PlugShader pointer :";
      pCVar4 = (CPlugFileGpuBuilder *)0x854798;
      pCVar3 = param_1;
      pCVar5 = (CFastString *)(**(code **)(DAT_00d5546c + 0x1c))();
      pCVar4 = CFastString::operator<<(pCVar5,pCVar4,(char *)pCVar3);
      CFastString::operator<<((CFastString *)pCVar4,(CPlugFileGpuBuilder *)pcVar9,(char *)pCVar11);
    }
    if ((pCVar12 != (CGameScoresVersion *)0x0) &&
       (iVar2 = CSystemCrashDump::IsValid((CSystemCrashDump *)&DAT_00d5546c,pCVar12), iVar2 == 0)) {
      pcVar9 = "!! Invalid PlugMaterial pointer :";
      pCVar4 = (CPlugFileGpuBuilder *)0x8547d4;
      pCVar3 = (CFastString *)(**(code **)(DAT_00d5546c + 0x1c))();
      pCVar4 = CFastString::operator<<(pCVar3,pCVar4,(char *)param_1);
      CFastString::operator<<((CFastString *)pCVar4,(CPlugFileGpuBuilder *)pcVar9,(char *)pCVar12);
    }
    pcVar9 = (char *)(**(code **)(*(int *)param_2 + 0x7c))();
    pcVar8 = (char *)0x0;
    if (pcVar9 != (char *)0x0) {
      do {
        uStack_14 = 0;
        uStack_4 = 0;
        puStack_10 = PTR_DAT_00bbf7d8;
        pCVar4 = CFastString::operator<<
                           ((CFastString *)&uStack_14,(CPlugFileGpuBuilder *)&DAT_00bade00,pcVar8);
        pCVar13 = (CSystemCrashDump *)0x854825;
        CFastString::operator<<((CFastString *)pCVar4,pCVar1,unaff_EDI);
        pCVar1 = (CPlugFileGpuBuilder *)0x854834;
        CSystemCrashDump::ContextPush((CSystemCrashDump *)&DAT_00d5546c,pCStack_8,unaff_ESI);
        unaff_EDI = (char *)0x854841;
        unaff_ESI = pcVar8;
        pCVar6 = (CPlugTree *)(**(code **)(*(int *)param_2 + 0x80))();
        OnCrashCheckTreeRecursive(unaff_retaddr,pCVar6);
        CSystemCrashDump::ContextPop((CSystemCrashDump *)&DAT_00d5546c,pCVar13);
        uStack_4 = 0xffffffff;
        if (puStack_10 != PTR_DAT_00bbf7d8) {
          puVar7 = puStack_10 + -1;
          if ((puStack_10[-1] & 0x80) != 0) {
            puVar7 = puStack_10 + -4;
          }
          operator_delete__(puVar7);
          uStack_14 = 0;
          puStack_10 = PTR_DAT_00bbf7d8;
        }
        pcVar8 = pcVar8 + 1;
      } while (pcVar8 < pcVar9);
    }
    (**(code **)(DAT_00d5546c + 0x18))();
    ExceptionList = local_c;
    return;
  }
  pcVar9 = "!! Invalid PlugTree pointer :";
  pCVar3 = (CFastString *)(**(code **)(DAT_00d5546c + 0x1c))();
  pCVar4 = CFastString::operator<<(pCVar3,(CPlugFileGpuBuilder *)param_1,pcVar9);
  CFastString::operator<<((CFastString *)pCVar4,(CPlugFileGpuBuilder *)param_2,(char *)pCVar1);
  ExceptionList = pCStack_8;
  return;
}
}

// =================================================
// Function: OrderWindowedValues
// =================================================
void __cdecl OrderWindowedValues(float *param_1,float *param_2,float param_3)
{
{
  float *pfVar1;
  
  pfVar1 = param_1;
  if (*param_1 <= *param_2) {
    pfVar1 = param_2;
  }
  if (*param_2 < *param_1) {
    param_1 = param_2;
  }
  if ((*param_1 + param_3) - *pfVar1 <= *pfVar1 - *param_1) {
    *param_1 = *param_1 + param_3;
    return;
  }
  return;
}
}

// =================================================
// Function: PackList_InstallFromFile_CryptSfNormal
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
PackList_InstallFromFile_CryptSfNormal
          (uchar param_1,uchar param_2,ulong param_3,ulong param_4,SPackListElem *param_5,
          SNat128 param_6,CClassicBufferMemory *param_7,char *param_8,int param_9,
          CSystemFids *param_10,CSystemFids *param_11,CSystemFids *param_12,
          CFastBuffer<class_CPlugFilePack*> *param_13,int param_14)
{
{
  CSystemFids CVar1;
  SPackListElem SVar2;
  CClassicBuffer CVar3;
  SStringParam *pSVar4;
  CClassicBuffer *pCVar5;
  CClassicBuffer *pCVar6;
  CSystemFids *pCVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  SCasterCat *pSVar11;
  undefined *puVar12;
  CClassicBuffer CVar13;
  uint uVar14;
  int iVar15;
  EFindWay unaff_EBP;
  int unaff_ESI;
  SPackListElem *pSVar16;
  SNat128 *unaff_EDI;
  uint uVar17;
  undefined3 in_stack_00000019;
  int in_stack_0000003c;
  CSystemFids *in_stack_00000040;
  int in_stack_00000044;
  uint local_190;
  SPackListElem *local_18c;
  SPackListElem *local_188;
  undefined4 local_184;
  undefined *local_180;
  uint local_17c;
  CSystemFids *local_178;
  uint local_174;
  int local_170;
  uint local_16c;
  CSystemFids *local_168;
  int local_164;
  char *local_160;
  undefined4 local_15c;
  undefined4 local_158;
  int local_154;
  int local_150;
  CClassicBufferMemory *local_14c;
  char *local_148;
  int local_144;
  byte local_130 [16];
  byte local_120 [16];
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined1 uStack_f0;
  CClassicBuffer local_ec;
  undefined4 local_eb;
  undefined4 local_e7;
  undefined4 local_e3;
  undefined4 local_df;
  undefined4 local_db;
  undefined4 local_d7;
  undefined4 local_d3;
  undefined4 local_cf;
  CClassicBuffer local_c8 [24];
  CClassicBuffer local_b0;
  CClassicBuffer local_af [31];
  CClassicBuffer local_90 [128];
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad656d;
  local_c = ExceptionList;
  local_10 = DAT_00cca150 ^ (uint)&local_190;
  pSVar4 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xfffffe60);
  ExceptionList = &local_c;
  local_188 = param_5;
  local_164 = param_14;
  local_170 = in_stack_0000003c;
  local_168 = (CSystemFids *)param_13;
  local_178 = in_stack_00000040;
  local_190 = 0;
  sprintf_s<32>((char *)&local_b0,"%u");
  local_158 = *(undefined4 *)(param_10 + 0xc);
  local_154 = *(int *)(param_10 + 0x10) + -0x10;
  local_90[0] = (CClassicBuffer)0x0;
  pCVar5 = local_90;
  if (DAT_00d127f4 != (CClassicBuffer)0x0) {
    iVar15 = (int)&DAT_00d127f5 - (int)pCVar5;
    CVar13 = DAT_00d127f4;
    do {
      *pCVar5 = CVar13;
      CVar13 = pCVar5[iVar15];
      pCVar5 = pCVar5 + 1;
    } while (CVar13 != (CClassicBuffer)0x0);
  }
  *pCVar5 = (CClassicBuffer)0x0;
  pCVar5 = &local_b0;
  pCVar6 = local_90;
  CVar13 = local_90[0];
  while (CVar13 != (CClassicBuffer)0x0) {
    pCVar6 = pCVar6 + 1;
    CVar13 = *pCVar6;
  }
  uVar17 = 0;
  CVar13 = local_b0;
  while (CVar13 != (CClassicBuffer)0x0) {
    pCVar5 = pCVar5 + 1;
    *pCVar6 = CVar13;
    pCVar6 = pCVar6 + 1;
    CVar13 = *pCVar5;
  }
  *pCVar6 = (CClassicBuffer)0x0;
  ComputeMD5OnStr((char *)pSVar4,unaff_EDI);
  _memset(local_90,0x78,0x80);
  local_150 = 0;
  local_14c = (CClassicBufferMemory *)0x0;
  local_148 = (char *)0x0;
  local_144 = 0;
  CFastAlgo::ComputeHMAC_MD5_Digest((SHMAC_MD5_Data *)&local_158);
  if ((((local_150 == _param_6) && (local_14c == param_7)) && (local_148 == param_8)) &&
     (local_144 == param_9)) {
    pCVar7 = param_11;
    do {
      CVar1 = *pCVar7;
      pCVar7 = pCVar7 + 1;
    } while (CVar1 != (CSystemFids)0x0);
    if ((uint)((int)pCVar7 - (int)(param_11 + 1)) < 0x18) {
      pCVar7 = param_11;
      do {
        CVar1 = *pCVar7;
        pCVar7 = pCVar7 + 1;
      } while (CVar1 != (CSystemFids)0x0);
      if (pCVar7 != param_11 + 1) {
        do {
          iVar15 = _tolower((int)(char)(local_c8 + uVar17)[(int)param_11 - (int)local_c8]);
          local_c8[uVar17] = SUB41(iVar15,0);
          uVar17 = uVar17 + 1;
          pCVar7 = param_11;
          do {
            CVar1 = *pCVar7;
            pCVar7 = pCVar7 + 1;
          } while (CVar1 != (CSystemFids)0x0);
        } while (uVar17 < (uint)((int)pCVar7 - (int)(param_11 + 1)));
      }
      pCVar7 = param_11 + 1;
      do {
        CVar1 = *param_11;
        param_11 = param_11 + 1;
      } while (CVar1 != (CSystemFids)0x0);
      param_11[(int)(local_c8 + -(int)pCVar7)] = (CSystemFids)0x0;
      pCVar5 = local_c8;
      do {
        CVar13 = *pCVar5;
        pCVar5 = pCVar5 + 1;
      } while (CVar13 != (CClassicBuffer)0x0);
      uVar8 = CFastAlgo::ComputeCrc32(local_c8,(int)pCVar5 - (int)(local_c8 + 1));
      local_90[0] = (CClassicBuffer)0x0;
      local_16c = (uint)(uVar8 == param_3);
      pCVar5 = local_90;
      if (DAT_00d12818 != (CClassicBuffer)0x0) {
        iVar15 = (int)&DAT_00d12819 - (int)pCVar5;
        CVar13 = DAT_00d12818;
        do {
          *pCVar5 = CVar13;
          CVar13 = pCVar5[iVar15];
          pCVar5 = pCVar5 + 1;
        } while (CVar13 != (CClassicBuffer)0x0);
      }
      *pCVar5 = (CClassicBuffer)0x0;
      pCVar5 = &local_b0;
      pCVar6 = local_90;
      CVar13 = local_90[0];
      while (CVar3 = local_b0, CVar13 != (CClassicBuffer)0x0) {
        pCVar6 = pCVar6 + 1;
        CVar13 = *pCVar6;
      }
      while (CVar3 != (CClassicBuffer)0x0) {
        pCVar5 = pCVar5 + 1;
        *pCVar6 = CVar3;
        pCVar6 = pCVar6 + 1;
        CVar3 = *pCVar5;
      }
      *pCVar6 = (CClassicBuffer)0x0;
      ComputeMD5OnStr((char *)pSVar4,unaff_EDI);
      _memset(local_90,0x78,0x80);
      local_eb = 0;
      local_e7 = 0;
      local_e3 = 0;
      local_df = 0;
      local_db = 0;
      local_d7 = 0;
      local_d3 = 0;
      local_cf = 0;
      local_110 = 0;
      uStack_10c = 0;
      uStack_108 = 0;
      uStack_104 = 0;
      uStack_100 = 0;
      uStack_fc = 0;
      uStack_f8 = 0;
      uStack_f4 = 0;
      uStack_f0 = 0;
      local_ec = (CClassicBuffer)0x0;
      uVar17 = (uint)param_2;
      pSVar16 = local_188;
      while (local_188 = (SPackListElem *)uVar17, local_188 != (SPackListElem *)0x0) {
        SVar2 = *pSVar16;
        uVar17 = (uint)(byte)SVar2;
        local_17c = uVar17 & 4;
        local_174 = uVar17 & 0x20;
        local_18c = pSVar16;
        if ((((local_16c != 0) || (((byte)SVar2 & 1) == 0)) &&
            (((param_12 != (CSystemFids *)0x0 ||
              ((((byte)SVar2 & 0x10) != 0 || (((byte)SVar2 & 8) != 0)))) || (((byte)SVar2 & 4) != 0)
             ))) && ((in_stack_00000044 == 0 || (((byte)SVar2 & 8) != 0)))) {
          uVar14 = (uint)(byte)pSVar16[1];
          uVar10 = 0;
          if (uVar14 != 0) {
            do {
              uVar9 = uVar10 + 1;
              (&local_ec)[uVar10] =
                   (CClassicBuffer)(local_130[uVar10 & 0xf] ^ (byte)pSVar16[uVar10 + 2]);
              uVar10 = uVar9;
            } while (uVar9 < uVar14);
          }
          (&local_ec)[uVar14] = (CClassicBuffer)0x0;
          local_90[0] = (CClassicBuffer)0x0;
          pCVar5 = local_90;
          if (local_ec != (CClassicBuffer)0x0) {
            CVar13 = local_ec;
            do {
              *pCVar5 = CVar13;
              CVar13 = pCVar5[(int)&local_eb - (int)local_90];
              pCVar5 = pCVar5 + 1;
            } while (CVar13 != (CClassicBuffer)0x0);
          }
          *pCVar5 = (CClassicBuffer)0x0;
          pCVar5 = &local_b0;
          pCVar6 = local_90;
          CVar13 = local_90[0];
          while (CVar3 = local_b0, CVar13 != (CClassicBuffer)0x0) {
            pCVar6 = pCVar6 + 1;
            CVar13 = *pCVar6;
          }
          while (CVar3 != (CClassicBuffer)0x0) {
            pCVar5 = pCVar5 + 1;
            *pCVar6 = CVar3;
            pCVar6 = pCVar6 + 1;
            CVar3 = *pCVar5;
          }
          *pCVar6 = (CClassicBuffer)0x0;
          pCVar5 = local_90;
          if (((byte)SVar2 & 1) == 0) {
            pCVar6 = &DAT_00d127ac;
            CVar13 = local_90[0];
            while (CVar3 = DAT_00d127ac, CVar13 != (CClassicBuffer)0x0) {
              pCVar5 = pCVar5 + 1;
              CVar13 = *pCVar5;
            }
            while (CVar3 != (CClassicBuffer)0x0) {
              pCVar6 = pCVar6 + 1;
              *pCVar5 = CVar3;
              pCVar5 = pCVar5 + 1;
              CVar3 = *pCVar6;
            }
          }
          else {
            pCVar6 = &DAT_00d127d0;
            CVar13 = local_90[0];
            while (CVar3 = DAT_00d127d0, CVar13 != (CClassicBuffer)0x0) {
              pCVar5 = pCVar5 + 1;
              CVar13 = *pCVar5;
            }
            while (CVar3 != (CClassicBuffer)0x0) {
              pCVar6 = pCVar6 + 1;
              *pCVar5 = CVar3;
              pCVar5 = pCVar5 + 1;
              CVar3 = *pCVar6;
            }
            *pCVar5 = (CClassicBuffer)0x0;
            pCVar6 = local_c8;
            pCVar5 = local_90;
            CVar13 = local_90[0];
            while (CVar3 = local_c8[0], CVar13 != (CClassicBuffer)0x0) {
              pCVar5 = pCVar5 + 1;
              CVar13 = *pCVar5;
            }
            while (CVar3 != (CClassicBuffer)0x0) {
              pCVar6 = pCVar6 + 1;
              *pCVar5 = CVar3;
              pCVar5 = pCVar5 + 1;
              CVar3 = *pCVar6;
            }
          }
          *pCVar5 = (CClassicBuffer)0x0;
          ComputeMD5OnStr((char *)pSVar4,unaff_EDI);
          _memset(local_90,0x78,0x80);
          uVar10 = 0;
          do {
            uVar14 = uVar10 + 1;
            *(byte *)((int)&local_110 + uVar10) =
                 local_120[uVar10 & 0xf] ^ (byte)pSVar16[uVar10 + 0x22];
            uVar10 = uVar14;
          } while (uVar14 < 0x20);
          pCVar7 = local_168;
          if (local_174 != 0) {
            local_160 = "Config\\";
            local_15c = 7;
            local_184 = 0;
            local_180 = PTR_DAT_00bbf7dc;
            local_4 = 0;
            CFastStringInt::SetString(&local_184,(CFastStringInt *)&local_160,pSVar4);
            local_18c = (SPackListElem *)((uint)local_18c | 1);
            pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                ((void *)(DAT_00d73300 + 0x20),
                                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                                 (ulong)unaff_EDI);
            unaff_EDI = (SNat128 *)0x0;
            pSVar4 = (SStringParam *)0x1;
            pCVar7 = CSystemEngine::GetLocationUser
                               (*(CSystemEngine **)pSVar11,(CSystemEngine *)&local_17c);
            pCVar7 = CSystemFids::FindLocationDown
                               (pCVar7,(CSystemFids *)pSVar4,(CFastStringInt *)unaff_EDI,unaff_ESI,
                                unaff_EBP);
          }
          local_4 = 0xffffffff;
          if (((local_190 & 1) != 0) &&
             (local_190 = local_190 & 0xfffffffe, local_180 != PTR_DAT_00bbf7dc)) {
            if ((local_180[-1] & 0x80) == 0) {
              puVar12 = local_180 + -2;
            }
            else {
              puVar12 = local_180 + -4;
            }
            operator_delete__(puVar12);
            local_184 = 0;
            local_180 = PTR_DAT_00bbf7dc;
          }
          iVar15 = local_170;
          if (local_17c == 0) {
            iVar15 = local_164;
          }
          InstallPack(pCVar7,(char *)&local_110,(char *)(uVar17 & 2),iVar15,local_178,
                      (CFastBuffer<class_CPlugFilePack*> *)(uVar17 & 1),uVar17 & 0x10,(int)pSVar4);
          local_110 = 0x78787878;
          uStack_10c = 0x78787878;
          uStack_108 = 0x78787878;
          uStack_104 = 0x78787878;
          uStack_100 = 0x78787878;
          uStack_fc = 0x78787878;
          uStack_f8 = 0x78787878;
          uStack_f4 = 0x78787878;
        }
        pSVar16 = local_18c + 0x42;
        uVar17 = (int)local_188 - 1;
      }
      ExceptionList = local_c;
      return 1;
    }
  }
  ExceptionList = local_c;
  return 0;
}
}

// =================================================
// Function: PackList_StaticInit_CryptSfNormal
// =================================================
void __cdecl PackList_StaticInit_CryptSfNormal(void)
{
{
  undefined *puVar1;
  undefined1 uVar2;
  char *pcVar3;
  int iVar4;
  char cVar5;
  undefined *puVar6;
  char *pcVar7;
  int iVar8;
  
  if (DAT_00d6eba0 == 0) {
    pcVar3 = &DAT_00d127ac;
    DAT_00d6eba0 = 1;
    DAT_00d127ac = '\0';
    cVar5 = 'B';
    do {
      *pcVar3 = cVar5;
      cVar5 = pcVar3[-0x1b09bb];
      pcVar3 = pcVar3 + 1;
    } while (cVar5 != '\0');
    *pcVar3 = '\0';
    pcVar7 = "F86A1B5D5AF9862";
    pcVar3 = &DAT_00d127ac;
    cVar5 = DAT_00d127ac;
    while (cVar5 != '\0') {
      pcVar3 = pcVar3 + 1;
      cVar5 = *pcVar3;
    }
    cVar5 = 'F';
    do {
      pcVar7 = pcVar7 + 1;
      *pcVar3 = cVar5;
      cVar5 = *pcVar7;
      pcVar3 = pcVar3 + 1;
    } while (cVar5 != '\0');
    *pcVar3 = '\0';
    pcVar3 = &DAT_00d127d0;
    cVar5 = '1';
    DAT_00d127d0 = '\0';
    do {
      *pcVar3 = cVar5;
      cVar5 = pcVar3[-0x163b3f];
      pcVar3 = pcVar3 + 1;
    } while (cVar5 != '\0');
    *pcVar3 = '\0';
    pcVar7 = "B810C656DF2DE33";
    pcVar3 = &DAT_00d127d0;
    cVar5 = DAT_00d127d0;
    while (cVar5 != '\0') {
      pcVar3 = pcVar3 + 1;
      cVar5 = *pcVar3;
    }
    cVar5 = 'B';
    do {
      pcVar7 = pcVar7 + 1;
      *pcVar3 = cVar5;
      cVar5 = *pcVar7;
      pcVar3 = pcVar3 + 1;
    } while (cVar5 != '\0');
    *pcVar3 = '\0';
    pcVar3 = &DAT_00d127f4;
    cVar5 = 'E';
    DAT_00d127f4 = '\0';
    do {
      *pcVar3 = cVar5;
      cVar5 = pcVar3[-0x163b87];
      pcVar3 = pcVar3 + 1;
    } while (cVar5 != '\0');
    *pcVar3 = '\0';
    pcVar7 = "AA42A5EAF0AEFC8";
    pcVar3 = &DAT_00d127f4;
    cVar5 = DAT_00d127f4;
    while (cVar5 != '\0') {
      pcVar3 = pcVar3 + 1;
      cVar5 = *pcVar3;
    }
    cVar5 = 'A';
    do {
      pcVar7 = pcVar7 + 1;
      *pcVar3 = cVar5;
      cVar5 = *pcVar7;
      pcVar3 = pcVar3 + 1;
    } while (cVar5 != '\0');
    *pcVar3 = '\0';
    pcVar3 = &DAT_00d12818;
    cVar5 = '6';
    DAT_00d12818 = '\0';
    do {
      *pcVar3 = cVar5;
      cVar5 = pcVar3[-0x163bcf];
      pcVar3 = pcVar3 + 1;
    } while (cVar5 != '\0');
    *pcVar3 = '\0';
    pcVar7 = "9536FC3226F3FD0";
    pcVar3 = &DAT_00d12818;
    cVar5 = DAT_00d12818;
    while (cVar5 != '\0') {
      pcVar3 = pcVar3 + 1;
      cVar5 = *pcVar3;
    }
    cVar5 = '9';
    do {
      pcVar7 = pcVar7 + 1;
      *pcVar3 = cVar5;
      puVar1 = PTR_DAT_00d12880;
      cVar5 = *pcVar7;
      pcVar3 = pcVar3 + 1;
    } while (cVar5 != '\0');
    *pcVar3 = '\0';
    pcVar7 = (char *)0x0;
    pcVar3 = puVar1;
    do {
      cVar5 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar5 != '\0');
    if ((int)pcVar3 - (int)(puVar1 + 1) != -1) {
      iVar4 = (int)puVar1 - (int)PTR_DAT_00d1287c;
      iVar8 = (int)&DAT_00d6eb90 - (int)PTR_DAT_00d1287c;
      puVar6 = PTR_DAT_00d1287c;
      do {
        if (((uint)pcVar7 & 1) == 0) {
          uVar2 = puVar6[iVar4];
        }
        else {
          uVar2 = *puVar6;
        }
        puVar6[iVar8] = uVar2;
        pcVar7 = pcVar7 + 1;
        puVar6 = puVar6 + 1;
        pcVar3 = puVar1;
        do {
          cVar5 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar5 != '\0');
      } while (pcVar7 < pcVar3 + (1 - (int)(puVar1 + 1)));
    }
  }
  return;
}
}

// =================================================
// Function: ParseHlslConstant
// =================================================
void __cdecl
ParseHlslConstant(_D3DXCONSTANT_DESC *param_1,CFastString *param_2,SGpuConst *param_3,
                 CFastArray<struct_CPlugFileGPU::SSemantic> *param_4,
                 CFastBuffer<struct_CPlugFileGPU::SSampler> *param_5)
{
{
  SParam SVar1;
  ulong uVar2;
  CPlugFileGpuBuilder *pCVar3;
  SCasterCat *pSVar4;
  int iVar5;
  SParam *pSVar6;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  CPlugFileGpuBuilder *pCVar7;
  SLoadedLight *pSVar8;
  uint uVar9;
  SGpuConst *pSVar10;
  uint uVar11;
  SCasterCat *pSVar12;
  uint uVar13;
  TiXmlAttributeSet *unaff_EBX;
  CMwId *unaff_ESI;
  CFastString *pCVar14;
  char *pcVar15;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  char *pcVar17;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar18;
  char *pcVar19;
  char *pcVar20;
  int *in_stack_ffffff70;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffff74;
  char *in_stack_ffffff78;
  char *in_stack_ffffff7c;
  char *in_stack_ffffff80;
  char *pcVar21;
  char *pcVar22;
  char *pcVar23;
  CFastString *pCVar24;
  SHeaderCommunity *pSVar25;
  CPlugFileGpuBuilder *pCVar26;
  CPlugFileGpuBuilder *in_stack_ffffff9c;
  CPlugFileGpuBuilder *in_stack_ffffffa4;
  CFastString *in_stack_ffffffa8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffb0;
  SParam *local_4c;
  SParam *local_48;
  char *local_44;
  CFastString local_40 [4];
  char *local_3c;
  uint uStack_38;
  uint local_34;
  undefined *puStack_30;
  undefined1 *local_2c;
  SParam_Fids local_28 [12];
  undefined1 local_1c;
  undefined1 local_18;
  void *local_14;
  undefined1 *local_10;
  void *local_c;
  undefined4 local_8;
  
  local_c = (void *)0xffffffff;
  local_10 = &DAT_00ade080;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pCVar14 = *(CFastString **)param_1;
  if (*pCVar14 == (CFastString)0x24) {
    pCVar14 = pCVar14 + 1;
  }
  if ((param_4 != (CFastArray<struct_CPlugFileGPU::SSemantic> *)0x0) &&
     (pCVar24 = pCVar14,
     uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                       (param_4,(CFastBuffer<class_CCrystalFace*> *)
                                (DAT_00cca150 ^ (uint)&stack0xffffff90)), uVar2 != 0)) {
    CMwId::CreateFromLocalName(&stack0xffffffac);
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    local_8 = 0;
    pCVar3 = (CPlugFileGpuBuilder *)CFastBuffer<class_CCrystalFace*>::GetCount(param_4,unaff_EDI);
    pCVar14 = in_stack_ffffffa8;
    if (pCVar3 != (CPlugFileGpuBuilder *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[](param_4,pCVar16,(ulong)unaff_ESI);
        if (*(SParam **)pSVar4 == local_4c) {
          pcVar22 = *(char **)(param_1 + 0xc);
          pcVar21 = (char *)(&DAT_00d154f8)[*(uint *)(pSVar4 + 4) & 0xffff];
          if (pcVar22 == pcVar21) {
            unaff_ESI = (CMwId *)0x8dbe44;
            pSVar8 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                               (param_3,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                                        0x8dbe44);
            *(undefined4 *)pSVar8 = 0;
            *(uint *)pSVar8 = *(uint *)pSVar8 | 1;
            *(uint *)pSVar8 = (*(uint *)(pSVar4 + 4) & 0x7fff) * 2 | *(uint *)pSVar8 & 1;
            *(undefined4 *)(pSVar8 + 4) = *(undefined4 *)(param_1 + 8);
            local_44 = (char *)0x1;
          }
          else {
            unaff_ESI = (CMwId *)&DAT_00bbd150;
            pcVar15 = " instead of ";
            pcVar23 = "\" should be ";
            in_stack_ffffff7c = "Register count of \"";
            in_stack_ffffff78 = (char *)0x8dbe10;
            pCVar7 = CFastString::operator<<
                               (param_2,(CPlugFileGpuBuilder *)"Register count of \"",
                                *(char **)param_1);
            in_stack_ffffff80 = (char *)0x8dbe17;
            pCVar7 = CFastString::operator<<
                               ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)pcVar23,pcVar21);
            pCVar7 = CFastString::operator<<
                               ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)pcVar15,pcVar22);
            pCVar7 = CFastString::operator<<
                               ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)unaff_ESI,
                                (char *)unaff_EBX);
            unaff_EBX = (TiXmlAttributeSet *)0x8dbe2c;
            pCVar7 = CFastString::operator<<
                               ((CFastString *)pCVar7,in_stack_ffffff9c,(char *)pCVar24);
            pCVar7 = CFastString::operator<<
                               ((CFastString *)pCVar7,in_stack_ffffffa4,(char *)pCVar14);
            pCVar14 = (CFastString *)0x8dbe3a;
            CFastString::operator<<((CFastString *)pCVar7,pCVar3,(char *)in_stack_ffffffb0);
          }
          break;
        }
        pCVar16 = pCVar16 + 1;
      } while (pCVar16 < in_stack_ffffffb0);
    }
    OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)unaff_ESI);
    in_stack_ffffffa8 = pCVar14;
    if (local_4c != (SParam *)0x0) {
      ExceptionList = local_c;
      return;
    }
  }
  pCVar24 = (CFastString *)0x3;
  pcVar23 = &DAT_00bbd118;
  pcVar21 = (char *)0x8dbe9c;
  pcVar22 = (char *)pCVar14;
  iVar5 = _strncmp((char *)pCVar14,"Gbx",3);
  if (iVar5 == 0) {
    pCVar24 = pCVar14 + 3;
    pcVar23 = (char *)0x8dbeb4;
    CFastString::CFastString((CFastString *)&puStack_30,pCVar24,(char *)unaff_ESI);
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      unaff_ESI = (CMwId *)(&PTR_s_VisualPrCamera_00d14e28)[(int)pCVar16];
      pSVar6 = (SParam *)unaff_ESI;
      do {
        SVar1 = *pSVar6;
        pSVar6 = pSVar6 + 1;
      } while (SVar1 != (SParam)0x0);
      pSVar6 = pSVar6 + -(int)(unaff_ESI + 1);
      if (unaff_ESI == (CMwId *)0x0) {
        local_48 = (SParam *)0x0;
      }
      else {
        local_48 = (SParam *)unaff_ESI;
        do {
          SVar1 = *local_48;
          local_48 = local_48 + 1;
        } while (SVar1 != (SParam)0x0);
        local_48 = local_48 + -(int)(unaff_ESI + 1);
      }
      local_4c = (SParam *)unaff_ESI;
      CFastString::Compare
                ((CFastString *)&stack0xffffffac,(SParam_Fids *)&local_4c,pSVar6,in_stack_ffffff70,
                 (int *)in_stack_ffffff74);
      if ((extraout_EAX == 0) &&
         (((local_4c <= pSVar6 || (SVar1 = local_48[(int)pSVar6], SVar1 == (SParam)0x5f)) ||
          (('/' < (char)SVar1 && ((char)SVar1 < ':')))))) {
        pCVar3 = (CPlugFileGpuBuilder *)(&DAT_00d15190)[(int)pCVar16];
        if (*(CPlugFileGpuBuilder **)(param_1 + 4) == pCVar3) {
          pCVar18 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                    (&DAT_00d15bc8)[(int)unaff_ESI];
          in_stack_ffffffb0 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_1 + 8);
          pcVar15 = (char *)(((uint)unaff_ESI & 0x7fff) * 2 | 1);
          if (pCVar18 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
            pSVar25 = (SHeaderCommunity *)0x0;
            in_stack_ffffff74 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x8dbf9f;
            pcVar20 = pcVar15;
            CMwId::CMwId(&stack0xffffff88,unaff_ESI);
            local_1c = 2;
            if (pSVar6 < local_48) {
              in_stack_ffffff74 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x8dbfbe;
              CFastString::CFastString
                        ((CFastString *)&stack0xffffffa8,(CFastString *)(local_44 + (int)pSVar6),
                         in_stack_ffffff7c);
              local_18 = 3;
              if (*in_stack_ffffffb0 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat>)0x5f) {
                SStringParam::SStringParam(&local_2c,(SStringParam *)"Sampler",in_stack_ffffff80);
                in_stack_ffffff78 = (char *)0x8dbfea;
                CFastString::Compare
                          (local_40,local_28,(SParam *)&DAT_00000007,(int *)pcVar21,(int *)pcVar22);
                if (extraout_EAX_00 != 0) goto LAB_008dbff2;
                CFastString::TruncBefore
                          ((CFastString *)&local_48,(CFastString *)(local_48 + -1),(ulong)pcVar23);
                pcVar22 = (char *)&local_44;
                in_stack_ffffff80 = &stack0xffffffa0;
                in_stack_ffffff7c = (char *)0x8dc173;
                in_stack_ffffffa8 =
                     (CFastString *)
                     GetUsageIndexFromSampler
                               ((CMwId *)in_stack_ffffff80,param_5,(CFastString *)pcVar22,
                                (SLoadDesc *)&local_3c);
                pcVar15 = local_3c;
                pcVar21 = (char *)param_5;
                if (in_stack_ffffffa8 == (CFastString *)0xffffffff) {
                  pcVar23 = &DAT_00bbd0dc;
                  pcVar21 = "Unknown Sampler \"";
                  in_stack_ffffff80 = (char *)0x8dc19a;
                  pCVar3 = CFastString::operator<<
                                     (param_2,(CPlugFileGpuBuilder *)"Unknown Sampler \"",
                                      (char *)&local_44);
                  pcVar22 = (char *)0x8dc1a1;
                  pCVar3 = CFastString::operator<<
                                     ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar23,
                                      (char *)pSVar25);
                  CFastString::operator<<
                            ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)unaff_ESI,
                             (char *)unaff_EBX);
                  unaff_EBX = (TiXmlAttributeSet *)0x8dc1b1;
                  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                            (&uStack_38,(SHeaderCommunity *)in_stack_ffffff9c);
                  goto LAB_008dc393;
                }
LAB_008dc228:
                if ((((uint)pcVar15 & 0x10000) != 0) ||
                   (pCVar14 = *(CFastString **)((int)pcVar20 * 4 + 0xd15860),
                   in_stack_ffffffa8 < pCVar14)) {
                  local_8 = CONCAT31(local_8._1_3_,2);
                  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_44,pSVar25);
                  goto LAB_008dc294;
                }
                pcVar23 = " usage(s).\r\n";
                pcVar21 = "\" has only ";
                in_stack_ffffff7c = "LoadId \"";
                in_stack_ffffff78 = (char *)0x8dc25c;
                pCVar7 = CFastString::operator<<
                                   (param_2,(CPlugFileGpuBuilder *)"LoadId \"",(char *)local_4c);
                in_stack_ffffff80 = (char *)0x8dc263;
                pCVar7 = CFastString::operator<<
                                   ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)pcVar21,
                                    (char *)pCVar14);
                pcVar22 = (char *)0x8dc26a;
                pCVar7 = CFastString::operator<<
                                   ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)pcVar23,
                                    (char *)pSVar25);
                pCVar7 = CFastString::operator<<
                                   ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)unaff_ESI,
                                    (char *)unaff_EBX);
                unaff_EBX = (TiXmlAttributeSet *)0x8dc278;
                CFastString::operator<<((CFastString *)pCVar7,in_stack_ffffff9c,(char *)pCVar3);
                CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                          (&puStack_30,(SHeaderCommunity *)in_stack_ffffffa4);
              }
              else {
LAB_008dbff2:
                puStack_30 = &DAT_00bbd108;
                local_2c = &DAT_00000004;
                in_stack_ffffff78 = (char *)0x8dc012;
                CFastString::Compare
                          ((CFastString *)&stack0xffffffb0,(SParam_Fids *)&puStack_30,
                           (SParam *)&DAT_00000004,(int *)pcVar21,(int *)pcVar22);
                if (extraout_EAX_01 != 0) {
                  if (*local_44 == '_') {
                    pcVar22 = (char *)0x0;
                    pcVar21 = (char *)0x0;
                    in_stack_ffffff80 = &stack0xffffffa4;
                    in_stack_ffffff7c = (char *)0x8dc035;
                    iVar5 = CFastString::GetNatural
                                      ((CFastString *)&local_48,(CFastString *)in_stack_ffffff80,
                                       (ulong *)0x0,0,(ulong)pcVar23);
                    if (iVar5 != 0) goto LAB_008dc039;
                  }
                  else {
LAB_008dc039:
                    pcVar22 = (char *)0x0;
                    pcVar21 = (char *)0x0;
                    in_stack_ffffff80 = &stack0xffffffa4;
                    in_stack_ffffff7c = (char *)0x8dc04b;
                    iVar5 = CFastString::GetNatural
                                      ((CFastString *)&local_48,(CFastString *)in_stack_ffffff80,
                                       (ulong *)0x0,0,(ulong)pcVar23);
                    if (iVar5 != 0) goto LAB_008dc228;
                  }
                  pcVar23 = (char *)0x8dc05c;
                  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_44,pSVar25);
                  pCVar24 = (CFastString *)0x8dc06a;
                  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)unaff_ESI);
                  goto LAB_008dc06a;
                }
                CFastString::TruncBefore
                          ((CFastString *)&local_48,(CFastString *)(local_48 + -4),(ulong)pcVar23);
                pcVar22 = (char *)&local_44;
                in_stack_ffffff80 = &stack0xffffffa0;
                in_stack_ffffff7c = (char *)0x8dc1df;
                in_stack_ffffffa8 =
                     (CFastString *)
                     GetUsageIndexFromSampler
                               ((CMwId *)in_stack_ffffff80,param_5,(CFastString *)pcVar22,
                                (SLoadDesc *)&local_3c);
                pcVar15 = local_3c;
                pcVar21 = (char *)param_5;
                if (in_stack_ffffffa8 != (CFastString *)0xffffffff) goto LAB_008dc228;
                pcVar23 = &DAT_00bbd0dc;
                pcVar21 = "Unknown Sampler \"";
                in_stack_ffffff80 = (char *)0x8dc202;
                pCVar3 = CFastString::operator<<
                                   (param_2,(CPlugFileGpuBuilder *)"Unknown Sampler \"",
                                    (char *)&local_44);
                pcVar22 = (char *)0x8dc209;
                pCVar3 = CFastString::operator<<
                                   ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar23,
                                    (char *)pSVar25);
                CFastString::operator<<
                          ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)unaff_ESI,(char *)unaff_EBX)
                ;
                unaff_EBX = (TiXmlAttributeSet *)0x8dc219;
                CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                          (&uStack_38,(SHeaderCommunity *)in_stack_ffffff9c);
              }
            }
            else {
LAB_008dc294:
              pcVar23 = (char *)(&DAT_00d154f8)[(int)in_stack_ffffffb0];
              pcVar17 = *(char **)(param_1 + 0xc);
              if (pcVar17 == pcVar23) {
                if (((uint)pcVar15 & 0x10000) == 0) {
                  uStack_38 = (int)pcVar20 << 0x11 | (uint)pcVar15 & 0x1ffff;
                }
                else {
                  pSVar10 = param_3 + 0x3c;
                  iVar5 = CFastArray<class_CGameMenuFrame*>::Find
                                    (pSVar10,(CFastArray<class_GxTexCoordSet> *)&stack0xffffffa4,
                                     (GxTexCoordSet *)unaff_ESI);
                  if (iVar5 == -1) {
                    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                                      (pSVar10,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
                    puStack_30 = (undefined *)(uVar2 << 0x11 | (uint)pcVar15 & 0x1ffff);
                    unaff_EBX = (TiXmlAttributeSet *)&stack0xffffffac;
                    unaff_ESI = (CMwId *)0x8dc348;
                    CFastBuffer<class_CMwId>::Add
                              (pSVar10,unaff_EBX,(TiXmlAttribute *)in_stack_ffffff9c);
                  }
                  else {
                    local_34 = iVar5 << 0x11 | (uint)pcVar15 & 0x1ffff;
                  }
                }
                pSVar10 = param_3;
                if (local_44 != (char *)0x2) {
                  if (local_44 == (char *)0x1) {
                    pSVar10 = param_3 + 0x24;
                  }
                  else {
                    pSVar10 = param_3 + 0x30;
                  }
                }
                pcVar23 = (char *)0x8dc38b;
                CFastBuffer<class_GmNat2>::Add
                          (pSVar10,(TiXmlAttributeSet *)&uStack_38,(TiXmlAttribute *)unaff_ESI);
                local_48 = (SParam *)0x1;
              }
              else {
                pCVar26 = (CPlugFileGpuBuilder *)&DAT_00bbd150;
                pcVar22 = " instead of ";
                in_stack_ffffff80 = "\" should be ";
                in_stack_ffffff78 = "Register count of \"";
                in_stack_ffffff74 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x8dc2c7
                ;
                pCVar7 = CFastString::operator<<
                                   (param_2,(CPlugFileGpuBuilder *)"Register count of \"",
                                    *(char **)param_1);
                in_stack_ffffff7c = (char *)0x8dc2ce;
                pCVar7 = CFastString::operator<<
                                   ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)in_stack_ffffff80,
                                    pcVar23);
                pcVar21 = (char *)0x8dc2d5;
                pCVar7 = CFastString::operator<<
                                   ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)pcVar22,pcVar17);
                pcVar23 = (char *)0x8dc2dc;
                pCVar7 = CFastString::operator<<((CFastString *)pCVar7,pCVar26,(char *)unaff_ESI);
                unaff_ESI = (CMwId *)0x8dc2e3;
                pCVar7 = CFastString::operator<<
                                   ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)unaff_EBX,
                                    (char *)in_stack_ffffff9c);
                in_stack_ffffff9c = (CPlugFileGpuBuilder *)0x8dc2ea;
                pCVar3 = CFastString::operator<<
                                   ((CFastString *)pCVar7,pCVar3,(char *)in_stack_ffffffa4);
                CFastString::operator<<
                          ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)in_stack_ffffffa8,pcVar20);
              }
            }
LAB_008dc393:
            pCVar24 = (CFastString *)0x8dc3a1;
            OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)unaff_ESI);
            pCVar16 = in_stack_ffffffb0;
          }
          else {
            pCVar16 = in_stack_ffffffb0;
            if (pCVar18 == in_stack_ffffffb0) {
              unaff_EBX = (TiXmlAttributeSet *)0x1;
            }
            else {
              in_stack_ffffff74 =
                   (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)&DAT_00bbd150;
              pcVar20 = " instead of ";
              pcVar15 = "\" should be ";
              pCVar3 = CFastString::operator<<
                                 (param_2,(CPlugFileGpuBuilder *)"Register index of \"",
                                  *(char **)param_1);
              pCVar3 = CFastString::operator<<
                                 ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar15,
                                  (char *)pCVar18);
              pCVar3 = CFastString::operator<<
                                 ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar20,
                                  (char *)in_stack_ffffffb0);
              pCVar3 = CFastString::operator<<
                                 ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)in_stack_ffffff74,
                                  in_stack_ffffff78);
              in_stack_ffffff78 = (char *)0x8dc12a;
              pCVar3 = CFastString::operator<<
                                 ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)in_stack_ffffff7c,
                                  in_stack_ffffff80);
              in_stack_ffffff80 = (char *)0x8dc131;
              pCVar3 = CFastString::operator<<
                                 ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar21,pcVar22);
              pcVar22 = (char *)0x8dc138;
              CFastString::operator<<
                        ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar23,(char *)pCVar24);
            }
          }
        }
        else {
          pcVar15 = (&PTR_DAT_00d14e10)[(int)pCVar3];
          in_stack_ffffff74 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)&DAT_00bbd150;
          pcVar20 = (&PTR_DAT_00d14e10)[*(int *)(param_1 + 4)];
          pcVar19 = " instead of ";
          pcVar17 = "\" should be ";
          pCVar3 = CFastString::operator<<
                             (param_2,(CPlugFileGpuBuilder *)"Register set of \"",*(char **)param_1)
          ;
          pCVar3 = CFastString::operator<<
                             ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar17,pcVar15);
          pCVar3 = CFastString::operator<<
                             ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar19,pcVar20);
          pCVar3 = CFastString::operator<<
                             ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)in_stack_ffffff74,
                              in_stack_ffffff78);
          in_stack_ffffff78 = (char *)0x8dc0d6;
          pCVar3 = CFastString::operator<<
                             ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)in_stack_ffffff7c,
                              in_stack_ffffff80);
          in_stack_ffffff80 = (char *)0x8dc0dd;
          pCVar3 = CFastString::operator<<
                             ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar21,pcVar22);
          pcVar22 = (char *)0x8dc0e4;
          CFastString::operator<<
                    ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar23,(char *)pCVar24);
          pCVar16 = in_stack_ffffffb0;
        }
        break;
      }
LAB_008dc06a:
      pCVar16 = in_stack_ffffffb0 + 1;
      in_stack_ffffffb0 = pCVar16;
    } while (pCVar16 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xda);
    in_stack_ffffffb0 = pCVar16;
    if (pCVar16 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xda) {
      pCVar24 = (CFastString *)&DAT_00b2ec78;
      pcVar22 = "Unknown Gbx LoadId \"";
      pcVar21 = (char *)0x8dc3c2;
      pCVar3 = CFastString::operator<<
                         (param_2,(CPlugFileGpuBuilder *)"Unknown Gbx LoadId \"",(char *)&puStack_30
                         );
      pcVar23 = (char *)0x8dc3c9;
      pCVar3 = CFastString::operator<<
                         ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pCVar24,(char *)unaff_ESI);
      unaff_ESI = (CMwId *)0x8dc3d0;
      CFastString::operator<<
                ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)unaff_EBX,(char *)in_stack_ffffff9c);
      in_stack_ffffffb0 = pCVar16;
    }
    if (local_2c != PTR_DAT_00bbf7d8) {
      pCVar24 = (CFastString *)(local_2c + -1);
      if ((local_2c[-1] & 0x80) != 0) {
        pCVar24 = (CFastString *)(local_2c + -4);
      }
      pcVar23 = (char *)0x8dc3f6;
      operator_delete__(pCVar24);
      puStack_30 = (undefined *)0x0;
      local_2c = PTR_DAT_00bbf7d8;
    }
    if (local_4c != (SParam *)0x0) {
      ExceptionList = local_c;
      return;
    }
  }
  pSVar8 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem(param_3,in_stack_ffffff74);
  *(undefined4 *)pSVar8 = 0;
  *(uint *)pSVar8 = *(uint *)pSVar8 & 0xfffffffe;
  uVar13 = *(uint *)pSVar8;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (param_3 + 0xc,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff78);
  *(uint *)pSVar8 = uVar13 & 1 | uVar2 * 2;
  *(undefined4 *)(pSVar8 + 4) = *(undefined4 *)(param_1 + 8);
  pSVar8 = CFastBuffer<struct_SPlugGpuLoadFx>::AddNewElem
                     (param_3 + 0xc,
                      (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)in_stack_ffffff7c);
  iVar5 = _strncmp((char *)unaff_ESI,"Rgba",4);
  if (iVar5 == 0) {
    unaff_ESI = unaff_ESI + 4;
    *(uint *)(pSVar8 + 4) = *(uint *)(pSVar8 + 4) & 0xfffffeff | 0xc0;
  }
  else {
    iVar5 = _strncmp((char *)unaff_ESI,"Rgb",3);
    if (iVar5 == 0) {
      unaff_ESI = unaff_ESI + 3;
      *(uint *)(pSVar8 + 4) = *(uint *)(pSVar8 + 4) & 0xfffffeff | 0xc0;
    }
    else {
      iVar5 = _strncmp((char *)unaff_ESI,"Alpha",5);
      if (iVar5 == 0) {
        unaff_ESI = unaff_ESI + 5;
        *(uint *)(pSVar8 + 4) = *(uint *)(pSVar8 + 4) & 0xffffff3f | 0x100;
      }
      else {
        iVar5 = _strncmp((char *)unaff_ESI,"In01",4);
        if (iVar5 == 0) {
          unaff_ESI = unaff_ESI + 4;
          *(uint *)(pSVar8 + 4) = *(uint *)(pSVar8 + 4) & 0xfffffe7f | 0x40;
        }
        else {
          iVar5 = _strncmp((char *)unaff_ESI,"Inv",3);
          if (iVar5 == 0) {
            unaff_ESI = unaff_ESI + 3;
            *(uint *)(pSVar8 + 4) = *(uint *)(pSVar8 + 4) & 0xfffffebf | 0x80;
          }
          else {
            *(uint *)(pSVar8 + 4) = *(uint *)(pSVar8 + 4) & 0xfffffe3f;
          }
        }
      }
    }
  }
  iVar5 = _strncmp((char *)unaff_ESI,"Comp",4);
  if (((iVar5 == 0) && ('0' < (char)unaff_ESI[4])) && ((char)unaff_ESI[4] < '4')) {
    unaff_ESI = unaff_ESI + 5;
  }
  CMwId::SetLocalName(pSVar8,unaff_ESI,(CFastStringInt *)in_stack_ffffff80);
  *(uint *)(pSVar8 + 4) =
       *(uint *)(pSVar8 + 4) ^ (*(int *)(param_1 + 0x20) << 9 ^ *(uint *)(pSVar8 + 4)) & 0x7fe00;
  uVar13 = *(uint *)(pSVar8 + 4);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (param_3 + 0x18,(CFastBuffer<class_CCrystalFace*> *)pcVar21);
  uVar9 = uVar2 << 0x13;
  uVar11 = uVar13 & 0x7ffff | uVar9;
  *(uint *)(pSVar8 + 4) = uVar11;
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
    uVar11 = uVar13 & 0x7ffc9 | uVar9 | 9;
    goto LAB_008dc639;
  case 1:
    pCVar14 = (CFastString *)(*(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18));
    if (in_stack_ffffffa8 <= pCVar14 && (int)pCVar14 - (int)in_stack_ffffffa8 != 0) {
      pCVar14 = in_stack_ffffffa8;
    }
    *(uint *)(pSVar8 + 4) = (uint)pCVar14 & 7 | uVar13 & 0x7ffc8 | uVar9 | 8;
    break;
  case 3:
    uVar11 = (*(uint *)(param_1 + 0x18) ^ uVar11) & 7 ^ uVar11;
    *(uint *)(pSVar8 + 4) = uVar11;
    *(uint *)(pSVar8 + 4) = (*(int *)(param_1 + 0x1c) * 8 ^ uVar11) & 0x38 ^ uVar11;
    break;
  case 5:
    pCVar14 = (CFastString *)(*(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18));
    if (in_stack_ffffffa8 <= pCVar14 && (int)pCVar14 - (int)in_stack_ffffffa8 != 0) {
      pCVar14 = in_stack_ffffffa8;
    }
    uVar11 = ((uint)pCVar14 ^ uVar11) & 7 ^ uVar11;
    *(uint *)(pSVar8 + 4) = uVar11;
    uVar11 = (*(int *)(param_1 + 0xc) * 8 ^ uVar11) & 0x38 ^ uVar11;
LAB_008dc639:
    *(uint *)(pSVar8 + 4) = uVar11;
  }
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (in_stack_ffffffb0,(CFastBuffer<class_CCrystalFace*> *)pcVar22);
  CFastBuffer<class_GmVec4>::AllocSetCount
            (in_stack_ffffffb0,(CFastBuffer<class_GxVertex2> *)(uVar2 + *(int *)(param_1 + 0xc)),
             (ulong)pcVar23);
  pSVar4 = CFastBuffer<class_GxColor>::operator[]
                     (in_stack_ffffffb0,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      (*(uint *)(pSVar8 + 4) >> 0x13),(ulong)pCVar24);
  uVar13 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    pSVar12 = pSVar4 + 8;
    do {
      uVar13 = uVar13 + 1;
      *(undefined4 *)(pSVar12 + -8) = 0;
      *(undefined4 *)(pSVar12 + -4) = 0;
      *(undefined4 *)pSVar12 = 0;
      *(undefined4 *)(pSVar12 + 4) = 0x3f800000;
      pSVar12 = pSVar12 + 0x10;
    } while (uVar13 < *(uint *)(param_1 + 0xc));
  }
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    _memcpy(pSVar4,*(void **)(param_1 + 0x2c),*(int *)(param_1 + 0xc) << 4);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: ParseHlslSampler
// =================================================
void __cdecl
ParseHlslSampler(_D3DXCONSTANT_DESC *param_1,CFastBuffer<struct_CPlugFileGPU::SSampler> *param_2)
{
{
  int iVar1;
  CPlugFileGpuBuilder *pCVar2;
  CFastString *pCVar3;
  int extraout_EAX;
  SLoadedLight *this;
  CFastStringBase<wchar_t> *pCVar4;
  undefined *puVar5;
  ulong unaff_EBX;
  void *unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  CPlugFileGpuBuilder *pCVar6;
  CFastStringInt *pCVar7;
  CFastString *in_stack_ffffffcc;
  char *in_stack_ffffffd4;
  CFastString local_28 [4];
  CFastString local_24 [4];
  uint uStack_20;
  CPlugFileGpuBuilder *local_1c;
  CFastStringBase<wchar_t> *local_18;
  CFastStringBase<wchar_t> *local_14;
  CMwId *local_10;
  undefined *local_c;
  undefined4 local_8;
  
  local_c = (undefined *)0xffffffff;
  local_10 = (CMwId *)&DAT_00ade0b0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = *(int *)(param_1 + 0x14);
  if ((iVar1 < 0xb) || (0xe < iVar1)) {
    pCVar2 = (CPlugFileGpuBuilder *)0x1;
  }
  else {
    pCVar2 = (CPlugFileGpuBuilder *)(iVar1 + -0xb);
  }
  pCVar3 = *(CFastString **)param_1;
  if (*pCVar3 == (CFastString)0x24) {
    pCVar3 = pCVar3 + 1;
  }
  CFastString::CFastString(local_28,pCVar3,(char *)(DAT_00cca150 ^ (uint)&stack0xffffffc0));
  pCVar6 = (CPlugFileGpuBuilder *)0x0;
  local_8 = 0;
  local_1c = (CPlugFileGpuBuilder *)&DAT_00bbd154;
  local_18 = (CFastStringBase<wchar_t> *)0x3;
  CFastString::Compare(local_24,(SParam_Fids *)&local_1c,(SParam *)0x3,unaff_EDI,unaff_ESI);
  if (extraout_EAX == 0) {
    CFastString::TruncBefore((CFastString *)&local_1c,(CFastString *)(local_1c + -3),unaff_EBX);
  }
  if (((1 < *(uint *)(param_1 + 0xc)) &&
      ((local_14 + -1)[(int)local_18] == (CFastStringBase<wchar_t>)0x73)) &&
     (pCVar4 = local_18 + -1, pCVar4 != local_18)) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)&local_18,pCVar4,1,0,(SOldChars *)in_stack_ffffffcc);
    local_10[(int)pCVar4] = (CMwId)0x0;
    local_14 = pCVar4;
  }
  local_1c = *(CPlugFileGpuBuilder **)(param_1 + 0xc);
  if (local_1c != (CPlugFileGpuBuilder *)0x0) {
    uStack_20 = uStack_20 & 3;
    do {
      this = CFastBuffer<struct_CPlugFileGPU::SSampler>::AddNewElem
                       (param_2,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                                in_stack_ffffffcc);
      in_stack_ffffffcc = (CFastString *)&local_14;
      pCVar7 = (CFastStringInt *)0x8dc7d8;
      CFastString::CFastString((CFastString *)&local_c,in_stack_ffffffcc,(char *)pCVar2);
      if (1 < *(uint *)(param_1 + 0xc)) {
        in_stack_ffffffcc = (CFastString *)0x8dc7ed;
        pCVar2 = pCVar6;
        CFastString::operator<<((CFastString *)&local_8,pCVar6,in_stack_ffffffd4);
      }
      *(undefined4 *)(this + 4) = 0;
      CMwId::SetLocalName(this,local_10,pCVar7);
      *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffffffc | uStack_20;
      *(uint *)(this + 4) = (int)(pCVar6 + *(int *)(param_1 + 8)) * 4 ^ uStack_20 & 3;
      if (local_c != PTR_DAT_00bbf7d8) {
        puVar5 = local_c + -1;
        if ((local_c[-1] & 0x80) != 0) {
          puVar5 = local_c + -4;
        }
        operator_delete__(puVar5);
        local_10 = (CMwId *)0x0;
        local_c = PTR_DAT_00bbf7d8;
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < local_1c);
  }
  if (local_14 != (CFastStringBase<wchar_t> *)PTR_DAT_00bbf7d8) {
    pCVar4 = local_14 + -1;
    if (((byte)local_14[-1] & 0x80) != 0) {
      pCVar4 = local_14 + -4;
    }
    operator_delete__(pCVar4);
  }
  ExceptionList = unaff_EBP;
  return;
}
}

// =================================================
// Function: ParseUrl
// =================================================
int __cdecl
ParseUrl(TiXmlElement *param_1,CControlBase *param_2,CGameManialinkPage *param_3,
        SBuildPageParams *param_4,SDico *param_5)
{
{
  char cVar1;
  char *pcVar2;
  _func___cdecl_void_ulong *p_Var3;
  SLoadedLight *this;
  int iVar4;
  CMwCmdFastCallUser *pCVar5;
  CMwNod *extraout_EAX;
  CMwNod *extraout_EAX_00;
  SDico *in_ECX;
  TiXmlElement *in_EDX;
  SStringParam *unaff_EBP;
  CMwCmdFastCallUser *unaff_ESI;
  CMwNod *pCVar6;
  TiXmlNode *unaff_EDI;
  undefined4 unaff_retaddr;
  void *pvVar7;
  CMwCmdFastCallUser *in_stack_0000001c;
  GmVec3 *in_stack_ffffffc0;
  char *local_34;
  char *local_30;
  char *local_2c;
  undefined *local_28;
  CMwCmdScriptVarBool local_24 [4];
  SNormalDec3N local_20 [4];
  undefined1 local_1c [12];
  char acStack_10 [4];
  void *local_c;
  TiXmlElement *local_8;
  void *local_4;
  
  local_8 = (TiXmlElement *)&LAB_00ac0d06;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_34 = PTR_DAT_00bbf7dc;
  local_4 = (void *)0x0;
  SControlUrlLink::SControlUrlLink
            (&local_30,(SControlUrlLink *)(DAT_00cca150 ^ (uint)&stack0xffffffb4));
  pvVar7 = (void *)CONCAT31((int3)((uint)unaff_retaddr >> 8),1);
  SPlugUrlLink::Clear(&local_2c,unaff_EDI);
  local_8 = (TiXmlElement *)0x0;
  if (local_28 == (undefined *)0x0) {
    unaff_EDI = (TiXmlNode *)&DAT_00b32c9c;
    pcVar2 = TiXmlElement::Attribute
                       (in_EDX,(TiXmlElement *)&DAT_00b32c9c,(char *)unaff_ESI,(int *)unaff_EBP);
    if (pcVar2 != (char *)0x0) {
      local_2c = pcVar2;
      do {
        cVar1 = *local_2c;
        local_2c = local_2c + 1;
      } while (cVar1 != '\0');
      local_2c = local_2c + -(int)(pcVar2 + 1);
      local_30 = pcVar2;
      CFastStringInt::SetUtf8
                (&local_28,(CFastStringInt *)&local_30,(SStringParam *)in_stack_ffffffc0);
      in_stack_ffffffc0 = (GmVec3 *)0x0;
      unaff_EBP = (SStringParam *)&DAT_00d71d58;
      unaff_ESI = (CMwCmdFastCallUser *)0x0;
      unaff_EDI = (TiXmlNode *)0x0;
      SPlugUrlLink::Set(local_1c,local_24,0);
    }
    if (local_2c == (char *)0x0) {
      pcVar2 = TiXmlElement::Attribute
                         (in_EDX,(TiXmlElement *)"manialink",(char *)unaff_EDI,(int *)unaff_ESI);
      if (pcVar2 != (char *)0x0) {
        local_30 = pcVar2;
        do {
          cVar1 = *local_30;
          local_30 = local_30 + 1;
        } while (cVar1 != '\0');
        local_30 = local_30 + -(int)(pcVar2 + 1);
        local_34 = pcVar2;
        CFastStringInt::SetUtf8(&local_2c,(CFastStringInt *)&local_34,unaff_EBP);
        unaff_EBP = (SStringParam *)0x0;
        unaff_ESI = (CMwCmdFastCallUser *)&DAT_00d71d58;
        unaff_EDI = (TiXmlNode *)0x0;
        SPlugUrlLink::Set(local_20,(CMwCmdScriptVarBool *)&local_28,1);
      }
      if (local_2c == (char *)0x0) {
        pcVar2 = TiXmlElement::Attribute
                           (in_EDX,(TiXmlElement *)"maniazone",(char *)unaff_EDI,(int *)unaff_ESI);
        if (pcVar2 != (char *)0x0) {
          local_30 = pcVar2;
          do {
            cVar1 = *local_30;
            local_30 = local_30 + 1;
          } while (cVar1 != '\0');
          local_30 = local_30 + -(int)(pcVar2 + 1);
          local_34 = pcVar2;
          CFastStringInt::SetUtf8(&local_2c,(CFastStringInt *)&local_34,unaff_EBP);
          unaff_EBP = (SStringParam *)0x0;
          unaff_ESI = (CMwCmdFastCallUser *)&DAT_00d71d58;
          unaff_EDI = (TiXmlNode *)0x0;
          SPlugUrlLink::Set(local_20,(CMwCmdScriptVarBool *)&local_28,2);
        }
        if (local_2c == (char *)0x0) {
          pcVar2 = TiXmlElement::Attribute
                             (in_EDX,(TiXmlElement *)"urlid",(char *)unaff_EDI,(int *)unaff_ESI);
          if (pcVar2 != (char *)0x0) {
            DicoGetText(in_ECX,pcVar2,(CFastStringInt *)&local_2c);
            unaff_ESI = (CMwCmdFastCallUser *)0x0;
            unaff_EDI = (TiXmlNode *)&DAT_00d71d58;
            SPlugUrlLink::Set(local_24,(CMwCmdScriptVarBool *)&local_2c,0);
          }
          if (local_2c == (char *)0x0) {
            pcVar2 = TiXmlElement::Attribute
                               (in_EDX,(TiXmlElement *)"manialinkid",(char *)unaff_EDI,
                                (int *)unaff_ESI);
            if (pcVar2 != (char *)0x0) {
              DicoGetText(in_ECX,pcVar2,(CFastStringInt *)&local_2c);
              unaff_ESI = (CMwCmdFastCallUser *)0x0;
              unaff_EDI = (TiXmlNode *)&DAT_00d71d58;
              SPlugUrlLink::Set(local_24,(CMwCmdScriptVarBool *)&local_2c,1);
            }
            if (local_2c == (char *)0x0) {
              SPlugUrlLink::~SPlugUrlLink(&local_2c,(SPlugUrlLink *)unaff_EDI);
              if (local_2c != PTR_DAT_00bbf7dc) {
                if ((local_2c[-1] & 0x80U) == 0) {
                  pcVar2 = local_2c + -2;
                }
                else {
                  pcVar2 = local_2c + -4;
                }
                operator_delete__(pcVar2);
              }
              ExceptionList = local_4;
              return 0;
            }
          }
        }
      }
    }
  }
  CControlTools::FixLocalUrl((CFastString *)param_4,(CFastStringInt *)&local_2c);
  TiXmlElement::QueryIntAttribute(in_EDX,(TiXmlElement *)"addplayerid",acStack_10,(int *)unaff_EDI);
  if (param_1 != (TiXmlElement *)0x0) {
    local_8 = param_1;
    CControlTools::ControlSetReadOnlyAndDraw((CControlBase *)param_1,0,0);
    p_Var3 = (_func___cdecl_void_ulong *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (param_4 + 0x44,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
    this = CFastBuffer<struct_SControlUrlLink>::AddNewElem
                     (param_4 + 0x44,
                      (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_EBP);
    SPlugUrlLink::operator=(this,local_20,in_stack_ffffffc0);
    *(TiXmlElement **)(this + 0x20) = param_1;
    unaff_ESI = in_stack_0000001c;
    CControlTools::ControlBindEvent
              ((CControlBase *)param_1,0,(CMwNod *)in_stack_0000001c,CGameManialinkPage::OnUrl,
               (ulong)p_Var3);
    iVar4 = (**(code **)(*(int *)param_1 + 0x10))();
    if (iVar4 == 0) {
      CControlTools::ControlBindEvent
                ((CControlBase *)param_1,1,(CMwNod *)in_stack_0000001c,
                 CGameManialinkPage::OnUrlFocusGained,(ulong)p_Var3);
      CControlTools::ControlBindEvent
                ((CControlBase *)param_1,2,(CMwNod *)in_stack_0000001c,
                 CGameManialinkPage::OnUrlFocusLost,(ulong)p_Var3);
    }
    else {
      pCVar5 = operator_new(0x28);
      if (pCVar5 == (CMwCmdFastCallUser *)0x0) {
        pCVar6 = (CMwNod *)0x0;
      }
      else {
        CMwCmdFastCallUser::CMwCmdFastCallUser
                  (pCVar5,in_stack_0000001c,(CMwNod *)CGameManialinkPage::OnUrlFocusGained,p_Var3,
                   (ulong)unaff_ESI);
        pCVar6 = extraout_EAX;
      }
      if (pCVar6 != *(CMwNod **)(param_1 + 0x164)) {
        if (pCVar6 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(pCVar6,(CMwNod *)unaff_ESI);
        }
        if (*(CMwNod **)(param_1 + 0x164) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(param_1 + 0x164),(CMwNod *)unaff_ESI);
        }
        *(CMwNod **)(param_1 + 0x164) = pCVar6;
      }
      pCVar5 = operator_new(0x28);
      if (pCVar5 == (CMwCmdFastCallUser *)0x0) {
        pCVar6 = (CMwNod *)0x0;
      }
      else {
        CMwCmdFastCallUser::CMwCmdFastCallUser
                  (pCVar5,(CMwCmdFastCallUser *)param_4,(CMwNod *)CGameManialinkPage::OnUrlFocusLost
                   ,p_Var3,(ulong)unaff_ESI);
        pCVar6 = extraout_EAX_00;
      }
      if (pCVar6 != *(CMwNod **)(param_1 + 0x168)) {
        if (pCVar6 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(pCVar6,(CMwNod *)unaff_ESI);
        }
        if (*(CMwNod **)(param_1 + 0x168) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(param_1 + 0x168),(CMwNod *)unaff_ESI);
        }
        *(CMwNod **)(param_1 + 0x168) = pCVar6;
      }
    }
  }
  SPlugUrlLink::~SPlugUrlLink(&local_28,(SPlugUrlLink *)unaff_ESI);
  if (local_28 != PTR_DAT_00bbf7dc) {
    if ((local_28[-1] & 0x80) != 0) {
      operator_delete__(local_28 + -4);
      ExceptionList = pvVar7;
      return 1;
    }
    operator_delete__(local_28 + -2);
  }
  ExceptionList = pvVar7;
  return 1;
}
}

// =================================================
// Function: PartBirthParamsInit
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
PartBirthParamsInit(SPartBirthParams *param_1,CMotionParticleType *param_2,SEmitParams *param_3)
{
{
  SPartBirthParams *pSVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  GmVec3 GVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined3 extraout_var;
  GmMat43 *unaff_EBX;
  float unaff_EBP;
  float unaff_ESI;
  GmMat43 *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  GmIso4 *in_stack_00000018;
  GmIso3 *in_stack_00000024;
  undefined4 in_stack_00000028;
  float fVar12;
  GmScaleTrans2 *pGVar13;
  GmIso4 *pGVar14;
  GmIso3 *in_stack_ffffffc8;
  GmIso4 *local_34;
  undefined4 uStack_1c;
  float local_18;
  float local_14;
  float local_10 [4];
  float *pfVar11;
  
  iVar8 = _rand();
  *(float *)(param_1 + 0x48) =
       (((float)iVar8 / (float)_DAT_00b530f8 + (float)iVar8 / (float)_DAT_00b530f8) -
       (float)_DAT_00b2c188) * *(float *)(param_2 + 0x114) + *(float *)(param_2 + 0x110);
  fVar12 = -*(float *)(param_2 + 0xa8);
  fVar2 = *(float *)(param_2 + 0xa8);
  iVar8 = _rand();
  pGVar13 = (GmScaleTrans2 *)
            (((fVar12 + ((float)iVar8 / (float)_DAT_00b530f8) * (fVar2 - fVar12) +
              *(float *)(param_2 + 0xa4)) * (float)_DAT_00b36110) / (float)_DAT_00b36ab8);
  fVar12 = -*(float *)(param_2 + 0xb0);
  fVar2 = *(float *)(param_2 + 0xb0);
  iVar8 = _rand();
  pGVar14 = (GmIso4 *)
            (((fVar12 + ((float)iVar8 / (float)_DAT_00b530f8) * (fVar2 - fVar12) +
              *(float *)(param_2 + 0xac)) * (float)_DAT_00b36110) / (float)_DAT_00b36ab8);
  fVar12 = -*(float *)(param_2 + 0xb8);
  fVar2 = *(float *)(param_2 + 0xb8);
  iVar8 = _rand();
  pSVar1 = param_1 + 4;
  *(float *)param_1 =
       ((fVar12 + ((float)iVar8 / (float)_DAT_00b530f8) * (fVar2 - fVar12) +
        *(float *)(param_2 + 0xb4)) * (float)_DAT_00b36110) / (float)_DAT_00b36ab8;
  GmMat3::SetIdentity(pSVar1,unaff_EDI);
  GmMat3::RotateX(pSVar1,pGVar14,unaff_ESI);
  GmMat3::RotateY(pSVar1,local_34,unaff_EBP);
  GmMat3::SetIdentity(&local_18,unaff_EBX);
  GmMat3::RotateZ(&local_14,in_stack_00000018,fVar12);
  GmMat3::LeftMult(pSVar1,(GmScaleTrans2 *)local_10,pGVar13);
  fVar2 = *(float *)(in_stack_00000024 + 0x30) * *(float *)(param_2 + 0x98);
  fVar12 = *(float *)(in_stack_00000024 + 0x34) * *(float *)(param_2 + 0x9c);
  fVar3 = *(float *)(in_stack_00000024 + 0x38) * *(float *)(param_2 + 0xa0);
  switch(*(undefined4 *)(param_2 + 0x88)) {
  case 0:
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x8c);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x90);
    fVar2 = *(float *)(param_2 + 0x94);
    break;
  case 1:
    local_18 = GmFunc::RandReal(_DAT_00b2c060,1.0);
    local_14 = GmFunc::RandReal(_DAT_00b2c060,1.0);
    local_10[0] = GmFunc::RandReal(_DAT_00b2c060,1.0);
    *(float *)(param_1 + 0x28) = local_18 * fVar2;
    *(float *)(param_1 + 0x2c) = local_14 * fVar12;
    fVar2 = local_10[0] * fVar3;
    break;
  case 2:
    local_18 = *(float *)(in_stack_00000024 + 0x30) * *(float *)(param_2 + 0x98);
    local_14 = *(float *)(in_stack_00000024 + 0x34) * *(float *)(param_2 + 0x9c);
    local_10[0] = *(float *)(in_stack_00000024 + 0x38) * *(float *)(param_2 + 0xa0);
    *(float *)(param_1 + 0x28) = *(float *)(param_2 + 0x8c) * local_18;
    *(float *)(param_1 + 0x2c) = *(float *)(param_2 + 0x90) * local_14;
    fVar2 = *(float *)(param_2 + 0x94) * local_10[0];
    break;
  case 3:
    do {
      iVar8 = _rand();
      fVar4 = (float)_DAT_00b530f8;
      iVar9 = _rand();
      fVar5 = (float)_DAT_00b530f8;
      iVar10 = _rand();
      fVar6 = (float)_DAT_00b33a58;
      local_18 = ((float)iVar10 / (float)_DAT_00b530f8) * fVar6 - 1.0;
      local_14 = ((float)iVar9 / fVar5) * fVar6 - 1.0;
      local_10[0] = fVar6 * ((float)iVar8 / fVar4) - 1.0;
    } while (_DAT_00b2c038 < local_14 * local_14 + local_18 * local_18 + local_10[0] * local_10[0]);
    *(float *)(param_1 + 0x28) = fVar2 * local_18;
    *(float *)(param_1 + 0x2c) = fVar12 * local_14;
    fVar2 = local_10[0] * fVar3;
    break;
  case 4:
    GmFunc::RandReal(0.0,_DAT_00b59b70);
    __CIcos();
    local_18 = (float)extraout_ST0;
    __CIsin();
    local_14 = (float)extraout_ST0_00;
    *(float *)(param_1 + 0x28) = local_18 * fVar2;
    *(float *)(param_1 + 0x2c) = local_14 * fVar12;
    fVar2 = fVar3 * (float)_PTR_00b2c178;
    break;
  default:
    goto switchD_0056335c_default;
  }
  *(float *)(param_1 + 0x30) = fVar2;
switchD_0056335c_default:
  GmIso4::Mult(param_1 + 4,in_stack_00000024,(GmIso3 *)pGVar14);
  if (*(int *)(param_2 + 0xcc) == 0) {
    iVar8 = _rand();
    fVar12 = (((float)iVar8 / (float)_DAT_00b530f8 + (float)iVar8 / (float)_DAT_00b530f8) -
             (float)_DAT_00b2c188) * *(float *)(param_2 + 200) + *(float *)(param_2 + 0xc4);
    *(float *)(param_1 + 0x44) = fVar12;
    fVar12 = fVar12 * *(float *)(param_2 + 0x58);
  }
  else {
    *(float *)(param_1 + 0x44) = *(float *)(param_2 + 0xd0) * fVar3;
    fVar12 = *(float *)(param_2 + 0xd0) * fVar12;
  }
  *(float *)(param_1 + 0x40) = fVar12;
  iVar8 = _rand();
  fVar2 = 1.0;
  *(float *)(param_1 + 0x5c) =
       (((float)iVar8 / (float)_DAT_00b530f8 + (float)iVar8 / (float)_DAT_00b530f8) - 1.0) *
       *(float *)(param_2 + 0x10c) + *(float *)(param_2 + 0x108);
  if (*(int *)(param_2 + 300) != 0) {
    fVar2 = (1.0 - *(float *)(param_2 + 0x130)) * *(float *)(in_stack_00000024 + 0x48) +
            *(float *)(param_2 + 0x130);
  }
  iVar8 = _rand();
  *(float *)(param_1 + 0x68) =
       ((((float)iVar8 / (float)_DAT_00b530f8 + (float)iVar8 / (float)_DAT_00b530f8) -
        (float)_DAT_00b2c188) * *(float *)(param_2 + 0x138) + *(float *)(param_2 + 0x134)) * fVar2;
  iVar8 = _rand();
  pSVar1 = param_1 + 0x34;
  fVar3 = (float)_DAT_00b530f8;
  fVar4 = (float)_DAT_00b2c188;
  fVar2 = *(float *)(param_2 + 0x104);
  fVar12 = *(float *)(param_2 + 0x100);
  *(float *)pSVar1 = 0.0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(float *)(param_1 + 0x3c) =
       (((float)iVar8 / fVar3 + (float)iVar8 / fVar3) - fVar4) * fVar2 + fVar12;
  GmVec3::Mult(pSVar1,(GmIso3 *)(param_1 + 4),in_stack_ffffffc8);
  *(undefined4 *)(param_1 + 0x60) = in_stack_00000028;
  *(float *)pSVar1 = *(float *)pSVar1 + *(float *)(in_stack_00000024 + 0x3c);
  *(float *)(param_1 + 0x38) = *(float *)(in_stack_00000024 + 0x40) + *(float *)(param_1 + 0x38);
  *(float *)(param_1 + 0x3c) = *(float *)(in_stack_00000024 + 0x44) + *(float *)(param_1 + 0x3c);
  if (*(int *)(param_2 + 0x70) == 1) {
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(in_stack_00000024 + 0x4c);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(in_stack_00000024 + 0x50);
    fVar2 = *(float *)(in_stack_00000024 + 0x54);
  }
  else {
    iVar8 = _rand();
    GVar7 = CFuncColorGradient::GetValue
                      (*(CFuncColorGradient **)(param_2 + 0x6c),(CFuncColorGradient *)local_10,
                       ((float)iVar8 / (float)_DAT_00b530f8) * 1.0 + 0.0);
    pfVar11 = (float *)CONCAT31(extraout_var,GVar7);
    *(float *)(param_1 + 0x4c) = *pfVar11 * *(float *)(in_stack_00000024 + 0x4c);
    *(float *)(param_1 + 0x50) = pfVar11[1] * *(float *)(in_stack_00000024 + 0x50);
    fVar2 = pfVar11[2] * *(float *)(in_stack_00000024 + 0x54);
  }
  *(float *)(param_1 + 0x54) = fVar2;
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_2 + 0x118);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(in_stack_00000024 + 0x48);
  iVar8 = *(int *)(param_2 + 0x40);
  if (iVar8 == 0) {
    *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
  }
  else {
    if (iVar8 == 1) {
      *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x4c);
      return;
    }
    if (iVar8 == 2) {
      iVar8 = _rand();
      fVar2 = (float)*(int *)(param_2 + 0x44);
      if (*(int *)(param_2 + 0x44) < 0) {
        fVar2 = fVar2 + _DAT_00c418d0;
      }
      fVar12 = (float)*(int *)(param_2 + 0x48);
      if (*(int *)(param_2 + 0x48) < 0) {
        fVar12 = fVar12 + _DAT_00c418d0;
      }
      uStack_1c = (undefined4)
                  (longlong)
                  ROUND(fVar12 * fVar2 * (((float)iVar8 / (float)_DAT_00b530f8) * 1.0 + 0.0));
      *(undefined4 *)(param_1 + 0x6c) = uStack_1c;
      return;
    }
  }
  return;
}
}

// =================================================
// Function: PartGetColor
// =================================================
void __cdecl
PartGetColor(CMotionParticleType *param_1,SPartBirthParams *param_2,float param_3,float param_4,
            GxColor *param_5)
{
{
  float fVar1;
  float fVar2;
  GmVec3 GVar3;
  undefined3 extraout_var;
  float unaff_EDI;
  float10 extraout_ST0;
  CFuncColorGradient local_c [12];
  float *pfVar4;
  
  if (*(int *)(param_1 + 0x70) == 1) {
    GVar3 = CFuncColorGradient::GetValue(*(CFuncColorGradient **)(param_1 + 0x6c),local_c,param_3);
    pfVar4 = (float *)CONCAT31(extraout_var,GVar3);
    *(float *)param_5 = *pfVar4 * *(float *)(param_2 + 0x4c);
    *(float *)(param_5 + 4) = pfVar4[1] * *(float *)(param_2 + 0x50);
    fVar1 = pfVar4[2] * *(float *)(param_2 + 0x54);
  }
  else {
    *(undefined4 *)param_5 = *(undefined4 *)(param_2 + 0x4c);
    *(undefined4 *)(param_5 + 4) = *(undefined4 *)(param_2 + 0x50);
    fVar1 = *(float *)(param_2 + 0x54);
  }
  *(float *)(param_5 + 8) = fVar1;
  if (*(int *)(param_1 + 0x68) != 0) {
    *(float *)param_5 = *(float *)param_5 * param_4;
    *(float *)(param_5 + 4) = *(float *)(param_5 + 4) * param_4;
    *(float *)(param_5 + 8) = *(float *)(param_5 + 8) * param_4;
  }
  CFuncEnvelope::GetValue
            (*(CFuncEnvelope **)(param_1 + 0x124),(CFuncColorGradient *)param_3,unaff_EDI);
  fVar1 = (float)((float10)*(float *)(param_2 + 0x58) * (float10)param_3 * extraout_ST0);
  fVar2 = 0.0;
  if ((fVar1 < 0.0 == (fVar1 == 0.0)) &&
     (fVar2 = fVar1, !NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0))) {
    fVar2 = 1.0;
  }
  *(float *)(param_5 + 0xc) = fVar2;
  if (*(int *)(param_1 + 0x74) != 0) {
    *(float *)param_5 = *(float *)param_5 * fVar2;
    *(float *)(param_5 + 4) = *(float *)(param_5 + 4) * fVar2;
    *(float *)(param_5 + 8) = fVar2 * *(float *)(param_5 + 8);
    return;
  }
  return;
}
}

// =================================================
// Function: PartGetLoc
// =================================================
void __cdecl
PartGetLoc(CMotionParticleType *param_1,SPartBirthParams *param_2,float param_3,float param_4,
          GmIso4 *param_5)
{
{
  int unaff_EDI;
  
  PartGetPos(param_1,param_2,param_3,param_4,(GmVec3 *)(param_5 + 0x24));
  GmMat3::Set(param_5,(CMwCmdScriptVarBool *)(param_2 + 4),unaff_EDI);
  return;
}
}

// =================================================
// Function: PartGetPos
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
PartGetPos(CMotionParticleType *param_1,SPartBirthParams *param_2,float param_3,float param_4,
          GmVec3 *param_5)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float10 extraout_ST0;
  
  if (_DAT_00b59b68 < *(float *)(param_2 + 0x68)) {
    *(undefined4 *)param_5 = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)(param_5 + 4) = *(undefined4 *)(param_2 + 0x2c);
    *(undefined4 *)(param_5 + 8) = *(undefined4 *)(param_2 + 0x30);
    fVar1 = *(float *)(param_2 + 0x48);
    fVar2 = *(float *)(param_2 + 0x68);
    fVar3 = (param_3 / fVar2) * 0.0;
    *(float *)param_5 = *(float *)param_5 + fVar3;
    *(float *)(param_5 + 4) = *(float *)(param_5 + 4) + fVar1 * (param_3 / fVar2);
    *(float *)(param_5 + 8) = *(float *)(param_5 + 8) + fVar3;
    fVar1 = *(float *)(param_2 + 0x48);
    fVar2 = *(float *)(param_2 + 0x68);
    fVar6 = (1.0 / fVar2) * 0.0;
    fVar3 = *(float *)(param_2 + 0x34);
    fVar4 = *(float *)(param_2 + 0x38);
    fVar5 = *(float *)(param_2 + 0x3c);
    __CIexp();
    fVar7 = ((float)extraout_ST0 - (float)_DAT_00b2c188) / *(float *)(param_2 + 0x68);
    *(float *)param_5 = *(float *)param_5 + fVar7 * (fVar6 - fVar3);
    *(float *)(param_5 + 4) = *(float *)(param_5 + 4) + (fVar1 * (1.0 / fVar2) - fVar4) * fVar7;
    *(float *)(param_5 + 8) = *(float *)(param_5 + 8) + fVar7 * (fVar6 - fVar5);
    return;
  }
  *(undefined4 *)param_5 = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_5 + 4) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_5 + 8) = *(undefined4 *)(param_2 + 0x30);
  fVar3 = (float)_DAT_00b313b8;
  fVar1 = *(float *)(param_2 + 0x48);
  fVar2 = *(float *)param_5;
  *(float *)param_5 = fVar2 + 0.0;
  *(float *)(param_5 + 4) = *(float *)(param_5 + 4) + param_3 * param_3 * fVar3 * fVar1;
  fVar1 = *(float *)(param_5 + 8);
  *(float *)(param_5 + 8) = fVar1 + 0.0;
  fVar3 = *(float *)(param_2 + 0x38);
  fVar4 = *(float *)(param_2 + 0x3c);
  *(float *)param_5 = fVar2 + 0.0 + *(float *)(param_2 + 0x34) * param_3;
  *(float *)(param_5 + 4) = *(float *)(param_5 + 4) + fVar3 * param_3;
  *(float *)(param_5 + 8) = fVar1 + 0.0 + fVar4 * param_3;
  return;
}
}

// =================================================
// Function: PartGetPrecalcPos
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl PartGetPrecalcPos(SEmitterPrecalc *param_1,ulong param_2,float param_3,GmVec3 *param_4)
{
{
  SEmitterPrecalc *this;
  float fVar1;
  float fVar2;
  float fVar3;
  SEmitterPrecalc *pSVar4;
  float fVar5;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  ulong unaff_EDI;
  ushort in_FPUControlWord;
  float *in_stack_00000018;
  int local_8;
  
  pSVar4 = param_1;
  fVar1 = (float)*(int *)param_1;
  if (*(int *)param_1 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  param_1 = (SEmitterPrecalc *)(uint)in_FPUControlWord;
  fVar5 = (float)((uint)param_1 | 0xc00);
  local_8 = (int)(longlong)ROUND(param_3 * fVar1);
  this = pSVar4 + 0x18;
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           (*(int *)(pSVar4 + 8) * param_2 + local_8);
  pSVar6 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this,pCVar8 + 1,unaff_EDI);
  pSVar7 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this,pCVar8,unaff_ESI);
  *in_stack_00000018 = *(float *)pSVar6 - *(float *)pSVar7;
  in_stack_00000018[1] = *(float *)(pSVar6 + 4) - *(float *)(pSVar7 + 4);
  in_stack_00000018[2] = *(float *)(pSVar6 + 8) - *(float *)(pSVar7 + 8);
  fVar1 = *in_stack_00000018;
  *in_stack_00000018 = fVar5 * fVar1;
  fVar2 = in_stack_00000018[1];
  in_stack_00000018[1] = fVar5 * fVar2;
  fVar3 = in_stack_00000018[2];
  in_stack_00000018[2] = fVar3 * fVar5;
  *in_stack_00000018 = *(float *)pSVar7 + fVar5 * fVar1;
  in_stack_00000018[1] = *(float *)(pSVar7 + 4) + fVar5 * fVar2;
  in_stack_00000018[2] = fVar3 * fVar5 + *(float *)(pSVar7 + 8);
  return;
}
}

// =================================================
// Function: PartGetPrecalcSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
PartGetPrecalcSpeed(SEmitterPrecalc *param_1,ulong param_2,float param_3,GmVec3 *param_4)
{
{
  float fVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  ulong unaff_EDI;
  float *in_stack_00000018;
  int local_8;
  
  fVar1 = (float)*(int *)param_1;
  if (*(int *)param_1 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  local_8 = (int)(longlong)ROUND(fVar1 * param_3);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           (local_8 + *(int *)(param_1 + 8) * param_2);
  pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (param_1 + 0x18,pCVar4,unaff_EDI);
  pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (param_1 + 0x18,pCVar4 + 1,unaff_ESI);
  *in_stack_00000018 = *(float *)pSVar3 - *(float *)pSVar2;
  in_stack_00000018[1] = *(float *)(pSVar3 + 4) - *(float *)(pSVar2 + 4);
  in_stack_00000018[2] = *(float *)(pSVar3 + 8) - *(float *)(pSVar2 + 8);
  fVar1 = (float)*(int *)param_1;
  if (*(int *)param_1 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  *in_stack_00000018 = fVar1 * *in_stack_00000018;
  in_stack_00000018[1] = in_stack_00000018[1] * fVar1;
  in_stack_00000018[2] = fVar1 * in_stack_00000018[2];
  return;
}
}

// =================================================
// Function: PartGetSize
// =================================================
void __cdecl
PartGetSize(CMotionParticleType *param_1,SPartBirthParams *param_2,float param_3,float param_4,
           GmVec2 *param_5)
{
{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float unaff_ESI;
  float unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float *in_stack_00000018;
  float in_stack_0000001c;
  
  pfVar2 = in_stack_00000018;
  CFuncEnvelope::GetValue
            (*(CFuncEnvelope **)(param_1 + 0xe4),(CFuncColorGradient *)param_3,unaff_EDI);
  pfVar1 = (float *)(float)extraout_ST0;
  in_stack_00000018[1] = (float)pfVar1;
  pfVar3 = pfVar1;
  if (*(int *)(param_1 + 0xe8) != 0) {
    CFuncEnvelope::GetValue
              (*(CFuncEnvelope **)(param_1 + 0xec),(CFuncColorGradient *)param_4,unaff_ESI);
    in_stack_0000001c = (float)extraout_ST0_00;
    pfVar1 = (float *)param_3;
    pfVar3 = in_stack_00000018;
  }
  in_stack_00000018 = pfVar3;
  *pfVar2 = in_stack_0000001c;
  *pfVar2 = in_stack_0000001c * *(float *)((int)param_4 + 0x40);
  pfVar2[1] = (float)pfVar1 * *(float *)((int)param_4 + 0x44);
  if (*(int *)(param_1 + 0xdc) == 0) {
    in_stack_00000018 = (float *)0x3f800000;
  }
  *pfVar2 = (float)in_stack_00000018 * *pfVar2;
  pfVar2[1] = (float)in_stack_00000018 * pfVar2[1];
  return;
}
}

// =================================================
// Function: PartGetSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
PartGetSpeed(CMotionParticleType *param_1,SPartBirthParams *param_2,float param_3,float param_4,
            GmVec3 *param_5)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 extraout_ST0;
  
  *(undefined4 *)param_5 = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_5 + 4) = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_5 + 8) = *(undefined4 *)(param_2 + 0x3c);
  fVar1 = *(float *)(param_2 + 0x48);
  if (_DAT_00b59b68 < *(float *)(param_2 + 0x68)) {
    fVar1 = fVar1 / *(float *)(param_2 + 0x68);
    fVar2 = *(float *)param_5;
    *(float *)param_5 = fVar2 - 0.0;
    fVar5 = *(float *)(param_5 + 4) - fVar1;
    *(float *)(param_5 + 4) = fVar5;
    fVar3 = *(float *)(param_5 + 8);
    *(float *)(param_5 + 8) = fVar3 - 0.0;
    __CIexp();
    fVar4 = (float)extraout_ST0;
    *(float *)param_5 = fVar4 * (fVar2 - 0.0) + 0.0;
    *(float *)(param_5 + 4) = fVar5 * fVar4 + fVar1;
    *(float *)(param_5 + 8) = (fVar3 - 0.0) * fVar4 + 0.0;
    return;
  }
  *(float *)param_5 = *(float *)param_5 + 0.0;
  *(float *)(param_5 + 4) = *(float *)(param_5 + 4) + fVar1 * param_3;
  *(float *)(param_5 + 8) = *(float *)(param_5 + 8) + 0.0;
  return;
}
}

// =================================================
// Function: PartGetState
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl PartGetState(ulong param_1,SPart *param_2,SPartGroup *param_3,SPartState *param_4)
{
{
  float fVar1;
  uint uVar2;
  CMotionParticleType *pCVar3;
  CFuncEnvelope *this;
  float fVar4;
  int iVar5;
  SCasterCat *pSVar6;
  GmVec3 *unaff_EBX;
  GmVec3 *unaff_EBP;
  int unaff_ESI;
  SPartBirthParams *pSVar7;
  float unaff_EDI;
  float10 extraout_ST0;
  float unaff_retaddr;
  SPartGroup *pSVar8;
  SPartState *pSVar9;
  SPartState *pSVar10;
  
  uVar2 = *(uint *)param_2;
  if ((uVar2 <= param_1) && (param_1 < *(uint *)(param_2 + 4))) {
    fVar1 = (float)(int)(param_1 - uVar2);
    if ((int)(param_1 - uVar2) < 0) {
      fVar1 = fVar1 + _DAT_00c418d0;
    }
    iVar5 = *(uint *)(param_2 + 4) - uVar2;
    fVar4 = (float)iVar5;
    if (iVar5 < 0) {
      fVar4 = fVar4 + _DAT_00c418d0;
    }
    pCVar3 = *(CMotionParticleType **)(param_3 + 0xc);
    this = *(CFuncEnvelope **)(pCVar3 + 100);
    *(float *)param_4 = fVar1 / fVar4;
    CFuncEnvelope::GetValue(this,*(CFuncColorGradient **)(param_2 + 0x74),unaff_EDI);
    fVar1 = (float)extraout_ST0;
    if (*(ulong *)(param_2 + 0xc) == 0xffffffff) {
      PartGetLoc(pCVar3,(SPartBirthParams *)(param_2 + 0x10),(float)param_3,fVar1,
                 (GmIso4 *)(param_4 + 4));
      PartGetSpeed(*(CMotionParticleType **)(param_3 + 0xc),(SPartBirthParams *)(param_2 + 0x10),
                   (float)param_3,fVar1,(GmVec3 *)(param_4 + 0x34));
    }
    else {
      pSVar9 = param_4 + 0x28;
      pSVar8 = param_3;
      pSVar6 = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                         (param_3 + 0x1c,
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_2 + 8),
                          *(ulong *)(param_2 + 0xc));
      PartGetPrecalcPos((SEmitterPrecalc *)(pSVar6 + 0x40),(ulong)pSVar8,(float)pSVar9,unaff_EBP);
      pSVar9 = param_4 + 0x34;
      pSVar10 = param_4;
      pSVar6 = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                         (param_3 + 0x1c,
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_2 + 8),
                          *(ulong *)(param_2 + 0xc));
      PartGetPrecalcSpeed((SEmitterPrecalc *)(pSVar6 + 0x40),(ulong)pSVar10,(float)pSVar9,unaff_EBX)
      ;
      GmMat3::Set(param_4 + 4,(CMwCmdScriptVarBool *)(param_2 + 0x14),unaff_ESI);
    }
    pSVar7 = (SPartBirthParams *)(param_2 + 0x10);
    PartGetSize(*(CMotionParticleType **)(param_3 + 0xc),pSVar7,unaff_retaddr,fVar1,
                (GmVec2 *)(param_4 + 0x40));
    pCVar3 = *(CMotionParticleType **)(param_3 + 0xc);
    *(float *)(param_4 + 0x48) = *(float *)(param_2 + 0x6c) * (float)param_3 + *(float *)pSVar7;
    PartGetColor(pCVar3,pSVar7,unaff_retaddr,fVar1,(GxColor *)(param_4 + 0x4c));
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: PlugTree_SetRenderBeforeForSpecialFidParametrization
// =================================================
void __cdecl
PlugTree_SetRenderBeforeForSpecialFidParametrization
          (CPlugTree *param_1,CSystemFidParameters *param_2,CSystemFidParameters *param_3)
{
{
  SCasterCat SVar1;
  SCasterCat *pSVar2;
  SSamplerState *pSVar3;
  uint uVar4;
  int iVar5;
  ulong unaff_ESI;
  CSystemFidParameters *pCVar6;
  uint uVar7;
  SParam *unaff_EDI;
  CSystemFidParameters *in_stack_00000010;
  CSystemFidParameters *pCStack_4;
  
  pSVar2 = CFastBuffer<unsigned_short>::operator[]
                     (param_2 + 4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,unaff_ESI);
  SVar1 = pSVar2[1];
  param_3 = (CSystemFidParameters *)0x0;
  pCVar6 = param_2 + 4;
  if ((CSystemFidParameters *)(uint)(byte)SVar1 != (CSystemFidParameters *)0x0) {
    do {
      pSVar3 = CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
               GetElemInCat(pCVar6,(CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                                    *)param_3,1,(ulong)unaff_EDI);
      pCVar6 = *(CSystemFidParameters **)pSVar3;
      iVar5 = *(int *)(pCVar6 + 0x14);
      if ((((iVar5 != 0) && (*(int *)(iVar5 + 0x38) == DAT_00cce628)) &&
          (*(int *)(iVar5 + 0x3c) == DAT_00cce62c)) &&
         ((*(int *)(iVar5 + 0x40) == DAT_00cce630 && (*(int *)(iVar5 + 0x44) == DAT_00cce634)))) {
        unaff_EDI = (SParam *)0x84936f;
        uVar4 = (**(code **)(**(int **)(param_2 + 0x94) + 0x7c))();
        uVar7 = 0;
        if (uVar4 != 0) {
          do {
            iVar5 = (**(code **)(**(int **)(param_2 + 0x94) + 0x8c))(uVar7);
            if (((iVar5 != 0) && (iVar5 = *(int *)(*(int *)(iVar5 + 0x1c) + 0x48), iVar5 != 0)) &&
               (*(int *)(iVar5 + 8) == *(int *)(*(int *)(pCVar6 + 0x14) + 0x48))) {
              *(uint *)(param_2 + 0x9c) = *(uint *)(param_2 + 0x9c) | 0x1000;
              if (in_stack_00000010 != (CSystemFidParameters *)0x0) {
                CSystemFidParameters::AddParam(in_stack_00000010,pCVar6,unaff_EDI);
              }
              break;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar4);
        }
      }
      param_3 = param_3 + 1;
      pCVar6 = pCStack_4;
    } while (param_3 < (CSystemFidParameters *)(uint)(byte)SVar1);
  }
  return;
}
}

// =================================================
// Function: PolarToVskCartesian
// =================================================
void __cdecl PolarToVskCartesian(GmVec2 *param_1,GmVec2 *param_2)
{
{
  float fVar1;
  float fVar2;
  float *unaff_ESI;
  float *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  __CIsin();
  fVar1 = *unaff_ESI;
  __CIcos();
  fVar2 = *unaff_ESI;
  *unaff_EDI = -((float)extraout_ST0 * fVar1);
  unaff_EDI[1] = (float)extraout_ST0_00 * fVar2;
  return;
}
}

// =================================================
// Function: PrepareStringForSystemCall
// =================================================
void __cdecl PrepareStringForSystemCall(CFastStringInt *param_1,wchar_t *param_2)
{
{
  uint uVar1;
  uint uVar2;
  wchar_t *unaff_EDI;
  
  uVar1 = *(uint *)param_1;
  if (uVar1 < 0x104) {
    uVar2 = uVar1;
    if (uVar1 == 0) {
      *unaff_EDI = L'\0';
      unaff_EDI[1] = L'\0';
      return;
    }
  }
  else {
    uVar2 = 0x103;
  }
  if (*(short *)(*(int *)(param_1 + 4) + -2 + uVar1 * 2) == 0x5c) {
    uVar2 = uVar2 - 1;
  }
  _memset(unaff_EDI,0,0x106);
  _wcsncpy_s(unaff_EDI,0x106,*(wchar_t **)(param_1 + 4),uVar2);
  return;
}
}

// =================================================
// Function: QuadGetIcons
// =================================================
CFuncEnum * __cdecl QuadGetIcons(CControlQuad *param_1)
{
{
  CControlStyle *pCVar1;
  CControlBase *unaff_ESI;
  CControlBase *unaff_retaddr;
  CControlBase *in_stack_00000008;
  
  pCVar1 = CControlBase::GetStyle(unaff_ESI,unaff_retaddr);
  if (pCVar1 == (CControlStyle *)0x0) {
    return (CFuncEnum *)0x0;
  }
  pCVar1 = CControlBase::GetStyle(unaff_ESI,(CControlBase *)param_1);
  if (*(int *)(pCVar1 + 0xec) != 0) {
    pCVar1 = CControlBase::GetStyle(unaff_ESI,in_stack_00000008);
    return *(CFuncEnum **)(pCVar1 + 0xec);
  }
  pCVar1 = CControlBase::GetStyle(unaff_ESI,in_stack_00000008);
  return *(CFuncEnum **)(pCVar1 + 0xc0);
}
}

// =================================================
// Function: QuadSetStyle
// =================================================
void __cdecl
QuadSetStyle(TiXmlElement *param_1,CControlBase *param_2,SBuildPageParams *param_3,
            SManialinkFormat *param_4,SDico *param_5)
{
{
  char cVar1;
  CControlStyleSheet *pCVar2;
  char *pcVar3;
  SDico *pSVar4;
  int iVar5;
  char *pcVar6;
  CSystemData *pCVar7;
  CMwNod *extraout_EAX;
  CPlugMaterial *pCVar8;
  undefined *puVar9;
  int *unaff_EBX;
  char *unaff_EBP;
  SStringParam *unaff_ESI;
  CMwNodRef<class_CControlStyle> *unaff_EDI;
  CMwNod *this;
  TiXmlElement *in_stack_00000018;
  void *in_stack_0000001c;
  TiXmlElement *in_stack_00000020;
  int in_stack_00000024;
  TiXmlElement *in_stack_0000002c;
  CMwCmdScriptVarBool *in_stack_00000030;
  int in_stack_00000034;
  SManialinkFormat *in_stack_00000038;
  CMwNod *this_00;
  CMwNod *pCVar10;
  char *in_stack_ffffff9c;
  int *piVar11;
  char *in_stack_ffffffa0;
  SStringParam *pSVar12;
  int *piVar13;
  CMwNod *in_stack_ffffffac;
  int local_50;
  char *local_48;
  char *local_44;
  int local_40;
  CControlStyle *local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined *local_30;
  int local_2c;
  char *local_28;
  int local_24;
  undefined *puStack_20;
  undefined1 auStack_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00ac0a13;
  local_c = ExceptionList;
  pCVar2 = (CControlStyleSheet *)(DAT_00cca150 ^ (uint)&stack0xffffff88);
  ExceptionList = &local_c;
  this_00 = (CMwNod *)0x0;
  local_4 = 0;
  ElemGetStyle(*(TiXmlElement **)(param_3 + 0xc),pCVar2,unaff_EDI);
  if (this_00 == (CMwNod *)0x0) {
    piVar13 = (int *)0x0;
    local_4 = CONCAT31(local_4._1_3_,1);
    pCVar10 = this_00;
    pSVar12 = (SStringParam *)PTR_DAT_00bbf7d8;
    local_44 = TiXmlElement::Attribute
                         (param_1,(TiXmlElement *)"image",(char *)pCVar2,(int *)unaff_EDI);
    if (local_44 == (char *)0x0) {
      local_40 = 0;
    }
    else {
      pcVar3 = local_44;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      local_40 = (int)pcVar3 - (int)(local_44 + 1);
    }
    CFastString::SetString((CFastString *)&stack0xffffffac,(CFastStringInt *)&local_44,unaff_ESI);
    if (local_50 == 0) {
      pSVar4 = (SDico *)TiXmlElement::Attribute
                                  (param_1,(TiXmlElement *)"imageid",unaff_EBP,unaff_EBX);
      iVar5 = DicoGetText(pSVar4,(char *)&local_48,(CFastStringInt *)pCVar10);
      if (iVar5 == 0) {
        CXmlEngine::ReadAssociatedText(param_1,(CFastStringInt *)&local_48);
        puVar9 = PTR_DAT_00d34100;
        CFastString::TrimLeft
                  ((CFastString *)&local_48,(CFastString *)PTR_DAT_00d34100,(char *)pCVar10);
        CFastString::TrimRight((CFastString *)&local_44,(CFastString *)puVar9,in_stack_ffffff9c);
        param_1 = in_stack_00000020;
      }
    }
    local_38 = 0;
    local_34 = PTR_DAT_00bbf7d8;
    piVar11 = (int *)&DAT_00b64530;
    in_stack_00000018 = (TiXmlElement *)CONCAT31(in_stack_00000018._1_3_,2);
    pCVar10 = (CMwNod *)0x71ecd8;
    pcVar3 = TiXmlElement::Attribute
                       (param_1,(TiXmlElement *)&DAT_00b64530,in_stack_ffffffa0,piVar13);
    if (pcVar3 != (char *)0x0) {
      pcVar6 = pcVar3;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      local_24 = (int)pcVar6 - (int)(pcVar3 + 1);
      local_28 = pcVar3;
      CFastString::SetString((CFastString *)&local_30,(CFastStringInt *)&local_28,pSVar12);
    }
    pSVar12 = (SStringParam *)0x71ed16;
    pCVar7 = MediaDataFindOrAdd((CFastString *)&local_34,(CFastString *)&local_2c,
                                (SBuildPageParams *)in_stack_ffffffac);
    if (pCVar7 != (CSystemData *)0x0) {
      *(uint *)(pCVar7 + 0x24) = DAT_00d68ef4 + 1000;
      *(uint *)(in_stack_00000030 + 0xfc) = *(uint *)(in_stack_00000030 + 0xfc) | 0x800;
      pcVar3 = (char *)0x71ed4d;
      local_3c = operator_new(0x184);
      if (local_3c == (CControlStyle *)0x0) {
        this = (CMwNod *)0x0;
      }
      else {
        CControlStyle::CControlStyle(local_3c,(CControlStyle *)in_stack_ffffffac);
        this = extraout_EAX;
      }
      in_stack_00000024 = CONCAT31(in_stack_00000024._1_3_,2);
      if (this != (CMwNod *)0x0) {
        CMwNod::MwAddRef(this,in_stack_ffffffac);
        this_00 = this;
        local_3c = (CControlStyle *)this;
      }
      piVar13 = (int *)0x71ed8b;
      (**(code **)(*(int *)this_00 + 0x4c))();
      *(int *)(this_00 + 0x38) = 0;
      *(int *)(this_00 + 0x3c) = 0;
      *(int *)(this_00 + 0x40) = *(int *)(in_stack_00000024 + 0x28);
      *(int *)(this_00 + 0x44) = *(int *)(in_stack_00000024 + 0x2c);
      *(int *)(this_00 + 0x48) = *(int *)(in_stack_00000024 + 0x30);
      pCVar8 = MaterialCreateFromSystemData((CSystemData *)pCVar10);
      if (pCVar8 != *(CPlugMaterial **)(this_00 + 0x28)) {
        if (pCVar8 != (CPlugMaterial *)0x0) {
          CMwNod::MwAddRef((CMwNod *)pCVar8,pCVar10);
        }
        if (*(CMwNod **)(this_00 + 0x28) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x28),pCVar10);
        }
        *(CPlugMaterial **)(this_00 + 0x28) = pCVar8;
      }
      local_38 = 0;
      local_34 = PTR_DAT_00bbf7d8;
      local_48 = TiXmlElement::Attribute
                           (in_stack_00000018,(TiXmlElement *)"imagefocus",(char *)pCVar10,piVar11);
      if (local_48 == (char *)0x0) {
        local_44 = (char *)0x0;
      }
      else {
        local_44 = local_48;
        do {
          cVar1 = *local_44;
          local_44 = local_44 + 1;
        } while (cVar1 != '\0');
        local_44 = local_44 + -(int)(local_48 + 1);
      }
      CFastString::SetString((CFastString *)&local_30,(CFastStringInt *)&local_48,pSVar12);
      if (local_2c == 0) {
        pSVar4 = (SDico *)TiXmlElement::Attribute
                                    (in_stack_00000018,(TiXmlElement *)"imagefocusid",pcVar3,piVar13
                                    );
        DicoGetText(pSVar4,(char *)&local_24,(CFastStringInt *)in_stack_ffffffac);
      }
      pCVar7 = MediaDataFindOrAdd((CFastString *)&local_24,(CFastString *)&local_2c,
                                  (SBuildPageParams *)in_stack_ffffffac);
      if (pCVar7 != (CSystemData *)0x0) {
        *(uint *)(pCVar7 + 0x24) = DAT_00d68ef4 + 1000;
        pCVar8 = MaterialCreateFromSystemData((CSystemData *)in_stack_ffffffac);
        if (pCVar8 != *(CPlugMaterial **)(this_00 + 0x34)) {
          if (pCVar8 != (CPlugMaterial *)0x0) {
            CMwNod::MwAddRef((CMwNod *)pCVar8,in_stack_ffffffac);
          }
          if (*(CMwNod **)(this_00 + 0x34) != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x34),in_stack_ffffffac);
          }
          *(CPlugMaterial **)(this_00 + 0x34) = pCVar8;
        }
      }
      if (puStack_20 != PTR_DAT_00bbf7d8) {
        puVar9 = puStack_20 + -1;
        if ((puStack_20[-1] & 0x80) != 0) {
          puVar9 = puStack_20 + -4;
        }
        operator_delete__(puVar9);
      }
    }
    if (local_28 != PTR_DAT_00bbf7d8) {
      pcVar3 = local_28 + -1;
      if ((local_28[-1] & 0x80U) != 0) {
        pcVar3 = local_28 + -4;
      }
      operator_delete__(pcVar3);
      local_2c = 0;
      local_28 = PTR_DAT_00bbf7d8;
    }
    if (local_30 != PTR_DAT_00bbf7d8) {
      puVar9 = local_30 + -1;
      if ((local_30[-1] & 0x80) != 0) {
        puVar9 = local_30 + -4;
      }
      operator_delete__(puVar9);
    }
    if (this_00 == (CMwNod *)0x0) {
      SManialinkFormat::SManialinkFormat(auStack_1c,in_stack_00000038);
      ElemModifyManialinkFormat
                (in_stack_0000002c,*(CControlStyleSheet **)(in_stack_00000034 + 0xc),
                 (SManialinkFormat *)in_stack_ffffffac);
      SetControlBg((CControlBase *)in_stack_00000030,(SManialinkFormat *)in_stack_0000002c);
      if (in_stack_00000018 != (TiXmlElement *)0x0) {
        CMwNod::MwRelease((CMwNod *)in_stack_00000018,in_stack_ffffffac);
      }
      goto LAB_0071ef91;
    }
  }
  CControlBase::CStyleSheetElem<class_CControlStyle>::Set
            (in_stack_00000030 + 0x110,in_stack_00000030,(int)this_00);
LAB_0071ef91:
  if (this_00 != (CMwNod *)0x0) {
    CMwNod::MwRelease(this_00,in_stack_ffffffac);
  }
  ExceptionList = in_stack_0000001c;
  return;
}
}

// =================================================
// Function: ReadNextUtf8Char
// =================================================
ulong __cdecl ReadNextUtf8Char(char **param_1)
{
{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *unaff_ESI;
  
  pbVar2 = (byte *)*unaff_ESI;
  bVar1 = *pbVar2;
  do {
    uVar3 = (uint)bVar1;
    if (uVar3 == 0) {
      *unaff_ESI = *unaff_ESI + 1;
      return 0;
    }
    if (uVar3 < 0x80) {
      *unaff_ESI = *unaff_ESI + 1;
      return uVar3;
    }
    if (uVar3 < 0xc2) {
LAB_00902ecd:
      *unaff_ESI = *unaff_ESI + 1;
    }
    else {
      if (uVar3 < 0xe0) {
        bVar1 = pbVar2[1];
        if ((((((bVar1 & 0xc0) != 0x80) && (bVar1 != 10)) && (bVar1 != 9)) &&
            ((bVar1 < 0x20 || (0x2f < bVar1)))) &&
           (((bVar1 < 0x3a || (0x3f < bVar1)) && ((bVar1 < 0x7b || (0x7d < bVar1)))))) {
          pbVar2[1] = bVar1 & 0x3f | 0x80;
        }
        if ((bVar1 ^ 0x80) < 0x40) {
          *unaff_ESI = *unaff_ESI + 2;
          return bVar1 ^ 0x80 | (uVar3 & 0x1f) << 6;
        }
        goto LAB_00902ecd;
      }
      if (0xef < uVar3) {
        if (uVar3 < 0xf8) {
          if ((((pbVar2[1] ^ 0x80) < 0x40) && ((pbVar2[2] ^ 0x80) < 0x40)) &&
             (((pbVar2[3] ^ 0x80) < 0x40 && ((0xf0 < uVar3 || (0x8f < pbVar2[1])))))) {
            *unaff_ESI = *unaff_ESI + 4;
            uVar3 = pbVar2[1] ^ 0x80 | (uVar3 & 7) << 6;
            uVar5 = (uint)pbVar2[2];
            uVar4 = (uint)pbVar2[3];
            goto LAB_00902f23;
          }
        }
        else if (uVar3 < 0xfc) {
          if (((((pbVar2[1] ^ 0x80) < 0x40) && ((pbVar2[2] ^ 0x80) < 0x40)) &&
              ((pbVar2[3] ^ 0x80) < 0x40)) &&
             (((pbVar2[4] ^ 0x80) < 0x40 && ((0xf8 < uVar3 || (0x87 < pbVar2[1])))))) {
            *unaff_ESI = *unaff_ESI + 5;
            uVar3 = (pbVar2[1] ^ 0x80 | (uVar3 & 3) << 6) << 6 | pbVar2[2] ^ 0x80;
            uVar5 = (uint)pbVar2[3];
            uVar4 = (uint)pbVar2[4];
LAB_00902f23:
            return (uVar3 << 6 | uVar5 ^ 0x80) << 6 | uVar4 ^ 0x80;
          }
        }
        else if ((((uVar3 < 0xfe) && ((pbVar2[1] ^ 0x80) < 0x40)) && ((pbVar2[2] ^ 0x80) < 0x40)) &&
                ((((pbVar2[3] ^ 0x80) < 0x40 && ((pbVar2[4] ^ 0x80) < 0x40)) &&
                 (((pbVar2[5] ^ 0x80) < 0x40 && ((0xfc < uVar3 || (0x83 < pbVar2[1])))))))) {
          *unaff_ESI = *unaff_ESI + 6;
          uVar3 = ((pbVar2[1] ^ 0xffffff80 | (uVar3 & 1) << 6) << 6 | pbVar2[2] ^ 0x80) << 6 |
                  pbVar2[3] ^ 0x80;
          uVar5 = (uint)pbVar2[4];
          uVar4 = (uint)pbVar2[5];
          goto LAB_00902f23;
        }
        goto LAB_00902ecd;
      }
      if (((0x3f < (pbVar2[1] ^ 0x80)) || (0x3f < (pbVar2[2] ^ 0x80))) ||
         ((uVar3 < 0xe1 && (pbVar2[1] < 0xa0)))) goto LAB_00902ecd;
      *unaff_ESI = *unaff_ESI + 3;
      uVar3 = (pbVar2[1] ^ 0x80 | (uVar3 & 0xf) << 6) << 6 | pbVar2[2] ^ 0x80;
      if (uVar3 != 0xfeff) {
        return uVar3;
      }
    }
    pbVar2 = (byte *)*unaff_ESI;
    bVar1 = *pbVar2;
  } while( true );
}
}

// =================================================
// Function: RecursiveSetRooted
// =================================================
void __cdecl RecursiveSetRooted(CPlugTree *param_1)
{
{
  uint uVar1;
  int iVar2;
  CPlugTree *pCVar3;
  int unaff_EDI;
  uint uVar4;
  
  CPlugTree::SetIsRooted(param_1,(CPlugTree *)0x1,unaff_EDI);
  uVar1 = (**(code **)(*(int *)param_1 + 0x7c))();
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = (**(code **)(*(int *)param_1 + 0x80))(uVar4);
      if ((*(uint *)(iVar2 + 0x9c) & 0x8000) == 0) {
        pCVar3 = (CPlugTree *)(**(code **)(*(int *)param_1 + 0x80))(uVar4);
        RecursiveSetRooted(pCVar3);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return;
}
}

// =================================================
// Function: RecursiveSetSolid
// =================================================
void __cdecl RecursiveSetSolid(CPlugTree *param_1,CPlugSolid *param_2)
{
{
  uint uVar1;
  CPlugTree *pCVar2;
  ulong *unaff_EBX;
  uchar **unaff_EBP;
  ulong unaff_ESI;
  uint uVar3;
  ulong unaff_EDI;
  CPlugSolid *pCVar4;
  
  CInputEventsStore::Lock(param_1,(CDx9DynamicVB *)param_2,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX);
  uVar1 = (**(code **)(*(int *)param_1 + 0x7c))();
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      pCVar4 = param_2;
      pCVar2 = (CPlugTree *)(**(code **)(*(int *)param_1 + 0x80))(uVar3);
      RecursiveSetSolid(pCVar2,pCVar4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}
}

// =================================================
// Function: RecursiveSetUnassigned
// =================================================
void __cdecl RecursiveSetUnassigned(CPlugTree *param_1)
{
{
  CPlugTree *pCVar1;
  CMwId *pCVar2;
  uint uVar3;
  CPlugTree *this;
  CPlugTree *extraout_EAX;
  CPlugTree *unaff_EDI;
  uint uVar4;
  CPlugTree *pCVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  pCVar1 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4d88;
  local_c = ExceptionList;
  pCVar2 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  uVar3 = (**(code **)(*(int *)param_1 + 0x7c))();
  uVar4 = 0;
  if (uVar3 != 0) {
    do {
      this = (CPlugTree *)(**(code **)(*(int *)pCVar1 + 0x80))(uVar4);
      if ((*(uint *)(this + 0x9c) & 0x8000) == 0) {
        CMwId::CMwId(&param_1,pCVar2);
        pCVar5 = extraout_EAX;
        CPlugTree::SetPlugId(this,extraout_EAX,(CMwId *)unaff_EDI);
        param_1 = (CPlugTree *)0xffffffff;
        OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar5);
        pCVar2 = (CMwId *)0x849b8b;
        RecursiveSetUnassigned(this);
        unaff_EDI = this;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: RecursiveSortFidsTrees
// =================================================
void __cdecl RecursiveSortFidsTrees(CSystemFids *param_1)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CSystemFids *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *pCVar5;
  
  pCVar5 = (CFastBuffer<class_CCrystalFace*> *)0xb00b000;
  iVar1 = (**(code **)(*(int *)param_1 + 0x10))();
  if (iVar1 != 0) {
    CFastBuffer<class_CGamePlayerProfile*>::QSort
              (param_1 + 0x28,
               (CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *)
               CSystemFidsFolder::sCompareNames,(_func___cdecl_int_SKey_ptr_SKey_ptr *)pCVar5);
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x28,pCVar5);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_1 + 0x28,pCVar4,(ulong)unaff_EDI);
      unaff_EDI = *(CSystemFids **)pSVar3;
      RecursiveSortFidsTrees(unaff_EDI);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: ReleaseFstMutex
// =================================================
void __cdecl ReleaseFstMutex(ulong *param_1)
{
{
  LOCK();
  *param_1 = *param_1 - 1;
  UNLOCK();
  return;
}
}

// =================================================
// Function: RemoveLeadingSpaceFromXmlString
// =================================================
void __cdecl RemoveLeadingSpaceFromXmlString(CFastStringInt *param_1)
{
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  CFastStringInt *pCVar6;
  void *pvVar7;
  CFastStringInt *unaff_EBX;
  ulong *unaff_EBP;
  CFastStringInt *unaff_ESI;
  SOldChars *unaff_EDI;
  CFastStringInt *pCVar8;
  SStringParam *in_stack_ffffffe8;
  undefined1 local_14 [8];
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ac0928;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastStringInt::CFastStringInt
            (local_14,unaff_EBX,(SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
  bVar4 = false;
  if (*(int *)unaff_EBX != 0) {
    CFastStringBase<wchar_t>::AllocAtLeast(unaff_EBX,(CFastStringBase<wchar_t> *)0x0,1,0,unaff_EDI);
    **(undefined2 **)(unaff_EBX + 4) = 0;
    *(undefined4 *)unaff_EBX = 0;
  }
  local_c = (void *)CFastStringInt::ReadCharsStart(&local_c,unaff_ESI);
  pCVar8 = (CFastStringInt *)&local_c;
  bVar1 = true;
  pCVar6 = (CFastStringInt *)CFastStringInt::ReadCharsNext(&local_8,pCVar8,unaff_EBP);
  while (pCVar6 != (CFastStringInt *)0x0) {
    if ((pCVar6 == (CFastStringInt *)&DAT_00000009) || (pCVar6 == (CFastStringInt *)&DAT_00000020))
    {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((pCVar6 == (CFastStringInt *)&DAT_0000000d) || (pCVar6 == (CFastStringInt *)&DAT_0000000a))
    {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((bVar2) || (bVar3)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (((!bVar1) || (bVar5)) && ((bVar1 = false, !bVar4 || (!bVar2)))) {
      if (bVar3) {
        bVar4 = true;
      }
      else {
        if (bVar4) {
          unaff_EBP = (ulong *)&DAT_0000000a;
          pCVar8 = (CFastStringInt *)0x71e512;
          CFastStringInt::Concat(unaff_EBX,(CFastStringInt *)&DAT_0000000a,in_stack_ffffffe8);
        }
        bVar4 = false;
        CFastStringInt::Concat(unaff_EBX,pCVar6,(SStringParam *)pCVar8);
      }
    }
    pCVar8 = (CFastStringInt *)&local_c;
    pCVar6 = (CFastStringInt *)CFastStringInt::ReadCharsNext(&local_8,pCVar8,unaff_EBP);
  }
  if (PTR_DAT_00bbf7dc != (undefined *)0x0) {
    if ((bRamffffffff & 0x80) == 0) {
      pvVar7 = (void *)0xfffffffe;
    }
    else {
      pvVar7 = (void *)0xfffffffc;
    }
    operator_delete__(pvVar7);
  }
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: ResetSailVisualToBase
// =================================================
void __cdecl ResetSailVisualToBase(CPlugVisual *param_1,CPlugVisual *param_2)
{
{
  CPlugVisual *pCVar1;
  int iVar2;
  int iVar3;
  CPlugVisual *pCVar4;
  int *unaff_EBX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int aiStack_8 [2];
  
  pCVar1 = param_1;
  if ((param_1 != (CPlugVisual *)0x0) && (unaff_EBX != (int *)0x0)) {
    uStack_10 = (**(code **)(*unaff_EBX + 0x8c))();
    iStack_14 = (**(code **)(*(int *)pCVar1 + 0x8c))();
    while (iStack_14 != -1) {
      (**(code **)(*(int *)pCVar1 + 0x90))(&iStack_14,&param_1,aiStack_8);
      (**(code **)(*unaff_EBX + 0x90))(&stack0xffffffe4,&uStack_10,&stack0xffffffe8);
      pCVar4 = (CPlugVisual *)0x0;
      if (param_1 != (CPlugVisual *)0x0) {
        iVar2 = 0;
        do {
          pCVar4 = pCVar4 + 1;
          puVar5 = (undefined4 *)(iVar2 + iStack_c);
          puVar6 = (undefined4 *)(iVar2 + aiStack_8[0]);
          for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
          }
          iVar2 = iVar2 + 0x28;
        } while (pCVar4 < param_1);
      }
    }
  }
  return;
}
}

// =================================================
// Function: SafeCreateDepthStencilSurface
// =================================================
long __cdecl
SafeCreateDepthStencilSurface
          (CSystemConfig *param_1,ulong param_2,ulong param_3,_D3DFORMAT param_4,
          _D3DMULTISAMPLE_TYPE param_5,ulong param_6,IDirect3DSurface9 **param_7)
{
{
  long lVar1;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00cca150 ^ 0xcc4518;
  ExceptionList = &local_14;
  local_8 = 0;
  lVar1 = (**(code **)(*DAT_00d75698 + 0x74))
                    (DAT_00d75698,param_2,param_3,param_4,param_5,param_6,1,param_7,0);
  ExceptionList = local_14;
  return lVar1;
}
}

// =================================================
// Function: ScanFormatTags
// =================================================
void __cdecl
ScanFormatTags(TiXmlElement *param_1,CControlStyleSheet *param_2,SManialinkFormat *param_3)
{
{
  TiXmlElement *in_EAX;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  SManialinkFormat *unaff_retaddr;
  
  iVar1 = 7;
  bVar4 = true;
  pcVar2 = (char *)(*(int *)(in_EAX + 0x20) + 8);
  pcVar3 = "format";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    ElemModifyManialinkFormat(in_EAX,(CControlStyleSheet *)param_1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: ScreenToRect
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl ScreenToRect(GmVec2 *param_1,GmRectAligned *param_2,GmVec2 *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar7 = (float)_DAT_00b313b8;
  fVar1 = *(float *)(param_2 + 0xc);
  fVar2 = *(float *)(param_2 + 4);
  fVar3 = *(float *)(param_2 + 8);
  fVar4 = *(float *)param_2;
  fVar5 = *(float *)(param_2 + 0xc);
  fVar6 = *(float *)(param_2 + 4);
  *(float *)param_3 = *(float *)param_1 - (*(float *)param_2 + *(float *)(param_2 + 8)) * fVar7;
  *(float *)(param_3 + 4) = *(float *)(param_1 + 4) - (fVar1 + fVar2) * fVar7;
  *(float *)param_3 = *(float *)param_3 / ((fVar3 - fVar4) * fVar7);
  *(float *)(param_3 + 4) = *(float *)(param_3 + 4) / ((fVar5 - fVar6) * fVar7);
  return;
}
}

// =================================================
// Function: Sector_GetGxLight
// =================================================
GxLight * __cdecl Sector_GetGxLight(CSceneSector *param_1,ESceneLight param_2)
{
{
  CSceneLight *pCVar1;
  
  pCVar1 = Sector_GetLight(param_1,param_2);
  if (pCVar1 != (CSceneLight *)0x0) {
    return *(GxLight **)(*(int *)(pCVar1 + 0x30) + 0x88);
  }
  return (GxLight *)0x0;
}
}

// =================================================
// Function: Sector_GetLight
// =================================================
CSceneLight * __cdecl Sector_GetLight(CSceneSector *param_1,ESceneLight param_2)
{
{
  CSceneLight *this;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CSceneSector *pCVar3;
  ESceneLight EVar4;
  CSceneLight *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ESceneLight in_stack_00000010;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(*(int *)(param_1 + 0x14) + 0x20),unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(param_1 + 0x14) + 0x20),pCVar5,(ulong)unaff_ESI);
      this = *(CSceneLight **)pSVar2;
      unaff_ESI = (CSceneLight *)0x571f77;
      pCVar3 = (CSceneSector *)(**(code **)(*(int *)this + 0x78))();
      if ((pCVar3 == param_1) &&
         (EVar4 = CSceneLight::GetKindLight(this,unaff_ESI), EVar4 == in_stack_00000010)) {
        return this;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar1);
  }
  return (CSceneLight *)0x0;
}
}

// =================================================
// Function: SetBlockMobilVisible
// =================================================
void __cdecl SetBlockMobilVisible(CSceneMobil *param_1,int param_2,int param_3)
{
{
  CPlugTree *pCVar1;
  SVolatileTreePointer *unaff_EBX;
  CPlugTree *unaff_ESI;
  CSceneMobil *unaff_EDI;
  int unaff_retaddr;
  
  CSceneMobil::GetTree(unaff_EDI,unaff_EBX);
  TreeSetVisible(unaff_ESI,unaff_retaddr);
  if ((unaff_EBX != (SVolatileTreePointer *)0x0) && (param_2 != 0)) {
    pCVar1 = CSceneMobil::GetTree(unaff_EDI,(SVolatileTreePointer *)param_1);
    if (((byte)pCVar1[0x9c] & 8) != 0) {
      CHmsItem::SetCountShadowTexCasted
                (*(CHmsItem **)(unaff_EDI + 0x28),(CHmsItem *)0x1,'\0',param_2);
      return;
    }
  }
  CHmsItem::SetCountShadowTexCasted(*(CHmsItem **)(unaff_EDI + 0x28),(CHmsItem *)0x0,'\x01',param_2)
  ;
  return;
}
}

// =================================================
// Function: SetBoxAt
// =================================================
void __cdecl
SetBoxAt(CPlugVisualIndexedLines *param_1,GmBoxOriented *param_2,GxColor *param_3,ulong param_4,
        ulong param_5)
{
{
  int iVar1;
  float fVar2;
  float fVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  CPlugVisualIndexedLines *this;
  ulong unaff_EBP;
  float *unaff_ESI;
  undefined4 *unaff_EDI;
  float fVar5;
  float fVar6;
  float fVar7;
  float fStack00000018;
  float fStack0000001c;
  float fStack00000020;
  float fStack00000024;
  float fStack00000028;
  float in_stack_0000002c;
  float fStack00000030;
  float fStack00000038;
  float in_stack_0000003c;
  float in_stack_00000040;
  float in_stack_00000048;
  float in_stack_0000004c;
  float in_stack_00000050;
  ulong in_stack_ffffffc8;
  ulong in_stack_ffffffcc;
  ulong in_stack_ffffffd0;
  ulong in_stack_ffffffd4;
  ulong in_stack_ffffffd8;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  this = param_1 + 0x78;
  CFastBuffer<struct_CPlugVisual::SSplit>::AllocSetCount
            (this,(CFastBuffer<class_GxVertex2> *)(param_2 + 8),unaff_EBP);
  CFastBuffer<wchar_t>::AllocSetCount
            ((void *)(*(int *)(param_2 + 0x98) + 0x1c),
             (CFastBuffer<class_GxVertex2> *)(param_4 + 0x18),unaff_EBX);
  do {
    pSVar4 = CFastBuffer<unsigned_short>::operator[]
                       ((void *)param_4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_5,
                        in_stack_ffffffc8);
    iVar1 = param_4 * 2;
    param_4 = param_4 + 1;
    *(short *)pSVar4 = *(short *)(&DAT_00d14b44 + iVar1) + (short)param_2;
  } while (param_4 < 0x18);
  fVar6 = unaff_ESI[0xc];
  fVar13 = unaff_ESI[0xd];
  fVar7 = unaff_ESI[0xe];
  fVar11 = unaff_ESI[9];
  fVar10 = unaff_ESI[0xb];
  fVar5 = -fVar6;
  fStack00000018 = fVar13 * unaff_ESI[4] + fVar5 * unaff_ESI[3] + fVar7 * unaff_ESI[5];
  fVar2 = fVar7 * unaff_ESI[8] + unaff_ESI[7] * fVar13 + unaff_ESI[6] * fVar5;
  fVar9 = unaff_ESI[10] + fStack00000018;
  fVar8 = fVar10 + fVar2;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                      in_stack_ffffffcc);
  *(float *)pSVar4 = fVar9;
  *(float *)(pSVar4 + 4) = fVar8;
  *(float *)(pSVar4 + 8) = fVar11;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                      in_stack_ffffffd0);
  fVar3 = fStack00000018;
  *(undefined4 *)(pSVar4 + 0x18) = *unaff_EDI;
  *(undefined4 *)(pSVar4 + 0x1c) = unaff_EDI[1];
  *(undefined4 *)(pSVar4 + 0x20) = unaff_EDI[2];
  *(undefined4 *)(pSVar4 + 0x24) = unaff_EDI[3];
  fVar11 = -(float)param_1;
  fStack00000020 = fVar11 * unaff_ESI[5] + fVar5 * unaff_ESI[4] + fStack00000018 * unaff_ESI[3];
  fVar8 = fVar11 * unaff_ESI[8] + unaff_ESI[7] * fVar5 + unaff_ESI[6] * fStack00000018;
  fVar6 = fVar6 + fStack00000020;
  fVar12 = fVar13 + fVar8;
  fStack0000001c = fVar11;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 1),
                      in_stack_ffffffd4);
  *(float *)pSVar4 = fVar6;
  *(float *)(pSVar4 + 4) = fVar12;
  *(float *)(pSVar4 + 8) = fVar10;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 1),
                      in_stack_ffffffd8);
  *(undefined4 *)(pSVar4 + 0x18) = *unaff_EDI;
  *(undefined4 *)(pSVar4 + 0x1c) = unaff_EDI[1];
  *(undefined4 *)(pSVar4 + 0x20) = unaff_EDI[2];
  *(undefined4 *)(pSVar4 + 0x24) = unaff_EDI[3];
  fStack00000028 = fVar3 * unaff_ESI[4] + (float)param_1 * unaff_ESI[3] + unaff_ESI[5] * 0.0;
  fVar10 = unaff_ESI[8] * 0.0 + unaff_ESI[7] * fVar3 + unaff_ESI[6] * (float)param_1;
  fVar7 = fVar7 + fStack00000028;
  fVar12 = fVar5 + fVar10;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 2),
                      (ulong)fVar8);
  *(float *)pSVar4 = fVar7;
  *(float *)(pSVar4 + 4) = fVar12;
  *(float *)(pSVar4 + 8) = fVar13;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 2),
                      (ulong)fVar9);
  *(undefined4 *)(pSVar4 + 0x18) = *unaff_EDI;
  *(undefined4 *)(pSVar4 + 0x1c) = unaff_EDI[1];
  *(undefined4 *)(pSVar4 + 0x20) = unaff_EDI[2];
  *(undefined4 *)(pSVar4 + 0x24) = unaff_EDI[3];
  fStack00000030 = in_stack_0000002c * unaff_ESI[5] + fVar11 * unaff_ESI[4] + unaff_ESI[3] * 0.0;
  fVar13 = in_stack_0000002c * unaff_ESI[8] + unaff_ESI[7] * fVar11 + unaff_ESI[6] * 0.0;
  fVar9 = (float)param_1 + fStack00000030;
  fVar8 = fVar3 + fVar13;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 3),
                      (ulong)fVar10);
  *(float *)pSVar4 = fVar9;
  *(float *)(pSVar4 + 4) = fVar8;
  *(float *)(pSVar4 + 8) = fVar5;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 3),
                      (ulong)fVar6);
  *(undefined4 *)(pSVar4 + 0x18) = *unaff_EDI;
  *(undefined4 *)(pSVar4 + 0x1c) = unaff_EDI[1];
  *(undefined4 *)(pSVar4 + 0x20) = unaff_EDI[2];
  *(undefined4 *)(pSVar4 + 0x24) = unaff_EDI[3];
  fStack00000020 = fStack00000030;
  fStack00000024 = -fStack00000018;
  fVar5 = fStack00000024 * unaff_ESI[4] + fStack00000030 * unaff_ESI[3] +
          fStack0000001c * unaff_ESI[5];
  fVar10 = fStack0000001c * unaff_ESI[8] +
           unaff_ESI[6] * fStack00000030 + fStack00000024 * unaff_ESI[7];
  fVar9 = unaff_ESI[1] * fStack00000024 + *unaff_ESI * fStack00000030 +
          unaff_ESI[2] * fStack0000001c + fVar3;
  fVar6 = fVar5 + 0.0;
  fVar8 = fVar11 + fVar10;
  fStack00000038 = fStack00000024;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 4),
                      (ulong)fVar13);
  *(float *)pSVar4 = fVar6;
  *(float *)(pSVar4 + 4) = fVar8;
  *(float *)(pSVar4 + 8) = fVar3;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 4),
                      (ulong)fVar7);
  *(undefined4 *)(pSVar4 + 0x18) = *unaff_EDI;
  *(undefined4 *)(pSVar4 + 0x1c) = unaff_EDI[1];
  *(undefined4 *)(pSVar4 + 0x20) = unaff_EDI[2];
  *(undefined4 *)(pSVar4 + 0x24) = unaff_EDI[3];
  fStack00000028 = fStack00000038;
  fVar12 = in_stack_0000003c * unaff_ESI[5] +
           in_stack_00000040 * unaff_ESI[4] + fStack00000038 * unaff_ESI[3];
  fVar7 = in_stack_0000003c * unaff_ESI[8] +
          unaff_ESI[6] * fStack00000038 + in_stack_00000040 * unaff_ESI[7];
  fVar6 = unaff_ESI[1];
  fVar8 = *unaff_ESI * fStack00000038;
  fVar13 = unaff_ESI[2];
  fVar3 = fStack00000018 + fVar7;
  fStack00000038 = fVar12;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 5),
                      (ulong)fVar5);
  *(float *)pSVar4 = fVar2 + fVar12;
  *(float *)(pSVar4 + 4) = fVar3;
  *(float *)(pSVar4 + 8) = fVar11;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 5),
                      (ulong)fVar10);
  *(undefined4 *)(pSVar4 + 0x18) = *unaff_EDI;
  *(undefined4 *)(pSVar4 + 0x1c) = unaff_EDI[1];
  *(undefined4 *)(pSVar4 + 0x20) = unaff_EDI[2];
  *(undefined4 *)(pSVar4 + 0x24) = unaff_EDI[3];
  fVar10 = in_stack_00000040 * unaff_ESI[8] +
           unaff_ESI[6] * fStack00000024 + in_stack_00000048 * unaff_ESI[7];
  fVar5 = fStack0000001c +
          in_stack_00000048 * unaff_ESI[4] + fStack00000024 * unaff_ESI[3] +
          in_stack_00000040 * unaff_ESI[5];
  fVar2 = fStack00000020 + fVar10;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 6),
                      (ulong)fVar9);
  *(float *)pSVar4 = fVar5;
  *(float *)(pSVar4 + 4) = fVar2;
  *(float *)(pSVar4 + 8) = fStack00000018;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 6),
                      (ulong)fVar7);
  *(undefined4 *)(pSVar4 + 0x18) = *unaff_EDI;
  *(undefined4 *)(pSVar4 + 0x1c) = unaff_EDI[1];
  *(undefined4 *)(pSVar4 + 0x20) = unaff_EDI[2];
  *(undefined4 *)(pSVar4 + 0x24) = unaff_EDI[3];
  fStack00000018 =
       fStack00000024 +
       in_stack_0000004c * unaff_ESI[5] +
       in_stack_00000050 * unaff_ESI[4] + in_stack_00000040 * unaff_ESI[3];
  fStack0000001c =
       fStack00000028 +
       in_stack_0000004c * unaff_ESI[8] +
       unaff_ESI[6] * in_stack_00000040 + in_stack_00000050 * unaff_ESI[7];
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 7),
                      (ulong)(fVar6 * in_stack_00000040 + fVar8 + fVar13 * in_stack_0000003c +
                             fVar11));
  *(float *)pSVar4 = fStack00000018;
  *(float *)(pSVar4 + 4) = fStack0000001c;
  *(float *)(pSVar4 + 8) = fStack00000020;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 7),
                      (ulong)fVar10);
  *(undefined4 *)(pSVar4 + 0x18) = *unaff_EDI;
  *(undefined4 *)(pSVar4 + 0x1c) = unaff_EDI[1];
  *(undefined4 *)(pSVar4 + 0x20) = unaff_EDI[2];
  *(undefined4 *)(pSVar4 + 0x24) = unaff_EDI[3];
  return;
}
}

// =================================================
// Function: SetControlBg
// =================================================
void __cdecl SetControlBg(CControlBase *param_1,SManialinkFormat *param_2)
{
{
  CControlStyle *pCVar1;
  CControlStyle *this;
  int *extraout_EAX;
  CPlugShaderApply *this_00;
  CPlugShaderGeneric *extraout_EAX_00;
  CPlugMaterial *this_01;
  CMwNod *extraout_EAX_01;
  int in_ECX;
  EGxBlendFactor unaff_EBX;
  CPlugShaderGeneric *this_02;
  EGxBlendFactor unaff_ESI;
  int *piVar2;
  GxColor *unaff_EDI;
  CMwNod *this_03;
  undefined4 uStack0000000c;
  undefined4 uStack00000010;
  int in_stack_00000018;
  CPlugShaderApply *pCVar3;
  CMwNod *pCVar4;
  
  pCVar1 = (CControlStyle *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  pCVar4 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  this = operator_new(0x184);
  this_02 = (CPlugShaderGeneric *)0x0;
  if (this == (CControlStyle *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    CControlStyle::CControlStyle(this,pCVar1);
    piVar2 = extraout_EAX;
  }
  (**(code **)(*piVar2 + 0x4c))();
  piVar2[0xe] = 0;
  piVar2[0xf] = 0;
  pCVar3 = (CPlugShaderApply *)0x0;
  piVar2[0x10] = *(int *)(in_ECX + 0x28);
  piVar2[0x11] = *(int *)(in_ECX + 0x2c);
  piVar2[0x12] = *(int *)(in_ECX + 0x30);
  CControlBase::CStyleSheetElem<class_CControlStyle>::Set
            (param_2 + 0x110,(CMwCmdScriptVarBool *)param_2,(int)piVar2);
  this_00 = operator_new(0xa8);
  if (this_00 != (CPlugShaderApply *)0x0) {
    CPlugShaderApply::CPlugShaderApply(this_00,pCVar3);
    this_02 = extraout_EAX_00;
  }
  CPlugShaderGeneric::SetVertexColor(this_02,(CPlugShaderGeneric *)0x0,in_ECX + 0x18,unaff_EDI);
  CPlugShaderApply::SetBlending
            ((CPlugShaderApply *)this_02,(CPlugShaderPass *)0x1,unaff_ESI,unaff_EBX);
  this_01 = operator_new(0x38);
  uStack0000000c = 2;
  if (this_01 == (CPlugMaterial *)0x0) {
    this_03 = (CMwNod *)0x0;
  }
  else {
    CPlugMaterial::CPlugMaterial(this_01,(CPlugMaterial *)this_02,(CPlugShader *)this_00);
    this_03 = extraout_EAX_01;
  }
  uStack00000010 = 0xffffffff;
  if (this_03 != (CMwNod *)piVar2[10]) {
    if (this_03 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_03,pCVar4);
    }
    if ((CMwNod *)piVar2[10] != (CMwNod *)0x0) {
      CMwNod::MwRelease((CMwNod *)piVar2[10],pCVar4);
    }
    piVar2[10] = (int)this_03;
  }
  if (this_03 != (CMwNod *)piVar2[0xb]) {
    if (this_03 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_03,pCVar4);
    }
    if ((CMwNod *)piVar2[0xb] != (CMwNod *)0x0) {
      CMwNod::MwRelease((CMwNod *)piVar2[0xb],pCVar4);
    }
    piVar2[0xb] = (int)this_03;
  }
  *(uint *)(in_stack_00000018 + 0xfc) = *(uint *)(in_stack_00000018 + 0xfc) | 0x800;
  ExceptionList = param_2;
  return;
}
}

// =================================================
// Function: SmoothValue
// =================================================
float __cdecl SmoothValue(float param_1,float param_2,float param_3)
{
{
  if (param_3 + param_2 < param_1) {
    return param_1 - param_3;
  }
  if (param_1 < param_2 - param_3) {
    return param_3 + param_1;
  }
  return param_2;
}
}

// =================================================
// Function: SolidGetTargetFromId
// =================================================
int __cdecl SolidGetTargetFromId(CMwId *param_1,CPlugSolid *param_2,STarget *param_3)
{
{
  void *this;
  int iVar1;
  int iVar2;
  CPlugModelTree *pCVar3;
  int *piVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CPlugModelTree_ItTree *unaff_EDI;
  undefined4 *in_stack_00000010;
  ulong uVar8;
  undefined1 local_20 [4];
  undefined1 local_1c [12];
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00accd98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlugTree::CIteratorTree::CIteratorTree
            (local_20,*(CIteratorTree **)(param_2 + 100),(CPlugTree *)0x0,
             (EMode)((uint)DAT_00cca150 ^ (uint)&stack0xffffffd0));
  while( true ) {
    if (local_10 == 0) {
      *in_stack_00000010 = 0;
      in_stack_00000010[1] = 0xffffffff;
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (local_1c,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_EDI);
      ExceptionList = pvStack_4;
      return 0;
    }
    pCVar3 = CPlugTree::CIteratorTree::GetNextTree(local_1c,unaff_EDI);
    unaff_EDI = (CPlugModelTree_ItTree *)0x7ca4a5;
    piVar4 = (int *)(**(code **)(*(int *)pCVar3 + 0x14))();
    iVar1 = *(int *)param_2;
    if (*piVar4 == iVar1) break;
    if ((*(int *)(pCVar3 + 0x90) != 0) &&
       (iVar2 = *(int *)(*(int *)(pCVar3 + 0x90) + 0x50), iVar2 != 0)) {
      this = (void *)(iVar2 + 0x18);
      uVar8 = 0x7ca4ce;
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
      pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this,pCVar7,uVar8);
          if (*(int *)pSVar6 == iVar1) {
            *in_stack_00000010 = pCVar3;
            in_stack_00000010[1] = pCVar7;
            CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                      (local_1c,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_EDI);
            ExceptionList = pvStack_4;
            return 1;
          }
          pCVar7 = pCVar7 + 1;
        } while (pCVar7 < pCVar5);
      }
    }
  }
  *in_stack_00000010 = pCVar3;
  in_stack_00000010[1] = 0xffffffff;
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (local_1c,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_EDI);
  ExceptionList = pvStack_4;
  return 1;
}
}

// =================================================
// Function: String_ConcatFixedDriveSerialFromPath
// =================================================
int __cdecl String_ConcatFixedDriveSerialFromPath(CFastString *param_1,CFastStringInt *param_2)
{
{
  CFastStringInt *pCVar1;
  UINT UVar2;
  BOOL BVar3;
  CFastString *this;
  
  pCVar1 = param_2;
  UVar2 = GetDriveTypeW(*(LPCWSTR *)(param_2 + 4));
  if (UVar2 == 3) {
    param_2 = (CFastStringInt *)0xffffffff;
    BVar3 = GetVolumeInformationW
                      (*(LPCWSTR *)(pCVar1 + 4),(LPWSTR)0x0,0,(LPDWORD)&param_2,(LPDWORD)0x0,
                       (LPDWORD)0x0,(LPWSTR)0x0,0);
    if ((BVar3 != 0) && (param_2 != (CFastStringInt *)0x0)) {
      CFastString::ConcatFormat(this,(CFastStringInt *)param_1,"%08X");
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: String_GetNextNaturalHexa
// =================================================
int __cdecl String_GetNextNaturalHexa(CFastString *param_1,SFastToken *param_2,ulong *param_3)
{
{
  int iVar1;
  CFastString *in_ECX;
  CFastStringInt *unaff_ESI;
  SFastTokenInt *unaff_retaddr;
  
  iVar1 = CFastString::GetNextToken(in_ECX,unaff_ESI,unaff_retaddr);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = CFastString::GetNatural
                    ((CFastString *)(unaff_ESI + 8),(CFastString *)param_2,(ulong *)0x1,0,
                     (ulong)param_1);
  return iVar1;
}
}

// =================================================
// Function: String_GetNextReal
// =================================================
int __cdecl String_GetNextReal(CFastString *param_1,SFastToken *param_2,float *param_3)
{
{
  int iVar1;
  CFastString *in_ECX;
  CFastStringInt *unaff_ESI;
  SFastTokenInt *unaff_retaddr;
  
  iVar1 = CFastString::GetNextToken(in_ECX,unaff_ESI,unaff_retaddr);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = CFastString::GetReal
                    ((CFastString *)(unaff_ESI + 8),(CFastString *)param_2,(float *)param_1);
  return iVar1;
}
}

// =================================================
// Function: TreeSetVisible
// =================================================
void __cdecl TreeSetVisible(CPlugTree *param_1,int param_2)
{
{
  CPlugTree *unaff_ESI;
  CPlugTree *unaff_retaddr;
  
  if (param_1 != (CPlugTree *)0x0) {
    *(uint *)(unaff_ESI + 0x9c) = *(uint *)(unaff_ESI + 0x9c) | 8;
    CPlugTree::HideInvalidTrees(unaff_ESI,unaff_retaddr);
    (**(code **)(*(int *)unaff_ESI + 0xbc))();
    return;
  }
  *(uint *)(unaff_ESI + 0x9c) = *(uint *)(unaff_ESI + 0x9c) & 0xfffffff7;
  return;
}
}

// =================================================
// Function: TwkInitReal
// =================================================
void __cdecl TwkInitReal(CFastArray<float*> *param_1,CPlugShader *param_2,char *param_3)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  SCasterCat *pSVar4;
  void *unaff_EBX;
  CMwId *unaff_EBP;
  CFastStringInt *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CMwId *in_stack_00000010;
  void *in_stack_00000014;
  undefined4 uStack0000001c;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffe4;
  ulong in_stack_ffffffe8;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffec;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffff0;
  CFastStringInt *pCVar6;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a98810;
  pCVar6 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  CMwId::CMwId(&stack0xffffffe4,(CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffd8));
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (&stack0xffffffec,unaff_EDI);
  param_1 = (CFastArray<float*> *)CONCAT31(param_1._1_3_,1);
  CMwId::SetLocalName(&stack0xffffffec,in_stack_00000010,unaff_ESI);
  CPlugShader::GetLoadFxValues
            ((CPlugShader *)in_stack_00000010,(CPlugShader *)&stack0xfffffff4,
             (CFastBuffer<struct_CPlugShader::SFxValue> *)&stack0xfffffff0,unaff_EBP);
  pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&local_8,in_stack_ffffffe4);
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount(unaff_EBX,pCVar1,in_stack_ffffffe8);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&stack0x00000000,in_stack_ffffffec);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](&param_1,pCVar5,(ulong)in_stack_fffffff0);
      in_stack_fffffff0 = pCVar5;
      if ((*(uint *)(*(int *)pSVar3 + 4) & 0x1c0) == 0x100) {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (unaff_EBX,pCVar5,(ulong)pCVar6);
        *(int *)pSVar4 = *(int *)(pSVar3 + 4) + 0xc;
      }
      else {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (unaff_EBX,pCVar5,(ulong)pCVar6);
        *(undefined4 *)pSVar4 = *(undefined4 *)(pSVar3 + 4);
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&param_1,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_fffffff0);
  uStack0000001c = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(pCVar6);
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: UpdateGeometrySpiAsym_MoveVertex
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl UpdateGeometrySpiAsym_MoveVertex(GmVec3 *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  float *in_ECX;
  float *in_EDX;
  
  *in_EAX = *in_ECX;
  in_EAX[1] = in_ECX[1];
  in_EAX[2] = in_ECX[2];
  *in_EAX = 0.0;
  fVar1 = *in_ECX;
  fVar2 = in_EDX[1];
  fVar3 = in_EDX[2];
  *in_EAX = fVar1 * *in_EDX + (float)_PTR_00b2c178;
  in_EAX[1] = fVar2 * fVar1 + in_EAX[1];
  in_EAX[2] = in_EAX[2] + fVar1 * fVar3;
  return;
}
}

// =================================================
// Function: ValueHLS
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl ValueHLS(float param_1,float param_2,float param_3)
{
{
  if (param_3 <= 1.0) {
    if (param_3 < 0.0) {
      param_3 = param_3 + (float)_DAT_00b2c188;
    }
  }
  else {
    param_3 = param_3 - (float)_DAT_00b2c188;
  }
  if (param_3 < _DAT_00babbd0) {
    return ((param_2 - param_1) * param_3) / (float)_DAT_00babbc8 + param_1;
  }
  if (param_3 < _DAT_00b31460) {
    return param_2;
  }
  if (_DAT_00babbc0 <= param_3) {
    return param_1;
  }
  return ((param_2 - param_1) * ((float)_DAT_00babbb8 - param_3)) / (float)_DAT_00babbc8 + param_1;
}
}

// =================================================
// Function: VskCartesianToPolar
// =================================================
void __cdecl VskCartesianToPolar(GmVec2 *param_1,GmVec2 *param_2)
{
{
  float *in_EAX;
  float *unaff_ESI;
  float10 fVar1;
  float10 extraout_ST0;
  
  fVar1 = (float10)func_0x009c1b40(-*in_EAX * -*in_EAX + in_EAX[1] * in_EAX[1]);
  *unaff_ESI = (float)fVar1;
  __CIatan2();
  unaff_ESI[1] = (float)extraout_ST0;
  return;
}
}

// =================================================
// Function: Win32SystemTimeToSystemTime
// =================================================
void __cdecl Win32SystemTimeToSystemTime(_SYSTEMTIME *param_1,SSystemTime *param_2)
{
{
  uint *in_EAX;
  uint uVar1;
  undefined2 *unaff_ESI;
  
  *(undefined2 *)in_EAX = *unaff_ESI;
  *in_EAX = *in_EAX ^ ((uint)(ushort)unaff_ESI[1] << 0x10 ^ *in_EAX) & 0xf0000;
  uVar1 = ((uint)(ushort)unaff_ESI[2] << 0x14 ^ *in_EAX) & 0x700000 ^ *in_EAX;
  *in_EAX = uVar1;
  *in_EAX = ((uint)(ushort)unaff_ESI[3] << 0x17 ^ uVar1) & 0xf800000 ^ uVar1;
  in_EAX[1] = in_EAX[1] ^ ((uint)(ushort)unaff_ESI[4] ^ in_EAX[1]) & 0x1f;
  uVar1 = ((uint)(ushort)unaff_ESI[5] << 5 ^ in_EAX[1]) & 0x7e0 ^ in_EAX[1];
  in_EAX[1] = uVar1;
  uVar1 = ((uint)(ushort)unaff_ESI[6] << 0xb ^ uVar1) & 0x1f800 ^ uVar1;
  in_EAX[1] = uVar1;
  in_EAX[1] = ((uint)(ushort)unaff_ESI[7] << 0x11 ^ uVar1) & 0x7fe0000 ^ uVar1;
  return;
}
}

// =================================================
// Function: XmlGetClassInfo
// =================================================
CMwClassInfo * __cdecl XmlGetClassInfo(TiXmlElement *param_1)
{
{
  CFastString CVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  CMwClassInfo *pCVar5;
  undefined1 *puVar6;
  CFastString *pCVar7;
  CFastString *pCVar8;
  CFastString *pCVar9;
  GxTexCoordSet *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  char *unaff_EDI;
  bool bVar11;
  void *unaff_retaddr;
  CFastString aCStack_10 [4];
  void *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = &LAB_00a82898;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar9 = (CFastString *)(*(int *)(param_1 + 0x20) + 8);
  if (pCVar9 != (CFastString *)0x0) {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (&DAT_00d55634,
                        (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffdc))
    ;
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<struct_SFastCat>::operator[](&DAT_00d55634,pCVar10,(ulong)unaff_EDI);
        pCVar7 = *(CFastString **)pSVar3;
        pCVar8 = pCVar9;
        do {
          CVar1 = *pCVar7;
          bVar11 = (byte)CVar1 < (byte)*pCVar8;
          if (CVar1 != *pCVar8) {
LAB_0042c060:
            iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            goto LAB_0042c065;
          }
          if (CVar1 == (CFastString)0x0) break;
          CVar1 = pCVar7[1];
          bVar11 = (byte)CVar1 < (byte)pCVar8[1];
          if (CVar1 != pCVar8[1]) goto LAB_0042c060;
          pCVar7 = pCVar7 + 2;
          pCVar8 = pCVar8 + 2;
        } while (CVar1 != (CFastString)0x0);
        iVar4 = 0;
LAB_0042c065:
        if (iVar4 == 0) {
          pCVar9 = *(CFastString **)(pSVar3 + 4);
          break;
        }
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < pCVar2);
    }
    CFastString::CFastString(aCStack_10,pCVar9,unaff_EDI);
    pCVar5 = CMwClassInfo::FindFromClassName((CFastString *)&local_c);
    if (local_8 != PTR_DAT_00bbf7d8) {
      puVar6 = local_8 + -1;
      if ((local_8[-1] & 0x80) != 0) {
        puVar6 = local_8 + -4;
      }
      operator_delete__(puVar6);
      local_c = (void *)0x0;
      local_8 = PTR_DAT_00bbf7d8;
    }
    if (pCVar5 != (CMwClassInfo *)0x0) {
      iVar4 = CFastArray<class_CGameMenuFrame*>::Find
                        (&DAT_00d55628,(CFastArray<class_GxTexCoordSet> *)(pCVar5 + 4),unaff_ESI);
      if (iVar4 == -1) {
        pCVar5 = (CMwClassInfo *)0x0;
      }
      ExceptionList = unaff_retaddr;
      return pCVar5;
    }
  }
  ExceptionList = local_4;
  return (CMwClassInfo *)0x0;
}
}

// =================================================
// Function: XmlParamActionGet
// =================================================
int __cdecl XmlParamActionGet(char *param_1,EXmlParamAction param_2)
{
{
  char *in_EAX;
  int iVar1;
  char *pcVar2;
  bool bVar3;
  
  bVar3 = true;
  iVar1 = 6;
  pcVar2 = "Modif";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar3 = *in_EAX == *pcVar2;
    in_EAX = in_EAX + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar3);
  return (uint)bVar3;
}
}

// =================================================
// Function: Zone_UpdateWaterHeights
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Zone_UpdateWaterHeights(CHmsCorpus *param_1)
{
{
  void *this;
  int iVar1;
  int iVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CHmsCorpus *in_ECX;
  TiXmlAttribute *unaff_EBX;
  GmVec4 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float unaff_retaddr;
  float in_stack_00000008;
  CHmsCorpus local_10 [8];
  float local_8;
  float local_4;
  
  iVar1 = *(int *)(in_ECX + 0x14);
  iVar2 = CHmsCorpus::WaterGetPlaneEqInZone(in_ECX,local_10,unaff_ESI);
  if (iVar2 != 0) {
    this = (void *)(iVar1 + 0xdc);
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GxColor>::operator[](this,pCVar5,(ulong)unaff_EBX);
        local_8 = *(float *)(pSVar4 + 8) * (float)param_1 +
                  *(float *)pSVar4 * local_4 + *(float *)(pSVar4 + 4) * unaff_retaddr;
        if (((float)_DAT_00b44a20 <= local_8) &&
           (local_8 = ABS(in_stack_00000008 - *(float *)(pSVar4 + 0xc)),
           local_8 <= (float)_DAT_00b362c0)) break;
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar3);
    }
    if (pCVar5 == pCVar3) {
      CFastBuffer<class_GmQuat>::Add(this,(TiXmlAttributeSet *)&local_8,unaff_EBX);
    }
  }
  return;
}
}

// =================================================
// Function: _D3DXLoadSurfaceFromFileInMemory_36
// =================================================
void __cdecl _D3DXLoadSurfaceFromFileInMemory_36(void)
{
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}
}

// =================================================
// Function: _D3DXLoadSurfaceFromMemory_40
// =================================================
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl _D3DXLoadSurfaceFromMemory_40(void)
{
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  code *pcVar4;
  undefined4 in_EAX;
  uint uVar5;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  
  bVar1 = 9 < ((byte)in_EAX & 0xf);
  bVar3 = bVar1 | in_AF;
  uVar5 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar3 * '\x06') & 0xffffff0f;
  bVar2 = 9 < (bVar3 * '\x06' & 0xf);
  *(uint *)(CONCAT22((short)(uVar5 >> 0x10),CONCAT11((char)((uint)in_EAX >> 8) + bVar3,(char)uVar5))
           + -4) =
       (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
       (uint)(byte)(bVar2 | bVar1 | in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 |
       (uint)(byte)(bVar2 | bVar1 | in_AF & 1) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}
}

// =================================================
// Function: _D3DXMatrixTranspose_8
// =================================================
void __cdecl _D3DXMatrixTranspose_8(void)
{
{
  in(0x37);
  func_0xf0d6f6f0();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
}

// =================================================
// Function: _GetAdaptersInfo_8
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00a0f1b2) overlaps instruction at (ram,0x00a0f1b1)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x00a0f03e) */
/* WARNING: Removing unreachable block (ram,0x00a0f1fa) */
/* WARNING: Removing unreachable block (ram,0x00a0f236) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl _GetAdaptersInfo_8(void)
{
{
  byte bVar1;
  undefined3 uVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  short sVar9;
  char cVar18;
  byte bVar20;
  byte *pbVar10;
  uint *puVar11;
  int iVar12;
  byte bVar19;
  undefined2 uVar21;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  char *pcVar16;
  char *pcVar17;
  ushort uVar22;
  byte bVar23;
  byte bVar26;
  int in_ECX;
  int iVar24;
  int extraout_ECX;
  byte *pbVar25;
  byte *extraout_ECX_00;
  byte bVar29;
  uint in_EDX;
  uint uVar27;
  uint uVar28;
  uint unaff_EBX;
  byte *pbVar30;
  uint uVar31;
  uint unaff_EBP;
  uint uVar32;
  uint *unaff_ESI;
  char *unaff_EDI;
  bool bVar33;
  byte in_AF;
  bool bVar34;
  bool bVar35;
  undefined8 uVar36;
  char *unaff_retaddr;
  undefined4 uStack_4;
  
  bVar7 = in_AF | 1;
  uVar14 = CONCAT31(0xc83fc0,bVar7 * -6 + '?') & 0xffffff0f;
  *unaff_EDI = *unaff_EDI >> 1;
  iVar24 = in_ECX + -1;
  if (iVar24 == 0 || *unaff_EDI == '\0') {
    uStack_4 = 0xa0efe7;
    uVar36 = func_0xf8e0e026();
    in_EDX = (uint)((ulonglong)uVar36 >> 0x20);
    bVar7 = 9 < ((byte)uVar36 & 0xf) | bVar7;
    uVar14 = CONCAT31((int3)((ulonglong)uVar36 >> 8),(byte)uVar36 + bVar7 * -6) & 0xffffff0f;
    cVar3 = (char)uVar14;
    cVar18 = (char)((ulonglong)uVar36 >> 8) - bVar7;
    pbVar30 = (byte *)CONCAT22((short)(uVar14 >> 0x10),CONCAT11(cVar18,cVar3));
    pbVar30[0x2440088] = pbVar30[0x2440088] + cVar18;
    *pbVar30 = *pbVar30 + cVar3;
    bVar5 = (byte)((ulonglong)uVar36 >> 0x28);
    *pbVar30 = *pbVar30 + bVar5;
    *pbVar30 = *pbVar30 | bVar5;
    bVar6 = *pbVar30;
    *pbVar30 = *pbVar30 + bVar5;
    *pbVar30 = (*pbVar30 - bVar5) - CARRY1(bVar6,bVar5);
    *pbVar30 = *pbVar30 & bVar5;
    *pbVar30 = *pbVar30 - bVar5;
    *pbVar30 = *pbVar30 ^ bVar5;
    pbVar10 = pbVar30 + 1;
    pbVar30[0x31] = pbVar30[0x31] ^ (byte)extraout_ECX;
    pbVar30[0x31] = pbVar30[0x31] ^ (byte)unaff_EBX;
    pbVar25 = pbVar30 + 0x31;
    bVar6 = (byte)((uint)extraout_ECX >> 8);
    *pbVar25 = *pbVar25 ^ bVar6;
    iVar24 = extraout_ECX;
    unaff_retaddr = unaff_EDI;
    if ((char)*pbVar25 < '\0') {
      iVar12 = (int)(short)pbVar10;
    }
    else {
      *pbVar10 = *pbVar10 ^ 0x88;
      pbVar30[-0x5fcf67cf] = pbVar30[-0x5fcf67cf] ^ (byte)((ulonglong)uVar36 >> 0x20);
      (pbVar30 + 0x30d430cd)[(int)unaff_ESI] = (pbVar30 + 0x30d430cd)[(int)unaff_ESI] ^ bVar6;
      in(0x30);
      uVar4 = in((short)((ulonglong)uVar36 >> 0x20));
      iVar12 = CONCAT31((int3)((uint)pbVar10 >> 8),uVar4);
    }
  }
  else {
    iVar12 = CONCAT22((short)(uVar14 >> 0x10),CONCAT11((char)((uint)iVar24 >> 8),(char)uVar14));
  }
  bVar5 = (byte)(in_EDX >> 8);
  puVar11 = (uint *)CONCAT22((short)((uint)iVar12 >> 0x10),
                             CONCAT11((byte)((uint)iVar12 >> 8) ^ bVar5,(byte)iVar12));
  *(byte *)puVar11 = (byte)*puVar11 ^ (byte)iVar12;
  *puVar11 = *puVar11 ^ (uint)&stack0x00000000;
  *puVar11 = *puVar11 ^ unaff_EBP;
  *puVar11 = *puVar11 ^ (uint)unaff_ESI;
  *puVar11 = *puVar11 ^ (uint)unaff_EDI;
  *(uint *)((int)puVar11 + 0x31) = *(uint *)((int)puVar11 + 0x31) ^ (uint)puVar11;
  puVar11[0xc] = puVar11[0xc] ^ in_EDX;
  *(uint *)(unaff_retaddr + 0x31) = *(uint *)(unaff_retaddr + 0x31) ^ (uint)&stack0x00000004;
  *(uint *)(unaff_retaddr + -0x37ce3fcf) = *(uint *)(unaff_retaddr + -0x37ce3fcf) ^ (uint)unaff_EDI;
  puVar11 = (uint *)((uint)unaff_retaddr ^ in_EDX ^ unaff_EBX ^ (uint)&stack0x00000000 ^ unaff_EBP ^
                     (uint)unaff_ESI ^ (uint)unaff_EDI);
  *puVar11 = *puVar11 ^ (uint)puVar11;
  uVar14 = CONCAT31((int3)((uint)puVar11 >> 8),(char)puVar11 + -0x32) ^ 0x32;
  iVar12 = uVar14 + 1;
  uVar21 = (undefined2)((uint)iVar12 >> 0x10);
  bVar6 = (byte)iVar12;
  bVar19 = (byte)((uint)iVar12 >> 8) ^ *(byte *)(uVar14 + 0x33);
  uStack_4 = 0x94327432;
  bVar19 = bVar19 ^ *(byte *)(CONCAT22(uVar21,CONCAT11(bVar19,bVar6)) + -0x1bcd3bce);
  pbVar25 = (byte *)CONCAT22((short)((uint)iVar24 >> 0x10),
                             CONCAT11((byte)((uint)iVar24 >> 8) ^ bVar19,
                                      (byte)iVar24 ^ *(byte *)(in_EDX + (int)unaff_ESI)));
  uVar27 = CONCAT22((short)(in_EDX >> 0x10),CONCAT11(bVar5 ^ bVar19,(char)in_EDX));
  pbVar30 = (byte *)CONCAT22((short)(unaff_EBX >> 0x10),
                             CONCAT11((byte)(unaff_EBX >> 8) ^ bVar19,(byte)unaff_EBX));
  bVar5 = bVar6 ^ pbVar30[(int)unaff_ESI] | 0x33;
  uVar14 = CONCAT31((int3)(CONCAT22(uVar21,CONCAT11(bVar19,bVar6)) >> 8),bVar5 - (0xcc < bVar5)) &
           0xffffff33;
  uVar14 = CONCAT31((int3)(uVar14 >> 8),(char)uVar14 + -0x33) ^ 0x33;
  uVar13 = uVar14 - 1;
  uVar32 = unaff_EBP ^ *(uint *)(uVar14 + 0x32);
  if (-1 < (int)uVar32) {
    *pbVar30 = *pbVar30 ^ 0x88;
    pbVar25 = (byte *)((uint)pbVar25 ^ (uint)&uStack_4);
    uVar27 = uVar27 ^ *(uint *)(uVar14 + 0xbc339c32) ^ (uint)&uStack_4;
    pbVar30 = (byte *)((uint)pbVar30 ^ (uint)&uStack_4);
    uVar13 = uVar13 ^ (uint)&uStack_4 ^ *unaff_ESI;
    pbVar10 = (byte *)(uVar13 + (int)unaff_ESI);
    *pbVar10 = *pbVar10 + (char)(uVar27 >> 8);
    uVar13 = uVar13 ^ 0xf8;
  }
  cVar3 = DAT_356c354c;
  bVar6 = (char)(uVar13 ^ 0x351435d4) - 0x35;
  cVar18 = (char)(uVar27 >> 8);
  DAT_356c354c = DAT_356c354c - cVar18;
  bVar5 = (byte)((uint)pbVar30 >> 8);
  if (DAT_356c354c == '\0') {
    bVar7 = 9 < (bVar6 & 0xf) | bVar7;
    bVar6 = ((bVar6 + bVar7 * '\x06' & 0xf) - 0x37) - bVar7;
code_r0x00a0f110:
    bVar7 = 9 < (bVar6 - 1 & 0xf) | bVar7;
    bVar7 = 9 < ((bVar6 - 1) + bVar7 * '\x06' & 0xf) | bVar7;
    *unaff_EDI = *unaff_EDI << 1;
    pbVar25 = pbVar25 + -1;
    if (pbVar25 == (byte *)0x0 || *unaff_EDI == '\0') {
      uVar36 = func_0xf8d8e162();
      uVar27 = (uint)((ulonglong)uVar36 >> 0x20);
      bVar7 = 9 < ((byte)uVar36 & 0xf) | bVar7;
      uVar14 = CONCAT31((int3)((ulonglong)uVar36 >> 8),(byte)uVar36 + bVar7 * '\x06') & 0xffffff0f;
      cVar3 = (char)uVar14;
      pbVar25 = (byte *)CONCAT22((short)(uVar14 >> 0x10),
                                 CONCAT11((char)((ulonglong)uVar36 >> 8) + bVar7,cVar3));
      *pbVar25 = *pbVar25 + bVar5;
      *pbVar25 = *pbVar25 | bVar5;
      uVar14 = CONCAT31((int3)((uint)pbVar25 >> 8),cVar3 + '8');
      pbVar25 = extraout_ECX_00;
LAB_00a0f132:
      uVar14 = uVar14 ^ 0x38;
      goto LAB_00a0f134;
    }
code_r0x00a0f13e:
    in(0x38);
    *pbVar25 = *pbVar25 | bVar5;
    *pbVar25 = *pbVar25 - bVar5;
    *pbVar25 = *pbVar25 ^ bVar5;
    puVar15 = &DAT_e439c439;
    bVar7 = (byte)uVar27;
    bVar33 = bVar7 < DAT_e439c473;
    bVar35 = SBORROW1(bVar7,DAT_e439c473);
    bVar34 = (char)(bVar7 - DAT_e439c473) < '\0';
LAB_00a0f174:
    if (bVar35) {
      puVar15[uVar27] = puVar15[uVar27] | bVar5;
      goto code_r0x00a0f1b5;
    }
  }
  else {
    if (cVar3 < cVar18) {
      bVar7 = 9 < (bVar6 & 0xf) | bVar7;
      bVar6 = bVar6 + bVar7 * '\x06' & 0xf;
      goto code_r0x00a0f110;
    }
    uVar14 = CONCAT31((int3)((uVar13 ^ 0x351435d4) >> 8),bVar6) ^ 0x35c835a8;
    DAT_35fc35dc = DAT_35fc35dc << 1;
    bVar7 = (byte)uVar14;
    bVar6 = bVar7 + 0x36;
    *(byte *)unaff_ESI = (byte)*unaff_ESI + cVar18 + (0xc9 < bVar7);
    bVar7 = bVar6 ^ 0x36;
    uVar14 = CONCAT31((int3)(uVar14 >> 8),bVar6) ^ 0x36;
    pcVar16 = unaff_EDI + 1;
    cVar3 = in((short)uVar27);
    *unaff_EDI = cVar3;
    unaff_EDI = pcVar16;
    if (bVar7 == 0) goto LAB_00a0f132;
    if (-1 < (char)bVar7) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
LAB_00a0f134:
    puVar15 = (undefined1 *)(uVar14 - 1);
    bVar7 = *(byte *)(uVar14 + 0x37);
    bVar6 = (byte)((uint)pbVar25 >> 8);
    bVar33 = bVar7 < bVar6;
    bVar34 = (char)(bVar7 - bVar6) < '\0';
    bVar35 = true;
    if (SBORROW1(bVar7,bVar6)) goto LAB_00a0f174;
    if ((char)bVar6 <= (char)bVar7) goto code_r0x00a0f13e;
  }
  if (bVar34) {
    pbVar30[(int)puVar15] = pbVar30[(int)puVar15] + bVar5 + bVar33;
  }
  else {
    puVar15 = (undefined1 *)((CONCAT31((int3)((uint)puVar15 >> 8),DAT_c83ac03a + -0x3b) ^ 0x3b) + 1)
    ;
  }
code_r0x00a0f1b5:
  uVar2 = (undefined3)((uint)puVar15 >> 8);
  DAT_3d583d50 = DAT_3d583d50 ^ bVar5;
  *(byte *)unaff_ESI = ((byte)*unaff_ESI - bVar5) - (CONCAT31(uVar2,0x3d) < 0x3e103df0);
  pcVar16 = (char *)(CONCAT31(uVar2,0x3d) & 0xffffff3e);
  bVar29 = (byte)(uVar27 >> 8);
  _DAT_e43ddc3a = pcVar16;
  *pcVar16 = *pcVar16 - bVar29;
  pcVar17 = pcVar16 + 1;
  bVar23 = (byte)pbVar25;
  (pcVar16 + 0x6d)[(int)unaff_ESI] = (pcVar16 + 0x6d)[(int)unaff_ESI] ^ bVar23;
  (pcVar16 + 0x7d)[(int)unaff_ESI] = (pcVar16 + 0x7d)[(int)unaff_ESI] ^ bVar29;
  pcVar16[-0x4fcf57cf] = pcVar16[-0x4fcf57cf] ^ bVar23;
  pcVar16[-0x1bcf3bcf] = pcVar16[-0x1bcf3bcf] ^ bVar5;
  bVar26 = (byte)((uint)pbVar25 >> 8);
  sVar9 = CONCAT11((byte)((uint)pcVar17 >> 8) ^ bVar26 ^ bVar29 ^ bVar5,(char)pcVar17);
  pbVar10 = (byte *)CONCAT22((short)((uint)pcVar17 >> 0x10),sVar9);
  *pbVar10 = *pbVar10 ^ bVar23;
  *(uint *)(pbVar25 + (int)unaff_ESI) = *(uint *)(pbVar25 + (int)unaff_ESI) ^ uVar32;
  *(uint *)(pbVar25 + 0x5c + (int)unaff_ESI) = *(uint *)(pbVar25 + 0x5c + (int)unaff_ESI) ^ uVar27;
  *(uint *)(pbVar25 + 0x6c + (int)unaff_ESI) =
       *(uint *)(pbVar25 + 0x6c + (int)unaff_ESI) ^ 0xe43ddc39;
  *(uint *)(pbVar10 + 0x31) = *(uint *)(pbVar10 + 0x31) ^ (uint)unaff_EDI;
  uVar14 = (uint)sVar9;
  *(uint *)(uVar14 + 0xb031a831) = *(uint *)(uVar14 + 0xb031a831) ^ 0xe43ddc39;
  *(uint *)(uVar14 + 0xc831c031) = *(uint *)(uVar14 + 0xc831c031) ^ (uint)unaff_EDI;
  puVar11 = (uint *)(uVar14 ^ uVar27);
  *puVar11 = *puVar11 ^ (uint)puVar11;
  pbVar10 = (byte *)CONCAT22((short)((uint)puVar11 >> 0x10),
                             CONCAT11((byte)((uint)puVar11 >> 8) ^ (byte)*puVar11,(byte)puVar11));
  bVar7 = *pbVar10;
  bVar6 = *pbVar10;
  bVar19 = *pbVar10;
  bVar1 = *(byte *)(CONCAT31((int3)((uint)pbVar10 >> 8),(byte)puVar11 ^ pbVar10[0x32]) + 0x31);
  iVar24 = *(int *)((uint)pbVar30 ^ 0xe43ddc39);
  uVar22 = (ushort)((uint)iVar24 >> 0x10);
  bVar20 = (byte)((uint)iVar24 >> 8) ^ *(byte *)(iVar24 + 0x32);
  iVar12 = CONCAT22(uVar22,CONCAT11(bVar20,(byte)iVar24));
  *(int *)((uint)pbVar30 ^ 0xe43ddc39) = 0x78327032;
  bVar8 = (byte)iVar24 ^ *(byte *)(iVar12 + -0x6fcd77ce);
  uVar31 = CONCAT22((short)((uint)pbVar30 >> 0x10),
                    CONCAT11(bVar5 ^ bVar19,
                             (byte)pbVar30 ^
                             *(byte *)(CONCAT31((int3)((uint)iVar12 >> 8),bVar8) + -0x3bcd5bce) ^
                             bVar20));
  bVar5 = bVar8 ^ *(byte *)(uVar31 + (int)unaff_ESI) | 0x33;
  uVar13 = CONCAT31((int3)(((uint)uVar22 << 0x10) >> 8),bVar5 - (0xcc < bVar5)) & 0xffffff33;
  uVar14 = *(uint *)(uVar31 + 0x58 + (int)unaff_ESI);
  puVar15 = (undefined1 *)((uint)unaff_EDI ^ *(uint *)((uVar31 - 100) + (int)unaff_ESI));
  uVar28 = CONCAT22((short)(uVar27 >> 0x10),CONCAT11(bVar29 ^ bVar6,(byte)uVar27 ^ bVar1 ^ bVar20))
           ^ 0xcc33c433;
  uVar13 = CONCAT31((int3)(uVar13 >> 8),(char)uVar13 + -0x33) ^ 0x33 ^ *unaff_ESI;
  uVar27 = uVar13 | 0x34;
  bVar6 = (byte)(uVar28 >> 8);
  puVar15[uVar27] = puVar15[uVar27] - bVar6;
  uVar13 = (CONCAT31((int3)(uVar13 >> 8),(char)uVar27) ^ 0x352c3519) - 1 ^ 0x35743568;
  DAT_35e435d8 = DAT_35e435d8 << 1;
  *(byte *)unaff_ESI = (byte)*unaff_ESI | bVar6;
  *(byte *)unaff_ESI = (byte)*unaff_ESI - bVar6;
  *(byte *)unaff_ESI = (byte)*unaff_ESI ^ bVar6;
  *(undefined4 *)(uVar13 - 4) = 0x35a43535;
  *(undefined4 *)(uVar13 - 4) = *(undefined4 *)(uVar13 - 4);
  *(uint *)(uVar13 - 8) =
       CONCAT22((short)((uint)pbVar25 >> 0x10),CONCAT11(bVar26 ^ bVar7,bVar23 ^ bVar20)) ^ uVar14;
  *(uint *)(uVar13 - 0xc) = uVar28;
  *(uint *)(uVar13 - 0x10) = uVar31 ^ 0xcc33c433;
  *(uint *)(uVar13 - 0x14) = uVar13;
  *(uint *)(uVar13 - 0x18) = uVar32;
  *(uint **)(uVar13 - 0x1c) = unaff_ESI;
  *(undefined1 **)(uVar13 - 0x20) = puVar15;
  uVar4 = in((short)uVar28);
  *puVar15 = uVar4;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: _V6_HeapAlloc
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl _V6_HeapAlloc(void)
{
{
  uint in_stack_00000004;
  
  if (in_stack_00000004 <= DAT_00d7aeac) {
    __lock(4);
    ___sbh_alloc_block();
    FUN_00407a04();
  }
  return;
}
}

// =================================================
// Function: __ArrayUnwind
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl
__ArrayUnwind(void *param_1,uint param_2,int param_3,_func___cdecl_void_void_ptr *param_4)
{
{
  void *in_stack_ffffffc8;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffc8);
  }
  return;
}
}

// =================================================
// Function: __CIacos
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c1d53) overlaps instruction at (ram,0x009c1d52)
    */
/* WARNING: Removing unreachable block (ram,0x009c1d10) */
/* WARNING: Removing unreachable block (ram,0x009c1d53) */
/* WARNING: Removing unreachable block (ram,0x009c1d14) */
/* WARNING: Removing unreachable block (ram,0x009c1d22) */
/* WARNING: Removing unreachable block (ram,0x009c1d72) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __CIacos(void)
{
{
  byte bVar1;
  char cVar2;
  code *pcVar3;
  undefined6 uVar4;
  char *in_EAX;
  char *pcVar5;
  int in_ECX;
  uint *puVar6;
  undefined4 in_EDX;
  undefined4 *puVar7;
  undefined4 *unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  byte in_AF;
  undefined2 in_FPUStatusWord;
  undefined1 *puStack_ccda;
  undefined1 auStack_ccd6 [52286];
  undefined1 *puStack_98;
  undefined4 uStack_24;
  
  *in_EAX = *in_EAX + (char)in_EAX;
  *(byte *)(unaff_EDI + 0x13340333) = *(byte *)(unaff_EDI + 0x13340333) ^ (byte)in_ECX;
  if (in_ECX - 1U == 0 || in_EAX != (char *)0x36533586) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar4 = *(undefined6 *)unaff_ESI;
  puStack_98 = &stack0xffffffe0;
  puVar7 = (undefined4 *)&stack0xffffffe0;
  cVar2 = '\x1d';
  do {
    unaff_EBP = unaff_EBP + -1;
    puVar7 = puVar7 + -1;
    *puVar7 = *unaff_EBP;
    cVar2 = cVar2 + -1;
  } while ('\0' < cVar2);
  puStack_ccda = auStack_ccd6;
  *unaff_ESI = *unaff_ESI >> 1;
  *(undefined2 *)uVar4 = in_FPUStatusWord;
  bVar1 = DAT_c03ebc3e + 0x78;
  DAT_c03ebc3e = DAT_c03ebc3e + 0xb6;
  if (bVar1 < 0xc2) {
    DAT_80357334 = (in_AF | 1) * '\x06' + 0x3e & 0xf;
    _DAT_ca38b138 = &DAT_c03ebc3e;
  }
  else {
    DAT_c03ebc3e = DAT_c03ebc3e ^ 0x9b;
    puVar6 = (uint *)(in_ECX - 1U ^ (uint)&puStack_ccda);
    pcVar5 = (char *)(CONCAT31(0xc03ebc,(byte)((uint)in_EDX >> 8) ^ 0x3e) ^ *puVar6 ^ 0x35ba3530);
    if (puVar6 != (uint *)0x0) {
      pcVar3 = (code *)swi(1);
      (*pcVar3)();
      return;
    }
    *pcVar5 = *pcVar5 + (char)((uint)pcVar5 >> 8);
    *pcVar5 = *pcVar5 + (char)pcVar5;
  }
  return;
}
}

// =================================================
// Function: __CIatan
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c2889) overlaps instruction at (ram,0x009c2888)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __CIatan(void)
{
{
  uint uVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  char cVar8;
  ushort uVar9;
  uint in_EAX;
  uint uVar10;
  uint uVar11;
  uint in_ECX;
  uint *puVar12;
  int iVar13;
  int *in_EDX;
  uint unaff_EBX;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  uint *puVar17;
  uint unaff_EBP;
  uint unaff_ESI;
  int unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  byte in_AF;
  uint uVar18;
  
  *(uint *)(in_ECX + 0x31) = *(uint *)(in_ECX + 0x31) ^ unaff_EBX;
  *(uint *)(unaff_EBX + 0xb431a031) = *(uint *)(unaff_EBX + 0xb431a031) ^ unaff_EBX;
  puVar12 = (uint *)(in_EAX ^ unaff_EBP);
  *puVar12 = *puVar12 ^ in_ECX;
  bVar5 = DAT_44322632;
  puVar14 = (uint *)(uint)DAT_44322632;
  bVar2 = *(byte *)((int)in_EDX + 0x32);
  uVar1 = *puVar14;
  *puVar14 = *puVar14 + unaff_ESI;
  *puVar14 = *puVar14 + unaff_ESI + (uint)CARRY4(uVar1,unaff_ESI);
  *puVar14 = *puVar14 & unaff_ESI;
  *puVar14 = *puVar14 ^ unaff_ESI;
  uVar1 = _DAT_35ad358d;
  if ((POPCOUNT(*puVar14 & 0xff) & 1U) != 0) {
    uVar10 = in_ECX ^ 0x3527352c;
    LOCK();
    UNLOCK();
    puVar15 = (uint *)(uint)CONCAT11(0x35,bVar5);
    uVar9 = (ushort)(byte)((char)uVar10 + (char)(uVar10 >> 8) * '5');
    iVar13 = CONCAT22((short)((uint)puVar12 >> 0x10),
                      CONCAT11((byte)((uint)puVar12 >> 8) ^ bVar2,(char)puVar12)) + -1;
    _DAT_35ad358d = *puVar14 * 0x3376336f;
    if (iVar13 != 0 && uVar9 == 0) {
      LOCK();
      iVar3 = *in_EDX;
      *in_EDX = unaff_EDI;
      UNLOCK();
      *in_EDX = *in_EDX >> 0x13;
      unaff_EDI = iVar3;
    }
    iVar3 = *(int *)CONCAT22((short)(uVar10 >> 0x10),uVar9);
    *(undefined4 *)(iVar3 + -4) = 0x703d6c3d;
    pbVar4 = _DAT_3dde3dd6;
    if ((int)&stack0xfffffffd < 0x3d783d74) {
      unaff_EBP = unaff_EBP ^ *(uint *)(unaff_EDI + -0x36cc3ccd);
    }
    LOCK();
    UNLOCK();
    bVar5 = (byte)&stack0xfffffffd;
    out(0x3d,bVar5);
    out((short)in_EDX,bVar5);
    _DAT_3dde3dd6 = (byte *)unaff_EDI;
    *(undefined2 *)(iVar3 + -8) = in_ES;
    bVar2 = 9 < (bVar5 & 0xf) | in_AF;
    bVar6 = bVar5 + bVar2 * -6 & 0xf;
    *(undefined2 *)(iVar3 + -0xc) = in_CS;
    bVar5 = 9 < bVar6 | bVar2;
    uVar10 = CONCAT31((int3)((uint)&stack0xfffffffd >> 8),bVar6 + bVar5 * -6) & 0xffff000f;
    cVar7 = (char)uVar10;
    *(uint *)(iVar3 + -0x10) = unaff_EBP;
    cVar8 = cVar7 * '\x02' + '5';
    puVar12 = (uint *)CONCAT31((int3)(CONCAT22((short)(uVar10 >> 0x10),
                                               CONCAT11(((char)((uint)&stack0xfffffffd >> 8) - bVar2
                                                        ) - bVar5,cVar7)) >> 8),cVar8);
    *(char *)puVar12 = (char)*puVar12 + cVar8;
    *(char *)(unaff_EBP + 0xf330dc30) =
         *(char *)(unaff_EBP + 0xf330dc30) + (char)((uint)iVar13 >> 8);
    *pbVar4 = *pbVar4 ^ (byte)in_EDX;
    *puVar12 = *puVar12 ^ iVar3 - 0x10U;
    *(uint *)(uVar1 + 0xec32d432) = *(uint *)(uVar1 + 0xec32d432) ^ uVar1;
    uVar10 = *puVar15;
    uVar16 = (iVar3 - 0x10U ^ *puVar15) + 4 ^ *(uint *)((int)puVar15 + 0x33);
    *(undefined2 *)(uVar16 - 4) = in_CS;
    puVar17 = (uint *)(uVar16 - 8);
    *(undefined4 *)(uVar16 - 8) = 0x9c288f;
    uVar11 = func_0xc333af33();
    uVar18 = *puVar17;
    *(undefined4 *)pbVar4 = *(undefined4 *)(uVar1 ^ uVar10 ^ *puVar15);
    *(uint *)(pbVar4 + (uint)((uVar18 & 0x400) != 0) * -8 + 4) = uVar11 ^ 0x366135f7;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(byte *)puVar14 = (byte)*puVar14 ^ 0xac;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: __CIatan2
// =================================================
void __cdecl __CIatan2(void)
{
{
  undefined1 in_AL;
  int *in_ECX;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = in_AL;
  *in_ECX = *in_ECX >> 0x13;
  return;
}
}

// =================================================
// Function: __CIcos
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c1f50) overlaps instruction at (ram,0x009c1f4f)
    */
/* WARNING: Removing unreachable block (ram,0x009c1fc6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __CIcos(void)
{
{
  byte *pbVar1;
  byte bVar2;
  undefined1 uVar3;
  code *pcVar4;
  byte bVar5;
  uint *in_EAX;
  uint uVar6;
  int iVar7;
  int in_ECX;
  int in_EDX;
  undefined1 *unaff_EBX;
  uint *puVar8;
  uint unaff_EBP;
  uint *unaff_ESI;
  uint *puVar9;
  uint *unaff_EDI;
  byte in_AF;
  bool in_OF;
  
  if (!in_OF) {
    *(char *)((int)in_EAX * 2) = *(char *)((int)in_EAX * 2) + (char)((uint)in_EAX >> 8);
    pbVar1 = (byte *)(in_ECX + 0x30);
    bVar2 = *pbVar1;
    bVar5 = (byte)in_EDX;
    *pbVar1 = *pbVar1 + bVar5;
    if (CARRY1(bVar2,bVar5)) {
      uVar3 = *unaff_EBX;
      unaff_EBX = unaff_EBX + 1;
      uVar6 = uRam7338ba38 ^ 0x35fa3546;
      puVar9 = (uint *)((uint)unaff_ESI & *unaff_ESI);
      *puVar9 = *puVar9 ^ (uint)puVar9;
      in_EDX = CONCAT22((short)((uint)in_EDX >> 0x10),CONCAT11(uVar3,bVar5)) + -1;
      unaff_ESI = (uint *)((uint)puVar9 ^ *unaff_EDI);
      iVar7 = uVar6 + 1;
      in_AF = 9 < ((byte)iVar7 & 0xf) | in_AF;
      uVar6 = CONCAT31((int3)((uint)iVar7 >> 8),(byte)iVar7 + in_AF * '\x06') & 0xffffff0f;
      in_EAX = (uint *)CONCAT22((short)(uVar6 >> 0x10),
                                CONCAT11((char)((uint)iVar7 >> 8) + in_AF,(char)uVar6));
      *in_EAX = *in_EAX ^ (uint)unaff_EDI;
      unaff_EDI = (uint *)((int)unaff_EDI + 1);
    }
    else {
      *(byte *)(in_ECX + -0x5ccf45d0) =
           *(byte *)(in_ECX + -0x5ccf45d0) ^ (byte)((uint)unaff_EBX >> 8);
      *(uint *)(unaff_EBX + 0x42332131) = *(uint *)(unaff_EBX + 0x42332131) ^ (uint)unaff_ESI;
    }
    bVar2 = 9 < ((byte)unaff_EBX & 0xf) | in_AF;
    uVar6 = CONCAT31((int3)((uint)unaff_EBX >> 8),(byte)unaff_EBX + bVar2 * -6) & 0xffffff0f;
    bVar5 = (byte)uVar6;
    puVar9 = (uint *)CONCAT22((short)(uVar6 >> 0x10),
                              CONCAT11((char)((uint)unaff_EBX >> 8) - bVar2,bVar5));
    *(byte *)puVar9 = (byte)*puVar9 + bVar5;
    *(byte *)(puVar9 + 0x1f0015) = (byte)puVar9[0x1f0015] + (char)in_EDX;
    *(byte *)puVar9 = (byte)*puVar9 + bVar5;
    uVar6 = *puVar9;
    *puVar9 = *puVar9 + (int)unaff_ESI;
    uVar6 = CONCAT22((short)((uint)in_EDX >> 0x10),
                     CONCAT11(((char)((uint)in_EDX >> 8) - (byte)*puVar9) -
                              CARRY4(uVar6,(uint)unaff_ESI),(char)in_EDX)) + 1;
    puVar8 = (uint *)CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX ^ (byte)(uVar6 >> 8));
    *(byte *)puVar9 = (byte)*puVar9 ^ bVar5;
    puVar9 = (uint *)(uVar6 ^ unaff_EBP);
    *puVar9 = *puVar9 ^ (uint)puVar9;
    *puVar8 = *puVar8 ^ 0xffffffc7;
    *(char *)((int)unaff_ESI + *unaff_ESI) =
         *(char *)((int)unaff_ESI + *unaff_ESI) + (char)((uint)puVar9 >> 8) +
         CARRY4((uint)unaff_ESI,*unaff_ESI);
    *unaff_EDI = *unaff_EDI << 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pcVar4 = (code *)swi(1);
  (*pcVar4)();
  return;
}
}

// =================================================
// Function: __CIexp
// =================================================
/* WARNING: Control flow encountered bad instruction data */

void __cdecl __CIexp(void)
{
{
  char *in_EAX;
  int unaff_EBP;
  ushort unaff_SI;
  
  *in_EAX = *in_EAX + (char)in_EAX;
  *(ushort *)(unaff_EBP + 0x31) = *(ushort *)(unaff_EBP + 0x31) ^ unaff_SI;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: __CIfmod
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c2a32) overlaps instruction at (ram,0x009c2a30)
    */
/* WARNING: Removing unreachable block (ram,0x009c2a32) */

void __cdecl __CIfmod(void)
{
{
  byte *pbVar1;
  int iVar2;
  char cVar3;
  byte *pbVar4;
  byte *in_ECX;
  uint uVar5;
  char in_DL;
  uint *unaff_EBX;
  undefined4 *puVar6;
  undefined4 *unaff_EBP;
  int *unaff_ESI;
  uint *puVar7;
  char in_ES;
  byte in_stack_0000002a;
  uint in_stack_c133bb2a;
  undefined1 auStack_6c6 [1722];
  undefined4 uStack_c;
  undefined4 in_stack_fffffff8;
  
  iVar2 = *unaff_ESI;
  puVar6 = (undefined4 *)&stack0xfffffff8;
  cVar3 = '\x1e';
  do {
    unaff_EBP = unaff_EBP + -1;
    puVar6 = puVar6 + -1;
    *puVar6 = *unaff_EBP;
    cVar3 = cVar3 + -1;
  } while ('\0' < cVar3);
  pbVar4 = (byte *)CONCAT31((int3)(CONCAT22((short)((uint)in_stack_fffffff8 >> 0x10),
                                            CONCAT11(0x3e,in_ES)) >> 8),in_ES + 0x3eU);
  *pbVar4 = *pbVar4 + (char)((uint)in_ECX >> 8);
  *(byte **)pbVar4 = pbVar4 + *(int *)pbVar4;
  *(char *)unaff_EBX = (char)*unaff_EBX + in_DL;
  *in_ECX = *in_ECX ^ 0x3e;
  pbVar1 = (byte *)(iVar2 * 0x3ea33e6e + 0xd630c330);
  *pbVar1 = *pbVar1 ^ (byte)unaff_EBX;
  *pbVar4 = *pbVar4 ^ in_ES + 0x3eU;
  *(uint *)((int)unaff_EBX + -0x3dce57cf) =
       *(uint *)((int)unaff_EBX + -0x3dce57cf) ^ (uint)auStack_6c6;
  uVar5 = (uint)in_ECX ^ (uint)&stack0xfffffff8;
  *unaff_EBX = *unaff_EBX ^ (uint)pbVar4;
  puVar7 = (uint *)((uint)unaff_ESI ^ in_stack_c133bb2a ^
                    CONCAT22((short)(uVar5 >> 0x10),
                             CONCAT11((byte)(uVar5 >> 8) ^ in_stack_0000002a,
                                      (byte)uVar5 ^ *pbVar4 ^ *(byte *)((int)unaff_ESI + 0x32))) ^
                    (int)&uStack_c + 3U ^ iVar2 * 0x3ea33e6e ^ (uint)pbVar4);
  puRamfffffffc = unaff_EBX;
  *puVar7 = *puVar7 ^ 0x36ac3693;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: __CIlog
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c233b) overlaps instruction at (ram,0x009c233a)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009c222a) */
/* WARNING: Removing unreachable block (ram,0x009c2240) */
/* WARNING: Removing unreachable block (ram,0x009c2246) */
/* WARNING: Removing unreachable block (ram,0x009c2254) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __CIlog(void)
{
{
  short sVar1;
  code *pcVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  char cVar13;
  byte *in_EAX;
  undefined3 uVar14;
  char *pcVar10;
  undefined4 uVar11;
  ushort *puVar12;
  byte *in_ECX;
  byte *extraout_ECX;
  byte *pbVar15;
  int in_EDX;
  int extraout_EDX;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  uint *puVar19;
  undefined2 uVar20;
  undefined4 unaff_EBX;
  uint *puVar21;
  undefined1 *puVar22;
  undefined4 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  byte *unaff_EBP;
  int unaff_ESI;
  byte *pbVar26;
  byte *pbVar27;
  uint *unaff_EDI;
  uint *puVar28;
  bool bVar29;
  byte in_AF;
  byte in_OF;
  undefined1 *puStack_28;
  uint *puStack_24;
  byte *pbStack_20;
  
  puVar21 = (uint *)CONCAT31((int3)((uint)unaff_EBX >> 8),0x34);
  *(byte *)(puVar21 + unaff_ESI) = 0;
  pbVar26 = (byte *)_DAT_36633651;
  puStack_24 = unaff_EDI;
  if ((bool)(in_OF & 1)) {
    bVar5 = func_0xf136e336();
    bVar7 = 9 < (bVar5 & 0xf) | in_AF;
    puStack_24 = (uint *)((int)unaff_EDI + 1);
    *(byte *)unaff_EDI = bVar5 + bVar7 * '\x06' & 0xf;
    bVar7 = bVar7 | 1;
    bVar6 = bVar7 * -6 + 0x3e & 0xf;
    bVar5 = 9 < bVar6 | bVar7;
    bVar6 = bVar6 + bVar5 * -6 & 0xf;
    in_EDX = extraout_EDX + 1;
    in_AF = 9 < bVar6 | bVar5;
    uVar16 = CONCAT31(0x13e00,bVar6 + in_AF * -6) & 0xffffff0f;
    in_EAX = (byte *)CONCAT22((short)(uVar16 >> 0x10),
                              CONCAT11(((-0x31 - bVar7) - bVar5) - in_AF,(char)uVar16));
    in_ECX = extraout_ECX;
    if ((bool)in_AF) goto LAB_009c21a4;
    in_EAX = (byte *)CONCAT31((int3)((uint)in_EAX >> 8),uRam1a3e013c);
    uVar16 = extraout_EDX + 2;
  }
  else {
LAB_009c21a4:
    *(char *)((int)in_EAX * 2) = *(char *)((int)in_EAX * 2) + '4';
    *(byte *)puVar21 = (byte)*puVar21 + (byte)in_EDX;
    bVar7 = (byte)((uint)in_EAX >> 8);
    *in_EAX = *in_EAX ^ bVar7;
    *(byte *)((int)puVar21 + 0x74326331) = *(byte *)((int)puVar21 + 0x74326331) ^ bVar7;
    if ((int)&stack0x00000000 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    puVar21 = (uint *)CONCAT22((short)((uint)unaff_EBX >> 0x10),
                               CONCAT11(((char)((uint)unaff_EBX >> 8) - *pbVar26) -
                                        ((char)in_EAX == '\0'),0x34));
    uVar16 = CONCAT31((int3)((uint)in_EDX >> 8),(byte)in_EDX ^ pbVar26[0x1632a932]) + 1;
  }
  puStack_28 = (undefined1 *)&puStack_24;
  *in_EAX = *in_EAX + (char)in_EAX;
  uVar14 = (undefined3)((uint)in_EAX >> 8);
  bVar7 = (char)in_EAX + (char)(uVar16 >> 8);
  puVar19 = (uint *)CONCAT31(uVar14,bVar7);
  *(char *)((int)puVar19 * 2) = *(char *)((int)puVar19 * 2) + (char)((uint)puVar21 >> 8);
  *in_ECX = *in_ECX + bVar7;
  *(byte *)puVar21 = (byte)*puVar21 ^ (byte)uVar16;
  bVar5 = (byte)((uint)in_EAX >> 8);
  *in_ECX = *in_ECX ^ bVar5;
  *(byte *)(uVar16 + 0x30) = *(byte *)(uVar16 + 0x30) ^ (byte)in_ECX;
  *puVar19 = *puVar19 ^ 0xffffff91;
  *(byte *)(uVar16 + 0xd031c330) = *(byte *)(uVar16 + 0xd031c330) ^ (byte)((uint)in_ECX >> 8);
  *(uint *)((int)puVar21 + 0x11329432) = *(uint *)((int)puVar21 + 0x11329432) ^ (uint)puVar19;
  puVar22 = (undefined1 *)((uint)&puStack_28 ^ *puStack_24);
  puVar17 = (uint *)(uVar16 ^ *(uint *)(uVar16 + 0x33));
  bVar29 = puVar19 < (uint *)0x3d513d43;
  pbVar27 = pbVar26;
  puVar28 = puStack_24;
  if ((POPCOUNT((int)puVar19 + 0xc2aec2bdU & 0xff) & 1U) == 0) {
    uVar11 = in(0x36);
code_r0x009c22b4:
    bVar7 = (byte)uVar11;
    out((short)puVar17,bVar7);
    iVar18 = CONCAT22((short)((uint)puVar17 >> 0x10),
                      CONCAT11((char)((uint)puVar17 >> 8) + (char)*puVar28 + bVar29,(char)puVar17));
    *puVar28 = *puVar28 & (uint)pbVar27;
    puVar19 = (uint *)(iVar18 + 1);
    in_AF = 9 < (bVar7 & 0xf) | in_AF;
    uVar16 = CONCAT31((int3)((uint)uVar11 >> 8),bVar7 + in_AF * '\x06') & 0xffffff0f;
    puVar12 = (ushort *)
              CONCAT22((short)(uVar16 >> 0x10),
                       CONCAT11((char)((uint)uVar11 >> 8) + in_AF,(char)uVar16));
    *(ushort *)puVar28 =
         (short)*puVar28 + (ushort)in_AF * (((ushort)pbVar27 & 3) - ((ushort)*puVar28 & 3));
    if (!SCARRY4(iVar18,1)) {
      pcVar2 = (code *)swi(1);
      pbStack_20 = pbVar26;
      (*pcVar2)();
      return;
    }
LAB_009c22f7:
    pcVar10 = (char *)((int)puVar12 * 2 + 0x30010000);
    *pcVar10 = *pcVar10 + (char)puVar21;
    bVar7 = (byte)((uint)puVar19 >> 8);
    uVar3 = *puVar12;
    uVar4 = *puVar12;
    uVar20 = (undefined2)((uint)puVar19 >> 0x10);
    sVar1 = ((ushort)pbVar27 & 3) - (*puVar12 & 3);
    *puVar12 = *puVar12 + (ushort)(bVar7 < (byte)*puVar12) * sVar1;
    puVar17 = (uint *)CONCAT22(uVar20,CONCAT11(bVar7 - (byte)uVar4,(char)puVar19));
    puVar24 = puVar22;
    pbVar26 = pbVar27;
    if (!SBORROW1(bVar7,(byte)uVar3)) goto LAB_009c2334;
    puVar17 = (uint *)CONCAT22(uVar20,CONCAT11((byte)*puVar12,(char)puVar19));
    *(int *)in_ECX = *(int *)in_ECX << ((byte)in_ECX & 0x1f);
    bVar29 = ((uint)in_ECX & 0x1f) == 0;
    pbVar15 = in_ECX + -1;
    puStack_24 = puVar28;
    if (pbVar15 == (byte *)0x0 || (bVar29 && 0 < sVar1 || !bVar29 && *(int *)in_ECX == 0)) {
code_r0x009c230a:
      puVar21 = (uint *)CONCAT22((short)((uint)puVar21 >> 0x10),
                                 CONCAT11((byte)((uint)puVar21 >> 8) ^ (byte)pbVar15,(char)puVar21))
      ;
      in_ECX = (byte *)((uint)pbVar15 ^ *(uint *)((int)puVar12 + -0x6fcc73cd));
      puVar19 = (uint *)(CONCAT31((int3)((uint)puVar17 >> 8),
                                  (byte)puVar17 ^ ((byte *)((int)puVar21 + 0x5b))[(int)pbVar26]) ^
                        *(uint *)((int)(puVar21 + 0xd010ce6) + (int)pbVar26));
      puVar24[(int)in_ECX] = puVar24[(int)in_ECX] | (byte)((uint)puVar19 >> 8);
      uVar16 = (uint)puVar12 ^ 0x2b;
      puVar28 = puStack_24;
      goto LAB_009c232f;
    }
    bVar7 = 9 < (byte)puVar12 | in_AF;
    uVar16 = CONCAT31((int3)((uint)puVar12 >> 8),(byte)puVar12 + bVar7 * '\x06') & 0xffffff0f;
    pcVar10 = (char *)CONCAT22((short)(uVar16 >> 0x10),
                               CONCAT11((char)((uint)puVar12 >> 8) + bVar7,(char)uVar16));
code_r0x009c233c:
    _DAT_3c393834 = 0x3c393838;
    puVar25 = (undefined1 *)0x3c393838;
    puVar19 = (uint *)((int)puVar28 + 1);
    cVar13 = in((short)puVar17);
    *(char *)puVar28 = cVar13;
    pbVar26 = *(byte **)(pcVar10 + 0x39);
    if ((pbVar26 != pbVar27) && (-1 < (int)pbVar26 - (int)pbVar27)) {
      if ((int)pbVar26 < (int)pbVar27) goto LAB_009c239b;
      goto LAB_009c2373;
    }
  }
  else {
    puVar21 = (uint *)CONCAT31((int3)((uint)puVar21 >> 8),0x3d);
    _DAT_3f233dda = _DAT_3f233dda >> 0x10;
    in_AF = 9 < (bVar7 & 0xf) | in_AF;
    uVar16 = CONCAT31(uVar14,bVar7 + in_AF * -6) & 0xffffff0f;
    bVar7 = (byte)uVar16;
    pcVar10 = (char *)CONCAT22((short)(uVar16 >> 0x10),CONCAT11(bVar5 - in_AF,bVar7));
    *pcVar10 = *pcVar10 + bVar7;
    *pcVar10 = *pcVar10 + bVar7;
    *(byte **)(puVar22 + -4) = unaff_EBP;
    bVar5 = (byte)((uint)puVar17 >> 8);
    *(char *)((int)pcVar10 * 2) = *(char *)((int)pcVar10 * 2) + bVar5;
    in_ECX[-0x2ecf3cd0] = in_ECX[-0x2ecf3cd0] + bVar5;
    *(byte *)puVar21 = (byte)*puVar21 ^ bVar5;
    *(uint *)(in_ECX + 0x31) = *(uint *)(in_ECX + 0x31) ^ (uint)pcVar10;
    puVar17 = *(uint **)(puVar22 + -4);
    *puVar21 = *puVar21 ^ (uint)pbVar26;
    bVar7 = bVar7 ^ pcVar10[0x32] ^ *(byte *)((int)puVar21 + (int)pbVar26);
    puVar19 = (uint *)CONCAT31((int3)((uint)pcVar10 >> 8),bVar7);
    pbVar15 = in_ECX + -1;
    if (pbVar15 == (byte *)0x0 || bVar7 != 0) {
      puVar22 = (undefined1 *)((uint)puVar22 ^ *puVar17);
      bVar29 = false;
      in_ECX = (byte *)CONCAT31((int3)((uint)pbVar15 >> 8),0x36);
      uVar11 = in(0x36);
      pbVar27 = pbVar26 + 4;
      puVar28 = puStack_24 + 1;
      goto code_r0x009c22b4;
    }
    if (puVar17 < *(uint **)(in_ECX + 0x3b)) {
      puVar12 = (ushort *)((int)(short)puVar19 ^ *(uint *)(puVar22 + (int)pbVar26));
      puVar24 = puVar22;
      goto code_r0x009c230a;
    }
    bVar5 = *pbVar26;
    bVar6 = 9 < ((byte)puVar17 & 0xf) | in_AF;
    uVar16 = CONCAT31((int3)((uint)puVar17 >> 8),(byte)puVar17 + bVar6 * -6) & 0xffffff0f;
    bVar8 = (byte)uVar16;
    cVar13 = (char)((uint)puVar17 >> 8) - bVar6;
    uVar11 = CONCAT22((short)(uVar16 >> 0x10),CONCAT11(cVar13,bVar8));
    *(undefined4 *)(puVar22 + -4) = uVar11;
    *(byte **)(puVar22 + -8) = pbVar15;
    *(uint **)(puVar22 + -0xc) = puVar19;
    *(uint **)(puVar22 + -0x10) = puVar21;
    *(undefined1 **)(puVar22 + -0x14) = puVar22;
    *(byte **)(puVar22 + -0x18) = unaff_EBP;
    *(byte **)(puVar22 + -0x1c) = pbVar26;
    puVar24 = puVar22 + -0x20;
    *(uint **)(puVar22 + -0x20) = puStack_24;
    in_AF = 9 < bVar8 | bVar6;
    uVar16 = CONCAT31((int3)((uint)uVar11 >> 8),bVar8 + in_AF * -6) & 0xffffff0f;
    bVar6 = (byte)uVar16;
    cVar13 = cVar13 - in_AF;
    uVar16 = CONCAT22((short)(uVar16 >> 0x10),CONCAT11(cVar13,bVar6));
    in_ECX = in_ECX + -2;
    if (in_ECX == (byte *)0x0 || bVar5 != 0x53) {
      in_AF = 9 < bVar6 | in_AF;
      uVar16 = CONCAT31((int3)(uVar16 >> 8),bVar6 + in_AF * -6) & 0xffffff0f;
      cVar9 = (char)uVar16;
      puVar12 = (ushort *)CONCAT22((short)(uVar16 >> 0x10),CONCAT11(cVar13 - in_AF,cVar9));
      *(byte *)puVar12 = (byte)*puVar12 + cVar9;
      *(byte *)puVar12 = (byte)*puVar12 + bVar7;
      puVar23 = (undefined4 *)(puVar22 + -0x24);
      puVar22 = puVar22 + -0x24;
      *puVar23 = unaff_EBP;
      goto LAB_009c22f7;
    }
LAB_009c232f:
    puVar12 = (ushort *)(uVar16 ^ 0x3673351a);
    puVar17 = puVar19;
LAB_009c2334:
    *pbVar26 = *pbVar26 ^ 0x33;
    bVar7 = 9 < ((byte)puVar12 & 0xf) | in_AF;
    bVar6 = (byte)puVar12 + bVar7 * '\x06' & 0xf;
    puVar25 = puVar24 + 1;
    bVar5 = 9 < bVar6 | bVar7;
    uVar16 = CONCAT31((int3)((uint)puVar12 >> 8),bVar6 + bVar5 * '\x06') & 0xffff000f;
    pcVar10 = (char *)CONCAT22((short)(uVar16 >> 0x10),
                               CONCAT11((char)((uint)puVar12 >> 8) + bVar7 + bVar5,(char)uVar16));
    pbVar15 = in_ECX + -1;
    pbVar27 = pbVar26;
    puVar19 = puVar28;
    if (pbVar15 == (byte *)0x0 || puVar24 == (undefined1 *)0xffffffff) goto code_r0x009c233c;
LAB_009c2373:
    bVar7 = *pbVar27;
    *(int *)pbVar27 = *(int *)pbVar27 >> 0x1a;
    puVar21 = (uint *)CONCAT31(CONCAT21((short)((uint)puVar21 >> 0x10),bVar7),0x3f);
    *(char *)puVar19 = (char)*puVar19;
    *unaff_EBP = *unaff_EBP & (byte)puVar17;
    *(char **)(puVar25 + -4) = pcVar10;
    *(byte **)(puVar25 + -8) = pbVar15;
    *(uint **)(puVar25 + -0xc) = puVar17;
    *(uint **)(puVar25 + -0x10) = puVar21;
    *(undefined1 **)(puVar25 + -0x14) = puVar25;
    *(byte **)(puVar25 + -0x18) = unaff_EBP;
    *(byte **)(puVar25 + -0x1c) = pbVar27;
    *(uint **)(puVar25 + -0x20) = puVar19;
    *pcVar10 = *pcVar10 + (char)pcVar10;
  }
  puVar17 = (uint *)CONCAT31((int3)((uint)puVar17 >> 8),(byte)puVar17 ^ (byte)((uint)puVar21 >> 8));
LAB_009c239b:
  *(byte *)puVar17 = (byte)*puVar17 ^ (byte)((uint)pcVar10 >> 8);
  *puVar21 = *puVar21 ^ (uint)pcVar10;
  *(byte *)puVar19 =
       (char)*puVar19 +
       (((byte)((uint)puVar17 >> 8) ^ *(byte *)((int)puVar21 + 0x4133c033) | *pbVar27) ^ *pbVar27) +
       CARRY4((uint)pbVar27,*puVar19);
  return;
}
}

// =================================================
// Function: __CIsin
// =================================================
void __cdecl __CIsin(void)
{
{
  byte *pbVar1;
  char cVar2;
  byte bVar6;
  undefined4 in_EAX;
  uint3 uVar7;
  byte *pbVar5;
  int in_ECX;
  uint *puVar8;
  byte bVar10;
  undefined4 in_EDX;
  undefined4 *puVar9;
  uint unaff_EBX;
  undefined1 *unaff_ESI;
  uint *unaff_EDI;
  byte in_AF;
  uint uVar3;
  char *pcVar4;
  
  uVar7 = (uint3)((uint)in_EAX >> 8);
  puVar8 = (uint *)CONCAT31(uVar7,*unaff_ESI);
  puVar9 = (undefined4 *)
           (CONCAT22((short)((uint)in_EDX >> 0x10),
                     CONCAT11((byte)((uint)in_EDX >> 8) ^ *(byte *)((int)puVar8 + 0x332b432),
                              (char)in_EDX)) ^ *puVar8);
  uVar7 = uVar7 ^ (uint3)((uint)in_ECX >> 8) ^ (uint3)((uint)*puVar9 >> 8);
  pbVar1 = (byte *)((int)(unaff_ESI + 1) + *(int *)(unaff_ESI + 1));
  bVar10 = (byte)((uint)puVar9 >> 8);
  *pbVar1 = *pbVar1 & bVar10;
  puVar8 = (uint *)(in_ECX + -1);
  if (puVar8 == (uint *)0x0 || *pbVar1 != 0) {
    *unaff_EDI = *unaff_EDI ^ 0xffffff90;
    *puVar8 = *puVar8 ^ (uint)unaff_EDI;
    return;
  }
  bVar6 = 9 < (*pbVar1 & 0xf) | in_AF;
  uVar3 = (CONCAT31(uVar7,*pbVar1 + bVar6 * -6) ^ 0x35c23500) & 0xffffff0f;
  cVar2 = (char)uVar3;
  bVar6 = ((byte)uVar7 ^ 0x35) - bVar6;
  pcVar4 = (char *)CONCAT22((short)(uVar3 >> 0x10),CONCAT11(bVar6,cVar2));
  *pcVar4 = *pcVar4 + cVar2;
  pcVar4[0x600054] = pcVar4[0x600054] + bVar10;
  *pcVar4 = *pcVar4 + cVar2;
  pbVar5 = (byte *)CONCAT31((int3)((uint)pcVar4 >> 8),cVar2 - 0x30U);
  *(byte *)(unaff_EDI + 0xc) = (byte)unaff_EDI[0xc] ^ bVar6;
  *pbVar5 = *pbVar5 ^ cVar2 - 0x30U;
  *(uint *)(in_ECX + -0x15cd38cf) = *(uint *)(in_ECX + -0x15cd38cf) ^ (uint)(pbVar1 + 1);
  *(byte *)(unaff_EBX ^ (uint)puVar9) = *(byte *)(unaff_EBX ^ (uint)puVar9) ^ 0xa1;
  return;
}
}

// =================================================
// Function: __CItan
// =================================================
/* WARNING: Control flow encountered bad instruction data */

void __cdecl __CItan(void)
{
{
  uint in_ECX;
  uint unaff_EBP;
  uint unaff_ESI;
  uint *puVar1;
  uint unaff_EDI;
  
  puVar1 = (uint *)(unaff_ESI ^ in_ECX ^ unaff_EBP ^ unaff_EDI);
  *puVar1 = *puVar1 ^ 0x36ac3693;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: __CxxThrowException_8
// =================================================
void __cdecl __CxxThrowException_8(void)
{
{
  int iVar1;
  DWORD *pDVar2;
  DWORD *pDVar3;
  byte *in_stack_00000008;
  DWORD local_24 [4];
  DWORD local_14;
  ULONG_PTR local_10 [3];
  
  pDVar2 = &DAT_00b2c83c;
  pDVar3 = local_24;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pDVar3 = *pDVar2;
    pDVar2 = pDVar2 + 1;
    pDVar3 = pDVar3 + 1;
  }
  if ((in_stack_00000008 != (byte *)0x0) && ((*in_stack_00000008 & 8) != 0)) {
    local_10[0] = 0x1994000;
  }
  RaiseException(local_24[0],local_24[1],local_14,local_10);
  return;
}
}

// =================================================
// Function: __FF_MSGBANNER
// =================================================
void __cdecl __FF_MSGBANNER(void)
{
{
  int iVar1;
  
  iVar1 = __set_error_mode(3);
  if (iVar1 != 1) {
    iVar1 = __set_error_mode(3);
    if (iVar1 != 0) {
      return;
    }
    if (DAT_00cca1b0 != 1) {
      return;
    }
  }
  __NMSG_WRITE(0xfc);
  __NMSG_WRITE(0xff);
  return;
}
}

// =================================================
// Function: __NMSG_WRITE
// =================================================
void __cdecl __NMSG_WRITE(int param_1)
{
{
  undefined4 *puVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  HANDLE hFile;
  uint uVar5;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  DWORD local_4;
  
  uVar5 = 0;
  do {
    if (param_1 == (&DAT_00cca228)[uVar5 * 2]) break;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x17);
  if (uVar5 < 0x17) {
    iVar2 = __set_error_mode(3);
    if ((iVar2 == 1) || ((iVar2 = __set_error_mode(3), iVar2 == 0 && (DAT_00cca1b0 == 1)))) {
      hFile = GetStdHandle(0xfffffff4);
      if ((hFile != (HANDLE)0x0) && (hFile != (HANDLE)0xffffffff)) {
        lpOverlapped = (LPOVERLAPPED)0x0;
        lpNumberOfBytesWritten = &local_4;
        puVar1 = (undefined4 *)(uVar5 * 8 + 0xcca22c);
        uVar5 = _strlen((char *)*puVar1);
        WriteFile(hFile,(LPCVOID)*puVar1,uVar5,lpNumberOfBytesWritten,lpOverlapped);
      }
    }
    else if (param_1 != 0xfc) {
      iVar2 = _strcpy_s(&DAT_00d53ab0,0x314,"Runtime Error!\n\nProgram: ");
      if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      DAT_00d53bcd = 0;
      DVar3 = GetModuleFileNameA((HMODULE)0x0,&DAT_00d53ac9,0x104);
      if ((DVar3 == 0) &&
         (iVar2 = _strcpy_s(&DAT_00d53ac9,0x2fb,"<program name unknown>"), iVar2 != 0)) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      uVar4 = _strlen(&DAT_00d53ac9);
      if (0x3c < uVar4 + 1) {
        uVar4 = _strlen(&DAT_00d53ac9);
        iVar2 = _strncpy_s((char *)(uVar4 + 0xd53a8e),(int)&DAT_00d53dc4 - (int)(uVar4 + 0xd53a8e),
                           "...",3);
        if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
      }
      iVar2 = _strcat_s(&DAT_00d53ab0,0x314,"\n\n");
      if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      iVar2 = _strcat_s(&DAT_00d53ab0,0x314,*(char **)(uVar5 * 8 + 0xcca22c));
      if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      ___crtMessageBoxA(&DAT_00d53ab0,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}
}

// =================================================
// Function: __VEC_memcpy
// =================================================
void __cdecl __VEC_memcpy(void)
{
{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 *in_stack_00000004;
  undefined4 *in_stack_00000008;
  uint in_stack_0000000c;
  
  uVar2 = (int)in_stack_00000008 >> 0x1f;
  iVar1 = (((uint)in_stack_00000008 ^ uVar2) - uVar2 & 0xf ^ uVar2) - uVar2;
  uVar2 = (int)in_stack_00000004 >> 0x1f;
  uVar4 = ((uint)in_stack_00000004 ^ uVar2) - uVar2 & 0xf ^ uVar2;
  if (iVar1 == 0 && uVar4 == uVar2) {
    uVar2 = in_stack_0000000c & 0x7f;
    if (in_stack_0000000c != uVar2) {
      fastcopy_I();
    }
    if (uVar2 != 0) {
      puVar3 = (undefined1 *)((int)in_stack_00000008 + (in_stack_0000000c - uVar2));
      puVar5 = (undefined1 *)((int)in_stack_00000004 + (in_stack_0000000c - uVar2));
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
    }
  }
  else if (iVar1 == uVar4 - uVar2) {
    for (iVar1 = 0x10 - iVar1; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)in_stack_00000004 = *(undefined1 *)in_stack_00000008;
      in_stack_00000008 = (undefined4 *)((int)in_stack_00000008 + 1);
      in_stack_00000004 = (undefined4 *)((int)in_stack_00000004 + 1);
    }
    __VEC_memcpy();
  }
  else {
    for (uVar2 = in_stack_0000000c >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *in_stack_00000004 = *in_stack_00000008;
      in_stack_00000008 = in_stack_00000008 + 1;
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    for (uVar2 = in_stack_0000000c & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)in_stack_00000004 = *(undefined1 *)in_stack_00000008;
      in_stack_00000008 = (undefined4 *)((int)in_stack_00000008 + 1);
      in_stack_00000004 = (undefined4 *)((int)in_stack_00000004 + 1);
    }
  }
  return;
}
}

// =================================================
// Function: __VEC_memzero
// =================================================
void __cdecl __VEC_memzero(void)
{
{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *in_stack_00000004;
  uint in_stack_0000000c;
  
  uVar1 = (int)in_stack_00000004 >> 0x1f;
  iVar2 = (((uint)in_stack_00000004 ^ uVar1) - uVar1 & 0xf ^ uVar1) - uVar1;
  if (iVar2 == 0) {
    uVar1 = in_stack_0000000c & 0x7f;
    if (in_stack_0000000c != uVar1) {
      fastzero_I();
    }
    if (uVar1 != 0) {
      puVar3 = in_stack_00000004 + (in_stack_0000000c - uVar1);
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
    }
  }
  else {
    for (iVar2 = 0x10 - iVar2; iVar2 != 0; iVar2 = iVar2 + -1) {
      *in_stack_00000004 = 0;
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    __VEC_memzero();
  }
  return;
}
}

// =================================================
// Function: ___addlocaleref
// =================================================
void __cdecl ___addlocaleref(void)
{
{
  LONG *pLVar1;
  int iVar2;
  LONG *in_stack_00000004;
  
  InterlockedIncrement(in_stack_00000004);
  if ((LONG *)in_stack_00000004[0x2c] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)in_stack_00000004[0x2c]);
  }
  if ((LONG *)in_stack_00000004[0x2e] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)in_stack_00000004[0x2e]);
  }
  if ((LONG *)in_stack_00000004[0x2d] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)in_stack_00000004[0x2d]);
  }
  if ((LONG *)in_stack_00000004[0x30] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)in_stack_00000004[0x30]);
  }
  pLVar1 = in_stack_00000004 + 0x14;
  iVar2 = 6;
  do {
    if (((undefined *)pLVar1[-2] != &DAT_00ccaa68) && ((LONG *)*pLVar1 != (LONG *)0x0)) {
      InterlockedIncrement((LONG *)*pLVar1);
    }
    if ((pLVar1[-1] != 0) && ((LONG *)pLVar1[1] != (LONG *)0x0)) {
      InterlockedIncrement((LONG *)pLVar1[1]);
    }
    pLVar1 = pLVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  InterlockedIncrement((LONG *)(in_stack_00000004[0x35] + 0xb4));
  return;
}
}

// =================================================
// Function: ___ansicp
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl ___ansicp(void)
{
{
  int iVar1;
  LCID in_stack_00000004;
  CHAR local_10 [6];
  undefined1 local_a;
  uint local_8;
  
  local_8 = DAT_00cca150 ^ (uint)&stack0xfffffffc;
  local_a = 0;
  iVar1 = GetLocaleInfoA(in_stack_00000004,0x1004,local_10,6);
  if (iVar1 != 0) {
    _atol(local_10);
  }
  return;
}
}

// =================================================
// Function: ___ascii_stricmp
// =================================================
int __cdecl ___ascii_stricmp(char *param_1,char *param_2)
{
{
  uint uVar1;
  uint uVar2;
  
  do {
    uVar1 = (uint)(byte)*param_1;
    param_1 = param_1 + 1;
    if (uVar1 - 0x41 < 0x1a) {
      uVar1 = uVar1 + 0x20;
    }
    uVar2 = (uint)(byte)*param_2;
    param_2 = param_2 + 1;
    if (uVar2 - 0x41 < 0x1a) {
      uVar2 = uVar2 + 0x20;
    }
  } while ((uVar1 != 0) && (uVar1 == uVar2));
  return uVar1 - uVar2;
}
}

// =================================================
// Function: ___ascii_strnicmp
// =================================================
int __cdecl ___ascii_strnicmp(char *param_1,char *param_2,uint param_3)
{
{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = 0;
  if (param_3 != 0) {
    do {
      bVar2 = *param_1;
      cVar1 = *param_2;
      uVar3 = CONCAT11(bVar2,cVar1);
      if (bVar2 == 0) break;
      uVar3 = CONCAT11(bVar2,cVar1);
      uVar4 = (uint)uVar3;
      if (cVar1 == '\0') break;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar4 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
      }
      uVar3 = (ushort)uVar4;
      bVar2 = (byte)uVar4;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar3 = (ushort)CONCAT31((int3)(uVar4 >> 8),bVar2 + 0x20);
      }
      bVar2 = (byte)(uVar3 >> 8);
      bVar6 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) goto LAB_004155d1;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
    iVar5 = 0;
    bVar2 = (byte)(uVar3 >> 8);
    bVar6 = bVar2 < (byte)uVar3;
    if (bVar2 != (byte)uVar3) {
LAB_004155d1:
      iVar5 = -1;
      if (!bVar6) {
        iVar5 = 1;
      }
    }
  }
  return iVar5;
}
}

// =================================================
// Function: ___convertcp
// =================================================
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl ___convertcp(void)
{
{
  uint uVar1;
  uint cbMultiByte;
  bool bVar2;
  BOOL BVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  LPSTR lpMultiByteStr;
  bool bVar7;
  UINT in_stack_00000004;
  UINT in_stack_00000008;
  char *in_stack_0000000c;
  uint *in_stack_00000010;
  LPSTR in_stack_00000014;
  int in_stack_00000018;
  LPCWSTR local_20;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_00cca150 ^ (uint)&stack0xfffffffc;
  cbMultiByte = *in_stack_00000010;
  bVar2 = false;
  if (in_stack_00000004 == in_stack_00000008) {
    return;
  }
  BVar3 = GetCPInfo(in_stack_00000004,&local_1c);
  if ((((BVar3 == 0) || (local_1c.MaxCharSize != 1)) ||
      (BVar3 = GetCPInfo(in_stack_00000008,&local_1c), BVar3 == 0)) || (local_1c.MaxCharSize != 1))
  {
    uVar4 = MultiByteToWideChar(in_stack_00000004,1,in_stack_0000000c,cbMultiByte,(LPWSTR)0x0,0);
    bVar7 = false;
    if (uVar4 == 0) {
      return;
    }
  }
  else {
    bVar2 = true;
    uVar4 = cbMultiByte;
    if (cbMultiByte == 0xffffffff) {
      uVar4 = _strlen(in_stack_0000000c);
      uVar4 = uVar4 + 1;
    }
    bVar7 = uVar4 == 0;
  }
  if ((bVar7 || (int)uVar4 < 0) || (0x7ffffff0 < uVar4)) {
    local_20 = (LPCWSTR)0x0;
  }
  else {
    uVar1 = uVar4 * 2 + 8;
    if (uVar1 < 0x401) {
      puVar5 = (undefined4 *)&stack0xffffffbc;
      local_20 = (LPCWSTR)&stack0xffffffbc;
      if (&stack0x00000000 == &DAT_00000044) goto LAB_00413803;
    }
    else {
      puVar5 = _malloc(uVar1);
      local_20 = (LPCWSTR)0x0;
      if (puVar5 == (undefined4 *)0x0) goto LAB_00413803;
      *puVar5 = 0xdddd;
    }
    local_20 = (LPCWSTR)(puVar5 + 2);
  }
LAB_00413803:
  if (local_20 != (LPCWSTR)0x0) {
    _memset(local_20,0,uVar4 * 2);
    iVar6 = MultiByteToWideChar(in_stack_00000004,1,in_stack_0000000c,cbMultiByte,local_20,uVar4);
    if (iVar6 != 0) {
      if (in_stack_00000014 == (LPSTR)0x0) {
        if (((bVar2) ||
            (uVar4 = WideCharToMultiByte(in_stack_00000008,0,local_20,uVar4,(LPSTR)0x0,0,(LPCSTR)0x0
                                         ,(LPBOOL)0x0), uVar4 != 0)) &&
           (lpMultiByteStr = __calloc_crt(1,uVar4), lpMultiByteStr != (LPSTR)0x0)) {
          uVar4 = WideCharToMultiByte(in_stack_00000008,0,local_20,uVar4,lpMultiByteStr,uVar4,
                                      (LPCSTR)0x0,(LPBOOL)0x0);
          if (uVar4 == 0) {
            _free(lpMultiByteStr);
          }
          else if (cbMultiByte != 0xffffffff) {
            *in_stack_00000010 = uVar4;
          }
        }
      }
      else {
        WideCharToMultiByte(in_stack_00000008,0,local_20,uVar4,in_stack_00000014,in_stack_00000018,
                            (LPCSTR)0x0,(LPBOOL)0x0);
      }
    }
    __freea(local_20);
  }
  return;
}
}

// =================================================
// Function: ___crtCorExitProcess
// =================================================
void __cdecl ___crtCorExitProcess(int param_1)
{
{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("mscoree.dll");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"CorExitProcess");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(param_1);
    }
  }
  return;
}
}

// =================================================
// Function: ___crtExitProcess
// =================================================
void __cdecl ___crtExitProcess(int param_1)
{
{
  ___crtCorExitProcess(param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}
}

// =================================================
// Function: ___crtGetStringTypeA
// =================================================
int __cdecl
___crtGetStringTypeA
          (localeinfo_struct *param_1,ulong param_2,char *param_3,int param_4,ushort *param_5,
          int param_6,int param_7)
{
{
  int iVar1;
  int in_stack_00000020;
  localeinfo_struct *in_stack_ffffffec;
  int in_stack_fffffff0;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate(&stack0xffffffec,(_LocaleUpdate *)param_1,in_stack_ffffffec);
  iVar1 = __crtGetStringTypeA_stat
                    ((localeinfo_struct *)param_2,(ulong)param_3,(char *)param_4,(int)param_5,
                     (ushort *)param_6,param_7,in_stack_00000020,in_stack_fffffff0);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar1;
}
}

// =================================================
// Function: ___crtInitCritSecAndSpinCount
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl ___crtInitCritSecAndSpinCount(void)
{
{
  FARPROC extraout_EAX;
  int extraout_EAX_00;
  HMODULE hModule;
  code *pcVar1;
  undefined4 extraout_EAX_01;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  
  __decode_pointer();
  pcVar1 = extraout_EAX;
  if (extraout_EAX == (FARPROC)0x0) {
    __get_osplatform();
    if (extraout_EAX_00 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    hModule = GetModuleHandleA("kernel32.dll");
    if ((hModule == (HMODULE)0x0) ||
       (pcVar1 = GetProcAddress(hModule,"InitializeCriticalSectionAndSpinCount"),
       pcVar1 == (FARPROC)0x0)) {
      pcVar1 = ___crtInitCritSecNoSpinCount_8;
    }
    __encode_pointer();
    DAT_00d54148 = extraout_EAX_01;
  }
  (*pcVar1)(in_stack_00000004,in_stack_00000008);
  return;
}
}

// =================================================
// Function: ___crtLCMapStringA
// =================================================
int __cdecl
___crtLCMapStringA(localeinfo_struct *param_1,wchar_t *param_2,ulong param_3,char *param_4,
                  int param_5,char *param_6,int param_7,int param_8,int param_9)
{
{
  int iVar1;
  localeinfo_struct *in_stack_ffffffec;
  int in_stack_fffffff0;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate(&stack0xffffffec,(_LocaleUpdate *)param_1,in_stack_ffffffec);
  iVar1 = __crtLCMapStringA_stat
                    ((localeinfo_struct *)param_2,param_3,(ulong)param_4,(char *)param_5,
                     (int)param_6,(char *)param_7,param_8,param_9,in_stack_fffffff0);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar1;
}
}

// =================================================
// Function: ___crtMessageBoxA
// =================================================
int __cdecl ___crtMessageBoxA(char *param_1,char *param_2,uint param_3)
{
{
  int extraout_EAX;
  HMODULE hModule;
  FARPROC pFVar1;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int extraout_EAX_05;
  code *extraout_EAX_06;
  code *extraout_EAX_07;
  int iVar2;
  int extraout_EAX_08;
  code *extraout_EAX_09;
  code *extraout_EAX_10;
  code *extraout_EAX_11;
  undefined1 local_24 [8];
  byte local_1c;
  undefined1 local_18 [4];
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  __encoded_null();
  local_8 = 0;
  local_10 = 0;
  local_14 = 0;
  local_c = extraout_EAX;
  if (DAT_00d54120 == 0) {
    hModule = LoadLibraryA("USER32.DLL");
    if (hModule == (HMODULE)0x0) {
      return 0;
    }
    pFVar1 = GetProcAddress(hModule,"MessageBoxA");
    if (pFVar1 == (FARPROC)0x0) {
      return 0;
    }
    __encode_pointer();
    DAT_00d54120 = extraout_EAX_00;
    GetProcAddress(hModule,"GetActiveWindow");
    __encode_pointer();
    DAT_00d54124 = extraout_EAX_01;
    GetProcAddress(hModule,"GetLastActivePopup");
    __encode_pointer();
    DAT_00d54128 = extraout_EAX_02;
    __get_osplatform();
    if (extraout_EAX_03 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    if (local_10 == 2) {
      GetProcAddress(hModule,"GetUserObjectInformationA");
      __encode_pointer();
      DAT_00d54130 = extraout_EAX_04;
      if (extraout_EAX_04 != 0) {
        GetProcAddress(hModule,"GetProcessWindowStation");
        __encode_pointer();
        DAT_00d5412c = extraout_EAX_05;
      }
    }
  }
  if ((DAT_00d5412c != local_c) && (DAT_00d54130 != local_c)) {
    __decode_pointer();
    __decode_pointer();
    if (((extraout_EAX_06 != (code *)0x0) && (extraout_EAX_07 != (code *)0x0)) &&
       (((iVar2 = (*extraout_EAX_06)(), iVar2 == 0 ||
         (iVar2 = (*extraout_EAX_07)(iVar2,1,local_24,0xc,local_18), iVar2 == 0)) ||
        ((local_1c & 1) == 0)))) {
      __get_winmajor();
      if (extraout_EAX_08 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      if (local_14 < 4) {
        param_3 = param_3 | 0x40000;
      }
      else {
        param_3 = param_3 | 0x200000;
      }
      goto LAB_0040b793;
    }
  }
  if ((((DAT_00d54124 != local_c) && (__decode_pointer(), extraout_EAX_09 != (code *)0x0)) &&
      (local_8 = (*extraout_EAX_09)(), local_8 != 0)) &&
     ((DAT_00d54128 != local_c && (__decode_pointer(), extraout_EAX_10 != (code *)0x0)))) {
    local_8 = (*extraout_EAX_10)(local_8);
  }
LAB_0040b793:
  __decode_pointer();
  if (extraout_EAX_11 == (code *)0x0) {
    return 0;
  }
  iVar2 = (*extraout_EAX_11)(local_8,param_1,param_2,param_3);
  return iVar2;
}
}

// =================================================
// Function: ___free_lc_time
// =================================================
void __cdecl ___free_lc_time(void)
{
{
  undefined4 *in_stack_00000004;
  
  if (in_stack_00000004 != (undefined4 *)0x0) {
    _free((void *)in_stack_00000004[1]);
    _free((void *)in_stack_00000004[2]);
    _free((void *)in_stack_00000004[3]);
    _free((void *)in_stack_00000004[4]);
    _free((void *)in_stack_00000004[5]);
    _free((void *)in_stack_00000004[6]);
    _free((void *)*in_stack_00000004);
    _free((void *)in_stack_00000004[8]);
    _free((void *)in_stack_00000004[9]);
    _free((void *)in_stack_00000004[10]);
    _free((void *)in_stack_00000004[0xb]);
    _free((void *)in_stack_00000004[0xc]);
    _free((void *)in_stack_00000004[0xd]);
    _free((void *)in_stack_00000004[7]);
    _free((void *)in_stack_00000004[0xe]);
    _free((void *)in_stack_00000004[0xf]);
    _free((void *)in_stack_00000004[0x10]);
    _free((void *)in_stack_00000004[0x11]);
    _free((void *)in_stack_00000004[0x12]);
    _free((void *)in_stack_00000004[0x13]);
    _free((void *)in_stack_00000004[0x14]);
    _free((void *)in_stack_00000004[0x15]);
    _free((void *)in_stack_00000004[0x16]);
    _free((void *)in_stack_00000004[0x17]);
    _free((void *)in_stack_00000004[0x18]);
    _free((void *)in_stack_00000004[0x19]);
    _free((void *)in_stack_00000004[0x1a]);
    _free((void *)in_stack_00000004[0x1b]);
    _free((void *)in_stack_00000004[0x1c]);
    _free((void *)in_stack_00000004[0x1d]);
    _free((void *)in_stack_00000004[0x1e]);
    _free((void *)in_stack_00000004[0x1f]);
    _free((void *)in_stack_00000004[0x20]);
    _free((void *)in_stack_00000004[0x21]);
    _free((void *)in_stack_00000004[0x22]);
    _free((void *)in_stack_00000004[0x23]);
    _free((void *)in_stack_00000004[0x24]);
    _free((void *)in_stack_00000004[0x25]);
    _free((void *)in_stack_00000004[0x26]);
    _free((void *)in_stack_00000004[0x27]);
    _free((void *)in_stack_00000004[0x28]);
    _free((void *)in_stack_00000004[0x29]);
    _free((void *)in_stack_00000004[0x2a]);
  }
  return;
}
}

// =================================================
// Function: ___free_lconv_mon
// =================================================
void __cdecl ___free_lconv_mon(void)
{
{
  int in_stack_00000004;
  
  if (in_stack_00000004 != 0) {
    if (*(undefined **)(in_stack_00000004 + 0xc) != PTR_DAT_00ccad64) {
      _free(*(undefined **)(in_stack_00000004 + 0xc));
    }
    if (*(undefined **)(in_stack_00000004 + 0x10) != PTR_DAT_00ccad68) {
      _free(*(undefined **)(in_stack_00000004 + 0x10));
    }
    if (*(undefined **)(in_stack_00000004 + 0x14) != PTR_DAT_00ccad6c) {
      _free(*(undefined **)(in_stack_00000004 + 0x14));
    }
    if (*(undefined **)(in_stack_00000004 + 0x18) != PTR_DAT_00ccad70) {
      _free(*(undefined **)(in_stack_00000004 + 0x18));
    }
    if (*(undefined **)(in_stack_00000004 + 0x1c) != PTR_DAT_00ccad74) {
      _free(*(undefined **)(in_stack_00000004 + 0x1c));
    }
    if (*(undefined **)(in_stack_00000004 + 0x20) != PTR_DAT_00ccad78) {
      _free(*(undefined **)(in_stack_00000004 + 0x20));
    }
    if (*(undefined **)(in_stack_00000004 + 0x24) != PTR_DAT_00ccad7c) {
      _free(*(undefined **)(in_stack_00000004 + 0x24));
    }
  }
  return;
}
}

// =================================================
// Function: ___free_lconv_num
// =================================================
void __cdecl ___free_lconv_num(void)
{
{
  undefined4 *in_stack_00000004;
  
  if (in_stack_00000004 != (undefined4 *)0x0) {
    if ((undefined *)*in_stack_00000004 != PTR_DAT_00ccad58) {
      _free((undefined *)*in_stack_00000004);
    }
    if ((undefined *)in_stack_00000004[1] != PTR_DAT_00ccad5c) {
      _free((undefined *)in_stack_00000004[1]);
    }
    if ((undefined *)in_stack_00000004[2] != PTR_DAT_00ccad60) {
      _free((undefined *)in_stack_00000004[2]);
    }
  }
  return;
}
}

// =================================================
// Function: ___freetlocinfo
// =================================================
void __cdecl ___freetlocinfo(void)
{
{
  int *piVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined4 *puVar4;
  void *in_stack_00000004;
  
  if ((((*(undefined ***)((int)in_stack_00000004 + 0xbc) != (undefined **)0x0) &&
       (*(undefined ***)((int)in_stack_00000004 + 0xbc) != &PTR_DAT_00ccad58)) &&
      (*(int **)((int)in_stack_00000004 + 0xb0) != (int *)0x0)) &&
     (**(int **)((int)in_stack_00000004 + 0xb0) == 0)) {
    piVar1 = *(int **)((int)in_stack_00000004 + 0xb8);
    if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
      _free(piVar1);
      ___free_lconv_mon();
    }
    piVar1 = *(int **)((int)in_stack_00000004 + 0xb4);
    if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
      _free(piVar1);
      ___free_lconv_num();
    }
    _free(*(void **)((int)in_stack_00000004 + 0xb0));
    _free(*(void **)((int)in_stack_00000004 + 0xbc));
  }
  if ((*(int **)((int)in_stack_00000004 + 0xc0) != (int *)0x0) &&
     (**(int **)((int)in_stack_00000004 + 0xc0) == 0)) {
    _free((void *)(*(int *)((int)in_stack_00000004 + 0xc4) + -0xfe));
    _free((void *)(*(int *)((int)in_stack_00000004 + 0xcc) + -0x80));
    _free((void *)(*(int *)((int)in_stack_00000004 + 0xd0) + -0x80));
    _free(*(void **)((int)in_stack_00000004 + 0xc0));
  }
  ppuVar2 = *(undefined ***)((int)in_stack_00000004 + 0xd4);
  if ((ppuVar2 != &PTR_DAT_00ccac98) && (ppuVar2[0x2d] == (undefined *)0x0)) {
    ___free_lc_time();
    _free(*(void **)((int)in_stack_00000004 + 0xd4));
  }
  puVar4 = (undefined4 *)((int)in_stack_00000004 + 0x50);
  iVar3 = 6;
  do {
    if ((((undefined *)puVar4[-2] != &DAT_00ccaa68) &&
        (piVar1 = (int *)*puVar4, piVar1 != (int *)0x0)) && (*piVar1 == 0)) {
      _free(piVar1);
    }
    if (((puVar4[-1] != 0) && (piVar1 = (int *)puVar4[1], piVar1 != (int *)0x0)) && (*piVar1 == 0))
    {
      _free(piVar1);
    }
    puVar4 = puVar4 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _free(in_stack_00000004);
  return;
}
}

// =================================================
// Function: ___removelocaleref
// =================================================
void __cdecl ___removelocaleref(void)
{
{
  LONG *pLVar1;
  int iVar2;
  LONG *in_stack_00000004;
  
  if (in_stack_00000004 != (LONG *)0x0) {
    InterlockedDecrement(in_stack_00000004);
    if ((LONG *)in_stack_00000004[0x2c] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)in_stack_00000004[0x2c]);
    }
    if ((LONG *)in_stack_00000004[0x2e] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)in_stack_00000004[0x2e]);
    }
    if ((LONG *)in_stack_00000004[0x2d] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)in_stack_00000004[0x2d]);
    }
    if ((LONG *)in_stack_00000004[0x30] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)in_stack_00000004[0x30]);
    }
    pLVar1 = in_stack_00000004 + 0x14;
    iVar2 = 6;
    do {
      if (((undefined *)pLVar1[-2] != &DAT_00ccaa68) && ((LONG *)*pLVar1 != (LONG *)0x0)) {
        InterlockedDecrement((LONG *)*pLVar1);
      }
      if ((pLVar1[-1] != 0) && ((LONG *)pLVar1[1] != (LONG *)0x0)) {
        InterlockedDecrement((LONG *)pLVar1[1]);
      }
      pLVar1 = pLVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    InterlockedDecrement((LONG *)(in_stack_00000004[0x35] + 0xb4));
  }
  return;
}
}

// =================================================
// Function: ___sbh_alloc_block
// =================================================
void __cdecl ___sbh_alloc_block(void)
{
{
  int *piVar1;
  char *pcVar2;
  int *piVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  uint *puVar7;
  uint *extraout_EAX;
  undefined4 extraout_EAX_00;
  byte bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  uint *in_stack_00000004;
  uint local_c;
  int local_8;
  
  puVar7 = (uint *)(DAT_00d7aea4 * 0x14 + (int)lpMem_00d7aea8);
  uVar9 = (int)in_stack_00000004 + 0x17U & 0xfffffff0;
  iVar10 = ((int)((int)in_stack_00000004 + 0x17U) >> 4) + -1;
  bVar8 = (byte)iVar10;
  in_stack_00000004 = DAT_00d7aeb0;
  if (iVar10 < 0x20) {
    uVar15 = 0xffffffff >> (bVar8 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    uVar15 = 0;
    local_c = 0xffffffff >> (bVar8 - 0x20 & 0x1f);
  }
  for (; (in_stack_00000004 < puVar7 &&
         ((in_stack_00000004[1] & local_c) == 0 && (*in_stack_00000004 & uVar15) == 0));
      in_stack_00000004 = in_stack_00000004 + 5) {
  }
  puVar13 = lpMem_00d7aea8;
  if (in_stack_00000004 == puVar7) {
    for (; (puVar13 < DAT_00d7aeb0 && ((puVar13[1] & local_c) == 0 && (*puVar13 & uVar15) == 0));
        puVar13 = puVar13 + 5) {
    }
    in_stack_00000004 = puVar13;
    if (puVar13 == DAT_00d7aeb0) {
      for (; (puVar13 < puVar7 && (puVar13[2] == 0)); puVar13 = puVar13 + 5) {
      }
      puVar14 = lpMem_00d7aea8;
      in_stack_00000004 = puVar13;
      if (puVar13 == puVar7) {
        for (; (puVar14 < DAT_00d7aeb0 && (puVar14[2] == 0)); puVar14 = puVar14 + 5) {
        }
        in_stack_00000004 = puVar14;
        if ((puVar14 == DAT_00d7aeb0) &&
           (___sbh_alloc_new_region(), in_stack_00000004 = extraout_EAX, extraout_EAX == (uint *)0x0
           )) {
          return;
        }
      }
      ___sbh_alloc_new_group();
      *(undefined4 *)in_stack_00000004[4] = extraout_EAX_00;
      if (*(int *)in_stack_00000004[4] == -1) {
        return;
      }
    }
  }
  piVar5 = (int *)in_stack_00000004[4];
  local_8 = *piVar5;
  if ((local_8 == -1) ||
     ((piVar5[local_8 + 0x31] & local_c) == 0 && (piVar5[local_8 + 0x11] & uVar15) == 0)) {
    local_8 = 0;
    puVar7 = (uint *)(piVar5 + 0x11);
    uVar12 = piVar5[0x31];
    while ((uVar12 & local_c) == 0 && (*puVar7 & uVar15) == 0) {
      local_8 = local_8 + 1;
      puVar13 = puVar7 + 0x21;
      puVar7 = puVar7 + 1;
      uVar12 = *puVar13;
    }
  }
  piVar3 = piVar5 + local_8 * 0x81 + 0x51;
  iVar10 = 0;
  uVar15 = piVar5[local_8 + 0x11] & uVar15;
  if (uVar15 == 0) {
    uVar15 = piVar5[local_8 + 0x31] & local_c;
    iVar10 = 0x20;
  }
  for (; -1 < (int)uVar15; uVar15 = uVar15 * 2) {
    iVar10 = iVar10 + 1;
  }
  piVar6 = (int *)piVar3[iVar10 * 2 + 1];
  iVar11 = *piVar6 - uVar9;
  iVar16 = (iVar11 >> 4) + -1;
  if (0x3f < iVar16) {
    iVar16 = 0x3f;
  }
  DAT_00d7aeb0 = in_stack_00000004;
  if (iVar16 != iVar10) {
    if (piVar6[1] == piVar6[2]) {
      if (iVar10 < 0x20) {
        pcVar2 = (char *)((int)piVar5 + iVar10 + 4);
        uVar15 = ~(0x80000000U >> ((byte)iVar10 & 0x1f));
        piVar5[local_8 + 0x11] = uVar15 & piVar5[local_8 + 0x11];
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          *in_stack_00000004 = *in_stack_00000004 & uVar15;
        }
      }
      else {
        pcVar2 = (char *)((int)piVar5 + iVar10 + 4);
        uVar15 = ~(0x80000000U >> ((byte)iVar10 - 0x20 & 0x1f));
        piVar5[local_8 + 0x31] = piVar5[local_8 + 0x31] & uVar15;
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          in_stack_00000004[1] = in_stack_00000004[1] & uVar15;
        }
      }
    }
    *(int *)(piVar6[2] + 4) = piVar6[1];
    *(int *)(piVar6[1] + 8) = piVar6[2];
    if (iVar11 == 0) goto LAB_0040c6e9;
    piVar1 = piVar3 + iVar16 * 2;
    iVar10 = piVar1[1];
    piVar6[2] = (int)piVar1;
    piVar6[1] = iVar10;
    piVar1[1] = (int)piVar6;
    *(int **)(piVar6[1] + 8) = piVar6;
    if (piVar6[1] == piVar6[2]) {
      cVar4 = *(char *)(iVar16 + 4 + (int)piVar5);
      *(char *)(iVar16 + 4 + (int)piVar5) = cVar4 + '\x01';
      bVar8 = (byte)iVar16;
      if (iVar16 < 0x20) {
        if (cVar4 == '\0') {
          *in_stack_00000004 = *in_stack_00000004 | 0x80000000U >> (bVar8 & 0x1f);
        }
        piVar5[local_8 + 0x11] = piVar5[local_8 + 0x11] | 0x80000000U >> (bVar8 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          in_stack_00000004[1] = in_stack_00000004[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        piVar5[local_8 + 0x31] = piVar5[local_8 + 0x31] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar11 != 0) {
    *piVar6 = iVar11;
    *(int *)(iVar11 + -4 + (int)piVar6) = iVar11;
  }
LAB_0040c6e9:
  *(int *)((int)piVar6 + iVar11) = uVar9 + 1;
  *(uint *)((int)piVar6 + iVar11 + (uVar9 - 4)) = uVar9 + 1;
  iVar10 = *piVar3;
  *piVar3 = iVar10 + 1;
  if (((iVar10 == 0) && (in_stack_00000004 == DAT_00d5413c)) && (local_8 == DAT_00d7aeb8)) {
    DAT_00d5413c = (uint *)0x0;
  }
  *piVar5 = local_8;
  return;
}
}

// =================================================
// Function: ___sbh_alloc_new_group
// =================================================
void __cdecl ___sbh_alloc_new_group(void)
{
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  LPVOID pvVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  LPVOID lpAddress;
  int in_stack_00000004;
  
  iVar2 = *(int *)(in_stack_00000004 + 0x10);
  iVar8 = 0;
  for (iVar3 = *(int *)(in_stack_00000004 + 8); -1 < iVar3; iVar3 = iVar3 * 2) {
    iVar8 = iVar8 + 1;
  }
  iVar3 = iVar8 * 0x204 + 0x144 + iVar2;
  iVar7 = 0x3f;
  iVar4 = iVar3;
  do {
    *(int *)(iVar4 + 8) = iVar4;
    *(int *)(iVar4 + 4) = iVar4;
    iVar4 = iVar4 + 8;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  lpAddress = (LPVOID)(iVar8 * 0x8000 + *(int *)(in_stack_00000004 + 0xc));
  pvVar5 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar5 != (LPVOID)0x0) {
    if (lpAddress <= (LPVOID)((int)lpAddress + 0x7000U)) {
      piVar6 = (int *)((int)lpAddress + 0x10);
      iVar7 = ((uint)((int)((int)lpAddress + 0x7000U) - (int)lpAddress) >> 0xc) + 1;
      do {
        piVar6[-2] = -1;
        piVar6[0x3fb] = -1;
        *piVar6 = (int)(piVar6 + 0x3ff);
        piVar6[-1] = 0xff0;
        piVar6[1] = (int)(piVar6 + -0x401);
        piVar6[0x3fa] = 0xff0;
        piVar6 = piVar6 + 0x400;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    *(int *)(iVar3 + 0x1fc) = (int)lpAddress + 0xc;
    *(int *)((int)lpAddress + 0x14) = iVar3 + 0x1f8;
    *(int *)(iVar3 + 0x200) = (int)lpAddress + 0x700c;
    *(int *)((int)lpAddress + 0x7010) = iVar3 + 0x1f8;
    *(undefined4 *)(iVar2 + 0x44 + iVar8 * 4) = 0;
    *(undefined4 *)(iVar2 + 0xc4 + iVar8 * 4) = 1;
    cVar1 = *(char *)(iVar2 + 0x43);
    *(char *)(iVar2 + 0x43) = cVar1 + '\x01';
    if (cVar1 == '\0') {
      *(uint *)(in_stack_00000004 + 4) = *(uint *)(in_stack_00000004 + 4) | 1;
    }
    *(uint *)(in_stack_00000004 + 8) =
         *(uint *)(in_stack_00000004 + 8) & ~(0x80000000U >> ((byte)iVar8 & 0x1f));
  }
  return;
}
}

// =================================================
// Function: ___sbh_alloc_new_region
// =================================================
void __cdecl ___sbh_alloc_new_region(void)
{
{
  LPVOID pvVar1;
  undefined4 *puVar2;
  
  if (DAT_00d7aea4 == DAT_00d7aeb4) {
    pvVar1 = HeapReAlloc(hHeap_00d53f34,0,lpMem_00d7aea8,(DAT_00d7aeb4 + 0x10) * 0x14);
    if (pvVar1 == (LPVOID)0x0) {
      return;
    }
    DAT_00d7aeb4 = DAT_00d7aeb4 + 0x10;
    lpMem_00d7aea8 = pvVar1;
  }
  puVar2 = (undefined4 *)(DAT_00d7aea4 * 0x14 + (int)lpMem_00d7aea8);
  pvVar1 = HeapAlloc(hHeap_00d53f34,8,0x41c4);
  puVar2[4] = pvVar1;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar1 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar2[3] = pvVar1;
    if (pvVar1 == (LPVOID)0x0) {
      HeapFree(hHeap_00d53f34,0,(LPVOID)puVar2[4]);
    }
    else {
      puVar2[2] = 0xffffffff;
      *puVar2 = 0;
      puVar2[1] = 0;
      DAT_00d7aea4 = DAT_00d7aea4 + 1;
      *(undefined4 *)puVar2[4] = 0xffffffff;
    }
  }
  return;
}
}

// =================================================
// Function: ___sbh_free_block
// =================================================
void __cdecl ___sbh_free_block(void)
{
{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  int *piVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint *in_stack_00000004;
  int in_stack_00000008;
  uint local_8;
  
  uVar6 = in_stack_00000004[4];
  puVar12 = (uint *)(in_stack_00000008 + -4);
  uVar14 = in_stack_00000008 - in_stack_00000004[3] >> 0xf;
  piVar4 = (int *)(uVar14 * 0x204 + 0x144 + uVar6);
  local_8 = *puVar12 - 1;
  if ((local_8 & 1) == 0) {
    puVar10 = (uint *)(local_8 + (int)puVar12);
    uVar13 = *puVar10;
    uVar7 = *(uint *)(in_stack_00000008 + -8);
    if ((uVar13 & 1) == 0) {
      uVar9 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar9) {
        uVar9 = 0x3f;
      }
      if (puVar10[1] == puVar10[2]) {
        if (uVar9 < 0x20) {
          pcVar2 = (char *)(uVar9 + 4 + uVar6);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 & 0x1f));
          puVar11 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
          *puVar11 = *puVar11 & uVar9;
          *pcVar2 = *pcVar2 + -1;
          if (*pcVar2 == '\0') {
            *in_stack_00000004 = *in_stack_00000004 & uVar9;
          }
        }
        else {
          pcVar2 = (char *)(uVar9 + 4 + uVar6);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 - 0x20 & 0x1f));
          puVar11 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
          *puVar11 = *puVar11 & uVar9;
          *pcVar2 = *pcVar2 + -1;
          if (*pcVar2 == '\0') {
            in_stack_00000004[1] = in_stack_00000004[1] & uVar9;
          }
        }
      }
      local_8 = local_8 + uVar13;
      *(uint *)(puVar10[2] + 4) = puVar10[1];
      *(uint *)(puVar10[1] + 8) = puVar10[2];
    }
    puVar10 = (uint *)(((int)local_8 >> 4) + -1);
    if (&DAT_0000003f < puVar10) {
      puVar10 = (uint *)&DAT_0000003f;
    }
    puVar11 = in_stack_00000004;
    if ((uVar7 & 1) == 0) {
      puVar12 = (uint *)((int)puVar12 - uVar7);
      puVar11 = (uint *)(((int)uVar7 >> 4) + -1);
      if (&DAT_0000003f < puVar11) {
        puVar11 = (uint *)&DAT_0000003f;
      }
      local_8 = local_8 + uVar7;
      puVar10 = (uint *)(((int)local_8 >> 4) + -1);
      if (&DAT_0000003f < puVar10) {
        puVar10 = (uint *)&DAT_0000003f;
      }
      if (puVar11 != puVar10) {
        if (puVar12[1] == puVar12[2]) {
          if (puVar11 < (uint *)0x20) {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 & 0x1f));
            puVar3 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
            *puVar3 = *puVar3 & uVar13;
            pcVar2 = (char *)((int)puVar11 + uVar6 + 4);
            *pcVar2 = *pcVar2 + -1;
            if (*pcVar2 == '\0') {
              *in_stack_00000004 = *in_stack_00000004 & uVar13;
            }
          }
          else {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 - 0x20 & 0x1f));
            puVar3 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
            *puVar3 = *puVar3 & uVar13;
            pcVar2 = (char *)((int)puVar11 + uVar6 + 4);
            *pcVar2 = *pcVar2 + -1;
            if (*pcVar2 == '\0') {
              in_stack_00000004[1] = in_stack_00000004[1] & uVar13;
            }
          }
        }
        *(uint *)(puVar12[2] + 4) = puVar12[1];
        *(uint *)(puVar12[1] + 8) = puVar12[2];
      }
    }
    if (((uVar7 & 1) != 0) || (puVar11 != puVar10)) {
      piVar1 = piVar4 + (int)puVar10 * 2;
      uVar13 = piVar1[1];
      puVar12[2] = (uint)piVar1;
      puVar12[1] = uVar13;
      piVar1[1] = (int)puVar12;
      *(uint **)(puVar12[1] + 8) = puVar12;
      if (puVar12[1] == puVar12[2]) {
        cVar5 = *(char *)((int)puVar10 + uVar6 + 4);
        *(char *)((int)puVar10 + uVar6 + 4) = cVar5 + '\x01';
        bVar8 = (byte)puVar10;
        if (puVar10 < (uint *)0x20) {
          if (cVar5 == '\0') {
            *in_stack_00000004 = *in_stack_00000004 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar10 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 & 0x1f);
        }
        else {
          if (cVar5 == '\0') {
            in_stack_00000004[1] = in_stack_00000004[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar10 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
      }
    }
    *puVar12 = local_8;
    *(uint *)((local_8 - 4) + (int)puVar12) = local_8;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      if (DAT_00d5413c != (uint *)0x0) {
        VirtualFree((LPVOID)(DAT_00d7aeb8 * 0x8000 + DAT_00d5413c[3]),0x8000,0x4000);
        DAT_00d5413c[2] = DAT_00d5413c[2] | 0x80000000U >> ((byte)DAT_00d7aeb8 & 0x1f);
        *(undefined4 *)(DAT_00d5413c[4] + 0xc4 + DAT_00d7aeb8 * 4) = 0;
        *(char *)(DAT_00d5413c[4] + 0x43) = *(char *)(DAT_00d5413c[4] + 0x43) + -1;
        if (*(char *)(DAT_00d5413c[4] + 0x43) == '\0') {
          DAT_00d5413c[1] = DAT_00d5413c[1] & 0xfffffffe;
        }
        if (DAT_00d5413c[2] == 0xffffffff) {
          VirtualFree((LPVOID)DAT_00d5413c[3],0,0x8000);
          HeapFree(hHeap_00d53f34,0,(LPVOID)DAT_00d5413c[4]);
          _memmove(DAT_00d5413c,DAT_00d5413c + 5,
                   (DAT_00d7aea4 * 0x14 - (int)DAT_00d5413c) + -0x14 + (int)lpMem_00d7aea8);
          DAT_00d7aea4 = DAT_00d7aea4 + -1;
          if (DAT_00d5413c < in_stack_00000004) {
            in_stack_00000004 = in_stack_00000004 + -5;
          }
          DAT_00d7aeb0 = lpMem_00d7aea8;
        }
      }
      DAT_00d5413c = in_stack_00000004;
      DAT_00d7aeb8 = uVar14;
    }
  }
  return;
}
}

// =================================================
// Function: ___sbh_resize_block
// =================================================
void __cdecl ___sbh_resize_block(void)
{
{
  char *pcVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  uint local_c;
  
  uVar7 = in_stack_00000004[4];
  uVar10 = in_stack_00000008 - in_stack_00000004[3] >> 0xf;
  iVar5 = uVar10 * 0x204 + 0x144 + uVar7;
  uVar12 = in_stack_0000000c + 0x17U & 0xfffffff0;
  iVar9 = *(int *)(in_stack_00000008 + -4) + -1;
  puVar8 = (uint *)(*(int *)(in_stack_00000008 + -4) + -5 + in_stack_00000008);
  uVar13 = *puVar8;
  if (iVar9 < (int)uVar12) {
    if (((uVar13 & 1) == 0) && ((int)uVar12 <= (int)(uVar13 + iVar9))) {
      local_c = ((int)uVar13 >> 4) - 1;
      if (0x3f < local_c) {
        local_c = 0x3f;
      }
      if (puVar8[1] == puVar8[2]) {
        if (local_c < 0x20) {
          pcVar1 = (char *)(local_c + 4 + uVar7);
          uVar11 = ~(0x80000000U >> ((byte)local_c & 0x1f));
          puVar2 = (uint *)(uVar7 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *in_stack_00000004 = *in_stack_00000004 & uVar11;
          }
        }
        else {
          pcVar1 = (char *)(local_c + 4 + uVar7);
          uVar11 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar7 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            in_stack_00000004[1] = in_stack_00000004[1] & uVar11;
          }
        }
      }
      *(uint *)(puVar8[2] + 4) = puVar8[1];
      *(uint *)(puVar8[1] + 8) = puVar8[2];
      iVar9 = uVar13 + (iVar9 - uVar12);
      if (0 < iVar9) {
        uVar13 = (iVar9 >> 4) - 1;
        iVar3 = in_stack_00000008 + -4 + uVar12;
        if (0x3f < uVar13) {
          uVar13 = 0x3f;
        }
        iVar5 = iVar5 + uVar13 * 8;
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar5 + 4);
        *(int *)(iVar3 + 8) = iVar5;
        *(int *)(iVar5 + 4) = iVar3;
        *(int *)(*(int *)(iVar3 + 4) + 8) = iVar3;
        if (*(int *)(iVar3 + 4) == *(int *)(iVar3 + 8)) {
          cVar6 = *(char *)(uVar13 + 4 + uVar7);
          *(char *)(uVar13 + 4 + uVar7) = cVar6 + '\x01';
          if (uVar13 < 0x20) {
            if (cVar6 == '\0') {
              *in_stack_00000004 = *in_stack_00000004 | 0x80000000U >> ((byte)uVar13 & 0x1f);
            }
            puVar8 = (uint *)(uVar7 + 0x44 + uVar10 * 4);
          }
          else {
            if (cVar6 == '\0') {
              in_stack_00000004[1] =
                   in_stack_00000004[1] | 0x80000000U >> ((byte)uVar13 - 0x20 & 0x1f);
            }
            puVar8 = (uint *)(uVar7 + 0xc4 + uVar10 * 4);
            uVar13 = uVar13 - 0x20;
          }
          *puVar8 = *puVar8 | 0x80000000U >> ((byte)uVar13 & 0x1f);
        }
        piVar4 = (int *)(in_stack_00000008 + -4 + uVar12);
        *piVar4 = iVar9;
        *(int *)(iVar9 + -4 + (int)piVar4) = iVar9;
      }
      *(uint *)(in_stack_00000008 + -4) = uVar12 + 1;
      *(uint *)(in_stack_00000008 + -8 + uVar12) = uVar12 + 1;
    }
  }
  else if ((int)uVar12 < iVar9) {
    in_stack_0000000c = iVar9 - uVar12;
    *(uint *)(in_stack_00000008 + -4) = uVar12 + 1;
    piVar4 = (int *)(in_stack_00000008 + -4 + uVar12);
    uVar11 = (in_stack_0000000c >> 4) - 1;
    piVar4[-1] = uVar12 + 1;
    if (0x3f < uVar11) {
      uVar11 = 0x3f;
    }
    if ((uVar13 & 1) == 0) {
      uVar12 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      if (puVar8[1] == puVar8[2]) {
        if (uVar12 < 0x20) {
          pcVar1 = (char *)(uVar12 + 4 + uVar7);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 & 0x1f));
          puVar2 = (uint *)(uVar7 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *in_stack_00000004 = *in_stack_00000004 & uVar12;
          }
        }
        else {
          pcVar1 = (char *)(uVar12 + 4 + uVar7);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar7 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            in_stack_00000004[1] = in_stack_00000004[1] & uVar12;
          }
        }
      }
      *(uint *)(puVar8[2] + 4) = puVar8[1];
      *(uint *)(puVar8[1] + 8) = puVar8[2];
      in_stack_0000000c = in_stack_0000000c + uVar13;
      uVar11 = (in_stack_0000000c >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
    }
    iVar5 = iVar5 + uVar11 * 8;
    iVar9 = *(int *)(iVar5 + 4);
    piVar4[2] = iVar5;
    piVar4[1] = iVar9;
    *(int **)(iVar5 + 4) = piVar4;
    *(int **)(piVar4[1] + 8) = piVar4;
    if (piVar4[1] == piVar4[2]) {
      cVar6 = *(char *)(uVar11 + 4 + uVar7);
      *(char *)(uVar11 + 4 + uVar7) = cVar6 + '\x01';
      if (uVar11 < 0x20) {
        if (cVar6 == '\0') {
          *in_stack_00000004 = *in_stack_00000004 | 0x80000000U >> ((byte)uVar11 & 0x1f);
        }
        puVar8 = (uint *)(uVar7 + 0x44 + uVar10 * 4);
      }
      else {
        if (cVar6 == '\0') {
          in_stack_00000004[1] = in_stack_00000004[1] | 0x80000000U >> ((byte)uVar11 - 0x20 & 0x1f);
        }
        puVar8 = (uint *)(uVar7 + 0xc4 + uVar10 * 4);
        uVar11 = uVar11 - 0x20;
      }
      *puVar8 = *puVar8 | 0x80000000U >> ((byte)uVar11 & 0x1f);
    }
    *piVar4 = in_stack_0000000c;
    *(int *)(in_stack_0000000c + -4 + (int)piVar4) = in_stack_0000000c;
  }
  return;
}
}

// =================================================
// Function: ___set_flsgetvalue
// =================================================
void __cdecl ___set_flsgetvalue(void)
{
{
  LPVOID pvVar1;
  LPVOID lpTlsValue;
  
  pvVar1 = TlsGetValue(dwTlsIndex_00cca204);
  if (pvVar1 == (LPVOID)0x0) {
    __decode_pointer();
    TlsSetValue(dwTlsIndex_00cca204,lpTlsValue);
  }
  return;
}
}

// =================================================
// Function: ___updatetlocinfo
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

threadlocaleinfostruct * __cdecl ___updatetlocinfo(void)
{
{
  _tiddata *p_Var1;
  
  p_Var1 = __getptd();
  if (((p_Var1->_ownlocale & DAT_00ccaa64) == 0) ||
     (p_Var1->ptlocinfo == (threadlocaleinfostruct *)0x0)) {
    __lock(0xc);
    __updatetlocinfoEx_nolock();
    FUN_004096a8();
  }
  else {
    p_Var1 = __getptd();
    p_Var1 = (_tiddata *)p_Var1->ptlocinfo;
  }
  if (p_Var1 == (_tiddata *)0x0) {
    __amsg_exit(0x20);
  }
  return (threadlocaleinfostruct *)p_Var1;
}
}

// =================================================
// Function: ___updatetmbcinfo
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

threadmbcinfostruct * __cdecl ___updatetmbcinfo(void)
{
{
  _tiddata *p_Var1;
  LONG LVar2;
  threadmbcinfostruct *lpAddend;
  
  p_Var1 = __getptd();
  if (((p_Var1->_ownlocale & DAT_00ccaa64) == 0) ||
     (p_Var1->ptlocinfo == (threadlocaleinfostruct *)0x0)) {
    __lock(0xd);
    lpAddend = p_Var1->ptmbcinfo;
    if (lpAddend != (threadmbcinfostruct *)lpAddend_00cca968) {
      if (lpAddend != (threadmbcinfostruct *)0x0) {
        LVar2 = InterlockedDecrement(&lpAddend->refcount);
        if ((LVar2 == 0) && (lpAddend != (threadmbcinfostruct *)&DAT_00cca540)) {
          _free(lpAddend);
        }
      }
      p_Var1->ptmbcinfo = (threadmbcinfostruct *)lpAddend_00cca968;
      lpAddend = (threadmbcinfostruct *)lpAddend_00cca968;
      InterlockedIncrement((LONG *)lpAddend_00cca968);
    }
    FUN_00408f76();
  }
  else {
    lpAddend = p_Var1->ptmbcinfo;
  }
  if (lpAddend == (threadmbcinfostruct *)0x0) {
    __amsg_exit(0x20);
  }
  return lpAddend;
}
}

// =================================================
// Function: __allmul
// =================================================
void __cdecl __allmul(void)
{
{
  int in_stack_00000008;
  int in_stack_00000010;
  
  if (in_stack_00000010 == 0 && in_stack_00000008 == 0) {
    return;
  }
  return;
}
}

// =================================================
// Function: __allshl
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c317e) overlaps instruction at (ram,0x009c317d)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __allshl(void)
{
{
  undefined1 *puVar1;
  undefined1 uVar2;
  bool bVar3;
  code *pcVar4;
  undefined4 uVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  char cVar14;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  char *pcVar13;
  undefined1 *extraout_ECX;
  undefined1 *puVar15;
  undefined1 *extraout_ECX_00;
  uint *puVar16;
  int iVar17;
  byte bVar18;
  undefined2 uVar19;
  byte bVar22;
  uint uVar20;
  undefined3 uVar23;
  uint *unaff_EBX;
  undefined2 *puVar24;
  undefined2 *puVar25;
  undefined4 *puVar26;
  uint unaff_EBP;
  undefined4 *puVar27;
  byte *unaff_ESI;
  undefined1 *unaff_EDI;
  int *piVar28;
  uint *puVar29;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined1 in_PF;
  byte in_AF;
  undefined8 uVar30;
  uint uVar21;
  
  uVar30 = func_0x5cdb6073();
  uVar20 = (uint)((ulonglong)uVar30 >> 0x20);
  in_AF = 9 < ((byte)uVar30 & 0xf) | in_AF;
  bVar8 = (byte)uVar30 + in_AF * -6 & 0xf;
  piVar28 = (int *)(unaff_EDI + 1);
  uVar2 = in((short)((ulonglong)uVar30 >> 0x20));
  *unaff_EDI = uVar2;
  bVar18 = 9 < bVar8 | in_AF;
  uVar10 = CONCAT31((int3)((ulonglong)uVar30 >> 8),bVar8 + bVar18 * -6) & 0xffff000f;
  puVar29 = (uint *)CONCAT22((short)(uVar10 >> 0x10),
                             CONCAT11(((char)((ulonglong)uVar30 >> 8) - in_AF) - bVar18,(char)uVar10
                                     ));
  puVar16 = puVar29;
  puVar15 = extraout_ECX;
  if (!(bool)in_PF) {
    bVar18 = 9 < ((byte)unaff_EBX & 0xf) | bVar18;
    bVar6 = (byte)unaff_EBX + bVar18 * -6 & 0xf;
    cVar14 = (char)((uint)unaff_EBX >> 8) - bVar18;
    bVar8 = 9 < bVar6 | bVar18;
    bVar6 = bVar6 + bVar8 * -6 & 0xf;
    *piVar28 = *piVar28 >> 0x1b;
    bVar18 = 9 < bVar6 | bVar8;
    uVar10 = CONCAT31((int3)(((uint)((uint3)(int3)cVar14 >> 8) << 0x10) >> 8),bVar6 + bVar18 * -6) &
             0xffffff0f;
    bVar7 = (byte)uVar10;
    pcVar13 = (char *)CONCAT22((short)(uVar10 >> 0x10),CONCAT11((cVar14 - bVar8) - bVar18,bVar7));
    *pcVar13 = *pcVar13 + bVar7;
    pcVar13[0x12c0056] = pcVar13[0x12c0056] + bVar7;
    *pcVar13 = *pcVar13 + bVar7;
    pbVar9 = (byte *)CONCAT31((int3)((uint)pcVar13 >> 8),bVar7 + 0x30);
    bVar8 = *pbVar9;
    bVar22 = (byte)((ulonglong)uVar30 >> 0x28);
    bVar6 = *pbVar9 + bVar22;
    *pbVar9 = bVar6 + (0xcf < bVar7);
    *(uint *)pbVar9 =
         (*(int *)pbVar9 - (int)unaff_ESI) -
         (uint)(CARRY1(bVar8,bVar22) || CARRY1(bVar6,0xcf < bVar7));
    uVar10 = (uint)pbVar9 & 0x31302b30;
    *(byte *)(uVar20 + 0x6a314a30) =
         *(byte *)(uVar20 + 0x6a314a30) ^ (byte)((uint)extraout_ECX >> 8);
    *(uint *)(unaff_EBP + 0xcd31bb31) = *(uint *)(unaff_EBP + 0xcd31bb31) ^ uVar20;
    *(uint *)(uVar10 + 0xb732a532) = *(uint *)(uVar10 + 0xb732a532) ^ uVar10;
    uVar11 = (uint)extraout_ECX & 0xffffff00;
    uVar20 = CONCAT31((int3)((ulonglong)uVar30 >> 0x28),
                      (byte)((ulonglong)uVar30 >> 0x20) ^ (byte)(uVar11 >> 8));
    puVar16 = (uint *)CONCAT31((int3)(uVar10 >> 8),(byte)uVar10 ^ *unaff_ESI);
    puVar15 = (undefined1 *)(uVar11 ^ *(uint *)(uVar11 + 0x33));
    piVar28 = (int *)0xdc33d833;
    unaff_EBX = puVar29;
  }
  puVar24 = (undefined2 *)0x0;
  puVar27 = (undefined4 *)(unaff_EBP ^ (uint)puVar16);
  uVar10 = (uint)unaff_ESI ^ (uint)puVar16;
  puVar29 = (uint *)((uint)piVar28 ^ (uint)puVar16);
  uVar11 = (uint)puVar16 ^ *puVar16 ^ 0x352635e3;
  if ((int)uVar11 < 0) {
    pcVar13 = (char *)(uVar11 + 1);
    if ((int)puVar29 <= (int)*(uint **)(uVar11 + 0x3a)) {
      puVar29 = (uint *)(*unaff_EBX * 0x3bd13b75);
      goto code_r0x009c3144;
    }
    bVar7 = (byte)unaff_EBX;
    bVar18 = 9 < ((byte)pcVar13 & 0xf) | bVar18;
    bVar6 = (byte)pcVar13 + bVar18 * -6 & 0xf;
    uRamfffffffc = CONCAT22((short)((uint)unaff_EBX >> 0x10),
                            CONCAT11(((char)((uint)unaff_EBX >> 8) - (byte)*puVar29) -
                                     (*(uint **)(uVar11 + 0x3a) < puVar29) ^ (byte)*puVar29,bVar7));
    bVar8 = 9 < bVar6 | bVar18;
    uVar10 = CONCAT31((int3)((uint)pcVar13 >> 8),bVar6 + bVar8 * -6) & 0xffff000f;
    puVar24 = (undefined2 *)
              CONCAT22((short)(uVar10 >> 0x10),
                       CONCAT11(((char)((uint)pcVar13 >> 8) - bVar18) - bVar8,(char)uVar10));
    uVar10 = CONCAT31(0xffffff,(bVar8 | 1) * -6 + -4) & 0xffffff0f;
    uVar10 = CONCAT22((short)(uVar10 >> 0x10),CONCAT11(-1 - (bVar8 | 1),(char)uVar10));
    pbVar9 = (byte *)(uVar10 * 2 + 0x300a0000);
    bVar18 = *pbVar9;
    *pbVar9 = *pbVar9 + bVar7;
    if (CARRY1(bVar18,bVar7)) {
      return;
    }
  }
  else {
    *puVar29 = uVar10 ^ 0x35a3359d;
    puVar15 = puRam00000018;
    uVar20 = _DAT_00000014;
    unaff_EBX = puRam00000010;
    puVar27 = _DAT_00000008;
    uVar5 = _DAT_00000004;
    puVar1 = (undefined1 *)segment(in_ES,(short)_DAT_00000000);
    puVar29 = (uint *)CONCAT22((short)((uint)_DAT_00000000 >> 0x10),(short)_DAT_00000000 + 1);
    uVar19 = (undefined2)_DAT_00000014;
    uVar2 = in(uVar19);
    uRamfffffffc = uVar11;
    *puVar1 = uVar2;
    uVar12 = in(uVar19);
    bVar18 = 9 < ((byte)uVar12 & 0xf) | bVar18;
    bVar8 = (byte)uVar12 + bVar18 * '\x06';
    bVar18 = 9 < (bVar8 & 0xf) | bVar18;
    bVar6 = bVar8 + bVar18 * '\x06' & 0xf;
    bVar8 = 9 < bVar6 | bVar18;
    uVar10 = CONCAT31((int3)((uint)uVar12 >> 8),bVar6 + bVar8 * '\x06') & 0xffff000f;
    pcVar13 = (char *)CONCAT22((short)(uVar10 >> 0x10),
                               CONCAT11((char)((uint)uVar12 >> 8) + bVar18 + bVar8,(char)uVar10));
    bVar8 = 9 < ((byte)uVar5 & 0xf) | bVar8;
    bVar18 = (byte)uVar5 + bVar8 * '\x06' & 0xf;
    puVar24 = (undefined2 *)0x24;
    bVar3 = 9 < bVar18 || (_DAT_00000020 & 0x10) != 0;
    uVar10 = CONCAT31((int3)((uint)uVar5 >> 8),bVar18 + bVar3 * '\x06') & 0xffff000f;
    bVar18 = (byte)uVar10;
    uVar11 = CONCAT22((short)(uVar10 >> 0x10),
                      CONCAT11((char)((uint)uVar5 >> 8) + bVar8 + bVar3,bVar18));
    if (((_DAT_00000020 & 0x800) != 0) == ((_DAT_00000020 & 0x80) != 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((_DAT_00000020 & 0x40) == 0) {
      uVar23 = (undefined3)(uVar20 >> 8);
      bVar18 = (byte)uVar20 ^ bVar18;
      uVar21 = CONCAT31(uVar23,bVar18);
      pbVar9 = (byte *)(uVar11 + 0x31);
      *pbVar9 = *pbVar9 ^ (byte)((uint)puVar15 >> 8);
      if (-1 < (char)*pbVar9) goto code_r0x009c31b5;
      *puVar15 = (char)(uVar20 >> 8);
      uVar10 = (uint)puVar15 ^ uVar21;
      puVar16 = (uint *)(uVar11 ^ (uint)pcVar13);
      *puVar16 = *puVar16 ^ (uint)puVar29;
      iVar17 = CONCAT31((int3)((uint)puVar16 >> 8),(byte)puVar16 ^ pcVar13[uVar21 + 0x75]);
      uVar20 = CONCAT31(uVar23,bVar18 ^ *(byte *)((int)unaff_EBX + 0x232e032));
LAB_009c3197:
      uVar30 = CONCAT44(uVar20 ^ *(uint *)(iVar17 + -0x9cc42cd),uVar10);
    }
    else {
      *unaff_EBX = (int)*unaff_EBX >> 1;
      uVar10 = uVar11;
code_r0x009c3144:
      uVar30 = CONCAT44(uVar20,uVar10);
      iVar17 = 0;
      if (puVar15 == (undefined1 *)0x0) goto LAB_009c3197;
      pcVar4 = (code *)swi(4);
      if (SBORROW1(*pcVar13,(char)((uint)unaff_EBX >> 8))) {
        uVar30 = (*pcVar4)();
        puVar15 = extraout_ECX_00;
      }
      if (puVar15 == (undefined1 *)0x1) {
        pcVar4 = (code *)swi(1);
        (*pcVar4)();
        return;
      }
    }
    uVar20 = (uint)((ulonglong)uVar30 >> 0x20);
    out(*(undefined4 *)pcVar13,(short)((ulonglong)uVar30 >> 0x20));
    uVar10 = (uint)uVar30 ^ 0x7f;
  }
  piVar28 = (int *)(CONCAT44(uVar20,uVar10) / (ulonglong)*puVar29);
  *piVar28 = (int)(*piVar28 + (int)puVar29);
code_r0x009c31b5:
  *puVar24 = in_CS;
  puVar25 = puVar24 + -2;
  *(undefined4 *)(puVar24 + -2) = 0x9c31c3;
  func_0xd038a838();
  puVar26 = (undefined4 *)((int)puVar25 + -4);
  *(undefined4 **)((int)puVar25 + -4) = puVar27;
  cVar14 = '\x1c';
  do {
    puVar27 = puVar27 + -1;
    puVar26 = puVar26 + -1;
    *puVar26 = *puVar27;
    cVar14 = cVar14 + -1;
  } while ('\0' < cVar14);
  *(undefined1 **)((int)puVar25 + -0x78) = (undefined1 *)((int)puVar25 + -4);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
}

// =================================================
// Function: __amsg_exit
// =================================================
void __cdecl __amsg_exit(int param_1)
{
{
  code *extraout_EAX;
  undefined *puVar1;
  
  __FF_MSGBANNER();
  __NMSG_WRITE(param_1);
  puVar1 = PTR___exit_00cca470;
  __decode_pointer();
  (*extraout_EAX)(0xff,puVar1);
  return;
}
}

// =================================================
// Function: __aullshr
// =================================================
void __cdecl __aullshr(void)
{
{
  byte in_CL;
  
  if (0x3f < in_CL) {
    return;
  }
  if (in_CL < 0x20) {
    return;
  }
  return;
}
}

// =================================================
// Function: __callnewh
// =================================================
int __cdecl __callnewh(uint param_1)
{
{
  code *extraout_EAX;
  int iVar1;
  
  __decode_pointer();
  if (extraout_EAX != (code *)0x0) {
    iVar1 = (*extraout_EAX)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: __calloc_crt
// =================================================
void * __cdecl __calloc_crt(uint param_1,uint param_2)
{
{
  void *extraout_EAX;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  while( true ) {
    __calloc_impl();
    if (extraout_EAX != (void *)0x0) {
      return extraout_EAX;
    }
    if (DAT_00d53dd8 == 0) break;
    Sleep(dwMilliseconds);
    dwMilliseconds = dwMilliseconds + 1000;
    if (DAT_00d53dd8 < dwMilliseconds) {
      dwMilliseconds = 0xffffffff;
    }
    if (dwMilliseconds == 0xffffffff) {
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}
}

// =================================================
// Function: __calloc_impl
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl __calloc_impl(void)
{
{
  int *piVar1;
  void *extraout_EAX;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  uint dwBytes;
  uint in_stack_00000004;
  uint in_stack_00000008;
  undefined4 *in_stack_0000000c;
  
  if ((in_stack_00000004 == 0) || (in_stack_00000008 <= 0xffffffe0 / in_stack_00000004)) {
    uVar3 = in_stack_00000004 * in_stack_00000008;
    dwBytes = uVar3;
    if (uVar3 == 0) {
      dwBytes = 1;
    }
    do {
      pvVar4 = (void *)0x0;
      if (dwBytes < 0xffffffe1) {
        if ((DAT_00d7aec0 == 3) && (dwBytes = dwBytes + 0xf & 0xfffffff0, uVar3 <= DAT_00d7aeac)) {
          __lock(4);
          ___sbh_alloc_block();
          FUN_0040d2a7();
          if (extraout_EAX != (void *)0x0) {
            _memset(extraout_EAX,0,uVar3);
            pvVar4 = extraout_EAX;
            goto LAB_0040d25c;
          }
        }
        else {
LAB_0040d25c:
          if (pvVar4 != (void *)0x0) {
            return;
          }
        }
        pvVar4 = HeapAlloc(hHeap_00d53f34,8,dwBytes);
      }
      if (pvVar4 != (void *)0x0) {
        return;
      }
      if (DAT_00d54140 == 0) {
        if (in_stack_0000000c == (undefined4 *)0x0) {
          return;
        }
        *in_stack_0000000c = 0xc;
        return;
      }
      iVar2 = __callnewh(dwBytes);
    } while (iVar2 != 0);
    if (in_stack_0000000c != (undefined4 *)0x0) {
      *in_stack_0000000c = 0xc;
    }
  }
  else {
    piVar1 = __errno();
    *piVar1 = 0xc;
    __invalid_parameter();
  }
  return;
}
}

// =================================================
// Function: __crtGetStringTypeA_stat
// =================================================
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
__crtGetStringTypeA_stat
          (localeinfo_struct *param_1,ulong param_2,char *param_3,int param_4,ushort *param_5,
          int param_6,int param_7,int param_8)
{
{
  uint uVar1;
  BOOL BVar2;
  DWORD DVar3;
  uint cchWideChar;
  undefined4 *puVar4;
  int cchSrc;
  ushort *extraout_EAX;
  void *extraout_EAX_00;
  int *in_ECX;
  LPCWSTR lpWideCharStr;
  void *pvVar5;
  BOOL local_c;
  uint local_8;
  
  local_8 = DAT_00cca150 ^ (uint)&stack0xfffffffc;
  lpWideCharStr = (LPCWSTR)0x0;
  if (DAT_00d54150 == 0) {
    BVar2 = GetStringTypeW(1,(LPCWSTR)&lpSrcStr_00b2d1b4,1,(LPWORD)&local_c);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x78) {
        DAT_00d54150 = 2;
      }
      goto LAB_0040db27;
    }
    DAT_00d54150 = 1;
  }
  else {
LAB_0040db27:
    if ((DAT_00d54150 == 2) || (DAT_00d54150 == 0)) {
      pvVar5 = (void *)0x0;
      if (param_6 == 0) {
        param_6 = *(int *)(*in_ECX + 0x14);
      }
      if (param_5 == (ushort *)0x0) {
        param_5 = *(ushort **)(*in_ECX + 4);
      }
      ___ansicp();
      if (extraout_EAX == (ushort *)0xffffffff) {
        return 0;
      }
      if ((extraout_EAX != param_5) &&
         (___convertcp(), pvVar5 = extraout_EAX_00, param_2 = (ulong)extraout_EAX_00,
         extraout_EAX_00 == (void *)0x0)) {
        return 0;
      }
      BVar2 = GetStringTypeA(param_6,(DWORD)param_1,(LPCSTR)param_2,(int)param_3,(LPWORD)param_4);
      if (pvVar5 != (void *)0x0) {
        _free(pvVar5);
        return BVar2;
      }
      return BVar2;
    }
    if (DAT_00d54150 != 1) {
      return 0;
    }
  }
  local_c = 0;
  if (param_5 == (ushort *)0x0) {
    param_5 = *(ushort **)(*in_ECX + 4);
  }
  cchWideChar = MultiByteToWideChar((UINT)param_5,(uint)(param_7 != 0) * 8 + 1,(LPCSTR)param_2,
                                    (int)param_3,(LPWSTR)0x0,0);
  if (cchWideChar == 0) {
    return 0;
  }
  if ((0 < (int)cchWideChar) && (cchWideChar < 0x7ffffff1)) {
    uVar1 = cchWideChar * 2 + 8;
    if (uVar1 < 0x401) {
      puVar4 = (undefined4 *)&stack0xffffffe8;
      lpWideCharStr = (LPCWSTR)&stack0xffffffe8;
      if (&stack0x00000000 == (undefined1 *)0x18) goto LAB_0040dbbc;
    }
    else {
      puVar4 = _malloc(uVar1);
      lpWideCharStr = (LPCWSTR)0x0;
      if (puVar4 == (undefined4 *)0x0) goto LAB_0040dbbc;
      *puVar4 = 0xdddd;
    }
    lpWideCharStr = (LPCWSTR)(puVar4 + 2);
  }
LAB_0040dbbc:
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  _memset(lpWideCharStr,0,cchWideChar * 2);
  cchSrc = MultiByteToWideChar((UINT)param_5,1,(LPCSTR)param_2,(int)param_3,lpWideCharStr,
                               cchWideChar);
  if (cchSrc != 0) {
    local_c = GetStringTypeW((DWORD)param_1,lpWideCharStr,cchSrc,(LPWORD)param_4);
  }
  __freea(lpWideCharStr);
  return local_c;
}
}

// =================================================
// Function: __crtLCMapStringA_stat
// =================================================
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
__crtLCMapStringA_stat
          (localeinfo_struct *param_1,ulong param_2,ulong param_3,char *param_4,int param_5,
          char *param_6,int param_7,int param_8,int param_9)
{
{
  uint uVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 *puVar7;
  LPCWSTR lpDestStr;
  int extraout_EAX;
  LPCSTR lpSrcStr;
  LPSTR lpDestStr_00;
  void *extraout_EAX_00;
  int *in_ECX;
  char *pcVar8;
  void *local_14;
  LPCWSTR local_10;
  uint local_c;
  
  if (DAT_00d5414c == 0) {
    iVar3 = LCMapStringW(0,0x100,(LPCWSTR)&lpSrcStr_00b2d1b4,1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00d5414c = 2;
      }
    }
    else {
      DAT_00d5414c = 1;
    }
  }
  pcVar5 = (char *)param_3;
  pcVar8 = param_4;
  if (0 < (int)param_4) {
    do {
      pcVar8 = pcVar8 + -1;
      if (*pcVar5 == '\0') goto LAB_0040d758;
      pcVar5 = pcVar5 + 1;
    } while (pcVar8 != (char *)0x0);
    pcVar8 = (char *)0xffffffff;
LAB_0040d758:
    pcVar5 = param_4 + -(int)pcVar8;
    bVar2 = (int)(pcVar5 + -1) < (int)param_4;
    param_4 = pcVar5 + -1;
    if (bVar2) {
      param_4 = pcVar5;
    }
  }
  if ((DAT_00d5414c == 2) || (DAT_00d5414c == 0)) {
    local_10 = (LPCWSTR)0x0;
    local_14 = (void *)0x0;
    if (param_1 == (localeinfo_struct *)0x0) {
      param_1 = *(localeinfo_struct **)(*in_ECX + 0x14);
    }
    if (param_7 == 0) {
      param_7 = *(int *)(*in_ECX + 4);
    }
    ___ansicp();
    if (extraout_EAX == -1) {
      return 0;
    }
    if (extraout_EAX == param_7) {
      uVar6 = LCMapStringA((LCID)param_1,param_2,(LPCSTR)param_3,(int)param_4,(LPSTR)param_5,
                           (int)param_6);
      goto LAB_0040da56;
    }
    ___convertcp();
    if (lpSrcStr == (LPCSTR)0x0) {
      return 0;
    }
    uVar6 = LCMapStringA((LCID)param_1,param_2,lpSrcStr,(int)param_4,(LPSTR)0x0,0);
    local_10 = (LPCWSTR)lpSrcStr;
    if (uVar6 != 0) {
      if (((int)uVar6 < 1) || (0xffffffe0 < uVar6)) {
        lpDestStr_00 = (LPSTR)0x0;
      }
      else if (uVar6 + 8 < 0x401) {
        if (&stack0x00000000 == (undefined1 *)0x24) goto LAB_0040d998;
        lpDestStr_00 = &stack0xffffffe4;
      }
      else {
        lpDestStr_00 = _malloc(uVar6 + 8);
        if (lpDestStr_00 != (LPSTR)0x0) {
          lpDestStr_00[0] = -0x23;
          lpDestStr_00[1] = -0x23;
          lpDestStr_00[2] = '\0';
          lpDestStr_00[3] = '\0';
          lpDestStr_00 = lpDestStr_00 + 8;
        }
      }
      if (lpDestStr_00 != (LPSTR)0x0) {
        _memset(lpDestStr_00,0,uVar6);
        uVar6 = LCMapStringA((LCID)param_1,param_2,lpSrcStr,(int)param_4,lpDestStr_00,uVar6);
        if (uVar6 == 0) {
          uVar6 = 0;
        }
        else {
          ___convertcp();
          uVar6 = -(uint)(extraout_EAX_00 != (void *)0x0) & uVar6;
          local_14 = extraout_EAX_00;
        }
        __freea(lpDestStr_00);
        goto LAB_0040da56;
      }
    }
LAB_0040d998:
    uVar6 = 0;
LAB_0040da56:
    if (local_10 != (LPCWSTR)0x0) {
      _free(local_10);
    }
    if (local_14 != (void *)0x0) {
      if ((void *)param_5 != local_14) {
        _free(local_14);
        return uVar6;
      }
      return uVar6;
    }
    return uVar6;
  }
  if (DAT_00d5414c != 1) {
    return 0;
  }
  local_c = 0;
  if (param_7 == 0) {
    param_7 = *(int *)(*in_ECX + 4);
  }
  uVar6 = MultiByteToWideChar(param_7,(uint)(param_8 != 0) * 8 + 1,(LPCSTR)param_3,(int)param_4,
                              (LPWSTR)0x0,0);
  if (uVar6 == 0) {
    return 0;
  }
  if (((int)uVar6 < 1) || (0xffffffe0 / uVar6 < 2)) {
    local_10 = (LPCWSTR)0x0;
  }
  else {
    uVar1 = uVar6 * 2 + 8;
    if (uVar1 < 0x401) {
      puVar7 = (undefined4 *)&stack0xffffffdc;
      local_10 = (LPCWSTR)&stack0xffffffdc;
      if (&stack0x00000000 != (undefined1 *)0x24) {
LAB_0040d800:
        local_10 = (LPCWSTR)(puVar7 + 2);
      }
    }
    else {
      puVar7 = _malloc(uVar1);
      local_10 = (LPCWSTR)0x0;
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = 0xdddd;
        goto LAB_0040d800;
      }
    }
  }
  if (local_10 == (LPCWSTR)0x0) {
    return 0;
  }
  iVar3 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,(int)param_4,local_10,uVar6);
  if ((iVar3 != 0) &&
     (local_c = LCMapStringW((LCID)param_1,param_2,local_10,uVar6,(LPWSTR)0x0,0), local_c != 0)) {
    if ((param_2 & 0x400) == 0) {
      if (((int)local_c < 1) || (0xffffffe0 / local_c < 2)) {
        lpDestStr = (LPCWSTR)0x0;
      }
      else {
        uVar1 = local_c * 2 + 8;
        if (uVar1 < 0x401) {
          if (&stack0x00000000 == (undefined1 *)0x24) goto LAB_0040d90f;
          lpDestStr = (LPCWSTR)&stack0xffffffe4;
        }
        else {
          lpDestStr = _malloc(uVar1);
          if (lpDestStr != (LPCWSTR)0x0) {
            lpDestStr[0] = L'\xdddd';
            lpDestStr[1] = L'\0';
            lpDestStr = lpDestStr + 4;
          }
        }
      }
      if (lpDestStr != (LPCWSTR)0x0) {
        iVar3 = LCMapStringW((LCID)param_1,param_2,local_10,uVar6,lpDestStr,local_c);
        if (iVar3 != 0) {
          if (param_6 == (char *)0x0) {
            param_6 = (char *)0x0;
            param_5 = 0;
          }
          local_c = WideCharToMultiByte(param_7,0,lpDestStr,local_c,(LPSTR)param_5,(int)param_6,
                                        (LPCSTR)0x0,(LPBOOL)0x0);
        }
        __freea(lpDestStr);
      }
    }
    else if ((param_6 != (char *)0x0) && ((int)local_c <= (int)param_6)) {
      LCMapStringW((LCID)param_1,param_2,local_10,uVar6,(LPWSTR)param_5,(int)param_6);
    }
  }
LAB_0040d90f:
  __freea(local_10);
  return local_c;
}
}

// =================================================
// Function: __crt_debugger_hook
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __crt_debugger_hook(int param_1)
{
{
  _DAT_00d7aebc = 0;
  return;
}
}

// =================================================
// Function: __decode_pointer
// =================================================
void __cdecl __decode_pointer(void)
{
{
  LPVOID pvVar1;
  code *pcVar2;
  int iVar3;
  HMODULE hModule;
  int extraout_EAX;
  FARPROC pFVar4;
  undefined4 in_stack_00000004;
  
  pvVar1 = TlsGetValue(dwTlsIndex_00cca204);
  if ((pvVar1 != (LPVOID)0x0) && (DAT_00cca200 != -1)) {
    iVar3 = DAT_00cca200;
    pcVar2 = TlsGetValue(dwTlsIndex_00cca204);
    iVar3 = (*pcVar2)(iVar3);
    if (iVar3 != 0) {
      pFVar4 = *(FARPROC *)(iVar3 + 0x1fc);
      goto LAB_00404ee0;
    }
  }
  hModule = GetModuleHandleA("KERNEL32.DLL");
  if (hModule == (HMODULE)0x0) {
    return;
  }
  __use_encode_pointer();
  if (extraout_EAX == 0) {
    return;
  }
  pFVar4 = GetProcAddress(hModule,"DecodePointer");
LAB_00404ee0:
  if (pFVar4 != (FARPROC)0x0) {
    (*pFVar4)(in_stack_00000004);
  }
  return;
}
}

// =================================================
// Function: __encode_pointer
// =================================================
void __cdecl __encode_pointer(void)
{
{
  LPVOID pvVar1;
  code *pcVar2;
  int iVar3;
  HMODULE hModule;
  int extraout_EAX;
  FARPROC pFVar4;
  undefined4 in_stack_00000004;
  
  pvVar1 = TlsGetValue(dwTlsIndex_00cca204);
  if ((pvVar1 != (LPVOID)0x0) && (DAT_00cca200 != -1)) {
    iVar3 = DAT_00cca200;
    pcVar2 = TlsGetValue(dwTlsIndex_00cca204);
    iVar3 = (*pcVar2)(iVar3);
    if (iVar3 != 0) {
      pFVar4 = *(FARPROC *)(iVar3 + 0x1f8);
      goto LAB_00404e69;
    }
  }
  hModule = GetModuleHandleA("KERNEL32.DLL");
  if (hModule == (HMODULE)0x0) {
    return;
  }
  __use_encode_pointer();
  if (extraout_EAX == 0) {
    return;
  }
  pFVar4 = GetProcAddress(hModule,"EncodePointer");
LAB_00404e69:
  if (pFVar4 != (FARPROC)0x0) {
    (*pFVar4)(in_stack_00000004);
  }
  return;
}
}

// =================================================
// Function: __encoded_null
// =================================================
void __cdecl __encoded_null(void)
{
{
  __encode_pointer();
  return;
}
}

// =================================================
// Function: __errno
// =================================================
int * __cdecl __errno(void)
{
{
  _tiddata *p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_tiddata *)0x0) {
    return (int *)&DAT_00cca448;
  }
  return &p_Var1->_terrno;
}
}

// =================================================
// Function: __freea
// =================================================
void __cdecl __freea(void *param_1)
{
{
  if ((param_1 != (void *)0x0) && (*(int *)((int)param_1 + -8) == 0xdddd)) {
    _free((int *)((int)param_1 + -8));
  }
  return;
}
}

// =================================================
// Function: __ftol2
// =================================================
/* WARNING: Control flow encountered bad instruction data */

void __cdecl __ftol2(void)
{
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined4 in_EAX;
  uint uVar5;
  undefined4 unaff_EBX;
  char *unaff_EDI;
  byte in_AF;
  char *pcVar6;
  
  *unaff_EDI = *unaff_EDI - (char)((uint)unaff_EBX >> 8);
  bVar1 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  bVar3 = (byte)in_EAX + bVar1 * -6 & 0xf;
  bVar2 = 9 < bVar3 | bVar1;
  bVar4 = bVar3 + bVar2 * -6 & 0xf;
  bVar3 = 9 < bVar4 | bVar2;
  uVar5 = CONCAT31((int3)((uint)in_EAX >> 8),bVar4 + bVar3 * -6) & 0xffff000f;
  pcVar6 = (char *)CONCAT22((short)(uVar5 >> 0x10),
                            CONCAT11((((char)((uint)in_EAX >> 8) - bVar1) - bVar2) - bVar3,
                                     (char)uVar5));
  *pcVar6 = *pcVar6 >> 10;
  *pcVar6 = *pcVar6 >> 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: __ftol2_sse
// =================================================
/* WARNING: Control flow encountered bad instruction data */

void __cdecl __ftol2_sse(void)
{
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined4 in_EAX;
  uint uVar6;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  byte in_AF;
  char *pcVar7;
  
  *unaff_EDI = *unaff_ESI;
  bVar1 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  bVar3 = (byte)in_EAX + bVar1 * '\x06' & 0xf;
  bVar2 = 9 < bVar3 | bVar1;
  bVar4 = bVar3 + bVar2 * -6 & 0xf;
  bVar3 = 9 < bVar4 | bVar2;
  bVar5 = bVar4 + bVar3 * -6 & 0xf;
  bVar4 = 9 < bVar5 | bVar3;
  uVar6 = CONCAT31((int3)((uint)in_EAX >> 8),bVar5 + bVar4 * -6) & 0xffff000f;
  pcVar7 = (char *)CONCAT22((short)(uVar6 >> 0x10),
                            CONCAT11(((((char)((uint)in_EAX >> 8) + bVar1) - bVar2) - bVar3) - bVar4
                                     ,(char)uVar6));
  *pcVar7 = *pcVar7 >> 10;
  *pcVar7 = *pcVar7 >> 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: __get_errno_from_oserr
// =================================================
int __cdecl __get_errno_from_oserr(ulong param_1)
{
{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_1 == (&DAT_00cca2e0)[uVar1 * 2]) {
      return *(int *)(uVar1 * 8 + 0xcca2e4);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x2d);
  if (param_1 - 0x13 < 0x12) {
    return 0xd;
  }
  return (-(uint)(0xe < param_1 - 0xbc) & 0xe) + 8;
}
}

// =================================================
// Function: __get_osplatform
// =================================================
void __cdecl __get_osplatform(void)
{
{
  int *piVar1;
  int *in_stack_00000004;
  
  if ((in_stack_00000004 != (int *)0x0) && (DAT_00d53de0 != 0)) {
    *in_stack_00000004 = DAT_00d53de0;
    return;
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  __invalid_parameter();
  return;
}
}

// =================================================
// Function: __get_winmajor
// =================================================
void __cdecl __get_winmajor(void)
{
{
  int *piVar1;
  undefined4 *in_stack_00000004;
  
  if ((in_stack_00000004 != (undefined4 *)0x0) && (DAT_00d53de0 != 0)) {
    *in_stack_00000004 = DAT_00d53dec;
    return;
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  __invalid_parameter();
  return;
}
}

// =================================================
// Function: __getptd
// =================================================
_tiddata * __cdecl __getptd(void)
{
{
  _tiddata *p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_tiddata *)0x0) {
    __amsg_exit(0x10);
  }
  return p_Var1;
}
}

// =================================================
// Function: __getptd_noexit
// =================================================
_tiddata * __cdecl __getptd_noexit(void)
{
{
  DWORD dwErrCode;
  code *extraout_EAX;
  _tiddata *p_Var1;
  code *extraout_EAX_00;
  int iVar2;
  DWORD DVar3;
  undefined4 uVar4;
  _tiddata *p_Var5;
  
  dwErrCode = GetLastError();
  uVar4 = DAT_00cca200;
  ___set_flsgetvalue();
  p_Var1 = (_tiddata *)(*extraout_EAX)(uVar4);
  if (p_Var1 == (_tiddata *)0x0) {
    p_Var1 = __calloc_crt(1,0x214);
    if (p_Var1 != (_tiddata *)0x0) {
      uVar4 = DAT_00cca200;
      p_Var5 = p_Var1;
      __decode_pointer();
      iVar2 = (*extraout_EAX_00)(uVar4,p_Var5);
      if (iVar2 == 0) {
        _free(p_Var1);
        p_Var1 = (_tiddata *)0x0;
      }
      else {
        __initptd(p_Var1,(threadlocaleinfostruct *)0x0);
        DVar3 = GetCurrentThreadId();
        p_Var1->_thandle = 0xffffffff;
        p_Var1->_tid = DVar3;
      }
    }
  }
  SetLastError(dwErrCode);
  return p_Var1;
}
}

// =================================================
// Function: __initptd
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl __initptd(_tiddata *param_1,threadlocaleinfostruct *param_2)
{
{
  HMODULE hModule;
  int extraout_EAX;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32.DLL");
  param_1->_pxcptacttab = &DAT_00cca478;
  param_1->_holdrand = 1;
  if (hModule != (HMODULE)0x0) {
    __use_encode_pointer();
    if (extraout_EAX != 0) {
      pFVar1 = GetProcAddress(hModule,"EncodePointer");
      *(FARPROC *)((param_1->_setloc_data)._cacheout + 0x1d) = pFVar1;
      pFVar1 = GetProcAddress(hModule,"DecodePointer");
      *(FARPROC *)((param_1->_setloc_data)._cacheout + 0x1f) = pFVar1;
    }
  }
  param_1->_ownlocale = 1;
  *(undefined1 *)((param_1->_setloc_data)._cachein + 8) = 0x43;
  *(undefined1 *)((int)(param_1->_setloc_data)._cachein + 0x93) = 0x43;
  param_1->ptmbcinfo = (threadmbcinfostruct *)&DAT_00cca540;
  InterlockedIncrement((LONG *)&DAT_00cca540);
  __lock(0xc);
  param_1->ptlocinfo = param_2;
  if (param_2 == (threadlocaleinfostruct *)0x0) {
    param_1->ptlocinfo = (threadlocaleinfostruct *)PTR_DAT_00ccab48;
  }
  ___addlocaleref();
  FUN_00405022();
  return;
}
}

// =================================================
// Function: __initterm
// =================================================
void __cdecl __initterm(void)
{
{
  undefined4 *in_EAX;
  undefined4 *in_stack_00000004;
  
  for (; in_EAX < in_stack_00000004; in_EAX = in_EAX + 1) {
    if ((code *)*in_EAX != (code *)0x0) {
      (*(code *)*in_EAX)();
    }
  }
  return;
}
}

// =================================================
// Function: __invalid_parameter
// =================================================
void __cdecl __invalid_parameter(void)
{
{
  code *UNRECOVERED_JUMPTABLE;
  wchar_t *in_stack_00000004;
  wchar_t *in_stack_00000008;
  wchar_t *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  
  __decode_pointer();
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00405d20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  __crt_debugger_hook(2);
                    /* WARNING: Subroutine does not return */
  __invoke_watson(in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010,
                  in_stack_00000014);
}
}

// =================================================
// Function: __invalid_parameter_noinfo
// =================================================
void __cdecl __invalid_parameter_noinfo(void)
{
{
  __invalid_parameter();
  return;
}
}

// =================================================
// Function: __invoke_watson
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl
__invoke_watson(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uint param_5)
{
{
  BOOL BVar1;
  LONG LVar2;
  HANDLE hProcess;
  UINT uExitCode;
  EXCEPTION_RECORD local_32c;
  _EXCEPTION_POINTERS local_2dc;
  undefined4 local_2d4;
  
  local_2d4 = 0x10001;
  _memset(&local_32c,0,0x50);
  local_2dc.ExceptionRecord = &local_32c;
  local_2dc.ContextRecord = (PCONTEXT)&local_2d4;
  local_32c.ExceptionCode = 0xc000000d;
  BVar1 = IsDebuggerPresent();
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  LVar2 = UnhandledExceptionFilter(&local_2dc);
  if ((LVar2 == 0) && (BVar1 == 0)) {
    __crt_debugger_hook(2);
  }
  uExitCode = 0xc000000d;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}
}

// =================================================
// Function: __isalpha_l
// =================================================
int __cdecl __isalpha_l(int param_1,localeinfo_struct *param_2)
{
{
  uint uVar1;
  threadlocaleinfostruct *in_stack_ffffffec;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate
            (&stack0xffffffec,(_LocaleUpdate *)param_2,(localeinfo_struct *)in_stack_ffffffec);
  if ((int)in_stack_ffffffec->locale_name[3] < 2) {
    uVar1 = *(ushort *)(in_stack_ffffffec[1].lc_category[0].locale + param_1 * 2) & 0x103;
  }
  else {
    uVar1 = __isctype_l(param_1,0x103,(localeinfo_struct *)&stack0xffffffec);
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1;
}
}

// =================================================
// Function: __isctype_l
// =================================================
int __cdecl __isctype_l(int param_1,int param_2,localeinfo_struct *param_3)
{
{
  int iVar1;
  char cVar2;
  localeinfo_struct *unaff_EBX;
  localeinfo_struct local_1c;
  int local_14;
  char local_10;
  char local_c;
  char local_b;
  undefined1 local_a;
  ushort local_8 [2];
  
  _LocaleUpdate::_LocaleUpdate(&local_1c,(_LocaleUpdate *)param_3,unaff_EBX);
  if (param_1 + 1U < 0x101) {
    local_8[0] = *(ushort *)(local_1c.locinfo[1].lc_category[0].locale + param_1 * 2);
  }
  else {
    iVar1 = __isleadbyte_l(param_1 >> 8 & 0xff,&local_1c);
    cVar2 = (char)param_1;
    if (iVar1 == 0) {
      local_b = '\0';
      iVar1 = 1;
      local_c = cVar2;
    }
    else {
      param_1._0_1_ = (char)((uint)param_1 >> 8);
      local_c = (char)param_1;
      local_a = 0;
      iVar1 = 2;
      local_b = cVar2;
    }
    iVar1 = ___crtGetStringTypeA
                      (&local_1c,1,&local_c,iVar1,local_8,(local_1c.locinfo)->lc_codepage,
                       (int)(local_1c.locinfo)->lc_category[0].wlocale);
    if (iVar1 == 0) {
      if (local_10 != '\0') {
        *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      }
      return 0;
    }
  }
  if (local_10 != '\0') {
    *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
  }
  return (uint)local_8[0] & param_2;
}
}

// =================================================
// Function: __isleadbyte_l
// =================================================
int __cdecl __isleadbyte_l(int param_1,localeinfo_struct *param_2)
{
{
  ushort uVar1;
  localeinfo_struct *in_stack_ffffffec;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate(&stack0xffffffec,(_LocaleUpdate *)param_2,in_stack_ffffffec);
  uVar1 = *(ushort *)
           ((int)&((threadlocaleinfostruct *)((in_stack_ffffffec[0x19].locinfo)->lc_category + -1))
                  ->refcount + (param_1 & 0xffU) * 2);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1 & 0x8000;
}
}

// =================================================
// Function: __isspace_l
// =================================================
int __cdecl __isspace_l(int param_1,localeinfo_struct *param_2)
{
{
  uint uVar1;
  threadlocaleinfostruct *in_stack_ffffffec;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate
            (&stack0xffffffec,(_LocaleUpdate *)param_2,(localeinfo_struct *)in_stack_ffffffec);
  if ((int)in_stack_ffffffec->locale_name[3] < 2) {
    uVar1 = (byte)in_stack_ffffffec[1].lc_category[0].locale[param_1 * 2] & 8;
  }
  else {
    uVar1 = __isctype_l(param_1,8,(localeinfo_struct *)&stack0xffffffec);
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1;
}
}

// =================================================
// Function: __lock
// =================================================
void __cdecl __lock(int param_1)
{
{
  int iVar1;
  
  if ((&lpCriticalSection_00ccab60)[param_1 * 2] == (LPCRITICAL_SECTION)0x0) {
    iVar1 = __mtinitlocknum(param_1);
    if (iVar1 == 0) {
      __amsg_exit(0x11);
    }
  }
  EnterCriticalSection((&lpCriticalSection_00ccab60)[param_1 * 2]);
  return;
}
}

// =================================================
// Function: __lockexit
// =================================================
void __cdecl __lockexit(void)
{
{
  __lock(8);
  return;
}
}

// =================================================
// Function: __lzo1x_1_do_compress
// =================================================
void __cdecl __lzo1x_1_do_compress(void)
{
{
  int iVar1;
  byte bVar2;
  char cVar3;
  int in_EAX;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *in_stack_00000004;
  byte *in_stack_00000008;
  int *in_stack_0000000c;
  int in_stack_00000010;
  uint local_18;
  byte *local_14;
  uint local_10;
  uint local_8;
  
  local_14 = in_stack_00000004;
  pbVar9 = in_stack_00000004 + 4;
  pbVar8 = in_stack_00000008;
  do {
    uVar4 = ((((uint)pbVar9[3] << 6 ^ (uint)pbVar9[2]) << 5 ^ (uint)pbVar9[1]) << 5 ^ (uint)*pbVar9)
            * 0x21 >> 5;
    uVar5 = uVar4 & 0x3fff;
    pbVar7 = *(byte **)(in_stack_00000010 + uVar5 * 4);
    puVar6 = (undefined4 *)(in_stack_00000010 + uVar5 * 4);
    if (pbVar7 < in_stack_00000004) {
LAB_0090fab7:
      *puVar6 = pbVar9;
      pbVar9 = pbVar9 + 1;
    }
    else {
      local_18 = (int)pbVar9 - (int)pbVar7;
      local_10 = local_18 - 1;
      if (0xbffe < local_10) goto LAB_0090fab7;
      if ((0x800 < local_18) && (pbVar7[3] != pbVar9[3])) {
        uVar4 = uVar4 & 0x7ff ^ 0x201f;
        pbVar7 = *(byte **)(in_stack_00000010 + uVar4 * 4);
        puVar6 = (undefined4 *)(in_stack_00000010 + uVar4 * 4);
        if (in_stack_00000004 <= pbVar7) {
          local_18 = (int)pbVar9 - (int)pbVar7;
          local_10 = local_18 - 1;
          if ((local_10 < 0xbfff) && ((local_18 < 0x801 || (pbVar7[3] == pbVar9[3]))))
          goto LAB_0090f85d;
        }
        goto LAB_0090fab7;
      }
LAB_0090f85d:
      if ((*(short *)pbVar7 != *(short *)pbVar9) || (pbVar7[2] != pbVar9[2])) goto LAB_0090fab7;
      uVar4 = (int)pbVar9 - (int)local_14;
      *puVar6 = pbVar9;
      if (uVar4 != 0) {
        if (uVar4 < 4) {
          pbVar8[-2] = pbVar8[-2] | (byte)uVar4;
        }
        else {
          if (uVar4 < 0x13) {
            local_8 = (uint)(byte)((byte)uVar4 - 3);
          }
          else {
            local_8 = uVar4 - 0x12;
            *pbVar8 = 0;
            pbVar8 = pbVar8 + 1;
            if (0xff < local_8) {
              uVar5 = (uVar4 - 0x112) / 0xff + 1;
              _memset(pbVar8,0,uVar5);
              pbVar8 = pbVar8 + uVar5;
              do {
                local_8 = local_8 - 0xff;
                uVar5 = uVar5 - 1;
              } while (uVar5 != 0);
            }
          }
          *pbVar8 = (byte)local_8;
          pbVar8 = pbVar8 + 1;
        }
        do {
          *pbVar8 = *local_14;
          pbVar8 = pbVar8 + 1;
          local_14 = local_14 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      pbVar10 = pbVar9 + 4;
      if (((((pbVar7[3] == pbVar9[3]) &&
            (bVar2 = *pbVar10, pbVar10 = pbVar9 + 5, pbVar7[4] == bVar2)) &&
           (bVar2 = *pbVar10, pbVar10 = pbVar9 + 6, pbVar7[5] == bVar2)) &&
          ((bVar2 = *pbVar10, pbVar10 = pbVar9 + 7, pbVar7[6] == bVar2 &&
           (bVar2 = *pbVar10, pbVar10 = pbVar9 + 8, pbVar7[7] == bVar2)))) &&
         (bVar2 = *pbVar10, pbVar10 = pbVar9 + 9, pbVar7[8] == bVar2)) {
        pbVar9 = pbVar10;
        for (pbVar7 = pbVar7 + 9; (pbVar9 < in_stack_00000004 + in_EAX && (*pbVar7 == *pbVar9));
            pbVar7 = pbVar7 + 1) {
          pbVar9 = pbVar9 + 1;
        }
        uVar4 = (int)pbVar9 - (int)local_14;
        if (local_18 < 0x4001) {
          local_18 = local_10;
          if (uVar4 < 0x22) {
            *pbVar8 = (char)uVar4 - 2U | 0x20;
          }
          else {
            iVar1 = -0x21;
            *pbVar8 = 0x20;
LAB_0090f9ea:
            uVar4 = uVar4 + iVar1;
            pbVar8 = pbVar8 + 1;
            if (0xff < uVar4) {
              uVar5 = (uVar4 - 0x100) / 0xff + 1;
              _memset(pbVar8,0,uVar5);
              pbVar8 = pbVar8 + uVar5;
              do {
                uVar4 = uVar4 - 0xff;
                uVar5 = uVar5 - 1;
              } while (uVar5 != 0);
            }
            *pbVar8 = (byte)uVar4;
            local_10 = local_18;
          }
        }
        else {
          local_10 = local_18 - 0x4000;
          bVar2 = (byte)(local_10 >> 0xb) & 8;
          if (9 < uVar4) {
            iVar1 = -9;
            *pbVar8 = bVar2 | 0x10;
            local_18 = local_10;
            goto LAB_0090f9ea;
          }
          *pbVar8 = bVar2 | (char)uVar4 - 2U | 0x10;
        }
LAB_0090fa9b:
        pbVar8[1] = (char)local_10 * '\x04';
        pbVar8[2] = (byte)(local_10 >> 6);
        pbVar8 = pbVar8 + 3;
        local_14 = pbVar9;
      }
      else {
        pbVar9 = pbVar10 + -1;
        cVar3 = (char)pbVar9 - (char)local_14;
        if (0x800 < local_18) {
          bVar2 = cVar3 - 2;
          if (local_18 < 0x4001) {
            *pbVar8 = bVar2 | 0x20;
          }
          else {
            local_10 = local_18 - 0x4000;
            *pbVar8 = (byte)(local_10 >> 0xb) & 8 | bVar2 | 0x10;
          }
          goto LAB_0090fa9b;
        }
        *pbVar8 = ((cVar3 + -1) * '\b' | (byte)local_10 & 7) * '\x04';
        pbVar8[1] = (byte)(local_10 >> 3);
        pbVar8 = pbVar8 + 2;
        local_14 = pbVar9;
      }
    }
    if (in_stack_00000004 + in_EAX + -0xd <= pbVar9) {
      *in_stack_0000000c = (int)pbVar8 - (int)in_stack_00000008;
      return;
    }
  } while( true );
}
}

// =================================================
// Function: __malloc_crt
// =================================================
void * __cdecl __malloc_crt(uint param_1)
{
{
  void *pvVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  while( true ) {
    pvVar1 = _malloc(param_1);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (DAT_00d53dd8 == 0) break;
    Sleep(dwMilliseconds);
    dwMilliseconds = dwMilliseconds + 1000;
    if (DAT_00d53dd8 < dwMilliseconds) {
      dwMilliseconds = 0xffffffff;
    }
    if (dwMilliseconds == 0xffffffff) {
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}
}

// =================================================
// Function: __msize
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

uint __cdecl __msize(void *param_1)
{
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint local_20;
  
  if (param_1 == (void *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter();
    uVar2 = 0xffffffff;
  }
  else {
    if (DAT_00d7aec0 == 3) {
      __lock(4);
      iVar3 = thunk____sbh_find_block(param_1);
      if (iVar3 != 0) {
        local_20 = *(int *)((int)param_1 + -4) - 9;
      }
      FUN_00407f33();
      if (iVar3 != 0) {
        return local_20;
      }
    }
    uVar2 = HeapSize(hHeap_00d53f34,0,param_1);
  }
  return uVar2;
}
}

// =================================================
// Function: __mtinitlocknum
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

int __cdecl __mtinitlocknum(int param_1)
{
{
  LPCRITICAL_SECTION *pp_Var1;
  LPCRITICAL_SECTION p_Var2;
  int *piVar3;
  int extraout_EAX;
  int iVar4;
  int local_20;
  
  iVar4 = 1;
  local_20 = 1;
  if (hHeap_00d53f34 != (HANDLE)0x0) {
    pp_Var1 = &lpCriticalSection_00ccab60 + param_1 * 2;
    if (*pp_Var1 == (LPCRITICAL_SECTION)0x0) {
      p_Var2 = __malloc_crt(0x18);
      if (p_Var2 == (LPCRITICAL_SECTION)0x0) {
        piVar3 = __errno();
        *piVar3 = 0xc;
        iVar4 = 0;
      }
      else {
        __lock(10);
        if (*pp_Var1 == (LPCRITICAL_SECTION)0x0) {
          ___crtInitCritSecAndSpinCount();
          if (extraout_EAX == 0) {
            _free(p_Var2);
            piVar3 = __errno();
            *piVar3 = 0xc;
            local_20 = 0;
          }
          else {
            *pp_Var1 = p_Var2;
          }
        }
        else {
          _free(p_Var2);
        }
        FUN_0040b279();
        iVar4 = local_20;
      }
    }
    return iVar4;
  }
  __FF_MSGBANNER();
  __NMSG_WRITE(0x1e);
                    /* WARNING: Subroutine does not return */
  ___crtExitProcess(0xff);
}
}

// =================================================
// Function: __onexit
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

_func___cdecl_int * __cdecl __onexit(_func___cdecl_int *param_1)
{
{
  _func___cdecl_int *extraout_EAX;
  
  __lockexit();
  __onexit_nolock();
  FUN_004032c2();
  return extraout_EAX;
}
}

// =================================================
// Function: __onexit_nolock
// =================================================
void __cdecl __onexit_nolock(void)
{
{
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 *puVar4;
  
  __decode_pointer();
  __decode_pointer();
  if (extraout_EAX <= extraout_EAX_00) {
    uVar2 = ((int)extraout_EAX_00 - (int)extraout_EAX) + 4;
    if (3 < uVar2) {
      uVar1 = __msize(extraout_EAX);
      puVar4 = extraout_EAX_00;
      if (uVar1 < uVar2) {
        uVar2 = 0x800;
        if (uVar1 < 0x800) {
          uVar2 = uVar1;
        }
        if ((uVar2 + uVar1 < uVar1) ||
           (pvVar3 = __realloc_crt(extraout_EAX,uVar2 + uVar1), pvVar3 == (void *)0x0)) {
          if (uVar1 + 0x10 < uVar1) {
            return;
          }
          pvVar3 = __realloc_crt(extraout_EAX,uVar1 + 0x10);
          if (pvVar3 == (void *)0x0) {
            return;
          }
        }
        puVar4 = (undefined4 *)((int)pvVar3 + ((int)extraout_EAX_00 - (int)extraout_EAX >> 2) * 4);
        __encode_pointer();
        DAT_00d7afe8 = extraout_EAX_01;
      }
      __encode_pointer();
      *puVar4 = extraout_EAX_02;
      __encode_pointer();
      DAT_00d7afe4 = extraout_EAX_03;
    }
  }
  return;
}
}

// =================================================
// Function: __realloc_crt
// =================================================
void * __cdecl __realloc_crt(void *param_1,uint param_2)
{
{
  void *pvVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  do {
    pvVar1 = _realloc(param_1,param_2);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (param_2 == 0) {
      return (void *)0x0;
    }
    if (DAT_00d53dd8 == 0) {
      return (void *)0x0;
    }
    Sleep(dwMilliseconds);
    dwMilliseconds = dwMilliseconds + 1000;
    if (DAT_00d53dd8 < dwMilliseconds) {
      dwMilliseconds = 0xffffffff;
    }
  } while (dwMilliseconds != 0xffffffff);
  return (void *)0x0;
}
}

// =================================================
// Function: __set_error_mode
// =================================================
int __cdecl __set_error_mode(int param_1)
{
{
  int iVar1;
  int *piVar2;
  
  if (-1 < param_1) {
    if (param_1 < 3) {
      iVar1 = DAT_00d53764;
      DAT_00d53764 = param_1;
      return iVar1;
    }
    if (param_1 == 3) {
      return DAT_00d53764;
    }
  }
  piVar2 = __errno();
  *piVar2 = 0x16;
  __invalid_parameter();
  return -1;
}
}

// =================================================
// Function: __set_invalid_parameter_handler
// =================================================
_func___cdecl_void_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_uint_uint * __cdecl
__set_invalid_parameter_handler
          (_func___cdecl_void_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_uint_uint *param_1)
{
{
  _func___cdecl_void_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_uint_uint *extraout_EAX;
  undefined4 extraout_EAX_00;
  
  __decode_pointer();
  __encode_pointer();
  DAT_00d53dd0 = extraout_EAX_00;
  return extraout_EAX;
}
}

// =================================================
// Function: __set_purecall_handler
// =================================================
_func___cdecl_void * __cdecl __set_purecall_handler(_func___cdecl_void *param_1)
{
{
  _func___cdecl_void *extraout_EAX;
  undefined4 extraout_EAX_00;
  
  __decode_pointer();
  __encode_pointer();
  DAT_00d53dcc = extraout_EAX_00;
  return extraout_EAX;
}
}

// =================================================
// Function: __stricmp
// =================================================
int __cdecl __stricmp(char *param_1,char *param_2)
{
{
  int *piVar1;
  int iVar2;
  
  if (DAT_00d53f54 == 0) {
    if ((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) {
      iVar2 = ___ascii_stricmp(param_1,param_2);
      return iVar2;
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter();
    iVar2 = 0x7fffffff;
  }
  else {
    iVar2 = __stricmp_l(param_1,param_2,(localeinfo_struct *)0x0);
  }
  return iVar2;
}
}

// =================================================
// Function: __stricmp_l
// =================================================
int __cdecl __stricmp_l(char *param_1,char *param_2,localeinfo_struct *param_3)
{
{
  int *piVar1;
  int iVar2;
  int iVar3;
  localeinfo_struct *unaff_EBX;
  localeinfo_struct local_14;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate(&local_14,(_LocaleUpdate *)param_3,unaff_EBX);
  if (param_1 == (char *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter();
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
    iVar2 = 0x7fffffff;
  }
  else if (param_2 == (char *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter();
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
    iVar2 = 0x7fffffff;
  }
  else {
    if ((local_14.locinfo)->lc_category[0].wlocale == (wchar_t *)0x0) {
      iVar2 = ___ascii_stricmp(param_1,param_2);
    }
    else {
      do {
        iVar2 = __tolower_l((uint)(byte)*param_1,&local_14);
        param_1 = param_1 + 1;
        iVar3 = __tolower_l((uint)(byte)*param_2,&local_14);
        param_2 = param_2 + 1;
        if (iVar2 == 0) break;
      } while (iVar2 == iVar3);
      iVar2 = iVar2 - iVar3;
    }
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
  }
  return iVar2;
}
}

// =================================================
// Function: __strnicmp
// =================================================
int __cdecl __strnicmp(char *param_1,char *param_2,uint param_3)
{
{
  int *piVar1;
  int iVar2;
  
  if (DAT_00d53f54 == 0) {
    if (((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) && (param_3 < 0x80000000)) {
      iVar2 = ___ascii_strnicmp(param_1,param_2,param_3);
      return iVar2;
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter();
    iVar2 = 0x7fffffff;
  }
  else {
    iVar2 = __strnicmp_l(param_1,param_2,param_3,(localeinfo_struct *)0x0);
  }
  return iVar2;
}
}

// =================================================
// Function: __strnicmp_l
// =================================================
int __cdecl __strnicmp_l(char *param_1,char *param_2,uint param_3,localeinfo_struct *param_4)
{
{
  int *piVar1;
  int iVar2;
  int iVar3;
  localeinfo_struct *unaff_EDI;
  localeinfo_struct local_14;
  int local_c;
  char local_8;
  
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    _LocaleUpdate::_LocaleUpdate(&local_14,(_LocaleUpdate *)param_4,unaff_EDI);
    if ((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) {
      piVar1 = __errno();
      *piVar1 = 0x16;
      __invalid_parameter();
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
      iVar2 = 0x7fffffff;
    }
    else if (param_3 < 0x80000000) {
      if ((local_14.locinfo)->lc_category[0].wlocale == (wchar_t *)0x0) {
        iVar2 = ___ascii_strnicmp(param_1,param_2,param_3);
      }
      else {
        do {
          iVar2 = __tolower_l((uint)(byte)*param_1,&local_14);
          param_1 = param_1 + 1;
          iVar3 = __tolower_l((uint)(byte)*param_2,&local_14);
          param_2 = param_2 + 1;
          param_3 = param_3 - 1;
          if ((param_3 == 0) || (iVar2 == 0)) break;
        } while (iVar2 == iVar3);
        iVar2 = iVar2 - iVar3;
      }
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
    }
    else {
      piVar1 = __errno();
      *piVar1 = 0x16;
      __invalid_parameter();
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
      iVar2 = 0x7fffffff;
    }
  }
  return iVar2;
}
}

// =================================================
// Function: __time64
// =================================================
/* WARNING: Control flow encountered bad instruction data */

__time64_t __cdecl __time64(__time64_t *_Time)
{
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: __tolower_l
// =================================================
int __cdecl __tolower_l(int param_1,localeinfo_struct *param_2)
{
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  localeinfo_struct *unaff_ESI;
  localeinfo_struct local_1c;
  int local_14;
  char local_10;
  byte local_c;
  undefined1 local_b;
  char local_8;
  char local_7;
  undefined1 local_6;
  
  iVar1 = param_1;
  _LocaleUpdate::_LocaleUpdate(&local_1c,(_LocaleUpdate *)param_2,unaff_ESI);
  if ((uint)param_1 < 0x100) {
    if ((int)(local_1c.locinfo)->locale_name[3] < 2) {
      uVar2 = (byte)local_1c.locinfo[1].lc_category[0].locale[param_1 * 2] & 1;
    }
    else {
      uVar2 = __isctype_l(param_1,1,&local_1c);
    }
    if (uVar2 == 0) {
LAB_0040a690:
      if (local_10 == '\0') {
        return iVar1;
      }
      *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      return iVar1;
    }
    uVar2 = (uint)*(byte *)((int)local_1c.locinfo[1].lc_category[0].wlocale + param_1);
  }
  else {
    cVar5 = (char)param_1;
    if (((int)(local_1c.locinfo)->locale_name[3] < 2) ||
       (iVar3 = __isleadbyte_l(param_1 >> 8 & 0xff,&local_1c), iVar3 == 0)) {
      piVar4 = __errno();
      *piVar4 = 0x2a;
      local_7 = '\0';
      iVar3 = 1;
      local_8 = cVar5;
    }
    else {
      param_1._0_1_ = (char)((uint)param_1 >> 8);
      local_8 = (char)param_1;
      local_6 = 0;
      iVar3 = 2;
      local_7 = cVar5;
    }
    iVar3 = ___crtLCMapStringA(&local_1c,(local_1c.locinfo)->lc_category[0].wlocale,0x100,&local_8,
                               iVar3,(char *)&local_c,3,(local_1c.locinfo)->lc_codepage,1);
    if (iVar3 == 0) goto LAB_0040a690;
    if (iVar3 == 1) {
      uVar2 = (uint)local_c;
    }
    else {
      uVar2 = (uint)CONCAT11(local_c,local_b);
    }
  }
  if (local_10 != '\0') {
    *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
  }
  return uVar2;
}
}

// =================================================
// Function: __unlock
// =================================================
void __cdecl __unlock(int param_1)
{
{
  LeaveCriticalSection((&lpCriticalSection_00ccab60)[param_1 * 2]);
  return;
}
}

// =================================================
// Function: __unlockexit
// =================================================
void __cdecl __unlockexit(void)
{
{
  __unlock(8);
  return;
}
}

// =================================================
// Function: __updatetlocinfoEx_nolock
// =================================================
void __cdecl __updatetlocinfoEx_nolock(void)
{
{
  int *piVar1;
  undefined4 *in_EAX;
  int *unaff_EDI;
  
  if ((unaff_EDI != (int *)0x0) && (in_EAX != (undefined4 *)0x0)) {
    piVar1 = (int *)*in_EAX;
    if (piVar1 != unaff_EDI) {
      *in_EAX = unaff_EDI;
      ___addlocaleref();
      if (piVar1 != (int *)0x0) {
        ___removelocaleref();
        if ((*piVar1 == 0) && (piVar1 != (int *)&DAT_00ccaa70)) {
          ___freetlocinfo();
        }
      }
    }
    return;
  }
  return;
}
}

// =================================================
// Function: __use_encode_pointer
// =================================================
/* WARNING: Removing unreachable block (ram,0x00404dc5) */

void __cdecl __use_encode_pointer(void)
{
{
  int iVar1;
  HMODULE pHVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0;
  __get_winmajor();
  pHVar2 = GetModuleHandleA((LPCSTR)0x0);
  iVar1 = pHVar2[0xf].unused;
  pcVar5 = (char *)((int)&pHVar2[6].unused +
                   iVar1 + (uint)*(ushort *)((int)&pHVar2[5].unused + iVar1));
  if (*(short *)((int)&pHVar2[1].unused + iVar1 + 2) != 0) {
    do {
      iVar3 = _strcmp(".mixcrt",pcVar5);
      if (iVar3 == 0) {
        return;
      }
      uVar4 = uVar4 + 1;
      pcVar5 = pcVar5 + 0x28;
    } while (uVar4 < *(ushort *)((int)&pHVar2[1].unused + iVar1 + 2));
  }
  return;
}
}

// =================================================
// Function: __vsnprintf
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c3a90) overlaps instruction at (ram,0x009c3a8f)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009c3992) */
/* WARNING: Removing unreachable block (ram,0x009c39dd) */
/* WARNING: Removing unreachable block (ram,0x009c39a2) */
/* WARNING: Removing unreachable block (ram,0x009c39be) */
/* WARNING: Removing unreachable block (ram,0x009c39ca) */
/* WARNING: Removing unreachable block (ram,0x009c39f0) */
/* WARNING: Removing unreachable block (ram,0x009c39fe) */
/* WARNING: Removing unreachable block (ram,0x009c39ff) */
/* WARNING: Removing unreachable block (ram,0x009c3a3b) */
/* WARNING: Removing unreachable block (ram,0x009c3a5e) */
/* WARNING: Removing unreachable block (ram,0x009c37b8) */
/* WARNING: Removing unreachable block (ram,0x009c37ec) */
/* WARNING: Removing unreachable block (ram,0x009c381f) */
/* WARNING: Removing unreachable block (ram,0x009c386a) */
/* WARNING: Removing unreachable block (ram,0x009c389b) */
/* WARNING: Removing unreachable block (ram,0x009c38a2) */
/* WARNING: Removing unreachable block (ram,0x009c38dd) */
/* WARNING: Removing unreachable block (ram,0x009c38e3) */
/* WARNING: Removing unreachable block (ram,0x009c393a) */
/* WARNING: Removing unreachable block (ram,0x009c3962) */
/* WARNING: Removing unreachable block (ram,0x009c3a8e) */
/* WARNING: Removing unreachable block (ram,0x009c3a90) */
/* WARNING: Removing unreachable block (ram,0x009c3a60) */
/* WARNING: Removing unreachable block (ram,0x009c3ace) */
/* WARNING: Removing unreachable block (ram,0x009c3b03) */
/* WARNING: Removing unreachable block (ram,0x009c379b) */

int __cdecl __vsnprintf(char *param_1,uint param_2,char *param_3,char *param_4)
{
{
  byte bVar1;
  undefined4 in_EAX;
  char *pcVar2;
  char *pcVar3;
  int in_ECX;
  byte bVar6;
  char extraout_DH;
  int in_EDX;
  int unaff_EBX;
  byte *pbVar7;
  uint unaff_EBP;
  uint uVar8;
  int unaff_ESI;
  int unaff_EDI;
  byte in_AF;
  byte bVar4;
  undefined2 uVar5;
  
  bVar6 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  bVar1 = (byte)in_EAX + bVar6 * -6 & 0xf;
  bVar4 = 9 < bVar1 | bVar6;
  uVar8 = CONCAT31((int3)((uint)in_EAX >> 8),bVar1 + bVar4 * -6) & 0xffff000f;
  uVar5 = (undefined2)(uVar8 >> 0x10);
  bVar1 = (byte)uVar8;
  bVar4 = ((char)((uint)in_EAX >> 8) - bVar6) - bVar4;
  pcVar2 = (char *)CONCAT22(uVar5,CONCAT11(bVar4,bVar1));
  bVar6 = (byte)((uint)in_EDX >> 8);
  *pcVar2 = *pcVar2 + bVar6;
  pcVar3 = (char *)((int)pcVar2 * 2 + 0x30280000);
  *pcVar3 = *pcVar3 + (char)((uint)in_ECX >> 8);
  pbVar7 = (byte *)(unaff_EBX + 1);
  pcVar2[unaff_ESI + -0x73] = pcVar2[unaff_ESI + -0x73] ^ (byte)in_EDX;
  *(byte *)(in_EDX + -0x65cf51d0) = *(byte *)(in_EDX + -0x65cf51d0) ^ bVar4;
  uVar8 = unaff_EBP ^ *(uint *)(unaff_EBP + 0x33);
  if (uVar8 == 0) {
    *pbVar7 = *pbVar7 ^ 0x98;
  }
  else if ((int)(CONCAT31((int3)(CONCAT22(uVar5,CONCAT11(bVar4 ^ *(byte *)(in_ECX + -0x1ccd4cce),
                                                         bVar1)) >> 8),
                          bVar1 ^ *(byte *)CONCAT22((short)((uint)in_EDX >> 0x10),
                                                    CONCAT11(bVar6 ^ (byte)pbVar7,(byte)in_EDX))) +
                 0x9accafcdU ^ 0x356b3565) < 0) {
    pcVar3 = (char *)func_0x00db7821(unaff_EDI + 4);
    *pcVar3 = *pcVar3 + (char)pcVar3;
    *(char *)((int)(pcVar3 + 1) * 2) = *(char *)((int)(pcVar3 + 1) * 2) + extraout_DH;
    pcVar3 = (char *)(uVar8 + 0x31);
    *pcVar3 = *pcVar3 + (char)((uint)pbVar7 >> 8);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: __wcsicmp
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c1a14) overlaps instruction at (ram,0x009c1a13)
    */

int __cdecl __wcsicmp(wchar_t *param_1,wchar_t *param_2)
{
{
  char *pcVar1;
  undefined4 in_EAX;
  uint in_EDX;
  uint unaff_ESI;
  uint uVar2;
  
  pcVar1 = (char *)(CONCAT31((int3)((uint)in_EAX >> 8),0x53) * 2 + 0x30680000);
  *pcVar1 = *pcVar1 + (char)in_EDX;
  DAT_c7319730 = 0x53;
  uVar2 = unaff_ESI ^ in_EDX;
  *(undefined4 *)(uVar2 + 0x3a32d232) = *(undefined4 *)(uVar2 + 0x3a32d232);
  LOCK();
  *(uint *)uVar2 = uVar2;
  UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: _atexit
// =================================================
int __cdecl _atexit(_func___cdecl_void *param_1)
{
{
  _func___cdecl_int *p_Var1;
  
  p_Var1 = __onexit((_func___cdecl_int *)param_1);
  return (p_Var1 != (_func___cdecl_int *)0x0) - 1;
}
}

// =================================================
// Function: _atof
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c3a90) overlaps instruction at (ram,0x009c3a8f)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009c3992) */
/* WARNING: Removing unreachable block (ram,0x009c39dd) */
/* WARNING: Removing unreachable block (ram,0x009c39a2) */
/* WARNING: Removing unreachable block (ram,0x009c39be) */
/* WARNING: Removing unreachable block (ram,0x009c39ca) */
/* WARNING: Removing unreachable block (ram,0x009c39f0) */
/* WARNING: Removing unreachable block (ram,0x009c39fe) */
/* WARNING: Removing unreachable block (ram,0x009c39ff) */
/* WARNING: Removing unreachable block (ram,0x009c3a3b) */
/* WARNING: Removing unreachable block (ram,0x009c3a5e) */
/* WARNING: Removing unreachable block (ram,0x009c3a8e) */
/* WARNING: Removing unreachable block (ram,0x009c3a90) */
/* WARNING: Removing unreachable block (ram,0x009c3a60) */
/* WARNING: Removing unreachable block (ram,0x009c3ace) */
/* WARNING: Removing unreachable block (ram,0x009c3b03) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double __cdecl _atof(char *param_1)
{
{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 in_EAX;
  int *piVar4;
  int in_ECX;
  undefined4 in_EDX;
  char *unaff_EBX;
  byte *unaff_ESI;
  int iVar5;
  float10 fVar6;
  
  bVar2 = *unaff_ESI;
  piVar4 = (int *)CONCAT31((int3)((uint)in_EAX >> 8),0x3a);
  iVar5 = _DAT_80003dbf * 0x57;
  *(char *)((int)piVar4 * 2) = *(char *)((int)piVar4 * 2) + (char)((uint)in_EAX >> 8);
  *unaff_EBX = *unaff_EBX + ((byte)((uint)in_EDX >> 8) ^ bVar2);
  *(byte *)(in_ECX + 0x30) = *(byte *)(in_ECX + 0x30) ^ 0x3a;
  pbVar1 = (byte *)(iVar5 + 0x30);
  *pbVar1 = *pbVar1 ^ (byte)unaff_EBX;
  *piVar4 = *piVar4 << 1;
  pcVar3 = (code *)swi(1);
  fVar6 = (float10)(*pcVar3)();
  return (double)fVar6;
}
}

// =================================================
// Function: _atol
// =================================================
long __cdecl _atol(char *param_1)
{
{
  long lVar1;
  
  lVar1 = _strtol(param_1,(char **)0x0,10);
  return lVar1;
}
}

// =================================================
// Function: _eh_vector_constructor_iterator_
// =================================================
/* WARNING: Instruction at (ram,0x009c1869) overlaps instruction at (ram,0x009c1868)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009c1867) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
_eh_vector_constructor_iterator_
          (void *param_1,uint param_2,int param_3,_func___cdecl_void_void_ptr *param_4,
          _func___cdecl_void_void_ptr *param_5)
{
{
  byte *pbVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  char cVar9;
  uint in_EAX;
  uint uVar5;
  undefined3 uVar10;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint in_ECX;
  undefined2 uVar11;
  undefined4 *in_EDX;
  byte bVar12;
  undefined4 unaff_EBX;
  uint *puVar13;
  undefined1 *unaff_EBP;
  undefined1 *unaff_ESI;
  byte *pbVar14;
  int *unaff_EDI;
  int *piVar15;
  byte in_AF;
  bool bVar16;
  bool bVar17;
  undefined1 *local_8;
  
  uVar5 = in_EAX ^ 0x362c35f5;
  pbVar14 = unaff_ESI + 1;
  uVar11 = SUB42(in_EDX,0);
  out(*unaff_ESI,uVar11);
  uVar10 = (undefined3)(uVar5 >> 8);
  bVar12 = (byte)unaff_EBX;
  if ((POPCOUNT(uVar5 & 0xff) & 1U) == 0) {
    pbVar1 = (byte *)*unaff_EDI;
    bVar2 = 9 < ((byte)uVar5 & 0xf) | in_AF;
    uVar8 = CONCAT31(uVar10,(byte)uVar5 + bVar2 * '\x06') & 0xffffff0f;
    cVar9 = (char)(uVar5 >> 8) + bVar2;
    puVar13 = (uint *)CONCAT22((short)(uVar8 >> 0x10),CONCAT11(cVar9,(char)uVar8));
    bVar2 = 9 < (bVar12 & 0xf) | bVar2;
    uVar5 = CONCAT31((int3)((uint)unaff_EBX >> 8),bVar12 + bVar2 * '\x06') & 0xffffff0f;
    uVar4 = (undefined1)uVar5;
    puVar6 = (uint *)CONCAT22((short)(uVar5 >> 0x10),
                              CONCAT11((char)((uint)unaff_EBX >> 8) + bVar2,uVar4));
    *unaff_EDI = *unaff_EDI << ((byte)in_ECX & 0x1f);
    bVar16 = (in_ECX & 0x1f) != 0;
    in_ECX = in_ECX - 1;
    if (in_ECX != 0 && (!bVar16 && pbVar1 == pbVar14 || bVar16 && *unaff_EDI == 0)) {
      puVar6 = (uint *)(CONCAT31((int3)((uint)puVar6 >> 8),uVar4) & 0xffffff3e);
      local_8 = &stack0xfffffffc;
      goto code_r0x009c17e4;
    }
    *(char *)puVar6 = (char)*puVar6 + cVar9;
    puVar13 = (uint *)((int)puVar13 + 1);
    piVar15 = (int *)((uint)unaff_EDI ^ *puVar6);
    local_8 = &stack0xfffffffc;
    puVar3 = &stack0xfffffffc;
    if (!SBORROW4((int)puVar6,0x3d5e3d49)) goto code_r0x009c17e4;
LAB_009c1821:
    local_8 = puVar3;
    if (puVar6 == (uint *)0x3535356b) {
      bVar12 = DAT_3591358c & (byte)((uint)in_EDX >> 8);
      bVar17 = (char)bVar12 < '\0';
      bVar16 = bVar12 == 0;
      uVar8 = 0;
      _DAT_3db73db0 = piVar15;
      goto LAB_009c183c;
    }
    uVar4 = in(uVar11);
    *(undefined1 *)*in_EDX = uVar4;
  }
  else {
    puVar6 = (uint *)CONCAT31(uVar10,0x3d);
    puVar13 = (uint *)CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(0x3d,bVar12));
code_r0x009c17e4:
    LOCK();
    UNLOCK();
    unaff_EBP = &DAT_f33dc13d;
    iVar7 = CONCAT31((int3)((uint)puVar6 >> 8),(byte)puVar6 - 0x3e);
    uVar5 = iVar7 - 1;
    bVar17 = (int)uVar5 < 0;
    bVar16 = uVar5 == 0;
    if ((byte)puVar6 < 0x3e) {
      uVar8 = in_ECX ^ 0x3660365c;
      bVar17 = (int)uVar8 < 0;
      bVar16 = uVar8 == 0;
      in_ECX = uVar5;
    }
    else {
      uVar8 = uVar5;
      if ((bVar16) && (0 < iVar7)) {
        *(char *)(iVar7 + 0x3195ffff) = *(char *)(iVar7 + 0x3195ffff) + (char)in_ECX;
        *puVar13 = *puVar13 ^ (uint)puVar13;
        puVar6 = (uint *)&DAT_0000000b;
        unaff_EBP = _DAT_f33dc13d;
        piVar15 = _DAT_3db73db0;
        puVar3 = local_8;
        goto LAB_009c1821;
      }
    }
LAB_009c183c:
    *(uint *)(local_8 + -4) = uVar8;
    *(uint *)(local_8 + -8) = in_ECX;
    *(undefined4 **)(local_8 + -0xc) = in_EDX;
    *(uint **)(local_8 + -0x10) = puVar13;
    *(undefined1 **)(local_8 + -0x14) = local_8;
    *(undefined1 **)(local_8 + -0x18) = unaff_EBP;
    *(byte **)(local_8 + -0x1c) = pbVar14;
    *(int **)(local_8 + -0x20) = _DAT_3db73db0;
    *(undefined4 *)(local_8 + -0x24) = 0x70366c36;
    if (!bVar16) {
      if (bVar17) goto code_r0x009c1886;
      *_DAT_3db73db0 = *_DAT_3db73db0 - (int)pbVar14;
      *(uint *)(local_8 + -0x28) = uVar8;
      *(uint *)(local_8 + -0x2c) = in_ECX;
      *(undefined4 **)(local_8 + -0x30) = in_EDX;
      *(uint **)(local_8 + -0x34) = puVar13;
      *(undefined1 **)(local_8 + -0x38) = local_8 + -0x24;
      *(undefined1 **)(local_8 + -0x3c) = unaff_EBP;
      *(int **)(local_8 + -0x44) = _DAT_3db73db0;
      pbVar14 = (byte *)*_DAT_3db73db0;
      uVar4 = in(uVar11);
      *(undefined1 *)_DAT_3db73db0 = uVar4;
      puVar13 = (uint *)0xff37f437;
    }
  }
  *pbVar14 = *pbVar14 ^ (byte)((uint)puVar13 >> 8);
code_r0x009c1886:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
}

// =================================================
// Function: _eh_vector_destructor_iterator_
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl
_eh_vector_destructor_iterator_
          (void *param_1,uint param_2,int param_3,_func___cdecl_void_void_ptr *param_4)
{
{
  void *in_stack_ffffffd0;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffd0);
  }
  FUN_0040318c();
  return;
}
}

// =================================================
// Function: _exit
// =================================================
void __cdecl _exit(int param_1)
{
{
  doexit();
  return;
}
}

// =================================================
// Function: _free
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl _free(void *param_1)
{
{
  int iVar1;
  BOOL BVar2;
  int *piVar3;
  DWORD DVar4;
  
  if (param_1 != (void *)0x0) {
    if (DAT_00d7aec0 == 3) {
      __lock(4);
      iVar1 = thunk____sbh_find_block(param_1);
      if (iVar1 != 0) {
        ___sbh_free_block();
      }
      FUN_00405bac();
      if (iVar1 != 0) {
        return;
      }
    }
    BVar2 = HeapFree(hHeap_00d53f34,0,param_1);
    if (BVar2 == 0) {
      piVar3 = __errno();
      DVar4 = GetLastError();
      iVar1 = __get_errno_from_oserr(DVar4);
      *piVar3 = iVar1;
    }
  }
  return;
}
}

// =================================================
// Function: _isalpha
// =================================================
int __cdecl _isalpha(int param_1)
{
{
  int iVar1;
  
  if (DAT_00d53f54 == 0) {
    return *(ushort *)(PTR_DAT_00ccab38 + param_1 * 2) & 0x103;
  }
  iVar1 = __isalpha_l(param_1,(localeinfo_struct *)0x0);
  return iVar1;
}
}

// =================================================
// Function: _isspace
// =================================================
int __cdecl _isspace(int param_1)
{
{
  int iVar1;
  
  if (DAT_00d53f54 == 0) {
    return (byte)PTR_DAT_00ccab38[param_1 * 2] & 8;
  }
  iVar1 = __isspace_l(param_1,(localeinfo_struct *)0x0);
  return iVar1;
}
}

// =================================================
// Function: _malloc
// =================================================
void * __cdecl _malloc(uint param_1)
{
{
  LPVOID extraout_EAX;
  LPVOID pvVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  if (0xffffffe0 < param_1) {
    __callnewh(param_1);
    piVar3 = __errno();
    *piVar3 = 0xc;
    return (void *)0x0;
  }
  do {
    if (hHeap_00d53f34 == (HANDLE)0x0) {
      __FF_MSGBANNER();
      __NMSG_WRITE(0x1e);
                    /* WARNING: Subroutine does not return */
      ___crtExitProcess(0xff);
    }
    if (DAT_00d7aec0 == 1) {
      uVar4 = param_1;
      if (param_1 == 0) {
        uVar4 = 1;
      }
LAB_00407a7e:
      pvVar1 = HeapAlloc(hHeap_00d53f34,0,uVar4);
    }
    else if ((DAT_00d7aec0 != 3) ||
            (_V6_HeapAlloc(), pvVar1 = extraout_EAX, extraout_EAX == (LPVOID)0x0)) {
      uVar4 = param_1;
      if (param_1 == 0) {
        uVar4 = 1;
      }
      uVar4 = uVar4 + 0xf & 0xfffffff0;
      goto LAB_00407a7e;
    }
    if (pvVar1 != (LPVOID)0x0) {
      return pvVar1;
    }
    if (DAT_00d54140 == 0) {
      piVar3 = __errno();
      *piVar3 = 0xc;
      goto LAB_00407aac;
    }
    iVar2 = __callnewh(param_1);
    if (iVar2 == 0) {
LAB_00407aac:
      piVar3 = __errno();
      *piVar3 = 0xc;
      return (void *)0x0;
    }
  } while( true );
}
}

// =================================================
// Function: _memcpy
// =================================================
void * __cdecl _memcpy(void *param_1,void *param_2,uint param_3)
{
{
  void *extraout_EAX;
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (void *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_0040c913_caseD_2;
        case 3:
          goto switchD_0040c913_caseD_3;
        }
        goto switchD_0040c913_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_0040c913_caseD_0;
      case 1:
        goto switchD_0040c913_caseD_1;
      case 2:
        goto switchD_0040c913_caseD_2;
      case 3:
        goto switchD_0040c913_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_0040c913_caseD_2;
            case 3:
              goto switchD_0040c913_caseD_3;
            }
            goto switchD_0040c913_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_0040c913_caseD_2;
            case 3:
              goto switchD_0040c913_caseD_3;
            }
            goto switchD_0040c913_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_0040c913_caseD_2;
            case 3:
              goto switchD_0040c913_caseD_3;
            }
            goto switchD_0040c913_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_0040c913_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_0040c913_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_0040c913_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_0040c913_caseD_0:
    return param_1;
  }
  if (((0xff < param_3) && (DAT_00d7affc != 0)) && (((uint)param_1 & 0xf) == ((uint)param_2 & 0xf)))
  {
    __VEC_memcpy();
    return extraout_EAX;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *(undefined4 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 4);
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_0040c78c_caseD_2;
      case 3:
        goto switchD_0040c78c_caseD_3;
      }
      goto switchD_0040c78c_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_0040c78c_caseD_0;
    case 1:
      goto switchD_0040c78c_caseD_1;
    case 2:
      goto switchD_0040c78c_caseD_2;
    case 3:
      goto switchD_0040c78c_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (void *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)param_2;
            param_2 = (undefined4 *)((int)param_2 + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_0040c78c_caseD_2;
          case 3:
            goto switchD_0040c78c_caseD_3;
          }
          goto switchD_0040c78c_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (void *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)param_2;
            param_2 = (undefined4 *)((int)param_2 + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_0040c78c_caseD_2;
          case 3:
            goto switchD_0040c78c_caseD_3;
          }
          goto switchD_0040c78c_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (void *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)param_2;
            param_2 = (undefined4 *)((int)param_2 + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_0040c78c_caseD_2;
          case 3:
            goto switchD_0040c78c_caseD_3;
          }
          goto switchD_0040c78c_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = *(undefined4 *)((int)param_2 + (uVar1 - 7) * 4);
  case 6:
    puVar3[uVar1 - 6] = *(undefined4 *)((int)param_2 + (uVar1 - 6) * 4);
  case 5:
    puVar3[uVar1 - 5] = *(undefined4 *)((int)param_2 + (uVar1 - 5) * 4);
  case 4:
    puVar3[uVar1 - 4] = *(undefined4 *)((int)param_2 + (uVar1 - 4) * 4);
  case 3:
    puVar3[uVar1 - 3] = *(undefined4 *)((int)param_2 + (uVar1 - 3) * 4);
  case 2:
    puVar3[uVar1 - 2] = *(undefined4 *)((int)param_2 + (uVar1 - 2) * 4);
  case 1:
    puVar3[uVar1 - 1] = *(undefined4 *)((int)param_2 + (uVar1 - 1) * 4);
    param_2 = (void *)((int)param_2 + uVar1 * 4);
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_0040c78c_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_0040c78c_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_0040c78c_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_0040c78c_caseD_0:
  return param_1;
}
}

// =================================================
// Function: _memmove
// =================================================
void * __cdecl _memmove(void *param_1,void *param_2,uint param_3)
{
{
  void *extraout_EAX;
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (void *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_0040aaa3_caseD_2;
        case 3:
          goto switchD_0040aaa3_caseD_3;
        }
        goto switchD_0040aaa3_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_0040aaa3_caseD_0;
      case 1:
        goto switchD_0040aaa3_caseD_1;
      case 2:
        goto switchD_0040aaa3_caseD_2;
      case 3:
        goto switchD_0040aaa3_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_0040aaa3_caseD_2;
            case 3:
              goto switchD_0040aaa3_caseD_3;
            }
            goto switchD_0040aaa3_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_0040aaa3_caseD_2;
            case 3:
              goto switchD_0040aaa3_caseD_3;
            }
            goto switchD_0040aaa3_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_0040aaa3_caseD_2;
            case 3:
              goto switchD_0040aaa3_caseD_3;
            }
            goto switchD_0040aaa3_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_0040aaa3_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_0040aaa3_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_0040aaa3_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_0040aaa3_caseD_0:
    return param_1;
  }
  if (((0xff < param_3) && (DAT_00d7affc != 0)) && (((uint)param_1 & 0xf) == ((uint)param_2 & 0xf)))
  {
    __VEC_memcpy();
    return extraout_EAX;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *(undefined4 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 4);
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_0040a91c_caseD_2;
      case 3:
        goto switchD_0040a91c_caseD_3;
      }
      goto switchD_0040a91c_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_0040a91c_caseD_0;
    case 1:
      goto switchD_0040a91c_caseD_1;
    case 2:
      goto switchD_0040a91c_caseD_2;
    case 3:
      goto switchD_0040a91c_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (void *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)param_2;
            param_2 = (undefined4 *)((int)param_2 + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_0040a91c_caseD_2;
          case 3:
            goto switchD_0040a91c_caseD_3;
          }
          goto switchD_0040a91c_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (void *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)param_2;
            param_2 = (undefined4 *)((int)param_2 + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_0040a91c_caseD_2;
          case 3:
            goto switchD_0040a91c_caseD_3;
          }
          goto switchD_0040a91c_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (void *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)param_2;
            param_2 = (undefined4 *)((int)param_2 + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_0040a91c_caseD_2;
          case 3:
            goto switchD_0040a91c_caseD_3;
          }
          goto switchD_0040a91c_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = *(undefined4 *)((int)param_2 + (uVar1 - 7) * 4);
  case 6:
    puVar3[uVar1 - 6] = *(undefined4 *)((int)param_2 + (uVar1 - 6) * 4);
  case 5:
    puVar3[uVar1 - 5] = *(undefined4 *)((int)param_2 + (uVar1 - 5) * 4);
  case 4:
    puVar3[uVar1 - 4] = *(undefined4 *)((int)param_2 + (uVar1 - 4) * 4);
  case 3:
    puVar3[uVar1 - 3] = *(undefined4 *)((int)param_2 + (uVar1 - 3) * 4);
  case 2:
    puVar3[uVar1 - 2] = *(undefined4 *)((int)param_2 + (uVar1 - 2) * 4);
  case 1:
    puVar3[uVar1 - 1] = *(undefined4 *)((int)param_2 + (uVar1 - 1) * 4);
    param_2 = (void *)((int)param_2 + uVar1 * 4);
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_0040a91c_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_0040a91c_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_0040a91c_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_0040a91c_caseD_0:
  return param_1;
}
}

// =================================================
// Function: _memset
// =================================================
void * __cdecl _memset(void *param_1,int param_2,uint param_3)
{
{
  uint uVar1;
  void *extraout_EAX;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_3 == 0) {
    return param_1;
  }
  uVar1 = param_2 & 0xff;
  if ((((char)param_2 == '\0') && (0xff < param_3)) && (DAT_00d7affc != 0)) {
    __VEC_memzero();
    return extraout_EAX;
  }
  puVar4 = param_1;
  if (3 < param_3) {
    uVar2 = -(int)param_1 & 3;
    uVar3 = param_3;
    if (uVar2 != 0) {
      uVar3 = param_3 - uVar2;
      do {
        *(char *)puVar4 = (char)param_2;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    param_3 = uVar3 & 3;
    uVar3 = uVar3 >> 2;
    if (uVar3 != 0) {
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (param_3 == 0) {
        return param_1;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    param_3 = param_3 - 1;
  } while (param_3 != 0);
  return param_1;
}
}

// =================================================
// Function: _modf
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c2889) overlaps instruction at (ram,0x009c2888)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double __cdecl _modf(double param_1,double *param_2)
{
{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  int in_EAX;
  uint uVar9;
  undefined4 in_ECX;
  undefined2 in_DX;
  uint *unaff_EBX;
  uint uVar10;
  uint *puVar11;
  uint unaff_EBP;
  uint unaff_ESI;
  int unaff_EDI;
  undefined2 in_CS;
  byte in_AF;
  uint uVar12;
  uint auStack_10 [3];
  undefined4 uStack_4;
  uint uVar7;
  uint *puVar8;
  
  pbVar2 = _DAT_3dde3dd6;
  uStack_4 = 0x703d6c3d;
  if (in_EAX < 0x3d783d74) {
    unaff_EBP = unaff_EBP ^ *(uint *)(unaff_EDI + -0x36cc3ccd);
  }
  LOCK();
  UNLOCK();
  bVar3 = (byte)in_EAX;
  out(0x3d,bVar3);
  out(in_DX,bVar3);
  bVar1 = 9 < (bVar3 & 0xf) | in_AF;
  bVar4 = bVar3 + bVar1 * -6 & 0xf;
  bVar3 = 9 < bVar4 | bVar1;
  uVar7 = CONCAT31((int3)((uint)in_EAX >> 8),bVar4 + bVar3 * -6) & 0xffff000f;
  cVar5 = (char)uVar7;
  cVar6 = cVar5 * '\x02' + (char)((uint)unaff_EBX >> 8);
  puVar8 = (uint *)CONCAT31((int3)(CONCAT22((short)(uVar7 >> 0x10),
                                            CONCAT11(((char)((uint)in_EAX >> 8) - bVar1) - bVar3,
                                                     cVar5)) >> 8),cVar6);
  _DAT_3dde3dd6 = (byte *)unaff_EDI;
  *(char *)puVar8 = (char)*puVar8 + cVar6;
  *(char *)(unaff_EBP + 0xf330dc30) = *(char *)(unaff_EBP + 0xf330dc30) + (char)((uint)in_ECX >> 8);
  *pbVar2 = *pbVar2 ^ (byte)in_DX;
  *puVar8 = *puVar8 ^ (uint)auStack_10;
  *(uint *)(unaff_ESI + 0xec32d432) = *(uint *)(unaff_ESI + 0xec32d432) ^ unaff_ESI;
  uVar7 = *unaff_EBX;
  uVar10 = ((uint)auStack_10 ^ *unaff_EBX) + 4 ^ *(uint *)((int)unaff_EBX + 0x33);
  *(undefined2 *)(uVar10 - 4) = in_CS;
  puVar11 = (uint *)(uVar10 - 8);
  *(undefined4 *)(uVar10 - 8) = 0x9c288f;
  auStack_10[0] = unaff_EBP;
  uVar9 = func_0xc333af33();
  uVar12 = *puVar11;
  *(undefined4 *)pbVar2 = *(undefined4 *)(unaff_ESI ^ uVar7 ^ *unaff_EBX);
  *(uint *)(pbVar2 + (uint)((uVar12 & 0x400) != 0) * -8 + 4) = uVar9 ^ 0x366135f7;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: _rand
// =================================================
/* WARNING: Instruction at (ram,0x009c233b) overlaps instruction at (ram,0x009c233a)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl _rand(void)
{
{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  short sVar4;
  code *pcVar5;
  ushort uVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  char cVar15;
  undefined4 in_EAX;
  char *pcVar10;
  undefined4 uVar11;
  int iVar12;
  ushort *puVar13;
  uint uVar14;
  int in_ECX;
  uint uVar16;
  int *piVar17;
  undefined1 uVar18;
  undefined4 in_EDX;
  byte *pbVar19;
  undefined2 uVar20;
  uint *unaff_EBX;
  byte *unaff_EBP;
  byte *unaff_ESI;
  uint *unaff_EDI;
  uint *puVar21;
  byte in_AF;
  byte bVar22;
  
  bVar22 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar16 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar22 * -6) & 0xffffff0f;
  bVar7 = (byte)uVar16;
  pcVar10 = (char *)CONCAT22((short)(uVar16 >> 0x10),
                             CONCAT11((char)((uint)in_EAX >> 8) - bVar22,bVar7));
  *pcVar10 = *pcVar10 + bVar7;
  *pcVar10 = *pcVar10 + bVar7;
  bVar8 = (byte)((uint)in_EDX >> 8);
  *(char *)((int)pcVar10 * 2) = *(char *)((int)pcVar10 * 2) + bVar8;
  *(char *)(in_ECX + -0x2ecf3cd0) = *(char *)(in_ECX + -0x2ecf3cd0) + bVar8;
  *(byte *)unaff_EBX = (byte)*unaff_EBX ^ bVar8;
  *(uint *)(in_ECX + 0x31) = *(uint *)(in_ECX + 0x31) ^ (uint)pcVar10;
  *unaff_EBX = *unaff_EBX ^ (uint)unaff_ESI;
  bVar7 = bVar7 ^ pcVar10[0x32] ^ *(byte *)((int)unaff_EBX + (int)unaff_ESI);
  pbVar19 = (byte *)CONCAT31((int3)((uint)pcVar10 >> 8),bVar7);
  uVar16 = in_ECX - 1;
  bVar8 = (byte)unaff_EBP;
  cVar15 = (char)((uint)unaff_EBP >> 8);
  if (uVar16 == 0 || bVar7 != 0) {
    unaff_EDI = unaff_EDI + 1;
    unaff_ESI = unaff_ESI + 4;
    piVar17 = (int *)CONCAT31((int3)(uVar16 >> 8),0x36);
    uVar11 = in(0x36);
    bVar7 = (byte)uVar11;
    out((short)unaff_EBP,bVar7);
    iVar12 = CONCAT22((short)((uint)unaff_EBP >> 0x10),CONCAT11(cVar15 + (char)*unaff_EDI,bVar8));
    *unaff_EDI = *unaff_EDI & (uint)unaff_ESI;
    pbVar19 = (byte *)(iVar12 + 1);
    bVar22 = 9 < (bVar7 & 0xf) | bVar22;
    uVar16 = CONCAT31((int3)((uint)uVar11 >> 8),bVar7 + bVar22 * '\x06') & 0xffffff0f;
    puVar13 = (ushort *)
              CONCAT22((short)(uVar16 >> 0x10),
                       CONCAT11((char)((uint)uVar11 >> 8) + bVar22,(char)uVar16));
    *(ushort *)unaff_EDI =
         (short)*unaff_EDI + (ushort)bVar22 * (((ushort)unaff_ESI & 3) - ((ushort)*unaff_EDI & 3));
    if (!SCARRY4(iVar12,1)) {
      pcVar5 = (code *)swi(1);
      iVar12 = (*pcVar5)();
      return iVar12;
    }
LAB_009c22f7:
    pcVar10 = (char *)((int)puVar13 * 2 + 0x30010000);
    *pcVar10 = *pcVar10 + (char)unaff_EBX;
    bVar7 = (byte)((uint)pbVar19 >> 8);
    uVar6 = *puVar13;
    uVar20 = (undefined2)((uint)pbVar19 >> 0x10);
    uVar18 = SUB41(pbVar19,0);
    pbVar19 = (byte *)CONCAT22(uVar20,CONCAT11(bVar7 - (byte)*puVar13,uVar18));
    sVar4 = ((ushort)unaff_ESI & 3) - (*puVar13 & 3);
    *puVar13 = *puVar13 + (ushort)(bVar7 < (byte)*puVar13) * sVar4;
    if (!SBORROW1(bVar7,(byte)uVar6)) goto LAB_009c2334;
    pbVar19 = (byte *)CONCAT22(uVar20,CONCAT11((byte)*puVar13,uVar18));
    *piVar17 = *piVar17 << ((byte)piVar17 & 0x1f);
    bVar2 = ((uint)piVar17 & 0x1f) == 0;
    uVar16 = (int)piVar17 - 1;
    if (uVar16 == 0 || (bVar2 && 0 < sVar4 || !bVar2 && *piVar17 == 0)) goto code_r0x009c230a;
    bVar7 = 9 < (byte)puVar13 | bVar22;
    uVar14 = CONCAT31((int3)((uint)puVar13 >> 8),(byte)puVar13 + bVar7 * '\x06') & 0xffffff0f;
    pcVar10 = (char *)CONCAT22((short)(uVar14 >> 0x10),
                               CONCAT11((char)((uint)puVar13 >> 8) + bVar7,(char)uVar14));
    puVar21 = unaff_EDI;
code_r0x009c233c:
    _DAT_3c393834 = 0x3c393838;
    unaff_EDI = (uint *)((int)puVar21 + 1);
    cVar15 = in((short)pbVar19);
    *(char *)puVar21 = cVar15;
    pbVar1 = *(byte **)(pcVar10 + 0x39);
    if (pbVar1 == unaff_ESI) goto LAB_009c2397;
    if (-1 < (int)pbVar1 - (int)unaff_ESI) {
      if ((int)pbVar1 < (int)unaff_ESI) goto LAB_009c239b;
      goto LAB_009c2373;
    }
  }
  else {
    if (unaff_EBP < *(byte **)(in_ECX + 0x3b)) {
      puVar13 = (ushort *)((int)(short)pbVar19 ^ *(uint *)(unaff_ESI + (int)&stack0x00000000));
      pbVar19 = unaff_EBP;
code_r0x009c230a:
      unaff_EBX = (uint *)CONCAT22((short)((uint)unaff_EBX >> 0x10),
                                   CONCAT11((byte)((uint)unaff_EBX >> 8) ^ (byte)uVar16,
                                            (char)unaff_EBX));
      piVar17 = (int *)(uVar16 ^ *(uint *)((int)puVar13 + -0x6fcc73cd));
      pbVar19 = (byte *)(CONCAT31((int3)((uint)pbVar19 >> 8),
                                  (byte)pbVar19 ^ ((byte *)((int)unaff_EBX + 0x5b))[(int)unaff_ESI])
                        ^ *(uint *)((int)(unaff_EBX + 0xd010ce6) + (int)unaff_ESI));
      (&stack0x00000000)[(int)piVar17] =
           (&stack0x00000000)[(int)piVar17] | (byte)((uint)pbVar19 >> 8);
      uVar16 = (uint)puVar13 ^ 0x2b;
    }
    else {
      bVar3 = 9 < (bVar8 & 0xf) | bVar22;
      bVar8 = bVar8 + bVar3 * -6 & 0xf;
      bVar22 = 9 < bVar8 | bVar3;
      uVar16 = CONCAT31((int3)((uint)unaff_EBP >> 8),bVar8 + bVar22 * -6) & 0xffff000f;
      bVar8 = (byte)uVar16;
      cVar15 = (cVar15 - bVar3) - bVar22;
      uVar16 = CONCAT22((short)(uVar16 >> 0x10),CONCAT11(cVar15,bVar8));
      piVar17 = (int *)(in_ECX + -2);
      if (piVar17 == (int *)0x0 || *unaff_ESI != 0x53) {
        bVar22 = 9 < bVar8 | bVar22;
        uVar16 = CONCAT31((int3)(uVar16 >> 8),bVar8 + bVar22 * -6) & 0xffffff0f;
        cVar9 = (char)uVar16;
        puVar13 = (ushort *)CONCAT22((short)(uVar16 >> 0x10),CONCAT11(cVar15 - bVar22,cVar9));
        *(byte *)puVar13 = (byte)*puVar13 + cVar9;
        *(byte *)puVar13 = (byte)*puVar13 + bVar7;
        goto LAB_009c22f7;
      }
    }
    puVar13 = (ushort *)(uVar16 ^ 0x3673351a);
LAB_009c2334:
    *unaff_ESI = *unaff_ESI ^ 0x33;
    bVar22 = 9 < ((byte)puVar13 & 0xf) | bVar22;
    bVar8 = (byte)puVar13 + bVar22 * '\x06' & 0xf;
    bVar7 = 9 < bVar8 | bVar22;
    uVar16 = CONCAT31((int3)((uint)puVar13 >> 8),bVar8 + bVar7 * '\x06') & 0xffff000f;
    pcVar10 = (char *)CONCAT22((short)(uVar16 >> 0x10),
                               CONCAT11((char)((uint)puVar13 >> 8) + bVar22 + bVar7,(char)uVar16));
    uVar16 = (int)piVar17 - 1;
    puVar21 = unaff_EDI;
    if (uVar16 == 0 || &stack0x00000000 == (undefined1 *)0xffffffff) goto code_r0x009c233c;
LAB_009c2373:
    bVar22 = *unaff_ESI;
    *(int *)unaff_ESI = *(int *)unaff_ESI >> 0x1a;
    unaff_EBX = (uint *)CONCAT31(CONCAT21((short)((uint)unaff_EBX >> 0x10),bVar22),0x3f);
    *(char *)unaff_EDI = (char)*unaff_EDI;
    *unaff_EBP = *unaff_EBP & (byte)pbVar19;
    *pcVar10 = *pcVar10 + (char)pcVar10;
LAB_009c2397:
    uVar16 = CONCAT31((int3)(uVar16 >> 8),(char)uVar16 + (char)((uint)pcVar10 >> 8));
  }
  pbVar19 = (byte *)CONCAT31((int3)((uint)pbVar19 >> 8),(byte)pbVar19 ^ (byte)((uint)unaff_EBX >> 8)
                            );
LAB_009c239b:
  *pbVar19 = *pbVar19 ^ (byte)((uint)pcVar10 >> 8);
  *unaff_EBX = *unaff_EBX ^ (uint)pcVar10;
  *(byte *)unaff_EDI =
       (char)*unaff_EDI +
       (((byte)((uint)pbVar19 >> 8) ^ *(byte *)((int)unaff_EBX + 0x4133c033) | *unaff_ESI) ^
       *unaff_ESI) + CARRY4((uint)unaff_ESI,*unaff_EDI);
  bVar7 = 9 < ((byte)uVar16 & 0xf) | bVar7;
  bVar8 = (byte)uVar16 + bVar7 * '\x06' & 0xf;
  bVar22 = 9 < bVar8 | bVar7;
  uVar14 = CONCAT31((int3)(uVar16 >> 8),bVar8 + bVar22 * '\x06') & 0xffff000f;
  return CONCAT22((short)(uVar14 >> 0x10),
                  CONCAT11((char)(uVar16 >> 8) + bVar7 + bVar22,(char)uVar14));
}
}

// =================================================
// Function: _realloc
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void * __cdecl _realloc(void *param_1,uint param_2)
{
{
  void *pvVar1;
  int extraout_EAX;
  void *extraout_EAX_00;
  uint uVar2;
  int iVar3;
  int *piVar4;
  DWORD DVar5;
  LPVOID pvVar6;
  int local_24;
  void *local_20;
  
  if (param_1 == (void *)0x0) {
    pvVar1 = _malloc(param_2);
    return pvVar1;
  }
  if (param_2 == 0) {
    _free(param_1);
    return (void *)0x0;
  }
  if (DAT_00d7aec0 == 3) {
    do {
      local_20 = (void *)0x0;
      if (0xffffffe0 < param_2) goto LAB_0040d4e1;
      __lock(4);
      local_24 = thunk____sbh_find_block(param_1);
      if (local_24 != 0) {
        if (param_2 <= DAT_00d7aeac) {
          ___sbh_resize_block();
          if (extraout_EAX == 0) {
            ___sbh_alloc_block();
            local_20 = extraout_EAX_00;
            if (extraout_EAX_00 != (void *)0x0) {
              uVar2 = *(int *)((int)param_1 + -4) - 1;
              if (param_2 <= uVar2) {
                uVar2 = param_2;
              }
              _memcpy(extraout_EAX_00,param_1,uVar2);
              local_24 = thunk____sbh_find_block(param_1);
              ___sbh_free_block();
            }
          }
          else {
            local_20 = param_1;
          }
        }
        if (local_20 == (void *)0x0) {
          if (param_2 == 0) {
            param_2 = 1;
          }
          param_2 = param_2 + 0xf & 0xfffffff0;
          local_20 = HeapAlloc(hHeap_00d53f34,0,param_2);
          if (local_20 != (LPVOID)0x0) {
            uVar2 = *(int *)((int)param_1 + -4) - 1;
            if (param_2 <= uVar2) {
              uVar2 = param_2;
            }
            _memcpy(local_20,param_1,uVar2);
            ___sbh_free_block();
          }
        }
      }
      FUN_0040d44c();
      if (local_24 == 0) {
        if (param_2 == 0) {
          param_2 = 1;
        }
        param_2 = param_2 + 0xf & 0xfffffff0;
        local_20 = HeapReAlloc(hHeap_00d53f34,0,param_1,param_2);
      }
      if (local_20 != (void *)0x0) {
        return local_20;
      }
      if (DAT_00d54140 == 0) {
        piVar4 = __errno();
        if (local_24 != 0) {
          *piVar4 = 0xc;
          return (void *)0x0;
        }
        goto LAB_0040d50e;
      }
      iVar3 = __callnewh(param_2);
    } while (iVar3 != 0);
    piVar4 = __errno();
    if (local_24 != 0) goto LAB_0040d4ed;
  }
  else {
    do {
      if (0xffffffe0 < param_2) goto LAB_0040d4e1;
      if (param_2 == 0) {
        param_2 = 1;
      }
      pvVar6 = HeapReAlloc(hHeap_00d53f34,0,param_1,param_2);
      if (pvVar6 != (LPVOID)0x0) {
        return pvVar6;
      }
      if (DAT_00d54140 == 0) {
        piVar4 = __errno();
LAB_0040d50e:
        DVar5 = GetLastError();
        iVar3 = __get_errno_from_oserr(DVar5);
        *piVar4 = iVar3;
        return (void *)0x0;
      }
      iVar3 = __callnewh(param_2);
    } while (iVar3 != 0);
    piVar4 = __errno();
  }
  DVar5 = GetLastError();
  iVar3 = __get_errno_from_oserr(DVar5);
  *piVar4 = iVar3;
  return (void *)0x0;
LAB_0040d4e1:
  __callnewh(param_2);
  piVar4 = __errno();
LAB_0040d4ed:
  *piVar4 = 0xc;
  return (void *)0x0;
}
}

// =================================================
// Function: _set_new_handler
// =================================================
_func___cdecl_int_uint * __cdecl _set_new_handler(_func___cdecl_int_uint *param_1)
{
{
  _func___cdecl_int_uint *extraout_EAX;
  undefined4 extraout_EAX_00;
  
  __lock(4);
  __decode_pointer();
  __encode_pointer();
  DAT_00d53dd4 = extraout_EAX_00;
  __unlock(4);
  return extraout_EAX;
}
}

// =================================================
// Function: _set_se_translator
// =================================================
/* WARNING: Instruction at (ram,0x009c42c8) overlaps instruction at (ram,0x009c42c3)
    */

_func___cdecl_void_uint__EXCEPTION_POINTERS_ptr * __cdecl
_set_se_translator(_func___cdecl_void_uint__EXCEPTION_POINTERS_ptr *param_1)
{
{
  char *pcVar1;
  ushort uVar2;
  byte bVar3;
  code *pcVar4;
  ushort uVar5;
  byte bVar6;
  undefined1 uVar7;
  char cVar11;
  uint in_EAX;
  _func___cdecl_void_uint__EXCEPTION_POINTERS_ptr *p_Var8;
  uint uVar9;
  undefined3 uVar12;
  undefined4 uVar10;
  byte *in_ECX;
  ushort *in_EDX;
  byte bVar13;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *unaff_EDI;
  bool bVar16;
  
  bVar6 = (byte)in_EAX | 0x3a;
  bVar13 = (byte)((uint)unaff_EBX >> 8);
  bVar16 = CARRY1((byte)*in_EDX,bVar13);
  *(byte *)in_EDX = (byte)*in_EDX + bVar13;
  bVar3 = bVar6 + 0x3a;
  *(byte *)in_EDX = ((byte)*in_EDX - bVar13) - (0xc5 < bVar6 || CARRY1(bVar3,bVar16));
  uVar5 = *in_EDX;
  uVar2 = *in_EDX;
  *in_EDX = *in_EDX;
  if ((short)(((ushort)unaff_EDI & 3) - (uVar2 & 3)) < 1) {
    pcVar4 = (code *)swi(3);
    p_Var8 = (_func___cdecl_void_uint__EXCEPTION_POINTERS_ptr *)(*pcVar4)();
    return p_Var8;
  }
  *(undefined4 *)unaff_ESI = unaff_ESI;
  bVar16 = 9 < ((bVar3 + bVar16 ^ 0x37) & 0xf) || (in_EAX & 0x1000) != 0;
  cVar11 = (char)(in_EAX >> 8) + bVar16;
  bVar16 = 9 < (DAT_b637a837 & 0xf) || bVar16;
  uVar9 = CONCAT31(CONCAT21((short)(in_EAX >> 0x10),cVar11),DAT_b637a837 + bVar16 * '\x06') &
          0xffffff0f;
  uVar10 = CONCAT22((short)(uVar9 >> 0x10),CONCAT11(cVar11 + bVar16,(char)uVar9));
  puVar14 = &DAT_2037e837;
  cVar11 = (char)((uint)in_ECX >> 8);
  if ((char)((byte)in_EDX[-0x1007e4] - cVar11) < '\0') {
    puVar15 = puVar14;
    if ((char)(byte)in_EDX[-0x1007e4] <= cVar11) goto code_r0x009c4290;
  }
  else {
    *unaff_EDI = DAT_2037e837;
    puVar15 = (undefined1 *)0x2037e838;
    unaff_EDI = unaff_EDI + 1;
  }
  puVar14 = puVar15 + 1;
  uVar10 = CONCAT31((int3)((uint)uVar10 >> 8),*puVar15);
code_r0x009c4290:
  *(undefined1 **)in_ECX = unaff_EDI + *(int *)in_ECX;
  out(0x3c,(char)uVar10);
  uVar12 = (undefined3)((uint)uVar10 >> 8);
  uVar7 = in((short)in_EDX);
  pcVar1 = puVar14 + 5;
  *pcVar1 = (*pcVar1 - ((bVar13 ^ (byte)uVar5) & *in_ECX)) - (CONCAT31(uVar12,uVar7) < 0x3df63ddb);
  return (_func___cdecl_void_uint__EXCEPTION_POINTERS_ptr *)CONCAT31(uVar12,*pcVar1);
}
}

// =================================================
// Function: _sscanf_s
// =================================================
int __cdecl _sscanf_s(char *param_1,char *param_2)
{
{
  int extraout_EAX;
  
  vscan_fn();
  return extraout_EAX;
}
}

// =================================================
// Function: _strcat_s
// =================================================
int __cdecl _strcat_s(char *param_1,uint param_2,char *param_3)
{
{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iStack_10;
  
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    pcVar3 = param_1;
    if (param_3 != (char *)0x0) {
      do {
        if (*pcVar3 == '\0') break;
        pcVar3 = pcVar3 + 1;
        param_2 = param_2 - 1;
      } while (param_2 != 0);
      if (param_2 != 0) {
        do {
          cVar1 = *param_3;
          *pcVar3 = cVar1;
          pcVar3 = pcVar3 + 1;
          param_3 = param_3 + 1;
          if (cVar1 == '\0') break;
          param_2 = param_2 - 1;
        } while (param_2 != 0);
        if (param_2 != 0) {
          return 0;
        }
        *param_1 = '\0';
        piVar2 = __errno();
        iStack_10 = 0x22;
        *piVar2 = 0x22;
        goto LAB_0040b7d9;
      }
    }
    *param_1 = '\0';
  }
  piVar2 = __errno();
  iStack_10 = 0x16;
  *piVar2 = 0x16;
LAB_0040b7d9:
  __invalid_parameter();
  return iStack_10;
}
}

// =================================================
// Function: _strchr
// =================================================
char * __cdecl _strchr(char *_Str,int _Val)
{
{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}
}

// =================================================
// Function: _strcmp
// =================================================
int __cdecl _strcmp(char *param_1,char *param_2)
{
{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)param_1 & 3) != 0) {
    if (((uint)param_1 & 1) != 0) {
      bVar4 = *param_1;
      param_1 = param_1 + 1;
      bVar5 = bVar4 < (byte)*param_2;
      if (bVar4 != *param_2) goto LAB_004056c4;
      param_2 = param_2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)param_1 & 2) == 0) goto LAB_00405690;
    }
    uVar1 = *(undefined2 *)param_1;
    param_1 = param_1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*param_2;
    if (bVar4 != *param_2) goto LAB_004056c4;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)param_2[1];
    if (bVar4 != param_2[1]) goto LAB_004056c4;
    if (bVar4 == 0) {
      return 0;
    }
    param_2 = param_2 + 2;
  }
LAB_00405690:
  while( true ) {
    uVar2 = *(undefined4 *)param_1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*param_2;
    if (bVar4 != *param_2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)param_2[1];
    if (bVar4 != param_2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)param_2[2];
    if (bVar4 != param_2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)param_2[3];
    if (bVar3 != param_2[3]) break;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_004056c4:
  return (uint)bVar5 * -2 + 1;
}
}

// =================================================
// Function: _strcpy_s
// =================================================
int __cdecl _strcpy_s(char *param_1,uint param_2,char *param_3)
{
{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iStack_10;
  
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    pcVar3 = param_1;
    if (param_3 != (char *)0x0) {
      do {
        cVar1 = *param_3;
        *pcVar3 = cVar1;
        param_3 = param_3 + 1;
        if (cVar1 == '\0') break;
        param_2 = param_2 - 1;
        pcVar3 = pcVar3 + 1;
      } while (param_2 != 0);
      if (param_2 != 0) {
        return 0;
      }
      *param_1 = '\0';
      piVar2 = __errno();
      iStack_10 = 0x22;
      *piVar2 = 0x22;
      goto LAB_0040ac44;
    }
    *param_1 = '\0';
  }
  piVar2 = __errno();
  iStack_10 = 0x16;
  *piVar2 = 0x16;
LAB_0040ac44:
  __invalid_parameter();
  return iStack_10;
}
}

// =================================================
// Function: _strcspn
// =================================================
uint __cdecl _strcspn(char *param_1,char *param_2)
{
{
  byte bVar1;
  uint uVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  uVar2 = 0xffffffff;
  do {
    uVar2 = uVar2 + 1;
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return uVar2;
    }
    param_1 = param_1 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return uVar2;
}
}

// =================================================
// Function: _strlen
// =================================================
uint __cdecl _strlen(char *param_1)
{
{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)param_1;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_00405df0;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00405e23:
  return (uint)((int)puVar2 + (-1 - (int)param_1));
LAB_00405df0:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)param_1;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (uint)((int)puVar3 + (1 - (int)param_1));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (uint)((int)puVar3 + (2 - (int)param_1));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_00405e23;
}
}

// =================================================
// Function: _strncmp
// =================================================
int __cdecl _strncmp(char *param_1,char *param_2,uint param_3)
{
{
  byte *pbVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint local_8;
  
  local_8 = 0;
  if (param_3 != 0) {
    if ((3 < param_3) && (pbVar1 = (byte *)param_1, pbVar3 = (byte *)param_2, param_3 != 4)) {
      do {
        param_1 = (char *)(pbVar1 + 4);
        param_2 = (char *)(pbVar3 + 4);
        if ((*pbVar1 == 0) || (*pbVar1 != *pbVar3)) {
          uVar2 = (uint)*pbVar1;
          uVar4 = (uint)*pbVar3;
          goto LAB_00410b2d;
        }
        if ((pbVar1[1] == 0) || (pbVar1[1] != pbVar3[1])) {
          uVar2 = (uint)pbVar1[1];
          uVar4 = (uint)pbVar3[1];
          goto LAB_00410b2d;
        }
        if ((pbVar1[2] == 0) || (pbVar1[2] != pbVar3[2])) {
          uVar2 = (uint)pbVar1[2];
          uVar4 = (uint)pbVar3[2];
          goto LAB_00410b2d;
        }
        if ((pbVar1[3] == 0) || (pbVar1[3] != pbVar3[3])) {
          uVar2 = (uint)pbVar1[3];
          uVar4 = (uint)pbVar3[3];
          goto LAB_00410b2d;
        }
        local_8 = local_8 + 4;
        pbVar1 = (byte *)param_1;
        pbVar3 = (byte *)param_2;
      } while (local_8 < param_3 - 4);
    }
    for (; local_8 < param_3; local_8 = local_8 + 1) {
      if ((*param_1 == 0) || (*param_1 != *param_2)) {
        uVar2 = (uint)(byte)*param_1;
        uVar4 = (uint)(byte)*param_2;
LAB_00410b2d:
        return uVar2 - uVar4;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: _strncpy_s
// =================================================
int __cdecl _strncpy_s(char *param_1,uint param_2,char *param_3,uint param_4)
{
{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  int iStack_14;
  
  if (param_4 == 0) {
    if (param_1 == (char *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_0040b84f:
      if (param_2 != 0) {
        if (param_4 == 0) {
          *param_1 = '\0';
          return 0;
        }
        if (param_3 != (char *)0x0) {
          pcVar3 = param_1;
          uVar4 = param_2;
          if (param_4 == 0xffffffff) {
            do {
              cVar1 = *param_3;
              *pcVar3 = cVar1;
              pcVar3 = pcVar3 + 1;
              param_3 = param_3 + 1;
              if (cVar1 == '\0') break;
              uVar4 = uVar4 - 1;
            } while (uVar4 != 0);
          }
          else {
            do {
              cVar1 = *param_3;
              *pcVar3 = cVar1;
              pcVar3 = pcVar3 + 1;
              param_3 = param_3 + 1;
              if ((cVar1 == '\0') || (uVar4 = uVar4 - 1, uVar4 == 0)) break;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            if (param_4 == 0) {
              *pcVar3 = '\0';
            }
          }
          if (uVar4 != 0) {
            return 0;
          }
          if (param_4 == 0xffffffff) {
            param_1[param_2 - 1] = '\0';
            return 0x50;
          }
          *param_1 = '\0';
          piVar2 = __errno();
          iStack_14 = 0x22;
          *piVar2 = 0x22;
          goto LAB_0040b860;
        }
        *param_1 = '\0';
      }
    }
  }
  else if (param_1 != (char *)0x0) goto LAB_0040b84f;
  piVar2 = __errno();
  iStack_14 = 0x16;
  *piVar2 = 0x16;
LAB_0040b860:
  __invalid_parameter();
  return iStack_14;
}
}

// =================================================
// Function: _strstr
// =================================================
char * __cdecl _strstr(char *param_1,char *param_2)
{
{
  undefined2 in_DX;
  
  in(in_DX);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
}

// =================================================
// Function: _strtol
// =================================================
long __cdecl _strtol(char *param_1,char **param_2,int param_3)
{
{
  ulong uVar1;
  undefined **ppuVar2;
  
  if (DAT_00d53f54 == 0) {
    ppuVar2 = &PTR_DAT_00ccab50;
  }
  else {
    ppuVar2 = (undefined **)0x0;
  }
  uVar1 = strtoxl((localeinfo_struct *)ppuVar2,param_1,param_2,param_3,0);
  return uVar1;
}
}

// =================================================
// Function: _strtoul
// =================================================
ulong __cdecl _strtoul(char *param_1,char **param_2,int param_3)
{
{
  ulong uVar1;
  undefined **ppuVar2;
  
  if (DAT_00d53f54 == 0) {
    ppuVar2 = &PTR_DAT_00ccab50;
  }
  else {
    ppuVar2 = (undefined **)0x0;
  }
  uVar1 = strtoxl((localeinfo_struct *)ppuVar2,param_1,param_2,param_3,1);
  return uVar1;
}
}

// =================================================
// Function: _tolower
// =================================================
int __cdecl _tolower(int param_1)
{
{
  if (DAT_00d53f54 == 0) {
    if (param_1 - 0x41U < 0x1a) {
      return param_1 + 0x20;
    }
  }
  else {
    param_1 = __tolower_l(param_1,(localeinfo_struct *)0x0);
  }
  return param_1;
}
}

// =================================================
// Function: _vector_constructor_iterator_
// =================================================
void __cdecl
_vector_constructor_iterator_
          (void *param_1,uint param_2,int param_3,_func___cdecl_void_ptr_void_ptr *param_4)
{
{
  void *unaff_ESI;
  
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: _vsprintf_s
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c169e) overlaps instruction at (ram,0x009c169a)
    */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl _vsprintf_s(char *param_1,uint param_2,char *param_3,char *param_4)
{
{
  byte *pbVar1;
  byte bVar2;
  byte bVar4;
  char cVar8;
  uint in_EAX;
  uint uVar5;
  int iVar6;
  undefined2 uVar9;
  char *pcVar7;
  int in_ECX;
  int *in_EDX;
  uint unaff_EBX;
  uint uVar10;
  int unaff_ESI;
  char *unaff_EDI;
  byte in_AF;
  int unaff_retaddr;
  byte bVar3;
  
  pbVar1 = (byte *)(unaff_ESI + 0x30);
  bVar2 = *pbVar1;
  bVar4 = (byte)((uint)in_ECX >> 8);
  bVar3 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar4;
  if ((char)*pbVar1 < '\0') {
    if (*pbVar1 != 0 && SCARRY1(bVar3,bVar4) == (char)*pbVar1 < '\0') goto code_r0x009c166e;
  }
  else {
    in_EDX = (int *)CONCAT22((short)((uint)in_EDX >> 0x10),
                             CONCAT11(((char)((uint)in_EDX >> 8) - *unaff_EDI) - CARRY1(bVar2,bVar4)
                                      ,(char)in_EDX));
  }
  in_EAX = in_EAX + 1;
code_r0x009c166e:
  *(uint *)(in_ECX + 0x31) = *(uint *)(in_ECX + 0x31) ^ unaff_EBX;
  *(uint *)(unaff_retaddr + 0x32) = *(uint *)(unaff_retaddr + 0x32) ^ unaff_EBX;
  iVar6 = *in_EDX;
  *unaff_EDI = (char)in_EAX;
  uVar10 = (uint)&param_1 ^ in_EAX ^ uRamde34b334;
  uVar5 = in(0x35);
  *(byte *)(iVar6 * 0x3395326e) =
       *(byte *)(iVar6 * 0x3395326e) ^ (byte)((uint)in_EDX >> 8) ^ (byte)(in_EAX >> 8);
  iVar6 = (uVar5 ^ 0x362b3620) + 0x40371a37;
  bVar2 = 9 < ((byte)iVar6 & 0xf) | in_AF;
  bVar4 = (byte)iVar6 + bVar2 * '\x06' & 0xf;
  bVar3 = 9 < bVar4 | bVar2;
  uVar5 = CONCAT31((int3)((uint)iVar6 >> 8),bVar4 + bVar3 * '\x06') & 0xffff000f;
  uVar9 = (undefined2)(uVar5 >> 0x10);
  bVar4 = (byte)uVar5;
  cVar8 = (char)((uint)iVar6 >> 8) + bVar2 + bVar3;
  *(uint *)(uVar10 - 4) = CONCAT22(uVar9,CONCAT11(cVar8,bVar4));
  pcVar7 = (char *)CONCAT31(CONCAT21(uVar9,cVar8 + (9 < bVar4 | bVar3)),DAT_b038ab38);
  *pcVar7 = *pcVar7 + DAT_b038ab38;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: _wcschr
// =================================================
wchar_t * __cdecl _wcschr(wchar_t *param_1,wchar_t param_2)
{
{
  undefined1 uVar1;
  undefined2 in_DX;
  byte unaff_BH;
  byte *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = in(in_DX);
  *unaff_EDI = uVar1;
  *unaff_ESI = *unaff_ESI ^ unaff_BH;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
}

// =================================================
// Function: _wcsncpy_s
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c1d53) overlaps instruction at (ram,0x009c1d52)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009c1ab0) */
/* WARNING: Removing unreachable block (ram,0x009c1d10) */
/* WARNING: Removing unreachable block (ram,0x009c1d53) */
/* WARNING: Removing unreachable block (ram,0x009c1d14) */
/* WARNING: Removing unreachable block (ram,0x009c1d22) */
/* WARNING: Removing unreachable block (ram,0x009c1d72) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl _wcsncpy_s(wchar_t *param_1,uint param_2,wchar_t *param_3,uint param_4)
{
{
  bool bVar1;
  uint *puVar2;
  longlong lVar3;
  code *pcVar4;
  undefined6 uVar5;
  wchar_t *pwVar6;
  byte bVar7;
  byte bVar8;
  undefined2 uVar9;
  undefined4 in_EAX;
  char cVar17;
  byte bVar18;
  uint uVar10;
  int iVar11;
  wchar_t *pwVar12;
  uint *puVar13;
  uint uVar14;
  char cVar19;
  ushort uVar20;
  byte *pbVar15;
  char *pcVar16;
  uint in_ECX;
  uint uVar21;
  uint in_EDX;
  uint uVar22;
  wchar_t *pwVar23;
  byte *pbVar24;
  byte bVar26;
  undefined4 unaff_EBX;
  undefined3 uVar27;
  undefined4 *puVar28;
  wchar_t *unaff_EBP;
  wchar_t *unaff_ESI;
  int *piVar29;
  byte *unaff_EDI;
  uint *puVar30;
  int in_GS_OFFSET;
  byte in_AF;
  undefined2 in_FPUStatusWord;
  uint *unaff_retaddr;
  wchar_t *in_stack_00000014;
  wchar_t *in_stack_00000018;
  uint *in_stack_00000020;
  wchar_t *in_stack_00000024;
  uint in_stack_00000028;
  wchar_t *in_stack_0000002c;
  int iStack_15;
  uint *puStack_10;
  wchar_t *pwStack_c;
  byte bVar25;
  
  bVar25 = (byte)((uint)unaff_EBX >> 8);
  *unaff_EDI = *unaff_EDI & bVar25;
  bVar8 = (char)in_EAX * '\x02';
  pwVar23 = (wchar_t *)CONCAT31((int3)((uint)in_EAX >> 8),bVar8);
  *(char *)pwVar23 = (char)*pwVar23 + (char)unaff_EBX;
  *(byte *)pwVar23 = (char)*pwVar23 + bVar8;
  uVar27 = (undefined3)((uint)unaff_EBX >> 8);
  bVar26 = (char)unaff_EBX + bVar8;
  puVar13 = (uint *)CONCAT31(uVar27,bVar26);
  uVar21 = in_ECX ^ in_EDX;
  uVar22 = in_EDX ^ (uint)unaff_EBP;
  *(uint *)(uVar22 + 0x32) = *(uint *)(uVar22 + 0x32) ^ (uint)puVar13;
  _DAT_0032af32 = pwVar23;
  *(byte *)pwVar23 = (char)*pwVar23 + bVar8;
  if (uVar21 - 1 == 0 || (char)*pwVar23 == '\0') {
    pcVar16 = (char *)((int)pwVar23 * 2 + 0x31b10000);
    *pcVar16 = *pcVar16 + (char)(uVar21 - 1);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar14 = *puVar13;
  *(uint *)unaff_ESI = *(uint *)unaff_ESI & uVar14;
  puVar30 = (uint *)(uVar14 ^ *(uint *)unaff_ESI);
  if (uVar21 == 0) {
    uRame53eb13e = uVar21;
    *puVar30 = *puVar30 | (uint)puVar30;
    puVar2 = (uint *)((int)puVar30 - *puVar30);
    bVar7 = in_AF * -6 & 0xf;
    bVar18 = 9 < bVar7 | in_AF;
    bVar7 = bVar7 + bVar18 * -6 & 0xf;
    cVar17 = -bVar18 - in_AF;
    in_AF = 9 < bVar7 | bVar18;
    bVar7 = bVar7 + in_AF * -6;
    bVar18 = bVar7 & 0xf;
    uVar10 = (uint)(CONCAT11(cVar17 - in_AF,bVar7) & 0xff0f);
    bVar1 = (int)puVar30 < (int)*puVar30;
    uVar21 = uVar22;
    puVar30 = puVar2;
    pwStack_c = pwVar23;
    if (bVar1) goto LAB_009c1b49;
    in_AF = 9 < bVar18 | in_AF;
    bVar18 = bVar18 + in_AF * -6;
    bVar7 = bVar18 & 0xf;
    pcVar16 = (char *)(uint)(CONCAT11('?' - in_AF,bVar18) & 0xff0f);
    *pcVar16 = *pcVar16 + bVar7;
    cVar17 = bVar7 + (char)((uint)in_EAX >> 8);
    bVar18 = ('?' - in_AF) + (char)(uVar22 >> 8);
    pwVar12 = (wchar_t *)(uint)CONCAT11(bVar18,cVar17);
    *(char *)pwVar12 = (char)*pwVar12 + cVar17;
    *(char *)unaff_ESI = (char)*unaff_ESI + cVar17;
    *(byte *)puVar13 = (byte)*puVar13 ^ bVar18;
    puVar2 = puVar13 + 0xc;
    *(byte *)puVar2 = (byte)*puVar2 ^ (byte)uVar22;
    puStack_10 = puVar13;
    if ((byte)*puVar2 != 0) {
      puVar30 = (uint *)CONCAT31((int3)(uVar22 >> 8),(byte)uVar22 ^ bVar8);
      pbVar15 = (byte *)(uint)CONCAT11(bVar18 ^ bVar25,cVar17);
      *pbVar15 = *pbVar15 ^ bVar26;
      *puVar30 = *puVar30 ^ (uint)pwVar23;
      *(uint *)((int)unaff_EBP + 0x31) = *(uint *)((int)unaff_EBP + 0x31) ^ (uint)puVar13;
      *(uint *)((int)pwVar23 + -0x7ecd8ccf) = *(uint *)((int)pwVar23 + -0x7ecd8ccf) ^ param_2;
      *unaff_retaddr = *unaff_retaddr ^ 0x33a13393;
      pcVar4 = (code *)swi(1);
      iVar11 = (*pcVar4)();
      return iVar11;
    }
    piVar29 = (int *)((int)unaff_ESI * 8 + 0x63351134);
    *piVar29 = *piVar29 << 0x15;
    puVar13 = (uint *)CONCAT31(uVar27,0x34);
    pwVar6 = unaff_EBP;
  }
  else {
    *(uint *)pwVar23 = *(uint *)pwVar23 << 1;
    uVar14 = *puVar13;
    *puVar13 = *puVar13 ^ (uint)unaff_ESI & uVar14;
    uVar10 = uVar22 ^ *(uint *)(in_GS_OFFSET + uVar21 + 0xa1339333);
    pwVar23 = (wchar_t *)((uint)pwVar23 ^ (uint)unaff_EBP);
    unaff_ESI = (wchar_t *)((uint)unaff_ESI & uVar14 ^ uVar21);
LAB_009c1b49:
    *puVar30 = *(uint *)unaff_ESI;
    pwVar12 = (wchar_t *)(uVar10 ^ 0xa200c1);
    uVar22 = uVar21 - 1;
    pwVar6 = unaff_EBP;
    unaff_ESI = unaff_ESI + 2;
    if (uVar21 - 1 == 0 || pwVar12 != (wchar_t *)0x0) {
      uVar22 = param_2 - 1;
      unaff_ESI = pwStack_c;
      puVar13 = puStack_10;
      if (uVar22 != 0 && pwVar12 == (wchar_t *)0xacc9ceca) goto code_r0x009c1ba9;
      *puStack_10 = (uint)(*puStack_10 + (int)pwStack_c);
      puVar13 = (uint *)in(0x37);
      *puVar13 = *puVar13 & (uint)puStack_10;
      in_AF = 9 < ((byte)puVar13 & 0xf) | 9 < (((byte)unaff_EBP ^ 0x37) & 0xf) | in_AF;
      pwVar12 = in_stack_0000002c;
      uVar22 = in_stack_00000028;
      pwVar23 = in_stack_00000024;
      puVar13 = in_stack_00000020;
      pwVar6 = in_stack_00000018;
      unaff_ESI = in_stack_00000014;
      puVar30 = puStack_10;
    }
  }
  param_3 = pwVar6;
  param_1 = pwVar23;
  unaff_EBP = pwVar12;
  unaff_retaddr =
       (uint *)CONCAT22((short)((uint)puVar13 >> 0x10),CONCAT11((char)*param_1,(char)puVar13));
  *(int *)param_1 = (int)*(uint *)param_1 >> 0x17;
  puVar13 = puVar30 + 1;
code_r0x009c1ba9:
  puVar30 = (uint *)(uVar22 + 1);
  lVar3 = CONCAT44(param_1,unaff_EBP) % (longlong)(int)*(uint *)unaff_ESI;
  uVar21 = (uint)(CONCAT44(param_1,unaff_EBP) / (longlong)(int)*(uint *)unaff_ESI) | 0x483f163f;
  bVar8 = 9 < ((byte)uVar21 & 0xf) | in_AF;
  bVar25 = (byte)uVar21 + bVar8 * -6 & 0xf;
  bVar26 = 9 < bVar25 | bVar8;
  uVar14 = CONCAT31((int3)(uVar21 >> 8),bVar25 + bVar26 * -6) & 0xffff000f;
  bVar25 = (byte)uVar14;
  iStack_15 = CONCAT22((short)(uVar14 >> 0x10),
                       CONCAT11(((char)(uVar21 >> 8) - bVar8) - bVar26,bVar25));
  bVar26 = 9 < bVar25 | bVar26;
  bVar8 = 9 < ((byte)&iStack_15 & 0xf) | 9 < (bVar25 + bVar26 * -6 & 0xf) | bVar26;
  bVar25 = (byte)&iStack_15 + bVar8 * -6 & 0xf;
  bVar26 = 9 < bVar25 | bVar8;
  uVar21 = CONCAT31((int3)((uint)&iStack_15 >> 8),bVar25 + bVar26 * -6) & 0xffff000f;
  uVar20 = (ushort)(uVar21 >> 0x10);
  bVar25 = (byte)uVar21;
  cVar19 = ((char)((uint)&iStack_15 >> 8) - bVar8) - bVar26;
  _DAT_f03db63d = unaff_EBP;
  *(uint *)(iStack_15 + -4) = CONCAT22(uVar20,CONCAT11(cVar19,bVar25));
  *(uint **)(iStack_15 + -8) = puVar30;
  *(int *)(iStack_15 + -0xc) = (int)lVar3;
  *(uint **)(iStack_15 + -0x10) = unaff_retaddr;
  *(int *)(iStack_15 + -0x14) = iStack_15;
  *(wchar_t **)(iStack_15 + -0x18) = param_3;
  *(wchar_t **)(iStack_15 + -0x1c) = unaff_ESI;
  *(uint **)(iStack_15 + -0x20) = puVar13;
  bVar26 = 9 < bVar25 | bVar26;
  bVar8 = bVar25 + bVar26 * -6 & 0xf;
  bVar25 = 9 < bVar8 | bVar26;
  bVar8 = bVar8 + bVar25 * -6 & 0xf;
  *(undefined4 *)(iStack_15 + -0x24) = 0xc13fb33f;
  bVar18 = 9 < bVar8 | bVar25;
  bVar7 = bVar8 + bVar18 * -6 & 0xf;
  bVar8 = 9 < bVar7 | bVar18;
  uVar21 = CONCAT31((int3)(((uint)uVar20 << 0x10) >> 8),bVar7 + bVar8 * -6) & 0xffffff0f;
  cVar17 = (char)uVar21;
  pbVar15 = (byte *)CONCAT22((short)(uVar21 >> 0x10),
                             CONCAT11((((cVar19 - bVar26) - bVar25) - bVar18) - bVar8,cVar17));
  *pbVar15 = *pbVar15 + cVar17;
  *pbVar15 = *pbVar15 + cVar17;
  *(int *)(iStack_15 + -0x28) = iStack_15 + -0x24;
  *pbVar15 = *pbVar15 + cVar17;
  *pbVar15 = *pbVar15 + cVar17;
  bVar25 = (byte)((ulonglong)lVar3 >> 8) & *pbVar15;
  pbVar24 = (byte *)CONCAT22((short)((ulonglong)lVar3 >> 0x10),CONCAT11(bVar25,(char)lVar3));
  piVar29 = (int *)((int)unaff_ESI + (uint)CARRY4((uint)unaff_ESI,*puVar30) + *puVar30 + *puVar30);
  *pbVar24 = *pbVar24 | bVar25;
  uVar21 = (uint)pbVar15 | 0x74326332;
  bVar26 = (byte)uVar21;
  if ((char)(bVar26 ^ 0xe3) < '\x01') {
    return CONCAT31((int3)(CONCAT22((short)(uVar21 >> 0x10),
                                    CONCAT11((byte)(uVar21 >> 8) ^
                                             *(byte *)((int)piVar29 + -0x7ccc54cd),bVar26)) >> 8),
                    bVar26) ^ 0xe3;
  }
  _DAT_36533595 = _DAT_36533595 ^ 0x60;
  if (uVar22 == 0 || _DAT_36533595 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar5 = *(undefined6 *)piVar29;
  puVar28 = (undefined4 *)(iStack_15 + -0x2c);
  *(wchar_t **)(iStack_15 + -0x2c) = param_3;
  cVar17 = '\x1d';
  do {
    param_3 = param_3 + -2;
    puVar28 = puVar28 + -1;
    *puVar28 = *(undefined4 *)param_3;
    cVar17 = cVar17 + -1;
  } while ('\0' < cVar17);
  *(int *)(iStack_15 + -0xa4) = iStack_15 + -0x2c;
  *piVar29 = *piVar29 >> 1;
  *(undefined2 *)uVar5 = in_FPUStatusWord;
  DAT_c03ebc3e = DAT_c03ebc3e + -0x44;
  *(int *)(iStack_15 + -0xcce6) = iStack_15 + -0xcce2;
  bVar26 = DAT_c03ebc3e + 0xbc;
  DAT_c03ebc3e = DAT_c03ebc3e - 6;
  if (bVar26 < 0xc2) {
    bVar8 = bVar8 | 1;
    uVar21 = CONCAT31(0xc03ebc,bVar8 * '\x06' + '>') & 0xffffff0f;
    DAT_80357334 = (undefined1)uVar21;
    uVar9 = CONCAT11(bVar8 + 0xbc,DAT_80357334);
    _DAT_ca38b138 = &DAT_c03ebc3e;
    *(uint *)(iStack_15 + -0xcce6) = uVar22;
    *(undefined4 *)(iStack_15 + -0xccea) = 0x36;
    iVar11 = (CONCAT22((short)(uVar21 >> 0x10),uVar9) ^ 0x36253601) + 1;
    bVar8 = 9 < ((byte)iVar11 & 0xf) | bVar8;
    uVar21 = CONCAT31((int3)((uint)iVar11 >> 8),(byte)iVar11 + bVar8 * '\x06') & 0xffffff0f;
    pcVar16 = (char *)CONCAT22((short)(uVar21 >> 0x10),
                               CONCAT11((char)((uint)iVar11 >> 8) + bVar8,(char)uVar21));
  }
  else {
    DAT_c03ebc3e = DAT_c03ebc3e ^ 0x9b;
    puVar13 = (uint *)(uVar22 ^ iStack_15 - 0xcce6U);
    pcVar16 = (char *)(CONCAT31(0xc03ebc,bVar25 ^ 0x3e) ^ *puVar13 ^ 0x35ba3530);
    if (puVar13 != (uint *)0x0) {
      pcVar4 = (code *)swi(1);
      iVar11 = (*pcVar4)();
      return iVar11;
    }
    *pcVar16 = *pcVar16 + (char)((uint)pcVar16 >> 8);
    *pcVar16 = *pcVar16 + (char)pcVar16;
  }
  return (int)pcVar16;
}
}

// =================================================
// Function: _wcsrchr
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

wchar_t * __cdecl _wcsrchr(wchar_t *param_1,wchar_t param_2)
{
{
  uint *puVar1;
  byte bVar2;
  byte *pbVar3;
  bool bVar4;
  undefined1 uVar5;
  uint *in_EAX;
  wchar_t *pwVar7;
  char *pcVar8;
  int in_ECX;
  int in_EDX;
  uint uVar9;
  uint unaff_EBP;
  int unaff_ESI;
  uint uVar10;
  undefined2 in_CS;
  byte in_AF;
  undefined8 uVar11;
  uint uVar6;
  
  uVar10 = *in_EAX;
  *(byte *)in_EAX = (byte)*in_EAX + (byte)in_EAX;
  uVar10 = unaff_ESI + *in_EAX + (uint)CARRY1((byte)uVar10,(byte)in_EAX) & *in_EAX;
  if (in_ECX == 0) {
LAB_009c18d2:
    pbVar3 = (byte *)((int)in_EAX + 0x61372c37);
    bVar4 = (bool)(9 < ((byte)pbVar3 & 0xf) | in_AF);
    uVar10 = CONCAT31((int3)((uint)pbVar3 >> 8),(byte)pbVar3 + bVar4 * '\x06') & 0xffffff0f;
    pwVar7 = (wchar_t *)
             CONCAT22((short)(uVar10 >> 0x10),
                      CONCAT11((char)((uint)pbVar3 >> 8) + bVar4,(char)uVar10));
    if (bVar4 || pbVar3 == (byte *)0x0) {
      if (!bVar4) {
        return pwVar7;
      }
      goto LAB_009c1914;
    }
  }
  else {
    uVar5 = (undefined1)((ushort)in_EAX / (ushort)(byte)*in_EAX);
    uVar6 = CONCAT22((short)((uint)in_EAX >> 0x10),
                     CONCAT11((char)((ushort)in_EAX % (ushort)(byte)*in_EAX),uVar5));
    out((short)in_EDX,uVar5);
    puVar1 = (uint *)(in_EDX + -0x7b + uVar10);
    *puVar1 = *puVar1 ^ unaff_EBP;
    bVar2 = *(byte *)(in_EDX + 0x333332ce + uVar10);
    uVar9 = (uint)&stack0x00000000 ^ *(uint *)(in_EDX + 0x33);
    uVar10 = *(uint *)(uVar10 + 0x34);
    *(undefined4 *)(uVar9 - 4) = 0xba34a134;
    in_EAX = (uint *)(CONCAT31((int3)(uVar6 >> 8),uVar5) ^ 0x356235c1);
    _DAT_36733590 = _DAT_36733590 ^ 0xffffff82;
    if ((CONCAT22((short)((uint)in_ECX >> 0x10),
                  CONCAT11((byte)((uint)in_ECX >> 8) ^ bVar2,(char)in_ECX)) ^ uVar6 ^ uVar10) == 1
        || _DAT_36733590 == 0) goto LAB_009c18d2;
    *(undefined2 *)(uVar9 - 8) = in_CS;
    *(undefined4 *)(uVar9 - 0xc) = 0x9c1911;
    uVar11 = func_0xf7319f31();
    in_EDX = (int)((ulonglong)uVar11 >> 0x20);
    pwVar7 = (wchar_t *)uVar11;
  }
  pwVar7 = (wchar_t *)CONCAT31((int3)((uint)pwVar7 >> 8),(byte)pwVar7 ^ *(byte *)(in_EDX + 0x32));
LAB_009c1914:
  pcVar8 = (char *)(((uint)pwVar7 | 0xd634c334) ^ 0x36a336c3);
  *pcVar8 = *pcVar8 >> 0x15;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: atoi
// =================================================
void __cdecl atoi(void)
{
{
  char *in_stack_00000004;
  
  _strtol(in_stack_00000004,(char **)0x0,10);
  return;
}
}

// =================================================
// Function: classic_md5_append
// =================================================
void __cdecl classic_md5_append(void)
{
{
  uchar *unaff_retaddr;
  int in_stack_00000004;
  md5_state_s *in_stack_00000008;
  
  static_md5_append(in_stack_00000008,unaff_retaddr,in_stack_00000004);
  return;
}
}

// =================================================
// Function: classic_md5_finish
// =================================================
void __cdecl classic_md5_finish(void)
{
{
  static_md5_finish();
  return;
}
}

// =================================================
// Function: classic_md5_init
// =================================================
void __cdecl classic_md5_init(void)
{
{
  static_md5_init();
  return;
}
}

// =================================================
// Function: crc32
// =================================================
void __cdecl crc32(void)
{
{
  int in_stack_00000008;
  
  if (in_stack_00000008 == 0) {
    return;
  }
  crc32_little();
  return;
}
}

// =================================================
// Function: crc32_little
// =================================================
void __cdecl crc32_little(void)
{
{
  uint in_ECX;
  uint in_EDX;
  uint uVar1;
  
  for (; (in_EDX != 0 && ((in_ECX & 3) != 0)); in_ECX = in_ECX + 1) {
    in_EDX = in_EDX - 1;
  }
  if (0x1f < in_EDX) {
    uVar1 = in_EDX >> 5;
    do {
      in_EDX = in_EDX - 0x20;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  if (3 < in_EDX) {
    uVar1 = in_EDX >> 2;
    do {
      in_EDX = in_EDX - 4;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  for (; in_EDX != 0; in_EDX = in_EDX - 1) {
  }
  return;
}
}

// =================================================
// Function: doexit
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl doexit(void)
{
{
  int iVar1;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int extraout_EAX_01;
  code *extraout_EAX_02;
  int *piVar2;
  int in_stack_00000004;
  int in_stack_00000008;
  undefined1 uStack0000000c;
  
  __lock(8);
  if (DAT_00d53e20 != 1) {
    _DAT_00d53e1c = 1;
    DAT_00d53e18 = uStack0000000c;
    if (in_stack_00000008 == 0) {
      __decode_pointer();
      __decode_pointer();
      piVar2 = extraout_EAX_00;
      if (extraout_EAX != (int *)0x0) {
        while( true ) {
          piVar2 = piVar2 + -1;
          if (piVar2 < extraout_EAX) break;
          if (*piVar2 != 0) {
            iVar1 = *piVar2;
            __encoded_null();
            if (iVar1 != extraout_EAX_01) {
              __decode_pointer();
              (*extraout_EAX_02)();
            }
          }
        }
      }
      __initterm();
    }
    __initterm();
  }
  FUN_004081b7();
  if (_uStack0000000c == 0) {
    DAT_00d53e20 = 1;
    __unlock(8);
                    /* WARNING: Subroutine does not return */
    ___crtExitProcess(in_stack_00000004);
  }
  return;
}
}

// =================================================
// Function: fastcopy_I
// =================================================
void __cdecl fastcopy_I(void)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined4 *in_stack_00000004;
  undefined4 *in_stack_00000008;
  uint in_stack_0000000c;
  
  uVar16 = in_stack_0000000c >> 7;
  do {
    uVar1 = in_stack_00000008[1];
    uVar2 = in_stack_00000008[2];
    uVar3 = in_stack_00000008[3];
    uVar4 = in_stack_00000008[4];
    uVar5 = in_stack_00000008[5];
    uVar6 = in_stack_00000008[6];
    uVar7 = in_stack_00000008[7];
    uVar8 = in_stack_00000008[8];
    uVar9 = in_stack_00000008[9];
    uVar10 = in_stack_00000008[10];
    uVar11 = in_stack_00000008[0xb];
    uVar12 = in_stack_00000008[0xc];
    uVar13 = in_stack_00000008[0xd];
    uVar14 = in_stack_00000008[0xe];
    uVar15 = in_stack_00000008[0xf];
    *in_stack_00000004 = *in_stack_00000008;
    in_stack_00000004[1] = uVar1;
    in_stack_00000004[2] = uVar2;
    in_stack_00000004[3] = uVar3;
    in_stack_00000004[4] = uVar4;
    in_stack_00000004[5] = uVar5;
    in_stack_00000004[6] = uVar6;
    in_stack_00000004[7] = uVar7;
    in_stack_00000004[8] = uVar8;
    in_stack_00000004[9] = uVar9;
    in_stack_00000004[10] = uVar10;
    in_stack_00000004[0xb] = uVar11;
    in_stack_00000004[0xc] = uVar12;
    in_stack_00000004[0xd] = uVar13;
    in_stack_00000004[0xe] = uVar14;
    in_stack_00000004[0xf] = uVar15;
    uVar1 = in_stack_00000008[0x11];
    uVar2 = in_stack_00000008[0x12];
    uVar3 = in_stack_00000008[0x13];
    uVar4 = in_stack_00000008[0x14];
    uVar5 = in_stack_00000008[0x15];
    uVar6 = in_stack_00000008[0x16];
    uVar7 = in_stack_00000008[0x17];
    uVar8 = in_stack_00000008[0x18];
    uVar9 = in_stack_00000008[0x19];
    uVar10 = in_stack_00000008[0x1a];
    uVar11 = in_stack_00000008[0x1b];
    uVar12 = in_stack_00000008[0x1c];
    uVar13 = in_stack_00000008[0x1d];
    uVar14 = in_stack_00000008[0x1e];
    uVar15 = in_stack_00000008[0x1f];
    in_stack_00000004[0x10] = in_stack_00000008[0x10];
    in_stack_00000004[0x11] = uVar1;
    in_stack_00000004[0x12] = uVar2;
    in_stack_00000004[0x13] = uVar3;
    in_stack_00000004[0x14] = uVar4;
    in_stack_00000004[0x15] = uVar5;
    in_stack_00000004[0x16] = uVar6;
    in_stack_00000004[0x17] = uVar7;
    in_stack_00000004[0x18] = uVar8;
    in_stack_00000004[0x19] = uVar9;
    in_stack_00000004[0x1a] = uVar10;
    in_stack_00000004[0x1b] = uVar11;
    in_stack_00000004[0x1c] = uVar12;
    in_stack_00000004[0x1d] = uVar13;
    in_stack_00000004[0x1e] = uVar14;
    in_stack_00000004[0x1f] = uVar15;
    in_stack_00000008 = in_stack_00000008 + 0x20;
    in_stack_00000004 = in_stack_00000004 + 0x20;
    uVar16 = uVar16 - 1;
  } while (uVar16 != 0);
  return;
}
}

// =================================================
// Function: fastzero_I
// =================================================
void __cdecl fastzero_I(void)
{
{
  uint uVar1;
  undefined1 (*in_stack_00000004) [16];
  uint in_stack_00000008;
  
  uVar1 = in_stack_00000008 >> 7;
  do {
    *in_stack_00000004 = (undefined1  [16])0x0;
    in_stack_00000004[1] = (undefined1  [16])0x0;
    in_stack_00000004[2] = (undefined1  [16])0x0;
    in_stack_00000004[3] = (undefined1  [16])0x0;
    in_stack_00000004[4] = (undefined1  [16])0x0;
    in_stack_00000004[5] = (undefined1  [16])0x0;
    in_stack_00000004[6] = (undefined1  [16])0x0;
    in_stack_00000004[7] = (undefined1  [16])0x0;
    in_stack_00000004 = in_stack_00000004 + 8;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}
}

// =================================================
// Function: lzo1x_1_compress
// =================================================
void __cdecl lzo1x_1_compress(void)
{
{
  uint extraout_EAX;
  byte bVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int in_stack_00000004;
  uint in_stack_00000008;
  char *in_stack_0000000c;
  int *in_stack_00000010;
  
  uVar2 = in_stack_00000008;
  pcVar3 = in_stack_0000000c;
  if (0xd < in_stack_00000008) {
    __lzo1x_1_do_compress();
    uVar2 = extraout_EAX;
    pcVar3 = in_stack_0000000c + *in_stack_00000010;
  }
  if (uVar2 == 0) goto LAB_0090fbd0;
  pcVar4 = (char *)((in_stack_00000004 - uVar2) + in_stack_00000008);
  bVar1 = (byte)uVar2;
  if ((pcVar3 == in_stack_0000000c) && (uVar2 < 0xef)) {
    *pcVar3 = bVar1 + 0x11;
LAB_0090fbb7:
    pcVar3 = pcVar3 + 1;
  }
  else {
    if (3 < uVar2) {
      if (uVar2 < 0x13) {
        in_stack_00000008 = (uint)(byte)(bVar1 - 3);
      }
      else {
        in_stack_00000008 = uVar2 - 0x12;
        *pcVar3 = '\0';
        pcVar3 = pcVar3 + 1;
        if (0xff < in_stack_00000008) {
          uVar5 = (uVar2 - 0x112) / 0xff + 1;
          _memset(pcVar3,0,uVar5);
          pcVar3 = pcVar3 + uVar5;
          do {
            in_stack_00000008 = in_stack_00000008 - 0xff;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
      }
      *pcVar3 = (char)in_stack_00000008;
      goto LAB_0090fbb7;
    }
    pcVar3[-2] = pcVar3[-2] | bVar1;
  }
  do {
    *pcVar3 = *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
LAB_0090fbd0:
  *pcVar3 = '\x11';
  pcVar3[1] = '\0';
  pcVar3[2] = '\0';
  *in_stack_00000010 = (int)(pcVar3 + 2 + (1 - (int)in_stack_0000000c));
  return;
}
}

// =================================================
// Function: lzo1x_decompress_safe
// =================================================
void __cdecl lzo1x_decompress_safe(void)
{
{
  ushort *puVar1;
  byte bVar2;
  ushort uVar3;
  byte *pbVar4;
  ushort *puVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  ushort *in_stack_00000004;
  int in_stack_00000008;
  byte *in_stack_0000000c;
  int *in_stack_00000010;
  
  puVar1 = (ushort *)((int)in_stack_00000004 + in_stack_00000008);
  pbVar4 = (byte *)*in_stack_00000010;
  *in_stack_00000010 = 0;
  bVar2 = (byte)*in_stack_00000004;
  pbVar11 = in_stack_0000000c;
  if (bVar2 < 0x12) goto LAB_0090fc74;
  pbVar6 = (byte *)(bVar2 - 0x11);
  puVar5 = (ushort *)((int)in_stack_00000004 + 1);
  in_stack_00000004 = puVar5;
  if (pbVar6 < (byte *)0x4) goto LAB_0090fda2;
  if (pbVar4 < pbVar6) {
LAB_0090fffe:
    *in_stack_00000010 = (int)pbVar11 - (int)in_stack_0000000c;
    return;
  }
  if ((uint)((int)puVar1 - (int)puVar5) < bVar2 - 0x10) {
LAB_0090ffb6:
    *in_stack_00000010 = (int)pbVar11 - (int)in_stack_0000000c;
    return;
  }
  do {
    *pbVar11 = (byte)*puVar5;
    pbVar11 = pbVar11 + 1;
    puVar5 = (ushort *)((int)puVar5 + 1);
    pbVar6 = pbVar6 + -1;
  } while (pbVar6 != (byte *)0x0);
LAB_0090fd30:
  uVar8 = (uint)(byte)*puVar5;
  in_stack_00000004 = (ushort *)((int)puVar5 + 1);
  if (0xf < uVar8) goto LAB_0090fddd;
  iVar10 = (uint)*(byte *)in_stack_00000004 * -4 - (uint)(byte)((byte)*puVar5 >> 2);
  in_stack_00000004 = puVar5 + 1;
  if (pbVar11 + iVar10 + -0x801 < in_stack_0000000c) {
LAB_0090ffe8:
    *in_stack_00000010 = (int)pbVar11 - (int)in_stack_0000000c;
    return;
  }
  if ((byte *)0x2 < in_stack_0000000c + ((int)pbVar4 - (int)pbVar11)) {
    *pbVar11 = pbVar11[iVar10 + -0x801];
    pbVar11[1] = pbVar11[iVar10 + -0x800];
    pbVar11[2] = pbVar11[iVar10 + -0x7ff];
    pbVar11 = pbVar11 + 3;
LAB_0090fd91:
    do {
      pbVar6 = (byte *)((byte)in_stack_00000004[-1] & 3);
      if (((byte)in_stack_00000004[-1] & 3) == 0) {
LAB_0090fc74:
        if (puVar1 <= in_stack_00000004) {
          *in_stack_00000010 = (int)pbVar11 - (int)in_stack_0000000c;
          return;
        }
        uVar3 = *in_stack_00000004;
        uVar8 = (uint)(byte)uVar3;
        in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 1);
        if (uVar8 < 0x10) goto code_r0x0090fc8b;
      }
      else {
LAB_0090fda2:
        if (in_stack_0000000c + ((int)pbVar4 - (int)pbVar11) < pbVar6) break;
        if ((byte *)((int)puVar1 - (int)in_stack_00000004) < pbVar6 + 1) goto LAB_0090ffb6;
        do {
          puVar5 = in_stack_00000004;
          *pbVar11 = (byte)*puVar5;
          pbVar11 = pbVar11 + 1;
          pbVar6 = pbVar6 + -1;
          in_stack_00000004 = (ushort *)((int)puVar5 + 1U);
        } while (pbVar6 != (byte *)0x0);
        uVar8 = (uint)*(byte *)((int)puVar5 + 1U);
        in_stack_00000004 = puVar5 + 1;
        if (puVar1 <= in_stack_00000004) goto LAB_0090fc74;
      }
LAB_0090fddd:
      if (uVar8 < 0x40) {
        if (uVar8 < 0x20) {
          if (uVar8 < 0x10) {
            pbVar6 = pbVar11 + ((uint)(byte)*in_stack_00000004 * -4 - (uVar8 >> 2));
            in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 1);
            if (pbVar6 + -1 < in_stack_0000000c) goto LAB_0090ffe8;
            if (in_stack_0000000c + ((int)pbVar4 - (int)pbVar11) < (byte *)0x2) break;
            *pbVar11 = pbVar6[-1];
            pbVar11[1] = *pbVar6;
            pbVar11 = pbVar11 + 2;
            goto LAB_0090fd91;
          }
          uVar9 = uVar8 & 7;
          if (uVar9 == 0) {
            if (puVar1 == in_stack_00000004) goto LAB_0090ffb6;
            iVar10 = 0;
            bVar2 = (byte)*in_stack_00000004;
            while (bVar2 == 0) {
              in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 1);
              iVar10 = iVar10 + 0xff;
              if (puVar1 == in_stack_00000004) goto LAB_0090ffb6;
              bVar2 = *(byte *)in_stack_00000004;
            }
            uVar9 = iVar10 + 7 + (uint)(byte)*in_stack_00000004;
            in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 1);
          }
          uVar3 = *in_stack_00000004;
          in_stack_00000004 = in_stack_00000004 + 1;
          if (pbVar11 + ((uVar8 & 8) * -0x800 - (uint)(uVar3 >> 2)) == pbVar11) {
            *in_stack_00000010 = (int)pbVar11 - (int)in_stack_0000000c;
            if (in_stack_00000004 != puVar1) {
              return;
            }
            return;
          }
          pbVar6 = pbVar11 + ((uVar8 & 8) * -0x800 - (uint)(uVar3 >> 2)) + -0x4000;
        }
        else {
          uVar9 = uVar8 & 0x1f;
          if (uVar9 == 0) {
            if (puVar1 == in_stack_00000004) goto LAB_0090ffb6;
            iVar10 = 0;
            bVar2 = (byte)*in_stack_00000004;
            while (bVar2 == 0) {
              in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 1);
              iVar10 = iVar10 + 0xff;
              if (puVar1 == in_stack_00000004) goto LAB_0090ffb6;
              bVar2 = *(byte *)in_stack_00000004;
            }
            uVar9 = iVar10 + 0x1f + (uint)(byte)*in_stack_00000004;
            in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 1);
          }
          pbVar6 = pbVar11 + (-1 - (uint)(*in_stack_00000004 >> 2));
          in_stack_00000004 = in_stack_00000004 + 1;
        }
        if (pbVar6 < in_stack_0000000c) goto LAB_0090ffe8;
        if (in_stack_0000000c + ((int)pbVar4 - (int)pbVar11) < (byte *)(uVar9 + 2)) break;
        if ((5 < uVar9) && (3 < (int)pbVar11 - (int)pbVar6)) {
          *(undefined4 *)pbVar11 = *(undefined4 *)pbVar6;
          pbVar11 = pbVar11 + 4;
          pbVar6 = pbVar6 + 4;
          uVar9 = uVar9 - 2;
          do {
            *(undefined4 *)pbVar11 = *(undefined4 *)pbVar6;
            uVar9 = uVar9 - 4;
            pbVar11 = pbVar11 + 4;
            pbVar6 = pbVar6 + 4;
          } while (3 < uVar9);
          for (; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pbVar11 = *pbVar6;
            pbVar11 = pbVar11 + 1;
            pbVar6 = pbVar6 + 1;
          }
          goto LAB_0090fd91;
        }
      }
      else {
        pbVar6 = pbVar11 + ((uint)(byte)*in_stack_00000004 * -8 - (uVar8 >> 2 & 7)) + -1;
        in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 1);
        uVar9 = (uVar8 >> 5) - 1;
        if (pbVar6 < in_stack_0000000c) goto LAB_0090ffe8;
        if (in_stack_0000000c + ((int)pbVar4 - (int)pbVar11) < (byte *)((uVar8 >> 5) + 1)) break;
      }
      *pbVar11 = *pbVar6;
      pbVar11[1] = pbVar6[1];
      pbVar11 = pbVar11 + 2;
      pbVar6 = pbVar6 + 2;
      do {
        *pbVar11 = *pbVar6;
        pbVar11 = pbVar11 + 1;
        pbVar6 = pbVar6 + 1;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    } while( true );
  }
  goto LAB_0090fffe;
code_r0x0090fc8b:
  if (uVar8 == 0) {
    if (puVar1 == in_stack_00000004) goto LAB_0090ffb6;
    iVar10 = 0;
    iVar7 = 0;
    if (*(byte *)in_stack_00000004 == (byte)uVar3) {
      do {
        in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 1);
        iVar10 = iVar10 + 0xff;
        if (puVar1 == in_stack_00000004) goto LAB_0090ffb6;
        iVar7 = iVar10;
      } while (*(byte *)in_stack_00000004 == 0);
    }
    uVar8 = iVar7 + 0xf + (uint)(byte)*in_stack_00000004;
    in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 1);
  }
  if (in_stack_0000000c + ((int)pbVar4 - (int)pbVar11) < (byte *)(uVar8 + 3)) goto LAB_0090fffe;
  if ((uint)((int)puVar1 - (int)in_stack_00000004) < uVar8 + 4) goto LAB_0090ffb6;
  *(undefined4 *)pbVar11 = *(undefined4 *)in_stack_00000004;
  pbVar11 = pbVar11 + 4;
  puVar5 = in_stack_00000004 + 2;
  uVar8 = uVar8 - 1;
  if (uVar8 != 0) {
    if (uVar8 < 4) {
      do {
        *pbVar11 = (byte)*puVar5;
        pbVar11 = pbVar11 + 1;
        puVar5 = (ushort *)((int)puVar5 + 1);
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    else {
      do {
        *(undefined4 *)pbVar11 = *(undefined4 *)puVar5;
        uVar8 = uVar8 - 4;
        pbVar11 = pbVar11 + 4;
        puVar5 = puVar5 + 2;
      } while (3 < uVar8);
      for (; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pbVar11 = (byte)*puVar5;
        pbVar11 = pbVar11 + 1;
        puVar5 = (ushort *)((int)puVar5 + 1);
      }
    }
  }
  goto LAB_0090fd30;
}
}

// =================================================
// Function: md5_process
// =================================================
void __cdecl md5_process(void)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *in_EAX;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int *piVar23;
  int in_stack_00000004;
  int local_40 [16];
  
  iVar1 = *(int *)(in_stack_00000004 + 8);
  uVar20 = *(uint *)(in_stack_00000004 + 0xc);
  uVar21 = *(uint *)(in_stack_00000004 + 0x10);
  uVar18 = *(uint *)(in_stack_00000004 + 0x14);
  if (((uint)in_EAX & 3) != 0) {
    piVar23 = local_40;
    for (iVar16 = 0x10; iVar16 != 0; iVar16 = iVar16 + -1) {
      *piVar23 = *in_EAX;
      in_EAX = in_EAX + 1;
      piVar23 = piVar23 + 1;
    }
    in_EAX = local_40;
  }
  iVar16 = *in_EAX;
  uVar17 = (~uVar20 & uVar18 | uVar21 & uVar20) + iVar16 + -0x28955b88 + iVar1;
  iVar1 = in_EAX[1];
  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar20;
  uVar18 = (~uVar17 & uVar21 | uVar20 & uVar17) + iVar1 + -0x173848aa + uVar18;
  iVar2 = in_EAX[2];
  uVar18 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar17;
  iVar3 = in_EAX[3];
  uVar21 = (~uVar18 & uVar20 | uVar18 & uVar17) + iVar2 + 0x242070db + uVar21;
  uVar21 = (uVar21 >> 0xf | uVar21 * 0x20000) + uVar18;
  uVar20 = (~uVar21 & uVar17 | uVar18 & uVar21) + iVar3 + -0x3e423112 + uVar20;
  iVar4 = in_EAX[4];
  uVar20 = (uVar20 >> 10 | uVar20 * 0x400000) + uVar21;
  uVar17 = (~uVar20 & uVar18 | uVar21 & uVar20) + iVar4 + -0xa83f051 + uVar17;
  iVar5 = in_EAX[5];
  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar20;
  uVar18 = (~uVar17 & uVar21 | uVar20 & uVar17) + iVar5 + 0x4787c62a + uVar18;
  iVar6 = in_EAX[6];
  uVar18 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar17;
  uVar21 = (~uVar18 & uVar20 | uVar18 & uVar17) + iVar6 + -0x57cfb9ed + uVar21;
  iVar7 = in_EAX[7];
  uVar21 = (uVar21 >> 0xf | uVar21 * 0x20000) + uVar18;
  uVar20 = (~uVar21 & uVar17 | uVar18 & uVar21) + iVar7 + -0x2b96aff + uVar20;
  iVar8 = in_EAX[8];
  uVar20 = (uVar20 >> 10 | uVar20 * 0x400000) + uVar21;
  iVar9 = in_EAX[9];
  uVar17 = (~uVar20 & uVar18 | uVar21 & uVar20) + iVar8 + 0x698098d8 + uVar17;
  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar20;
  uVar18 = (~uVar17 & uVar21 | uVar20 & uVar17) + iVar9 + -0x74bb0851 + uVar18;
  iVar10 = in_EAX[10];
  uVar18 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar17;
  uVar21 = (~uVar18 & uVar20 | uVar18 & uVar17) + iVar10 + -0xa44f + uVar21;
  iVar11 = in_EAX[0xb];
  uVar22 = (uVar21 >> 0xf | uVar21 * 0x20000) + uVar18;
  uVar20 = (~uVar22 & uVar17 | uVar18 & uVar22) + iVar11 + -0x76a32842 + uVar20;
  iVar12 = in_EAX[0xc];
  uVar21 = (uVar20 >> 10 | uVar20 * 0x400000) + uVar22;
  uVar17 = (~uVar21 & uVar18 | uVar22 & uVar21) + iVar12 + 0x6b901122 + uVar17;
  iVar13 = in_EAX[0xd];
  uVar20 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar21;
  uVar18 = (~uVar20 & uVar22 | uVar21 & uVar20) + iVar13 + -0x2678e6d + uVar18;
  uVar19 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar20;
  iVar14 = in_EAX[0xe];
  iVar15 = in_EAX[0xf];
  uVar18 = uVar22 + 0xa679438e + (~uVar19 & uVar21 | uVar19 & uVar20) + iVar14;
  uVar17 = (uVar18 >> 0xf | uVar18 * 0x20000) + uVar19;
  uVar21 = (~uVar17 & uVar20 | uVar19 & uVar17) + iVar15 + 0x49b40821 + uVar21;
  uVar21 = (uVar21 >> 10 | uVar21 * 0x400000) + uVar17;
  uVar20 = (~uVar19 & uVar17 | uVar19 & uVar21) + iVar1 + -0x9e1da9e + uVar20;
  uVar20 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar21;
  uVar18 = uVar19 + 0xc040b340 + (~uVar17 & uVar21 | uVar17 & uVar20) + iVar6;
  uVar18 = (uVar18 * 0x200 | uVar18 >> 0x17) + uVar20;
  uVar17 = (~uVar21 & uVar20 | uVar18 & uVar21) + iVar11 + 0x265e5a51 + uVar17;
  uVar17 = (uVar17 * 0x4000 | uVar17 >> 0x12) + uVar18;
  uVar21 = (~uVar20 & uVar18 | uVar17 & uVar20) + iVar16 + -0x16493856 + uVar21;
  uVar21 = (uVar21 >> 0xc | uVar21 * 0x100000) + uVar17;
  uVar20 = (~uVar18 & uVar17 | uVar18 & uVar21) + iVar5 + -0x29d0efa3 + uVar20;
  uVar20 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar21;
  uVar18 = (~uVar17 & uVar21 | uVar17 & uVar20) + iVar10 + 0x2441453 + uVar18;
  uVar18 = (uVar18 * 0x200 | uVar18 >> 0x17) + uVar20;
  uVar17 = (~uVar21 & uVar20 | uVar18 & uVar21) + iVar15 + -0x275e197f + uVar17;
  uVar17 = (uVar17 * 0x4000 | uVar17 >> 0x12) + uVar18;
  uVar21 = (~uVar20 & uVar18 | uVar17 & uVar20) + iVar4 + -0x182c0438 + uVar21;
  uVar21 = (uVar21 >> 0xc | uVar21 * 0x100000) + uVar17;
  uVar20 = (~uVar18 & uVar17 | uVar18 & uVar21) + iVar9 + 0x21e1cde6 + uVar20;
  uVar20 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar21;
  uVar18 = (~uVar17 & uVar21 | uVar17 & uVar20) + iVar14 + -0x3cc8f82a + uVar18;
  uVar18 = (uVar18 * 0x200 | uVar18 >> 0x17) + uVar20;
  uVar17 = (~uVar21 & uVar20 | uVar18 & uVar21) + iVar3 + -0xb2af279 + uVar17;
  uVar17 = (uVar17 * 0x4000 | uVar17 >> 0x12) + uVar18;
  uVar21 = (~uVar20 & uVar18 | uVar17 & uVar20) + iVar8 + 0x455a14ed + uVar21;
  uVar21 = (uVar21 >> 0xc | uVar21 * 0x100000) + uVar17;
  uVar20 = (~uVar18 & uVar17 | uVar18 & uVar21) + iVar13 + -0x561c16fb + uVar20;
  uVar20 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar21;
  uVar18 = (~uVar17 & uVar21 | uVar17 & uVar20) + iVar2 + -0x3105c08 + uVar18;
  uVar18 = (uVar18 * 0x200 | uVar18 >> 0x17) + uVar20;
  uVar17 = (~uVar21 & uVar20 | uVar18 & uVar21) + iVar7 + 0x676f02d9 + uVar17;
  uVar17 = (uVar17 * 0x4000 | uVar17 >> 0x12) + uVar18;
  uVar21 = (~uVar20 & uVar18 | uVar17 & uVar20) + iVar12 + -0x72d5b376 + uVar21;
  uVar21 = (uVar21 >> 0xc | uVar21 * 0x100000) + uVar17;
  uVar20 = (uVar18 ^ uVar17 ^ uVar21) + iVar5 + -0x5c6be + uVar20;
  uVar20 = (uVar20 * 0x10 | uVar20 >> 0x1c) + uVar21;
  uVar18 = (uVar17 ^ uVar21 ^ uVar20) + iVar8 + -0x788e097f + uVar18;
  uVar18 = (uVar18 * 0x800 | uVar18 >> 0x15) + uVar20;
  uVar17 = (uVar18 ^ uVar21 ^ uVar20) + iVar11 + 0x6d9d6122 + uVar17;
  uVar17 = (uVar17 * 0x10000 | uVar17 >> 0x10) + uVar18;
  uVar21 = (uVar18 ^ uVar17 ^ uVar20) + iVar14 + -0x21ac7f4 + uVar21;
  uVar21 = (uVar21 >> 9 | uVar21 * 0x800000) + uVar17;
  uVar20 = (uVar18 ^ uVar17 ^ uVar21) + iVar1 + -0x5b4115bc + uVar20;
  uVar20 = (uVar20 * 0x10 | uVar20 >> 0x1c) + uVar21;
  uVar18 = (uVar17 ^ uVar21 ^ uVar20) + iVar4 + 0x4bdecfa9 + uVar18;
  uVar18 = (uVar18 * 0x800 | uVar18 >> 0x15) + uVar20;
  uVar17 = (uVar18 ^ uVar21 ^ uVar20) + iVar7 + -0x944b4a0 + uVar17;
  uVar17 = (uVar17 * 0x10000 | uVar17 >> 0x10) + uVar18;
  uVar21 = (uVar18 ^ uVar17 ^ uVar20) + iVar10 + -0x41404390 + uVar21;
  uVar21 = (uVar21 >> 9 | uVar21 * 0x800000) + uVar17;
  uVar20 = (uVar18 ^ uVar17 ^ uVar21) + iVar13 + 0x289b7ec6 + uVar20;
  uVar20 = (uVar20 * 0x10 | uVar20 >> 0x1c) + uVar21;
  uVar18 = (uVar17 ^ uVar21 ^ uVar20) + iVar16 + -0x155ed806 + uVar18;
  uVar18 = (uVar18 * 0x800 | uVar18 >> 0x15) + uVar20;
  uVar17 = (uVar18 ^ uVar21 ^ uVar20) + iVar3 + -0x2b10cf7b + uVar17;
  uVar17 = (uVar17 * 0x10000 | uVar17 >> 0x10) + uVar18;
  uVar21 = (uVar18 ^ uVar17 ^ uVar20) + iVar6 + 0x4881d05 + uVar21;
  uVar21 = (uVar21 >> 9 | uVar21 * 0x800000) + uVar17;
  uVar20 = (uVar18 ^ uVar17 ^ uVar21) + iVar9 + -0x262b2fc7 + uVar20;
  uVar20 = (uVar20 * 0x10 | uVar20 >> 0x1c) + uVar21;
  uVar18 = (uVar17 ^ uVar21 ^ uVar20) + iVar12 + -0x1924661b + uVar18;
  uVar18 = (uVar18 * 0x800 | uVar18 >> 0x15) + uVar20;
  uVar17 = (uVar18 ^ uVar21 ^ uVar20) + iVar15 + 0x1fa27cf8 + uVar17;
  uVar17 = (uVar17 * 0x10000 | uVar17 >> 0x10) + uVar18;
  uVar21 = (uVar18 ^ uVar17 ^ uVar20) + iVar2 + -0x3b53a99b + uVar21;
  uVar21 = (uVar21 >> 9 | uVar21 * 0x800000) + uVar17;
  uVar20 = ((~uVar18 | uVar21) ^ uVar17) + iVar16 + -0xbd6ddbc + uVar20;
  uVar20 = (uVar20 * 0x40 | uVar20 >> 0x1a) + uVar21;
  uVar18 = ((~uVar17 | uVar20) ^ uVar21) + iVar7 + 0x432aff97 + uVar18;
  uVar18 = (uVar18 * 0x400 | uVar18 >> 0x16) + uVar20;
  uVar17 = ((~uVar21 | uVar18) ^ uVar20) + iVar14 + -0x546bdc59 + uVar17;
  uVar17 = (uVar17 * 0x8000 | uVar17 >> 0x11) + uVar18;
  uVar21 = ((~uVar20 | uVar17) ^ uVar18) + iVar5 + -0x36c5fc7 + uVar21;
  uVar21 = (uVar21 >> 0xb | uVar21 * 0x200000) + uVar17;
  uVar20 = ((~uVar18 | uVar21) ^ uVar17) + iVar12 + 0x655b59c3 + uVar20;
  uVar20 = (uVar20 * 0x40 | uVar20 >> 0x1a) + uVar21;
  uVar18 = ((~uVar17 | uVar20) ^ uVar21) + iVar3 + -0x70f3336e + uVar18;
  uVar18 = (uVar18 * 0x400 | uVar18 >> 0x16) + uVar20;
  uVar17 = ((~uVar21 | uVar18) ^ uVar20) + iVar10 + -0x100b83 + uVar17;
  uVar17 = (uVar17 * 0x8000 | uVar17 >> 0x11) + uVar18;
  uVar21 = ((~uVar20 | uVar17) ^ uVar18) + iVar1 + -0x7a7ba22f + uVar21;
  uVar21 = (uVar21 >> 0xb | uVar21 * 0x200000) + uVar17;
  uVar20 = ((~uVar18 | uVar21) ^ uVar17) + iVar8 + 0x6fa87e4f + uVar20;
  uVar20 = (uVar20 * 0x40 | uVar20 >> 0x1a) + uVar21;
  uVar18 = ((~uVar17 | uVar20) ^ uVar21) + iVar15 + -0x1d31920 + uVar18;
  uVar18 = (uVar18 * 0x400 | uVar18 >> 0x16) + uVar20;
  uVar17 = ((~uVar21 | uVar18) ^ uVar20) + iVar6 + -0x5cfebcec + uVar17;
  uVar17 = (uVar17 * 0x8000 | uVar17 >> 0x11) + uVar18;
  uVar21 = ((~uVar20 | uVar17) ^ uVar18) + iVar13 + 0x4e0811a1 + uVar21;
  uVar21 = (uVar21 >> 0xb | uVar21 * 0x200000) + uVar17;
  uVar20 = ((~uVar18 | uVar21) ^ uVar17) + iVar4 + -0x8ac817e + uVar20;
  uVar20 = (uVar20 * 0x40 | uVar20 >> 0x1a) + uVar21;
  uVar18 = ((~uVar17 | uVar20) ^ uVar21) + iVar11 + -0x42c50dcb + uVar18;
  uVar18 = (uVar18 * 0x400 | uVar18 >> 0x16) + uVar20;
  uVar17 = ((~uVar21 | uVar18) ^ uVar20) + iVar2 + 0x2ad7d2bb + uVar17;
  uVar17 = (uVar17 * 0x8000 | uVar17 >> 0x11) + uVar18;
  uVar21 = ((~uVar20 | uVar17) ^ uVar18) + iVar9 + -0x14792c6f + uVar21;
  *(uint *)(in_stack_00000004 + 0x10) = *(int *)(in_stack_00000004 + 0x10) + uVar17;
  *(uint *)(in_stack_00000004 + 8) = *(int *)(in_stack_00000004 + 8) + uVar20;
  *(uint *)(in_stack_00000004 + 0xc) =
       (uVar21 >> 0xb | uVar21 * 0x200000) + *(int *)(in_stack_00000004 + 0xc) + uVar17;
  *(uint *)(in_stack_00000004 + 0x14) = *(int *)(in_stack_00000004 + 0x14) + uVar18;
  return;
}
}

// =================================================
// Function: operator_delete
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl operator_delete(void *param_1)
{
{
  int iVar1;
  BOOL BVar2;
  int *piVar3;
  DWORD DVar4;
  
  if (param_1 != (void *)0x0) {
    if (DAT_00d7aec0 == 3) {
      __lock(4);
      iVar1 = thunk____sbh_find_block(param_1);
      if (iVar1 != 0) {
        ___sbh_free_block();
      }
      FUN_00405bac();
      if (iVar1 != 0) {
        return;
      }
    }
    BVar2 = HeapFree(hHeap_00d53f34,0,param_1);
    if (BVar2 == 0) {
      piVar3 = __errno();
      DVar4 = GetLastError();
      iVar1 = __get_errno_from_oserr(DVar4);
      *piVar3 = iVar1;
    }
  }
  return;
}
}

// =================================================
// Function: operator_delete__
// =================================================
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl operator_delete__(void *param_1)
{
{
  int iVar1;
  BOOL BVar2;
  int *piVar3;
  DWORD DVar4;
  
  if (param_1 != (void *)0x0) {
    if (DAT_00d7aec0 == 3) {
      __lock(4);
      iVar1 = thunk____sbh_find_block(param_1);
      if (iVar1 != 0) {
        ___sbh_free_block();
      }
      FUN_00405bac();
      if (iVar1 != 0) {
        return;
      }
    }
    BVar2 = HeapFree(hHeap_00d53f34,0,param_1);
    if (BVar2 == 0) {
      piVar3 = __errno();
      DVar4 = GetLastError();
      iVar1 = __get_errno_from_oserr(DVar4);
      *piVar3 = iVar1;
    }
  }
  return;
}
}

// =================================================
// Function: operator_new
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * __cdecl operator_new(uint param_1)
{
{
  int iVar1;
  void *pvVar2;
  bad_alloc *in_stack_fffffff0;
  
  do {
    pvVar2 = _malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    iVar1 = __callnewh(param_1);
  } while (iVar1 != 0);
  if ((_DAT_00d53758 & 1) == 0) {
    _DAT_00d53758 = _DAT_00d53758 | 1;
    std::bad_alloc::bad_alloc((bad_alloc *)&DAT_00d5374c,in_stack_fffffff0);
    _atexit(`void*___cdecl_operator_new(unsigned_int)'::__l6::
            _dynamic_atexit_destructor_for__nomem__);
  }
  std::exception::exception((exception *)&stack0xfffffff0,(exception *)&DAT_00d5374c);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8();
}
}

// =================================================
// Function: operator_new__
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c136d) overlaps instruction at (ram,0x009c136a)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * __cdecl operator_new__(uint param_1)
{
{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  longlong lVar5;
  code *pcVar6;
  byte bVar7;
  char cVar8;
  char cVar9;
  char cVar17;
  int *piVar12;
  uint *puVar13;
  int *piVar14;
  uint uVar15;
  undefined3 uVar18;
  undefined2 extraout_CX;
  undefined2 uVar19;
  char *in_EDX;
  uint *puVar21;
  uint unaff_ESI;
  uint *unaff_EDI;
  undefined1 *puVar22;
  byte *pbVar23;
  undefined2 in_SS;
  char in_CF;
  byte in_AF;
  byte bVar24;
  undefined2 in_FPUControlWord;
  undefined8 uVar25;
  uint unaff_retaddr;
  int *in_stack_0000000c;
  uint in_stack_00000010;
  uint *in_stack_00000014;
  int *in_stack_00000018;
  uint uVar10;
  int *piVar11;
  char *pcVar16;
  byte bVar20;
  
  puVar13 = _DAT_36293612;
  cVar17 = *in_EDX;
  *(uint *)(unaff_ESI ^ *unaff_EDI) = *(uint *)(unaff_ESI ^ *unaff_EDI) ^ 0x36ba3692;
  *(char *)unaff_EDI = (char)*unaff_EDI + (char)((uint)in_EDX >> 8) + cVar17 + in_CF;
  bVar24 = 9 < ((byte)in_stack_00000018 & 0xf) | in_AF;
  uVar10 = CONCAT31((int3)((uint)in_stack_00000018 >> 8),(byte)in_stack_00000018 + bVar24 * '\x06')
           & 0xffffff0f;
  bVar7 = (byte)uVar10;
  cVar17 = (char)((uint)in_stack_00000018 >> 8) + bVar24;
  piVar11 = (int *)CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar17,bVar7));
  uVar18 = (undefined3)((uint)piVar11 >> 8);
  piVar14 = in_stack_0000000c;
  if ((bool)bVar24) {
    *puVar13 = *puVar13 ^ 0x380a379a;
    in_stack_00000018 = in_stack_0000000c;
    *piVar11 = *piVar11 >> 0x17;
    if ((int)unaff_retaddr <= in_stack_0000000c[0xf]) {
      if (in_stack_00000014 == (uint *)0x0) goto code_r0x009c123d;
      cVar8 = (char)((short)in_stack_0000000c / (short)*(char *)(in_stack_00000010 + (int)puVar13));
      uVar10 = CONCAT22((short)((uint)in_stack_0000000c >> 0x10),
                        CONCAT11((char)((short)in_stack_0000000c %
                                       (short)*(char *)(in_stack_00000010 + (int)puVar13)),cVar8));
      if (in_stack_00000014 != (uint *)0x1 && uVar10 == 0x3d803d73) {
        piVar14 = (int *)CONCAT31((int3)(uVar10 >> 8),cVar8 + '6' + (uVar10 < 0x3d803d73));
        bVar24 = 9 < (DAT_17370136 & 0xf) | bVar24;
        uVar10 = CONCAT31(uVar18,DAT_17370136 + bVar24 * '\x06') & 0xffffff0f;
        piVar12 = (int *)CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar17 + bVar24,(char)uVar10));
        in_stack_00000010 =
             (uint)CONCAT11((byte)((uint)in_stack_0000000c >> 8) ^ (byte)*puVar13,
                            (char)in_stack_0000000c);
        *(undefined1 *)puVar13 = 0;
        goto LAB_009c1257;
      }
      lVar5 = CONCAT44(in_stack_00000010,uVar10);
      in_stack_00000010 = (uint)(lVar5 % (longlong)_DAT_3e833e12);
      piVar14 = (int *)(lVar5 / (longlong)_DAT_3e833e12);
      goto code_r0x009c120f;
    }
  }
  else {
code_r0x009c120f:
    in_stack_00000014 = (uint *)&DAT_3a3ec83e;
    bVar24 = 9 < bVar7 | bVar24;
    uVar10 = CONCAT31(uVar18,bVar7 + bVar24 * -6) & 0xffffff0f;
    piVar12 = (int *)CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar17 - bVar24,(char)uVar10));
    in_stack_0000000c = piVar12;
    piVar11 = piVar14;
    if (!(bool)bVar24) {
LAB_009c1257:
      bVar24 = 9 < (byte)piVar12 | bVar24;
      uVar10 = CONCAT31((int3)((uint)piVar12 >> 8),(byte)piVar12 + bVar24 * '\x06') & 0xffffff0f;
      puVar21 = (uint *)CONCAT22((short)(uVar10 >> 0x10),
                                 CONCAT11((char)((uint)piVar12 >> 8) + bVar24,(char)uVar10));
      puVar22 = (undefined1 *)((uint)puVar13 ^ *puVar21);
      segment(in_SS,(short)param_1 + (short)(undefined1 *)(unaff_retaddr + 1) + 0x39);
      *puVar22 = *(undefined1 *)(unaff_retaddr + 1);
      uVar1 = in((short)in_stack_00000010);
      puVar22[1] = uVar1;
      if (SBORROW4((int)puVar21,0x3e653e37)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      pcVar6 = (code *)swi(0x3e);
      uVar25 = (*pcVar6)();
      piVar11 = (int *)uVar25;
      *(undefined2 *)(unaff_retaddr + 2) = in_FPUControlWord;
      puVar3 = *(undefined4 **)(puVar22 + 2);
      *(byte *)piVar11 = (char)*piVar11 + (byte)uVar25;
      *(char *)piVar11 = (char)*piVar11 + (char)((ulonglong)uVar25 >> 0x28);
      in_stack_00000018[-1] = (int)((ulonglong)uVar25 >> 0x20);
      pcVar16 = (char *)((int)piVar11 * 2 + 0x30c40000);
      *pcVar16 = *pcVar16 + (char)((ulonglong)uVar25 >> 8);
      *piVar11 = *piVar11 << ((byte)extraout_CX & 0x1f);
      puVar13 = (uint *)in_stack_00000018[-1];
      *(uint *)((int)piVar14 + 0x31) = *(uint *)((int)piVar14 + 0x31) ^ (uint)in_stack_00000018;
      uVar10 = *puVar13;
      puVar21 = (uint *)((int)piVar14 + 1);
      bVar7 = *(byte *)((int)puVar13 + 0x32);
      puVar2 = puVar3 + 1;
      *puVar3 = piVar11;
      bVar20 = (byte)((uint)puVar13 >> 8) ^ *(byte *)(piVar14 + 0xd);
      uVar19 = CONCAT11(bVar20,(char)puVar13);
      pbVar23 = (byte *)CONCAT22((short)((uint)puVar13 >> 0x10),uVar19);
      *puVar21 = *puVar21 ^ 0xffffff9c;
      uVar4 = *puVar21;
      uVar15 = CONCAT31((int3)((ulonglong)uVar25 >> 8),
                        (byte)uVar25 ^ (byte)((ushort)extraout_CX >> 8) ^ bVar7) ^ 0x35f0355d;
      in_stack_00000018[-1] = (int)puVar21;
      in_stack_00000018[-2] = (unaff_retaddr + 2 ^ uVar10 ^ (uint)puVar2 ^ uVar4) + 1;
      uVar18 = (undefined3)(uVar15 >> 8);
      bVar7 = (byte)uVar15;
      cVar8 = (char)((uint)puVar21 >> 8);
      cVar17 = (char)(uVar15 >> 8);
      if ((POPCOUNT(uVar15 + 0xc28cc29a & 0xff) & 1U) == 0) {
        if (uVar15 + 0xc28cc29a == 0 || (int)uVar15 < 0x3d733d66) {
          out(uVar19,bVar7);
          bVar24 = 9 < (bVar7 & 0xf) | bVar24;
          uVar10 = CONCAT31(uVar18,bVar7 + bVar24 * -6) & 0xffffff0f;
          cVar9 = (char)uVar10;
          pcVar16 = (char *)CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar17 - bVar24,cVar9));
          pcVar16[0x52] = pcVar16[0x52] + cVar9;
          *pcVar16 = *pcVar16 + cVar8;
          *pcVar16 = *pcVar16 + cVar9;
          pbVar23 = (byte *)((uint)puVar2 ^ (uint)puVar21);
          *pbVar23 = *pbVar23 - (bVar20 & *pbVar23);
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
      else {
        bVar24 = 9 < (bVar7 & 0xf) | bVar24;
        uVar10 = CONCAT31(uVar18,bVar7 + bVar24 * '\x06') & 0xffffff0f;
        uRamf439b539 = CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar17 + bVar24,(char)uVar10));
      }
      *pbVar23 = *pbVar23 ^ cVar8 - *pbVar23;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  bVar24 = 9 < ((byte)in_stack_0000000c & 0xf) | bVar24;
  uVar10 = CONCAT31((int3)((uint)in_stack_0000000c >> 8),(byte)in_stack_0000000c + bVar24 * -6) &
           0xffffff0f;
  lVar5 = CONCAT44(in_stack_00000010,
                   CONCAT22((short)(uVar10 >> 0x10),
                            CONCAT11((char)((uint)in_stack_0000000c >> 8) - bVar24,(char)uVar10))) /
          (longlong)(int)*puVar13;
  puVar13 = (uint *)lVar5;
  *(char *)puVar13 = (char)*puVar13 + (char)lVar5;
  *(char *)puVar13 = (char)*puVar13 + (char)((ulonglong)lVar5 >> 8);
  *(char *)((int)puVar13 * 2) = *(char *)((int)puVar13 * 2) + (char)((uint)piVar11 >> 8);
  DAT_74306330 = DAT_74306330 + (char)piVar11;
  *(byte *)(param_1 + 0x2330fc30) = *(byte *)(param_1 + 0x2330fc30) ^ (byte)in_stack_00000014;
  *puVar13 = *puVar13 ^ unaff_retaddr;
  *in_stack_00000014 = *in_stack_00000014 ^ (uint)puVar13;
  in_stack_0000000c = (int *)((uint)puVar13 ^ 0x11);
code_r0x009c123d:
  return (void *)((uint)in_stack_0000000c ^ 0x35b03543);
}
}

// =================================================
// Function: sBufferMemoryFree
// =================================================
void __cdecl sBufferMemoryFree(CClassicBufferMemory **param_1)
{
{
  uint uVar1;
  TiXmlAttribute *unaff_ESI;
  
  if (*param_1 != (CClassicBufferMemory *)0x0) {
    uVar1 = (**(code **)(*(int *)*param_1 + 0x2c))();
    if (uVar1 < 0x100000) {
      CFastBuffer<class_CDx9TextureKeeper*>::Add
                (&DAT_00d72ea0,(TiXmlAttributeSet *)param_1,unaff_ESI);
    }
    else if (*param_1 != (CClassicBufferMemory *)0x0) {
      (*(code *)**(undefined4 **)*param_1)(1);
      *param_1 = (CClassicBufferMemory *)0x0;
      return;
    }
    *param_1 = (CClassicBufferMemory *)0x0;
  }
  return;
}
}

// =================================================
// Function: sBufferMemoryGetNew
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CClassicBufferMemory * __cdecl sBufferMemoryGetNew(void)
{
{
  ulong uVar1;
  SNewTriangleVert *pSVar2;
  CClassicBufferMemory *extraout_EAX;
  CClassicBufferMemory *pCVar3;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_ESI;
  void *unaff_retaddr;
  CClassicBufferMemory *extraout_var;
  CClassicBufferMemory *pCVar4;
  CClassicBufferMemory *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ae1c4b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (&DAT_00d72ea0,
                     (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  if (uVar1 != 0) {
    pCVar4 = extraout_var;
    pSVar2 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(&DAT_00d72ea0,unaff_ESI);
    pCVar3 = *(CClassicBufferMemory **)pSVar2;
    CClassicBufferMemory::Empty(pCVar3,pCVar4);
    _DAT_00d72ea0 = _DAT_00d72ea0 + -1;
    ExceptionList = unaff_retaddr;
    return pCVar3;
  }
  local_c = operator_new(0x20);
  if (local_c == (CClassicBufferMemory *)0x0) {
    pCVar3 = (CClassicBufferMemory *)0x0;
  }
  else {
    CClassicBufferMemory::CClassicBufferMemory(local_c,(CClassicBufferMemory *)unaff_ESI);
    pCVar3 = extraout_EAX;
  }
  ExceptionList = local_4;
  return pCVar3;
}
}

// =================================================
// Function: sprintf_s<128>
// =================================================
int __cdecl sprintf_s<128>(char *param_1,char *param_2)
{
{
  int iVar1;
  
  iVar1 = _vsprintf_s(param_1,0x80,param_2,&stack0x0000000c);
  return iVar1;
}
}

// =================================================
// Function: sprintf_s<16>
// =================================================
int __cdecl sprintf_s<16>(char *param_1,char *param_2)
{
{
  int iVar1;
  
  iVar1 = _vsprintf_s(param_1,0x10,param_2,&stack0x0000000c);
  return iVar1;
}
}

// =================================================
// Function: sprintf_s<256>
// =================================================
int __cdecl sprintf_s<256>(char *param_1,char *param_2)
{
{
  int iVar1;
  
  iVar1 = _vsprintf_s(param_1,0x100,param_2,&stack0x0000000c);
  return iVar1;
}
}

// =================================================
// Function: sprintf_s<25>
// =================================================
int __cdecl sprintf_s<25>(char *param_1,char *param_2)
{
{
  int iVar1;
  
  iVar1 = _vsprintf_s(param_1,0x19,param_2,&stack0x0000000c);
  return iVar1;
}
}

// =================================================
// Function: sprintf_s<32>
// =================================================
int __cdecl sprintf_s<32>(char *param_1,char *param_2)
{
{
  int iVar1;
  
  iVar1 = _vsprintf_s(param_1,0x20,param_2,&stack0x0000000c);
  return iVar1;
}
}

// =================================================
// Function: sprintf_s<4096>
// =================================================
int __cdecl sprintf_s<4096>(char *param_1,char *param_2)
{
{
  int iVar1;
  
  iVar1 = _vsprintf_s(param_1,0x1000,param_2,&stack0x0000000c);
  return iVar1;
}
}

// =================================================
// Function: sprintf_s<512>
// =================================================
int __cdecl sprintf_s<512>(char *param_1,char *param_2)
{
{
  int iVar1;
  
  iVar1 = _vsprintf_s(param_1,0x200,param_2,&stack0x0000000c);
  return iVar1;
}
}

// =================================================
// Function: sprintf_s<8>
// =================================================
int __cdecl sprintf_s<8>(char *param_1,char *param_2)
{
{
  int iVar1;
  
  iVar1 = _vsprintf_s(param_1,8,param_2,&stack0x0000000c);
  return iVar1;
}
}

// =================================================
// Function: static_md5_append
// =================================================
void __cdecl static_md5_append(md5_state_s *param_1,uchar *param_2,int param_3)
{
{
  uint in_EAX;
  uint *in_ECX;
  uint uVar1;
  uint uVar2;
  
  uVar2 = *in_ECX >> 3 & 0x3f;
  if (0 < (int)in_EAX) {
    *in_ECX = *in_ECX + in_EAX * 8;
    in_ECX[1] = in_ECX[1] + ((int)in_EAX >> 0x1d);
    if (*in_ECX < in_EAX * 8) {
      in_ECX[1] = in_ECX[1] + 1;
    }
    if (uVar2 != 0) {
      uVar1 = in_EAX;
      if (0x40 < (int)(uVar2 + in_EAX)) {
        uVar1 = 0x40 - uVar2;
      }
      _memcpy((void *)(uVar2 + 0x18 + (int)in_ECX),param_1,uVar1);
      if ((int)(uVar2 + uVar1) < 0x40) {
        return;
      }
      param_1 = param_1 + uVar1;
      in_EAX = in_EAX - uVar1;
      md5_process();
    }
    if (0x3f < (int)in_EAX) {
      uVar2 = in_EAX >> 6;
      in_EAX = in_EAX + uVar2 * -0x40;
      do {
        md5_process();
        param_1 = param_1 + 0x40;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if (in_EAX != 0) {
      _memcpy(in_ECX + 6,param_1,in_EAX);
    }
  }
  return;
}
}

// =================================================
// Function: static_md5_finish
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl static_md5_finish(void)
{
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  uchar *puVar4;
  uchar *puVar5;
  
  puVar5 = (uchar *)*unaff_ESI;
  puVar4 = &DAT_00bc3538;
  static_md5_append((md5_state_s *)&DAT_00bc3538,puVar5,unaff_ESI[1]);
  static_md5_append((md5_state_s *)&stack0xfffffff4,puVar4,(int)puVar5);
  iVar2 = 0;
  do {
    bVar1 = (byte)iVar2;
    iVar3 = iVar2 >> 2;
    iVar2 = iVar2 + 1;
    *(char *)(unaff_EDI + -1 + iVar2) = (char)((uint)unaff_ESI[iVar3 + 2] >> (bVar1 & 3) * '\b');
  } while (iVar2 < 0x10);
  return;
}
}

// =================================================
// Function: static_md5_init
// =================================================
void __cdecl static_md5_init(void)
{
{
  undefined4 *in_EAX;
  
  in_EAX[1] = 0;
  *in_EAX = 0;
  in_EAX[2] = 0x67452301;
  in_EAX[3] = 0xefcdab89;
  in_EAX[4] = 0x98badcfe;
  in_EAX[5] = 0x10325476;
  return;
}
}

// =================================================
// Function: strtoxl
// =================================================
ulong __cdecl
strtoxl(localeinfo_struct *param_1,char *param_2,char **param_3,int param_4,int param_5)
{
{
  ushort uVar1;
  byte *pbVar2;
  int *piVar3;
  uint uVar4;
  threadlocaleinfostruct *ptVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  localeinfo_struct *unaff_EDI;
  byte *pbVar9;
  localeinfo_struct local_18;
  int local_10;
  char local_c;
  uint local_8;
  
  _LocaleUpdate::_LocaleUpdate(&local_18,(_LocaleUpdate *)param_1,unaff_EDI);
  if (param_3 != (char **)0x0) {
    *param_3 = param_2;
  }
  if ((param_2 == (char *)0x0) || ((param_4 != 0 && ((param_4 < 2 || (0x24 < param_4)))))) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    __invalid_parameter();
    if (local_c != '\0') {
      *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
    }
    return 0;
  }
  bVar8 = *param_2;
  local_8 = 0;
  ptVar5 = local_18.locinfo;
  pbVar2 = (byte *)param_2;
  while( true ) {
    pbVar9 = pbVar2 + 1;
    if ((int)ptVar5->locale_name[3] < 2) {
      uVar4 = (byte)ptVar5[1].lc_category[0].locale[(uint)bVar8 * 2] & 8;
    }
    else {
      uVar4 = __isctype_l((uint)bVar8,8,&local_18);
      ptVar5 = local_18.locinfo;
    }
    if (uVar4 == 0) break;
    bVar8 = *pbVar9;
    pbVar2 = pbVar9;
  }
  if (bVar8 == 0x2d) {
    param_5 = param_5 | 2;
LAB_0041482a:
    bVar8 = *pbVar9;
    pbVar9 = pbVar2 + 2;
  }
  else if (bVar8 == 0x2b) goto LAB_0041482a;
  if (((param_4 < 0) || (param_4 == 1)) || (0x24 < param_4)) {
    if (param_3 != (char **)0x0) {
      *param_3 = param_2;
    }
    if (local_c != '\0') {
      *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
    }
    return 0;
  }
  if (param_4 == 0) {
    if (bVar8 != 0x30) {
      param_4 = 10;
      goto LAB_00414890;
    }
    if ((*pbVar9 != 0x78) && (*pbVar9 != 0x58)) {
      param_4 = 8;
      goto LAB_00414890;
    }
    param_4 = 0x10;
  }
  else if ((param_4 != 0x10) || (bVar8 != 0x30)) goto LAB_00414890;
  if ((*pbVar9 == 0x78) || (*pbVar9 == 0x58)) {
    bVar8 = pbVar9[1];
    pbVar9 = pbVar9 + 2;
  }
LAB_00414890:
  uVar4 = (uint)(0xffffffff / (ulonglong)(uint)param_4);
  do {
    uVar1 = *(ushort *)(ptVar5[1].lc_category[0].locale + (uint)bVar8 * 2);
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 0x103) == 0) {
LAB_004148ea:
        pbVar9 = pbVar9 + -1;
        if ((param_5 & 8U) == 0) {
          if (param_3 != (char **)0x0) {
            pbVar9 = (byte *)param_2;
          }
          local_8 = 0;
        }
        else if (((param_5 & 4U) != 0) ||
                (((param_5 & 1U) == 0 &&
                 ((((param_5 & 2U) != 0 && (0x80000000 < local_8)) ||
                  (((param_5 & 2U) == 0 && (0x7fffffff < local_8)))))))) {
          piVar3 = __errno();
          *piVar3 = 0x22;
          if ((param_5 & 1U) == 0) {
            local_8 = ((param_5 & 2U) != 0) + 0x7fffffff;
          }
          else {
            local_8 = 0xffffffff;
          }
        }
        if (param_3 != (char **)0x0) {
          *param_3 = (char *)pbVar9;
        }
        if ((param_5 & 2U) != 0) {
          local_8 = -local_8;
        }
        if (local_c == '\0') {
          return local_8;
        }
        *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
        return local_8;
      }
      iVar7 = (int)(char)bVar8;
      if ((byte)(bVar8 + 0x9f) < 0x1a) {
        iVar7 = iVar7 + -0x20;
      }
      uVar6 = iVar7 - 0x37;
    }
    else {
      uVar6 = (int)(char)bVar8 - 0x30;
    }
    if ((uint)param_4 <= uVar6) goto LAB_004148ea;
    if ((local_8 < uVar4) ||
       ((local_8 == uVar4 && (uVar6 <= (uint)(0xffffffff % (ulonglong)(uint)param_4))))) {
      local_8 = local_8 * param_4 + uVar6;
      param_5 = param_5 | 8;
    }
    else {
      param_5 = param_5 | 0xc;
      if (param_3 == (char **)0x0) goto LAB_004148ea;
    }
    bVar8 = *pbVar9;
    pbVar9 = pbVar9 + 1;
  } while( true );
}
}

// =================================================
// Function: thunk____sbh_find_block
// =================================================
LPVOID thunk____sbh_find_block(int param_1)
{
{
  LPVOID pvVar1;
  
  pvVar1 = lpMem_00d7aea8;
  while( true ) {
    if ((LPVOID)(DAT_00d7aea4 * 0x14 + (int)lpMem_00d7aea8) <= pvVar1) {
      return (LPVOID)0x0;
    }
    if ((uint)(param_1 - *(int *)((int)pvVar1 + 0xc)) < 0x100000) break;
    pvVar1 = (LPVOID)((int)pvVar1 + 0x14);
  }
  return pvVar1;
}
}

// =================================================
// Function: vscan_fn
// =================================================
void __cdecl vscan_fn(void)
{
{
  int *piVar1;
  char *unaff_ESI;
  code *in_stack_00000004;
  int in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  
  _strlen(unaff_ESI);
  if ((unaff_ESI == (char *)0x0) || (in_stack_00000008 == 0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter();
  }
  else {
    (*in_stack_00000004)(&stack0xffffffdc,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  }
  return;
}
}

