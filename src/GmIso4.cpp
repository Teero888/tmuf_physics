
/* public: void __thiscall GmIso4::ArchiveGmIso4(class CClassicArchive &) */

void __thiscall GmIso4::ArchiveGmIso4(GmIso4 *this, CClassicArchive *param_1)

{
  GmMat3::ArchiveGmMat3((GmMat3 *)this, param_1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x24), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x28), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x2c), 1);
  return;
}

/* public: void __thiscall GmIso4::GetDir(class GmVec3 &)const  */

void __thiscall GmIso4::GetDir(GmIso4 *this, GmVec3 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;

  uVar1 = *(undefined4 *)(this + 0x14);
  uVar2 = *(undefined4 *)(this + 0x20);
  *(undefined4 *)param_1 = *(undefined4 *)(this + 8);
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 8) = uVar2;
  return;
}

/* public: void __thiscall GmIso4::GetPlaneEq(unsigned long,class GmVec4 &)const
 */

void __thiscall GmIso4::GetPlaneEq(GmIso4 *this, ulong param_1, GmVec4 *param_2)

{
  float local_c;
  float local_8;
  float local_4;

  GmMat3::GetLine((GmMat3 *)this, param_1, (GmVec3 *)&local_c);
  *(float *)param_2 = local_c;
  *(float *)(param_2 + 4) = local_8;
  *(float *)(param_2 + 8) = local_4;
  *(float *)(param_2 + 0xc) =
      (-local_c * *(float *)(this + 0x24) - *(float *)(this + 0x28) * local_8) -
      *(float *)(this + 0x2c) * local_4;
  return;
}

/* public: void __thiscall GmIso4::Inverse(void) */

void __thiscall GmIso4::Inverse(GmIso4 *this)

{
  GmMat3::Transpose((GmMat3 *)this);
  *(float *)(this + 0x24) = -*(float *)(this + 0x24);
  *(float *)(this + 0x28) = -*(float *)(this + 0x28);
  *(float *)(this + 0x2c) = -*(float *)(this + 0x2c);
  GmVec3::Mult((GmVec3 *)(this + 0x24), (GmMat3 *)this);
  return;
}

/* public: unsigned long __thiscall GmIso4::IsNearlyEqual(class GmIso4 const
 * &)const  */

ulong __thiscall GmIso4::IsNearlyEqual(GmIso4 *this, GmIso4 *param_1)

