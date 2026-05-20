// Class implementation: CGameNetwork

// =================================================
// Function: CGameNetwork::AddManiaNetData
// =================================================
void __thiscall
CGameNetwork::AddManiaNetData(CGameNetwork *this,CGameNetwork *param_1,CSystemData *param_2)
{
{
  TiXmlAttribute *unaff_retaddr;
  
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (this + 0x5c8,(TiXmlAttributeSet *)&param_1,unaff_retaddr);
  CMwNod::MwAddRef((CMwNod *)param_2,(CMwNod *)param_1);
  return;
}
}

// =================================================
// Function: CGameNetwork::ChatSend
// =================================================
int __thiscall
CGameNetwork::ChatSend
          (CGameNetwork *this,CGameNetwork *param_1,CFastStringInt *param_2,uchar param_3,
          uchar param_4,uchar param_5,uchar param_6,int param_7,int param_8)
{
{
  EMessageType unaff_ESI;
  CClassicArchive *in_stack_0000002c;
  void *in_stack_00000038;
  undefined4 uStack0000003c;
  int in_stack_00000050;
  CGameNetFormAdmin *in_stack_00000054;
  CClassicArchive *in_stack_ffffff98;
  int in_stack_ffffff9c;
  int in_stack_ffffffa0;
  int in_stack_ffffffa4;
  undefined **ppuVar1;
  int in_stack_ffffffac;
  ulong in_stack_ffffffb0;
  int iVar2;
  ulong in_stack_ffffffb8;
  undefined4 in_stack_ffffffbc;
  CPlugFileOggVorbis *pCVar3;
  SStreamContext **in_stack_ffffffc0;
  CCrystalVertex *in_stack_ffffffc4;
  CGameNetFormAdmin *in_stack_ffffffc8;
  CClassicArchive *in_stack_ffffffcc;
  CGameNetFormAdmin *in_stack_ffffffd0;
  CClassicArchive local_28 [8];
  CNetArchive local_20 [12];
  CGameNetwork local_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aa7830;
  local_c = ExceptionList;
  if (*(int *)(this + 0x1a8) == 0) {
    return 0;
  }
  ExceptionList = &local_c;
  if ((char)param_2 == -1) {
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
               DAT_00cca150 ^ (uint)&stack0xffffff94);
  }
  CGameNetFormAdmin::CGameNetFormAdmin
            ((CGameNetFormAdmin *)&stack0xffffffb8,(CGameNetFormAdmin *)&DAT_00000004,unaff_ESI);
  CClassicArchive::CClassicArchive((CClassicArchive *)&stack0xffffffa4,in_stack_ffffff98);
  ppuVar1 = CNetArchive::vftable;
  iVar2 = 0;
  CNetArchive::StartStoring
            ((CNetArchive *)&stack0xffffffa8,local_20,(CClassicBufferMemory *)0x1,in_stack_ffffff9c)
  ;
  CClassicArchive::WriteNat8
            ((CClassicArchive *)&stack0xffffffac,(CClassicArchive *)&param_6,(uchar *)0x1,0,
             in_stack_ffffffa0);
  CClassicArchive::WriteNat8
            ((CClassicArchive *)&stack0xffffffb0,(CClassicArchive *)&param_8,(uchar *)0x1,0,
             in_stack_ffffffa4);
  CClassicArchive::WriteNat8
            ((CClassicArchive *)&stack0xffffffb4,(CClassicArchive *)&stack0x00000028,(uchar *)0x1,0,
             (int)ppuVar1);
  CClassicArchive::WriteNat8
            ((CClassicArchive *)&stack0xffffffb8,(CClassicArchive *)&stack0x00000030,(uchar *)0x1,0,
             in_stack_ffffffac);
  CClassicArchive::WriteBool
            ((CClassicArchive *)&stack0xffffffbc,(CClassicArchive *)&stack0x00000038,(int *)0x1,
             in_stack_ffffffb0);
  pCVar3 = (CPlugFileOggVorbis *)CONCAT13(1,(int3)in_stack_ffffffbc);
  CClassicArchive::WriteNat8
            ((CClassicArchive *)&stack0xffffffc0,(CClassicArchive *)&stack0xffffffbf,(uchar *)0x1,0,
             iVar2);
  CClassicArchive::WriteString
            ((CClassicArchive *)&stack0xffffffc4,in_stack_0000002c,(CFastStringInt *)0x1,
             in_stack_ffffffb8);
  CNetArchive::EndReading((CNetArchive *)&stack0xffffffc8,pCVar3,in_stack_ffffffc0);
  if (*(int *)(this + 0x1d0) == 0) {
    iVar2 = IsConnected(this,in_stack_ffffffc4);
    if ((iVar2 != 0) && (in_stack_00000050 == 0)) {
      SendToServer(this,local_14,in_stack_ffffffc8);
      goto LAB_0061dc29;
    }
  }
  OnChatReceived(this,local_14,in_stack_00000054,(int)in_stack_ffffffc8);
LAB_0061dc29:
  in_stack_00000038 = (void *)((uint)in_stack_00000038 & 0xffffff00);
  CClassicArchive::~CClassicArchive(local_28,in_stack_ffffffcc);
  uStack0000003c = 0xffffffff;
  CGameNetFormAdmin::~CGameNetFormAdmin((CGameNetFormAdmin *)&local_c,in_stack_ffffffd0);
  ExceptionList = in_stack_00000038;
  return 1;
}
}

// =================================================
// Function: CGameNetwork::CopperTransaction_ChangeBillState
// =================================================
void __thiscall
CGameNetwork::CopperTransaction_ChangeBillState
          (CGameNetwork *this,CGameNetwork *param_1,SBill *param_2,EBillState param_3,
          CFastString *param_4)
{
{
  SStringParam *unaff_EBX;
  SStringParam *unaff_ESI;
  char *unaff_EDI;
  int local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  CFastStringInt local_34 [4];
  undefined1 local_30 [4];
  CFastStringInt local_2c [4];
  undefined1 local_28 [4];
  CFastStringInt local_24 [4];
  undefined1 local_20 [4];
  CFastStringInt local_1c [4];
  undefined1 local_18 [4];
  CFastStringInt local_14 [4];
  undefined1 local_10 [4];
  CFastStringInt local_c [8];
  
  if ((param_1 != (CGameNetwork *)0x0) && (*(int *)(param_1 + 4) != 6)) {
    switch(param_2) {
    case (SBill *)0x1:
      *(undefined4 *)(param_1 + 4) = 1;
      SStringParam::SStringParam(&local_40,(SStringParam *)"CreatingTransaction",unaff_EDI);
      CFastString::SetString((CFastString *)(param_1 + 8),(CFastStringInt *)&local_3c,unaff_ESI);
      break;
    case (SBill *)0x2:
      *(undefined4 *)(param_1 + 4) = 2;
      SStringParam::SStringParam(local_38,(SStringParam *)"Issued",unaff_EDI);
      CFastString::SetString((CFastString *)(param_1 + 8),local_34,unaff_ESI);
      break;
    case (SBill *)0x3:
      *(undefined4 *)(param_1 + 4) = 3;
      SStringParam::SStringParam(local_30,(SStringParam *)"ValidatingPayement",unaff_EDI);
      CFastString::SetString((CFastString *)(param_1 + 8),local_2c,unaff_ESI);
      break;
    case (SBill *)0x4:
      *(undefined4 *)(param_1 + 4) = 4;
      SStringParam::SStringParam(local_28,(SStringParam *)"Payed",unaff_EDI);
      CFastString::SetString((CFastString *)(param_1 + 8),local_24,unaff_ESI);
      break;
    case (SBill *)0x5:
      *(undefined4 *)(param_1 + 4) = 5;
      SStringParam::SStringParam(local_20,(SStringParam *)"Refused",unaff_EDI);
      CFastString::SetString((CFastString *)(param_1 + 8),local_1c,unaff_ESI);
      break;
    case (SBill *)0x6:
      *(undefined4 *)(param_1 + 4) = 6;
      if (*(int *)param_3 == 0) {
        SStringParam::SStringParam(local_18,(SStringParam *)"Error",unaff_EDI);
        CFastString::SetString((CFastString *)(param_1 + 8),local_14,unaff_ESI);
      }
      else {
        SStringParam::SStringParam(local_10,(SStringParam *)"Error: ",unaff_EDI);
        CFastString::SetString((CFastString *)(param_1 + 8),local_c,unaff_ESI);
        local_40 = *(int *)(param_3 + 4);
        local_3c = *(undefined4 *)param_3;
        CFastString::Concat((CFastString *)(param_1 + 8),(CFastStringInt *)&local_40,unaff_EBX);
      }
      break;
    default:
      goto switchD_00612e98_default;
    }
    if (*(int *)(*(int *)(local_40 + 0x1b8) + 0x138) != 0) {
      (**(code **)(**(int **)(*(int *)(local_40 + 0x1b8) + 0x138) + 0x14))
                (*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4),param_1 + 8,
                 *(undefined4 *)(param_1 + 0x14),this);
    }
  }
switchD_00612e98_default:
  return;
}
}

// =================================================
// Function: CGameNetwork::CopperTransaction_OnFormReceived
// =================================================
void __thiscall
CGameNetwork::CopperTransaction_OnFormReceived
          (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2)
{
{
  CGameNetFormAdmin *pCVar1;
  CGameNetwork *pCVar2;
  CGameNetwork *pCVar3;
  SCasterCat *pSVar4;
  undefined4 *extraout_EAX;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  int unaff_EDI;
  CGameNetwork *in_stack_00000010;
  undefined1 in_stack_00000014;
  undefined1 in_stack_00000018;
  CFastStringInt *in_stack_0000001c;
  undefined1 in_stack_00000024;
  void *in_stack_0000002c;
  undefined4 uStack00000030;
  int iVar5;
  CFastString *in_stack_ffffffb8;
  int in_stack_ffffffbc;
  TiXmlAttribute *in_stack_ffffffc0;
  SNationConfig *pSVar6;
  SHeaderCommunity *pSVar7;
  SHeaderCommunity *in_stack_ffffffcc;
  CPlugFileOggVorbis *in_stack_ffffffd0;
  SStreamContext **in_stack_ffffffd4;
  CClassicArchive *in_stack_ffffffd8;
  undefined4 *local_24;
  undefined **local_20;
  CClassicArchive local_1c [4];
  undefined4 local_18;
  undefined *local_14;
  CClassicArchive local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00aa7623;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CClassicArchive::CClassicArchive
            ((CClassicArchive *)&local_24,(CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffffa8)
            );
  pCVar1 = param_2;
  local_20 = CNetArchive::vftable;
  local_14 = (undefined *)0x0;
  iVar5 = 1;
  CNetArchive::StartReading((CNetArchive *)&local_20,(CPlugFileOggVorbis *)(param_2 + 0x20));
  if (*(int *)(pCVar1 + 0x1c) == 10) {
    if (*(int *)(this + 0x1d0) != 0) goto LAB_0061c564;
    in_stack_ffffffd4 = (SStreamContext **)0x0;
    in_stack_ffffffcc = (SHeaderCommunity *)0x0;
    pSVar6 = (SNationConfig *)0x0;
    local_4 = CONCAT31(local_4._1_3_,3);
    pSVar7 = (SHeaderCommunity *)PTR_DAT_00bbf7dc;
    in_stack_ffffffd0 = (CPlugFileOggVorbis *)PTR_DAT_00bbf7d8;
    CClassicArchive::ReadNatural
              ((CClassicArchive *)&local_24,(CClassicArchive *)&stack0xffffffb8,(ulong *)0x1,0,iVar5
              );
    CClassicArchive::ReadNatural
              ((CClassicArchive *)&local_20,(CClassicArchive *)&stack0xffffffc0,(ulong *)0x1,0,
               unaff_EDI);
    CClassicArchive::ReadInteger
              (local_1c,(CClassicArchive *)&stack0x0000000c,(int *)0x1,0,unaff_ESI);
    CClassicArchive::ReadString
              ((CClassicArchive *)&local_18,(CClassicArchive *)&local_20,(CFastStringInt *)0x1,
               (ulong)unaff_EBP);
    CClassicArchive::ReadString
              ((CClassicArchive *)&local_14,(CClassicArchive *)&local_24,(CFastStringInt *)0x1,
               unaff_EBX);
    CClassicArchive::ReadString
              (local_10,(CClassicArchive *)&stack0xffffffd8,(CFastStringInt *)0x1,
               (ulong)in_stack_ffffffb8);
    in_stack_ffffffd8 = operator_new(0x34);
    in_stack_00000014 = 4;
    if (in_stack_ffffffd8 == (CClassicArchive *)0x0) {
      local_24 = (undefined4 *)0x0;
    }
    else {
      SBill::SBill(in_stack_ffffffd8,(SBill *)&local_14,(CFastString *)local_1c,
                   (CFastString *)&local_24,in_stack_0000001c,in_stack_ffffffbc);
      local_24 = extraout_EAX;
    }
    *local_24 = in_stack_ffffffd4;
    local_24[5] = in_stack_ffffffd8;
    in_stack_00000018 = 3;
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this + 0x390,(TiXmlAttributeSet *)&local_24,in_stack_ffffffc0);
    CGameCtnApp::SNationConfig::~SNationConfig(local_1c,pSVar6);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(local_10,pSVar7);
  }
  else {
    if ((*(int *)(pCVar1 + 0x1c) != 0xb) || (*(int *)(this + 0x1d0) == 0)) goto LAB_0061c564;
    CClassicArchive::ReadNatural
              ((CClassicArchive *)&local_24,(CClassicArchive *)&param_1,(ulong *)0x1,0,iVar5);
    CClassicArchive::ReadNatural
              ((CClassicArchive *)&local_20,(CClassicArchive *)&stack0xffffffc4,(ulong *)0x1,0,
               unaff_EDI);
    CClassicArchive::ReadBool(local_1c,(CClassicArchive *)&stack0xffffffc0,(int *)0x1,unaff_ESI);
    pCVar2 = in_stack_00000010;
    if (in_stack_00000010 == (CGameNetwork *)0x0) goto LAB_0061c564;
    pCVar3 = (CGameNetwork *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x378,unaff_EBP);
    if (pCVar3 < pCVar2) goto LAB_0061c564;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x378,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pCVar2 + -1)
                        ,unaff_EBX);
    if (in_stack_ffffffcc != (SHeaderCommunity *)0x0) {
      CopperTransaction_ValidatePayement(this,pCVar2,(ulong)in_stack_ffffffb8);
      goto LAB_0061c564;
    }
    local_18 = 0;
    local_14 = PTR_DAT_00bbf7d8;
    in_stack_00000010 = (CGameNetwork *)CONCAT31(in_stack_00000010._1_3_,5);
    CopperTransaction_ChangeBillState
              (this,*(CGameNetwork **)pSVar4,(SBill *)&DAT_00000005,(EBillState)&local_18,
               in_stack_ffffffb8);
  }
  in_stack_00000024 = 0;
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_4,in_stack_ffffffcc);
LAB_0061c564:
  CNetArchive::EndReading((CNetArchive *)&param_2,in_stack_ffffffd0,in_stack_ffffffd4);
  uStack00000030 = 0xffffffff;
  CClassicArchive::~CClassicArchive((CClassicArchive *)&stack0x00000010,in_stack_ffffffd8);
  ExceptionList = in_stack_0000002c;
  return;
}
}

