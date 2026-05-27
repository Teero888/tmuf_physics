// Class implementation: CPlugFileGPU_SLoadDesc

// =================================================
// Function: CPlugFileGPU::SLoadDesc::GetNextRegisterIndex
// =================================================
ulong __thiscall
CPlugFileGPU::SLoadDesc::GetNextRegisterIndex
          (void *this,SLoadDesc *param_1,CFastArray<struct_SPlugGpuLoadFx> *param_2)
{
{
  uint uVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  
  uVar1 = *(uint *)this;
  if ((uVar1 & 1) != 0) {
    return *(int *)((int)this + 4) + (&DAT_00d154f8)[uVar1 >> 1 & 0x7fff];
  }
  pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                     (param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar1 >> 1),
                      unaff_ESI);
  return *(int *)((int)this + 4) +
         (*(uint *)(pSVar2 + 4) >> 9 & 0x3ff) * (*(uint *)(pSVar2 + 4) >> 3 & 7);
}
}

