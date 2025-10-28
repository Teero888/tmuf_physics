
/* public: void __thiscall CMwCmdBufferCore::SetSimulationCurrentTime(unsigned
 * long) */

void __thiscall CMwCmdBufferCore::SetSimulationCurrentTime(
    CMwCmdBufferCore *this, ulong param_1)

{
  EMwSchemeTimedPatterns *pEVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;

  CMwTimerAdapter::SetCurrentTimeAtHumanTick((CMwTimerAdapter *)(this + 0xa0),
                                             param_1);
  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x24));
  if (uVar3 != 0) {
    uVar6 = 0;
    piVar5 = &DAT_00d731ec;
    do {
      pEVar1 = (&s_MwSchemeTimedPatterns)[uVar6];
      piVar5[1] = 0;
      uVar2 = *(uint *)(this + (int)pEVar1 * 8 + 200);
      uVar6 = uVar6 + 1;
      iVar4 = (((uVar2 - 1) + param_1) / uVar2) * uVar2;
      *piVar5 = iVar4;
      piVar5[-1] = *(uint *)(this + (int)pEVar1 * 8 + 200) + iVar4;
      piVar5 = piVar5 + 3;
    } while (uVar6 < uVar3);
  }
  if (*(CMwCmdBuffer **)(this + 0x100) != (CMwCmdBuffer *)0x0) {
    CMwCmdBuffer::Run(*(CMwCmdBuffer **)(this + 0x100), 0);
  }
  return;
}
