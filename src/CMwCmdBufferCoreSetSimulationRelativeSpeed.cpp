
/* public: void __thiscall CMwCmdBufferCore::SetSimulationRelativeSpeed(float)
 */

void __thiscall CMwCmdBufferCore::SetSimulationRelativeSpeed(
    CMwCmdBufferCore *this, float param_1)

{
  if ((*(int *)(this + 0x34) != 0) && (param_1 < 0.0)) {
    param_1 = 0.0;
  }
  CMwTimerAdapter::SetRelativeSpeed((CMwTimerAdapter *)(this + 0xa0), param_1);
  return;
}
