
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
