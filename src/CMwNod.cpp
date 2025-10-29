
/* public: static void __cdecl CMwNod::AddClass(class CMwClassInfo *) */

void __cdecl CMwNod::AddClass(CMwClassInfo *param_1)

{
  CMwEngineManager::AddClass(&MwEngines, param_1);
  return;
}

/* public: virtual class CMwNod * __thiscall CMwNod::Archive(class
 * CClassicArchive &) */

CMwNod *__thiscall CMwNod::Archive(CMwNod *this, CClassicArchive *param_1)

{
  CClassicArchive *this_00;
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  CClassicArchive *pCVar6;
  ulong uStack_48;
  ulong uStack_44;
  ulong uStack_40;
  CClassicArchive *pCStack_3c;
  ulong uStack_38;
  ulong uStack_34;
  ulong uStack_30;
  CClassicBufferMemory aCStack_2c[12];
  int iStack_20;
  int iStack_18;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae2f28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = (**(code **)(*(int *)this + 8))(___security_cookie ^
                                          (uint)&stack0xffffffa8);
  this_00 = param_1;
  if (*(int *)(iVar2 + 8) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 4) + 8) = 1;
    uStack_48 =
        CMwDeprecated::UnWrapClassId(*(ulong *)(*(int *)(iVar2 + 8) + 4));
    if (uStack_48 == 0x7031000) {
      uStack_48 = 0x7001000;
    }
    CClassicArchive::WriteNatural(this_00, &uStack_48, 1, 0);
    *(undefined4 *)(*(int *)(this_00 + 4) + 8) = 0;
  }
  if (*(int *)(this_00 + 8) == 0) {
    CClassicArchive::ReadMask(this_00, (ulong *)&param_1, 1);
    while (param_1 != (CClassicArchive *)0xfacade01) {
      uVar5 = (**(code **)(*(int *)this + 0x3c))(param_1);
      if ((uVar5 == 0xfacade01) ||
          (((uVar5 & 1) == 0 && ((uVar5 & 0x10) != 0)))) {
        CClassicArchive::ReadNatural(this_00, &uStack_38, 1, 0);
        if (uStack_38 != 0x534b4950)
          break;
        CClassicArchive::ReadNatural(this_00, (ulong *)&pCStack_3c, 1, 0);
        CClassicArchive::SkipData(this_00, (ulong)pCStack_3c);
      } else {
        if ((uVar5 & 0x10) != 0) {
          CClassicArchive::ReadNatural(this_00, &uStack_34, 1, 0);
          CClassicArchive::ReadNatural(this_00, &uStack_30, 1, 0);
        }
        (**(code **)(*(int *)this + 0x38))(this_00, param_1);
      }
      CClassicArchive::ReadMask(this_00, (ulong *)&param_1, 1);
    }
  } else {
    pCStack_3c = (CClassicArchive *)(**(code **)(*(int *)this + 0x44))();
    param_1 = (CClassicArchive *)0x0;
    if (pCStack_3c != (CClassicArchive *)0x0) {
      do {
        pCVar6 = param_1;
        uVar3 = (**(code **)(*(int *)this + 0x40))(param_1);
        bVar1 = (**(code **)(*(int *)this + 0x3c))(uVar3);
        if (((bVar1 & 2) != 0) &&
            ((bVar1 & (*(int *)(this_00 + 0x10) == 0) * '\x04' + 4U) == 0)) {
          CClassicArchive::WriteMask(this_00, &uStack_48, 1);
          if ((bVar1 & 0x10) == 0) {
            (**(code **)(*(int *)this + 0x38))(this_00, uStack_48);
          } else {
            CClassicBufferMemory::CClassicBufferMemory(aCStack_2c);
            uStack_4 = 0;
            piVar4 = (int *)CClassicArchive::DetachBuffer(this_00, 0);
            CVisionVisualKeeper::SetVisual((CVisionVisualKeeper *)this_00,
                                           (CPlugVisual *)aCStack_2c);
            iVar2 = iStack_18;
            (**(code **)(*(int *)this + 0x38))(this_00, uStack_48);
            uStack_44 = iStack_18 - iVar2;
            CClassicArchive::DetachBuffer(this_00, 0);
            CVisionVisualKeeper::SetVisual((CVisionVisualKeeper *)this_00,
                                           (CPlugVisual *)piVar4);
            uStack_40 = 0x534b4950;
            CClassicArchive::WriteNatural(this_00, &uStack_40, 1, 0);
            CClassicArchive::WriteNatural(this_00, &uStack_44, 1, 0);
            if (uStack_44 != 0) {
              (**(code **)(*piVar4 + 8))(iStack_20 + iVar2, uStack_44);
            }
            uStack_4 = 0xffffffff;
            CClassicBufferMemory::~CClassicBufferMemory(aCStack_2c);
            pCVar6 = param_1;
          }
        }
        param_1 = pCVar6 + 1;
      } while (param_1 < pCStack_3c);
    }
    uStack_38 = 0xfacade01;
    CClassicArchive::WriteMask(this_00, &uStack_38, 1);
  }
  if (*(int *)(this_00 + 8) == 0) {
    (**(code **)(*(int *)this + 0x48))();
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: virtual void __thiscall CMwNod::Chunk(class CClassicArchive
 * &,unsigned long) */

void __thiscall CMwNod::Chunk(CMwNod *this, CClassicArchive *param_1,
                              ulong param_2)

{
  char *pcVar1;
  undefined4 local_1c;
  char *local_18;
  char *local_14;
  undefined4 local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae2f90;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_2 != 0x1001000) {
    CMwDeprecated::Chunk(param_1, param_2);
    ExceptionList = local_c;
    return;
  }
  local_1c = 0;
  local_18 = "";
  if (*(int *)(param_1 + 8) == 0) {
    local_4 = 1;
    CClassicArchive::ReadString(param_1, (CFastString *)&local_1c, 1);
  } else {
    local_4 = 0;
    local_14 = "No DevName";
    local_10 = 10;
    CFastString::SetString((CFastString *)&local_1c, (SStringParam *)&local_14);
    CClassicArchive::WriteString(param_1, (CFastString *)&local_1c, 1);
  }
  if (local_18 != "") {
    pcVar1 = local_18 + -1;
    if ((local_18[-1] & 0x80U) != 0) {
      pcVar1 = local_18 + -4;
    }
    operator_delete[](pcVar1);
  }
  ExceptionList = local_c;
  return;
}

