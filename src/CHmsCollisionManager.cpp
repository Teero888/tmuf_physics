
/* private: virtual void * __thiscall CHmsCollisionManager::`vector deleting
   destructor'(unsigned int) */

void *__thiscall CHmsCollisionManager::`vector_deleting_destructor'(CHmsCollisionManager *this,uint param_1)

{
  ~CHmsCollisionManager(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: struct CHmsCollisionManager::SZone * __thiscall
   CHmsCollisionManager::AddZone(unsigned long) */

SZone *__thiscall CHmsCollisionManager::AddZone(CHmsCollisionManager *this,
                                                ulong param_1)

{
  SZone *this_00;
  SZone *pSVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9575b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = (SZone *)operator_new(0x1ac);
  pSVar1 = (SZone *)0x0;
  local_4 = 0;
  if (this_00 != (SZone *)0x0) {
    pSVar1 = (SZone *)SZone::SZone(this_00, param_1, this);
  }
  local_4 = 0xffffffff;
  param_1 = (ulong)pSVar1;
  CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x18),
                     (CDx9TextureKeeper **)&param_1);
  ExceptionList = local_c;
  return pSVar1;
}

/* private: __thiscall CHmsCollisionManager::CHmsCollisionManager(void) */

CHmsCollisionManager *__thiscall CHmsCollisionManager::CHmsCollisionManager(
    CHmsCollisionManager *this)

{
  CMwNod::CMwNod((CMwNod *)this);
  *(undefined ***)this = vftable;
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x18));
  *(undefined4 *)(this + 0x14) = 2;
  return this;
}

/* public: void __thiscall CHmsCollisionManager::DisableStaticCollision(void) */

void __thiscall CHmsCollisionManager::DisableStaticCollision(
    CHmsCollisionManager *this)

{
  ulong uVar1;
  int *piVar2;
  uint uVar3;
  ulong uVar4;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x18));
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      uVar3 = 0;
      do {
        piVar2 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x18), uVar4);
        SGroup::ClearAllStatic((SGroup *)(*piVar2 + uVar3));
        uVar3 = uVar3 + 0x44;
      } while (uVar3 < 0x154);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return;
}

/* public: virtual unsigned long __thiscall
 * CHmsCollisionManager::GetMwClassId(void)const  */

ulong __thiscall CHmsCollisionManager::GetMwClassId(CHmsCollisionManager *this)

{
  return 0x6019000;
}

/* public: virtual class CMwClassInfo const * __thiscall
   CHmsCollisionManager::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CHmsCollisionManager::MwGetClassInfo(
    CHmsCollisionManager *this)

{
  return &m_MwClassInfo_CHmsCollisionManager;
}

/* public: virtual class CMwClassInfo const * __thiscall
   CHmsCollisionManager::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CHmsCollisionManager::MwGetClassInfo(
    CHmsCollisionManager *this)

{
  return &m_MwClassInfo_CHmsCollisionManager;
}

/* public: virtual int __thiscall CHmsCollisionManager::MwIsKindOf(unsigned
 * long)const  */

int __thiscall CHmsCollisionManager::MwIsKindOf(CHmsCollisionManager *this,
                                                ulong param_1)

{
  if (param_1 == 0x6019000) {
    return 1;
  }
  return (uint)(param_1 == 0x1001000);
}

/* public: static class CMwNod * __cdecl
 * CHmsCollisionManager::MwNewCHmsCollisionManager(void) */

CMwNod *__cdecl CHmsCollisionManager::MwNewCHmsCollisionManager(void)

{
  CHmsCollisionManager *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9547b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CHmsCollisionManager *)operator_new(0x24);
  local_4 = 0;
  if (this != (CHmsCollisionManager *)0x0) {
    pCVar1 = (CMwNod *)CHmsCollisionManager(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: void __thiscall CHmsCollisionManager::RemoveZone(unsigned long) */

void __thiscall CHmsCollisionManager::RemoveZone(CHmsCollisionManager *this,
                                                 ulong param_1)

{
  CFastBuffer<> *this_00;
  void *pvVar1;
  ulong uVar2;
  int *piVar3;
  void **ppvVar4;
  ulong uVar5;

  this_00 = (CFastBuffer<> *)(this + 0x18);
  uVar2 = CFastBuffer<>::GetCount(this_00);
  uVar5 = 0;
  if (uVar2 != 0) {
    do {
      piVar3 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar5);
      if (*(ulong *)(*piVar3 + 0x198) == param_1)
        break;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar2);
  }
  ppvVar4 = (void **)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar5);
  pvVar1 = *ppvVar4;
  if (pvVar1 != (void *)0x0) {
    CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)((int)pvVar1 + 0x1a0));
    CFastArray<>::~CFastArray<>((CFastArray<> *)((int)pvVar1 + 0x170));
    `eh_vector_destructor_iterator'(pvVar1,0x44,5,SGroup::~SGroup); operator_delete(
        pvVar1);
  }
  CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)this_00, uVar5, 1);
  return;
}

/* public: static void __cdecl CHmsCollisionManager::StaticAddRef(void) */

void __cdecl CHmsCollisionManager::StaticAddRef(void)

{
  CHmsCollisionManager *this;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a954ab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (s_StaticCreationsCount == 0) {
    this = (CHmsCollisionManager *)operator_new(0x24);
    local_4 = 0;
    if (this == (CHmsCollisionManager *)0x0) {
      s_Manager = (CHmsCollisionManager *)0x0;
    } else {
      s_Manager = (CHmsCollisionManager *)CHmsCollisionManager(this);
    }
  }
  s_StaticCreationsCount = s_StaticCreationsCount + 1;
  ExceptionList = local_c;
  return;
}

/* public: static void __cdecl CHmsCollisionManager::StaticRelease(void) */

void __cdecl CHmsCollisionManager::StaticRelease(void)

{
  s_StaticCreationsCount = s_StaticCreationsCount - 1;
  if (s_StaticCreationsCount == 0) {
    if (s_Manager != (CHmsCollisionManager *)0x0) {
      (**(code **)(*(int *)s_Manager + 4))(1);
    }
    s_Manager = (CHmsCollisionManager *)0x0;
  }
  return;
}

/* public: void __thiscall
 * CHmsCollisionManager::UpdateStaticCollisionTrees(void) */

void __thiscall CHmsCollisionManager::UpdateStaticCollisionTrees(
    CHmsCollisionManager *this)

{
  ulong uVar1;
  SZone **ppSVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x18));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      ppSVar2 = (SZone **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x18), uVar3);
      SZone::UpdateStaticCollisionTrees(*ppSVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: virtual unsigned long __thiscall
 *CHmsCollisionManager::VirtualParam_Get(class CMwStack ,class CMwValueStd *) */

ulong __thiscall CHmsCollisionManager::VirtualParam_Get(
    CHmsCollisionManager *this, CMwStack *param_1, CMwValueStd *param_2)

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
  } else {
    if (iVar2 == 0x6019003) {
      *(float **)param_2 =
          &SHmsSphereBufferContact::s_SphereContactMergeThreshold;
      return 0;
    }
    if (iVar2 != -1) {
      *(int *)(param_1 + 0x18) = iVar1;
      uVar3 = CMwNod::VirtualParam_Get((CMwNod *)this, param_1, param_2);
      return uVar3;
    }
  }
  return 0;
}

/* public: virtual unsigned long __thiscall
 *CHmsCollisionManager::VirtualParam_Set(class CMwStack ,void *) */

ulong __thiscall CHmsCollisionManager::VirtualParam_Set(
    CHmsCollisionManager *this, CMwStack *param_1, void *param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x6019003) {
    /* WARNING: Load size is inaccurate */
    SHmsSphereBufferContact::s_SphereContactMergeThreshold = *param_2;
  } else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Set((CMwNod *)this, param_1, param_2);
    return uVar3;
  }
  return 0;
}

/* private: virtual __thiscall CHmsCollisionManager::~CHmsCollisionManager(void)
 */

void __thiscall CHmsCollisionManager::~CHmsCollisionManager(
    CHmsCollisionManager *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00a95793;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  CFastBuffer<>::DeleteAll((CFastBuffer<> *)(this + 0x18));
  CFastBuffer<>::~CFastBuffer<>(
      (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x18));
  local_4 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this);
  ExceptionList = local_c;
  return;
}

// ****************************
// CHmsCollisionManager::SGroup
// ****************************

/* public: void __thiscall CHmsCollisionManager::SGroup::AddCorpus(class
 * CHmsCorpus *) */

void __thiscall CHmsCollisionManager::SGroup::AddCorpus(SGroup *this,
                                                        CHmsCorpus *param_1)

{
  CFastBuffer<>::Add((CFastBuffer<> *)this, (CDx9TextureKeeper **)&param_1);
  AddNonStaticCorpus(this, param_1);
  return;
}

/* private: void __thiscall
 * CHmsCollisionManager::SGroup::AddNonStaticCorpus(class CHmsCorpus *) */

void __thiscall CHmsCollisionManager::SGroup::AddNonStaticCorpus(
    SGroup *this, CHmsCorpus *param_1)

{
  ulong uVar1;
  int *piVar2;
  SGroup **ppSVar3;
  ulong uVar4;
  SGroup *local_4;

  local_4 = this;
  CFastBuffer<>::Add((CFastBuffer<> *)(this + 0xc),
                     (CDx9TextureKeeper **)&param_1);
  local_4 = (SGroup *)0x0;
  CFastBuffer<float>::Add((CFastBuffer<float> *)(this + 0x18),
                          (float *)&local_4);
  uVar1 =
      CFastBuffer<>::GetCount((CFastBuffer<> *)(CFastBuffer<> *)(this + 0xc));
  *(ulong *)(param_1 + 0x54) = uVar1 - 1;
  local_4 = (SGroup *)CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x24));
  param_1 = (CHmsCorpus *)0x0;
  if (local_4 != (SGroup *)0x0) {
    do {
      piVar2 = (int *)CFastArray<>::operator[]((CFastArray<> *)(this + 0x24),
                                               (ulong)param_1);
      CFastRectTable<int>::AddLine((CFastRectTable<int> *)(piVar2 + 2));
      uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(*piVar2 + 0x24));
      uVar4 = 0;
      if (uVar1 != 0) {
        do {
          ppSVar3 = (SGroup **)CFastArray<>::operator[](
              (CFastArray<> *)(*piVar2 + 0x24), uVar4);
          if (*ppSVar3 == this) {
            CFastRectTable<int>::AddColumn(
                (CFastRectTable<int> *)(ppSVar3 + 2));
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
      }
      param_1 = param_1 + 1;
    } while (param_1 < local_4);
  }
  return;
}

