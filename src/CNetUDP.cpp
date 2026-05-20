// Class implementation: CNetUDP

// =================================================
// Function: CNetUDP::SendTo
// =================================================
ERetCode __thiscall
CNetUDP::SendTo(void *this,CNetUDP *param_1,CNetIPAddress *param_2,CClassicBufferMemory *param_3)
{
{
  int iVar1;
  char *pcVar2;
  int extraout_EAX;
  int iVar3;
  char *in_stack_ffffffa4;
  CNetSystemError *pCVar4;
  undefined4 uStack_44;
  CNetUDP *pCStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  void *pvStack_24;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a91be8;
  local_c = ExceptionList;
  uStack_38 = DAT_00cca150 ^ (uint)&stack0xffffffcc;
  ExceptionList = &local_c;
  uStack_3c = 0x10;
  pCStack_40 = param_1;
  uStack_44 = 0;
  (**(code **)(*(int *)param_2 + 0x18))();
  iVar1 = Ordinal_20();
  if (0 < iVar1) {
    iVar3 = (**(code **)(*(int *)param_2 + 0x18))();
    ExceptionList = pvStack_24;
    return -(uint)(iVar1 != iVar3) & 2;
  }
  if (iVar1 != 0) {
    iVar1 = Ordinal_111();
    if (iVar1 != 0x2733) {
      pCVar4 = (CNetSystemError *)0x50753d;
      LogSocketError(0);
      pcVar2 = (char *)Ordinal_111();
      CFastString::CFastString
                ((CFastString *)&stack0xffffffa4,(CFastString *)"CNetUDP::SendTo",in_stack_ffffffa4)
      ;
      CNetSystem::CNetSystemError::CNetSystemError
                ((CNetSystemError *)&stack0xffffffd0,(CNetSystemError *)0x0,pCVar4);
      CFastString::CFastString((CFastString *)&uStack_44,(CFastString *)(extraout_EAX + 4),pcVar2);
      uStack_38 = *(undefined4 *)(extraout_EAX + 0xc);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8();
    }
  }
  ExceptionList = pvStack_24;
  return 2;
}
}

