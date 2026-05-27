// Class implementation: CFastBuffer_struct_CPlugFileGPU_SSampler_CFastBuffer_struct_CPlugFileGPU

// =================================================
// Function: CFastBuffer<struct_CPlugFileGPU::SSampler>::~CFastBuffer<struct_CPlugFileGPU::SSampler>
// =================================================
void __thiscall
CFastBuffer<struct_CPlugFileGPU::SSampler>::~CFastBuffer<struct_CPlugFileGPU::SSampler>
          (void *this,CFastBuffer<struct_CPlugFileGPU::SSampler> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,8,*(int *)((int)pvVar1 + -4),SPlugGpuLoadFx::~SPlugGpuLoadFx);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

