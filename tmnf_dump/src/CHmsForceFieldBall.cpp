// Class implementation: CHmsForceFieldBall

// =================================================
// Function: CHmsForceFieldBall::CHmsForceFieldBall
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsForceFieldBall::CHmsForceFieldBall(CHmsForceFieldBall *this,CHmsForceFieldBall *param_1)
{
{
  CHmsForceField *unaff_ESI;
  CPlugVisualStrip *unaff_retaddr;
  ulong in_stack_00000008;
  
  CHmsForceField::CHmsForceField((CHmsForceField *)this,unaff_ESI);
  *(undefined4 *)(this + 0x5c) = _DAT_00b313ac;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x60) = 0x3f800000;
  ComputeBoundingBox(this,unaff_retaddr,(ulong)param_1,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CHmsForceFieldBall::Chunk
// =================================================
void __thiscall
CHmsForceFieldBall::Chunk
          (CHmsForceFieldBall *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  ulong unaff_ESI;
  ulong unaff_EDI;
  CPlugVisualStrip *unaff_retaddr;
  
  if (param_2 == (CClassicArchive *)0x6015000) {
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x5c),(float *)0x1,unaff_EDI);
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x60),(float *)0x1,unaff_ESI);
    ComputeBoundingBox(this,unaff_retaddr,(ulong)param_1,0x6015000);
  }
  else if (param_2 != (CClassicArchive *)0xffffffff) {
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,unaff_ESI);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsForceFieldBall::ComputeBoundingBox
// =================================================
void __thiscall
CHmsForceFieldBall::ComputeBoundingBox
          (CHmsForceFieldBall *this,CPlugVisualStrip *param_1,ulong param_2,ulong param_3)
{
{
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(this + 0x5c);
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(this + 0x5c);
  *(undefined4 *)(this + 0x78) = *(undefined4 *)(this + 0x5c);
  return;
}
}

// =================================================
// Function: CHmsForceFieldBall::GetChunkInfo
// =================================================
ulong __thiscall
CHmsForceFieldBall::GetChunkInfo(CHmsForceFieldBall *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 == (CFuncSegment *)0x6015000) {
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
// Function: CHmsForceFieldBall::GetMwClassId
// =================================================
ulong __thiscall CHmsForceFieldBall::GetMwClassId(CHmsForceFieldBall *this,CControlStyle *param_1)
{
{
  return 0x6015000;
}
}

// =================================================
// Function: CHmsForceFieldBall::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CHmsForceFieldBall::GetUidChunkFromIndex
          (CHmsForceFieldBall *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x6015000;
}
}

// =================================================
// Function: CHmsForceFieldBall::GetValue
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

GmVec3 __thiscall
CHmsForceFieldBall::GetValue(CHmsForceFieldBall *this,CFuncColorGradient *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(this + 0x3c) - *(float *)param_1;
  fVar2 = *(float *)(this + 0x40) - *(float *)(param_1 + 4);
  fVar3 = *(float *)(this + 0x44) - *(float *)(param_1 + 8);
  fVar4 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
  if ((fVar4 < *(float *)(this + 0x5c) * *(float *)(this + 0x5c)) && (_DAT_00cde80c < fVar4)) {
    fVar4 = -*(float *)(this + 0x60) / fVar4;
    *(float *)param_2 = fVar4 * fVar1;
    *(float *)((int)param_2 + 4) = fVar2 * fVar4;
    *(float *)((int)param_2 + 8) = fVar3 * fVar4;
    return (GmVec3)0x1;
  }
  return (GmVec3)0x0;
}
}

// =================================================
// Function: CHmsForceFieldBall::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall
CHmsForceFieldBall::MwGetClassInfo(CHmsForceFieldBall *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d67b10;
}
}

// =================================================
// Function: CHmsForceFieldBall::MwIsKindOf
// =================================================
int __thiscall
CHmsForceFieldBall::MwIsKindOf(CHmsForceFieldBall *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((((param_1 != (CMwCmdAffectParam *)0x6015000) && (param_1 != (CMwCmdAffectParam *)0x6014000))
      && (param_1 != (CMwCmdAffectParam *)0x6007000)) && (param_1 != (CMwCmdAffectParam *)0x6008000)
     ) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CHmsForceFieldBall::MwNewCHmsForceFieldBall
// =================================================
CMwNod * __cdecl CHmsForceFieldBall::MwNewCHmsForceFieldBall(void)
{
{
  CHmsForceFieldBall *pCVar1;
  CMwNod *extraout_EAX;
  CHmsForceFieldBall *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9795b;
  local_c = ExceptionList;
  pCVar1 = (CHmsForceFieldBall *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x7c);
  local_4 = 0;
  if (local_10 != (CHmsForceFieldBall *)0x0) {
    CHmsForceFieldBall(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CHmsForceFieldBall::TestBoxOverlap
// =================================================
int __thiscall
CHmsForceFieldBall::TestBoxOverlap
          (CHmsForceFieldBall *this,CHmsForceFieldBall *param_1,GmBoxAligned *param_2)
{
{
  int iVar1;
  GmIso4 *in_stack_0000000c;
  
  iVar1 = GmBoxAligned::TestInter
                    (this + 100,(CPlugVolumeProjector *)param_1,param_2,in_stack_0000000c);
  return iVar1;
}
}

// =================================================
// Function: CHmsForceFieldBall::VirtualParam_Set
// =================================================
ulong __thiscall
CHmsForceFieldBall::VirtualParam_Set
          (CHmsForceFieldBall *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  CPlugVisualStrip *unaff_ESI;
  ulong unaff_retaddr;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x6015000) {
    *(undefined4 *)(this + 0x5c) = *(undefined4 *)param_2;
    ComputeBoundingBox(this,unaff_ESI,unaff_retaddr,(ulong)param_1);
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CHmsPoc::VirtualParam_Set((CHmsPoc *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CHmsForceFieldBall::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CHmsForceFieldBall::_scalar_deleting_destructor_
          (CHmsForceFieldBall *this,CPfmHeap *param_1,uint param_2)
{
{
  CHmsForceFieldBall *unaff_ESI;
  
  ~CHmsForceFieldBall(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CHmsForceFieldBall::~CHmsForceFieldBall
// =================================================
void __thiscall
CHmsForceFieldBall::~CHmsForceFieldBall(CHmsForceFieldBall *this,CHmsForceFieldBall *param_1)
{
{
  *(undefined ***)this = vftable;
  CHmsForceField::~CHmsForceField((CHmsForceField *)this,(CHmsForceField *)param_1);
  return;
}
}

