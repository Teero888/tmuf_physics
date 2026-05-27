// Class implementation: CHmsZone

// =================================================
// Function: CHmsZone::AddCorpus
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsZone::AddCorpus(CHmsZone *this,SZone *param_1,CHmsCorpus *param_2)
{
{
  CHmsItem *this_00;
  float fVar1;
  CHmsCorpus **ppCVar2;
  ulong uVar3;
  CHmsCorpus *unaff_EBX;
  ulong unaff_ESI;
  CHmsItem *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  
  this_00 = *(CHmsItem **)(param_1 + 0x48);
  ppCVar2 = (CHmsCorpus **)CHmsItem::GetCorpusCat(this_00,unaff_EDI);
  CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::AddInCat
            (this + 0x1c,
             (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)&param_2,ppCVar2
             ,unaff_ESI);
  fVar1 = _DAT_00b37b60;
  *(CHmsZone **)(param_1 + 0x14) = this;
  if (fVar1 < *(float *)(this + 0x108)) {
    Zone_UpdateWaterHeights(unaff_EBX);
  }
  if (((*(uint *)(this_00 + 0x18) & 0x100) != 0) &&
     (*(CHmsZoneVPacker **)(this + 0x104) != (CHmsZoneVPacker *)0x0)) {
    CHmsZoneVPacker::AddNewSolid
              (*(CHmsZoneVPacker **)(this + 0x104),(CHmsZoneVPacker *)param_1,unaff_EBX);
  }
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x28,unaff_retaddr);
  if ((uVar3 != 0) || (*(int *)(this_00 + 0x30) != 0)) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this + 0x40,(TiXmlAttributeSet *)&stack0x00000014,(TiXmlAttribute *)param_1);
  }
  if (((byte)this_00[0x20] & 1) != 0) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this + 0x4c,(TiXmlAttributeSet *)&stack0x00000018,(TiXmlAttribute *)param_2);
  }
  return;
}
}

// =================================================
// Function: CHmsZone::AddField
// =================================================
void __thiscall CHmsZone::AddField(CHmsZone *this,CHmsZone *param_1,CHmsForceField *param_2)
{
{
  TiXmlAttribute *unaff_retaddr;
  
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (this + 0x7c,(TiXmlAttributeSet *)&param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsZone::AddItem
// =================================================
void __thiscall
CHmsZone::AddItem(CHmsZone *this,CGamePopUp *param_1,CFastStringInt *param_2,ulong param_3,
                 int param_4)
{
{
  CHmsCorpus *this_00;
  CHmsCorpus *unaff_EBX;
  GmIso4 *unaff_ESI;
  CHmsItem *unaff_EDI;
  
  this_00 = (CHmsCorpus *)(**(code **)(*(int *)this + 0xb4))();
  CHmsCorpus::SetItem(this_00,(CHmsCorpus *)param_1,unaff_EDI);
  CHmsCorpus::SetLocation(this_00,(CPlugTree *)param_3,unaff_ESI);
  *(CHmsZone **)(this_00 + 0x14) = this;
  CHmsItem::AddCorpus((CHmsItem *)param_1,(SZone *)this_00,unaff_EBX);
  (**(code **)(*(int *)this + 0xb0))(this_00);
  return;
}
}

// =================================================
// Function: CHmsZone::AddLight
// =================================================
void __thiscall
CHmsZone::AddLight(CHmsZone *this,CHmsZone *param_1,CHmsLight *param_2,GmIso4 *param_3)
{
{
  CHmsZone *this_00;
  CHmsLight *pCVar1;
  SCasterCat *pSVar2;
  CHmsCorpusLight *extraout_EAX;
  int iVar3;
  CHmsCorpus **ppCVar4;
  CHmsCorpusLight *unaff_EBX;
  TiXmlAttribute *unaff_EBP;
  GmIso4 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CHmsCorpusLight *this_01;
  CHmsCorpusLight *unaff_EDI;
  CPlugTree *in_stack_00000010;
  ulong uVar6;
  void *local_c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&LAB_00a9698b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = this + 0x58;
  local_c = (void *)CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll
                              (this_00,(CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *)
                                       (DAT_00cca150 ^ (uint)&stack0xffffffe0));
  pCVar1 = param_2;
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (local_c != (void *)0x0) {
    do {
      pSVar2 = CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::operator[]
                         (this_00,pCVar5,(ulong)unaff_EDI);
      if (*(CHmsLight **)(*(int *)pSVar2 + 0x48) == pCVar1) {
        ExceptionList = local_8;
        return;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < local_8);
  }
  *(CHmsZone **)(pCVar1 + 0x14) = this;
  param_2 = operator_new(100);
  this_01 = (CHmsCorpusLight *)0x0;
  if (param_2 != (CHmsLight *)0x0) {
    CHmsCorpusLight::CHmsCorpusLight((CHmsCorpusLight *)param_2,unaff_EDI);
    this_01 = extraout_EAX;
  }
  param_2 = (CHmsLight *)this_01;
  CHmsCorpusLight::SetLight(this_01,(CMotionLight *)pCVar1,(GxLight *)unaff_EDI);
  *(CHmsZone **)(this_01 + 0x14) = this;
  uVar6 = 0x54f013;
  CHmsCorpusLight::SetLocation(this_01,in_stack_00000010,unaff_ESI);
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (pCVar1 + 0x58,(TiXmlAttributeSet *)&stack0x00000010,unaff_EBP);
  if (*(int *)(this_01 + 0x4c) != 0) {
    *(int *)(this + 0x100) = *(int *)(this + 0x100) + 1;
  }
  iVar3 = (**(code **)(**(int **)(pCVar1 + 0x88) + 0x78))();
  if (iVar3 == 0) {
    CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat>::ResetCat
              (this_00,(CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                        *)0x0,(ulong)unaff_EBX);
  }
  else if ((((byte)pCVar1[0x8c] & 3) == 0) &&
          (*(CHmsZoneVPacker **)(this + 0x104) != (CHmsZoneVPacker *)0x0)) {
    CHmsZoneVPacker::AddNewLight
              (*(CHmsZoneVPacker **)(this + 0x104),(CHmsZoneVPacker *)this_01,unaff_EBX);
  }
  ppCVar4 = (CHmsCorpus **)(**(code **)(**(int **)(pCVar1 + 0x88) + 0x78))();
  CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::AddInCat
            (this_00,(CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)&param_1
             ,ppCVar4,uVar6);
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CHmsZone::AddSound
// =================================================
CAudioSound * __thiscall
CHmsZone::AddSound(CHmsZone *this,CAudioPort *param_1,CPlugSound *param_2,EBalanceGroup param_3,
                  int param_4)
{
{
  CAudioSound *extraout_EAX;
  TiXmlAttribute *unaff_retaddr;
  
  *(CHmsZone **)(param_1 + 0x14) = this;
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (this + 0x10c,(TiXmlAttributeSet *)&param_1,unaff_retaddr);
  return extraout_EAX;
}
}

// =================================================
// Function: CHmsZone::ApplyFidParameters
// =================================================
void __thiscall
CHmsZone::ApplyFidParameters
          (CHmsZone *this,CPlugFontBitmap *param_1,CSystemFidParameters *param_2,
          CSystemFidParameters *param_3,CFastBuffer<struct_CMwNod::SManuallyLoadedFid> *param_4)
{
{
  SParam *pSVar1;
  SParam *pSVar2;
  SParam_Id *pSVar3;
  SParam_Id local_24 [4];
  SParam_Id local_20 [16];
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a966f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CVisionViewportNull::SetFullScreenGammaRamp
            ((CVisionViewportNull *)this,(CVisionViewportNull *)param_1,(float)param_2,
             (float)param_3,(float)(DAT_00cca150 ^ (uint)&stack0xffffffd0));
  pSVar3 = (SParam_Id *)0x0;
  pSVar2 = (SParam *)0x0;
  pSVar1 = (SParam *)0x0;
  CSystemFidParameters::SParam_Id::SParam_Id(local_20,(SParam_Id *)&DAT_00d67738);
  local_c = (void *)0x0;
  CSystemFidParameters::GetParamValue
            ((CSystemFidParameters *)param_1,(CSystemFidParameters *)&stack0xffffffd4,pSVar1);
  CSystemFidParameters::AddParam(param_2,(CSystemFidParameters *)&stack0xffffffd8,pSVar2);
  *(undefined4 *)(this + 0xb4) = local_10;
  local_4 = 0xffffffff;
  CSystemFidParameters::SParam_Id::~SParam_Id(local_24,pSVar3);
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CHmsZone::CHmsZone
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsZone::CHmsZone(CHmsZone *this,CHmsZone *param_1)
{
{
  CMwNod *extraout_EAX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CMwNod *this_00;
  ulong unaff_ESI;
  CMwNod *unaff_EDI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  GxFog *in_stack_00000008;
  CMwNod *in_stack_0000000c;
  SPlugVisibleFilter *in_stack_00000010;
  GxFog *pGStack0000001c;
  undefined1 uStack00000028;
  void *in_stack_0000002c;
  CHmsZone *pCVar1;
  ulong in_stack_fffffff0;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar2;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar3;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar4;
  
  pCVar4 = (CFastBuffer<class_CPlugFileSndGen*> *)0xffffffff;
  pCVar3 = (CFastBuffer<class_CPlugFileSndGen*> *)&LAB_00a9681e;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe0),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastBufferCat<class_CHmsCorpus*,struct_SFastCat>::
  CFastBufferCat<class_CHmsCorpus*,struct_SFastCat>
            (this + 0x1c,(CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> *)&DAT_00000005,0x32,
             unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x40,unaff_EBP);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x4c,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar1);
  in_stack_00000010 = (SPlugVisibleFilter *)CONCAT31(in_stack_00000010._1_3_,3);
  CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat>::
  CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat>
            (this + 0x58,(CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat> *)&DAT_00000006,10,
             in_stack_fffffff0);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x7c,pCVar2);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x88,pCVar3);
  *(undefined4 *)(this + 0xb0) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0xdc,pCVar4);
  *(undefined4 *)(this + 0xe8) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0xf4,unaff_retaddr);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x10c,(CFastBuffer<class_CPlugFileSndGen*> *)0x0);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x94) = 0x3f800000;
  *(undefined4 *)(this + 0x98) = 0x3f800000;
  *(undefined4 *)(this + 0x9c) = 0x3f800000;
  uStack00000028 = 0xb;
  *(undefined4 *)(this + 0xa8) = 0x3f800000;
  *(undefined4 *)(this + 0xac) = 6;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 0x3f800000;
  pGStack0000001c = operator_new(0x40);
  uStack00000028 = 0xc;
  if (pGStack0000001c == (GxFog *)0x0) {
    this_00 = (CMwNod *)0x0;
  }
  else {
    GxFog::GxFog(pGStack0000001c,in_stack_00000008);
    this_00 = extraout_EAX;
  }
  in_stack_0000002c = (void *)CONCAT31(in_stack_0000002c._1_3_,0xb);
  if (this_00 != *(CMwNod **)(this + 0xb0)) {
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_00,in_stack_0000000c);
    }
    if (*(CMwNod **)(this + 0xb0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xb0),in_stack_0000000c);
    }
    *(CMwNod **)(this + 0xb0) = this_00;
  }
  *(undefined4 *)(*(int *)(this + 0xb0) + 0x14) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xb8) = 1;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 200) = 0;
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0xd4) = 0x3f800000;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0x108) = _DAT_00b2c060;
  SPlugVisibleFilter::SetDefaultValues(this + 0xec,(SPlugVisibleFilter *)in_stack_0000000c);
  SPlugVisibleFilter::SetDefaultValues(this + 0xf0,in_stack_00000010);
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x104) = 0;
  ExceptionList = in_stack_0000002c;
  return;
}
}

