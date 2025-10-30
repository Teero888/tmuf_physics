
/* public: void __thiscall GmOctreeLowMem_15b_31b::Build(class
   CFastBuffer<struct GmOctreeLowMem<struct
   GmOctreeLowMemCell_i15b>::SBuildInput> const &,struct
   SOctreeLowMem_BuildParam *) */

void __thiscall GmOctreeLowMem_15b_31b::Build(GmOctreeLowMem_15b_31b *this,
                                              CFastBuffer<> *param_1,
                                              SOctreeLowMem_BuildParam *param_2)

{
  CFastBuffer<> *this_00;

  Release(this);
  *(undefined4 *)this = 0;
  this_00 = (CFastBuffer<> *)operator_new(0xc);
  if (this_00 != (CFastBuffer<> *)0x0) {
    CFastBuffer<>::CFastBuffer<>(this_00);
    *(CFastBuffer<> **)(this + 4) = this_00;
    GmOctreeLowMem<>::Build((GmOctreeLowMem<> *)this_00, param_1, param_2);
    return;
  }
  *(undefined4 *)(this + 4) = 0;
  GmOctreeLowMem<>::Build((GmOctreeLowMem<> *)0x0, param_1, param_2);
  return;
}

/* public: void __thiscall GmOctreeLowMem_15b_31b::Build(class
   CFastBuffer<struct GmOctreeLowMem<struct
   GmOctreeLowMemCell_i31b>::SBuildInput> const &,struct
   SOctreeLowMem_BuildParam *) */

void __thiscall GmOctreeLowMem_15b_31b::Build(GmOctreeLowMem_15b_31b *this,
                                              CFastBuffer<> *param_1,
                                              SOctreeLowMem_BuildParam *param_2)

{
  CFastBuffer<> *this_00;

  Release(this);
  *(undefined4 *)this = 1;
  this_00 = (CFastBuffer<> *)operator_new(0xc);
  if (this_00 != (CFastBuffer<> *)0x0) {
    CFastBuffer<>::CFastBuffer<>(this_00);
    *(CFastBuffer<> **)(this + 4) = this_00;
    GmOctreeLowMem<>::Build((GmOctreeLowMem<> *)this_00, param_1, param_2);
    return;
  }
  *(undefined4 *)(this + 4) = 0;
  GmOctreeLowMem<>::Build((GmOctreeLowMem<> *)0x0, param_1, param_2);
  return;
}

/* public: void __thiscall GmOctreeLowMem_15b_31b::BuildFromPos(unsigned
 *long,class GmVec3 const ,unsigned long,struct SOctreeLowMem_BuildParam *) */

void __thiscall GmOctreeLowMem_15b_31b::BuildFromPos(
    GmOctreeLowMem_15b_31b *this, ulong param_1, GmVec3 *param_2, ulong param_3,
    SOctreeLowMem_BuildParam *param_4)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  short *psVar4;
  int *piVar5;
  ulong uVar6;
  undefined4 *puVar7;
  int *piVar8;
  CFastBuffer<> local_18[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ade5b0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 < 0x8000) {
    CFastBuffer<>::CFastBuffer<>(local_18);
    local_4 = 0;
    CFastBuffer<>::AllocSetCount((CFastBuffer<> *)local_18, param_1);
    uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_18);
    uVar6 = 0;
    if (uVar3 != 0) {
      puVar7 = (undefined4 *)(param_2 + 8);
      do {
        psVar4 =
            (short *)CFastArray<>::operator[]((CFastArray<> *)local_18, uVar6);
        *psVar4 = (short)uVar6 * 2;
        *(undefined4 *)(psVar4 + 2) = puVar7[-2];
        uVar6 = uVar6 + 1;
        *(undefined4 *)(psVar4 + 4) = puVar7[-1];
        uVar1 = *puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + param_3);
        *(undefined4 *)(psVar4 + 6) = uVar1;
        *(undefined4 *)(psVar4 + 8) = 0;
        *(undefined4 *)(psVar4 + 10) = 0;
        *(undefined4 *)(psVar4 + 0xc) = 0;
      } while (uVar6 < uVar3);
    }
    Build(this, (CFastBuffer<> *)local_18, param_4);
    CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_18);
  } else {
    CFastBuffer<>::CFastBuffer<>(local_18);
    local_4 = 1;
    CFastBuffer<>::AllocSetCount((CFastBuffer<> *)local_18, param_1);
    uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_18);
    uVar6 = 0;
    if (uVar3 != 0) {
      piVar8 = (int *)(param_2 + 8);
      do {
        piVar5 =
            (int *)CFastArray<>::operator[]((CFastArray<> *)local_18, uVar6);
        *piVar5 = uVar6 * 2;
        piVar5[1] = piVar8[-2];
        uVar6 = uVar6 + 1;
        piVar5[2] = piVar8[-1];
        iVar2 = *piVar8;
        piVar8 = (int *)((int)piVar8 + param_3);
        piVar5[3] = iVar2;
        piVar5[4] = 0;
        piVar5[5] = 0;
        piVar5[6] = 0;
      } while (uVar6 < uVar3);
    }
    Build(this, (CFastBuffer<> *)local_18, param_4);
    CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_18);
  }
  ExceptionList = local_c;
  return;
}

/* public: int __thiscall
   GmOctreeLowMem_15b_31b::GetAllUserDatas_InterBBox_AreAllIncluded(class
   CFastBuffer<unsigned long> &,class GmBoxAligned const &) */

int __thiscall GmOctreeLowMem_15b_31b::GetAllUserDatas_InterBBox_AreAllIncluded(
    GmOctreeLowMem_15b_31b *this, CFastBuffer<> *param_1, GmBoxAligned *param_2)

{
  int iVar1;

  if (*(int *)this == 0) {
    iVar1 = GmOctreeLowMem<>::GetAllUserDatas_InterBBox_AreAllIncluded(
        *(GmOctreeLowMem<> **)(this + 4), param_1, param_2);
    return iVar1;
  }
  iVar1 = GmOctreeLowMem<>::GetAllUserDatas_InterBBox_AreAllIncluded(
      *(GmOctreeLowMem<> **)(this + 4), param_1, param_2);
  return iVar1;
}

/* protected: void __thiscall GmOctreeLowMem_15b_31b::Release(void) */

void __thiscall GmOctreeLowMem_15b_31b::Release(GmOctreeLowMem_15b_31b *this)

{
  CFastBuffer<> *this_00;

  if ((*(int *)this == 0) || (*(int *)this == 1)) {
    this_00 = *(CFastBuffer<> **)(this + 4);
    if (this_00 != (CFastBuffer<> *)0x0) {
      CFastBuffer<>::~CFastBuffer<>(this_00);
      operator_delete(this_00);
    }
    *(undefined4 *)(this + 4) = 0;
  }
  *(undefined4 *)this = 2;
  return;
}
