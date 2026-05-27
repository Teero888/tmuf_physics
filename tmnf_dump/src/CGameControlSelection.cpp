// Class implementation: CGameControlSelection

// =================================================
// Function: CGameControlSelection::CGameControlSelection
// =================================================
void __thiscall
CGameControlSelection::CGameControlSelection
          (CGameControlSelection *this,CGameControlSelection *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000008;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000000c;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x18,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x28,in_stack_00000008);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x48,in_stack_0000000c);
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  return;
}
}

