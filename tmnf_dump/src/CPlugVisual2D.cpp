// Class implementation: CPlugVisual2D

// =================================================
// Function: CPlugVisual2D::CPlugVisual2D
// =================================================
void __thiscall CPlugVisual2D::CPlugVisual2D(CPlugVisual2D *this,CPlugVisual2D *param_1)
{
{
  CPlugVisual *unaff_ESI;
  CPlugVisual *unaff_retaddr;
  
  CPlugVisual::CPlugVisual((CPlugVisual *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x78,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0xffffff7f;
  return;
}
}

