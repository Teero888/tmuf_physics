// Class implementation: CNetTransferInfoQueue

// =================================================
// Function: CNetTransferInfoQueue::Add
// =================================================
void __thiscall
CNetTransferInfoQueue::Add
          (CNetTransferInfoQueue *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  undefined4 *puVar1;
  ulong uVar2;
  ulong *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  CMwTimerAdapter *unaff_EDI;
  uint uVar8;
  int in_stack_0000000c;
  
  puVar3 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_EDI);
  uVar2 = *puVar3;
  if (*(int *)(this + 0x14) == *(int *)(this + 8)) {
    uVar7 = *(int *)(this + 8) * 2;
    if (uVar7 == 0) {
      uVar7 = 2;
    }
    puVar4 = operator_new__(-(uint)((int)((ulonglong)uVar7 * 0xc >> 0x20) != 0) |
                            (uint)((ulonglong)uVar7 * 0xc));
    uVar8 = 0;
    puVar6 = puVar4;
    if (*(int *)(this + 0x14) != 0) {
      do {
        uVar5 = *(int *)(this + 0xc) + uVar8;
        uVar8 = uVar8 + 1;
        puVar1 = (undefined4 *)(*(int *)(this + 4) + (uVar5 % *(uint *)(this + 8)) * 0xc);
        *puVar6 = *puVar1;
        puVar6[1] = puVar1[1];
        puVar6[2] = puVar1[2];
        puVar6 = puVar6 + 3;
      } while (uVar8 < *(uint *)(this + 0x14));
    }
    *(undefined4 *)(this + 0xc) = 0;
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(this + 0x14);
    *(uint *)(this + 8) = uVar7;
    operator_delete__(*(void **)(this + 4));
    *(undefined4 **)(this + 4) = puVar4;
  }
  *(TiXmlAttribute **)(*(int *)(this + 4) + *(int *)(this + 0x10) * 0xc) = param_2;
  *(ulong *)(*(int *)(this + 4) + 4 + *(int *)(this + 0x10) * 0xc) = uVar2;
  *(int *)(*(int *)(this + 4) + 8 + *(int *)(this + 0x10) * 0xc) = in_stack_0000000c;
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  *(TiXmlAttribute **)(this + 0x18) = param_2 + *(int *)(this + 0x18);
  *(uint *)(this + 0x10) = (*(int *)(this + 0x10) + 1U) % *(uint *)(this + 8);
  if (in_stack_0000000c != 1) {
    if (in_stack_0000000c == 2) {
      *(TiXmlAttribute **)(this + 0x1c) = param_2 + *(int *)(this + 0x1c);
    }
    return;
  }
  *(TiXmlAttribute **)(this + 0x20) = param_2 + *(int *)(this + 0x20);
  return;
}
}

