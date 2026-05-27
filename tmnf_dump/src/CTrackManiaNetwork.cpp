// Class implementation: CTrackManiaNetwork

// =================================================
// Function: CTrackManiaNetwork::ChallengeNetRoundsFinished
// =================================================
void __thiscall
CTrackManiaNetwork::ChallengeNetRoundsFinished
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,int param_2)
{
{
  CTrackManiaPlayerInfo *pCVar1;
  CMwId *pCVar2;
  SCasterCat *pSVar3;
  CTrackManiaRaceNet *this_00;
  CPlugAudio *this_01;
  CTrackManiaRaceNet *pCVar4;
  CPlugAudio *unaff_EBX;
  ERaceState unaff_EBP;
  ulong unaff_ESI;
  CTrackMania *unaff_EDI;
  ulong unaff_retaddr;
  ulong uVar5;
  
  if ((*(int *)(*(CTrackMania **)(this + 0x5f8) + 0x268) != 0) &&
     (param_1 != (CTrackManiaNetwork *)0x0)) {
    CTrackMania::CancelOfficialRecord(*(CTrackMania **)(this + 0x5f8),unaff_EDI);
  }
  this_01 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_01 == (CPlugAudio *)0x0) {
    this_01 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar2 = CPlugAudio::MwGetId(this_01,unaff_EBX);
  pCVar1 = *(CTrackManiaPlayerInfo **)pCVar2;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  CTrackManiaPlayerInfo::ChangeRaceState(*(CTrackManiaPlayerInfo **)pSVar3,pCVar1,2,unaff_EBP);
  (**(code **)(*(int *)this + 0x1ac))(1);
  if (((*(int *)(*(int *)(this + 0x5f8) + 0x418) == 0x11) ||
      (*(int *)(*(int *)(this + 0x5f8) + 0x418) == 0x12)) && (param_1 != (CTrackManiaNetwork *)0x0))
  {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        unaff_retaddr);
    pCVar4 = (CTrackManiaRaceNet *)(uint)*(byte *)(*(int *)pSVar3 + 0x24);
    uVar5 = 0xff;
    this_00 = GetRace(this,(CTrackManiaNetwork *)0x0);
    CTrackManiaRaceNet::NotifyNewTime(this_00,pCVar4,uVar5,(ulong)param_1,(uchar)param_2);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaNetwork::ForceEndRound
// =================================================
int __thiscall
CTrackManiaNetwork::ForceEndRound
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CFastString *param_2)
{
{
  if (*(int *)(this + 0x1d0) == 0) {
    CFastString::SetString
              ((CFastString *)param_1,(CFastStringInt *)&stack0xfffffff8,
               (SStringParam *)"Not a server.");
    return 0;
  }
  if ((*(int *)(*(int *)(this + 0x5f8) + 0x418) != 0x11) &&
     (*(int *)(*(int *)(this + 0x5f8) + 0x418) != 0x12)) {
    CFastString::SetString
              ((CFastString *)param_1,(CFastStringInt *)&stack0xfffffff8,
               (SStringParam *)"Not in Rounds or Laps mode.");
    return 0;
  }
  *(undefined4 *)(this + 0x82c) = 1;
  return 1;
}
}

// =================================================
// Function: CTrackManiaNetwork::ForcePlayerTeam
// =================================================
int __thiscall
CTrackManiaNetwork::ForcePlayerTeam
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CGameNetPlayerInfo *param_2,
          ulong param_3,CFastString *param_4)
{
{
  CTrackManiaRaceNet *pCVar1;
  CTrackManiaNetworkServerInfo *pCVar2;
  SCasterCat *pSVar3;
  CTrackManiaNetwork *this_00;
  CTrackManiaNetForm *unaff_EBX;
  CFastStringInt *unaff_ESI;
  CTrackManiaNetwork *unaff_EDI;
  CFastString *in_stack_00000018;
  CClassicArchive *in_stack_fffffef0;
  int in_stack_fffffef4;
  int in_stack_fffffef8;
  int in_stack_fffffefc;
  CPlugFileOggVorbis *pCVar4;
  SStreamContext **ppSVar5;
  SStringParam *pSVar6;
  CClassicArchive aCStack_ec [4];
  undefined **ppuStack_e8;
  char *local_e4;
  char *local_e0;
  char *local_dc;
  undefined4 local_d8;
  CTrackManiaNetForm aCStack_d4 [4];
  CClassicArchive aCStack_d0 [20];
  CNetConnectedClient local_bc [8];
  CTrackManiaNetForm local_b4 [8];
  CNetArchive aCStack_ac [148];
  undefined4 uStack_18;
  undefined1 uStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a8edb6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar4 = (CPlugFileOggVorbis *)0x4dde73;
  pCVar1 = GetRace(this,(CTrackManiaNetwork *)(DAT_00cca150 ^ (uint)&stack0xffffff08));
  if (pCVar1 == (CTrackManiaRaceNet *)0x0) {
    local_e4 = "No race in progress.";
    local_e0 = (char *)0x14;
  }
  else {
    if (*(int *)(*(int *)(this + 0x5f8) + 0x418) == 0x11) {
      ppSVar5 = (SStreamContext **)0x4ddea6;
      pCVar2 = GetServerInfo(this_00,unaff_EDI);
      if (*(int *)(pCVar2 + 0x200) == 6) {
        if ((param_4 == (CFastString *)0x0) || (param_4 == (CFastString *)0x1)) {
          if (*(int *)(this + 0x1d0) == 0) {
            unaff_EDI = (CTrackManiaNetwork *)0x0;
            ppSVar5 = (SStreamContext **)0x4ddefa;
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                (ulong)unaff_ESI);
            if (param_3 != *(ulong *)pSVar3) {
              unaff_ESI = (CFastStringInt *)&local_dc;
              local_dc = "You can only change the local player team.";
              local_d8 = 0x2a;
              goto LAB_004ddff8;
            }
          }
          CTrackManiaNetForm::CTrackManiaNetForm(aCStack_d4,(CTrackManiaNetForm *)&DAT_00000014);
          uStack_18 = 0;
          CClassicArchive::CClassicArchive(aCStack_ec,in_stack_fffffef0);
          ppuStack_e8 = CNetArchive::vftable;
          local_dc = (char *)0x0;
          uStack_14 = 1;
          CNetArchive::StartStoring
                    ((CNetArchive *)&ppuStack_e8,aCStack_ac,(CClassicBufferMemory *)0x1,
                     in_stack_fffffef4);
          pSVar6 = (SStringParam *)CONCAT13(1,(int3)unaff_EDI);
          CClassicArchive::DoNat8
                    ((CClassicArchive *)&local_e4,(CClassicArchive *)&stack0xffffff0b,(uchar *)0x1,0
                     ,in_stack_fffffef8);
          CClassicArchive::DoNatural
                    ((CClassicArchive *)&local_e0,(CClassicArchive *)&stack0x00000000,(ulong *)0x1,0
                     ,in_stack_fffffefc);
          CNetArchive::EndReading((CNetArchive *)&local_dc,pCVar4,ppSVar5);
          CGameNetwork::Send((CGameNetwork *)this,local_bc,
                             (CNetNod *)(uint)*(byte *)(param_3 + 0x24));
          local_dc = "";
          local_d8 = 0;
          CFastString::SetString(param_4,(CFastStringInt *)&local_dc,pSVar6);
          param_1 = (CTrackManiaNetwork *)((uint)param_1 & 0xffffff00);
          CClassicArchive::~CClassicArchive(aCStack_d0,(CClassicArchive *)unaff_ESI);
          CTrackManiaNetForm::~CTrackManiaNetForm(local_b4,unaff_EBX);
          ExceptionList = param_1;
          return 1;
        }
        local_e0 = "Unknown team";
        local_dc = (char *)0xc;
        goto LAB_004ddff8;
      }
    }
    local_dc = "Not in Team mode.";
    local_d8 = 0x11;
  }
  unaff_ESI = (CFastStringInt *)&local_dc;
LAB_004ddff8:
  CFastString::SetString(in_stack_00000018,unaff_ESI,(SStringParam *)unaff_EBX);
  ExceptionList = param_1;
  return 0;
}
}