/* public: void __thiscall
   CHmsCollisionManager::SGroup::AddStaticSurfacesFromTree(class CHmsCorpus
   *,class CPlugTree *,class GmIso4 const &,class CFastBuffer<struct
   CHmsCollisionManager::SColOctreeCell> &) */

void __thiscall CHmsCollisionManager::SGroup::AddStaticSurfacesFromTree(
    SGroup *this, CHmsCorpus *param_1, CPlugTree *param_2, GmIso4 *param_3,
    CFastBuffer<> *param_4)

{
  uint uVar1;
  CPlugTree *pCVar2;
  int iVar3;
  wchar_t *pwVar4;
  SColOctreeCell *pSVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  CFastBuffer<> *pCVar10;
  SGroup *local_44;
  wchar_t *pwStack_40;
  undefined4 local_3c[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a955a8;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffffac;
  ExceptionList = &local_c;
  if ((char)*(uint *)(param_2 + 0x9c) < '\0') {
    local_44 = this;
    if ((*(uint *)(param_2 + 0x9c) & 4) == 0) {
      puVar8 = local_3c;
      for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = *(undefined4 *)param_3;
        param_3 = (GmIso4 *)((int)param_3 + 4);
        puVar8 = puVar8 + 1;
      }
    } else {
      GmIso4::SetMult((GmIso4 *)local_3c, (GmIso4 *)(param_2 + 0x5c), param_3);
    }
    uVar1 = (**(code **)(*(int *)param_2 + 0x7c))(uVar1);
    uVar7 = 0;
    if (uVar1 != 0) {
      do {
        puVar8 = local_3c;
        pCVar10 = param_4;
        pCVar2 = (CPlugTree *)(**(code **)(*(int *)param_2 + 0x80))(uVar7);
        AddStaticSurfacesFromTree(local_44, param_1, pCVar2, (GmIso4 *)puVar8,
                                  pCVar10);
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar1);
    }
    iVar6 = *(int *)(param_2 + 0x8c);
    if (iVar6 != 0) {
      if (0.0 <= *(float *)(*(int *)(iVar6 + 0x14) + 0x28)) {
        pSVar5 = CFastBuffer<>::AddNewElem(param_4);
        GmBoxAligned::SetMult((GmBoxAligned *)(pSVar5 + 4),
                              (GmBoxAligned *)(*(int *)(iVar6 + 0x14) + 0x1c),
                              (GmIso4 *)local_3c);
        *(int *)(pSVar5 + 0x4c) = iVar6;
        puVar8 = local_3c;
        puVar9 = (undefined4 *)(pSVar5 + 0x1c);
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        *(CHmsCorpus **)(pSVar5 + 0x54) = param_1;
        *(CPlugTree **)(pSVar5 + 0x50) = param_2;
      } else {
        CClassicLog::s_IsOutputToFileEnable =
            CClassicLog::s_IsOutputToFileEnable + 1;
        local_44 = (SGroup *)0x0;
        pwStack_40 = L"";
        uStack_4 = 0;
        iVar6 = *(int *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x68);
        iVar3 = *(int *)(*(int *)(param_1 + 0x48) + 0x14);
        if (iVar6 != 0) {
          iVar3 = iVar6;
        }
        if (*(CSystemFidFile **)(iVar3 + 8) != (CSystemFidFile *)0x0) {
          CSystemFidFile::GetFullName(*(CSystemFidFile **)(iVar3 + 8),
                                      (CFastStringInt *)&local_44, 0, 0);
        }
        CClassicLog::s_IsOutputToFileEnable =
            CClassicLog::s_IsOutputToFileEnable - 1;
        if (pwStack_40 != L"") {
          pwVar4 = pwStack_40 + -2;
          if ((*(byte *)((int)pwStack_40 + -1) & 0x80) == 0) {
            pwVar4 = pwStack_40 + -1;
          }
          operator_delete[](pwVar4);
        }
      }
    }
  }
  ExceptionList = local_c;
  return;
}

/* public: void __thiscall CHmsCollisionManager::SGroup::ClearAllStatic(void) */

void __thiscall CHmsCollisionManager::SGroup::ClearAllStatic(SGroup *this)

{
  ulong uVar1;
  CHmsCorpus **ppCVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      ppCVar2 = (CHmsCorpus **)CFastBuffer<>::operator[]((CFastBuffer<> *)this,
                                                         uVar3);
      if (*(int *)(*ppCVar2 + 0x54) == -1) {
        AddNonStaticCorpus(this, *ppCVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  CFastBuffer<>::Reset((CFastBuffer<> *)(this + 0x30));
  return;
}

/* public: void __thiscall
 * CHmsCollisionManager::SGroup::ComputeIsToPerformCollisions(void) */

void __thiscall CHmsCollisionManager::SGroup::ComputeIsToPerformCollisions(
    SGroup *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  ulong uVar5;
  int *piVar6;
  int *piVar7;
  float *pfVar8;
  float *pfVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  uint local_10;

  if (*(int *)(this + 0x40) == 0) {
    uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x24));
    local_10 = 0;
    if (uVar5 != 0) {
      do {
        piVar6 = (int *)CFastArray<>::operator[]((CFastArray<> *)(this + 0x24),
                                                 local_10);
        uVar1 = piVar6[3];
        if (*(int *)(*piVar6 + 0x40) == 0) {
          uVar2 = piVar6[4];
          uVar10 = 0;
          if (uVar1 != 0) {
            do {
              uVar11 = 0;
              if (uVar2 != 0) {
                do {
                  pfVar8 = (float *)CFastBuffer<>::operator[](
                      (CFastBuffer<> *)(this + 0x18), uVar10);
                  iVar12 = *piVar6;
                  pfVar9 = (float *)CFastBuffer<>::operator[](
                      (CFastBuffer<> *)(iVar12 + 0x18), uVar11);
                  fVar4 = *pfVar8 - *pfVar9;
                  if (1e-05 < fVar4) {
                  LAB_0053803c:
                    iVar12 = 1;
                  } else {
                    if (fVar4 < 1e-05 != (fVar4 == 1e-05)) {
                      uVar3 = *(uint *)(iVar12 + 0x3c);
                      if (((*(uint *)(this + 0x3c) == uVar3) &&
                           (uVar11 != uVar10)) ||
                          (*(uint *)(this + 0x3c) < uVar3))
                        goto LAB_0053803c;
                    }
                    iVar12 = 0;
                  }
                  piVar7 = CFastRectTable<int>::Get(
                      (CFastRectTable<int> *)(piVar6 + 2), uVar10, uVar11);
                  uVar11 = uVar11 + 1;
                  *piVar7 = iVar12;
                } while (uVar11 < uVar2);
              }
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar1);
          }
        } else {
          uVar2 = piVar6[4];
          uVar10 = 0;
          if (uVar1 != 0) {
            do {
              uVar11 = 0;
              if (uVar2 != 0) {
                do {
                  piVar7 = CFastRectTable<int>::Get(
                      (CFastRectTable<int> *)(piVar6 + 2), uVar10, uVar11);
                  uVar11 = uVar11 + 1;
                  *piVar7 = 1;
                } while (uVar11 < uVar2);
              }
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar1);
          }
        }
        local_10 = local_10 + 1;
      } while (local_10 < uVar5);
    }
  }
  return;
}

/* public: void __thiscall
 * CHmsCollisionManager::SGroup::ComputeNonStaticCorpusInfos(void) */

void __thiscall CHmsCollisionManager::SGroup::ComputeNonStaticCorpusInfos(
    SGroup *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;
  int *piVar5;
  float *pfVar6;
  ulong uVar7;
  float local_14;
  float local_10;
  float local_c;

  if (*(int *)(this + 0x40) == 0) {
    uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x18));
    uVar7 = 0;
    if (uVar4 != 0) {
      do {
        piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0xc),
                                                  uVar7);
        if (*(CHmsDyna **)(*piVar5 + 0x58) == (CHmsDyna *)0x0) {
          local_c = 0.0;
          local_10 = 0.0;
          local_14 = 0.0;
        } else {
          CHmsDyna::GetLinearSpeed(*(CHmsDyna **)(*piVar5 + 0x58),
                                   (GmVec3 *)&local_14);
        }
        fVar3 = local_c;
        fVar2 = local_10;
        fVar1 = local_14;
        pfVar6 = (float *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x18), uVar7);
        uVar7 = uVar7 + 1;
        *pfVar6 = fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2;
      } while (uVar7 < uVar4);
    }
  }
  return;
}

/* public: void __thiscall CHmsCollisionManager::SGroup::RemoveCorpus(class
 * CHmsCorpus *) */

void __thiscall CHmsCollisionManager::SGroup::RemoveCorpus(SGroup *this,
                                                           CHmsCorpus *param_1)

{
  CFastBuffer<>::Remove((CFastBuffer<> *)this, (CGameCtnBlock **)&param_1);
  if (*(int *)(param_1 + 0x54) != -1) {
    RemoveNonStaticCorpus(this, param_1);
    return;
  }
  ClearAllStatic(this);
  return;
}

/* private: void __thiscall
 * CHmsCollisionManager::SGroup::RemoveNonStaticCorpus(class CHmsCorpus *)
 */

void __thiscall CHmsCollisionManager::SGroup::RemoveNonStaticCorpus(
    SGroup *this, CHmsCorpus *param_1)

{
  CFastBuffer<> *this_00;
  ulong uVar1;
  ulong uVar2;
  int *piVar3;
  CHmsCorpus *pCVar4;
  SGroup **ppSVar5;
  ulong uVar6;

  uVar1 = *(ulong *)(param_1 + 0x54);
  this_00 = (CFastBuffer<> *)(this + 0xc);
  uVar2 = CFastBuffer<>::GetCount(this_00);
  piVar3 =
      (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar2 - 1);
  *(ulong *)(*piVar3 + 0x54) = uVar1;
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)this_00, uVar1, 1);
  CFastBuffer<float>::ReplaceByLastAt((CFastBuffer<float> *)(this + 0x18),
                                      uVar1, 1);
  pCVar4 =
      (CHmsCorpus *)CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x24));
  param_1 = (CHmsCorpus *)0x0;
  if (pCVar4 != (CHmsCorpus *)0x0) {
    do {
      piVar3 = (int *)CFastArray<>::operator[]((CFastArray<> *)(this + 0x24),
                                               (ulong)param_1);
      CFastRectTable<int>::ReplaceLineByLastAt(
          (CFastRectTable<int> *)(piVar3 + 2), uVar1);
      uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)(*piVar3 + 0x24));
      uVar6 = 0;
      if (uVar2 != 0) {
        do {
          ppSVar5 = (SGroup **)CFastArray<>::operator[](
              (CFastArray<> *)(*piVar3 + 0x24), uVar6);
          if (*ppSVar5 == this) {
            CFastRectTable<int>::ReplaceColumnByLastAt(
                (CFastRectTable<int> *)(ppSVar5 + 2), uVar1);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar2);
      }
      param_1 = param_1 + 1;
    } while (param_1 < pCVar4);
  }
  return;
}

