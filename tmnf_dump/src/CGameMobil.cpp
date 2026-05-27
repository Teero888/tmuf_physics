// Class implementation: CGameMobil

// =================================================
// Function: CGameMobil::CGameMobil
// =================================================
void __thiscall CGameMobil::CGameMobil(CGameMobil *this,CGameMobil *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined **)(this + 0x28) = PTR_DAT_00bbf7dc;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x18) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 0xffffffff;
  *(undefined4 *)(this + 0x20) = 1;
  return;
}
}

// =================================================
// Function: CGameMobil::GetMwClassId
// =================================================
ulong __thiscall CGameMobil::GetMwClassId(CGameMobil *this,CControlStyle *param_1)
{
{
  return 0x3007000;
}
}

// =================================================
// Function: CGameMobil::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CGameMobil::MwGetClassInfo(CGameMobil *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d69d88;
}
}

// =================================================
// Function: CGameMobil::MwIsKindOf
// =================================================
int __thiscall CGameMobil::MwIsKindOf(CGameMobil *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0x3007000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CGameMobil::MwNewCGameMobil
// =================================================
CMwNod * __cdecl CGameMobil::MwNewCGameMobil(void)
{
{
  CGameMobil *pCVar1;
  CMwNod *extraout_EAX;
  CGameMobil *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ab1d0b;
  local_c = ExceptionList;
  pCVar1 = (CGameMobil *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x38);
  local_4 = 0;
  if (local_10 != (CGameMobil *)0x0) {
    CGameMobil(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CGameMobil::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CGameMobil::_scalar_deleting_destructor_(CGameMobil *this,CPfmHeap *param_1,uint param_2)
{
{
  CGameMobil *unaff_ESI;
  
  ~CGameMobil(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CGameMobil::~CGameMobil
// =================================================
void __thiscall CGameMobil::~CGameMobil(CGameMobil *this,CGameMobil *param_1)
{
{
  CMwNod *pCVar1;
  undefined *puVar2;
  CMwNod *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00ab1cde;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = (void *)0x2;
  if (*(CMwNod **)(this + 0x2c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x2c),pCVar1);
  }
  puVar2 = *(undefined **)(this + 0x28);
  if (puVar2 != PTR_DAT_00bbf7dc) {
    if ((puVar2[-1] & 0x80) == 0) {
      puVar2 = puVar2 + -2;
    }
    else {
      puVar2 = puVar2 + -4;
    }
    operator_delete__(puVar2);
    *(undefined4 *)(this + 0x24) = 0;
    *(undefined **)(this + 0x28) = PTR_DAT_00bbf7dc;
  }
  if (*(CMwNod **)(this + 0x14) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x14),unaff_ESI);
  }
  CMwNod::~CMwNod((CMwNod *)this,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

