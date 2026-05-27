// Class implementation: CMwCmd

// =================================================
// Function: CMwCmd::CMwCmd
// =================================================
void __thiscall CMwCmd::CMwCmd(CMwCmd *this,CMwCmd *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xfffffffc;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CMwCmd::SetSchemeLocation
// =================================================
void __thiscall CMwCmd::SetSchemeLocation(CMwCmd *this,CMwCmd *param_1,ulong param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  
  if ((CMwCmd *)0x7f < param_1) {
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d731e0 + 0x24),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_1 + -0x80),
                        unaff_ESI);
    *(undefined4 *)(this + 0x14) = *(undefined4 *)pSVar1;
    return;
  }
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d731e0 + 0x1c),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_ESI);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)pSVar1;
  return;
}
}

