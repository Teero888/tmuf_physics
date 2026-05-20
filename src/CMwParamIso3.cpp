// Class implementation: CMwParamIso3

// =================================================
// Function: CMwParamIso3::GetValue
// =================================================
GmVec3 __thiscall
CMwParamIso3::GetValue(CMwParamIso3 *this,CFuncColorGradient *param_1,float param_2)
{
{
  int iVar1;
  int iVar2;
  int *in_stack_0000000c;
  
  iVar1 = *(int *)((int)param_2 + 0x18);
  if (-1 < iVar1) {
    iVar2 = *(int *)(*(int *)((int)param_2 + 0x10) + iVar1 * 4);
    *(int *)((int)param_2 + 0x18) = iVar1 + -1;
    *in_stack_0000000c = (int)(param_1 + iVar2 * 4);
    return (GmVec3)0x0;
  }
  *in_stack_0000000c = (int)param_1;
  return (GmVec3)0x0;
}
}

