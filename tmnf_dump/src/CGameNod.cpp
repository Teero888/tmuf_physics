// Class implementation: CGameNod

// =================================================
// Function: CGameNod::CGameNod
// =================================================
void __thiscall CGameNod::CGameNod(CGameNod *this,CGameNod *param_1)
{
{
  CMwNod *unaff_ESI;
  void *unaff_retaddr;
  CGameNod *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00abf208;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec),unaff_ESI);
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x14,(CMwId *)pCVar1);
  *(undefined4 *)(this + 0x18) = 0;
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CGameNod::Chunk
// =================================================
void __thiscall
CGameNod::Chunk(CGameNod *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CClassicArchive *unaff_retaddr;
  
  if (param_2 == (CClassicArchive *)0x3008000) {
    CMwId::Archive(this + 0x14,(CFastCrypt<unsigned_long> *)param_1,unaff_retaddr);
  }
  else if (param_2 != (CClassicArchive *)0xffffffff) {
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,param_3);
    return;
  }
  return;
}
}

// =================================================
// Function: CGameNod::GetChunkInfo
// =================================================
ulong __thiscall CGameNod::GetChunkInfo(CGameNod *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 == (CFuncSegment *)0x3008000) {
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
// Function: CGameNod::~CGameNod
// =================================================
void __thiscall CGameNod::~CGameNod(CGameNod *this,CGameNod *param_1)
{
{
  CFastStringInt *pCVar1;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00abf238;
  local_c = ExceptionList;
  pCVar1 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  local_4 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this,(CMwNod *)pCVar1);
  ExceptionList = local_8;
  return;
}
}

