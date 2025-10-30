
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmOctreeLowMem<struct
   GmOctreeLowMemCell_i15b>::Build(class CFastBuffer<struct
   GmOctreeLowMem<struct GmOctreeLowMemCell_i15b>::SBuildInput> const &,struct
   SOctreeLowMem_BuildParam *) */

void __thiscall GmOctreeLowMem<>::Build(GmOctreeLowMem<> *this,
                                        CFastBuffer<> *param_1,
                                        SOctreeLowMem_BuildParam *param_2)

{
  ulong uVar1;
  uint *puVar2;

  CFastBuffer<>::Reset((CFastBuffer<> *)this);
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
  CFastBuffer<>::AllocSetCount((CFastBuffer<> *)this, uVar1 + 0x1c);
  puVar2 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
  *puVar2 = *puVar2 | 1;
  if (param_2 == (SOctreeLowMem_BuildParam *)0x0) {
    SOctreeLowMem_BuildParam::Reset(&s_BuildParam);
  } else {
    _s_BuildParam = *(undefined4 *)param_2;
    DAT_00d70844 = *(undefined4 *)(param_2 + 4);
    _DAT_00d70848 = *(undefined4 *)(param_2 + 8);
  }
  BuildBintreeRecurse(this, param_1, 0);
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
  puVar2 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, 0);
  *puVar2 = *puVar2 & 1 | uVar1 * 2;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* protected: void __thiscall GmOctreeLowMem<struct
   GmOctreeLowMemCell_i15b>::BuildBintreeRecurse(class CFastBuffer<struct
   GmOctreeLowMem<struct GmOctreeLowMemCell_i15b>::SBuildInput> const &,unsigned
   long) */

void __thiscall GmOctreeLowMem<>::BuildBintreeRecurse(GmOctreeLowMem<> *this,
                                                      CFastBuffer<> *param_1,
                                                      ulong param_2)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ulong uVar5;
  SDeviceMat *pSVar6;
  SSkinIndex *pSVar7;
  ulong uVar8;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  float local_44;
  float local_40;
  float local_3c;
  ulong local_38;
  CFastBuffer<> *local_34;
  CFastBuffer<> local_30[12];
  CFastBuffer<> local_24[16];
  int local_14;
  int local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ade548;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)param_1);
  if (uVar5 != 0) {
    pSVar6 = CFastArray<>::operator[]((CFastArray<> *)param_1, 0);
    local_50 = *(undefined4 *)(pSVar6 + 4);
    uVar8 = 1;
    local_4c = *(undefined4 *)(pSVar6 + 8);
    local_48 = *(undefined4 *)(pSVar6 + 0xc);
    local_44 = *(float *)(pSVar6 + 0x10);
    local_40 = *(float *)(pSVar6 + 0x14);
    local_3c = *(float *)(pSVar6 + 0x18);
    if (1 < uVar5) {
      do {
        pSVar6 = CFastArray<>::operator[]((CFastArray<> *)param_1, uVar8);
        GmBoxAligned::Union((GmBoxAligned *)&local_50,
                            (GmBoxAligned *)(pSVar6 + 4));
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar5);
    }
    uVar8 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
    pSVar7 = CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar8 - 0x1c);
    *(undefined4 *)(pSVar7 + 4) = local_50;
    *(undefined4 *)(pSVar7 + 8) = local_4c;
    *(undefined4 *)(pSVar7 + 0xc) = local_48;
    *(float *)(pSVar7 + 0x10) = local_44;
    *(float *)(pSVar7 + 0x14) = local_40;
    *(float *)(pSVar7 + 0x18) = local_3c;
    if ((_s_BuildParam == 0) || (param_2 < _s_BuildParam)) {
      bVar2 = false;
    } else {
      bVar2 = true;
    }
    if ((DAT_00d70844 == 0) || (DAT_00d70844 < uVar5)) {
      bVar3 = false;
    } else {
      bVar3 = true;
    }
    if ((_DAT_00d70848 <= 1e-05) ||
        (fVar1 = local_44 * 8.0 * local_40 * local_3c,
         fVar1 < _DAT_00d70848 == (NAN(fVar1) || NAN(_DAT_00d70848)))) {
      bVar4 = false;
    } else {
      bVar4 = true;
    }
    if ((((bVar2) || (bVar3)) || (bVar4)) ||
        (fVar1 =
             local_3c * local_3c + local_40 * local_40 + local_44 * local_44,
         NAN(fVar1) != (fVar1 == 0.0))) {
      CellCopyInputAsTailLeafs(this, param_1);
    } else {
      local_38 = param_2;
      local_34 = param_1;
      CFastBuffer<>::CFastBuffer<>(local_30);
      CFastBuffer<>::CFastBuffer<>(local_24);
      local_4 = 0;
      GmOctreeLowMem<>::BuildSplit_Init((GmOctreeLowMem<> *)this,
                                        (SBuildSplit *)&local_38,
                                        (GmBoxAligned *)&local_50);
      if ((local_14 == 0) || (local_10 == 0)) {
        CellCopyInputAsTailLeafs(this, param_1);
      } else {
        BuildSplit_CreateSub(this, (SBuildSplit *)&local_38, 1);
        BuildSplit_CreateSub(this, (SBuildSplit *)&local_38, 2);
        BuildSplit_CreateSub(this, (SBuildSplit *)&local_38, 0);
      }
      CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_24);
      CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_30);
    }
  }
  ExceptionList = local_c;
  return;
}

