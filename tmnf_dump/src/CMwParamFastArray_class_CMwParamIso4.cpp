// Class implementation: CMwParamFastArray_class_CMwParamIso4

// =================================================
// Function: CMwParamFastArray<class_CMwParamIso4>::GetElemFromStack
// =================================================
GmVec4 * __cdecl
CMwParamFastArray<class_CMwParamIso4>::GetElemFromStack
          (CFastBufferCat<class_GmVec4,struct_SFastCat> *param_1,CMwStack *param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  ulong unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000000c;
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (*(int *)(*(int *)(param_2 + 0x14) + iVar1 * 4) == 2) {
    CMwStack::WatchNextNameIndex
              (param_2,(CMwStack *)&param_2,*(ulong **)(param_1 + 4),*(CMwNod ***)param_1,unaff_ESI)
    ;
    pSVar3 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
             ::operator[](param_1,in_stack_0000000c,unaff_retaddr);
    return (GmVec4 *)pSVar3;
  }
  pCVar2 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
            (*(int *)(param_2 + 0x10) + iVar1 * 4);
  *(int *)(param_2 + 0x18) = iVar1 + -1;
  pSVar3 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>::
           operator[](param_1,pCVar2,unaff_ESI);
  return (GmVec4 *)pSVar3;
}
}