// =================================================
// Function: CHmsZone::CheckPreloadVisionData
// =================================================
int __thiscall
CHmsZone::CheckPreloadVisionData
          (CHmsZone *this,CHmsZone *param_1,CHmsViewport *param_2,CHmsCamera *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_EBX;
  ulong unaff_EBP;
  int iVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CHmsCamera *unaff_EDI;
  undefined4 in_stack_00000010;
  
  iVar4 = 0;
  if (*(int *)(this + 0xb8) != 0) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetParsingCat
                       (this + 0x1c,
                        (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)
                        (-(uint)(*(int *)(this + 0x104) != 0) & 2),
                        (uint)(*(int *)(this + 0x104) == 0) * 2 + 3,unaff_EBP);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::operator[]
                           (this + 0x1c,pCVar5,unaff_EBX);
        unaff_EBX = 0;
        (**(code **)(*(int *)param_1 + 0xa0))
                  (*(undefined4 *)(*(int *)(*(int *)(*(int *)pSVar2 + 0x48) + 0x14) + 100),1,
                   in_stack_00000010);
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar1);
    }
    (**(code **)(*(int *)param_1 + 0xa4))();
    *(undefined4 *)(this + 0xb8) = 0;
    iVar4 = 1;
  }
  if ((*(CHmsZoneVPacker **)(this + 0x104) != (CHmsZoneVPacker *)0x0) &&
     (iVar3 = CHmsZoneVPacker::CheckDirty
                        (*(CHmsZoneVPacker **)(this + 0x104),(CHmsZoneVPacker *)param_1,param_2,
                         unaff_EDI), iVar3 != 0)) {
    return 1;
  }
  return iVar4;
}
}

