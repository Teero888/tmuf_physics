
/* public: void __thiscall CMwCmdBufferCore::StopSimulation(void) */

void __thiscall CMwCmdBufferCore::StopSimulation(CMwCmdBufferCore *this)

{
  CMwTimerAdapter::SetRelativeSpeed((CMwTimerAdapter *)(this + 0xa0), 0.0);
  *(undefined4 *)(this + 0x34) = 0;
  return;
}