{
  ulong uVar1;

  uVar1 = GmVec3::IsNearlyEqual((GmVec3 *)(this + 0x24),
                                (GmVec3 *)(param_1 + 0x24));
  if (uVar1 != 0) {
    uVar1 = GmMat3::IsNearlyEqual((GmMat3 *)this, (GmMat3 *)param_1);
    if (uVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

/* public: void __thiscall GmIso4::LeftMult(class GmIso4 const &) */

void __thiscall GmIso4::LeftMult(GmIso4 *this, GmIso4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_30[12];

  puVar2 = (undefined4 *)this;
  puVar3 = local_30;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  SetMult(this, param_1, (GmIso4 *)local_30);
  return;
}

/* public: void __thiscall GmIso4::Mult(class GmIso4 const &) */

void __thiscall GmIso4::Mult(GmIso4 *this, GmIso4 *param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float local_24[4];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  fVar1 = *(float *)param_1;
  pfVar3 = (float *)this;
  pfVar4 = local_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  *(float *)this = local_c * *(float *)(param_1 + 8) +
                   local_24[3] * *(float *)(param_1 + 4) + local_24[0] * fVar1;
  *(float *)(this + 4) = local_8 * *(float *)(param_1 + 8) +
                         local_14 * *(float *)(param_1 + 4) +
                         local_24[1] * *(float *)param_1;
  *(float *)(this + 8) = local_4 * *(float *)(param_1 + 8) +
                         local_10 * *(float *)(param_1 + 4) +
                         *(float *)param_1 * local_24[2];
  *(float *)(this + 0xc) = *(float *)(param_1 + 0x14) * local_c +
                           local_24[0] * *(float *)(param_1 + 0xc) +
                           *(float *)(param_1 + 0x10) * local_24[3];
  *(float *)(this + 0x10) = *(float *)(param_1 + 0x14) * local_8 +
                            *(float *)(param_1 + 0xc) * local_24[1] +
                            *(float *)(param_1 + 0x10) * local_14;
  *(float *)(this + 0x14) = *(float *)(param_1 + 0x14) * local_4 +
                            *(float *)(param_1 + 0xc) * local_24[2] +
                            *(float *)(param_1 + 0x10) * local_10;
  *(float *)(this + 0x18) = *(float *)(param_1 + 0x1c) * local_24[3] +
                            *(float *)(param_1 + 0x18) * local_24[0] +
                            *(float *)(param_1 + 0x20) * local_c;
  *(float *)(this + 0x1c) = *(float *)(param_1 + 0x20) * local_8 +
                            local_14 * *(float *)(param_1 + 0x1c) +
                            *(float *)(param_1 + 0x18) * local_24[1];
  *(float *)(this + 0x20) = *(float *)(param_1 + 0x20) * local_4 +
                            *(float *)(param_1 + 0x18) * local_24[2] +
                            *(float *)(param_1 + 0x1c) * local_10;
  GmVec3::Mult((GmVec3 *)(this + 0x24), param_1);
  return;
}

/* public: void __thiscall GmIso4::MultInverse(class GmIso4 const &) */

void __thiscall GmIso4::MultInverse(GmIso4 *this, GmIso4 *param_1)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float local_54[4];
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
  float local_c;
  float local_8;
  float local_4;

  local_30 = *(float *)param_1;
  local_20 = *(float *)(param_1 + 0x10);
  local_10 = *(float *)(param_1 + 0x20);
  local_2c = *(float *)(param_1 + 0xc);
  local_24 = *(float *)(param_1 + 4);
  local_28 = *(float *)(param_1 + 0x18);
  local_18 = *(float *)(param_1 + 8);
  local_1c = *(float *)(param_1 + 0x1c);
  local_14 = *(float *)(param_1 + 0x14);
  local_c = -*(float *)(param_1 + 0x24);
  local_8 = -*(float *)(param_1 + 0x28);
  local_4 = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((GmVec3 *)&local_c, (GmMat3 *)&local_30);
  pfVar2 = (float *)this;
  pfVar3 = local_54;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  *(float *)this =
      local_3c * local_28 + local_2c * local_54[3] + local_30 * local_54[0];
  *(float *)(this + 4) =
      local_38 * local_28 + local_54[1] * local_30 + local_44 * local_2c;
  *(float *)(this + 8) =
      local_34 * local_28 + local_40 * local_2c + local_54[2] * local_30;
  *(float *)(this + 0xc) =
      local_3c * local_1c + local_54[3] * local_20 + local_54[0] * local_24;
  *(float *)(this + 0x10) =
      local_38 * local_1c + local_44 * local_20 + local_54[1] * local_24;
  *(float *)(this + 0x14) =
      local_34 * local_1c + local_40 * local_20 + local_54[2] * local_24;
  *(float *)(this + 0x18) =
      local_14 * local_54[3] + local_18 * local_54[0] + local_10 * local_3c;
  *(float *)(this + 0x1c) =
      local_38 * local_10 + local_54[1] * local_18 + local_44 * local_14;
  *(float *)(this + 0x20) =
      local_10 * local_34 + local_14 * local_40 + local_54[2] * local_18;
  GmVec3::Mult((GmVec3 *)(this + 0x24), (GmIso4 *)&local_30);
  return;
}

/* public: void __thiscall GmIso4::NUGetIso4AndScale(class GmIso4 &,class GmVec3
 * &)const  */

void __thiscall GmIso4::NUGetIso4AndScale(GmIso4 *this, GmIso4 *param_1,
                                          GmVec3 *param_2)

{
  float fVar1;
  ulong uVar2;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;

  puVar4 = (undefined4 *)param_1;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *(undefined4 *)this;
    this = (GmIso4 *)((int)this + 4);
    puVar4 = puVar4 + 1;
  }
  GmMat3::Transpose((GmMat3 *)param_1);
  fVar5 = (float10)__CIsqrt();
  *(float *)param_2 = (float)fVar5;
  fVar5 = (float10)__CIsqrt();
  *(float *)(param_2 + 4) = (float)fVar5;
  fVar5 = (float10)__CIsqrt();
  *(float *)(param_2 + 8) = (float)fVar5;
  fVar1 = *(float *)param_2 / 1.0;
  *(float *)param_1 = fVar1 * *(float *)param_1;
  *(float *)(param_1 + 4) = *(float *)(param_1 + 4) * fVar1;
  *(float *)(param_1 + 8) = fVar1 * *(float *)(param_1 + 8);
  fVar1 = 1.0 / *(float *)(param_2 + 4);
  *(float *)(param_1 + 0xc) = fVar1 * *(float *)(param_1 + 0xc);
  *(float *)(param_1 + 0x10) = fVar1 * *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 0x14) = fVar1 * *(float *)(param_1 + 0x14);
  fVar1 = 1.0 / *(float *)(param_2 + 8);
  *(float *)(param_1 + 0x18) = fVar1 * *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) * fVar1;
  *(float *)(param_1 + 0x20) = fVar1 * *(float *)(param_1 + 0x20);
  uVar2 = GmMat3::IsIndirect((GmMat3 *)param_1);
  if (uVar2 != 0) {
    *(float *)param_1 = -*(float *)param_1;
    *(float *)(param_1 + 4) = -*(float *)(param_1 + 4);
    *(float *)(param_1 + 8) = -*(float *)(param_1 + 8);
    *(float *)param_2 = -*(float *)param_2;
  }
  GmMat3::Transpose((GmMat3 *)param_1);
  return;
}

