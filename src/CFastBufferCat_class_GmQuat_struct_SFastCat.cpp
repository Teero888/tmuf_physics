// Class implementation: CFastBufferCat_class_GmQuat_struct_SFastCat

// =================================================
// Function: struct_SFastCat>::GetElemInAll
// =================================================
GmQuat * __thiscall
CFastBufferCat<class_GmQuat,struct_SFastCat>::GetElemInAll
          (void *this,CFastBufferCat<class_GmQuat,struct_SFastCat> *param_1,ulong param_2)
{
{
  SCasterCat *pSVar1;
  
  pSVar1 = CFastBuffer<class_GxColor>::operator[]
                     ((void *)((int)this + 0xc),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,param_2);
  return (GmQuat *)pSVar1;
}
}

