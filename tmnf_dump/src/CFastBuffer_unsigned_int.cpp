// Class implementation: CFastBuffer_unsigned_int

// =================================================
// Function: CFastBuffer<unsigned_int>::RemoveIfFound
// =================================================
void __thiscall
CFastBuffer<unsigned_int>::RemoveIfFound
          (void *this,CFastBuffer<unsigned_int> *param_1,uint *param_2)
{
{
  CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *pCVar1;
  GxTexCoordSet *unaff_ESI;
  ulong unaff_retaddr;
  
  pCVar1 = (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     (this,(CFastArray<class_GxTexCoordSet> *)param_1,unaff_ESI);
  if (pCVar1 != (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0xffffffff) {
    CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt(this,pCVar1,1,unaff_retaddr);
  }
  return;
}
}

