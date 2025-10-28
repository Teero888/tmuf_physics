
/* public: void __thiscall GmVec3::MultInverse(class GmIso4 const &) */

void __thiscall GmVec3::MultInverse(GmVec3 *this, GmIso4 *param_1)

{
  float local_c;
  float local_8;
  float local_4;

  local_c = *(float *)this - *(float *)(param_1 + 0x24);
  local_8 = *(float *)(this + 4) - *(float *)(param_1 + 0x28);
  local_4 = *(float *)(this + 8) - *(float *)(param_1 + 0x2c);
  MultTranspose((GmVec3 *)&local_c, (GmMat3 *)param_1);
  *(float *)this = local_c;
  *(float *)(this + 4) = local_8;
  *(float *)(this + 8) = local_4;
  return;
}
