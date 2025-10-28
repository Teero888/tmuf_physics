
/* public: void __thiscall GmIso4::GetDir(class GmVec3 &)const  */

void __thiscall GmIso4::GetDir(GmIso4 *this, GmVec3 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;

  uVar1 = *(undefined4 *)(this + 0x14);
  uVar2 = *(undefined4 *)(this + 0x20);
  *(undefined4 *)param_1 = *(undefined4 *)(this + 8);
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 8) = uVar2;
  return;
}
