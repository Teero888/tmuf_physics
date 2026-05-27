// Class implementation: CFastBuffer_struct_CHmsVPackerCell_STreeMipLocated

// =================================================
// Function: CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(iVar1 * 0x20 + *(int *)((int)this + 4));
}
}

