
/* public: void __thiscall GmVec3::SetMult(class GmVec3 const &,class GmMat3
 * const &) */

void __thiscall GmVec3::SetMult(GmVec3 *this, GmVec3 *param_1, GmMat3 *param_2)

{
  *(float *)this = *(float *)(param_2 + 8) * *(float *)(param_1 + 8) +
                   *(float *)param_1 * *(float *)param_2 +
                   *(float *)(param_2 + 4) * *(float *)(param_1 + 4);
  *(float *)(this + 4) = *(float *)(param_2 + 0x14) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0xc) * *(float *)param_1;
  *(float *)(this + 8) = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0x18) * *(float *)param_1;
  return;
}

/* public: void __thiscall GmVec3::SetMult(class GmVec3 const &,class GmIso4
 * const &) */

void __thiscall GmVec3::SetMult(GmVec3 *this, GmVec3 *param_1, GmIso4 *param_2)

{
  *(float *)this = *(float *)(param_2 + 8) * *(float *)(param_1 + 8) +
                   *(float *)param_1 * *(float *)param_2 +
                   *(float *)(param_2 + 4) * *(float *)(param_1 + 4) +
                   *(float *)(param_2 + 0x24);
  *(float *)(this + 4) = *(float *)(param_2 + 0x14) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0xc) * *(float *)param_1 +
                         *(float *)(param_2 + 0x28);
  *(float *)(this + 8) = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0x18) * *(float *)param_1 +
                         *(float *)(param_2 + 0x2c);
  return;
}

/* public: void __thiscall GmVec3::SetMult(class GmVec3 const &,class GmMat4
 * const &) */

void __thiscall GmVec3::SetMult(GmVec3 *this, GmVec3 *param_1, GmMat4 *param_2)

{
  float fVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_20 = *(undefined4 *)param_1;
  local_1c = *(undefined4 *)(param_1 + 4);
  local_18 = *(undefined4 *)(param_1 + 8);
  local_14 = 0x3f800000;
  GmVec4::SetMult((GmVec4 *)&local_10, (GmVec4 *)&local_20, param_2);
  fVar1 = 1.0 / ABS(local_4);
  *(float *)this = fVar1 * local_10;
  *(float *)(this + 4) = local_c * fVar1;
  *(float *)(this + 8) = fVar1 * local_8;
  return;
}
