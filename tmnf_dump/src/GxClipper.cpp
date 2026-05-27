// Class implementation: GxClipper

// =================================================
// Function: GxClipper::GxClipper
// =================================================
void __thiscall GxClipper::GxClipper(GxClipper *this,GxClipper *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000008;
  
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x74,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x80,unaff_retaddr);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x8c,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x98,in_stack_00000008);
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
}

