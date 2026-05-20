// Class implementation: CMwNod

// =================================================
// Function: CMwNod::AddClass
// =================================================
void __thiscall CMwNod::AddClass(CMwNod *this,CMwEngineInfo *param_1,CMwClassInfo *param_2)
{
{
  CMwClassInfo *unaff_retaddr;
  
  CMwEngineManager::AddClass((CMwEngineManager *)&DAT_00d73344,param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CMwNod::CMwNod
// =================================================
void __thiscall CMwNod::CMwNod(CMwNod *this,CMwNod *param_1,CMwNod *param_2)
{
{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}
}

// =================================================
// Function: CMwNod::Chunk
// =================================================
void __thiscall
CMwNod::Chunk(CMwNod *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  SStringParam *pSVar1;
  char *pcVar2;
  ulong unaff_ESI;
  void *unaff_retaddr;
  undefined4 local_1c;
  undefined *local_18;
  char *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae2f90;
  local_c = ExceptionList;
  pSVar1 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_c;
  if (param_2 != (CClassicArchive *)0x1001000) {
    CMwDeprecated::Chunk(this,param_1,param_2,(ulong)pSVar1);
    ExceptionList = unaff_retaddr;
    return;
  }
  local_1c = 0;
  local_18 = PTR_DAT_00bbf7d8;
  if (*(int *)(param_1 + 8) == 0) {
    local_4 = 1;
    CClassicArchive::ReadString
              ((CClassicArchive *)param_1,(CClassicArchive *)&local_1c,(CFastStringInt *)0x1,
               (ulong)pSVar1);
  }
  else {
    local_4 = 0;
    local_14 = "No DevName";
    local_10 = 10;
    CFastString::SetString((CFastString *)&local_1c,(CFastStringInt *)&local_14,pSVar1);
    CClassicArchive::WriteString
              ((CClassicArchive *)param_1,(CClassicArchive *)&local_18,(CFastStringInt *)0x1,
               unaff_ESI);
  }
  if (local_14 != PTR_DAT_00bbf7d8) {
    pcVar2 = local_14 + -1;
    if ((local_14[-1] & 0x80U) != 0) {
      pcVar2 = local_14 + -4;
    }
    operator_delete__(pcVar2);
  }
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: CMwNod::CreateByMwClassId
// =================================================
CMwNod * __cdecl CMwNod::CreateByMwClassId(ulong param_1)
{
{
  CMwClassInfo *pCVar1;
  CMwNod *pCVar2;
  ulong unaff_retaddr;
  
  pCVar1 = CMwEngineManager::GetClassInfo
                     ((CMwEngineManager *)&DAT_00d73344,(CMwEngineManager *)param_1,unaff_retaddr);
  if (pCVar1 != (CMwClassInfo *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00923d46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pCVar2 = (CMwNod *)(**(code **)(pCVar1 + 0x1c))();
    return pCVar2;
  }
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CMwNod::DependantSendMwIsKilled
// =================================================
void __thiscall CMwNod::DependantSendMwIsKilled(CMwNod *this,CMwNod *param_1)
{
{
  void *pvVar1;
  int *piVar2;
  bool bVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CMwNod *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  ulong unaff_EDI;
  
  do {
    bVar3 = false;
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (*(void **)(this + 0xc),(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
    if (uVar4 == 0) break;
    do {
      pvVar1 = *(void **)(this + 0xc);
      unaff_EBX = pCVar7;
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](pvVar1,pCVar7,unaff_EDI);
      if (*(int *)pSVar5 != 0) {
        unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x923fbe;
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pvVar1,pCVar7,(ulong)unaff_ESI);
        piVar2 = *(int **)pSVar5;
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pvVar1,pCVar7,(ulong)unaff_EBP);
        *(undefined4 *)pSVar5 = 0;
        unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x923fd8;
        unaff_EBP = this;
        (**(code **)(*piVar2 + 0x1c))();
        bVar3 = true;
      }
      pCVar7 = pCVar7 + 1;
      unaff_EDI = 0x923fe8;
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(*(void **)(this + 0xc),unaff_ESI);
    } while (pCVar7 < pCVar6);
  } while (bVar3);
  pvVar1 = *(void **)(this + 0xc);
  if (pvVar1 != (void *)0x0) {
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (pvVar1,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_ESI);
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xc) = 0;
  return;
}
}

// =================================================
// Function: CMwNod::GetChunkInfo
// =================================================
ulong __thiscall CMwNod::GetChunkInfo(CMwNod *this,CFuncSegment *param_1,ulong param_2)
{
{
  undefined1 *puVar1;
  void *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_8 = &LAB_00ae2fb8;
  local_c = ExceptionList;
  if (param_1 != (CFuncSegment *)0x1001000) {
    local_4 = (void *)0x0;
    ExceptionList = &local_c;
    CFastString::Format((CFastString *)0x0,(CFastString *)&stack0xffffffec,"Unknown ChunkId: %08X");
    if (local_8 != PTR_DAT_00bbf7d8) {
      puVar1 = local_8 + -1;
      if ((local_8[-1] & 0x80) != 0) {
        puVar1 = local_8 + -4;
      }
      operator_delete__(puVar1);
    }
    ExceptionList = local_4;
    return 0xfacade01;
  }
  return 1;
}
}

// =================================================
// Function: CMwNod::MwAddDependant
// =================================================
void __thiscall CMwNod::MwAddDependant(CMwNod *this,CMwNod *param_1,CMwNod *param_2)
{
{
  void *pvVar1;
  void *extraout_EAX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  ulong unaff_retaddr;
  
  if (*(int *)(this + 0xc) == 0) {
    pvVar1 = operator_new(0xc);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(pvVar1,unaff_ESI);
      pvVar1 = extraout_EAX;
    }
    *(void **)(this + 0xc) = pvVar1;
    CFastBuffer<int>::SetSizeAtLeast
              (pvVar1,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)&DAT_00000004,unaff_retaddr);
  }
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (*(void **)(this + 0xc),(TiXmlAttributeSet *)&stack0x0000000c,(TiXmlAttribute *)param_1)
  ;
  return;
}
}

// =================================================
// Function: CMwNod::MwAddReceiver
// =================================================
void __thiscall CMwNod::MwAddReceiver(CMwNod *this,CMwNod *param_1,CMwNod *param_2)
{
{
  void *pvVar1;
  void *extraout_EAX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  ulong unaff_retaddr;
  
  if (*(int *)(this + 0x10) == 0) {
    pvVar1 = operator_new(0xc);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(pvVar1,unaff_ESI);
      pvVar1 = extraout_EAX;
    }
    *(void **)(this + 0x10) = pvVar1;
    CFastBuffer<int>::SetSizeAtLeast
              (pvVar1,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)&DAT_00000004,unaff_retaddr);
  }
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (*(void **)(this + 0x10),(TiXmlAttributeSet *)&stack0x0000000c,(TiXmlAttribute *)param_1
            );
  return;
}
}

// =================================================
// Function: CMwNod::MwAddRef
// =================================================
ulong __thiscall CMwNod::MwAddRef(CMwNod *this,CMwNod *param_1)
{
{
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return *(ulong *)(this + 4);
}
}

// =================================================
// Function: CMwNod::MwFinalSubDependant
// =================================================
void __thiscall CMwNod::MwFinalSubDependant(CMwNod *this,CMwNod *param_1,CMwNod *param_2)
{
{
  ulong uVar1;
  CPlugBitmap **unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  
  CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
            (*(void **)(this + 0xc),(CFastBuffer<class_CPlugBitmap*> *)&param_1,unaff_ESI);
  if (*(int *)(this + 4) == 0) {
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(*(void **)(this + 0xc),unaff_retaddr);
    if (uVar1 == 0) {
      (**(code **)(*(int *)this + 4))();
    }
  }
  return;
}
}

// =================================================
// Function: CMwNod::MwForceRef
// =================================================
ulong __thiscall CMwNod::MwForceRef(CMwNod *this,CMwNod *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  uVar1 = *(ulong *)(this + 4);
  *(CMwNod **)(this + 4) = param_1;
  return uVar1;
}
}

// =================================================
// Function: CMwNod::MwGetNearestFather
// =================================================
ulong __thiscall
CMwNod::MwGetNearestFather(CMwNod *this,CMwClassInfo *param_1,ulong param_2,ulong *param_3)
{
{
  CMwClassInfo *this_00;
  ulong uVar1;
  
  this_00 = (CMwClassInfo *)(**(code **)(*(int *)this + 8))();
  if (this_00 != (CMwClassInfo *)0x0) {
    uVar1 = CMwClassInfo::MwGetNearestFather(this_00,param_1,param_2,param_3);
    return uVar1;
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CMwNod::MwIsUnreferenced
// =================================================
void __thiscall CMwNod::MwIsUnreferenced(CMwNod *this,CVisionViewportDx9 *param_1,CMwNod *param_2)
{
{
  CMwNod *unaff_retaddr;
  
  MwFinalSubDependant((CMwNod *)param_1,this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CMwNod::MwRelease
// =================================================
ulong __thiscall CMwNod::MwRelease(CMwNod *this,CMwNod *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  void *this_00;
  CMwNod *unaff_EDI;
  ulong uVar5;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  
  uVar5 = *(int *)(this + 4) - 1;
  *(ulong *)(this + 4) = uVar5;
  if (uVar5 != 0) {
    return uVar5;
  }
  this_00 = *(void **)(this + 0xc);
  if ((this_00 != (void *)0x0) &&
     (uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI), uVar5 != 0)) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_EDI);
      pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x924955;
      unaff_EDI = this;
      (**(code **)(**(int **)pSVar2 + 0x20))();
      if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1) {
        return (ulong)param_1;
      }
      this_00 = *(void **)(this + 0xc);
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar6);
      if (pCVar3 == pCVar1) {
        pCVar4 = pCVar4 + 1;
        pCVar3 = pCVar1;
      }
      pCVar1 = pCVar3;
    } while (pCVar4 < pCVar3);
    return (ulong)param_1;
  }
  (**(code **)(*(int *)this + 4))(1);
  return 0;
}
}

