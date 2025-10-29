
/* public: virtual void * __thiscall CSceneVehicleTuning::`vector deleting
 * destructor'(unsigned int)
 */

void *__thiscall CSceneVehicleTuning::`vector_deleting_destructor'(CSceneVehicleTuning *this,uint param_1)

{
  ~CSceneVehicleTuning(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: virtual void __thiscall CSceneVehicleTuning::Chunk(class
 * CClassicArchive &,unsigned long)
 */

void __thiscall CSceneVehicleTuning::Chunk(CSceneVehicleTuning *this,
                                           CClassicArchive *param_1,
                                           ulong param_2)

{
  CMwId *this_00;
  char cVar1;
  CClassicArchive *this_01;
  char *pcVar2;
  char *pcVar3;
  uchar *puVar4;
  CMwNod *unaff_retaddr;
  ulong uVar5;
  int iVar6;

  this_01 = param_1;
  if (param_2 == 0xa02e000) {
    this_00 = (CMwId *)(this + 0x14);
    CMwId::Archive(this_00, param_1);
    param_1 = *(CClassicArchive **)(this + 0x24);
    (**(code **)(*(int *)this_01 + 4))(&param_1);
    if (unaff_retaddr != *(CMwNod **)(this + 0x24)) {
      if (unaff_retaddr != (CMwNod *)0x0) {
        CMwNod::MwAddRef(unaff_retaddr);
      }
      if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x24));
      }
      *(CMwNod **)(this + 0x24) = unaff_retaddr;
    }
    CClassicArchive::DoReal(this_01, (float *)(this + 0x28), 1);
    pcVar2 = CMwId::GetString(this_00);
    if (pcVar2 != (char *)0x0) {
      pcVar3 = CMwId::GetString(this_00);
      pcVar2 = pcVar3 + 1;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (3 < (uint)((int)pcVar3 - (int)pcVar2)) {
        iVar6 = 0;
        uVar5 = 4;
        *(undefined4 *)(*(int *)(this_01 + 4) + 8) = 1;
        puVar4 = (uchar *)CMwId::GetString(this_00);
        CClassicArchive::WriteNat8(this_01, puVar4, uVar5, iVar6);
        *(undefined4 *)(*(int *)(this_01 + 4) + 8) = 0;
      }
    }
  } else if (param_2 != 0xffffffff) {
    CMwNod::Chunk((CMwNod *)this, param_1, param_2);
    return;
  }
  return;
}

/* public: virtual void __thiscall CSceneVehicleTuning::CreateDefaultData(void)
 */

void __thiscall CSceneVehicleTuning::CreateDefaultData(
    CSceneVehicleTuning *this)

{
  CFuncKeysReal *this_00;
  CMwNod *this_01;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad3c8b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CScene2d::OnNodLoaded((CScene2d *)this);
  this_00 = (CFuncKeysReal *)operator_new(0x2c);
  local_4 = 0;
  if (this_00 == (CFuncKeysReal *)0x0) {
    this_01 = (CMwNod *)0x0;
  } else {
    this_01 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(this_00);
  }
  local_4 = 0xffffffff;
  if (this_01 != *(CMwNod **)(this + 0x24)) {
    if (this_01 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_01);
    }
    if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x24));
    }
    *(CMwNod **)(this + 0x24) = this_01;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x24), 0.0, 0.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x24), 30.0, 0.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x24), 100.0, 1.0);
  ExceptionList = local_c;
  return;
}

/* public: __thiscall CSceneVehicleTuning::CSceneVehicleTuning(void) */

CSceneVehicleTuning *__thiscall CSceneVehicleTuning::CSceneVehicleTuning(
    CSceneVehicleTuning *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad3c28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwNod::CMwNod((CMwNod *)this);
  local_4 = 0;
  *(undefined ***)this = vftable;
  CMwId::CMwId((CMwId *)(this + 0x14));
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x18) = 0x3f800000;
  *(undefined4 *)(this + 0x1c) = 0x3f060a92;
  *(undefined4 *)(this + 0x20) = 0x3f060a92;
  ExceptionList = local_c;
  return this;
}

/* public: virtual unsigned long __thiscall
 * CSceneVehicleTuning::GetChunkInfo(unsigned long)const
 */

ulong __thiscall CSceneVehicleTuning::GetChunkInfo(CSceneVehicleTuning *this,
                                                   ulong param_1)

{
  ulong uVar1;

  if (param_1 == 0xa02e000) {
    return 3;
  }
  if (param_1 != 0xffffffff) {
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this, param_1);
    return uVar1;
  }
  return 0xffffffff;
}

/* public: virtual unsigned long __thiscall
 * CSceneVehicleTuning::GetMwClassId(void)const  */

ulong __thiscall CSceneVehicleTuning::GetMwClassId(CSceneVehicleTuning *this)

{
  return 0xa02e000;
}

/* public: virtual unsigned long __thiscall
   CSceneVehicleTuning::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CSceneVehicleTuning::GetUidChunkFromIndex(
    CSceneVehicleTuning *this, ulong param_1)

{
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0xa02e000;
}

/* public: virtual class CMwClassInfo const * __thiscall
   CSceneVehicleTuning::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CSceneVehicleTuning::MwGetClassInfo(
    CSceneVehicleTuning *this)

{
  return &m_MwClassInfo_CSceneVehicleTuning;
}

/* public: virtual int __thiscall CSceneVehicleTuning::MwIsKindOf(unsigned
 * long)const  */

int __thiscall CSceneVehicleTuning::MwIsKindOf(CSceneVehicleTuning *this,
                                               ulong param_1)

{
  if (param_1 == 0xa02e000) {
    return 1;
  }
  return (uint)(param_1 == 0x1001000);
}

/* public: virtual __thiscall CSceneVehicleTuning::~CSceneVehicleTuning(void) */

void __thiscall CSceneVehicleTuning::~CSceneVehicleTuning(
    CSceneVehicleTuning *this)

{
  void *local_c;
  undefined *puStack_8;
  uint local_4;

  puStack_8 = &LAB_00ad3c63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x24));
  }
  local_4 = local_4 & 0xffffff00;
  CScene2d::OnNodLoaded((CScene2d *)(this + 0x14));
  local_4 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this);
  ExceptionList = local_c;
  return;
}
