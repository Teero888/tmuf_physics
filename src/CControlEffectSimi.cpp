// Class implementation: CControlEffectSimi

// =================================================
// Function: CControlEffectSimi::GetValue
// =================================================
GmVec3 __thiscall
CControlEffectSimi::GetValue(CControlEffectSimi *this,CFuncColorGradient *param_1,float param_2)
{
{
  GmVec3 GVar1;
  undefined **local_5c;
  undefined4 local_58;
  undefined4 local_54;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00ac9288;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_5c = SParamEffectSimi::vftable;
  local_4 = 0;
  local_58 = 0;
  local_54 = 0;
  GVar1 = GetValue(this,param_1,(float)&local_5c);
  ExceptionList = local_10;
  return GVar1;
}
}