// =================================================
// Function: CGameNetwork::CopperTransaction_ValidatePayement
// =================================================
void __thiscall
CGameNetwork::CopperTransaction_ValidatePayement
          (CGameNetwork *this,CGameNetwork *param_1,ulong param_2)
{
{
  CGameNetwork *pCVar1;
  undefined *puVar2;
  CGameNetwork *pCVar3;
  SCasterCat *pSVar4;
  undefined *puVar5;
  CNetMasterServerRequest *this_00;
  SLoadedLight *pSVar6;
  ulong unaff_EBX;
  CFastString *unaff_EBP;
  CNetMasterServerRequest *unaff_ESI;
  ulong unaff_EDI;
  undefined4 uStack0000000c;
  undefined4 uStack00000010;
  void *in_stack_00000014;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffffec;
  SHeaderCommunity *in_stack_fffffff0;
  CMwNod *pCVar7;
  undefined1 *local_8;
  undefined *local_4;
  
  pCVar1 = param_1;
  local_4 = (undefined *)0xffffffff;
  local_8 = &LAB_00aa7140;
  if (param_1 != (CGameNetwork *)0x0) {
    pCVar7 = ExceptionList;
    ExceptionList = &stack0xfffffff4;
    pCVar3 = (CGameNetwork *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this + 0x378,
                        (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffdc))
    ;
    if (pCVar1 <= pCVar3) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x378,
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pCVar1 + -1),unaff_EDI)
      ;
      pCVar1 = *(CGameNetwork **)pSVar4;
      if (*(CNetMasterServerRequest **)(pCVar1 + 0x10) != (CNetMasterServerRequest *)0x0) {
        CNetMasterServerRequest::Abort(*(CNetMasterServerRequest **)(pCVar1 + 0x10),unaff_ESI);
        *(undefined4 *)(pCVar1 + 0x10) = 0;
      }
      puVar2 = PTR_DAT_00bbf7d8;
      local_8 = (undefined1 *)0x0;
      local_4 = PTR_DAT_00bbf7d8;
      param_2 = 0;
      CopperTransaction_ChangeBillState(this,pCVar1,(SBill *)0x3,(EBillState)&local_8,unaff_EBP);
      uStack0000000c = 0xffffffff;
      if (puVar2 != PTR_DAT_00bbf7d8) {
        puVar5 = puVar2 + -1;
        if ((puVar2[-1] & 0x80) != 0) {
          puVar5 = puVar2 + -4;
        }
        operator_delete__(puVar5);
      }
      this_00 = CGameMasterServer::IsCoppersTransactionPaid
                          (*(CGameMasterServer **)(this + 0x1b0),
                           *(CGameMasterServer **)(pCVar1 + 0x14),unaff_EBX);
      if (this_00 == (CNetMasterServerRequest *)0x0) {
        param_1 = (CGameNetwork *)PTR_DAT_00bbf7d8;
        uStack00000010 = 1;
        CopperTransaction_ChangeBillState
                  (this,pCVar1,(SBill *)&DAT_00000006,(EBillState)&stack0x00000000,
                   (CFastString *)in_stack_ffffffec);
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&param_1,in_stack_fffffff0);
      }
      else {
        pSVar6 = CFastBuffer<class_CMwNodRef<class_CNetMasterServerRequest>_>::AddNewElem
                           (this + 900,in_stack_ffffffec);
        if (this_00 != *(CNetMasterServerRequest **)pSVar6) {
          CMwNod::MwAddRef((CMwNod *)this_00,(CMwNod *)in_stack_fffffff0);
          if (*(CMwNod **)pSVar6 != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)pSVar6,pCVar7);
          }
          *(CNetMasterServerRequest **)pSVar6 = this_00;
        }
      }
      *(CNetMasterServerRequest **)(pCVar1 + 0x10) = this_00;
    }
  }
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CGameNetwork::DisconnectPlayer
// =================================================
int __thiscall
CGameNetwork::DisconnectPlayer
          (CGameNetwork *this,CGameNetwork *param_1,char *param_2,CFastStringInt *param_3,
          uchar param_4)
{
{
  CGameNetFormAdmin CVar1;
  CGameNetFormAdmin *pCVar2;
  CNetConnectedClient *this_00;
  int iVar3;
  CPlugFileGpuBuilder *pCVar4;
  undefined *puVar5;
  ulong unaff_EBX;
  SStringParam *unaff_EBP;
  int unaff_ESI;
  CClassicArchive *unaff_EDI;
  undefined3 in_stack_00000011;
  CClassicArchive *in_stack_0000001c;
  undefined1 uStack00000020;
  undefined4 uStack00000024;
  char *in_stack_0000002c;
  void *in_stack_00000038;
  undefined4 uStack0000003c;
  ulong in_stack_ffffff8c;
  CPlugFileOggVorbis *in_stack_ffffff90;
  SStreamContext **in_stack_ffffff94;
  ulong uVar6;
  char *pcVar7;
  CClassicArchive *pCVar8;
  CGameNetFormAdmin *pCVar9;
  LPCSTR *ppCVar10;
  CPlugFileGpuBuilder *in_stack_ffffffa8;
  char *in_stack_ffffffac;
  CPlugFileGpuBuilder *pCVar11;
  char *in_stack_ffffffb4;
  CGameNetFormAdmin *in_stack_ffffffb8;
  CClassicArchive local_40 [8];
  undefined4 local_38;
  undefined *local_34 [3];
  CNetConnectedClient local_28 [4];
  CNetArchive local_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a9e1f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CGameNetFormAdmin::CGameNetFormAdmin
            ((CGameNetFormAdmin *)&stack0xffffffb4,(CGameNetFormAdmin *)&DAT_00000005,
             (EMessageType)((uint)DAT_00cca150 ^ (uint)&stack0xffffff7c));
  CClassicArchive::CClassicArchive((CClassicArchive *)&stack0xffffffa0,unaff_EDI);
  pCVar11 = (CPlugFileGpuBuilder *)0x0;
  CNetArchive::StartStoring
            ((CNetArchive *)&stack0xffffffa4,local_24,(CClassicBufferMemory *)0x1,unaff_ESI);
  uVar6 = 0;
  if (_param_4 == (CGameNetFormAdmin *)0x0) {
    pCVar2 = (CGameNetFormAdmin *)0x0;
  }
  else {
    pCVar2 = _param_4;
    do {
      CVar1 = *pCVar2;
      pCVar2 = pCVar2 + 1;
    } while (CVar1 != (CGameNetFormAdmin)0x0);
    pCVar2 = pCVar2 + -(int)(_param_4 + 1);
  }
  pCVar8 = (CClassicArchive *)PTR_DAT_00bbf7d8;
  pCVar9 = _param_4;
  CFastString::SetString
            ((CFastString *)&stack0xffffff98,(CFastStringInt *)&stack0xffffffa0,unaff_EBP);
  CClassicArchive::WriteString
            ((CClassicArchive *)&stack0xffffffac,(CClassicArchive *)&stack0xffffff9c,
             (CFastStringInt *)0x1,unaff_EBX);
  CClassicArchive::WriteString
            ((CClassicArchive *)&stack0xffffffb0,in_stack_0000001c,(CFastStringInt *)0x1,
             in_stack_ffffff8c);
  CNetArchive::EndReading((CNetArchive *)&stack0xffffffb4,in_stack_ffffff90,in_stack_ffffff94);
  this_00 = CGameNetServer::FindConnection
                      (*(CGameNetServer **)(this + 0x1ac),
                       (CGameNetServer *)((uint)in_stack_0000002c & 0xff),uVar6);
  if (this_00 == (CNetConnectedClient *)0x0) {
    if (in_stack_ffffffb4 != PTR_DAT_00bbf7d8) {
      pcVar7 = in_stack_ffffffb4 + -1;
      if ((in_stack_ffffffb4[-1] & 0x80U) != 0) {
        pcVar7 = in_stack_ffffffb4 + -4;
      }
      operator_delete__(pcVar7);
    }
    uStack00000020 = 0;
    CClassicArchive::~CClassicArchive(local_40,pCVar8);
    uStack00000024 = 0xffffffff;
    CGameNetFormAdmin::~CGameNetFormAdmin((CGameNetFormAdmin *)local_24,pCVar9);
    iVar3 = 0;
  }
  else {
    CNetConnectedClient::Send(this_00,local_28,(CNetNod *)pCVar8);
    CNetConnectedClient::Poll(this_00,(CNetServer *)pCVar9);
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    ppCVar10 = &lpOutputString_00b2bcc4;
    pcVar7 = " - Reason : ";
    pCVar4 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Net] CGameNetwork::DisconnectPlayer (2) : ",
                        in_stack_0000002c);
    pCVar4 = CFastString::operator<<
                       ((CFastString *)pCVar4,(CPlugFileGpuBuilder *)pcVar7,(char *)_param_4);
    pCVar4 = CFastString::operator<<
                       ((CFastString *)pCVar4,(CPlugFileGpuBuilder *)ppCVar10,(char *)pCVar2);
    pCVar4 = CFastString::operator<<((CFastString *)pCVar4,in_stack_ffffffa8,in_stack_ffffffac);
    CFastString::operator<<((CFastString *)pCVar4,pCVar11,in_stack_ffffffb4);
    CClassicLog::AddLogStringInFile();
    pCVar8 = (CClassicArchive *)local_34;
    CNetServer::Disconnect(*(CNetServer **)(this + 0x1ac),(CGameMasterServer *)this_00);
    if (local_34[0] != PTR_DAT_00bbf7d8) {
      puVar5 = local_34[0] + -1;
      if ((local_34[0][-1] & 0x80) != 0) {
        puVar5 = local_34[0] + -4;
      }
      operator_delete__(puVar5);
      local_38 = 0;
      local_34[0] = PTR_DAT_00bbf7d8;
    }
    in_stack_00000038 = (void *)((uint)in_stack_00000038 & 0xffffff00);
    CClassicArchive::~CClassicArchive((CClassicArchive *)local_28,pCVar8);
    uStack0000003c = 0xffffffff;
    CGameNetFormAdmin::~CGameNetFormAdmin((CGameNetFormAdmin *)&local_c,in_stack_ffffffb8);
    iVar3 = 1;
  }
  ExceptionList = in_stack_00000038;
  return iVar3;
}
}

// =================================================
// Function: CGameNetwork::FindManiaNetData
// =================================================
CSystemData * __thiscall
CGameNetwork::FindManiaNetData(CGameNetwork *this,CGameNetwork *param_1,CFastString *param_2)
{
{
  CGameNetwork *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x5c8;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
      if (*(int *)(*(int *)pSVar2 + 0x14) == *(int *)param_2) {
        unaff_ESI = 0;
        iVar3 = CFastString::CompareNoCase
                          (param_2,(CFastStringInt *)&stack0x00000000,(SStringParam *)0x0,unaff_EBP)
        ;
        if (iVar3 == 0) {
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar4,unaff_EBX);
          return *(CSystemData **)pSVar2;
        }
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return (CSystemData *)0x0;
}
}

// =================================================
// Function: CGameNetwork::FindPlayerInfoFromLogin
// =================================================
CGameNetPlayerInfo * __thiscall
CGameNetwork::FindPlayerInfoFromLogin(CGameNetwork *this,CGameNetwork *param_1,CFastString *param_2)
{
{
  CGameNetwork *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x240;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      iVar3 = *(int *)param_2;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
      if (iVar3 == *(int *)(*(int *)pSVar2 + 0x28)) {
        unaff_ESI = 0;
        iVar3 = CFastString::CompareNoCase
                          ((CFastString *)(*(int *)pSVar2 + 0x28),(CFastStringInt *)&stack0x00000000
                           ,(SStringParam *)0x0,unaff_EBP);
        if (iVar3 == 0) {
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar4,unaff_EBX);
          return *(CGameNetPlayerInfo **)pSVar2;
        }
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return (CGameNetPlayerInfo *)0x0;
}
}

