
/* public: void __thiscall GmIso4::SetTranslation(class GmVec3 const &) */

void __thiscall GmIso4::SetTranslation(GmIso4 *this, GmVec3 *param_1)

{
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 8);
  return;
}
