// Class implementation: CSystemFidParameters_SParam_Id

// =================================================
// Function: CSystemFidParameters::SParam_Id::SParam_Id
// =================================================
void __thiscall CSystemFidParameters::SParam_Id::SParam_Id(SParam_Id *this,SParam_Id *param_1)
{
{
  CMwId *in_stack_00000008;
  EParamType in_stack_0000000c;
  ulong *in_stack_00000010;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a82288;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  SParam::SParam((SParam *)this,(SParam *)0x2,in_stack_0000000c,in_stack_00000010,
                 DAT_00cca150 ^ (uint)&stack0xffffffec);
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x10,in_stack_00000008);
  *(EParamType *)(this + 0x14) = in_stack_0000000c;
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CSystemFidParameters::SParam_Id::~SParam_Id
// =================================================
void __thiscall CSystemFidParameters::SParam_Id::~SParam_Id(SParam_Id *this,SParam_Id *param_1)
{
{
  CFastStringInt *pCVar1;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00a82258;
  local_c = ExceptionList;
  pCVar1 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  local_4 = 0;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  SParam::~SParam((SParam *)this,(SParam *)pCVar1);
  ExceptionList = local_8;
  return;
}
}

