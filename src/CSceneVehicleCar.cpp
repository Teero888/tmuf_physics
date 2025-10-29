
/* public: virtual void * __thiscall CSceneVehicleCar::`vector deleting
 * destructor'(unsigned int) */

void *__thiscall CSceneVehicleCar::`vector_deleting_destructor'(CSceneVehicleCar *this,uint param_1)

{
  ~CSceneVehicleCar(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* protected: virtual void __thiscall CSceneVehicleCar::AbsorbContact(class
 * CHmsPhysicalContact &)
 */

void __thiscall CSceneVehicleCar::AbsorbContact(CSceneVehicleCar *this,
                                                CHmsPhysicalContact *param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  ulong uVar5;
  SSimulationWheel *pSVar6;
  int *piVar7;
  float10 fVar8;
  float10 fVar9;
  float local_30;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  if ((*(short *)(param_1 + 0x48) == 0xd) ||
      (*(short *)(param_1 + 0x48) == 0x17)) {
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    return;
  }
  *(undefined4 *)(this + 0x5d4) = 1;
  uVar5 = GetWheelFromSurfaceTree(this, *(CPlugTree **)(param_1 + 4));
  fVar3 = ABS(*(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x2c) +
              *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x24) +
              *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x28));
  if ((uVar5 == 0xffffffff) || (*(float *)(param_1 + 0x10) <= 0.2)) {
    *(float *)(this + 0x678) = *(float *)(this + 0x678) + fVar3;
  } else {
    pSVar6 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), uVar5);
    if (*(int *)(pSVar6 + 4) == 0) {
      *(float *)(this + 0x674) = *(float *)(this + 0x674) + fVar3;
    } else {
      *(float *)(this + 0x670) = fVar3 + *(float *)(this + 0x670);
    }
  }
  if (uVar5 != 0xffffffff) {
    this[0x201] = *(CSceneVehicleCar *)(param_1 + 0x48);
    pSVar6 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), uVar5);
    WheelAbsorbContact(this, pSVar6, param_1);
    *(int *)(this + 0x67c) = *(int *)(this + 0x67c) + 1;
    return;
  }
  if ((*(float *)(param_1 + 0x10) < -0.75) &&
      (piVar7 = (int *)CFastBuffer<>::operator[](
           (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
           *(ulong *)(*(int *)(this + 100) + 0x24)),
       *(int *)(*piVar7 + 0x354) == 5)) {
    fVar3 = *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x38) +
            *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x30) +
            *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x34);
    *(float *)(param_1 + 0x30) = fVar3 * *(float *)(param_1 + 0xc);
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x10) * fVar3;
    *(float *)(param_1 + 0x38) = fVar3 * *(float *)(param_1 + 0x14);
  }
  pfVar1 = (float *)(param_1 + 0x18);
  *(float *)(this + 0x684) = *(float *)(this + 0x684) + *pfVar1;
  *(float *)(this + 0x688) =
      *(float *)(param_1 + 0x1c) + *(float *)(this + 0x688);
  *(float *)(this + 0x68c) =
      *(float *)(param_1 + 0x20) + *(float *)(this + 0x68c);
  *(float *)(this + 0x690) =
      *(float *)(param_1 + 0xc) + *(float *)(this + 0x690);
  *(float *)(this + 0x694) =
      *(float *)(param_1 + 0x10) + *(float *)(this + 0x694);
  *(float *)(this + 0x698) =
      *(float *)(param_1 + 0x14) + *(float *)(this + 0x698);
  *(int *)(this + 0x680) = *(int *)(this + 0x680) + 1;
  *(undefined4 *)(this + 0x5d8) = 1;
  iVar4 = *(int *)(this + 100);
  this[0x200] = *(CSceneVehicleCar *)(param_1 + 0x48);
  piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar4 + 0x14),
                                            *(ulong *)(iVar4 + 0x24));
  if (*(int *)(*piVar7 + 0x350) == 2) {
    fVar3 = *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x2c) +
            *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x24) +
            *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x28);
    if (fVar3 < 0.0 != NAN(fVar3)) {
      if (*(short *)(param_1 + 0x48) == 4) {
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        local_30 = *(float *)(*piVar7 + 0x178);
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        fVar3 = *(float *)(*piVar7 + 0x174);
      } else {
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        local_30 = *(float *)(*piVar7 + 0x17c);
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        fVar3 = *(float *)(*piVar7 + 0x170);
      }
      local_30 = -local_30;
      pfVar2 = (float *)(param_1 + 0x24);
      local_4 = *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x14) +
                *pfVar2 * *(float *)(param_1 + 0xc) +
                *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x10);
      local_c = local_4 * *(float *)(param_1 + 0xc);
      local_8 = *(float *)(param_1 + 0x10) * local_4;
      local_4 = local_4 * *(float *)(param_1 + 0x14);
      local_18 = *pfVar2 - local_c;
      local_14 = *(float *)(param_1 + 0x28) - local_8;
      local_10 = *(float *)(param_1 + 0x2c) - local_4;
      fVar8 = (float10)__CIsqrt();
      fVar9 = (float10)__CIsqrt();
      if ((float)fVar8 * fVar3 < (float)fVar9) {
        fVar3 = ((float)fVar8 * fVar3) / (float)fVar9;
        local_18 = fVar3 * local_18;
        local_14 = local_14 * fVar3;
        local_10 = fVar3 * local_10;
      }
      local_24 = -(local_18 + local_c);
      local_20 = -(local_14 + local_8);
      local_1c = -(local_10 + local_4);
      fVar8 = (float10)__CIsqrt();
      if (1e-05 < (float)fVar8) {
        fVar3 = 1.0 / (float)fVar8;
        iVar4 = *(int *)(*(int *)(this + 0x28) + 0x14);
        local_24 = fVar3 * local_24;
        local_20 = local_20 * fVar3;
        local_1c = fVar3 * local_1c;
        local_c = *pfVar1 - *(float *)(iVar4 + 0x50);
        local_8 = *(float *)(param_1 + 0x1c) - *(float *)(iVar4 + 0x54);
        local_4 = *(float *)(param_1 + 0x20) - *(float *)(iVar4 + 0x58);
        SDynaMath::ComputeImpulse(*(float *)(iVar4 + 0x18),
                                  (GmMat3 *)(iVar4 + 0x1c), local_30,
                                  (GmVec3 *)pfVar2, (GmVec3 *)&local_24,
                                  (GmVec3 *)&local_c, (GmVec3 *)&local_18);
        AddVehicleImpulse(this, (GmVec3 *)&local_18, (GmVec3 *)pfVar1);
        *(undefined4 *)(param_1 + 0x3c) = 0;
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::AddStateForPrediction(class
   CClassicBufferMemory &,unsigned long,unsigned long) */

void __thiscall CSceneVehicleCar::AddStateForPrediction(
    CSceneVehicleCar *this, CClassicBufferMemory *param_1, ulong param_2,
    ulong param_3)

{
  ulong uVar1;
  int *piVar2;
  uint uVar3;
  ulong unaff_retaddr;
  undefined auStack_28[36];
  int *piStack_4;

  piVar2 = (int *)(**(code **)(*(int *)this + 8))();
  uVar1 = param_3;
  uVar3 = (**(code **)(*piVar2 + 4))(param_3, auStack_28);
  CHmsItem::AddStateForPrediction(*(CHmsItem **)(this + 0x28),
                                  (CClassicBufferMemory *)piStack_4,
                                  unaff_retaddr, uVar3 & 0xff);
  if (uVar1 == 6) {
    (**(code **)(*piStack_4 + 4))(&param_1, 2);
    return;
  }
  if (uVar1 == 9) {
    (**(code **)(*piStack_4 + 4))(&stack0xffffffd4, 0x23);
  }
  return;
}

/* protected: void __thiscall CSceneVehicleCar::AddVehicleCentralForce(class
 * GmVec3 const &) */

void __thiscall CSceneVehicleCar::AddVehicleCentralForce(CSceneVehicleCar *this,
                                                         GmVec3 *param_1)

{
  CHmsItem::AddForce(*(CHmsItem **)(this + 0x28), param_1);
  *(float *)(this + 0x818) = *(float *)(this + 0x818) + *(float *)param_1;
  *(float *)(this + 0x81c) = *(float *)(param_1 + 4) + *(float *)(this + 0x81c);
  *(float *)(this + 0x820) = *(float *)(param_1 + 8) + *(float *)(this + 0x820);
  return;
}

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

/* protected: void __thiscall CSceneVehicleCar::AddVehicleImpulse(class GmVec3
 * const &) */

void __thiscall CSceneVehicleCar::AddVehicleImpulse(CSceneVehicleCar *this,
                                                    GmVec3 *param_1)

{
  CHmsItem::AddImpulse(*(CHmsItem **)(this + 0x28), param_1);
  *(float *)(this + 0x824) = *(float *)(this + 0x824) + *(float *)param_1;
  *(float *)(this + 0x828) = *(float *)(param_1 + 4) + *(float *)(this + 0x828);
  *(float *)(this + 0x82c) = *(float *)(param_1 + 8) + *(float *)(this + 0x82c);
  return;
}

/* protected: void __thiscall CSceneVehicleCar::AddVehicleTorque(class GmVec3
 * const &) */

void __thiscall CSceneVehicleCar::AddVehicleTorque(CSceneVehicleCar *this,
                                                   GmVec3 *param_1)

{
  CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28), param_1);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CSceneVehicleCar::AfterContacts(void) */

void __thiscall CSceneVehicleCar::AfterContacts(CSceneVehicleCar *this)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;
  SSimulationWheel *pSVar5;
  int *piVar6;
  ulong *puVar7;
  int iVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar9;
  int extraout_ECX_03;
  int extraout_ECX_04;
  ulong uVar10;
  float *pfVar11;
  undefined4 *puVar12;
  float unaff_EDI;
  float *pfVar13;
  undefined4 *puVar14;
  float10 fVar15;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  uint uStack_28;
  float fStack_10;
  float local_c;
  float local_8;
  float local_4;

  puVar12 = (undefined4 *)(this + 0x3a0);
  puVar14 = (undefined4 *)(this + 0x2f8);
  for (iVar8 = 0x2a; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar14 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar14 = puVar14 + 1;
  }
  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar10 = 0;
  if (uVar4 != 0) {
    do {
      pSVar5 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), uVar10);
      uVar10 = uVar10 + 1;
      puVar12 = (undefined4 *)(pSVar5 + 0x1d0);
      puVar14 = (undefined4 *)(pSVar5 + 0x16c);
      for (iVar8 = 0x19; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar14 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar14 = puVar14 + 1;
      }
    } while (uVar10 < uVar4);
  }
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28), (GmVec3 *)&local_c);
  *(float *)(this + 0x3a0) = local_4;
  *(float *)(this + 0x3a4) = local_c;
  *(undefined4 *)(this + 0x420) = *(undefined4 *)(this + 0x5b4);
  *(uint *)(this + 0x3b4) = (uint)(*(int *)(this + 0x600) != 0);
  *(undefined4 *)(this + 0x3b8) = *(undefined4 *)(this + 0x5f0);
  piVar6 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
  pfVar1 = (float *)(this + 0x3d4);
  pfVar11 = (float *)(*piVar6 + 0x18);
  pfVar13 = pfVar1;
  for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pfVar13 = *pfVar11;
    pfVar11 = pfVar11 + 1;
    pfVar13 = pfVar13 + 1;
  }
  *(undefined4 *)(this + 0x404) = *(undefined4 *)(this + 0xb0);
  *(undefined4 *)(this + 0x408) = *(undefined4 *)(this + 0xb8);
  *(float *)(this + 0x40c) = local_8 * *(float *)(this + 0x3d8) +
                             local_c * *pfVar1 +
                             local_4 * *(float *)(this + 0x3dc);
  *(float *)(this + 0x410) = *(float *)(this + 1000) * local_4 +
                             *(float *)(this + 0x3e0) * local_c +
                             *(float *)(this + 0x3e4) * local_8;
  *(float *)(this + 0x414) = local_4 * *(float *)(this + 0x3f4) +
                             *(float *)(this + 0x3f0) * local_8 +
                             *(float *)(this + 0x3ec) * local_c;
  *(undefined4 *)(this + 0x3bc) = *(undefined4 *)(this + 0x6a0);
  *(undefined4 *)(this + 0x424) = *(undefined4 *)(this + 0x5d4);
  *(undefined4 *)(this + 0x3c0) = *(undefined4 *)(this + 0x624);
  *(undefined4 *)(this + 0x3a8) = *(undefined4 *)(this + 0x58);
  *(undefined4 *)(this + 0x3b0) = *(undefined4 *)(this + 0x54);
  *(undefined4 *)(this + 0x3ac) = *(undefined4 *)(this + 0x50);
  *(undefined4 *)(this + 0x428) = *(undefined4 *)(this + 0x2e4);
  uVar9 = *(undefined4 *)(this + 0x748);
  *(undefined4 *)(this + 0x42c) = uVar9;
  *(undefined4 *)(this + 0x3c4) = *(undefined4 *)(this + 0x21c);
  *(undefined4 *)(this + 0x3c8) = *(undefined4 *)(this + 0x230);
  *(undefined4 *)(this + 0x3cc) = *(undefined4 *)(this + 0x240);
  *(undefined4 *)(this + 0x3d0) = *(undefined4 *)(this + 0x23c);
  if (*(int *)(this + 0x680) == 0) {
    *(undefined4 *)(this + 0x434) = 0;
    *(undefined4 *)(this + 0x438) = 0;
    *(undefined4 *)(this + 0x440) = 0;
  } else {
    fVar3 = *(float *)(this + 0x698) * *(float *)(this + 0x698) +
            *(float *)(this + 0x690) * *(float *)(this + 0x690) +
            *(float *)(this + 0x694) * *(float *)(this + 0x694);
    if (_DAT_00d06a80 < fVar3 != (NAN(_DAT_00d06a80) || NAN(fVar3))) {
      fVar15 = (float10)__CIsqrt();
      fVar3 = 1.0 / (float)fVar15;
      *(float *)(this + 0x690) = fVar3 * *(float *)(this + 0x690);
      *(float *)(this + 0x694) = fVar3 * *(float *)(this + 0x694);
      *(float *)(this + 0x698) = fVar3 * *(float *)(this + 0x698);
      uVar9 = extraout_ECX;
    }
    *(float *)(this + 0x690) = -*(float *)(this + 0x690);
    *(float *)(this + 0x694) = -*(float *)(this + 0x694);
    *(float *)(this + 0x698) = -*(float *)(this + 0x698);
    fVar3 = (float)*(int *)(this + 0x680);
    if (*(int *)(this + 0x680) < 0) {
      fVar3 = fVar3 + 4.294967e+09;
    }
    fVar3 = 1.0 / fVar3;
    *(float *)(this + 0x684) = fVar3 * *(float *)(this + 0x684);
    *(float *)(this + 0x688) = *(float *)(this + 0x688) * fVar3;
    *(float *)(this + 0x68c) = fVar3 * *(float *)(this + 0x68c);
    fVar3 = *(float *)(this + 0x694) * *(float *)(this + 0x694) +
            *(float *)(this + 0x690) * *(float *)(this + 0x690) + 0.0;
    if (_DAT_00d06a80 < fVar3 != (NAN(_DAT_00d06a80) || NAN(fVar3))) {
      __CIsqrt();
      uVar9 = extraout_ECX_00;
    }
    fVar15 = (float10)__CIatan2(uVar9);
    *(float *)(this + 0x440) = ABS((float)fVar15) / 3.141593;
    fStack_10 = *(float *)(this + 0x698);
    fVar3 = *(float *)(this + 0x694) * *(float *)(this + 0x694) + 0.0 +
            fStack_10 * fStack_10;
    uVar9 = extraout_ECX_01;
    if (_DAT_00d06a80 < fVar3 != (NAN(_DAT_00d06a80) || NAN(fVar3))) {
      fVar15 = (float10)__CIsqrt();
      fStack_10 = (1.0 / (float)fVar15) * fStack_10;
      uVar9 = extraout_ECX_02;
    }
    fVar15 = (float10)__CIatan2(uVar9);
    *(float *)(this + 0x438) = ABS((float)fVar15) / 3.141593;
    *(uint *)(this + 0x43c) = (uint)(0.0 < fStack_10 != NAN(fStack_10));
    *(undefined4 *)(this + 0x434) = 1;
  }
  *(uint *)(this + 0x430) = (uint)(*(int *)(this + 0x67c) != 0);
  *(undefined4 *)(this + 0x444) = *(undefined4 *)(this + 0x5e4);
  *(undefined4 *)(this + 0x67c) = 0;
  *(undefined4 *)(this + 0x680) = 0;
  *(undefined4 *)(this + 0x68c) = 0;
  *(undefined4 *)(this + 0x688) = 0;
  *(undefined4 *)(this + 0x684) = 0;
  *(undefined4 *)(this + 0x698) = 0;
  *(undefined4 *)(this + 0x694) = 0;
  *(undefined4 *)(this + 0x690) = 0;
  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uStack_28 = 0;
  if (uVar4 != 0) {
    do {
      pSVar5 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), uStack_28);
      *(undefined4 *)(pSVar5 + 0x1d0) = *(undefined4 *)(pSVar5 + 0xb4);
      *(undefined4 *)(pSVar5 + 0x1d4) = *(undefined4 *)(pSVar5 + 0x150);
      puVar12 = (undefined4 *)(pSVar5 + 0xc0);
      puVar14 = (undefined4 *)(pSVar5 + 0x200);
      for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar14 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar14 = puVar14 + 1;
      }
      *(undefined4 *)(pSVar5 + 0x1e0) = *(undefined4 *)(pSVar5 + 0x124);
      *(undefined2 *)(pSVar5 + 0x1dc) = *(undefined2 *)(pSVar5 + 0x128);
      *(undefined4 *)(pSVar5 + 0x1d8) = *(undefined4 *)(pSVar5 + 0x154);
      *(undefined4 *)(pSVar5 + 0x1e4) = *(undefined4 *)(pSVar5 + 300);
      *(undefined4 *)(pSVar5 + 500) = *(undefined4 *)(pSVar5 + 100);
      *(undefined4 *)(pSVar5 + 0x1f8) = *(undefined4 *)(pSVar5 + 0x68);
      *(undefined4 *)(pSVar5 + 0x1fc) = *(undefined4 *)(pSVar5 + 0x6c);
      *(float *)(pSVar5 + 0x1f8) =
          *(float *)(pSVar5 + 0x1f8) - *(float *)(pSVar5 + 8);
      *(float *)(pSVar5 + 0x1e8) =
          *(float *)(this + 0x3dc) * *(float *)(pSVar5 + 0x1fc) +
          *(float *)(pSVar5 + 0x1f8) * *(float *)(this + 0x3d8) +
          *pfVar1 * *(float *)(pSVar5 + 500) + *(float *)(this + 0x3f8);
      *(float *)(pSVar5 + 0x1ec) =
          *(float *)(this + 1000) * *(float *)(pSVar5 + 0x1fc) +
          *(float *)(this + 0x3e0) * *(float *)(pSVar5 + 500) +
          *(float *)(pSVar5 + 0x1f8) * *(float *)(this + 0x3e4) +
          *(float *)(this + 0x3fc);
      *(float *)(pSVar5 + 0x1f0) =
          *(float *)(this + 0x3f4) * *(float *)(pSVar5 + 0x1fc) +
          *(float *)(this + 0x3ec) * *(float *)(pSVar5 + 500) +
          *(float *)(pSVar5 + 0x1f8) * *(float *)(this + 0x3f0) +
          *(float *)(this + 0x400);
      *(undefined4 *)(pSVar5 + 0x224) = *(undefined4 *)(pSVar5 + 0x15c);
      *(undefined4 *)(pSVar5 + 0x228) = *(undefined4 *)(pSVar5 + 0x160);
      *(undefined4 *)(pSVar5 + 0x22c) = *(undefined4 *)(pSVar5 + 0x164);
      *(undefined4 *)(pSVar5 + 0x230) = *(undefined4 *)(pSVar5 + 0x168);
      uStack_28 = uStack_28 + 1;
    } while (uStack_28 < uVar4);
  }
  puVar7 = (ulong *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x6c),
                                              (uint)(byte)this[0x201]);
  piVar6 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 0x68) + 0x14), *puVar7);
  iVar8 = *piVar6;
  if (*(int *)(this + 0x5d4) == 0) {
    fVar3 = 0.0;
  } else {
    fVar2 = *(float *)(iVar8 + 0x30) * ABS(*(float *)(this + 0x3a0));
    fVar3 = *(float *)(iVar8 + 0x34);
    if (fVar2 <= fVar3) {
      fVar3 = fVar2;
    }
  }
  fVar3 = *(float *)(iVar8 + 0x40) * fVar3;
  if (fVar3 < 0.15 == (fVar3 == 0.15)) {
    fVar3 = 0.15;
  }
  FUN_007bc950(*(float10 **)(this + 0x418),
               ABS(*(float *)(this + 0x3a0)) / *(float *)(iVar8 + 0x3c), 0.5,
               unaff_EDI);
  fVar2 = (float)extraout_ST0;
  *(float *)(extraout_ECX_03 + 0x78) = fVar2;
  FUN_007bc950(*(float10 **)(extraout_ECX_03 + 0x7c), fVar3, 0.05, unaff_EDI);
  fVar3 = (float)extraout_ST0_00;
  *(float *)(extraout_ECX_04 + 0x7c) = fVar3;
  if ((1 < *(uint *)(this + 0x1fc)) ||
      ((1 < *(uint *)(this + 0x654) && (*(int *)(this + 0x658) != 0)))) {
    if (fVar2 < 2.0) {
      fVar2 = 2.0;
    }
    *(float *)(extraout_ECX_04 + 0x78) = fVar2;
    if (1.0 <= fVar3) {
      *(float *)(extraout_ECX_04 + 0x7c) = fVar3;
      return;
    }
    *(undefined4 *)(extraout_ECX_04 + 0x7c) = 0x3f800000;
    return;
  }
  if ((*(uint *)(this + 0x1fc) == 0) &&
      ((*(uint *)(this + 0x654) == 0 || (*(int *)(this + 0x658) == 0)))) {
    return;
  }
  if (fVar2 < 4.0) {
    fVar2 = 4.0;
  }
  *(float *)(extraout_ECX_04 + 0x78) = fVar2;
  if (0.66 <= fVar3) {
    *(float *)(extraout_ECX_04 + 0x7c) = fVar3;
    return;
  }
  *(undefined4 *)(extraout_ECX_04 + 0x7c) = 0x3f28f5c3;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* protected: void __thiscall CSceneVehicleCar::ApplyFrictionForces(class GmVec3
 * const &) */

void __thiscall CSceneVehicleCar::ApplyFrictionForces(CSceneVehicleCar *this,
                                                      GmVec3 *param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  CSceneVehicleCarTuning **ppCVar6;
  ulong *puVar7;
  CMwCmdBufferCore *this_00;
  float10 fVar8;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  iVar2 = *(int *)(this + 100);
  piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  if ((((*(int *)(*piVar4 + 0x354) == 4) ||
        (piVar4 = (int *)CFastBuffer<>::operator[](
             (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24)),
         *(int *)(*piVar4 + 0x354) == 5)) &&
       (*(int *)(this + 0x5e4) != 0)) &&
      (iVar5 = IsGroundContact(this), iVar5 == 0)) {
    return;
  }
  if (*(int *)(this + 0x5c4) == 0) {
    fVar1 = *(float *)(this + 0x50);
  } else {
    fVar1 = *(float *)(this + 0x54);
  }
  if ((fVar1 < 1e-05) || (*(int *)(this + 0x60c) != 0)) {
    local_18 = *(float *)param_1;
    local_14 = *(float *)(param_1 + 4);
    local_10 = *(float *)(param_1 + 8);
    fVar1 = local_10 * local_10 + local_18 * local_18 + local_14 * local_14;
    if (_DAT_00d06a80 < fVar1 != (NAN(_DAT_00d06a80) || NAN(fVar1))) {
      fVar8 = (float10)__CIsqrt();
      fVar1 = 1.0 / (float)fVar8;
      local_18 = fVar1 * local_18;
      local_14 = local_14 * fVar1;
      local_10 = fVar1 * local_10;
      piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                                *(ulong *)(iVar2 + 0x24));
      fVar1 = -*(float *)(*piVar4 + 0x58);
      local_18 = fVar1 * local_18;
      local_14 = local_14 * fVar1;
      local_10 = fVar1 * local_10;
      if (*(int *)(this + 0x60c) == 0) {
        piVar4 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
        local_4 = -*(float *)(*piVar4 + 0x5c);
        local_c = local_4 * *(float *)param_1;
        local_8 = *(float *)(param_1 + 4) * local_4;
        local_4 = local_4 * *(float *)(param_1 + 8);
        local_18 = local_c + local_18;
        local_14 = local_8 + local_14;
        local_10 = local_4 + local_10;
      }
      AddVehicleCentralForce(this, (GmVec3 *)&local_18);
    }
  }
  iVar2 = *(int *)(this + 100);
  piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  if (*(int *)(*piVar4 + 0x354) < 4) {
    if (*(int *)(this + 0x5dc) != 0) {
      ppCVar6 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      local_4 = CSceneVehicleCarTuning::GetLateralContactSlowDownFromSpeed(
          *ppCVar6, *(float *)(param_1 + 8));
      local_4 = -local_4;
      local_c = local_4 * *(float *)param_1;
      local_8 = *(float *)(param_1 + 4) * local_4;
      local_4 = local_4 * *(float *)(param_1 + 8);
      AddVehicleCentralForce(this, (GmVec3 *)&local_c);
      return;
    }
  } else {
    this_00 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
    if (this_00 == (CMwCmdBufferCore *)0x0) {
      this_00 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
    }
    puVar7 = CMwTimerAdapter::GetTickTime((CMwTimerAdapter *)this_00);
    uVar3 = *puVar7;
    if (*(int *)(this + 0x5dc) != 0) {
      *(uint *)(this + 0x5e0) = uVar3;
    }
    if (*(uint *)(this + 0x5e0) <= uVar3) {
      iVar2 = *(int *)(this + 100);
      piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                                *(ulong *)(iVar2 + 0x24));
      if (uVar3 - *(int *)(this + 0x5e0) < *(uint *)(*piVar4 + 0x1e8)) {
        fVar8 = (float10)__CIsqrt();
        fVar1 = (float)fVar8;
        if (1e-05 < fVar1) {
          local_4 = 1.0 / fVar1;
          local_c = local_4 * *(float *)param_1;
          local_8 = *(float *)(param_1 + 4) * local_4;
          local_4 = local_4 * *(float *)(param_1 + 8);
          ppCVar6 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
          local_10 =
              CSceneVehicleCarTuning::M5GetLateralContactSlowDownFromSpeed(
                  *ppCVar6, fVar1);
          local_10 = -local_10;
          local_18 = local_10 * local_c;
          local_14 = local_8 * local_10;
          local_10 = local_10 * local_4;
          AddVehicleCentralForce(this, (GmVec3 *)&local_18);
          return;
        }
      }
    }
  }
  return;
}

/* protected: int __thiscall CSceneVehicleCar::ApplyWaterForces(class GmVec3
 * const &) */

int __thiscall CSceneVehicleCar::ApplyWaterForces(CSceneVehicleCar *this,
                                                  GmVec3 *param_1)

{
  float fVar1;
  float fVar2;
  int **ppiVar3;
  GmMat3 *pGVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uchar *puVar8;
  CSceneVehicleCarTuning **ppCVar9;
  float10 fVar10;
  float fStack_7c;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_8;

  ppiVar3 = (int **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
  pGVar4 = (GmMat3 *)(**(code **)(**ppiVar3 + 0x78))();
  GmBoxAligned::SetMult((GmBoxAligned *)&fStack_18,
                        (GmBoxAligned *)(this + 0x1dc), (GmIso4 *)pGVar4);
  fStack_24 = fStack_18;
  fStack_1c = fStack_10;
  fVar2 = ABS(fStack_8) + fStack_14;
  fVar1 = fStack_14 - ABS(fStack_8);
  piVar5 = (int *)CHmsItem::GetZone(*(CHmsItem **)(this + 0x28), 0);
  iVar6 = (**(code **)(*piVar5 + 0xa8))();
  fStack_6c = fStack_24;
  fStack_68 = fStack_1c;
  iVar7 = GmMap2<>::IsInside((GmMap2<> *)(iVar6 + 0x154), (GmVec2 *)&fStack_6c);
  if (((iVar7 != 0) || (*(char *)(iVar6 + 0x16c) != '\x01')) ||
      (*(float *)(iVar6 + 0x178) <= fVar1)) {
    if (fVar2 <= *(float *)(iVar6 + 0x17c)) {
      return 0;
    }
    if (*(float *)(iVar6 + 0x178) <= fVar1) {
      return 0;
    }
    fStack_6c = fStack_24;
    fStack_68 = fStack_1c;
    puVar8 =
        GmMap2<>::GetValue((GmMap2<> *)(iVar6 + 0x154), (GmVec2 *)&fStack_6c);
    if (*puVar8 != '\x01') {
      return 0;
    }
  }
  fVar1 = *(float *)(iVar6 + 0x178) - fVar1;
  if (0.5 < fVar1 == NAN(fVar1)) {
    return 0;
  }
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28), (GmVec3 *)&fStack_60);
  GmVec3::SetMult((GmVec3 *)&fStack_30, (GmVec3 *)&fStack_60, pGVar4);
  iVar7 = *(int *)(this + 100);
  fStack_70 = fStack_30 * fStack_30 + fStack_28 * fStack_28;
  piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar7 + 0x14),
                                            *(ulong *)(iVar7 + 0x24));
  fStack_74 = *(float *)(*piVar5 + 0x208);
  if (((*(int *)(this + 0x5d4) != 0) || (fVar1 < 0.9 == NAN(fVar1))) ||
      ((fVar2 = *(float *)(iVar6 + 0x178) - fVar2,
        fVar2 < 0.0 == NAN(fVar2) || (-1e-05 <= fStack_2c))))
    goto LAB_007c2bef;
  if (fStack_70 <= fStack_74 * fStack_74) {
    piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar7 + 0x14),
                                              *(ulong *)(iVar7 + 0x24));
    fVar1 =
        fStack_58 * fStack_58 + fStack_60 * fStack_60 + fStack_5c * fStack_5c;
    fStack_70 = *(float *)(*piVar5 + 0x20c) * *(float *)(*piVar5 + 0x20c);
    if (fStack_70 < fVar1 == (NAN(fStack_70) || NAN(fVar1)))
      goto LAB_007c2bef;
    fStack_7c = 0.0;
  LAB_007c2b35:
    piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar7 + 0x14),
                                              *(ulong *)(iVar7 + 0x24));
    CFuncKeysReal::GetValue(*(CFuncKeysReal **)(*piVar5 + 0x210), fStack_7c,
                            &fStack_6c, (ulong *)&fStack_70);
    piVar5 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
        *(ulong *)(*(int *)(this + 100) + 0x24));
    CFuncKeysReal::GetValue(*(CFuncKeysReal **)(*piVar5 + 0x214), fStack_7c,
                            &fStack_74, (ulong *)&fStack_70);
    fStack_24 = -fStack_74 * fStack_30;
    fStack_20 = -fStack_6c * fStack_2c;
    fStack_1c = -fStack_74 * fStack_28;
    GmVec3::MultTranspose((GmVec3 *)&fStack_24, pGVar4);
    CSceneVehicle::WaterSplash((CSceneVehicle *)this, (GmVec3 *)&fStack_30);
    AddVehicleImpulse(this, (GmVec3 *)&fStack_24);
  } else {
    fVar10 = (float10)__CIsqrt();
    fStack_70 = (float)fVar10;
    fStack_7c = -fStack_70 / fStack_2c;
    if (0.0 < fStack_7c != (fStack_7c == 0.0))
      goto LAB_007c2b35;
  }
  if (0.0 <= fStack_7c) {
    return 0;
  }
LAB_007c2bef:
  fStack_6c =
      fStack_58 * fStack_58 + fStack_60 * fStack_60 + fStack_5c * fStack_5c;
  fVar10 = (float10)__CIsqrt();
  fVar1 = (float)fVar10;
  fStack_1c = 0.0;
  fStack_20 = 0.0;
  fStack_24 = 0.0;
  fStack_6c = fVar1;
  if (1e-05 < fVar1 != NAN(fVar1)) {
    ppCVar9 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
        *(ulong *)(*(int *)(this + 100) + 0x24));
    fStack_6c =
        CSceneVehicleCarTuning::GetWaterFrictionFromSpeed(*ppCVar9, fVar1);
    fStack_6c = -fStack_6c;
    fStack_24 = fStack_6c * fStack_60;
    fStack_20 = fStack_5c * fStack_6c;
    fStack_1c = fStack_6c * fStack_58;
  }
  CHmsItem::GetAngularSpeed(*(CHmsItem **)(this + 0x28), (GmVec3 *)&fStack_54);
  iVar6 = *(int *)(this + 100);
  piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar6 + 0x14),
                                            *(ulong *)(iVar6 + 0x24));
  fStack_6c = -*(float *)(*piVar5 + 0x21c);
  fStack_3c = fStack_6c * fStack_54;
  fStack_38 = fStack_50 * fStack_6c;
  fStack_34 = fStack_6c * fStack_4c;
  piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar6 + 0x14),
                                            *(ulong *)(iVar6 + 0x24));
  fStack_6c =
      fStack_50 * fStack_50 + fStack_54 * fStack_54 + fStack_4c * fStack_4c;
  fVar10 = (float10)__CIsqrt();
  fVar1 = -(float)fVar10 * *(float *)(*piVar5 + 0x220);
  fStack_68 = fStack_50 * fVar1;
  fStack_64 = fVar1 * fStack_4c;
  fStack_3c = fVar1 * fStack_54 + fStack_3c;
  fStack_38 = fStack_68 + fStack_38;
  fStack_34 = fStack_64 + fStack_34;
  fStack_6c = 0.0;
  piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar6 + 0x14),
                                            *(ulong *)(iVar6 + 0x24));
  fStack_68 = -*(float *)(*piVar5 + 0x204);
  fStack_64 = 0.0;
  GmVec3::MultTranspose((GmVec3 *)&fStack_6c, pGVar4);
  fStack_48 = (fStack_6c + fStack_24) - *(float *)param_1;
  fStack_44 = (fStack_68 + fStack_20) - *(float *)(param_1 + 4);
  fStack_40 = (fStack_64 + fStack_1c) - *(float *)(param_1 + 8);
  AddVehicleCentralForce(this, (GmVec3 *)&fStack_48);
  AddVehicleTorque(this, (GmVec3 *)&fStack_3c);
  return 1;
}

/* public: virtual void __thiscall CSceneVehicleCar::Chunk(class CClassicArchive
 * &,unsigned long) */

void __thiscall CSceneVehicleCar::Chunk(CSceneVehicleCar *this,
                                        CClassicArchive *param_1, ulong param_2)

{
  int iVar1;
  CClassicArchive *pCVar2;
  SSplit *pSVar3;
  CGameCamera *pCVar4;
  SRenderTarget *pSVar5;
  STexStageCat *pSVar6;
  SVisualWheel *this_00;
  int *piVar7;
  CFastBuffer<> *pCVar8;
  ulong uVar9;
  CFastBuffer<> *this_01;
  ulong uVar10;
  CMwNod *pCVar11;
  CClassicArchive *pCVar12;
  CMwNod *local_40;
  SRenderTarget *local_3c;
  CFastBuffer<> *local_38;
  STexStageCat *local_34;
  ulong local_30;
  ulong local_2c;
  ulong local_28;
  char *local_24;
  SStringParam local_20[8];
  float local_18;
  float fStack_14;
  float fStack_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  pCVar2 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00accc1b;
  local_c = ExceptionList;
  if (param_2 < 0xa02b00c) {
    if (param_2 == 0xa02b00b) {
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x28c));
      CClassicArchive::MwDoNodRef<>(pCVar2, (CMwNodRef<> *)(this + 0x298));
      ExceptionList = local_c;
      return;
    }
    switch (param_2) {
    case 0xa02b000:
      ExceptionList = &local_c;
      CreateOldStruct(this);
      pCVar2 = param_1;
      CClassicArchive::DoNatural(param_1, &param_2, 1, 0);
      iVar1 = *(int *)(this + 0x60);
      uVar9 = CFastBuffer<>::GetCount((CFastBuffer<> *)(iVar1 + 0x14));
      uVar10 = 0;
      if (uVar9 != 0) {
        do {
          pCVar12 = pCVar2;
          pSVar6 = CFastBuffer<>::operator[](
              (CFastBuffer<> *)(CFastBuffer<> *)(iVar1 + 0x14), uVar10);
          CMwId::Archive((CMwId *)pSVar6, pCVar12);
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar9);
        ExceptionList = local_c;
        return;
      }
      ExceptionList = local_c;
      return;
    case 0xa02b001:
      ExceptionList = &local_c;
      CreateOldStruct(this);
      pCVar2 = param_1;
      CClassicArchive::DoNatural(param_1, &local_30, 1, 0);
      pCVar8 = (CFastBuffer<> *)(*(int *)(this + 0x60) + 0x14);
      param_2 = (ulong)pCVar8;
      pSVar5 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 0x60) + 0x20), 0);
      local_40 = (CMwNod *)CFastBuffer<>::GetCount(pCVar8);
      pCVar11 = (CMwNod *)0x0;
      if (local_40 != (CMwNod *)0x0) {
        local_3c = pSVar5 + 0x24;
        do {
          piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar8,
                                                    (ulong)pCVar11);
          pSVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)local_3c,
                                             (ulong)pCVar11);
          CMwId::CMwId((CMwId *)&param_1);
          local_4 = 0;
          CMwId::Archive((CMwId *)&param_1, pCVar2);
          CClassicArchive::DoNatural(pCVar2, (ulong *)&local_34, 1, 0);
          CMwId::Archive((CMwId *)piVar7, pCVar2);
          if (*piVar7 != -1) {
            local_28 = 0;
            local_24 = "";
            local_4._0_1_ = 1;
            CMwId::GetName((CMwId *)piVar7, (CFastString *)&local_28);
            SStringParam::SStringParam(local_20, "Mesh");
            CFastString::Concat((CFastString *)&local_28, local_20);
            CMwId::SetLocalName((CMwId *)pSVar3, local_24);
            local_4 = (uint)local_4._1_3_ << 8;
            CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(
                (SHeaderCommunity *)&local_28);
          }
          CClassicArchive::DoBool(pCVar2, piVar7 + 1, 1);
          CClassicArchive::DoBool(pCVar2, piVar7 + 2, 1);
          if (*(int *)(pCVar2 + 8) == 0) {
            piVar7[1] = 1;
          }
          local_4 = 0xffffffff;
          CScene2d::OnNodLoaded((CScene2d *)&param_1);
          pCVar11 = pCVar11 + 1;
          pCVar8 = (CFastBuffer<> *)param_2;
        } while (pCVar11 < local_40);
        ExceptionList = local_c;
        return;
      }
      ExceptionList = local_c;
      return;
    case 0xa02b002:
      ExceptionList = &local_c;
      CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)&local_18);
      pCVar2 = param_1;
      local_4 = 2;
      CFastBuffer<>::ArchiveFastBufferNod((CFastBuffer<> *)&local_18, param_1);
      CFastBuffer<>::AddRefAll((CFastBuffer<> *)&local_18);
      CFastBuffer<>::ReleaseAll((CFastBuffer<> *)&local_18);
      CClassicArchive::DoNatural(pCVar2, (ulong *)&param_1, 1, 0);
      CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)&local_18);
      ExceptionList = local_c;
      return;
    case 0xa02b003:
      param_2 = *(ulong *)(this + 100);
      ExceptionList = &local_c;
      (**(code **)(*(int *)param_1 + 4))(&param_2);
      if (*(int *)(pCVar2 + 8) == 0) {
        CSceneVehicle::TuningsSet((CSceneVehicle *)this,
                                  (CSceneVehicleTunings *)param_2);
        ExceptionList = local_c;
        return;
      }
      ExceptionList = local_c;
      return;
    case 0xa02b004:
      param_2 = 0;
      ExceptionList = &local_c;
      (**(code **)(*(int *)param_1 + 4))(&param_2);
      ExceptionList = local_c;
      return;
    case 0xa02b005:
      param_2 = 0;
      ExceptionList = &local_c;
      (**(code **)(*(int *)param_1 + 4))(&param_2);
      fStack_10 = 0.0;
      fStack_14 = 0.0;
      local_18 = 0.0;
      CClassicArchive::DoReal(pCVar2, &local_18, 1);
      CClassicArchive::DoReal(pCVar2, &fStack_14, 1);
      CClassicArchive::DoReal(pCVar2, &fStack_10, 1);
      ExceptionList = local_c;
      return;
    case 0xa02b006:
      local_3c = (SRenderTarget *)0x0;
      local_40 = (CMwNod *)0x0;
      param_2 = 0;
      local_4._0_1_ = 5;
      local_4._1_3_ = 0;
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)&local_3c);
      CClassicArchive::MwDoNodRef<>(pCVar2, (CMwNodRef<> *)&local_40);
      CClassicArchive::MwDoNodRef<>(pCVar2, (CMwNodRef<> *)&param_2);
      local_4._0_1_ = 4;
      if (param_2 != 0) {
        CMwNod::MwRelease((CMwNod *)param_2);
      }
      local_4 = CONCAT31(local_4._1_3_, 3);
      if (local_40 != (CMwNod *)0x0) {
        CMwNod::MwRelease(local_40);
      }
      local_4 = 0xffffffff;
      if (local_3c != (SRenderTarget *)0x0) {
        CMwNod::MwRelease((CMwNod *)local_3c);
        ExceptionList = local_c;
        return;
      }
      ExceptionList = local_c;
      return;
    case 0xa02b007:
      param_2 = 0;
      ExceptionList = &local_c;
      (**(code **)(*(int *)param_1 + 4))(&param_2, ___security_cookie ^
                                                       (uint)&stack0xffffffb0);
      CClassicArchive::DoReal(pCVar2, &local_18, 1);
      CClassicArchive::DoReal(pCVar2, &fStack_14, 1);
      CClassicArchive::DoReal(pCVar2, &fStack_10, 1);
      ExceptionList = local_c;
      return;
    case 0xa02b008:
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x68));
      if (*(int *)(pCVar2 + 8) == 0) {
        CSceneVehicle::BuildVehicleMaterialsRemap((CSceneVehicle *)this);
        ExceptionList = local_c;
        return;
      }
      ExceptionList = local_c;
      return;
    case 0xa02b009:
      ExceptionList = &local_c;
      CreateOldStruct(this);
      pCVar2 = param_1;
      CClassicArchive::DoNatural(param_1, &local_30, 1, 0);
      pCVar8 = (CFastBuffer<> *)(*(int *)(this + 0x60) + 0x14);
      param_2 = (ulong)pCVar8;
      pSVar5 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 0x60) + 0x20), 0);
      local_40 = (CMwNod *)CFastBuffer<>::GetCount(pCVar8);
      pCVar11 = (CMwNod *)0x0;
      if (local_40 != (CMwNod *)0x0) {
        local_3c = pSVar5 + 0x24;
        do {
          pSVar6 = CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar8,
                                             (ulong)pCVar11);
          pSVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)local_3c,
                                             (ulong)pCVar11);
          CMwId::CMwId((CMwId *)&param_1);
          local_4 = 6;
          CMwId::Archive((CMwId *)&param_1, pCVar2);
          CClassicArchive::DoNatural(pCVar2, (ulong *)&local_34, 1, 0);
          CMwId::Archive((CMwId *)pSVar6, pCVar2);
          CMwId::Archive((CMwId *)pSVar3, pCVar2);
          CClassicArchive::DoBool(pCVar2, (int *)(pSVar6 + 4), 1);
          CClassicArchive::DoBool(pCVar2, (int *)(pSVar6 + 8), 1);
          local_4 = 0xffffffff;
          CScene2d::OnNodLoaded((CScene2d *)&param_1);
          pCVar11 = pCVar11 + 1;
          pCVar8 = (CFastBuffer<> *)param_2;
        } while (pCVar11 < local_40);
        ExceptionList = local_c;
        return;
      }
      ExceptionList = local_c;
      return;
    case 0xa02b00a:
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)&param_1, 1);
      CClassicArchive::DoReal(pCVar2, (float *)&param_2, 1);
      CClassicArchive::DoReal(pCVar2, (float *)(this + 0x2e0), 1);
      CClassicArchive::DoReal(pCVar2, (float *)(this + 0x5cc), 1);
      ExceptionList = local_c;
      return;
    }
  } else if (param_2 < 0xa02b012) {
    if (param_2 == 0xa02b011) {
      return;
    }
    switch (param_2) {
    case 0xa02b00c:
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)(this + 0x2e0), 1);
      CClassicArchive::DoReal(pCVar2, (float *)(this + 0x5cc), 1);
      GmBoxAligned::ArchiveABox((GmBoxAligned *)(this + 0x1dc), pCVar2);
      ExceptionList = local_c;
      return;
    case 0xa02b00d:
    case 0xa02b00e:
    case 0xa02b00f:
    case 0xa02b010:
      return;
    }
  } else if (param_2 < 0xa02b015) {
    if (param_2 == 0xa02b014) {
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x60));
      ExceptionList = local_c;
      return;
    }
    if (param_2 == 0xa02b012) {
      return;
    }
    if (param_2 == 0xa02b013) {
      ExceptionList = &local_c;
      param_2 = (ulong)operator_new(0x50);
      local_4 = 7;
      if ((CSceneVehicleStruct *)param_2 == (CSceneVehicleStruct *)0x0) {
        pCVar4 = (CGameCamera *)0x0;
      } else {
        pCVar4 = (CGameCamera *)CSceneVehicleStruct::CSceneVehicleStruct(
            (CSceneVehicleStruct *)param_2);
      }
      piVar7 = (int *)(this + 0x60);
      local_4 = 0xffffffff;
      CMwNodRef<>::MwSetNod((CMwNodRef<> *)piVar7, pCVar4);
      this_01 = (CFastBuffer<> *)(*piVar7 + 0x14);
      local_38 = this_01;
      CFastBuffer<>::AddNewElem((CFastBuffer<> *)(*piVar7 + 0x20));
      pSVar5 = CFastBuffer<>::operator[]((CFastBuffer<> *)(*piVar7 + 0x20), 0);
      pCVar2 = param_1;
      param_2 = (ulong)pSVar5;
      CFastBuffer<>::ArchiveCount(this_01, param_1);
      local_30 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_01);
      uVar9 = 0;
      if (local_30 != 0) {
        do {
          pSVar6 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_01, uVar9);
          local_34 = pSVar6;
          this_00 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)(pSVar5 + 0x24));
          CMwId::CMwId((CMwId *)&local_40);
          local_4 = 8;
          CMwId::Archive((CMwId *)&local_40, pCVar2);
          CClassicArchive::DoNatural(pCVar2, (ulong *)&local_3c, 1, 0);
          param_1 = (CClassicArchive *)0x0;
          if (local_3c != (SRenderTarget *)0x0) {
            do {
              piVar7 = (int *)CFastBuffer<>::AddNewElem(
                  (CFastBuffer<> *)(param_2 + 0x30));
              CMwId::Archive((CMwId *)(piVar7 + 7), pCVar2);
              CClassicArchive::DoBool(pCVar2, piVar7, 1);
              CClassicArchive::DoBool(pCVar2, piVar7 + 1, 1);
              param_1 = param_1 + 1;
              pSVar6 = local_34;
            } while (param_1 < local_3c);
          }
          *(ulong *)(this_00 + 0x20) = uVar9;
          CClassicArchive::DoNatural(pCVar2, &local_2c, 1, 0);
          CMwId::Archive((CMwId *)pSVar6, pCVar2);
          CMwId::Archive((CMwId *)this_00, pCVar2);
          CClassicArchive::DoBool(pCVar2, (int *)(this_00 + 4), 1);
          CMwId::Archive((CMwId *)(this_00 + 0x10), pCVar2);
          CClassicArchive::DoBool(pCVar2, (int *)(this_00 + 0x14), 1);
          CMwId::Archive((CMwId *)(this_00 + 8), pCVar2);
          CClassicArchive::DoBool(pCVar2, (int *)(this_00 + 0xc), 1);
          CClassicArchive::DoBool(pCVar2, (int *)((CMwId *)pSVar6 + 4), 1);
          CClassicArchive::DoBool(pCVar2, (int *)((CMwId *)pSVar6 + 8), 1);
          local_4 = 0xffffffff;
          CScene2d::OnNodLoaded((CScene2d *)&local_40);
          uVar9 = uVar9 + 1;
          this_01 = local_38;
          pSVar5 = (SRenderTarget *)param_2;
        } while (uVar9 < local_30);
      }
      CMwId::Archive((CMwId *)(pSVar5 + 4), pCVar2);
      CMwId::Archive((CMwId *)(pSVar5 + 0xc), pCVar2);
      CClassicArchive::DoNatural(pCVar2, &local_28, 1, 0);
      ExceptionList = local_c;
      return;
    }
  } else if (param_2 == 0xffffffff) {
    return;
  }
  ExceptionList = &local_c;
  CSceneVehicle::Chunk((CSceneVehicle *)this, param_1, param_2);
  ExceptionList = local_c;
  return;
}

/* protected: void __thiscall CSceneVehicleCar::ComputeAirControl(class GmVec3
   const &,unsigned long,int,int) */

void __thiscall CSceneVehicleCar::ComputeAirControl(CSceneVehicleCar *this,
                                                    GmVec3 *param_1,
                                                    ulong param_2, int param_3,
                                                    int param_4)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  GmVec3 *pGVar4;
  int *piVar5;
  int *piVar6;
  float10 fVar7;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  iVar2 = *(int *)(this + 100);
  piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  if (((*(int *)(*piVar5 + 0x354) == 4) ||
       (piVar5 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24)),
        *(int *)(*piVar5 + 0x354) == 5)) &&
      (*(int *)(this + 0x5e4) != 0)) {
    return;
  }
  pGVar4 = param_1;
  local_18 = -*(float *)param_1;
  local_14 = -*(float *)(param_1 + 4);
  local_10 = -*(float *)(param_1 + 8);
  if (param_4 != 0) {
    *(ulong *)(this + 0x614) = param_2;
    *(undefined4 *)(this + 0x618) = *(undefined4 *)param_1;
    *(undefined4 *)(this + 0x61c) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 0x620) = *(undefined4 *)(param_1 + 8);
    goto LAB_007bf480;
  }
  if (*(int *)(this + 0x5d4) != 0) {
    *(undefined4 *)(this + 0x618) = *(undefined4 *)param_1;
    *(undefined4 *)(this + 0x61c) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 0x620) = *(undefined4 *)(param_1 + 8);
    goto LAB_007bf480;
  }
  piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  if (*(uint *)(*piVar5 + 0x364) <= param_2 - *(int *)(this + 0x614))
    goto LAB_007bf480;
  local_c = *(float *)pGVar4;
  bVar3 = false;
  local_8 = *(float *)(pGVar4 + 4);
  local_4 = *(float *)(pGVar4 + 8);
  if (((1e-05 < *(float *)(this + 0x58) != NAN(*(float *)(this + 0x58))) &&
       (*(float *)(this + 0x61c) < 0.0)) ||
      ((*(float *)(this + 0x58) < -1e-05 &&
        (0.0 < *(float *)(this + 0x61c) != NAN(*(float *)(this + 0x61c)))))) {
    piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    param_2 = (ulong)ABS(*(float *)(pGVar4 + 4));
    if (*(float *)(*piVar5 + 0x368) < (float)param_2 !=
        (NAN(*(float *)(*piVar5 + 0x368)) || NAN((float)param_2))) {
      bVar3 = true;
      goto LAB_007bf388;
    }
  } else {
    if ((1e-05 < *(float *)(this + 0x58) == NAN(*(float *)(this + 0x58))) ||
        (0.0 < *(float *)(this + 0x61c) == NAN(*(float *)(this + 0x61c)))) {
      if ((*(float *)(this + 0x58) < -1e-05) &&
          (*(float *)(this + 0x61c) < 0.0)) {
        bVar3 = true;
      }
    } else {
      bVar3 = true;
    }
  LAB_007bf388:
    *(undefined4 *)(this + 0x61c) = *(undefined4 *)(pGVar4 + 4);
  }
  local_8 = *(float *)(this + 0x61c);
  piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  if ((*(int *)(*piVar5 + 0x354) == 4) ||
      (piVar5 = (int *)CFastBuffer<>::operator[](
           (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24)),
       *(int *)(*piVar5 + 0x354) == 5)) {
    if ((1e-05 < *(float *)(this + 0x54) == NAN(*(float *)(this + 0x54))) ||
        (uVar1 = 0,
         0.0 < *(float *)(this + 0x618) == NAN(*(float *)(this + 0x618)))) {
      uVar1 = *(undefined4 *)pGVar4;
    }
    *(undefined4 *)(this + 0x618) = uVar1;
    local_c = *(float *)(this + 0x618);
  }
  if (bVar3) {
    local_18 = local_18 * 3.0;
    local_14 = local_14 * 3.0;
    local_10 = local_10 * 3.0;
  }
  if (param_3 == 0) {
    param_2 = 0;
    piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    param_1 = (GmVec3 *)ABS(*(float *)(pGVar4 + 8));
    CFuncKeysReal::GetValue(*(CFuncKeysReal **)(*piVar5 + 0x36c),
                            (float)param_1, (float *)&param_1, &param_2);
    local_10 = local_10 * (float)param_1;
  }
  SetVehicleAngularSpeed(this, (GmVec3 *)&local_c);
LAB_007bf480:
  if (param_3 == 0) {
    param_2 = (ulong)(local_14 * local_14 + local_18 * local_18 +
                      local_10 * local_10);
    fVar7 = (float10)__CIsqrt();
    param_2 = (ulong)(float)fVar7;
    if (1e-05 <= (float)param_2) {
      iVar2 = *(int *)(this + 100);
      param_3 = (int)(1.0 / (float)param_2);
      local_c = (float)param_3 * local_18;
      local_8 = (float)param_3 * local_14;
      local_4 = (float)param_3 * local_10;
      piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                                *(ulong *)(iVar2 + 0x24));
      piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                                *(ulong *)(iVar2 + 0x24));
      param_2 = (ulong)((float)param_2 * *(float *)(*piVar6 + 0x158) +
                        (float)param_2 * (float)param_2 *
                            *(float *)(*piVar5 + 0x15c));
      local_c = (float)param_2 * local_c;
      local_8 = local_8 * (float)param_2;
      local_4 = (float)param_2 * local_4;
      AddVehicleTorque(this, (GmVec3 *)&local_c);
      return;
    }
  }
  return;
}

/* protected: void __thiscall CSceneVehicleCar::ComputeAsyncState(void) */

void __thiscall CSceneVehicleCar::ComputeAsyncState(CSceneVehicleCar *this)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  SSimulationWheel *pSVar4;
  uint *puVar5;
  CMwCmdBufferCore *pCVar6;
  int *piVar7;
  int iVar8;
  undefined4 extraout_ECX;
  ulong uVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  float10 fVar13;
  float fVar14;
  float local_c;
  float local_8;

  puVar10 = (undefined4 *)(this + 0x448);
  puVar12 = (undefined4 *)(this + 0x4f0);
  for (iVar8 = 0x2a; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar12 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar12 = puVar12 + 1;
  }
  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar9 = 0;
  if (uVar3 != 0) {
    do {
      pSVar4 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), uVar9);
      uVar9 = uVar9 + 1;
      puVar10 = (undefined4 *)(pSVar4 + 0x298);
      puVar12 = (undefined4 *)(pSVar4 + 0x234);
      for (iVar8 = 0x19; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
    } while (uVar9 < uVar3);
  }
  pCVar6 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
  if (pCVar6 == (CMwCmdBufferCore *)0x0) {
    pCVar6 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
  }
  puVar5 = (uint *)CPlugAudio::MwGetId((CPlugAudio *)pCVar6);
  uVar11 = *puVar5;
  if (*(int *)(this + 0x78) != 0) {
    if (CHmsDyna::s_PredictionDelayPHBInterpolation < uVar11) {
      uVar11 = uVar11 - CHmsDyna::s_PredictionDelayPHBInterpolation;
    } else {
      uVar11 = 0;
    }
  }
  iVar8 = CSceneMobil::IsZombie((CSceneMobil *)this);
  if (iVar8 == 0) {
    puVar5 = (uint *)CMwCmdBufferCore::GetSchemeProperies(
        CMwCmdBufferCore::TheCoreCmdBuffer, 0x8c);
    uVar1 = *puVar5;
    iVar8 = (uVar11 / uVar1) * uVar1;
    if (iVar8 - uVar11 == 0) {
      local_c = 1.0;
    } else {
      iVar8 = uVar11 - iVar8;
      local_c = (float)iVar8;
      if (iVar8 < 0) {
        local_c = local_c + 4.294967e+09;
      }
      fVar14 = (float)uVar1;
      if ((int)uVar1 < 0) {
        fVar14 = fVar14 + 4.294967e+09;
      }
      local_c = local_c / fVar14;
    }
  LAB_007be845:
    if (local_c < 0.0 == NAN(local_c)) {
      if (1.0 < local_c == NAN(local_c)) {
        if (NAN(local_c) != (local_c == 0.0))
          goto LAB_007be87e;
        if (NAN(local_c) == (local_c == 1.0)) {
          SVehicleCarState::SetBlend((SVehicleCarState *)(this + 0x448),
                                     (SVehicleCarState *)(this + 0x2f8),
                                     (SVehicleCarState *)(this + 0x3a0),
                                     local_c);
          goto LAB_007be8d0;
        }
      } else {
        local_c = 1.0;
      }
    LAB_007be89f:
      SVehicleCarState::Set((SVehicleCarState *)(this + 0x448),
                            (SVehicleCarState *)(this + 0x3a0));
      goto LAB_007be8d0;
    }
    local_c = 0.0;
  } else {
    uVar1 = *(uint *)(*(int *)(this + 0x28) + 0x4c);
    if (uVar1 == 0xffffffff) {
      local_c = 0.0;
    } else {
      uVar2 = *(uint *)(*(int *)(this + 0x28) + 0x48);
      if (uVar1 == uVar2) {
        local_c = 0.0;
      } else {
        if (uVar2 <= uVar11) {
          if (uVar11 <= uVar1) {
            local_c = (float)(uVar11 - uVar2);
            if ((int)(uVar11 - uVar2) < 0) {
              local_c = local_c + 4.294967e+09;
            }
            fVar14 = (float)(uVar1 - uVar2);
            if ((int)(uVar1 - uVar2) < 0) {
              fVar14 = fVar14 + 4.294967e+09;
            }
            local_c = local_c / fVar14;
            goto LAB_007be845;
          }
          local_c = 1.0;
          goto LAB_007be89f;
        }
        local_c = 0.0;
      }
    }
  }
LAB_007be87e:
  SVehicleCarState::Set((SVehicleCarState *)(this + 0x448),
                        (SVehicleCarState *)(this + 0x2f8));
LAB_007be8d0:
  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar9 = 0;
  if (uVar3 != 0) {
    do {
      pSVar4 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), uVar9);
      local_8 = *(float *)(pSVar4 + 0x29c);
      SSimulationWheel::SState::SetBlend((SState *)(pSVar4 + 0x298),
                                         (SState *)(pSVar4 + 0x16c),
                                         (SState *)(pSVar4 + 0x1d0), local_c);
      if (*(int *)(this + 0x78) != 0) {
        pCVar6 =
            *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
        if (pCVar6 == (CMwCmdBufferCore *)0x0) {
          pCVar6 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
        }
        fVar14 = CMwTimerAdapter::GetAsyncPeriod((CMwTimerAdapter *)pCVar6);
        *(float *)(pSVar4 + 0x29c) = local_8;
        local_8 = (*(float *)(this + 0x448) / *(float *)(pSVar4 + 8)) * fVar14 +
                  local_8;
        *(float *)(pSVar4 + 0x29c) = local_8;
        if ((local_8 < 0.0) || (local_8 < 1608.495 == NAN(local_8))) {
          fVar13 = (float10)__CIfmod(extraout_ECX);
          local_8 = (float)fVar13;
          if (local_8 < 0.0 != NAN(local_8)) {
            local_8 = local_8 + 1608.495;
          }
          local_8 = local_8 + 0.0;
        }
        *(float *)(pSVar4 + 0x29c) = local_8;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar3);
  }
  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  if (uVar3 != 0) {
    uVar9 = 0;
    do {
      pSVar4 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), uVar9);
      *(undefined4 *)(pSVar4 + 700) = *(undefined4 *)(pSVar4 + 100);
      *(undefined4 *)(pSVar4 + 0x2c0) = *(undefined4 *)(pSVar4 + 0x68);
      *(undefined4 *)(pSVar4 + 0x2c4) = *(undefined4 *)(pSVar4 + 0x6c);
      *(float *)(pSVar4 + 0x2c0) =
          *(float *)(pSVar4 + 0x2c0) - *(float *)(pSVar4 + 8);
      piVar7 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
      iVar8 = *piVar7;
      *(float *)(pSVar4 + 0x2b0) =
          *(float *)(iVar8 + 0x20) * *(float *)(pSVar4 + 0x2c4) +
          *(float *)(pSVar4 + 700) * *(float *)(iVar8 + 0x18) +
          *(float *)(iVar8 + 0x1c) * *(float *)(pSVar4 + 0x2c0) +
          *(float *)(iVar8 + 0x3c);
      *(float *)(pSVar4 + 0x2b4) =
          *(float *)(iVar8 + 0x2c) * *(float *)(pSVar4 + 0x2c4) +
          *(float *)(iVar8 + 0x28) * *(float *)(pSVar4 + 0x2c0) +
          *(float *)(iVar8 + 0x24) * *(float *)(pSVar4 + 700) +
          *(float *)(iVar8 + 0x40);
      *(float *)(pSVar4 + 0x2b8) =
          *(float *)(iVar8 + 0x38) * *(float *)(pSVar4 + 0x2c4) +
          *(float *)(iVar8 + 0x34) * *(float *)(pSVar4 + 0x2c0) +
          *(float *)(iVar8 + 0x30) * *(float *)(pSVar4 + 700) +
          *(float *)(iVar8 + 0x44);
      GmMat3::Set((GmMat3 *)(pSVar4 + 0x2c8), (GmMat3 *)(pSVar4 + 0x40));
      GmMat3::RotateY((GmMat3 *)(pSVar4 + 0x2c8), *(float *)(pSVar4 + 0x2a0));
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar3);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CSceneVehicleCar::ComputeForces(float) */

void __thiscall CSceneVehicleCar::ComputeForces(CSceneVehicleCar *this,
                                                float param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  ulong *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  ulong uVar12;
  SSimulationWheel *pSVar13;
  CMwTimerAdapter *this_00;
  ulong uVar14;
  float10 fVar15;
  float fVar16;
  ulong local_78;
  float local_74;
  undefined8 local_70;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  GmVec3 local_34[12];
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  local_1c = *(float *)(this + 0x824);
  local_18 = *(undefined4 *)(this + 0x828);
  local_14 = *(float *)(this + 0x82c);
  local_28 = *(float *)(this + 0x818);
  local_24 = *(undefined4 *)(this + 0x81c);
  local_20 = *(float *)(this + 0x820);
  *(undefined4 *)(this + 0x820) = 0;
  *(undefined4 *)(this + 0x81c) = 0;
  *(undefined4 *)(this + 0x818) = 0;
  *(undefined4 *)(this + 0x82c) = 0;
  *(undefined4 *)(this + 0x828) = 0;
  *(undefined4 *)(this + 0x824) = 0;
  if ((((byte)this[0x2f4] & 0x30) == 0) && (0.0 <= *(float *)(this + 0x1e8))) {
    CreateFakeContacts(this);
    IntegrateVehicle(this, param_1);
    this_00 = *(CMwTimerAdapter **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
    if (this_00 == (CMwTimerAdapter *)0x0) {
      this_00 = (CMwTimerAdapter *)(CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0);
    }
    puVar5 = CMwTimerAdapter::GetTickTime(this_00);
    local_54 = (float)*puVar5;
    iVar6 = IsGroundContact(this);
    iVar11 = *(int *)(*(int *)(this + 0x28) + 0x14);
    iVar10 = *(int *)(this + 100);
    local_50 = (float)(iVar11 + 0x18);
    local_58 = (float)iVar6;
    if (iVar6 == 0) {
      piVar7 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar10 + 0x14), *(ulong *)(iVar10 + 0x24));
      local_5c = *(float *)(*piVar7 + 0x164);
    } else {
      piVar7 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar10 + 0x14), *(ulong *)(iVar10 + 0x24));
      local_5c = *(float *)(*piVar7 + 0x160);
    }
    *(float *)(iVar11 + 0x4c) = local_5c;
    if (iVar6 == 0) {
      piVar7 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      local_5c = *(float *)(*piVar7 + 0x154);
    } else {
      local_5c = 0.0;
    }
    *(float *)(iVar11 + 0x40) = local_5c;
    if (((byte)this[0x2f4] & 2) != 0) {
      local_64 = 0.0;
      CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),
                               (GmVec3 *)&local_4c);
      if (((byte)this[0x2f4] & 8) == 0) {
        CHmsItem::GetAngularSpeed(*(CHmsItem **)(this + 0x28), local_34);
        CHmsItem::GetForce(*(CHmsItem **)(this + 0x28), (GmVec3 *)&local_40);
        *(undefined4 *)(this + 0x5b0) = 0;
        ApplyFrictionForces(this, (GmVec3 *)&local_4c);
        fVar16 = *(float *)(this + 0x2e0) * *(float *)(this + 0x2e0);
        local_70 = (double)CONCAT44(local_70._4_4_, fVar16);
        local_5c =
            local_44 * local_44 + local_4c * local_4c + local_48 * local_48;
        if ((fVar16 < local_5c != (NAN(fVar16) || NAN(local_5c))) &&
            (_DAT_00d06a80 < fVar16 != (NAN(_DAT_00d06a80) || NAN(fVar16)))) {
          local_70 = (double)*(float *)(this + 0x2e0);
          fVar15 = (float10)__CIsqrt();
          local_5c = (float)local_70 / (float)fVar15;
          local_4c = local_5c * local_4c;
          local_48 = local_48 * local_5c;
          local_44 = local_5c * local_44;
          SetVehicleLinearSpeed(this, (GmVec3 *)&local_4c);
        }
        local_10 = 0x3f800000;
        local_c = 0x3f800000;
        local_8 = 0x3f800000;
        local_4 = 0x3f800000;
        local_78 = 0;
        ComputeVehicleGroundMaterialVals(this, (SBlendableVals *)&local_10,
                                         (int *)&local_78);
        local_70 = (double)CONCAT44(local_70._4_4_, 0x3f800000);
        local_74 = 1.0;
        GetSlopeAdherence(this, (GmVec3 *)&local_40, (float *)&local_70,
                          &local_74);
        iVar11 = *(int *)(this + 100);
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
        piVar8 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
        local_5c = ABS(local_44) * *(float *)(*piVar7 + 0x70) +
                   *(float *)(*piVar8 + 0x6c);
        if (local_5c < 1e-05 == NAN(local_5c)) {
          local_5c = 1.0 / local_5c;
          local_5c = GmFunc::AsinSafe(local_5c);
        } else {
          local_5c = 0.0;
        }
        local_5c = -*(float *)(this + 0x5e8) * local_5c;
        *(float *)(this + 0x70c) = local_4c;
        *(float *)(this + 0x710) = local_48;
        local_60 = 0.0;
        *(float *)(this + 0x714) = local_44;
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
        if (*(int *)(*piVar7 + 0x354) == 3) {
          ComputeForcesModel4(
              this, param_1, (GmVec3 *)&local_40, (float)local_70, local_74,
              (GmVec3 *)&local_4c, local_34, local_5c, local_78,
              (SBlendableVals *)&local_10, (int *)&local_60, &local_64);
        } else {
          piVar7 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          if (*(int *)(*piVar7 + 0x354) == 4) {
            ComputeForcesModel5(
                this, param_1, (GmVec3 *)&local_40, (float)local_70, local_74,
                (GmVec3 *)&local_4c, local_34, local_5c, local_78,
                (SBlendableVals *)&local_10, (int *)&local_60, &local_64);
          } else {
            piVar7 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
            if (*(int *)(*piVar7 + 0x354) == 5) {
              ComputeForcesModel6(
                  this, param_1, (GmVec3 *)&local_40, (float)local_70, local_74,
                  (GmVec3 *)&local_4c, local_34, local_5c, local_78,
                  (SBlendableVals *)&local_10, (int *)&local_60, &local_64);
            } else {
              ComputeForcesModel3(
                  this, param_1, (GmVec3 *)&local_40, (float)local_70, local_74,
                  (GmVec3 *)&local_4c, local_34, local_5c, local_78,
                  (SBlendableVals *)&local_10, (int *)&local_60, &local_64);
            }
          }
        }
        uVar14 = 0;
        local_5c = 0.0;
        local_70 = (double)((ulonglong)local_70 & 0xffffffff00000000);
        uVar12 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
        if (uVar12 != 0) {
          do {
            piVar7 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar14);
            if (piVar7[0x49] != 0) {
              local_70 = (double)CONCAT44(local_70._4_4_, 1);
              if (*piVar7 != 0) {
                local_5c = 1.401298e-45;
              }
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 < uVar12);
          if ((float)local_70 != 0.0) {
            piVar7 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                *(ulong *)(*(int *)(this + 100) + 0x24));
            *(float *)(this + 0x5b0) =
                -*(float *)(this + 0x54) * *(float *)(this + 0x5a8) -
                *(float *)(*piVar7 + 0x58) * *(float *)(this + 0x5ac);
          }
          if ((local_5c != 0.0) &&
              (piVar7 = (int *)CFastBuffer<>::operator[](
                   (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                   *(ulong *)(*(int *)(this + 100) + 0x24)),
               *(float *)(*piVar7 + 0xa4) < 0.0)) {
            local_4c = 0.0;
            SetVehicleLinearSpeed(this, (GmVec3 *)&local_4c);
          }
        }
        uVar4 = (uint)local_54;
        iVar11 = (int)local_58;
        ComputeAirControl(this, local_34, (ulong)local_54, (int)local_58,
                          (int)local_5c);
        if (1e-05 < *(float *)(this + 0x5c) != NAN(*(float *)(this + 0x5c))) {
          iVar10 = *(int *)(this + 0x74c);
          if (iVar10 == 1) {
            if ((iVar11 != 0) && (*(uint *)(this + 0x610) < uVar4)) {
              local_70._0_4_ = -local_40;
              local_70._4_4_ = -local_3c;
              local_68 = -local_38;
              local_50 = local_68 * local_68 + local_70._4_4_ * local_70._4_4_ +
                         (float)local_70 * (float)local_70;
              if (_DAT_00d06a80 < local_50 !=
                  (NAN(_DAT_00d06a80) || NAN(local_50))) {
                fVar15 = (float10)__CIsqrt();
                local_50 = 1.0 / (float)fVar15;
                local_70._0_4_ = local_50 * (float)local_70;
                local_70._4_4_ = local_70._4_4_ * local_50;
                local_68 = local_50 * local_68;
              }
              piVar7 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                  *(ulong *)(*(int *)(this + 100) + 0x24));
              local_50 = *(float *)(*piVar7 + 0x104);
              local_70 = (double)CONCAT44(local_70._4_4_ * local_50,
                                          local_50 * (float)local_70);
              local_68 = local_50 * local_68;
              AddVehicleImpulse(this, (GmVec3 *)&local_70);
              *(uint *)(this + 0x610) = uVar4 + 100;
            }
          } else if (iVar10 == 2) {
            piVar7 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                *(ulong *)(*(int *)(this + 100) + 0x24));
            *(undefined4 *)((int)local_50 + 0x34) =
                *(undefined4 *)(*piVar7 + 0x108);
          } else if (iVar10 == 3) {
            *(undefined4 *)(this + 0x600) = 1;
            piVar7 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                *(ulong *)(*(int *)(this + 100) + 0x24));
            *(undefined4 *)(this + 0x5f4) = *(undefined4 *)(*piVar7 + 0xf0);
          }
        }
        iVar11 = *(int *)(this + 100);
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
        if (*(float *)(*piVar7 + 0x39c) < *(float *)(this + 0x670) !=
            (NAN(*(float *)(*piVar7 + 0x39c)) ||
             NAN(*(float *)(this + 0x670)))) {
          piVar7 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          uVar9 = *(uint *)(this + 0x654);
          if (*(float *)(*piVar7 + 0x398) < *(float *)(this + 0x670) ==
              (NAN(*(float *)(*piVar7 + 0x398)) ||
               NAN(*(float *)(this + 0x670)))) {
            if (uVar9 == 0) {
              uVar9 = 1;
            }
          } else if (uVar9 < 2) {
            uVar9 = 2;
          }
          *(uint *)(this + 0x654) = uVar9;
        }
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
        if (*(float *)(*piVar7 + 0x39c) < *(float *)(this + 0x674) !=
            (NAN(*(float *)(*piVar7 + 0x39c)) ||
             NAN(*(float *)(this + 0x674)))) {
          piVar7 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          uVar9 = *(uint *)(this + 0x658);
          if (*(float *)(*piVar7 + 0x398) < *(float *)(this + 0x674) ==
              (NAN(*(float *)(*piVar7 + 0x398)) ||
               NAN(*(float *)(this + 0x674)))) {
            if (uVar9 == 0) {
              uVar9 = 1;
            }
          } else if (uVar9 < 2) {
            uVar9 = 2;
          }
          *(uint *)(this + 0x658) = uVar9;
        }
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
        if (*(float *)(*piVar7 + 0x3a0) < *(float *)(this + 0x678) !=
            (NAN(*(float *)(*piVar7 + 0x3a0)) ||
             NAN(*(float *)(this + 0x678)))) {
          piVar7 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          uVar9 = *(uint *)(this + 0x1fc);
          if (*(float *)(*piVar7 + 0x28) < *(float *)(this + 0x678) ==
              (NAN(*(float *)(*piVar7 + 0x28)) ||
               NAN(*(float *)(this + 0x678)))) {
            if (uVar9 == 0) {
              uVar9 = 1;
            }
          } else if (uVar9 < 2) {
            uVar9 = 2;
          }
          *(uint *)(this + 0x1fc) = uVar9;
        }
        if (*(uint *)(this + 0x660) < *(uint *)(this + 0x658)) {
          *(uint *)(this + 0x660) = *(uint *)(this + 0x658);
          this[0x66c] = this[0x201];
        }
        if (*(uint *)(this + 0x664) < *(uint *)(this + 0x654)) {
          *(uint *)(this + 0x664) = *(uint *)(this + 0x654);
          this[0x66c] = this[0x201];
        }
        if (*(uint *)(this + 0x668) < *(uint *)(this + 0x1fc)) {
          *(uint *)(this + 0x668) = *(uint *)(this + 0x1fc);
          this[0x66d] = this[0x200];
        }
        *(uint *)(this + 0x650) = uVar4;
        iVar10 = IsGroundContactId(this, '\a', (GmVec3 *)&local_70, &local_78);
        if (iVar10 != 0) {
          piVar7 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          piVar8 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          local_50 = *(float *)(*piVar7 + 0xf0) * local_68;
          EnableTurbo(this, uVar4, *(ulong *)(*piVar8 + 0xf8), local_50, 1,
                      local_78);
        }
        iVar11 =
            IsGroundContactId(this, '\x1a', (GmVec3 *)&local_70, &local_78);
        if (iVar11 != 0) {
          iVar11 = *(int *)(this + 100);
          piVar7 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          piVar8 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          local_50 = *(float *)(*piVar7 + 0xf4) * local_68;
          EnableTurbo(this, uVar4, *(ulong *)(*piVar8 + 0xfc), local_50, 1,
                      local_78);
        }
        iVar11 =
            IsGroundContactId(this, '\x1e', (GmVec3 *)&local_70, &local_78);
        if (iVar11 != 0) {
          iVar11 = *(int *)(this + 100);
          piVar7 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          piVar8 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
          local_50 = *(float *)(*piVar7 + 0xf0) * local_68;
          EnableTurbo(this, uVar4, *(ulong *)(*piVar8 + 0xf8), local_50, 2,
                      local_78);
        }
        iVar11 =
            IsGroundContactId(this, '\x1d', (GmVec3 *)&local_70, &local_78);
        if (iVar11 != 0) {
          *(undefined4 *)(this + 0x60c) = 1;
        }
        UpdateTurbo(this, uVar4);
        (**(code **)(*(int *)this + 0x1a4))();
      } else {
        local_4c = 0.0;
        local_44 = 0.0;
        CHmsItem::SetLinearSpeed(*(CHmsItem **)(this + 0x28),
                                 (GmVec3 *)&local_4c);
      }
      pfVar1 = (float *)(this + 0x6d4);
      CHmsItem::GetForce(*(CHmsItem **)(this + 0x28), (GmVec3 *)pfVar1);
      piVar7 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      local_50 = 1.0 / *(float *)(*piVar7 + 0x228);
      *pfVar1 = local_50 * *pfVar1;
      *(float *)(this + 0x6d8) = local_50 * *(float *)(this + 0x6d8);
      *(float *)(this + 0x6dc) = local_50 * *(float *)(this + 0x6dc);
      iVar11 = *(int *)(this + 100);
      piVar7 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
      local_54 = *(float *)(*piVar7 + 900);
      piVar7 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar11 + 0x14), *(ulong *)(iVar11 + 0x24));
      fVar16 = CFuncKeysReal::GetValue(*(CFuncKeysReal **)(*piVar7 + 0x380),
                                       local_64, (ulong *)0x0);
      local_50 = *(float *)(this + 0x624) + param_1 * (fVar16 + local_54);
      *(float *)(this + 0x624) = local_50;
      local_5c = 0.0;
      if ((local_50 < 0.0 == (local_50 == 0.0)) &&
          (local_5c = local_50, 1.0 < local_50 != (local_50 == 1.0))) {
        local_5c = 1.0;
      }
      *(float *)(this + 0x624) = local_5c;
      GmSpring<float>::Integrate((GmSpring<float> *)(this + 0x228), param_1);
      fVar2 = local_1c + param_1 * local_28;
      fVar3 = -*(float *)(this + 0x244);
      fVar16 = *(float *)(this + 0x244);
      if ((fVar3 < fVar2) &&
          (fVar3 = fVar2, fVar16 < fVar2 != (fVar16 == fVar2))) {
        fVar3 = fVar16;
      }
      local_60 = (fVar3 / *(float *)(this + 0x244)) * *(float *)(this + 0x24c);
      fVar16 = *(float *)(this + 0x230);
      fVar3 = -*(float *)(this + 0x250);
      fVar2 = *(float *)(this + 0x250);
      if ((fVar3 < fVar16) &&
          (fVar3 = fVar16, fVar2 < fVar16 != (fVar2 == fVar16))) {
        fVar3 = fVar2;
      }
      *(float *)(this + 0x230) = fVar3;
      local_50 = *(float *)(this + 0x238) + local_60;
      local_54 = -*(float *)(this + 0x24c);
      local_58 = *(float *)(this + 0x24c);
      local_5c = local_54;
      if ((local_54 < local_50) &&
          (local_5c = local_50,
           local_58 < local_50 != (local_58 == local_50))) {
        local_5c = local_58;
      }
      *(float *)(this + 0x238) = local_5c;
      GmSpring<float>::Integrate((GmSpring<float> *)(this + 0x214), param_1);
      fVar2 = -local_20 * param_1 - local_14;
      fVar3 = -*(float *)(this + 0x244);
      fVar16 = *(float *)(this + 0x244);
      if ((fVar3 < fVar2) &&
          (fVar3 = fVar2, fVar16 < fVar2 != (fVar16 == fVar2))) {
        fVar3 = fVar16;
      }
      local_60 = (fVar3 / *(float *)(this + 0x244)) * *(float *)(this + 0x24c);
      fVar16 = *(float *)(this + 0x21c);
      fVar3 = -*(float *)(this + 0x250);
      fVar2 = *(float *)(this + 0x250);
      if ((fVar3 < fVar16) &&
          (fVar3 = fVar16, fVar2 < fVar16 != (fVar2 == fVar16))) {
        fVar3 = fVar2;
      }
      *(float *)(this + 0x21c) = fVar3;
      local_50 = *(float *)(this + 0x224) + local_60;
      local_54 = -*(float *)(this + 0x24c);
      local_58 = *(float *)(this + 0x24c);
      local_5c = local_54;
      if ((local_54 < local_50) &&
          (local_5c = local_50,
           local_58 < local_50 != (local_58 == local_50))) {
        local_5c = local_58;
      }
      *(float *)(this + 0x224) = local_5c;
      iVar11 = IsAllWheelGroundContactId(this, '\x06');
      if (iVar11 == 0) {
        local_60 = -1.0;
      } else {
        local_60 = 1.0;
      }
      local_50 = ABS(local_44 * 3.6);
      fVar16 = CFuncKeysReal::GetValue(
          *(CFuncKeysReal **)(*(int *)(this + 0x60) + 0x48), local_50,
          (ulong *)0x0);
      fVar16 = fVar16 * param_1 * local_60 + *(float *)(this + 0x23c);
      local_5c = 0.0;
      if ((fVar16 < 0.0 == (fVar16 == 0.0)) &&
          (local_5c = fVar16, 1.0 < fVar16 != (fVar16 == 1.0))) {
        local_5c = 1.0;
      }
      *(float *)(this + 0x23c) = local_5c;
      local_50 = ABS(local_44 * 3.6);
      fVar16 = CFuncKeysReal::GetValue(
          *(CFuncKeysReal **)(*(int *)(this + 0x60) + 0x44), local_50,
          (ulong *)0x0);
      local_50 = fVar16 * param_1 * local_60 + *(float *)(this + 0x240);
      local_5c = 0.0;
      if ((local_50 < 0.0 == (local_50 == 0.0)) &&
          (local_5c = local_50, 1.0 < local_50 != (local_50 == 1.0))) {
        local_5c = 1.0;
      }
      *(float *)(this + 0x240) = local_5c;
      uVar12 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
      uVar14 = 0;
      if (uVar12 != 0) {
        do {
          pSVar13 = CFastBuffer<>::operator[](
              (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar14);
          *(undefined4 *)(pSVar13 + 0x124) = 0;
          *(undefined4 *)(pSVar13 + 0x140) = 0;
          *(undefined4 *)(pSVar13 + 0x110) = 0;
          *(undefined4 *)(pSVar13 + 0x10c) = 0;
          uVar14 = uVar14 + 1;
          *(undefined4 *)(pSVar13 + 0x108) = 0;
          *(undefined4 *)(pSVar13 + 0x14c) = 0;
          *(undefined4 *)(pSVar13 + 0x148) = 0;
          *(undefined4 *)(pSVar13 + 0x144) = 0;
          *(undefined2 *)(pSVar13 + 0x128) = 0;
          *(undefined4 *)(pSVar13 + 0x15c) = 0;
        } while (uVar14 < uVar12);
      }
      *(undefined4 *)(this + 0x670) = 0;
      *(undefined4 *)(this + 0x5d8) = 0;
      *(undefined4 *)(this + 0x674) = 0;
      *(undefined4 *)(this + 0x5d4) = 0;
      *(undefined4 *)(this + 0x678) = 0;
      *(undefined4 *)(this + 0x5dc) = 0;
    }
    return;
  }
  local_1c = 0.0;
  local_18 = 0;
  local_14 = 0.0;
  CHmsItem::SetLinearSpeed(*(CHmsItem **)(this + 0x28), (GmVec3 *)&local_1c);
  local_1c = 0.0;
  local_18 = 0;
  local_14 = 0.0;
  CHmsItem::SetAngularSpeed(*(CHmsItem **)(this + 0x28), (GmVec3 *)&local_1c);
  local_1c = 0.0;
  local_18 = 0;
  local_14 = 0.0;
  CHmsItem::SetForce(*(CHmsItem **)(this + 0x28), (GmVec3 *)&local_1c);
  local_1c = 0.0;
  local_18 = 0;
  local_14 = 0.0;
  CHmsItem::SetTorque(*(CHmsItem **)(this + 0x28), (GmVec3 *)&local_1c);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* protected: void __thiscall CSceneVehicleCar::ComputeForcesModel3(float,class
   GmVec3 const
   &,float,float,class GmVec3 const &,class GmVec3 const &,float,int,struct
   CSceneVehicleMaterial::SBlendableVals *,int &,float &) */

void __thiscall CSceneVehicleCar::ComputeForcesModel3(
    CSceneVehicleCar *this, float param_1, GmVec3 *param_2, float param_3,
    float param_4, GmVec3 *param_5, GmVec3 *param_6, float param_7, int param_8,
    SBlendableVals *param_9, int *param_10, float *param_11)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  CSceneVehicleCarTuning *this_00;
  GmVec3 *pGVar5;
  ulong uVar6;
  SSimulationWheel *pSVar7;
  ulong *puVar8;
  int *piVar9;
  CSceneVehicleCarTuning **ppCVar10;
  int *piVar11;
  float10 *extraout_ECX;
  float10 *extraout_ECX_00;
  float10 *pfVar12;
  float10 *extraout_ECX_01;
  float10 *extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar13;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  ulong uVar14;
  float10 fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint local_68;
  float local_5c;
  float fStack_58;
  float local_54;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
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
  float local_8;

  pGVar5 = param_5;
  uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  local_68 = 0;
  if (uVar6 != 0) {
    do {
      pSVar7 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), local_68);
      WheelAddForceToVehicle(this, pSVar7, param_2);
      puVar8 = (ulong *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0x6c), (uint) * (ushort *)(pSVar7 + 0x128));
      piVar9 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 0x68) + 0x14), *puVar8);
      iVar3 = *piVar9;
      if (*(int *)(pSVar7 + 0x124) != 0) {
        iVar4 = *(int *)(this + 100);
        piVar9 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        if (((0.0 < *(float *)(*piVar9 + 0xa4) !=
              (*(float *)(*piVar9 + 0xa4) == 0.0)) &&
             (piVar9 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24)),
              *(int *)(*piVar9 + 0x354) != 0)) &&
            (piVar9 = (int *)CFastBuffer<>::operator[](
                 (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24)),
             *(int *)(*piVar9 + 0x354) == 1)) {
          if (*(int *)(pSVar7 + 300) == 0) {
            fVar17 = 1.0;
          } else {
            piVar9 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
            fVar17 = *(float *)(*piVar9 + 0xb0);
          }
          ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
          fVar16 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(
              *ppCVar10, *(float *)(param_5 + 8));
          fVar17 = *(float *)(iVar3 + 0x20) * param_3 * fVar16 * fVar17;
          local_5c =
              *(float *)(pSVar7 + 0x148) - *(float *)(pSVar7 + 0x14c) * 0.0;
          fStack_58 =
              *(float *)(pSVar7 + 0x14c) * 0.0 - *(float *)(pSVar7 + 0x144);
          fVar16 = *(float *)(pSVar7 + 0x144) * 0.0 -
                   *(float *)(pSVar7 + 0x148) * 0.0;
          fVar1 = fVar16 * fVar16 + local_5c * local_5c + fStack_58 * fStack_58;
          if (_DAT_00d0ac60 < fVar1 == (NAN(_DAT_00d0ac60) || NAN(fVar1))) {
            local_54 = 0.0;
            local_5c = 1.0;
            fStack_58 = 0.0;
            pfVar12 = extraout_ECX;
            uVar13 = extraout_EDX;
          } else {
            fVar15 = (float10)__CIsqrt();
            local_54 = 1.0 / (float)fVar15;
            local_5c = local_54 * local_5c;
            fStack_58 = local_54 * fStack_58;
            local_54 = local_54 * fVar16;
            pfVar12 = extraout_ECX_00;
            uVar13 = extraout_EDX_00;
          }
          if (*(int *)(pSVar7 + 4) != 0) {
            fVar15 = (float10)__CIcos(pfVar12, uVar13);
            local_28 = (float)fVar15;
            local_30 = local_28 * local_5c;
            local_2c = local_28 * fStack_58;
            local_28 = local_28 * local_54;
            fVar15 = (float10)__CIsin(extraout_ECX_01, extraout_EDX_01);
            local_34 = -(float)fVar15;
            local_3c = local_34 * 0.0;
            local_5c = local_30 + local_3c;
            fStack_58 = local_3c + local_2c;
            local_54 = local_34 + local_28;
            local_38 = local_3c;
          }
          local_24 = *(float *)param_5;
          iVar3 = *(int *)(this + 100);
          local_20 = *(float *)(param_5 + 4);
          local_1c = *(float *)(param_5 + 8);
          piVar9 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
          fVar16 = -*(float *)(*piVar9 + 0xa4) * 0.5 *
                   (local_1c * local_54 + local_20 * fStack_58 +
                    local_24 * local_5c);
          if (fVar17 < ABS(fVar16) == (NAN(fVar17) || NAN(ABS(fVar16)))) {
            *(undefined4 *)(pSVar7 + 300) = 0;
          } else {
            piVar9 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
            fVar1 = *(float *)(*piVar9 + 0xb4);
            if (fVar16 <= 0.0) {
              fVar17 = -fVar17;
            }
            *(undefined4 *)(pSVar7 + 300) = 1;
            fVar16 = (1.0 - fVar1) * fVar17 + fVar1 * fVar16;
          }
          if (*(int *)(pSVar7 + 300) != 0) {
            *param_10 = 1;
          }
          local_48 = local_5c * fVar16;
          local_44 = fStack_58 * fVar16;
          local_40 = fVar16 * local_54;
          AddVehicleCentralForce(this, (GmVec3 *)&local_48);
          iVar3 = *(int *)(this + 100);
          ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
          this_00 = *ppCVar10;
          ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
          fVar17 = CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle(
              *ppCVar10, ABS(fStack_58));
          fVar16 = CSceneVehicleCarTuning::GetRolloverLateralFromSpeed(
              this_00, *(float *)(param_5 + 8));
          local_8 = -(fVar16 * param_3 * fVar17);
          local_18 = local_40 * local_8 - local_44 * 0.0;
          local_14 = local_48 * 0.0 - local_40 * 0.0;
          local_10 = local_44 * 0.0 - local_8 * local_48;
          AddVehicleTorque(this, (GmVec3 *)&local_18);
        }
      }
      local_68 = local_68 + 1;
    } while (local_68 < uVar6);
  }
  if (param_8 == 0) {
    return;
  }
  piVar9 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  if (*(int *)(*piVar9 + 0x354) != 1) {
    return;
  }
  fVar15 = (float10)__CIsqrt();
  fVar17 = (float)fVar15;
  if (*(int *)(this + 0x60c) == 0) {
    if (*(float *)(this + 0x5cc) <= fVar17) {
      if (0.1 < *(float *)(this + 0x50))
        goto LAB_007facea;
    } else if (*(float *)(this + 0x54) <= 0.1) {
    LAB_007facea:
      *(undefined4 *)(this + 0x5c4) = 0;
    } else {
      *(undefined4 *)(this + 0x5c4) = 1;
    }
  }
  fVar16 = (float)CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  param_3 = 0.0;
  if (fVar16 != 0.0) {
    do {
      pSVar7 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8),
                                         (ulong)param_3);
      iVar3 = *(int *)(pSVar7 + 4);
      if (iVar3 == 0) {
        fVar1 = -*(float *)(this + 0x840);
      } else {
        fVar1 = *(float *)(this + 0x840);
      }
      fVar1 = fVar1 * 0.5;
      iVar4 = *(int *)(this + 100);
      local_48 = fVar1 * *(float *)(param_6 + 4) + *(float *)param_5;
      local_44 = *(float *)(param_5 + 4) + 0.0;
      local_40 = *(float *)(param_5 + 8) + 0.0;
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar4 + 0x14),
                                                *(ulong *)(iVar4 + 0x24));
      if (*(float *)(*piVar9 + 0x74) < fVar17 ==
          (NAN(*(float *)(*piVar9 + 0x74)) || NAN(fVar17))) {
        fVar15 = (float10)__CIsin(extraout_ECX_02, extraout_EDX_02);
        fVar20 = (float)fVar15;
      } else {
        fVar20 = 1.0;
      }
      ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
      fVar18 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(
          *ppCVar10, *(float *)(param_5 + 8));
      iVar4 = *(int *)(this + 100);
      fVar18 = fVar18 * *(float *)(param_9 + 0xc);
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar4 + 0x14),
                                                *(ulong *)(iVar4 + 0x24));
      fVar2 = -*(float *)(*piVar9 + 0xa4) * 0.5 *
              (local_40 * 0.0 + local_48 + local_44 * 0.0);
      fVar19 = ABS(fVar2);
      param_7 = fVar2;
      if (fVar18 < fVar19 != (NAN(fVar18) || NAN(fVar19))) {
        piVar9 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        piVar11 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        param_7 = *(float *)(*piVar11 + 0xe4) * fVar19 +
                  (1.0 - *(float *)(*piVar9 + 0xe4)) * fVar18;
        if (0.0 < fVar2 == NAN(fVar2)) {
          param_7 = -param_7;
        }
      }
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar4 + 0x14),
                                                *(ulong *)(iVar4 + 0x24));
      param_7 = *(float *)(*piVar9 + 0x98) * param_7;
      if (iVar3 != 0) {
        if (*(int *)(this + 0x5c4) == 0) {
          fVar18 = 1.0;
        } else {
          fVar18 = -1.0;
        }
        if (*(int *)(pSVar7 + 300) == 0) {
          fVar2 = 1.0;
        } else {
          piVar9 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
          fVar2 = *(float *)(*piVar9 + 0x9c);
        }
        ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        fVar19 = CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed(
            *ppCVar10, *(float *)(param_5 + 8));
        param_7 = param_7 -
                  fVar18 * fVar20 * *(float *)(this + 0x5e8) * fVar19 * fVar2;
      }
      local_24 = param_7;
      local_20 = param_7 * 0.0;
      local_18 = local_20 * 0.0 - fVar1 * local_20;
      local_14 = param_7 * fVar1 - local_20 * 0.0;
      local_10 = local_20 * 0.0 - param_7 * 0.0;
      local_1c = local_20;
      AddVehicleTorque(this, (GmVec3 *)&local_18);
      param_3 = (float)((int)param_3 + 1);
    } while ((uint)param_3 < (uint)fVar16);
  }
  ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  fVar16 = CSceneVehicleCarTuning::GetAccelFromSpeed(*ppCVar10,
                                                     *(float *)(param_5 + 8));
  ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  fVar17 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(
      *ppCVar10, *(float *)(param_5 + 8));
  iVar3 = *(int *)(this + 100);
  fVar17 = fVar17 * *(float *)(param_9 + 0xc);
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                            *(ulong *)(iVar3 + 0x24));
  param_7 = ABS(*(float *)(*piVar9 + 0xa4) * 0.5 * *(float *)param_5);
  if (fVar17 < param_7 != (NAN(fVar17) || NAN(param_7))) {
    param_7 = fVar17;
  }
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                            *(ulong *)(iVar3 + 0x24));
  fVar17 = *(float *)(this + 0x5e8);
  iVar4 = *piVar9;
  ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
  fVar20 = CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed(
      *ppCVar10, *(float *)(param_5 + 8));
  fVar1 = *(float *)(iVar4 + 0x7c) * param_7;
  if (*(int *)(this + 0x5c4) == 0) {
    param_7 = 0.0;
  } else {
    param_7 = -1.0;
  }
  if (*(int *)(this + 0x600) == 0) {
    param_3 = 0.0;
  } else {
    param_3 = *(float *)(this + 0x5f4);
  }
  param_5 =
      (GmVec3 *)((fVar16 - fVar1 * ABS(fVar17) * fVar20) *
                 (*(float *)(this + 0x50) * *(float *)(param_9 + 4) +
                  param_7 * *(float *)(param_9 + 4) * *(float *)(this + 0x54) +
                  param_3));
  if (*(int *)(this + 0x60c) != 0) {
    if (*(int *)(this + 0x600) == 0) {
      param_5 = (GmVec3 *)(fVar16 * 0.0);
    } else {
      param_5 = (GmVec3 *)(fVar16 * *(float *)(this + 0x5f4));
    }
  }
  param_7 = 0.0;
  if (0.0 < *(float *)(pGVar5 + 8) != NAN(*(float *)(pGVar5 + 8))) {
    iVar3 = *(int *)(this + 100);
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                               *(ulong *)(iVar3 + 0x24));
    param_7 = (*(float *)(*piVar9 + 0x44) * *(float *)(pGVar5 + 8) +
               *(float *)(*piVar11 + 0x40)) *
              *(float *)(this + 0x54);
    if (*param_10 == 0) {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                                *(ulong *)(iVar3 + 0x24));
      fVar17 = *(float *)(*piVar9 + 0x4c);
    } else {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                                *(ulong *)(iVar3 + 0x24));
      fVar17 = *(float *)(*piVar9 + 0x48);
    }
    fVar17 = *(float *)(param_9 + 8) * fVar17;
    if (fVar17 < param_7 != (NAN(fVar17) || NAN(param_7))) {
      uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
      uVar14 = 0;
      param_7 = fVar17;
      if (uVar6 != 0) {
        do {
          pSVar7 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8),
                                             uVar14);
          uVar14 = uVar14 + 1;
          *(undefined4 *)(pSVar7 + 300) = 1;
        } while (uVar14 < uVar6);
      }
    }
  }
  if (*(float *)(pGVar5 + 8) < 0.0) {
    if (*(int *)(this + 0x60c) == 0)
      goto LAB_007fb44c;
    iVar3 = *(int *)(this + 100);
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                               *(ulong *)(iVar3 + 0x24));
    param_7 = (*(float *)(*piVar9 + 0x40) -
               *(float *)(*piVar11 + 0x44) * *(float *)(pGVar5 + 8)) *
              *(float *)(this + 0x50);
    if (*param_10 == 0) {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                                *(ulong *)(iVar3 + 0x24));
      fVar17 = *(float *)(*piVar9 + 0x4c);
    } else {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                                *(ulong *)(iVar3 + 0x24));
      fVar17 = *(float *)(*piVar9 + 0x48);
    }
    fVar17 = *(float *)(param_9 + 8) * fVar17;
    if (fVar17 < param_7 != (NAN(fVar17) || NAN(param_7))) {
      uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
      uVar14 = 0;
      param_7 = fVar17;
      if (uVar6 != 0) {
        do {
          pSVar7 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8),
                                             uVar14);
          uVar14 = uVar14 + 1;
          *(undefined4 *)(pSVar7 + 300) = 1;
        } while (uVar14 < uVar6);
      }
    }
    param_7 = -param_7;
  }
  if ((*(int *)(this + 0x60c) != 0) &&
      (fVar17 = ABS(*(float *)(pGVar5 + 8)), fVar17 < 1.0 != NAN(fVar17))) {
    param_7 = fVar17 * param_7;
  }
LAB_007fb44c:
  *param_11 = param_7;
  iVar3 = *(int *)(this + 100);
  param_10 = (int *)((float)param_5 - param_7);
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                            *(ulong *)(iVar3 + 0x24));
  fVar17 = *(float *)(*piVar9 + 0x30);
  fVar16 = *(float *)param_9;
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                            *(ulong *)(iVar3 + 0x24));
  fVar1 = *(float *)(*piVar9 + 0x2c) * *(float *)param_9;
  if (fVar1 < *(float *)(pGVar5 + 8) !=
      (NAN(fVar1) || NAN(*(float *)(pGVar5 + 8)))) {
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    param_10 = (int *)-*(float *)(*piVar9 + 0x60);
  }
  if (*(float *)(pGVar5 + 8) < -(fVar17 * fVar16)) {
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    param_10 = *(int **)(*piVar9 + 0x60);
  }
  local_18 = 0.0;
  local_14 = 0.0;
  local_10 = (float)param_10 * param_4;
  AddVehicleCentralForce(this, (GmVec3 *)&local_18);
  local_28 = 0.0;
  local_2c = 0.0;
  local_30 = 0.0;
  piVar9 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  local_30 = -((float)param_10 * param_4) * *(float *)(*piVar9 + 0xc0);
  AddVehicleTorque(this, (GmVec3 *)&local_30);
  iVar3 = *(int *)(this + 100);
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                            *(ulong *)(iVar3 + 0x24));
  piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                             *(ulong *)(iVar3 + 0x24));
  local_34 = (-*(float *)(*piVar9 + 100) * *(float *)(param_2 + 8)) /
             *(float *)(*piVar11 + 0x160);
  local_3c = 0.0;
  local_38 = 0.0;
  AddVehicleCentralForce(this, (GmVec3 *)&local_3c);
  return;
}

/* protected: void __thiscall CSceneVehicleCar::ComputeForcesModel4(float,class
   GmVec3 const
   &,float,float,class GmVec3 const &,class GmVec3 const &,float,int,struct
   CSceneVehicleMaterial::SBlendableVals *,int &,float &) */

void __thiscall CSceneVehicleCar::ComputeForcesModel4(
    CSceneVehicleCar *this, float param_1, GmVec3 *param_2, float param_3,
    float param_4, GmVec3 *param_5, GmVec3 *param_6, float param_7, int param_8,
    SBlendableVals *param_9, int *param_10, float *param_11)

{
  int iVar1;
  CSceneVehicleCarTuning *this_00;
  bool bVar2;
  uint uVar3;
  ulong uVar4;
  SSimulationWheel *pSVar5;
  int *piVar6;
  int *piVar7;
  CSceneVehicleCarTuning **ppCVar8;
  float10 *extraout_ECX;
  float10 *extraout_ECX_00;
  float10 *extraout_ECX_01;
  float10 *pfVar9;
  float10 *extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar10;
  undefined4 extraout_EDX_02;
  ulong uVar11;
  float10 fVar12;
  float fVar13;
  GmVec3 *pGVar14;
  float fStack_84;
  float fStack_80;
  float local_7c;
  float fStack_78;
  float local_74;
  float local_70;
  float fStack_6c;
  int local_68;
  float fStack_64;
  uint local_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  int iStack_4;

  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar11 = 0;
  if (uVar4 != 0) {
    do {
      pGVar14 = param_2;
      pSVar5 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar11);
      WheelAddForceToVehicle(this, pSVar5, pGVar14);
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar4);
  }
  iVar1 = *(int *)(this + 0x640);
  local_60 = (uint)(iVar1 != 0);
  local_68 = 0;
  if (param_8 == 0)
    goto LAB_007fc108;
  local_70 = *(float *)(param_5 + 8) * *(float *)(param_5 + 8) +
             *(float *)param_5 * *(float *)param_5 +
             *(float *)(param_5 + 4) * *(float *)(param_5 + 4);
  fVar12 = (float10)__CIsqrt();
  local_7c = (float)fVar12;
  if (*(int *)(this + 0x60c) == 0) {
    if (*(float *)(this + 0x5cc) <= local_7c) {
      if (0.1 < *(float *)(this + 0x50))
        goto LAB_007fb6d4;
    } else if (*(float *)(this + 0x54) <= 0.1) {
    LAB_007fb6d4:
      *(undefined4 *)(this + 0x5c4) = 0;
    } else {
      *(undefined4 *)(this + 0x5c4) = 1;
    }
  }
  pfVar9 = extraout_ECX;
  uVar10 = extraout_EDX;
  local_70 = local_7c;
  if ((iVar1 == 1) && (local_70 = ABS(*(float *)(this + 0x5e8)),
                       local_70 < 1e-05 != NAN(local_70))) {
    fVar12 = (float10)__CIatan2(extraout_ECX);
    local_70 = (float)fVar12;
    *(undefined4 *)(this + 0x640) = 2;
    *(float *)(this + 0x638) = local_70;
    pfVar9 = extraout_ECX_00;
    uVar10 = extraout_EDX_00;
  }
  iVar1 = *(int *)(this + 0x640);
  local_74 = 0.0;
  fVar13 = 0.0;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      piVar6 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      pfVar9 = extraout_ECX_01;
      uVar10 = extraout_EDX_01;
      fVar13 = -*(float *)(this + 0x5e8) * *(float *)(*piVar6 + 0x1dc);
    } else {
      fVar13 = local_74;
      if (iVar1 == 2) {
        fVar13 = *(float *)(this + 0x638);
      }
    }
  }
  local_74 = fVar13;
  fVar12 = (float10)__CIsin(pfVar9, uVar10);
  local_70 = (float)fVar12;
  fStack_50 = local_70;
  fVar12 = (float10)__CIcos(extraout_ECX_02, extraout_EDX_02);
  uVar3 = local_60;
  local_70 = (float)fVar12;
  fStack_3c = 0.0;
  fStack_38 = -fStack_50;
  fStack_4c = 1.0;
  fStack_48 = 0.0;
  fStack_44 = 0.0;
  local_74 = *(float *)param_5 * fStack_50 + *(float *)(param_5 + 4) * 0.0 +
             *(float *)(param_5 + 8) * local_70;
  fStack_64 = *(float *)(param_5 + 8) * 0.0 + *(float *)param_5 +
              *(float *)(param_5 + 4) * 0.0;
  fStack_40 = local_70;
  GetLateralFriction(this, param_5, (GmVec3 *)&fStack_40, param_9, param_3,
                     local_60, &fStack_84, (int *)&fStack_80);
  GetLateralFriction(this, param_5, (GmVec3 *)&fStack_4c, param_9, param_3,
                     uVar3, &fStack_6c, &iStack_4);
  fStack_84 = fStack_84 * 0.5;
  fStack_28 = fStack_84 * fStack_40;
  fStack_24 = fStack_3c * fStack_84;
  fStack_20 = fStack_84 * fStack_38;
  fStack_78 = fStack_6c * 0.5;
  fStack_10 = fStack_78 * fStack_4c;
  fStack_c = fStack_48 * fStack_78;
  fStack_8 = fStack_78 * fStack_44;
  AddVehicleCentralForce(this, (GmVec3 *)&fStack_28);
  AddVehicleCentralForce(this, (GmVec3 *)&fStack_10);
  iVar1 = *(int *)(this + 100);
  piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                            *(ulong *)(iVar1 + 0x24));
  piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                            *(ulong *)(iVar1 + 0x24));
  fStack_58 = -*(float *)(param_6 + 4) * *(float *)(*piVar6 + 0x1a0) -
              ABS(*(float *)(param_6 + 4)) * *(float *)(param_6 + 4) *
                  *(float *)(*piVar7 + 0x1a4);
  fStack_84 = fStack_58 * 0.0;
  fStack_5c = fStack_84;
  fStack_54 = fStack_84;
  AddVehicleTorque(this, (GmVec3 *)&fStack_5c);
  if ((*(int *)(this + 0x640) == 2) &&
      (fStack_6c = ABS(*(float *)(this + 0x638)),
       1e-05 < fStack_6c != NAN(fStack_6c))) {
    iVar1 = *(int *)(this + 100);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    fStack_84 = ABS(*(float *)(*piVar6 + 0x1d0));
    if (1e-05 < fStack_84 == NAN(fStack_84))
      goto LAB_007fba9d;
    if (*(int *)(this + 0x5c4) == 0) {
      fStack_84 = 1.0;
    } else {
      fStack_84 = -1.0;
    }
    if (0.0 < *(float *)(this + 0x638) == NAN(*(float *)(this + 0x638))) {
      fStack_78 = -1.0;
    } else {
      fStack_78 = 1.0;
    }
    ppCVar8 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(iVar1 + 0x14), *(ulong *)(iVar1 + 0x24));
    fStack_80 = fStack_6c;
    this_00 = *ppCVar8;
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    iVar1 = *piVar6;
    fStack_6c = ABS(local_7c);
    fStack_6c =
        CSceneVehicleCarTuning::M4GetSteerRadiusFromSpeed(this_00, fStack_6c);
    fStack_6c = fStack_6c / (*(float *)(iVar1 + 0x1d0) * fStack_80);
    if (1e-05 < fStack_6c != NAN(fStack_6c)) {
      iVar1 = *(int *)(this + 100);
      piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      fStack_58 = (-(fStack_78 * fStack_84) * local_7c *
                   *(float *)(*piVar6 + 0x19c) * *(float *)(*piVar7 + 0x1a0)) /
                  fStack_6c;
    LAB_007fbbd1:
      fStack_80 = fStack_58 * 0.0;
      fStack_5c = fStack_80;
      fStack_54 = fStack_80;
      AddVehicleTorque(this, (GmVec3 *)&fStack_5c);
    }
  } else {
  LAB_007fba9d:
    fStack_80 = ABS(*(float *)(this + 0x5e8));
    if (1e-05 < fStack_80 != NAN(fStack_80)) {
      if (*(int *)(this + 0x5c4) == 0) {
        fStack_78 = 1.0;
      } else {
        fStack_78 = -1.0;
      }
      fVar13 = 1.0;
      if (0.0 < *(float *)(this + 0x5e8) == NAN(*(float *)(this + 0x5e8))) {
        fStack_84 = -1.0;
      } else {
        fStack_84 = 1.0;
      }
      fStack_78 = fStack_84 * fStack_78;
      if (local_60 != 0) {
        piVar6 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
            *(ulong *)(*(int *)(this + 100) + 0x24));
        fVar13 = *(float *)(*piVar6 + 0x1b8);
      }
      fStack_84 = fVar13;
      ppCVar8 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      fStack_80 = ABS(local_7c);
      fVar13 = CSceneVehicleCarTuning::M4GetSteerRadiusFromSpeed(*ppCVar8,
                                                                 fStack_80);
      fStack_84 = fVar13 * fStack_84;
      if (1e-05 < fStack_84 != NAN(fStack_84)) {
        iVar1 = *(int *)(this + 100);
        piVar6 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar1 + 0x14), *(ulong *)(iVar1 + 0x24));
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar1 + 0x14), *(ulong *)(iVar1 + 0x24));
        fStack_58 =
            (-fStack_78 * local_7c * *(float *)(*piVar6 + 0x19c) *
             *(float *)(*piVar7 + 0x1a0) * ABS(*(float *)(this + 0x5e8))) /
            fStack_84;
        goto LAB_007fbbd1;
      }
    }
  }
  ppCVar8 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  fStack_80 = CSceneVehicleCarTuning::GetAccelFromSpeed(*ppCVar8, local_74);
  if (*(int *)(this + 0x5c4) == 0) {
    fStack_84 = 0.0;
  } else {
    fStack_84 = -1.0;
  }
  if (*(int *)(this + 0x600) == 0) {
    fStack_78 = 0.0;
  } else {
    fStack_78 = *(float *)(this + 0x5f4);
  }
  fStack_78 = fStack_80 *
              (*(float *)(param_9 + 4) * *(float *)(this + 0x50) +
               *(float *)(param_9 + 4) * fStack_84 * *(float *)(this + 0x54) +
               fStack_78);
  if (*(int *)(this + 0x60c) != 0) {
    if (*(int *)(this + 0x600) == 0) {
      fStack_84 = 0.0;
      fStack_78 = fStack_80 * 0.0;
    } else {
      fStack_84 = *(float *)(this + 0x5f4);
      fStack_78 = fStack_80 * fStack_84;
    }
  }
  local_7c = 0.0;
  if (0.0 < local_74 != NAN(local_74)) {
    iVar1 = *(int *)(this + 100);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    local_7c =
        (*(float *)(*piVar6 + 0x44) * local_74 + *(float *)(*piVar7 + 0x40)) *
        *(float *)(this + 0x54);
    if (*param_10 == 0) {
      piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      fStack_84 = *(float *)(*piVar6 + 0x4c);
    } else {
      piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      fStack_84 = *(float *)(*piVar6 + 0x48);
    }
    fStack_80 = *(float *)(param_9 + 8) * fStack_84;
    if (fStack_80 < local_7c != (NAN(fStack_80) || NAN(local_7c))) {
      local_68 = 1;
      local_7c = fStack_80;
    }
  }
  if ((local_74 < 0.0) && (*(int *)(this + 0x60c) != 0)) {
    iVar1 = *(int *)(this + 100);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    local_7c =
        (*(float *)(*piVar6 + 0x40) - *(float *)(*piVar7 + 0x44) * local_74) *
        *(float *)(this + 0x50);
    if (*param_10 == 0) {
      piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      fStack_84 = *(float *)(*piVar6 + 0x4c);
    } else {
      piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      fStack_84 = *(float *)(*piVar6 + 0x48);
    }
    fStack_80 = *(float *)(param_9 + 8) * fStack_84;
    if (fStack_80 < local_7c != (NAN(fStack_80) || NAN(local_7c))) {
      local_68 = 1;
      local_7c = fStack_80;
    }
    local_7c = -local_7c;
  }
  if ((*(int *)(this + 0x60c) != 0) &&
      (fStack_80 = ABS(local_74), fStack_80 < 1.0 != NAN(fStack_80))) {
    local_7c = fStack_80 * local_7c;
  }
  if (local_68 == 0) {
    if (local_60 != 0)
      goto LAB_007fbe97;
  } else if (local_60 == 0) {
    *(undefined4 *)(this + 0x638) = 0;
    if (0.0 < *(float *)(this + 0x5e8) == NAN(*(float *)(this + 0x5e8))) {
      fStack_84 = -1.0;
    } else {
      fStack_84 = 1.0;
    }
    *(undefined4 *)(this + 0x640) = 1;
    *(float *)(this + 0x63c) = fStack_84;
  } else {
  LAB_007fbe97:
    iVar1 = *(int *)(this + 100);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    fStack_84 =
        *(float *)(*piVar6 + 0x1cc) * *(float *)(this + 0x5e8) * param_1 +
        *(float *)(this + 0x638);
    *(float *)(this + 0x638) = fStack_84;
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    fStack_80 = ABS(fStack_84);
    if (*(float *)(*piVar6 + 0x1d8) < fStack_80 !=
        (NAN(*(float *)(*piVar6 + 0x1d8)) || NAN(fStack_80))) {
      if (0.0 < fStack_84 == NAN(fStack_84)) {
        fStack_84 = -1.0;
      } else {
        fStack_84 = 1.0;
      }
      piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      *(float *)(this + 0x638) = *(float *)(*piVar6 + 0x1d8) * fStack_84;
    }
    bVar2 = false;
    if ((0.0 < *(float *)(this + 0x63c) == NAN(*(float *)(this + 0x63c))) ||
        (0.0 <= *(float *)(this + 0x638))) {
      if ((*(float *)(this + 0x63c) < 0.0) &&
          (0.0 < *(float *)(this + 0x638) != NAN(*(float *)(this + 0x638)))) {
        bVar2 = true;
      }
    } else {
      bVar2 = true;
    }
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    fStack_64 = ABS(fStack_64);
    if (((fStack_64 < *(float *)(*piVar6 + 0x1b0)) &&
         (fStack_64 = ABS(*(float *)(this + 0x5e8)),
          fStack_64 < 1e-05 != NAN(fStack_64))) ||
        (bVar2)) {
      local_68 = 0;
      *(undefined4 *)(this + 0x638) = 0;
      *(undefined4 *)(this + 0x640) = 0;
    } else {
      local_68 = 1;
    }
  }
  *param_11 = local_7c;
  iVar1 = *(int *)(this + 100);
  local_7c = fStack_78 - local_7c;
  piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                            *(ulong *)(iVar1 + 0x24));
  fStack_80 = *(float *)(*piVar6 + 0x30) * *(float *)param_9;
  piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                            *(ulong *)(iVar1 + 0x24));
  fStack_64 = *(float *)(*piVar6 + 0x2c) * *(float *)param_9;
  if (fStack_64 < local_74 != (NAN(fStack_64) || NAN(local_74))) {
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    local_7c = -*(float *)(*piVar6 + 0x60);
  }
  if (local_74 < -fStack_80) {
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    local_7c = *(float *)(*piVar6 + 0x60);
  }
  local_7c = local_7c * param_4;
  fStack_1c = local_7c * fStack_50;
  fStack_18 = local_7c * 0.0;
  fStack_14 = local_7c * local_70;
  AddVehicleCentralForce(this, (GmVec3 *)&fStack_1c);
  uStack_2c = 0;
  uStack_30 = 0;
  fStack_34 = 0.0;
  piVar6 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  fStack_34 = -local_7c * *(float *)(*piVar6 + 0xc0);
  AddVehicleTorque(this, (GmVec3 *)&fStack_34);
LAB_007fc108:
  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar11 = 0;
  if (uVar4 == 0) {
    *(int *)(this + 0x628) = local_68;
    return;
  }
  do {
    pSVar5 = CFastBuffer<>::operator[](
        (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar11);
    uVar11 = uVar11 + 1;
    *(int *)(pSVar5 + 300) = local_68;
  } while (uVar11 < uVar4);
  *(int *)(this + 0x628) = local_68;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* protected: void __thiscall CSceneVehicleCar::ComputeForcesModel5(float,class
   GmVec3 const
   &,float,float,class GmVec3 const &,class GmVec3 const &,float,int,struct
   CSceneVehicleMaterial::SBlendableVals *,int &,float &) */

void __thiscall CSceneVehicleCar::ComputeForcesModel5(
    CSceneVehicleCar *this, float param_1, GmVec3 *param_2, float param_3,
    float param_4, GmVec3 *param_5, GmVec3 *param_6, float param_7, int param_8,
    SBlendableVals *param_9, int *param_10, float *param_11)

{
  float fVar1;
  int iVar2;
  int iVar3;
  CSceneVehicleCarTuning *this_00;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  SSimulationWheel *pSVar7;
  ulong *puVar8;
  int *piVar9;
  CSceneVehicleCarTuning **ppCVar10;
  int *piVar11;
  float10 *extraout_ECX;
  float10 *extraout_ECX_00;
  float10 *pfVar12;
  float10 *extraout_ECX_01;
  float10 *extraout_ECX_02;
  CMwCmdBufferCore *this_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar13;
  undefined4 extraout_EDX_01;
  int iVar14;
  uint uVar15;
  ulong uVar16;
  float10 fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float local_90;
  float local_8c;
  float local_84;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  uint local_60;
  int local_5c;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_8;

  iVar5 = ApplyWaterForces(this, param_2);
  iVar2 = *(int *)(this + 0x628);
  *(int *)(this + 0x5e4) = iVar5;
  local_5c = 0;
  uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  local_60 = 0;
  if (uVar6 != 0) {
    do {
      pSVar7 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), local_60);
      WheelAddForceToVehicle(this, pSVar7, param_2);
      puVar8 = (ulong *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0x6c), (uint) * (ushort *)(pSVar7 + 0x128));
      piVar9 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 0x68) + 0x14), *puVar8);
      iVar14 = *piVar9;
      if (*(int *)(pSVar7 + 0x124) != 0) {
        iVar3 = *(int *)(this + 100);
        piVar9 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
        if (0.0 < *(float *)(*piVar9 + 0xa4) !=
            (*(float *)(*piVar9 + 0xa4) == 0.0)) {
          if (*(int *)(pSVar7 + 300) == 0) {
            fVar19 = 1.0;
          } else {
            piVar9 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
            fVar19 = *(float *)(*piVar9 + 0xb0);
          }
          ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
          fVar18 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(
              *ppCVar10, *(float *)(param_5 + 8));
          fVar19 = *(float *)(iVar14 + 0x20) * param_3 * fVar18 * fVar19;
          local_74 =
              *(float *)(pSVar7 + 0x148) - *(float *)(pSVar7 + 0x14c) * 0.0;
          local_70 =
              *(float *)(pSVar7 + 0x14c) * 0.0 - *(float *)(pSVar7 + 0x144);
          fVar18 = *(float *)(pSVar7 + 0x144) * 0.0 -
                   *(float *)(pSVar7 + 0x148) * 0.0;
          fVar22 = fVar18 * fVar18 + local_70 * local_70 + local_74 * local_74;
          if (_DAT_00d0ac60 < fVar22 == (NAN(_DAT_00d0ac60) || NAN(fVar22))) {
            local_74 = 1.0;
            local_6c = 0.0;
            local_70 = 0.0;
            pfVar12 = extraout_ECX;
            uVar13 = extraout_EDX;
          } else {
            fVar17 = (float10)__CIsqrt();
            local_6c = 1.0 / (float)fVar17;
            local_74 = local_6c * local_74;
            local_70 = local_6c * local_70;
            local_6c = local_6c * fVar18;
            pfVar12 = extraout_ECX_00;
            uVar13 = extraout_EDX_00;
          }
          if (*(int *)(pSVar7 + 4) != 0) {
            fVar17 = (float10)__CIcos(pfVar12, uVar13);
            local_30 = (float)fVar17;
            local_38 = local_30 * local_74;
            local_34 = local_30 * local_70;
            local_30 = local_30 * local_6c;
            fVar17 = (float10)__CIsin(extraout_ECX_01, extraout_EDX_01);
            local_10 = -(float)fVar17;
            local_18 = local_10 * 0.0;
            local_74 = local_38 + local_18;
            local_70 = local_18 + local_34;
            local_6c = local_10 + local_30;
            local_14 = local_18;
          }
          local_50 = *(float *)param_5;
          iVar14 = *(int *)(this + 100);
          local_4c = *(float *)(param_5 + 4);
          local_48 = *(float *)(param_5 + 8);
          piVar9 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar14 + 0x14), *(ulong *)(iVar14 + 0x24));
          local_8c =
              -*(float *)(*piVar9 + 0xa4) * 0.5 *
              (local_48 * local_6c + local_4c * local_70 + local_50 * local_74);
          if (fVar19 < ABS(local_8c) == (NAN(fVar19) || NAN(ABS(local_8c)))) {
            *(undefined4 *)(pSVar7 + 300) = 0;
          } else {
            piVar9 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar14 + 0x14), *(ulong *)(iVar14 + 0x24));
            fVar18 = *(float *)(*piVar9 + 0xb4);
            if (local_8c <= 0.0) {
              fVar19 = -fVar19;
            }
            *(undefined4 *)(pSVar7 + 300) = 1;
            local_8c = (1.0 - fVar18) * fVar19 + fVar18 * local_8c;
          }
          if (*(int *)(pSVar7 + 300) != 0) {
            *param_10 = 1;
          }
          local_28 = local_74 * local_8c;
          local_24 = local_70 * local_8c;
          local_20 = local_8c * local_6c;
          AddVehicleCentralForce(this, (GmVec3 *)&local_28);
          iVar14 = *(int *)(this + 100);
          ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar14 + 0x14), *(ulong *)(iVar14 + 0x24));
          this_00 = *ppCVar10;
          ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar14 + 0x14), *(ulong *)(iVar14 + 0x24));
          fVar19 = CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle(
              *ppCVar10, ABS(local_70));
          fVar18 = CSceneVehicleCarTuning::GetRolloverLateralFromSpeed(
              this_00, *(float *)(param_5 + 8));
          local_8 = -(fVar18 * param_3 * fVar19);
          local_44 = local_20 * local_8 - local_24 * 0.0;
          local_40 = local_28 * 0.0 - local_20 * 0.0;
          local_3c = local_24 * 0.0 - local_8 * local_28;
          AddVehicleTorque(this, (GmVec3 *)&local_44);
        }
      }
      local_60 = local_60 + 1;
    } while (local_60 < uVar6);
  }
  if (param_8 == 0) {
    *(undefined4 *)(this + 0x628) = 0;
    return;
  }
  fVar17 = (float10)__CIsqrt();
  local_2c = (float)fVar17;
  if (*(int *)(this + 0x60c) == 0) {
    if (*(float *)(this + 0x5cc) <= local_2c) {
      if (0.1 < *(float *)(this + 0x50))
        goto LAB_007fc67c;
    } else if (*(float *)(this + 0x54) <= 0.1) {
    LAB_007fc67c:
      *(undefined4 *)(this + 0x5c4) = 0;
    } else {
      *(undefined4 *)(this + 0x5c4) = 1;
    }
  }
  local_60 = 0;
  local_78 = 0.0;
  local_7c = 0.0;
  do {
    pSVar7 =
        CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), local_60);
    iVar14 = *(int *)(pSVar7 + 4);
    if (iVar14 == 0) {
      fVar19 = -*(float *)(this + 0x840);
    } else {
      fVar19 = *(float *)(this + 0x840);
    }
    fVar19 = fVar19 * 0.5;
    iVar3 = *(int *)(this + 100);
    fVar18 = *(float *)(param_6 + 4);
    fVar22 = *(float *)param_5;
    fVar21 = *(float *)(param_5 + 4);
    fVar23 = *(float *)(param_5 + 8);
    local_1c = iVar14;
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    fVar1 = *(float *)(*piVar9 + 0x74);
    if (fVar1 < local_2c == (NAN(fVar1) || NAN(local_2c))) {
      fVar17 = (float10)__CIsin(extraout_ECX_02, *piVar9);
      fVar1 = (float)fVar17;
    } else {
      fVar1 = 1.0;
    }
    ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
    fVar20 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(
        *ppCVar10, *(float *)(param_5 + 8));
    fVar20 = fVar20 * *(float *)(param_9 + 0xc);
    iVar3 = *(int *)(this + 100);
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    local_8c = -*(float *)(*piVar9 + 0xa4) * 0.5 *
               ((fVar23 + 0.0) * 0.0 + fVar19 * fVar18 + fVar22 +
                (fVar21 + 0.0) * 0.0);
    fVar18 = ABS(local_8c);
    if (fVar20 < fVar18 != (NAN(fVar20) || NAN(fVar18))) {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                                *(ulong *)(iVar3 + 0x24));
      piVar11 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
      local_7c = fVar20 + local_7c;
      local_78 = fVar18 + local_78;
      if ((int)local_8c < 0) {
        local_8c = -1.0;
      } else {
        local_8c = 1.0;
      }
      local_5c = 1;
      local_8c = local_8c * (fVar20 * (1.0 - *(float *)(*piVar9 + 0xe4)) +
                             fVar18 * *(float *)(*piVar11 + 0xe4));
      iVar14 = local_1c;
    }
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar3 + 0x14),
                                              *(ulong *)(iVar3 + 0x24));
    local_8c = *(float *)(*piVar9 + 0x98) * local_8c;
    if (iVar14 != 0) {
      if (*(int *)(this + 0x5c4) == 0) {
        fVar18 = 1.0;
      } else {
        fVar18 = -1.0;
      }
      if (*(int *)(pSVar7 + 300) == 0) {
        fVar22 = 1.0;
      } else {
        piVar9 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
        fVar22 = *(float *)(*piVar9 + 0x9c);
      }
      ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar3 + 0x14), *(ulong *)(iVar3 + 0x24));
      fVar21 = CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed(
          *ppCVar10, *(float *)(param_5 + 8));
      local_8c = local_8c -
                 fVar18 * fVar1 * *(float *)(this + 0x5e8) * fVar21 * fVar22;
    }
    local_50 = local_8c;
    local_4c = local_8c * 0.0;
    local_44 = local_4c * 0.0 - fVar19 * local_4c;
    local_40 = local_8c * fVar19 - local_4c * 0.0;
    local_3c = local_4c * 0.0 - local_8c * 0.0;
    local_48 = local_4c;
    AddVehicleTorque(this, (GmVec3 *)&local_44);
    local_60 = local_60 + 1;
  } while (local_60 < 4);
  this_01 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
  if (this_01 == (CMwCmdBufferCore *)0x0) {
    this_01 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
  }
  puVar8 = CMwTimerAdapter::GetTickTime((CMwTimerAdapter *)this_01);
  uVar4 = *puVar8;
  if (local_5c != 0) {
    *(uint *)(this + 0x62c) = uVar4;
    if (iVar2 == 0) {
      *(uint *)(this + 0x630) = uVar4;
    }
    *(uint *)(this + 0x634) = uVar4 - *(int *)(this + 0x630);
  }
  local_90 = 1.0;
  if ((uVar4 == *(uint *)(this + 0x62c)) &&
      (1e-05 < local_7c != NAN(local_7c))) {
    piVar9 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
        *(ulong *)(*(int *)(this + 100) + 0x24));
    fVar19 = ((local_78 - local_7c) / local_7c) / *(float *)(*piVar9 + 0x200);
    local_90 = 0.0;
    if ((fVar19 < 0.0 == (fVar19 == 0.0)) &&
        (local_90 = fVar19, 1.0 < fVar19 != (fVar19 == 1.0))) {
      local_90 = 1.0;
    }
    local_90 = 1.0 - local_90;
  }
  ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  fVar22 = CSceneVehicleCarTuning::M5GetSlippingAccelFromSpeed(
      *ppCVar10, *(float *)(param_5 + 8));
  ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  fVar21 = CSceneVehicleCarTuning::M5GetAccelFromSpeed(*ppCVar10,
                                                       *(float *)(param_5 + 8));
  fVar18 = 1.0 - local_90;
  fVar19 = fVar21 * local_90;
  if (1e-05 < ABS(*(float *)(this + 0x58))) {
    *(uint *)(this + 0x648) = uVar4;
    *(int *)(this + 0x64c) = local_5c;
  }
  uVar15 = *(uint *)(this + 0x648);
  local_7c = 0.0;
  if (uVar15 <= uVar4) {
    iVar2 = *(int *)(this + 100);
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    if (uVar4 - uVar15 < *(uint *)(*piVar9 + 0x1fc)) {
      if ((*(int *)(this + 0x64c) == 0) ||
          (piVar9 = (int *)CFastBuffer<>::operator[](
               (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24)),
           *(int *)(*piVar9 + 0x80) == 0)) {
        local_7c = 1.0;
      } else {
        local_7c = 0.0;
      }
    }
  }
  iVar2 = *(int *)(this + 100);
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  uVar15 = *(uint *)(this + 0x634);
  if (*(uint *)(*piVar9 + 0x84) < *(uint *)(this + 0x634)) {
    uVar15 = *(uint *)(*piVar9 + 0x84);
  }
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  if (((*(int *)(*piVar9 + 0x80) != 0) && (*(uint *)(this + 0x62c) <= uVar4)) &&
      (uVar4 - *(uint *)(this + 0x62c) <= uVar15)) {
    local_7c = 0.0;
  }
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  iVar14 = *piVar9;
  ppCVar10 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
  fVar23 = CSceneVehicleCarTuning::M5GetSteerSlowDownFromSpeed(
      *ppCVar10, *(float *)(param_5 + 8));
  if (*(int *)(this + 0x5c4) == 0) {
    local_90 = 0.0;
  } else {
    local_90 = -1.0;
  }
  if (*(int *)(this + 0x600) == 0) {
    local_84 = 0.0;
  } else {
    local_84 = *(float *)(this + 0x5f4);
  }
  local_84 = ((*(float *)(param_9 + 4) * *(float *)(this + 0x50) +
               *(float *)(param_9 + 4) * local_90 * *(float *)(this + 0x54)) *
                  (fVar18 * fVar22 + fVar19) +
              fVar21 * local_84) -
             *(float *)(iVar14 + 0x7c) * local_7c * fVar23;
  if (*(int *)(this + 0x60c) != 0) {
    if (*(int *)(this + 0x600) == 0) {
      local_84 = fVar21 * 0.0;
    } else {
      local_84 = fVar21 * *(float *)(this + 0x5f4);
    }
  }
  local_8c = 0.0;
  if (0.0 < *(float *)(param_5 + 8) != NAN(*(float *)(param_5 + 8))) {
    iVar2 = *(int *)(this + 100);
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                               *(ulong *)(iVar2 + 0x24));
    local_8c = (*(float *)(*piVar9 + 0x44) * *(float *)(param_5 + 8) +
                *(float *)(*piVar11 + 0x40)) *
               *(float *)(this + 0x54);
    if (*param_10 == 0) {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                                *(ulong *)(iVar2 + 0x24));
      fVar19 = *(float *)(*piVar9 + 0x4c);
    } else {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                                *(ulong *)(iVar2 + 0x24));
      fVar19 = *(float *)(*piVar9 + 0x48);
    }
    fVar19 = *(float *)(param_9 + 8) * fVar19;
    if (fVar19 < local_8c != (NAN(fVar19) || NAN(local_8c))) {
      uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
      uVar16 = 0;
      local_8c = fVar19;
      if (uVar6 != 0) {
        local_5c = 1;
        do {
          pSVar7 = CFastBuffer<>::operator[](
              (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar16);
          uVar16 = uVar16 + 1;
          *(undefined4 *)(pSVar7 + 300) = 1;
        } while (uVar16 < uVar6);
      }
    }
  }
  if (*(float *)(param_5 + 8) < 0.0) {
    if (*(int *)(this + 0x60c) == 0)
      goto LAB_007fce6d;
    iVar2 = *(int *)(this + 100);
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                               *(ulong *)(iVar2 + 0x24));
    local_8c = (*(float *)(*piVar9 + 0x40) -
                *(float *)(*piVar11 + 0x44) * *(float *)(param_5 + 8)) *
               *(float *)(this + 0x50);
    if (*param_10 == 0) {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                                *(ulong *)(iVar2 + 0x24));
      fVar19 = *(float *)(*piVar9 + 0x4c);
    } else {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                                *(ulong *)(iVar2 + 0x24));
      fVar19 = *(float *)(*piVar9 + 0x48);
    }
    fVar19 = *(float *)(param_9 + 8) * fVar19;
    if (fVar19 < local_8c != (NAN(fVar19) || NAN(local_8c))) {
      uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
      local_8c = fVar19;
      if (uVar6 != 0) {
        local_5c = 1;
        uVar16 = 0;
        do {
          pSVar7 = CFastBuffer<>::operator[](
              (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar16);
          uVar16 = uVar16 + 1;
          *(undefined4 *)(pSVar7 + 300) = 1;
        } while (uVar16 < uVar6);
      }
    }
    local_8c = -local_8c;
  }
  if ((*(int *)(this + 0x60c) != 0) &&
      (fVar19 = ABS(*(float *)(param_5 + 8)), fVar19 < 1.0 != NAN(fVar19))) {
    local_8c = fVar19 * local_8c;
  }
LAB_007fce6d:
  *param_11 = local_8c;
  iVar2 = *(int *)(this + 100);
  local_8c = local_84 - local_8c;
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  fVar19 = *(float *)(*piVar9 + 0x30);
  fVar18 = *(float *)param_9;
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  fVar22 = *(float *)(*piVar9 + 0x2c) * *(float *)param_9;
  if (fVar22 < *(float *)(param_5 + 8) !=
      (NAN(fVar22) || NAN(*(float *)(param_5 + 8)))) {
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    local_8c = -*(float *)(*piVar9 + 0x60);
  }
  if (*(float *)(param_5 + 8) < -(fVar19 * fVar18)) {
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    local_8c = *(float *)(*piVar9 + 0x60);
  }
  local_90 = local_8c * param_4;
  local_44 = 0.0;
  local_40 = 0.0;
  local_3c = local_90;
  AddVehicleCentralForce(this, (GmVec3 *)&local_44);
  if (iVar5 == 0) {
    iVar2 = *(int *)(this + 100);
    local_48 = 0.0;
    local_4c = 0.0;
    local_50 = 0.0;
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    if (*(float *)(*piVar9 + 500) < ABS(local_90) !=
        (NAN(*(float *)(*piVar9 + 500)) || NAN(ABS(local_90)))) {
      if ((int)local_90 < 0) {
        local_90 = -1.0;
      } else {
        local_90 = 1.0;
      }
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                                *(ulong *)(iVar2 + 0x24));
      local_90 = *(float *)(*piVar9 + 500) * local_90;
    }
    piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    local_50 = -local_90 * *(float *)(*piVar9 + 0xc0);
    AddVehicleTorque(this, (GmVec3 *)&local_50);
  }
  iVar2 = *(int *)(this + 100);
  piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                             *(ulong *)(iVar2 + 0x24));
  local_30 = (-*(float *)(*piVar9 + 100) * *(float *)(param_2 + 8)) /
             *(float *)(*piVar11 + 0x160);
  local_38 = 0.0;
  local_34 = 0.0;
  AddVehicleCentralForce(this, (GmVec3 *)&local_38);
  *(int *)(this + 0x628) = local_5c;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* protected: void __thiscall CSceneVehicleCar::ComputeForcesModel6(float,class
   GmVec3 const
   &,float,float,class GmVec3 const &,class GmVec3 const &,float,int,struct
   CSceneVehicleMaterial::SBlendableVals *,int &,float &) */

void __thiscall CSceneVehicleCar::ComputeForcesModel6(
    CSceneVehicleCar *this, float param_1, GmVec3 *param_2, float param_3,
    float param_4, GmVec3 *param_5, GmVec3 *param_6, float param_7, int param_8,
    SBlendableVals *param_9, int *param_10, float *param_11)

{
  CFastBuffer<> *this_00;
  float *this_01;
  float fVar1;
  int iVar2;
  CSceneVehicleCarTuning *this_02;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  float *pfVar8;
  int **ppiVar9;
  undefined4 *puVar10;
  ulong uVar11;
  SSimulationWheel *pSVar12;
  int *piVar13;
  GmVector2<> *pGVar14;
  CSceneVehicleCarTuning **ppCVar15;
  CMwCmdBufferCore *pCVar16;
  ulong *puVar17;
  float10 *pfVar18;
  int *piVar19;
  uint uVar20;
  int iVar21;
  float10 *extraout_ECX;
  float10 *extraout_ECX_00;
  float10 *extraout_ECX_01;
  float10 *extraout_ECX_02;
  int extraout_EDX;
  int iVar22;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  ulong uVar23;
  undefined4 *puVar24;
  float10 fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fStack_128;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float *pfStack_e0;
  float fStack_dc;
  undefined8 uStack_d8;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  int *piStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  undefined8 uStack_98;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined4 uStack_68;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  undefined4 uStack_44;
  float fStack_40;
  GmVec3 aGStack_3c[4];
  float fStack_38;
  GmIso4 aGStack_30[48];

  ppiVar9 = (int **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
  puVar10 = (undefined4 *)(**(code **)(**ppiVar9 + 0x78))();
  puVar24 = (undefined4 *)(this + 0x6a4);
  for (iVar21 = 0xc; iVar21 != 0; iVar21 = iVar21 + -1) {
    *puVar24 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar24 = puVar24 + 1;
  }
  fStack_38 = *(float *)(this + 0x6b4);
  iVar21 = ApplyWaterForces(this, param_2);
  this_00 = (CFastBuffer<> *)(this + 0x2e8);
  *(int *)(this + 0x5e4) = iVar21;
  bVar7 = true;
  uVar11 = CFastBuffer<>::GetCount(this_00);
  uVar23 = 0;
  if (uVar11 != 0) {
    do {
      pSVar12 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar23);
      if ((*(int *)(pSVar12 + 0x124) == 0) ||
          (*(short *)(pSVar12 + 0x128) != 6)) {
        bVar7 = false;
      }
      uVar23 = uVar23 + 1;
    } while (uVar23 < uVar11);
  }
  iVar2 = *(int *)(this + 0x628);
  pfStack_e0 = (float *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x50);
  fStack_f4 = 0.0;
  if (*(int *)(this + 0x69c) != 2) {
    pCVar16 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
    if (pCVar16 == (CMwCmdBufferCore *)0x0) {
      pCVar16 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
    }
    puVar17 = CMwTimerAdapter::GetTickTime((CMwTimerAdapter *)pCVar16);
    uVar3 = *puVar17;
    if (*(int *)(this + 0x69c) == 1) {
      uVar20 = *(uint *)(this + 0x6f4);
      if ((uVar3 < uVar20) ||
          (piVar13 = (int *)CFastBuffer<>::operator[](
               (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
               *(ulong *)(*(int *)(this + 100) + 0x24)),
           *(uint *)(*piVar13 + 0x298) <= uVar3 - uVar20)) {
        *(uint *)(this + 0x6f8) = uVar3;
        *(undefined4 *)(this + 0x69c) = 3;
      } else {
        fStack_f4 = 1.401298e-45;
      }
    }
    if (*(int *)(this + 0x69c) == 3) {
      uVar20 = *(uint *)(this + 0x6f8);
      if ((uVar3 < uVar20) ||
          (piVar13 = (int *)CFastBuffer<>::operator[](
               (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
               *(ulong *)(*(int *)(this + 100) + 0x24)),
           *(uint *)(*piVar13 + 0x2a8) <= uVar3 - uVar20)) {
        *(undefined4 *)(this + 0x69c) = 0;
        *(undefined4 *)(this + 0x6a0) = 0;
      } else {
        uVar11 = CFastBuffer<>::GetCount(this_00);
        uVar23 = 0;
        if (uVar11 != 0) {
          do {
            pSVar12 =
                CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar23);
            uVar23 = uVar23 + 1;
            *(undefined4 *)(pSVar12 + 300) = 1;
          } while (uVar23 < uVar11);
        }
      }
    }
    fVar26 = (float)CFastBuffer<>::GetCount(this_00);
    fStack_f0 = 0.0;
    if (fVar26 != 0.0) {
      do {
        pSVar12 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8),
                                            (ulong)fStack_f0);
        WheelAddForceToVehicle(this, pSVar12, param_2);
        puVar17 = (ulong *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x6c),
            (uint) * (ushort *)(pSVar12 + 0x128));
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*(int *)(this + 0x68) + 0x14), *puVar17);
        iVar4 = *piVar13;
        if (*(int *)(pSVar12 + 0x124) != 0) {
          iVar5 = *(int *)(this + 100);
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
          fVar29 = 0.0;
          iVar22 = *piVar13;
          if (0.0 < *(float *)(iVar22 + 0xa4) !=
              (*(float *)(iVar22 + 0xa4) == 0.0)) {
            fStack_78 = *(float *)(pSVar12 + 0x108) - *pfStack_e0;
            fStack_74 = *(float *)(pSVar12 + 0x10c) - pfStack_e0[1];
            fStack_70 = *(float *)(pSVar12 + 0x110) - pfStack_e0[2];
            fStack_100 =
                *(float *)(pSVar12 + 0x148) - *(float *)(pSVar12 + 0x14c) * 0.0;
            fStack_fc =
                *(float *)(pSVar12 + 0x14c) * 0.0 - *(float *)(pSVar12 + 0x144);
            fStack_f8 = *(float *)(pSVar12 + 0x144) * 0.0 -
                        *(float *)(pSVar12 + 0x148) * 0.0;
            fVar27 = fStack_f8 * fStack_f8 + fStack_fc * fStack_fc +
                     fStack_100 * fStack_100;
            if (_DAT_00d06a80 < fVar27 == (NAN(_DAT_00d06a80) || NAN(fVar27))) {
              fStack_100 = 1.0;
              fStack_fc = 0.0;
              pfVar18 = extraout_ECX;
            } else {
              fVar25 = (float10)__CIsqrt();
              fVar29 = 1.0 / (float)fVar25;
              fStack_100 = fVar29 * fStack_100;
              fStack_fc = fVar29 * fStack_fc;
              fVar29 = fVar29 * fStack_f8;
              pfVar18 = extraout_ECX_00;
              iVar22 = extraout_EDX;
            }
            fStack_f8 = fVar29;
            if (*(int *)(pSVar12 + 4) != 0) {
              fVar25 = (float10)__CIcos(pfVar18, iVar22);
              fStack_a8 = (float)fVar25;
              fStack_b0 = fStack_a8 * fStack_100;
              fStack_ac = fStack_a8 * fStack_fc;
              fStack_a8 = fStack_a8 * fStack_f8;
              fVar25 = (float10)__CIsin(extraout_ECX_01, extraout_EDX_00);
              fStack_88 = -(float)fVar25;
              fStack_90 = fStack_88 * 0.0;
              fStack_100 = fStack_b0 + fStack_90;
              fStack_fc = fStack_90 + fStack_ac;
              fStack_f8 = fStack_88 + fStack_a8;
              fStack_8c = fStack_90;
            }
            fStack_ec = *(float *)param_5;
            fStack_e8 = *(float *)(param_5 + 4);
            fStack_e4 = *(float *)(param_5 + 8);
            fVar29 = fStack_ec * fStack_100;
            fVar28 = fStack_e8 * fStack_fc;
            fVar27 = fStack_e4 * fStack_f8;
            piVar13 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
            fStack_7c = -*(float *)(*piVar13 + 0x228);
            fStack_84 = fStack_7c * *(float *)(this + 0x6d4);
            fStack_80 = *(float *)(this + 0x6d8) * fStack_7c;
            fStack_7c = fStack_7c * *(float *)(this + 0x6dc);
            uStack_98 = (double)fStack_84;
            uStack_d8 = (double)fStack_80;
            piStack_b4 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
            fVar25 = (float10)__CIsqrt();
            if ((float)fVar25 < *(float *)(*piStack_b4 + 0x234)) {
              fStack_7c = 0.0;
              fStack_80 = 0.0;
              fStack_84 = 0.0;
            }
            fStack_c0 = (fStack_74 * fStack_7c - fStack_70 * fStack_80) * -1.0;
            fStack_bc = (fStack_84 * fStack_70 - fStack_78 * fStack_7c) * -1.0;
            fStack_b8 = (fStack_80 * fStack_78 - fStack_74 * fStack_84) * -1.0;
            piVar13 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
            fVar30 = *(float *)(*piVar13 + 0x23c) * fStack_b8;
            piVar13 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
            fStack_c0 = *(float *)(*piVar13 + 0x238) * fStack_c0;
            fStack_bc = 0.0;
            fStack_b8 = fVar30;
            AddVehicleTorque(this, (GmVec3 *)&fStack_c0);
            if (*(int *)(this + 0x69c) == 1) {
              ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                  *(ulong *)(*(int *)(this + 100) + 0x24));
              fStack_60 = CSceneVehicleCarTuning::M6GetBurnoutRolloverFromSpeed(
                  *ppCVar15, *(float *)(param_5 + 8));
              uStack_5c = 0;
              fStack_58 = 0.0;
              AddVehicleTorque(this, (GmVec3 *)&fStack_60);
            }
            fStack_128 = 1.0;
            if (*(int *)(this + 0x69c) == 1) {
              iVar5 = *(int *)(this + 100);
              pfVar18 = (float10 *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
              piVar13 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
              uStack_d8 = (double)CONCAT44(
                  uStack_d8._4_4_, *(int *)(*(int *)pfVar18 + 0x298) * 2);
              fVar25 = (float10)__CIcos(pfVar18, *(int *)pfVar18);
              fStack_128 =
                  (*(float *)(*piVar13 + 0x2a0) - 1.0) * (float)fVar25 + 1.0;
            }
            ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                *(ulong *)(*(int *)(this + 100) + 0x24));
            fVar30 = CSceneVehicleCarTuning::M6GetModulationFromDamperAbsorbVal(
                *ppCVar15, *(float *)(pSVar12 + 0xb4));
            if (*(int *)(pSVar12 + 300) == 0) {
              fVar1 = 1.0;
            LAB_007c4ee4:
              fStack_dc = 1.0;
            } else {
              piVar13 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                  *(ulong *)(*(int *)(this + 100) + 0x24));
              fVar1 = *(float *)(*piVar13 + 0xb0);
              if (*(float *)(this + 0x54) <= 0.1)
                goto LAB_007c4ee4;
              piVar13 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                  *(ulong *)(*(int *)(this + 100) + 0x24));
              fStack_dc = *(float *)(*piVar13 + 0x244);
            }
            ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                *(ulong *)(*(int *)(this + 100) + 0x24));
            fVar31 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(
                *ppCVar15, *(float *)(param_5 + 8));
            iVar5 = *(int *)(this + 100);
            fVar30 = *(float *)(iVar4 + 0x20) * param_3 * fVar31 * fVar1 *
                     fStack_dc * fVar30;
            piVar13 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
            fStack_128 = -*(float *)(*piVar13 + 0xa4) * 0.5 *
                         (fVar27 + fVar28 + fVar29) * fStack_128;
            if (fVar30 < ABS(fStack_128) ==
                (NAN(fVar30) || NAN(ABS(fStack_128)))) {
              *(undefined4 *)(pSVar12 + 300) = 0;
            } else {
              piVar13 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
              fVar29 = *(float *)(*piVar13 + 0xb4);
              if (fStack_128 <= 0.0) {
                fVar30 = -fVar30;
              }
              *(undefined4 *)(pSVar12 + 300) = 1;
              fStack_128 = (1.0 - fVar29) * fVar30 + fVar29 * fStack_128;
            }
            if (*(int *)(pSVar12 + 300) != 0) {
              *param_10 = 1;
            }
            fStack_a4 = fStack_128 * fStack_100;
            fStack_a0 = fStack_128 * fStack_fc;
            fStack_9c = fStack_f8 * fStack_128;
            if ((bVar7) && (6.0 < *(float *)(param_5 + 8) !=
                            NAN(*(float *)(param_5 + 8)))) {
              fStack_40 = 0.0;
              uStack_44 = 0;
              fStack_48 = 0.0;
              fStack_64 = 0.0;
              uStack_68 = 0;
              fStack_6c = 0.0;
              fStack_cc = *(float *)param_5;
              fStack_c8 = *(float *)(param_5 + 4);
              fStack_c4 = *(float *)(param_5 + 8);
              fVar29 = fStack_c4 * fStack_c4 + fStack_cc * fStack_cc +
                       fStack_c8 * fStack_c8;
              if (_DAT_00d06a80 < fVar29 !=
                  (NAN(_DAT_00d06a80) || NAN(fVar29))) {
                fVar25 = (float10)__CIsqrt();
                fStack_cc = (1.0 / (float)fVar25) * fStack_cc;
              }
              if (0.1 < *(float *)(this + 0x54) !=
                  NAN(*(float *)(this + 0x54))) {
                fStack_54 = *(float *)param_5 * -0.1;
                fStack_50 = *(float *)(param_5 + 4) * -0.1;
                fStack_4c = *(float *)(param_5 + 8) * -0.1;
                AddVehicleCentralForce(this, (GmVec3 *)&fStack_54);
              }
              if (((*(int *)(this + 0x60c) == 0) &&
                   (0.1 < *(float *)(this + 0x50))) &&
                  (*(float *)(this + 0x54) < 0.1 !=
                   (*(float *)(this + 0x54) == 0.1))) {
                iVar4 = *(int *)(this + 100);
                piVar13 = (int *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
                fVar30 = ABS(fStack_cc);
                uStack_d8 = (double)(fVar30 * 20.0 + 1.0);
                piVar19 = (int *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
                fVar1 = (ABS(*(float *)(param_5 + 8)) + 1.0) *
                        (ABS(*(float *)(param_5 + 8)) + 1.0);
                uStack_98 = (double)fVar1;
                fVar29 = *(float *)(*piVar13 + 0x348);
                fVar27 = *(float *)(this + 0x50);
                fVar31 = (float)uStack_d8;
                fVar28 = *(float *)(*piVar19 + 0x344);
                piVar13 = (int *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
                piVar19 = (int *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
                fStack_48 =
                    (*(float *)(*piVar13 + 0x33c) * fStack_cc) /
                    (*(float *)(*piVar19 + 0x340) * *(float *)(this + 0x50) +
                     1.0);
                uStack_44 = 0;
                fStack_40 =
                    (fVar29 * fVar27 * 1.5 * fVar30 * fVar31 * fVar28) / fVar1;
                piVar13 = (int *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
                piVar19 = (int *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
                fVar29 = *(float *)(*piVar13 + 0x348);
                fVar27 = *(float *)(this + 0x50);
                fVar31 = (float)uStack_d8;
                fVar28 = *(float *)(*piVar19 + 0x344);
                fVar1 = (float)uStack_98;
                piVar13 = (int *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
                piVar19 = (int *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
                fStack_6c =
                    (fStack_cc * -1.0 * *(float *)(*piVar13 + 0x33c)) /
                    (*(float *)(*piVar19 + 0x340) * *(float *)(this + 0x50) +
                     1.0);
                uStack_68 = 0;
                fStack_64 =
                    (fVar29 * fVar27 * fVar30 * fVar31 * fVar28) / fVar1;
              }
              uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
              uVar23 = 0;
              if (uVar11 != 0) {
                do {
                  pSVar12 = CFastBuffer<>::operator[](
                      (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar23);
                  if (((uVar23 == 0) || (uVar23 == 1)) &&
                      ((*(float *)(this + 0x54) < 0.1 !=
                            (*(float *)(this + 0x54) == 0.1) &&
                        (*(int *)(pSVar12 + 300) != 0)))) {
                    AddVehicleForce(this, (GmVec3 *)&fStack_48,
                                    (GmVec3 *)(pSVar12 + 0xa8));
                  }
                  if (((uVar23 == 2) || (uVar23 == 3)) &&
                      ((*(float *)(this + 0x54) < 0.1 !=
                            (*(float *)(this + 0x54) == 0.1) &&
                        (*(int *)(pSVar12 + 300) != 0)))) {
                    AddVehicleForce(this, (GmVec3 *)&fStack_6c,
                                    (GmVec3 *)(pSVar12 + 0xa8));
                  }
                  uVar23 = uVar23 + 1;
                } while (uVar23 < uVar11);
                AddVehicleCentralForce(this, (GmVec3 *)&fStack_a4);
                goto LAB_007c53a5;
              }
            }
            AddVehicleCentralForce(this, (GmVec3 *)&fStack_a4);
          }
        }
      LAB_007c53a5:
        fStack_f0 = (float)((int)fStack_f0 + 1);
      } while ((uint)fStack_f0 < (uint)fVar26);
    }
    if (param_8 == 0) {
      if (*(int *)(this + 0x69c) == 1) {
        *(uint *)(this + 0x6f8) = uVar3;
        *(undefined4 *)(this + 0x69c) = 3;
      }
    } else {
      fVar25 = (float10)__CIsqrt();
      piStack_b4 = (int *)(float)fVar25;
      if ((((*(int *)(this + 0x60c) == 0) &&
            (0.1 < *(float *)(this + 0x54) != NAN(*(float *)(this + 0x54)))) &&
           (*(float *)(this + 0x50) < 0.1 != NAN(*(float *)(this + 0x50)))) &&
          (*(int *)(this + 0x69c) == 1)) {
        *(uint *)(this + 0x6f8) = uVar3;
        *(undefined4 *)(this + 0x69c) = 3;
      }
      if (*(int *)(this + 0x60c) == 0) {
        if (((0.1 < *(float *)(this + 0x50)) &&
             (0.1 < *(float *)(this + 0x54))) &&
            ((piVar13 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                  *(ulong *)(*(int *)(this + 100) + 0x24)),
              *(float *)(param_5 + 8) < *(float *)(*piVar13 + 600) &&
                  (0.75 < fStack_38 != NAN(fStack_38))))) {
          *(undefined4 *)(this + 0x69c) = 1;
          *(undefined4 *)(this + 0x6a0) = 1;
          *(uint *)(this + 0x6f4) = uVar3;
        }
        if ((0.1 < *(float *)(this + 0x50)) &&
            (0.1 < *(float *)(this + 0x54))) {
          iVar4 = *(int *)(this + 100);
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
          if ((*(float *)(param_5 + 8) < *(float *)(*piVar13 + 0x254)) &&
              ((piVar13 = (int *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24)),
                *(float *)(*piVar13 + 600) < *(float *)(param_5 + 8) !=
                        (NAN(*(float *)(*piVar13 + 600)) ||
                         NAN(*(float *)(param_5 + 8))) &&
                    (ABS(param_7) < 1e-05 == NAN(ABS(param_7)))))) {
            *(undefined4 *)(this + 0x69c) = 2;
            if ((int)param_7 < 0) {
              uVar6 = 0xbf800000;
            } else {
              uVar6 = 0x3f800000;
            }
            this_01 = (float *)(this + 0x6fc);
            *(undefined4 *)(this + 0x708) = uVar6;
            *(undefined4 *)(this + 0x704) = 0;
            *(undefined4 *)(this + 0x700) = 0;
            *this_01 = 0.0;
            uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
            uVar23 = 0;
            if (uVar11 != 0) {
              do {
                pSVar12 = CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(this + 0x2e8), uVar23);
                if (*(int *)(pSVar12 + 0x124) != 0) {
                  *this_01 = *(float *)(pSVar12 + 0x144) + *this_01;
                  *(float *)(this + 0x700) =
                      *(float *)(pSVar12 + 0x148) + *(float *)(this + 0x700);
                  *(float *)(this + 0x704) =
                      *(float *)(pSVar12 + 0x14c) + *(float *)(this + 0x704);
                }
                uVar23 = uVar23 + 1;
              } while (uVar23 < uVar11);
            }
            fVar26 = *(float *)(this + 0x704) * *(float *)(this + 0x704) +
                     *this_01 * *this_01 +
                     *(float *)(this + 0x700) * *(float *)(this + 0x700);
            if (_DAT_00d06a80 < fVar26 == (NAN(_DAT_00d06a80) || NAN(fVar26))) {
              *(undefined4 *)(this + 0x69c) = 0;
              fVar26 = 0.0;
              *this_01 = 0.0;
              *(undefined4 *)(this + 0x700) = 0x3f800000;
            } else {
              fVar25 = (float10)__CIsqrt();
              fVar26 = 1.0 / (float)fVar25;
              *this_01 = fVar26 * *this_01;
              *(float *)(this + 0x700) = *(float *)(this + 0x700) * fVar26;
              fVar26 = fVar26 * *(float *)(this + 0x704);
            }
            pfVar8 = pfStack_e0;
            *(float *)(this + 0x704) = fVar26;
            fStack_b0 = *(float *)(this + 0x1dc) - *pfStack_e0;
            fStack_ac = *(float *)(this + 0x1e0) - pfStack_e0[1];
            fStack_a8 = *(float *)(this + 0x1e4) - pfStack_e0[2];
            fStack_e4 = *(float *)(this + 0x1f0) +
                        *(float *)(this + 0x1e8) * 0.0 +
                        *(float *)(this + 0x1ec) * 0.0;
            fStack_ec = fStack_e4 * 0.0;
            fStack_90 = fStack_ec + fStack_b0;
            fStack_8c = fStack_ec + fStack_ac;
            fStack_88 = fStack_e4 + fStack_a8;
            fStack_e8 = fStack_ec;
            fVar25 = (float10)__CIsqrt();
            *(float *)(this + 0x6ec) = (float)fVar25;
            if ((int)param_7 < 0) {
              fStack_f8 = -1.0;
            } else {
              fStack_f8 = 1.0;
            }
            fStack_100 = fStack_f8 *
                         (*(float *)(this + 0x700) * *(float *)(param_5 + 8) -
                          *(float *)(this + 0x704) * *(float *)(param_5 + 4));
            fStack_fc =
                fStack_f8 * (*(float *)(this + 0x704) * *(float *)param_5 -
                             *this_01 * *(float *)(param_5 + 8));
            fStack_f8 =
                fStack_f8 * (*this_01 * *(float *)(param_5 + 4) -
                             *(float *)(this + 0x700) * *(float *)param_5);
            fVar26 = fStack_fc * fStack_fc + fStack_100 * fStack_100 +
                     fStack_f8 * fStack_f8;
            if (_DAT_00d06a80 < fVar26 != (NAN(_DAT_00d06a80) || NAN(fVar26))) {
              fVar25 = (float10)__CIsqrt();
              fVar26 = 1.0 / (float)fVar25;
              fStack_100 = fVar26 * fStack_100;
              fStack_fc = fVar26 * fStack_fc;
              fStack_f8 = fVar26 * fStack_f8;
            }
            GmVec3::Mult((GmVec3 *)this_01, (GmMat3 *)(this + 0x6a4));
            if (*(float *)(this + 0x700) < 0.75) {
              *(undefined4 *)(this + 0x69c) = 0;
              *this_01 = 0.0;
              *(undefined4 *)(this + 0x700) = 0x3f800000;
              *(undefined4 *)(this + 0x704) = 0;
            }
            if ((int)param_7 < 0) {
              fStack_11c = -1.0;
            } else {
              fStack_11c = 1.0;
            }
            fStack_a4 = 0.0;
            fStack_a0 = 0.0;
            fStack_9c = 1.0;
            fVar26 =
                GmVec3::GetAngle((GmVec3 *)&fStack_a4, (GmVec3 *)&fStack_100);
            iVar4 = *(int *)(this + 100);
            fVar26 = fVar26 * fStack_11c;
            piVar13 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
            if ((*(float *)(*piVar13 + 0x290) < fVar26 !=
                 (NAN(*(float *)(*piVar13 + 0x290)) || NAN(fVar26))) ||
                (piVar13 = (int *)CFastBuffer<>::operator[](
                     (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24)),
                 fVar26 < -*(float *)(*piVar13 + 0x294))) {
              *(undefined4 *)(this + 0x69c) = 0;
            } else {
              GmVec3::SetMult((GmVec3 *)&fStack_a4, (GmVec3 *)&fStack_100,
                              (GmMat3 *)(this + 0x6a4));
              GmVec3::SetMult((GmVec3 *)&fStack_54, (GmVec3 *)pfVar8,
                              (GmIso4 *)(GmMat3 *)(this + 0x6a4));
              ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                  *(ulong *)(*(int *)(this + 100) + 0x24));
              fVar26 = CSceneVehicleCarTuning::M6GetBurnoutRadiusFromSpeed(
                  *ppCVar15, *(float *)(param_5 + 8));
              fVar26 = fVar26 + *(float *)(this + 0x6ec);
              *(float *)(this + 0x6f0) = fVar26;
              *(float *)(this + 0x6e0) = fVar26 * fStack_a4;
              *(float *)(this + 0x6e4) = fVar26 * fStack_a0;
              *(float *)(this + 0x6e8) = fVar26 * fStack_9c;
              *(float *)(this + 0x6e0) = fStack_54 + *(float *)(this + 0x6e0);
              *(float *)(this + 0x6e4) = *(float *)(this + 0x6e4) + fStack_50;
              *(float *)(this + 0x6e8) = fStack_4c + *(float *)(this + 0x6e8);
            }
            *(uint *)(this + 0x6a0) = (uint)(*(int *)(this + 0x69c) == 2);
          }
        }
      }
      if (*(int *)(this + 0x69c) == 0) {
        if (((0.1 < *(float *)(this + 0x54)) &&
             (*(float *)(param_5 + 8) < *(float *)(this + 0x5cc))) &&
            (ABS(*(float *)param_5) < 2.0 != NAN(ABS(*(float *)param_5)))) {
          *(undefined4 *)(this + 0x5c4) = 1;
        }
        if ((0.1 < *(float *)(this + 0x50)) &&
            ((0.0 < *(float *)(param_5 + 8) != NAN(*(float *)(param_5 + 8)) ||
              (2.0 < ABS(*(float *)param_5))))) {
          *(undefined4 *)(this + 0x5c4) = 0;
        }
        if ((*(float *)(this + 0x50) < 0.1 != NAN(*(float *)(this + 0x50))) &&
            (*(float *)(this + 0x54) < 0.1 != NAN(*(float *)(this + 0x54)))) {
          if ((0.0 < *(float *)(param_5 + 8) ==
               (*(float *)(param_5 + 8) == 0.0)) &&
              (ABS(*(float *)(param_5 + 8)) < 2.0 ==
               NAN(ABS(*(float *)(param_5 + 8))))) {
            *(undefined4 *)(this + 0x5c4) = 1;
          } else {
            *(undefined4 *)(this + 0x5c4) = 0;
          }
        }
        if ((0.0 < *(float *)(param_5 + 8) != NAN(*(float *)(param_5 + 8))) &&
            (*(int *)(this + 0x600) != 0))
          goto LAB_007c5b0e;
      } else {
      LAB_007c5b0e:
        *(undefined4 *)(this + 0x5c4) = 0;
      }
      fVar26 = *(float *)param_5;
      fVar29 = *(float *)(param_5 + 8);
      if ((int)-*(float *)param_5 < 0) {
        fVar27 = -1.0;
      } else {
        fVar27 = 1.0;
      }
      ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      fStack_58 = CSceneVehicleCarTuning::M6GetRolloverLateralFromSpeedRatio(
          *ppCVar15, (fVar26 * fVar26) / (ABS(fVar29) + 1.0));
      fStack_58 = fStack_58 * fVar27;
      fStack_60 = 0.0;
      uStack_5c = 0;
      AddVehicleTorque(this, (GmVec3 *)&fStack_60);
      fStack_120 = 0.0;
      fStack_118 = 0.0;
      uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
      uStack_d8 = (double)CONCAT44(uStack_d8._4_4_, uVar11);
      fStack_dc = 0.0;
      if (uVar11 != 0) {
        fVar26 = ABS((float)piStack_b4);
        do {
          pSVar12 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8),
                                              (ulong)fStack_dc);
          iVar4 = *(int *)(pSVar12 + 4);
          uStack_98 = (double)CONCAT44(uStack_98._4_4_, pSVar12);
          if (iVar4 == 0) {
            fVar29 = -*(float *)(this + 0x840);
          } else {
            fVar29 = *(float *)(this + 0x840);
          }
          fVar29 = fVar29 * 0.5;
          iVar5 = *(int *)(this + 100);
          fStack_cc = *(float *)(param_6 + 4) * fVar29 + *(float *)param_5;
          fStack_c8 = *(float *)(param_5 + 4) + 0.0;
          fStack_c4 = *(float *)(param_5 + 8) + 0.0;
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
          if (0.7 <= fVar26) {
            if (*(float *)(*piVar13 + 0x74) < (float)piStack_b4 ==
                (NAN(*(float *)(*piVar13 + 0x74)) || NAN((float)piStack_b4))) {
              fVar25 = (float10)__CIsin(extraout_ECX_02, extraout_EDX_01);
              pfStack_e0 = (float *)(float)fVar25;
            } else {
              pfStack_e0 = (float *)&DAT_3f800000;
            }
          } else {
            pfStack_e0 = (float *)0x0;
          }
          ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
          fVar27 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(
              *ppCVar15, *(float *)(param_5 + 8));
          iVar5 = *(int *)(this + 100);
          fVar27 = fVar27 * *(float *)(param_9 + 0xc);
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
          fStack_128 = -*(float *)(*piVar13 + 0xa4) * 0.5 *
                       (fStack_c4 * 0.0 + fStack_cc + fStack_c8 * 0.0);
          fStack_f0 = ABS(fStack_128);
          if (fVar27 < fStack_f0 != (NAN(fVar27) || NAN(fStack_f0))) {
            piVar13 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
            fVar28 = fVar27 * (1.0 - *(float *)(*piVar13 + 0xe4)) +
                     fStack_f0 * *(float *)(*piVar13 + 0xe4);
            fStack_118 = fStack_118 + fVar27;
            fStack_120 = fStack_f0 + fStack_120;
            if ((int)fStack_128 < 0) {
              fStack_128 = -1.0;
            } else {
              fStack_128 = 1.0;
            }
            fStack_f4 = 1.401298e-45;
            fStack_128 = fStack_128 * fVar28;
            fStack_f0 = fVar28;
          }
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
          fStack_f0 = *(float *)(*piVar13 + 0x98) * fStack_128;
          if (iVar4 != 0) {
            if (*(int *)(this + 0x5c4) == 0) {
              fVar27 = 1.0;
            } else {
              fVar27 = -1.0;
            }
            if (*(int *)((int)(float)uStack_98 + 300) == 0) {
              fVar28 = 1.0;
            } else {
              piVar13 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
              fVar28 = *(float *)(*piVar13 + 0x9c);
            }
            ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
            uStack_98 = (double)fStack_f0;
            fVar30 = CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed(
                *ppCVar15, *(float *)(param_5 + 8));
            fStack_f0 = (float)uStack_98 - fVar27 * (float)pfStack_e0 *
                                               *(float *)(this + 0x5e8) *
                                               fVar30 * fVar28;
          }
          fStack_ec = fStack_f0;
          fStack_e8 = fStack_f0 * 0.0;
          uStack_98 = (double)CONCAT44(uStack_98._4_4_, fStack_e8);
          fStack_a4 = fStack_e8 * 0.0 - fStack_e8 * fVar29;
          fStack_a0 = fStack_f0 * fVar29 - fStack_e8 * 0.0;
          fStack_9c = fStack_e8 * 0.0 - fStack_f0 * 0.0;
          fStack_e4 = fStack_e8;
          AddVehicleTorque(this, (GmVec3 *)&fStack_a4);
          fStack_dc = (float)((int)fStack_dc + 1);
        } while ((uint)fStack_dc < (int *)uStack_d8);
      }
      if (fStack_f4 != 0.0) {
        *(uint *)(this + 0x62c) = uVar3;
        if (iVar2 == 0) {
          *(uint *)(this + 0x630) = uVar3;
        }
        *(uint *)(this + 0x634) = uVar3 - *(int *)(this + 0x630);
      }
      fStack_110 = 1.0;
      if ((uVar3 == *(uint *)(this + 0x62c)) &&
          (1e-05 < fStack_118 != NAN(fStack_118))) {
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
            *(ulong *)(*(int *)(this + 100) + 0x24));
        fVar26 = ((fStack_120 - fStack_118) / fStack_118) /
                 *(float *)(*piVar13 + 0x200);
        fStack_110 = 0.0;
        if ((fVar26 < 0.0 == (fVar26 == 0.0)) &&
            (fStack_110 = fVar26, 1.0 < fVar26 != (fVar26 == 1.0))) {
          fStack_110 = 1.0;
        }
        fStack_110 = 1.0 - fStack_110;
      }
      ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      fVar26 = CSceneVehicleCarTuning::M5GetSlippingAccelFromSpeed(
          *ppCVar15, *(float *)(param_5 + 8));
      iVar2 = *(int *)(this + 100);
      if (*(int *)(this + 0x5c4) == 0) {
        ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
        fVar29 = CSceneVehicleCarTuning::M5GetAccelFromSpeed(
            *ppCVar15, *(float *)(param_5 + 8));
      } else {
        ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
        fVar29 = CSceneVehicleCarTuning::M6GetRearGearAccelFromSpeed(
            *ppCVar15, *(float *)(param_5 + 8));
      }
      if (*(int *)(this + 0x2e4) == 1) {
        fVar26 = 0.0;
      } else {
        fVar26 = (1.0 - fStack_110) * fVar26 + fVar29 * fStack_110;
      }
      iVar2 = *(int *)(this + 100);
      uStack_98 = (double)CONCAT44(uStack_98._4_4_, fVar26);
      fVar26 = *(float *)(this + 0x5e8);
      piVar13 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      iVar4 = *piVar13;
      ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      fVar28 = CSceneVehicleCarTuning::M5GetSteerSlowDownFromSpeed(
          *ppCVar15, *(float *)(param_5 + 8));
      fVar27 = *(float *)(iVar4 + 0x7c);
      iVar2 = *(int *)(this + 0x69c);
      fStack_dc = 1.0;
      pfStack_e0 = (float *)0x0;
      if (iVar2 == 1) {
        iVar4 = *(int *)(this + 100);
        pfVar18 = (float10 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
        uStack_d8 =
            (double)CONCAT44(uStack_d8._4_4_, uVar3 - *(int *)(this + 0x6f4));
        fVar25 = (float10)__CIsin(pfVar18, *(undefined4 *)pfVar18);
        fStack_dc = (*(float *)(*piVar13 + 0x29c) - 1.0) * (float)fVar25 + 1.0;
      }
      if (iVar2 == 3) {
        iVar2 = *(int *)(this + 100);
        iVar4 = *(int *)(this + 0x6f8);
        puVar10 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
        pGVar14 = CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
        uStack_d8 = (double)CONCAT44(uStack_d8._4_4_, pGVar14);
        fVar25 = (float10)__CIsin((float10 *)(uVar3 - iVar4), *puVar10);
        fStack_dc =
            (*(float *)(*(int *)uStack_d8 + 0x2ac) - 1.0) * (float)fVar25 + 1.0;
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
        uVar20 = (uint)(float10 *)(uVar3 - iVar4) / *(uint *)(*piVar13 + 0x2a8);
        fVar30 = (float)uVar20;
        if ((int)uVar20 < 0) {
          fVar30 = fVar30 + 4.294967e+09;
        }
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
        pfStack_e0 = (float *)((fVar30 - 1.0) * (fVar30 - 1.0) *
                               *(float *)(*piVar13 + 0x2b8));
      }
      if (*(int *)(this + 0x5c4) == 0) {
        fStack_110 = 0.0;
      } else {
        fStack_110 = -1.0;
      }
      if (*(int *)(this + 0x600) == 0) {
        piStack_b4 = (int *)0x0;
      } else {
        piStack_b4 = *(int **)(this + 0x5f4);
      }
      if (*(int *)(this + 0x5c4) == 0) {
        fVar30 = 1.0;
      } else {
        fVar30 = -1.0;
      }
      fStack_128 =
          (float)pfStack_e0 +
          (fStack_dc * (fVar29 * (float)piStack_b4 +
                        (*(float *)(this + 0x50) * *(float *)(param_9 + 4) +
                         fStack_110 * *(float *)(param_9 + 4) *
                             *(float *)(this + 0x54)) *
                            (float)uStack_98) -
           fVar27 * ABS(fVar26) * fVar28 * fVar30);
      if (iVar21 != 0) {
        fStack_128 = fStack_128 * 0.5;
      }
      if (*(int *)(this + 0x60c) != 0) {
        if (*(int *)(this + 0x600) == 0) {
          fStack_128 = fVar29 * 0.0;
        } else {
          fStack_128 = fVar29 * *(float *)(this + 0x5f4);
        }
      }
      fStack_118 = 0.0;
      if (0.0 < *(float *)(param_5 + 8) != NAN(*(float *)(param_5 + 8))) {
        fStack_120 = 1.0;
        uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
        uVar23 = 0;
        if (uVar11 != 0) {
          do {
            pSVar12 = CFastBuffer<>::operator[](
                (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar23);
            if (*(int *)(pSVar12 + 300) != 0) {
              piVar13 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                  *(ulong *)(*(int *)(this + 100) + 0x24));
              fStack_120 = *(float *)(*piVar13 + 0x240) * fStack_120;
            }
            uVar23 = uVar23 + 1;
          } while (uVar23 < uVar11);
        }
        iVar21 = *(int *)(this + 100);
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
        piVar19 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
        fStack_118 = (*(float *)(*piVar13 + 0x44) * *(float *)(param_5 + 8) +
                      *(float *)(*piVar19 + 0x40)) *
                     *(float *)(this + 0x54) * fStack_120;
        if (*param_10 == 0) {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fVar26 = *(float *)(*piVar13 + 0x4c);
        } else {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fVar26 = *(float *)(*piVar13 + 0x48);
        }
        fVar26 = *(float *)(param_9 + 8) * fVar26;
        if (fVar26 < fStack_118 != (NAN(fVar26) || NAN(fStack_118))) {
          uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
          uVar23 = 0;
          fStack_118 = fVar26;
          if (uVar11 != 0) {
            fStack_f4 = 1.401298e-45;
            do {
              pSVar12 = CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(this + 0x2e8), uVar23);
              uVar23 = uVar23 + 1;
              *(undefined4 *)(pSVar12 + 300) = 1;
            } while (uVar23 < uVar11);
          }
        }
      }
      if ((*(float *)(param_5 + 8) < 0.0) && (0.1 < *(float *)(this + 0x50))) {
        if (*(int *)(this + 0x60c) == 0) {
          iVar21 = *(int *)(this + 100);
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          piVar19 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fVar26 = -fStack_128 * *(float *)(*piVar13 + 0x228) *
                   *(float *)(param_5 + 8);
          if ((*(float *)(*piVar19 + 0x22c) < fVar26 !=
               (NAN(*(float *)(*piVar19 + 0x22c)) || NAN(fVar26))) &&
              (0.75 < fStack_38 != NAN(fStack_38))) {
            *(uint *)(this + 0x6f4) = uVar3;
            *(undefined4 *)(this + 0x69c) = 1;
            *(undefined4 *)(this + 0x6a0) = 1;
          }
        }
        fStack_120 = 1.0;
        uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
        uVar23 = 0;
        if (uVar11 != 0) {
          do {
            pSVar12 = CFastBuffer<>::operator[](
                (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar23);
            if (*(int *)(pSVar12 + 300) != 0) {
              piVar13 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                  *(ulong *)(*(int *)(this + 100) + 0x24));
              fStack_120 = *(float *)(*piVar13 + 0x240) * fStack_120;
            }
            uVar23 = uVar23 + 1;
          } while (uVar23 < uVar11);
        }
        iVar21 = *(int *)(this + 100);
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
        piVar19 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
        fStack_118 = (*(float *)(*piVar13 + 0x40) -
                      *(float *)(*piVar19 + 0x44) * *(float *)(param_5 + 8)) *
                     *(float *)(this + 0x50) * fStack_120;
        if (*param_10 == 0) {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fVar26 = *(float *)(*piVar13 + 0x24c);
        } else {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fVar26 = *(float *)(*piVar13 + 0x248);
        }
        fVar26 = *(float *)(param_9 + 8) * fVar26;
        if (fVar26 < fStack_118 != (NAN(fVar26) || NAN(fStack_118))) {
          uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
          uVar23 = 0;
          fStack_118 = fVar26;
          if (uVar11 != 0) {
            fStack_f4 = 1.401298e-45;
            do {
              pSVar12 = CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(this + 0x2e8), uVar23);
              uVar23 = uVar23 + 1;
              *(undefined4 *)(pSVar12 + 300) = 1;
            } while (uVar23 < uVar11);
          }
        }
      }
      *param_11 = fStack_118;
      if (*(int *)(param_5 + 8) < 0) {
        fVar26 = -1.0;
      } else {
        fVar26 = 1.0;
      }
      iVar21 = *(int *)(this + 100);
      fStack_114 = fStack_128 - fVar26 * fStack_118;
      piVar13 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
      uStack_d8 = (double)CONCAT44(
          uStack_d8._4_4_, *(float *)(*piVar13 + 0x30) * *(float *)param_9);
      piVar13 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
      fVar26 = *(float *)(*piVar13 + 0x2c) * *(float *)param_9;
      if (fVar26 < *(float *)(param_5 + 8) !=
          (NAN(fVar26) || NAN(*(float *)(param_5 + 8)))) {
        if (0.0 <= fStack_114) {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fStack_114 = -*(float *)(*piVar13 + 0x60);
        } else {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fStack_114 = fStack_114 - *(float *)(*piVar13 + 0x60);
        }
      }
      if (*(float *)(param_5 + 8) < -(float)(int *)uStack_d8) {
        if (0.0 < fStack_114 == NAN(fStack_114)) {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fStack_114 = *(float *)(*piVar13 + 0x60);
        } else {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fStack_114 = *(float *)(*piVar13 + 0x60) + fStack_114;
        }
      }
      fStack_a4 = 0.0;
      fStack_a0 = 0.0;
      fStack_9c = fStack_114 * param_4;
      AddVehicleCentralForce(this, (GmVec3 *)&fStack_a4);
      iVar21 = *(int *)(this + 100);
      piVar13 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
      piVar19 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
      fStack_a8 = (-*(float *)(*piVar13 + 100) * *(float *)(param_2 + 8)) /
                  *(float *)(*piVar19 + 0x160);
      fStack_b0 = 0.0;
      fStack_ac = 0.0;
      AddVehicleCentralForce(this, (GmVec3 *)&fStack_b0);
    }
    *(float *)(this + 0x628) = fStack_f4;
    goto LAB_007c67f9;
  }
  if (((*(float *)(this + 0x50) < 0.1) ||
       (*(float *)(this + 0x54) < 0.1 != NAN(*(float *)(this + 0x54)))) ||
      (ABS(param_7) < 1e-05 != NAN(ABS(param_7)))) {
  LAB_007c47de:
    *(undefined4 *)(this + 0x69c) = 0;
  } else {
    if ((int)param_7 < 0) {
      fVar26 = -1.0;
    } else {
      fVar26 = 1.0;
    }
    if (((((NAN(*(float *)(this + 0x708)) || NAN(fVar26)) ==
           (*(float *)(this + 0x708) == fVar26)) ||
          (*(int *)(this + 0x5dc) != 0)) ||
         ((0 < *(int *)(this + 0x5d8) || ((param_8 == 0 || (iVar21 != 0)))))) ||
        (*(int *)(this + 0x60c) != 0))
      goto LAB_007c47de;
    fStack_f8 = 0.0;
    fStack_fc = 0.0;
    fStack_100 = 0.0;
    uVar11 = CFastBuffer<>::GetCount(this_00);
    uVar23 = 0;
    if (uVar11 != 0) {
      do {
        pSVar12 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar23);
        fStack_100 = *(float *)(pSVar12 + 0x144) + fStack_100;
        uVar23 = uVar23 + 1;
        fStack_fc = *(float *)(pSVar12 + 0x148) + fStack_fc;
        fStack_f8 = *(float *)(pSVar12 + 0x14c) + fStack_f8;
      } while (uVar23 < uVar11);
    }
    fVar26 =
        fStack_fc * fStack_fc + fStack_100 * fStack_100 + fStack_f8 * fStack_f8;
    if (_DAT_00d06a80 < fVar26 == (NAN(_DAT_00d06a80) || NAN(fVar26))) {
      fStack_f8 = 0.0;
      fStack_100 = 0.0;
      fStack_fc = 1.0;
    } else {
      fVar25 = (float10)__CIsqrt();
      fVar26 = 1.0 / (float)fVar25;
      fStack_100 = fVar26 * fStack_100;
      fStack_fc = fStack_fc * fVar26;
      fStack_f8 = fVar26 * fStack_f8;
    }
    GmVec3::SetMult(aGStack_3c, (GmVec3 *)&fStack_100,
                    (GmMat3 *)(GmIso4 *)(this + 0x6a4));
    fVar26 = GmVec3::GetAngle(aGStack_3c, (GmVec3 *)(this + 0x6fc));
    piVar13 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
        *(ulong *)(*(int *)(this + 100) + 0x24));
    if (*(float *)(*piVar13 + 0x28c) < ABS(fVar26) ==
        (NAN(*(float *)(*piVar13 + 0x28c)) || NAN(ABS(fVar26)))) {
      GmIso4::SetInverse(aGStack_30, (GmIso4 *)(this + 0x6a4));
      GmVec3::SetMult((GmVec3 *)&fStack_ec, (GmVec3 *)(this + 0x6e0),
                      aGStack_30);
      fStack_c0 = fStack_ec - *pfStack_e0;
      fStack_bc = fStack_e8 - pfStack_e0[1];
      fStack_b8 = fStack_e4 - pfStack_e0[2];
      fVar29 =
          fStack_b8 * fStack_b8 + fStack_c0 * fStack_c0 + fStack_bc * fStack_bc;
      fVar25 = (float10)__CIsqrt();
      fVar26 = (float)fVar25;
      uStack_d8 = (double)CONCAT44(fStack_bc, fStack_c0);
      fStack_d0 = fStack_b8;
      if (_DAT_00d06a80 < fVar29 != (NAN(_DAT_00d06a80) || NAN(fVar29))) {
        fVar25 = (float10)__CIsqrt();
        fStack_d0 = 1.0 / (float)fVar25;
        uStack_d8 =
            (double)CONCAT44(fStack_bc * fStack_d0, fStack_d0 * fStack_c0);
        fStack_d0 = fStack_d0 * fStack_b8;
      }
      iVar21 = *(int *)(this + 100);
      fStack_cc = fStack_fc * fStack_d0 - fStack_f8 * uStack_d8._4_4_;
      fStack_c8 = (float)(int *)uStack_d8 * fStack_f8 - fStack_100 * fStack_d0;
      fStack_c4 =
          uStack_d8._4_4_ * fStack_100 - fStack_fc * (float)(int *)uStack_d8;
      fVar29 = fStack_c4 * *(float *)(param_5 + 8) +
               fStack_cc * *(float *)param_5 +
               fStack_c8 * *(float *)(param_5 + 4);
      piVar13 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
      if (*(float *)(*piVar13 + 0x284) < ABS(fVar29) !=
          (NAN(*(float *)(*piVar13 + 0x284)) || NAN(ABS(fVar29)))) {
        *(undefined4 *)(this + 0x69c) = 0;
      }
      if ((*(float *)(this + 0x6ec) < fVar26 !=
           (NAN(*(float *)(this + 0x6ec)) || NAN(fVar26))) ||
          (piVar13 = (int *)CFastBuffer<>::operator[](
               (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24)),
           fVar26 < *(float *)(*piVar13 + 0x280))) {
        pGVar14 = CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar21 + 0x14),
                                            *(ulong *)(iVar21 + 0x24));
        CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar21 + 0x14),
                                  *(ulong *)(iVar21 + 0x24));
        fVar25 = (float10)__CIexp(pGVar14);
        fStack_e4 = ((fVar29 * fVar29) / fVar26) * (float)fVar25;
        fStack_ec = fStack_e4 * (float)(int *)uStack_d8;
        fStack_e8 = fStack_e4 * uStack_d8._4_4_;
        fStack_e4 = fStack_e4 * fStack_d0;
        AddVehicleCentralForce(this, (GmVec3 *)&fStack_ec);
      } else {
        *(undefined4 *)(this + 0x69c) = 0;
      }
      uVar11 = CFastBuffer<>::GetCount(this_00);
      uVar23 = 0;
      if (uVar11 != 0) {
        do {
          pSVar12 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar23);
          WheelAddForceToVehicle(this, pSVar12, param_2);
          uVar23 = uVar23 + 1;
          *(undefined4 *)(pSVar12 + 300) = 0;
        } while (uVar23 < uVar11);
      }
      ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      this_02 = *ppCVar15;
      fVar27 = GmFunc::Sign(param_7);
      fVar28 = CSceneVehicleCarTuning::M6GetLateralSpeedFromBurnoutRadius(
          this_02, fVar26);
      piVar13 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      fStack_a8 = *(float *)(*piVar13 + 0x264) * (-fVar27 * fVar28 - fVar29);
      fStack_b0 = fStack_a8 * fStack_cc;
      fStack_ac = fStack_a8 * fStack_c8;
      fStack_a8 = fStack_a8 * fStack_c4;
      AddVehicleCentralForce(this, (GmVec3 *)&fStack_b0);
      fStack_ec = 0.0;
      fStack_e8 = 0.0;
      fStack_e4 = 1.0;
      fStack_f4 = GmVec3::GetAngle((GmVec3 *)&fStack_ec, (GmVec3 *)&uStack_d8);
      fStack_f4 = fStack_f4 / 3.141593;
      iVar21 = GmFunc::IsANumber(fStack_f4);
      if (iVar21 == 0) {
      LAB_007c4700:
        *(undefined4 *)(this + 0x69c) = 0;
      } else {
        iVar21 = *(int *)(this + 100);
        fVar27 = fVar27 * fStack_f4 * 3.141593;
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
        if ((fVar27 < -*(float *)(*piVar13 + 0x294)) ||
            (piVar13 = (int *)CFastBuffer<>::operator[](
                 (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24)),
             *(float *)(*piVar13 + 0x290) < fVar27 !=
                 (NAN(*(float *)(*piVar13 + 0x290)) || NAN(fVar27))))
          goto LAB_007c4700;
        fVar27 = *(float *)(param_6 + 4);
        if (fStack_f4 <= 0.0) {
          if (0.0 < fVar27 == NAN(fVar27)) {
            fVar27 = fStack_f4 + 1.0;
            piVar13 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
            fVar27 = -*(float *)(*piVar13 + 0x270) * *(float *)(param_6 + 4) *
                     fVar27 * fVar27;
          } else {
            piVar13 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
            fVar27 = -*(float *)(*piVar13 + 0x26c) * *(float *)(param_6 + 4);
          }
        } else if (0.0 <= fVar27) {
          fVar27 = fStack_f4 - 1.0;
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fVar27 = -*(float *)(*piVar13 + 0x270) * *(float *)(param_6 + 4) *
                   fVar27 * fVar27;
        } else {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fVar27 = -*(float *)(*piVar13 + 0x26c) * *(float *)(param_6 + 4);
        }
        fVar29 = fVar29 / fVar26;
        fStack_118 = 0.0;
        if (0.0 < fStack_f4 == NAN(fStack_f4)) {
          if (0.0 < fVar29 != NAN(fVar29)) {
            piVar13 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
            fVar26 = *(float *)(*piVar13 + 0x274);
            goto LAB_007c46a4;
          }
        } else if (0.0 >= fVar29 && fVar29 != 0.0) {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
          fVar26 = *(float *)(*piVar13 + 0x274);
        LAB_007c46a4:
          fStack_118 = -fVar26 * fVar29;
        }
        piVar13 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar21 + 0x14), *(ulong *)(iVar21 + 0x24));
        fStack_e8 =
            *(float *)(*piVar13 + 0x268) * fStack_f4 + fVar27 + fStack_118;
        fStack_ec = fStack_e8 * 0.0;
        fStack_e4 = fStack_ec;
        AddVehicleTorque(this, (GmVec3 *)&fStack_ec);
      }
      fVar26 = *(float *)param_5;
      ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      fVar26 = CSceneVehicleCarTuning::M6GetDonutRolloverFromSpeed(*ppCVar15,
                                                                   ABS(fVar26));
      fVar29 = GmFunc::Sign(*(float *)param_5);
      fStack_88 = -fVar29 * fVar26;
      fStack_90 = fStack_88 * 0.0;
      fStack_8c = fStack_90;
      AddVehicleTorque(this, (GmVec3 *)&fStack_90);
      ppCVar15 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      fStack_6c = CSceneVehicleCarTuning::M6GetBurnoutRolloverFromSpeed(
          *ppCVar15, *(float *)(param_5 + 8));
      uStack_68 = 0;
      fStack_64 = 0.0;
      AddVehicleTorque(this, (GmVec3 *)&fStack_6c);
    } else {
      *(undefined4 *)(this + 0x69c) = 0;
    }
  }
  if (*(int *)(this + 0x69c) != 2) {
    *(undefined4 *)(this + 0x69c) = 1;
    pCVar16 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
    if (pCVar16 == (CMwCmdBufferCore *)0x0) {
      pCVar16 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
    }
    puVar17 = CMwTimerAdapter::GetTickTime((CMwTimerAdapter *)pCVar16);
    *(ulong *)(this + 0x6f4) = *puVar17;
  }
LAB_007c67f9:
  *(undefined4 *)(this + 0x70c) = *(undefined4 *)param_5;
  *(undefined4 *)(this + 0x710) = *(undefined4 *)(param_5 + 4);
  *(undefined4 *)(this + 0x714) = *(undefined4 *)(param_5 + 8);
  return;
}

/* protected: void __thiscall
   CSceneVehicleCar::ComputeVehicleGroundMaterialVals(struct
   CSceneVehicleMaterial::SBlendableVals &,int &) */

void __thiscall CSceneVehicleCar::ComputeVehicleGroundMaterialVals(
    CSceneVehicleCar *this, SBlendableVals *param_1, int *param_2)

{
  CFastBuffer<> *this_00;
  int iVar1;
  float fVar2;
  SBlendableVals *pSVar3;
  SBlendableVals *pSVar4;
  SSimulationWheel *pSVar5;
  ulong *puVar6;
  int *piVar7;
  int iVar8;

  pSVar3 = param_1;
  *param_2 = 0;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  this_00 = (CFastBuffer<> *)(this + 0x2e8);
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar8 = 0;
  pSVar4 = (SBlendableVals *)CFastBuffer<>::GetCount(this_00);
  param_1 = (SBlendableVals *)0x0;
  if (pSVar4 != (SBlendableVals *)0x0) {
    do {
      pSVar5 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, (ulong)param_1);
      if (*(int *)(pSVar5 + 0x124) != 0) {
        pSVar5 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 0);
        puVar6 = (ulong *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x6c),
            (uint) * (ushort *)(pSVar5 + 0x128));
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*(int *)(this + 0x68) + 0x14), *puVar6);
        iVar1 = *piVar7;
        iVar8 = iVar8 + 1;
        *(float *)pSVar3 = *(float *)(iVar1 + 0x14) + *(float *)pSVar3;
        *(float *)(pSVar3 + 4) =
            *(float *)(iVar1 + 0x18) + *(float *)(pSVar3 + 4);
        *(float *)(pSVar3 + 8) =
            *(float *)(iVar1 + 0x1c) + *(float *)(pSVar3 + 8);
        *(float *)(pSVar3 + 0xc) =
            *(float *)(iVar1 + 0x20) + *(float *)(pSVar3 + 0xc);
        *param_2 = 1;
      }
      param_1 = param_1 + 1;
    } while (param_1 < pSVar4);
    if (iVar8 != 0) {
      fVar2 = (float)iVar8;
      if (iVar8 < 0) {
        fVar2 = fVar2 + 4.294967e+09;
      }
      fVar2 = 1.0 / fVar2;
      *(float *)pSVar3 = fVar2 * *(float *)pSVar3;
      *(float *)(pSVar3 + 4) = *(float *)(pSVar3 + 4) * fVar2;
      *(float *)(pSVar3 + 8) = fVar2 * *(float *)(pSVar3 + 8);
      *(float *)(pSVar3 + 0xc) = fVar2 * *(float *)(pSVar3 + 0xc);
    }
  }
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::CreateDefaultData(void) */

void __thiscall CSceneVehicleCar::CreateDefaultData(CSceneVehicleCar *this)

{
  CSceneVehicleTunings *pCVar1;
  CSceneVehicleCarTuning *this_00;
  CMwNod **ppCVar2;
  CSceneVehicleStruct *this_01;
  SSimulationWheel *this_02;
  ulong uVar3;
  CMwNod *pCVar4;
  int iVar5;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00accb81;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSceneVehicle::CreateDefaultData((CSceneVehicle *)this);
  pCVar1 = (CSceneVehicleTunings *)operator_new(0x28);
  pCVar4 = (CMwNod *)0x0;
  local_4 = 0;
  if (pCVar1 == (CSceneVehicleTunings *)0x0) {
    pCVar1 = (CSceneVehicleTunings *)0x0;
  } else {
    pCVar1 = (CSceneVehicleTunings *)CSceneVehicleTunings::CSceneVehicleTunings(
        pCVar1);
  }
  local_4 = 0xffffffff;
  this_00 = (CSceneVehicleCarTuning *)operator_new(0x3ac);
  local_4 = 1;
  if (this_00 != (CSceneVehicleCarTuning *)0x0) {
    pCVar4 = (CMwNod *)CSceneVehicleCarTuning::CSceneVehicleCarTuning(this_00);
  }
  local_4 = 0xffffffff;
  ppCVar2 =
      (CMwNod **)CFastBuffer<>::AddNewElem((CFastBuffer<> *)(pCVar1 + 0x14));
  if (pCVar4 != *ppCVar2) {
    if (pCVar4 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar4);
    }
    if (*ppCVar2 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*ppCVar2);
    }
    *ppCVar2 = pCVar4;
  }
  CSceneVehicle::TuningsSet((CSceneVehicle *)this, pCVar1);
  this_01 = (CSceneVehicleStruct *)operator_new(0x50);
  local_4 = 2;
  if (this_01 == (CSceneVehicleStruct *)0x0) {
    pCVar4 = (CMwNod *)0x0;
  } else {
    pCVar4 = (CMwNod *)CSceneVehicleStruct::CSceneVehicleStruct(this_01);
  }
  local_4 = 0xffffffff;
  if (pCVar4 != *(CMwNod **)(this + 0x60)) {
    if (pCVar4 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar4);
    }
    if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x60));
    }
    *(CMwNod **)(this + 0x60) = pCVar4;
  }
  CFastBuffer<>::Reset((CFastBuffer<> *)(*(int *)(this + 0x60) + 0x14));
  iVar5 = 4;
  do {
    this_02 = CFastBuffer<>::AddNewElem(
        (CFastBuffer<> *)(*(int *)(this + 0x60) + 0x14));
    CSceneVehicleStruct::SSimulationWheel::Reset(this_02);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar3 =
      CFastBuffer<>::GetCount((CFastBuffer<> *)(*(int *)(this + 0x60) + 0x14));
  CFastBuffer<>::AllocSetCount((CFastBuffer<> *)(this + 0x2e8), uVar3);
  ExceptionList = local_c;
  return;
}

/* protected: void __thiscall CSceneVehicleCar::CreateFakeContacts(void) */

void __thiscall CSceneVehicleCar::CreateFakeContacts(CSceneVehicleCar *this)

{
  int iVar1;
  CPlugBitmap *this_00;
  CPlugFileImg *this_01;
  float fVar2;
  ulong uVar3;
  SSimulationWheel *pSVar4;
  ulong *puVar5;
  int *piVar6;
  int iVar7;
  int **ppiVar8;
  GmIso4 *pGVar9;
  byte *pbVar10;
  undefined4 extraout_ECX;
  float10 fVar11;
  float fStack_9c;
  ulong uStack_98;
  ulong uStack_88;
  uint local_7c;
  GmVec3 aGStack_74[12];
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined2 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float fStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined2 uStack_20;
  GmVec3 local_14[8];
  float fStack_c;

  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28), local_14);
  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  local_7c = 0;
  if (uVar3 != 0) {
    do {
      pSVar4 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), local_7c);
      if (*(int *)(pSVar4 + 0x124) != 0) {
        puVar5 = (ulong *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x6c),
            (uint) * (ushort *)(pSVar4 + 0x128));
        piVar6 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*(int *)(this + 0x68) + 0x14), *puVar5);
        iVar1 = *piVar6;
        this_00 = *(CPlugBitmap **)(iVar1 + 0x24);
        if (this_00 == (CPlugBitmap *)0x0) {
          return;
        }
        iVar7 =
            CPlugFileImg::IsInSystemMemory(*(CPlugFileImg **)(this_00 + 0x48));
        if ((iVar7 == 0) &&
            (iVar7 = CPlugBitmap::ReGenerate(this_00), iVar7 == 0)) {
          return;
        }
        ppiVar8 = (int **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
        pGVar9 = (GmIso4 *)(**(code **)(**ppiVar8 + 0x78))();
        GmVec3::SetMult(aGStack_74, (GmVec3 *)(pSVar4 + 0x34), pGVar9);
        fVar11 = (float10)__CIfmod(extraout_ECX);
        iVar7 = *(int *)(*(int *)(this_00 + 0x48) + 0x18);
        fVar2 = (float)*(int *)(*(int *)(this_00 + 0x48) + 0x18);
        if (iVar7 < 0) {
          fVar2 = fVar2 + 4.294967e+09;
        }
        this_01 = *(CPlugFileImg **)(this_00 + 0x48);
        uStack_88 = (ulong)(longlong)ROUND(
            fVar2 * (ABS((float)fVar11) / *(float *)(iVar1 + 0x28)));
        fVar11 = (float10)__CIfmod(iVar7);
        fVar2 = (float)*(int *)(this_01 + 0x1c);
        if (*(int *)(this_01 + 0x1c) < 0) {
          fVar2 = fVar2 + 4.294967e+09;
        }
        uStack_98 = (ulong)(longlong)ROUND(
            fVar2 * (ABS((float)fVar11) / *(float *)(iVar1 + 0x2c)));
        pbVar10 = CPlugFileImg::GetPixel(this_01, uStack_88, uStack_98);
        if (*pbVar10 != 0) {
          fStack_9c = ((float)(uint)*pbVar10 / 255.0) * fStack_c *
                      *(float *)(iVar1 + 0x30);
          if (*(float *)(iVar1 + 0x34) < fStack_9c !=
              (NAN(*(float *)(iVar1 + 0x34)) || NAN(fStack_9c))) {
            fStack_9c = *(float *)(iVar1 + 0x34);
          }
          uStack_50 = *(undefined4 *)(pSVar4 + 0x34);
          uStack_20 = *(undefined2 *)(pSVar4 + 0x128);
          uStack_4c = *(undefined4 *)(pSVar4 + 0x38);
          uStack_48 = *(undefined4 *)(pSVar4 + 0x3c);
          uStack_5c = 0;
          uStack_60 = 0;
          uStack_68 = 0;
          uStack_58 = 0x3f800000;
          uStack_28 = 0;
          uStack_64 = 0;
          uStack_24 = 0;
          uStack_54 = 0;
          uStack_44 = 0;
          fStack_40 = -fStack_9c;
          uStack_3c = 0;
          uStack_30 = 0;
          uStack_34 = 0;
          uStack_38 = 0;
          WheelAbsorbContact(this, pSVar4, (CHmsPhysicalContact *)&uStack_68);
        }
      }
      local_7c = local_7c + 1;
    } while (local_7c < uVar3);
  }
  return;
}

/* private: void __thiscall CSceneVehicleCar::CreateOldStruct(void) */

void __thiscall CSceneVehicleCar::CreateOldStruct(CSceneVehicleCar *this)

{
  CFastBuffer<> *this_00;
  int iVar1;
  CSceneVehicleStruct *this_01;
  CMwNod *this_02;
  SVisualVehicle *pSVar2;
  ulong uVar3;
  SSplit *pSVar4;
  ulong uVar5;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00accbab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_01 = (CSceneVehicleStruct *)operator_new(0x50);
  local_4 = 0;
  if (this_01 == (CSceneVehicleStruct *)0x0) {
    this_02 = (CMwNod *)0x0;
  } else {
    this_02 = (CMwNod *)CSceneVehicleStruct::CSceneVehicleStruct(this_01);
  }
  local_4 = 0xffffffff;
  if (this_02 != *(CMwNod **)(this + 0x60)) {
    if (this_02 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_02);
    }
    if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x60));
    }
    *(CMwNod **)(this + 0x60) = this_02;
  }
  iVar1 = *(int *)(this + 0x60);
  CFastBuffer<>::AllocSetCount((CFastBuffer<> *)(iVar1 + 0x14), 4);
  pSVar2 = CFastBuffer<>::AddNewElem(
      (CFastBuffer<> *)(*(int *)(this + 0x60) + 0x20));
  this_00 = (CFastBuffer<> *)(pSVar2 + 0x24);
  uVar3 =
      CFastBuffer<>::GetCount((CFastBuffer<> *)(CFastBuffer<> *)(iVar1 + 0x14));
  CFastBuffer<>::AllocSetCount(this_00, uVar3);
  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_00);
  uVar5 = 0;
  if (uVar3 != 0) {
    do {
      pSVar4 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar5);
      *(ulong *)(pSVar4 + 0x20) = uVar5;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(pSVar4 + 4) = 1;
      *(undefined4 *)(pSVar4 + 0xc) = 1;
      *(undefined4 *)(pSVar4 + 0x14) = 1;
    } while (uVar5 < uVar3);
  }
  ExceptionList = local_c;
  return;
}

/* public: __thiscall CSceneVehicleCar::CSceneVehicleCar(void) */

CSceneVehicleCar *__thiscall CSceneVehicleCar::CSceneVehicleCar(
    CSceneVehicleCar *this)

{
  CSceneVehicleCar *this_00;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acc9ee;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSceneVehicle::CSceneVehicle((CSceneVehicle *)this);
  local_4 = 0;
  *(undefined ***)this = vftable;
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x2e8));
  local_4._0_1_ = 1;
  SVehicleCarState::Reset((SVehicleCarState *)(this + 0x2f8));
  SVehicleCarState::Reset((SVehicleCarState *)(this + 0x3a0));
  SVehicleCarState::Reset((SVehicleCarState *)(this + 0x448));
  SVehicleCarState::Reset((SVehicleCarState *)(this + 0x4f0));
  SEngine::SEngine((SEngine *)(this + 0x59c));
  *(undefined4 *)(this + 0x728) = 0;
  *(undefined4 *)(this + 0x730) = 0;
  *(undefined4 *)(this + 0x724) = 0x3f800000;
  *(undefined4 *)(this + 0x734) = 0;
  *(undefined4 *)(this + 0x738) = 0;
  *(undefined4 *)(this + 0x718) = 0x3f800000;
  *(undefined4 *)(this + 0x71c) = 1000;
  *(undefined4 *)(this + 0x720) = 1000;
  *(undefined4 *)(this + 0x72c) = 0;
  `eh_vector_constructor_iterator' (this + 0x750, 0x30, 4, SDynaPart::SDynaPart,
                                    SPlugGpuLoadFx::~SPlugGpuLoadFx);
  local_4 = CONCAT31(local_4._1_3_, 2);
  CSceneMobil::EnableAbsorbContactCallback((CSceneMobil *)this, 1);

  // PTR_vftable_00d06a84 XREF[2]: CSceneVehicleCar:007c313b(*),
  // FUN_00b22780:00b22780(*)
  //       00d06a84 e4 ef b9 00     addr
  //       CCallbackSceneVehicleCarComputeForces::vftable

  // PTR_vftable_00d06a88 XREF[2]: CSceneVehicleCar:007c314a(*),
  // FUN_00b22790:00b22790(*)
  //       00d06a88 a0 ef b9 00     addr
  //       CCallbackSceneVehicleCarAfterContacts::vftable 00d06a8c 00 ?? 00h

  // NOTE: THESE ^^^^^^ ARE THE VTABLE CALLBACKS HERE
  CHmsItem::CallbackSet(*(CHmsItem **)(this + 0x28), 3,
                        (CCallback *)&PTR_vftable_00d06a84);
  CHmsItem::CallbackSet(*(CHmsItem **)(this + 0x28), 4,
                        (CCallback *)&PTR_vftable_00d06a88);

  *(uint *)(this + 0x2f4) = *(uint *)(this + 0x2f4) & 0xfffffff7 | 7;
  VehicleBlockSpeedSet(this, 1);
  VehicleBlockSpeed2Set(this_00, 1);
  *(undefined4 *)(this + 0x840) = 0x3f800000;
  *(undefined4 *)(this + 0x74c) = 1;
  *(undefined4 *)(this + 0x810) = 0;
  *(undefined4 *)(this + 0x814) = 0x3f060a92;
  *(undefined4 *)(this + 0x2e0) = 0x438ae38e;
  *(undefined4 *)(this + 0x5cc) = 0x41200000;
  *(undefined4 *)(this + 0x6dc) = 0;
  *(undefined4 *)(this + 0x6d8) = 0;
  *(undefined4 *)(this + 0x6d4) = 0;
  *(undefined4 *)(this + 0x6ec) = 0x3f800000;
  *(undefined4 *)(this + 0x6f0) = 0x40000000;
  *(undefined4 *)(this + 0x86c) = 0;
  *(undefined4 *)(this + 0x870) = 0;
  *(undefined4 *)(this + 0x874) = 0;
  *(undefined4 *)(this + 0x848) = 0;
  *(undefined4 *)(this + 0x84c) = 0;
  *(undefined4 *)(this + 0x850) = 0;
  *(undefined4 *)(this + 0x854) = 0;
  *(undefined4 *)(this + 0x858) = 0;
  *(undefined4 *)(this + 0x85c) = 0;
  *(undefined4 *)(this + 0x860) = 0;
  *(undefined4 *)(this + 0x864) = 0;
  *(undefined4 *)(this + 0x868) = 0;
  *(undefined4 *)(this + 0x844) = 0;
  *(undefined4 *)(this + 0x1e4) = 0;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1dc) = 0;
  *(undefined4 *)(this + 0x1e8) = 0xbf800000;
  *(undefined4 *)(this + 0x1ec) = 0xbf800000;
  *(undefined4 *)(this + 0x1f0) = 0xbf800000;
  *(undefined4 *)(this + 0x834) = 0;
  *(undefined4 *)(this + 0x838) = 0;
  *(undefined4 *)(this + 0x244) = 0x41200000;
  *(undefined4 *)(this + 0x83c) = 0;
  *(undefined4 *)(this + 0x24c) = 0x41700000;
  *(undefined4 *)(this + 0x250) = 0x3f800000;
  *(undefined4 *)(this + 0x214) = 0x43160000;
  *(undefined4 *)(this + 0x218) = 0x41000000;
  *(undefined4 *)(this + 0x22c) = 0x41000000;
  *(undefined4 *)(this + 0x228) = 0x43160000;
  ExceptionList = local_c;
  return this;
}

/* protected: void __thiscall CSceneVehicleCar::EnableTurbo(unsigned
   long,unsigned long,float,enum CSceneVehicleCar::ETurboType,unsigned long) */

void __thiscall CSceneVehicleCar::EnableTurbo(CSceneVehicleCar *this,
                                              ulong param_1, ulong param_2,
                                              float param_3, ETurboType param_4,
                                              ulong param_5)

{
  float fVar1;

  if (*(ETurboType *)(this + 0x600) != param_4) {
    *(ulong *)(this + 0x5f8) = param_1;
    if (*(CSceneSoundSource **)(this + 0x26c) != (CSceneSoundSource *)0x0) {
      CSceneSoundSource::Play(*(CSceneSoundSource **)(this + 0x26c));
    }
    *(undefined4 *)(this + 0x604) = 0;
  }
  if (param_4 != 1) {
    if ((param_4 != 2) || (*(ulong *)(this + 0x604) == param_5))
      goto LAB_007bd023;
    fVar1 = GetRouletteValue01(param_1 - *(int *)(this + 0x5d0),
                               s_TurboRoulettePeriodMs);
    *(float *)(this + 0x608) = fVar1;
    fVar1 = GetRouletteBoostFactorFromValue01(fVar1);
    param_3 = fVar1 * param_3;
    *(ulong *)(this + 0x604) = param_5;
  }
  *(float *)(this + 0x5f4) = param_3;
LAB_007bd023:
  *(ulong *)(this + 0x5fc) = param_1 + param_2;
  *(ETurboType *)(this + 0x600) = param_4;
  return;
}

/* protected: void __thiscall CSceneVehicleCar::EngineIntegrate(float,float) */

void __thiscall CSceneVehicleCar::EngineIntegrate(CSceneVehicleCar *this,
                                                  float param_1, float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  bool bVar8;
  ulong uVar9;
  SSimulationWheel *pSVar10;
  int *piVar11;
  float *pfVar12;
  float *pfVar13;
  int iVar14;
  ulong uVar15;
  float10 fVar16;

  bVar7 = 0.1 < param_1;
  bVar8 = true;
  uVar9 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar15 = 0;
  if (uVar9 != 0) {
    do {
      pSVar10 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar15);
      if (*(int *)(pSVar10 + 0x124) != 0) {
        bVar8 = false;
        break;
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 < uVar9);
  }
  if (0.0 < *(float *)(this + 0x5c0) != NAN(*(float *)(this + 0x5c0))) {
    *(float *)(this + 0x5c0) = *(float *)(this + 0x5c0) - param_2;
  }
  if ((bVar8) ||
      (0.0 < *(float *)(this + 0x5c0) != NAN(*(float *)(this + 0x5c0)))) {
    bVar8 = true;
  } else {
    bVar8 = false;
  }
  iVar5 = *(int *)(this + 100);
  piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                             *(ulong *)(iVar5 + 0x24));
  if (*(int *)(*piVar11 + 0x354) != 5) {
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                               *(ulong *)(iVar5 + 0x24));
    fVar3 = *(float *)(*piVar11 + 0x2c);
    fVar4 = ABS(param_1);
    if ((bVar8) || (bVar7 = true, 0.0 < *(float *)(this + 0x5c0))) {
      bVar7 = false;
    }
    iVar14 = *(int *)(this + 0x5c8);
    if (iVar14 < 2) {
      uVar9 = 0;
    } else {
      uVar9 = iVar14 - 1;
    }
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                               *(ulong *)(iVar5 + 0x24));
    pfVar12 = (float *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*piVar11 + 0x2d4), uVar9);
    fVar1 = *pfVar12;
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                               *(ulong *)(iVar5 + 0x24));
    pfVar12 = (float *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*piVar11 + 0x2e0), uVar9);
    fVar2 = *pfVar12;
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                               *(ulong *)(iVar5 + 0x24));
    pfVar12 = (float *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*piVar11 + 0x2c4), uVar9);
    fVar16 = (float10)__CIsqrt();
    fVar3 = ((float)fVar16 / (fVar3 * 0.2)) * *pfVar12;
    if (bVar7) {
      fVar4 = fVar3;
      if (*(int *)(this + 0x5c4) == 0) {
        if (iVar14 == 0) {
          *(undefined4 *)(this + 0x5c8) = 1;
          *(undefined4 *)(this + 0x5c0) = 0x3d23d70a;
        } else {
          if ((fVar1 < fVar3 == (NAN(fVar1) || NAN(fVar3))) || (4 < iVar14)) {
            if ((fVar2 <= fVar3) || (iVar14 < 2))
              goto LAB_007be202;
            iVar14 = iVar14 + -1;
          } else {
            iVar14 = iVar14 + 1;
          }
          *(int *)(this + 0x5c8) = iVar14;
          *(undefined4 *)(this + 0x5c0) = 0x3d23d70a;
        }
      } else if (iVar14 != 0) {
        *(undefined4 *)(this + 0x5c8) = 0;
        *(undefined4 *)(this + 0x5c0) = 0x3d23d70a;
      }
    } else if ((0.0 < *(float *)(this + 0x5c0) !=
                (*(float *)(this + 0x5c0) == 0.0)) &&
               (*(float *)(this + 0x5c0) <= param_2 + param_2)) {
      *(float *)(this + 0x5b4) =
          *(float *)(this + 0x5b4) - *(float *)(this + 0x59c) * param_2 * 1.9;
    }
  LAB_007be202:
    if (bVar7) {
      fVar3 = 12.0;
    } else {
      fVar3 = 3.5;
    }
    *(float *)(this + 0x5b4) =
        (*(float *)(this + 0x59c) * fVar4 - *(float *)(this + 0x5b4)) *
            param_2 * fVar3 +
        *(float *)(this + 0x5b4);
    goto LAB_007be257;
  }
  if (bVar8) {
    if (bVar7) {
      piVar11 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
      *(float *)(this + 0x5b4) =
          *(float *)(*piVar11 + 0x2f0) * param_2 + *(float *)(this + 0x5b4);
    } else {
      piVar11 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
      *(float *)(this + 0x5b4) =
          *(float *)(this + 0x5b4) - *(float *)(*piVar11 + 0x2f4) * param_2;
    }
    goto LAB_007be257;
  }
  if ((*(int *)(this + 0x69c) == 1) || (*(int *)(this + 0x69c) == 2)) {
    bVar8 = true;
    if (*(int *)(this + 0x5c8) == 0)
      goto LAB_007bd83d;
    *(undefined4 *)(this + 0x2e4) = 4;
  } else {
    bVar8 = false;
  LAB_007bd83d:
    if (*(int *)(this + 0x2e4) == 4) {
      *(undefined4 *)(this + 0x2e4) = 0;
    }
  }
  iVar14 = *(int *)(this + 0x2e4);
  if (iVar14 == 2) {
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                               *(ulong *)(iVar5 + 0x24));
    if ((*(float *)(*piVar11 + 0x32c) < *(float *)(this + 0x714) !=
         (NAN(*(float *)(*piVar11 + 0x32c)) ||
          NAN(*(float *)(this + 0x714)))) ||
        (piVar11 = (int *)CFastBuffer<>::operator[](
             (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24)),
         *(float *)(this + 0x714) < *(float *)(*piVar11 + 0x330))) {
      *(undefined4 *)(this + 0x744) = 1;
    } else {
      *(undefined4 *)(this + 0x744) = 0;
    }
    *(undefined4 *)(this + 0x5bc) = 0x3f800000;
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                               *(ulong *)(iVar5 + 0x24));
    pfVar12 = (float *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*piVar11 + 0x2c4), 1);
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                               *(ulong *)(iVar5 + 0x24));
    pfVar13 = (float *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*piVar11 + 0x304), 1);
    *(float *)(this + 0x5b8) =
        *pfVar13 * 0.0 + ABS(*(float *)(this + 0x714)) * *pfVar12;
    if (*(int *)(this + 0x744) == 0) {
      if (bVar7) {
      LAB_007bdd33:
        piVar11 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
        fVar3 = *(float *)(*piVar11 + 0x324);
        goto LAB_007bdd44;
      }
      piVar11 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
      fVar3 = *(float *)(this + 0x5b4) - *(float *)(*piVar11 + 0x328) * param_2;
    } else {
      piVar11 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
      fVar3 = *(float *)(this + 0x5b4) - *(float *)(*piVar11 + 0x328) * param_2;
    }
    *(float *)(this + 0x5b4) = fVar3;
    if (fVar3 <= *(float *)(this + 0x5b8)) {
      fVar3 = *(float *)(this + 0x5b8);
      *(undefined4 *)(this + 0x2e4) = 0;
      *(undefined4 *)(this + 0x744) = 0;
      goto LAB_007bdd4e;
    }
  } else {
    if (iVar14 == 3) {
      piVar11 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
      if ((*(float *)(this + 0x714) < *(float *)(*piVar11 + 0x338)) ||
          (piVar11 = (int *)CFastBuffer<>::operator[](
               (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24)),
           *(float *)(*piVar11 + 0x334) < *(float *)(this + 0x714) !=
               (NAN(*(float *)(*piVar11 + 0x334)) ||
                NAN(*(float *)(this + 0x714))))) {
        *(undefined4 *)(this + 0x744) = 1;
      } else {
        *(undefined4 *)(this + 0x744) = 0;
      }
      *(undefined4 *)(this + 0x5bc) = 0x3f800000;
      piVar11 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
      pfVar12 = (float *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*piVar11 + 0x2c4), 0);
      piVar11 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
      pfVar13 = (float *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*piVar11 + 0x304), 0);
      *(float *)(this + 0x5b8) =
          *pfVar13 * 0.0 + ABS(*(float *)(this + 0x714)) * *pfVar12;
      if (*(int *)(this + 0x744) == 0) {
        if (bVar7)
          goto LAB_007bdd33;
        piVar11 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
        fVar3 =
            *(float *)(this + 0x5b4) - *(float *)(*piVar11 + 0x328) * param_2;
      } else {
        piVar11 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
        fVar3 =
            *(float *)(this + 0x5b4) - *(float *)(*piVar11 + 0x328) * param_2;
      }
      *(float *)(this + 0x5b4) = fVar3;
      if (*(float *)(this + 0x5b8) < fVar3)
        goto LAB_007bdd54;
      fVar3 = *(float *)(this + 0x5b8);
      *(undefined4 *)(this + 0x2e4) = 0;
      *(undefined4 *)(this + 0x744) = 0;
    } else {
      if (iVar14 != 4) {
        iVar14 = *(int *)(this + 0x628);
        if ((iVar14 == 0) || (!bVar7)) {
          fVar3 = 1.0;
        } else {
          fVar3 = 1.15;
          if (*(float *)(this + 0x5bc) < 1.15) {
            fVar3 = (1.15 - *(float *)(this + 0x5bc)) * 0.3 * param_2 +
                    *(float *)(this + 0x5bc);
          }
        }
        uVar9 = *(ulong *)(this + 0x5c8);
        *(float *)(this + 0x5bc) = fVar3;
        piVar11 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
        pfVar12 = (float *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*piVar11 + 0x2c4), uVar9);
        *(float *)(this + 0x5b8) =
            ABS(*(float *)(this + 0x714) * *(float *)(this + 0x5bc)) * *pfVar12;
        if (*(int *)(this + 0x5c4) == 0) {
        LAB_007bd927:
          if (uVar9 == 0) {
          LAB_007bd92b:
            *(undefined4 *)(this + 0x5b8) = 0;
          }
        } else {
          if (uVar9 != 0)
            goto LAB_007bd92b;
          if (*(int *)(this + 0x5c4) == 0)
            goto LAB_007bd927;
        }
        if (*(float *)(this + 0x5b4) < *(float *)(this + 0x5b8) ==
            (NAN(*(float *)(this + 0x5b4)) || NAN(*(float *)(this + 0x5b8)))) {
          if (bVar7) {
            if ((iVar14 == 0) || (bVar8)) {
              piVar11 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
              fVar3 = *(float *)(this + 0x5b4);
              fVar4 = *(float *)(*piVar11 + 0x31c);
            } else {
              piVar11 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
              fVar3 = *(float *)(this + 0x5b4);
              fVar4 = *(float *)(*piVar11 + 0x2f4);
            }
          } else {
            piVar11 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
            fVar3 = *(float *)(this + 0x5b4);
            fVar4 = *(float *)(*piVar11 + 0x328);
          }
          *(float *)(this + 0x5b4) = fVar3 - fVar4 * param_2;
          if (*(float *)(this + 0x5b4) < *(float *)(this + 0x5b8)) {
            *(undefined4 *)(this + 0x2e4) = 0;
          }
        } else {
          piVar11 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
          fVar3 =
              *(float *)(*piVar11 + 800) * param_2 + *(float *)(this + 0x5b4);
          *(float *)(this + 0x5b4) = fVar3;
          if (*(float *)(this + 0x5b8) < fVar3 !=
              (NAN(*(float *)(this + 0x5b8)) || NAN(fVar3))) {
            *(undefined4 *)(this + 0x2e4) = 0;
          }
        }
        goto LAB_007bdd54;
      }
      fVar3 = *(float *)(this + 0x59c);
      *(float *)(this + 0x5b8) = fVar3;
      *(undefined4 *)(this + 0x5bc) = 0x3f933333;
      if (*(float *)(this + 0x5b4) < fVar3 ==
          (NAN(*(float *)(this + 0x5b4)) || NAN(fVar3))) {
        if (*(float *)(this + 0x5b4) <= fVar3)
          goto LAB_007bdd54;
        piVar11 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
        fVar3 = *(float *)(*piVar11 + 0x2f4);
      } else {
        piVar11 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
        fVar3 = *(float *)(*piVar11 + 0x2ec);
      }
    LAB_007bdd44:
      fVar3 = fVar3 * param_2 + *(float *)(this + 0x5b4);
    }
  LAB_007bdd4e:
    *(float *)(this + 0x5b4) = fVar3;
  }
LAB_007bdd54:
  piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                             *(ulong *)(iVar5 + 0x24));
  if ((((*(float *)(*piVar11 + 0x330) < *(float *)(this + 0x714) ==
         (NAN(*(float *)(*piVar11 + 0x330)) ||
          NAN(*(float *)(this + 0x714)))) ||
        (piVar11 = (int *)CFastBuffer<>::operator[](
             (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24)),
         *(float *)(*piVar11 + 0x32c) <= *(float *)(this + 0x714))) ||
       (!bVar7)) ||
      ((*(int *)(this + 0x5c4) != 0 || (*(int *)(this + 0x2e4) != 0)))) {
    piVar11 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar5 + 0x14),
                                               *(ulong *)(iVar5 + 0x24));
    if ((((*(float *)(*piVar11 + 0x338) < *(float *)(this + 0x714) !=
           (NAN(*(float *)(*piVar11 + 0x338)) ||
            NAN(*(float *)(this + 0x714)))) &&
          ((piVar11 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24)),
            *(float *)(this + 0x714) < *(float *)(*piVar11 + 0x334) &&
                (bVar7)))) &&
         (*(int *)(this + 0x5c4) != 0)) &&
        (*(int *)(this + 0x2e4) == 0)) {
      *(undefined4 *)(this + 0x2e4) = 3;
      *(undefined4 *)(this + 0x744) = 0;
      if (*(int *)(this + 0x5c8) != 0) {
        *(undefined4 *)(this + 0x5c8) = 0;
        *(undefined4 *)(this + 0x5c0) = 0x3ccccccd;
      }
    }
  } else {
    *(undefined4 *)(this + 0x2e4) = 2;
    *(undefined4 *)(this + 0x744) = 0;
    if (*(int *)(this + 0x5c8) == 0) {
      *(undefined4 *)(this + 0x5c0) = 0x3ccccccd;
      *(undefined4 *)(this + 0x5c8) = 1;
    }
  }
  if ((*(int *)(this + 0x2e4) == 0) || (*(int *)(this + 0x2e4) == 1)) {
    if (*(int *)(this + 0x5c4) == 0) {
      if (*(int *)(this + 0x5c8) == 0) {
        *(undefined4 *)(this + 0x2e4) = 1;
        *(undefined4 *)(this + 0x748) = 0;
        if (*(float *)(this + 0x5b4) < 1000.0 !=
            NAN(*(float *)(this + 0x5b4))) {
          *(undefined4 *)(this + 0x5c0) = 0x3ccccccd;
          *(undefined4 *)(this + 0x5c8) = 1;
        }
      }
      uVar9 = *(ulong *)(this + 0x5c8);
      if (0 < (int)uVar9) {
        piVar11 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
        pfVar12 = (float *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*piVar11 + 0x2d4), uVar9);
        if ((*pfVar12 * *(float *)(this + 0x59c) < *(float *)(this + 0x5b8) ==
             (NAN(*pfVar12 * *(float *)(this + 0x59c)) ||
              NAN(*(float *)(this + 0x5b8)))) ||
            (4 < (int)uVar9)) {
          piVar11 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar5 + 0x14), *(ulong *)(iVar5 + 0x24));
          pfVar12 = (float *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(*piVar11 + 0x2e0), uVar9);
          if ((*(float *)(this + 0x5b8) <
               *pfVar12 * *(float *)(this + 0x59c)) &&
              (1 < (int)uVar9)) {
            *(undefined4 *)(this + 0x5c0) = 0x3ccccccd;
            *(ulong *)(this + 0x5c8) = uVar9 - 1;
            *(undefined4 *)(this + 0x2e4) = 1;
            *(undefined4 *)(this + 0x748) = 1;
          }
        } else {
          *(undefined4 *)(this + 0x5c0) = 0x3ccccccd;
          *(ulong *)(this + 0x5c8) = uVar9 + 1;
          *(undefined4 *)(this + 0x2e4) = 1;
          *(undefined4 *)(this + 0x748) = 0;
        }
      }
    } else if (*(int *)(this + 0x5c8) != 0) {
      *(undefined4 *)(this + 0x2e4) = 1;
      uVar6 = 0x3ccccccd;
      *(undefined4 *)(this + 0x748) = 1;
      if (*(float *)(this + 0x5b4) < 1000.0 != NAN(*(float *)(this + 0x5b4))) {
        *(undefined4 *)(this + 0x5c8) = 0;
        if (bVar8) {
          uVar6 = 0x3b03126f;
        }
        *(undefined4 *)(this + 0x5c0) = uVar6;
      }
    }
  }
LAB_007be257:
  fVar3 = *(float *)(this + 0x5b4);
  fVar4 = *(float *)(this + 0x59c);
  fVar1 = 0.0;
  if ((fVar3 < 0.0 == (fVar3 == 0.0)) &&
      (fVar1 = fVar3, fVar4 < fVar3 != (fVar4 == fVar3))) {
    *(float *)(this + 0x5b4) = fVar4;
    return;
  }
  *(float *)(this + 0x5b4) = fVar1;
  return;
}

/* WARNING: Switch with 1 destination removed at 0x007bc738 : 11 cases all go to
 * same destination */
/* public: virtual unsigned long __thiscall
 * CSceneVehicleCar::GetChunkInfo(unsigned long)const  */

ulong __thiscall CSceneVehicleCar::GetChunkInfo(CSceneVehicleCar *this,
                                                ulong param_1)

{
  ulong uVar1;

  if (param_1 < 0xa02b00c) {
    if (param_1 == 0xa02b00b) {
      return 1;
    }
    if (param_1 + 0xf5fd5000 < 0xb) {
      return 1;
    }
  } else {
    if (param_1 < 0xa02b012) {
      if (param_1 != 0xa02b011) {
        switch (param_1) {
        case 0xa02b00c:
          return 3;
        case 0xa02b00d:
        case 0xa02b00e:
        case 0xa02b00f:
        case 0xa02b010:
          break;
        default:
          goto switchD_007bc75b_caseD_5;
        }
      }
      return 1;
    }
    if (param_1 < 0xa02b015) {
      if (param_1 == 0xa02b014) {
        return 1;
      }
      if (param_1 == 0xa02b012) {
        return 1;
      }
      if (param_1 == 0xa02b013) {
        return 1;
      }
    } else if (param_1 == 0xffffffff) {
      return 0xffffffff;
    }
  }
switchD_007bc75b_caseD_5:
  uVar1 = CSceneVehicle::GetChunkInfo((CSceneVehicle *)this, param_1);
  return uVar1;
}

/* protected: void __thiscall CSceneVehicleCar::GetLateralFriction(class GmVec3
   const &,class GmVec3 const &,struct CSceneVehicleMaterial::SBlendableVals
   *,float,int,float &,int &) */

void __thiscall CSceneVehicleCar::GetLateralFriction(
    CSceneVehicleCar *this, GmVec3 *param_1, GmVec3 *param_2,
    SBlendableVals *param_3, float param_4, int param_5, float *param_6,
    int *param_7)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int *piVar4;
  int *piVar5;
  CSceneVehicleCarTuning **ppCVar6;
  float fVar7;

  iVar2 = *(int *)(this + 100);
  fVar7 = *(float *)(param_1 + 8) * *(float *)(param_2 + 8) +
          *(float *)param_2 * *(float *)param_1 +
          *(float *)(param_1 + 4) * *(float *)(param_2 + 4);
  piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  fVar3 = -fVar7 * *(float *)(*piVar4 + 0x1a8) -
          *(float *)(*piVar5 + 0x1ac) * ABS(fVar7) * fVar7;
  if (param_5 == 0) {
    fVar1 = 1.0;
  } else {
    piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    fVar1 = *(float *)(*piVar4 + 0x1c0);
  }
  ppCVar6 = (CSceneVehicleCarTuning **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
  fVar7 = CSceneVehicleCarTuning::M4GetMaxFrictionForceFromSpeed(*ppCVar6,
                                                                 ABS(fVar7));
  fVar1 = *(float *)(param_3 + 0xc) * param_4 * fVar7 * fVar1;
  if (fVar1 < ABS(fVar3) != (NAN(fVar1) || NAN(ABS(fVar3)))) {
    if ((int)fVar3 < 0) {
      fVar7 = -1.0;
    } else {
      fVar7 = 1.0;
    }
    *param_7 = 1;
    *param_6 = fVar1 * fVar7;
    return;
  }
  *param_7 = 0;
  *param_6 = fVar3;
  return;
}

/* public: float __thiscall CSceneVehicleCar::GetMaxSpeed(void) */

float __thiscall CSceneVehicleCar::GetMaxSpeed(CSceneVehicleCar *this)

{
  int *piVar1;

  piVar1 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  return *(float *)(*piVar1 + 0x2c) * 3.6;
}

/* public: virtual unsigned long __thiscall
 * CSceneVehicleCar::GetMwClassId(void)const  */

ulong __thiscall CSceneVehicleCar::GetMwClassId(CSceneVehicleCar *this)

{
  return 0xa02b000;
}

/* public: static float __cdecl
 * CSceneVehicleCar::GetRouletteBoostFactorFromValue01(float) */

float __cdecl CSceneVehicleCar::GetRouletteBoostFactorFromValue01(float param_1)

{
  return param_1 + 1.0;
}

/* public: float __thiscall
 * CSceneVehicleCar::GetRouletteCurrentBoostFactor(void)const  */

float __thiscall CSceneVehicleCar::GetRouletteCurrentBoostFactor(
    CSceneVehicleCar *this)

{
  float fVar1;

  fVar1 = GetRouletteBoostFactorFromValue01(*(float *)(this + 0x608));
  return fVar1;
}

/* public: static float __cdecl CSceneVehicleCar::GetRouletteValue01(unsigned
 * long,unsigned long) */

float __cdecl CSceneVehicleCar::GetRouletteValue01(ulong param_1, ulong param_2)

{
  float fVar1;
  float fVar2;

  fVar1 = (float)(param_1 % param_2);
  if ((int)(param_1 % param_2) < 0) {
    fVar1 = fVar1 + 4.294967e+09;
  }
  fVar2 = (float)param_2;
  if ((int)param_2 < 0) {
    fVar2 = fVar2 + 4.294967e+09;
  }
  fVar1 = fVar1 / fVar2;
  if (fVar1 < 0.5714286 != NAN(fVar1)) {
    return 0.0;
  }
  if (fVar1 < 0.8571429 != NAN(fVar1)) {
    return 0.5;
  }
  return 1.0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* protected: void __thiscall CSceneVehicleCar::GetSlopeAdherence(class GmVec3
   const &,float &,float
   &) */

void __thiscall CSceneVehicleCar::GetSlopeAdherence(CSceneVehicleCar *this,
                                                    GmVec3 *param_1,
                                                    float *param_2,
                                                    float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 *pfVar5;
  int *piVar6;
  float10 **ppfVar7;
  float10 *extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  float10 fVar8;
  float10 fVar9;

  fVar1 = *(float *)(param_1 + 8) * *(float *)(param_1 + 8) +
          *(float *)param_1 * *(float *)param_1 +
          *(float *)(param_1 + 4) * *(float *)(param_1 + 4);
  if (_DAT_00d06a80 < fVar1 != (NAN(_DAT_00d06a80) || NAN(fVar1))) {
    iVar4 = *(int *)(this + 100);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar4 + 0x14),
                                              *(ulong *)(iVar4 + 0x24));
    fVar1 = *(float *)(*piVar6 + 0xd4);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar4 + 0x14),
                                              *(ulong *)(iVar4 + 0x24));
    fVar2 = *(float *)(*piVar6 + 0xd8);
    fVar3 = *(float *)(param_1 + 4);
    fVar8 = (float10)__CIsqrt();
    fVar3 = ABS(fVar3 / (float)fVar8);
    *param_2 = fVar3;
    if (fVar1 <= fVar3) {
      if (fVar2 < fVar3 == (NAN(fVar2) || NAN(fVar3))) {
        fVar9 = (float10)__CIcos(extraout_ECX, extraout_EDX);
        fVar1 = 1.0 - (float)fVar9;
      } else {
        fVar1 = 1.0;
      }
    } else {
      fVar1 = 0.0;
    }
    *param_2 = fVar1;
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar4 + 0x14),
                                              *(ulong *)(iVar4 + 0x24));
    fVar1 = *(float *)(*piVar6 + 0xdc);
    ppfVar7 = (float10 **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(iVar4 + 0x14), *(ulong *)(iVar4 + 0x24));
    pfVar5 = *ppfVar7;
    fVar2 = *(float *)(pfVar5 + 0xe);
    fVar3 = ABS(*(float *)(param_1 + 4) / (float)fVar8);
    *param_3 = fVar3;
    if (fVar3 < fVar1) {
      *param_3 = 0.0;
      return;
    }
    if (fVar2 < fVar3 != (NAN(fVar2) || NAN(fVar3))) {
      *param_3 = 1.0;
      return;
    }
    fVar8 = (float10)__CIcos(pfVar5, extraout_EDX_00);
    *param_3 = 1.0 - (float)fVar8;
  }
  return;
}

/* public: virtual unsigned long __thiscall
   CSceneVehicleCar::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CSceneVehicleCar::GetUidChunkFromIndex(CSceneVehicleCar *this,
                                                        ulong param_1)

{
  if (0xd < param_1) {
    return param_1 - 0xe | 0xa02b000;
  }
  if (0xc < param_1) {
    return param_1 - 0xd | 0xa060000;
  }
  if (5 < param_1) {
    return param_1 - 6 | 0xa011000;
  }
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0xa005000;
}

/* protected: unsigned long __thiscall
   CSceneVehicleCar::GetWheelFromSurfaceTree(class CPlugTree const *) */

ulong __thiscall CSceneVehicleCar::GetWheelFromSurfaceTree(
    CSceneVehicleCar *this, CPlugTree *param_1)

{
  ulong uVar1;
  SSimulationWheel *pSVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      pSVar2 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar3);
      if (*(CPlugTree **)(pSVar2 + 0xc) == param_1) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0xffffffff;
}

/* public: virtual int __thiscall CSceneVehicleCar::HasSavedStateChanged(void)
 */

int __thiscall CSceneVehicleCar::HasSavedStateChanged(CSceneVehicleCar *this)

{
  int iVar1;

  iVar1 = CHmsItem::IsStateDifferentFrom(*(CHmsItem **)(this + 0x28),
                                         (GmIso4 *)(this + 0x848));
  return iVar1;
}

/* protected: void __thiscall CSceneVehicleCar::IntegrateVehicle(float) */

void __thiscall CSceneVehicleCar::IntegrateVehicle(CSceneVehicleCar *this,
                                                   float param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  SSimulationWheel *pSVar5;
  ulong uVar6;
  ulong uVar7;
  float fVar8;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  ulong local_10;
  GmVec3 local_c[8];
  float local_4;

  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28), local_c);
  if (((byte)this[0x2f4] & 1) != 0) {
    iVar2 = *(int *)(this + 100);
    piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    local_20 = ABS(local_4);
    local_1c =
        local_20 * *(float *)(*piVar3 + 0x70) + *(float *)(*piVar4 + 0x6c);
    local_10 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
    uVar6 = 0;
    if (local_10 != 0) {
      do {
        pSVar5 =
            CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), uVar6);
        GmMat3::Set((GmMat3 *)(pSVar5 + 0xc0), (GmMat3 *)(pSVar5 + 0x10));
        if (*(int *)(pSVar5 + 4) == 0) {
          fVar8 = 0.0;
        } else {
          if (local_1c < 1e-05 == NAN(local_1c)) {
            local_18 = -*(float *)(this + 0x5e8) / local_1c;
          } else {
            local_18 = 0.0;
          }
          GmMat3::RotateY((GmMat3 *)(pSVar5 + 0xc0), local_18);
          iVar2 = *(int *)(this + 100);
          local_20 = 30.0;
          piVar3 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
          if (*(int *)(*piVar3 + 0x378) != 0) {
            local_18 = 0.0;
            piVar3 = (int *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
            local_14 = ABS(local_4) * 3.6;
            CFuncKeysReal::GetValue(*(CFuncKeysReal **)(*piVar3 + 0x378),
                                    local_14, &local_20, (ulong *)&local_18);
          }
          local_14 = (local_20 * 3.141593) / 180.0;
          fVar8 = -*(float *)(this + 0x5e8) * local_14;
        }
        *(float *)(pSVar5 + 0x158) = fVar8;
        WheelUpdateSpeedFromVehicleSpeed(this, pSVar5, local_4, param_1);
        SSimulationWheel::SRealTimeState::Integrate(
            (SRealTimeState *)(pSVar5 + 0xb4), param_1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < local_10);
    }
  }
  if (((byte)this[0x2f4] & 2) != 0) {
    uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
    uVar7 = 0;
    if (uVar6 != 0) {
      do {
        fVar8 = param_1;
        pSVar5 = CFastBuffer<>::operator[](
            (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar7);
        WheelIntegrate(this, pSVar5, fVar8);
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar6);
    }
  }
  if (((byte)this[0x2f4] & 4) != 0) {
    if (*(int *)(this + 0x60c) == 0) {
      if (*(int *)(this + 0x5c4) == 0) {
        local_20 = *(float *)(this + 0x50);
      } else {
        local_20 = *(float *)(this + 0x54);
      }
      EngineIntegrate(this, local_20, param_1);
    } else {
      *(undefined4 *)(this + 0x5b4) = 0;
    }
  }
  iVar2 = *(int *)(this + 100);
  piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                            *(ulong *)(iVar2 + 0x24));
  if (0.0 < *(float *)(*piVar3 + 0x94)) {
    if (*(float *)(this + 0x5e8) - *(float *)(this + 0x58) < 0.0 ==
        NAN(*(float *)(this + 0x5e8) - *(float *)(this + 0x58))) {
      local_20 = -1.0;
    } else {
      local_20 = 1.0;
    }
    piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar2 + 0x14),
                                              *(ulong *)(iVar2 + 0x24));
    fVar1 = *(float *)(*piVar3 + 0x94) * local_20 * param_1 +
            *(float *)(this + 0x5e8);
    fVar8 = *(float *)(this + 0x58);
    if (*(float *)(this + 0x58) <= *(float *)(this + 0x5e8)) {
      if (fVar8 <= fVar1)
        goto LAB_007c3bd5;
    } else if (fVar8 < fVar1 == (NAN(fVar8) || NAN(fVar1)))
      goto LAB_007c3bd5;
  }
  fVar1 = *(float *)(this + 0x58);
LAB_007c3bd5:
  *(float *)(this + 0x5e8) = fVar1;
  (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 100) +
               0xbc))(0);
  return;
}

/* protected: int __thiscall
 * CSceneVehicleCar::IsAllWheelGroundContactId(unsigned char) */

int __thiscall CSceneVehicleCar::IsAllWheelGroundContactId(
    CSceneVehicleCar *this, uchar param_1)

{
  ulong uVar1;
  SSimulationWheel *pSVar2;
  uint uVar3;
  ulong uVar4;

  uVar3 = 0;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      pSVar2 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar4);
      if (*(int *)(pSVar2 + 0x124) == 0) {
        uVar3 = uVar3 + 1;
      } else if (*(ushort *)(pSVar2 + 0x128) != (ushort)param_1) {
        return 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return (uint)(uVar3 < uVar1);
}

/* protected: int __thiscall CSceneVehicleCar::IsGroundContact(void) */

int __thiscall CSceneVehicleCar::IsGroundContact(CSceneVehicleCar *this)

{
  ulong uVar1;
  SSimulationWheel *pSVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      pSVar2 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar3);
      if (*(int *)(pSVar2 + 0x124) != 0) {
        return 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0;
}

/* protected: int __thiscall CSceneVehicleCar::IsGroundContactId(unsigned
   char,class GmVec3
   &,unsigned long &) */

int __thiscall CSceneVehicleCar::IsGroundContactId(CSceneVehicleCar *this,
                                                   uchar param_1,
                                                   GmVec3 *param_2,
                                                   ulong *param_3)

{
  ulong uVar1;
  SSimulationWheel *pSVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      pSVar2 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar3);
      if ((*(int *)(pSVar2 + 0x124) != 0) &&
          (*(ushort *)(pSVar2 + 0x128) == (ushort)param_1)) {
        *(undefined4 *)param_2 = *(undefined4 *)(pSVar2 + 0x130);
        *(undefined4 *)(param_2 + 4) = *(undefined4 *)(pSVar2 + 0x134);
        *(undefined4 *)(param_2 + 8) = *(undefined4 *)(pSVar2 + 0x138);
        *param_3 = *(ulong *)(pSVar2 + 0x13c);
        return 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0;
}

/* protected: virtual int __thiscall CSceneVehicleCar::IsRubberBall(void) */

int __thiscall CSceneVehicleCar::IsRubberBall(CSceneVehicleCar *this)

{
  return *(int *)(this + 0x844);
}

/* public: virtual class CMwClassInfo const * __thiscall
 * CSceneVehicleCar::MwGetClassInfo(void)const
 */

CMwClassInfo *__thiscall CSceneVehicleCar::MwGetClassInfo(
    CSceneVehicleCar *this)

{
  return (CMwClassInfo *)&m_MwClassInfo_CSceneVehicleCar;
}

/* public: virtual int __thiscall CSceneVehicleCar::MwIsKindOf(unsigned
 * long)const  */

int __thiscall CSceneVehicleCar::MwIsKindOf(CSceneVehicleCar *this,
                                            ulong param_1)

{
  if ((((param_1 != 0xa02b000) && (param_1 != 0xa060000)) &&
       (param_1 != 0xa011000)) &&
      (param_1 != 0xa005000)) {
    return (uint)(param_1 == 0x1001000);
  }
  return 1;
}

/* public: static class CMwNod * __cdecl
 * CSceneVehicleCar::MwNewCSceneVehicleCar(void) */

CMwNod *__cdecl CSceneVehicleCar::MwNewCSceneVehicleCar(void)

{
  CSceneVehicleCar *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acca7b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CSceneVehicleCar *)operator_new(0x878);
  local_4 = 0;
  if (this != (CSceneVehicleCar *)0x0) {
    pCVar1 = (CMwNod *)CSceneVehicleCar(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* private: void __thiscall CSceneVehicleCar::NewSolidInstance(void) */

void __thiscall CSceneVehicleCar::NewSolidInstance(CSceneVehicleCar *this)

{
  int iVar1;
  CPlugSolid *pCVar2;

  pCVar2 = *(CPlugSolid **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x68);
  if (pCVar2 != (CPlugSolid *)0x0) {
    iVar1 = *(int *)this;
    pCVar2 = CPlugSolid::CreateModelInstance(pCVar2);
    (**(code **)(iVar1 + 0xd8))(pCVar2);
  }
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::OnEnterScene(void) */

void __thiscall CSceneVehicleCar::OnEnterScene(CSceneVehicleCar *this)

{
  float fVar1;
  CHmsCorpus *pCVar2;
  int iVar3;
  CHmsCorpus **ppCVar4;
  int *piVar5;

  CSceneVehicle::OnEnterScene((CSceneVehicle *)this);
  (**(code **)(*(int *)this + 0x130))();
  CHmsItem::PickDisable(*(CHmsItem **)(this + 0x28));
  *(undefined4 *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x44) = 0;
  ppCVar4 = (CHmsCorpus **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
  pCVar2 = *ppCVar4;
  iVar3 = *(int *)(pCVar2 + 0x58);
  if (iVar3 != 0) {
    piVar5 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
        *(ulong *)(*(int *)(this + 100) + 0x24));
    fVar1 = *(float *)(*piVar5 + 0x14c);
    *(float *)(iVar3 + 0xc4) = fVar1;
    *(uint *)(iVar3 + 0xc0) = (uint)(1e-05 < fVar1);
  }
  piVar5 = (int *)CHmsViewport::FindOrCreateViewport((CSystemWindow *)0x0);
  if (piVar5 != (int *)0x0) {
    CHmsViewport::LoadResourceCorpus((CHmsViewport *)piVar5, pCVar2);
    /* WARNING: Could not recover jumptable at 0x007bcf89. Too many branches */
    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar5 + 0xa4))();
    return;
  }
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::OnNodLoaded(void) */

void __thiscall CSceneVehicleCar::OnNodLoaded(CSceneVehicleCar *this)

{
  CSceneVehicle::OnNodLoaded((CSceneVehicle *)this);
  (**(code **)(*(int *)this + 0x130))();
  CSceneVehicle::RetrieveLoadedLinkedSounds((CSceneVehicle *)this);
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::RestoreStaticState(class
   CClassicBufferMemory
   &,int,unsigned long,unsigned long,int) */

void __thiscall CSceneVehicleCar::RestoreStaticState(
    CSceneVehicleCar *this, CClassicBufferMemory *param_1, int param_2,
    ulong param_3, ulong param_4, int param_5)

{
  CFastBuffer<> *pCVar1;
  float fVar2;
  byte bVar3;
  int *piVar4;
  SSimulationWheel *pSVar5;
  SSimulationWheel *pSVar6;
  SSimulationWheel *pSVar7;
  SSimulationWheel *pSVar8;
  int iVar9;
  SState *pSVar10;
  ulong uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int unaff_EBX;
  undefined4 *puVar15;
  ulong uVar16;
  undefined4 unaff_EBP;
  SState *pSVar17;
  undefined4 *puVar18;
  SState *pSVar19;
  undefined4 *puVar20;
  float fVar21;
  float fVar22;
  int unaff_retaddr;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  uint uStack_18;
  CSceneVehicleCar CStack_11;
  CSceneVehicleCar CStack_10;
  byte bStack_c;
  int *piStack_8;
  int *piStack_4;

  piVar4 = (int *)(**(code **)(*(int *)this + 8))();
  bVar3 = (**(code **)(*piVar4 + 4))(param_4, &uStack_2c);
  piVar4 = piStack_4;
  if (unaff_EBX == 0) {
    CHmsItem::RestoreStaticState(*(CHmsItem **)(this + 0x28),
                                 (CClassicBufferMemory *)piStack_4,
                                 unaff_retaddr, (ulong)param_1, (uint)bVar3);
  } else {
    CHmsItem::OldRestoreStaticState(
        *(CHmsItem **)(this + 0x28), (CClassicBufferMemory *)piStack_4,
        unaff_retaddr, (ulong)param_1, bVar3, param_3);
  }
  if (param_4 < 2) {
    (**(code **)(*piVar4 + 4))(&stack0xffffffcb, 1);
    bVar3 = (byte)((uint)unaff_EBP >> 0x18);
  } else {
    bVar3 = (byte)param_4;
  }
  if (bVar3 == 0) {
    return;
  }
  if ((bVar3 == 2) || (bVar3 == 1)) {
    (**(code **)(*piVar4 + 4))(&uStack_2c, 0x16);
    if (unaff_retaddr != 0) {
      pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 3);
      pSVar5 = pSVar5 + 0x16c;
      pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
      pSVar6 = pSVar6 + 0x16c;
      pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
      pSVar7 = pSVar7 + 0x16c;
      pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
      SVehicleSimpleState_ReplayAfter211003::RestoreFromStruct(
          (SVehicleSimpleState_ReplayAfter211003 *)&stack0xffffffcc,
          (SVehicleCarState *)(this + 0x2f8), (SState *)(pSVar8 + 0x16c),
          (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
      piStack_8 = (int *)(*(int *)(this + 0x28) + 0x34);
      piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)piStack_8, 0);
      puVar15 =
          (undefined4 *)(*(int *)(*(int *)(*piVar4 + 0x58) + 0x328) + 0x10);
      puVar18 = (undefined4 *)(this + 0x32c);
      for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar18 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar18 = puVar18 + 1;
      }
      piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)piStack_8, 0);
      iVar9 = *(int *)(*(int *)(*piVar4 + 0x58) + 0x328);
      *(undefined4 *)(this + 0x364) = *(undefined4 *)(iVar9 + 0x40);
      *(undefined4 *)(this + 0x368) = *(undefined4 *)(iVar9 + 0x44);
      *(undefined4 *)(this + 0x36c) = *(undefined4 *)(iVar9 + 0x48);
      if (*(int *)(this + 0x78) != 0) {
        piStack_4 = (int *)CFastBuffer<>::GetCount((CFastBuffer<> *)pCVar1);
        piStack_8 = (int *)0x0;
        if (piStack_4 != (int *)0x0) {
          do {
            pSVar5 = CFastBuffer<>::operator[](pCVar1, (ulong)piStack_8);
            puVar15 = (undefined4 *)(pSVar5 + 400);
            *puVar15 = *(undefined4 *)(pSVar5 + 100);
            *(undefined4 *)(pSVar5 + 0x194) = *(undefined4 *)(pSVar5 + 0x68);
            *(undefined4 *)(pSVar5 + 0x198) = *(undefined4 *)(pSVar5 + 0x6c);
            *(float *)(pSVar5 + 0x194) =
                *(float *)(pSVar5 + 0x194) - *(float *)(pSVar5 + 8);
            GmVec3::Mult(
                (GmVec3 *)puVar15,
                (GmIso4 *)(*(int *)(*(int *)(*(int *)(this + 0x28) + 0x14) +
                                    100) +
                           0x5c));
            GmVec3::SetMult((GmVec3 *)(pSVar5 + 0x184), (GmVec3 *)puVar15,
                            (GmIso4 *)(this + 0x32c));
            piStack_8 = (int *)((int)piStack_8 + 1);
          } while (piStack_8 < piStack_4);
        }
      }
      iVar9 = CSceneVehicle::UpdateEvent((CSceneVehicle *)this, 0,
                                         *(ulong *)(this + 0x35c));
      if (iVar9 != 0) {
        (**(code **)(*(int *)this + 0x164))();
      }
      iVar9 = CSceneVehicle::UpdateEvent((CSceneVehicle *)this, 1,
                                         *(ulong *)(this + 0x360));
      if (iVar9 == 0) {
        return;
      }
      CSceneVehicle::WaterSplash((CSceneVehicle *)this,
                                 (GmVec3 *)(this + 0x364));
      return;
    }
    pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
    pSVar5 = CFastBuffer<>::operator[](pCVar1, 3);
    pSVar5 = pSVar5 + 0x1d0;
    pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
    pSVar6 = pSVar6 + 0x1d0;
    pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
    pSVar7 = pSVar7 + 0x1d0;
    pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
    SVehicleSimpleState_ReplayAfter211003::RestoreFromStruct(
        (SVehicleSimpleState_ReplayAfter211003 *)&stack0xffffffcc,
        (SVehicleCarState *)(this + 0x3a0), (SState *)(pSVar8 + 0x1d0),
        (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
    iVar9 = *(int *)(this + 0x28);
    piVar4 =
        (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
    puVar15 = (undefined4 *)(*(int *)(*(int *)(*piVar4 + 0x58) + 0x32c) + 0x10);
    puVar18 = (undefined4 *)(this + 0x3d4);
    for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar18 = *puVar15;
      puVar15 = puVar15 + 1;
      puVar18 = puVar18 + 1;
    }
    piVar4 =
        (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
    iVar9 = *(int *)(*(int *)(*piVar4 + 0x58) + 0x32c);
  LAB_007cff2c:
    *(undefined4 *)(this + 0x40c) = *(undefined4 *)(iVar9 + 0x40);
    *(undefined4 *)(this + 0x410) = *(undefined4 *)(iVar9 + 0x44);
    *(undefined4 *)(this + 0x414) = *(undefined4 *)(iVar9 + 0x48);
    return;
  }
  if (bVar3 == 4) {
    (**(code **)(*piVar4 + 4))(&uStack_2c, 0x1c);
    pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
    pSVar5 = CFastBuffer<>::operator[](pCVar1, 3);
    if (unaff_retaddr != 0) {
      pSVar5 = pSVar5 + 0x16c;
      pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
      pSVar6 = pSVar6 + 0x16c;
      pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
      pSVar7 = pSVar7 + 0x16c;
      pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
      SVehicleSimpleState_ReplayAfter040104::RestoreFromStruct(
          (SVehicleSimpleState_ReplayAfter040104 *)&stack0xffffffcc,
          (SVehicleCarState *)(this + 0x2f8), (SState *)(pSVar8 + 0x16c),
          (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
      iVar9 = *(int *)(this + 0x28);
      piVar4 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
      puVar15 =
          (undefined4 *)(*(int *)(*(int *)(*piVar4 + 0x58) + 0x328) + 0x10);
      puVar18 = (undefined4 *)(this + 0x32c);
      for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar18 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar18 = puVar18 + 1;
      }
      piVar4 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
      iVar9 = *(int *)(*(int *)(*piVar4 + 0x58) + 0x328);
      *(undefined4 *)(this + 0x364) = *(undefined4 *)(iVar9 + 0x40);
      *(undefined4 *)(this + 0x368) = *(undefined4 *)(iVar9 + 0x44);
      *(undefined4 *)(this + 0x36c) = *(undefined4 *)(iVar9 + 0x48);
      iVar9 = CSceneVehicle::UpdateEvent((CSceneVehicle *)this, 0,
                                         *(ulong *)(this + 0x35c));
      if (iVar9 != 0) {
        (**(code **)(*(int *)this + 0x164))();
      }
      iVar9 = CSceneVehicle::UpdateEvent((CSceneVehicle *)this, 1,
                                         *(ulong *)(this + 0x360));
      if (iVar9 == 0) {
        return;
      }
      CSceneVehicle::WaterSplash((CSceneVehicle *)this,
                                 (GmVec3 *)(this + 0x364));
      return;
    }
    pSVar5 = pSVar5 + 0x1d0;
    pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
    pSVar6 = pSVar6 + 0x1d0;
    pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
    pSVar7 = pSVar7 + 0x1d0;
    pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
    SVehicleSimpleState_ReplayAfter040104::RestoreFromStruct(
        (SVehicleSimpleState_ReplayAfter040104 *)&stack0xffffffcc,
        (SVehicleCarState *)(this + 0x3a0), (SState *)(pSVar8 + 0x1d0),
        (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
    iVar9 = *(int *)(this + 0x28);
    piVar4 =
        (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
    puVar15 = (undefined4 *)(*(int *)(*(int *)(*piVar4 + 0x58) + 0x32c) + 0x10);
    puVar18 = (undefined4 *)(this + 0x3d4);
    for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar18 = *puVar15;
      puVar15 = puVar15 + 1;
      puVar18 = puVar18 + 1;
    }
    piVar4 =
        (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
    iVar9 = *(int *)(*(int *)(*piVar4 + 0x58) + 0x32c);
    goto LAB_007cff2c;
  }
  if ((((bVar3 == 5) || (bVar3 == 7)) || (bVar3 == 8)) || (bVar3 == 9)) {
    if (unaff_retaddr == 0) {
      switch (bVar3 - 5) {
      case 0:
      case 2:
        (**(code **)(*piVar4 + 4))(&uStack_2c, 0x1e);
        pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
        pSVar5 = CFastBuffer<>::operator[](pCVar1, 3);
        pSVar5 = pSVar5 + 0x1d0;
        pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
        pSVar6 = pSVar6 + 0x1d0;
        pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
        pSVar7 = pSVar7 + 0x1d0;
        pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
        SVehicleSimpleState_ReplayAfter040104::RestoreFromStruct(
            (SVehicleSimpleState_ReplayAfter040104 *)&uStack_2c,
            (SVehicleCarState *)(this + 0x3a0), (SState *)(pSVar8 + 0x1d0),
            (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
        break;
      case 3:
        (**(code **)(*piVar4 + 4))(&uStack_2c, 0x22);
        pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
        pSVar5 = CFastBuffer<>::operator[](pCVar1, 3);
        pSVar5 = pSVar5 + 0x1d0;
        pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
        pSVar6 = pSVar6 + 0x1d0;
        pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
        pSVar7 = pSVar7 + 0x1d0;
        pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
        SVehicleSimpleState_ReplayAfter081205::RestoreFromStruct(
            (SVehicleSimpleState_ReplayAfter081205 *)&uStack_2c,
            (SVehicleCarState *)(this + 0x3a0), (SState *)(pSVar8 + 0x1d0),
            (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
        break;
      case 4:
        (**(code **)(*piVar4 + 4))(&uStack_2c, 0x23);
        pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
        pSVar5 = CFastBuffer<>::operator[](pCVar1, 3);
        pSVar5 = pSVar5 + 0x1d0;
        pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
        pSVar6 = pSVar6 + 0x1d0;
        pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
        pSVar7 = pSVar7 + 0x1d0;
        pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
        SVehicleSimpleState_ReplayAfter170806::RestoreFromStruct(
            (SVehicleSimpleState_ReplayAfter170806 *)&uStack_2c,
            (SVehicleCarState *)(this + 0x3a0), (SState *)(pSVar8 + 0x1d0),
            (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
      }
      iVar9 = *(int *)(this + 0x28);
      piVar4 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
      puVar15 =
          (undefined4 *)(*(int *)(*(int *)(*piVar4 + 0x58) + 0x32c) + 0x10);
      puVar18 = (undefined4 *)(this + 0x3d4);
      for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar18 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar18 = puVar18 + 1;
      }
      piVar4 =
          (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
      iVar9 = *(int *)(*(int *)(*piVar4 + 0x58) + 0x32c);
      goto LAB_007cff2c;
    }
    switch (bVar3 - 5) {
    case 0:
    case 2:
      (**(code **)(*piVar4 + 4))(&uStack_2c, 0x1e);
      pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 3);
      pSVar5 = pSVar5 + 0x16c;
      pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
      pSVar6 = pSVar6 + 0x16c;
      pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
      pSVar7 = pSVar7 + 0x16c;
      pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
      SVehicleSimpleState_ReplayAfter040104::RestoreFromStruct(
          (SVehicleSimpleState_ReplayAfter040104 *)&uStack_2c,
          (SVehicleCarState *)(this + 0x2f8), (SState *)(pSVar8 + 0x16c),
          (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
      uVar14 = uStack_18 >> 0x14;
      *(uint *)(this + 0x654) = uStack_18 >> 0x12 & 3;
      *(uint *)(this + 0x1fc) = uStack_18 >> 0x16 & 3;
      this[0x200] = CStack_11;
      this[0x201] = CStack_10;
      goto LAB_007cfadb;
    default:
      goto switchD_007cf931_caseD_1;
    case 3:
      (**(code **)(*piVar4 + 4))(&uStack_2c, 0x22);
      pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 3);
      pSVar5 = pSVar5 + 0x16c;
      pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
      pSVar6 = pSVar6 + 0x16c;
      pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
      pSVar7 = pSVar7 + 0x16c;
      pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
      SVehicleSimpleState_ReplayAfter081205::RestoreFromStruct(
          (SVehicleSimpleState_ReplayAfter081205 *)&uStack_2c,
          (SVehicleCarState *)(this + 0x2f8), (SState *)(pSVar8 + 0x16c),
          (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
      break;
    case 4:
      (**(code **)(*piVar4 + 4))(&uStack_2c, 0x23);
      pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 3);
      pSVar5 = pSVar5 + 0x16c;
      pSVar6 = CFastBuffer<>::operator[](pCVar1, 2);
      pSVar6 = pSVar6 + 0x16c;
      pSVar7 = CFastBuffer<>::operator[](pCVar1, 1);
      pSVar7 = pSVar7 + 0x16c;
      pSVar8 = CFastBuffer<>::operator[](pCVar1, 0);
      SVehicleSimpleState_ReplayAfter170806::RestoreFromStruct(
          (SVehicleSimpleState_ReplayAfter170806 *)&uStack_2c,
          (SVehicleCarState *)(this + 0x2f8), (SState *)(pSVar8 + 0x16c),
          (SState *)pSVar7, (SState *)pSVar6, (SState *)pSVar5);
    }
    *(uint *)(this + 0x1fc) = bStack_c >> 4 & 3;
    *(uint *)(this + 0x654) = bStack_c & 3;
    uVar14 = (uint)(bStack_c >> 2);
    this[0x201] = SUB21((ushort)uStack_1c._1_2_ >> 8, 0);
    this[0x200] = SUB21(uStack_1c._1_2_, 0);
  LAB_007cfadb:
    *(uint *)(this + 0x658) = uVar14 & 3;
  switchD_007cf931_caseD_1:
    iVar9 = *(int *)(this + 0x28);
    piVar4 =
        (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
    puVar15 = (undefined4 *)(*(int *)(*(int *)(*piVar4 + 0x58) + 0x328) + 0x10);
    puVar18 = (undefined4 *)(this + 0x32c);
    for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar18 = *puVar15;
      puVar15 = puVar15 + 1;
      puVar18 = puVar18 + 1;
    }
    piVar4 =
        (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x34), 0);
    iVar9 = *(int *)(*(int *)(*piVar4 + 0x58) + 0x328);
    *(undefined4 *)(this + 0x364) = *(undefined4 *)(iVar9 + 0x40);
    *(undefined4 *)(this + 0x368) = *(undefined4 *)(iVar9 + 0x44);
    *(undefined4 *)(this + 0x36c) = *(undefined4 *)(iVar9 + 0x48);
    iVar9 = CSceneVehicle::UpdateEvent((CSceneVehicle *)this, 0,
                                       *(ulong *)(this + 0x35c));
    if (iVar9 != 0) {
      (**(code **)(*(int *)this + 0x164))();
    }
    iVar9 = CSceneVehicle::UpdateEvent((CSceneVehicle *)this, 1,
                                       *(ulong *)(this + 0x360));
    if (iVar9 == 0)
      goto LAB_007cf906;
  } else {
    if ((bVar3 != 3) && (bVar3 != 6)) {
      return;
    }
    (**(code **)(*piVar4 + 4))(&piStack_4, 2);
    if (unaff_retaddr == 0) {
      pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
      puVar15 = (undefined4 *)(this + 0x3a0);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 0);
      pSVar19 = (SState *)(pSVar5 + 0x1d0);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 1);
      param_2 = (int)(pSVar5 + 0x1d0);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 2);
      pSVar17 = (SState *)(pSVar5 + 0x1d0);
      pSVar5 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), 3);
      pSVar10 = (SState *)(pSVar5 + 0x1d0);
    } else {
      pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
      puVar15 = (undefined4 *)(this + 0x2f8);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 0);
      pSVar19 = (SState *)(pSVar5 + 0x16c);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 1);
      param_2 = (int)(pSVar5 + 0x16c);
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 2);
      pSVar17 = (SState *)(pSVar5 + 0x16c);
      pSVar5 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), 3);
      pSVar10 = (SState *)(pSVar5 + 0x16c);
    }
    fVar2 = *(float *)(this + 0x378);
    SVehicleSimpleNetState::RestoreFromStruct(
        (SVehicleSimpleNetState *)&piStack_4, (SVehicleCarState *)puVar15,
        *(float *)(this + 0x59c), pSVar19, (SState *)param_2, pSVar17, pSVar10);
    piVar4 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
    iVar9 = *(int *)(*piVar4 + 0x58);
    if (unaff_retaddr == 0) {
      iVar12 = *(int *)(iVar9 + 0x32c);
    } else {
      iVar12 = *(int *)(iVar9 + 0x328);
    }
    puVar18 = (undefined4 *)(iVar12 + 0x10);
    puVar20 = puVar15 + 0xd;
    for (iVar13 = 0xc; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar20 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar20 = puVar20 + 1;
    }
    if ((unaff_retaddr == 0) || (*(int *)(this + 0x78) != 0)) {
      iVar9 = *(int *)(iVar9 + 0x32c);
    } else {
      iVar9 = *(int *)(iVar9 + 0x328);
    }
    puVar15[0x1b] = *(undefined4 *)(iVar9 + 0x40);
    puVar15[0x1c] = *(undefined4 *)(iVar9 + 0x44);
    puVar15[0x1d] = *(undefined4 *)(iVar9 + 0x48);
    uStack_24 = puVar15[0x1d];
    uStack_2c = puVar15[0x1b];
    uStack_28 = puVar15[0x1c];
    piVar4 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
    GmVec3::MultTranspose((GmVec3 *)&uStack_2c, (GmMat3 *)(*piVar4 + 0x18));
    *puVar15 = uStack_24;
    puVar15[1] = uStack_2c;
    if (*(int *)(this + 0x78) != 0) {
      fVar22 = *(float *)(this + 0x378) - fVar2;
      fVar21 = GmFunc::Min(
          ABS(fVar22), ((*(float *)(this + 0x59c) - *(float *)(this + 0x378)) /
                        *(float *)(this + 0x59c)) *
                               2000.0 +
                           333.0);
      fVar22 = GmFunc::Sign(fVar22, fVar21);
      *(float *)(this + 0x378) = fVar22 + fVar2;
    }
    puVar15[0x1a] = ((uint)piStack_4 & 0xff) >> 6;
    if (*(int *)(this + 0x78) != 0) {
      uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
      uVar16 = 0;
      if (uVar11 != 0) {
        do {
          pSVar6 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8),
                                             uVar16);
          pSVar5 = pSVar6 + 0x16c;
          if (unaff_retaddr == 0) {
            pSVar5 = pSVar6 + 0x1d0;
          }
          puVar15 = (undefined4 *)(pSVar5 + 0x24);
          *puVar15 = *(undefined4 *)(pSVar6 + 100);
          *(undefined4 *)(pSVar5 + 0x28) = *(undefined4 *)(pSVar6 + 0x68);
          *(undefined4 *)(pSVar5 + 0x2c) = *(undefined4 *)(pSVar6 + 0x6c);
          *(float *)(pSVar5 + 0x28) =
              *(float *)(pSVar5 + 0x28) - *(float *)(pSVar6 + 8);
          GmVec3::Mult(
              (GmVec3 *)puVar15,
              (GmIso4 *)(*(int *)(*(int *)(*(int *)(this + 0x28) + 0x14) +
                                  100) +
                         0x5c));
          GmVec3::SetMult((GmVec3 *)(pSVar5 + 0x18), (GmVec3 *)puVar15,
                          (GmIso4 *)(this + 0x32c));
          uVar16 = uVar16 + 1;
        } while (uVar16 < uVar11);
      }
    }
    if (unaff_retaddr == 0) {
      return;
    }
    iVar9 = CSceneVehicle::UpdateEvent((CSceneVehicle *)this, 0,
                                       *(ulong *)(this + 0x35c));
    if (iVar9 != 0) {
      (**(code **)(*(int *)this + 0x164))();
    }
    iVar9 = CSceneVehicle::UpdateEvent((CSceneVehicle *)this, 1,
                                       *(ulong *)(this + 0x360));
    if (iVar9 == 0)
      goto LAB_007cf906;
    if (((uint)piStack_4 >> 8 & 1) != 0) {
      *(undefined4 *)(this + 0x658) = 2;
      this[0x201] = (CSceneVehicleCar)0x10;
      *(CClassicBufferMemory **)(this + 0x650) = param_1;
      return;
    }
  }
  CSceneVehicle::WaterSplash((CSceneVehicle *)this, (GmVec3 *)(this + 0x364));
LAB_007cf906:
  *(CClassicBufferMemory **)(this + 0x650) = param_1;
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::SaveState(class
   CClassicBufferMemory &,unsigned long &,unsigned long) */

void __thiscall CSceneVehicleCar::SaveState(CSceneVehicleCar *this,
                                            CClassicBufferMemory *param_1,
                                            ulong *param_2, ulong param_3)

{
  CFastBuffer<> *pCVar1;
  CClassicBufferMemory *pCVar2;
  SSimulationWheel *pSVar3;
  SSimulationWheel *pSVar4;
  SSimulationWheel *pSVar5;
  SSimulationWheel *pSVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  SVehicleSimpleState_ReplayAfter170806 local_24[16];
  uint local_14;
  byte local_4;

  pCVar2 = param_1;
  *param_2 = *(ulong *)(*(int *)(this + 0x28) + 0x48);
  if (param_3 != 6) {
    if (param_3 == 9) {
      CHmsItem::SaveState(*(CHmsItem **)(this + 0x28), param_1, 1);
      pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
      pSVar3 = CFastBuffer<>::operator[](pCVar1, 3);
      pSVar3 = pSVar3 + 0x16c;
      pSVar4 = CFastBuffer<>::operator[](pCVar1, 2);
      pSVar4 = pSVar4 + 0x16c;
      pSVar5 = CFastBuffer<>::operator[](pCVar1, 1);
      pSVar5 = pSVar5 + 0x16c;
      pSVar6 = CFastBuffer<>::operator[](pCVar1, 0);
      SVehicleSimpleState_ReplayAfter170806::SaveToStruct(
          local_24, (SVehicleCarState *)(this + 0x2f8),
          (SState *)(pSVar6 + 0x16c), (SState *)pSVar5, (SState *)pSVar4,
          (SState *)pSVar3);
      local_4 =
          (((byte)this[0x668] & 3) * '\x04' | (byte)this[0x660] & 3) * '\x04' |
          (byte)this[0x664] & 3 | local_4 & 0xc0;
      local_14 = (uint)(byte)this[0x66d] << 8 | local_14 & 0xff0000ff |
                 (uint)(byte)this[0x66c] << 0x10;
      (**(code **)(*(int *)pCVar2 + 8))(local_24, 0x23);
    }
    goto LAB_007cf2e5;
  }
  CHmsItem::SaveState(*(CHmsItem **)(this + 0x28), param_1, 0);
  iVar7 = CSceneMobil::IsZombie((CSceneMobil *)this);
  if (iVar7 == 0) {
    if (*(uint *)(this + 0xbc) < *(uint *)(this + 0x360)) {
      *(uint *)(this + 0xbc) = *(uint *)(this + 0x360);
      *(undefined4 *)(this + 0xc4) = 0;
    } else {
      if (((uint)(*(int *)(this + 0x664) + *(int *)(this + 0x660)) < 3) &&
          (*(int *)(this + 0x668) == 0))
        goto LAB_007cf1f4;
      *(undefined4 *)(this + 0xc4) = 1;
    }
    *(int *)(this + 0xc0) = *(int *)(this + 0xc0) + 1;
  }
LAB_007cf1f4:
  pCVar1 = (CFastBuffer<> *)(this + 0x2e8);
  pSVar3 = CFastBuffer<>::operator[](pCVar1, 3);
  iVar7 = *(int *)(pSVar3 + 4);
  pSVar3 = CFastBuffer<>::operator[](pCVar1, 3);
  pSVar3 = pSVar3 + 0x16c;
  pSVar4 = CFastBuffer<>::operator[](pCVar1, 2);
  iVar11 = *(int *)(pSVar4 + 4);
  pSVar4 = CFastBuffer<>::operator[](pCVar1, 2);
  pSVar4 = pSVar4 + 0x16c;
  pSVar5 = CFastBuffer<>::operator[](pCVar1, 1);
  iVar10 = *(int *)(pSVar5 + 4);
  pSVar5 = CFastBuffer<>::operator[](pCVar1, 1);
  pSVar5 = pSVar5 + 0x16c;
  pSVar6 = CFastBuffer<>::operator[](pCVar1, 0);
  iVar9 = *(int *)(pSVar6 + 4);
  pSVar6 = CFastBuffer<>::operator[](pCVar1, 0);
  SVehicleSimpleNetState::SaveToStruct(
      (SVehicleSimpleNetState *)&param_1, (SVehicleCarState *)(this + 0x2f8),
      *(float *)(this + 0x59c), *(ulong *)(this + 0xc0), *(int *)(this + 0xc4),
      (SState *)(pSVar6 + 0x16c), iVar9, (SState *)pSVar5, iVar10,
      (SState *)pSVar4, iVar11, (SState *)pSVar3, iVar7);
  (**(code **)(*(int *)pCVar2 + 8))(&param_1, 2);
  piVar8 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 0x28) + 0x34), 0);
  iVar7 = *(int *)(*(int *)(*piVar8 + 0x58) + 0x328);
  *(undefined4 *)(this + 0x86c) = *(undefined4 *)(iVar7 + 0x34);
  *(undefined4 *)(this + 0x870) = *(undefined4 *)(iVar7 + 0x38);
  *(undefined4 *)(this + 0x874) = *(undefined4 *)(iVar7 + 0x3c);
  GmMat3::Set((GmMat3 *)(this + 0x848), (GmMat3 *)(iVar7 + 0x10));
LAB_007cf2e5:
  *(undefined4 *)(this + 0x664) = 0;
  *(undefined4 *)(this + 0x660) = 0;
  *(undefined4 *)(this + 0x668) = 0;
  this[0x66d] = (CSceneVehicleCar)0x0;
  this[0x66c] = (CSceneVehicleCar)0x0;
  return;
}

/* protected: void __thiscall CSceneVehicleCar::SetVehicleAngularSpeed(class
 * GmVec3 const &) */

void __thiscall CSceneVehicleCar::SetVehicleAngularSpeed(CSceneVehicleCar *this,
                                                         GmVec3 *param_1)

{
  CHmsItem::SetAngularSpeed(*(CHmsItem **)(this + 0x28), param_1);
  return;
}

/* protected: void __thiscall CSceneVehicleCar::SetVehicleLinearSpeed(class
 * GmVec3 const &) */

void __thiscall CSceneVehicleCar::SetVehicleLinearSpeed(CSceneVehicleCar *this,
                                                        GmVec3 *param_1)

{
  CHmsItem::SetLinearSpeed(*(CHmsItem **)(this + 0x28), param_1);
  return;
}

/* public: virtual void __thiscall
 * CSceneVehicleCar::UpdateParamsFromTuning(void) */

void __thiscall CSceneVehicleCar::UpdateParamsFromTuning(CSceneVehicleCar *this)

{
  CFastBuffer<> *this_00;
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  ulong uVar11;
  SSimulationWheel *pSVar12;
  ulong uVar13;
  int *piVar14;
  CGameCamera **ppCVar15;
  GmVector2<> *this_01;
  int *piVar16;
  ulong uVar17;
  undefined4 *this_02;
  CGameCamera *pCVar18;
  float local_5c;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  float local_20;
  undefined4 local_18;
  float local_14;
  float local_10;
  float local_4;

  if (*(int *)(*(int *)(this + 0x28) + 0x14) != 0) {
    uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
    if (uVar11 != 0) {
      uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
      uVar17 = 0;
      if (uVar11 != 0) {
        do {
          pSVar12 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8),
                                              uVar17);
          if ((*(int *)(pSVar12 + 0xc) != 0) &&
              (iVar2 = *(int *)(*(int *)(pSVar12 + 0xc) + 0x8c), iVar2 != 0)) {
            this_00 = (CFastBuffer<> *)(iVar2 + 0x18);
            uVar13 = CFastBuffer<>::GetCount(this_00);
            if (uVar13 == 1) {
              piVar14 = (int *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
                  *(ulong *)(*(int *)(this + 100) + 0x24));
              ppCVar15 = (CGameCamera **)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)&s_DefaultSurfaceMaterials,
                  *(ulong *)(*piVar14 + 0x16c));
              pCVar18 = *ppCVar15;
              this_01 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 0);
              CMwNodRef<>::MwSetNod((CMwNodRef<> *)this_01, pCVar18);
            }
          }
          local_3c = *(float *)(pSVar12 + 0x34);
          local_38 = *(float *)(pSVar12 + 0x38);
          local_34 = *(float *)(pSVar12 + 0x3c);
          fVar1 = *(float *)(pSVar12 + 8);
          local_14 = local_38 - *(float *)(pSVar12 + 8);
          fVar4 = local_3c;
          fVar5 = local_38;
          fVar6 = local_34;
          fVar7 = local_3c;
          fVar8 = local_38;
          fVar9 = local_34;
          fVar10 = local_14;
          if (uVar17 != 0) {
            if (local_5c < fVar1 != (NAN(local_5c) || NAN(fVar1))) {
              local_5c = fVar1;
            }
            if (local_3c < local_48) {
              local_48 = local_3c;
            }
            if (local_38 < local_44) {
              local_44 = local_38;
            }
            if (local_34 < local_40) {
              local_40 = local_34;
            }
            if (local_54 < local_3c != (NAN(local_54) || NAN(local_3c))) {
              local_54 = local_3c;
            }
            if (local_50 < local_38 != (NAN(local_50) || NAN(local_38))) {
              local_50 = local_38;
            }
            fVar1 = local_5c;
            fVar4 = local_54;
            fVar5 = local_50;
            fVar6 = local_4c;
            fVar7 = local_48;
            fVar8 = local_44;
            fVar9 = local_40;
            fVar10 = local_20 + local_14;
            if (local_4c < local_34 != (NAN(local_4c) || NAN(local_34))) {
              fVar6 = local_34;
            }
          }
          local_20 = fVar10;
          local_40 = fVar9;
          local_44 = fVar8;
          local_48 = fVar7;
          local_4c = fVar6;
          local_50 = fVar5;
          local_54 = fVar4;
          local_5c = fVar1;
          uVar17 = uVar17 + 1;
        } while (uVar17 < uVar11);
      }
      uVar11 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
      fVar1 = (float)uVar11;
      if ((int)uVar11 < 0) {
        fVar1 = fVar1 + 4.294967e+09;
      }
      GmBoxAligned::SetMinMax((GmBoxAligned *)&local_18, (GmVec3 *)&local_48,
                              (GmVec3 *)&local_54);
      iVar2 = *(int *)(this + 100);
      local_30 = local_18;
      local_2c = local_14;
      local_28 = local_10;
      *(float *)(this + 0x840) = local_4 + local_4;
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      local_28 = *(float *)(*piVar14 + 0x144) * local_4 + local_10;
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      local_2c = (1.0 / fVar1) * local_20 + *(float *)(*piVar14 + 0x148);
      iVar3 = *(int *)(*(int *)(this + 0x28) + 0x14);
      this_02 = (undefined4 *)(iVar3 + 0x18);
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      *this_02 = *(undefined4 *)(*piVar14 + 0x130);
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      *(undefined4 *)(iVar3 + 0x4c) = *(undefined4 *)(*piVar14 + 0x160);
      *(undefined4 *)(iVar3 + 0x40) = 0;
      *(undefined4 *)(iVar3 + 0x44) = 0;
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      *(undefined4 *)(iVar3 + 0x48) = *(undefined4 *)(*piVar14 + 0x168);
      CPlugPhysicalObject::SetComPos((CPlugPhysicalObject *)this_02,
                                     (GmVec3 *)&local_30);
      iVar2 = *(int *)(this + 100);
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      piVar16 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      CPlugPhysicalObject::SetInertiaMatrixBox((CPlugPhysicalObject *)this_02,
                                               *(float *)(*piVar16 + 0x134),
                                               (GmVec3 *)(*piVar14 + 0x138));
      iVar2 = *(int *)(this + 100);
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      *(undefined4 *)(this + 0x718) = *(undefined4 *)(*piVar14 + 0x7c);
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      *(undefined4 *)(this + 0x71c) = *(undefined4 *)(*piVar14 + 0x88);
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      *(undefined4 *)(this + 0x720) = *(undefined4 *)(*piVar14 + 0x8c);
      piVar14 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar2 + 0x14), *(ulong *)(iVar2 + 0x24));
      *(undefined4 *)(this + 0x59c) = *(undefined4 *)(*piVar14 + 0x2d0);
    }
  }
  return;
}

/* protected: void __thiscall CSceneVehicleCar::UpdateTurbo(unsigned long) */

void __thiscall CSceneVehicleCar::UpdateTurbo(CSceneVehicleCar *this,
                                              ulong param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;

  if (*(int *)(this + 0x600) != 0) {
    if (*(uint *)(this + 0x5fc) < param_1) {
      *(undefined4 *)(this + 0x600) = 0;
    }
    if (*(int *)(this + 0x600) != 0) {
      iVar3 = param_1 - *(int *)(this + 0x5f8);
      fVar1 = (float)iVar3;
      if (iVar3 < 0) {
        fVar1 = fVar1 + 4.294967e+09;
      }
      iVar3 = *(int *)(this + 0x5fc) - *(int *)(this + 0x5f8);
      fVar2 = (float)iVar3;
      if (iVar3 < 0) {
        fVar2 = fVar2 + 4.294967e+09;
      }
      *(float *)(this + 0x5f0) = fVar1 / fVar2;
      return;
    }
  }
  *(undefined4 *)(this + 0x5f0) = 0;
  return;
}

/* public: virtual void __thiscall
 * CSceneVehicleCar::VehicleAsyncWorldSpeedGet(class GmVec3 &) */

void __thiscall CSceneVehicleCar::VehicleAsyncWorldSpeedGet(
    CSceneVehicleCar *this, GmVec3 *param_1)

{
  *(undefined4 *)param_1 = *(undefined4 *)(this + 0x4b4);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(this + 0x4b8);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(this + 0x4bc);
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::VehicleBlockSpeed2Set(int)
 */

void __thiscall CSceneVehicleCar::VehicleBlockSpeed2Set(CSceneVehicleCar *this,
                                                        int param_1)

{
  *(uint *)(this + 0x2f4) =
      *(uint *)(this + 0x2f4) ^
      ((uint)(param_1 != 0) << 5 ^ *(uint *)(this + 0x2f4)) & 0x20;
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::VehicleBlockSpeedSet(int)
 */

void __thiscall CSceneVehicleCar::VehicleBlockSpeedSet(CSceneVehicleCar *this,
                                                       int param_1)

{
  *(uint *)(this + 0x2f4) =
      *(uint *)(this + 0x2f4) ^
      ((uint)(param_1 != 0) << 4 ^ *(uint *)(this + 0x2f4)) & 0x10;
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::VehicleFreeWheelingSet(int)
 */

void __thiscall CSceneVehicleCar::VehicleFreeWheelingSet(CSceneVehicleCar *this,
                                                         int param_1)

{
  *(int *)(this + 0x60c) = param_1;
  return;
}

/* protected: virtual void __thiscall
 * CSceneVehicleCar::VehicleInitFromSolid(void) */

void __thiscall CSceneVehicleCar::VehicleInitFromSolid(CSceneVehicleCar *this)

{
  CFastBuffer<> *this_00;
  CFastBuffer<> *this_01;
  undefined4 uVar1;
  CPlugSolid *pCVar2;
  CPlugTree *this_02;
  int iVar3;
  ulong uVar4;
  undefined4 *puVar5;
  STexStageCat *pSVar6;
  ulong uVar7;
  GmIso4 local_30[36];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  if (*(int *)(this + 0x60) == 0) {
    return;
  }
  pCVar2 = *(CPlugSolid **)(*(int *)(this + 0x28) + 0x14);
  this_00 = (CFastBuffer<> *)(*(int *)(this + 0x60) + 0x14);
  this_01 = (CFastBuffer<> *)(this + 0x2e8);
  uVar4 = CFastBuffer<>::GetCount(this_00);
  CFastBuffer<>::AllocSetCount(this_01, uVar4);
  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_01);
  uVar7 = 0;
  if (uVar4 != 0) {
    do {
      puVar5 = (undefined4 *)CFastBuffer<>::operator[](this_01, uVar7);
      pSVar6 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar7);
      *puVar5 = *(undefined4 *)(pSVar6 + 4);
      puVar5[1] = *(undefined4 *)(pSVar6 + 8);
      CSceneVehicle::SSurfaceHandler::Init((SSurfaceHandler *)(puVar5 + 3),
                                           pCVar2, (SSurfaceId *)pSVar6);
      this_02 = (CPlugTree *)puVar5[3];
      if (this_02 == (CPlugTree *)0x0) {
      LAB_007c33cb:
        puVar5[0x2c] = 0;
        puVar5[0x2b] = 0;
        puVar5[0x2a] = 0;
      } else {
        if ((*(int *)(this_02 + 0x8c) != 0) &&
            (iVar3 = *(int *)(*(int *)(this_02 + 0x8c) + 0x14), iVar3 != 0)) {
          iVar3 = *(int *)(iVar3 + 0x34);
          if (*(char *)(iVar3 + 6) == '\0') {
            uVar1 = *(undefined4 *)(iVar3 + 8);
          } else {
            if (*(char *)(iVar3 + 6) != '\x01')
              goto LAB_007c3399;
            uVar1 = *(undefined4 *)(iVar3 + 0xc);
          }
          puVar5[2] = uVar1;
        }
      LAB_007c3399:
        if (this_02 == (CPlugTree *)0x0)
          goto LAB_007c33cb;
        CPlugTree::GetThisToRootTransfo(this_02, local_30, 1, (CPlugTree *)0x0);
        puVar5[0x2a] = local_c;
        puVar5[0x2b] = local_8;
        puVar5[0x2c] = local_4;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar4);
  }
  (**(code **)(*(int *)this + 0x174))();
  CSceneVehicle::VehicleInitFromSolid((CSceneVehicle *)this);
  return;
}

/* public: virtual void __thiscall CSceneVehicleCar::VehicleReset(void) */

void __thiscall CSceneVehicleCar::VehicleReset(CSceneVehicleCar *this)

{
  ulong uVar1;
  SSimulationWheel *pSVar2;
  int *piVar3;
  int iVar4;
  ulong uVar5;
  CSceneVehicleCar *this_00;

  CSceneVehicle::VehicleReset((CSceneVehicle *)this);
  SVehicleCarState::Reset((SVehicleCarState *)(this + 0x448));
  SVehicleCarState::Reset((SVehicleCarState *)(this + 0x4f0));
  SVehicleCarState::Reset((SVehicleCarState *)(this + 0x2f8));
  SVehicleCarState::Reset((SVehicleCarState *)(this + 0x3a0));
  *(undefined4 *)(this + 0x404) = *(undefined4 *)(this + 0xb0);
  *(undefined4 *)(this + 0x35c) = *(undefined4 *)(this + 0xb0);
  *(undefined4 *)(this + 0x408) = *(undefined4 *)(this + 0xb8);
  *(undefined4 *)(this + 0x360) = *(undefined4 *)(this + 0xb8);
  *(undefined4 *)(this + 0x5e8) = 0;
  *(undefined4 *)(this + 0x5f0) = 0;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(this + 0xb8);
  *(undefined4 *)(this + 0x600) = 0;
  *(undefined4 *)(this + 0x610) = 0;
  *(undefined4 *)(this + 0x5d4) = 0;
  *(undefined4 *)(this + 0x5d8) = 0;
  *(undefined4 *)(this + 0x5dc) = 0;
  *(undefined4 *)(this + 0x614) = 0;
  *(undefined4 *)(this + 0x620) = 0;
  *(undefined4 *)(this + 0x61c) = 0;
  *(undefined4 *)(this + 0x618) = 0;
  *(undefined4 *)(this + 0x5f4) = 0;
  *(undefined4 *)(this + 0x628) = 0;
  *(undefined4 *)(this + 0x638) = 0;
  *(undefined4 *)(this + 0x640) = 0;
  *(undefined4 *)(this + 0x63c) = 0;
  *(undefined4 *)(this + 0x5e0) = 0xffffffff;
  *(undefined4 *)(this + 0x644) = 0;
  *(undefined4 *)(this + 0x648) = 0xffffffff;
  *(undefined4 *)(this + 0x62c) = 0xffffffff;
  *(undefined4 *)(this + 0x630) = 0xffffffff;
  *(undefined4 *)(this + 0x5e4) = 0;
  *(undefined4 *)(this + 0x6a0) = 0;
  *(undefined4 *)(this + 0x6f4) = 0xffffffff;
  *(undefined4 *)(this + 0x6f8) = 0xffffffff;
  GmIso4::SetIdentity((GmIso4 *)(this + 0x6a4));
  *(undefined4 *)(this + 0x704) = 0;
  *(undefined4 *)(this + 0x700) = 0;
  *(undefined4 *)(this + 0x6fc) = 0;
  *(undefined4 *)(this + 0x714) = 0;
  *(undefined4 *)(this + 0x710) = 0;
  *(undefined4 *)(this + 0x70c) = 0;
  *(undefined4 *)(this + 0x624) = 0;
  *(undefined4 *)(this + 0x69c) = 0;
  *(undefined4 *)(this + 0x2e4) = 0;
  *(undefined4 *)(this + 0x744) = 0;
  *(undefined4 *)(this + 0x728) = 0;
  *(undefined4 *)(this + 0x730) = 0;
  *(undefined4 *)(this + 0x724) = 0x3f800000;
  *(undefined4 *)(this + 0x734) = 0;
  *(undefined4 *)(this + 0x738) = 0;
  *(undefined4 *)(this + 500) = 0;
  *(undefined4 *)(this + 0x73c) = 0;
  *(undefined4 *)(this + 0x740) = 0xffffffff;
  *(undefined4 *)(this + 0x654) = 0;
  *(undefined4 *)(this + 0x658) = 0;
  *(undefined4 *)(this + 0x1fc) = 0;
  this[0x201] = (CSceneVehicleCar)0x0;
  this[0x200] = (CSceneVehicleCar)0x0;
  *(undefined4 *)(this + 0x210) = 0;
  *(undefined4 *)(this + 0x660) = 0;
  *(undefined4 *)(this + 0x664) = 0;
  *(undefined4 *)(this + 0x668) = 0;
  *(undefined4 *)(this + 0x670) = 0;
  this[0x66c] = (CSceneVehicleCar)0x0;
  *(undefined4 *)(this + 0x674) = 0;
  this[0x66d] = (CSceneVehicleCar)0x0;
  *(undefined4 *)(this + 0x678) = 0;
  *(undefined4 *)(this + 0x650) = 0;
  *(undefined4 *)(this + 0x65c) = 0;
  *(undefined4 *)(this + 0x820) = 0;
  *(undefined4 *)(this + 0x81c) = 0;
  *(undefined4 *)(this + 0x818) = 0;
  *(undefined4 *)(this + 0x82c) = 0;
  *(undefined4 *)(this + 0x828) = 0;
  *(undefined4 *)(this + 0x824) = 0;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      pSVar2 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar5);
      WheelReset(this, pSVar2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  SEngine::Reset((SEngine *)(this + 0x59c));
  this_00 = this + 0x750;
  iVar4 = 4;
  do {
    SDynaPart::Reset((SDynaPart *)this_00);
    this_00 = (CSceneVehicleCar *)((SDynaPart *)this_00 + 0x30);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = *(int *)(*(int *)(this + 0x28) + 0x14);
  if (iVar4 != 0) {
    piVar3 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
        *(ulong *)(*(int *)(this + 100) + 0x24));
    *(undefined4 *)(iVar4 + 0x4c) = *(undefined4 *)(*piVar3 + 0x160);
    *(undefined4 *)(iVar4 + 0x40) = 0;
  }
  *(undefined4 *)(this + 0x68c) = 0;
  *(undefined4 *)(this + 0x688) = 0;
  *(undefined4 *)(this + 0x684) = 0;
  *(undefined4 *)(this + 0x698) = 0;
  *(undefined4 *)(this + 0x694) = 0;
  *(undefined4 *)(this + 0x690) = 0;
  *(undefined4 *)(this + 0x680) = 0;
  *(undefined4 *)(this + 0x67c) = 0;
  *(undefined4 *)(this + 0x810) = 0;
  *(undefined4 *)(this + 0x834) = 0;
  *(undefined4 *)(this + 0x838) = 0;
  *(undefined4 *)(this + 0x83c) = 0;
  *(undefined4 *)(this + 0x60c) = 0;
  return;
}

/* public: virtual struct CSceneVehicle::SVehicleState const & __thiscall
   CSceneVehicleCar::VehicleStateAsyncGet(void)const  */

SVehicleState *__thiscall CSceneVehicleCar::VehicleStateAsyncGet(
    CSceneVehicleCar *this)

{
  return (SVehicleState *)(this + 0x448);
}

/* public: virtual struct CSceneVehicle::SVehicleState const & __thiscall
   CSceneVehicleCar::VehicleStatePrevAsyncGet(void)const  */

SVehicleState *__thiscall CSceneVehicleCar::VehicleStatePrevAsyncGet(
    CSceneVehicleCar *this)

{
  return (SVehicleState *)(this + 0x4f0);
}

/* protected: virtual void __thiscall CSceneVehicleCar::VehicleUpdateAsync(void)
 */

void __thiscall CSceneVehicleCar::VehicleUpdateAsync(CSceneVehicleCar *this)

{
  ulong *puVar1;
  undefined4 uVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  SSimulationWheel *pSVar7;
  ulong *puVar8;
  int *piVar9;
  float *pfVar10;
  uint *puVar11;
  SSimulationWheel *pSVar12;
  CMwCmdBufferCore *pCVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  float10 *extraout_ECX;
  undefined4 extraout_EDX;
  code *pcVar17;
  ulong uVar18;
  undefined4 *puVar19;
  int *piVar20;
  undefined4 *puVar21;
  int *piVar22;
  float10 fVar23;
  float fVar24;
  float fVar25;
  uint local_b8;
  uint local_b4;
  float local_b0;
  uint local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  ulong local_9c;
  float local_98;
  float local_94;
  float local_90;
  int local_8c;
  float local_88;
  float local_84;
  float local_80;
  int local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60[9];
  float local_3c;
  float local_38;
  float local_34;
  GmIso4 local_30[48];

  if ((CSceneVehicle::s_IsUpdateAsync == 0) || (*(int *)(this + 0x4c) == 0)) {
    return;
  }
  ComputeAsyncState(this);
  iVar5 = CSceneMobil::IsZombie((CSceneMobil *)this);
  uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  uVar18 = 0;
  if (uVar6 != 0) {
    do {
      pSVar7 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), uVar18);
      if (iVar5 != 0) {
        local_94 = -*(float *)(pSVar7 + 0x298);
        puVar19 = (undefined4 *)(pSVar7 + 0x10);
        puVar21 = (undefined4 *)(pSVar7 + 0x40);
        for (iVar16 = 0xc; iVar16 != 0; iVar16 = iVar16 + -1) {
          *puVar21 = *puVar19;
          puVar19 = puVar19 + 1;
          puVar21 = puVar21 + 1;
        }
        local_98 = local_94 * 0.0;
        *(float *)(pSVar7 + 100) = *(float *)(pSVar7 + 100) + local_98;
        *(float *)(pSVar7 + 0x68) = local_94 + *(float *)(pSVar7 + 0x68);
        *(float *)(pSVar7 + 0x6c) = local_98 + *(float *)(pSVar7 + 0x6c);
        local_90 = local_98;
        CSceneVehicle::SSurfaceHandler::UpdateSurface(
            (SSurfaceHandler *)(pSVar7 + 0xc));
      }
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar6);
  }
  if (*(CPlugShaderGeneric **)(this + 0x2d4) != (CPlugShaderGeneric *)0x0) {
    fVar24 = *(float *)(this + 0x468);
    local_a8 = fVar24 * 1.0 + 0.0;
    local_a4 = fVar24 * 1.0 + 0.0;
    local_a0 = fVar24 * 1.0 + 0.0;
    CPlugShaderGeneric::SetEmissive(*(CPlugShaderGeneric **)(this + 0x2d4), 1,
                                    (GmVec3 *)&local_a8, 0);
  }
  iVar5 =
      CSceneVehicle::SVisualHandler::IsInit((SVisualHandler *)(this + 0x104));
  if (iVar5 != 0) {
    fVar24 = *(float *)(this + 0x460);
    if (*(int *)(this + 0x45c) == 0) {
      local_b0 = 0.0;
    } else {
      if (fVar24 < 0.3 == NAN(fVar24)) {
        if (0.7 <= fVar24) {
          if (fVar24 < 1.0 == NAN(fVar24)) {
            local_b0 = 0.0;
          } else {
            fVar23 = (float10)__CIsin(extraout_ECX, extraout_EDX);
            local_b0 = 1.0 - (float)fVar23;
          }
        } else {
          local_b0 = 1.0;
        }
      } else {
        fVar23 = (float10)__CIsin(extraout_ECX, extraout_EDX);
        local_b0 = (float)fVar23;
      }
      pCVar13 =
          *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
      local_b0 = local_b0 * 0.04908739;
      if (pCVar13 == (CMwCmdBufferCore *)0x0) {
        pCVar13 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
      }
      fVar24 = CMwTimerAdapter::GetRelativeSpeed((CMwTimerAdapter *)pCVar13);
      if (ABS(fVar24) < 1e-05 == NAN(ABS(fVar24))) {
        local_b0 = GmFunc::RandReal(local_b0 - 0.005, local_b0 + 0.005);
      }
    }
    GmIso4::SetIdentity(local_30);
    GmMat3::RotateX((GmMat3 *)local_30, -local_b0);
    GmIso4::SetMult((GmIso4 *)(this + 0x13c), local_30,
                    (GmIso4 *)(this + 0x10c));
    CSceneVehicle::SVisualHandler::UpdateVisual(
        (SVisualHandler *)(this + 0x104));
  }
  local_9c = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0xe0));
  local_ac = 0;
  if (local_9c != 0) {
    do {
      puVar8 = (ulong *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0xe0), local_ac);
      pSVar7 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), *puVar8);
      iVar5 =
          CSceneVehicle::SVisualHandler::IsInit((SVisualHandler *)(puVar8 + 2));
      if (iVar5 != 0) {
        puVar1 = puVar8 + 0x10;
        GmIso4::SetIdentity((GmIso4 *)puVar1);
        GmMat3::RotateX((GmMat3 *)puVar1, *(float *)(pSVar7 + 0x29c));
        if (puVar8[1] != 0) {
          GmMat3::Mult((GmMat3 *)puVar1, (GmMat3 *)(pSVar7 + 0x2c8));
        }
        if (puVar8[0x1c] == 0) {
          GmIso4::Mult((GmIso4 *)puVar1, (GmIso4 *)(puVar8 + 4));
          puVar8[0x1a] =
              (ulong)((*(float *)(pSVar7 + 0x68) - *(float *)(pSVar7 + 0x38)) +
                      (float)puVar8[0x1a]);
        }
      }
      iVar5 = CSceneVehicle::SVisualHandler::IsInit(
          (SVisualHandler *)(puVar8 + 0x1d));
      if (iVar5 != 0) {
        GmIso4::SetIdentity((GmIso4 *)(puVar8 + 0x2b));
        if (puVar8[0x37] == 0) {
          GmIso4::Mult((GmIso4 *)(puVar8 + 0x2b), (GmIso4 *)(puVar8 + 0x1f));
          puVar8[0x35] =
              (ulong)((*(float *)(pSVar7 + 0x68) - *(float *)(pSVar7 + 0x38)) +
                      (float)puVar8[0x35]);
        }
      }
      iVar5 = CSceneVehicle::SVisualHandler::IsInit(
          (SVisualHandler *)(puVar8 + 0x53));
      if (iVar5 != 0) {
        puVar1 = puVar8 + 0x61;
        GmIso4::SetIdentity((GmIso4 *)puVar1);
        if (puVar8[1] != 0) {
          GmMat3::Mult((GmMat3 *)puVar1, (GmMat3 *)(pSVar7 + 0x2c8));
        }
        GmIso4::Mult((GmIso4 *)puVar1, (GmIso4 *)(puVar8 + 0x55));
        puVar8[0x6b] =
            (ulong)((*(float *)(pSVar7 + 0x68) - *(float *)(pSVar7 + 0x38)) +
                    (float)puVar8[0x6b]);
      }
      CSceneVehicle::SVisualHandler::UpdateVisual(
          (SVisualHandler *)(puVar8 + 2));
      CSceneVehicle::SVisualHandler::UpdateVisual(
          (SVisualHandler *)(puVar8 + 0x1d));
      CSceneVehicle::SVisualHandler::UpdateVisual(
          (SVisualHandler *)(puVar8 + 0x53));
      local_ac = local_ac + 1;
    } while (local_ac < local_9c);
  }
  CSceneVehicle::VisualUpdateAsync((CSceneVehicle *)this);
  uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0xd4));
  local_ac = 0;
  if (uVar6 != 0) {
    do {
      piVar9 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0xd4),
                                                local_ac);
      if (*piVar9 != 0) {
        iVar5 = piVar9[0x1f];
        iVar16 = piVar9[0x3a];
        local_78 = *(float *)(iVar5 + 100) * (float)piVar9[0x57] +
                   (float)piVar9[0x55] * *(float *)(iVar5 + 0x5c) +
                   *(float *)(iVar5 + 0x60) * (float)piVar9[0x56] +
                   *(float *)(iVar5 + 0x80);
        local_74 = *(float *)(iVar5 + 0x70) * (float)piVar9[0x57] +
                   *(float *)(iVar5 + 0x6c) * (float)piVar9[0x56] +
                   *(float *)(iVar5 + 0x68) * (float)piVar9[0x55] +
                   *(float *)(iVar5 + 0x84);
        local_70 = *(float *)(iVar5 + 0x7c) * (float)piVar9[0x57] +
                   *(float *)(iVar5 + 0x78) * (float)piVar9[0x56] +
                   *(float *)(iVar5 + 0x74) * (float)piVar9[0x55] +
                   *(float *)(iVar5 + 0x88);
        local_88 = *(float *)(iVar16 + 100) * (float)piVar9[0x5a] +
                   *(float *)(iVar16 + 0x5c) * (float)piVar9[0x58] +
                   *(float *)(iVar16 + 0x60) * (float)piVar9[0x59] +
                   *(float *)(iVar16 + 0x80);
        local_84 = *(float *)(iVar16 + 0x70) * (float)piVar9[0x5a] +
                   *(float *)(iVar16 + 0x68) * (float)piVar9[0x58] +
                   *(float *)(iVar16 + 0x6c) * (float)piVar9[0x59] +
                   *(float *)(iVar16 + 0x84);
        local_80 = *(float *)(iVar16 + 0x7c) * (float)piVar9[0x5a] +
                   *(float *)(iVar16 + 0x74) * (float)piVar9[0x58] +
                   *(float *)(iVar16 + 0x78) * (float)piVar9[0x59] +
                   *(float *)(iVar16 + 0x88);
        local_a8 = local_88 - local_78;
        local_a4 = local_84 - local_74;
        local_a0 = local_80 - local_70;
        fVar23 = (float10)__CIsqrt();
        fVar24 = (float)fVar23;
        if (fVar24 < 1e-05 == NAN(fVar24)) {
          fVar3 = 1.0 / fVar24;
          local_a8 = fVar3 * local_a8;
          local_a4 = local_a4 * fVar3;
          local_a0 = fVar3 * local_a0;
          local_3c = local_78;
          local_38 = local_74;
          local_34 = local_70;
          local_6c = 0;
          local_68 = 0x3f800000;
          local_64 = 0;
          GmMat3::SetDOVandUpV((GmMat3 *)local_60, (GmVec3 *)&local_a8,
                               (GmVec3 *)&local_6c);
          if (piVar9[1] != 0) {
            GmMat3::GetLine((GmMat3 *)local_60, 2, (GmVec3 *)&local_98);
            fVar24 = fVar24 / (float)piVar9[0x5b];
            local_98 = fVar24 * local_98;
            local_94 = local_94 * fVar24;
            local_90 = fVar24 * local_90;
            GmMat3::SetLine((GmMat3 *)local_60, 2, (GmVec3 *)&local_98);
          }
          if (piVar9[2] != 0) {
            uVar14 = piVar9[3];
            uVar18 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
            if (uVar14 < uVar18) {
              pSVar7 = CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar14);
              GmIso4::SetIdentity(local_30);
              GmMat3::RotateZ((GmMat3 *)local_30, *(float *)(pSVar7 + 0x29c));
              GmMat3::Mult((GmMat3 *)local_30, (GmMat3 *)(pSVar7 + 0x2c8));
              GmIso4::LeftMult((GmIso4 *)local_60, local_30);
            }
          }
          piVar20 = local_60;
          piVar22 = piVar9 + 0x12;
          for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar22 = *piVar20;
            piVar20 = piVar20 + 1;
            piVar22 = piVar22 + 1;
          }
          CSceneVehicle::SVisualHandler::UpdateVisual(
              (SVisualHandler *)(piVar9 + 4));
        }
      }
      local_ac = local_ac + 1;
    } while (local_ac < uVar6);
  }
  if (*(int *)(this + 0x7c) != 0)
    goto LAB_007c27e7;
  iVar5 = CSceneMobil::IsZombie((CSceneMobil *)this);
  pfVar10 = (float *)(this + 0x448);
  if (iVar5 == 0) {
    pfVar10 = (float *)(this + 0x2f8);
  }
  pCVar13 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
  if (pCVar13 == (CMwCmdBufferCore *)0x0) {
    pCVar13 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
  }
  puVar11 = (uint *)CPlugAudio::MwGetId((CPlugAudio *)pCVar13);
  if ((*(int *)(*(int *)(this + 0x28) + 0x4c) == -1) ||
      (bVar4 = true,
       *puVar11 <= *(int *)(*(int *)(this + 0x28) + 0x4c) + 500U)) {
    bVar4 = false;
  }
  local_b8 = (uint)(byte)this[0x201];
  uVar18 = 0;
  local_9c = 0;
  local_7c = 0;
  local_b0 = 0.0;
  local_8c = 0;
  uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  local_b4 = local_b8;
  if (uVar6 != 0) {
    do {
      pSVar12 = CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x2e8), uVar18);
      pSVar7 = pSVar12 + 0x16c;
      if (iVar5 == 0) {
        pSVar7 = pSVar12 + 0x298;
      }
      if (*(int *)(pSVar7 + 0x10) != 0) {
        if (*(int *)(pSVar12 + 4) == 0) {
          local_7c = local_7c + 1;
          local_b8 = (uint) * (ushort *)(pSVar7 + 0xc);
        } else {
          local_8c = local_8c + 1;
          local_b4 = (uint) * (ushort *)(pSVar7 + 0xc);
        }
        if ((*(int *)(pSVar7 + 0x14) != 0) || (*(int *)(this + 0x6a0) != 0)) {
          if (*(int *)(pSVar12 + 4) == 0) {
            local_9c = local_9c + 1;
          } else {
            local_b0 = (float)((int)local_b0 + 1);
          }
        }
      }
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar6);
  }
  if ((*(int *)(this + 0x270) != 0) &&
      (iVar5 = *(int *)(*(int *)(this + 0x270) + 0x30), iVar5 != 0)) {
    if (local_8c == 0) {
      *(undefined4 *)(iVar5 + 0x78) = 0;
      *(undefined4 *)(*(int *)(*(int *)(this + 0x270) + 0x30) + 0x90) = 0;
    } else {
      *(float *)(iVar5 + 0x78) = ABS(*pfVar10 * 3.6);
      fVar24 = (float)(int)local_b0;
      if ((int)local_b0 < 0) {
        fVar24 = fVar24 + 4.294967e+09;
      }
      fVar3 = (float)uVar6;
      if ((int)uVar6 < 0) {
        fVar3 = fVar3 + 4.294967e+09;
      }
      *(float *)(*(int *)(*(int *)(this + 0x270) + 0x30) + 0x90) =
          fVar24 / fVar3;
    }
    *(uint *)(*(int *)(*(int *)(this + 0x270) + 0x30) + 0x88) = local_b4;
  }
  if ((*(int *)(this + 0x264) != 0) &&
      (iVar5 = *(int *)(*(int *)(this + 0x264) + 0x30), iVar5 != 0)) {
    if (local_7c == 0) {
      if (local_b8 == 0xd) {
        *(undefined4 *)(iVar5 + 0x78) = *(undefined4 *)(this + 500);
        *(undefined4 *)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x90) = 0;
      } else {
        *(undefined4 *)(iVar5 + 0x78) = 0;
        *(undefined4 *)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x90) = 0;
      }
    } else {
      *(float *)(iVar5 + 0x78) = ABS(*pfVar10 * 3.6);
      fVar24 = (float)((int)local_b0 + local_9c);
      if ((int)((int)local_b0 + local_9c) < 0) {
        fVar24 = fVar24 + 4.294967e+09;
      }
      fVar3 = (float)uVar6;
      if ((int)uVar6 < 0) {
        fVar3 = fVar3 + 4.294967e+09;
      }
      *(float *)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x90) =
          fVar24 / fVar3;
    }
    *(uint *)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x88) = local_b8;
  }
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28), (GmVec3 *)&local_88);
  if ((*(int *)(this + 0x268) != 0) &&
      (iVar5 = *(int *)(*(int *)(this + 0x268) + 0x30), iVar5 != 0)) {
    if ((*(int *)(this + 0x5c4) == 0) || (*(int *)(this + 0x5c8) != 0)) {
      fVar24 = 1.0;
    } else {
      fVar24 = -1.0;
    }
    if ((*(int *)(this + 0x60c) != 0) || (bVar4)) {
      fVar24 = 0.0;
    } else {
      fVar24 = pfVar10[0x20] * fVar24;
    }
    if (*(int *)(this + 0x78) == 0) {
      *(float *)(iVar5 + 0x78) = fVar24;
    } else {
      pCVar13 =
          *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
      if (pCVar13 == (CMwCmdBufferCore *)0x0) {
        pCVar13 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
      }
      fVar25 = CMwTimerAdapter::GetAsyncPeriod((CMwTimerAdapter *)pCVar13);
      fVar24 = fVar24 - *(float *)(iVar5 + 0x78);
      fVar3 = ABS(fVar24);
      if (fVar25 * 10000.0 <= fVar3) {
        fVar3 = fVar25 * 10000.0;
      }
      if (0.0 < fVar24 == (fVar24 == 0.0)) {
        fVar3 = -fVar3;
      }
      *(float *)(iVar5 + 0x78) = fVar3 + *(float *)(iVar5 + 0x78);
    }
    uVar2 = 0;
    if (*(int *)(this + 0x60c) == 0) {
      if (0.0 < local_80 == (local_80 == 0.0)) {
        uVar2 = *(undefined4 *)(this + 0x54);
      } else {
        uVar2 = *(undefined4 *)(this + 0x50);
      }
    }
    *(undefined4 *)(iVar5 + 0x7c) = uVar2;
    if (*(int *)(this + 0x5e4) == 0) {
      uVar2 = 0xbf800000;
    } else {
      uVar2 = 0x3f800000;
    }
    *(undefined4 *)(iVar5 + 0x80) = uVar2;
  }
  if ((*(int *)(this + 0x288) != 0) &&
      (iVar5 = *(int *)(*(int *)(this + 0x288) + 0x30), iVar5 != 0)) {
    fVar23 = (float10)__CIsqrt();
    *(float *)(iVar5 + 0x78) = (float)fVar23 * 3.6;
    uVar2 = 0;
    if (*(int *)(this + 0x60c) == 0) {
      if (0.0 < local_80 == (local_80 == 0.0)) {
        uVar2 = *(undefined4 *)(this + 0x54);
      } else {
        uVar2 = *(undefined4 *)(this + 0x50);
      }
    }
    *(undefined4 *)(*(int *)(*(int *)(this + 0x288) + 0x30) + 0x7c) = uVar2;
  }
  if (((((*(int *)(this + 0x60c) != 0) ||
         (*(CSceneSoundSource **)(this + 0x284) == (CSceneSoundSource *)0x0)) ||
        (*(int *)(this + 0x2e4) != 2)) ||
       ((*(int *)(this + 0x744) != 0 || (*(float *)(this + 0x50) <= 0.9)))) ||
      (*(int *)(this + 0x5e4) != 0)) {
    *(undefined4 *)(this + 0x83c) = 0;
  } else {
    if (*(int *)(this + 0x83c) == 0) {
      CSceneSoundSource::Play(*(CSceneSoundSource **)(this + 0x284));
    }
    *(undefined4 *)(this + 0x83c) = 1;
  }
  if ((*(float *)(this + 0x54) <= 0.9) || (*(int *)(this + 0x5e4) != 0)) {
    *(undefined4 *)(this + 0x838) = 0;
  } else {
    if ((*(CSceneSoundSource **)(this + 0x280) != (CSceneSoundSource *)0x0) &&
        (*(int *)(this + 0x838) == 0)) {
      CSceneSoundSource::Play(*(CSceneSoundSource **)(this + 0x280));
    }
    *(undefined4 *)(this + 0x838) = 1;
  }
  if (((*(int *)(this + 0x5c4) != 0) || (*(float *)(this + 0x54) <= 0.9)) ||
      (*(int *)(this + 0x5e4) != 0)) {
    if (*(int **)(this + 0x274) != (int *)0x0) {
      pcVar17 = *(code **)(**(int **)(this + 0x274) + 0xb4);
      goto LAB_007c26b6;
    }
  } else if (*(int **)(this + 0x274) != (int *)0x0) {
    pcVar17 = *(code **)(**(int **)(this + 0x274) + 0xb0);
  LAB_007c26b6:
    (*pcVar17)();
  }
  if (((*(int *)(this + 0x27c) != 0) &&
       (iVar5 = *(int *)(this + 0x5c8), *(int *)(this + 0x834) != iVar5)) &&
      (*(int *)(this + 0x5e4) == 0)) {
    *(int *)(this + 0x834) = iVar5;
    *(undefined4 *)(*(int *)(*(int *)(this + 0x27c) + 0x30) + 0x84) =
        *(undefined4 *)(&DAT_00b9f1c8 + iVar5 * 4);
    CSceneSoundSource::Play(*(CSceneSoundSource **)(this + 0x27c));
  }
  if (*(int *)(this + 0x65c) != *(int *)(this + 0x650)) {
    *(int *)(this + 0x65c) = *(int *)(this + 0x650);
    if (((*(int *)(this + 0x264) != 0) &&
         (iVar5 = *(int *)(*(int *)(this + 0x264) + 0x30), iVar5 != 0)) &&
        ((*(int *)(this + 0x5e4) == 0 ||
          (this[0x201] == (CSceneVehicleCar)0xd)))) {
      uVar14 = *(uint *)(this + 0x658);
      if (*(uint *)(this + 0x658) <= *(uint *)(iVar5 + 0x8c)) {
        uVar14 = *(uint *)(iVar5 + 0x8c);
      }
      *(uint *)(iVar5 + 0x8c) = uVar14;
    }
    if (((*(int *)(this + 0x270) != 0) &&
         (iVar5 = *(int *)(*(int *)(this + 0x270) + 0x30), iVar5 != 0)) &&
        ((*(int *)(this + 0x5e4) == 0 ||
          (this[0x201] == (CSceneVehicleCar)0xd)))) {
      uVar14 = *(uint *)(this + 0x654);
      if (*(uint *)(this + 0x654) <= *(uint *)(iVar5 + 0x8c)) {
        uVar14 = *(uint *)(iVar5 + 0x8c);
      }
      *(uint *)(iVar5 + 0x8c) = uVar14;
    }
    if (((*(int *)(this + 0x278) != 0) &&
         (iVar5 = *(int *)(*(int *)(this + 0x278) + 0x30), iVar5 != 0)) &&
        ((*(int *)(this + 0x5e4) == 0 ||
          (this[0x200] == (CSceneVehicleCar)0xd)))) {
      *(uint *)(iVar5 + 0x88) = (uint)(byte)this[0x200];
      uVar14 = *(uint *)(*(int *)(*(int *)(this + 0x278) + 0x30) + 0x8c);
      uVar15 = *(uint *)(this + 0x1fc);
      if (*(uint *)(this + 0x1fc) <= uVar14) {
        uVar15 = uVar14;
      }
      *(uint *)(*(int *)(*(int *)(this + 0x278) + 0x30) + 0x8c) = uVar15;
    }
    *(undefined4 *)(this + 0x658) = 0;
    *(undefined4 *)(this + 0x654) = 0;
    *(undefined4 *)(this + 0x1fc) = 0;
  }
LAB_007c27e7:
  CSceneVehicle::VehicleUpdateAsync((CSceneVehicle *)this);
  return;
}

/* public: virtual unsigned long __thiscall
 *CSceneVehicleCar::VirtualParam_Get(class CMwStack ,class CMwValueStd *) */

ulong __thiscall CSceneVehicleCar::VirtualParam_Get(CSceneVehicleCar *this,
                                                    CMwStack *param_1,
                                                    CMwValueStd *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  float10 fVar5;
  float fVar6;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0xa02b009) {
    if (uVar3 == 0xa02b008) {
      *(CSceneVehicleCar **)param_2 = this + 0x5a4;
      return 0;
    }
    switch (uVar3) {
    case 0xa02b001:
      *(CSceneVehicleCar **)param_2 = this + 0x5c8;
      return 0;
    case 0xa02b002:
      *(CSceneVehicleCar **)param_2 = this + 0x5c4;
      return 0;
    case 0xa02b003:
      if (0.0 < *(float *)(this + 0x5c0) == NAN(*(float *)(this + 0x5c0))) {
        *(CMwValueStd **)param_2 = param_2 + 4;
        *(undefined4 *)(param_2 + 4) = 0;
        return 0;
      }
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(undefined4 *)(param_2 + 4) = 1;
      return 0;
    case 0xa02b004:
      *(CSceneVehicleCar **)param_2 = this + 0x5b4;
      return 0;
    case 0xa02b005:
      *(CSceneVehicleCar **)param_2 = this + 0x59c;
      return 0;
    case 0xa02b006:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x5cc) * 3.6;
      return 0;
    case 0xa02b007:
      *(CSceneVehicleCar **)param_2 = this + 0x5a0;
      return 0;
    }
  } else {
    if (0xa02b00c < uVar3) {
      if (uVar3 == 0xa02b012) {
        *(ulong **)param_2 = &s_TurboRoulettePeriodMs;
      } else if (uVar3 != 0xffffffff)
        goto switchD_007bfa9c_caseD_7;
      return 0;
    }
    if (uVar3 == 0xa02b00c) {
      fVar5 = (float10)(**(code **)(*(int *)this + 0x134))();
      param_1 = (CMwStack *)(float)fVar5;
      if ((float)param_1 < 2.0) {
        param_1 = (CMwStack *)0x0;
      }
      *(CMwValueStd **)param_2 = param_2 + 4;
      fVar6 = GetMaxSpeed(this);
      *(float *)(param_2 + 4) = (float)param_1 / fVar6;
      return 0;
    }
    if (uVar3 == 0xa02b009) {
      *(CSceneVehicleCar **)param_2 = this + 0x5a8;
      return 0;
    }
    if (uVar3 == 0xa02b00a) {
      *(CSceneVehicleCar **)param_2 = this + 0x5ac;
      return 0;
    }
    if (uVar3 == 0xa02b00b) {
      fVar5 = (float10)(**(code **)(*(int *)this + 0x134))();
      param_1 = (CMwStack *)(float)fVar5;
      if ((float)param_1 < 2.0) {
        param_1 = (CMwStack *)0x0;
      }
      *(CMwStack **)(param_2 + 4) = param_1;
      *(CMwValueStd **)param_2 = param_2 + 4;
      return 0;
    }
  }
switchD_007bfa9c_caseD_7:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 =
      CSceneVehicle::VirtualParam_Get((CSceneVehicle *)this, param_1, param_2);
  return uVar4;
}

/* public: virtual unsigned long __thiscall
 *CSceneVehicleCar::VirtualParam_Set(class CMwStack *,void
 *) */

ulong __thiscall CSceneVehicleCar::VirtualParam_Set(CSceneVehicleCar *this,
                                                    CMwStack *param_1,
                                                    void *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (0xa02b009 < uVar3) {
    if (uVar3 == 0xa02b00a) {
      /* WARNING: Load size is inaccurate */
      *(undefined4 *)(this + 0x5ac) = *param_2;
    } else {
      if (uVar3 == 0xa02b012) {
        /* WARNING: Load size is inaccurate */
        s_TurboRoulettePeriodMs = *param_2;
        return 0;
      }
      if (uVar3 != 0xffffffff)
        goto switchD_007bcdc1_caseD_4;
    }
    return 0;
  }
  if (uVar3 == 0xa02b009) {
    /* WARNING: Load size is inaccurate */
    *(undefined4 *)(this + 0x5a8) = *param_2;
    return 0;
  }
  switch (uVar3) {
  case 0xa02b005:
    /* WARNING: Load size is inaccurate */
    *(undefined4 *)(this + 0x59c) = *param_2;
    return 0;
  case 0xa02b006:
    /* WARNING: Load size is inaccurate */
    *(float *)(this + 0x5cc) = *param_2 / 3.6;
    return 0;
  case 0xa02b007:
    /* WARNING: Load size is inaccurate */
    *(undefined4 *)(this + 0x5a0) = *param_2;
    return 0;
  case 0xa02b008:
    /* WARNING: Load size is inaccurate */
    *(undefined4 *)(this + 0x5a4) = *param_2;
    return 0;
  }
switchD_007bcdc1_caseD_4:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 =
      CSceneVehicle::VirtualParam_Set((CSceneVehicle *)this, param_1, param_2);
  return uVar4;
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

/* public: virtual class GmVec3 const & __thiscall
   CSceneVehicleCar::WheelGetAsyncGroundContactPos(unsigned long)const  */

GmVec3 *__thiscall CSceneVehicleCar::WheelGetAsyncGroundContactPos(
    CSceneVehicleCar *this, ulong param_1)

{
  SSimulationWheel *pSVar1;

  pSVar1 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), param_1);
  return (GmVec3 *)(pSVar1 + 700);
}

/* public: virtual unsigned short __thiscall
   CSceneVehicleCar::WheelGetContactMaterial(unsigned long)const  */

ushort __thiscall CSceneVehicleCar::WheelGetContactMaterial(
    CSceneVehicleCar *this, ulong param_1)

{
  SSimulationWheel *pSVar1;

  pSVar1 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), param_1);
  if (*(int *)(pSVar1 + 0x2a8) != 0) {
    return *(ushort *)(pSVar1 + 0x2a4);
  }
  return 0xffff;
}

/* public: virtual unsigned long __thiscall
 * CSceneVehicleCar::WheelGetCount(void)const  */

ulong __thiscall CSceneVehicleCar::WheelGetCount(CSceneVehicleCar *this)

{
  ulong uVar1;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2e8));
  return uVar1;
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

/* public: virtual int __thiscall CSceneVehicleCar::WheelIsSliding(unsigned
 * long)const  */

int __thiscall CSceneVehicleCar::WheelIsSliding(CSceneVehicleCar *this,
                                                ulong param_1)

{
  SSimulationWheel *pSVar1;

  pSVar1 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x2e8), param_1);
  if ((*(int *)(pSVar1 + 0x2ac) != 0) && (*(int *)(pSVar1 + 0x2a8) != 0)) {
    return 1;
  }
  return 0;
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

/* public: virtual __thiscall CSceneVehicleCar::~CSceneVehicleCar(void) */

void __thiscall CSceneVehicleCar::~CSceneVehicleCar(CSceneVehicleCar *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00acc93e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 2;
  CSceneVehicle::TuningsSet((CSceneVehicle *)this, (CSceneVehicleTunings *)0x0);
  local_4._0_1_ = 1;
  `eh_vector_destructor_iterator'(this + 0x750,0x30,4,SPlugGpuLoadFx::~SPlugGpuLoadFx); local_4 = (
      uint)local_4._1_3_
      << 8;
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x2e8));
  local_4 = 0xffffffff;
  CSceneVehicle::~CSceneVehicle((CSceneVehicle *)this);
  ExceptionList = local_c;
  return;
}

// *************
// SDynaPart
// *************

/* public: void __thiscall CSceneVehicleCar::SDynaPart::Reset(void) */

void __thiscall CSceneVehicleCar::SDynaPart::Reset(SDynaPart *this)

{
  GmSpring<float>::ClearVals((GmSpring<float> *)(this + 0x1c));
  return;
}

/* public: __thiscall CSceneVehicleCar::SDynaPart::SDynaPart(void) */

SDynaPart *__thiscall CSceneVehicleCar::SDynaPart::SDynaPart(SDynaPart *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acc968;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwId::CMwId((CMwId *)this);
  local_4 = 0;
  GmSpring<float>::GmSpring<float>((GmSpring<float> *)(this + 0x1c));
  *(undefined4 *)(this + 0x1c) = 0x42f00000;
  *(undefined **)(this + 0x20) = &DAT_40400000;
  ExceptionList = local_c;
  return this;
}

// *************
// SEngine
// *************

/* public: void __thiscall CSceneVehicleCar::SEngine::Reset(void) */

void __thiscall CSceneVehicleCar::SEngine::Reset(SEngine *this)

{
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x2c) = 1;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x20) = 0x3f800000;
  return;
}

/* public: __thiscall CSceneVehicleCar::SEngine::SEngine(void) */

undefined4 __thiscall CSceneVehicleCar::SEngine::SEngine(SEngine *this)

{
  undefined4 extraout_ECX;

  *(undefined4 *)this = 0x462be000;
  *(undefined4 *)(this + 4) = 0x3f800000;
  *(undefined4 *)(this + 8) = 0x3f800000;
  *(undefined4 *)(this + 0xc) = 0x3f800000;
  *(undefined4 *)(this + 0x10) = 0;
  Reset(this);
  return extraout_ECX;
}

// *******************
// SSimulationWheel
// *******************

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
