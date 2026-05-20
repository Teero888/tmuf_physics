// Class implementation: CHmsCollisionManager

// =================================================
// Function: CHmsCollisionManager::AddZone
// =================================================
SZone * __thiscall
CHmsCollisionManager::AddZone
          (CHmsCollisionManager *this,CHmsCollisionManager *param_1,ulong param_2)
{
{
  CHmsCollisionManager *pCVar1;
  void *this_00;
  SZone *extraout_EAX;
  SZone *pSVar2;
  TiXmlAttribute *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a9575b;
  local_c = ExceptionList;
  pCVar1 = (CHmsCollisionManager *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  this_00 = operator_new(0x1ac);
  pSVar2 = (SZone *)0x0;
  local_4 = (void *)0x0;
  if (this_00 != (void *)0x0) {
    SZone::SZone(this_00,(SZone *)param_1,(ulong)this,pCVar1);
    pSVar2 = extraout_EAX;
  }
  param_2 = (ulong)pSVar2;
  CFastBuffer<class_CDx9TextureKeeper*>::Add(this + 0x18,(TiXmlAttributeSet *)&param_2,unaff_EDI);
  ExceptionList = local_4;
  return pSVar2;
}
}

// =================================================
// Function: CHmsCollisionManager::CHmsCollisionManager
// =================================================
void __thiscall
CHmsCollisionManager::CHmsCollisionManager(CHmsCollisionManager *this,CHmsCollisionManager *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x18,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  *(undefined4 *)(this + 0x14) = 2;
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::DisableStaticCollision
// =================================================
void __thiscall
CHmsCollisionManager::DisableStaticCollision
          (CHmsCollisionManager *this,CHmsCollisionManager *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SGroup *unaff_EBP;
  ulong unaff_ESI;
  uint uVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x18,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      uVar3 = 0;
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x18,pCVar4,unaff_ESI);
        unaff_ESI = 0x539ad9;
        SGroup::ClearAllStatic((void *)(*(int *)pSVar2 + uVar3),unaff_EBP);
        uVar3 = uVar3 + 0x44;
      } while (uVar3 < 0x154);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::GetMwClassId
// =================================================
ulong __thiscall
CHmsCollisionManager::GetMwClassId(CHmsCollisionManager *this,CControlStyle *param_1)
{
{
  return 0x6019000;
}
}

// =================================================
// Function: CHmsCollisionManager::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall
CHmsCollisionManager::MwGetClassInfo(CHmsCollisionManager *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d67534;
}
}

