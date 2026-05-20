// Class implementation: CFastMap_class_CMwId_float

// =================================================
// Function: float>::SetElem
// =================================================
int __thiscall
CFastMap<class_CMwId,float>::SetElem
          (CFastMap<class_CMwId,float> *this,CFastMap<class_CMwId,float> *param_1,CMwId *param_2,
          float *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SLocationAlloc *unaff_ESI;
  ulong unaff_retaddr;
  undefined4 *in_stack_00000010;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastMap<class_CMwId,unsigned_long>::GetIndex
                     ((CFastMap<class_CMwId,unsigned_long> *)this,(SStackLocation *)param_1,
                      unaff_ESI);
  if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    return 0;
  }
  pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this + 4,pCVar1,unaff_retaddr);
  *(undefined4 *)(pSVar2 + 4) = *in_stack_00000010;
  return 1;
}
}

