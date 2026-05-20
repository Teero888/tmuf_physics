// Class implementation: CMwTimerAdapter

// =================================================
// Function: CMwTimerAdapter::ComputeTimeAtHumanTick
// =================================================
void __thiscall CMwTimerAdapter::ComputeTimeAtHumanTick(void *this,CMwTimerAdapter *param_1)
{
{
  ulong *puVar1;
  ulong uVar2;
  CMwTimerAdapter *unaff_ESI;
  ulong unaff_retaddr;
  
  puVar1 = CMwTimer::GetTickTime(*(void **)this,unaff_ESI);
  uVar2 = ConvertHumanToGame(this,(CMwTimerAdapter *)*puVar1,unaff_retaddr);
  *(ulong *)((int)this + 0x14) = uVar2;
  return;
}
}

// =================================================
// Function: CMwTimerAdapter::ConvertHumanToGame
// =================================================
ulong __thiscall
CMwTimerAdapter::ConvertHumanToGame(void *this,CMwTimerAdapter *param_1,ulong param_2)
{
{
  uint extraout_EAX;
  ulong uVar1;
  int iVar2;
  
  if (param_1 != *(CMwTimerAdapter **)((int)this + 0xc)) {
    __ftol2_sse();
    uVar1 = extraout_EAX + *(uint *)((int)this + 0x10);
    iVar2 = ((int)extraout_EAX >> 0x1f) + (uint)CARRY4(extraout_EAX,*(uint *)((int)this + 0x10));
    if (((1 < iVar2) || (0 < iVar2)) || ((iVar2 < 1 && (iVar2 < 0)))) {
      uVar1 = 0;
    }
    return uVar1;
  }
  return *(ulong *)((int)this + 0x10);
}
}

// =================================================
// Function: CMwTimerAdapter::GetAsyncPeriod
// =================================================
float __thiscall CMwTimerAdapter::GetAsyncPeriod(void *this,CMwTimerAdapter *param_1)
{
{
  return *(float *)(*(int *)this + 0x10) * *(float *)((int)this + 8);
}
}

