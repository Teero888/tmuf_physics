
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

/* public: void __thiscall CHmsItem::SetDynamicType(enum CHmsItem::EDynamicType)
 */

void __thiscall CHmsItem::SetDynamicType(CHmsItem *this, EDynamicType param_1)

{
  ulong uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  ulong uVar8;
  CFastArray<> local_20[12];
  void *local_14;
  undefined *puStack_10;
  undefined4 local_c;

  local_c = 0xffffffff;
  puStack_10 = &LAB_00a95808;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1 != (*(uint *)(this + 0x18) >> 0xb & 3)) {
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
    CFastArray<>::CFastArray<>(local_20);
    uVar8 = 0;
    local_c = 0;
    CFastArray<>::SetCount((CFastArray<> *)local_20, uVar1);
    if (uVar1 != 0) {
      do {
        piVar2 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x34), uVar8);
        puVar3 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)local_20, uVar8);
        *puVar3 = *(undefined4 *)(*piVar2 + 0x14);
        ppiVar4 = (int **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x34), uVar8);
        puVar5 = (undefined4 *)(**(code **)(**ppiVar4 + 0x78))();
        puVar6 = puVar3;
        for (iVar7 = 0xc; puVar6 = puVar6 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
        }
        puVar6 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x34), uVar8);
        uVar8 = uVar8 + 1;
        puVar3[0xd] = *puVar6;
      } while (uVar8 < uVar1);
    }
    uVar8 = 0;
    if (uVar1 != 0) {
      do {
        ppiVar4 =
            (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)local_20, uVar8);
        (**(code **)(**ppiVar4 + 0x7c))(ppiVar4[0xd]);
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar1);
    }
    uVar8 = 0;
    *(EDynamicType *)(this + 0x18) =
        *(uint *)(this + 0x18) ^
        (param_1 << 0xb ^ *(uint *)(this + 0x18)) & 0x1800;
    if (uVar1 != 0) {
      do {
        ppiVar4 =
            (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)local_20, uVar8);
        (**(code **)(**ppiVar4 + 0x78))(this, ppiVar4 + 1);
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar1);
    }
    CFastArray<>::~CFastArray<>((CFastArray<> *)local_20);
  }
  ExceptionList = local_14;
  return;
}

/* public: void __thiscall CHmsItem::ResetDynamicState(void) */

void __thiscall CHmsItem::ResetDynamicState(CHmsItem *this)

{
  ulong uVar1;
  CHmsCorpus **ppCVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      ppCVar2 = (CHmsCorpus **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      CHmsCorpus::Reset(*ppCVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}