/* public: __thiscall
 * CHmsCollisionManager::SGroup::SAgainstGroup::SAgainstGroup(void) */

SAgainstGroup
    *__thiscall CHmsCollisionManager::SGroup::SAgainstGroup::SAgainstGroup(
        SAgainstGroup *this)

{
  CFastRectTable<int>::CFastRectTable<int>((CFastRectTable<int> *)(this + 8));
  return this;
}

/* public: __thiscall
 * CHmsCollisionManager::SGroup::SAgainstGroup::~SAgainstGroup(void) */

void __thiscall CHmsCollisionManager::SGroup::SAgainstGroup::~SAgainstGroup(
    SAgainstGroup *this)

{
  VertexCache::~VertexCache((VertexCache *)(this + 8));
  return;
}

/* public: __thiscall CHmsCollisionManager::SGroup::SGroup(void) */

SGroup *__thiscall CHmsCollisionManager::SGroup::SGroup(SGroup *this)

{
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)this);
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0xc));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x18));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x24));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x30));
  return this;
}

/* public: void __thiscall
 * CHmsCollisionManager::SGroup::UpdateStaticCollisionTrees(int) */

void __thiscall CHmsCollisionManager::SGroup::UpdateStaticCollisionTrees(
    SGroup *this, int param_1)

{
  int *piVar1;
  ulong uVar2;
  int **ppiVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  ulong uVar7;
  ulong uVar8;
  float fVar9;
  uint local_50;
  CFastBuffer<> local_48[4];
  SColOctreeCell *local_44;
  undefined4 auStack_3c[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a956d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  ClearAllStatic(this);
  CFastBuffer<>::CFastBuffer<>(local_48);
  local_4 = 0;
  uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
  local_50 = 0;
  if (uVar2 != 0) {
    do {
      ppiVar3 =
          (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)this, local_50);
      piVar1 = *ppiVar3;
      if ((*(uint *)(piVar1[0x12] + 0x18) & 0x80000) != 0) {
        RemoveNonStaticCorpus(this, (CHmsCorpus *)piVar1);
        puVar4 = (undefined4 *)(**(code **)(*piVar1 + 0x78))();
        puVar6 = auStack_3c;
        for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar6 = puVar6 + 1;
        }
        AddStaticSurfacesFromTree(
            this, (CHmsCorpus *)piVar1,
            *(CPlugTree **)(*(int *)(piVar1[0x12] + 0x14) + 100),
            (GmIso4 *)auStack_3c, (CFastBuffer<> *)local_48);
      }
      local_50 = local_50 + 1;
    } while (local_50 < uVar2);
  }
  fVar9 = 0.0;
  uVar8 = 0;
  uVar7 = 0;
  iVar5 = 1;
  uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_48);
  GmOctree<>::Build((GmOctree<> *)(this + 0x30), uVar2, local_44, iVar5, uVar7,
                    uVar8, fVar9);
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_48);
  ExceptionList = local_c;
  return;
}

/* public: __thiscall CHmsCollisionManager::SGroup::~SGroup(void) */

void __thiscall CHmsCollisionManager::SGroup::~SGroup(SGroup *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00a956ae;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 2;
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x30));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x24));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x18));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0xc));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)this);
  ExceptionList = local_c;
  return;
}

// ****************************
// CHmsCollisionManager::SZone
// ****************************

/* public: void __thiscall CHmsCollisionManager::SZone::AddCorpus(class
 * CHmsCorpus *) */

void __thiscall CHmsCollisionManager::SZone::AddCorpus(SZone *this,
                                                       CHmsCorpus *param_1)

{
  uint uVar1;

  uVar1 = *(uint *)(*(int *)(param_1 + 0x48) + 0x18) >> 0xd & 0xf;
  if (uVar1 != 0) {
    SGroup::AddCorpus((SGroup *)(this + uVar1 * 0x44 + -0x44), param_1);
    return;
  }
  return;
}

/* private: int __thiscall CHmsCollisionManager::SZone::ComputeCollision(struct
   CHmsCollisionManager::SZone::SPlugTreeLocatedPair const &) */

int __thiscall CHmsCollisionManager::SZone::ComputeCollision(
    SZone *this, SPlugTreeLocatedPair *param_1)

{
  int *this_00;
  GmIso4 *pGVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  bool bVar11;
  int local_d8;
  int *local_d0;
  int *local_cc;
  int *local_c8;
  int *piStack_c4;
  int *piStack_c0;
  int *piStack_bc;
  int *piStack_b8;
  int *local_b4;
  int *local_b0;
  undefined4 uStack_ac;
  int *piStack_a8;
  undefined4 uStack_a4;
  int *piStack_a0;
  int local_9c[12];
  int local_6c[12];
  GmBoxAligned local_3c[24];
  GmBoxAligned local_24[24];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9566e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = *(int **)param_1;
  piVar8 = *(int **)(param_1 + 8);
  if ((((byte) * (CMwNod *)(this_00 + 0x27) & 0x80) != 0) &&
      ((*(byte *)(piVar8 + 0x27) & 0x80) != 0)) {
    local_cc = piVar8;
    GmBoxAligned::SetMult(local_3c, (GmBoxAligned *)(this_00 + 0xd),
                          *(GmIso4 **)(param_1 + 4));
    GmBoxAligned::SetMult(local_24, (GmBoxAligned *)(piVar8 + 0xd),
                          *(GmIso4 **)(param_1 + 0xc));
    iVar2 = GmBoxAligned::TestInter(local_3c, local_24);
    if (iVar2 != 0) {
      local_d8 = 0;
      iVar2 = 0xc;
      if (((byte) * (CMwNod *)(this_00 + 0x27) & 4) == 0) {
        piVar8 = *(int **)(param_1 + 4);
        piVar6 = local_6c;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar6 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar6 = piVar6 + 1;
        }
      } else {
        piVar8 = this_00 + 0x17;
        piVar6 = local_6c;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar6 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar6 = piVar6 + 1;
        }
        GmIso4::Mult((GmIso4 *)local_6c, *(GmIso4 **)(param_1 + 4));
      }
      iVar2 = 0xc;
      if ((*(byte *)(local_cc + 0x27) & 4) == 0) {
        piVar8 = *(int **)(param_1 + 0xc);
        piVar6 = local_9c;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar6 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar6 = piVar6 + 1;
        }
      } else {
        pGVar1 = *(GmIso4 **)(param_1 + 0xc);
        piVar8 = local_cc + 0x17;
        piVar6 = local_9c;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar6 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar6 = piVar6 + 1;
        }
        GmIso4::Mult((GmIso4 *)local_9c, pGVar1);
      }
      piVar8 = (int *)this_00[0x23];
      local_b0 = (int *)local_cc[0x23];
      local_c8 = piVar8;
      if ((piVar8 != (int *)0x0) && (local_b0 != (int *)0x0)) {
        local_d0 = (int *)0x0;
        if ((*(char *)(*(int *)(piVar8[5] + 0x34) + 6) == '\0') ||
            (*(char *)(*(int *)(piVar8[5] + 0x34) + 6) == '\x01')) {
          if (this_00[0x14] == 0) {
            local_b4 = (int *)operator_new(0x14);
            local_4 = 0;
            if (local_b4 == (int *)0x0) {
              iVar2 = 0;
            } else {
              iVar2 = SHmsSphereBufferContact::SHmsSphereBufferContact(
                  (SHmsSphereBufferContact *)local_b4);
            }
            this_00[0x14] = iVar2;
            local_4 = 0xffffffff;
            CMwNod::MwAddDependant((CMwNod *)this_00,
                                   *(CMwNod **)(this + 0x19c));
          }
          piVar6 = (int *)this_00[0x14];
          local_d0 = piVar6;
        } else {
          piVar6 = *(int **)(this + 400);
        }
        uVar3 = (**(code **)(*piVar6 + 8))();
        piStack_c0 = local_6c;
        piStack_b8 = local_9c;
        piStack_bc = local_b0;
        piStack_c4 = piVar8;
        local_d8 = CPlugSurface::ComputeCollision(
            (SPlugSurfaceLocatedPair *)&piStack_c4,
            (CGmCollisionBuffer *)piVar6);
        if (local_d8 != 0) {
          if ((local_d0 != (int *)0x0) && (local_d0[4] == 0)) {
            local_d0[4] = 1;
            CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x1a0),
                               (CDx9TextureKeeper **)&local_d0);
          }
          uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(piVar6 + 1));
          piVar8 = local_c8;
          for (; local_c8 = piVar8, uVar3 < uVar4; uVar3 = uVar3 + 1) {
            puVar5 = (undefined4 *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(piVar6 + 1), uVar3);
            puVar5[1] = this_00;
            puVar5[3] = local_cc;
            *puVar5 = *(undefined4 *)(this + 0x188);
            puVar5[2] = *(undefined4 *)(this + 0x18c);
            puVar5[0x12] = *(undefined4 *)(this + 0x184);
            piVar8 = local_c8;
          }
        }
      }
      uVar3 = (**(code **)(*local_cc + 0x7c))();
      local_c8 = (int *)uVar3;
      if ((piVar8 != (int *)0x0) && (uVar9 = 0, uVar3 != 0)) {
        piStack_c0 = local_6c;
        piStack_b8 = local_9c;
        piStack_c4 = this_00;
        do {
          piStack_bc = (int *)(**(code **)(*local_cc + 0x80))(uVar9);
          iVar2 = ComputeCollisionTree1RootOnly(
              this, (SPlugTreeLocatedPair *)&piStack_c4, local_3c);
          if ((iVar2 != 0) || (bVar11 = local_d8 != 0, local_d8 = 0, bVar11)) {
            local_d8 = 1;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar3);
      }
      piVar6 = (int *)(**(code **)(*this_00 + 0x7c))();
      piVar8 = local_cc;
      local_b4 = piVar6;
      if ((local_b0 != (int *)0x0) &&
          (piVar10 = (int *)0x0, piVar6 != (int *)0x0)) {
        piStack_c0 = local_6c;
        piStack_b8 = local_9c;
        piStack_bc = local_cc;
        do {
          piStack_c4 = (int *)(**(code **)(*this_00 + 0x80))(piVar10);
          iVar2 = ComputeCollisionTree2RootOnly(
              this, (SPlugTreeLocatedPair *)&piStack_c4, local_24);
          if ((iVar2 != 0) || (bVar11 = local_d8 != 0, local_d8 = 0, bVar11)) {
            local_d8 = 1;
          }
          piVar10 = (int *)((int)piVar10 + 1);
        } while (piVar10 < piVar6);
      }
      local_d0 = (int *)0x0;
      if (piVar6 == (int *)0x0) {
        ExceptionList = local_c;
        return local_d8;
      }
      do {
        uVar3 = 0;
        if (local_c8 != (int *)0x0) {
          do {
            uVar7 = (**(code **)(*piVar8 + 0x80))(uVar3);
            uStack_ac = (**(code **)(*this_00 + 0x80))(this);
            piStack_a0 = local_9c;
            piStack_a8 = local_6c;
            uStack_a4 = uVar7;
            iVar2 = ComputeCollision(this, (SPlugTreeLocatedPair *)&uStack_ac);
            if ((iVar2 != 0) ||
                (bVar11 = local_d8 != 0, local_d8 = 0, bVar11)) {
              local_d8 = 1;
            }
            uVar3 = uVar3 + 1;
            piVar6 = local_b4;
          } while (uVar3 < local_c8);
        }
        local_d0 = (int *)((int)local_d0 + 1);
      } while (local_d0 < piVar6);
      ExceptionList = local_c;
      return local_d8;
    }
  }
  ExceptionList = local_c;
  return 0;
}