// =================================================
// Function: CTrackManiaNetwork::ForceScores
// =================================================
int __thiscall
CTrackManiaNetwork::ForceScores
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,
          CFastBuffer<struct_CTrackManiaNetwork::SRpcForcedScores> *param_2,int param_3,
          CFastString *param_4)
{
{
  byte bVar1;
  CTrackManiaRaceNet *pCVar2;
  int iVar3;
  ulong uVar4;
  CTrackManiaNetworkServerInfo *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *this_00;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  CFastStringInt *pCVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CTrackManiaNetwork *unaff_EBP;
  CTrackManiaNetwork *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  void *in_stack_00000014;
  void *in_stack_00000018;
  int in_stack_0000001c;
  CTrackManiaNetwork *in_stack_00000030;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffbc;
  ulong uVar11;
  CTrackManiaRaceScore *pCVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  ulong uVar15;
  CTrackManiaNetwork *pCVar16;
  SStringParam *in_stack_ffffffdc;
  SCasterCat *in_stack_ffffffe0;
  SNationConfig *in_stack_ffffffe4;
  CFastString *in_stack_ffffffe8;
  CGameNetwork *local_14;
  char *local_10;
  void *local_c;
  undefined1 *puStack_8;
  ulong local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a90518;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar11 = 0x4f1f52;
  pCVar16 = this;
  pCVar2 = GetRace(this,(CTrackManiaNetwork *)(DAT_00cca150 ^ (uint)&stack0xffffffc8));
  if (pCVar2 == (CTrackManiaRaceNet *)0x0) {
    local_10 = "No race in progress.";
    local_c = (void *)0x14;
    CFastString::SetString(param_4,(CFastStringInt *)&local_10,(SStringParam *)unaff_EDI);
    iVar3 = 0;
  }
  else if (*(int *)(*(int *)(this + 0x5f8) + 0x418) == 0x11) {
    pCVar12 = (CTrackManiaRaceScore *)0x4f1fb8;
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EDI);
    if (uVar4 != 0) {
      pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4f1fc7;
      pCVar5 = GetServerInfo(this,unaff_ESI);
      if (*(int *)(pCVar5 + 0x200) == 6) {
        uVar4 = 0x4f1fd7;
        pCVar2 = GetRace(this,unaff_EBP);
        pCVar2 = pCVar2 + 0x5a8;
      }
      else {
        uVar4 = 0x4f1fe6;
        pCVar2 = GetRace(this,unaff_EBP);
        pCVar2 = pCVar2 + 0x590;
      }
      pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      local_14 = (CGameNetwork *)0x0;
      pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4f1ffb;
      this_00 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount(pCVar2,unaff_EBX);
      if (this_00 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          uVar15 = 0x4f2010;
          local_4 = CFastBuffer<class_CCrystalFace*>::GetCount
                              (in_stack_00000018,(CFastBuffer<class_CCrystalFace*> *)pCVar16);
          pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (local_4 != 0) {
            do {
              pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (pCVar2,pCVar10,(ulong)in_stack_ffffffbc);
              in_stack_ffffffbc = pCVar9;
              in_stack_ffffffe0 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar9,uVar11);
              uVar11 = 0x4f2040;
              bVar1 = CTrackManiaRaceScore::GetPlayerUid(*(CTrackManiaRaceScore **)pSVar6,pCVar12);
              this = (CTrackManiaNetwork *)local_14;
              if ((uint)bVar1 == *(uint *)in_stack_ffffffe4) {
                uVar11 = 0x4f205e;
                pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (pCVar2,pCVar10,(ulong)pCVar13);
                pCVar12 = (CTrackManiaRaceScore *)0x4f206a;
                pCVar13 = pCVar9;
                pSVar7 = CFastBuffer<struct_SFastCat>::operator[]((void *)param_3,pCVar9,uVar4);
                if (*(int *)(*(int *)pSVar6 + 0x14) != *(int *)(pSVar7 + 4)) {
                  pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4f207d;
                  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     (pCVar2,pCVar10,(ulong)pCVar14);
                  uVar4 = 0x4f2089;
                  pSVar7 = CFastBuffer<struct_SFastCat>::operator[](in_stack_00000014,pCVar9,uVar15)
                  ;
                  *(undefined4 *)(*(int *)pSVar6 + 0x14) = *(undefined4 *)(pSVar7 + 4);
                  local_10 = (char *)0x1;
                  pCVar14 = pCVar9;
                }
                break;
              }
              pCVar9 = pCVar9 + 1;
            } while (pCVar9 < in_stack_ffffffe8);
          }
          pCVar10 = pCVar10 + 1;
        } while (pCVar10 < this_00);
        if (local_10 != (char *)0x0) {
          if (in_stack_0000001c == 0) {
            pCVar8 = (CFastStringInt *)
                     CClassicI18n::GetTranslatedStringInternal
                               ((CClassicI18n *)&DAT_00d71d10,
                                (CClassicI18n *)
                                L"Notice: The scores have been altered by the administrator.",
                                (wchar_t *)pCVar16);
            CFastStringInt::CFastStringInt(&local_4,pCVar8,in_stack_ffffffdc);
            in_stack_00000018 = (void *)0x0;
            CGameNetwork::ChatSend
                      ((CGameNetwork *)this,(CGameNetwork *)&stack0x00000000,(CFastStringInt *)0xff,
                       0xff,'\0','\x10','\0',0,(int)in_stack_ffffffe0);
            in_stack_0000001c = 0xffffffff;
            CGameCtnApp::SNationConfig::~SNationConfig(&param_1,in_stack_ffffffe4);
            iVar3 = ForceEndRound(this,in_stack_00000030,in_stack_ffffffe8);
            ExceptionList = param_2;
            return iVar3;
          }
          SendScores(this,(CTrackManiaNetwork *)0xff,(uchar)pCVar16);
        }
      }
    }
    iVar3 = 1;
  }
  else {
    local_10 = "Not in Rounds or Team mode.";
    local_c = (void *)0x1b;
    CFastString::SetString(param_4,(CFastStringInt *)&local_10,(SStringParam *)unaff_EDI);
    iVar3 = 0;
  }
  ExceptionList = param_2;
  return iVar3;
}
}

// =================================================
// Function: CTrackManiaNetwork::ForceSpectatorTarget
// =================================================
int __thiscall
CTrackManiaNetwork::ForceSpectatorTarget
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CGameNetPlayerInfo *param_2,
          CGameNetPlayerInfo *param_3,ulong param_4,CFastString *param_5)
{
{
  CTrackManiaNetwork *pCVar1;
  CTrackManiaRaceNet *pCVar2;
  SCasterCat *pSVar3;
  int extraout_EAX;
  int iVar4;
  uint uVar5;
  CNetNod *pCVar6;
  int *unaff_EBX;
  CTrackManiaNetwork *this_00;
  CTrackManiaNetwork *unaff_EBP;
  SStringParam *unaff_ESI;
  SStringParam *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  void *unaff_retaddr;
  CFastString *in_stack_00000018;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff30;
  char *local_cc;
  CTrackManiaNetwork *local_c8;
  undefined4 local_c4;
  CGameNetwork *local_c0;
  CTrackManiaNetwork *local_bc;
  ulong local_b8;
  CTrackManiaNetForm local_b4 [64];
  undefined1 local_74;
  uint local_70;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a8edeb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_c8 = this;
  pCVar2 = GetRace(this,(CTrackManiaNetwork *)(DAT_00cca150 ^ (uint)&stack0xffffff20));
  if (pCVar2 == (CTrackManiaRaceNet *)0x0) {
    local_cc = "No race in progress.";
    local_c8 = (CTrackManiaNetwork *)0x14;
    CFastString::SetString(param_5,(CFastStringInt *)&local_cc,unaff_EDI);
    ExceptionList = unaff_retaddr;
    return 0;
  }
  if ((*(int *)(this + 0x1d0) == 0) &&
     (pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)unaff_EDI), param_2 = param_3,
     param_3 != *(CGameNetPlayerInfo **)pSVar3)) {
    local_c8 = (CTrackManiaNetwork *)0xb48d90;
    local_c4 = 0x2c;
    CFastString::SetString(in_stack_00000018,(CFastStringInt *)&local_c8,unaff_ESI);
    ExceptionList = unaff_retaddr;
    return 0;
  }
  if (((param_2 != (CGameNetPlayerInfo *)0x0) && (*(int *)(param_2 + 0x70) == 0)) &&
     (*(int *)(param_2 + 0x74) == 0)) {
    local_c8 = (CTrackManiaNetwork *)0xb48d70;
    local_c4 = 0x1e;
    CFastString::SetString(in_stack_00000018,(CFastStringInt *)&local_c8,unaff_ESI);
    ExceptionList = unaff_retaddr;
    return 0;
  }
  if (param_5 == (CFastString *)0xffffffff) {
    param_5 = (CFastString *)0xff;
    goto LAB_004de1ff;
  }
  if ((param_5 == (CFastString *)0x0) || (param_5 == (CFastString *)0x1)) {
LAB_004de170:
    if (param_5 != (CFastString *)0x2) goto LAB_004de1ff;
  }
  else if (param_5 != (CFastString *)0x2) {
    if (param_5 != (CFastString *)0xff) {
      local_c8 = (CTrackManiaNetwork *)0xb48d58;
      local_c4 = 0x14;
      CFastString::SetString(in_stack_00000018,(CFastStringInt *)&local_c8,unaff_ESI);
      ExceptionList = unaff_retaddr;
      return 0;
    }
    goto LAB_004de170;
  }
  if (param_4 == 0) {
    SStringParam::SStringParam(&local_c8,(SStringParam *)"v2008-06-10",(char *)unaff_ESI);
    unaff_ESI = (SStringParam *)&DAT_0000000b;
    CFastString::Compare
              ((CFastString *)(param_2 + 0x40),(SParam_Fids *)&local_c4,(SParam *)&DAT_0000000b,
               (int *)unaff_EBP,unaff_EBX);
    if (extraout_EAX < 0) {
      this_00 = this + 0x240;
      local_b8 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_ffffff30);
      pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      this = (CTrackManiaNetwork *)local_c0;
      if (local_b8 != 0) {
        do {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar7,(ulong)unaff_ESI);
          pCVar1 = *(CTrackManiaNetwork **)pSVar3;
          pCVar2 = GetRace(local_bc,unaff_EBP);
          unaff_ESI = (SStringParam *)0x4de1e0;
          unaff_EBP = pCVar1;
          iVar4 = (**(code **)(*(int *)pCVar2 + 0xe4))();
          if (iVar4 != 0) {
            param_4 = (ulong)pCVar1;
          }
          pCVar7 = pCVar7 + 1;
          this = (CTrackManiaNetwork *)local_c0;
          param_2 = param_3;
        } while (pCVar7 < local_c8);
      }
    }
  }
LAB_004de1ff:
  CTrackManiaNetForm::CTrackManiaNetForm
            ((CTrackManiaNetForm *)&local_b8,(CTrackManiaNetForm *)&DAT_00000014);
  local_74 = 2;
  if (param_4 == 0) {
    uVar5 = 0xff;
  }
  else {
    uVar5 = CONCAT31((int3)(param_4 >> 8),*(undefined1 *)(param_4 + 0x24));
  }
  local_70 = (int)param_5 << 0x10 | uVar5 & 0xff;
  if (param_2 == (CGameNetPlayerInfo *)0x0) {
    pCVar6 = (CNetNod *)(uVar5 | 0xff);
  }
  else {
    pCVar6 = (CNetNod *)CONCAT31((int3)(uVar5 >> 8),param_2[0x24]);
  }
  CGameNetwork::Send((CGameNetwork *)this,(CNetConnectedClient *)&local_b8,pCVar6);
  local_c0 = (CGameNetwork *)&DAT_00b2c878;
  local_bc = (CTrackManiaNetwork *)0x0;
  CFastString::SetString(in_stack_00000018,(CFastStringInt *)&local_c0,unaff_ESI);
  CTrackManiaNetForm::~CTrackManiaNetForm(local_b4,(CTrackManiaNetForm *)unaff_EBP);
  ExceptionList = unaff_retaddr;
  return 1;
}
}

