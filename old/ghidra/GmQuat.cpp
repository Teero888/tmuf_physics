
/* public: void __thiscall GmQuat::ArchiveGmQuat(class CClassicArchive &) */

void __thiscall GmQuat::ArchiveGmQuat(GmQuat *this, CClassicArchive *param_1)

{
  CClassicArchive::DoReal(param_1, (float *)(this + 4), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 8), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0xc), 1);
  CClassicArchive::DoReal(param_1, (float *)this, 1);
  return;
}

/* public: void __thiscall GmQuat::ArchiveGmQuatCompact(class CClassicArchive &)
 */

void __thiscall GmQuat::ArchiveGmQuatCompact(GmQuat *this,
                                             CClassicArchive *param_1)

{
  float *pfVar1;
  CClassicArchive *this_00;
  float10 *extraout_ECX;
  float10 *extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined2 in_FPUControlWord;
  float10 fVar2;
  float10 fVar3;
  undefined local_10;
  float local_c;
  float local_8;
  float local_4;

  this_00 = param_1;
  if (*(int *)(param_1 + 8) != 0) {
    fVar2 = (float10)__CIacos();
    local_c = *(float *)(this + 4);
    local_8 = *(float *)(this + 8);
    local_4 = *(float *)(this + 0xc);
    param_1 = (CClassicArchive *)(local_4 * local_4 + local_c * local_c +
                                  local_8 * local_8);
    fVar3 = (float10)__CIsqrt();
    param_1 = (CClassicArchive *)(float)fVar3;
    if ((float)param_1 < 1e-05 == NAN((float)param_1)) {
      param_1 = (CClassicArchive *)(1.0 / (float)param_1);
      local_c = (float)param_1 * local_c;
      local_8 = local_8 * (float)param_1;
      local_4 = (float)param_1 * local_4;
    } else {
      local_c = 1.0;
      local_4 = 0.0;
      local_8 = 0.0;
    }
    param_1 = (CClassicArchive *)CONCAT22(param_1._2_2_, in_FPUControlWord);
    local_10 = (undefined)(int)ROUND(((float)fVar2 * 255.0) / 3.141593);
    param_1 = (CClassicArchive *)CONCAT31(param_1._1_3_, local_10);
    CClassicArchive::DoNat8(this_00, (uchar *)&param_1, 1, 0);
    GmFunc::WriteUnitVec3(*(CClassicBuffer **)(this_00 + 4),
                          (GmVec3 *)&local_c);
    return;
  }
  CClassicArchive::DoNat8(param_1, (uchar *)&param_1, 1, 0);
  pfVar1 = (float *)(this + 4);
  GmFunc::ReadUnitVec3(*(CClassicBuffer **)(this_00 + 4), (GmVec3 *)pfVar1);
  fVar2 = (float10)__CIsin(extraout_ECX, extraout_EDX);
  param_1 = (CClassicArchive *)(float)fVar2;
  *pfVar1 = (float)param_1 * *pfVar1;
  *(float *)(this + 8) = (float)param_1 * *(float *)(this + 8);
  *(float *)(this + 0xc) = (float)param_1 * *(float *)(this + 0xc);
  fVar2 = (float10)__CIcos(extraout_ECX_00, extraout_EDX_00);
  *(float *)this = (float)fVar2;
  return;
}

/* public: void __thiscall GmQuat::ComputeSquad(class GmQuat &,class GmQuat
   &,class GmQuat &,class GmQuat &,float) */

void __thiscall GmQuat::ComputeSquad(GmQuat *this, GmQuat *param_1,
                                     GmQuat *param_2, GmQuat *param_3,
                                     GmQuat *param_4, float param_5)

