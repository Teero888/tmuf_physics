
/* public: void __thiscall GmIso4::SetColumn(unsigned long,class GmVec4 const &)
 */

void __thiscall GmIso4::SetColumn(GmIso4 *this, ulong param_1, GmVec4 *param_2)

{
  *(undefined4 *)(this + param_1 * 0xc) = *(undefined4 *)param_2;
  *(undefined4 *)(this + param_1 * 0xc + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + param_1 * 0xc + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(this + param_1 * 4 + 0x24) = *(undefined4 *)(param_2 + 0xc);
  return;
}