// =================================================
// Function: CTrackManiaNetwork::GetForceShowAllOpponents
// =================================================
int __thiscall
CTrackManiaNetwork::GetForceShowAllOpponents
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,int *param_2,int *param_3,
          CFastString *param_4)
{
{
  CTrackManiaNetworkServerInfo *pCVar1;
  CTrackManiaNetwork *unaff_ESI;
  CTrackManiaNetwork *unaff_retaddr;
  
  pCVar1 = GetServerInfo(this,unaff_ESI);
  *param_2 = (uint)(*(int *)(pCVar1 + 0x254) != 0);
  pCVar1 = GetServerInfo(this,unaff_retaddr);
  *(uint *)param_4 = (uint)(*(int *)(pCVar1 + 0x2ac) != 0);
  return 1;
}
}

// =================================================
// Function: CTrackManiaNetwork::GetMenuManager
// =================================================
CTrackManiaMenus * __thiscall
CTrackManiaNetwork::GetMenuManager(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1)
{
{
  return *(CTrackManiaMenus **)(*(int *)(this + 0x5f8) + 0x194);
}
}

// =================================================
// Function: CTrackManiaNetwork::GetRoundForcedLaps
// =================================================
int __thiscall
CTrackManiaNetwork::GetRoundForcedLaps
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,ulong *param_2,ulong *param_3,
          CFastString *param_4)
{
{
  CTrackManiaNetworkServerInfo *pCVar1;
  CTrackManiaNetwork *unaff_ESI;
  CTrackManiaNetwork *unaff_retaddr;
  
  pCVar1 = GetServerInfo(this,unaff_ESI);
  *param_2 = *(ulong *)(pCVar1 + 0x208);
  pCVar1 = GetServerInfo(this,unaff_retaddr);
  *(undefined4 *)param_4 = *(undefined4 *)(pCVar1 + 0x260);
  return 1;
}
}

// =================================================
// Function: CTrackManiaNetwork::GetServerInfo
// =================================================
CTrackManiaNetworkServerInfo * __thiscall
CTrackManiaNetwork::GetServerInfo(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1)
{
{
  return *(CTrackManiaNetworkServerInfo **)(this + 0x23c);
}
}

// =================================================
// Function: CTrackManiaNetwork::Hack_ResetAfterValidation
// =================================================
void __thiscall
CTrackManiaNetwork::Hack_ResetAfterValidation(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1)
{
{
  int iVar1;
  CMwId *pCVar2;
  SCasterCat *pSVar3;
  CTrackManiaRaceNet *pCVar4;
  CTrackManiaNetwork *pCVar5;
  CTrackManiaRaceNet *pCVar6;
  CPlugAudio *this_00;
  CTrackManiaNetwork *this_01;
  CTrackManiaNetwork *this_02;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CTrackMania *unaff_ESI;
  CPlugAudio *unaff_EDI;
  undefined4 *puVar7;
  CTrackManiaNetwork *unaff_retaddr;
  undefined4 in_stack_00000018;
  CTrackManiaNetwork *pCVar8;
  CGamePlayground *in_stack_fffffff8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  ulong in_stack_fffffffc;
  
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar2 = CPlugAudio::MwGetId(this_00,unaff_EDI);
  pCVar8 = *(CTrackManiaNetwork **)pCVar2;
  if (*(int *)(*(CTrackMania **)(this + 0x5f8) + 0x268) != 0) {
    CTrackMania::CancelOfficialRecord(*(CTrackMania **)(this + 0x5f8),unaff_ESI);
  }
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP);
  if ((*(int *)(*(int *)pSVar3 + 0x70) == 0) && (*(int *)(*(int *)pSVar3 + 0x74) == 0)) {
    if ((*(int *)(*(int *)(this + 0x5f8) + 0x418) != 0x11) &&
       (*(int *)(*(int *)(this + 0x5f8) + 0x418) != 0x12)) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          unaff_EBX);
      pCVar4 = GetRace(this,(CTrackManiaNetwork *)(uint)*(byte *)(*(int *)pSVar3 + 0x24));
      pCVar5 = (CTrackManiaNetwork *)
               CGamePlayground::GetPlayerNumber
                         ((CGamePlayground *)pCVar4,in_stack_fffffff8,in_stack_fffffffc);
      pCVar4 = GetRace(this,unaff_retaddr);
      iVar1 = *(int *)pCVar4;
      GetServerInfo(this_01,param_1);
      puVar7 = &stack0x00000018;
      pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&stack0x0000001c;
      (**(code **)(iVar1 + 0x110))();
      pCVar4 = GetRace(this,pCVar8);
      pCVar6 = GetRace(this_02,pCVar5);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar6 + 0x24,pCVar9,(ulong)puVar7);
      (**(code **)(*(int *)pCVar4 + 0x164))(*(undefined4 *)pSVar3,in_stack_00000018);
      return;
    }
    ChallengeNetRoundsFinished(this,(CTrackManiaNetwork *)0x1,(int)in_stack_fffffff8);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaNetwork::RefereeDoOneStep
