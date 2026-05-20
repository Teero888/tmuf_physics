// Class implementation: CFastBufferCat_struct_CPlugBitmap_SSpecularHighlight_struct_CPlugBitmap_SSpecularSubMapCat

// =================================================
// Function: ResetCat
// =================================================
void __thiscall
CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>::
ResetCat(void *this,
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
  pSVar3 = CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_ESI);
  uVar1 = *(ulong *)(pSVar3 + 4);
  if (uVar1 != 0) {
    CFastBuffer<class_GmQuat>::RemoveAt
              ((void *)((int)this + 0xc),
               *(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> **)pSVar3,uVar1,
               unaff_EBP);
    pSVar3 = CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                       (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_EBX);
    *(undefined4 *)(pSVar3 + 4) = 0;
    while (param_2 = param_2 + 1, param_2 < pCVar2) {
      pSVar3 = CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                         (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                          unaff_retaddr);
      *(ulong *)pSVar3 = *(int *)pSVar3 - uVar1;
    }
  }
  return;
}
}

// =================================================
// Function: SetParsingCat
// =================================================
ulong __thiscall
CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>::
SetParsingCat(void *this,CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *param_1,
             ulong param_2,ulong param_3)
{
{
  SCasterCat *pSVar1;
  ulong uVar2;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  uint uVar3;
  uint in_stack_00000010;
  uint in_stack_00000014;
  
  *(CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> **)((int)this + 0x18) = param_1
  ;
  *(ulong *)((int)this + 0x1c) = param_2;
  pSVar1 = CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_EDI);
  *(int *)((int)this + 0x20) = *(int *)pSVar1 * 0x10 + *(int *)((int)this + 0x10);
  pSVar1 = CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_ESI);
  uVar2 = *(ulong *)(pSVar1 + 4);
  uVar3 = 1;
  if (1 < in_stack_00000010) {
    do {
      pSVar1 = CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                         (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_1 + uVar3),
                          unaff_EBP);
      uVar2 = uVar2 + *(int *)(pSVar1 + 4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < in_stack_00000014);
  }
  return uVar2;
}
}