// =================================================
// Function: CMwTimerAdapter::GetAsyncPeriodMwTime
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall CMwTimerAdapter::GetAsyncPeriodMwTime(void *this,CMwTimerAdapter *param_1)
{
{
  float fVar1;
  undefined4 local_8;
  
  fVar1 = (float)*(int *)(*(int *)this + 0xc);
  if (*(int *)(*(int *)this + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  local_8 = (ulong)(longlong)ROUND(fVar1 * *(float *)((int)this + 8));
  return local_8;
}
}

// =================================================
// Function: CMwTimerAdapter::GetRelativeSpeed
// =================================================
float __thiscall CMwTimerAdapter::GetRelativeSpeed(void *this,CMwTimerAdapter *param_1)
{
{
  return *(float *)((int)this + 8);
}
}

// =================================================
// Function: CMwTimerAdapter::GetTickTime
// =================================================
ulong * __thiscall CMwTimerAdapter::GetTickTime(void *this,CMwTimerAdapter *param_1)
{
{
  return (ulong *)((int)this + 0x1c);
}
}

// =================================================
// Function: CMwTimerAdapter::GetTime
// =================================================
ulong __thiscall CMwTimerAdapter::GetTime(void *this,CMwTimerAdapter *param_1)
{
{
  CMwTimerAdapter *pCVar1;
  ulong uVar2;
  CMwTimer *unaff_ESI;
  ulong unaff_retaddr;
  
  pCVar1 = (CMwTimerAdapter *)CMwTimer::GetElapsedTimeSinceInit(*(void **)this,unaff_ESI);
  uVar2 = ConvertHumanToGame(this,pCVar1,unaff_retaddr);
  return uVar2;
}
}

// =================================================
// Function: CMwTimerAdapter::GetTimeAtPreviousHumanTick
// =================================================
ulong __thiscall CMwTimerAdapter::GetTimeAtPreviousHumanTick(void *this,CMwTimerAdapter *param_1)
{
{
  CMwId *pCVar1;
  CPlugAudio *this_00;
  int extraout_EDX;
  CMwTimerAdapter *unaff_retaddr;
  
  GetAsyncPeriodMwTime(this,unaff_retaddr);
  pCVar1 = CPlugAudio::MwGetId(this_00,(CPlugAudio *)param_1);
  return *(int *)pCVar1 - extraout_EDX;
}
}

// =================================================
// Function: CMwTimerAdapter::InitTimer
// =================================================
void __thiscall
CMwTimerAdapter::InitTimer(void *this,CMwTimerAdapter *param_1,CMwTimer *param_2,float param_3)
{
{
  ulong uVar1;
  DWORD DVar2;
  CMwTimer *unaff_ESI;
  
  *(CMwTimer **)((int)this + 8) = param_2;
  *(CMwTimerAdapter **)this = param_1;
  uVar1 = CMwTimer::GetElapsedTimeSinceInit(param_1,unaff_ESI);
  *(ulong *)((int)this + 0xc) = uVar1;
  DVar2 = timeGetTime();
  *(DWORD *)((int)this + 4) = DVar2;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x18) = 100;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CMwTimerAdapter::Resync
// =================================================
void __thiscall CMwTimerAdapter::Resync(void *this,CMwTimerAdapter *param_1)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  DWORD DVar4;
  CMwTimer *unaff_EDI;
  
  uVar3 = CMwTimer::GetElapsedTimeSinceInit(*(void **)this,unaff_EDI);
  iVar1 = *(int *)((int)this + 0xc);
  iVar2 = *(int *)((int)this + 4);
  DVar4 = timeGetTime();
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + (int)(DVar4 + ((iVar1 - iVar2) - uVar3)) / 2;
  return;
}
}

// =================================================
// Function: CMwTimerAdapter::SetCurrentTimeAtHumanTick
// =================================================
void __thiscall
CMwTimerAdapter::SetCurrentTimeAtHumanTick(void *this,CMwTimerAdapter *param_1,ulong param_2)
{
{
  ulong uVar1;
  ulong *puVar2;
  int extraout_EDX;
  CMwTimerAdapter *unaff_ESI;
  CMwTimerAdapter *unaff_retaddr;
  
  puVar2 = CMwTimer::GetTickTime(*(void **)this,unaff_ESI);
  uVar1 = *puVar2;
  *(ulong *)((int)this + 0xc) = uVar1;
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + (uVar1 - extraout_EDX);
  *(ulong *)((int)this + 0x10) = param_2;
  ComputeTimeAtHumanTick(this,unaff_retaddr);
  Resync(this,param_1);
  return;
}
}

// =================================================
// Function: CMwTimerAdapter::SetRelativeSpeed
// =================================================
void __thiscall CMwTimerAdapter::SetRelativeSpeed(void *this,CMwTimerAdapter *param_1,float param_2)
{
{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  CMwId *pCVar4;
  ulong *puVar5;
  undefined4 *extraout_EDX;
  int extraout_EDX_00;
  CMwTimerAdapter *unaff_ESI;
  CPlugAudio *unaff_EDI;
  float10 extraout_ST0;
  
  if (*(float *)((int)this + 8) != (float)param_1) {
    pCVar4 = CPlugAudio::MwGetId(this,unaff_EDI);
    uVar1 = *(undefined4 *)pCVar4;
    iVar2 = extraout_EDX[3];
    puVar5 = CMwTimer::GetTickTime((void *)*extraout_EDX,unaff_ESI);
    uVar3 = *puVar5;
    *(float *)(extraout_EDX_00 + 8) = (float)extraout_ST0;
    *(ulong *)(extraout_EDX_00 + 0xc) = uVar3;
    *(int *)(extraout_EDX_00 + 4) = *(int *)(extraout_EDX_00 + 4) + (uVar3 - iVar2);
    *(undefined4 *)(extraout_EDX_00 + 0x10) = uVar1;
    return;
  }
  return;
}
}