// =================================================
// Function: CGameNetwork::FindPlayerInfoFromUId
// =================================================
ulong __thiscall
CGameNetwork::FindPlayerInfoFromUId(CGameNetwork *this,CGameNetwork *param_1,uchar param_2)
{
{
  ulong uVar1;
  undefined4 in_stack_fffffff8;
  
  uVar1 = CFastBuffer<class_CGameNetPlayerInfo*>::FindKey<unsigned_char>
                    (this + 0x240,(CFastBuffer<class_CGameNetPlayerInfo*> *)&stack0xfffffff8,
                     (SFastKey<class_CGameNetPlayerInfo*,unsigned_char> *)
                     CONCAT31((int3)((uint)in_stack_fffffff8 >> 8),param_1._0_1_));
  return uVar1;
}
}

// =================================================
// Function: CGameNetwork::FormatChat
// =================================================
void __thiscall
CGameNetwork::FormatChat
          (CGameNetwork *this,CGameNetwork *param_1,CFastStringInt *param_2,ulong param_3,
          char *param_4,char *param_5,char *param_6)
{
{
  CGameNetwork *this_00;
  SCasterCat *pSVar1;
  CFastStringInt *unaff_EBX;
  ulong unaff_EBP;
  char *unaff_ESI;
  ulong unaff_EDI;
  char *in_stack_0000001c;
  SStringParam *in_stack_fffffff4;
  undefined4 local_4;
  
  this_00 = this + 0xa0;
  pSVar1 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_EDI);
  if (*(int *)pSVar1 == 0) {
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x94,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                        unaff_EBP);
    pSVar1 = CFastBuffer<struct_SFastCat>::operator[]
                       (this + 0x88,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                        *(ulong *)pSVar1);
    FormatChat(this,(CGameNetwork *)param_4,(CFastStringInt *)pSVar1,(ulong)param_5,param_6,
               in_stack_0000001c,unaff_ESI);
    pSVar1 = CFastBuffer<struct_SFastCat>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                        (ulong)&stack0x00000000);
    CFastStringInt::SetString(pSVar1,unaff_EBX,in_stack_fffffff4);
    return;
  }
  pSVar1 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                      (ulong)unaff_ESI);
  local_4 = *(undefined4 *)(pSVar1 + 4);
  CFastStringInt::SetString((void *)param_3,(CFastStringInt *)&local_4,(SStringParam *)unaff_EBX);
  return;
}
}

// =================================================
// Function: CGameNetwork::GetPlayerInfoFromUId
// =================================================
CGameNetPlayerInfo * __thiscall
CGameNetwork::GetPlayerInfoFromUId(CGameNetwork *this,CGameNetwork *param_1,uchar param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  uchar unaff_SI;
  ulong unaff_retaddr;
  
  if (((char)param_1 != -1) && ((char)param_1 != -2)) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             FindPlayerInfoFromUId(this,param_1,unaff_SI);
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x240,pCVar1,unaff_retaddr);
      return *(CGameNetPlayerInfo **)pSVar2;
    }
  }
  return (CGameNetPlayerInfo *)0x0;
}
}

// =================================================
// Function: CGameNetwork::GetState
// =================================================
EState __thiscall CGameNetwork::GetState(CGameNetwork *this,CMwCmdFiber *param_1)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_retaddr);
  return *(EState *)(*(int *)pSVar1 + 0x124);
}
}

// =================================================
// Function: CGameNetwork::IsChatCommand
// =================================================
int __thiscall
CGameNetwork::IsChatCommand(CGameNetwork *this,CGameNetwork *param_1,CFastStringInt *param_2)
{
{
  if ((*(int *)param_1 != 0) && (**(short **)(param_1 + 4) == 0x2f)) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CGameNetwork::IsConnected
// =================================================
int __thiscall CGameNetwork::IsConnected(CGameNetwork *this,CCrystalVertex *param_1)
{
{
  int iVar1;
  CCrystalVertex *unaff_retaddr;
  
  if (*(CGameNetClient **)(this + 0x1a8) != (CGameNetClient *)0x0) {
    if (*(int *)(this + 0x1d4) != 0) {
      return 1;
    }
    if (((*(int *)(*(int *)(this + 0x23c) + 0x84) != 0) &&
        (*(int *)(*(int *)(this + 0x23c) + 0x98) != 0)) &&
       (iVar1 = CGameNetClient::IsConnected(*(CGameNetClient **)(this + 0x1a8),unaff_retaddr),
       iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CGameNetwork::IsIgnored
// =================================================
int __thiscall
CGameNetwork::IsIgnored(CGameNetwork *this,CGameNetwork *param_1,CFastString *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x5c,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this + 0x5c,pCVar4,unaff_ESI);
      if (*(int *)pSVar2 == *(int *)param_2) {
        unaff_ESI = 0;
        iVar3 = CFastString::CompareNoCase
                          (param_2,(CFastStringInt *)&stack0x00000000,(SStringParam *)0x0,unaff_EBP)
        ;
        if (iVar3 == 0) {
          return 1;
        }
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return 0;
}
}

// =================================================
// Function: CGameNetwork::IsInternet
// =================================================
int __thiscall CGameNetwork::IsInternet(CGameNetwork *this,CGameNetwork *param_1)
{
{
  int iVar1;
  int extraout_ECX;
  CGameNetwork *unaff_retaddr;
  
  iVar1 = IsMasterServerConnected(this,unaff_retaddr);
  if (iVar1 == 0) {
    return 0;
  }
  return *(int *)(*(int *)(extraout_ECX + 0x1b0) + 0x188);
}
}

// =================================================
// Function: CGameNetwork::IsMasterServerConnected
// =================================================
int __thiscall CGameNetwork::IsMasterServerConnected(CGameNetwork *this,CGameNetwork *param_1)
{
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x1b0);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x174) != 0)) && (*(int *)(iVar1 + 0x17c) == 0)) {
    return *(int *)(iVar1 + 0x184);
  }
  return 0;
}
}

// =================================================
// Function: CGameNetwork::OnChatReceived
// =================================================
void __thiscall
CGameNetwork::OnChatReceived
          (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2,int param_3)
{
{
  CGameNetPlayerInfo *pCVar1;
  CGameNetPlayerInfo CVar2;
  CGameNetwork *pCVar3;
  SCasterCat *pSVar4;
  CGameNetPlayerInfo *pCVar5;
  SBitmapSpecular *pSVar6;
  int iVar7;
  CNetConnectedClient *this_00;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar8;
  undefined *puVar9;
  CFastStringInt *pCVar10;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  int unaff_EBP;
  int unaff_ESI;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar12;
  int unaff_EDI;
  bool bVar13;
  undefined *in_stack_00000010;
  undefined *in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined *in_stack_0000001c;
  undefined1 in_stack_0000002c;
  undefined1 in_stack_00000030;
  CGameNetServer *in_stack_00000038;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000003c;
  ulong in_stack_00000040;
  CNetConnectedClient *in_stack_00000044;
  undefined1 in_stack_00000048;
  undefined1 in_stack_0000004c;
  undefined1 in_stack_00000050;
  undefined1 in_stack_00000054;
  int iVar14;
  int in_stack_ffffffa4;
  CFastStringInt *pCVar15;
  CClassicArchive CVar16;
  ulong in_stack_ffffffa8;
  uchar uVar17;
  CPlugFileOggVorbis *in_stack_ffffffac;
  uchar uVar18;
  SStreamContext **in_stack_ffffffb0;
  uchar uVar19;
  CFastStringInt *in_stack_ffffffb4;
  ulong uVar20;
  uchar in_stack_ffffffbc;
  int iVar21;
  CFastString *in_stack_ffffffc0;
  SNationConfig *pSVar22;
  char *in_stack_ffffffc4;
  CGameNetServer *in_stack_ffffffc8;
  CFastStringInt *in_stack_ffffffcc;
  wchar_t *pwVar23;
  SStringParam *in_stack_ffffffd8;
  char cVar25;
  CGameNetwork *pCVar24;
  CGameNetPlayerInfo CVar26;
  SNationConfig *in_stack_ffffffe4;
  CFastStringInt *pCVar27;
  int local_14;
  CGameNetwork *local_10;
  CGameNetPlayerInfo *local_c;
  undefined1 *local_8;
  CGameNetFormAdmin *pCStack_4;
  
  pCStack_4 = (CGameNetFormAdmin *)0xffffffff;
  local_8 = &LAB_00aa77c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x1a8) == 0) {
    ExceptionList = in_stack_0000003c;
    return;
  }
  uVar20 = 0;
  CClassicArchive::CClassicArchive
            ((CClassicArchive *)&stack0xffffffdc,
             (CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffff94));
  local_14 = 0;
  iVar14 = 1;
  CNetArchive::StartReading((CNetArchive *)&stack0xffffffe0,(CPlugFileOggVorbis *)(param_2 + 0x20));
  CClassicArchive::ReadNat8
            ((CClassicArchive *)&stack0xffffffdc,(CClassicArchive *)&stack0xffffffa8,(uchar *)0x1,0,
             iVar14);
  CClassicArchive::ReadNat8
            ((CClassicArchive *)&stack0xffffffe0,(CClassicArchive *)&stack0xffffffa8,(uchar *)0x1,0,
             unaff_EDI);
  CClassicArchive::ReadNat8
            ((CClassicArchive *)&stack0xffffffe4,(CClassicArchive *)&stack0xffffffae,(uchar *)0x1,0,
             unaff_ESI);
  CClassicArchive::ReadNat8
            ((CClassicArchive *)&stack0xffffffe8,(CClassicArchive *)&stack0xffffffb1,(uchar *)0x1,0,
             unaff_EBP);
  pCVar10 = (CFastStringInt *)
            CONCAT31(CONCAT21(CONCAT11((char)((uint)in_stack_ffffffb4 >> 8),
                                       (char)((uint)in_stack_ffffffb4 >> 0x10)),
                              (char)in_stack_ffffffb4),(char)uVar20);
  CClassicArchive::ReadBool
            ((CClassicArchive *)&local_14,(CClassicArchive *)&stack0xffffffc8,(int *)0x1,unaff_EBX);
  pCVar24 = (CGameNetwork *)0x0;
  in_stack_00000010 = (undefined *)CONCAT31(in_stack_00000010._1_3_,1);
  pCVar5 = (CGameNetPlayerInfo *)PTR_DAT_00bbf7dc;
  CClassicArchive::ReadNat8
            ((CClassicArchive *)&local_10,(CClassicArchive *)&stack0xffffffbb,(uchar *)0x1,0,
             in_stack_ffffffa4);
  pCVar15 = (CFastStringInt *)0x1;
  CClassicArchive::ReadString
            ((CClassicArchive *)&local_c,(CClassicArchive *)&stack0xffffffe0,(CFastStringInt *)0x1,
             in_stack_ffffffa8);
  CVar16 = (CClassicArchive)0x69;
  CNetArchive::EndReading((CNetArchive *)&local_8,in_stack_ffffffac,in_stack_ffffffb0);
  uVar17 = 'u';
  pCVar3 = (CGameNetwork *)IsChatCommand(this,(CGameNetwork *)&local_14,in_stack_ffffffb4);
  uVar19 = '\0';
  uVar18 = 0x85;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar20);
  pCVar1 = *(CGameNetPlayerInfo **)pSVar4;
  CVar26 = pCVar1[0x24];
  pwVar23 = (wchar_t *)pCVar3;
  if (((char)pCVar3 == -1) || ((char)pCVar3 == -2)) {
    pCVar24 = (CGameNetwork *)0x0;
LAB_0061d3d1:
    CVar2 = SUB41(pCVar3,0);
    pCVar27 = (CFastStringInt *)0x0;
  }
  else {
    uVar19 = 0xa2;
    pCVar5 = GetPlayerInfoFromUId(this,pCVar3,in_stack_ffffffbc);
    pCVar3 = pCVar24;
    pCVar24 = pCVar3;
    if ((pCVar5 == (CGameNetPlayerInfo *)0x0) ||
       (iVar14 = IsIgnored(this,(CGameNetwork *)(pCVar5 + 0x28),in_stack_ffffffc0), pCVar24 = pCVar3
       , iVar14 == 0)) goto LAB_0061d3d1;
    CVar2 = SUB41(pCVar3,0);
    pCVar27 = (CFastStringInt *)0x1;
  }
  if (((char)((uint)in_stack_ffffffd8 >> 8) == '\0') && (pCVar5 == (CGameNetPlayerInfo *)0x0)) {
    if (pCVar27 != (CFastStringInt *)0x0) goto LAB_0061d6aa;
    if ((*(int *)(this + 0x1d0) == 0) || (*(int *)(this + 0xb4) == 0)) {
LAB_0061d416:
      if ((SUB41(in_stack_ffffffd8,0) != (CGameNetPlayerInfo)0xff) &&
         ((SUB41(in_stack_ffffffd8,0) != CVar26 && (CVar2 != CVar26)))) {
        iVar14 = CGameNetPlayerInfo::IsSpectator(pCVar1,(CGameNetPlayerInfo *)in_stack_ffffffc4);
        if ((iVar14 == 0) || (cVar25 = (char)((uint)pCVar24 >> 0x10), cVar25 == '\0'))
        goto LAB_0061d6aa;
        if (cVar25 == '\x01') {
          bVar13 = pCVar1[0x78] == SUB41(pCVar24,0);
        }
        else if (cVar25 == '\x02') {
          bVar13 = pCVar1[0x78] == (CGameNetPlayerInfo)0xfc;
        }
        else {
          if (cVar25 != '\x03') goto LAB_0061d6aa;
          if (pCVar1[0x78] == (CGameNetPlayerInfo)0xfc) goto LAB_0061d478;
          bVar13 = pCVar1[0x78] == SUB41(pCVar24,0);
        }
        if (!bVar13) goto LAB_0061d6aa;
      }
      goto LAB_0061d478;
    }
    if (in_stack_0000003c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)
    goto LAB_0061d6aa;
    if ((CVar2 == (CGameNetPlayerInfo)0xfe) || (CVar2 == CVar26)) goto LAB_0061d416;
  }
  else {
LAB_0061d478:
    if (in_stack_0000003c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)
    goto LAB_0061d6aa;
  }
  iVar21 = 0;
  param_2 = pCStack_4;
  param_3 = 0;
  iVar14 = 0x61d4a7;
  param_1 = (CGameNetwork *)0x0;
  pSVar6 = CFastBuffer<class_CFastStringIntForArray>::InsertNewElemAt
                     (this + 0x88,(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)0x0,
                      (ulong)&param_1);
  pSVar22 = (SNationConfig *)0x61d4ae;
  CFastStringInt::SetString
            (pSVar6,(CFastStringInt *)in_stack_ffffffc4,(SStringParam *)in_stack_ffffffc8);
  pSVar6 = CFastBuffer<class_CNetFileTransferDownload*>::InsertNewElemAt
                     (this + 0x94,(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)0x0,
                      (ulong)in_stack_ffffffcc);
  *(undefined4 *)pSVar6 = 0;
  in_stack_ffffffc8 = (CGameNetServer *)0x0;
  param_1 = (CGameNetwork *)0x0;
  in_stack_ffffffc4 = (char *)0x61d4dd;
  pSVar6 = CFastBuffer<class_CFastStringIntForArray>::InsertNewElemAt
                     (this + 0xa0,(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)0x0,
                      (ulong)&stack0x00000000);
  in_stack_ffffffcc = (CFastStringInt *)0x61d4e4;
  CFastStringInt::SetString(pSVar6,pCVar10,(SStringParam *)pwVar23);
  *(undefined4 *)(this + 0xac) = 1;
  if (local_c != (CGameNetPlayerInfo *)0x0) {
    pwVar23 = L"/version";
    pCVar10 = (CFastStringInt *)0x61d506;
    CFastStringInt::CFastStringInt(&param_2,(CFastStringInt *)L"/version",in_stack_ffffffd8);
    in_stack_00000048 = 2;
    iVar7 = IsChatCommandBis((CFastStringInt *)pCVar24,(CFastStringInt *)pCVar5);
    in_stack_00000048 = 1;
    CGameCtnApp::SNationConfig::~SNationConfig(&param_3,(SNationConfig *)pCVar24);
    if (iVar7 == 0) {
      in_stack_ffffffd8 = (SStringParam *)0x61d588;
      CFastStringInt::CFastStringInt
                (&stack0x00000010,(CFastStringInt *)L"/serverlogin",(SStringParam *)pCVar5);
      in_stack_00000050 = 4;
      iVar7 = IsChatCommandBis((CFastStringInt *)in_stack_ffffffe4,pCVar27);
      in_stack_00000050 = 1;
      pCVar5 = (CGameNetPlayerInfo *)0x61d5a6;
      CGameCtnApp::SNationConfig::~SNationConfig(&stack0x00000014,in_stack_ffffffe4);
      if (iVar7 == 0) goto LAB_0061d600;
      in_stack_00000018 = 0;
      in_stack_0000001c = PTR_DAT_00bbf7dc;
      in_stack_00000054 = 5;
      CFastStringInt::ConcatFormat
                (&stack0x00000018,(CFastStringInt *)&stack0x00000018,"Server login: %s");
      local_14 = 0;
      pCVar27 = (CFastStringInt *)0x0;
      in_stack_ffffffd8 = (SStringParam *)0xff;
      pCVar24 = (CGameNetwork *)&stack0x00000020;
    }
    else {
      in_stack_00000010 = (undefined *)0x0;
      in_stack_00000014 = PTR_DAT_00bbf7dc;
      in_stack_ffffffcc = (CFastStringInt *)&stack0x00000010;
      in_stack_0000004c = 3;
      in_stack_ffffffc8 = (CGameNetServer *)0x61d561;
      CFastStringInt::ConcatFormat(DAT_00d54314,in_stack_ffffffcc,"Server is: %s v%s (%s)");
      in_stack_ffffffd8 = (SStringParam *)0x0;
      pwVar23 = (wchar_t *)&DAT_00b2c878;
      pCVar10 = (CFastStringInt *)0xff;
      pCVar24 = (CGameNetwork *)&stack0x00000018;
    }
    pCVar5 = (CGameNetPlayerInfo *)0x0;
    ChatSend(this,pCVar24,pCVar15,(uchar)CVar16,uVar17,uVar18,uVar19,iVar14,iVar21);
    in_stack_0000002c = 1;
    CGameCtnApp::SNationConfig::~SNationConfig(&local_10,pSVar22);
  }
