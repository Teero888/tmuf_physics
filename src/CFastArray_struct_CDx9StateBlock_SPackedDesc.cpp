// Class implementation: CFastArray_struct_CDx9StateBlock_SPackedDesc

// =================================================
// Function: CFastArray<struct_CDx9StateBlock::SPackedDesc>::AddNewTailElem
// =================================================
SPackedDesc * __thiscall
CFastArray<struct_CDx9StateBlock::SPackedDesc>::AddNewTailElem
          (void *this,CFastArray<struct_CDx9StateBlock::SPackedDesc> *param_1)
{
{
  ulong unaff_ESI;
  
  if (*(int *)this == 0) {
    CFastArray<class_GmVec3>::SetCount(this,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_ESI);
    return *(SPackedDesc **)((int)this + 4);
  }
  CFastArray<class_GmVec3>::AllocateMore
            (this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x1,unaff_ESI);
  return (SPackedDesc *)(*(int *)((int)this + 4) + -0xc + *(int *)this * 0xc);
}
}

// =================================================
// Function: CFastArray<struct_CDx9StateBlock::SPackedDesc>::CopyFromFastArray
// =================================================
void __thiscall
CFastArray<struct_CDx9StateBlock::SPackedDesc>::CopyFromFastArray
          (void *this,CFastArray<class_GmVec4> *param_1,CFastArray<class_GmVec4> *param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EDI);
  CFastArray<class_GmVec3>::SetCount(this,pCVar1,unaff_ESI);
  if (pCVar1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    iVar4 = 0;
    do {
      iVar2 = *(int *)(param_1 + 4) + iVar4;
      puVar3 = (undefined4 *)(*(int *)((int)this + 4) + iVar4);
      *puVar3 = *(undefined4 *)(*(int *)(param_1 + 4) + iVar4);
      puVar3[1] = *(undefined4 *)(iVar2 + 4);
      iVar4 = iVar4 + 0xc;
      pCVar1 = pCVar1 + -1;
      puVar3[2] = *(undefined4 *)(iVar2 + 8);
    } while (pCVar1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0);
  }
  return;
}
}

