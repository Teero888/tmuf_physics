
/* public: void __thiscall CInputPort::ClearInputs(int) */

void __thiscall CInputPort::ClearInputs(CInputPort *this, int param_1)

{
  CMwCmdBufferCore *this_00;
  ulong uVar1;

  (**(code **)(*(int *)this + 0xa4))();
  CInputEventsStore::ClearStore((CInputEventsStore *)(this + 0x40));
  CInputEventsStore::Lock((CInputEventsStore *)(this + 0x40), 0);
  *(undefined4 *)(this + 0x38) = 1;
  this_00 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
  if (this_00 == (CMwCmdBufferCore *)0x0) {
    this_00 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
  }
  uVar1 = CMwTimerAdapter::GetTime((CMwTimerAdapter *)this_00);
  *(ulong *)(this + 200) = uVar1;
  if ((param_1 != 0) || (*(int *)(this + 0x8c) != 0)) {
    ReadCurMapLatestEventsFromHarware(this, 1);
  }
  return;
}
