// Class implementation: CMwParamClass

// =================================================
// Function: CMwParamClass::GetValue
// =================================================
GmVec3 __thiscall
CMwParamClass::GetValue(CMwParamClass *this,CFuncColorGradient *param_1,float param_2)
{
{
  ulong uVar1;
  CMwValueStd *unaff_retaddr;
  CMwStack *in_stack_0000000c;
  
  if (*(int *)((int)param_2 + 0x18) < 0) {
    *(undefined4 *)in_stack_0000000c = *(undefined4 *)param_1;
    return (GmVec3)0x0;
  }
  uVar1 = CMwNod::Param_Get(*(CMwNod **)param_1,(CMwNod *)param_2,in_stack_0000000c,unaff_retaddr);
  return SUB41(uVar1,0);
}
}

// =================================================
// Function: CMwParamClass::SetValue
// =================================================
void __thiscall CMwParamClass::SetValue(CMwParamClass *this,CMwCmdAffectParamBool *param_1)
{
{
  CFastStringInt *unaff_retaddr;
  CMwNod *in_stack_00000008;
  CFastString *in_stack_0000000c;
  
  if (*(int *)(in_stack_00000008 + 0x18) < 0) {
    *(CFastString **)param_1 = in_stack_0000000c;
    return;
  }
  CMwNod::Param_Set(*(CMwNod **)param_1,in_stack_00000008,in_stack_0000000c,unaff_retaddr);
  return;
}
}

