// Class implementation: CPlugVisualLines

// =================================================
// Function: CPlugVisualLines::AddLine
// =================================================
void __thiscall
CPlugVisualLines::AddLine
          (CPlugVisualLines *this,CPlugVisualLines2D *param_1,GmVec2 *param_2,GmVec2 *param_3,
          GxColor *param_4)
{
{
  SLoadedLight *pSVar1;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  
  pSVar1 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(this + 0x78,unaff_EDI);
  *(undefined4 *)pSVar1 = *(undefined4 *)param_2;
  *(undefined4 *)(pSVar1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(pSVar1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(pSVar1 + 0x18) = *(undefined4 *)param_4;
  *(undefined4 *)(pSVar1 + 0x1c) = *(undefined4 *)(param_4 + 4);
  *(undefined4 *)(pSVar1 + 0x20) = *(undefined4 *)(param_4 + 8);
  *(undefined4 *)(pSVar1 + 0x24) = *(undefined4 *)(param_4 + 0xc);
  *(undefined4 *)(pSVar1 + 0xc) = 0x3f800000;
  *(undefined4 *)(pSVar1 + 0x10) = 0x3f800000;
  *(undefined4 *)(pSVar1 + 0x14) = 0x3f800000;
  pSVar1 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(this + 0x78,unaff_ESI);
  *(undefined4 *)pSVar1 = *(undefined4 *)param_4;
  *(undefined4 *)(pSVar1 + 4) = *(undefined4 *)(param_4 + 4);
  *(undefined4 *)(pSVar1 + 8) = *(undefined4 *)(param_4 + 8);
  *(undefined4 *)(pSVar1 + 0x18) = *(undefined4 *)param_4;
  *(undefined4 *)(pSVar1 + 0x1c) = *(undefined4 *)(param_4 + 4);
  *(undefined4 *)(pSVar1 + 0x20) = *(undefined4 *)(param_4 + 8);
  *(undefined4 *)(pSVar1 + 0x24) = *(undefined4 *)(param_4 + 0xc);
  *(undefined4 *)(pSVar1 + 0xc) = 0x3f800000;
  *(undefined4 *)(pSVar1 + 0x10) = 0x3f800000;
  *(undefined4 *)(pSVar1 + 0x14) = 0x3f800000;
  return;
}
}

// =================================================
// Function: CPlugVisualLines::CPlugVisualLines
// =================================================
void __thiscall CPlugVisualLines::CPlugVisualLines(CPlugVisualLines *this,CPlugVisualLines *param_1)
{
{
  CPlugVisual3D *unaff_ESI;
  CPlugVisual3D *unaff_retaddr;
  
  CPlugVisual3D::CPlugVisual3D((CPlugVisual3D *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  return;
}
}

