// Class implementation: CSceneVehicleTunings

// =================================================
// Function: CSceneVehicleTunings::CSceneVehicleTunings
// =================================================
void __thiscall
CSceneVehicleTunings::CSceneVehicleTunings(CSceneVehicleTunings *this,CSceneVehicleTunings *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x14,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x20) = 0xa02e000;
  return;
}
}

// =================================================
// Function: CSceneVehicleTunings::Chunk
// =================================================
void __thiscall
CSceneVehicleTunings::Chunk
          (CSceneVehicleTunings *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  ulong unaff_ESI;
  CClassicArchive *unaff_EDI;
  
  if (param_2 == (CClassicArchive *)0xa030000) {
    CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_>::ArchiveFastBufferNodRef
              (this + 0x14,(CFastBuffer<class_CMwNodRef<class_CMwNod>_> *)param_1,unaff_EDI);
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x24),(ulong *)0x1,0,unaff_ESI)
    ;
  }
  else if (param_2 != (CClassicArchive *)0xffffffff) {
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,unaff_ESI);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleTunings::GetChunkInfo
// =================================================
ulong __thiscall
CSceneVehicleTunings::GetChunkInfo(CSceneVehicleTunings *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 == (CFuncSegment *)0xa030000) {
    return 3;
  }
  if (param_1 != (CFuncSegment *)0xffffffff) {
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
    return uVar1;
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CSceneVehicleTunings::GetMwClassId
// =================================================
ulong __thiscall
CSceneVehicleTunings::GetMwClassId(CSceneVehicleTunings *this,CControlStyle *param_1)
{
{
  return 0xa030000;
}
}

// =================================================
// Function: CSceneVehicleTunings::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CSceneVehicleTunings::GetUidChunkFromIndex
          (CSceneVehicleTunings *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0xa030000;
}
}

// =================================================
// Function: CSceneVehicleTunings::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall
CSceneVehicleTunings::MwGetClassInfo(CSceneVehicleTunings *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6d708;
}
}