/* public: __thiscall CMwNod::CMwNod(void) */

void __thiscall CMwNod::CMwNod(CMwNod *this)

{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

/* public: __thiscall CMwNod::CMwNod(class CMwNod const &) */

void __thiscall CMwNod::CMwNod(CMwNod *this, CMwNod *param_1)

{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

/* public: static class CMwNod * __cdecl CMwNod::CreateByMwClassId(unsigned
 * long) */

CMwNod *__cdecl CMwNod::CreateByMwClassId(ulong param_1)

{
  CMwClassInfo *pCVar1;
  CMwNod *pCVar2;

  pCVar1 = CMwEngineManager::GetClassInfo(&MwEngines, param_1);
  if (pCVar1 != (CMwClassInfo *)0x0) {
    /* WARNING: Could not recover jumptable at 0x00923d46. Too many branches */
    /* WARNING: Treating indirect jump as call */
    pCVar2 = (CMwNod *)(**(code **)(pCVar1 + 0x1c))();
    return pCVar2;
  }
  return (CMwNod *)0x0;
}

/* public: void __thiscall CMwNod::DependantSendMwIsKilled(void) */

void __thiscall CMwNod::DependantSendMwIsKilled(CMwNod *this)

{
  CFastBuffer<> *this_00;
  CFastBuffer<> *this_01;
  bool bVar1;
  ulong uVar2;
  int *piVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  ulong uVar6;

  do {
    bVar1 = false;
    uVar6 = 0;
    uVar2 = CFastBuffer<>::GetCount(*(CFastBuffer<> **)(this + 0xc));
    if (uVar2 == 0)
      break;
    do {
      this_00 = *(CFastBuffer<> **)(this + 0xc);
      piVar3 = (int *)CFastBuffer<>::operator[](this_00, uVar6);
      if (*piVar3 != 0) {
        ppiVar4 = (int **)CFastBuffer<>::operator[](this_00, uVar6);
        piVar3 = *ppiVar4;
        puVar5 = (undefined4 *)CFastBuffer<>::operator[](this_00, uVar6);
        *puVar5 = 0;
        (**(code **)(*piVar3 + 0x1c))(this);
        bVar1 = true;
      }
      uVar6 = uVar6 + 1;
      uVar2 = CFastBuffer<>::GetCount(*(CFastBuffer<> **)(this + 0xc));
    } while (uVar6 < uVar2);
  } while (bVar1);
  this_01 = *(CFastBuffer<> **)(this + 0xc);
  if (this_01 != (CFastBuffer<> *)0x0) {
    CFastBuffer<>::~CFastBuffer<>(this_01);
    operator_delete(this_01);
  }
  *(undefined4 *)(this + 0xc) = 0;
  return;
}

/* public: virtual unsigned long __thiscall CMwNod::GetChunkInfo(unsigned
 * long)const  */

ulong __thiscall CMwNod::GetChunkInfo(CMwNod *this, ulong param_1)

{
  char *pcVar1;
  undefined4 local_14;
  char *local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00ae2fb8;
  local_c = ExceptionList;
  if (param_1 != 0x1001000) {
    local_14 = 0;
    local_10 = "";
    local_4 = 0;
    ExceptionList = &local_c;
    CFastString::Format((CFastString *)0x0, (char *)&local_14,
                        "Unknown ChunkId: %08X", param_1,
                        ___security_cookie ^ (uint)&local_14);
    if (local_10 != "") {
      pcVar1 = local_10 + -1;
      if ((local_10[-1] & 0x80U) != 0) {
        pcVar1 = local_10 + -4;
      }
      operator_delete[](pcVar1);
    }
    ExceptionList = local_c;
    return 0xfacade01;
  }
  return 1;
}

/* public: virtual unsigned long __thiscall CMwNod::GetMwClassId(void)const  */

ulong __thiscall CMwNod::GetMwClassId(CMwNod *this)

{
  return 0x1001000;
}

/* public: unsigned long __thiscall
 * CMwNod::GetMwParamIdForRecursiveIndex(unsigned long)const  */

ulong __thiscall CMwNod::GetMwParamIdForRecursiveIndex(CMwNod *this,
                                                       ulong param_1)

{
  CMwClassInfo *this_00;
  ulong uVar1;

  this_00 = (CMwClassInfo *)(**(code **)(*(int *)this + 8))();
  uVar1 = CMwClassInfo::GetMwParamIdRecursive_FromIndex(this_00, param_1);
  return uVar1;
}

/* public: unsigned long __thiscall
 * CMwNod::GetMwParamIdRecursiveCount(void)const  */

ulong __thiscall CMwNod::GetMwParamIdRecursiveCount(CMwNod *this)

{
  CMwClassInfo *this_00;
  ulong uVar1;

  this_00 = (CMwClassInfo *)(**(code **)(*(int *)this + 8))();
  uVar1 = CMwClassInfo::GetMwParamIdRecursive_Count(this_00);
  return uVar1;
}

/* public: static struct SMwParamInfo const * __cdecl
 * CMwNod::GetParamInfoFromParamId(unsigned long)
 */

SMwParamInfo *__cdecl CMwNod::GetParamInfoFromParamId(ulong param_1)

{
  CMwClassInfo *pCVar1;

  pCVar1 = CMwEngineManager::GetClassInfo(&MwEngines, param_1 & 0xfffff000);
  if (pCVar1 != (CMwClassInfo *)0x0) {
    return *(SMwParamInfo **)(*(int *)(pCVar1 + 0x20) + (param_1 & 0xfff) * 4);
  }
  return (SMwParamInfo *)0x0;
}

/* public: virtual unsigned long __thiscall
 * CMwNod::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CMwNod::GetUidChunkFromIndex(CMwNod *this, ulong param_1)

{
  return param_1 | 0x1001000;
}

/* public: void __thiscall CMwNod::MwAddDependant(class CMwNod *)const  */

void __thiscall CMwNod::MwAddDependant(CMwNod *this, CMwNod *param_1)

{
  CFastBuffer<> *this_00;
  CFastBuffer<int> *this_01;

  if (*(int *)(this + 0xc) == 0) {
    this_00 = (CFastBuffer<> *)operator_new(0xc);
    if (this_00 == (CFastBuffer<> *)0x0) {
      this_01 = (CFastBuffer<int> *)0x0;
    } else {
      this_01 = (CFastBuffer<int> *)CFastBuffer<>::CFastBuffer<>(this_00);
    }
    *(CFastBuffer<int> **)(this + 0xc) = this_01;
    CFastBuffer<int>::SetSizeAtLeast(this_01, 4);
  }
  CFastBuffer<>::Add(*(CFastBuffer<> **)(this + 0xc),
                     (CDx9TextureKeeper **)&param_1);
  return;
}

/* public: void __thiscall CMwNod::MwAddReceiver(class CMwNod *) */

void __thiscall CMwNod::MwAddReceiver(CMwNod *this, CMwNod *param_1)

{
  CFastBuffer<> *this_00;
  CFastBuffer<int> *this_01;

  if (*(int *)(this + 0x10) == 0) {
    this_00 = (CFastBuffer<> *)operator_new(0xc);
    if (this_00 == (CFastBuffer<> *)0x0) {
      this_01 = (CFastBuffer<int> *)0x0;
    } else {
      this_01 = (CFastBuffer<int> *)CFastBuffer<>::CFastBuffer<>(this_00);
    }
    *(CFastBuffer<int> **)(this + 0x10) = this_01;
    CFastBuffer<int>::SetSizeAtLeast(this_01, 4);
  }
  CFastBuffer<>::Add(*(CFastBuffer<> **)(this + 0x10),
                     (CDx9TextureKeeper **)&param_1);
  return;
}

/* public: unsigned long __thiscall CMwNod::MwAddRef(void) */

ulong __thiscall CMwNod::MwAddRef(CMwNod *this)

{
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return *(ulong *)(this + 4);
}

/* public: unsigned long __thiscall CMwNod::MwAddRef(void) */

ulong __thiscall CMwNod::MwAddRef(CMwNod *this)

{
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return *(ulong *)(this + 4);
}

/* public: void __thiscall CMwNod::MwFinalSubDependant(class CMwNod *)const  */

void __thiscall CMwNod::MwFinalSubDependant(CMwNod *this, CMwNod *param_1)

{
  ulong uVar1;

  CFastBuffer<>::ReplaceByLast(*(CFastBuffer<> **)(this + 0xc),
                               (CPlugBitmap **)&param_1);
  if (*(int *)(this + 4) == 0) {
    uVar1 = CFastBuffer<>::GetCount(*(CFastBuffer<> **)(this + 0xc));
    if (uVar1 == 0) {
      (**(code **)(*(int *)this + 4))(1);
    }
  }
  return;
}

/* public: void __thiscall CMwNod::MwFinalSubDependant(class CMwNod *)const  */

void __thiscall CMwNod::MwFinalSubDependant(CMwNod *this, CMwNod *param_1)

{
  ulong uVar1;

  CFastBuffer<>::ReplaceByLast(*(CFastBuffer<> **)(this + 0xc),
                               (CPlugBitmap **)&param_1);
  if (*(int *)(this + 4) == 0) {
    uVar1 = CFastBuffer<>::GetCount(*(CFastBuffer<> **)(this + 0xc));
    if (uVar1 == 0) {
      (**(code **)(*(int *)this + 4))(1);
    }
  }
  return;
}

/* public: virtual class CMwClassInfo const * __thiscall
 * CMwNod::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CMwNod::MwGetClassInfo(CMwNod *this)

{
  return &m_MwClassInfo_CMwNod;
}

/* public: unsigned long __thiscall CMwNod::MwGetNearestFather(unsigned
 *long,unsigned long const )const  */

ulong __thiscall CMwNod::MwGetNearestFather(CMwNod *this, ulong param_1,
                                            ulong *param_2)

{
  CMwClassInfo *this_00;
  ulong uVar1;

  this_00 = (CMwClassInfo *)(**(code **)(*(int *)this + 8))();
  if (this_00 != (CMwClassInfo *)0x0) {
    uVar1 = CMwClassInfo::MwGetNearestFather(this_00, param_1, param_2);
    return uVar1;
  }
  return 0xffffffff;
}

/* public: virtual int __thiscall CMwNod::MwIsKindOf(unsigned long)const  */

int __thiscall CMwNod::MwIsKindOf(CMwNod *this, ulong param_1)

{
  return (uint)(param_1 == 0x1001000);
}

/* public: virtual void __thiscall CMwNod::MwIsUnreferenced(class CMwNod *) */

void __thiscall CMwNod::MwIsUnreferenced(CMwNod *this, CMwNod *param_1)

{
  MwFinalSubDependant(param_1, this);
  return;
}

/* public: static class CMwNod * __cdecl CMwNod::MwNew(void) */

CMwNod *__cdecl CMwNod::MwNew(void)

{
  CMwNod *pCVar1;

  pCVar1 = (CMwNod *)operator_new(0x14);
  if (pCVar1 != (CMwNod *)0x0) {
    pCVar1 = (CMwNod *)CMwNod(pCVar1);
    return pCVar1;
  }
  return (CMwNod *)0x0;
}

/* public: unsigned long __thiscall CMwNod::MwRelease(void) */

ulong __thiscall CMwNod::MwRelease(CMwNod *this)

{
  int **ppiVar1;
  ulong uVar2;
  uint uVar3;
  CFastBuffer<> *this_00;
  ulong uVar4;

  uVar4 = *(int *)(this + 4) - 1;
  *(ulong *)(this + 4) = uVar4;
  if (uVar4 != 0) {
    return uVar4;
  }
  this_00 = *(CFastBuffer<> **)(this + 0xc);
  if ((this_00 != (CFastBuffer<> *)0x0) &&
      (uVar4 = CFastBuffer<>::GetCount(this_00), uVar4 != 0)) {
    uVar4 = CFastBuffer<>::GetCount(this_00);
    uVar3 = 0;
    do {
      ppiVar1 =
          (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar3);
      (**(code **)(**ppiVar1 + 0x20))(this);
      if (uVar4 == 1) {
        return 0;
      }
      this_00 = *(CFastBuffer<> **)(this + 0xc);
      uVar2 = CFastBuffer<>::GetCount(this_00);
      if (uVar2 == uVar4) {
        uVar3 = uVar3 + 1;
        uVar2 = uVar4;
      }
      uVar4 = uVar2;
    } while (uVar3 < uVar2);
    return 0;
  }
  (**(code **)(*(int *)this + 4))(1);
  return 0;
}

/* public: void __thiscall CMwNod::MwSendMessage(unsigned long,unsigned long *)
 */

void __thiscall CMwNod::MwSendMessage(CMwNod *this, ulong param_1,
                                      ulong *param_2)

{
  ulong *puVar1;
  ulong uVar2;
  int **ppiVar3;
  ulong uVar4;

  if (*(CFastBuffer<> **)(this + 0x10) != (CFastBuffer<> *)0x0) {
    uVar2 = CFastBuffer<>::GetCount(*(CFastBuffer<> **)(this + 0x10));
    puVar1 = param_2;
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        ppiVar3 = (int **)CFastBuffer<>::operator[](
            *(CFastBuffer<> **)(this + 0x10), uVar4);
        (**(code **)(**ppiVar3 + 0x74))(&param_1, this, puVar1);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
  }
  return;
}

/* public: void __thiscall CMwNod::MwSubDependant(class CMwNod *)const  */

void __thiscall CMwNod::MwSubDependant(CMwNod *this, CMwNod *param_1)

{
  CFastBuffer<>::ReplaceByLast(*(CFastBuffer<> **)(this + 0xc),
                               (CPlugBitmap **)&param_1);
  return;
}

/* public: void __thiscall CMwNod::MwSubDependantSafe(class CMwNod *)const  */

void __thiscall CMwNod::MwSubDependantSafe(CMwNod *this, CMwNod *param_1)

{
  CFastArray<> *this_00;
  ulong uVar1;

  this_00 = *(CFastArray<> **)(this + 0xc);
  if (this_00 != (CFastArray<> *)0x0) {
    uVar1 = CFastArray<>::Find(this_00, (CGameMenuFrame **)&param_1);
    if (uVar1 != 0xffffffff) {
      CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)this_00, uVar1, 1);
    }
  }
  return;
}

