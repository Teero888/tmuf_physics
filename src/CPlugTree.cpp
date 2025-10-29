
/* public: void __thiscall CPlugTree::SetLocation(class GmTransQuat const &) */

void __thiscall CPlugTree::SetLocation(CPlugTree *this, GmTransQuat *param_1)

{
  GmIso4::Set((GmIso4 *)(this + 0x5c), param_1);
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  return;
}
