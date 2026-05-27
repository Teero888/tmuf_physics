// Class implementation: CFuncEnvelope

// =================================================
// Function: CFuncEnvelope::GetValue
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

GmVec3 __thiscall
CFuncEnvelope::GetValue(CFuncEnvelope *this,CFuncColorGradient *param_1,float param_2)
{
{
  GmVec3 extraout_AL;
  GmVec3 extraout_AL_00;
  
  if (ABS(*(float *)(this + 0x30)) <= _DAT_00b59b68) {
    return (GmVec3)0x0;
  }
  if (*(int *)(this + 0x34) == 0) {
    __CIsin();
    return extraout_AL;
  }
  __CIcos();
  return extraout_AL_00;
}
}