// =================================================
// Function: CMwNod::MwSendMessage
// =================================================
void __thiscall CMwNod::MwSendMessage(CMwNod *this,CMwNod *param_1,ulong param_2,ulong *param_3)
{
{
  ulong *puVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  
  if (*(void **)(this + 0x10) != (void *)0x0) {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(*(void **)(this + 0x10),unaff_ESI);
    puVar1 = param_3;
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (*(void **)(this + 0x10),pCVar4,(ulong)unaff_EBP);
        unaff_EBP = puVar1;
        (**(code **)(**(int **)pSVar3 + 0x74))(&param_3,this);
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
  }
  return;
}
}

// =================================================
// Function: CMwNod::MwSubDependant
// =================================================
void __thiscall CMwNod::MwSubDependant(CMwNod *this,CMwNod *param_1,CMwNod *param_2)
{
{
  CPlugBitmap **unaff_retaddr;
  
  CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
            (*(void **)(this + 0xc),(CFastBuffer<class_CPlugBitmap*> *)&param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CMwNod::MwSubDependantSafe
// =================================================
void __thiscall CMwNod::MwSubDependantSafe(CMwNod *this,CMwNod *param_1,CMwNod *param_2)
{
{
  void *this_00;
  CFastBufferRef<class_CGameMobil> *pCVar1;
  GxTexCoordSet *unaff_ESI;
  ulong unaff_retaddr;
  
  this_00 = *(void **)(this + 0xc);
  if (this_00 != (void *)0x0) {
    pCVar1 = (CFastBufferRef<class_CGameMobil> *)
             CFastArray<class_CGameMenuFrame*>::Find
                       (this_00,(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_ESI);
    if (pCVar1 != (CFastBufferRef<class_CGameMobil> *)0xffffffff) {
      CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt(this_00,pCVar1,1,unaff_retaddr);
    }
  }
  return;
}
}

// =================================================
// Function: CMwNod::MwSubReceiver
// =================================================
void __thiscall CMwNod::MwSubReceiver(CMwNod *this,CMwNod *param_1,CMwNod *param_2)
{
{
  void *this_00;
  CMwNod *this_01;
  CFastBufferRef<class_CGameMobil> *pCVar1;
  ulong uVar2;
  ulong unaff_ESI;
  GxTexCoordSet *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  
  this_00 = *(void **)(this + 0x10);
  pCVar1 = (CFastBufferRef<class_CGameMobil> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     (this_00,(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_EDI);
  if (pCVar1 != (CFastBufferRef<class_CGameMobil> *)0xffffffff) {
    CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt(this_00,pCVar1,1,unaff_ESI);
    this_01 = *(CMwNod **)(this + 0x10);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_retaddr);
    if (uVar2 == 0) {
      if (this_01 != (CMwNod *)0x0) {
        CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                  (this_01,(CFastBuffer<class_CPlugFileGPUV*> *)param_1);
        param_1 = this_01;
        operator_delete(this_01);
      }
      *(undefined4 *)(this + 0x10) = 0;
    }
  }
  return;
}
}

// =================================================
// Function: CMwNod::OnCrashDump
// =================================================
int __thiscall CMwNod::OnCrashDump(CMwNod *this,CMwNod *param_1,CFastString *param_2)
{
{
  int iVar1;
  CFastString *this_00;
  CFastString *this_01;
  CMwNod *pCVar2;
  char *pcVar3;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00cca150 ^ 0xcbd798;
  ExceptionList = &local_14;
  local_8 = 0;
  iVar1 = CMwNod_MwCheckThisRelease(this);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)this + 8))();
    if (iVar1 != 0) {
      pcVar3 = *(char **)(iVar1 + 0x14);
      pCVar2 = param_1;
      this_00 = (CFastString *)(**(code **)(*DAT_00d72ec0 + 0x1c))();
      CFastString::operator<<(this_00,(CPlugFileGpuBuilder *)pCVar2,pcVar3);
      CFastString::ConcatFormat(this_01,(CFastStringInt *)param_1,"(0x%08X)");
      ExceptionList = local_14;
      return 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}
}

// =================================================
// Function: CMwNod::Param_Add
// =================================================
ulong __thiscall CMwNod::Param_Add(CMwNod *this,CMwNod *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  if ((*(byte *)(iVar2 + 0x14) & 0x40) != 0) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = (**(code **)(*(int *)this + 0x2c))(param_1,param_2);
    return uVar3;
  }
  uVar3 = (**(code **)(**(int **)(iVar2 + 8) + 0x9c))(this + *(int *)(iVar2 + 0xc),param_1,param_2);
  return uVar3;
}
}

// =================================================
// Function: CMwNod::Param_Check
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall CMwNod::Param_Check(CMwNod *this,CMwNod *param_1,CMwStack *param_2)
{
{
  int iVar1;
  CMwNod *pCVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  CMwNod *pCVar6;
  CMwNod *pCVar7;
  uint uStack_78;
  CMwStack local_68 [68];
  undefined4 local_24;
  int local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pCVar2 = param_1;
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00cca150 ^ 0xcbd698;
  uStack_78 = DAT_00cca150 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&uStack_78;
  local_8 = 0;
  if (*(int *)(param_1 + 0x18) < 0) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
  ExceptionList = &local_14;
  iVar3 = (**(code **)(*(int *)this + 0x10))(*(uint *)(iVar1 + 4) & 0xfffff000);
  if (iVar3 == 0) {
    ExceptionList = local_14;
    return 2;
  }
  pCVar6 = this;
  pCVar7 = pCVar2;
  uVar4 = (**(code **)(**(int **)(iVar1 + 8) + 0xa4))(this,pCVar2,&param_1);
  if (uVar4 == 0) {
    if (param_1 == (CMwNod *)0x0) {
      if ((0 < *(int *)(pCVar2 + 0x18)) &&
         (*(int *)(*(int *)(pCVar2 + 0x14) + -4 + *(int *)(pCVar2 + 0x18) * 4) == 1)) {
        local_24 = 0;
        _DAT_00d73388 = &local_20;
        _DAT_00d7338c = &local_24;
        _DAT_00d73380 = 1;
        _DAT_00d7337c = 1;
        _DAT_00d73390 = 0;
        local_20 = iVar1;
        uVar4 = Param_Get(this,(CMwNod *)&DAT_00d73378,local_68,(CMwValueStd *)pCVar6);
        _DAT_00d73388 = (int *)0x0;
        _DAT_00d7338c = (undefined4 *)0x0;
        if (uVar4 != 0) {
          _DAT_00d73388 = (int *)0x0;
          _DAT_00d7338c = (undefined4 *)0x0;
          ExceptionList = local_14;
          return uVar4;
        }
        iVar3 = CMwParam::IsIndexed(*(CMwParam **)(iVar1 + 8),(CMwParam *)pCVar7);
        if (iVar3 == 0) {
          uVar5 = (**(code **)(**(int **)(iVar1 + 8) + 0x90))(local_68);
        }
        else {
          uVar5 = (**(code **)(**(int **)(iVar1 + 8) + 0x88))(local_68);
        }
        if (uVar5 <= *(uint *)(*(int *)(pCVar2 + 0x10) + -4 + *(int *)(pCVar2 + 0x18) * 4)) {
          ExceptionList = local_14;
          return 2;
        }
      }
      ExceptionList = local_14;
      return 0;
    }
    uVar4 = Param_Check(param_1,pCVar2,(CMwStack *)pCVar6);
  }
  ExceptionList = local_14;
  return uVar4;
}
}

// =================================================
// Function: CMwNod::Param_Get
// =================================================
ulong __thiscall
CMwNod::Param_Get(CMwNod *this,CMwNod *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  ulong uVar2;
  int iVar3;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00cca150 ^ 0xcbd678;
  ExceptionList = &local_14;
  iVar3 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + iVar3 * 4);
  *(int *)(param_1 + 0x18) = iVar3 + -1;
  if ((*(byte *)(iVar1 + 0x14) & 0x10) != 0) {
    *(int *)(param_1 + 0x18) = iVar3;
    local_8 = 0;
    uVar2 = (**(code **)(*(int *)this + 0x24))(param_1,param_2);
    ExceptionList = local_14;
    return uVar2;
  }
  iVar3 = (**(code **)(*(int *)this + 0x10))(*(uint *)(iVar1 + 4) & 0xfffff000);
  if (iVar3 != 0) {
    uVar2 = (**(code **)(**(int **)(iVar1 + 8) + 0x94))
                      (this + *(int *)(iVar1 + 0xc),param_1,param_2);
    ExceptionList = local_14;
    return uVar2;
  }
  ExceptionList = local_14;
  return 1;
}
}

