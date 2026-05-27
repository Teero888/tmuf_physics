// Class implementation: CPlugIndexBuffer

// =================================================
// Function: CPlugIndexBuffer::CPlugIndexBuffer
// =================================================
void __thiscall CPlugIndexBuffer::CPlugIndexBuffer(CPlugIndexBuffer *this,CPlugIndexBuffer *param_1)
{
{
  CPlug *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CPlug::CPlug((CPlug *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x1c,unaff_retaddr);
  *(undefined4 *)(this + 0x18) = 0;
  *(uint *)(this + 0x18) = *(uint *)(this + 0x18) | 2;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
}

