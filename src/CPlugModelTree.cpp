// Class implementation: CPlugModelTree

// =================================================
// Function: CPlugModelTree::SurfaceAdd
// =================================================
void __thiscall
CPlugModelTree::SurfaceAdd
          (CPlugModelTree *this,CVisionViewportDx9 *param_1,ESurface param_2,GmNat2 *param_3,
          _D3DFORMAT param_4,_D3DMULTISAMPLE_TYPE param_5,IDirect3DSurface9 *param_6)
{
{
  TiXmlAttribute *unaff_EBX;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x3c,unaff_EDI);
  CFastBuffer<class_CMwNodRef<class_CPlugModelMesh>_>::AddNewElem(this + 0x3c,unaff_ESI);
  CFastBuffer<class_GmIso4>::Add(this + 0x48,(TiXmlAttributeSet *)PTR_DAT_00d17784,unaff_EBX);
  return;
}
}

