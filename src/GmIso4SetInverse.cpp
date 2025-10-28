
/* public: void __thiscall GmIso4::SetInverse(class GmIso4 const &) */

void __thiscall GmIso4::SetInverse(GmIso4 *this, GmIso4 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x14);
  *(float *)(this + 0x24) = -*(float *)(param_1 + 0x24);
  *(float *)(this + 0x28) = -*(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((GmVec3 *)(this + 0x24), (GmMat3 *)this);
  return;
}