/* public: void __thiscall CMwNod::MwSubReceiver(class CMwNod *) */

void __thiscall CMwNod::MwSubReceiver(CMwNod *this, CMwNod *param_1)

{
  CFastArray<> *this_00;
  CFastBuffer<> *this_01;
  ulong uVar1;

  this_00 = *(CFastArray<> **)(this + 0x10);
  uVar1 = CFastArray<>::Find(this_00, (CGameMenuFrame **)&param_1);
  if (uVar1 != 0xffffffff) {
    CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)this_00, uVar1, 1);
    this_01 = *(CFastBuffer<> **)(this + 0x10);
    uVar1 = CFastBuffer<>::GetCount(this_01);
    if (uVar1 == 0) {
      if (this_01 != (CFastBuffer<> *)0x0) {
        CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)this_01);
        operator_delete(this_01);
      }
      *(undefined4 *)(this + 0x10) = 0;
    }
  }
  return;
}

/* public: virtual int __thiscall CMwNod::OnCrashDump(class CFastString &) */

int __thiscall CMwNod::OnCrashDump(CMwNod *this, CFastString *param_1)

{
  int iVar1;
  CFastString *this_00;
  CFastString *this_01;
  CFastString *pCVar2;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;

  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = ___security_cookie ^ 0xcbd798;
  ExceptionList = &local_14;
  local_8 = 0;
  iVar1 = CMwNod_MwCheckThisRelease(this);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)this + 8))();
    if (iVar1 != 0) {
      pCVar2 = param_1;
      this_00 = (CFastString *)(**(
          code **)(*(int *)CClassicCrashDump::s_TheCrashDump + 0x1c))(
          param_1, *(undefined4 *)(iVar1 + 0x14));
      CFastString::operator<<(this_00, (char *)pCVar2);
      CFastString::ConcatFormat(this_01, (char *)param_1, "(0x%08X)", this);
      ExceptionList = local_14;
      return 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}

