// Class implementation: CMwParamVec3

// =================================================
// Function: CMwParamVec3::GetValue
// =================================================
GmVec3 __thiscall
CMwParamVec3::GetValue(CMwParamVec3 *this,CFuncColorGradient *param_1,float param_2)
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

// =================================================
// Function: CMwParamVec3::SetValue
// =================================================
void __thiscall CMwParamVec3::SetValue(CMwParamVec3 *this,CMwCmdAffectParamBool *param_1)
{
{
  int iVar1;
  int iVar2;
  int in_stack_00000008;
  undefined4 *in_stack_0000000c;
  
  iVar1 = *(int *)(in_stack_00000008 + 0x18);
  if (-1 < iVar1) {
    iVar2 = *(int *)(*(int *)(in_stack_00000008 + 0x10) + iVar1 * 4);
    *(int *)(in_stack_00000008 + 0x18) = iVar1 + -1;
    *(undefined4 *)(param_1 + iVar2 * 4) = *in_stack_0000000c;
    return;
  }
  *(undefined4 *)param_1 = *in_stack_0000000c;
  *(undefined4 *)(param_1 + 4) = in_stack_0000000c[1];
  *(undefined4 *)(param_1 + 8) = in_stack_0000000c[2];
  return;
}
}

