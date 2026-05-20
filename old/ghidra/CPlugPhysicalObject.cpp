
/* public: void __thiscall CPlugPhysicalObject::ComputeComPos(int) */

void __thiscall CPlugPhysicalObject::ComputeComPos(CPlugPhysicalObject *this,
                                                   int param_1)

{
  CPlugTree *this_00;
  CPlugSurfaceGeom *this_01;
  CPlugTree *this_02;
  ulong uVar1;
  CMwClassInfo *unaff_EBP;
  float fVar2;
  float local_58;
  int local_54;
  ulong local_50;
  CPlugPhysicalObject *local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  GmIso4 local_30[36];
  float local_c;
  float local_8;
  float local_4;

  this_00 = *(CPlugTree **)(this + 0x44);
  if (this_00 != (CPlugTree *)0x0) {
    local_40 = 0.0;
    local_54 = 0;
    local_44 = 0.0;
    local_48 = 0.0;
    local_58 = 0.0;
    local_4c = this;
    local_50 = __InitClassInfo_CFuncShader(unaff_EBP);
    if (local_50 != 0xffffffff) {
      do {
        this_02 = CPlugTree::GetAllTreeNext(this_00, &local_50);
        if ((*(int *)(this_02 + 0x8c) != 0) &&
            (((byte)this_02[0x9c] & 0x80) != 0)) {
          this_01 = *(CPlugSurfaceGeom **)(*(int *)(this_02 + 0x8c) + 0x14);
          uVar1 = CPlugSurfaceGeom::GetWeightDistribCount(this_01);
          if (uVar1 != 0) {
            CPlugTree::GetThisToRootTransfo(this_02, local_30, 1,
                                            (CPlugTree *)0x0);
            fVar2 = CPlugSurfaceGeom::GetVolume(this_01);
            local_3c = local_c;
            local_38 = local_8;
            local_34 = local_4;
            if (param_1 != 0) {
              local_3c = fVar2 * local_c;
              local_38 = fVar2 * local_8;
              local_34 = local_4 * fVar2;
            }
            local_54 = local_54 + 1;
            local_48 = local_3c + local_48;
            local_44 = local_38 + local_44;
            local_40 = local_34 + local_40;
            local_58 = fVar2 + local_58;
          }
        }
      } while (local_50 != 0xffffffff);
      if ((local_58 < 1e-05 == NAN(local_58)) && (local_54 != 0)) {
        if ((param_1 == 0) && (local_58 = (float)local_54, local_54 < 0)) {
          local_58 = local_58 + 4.294967e+09;
        }
        local_58 = 1.0 / local_58;
        *(float *)(local_4c + 0x38) = local_58 * local_48;
        *(float *)(local_4c + 0x3c) = local_44 * local_58;
        *(float *)(local_4c + 0x40) = local_58 * local_40;
        return;
      }
    }
  }
  return;
}

/* public: void __thiscall
 * CPlugPhysicalObject::ComputeComPosAndInertiaMatrix(float,int) */

void __thiscall CPlugPhysicalObject::ComputeComPosAndInertiaMatrix(
    CPlugPhysicalObject *this, float param_1, int param_2)

{
  ComputeComPos(this, param_2);
  ComputeInertiaMatrix(this, param_1, param_2);
  return;
}

/* public: void __thiscall CPlugPhysicalObject::ComputeInertiaMatrix(float,int)
 */

void __thiscall CPlugPhysicalObject::ComputeInertiaMatrix(
    CPlugPhysicalObject *this, float param_1, int param_2)

{
  CPlugSurfaceGeom *this_00;
  float fVar1;
  CPlugTree *pCVar2;
  ulong uVar3;
  CMwClassInfo *unaff_ESI;
  ulong uVar4;
  float local_70;
  ulong local_6c;
  CPlugTree *local_68;
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
  float local_34;
  GmIso4 local_30[48];

  pCVar2 = *(CPlugTree **)(this + 0x44);
  if (pCVar2 != (CPlugTree *)0x0) {
    local_70 = 0.0;
    local_68 = pCVar2;
    GmMat3::SetIdentity((GmMat3 *)&local_54);
    local_6c = __InitClassInfo_CFuncShader(unaff_ESI);
    if (local_6c != 0xffffffff) {
      do {
        pCVar2 = CPlugTree::GetAllTreeNext(pCVar2, &local_6c);
        if ((*(int *)(pCVar2 + 0x8c) != 0) &&
            (((byte)pCVar2[0x9c] & 0x80) != 0)) {
          this_00 = *(CPlugSurfaceGeom **)(*(int *)(pCVar2 + 0x8c) + 0x14);
          CPlugTree::GetThisToRootTransfo(pCVar2, local_30, 1,
                                          (CPlugTree *)0x0);
          uVar3 = CPlugSurfaceGeom::GetWeightDistribCount(this_00);
          if (uVar3 != 0) {
            local_64 = CPlugSurfaceGeom::GetVolume(this_00);
            local_70 = local_64 + local_70;
            fVar1 = (float)uVar3;
            if ((int)uVar3 < 0) {
              fVar1 = fVar1 + 4.294967e+09;
            }
            local_64 = local_64 / fVar1;
            uVar4 = 0;
            if (uVar3 != 0) {
              do {
                CPlugSurfaceGeom::GetWeightDistrib(this_00, uVar4,
                                                   (GmVec3 *)&local_60);
                GmVec3::Mult((GmVec3 *)&local_60, local_30);
                local_60 = local_60 - *(float *)(this + 0x38);
                uVar4 = uVar4 + 1;
                local_5c = local_5c - *(float *)(this + 0x3c);
                local_58 = local_58 - *(float *)(this + 0x40);
                local_54 = local_54 + local_64 * (local_5c * local_5c +
                                                  local_58 * local_58);
                local_44 = local_44 + local_64 * (local_60 * local_60 +
                                                  local_58 * local_58);
                local_34 = local_34 + local_64 * (local_60 * local_60 +
                                                  local_5c * local_5c);
                fVar1 = local_60 * local_5c * local_64;
                local_50 = local_50 - fVar1;
                local_48 = local_48 - fVar1;
                fVar1 = local_64 * local_58 * local_60;
                local_4c = local_4c - fVar1;
                local_3c = local_3c - fVar1;
                fVar1 = local_64 * local_5c * local_58;
                local_40 = local_40 - fVar1;
                local_38 = local_38 - fVar1;
              } while (uVar4 < uVar3);
            }
          }
        }
        pCVar2 = local_68;
      } while (local_6c != 0xffffffff);
      if (local_70 < 1e-05 == NAN(local_70)) {
        local_64 = (*(float *)this * param_1) / local_70;
        GmMat3::Mult((GmMat3 *)&local_54, local_64);
        GmMat3::Set((GmMat3 *)(this + 4), (GmMat3 *)&local_54);
        GmMat3::Inverse((GmMat3 *)(this + 4));
        return;
      }
    }
  }
  return;
}

