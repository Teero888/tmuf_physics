
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
