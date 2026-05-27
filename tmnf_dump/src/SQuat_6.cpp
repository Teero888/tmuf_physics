// Class implementation: SQuat_6

// =================================================
// Function: SQuat_6::GetGmQuat
// =================================================
void __thiscall SQuat_6::GetGmQuat(void *this,SQuat_6 *param_1,GmQuat *param_2)
{
{
  ulong unaff_ESI;
  GmQuat *in_stack_0000000c;
  CClassicBufferMemory *in_stack_ffffffd4;
  CClassicBufferMemory local_28 [4];
  CClassicBuffer local_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acfa98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CClassicBufferMemory::CClassicBufferMemory
            ((CClassicBufferMemory *)&stack0xffffffd4,
             (CClassicBufferMemory *)(DAT_00cca150 ^ (uint)&stack0xffffffd0));
  CClassicBufferMemory::Attach(local_28,this,&DAT_00000006,unaff_ESI);
  GmArchive::ReadQuat_6(local_24,in_stack_0000000c);
  CClassicBufferMemory::~CClassicBufferMemory((CClassicBufferMemory *)local_24,in_stack_ffffffd4);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: SQuat_6::SetFromGmQuat
// =================================================
void __thiscall SQuat_6::SetFromGmQuat(void *this,SQuat_6 *param_1,GmQuat *param_2)
{
{
  ulong unaff_ESI;
  GmQuat *in_stack_0000000c;
  CClassicBufferMemory *in_stack_ffffffd4;
  CClassicBufferMemory local_28 [4];
  CClassicBuffer local_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acfac8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CClassicBufferMemory::CClassicBufferMemory
            ((CClassicBufferMemory *)&stack0xffffffd4,
             (CClassicBufferMemory *)(DAT_00cca150 ^ (uint)&stack0xffffffd0));
  CClassicBufferMemory::Attach(local_28,this,&DAT_00000006,unaff_ESI);
  GmArchive::WriteQuat_6(local_24,in_stack_0000000c);
  CClassicBufferMemory::~CClassicBufferMemory((CClassicBufferMemory *)local_24,in_stack_ffffffd4);
  ExceptionList = (void *)0x0;
  return;
}
}

