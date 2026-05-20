// Class implementation: CSceneVehicleStruct_SVisualWheel

// =================================================
// Function: CSceneVehicleStruct::SVisualWheel::Reset
// =================================================
void __thiscall CSceneVehicleStruct::SVisualWheel::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  GmFrustumIso4 *unaff_retaddr;
  GmFrustumIso4 *in_stack_00000008;
  GmFrustumIso4 *in_stack_0000000c;
  
  SVisualId::Reset(this,unaff_retaddr);
  SVisualId::Reset((void *)(extraout_EAX + 8),param_1);
  SVisualId::Reset((void *)(extraout_EAX_00 + 0x10),in_stack_00000008);
  SVisualId::Reset((void *)(extraout_EAX_01 + 0x18),in_stack_0000000c);
  *(undefined4 *)(extraout_EAX_02 + 0x20) = 0xffffffff;
  *(undefined4 *)(extraout_EAX_02 + 0x24) = 1;
  return;
}
}

// =================================================
// Function: CSceneVehicleStruct::SVisualWheel::SVisualWheel
// =================================================
void __thiscall CSceneVehicleStruct::SVisualWheel::SVisualWheel(void *this,SVisualWheel *param_1)
{
{
  SVisualId *unaff_ESI;
  void *in_stack_00000008;
  SVisualId *pSVar1;
  SVisualId *pSVar2;
  GmFrustumIso4 *pGVar3;
  
  pGVar3 = (GmFrustumIso4 *)&LAB_00ad027e;
  pSVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pSVar1 = this;
  SVisualId::SVisualId(this,(SVisualId *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  SVisualId::SVisualId((void *)((int)this + 8),unaff_ESI);
  SVisualId::SVisualId((void *)((int)this + 0x10),pSVar1);
  in_stack_00000008 = (void *)CONCAT31(in_stack_00000008._1_3_,2);
  SVisualId::SVisualId((void *)((int)this + 0x18),pSVar2);
  Reset(this,pGVar3);
  ExceptionList = in_stack_00000008;
  return;
}
}

// =================================================
// Function: CSceneVehicleStruct::SVisualWheel::~SVisualWheel
// =================================================
void __thiscall CSceneVehicleStruct::SVisualWheel::~SVisualWheel(void *this,SVisualWheel *param_1)
{
{
  CFastStringInt *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00acc8ae;
  local_c = ExceptionList;
  pCVar1 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  local_4 = 2;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  local_4._0_1_ = 1;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  local_4 = (uint)local_4._1_3_ << 8;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  local_4 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  ExceptionList = local_c;
  return;
}
}

