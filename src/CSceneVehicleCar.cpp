
/* protected: void __thiscall CSceneVehicleCar::AddVehicleForce(class GmVec3
   const &,class GmVec3 const &) */

void __thiscall CSceneVehicleCar::AddVehicleForce(CSceneVehicleCar *this,
                                                  GmVec3 *param_1,
                                                  GmVec3 *param_2)

{
  CHmsItem::AddForce(*(CHmsItem **)(this + 0x28), param_1, param_2);
  *(float *)(this + 0x818) = *(float *)(this + 0x818) + *(float *)param_1;
  *(float *)(this + 0x81c) = *(float *)(param_1 + 4) + *(float *)(this + 0x81c);
  *(float *)(this + 0x820) = *(float *)(param_1 + 8) + *(float *)(this + 0x820);
  return;
}

/* protected: void __thiscall CSceneVehicleCar::AddVehicleImpulse(class GmVec3
   const &,class GmVec3 const &) */

void __thiscall CSceneVehicleCar::AddVehicleImpulse(CSceneVehicleCar *this,
                                                    GmVec3 *param_1,
                                                    GmVec3 *param_2)

{
  GmMat3 *pGVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int *piVar6;
  float10 fVar7;
  undefined8 local_3c;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  piVar6 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
  iVar3 = *(int *)(*piVar6 + 0x58);
  if (iVar3 != 0) {
    iVar4 = *(int *)(iVar3 + 0x32c);
    pGVar1 = (GmMat3 *)(iVar4 + 0x10);
    GmVec3::SetMult((GmVec3 *)&local_18, param_1, pGVar1);
    GmVec3::SetMult((GmVec3 *)&local_c, param_2, (GmIso4 *)pGVar1);
    pfVar5 = *(float **)(iVar3 + 0x108);
    local_28 = 1.0 / *pfVar5;
    local_30 = local_28 * local_18;
    local_2c = local_14 * local_28;
    local_28 = local_28 * local_10;
    local_24 = *(float *)(iVar4 + 0x40) + local_30;
    local_20 = *(float *)(iVar4 + 0x44) + local_2c;
    local_1c = *(float *)(iVar4 + 0x48) + local_28;
    local_3c._0_4_ = *(float *)(iVar4 + 0x48) * *(float *)(iVar4 + 0x48) +
                     *(float *)(iVar4 + 0x40) * *(float *)(iVar4 + 0x40) +
                     *(float *)(iVar4 + 0x44) * *(float *)(iVar4 + 0x44);
    fVar2 = local_1c * local_1c + local_24 * local_24 + local_20 * local_20;
    if (((float)local_3c < fVar2 != (NAN((float)local_3c) || NAN(fVar2))) &&
        (piVar6 = (int *)CFastBuffer<>::operator[](
             (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
             *(ulong *)(*(int *)(this + 100) + 0x24)),
         *(float *)(*piVar6 + 0x150) < fVar2 - (float)local_3c !=
             (NAN(*(float *)(*piVar6 + 0x150)) ||
              NAN(fVar2 - (float)local_3c)))) {
      local_1c = 0.0;
      local_20 = 0.0;
      local_24 = 0.0;
    }
    *(float *)(iVar4 + 0x40) = local_24;
    *(float *)(iVar4 + 0x44) = local_20;
    *(float *)(iVar4 + 0x48) = local_1c;
    GmVec3::SetMult((GmVec3 *)&local_3c, (GmVec3 *)(pfVar5 + 0xe),
                    (GmIso4 *)pGVar1);
    local_24 = local_c - (float)local_3c;
    local_20 = local_8 - local_3c._4_4_;
    local_1c = local_4 - local_34;
    local_30 = local_10 * local_20 - local_14 * local_1c;
    local_2c = local_18 * local_1c - local_24 * local_10;
    local_28 = local_24 * local_14 - local_18 * local_20;
    GmVec3::Mult((GmVec3 *)&local_30, (GmMat3 *)(iVar4 + 0x7c));
    iVar3 = *(int *)(this + 100);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    fVar2 = *(float *)(*piVar6 + 0xec);
    local_30 = fVar2 * local_30;
    local_2c = fVar2 * local_2c;
    local_28 = fVar2 * local_28;
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    local_2c = *(float *)(*piVar6 + 0xe8) * local_2c;
    *(float *)(iVar4 + 0x58) = *(float *)(iVar4 + 0x58) + local_30;
    *(float *)(iVar4 + 0x5c) = *(float *)(iVar4 + 0x5c) + local_2c;
    *(float *)(iVar4 + 0x60) = *(float *)(iVar4 + 0x60) + local_28;
    local_3c = (double)CONCAT44(
        local_3c._4_4_,
        *(float *)(iVar4 + 0x60) * *(float *)(iVar4 + 0x60) +
            *(float *)(iVar4 + 0x58) * *(float *)(iVar4 + 0x58) +
            *(float *)(iVar4 + 0x5c) * *(float *)(iVar4 + 0x5c));
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    fVar2 = *(float *)(*piVar6 + 0x14c);
    if (fVar2 * fVar2 < (float)local_3c) {
      local_3c = (double)fVar2;
      fVar7 = (float10)__CIsqrt();
      fVar2 = (float)local_3c / (float)fVar7;
      *(float *)(iVar4 + 0x58) = fVar2 * *(float *)(iVar4 + 0x58);
      *(float *)(iVar4 + 0x5c) = *(float *)(iVar4 + 0x5c) * fVar2;
      *(float *)(iVar4 + 0x60) = fVar2 * *(float *)(iVar4 + 0x60);
    }
    *(float *)(this + 0x824) = *(float *)param_1 + *(float *)(this + 0x824);
    *(float *)(this + 0x828) =
        *(float *)(param_1 + 4) + *(float *)(this + 0x828);
    *(float *)(this + 0x82c) =
        *(float *)(param_1 + 8) + *(float *)(this + 0x82c);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall
 * CSceneVehicleCar::SSimulationWheel::SRealTimeState::Integrate(float) */

void __thiscall CSceneVehicleCar::SSimulationWheel::SRealTimeState::Integrate(
    SRealTimeState *this, float param_1)

{
  float *pfVar1;
  float10 fVar2;
  float fVar3;
  float local_c;
  float local_8;
  float local_4;

  fVar3 =
      GmFunc::Mod(*(float *)(this + 0x6c) * param_1 + *(float *)(this + 0x9c),
                  0.0, 1608.495);
  *(float *)(this + 0x9c) = fVar3;
  pfVar1 = (float *)(this + 0x90);
  fVar3 = *(float *)(this + 0x98) * *(float *)(this + 0x98) +
          *pfVar1 * *pfVar1 + *(float *)(this + 0x94) * *(float *)(this + 0x94);
  if (_DAT_00d06a80 < fVar3 != (NAN(_DAT_00d06a80) || NAN(fVar3))) {
    fVar2 = (float10)__CIsqrt();
    fVar3 = 1.0 / (float)fVar2;
    *pfVar1 = fVar3 * *pfVar1;
    *(float *)(this + 0x94) = *(float *)(this + 0x94) * fVar3;
    *(float *)(this + 0x98) = fVar3 * *(float *)(this + 0x98);
    local_c = *(float *)(this + 0x98) * 0.0 - *(float *)(this + 0x94) * 0.0;
    local_8 = *pfVar1 * 0.0 - *(float *)(this + 0x98);
    local_4 = *(float *)(this + 0x94) - *pfVar1 * 0.0;
    GmMat3::SetUpVandDOV((GmMat3 *)(this + 0x30), (GmVec3 *)pfVar1,
                         (GmVec3 *)&local_c);
  }
  if (*(float *)(this + 0xa4) <= *(float *)(this + 0xa0)) {
    fVar3 = *(float *)(this + 0xa0) - param_1;
    *(float *)(this + 0xa0) = fVar3;
    if (fVar3 < *(float *)(this + 0xa4)) {
      *(undefined4 *)(this + 0xa0) = *(undefined4 *)(this + 0xa4);
    }
  } else {
    fVar3 = *(float *)(this + 0xa0) + param_1;
    *(float *)(this + 0xa0) = fVar3;
    if (*(float *)(this + 0xa4) < fVar3 !=
        (NAN(*(float *)(this + 0xa4)) || NAN(fVar3))) {
      *(undefined4 *)(this + 0xa0) = *(undefined4 *)(this + 0xa4);
      return;
    }
  }
  return;
}

/* public: __thiscall CSceneVehicleCar::SSimulationWheel::SSimulationWheel(void)
 */

SSimulationWheel
    *__thiscall CSceneVehicleCar::SSimulationWheel::SSimulationWheel(
        SSimulationWheel *this)

{
  CSceneVehicle::SSurfaceHandler::SSurfaceHandler(
      (SSurfaceHandler *)(this + 0xc));
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  GmIso4::SetIdentity((GmIso4 *)(this + 0x70));
  *(undefined4 *)(this + 0xa0) = 0x3f800000;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0xa4) = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0x3f800000;
  return this;
}

/* public: void __thiscall
 * CSceneVehicleCar::SSimulationWheel::SState::Reset(void) */

void __thiscall CSceneVehicleCar::SSimulationWheel::SState::Reset(SState *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined2 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  GmMat3::SetIdentity((GmMat3 *)(this + 0x30));
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  return;
}

/* public: void __thiscall
   CSceneVehicleCar::SSimulationWheel::SState::SetBlend(struct
   CSceneVehicleCar::SSimulationWheel::SState const &,struct
   CSceneVehicleCar::SSimulationWheel::SState const &,float) */

void __thiscall CSceneVehicleCar::SSimulationWheel::SState::SetBlend(
    SState *this, SState *param_1, SState *param_2, float param_3)

{
  float fVar1;
  SState *pSVar2;
  SState *pSVar3;
  undefined4 uVar4;

  pSVar3 = param_2;
  pSVar2 = param_1;
  fVar1 = 1.0 - param_3;
  *(float *)this = *(float *)param_1 * fVar1 + *(float *)param_2 * param_3;
  param_1 = *(SState **)(param_1 + 4);
  param_2 = *(SState **)(param_2 + 4);
  OrderWindowedValues((float *)&param_1, (float *)&param_2, 1608.495);
  *(float *)(this + 4) = fVar1 * (float)param_1 + param_3 * (float)param_2;
  *(float *)(this + 8) =
      fVar1 * *(float *)(pSVar2 + 8) + *(float *)(pSVar3 + 8) * param_3;
  if ((*(int *)(pSVar2 + 0x10) == 0) || (*(int *)(pSVar3 + 0x10) == 0)) {
    uVar4 = 0;
  } else {
    uVar4 = 1;
  }
  *(undefined4 *)(this + 0x10) = uVar4;
  *(undefined2 *)(this + 0xc) = *(undefined2 *)(pSVar2 + 0xc);
  if ((*(int *)(pSVar2 + 0x14) != 0) && (*(int *)(pSVar3 + 0x14) != 0)) {
    *(undefined4 *)(this + 0x14) = 1;
    return;
  }
  *(undefined4 *)(this + 0x14) = 0;
  return;
}

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

/* protected: void __thiscall CSceneVehicleCar::WheelAddForceToVehicle(struct
   CSceneVehicleCar::SSimulationWheel &,class GmVec3 const &) */

void __thiscall CSceneVehicleCar::WheelAddForceToVehicle(
    CSceneVehicleCar *this, SSimulationWheel *param_1, GmVec3 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;

  iVar1 = *(int *)(this + 100);
  piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                            *(ulong *)(iVar1 + 0x24));
  iVar2 = *(int *)(*piVar3 + 0x350);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x124) != 0) {
      local_24 = 0.0;
      local_20 = 1.0;
      local_1c = 0.0;
      piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      local_20 = *(float *)(*piVar4 + 0x114) * *(float *)(*piVar3 + 0x128) *
                 (*(float *)(*piVar5 + 0x124) - *(float *)(param_1 + 0xb4));
      local_24 = local_20 * 0.0;
      local_1c = local_24;
      AddVehicleForce(this, (GmVec3 *)&local_24, (GmVec3 *)(param_1 + 0xa8));
    }
  } else if (iVar2 == 1) {
    if (*(int *)(param_1 + 0x124) != 0) {
      piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      local_8 = (*(float *)(*piVar3 + 0x124) - *(float *)(param_1 + 0xb4)) *
                    *(float *)(*piVar4 + 0x114) -
                *(float *)(*piVar5 + 0x118) * *(float *)(param_1 + 0xb8);
      local_c = 0;
      local_4 = 0;
      AddVehicleForce(this, (GmVec3 *)&local_c, (GmVec3 *)(param_1 + 0xa8));
      return;
    }
  } else if ((iVar2 == 2) && (*(int *)(param_1 + 0x124) != iVar2 + -2)) {
    piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    local_14 = (*(float *)(*piVar3 + 0x124) - *(float *)(param_1 + 0xb4)) *
                   *(float *)(*piVar4 + 0x114) -
               *(float *)(*piVar5 + 0x118) * *(float *)(param_1 + 0xb8);
    local_18 = 0;
    local_10 = 0;
    AddVehicleForce(this, (GmVec3 *)&local_18, (GmVec3 *)(param_1 + 0xa8));
    return;
  }
  return;
}

