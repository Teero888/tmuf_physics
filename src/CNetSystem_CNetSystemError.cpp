// Class implementation: CNetSystem_CNetSystemError

// =================================================
// Function: CNetSystem::CNetSystemError::CNetSystemError
// =================================================
void __thiscall
CNetSystem::CNetSystemError::CNetSystemError
          (CNetSystemError *this,CNetSystemError *param_1,CNetSystemError *param_2)
{
{
  char *pcVar1;
  undefined *puVar2;
  undefined *in_stack_00000010;
  undefined4 in_stack_00000014;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00a91bb8;
  local_c = ExceptionList;
  pcVar1 = (char *)(DAT_00cca150 ^ (uint)&stack0xfffffff0);
  ExceptionList = &local_c;
  local_4 = 0;
  *(CNetSystemError **)this = param_1;
  CFastString::CFastString((CFastString *)(this + 4),(CFastString *)&param_2,pcVar1);
  *(undefined4 *)(this + 0xc) = in_stack_00000014;
  if (in_stack_00000010 != PTR_DAT_00bbf7d8) {
    puVar2 = in_stack_00000010 + -1;
    if ((in_stack_00000010[-1] & 0x80) != 0) {
      puVar2 = in_stack_00000010 + -4;
    }
    operator_delete__(puVar2);
  }
  ExceptionList = local_8;
  return;
}
}