// =================================================
// Function: CHmsZone::Chunk
// =================================================
void __thiscall
CHmsZone::Chunk(CHmsZone *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CFuncSegment *this_00;
  ulong unaff_EBX;
  CClassicArchive *unaff_ESI;
  CClassicArchive *unaff_EDI;
  ulong unaff_retaddr;
  CMwNod *pCVar1;
  
  this_00 = param_1;
  if (param_2 < (CClassicArchive *)0x6004005) {
    if (param_2 == (CClassicArchive *)0x6004004) {
      pCVar1 = (CMwNod *)&param_2;
      param_2 = (CClassicArchive *)0x0;
      (**(code **)(*(int *)param_1 + 4))();
      if (param_1 != (CFuncSegment *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_1,pCVar1);
        CMwNod::MwRelease((CMwNod *)param_2,(CMwNod *)unaff_EDI);
        return;
      }
    }
    else {
      switch(param_2) {
      case (CClassicArchive *)0x6004000:
        CClassicArchive::DoNatural
                  ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(ulong *)0x1,0,
                   (int)unaff_EDI);
        return;
      case (CClassicArchive *)0x6004001:
        break;
      case (CClassicArchive *)0x6004002:
        CFastBuffer<class_CPlugMaterial*>::ArchiveFastBufferNod
                  (this + 0x88,(CFastBuffer<class_CPlugMaterial*> *)param_1,unaff_EDI);
        GxFogGlobal::ArchiveFog(this + 0x94,(GxFogGlobal *)this_00,unaff_ESI);
        return;
      case (CClassicArchive *)0x6004003:
        CClassicArchive::DoBool
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0xbc),(int *)0x1,unaff_EBX)
        ;
        if (*(int *)(this + 0xbc) != 0) {
          CClassicArchive::DoReal
                    ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xc4),(float *)0x1,
                     (ulong)unaff_EDI);
          CClassicArchive::DoReal
                    ((CClassicArchive *)this_00,(CClassicArchive *)(this + 200),(float *)0x1,
                     (ulong)unaff_ESI);
          CClassicArchive::DoReal
                    ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xcc),(float *)0x1,
                     unaff_retaddr);
          CClassicArchive::DoReal
                    ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xd0),(float *)0x1,
                     (ulong)param_1);
          param_1 = (CFuncSegment *)0x1;
          CClassicArchive::DoReal
                    ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xd4),(float *)0x1,
                     (ulong)param_2);
          param_2 = (CClassicArchive *)0x1;
          param_1 = (CFuncSegment *)(this + 0xd8);
          CClassicArchive::DoReal
                    ((CClassicArchive *)this_00,(CClassicArchive *)param_1,(float *)0x1,param_3);
        }
        break;
      default:
        goto switchD_0054eaa8_default;
      }
    }
  }
  else {
    if (param_2 == (CClassicArchive *)0x6004005) {
      CFastBuffer<class_CPlugMaterial*>::ArchiveFastBufferNod
                (this + 0xf4,(CFastBuffer<class_CPlugMaterial*> *)param_1,unaff_EDI);
      return;
    }
    if (param_2 == (CClassicArchive *)0x6004006) {
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0xe8),
                 (CMwNodRef<class_CMwRefBuffer> *)unaff_EDI);
      return;
    }
    if (param_2 != (CClassicArchive *)0xffffffff) {
switchD_0054eaa8_default:
      CMwNod::Chunk((CMwNod *)this,param_1,param_2,(ulong)unaff_EDI);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CHmsZone::CorpusChangeBuild
// =================================================
void __thiscall
CHmsZone::CorpusChangeBuild(CHmsZone *this,CHmsZone *param_1,CHmsCorpus *param_2,int param_3)
{
{
  TiXmlAttribute *unaff_retaddr;
  
  if (param_2 != (CHmsCorpus *)0x0) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this + 0x40,(TiXmlAttributeSet *)&param_1,unaff_retaddr);
    return;
  }
  CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
            (this + 0x40,(CFastBuffer<class_CPlugBitmap*> *)&param_1,(CPlugBitmap **)unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsZone::CorpusChangeCat
// =================================================
void __thiscall
CHmsZone::CorpusChangeCat
          (CHmsZone *this,CHmsZone *param_1,ulong param_2,EHmsCorpusCat param_3,
          EHmsCorpusCat param_4)
{
{
  CHmsZone *this_00;
  CHmsZoneVPacker *pCVar1;
  int iVar2;
  SSamplerState *pSVar3;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
  *extraout_ECX;
  int extraout_EDX;
  CHmsCorpus *unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  this_00 = this + 0x1c;
  CFastBufferCat<class_CPlugTree*,struct_SFastCat>::ChangeCatAt
            (this_00,(CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *)
                     param_1,param_2,param_3,unaff_EDI);
  CorpusCat_IsStatic(param_2);
  iVar2 = CorpusCat_IsStatic(param_3);
  if (iVar2 == 0) {
    if ((extraout_EDX != 0) &&
       (pCVar1 = *(CHmsZoneVPacker **)(this + 0x104), pCVar1 != (CHmsZoneVPacker *)0x0)) {
      pSVar3 = CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::GetElemInCat
                         (this_00,extraout_ECX,param_3,unaff_ESI);
      CHmsZoneVPacker::RemoveSolid(pCVar1,*(CHmsZoneVPacker **)pSVar3,unaff_EBP);
    }
  }
  else if ((extraout_EDX == 0) &&
          (pCVar1 = *(CHmsZoneVPacker **)(this + 0x104), pCVar1 != (CHmsZoneVPacker *)0x0)) {
    pSVar3 = CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::GetElemInCat
                       (this_00,extraout_ECX,param_3,unaff_ESI);
    CHmsZoneVPacker::AddNewSolid(pCVar1,*(CHmsZoneVPacker **)pSVar3,unaff_EBP);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsZone::CorpusChangeLightEmitter
// =================================================
void __thiscall
CHmsZone::CorpusChangeLightEmitter(CHmsZone *this,CHmsZone *param_1,CHmsCorpus *param_2,int param_3)
{
{
  TiXmlAttribute *unaff_retaddr;
  
  if (param_2 != (CHmsCorpus *)0x0) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this + 0x4c,(TiXmlAttributeSet *)&param_1,unaff_retaddr);
    return;
  }
  CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
            (this + 0x4c,(CFastBuffer<class_CPlugBitmap*> *)&param_1,(CPlugBitmap **)unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsZone::CreateZoneCorpus
// =================================================
CHmsCorpus * __thiscall CHmsZone::CreateZoneCorpus(CHmsZone *this,CHmsZoneOverlay *param_1)
{
{
  CHmsCorpus *pCVar1;
  CHmsCorpus *extraout_EAX;
  CHmsZone *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a966cb;
  local_c = ExceptionList;
  pCVar1 = (CHmsCorpus *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = this;
  local_10 = operator_new(0x5c);
  local_4 = 0;
  if (local_10 != (CHmsZone *)0x0) {
    CHmsCorpus::CHmsCorpus((CHmsCorpus *)local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CHmsCorpus *)0x0;
}
}

// =================================================
// Function: CHmsZone::GetChunkInfo
// =================================================
ulong __thiscall CHmsZone::GetChunkInfo(CHmsZone *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if ((CFuncSegment *)0x6004004 < param_1) {
    if ((param_1 == (CFuncSegment *)0x6004005) || (param_1 == (CFuncSegment *)0x6004006)) {
switchD_0054cb98_caseD_6004002:
      return 3;
    }
    if (param_1 == (CFuncSegment *)0xffffffff) {
      return 0xffffffff;
    }
switchD_0054cb98_default:
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
    return uVar1;
  }
  if (param_1 == (CFuncSegment *)0x6004004) {
switchD_0054cb98_caseD_6004000:
    return 1;
  }
  switch(param_1) {
  case (CFuncSegment *)0x6004000:
  case (CFuncSegment *)0x6004001:
    goto switchD_0054cb98_caseD_6004000;
  case (CFuncSegment *)0x6004002:
  case (CFuncSegment *)0x6004003:
    goto switchD_0054cb98_caseD_6004002;
  default:
    goto switchD_0054cb98_default;
  }
}
}

// =================================================
// Function: CHmsZone::GetMwClassId
// =================================================
ulong __thiscall CHmsZone::GetMwClassId(CHmsZone *this,CControlStyle *param_1)
{
{
  return 0x6004000;
}
}

// =================================================
// Function: CHmsZone::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CHmsZone::GetUidChunkFromIndex(CHmsZone *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x6004000;
}
}

// =================================================
// Function: CHmsZone::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CHmsZone::MwGetClassInfo(CHmsZone *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6770c;
}
}

// =================================================
// Function: CHmsZone::MwIsKindOf
// =================================================
int __thiscall CHmsZone::MwIsKindOf(CHmsZone *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0x6004000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CHmsZone::MwNewCHmsZone
// =================================================
CMwNod * __cdecl CHmsZone::MwNewCHmsZone(void)
{
{
  CHmsZone *pCVar1;
  CMwNod *extraout_EAX;
  CHmsZone *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9692b;
  local_c = ExceptionList;
  pCVar1 = (CHmsZone *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x11c);
  local_4 = 0;
  if (local_10 != (CHmsZone *)0x0) {
    CHmsZone(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CHmsZone::RemoveCorpus
// =================================================
void __thiscall CHmsZone::RemoveCorpus(CHmsZone *this,CHmsZoneOverlay *param_1,CHmsCorpus *param_2)
{
{
  CHmsItem *this_00;
  CHmsZoneOverlay *pCVar1;
  ulong uVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CHmsCorpus *unaff_ESI;
  ulong *unaff_EDI;
  CPlugBitmap **unaff_retaddr;
  
  pCVar1 = param_1;
  this_00 = *(CHmsItem **)(param_1 + 0x48);
  CFastBufferCat<class_CHmsCorpus*,struct_SFastCat>::ReplaceByLastInAll
            (this + 0x1c,(CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> *)&param_1,
             (CHmsCorpus **)0x0,unaff_EDI);
  if (((*(uint *)(this_00 + 0x18) & 0x100) != 0) &&
     (*(CHmsZoneVPacker **)(this + 0x104) != (CHmsZoneVPacker *)0x0)) {
    CHmsZoneVPacker::RemoveSolid
              (*(CHmsZoneVPacker **)(this + 0x104),(CHmsZoneVPacker *)pCVar1,unaff_ESI);
  }
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x28,unaff_EBX);
  if ((uVar2 != 0) || (*(int *)(this_00 + 0x30) != 0)) {
    CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
              (this + 0x40,(CFastBuffer<class_CPlugBitmap*> *)&stack0x00000010,unaff_retaddr);
  }
  if (((byte)this_00[0x20] & 1) != 0) {
    CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
              (this + 0x4c,(CFastBuffer<class_CPlugBitmap*> *)&stack0x00000014,
               (CPlugBitmap **)param_1);
  }
  CHmsItem::RemoveCorpus(this_00,pCVar1,(CHmsCorpus *)param_1);
  param_1 = (CHmsZoneOverlay *)0x1;
  (**(code **)(*(int *)pCVar1 + 4))();
  return;
}
}

// =================================================
// Function: CHmsZone::RemoveField
// =================================================
void __thiscall CHmsZone::RemoveField(CHmsZone *this,CHmsZone *param_1,CHmsForceField *param_2)
{
{
  CPlugBitmap **unaff_retaddr;
  
  CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
            (this + 0x7c,(CFastBuffer<class_CPlugBitmap*> *)&param_1,unaff_retaddr);
  *(undefined4 *)(param_2 + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CHmsZone::RemoveItem
// =================================================
void __thiscall CHmsZone::RemoveItem(CHmsZone *this,CHmsZone *param_1,CHmsItem *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    while( true ) {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_1 + 0x34,pCVar3,unaff_ESI);
      if (*(CHmsZone **)(*(int *)pSVar2 + 0x14) == this) break;
      pCVar3 = pCVar3 + 1;
      if (pCVar1 <= pCVar3) {
        return;
      }
    }
    (**(code **)(*(int *)this + 0x7c))(*(int *)pSVar2);
  }
  return;
}
}

// =================================================
// Function: CHmsZone::RemoveLight
// =================================================
void __thiscall
CHmsZone::RemoveLight(CHmsZone *this,CHmsZoneVPacker *param_1,CHmsCorpusLight *param_2)
{
{
  CHmsZoneVPacker *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CHmsCorpusLight *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CHmsZoneVPacker *this_00;
  int in_stack_0000000c;
  int in_stack_00000018;
  CHmsZone *pCVar5;
  
  this_00 = param_1 + 0x58;
  pCVar5 = this;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
      if (*(CHmsZone **)(*(int *)pSVar3 + 0x14) == this) break;
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
  pCVar1 = *(CHmsZoneVPacker **)pSVar3;
  if ((*(int *)(pCVar1 + 0x4c) != 0) && (*(int *)(this + 0x100) != 0)) {
    *(int *)(this + 0x100) = *(int *)(this + 0x100) + -1;
  }
  if ((*(CHmsZoneVPacker **)(this + 0x104) != (CHmsZoneVPacker *)0x0) &&
     ((*(byte *)(in_stack_0000000c + 0x8c) & 3) == 0)) {
    CHmsZoneVPacker::RemoveLight(*(CHmsZoneVPacker **)(this + 0x104),pCVar1,unaff_EBP);
  }
  CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt
            (this_00,(CFastBufferRef<class_CGameMobil> *)pCVar4,1,unaff_EBX);
  CFastBufferCat<class_CHmsCorpus*,struct_SFastCat>::ReplaceByLastInAll
            (this + 0x58,(CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> *)&stack0x0000000c,
             (CHmsCorpus **)0x0,(ulong *)pCVar5);
  *(undefined4 *)(in_stack_00000018 + 0x14) = 0;
  (**(code **)(*(int *)pCVar1 + 4))(1);
  return;
}
}

// =================================================
// Function: CHmsZone::RemoveSound
// =================================================
void __thiscall CHmsZone::RemoveSound(CHmsZone *this,CAudioPort *param_1,CAudioSound *param_2)
{
{
  CFastBufferRef<class_CGameMobil> *pCVar1;
  GxTexCoordSet *unaff_ESI;
  ulong unaff_retaddr;
  int in_stack_0000000c;
  
  pCVar1 = (CFastBufferRef<class_CGameMobil> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     (this + 0x10c,(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_ESI);
  if (pCVar1 != (CFastBufferRef<class_CGameMobil> *)0xffffffff) {
    CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt(this + 0x10c,pCVar1,1,unaff_retaddr);
    *(undefined4 *)(in_stack_0000000c + 0x14) = 0;
    return;
  }
  *(undefined4 *)(param_2 + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CHmsZone::VPackerCreate
// =================================================
void __thiscall CHmsZone::VPackerCreate(CHmsZone *this,CHmsZone *param_1,SHmsVPackerCreate *param_2)
{
{
  CHmsZone *this_00;
  int *piVar1;
  char *pcVar2;
  CPlugFileGpuBuilder *pCVar3;
  CHmsZoneVPacker *pCVar4;
  CHmsZoneVPacker *extraout_EAX;
  CHmsZoneVPacker *extraout_EAX_00;
  SCasterCat *pSVar5;
  ulong uVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  int iVar8;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this_01;
  char *unaff_EBX;
  CPlugFileGpuBuilder *unaff_EBP;
  char *unaff_ESI;
  uint uVar9;
  CPlugFileGpuBuilder *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CHmsZoneVPacker *in_stack_00000018;
  char *pcVar11;
  LPCSTR *ppCVar12;
  SGmSmoothReal2 *pSVar13;
  CHmsCorpus *pCVar14;
  int iVar15;
  CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *pCVar16;
  SHmsVPackerCreate *in_stack_ffffffec;
  CHmsCorpusLight *pCVar17;
  ulong in_stack_fffffff0;
  void *pvVar18;
  
  this_00 = this + 0x1c;
  pvVar18 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pcVar2 = (char *)CFastBufferCat<class_CHmsCorpus*,struct_SFastCat>::GetCountInCats
                             (this_00,(CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> *)0x0,2,
                              DAT_00cca150 ^ (uint)&stack0xffffffdc);
  if ((*(int *)(this + 0x104) != 0) && (pcVar2 != (char *)0x0)) {
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    ppCVar12 = &lpOutputString_00b2bcc4;
    pcVar11 = " corpuses";
    pCVar3 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"Trying to update packer with ",pcVar2);
    pCVar3 = CFastString::operator<<
                       ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar11,(char *)ppCVar12);
    pCVar3 = CFastString::operator<<((CFastString *)pCVar3,unaff_EDI,unaff_ESI);
    CFastString::operator<<((CFastString *)pCVar3,unaff_EBP,unaff_EBX);
    CClassicLog::AddLogStringInFile();
    if (*(undefined4 **)(this + 0x104) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(this + 0x104))();
    }
    *(undefined4 *)(this + 0x104) = 0;
  }
  iVar15 = *(int *)(this + 0x104);
  if (iVar15 != 0) goto LAB_0054fcb1;
  if (*(int *)(in_stack_00000018 + 0x20) == 0) {
    pCVar4 = operator_new(0x1a8);
    if (pCVar4 == (CHmsZoneVPacker *)0x0) goto LAB_0054fc99;
    CHmsZoneVPacker::CHmsZoneVPacker(pCVar4,(CHmsZoneVPacker *)in_stack_ffffffec);
    pCVar4 = extraout_EAX_00;
  }
  else {
    pCVar4 = operator_new(0x1a8);
    if (pCVar4 == (CHmsZoneVPacker *)0x0) {
LAB_0054fc99:
      pCVar4 = (CHmsZoneVPacker *)0x0;
    }
    else {
      CHmsZoneVPacker::CHmsZoneVPacker(pCVar4,*(CHmsZoneVPacker **)in_stack_00000018);
      pCVar4 = extraout_EAX;
    }
  }
  *(CHmsZoneVPacker **)(this + 0x104) = pCVar4;
  CHmsZoneVPacker::SetZone(pCVar4,(CSceneSector *)this,(CHmsZone *)in_stack_ffffffec);
LAB_0054fcb1:
  pCVar14 = (CHmsCorpus *)0x54fcbd;
  CHmsZoneVPacker::SetCreateParams
            (*(CHmsZoneVPacker **)(this + 0x104),in_stack_00000018,in_stack_ffffffec);
  if (iVar15 != 0) {
    this_01 = *(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                **)(this + 0x104);
    uVar6 = *(ulong *)(in_stack_00000018 + 8);
    iVar15 = *(int *)(in_stack_00000018 + 4);
    pSVar13 = *(SGmSmoothReal2 **)in_stack_00000018;
  }
  else {
    pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        in_stack_fffffff0);
    param_2 = (SHmsVPackerCreate *)(*(int *)(this + 0x2c) + *(int *)pSVar5 * 4);
    pCVar17 = (CHmsCorpusLight *)0x0;
    pCVar16 = (CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *)0x54fce5;
    uVar6 = CFastBufferCat<class_CHmsCorpus*,struct_SFastCat>::GetCountInCats
                      (this_00,(CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> *)0x0,2,
                       (ulong)pvVar18);
    uVar9 = 0;
    if (uVar6 != 0) {
      do {
        CHmsZoneVPacker::AddNewSolid
                  (*(CHmsZoneVPacker **)(this + 0x104),
                   *(CHmsZoneVPacker **)(&LAB_00a96a86 + uVar9 * 4),pCVar14);
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar6);
    }
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll
                       (this + 0x58,pCVar16);
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::operator[]
                           (this + 0x58,pCVar10,(ulong)pCVar17);
        pCVar4 = *(CHmsZoneVPacker **)pSVar5;
        iVar15 = *(int *)(pCVar4 + 0x48);
        piVar1 = *(int **)(iVar15 + 0x88);
        pCVar17 = (CHmsCorpusLight *)0x54fd43;
        iVar8 = (**(code **)(*piVar1 + 0x78))();
        if (((iVar8 != 0) && (iVar8 = (**(code **)(*piVar1 + 0x78))(), iVar8 != 1)) &&
           ((*(byte *)(iVar15 + 0x8c) & 3) == 0)) {
          CHmsZoneVPacker::AddNewLight(*(CHmsZoneVPacker **)(this + 0x104),pCVar4,pCVar17);
        }
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < pCVar7);
    }
    if (*(int *)(in_stack_00000018 + 0x20) != 0) {
      ExceptionList = param_2;
      return;
    }
    iVar15 = *(int *)(in_stack_00000018 + 8);
    pSVar13 = *(SGmSmoothReal2 **)in_stack_00000018;
    uVar6 = 0;
    this_01 = *(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                **)(this + 0x104);
  }
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::Update
            (this_01,pSVar13,iVar15,uVar6);
  ExceptionList = param_2;
  return;
}
}

// =================================================
// Function: CHmsZone::VPackerRemove
// =================================================
void __thiscall CHmsZone::VPackerRemove(CHmsZone *this,CHmsZone *param_1)
{
{
  if (*(undefined4 **)(this + 0x104) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x104))(1);
  }
  *(undefined4 *)(this + 0x104) = 0;
  return;
}
}

// =================================================
// Function: CHmsZone::VirtualParam_Add
// =================================================
ulong __thiscall
CHmsZone::VirtualParam_Add
          (CHmsZone *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x600400b) {
    CMwParamFastBuffer<class_CMwParamClass>::AddValue
              ((CMwParamFastBuffer<class_CMwParamClass> *)(this + 0xf4),
               (CMwStatsValue *)(this + 0xf4),(float)param_1);
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Add((CMwNod *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CHmsZone::VirtualParam_Get
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CHmsZone::VirtualParam_Get
          (CHmsZone *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  uint uVar2;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this_00;
  float fVar3;
  float fVar4;
  GmVec3 GVar5;
  undefined3 extraout_var;
  ulong uVar6;
  int iVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int *in_stack_00000010;
  
  iVar7 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + iVar7 * 4);
  *(int *)(param_1 + 0x18) = iVar7 + -1;
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 < 0x6004033) {
    if (uVar2 == 0x6004032) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf0] >> 1 & 1;
      return 0;
    }
    switch(uVar2) {
    case 0x6004002:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0xac) & 1;
      return 0;
    case 0x6004003:
      GVar5 = CMwParamIso3::GetValue
                        ((CMwParamIso3 *)param_1,(CFuncColorGradient *)(this + 0x94),(float)param_1)
      ;
      return CONCAT31(extraout_var,GVar5);
    case 0x6004004:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0xac) >> 1 & 3;
      return 0;
    case 0x6004005:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0xac) >> 3 & 1;
      return 0;
    case 0x6004006:
      *(CHmsZone **)param_2 = this + 0xa0;
      return 0;
    case 0x6004007:
      *(CHmsZone **)param_2 = this + 0xa4;
      return 0;
    case 0x6004008:
      *(CHmsZone **)param_2 = this + 0xa8;
      return 0;
    case 0x6004013:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xec] & 1;
      return 0;
    case 0x6004014:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xec] >> 1 & 1;
      return 0;
    case 0x6004015:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xec] >> 2 & 1;
      return 0;
    case 0x6004016:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xec] >> 3 & 1;
      return 0;
    case 0x6004017:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xec] >> 4 & 1;
      return 0;
    case 0x6004018:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xec] >> 5 & 1;
      return 0;
    case 0x6004019:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xec] >> 6 & 1;
      return 0;
    case 0x600401a:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)((byte)this[0xec] >> 7);
      return 0;
    case 0x600401b:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xed] & 1;
      return 0;
    case 0x600401c:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xec) >> 9 & 1;
      return 0;
    case 0x600401d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xec) >> 10 & 1;
      return 0;
    case 0x600401e:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xec) >> 0xb & 1;
      return 0;
    case 0x600401f:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xec) >> 0xc & 1;
      return 0;
    case 0x6004020:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xec) >> 0xd & 1;
      return 0;
    case 0x6004021:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xec) >> 0xe & 1;
      return 0;
    case 0x6004022:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xee] & 1;
      return 0;
    case 0x6004023:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xee] >> 1 & 1;
      return 0;
    case 0x6004024:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xee] >> 2 & 1;
      return 0;
    case 0x6004025:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xee] >> 3 & 1;
      return 0;
    case 0x6004026:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xee] >> 4 & 1;
      return 0;
    case 0x6004027:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xee] >> 5 & 1;
      return 0;
    case 0x6004028:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xee] >> 6 & 1;
      return 0;
    case 0x6004029:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)((byte)this[0xee] >> 7);
      return 0;
    case 0x600402a:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xef] & 1;
      return 0;
    case 0x600402b:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xee) >> 9 & 1;
      return 0;
    case 0x600402c:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xee) >> 10 & 1;
      return 0;
    case 0x600402d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xee) >> 0xb & 1;
      return 0;
    case 0x600402e:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xee) >> 0xc & 1;
      return 0;
    case 0x600402f:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xee) >> 0xd & 1;
      return 0;
    case 0x6004030:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xee) >> 0xe & 1;
      return 0;
    case 0x6004031:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf0] & 1;
      return 0;
    }
