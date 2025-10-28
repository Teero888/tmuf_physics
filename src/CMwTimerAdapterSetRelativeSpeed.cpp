
/* public: void __thiscall CMwTimerAdapter::SetRelativeSpeed(float) */

void __thiscall CMwTimerAdapter::SetRelativeSpeed(CMwTimerAdapter *this,
                                                  float param_1)

{
  undefined4 uVar1;
  CMwTimer *pCVar2;
  ulong uVar3;
  undefined4 *puVar4;
  ulong *puVar5;
  CMwTimer **extraout_EDX;
  int extraout_EDX_00;
  float10 extraout_ST0;

  if ((NAN(*(float *)(this + 8)) || NAN(param_1)) ==
      (*(float *)(this + 8) == param_1)) {
    puVar4 = (undefined4 *)CPlugAudio::MwGetId((CPlugAudio *)this);
    uVar1 = *puVar4;
    pCVar2 = extraout_EDX[3];
    puVar5 = CMwTimer::GetTickTime(*extraout_EDX);
    uVar3 = *puVar5;
    *(float *)(extraout_EDX_00 + 8) = (float)extraout_ST0;
    *(ulong *)(extraout_EDX_00 + 0xc) = uVar3;
    *(int *)(extraout_EDX_00 + 4) =
        *(int *)(extraout_EDX_00 + 4) + (uVar3 - (int)pCVar2);
    *(undefined4 *)(extraout_EDX_00 + 0x10) = uVar1;
    return;
  }
  return;
}
