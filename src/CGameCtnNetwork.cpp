// Class implementation: CGameCtnNetwork

// =================================================
// Function: CGameCtnNetwork::ForcedMods_Send
// =================================================
void __thiscall
CGameCtnNetwork::ForcedMods_Send
          (CGameCtnNetwork *this,CGameCtnNetwork *param_1,CGameNetPlayerInfo *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CNetNod *pCVar3;
  ulong unaff_EBP;
  int unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CClassicArchive *unaff_EDI;
  void *in_stack_0000001c;
  undefined4 uStack00000020;
  int in_stack_00000024;
  CClassicArchive *in_stack_ffffff98;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff9c;
  undefined **ppuVar5;
  CFastString *in_stack_ffffffa4;
  CClassicArchive *in_stack_ffffffa8;
  CGameCtnNetForm *pCVar6;
  CSystemPackManager *in_stack_ffffffb0;
  CClassicArchive *in_stack_ffffffb4;
  CSystemPackDesc **in_stack_ffffffb8;
  CSystemPackManager local_38 [8];
  CNetConnectedClient aCStack_30 [4];
  CGameCtnNetForm local_2c [8];
  CNetArchive local_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aaff40;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CGameCtnNetForm::CGameCtnNetForm
            ((CGameCtnNetForm *)&stack0xffffffb0,(CGameCtnNetForm *)&DAT_0000000e,
             (EMessageType)((uint)DAT_00cca150 ^ (uint)&stack0xffffff8c));
  CClassicArchive::CClassicArchive((CClassicArchive *)&stack0xffffff9c,unaff_EDI);
  ppuVar5 = CNetArchive::vftable;
  pCVar6 = (CGameCtnNetForm *)0x0;
  CNetArchive::StartStoring
            ((CNetArchive *)&stack0xffffffa0,local_24,(CClassicBufferMemory *)0x1,unaff_ESI);
  CClassicArchive::DoBool
            ((CClassicArchive *)&stack0xffffffa4,(CClassicArchive *)(*(int *)(this + 0x5f8) + 0x310)
             ,(int *)0x1,unaff_EBP);
  CFastBuffer<struct_SCtnForcedMods::SEnvMod>::ArchiveCount
            ((void *)(*(int *)(this + 0x5f8) + 0x314),
             (CFastArray<class_CPlugFileSnd*> *)&stack0xffffffa8,in_stack_ffffff98);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(*(int *)(this + 0x5f8) + 0x314),in_stack_ffffff9c);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                         ((void *)(*(int *)(this + 0x5f8) + 0x314),pCVar4,0xd71ca4);
      CMwId::GetName(pSVar2,(CTrackManiaEditorIconPage *)ppuVar5);
      ppuVar5 = (undefined **)0x1;
      CClassicArchive::DoString
                ((CClassicArchive *)&stack0xffffffb4,(CClassicCrypto_BlowFish *)&DAT_00d71ca4,
                 (CFastString *)0x1,in_stack_ffffffa4,(ECipherOpMode)in_stack_ffffffa8,
                 (uint64 *)pCVar6,(int)in_stack_ffffffb0);
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                         ((void *)(*(int *)(this + 0x5f8) + 0x314),pCVar4,(ulong)in_stack_ffffffb4);
      in_stack_ffffffb4 = (CClassicArchive *)(pSVar2 + 4);
      in_stack_ffffffb0 = local_38;
      pCVar6 = (CGameCtnNetForm *)0x67c304;
      CSystemPackManager::ArchivePackDesc
                (DAT_00d54250,in_stack_ffffffb0,in_stack_ffffffb4,in_stack_ffffffb8);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  CNetArchive::EndReading
            ((CNetArchive *)&stack0xffffffb0,(CPlugFileOggVorbis *)ppuVar5,
             (SStreamContext **)in_stack_ffffffa4);
  if (in_stack_00000024 == 0) {
    pCVar3 = (CNetNod *)0xff;
  }
  else {
    pCVar3 = (CNetNod *)
             CONCAT31((int3)((uint)in_stack_00000024 >> 8),*(undefined1 *)(in_stack_00000024 + 0x24)
                     );
  }
  CGameNetwork::Send((CGameNetwork *)this,aCStack_30,pCVar3);
  in_stack_0000001c = (void *)((uint)in_stack_0000001c & 0xffffff00);
  CClassicArchive::~CClassicArchive((CClassicArchive *)&stack0xffffffb8,in_stack_ffffffa8);
  uStack00000020 = 0xffffffff;
  CGameCtnNetForm::~CGameCtnNetForm(local_2c,pCVar6);
  ExceptionList = in_stack_0000001c;
  return;
}
}