{
  float fVar1;
  GmQuat *extraout_ECX;
  float10 *extraout_ECX_00;
  float10 *extraout_ECX_01;
  GmQuat *extraout_ECX_02;
  float10 *extraout_ECX_03;
  float10 *extraout_ECX_04;
  float *extraout_ECX_05;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  float10 fVar2;
  float10 fVar3;
  float *pfVar4;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  GmQuat local_40[4];
  float local_3c;
  float local_38;
  float local_34;
  GmQuat local_30[4];
  float local_2c;
  float local_28;
  float local_24;
  GmQuat local_20[16];
  float local_10[4];

  SetInverse(local_20, param_2);
  SetMult(local_40, extraout_ECX, param_3);
  SetMult(local_30, local_20, param_1);
  fVar2 = (float10)__CIsqrt();
  fVar3 = (float10)__CIasin();
  local_4c = (float)fVar3;
  local_44 = 0.0;
  if ((float)fVar2 <= 1e-05) {
    local_48 = 0.0;
  } else {
    local_44 = local_4c / (float)fVar2;
    local_4c = local_44 * local_3c;
    local_48 = local_38 * local_44;
    local_44 = local_44 * local_34;
  }
  fVar2 = (float10)__CIsqrt();
  fVar3 = (float10)__CIasin();
  local_58 = (float)fVar3;
  if ((float)fVar2 <= 1e-05) {
    local_50 = 0.0;
    local_54 = 0.0;
  } else {
    local_50 = local_58 / (float)fVar2;
    local_58 = local_50 * local_2c;
    local_54 = local_28 * local_50;
    local_50 = local_50 * local_24;
  }
  local_64 = (local_58 + local_4c) * -0.25;
  local_60 = (local_54 + local_48) * -0.25;
  local_5c = (local_50 + local_44) * -0.25;
  fVar2 = (float10)__CIsqrt();
  if ((float)fVar2 <= 1e-05) {
    SetIdentity(local_40);
  } else {
    fVar3 = (float10)__CIsin(extraout_ECX_00, extraout_EDX);
    pfVar4 = &local_64;
    fVar1 = (float)fVar2 / (float)fVar3;
    local_64 = fVar1 * local_64;
    local_60 = local_60 * fVar1;
    local_5c = fVar1 * local_5c;
    fVar2 = (float10)__CIcos(extraout_ECX_01, extraout_EDX_00);
    Set(local_40, (float)fVar2, (GmVec3 *)pfVar4);
  }
  SetMult((GmQuat *)local_10, param_2, local_40);
  SetInverse(local_20, param_3);
  SetMult(local_40, extraout_ECX_02, param_4);
  SetMult(local_30, local_20, param_2);
  fVar2 = (float10)__CIsqrt();
  fVar3 = (float10)__CIasin();
  local_4c = (float)fVar3;
  if ((float)fVar2 <= 1e-05) {
    local_44 = 0.0;
    local_48 = 0.0;
  } else {
    local_44 = local_4c / (float)fVar2;
    local_4c = local_44 * local_3c;
    local_48 = local_38 * local_44;
    local_44 = local_44 * local_34;
  }
  fVar2 = (float10)__CIsqrt();
  fVar3 = (float10)__CIasin();
  local_58 = (float)fVar3;
  if ((float)fVar2 <= 1e-05) {
    local_50 = 0.0;
    local_54 = 0.0;
  } else {
    local_50 = local_58 / (float)fVar2;
    local_58 = local_50 * local_2c;
    local_54 = local_28 * local_50;
    local_50 = local_50 * local_24;
  }
  local_64 = (local_58 + local_4c) * -0.25;
  local_60 = (local_54 + local_48) * -0.25;
  local_5c = (local_50 + local_44) * -0.25;
  fVar2 = (float10)__CIsqrt();
  if ((float)fVar2 <= 1e-05) {
    SetIdentity(local_40);
  } else {
    fVar3 = (float10)__CIsin(extraout_ECX_03, extraout_EDX_01);
    pfVar4 = &local_64;
    fVar1 = (float)fVar2 / (float)fVar3;
    local_64 = fVar1 * local_64;
    local_60 = local_60 * fVar1;
    local_5c = fVar1 * local_5c;
    fVar2 = (float10)__CIcos(extraout_ECX_04, pfVar4);
    Set(local_40, (float)fVar2, (GmVec3 *)pfVar4);
  }
  SetMult(local_20, param_3, local_40);
  SetSquad(this, *(float *)param_2, *(float *)(param_2 + 4),
           *(float *)(param_2 + 8), *(float *)(param_2 + 0xc), local_10,
           extraout_ECX_05, (float *)param_3, param_5);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmQuat::GetRotation(float &,class GmVec3 &) */

void __thiscall GmQuat::GetRotation(GmQuat *this, float *param_1,
                                    GmVec3 *param_2)

{
  float fVar1;
  uint uVar2;
  float10 fVar3;

  *(undefined4 *)param_2 = *(undefined4 *)(this + 4);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(this + 8);
  fVar1 = *(float *)(this + 0xc);
  *(float *)(param_2 + 8) = fVar1;
  fVar1 = *(float *)param_2 * *(float *)param_2 +
          *(float *)(param_2 + 4) * *(float *)(param_2 + 4) + fVar1 * fVar1;
  if (_DAT_00d1a87c < fVar1 != (NAN(_DAT_00d1a87c) || NAN(fVar1))) {
    fVar3 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar3;
    *(float *)param_2 = fVar1 * *(float *)param_2;
    *(float *)(param_2 + 4) = *(float *)(param_2 + 4) * fVar1;
    *(float *)(param_2 + 8) = fVar1 * *(float *)(param_2 + 8);
    uVar2 = (uint)(ABS(*(float *)param_2) < ABS(*(float *)(param_2 + 4)) !=
                   (NAN(ABS(*(float *)param_2)) ||
                    NAN(ABS(*(float *)(param_2 + 4)))));
    if (ABS(*(float *)(param_2 + uVar2 * 4)) < ABS(*(float *)(param_2 + 8)) !=
        (NAN(ABS(*(float *)(param_2 + uVar2 * 4))) ||
         NAN(ABS(*(float *)(param_2 + 8))))) {
      uVar2 = 2;
    }
    fVar3 = (float10)__CIatan2(uVar2);
    *param_1 = (float)fVar3 + (float)fVar3;
    return;
  }
  *(undefined4 *)param_2 = 0x3f800000;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *param_1 = 0.0;
  return;
}

/* public: void __thiscall GmQuat::GetYawPitchRoll(float &,float &,float &) */

void __thiscall GmQuat::GetYawPitchRoll(GmQuat *this, float *param_1,
                                        float *param_2, float *param_3)

{
  float fVar1;
  float fVar2;
  undefined4 extraout_ECX;
  float10 fVar3;

  fVar1 = *(float *)(this + 8) * *(float *)(this + 4) +
          *(float *)(this + 0xc) * *(float *)this;
  fVar2 = fVar1 - 0.5;
  if ((ABS(fVar2) < 1e-05) || (-1 < (int)fVar2)) {
    fVar3 = (float10)__CIatan2(this);
    *param_1 = (float)fVar3 * -2.0;
    *param_3 = 1.570796;
    *param_2 = 0.0;
    return;
  }
  fVar1 = fVar1 + 0.5;
  fVar2 = ABS(fVar1);
  if ((fVar2 < 1e-05 == NAN(fVar2)) && (((uint)fVar1 & 0x80000000) == 0)) {
    fVar3 = (float10)__CIatan2(this);
    *param_1 = (float)fVar3;
    fVar3 = (float10)__CIasin();
    *param_3 = (float)fVar3;
    fVar3 = (float10)__CIatan2(extraout_ECX);
    *param_2 = (float)fVar3;
    return;
  }
  fVar3 = (float10)__CIatan2(this);
  *param_1 = (float)fVar3 + (float)fVar3;
  *param_3 = -1.570796;
  *param_2 = 0.0;
  return;
}

/* public: void __thiscall GmQuat::Mult(class GmQuat const &) */

void __thiscall GmQuat::Mult(GmQuat *this, GmQuat *param_1)

{
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_10 = *(float *)param_1 * *(float *)this -
             (*(float *)(this + 0xc) * *(float *)(param_1 + 0xc) +
              *(float *)(this + 4) * *(float *)(param_1 + 4) +
              *(float *)(this + 8) * *(float *)(param_1 + 8));
  local_c = (*(float *)(param_1 + 0xc) * *(float *)(this + 8) +
             *(float *)this * *(float *)(param_1 + 4) +
             *(float *)(this + 4) * *(float *)param_1) -
            *(float *)(param_1 + 8) * *(float *)(this + 0xc);
  local_8 = (*(float *)(this + 0xc) * *(float *)(param_1 + 4) +
             *(float *)(param_1 + 8) * *(float *)this +
             *(float *)(this + 8) * *(float *)param_1) -
            *(float *)(param_1 + 0xc) * *(float *)(this + 4);
  local_4 = (*(float *)(param_1 + 8) * *(float *)(this + 4) +
             *(float *)(this + 0xc) * *(float *)param_1 +
             *(float *)(param_1 + 0xc) * *(float *)this) -
            *(float *)(this + 8) * *(float *)(param_1 + 4);
  GmVec4::Set((GmVec4 *)this, (GmVec4 *)&local_10);
  return;
}

/* public: void __thiscall GmQuat::Normalize(void) */

void __thiscall GmQuat::Normalize(GmQuat *this)

{
  float fVar1;
  float10 fVar2;

  fVar2 = (float10)__CIsqrt();
  fVar1 = 1.0 / (float)fVar2;
  *(float *)this = fVar1 * *(float *)this;
  *(float *)(this + 4) = *(float *)(this + 4) * fVar1;
  *(float *)(this + 8) = *(float *)(this + 8) * fVar1;
  *(float *)(this + 0xc) = fVar1 * *(float *)(this + 0xc);
  return;
}

/* public: void __thiscall GmQuat::Set(float,class GmVec3 const &) */

void __thiscall GmQuat::Set(GmQuat *this, float param_1, GmVec3 *param_2)

{
  *(float *)this = param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_2 + 8);
  return;
}

