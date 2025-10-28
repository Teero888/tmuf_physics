
/* public: void __thiscall CMwCmdBufferCore::StartSimulation(int,int,float) */

void __thiscall CMwCmdBufferCore::StartSimulation(CMwCmdBufferCore *this,
                                                  int param_1, int param_2,
                                                  float param_3)

{
  CMwTimerAdapter *this_00;
  EMwSchemeTimedPatterns *pEVar1;
  uint uVar2;
  uint *puVar3;
  ulong uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;

  uVar7 = 0;
  this_00 = (CMwTimerAdapter *)(this + 0xa0);
  if (param_1 == 0) {
    puVar3 = (uint *)CPlugAudio::MwGetId((CPlugAudio *)this_00);
    param_1 = *puVar3;
    if (((param_2 != 0) &&
         (uVar2 = *(uint *)(this + 0xbc), uVar2 <= (uint)param_1)) &&
        ((uint)param_1 <= uVar2 + 1000)) {
      param_1 = uVar2 + 1;
      goto LAB_009230b3;
    }
  } else {
    CMwTimerAdapter::SetCurrentTimeAtHumanTick(this_00, 1);
    *(undefined4 *)(this + 0xbc) = 1;
    *(undefined4 *)(this + 0xb4) = 1;
    param_1 = 0;
  }
  if (*(CMwCmdBuffer **)(this + 0x100) != (CMwCmdBuffer *)0x0) {
    CMwCmdBuffer::Run(*(CMwCmdBuffer **)(this + 0x100), 0);
  }
LAB_009230b3:
  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x24));
  if (uVar4 != 0) {
    piVar6 = &DAT_00d731ec;
    do {
      pEVar1 = (&s_MwSchemeTimedPatterns)[uVar7];
      piVar6[1] = 0;
      uVar2 = *(uint *)(this + (int)pEVar1 * 8 + 200);
      uVar7 = uVar7 + 1;
      iVar5 = (((uVar2 - 1) + param_1) / uVar2) * uVar2;
      *piVar6 = iVar5;
      piVar6[-1] = *(uint *)(this + (int)pEVar1 * 8 + 200) + iVar5;
      piVar6 = piVar6 + 3;
    } while (uVar7 < uVar4);
  }
  *(undefined4 *)(this + 0x34) = 1;
  CMwTimerAdapter::SetRelativeSpeed(this_00, param_3);
  return;
}
