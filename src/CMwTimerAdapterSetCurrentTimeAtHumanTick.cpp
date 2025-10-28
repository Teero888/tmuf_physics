
/* public: void __thiscall CMwTimerAdapter::SetCurrentTimeAtHumanTick(unsigned
 * long) */

void __thiscall CMwTimerAdapter::SetCurrentTimeAtHumanTick(
    CMwTimerAdapter *this, ulong param_1)

{
  ulong uVar1;
  ulong *puVar2;
  int extraout_EDX;

  puVar2 = CMwTimer::GetTickTime(*(CMwTimer **)this);
  uVar1 = *puVar2;
  *(ulong *)(this + 0xc) = uVar1;
  *(ulong *)(this + 4) = *(int *)(this + 4) + (uVar1 - extraout_EDX);
  *(ulong *)(this + 0x10) = param_1;
  ComputeTimeAtHumanTick(this);
  Resync(this);
  return;
}
