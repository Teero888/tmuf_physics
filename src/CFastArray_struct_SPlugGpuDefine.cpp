// Class implementation: CFastArray_struct_SPlugGpuDefine

// =================================================
// Function: CFastArray<struct_SPlugGpuDefine>::AddNewTailElem
// =================================================
SPackedDesc * __thiscall
CFastArray<struct_SPlugGpuDefine>::AddNewTailElem
          (void *this,CFastArray<struct_CDx9StateBlock::SPackedDesc> *param_1)
{
{
  ulong unaff_ESI;
  
  if (*(int *)this == 0) {
    SetCount(this,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_ESI);
    return *(SPackedDesc **)((int)this + 4);
  }
  AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x1,unaff_ESI);
  return (SPackedDesc *)(*(int *)((int)this + 4) + -0xc + *(int *)this * 0xc);
}
}

