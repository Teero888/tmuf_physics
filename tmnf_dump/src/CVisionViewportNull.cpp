// Class implementation: CVisionViewportNull

// =================================================
// Function: CVisionViewportNull::CVisionViewportNull
// =================================================
void __thiscall
CVisionViewportNull::CVisionViewportNull(CVisionViewportNull *this,CVisionViewportNull *param_1)
{
{
  CVisionViewportNull *this_00;
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  ulong unaff_EDI;
  void *in_stack_00000010;
  ulong in_stack_ffffffec;
  CVisionViewportNull *pCVar2;
  void *pvVar3;
  undefined1 *puVar4;
  
  puVar4 = &LAB_00ae9ec8;
  pvVar3 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar2 = this;
  CVisionViewport::CVisionViewport
            ((CVisionViewport *)this,(CVisionViewport *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  this_00 = this + 0x164;
  *(undefined ***)this = vftable;
  CFastArray<struct_CHmsViewport::SDisplayMode>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_EDI);
  pSVar1 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  *(undefined4 *)pSVar1 = 0x280;
  pSVar1 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_ffffffec);
  *(undefined4 *)(pSVar1 + 4) = 0x1e0;
  CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
            (this + 0x16c,
             (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
              *)0x1,(ulong)pCVar2);
  CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
            (this + 400,
             (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
              *)0x1,(ulong)pvVar3);
  param_1 = (CVisionViewportNull *)0x1;
  CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::AddInCat
            (this + 400,
             (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)&param_1,
             (CHmsCorpus **)0x0,(ulong)puVar4);
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CVisionViewportNull::SetFullScreenGammaRamp
// =================================================
void __thiscall
CVisionViewportNull::SetFullScreenGammaRamp
          (CVisionViewportNull *this,CVisionViewportNull *param_1,float param_2,float param_3,
          float param_4)
{
{
  return;
}
}

