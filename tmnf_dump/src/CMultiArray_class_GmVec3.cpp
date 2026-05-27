// Class implementation: CMultiArray_class_GmVec3

// =================================================
// Function: CMultiArray<class_GmVec3>::CopyFrom
// =================================================
void __thiscall CMultiArray<class_GmVec3>::CopyFrom(void *this,SParam_Set *param_1,SParam *param_2)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  CFastArray<struct_CDx9StateBlock::SPackedDesc>::CopyFromFastArray
            ((void *)((int)this + 8),(CFastArray<class_GmVec4> *)(param_1 + 8),
             (CFastArray<class_GmVec4> *)param_2);
  return;
}
}

