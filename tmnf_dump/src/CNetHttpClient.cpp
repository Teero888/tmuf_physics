// Class implementation: CNetHttpClient

// =================================================
// Function: CNetHttpClient::InternalReadFile
// =================================================
EReadFileRes __thiscall
CNetHttpClient::InternalReadFile
          (CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2,char *param_3,
          ulong param_4)
{
{
  int iVar1;
  DWORD DVar2;
  char *pcVar3;
  CPlugFileGpuBuilder *this_00;
  SStringParam *unaff_EBX;
  CPlugFileGpuBuilder *pCVar4;
  SStringParam *pSVar5;
  
  pCVar4 = *(CPlugFileGpuBuilder **)(param_1 + 0x58);
  iVar1 = InternetReadFile();
  if (iVar1 != 0) {
    return 0;
  }
  DVar2 = GetLastError();
  if (DVar2 != 0x3e5) {
    pSVar5 = (SStringParam *)&DAT_00b2c878;
    CFastString::SetString
              ((CFastString *)(this + 0x28),(CFastStringInt *)&stack0xffffffe8,unaff_EBX);
    pcVar3 = (char *)GetLastError();
    this_00 = CFastString::operator<<
                        ((CFastString *)(this + 0x28),
                         (CPlugFileGpuBuilder *)"Failed in call to InternetReadFile, Error: ",pcVar3
                        );
    CFastString::operator<<((CFastString *)this_00,pCVar4,(char *)param_2);
    *(undefined4 *)(param_1 + 0x50) = 4;
    DVar2 = GetLastError();
    *(DWORD *)(param_1 + 0x68) = DVar2;
    CFastString::SetString
              ((CFastString *)(param_1 + 0x14),(CFastStringInt *)&stack0xfffffff4,pSVar5);
    return 2;
  }
  return 1;
}
}

// =================================================
// Function: CNetHttpClient::InternalTerminateReq
// =================================================
void __thiscall
CNetHttpClient::InternalTerminateReq
          (CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2)
{
{
  CMwNod *unaff_ESI;
  ulong unaff_retaddr;
  undefined *puVar1;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    CMwNod::MwAddRef((CMwNod *)param_1,unaff_ESI);
    puVar1 = &DAT_00cd8708;
    AcquireFstMutex((ulong *)&DAT_00cd8708);
    CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
              (&DAT_00d66ba4,
               (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                *)0x2,(ulong)puVar1);
    CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::AddInCat
              (&DAT_00d66ba4,
               (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)&param_2,
               (CHmsCorpus **)0x0,unaff_retaddr);
    ReleaseFstMutex((ulong *)&DAT_00cd8708);
    InternetCloseHandle(*(undefined4 *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}
}

// =================================================
// Function: CNetHttpClient::ReadFile
// =================================================
int __thiscall
CNetHttpClient::ReadFile(CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2)
{
{
  CFastStringBase<char> *this_00;
  CClassicBufferMemory *pCVar1;
  int iVar2;
  CClassicBufferMemory *pCVar3;
  CClassicBufferMemory *pCVar4;
  EReadFileRes EVar5;
  ulong unaff_ESI;
  TiXmlAttributeSet *unaff_EDI;
  CFastStringBase<wchar_t> *pCVar6;
  
  this_00 = (CFastStringBase<char> *)(param_1 + 0x14);
  while( true ) {
    if (*(int *)(param_1 + 0x6c) != -1) {
      pCVar6 = (CFastStringBase<wchar_t> *)(*(int *)this_00 + *(int *)(param_1 + 0x6c));
      if (pCVar6 != *(CFastStringBase<wchar_t> **)this_00) {
        CFastStringBase<char>::AllocAtLeast(this_00,pCVar6,1,0,(SOldChars *)unaff_EDI);
        pCVar6[*(int *)(param_1 + 0x18)] = (CFastStringBase<wchar_t>)0x0;
        *(CFastStringBase<wchar_t> **)this_00 = pCVar6;
      }
      if (*(int *)this_00 != 0) {
        *(undefined1 *)(*(int *)this_00 + *(int *)(param_1 + 0x18)) = 0;
      }
    }
    iVar2 = *(int *)this_00;
    pCVar3 = *(CClassicBufferMemory **)(param_1 + 0x1c);
    pCVar1 = (CClassicBufferMemory *)(iVar2 + 0x4000);
    pCVar4 = pCVar1;
    if (((pCVar1 < pCVar3) && (pCVar4 = pCVar3, (CClassicBufferMemory *)0x200000 < pCVar3)) &&
       (pCVar4 = (CClassicBufferMemory *)((((uint)pCVar1 >> 0x15) + 1) * 0x200000), pCVar3 <= pCVar4
       )) {
      pCVar4 = pCVar3;
    }
    CFastStringBase<char>::PreAlloc(this_00,pCVar4,(ulong)unaff_EDI);
    *(undefined1 *)(*(int *)(param_1 + 0x18) + 0x4000 + iVar2) = 0;
    EVar5 = InternalReadFile(this,param_1,(CNetHttpResult *)(*(int *)(param_1 + 0x18) + iVar2),
                             (char *)0x4000,unaff_ESI);
    if (EVar5 == 2) {
      return 1;
    }
    if (EVar5 == 1) {
      return 0;
    }
    unaff_EDI = *(TiXmlAttributeSet **)(param_1 + 0x6c);
    if (unaff_EDI == (TiXmlAttributeSet *)0x0) break;
    unaff_ESI = 1;
    CNetTransferInfoQueue::Add
              (*(CNetTransferInfoQueue **)(this + 0x50),unaff_EDI,(TiXmlAttribute *)0x1);
  }
  *(undefined4 *)(param_1 + 0x50) = 3;
  if (*(int *)this_00 != 0) {
    *(undefined1 *)(*(int *)this_00 + *(int *)(param_1 + 0x18)) = 0;
  }
  if ((*(uint *)(param_1 + 0x1c) != 0) && (*(uint *)this_00 < *(uint *)(param_1 + 0x1c))) {
    *(undefined4 *)(param_1 + 0x50) = 4;
  }
  return 1;
}
}

// =================================================
// Function: CNetHttpClient::TerminateReq
// =================================================
void __thiscall
CNetHttpClient::TerminateReq(CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2)
{
{
  ulong unaff_ESI;
  CNetHttpResult *unaff_EDI;
  CMwNod *unaff_retaddr;
  
  if (param_1 != (CNetHttpClient *)0x0) {
    InternalTerminateReq(this,param_1,unaff_EDI);
    *(undefined4 *)(param_1 + 0x54) = 0;
    CFastBuffer<class_CGameCtnBlock*>::Remove
              (this + 0x44,
               (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)&param_2,
               unaff_ESI);
    if (*(int *)(param_1 + 0x8c) != 0) {
      (**(code **)(param_1 + 0x88))(param_1);
    }
    CMwNod::MwRelease((CMwNod *)param_1,unaff_retaddr);
  }
  return;
}
}

