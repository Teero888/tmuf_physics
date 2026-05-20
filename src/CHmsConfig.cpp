// Class implementation: CHmsConfig

// =================================================
// Function: CHmsConfig::CHmsConfig
// =================================================
void __thiscall CHmsConfig::CHmsConfig(CHmsConfig *this,CHmsConfig *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0x20,(CFastArray<class_CManoeuvre*> *)param_1);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}
}

// =================================================
// Function: CHmsConfig::Chunk
// =================================================
void __thiscall
CHmsConfig::Chunk(CHmsConfig *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CClassicArchive *unaff_ESI;
  CFastBuffer<class_CSystemPackDesc*> *unaff_EDI;
  CFastBuffer<class_CMwNod*> *unaff_retaddr;
  
  if (param_2 < (CClassicArchive *)0x601d003) {
    if (param_2 == (CClassicArchive *)0x601d002) {
      CClassicArchive::DoBool
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x14),(int *)0x1,
                 (ulong)unaff_EDI);
      CClassicArchive::DoNatural
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x18),(ulong *)0x1,0,
                 (int)unaff_ESI);
      return;
    }
    if (param_2 == (CClassicArchive *)0x601d000) {
      if (*(int *)(param_1 + 8) == 0) {
        CFastArray<class_CFuncKeysPath*>::ReleaseAll(this + 0x20,unaff_EDI);
      }
      CFastArray<class_CPlugSoundEngineComponent*>::ArchiveCountAndNods
                (this + 0x20,(CFastArray<class_CPlugSoundEngineComponent*> *)param_1,unaff_ESI);
      if (*(int *)(param_1 + 8) != 0) {
        return;
      }
      CFastBuffer<class_CMwNod*>::AddRefAll(this + 0x20,unaff_retaddr);
      return;
    }
    if (param_2 == (CClassicArchive *)0x601d001) {
      CClassicArchive::DoBool
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x14),(int *)0x1,
                 (ulong)unaff_EDI);
      return;
    }
  }
  else if (param_2 == (CClassicArchive *)0xffffffff) {
    return;
  }
  CMwNod::Chunk((CMwNod *)this,param_1,param_2,(ulong)unaff_EDI);
  return;
}
}

// =================================================
// Function: CHmsConfig::CopyFromConfig
// =================================================
void __thiscall CHmsConfig::CopyFromConfig(CHmsConfig *this,CHmsConfig *param_1,CHmsConfig *param_2)
{
{
  CFastArray<class_CHmsShadowGroup*> *unaff_EDI;
  
  CopyFromShadowGroups(this,param_1 + 0x20,unaff_EDI);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  return;
}
}

// =================================================
// Function: CHmsConfig::CopyFromShadowGroups
// =================================================
void __thiscall
CHmsConfig::CopyFromShadowGroups
          (CHmsConfig *this,CHmsConfig *param_1,CFastArray<class_CHmsShadowGroup*> *param_2)
{
{
  CHmsConfig *this_00;
  CFastBuffer<class_CSystemPackDesc*> *unaff_ESI;
  CFastArray<class_GmVec4> *unaff_retaddr;
  
  this_00 = this + 0x20;
  CFastArray<class_CFuncKeysPath*>::ReleaseAll(this_00,unaff_ESI);
  CFastArray<class_CControlBase*>::CopyFromFastArray
            (this_00,(CFastArray<class_GmVec4> *)param_2,unaff_retaddr);
  CFastBuffer<class_CMwNod*>::AddRefAll(this_00,(CFastBuffer<class_CMwNod*> *)param_1);
  return;
}
}

// =================================================
// Function: CHmsConfig::CreateDefaultData
// =================================================
void __thiscall CHmsConfig::CreateDefaultData(CHmsConfig *this,CCrystal *param_1)
{
{
  CHmsConfig *this_00;
  CHmsShadowGroup *this_01;
  undefined4 extraout_EAX;
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  CHmsShadowGroup *unaff_EDI;
  undefined4 uVar2;
  void *in_stack_00000010;
  undefined1 *puVar3;
  _func___cdecl_void_CMwNod_ptr_CFastString_ptr *p_Var4;
  
  p_Var4 = (_func___cdecl_void_CMwNod_ptr_CFastString_ptr *)0xffffffff;
  puVar3 = &LAB_00a9663b;
  ExceptionList = &stack0xfffffff4;
  this_00 = this + 0x20;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,
             DAT_00cca150 ^ (uint)&stack0xffffffe8);
  this_01 = operator_new(0x9c);
  if (this_01 == (CHmsShadowGroup *)0x0) {
    uVar2 = 0;
  }
  else {
    CHmsShadowGroup::CHmsShadowGroup(this_01,unaff_EDI);
    uVar2 = extraout_EAX;
  }
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  *(undefined4 *)pSVar1 = uVar2;
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)this);
  CMwNod::MwAddRef(*(CMwNod **)pSVar1,(CMwNod *)this_01);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)puVar3);
  CGameControlCardManager::SetGetDataTypeInfosFromNodCallBack
            (*(CGameControlCardManager **)pSVar1,(CGameControlCardManager *)&DAT_00000080,
             (CMwNod *)&DAT_00000080,p_Var4);
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CHmsConfig::GetChunkInfo
// =================================================
ulong __thiscall CHmsConfig::GetChunkInfo(CHmsConfig *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 < (CFuncSegment *)0x601d003) {
    if (param_1 == (CFuncSegment *)0x601d002) {
      return 0x13;
    }
    if (param_1 == (CFuncSegment *)0x601d000) {
      return 3;
    }
    if (param_1 == (CFuncSegment *)0x601d001) {
      return 0x11;
    }
  }
  else if (param_1 == (CFuncSegment *)0xffffffff) {
    return 0xffffffff;
  }
  uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
  return uVar1;
}
}

