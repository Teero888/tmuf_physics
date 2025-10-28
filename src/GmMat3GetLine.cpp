
/* public: void __thiscall GmMat3::GetLine(unsigned long,class GmVec3 &)const */

void __thiscall GmMat3::GetLine(GmMat3 *this, ulong param_1, GmVec3 *param_2)

{
  *(undefined4 *)param_2 = *(undefined4 *)(this + param_1 * 4);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(this + param_1 * 4 + 0xc);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(this + param_1 * 4 + 0x18);
  return;
}
