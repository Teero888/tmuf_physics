// Class implementation: CScenePath

// =================================================
// Function: CScenePath::GetLength
// =================================================
float __thiscall CScenePath::GetLength(CScenePath *this,CPlugFileSnd *param_1)
{
{
  CScenePath *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  
  this_00 = this + 0x30;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  if (uVar1 != 0) {
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this_00,(CFastBuffer<class_CCrystalFace*> *)this);
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar1 - 1),
                        unaff_retaddr);
    return *(float *)pSVar2;
  }
  return 0.0;
}
}

