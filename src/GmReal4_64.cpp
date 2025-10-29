
/* public: void __thiscall GmReal4_64::GetClipFlag(struct GmClipFlag_HalfCube
 * &)const  */

void __thiscall GmReal4_64::GetClipFlag(GmReal4_64 *this,
                                        GmClipFlag_HalfCube *param_1)

{
  double dVar1;
  uint uVar2;

  *(undefined4 *)param_1 = 0;
  dVar1 = *(double *)(this + 0x10);
  *(uint *)param_1 = (uint)(dVar1 < 0.0);
  uVar2 =
      (uint)(*(double *)(this + 0x18) < *(double *)(this + 0x10) !=
             (NAN(*(double *)(this + 0x18)) || NAN(*(double *)(this + 0x10)))) *
              2 &
          2 ^
      (uint)(dVar1 < 0.0);
  *(uint *)param_1 = uVar2;
  uVar2 =
      (uint)(*(double *)(this + 8) < -*(double *)(this + 0x18)) * 4 & 4 ^ uVar2;
  *(uint *)param_1 = uVar2;
  uVar2 =
      (uint)(*(double *)(this + 0x18) < *(double *)(this + 8) !=
             (NAN(*(double *)(this + 0x18)) || NAN(*(double *)(this + 8)))) *
              8 &
          8 ^
      uVar2;
  *(uint *)param_1 = uVar2;
  uVar2 = (uint)(*(double *)this < -*(double *)(this + 0x18)) << 4 ^ uVar2;
  *(uint *)param_1 = uVar2;
  if (*(double *)(this + 0x18) < *(double *)this !=
      (NAN(*(double *)(this + 0x18)) || NAN(*(double *)this))) {
    *(uint *)param_1 = uVar2 ^ 0x20;
    return;
  }
  *(uint *)param_1 = uVar2;
  return;
}
