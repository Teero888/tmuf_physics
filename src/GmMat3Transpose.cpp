
/* public: void __thiscall GmMat3::Transpose(void) */

void __thiscall GmMat3::Transpose(GmMat3 *this)

{
  undefined4 uVar1;

  uVar1 = *(undefined4 *)(this + 4);
  *(undefined4 *)(this + 4) = *(undefined4 *)(this + 0xc);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = *(undefined4 *)(this + 8);
  *(undefined4 *)(this + 8) = *(undefined4 *)(this + 0x18);
  *(undefined4 *)(this + 0x18) = uVar1;
  uVar1 = *(undefined4 *)(this + 0x14);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 0x1c);
  *(undefined4 *)(this + 0x1c) = uVar1;
  return;
}