/* public: void __thiscall GmIso4::NUScaleSetInverse(class GmIso4 const &) */

void __thiscall GmIso4::NUScaleSetInverse(GmIso4 *this, GmIso4 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  GmMat3::SetTranspose((GmMat3 *)this, (GmMat3 *)param_1);
  fVar1 = (*(float *)(this + 8) * *(float *)(this + 8) +
           *(float *)this * *(float *)this +
           *(float *)(this + 4) * *(float *)(this + 4)) /
          1.0;
  fVar2 = 1.0 / (*(float *)(this + 0x14) * *(float *)(this + 0x14) +
                 *(float *)(this + 0xc) * *(float *)(this + 0xc) +
                 *(float *)(this + 0x10) * *(float *)(this + 0x10));
  fVar3 = 1.0 / (*(float *)(this + 0x20) * *(float *)(this + 0x20) +
                 *(float *)(this + 0x18) * *(float *)(this + 0x18) +
                 *(float *)(this + 0x1c) * *(float *)(this + 0x1c));
  *(float *)this = fVar1 * *(float *)this;
  *(float *)(this + 4) = fVar1 * *(float *)(this + 4);
  *(float *)(this + 8) = fVar1 * *(float *)(this + 8);
  *(float *)(this + 0xc) = fVar2 * *(float *)(this + 0xc);
  *(float *)(this + 0x10) = *(float *)(this + 0x10) * fVar2;
  *(float *)(this + 0x14) = fVar2 * *(float *)(this + 0x14);
  *(float *)(this + 0x18) = fVar3 * *(float *)(this + 0x18);
  *(float *)(this + 0x1c) = *(float *)(this + 0x1c) * fVar3;
  *(float *)(this + 0x20) = fVar3 * *(float *)(this + 0x20);
  *(float *)(this + 0x24) = -*(float *)(param_1 + 0x24);
  *(float *)(this + 0x28) = -*(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((GmVec3 *)(this + 0x24), (GmMat3 *)this);
  return;
}

/* public: void __thiscall GmIso4::RotateX(float) */

void __thiscall GmIso4::RotateX(GmIso4 *this, float param_1)

{
  GmMat3::RotateX((GmMat3 *)this, param_1);
  return;
}

/* public: void __thiscall GmIso4::RotateY(float) */

void __thiscall GmIso4::RotateY(GmIso4 *this, float param_1)

{
  GmMat3::RotateY((GmMat3 *)this, param_1);
  return;
}

/* public: void __thiscall GmIso4::RotateZ(float) */

void __thiscall GmIso4::RotateZ(GmIso4 *this, float param_1)

{
  GmMat3::RotateZ((GmMat3 *)this, param_1);
  return;
}

/* public: void __thiscall GmIso4::Set(class GmMat3 const &,class GmVec3 const
 * &) */

void __thiscall GmIso4::Set(GmIso4 *this, GmMat3 *param_1, GmVec3 *param_2)

{
  GmMat3::Set((GmMat3 *)this, param_1);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_2 + 8);
  return;
}

