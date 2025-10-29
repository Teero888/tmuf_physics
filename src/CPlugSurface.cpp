
/* public: virtual void * __thiscall CPlugSurface::`scalar deleting
 * destructor'(unsigned int) */

void *__thiscall CPlugSurface::`scalar_deleting_destructor'(CPlugSurface *this,uint param_1)

{
  ~CPlugSurface(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
/* public: virtual void __thiscall CPlugSurface::Chunk(class CClassicArchive
 * &,unsigned long) */

void __thiscall CPlugSurface::Chunk(CPlugSurface *this,
                                    CClassicArchive *param_1, ulong param_2)

{
  CMwNod *this_00;
  CClassicArchive *this_01;
  CClassicArchive *pCVar1;
  ulong uVar2;
  CGameMenuFrame **ppCVar3;
  int iVar4;
  CMwNod **ppCVar5;
  int *piVar6;
  uint unaff_EBX;
  CFastBuffer<> *this_02;
  ulong uVar7;
  uint unaff_retaddr;

  this_01 = param_1;
  if (param_2 == 0x900c000) {
    param_2 = *(ulong *)(this + 0x14);
    (**(code **)(*(int *)param_1 + 4))(&param_2);
    pCVar1 = param_1;
    if (param_1 != *(CClassicArchive **)(this + 0x14)) {
      if (param_1 != (CClassicArchive *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_1);
      }
      if (*(CMwNod **)(this + 0x14) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x14));
      }
      *(CClassicArchive **)(this + 0x14) = pCVar1;
    }
    this_02 = (CFastBuffer<> *)(this + 0x18);
    CFastBuffer<>::ArchiveCount(this_02, this_01);
    uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_02);
    uVar7 = 0;
    if (uVar2 != 0) {
      do {
        if (*(int *)(this_01 + 8) != 0) {
          ppCVar3 = (CGameMenuFrame **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)this_02, uVar7);
          iVar4 = CFastArray<>::Find((CFastArray<> *)&s_DefaultSurfaceMaterials,
                                     ppCVar3);
          unaff_retaddr = (uint)(iVar4 == -1);
        }
        CClassicArchive::DoBool(this_01, (int *)&stack0x00000000, 1);
        if (unaff_retaddr == 0) {
          if (*(int *)(this_01 + 8) != 0) {
            piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_02,
                                                      uVar7);
            unaff_EBX = (uint) * (byte *)(*piVar6 + 0x18);
          }
          CClassicArchive::DoNat16(this_01, (ushort *)&stack0xffffffec, 1, 0);
          if (*(int *)(this_01 + 8) == 0) {
            ppCVar5 = (CMwNod **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)&s_DefaultSurfaceMaterials,
                unaff_EBX & 0xffff);
            this_00 = *ppCVar5;
            ppCVar5 = (CMwNod **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)this_02, uVar7);
            if (this_00 != *ppCVar5) {
              if (this_00 != (CMwNod *)0x0) {
                CMwNod::MwAddRef(this_00);
              }
              if (*ppCVar5 != (CMwNod *)0x0) {
                CMwNod::MwRelease(*ppCVar5);
              }
              *ppCVar5 = this_00;
            }
          }
        } else {
          ppCVar5 = (CMwNod **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)this_02, uVar7);
          param_1 = (CClassicArchive *)*ppCVar5;
          (**(code **)(*(int *)this_01 + 4))(&param_1);
          pCVar1 = param_1;
          if (param_1 != (CClassicArchive *)*ppCVar5) {
            if (param_1 != (CClassicArchive *)0x0) {
              CMwNod::MwAddRef((CMwNod *)param_1);
            }
            if (*ppCVar5 != (CMwNod *)0x0) {
              CMwNod::MwRelease(*ppCVar5);
            }
            *ppCVar5 = (CMwNod *)pCVar1;
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar2);
    }
  } else if (param_2 != 0xffffffff) {
    CMwNod::Chunk((CMwNod *)this, param_1, param_2);
    return;
  }
  return;
}

/* public: static int __cdecl CPlugSurface::ComputeCollision(struct
   SPlugSurfaceLocatedPair const
   &,struct CGmCollisionBuffer &) */

int __cdecl CPlugSurface::ComputeCollision(SPlugSurfaceLocatedPair *param_1,
                                           CGmCollisionBuffer *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;

  uVar1 = (**(code **)(*(int *)param_2 + 8))();
  uStack_18 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x14) + 0x34);
  uStack_14 = *(undefined4 *)(param_1 + 0xc);
  uStack_10 = 1;
  uStack_c = *(undefined4 *)(*(int *)(*(int *)param_1 + 0x14) + 0x34);
  uStack_8 = *(undefined4 *)(param_1 + 4);
  uStack_4 = 1;
  iVar2 = GmSurf::ComputeCollision((LocatedGmSurf *)&uStack_c,
                                   (LocatedGmSurf *)&uStack_18, param_2);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = (**(code **)(*(int *)param_2 + 8))();
  for (; uVar1 < uVar3; uVar1 = uVar1 + 1) {
    iVar2 = (**(code **)(*(int *)param_2 + 4))(uVar1);
    piVar4 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)param_1 + 0x18),
        (uint) * (ushort *)(iVar2 + 0x24));
    *(ushort *)(iVar2 + 0x24) = (ushort) * (byte *)(*piVar4 + 0x18);
    piVar4 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(param_1 + 8) + 0x18),
        (uint) * (ushort *)(iVar2 + 0x26));
    *(ushort *)(iVar2 + 0x26) = (ushort) * (byte *)(*piVar4 + 0x18);
  }
  return 1;
}

/* public: __thiscall CPlugSurface::CPlugSurface(void) */

CPlugSurface *__thiscall CPlugSurface::CPlugSurface(CPlugSurface *this)

{
  CPlug::CPlug((CPlug *)this);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x18));
  return this;
}

/* public: virtual unsigned long __thiscall CPlugSurface::GetChunkInfo(unsigned
 * long)const  */

ulong __thiscall CPlugSurface::GetChunkInfo(CPlugSurface *this, ulong param_1)

{
  ulong uVar1;

  if (param_1 == 0x900c000) {
    return 3;
  }
  if (param_1 != 0xffffffff) {
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this, param_1);
    return uVar1;
  }
  return 0xffffffff;
}

/* public: virtual unsigned long __thiscall
 * CPlugSurface::GetMwClassId(void)const  */

ulong __thiscall CPlugSurface::GetMwClassId(CPlugSurface *this)

{
  return 0x900c000;
}

/* public: virtual unsigned long __thiscall
 * CPlugSurface::GetUidChunkFromIndex(unsigned long)const
 */

ulong __thiscall CPlugSurface::GetUidChunkFromIndex(CPlugSurface *this,
                                                    ulong param_1)

{
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0x900c000;
}

/* public: virtual class CMwClassInfo const * __thiscall
 * CPlugSurface::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CPlugSurface::MwGetClassInfo(CPlugSurface *this)

{
  return &m_MwClassInfo_CPlugSurface;
}

/* public: virtual int __thiscall CPlugSurface::MwIsKindOf(unsigned long)const
 */

int __thiscall CPlugSurface::MwIsKindOf(CPlugSurface *this, ulong param_1)

{
  if ((param_1 != 0x900c000) && (param_1 != 0x902b000)) {
    return (uint)(param_1 == 0x1001000);
  }
  return 1;
}

/* public: static class CMwNod * __cdecl CPlugSurface::MwNewCPlugSurface(void)
 */

CMwNod *__cdecl CPlugSurface::MwNewCPlugSurface(void)

{
  CPlugSurface *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00adb9bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CPlugSurface *)operator_new(0x24);
  local_4 = 0;
  if (this != (CPlugSurface *)0x0) {
    pCVar1 = (CMwNod *)CPlugSurface(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: static void __cdecl CPlugSurface::StaticInit(void) */

void __cdecl CPlugSurface::StaticInit(void)

{
  uint uVar1;
  CPlugMaterial *this;
  CMwNod **ppCVar2;
  uint uVar3;
  CMwNod *this_00;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00adb98b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  GmSurf::StaticInit();
  uVar3 = 0;
  do {
    uVar1 = uVar3 + 8;
    *(undefined4 *)((int)&DAT_00d6eec4 + uVar3) = 0x3f000000;
    *(undefined4 *)(&s_PlugSurfaceMaterialDatas + uVar3) = 0x3f800000;
    uVar3 = uVar1;
  } while (uVar1 < 0xf8);
  _DAT_00d6eedc = 0;
  _DAT_00d6eed8 = 0;
  _DAT_00d6ef14 = 0xbf000000;
  _DAT_00d6ef10 = 0;
  _DAT_00d6ef0c = 0;
  _DAT_00d6ef08 = 0;
  _DAT_00d6ef1c = 0;
  _DAT_00d6ef18 = 0;
  _DAT_00d6ef7c = 0x3f733333;
  _DAT_00d6ef78 = 0x3f800000;
  _DAT_00d6ef84 = 0x3f4ccccd;
  _DAT_00d6ef8c = 0x3f4ccccd;
  _DAT_00d6ef80 = 0x3f800000;
  _DAT_00d6ef88 = 0x3f800000;
  CFastBufferRef<>::Reset(&s_DefaultSurfaceMaterials);
  uVar3 = 0;
  do {
    this = (CPlugMaterial *)operator_new(0x38);
    this_00 = (CMwNod *)0x0;
    local_4 = 0;
    if (this != (CPlugMaterial *)0x0) {
      this_00 = (CMwNod *)CPlugMaterial::CPlugMaterial(this);
    }
    local_4 = 0xffffffff;
    ppCVar2 = (CMwNod **)CFastBuffer<>::AddNewElem(
        (CFastBuffer<> *)&s_DefaultSurfaceMaterials);
    if (this_00 != *ppCVar2) {
      if (this_00 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(this_00);
      }
      if (*ppCVar2 != (CMwNod *)0x0) {
        CMwNod::MwRelease(*ppCVar2);
      }
      *ppCVar2 = this_00;
    }
    this_00[0x18] = SUB41(uVar3, 0);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x1f);
  ExceptionList = local_c;
  return;
}

/* public: static void __cdecl CPlugSurface::StaticRelease(void) */

void __cdecl CPlugSurface::StaticRelease(void)

{
  CFastBuffer<>::ResetAndFreeMemory(
      (CFastBuffer<> *)&s_DefaultSurfaceMaterials);
  return;
}

/* public: virtual __thiscall CPlugSurface::~CPlugSurface(void) */

void __thiscall CPlugSurface::~CPlugSurface(CPlugSurface *this)

{
  void *local_c;
  undefined *puStack_8;
  uint local_4;

  puStack_8 = &LAB_00adb963;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x18));
  local_4 = local_4 & 0xffffff00;
  if (*(CMwNod **)(this + 0x14) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x14));
  }
  local_4 = 0xffffffff;
  CPlug::~CPlug((CPlug *)this);
  ExceptionList = local_c;
  return;
}
