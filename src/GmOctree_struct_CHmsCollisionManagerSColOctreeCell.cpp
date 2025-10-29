
/* public: void __thiscall GmOctree<struct
   CHmsCollisionManager::SColOctreeCell>::Build(unsigned long,struct
   CHmsCollisionManager::SColOctreeCell *,int,unsigned long,unsigned long,float)
 */

void __thiscall GmOctree<>::Build(GmOctree<> *this, ulong param_1,
                                  SColOctreeCell *param_2, int param_3,
                                  ulong param_4, ulong param_5, float param_6)

{
  SColOctreeCell *pSVar1;
  ulong *puVar2;
  ulong uVar3;

  CFastBuffer<>::Reset((CFastBuffer<> *)this);
  pSVar1 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
  *(undefined4 *)(pSVar1 + 0x4c) = 0;
  if (param_3 == 0) {
    BuildOctreeRecurse(this, param_1, param_2);
  } else {
    BuildBintreeRecurse(this, param_1, param_2, 0, param_4, param_5, param_6);
  }
  puVar2 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, 0);
  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
  *puVar2 = uVar3;
  return;
}

/* public: unsigned long __thiscall GmOctree<struct
   CHmsCollisionManager::SColOctreeCell>::BuildBintreeRecurse(unsigned
   long,struct CHmsCollisionManager::SColOctreeCell *,unsigned long,unsigned
   long,unsigned long,float) */

ulong __thiscall GmOctree<>::BuildBintreeRecurse(GmOctree<> *this,
                                                 ulong param_1,
                                                 SColOctreeCell *param_2,
                                                 ulong param_3, ulong param_4,
                                                 ulong param_5, float param_6)

