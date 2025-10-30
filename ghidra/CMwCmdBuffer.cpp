
/* public: void __thiscall CMwCmdBuffer::Run(unsigned long) */

void __thiscall CMwCmdBuffer::Run(CMwCmdBuffer *this, ulong param_1)

{
  CFastBuffer<> *this_00;
  CMwNod *this_01;
  int iVar1;
  ulong uVar2;
  SFastCat *pSVar3;
  CSceneMobil **ppCVar4;
  int **ppiVar5;
  uint uVar6;
  ulong uVar7;
  uint local_4;

  if (*(int *)(this + 0x44) != 0) {
    this_00 = (CFastBuffer<> *)(this + 0x20);
    uVar7 = 0;
    uVar2 = CFastBuffer<>::GetCount(this_00);
    if (uVar2 != 0) {
      do {
        pSVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar7);
        local_4 = *(uint *)(pSVar3 + 4);
        uVar6 = 0;
        if (local_4 != 0) {
          do {
            ppCVar4 = CFastBufferCat<>::GetElemInCat(
                (CFastBufferCat<> *)this_00, uVar6, uVar7);
            this_01 = (CMwNod *)*ppCVar4;
            if ((*(uint *)(this_01 + 0x18) & 2) == 0) {
              uVar6 = uVar6 + 1;
            } else {
              *(uint *)(this_01 + 0x18) =
                  *(uint *)(this_01 + 0x18) & 0xfffffffd;
              CMwNod::MwRelease(this_01);
              CFastBufferCat<>::ReplaceByLastInCatAt(
                  (CFastBufferCat<> *)this_00, uVar6, uVar7);
              local_4 = local_4 - 1;
            }
          } while (uVar6 < local_4);
        }
        uVar7 = uVar7 + 1;
        uVar2 = CFastBuffer<>::GetCount(this_00);
      } while (uVar7 < uVar2);
    }
    *(undefined4 *)(this + 0x44) = 0;
  }
  *(ulong *)(this + 0x18) = param_1;
  pSVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x20), param_1);
  iVar1 = *(int *)(pSVar3 + 4);
  *(int *)(this + 0x1c) = iVar1;
  *(undefined4 *)(this + 0x14) = 0;
  if (iVar1 != 0) {
    do {
      ppiVar5 = (int **)CFastBufferCat<>::GetElemInCat(
          (CFastBufferCat<> *)(CFastBuffer<> *)(this + 0x20),
          *(ulong *)(this + 0x14), param_1);
      (**(code **)(**ppiVar5 + 0x78))();
      *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
    } while (*(uint *)(this + 0x14) < *(uint *)(this + 0x1c));
  }
  return;
}
