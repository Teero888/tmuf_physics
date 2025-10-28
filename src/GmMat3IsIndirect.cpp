
/* public: unsigned long __thiscall GmMat3::IsIndirect(void)const  */

ulong __thiscall GmMat3::IsIndirect(GmMat3 *this)

{
  float fVar1;

  fVar1 =
      *(float *)(this + 0x20) *
          (*(float *)(this + 0x10) * *(float *)this -
           *(float *)(this + 0xc) * *(float *)(this + 4)) +
      *(float *)(this + 0x18) *
          (*(float *)(this + 0x14) * *(float *)(this + 4) -
           *(float *)(this + 0x10) * *(float *)(this + 8)) +
      *(float *)(this + 0x1c) * (*(float *)(this + 8) * *(float *)(this + 0xc) -
                                 *(float *)(this + 0x14) * *(float *)this);
  if (fVar1 < 0.0 != NAN(fVar1)) {
    return 1;
  }
  return 0;
}