{
  bool bVar1;
  float fVar2;
  ulong uVar3;
  SColOctreeCell *pSVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  SFastCat *pSVar10;
  ulong *puVar11;
  int iVar12;
  uint uVar13;
  GmBoxAligned *pGVar14;
  ulong uVar15;
  undefined4 *puVar16;
  float *pfVar17;
  float fVar18;
  ulong local_54;
  float local_50;
  float local_48;
  SColOctreeCell *local_44;
  float local_40;
  float local_3c[3];
  float local_30[4];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puVar6 = (undefined4 *)param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a95580;
  local_c = ExceptionList;
  if (param_1 == 0) {
    return 0;
  }
  local_30[3] = *(float *)(param_2 + 4);
  local_20 = *(float *)(param_2 + 8);
  local_1c = *(float *)(param_2 + 0xc);
  local_18 = *(float *)(param_2 + 0x10);
  local_14 = *(float *)(param_2 + 0x14);
  local_10 = *(float *)(param_2 + 0x18);
  ExceptionList = &local_c;
  if (1 < param_1) {
    local_50 = (float)(param_1 - 1);
    pGVar14 = (GmBoxAligned *)(param_2 + 0x5c);
    do {
      GmBoxAligned::Union((GmBoxAligned *)(local_30 + 3), pGVar14);
      pGVar14 = pGVar14 + 0x58;
      local_50 = (float)((int)local_50 + -1);
    } while (local_50 != 0.0);
  }
  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
  uVar15 = 0;
  if (uVar3 != 0) {
    pSVar4 = CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar3 - 1);
    *(float *)(pSVar4 + 4) = local_30[3];
    *(float *)(pSVar4 + 8) = local_20;
    *(float *)(pSVar4 + 0xc) = local_1c;
    *(float *)(pSVar4 + 0x10) = local_18;
    *(float *)(pSVar4 + 0x14) = local_14;
    *(float *)(pSVar4 + 0x18) = local_10;
  }
  local_54 = 1;
  if (((param_4 == 0) || (param_3 < param_4)) &&
      ((param_5 == 0 || (param_5 < param_1)))) {
    if (1e-05 < param_6) {
      local_3c[0] = local_18 * 2.0;
      local_30[1] = local_14 * 2.0;
      local_40 = local_10 * 2.0;
      fVar18 = local_30[1] * local_3c[0] * local_40;
      if (fVar18 < param_6 != (NAN(fVar18) || NAN(param_6)))
        goto LAB_0053932f;
    }
    fVar18 = local_10 * local_10 + local_14 * local_14 + local_18 * local_18;
    if (NAN(fVar18) == (fVar18 == 0.0)) {
      CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)local_3c);
      local_4 = 0;
      CFastBuffer<>::AllocSetCount((CFastBuffer<> *)local_3c, param_1);
      if (param_1 != 0) {
        do {
          puVar6 = (undefined4 *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)local_3c, uVar15);
          *puVar6 = 0;
          puVar6[1] = uVar15;
          uVar15 = uVar15 + 1;
        } while (uVar15 < param_1);
      }
      local_50 = (local_30[3] + local_18) - (local_30[3] - local_18);
      fVar18 = (local_20 + local_14) -
               (float)(SColOctreeCell *)(local_20 - local_14);
      bVar1 = local_50 < fVar18 != (NAN(local_50) || NAN(fVar18));
      if (bVar1) {
        local_50 = fVar18;
      }
      uVar13 = (uint)bVar1;
      fVar18 = (local_1c + local_10) - (local_1c - local_10);
      if (local_50 < fVar18 != (NAN(local_50) || NAN(fVar18))) {
        uVar13 = 2;
      }
      uVar3 = 0;
      local_30[0] = local_30[3] + local_18;
      local_30[1] = local_20 + local_14;
      local_30[2] = local_1c + local_10;
      local_48 = local_30[3] - local_18;
      local_44 = (SColOctreeCell *)(local_20 - local_14);
      local_40 = local_1c - local_10;
      fVar18 = ((&local_48)[uVar13] + local_30[uVar13]) * 0.5;
      if (param_1 != 0) {
        pfVar17 = (float *)(param_2 + 0xc);
        do {
          local_30[0] = pfVar17[-2];
          local_30[1] = pfVar17[-1];
          local_30[2] = *pfVar17;
          local_48 = pfVar17[1];
          local_44 = (SColOctreeCell *)pfVar17[2];
          local_40 = pfVar17[3];
          fVar2 = (&local_48)[uVar13] + local_30[uVar13];
          if (fVar2 < fVar18 == (fVar2 == fVar18)) {
            if (fVar18 <= local_30[uVar13] - (&local_48)[uVar13]) {
              puVar7 = (uint *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)local_3c, uVar3);
              *puVar7 = *puVar7 | 2;
            }
          } else {
            puVar7 = (uint *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)local_3c, uVar3);
            *puVar7 = *puVar7 | 1;
          }
          uVar3 = uVar3 + 1;
          pfVar17 = pfVar17 + 0x16;
        } while (uVar3 < param_1);
      }
      CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)&local_48);
      local_4 = CONCAT31(local_4._1_3_, 1);
      CFastBuffer<>::Reset((CFastBuffer<> *)&local_48);
      fVar18 = 0.0;
      if (local_3c[0] != 0.0) {
        do {
          piVar8 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_3c,
                                                    (ulong)fVar18);
          if (*piVar8 == 1) {
            CFastBuffer<>::Add((CFastBuffer<> *)&local_48,
                               param_2 + piVar8[1] * 0x58);
            CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_3c,
                                           (ulong)fVar18, 1);
          } else {
            fVar18 = (float)((int)fVar18 + 1);
          }
        } while ((uint)fVar18 < (uint)local_3c[0]);
      }
      uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_48);
      if (uVar3 != 0) {
        if (uVar3 == 1) {
          puVar9 =
              (undefined4 *)CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
          puVar6 = (undefined4 *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)&local_48, 0);
          puVar16 = puVar9;
          for (iVar12 = 0x16; iVar12 != 0; iVar12 = iVar12 + -1) {
            *puVar16 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar16 = puVar16 + 1;
          }
          *puVar9 = 1;
          local_54 = 2;
        } else {
          uVar3 = *(ulong *)this;
          pSVar4 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
          *(undefined4 *)(pSVar4 + 0x4c) = 0;
          local_54 =
              BuildBintreeRecurse(this, (ulong)local_48, local_44, param_3 + 1,
                                  param_4, param_5, param_6);
          puVar11 =
              (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar3);
          *puVar11 = local_54;
          local_54 = local_54 + 1;
        }
      }
      CFastBuffer<>::Reset((CFastBuffer<> *)&local_48);
      fVar18 = 0.0;
      if (local_3c[0] != 0.0) {
        do {
          piVar8 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_3c,
                                                    (ulong)fVar18);
          if (*piVar8 == 2) {
            CFastBuffer<>::Add((CFastBuffer<> *)&local_48,
                               param_2 + piVar8[1] * 0x58);
            CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_3c,
                                           (ulong)fVar18, 1);
          } else {
            fVar18 = (float)((int)fVar18 + 1);
          }
        } while ((uint)fVar18 < (uint)local_3c[0]);
      }
      uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_48);
      if (uVar3 != 0) {
        if (uVar3 == 1) {
          puVar9 =
              (undefined4 *)CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
          puVar6 = (undefined4 *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)&local_48, 0);
          local_54 = local_54 + 1;
          puVar16 = puVar9;
          for (iVar12 = 0x16; iVar12 != 0; iVar12 = iVar12 + -1) {
            *puVar16 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar16 = puVar16 + 1;
          }
          *puVar9 = 1;
        } else {
          uVar3 = *(ulong *)this;
          pSVar4 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
          *(undefined4 *)(pSVar4 + 0x4c) = 0;
          uVar15 = BuildBintreeRecurse(this, (ulong)local_48, local_44,
                                       param_3 + 1, param_4, param_5, param_6);
          puVar11 =
              (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar3);
          local_54 = local_54 + uVar15;
          *puVar11 = uVar15;
        }
      }
      uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_3c);
      if ((uVar3 == param_1) || (uVar3 < 2)) {
        param_1 = 0;
        if (uVar3 != 0) {
          local_54 = local_54 + uVar3;
          do {
            puVar9 =
                (undefined4 *)CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
            pSVar10 =
                CFastBuffer<>::operator[]((CFastBuffer<> *)local_3c, param_1);
            puVar6 = (undefined4 *)(param_2 + *(int *)(pSVar10 + 4) * 0x58);
            puVar16 = puVar9;
            for (iVar12 = 0x16; iVar12 != 0; iVar12 = iVar12 + -1) {
              *puVar16 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar16 = puVar16 + 1;
            }
            param_1 = param_1 + 1;
            *puVar9 = 1;
          } while (param_1 < uVar3);
        }
      } else {
        CFastBuffer<>::Reset((CFastBuffer<> *)&local_48);
        uVar15 = 0;
        if (uVar3 != 0) {
          do {
            pSVar10 =
                CFastBuffer<>::operator[]((CFastBuffer<> *)local_3c, uVar15);
            CFastBuffer<>::Add((CFastBuffer<> *)&local_48,
                               param_2 + *(int *)(pSVar10 + 4) * 0x58);
            uVar15 = uVar15 + 1;
          } while (uVar15 < uVar3);
        }
        uVar15 = *(ulong *)this;
        pSVar4 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
        *(undefined4 *)(pSVar4 + 0x4c) = 0;
        uVar3 = BuildBintreeRecurse(this, uVar3, local_44, param_3 + 1, param_4,
                                    param_5, param_6);
        puVar11 =
            (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar15);
        local_54 = local_54 + uVar3;
        *puVar11 = uVar3;
      }
      CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)&local_48);
      CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_3c);
      ExceptionList = local_c;
      return local_54;
    }
  }
