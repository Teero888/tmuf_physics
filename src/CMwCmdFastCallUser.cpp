// Class implementation: CMwCmdFastCallUser

// =================================================
// Function: CMwCmdFastCallUser::CMwCmdFastCallUser
// =================================================
void __thiscall
CMwCmdFastCallUser::CMwCmdFastCallUser
          (CMwCmdFastCallUser *this,CMwCmdFastCallUser *param_1,CMwNod *param_2,
          _func___cdecl_void_ulong *param_3,ulong param_4)
{
{
  CMwCmd *unaff_ESI;
  
  CMwCmd::CMwCmd((CMwCmd *)this,unaff_ESI);
  *(_func___cdecl_void_ulong **)(this + 0x1c) = param_3;
  *(undefined ***)this = vftable;
  *(CMwNod **)(this + 0x20) = param_2;
  *(ulong *)(this + 0x24) = param_4;
  return;
}
}

