// Class implementation: CHmsCollisionBuffer

// =================================================
// Function: CHmsCollisionBuffer::AddCollision
// =================================================
GmCollision * __thiscall
CHmsCollisionBuffer::AddCollision(CHmsCollisionBuffer *this,CHmsCollisionBuffer *param_1)
{
{
  SLoadedLight *pSVar1;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_SHmsPhysicalCollision>::AddNewElem(this + 4,unaff_retaddr);
  return (GmCollision *)(pSVar1 + 0x10);
}
}

// =================================================
// Function: CHmsCollisionBuffer::CHmsCollisionBuffer
// =================================================
void __thiscall
CHmsCollisionBuffer::CHmsCollisionBuffer(CHmsCollisionBuffer *this,CHmsCollisionBuffer *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *pCVar1;
  ulong unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a954db;
  local_c = ExceptionList;
  pCVar1 = (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 4,pCVar1);
  CFastBuffer<struct_SHmsPhysicalCollision>::SetSizeAtLeast
            (this + 4,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)&DAT_00000032,unaff_EDI);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CHmsCollisionBuffer::GetCollision
// =================================================
GmCollision * __thiscall
CHmsCollisionBuffer::GetCollision
          (CHmsCollisionBuffer *this,CHmsCollisionBuffer *param_1,ulong param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_SHmsPhysicalCollision>::operator[]
                     (this + 4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  return (GmCollision *)(pSVar1 + 0x10);
}
}

