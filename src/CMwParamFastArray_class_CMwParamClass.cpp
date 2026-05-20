// Class implementation: CMwParamFastArray_class_CMwParamClass

// =================================================
// Function: CMwParamFastArray<class_CMwParamClass>::SubValue
// =================================================
ulong __cdecl
CMwParamFastArray<class_CMwParamClass>::SubValue
          (CFastBufferCat<class_GmVec2,struct_SFastCat> *param_1,CMwStack *param_2,void *param_3)
{
{
  GmVec4 *pGVar1;
  void *unaff_ESI;
  
  if (*(int *)(param_2 + 0x18) < 0) {
    CFastArray<class_CCrystalVertex*>::RemoveAt
              (param_1,*(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> **)param_3,1,
               (ulong)unaff_ESI);
    return 0;
  }
  pGVar1 = CMwParamFastBuffer<class_CMwParamMwId>::GetElemFromStack
                     ((CFastBufferCat<class_GmVec4,struct_SFastCat> *)param_1,param_2);
  if (-1 < *(int *)(param_2 + 0x18)) {
    CMwNod::Param_Sub(*(CMwNod **)pGVar1,(CMwNod *)param_2,param_3,unaff_ESI);
  }
  return 0;
}
}

