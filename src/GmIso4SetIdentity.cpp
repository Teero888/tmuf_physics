
/* public: void __thiscall GmIso4::SetIdentity(void) */

void __thiscall GmIso4::SetIdentity(GmIso4 *this)

{
  GmMat3::SetIdentity((GmMat3 *)this);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  return;
}