// =================================================
void __thiscall
CTrackManiaNetwork::RefereeDoOneStep
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,SMwFiberContext **param_2,
          int *param_3)
{
{
  int iVar1;
  CTrackManiaNetwork *pCVar2;
  SMwFiberContext **ppSVar3;
  undefined1 *puVar4;
  CTrackManiaNetwork *pCVar5;
  undefined4 *puVar6;
  CTrackManiaMenus *pCVar7;
  SNewTriangleVert *pSVar8;
  ulong uVar9;
  CFastStringInt *pCVar10;
  SCasterCat *pSVar11;
  SStringParam *unaff_EBX;
  GmVec3 *unaff_EBP;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  bool bVar12;
  SNationConfig *unaff_retaddr;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  void *in_stack_00000034;
  undefined4 in_stack_00000038;
  SStringParam *in_stack_ffffffd8;
  CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData> *in_stack_ffffffdc;
  char *in_stack_ffffffe0;
  ulong in_stack_ffffffe4;
  SHeaderCommunity *in_stack_ffffffe8;
  CMwNod *in_stack_ffffffec;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff0;
  wchar_t *pwVar13;
  SStringParam *pSVar14;
  int iVar15;
  
  pCVar2 = param_1;
  iVar15 = -1;
  pSVar14 = (SStringParam *)&LAB_00a91a20;
  pCVar5 = (CTrackManiaNetwork *)(DAT_00cca150 ^ (uint)&stack0xffffffc8);
  if (*(int *)param_1 == -1) {
    ExceptionList = in_stack_00000034;
    return;
  }
  puVar4 = &stack0xfffffff4;
  pwVar13 = ExceptionList;
  if (*(int *)param_1 == 0) {
    ExceptionList = &stack0xfffffff4;
    puVar6 = operator_new(0x3c);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      *puVar6 = `public:_void___thiscall_CTrackManiaNetwork::RefereeDoOneStep(struct_SMwFiberContext*&,int&)'
                ::__l2::SContext::vftable;
      puVar6[4] = 0;
      puVar6[6] = 0;
      puVar6[7] = PTR_DAT_00bbf7d8;
      puVar6[8] = 0;
      puVar6[9] = PTR_DAT_00bbf7dc;
    }
    *(undefined4 **)pCVar2 = puVar6;
    puVar4 = ExceptionList;
  }
  ExceptionList = puVar4;
  ppSVar3 = param_2;
  if (*(int *)(*(int *)pCVar2 + 4) == 0) {
    *param_2 = (SMwFiberContext *)0x0;
    pCVar7 = GetMenuManager(this,pCVar5);
    if (*(int *)(pCVar7 + 0x700) == 0x42) {
      *ppSVar3 = (SMwFiberContext *)0x1;
      puVar6 = *(undefined4 **)pCVar2;
      if ((puVar6 != (undefined4 *)0xffffffff) && (puVar6 != (undefined4 *)0x0)) {
        (**(code **)*puVar6)(1);
      }
      goto LAB_0050577d;
    }
    pCVar5 = this + 0x7f4;
    uVar9 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar5,unaff_EDI);
    if (uVar9 != 0) {
      pSVar8 = CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>::GetLastElem
                         (pCVar5,unaff_ESI);
      CMwNodRef<class_CGameNetOnlineMessage>::operator=
                ((void *)(*(int *)pCVar2 + 0x10),(SNormalDec3N *)(pSVar8 + 0x1c),unaff_EBP);
      in_stack_ffffffe8 = *(SHeaderCommunity **)(pSVar8 + 0xc);
      CFastString::SetString
                ((CFastString *)(*(int *)pCVar2 + 0x18),(CFastStringInt *)&stack0xffffffe8,unaff_EBX
                );
      in_stack_ffffffec = *(CMwNod **)(pSVar8 + 0x14);
      in_stack_fffffff0 = *(CFastBuffer<class_CCrystalFace*> **)(pSVar8 + 0x10);
      pwVar13 = (wchar_t *)0x0;
      CFastStringInt::SetString
                ((void *)(*(int *)pCVar2 + 0x20),(CFastStringInt *)&stack0xffffffec,
                 in_stack_ffffffd8);
      *(undefined4 *)(*(int *)pCVar2 + 0x2c) = *(undefined4 *)(pSVar8 + 0x18);
      *(undefined4 *)(*(int *)pCVar2 + 0x34) = *(undefined4 *)pSVar8;
      *(undefined4 *)(*(int *)pCVar2 + 0x30) = *(undefined4 *)(pSVar8 + 4);
      *(undefined4 *)(*(int *)pCVar2 + 0x38) = 1;
      CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>::RemoveLastElem
                (pCVar5,in_stack_ffffffdc);
      *(undefined4 *)(*(int *)pCVar2 + 0xc) = 0;
      goto LAB_00505633;
    }
    *(undefined4 *)(this + 0x7d8) = *(undefined4 *)(this + 0x65c);
LAB_00505730:
    if (*(int *)(this + 0x7d8) != 0) {
      pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                           (ulong)param_1);
      param_1 = (CTrackManiaNetwork *)(uint)*(byte *)(*(int *)pSVar11 + 0x24);
      (**(code **)(*(int *)this + 400))();
      (**(code **)(*(int *)this + 0x198))();
      *(undefined4 *)(this + 0x7d8) = 0;
    }
  }
  else if (*(int *)(*(int *)pCVar2 + 4) == 0x1b8) {
LAB_00505633:
    iVar1 = *(int *)(*(int *)pCVar2 + 0xc);
    if ((iVar1 == 0) || (iVar1 == -1)) {
      bVar12 = false;
    }
    else {
      bVar12 = *(int *)(iVar1 + 4) == -1;
    }
    CFastString::CFastString
              ((CFastString *)&stack0x00000000,(CFastString *)&DAT_00b2c878,in_stack_ffffffe0);
    iVar1 = *(int *)pCVar2;
    in_stack_0000001c = 0;
    ValidateReplay(this,(CTrackManiaNetwork *)(iVar1 + 0xc),(SMwFiberContext **)(iVar1 + 0x18),
                   (CFastString *)(iVar1 + 0x20),*(CFastStringInt **)(iVar1 + 0x38),(int)&param_1,
                   (CFastString *)(iVar1 + 0x10),
                   *(CMwNodRef<class_CGameCtnReplayRecord> **)(iVar1 + 0x34),
                   *(ulong *)(iVar1 + 0x30),in_stack_ffffffe4);
    in_stack_00000020 = 0xffffffff;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&param_2,in_stack_ffffffe8);
    if (bVar12) {
      ExceptionList = in_stack_00000034;
      return;
    }
    iVar1 = *(int *)pCVar2;
    if (*(int *)(iVar1 + 0xc) != -1) {
      *(undefined4 *)(iVar1 + 4) = 0x1b8;
      ExceptionList = in_stack_00000034;
      return;
    }
    if (*(CMwNod **)(iVar1 + 0x10) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(iVar1 + 0x10),in_stack_ffffffec);
      *(undefined4 *)(iVar1 + 0x10) = 0;
    }
    uVar9 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x7f4,in_stack_fffffff0);
    if (uVar9 == 0) {
      pCVar10 = (CFastStringInt *)
                CClassicI18n::GetTranslatedStringInternal
                          ((CClassicI18n *)&DAT_00d71d10,
                           (CClassicI18n *)L"All scores validated, waiting ...",pwVar13);
      CFastStringInt::CFastStringInt(&stack0x00000020,pCVar10,pSVar14);
      in_stack_00000034 = (void *)0x1;
      RefereeLog(this,(CTrackManiaNetwork *)&stack0x00000024,(CFastStringInt *)0x0,iVar15);
      if (*(int *)(this + 0x65c) != 0) {
        *(undefined4 *)(this + 0x7d8) = 1;
      }
      in_stack_00000038 = 0xffffffff;
      CGameCtnApp::SNationConfig::~SNationConfig(&stack0x00000028,unaff_retaddr);
    }
    goto LAB_00505730;
  }
  puVar6 = *(undefined4 **)pCVar2;
  if ((puVar6 != (undefined4 *)0xffffffff) && (puVar6 != (undefined4 *)0x0)) {
    (**(code **)*puVar6)();
  }
LAB_0050577d:
  *(undefined4 *)pCVar2 = 0xffffffff;
  ExceptionList = in_stack_00000034;
  return;
}
}

// =================================================
// Function: CTrackManiaNetwork::RefereeLog
// =================================================
void __thiscall
CTrackManiaNetwork::RefereeLog
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CFastStringInt *param_2,int param_3)
{
{
  CPlugFileGpuBuilder *this_00;
  CTrackManiaMenus *pCVar1;
  CTrackManiaNetwork *this_01;
  CPlugFileGpuBuilder *unaff_ESI;
  ulong unaff_EDI;
  char *unaff_retaddr;
  int in_stack_00000014;
  
  if (*(CClassicArchive **)(this + 0x850) != (CClassicArchive *)0x0) {
    CClassicArchive::WriteString
              (*(CClassicArchive **)(this + 0x850),(CClassicArchive *)param_1,(CFastStringInt *)0x1,
               unaff_EDI);
  }
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  this_00 = CFastString::operator<<
                      ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)param_1,
                       (char *)&lpOutputString_00b2bcc4);
  CFastString::operator<<((CFastString *)this_00,unaff_ESI,unaff_retaddr);
  CClassicLog::ConsoleAddLogString(4,(CFastString *)&DAT_00d71e54);
  if (in_stack_00000014 == 0) {
    pCVar1 = GetMenuManager(this,param_1);
    if (pCVar1 != (CTrackManiaMenus *)0x0) {
      pCVar1 = GetMenuManager(this_01,param_1);
      CGameCtnMenus::DialogRefereeStatus_PushMessage
                ((CGameCtnMenus *)pCVar1,(CGameCtnMenus *)param_2,(CFastStringInt *)param_3);
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaNetwork::SendInvalidReplay
// =================================================
void __thiscall
CTrackManiaNetwork::SendInvalidReplay
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,CFastString *param_2,
          CGameCtnReplayRecord *param_3,CFastStringInt *param_4)
{
{
  CClassicBufferMemory *pCVar1;
  int iVar2;
  SFeature *pSVar3;
  CClassicBufferMemory *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  undefined4 *puVar4;
  CFastStringInt *extraout_EAX_02;
  CFastString *extraout_EAX_03;
  CMwId *pCVar5;
  CFastStringInt *pCVar6;
  CClassicBufferMemory *unaff_EBP;
  char *unaff_ESI;
  CClassicBufferMemory *pCVar7;
  CSystemPackDesc *pCVar8;
  char *unaff_EDI;
  void *unaff_retaddr;
  CGameCtnApp *in_stack_00000014;
  CFastStringInt *in_stack_ffffff84;
  char *in_stack_ffffff88;
  char *in_stack_ffffff8c;
  SStringParam *in_stack_ffffff90;
  SStringParam *in_stack_ffffff94;
  SStringParam *in_stack_ffffff9c;
  SStringParam *pSVar9;
  CMwId *pCVar10;
  CMwId *pCVar11;
  CFastStringInt *pCVar12;
  CFastStringInt aCStack_40 [8];
  undefined1 auStack_38 [4];
  CClassicBufferMemory *local_34;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  CGameMasterServer *local_20;
  undefined4 local_1c;
  CClassicBufferMemory *local_18;
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a8f256;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = CGameNetwork::IsInternet
                    ((CGameNetwork *)this,(CGameNetwork *)(DAT_00cca150 ^ (uint)&stack0xffffffac));
  if (((iVar2 != 0) &&
      (pSVar3 = CGameMasterServer::GetFeatureFromName
                          (*(CGameMasterServer **)(this + 0x1b0),
                           (CGameMasterServer *)"SendInvalidReplay",unaff_EDI), pCVar6 = param_4,
      pSVar3 != (SFeature *)0x0)) && (*(int *)(pSVar3 + 4) != 0)) {
    if (param_4 == (CFastStringInt *)0x0) {
      pSVar3 = CGameMasterServer::GetFeatureFromName
                         (*(CGameMasterServer **)(this + 0x1b0),
                          (CGameMasterServer *)"SendInvalidReplayNull",unaff_ESI);
      if (pSVar3 == (SFeature *)0x0) {
        ExceptionList = unaff_retaddr;
        return;
      }
      if (*(int *)(pSVar3 + 4) == 0) {
        ExceptionList = unaff_retaddr;
        return;
      }
    }
    pCVar12 = (CFastStringInt *)&DAT_00000020;
    pCVar11 = (CMwId *)0x4e16ad;
    local_34 = operator_new(0x20);
    param_2 = (CFastString *)0x0;
    if (local_34 == (CClassicBufferMemory *)0x0) {
      pCVar7 = (CClassicBufferMemory *)0x0;
    }
    else {
      pCVar12 = (CFastStringInt *)0x4e16c3;
      CClassicBufferMemory::CClassicBufferMemory(local_34,unaff_EBP);
      pCVar7 = extraout_EAX;
    }
    local_28 = 0xffffffff;
    if (pCVar6 != (CFastStringInt *)0x0) {
      CSystemArchiveNod::SaveMemoryTemp(pCVar7,(CMwNod *)pCVar6,8,0);
    }
    pCVar1 = local_18;
    CGameMasterServer::ReportInvalidReplay
              (*(CGameMasterServer **)(this + 0x1b0),local_20,(CFastString *)pCVar7,local_18,
               in_stack_ffffff84);
    pSVar3 = CGameMasterServer::GetFeatureFromName
                       (*(CGameMasterServer **)(this + 0x1b0),
                        (CGameMasterServer *)"AbuseOnInvalidReplay",in_stack_ffffff88);
    if ((pSVar3 != (SFeature *)0x0) && (*(int *)(pSVar3 + 4) == 1)) {
      if (pCVar6 == (CFastStringInt *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(pCVar6 + 0x24);
      }
      pSVar9 = (SStringParam *)0x0;
      local_20 = (CGameMasterServer *)0x1;
      if (pCVar6 == (CFastStringInt *)0x0) {
        SStringParam::SStringParam
                  (&stack0xffffffb4,(SStringParam *)"SendInvalidReplay : no replay",
                   in_stack_ffffff8c);
        CFastStringInt::CFastStringInt
                  (aCStack_40,(CFastStringInt *)&stack0xffffffb8,in_stack_ffffff90);
        local_18 = (CClassicBufferMemory *)0x3;
        pCVar5 = (CMwId *)0x2;
        puVar4 = extraout_EAX_01;
      }
      else {
        SStringParam::SStringParam
                  (&stack0xffffffac,(SStringParam *)"SendInvalidReplay : invalid replay",
                   in_stack_ffffff8c);
        CFastStringInt::CFastStringInt
                  (auStack_38,(CFastStringInt *)&stack0xffffffb0,in_stack_ffffff90);
        local_18 = (CClassicBufferMemory *)CONCAT31(local_18._1_3_,2);
        pCVar5 = (CMwId *)0x1;
        puVar4 = extraout_EAX_00;
      }
      uStack_2c = puVar4[1];
      local_28 = *puVar4;
      local_24 = 0;
      pCVar10 = pCVar5;
      CFastStringInt::SetString(&stack0xffffffac,(CFastStringInt *)&uStack_2c,in_stack_ffffff94);
      if (((uint)pCVar5 & 2) != 0) {
        pCVar5 = (CMwId *)((uint)pCVar5 & 0xfffffffd);
        pCVar11 = pCVar5;
        CGameCtnApp::SNationConfig::~SNationConfig(auStack_38,(SNationConfig *)in_stack_ffffff9c);
      }
      local_10 = 1;
      if (((uint)pCVar5 & 1) != 0) {
        pCVar12 = (CFastStringInt *)((uint)pCVar5 & 0xfffffffe);
        CGameCtnApp::SNationConfig::~SNationConfig(&uStack_2c,(SNationConfig *)in_stack_ffffff9c);
      }
      local_24 = *(undefined4 *)(pCVar1 + 4);
      local_20 = *(CGameMasterServer **)pCVar1;
      local_1c = 0;
      CFastStringInt::Concat(&stack0xffffffb4,(CFastStringInt *)&local_24,in_stack_ffffff9c);
      if (iVar2 == 0) {
        CMwId::CMwId(&param_1,(CMwId *)pSVar9);
        local_8 = (undefined1 *)CONCAT31(local_8._1_3_,4);
        pCVar8 = (CSystemPackDesc *)&DAT_00d71d58;
        pCVar6 = extraout_EAX_02;
      }
      else {
        pCVar6 = (CFastStringInt *)(iVar2 + 0xdc);
        pCVar8 = (CSystemPackDesc *)(iVar2 + 0x108);
      }
      CFastStringInt::CFastStringInt(&local_24,(CFastStringInt *)&DAT_00b49120,pSVar9);
      local_4 = 5;
      CGameMasterServer::AddAbuse
                (*(CGameMasterServer **)(this + 0x1b0),(CGameMasterServer *)param_1,extraout_EAX_03,
                 aCStack_40,(CFastStringInt *)&DAT_00d71d58,(CFastStringInt *)0x0,
                 (CSystemPackDesc *)0x0,pCVar8,pCVar6,pCVar10);
      CGameCtnApp::SNationConfig::~SNationConfig(&local_1c,(SNationConfig *)pCVar11);
      param_1 = (CTrackManiaNetwork *)0x1;
      if (iVar2 == 0) {
        OnAccessViolation_ConcatToCrashFileName(pCVar12);
      }
      param_1 = (CTrackManiaNetwork *)0xffffffff;
      CGameCtnApp::SNationConfig::~SNationConfig(auStack_38,(SNationConfig *)pCVar12);
      pCVar6 = (CFastStringInt *)in_stack_00000014;
    }
    if (pCVar6 != (CFastStringInt *)0x0) {
      CGameCtnApp::SaveValidationReplay
                (*(CGameCtnApp **)(this + 0x5f8),(CGameCtnApp *)pCVar6,(CGameCtnReplayRecord *)0x0,
                 (int)unaff_EBP);
    }
  }
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CTrackManiaNetwork::SendRefereePlayerScoreCheckResult
// =================================================
void __thiscall
CTrackManiaNetwork::SendRefereePlayerScoreCheckResult
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,ulong param_2,CFastString *param_3,
          ulong param_4,ETmValidateResult param_5,ulong param_6)
{
{
  SStringParam *pSVar1;
  CGameNetFormAdmin *unaff_ESI;
  void *unaff_retaddr;
  CTrackManiaNetForm *pCVar2;
  CTrackManiaNetForm local_c0 [4];
  CGameNetwork local_bc [4];
  CTrackManiaNetForm local_b8 [140];
  CTrackManiaNetwork *local_2c;
  CFastString local_28 [12];
  ulong local_1c;
  undefined1 local_18;
  ulong local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a8ed7b;
  local_c = ExceptionList;
  pSVar1 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffff34);
  ExceptionList = &local_c;
  CTrackManiaNetForm::CTrackManiaNetForm(local_c0,(CTrackManiaNetForm *)0x15);
  local_2c = param_1;
  pCVar2 = *(CTrackManiaNetForm **)(param_2 + 4);
  local_4 = 0;
  CFastString::SetString(local_28,(CFastStringInt *)&stack0xffffff38,pSVar1);
  local_1c = param_4;
  local_18 = (undefined1)param_5;
  local_14 = param_6;
  CGameNetwork::SendToServer((CGameNetwork *)this,local_bc,unaff_ESI);
  CTrackManiaNetForm::~CTrackManiaNetForm(local_b8,pCVar2);
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CTrackManiaNetwork::SendScores
// =================================================
void __thiscall
CTrackManiaNetwork::SendScores(CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,uchar param_2)
{
{
  CClassicArchive *pCVar1;
  CTrackManiaRaceNet *pCVar2;
  CTrackManiaNetworkServerInfo *pCVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  int iVar6;
  CTrackManiaNetwork *this_00;
  CTrackManiaNetwork *unaff_EBX;
  SStreamContext **unaff_EBP;
  CTrackManiaNetwork *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  int unaff_EDI;
  CNetNod *in_stack_00000014;
  void *in_stack_00000018;
  undefined4 uStack0000001c;
  CNetNod *in_stack_0000002c;
  CPlugFileOggVorbis *pCVar8;
  CTrackManiaNetwork *in_stack_ffffff28;
  undefined **ppuVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff30;
  CNetConnectedClient *in_stack_ffffff34;
  CTrackManiaPlayerInfo *pCVar10;
  CTrackManiaNetForm local_c0 [4];
  CClassicArchive aCStack_bc [12];
  CNetConnectedClient aCStack_b0 [16];
  CTrackManiaNetForm aCStack_a0 [8];
  CNetArchive local_98 [140];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a8ef06;
  local_c = ExceptionList;
  pCVar1 = (CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffff18);
  ExceptionList = &local_c;
  CTrackManiaNetForm::CTrackManiaNetForm(local_c0,(CTrackManiaNetForm *)0x1);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_4 = 0;
  CClassicArchive::CClassicArchive((CClassicArchive *)&stack0xffffff28,pCVar1);
  ppuVar9 = CNetArchive::vftable;
  pCVar10 = (CTrackManiaPlayerInfo *)0x0;
  CNetArchive::StartStoring
            ((CNetArchive *)&stack0xffffff2c,local_98,(CClassicBufferMemory *)0x1,unaff_EDI);
  pCVar2 = GetRace(this,unaff_ESI);
  pCVar8 = (CPlugFileOggVorbis *)&stack0xffffff34;
  (**(code **)(*(int *)pCVar2 + 0x250))();
  CNetArchive::EndReading((CNetArchive *)&stack0xffffff30,pCVar8,unaff_EBP);
  CGameNetwork::Send((CGameNetwork *)this,aCStack_b0,in_stack_00000014);
  pCVar3 = GetServerInfo(this,unaff_EBX);
  if (*(int *)(pCVar3 + 0x200) == 9) {
    pCVar2 = GetRace(this_00,in_stack_ffffff28);
    pCVar2 = pCVar2 + 0x590;
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (pCVar2,(CFastBuffer<class_CCrystalFace*> *)ppuVar9);
    if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar2,pCVar7,(ulong)in_stack_ffffff30);
        if ((*(int *)(*(int *)pSVar5 + 0x54) != 0) &&
           (*(int *)(*(int *)(*(int *)pSVar5 + 0x54) + 0x70) != 0)) {
          in_stack_ffffff30 = pCVar7;
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (pCVar2,pCVar7,(ulong)in_stack_ffffff34);
          in_stack_ffffff34 = (CNetConnectedClient *)0x4de996;
          iVar6 = CTrackManiaRaceScore::IsPureSpectator(*(CTrackManiaRaceScore **)pSVar5,pCVar10);
          if (iVar6 == 0) {
            in_stack_ffffff34 = (CNetConnectedClient *)local_98;
            in_stack_ffffff30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4de9b7;
            CGameNetwork::Send((CGameNetwork *)this,in_stack_ffffff34,in_stack_0000002c);
            break;
          }
        }
        pCVar7 = pCVar7 + 1;
      } while (pCVar7 < pCVar4);
    }
  }
  in_stack_00000018 = (void *)((uint)in_stack_00000018 & 0xffffff00);
  CClassicArchive::~CClassicArchive(aCStack_bc,(CClassicArchive *)in_stack_ffffff30);
  uStack0000001c = 0xffffffff;
  CTrackManiaNetForm::~CTrackManiaNetForm(aCStack_a0,(CTrackManiaNetForm *)in_stack_ffffff34);
  ExceptionList = in_stack_00000018;
  return;
}
}

// =================================================
// Function: CTrackManiaNetwork::SetForceShowAllOpponents
// =================================================
int __thiscall
CTrackManiaNetwork::SetForceShowAllOpponents
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,int param_2,CFastString *param_3)
{
{
  CTrackManiaNetworkServerInfo *pCVar1;
  CTrackManiaNetwork *unaff_ESI;
  CTrackManiaNetwork *unaff_EDI;
  CGameNetServerInfo *unaff_retaddr;
  
  pCVar1 = GetServerInfo(this,unaff_EDI);
  if (*(uint *)(pCVar1 + 0x2ac) != (uint)(param_1 != (CTrackManiaNetwork *)0x0)) {
    pCVar1 = GetServerInfo(this,unaff_ESI);
    *(uint *)(pCVar1 + 0x2ac) = (uint)(param_1 != (CTrackManiaNetwork *)0x0);
    pCVar1 = GetServerInfo(this,(CTrackManiaNetwork *)0x1);
    CGameNetServerInfo::SetReloadNeeded((CGameNetServerInfo *)pCVar1,unaff_retaddr,(EReload)param_1)
    ;
  }
  return 1;
}
}

// =================================================
// Function: CTrackManiaNetwork::SetRoundForcedLaps
// =================================================
int __thiscall
CTrackManiaNetwork::SetRoundForcedLaps
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,ulong param_2,CFastString *param_3)
{
{
  CTrackManiaNetworkServerInfo *pCVar1;
  CTrackManiaNetwork *unaff_ESI;
  CTrackManiaNetwork *unaff_EDI;
  CGameNetServerInfo *unaff_retaddr;
  
  pCVar1 = GetServerInfo(this,unaff_EDI);
  if (*(ulong *)(pCVar1 + 0x260) != param_2) {
    pCVar1 = GetServerInfo(this,unaff_ESI);
    *(ulong *)(pCVar1 + 0x260) = param_2;
    pCVar1 = GetServerInfo(this,(CTrackManiaNetwork *)0x2);
    CGameNetServerInfo::SetReloadNeeded((CGameNetServerInfo *)pCVar1,unaff_retaddr,(EReload)param_1)
    ;
  }
  return 1;
}
}

// =================================================
// Function: CTrackManiaNetwork::ValidateReplay
// =================================================
void __thiscall
CTrackManiaNetwork::ValidateReplay
          (CTrackManiaNetwork *this,CTrackManiaNetwork *param_1,SMwFiberContext **param_2,
          CFastString *param_3,CFastStringInt *param_4,int param_5,CFastString *param_6,
          CMwNodRef<class_CGameCtnReplayRecord> *param_7,ulong param_8,ulong param_9)
{
{
  undefined4 *puVar1;
  SContext *pSVar2;
  void *this_00;
  undefined4 extraout_EAX;
  int iVar3;
  int iVar4;
  undefined4 *extraout_EAX_00;
  SStringParamInt *pSVar5;
  CFastStringInt *extraout_EAX_01;
  CTrackManiaRace *extraout_EAX_02;
  CTrackManiaRaceNet *this_01;
  undefined4 *extraout_EAX_03;
  SCasterCat *pSVar6;
  CFastStringInt *extraout_EAX_04;
  CTrackManiaMenus *this_02;
  undefined4 uVar7;
  ETmValidateResult *pEVar8;
  SStringParam *unaff_EBX;
  CFastStringInt *unaff_ESI;
  CGameDialogs *unaff_EDI;
  CTrackManiaRace *pCVar9;
  SMwFiberContext **ppSVar10;
  SStringParam *in_stack_fffffe3c;
  STmValidateParam *pSVar11;
  SStringParam *in_stack_fffffe40;
  SStringParam *in_stack_fffffe44;
  CFastStringInt *pCVar12;
  CTrackMania *pCVar13;
  int iVar14;
  SStringParam *pSVar15;
  CFastStringInt *in_stack_fffffe5c;
  CTrackManiaNetwork *in_stack_fffffe60;
  SNationConfig *in_stack_fffffe64;
  wchar_t *pwVar16;
  SNationConfig *pSVar17;
  SNationConfig *in_stack_fffffe68;
  undefined *puVar18;
  SNationConfig *in_stack_fffffe6c;
  SStringParam *pSVar19;
  _func___cdecl_void *p_Var20;
  uint uVar21;
  SNationConfig *pSVar22;
  undefined *local_184;
  wchar_t *local_180;
  undefined *local_17c;
  undefined4 local_178;
  undefined1 local_174 [8];
  undefined1 local_16c [8];
  CGameDialogs local_164 [4];
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140 [2];
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128 [4];
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104 [5];
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  _func___cdecl_void *p_Stack_d0;
  CFastStringInt *pCStack_cc;
  undefined4 uStack_c8;
  wchar_t *pwStack_c4;
  undefined *local_c0;
  undefined4 local_bc;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  _func___cdecl_void *local_ac;
  CFastStringInt *local_a8;
  undefined4 local_a4;
  undefined1 local_a0 [4];
  CFastStringInt local_9c [4];
  undefined1 local_98 [8];
  undefined1 local_90 [4];
  CFastStringInt local_8c [4];
  CFastStringInt local_88 [4];
  undefined1 local_84 [4];
  undefined1 local_80 [4];
  undefined1 local_7c [4];
  undefined1 auStack_78 [12];
  undefined1 local_6c [4];
  CFastStringInt local_68 [4];
  undefined1 local_64 [4];
  CFastStringInt local_60 [4];
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  CFastStringInt aCStack_54 [12];
  undefined1 auStack_48 [8];
  SStringParamInt aSStack_40 [4];
  CFastStringInt local_3c [16];
  undefined1 auStack_2c [4];
  CMwNod *local_28;
  undefined1 local_24 [4];
  CFastStringInt aCStack_20 [12];
  void *local_14;
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = 0xffffffff;
  local_10 = &LAB_00a8f3f0;
  local_14 = ExceptionList;
  pSVar2 = (SContext *)(DAT_00cca150 ^ (uint)&stack0xfffffe50);
  ExceptionList = &local_14;
  if (*(int *)param_1 == -1) {
    ExceptionList = &LAB_00a8f3f0;
    return;
  }
  if (*(int *)param_1 == 0) {
    in_stack_fffffe44 = (SStringParam *)0x4e1fef;
    this_00 = operator_new(0x6c);
    if (this_00 == (void *)0x0) {
      uVar7 = 0;
    }
    else {
      `public:_void___thiscall_CTrackManiaNetwork::
      ValidateReplay(struct_SMwFiberContext*&,class_CFastString_const&,class_CFastStringInt_const&,int,class_CFastString_const&,class_CMwNodRef<class_CGameCtnReplayRecord>_const&,unsigned_long,unsigned_long)'
      ::__l2::SContext::SContext(this_00,pSVar2);
      uVar7 = extraout_EAX;
    }
    *(undefined4 *)param_1 = uVar7;
  }
  uVar21 = *(uint *)(*(int *)param_1 + 4);
  if (uVar21 < 0x1465) {
    if (uVar21 != 0x1464) {
      if (0x1428 < uVar21) {
        if (uVar21 != 0x145f) goto LAB_004e2a81;
        goto LAB_004e2a32;
      }
      if (uVar21 != 0x1428) {
        if (uVar21 == 0) {
          pCVar13 = (CTrackMania *)0x4e20a9;
          CMwNodRef<class_CGameNetOnlineMessage>::operator=
                    ((void *)(*(int *)param_1 + 0x10),(SNormalDec3N *)param_6,(GmVec3 *)unaff_EDI);
          if (*(int *)(*(int *)param_1 + 0x10) == 0) {
            uVar7 = 0;
          }
          else {
            param_6 = (CFastString *)0x4e20bb;
            pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(*(int *)(*(int *)param_1 + 0x10) + 0x18),
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                (ulong)unaff_ESI);
            uVar7 = *(undefined4 *)pSVar6;
          }
          *(undefined4 *)(*(int *)param_1 + 0x14) = uVar7;
          unaff_EDI = (CGameDialogs *)param_2[1];
          CFastString::SetString
                    ((CFastString *)(*(int *)param_1 + 0x18),(CFastStringInt *)&stack0xfffffe50,
                     in_stack_fffffe3c);
          unaff_ESI = *(CFastStringInt **)(param_3 + 4);
          CFastStringInt::SetString
                    ((void *)(*(int *)param_1 + 0x20),(CFastStringInt *)&stack0xfffffe54,
                     in_stack_fffffe40);
          unaff_EBX = DAT_00d71d5c;
          in_stack_fffffe5c = DAT_00d71d58;
          CFastStringInt::SetString
                    ((void *)(*(int *)param_1 + 0x34),(CFastStringInt *)&stack0xfffffe58,
                     in_stack_fffffe44);
          iVar3 = CTrackMania::IsInStuntsMode(*(CTrackMania **)(this + 0x5f8),pCVar13);
          *(int *)(*(int *)param_1 + 0x44) = iVar3;
          *(CFastStringInt **)(*(int *)param_1 + 0x3c) = param_4;
          in_stack_fffffe60 = *(CTrackManiaNetwork **)(param_5 + 4);
          in_stack_fffffe64 = *(SNationConfig **)param_5;
          CFastString::SetString
                    ((CFastString *)(*(int *)param_1 + 0x50),(CFastStringInt *)&stack0xfffffe60,
                     (SStringParam *)param_6);
          *(undefined4 *)(*(int *)param_1 + 0x68) = 0;
          *(undefined4 *)(this + 0x820) = 1;
          if (*(int *)(*(int *)param_1 + 0x3c) == 0) {
LAB_004e21b2:
            iVar3 = *(int *)param_1;
            if (((*(int *)(iVar3 + 0x3c) != 0) &&
                (*(CGameCtnGhost **)(iVar3 + 0x14) != (CGameCtnGhost *)0x0)) &&
               (iVar3 = CGameCtnGhost::CanValidate
                                  (*(CGameCtnGhost **)(iVar3 + 0x14),
                                   *(CGameCtnGhost **)(this + 0x5f8),(CGameApp *)(iVar3 + 0x34),
                                   (CFastStringInt *)unaff_EDI), iVar3 == 0)) {
              uStack_138 = *(undefined4 *)(*(int *)param_1 + 0x24);
              uStack_134 = *(undefined4 *)(*(int *)param_1 + 0x20);
              local_130 = 0;
              pSVar5 = (SStringParamInt *)
                       CClassicI18n::GetTranslatedStringInternal
                                 ((CClassicI18n *)&DAT_00d71d10,
                                  (CClassicI18n *)L"Could not validate the replay for $<%1$>",
                                  (wchar_t *)unaff_ESI);
              SStringParamInt::SStringParamInt(local_6c,pSVar5,(wchar_t *)unaff_EBX);
              unaff_EBX = (SStringParam *)&local_130;
              unaff_ESI = local_68;
              unaff_EDI = (CGameDialogs *)0x4e222c;
              CFastStringInt::SetCompose
                        ((void *)(*(int *)param_1 + 0x60),unaff_ESI,unaff_EBX,
                         (SStringParamInt *)in_stack_fffffe5c);
              *(undefined4 *)(*(int *)param_1 + 0x3c) = 0;
              if (*(int *)(this + 0x660) != 0) {
                RefereeLog(this,(CTrackManiaNetwork *)(*(int *)param_1 + 0x60),(CFastStringInt *)0x0
                           ,(int)in_stack_fffffe60);
                RefereeLog(this,(CTrackManiaNetwork *)(*(int *)param_1 + 0x34),(CFastStringInt *)0x0
                           ,(int)in_stack_fffffe64);
                *(undefined4 *)(*(int *)param_1 + 4) = 0x1402;
                ExceptionList = param_2;
                return;
              }
              goto LAB_004e2039;
            }
          }
          else {
            iVar3 = *(int *)(*(int *)param_1 + 0x10);
            if (iVar3 != 0) {
              iVar3 = *(int *)(iVar3 + 0x24);
              iVar4 = (**(code **)(*(int *)this + 0x164))();
              if (*(int *)(iVar3 + 0xdc) == *(int *)(iVar4 + 0xdc)) goto LAB_004e21b2;
            }
            *(undefined4 *)(*(int *)param_1 + 0x3c) = 0;
          }
        }
        else {
          if (uVar21 != 0x1402) goto LAB_004e2a81;
LAB_004e2039:
          if (*(int *)(this + 0x1b0) != 0) {
            iVar3 = *(int *)param_1;
            SendInvalidReplay(this,(CTrackManiaNetwork *)(iVar3 + 0x18),
                              *(CFastString **)(iVar3 + 0x10),(CGameCtnReplayRecord *)(iVar3 + 0x34)
                              ,(CFastStringInt *)unaff_EDI);
          }
        }
        iVar3 = *(int *)param_1;
        if (*(int *)(iVar3 + 0x3c) == 0) {
          *(undefined4 *)(this + 0x820) = 0;
          iVar3 = *(int *)param_1;
          if (*(int *)(iVar3 + 0x10) == 0) {
            local_17c = *(undefined **)(iVar3 + 0x54);
            local_178 = *(undefined4 *)(iVar3 + 0x50);
            CFastStringInt::SetString
                      ((void *)(iVar3 + 0x58),(CFastStringInt *)&local_17c,(SStringParam *)unaff_EDI
                      );
            if (*(int *)(this + 0x1b0) != 0) {
              SendInvalidReplay(this,(CTrackManiaNetwork *)(*(int *)param_1 + 0x18),
                                (CFastString *)0x0,(CGameCtnReplayRecord *)(*(int *)param_1 + 0x58),
                                unaff_ESI);
            }
            if (*(int *)(this + 0x660) != 0) {
              local_184 = PTR_DAT_00bbf7dc;
              pSVar5 = (SStringParamInt *)
                       CClassicI18n::GetTranslatedString((CFastStringInt *)(*(int *)param_1 + 0x58))
              ;
              SStringParamInt::SStringParamInt(auStack_48,pSVar5,(wchar_t *)unaff_EBX);
              local_160 = *(undefined4 *)(*(int *)param_1 + 0x24);
              local_15c = *(undefined4 *)(*(int *)param_1 + 0x20);
              local_158 = 0;
              SStringParam::SStringParam
                        (local_a0,(SStringParam *)"$<%1$> : %2",(char *)in_stack_fffffe5c);
              CFastStringInt::SetCompose(&local_180,local_9c,(SStringParam *)&local_15c,aSStack_40);
              RefereeLog(this,(CTrackManiaNetwork *)&local_180,(CFastStringInt *)0x0,
                         (int)in_stack_fffffe60);
              CGameCtnApp::SNationConfig::~SNationConfig(&local_17c,in_stack_fffffe64);
              *(undefined4 *)(*(int *)param_1 + 4) = 0x147a;
              ExceptionList = param_2;
              return;
            }
            pCVar12 = (CFastStringInt *)
                      CClassicI18n::GetTranslatedString((CFastStringInt *)(*(int *)param_1 + 0x58));
            CFastStringInt::CFastStringInt(local_16c,pCVar12,unaff_EBX);
            CFastStringInt::CFastStringInt
                      (local_80,(CFastStringInt *)&DAT_00b38330,(SStringParam *)in_stack_fffffe5c);
            unaff_EDI = local_164;
            param_2 = (SMwFiberContext **)CONCAT31(param_2._1_3_,10);
            unaff_ESI = extraout_EAX_01;
            CGameDialogs::DoMessage
                      (*(CGameDialogs **)(this + 0x118),unaff_EDI,extraout_EAX_01,
                       (CFastStringInt *)0x0,(CMwNod *)0x0,(_func___cdecl_void *)in_stack_fffffe60);
            CGameCtnApp::SNationConfig::~SNationConfig(auStack_78,in_stack_fffffe64);
            CGameCtnApp::SNationConfig::~SNationConfig(&local_15c,in_stack_fffffe68);
            goto LAB_004e255b;
          }
          goto LAB_004e2a32;
        }
        pwVar16 = (wchar_t *)0x0;
        uStack_8 = 0;
        puVar18 = PTR_DAT_00bbf7d8;
        if (*(int *)(iVar3 + 0x44) == 0) {
          CMwTimer::GetMmSsCcTimeStringFromMwTime
                    (*(ulong *)(*(int *)(iVar3 + 0x14) + 0xe8),(CFastString *)&stack0xfffffe64);
        }
        else {
          CFastString::SetNatural
                    ((CFastString *)&stack0xfffffe64,
                     *(CFastString **)(*(int *)(iVar3 + 0x14) + 0xf0),0,0,0,0,1,(int)unaff_EDI);
        }
        local_184 = puVar18;
        local_180 = pwVar16;
        CFastStringInt::CFastStringInt
                  (local_84,(CFastStringInt *)&local_184,(SStringParam *)unaff_EDI);
        uStack_f0 = extraout_EAX_00[1];
        unaff_EDI = (CGameDialogs *)&uStack_f0;
        uStack_ec = *extraout_EAX_00;
        local_e8 = 0;
        CFastStringInt::SetString
                  ((void *)(*(int *)param_1 + 0x28),(CFastStringInt *)unaff_EDI,
                   (SStringParam *)unaff_ESI);
        unaff_ESI = (CFastStringInt *)0x4e22ee;
        CGameCtnApp::SNationConfig::~SNationConfig(local_7c,(SNationConfig *)unaff_EBX);
        unaff_EBX = (SStringParam *)0x4e2302;
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                  (&stack0xfffffe70,(SHeaderCommunity *)in_stack_fffffe5c);
        if (*(int *)(this + 0x660) != 0) {
          local_180 = (wchar_t *)0x0;
          local_17c = PTR_DAT_00bbf7dc;
          iVar3 = *(int *)param_1;
          local_114 = *(undefined4 *)(iVar3 + 0x2c);
          local_110 = *(undefined4 *)(iVar3 + 0x28);
          local_10c = 0;
          uStack_b4 = *(undefined4 *)(iVar3 + 0x24);
          uStack_b0 = *(undefined4 *)(iVar3 + 0x20);
          param_2 = (SMwFiberContext **)0x2;
          local_ac = (_func___cdecl_void *)0x0;
          pSVar5 = (SStringParamInt *)
                   CClassicI18n::GetTranslatedStringInternal
                             ((CClassicI18n *)&DAT_00d71d10,
                              (CClassicI18n *)L"Validating $<%1$> (%2)...",
                              (wchar_t *)in_stack_fffffe60);
          SStringParamInt::SStringParamInt(local_24,pSVar5,pwVar16);
          unaff_EBX = (SStringParam *)0x4e239c;
          CFastStringInt::SetCompose
                    (&local_178,aCStack_20,(SStringParam *)&local_ac,(SStringParamInt *)&local_10c);
          in_stack_fffffe60 = (CTrackManiaNetwork *)&local_178;
          in_stack_fffffe5c = (CFastStringInt *)0x4e23a9;
          RefereeLog(this,in_stack_fffffe60,(CFastStringInt *)0x0,(int)puVar18);
          param_5 = -1;
          CGameCtnApp::SNationConfig::~SNationConfig(local_174,in_stack_fffffe6c);
        }
        *(undefined4 *)(*(int *)param_1 + 0xc) = 0;
      }
      iVar3 = *(int *)param_1;
      iVar4 = *(int *)(iVar3 + 0xc);
      if ((iVar4 == 0) || (iVar4 == -1)) {
        uVar21 = 0;
      }
      else {
        uVar21 = (uint)(*(int *)(iVar4 + 4) == -1);
      }
      iVar4 = *(int *)(iVar3 + 0x44);
      STmValidateParam::STmValidateParam(auStack_2c,*(STmValidateParam **)(iVar3 + 0x14));
      iVar3 = *(int *)param_1;
      iVar14 = 0;
      pEVar8 = (ETmValidateResult *)(uint)(*(int *)(this + 0x660) == 0);
      pCVar12 = (CFastStringInt *)0x0;
      local_c = 3;
      pSVar11 = (STmValidateParam *)(iVar3 + 0x34);
      ppSVar10 = (SMwFiberContext **)(iVar3 + 0x30);
      pCVar9 = extraout_EAX_02;
      this_01 = GetRace(this,(CTrackManiaNetwork *)(iVar3 + 0xc));
      CTrackManiaRace::Validate
                ((CTrackManiaRace *)this_01,pCVar9,ppSVar10,pSVar11,pEVar8,pCVar12,iVar14,iVar4,
                 (int)unaff_EDI);
      if (local_28 != (CMwNod *)0x0) {
        unaff_EDI = (CGameDialogs *)0x4e25f4;
        CMwNod::MwRelease(local_28,(CMwNod *)0x4e25f4);
      }
      if (uVar21 != 0) {
        ExceptionList = local_10;
        return;
      }
      if (*(int *)(*(int *)param_1 + 0xc) != -1) {
        *(undefined4 *)(*(int *)param_1 + 4) = 0x1428;
        ExceptionList = local_10;
        return;
      }
      *(undefined4 *)(this + 0x820) = 0;
      pSVar17 = (SNationConfig *)0x0;
      pSVar19 = (SStringParam *)0x0;
      iVar3 = *(int *)param_1;
      uStack_8 = 5;
      pSVar22 = (SNationConfig *)0x0;
      puVar18 = PTR_DAT_00bbf7dc;
      p_Var20 = (_func___cdecl_void *)PTR_DAT_00bbf7dc;
      if (*(int *)(iVar3 + 0x30) == 1) {
        local_10c = *(undefined4 *)(iVar3 + 0x2c);
        local_108 = *(undefined4 *)(iVar3 + 0x28);
        local_104[0] = 0;
        local_154 = *(undefined4 *)(iVar3 + 0x24);
        local_150 = *(undefined4 *)(iVar3 + 0x20);
        local_14c = 0;
        pSVar5 = (SStringParamInt *)
                 CClassicI18n::GetTranslatedStringInternal
                           ((CClassicI18n *)&DAT_00d71d10,
                            (CClassicI18n *)L"The score of $<%1$> (%2) is valid.",
                            (wchar_t *)unaff_EDI);
        SStringParamInt::SStringParamInt(local_64,pSVar5,(wchar_t *)unaff_ESI);
        pSVar5 = (SStringParamInt *)local_104;
        pSVar15 = (SStringParam *)&local_14c;
        pCVar12 = local_60;
LAB_004e2787:
        CFastStringInt::SetCompose(&stack0xfffffe6c,pCVar12,pSVar15,pSVar5);
      }
      else {
        if (*(int *)(iVar3 + 0x30) != 0) {
          local_130 = *(undefined4 *)(iVar3 + 0x2c);
          local_12c = *(undefined4 *)(iVar3 + 0x28);
          local_128[0] = 0;
          local_118 = *(undefined4 *)(iVar3 + 0x24);
          local_114 = *(undefined4 *)(iVar3 + 0x20);
          local_110 = 0;
          pSVar5 = (SStringParamInt *)
                   CClassicI18n::GetTranslatedStringInternal
                             ((CClassicI18n *)&DAT_00d71d10,
                              (CClassicI18n *)L"We can\'t validate the score of $<%1$> (%2).",
                              (wchar_t *)unaff_EDI);
          SStringParamInt::SStringParamInt(aSStack_40,pSVar5,(wchar_t *)unaff_ESI);
          pSVar5 = (SStringParamInt *)local_128;
          pSVar15 = (SStringParam *)&local_110;
          pCVar12 = local_3c;
          goto LAB_004e2787;
        }
        local_148 = *(undefined4 *)(iVar3 + 0x2c);
        local_144 = *(undefined4 *)(iVar3 + 0x28);
        local_140[0] = 0;
        local_160 = *(undefined4 *)(iVar3 + 0x24);
        local_15c = *(undefined4 *)(iVar3 + 0x20);
        local_158 = 0;
        pSVar5 = (SStringParamInt *)
                 CClassicI18n::GetTranslatedStringInternal
                           ((CClassicI18n *)&DAT_00d71d10,
                            (CClassicI18n *)L"The score of $<%1$> (%2) is not valid.",
                            (wchar_t *)unaff_EDI);
        SStringParamInt::SStringParamInt(local_58,pSVar5,(wchar_t *)unaff_ESI);
        CFastStringInt::SetCompose
                  (&stack0xfffffe6c,aCStack_54,(SStringParam *)&local_158,
                   (SStringParamInt *)local_140);
        local_17c = (undefined *)
                    CGameCtnGhost::IsSameSystem
                              (*(CGameCtnGhost **)(*(int *)param_1 + 0x14),
                               (CGameCtnGhost *)&stack0xfffffe78,(CFastStringInt *)unaff_EBX);
      }
      if (*(int *)(*(int *)param_1 + 0x34) != 0) {
        SStringParam::SStringParam(local_8c,(SStringParam *)&DAT_00b32c2c,(char *)unaff_EBX);
        CFastStringInt::CFastStringInt(local_98,local_88,(SStringParam *)in_stack_fffffe5c);
        uStack_f0 = extraout_EAX_03[1];
        uStack_ec = *extraout_EAX_03;
        in_stack_fffffe5c = (CFastStringInt *)&uStack_f0;
        param_2 = (SMwFiberContext **)CONCAT31(param_2._1_3_,6);
        local_e8 = 0;
        unaff_EBX = (SStringParam *)0x4e27ef;
        CFastStringInt::Concat(&stack0xfffffe74,in_stack_fffffe5c,(SStringParam *)in_stack_fffffe60)
        ;
        in_stack_fffffe60 = (CTrackManiaNetwork *)0x4e2803;
        CGameCtnApp::SNationConfig::~SNationConfig(local_90,pSVar17);
      }
      local_e0 = *(undefined4 *)(*(int *)param_1 + 0x38);
      local_dc = *(undefined4 *)(*(int *)param_1 + 0x34);
      local_d8 = 0;
      unaff_EDI = (CGameDialogs *)0x4e2833;
      CFastStringInt::Concat(&stack0xfffffe6c,(CFastStringInt *)&local_e0,unaff_EBX);
      if (local_17c == (undefined *)0x0) {
        uStack_c8 = 0;
        unaff_ESI = (CFastStringInt *)0x4e28d7;
        p_Stack_d0 = p_Var20;
        pCStack_cc = (CFastStringInt *)pSVar19;
        CFastStringInt::SetString
                  ((void *)(*(int *)param_1 + 0x34),(CFastStringInt *)&p_Stack_d0,
                   (SStringParam *)in_stack_fffffe5c);
      }
      else {
        pwStack_c4 = local_180;
        local_c0 = local_184;
        local_bc = 0;
        local_a4 = 0;
        local_ac = p_Var20;
        local_a8 = (CFastStringInt *)pSVar19;
        SStringParam::SStringParam(local_90,(SStringParam *)"%1\n\n%2",(char *)in_stack_fffffe5c);
        unaff_ESI = local_8c;
        unaff_EDI = (CGameDialogs *)0x4e28a6;
        CFastStringInt::SetCompose
                  ((void *)(*(int *)param_1 + 0x34),unaff_ESI,(SStringParam *)&local_a8,
                   (SStringParamInt *)&local_c0);
      }
      CGameCtnApp::SNationConfig::~SNationConfig(&local_180,(SNationConfig *)in_stack_fffffe60);
      CGameCtnApp::SNationConfig::~SNationConfig(&stack0xfffffe78,pSVar17);
      if (((*(int *)(this + 0x660) != 0) &&
          (param_7 != (CMwNodRef<class_CGameCtnReplayRecord> *)0xffffffff)) &&
         (param_8 != 0xffffffff)) {
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)puVar18);
        unaff_ESI = (CFastStringInt *)0x4e2937;
        SendRefereePlayerScoreCheckResult
                  (this,(CTrackManiaNetwork *)param_7,(ulong)param_2,(CFastString *)param_8,
                   *(ulong *)(*(int *)param_1 + 0x30),*(ETmValidateResult *)(*(int *)pSVar6 + 0x31c)
                   ,(ulong)in_stack_fffffe6c);
        *(undefined4 *)(*(int *)param_1 + 0x68) = 1;
      }
      if ((*(int *)(this + 0x1b0) != 0) && (iVar3 = *(int *)param_1, *(int *)(iVar3 + 0x30) == 0)) {
        SendInvalidReplay(this,(CTrackManiaNetwork *)(iVar3 + 0x18),*(CFastString **)(iVar3 + 0x10),
                          (CGameCtnReplayRecord *)(iVar3 + 0x34),(CFastStringInt *)pSVar19);
      }
      if (*(int *)(this + 0x660) != 0) {
        RefereeLog(this,(CTrackManiaNetwork *)(*(int *)param_1 + 0x34),(CFastStringInt *)0x0,
                   (int)pSVar19);
        *(undefined4 *)(*(int *)param_1 + 4) = 0x145f;
        ExceptionList = (void *)param_5;
        return;
      }
      CFastStringInt::CFastStringInt(local_5c,(CFastStringInt *)&DAT_00b38330,pSVar19);
      param_7 = (CMwNodRef<class_CGameCtnReplayRecord> *)&DAT_00000007;
      CGameDialogs::DoMessage
                (*(CGameDialogs **)(this + 0x118),(CGameDialogs *)(*(int *)param_1 + 0x34),
                 extraout_EAX_04,(CFastStringInt *)0x0,(CMwNod *)0x0,p_Var20);
      param_8 = 0xffffffff;
      CGameCtnApp::SNationConfig::~SNationConfig(aCStack_54,pSVar22);
    }
    if (*(int *)(*(int *)(this + 0x118) + 0x14) == 0) {
      *(undefined4 *)(*(int *)param_1 + 4) = 0x1464;
      ExceptionList = local_10;
      return;
    }
  }
  else if (uVar21 != 0x147a) {
    if (uVar21 != 0x147f) {
      if (uVar21 == 0xffffffff) {
        *(undefined4 *)(this + 0x820) = 0;
      }
      goto LAB_004e2a81;
    }
LAB_004e255b:
    if (*(int *)(*(int *)(this + 0x118) + 0x14) == 0) {
      *(undefined4 *)(*(int *)param_1 + 4) = 0x147f;
      ExceptionList = local_10;
      return;
    }
  }
LAB_004e2a32:
  if (*(int *)(this + 0x660) == 0) {
    this_02 = GetMenuManager(this,(CTrackManiaNetwork *)unaff_EDI);
    unaff_EDI = (CGameDialogs *)0x4e2a48;
    CGameCtnMenus::HideDialogs((CGameCtnMenus *)this_02,(CGameCtnMenus *)unaff_ESI);
    if (*(int *)(this + 0x660) == 0) goto LAB_004e2a81;
  }
  if (*(int *)(*(int *)param_1 + 0x68) == 0) {
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)unaff_EDI);
    SendRefereePlayerScoreCheckResult
              (this,(CTrackManiaNetwork *)param_7,(ulong)param_2,(CFastString *)param_8,2,
               *(ETmValidateResult *)(*(int *)pSVar6 + 0x31c),(ulong)unaff_ESI);
  }
LAB_004e2a81:
  puVar1 = *(undefined4 **)param_1;
  if ((puVar1 != (undefined4 *)0xffffffff) && (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)param_1 = 0xffffffff;
  ExceptionList = local_10;
  return;
}
}

