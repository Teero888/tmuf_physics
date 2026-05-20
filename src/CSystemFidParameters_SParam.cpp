// Class implementation: CSystemFidParameters_SParam

// =================================================
// Function: CSystemFidParameters::SParam::SParam
// =================================================
void __thiscall
CSystemFidParameters::SParam::SParam
          (SParam *this,SParam *param_1,EParamType param_2,ulong *param_3,int param_4)
{
{
  *(SParam **)(this + 4) = param_1;
  *(undefined ***)this = vftable;
  *(EParamType *)(this + 8) = param_2;
  *(ulong **)(this + 0xc) = param_3;
  return;
}
}

// =================================================
// Function: CSystemFidParameters::SParam::~SParam
// =================================================
void __thiscall CSystemFidParameters::SParam::~SParam(SParam *this,SParam *param_1)
{
{
  *(undefined ***)this = vftable;
  return;
}
}