/* public: unsigned long __thiscall CMwNod::Param_Add(class CMwStack *,void *)
 */

ulong __thiscall CMwNod::Param_Add(CMwNod *this, CMwStack *param_1,
                                   void *param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  if ((*(byte *)(iVar2 + 0x14) & 0x40) != 0) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = (**(code **)(*(int *)this + 0x2c))(param_1, param_2);
    return uVar3;
  }
  uVar3 = (**(code **)(**(int **)(iVar2 + 8) + 0x9c))(
      this + *(int *)(iVar2 + 0xc), param_1, param_2);
  return uVar3;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: unsigned long __thiscall CMwNod::Param_Check(class CMwStack *) */

ulong __thiscall CMwNod::Param_Check(CMwNod *this, CMwStack *param_1)

{
  int iVar1;
  CMwStack *pCVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  uint uStack_78;
  CMwValueStd local_68[68];
  undefined4 local_24;
  int local_20;
  uint *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;

  pCVar2 = param_1;
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = ___security_cookie ^ 0xcbd698;
  uStack_78 = ___security_cookie ^ (uint)&stack0xfffffffc;
  local_1c = &uStack_78;
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
  uVar4 = (**(code **)(**(int **)(iVar1 + 8) + 0xa4))(this, pCVar2, &param_1);
  if (uVar4 == 0) {
    if (param_1 == (CMwStack *)0x0) {
      if ((0 < *(int *)(pCVar2 + 0x18)) &&
          (*(int *)(*(int *)(pCVar2 + 0x14) + -4 +
                    *(int *)(pCVar2 + 0x18) * 4) == 1)) {
        local_24 = 0;
        _DAT_00d73388 = &local_20;
        _DAT_00d7338c = &local_24;
        _DAT_00d73380 = 1;
        _DAT_00d7337c = 1;
        _DAT_00d73390 = 0;
        local_20 = iVar1;
        uVar4 = Param_Get(this, (CMwStack *)&DAT_00d73378, local_68);
        _DAT_00d73388 = (int *)0x0;
        _DAT_00d7338c = (undefined4 *)0x0;
        if (uVar4 != 0) {
          _DAT_00d73388 = (int *)0x0;
          _DAT_00d7338c = (undefined4 *)0x0;
          ExceptionList = local_14;
          return uVar4;
        }
        iVar3 = CMwParam::IsIndexed(*(CMwParam **)(iVar1 + 8));
        if (iVar3 == 0) {
          uVar5 = (**(code **)(**(int **)(iVar1 + 8) + 0x90))(local_68);
        } else {
          uVar5 = (**(code **)(**(int **)(iVar1 + 8) + 0x88))(local_68);
        }
        if (uVar5 <= *(uint *)(*(int *)(pCVar2 + 0x10) + -4 +
                               *(int *)(pCVar2 + 0x18) * 4)) {
          ExceptionList = local_14;
          return 2;
        }
      }
      ExceptionList = local_14;
      return 0;
    }
    uVar4 = Param_Check((CMwNod *)param_1, pCVar2);
  }
  ExceptionList = local_14;
  return uVar4;
}

