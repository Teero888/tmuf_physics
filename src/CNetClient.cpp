
/* private: void __thiscall CNetClient::NotifySimulationTimerSet(void) */

void __thiscall CNetClient::NotifySimulationTimerSet(CNetClient *this)

{
  int iVar1;
  ulong uVar2;
  CMwTimerAdapter *this_00;

  uVar2 = CMwTimer::GetElapsedTimeSinceInit(
      (CMwTimer *)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x70));
  iVar1 = *(int *)(this + 0x154);
  *(undefined4 *)(this + 300) = 0x3f800000;
  *(undefined4 *)(this + 0x118) = 0;
  *(ulong *)(this + 0x120) = uVar2;
  *(undefined4 *)(this + 0x11c) = 0;
  CFastBufferWheel<>::ClearWheel((CFastBufferWheel<> *)(iVar1 + 0x6c));
  *(undefined4 *)(iVar1 + 0x68) = 1;
  *(undefined4 *)(this + 0x114) = 0;
  *(undefined4 *)(this + 0x128) = 0;
  uVar2 = CMwTimerAdapter::GetTime(this_00);
  *(ulong *)(this + 0x13c) = uVar2;
  *(undefined4 *)(this + 0x110) = 0xffffffff;
  return;
}
