
/* public: virtual void * __thiscall CHmsCorpus::`vector deleting
 * destructor'(unsigned int) */

void *__thiscall CHmsCorpus::`vector_deleting_destructor'(CHmsCorpus *this,uint param_1)

{
  ~CHmsCorpus(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: __thiscall CHmsCorpus::CHmsCorpus(void) */

CHmsCorpus *__thiscall CHmsCorpus::CHmsCorpus(CHmsCorpus *this)

{
  CHmsZoneElem::CHmsZoneElem((CHmsZoneElem *)this);
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x54) = 0xffffffff;
  return this;
}

/* public: void __thiscall CHmsCorpus::ComputeCurrentState(float) */

void __thiscall CHmsCorpus::ComputeCurrentState(CHmsCorpus *this, float param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_30[12];

  iVar1 = *(int *)(this + 0x58);
  if (iVar1 != 0) {
    GmIso4::SetBlend((GmIso4 *)local_30,
                     (GmIso4 *)(*(int *)(iVar1 + 0x328) + 0x10),
                     (GmIso4 *)(*(int *)(iVar1 + 0x32c) + 0x10), param_1);
    puVar2 = local_30;
    puVar3 = (undefined4 *)(this + 0x18);
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}

/* public: virtual class GmIso4 const * __thiscall
 * CHmsCorpus::GetLocation(void)const  */

GmIso4 *__thiscall CHmsCorpus::GetLocation(CHmsCorpus *this)

{
  if (*(int *)(this + 0x58) != 0) {
    return (GmIso4 *)(*(int *)(*(int *)(this + 0x58) + 0x328) + 0x10);
  }
  return (GmIso4 *)(this + 0x18);
}

/* public: virtual unsigned long __thiscall CHmsCorpus::GetMwClassId(void)const
 */

ulong __thiscall CHmsCorpus::GetMwClassId(CHmsCorpus *this)

{
  return 0x6002000;
}

/* public: virtual class CMwClassInfo const * __thiscall
 * CHmsCorpus::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CHmsCorpus::MwGetClassInfo(CHmsCorpus *this)

{
  return &m_MwClassInfo_CHmsCorpus;
}

/* public: virtual int __thiscall CHmsCorpus::MwIsKindOf(unsigned long)const  */

int __thiscall CHmsCorpus::MwIsKindOf(CHmsCorpus *this, ulong param_1)

{
  if ((param_1 != 0x6002000) && (param_1 != 0x6008000)) {
    return (uint)(param_1 == 0x1001000);
  }
  return 1;
}

/* public: static class CMwNod * __cdecl CHmsCorpus::MwNewCHmsCorpus(void) */

CMwNod *__cdecl CHmsCorpus::MwNewCHmsCorpus(void)

{
  CHmsCorpus *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9615b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CHmsCorpus *)operator_new(0x5c);
  local_4 = 0;
  if (this != (CHmsCorpus *)0x0) {
    pCVar1 = (CMwNod *)CHmsCorpus(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: void __thiscall CHmsCorpus::OldRestoreStaticState(class
   CClassicBufferMemory
   &,int,unsigned char,int) */

void __thiscall CHmsCorpus::OldRestoreStaticState(CHmsCorpus *this,
                                                  CClassicBufferMemory *param_1,
                                                  int param_2, uchar param_3,
                                                  int param_4)

{
  if (*(CHmsDyna **)(this + 0x58) != (CHmsDyna *)0x0) {
    CHmsDyna::OldRestoreStaticState(*(CHmsDyna **)(this + 0x58), param_1,
                                    param_2, param_3);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: virtual int __thiscall CHmsCorpus::OnCrashDump(class CFastString &)
 */

int __thiscall CHmsCorpus::OnCrashDump(CHmsCorpus *this, CFastString *param_1)

{
  int *piVar1;
  int iVar2;
  CFastString *this_00;
  CFastString *pCVar3;

  iVar2 = CMwNod::OnCrashDump((CMwNod *)this, param_1);
  if (iVar2 == 0) {
    return 0;
  }
  (**(code **)(_s_SystemCrashDump + 0x14))();
  iVar2 = (**(code **)(*(int *)this + 0x78))();
  pCVar3 = param_1;
  this_00 = (CFastString *)(**(code **)(_s_SystemCrashDump + 0x1c))(
      param_1, "Translation=");
  CFastString::operator<<(this_00, (char *)pCVar3);
  CSystemCrashDump::StringCatVec3(&CSystemCrashDump::s_SystemCrashDump, param_1,
                                  (GmVec3 *)(iVar2 + 0x24));
  piVar1 = *(int **)(this + 0x48);
  iVar2 = CSystemCrashDump::IsValid_DumpFidAndMwId(
      &CSystemCrashDump::s_SystemCrashDump, param_1, "HmsItem",
      (CMwNod *)piVar1, 1);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x58))(param_1);
  }
  (**(code **)(_s_SystemCrashDump + 0x18))();
  return 1;
}

/* public: void __thiscall CHmsCorpus::RefreshFromSolid(void) */

void __thiscall CHmsCorpus::RefreshFromSolid(CHmsCorpus *this)

{
  if (*(int *)(this + 0x58) != 0) {
    *(int *)(*(int *)(this + 0x58) + 0x108) =
        *(int *)(*(int *)(this + 0x48) + 0x14) + 0x18;
  }
  return;
}

/* public: void __thiscall CHmsCorpus::Reset(void) */

void __thiscall CHmsCorpus::Reset(CHmsCorpus *this)

{
  if (*(CHmsDyna **)(this + 0x58) != (CHmsDyna *)0x0) {
    CHmsDyna::Reset(*(CHmsDyna **)(this + 0x58));
    return;
  }
  return;
}

/* public: void __thiscall CHmsCorpus::RestoreStaticState(class
   CClassicBufferMemory &,int,enum CHmsItem::ESaveStateVersion) */

void __thiscall CHmsCorpus::RestoreStaticState(CHmsCorpus *this,
                                               CClassicBufferMemory *param_1,
                                               int param_2,
                                               ESaveStateVersion param_3)

{
  if (*(CHmsDyna **)(this + 0x58) != (CHmsDyna *)0x0) {
    CHmsDyna::RestoreStaticState(*(CHmsDyna **)(this + 0x58), param_1, param_2,
                                 (uchar)param_3);
    return;
  }
  return;
}

/* public: void __thiscall CHmsCorpus::RotateOf(class GmMat3 const &) */

void __thiscall CHmsCorpus::RotateOf(CHmsCorpus *this, GmMat3 *param_1)

{
  GmMat3 *pGVar1;
  GmMat3 local_30[36];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;

  if (*(CHmsDyna **)(this + 0x58) != (CHmsDyna *)0x0) {
    CHmsDyna::RotateOf(*(CHmsDyna **)(this + 0x58), param_1);
    return;
  }
  GmMat3::Set(local_30, param_1);
  pGVar1 = (GmMat3 *)(**(code **)(*(int *)this + 0x78))();
  uStack_c = *(undefined4 *)(pGVar1 + 0x24);
  uStack_8 = *(undefined4 *)(pGVar1 + 0x28);
  uStack_4 = *(undefined4 *)(pGVar1 + 0x2c);
  GmMat3::Mult(local_30, pGVar1);
  GmMat3::OrthoNormalize(local_30);
  SetLocation(this, (GmIso4 *)local_30);
  return;
}

/* public: void __thiscall CHmsCorpus::SetItem(class CHmsItem *) */

void __thiscall CHmsCorpus::SetItem(CHmsCorpus *this, CHmsItem *param_1)

{
  CHmsDyna *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9618b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = *(CHmsDyna **)(this + 0x58);
  *(CHmsItem **)(this + 0x48) = param_1;
  if (pCVar1 != (CHmsDyna *)0x0) {
    CHmsDyna::~CHmsDyna(pCVar1);
    operator_delete(pCVar1);
  }
  *(undefined4 *)(this + 0x58) = 0;
  if ((*(uint *)(param_1 + 0x18) >> 0xb & 3) != 0) {
    pCVar1 = (CHmsDyna *)operator_new(0x590);
    local_4 = 0;
    if (pCVar1 == (CHmsDyna *)0x0) {
      pCVar1 = (CHmsDyna *)0x0;
    } else {
      pCVar1 = (CHmsDyna *)CHmsDyna::CHmsDyna(pCVar1);
    }
    *(CHmsDyna **)(this + 0x58) = pCVar1;
    local_4 = 0xffffffff;
    CHmsDyna::SetDynamicType(pCVar1, (*(uint *)(param_1 + 0x18) >> 0xb & 3) +
                                         0xffffffff);
  }
  RefreshFromSolid(this);
  ExceptionList = local_c;
  return;
}

/* public: void __thiscall CHmsCorpus::SetLocation(class GmIso4 const &) */

void __thiscall CHmsCorpus::SetLocation(CHmsCorpus *this, GmIso4 *param_1)

{
  CHmsDyna *this_00;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  this_00 = *(CHmsDyna **)(this + 0x58);
  puVar2 = (undefined4 *)param_1;
  puVar3 = (undefined4 *)(this + 0x18);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (this_00 != (CHmsDyna *)0x0) {
    CHmsDyna::SetLocation(this_00, param_1);
    return;
  }
  return;
}

/* public: void __thiscall CHmsCorpus::SetTranslation(class GmVec3 const &) */

void __thiscall CHmsCorpus::SetTranslation(CHmsCorpus *this, GmVec3 *param_1)

{
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 8);
  if (*(CHmsDyna **)(this + 0x58) != (CHmsDyna *)0x0) {
    CHmsDyna::SetTranslation(*(CHmsDyna **)(this + 0x58), param_1);
    return;
  }
  return;
}

/* public: int __thiscall CHmsCorpus::WaterGetPlaneEqInZone(class GmVec4 &) */

int __thiscall CHmsCorpus::WaterGetPlaneEqInZone(CHmsCorpus *this,
                                                 GmVec4 *param_1)

{
  CPlugShader *this_00;
  CPlugBitmapRender *pCVar1;
  GmIso4 *pGVar2;
  CPlugTree *local_60[2];
  float fStack_58;
  CIteratorShader local_50[12];
  int local_44;
  GmIso4 local_3c[48];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a961b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(*(int *)(this + 0x48) + 0x14) != 0) {
    CPlugTree::CIteratorShader::CIteratorShader(
        local_50, *(CPlugTree **)(*(int *)(*(int *)(this + 0x48) + 0x14) + 100),
        0);
    local_4 = 0;
    while (local_44 != 0) {
      this_00 = CPlugTree::CIteratorShader::GetNextShader(local_50, local_60);
      if ((*(uint *)(this_00 + 0x20) & 0xc00000) == 0x800000) {
        pCVar1 = CPlugShader::FindBitmapRenderByClassId(
            this_00, 0x9087000, (CPlugBitmap **)0x0,
            (CPlugBitmapAddress **)0x0);
        if (pCVar1 != (CPlugBitmapRender *)0x0) {
          CPlugTree::GetThisToRootTransfo(local_60[0], local_3c, 1,
                                          (CPlugTree *)0x0);
          pGVar2 = (GmIso4 *)(**(code **)(*(int *)this + 0x78))();
          GmIso4::Mult(local_3c, pGVar2);
          fStack_58 = *(float *)(*(int *)(local_60[0] + 0x90) + 0x38);
          *(undefined4 *)param_1 = 0;
          *(undefined4 *)(param_1 + 4) = 0x3f800000;
          *(undefined4 *)(param_1 + 8) = 0;
          *(float *)(param_1 + 0xc) = (-0.0 - fStack_58) - 0.0;
          GmVec4::PlaneEqMult(param_1, local_3c);
          CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_50);
          ExceptionList = local_c;
          return 1;
        }
      }
    }
    CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_50);
  }
  ExceptionList = local_c;
  return 0;
}
