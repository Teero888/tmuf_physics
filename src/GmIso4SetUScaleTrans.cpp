
/* public: void __thiscall GmIso4::SetUScaleTrans(float,class GmVec3 const &) */

void __thiscall GmIso4::SetUScaleTrans(GmIso4 *this, float param_1,
                                       GmVec3 *param_2)

{
  *(float *)(this + 0x20) = param_1;
  *(float *)(this + 0x10) = param_1;
  *(float *)this = param_1;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_2 + 8);
  return;
}