/* public: void __thiscall GmIso4::Set(class GmTransQuat const &) */

void __thiscall GmIso4::Set(GmIso4 *this, GmTransQuat *param_1)

{
  GmMat3::Set((GmMat3 *)this, *(float *)param_1, *(float *)(param_1 + 4),
              *(float *)(param_1 + 8), *(float *)(param_1 + 0xc));
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x18);
  return;
}

/* public: void __thiscall GmIso4::SetBlend(class GmIso4 const &,class GmIso4
 * const &,float) */

void __thiscall GmIso4::SetBlend(GmIso4 *this, GmIso4 *param_1, GmIso4 *param_2,
                                 float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;

  *(float *)(this + 0x24) =
      *(float *)(param_2 + 0x24) - *(float *)(param_1 + 0x24);
  *(float *)(this + 0x28) =
      *(float *)(param_2 + 0x28) - *(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) =
      *(float *)(param_2 + 0x2c) - *(float *)(param_1 + 0x2c);
  fVar1 = *(float *)(this + 0x24);
  *(float *)(this + 0x24) = param_3 * fVar1;
  fVar2 = *(float *)(this + 0x28);
  *(float *)(this + 0x28) = fVar2 * param_3;
  fVar3 = *(float *)(this + 0x2c);
  *(float *)(this + 0x2c) = fVar3 * param_3;
  *(float *)(this + 0x24) = *(float *)(param_1 + 0x24) + param_3 * fVar1;
  *(float *)(this + 0x28) = fVar2 * param_3 + *(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) = fVar3 * param_3 + *(float *)(param_1 + 0x2c);
  GmMat3::SetBlend((GmMat3 *)this, (GmMat3 *)param_1, (GmMat3 *)param_2,
                   param_3);
  return;
}

/* public: void __thiscall GmIso4::SetColumn(unsigned long,class GmVec4 const &)
 */

void __thiscall GmIso4::SetColumn(GmIso4 *this, ulong param_1, GmVec4 *param_2)

{
  *(undefined4 *)(this + param_1 * 0xc) = *(undefined4 *)param_2;
  *(undefined4 *)(this + param_1 * 0xc + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + param_1 * 0xc + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(this + param_1 * 4 + 0x24) = *(undefined4 *)(param_2 + 0xc);
  return;
}

/* public: void __thiscall GmIso4::SetIdentity(void) */

void __thiscall GmIso4::SetIdentity(GmIso4 *this)

{
  GmMat3::SetIdentity((GmMat3 *)this);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  return;
}

/* public: void __thiscall GmIso4::SetInverse(class GmIso4 const &) */

void __thiscall GmIso4::SetInverse(GmIso4 *this, GmIso4 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x14);
  *(float *)(this + 0x24) = -*(float *)(param_1 + 0x24);
  *(float *)(this + 0x28) = -*(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((GmVec3 *)(this + 0x24), (GmMat3 *)this);
  return;
}

/* public: void __thiscall GmIso4::SetLookAt(class GmVec3 const &,class GmVec3
   const &,class GmVec3 const &) */

void __thiscall GmIso4::SetLookAt(GmIso4 *this, GmVec3 *param_1,
                                  GmVec3 *param_2, GmVec3 *param_3)

{
  float local_c;
  float local_8;
  float local_4;

  local_c = *(float *)param_2 - *(float *)param_1;
  local_8 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_4 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  GmMat3::SetDOVandUpV((GmMat3 *)this, (GmVec3 *)&local_c, param_3);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 8);
  return;
}

