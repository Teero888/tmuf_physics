// Class implementation: CNetTcpConnectedSocket

// =================================================
// Function: CNetTcpConnectedSocket::Send
// =================================================
void __thiscall
CNetTcpConnectedSocket::Send(void *this,CNetConnectedClient *param_1,CNetNod *param_2)
{
{
  int iVar1;
  char *pcVar2;
  int extraout_EAX;
  char *in_stack_ffffffb0;
  CNetSystemError *pCVar3;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  CNetSystemError aCStack_28 [12];
  void *pvStack_1c;
  undefined4 uStack_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a91d58;
  local_c = ExceptionList;
  uStack_34 = DAT_00cca150 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_c;
  uStack_3c = *(undefined4 *)param_2;
  uStack_38 = 0;
  iVar1 = Ordinal_19();
  if (0 < iVar1) {
    *(int *)param_2 = iVar1;
    ExceptionList = pvStack_1c;
    return;
  }
  *(undefined4 *)param_2 = 0;
  if (iVar1 != 0) {
    iVar1 = Ordinal_111();
    if (iVar1 != 0x2733) {
      pCVar3 = (CNetSystemError *)0x507e11;
      LogSocketError(0);
      pcVar2 = (char *)Ordinal_111();
      puStack_8 = &stack0xffffffb0;
      CFastString::CFastString
                ((CFastString *)&stack0xffffffb0,(CFastString *)"CNetTcpConnectedSocket::Send",
                 in_stack_ffffffb0);
      CNetSystem::CNetSystemError::CNetSystemError(aCStack_28,(CNetSystemError *)0x0,pCVar3);
      uStack_18 = 0;
      CFastString::CFastString((CFastString *)&uStack_3c,(CFastString *)(extraout_EAX + 4),pcVar2);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}
}

// =================================================
// Function: CNetTcpConnectedSocket::Shutdown
// =================================================
int __thiscall CNetTcpConnectedSocket::Shutdown(void *this,CNetTcpConnectedSocket *param_1)
{
{
  int iVar1;
  
  if (*(int *)this != -1) {
    iVar1 = Ordinal_22(*(int *)this,1);
    if (iVar1 == 0) {
      return 1;
    }
    LogSocketError(0);
  }
  return 0;
}
}

// =================================================
// Function: CNetTcpConnectedSocket::Writable
// =================================================
int __thiscall CNetTcpConnectedSocket::Writable(void *this,CNetTcpConnectedSocket *param_1)
{
{
  int iVar1;
  undefined4 uVar2;
  SStringParam *pSVar3;
  undefined *puVar4;
  undefined *unaff_ESI;
  SStringParam *pSVar5;
  SStringParam *pSVar6;
  char *pcVar7;
  SStringParam *pSVar8;
  SStringParam *pSVar9;
  undefined4 *puStack_2a0;
  SStringParam *pSStack_29c;
  undefined *puStack_288;
  undefined *puStack_284;
  undefined *puStack_280;
  SStringParam *pSStack_27c;
  undefined4 uStack_278;
  undefined *puStack_274;
  undefined *puStack_270;
  undefined *puStack_26c;
  SStringParam *pSStack_268;
  undefined **ppuStack_264;
  undefined4 uStack_260;
  undefined *puStack_25c;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined *puStack_24c;
  undefined4 uStack_244;
  undefined *puStack_240;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  void *pvStack_20;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a91d24;
  local_c = ExceptionList;
  pSStack_29c = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xfffffd68);
  ExceptionList = &local_c;
  local_210 = *(undefined4 *)this;
  puStack_2a0 = &local_21c;
  pSVar3 = (SStringParam *)&local_110;
  pSVar8 = (SStringParam *)0x0;
  pcVar7 = &DAT_00000040;
  local_110 = 1;
  local_214 = 1;
  local_21c = 0;
  local_218 = 0;
  local_10c = local_210;
  iVar1 = Ordinal_18();
  if (iVar1 == -1) {
    LogSocketError(0);
    CFastString::CFastString
              ((CFastString *)&stack0xfffffd6c,(CFastString *)"CNetTcpConnectedSocket::Writable(1)",
               pcVar7);
    uVar2 = Ordinal_111();
    pSStack_268 = (SStringParam *)&puStack_284;
    puStack_288 = (undefined *)0x0;
    puStack_284 = (undefined *)0x0;
    puStack_280 = PTR_DAT_00bbf7d8;
    uStack_14 = 1;
    CFastString::SetString((CFastString *)&puStack_284,(CFastStringInt *)&pSStack_29c,pSVar8);
    uStack_278 = uVar2;
    if (puStack_288 != PTR_DAT_00bbf7d8) {
      puVar4 = puStack_288 + -1;
      if ((puStack_288[-1] & 0x80) != 0) {
        puVar4 = puStack_288 + -4;
      }
      operator_delete__(puVar4);
      puStack_288 = PTR_DAT_00bbf7d8;
    }
    ppuStack_264 = &puStack_270;
    puStack_274 = puStack_284;
    puStack_270 = (undefined *)0x0;
    puStack_26c = PTR_DAT_00bbf7d8;
    uStack_10 = 3;
    CFastString::SetString((CFastString *)&puStack_270,(CFastStringInt *)&stack0xfffffd68,pSVar3);
    local_c = (void *)CONCAT31(local_c._1_3_,2);
    ppuStack_264 = (undefined **)puStack_274;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8();
  }
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = func_0x009f2616(*(undefined4 *)this);
    if (iVar1 != 0) {
      pcVar7 = *(char **)this;
      pSVar6 = (SStringParam *)0x1007;
      pSVar5 = (SStringParam *)0xffff;
      puStack_26c = (undefined *)0x4;
      iVar1 = Ordinal_7();
      if (iVar1 == -1) {
        LogSocketError(0);
      }
      else {
        LogSocketError((int)pSVar8);
        if (pSVar8 == (SStringParam *)0x2740) {
          CFastString::CFastString
                    ((CFastString *)&puStack_2a0,
                     (CFastString *)"CNetTcpConnectedSocket::Writable(2)",pcVar7);
          puStack_288 = (undefined *)0x0;
          puStack_284 = PTR_DAT_00bbf7d8;
          uStack_28 = 5;
          CFastString::SetString
                    ((CFastString *)&puStack_288,(CFastStringInt *)&stack0xfffffd50,pSVar5);
          pSStack_27c = pSVar3;
          if (unaff_ESI != PTR_DAT_00bbf7d8) {
            puVar4 = unaff_ESI + -1;
            if ((unaff_ESI[-1] & 0x80) != 0) {
              puVar4 = unaff_ESI + -4;
            }
            operator_delete__(puVar4);
          }
          puStack_2a0 = &uStack_250;
          uStack_254 = puStack_288;
          uStack_250 = 0;
          puStack_24c = PTR_DAT_00bbf7d8;
          uStack_24 = 7;
          CFastString::SetString
                    ((CFastString *)&uStack_250,(CFastStringInt *)&stack0xfffffd54,pSVar6);
          pvStack_20 = (void *)CONCAT31(pvStack_20._1_3_,6);
          uStack_244 = uStack_278;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8();
        }
      }
      CFastString::CFastString
                ((CFastString *)&stack0xfffffd4c,
                 (CFastString *)"CNetTcpConnectedSocket::Writable(3)",pcVar7);
      uStack_278 = 0;
      puStack_274 = (undefined *)0x0;
      puStack_270 = PTR_DAT_00bbf7d8;
      uStack_28 = 9;
      pSVar9 = pSVar3;
      pSStack_29c = pSVar8;
      CFastString::SetString((CFastString *)&puStack_274,(CFastStringInt *)&pSStack_29c,pSVar5);
      pSStack_268 = pSVar3;
      if (pSVar9 != (SStringParam *)PTR_DAT_00bbf7d8) {
        pSVar3 = pSVar9 + -1;
        if (((byte)pSVar9[-1] & 0x80) != 0) {
          pSVar3 = pSVar9 + -4;
        }
        operator_delete__(pSVar3);
      }
      puStack_2a0 = &uStack_260;
      ppuStack_264 = (undefined **)puStack_274;
      uStack_260 = 0;
      puStack_25c = PTR_DAT_00bbf7d8;
      puStack_240 = puStack_270;
      uStack_24 = 0xb;
      uStack_244 = puStack_26c;
      CFastString::SetString((CFastString *)&uStack_260,(CFastStringInt *)&uStack_244,pSVar6);
      pvStack_20 = (void *)CONCAT31(pvStack_20._1_3_,10);
      uStack_254 = ppuStack_264;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8();
    }
    iVar1 = 1;
  }
  ExceptionList = pvStack_20;
  return iVar1;
}
}

