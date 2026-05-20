// Class implementation: CFuncColorGradient

// =================================================
// Function: CFuncColorGradient::GetValue
// =================================================
GmVec3 __thiscall
CFuncColorGradient::GetValue(CFuncColorGradient *this,CFuncColorGradient *param_1,float param_2)
{
{
  float fVar1;
  GmVec3 GVar2;
  
  if (NAN(param_2) || param_2 < 0.0 == (param_2 == 0.0)) {
    if (!NAN(param_2) && 1.0 < param_2 != (param_2 == 1.0)) {
      param_2 = 1.0;
    }
  }
  else {
    param_2 = 0.0;
  }
  GVar2 = SUB41(param_1,0);
  if (*(float *)(this + 0x44) <= param_2) {
    if (*(float *)(this + 0x48) <= param_2) {
      fVar1 = (param_2 - *(float *)(this + 0x48)) / (1.0 - *(float *)(this + 0x48));
      *(float *)param_1 =
           fVar1 * (*(float *)(this + 0x38) - *(float *)(this + 0x2c)) + *(float *)(this + 0x2c);
      *(float *)(param_1 + 4) =
           (*(float *)(this + 0x3c) - *(float *)(this + 0x30)) * fVar1 + *(float *)(this + 0x30);
      *(float *)(param_1 + 8) =
           fVar1 * (*(float *)(this + 0x40) - *(float *)(this + 0x34)) + *(float *)(this + 0x34);
      return GVar2;
    }
    fVar1 = (param_2 - *(float *)(this + 0x44)) /
            (*(float *)(this + 0x48) - *(float *)(this + 0x44));
    *(float *)param_1 =
         fVar1 * (*(float *)(this + 0x2c) - *(float *)(this + 0x20)) + *(float *)(this + 0x20);
    *(float *)(param_1 + 4) =
         (*(float *)(this + 0x30) - *(float *)(this + 0x24)) * fVar1 + *(float *)(this + 0x24);
    *(float *)(param_1 + 8) =
         fVar1 * (*(float *)(this + 0x34) - *(float *)(this + 0x28)) + *(float *)(this + 0x28);
    return GVar2;
  }
  fVar1 = param_2 / *(float *)(this + 0x44);
  *(float *)param_1 =
       fVar1 * (*(float *)(this + 0x20) - *(float *)(this + 0x14)) + *(float *)(this + 0x14);
  *(float *)(param_1 + 4) =
       (*(float *)(this + 0x24) - *(float *)(this + 0x18)) * fVar1 + *(float *)(this + 0x18);
  *(float *)(param_1 + 8) =
       fVar1 * (*(float *)(this + 0x28) - *(float *)(this + 0x1c)) + *(float *)(this + 0x1c);
  return GVar2;
}
}