/* protected: void __thiscall CSceneVehicleCar::WheelIntegrate(struct
   CSceneVehicleCar::SSimulationWheel &,float) */

void __thiscall CSceneVehicleCar::WheelIntegrate(CSceneVehicleCar *this,
                                                 SSimulationWheel *param_1,
                                                 float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float local_4;

  iVar9 = *(int *)(this + 100);
  piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                            *(ulong *)(iVar9 + 0x24));
  iVar5 = *(int *)(*piVar6 + 0x350);
  if (iVar5 == 0) {
    *(float *)(param_1 + 0xb4) =
        *(float *)(param_1 + 0xb4) - *(float *)(param_1 + 0xbc);
    *(undefined4 *)(param_1 + 0xbc) = 0;
    iVar9 = *(int *)(this + 100);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    piVar8 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    fVar1 = *(float *)(*piVar6 + 0x124);
    fVar2 = *(float *)(param_1 + 0xb4);
    fVar3 = *(float *)(*piVar7 + 0x114);
    fVar4 = *(float *)(*piVar8 + 0x118);
    puVar10 = (undefined4 *)(param_1 + 0x10);
    puVar11 = (undefined4 *)(param_1 + 0x40);
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    fVar1 = *(float *)(param_1 + 0xb8) +
            param_2 *
                ((fVar1 - fVar2) * fVar3 - fVar4 * *(float *)(param_1 + 0xb8));
    *(float *)(param_1 + 0xb8) = fVar1;
    fVar1 = fVar1 * param_2 + *(float *)(param_1 + 0xb4);
    *(float *)(param_1 + 0xb4) = fVar1;
    fVar1 = -fVar1;
    local_4 = fVar1 * 0.0;
    *(float *)(param_1 + 100) = *(float *)(param_1 + 100) + local_4;
    fVar1 = fVar1 + *(float *)(param_1 + 0x68);
  } else {
    if (iVar5 != 1) {
      if (iVar5 == 2) {
        fVar1 = *(float *)(param_1 + 0xb4);
        fVar2 = *(float *)(param_1 + 0xbc);
        piVar6 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar9 + 0x14), *(ulong *)(iVar9 + 0x24));
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar9 + 0x14), *(ulong *)(iVar9 + 0x24));
        fVar3 = *(float *)(*piVar6 + 0x124);
        fVar4 = *(float *)(*piVar7 + 0x194);
        puVar10 = (undefined4 *)(param_1 + 0x10);
        puVar11 = (undefined4 *)(param_1 + 0x40);
        for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        fVar1 = fVar4 * param_2 * (fVar3 - (fVar1 - fVar2)) + (fVar1 - fVar2);
        *(float *)(param_1 + 0xb8) =
            param_2 / (fVar1 - *(float *)(param_1 + 0xb4));
        *(float *)(param_1 + 0xb4) = fVar1;
        *(undefined4 *)(param_1 + 0xbc) = 0;
        fVar2 = -fVar1 * 0.0;
        *(float *)(param_1 + 100) = fVar2 + *(float *)(param_1 + 100);
        *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x68) + -fVar1;
        *(float *)(param_1 + 0x6c) = fVar2 + *(float *)(param_1 + 0x6c);
        CSceneVehicle::SSurfaceHandler::UpdateSurface(
            (SSurfaceHandler *)(param_1 + 0xc));
        return;
      }
      goto LAB_007bd6c6;
    }
    fVar1 = *(float *)(param_1 + 0xb4);
    fVar2 = *(float *)(param_1 + 0xbc);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    fVar3 = *(float *)(*piVar6 + 0x124);
    fVar4 = *(float *)(*piVar7 + 0x194);
    puVar10 = (undefined4 *)(param_1 + 0x10);
    puVar11 = (undefined4 *)(param_1 + 0x40);
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    fVar1 = fVar4 * param_2 * (fVar3 - (fVar1 - fVar2)) + (fVar1 - fVar2);
    *(float *)(param_1 + 0xb8) = param_2 / (fVar1 - *(float *)(param_1 + 0xb4));
    *(float *)(param_1 + 0xb4) = fVar1;
    *(undefined4 *)(param_1 + 0xbc) = 0;
    local_4 = -fVar1 * 0.0;
    *(float *)(param_1 + 100) = local_4 + *(float *)(param_1 + 100);
    fVar1 = *(float *)(param_1 + 0x68) + -fVar1;
  }
  *(float *)(param_1 + 0x68) = fVar1;
  *(float *)(param_1 + 0x6c) = *(float *)(param_1 + 0x6c) + local_4;
