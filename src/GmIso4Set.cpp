
/* public: void __thiscall GmIso4::Set(class GmMat3 const &,class GmVec3 const
 * &) */

void __thiscall GmIso4::Set(GmIso4 *this, GmMat3 *param_1, GmVec3 *param_2)

{
  GmMat3::Set((GmMat3 *)this, param_1);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_2 + 8);
  return;
}

/* public: void __thiscall GmIso4::Set(class GmTransQuat const &) */

void __thiscall GmIso4::Set(GmIso4 *this, GmTransQuat *param_1)

{
  GmMat3::Set((GmMat3 *)this, *(float *)param_1, *(float *)(param_1 + 4),
              *(float *)(param_1 + 8), *(float *)(param_1 + 0xc));
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x18);
  return;
}