/* private: int __thiscall
   CHmsCollisionManager::SZone::ComputeCollisionTree1RootOnly(struct
   CHmsCollisionManager::SZone::SPlugTreeLocatedPair const &,class GmBoxAligned
   const &) */

int __thiscall CHmsCollisionManager::SZone::ComputeCollisionTree1RootOnly(
    SZone *this, SPlugTreeLocatedPair *param_1, GmBoxAligned *param_2)

{
  int *piVar1;
  CMwNod *this_00;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  SHmsSphereBufferContact *pSVar7;
  int *piVar8;
  uint uVar9;
  bool bVar10;
  int local_8c;
  int *local_84;
  int local_80;
  SHmsSphereBufferContact *local_7c;
  SHmsSphereBufferContact *local_78;
  int iStack_74;
  undefined4 uStack_70;
  SHmsSphereBufferContact *pSStack_6c;
  int *piStack_68;
  CMwNod *pCStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int *piStack_58;
  GmBoxAligned local_54[24];
  int local_3c[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9560b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = *(int **)(param_1 + 8);
  this_00 = *(CMwNod **)param_1;
  if ((*(byte *)(piVar1 + 0x27) & 0x80) != 0) {
    GmBoxAligned::SetMult(local_54, (GmBoxAligned *)(piVar1 + 0xd),
                          *(GmIso4 **)(param_1 + 0xc));
    iVar2 = GmBoxAligned::TestInter(local_54, param_2);
    if (iVar2 != 0) {
      iVar2 = 0xc;
      if ((*(byte *)(piVar1 + 0x27) & 4) == 0) {
        piVar6 = *(int **)(param_1 + 0xc);
        piVar8 = local_3c;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar8 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar8 = piVar8 + 1;
        }
      } else {
        piVar6 = piVar1 + 0x17;
        piVar8 = local_3c;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar8 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar8 = piVar8 + 1;
        }
        GmIso4::Mult((GmIso4 *)local_3c, *(GmIso4 **)(param_1 + 0xc));
      }
      local_7c = (SHmsSphereBufferContact *)piVar1[0x23];
      local_80 = *(int *)(this_00 + 0x8c);
      local_8c = 0;
      if (local_7c != (SHmsSphereBufferContact *)0x0) {
        iVar2 = *(int *)(*(int *)(local_80 + 0x14) + 0x34);
        local_84 = (int *)0x0;
        if ((*(char *)(iVar2 + 6) == '\0') ||
            (*(char *)(iVar2 + 6) == '\x01')) {
          if (*(int *)(this_00 + 0x50) == 0) {
            local_78 = (SHmsSphereBufferContact *)operator_new(0x14);
            local_4 = 0;
            if (local_78 == (SHmsSphereBufferContact *)0x0) {
              uVar3 = 0;
            } else {
              uVar3 =
                  SHmsSphereBufferContact::SHmsSphereBufferContact(local_78);
            }
            *(undefined4 *)(this_00 + 0x50) = uVar3;
            local_4 = 0xffffffff;
            CMwNod::MwAddDependant(this_00, *(CMwNod **)(this + 0x19c));
          }
          piVar6 = *(int **)(this_00 + 0x50);
          local_84 = piVar6;
        } else {
          piVar6 = *(int **)(this + 400);
        }
        piVar8 = local_84;
        local_78 = (SHmsSphereBufferContact *)(**(code **)(*piVar6 + 8))();
        uStack_70 = *(undefined4 *)(param_1 + 4);
        iStack_74 = local_80;
        piStack_68 = local_3c;
        pSStack_6c = local_7c;
        iVar2 = CPlugSurface::ComputeCollision(
            (SPlugSurfaceLocatedPair *)&iStack_74,
            (CGmCollisionBuffer *)piVar6);
        if (iVar2 == 0) {
          local_8c = 0;
        } else {
          local_8c = 1;
          if ((piVar8 != (int *)0x0) && (piVar8[4] == 0)) {
            piVar8[4] = 1;
            CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x1a0),
                               (CDx9TextureKeeper **)&local_84);
          }
          local_7c = (SHmsSphereBufferContact *)(**(code **)(*piVar6 + 8))();
          if (local_78 < local_7c) {
            pSVar7 = local_78;
            do {
              puVar4 = (undefined4 *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(piVar6 + 1), (ulong)pSVar7);
              puVar4[1] = this_00;
              puVar4[3] = piVar1;
              *puVar4 = *(undefined4 *)(this + 0x188);
              puVar4[2] = *(undefined4 *)(this + 0x18c);
              pSVar7 = pSVar7 + 1;
              puVar4[0x12] = *(undefined4 *)(this + 0x184);
            } while (pSVar7 < local_7c);
          }
        }
      }
      uVar5 = (**(code **)(*piVar1 + 0x7c))();
      uVar9 = 0;
      if (uVar5 == 0) {
        ExceptionList = local_c;
        return local_8c;
      }
      do {
        uStack_5c = (**(code **)(*piVar1 + 0x80))(uVar9);
        uStack_60 = *(undefined4 *)(param_1 + 4);
        piStack_58 = local_3c;
        pCStack_64 = this_00;
        iVar2 = ComputeCollisionTree1RootOnly(
            this, (SPlugTreeLocatedPair *)&pCStack_64, param_2);
        if ((iVar2 != 0) || (bVar10 = local_8c != 0, local_8c = 0, bVar10)) {
          local_8c = 1;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar5);
      ExceptionList = local_c;
      return local_8c;
    }
  }
  ExceptionList = local_c;
  return 0;
}

/* private: int __thiscall
   CHmsCollisionManager::SZone::ComputeCollisionTree2RootOnly(struct
   CHmsCollisionManager::SZone::SPlugTreeLocatedPair const &,class GmBoxAligned
   const &) */

int __thiscall CHmsCollisionManager::SZone::ComputeCollisionTree2RootOnly(
    SZone *this, SPlugTreeLocatedPair *param_1, GmBoxAligned *param_2)

