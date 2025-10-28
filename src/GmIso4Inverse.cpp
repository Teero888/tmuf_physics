
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
