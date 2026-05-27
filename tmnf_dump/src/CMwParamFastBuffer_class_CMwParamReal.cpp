// Class implementation: CMwParamFastBuffer_class_CMwParamReal

// =================================================
// Function: CMwParamFastBuffer<class_CMwParamReal>::SetValue
// =================================================
void __thiscall
CMwParamFastBuffer<class_CMwParamReal>::SetValue
          (CMwParamFastBuffer<class_CMwParamReal> *this,CMwCmdAffectParamBool *param_1)
{
{
  GmVec4 *pGVar1;
  CMwStack *in_stack_00000008;
  undefined4 *in_stack_0000000c;
  
  if (-1 < *(int *)(in_stack_00000008 + 0x18)) {
    pGVar1 = CMwParamFastBuffer<class_CMwParamMwId>::GetElemFromStack
                       ((CFastBufferCat<class_GmVec4,struct_SFastCat> *)param_1,in_stack_00000008);
    *(undefined4 *)pGVar1 = *in_stack_0000000c;
  }
  return;
}
}

