
/* public: void __thiscall GmVec3::SetFromBGRA(unsigned char const *,unsigned
 * long) */

void __thiscall GmVec3::SetFromBGRA(GmVec3 *this, uchar *param_1, ulong param_2)

{
  *(float *)(this + 8) = (float)(uint)*param_1 * 0.003921569;
  *(float *)(this + 4) = (float)(uint)param_1[1] * 0.003921569;
  *(float *)this = (float)(uint)param_1[2] * 0.003921569;
  return;
}
