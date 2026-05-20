// Class implementation: CHmsForceFieldUniform

// =================================================
// Function: CHmsForceFieldUniform::CHmsForceFieldUniform
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsForceFieldUniform::CHmsForceFieldUniform
          (CHmsForceFieldUniform *this,CHmsForceFieldUniform *param_1)
{
{
  CHmsForceField *unaff_ESI;
  
  CHmsForceField::CHmsForceField((CHmsForceField *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = _DAT_00b59790;
  *(undefined4 *)(this + 100) = 0;
  return;
}
}

// =================================================
// Function: CHmsForceFieldUniform::Chunk
// =================================================
void __thiscall
CHmsForceFieldUniform::Chunk
          (CHmsForceFieldUniform *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  if (param_2 == (CClassicArchive *)0x6016000) {
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x5c),(float *)0x1,unaff_EDI);
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x60),(float *)0x1,unaff_ESI);
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 100),(float *)0x1,unaff_retaddr
              );
  }
  else if (param_2 != (CClassicArchive *)0xffffffff) {
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,param_3);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsForceFieldUniform::GetChunkInfo
// =================================================
ulong __thiscall
CHmsForceFieldUniform::GetChunkInfo(CHmsForceFieldUniform *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 == (CFuncSegment *)0x6016000) {
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
// Function: CHmsForceFieldUniform::GetMwClassId
// =================================================
ulong __thiscall
CHmsForceFieldUniform::GetMwClassId(CHmsForceFieldUniform *this,CControlStyle *param_1)
{
{
  return 0x6016000;
}
}

// =================================================
// Function: CHmsForceFieldUniform::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CHmsForceFieldUniform::GetUidChunkFromIndex
          (CHmsForceFieldUniform *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x6016000;
}
}

// =================================================
// Function: CHmsForceFieldUniform::GetValue
// =================================================
GmVec3 __thiscall
CHmsForceFieldUniform::GetValue
          (CHmsForceFieldUniform *this,CFuncColorGradient *param_1,float param_2)
{
{
  if (*(int *)(this + 0x54) == 0) {
    return (GmVec3)0x0;
  }
  *(undefined4 *)param_2 = *(undefined4 *)(this + 0x5c);
  *(undefined4 *)((int)param_2 + 4) = *(undefined4 *)(this + 0x60);
  *(undefined4 *)((int)param_2 + 8) = *(undefined4 *)(this + 100);
  return (GmVec3)0x1;
}
}

// =================================================
// Function: CHmsForceFieldUniform::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall
CHmsForceFieldUniform::MwGetClassInfo(CHmsForceFieldUniform *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d67ae4;
}
}

// =================================================
// Function: CHmsForceFieldUniform::MwIsKindOf
// =================================================
int __thiscall
CHmsForceFieldUniform::MwIsKindOf
          (CHmsForceFieldUniform *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((((param_1 != (CMwCmdAffectParam *)0x6016000) && (param_1 != (CMwCmdAffectParam *)0x6014000))
      && (param_1 != (CMwCmdAffectParam *)0x6007000)) && (param_1 != (CMwCmdAffectParam *)0x6008000)
     ) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CHmsForceFieldUniform::MwNewCHmsForceFieldUniform
// =================================================
CMwNod * __cdecl CHmsForceFieldUniform::MwNewCHmsForceFieldUniform(void)
{
{
  CHmsForceFieldUniform *pCVar1;
  CMwNod *extraout_EAX;
  CHmsForceFieldUniform *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9792b;
  local_c = ExceptionList;
  pCVar1 = (CHmsForceFieldUniform *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x68);
  local_4 = 0;
  if (local_10 != (CHmsForceFieldUniform *)0x0) {
    CHmsForceFieldUniform(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CHmsForceFieldUniform::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CHmsForceFieldUniform::_scalar_deleting_destructor_
          (CHmsForceFieldUniform *this,CPfmHeap *param_1,uint param_2)
{
{
  CHmsForceFieldUniform *unaff_ESI;
  
  ~CHmsForceFieldUniform(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CHmsForceFieldUniform::~CHmsForceFieldUniform
// =================================================
void __thiscall
CHmsForceFieldUniform::~CHmsForceFieldUniform
          (CHmsForceFieldUniform *this,CHmsForceFieldUniform *param_1)
{
{
  *(undefined ***)this = vftable;
  CHmsForceField::~CHmsForceField((CHmsForceField *)this,(CHmsForceField *)param_1);
  return;
}
}

