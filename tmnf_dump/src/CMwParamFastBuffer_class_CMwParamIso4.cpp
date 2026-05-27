// Class implementation: CMwParamFastBuffer_class_CMwParamIso4

// =================================================
// Function: CMwParamFastBuffer<class_CMwParamIso4>::GetValue
// =================================================
GmVec3 __thiscall
CMwParamFastBuffer<class_CMwParamIso4>::GetValue
          (CMwParamFastBuffer<class_CMwParamIso4> *this,CFuncColorGradient *param_1,float param_2)
{
{
  int iVar1;
  int iVar2;
  GmVec4 *pGVar3;
  int *in_stack_0000000c;
  
  if (*(int *)((int)param_2 + 0x18) < 0) {
    *in_stack_0000000c = (int)param_1;
    return (GmVec3)0x0;
  }
  pGVar3 = CMwParamFastArray<class_CMwParamIso4>::GetElemFromStack
                     ((CFastBufferCat<class_GmVec4,struct_SFastCat> *)param_1,(CMwStack *)param_2);
  iVar1 = *(int *)((int)param_2 + 0x18);
  if (-1 < iVar1) {
    iVar2 = *(int *)(*(int *)((int)param_2 + 0x10) + iVar1 * 4);
    *(int *)((int)param_2 + 0x18) = iVar1 + -1;
    *in_stack_0000000c = (int)(pGVar3 + iVar2 * 4);
    return (GmVec3)0x0;
  }
  *in_stack_0000000c = (int)pGVar3;
  return (GmVec3)0x0;
}
}

// =================================================
// Function: CMwParamFastBuffer<class_CMwParamIso4>::SetValue
// =================================================
void __thiscall
CMwParamFastBuffer<class_CMwParamIso4>::SetValue
          (CMwParamFastBuffer<class_CMwParamIso4> *this,CMwCmdAffectParamBool *param_1)
{
{
  int iVar1;
  GmVec4 *pGVar2;
  int iVar3;
  CMwStack *in_stack_00000008;
  undefined4 *in_stack_0000000c;
  
  if (-1 < *(int *)(in_stack_00000008 + 0x18)) {
    pGVar2 = CMwParamFastArray<class_CMwParamIso4>::GetElemFromStack
                       ((CFastBufferCat<class_GmVec4,struct_SFastCat> *)param_1,in_stack_00000008);
    iVar3 = *(int *)(in_stack_00000008 + 0x18);
    if (-1 < iVar3) {
      iVar1 = *(int *)(*(int *)(in_stack_00000008 + 0x10) + iVar3 * 4);
      *(int *)(in_stack_00000008 + 0x18) = iVar3 + -1;
      *(undefined4 *)(pGVar2 + iVar1 * 4) = *in_stack_0000000c;
      return;
    }
    for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined4 *)pGVar2 = *in_stack_0000000c;
      in_stack_0000000c = in_stack_0000000c + 1;
      pGVar2 = pGVar2 + 4;
    }
  }
  return;
}
}

