// Class implementation: CGameRemoteBufferPool

// =================================================
// Function: CGameRemoteBufferPool::GetOrCreateRemoteBuffer
// =================================================
CGameRemoteBuffer * __thiscall
CGameRemoteBufferPool::GetOrCreateRemoteBuffer
          (CGameRemoteBufferPool *this,CGameRemoteBufferPool *param_1,
          CGameMasterServerRequestParams *param_2)
{
{
  CFastString CVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  CGameRemoteBuffer *pCVar3;
  
  if (*(int **)(this + 0x14) == (int *)0x0) {
    return (CGameRemoteBuffer *)0x0;
  }
  puVar2 = (undefined4 *)(**(code **)(**(int **)(this + 0x14) + 0x90))();
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(param_1,&stack0xfffffff8);
    if (param_1 != (CGameRemoteBufferPool *)0xffffffff) {
      pCVar3 = (CGameRemoteBuffer *)0x0;
      CVar1 = CFastMapTable<unsigned_long>::GetElem
                        ((CFastMapTable<unsigned_long> *)(this + 0x18),
                         (CVirtualisedBuffer<class_CFastString> *)param_1,(ulong)&stack0xfffffff8);
      if (CONCAT31(extraout_var,CVar1) == 0) {
        pCVar3 = (CGameRemoteBuffer *)(**(code **)(*(int *)this + 0x78))(param_1);
        CFastMapTable<class_CGameRemoteBuffer*>::Add
                  ((CFastMapTable<class_CGameRemoteBuffer*> *)(this + 0x18),
                   (TiXmlAttributeSet *)&stack0xfffffff8,(TiXmlAttribute *)param_1);
      }
      return pCVar3;
    }
  }
  return (CGameRemoteBuffer *)0x0;
}
}

// =================================================
// Function: CGameRemoteBufferPool::GetRemoteBuffer
// =================================================
CGameRemoteBuffer * __thiscall
CGameRemoteBufferPool::GetRemoteBuffer
          (CGameRemoteBufferPool *this,CGameRemoteBufferPool *param_1,
          CGameMasterServerRequestParams *param_2)
{
{
  CFastString CVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  CVirtualisedBuffer<class_CFastString> *unaff_EDI;
  CGameRemoteBufferPool *pCStack_10;
  
  if (*(int **)(this + 0x14) == (int *)0x0) {
    return (CGameRemoteBuffer *)0x0;
  }
  pCStack_10 = param_1;
  puVar2 = (undefined4 *)(**(code **)(**(int **)(this + 0x14) + 0x90))();
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(param_1,&stack0x00000000);
    if (unaff_EDI != (CVirtualisedBuffer<class_CFastString> *)0xffffffff) {
      pCStack_10 = (CGameRemoteBufferPool *)0x0;
      CVar1 = CFastMapTable<unsigned_long>::GetElem
                        ((CFastMapTable<unsigned_long> *)(this + 0x18),unaff_EDI,(ulong)&pCStack_10)
      ;
      return (CGameRemoteBuffer *)(-(uint)(CONCAT31(extraout_var,CVar1) != 0) & (uint)pCStack_10);
    }
  }
  return (CGameRemoteBuffer *)0x0;
}
}