LAB_0061d600:
  if ((*(int *)(*(int *)(this + 0x1b8) + 0x138) != 0) &&
     ((*(int *)(this + 0xb4) == 0 || ((char)((uint)in_stack_ffffffd8 >> 8) == '\0')))) {
    (**(code **)(**(int **)(*(int *)(this + 0x1b8) + 0x138) + 0xc))();
  }
  if (*(int *)(this + 0x5c0) != 0) {
    local_c = (CGameNetPlayerInfo *)0x0;
    local_8 = PTR_DAT_00bbf7d8;
    in_stack_00000030 = 6;
    CFastStringInt::GetUtf8
              (&pCStack_4,(CFastStringInt *)&local_c,(CFastString *)0x0,(int)in_stack_ffffffc4);
    CFastString::ReplaceFirst
              ((CFastString *)&local_8,(CFastString *)&DAT_0000000a,(SStringParam *)&DAT_00000020,
               (SStringParam *)0x0,0xffffffff,(ulong)in_stack_ffffffc8);
    CFastString::ReplaceFirst
              ((CFastString *)&pCStack_4,(CFastString *)&DAT_0000000d,(SStringParam *)&DAT_00000020,
               (SStringParam *)0x0,0xffffffff,(ulong)in_stack_ffffffcc);
    in_stack_ffffffcc = (CFastStringInt *)0x1;
    in_stack_ffffffc8 = (CGameNetServer *)0x1;
    in_stack_ffffffc4 = "<chat> ";
    WriteToGameLog(this,local_10,(CGameNetPlayerInfo *)&stack0x00000000,(CFastStringInt *)"<chat> ",
                   (char *)0x1,1,(int)pCVar10);
    in_stack_00000040 = CONCAT31(in_stack_00000040._1_3_,1);
    pCVar10 = (CFastStringInt *)0x61d6aa;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&param_1,(SHeaderCommunity *)pwVar23);
  }
LAB_0061d6aa:
  if ((((*(int *)(this + 0x1d0) != 0) && (local_14 == 0)) && (pCVar5 == (CGameNetPlayerInfo *)0x0))
     && ((pCVar27 == (CFastStringInt *)0x0 &&
         (((*(int *)(this + 0xb4) == 0 ||
           (in_stack_0000003c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)) ||
          ((char)((uint)in_stack_ffffffd8 >> 8) != '\0')))))) {
    if ((char)in_stack_ffffffd8 == -1) {
      CGameNetServer::SendAll
                (*(CGameNetServer **)(this + 0x1ac),in_stack_00000038,(CNetNod *)in_stack_ffffffc4);
    }
    else {
      in_stack_00000040 =
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this + 0x240,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffc4);
      pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (in_stack_00000040 != 0) {
        do {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0x240,pCVar11,(ulong)in_stack_ffffffc4);
          pCVar1 = *(CGameNetPlayerInfo **)pSVar4;
          if (pCVar1 == local_c) goto switchD_0061d749_default;
          in_stack_ffffffc4 = (char *)0x61d73b;
          iVar14 = CGameNetPlayerInfo::IsSpectator(pCVar1,(CGameNetPlayerInfo *)0x61d73b);
          CVar26 = SUB41(pCVar5,0);
          if (iVar14 == 0) {
LAB_0061d77b:
            bVar13 = pCVar1[0x24] == CVar26;
            goto LAB_0061d77e;
          }
          switch((uint)pCVar5 >> 0x10 & 0xff) {
          case 0:
            bVar13 = pCVar1[0x24] == CVar26;
            goto LAB_0061d77e;
          case 1:
            if (pCVar1[0x78] != CVar26) goto LAB_0061d77b;
            break;
          case 2:
            bVar13 = pCVar1[0x78] == (CGameNetPlayerInfo)0xfc;
LAB_0061d77e:
            if (bVar13) break;
            goto switchD_0061d749_default;
          case 3:
            if (pCVar1[0x78] != (CGameNetPlayerInfo)0xfc) {
              bVar13 = pCVar1[0x78] == CVar26;
              goto LAB_0061d77e;
            }
            break;
          default:
            goto switchD_0061d749_default;
          }
          in_stack_ffffffc8 = (CGameNetServer *)(uint)(byte)pCVar1[0x24];
          in_stack_ffffffc4 = (char *)0x61d790;
          this_00 = CGameNetServer::FindConnection
                              (*(CGameNetServer **)(this + 0x1ac),in_stack_ffffffc8,
                               (ulong)in_stack_ffffffcc);
          if (this_00 != (CNetConnectedClient *)0x0) {
            in_stack_ffffffc8 = (CGameNetServer *)0x61d7a0;
            in_stack_ffffffcc = (CFastStringInt *)in_stack_00000044;
            CNetConnectedClient::Send(this_00,in_stack_00000044,(CNetNod *)pCVar10);
          }
switchD_0061d749_default:
          pCVar11 = pCVar11 + 1;
        } while (pCVar11 < in_stack_0000003c);
      }
    }
  }
  pCVar12 = (CFastBuffer<class_CSystemFidsFolder*> *)(uint)*(ushort *)(this + 0xb0);
  pCVar8 = (CFastBuffer<class_CSystemFidsFolder*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this + 0x88,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffc4);
  if (pCVar12 < pCVar8) {
    CFastBuffer<class_CSystemFidsFolder*>::SetCount(this + 0x88,pCVar12,(ulong)in_stack_ffffffc8);
    CFastBuffer<class_CSystemFidsFolder*>::SetCount(this + 0x94,pCVar12,(ulong)in_stack_ffffffcc);
    CFastBuffer<class_CSystemFidsFolder*>::SetCount(this + 0xa0,pCVar12,(ulong)pCVar10);
  }
  if (in_stack_00000010 != PTR_DAT_00bbf7dc) {
    if ((in_stack_00000010[-1] & 0x80) == 0) {
      puVar9 = in_stack_00000010 + -2;
    }
    else {
      puVar9 = in_stack_00000010 + -4;
    }
    operator_delete__(puVar9);
    param_3 = 0;
    in_stack_00000010 = PTR_DAT_00bbf7dc;
  }
  in_stack_00000040 = 0xffffffff;
  CClassicArchive::~CClassicArchive((CClassicArchive *)&stack0x00000020,(CClassicArchive *)pwVar23);
  ExceptionList = in_stack_0000003c;
  return;
}
}

// =================================================
// Function: CGameNetwork::OnDisplayManialinkPageReceived
// =================================================
void __thiscall
CGameNetwork::OnDisplayManialinkPageReceived
          (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2)
{
{
  char cVar1;
  SCasterCat *pSVar2;
  undefined *puVar3;
  ulong unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 uStack0000000c;
  void *in_stack_0000001c;
  undefined4 uStack00000020;
  int iVar4;
  CPlugFileOggVorbis *in_stack_ffffffc8;
  SStreamContext **in_stack_ffffffcc;
  ulong in_stack_ffffffd0;
  ulong in_stack_ffffffd4;
  CClassicArchive *in_stack_ffffffd8;
  CClassicArchive local_24 [4];
  undefined **local_20;
  undefined4 local_1c;
  undefined *local_18;
  undefined4 local_14;
  int local_10;
  void *local_c;
  undefined1 *local_8;
  undefined *local_4;
  
  local_4 = (undefined *)0xffffffff;
  local_8 = &LAB_00aa6970;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CClassicArchive::CClassicArchive
            (local_24,(CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffffb8));
  local_20 = CNetArchive::vftable;
  local_14 = 0;
  iVar4 = 1;
  CNetArchive::StartReading((CNetArchive *)&local_20,(CPlugFileOggVorbis *)(param_2 + 0x20));
  CClassicArchive::ReadNat8(local_24,(CClassicArchive *)&stack0xffffffca,(uchar *)0x1,0,iVar4);
  CClassicArchive::ReadNat8
            ((CClassicArchive *)&local_20,(CClassicArchive *)&stack0xffffffcf,(uchar *)0x1,0,
             unaff_EDI);
  CClassicArchive::ReadNat8
            ((CClassicArchive *)&local_1c,(CClassicArchive *)&stack0xffffffd8,(uchar *)0x1,0,
             unaff_ESI);
  CClassicArchive::ReadNatural
            ((CClassicArchive *)&local_18,(CClassicArchive *)&stack0xffffffd8,(ulong *)0x1,0,
             unaff_EBP);
  local_1c = 0;
  local_18 = PTR_DAT_00bbf7d8;
  uStack0000000c = 1;
  CClassicArchive::ReadString
            ((CClassicArchive *)&local_14,(CClassicArchive *)&local_1c,(CFastStringInt *)0x1,
             unaff_EBX);
  CNetArchive::EndReading((CNetArchive *)&local_10,in_stack_ffffffc8,in_stack_ffffffcc);
  cVar1 = local_1c._2_1_;
  if (local_1c._2_1_ != -1) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        in_stack_ffffffd0);
    if ((*(int *)pSVar2 != 0) &&
       (pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            in_stack_ffffffd4), *(char *)(*(int *)pSVar2 + 0x24) != cVar1))
    goto LAB_00613bbc;
  }
  if (local_10 != 0) {
    CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),(CMwTimerAdapter *)in_stack_ffffffd8);
  }
  (**(code **)(*(int *)this + 0xb0))();
