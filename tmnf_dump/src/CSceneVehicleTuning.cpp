// Class implementation: CSceneVehicleTuning

// =================================================
// Function: CSceneVehicleTuning::CSceneVehicleTuning
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleTuning::CSceneVehicleTuning(CSceneVehicleTuning *this,CSceneVehicleTuning *param_1)
{
{
  undefined4 uVar1;
  CMwNod *unaff_ESI;
  void *unaff_retaddr;
  CSceneVehicleTuning *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad3c28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar2 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec),unaff_ESI);
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x14,(CMwId *)pCVar2);
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x18) = 0x3f800000;
  uVar1 = _DAT_00b9f20c;
  *(undefined4 *)(this + 0x1c) = _DAT_00b9f20c;
  *(undefined4 *)(this + 0x20) = uVar1;
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CSceneVehicleTuning::Chunk
// =================================================
void __thiscall
CSceneVehicleTuning::Chunk
          (CSceneVehicleTuning *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CSceneVehicleTuning *this_00;
  char cVar1;
  int extraout_EAX;
  char *extraout_EAX_00;
  char *pcVar2;
  CClassicArchive *extraout_EAX_01;
  CFastString *unaff_EBX;
  CMwStatsValue *unaff_EBP;
  CMwStatsValue *unaff_ESI;
  CClassicArchive *unaff_EDI;
  CFastString *unaff_retaddr;
  CMwNod *pCVar3;
  
  if (param_2 == (CClassicArchive *)0xa02e000) {
    this_00 = this + 0x14;
    CMwId::Archive(this_00,(CFastCrypt<unsigned_long> *)param_1,unaff_EDI);
    param_2 = *(CClassicArchive **)(this + 0x24);
    pCVar3 = (CMwNod *)&param_2;
    (**(code **)(*(int *)param_1 + 4))();
    if (param_1 != *(CFuncSegment **)(this + 0x24)) {
      if (param_1 != (CFuncSegment *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_1,pCVar3);
      }
      if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x24),pCVar3);
      }
      *(CFuncSegment **)(this + 0x24) = param_1;
    }
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x28),(float *)0x1,
               (ulong)pCVar3);
    CMwId::GetString(this_00,unaff_EBP,unaff_EBX);
    if (extraout_EAX != 0) {
      CMwId::GetString(this_00,unaff_ESI,unaff_retaddr);
      pcVar2 = extraout_EAX_00;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if (3 < (uint)((int)pcVar2 - (int)(extraout_EAX_00 + 1))) {
        *(undefined4 *)(*(int *)(param_1 + 4) + 8) = 1;
        CMwId::GetString(this_00,(CMwStatsValue *)&DAT_00000004,(CFastString *)0x0);
        CClassicArchive::WriteNat8
                  ((CClassicArchive *)param_1,extraout_EAX_01,(uchar *)param_1,(ulong)param_2,
                   param_3);
        *(undefined4 *)(*(int *)(param_1 + 4) + 8) = 0;
      }
    }
  }
  else if (param_2 != (CClassicArchive *)0xffffffff) {
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,(ulong)unaff_ESI);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleTuning::CreateDefaultData
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneVehicleTuning::CreateDefaultData(CSceneVehicleTuning *this,CCrystal *param_1)
{
{
  CFastStringInt *pCVar1;
  CFuncKeysReal *this_00;
  CMwNod *extraout_EAX;
  float unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *this_01;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad3c8b;
  local_c = ExceptionList;
  pCVar1 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  this_00 = operator_new(0x2c);
  local_4 = 0;
  if (this_00 == (CFuncKeysReal *)0x0) {
    this_01 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(this_00,(CFuncKeysReal *)pCVar1);
    this_01 = extraout_EAX;
  }
  if (this_01 != *(CMwNod **)(this + 0x24)) {
    if (this_01 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_01,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x24),unaff_EDI);
    }
    *(CMwNod **)(this + 0x24) = this_01;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x24),(CFuncKeysReal *)0x0,0.0,(float)unaff_EDI);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x24),_DAT_00b36198,0.0,unaff_ESI);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x24),_DAT_00b36adc,1.0,(float)this_00);
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CSceneVehicleTuning::GetChunkInfo
// =================================================
ulong __thiscall
CSceneVehicleTuning::GetChunkInfo(CSceneVehicleTuning *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 == (CFuncSegment *)0xa02e000) {
    return 3;
  }
  if (param_1 != (CFuncSegment *)0xffffffff) {
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
    return uVar1;
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CSceneVehicleTuning::GetMwClassId
// =================================================
ulong __thiscall CSceneVehicleTuning::GetMwClassId(CSceneVehicleTuning *this,CControlStyle *param_1)
{
{
  return 0xa02e000;
}
}

// =================================================
// Function: CSceneVehicleTuning::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CSceneVehicleTuning::GetUidChunkFromIndex
          (CSceneVehicleTuning *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0xa02e000;
}
}

// =================================================
// Function: CSceneVehicleTuning::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall
CSceneVehicleTuning::MwGetClassInfo(CSceneVehicleTuning *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6e294;
}
}

// =================================================
// Function: CSceneVehicleTuning::MwIsKindOf
// =================================================
int __thiscall
CSceneVehicleTuning::MwIsKindOf(CSceneVehicleTuning *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0xa02e000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CSceneVehicleTuning::_vector_deleting_destructor_
// =================================================
void * __thiscall
CSceneVehicleTuning::_vector_deleting_destructor_
          (CSceneVehicleTuning *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CSceneVehicleTuning *unaff_ESI;
  
  ~CSceneVehicleTuning(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CSceneVehicleTuning::~CSceneVehicleTuning
// =================================================
void __thiscall
CSceneVehicleTuning::~CSceneVehicleTuning(CSceneVehicleTuning *this,CSceneVehicleTuning *param_1)
{
{
  CMwNod *pCVar1;
  CFastStringInt *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00ad3c63;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = (void *)0x1;
  if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x24),pCVar1);
  }
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  CMwNod::~CMwNod((CMwNod *)this,(CMwNod *)unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