/* public: void __thiscall GmIso4::SetLookAt(class GmVec3 const &,class GmVec3
   const &,unsigned long) */

void __thiscall GmIso4::SetLookAt(GmIso4 *this, GmVec3 *param_1,
                                  GmVec3 *param_2, ulong param_3)

{
  float local_c;
  float local_8;
  float local_4;

  local_c = *(float *)param_2 - *(float *)param_1;
  local_8 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_4 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  GmMat3::SetDOV((GmMat3 *)this, (GmVec3 *)&local_c, param_3);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 8);
  return;
}

/* public: void __thiscall GmIso4::SetMult(class GmIso4 const &,class GmIso4
 * const &) */

void __thiscall GmIso4::SetMult(GmIso4 *this, GmIso4 *param_1, GmIso4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;

  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 0xc);
  fVar3 = *(float *)(param_1 + 0x18);
  fVar4 = *(float *)(param_1 + 4);
  fVar5 = *(float *)(param_1 + 0x10);
  fVar6 = *(float *)(param_1 + 0x1c);
  fVar7 = *(float *)(param_1 + 8);
  fVar8 = *(float *)(param_1 + 0x14);
  fVar9 = *(float *)(param_1 + 0x20);
  *(float *)this = fVar3 * *(float *)(param_2 + 8) +
                   fVar2 * *(float *)(param_2 + 4) + fVar1 * *(float *)param_2;
  *(float *)(this + 4) = fVar6 * *(float *)(param_2 + 8) +
                         fVar5 * *(float *)(param_2 + 4) +
                         fVar4 * *(float *)param_2;
  *(float *)(this + 8) = fVar9 * *(float *)(param_2 + 8) +
                         fVar8 * *(float *)(param_2 + 4) +
                         *(float *)param_2 * fVar7;
  *(float *)(this + 0xc) = *(float *)(param_2 + 0x14) * fVar3 +
                           *(float *)(param_2 + 0xc) * fVar1 +
                           *(float *)(param_2 + 0x10) * fVar2;
  *(float *)(this + 0x10) = *(float *)(param_2 + 0x14) * fVar6 +
                            fVar4 * *(float *)(param_2 + 0xc) +
                            *(float *)(param_2 + 0x10) * fVar5;
  *(float *)(this + 0x14) = *(float *)(param_2 + 0x14) * fVar9 +
                            *(float *)(param_2 + 0xc) * fVar7 +
                            *(float *)(param_2 + 0x10) * fVar8;
  *(float *)(this + 0x18) = *(float *)(param_2 + 0x1c) * fVar2 +
                            *(float *)(param_2 + 0x18) * fVar1 +
                            *(float *)(param_2 + 0x20) * fVar3;
  *(float *)(this + 0x1c) = *(float *)(param_2 + 0x20) * fVar6 +
                            fVar5 * *(float *)(param_2 + 0x1c) +
                            *(float *)(param_2 + 0x18) * fVar4;
  *(float *)(this + 0x20) = *(float *)(param_2 + 0x20) * fVar9 +
                            *(float *)(param_2 + 0x18) * fVar7 +
                            *(float *)(param_2 + 0x1c) * fVar8;
  *(float *)(this + 0x24) =
      *(float *)(param_1 + 0x2c) * *(float *)(param_2 + 8) +
      *(float *)(param_1 + 0x24) * *(float *)param_2 +
      *(float *)(param_1 + 0x28) * *(float *)(param_2 + 4) +
      *(float *)(param_2 + 0x24);
  *(float *)(this + 0x28) =
      *(float *)(param_2 + 0x14) * *(float *)(param_1 + 0x2c) +
      *(float *)(param_2 + 0xc) * *(float *)(param_1 + 0x24) +
      *(float *)(param_2 + 0x10) * *(float *)(param_1 + 0x28) +
      *(float *)(param_2 + 0x28);
  *(float *)(this + 0x2c) =
      *(float *)(param_2 + 0x20) * *(float *)(param_1 + 0x2c) +
      *(float *)(param_1 + 0x24) * *(float *)(param_2 + 0x18) +
      *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 0x28) +
      *(float *)(param_2 + 0x2c);
  return;
}