// =================================================
// Function: CSceneVehicleTunings::MwIsKindOf
// =================================================
int __thiscall
CSceneVehicleTunings::MwIsKindOf
          (CSceneVehicleTunings *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0xa030000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CSceneVehicleTunings::MwNewCSceneVehicleTunings
// =================================================
CMwNod * __cdecl CSceneVehicleTunings::MwNewCSceneVehicleTunings(void)
{
{
  CSceneVehicleTunings *pCVar1;
  CMwNod *extraout_EAX;
  CSceneVehicleTunings *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ad061b;
  local_c = ExceptionList;
  pCVar1 = (CSceneVehicleTunings *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x28);
  local_4 = 0;
  if (local_10 != (CSceneVehicleTunings *)0x0) {
    CSceneVehicleTunings(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CSceneVehicleTunings::VirtualParam_Add
// =================================================
ulong __thiscall
CSceneVehicleTunings::VirtualParam_Add
          (CSceneVehicleTunings *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  ulong uVar2;
  int iVar3;
  SLoadedLight *this_00;
  void *unaff_ESI;
  CGameCamera *unaff_EDI;
  CMwNodRef<class_CGameCamera> *pCVar4;
  
  iVar3 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + iVar3 * 4);
  *(int *)(param_1 + 0x18) = iVar3 + -1;
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == 0xa030001) {
    if ((iVar3 + -1 < 0) && (param_2 != (CMwStack *)0x0)) {
      pCVar4 = *(CMwNodRef<class_CGameCamera> **)(this + 0x20);
      iVar3 = (**(code **)(*(int *)param_2 + 0x10))();
      if (iVar3 != 0) {
        this_00 = CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_>::AddNewElem
                            (this + 0x14,
                             (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)param_2);
        CMwNodRef<class_CGameCamera>::MwSetNod(this_00,pCVar4,unaff_EDI);
      }
    }
  }
  else if (iVar1 != -1) {
    *(int *)(param_1 + 0x18) = iVar3;
    uVar2 = CMwNod::VirtualParam_Add((CMwNod *)this,param_1,param_2,unaff_ESI);
    return uVar2;
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicleTunings::VirtualParam_Get
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CSceneVehicleTunings::VirtualParam_Get
          (CSceneVehicleTunings *this,CPlugBlendShapes *param_1,CMwStack *param_2,
          CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong uVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  CMwValueStd *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *in_stack_00000010;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa030000) {
    if ((_DAT_00d6d704 & 1) == 0) {
      _DAT_00d6d704 = _DAT_00d6d704 | 1;
      _DAT_00d6d6fc = 0;
      DAT_00d6d700 = PTR_DAT_00bbf7d8;
      _atexit(`public:_virtual_unsigned_long___thiscall_CSceneVehicleTunings::
              VirtualParam_Get(class_CMwStack*,class_CMwValueStd*)'::__l6::
              _dynamic_atexit_destructor_for__StrCrc__);
    }
    pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x24);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x14,unaff_EDI);
    if (pCVar3 < pCVar5) {
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x14,pCVar3,(ulong)unaff_ESI);
      CSystemArchiveNod::ComputeCrcString(*(CMwNod **)pSVar6,(CFastString *)&DAT_00d6d6fc);
    }
    *in_stack_00000010 = &DAT_00d6d6fc;
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar4 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,unaff_ESI);
    return uVar4;
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicleTunings::VirtualParam_Set
// =================================================
ulong __thiscall
CSceneVehicleTunings::VirtualParam_Set
          (CSceneVehicleTunings *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  GmVec4 *pGVar4;
  CFastStringInt *unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa030001) {
    if (-1 < iVar1 + -1) {
      pGVar4 = CMwParamFastBuffer<class_CMwParamMwId>::GetElemFromStack
                         ((CFastBufferCat<class_GmVec4,struct_SFastCat> *)(this + 0x14),
                          (CMwStack *)param_1);
      if (*(int *)(param_1 + 0x18) < 0) {
        *(CMwStack **)pGVar4 = param_2;
        return 0;
      }
      CMwNod::Param_Set(*(CMwNod **)pGVar4,(CMwNod *)param_1,(CFastString *)param_2,unaff_ESI);
    }
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,unaff_ESI);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicleTunings::VirtualParam_Sub
// =================================================
ulong __thiscall
CSceneVehicleTunings::VirtualParam_Sub
          (CSceneVehicleTunings *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,
          void *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  void *unaff_ESI;
  ulong unaff_EDI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa030001) {
    if (iVar1 + -1 < 0) {
      CFastBufferRef<class_CGameCtnMediaClip>::RemoveAt
                (this + 0x14,
                 *(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> **)param_2,1,
                 unaff_EDI);
      uVar3 = *(uint *)(this + 0x24);
      uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x14,unaff_EBX);
      if ((uVar4 <= uVar3) && (uVar3 != 0)) {
        *(uint *)(this + 0x24) = uVar3 - 1;
      }
    }
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar4 = CMwNod::VirtualParam_Sub((CMwNod *)this,param_1,param_2,unaff_ESI);
    return uVar4;
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicleTunings::_vector_deleting_destructor_
// =================================================
void * __thiscall
CSceneVehicleTunings::_vector_deleting_destructor_
          (CSceneVehicleTunings *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CSceneVehicleTunings *unaff_ESI;
  
  ~CSceneVehicleTunings(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CSceneVehicleTunings::~CSceneVehicleTunings
// =================================================
void __thiscall
CSceneVehicleTunings::~CSceneVehicleTunings
          (CSceneVehicleTunings *this,CSceneVehicleTunings *param_1)
{
{
  CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_> *pCVar1;
  CMwNod *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00ad05e8;
  local_c = ExceptionList;
  pCVar1 = (CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_> *)
           (DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = (void *)0x0;
  CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_>::
  ~CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_>(this + 0x14,pCVar1);
  CMwNod::~CMwNod((CMwNod *)this,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