/* protected: void __thiscall GmOctreeLowMem<struct
   GmOctreeLowMemCell_i15b>::BuildSplit_CreateSub(struct GmOctreeLowMem<struct
   GmOctreeLowMemCell_i15b>::SBuildSplit &,enum GmOctreeLowMem<struct
   GmOctreeLowMemCell_i15b>::ESubLocation) */

void __thiscall GmOctreeLowMem<>::BuildSplit_CreateSub(GmOctreeLowMem<> *this,
                                                       SBuildSplit *param_1,
                                                       ESubLocation param_2)

{
  CFastBuffer<> *this_00;
  CFastArray<> *this_01;
  ulong uVar1;
  SFastCat *pSVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  ESubLocation *pEVar5;
  SDeviceMat *pSVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  uint *puVar9;
  int iVar10;
  ulong uVar11;

  this_01 = *(CFastArray<> **)(param_1 + 4);
  this_00 = (CFastBuffer<> *)(param_1 + 8);
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(param_1 + 0x14));
  if (param_2 == 0) {
    CFastBuffer<>::AllocSetCount(this_00, uVar1);
    uVar11 = 0;
    if (uVar1 != 0) {
      do {
        pSVar2 = CFastBuffer<>::operator[]((CFastBuffer<> *)(param_1 + 0x14),
                                           uVar11);
        puVar3 = (undefined4 *)CFastArray<>::operator[](this_01,
                                                        *(ulong *)(pSVar2 + 4));
        puVar4 = (undefined4 *)CFastArray<>::operator[]((CFastArray<> *)this_00,
                                                        uVar11);
        uVar11 = uVar11 + 1;
        for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
      } while (uVar11 < uVar1);
    }
  } else {
    CFastBuffer<>::Reset((CFastBuffer<> *)this_00);
    uVar11 = 0;
    if (uVar1 != 0) {
      do {
        pEVar5 = (ESubLocation *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(param_1 + 0x14), uVar11);
        if (param_2 == *pEVar5) {
          pSVar6 = CFastArray<>::operator[](this_01, pEVar5[1]);
          CFastBuffer<>::Add((CFastBuffer<> *)this_00, (SBuildInput *)pSVar6);
          CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)(param_1 + 0x14),
                                         uVar11, 1);
          uVar11 = uVar11 - 1;
          uVar1 = uVar1 - 1;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar1);
    }
  }
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_00);
  if (uVar1 != 0) {
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_00);
    if (uVar1 == 1) {
      uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
      CFastBuffer<>::AllocSetCount((CFastBuffer<> *)this, uVar1 + 2);
      puVar7 =
          (undefined2 *)CFastArray<>::operator[]((CFastArray<> *)this_00, 0);
      puVar8 =
          (undefined2 *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
      *puVar8 = *puVar7;
      return;
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
    CFastBuffer<>::AllocSetCount((CFastBuffer<> *)this, uVar1 + 0x1c);
    puVar9 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
    *puVar9 = *puVar9 | 1;
    BuildBintreeRecurse(this, (CFastBuffer<> *)this_00, *(int *)param_1 + 1);
    puVar9 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
    uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
    *puVar9 = (uVar11 - uVar1) * 2 ^ *puVar9 & 1;
  }
  return;
}