{
  int *this_00;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  SHmsSphereBufferContact *pSVar6;
  int *piVar7;
  uint uVar8;
  bool bVar9;
  int local_8c;
  int *local_84;
  int local_80;
  SHmsSphereBufferContact *local_7c;
  SHmsSphereBufferContact *local_78;
  int iStack_74;
  int *piStack_70;
  SHmsSphereBufferContact *pSStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int *piStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  GmBoxAligned local_54[24];
  int local_3c[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9563b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = *(int **)param_1;
  iVar1 = *(int *)(param_1 + 8);
  if (((byte) * (CMwNod *)(this_00 + 0x27) & 0x80) != 0) {
    GmBoxAligned::SetMult(local_54, (GmBoxAligned *)(this_00 + 0xd),
                          *(GmIso4 **)(param_1 + 4));
    iVar3 = GmBoxAligned::TestInter(local_54, param_2);
    if (iVar3 != 0) {
      iVar3 = 0xc;
      if (((byte) * (CMwNod *)(this_00 + 0x27) & 4) == 0) {
        piVar5 = *(int **)(param_1 + 4);
        piVar7 = local_3c;
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar7 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar7 = piVar7 + 1;
        }
      } else {
        piVar5 = this_00 + 0x17;
        piVar7 = local_3c;
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar7 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar7 = piVar7 + 1;
        }
        GmIso4::Mult((GmIso4 *)local_3c, *(GmIso4 **)(param_1 + 4));
      }
      local_80 = this_00[0x23];
      local_7c = *(SHmsSphereBufferContact **)(iVar1 + 0x8c);
      local_8c = 0;
      if (local_80 != 0) {
        iVar3 = *(int *)(*(int *)(local_80 + 0x14) + 0x34);
        local_84 = (int *)0x0;
        if ((*(char *)(iVar3 + 6) == '\0') ||
            (*(char *)(iVar3 + 6) == '\x01')) {
          if (this_00[0x14] == 0) {
            local_78 = (SHmsSphereBufferContact *)operator_new(0x14);
            local_4 = 0;
            if (local_78 == (SHmsSphereBufferContact *)0x0) {
              iVar3 = 0;
            } else {
              iVar3 =
                  SHmsSphereBufferContact::SHmsSphereBufferContact(local_78);
            }
            this_00[0x14] = iVar3;
            local_4 = 0xffffffff;
            CMwNod::MwAddDependant((CMwNod *)this_00,
                                   *(CMwNod **)(this + 0x19c));
          }
          piVar5 = (int *)this_00[0x14];
          local_84 = piVar5;
        } else {
          piVar5 = *(int **)(this + 400);
        }
        piVar7 = local_84;
        local_78 = (SHmsSphereBufferContact *)(**(code **)(*piVar5 + 8))();
        iStack_74 = local_80;
        piStack_70 = local_3c;
        pSStack_6c = local_7c;
        uStack_68 = *(undefined4 *)(param_1 + 0xc);
        iVar3 = CPlugSurface::ComputeCollision(
            (SPlugSurfaceLocatedPair *)&iStack_74,
            (CGmCollisionBuffer *)piVar5);
        if (iVar3 == 0) {
          local_8c = 0;
        } else {
          local_8c = 1;
          if ((piVar7 != (int *)0x0) && (piVar7[4] == 0)) {
            piVar7[4] = 1;
            CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x1a0),
                               (CDx9TextureKeeper **)&local_84);
          }
          local_7c = (SHmsSphereBufferContact *)CFastBuffer<>::GetCount(
              (CFastBuffer<> *)(piVar5 + 1));
          pSVar6 = local_78;
          if (local_78 < local_7c) {
            do {
              puVar4 = (undefined4 *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(piVar5 + 1), (ulong)pSVar6);
              puVar4[1] = this_00;
              puVar4[3] = iVar1;
              *puVar4 = *(undefined4 *)(this + 0x188);
              puVar4[2] = *(undefined4 *)(this + 0x18c);
              pSVar6 = pSVar6 + 1;
              puVar4[0x12] = *(undefined4 *)(this + 0x184);
            } while (pSVar6 < local_7c);
          }
        }
      }
      local_78 = (SHmsSphereBufferContact *)(**(code **)(*this_00 + 0x7c))();
      uVar8 = 0;
      if (local_78 == (SHmsSphereBufferContact *)0x0) {
        ExceptionList = local_c;
        return local_8c;
      }
      do {
        uVar2 = *(undefined4 *)(param_1 + 0xc);
        uStack_64 = (**(code **)(*this_00 + 0x80))(uVar8);
        piStack_60 = local_3c;
        iStack_5c = iVar1;
        uStack_58 = uVar2;
        iVar3 = ComputeCollisionTree2RootOnly(
            this, (SPlugTreeLocatedPair *)&uStack_64, param_2);
        if ((iVar3 != 0) || (bVar9 = local_8c != 0, local_8c = 0, bVar9)) {
          local_8c = 1;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < local_78);
      ExceptionList = local_c;
      return local_8c;
    }
  }
  ExceptionList = local_c;
  return 0;
}

/* private: void __thiscall
 *CHmsCollisionManager::SZone::DetectCollisionBetween(class CHmsCorpus ,class
 *CHmsCorpus *) */

void __thiscall CHmsCollisionManager::SZone::DetectCollisionBetween(
    SZone *this, CHmsCorpus *param_1, CHmsCorpus *param_2)

{
  undefined4 local_10;
  CHmsCorpus *local_c;
  undefined4 local_8;
  CHmsCorpus *local_4;

  *(CHmsCorpus **)(this + 0x188) = param_1;
  *(CHmsCorpus **)(this + 0x18c) = param_2;
  if (*(int *)(param_2 + 0x58) == 0) {
    local_4 = param_2 + 0x18;
  } else {
    local_4 = (CHmsCorpus *)(*(int *)(*(int *)(param_2 + 0x58) + 0x32c) + 0x10);
  }
  local_8 = *(undefined4 *)(*(int *)(*(int *)(param_2 + 0x48) + 0x14) + 100);
  if (*(int *)(param_1 + 0x58) == 0) {
    local_c = param_1 + 0x18;
  } else {
    local_c = (CHmsCorpus *)(*(int *)(*(int *)(param_1 + 0x58) + 0x32c) + 0x10);
  }
  local_10 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 100);
  ComputeCollision(this, (SPlugTreeLocatedPair *)&local_10);
  return;
}

/* private: void __thiscall
   CHmsCollisionManager::SZone::DetectCollisionBetweenTreeAndStaticCollisionTree(class
   GmIso4 const
   &,class CPlugTree const &) */

void __thiscall CHmsCollisionManager::SZone::
    DetectCollisionBetweenTreeAndStaticCollisionTree(SZone *this,
                                                     GmIso4 *param_1,
                                                     CPlugTree *param_2)

{
  CPlugTree *this_00;
  uint uVar1;
  CPlugTree *pCVar2;
  GmIso4 *pGVar3;
  int iVar4;
  CHmsCollisionBuffer *pCVar5;
  CPlugTree *pCVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  undefined4 uStack_64;
  undefined4 *puStack_60;
  int iStack_5c;
  int *piStack_58;
  GmBoxAligned aGStack_54[24];
  undefined4 local_3c[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  this_00 = param_2;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a955db;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffff7c;
  ExceptionList = &local_c;
  if ((char)*(uint *)(param_2 + 0x9c) < '\0') {
    iVar8 = 0xc;
    puVar7 = local_3c;
    puVar10 = (undefined4 *)param_1;
    if ((*(uint *)(param_2 + 0x9c) & 4) == 0) {
      for (; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar7 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar7 = puVar7 + 1;
      }
    } else {
      puVar10 = (undefined4 *)(param_2 + 0x5c);
      for (; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar7 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar7 = puVar7 + 1;
      }
      GmIso4::Mult((GmIso4 *)local_3c, param_1);
    }
    uVar1 = (**(code **)(*(int *)this_00 + 0x7c))(uVar1);
    uVar11 = 0;
    if (uVar1 != 0) {
      do {
        pCVar2 = (CPlugTree *)(**(code **)(*(int *)this_00 + 0x80))(uVar11);
        DetectCollisionBetweenTreeAndStaticCollisionTree(
            this, (GmIso4 *)local_3c, pCVar2);
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar1);
    }
    if (*(int *)(this_00 + 0x8c) != 0) {
      GmBoxAligned::SetMult(aGStack_54, (GmBoxAligned *)(this_00 + 0x34),
                            param_1);
      iVar8 = *(int *)(this + 0x194);
      param_1 = (GmIso4 *)0x0;
      pGVar3 =
          (GmIso4 *)CFastBuffer<>::GetCount((CFastBuffer<> *)(iVar8 + 0x30));
      if (pGVar3 != (GmIso4 *)0x0) {
        do {
          piVar12 = (int *)((int)param_1 * 0x58 + *(int *)(iVar8 + 0x34));
          iVar4 = GmBoxAligned::TestInter(aGStack_54,
                                          (GmBoxAligned *)(piVar12 + 1));
          if (iVar4 == 0) {
            param_1 = param_1 + *piVar12;
          } else {
            if ((piVar12[0x13] != 0) &&
                ((*(byte *)(piVar12[0x14] + 0x9c) & 0x80) != 0)) {
              param_2 = (CPlugTree *)0x0;
              if ((*(char *)(*(int *)(*(int *)(*(int *)(this_00 + 0x8c) +
                                               0x14) +
                                      0x34) +
                             6) == '\0') ||
                  (*(char *)(*(int *)(*(int *)(*(int *)(this_00 + 0x8c) +
                                               0x14) +
                                      0x34) +
                             6) == '\x01')) {
                if (*(int *)(this_00 + 0x50) == 0) {
                  pCVar5 = (CHmsCollisionBuffer *)operator_new(0x14);
                  uStack_4 = 0;
                  param_2 = (CPlugTree *)pCVar5;
                  if (pCVar5 == (CHmsCollisionBuffer *)0x0) {
                    pCVar5 = (CHmsCollisionBuffer *)0x0;
                  } else {
                    CHmsCollisionBuffer::CHmsCollisionBuffer(pCVar5);
                    *(undefined4 *)(pCVar5 + 0x10) = 0;
                  }
                  *(CHmsCollisionBuffer **)(this_00 + 0x50) = pCVar5;
                  uStack_4 = 0xffffffff;
                  CMwNod::MwAddDependant((CMwNod *)this_00,
                                         *(CMwNod **)(this + 0x19c));
                }
                piVar9 = *(int **)(this_00 + 0x50);
                param_2 = (CPlugTree *)piVar9;
              } else {
                piVar9 = *(int **)(this + 400);
              }
              pCVar2 = param_2;
              pCVar6 = (CPlugTree *)(**(code **)(*piVar9 + 8))();
              uStack_64 = *(undefined4 *)(this_00 + 0x8c);
              puStack_60 = local_3c;
              iStack_5c = piVar12[0x13];
              piStack_58 = piVar12 + 7;
              iVar4 = CPlugSurface::ComputeCollision(
                  (SPlugSurfaceLocatedPair *)&uStack_64,
                  (CGmCollisionBuffer *)piVar9);
              if (iVar4 != 0) {
                if ((pCVar2 != (CPlugTree *)0x0) &&
                    (*(int *)(pCVar2 + 0x10) == 0)) {
                  *(undefined4 *)(pCVar2 + 0x10) = 1;
                  CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x1a0),
                                     (CDx9TextureKeeper **)&param_2);
                }
                param_2 = (CPlugTree *)(**(code **)(*piVar9 + 8))();
                if (pCVar6 < param_2) {
                  do {
                    puVar7 = (undefined4 *)CFastBuffer<>::operator[](
                        (CFastBuffer<> *)(piVar9 + 1), (ulong)pCVar6);
                    puVar7[1] = this_00;
                    puVar7[3] = piVar12[0x14];
                    *puVar7 = *(undefined4 *)(this + 0x188);
                    puVar7[2] = piVar12[0x15];
                    pCVar6 = pCVar6 + 1;
                    puVar7[0x12] = *(undefined4 *)(this + 0x184);
                  } while (pCVar6 < param_2);
                }
              }
            }
            param_1 = param_1 + 1;
          }
        } while (param_1 < pGVar3);
      }
    }
  }
  ExceptionList = local_c;
  return;
}

/* public: void __thiscall
   CHmsCollisionManager::SZone::DetectCollisionsCorpus(struct
   CHmsCollisionBuffer &,class CHmsCorpus *) */

