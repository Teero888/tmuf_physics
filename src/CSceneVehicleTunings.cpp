
/* public: virtual void * __thiscall CSceneVehicleTunings::`vector deleting
   destructor'(unsigned int) */

void *__thiscall CSceneVehicleTunings::`vector_deleting_destructor'(CSceneVehicleTunings *this,uint param_1)

{
  ~CSceneVehicleTunings(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: virtual void __thiscall CSceneVehicleTunings::Chunk(class
   CClassicArchive &,unsigned long) */

void __thiscall CSceneVehicleTunings::Chunk(CSceneVehicleTunings *this,
                                            CClassicArchive *param_1,
                                            ulong param_2)

{
  if (param_2 == 0xa030000) {
    CFastBuffer<>::ArchiveFastBufferNodRef((CFastBuffer<> *)(this + 0x14),
                                           param_1);
    CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x24), 1, 0);
  } else if (param_2 != 0xffffffff) {
    CMwNod::Chunk((CMwNod *)this, param_1, param_2);
    return;
  }
  return;
}

/* public: __thiscall CSceneVehicleTunings::CSceneVehicleTunings(void) */

CSceneVehicleTunings *__thiscall CSceneVehicleTunings::CSceneVehicleTunings(
    CSceneVehicleTunings *this)

{
  CMwNod::CMwNod((CMwNod *)this);
  *(undefined ***)this = vftable;
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x14));
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x20) = 0xa02e000;
  return this;
}

/* public: virtual unsigned long __thiscall
 * CSceneVehicleTunings::GetChunkInfo(unsigned long)const
 */

ulong __thiscall CSceneVehicleTunings::GetChunkInfo(CSceneVehicleTunings *this,
                                                    ulong param_1)

{
  ulong uVar1;

  if (param_1 == 0xa030000) {
    return 3;
  }
  if (param_1 != 0xffffffff) {
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this, param_1);
    return uVar1;
  }
  return 0xffffffff;
}

/* public: virtual unsigned long __thiscall
 * CSceneVehicleTunings::GetMwClassId(void)const  */

ulong __thiscall CSceneVehicleTunings::GetMwClassId(CSceneVehicleTunings *this)

{
  return 0xa030000;
}

/* public: virtual unsigned long __thiscall
   CSceneVehicleTunings::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CSceneVehicleTunings::GetUidChunkFromIndex(
    CSceneVehicleTunings *this, ulong param_1)

{
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0xa030000;
}

/* public: virtual class CMwClassInfo const * __thiscall
   CSceneVehicleTunings::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CSceneVehicleTunings::MwGetClassInfo(
    CSceneVehicleTunings *this)

{
  return &m_MwClassInfo_CSceneVehicleTunings;
}

/* public: virtual int __thiscall CSceneVehicleTunings::MwIsKindOf(unsigned
 * long)const  */

int __thiscall CSceneVehicleTunings::MwIsKindOf(CSceneVehicleTunings *this,
                                                ulong param_1)

{
  if (param_1 == 0xa030000) {
    return 1;
  }
  return (uint)(param_1 == 0x1001000);
}

/* public: static class CMwNod * __cdecl
 * CSceneVehicleTunings::MwNewCSceneVehicleTunings(void) */

CMwNod *__cdecl CSceneVehicleTunings::MwNewCSceneVehicleTunings(void)

{
  CSceneVehicleTunings *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad061b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CSceneVehicleTunings *)operator_new(0x28);
  local_4 = 0;
  if (this != (CSceneVehicleTunings *)0x0) {
    pCVar1 = (CMwNod *)CSceneVehicleTunings(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: virtual unsigned long __thiscall
 *CSceneVehicleTunings::VirtualParam_Add(class CMwStack ,void *) */

ulong __thiscall CSceneVehicleTunings::VirtualParam_Add(
    CSceneVehicleTunings *this, CMwStack *param_1, void *param_2)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  CMwNodRef<> *this_00;

  iVar3 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + iVar3 * 4);
  *(int *)(param_1 + 0x18) = iVar3 + -1;
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == 0xa030001) {
    /* WARNING: Load size is inaccurate */
    if (((iVar3 + -1 < 0) && (param_2 != (void *)0x0)) &&
        (iVar3 = (**(code **)(*param_2 + 0x10))(*(undefined4 *)(this + 0x20)),
         iVar3 != 0)) {
      this_00 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)(this + 0x14));
      CMwNodRef<>::MwSetNod((CMwNodRef<> *)this_00, (CGameCamera *)param_2);
    }
  } else if (iVar1 != -1) {
    *(int *)(param_1 + 0x18) = iVar3;
    uVar2 = CMwNod::VirtualParam_Add((CMwNod *)this, param_1, param_2);
    return uVar2;
  }
  return 0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: virtual unsigned long __thiscall
 *CSceneVehicleTunings::VirtualParam_Get(class CMwStack ,class CMwValueStd *) */

ulong __thiscall CSceneVehicleTunings::VirtualParam_Get(
    CSceneVehicleTunings *this, CMwStack *param_1, CMwValueStd *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  CMwNod **ppCVar5;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa030000) {
    if ((_DAT_00d6d704 & 1) == 0) {
      _DAT_00d6d704 = _DAT_00d6d704 | 1;
      _DAT_00d6d6fc = 0;
      DAT_00d6d700 = "";
      _atexit((_func_4879 *)&LAB_00b22b70);
    }
    uVar3 = *(uint *)(this + 0x24);
    uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x14));
    if (uVar3 < uVar4) {
      ppCVar5 = (CMwNod **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x14), uVar3);
      CSystemArchiveNod::ComputeCrcString(*ppCVar5,
                                          (CFastString *)&DAT_00d6d6fc);
    }
    *(undefined **)param_2 = &DAT_00d6d6fc;
  } else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar4 = CMwNod::VirtualParam_Get((CMwNod *)this, param_1, param_2);
    return uVar4;
  }
  return 0;
}

/* public: virtual unsigned long __thiscall
 *CSceneVehicleTunings::VirtualParam_Set(class CMwStack ,void *) */

ulong __thiscall CSceneVehicleTunings::VirtualParam_Set(
    CSceneVehicleTunings *this, CMwStack *param_1, void *param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  CMwNod **ppCVar4;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa030001) {
    if (-1 < iVar1 + -1) {
      ppCVar4 = (CMwNod **)CMwParamFastBuffer<>::GetElemFromStack(
          (CFastBuffer<> *)(this + 0x14), param_1);
      if (*(int *)(param_1 + 0x18) < 0) {
        *ppCVar4 = (CMwNod *)param_2;
        return 0;
      }
      CMwNod::Param_Set(*ppCVar4, param_1, param_2);
    }
  } else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Set((CMwNod *)this, param_1, param_2);
    return uVar3;
  }
  return 0;
}

/* public: virtual unsigned long __thiscall
 *CSceneVehicleTunings::VirtualParam_Sub(class CMwStack ,void *) */

ulong __thiscall CSceneVehicleTunings::VirtualParam_Sub(
    CSceneVehicleTunings *this, CMwStack *param_1, void *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa030001) {
    if (iVar1 + -1 < 0) {
      /* WARNING: Load size is inaccurate */
      CFastBufferRef<>::RemoveAt((CFastBufferRef<> *)(this + 0x14), *param_2,
                                 1);
      uVar3 = *(uint *)(this + 0x24);
      uVar4 = CFastBuffer<>::GetCount(
          (CFastBuffer<> *)(CFastBufferRef<> *)(this + 0x14));
      if ((uVar4 <= uVar3) && (uVar3 != 0)) {
        *(uint *)(this + 0x24) = uVar3 - 1;
      }
    }
  } else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar4 = CMwNod::VirtualParam_Sub((CMwNod *)this, param_1, param_2);
    return uVar4;
  }
  return 0;
}

/* public: virtual __thiscall CSceneVehicleTunings::~CSceneVehicleTunings(void)
 */

void __thiscall CSceneVehicleTunings::~CSceneVehicleTunings(
    CSceneVehicleTunings *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00ad05e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x14));
  local_4 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this);
  ExceptionList = local_c;
  return;
}
