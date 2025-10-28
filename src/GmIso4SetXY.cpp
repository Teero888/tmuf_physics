
/* public: void __thiscall GmIso4::SetXY(class GmIso3 const &) */

void __thiscall GmIso4::SetXY(GmIso4 *this, GmIso3 *param_1)

{
  undefined4 uVar1;

  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = 0;
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x10) = uVar1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0x3f800000;
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x28) = uVar1;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}