/* public: void __thiscall GmIso4::SetNUScaleTrans(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall GmIso4::SetNUScaleTrans(GmIso4 *this, GmVec3 *param_1,
                                        GmVec3 *param_2)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_2 + 8);
  return;
}

/* public: void __thiscall GmIso4::SetRotation(class GmMat3 const &) */

void __thiscall GmIso4::SetRotation(GmIso4 *this, GmMat3 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  return;
}

/* public: void __thiscall GmIso4::SetTranslation(class GmVec3 const &) */

void __thiscall GmIso4::SetTranslation(GmIso4 *this, GmVec3 *param_1)

{
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 8);
  return;
}

/* public: void __thiscall GmIso4::SetUScaleTrans(float,class GmVec3 const &) */

void __thiscall GmIso4::SetUScaleTrans(GmIso4 *this, float param_1,
                                       GmVec3 *param_2)

{
  *(float *)(this + 0x20) = param_1;
  *(float *)(this + 0x10) = param_1;
  *(float *)this = param_1;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_2 + 8);
  return;
}

/* public: void __thiscall GmIso4::SetXY(class GmIso3 const &) */

void __thiscall GmIso4::SetXY(GmIso4 *this, GmIso3 *param_1)

{
  undefined4 uVar1;

  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = 0;
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x10) = uVar1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0x3f800000;
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x28) = uVar1;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}

/* public: void __thiscall GmIso4::SymmetryPlane(class GmVec4 const &) */

void __thiscall GmIso4::SymmetryPlane(GmIso4 *this, GmVec4 *param_1)

{
  float fVar1;
  ulong uVar2;
  float local_c;
  float local_8;
  float local_4;

  uVar2 = 0;
  do {
    GmMat3::GetLine((GmMat3 *)this, uVar2, (GmVec3 *)&local_c);
    fVar1 = local_8 * *(float *)(param_1 + 4) + local_c * *(float *)param_1 +
            local_4 * *(float *)(param_1 + 8);
    fVar1 = fVar1 + fVar1;
    local_c = local_c - fVar1 * *(float *)param_1;
    local_8 = local_8 - fVar1 * *(float *)(param_1 + 4);
    local_4 = local_4 - fVar1 * *(float *)(param_1 + 8);
    GmMat3::SetLine((GmMat3 *)this, uVar2, (GmVec3 *)&local_c);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 3);
  fVar1 = *(float *)(this + 0x2c) * *(float *)(param_1 + 8) +
          *(float *)(this + 0x28) * *(float *)(param_1 + 4) +
          *(float *)(this + 0x24) * *(float *)param_1 +
          *(float *)(param_1 + 0xc);
  fVar1 = fVar1 + fVar1;
  *(float *)(this + 0x24) = *(float *)(this + 0x24) - fVar1 * *(float *)param_1;
  *(float *)(this + 0x28) =
      *(float *)(this + 0x28) - fVar1 * *(float *)(param_1 + 4);
  *(float *)(this + 0x2c) =
      *(float *)(this + 0x2c) - *(float *)(param_1 + 8) * fVar1;
  return;
}

/* public: void __thiscall GmIso4::UScaleSetInverse(class GmIso4 const &) */

void __thiscall GmIso4::UScaleSetInverse(GmIso4 *this, GmIso4 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar1 = *(float *)(param_1 + 4);
  fVar2 = *(float *)param_1;
  fVar3 = *(float *)(param_1 + 8);
  GmMat3::SetTranspose((GmMat3 *)this, (GmMat3 *)param_1);
  GmMat3::Mult((GmMat3 *)this,
               1.0 / (fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1));
  *(float *)(this + 0x24) = -*(float *)(param_1 + 0x24);
  *(float *)(this + 0x28) = -*(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((GmVec3 *)(this + 0x24), (GmMat3 *)this);
  return;
}