// =================================================
// Function: CGameCtnNetwork::ForcedMusic_Send
// =================================================
void __thiscall
CGameCtnNetwork::ForcedMusic_Send
          (CGameCtnNetwork *this,CGameCtnNetwork *param_1,CGameNetPlayerInfo *param_2)
{
{
  CNetNod *pCVar1;
  CClassicArchive *unaff_ESI;
  void *in_stack_00000018;
  undefined4 uStack0000001c;
  int in_stack_00000020;
  int in_stack_ffffff98;
  ulong in_stack_ffffff9c;
  undefined **ppuVar2;
  CPlugFileOggVorbis *in_stack_ffffffa4;
  SStreamContext **in_stack_ffffffa8;
  CClassicArchive *pCVar3;
  CGameCtnNetForm *in_stack_ffffffb0;
  CClassicArchive local_4c [24];
  CNetConnectedClient local_34 [4];
  CGameCtnNetForm local_30 [12];
  CNetArchive local_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aafb10;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CGameCtnNetForm::CGameCtnNetForm
            ((CGameCtnNetForm *)&stack0xffffffb0,(CGameCtnNetForm *)0x10,
             (EMessageType)((uint)DAT_00cca150 ^ (uint)&stack0xffffff94));
  CClassicArchive::CClassicArchive((CClassicArchive *)&stack0xffffff9c,unaff_ESI);
  ppuVar2 = CNetArchive::vftable;
  pCVar3 = (CClassicArchive *)0x0;
  CNetArchive::StartStoring
            ((CNetArchive *)&stack0xffffffa0,local_24,(CClassicBufferMemory *)0x1,in_stack_ffffff98)
  ;
  CClassicArchive::DoBool
            ((CClassicArchive *)&stack0xffffffa4,(CClassicArchive *)(*(int *)(this + 0x5f8) + 0x324)
             ,(int *)0x1,in_stack_ffffff9c);
  CSystemPackManager::ArchivePackDesc
            (DAT_00d54250,(CSystemPackManager *)&stack0xffffffa8,
             (CClassicArchive *)(*(int *)(this + 0x5f8) + 800),(CSystemPackDesc **)ppuVar2);
  CNetArchive::EndReading((CNetArchive *)&stack0xffffffac,in_stack_ffffffa4,in_stack_ffffffa8);
  if (in_stack_00000020 == 0) {
    pCVar1 = (CNetNod *)0xff;
  }
  else {
    pCVar1 = (CNetNod *)
             CONCAT31((int3)((uint)in_stack_00000020 >> 8),*(undefined1 *)(in_stack_00000020 + 0x24)
                     );
  }
  CGameNetwork::Send((CGameNetwork *)this,local_34,pCVar1);
  in_stack_00000018 = (void *)((uint)in_stack_00000018 & 0xffffff00);
  CClassicArchive::~CClassicArchive(local_4c,pCVar3);
  uStack0000001c = 0xffffffff;
  CGameCtnNetForm::~CGameCtnNetForm(local_30,in_stack_ffffffb0);
  ExceptionList = in_stack_00000018;
  return;
}
}