// =================================================
// Function: CMwNod::Param_Set
// =================================================
ulong __thiscall
CMwNod::Param_Set(CMwNod *this,CMwNod *param_1,CFastString *param_2,CFastStringInt *param_3)
{
{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  CMwStack *unaff_EBX;
  CMwStack *unaff_EBP;
  CFastString *unaff_ESI;
  ulong unaff_EDI;
  CMwStack *pCVar6;
  CFastStringInt *pCVar7;
  SHeaderCommunity *pSVar8;
  CMwStack local_a8 [4];
  int iStack_a4;
  int local_a0;
  CMwStack local_9c [4];
  int local_98 [2];
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined *local_84;
  undefined1 auStack_80 [4];
  CFastString aCStack_7c [4];
  CFastString *pCStack_78;
  int *local_74;
  int *piStack_70;
  int *piStack_6c;
  int *local_68;
  byte local_5c;
  CFastString *apCStack_4c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae2ff6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwStack::CMwStack(local_a8,(CMwStack *)(DAT_00cca150 ^ (uint)&stack0xffffff48),unaff_EDI);
  uVar1 = CMwStack::FillIndexFromText
                    ((CMwStack *)&local_a0,(CMwStack *)0xffffffff,(ulong)this,(CMwNod *)param_3,
                     unaff_ESI);
  if (uVar1 != 0) {
LAB_00924d0f:
    CMwStack::~CMwStack((CMwStack *)local_98,unaff_EBX);
    ExceptionList = param_2;
    return uVar1;
  }
  if (local_98[0] == 0) {
    CMwStack::~CMwStack(local_9c,unaff_EBP);
    ExceptionList = (void *)0xffffffff;
    return 5;
  }
  local_84 = (undefined *)(local_98[0] + -1);
  pCVar6 = (CMwStack *)0x924d5e;
  uVar1 = CMwStack::MakeInfoFromStack
                    (local_9c,(CMwStack *)&local_74,(SMwParamInfo *)this,(CMwNod *)unaff_EBP);
  if (uVar1 != 0) goto LAB_00924d0f;
  if ((local_5c & 2) == 0) {
    CMwStack::~CMwStack((CMwStack *)local_98,unaff_EBX);
    ExceptionList = param_2;
    return 2;
  }
  pSVar8 = (SHeaderCommunity *)0x1009000;
  iVar2 = (**(code **)(*local_68 + 0x10))();
  uVar1 = 0x1007000;
  iVar3 = (**(code **)(*piStack_6c + 0x10))();
  pCVar7 = (CFastStringInt *)0x924db5;
  iVar4 = (**(code **)(*piStack_70 + 0xac))();
  if (((iVar4 == 0) && (iVar2 == 0)) && (iVar3 == 0)) {
    uStack_4 = 0xffffffff;
    CMwStack::~CMwStack(local_a8,pCVar6);
    ExceptionList = param_2;
    return 7;
  }
  iStack_90 = iStack_a4 + -1;
  uVar5 = Param_Check(this,(CMwNod *)local_a8,pCVar6);
  if (uVar5 != 0) {
    CMwStack::~CMwStack((CMwStack *)&iStack_a4,(CMwStack *)pCVar7);
    ExceptionList = param_2;
    return uVar5;
  }
  iStack_8c = local_a0 + -1;
  if (iVar2 == 0) {
    if (iVar3 == 0) {
      (**(code **)(*local_74 + 0xb0))(apCStack_4c,param_3,aCStack_7c);
    }
    else {
      if (*(int *)param_3 != 0) {
        uStack_88 = 0;
        local_84 = PTR_DAT_00bbf7d8;
        CFastStringInt::GetAscii(param_3,(CFastStringInt *)&uStack_88,(CFastString *)pCVar7);
        iVar2 = CFastString::GetNatural((CFastString *)&local_84,aCStack_7c,(ulong *)0x1,0,uVar1);
        if (iVar2 == 0) {
          uVar1 = 7;
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(auStack_80,pSVar8);
        }
        else {
          uVar1 = Param_Set(this,(CMwNod *)local_9c,pCStack_78,(CFastStringInt *)pSVar8);
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                    (aCStack_7c,(SHeaderCommunity *)unaff_EBX);
        }
        goto LAB_00924ee1;
      }
      apCStack_4c[0] = (CFastString *)0x0;
    }
  }
  else {
    apCStack_4c[0] = (CFastString *)0x0;
  }
  uVar1 = Param_Set(this,(CMwNod *)&iStack_a4,apCStack_4c[0],pCVar7);
LAB_00924ee1:
  CMwStack::~CMwStack((CMwStack *)local_98,unaff_EBX);
  ExceptionList = param_2;
  return uVar1;
}
}