/* public: void __thiscall CPlugPhysicalObject::CopyFrom(class
 * CPlugPhysicalObject const &) */

void __thiscall CPlugPhysicalObject::CopyFrom(CPlugPhysicalObject *this,
                                              CPlugPhysicalObject *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  GmMat3::Set((GmMat3 *)(this + 4), (GmMat3 *)(param_1 + 4));
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  return;
}

/* public: __thiscall CPlugPhysicalObject::CPlugPhysicalObject(void) */

CPlugPhysicalObject *__thiscall CPlugPhysicalObject::CPlugPhysicalObject(
    CPlugPhysicalObject *this)

{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 0x28) = 0x3dcccccd;
  *(undefined4 *)(this + 0x2c) = 0x3e99999a;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x30) = 0x3e99999a;
  *(undefined4 *)(this + 0x34) = 0x3f800000;
  SetInertiaMatrixSphere(this, 1.0);
  return this;
}

/* public: void __thiscall CPlugPhysicalObject::SetComPos(class GmVec3 const &)
 */

void __thiscall CPlugPhysicalObject::SetComPos(CPlugPhysicalObject *this,
                                               GmVec3 *param_1)

{
  *(undefined4 *)(this + 0x38) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 8);
  return;
}

/* public: void __thiscall
 * CPlugPhysicalObject::SetComPosAndInertiaMatrixFromTreeBoundingBox(void)
 */

void __thiscall CPlugPhysicalObject::
    SetComPosAndInertiaMatrixFromTreeBoundingBox(CPlugPhysicalObject *this)

{
  int iVar1;

  if (*(int *)(this + 0x44) != 0) {
    iVar1 = *(int *)(this + 0x44);
    *(undefined4 *)(this + 0x38) = *(undefined4 *)(iVar1 + 0x34);
    *(undefined4 *)(this + 0x3c) = *(undefined4 *)(iVar1 + 0x38);
    *(undefined4 *)(this + 0x40) = *(undefined4 *)(iVar1 + 0x3c);
    SetInertiaMatrixBox(this, *(float *)this,
                        (GmVec3 *)(*(int *)(this + 0x44) + 0x40));
  }
  return;
}

/* public: void __thiscall CPlugPhysicalObject::SetInertiaMatrixBox(float,class
 * GmVec3 const &) */

void __thiscall CPlugPhysicalObject::SetInertiaMatrixBox(
    CPlugPhysicalObject *this, float param_1, GmVec3 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  fVar1 = *(float *)param_2;
  fVar2 = *(float *)(param_2 + 4);
  fVar3 = *(float *)(param_2 + 8);
  GmMat3::SetIdentity((GmMat3 *)(this + 4));
  fVar4 = (1.0 / param_1) * 12.0;
  fVar3 = fVar3 * 2.0 * fVar3 * 2.0;
  fVar2 = fVar2 * 2.0 * fVar2 * 2.0;
  *(float *)(this + 4) = fVar4 / (fVar2 + fVar3);
  fVar1 = fVar1 * 2.0 * fVar1 * 2.0;
  *(float *)(this + 0x14) = (fVar1 + fVar3) / fVar4;
  *(float *)(this + 0x24) = fVar4 / (fVar2 + fVar1);
  return;
}

/* public: void __thiscall CPlugPhysicalObject::SetInertiaMatrixSphere(float) */

void __thiscall CPlugPhysicalObject::SetInertiaMatrixSphere(
    CPlugPhysicalObject *this, float param_1)

{
  GmMat3 *this_00;

  this_00 = (GmMat3 *)(this + 4);
  GmMat3::SetIdentity(this_00);
  GmMat3::Mult(this_00, 3.0 / (param_1 * 12.56637 * param_1 * param_1));
  GmMat3::Mult(this_00, 1.0 / *(float *)this);
  return;
}
