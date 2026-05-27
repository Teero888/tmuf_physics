// Class implementation: CHmsForceField

// =================================================
// Function: CHmsForceField::CHmsForceField
// =================================================
void __thiscall CHmsForceField::CHmsForceField(CHmsForceField *this,CHmsForceField *param_1)
{
{
  CHmsPoc *unaff_ESI;
  
  CHmsPoc::CHmsPoc((CHmsPoc *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x58) = 0;
  return;
}
}

// =================================================
// Function: CHmsForceField::GetMwClassId
// =================================================
ulong __thiscall CHmsForceField::GetMwClassId(CHmsForceField *this,CControlStyle *param_1)
{
{
  return 0x6014000;
}
}

// =================================================
// Function: CHmsForceField::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CHmsForceField::MwGetClassInfo(CHmsForceField *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d67a08;
}
}

// =================================================
// Function: CHmsForceField::MwIsKindOf
// =================================================
int __thiscall
CHmsForceField::MwIsKindOf(CHmsForceField *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (((param_1 != (CMwCmdAffectParam *)0x6014000) && (param_1 != (CMwCmdAffectParam *)0x6007000))
     && (param_1 != (CMwCmdAffectParam *)0x6008000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CHmsForceField::MwNewCHmsForceField
// =================================================
CMwNod * __cdecl CHmsForceField::MwNewCHmsForceField(void)
{
{
  CHmsForceField *pCVar1;
  CMwNod *extraout_EAX;
  CHmsForceField *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9783b;
  local_c = ExceptionList;
  pCVar1 = (CHmsForceField *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x5c);
  local_4 = 0;
  if (local_10 != (CHmsForceField *)0x0) {
    CHmsForceField(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CHmsForceField::SetZone
// =================================================
void __thiscall
CHmsForceField::SetZone(CHmsForceField *this,CSceneSector *param_1,CHmsZone *param_2)
{
{
  CHmsForceField *unaff_ESI;
  CHmsForceField *unaff_retaddr;
  
  if (*(CHmsZone **)(this + 0x14) != (CHmsZone *)0x0) {
    CHmsZone::RemoveField(*(CHmsZone **)(this + 0x14),(CHmsZone *)this,unaff_ESI);
  }
  *(CHmsZone **)(this + 0x14) = param_2;
  if (param_2 != (CHmsZone *)0x0) {
    CHmsZone::AddField(param_2,(CHmsZone *)this,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CHmsForceField::_vector_deleting_destructor_
// =================================================
void * __thiscall
CHmsForceField::_vector_deleting_destructor_
          (CHmsForceField *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CHmsForceField *unaff_ESI;
  
  ~CHmsForceField(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CHmsForceField::~CHmsForceField
// =================================================
void __thiscall CHmsForceField::~CHmsForceField(CHmsForceField *this,CHmsForceField *param_1)
{
{
  CHmsForceField *pCVar1;
  CHmsPoc *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00a97808;
  local_c = ExceptionList;
  pCVar1 = (CHmsForceField *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = (void *)0x0;
  if (*(CHmsZone **)(this + 0x14) != (CHmsZone *)0x0) {
    CHmsZone::RemoveField(*(CHmsZone **)(this + 0x14),(CHmsZone *)this,pCVar1);
  }
  CHmsPoc::~CHmsPoc((CHmsPoc *)this,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