void __thiscall CHmsCollisionManager::SZone::DetectCollisionsCorpus(
    SZone *this, CHmsCollisionBuffer *param_1, CHmsCorpus *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  CHmsCorpus *pCVar4;
  CHmsCorpus *pCVar5;
  int *piVar6;
  int *piVar7;
  CHmsCorpus **ppCVar8;
  GmIso4 *pGVar9;
  ulong uVar10;
  SHmsSphereBufferContact **ppSVar11;
  ulong uVar12;
  CFastBuffer<> *this_00;

  pCVar4 = param_2;
  *(CHmsCollisionBuffer **)(this + 400) = param_1;
  uVar1 = *(uint *)(*(int *)(param_2 + 0x48) + 0x18);
  uVar10 = *(ulong *)(param_2 + 0x54);
  pCVar5 = (CHmsCorpus *)CFastBuffer<>::GetCount(
      (CFastBuffer<> *)(this + (uVar1 >> 0xd & 0xf) * 0x44 + -0x20));
  param_2 = (CHmsCorpus *)0x0;
  if (pCVar5 != (CHmsCorpus *)0x0) {
    do {
      piVar6 = (int *)CFastArray<>::operator[](
          (CFastArray<> *)(CFastBuffer<> *)(this + (uVar1 >> 0xd & 0xf) * 0x44 +
                                            -0x20),
          (ulong)param_2);
      *(int *)(this + 0x184) = piVar6[1];
      uVar2 = piVar6[4];
      uVar12 = 0;
      if (uVar2 != 0) {
        do {
          piVar7 = CFastRectTable<int>::Get((CFastRectTable<int> *)(piVar6 + 2),
                                            uVar10, uVar12);
          if (*piVar7 != 0) {
            ppCVar8 = (CHmsCorpus **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(*piVar6 + 0xc), uVar12);
            DetectCollisionBetween(this, pCVar4, *ppCVar8);
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 < uVar2);
      }
      iVar3 = *piVar6;
      *(int *)(this + 0x194) = iVar3;
      uVar12 = CFastBuffer<>::GetCount((CFastBuffer<> *)(iVar3 + 0x30));
      if (1 < uVar12) {
        *(CHmsCorpus **)(this + 0x188) = pCVar4;
        if (*(int *)(pCVar4 + 0x58) == 0) {
          pGVar9 = (GmIso4 *)(pCVar4 + 0x18);
        } else {
          pGVar9 = (GmIso4 *)(*(int *)(*(int *)(pCVar4 + 0x58) + 0x32c) + 0x10);
        }
        DetectCollisionBetweenTreeAndStaticCollisionTree(
            this, pGVar9,
            *(CPlugTree **)(*(int *)(*(int *)(pCVar4 + 0x48) + 0x14) + 100));
      }
      param_2 = param_2 + 1;
    } while (param_2 < pCVar5);
  }
  this_00 = (CFastBuffer<> *)(this + 0x1a0);
  uVar10 = CFastBuffer<>::GetCount(this_00);
  uVar12 = 0;
  if (uVar10 != 0) {
    do {
      ppSVar11 = (SHmsSphereBufferContact **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)this_00, uVar12);
      SHmsSphereBufferContact::MergeAndAddToCollisions(*ppSVar11, param_1);
      uVar12 = uVar12 + 1;
    } while (uVar12 < uVar10);
  }
  CFastBuffer<>::Reset((CFastBuffer<> *)this_00);
  return;
}

/* public: int __thiscall CHmsCollisionManager::SZone::IntersectSegment(enum
   CHmsItem::ECollisionGroup,class GmVec3 const &,class GmVec3 const &,float
   &,class CPlugTree * *)
    */

int __thiscall CHmsCollisionManager::SZone::IntersectSegment(
    SZone *this, ECollisionGroup param_1, GmVec3 *param_2, GmVec3 *param_3,
    float *param_4, CPlugTree **param_5)

{
  float *pfVar1;
  GmVec3 *pGVar2;
  GmVec3 *pGVar3;
  ulong uVar4;
  int iVar5;
  GmIso4 *pGVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  int *piVar10;
  CFastBuffer<> *this_00;
  float local_c;
  float local_8;
  float local_4;
  SZone *pSVar11;

  pGVar3 = param_3;
  pGVar2 = param_2;
  local_c = *(float *)param_2;
  pfVar1 = (float *)(param_2 + 4);
  uVar8 = 0;
  param_2 = (GmVec3 *)0x0;
  local_c = *(float *)param_3 + local_c;
  local_8 = *(float *)(param_3 + 4) + *pfVar1;
  local_4 = *(float *)(param_3 + 8) + *(float *)(pGVar2 + 8);
  *param_4 = 3.402823e+38;
  pSVar11 = this + param_1 * 0x44;
  param_3 = (GmVec3 *)pSVar11;
  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(pSVar11 + -0x14));
  if (uVar4 != 0) {
    do {
      piVar10 = (int *)(uVar8 * 0x58 + *(int *)(param_3 + -0x10));
      iVar5 = GmBoxAligned::TestInterSegment((GmBoxAligned *)(piVar10 + 1),
                                             pGVar2, (GmVec3 *)&local_c);
      if (iVar5 == 0) {
        uVar8 = uVar8 + *piVar10;
      } else {
        if ((((piVar10[0x13] != 0) && (iVar5 = *(int *)(piVar10[0x13] + 0x14),
                                       *(int *)(iVar5 + 0x34) != 0)) &&
             (iVar5 = GmSurf::ClipSegment(
                  pGVar2, pGVar3, *(GmSurf **)(iVar5 + 0x34),
                  (GmIso4 *)(piVar10 + 7), (float *)&param_1),
              iVar5 != 0)) &&
            ((float)param_1 < *param_4)) {
          *param_4 = (float)param_1;
          param_2 = (GmVec3 *)&DAT_00000001;
          if (param_5 != (CPlugTree **)0x0) {
            *param_5 = (CPlugTree *)piVar10[0x14];
          }
        }
        uVar8 = uVar8 + 1;
      }
      pSVar11 = (SZone *)param_3;
    } while (uVar8 < uVar4);
  }
  this_00 = (CFastBuffer<> *)(pSVar11 + -0x38);
  param_3 = (GmVec3 *)this_00;
  uVar4 = CFastBuffer<>::GetCount(this_00);
  uVar9 = 0;
  if (uVar4 != 0) {
    do {
      piVar10 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar9);
      iVar5 = *piVar10;
      if (*(int *)(iVar5 + 0x58) == 0) {
        pGVar6 = (GmIso4 *)(iVar5 + 0x18);
      } else {
        pGVar6 = (GmIso4 *)(*(int *)(*(int *)(iVar5 + 0x58) + 0x32c) + 0x10);
      }
      iVar7 = IntersectSegmentTree(
          this, pGVar2, pGVar3,
          *(CPlugTree **)(*(int *)(*(int *)(iVar5 + 0x48) + 0x14) + 100),
          pGVar6, (float *)&param_1);
      if ((iVar7 != 0) && ((float)param_1 < *param_4)) {
        *param_4 = (float)param_1;
        param_2 = (GmVec3 *)&DAT_00000001;
        if (param_5 != (CPlugTree **)0x0) {
          *param_5 =
              *(CPlugTree **)(*(int *)(*(int *)(iVar5 + 0x48) + 0x14) + 100);
        }
      }
      uVar9 = uVar9 + 1;
      this_00 = (CFastBuffer<> *)param_3;
    } while (uVar9 < uVar4);
  }
  return (int)param_2;
}

/* public: int __thiscall CHmsCollisionManager::SZone::IntersectSegment2(enum
   CHmsItem::ECollisionGroup,class GmVec3 const &,class GmVec3 const &,int,float
   &,class GmVec3 &)
    */

int __thiscall CHmsCollisionManager::SZone::IntersectSegment2(
    SZone *this, ECollisionGroup param_1, GmVec3 *param_2, GmVec3 *param_3,
    int param_4, float *param_5, GmVec3 *param_6)

{
  float *pfVar1;
  ECollisionGroup EVar2;
  GmVec3 *pGVar3;
  GmVec3 *pGVar4;
  ulong uVar5;
  int iVar6;
  GmIso4 *pGVar7;
  uint uVar8;
  int *piVar9;
  GmVec3 *pGVar10;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  pGVar3 = param_2;
  EVar2 = param_1;
  local_18 = *(float *)param_2;
  uVar8 = 0;
  pfVar1 = (float *)(param_2 + 4);
  param_2 = (GmVec3 *)0x0;
  local_18 = *(float *)param_3 + local_18;
  local_14 = *(float *)(param_3 + 4) + *pfVar1;
  local_10 = *(float *)(param_3 + 8) + *(float *)(pGVar3 + 8);
  uVar5 =
      CFastBuffer<>::GetCount((CFastBuffer<> *)(this + param_1 * 0x44 + -0x14));
  pGVar4 = param_6;
  if (uVar5 != 0) {
    do {
      piVar9 = (int *)(uVar8 * 0x58 + *(int *)(this + EVar2 * 0x44 + -0x10));
      iVar6 = GmBoxAligned::TestInterSegment((GmBoxAligned *)(piVar9 + 1),
                                             pGVar3, (GmVec3 *)&local_18);
      if (iVar6 == 0) {
        uVar8 = uVar8 + *piVar9;
      } else {
        if (((piVar9[0x13] != 0) && (iVar6 = *(int *)(piVar9[0x13] + 0x14),
                                     *(int *)(iVar6 + 0x34) != 0)) &&
            (iVar6 = GmSurf::ClipSegment2(pGVar3, param_3, param_4,
                                          (float *)&param_1, (GmVec3 *)&local_c,
                                          *(GmSurf **)(iVar6 + 0x34),
                                          (GmIso4 *)(piVar9 + 7)),
             iVar6 != 0)) {
          if (param_2 == (GmVec3 *)0x0) {
            *param_5 = (float)param_1;
            param_2 = (GmVec3 *)&DAT_00000001;
          } else {
            if (*param_5 <= (float)param_1)
              goto LAB_00539e30;
            *param_5 = (float)param_1;
          }
          *(undefined4 *)pGVar4 = local_c;
          *(undefined4 *)(pGVar4 + 4) = local_8;
          *(undefined4 *)(pGVar4 + 8) = local_4;
        }
      LAB_00539e30:
        uVar8 = uVar8 + 1;
      }
    } while (uVar8 < uVar5);
  }
  param_6 = (GmVec3 *)CFastBuffer<>::GetCount(
      (CFastBuffer<> *)(this + EVar2 * 0x44 + -0x38));
  pGVar10 = (GmVec3 *)0x0;
  if (param_6 != (GmVec3 *)0x0) {
    do {
      piVar9 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + EVar2 * 0x44 + -0x38),
          (ulong)pGVar10);
      iVar6 = *piVar9;
      if (*(int *)(iVar6 + 0x58) == 0) {
        pGVar7 = (GmIso4 *)(iVar6 + 0x18);
      } else {
        pGVar7 = (GmIso4 *)(*(int *)(*(int *)(iVar6 + 0x58) + 0x32c) + 0x10);
      }
      iVar6 = IntersectSegmentTree2(
          this, pGVar3, param_3, param_4,
          *(CPlugTree **)(*(int *)(*(int *)(iVar6 + 0x48) + 0x14) + 100),
          pGVar7, (float *)&param_1, (GmVec3 *)&local_c);
      if (iVar6 != 0) {
        if (param_2 == (GmVec3 *)0x0) {
          *param_5 = (float)param_1;
          param_2 = (GmVec3 *)&DAT_00000001;
        } else {
          if (*param_5 <= (float)param_1)
            goto LAB_00539ef4;
          *param_5 = (float)param_1;
        }
        *(undefined4 *)pGVar4 = local_c;
        *(undefined4 *)(pGVar4 + 4) = local_8;
        *(undefined4 *)(pGVar4 + 8) = local_4;
      }
    LAB_00539ef4:
      pGVar10 = pGVar10 + 1;
    } while (pGVar10 < param_6);
  }
  return (int)param_2;
}