switchD_0054d39a_caseD_6004009:
    *(int *)(param_1 + 0x18) = iVar7;
    uVar6 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,(CMwValueStd *)unaff_EDI);
    return uVar6;
  }
  if (uVar2 < 0x6004046) {
    if (uVar2 == 0x6004045) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf2] >> 5 & 1;
      return 0;
    }
    switch(uVar2) {
    case 0x6004033:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf0] >> 2 & 1;
      return 0;
    case 0x6004034:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf0] >> 3 & 1;
      return 0;
    case 0x6004035:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf0] >> 4 & 1;
      return 0;
    case 0x6004036:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf0] >> 5 & 1;
      return 0;
    case 0x6004037:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf0] >> 6 & 1;
      return 0;
    case 0x6004038:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)((byte)this[0xf0] >> 7);
      return 0;
    case 0x6004039:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf1] & 1;
      return 0;
    case 0x600403a:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf0) >> 9 & 1;
      return 0;
    case 0x600403b:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf0) >> 10 & 1;
      return 0;
    case 0x600403c:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf0) >> 0xb & 1;
      return 0;
    case 0x600403d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf0) >> 0xc & 1;
      return 0;
    case 0x600403e:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf0) >> 0xd & 1;
      return 0;
    case 0x600403f:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf0) >> 0xe & 1;
      return 0;
    case 0x6004040:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf2] & 1;
      return 0;
    case 0x6004041:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf2] >> 1 & 1;
      return 0;
    case 0x6004042:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf2] >> 2 & 1;
      return 0;
    case 0x6004043:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf2] >> 3 & 1;
      return 0;
    case 0x6004044:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf2] >> 4 & 1;
      return 0;
    }
    goto switchD_0054d39a_caseD_6004009;
  }
  if (uVar2 < 0x6004051) {
    if (uVar2 == 0x6004050) {
      if (*(int *)(this + 0x104) != 0) {
        *(undefined4 *)(param_2 + 4) = *(undefined4 *)(*(int *)(this + 0x104) + 0x4c);
        *(CMwStack **)param_2 = param_2 + 4;
        return 0;
      }
      goto LAB_0054dc21;
    }
    switch(uVar2) {
    case 0x6004046:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf2] >> 6 & 1;
      return 0;
    case 0x6004047:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)((byte)this[0xf2] >> 7);
      return 0;
    case 0x6004048:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0xf3] & 1;
      return 0;
    case 0x6004049:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf2) >> 9 & 1;
      return 0;
    case 0x600404a:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf2) >> 10 & 1;
      return 0;
    case 0x600404b:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf2) >> 0xb & 1;
      return 0;
    case 0x600404c:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf2) >> 0xc & 1;
      return 0;
    case 0x600404d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf2) >> 0xd & 1;
      return 0;
    case 0x600404e:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0xf2) >> 0xe & 1;
      return 0;
    }
    goto switchD_0054d39a_caseD_6004009;
  }
  if (uVar2 < 0x6004056) {
    if (uVar2 != 0x6004055) {
      switch(uVar2) {
      case 0x6004051:
        if (*(int *)(this + 0x104) != 0) {
          *(undefined4 *)(param_2 + 4) = *(undefined4 *)(*(int *)(this + 0x104) + 0x50);
          *(CMwStack **)param_2 = param_2 + 4;
          return 0;
        }
        break;
      case 0x6004052:
        if (*(int *)(this + 0x104) != 0) {
          *(undefined4 *)(param_2 + 4) = *(undefined4 *)(*(int *)(this + 0x104) + 0x54);
          *(CMwStack **)param_2 = param_2 + 4;
          return 0;
        }
        break;
      case 0x6004053:
        if ((*(int *)(this + 0x104) != 0) &&
           (uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount
                              ((void *)(*(int *)(this + 0x104) + 0x58),unaff_EDI), uVar6 != 0)) {
          uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount
                            ((void *)(*(int *)(this + 0x104) + 0x58),unaff_ESI);
          fVar3 = (float)(int)uVar6;
          if ((int)uVar6 < 0) {
            fVar3 = fVar3 + _DAT_00c418d0;
          }
          *in_stack_00000010 = (int)(in_stack_00000010 + 1);
          in_stack_00000010[1] = (int)((float)param_3 / fVar3);
          return 0;
        }
LAB_0054dea5:
        *(undefined4 *)(param_3 + 4) = 0;
        *(CMwValueStd **)param_3 = param_3 + 4;
        return 0;
      case 0x6004054:
        iVar7 = *(int *)(this + 0x104);
        if ((iVar7 == 0) || (*(int *)(iVar7 + 0x6c) == 0)) goto LAB_0054dea5;
        fVar3 = (float)*(int *)(iVar7 + 0x70);
        if (*(int *)(iVar7 + 0x70) < 0) {
          fVar3 = fVar3 + _DAT_00c418d0;
        }
        fVar4 = (float)*(int *)(iVar7 + 0x6c);
        if (*(int *)(iVar7 + 0x6c) < 0) {
          fVar4 = fVar4 + _DAT_00c418d0;
        }
        goto LAB_0054dd4d;
      default:
        goto switchD_0054d39a_caseD_6004009;
      }
LAB_0054dc21:
      *(undefined4 *)(param_2 + 4) = 0;
      *(CMwStack **)param_2 = param_2 + 4;
      return 0;
    }
    iVar1 = *(int *)(this + 0x104);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x6c) == 0)) goto LAB_0054dea5;
    fVar3 = (float)*(int *)(iVar1 + 0xc4);
    if (*(int *)(iVar1 + 0xc4) < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    iVar7 = *(int *)(iVar1 + 0x6c);
    iVar1 = *(int *)(iVar1 + 0x6c);
  }
  else {
    if (uVar2 == 0x6004056) {
      iVar7 = *(int *)(this + 0x104);
      if ((iVar7 != 0) && (*(int *)(iVar7 + 0xc4) != 0)) {
        fVar3 = (float)*(int *)(iVar7 + 200);
        if (*(int *)(iVar7 + 200) < 0) {
          fVar3 = fVar3 + _DAT_00c418d0;
        }
        fVar4 = (float)*(int *)(iVar7 + 0xc4);
        if (*(int *)(iVar7 + 0xc4) < 0) {
          fVar4 = fVar4 + _DAT_00c418d0;
        }
        *(CMwStack **)param_2 = param_2 + 4;
        *(float *)(param_2 + 4) = (fVar3 / fVar4) * (float)_DAT_00b57950;
        return 0;
      }
      goto LAB_0054dea5;
    }
    if (uVar2 != 0x6004057) {
      if (uVar2 == 0xffffffff) {
        return 0;
      }
      goto switchD_0054d39a_caseD_6004009;
    }
    this_00 = *(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                **)(this + 0x104);
    if (this_00 ==
        (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *)0x0)
    {
      *(undefined4 *)(param_2 + 4) = 0;
      *(CMwStack **)param_2 = param_2 + 4;
      return 0;
    }
    uVar6 = GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
            GetNbObjectOutside(this_00,(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                        *)unaff_EDI);
    iVar7 = *(int *)(this_00 + 0x70) + uVar6;
    if (iVar7 == 0) goto LAB_0054dea5;
    fVar3 = (float)(int)uVar6;
    if ((int)uVar6 < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    fVar3 = fVar3 * (float)_DAT_00b40f30;
    iVar1 = iVar7;
  }
  fVar4 = (float)iVar1;
  if (iVar7 < 0) {
    fVar4 = fVar4 + _DAT_00c418d0;
    *(CMwValueStd **)param_3 = param_3 + 4;
    *(float *)(param_3 + 4) = fVar3 / fVar4;
    return 0;
  }
LAB_0054dd4d:
  *(CMwValueStd **)param_3 = param_3 + 4;
  *(float *)(param_3 + 4) = fVar3 / fVar4;
  return 0;
}
}

