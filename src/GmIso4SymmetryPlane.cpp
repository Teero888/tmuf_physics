
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
