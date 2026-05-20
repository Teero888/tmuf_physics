// Class implementation: CSystemFidParameters_SParam_Fid_Common

// =================================================
// Function: CSystemFidParameters::SParam_Fid_Common::SParam_Fid_Common
// =================================================
void __thiscall
CSystemFidParameters::SParam_Fid_Common::SParam_Fid_Common
          (SParam_Fid_Common *this,SParam_Fid_Common *param_1,EParamType param_2,
          CSystemPackDesc *param_3,CFastString *param_4,ulong param_5)
{
{
  ulong uVar1;
  char *unaff_EDI;
  undefined4 in_stack_00000018;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a82318;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  SParam::SParam((SParam *)this,(SParam *)param_1,0,(ulong *)0x0,
                 DAT_00cca150 ^ (uint)&stack0xffffffe8);
  *(undefined ***)this = vftable;
  uVar1 = CFastAlgo::ComputeHashVal(*(char **)(param_4 + 4),(ulong *)0x0);
  *(CSystemPackDesc **)(this + 0x14) = param_3;
  *(ulong *)(this + 0x10) = uVar1;
  CFastString::CFastString((CFastString *)(this + 0x18),param_4,unaff_EDI);
  *(undefined4 *)(this + 0x20) = in_stack_00000018;
  ExceptionList = local_4;
  return;
}
}

