
/* public: void __thiscall GmMat3::SetTranspose(class GmMat3 const &) */

void __thiscall GmMat3::SetTranspose(GmMat3 *this, GmMat3 *param_1)

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
  return;
}
