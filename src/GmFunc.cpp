
/* public: static unsigned long __cdecl GmFunc::Mod(int,int) */

ulong __cdecl GmFunc::Mod(int param_1, int param_2)

{
  ulong uVar1;

  uVar1 = param_1 % param_2;
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + param_2;
  }
  return uVar1;
}

/* public: static unsigned char __cdecl GmFunc::RealToNat7(float,float,float) */

uchar __cdecl GmFunc::RealToNat7(float param_1, float param_2, float param_3)

{
  float fVar1;

  fVar1 = ((param_1 - param_2) / (param_3 - param_2)) * 127.0;
  if (fVar1 < 0.0 == (fVar1 == 0.0)) {
    if (127.0 <= fVar1) {
      fVar1 = 127.0;
    }
  } else {
    fVar1 = 0.0;
  }
  param_2._0_1_ = (uchar)(int)ROUND(fVar1);
  return param_2._0_1_;
}
