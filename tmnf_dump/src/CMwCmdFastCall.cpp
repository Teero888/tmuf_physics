// Class implementation: CMwCmdFastCall

// =================================================
// Function: CMwCmdFastCall::CMwCmdFastCall
// =================================================
void __thiscall
CMwCmdFastCall::CMwCmdFastCall
          (CMwCmdFastCall *this,CMwCmdFastCall *param_1,CMwNod *param_2,_func___cdecl_void *param_3,
          ulong param_4)
{
{
  ulong unaff_ESI;
  CMwCmdFastCall *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ae30e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMwCmd::CMwCmd((CMwCmd *)this,(CMwCmd *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(CMwNod **)(this + 0x20) = param_2;
  *(undefined ***)this = vftable;
  *(_func___cdecl_void **)(this + 0x1c) = param_3;
  CMwCmd::SetSchemeLocation((CMwCmd *)this,(CMwCmd *)param_4,unaff_ESI);
  FastCall_SetDevNameFromObjectClass(pCVar1);
  ExceptionList = local_4;
  return;
}
}