// =================================================
// Function: CHmsZone::VirtualParam_Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CHmsZone::VirtualParam_Set(CHmsZone *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar3;
  float fVar4;
  ulong extraout_EAX;
  uint uVar5;
  ulong uVar6;
  SHmsVPackerCreate *unaff_ESI;
  CMwCmdAffectParamBool *pCVar7;
  SHmsVPackerCreate *unaff_EDI;
  float10 fVar8;
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar5 = *(uint *)(iVar2 + 4);
  if (uVar5 < 0x6004031) {
    if (uVar5 == 0x6004030) {
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^
           ((ushort)(*(int *)param_2 != 0) << 0xe ^ *(ushort *)(this + 0xee)) & 0x4000;
      return 0;
    }
    switch(uVar5) {
    case 0x6004002:
      *(uint *)(this + 0xac) =
           *(uint *)(this + 0xac) ^ ((uint)(*(int *)param_2 != 0) ^ *(uint *)(this + 0xac)) & 1;
      return 0;
    case 0x6004003:
      CMwParamVec3::SetValue((CMwParamVec3 *)param_1,(CMwCmdAffectParamBool *)(this + 0x94));
      return extraout_EAX;
    case 0x6004004:
      uVar5 = *(uint *)param_2;
      if (3 < uVar5) {
        uVar5 = 3;
      }
      *(uint *)(this + 0xac) = *(uint *)(this + 0xac) ^ (uVar5 * 2 ^ *(uint *)(this + 0xac)) & 6;
      return 0;
    case 0x6004005:
      uVar5 = *(uint *)param_2;
      if (1 < uVar5) {
        uVar5 = 1;
      }
      *(uint *)(this + 0xac) = *(uint *)(this + 0xac) ^ (uVar5 * 8 ^ *(uint *)(this + 0xac)) & 8;
      return 0;
    case 0x6004006:
      *(undefined4 *)(this + 0xa0) = *(undefined4 *)param_2;
      return 0;
    case 0x6004007:
      *(undefined4 *)(this + 0xa4) = *(undefined4 *)param_2;
      return 0;
    case 0x6004008:
      *(undefined4 *)(this + 0xa8) = *(undefined4 *)param_2;
      return 0;
    case 0x6004012:
      pCVar7 = (CMwCmdAffectParamBool *)(this + 0xd0);
      CMwParamVec3::SetValue((CMwParamVec3 *)param_1,pCVar7);
      if (_DAT_00cdcda8 <
          *(float *)(this + 0xd8) * *(float *)(this + 0xd8) +
          *(float *)pCVar7 * *(float *)pCVar7 + *(float *)(this + 0xd4) * *(float *)(this + 0xd4)) {
        fVar8 = (float10)func_0x009c1b40();
        fVar4 = 1.0 / (float)fVar8;
        *(float *)pCVar7 = fVar4 * *(float *)pCVar7;
        *(float *)(this + 0xd4) = *(float *)(this + 0xd4) * fVar4;
        *(float *)(this + 0xd8) = fVar4 * *(float *)(this + 0xd8);
        return 0;
      }
      *(undefined4 *)pCVar7 = 0;
      *(undefined4 *)(this + 0xd4) = 0x3f800000;
      *(undefined4 *)(this + 0xd8) = 0;
      return 0;
    case 0x6004013:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^ (*(int *)param_2 != 0 ^ (byte)this[0xec]) & 1;
      return 0;
    case 0x6004014:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^ (byte)((*(int *)param_2 != 0) * '\x02' ^ (byte)this[0xec]) & 2
      ;
      return 0;
    case 0x6004015:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^ (byte)((*(int *)param_2 != 0) * '\x04' ^ (byte)this[0xec]) & 4
      ;
      return 0;
    case 0x6004016:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^ (byte)((*(int *)param_2 != 0) * '\b' ^ (byte)this[0xec]) & 8;
      return 0;
    case 0x6004017:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^ (byte)((*(int *)param_2 != 0) << 4 ^ (byte)this[0xec]) & 0x10;
      return 0;
    case 0x6004018:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^ (byte)((*(int *)param_2 != 0) << 5 ^ (byte)this[0xec]) & 0x20;
      return 0;
    case 0x6004019:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^ (byte)((*(int *)param_2 != 0) << 6 ^ (byte)this[0xec]) & 0x40;
      return 0;
    case 0x600401a:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^ (byte)((*(int *)param_2 != 0) << 7 ^ (byte)this[0xec]) & 0x80;
      return 0;
    case 0x600401b:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^
           ((ushort)(*(int *)param_2 != 0) << 8 ^ *(ushort *)(this + 0xec)) & 0x100;
      return 0;
    case 0x600401c:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^
           ((ushort)(*(int *)param_2 != 0) << 9 ^ *(ushort *)(this + 0xec)) & 0x200;
      return 0;
    case 0x600401d:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^
           ((ushort)(*(int *)param_2 != 0) << 10 ^ *(ushort *)(this + 0xec)) & 0x400;
      return 0;
    case 0x600401e:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^
           ((ushort)(*(int *)param_2 != 0) << 0xb ^ *(ushort *)(this + 0xec)) & 0x800;
      return 0;
    case 0x600401f:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^
           ((ushort)(*(int *)param_2 != 0) << 0xc ^ *(ushort *)(this + 0xec)) & 0x1000;
      return 0;
    case 0x6004020:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^
           ((ushort)(*(int *)param_2 != 0) << 0xd ^ *(ushort *)(this + 0xec)) & 0x2000;
      return 0;
    case 0x6004021:
      *(ushort *)(this + 0xec) =
           *(ushort *)(this + 0xec) ^
           ((ushort)(*(int *)param_2 != 0) << 0xe ^ *(ushort *)(this + 0xec)) & 0x4000;
      return 0;
    case 0x6004022:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^ (*(int *)param_2 != 0 ^ (byte)this[0xee]) & 1;
      return 0;
    case 0x6004023:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^ (byte)((*(int *)param_2 != 0) * '\x02' ^ (byte)this[0xee]) & 2
      ;
      return 0;
    case 0x6004024:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^ (byte)((*(int *)param_2 != 0) * '\x04' ^ (byte)this[0xee]) & 4
      ;
      return 0;
    case 0x6004025:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^ (byte)((*(int *)param_2 != 0) * '\b' ^ (byte)this[0xee]) & 8;
      return 0;
    case 0x6004026:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^ (byte)((*(int *)param_2 != 0) << 4 ^ (byte)this[0xee]) & 0x10;
      return 0;
    case 0x6004027:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^ (byte)((*(int *)param_2 != 0) << 5 ^ (byte)this[0xee]) & 0x20;
      return 0;
    case 0x6004028:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^ (byte)((*(int *)param_2 != 0) << 6 ^ (byte)this[0xee]) & 0x40;
      return 0;
    case 0x6004029:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^ (byte)((*(int *)param_2 != 0) << 7 ^ (byte)this[0xee]) & 0x80;
      return 0;
    case 0x600402a:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^
           ((ushort)(*(int *)param_2 != 0) << 8 ^ *(ushort *)(this + 0xee)) & 0x100;
      return 0;
    case 0x600402b:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^
           ((ushort)(*(int *)param_2 != 0) << 9 ^ *(ushort *)(this + 0xee)) & 0x200;
      return 0;
    case 0x600402c:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^
           ((ushort)(*(int *)param_2 != 0) << 10 ^ *(ushort *)(this + 0xee)) & 0x400;
      return 0;
    case 0x600402d:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^
           ((ushort)(*(int *)param_2 != 0) << 0xb ^ *(ushort *)(this + 0xee)) & 0x800;
      return 0;
    case 0x600402e:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^
           ((ushort)(*(int *)param_2 != 0) << 0xc ^ *(ushort *)(this + 0xee)) & 0x1000;
      return 0;
    case 0x600402f:
      *(ushort *)(this + 0xee) =
           *(ushort *)(this + 0xee) ^
           ((ushort)(*(int *)param_2 != 0) << 0xd ^ *(ushort *)(this + 0xee)) & 0x2000;
      return 0;
    }
  }
  else if (uVar5 < 0x6004044) {
    if (uVar5 == 0x6004043) {
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^ (byte)((*(int *)param_2 != 0) * '\b' ^ (byte)this[0xf2]) & 8;
      return 0;
    }
    switch(uVar5) {
    case 0x6004031:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^ (*(int *)param_2 != 0 ^ (byte)this[0xf0]) & 1;
      return 0;
    case 0x6004032:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^ (byte)((*(int *)param_2 != 0) * '\x02' ^ (byte)this[0xf0]) & 2
      ;
      return 0;
    case 0x6004033:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^ (byte)((*(int *)param_2 != 0) * '\x04' ^ (byte)this[0xf0]) & 4
      ;
      return 0;
    case 0x6004034:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^ (byte)((*(int *)param_2 != 0) * '\b' ^ (byte)this[0xf0]) & 8;
      return 0;
    case 0x6004035:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^ (byte)((*(int *)param_2 != 0) << 4 ^ (byte)this[0xf0]) & 0x10;
      return 0;
    case 0x6004036:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^ (byte)((*(int *)param_2 != 0) << 5 ^ (byte)this[0xf0]) & 0x20;
      return 0;
    case 0x6004037:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^ (byte)((*(int *)param_2 != 0) << 6 ^ (byte)this[0xf0]) & 0x40;
      return 0;
    case 0x6004038:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^ (byte)((*(int *)param_2 != 0) << 7 ^ (byte)this[0xf0]) & 0x80;
      return 0;
    case 0x6004039:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^
           ((ushort)(*(int *)param_2 != 0) << 8 ^ *(ushort *)(this + 0xf0)) & 0x100;
      return 0;
    case 0x600403a:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^
           ((ushort)(*(int *)param_2 != 0) << 9 ^ *(ushort *)(this + 0xf0)) & 0x200;
      return 0;
    case 0x600403b:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^
           ((ushort)(*(int *)param_2 != 0) << 10 ^ *(ushort *)(this + 0xf0)) & 0x400;
      return 0;
    case 0x600403c:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^
           ((ushort)(*(int *)param_2 != 0) << 0xb ^ *(ushort *)(this + 0xf0)) & 0x800;
      return 0;
    case 0x600403d:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^
           ((ushort)(*(int *)param_2 != 0) << 0xc ^ *(ushort *)(this + 0xf0)) & 0x1000;
      return 0;
    case 0x600403e:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^
           ((ushort)(*(int *)param_2 != 0) << 0xd ^ *(ushort *)(this + 0xf0)) & 0x2000;
      return 0;
    case 0x600403f:
      *(ushort *)(this + 0xf0) =
           *(ushort *)(this + 0xf0) ^
           ((ushort)(*(int *)param_2 != 0) << 0xe ^ *(ushort *)(this + 0xf0)) & 0x4000;
      return 0;
    case 0x6004040:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^ (*(int *)param_2 != 0 ^ (byte)this[0xf2]) & 1;
      return 0;
    case 0x6004041:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^ (byte)((*(int *)param_2 != 0) * '\x02' ^ (byte)this[0xf2]) & 2
      ;
      return 0;
    case 0x6004042:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^ (byte)((*(int *)param_2 != 0) * '\x04' ^ (byte)this[0xf2]) & 4
      ;
      return 0;
    }
  }
  else if (uVar5 < 0x600404d) {
    if (uVar5 == 0x600404c) {
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^
           ((ushort)(*(int *)param_2 != 0) << 0xc ^ *(ushort *)(this + 0xf2)) & 0x1000;
      return 0;
    }
    switch(uVar5) {
    case 0x6004044:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^ (byte)((*(int *)param_2 != 0) << 4 ^ (byte)this[0xf2]) & 0x10;
      return 0;
    case 0x6004045:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^ (byte)((*(int *)param_2 != 0) << 5 ^ (byte)this[0xf2]) & 0x20;
      return 0;
    case 0x6004046:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^ (byte)((*(int *)param_2 != 0) << 6 ^ (byte)this[0xf2]) & 0x40;
      return 0;
    case 0x6004047:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^ (byte)((*(int *)param_2 != 0) << 7 ^ (byte)this[0xf2]) & 0x80;
      return 0;
    case 0x6004048:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^
           ((ushort)(*(int *)param_2 != 0) << 8 ^ *(ushort *)(this + 0xf2)) & 0x100;
      return 0;
    case 0x6004049:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^
           ((ushort)(*(int *)param_2 != 0) << 9 ^ *(ushort *)(this + 0xf2)) & 0x200;
      return 0;
    case 0x600404a:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^
           ((ushort)(*(int *)param_2 != 0) << 10 ^ *(ushort *)(this + 0xf2)) & 0x400;
      return 0;
    case 0x600404b:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^
           ((ushort)(*(int *)param_2 != 0) << 0xb ^ *(ushort *)(this + 0xf2)) & 0x800;
      return 0;
    }
  }
  else {
    if (0x6004051 < uVar5) {
      if (uVar5 == 0x6004052) {
        pGVar3 = *(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                   **)(this + 0x104);
        GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::Update
                  (pGVar3,*(SGmSmoothReal2 **)(pGVar3 + 0x4c),*(int *)(pGVar3 + 0x50),
                   *(ulong *)param_2);
      }
      else {
        if (uVar5 == 0x6004058) {
          pGVar3 = *(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                     **)(this + 0x104);
          GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
          Update(pGVar3,*(SGmSmoothReal2 **)(pGVar3 + 0x4c),*(int *)(pGVar3 + 0x50),
                 *(ulong *)(pGVar3 + 0x54));
          return 0;
        }
        if (uVar5 != 0xffffffff) goto switchD_0054fe0c_caseD_6004009;
      }
      return 0;
    }
    if (uVar5 == 0x6004051) {
      pGVar3 = *(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 **)(this + 0x104);
      GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::Update
                (pGVar3,*(SGmSmoothReal2 **)(pGVar3 + 0x4c),*(int *)param_2,
                 *(ulong *)(pGVar3 + 0x54));
      return 0;
    }
    switch(uVar5) {
    case 0x600404d:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^
           ((ushort)(*(int *)param_2 != 0) << 0xd ^ *(ushort *)(this + 0xf2)) & 0x2000;
      return 0;
    case 0x600404e:
      *(ushort *)(this + 0xf2) =
           *(ushort *)(this + 0xf2) ^
           ((ushort)(*(int *)param_2 != 0) << 0xe ^ *(ushort *)(this + 0xf2)) & 0x4000;
      return 0;
    case 0x600404f:
      SHmsVPackerCreate::SHmsVPackerCreate(local_28,unaff_EDI);
      local_1c = 2;
      local_20 = 2;
      local_24 = 2;
      VPackerCreate(this,(CHmsZone *)&local_24,unaff_ESI);
      return 0;
    case 0x6004050:
      pGVar3 = *(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 **)(this + 0x104);
      GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::Update
                (pGVar3,*(SGmSmoothReal2 **)param_2,*(int *)(pGVar3 + 0x50),
                 *(ulong *)(pGVar3 + 0x54));
      return 0;
    }
  }