/* public: unsigned long __thiscall CMwNod::Param_Get(class CMwStack *,class
 * CMwValueStd *) */

ulong __thiscall CMwNod::Param_Get(CMwNod *this, CMwStack *param_1,
                                   CMwValueStd *param_2)

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
  local_c = ___security_cookie ^ 0xcbd678;
  ExceptionList = &local_14;
  iVar3 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + iVar3 * 4);
  *(int *)(param_1 + 0x18) = iVar3 + -1;
  if ((*(byte *)(iVar1 + 0x14) & 0x10) != 0) {
    *(int *)(param_1 + 0x18) = iVar3;
    local_8 = 0;
    uVar2 = (**(code **)(*(int *)this + 0x24))(param_1, param_2);
    ExceptionList = local_14;
    return uVar2;
  }
  iVar3 = (**(code **)(*(int *)this + 0x10))(*(uint *)(iVar1 + 4) & 0xfffff000);
  if (iVar3 != 0) {
    uVar2 = (**(code **)(**(int **)(iVar1 + 8) + 0x94))(
        this + *(int *)(iVar1 + 0xc), param_1, param_2);
    ExceptionList = local_14;
    return uVar2;
  }
  ExceptionList = local_14;
  return 1;
}

/* public: unsigned long __thiscall CMwNod::Param_Set(class CMwStack *,void *)
 */

