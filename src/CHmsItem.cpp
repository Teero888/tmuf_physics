
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

/* public: void __thiscall CHmsItem::AddForce(class GmVec3 const &) */

void __thiscall CHmsItem::AddForce(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::AddLocalForce(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}