switchD_0054fe0c_caseD_6004009:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar6 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,unaff_EDI);
  return uVar6;
}
}

// =================================================
// Function: CHmsZone::VirtualParam_Sub
// =================================================
ulong __thiscall
CHmsZone::VirtualParam_Sub
          (CHmsZone *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  GmVec4 *pGVar6;
  void *unaff_ESI;
  void *unaff_EDI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  iVar3 = iVar1 + -1;
  *(int *)(param_1 + 0x18) = iVar3;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x600400a) {
    if (iVar3 < 0) {
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x88,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_2,
                          (ulong)unaff_EDI);
      if (*(int **)pSVar5 != (int *)0x0) {
        (**(code **)(**(int **)pSVar5 + 4))(1);
      }
    }
    if (*(int *)(param_1 + 0x18) < 0) {
      CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt
                ((CFastBufferCat<class_GmVec4,struct_SFastCat> *)(this + 0x88),
                 *(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> **)param_2,1,
                 (ulong)unaff_ESI);
      return 0;
    }
    pGVar6 = CMwParamFastBuffer<class_CMwParamMwId>::GetElemFromStack
                       ((CFastBufferCat<class_GmVec4,struct_SFastCat> *)(this + 0x88),
                        (CMwStack *)param_1);
    if (-1 < *(int *)(param_1 + 0x18)) {
      CMwNod::Param_Sub(*(CMwNod **)pGVar6,(CMwNod *)param_1,param_2,unaff_ESI);
    }
  }
  else {
    if (iVar2 == 0x600400b) {
      if (iVar3 < 0) {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0xf4,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_2,
                            (ulong)unaff_EDI);
        if (*(int **)pSVar5 != (int *)0x0) {
          (**(code **)(**(int **)pSVar5 + 4))(1);
        }
      }
      CMwParamFastBuffer<class_CMwParamClass>::SubValue
                ((CFastBufferCat<class_GmVec2,struct_SFastCat> *)(this + 0xf4),(CMwStack *)param_1,
                 param_2);
      return 0;
    }
    if (iVar2 != -1) {
      *(int *)(param_1 + 0x18) = iVar1;
      uVar4 = CMwNod::VirtualParam_Sub((CMwNod *)this,param_1,param_2,unaff_EDI);
      return uVar4;
    }
  }
  return 0;
}
}