ulong __thiscall CMwNod::Param_Set(CMwNod *this, CMwStack *param_1,
                                   void *param_2)

{
  int iVar1;
  int *piVar2;
  ulong uVar3;

  iVar1 = *(int *)(param_1 + 0x18);
  piVar2 = *(int **)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  if ((*(byte *)(piVar2 + 5) & 0x20) != 0) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = (**(code **)(*(int *)this + 0x28))(param_1, param_2);
    return uVar3;
  }
  if (*piVar2 == 0) {
    (*(code *)piVar2[7])();
    return 0;
  }
  if (*piVar2 == 0x41) {
    (*(code *)piVar2[7])(param_1);
    return 0;
  }
  uVar3 = (**(code **)(*(int *)piVar2[2] + 0x98))(this + piVar2[3], param_1,
                                                  param_2);
  return uVar3;
}

/* public: unsigned long __thiscall CMwNod::Param_Set(class CFastString const
   &,class CFastStringInt const &) */

ulong __thiscall CMwNod::Param_Set(CMwNod *this, CFastString *param_1,
                                   CFastStringInt *param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  CMwStack local_a8[4];
  int local_a4;
  int local_90;
  undefined4 uStack_8c;
  char *pcStack_88;
  void *pvStack_84;
  int *local_80;
  int *piStack_7c;
  int *local_78;
  byte local_6c;
  void *apvStack_50[17];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae2ff6;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffff48;
  ExceptionList = &local_c;
  CMwStack::CMwStack(local_a8);
  local_4 = 0;
  uVar2 = CMwStack::FillIndexFromText(local_a8, 0xffffffff, this, param_1);
  if (uVar2 != 0) {
  LAB_00924d0f:
    local_4 = 0xffffffff;
    CMwStack::~CMwStack(local_a8);
    ExceptionList = local_c;
    return uVar2;
  }
  if (local_a4 == 0) {
    local_4 = 0xffffffff;
    CMwStack::~CMwStack(local_a8);
    ExceptionList = local_c;
    return 5;
  }
  local_90 = local_a4 + -1;
  uVar2 =
      CMwStack::MakeInfoFromStack(local_a8, (SMwParamInfo *)&local_80, this);
  if (uVar2 != 0)
    goto LAB_00924d0f;
  if ((local_6c & 2) == 0) {
    local_4 = 0xffffffff;
    CMwStack::~CMwStack(local_a8);
    ExceptionList = local_c;
    return 2;
  }
  iVar3 = (**(code **)(*local_78 + 0x10))(0x1009000, uVar1);
  iVar4 = (**(code **)(*piStack_7c + 0x10))(0x1007000);
  iVar5 = (**(code **)(*local_80 + 0xac))();
  if (((iVar5 == 0) && (iVar3 == 0)) && (iVar4 == 0)) {
    local_4 = 0xffffffff;
    CMwStack::~CMwStack(local_a8);
    ExceptionList = local_c;
    return 7;
  }
  local_90 = local_a4 + -1;
  uVar2 = Param_Check(this, local_a8);
  if (uVar2 != 0) {
    local_4 = 0xffffffff;
    CMwStack::~CMwStack(local_a8);
    ExceptionList = local_c;
    return uVar2;
  }
  local_90 = local_a4 + -1;
  if (iVar3 == 0) {
    if (iVar4 == 0) {
      (**(code **)(*local_78 + 0xb0))(apvStack_50, param_2, &local_80);
    } else {
      if (*(int *)param_2 != 0) {
        uStack_8c = 0;
        pcStack_88 = "";
        local_4 = CONCAT31(local_4._1_3_, 1);
        CFastStringInt::GetAscii(param_2, (CFastString *)&uStack_8c);
        iVar3 = CFastString::GetNatural((CFastString *)&uStack_8c,
                                        (ulong *)&pvStack_84, 1, 0);
        if (iVar3 == 0) {
          uVar2 = 7;
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(
              (SHeaderCommunity *)&uStack_8c);
        } else {
          uVar2 = Param_Set(this, local_a8, pvStack_84);
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(
              (SHeaderCommunity *)&uStack_8c);
        }
        goto LAB_00924ee1;
      }
      apvStack_50[0] = (void *)0x0;
    }
  } else {
    apvStack_50[0] = (void *)0x0;
  }
  uVar2 = Param_Set(this, local_a8, apvStack_50[0]);
LAB_00924ee1:
  local_4 = 0xffffffff;
  CMwStack::~CMwStack(local_a8);
  ExceptionList = local_c;
  return uVar2;
}

