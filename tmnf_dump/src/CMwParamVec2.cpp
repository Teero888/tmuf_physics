// Class implementation: CMwParamVec2

// =================================================
// Function: CMwParamVec2::GetValue
// =================================================
GmVec3 __thiscall
CMwParamVec2::GetValue(CMwParamVec2 *this,CFuncColorGradient *param_1,float param_2)
{
{
  int iVar1;
  int iVar2;
  float10 fVar3;
  int *in_stack_0000000c;
  
  iVar1 = *(int *)((int)param_2 + 0x18);
  if (iVar1 < 0) {
    *in_stack_0000000c = (int)param_1;
    return (GmVec3)0x0;
  }
  iVar2 = *(int *)(*(int *)((int)param_2 + 0x10) + iVar1 * 4);
  *(int *)((int)param_2 + 0x18) = iVar1 + -1;
  if (iVar2 == -1) {
    fVar3 = (float10)func_0x009c1b40();
    *in_stack_0000000c = (int)(in_stack_0000000c + 1);
    in_stack_0000000c[1] = (int)(float)fVar3;
    return (GmVec3)0x0;
  }
  *in_stack_0000000c = (int)(param_1 + iVar2 * 4);
  return (GmVec3)0x0;
}
}

