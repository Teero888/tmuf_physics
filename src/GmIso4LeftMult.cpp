
/* public: void __thiscall GmIso4::LeftMult(class GmIso4 const &) */

void __thiscall GmIso4::LeftMult(GmIso4 *this, GmIso4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_30[12];

  puVar2 = (undefined4 *)this;
  puVar3 = local_30;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  SetMult(this, param_1, (GmIso4 *)local_30);
  return;
}