LAB_007bd6c6:
  CSceneVehicle::SSurfaceHandler::UpdateSurface(
      (SSurfaceHandler *)(param_1 + 0xc));
  return;
}

/* protected: void __thiscall CSceneVehicleCar::WheelReset(struct
   CSceneVehicleCar::SSimulationWheel
   &) */

void __thiscall CSceneVehicleCar::WheelReset(CSceneVehicleCar *this,
                                             SSimulationWheel *param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;

  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  piVar3 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  fVar1 = *(float *)(*piVar3 + 0x124);
  *(float *)(param_1 + 0xb4) = fVar1;
  fVar1 = -fVar1;
  fVar2 = fVar1 * 0.0;
  CSceneVehicle::SSurfaceHandler::Reset((SSurfaceHandler *)(param_1 + 0xc));
  *(float *)(param_1 + 100) = *(float *)(param_1 + 100) + fVar2;
  *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x68) + fVar1;
  *(float *)(param_1 + 0x6c) = *(float *)(param_1 + 0x6c) + fVar2;
  CSceneVehicle::SSurfaceHandler::UpdateSurface(
      (SSurfaceHandler *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  GmIso4::SetIdentity((GmIso4 *)(param_1 + 0xe4));
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined2 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  SSimulationWheel::SState::Reset((SState *)(param_1 + 0x234));
  SSimulationWheel::SState::Reset((SState *)(param_1 + 0x298));
  SSimulationWheel::SState::Reset((SState *)(param_1 + 0x16c));
  SSimulationWheel::SState::Reset((SState *)(param_1 + 0x1d0));
  return;
}

/* protected: void __thiscall
   CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed(struct
   CSceneVehicleCar::SSimulationWheel &,float,float) */

void __thiscall CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed(
    CSceneVehicleCar *this, SSimulationWheel *param_1, float param_2,
    float param_3)

{
  float fVar1;
  SSimulationWheel *pSVar2;
  int *piVar3;

  pSVar2 = param_1;
  if (*(int *)(param_1 + 0x124) != 0) {
    if ((*(int *)(this + 0x6a0) != 0) && (*(int *)(this + 0x73c) == 0)) {
      piVar3 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(*piVar3 + 700);
      return;
    }
    *(float *)(param_1 + 0x120) = param_2 / *(float *)(param_1 + 8);
    return;
  }
  param_2 = 0.0;
  param_1 = (SSimulationWheel *)0x0;
  if (1e-05 < *(float *)(this + 0x54) == NAN(*(float *)(this + 0x54))) {
    if (((1e-05 < *(float *)(this + 0x50) == NAN(*(float *)(this + 0x50))) ||
         (*(int *)(this + 0x73c) != 0)) ||
        (*(int *)(this + 0x60c) != 0)) {
      *(float *)(pSVar2 + 0x120) = *(float *)(pSVar2 + 0x120) * 0.995;
    } else {
      param_1 = (SSimulationWheel *)(*(float *)(this + 0x50) * 200.0);
      param_2 = 100.0;
    }
  } else {
    param_1 = (SSimulationWheel *)(1.0 - *(float *)(this + 0x54));
    if ((float)param_1 < 0.0 == ((float)param_1 == 0.0)) {
      if (1.0 < (float)param_1 == ((float)param_1 == 1.0)) {
        param_2 = -100.0;
      } else {
        param_1 = (SSimulationWheel *)&DAT_3f800000;
        param_2 = -100.0;
      }
    } else {
      param_1 = (SSimulationWheel *)0x0;
      param_2 = -100.0;
    }
  }
  if (ABS(param_2) < 1e-05 == NAN(ABS(param_2))) {
    fVar1 = param_2 * param_3 + *(float *)(pSVar2 + 0x120);
    *(float *)(pSVar2 + 0x120) = fVar1;
    if ((0.0 < param_2) &&
        ((float)param_1 < fVar1 != (NAN((float)param_1) || NAN(fVar1)))) {
      *(SSimulationWheel **)(pSVar2 + 0x120) = param_1;
      return;
    }
    if ((param_2 < 0.0 != NAN(param_2)) && (fVar1 < (float)param_1)) {
      *(SSimulationWheel **)(pSVar2 + 0x120) = param_1;
      return;
    }
  }
  return;
}