/* public: int __thiscall CHmsCollisionManager::SZone::IntersectSegment3(enum
   CHmsItem::ECollisionGroup,class GmVec3 const &,class GmVec3 const &,float
   &,unsigned short &) */

int __thiscall CHmsCollisionManager::SZone::IntersectSegment3(
    SZone *this, ECollisionGroup param_1, GmVec3 *param_2, GmVec3 *param_3,
    float *param_4, ushort *param_5)

{
  GmVec3 *pGVar1;
  GmVec3 *pGVar2;
  int iVar3;
  GmIso4 *pGVar4;
  uint uVar5;
  ulong uVar6;
  int *piVar7;
  SZone *pSVar8;
  float local_18;
  ulong local_14;
  SZone *local_10;
  float local_c;
  float local_8;
  float local_4;

  pGVar2 = param_3;
  pGVar1 = param_2;
  uVar5 = 0;
  param_3 = (GmVec3 *)0x0;
  local_c = *(float *)pGVar2 + *(float *)param_2;
  local_8 = *(float *)(pGVar2 + 4) + *(float *)(param_2 + 4);
  local_4 = *(float *)(pGVar2 + 8) + *(float *)(param_2 + 8);
  *param_4 = 3.402823e+38;
  pSVar8 = this + param_1 * 0x44;
  param_1 = (ECollisionGroup)pSVar8;
  local_10 = this;
  local_14 = CFastBuffer<>::GetCount((CFastBuffer<> *)(pSVar8 + -0x14));
  if (local_14 != 0) {
    do {
      piVar7 = (int *)(uVar5 * 0x58 + *(int *)(param_1 + 0xfffffff0));
      iVar3 = GmBoxAligned::TestInterSegment((GmBoxAligned *)(piVar7 + 1),
                                             pGVar1, (GmVec3 *)&local_c);
      if (iVar3 == 0) {
        uVar5 = uVar5 + *piVar7;
      } else {
        if ((((piVar7[0x13] != 0) && (iVar3 = *(int *)(piVar7[0x13] + 0x14),
                                      *(int *)(iVar3 + 0x34) != 0)) &&
             (iVar3 = GmSurf::ClipSegment3(
                  pGVar1, pGVar2, *(GmSurf **)(iVar3 + 0x34),
                  (GmIso4 *)(piVar7 + 7), &local_18, (ushort *)&param_2),
              iVar3 != 0)) &&
            (local_18 < *param_4)) {
          *param_4 = local_18;
          param_3 = (GmVec3 *)&DAT_00000001;
          piVar7 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(piVar7[0x13] + 0x18), (uint)param_2 & 0xffff);
          *param_5 = (ushort) * (byte *)(*piVar7 + 0x18);
        }
        uVar5 = uVar5 + 1;
      }
      pSVar8 = (SZone *)param_1;
    } while (uVar5 < local_14);
  }
  local_14 = CFastBuffer<>::GetCount((CFastBuffer<> *)(pSVar8 + -0x38));
  uVar6 = 0;
  if (local_14 != 0) {
    do {
      piVar7 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(pSVar8 + -0x38), uVar6);
      iVar3 = *piVar7;
      if (*(int *)(iVar3 + 0x58) == 0) {
        pGVar4 = (GmIso4 *)(iVar3 + 0x18);
      } else {
        pGVar4 = (GmIso4 *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x32c) + 0x10);
      }
      iVar3 = IntersectSegmentTree3(
          local_10, pGVar1, pGVar2,
          *(CPlugTree **)(*(int *)(*(int *)(iVar3 + 0x48) + 0x14) + 100),
          pGVar4, (float *)&param_1, (ushort *)&param_2);
      if ((iVar3 != 0) && ((float)param_1 < *param_4)) {
        *param_4 = (float)param_1;
        param_3 = (GmVec3 *)&DAT_00000001;
        *param_5 = (ushort)param_2;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < local_14);
  }
  return (int)param_3;
}

/* private: int __thiscall
   CHmsCollisionManager::SZone::IntersectSegmentTree(class GmVec3 const
   &,class GmVec3 const &,class CPlugTree const &,class GmIso4 const &,float &)
 */

int __thiscall CHmsCollisionManager::SZone::IntersectSegmentTree(
    SZone *this, GmVec3 *param_1, GmVec3 *param_2, CPlugTree *param_3,
    GmIso4 *param_4, float *param_5)

