
/* public: void __thiscall GmMat3::SetRotateQuarterY(unsigned long) */

void __thiscall GmMat3::SetRotateQuarterY(GmMat3 *this, ulong param_1)

{
  undefined4 uVar1;
  float fVar2;

  uVar1 = *(undefined4 *)(&DAT_00bbd760 + (param_1 & 3) * 4);
  fVar2 = *(float *)(&DAT_00bbd760 + (param_1 - 1 & 3) * 4);
  *(undefined4 *)this = uVar1;
  *(undefined4 *)(this + 4) = 0;
  *(float *)(this + 8) = fVar2;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0x3f800000;
  *(undefined4 *)(this + 0x14) = 0;
  *(float *)(this + 0x18) = -fVar2;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = uVar1;
  return;
}