/* public: unsigned long __thiscall CMwNod::Param_Sub(class CMwStack *,void *)
 */

ulong __thiscall CMwNod::Param_Sub(CMwNod *this, CMwStack *param_1,
                                   void *param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  if ((*(byte *)(iVar2 + 0x14) & 0x80) != 0) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = (**(code **)(*(int *)this + 0x30))(param_1, param_2);
    return uVar3;
  }
  uVar3 = (**(code **)(**(int **)(iVar2 + 8) + 0xa0))(
      this + *(int *)(iVar2 + 0xc), param_1, param_2);
  return uVar3;
}

/* public: virtual void __thiscall CMwNod::SetIdName(char const *) */

void __thiscall CMwNod::SetIdName(CMwNod *this, char *param_1)

{
  undefined4 *this_00;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;

  this_00 = (undefined4 *)(**(code **)(*(int *)this + 0x14))();
  if (this_00 != (undefined4 *)0x0) {
    if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
      bVar4 = true;
      iVar1 = 0xb;
      pcVar2 = param_1;
      pcVar3 = "Unassigned";
      do {
        if (iVar1 == 0)
          break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (!bVar4) {
        CMwId::SetLocalName((CMwId *)this_00, param_1);
        return;
      }
    }
    *this_00 = 0xffffffff;
  }
  return;
}

/* public: static class CMwClassInfo const * __cdecl
 * CMwNod::StaticGetClassInfo(unsigned long) */

CMwClassInfo *__cdecl CMwNod::StaticGetClassInfo(ulong param_1)

