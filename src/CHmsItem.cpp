
/* public: void __thiscall CHmsItem::SetCollisionGroup(enum
 * CHmsItem::ECollisionGroup) */

void __thiscall CHmsItem::SetCollisionGroup(CHmsItem *this,
                                            ECollisionGroup param_1)

{
  CFastBuffer<> *this_00;
  ulong uVar1;
  int *piVar2;
  undefined4 *puVar3;
  ulong uVar4;

  if (param_1 != (*(uint *)(this + 0x18) >> 0xd & 0xf)) {
    this_00 = (CFastBuffer<> *)(this + 0x34);
    uVar1 = CFastBuffer<>::GetCount(this_00);
    uVar4 = 0;
    if (uVar1 != 0) {
      do {
        piVar2 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar4);
        piVar2 = *(int **)(*piVar2 + 0x14);
        puVar3 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)this_00, uVar4);
        (**(code **)(*piVar2 + 0x84))(*puVar3);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    uVar4 = 0;
    *(ECollisionGroup *)(this + 0x18) =
        *(uint *)(this + 0x18) ^
        (param_1 << 0xd ^ *(uint *)(this + 0x18)) & 0x1e000;
    if (uVar1 != 0) {
      do {
        piVar2 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar4);
        piVar2 = *(int **)(*piVar2 + 0x14);
        puVar3 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)this_00, uVar4);
        (**(code **)(*piVar2 + 0x88))(*puVar3);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
  }
  return;
}