// =================================================
// Function: CHmsZone::WaterRenderTileHeightSet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsZone::WaterRenderTileHeightSet(CHmsZone *this,CHmsZone *param_1,float param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *unaff_EDI;
  
  if ((float)param_1 == *(float *)(this + 0x108)) {
    return;
  }
  if ((*(float *)(this + 0x108) <= _DAT_00b37b60) &&
     (_DAT_00b37b60 < (float)param_1 != (_DAT_00b37b60 == (float)param_1))) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll
                       (this + 0x1c,unaff_EDI);
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::operator[]
                  (this + 0x1c,pCVar2,unaff_ESI);
        unaff_ESI = 0x54e15f;
        Zone_UpdateWaterHeights((CHmsCorpus *)0x54e15f);
        pCVar2 = pCVar2 + 1;
      } while (pCVar2 < pCVar1);
    }
    *(float *)(this + 0x108) = param_2;
    return;
  }
  *(CHmsZone **)(this + 0x108) = param_1;
  return;
}
}

// =================================================
// Function: CHmsZone::_vector_deleting_destructor_
// =================================================
void * __thiscall
CHmsZone::_vector_deleting_destructor_(CHmsZone *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CHmsZone *unaff_ESI;
  
  ~CHmsZone(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CHmsZone::~CHmsZone
// =================================================
void __thiscall CHmsZone::~CHmsZone(CHmsZone *this,CHmsZone *param_1)
{
{
  CHmsZone *pCVar1;
  CHmsZoneOverlay *pCVar2;
  int *piVar3;
  SShaderCustom *pSVar4;
  int iVar5;
  SCasterCat *pSVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  ulong uVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  SShaderCustom *unaff_EBP;
  CAudioSound *unaff_ESI;
  CAudioPort *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  uint uVar10;
  CMwNod *unaff_retaddr;
  CMwNod *in_stack_00000008;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_0000000c;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_00000010;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_00000014;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_00000018;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_0000001c;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_00000020;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_00000024;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_00000028;
  CMwNod *in_stack_0000002c;
  void *in_stack_00000048;
  undefined4 uStack0000004c;
  CHmsZone *pCVar11;
  CFastArray<class_CCrystalEdge*> *pCVar12;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar13;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar14;
  
  pCVar12 = ExceptionList;
  pCVar13 = (CFastBuffer<class_CPlugFileGPUV*> *)&LAB_00a968d3;
  pSVar4 = (SShaderCustom *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar1 = this + 0x10c;
  pCVar14 = (CFastBuffer<class_CPlugFileGPUV*> *)&DAT_0000000b;
  pCVar11 = this;
  iVar5 = CFastBuffer<class_CAudioSound*>::IsEmpty(pCVar1,pSVar4);
  while (iVar5 == 0) {
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)unaff_EDI);
    unaff_EDI = *(CAudioPort **)pSVar6;
    RemoveSound(this,unaff_EDI,unaff_ESI);
    unaff_ESI = (CAudioSound *)0x54e90a;
    iVar5 = CFastBuffer<class_CAudioSound*>::IsEmpty(pCVar1,unaff_EBP);
  }
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (*(undefined4 **)(this + 0x104) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x104))(1);
  }
  *(undefined4 *)(this + 0x104) = 0;
  CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat>::DeleteAll
            (this + 0x58,(CFastArray<class_CCrystalEdge*> *)unaff_EDI);
  pCVar1 = this + 0x7c;
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (pCVar1,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar1,pCVar9,(ulong)unaff_EBP);
      pCVar9 = pCVar9 + 1;
      *(undefined4 *)(*(int *)pSVar6 + 0x14) = 0;
    } while (pCVar9 < pCVar7);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pCVar1,(GmFrustumIso4 *)unaff_EBP);
  iVar5 = *(int *)(this + 0x2c);
  uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_EBX);
  uVar10 = 0;
  if (uVar8 != 0) {
    do {
      pCVar2 = *(CHmsZoneOverlay **)(iVar5 + uVar10 * 4);
      CHmsItem::RemoveCorpus(*(CHmsItem **)(pCVar2 + 0x48),pCVar2,(CHmsCorpus *)pCVar11);
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar8);
  }
  uVar10 = 0;
  if (uVar8 != 0) {
    do {
      piVar3 = *(int **)(iVar5 + uVar10 * 4);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar8);
  }
  if (*(undefined4 **)(this + 0x118) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x118))();
  }
  CFastBuffer<class_CPlugBitmapPackInput*>::DeleteAll
            (this + 0x88,(CFastArray<class_CCrystalEdge*> *)pCVar11);
  CFastBuffer<class_CPlugBitmapPackInput*>::DeleteAll(this + 0xf4,pCVar12);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x10c,pCVar13);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0xf4,pCVar14);
  in_stack_00000020 = (CFastBuffer<class_CPlugFileGPUV*> *)CONCAT31(in_stack_00000020._1_3_,8);
  if (*(CMwNod **)(this + 0xe8) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xe8),unaff_retaddr);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0xdc,(CFastBuffer<class_CPlugFileGPUV*> *)param_1);
  in_stack_00000028 = (CFastBuffer<class_CPlugFileGPUV*> *)CONCAT31(in_stack_00000028._1_3_,6);
  if (*(CMwNod **)(this + 0xb0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xb0),in_stack_00000008);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x88,in_stack_0000000c);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x7c,in_stack_00000010);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 100,in_stack_00000014);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x58,in_stack_00000018);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x4c,in_stack_0000001c);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x40,in_stack_00000020);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x28,in_stack_00000024);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x1c,in_stack_00000028);
  uStack0000004c = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this,in_stack_0000002c);
  ExceptionList = in_stack_00000048;
  return;
}
}

