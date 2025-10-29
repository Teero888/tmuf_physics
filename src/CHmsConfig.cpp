
/* public: virtual void * __thiscall CHmsConfig::`vector deleting
 * destructor'(unsigned int) */

void *__thiscall CHmsConfig::`vector_deleting_destructor'(CHmsConfig *this,uint param_1)

{
  ~CHmsConfig(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: virtual void * __thiscall CHmsConfig::`vector deleting
 * destructor'(unsigned int) */

void *__thiscall CHmsConfig::`vector_deleting_destructor'(CHmsConfig *this,uint param_1)

{
  ~CHmsConfig(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: virtual void __thiscall CHmsConfig::Chunk(class CClassicArchive
 * &,unsigned long) */

void __thiscall CHmsConfig::Chunk(CHmsConfig *this, CClassicArchive *param_1,
                                  ulong param_2)

{
  if (param_2 < 0x601d003) {
    if (param_2 == 0x601d002) {
      CClassicArchive::DoBool(param_1, (int *)(this + 0x14), 1);
      CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x18), 1, 0);
      return;
    }
    if (param_2 == 0x601d000) {
      if (*(int *)(param_1 + 8) == 0) {
        CFastArray<>::ReleaseAll((CFastArray<> *)(this + 0x20));
      }
      CFastArray<>::ArchiveCountAndNods((CFastArray<> *)(this + 0x20), param_1);
      if (*(int *)(param_1 + 8) != 0) {
        return;
      }
      CFastBuffer<>::AddRefAll((CFastBuffer<> *)(CFastArray<> *)(this + 0x20));
      return;
    }
    if (param_2 == 0x601d001) {
      CClassicArchive::DoBool(param_1, (int *)(this + 0x14), 1);
      return;
    }
  } else if (param_2 == 0xffffffff) {
    return;
  }
  CMwNod::Chunk((CMwNod *)this, param_1, param_2);
  return;
}

/* public: void __thiscall CHmsConfig::CopyFromConfig(class CHmsConfig const *)
 */

void __thiscall CHmsConfig::CopyFromConfig(CHmsConfig *this,
                                           CHmsConfig *param_1)

{
  CopyFromShadowGroups(this, (CFastArray<> *)(param_1 + 0x20));
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  return;
}

/* public: void __thiscall CHmsConfig::CopyFromShadowGroups(class
 *CFastArray<class CHmsShadowGroup > const &) */

void __thiscall CHmsConfig::CopyFromShadowGroups(CHmsConfig *this,
                                                 CFastArray<> *param_1)

{
  CFastArray<> *this_00;

  this_00 = (CFastArray<> *)(this + 0x20);
  CFastArray<>::ReleaseAll(this_00);
  CFastArray<>::CopyFromFastArray((CFastArray<> *)this_00,
                                  (CFastArray<> *)param_1);
  CFastBuffer<>::AddRefAll((CFastBuffer<> *)this_00);
  return;
}

/* public: virtual void __thiscall CHmsConfig::CreateDefaultData(void) */

void __thiscall CHmsConfig::CreateDefaultData(CHmsConfig *this)

{
  CFastArray<> *this_00;
  CHmsShadowGroup *this_01;
  undefined4 uVar1;
  undefined4 *puVar2;
  CMwNod **ppCVar3;
  CGameControlCardManager **ppCVar4;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9663b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = (CFastArray<> *)(this + 0x20);
  CFastArray<>::SetCount(this_00, 1);
  this_01 = (CHmsShadowGroup *)operator_new(0x9c);
  local_4 = 0;
  if (this_01 == (CHmsShadowGroup *)0x0) {
    uVar1 = 0;
  } else {
    uVar1 = CHmsShadowGroup::CHmsShadowGroup(this_01);
  }
  local_4 = 0xffffffff;
  puVar2 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 0);
  *puVar2 = uVar1;
  ppCVar3 = (CMwNod **)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 0);
  CMwNod::MwAddRef(*ppCVar3);
  ppCVar4 = (CGameControlCardManager **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)this_00, 0);
  CGameControlCardManager::SetGetDataTypeInfosFromNodCallBack(
      *ppCVar4, (CMwNod *)0x80, (_func_void_CMwNod_ptr_CFastString_ptr *)0x80);
  ExceptionList = local_c;
  return;
}

/* public: virtual unsigned long __thiscall CHmsConfig::GetChunkInfo(unsigned
 * long)const  */

ulong __thiscall CHmsConfig::GetChunkInfo(CHmsConfig *this, ulong param_1)

{
  ulong uVar1;

  if (param_1 < 0x601d003) {
    if (param_1 == 0x601d002) {
      return 0x13;
    }
    if (param_1 == 0x601d000) {
      return 3;
    }
    if (param_1 == 0x601d001) {
      return 0x11;
    }
  } else if (param_1 == 0xffffffff) {
    return 0xffffffff;
  }
  uVar1 = CMwNod::GetChunkInfo((CMwNod *)this, param_1);
  return uVar1;
}

/* public: virtual unsigned long __thiscall CHmsConfig::GetMwClassId(void)const
 */

ulong __thiscall CHmsConfig::GetMwClassId(CHmsConfig *this)

{
  return 0x601d000;
}

/* public: virtual unsigned long __thiscall
 * CHmsConfig::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CHmsConfig::GetUidChunkFromIndex(CHmsConfig *this,
                                                  ulong param_1)

{
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0x601d000;
}

/* public: virtual class CMwClassInfo const * __thiscall
 * CHmsConfig::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CHmsConfig::MwGetClassInfo(CHmsConfig *this)

{
  return &m_MwClassInfo_CHmsConfig;
}

/* public: virtual int __thiscall CHmsConfig::MwIsKindOf(unsigned long)const  */

int __thiscall CHmsConfig::MwIsKindOf(CHmsConfig *this, ulong param_1)

{
  if (param_1 == 0x601d000) {
    return 1;
  }
  return (uint)(param_1 == 0x1001000);
}

/* public: static class CMwNod * __cdecl CHmsConfig::MwNewCHmsConfig(void) */

CMwNod *__cdecl CHmsConfig::MwNewCHmsConfig(void)

{
  CHmsConfig *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9669b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CHmsConfig *)operator_new(0x28);
  local_4 = 0;
  if (this != (CHmsConfig *)0x0) {
    pCVar1 = (CMwNod *)CHmsConfig(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: void __thiscall CHmsConfig::ShadowGroupsSetCount(unsigned long) */

void __thiscall CHmsConfig::ShadowGroupsSetCount(CHmsConfig *this,
                                                 ulong param_1)

{
  CFastBuffer<> *this_00;
  uint uVar1;
  CHmsShadowGroup *this_01;
  undefined4 *puVar2;
  CMwNod **ppCVar3;
  undefined4 uVar4;
  uint uVar5;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9666b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = (CFastBuffer<> *)(this + 0x20);
  uVar1 = CFastBuffer<>::GetCount(this_00);
  if (uVar1 < param_1) {
    CFastArray<>::SetCount((CFastArray<> *)this_00, param_1);
    for (; uVar1 < param_1; uVar1 = uVar1 + 1) {
      this_01 = (CHmsShadowGroup *)operator_new(0x9c);
      uVar4 = 0;
      local_4 = 0;
      if (this_01 != (CHmsShadowGroup *)0x0) {
        uVar4 = CHmsShadowGroup::CHmsShadowGroup(this_01);
      }
      local_4 = 0xffffffff;
      puVar2 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00,
                                                       uVar1);
      *puVar2 = uVar4;
      ppCVar3 =
          (CMwNod **)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar1);
      CMwNod::MwAddRef(*ppCVar3);
    }
  } else {
    uVar5 = param_1;
    if (param_1 < uVar1) {
      do {
        ppCVar3 = (CMwNod **)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00,
                                                       uVar5);
        CMwNod::MwRelease(*ppCVar3);
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar1);
      CFastArray<>::SetCount((CFastArray<> *)this_00, param_1);
    }
  }
  ExceptionList = local_c;
  return;
}

/* public: virtual __thiscall CHmsConfig::~CHmsConfig(void) */

void __thiscall CHmsConfig::~CHmsConfig(CHmsConfig *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00a96613;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  CFastArray<>::ReleaseAll((CFastArray<> *)(this + 0x20));
  CFastArray<>::~CFastArray<>((CFastArray<> *)(CFastArray<> *)(this + 0x20));
  local_4 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this);
  ExceptionList = local_c;
  return;
}
