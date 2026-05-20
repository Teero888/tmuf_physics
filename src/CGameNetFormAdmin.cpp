// Class implementation: CGameNetFormAdmin

// =================================================
// Function: CGameNetFormAdmin::CGameNetFormAdmin
// =================================================
void __thiscall
CGameNetFormAdmin::CGameNetFormAdmin
          (CGameNetFormAdmin *this,CGameNetFormAdmin *param_1,EMessageType param_2)
{
{
  CClassicBufferMemory *this_00;
  ulong unaff_ESI;
  CClassicBufferMemory *unaff_EDI;
  undefined4 in_stack_00000014;
  CGameNetFormAdmin *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00abe843;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CNetNod::CNetNod((CNetNod *)this,(CNetNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  this_00 = (CClassicBufferMemory *)(this + 0x20);
  *(undefined ***)this = vftable;
  CClassicBufferMemory::CClassicBufferMemory(this_00,unaff_EDI);
  param_1 = (CGameNetFormAdmin *)CONCAT31(param_1._1_3_,1);
  CClassicBufferMemory::PreAlloc(this_00,(CClassicBufferMemory *)&DAT_00000080,unaff_ESI);
  CClassicBufferMemory::Empty(this_00,(CClassicBufferMemory *)pCVar1);
  *(undefined4 *)(this + 0x1c) = in_stack_00000014;
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CGameNetFormAdmin::~CGameNetFormAdmin
// =================================================
void __thiscall
CGameNetFormAdmin::~CGameNetFormAdmin(CGameNetFormAdmin *this,CGameNetFormAdmin *param_1)
{
{
  CClassicBufferMemory *pCVar1;
  CNetNod *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00abe868;
  local_c = ExceptionList;
  pCVar1 = (CClassicBufferMemory *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = (void *)0x0;
  CClassicBufferMemory::~CClassicBufferMemory((CClassicBufferMemory *)(this + 0x20),pCVar1);
  CNetNod::~CNetNod((CNetNod *)this,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

