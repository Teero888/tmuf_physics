// Class implementation: CMotionCmdBase

// =================================================
// Function: CMotionCmdBase::CMotionCmdBase
// =================================================
void __thiscall CMotionCmdBase::CMotionCmdBase(CMotionCmdBase *this,CMotionCmdBase *param_1)
{
{
  CMwCmd *unaff_ESI;
  
  CMwCmd::CMwCmd((CMwCmd *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x1c) = 1;
  *(CMotionCmdBase **)(this + 0x24) = this + 0x28;
  *(undefined4 *)(this + 0x30) = 3;
  *(undefined4 *)(this + 0x28) = 1000;
  return;
}
}

// =================================================
// Function: CMotionCmdBase::GetBaseTime
// =================================================
ulong __thiscall CMotionCmdBase::GetBaseTime(CMotionCmdBase *this,CMotionCmdBase *param_1)
{
{
  int iVar1;
  ulong *puVar2;
  CPlugAudio *this_00;
  CMwId *pCVar3;
  void *this_01;
  CMwTimerAdapter *unaff_retaddr;
  
  iVar1 = *(int *)(this + 0x1c);
  if (iVar1 == 0) {
    this_01 = *(void **)(DAT_00d731e0 + 0x14);
    if (this_01 == (void *)0x0) {
      this_01 = (void *)(DAT_00d731e0 + 0xa0);
    }
    puVar2 = CMwTimerAdapter::GetTickTime(this_01,unaff_retaddr);
    return *puVar2;
  }
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      return 0;
    }
    puVar2 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_retaddr);
    return *puVar2;
  }
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar3 = CPlugAudio::MwGetId(this_00,(CPlugAudio *)unaff_retaddr);
  return *(ulong *)pCVar3;
}
}

// =================================================
// Function: CMotionCmdBase::SetPeriod
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CMotionCmdBase::SetPeriod(CMotionCmdBase *this,CFuncPlug *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  CMotionCmdBase *unaff_EDI;
  float10 extraout_ST0;
  float10 fVar5;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar6;
  int local_4;
  
  if (param_1 == (CFuncPlug *)0x0) {
    param_1 = (CFuncPlug *)0x1;
  }
  uVar4 = GetBaseTime(this,unaff_EDI);
  fVar1 = (float)(int)param_1;
  if ((int)param_1 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  fVar2 = (float)*(int *)(this + 0x28);
  if (*(int *)(this + 0x28) < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar3 = (float)(int)uVar4;
  if ((int)uVar4 < 0) {
    fVar3 = fVar3 + (float)_DAT_00b3dca0;
  }
  fVar1 = fVar3 * ((fVar1 - fVar2) / (fVar2 * fVar1)) + *(float *)(this + 0x2c);
  *(float *)(this + 0x2c) = fVar1;
  if (0.0 <= fVar1) {
    __ftol2_sse();
    fVar5 = extraout_ST0_00 - (float10)extraout_EAX_00;
    fVar6 = extraout_ST1_00;
  }
  else {
    __ftol2_sse();
    fVar5 = extraout_ST0 - (float10)extraout_EAX;
    fVar6 = extraout_ST1;
  }
  *(float *)(this + 0x2c) = (float)fVar5;
  *(CFuncPlug **)(this + 0x28) = param_1;
  local_4 = (int)(longlong)ROUND(fVar6 * (float10)*(float *)(this + 0x2c));
  *(uint *)(this + 0x3c) = (local_4 + uVar4) / (uint)param_1;
  return;
}
}

// =================================================
// Function: CMotionCmdBase::SetPhase
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CMotionCmdBase::SetPhase(CMotionCmdBase *this,CFuncPlug *param_1,float param_2)
{
{
  void *this_00;
  float fVar1;
  float10 extraout_ST0;
  CFuncPlug *local_c;
  int local_8;
  
  local_c = (CFuncPlug *)0x0;
  if ((float)param_1 < 0.0 == ((float)param_1 == 0.0)) {
    if (1.0 < (float)param_1 == ((float)param_1 == 1.0)) {
      local_c = param_1;
    }
    else {
      local_c = (CFuncPlug *)0x3f800000;
    }
  }
  if (*(int *)(this + 0x48) != 0) {
    *(CFuncPlug **)(this + 0x2c) = local_c;
    return;
  }
  if (((byte)this[0x18] & 1) != 0) {
    return;
  }
  this_00 = *(void **)(this + 0x28);
  fVar1 = (float)(int)this_00;
  if ((int)this_00 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  local_8 = (int)(longlong)ROUND(fVar1 * (float)param_1);
  *(uint *)(this + 0x20) = local_8 + (*(uint *)(this + 0x20) / (uint)this_00) * (int)this_00;
  ComputeOutput(this_00,(CFuncColor *)param_1);
  *(float *)(this + 0x34) = (float)extraout_ST0;
  *(int *)(this + 0x2c) = local_8;
  return;
}
}

