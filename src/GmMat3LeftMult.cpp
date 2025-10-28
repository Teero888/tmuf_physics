
/* public: void __thiscall GmMat3::LeftMult(class GmMat3 const &) */

void __thiscall GmMat3::LeftMult(GmMat3 *this, GmMat3 *param_1)

{
  GmMat3 *extraout_ECX;
  GmMat3 *this_00;
  GmMat3 local_24[36];

  Set(local_24, this);
  SetMult(this_00, param_1, extraout_ECX);
  return;
}
