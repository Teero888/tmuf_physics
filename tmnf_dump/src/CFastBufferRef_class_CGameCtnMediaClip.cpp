// Class implementation: CFastBufferRef_class_CGameCtnMediaClip

// =================================================
// Function: CFastBufferRef<class_CGameCtnMediaClip>::FindPtr
// =================================================
ulong __thiscall
CFastBufferRef<class_CGameCtnMediaClip>::FindPtr
          (void *this,CFastBufferRef<class_CGameCtnMediaClip> *param_1,CGameCtnMediaClip *param_2)
{
{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  if (*(uint *)this != 0) {
    piVar2 = *(int **)((int)this + 4);
    do {
      if ((CFastBufferRef<class_CGameCtnMediaClip> *)*piVar2 == param_1) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar1 < *(uint *)this);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CFastBufferRef<class_CGameCtnMediaClip>::RemoveAt
// =================================================
void __thiscall
CFastBufferRef<class_CGameCtnMediaClip>::RemoveAt
          (void *this,CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *param_1,
          ulong param_2,ulong param_3)
{
{
  CMwNod *pCVar1;
  int iVar2;
  int iVar3;
  CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *pCVar4;
  CMwNod *unaff_EDI;
  int iVar5;
  int *unaff_retaddr;
  
  for (pCVar4 = param_1; pCVar4 < param_1 + param_2; pCVar4 = pCVar4 + 1) {
    iVar5 = *(int *)((int)this + 4);
    pCVar1 = *(CMwNod **)(iVar5 + (int)pCVar4 * 4);
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(pCVar1,unaff_EDI);
      *(undefined4 *)(iVar5 + (int)pCVar4 * 4) = 0;
      this = unaff_retaddr;
    }
  }
  pCVar4 = (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)
           ((*(int *)this - (int)param_1) - param_2);
  if (pCVar4 != (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0x0) {
    iVar3 = (int)(param_1 + param_2) * 4;
    iVar5 = (int)param_1 * 4;
    param_1 = pCVar4;
    do {
      iVar2 = *(int *)((int)this + 4);
      pCVar1 = *(CMwNod **)(iVar2 + iVar3);
      if (pCVar1 != *(CMwNod **)(iVar5 + iVar2)) {
        if (pCVar1 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(pCVar1,unaff_EDI);
          this = unaff_retaddr;
        }
        if (*(CMwNod **)(iVar5 + iVar2) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(iVar5 + iVar2),unaff_EDI);
          this = unaff_retaddr;
        }
        *(CMwNod **)(iVar5 + iVar2) = pCVar1;
      }
      iVar2 = *(int *)((int)this + 4);
      pCVar1 = *(CMwNod **)(iVar2 + iVar3);
      if (pCVar1 != (CMwNod *)0x0) {
        CMwNod::MwRelease(pCVar1,unaff_EDI);
        *(undefined4 *)(iVar2 + iVar3) = 0;
        this = unaff_retaddr;
      }
      iVar5 = iVar5 + 4;
      iVar3 = iVar3 + 4;
      param_1 = param_1 + -1;
    } while (param_1 != (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0x0);
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

