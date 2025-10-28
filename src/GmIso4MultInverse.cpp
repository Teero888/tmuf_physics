
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
