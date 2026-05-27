// Class implementation: CFastBufferRef_class_CPlugSolid

// =================================================
// Function: CFastBufferRef<class_CPlugSolid>::AllocSetCount
// =================================================
void __thiscall
CFastBufferRef<class_CPlugSolid>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  CFastBuffer<class_GxVertex2> *pCVar1;
  int iVar2;
  CMwNod *this_00;
  CMwNod *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<class_GxVertex2> *pCVar3;
  
  pCVar1 = *(CFastBuffer<class_GxVertex2> **)this;
  for (pCVar3 = param_1; pCVar3 < pCVar1; pCVar3 = pCVar3 + 1) {
    iVar2 = *(int *)((int)this + 4);
    this_00 = *(CMwNod **)(iVar2 + (int)pCVar3 * 4);
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwRelease(this_00,unaff_ESI);
      *(undefined4 *)(iVar2 + (int)pCVar3 * 4) = 0;
    }
  }
  CFastBuffer<class_CMwNodRef<class_CPlugSolid>_>::AllocSetCount(this,param_1,unaff_EDI);
  return;
}
}