/* public: void __thiscall GmQuat::Set(class GmMat3 const &) */

void __thiscall GmQuat::Set(GmQuat *this, GmMat3 *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  float10 fVar5;

  if (0.0 < *(float *)param_1 + *(float *)(param_1 + 0x10) +
                *(float *)(param_1 + 0x20)) {
    fVar5 = (float10)__CIsqrt();
    *(float *)this = (float)fVar5 * 0.5;
    fVar3 = 0.5 / (float)fVar5;
    *(float *)(this + 4) =
        fVar3 * (*(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x14));
    *(float *)(this + 8) =
        (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x18)) * fVar3;
    *(float *)(this + 0xc) =
        (*(float *)(param_1 + 0xc) - *(float *)(param_1 + 4)) * fVar3;
    return;
  }
  uVar4 = (uint)(*(float *)param_1 < *(float *)(param_1 + 0x10) !=
                 (NAN(*(float *)param_1) || NAN(*(float *)(param_1 + 0x10))));
  if (*(float *)(param_1 + uVar4 * 0x10) < *(float *)(param_1 + 0x20) !=
      (NAN(*(float *)(param_1 + uVar4 * 0x10)) ||
       NAN(*(float *)(param_1 + 0x20)))) {
    uVar4 = 2;
  }
  iVar1 = *(int *)(&DAT_00d1a86c + uVar4 * 4);
  iVar2 = *(int *)(&DAT_00d1a86c + iVar1 * 4);
  fVar5 = (float10)__CIsqrt();
  *(float *)(this + uVar4 * 4 + 4) = (float)fVar5 * 0.5;
  fVar3 = 0.5 / (float)fVar5;
  *(float *)this = fVar3 * (*(float *)(param_1 + (iVar2 * 3 + iVar1) * 4) -
                            *(float *)(param_1 + (iVar1 * 3 + iVar2) * 4));
  *(float *)(this + iVar1 * 4 + 4) =
      (*(float *)(param_1 + (uVar4 * 3 + iVar1) * 4) +
       *(float *)(param_1 + (iVar1 * 3 + uVar4) * 4)) *
      fVar3;
  *(float *)(this + iVar2 * 4 + 4) =
      (*(float *)(param_1 + (uVar4 * 3 + iVar2) * 4) +
       *(float *)(param_1 + (iVar2 * 3 + uVar4) * 4)) *
      fVar3;
  return;
}