LAB_0053932f:
  if (param_1 != 0) {
    param_2 = (SColOctreeCell *)param_1;
    local_54 = param_1 + 1;
    do {
      puVar5 = (undefined4 *)CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
      param_2 = param_2 + -1;
      puVar16 = puVar6;
      puVar9 = puVar5;
      for (iVar12 = 0x16; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar9 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar9 = puVar9 + 1;
      }
      *puVar5 = 1;
      puVar6 = puVar6 + 0x16;
    } while (param_2 != (SColOctreeCell *)0x0);
  }
  ExceptionList = local_c;
  return local_54;
}

/* public: unsigned long __thiscall GmOctree<struct
   CHmsCollisionManager::SColOctreeCell>::BuildOctreeRecurse(unsigned
   long,struct CHmsCollisionManager::SColOctreeCell *) */

ulong __thiscall GmOctree<>::BuildOctreeRecurse(GmOctree<> *this, ulong param_1,
                                                SColOctreeCell *param_2)

{
  ulong uVar1;
  SColOctreeCell *pSVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int *piVar5;
  ulong *puVar6;
  ulong uVar7;
  undefined4 *puVar8;
  SFastCat *pSVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  GmBoxAligned *pGVar13;
  undefined4 *puVar14;
  ulong local_84;
  float local_78;
  SColOctreeCell *local_74;
  float local_70;
  uint local_6c[3];
  float local_60;
  float local_58;
  float local_50;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  SColOctreeCell *local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a95540;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 == 0) {
    local_84 = 0;
  } else {
    local_24 = *(float *)(param_2 + 4);
    local_20 = *(SColOctreeCell **)(param_2 + 8);
    local_1c = *(float *)(param_2 + 0xc);
    local_18 = *(float *)(param_2 + 0x10);
    local_14 = *(float *)(param_2 + 0x14);
    local_10 = *(float *)(param_2 + 0x18);
    if (1 < param_1) {
      pGVar13 = (GmBoxAligned *)(param_2 + 0x5c);
      iVar10 = param_1 - 1;
      do {
        GmBoxAligned::Union((GmBoxAligned *)&local_24, pGVar13);
        pGVar13 = pGVar13 + 0x58;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
    if (uVar1 != 0) {
      pSVar2 = CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1 - 1);
      *(float *)(pSVar2 + 4) = local_24;
      *(SColOctreeCell **)(pSVar2 + 8) = local_20;
      *(float *)(pSVar2 + 0xc) = local_1c;
      *(float *)(pSVar2 + 0x10) = local_18;
      *(float *)(pSVar2 + 0x14) = local_14;
      *(float *)(pSVar2 + 0x18) = local_10;
    }
    local_78 = local_24;
    local_74 = local_20;
    local_70 = local_1c;
    CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)local_6c);
    local_4 = 0;
    CFastBuffer<>::AllocSetCount((CFastBuffer<> *)local_6c, param_1);
    uVar1 = 0;
    if (param_1 != 0) {
      do {
        puVar3 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)local_6c, uVar1);
        *puVar3 = 0;
        puVar3[1] = uVar1;
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_1);
    }
    uVar1 = 0;
    local_40 = local_1c - local_10;
    local_50 = (float)local_20 - local_14;
    local_60 = local_24 - local_18;
    local_3c = (local_78 + local_60) * 0.5;
    local_38 = ((float)local_74 + local_50) * 0.5;
    local_34 = (local_70 + local_40) * 0.5;
    local_30 = (local_78 - local_60) * 0.5;
    local_2c = ((float)local_74 - local_50) * 0.5;
    local_28 = (local_70 - local_40) * 0.5;
    if (param_1 != 0) {
      pGVar13 = (GmBoxAligned *)(param_2 + 4);
      do {
        iVar10 = GmBoxAligned::TestInter(pGVar13, (GmBoxAligned *)&local_3c);
        if (iVar10 != 0) {
          puVar4 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c,
                                                     uVar1);
          *puVar4 = *puVar4 | 1;
        }
        uVar1 = uVar1 + 1;
        pGVar13 = pGVar13 + 0x58;
      } while (uVar1 < param_1);
    }
    uVar1 = 0;
    local_58 = local_10 + local_1c;
    local_50 = (float)local_20 - local_14;
    local_48 = local_24 - local_18;
    local_3c = (local_48 + local_78) * 0.5;
    local_38 = (local_50 + (float)local_74) * 0.5;
    local_34 = (local_58 + local_70) * 0.5;
    local_30 = (local_78 - local_48) * 0.5;
    local_2c = ((float)local_74 - local_50) * 0.5;
    local_28 = (local_58 - local_70) * 0.5;
    if (param_1 != 0) {
      pGVar13 = (GmBoxAligned *)(param_2 + 4);
      do {
        iVar10 = GmBoxAligned::TestInter(pGVar13, (GmBoxAligned *)&local_3c);
        if (iVar10 != 0) {
          puVar4 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c,
                                                     uVar1);
          *puVar4 = *puVar4 | 2;
        }
        uVar1 = uVar1 + 1;
        pGVar13 = pGVar13 + 0x58;
      } while (uVar1 < param_1);
    }
    uVar1 = 0;
    local_50 = local_14 + (float)local_20;
    local_58 = local_1c - local_10;
    local_48 = local_24 - local_18;
    local_3c = (local_48 + local_78) * 0.5;
    local_38 = (local_50 + (float)local_74) * 0.5;
    local_34 = (local_58 + local_70) * 0.5;
    local_30 = (local_78 - local_48) * 0.5;
    local_2c = (local_50 - (float)local_74) * 0.5;
    local_28 = (local_70 - local_58) * 0.5;
    if (param_1 != 0) {
      pGVar13 = (GmBoxAligned *)(param_2 + 4);
      do {
        iVar10 = GmBoxAligned::TestInter(pGVar13, (GmBoxAligned *)&local_3c);
        if (iVar10 != 0) {
          puVar4 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c,
                                                     uVar1);
          *puVar4 = *puVar4 | 4;
        }
        uVar1 = uVar1 + 1;
        pGVar13 = pGVar13 + 0x58;
      } while (uVar1 < param_1);
    }
    uVar1 = 0;
    local_58 = local_10 + local_1c;
    local_50 = local_14 + (float)local_20;
    local_48 = local_24 - local_18;
    local_3c = (local_48 + local_78) * 0.5;
    local_38 = (local_50 + (float)local_74) * 0.5;
    local_34 = (local_58 + local_70) * 0.5;
    local_30 = (local_78 - local_48) * 0.5;
    local_2c = (local_50 - (float)local_74) * 0.5;
    local_28 = (local_58 - local_70) * 0.5;
    if (param_1 != 0) {
      pGVar13 = (GmBoxAligned *)(param_2 + 4);
      do {
        iVar10 = GmBoxAligned::TestInter(pGVar13, (GmBoxAligned *)&local_3c);
        if (iVar10 != 0) {
          puVar4 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c,
                                                     uVar1);
          *puVar4 = *puVar4 | 8;
        }
        uVar1 = uVar1 + 1;
        pGVar13 = pGVar13 + 0x58;
      } while (uVar1 < param_1);
    }
    uVar1 = 0;
    local_48 = local_18 + local_24;
    local_58 = local_1c - local_10;
    local_50 = (float)local_20 - local_14;
    local_3c = (local_48 + local_78) * 0.5;
    local_38 = (local_50 + (float)local_74) * 0.5;
    local_34 = (local_58 + local_70) * 0.5;
    local_30 = (local_48 - local_78) * 0.5;
    local_2c = ((float)local_74 - local_50) * 0.5;
    local_28 = (local_70 - local_58) * 0.5;
    if (param_1 != 0) {
      pGVar13 = (GmBoxAligned *)(param_2 + 4);
      do {
        iVar10 = GmBoxAligned::TestInter(pGVar13, (GmBoxAligned *)&local_3c);
        if (iVar10 != 0) {
          puVar4 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c,
                                                     uVar1);
          *puVar4 = *puVar4 | 0x10;
        }
        uVar1 = uVar1 + 1;
        pGVar13 = pGVar13 + 0x58;
      } while (uVar1 < param_1);
    }
    uVar1 = 0;
    local_58 = local_10 + local_1c;
    local_48 = local_18 + local_24;
    local_50 = (float)local_20 - local_14;
    local_3c = (local_48 + local_78) * 0.5;
    local_38 = (local_50 + (float)local_74) * 0.5;
    local_34 = (local_58 + local_70) * 0.5;
    local_30 = (local_48 - local_78) * 0.5;
    local_2c = ((float)local_74 - local_50) * 0.5;
    local_28 = (local_58 - local_70) * 0.5;
    if (param_1 != 0) {
      pGVar13 = (GmBoxAligned *)(param_2 + 4);
      do {
        iVar10 = GmBoxAligned::TestInter(pGVar13, (GmBoxAligned *)&local_3c);
        if (iVar10 != 0) {
          puVar4 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c,
                                                     uVar1);
          *puVar4 = *puVar4 | 0x20;
        }
        uVar1 = uVar1 + 1;
        pGVar13 = pGVar13 + 0x58;
      } while (uVar1 < param_1);
    }
    uVar1 = 0;
    local_50 = local_14 + (float)local_20;
    local_48 = local_18 + local_24;
    local_58 = local_1c - local_10;
    local_3c = (local_48 + local_78) * 0.5;
    local_38 = (local_50 + (float)local_74) * 0.5;
    local_34 = (local_58 + local_70) * 0.5;
    local_30 = (local_48 - local_78) * 0.5;
    local_2c = (local_50 - (float)local_74) * 0.5;
    local_28 = (local_70 - local_58) * 0.5;
    if (param_1 != 0) {
      pGVar13 = (GmBoxAligned *)(param_2 + 4);
      do {
        iVar10 = GmBoxAligned::TestInter(pGVar13, (GmBoxAligned *)&local_3c);
        if (iVar10 != 0) {
          puVar4 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c,
                                                     uVar1);
          *puVar4 = *puVar4 | 0x40;
        }
        uVar1 = uVar1 + 1;
        pGVar13 = pGVar13 + 0x58;
      } while (uVar1 < param_1);
    }
    uVar1 = 0;
    local_58 = local_10 + local_1c;
    local_50 = local_14 + (float)local_20;
    local_48 = local_18 + local_24;
    local_3c = (local_48 + local_78) * 0.5;
    local_38 = (local_50 + (float)local_74) * 0.5;
    local_34 = (local_58 + local_70) * 0.5;
    local_30 = (local_48 - local_78) * 0.5;
    local_2c = (local_50 - (float)local_74) * 0.5;
    local_28 = (local_58 - local_70) * 0.5;
    if (param_1 != 0) {
      pGVar13 = (GmBoxAligned *)(param_2 + 4);
      do {
        iVar10 = GmBoxAligned::TestInter(pGVar13, (GmBoxAligned *)&local_3c);
        if (iVar10 != 0) {
          puVar4 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c,
                                                     uVar1);
          *puVar4 = *puVar4 | 0x80;
        }
        uVar1 = uVar1 + 1;
        pGVar13 = pGVar13 + 0x58;
      } while (uVar1 < param_1);
    }
    CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)&local_78);
    local_4 = CONCAT31(local_4._1_3_, 1);
    local_84 = 1;
    CFastBuffer<>::Reset((CFastBuffer<> *)&local_78);
    uVar12 = 0;
    uVar11 = local_6c[0];
    if (local_6c[0] != 0) {
      do {
        piVar5 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c, uVar12);
        if (*piVar5 == 1) {
          CFastBuffer<>::Add((CFastBuffer<> *)&local_78,
                             param_2 + piVar5[1] * 0x58);
          CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_6c, uVar12, 1);
          uVar11 = local_6c[0];
        } else {
          uVar12 = uVar12 + 1;
        }
      } while (uVar12 < uVar11);
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_78);
    if (uVar1 != 0) {
      uVar1 = *(ulong *)this;
      pSVar2 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
      *(undefined4 *)(pSVar2 + 0x4c) = 0;
      local_84 = BuildOctreeRecurse(this, (ulong)local_78, local_74);
      puVar6 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
      *puVar6 = local_84;
      local_84 = local_84 + 1;
    }
    CFastBuffer<>::Reset((CFastBuffer<> *)&local_78);
    uVar12 = 0;
    if (uVar11 != 0) {
      do {
        piVar5 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c, uVar12);
        if (*piVar5 == 2) {
          CFastBuffer<>::Add((CFastBuffer<> *)&local_78,
                             param_2 + piVar5[1] * 0x58);
          CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_6c, uVar12, 1);
          uVar11 = local_6c[0];
        } else {
          uVar12 = uVar12 + 1;
        }
      } while (uVar12 < uVar11);
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_78);
    if (uVar1 != 0) {
      uVar1 = *(ulong *)this;
      pSVar2 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
      *(undefined4 *)(pSVar2 + 0x4c) = 0;
      uVar7 = BuildOctreeRecurse(this, (ulong)local_78, local_74);
      puVar6 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
      local_84 = local_84 + uVar7;
      *puVar6 = uVar7;
    }
    CFastBuffer<>::Reset((CFastBuffer<> *)&local_78);
    uVar12 = 0;
    if (uVar11 != 0) {
      do {
        piVar5 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c, uVar12);
        if (*piVar5 == 4) {
          CFastBuffer<>::Add((CFastBuffer<> *)&local_78,
                             param_2 + piVar5[1] * 0x58);
          CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_6c, uVar12, 1);
          uVar11 = local_6c[0];
        } else {
          uVar12 = uVar12 + 1;
        }
      } while (uVar12 < uVar11);
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_78);
    if (uVar1 != 0) {
      uVar1 = *(ulong *)this;
      pSVar2 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
      *(undefined4 *)(pSVar2 + 0x4c) = 0;
      uVar7 = BuildOctreeRecurse(this, (ulong)local_78, local_74);
      puVar6 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
      local_84 = local_84 + uVar7;
      *puVar6 = uVar7;
    }
    CFastBuffer<>::Reset((CFastBuffer<> *)&local_78);
    uVar12 = 0;
    if (uVar11 != 0) {
      do {
        piVar5 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c, uVar12);
        if (*piVar5 == 8) {
          CFastBuffer<>::Add((CFastBuffer<> *)&local_78,
                             param_2 + piVar5[1] * 0x58);
          CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_6c, uVar12, 1);
          uVar11 = local_6c[0];
        } else {
          uVar12 = uVar12 + 1;
        }
      } while (uVar12 < uVar11);
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_78);
    if (uVar1 != 0) {
      uVar1 = *(ulong *)this;
      pSVar2 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
      *(undefined4 *)(pSVar2 + 0x4c) = 0;
      uVar7 = BuildOctreeRecurse(this, (ulong)local_78, local_74);
      puVar6 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
      local_84 = local_84 + uVar7;
      *puVar6 = uVar7;
    }
    CFastBuffer<>::Reset((CFastBuffer<> *)&local_78);
    uVar12 = 0;
    if (uVar11 != 0) {
      do {
        piVar5 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c, uVar12);
        if (*piVar5 == 0x10) {
          CFastBuffer<>::Add((CFastBuffer<> *)&local_78,
                             param_2 + piVar5[1] * 0x58);
          CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_6c, uVar12, 1);
          uVar11 = local_6c[0];
        } else {
          uVar12 = uVar12 + 1;
        }
      } while (uVar12 < uVar11);
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_78);
    if (uVar1 != 0) {
      uVar1 = *(ulong *)this;
      pSVar2 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
      *(undefined4 *)(pSVar2 + 0x4c) = 0;
      uVar7 = BuildOctreeRecurse(this, (ulong)local_78, local_74);
      puVar6 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
      local_84 = local_84 + uVar7;
      *puVar6 = uVar7;
    }
    CFastBuffer<>::Reset((CFastBuffer<> *)&local_78);
    uVar12 = 0;
    if (uVar11 != 0) {
      do {
        piVar5 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c, uVar12);
        if (*piVar5 == 0x20) {
          CFastBuffer<>::Add((CFastBuffer<> *)&local_78,
                             param_2 + piVar5[1] * 0x58);
          CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_6c, uVar12, 1);
          uVar11 = local_6c[0];
        } else {
          uVar12 = uVar12 + 1;
        }
      } while (uVar12 < uVar11);
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_78);
    if (uVar1 != 0) {
      uVar1 = *(ulong *)this;
      pSVar2 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
      *(undefined4 *)(pSVar2 + 0x4c) = 0;
      uVar7 = BuildOctreeRecurse(this, (ulong)local_78, local_74);
      puVar6 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
      local_84 = local_84 + uVar7;
      *puVar6 = uVar7;
    }
    CFastBuffer<>::Reset((CFastBuffer<> *)&local_78);
    uVar12 = 0;
    if (uVar11 != 0) {
      do {
        piVar5 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c, uVar12);
        if (*piVar5 == 0x40) {
          CFastBuffer<>::Add((CFastBuffer<> *)&local_78,
                             param_2 + piVar5[1] * 0x58);
          CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_6c, uVar12, 1);
          uVar11 = local_6c[0];
        } else {
          uVar12 = uVar12 + 1;
        }
      } while (uVar12 < uVar11);
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_78);
    if (uVar1 != 0) {
      uVar1 = *(ulong *)this;
      pSVar2 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
      *(undefined4 *)(pSVar2 + 0x4c) = 0;
      uVar7 = BuildOctreeRecurse(this, (ulong)local_78, local_74);
      puVar6 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
      local_84 = local_84 + uVar7;
      *puVar6 = uVar7;
    }
    CFastBuffer<>::Reset((CFastBuffer<> *)&local_78);
    uVar12 = 0;
    if (uVar11 != 0) {
      do {
        piVar5 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c, uVar12);
        if (*piVar5 == 0x80) {
          CFastBuffer<>::Add((CFastBuffer<> *)&local_78,
                             param_2 + piVar5[1] * 0x58);
          CFastBuffer<>::ReplaceByLastAt((CFastBuffer<> *)local_6c, uVar12, 1);
          uVar11 = local_6c[0];
        } else {
          uVar12 = uVar12 + 1;
        }
      } while (uVar12 < uVar11);
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)&local_78);
    if (uVar1 != 0) {
      uVar1 = *(ulong *)this;
      pSVar2 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
      *(undefined4 *)(pSVar2 + 0x4c) = 0;
      uVar7 = BuildOctreeRecurse(this, (ulong)local_78, local_74);
      puVar6 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)this, uVar1);
      local_84 = local_84 + uVar7;
      *puVar6 = uVar7;
    }
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_6c);
    uVar7 = 0;
    if (uVar1 != 0) {
      local_84 = local_84 + uVar1;
      do {
        puVar8 = (undefined4 *)CFastBuffer<>::AddNewElem((CFastBuffer<> *)this);
        pSVar9 = CFastBuffer<>::operator[]((CFastBuffer<> *)local_6c, uVar7);
        uVar7 = uVar7 + 1;
        puVar3 = (undefined4 *)(param_2 + *(int *)(pSVar9 + 4) * 0x58);
        puVar14 = puVar8;
        for (iVar10 = 0x16; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar14 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar14 = puVar14 + 1;
        }
        *puVar8 = 1;
      } while (uVar7 < uVar1);
    }
    CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)&local_78);
    CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_6c);
  }
  ExceptionList = local_c;
  return local_84;
}