LAB_00613bbc:
  if (local_4 != PTR_DAT_00bbf7d8) {
    puVar3 = local_4 + -1;
    if ((local_4[-1] & 0x80) != 0) {
      puVar3 = local_4 + -4;
    }
    operator_delete__(puVar3);
    local_8 = (undefined1 *)0x0;
    local_4 = PTR_DAT_00bbf7d8;
  }
  uStack00000020 = 0xffffffff;
  CClassicArchive::~CClassicArchive((CClassicArchive *)&stack0x00000000,in_stack_ffffffd8);
  ExceptionList = in_stack_0000001c;
  return;
}
}

// =================================================
// Function: CGameNetwork::OnHideManialinkPageReceived
// =================================================
void __thiscall CGameNetwork::OnHideManialinkPageReceived(CGameNetwork *this,CGameNetwork *param_1)
{
{
  undefined *puVar1;
  void *unaff_ESI;
  undefined *puVar2;
  CFastString local_14 [4];
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aa6998;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastString::CFastString
            (local_14,(CFastString *)&DAT_00b2c878,(char *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  puVar2 = (undefined *)0x1;
  (**(code **)(*(int *)this + 0xb0))(local_10,0,0);
  if (puVar2 != PTR_DAT_00bbf7d8) {
    puVar1 = puVar2 + -1;
    if ((puVar2[-1] & 0x80) != 0) {
      puVar1 = puVar2 + -4;
    }
    operator_delete__(puVar1);
  }
  ExceptionList = unaff_ESI;
  return;
}
}

// =================================================
// Function: CGameNetwork::OnManialinkPageAnswerReceived
// =================================================
void __thiscall
CGameNetwork::OnManialinkPageAnswerReceived
          (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2)
{
{
  CGameNetPlayerInfo *pCVar1;
  CGameNetFormAdmin *pCVar2;
  uchar *puVar3;
  uint64 *unaff_EBX;
  ECipherOpMode unaff_EBP;
  CFastString *unaff_ESI;
  int unaff_EDI;
  undefined1 uStack00000018;
  void *in_stack_0000002c;
  undefined4 uStack00000030;
  int iVar4;
  int in_stack_ffffffc4;
  CMwId *in_stack_ffffffc8;
  CFastStringInt *in_stack_ffffffcc;
  int in_stack_ffffffd0;
  CPlugFileOggVorbis *in_stack_ffffffd4;
  SStreamContext **in_stack_ffffffd8;
  CClassicArchive CVar5;
  SHeaderCommunity *pSVar6;
  CClassicArchive *in_stack_ffffffe4;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined1 *local_8;
  CGameNetwork *local_4;
  
  local_4 = (CGameNetwork *)0xffffffff;
  local_8 = &LAB_00aa73c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x1d0) != 0) {
    CClassicArchive::CClassicArchive
              ((CClassicArchive *)&stack0xffffffdc,
               (CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffffb4));
    local_14 = 0;
    iVar4 = 1;
    CNetArchive::StartReading
              ((CNetArchive *)&stack0xffffffe0,(CPlugFileOggVorbis *)(param_2 + 0x20));
    CClassicArchive::ReadNat8
              ((CClassicArchive *)&stack0xffffffdc,(CClassicArchive *)&stack0xffffffd0,(uchar *)0x1,
               0,iVar4);
    CClassicArchive::ReadNat8
              ((CClassicArchive *)&stack0xffffffe0,(CClassicArchive *)&stack0xffffffcb,(uchar *)0x1,
               0,unaff_EDI);
    CVar5 = (CClassicArchive)0x0;
    param_1 = (CGameNetwork *)CONCAT31(param_1._1_3_,1);
    pSVar6 = (SHeaderCommunity *)PTR_DAT_00bbf7d8;
    CClassicArchive::DoString
              ((CClassicArchive *)&stack0xffffffe4,(CClassicCrypto_BlowFish *)&stack0xffffffdc,
               (CFastString *)0x1,unaff_ESI,unaff_EBP,unaff_EBX,in_stack_ffffffc4);
    CMwId::CMwId(&stack0xffffffe0,in_stack_ffffffc8);
    uStack00000018 = 2;
    if (local_10 != 0) {
      CMwId::SetLocalName(&stack0xffffffe4,local_c,in_stack_ffffffcc);
    }
    CClassicArchive::ReadNatural
              ((CClassicArchive *)&local_4,(CClassicArchive *)&local_14,(ulong *)0x1,0,
               in_stack_ffffffd0);
    CNetArchive::EndReading((CNetArchive *)&stack0x00000000,in_stack_ffffffd4,in_stack_ffffffd8);
    pCVar1 = GetPlayerInfoFromUId(this,local_4,(uchar)CVar5);
    if (pCVar1 == (CGameNetPlayerInfo *)0x0) {
      in_stack_0000002c = (void *)CONCAT31(in_stack_0000002c._1_3_,1);
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pSVar6);
      if (param_2 != (CGameNetFormAdmin *)PTR_DAT_00bbf7d8) {
        pCVar2 = param_2 + -1;
        if (((byte)param_2[-1] & 0x80) != 0) {
          pCVar2 = param_2 + -4;
        }
        operator_delete__(pCVar2);
        param_1 = (CGameNetwork *)0x0;
        param_2 = (CGameNetFormAdmin *)PTR_DAT_00bbf7d8;
      }
    }
    else {
      puVar3 = Manialink_GetClientUpdateIdForSubPage
                         ((CFastBuffer<struct_CGameNetPlayerInfo::SPagesOnClient> *)&local_8,
                          (CMwId *)0x0,(int)pSVar6);
      if ((local_c._3_1_ != '\0') && (local_c._3_1_ == *puVar3)) {
        *(CGameNetwork **)(pCVar1 + 0xbc) = local_4;
        *(undefined1 **)(pCVar1 + 0xc0) = local_8;
        *(undefined4 *)(pCVar1 + 0xc4) = 1;
        if (*(int *)(*(int *)(this + 0x1b8) + 0x138) != 0) {
          (**(code **)(**(int **)(*(int *)(this + 0x1b8) + 0x138) + 0x10))();
        }
      }
      in_stack_0000002c = (void *)CONCAT31(in_stack_0000002c._1_3_,1);
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pSVar6);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&param_1,pSVar6);
    }
    uStack00000030 = 0xffffffff;
    CClassicArchive::~CClassicArchive((CClassicArchive *)&stack0x00000010,in_stack_ffffffe4);
  }
  ExceptionList = in_stack_0000002c;
  return;
}
}

