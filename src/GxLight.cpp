// Class implementation: GxLight

// =================================================
// Function: GxLight::GetIntensRGB
// =================================================
GmVec3 __thiscall GxLight::GetIntensRGB(GxLight *this,GxLight *param_1)
{
{
  float fVar1;
  
  fVar1 = *(float *)(this + 0x24);
  *(float *)param_1 = fVar1 * *(float *)(this + 0x18);
  *(float *)(param_1 + 4) = *(float *)(this + 0x1c) * fVar1;
  *(float *)(param_1 + 8) = fVar1 * *(float *)(this + 0x20);
  return SUB41(param_1,0);
}
}

// =================================================
// Function: GxLight::SetBaseRGB
// =================================================
void __thiscall GxLight::SetBaseRGB(GxLight *this,GxLight *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  
  *(undefined4 *)(this + 0x18) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 8);
  fVar1 = *(float *)(this + 0x28) * *(float *)(this + 0x24);
  *(float *)(this + 0x2c) = fVar1 * *(float *)(this + 0x18);
  *(float *)(this + 0x30) = *(float *)(this + 0x1c) * fVar1;
  *(float *)(this + 0x34) = fVar1 * *(float *)(this + 0x20);
  return;
}
}

// =================================================
// Function: GxLight::SetIntensity
// =================================================
void __thiscall GxLight::SetIntensity(GxLight *this,GxLight *param_1,float param_2)
{
{
  float fVar1;
  
  *(GxLight **)(this + 0x24) = param_1;
  fVar1 = (float)param_1 * *(float *)(this + 0x28);
  *(float *)(this + 0x2c) = fVar1 * *(float *)(this + 0x18);
  *(float *)(this + 0x30) = *(float *)(this + 0x1c) * fVar1;
  *(float *)(this + 0x34) = fVar1 * *(float *)(this + 0x20);
  return;
}
}