// =================================================
// Function: CMwNod::Param_Sub
// =================================================
ulong __thiscall CMwNod::Param_Sub(CMwNod *this,CMwNod *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  if ((*(byte *)(iVar2 + 0x14) & 0x80) != 0) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = (**(code **)(*(int *)this + 0x30))(param_1,param_2);
    return uVar3;
  }
  uVar3 = (**(code **)(**(int **)(iVar2 + 8) + 0xa0))(this + *(int *)(iVar2 + 0xc),param_1,param_2);
  return uVar3;
}
}

// =================================================
// Function: CMwNod::StaticGetClassInfo
// =================================================
CMwClassInfo * __cdecl CMwNod::StaticGetClassInfo(ulong param_1)
{
{
  CMwClassInfo *pCVar1;
  ulong unaff_retaddr;
  
  pCVar1 = CMwEngineManager::GetClassInfo
                     ((CMwEngineManager *)&DAT_00d73344,(CMwEngineManager *)param_1,unaff_retaddr);
  return pCVar1;
}
}

// =================================================
// Function: CMwNod::StaticInit
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CMwNod::StaticInit(void)
{
{
  CMwEngineInfo *pCVar1;
  CMwNod *extraout_ECX;
  CMwNod *in_ECX;
  CMwClassInfo *unaff_ESI;
  CMwClassInfo *in_stack_00000004;
  
  _DAT_00d73370 = &PTR_DAT_00bc61c4;
  _DAT_00d73374 = 1;
  for (pCVar1 = (CMwEngineInfo *)DAT_00d73ba8; pCVar1 != (CMwEngineInfo *)0x0;
      pCVar1 = *(CMwEngineInfo **)(pCVar1 + 0x18)) {
    AddClass(in_ECX,pCVar1,unaff_ESI);
    in_ECX = extraout_ECX;
  }
  CMwClassInfo::BuildTree(DAT_00d73ba8,in_stack_00000004);
  return;
}
}