{
  CMwClassInfo *pCVar1;

  pCVar1 = CMwEngineManager::GetClassInfo(&MwEngines, param_1);
  return pCVar1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: static void __cdecl CMwNod::StaticInit(void) */

void __cdecl CMwNod::StaticInit(void)

{
  CMwClassInfo *pCVar1;

  _DAT_00d73370 = &m_ParamInfos;
  _DAT_00d73374 = 1;
  pCVar1 = CMwEngineManager::First;
  if (CMwEngineManager::First != (CMwClassInfo *)0x0) {
    do {
      AddClass(pCVar1);
      pCVar1 = *(CMwClassInfo **)(pCVar1 + 0x18);
    } while (pCVar1 != (CMwClassInfo *)0x0);
  }
  CMwClassInfo::BuildTree(CMwEngineManager::First);
  return;
}

/* public: static int __cdecl CMwNod::StaticMwIsKindOf(unsigned long,unsigned
 * long) */

int __cdecl CMwNod::StaticMwIsKindOf(ulong param_1, ulong param_2)

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
      for (iVar1 = *(int *)(pCVar2 + 8); iVar1 != 0;
           iVar1 = *(int *)(iVar1 + 8)) {
        if (*(int *)(iVar1 + 4) == *(int *)(pCVar3 + 4)) {
          return 1;
        }
      }
    }
    return 0;
  }
  return 0;
}

/* public: virtual unsigned long __thiscall CMwNod::VirtualParam_Add(class
 * CMwStack *,void *) */

ulong __thiscall CMwNod::VirtualParam_Add(CMwNod *this, CMwStack *param_1,
                                          void *param_2)

{
  ulong uVar1;

  uVar1 = Internal_VirtualParam_AddOrSub(this, param_1, param_2, 1);
  return uVar1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: virtual unsigned long __thiscall CMwNod::VirtualParam_Get(class
   CMwStack *,class CMwValueStd *) */

ulong __thiscall CMwNod::VirtualParam_Get(CMwNod *this, CMwStack *param_1,
                                          CMwValueStd *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  CMwId *this_00;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  char *pcStack_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae3028;
  local_c = ExceptionList;
  uVar3 = ___security_cookie ^ (uint)&stack0xffffffdc;
  ExceptionList = &local_c;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
  uVar2 = _DAT_00d733d8 & 1;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  iVar1 = *(int *)(iVar1 + 4);
  if (uVar2 == 0) {
    _DAT_00d733d8 = _DAT_00d733d8 | 1;
    _DAT_00d733d0 = 0;
    DAT_00d733d4 = "";
    _atexit((_func_4879 *)&LAB_00b26d00);
  }
  if (iVar1 == 0x1001000) {
    this_00 = (CMwId *)(**(code **)(*(int *)this + 0x14))(uVar3);
    if (this_00 != (CMwId *)0x0) {
      puVar4 = CMwId::GetName(this_00, &uStack_14);
      uStack_1c = puVar4[1];
      uStack_18 = *puVar4;
      uStack_4 = 0;
      CFastString::SetString((CFastString *)&DAT_00d733d0,
                             (SStringParam *)&uStack_1c);
      if (pcStack_10 != "") {
        pcVar5 = pcStack_10 + -1;
        if ((pcStack_10[-1] & 0x80U) != 0) {
          pcVar5 = pcStack_10 + -4;
        }
        operator_delete[](pcVar5);
      }
      *(undefined **)param_2 = &DAT_00d733d0;
      ExceptionList = local_c;
      return 0;
    }
    *(CFastString **)param_2 = &CFastString::s_Null;
    ExceptionList = local_c;
    return 0;
  }
  ExceptionList = local_c;
  return 1;
}

/* public: virtual unsigned long __thiscall CMwNod::VirtualParam_Set(class
 * CMwStack *,void *) */

ulong __thiscall CMwNod::VirtualParam_Set(CMwNod *this, CMwStack *param_1,
                                          void *param_2)

{
  int iVar1;

  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  if (*(int *)(iVar1 + 4) == 0x1001000) {
    (**(code **)(*(int *)this + 0x18))(*(undefined4 *)((int)param_2 + 4));
  }
  return 0;
}

/* public: virtual unsigned long __thiscall CMwNod::VirtualParam_Sub(class
 * CMwStack *,void *) */

ulong __thiscall CMwNod::VirtualParam_Sub(CMwNod *this, CMwStack *param_1,
                                          void *param_2)

{
  ulong uVar1;

  uVar1 = Internal_VirtualParam_AddOrSub(this, param_1, param_2, 0);
  return uVar1;
}

/* public: virtual __thiscall CMwNod::~CMwNod(void) */

void __thiscall CMwNod::~CMwNod(CMwNod *this)

{
  CFastBuffer<> *this_00;

  *(undefined ***)this = vftable;
  if ((*(int *)(this + 8) != 0) &&
      (s_CallbackSystemOnDelete != (CFastCallback1P<> *)0x0)) {
    (***(code ***)s_CallbackSystemOnDelete)(this);
  }
  if (*(int *)(this + 0xc) != 0) {
    DependantSendMwIsKilled(this);
  }
  this_00 = *(CFastBuffer<> **)(this + 0x10);
  if (this_00 != (CFastBuffer<> *)0x0) {
    CFastBuffer<>::~CFastBuffer<>(this_00);
    operator_delete(this_00);
  }
  return;
}