// =================================================
// Function: CGameCtnNetwork::GetNbAutoSpectators
// =================================================
ulong __thiscall
CGameCtnNetwork::GetNbAutoSpectators(CGameCtnNetwork *this,CGameCtnNetwork *param_1)
{
{
  CGameCtnNetwork *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong uVar3;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x240;
  uVar3 = 0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      if (((*(int *)(*(int *)pSVar2 + 0x70) != 0) || (*(int *)(*(int *)pSVar2 + 0x74) != 0)) &&
         (unaff_ESI = pCVar4,
         pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this_00,pCVar4,unaff_EBP), *(char *)(*(int *)pSVar2 + 0x78) == -4)) {
        uVar3 = uVar3 + 1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return uVar3;
}
}

// =================================================
// Function: CGameCtnNetwork::PauseAllDataDownloads
// =================================================
void __thiscall
CGameCtnNetwork::PauseAllDataDownloads
          (CGameCtnNetwork *this,CGameCtnNetwork *param_1,ulong param_2,ulong param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CGameNetDataDownload *unaff_EBP;
  CGameCtnNetwork *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  uint in_stack_00000010;
  CGameCtnNetwork *pCVar3;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x68c,unaff_EDI);
  while (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pCVar1 = pCVar1 + -1;
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x68c,pCVar1,(ulong)unaff_ESI);
    pCVar3 = *(CGameCtnNetwork **)pSVar2;
    if (((pCVar3 != (CGameCtnNetwork *)0x0) && (param_2 <= *(uint *)(pCVar3 + 0x34))) &&
       (*(uint *)(pCVar3 + 0x34) < in_stack_00000010)) {
      PauseDataDownload(this,pCVar3,unaff_EBP);
      unaff_ESI = pCVar3;
    }
  }
  return;
}
}

