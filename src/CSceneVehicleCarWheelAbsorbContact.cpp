
/* protected: void __thiscall CSceneVehicleCar::WheelAbsorbContact(struct
   CSceneVehicleCar::SSimulationWheel &,class CHmsPhysicalContact &) */

void __thiscall CSceneVehicleCar::WheelAbsorbContact(
    CSceneVehicleCar *this, SSimulationWheel *param_1,
    CHmsPhysicalContact *param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  CHmsPhysicalContact *pCVar4;
  CHmsPhysicalContact *pCVar5;
  float fVar6;
  bool bVar7;
  CHmsPhysicalContact *pCVar8;
  uint uVar9;
  int iVar10;
  int **ppiVar11;
  GmMat3 *pGVar12;
  int *piVar13;
  undefined4 in_EDX;
  float10 fVar14;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  CHmsPhysicalContact *pCStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;

  pCVar8 = param_2;
  fVar3 = *(float *)(param_2 + 0xc);
  pfVar1 = (float *)(param_2 + 0xc);
  fVar14 = (float10)__CIsin((float10 *)this, in_EDX);
  uVar9 = (uint)(ABS(fVar3) < (float)fVar14 !=
                 (NAN(ABS(fVar3)) || NAN((float)fVar14)));
  *(uint *)(param_1 + 0x124) = uVar9;
  if (uVar9 == 0) {
    *(undefined4 *)(this + 0x5dc) = 1;
    *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_2 + 0x18);
    *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_2 + 0x20);
    *(undefined4 *)(param_1 + 0x15c) = 1;
  }
  if (*(int *)(param_1 + 0x124) != 0) {
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 1;
    *(float *)(param_1 + 0x144) = *(float *)(param_1 + 0x144) + *pfVar1;
    *(float *)(param_1 + 0x148) =
        *(float *)(param_2 + 0x10) + *(float *)(param_1 + 0x148);
    *(float *)(param_1 + 0x14c) =
        *(float *)(param_2 + 0x14) + *(float *)(param_1 + 0x14c);
    *(undefined2 *)(param_1 + 0x128) = *(undefined2 *)(param_2 + 0x48);
  }
  *(undefined4 *)(param_2 + 0x3c) = 0;
  if (*(int **)(param_2 + 0x40) != (int *)0x0) {
    iVar10 = (**(code **)(**(int **)(param_2 + 0x40) + 0x78))();
    fStack_18 = *(float *)(iVar10 + 8);
    pCStack_14 = *(CHmsPhysicalContact **)(iVar10 + 0x14);
    fStack_10 = *(float *)(iVar10 + 0x20);
    *(float *)(param_1 + 0x130) = fStack_18;
    *(CHmsPhysicalContact **)(param_1 + 0x134) = pCStack_14;
    *(float *)(param_1 + 0x138) = fStack_10;
    *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_2 + 0x40);
    ppiVar11 = (int **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
    pGVar12 = (GmMat3 *)(**(code **)(**ppiVar11 + 0x78))();
    GmVec3::MultTranspose((GmVec3 *)(param_1 + 0x130), pGVar12);
  }
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_2 + 0x18);
  pfVar2 = (float *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_2 + 0x20);
  piVar13 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  if (*(int *)(*piVar13 + 0x350) == 2) {
    pCVar5 = (CHmsPhysicalContact *)(*(float *)(param_2 + 0x38) * 0.0 +
                                     *(float *)(param_2 + 0x34) +
                                     *(float *)(param_2 + 0x30) * 0.0);
    if (0.0 < (float)pCVar5 == NAN((float)pCVar5)) {
      bVar7 = true;
    } else {
      piVar13 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      fVar3 = *(float *)(*piVar13 + 0x11c);
      bVar7 = false;
      if ((fVar3 < -1e-05 == NAN(fVar3)) &&
          ((float)(CHmsPhysicalContact *)(*(float *)(param_1 + 0xb4) - fVar3) <=
           (float)pCVar5)) {
        bVar7 = true;
        pCVar5 = (CHmsPhysicalContact *)(*(float *)(param_1 + 0xb4) - fVar3);
      }
      pCVar4 = *(CHmsPhysicalContact **)(param_1 + 0xbc);
      param_2 = pCVar5;
      if ((float)pCVar5 < (float)pCVar4 != ((float)pCVar5 == (float)pCVar4)) {
        param_2 = pCVar4;
      }
      *(CHmsPhysicalContact **)(param_1 + 0xbc) = param_2;
      fStack_18 = (float)pCVar5 * 0.0;
      *(float *)(pCVar8 + 0x30) = *(float *)(pCVar8 + 0x30) - fStack_18;
      *(float *)(pCVar8 + 0x34) = *(float *)(pCVar8 + 0x34) - (float)pCVar5;
      *(float *)(pCVar8 + 0x38) = *(float *)(pCVar8 + 0x38) - fStack_18;
      pCStack_14 = pCVar5;
      fStack_10 = fStack_18;
    }
    if (*(int *)(param_1 + 0x124) == 0) {
      if (*(short *)(pCVar8 + 0x48) == 4) {
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
            *(ulong *)(*(int *)(this + 100) + 0x24));
        fVar3 = *(float *)(*piVar13 + 0x178);
      } else {
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
            *(ulong *)(*(int *)(this + 100) + 0x24));
        fVar3 = *(float *)(*piVar13 + 0x17c);
      }
      fVar6 = *(float *)(pCVar8 + 0x14) * *(float *)(pCVar8 + 0x2c) +
              *pfVar1 * *(float *)(pCVar8 + 0x24) +
              *(float *)(pCVar8 + 0x10) * *(float *)(pCVar8 + 0x28);
      if (fVar6 < 0.0 != NAN(fVar6)) {
        fStack_18 = *pfVar2;
        iVar10 = *(int *)(*(int *)(this + 0x28) + 0x14);
        fStack_10 = *(float *)(pCVar8 + 0x20);
        fStack_30 = *pfVar1;
        fStack_2c = *(float *)(pCVar8 + 0x10);
        pCStack_14 = *(CHmsPhysicalContact **)(iVar10 + 0x54);
        fStack_28 = *(float *)(pCVar8 + 0x14);
        fStack_c = fStack_18 - *(float *)(iVar10 + 0x50);
        fStack_8 = (float)pCStack_14 - *(float *)(iVar10 + 0x54);
        fStack_4 = fStack_10 - *(float *)(iVar10 + 0x58);
        SDynaMath::ComputeImpulse(
            *(float *)(iVar10 + 0x18), (GmMat3 *)(iVar10 + 0x1c), -fVar3,
            (GmVec3 *)(pCVar8 + 0x24), (GmVec3 *)&fStack_30,
            (GmVec3 *)&fStack_c, (GmVec3 *)&fStack_24);
        AddVehicleImpulse(this, (GmVec3 *)&fStack_24, (GmVec3 *)&fStack_18);
        return;
      }
    } else {
      piVar13 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      if (*(short *)(pCVar8 + 0x48) == 4) {
        fVar3 = *(float *)(*piVar13 + 0x18c);
      } else {
        fVar3 = *(float *)(*piVar13 + 0x184);
      }
      pCStack_14 = *(CHmsPhysicalContact **)(pCVar8 + 0x28);
      fStack_18 = *(float *)(pCVar8 + 0x24);
      fStack_10 = *(float *)(pCVar8 + 0x2c);
      fStack_1c = *(float *)(pCVar8 + 0x14) * fStack_10 + *pfVar1 * fStack_18 +
                  *(float *)(pCVar8 + 0x10) * (float)pCStack_14;
      if (fStack_1c < 0.0 != NAN(fStack_1c)) {
        fStack_24 = *pfVar1 * fStack_1c;
        fStack_20 = *(float *)(pCVar8 + 0x10) * fStack_1c;
        fStack_1c = fStack_1c * *(float *)(pCVar8 + 0x14);
        fVar6 = fStack_1c * 0.0 + fStack_20 + fStack_24 * 0.0;
        if ((bVar7) || (fVar6 < 0.0 == NAN(fVar6))) {
          iVar10 = *(int *)(*(int *)(this + 0x28) + 0x14);
          fStack_c = *pfVar2 - *(float *)(iVar10 + 0x50);
          fStack_8 = *(float *)(pCVar8 + 0x1c) - *(float *)(iVar10 + 0x54);
          fStack_4 = *(float *)(pCVar8 + 0x20) - *(float *)(iVar10 + 0x58);
          SDynaMath::ComputeImpulse(*(float *)(iVar10 + 0x18),
                                    (GmMat3 *)(iVar10 + 0x1c), -fVar3,
                                    (GmVec3 *)&fStack_18, (GmVec3 *)pfVar1,
                                    (GmVec3 *)&fStack_c, (GmVec3 *)&fStack_24);
          AddVehicleImpulse(this, (GmVec3 *)&fStack_24, (GmVec3 *)pfVar2);
          return;
        }
        fStack_30 = *(float *)(pCVar8 + 0x24) - fVar6 * 0.0;
        fStack_2c = *(float *)(pCVar8 + 0x28) - fVar6;
        fStack_28 = *(float *)(pCVar8 + 0x2c) - fVar6 * 0.0;
        if (*(float *)(pCVar8 + 0x14) * fStack_28 + *pfVar1 * fStack_30 +
                *(float *)(pCVar8 + 0x10) * fStack_2c <
            0.0) {
          fStack_18 = *(float *)(param_1 + 100);
          pCStack_14 = *(CHmsPhysicalContact **)(param_1 + 0x68);
          iVar10 = *(int *)(*(int *)(this + 0x28) + 0x14);
          fStack_10 = *(float *)(param_1 + 0x6c);
          fStack_c = fStack_18 - *(float *)(iVar10 + 0x50);
          fStack_8 = (float)pCStack_14 - *(float *)(iVar10 + 0x54);
          fStack_4 = fStack_10 - *(float *)(iVar10 + 0x58);
          SDynaMath::ComputeImpulse(*(float *)(iVar10 + 0x18),
                                    (GmMat3 *)(iVar10 + 0x1c), -fVar3,
                                    (GmVec3 *)&fStack_30, (GmVec3 *)pfVar1,
                                    (GmVec3 *)&fStack_c, (GmVec3 *)&fStack_24);
          AddVehicleImpulse(this, (GmVec3 *)&fStack_24, (GmVec3 *)&fStack_18);
          return;
        }
      }
    }
  }
  return;
}