// =================================================
// Function: CGameNetwork::OnNetFormAdminReceived
// =================================================
void __thiscall
CGameNetwork::OnNetFormAdminReceived
          (CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2,
          CNetConnectedClient *param_3)
{
{
  CPlugFileOggVorbis *pCVar1;
  CGameNetwork *this_00;
  SStringParamInt *pSVar2;
  int iVar3;
  CNetConnectedClient *pCVar4;
  CClassicArchive *pCVar5;
  int iVar6;
  CGameNetPlayerInfo *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  SCasterCat *pSVar8;
  ulong *puVar9;
  ulong uVar10;
  SStringParamInt *unaff_EBX;
  SStringParam *unaff_EBP;
  CClassicArchive *unaff_ESI;
  uint uVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  CFastStringInt *unaff_EDI;
  int in_stack_00000010;
  CNetConnectedClient *in_stack_00000018;
  undefined1 in_stack_0000001c;
  undefined1 in_stack_00000020;
  void *in_stack_00000024;
  void *in_stack_00000028;
  undefined1 in_stack_0000002c;
  CGameNetwork *pCVar13;
  SNationConfig *pSVar14;
  int *piVar15;
  uchar uVar16;
  CPlugFileOggVorbis *in_stack_ffffff34;
  CPlugFileOggVorbis *in_stack_ffffff38;
  CFastStringInt *in_stack_ffffff3c;
  CClassicArchive CVar17;
  byte bVar21;
  SStringParam *in_stack_ffffff40;
  undefined *puVar18;
  CClassicArchive *pCVar19;
  SStringParam *pSVar20;
  SNationConfig SVar22;
  CGameNetwork *in_stack_ffffff44;
  SStringParam *pSVar23;
  undefined4 uVar24;
  CGameNetFormAdmin *pCVar25;
  CNetArchive *pCVar26;
  CClassicI18n *pCVar27;
  CGameNetwork *in_stack_ffffff4c;
  int in_stack_ffffff50;
  undefined **local_ac;
  CClassicArchive local_a8 [3];
  SNationConfig SStack_a5;
  CGameNetwork local_a4 [4];
  SStringParam *local_a0 [2];
  undefined1 uStack_96;
  CNetArchive local_94 [4];
  CGameNetwork *local_90 [2];
  CClassicArchive local_88 [4];
  CClassicArchive local_84 [4];
  CClassicArchive local_80 [8];
  CClassicI18n *local_78;
  CClassicArchive local_74 [4];
  undefined4 local_70;
  uint uStack_6c;
  undefined **ppuStack_68;
  undefined **local_64;
  int local_60;
  int local_5c;
  SStringParamInt local_58 [8];
  undefined1 local_50 [4];
  CFastStringInt local_4c [8];
  SStringParam local_44 [20];
  CNetConnectedClient aCStack_30 [4];
  CNetConnectedClient local_2c [4];
  CGameNetFormAdmin aCStack_28 [4];
  CGameNetFormAdmin local_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9e3d2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar6 = *(int *)(this + 0x1d0);
  pCVar26 = (CNetArchive *)this;
  CClassicArchive::CClassicArchive
            ((CClassicArchive *)&stack0xffffff50,
             (CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffff24));
  pCVar25 = param_2;
  local_ac = CNetArchive::vftable;
  local_a0[0] = (SStringParam *)0x0;
  pCVar13 = (CGameNetwork *)0x1;
  pCVar1 = (CPlugFileOggVorbis *)(param_2 + 0x20);
  CNetArchive::StartReading((CNetArchive *)&local_ac,pCVar1);
  switch(*(undefined4 *)(pCVar25 + 0x1c)) {
  case 0:
    if ((iVar6 == 0) && (iVar6 = (**(code **)(*(int *)pCVar1 + 0x18))(), iVar6 != 0)) {
      CClassicArchive::ReadNat8
                (local_a8,(CClassicArchive *)&stack0xffffff44,(uchar *)0x1,0,(int)unaff_ESI);
      unaff_ESI = (CClassicArchive *)pCVar26;
      pCVar13 = local_a4;
      (**(code **)(**(int **)(this + 0x23c) + 0xa4))();
      iVar6 = *(int *)(this + 0x23c);
      puVar9 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),(CMwTimerAdapter *)pCVar13);
      *(ulong *)(iVar6 + 0x90) = *puVar9;
      uVar10 = (**(code **)(**(int **)(this + 0x23c) + 200))();
      CGameNetFormGameSync::SetPlayerDataSize(uVar10);
    }
    break;
  case 1:
    iVar3 = (**(code **)(*(int *)pCVar1 + 0x18))();
    if (iVar3 != 0) {
      uVar11 = 0;
      if (iVar6 == 0) {
        CClassicArchive::ReadNat8
                  (local_a8,(CClassicArchive *)&stack0xffffff40,(uchar *)0x1,0,(int)unaff_ESI);
        SVar22 = SUB41(in_stack_ffffff44,0);
        while ((SVar22 != (SNationConfig)0xff && (uVar11 = uVar11 + 1, uVar11 < 0xff))) {
          CClassicArchive::ReadNat8
                    (local_a8,(CClassicArchive *)&stack0xffffff3d,(uchar *)0x1,0,(int)unaff_ESI);
          UpdatePlayerInfo(this,local_a4,(CNetArchive *)in_stack_ffffff44,(uchar)&stack0xffffff48,
                           (int *)((uint)in_stack_ffffff40 >> 8 & 0xff),0,0xd71c9c,
                           (CFastString *)unaff_EBP);
          unaff_EBP = (SStringParam *)0x0;
          unaff_ESI = (CClassicArchive *)0x1;
          CClassicArchive::ReadNat8
                    ((CClassicArchive *)local_a0,(CClassicArchive *)&stack0xffffff48,(uchar *)0x1,0,
                     (int)unaff_EBX);
          SVar22 = SUB41(in_stack_ffffff4c,0);
        }
      }
      else {
        pSVar20 = *(SStringParam **)(in_stack_00000010 + 0x10);
        pSVar23 = pSVar20;
        CClassicArchive::ReadNat8
                  (local_a8,(CClassicArchive *)&stack0xffffff40,(uchar *)0x1,0,(int)unaff_ESI);
        CVar17 = SUB41(pSVar23,0);
        while (CVar17 != (CClassicArchive)0xff) {
          uVar16 = (uchar)in_stack_ffffff34;
          uStack_6c = uVar11 + 1;
          if (1 < uStack_6c) break;
          in_stack_ffffff3c =
               (CFastStringInt *)
               CONCAT22((short)((uint)in_stack_ffffff3c >> 0x10),
                        CONCAT11(1,SUB41(in_stack_ffffff3c,0)));
          CClassicArchive::ReadNat8
                    (local_a8,(CClassicArchive *)&stack0xffffff3d,(uchar *)0x1,0,(int)unaff_ESI);
          if (pSVar20[4] != SUB41(pSVar23,0)) break;
          unaff_ESI = (CClassicArchive *)((uint)pSVar23 & 0xff);
          pCVar4 = CGameNetServer::FindConnection
                             (*(CGameNetServer **)(this + 0x1ac),(CGameNetServer *)unaff_ESI,
                              (ulong)unaff_EBP);
          if (pCVar4 != in_stack_00000018) break;
          pCVar5 = (CClassicArchive *)((uint)pSVar23 >> 8 & 0xff);
          unaff_EBP = pSVar20 + 8;
          unaff_ESI = (CClassicArchive *)0x1;
          piVar15 = &local_60;
          iVar6 = UpdatePlayerInfo(this,(CGameNetwork *)local_a0,pCVar26,(uchar)piVar15,
                                   (int *)pCVar5,1,(int)unaff_EBP,(CFastString *)unaff_EBX);
          if (local_5c != 0) break;
          unaff_EBP = (SStringParam *)0x5b9355;
          pCVar13 = in_stack_ffffff4c;
          this_01 = GetPlayerInfoFromUId(this,in_stack_ffffff4c,uVar16);
          unaff_EBX = (SStringParamInt *)in_stack_ffffff4c;
          if (this_01 == (CGameNetPlayerInfo *)0x0) break;
          in_stack_ffffff34 = (CPlugFileOggVorbis *)0x5b9366;
          CGameNetPlayerInfo::SetDirty
                    (this_01,(CPlugVertexStream *)unaff_ESI,(int)in_stack_ffffff3c);
          if (iVar6 != 0) {
            local_60 = *(int *)(pSVar20 + 0x1c);
            local_5c = *(int *)(pSVar20 + 0x18);
            in_stack_ffffff3c = (CFastStringInt *)&local_60;
            pCVar4 = (CNetConnectedClient *)0x5b9389;
            CFastString::SetString
                      ((CFastString *)(this_01 + 0x40),in_stack_ffffff3c,in_stack_ffffff40);
            *(undefined4 *)(this_01 + 0x48) = *(undefined4 *)(pSVar20 + 0x20);
            *(undefined4 *)(this_01 + 0x4c) = *(undefined4 *)(pSVar20 + 0x24);
            *(undefined4 *)(this_01 + 0x50) = *(undefined4 *)(pSVar20 + 0x28);
            this_00 = this + 0x240;
            *(undefined4 *)(this_01 + 0x54) = *(undefined4 *)(pSVar20 + 0x2c);
            pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     CFastBuffer<class_CCrystalFace*>::GetCount
                               (this_00,(CFastBuffer<class_CCrystalFace*> *)pSVar23);
            pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              do {
                pCVar19 = (CClassicArchive *)0x5b93c8;
                CGameNetFormAdmin::CGameNetFormAdmin
                          (local_24,(CGameNetFormAdmin *)0x1,(EMessageType)pCVar26);
                in_stack_00000028 = (void *)CONCAT31(in_stack_00000028._1_3_,4);
                CClassicArchive::CClassicArchive
                          ((CClassicArchive *)&uStack_6c,(CClassicArchive *)pCVar13);
                uVar11 = 0;
                ppuStack_68 = CNetArchive::vftable;
                local_5c = 0;
                pCVar13 = (CGameNetwork *)0x1;
                pCVar26 = (CNetArchive *)&param_1;
                in_stack_0000002c = 5;
                uVar24 = 0x5b9402;
                CNetArchive::StartStoring
                          ((CNetArchive *)&ppuStack_68,pCVar26,(CClassicBufferMemory *)0x1,
                           in_stack_ffffff50);
                uStack_96 = 1;
                while ((pCVar12 < pCVar7 && (uVar11 < DAT_00ce9c24))) {
                  pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     (this_00,pCVar12,(ulong)in_stack_ffffff4c);
                  SStack_a5 = *(SNationConfig *)(*(int *)pSVar8 + 0x24);
                  if (SUB41(pCVar13,0) != SStack_a5) {
                    CClassicArchive::WriteNat8
                              (local_84,(CClassicArchive *)&SStack_a5,(uchar *)0x1,0,
                               (int)in_stack_ffffff34);
                    in_stack_ffffff4c = (CGameNetwork *)0x1;
                    CClassicArchive::WriteNat8
                              (local_80,(CClassicArchive *)&stack0xffffff4e,(uchar *)0x1,0,
                               (int)pCVar4);
                    pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                       (this_00,pCVar12,(ulong)in_stack_ffffff3c);
                    in_stack_ffffff3c = (CFastStringInt *)0x1;
                    pCVar4 = (CNetConnectedClient *)&local_78;
                    in_stack_ffffff34 = (CPlugFileOggVorbis *)0x5b946b;
                    (**(code **)(**(int **)pSVar8 + 0x78))();
                    uVar11 = uVar11 + 1;
                  }
                  pCVar12 = pCVar12 + 1;
                }
                unaff_EBP = (SStringParam *)0x0;
                unaff_ESI = (CClassicArchive *)0x1;
                pCVar5 = (CClassicArchive *)&stack0xffffff47;
                pCVar25 = (CGameNetFormAdmin *)CONCAT13(0xff,(int3)uVar24);
                piVar15 = (int *)0x5b948c;
                CClassicArchive::WriteNat8(local_88,pCVar5,(uchar *)0x1,0,(int)in_stack_ffffff4c);
                in_stack_ffffff4c = (CGameNetwork *)0x5b9495;
                CNetArchive::EndReading
                          ((CNetArchive *)local_84,in_stack_ffffff34,(SStreamContext **)pCVar4);
                pCVar4 = aCStack_30;
                in_stack_ffffff34 = (CPlugFileOggVorbis *)0x5b94a9;
                CNetConnectedClient::Send(in_stack_00000024,pCVar4,(CNetNod *)in_stack_ffffff3c);
                in_stack_0000001c = 4;
                in_stack_ffffff3c = (CFastStringInt *)0x5b94ba;
                CClassicArchive::~CClassicArchive((CClassicArchive *)&local_78,pCVar19);
                in_stack_00000020 = 0;
                CGameNetFormAdmin::~CGameNetFormAdmin(aCStack_28,pCVar25);
                this = local_90[0];
              } while (pCVar12 < pCVar7);
            }
            pSVar20 = (SStringParam *)0x5b94ec;
            pSVar23 = local_a0[0];
            (**(code **)(*(int *)this + 0x94))();
            Sv_SendServerInfo(this,(CGameNetwork *)param_2,(CNetConnectedClient *)0x1,(int)piVar15);
            in_stack_ffffff40 = pSVar20;
          }
          CClassicArchive::ReadNat8
                    ((CClassicArchive *)&local_ac,(CClassicArchive *)&stack0xffffff3c,(uchar *)0x1,0
                     ,(int)pCVar5);
          uVar11 = uStack_6c;
          unaff_EBX = (SStringParamInt *)in_stack_ffffff4c;
          in_stack_ffffff4c = pCVar13;
          CVar17 = SUB41(in_stack_ffffff40,0);
        }
      }
    }
    break;
  case 2:
    if (iVar6 == 0) {
      CClassicArchive::ReadNat8
                ((CClassicArchive *)&stack0xffffff50,(CClassicArchive *)&stack0xffffff38,
                 (uchar *)0x1,0,(int)pCVar13);
      pCVar13 = (CGameNetwork *)
                FindPlayerInfoFromUId(this,(CGameNetwork *)in_stack_ffffff3c,(uchar)unaff_EDI);
      if ((pCVar13 != (CGameNetwork *)0xffffffff) && (pCVar13 != (CGameNetwork *)0x0)) {
        RemovePlayerInfo(this,pCVar13,(ulong)unaff_ESI);
      }
    }
    break;
  case 4:
    OnChatReceived(this,(CGameNetwork *)pCVar25,(CGameNetFormAdmin *)0x0,(int)pCVar13);
    break;
  case 5:
    if (iVar6 == 0) {
      pCVar27 = (CClassicI18n *)0x0;
      local_4 = CONCAT31(local_4._1_3_,3);
      CClassicArchive::ReadString
                ((CClassicArchive *)&stack0xffffff50,(CClassicArchive *)&stack0xffffff3c,
                 (CFastStringInt *)0x1,(ulong)pCVar13);
      pSVar14 = (SNationConfig *)0x1;
      CClassicArchive::ReadString
                ((CClassicArchive *)&local_ac,(CClassicArchive *)&stack0xffffff4c,
                 (CFastStringInt *)0x1,(ulong)unaff_EDI);
      if (in_stack_ffffff44 != (CGameNetwork *)0x0) {
        if (in_stack_ffffff50 == 0) {
          unaff_EDI = (CFastStringInt *)&local_78;
          local_70 = 0;
          pSVar14 = (SNationConfig *)0x5b91ef;
          local_78 = pCVar27;
          CFastStringInt::SetString(this + 0x10c,unaff_EDI,(SStringParam *)unaff_ESI);
        }
        else {
          local_64 = local_ac;
          local_5c = 0;
          pSVar14 = (SNationConfig *)0x5b918d;
          local_60 = in_stack_ffffff50;
          pSVar2 = (SStringParamInt *)
                   CClassicI18n::GetTranslatedStringInternal
                             ((CClassicI18n *)&DAT_00d71d10,pCVar27,(wchar_t *)unaff_ESI);
          SStringParamInt::SStringParamInt(local_4c,pSVar2,(wchar_t *)unaff_EBP);
          SStringParam::SStringParam(local_50,(SStringParam *)"|notrad|%1\n(%2)",(char *)unaff_EBX);
          unaff_EBX = local_58;
          unaff_EBP = local_44;
          unaff_ESI = (CClassicArchive *)local_4c;
          unaff_EDI = (CFastStringInt *)0x5b91cb;
          CFastStringInt::SetCompose(this + 0x10c,(CFastStringInt *)unaff_ESI,unaff_EBP,unaff_EBX);
        }
      }
      CGameCtnApp::SNationConfig::~SNationConfig(&stack0xffffff48,pSVar14);
      CGameCtnApp::SNationConfig::~SNationConfig(&stack0xffffff40,(SNationConfig *)unaff_EDI);
    }
    break;
  case 7:
    OnDisplayManialinkPageReceived(this,(CGameNetwork *)pCVar25,(CGameNetFormAdmin *)pCVar13);
    break;
  case 8:
    if (iVar6 != 0) {
      OnManialinkPageAnswerReceived(this,(CGameNetwork *)pCVar25,(CGameNetFormAdmin *)pCVar13);
    }
    break;
  case 9:
    OnHideManialinkPageReceived(this,pCVar13);
    break;
  case 10:
  case 0xb:
    CopperTransaction_OnFormReceived(this,(CGameNetwork *)pCVar25,(CGameNetFormAdmin *)pCVar13);
    break;
  case 0xc:
    local_4 = CONCAT31(local_4._1_3_,1);
    puVar18 = PTR_DAT_00bbf7dc;
    CClassicArchive::ReadString
              ((CClassicArchive *)&stack0xffffff50,(CClassicArchive *)&stack0xffffff3c,
               (CFastStringInt *)0x1,(ulong)pCVar13);
    bVar21 = (byte)((uint)puVar18 >> 8);
    uVar16 = (uchar)unaff_EBP;
    CClassicArchive::ReadNat8
              ((CClassicArchive *)&local_ac,(CClassicArchive *)&stack0xffffff3c,(uchar *)0x1,0,
               (int)unaff_EDI);
    CClassicArchive::ReadNat8
              (local_a8,(CClassicArchive *)&stack0xffffff3d,(uchar *)0x1,0,(int)unaff_ESI);
    if (bVar21 == 0xff) {
      unaff_EBP = (SStringParam *)0xffffffff;
    }
    else {
      unaff_EBP = (SStringParam *)((uint)bVar21 * 1000);
    }
    if ((char)in_stack_ffffff44 == -1) {
      unaff_ESI = (CClassicArchive *)0x0;
    }
    else {
      unaff_ESI = (CClassicArchive *)GetPlayerInfoFromUId(this,in_stack_ffffff44,uVar16);
    }
    pSVar14 = (SNationConfig *)&stack0xffffff4c;
    (**(code **)(*(int *)this + 0xb4))();
    CGameCtnApp::SNationConfig::~SNationConfig(&stack0xffffff40,pSVar14);
    break;
  case 0xd:
    if (iVar6 != 0) {
      CGameNetFormAdmin::CGameNetFormAdmin
                ((CGameNetFormAdmin *)local_4c,(CGameNetFormAdmin *)&DAT_0000000e,
                 (EMessageType)pCVar13);
      CNetArchive::CNetArchive(local_94,(CNetArchive *)unaff_EDI);
      param_1 = (CGameNetwork *)CONCAT31(param_1._1_3_,7);
      CNetArchive::StartStoring
                ((CNetArchive *)local_90,(CNetArchive *)local_24,(CClassicBufferMemory *)0x1,
                 (int)unaff_ESI);
      CGamePlayerUIdAllocator::GetUnallocatedRange
                (&DAT_00d6a358,(CGamePlayerUIdAllocator *)&stack0xffffff43,&stack0xffffff42,
                 (uchar *)unaff_EBP);
      CClassicArchive::DoNat8
                (local_88,(CClassicArchive *)&stack0xffffff47,(uchar *)0x1,0,(int)unaff_EBX);
      unaff_EBX = (SStringParamInt *)0x0;
      unaff_EBP = (SStringParam *)0x1;
      unaff_ESI = (CClassicArchive *)&stack0xffffff4a;
      CClassicArchive::DoNat8(local_84,unaff_ESI,(uchar *)0x1,0,(int)in_stack_ffffff34);
      CNetArchive::EndReading
                ((CNetArchive *)local_80,in_stack_ffffff38,(SStreamContext **)in_stack_ffffff3c);
      CNetConnectedClient::Send(in_stack_00000028,local_2c,(CNetNod *)in_stack_ffffff40);
      in_stack_00000020 = 6;
      CClassicArchive::~CClassicArchive(local_74,(CClassicArchive *)in_stack_ffffff44);
      in_stack_00000024 = (void *)((uint)in_stack_00000024 & 0xffffff00);
      CGameNetFormAdmin::~CGameNetFormAdmin(local_24,(CGameNetFormAdmin *)pCVar26);
    }
    break;
  case 0xe:
    if (iVar6 == 0) {
      CClassicArchive::DoNat8
                ((CClassicArchive *)&stack0xffffff50,(CClassicArchive *)&stack0xffffff37,
                 (uchar *)0x1,0,(int)pCVar13);
      CClassicArchive::DoNat8
                ((CClassicArchive *)&local_ac,(CClassicArchive *)&stack0xffffff3a,(uchar *)0x1,0,
                 (int)unaff_EDI);
    }
  }
  CNetArchive::EndReading
            ((CNetArchive *)local_a8,(CPlugFileOggVorbis *)unaff_ESI,(SStreamContext **)unaff_EBP);
  param_3 = (CNetConnectedClient *)0xffffffff;
  CClassicArchive::~CClassicArchive((CClassicArchive *)local_a0,(CClassicArchive *)unaff_EBX);
  ExceptionList = param_2;
  return;
}
}