// =================================================
// Function: CHmsConfig::GetMwClassId
// =================================================
ulong __thiscall CHmsConfig::GetMwClassId(CHmsConfig *this,CControlStyle *param_1)
{
{
  return 0x601d000;
}
}

// =================================================
// Function: CHmsConfig::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CHmsConfig::GetUidChunkFromIndex(CHmsConfig *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x601d000;
}
}

// =================================================
// Function: CHmsConfig::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CHmsConfig::MwGetClassInfo(CHmsConfig *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d676e0;
}
}

// =================================================
// Function: CHmsConfig::MwIsKindOf
// =================================================
int __thiscall CHmsConfig::MwIsKindOf(CHmsConfig *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0x601d000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CHmsConfig::MwNewCHmsConfig
// =================================================
CMwNod * __cdecl CHmsConfig::MwNewCHmsConfig(void)
{
{
  CHmsConfig *pCVar1;
  CMwNod *extraout_EAX;
  CHmsConfig *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9669b;
  local_c = ExceptionList;
  pCVar1 = (CHmsConfig *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x28);
  local_4 = 0;
  if (local_10 != (CHmsConfig *)0x0) {
    CHmsConfig(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CHmsConfig::ShadowGroupsSetCount
// =================================================
void __thiscall CHmsConfig::ShadowGroupsSetCount(CHmsConfig *this,CHmsConfig *param_1,ulong param_2)
{
{
  CHmsConfig *this_00;
  CFastBuffer<class_CCrystalFace*> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  CHmsShadowGroup *this_01;
  undefined4 extraout_EAX;
  SCasterCat *pSVar3;
  undefined4 uVar4;
  CHmsShadowGroup *unaff_ESI;
  ulong unaff_EDI;
  ulong uVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CMwNod *pCVar7;
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a9666b;
  local_c = ExceptionList;
  pCVar1 = (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  this_00 = this + 0x20;
  uVar5 = 0x54c98e;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar1);
  if (pCVar2 < param_2) {
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x54c9a0;
    CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
              (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)param_2,unaff_EDI);
    for (; pCVar2 < param_2; pCVar2 = pCVar2 + 1) {
      pCVar7 = (CMwNod *)0x9c;
      uVar5 = 0x54c9ae;
      this_01 = operator_new(0x9c);
      uVar4 = 0;
      if (this_01 != (CHmsShadowGroup *)0x0) {
        pCVar7 = (CMwNod *)0x54c9c6;
        CHmsShadowGroup::CHmsShadowGroup(this_01,unaff_ESI);
        uVar4 = extraout_EAX;
      }
      puStack_8 = (undefined1 *)0xffffffff;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar2,(ulong)pCVar6);
      *(undefined4 *)pSVar3 = uVar4;
      pCVar6 = pCVar2;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar2,uVar5);
      CMwNod::MwAddRef(*(CMwNod **)pSVar3,pCVar7);
    }
  }
  else {
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2;
    if (param_2 < pCVar2) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar6,uVar5);
        uVar5 = 0x54ca05;
        CMwNod::MwRelease(*(CMwNod **)pSVar3,(CMwNod *)pCVar1);
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < pCVar2);
      CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
                (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)param_2,unaff_EDI);
    }
  }
  ExceptionList = pvStack_4;
  return;
}
}

// =================================================
// Function: CHmsConfig::_vector_deleting_destructor_
// =================================================
void * __thiscall
CHmsConfig::_vector_deleting_destructor_(CHmsConfig *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CHmsConfig *unaff_ESI;
  
  ~CHmsConfig(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CHmsConfig::~CHmsConfig
// =================================================
void __thiscall CHmsConfig::~CHmsConfig(CHmsConfig *this,CHmsConfig *param_1)
{
{
  CFastBuffer<class_CSystemPackDesc*> *pCVar1;
  CMwNod *unaff_ESI;
  CFastArray<class_CFuncShader*> *unaff_EDI;
  void *unaff_retaddr;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a96613;
  local_c = ExceptionList;
  pCVar1 = (CFastBuffer<class_CSystemPackDesc*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  CFastArray<class_CFuncKeysPath*>::ReleaseAll(this + 0x20,pCVar1);
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(this + 0x20,unaff_EDI);
  CMwNod::~CMwNod((CMwNod *)this,unaff_ESI);
  ExceptionList = unaff_retaddr;
  return;
}
}

