// Class implementation: CMwCmdContainer

// =================================================
// Function: CMwCmdContainer::AddCmd
// =================================================
void __thiscall CMwCmdContainer::AddCmd(CMwCmdContainer *this,CMwCmdBuffer *param_1,CMwCmd *param_2)
{
{
  TiXmlAttribute *unaff_ESI;
  ulong unaff_EDI;
  CMwNod *unaff_retaddr;
  
  CMwCmd::SetSchemeLocation((CMwCmd *)param_1,param_2,unaff_EDI);
  CFastBuffer<class_CDx9TextureKeeper*>::Add(this + 0x14,(TiXmlAttributeSet *)&param_2,unaff_ESI);
  CMwNod::MwAddRef((CMwNod *)param_1,unaff_retaddr);
  if (*(int *)(this + 0x20) == 1) {
    (**(code **)(*(int *)param_1 + 0x7c))();
  }
  return;
}
}

// =================================================
// Function: CMwCmdContainer::AddFastCall
// =================================================
CMwCmdFastCall * __thiscall
CMwCmdContainer::AddFastCall
          (CMwCmdContainer *this,CMwCmdContainer *param_1,CMwNod *param_2,
          _func___cdecl_void *param_3,ulong param_4)
{
{
  _func___cdecl_void *p_Var1;
  CMwCmdFastCall *this_00;
  CMwCmdBuffer *extraout_EAX;
  CMwCmdBuffer *pCVar2;
  ulong unaff_EDI;
  CMwCmd *in_stack_00000014;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ae50fb;
  local_c = ExceptionList;
  p_Var1 = (_func___cdecl_void *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  this_00 = operator_new(0x24);
  pCVar2 = (CMwCmdBuffer *)0x0;
  local_4 = (void *)0x0;
  if (this_00 != (CMwCmdFastCall *)0x0) {
    CMwCmdFastCall::CMwCmdFastCall(this_00,(CMwCmdFastCall *)param_1,param_2,p_Var1,unaff_EDI);
    pCVar2 = extraout_EAX;
  }
  AddCmd(this,pCVar2,in_stack_00000014);
  ExceptionList = local_4;
  return (CMwCmdFastCall *)pCVar2;
}
}

// =================================================
// Function: CMwCmdContainer::CMwCmdContainer
// =================================================
void __thiscall CMwCmdContainer::CMwCmdContainer(CMwCmdContainer *this,CMwCmdContainer *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CMwNod *unaff_EDI;
  undefined1 uStack00000008;
  CMwCmdContainer *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae50d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x14,unaff_ESI);
  uStack00000008 = 1;
  CFastBuffer<int>::SetSizeAtLeast
            (this + 0x14,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x1,(ulong)pCVar1);
  *(undefined4 *)(this + 0x20) = 0;
  ExceptionList = (void *)0x0;
  return;
}
}