// =================================================
// Function: CGameNetwork::RemovePlayerInfo
// =================================================
void __thiscall
CGameNetwork::RemovePlayerInfo(CGameNetwork *this,CGameNetwork *param_1,ulong param_2)
{
{
  CGameNetwork *this_00;
  CMwNod *this_01;
  CGameNetPlayerInfo *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  CMwNod *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  undefined4 unaff_retaddr;
  CGameNetPlayerInfo *pCVar5;
  CGameNetPlayerInfo *in_stack_00000018;
  CMwNod *pCVar6;
  ulong in_stack_fffffff8;
  CMwNod *pCVar7;
  
  if (param_1 != (CGameNetwork *)0x0) {
    this_00 = this + 0x240;
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_ESI)
    ;
    this_01 = *(CMwNod **)pSVar2;
    pCVar5 = (CGameNetPlayerInfo *)CONCAT31((int3)((uint)unaff_retaddr >> 8),this_01[0x24]);
    pCVar6 = this_01;
    pCVar7 = this_01;
    (**(code **)(*(int *)this + 0x9c))();
    CFastBuffer<struct_CGameRemoteBuffer::SUser*>::ReplaceByLastIfFound
              (this + 0x24c,(CFastBuffer<struct_CGameRemoteBuffer::SUser*> *)&stack0xfffffff8,
               (SUser **)pCVar6);
    CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt
              (this_00,(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)param_1,1,
               unaff_EBX);
    CMwNod::MwRelease(this_01,unaff_EDI);
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,in_stack_fffffff8);
        pCVar1 = *(CGameNetPlayerInfo **)(*(int *)pSVar2 + 0xd4);
        if (in_stack_00000018 < pCVar1) {
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar4,(ulong)pCVar7);
          *(CGameNetPlayerInfo **)(*(int *)pSVar2 + 0xd4) = pCVar1 + -1;
        }
        in_stack_fffffff8 = 0x5b3d11;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,(ulong)pCVar5);
        pCVar7 = (CMwNod *)0x5b3d1d;
        pCVar5 = in_stack_00000018;
        CGameNetPlayerInfo::RemoveNetStateSending
                  (*(CGameNetPlayerInfo **)pSVar2,in_stack_00000018,(uchar)param_1);
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar3);
    }
  }
  return;
}
}

// =================================================
// Function: CGameNetwork::Send
// =================================================
void __thiscall CGameNetwork::Send(CGameNetwork *this,CNetConnectedClient *param_1,CNetNod *param_2)
{
{
  CGameNetwork *this_00;
  CNetNod CVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CNetConnectedClient *pCVar5;
  CNetConnectedClient *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CGameNetServer *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CNetNod *unaff_retaddr;
  CNetConnectedClient *in_stack_00000014;
  CNetNod *pCVar7;
  
  if (param_2._0_1_ == (CNetNod)0xfe) {
    SendToServer(this,(CGameNetwork *)param_1,(CGameNetFormAdmin *)unaff_ESI);
    return;
  }
  this_00 = this + 0x240;
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
  CVar1 = *(CNetNod *)(*(int *)pSVar2 + 0x24);
  param_2[0x1d] = CVar1;
  param_2[0x1c] = param_2._0_1_;
  if (param_2._0_1_ == CVar1) {
    (**(code **)(*(int *)this + 0xf0))(param_2);
    return;
  }
  if (*(int *)(this + 0x1d0) != 0) {
    if (param_2._0_1_ != (CNetNod)0xff) {
      if (param_2._0_1_ != (CNetNod)0xfb) {
        pCVar5 = CGameNetServer::FindConnection
                           (*(CGameNetServer **)(this + 0x1ac),
                            (CGameNetServer *)((uint)param_2 & 0xff),(ulong)unaff_EBP);
        if (pCVar5 == (CNetConnectedClient *)0x0) {
          return;
        }
        CNetConnectedClient::Send(pCVar5,(CNetConnectedClient *)param_2,(CNetNod *)unaff_ESI);
        return;
      }
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar4 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        return;
      }
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar6,(ulong)unaff_ESI);
        if (*(int *)(*(int *)pSVar2 + 0x88) != 0) {
          unaff_ESI = (CGameNetServer *)(uint)*(byte *)(*(int *)pSVar2 + 0x24);
          pCVar5 = CGameNetServer::FindConnection
                             (*(CGameNetServer **)(this + 0x1ac),unaff_ESI,(ulong)unaff_EBX);
          if (pCVar5 != (CNetConnectedClient *)0x0) {
            unaff_ESI = (CGameNetServer *)0x5b68e8;
            unaff_EBX = in_stack_00000014;
            CNetConnectedClient::Send(pCVar5,in_stack_00000014,unaff_retaddr);
          }
        }
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < pCVar4);
      return;
    }
    pCVar7 = param_2;
    iVar3 = (**(code **)(*(int *)this + 0xf0))();
    if (iVar3 != 0) {
      return;
    }
    CGameNetServer::SendAll(*(CGameNetServer **)(this + 0x1ac),(CGameNetServer *)param_2,pCVar7);
    if (*(int *)(this + 0x1d4) != 0) {
      return;
    }
  }
  (**(code **)(**(int **)(this + 0x1a8) + 0x78))(param_2,0);
  return;
}
}

// =================================================
// Function: CGameNetwork::SendToServer
// =================================================
void __thiscall
CGameNetwork::SendToServer(CGameNetwork *this,CGameNetwork *param_1,CGameNetFormAdmin *param_2)
{
{
  CNetConnectedClient *unaff_retaddr;
  
  if (*(int *)(this + 0x1d4) != 0) {
    OnNetFormAdminReceived(this,param_1,(CGameNetFormAdmin *)0x0,unaff_retaddr);
    return;
  }
  (**(code **)(**(int **)(this + 0x1a8) + 0x78))();
  return;
}
}

// =================================================
// Function: CGameNetwork::SetPlayerInfoType
// =================================================
void __cdecl CGameNetwork::SetPlayerInfoType(CGameNetPlayerInfo *param_1,EPlayerType param_2)
{
{
  *(EPlayerType *)(param_1 + 0x148) = param_2;
  return;
}
}