// =================================================
// Function: CHmsCollisionManager::MwIsKilled
// =================================================
void __thiscall
CHmsCollisionManager::MwIsKilled
          (CHmsCollisionManager *this,CVisionViewportDx9 *param_1,CMwNod *param_2)
{
{
  void *pvVar1;
  int iVar2;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  
  iVar2 = (**(code **)(*(int *)param_1 + 0x10))(0x904f000);
  if ((iVar2 != 0) && (pvVar1 = *(void **)(param_1 + 0x50), pvVar1 != (void *)0x0)) {
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              ((void *)((int)pvVar1 + 4),unaff_ESI);
    operator_delete(pvVar1);
    *(undefined4 *)(param_1 + 0x50) = DAT_00d6e63c;
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::MwIsKindOf
// =================================================
int __thiscall
CHmsCollisionManager::MwIsKindOf
          (CHmsCollisionManager *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0x6019000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CHmsCollisionManager::MwNewCHmsCollisionManager
// =================================================
CMwNod * __cdecl CHmsCollisionManager::MwNewCHmsCollisionManager(void)
{
{
  CHmsCollisionManager *pCVar1;
  CMwNod *extraout_EAX;
  CHmsCollisionManager *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9547b;
  local_c = ExceptionList;
  pCVar1 = (CHmsCollisionManager *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x24);
  local_4 = 0;
  if (local_10 != (CHmsCollisionManager *)0x0) {
    CHmsCollisionManager(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CHmsCollisionManager::RemoveZone
// =================================================
void __thiscall
CHmsCollisionManager::RemoveZone
          (CHmsCollisionManager *this,CHmsCollisionManager *param_1,ulong param_2)
{
{
  CHmsCollisionManager *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  
  this_00 = this + 0x18;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar3,unaff_EBP);
      if (*(ulong *)(*(int *)pSVar2 + 0x198) == param_2) break;
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  pCVar4 = pCVar3;
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar3,unaff_EBX);
  pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar2;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (pCVar1 + 0x1a0,unaff_retaddr);
    CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
              (pCVar1 + 0x170,(CFastArray<class_CFuncShader*> *)param_1);
    pCVar4 = pCVar1;
    _eh_vector_destructor_iterator_(pCVar1,0x44,5,SGroup::~SGroup);
    operator_delete(pCVar1);
  }
  CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt
            (this_00,(CFastBufferRef<class_CGameMobil> *)pCVar3,1,(ulong)pCVar4);
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::StaticAddRef
// =================================================
void __cdecl CHmsCollisionManager::StaticAddRef(void)
{
{
  CHmsCollisionManager *pCVar1;
  undefined4 extraout_EAX;
  CHmsCollisionManager *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a954ab;
  local_c = ExceptionList;
  pCVar1 = (CHmsCollisionManager *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  if (DAT_00d6752c == 0) {
    local_10 = operator_new(0x24);
    local_4 = 0;
    if (local_10 == (CHmsCollisionManager *)0x0) {
      DAT_00d67528 = 0;
    }
    else {
      CHmsCollisionManager(local_10,pCVar1);
      DAT_00d67528 = extraout_EAX;
    }
  }
  DAT_00d6752c = DAT_00d6752c + 1;
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::StaticRelease
// =================================================
void __cdecl CHmsCollisionManager::StaticRelease(void)
{
{
  DAT_00d6752c = DAT_00d6752c + -1;
  if (DAT_00d6752c == 0) {
    if (DAT_00d67528 != (int *)0x0) {
      (**(code **)(*DAT_00d67528 + 4))(1);
    }
    DAT_00d67528 = (int *)0x0;
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::UpdateStaticCollisionTrees
// =================================================
void __thiscall
CHmsCollisionManager::UpdateStaticCollisionTrees
          (CHmsCollisionManager *this,CHmsCollisionManager *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CHmsCollisionManager *unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x18,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x18,pCVar3,unaff_ESI);
      unaff_ESI = 0x53b054;
      SZone::UpdateStaticCollisionTrees(*(void **)pSVar2,unaff_EBX);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::VirtualParam_Get
// =================================================
ulong __thiscall
CHmsCollisionManager::VirtualParam_Get
          (CHmsCollisionManager *this,CPlugBlendShapes *param_1,CMwStack *param_2,
          CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x6019000) {
    *(CHmsCollisionManager **)param_2 = this + 0x18;
  }
  else {
    if (iVar2 == 0x6019003) {
      *(undefined **)param_2 = &DAT_00d67530;
      return 0;
    }
    if (iVar2 != -1) {
      *(int *)(param_1 + 0x18) = iVar1;
      uVar3 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,param_3);
      return uVar3;
    }
  }
  return 0;
}
}

// =================================================
// Function: CHmsCollisionManager::VirtualParam_Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CHmsCollisionManager::VirtualParam_Set
          (CHmsCollisionManager *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x6019003) {
    _DAT_00d67530 = *(undefined4 *)param_2;
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CHmsCollisionManager::_vector_deleting_destructor_
// =================================================
void * __thiscall
CHmsCollisionManager::_vector_deleting_destructor_
          (CHmsCollisionManager *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CHmsCollisionManager *unaff_ESI;
  
  ~CHmsCollisionManager(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CHmsCollisionManager::~CHmsCollisionManager
// =================================================
void __thiscall
CHmsCollisionManager::~CHmsCollisionManager
          (CHmsCollisionManager *this,CHmsCollisionManager *param_1)
{
{
  CFastArray<class_CCrystalEdge*> *pCVar1;
  CMwNod *unaff_ESI;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EDI;
  void *unaff_retaddr;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a95793;
  local_c = ExceptionList;
  pCVar1 = (CFastArray<class_CCrystalEdge*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  CFastBuffer<struct_CHmsCollisionManager::SZone*>::DeleteAll(this + 0x18,pCVar1);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x18,unaff_EDI);
  CMwNod::~CMwNod((CMwNod *)this,unaff_ESI);
  ExceptionList = unaff_retaddr;
  return;
}
}

