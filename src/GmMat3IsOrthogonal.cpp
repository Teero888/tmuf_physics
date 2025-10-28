
/* public: unsigned long __thiscall GmMat3::IsOrthogonal(void)const  */

ulong __thiscall GmMat3::IsOrthogonal(GmMat3 *this)

{
  float fVar1;

  if (((ABS(*(float *)(this + 0x14) * *(float *)(this + 8) +
            *(float *)(this + 0xc) * *(float *)this +
            *(float *)(this + 0x10) * *(float *)(this + 4)) < 0.001) &&
       (fVar1 = ABS(*(float *)(this + 0x20) * *(float *)(this + 8) +
                    *(float *)(this + 0x18) * *(float *)this +
                    *(float *)(this + 0x1c) * *(float *)(this + 4)),
        fVar1 < 0.001 != NAN(fVar1))) &&
      (ABS(*(float *)(this + 0x20) * *(float *)(this + 0x14) +
           *(float *)(this + 0xc) * *(float *)(this + 0x18) +
           *(float *)(this + 0x1c) * *(float *)(this + 0x10)) < 0.001)) {
    return 1;
  }
  return 0;
}