// =================================================
// Function: CGameNetwork::Sv_SendServerInfo
// =================================================
void __thiscall
CGameNetwork::Sv_SendServerInfo
          (CGameNetwork *this,CGameNetwork *param_1,CNetConnectedClient *param_2,int param_3)
{
{
  CNetNod *pCVar1;
  int unaff_EBP;
  int unaff_ESI;
  CClassicArchive *unaff_EDI;
  int in_stack_00000014;
  CPlugFileOggVorbis *pCVar2;
  CPlugFileOggVorbis *in_stack_ffffff54;
  SStreamContext **ppSVar3;
  SStreamContext **in_stack_ffffff58;
  CNetConnectedClient *pCVar4;
  CNetNod *in_stack_ffffff5c;
  CClassicArchive *pCVar5;
  CClassicArchive *pCVar6;
  CGameNetFormAdmin *pCVar7;
  CClassicArchive *pCVar8;
  CClassicArchive aCStack_84 [4];
  CClassicArchive aCStack_80 [4];
  undefined4 uStack_7c;
  CClassicArchive local_78 [4];
  undefined **local_74;
  CClassicArchive local_70 [4];
  CNetArchive local_6c [4];
  undefined4 local_68;
  CClassicArchive aCStack_64 [4];
  CGameNetFormAdmin aCStack_60 [4];
  CGameNetServer aCStack_5c [4];
  CNetConnectedClient aCStack_58 [8];
  CGameNetFormAdmin aCStack_50 [4];
  CGameNetFormAdmin local_4c [28];
  CNetArchive aCStack_30 [12];
  CNetArchive local_24 [20];
  undefined1 uStack_10;
  void *local_c;
  CNetNod *pCStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pCStack_8 = (CNetNod *)&LAB_00a9dde8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((*(int *)(this + 0x1a8) != 0) && (*(int *)(this + 0x124) != 0)) {
    pCVar6 = (CClassicArchive *)0x5b1690;
    CGameNetFormAdmin::CGameNetFormAdmin
              (local_4c,(CGameNetFormAdmin *)0x0,
               (EMessageType)((uint)DAT_00cca150 ^ (uint)&stack0xffffff6c));
    CClassicArchive::CClassicArchive(local_78,unaff_EDI);
    local_74 = CNetArchive::vftable;
    local_68 = 0;
    CNetArchive::StartStoring
              ((CNetArchive *)&local_74,local_24,(CClassicBufferMemory *)0x1,unaff_ESI);
    if (in_stack_00000014 == 0) {
      local_78[0] = *(CClassicArchive *)(*(int *)(this + 0x23c) + 0xa8);
    }
    else {
      local_78[0] = (CClassicArchive)0x2;
    }
    pCVar8 = local_78;
    pCVar7 = (CGameNetFormAdmin *)0x5b16f7;
    CClassicArchive::WriteNat8(local_70,pCVar8,(uchar *)0x1,0,unaff_EBP);
    (**(code **)(**(int **)(this + 0x23c) + 0xa4))();
    pCVar2 = (CPlugFileOggVorbis *)0x5b171a;
    CNetArchive::EndReading((CNetArchive *)&stack0xffffff70,in_stack_ffffff54,in_stack_ffffff58);
    pCVar1 = pCStack_8;
    if ((pCStack_8 == (CNetNod *)0x0) ||
       ((*(int *)(*(int *)(this + 0x23c) + 0x94) != 0 && (in_stack_00000014 == 0)))) {
      *(undefined4 *)(*(int *)(this + 0x23c) + 0x94) = 0;
      *(undefined1 *)(*(int *)(this + 0x23c) + 0xa8) = 0;
      CGameNetServer::SendAll
                (*(CGameNetServer **)(this + 0x1ac),(CGameNetServer *)aCStack_58,in_stack_ffffff5c);
    }
    else {
      ppSVar3 = (SStreamContext **)0x5b174b;
      CNetConnectedClient::Send(pCStack_8,aCStack_58,in_stack_ffffff5c);
      if (*(int *)(*(int *)(this + 0x23c) + 0x94) != 0) {
        CNetArchive::CNetArchive(local_6c,(CNetArchive *)pCVar6);
        pCStack_8 = (CNetNod *)CONCAT31(pCStack_8._1_3_,2);
        CNetArchive::StartStoring
                  ((CNetArchive *)&local_68,aCStack_30,(CClassicBufferMemory *)0x1,(int)pCVar7);
        aCStack_80[0] = *(CClassicArchive *)(*(int *)(this + 0x23c) + 0xa8);
        pCVar5 = aCStack_80;
        pCVar4 = (CNetConnectedClient *)0x5b179f;
        CClassicArchive::WriteNat8(aCStack_64,pCVar5,(uchar *)0x1,0,(int)pCVar8);
        pCVar7 = aCStack_60;
        pCVar6 = (CClassicArchive *)0x5b17b9;
        (**(code **)(**(int **)(this + 0x23c) + 0xa4))(pCVar7,uStack_7c);
        CNetArchive::EndReading((CNetArchive *)&uStack_7c,pCVar2,ppSVar3);
        *(undefined4 *)(*(int *)(this + 0x23c) + 0x94) = 0;
        *(undefined1 *)(*(int *)(this + 0x23c) + 0xa8) = 0;
        CGameNetServer::SendAllExcept(*(CGameNetServer **)(this + 0x1ac),aCStack_5c,pCVar1,pCVar4);
        uStack_10 = 1;
        CClassicArchive::~CClassicArchive(local_70,pCVar5);
      }
    }
    local_c = (void *)((uint)local_c & 0xffffff00);
    CClassicArchive::~CClassicArchive(aCStack_84,pCVar6);
    pCStack_8 = (CNetNod *)0xffffffff;
    CGameNetFormAdmin::~CGameNetFormAdmin(aCStack_50,pCVar7);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CGameNetwork::UpdatePlayerInfo
// =================================================
int __thiscall
CGameNetwork::UpdatePlayerInfo
          (CGameNetwork *this,CGameNetwork *param_1,CNetArchive *param_2,uchar param_3,int *param_4,
          EPlayerInfoArchiveState param_5,int param_6,CFastString *param_7)
{
{
  CGameNetwork *this_00;
  code *pcVar1;
  undefined *puVar2;
  int iVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CMwNod *pCVar5;
  SCasterCat *pSVar6;
  int extraout_EAX;
  ulong *puVar7;
  CGameNetPlayerInfo *pCVar8;
  SCasterCat *pSVar9;
  int *unaff_EBX;
  CMwTimerAdapter *pCVar10;
  char *unaff_EBP;
  ulong unaff_ESI;
  SFastKey<class_CGameNetPlayerInfo*,unsigned_char> *unaff_EDI;
  CGameNetPlayerInfo *unaff_retaddr;
  undefined3 in_stack_0000000d;
  int *in_stack_00000024;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffac;
  ulong in_stack_ffffffb0;
  TiXmlAttributeSet *in_stack_ffffffb4;
  CGameNetPlayerInfo *in_stack_ffffffb8;
  uchar in_stack_ffffffbc;
  ulong uVar11;
  CFastStringInt *pCVar12;
  CMwTimer *pCVar13;
  SHeaderCommunity *pSVar14;
  undefined4 uVar15;
  CMwNod *pCVar16;
  CFastBuffer<class_CGameNetPlayerInfo*> *pCVar17;
  SHeaderCommunity *pSVar18;
  int *in_stack_ffffffd8;
  int local_24;
  int local_20;
  code *local_1c;
  int local_18;
  undefined *local_14 [2];
  void *local_c;
  undefined1 *puStack_8;
  CGameNetwork *pCStack_4;
  
  pCStack_4 = (CGameNetwork *)0xffffffff;
  puStack_8 = &LAB_00a9e288;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((*(int *)(this + 0x1d4) == 0) &&
     (iVar3 = CGameNetClient::IsConnected
                        (*(CGameNetClient **)(this + 0x1a8),
                         (CCrystalVertex *)(DAT_00cca150 ^ (uint)&stack0xffffffc8)), iVar3 == 0)) {
    *param_4 = 1;
    goto LAB_005b7e2b;
  }
  pCVar17 = (CFastBuffer<class_CGameNetPlayerInfo*> *)&local_20;
  local_20 = CONCAT31(local_20._1_3_,param_3);
  this_00 = this + 0x240;
  local_24 = 0;
  *param_4 = 0;
  local_1c = CGameNetPlayerInfo::sComparePlayerUId;
  pCVar13 = (CMwTimer *)0x5b7d45;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CGameNetPlayerInfo*>::FindKey<unsigned_char>(this_00,pCVar17,unaff_EDI)
  ;
  pCVar10 = (CMwTimerAdapter *)param_4;
  if (param_6 == 1) {
    if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) goto LAB_005b7e67;
    local_20 = 1;
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this_00,(CFastBuffer<class_CCrystalFace*> *)0x5b7d76);
    unaff_EDI = (SFastKey<class_CGameNetPlayerInfo*,unsigned_char> *)0x5b7d89;
    pCVar5 = (CMwNod *)(**(code **)(*(int *)this + 0xe0))();
    CMwNod::MwAddRef(pCVar5,(CMwNod *)in_stack_ffffffb4);
    in_stack_ffffffb4 = (TiXmlAttributeSet *)&stack0xffffffd0;
    in_stack_ffffffb0 = 0x5b7da2;
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this_00,in_stack_ffffffb4,(TiXmlAttribute *)in_stack_ffffffb8);
    if ((*(int *)(this + 0x1d4) != 0) && (_param_3 != (CMwTimerAdapter *)0x0)) {
      in_stack_ffffffb4 = (TiXmlAttributeSet *)0x5b7dbe;
      CGameNetPlayerInfo::SetGeneratedPlayerUId
                ((CGameNetPlayerInfo *)pCVar5,unaff_retaddr,in_stack_ffffffbc);
      in_stack_ffffffb8 = unaff_retaddr;
    }
    pCVar5[0x24] = param_1._0_1_;
    if ((*(int *)(this + 0x1d0) != 0) && (param_4 != (int *)0x0)) {
      in_stack_ffffffd8 = *(int **)(param_5 + 4);
      local_24 = *(int *)param_5;
      in_stack_ffffffb8 = (CGameNetPlayerInfo *)0x5b7df3;
      CFastString::SetString
                ((CFastString *)(pCVar5 + 0x28),(CFastStringInt *)&stack0xffffffd8,
                 (SStringParam *)pCVar13);
    }
    uVar11 = CMwTimer::GetElapsedTimeSinceInit((void *)(DAT_00d731e0 + 0x70),pCVar13);
    *(ulong *)(pCVar5 + 0x164) = uVar11;
    *(undefined4 *)(pCVar5 + 0x5c) = *(undefined4 *)(this + 0x128);
    pCVar10 = _param_3;
  }
  else {
    if (pCVar4 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      *param_4 = 1;
      goto LAB_005b7e2b;
    }
LAB_005b7e67:
    if ((*(int *)(this + 0x1d0) != 0) && (param_7 != (CFastString *)0x0)) {
      pCVar17 = (CFastBuffer<class_CGameNetPlayerInfo*> *)0x5b7e7f;
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
      if (*(int *)pSVar6 != 0) {
        local_18 = in_stack_00000024[1];
        puVar2 = (undefined *)*in_stack_00000024;
        local_14[0] = puVar2;
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,(ulong)unaff_EBP);
        pCVar10 = _param_3;
        if (puVar2 == *(undefined **)(*(int *)pSVar6 + 0x28)) {
          unaff_EBP = (char *)0x0;
          unaff_EDI = (SFastKey<class_CGameNetPlayerInfo*,unsigned_char> *)0x5b7eb2;
          CFastString::Compare
                    ((CFastString *)(*(int *)pSVar6 + 0x28),(SParam_Fids *)local_14,(SParam *)0x0,
                     unaff_EBX,in_stack_ffffffd8);
          if (extraout_EAX == 0) goto LAB_005b7e14;
        }
      }
      *(int *)pCVar10 = 1;
      goto LAB_005b7e2b;
    }
  }
LAB_005b7e14:
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,(ulong)pCVar17);
  if (*(int *)(*(int *)pSVar6 + 0x148) != 0) {
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,pCVar4,(ulong)unaff_EDI);
    (**(code **)(**(int **)pSVar6 + 0x78))();
    puVar7 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),_param_3);
    *(ulong *)(*(int *)pSVar6 + 0x14c) = *puVar7;
    if (local_24 != 0) {
      if (*(int *)(this + 0x1d0) != 0) {
        local_18 = 0;
        local_14[0] = PTR_DAT_00bbf7d8;
        pSVar14 = *(SHeaderCommunity **)pSVar6;
        pSVar18 = (SHeaderCommunity *)&local_18;
        uVar11 = 0x5b7f3f;
        iVar3 = (**(code **)(*(int *)this + 0x10c))();
        if (iVar3 != 0) {
          *(int *)pCVar10 = 1;
          pCVar8 = in_stack_ffffffb8;
LAB_005b7f58:
          DisconnectPlayer(this,(CGameNetwork *)unaff_EBP,(char *)in_stack_ffffffb4,
                           (CFastStringInt *)pCVar8,(uchar)uVar11);
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_20,pSVar14);
          ExceptionList = local_c;
          return 0;
        }
        pCVar8 = (CGameNetPlayerInfo *)
                 CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_ffffffac);
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar8 != (CGameNetPlayerInfo *)0x0) {
          do {
            in_stack_ffffffd8 = *(int **)(*(int *)pSVar6 + 0x2c);
            local_24 = *(int *)(*(int *)pSVar6 + 0x28);
            pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar4,in_stack_ffffffb0);
            if (local_20 == *(int *)(*(int *)pSVar9 + 0x28)) {
              in_stack_ffffffb0 = 0;
              iVar3 = CFastString::CompareNoCase
                                ((CFastString *)(*(int *)pSVar9 + 0x28),(CFastStringInt *)&local_24,
                                 (SStringParam *)0x0,(ulong)in_stack_ffffffb4);
              if (iVar3 == 0) {
                in_stack_ffffffb0 = 0x5b7fc7;
                in_stack_ffffffb4 = (TiXmlAttributeSet *)pCVar4;
                pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (this_00,pCVar4,(ulong)in_stack_ffffffb8);
                if (*(int *)pSVar9 != *(int *)pSVar6) {
                  if (pCVar4 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
                    in_stack_ffffffb4 = (TiXmlAttributeSet *)&DAT_00d71d58;
                    *(undefined4 *)param_1 = 1;
                    unaff_EBP = "You are already connected to this server.";
                    goto LAB_005b7f58;
                  }
                  if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
                    pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                       (this_00,pCVar4,uVar11);
                    in_stack_ffffffb8 = (CGameNetPlayerInfo *)&DAT_00d71d58;
                    DisconnectPlayer(this,(CGameNetwork *)"New connection have been established.",
                                     (char *)&DAT_00d71d58,
                                     (CFastStringInt *)(uint)*(byte *)(*(int *)pSVar9 + 0x24),
                                     (uchar)pSVar14);
                  }
                  break;
                }
              }
            }
            pCVar4 = pCVar4 + 1;
          } while (pCVar4 < pCVar8);
        }
        pCStack_4 = (CGameNetwork *)0xffffffff;
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_1c,pSVar18);
        pCVar10 = (CMwTimerAdapter *)param_4;
      }
      uVar15 = *(undefined4 *)pSVar6;
      pCVar12 = (CFastStringInt *)0x5b8046;
      (**(code **)(*(int *)this + 0x98))(uVar15,pCVar10);
      if (*(int *)pCVar10 != 0) {
        DisconnectPlayer(this,pCStack_4,(char *)in_stack_ffffffb8,pCVar12,(uchar)uVar15);
        ExceptionList = local_c;
        return 0;
      }
      if (*(int *)(*(int *)(this + 0x1b8) + 0x138) != 0) {
        (**(code **)(**(int **)(*(int *)(this + 0x1b8) + 0x138) + 4))
                  (*(int *)pSVar6 + 0x28,*(undefined4 *)(*(int *)pSVar6 + 0x70));
      }
      (**(code **)(*(int *)this + 0xac))(*(undefined4 *)pSVar6);
    }
    (**(code **)(*(int *)this + 0xa0))(*(undefined4 *)pSVar6);
    ExceptionList = local_c;
    return (int)in_stack_ffffffd8;
  }
LAB_005b7e2b:
  pCVar16 = (CMwNod *)0x0;
  pCVar5 = (CMwNod *)(**(code **)(*(int *)this + 0xe0))();
  CMwNod::MwAddRef(pCVar5,pCVar16);
  pcVar1 = *(code **)(*(int *)pCVar5 + 0x78);
  pCVar5[0x24] = (CMwNod)0xff;
  (*pcVar1)(param_2,param_5);
  CMwNod::MwRelease(pCVar5,(CMwNod *)param_2);
  ExceptionList = local_c;
  return 0;
}
}

// =================================================
// Function: CGameNetwork::WriteToGameLog
// =================================================
void __thiscall
CGameNetwork::WriteToGameLog
          (CGameNetwork *this,CGameNetwork *param_1,CGameNetPlayerInfo *param_2,
          CFastStringInt *param_3,char *param_4,int param_5,int param_6)
{
{
  undefined1 *puVar1;
  int unaff_ESI;
  undefined4 local_14;
  undefined *local_10;
  void *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = &LAB_00a9e2e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x5c0) != 0) {
    local_14 = 0;
    local_10 = PTR_DAT_00bbf7d8;
    local_4 = (void *)0x0;
    CFastStringInt::GetUtf8
              (param_2,(CFastStringInt *)&local_14,(CFastString *)0x0,
               DAT_00cca150 ^ (uint)&stack0xffffffe8);
    WriteToGameLog(this,(CGameNetwork *)param_2,(CGameNetPlayerInfo *)&local_10,
                   (CFastStringInt *)param_4,(char *)param_5,param_6,unaff_ESI);
    if (local_8 != PTR_DAT_00bbf7d8) {
      puVar1 = local_8 + -1;
      if ((local_8[-1] & 0x80) != 0) {
        puVar1 = local_8 + -4;
      }
      operator_delete__(puVar1);
    }
  }
  ExceptionList = local_4;
  return;
}
}

