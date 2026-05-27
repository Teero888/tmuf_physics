// Class implementation: CFastBufferCat_class_CHmsCorpusLight_struct_SFastCat

// =================================================
// Function: struct_SFastCat>::DeleteAll
// =================================================
void __thiscall
CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat>::DeleteAll
          (void *this,CFastArray<class_CCrystalEdge*> *param_1)
{
{
  CFastArray<class_CCrystalEdge*> *unaff_ESI;
  CFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat> *in_stack_00000008;
  
  CFastBuffer<class_CPlugBitmapPackInput*>::DeleteAll((void *)((int)this + 0xc),unaff_ESI);
  CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::ResetCatDescs(this,in_stack_00000008);
  return;
}
}

// =================================================
// Function: struct_SFastCat>::ResetCat
// =================================================
void __thiscall
CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat>::ResetCat
          (void *this,
          CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
          *param_1,ulong param_2)
{
{
  ulong uVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_ESI);
  uVar1 = *(ulong *)(pSVar3 + 4);
  if (uVar1 != 0) {
    CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt
              ((void *)((int)this + 0xc),
               *(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> **)pSVar3,uVar1,
               unaff_EBP);
    pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                       (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_EBX);
    *(undefined4 *)(pSVar3 + 4) = 0;
    while (param_2 = param_2 + 1, param_2 < pCVar2) {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                         (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                          unaff_retaddr);
      *(ulong *)pSVar3 = *(int *)pSVar3 - uVar1;
    }
  }
  return;
}
}

