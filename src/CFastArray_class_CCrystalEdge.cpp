// Class implementation: CFastArray_class_CCrystalEdge

// =================================================
// Function: >::RemoveElems
// =================================================
void __thiscall
CFastArray<class_CCrystalEdge*>::RemoveElems
          (void *this,CFastArray<class_CCrystalEdge*> *param_1,CCrystalEdge **param_2,ulong param_3)
{
{
  CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *pCVar1;
  ulong unaff_ESI;
  ulong unaff_retaddr;
  
  pCVar1 = (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     (this,(CFastArray<class_GxTexCoordSet> *)param_1,(GxTexCoordSet *)param_2);
  CFastArray<class_CCrystalVertex*>::RemoveAt(this,pCVar1,unaff_ESI,unaff_retaddr);
  return;
}
}

