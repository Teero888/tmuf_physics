
/* public: void __thiscall GmVec3::SetInverseTranslation(class GmIso4 const &)
 */

void __thiscall GmVec3::SetInverseTranslation(GmVec3 *this, GmIso4 *param_1)

{
  *(float *)this = (-*(float *)(param_1 + 0x24) * *(float *)param_1 -
                    *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x28)) -
                   *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x2c);
  *(float *)(this + 4) =
      (-*(float *)(param_1 + 0x24) * *(float *)(param_1 + 4) -
       *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x28)) -
      *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x2c);
  *(float *)(this + 8) =
      (-*(float *)(param_1 + 0x24) * *(float *)(param_1 + 8) -
       *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x28)) -
      *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x2c);
  return;
}