// =================================================
// Function: CGameCtnNetwork::PauseDataDownload
// =================================================
void __thiscall
CGameCtnNetwork::PauseDataDownload
          (CGameCtnNetwork *this,CGameCtnNetwork *param_1,CGameNetDataDownload *param_2)
{
{
  if ((*(int *)(param_1 + 0x40) == 0) && (*(int *)(param_1 + 0x44) == 0)) {
    if (*(CNetMasterServer **)(param_1 + 0x24) != (CNetMasterServer *)0x0) {
      *(undefined4 *)(param_1 + 0x40) = 1;
      CNetMasterServer::CancelUpToDateCheck
                (*(CNetMasterServer **)(this + 0x1b0),*(CNetMasterServer **)(param_1 + 0x24),
                 (CNetMasterServerUptoDateCheck *)param_2);
      return;
    }
    if (*(CNetMasterServer **)(param_1 + 0x28) != (CNetMasterServer *)0x0) {
      CNetMasterServer::PauseDownload
                (*(CNetMasterServer **)(this + 0x1b0),*(CNetMasterServer **)(param_1 + 0x28),
                 (CNetMasterServerDownload *)param_2);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CGameCtnNetwork::SetForceSpectator
// =================================================
void __thiscall
CGameCtnNetwork::SetForceSpectator(CGameCtnNetwork *this,CGameCtnNetwork *param_1,int param_2)
{
{
  CGameCtnNetwork *this_00;
  SCasterCat *pSVar1;
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  CPlugVertexStream *unaff_retaddr;
  
  this_00 = this + 0x2fc;
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
  if ((*(int *)(*(int *)pSVar1 + 0x74) != 0) != (param_2 != 0)) {
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
    *(int *)(*(int *)pSVar1 + 0x74) = param_2;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX);
    CGameNetPlayerInfo::SetDirty(*(CGameNetPlayerInfo **)pSVar1,unaff_retaddr,(int)param_1);
    (**(code **)(*(int *)this + 0x1b4))();
  }
  return;
}
}

// =================================================
// Function: CGameCtnNetwork::UpdateSpectatorsCounts
// =================================================
void __thiscall
CGameCtnNetwork::UpdateSpectatorsCounts(CGameCtnNetwork *this,CGameCtnNetwork *param_1)
{
{
  CGameCtnNetwork *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> CVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int unaff_retaddr;
  CGameCtnNetwork *pCVar10;
  ulong in_stack_fffffff0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_8;
  CGameCtnNetwork *pCStack_4;
  
  if ((*(int *)(this + 0x5f8) != 0) &&
     (pCVar10 = this, iVar5 = (**(code **)(**(int **)(this + 0x5f8) + 0x16c))(), iVar5 != 0)) {
    pCVar1 = this + 0x240;
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(pCVar1,unaff_EDI);
    pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar1,pCVar9,(ulong)unaff_ESI);
        *(undefined4 *)(*(int *)pSVar7 + 0x7c) = 0;
        unaff_ESI = pCVar9;
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](pCVar1,pCVar9,unaff_EBP);
        pCVar9 = pCVar9 + 1;
        *(undefined4 *)(*(int *)pSVar7 + 0x80) = 0;
      } while (pCVar9 < pCVar6);
    }
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (pCVar1,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
    pCStack_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x240,pCStack_8,unaff_EBP);
        iVar5 = *(int *)pSVar7;
        pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if ((((*(int *)(iVar5 + 0x70) != 0) || (*(int *)(iVar5 + 0x74) != 0)) &&
            (*(int *)(iVar5 + 0x88) == 0)) && (*(int *)(iVar5 + 0x6c) == 0)) {
          if (*(char *)(iVar5 + 0x78) == -1) {
            *(undefined4 *)(iVar5 + 0x80) = 0;
          }
          else {
            pCVar1 = this + 0x24c;
            *(undefined4 *)(iVar5 + 0x80) = 1;
            if (*(char *)(iVar5 + 0x78) == -4) {
              unaff_EBP = 0x67a060;
              pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       CFastBuffer<class_CCrystalFace*>::GetCount
                                 (pCVar1,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
              if (pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
                do {
                  unaff_EBP = 0x67a078;
                  unaff_EBX = pCVar9;
                  pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     (pCVar1,pCVar9,(ulong)pCVar10);
                  iVar4 = *(int *)pSVar7;
                  CVar2 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar4 + 0x24);
                  if (CVar2 == pCVar8[0x1c]) {
                    *(int *)(iVar4 + 0x7c) = *(int *)(iVar4 + 0x7c) + 1;
                    pCVar10 = (CGameCtnNetwork *)0x0;
                    *(undefined4 *)(iVar4 + 0x80) = 3;
                    unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x67a0a5;
                    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                       ((void *)(unaff_retaddr + 0x2fc),
                                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                        in_stack_fffffff0);
                    if (CVar2 == *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                  (*(int *)pSVar7 + 0x24)) {
                      *(undefined4 *)(iVar5 + 0x80) = 2;
                    }
                  }
                  pCVar9 = pCVar9 + 1;
                  this = pCStack_4;
                } while (pCVar9 < pCVar8);
              }
            }
            else {
              unaff_EBP = 0x67a0c6;
              pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       CFastBuffer<class_CCrystalFace*>::GetCount
                                 (pCVar1,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
              if (pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
                do {
                  unaff_EBP = 0x67a0d8;
                  unaff_EBX = pCVar9;
                  pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     (pCVar1,pCVar9,(ulong)pCVar10);
                  iVar4 = *(int *)pSVar7;
                  cVar3 = *(char *)(iVar4 + 0x24);
                  if (cVar3 == *(char *)(iVar5 + 0x78)) {
                    *(int *)(iVar4 + 0x7c) = *(int *)(iVar4 + 0x7c) + 1;
                    pCVar10 = (CGameCtnNetwork *)0x0;
                    *(undefined4 *)(iVar4 + 0x80) = 3;
                    unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x67a101;
                    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                       ((void *)(unaff_retaddr + 0x2fc),
                                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                        in_stack_fffffff0);
                    if (cVar3 == *(char *)(*(int *)pSVar7 + 0x24)) {
                      *(undefined4 *)(iVar5 + 0x80) = 2;
                    }
                  }
                  pCVar9 = pCVar9 + 1;
                  this = pCStack_4;
                } while (pCVar9 < pCVar8);
              }
            }
          }
        }
        pCStack_8 = pCStack_8 + 1;
      } while (pCStack_8 < pCVar6);
    }
  }
  return;
}
}