/* public: void __thiscall GmQuat::SetIdentity(void) */

void __thiscall GmQuat::SetIdentity(GmQuat *this)

{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

/* public: void __thiscall GmQuat::SetInverse(class GmQuat const &) */

void __thiscall GmQuat::SetInverse(GmQuat *this, GmQuat *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(float *)(this + 4) = -*(float *)(param_1 + 4);
  *(float *)(this + 8) = -*(float *)(param_1 + 8);
  *(float *)(this + 0xc) = -*(float *)(param_1 + 0xc);
  return;
}

/* public: void __thiscall GmQuat::SetMult(class GmQuat const &,class GmQuat
 * const &) */

void __thiscall GmQuat::SetMult(GmQuat *this, GmQuat *param_1, GmQuat *param_2)

{
  *(float *)this = *(float *)param_1 * *(float *)param_2 -
                   (*(float *)(param_1 + 0xc) * *(float *)(param_2 + 0xc) +
                    *(float *)(param_1 + 4) * *(float *)(param_2 + 4) +
                    *(float *)(param_1 + 8) * *(float *)(param_2 + 8));
  *(float *)(this + 4) = (*(float *)(param_1 + 8) * *(float *)(param_2 + 0xc) +
                          *(float *)param_1 * *(float *)(param_2 + 4) +
                          *(float *)(param_1 + 4) * *(float *)param_2) -
                         *(float *)(param_1 + 0xc) * *(float *)(param_2 + 8);
  *(float *)(this + 8) = (*(float *)(param_1 + 0xc) * *(float *)(param_2 + 4) +
                          *(float *)(param_1 + 8) * *(float *)param_2 +
                          *(float *)param_1 * *(float *)(param_2 + 8)) -
                         *(float *)(param_2 + 0xc) * *(float *)(param_1 + 4);
  *(float *)(this + 0xc) = (*(float *)(param_1 + 4) * *(float *)(param_2 + 8) +
                            *(float *)param_2 * *(float *)(param_1 + 0xc) +
                            *(float *)(param_2 + 0xc) * *(float *)param_1) -
                           *(float *)(param_1 + 8) * *(float *)(param_2 + 4);
  return;
}

/* public: void __thiscall GmQuat::SetRotation(float,class GmVec3 const &) */

void __thiscall GmQuat::SetRotation(GmQuat *this, float param_1,
                                    GmVec3 *param_2)

{
  float fVar1;
  float10 *extraout_ECX;
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  float10 fVar2;

  fVar2 = (float10)__CIcos((float10 *)this, in_EDX);
  *(float *)this = (float)fVar2;
  fVar2 = (float10)__CIsin(extraout_ECX, extraout_EDX);
  fVar1 = (float)fVar2;
  *(float *)(this + 4) = fVar1 * *(float *)param_2;
  *(float *)(this + 8) = *(float *)(param_2 + 4) * fVar1;
  *(float *)(this + 0xc) = fVar1 * *(float *)(param_2 + 8);
  return;
}

/* public: void __thiscall GmQuat::SetSlerp(class GmQuat,class GmQuat const
 * &,float) */

void __thiscall GmQuat::SetSlerp(GmQuat *this, float param_1, float param_2,
                                 float param_3, float param_4, float *param_5,
                                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 *extraout_ECX;
  float10 *extraout_ECX_00;
  float10 *extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  float10 fVar5;

  fVar1 = param_1 * *param_5 + param_3 * param_5[2] + param_2 * param_5[1] +
          param_4 * param_5[3];
  if (fVar1 < 0.0 != NAN(fVar1)) {
    fVar1 = -fVar1;
    param_2 = -param_2;
    param_3 = -param_3;
    param_4 = -param_4;
    param_1 = -param_1;
  }
  fVar2 = 1.0 - param_6;
  fVar3 = ABS(fVar2);
  fVar4 = ABS(param_6);
  if (fVar3 < fVar4 != (fVar3 == fVar4)) {
    fVar3 = fVar4;
  }
  if (1e-05 < fVar3 * (1.0 - fVar1)) {
    __CIacos();
    fVar5 = (float10)__CIsin(extraout_ECX, extraout_EDX);
    fVar1 = ABS((float)fVar5);
    if (fVar1 < 1e-05 == NAN(fVar1)) {
      fVar1 = 1.0 / (float)fVar5;
      fVar5 = (float10)__CIsin(extraout_ECX_00, extraout_EDX_00);
      fVar2 = (float)fVar5 * fVar1;
      fVar5 = (float10)__CIsin(extraout_ECX_01, extraout_EDX_01);
      param_6 = (float)fVar5 * fVar1;
    }
  }
  *(float *)(this + 4) = param_6 * param_5[1] + fVar2 * param_2;
  *(float *)(this + 8) = fVar2 * param_3 + param_5[2] * param_6;
  *(float *)(this + 0xc) = fVar2 * param_4 + param_5[3] * param_6;
  *(float *)this = param_6 * *param_5 + param_1 * fVar2;
  return;
}

/* public: void __thiscall GmQuat::SetSquad(class GmQuat,class GmQuat const
   &,class GmQuat const
   &,class GmQuat const &,float) */

void __thiscall GmQuat::SetSquad(GmQuat *this, float param_1, float param_2,
                                 float param_3, float param_4, float *param_5,
                                 float *param_6, float *param_7, float param_8)

{
  float local_10[4];

  SetSlerp((GmQuat *)&param_1, param_1, param_2, param_3, param_4, param_7,
           param_8);
  SetSlerp((GmQuat *)local_10, *param_5, param_5[1], param_5[2], param_5[3],
           param_6, param_8);
  param_8 = (param_8 + param_8) * (1.0 - param_8);
  SetSlerp(this, param_1, param_2, param_3, param_4, local_10, param_8);
  return;
}

/* public: void __thiscall GmQuat::SetYawPitchRoll(float,float,float) */

void __thiscall GmQuat::SetYawPitchRoll(GmQuat *this, float param_1,
                                        float param_2, float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float10 *extraout_ECX;
  float10 *extraout_ECX_00;
  float10 *extraout_ECX_01;
  float10 *extraout_ECX_02;
  float10 *extraout_ECX_03;
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;

  fVar7 = (float10)__CIsin((float10 *)this, in_EDX);
  fVar8 = (float10)__CIcos(extraout_ECX, extraout_EDX);
  fVar9 = (float10)__CIsin(extraout_ECX_00, extraout_EDX_00);
  fVar10 = (float10)__CIcos(extraout_ECX_01, extraout_EDX_01);
  fVar11 = (float10)__CIsin(extraout_ECX_02, extraout_EDX_02);
  fVar1 = (float)fVar11;
  fVar11 = (float10)__CIcos(extraout_ECX_03, extraout_EDX_03);
  fVar2 = (float)fVar11;
  fVar6 = (float)fVar7 * (float)fVar9;
  fVar4 = (float)fVar8 * (float)fVar10;
  fVar3 = (float)fVar8 * (float)fVar9;
  fVar5 = (float)fVar7 * (float)fVar10;
  *(float *)this = fVar1 * fVar6 - fVar2 * fVar4;
  *(float *)(this + 4) = -fVar6 * fVar2 - fVar1 * fVar4;
  *(float *)(this + 8) = -fVar3 * fVar1 - fVar5 * fVar2;
  *(float *)(this + 0xc) = fVar5 * fVar1 - fVar3 * fVar2;
  return;
}
