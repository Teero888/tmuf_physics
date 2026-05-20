// Class implementation: CSystemFidMemory

// =================================================
// Function: CSystemFidMemory::CSystemFidMemory
// =================================================
void __thiscall CSystemFidMemory::CSystemFidMemory(CSystemFidMemory *this,CSystemFidMemory *param_1)
{
{
  CSystemFid *unaff_ESI;
  
  CSystemFid::CSystemFid((CSystemFid *)this,unaff_ESI);
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x18) = 8;
  return;
}
}

// =================================================
// Function: CSystemFidMemory::~CSystemFidMemory
// =================================================
void __thiscall
CSystemFidMemory::~CSystemFidMemory(CSystemFidMemory *this,CSystemFidMemory *param_1)
{
{
  CSystemFid *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a826a8;
  local_c = ExceptionList;
  pCVar1 = (CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  if ((*(int *)(this + 0x78) != 0) && (*(undefined4 **)(this + 0x74) != (undefined4 *)0x0)) {
    (**(code **)**(undefined4 **)(this + 0x74))(1);
  }
  local_4 = 0xffffffff;
  CSystemFid::~CSystemFid((CSystemFid *)this,pCVar1);
  ExceptionList = puStack_8;
  return;
}
}

