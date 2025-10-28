
ulong __thiscall CMwTimerAdapter::GetTime(CMwTimerAdapter *this)

{
  ulong uVar1;

  uVar1 =
      GetTime((CMwTimerAdapter *)(CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0));
  return uVar1;
}