{
  CPlugTree *pCVar1;
  int iVar2;
  uint uVar3;
  CPlugTree *pCVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  GmIso4 **ppGVar8;
  float local_54;
  float local_50;
  float local_4c;
  GmBoxAligned local_48[24];
  undefined4 local_30[12];

  puVar5 = (undefined4 *)param_4;
  pCVar1 = param_3;
  if (((byte)param_3[0x9c] & 0x80) == 0) {
    return 0;
  }
  GmBoxAligned::SetMult(local_48, (GmBoxAligned *)(param_3 + 0x34), param_4);
  local_54 = *(float *)param_2 + *(float *)param_1;
  local_50 = *(float *)(param_2 + 4) + *(float *)(param_1 + 4);
  local_4c = *(float *)(param_2 + 8) + *(float *)(param_1 + 8);
  iVar2 =
      GmBoxAligned::TestInterSegment(local_48, param_1, (GmVec3 *)&local_54);
  if (iVar2 != 0) {
    pCVar4 = param_3 + 0x9c;
    param_3 = (CPlugTree *)0x0;
    iVar2 = 0xc;
    puVar7 = local_30;
    if (((byte)*pCVar4 & 4) == 0) {
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
    } else {
      puVar5 = (undefined4 *)(pCVar1 + 0x5c);
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      GmIso4::Mult((GmIso4 *)local_30, param_4);
    }
    if (((*(int *)(pCVar1 + 0x8c) != 0) &&
         (iVar2 = *(int *)(*(int *)(pCVar1 + 0x8c) + 0x14),
          *(int *)(iVar2 + 0x34) != 0)) &&
        (iVar2 =
             GmSurf::ClipSegment(param_1, param_2, *(GmSurf **)(iVar2 + 0x34),
                                 (GmIso4 *)local_30, (float *)&param_4),
         iVar2 != 0)) {
      *param_5 = (float)param_4;
      param_3 = (CPlugTree *)&DAT_00000001;
    }
    uVar3 = (**(code **)(*(int *)pCVar1 + 0x7c))();
    uVar6 = 0;
    if (uVar3 != 0) {
      do {
        ppGVar8 = &param_4;
        puVar5 = local_30;
        pCVar4 = (CPlugTree *)(**(code **)(*(int *)pCVar1 + 0x80))(uVar6);
        iVar2 = IntersectSegmentTree(this, param_1, param_2, pCVar4,
                                     (GmIso4 *)puVar5, (float *)ppGVar8);
        if (iVar2 != 0) {
          if (param_3 == (CPlugTree *)0x0) {
            *param_5 = (float)param_4;
            param_3 = (CPlugTree *)&DAT_00000001;
          } else if ((float)param_4 < *param_5) {
            *param_5 = (float)param_4;
          }
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar3);
    }
    return (int)param_3;
  }
  return 0;
}

/* private: int __thiscall
   CHmsCollisionManager::SZone::IntersectSegmentTree2(class GmVec3 const
   &,class GmVec3 const &,int,class CPlugTree const &,class GmIso4 const &,float
   &,class GmVec3 &)
    */

int __thiscall CHmsCollisionManager::SZone::IntersectSegmentTree2(
    SZone *this, GmVec3 *param_1, GmVec3 *param_2, int param_3,
    CPlugTree *param_4, GmIso4 *param_5, float *param_6, GmVec3 *param_7)

{
  CPlugTree *pCVar1;
  GmVec3 *pGVar2;
  int iVar3;
  uint uVar4;
  CPlugTree *pCVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  GmIso4 **ppGVar9;
  float *pfVar10;
  float local_54;
  float local_50;
  float local_4c;
  GmBoxAligned local_48[24];
  undefined4 local_30[12];

  puVar6 = (undefined4 *)param_5;
  pCVar1 = param_4;
  if (((byte)param_4[0x9c] & 0x80) == 0) {
    return 0;
  }
  GmBoxAligned::SetMult(local_48, (GmBoxAligned *)(param_4 + 0x34), param_5);
  local_54 = *(float *)param_2 + *(float *)param_1;
  local_50 = *(float *)(param_2 + 4) + *(float *)(param_1 + 4);
  local_4c = *(float *)(param_2 + 8) + *(float *)(param_1 + 8);
  iVar3 =
      GmBoxAligned::TestInterSegment(local_48, param_1, (GmVec3 *)&local_54);
  if (iVar3 == 0) {
    return 0;
  }
  pCVar5 = param_4 + 0x9c;
  param_4 = (CPlugTree *)0x0;
  iVar3 = 0xc;
  puVar7 = local_30;
  if (((byte)*pCVar5 & 4) == 0) {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
  } else {
    puVar6 = (undefined4 *)(pCVar1 + 0x5c);
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    GmIso4::Mult((GmIso4 *)local_30, param_5);
  }
  pGVar2 = param_7;
  if (((*(int *)(pCVar1 + 0x8c) != 0) &&
       (iVar3 = *(int *)(*(int *)(pCVar1 + 0x8c) + 0x14),
        *(int *)(iVar3 + 0x34) != 0)) &&
      (iVar3 = GmSurf::ClipSegment2(
           param_1, param_2, param_3, (float *)&param_5, (GmVec3 *)&local_54,
           *(GmSurf **)(iVar3 + 0x34), (GmIso4 *)local_30),
       iVar3 != 0)) {
    *param_6 = (float)param_5;
    param_4 = (CPlugTree *)&DAT_00000001;
    *(float *)pGVar2 = local_54;
    *(float *)(pGVar2 + 4) = local_50;
    *(float *)(pGVar2 + 8) = local_4c;
  }
  uVar4 = (**(code **)(*(int *)pCVar1 + 0x7c))();
  uVar8 = 0;
  if (uVar4 != 0) {
    do {
      pfVar10 = &local_54;
      ppGVar9 = &param_5;
      puVar6 = local_30;
      pCVar5 = (CPlugTree *)(**(code **)(*(int *)pCVar1 + 0x80))(uVar8);
      iVar3 = IntersectSegmentTree2(this, param_1, param_2, param_3, pCVar5,
                                    (GmIso4 *)puVar6, (float *)ppGVar9,
                                    (GmVec3 *)pfVar10);
      if (iVar3 != 0) {
        if (param_4 == (CPlugTree *)0x0) {
          *param_6 = (float)param_5;
          param_4 = (CPlugTree *)&DAT_00000001;
        } else {
          if (*param_6 <= (float)param_5)
            goto LAB_00537c87;
          *param_6 = (float)param_5;
        }
        *(float *)pGVar2 = local_54;
        *(float *)(pGVar2 + 4) = local_50;
        *(float *)(pGVar2 + 8) = local_4c;
      }
    LAB_00537c87:
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar4);
  }
  return (int)param_4;
}

/* private: int __thiscall
   CHmsCollisionManager::SZone::IntersectSegmentTree3(class GmVec3 const
   &,class GmVec3 const &,class CPlugTree const &,class GmIso4 const &,float
   &,unsigned short &) */

int __thiscall CHmsCollisionManager::SZone::IntersectSegmentTree3(
    SZone *this, GmVec3 *param_1, GmVec3 *param_2, CPlugTree *param_3,
    GmIso4 *param_4, float *param_5, ushort *param_6)

{
  GmVec3 *pGVar1;
  CPlugTree *pCVar2;
  float *pfVar3;
  int iVar4;
  int *piVar5;
  CPlugTree *pCVar6;
  undefined4 *puVar7;
  float *pfVar8;
  undefined4 *puVar9;
  GmVec3 **ppGVar10;
  GmIso4 **ppGVar11;
  float local_54;
  float local_50;
  float local_4c;
  GmBoxAligned local_48[24];
  undefined4 local_30[12];

  puVar7 = (undefined4 *)param_4;
  pCVar2 = param_3;
  if (((byte)param_3[0x9c] & 0x80) == 0) {
    return 0;
  }
  GmBoxAligned::SetMult(local_48, (GmBoxAligned *)(param_3 + 0x34), param_4);
  pGVar1 = param_1;
  local_54 = *(float *)param_2 + *(float *)param_1;
  local_50 = *(float *)(param_2 + 4) + *(float *)(param_1 + 4);
  local_4c = *(float *)(param_2 + 8) + *(float *)(param_1 + 8);
  iVar4 =
      GmBoxAligned::TestInterSegment(local_48, param_1, (GmVec3 *)&local_54);
  if (iVar4 != 0) {
    param_3 = (CPlugTree *)0x0;
    iVar4 = 0xc;
    puVar9 = local_30;
    if (((byte)pCVar2[0x9c] & 4) == 0) {
      for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
    } else {
      puVar7 = (undefined4 *)(pCVar2 + 0x5c);
      for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      GmIso4::Mult((GmIso4 *)local_30, param_4);
    }
    pfVar3 = param_5;
    if (((*(int *)(pCVar2 + 0x8c) != 0) &&
         (iVar4 = *(int *)(*(int *)(pCVar2 + 0x8c) + 0x14),
          *(int *)(iVar4 + 0x34) != 0)) &&
        (iVar4 = GmSurf::ClipSegment3(
             pGVar1, param_2, *(GmSurf **)(iVar4 + 0x34), (GmIso4 *)local_30,
             (float *)&param_1, (ushort *)&param_4),
         iVar4 != 0)) {
      *pfVar3 = (float)param_1;
      param_3 = (CPlugTree *)&DAT_00000001;
      piVar5 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(pCVar2 + 0x8c) + 0x18),
          (uint)param_4 & 0xffff);
      *param_6 = (ushort) * (byte *)(*piVar5 + 0x18);
    }
    param_5 = (float *)(**(code **)(*(int *)pCVar2 + 0x7c))();
    pfVar8 = (float *)0x0;
    if (param_5 != (float *)0x0) {
      do {
        ppGVar11 = &param_4;
        ppGVar10 = &param_1;
        puVar7 = local_30;
        pCVar6 = (CPlugTree *)(**(code **)(*(int *)pCVar2 + 0x80))(pfVar8);
        iVar4 = IntersectSegmentTree3(this, pGVar1, param_2, pCVar6,
                                      (GmIso4 *)puVar7, (float *)ppGVar10,
                                      (ushort *)ppGVar11);
        if (iVar4 != 0) {
          if (param_3 == (CPlugTree *)0x0) {
            *pfVar3 = (float)param_1;
            param_3 = (CPlugTree *)&DAT_00000001;
            *param_6 = (ushort)param_4;
          } else if ((float)param_1 < *pfVar3) {
            *pfVar3 = (float)param_1;
            *param_6 = (ushort)param_4;
          }
        }
        pfVar8 = (float *)((int)pfVar8 + 1);
      } while (pfVar8 < param_5);
    }
    return (int)param_3;
  }
  return 0;
}

/* public: void __thiscall CHmsCollisionManager::SZone::PrepareCollisions(void)
 */

void __thiscall CHmsCollisionManager::SZone::PrepareCollisions(SZone *this)

{
  int iVar1;
  SZone *this_00;
  int iVar2;

  iVar1 = 5;
  this_00 = this;
  do {
    iVar2 = iVar1;
    SGroup::ComputeNonStaticCorpusInfos((SGroup *)this_00);
    this_00 = (SZone *)((SGroup *)this_00 + 0x44);
    iVar1 = iVar2 + -1;
  } while (iVar1 != 0);
  iVar2 = iVar2 + 4;
  do {
    SGroup::ComputeIsToPerformCollisions((SGroup *)this);
    this = (SZone *)((SGroup *)this + 0x44);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* public: void __thiscall CHmsCollisionManager::SZone::RemoveCorpus(class
 * CHmsCorpus *) */

void __thiscall CHmsCollisionManager::SZone::RemoveCorpus(SZone *this,
                                                          CHmsCorpus *param_1)

{
  uint uVar1;

  uVar1 = *(uint *)(*(int *)(param_1 + 0x48) + 0x18) >> 0xd & 0xf;
  if (uVar1 != 0) {
    SGroup::RemoveCorpus((SGroup *)(this + uVar1 * 0x44 + -0x44), param_1);
    return;
  }
  return;
}

/* public: __thiscall CHmsCollisionManager::SZone::SZone(unsigned long,class
 * CHmsCollisionManager *)
 */

SZone *__thiscall CHmsCollisionManager::SZone::SZone(
    SZone *this, ulong param_1, CHmsCollisionManager *param_2)

{
  int *piVar1;
  ulong uVar2;
  SZone **ppSVar3;
  int iVar4;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9572f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  `eh_vector_constructor_iterator'(this,0x44,5,SGroup::SGroup,SGroup::~SGroup); iVar4 = 0; local_4 = 0; GmMap2<>:: GmMap2<>(
      (GmMap2<> *)(this + 0x154));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x1a0));
  *(undefined4 *)(this + 0x178) = 0xff7fffff;
  *(undefined4 *)(this + 0x17c) = 0xff7fffff;
  *(CHmsCollisionManager **)(this + 0x19c) = param_2;
  *(undefined4 *)(this + 0x180) = 0xff7fffff;
  *(ulong *)(this + 0x198) = param_1;
  *(undefined4 *)(this + 0x80) = 1;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0xc4) = 2;
  *(undefined4 *)(this + 200) = 0;
  *(undefined4 *)(this + 0x108) = 3;
  *(undefined4 *)(this + 0x14c) = 4;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x10c) = 1;
  local_4 = CONCAT31(local_4._1_3_, 2);
  for (uVar2 = CFastBuffer<>::GetCount(
           (CFastBuffer<> *)&CHmsItem::s_CollisionGroupPairs);
       uVar2 != 0; uVar2 = uVar2 - 1) {
    piVar1 = (int *)(iVar4 + DAT_00d67594);
    ppSVar3 = (SZone **)CFastBuffer<>::AddNewElem(
        (CFastBuffer<> *)(this + *piVar1 * 0x44 + -0x20));
    *ppSVar3 = this + piVar1[1] * 0x44 + -0x44;
    ppSVar3[1] = (SZone *)piVar1;
    if (*piVar1 != piVar1[1]) {
      ppSVar3 = (SZone **)CFastBuffer<>::AddNewElem(
          (CFastBuffer<> *)(this + piVar1[1] * 0x44 + -0x20));
      *ppSVar3 = this + *piVar1 * 0x44 + -0x44;
      ppSVar3[1] = (SZone *)piVar1;
    }
    iVar4 = iVar4 + 0x14;
  }
  ExceptionList = local_c;
  return this;
}

/* public: void __thiscall
 * CHmsCollisionManager::SZone::UpdateStaticCollisionTrees(void) */

void __thiscall CHmsCollisionManager::SZone::UpdateStaticCollisionTrees(
    SZone *this)

{
  int iVar1;

  iVar1 = 5;
  do {
    SGroup::UpdateStaticCollisionTrees((SGroup *)this, 1);
    this = (SZone *)((SGroup *)this + 0x44);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* public: void __thiscall
 * CHmsCollisionManager::UpdateStaticCollisionTrees(void) */

void __thiscall CHmsCollisionManager::UpdateStaticCollisionTrees(
    CHmsCollisionManager *this)

{
  ulong uVar1;
  SZone **ppSVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x18));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      ppSVar2 = (SZone **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x18), uVar3);
      SZone::UpdateStaticCollisionTrees(*ppSVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}
