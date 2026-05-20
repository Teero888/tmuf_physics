// Class implementation: CFastBuffer_struct_CPlugFileGPU_SLoadDesc

// =================================================
// Function: CFastBuffer<struct_CPlugFileGPU::SLoadDesc>::DetachElems
// =================================================
SLoadDesc * __thiscall
CFastBuffer<struct_CPlugFileGPU::SLoadDesc>::DetachElems
          (void *this,CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *param_1)
{
{
  SLoadDesc *pSVar1;
  
  pSVar1 = *(SLoadDesc **)((int)this + 4);
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return pSVar1;
}
}

