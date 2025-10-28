
/* public: void __thiscall GmIso4::SetNUScaleTrans(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall GmIso4::SetNUScaleTrans(GmIso4 *this, GmVec3 *param_1,
                                        GmVec3 *param_2)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 8);
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
