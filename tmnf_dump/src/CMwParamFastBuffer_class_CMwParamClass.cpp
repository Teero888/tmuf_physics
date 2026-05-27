// Class implementation: CMwParamFastBuffer_class_CMwParamClass

// =================================================
// Function: CMwParamFastBuffer<class_CMwParamClass>::AddValue
// =================================================
void __thiscall
CMwParamFastBuffer<class_CMwParamClass>::AddValue
          (CMwParamFastBuffer<class_CMwParamClass> *this,CMwStatsValue *param_1,float param_2)
{
{
  float fVar1;
  GmVec4 *pGVar2;
  TiXmlAttribute *unaff_ESI;
  CMwStack *in_stack_0000000c;
  
  fVar1 = param_2;
  if (*(int *)((int)param_2 + 0x18) < 0) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add(param_1,(TiXmlAttributeSet *)&param_2,unaff_ESI);
    return;
  }
  pGVar2 = CMwParamFastBuffer<class_CMwParamMwId>::GetElemFromStack
                     ((CFastBufferCat<class_GmVec4,struct_SFastCat> *)param_1,(CMwStack *)param_2);
  if (-1 < *(int *)((int)fVar1 + 0x18)) {
    CMwNod::Param_Add(*(CMwNod **)pGVar2,(CMwNod *)fVar1,in_stack_0000000c,unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: CMwParamFastBuffer<class_CMwParamClass>::SubValue
// =================================================
ulong __cdecl
CMwParamFastBuffer<class_CMwParamClass>::SubValue
          (CFastBufferCat<class_GmVec2,struct_SFastCat> *param_1,CMwStack *param_2,void *param_3)
{
{
  GmVec4 *pGVar1;
  void *unaff_ESI;
  
  if (*(int *)(param_2 + 0x18) < 0) {
    CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt
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