/* protected: void __thiscall GmOctreeLowMem<struct
   GmOctreeLowMemCell_i15b>::CellCopyInputAsTailLeafs(class CFastBuffer<struct
   GmOctreeLowMem<struct GmOctreeLowMemCell_i15b>::SBuildInput> const &) */

void __thiscall GmOctreeLowMem<>::CellCopyInputAsTailLeafs(
    GmOctreeLowMem<> *this, CFastBuffer<> *param_1)

{
  ulong uVar1;
  ulong uVar2;
  SSkinIndex *pSVar3;
  undefined2 *puVar4;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)param_1);
  uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
  CFastBuffer<>::AllocSetCount((CFastBuffer<> *)this, uVar2 + uVar1 * 2);
  pSVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar2);
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      puVar4 = (undefined2 *)CFastArray<>::operator[]((CFastArray<> *)param_1,
                                                      uVar2);
      *(undefined2 *)(pSVar3 + uVar2 * 2) = *puVar4;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

/* public: int __thiscall GmOctreeLowMem<struct
   GmOctreeLowMemCell_i15b>::GetAllUserDatas_InterBBox_AreAllIncluded(class
   CFastBuffer<unsigned long> &,class GmBoxAligned const &) */

int __thiscall GmOctreeLowMem<>::GetAllUserDatas_InterBBox_AreAllIncluded(
    GmOctreeLowMem<> *this, CFastBuffer<> *param_1, GmBoxAligned *param_2)

{
  ulong uVar1;
  SSkinIndex *pSVar2;
  uint *puVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  uint local_8;
  CDx9TextureKeeper *local_4;

  CFastBuffer<>::Reset((CFastBuffer<> *)param_1);
  uVar6 = 0;
  local_8 = 0;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
  if (uVar1 != 0) {
    do {
      pSVar2 = CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar6);
      if (((byte)*pSVar2 & 1) == 0) {
        puVar5 =
            (ushort *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar6);
        local_4 = (CDx9TextureKeeper *)(uint)(*puVar5 >> 1);
        CFastBuffer<>::Add((CFastBuffer<> *)param_1, &local_4);
        uVar6 = uVar6 + 2;
      } else {
        puVar3 =
            (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar6);
        if (uVar6 < local_8) {
          uVar6 = uVar6 + 0x1c;
        } else {
          iVar4 =
              GmBoxAligned::TestInter((GmBoxAligned *)(puVar3 + 1), param_2);
          if (iVar4 == 0) {
            uVar6 = uVar6 + (*puVar3 >> 1);
          } else {
            iVar4 =
                GmBoxAligned::IsIncluded((GmBoxAligned *)(puVar3 + 1), param_2);
            if (iVar4 != 0) {
              if (uVar6 == 0) {
                return 1;
              }
              local_8 = (*puVar3 >> 1) + uVar6;
            }
            uVar6 = uVar6 + 0x1c;
          }
        }
      }
      uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
    } while (uVar6 < uVar1);
  }
  return 0;
}