// =================================================
// Function: CMwNod::StaticMwIsKindOf
// =================================================
int __cdecl CMwNod::StaticMwIsKindOf(ulong param_1,ulong param_2)
{
{
  int iVar1;
  CMwClassInfo *pCVar2;
  CMwClassInfo *pCVar3;
  
  if ((param_1 != 0xffffffff) && (param_2 != 0xffffffff)) {
    if (param_1 == param_2) {
      return 1;
    }
    pCVar2 = StaticGetClassInfo(param_1);
    if ((pCVar2 != (CMwClassInfo *)0x0) &&
       (pCVar3 = StaticGetClassInfo(param_2), pCVar3 != (CMwClassInfo *)0x0)) {
      if (*(int *)(pCVar2 + 4) == *(int *)(pCVar3 + 4)) {
        return 1;
      }
      for (iVar1 = *(int *)(pCVar2 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
        if (*(int *)(iVar1 + 4) == *(int *)(pCVar3 + 4)) {
          return 1;
        }
      }
    }
    return 0;
  }
  return 0;
}
}

// =================================================
// Function: CMwNod::VirtualParam_Add
// =================================================
ulong __thiscall
CMwNod::VirtualParam_Add(CMwNod *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3)
{
{
  ulong uVar1;
  
  uVar1 = Internal_VirtualParam_AddOrSub(this,(CMwStack *)param_1,param_2,1);
  return uVar1;
}
}

// =================================================
// Function: CMwNod::VirtualParam_Get
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CMwNod::VirtualParam_Get
          (CMwNod *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  uint uVar2;
  CFastString CVar3;
  SStringParam *pSVar4;
  void *this_00;
  undefined3 extraout_var;
  undefined *puVar5;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  CTrackManiaEditorIconPage aCStack_14 [8];
  undefined *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae3028;
  local_c = ExceptionList;
  pSVar4 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
  uVar2 = _DAT_00d733d8 & 1;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  iVar1 = *(int *)(iVar1 + 4);
  if (uVar2 == 0) {
    _DAT_00d733d8 = _DAT_00d733d8 | 1;
    _DAT_00d733d0 = 0;
    DAT_00d733d4 = PTR_DAT_00bbf7d8;
    _atexit(`public:_virtual_unsigned_long___thiscall_CMwNod::
            VirtualParam_Get(class_CMwStack*,class_CMwValueStd*)'::__l2::
            _dynamic_atexit_destructor_for__StaticString__);
  }
  if (iVar1 == 0x1001000) {
    this_00 = (void *)(**(code **)(*(int *)this + 0x14))();
    if (this_00 != (void *)0x0) {
      CVar3 = CMwId::GetName(this_00,aCStack_14);
      uStack_1c = ((undefined4 *)CONCAT31(extraout_var,CVar3))[1];
      uStack_18 = *(undefined4 *)CONCAT31(extraout_var,CVar3);
      uStack_4 = 0;
      CFastString::SetString((CFastString *)&DAT_00d733d0,(CFastStringInt *)&uStack_1c,pSVar4);
      if (local_c != PTR_DAT_00bbf7d8) {
        puVar5 = local_c + -1;
        if ((local_c[-1] & 0x80) != 0) {
          puVar5 = local_c + -4;
        }
        operator_delete__(puVar5);
      }
      *(undefined **)param_3 = &DAT_00d733d0;
      ExceptionList = puStack_8;
      return 0;
    }
    *(undefined4 **)param_2 = &DAT_00d71c9c;
    ExceptionList = local_c;
    return 0;
  }
  ExceptionList = local_c;
  return 1;
}
}

// =================================================
// Function: CMwNod::VirtualParam_Set
// =================================================
ulong __thiscall
CMwNod::VirtualParam_Set(CMwNod *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  if (*(int *)(iVar1 + 4) == 0x1001000) {
    (**(code **)(*(int *)this + 0x18))(*(undefined4 *)(param_2 + 4));
  }
  return 0;
}
}

// =================================================
// Function: CMwNod::VirtualParam_Sub
// =================================================
ulong __thiscall
CMwNod::VirtualParam_Sub
          (CMwNod *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3)
{
{
  ulong uVar1;
  
  uVar1 = Internal_VirtualParam_AddOrSub(this,(CMwStack *)param_1,param_2,0);
  return uVar1;
}
}

// =================================================
// Function: CMwNod::~CMwNod
// =================================================
void __thiscall CMwNod::~CMwNod(CMwNod *this,CMwNod *param_1)
{
{
  void *this_00;
  CMwNod *unaff_ESI;
  
  *(undefined ***)this = vftable;
  if ((*(int *)(this + 8) != 0) && (DAT_00d7333c != (undefined4 *)0x0)) {
    (**(code **)*DAT_00d7333c)(this);
  }
  if (*(int *)(this + 0xc) != 0) {
    DependantSendMwIsKilled(this,unaff_ESI);
  }
  this_00 = *(void **)(this + 0x10);
  if (this_00 != (void *)0x0) {
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (this_00,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_ESI);
    operator_delete(this_00);
  }
  return;
}
}

