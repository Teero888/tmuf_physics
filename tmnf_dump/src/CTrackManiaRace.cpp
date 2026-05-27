// Class implementation: CTrackManiaRace

// =================================================
// Function: CTrackManiaRace::GetBlockFromCheckpointMobil
// =================================================
CGameCtnBlock * __thiscall
CTrackManiaRace::GetBlockFromCheckpointMobil
          (CTrackManiaRace *this,CTrackManiaRace *param_1,CSceneMobil *param_2)
{
{
  CGameCtnBlock *pCVar1;
  int iVar2;
  
  pCVar1 = *(CGameCtnBlock **)(param_1 + 0x1c);
  if (pCVar1 != (CGameCtnBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(0x3057000);
    if (iVar2 == 0) {
      return (CGameCtnBlock *)0x0;
    }
  }
  return pCVar1;
}
}

// =================================================
// Function: CTrackManiaRace::GetCurrentStandardTime
// =================================================
ulong __thiscall
CTrackManiaRace::GetCurrentStandardTime(CTrackManiaRace *this,CTrackManiaRace *param_1)
{
{
  CGamePlayerInfo *pCVar1;
  int iVar2;
  CGameRace *unaff_ESI;
  
  pCVar1 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,unaff_ESI);
  if (*(int *)(this + 0x288) == 0) {
    if (pCVar1 == (CGamePlayerInfo *)0x0) {
      return *(ulong *)(this + 0x274);
    }
    if (*(int *)(pCVar1 + 0x33c) == 0) {
      if (*(int *)(this + 0xf4) == 0) {
        iVar2 = *(int *)(pCVar1 + 0x2ac);
      }
      else {
        iVar2 = *(int *)(pCVar1 + 0x2b8);
      }
      if (iVar2 == 0) {
        return 0;
      }
      return *(int *)(this + 0x274) - iVar2;
    }
  }
  else if ((pCVar1 == (CGamePlayerInfo *)0x0) || (*(int *)(pCVar1 + 0x33c) == 0)) {
    return 0;
  }
  if (*(int *)(this + 0xf4) == 0) {
    return *(ulong *)(pCVar1 + 0x2b0);
  }
  return *(ulong *)(pCVar1 + 700);
}
}

// =================================================
// Function: CTrackManiaRace::GetPlayerFromMobil
// =================================================
CTrackManiaPlayer * __thiscall
CTrackManiaRace::GetPlayerFromMobil
          (CTrackManiaRace *this,CTrackManiaRace *param_1,CSceneMobil *param_2)
{
{
  CTrackManiaRace *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if (param_1 != (CTrackManiaRace *)0x0) {
    this_00 = this + 0x24;
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar3,unaff_ESI)
        ;
        if (*(CTrackManiaRace **)(*(int *)(*(int *)pSVar2 + 0x28) + 0x14) == param_1) {
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar3,unaff_EBP);
          return *(CTrackManiaPlayer **)pSVar2;
        }
        pCVar3 = pCVar3 + 1;
      } while (pCVar3 < pCVar1);
    }
  }
  return (CTrackManiaPlayer *)0x0;
}
}

// =================================================
// Function: CTrackManiaRace::GetPlayerOrGhosts
// =================================================
void __thiscall
CTrackManiaRace::GetPlayerOrGhosts
          (CTrackManiaRace *this,CTrackManiaRace *param_1,
          CFastBuffer<struct_CTrackManiaRace::SPlayerOrGhost> *param_2)
{
{
  CTrackManiaRace *this_00;
  CTrackManiaRace *this_01;
  void *this_02;
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SLoadedLight *pSVar5;
  SCasterCat *pSVar6;
  GmFrustumIso4 *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_retaddr;
  void *in_stack_0000000c;
  int in_stack_00000010;
  int in_stack_00000014;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack0000001c;
  void *in_stack_00000020;
  
  this_00 = this + 0x24;
  this_01 = this + 0x520;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_ESI);
  CFastBuffer<class_GmVec3>::SetSizeAtLeast
            (in_stack_0000000c,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(uVar2 + 1 + uVar3),
             unaff_EBP);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(in_stack_0000000c,unaff_EBX);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)this);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar5 = CFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo>::AddNewElem
                         (in_stack_0000000c,
                          (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_retaddr);
      unaff_retaddr = pCVar7;
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar7,(ulong)param_1);
      iVar1 = *(int *)pSVar6;
      *(int *)pSVar5 = iVar1;
      pCVar7 = pCVar7 + 1;
      *(undefined4 *)(pSVar5 + 4) = *(undefined4 *)(*(int *)(iVar1 + 0x28) + 0x14);
      *(undefined4 *)(pSVar5 + 8) = 0;
      in_stack_0000000c = in_stack_00000020;
    } while (pCVar7 < pCVar4);
  }
  this_02 = (void *)(in_stack_00000010 + 0x520);
  pCStack0000001c =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
       CFastBuffer<class_CCrystalFace*>::GetCount
                 (this_02,(CFastBuffer<class_CCrystalFace*> *)unaff_retaddr);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack0000001c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_02,pCVar4,(ulong)param_1);
      iVar1 = *(int *)(*(int *)pSVar6 + 0x20);
      if (iVar1 != 0) {
        param_1 = (CTrackManiaRace *)0x4fc80b;
        pSVar5 = CFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo>::AddNewElem
                           (in_stack_0000000c,
                            (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x4fc80b);
        *(undefined4 *)pSVar5 = 0;
        *(int *)(pSVar5 + 4) = iVar1;
        *(undefined4 *)(pSVar5 + 8) = 0;
      }
      pCVar4 = pCVar4 + 1;
      in_stack_00000010 = in_stack_00000014;
    } while (pCVar4 < pCStack0000001c);
  }
  if ((*(int *)(in_stack_00000010 + 0x538) != 0) &&
     (*(int *)(*(int *)(in_stack_00000010 + 0x538) + 0x20) != 0)) {
    pSVar5 = CFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo>::AddNewElem
                       (in_stack_0000000c,
                        (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)param_1);
    *(undefined4 *)pSVar5 = 0;
    *(undefined4 *)(pSVar5 + 4) = *(undefined4 *)(*(int *)(in_stack_00000010 + 0x538) + 0x20);
    *(uint *)(pSVar5 + 8) = (uint)(*(int *)(in_stack_00000010 + 0x53c) == 0);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRace::GetPlayingPlayer
// =================================================
CTrackManiaPlayer * __thiscall
CTrackManiaRace::GetPlayingPlayer(CTrackManiaRace *this,CTrackManiaRace *param_1)
{
{
  CGamePlayer *pCVar1;
  
  if (*(int *)(this + 0x330) != 0) {
    return *(CTrackManiaPlayer **)(*(int *)(this + 0x330) + 0x238);
  }
  pCVar1 = CGameRace::GetLocalPlayer((CGameRace *)this,(CGameRace *)param_1);
  return (CTrackManiaPlayer *)pCVar1;
}
}

// =================================================
// Function: CTrackManiaRace::GetPlayingPlayerInfo
// =================================================
CTrackManiaPlayerInfo * __thiscall
CTrackManiaRace::GetPlayingPlayerInfo(CTrackManiaRace *this,CTrackManiaRace *param_1)
{
{
  CGamePlayerInfo *pCVar1;
  
  if (*(CTrackManiaPlayerInfo **)(this + 0x330) == (CTrackManiaPlayerInfo *)0x0) {
    pCVar1 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,(CGameRace *)param_1);
    return (CTrackManiaPlayerInfo *)pCVar1;
  }
  return *(CTrackManiaPlayerInfo **)(this + 0x330);
}
}

// =================================================
// Function: CTrackManiaRace::GetTimePenalty
// =================================================
ulong __thiscall
CTrackManiaRace::GetTimePenalty(CTrackManiaRace *this,CTrackManiaRace *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  uVar1 = 0;
  if (param_1 != (CTrackManiaRace *)0x0) {
    uVar1 = (uint)((int)param_1 * 10) / 1000;
  }
  return uVar1;
}
}

// =================================================
// Function: CTrackManiaRace::Ghosts_PreviousRaceGhostsClear
// =================================================
void __thiscall
CTrackManiaRace::Ghosts_PreviousRaceGhostsClear(CTrackManiaRace *this,CTrackManiaRace *param_1)
{
{
  CFastBufferRef<class_CPlugMaterial>::Reset(this + 0x52c,(GmFrustumIso4 *)param_1);
  return;
}
}

// =================================================
// Function: CTrackManiaRace::Ghosts_UpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CTrackManiaRace::Ghosts_UpdateAsync(CTrackManiaRace *this,CTrackManiaRace *param_1)
{
{
  int *piVar1;
  int *piVar2;
  CGamePlayer *pCVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  CGameRace *unaff_EDI;
  float10 fVar6;
  GxColor *pGVar7;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar4 = *(int *)(this + 0x538);
  if (((iVar4 != 0) && (*(int *)(iVar4 + 0x88) != 0)) &&
     (piVar1 = *(int **)(iVar4 + 0x20), piVar1 != (int *)0x0)) {
    pCVar3 = CGameRace::GetLocalPlayer((CGameRace *)this,unaff_EDI);
    piVar2 = *(int **)(*(int *)(pCVar3 + 0x28) + 0x14);
    pGVar7 = (GxColor *)0x0;
    iVar4 = (**(code **)(*piVar1 + 0x80))();
    iVar5 = (**(code **)(*piVar2 + 0x80))(0);
    fStack_14 = *(float *)(iVar5 + 0x24) - *(float *)(iVar4 + 0x24);
    fStack_10 = *(float *)(iVar5 + 0x28) - *(float *)(iVar4 + 0x28);
    fStack_c = *(float *)(iVar5 + 0x2c) - *(float *)(iVar4 + 0x2c);
    fVar6 = (float10)func_0x009c1b40();
    if ((float)fVar6 < _DAT_00b3618c) {
      fStack_8 = ((float)fVar6 * (float)_DAT_00b4fbd0) / (float)_DAT_00b3d380;
    }
    else {
      fStack_8 = (float)_DAT_00b4fbd0;
    }
    fStack_14 = 1.0;
    fStack_10 = 1.0;
    fStack_c = 1.0;
    CPlugShaderGeneric::SetDiffuseSrc
              (*(CPlugShaderGeneric **)(*(int *)(this + 0x538) + 0x88),(CPlugShaderGeneric *)0x0,
               (int)&fStack_14,pGVar7);
    fStack_10 = 0.0;
    fStack_c = 0.0;
    fStack_8 = 0.0;
    CPlugShaderGeneric::SetEmissive
              (*(CPlugShaderGeneric **)(*(int *)(this + 0x538) + 0x88),(CPlugShaderGeneric *)0x1,
               (int)&fStack_10,(GmVec3 *)0x0,unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRace::InitNbLapsAndCheckpoints
// =================================================
void __thiscall
CTrackManiaRace::InitNbLapsAndCheckpoints
          (CTrackManiaRace *this,CTrackManiaRace *param_1,ulong param_2)
{
{
  ulong uVar1;
  CTrackManiaNetworkServerInfo *pCVar2;
  int iVar3;
  uint uVar4;
  CTrackManiaNetwork *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CTrackManiaNetwork *pCVar5;
  
  iVar3 = *(int *)(this + 0xc4);
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar3 + 0x60),unaff_EDI);
  if (param_2 == 0xffffffff) {
    if (*(int *)(iVar3 + 0xf4) != 0) {
      *(undefined4 *)(this + 0xec) = *(undefined4 *)(iVar3 + 0x100);
      iVar3 = (**(code **)(*(int *)this + 0x10))(0x24045000);
      if (iVar3 == 0) {
        pCVar5 = (CTrackManiaNetwork *)0x24056000;
        iVar3 = (**(code **)(*(int *)this + 0x10))();
        if (iVar3 == 0) {
          iVar3 = (**(code **)(*(int *)this + 0x10))(0x24037000);
          if (iVar3 != 0) {
            pCVar2 = CTrackManiaNetwork::GetServerInfo
                               (*(CTrackManiaNetwork **)(*(int *)(this + 0x18) + 300),unaff_ESI);
            if ((*(int *)(pCVar2 + 0x208) != 0) && (*(int *)(this + 0xec) != 0)) {
              pCVar2 = CTrackManiaNetwork::GetServerInfo
                                 (*(CTrackManiaNetwork **)(*(int *)(this + 0x18) + 300),
                                  (CTrackManiaNetwork *)0x47ceb2);
              *(undefined4 *)(this + 0xec) = *(undefined4 *)(pCVar2 + 0x208);
            }
          }
        }
        else {
          pCVar2 = CTrackManiaNetwork::GetServerInfo
                             (*(CTrackManiaNetwork **)(*(int *)(this + 0x18) + 300),pCVar5);
          *(undefined4 *)(this + 0xec) = *(undefined4 *)(pCVar2 + 0x22c);
        }
        goto LAB_0047ceca;
      }
    }
    *(undefined4 *)(this + 0xec) = 1;
  }
  else {
    *(ulong *)(this + 0xec) = param_2;
  }
LAB_0047ceca:
  if (*(int *)(this + 0xec) == 0) {
    *(undefined4 *)(this + 0x2c0) = 0;
    *(ulong *)(this + 0x2c4) = uVar1 + 1;
  }
  else {
    iVar3 = (uVar1 + 1) * *(int *)(this + 0xec);
    *(int *)(this + 0x2c0) = iVar3;
    *(int *)(this + 0x2c4) = iVar3;
  }
  iVar3 = (**(code **)(*(int *)this + 0x10))(0x24044000);
  uVar4 = (-(uint)(iVar3 != 0) & 0xfffffd12) + 1000;
  if (uVar4 < *(uint *)(this + 0x2c4)) {
    *(uint *)(this + 0x2c4) = uVar4;
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRace::InternalPrepareEvent
// =================================================
void __thiscall
CTrackManiaRace::InternalPrepareEvent
          (CTrackManiaRace *this,CTrackManiaRace *param_1,CTrackManiaPlayer *param_2)
{
{
  void *this_00;
  ulong *puVar1;
  CMwTimerAdapter *unaff_ESI;
  
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x344) = 1;
  this_00 = *(void **)(DAT_00d731e0 + 0x14);
  if (this_00 == (void *)0x0) {
    this_00 = (void *)(DAT_00d731e0 + 0xa0);
  }
  puVar1 = CMwTimerAdapter::GetTickTime(this_00,unaff_ESI);
  *(ulong *)(this + 0x274) = *puVar1;
  return;
}
}

// =================================================
// Function: CTrackManiaRace::IsStuntTimeOver
// =================================================
int __thiscall
CTrackManiaRace::IsStuntTimeOver(CTrackManiaRace *this,CTrackManiaRace *param_1,ulong param_2)
{
{
  int iVar1;
  CTrackManiaPlayerInfo *pCVar2;
  CTrackManiaRace *unaff_EBX;
  CTrackManiaRace *unaff_EDI;
  
  pCVar2 = GetPlayingPlayerInfo(this,unaff_EDI);
  if (param_2 <= *(uint *)(pCVar2 + 0x2ac)) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)(this + 0xc4) + 0xb4);
  pCVar2 = GetPlayingPlayerInfo(this,unaff_EBX);
  return (uint)(*(uint *)(iVar1 + 0x24) < param_2 - *(int *)(pCVar2 + 0x2ac));
}
}

// =================================================
// Function: CTrackManiaRace::PrepareCheckpoints
// =================================================
void __thiscall CTrackManiaRace::PrepareCheckpoints(CTrackManiaRace *this,CTrackManiaRace *param_1)
{
{
  int iVar1;
  int iVar2;
  CSceneMobil *this_00;
  CSceneMobil *pCVar3;
  SCasterCat *pSVar4;
  CPlugTree *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CGameCtnBlock *pCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CTrackManiaRace *this_01;
  ECallback unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  GmFrustumIso4 *unaff_EDI;
  int in_stack_00000014;
  int in_stack_00000018;
  GmFrustumIso4 *in_stack_ffffffe8;
  CTrackManiaRace *in_stack_ffffffec;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffff0;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff4;
  CSceneMobil *pCVar11;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0xd4,unaff_EDI);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0xe0,in_stack_ffffffe8);
  if (*(int *)(this + 0x30) != 0) {
    iVar1 = *(int *)(this + 0xc4);
    pCVar3 = (CSceneMobil *)
             CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar1 + 0x54),unaff_ESI);
    pCVar11 = (CSceneMobil *)0x0;
    if (pCVar3 != (CSceneMobil *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x54),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar11,
                            (ulong)unaff_EBP);
        iVar2 = *(int *)(*(int *)(*(int *)pSVar4 + 0x24) + 0x11c);
        if ((iVar2 != 3) &&
           (this_00 = *(CSceneMobil **)(*(int *)pSVar4 + 0x34), pCVar11 = this_00,
           this_00 != (CSceneMobil *)0x0)) {
          pCVar5 = CSceneMobil::GetTree(this_00,(SVolatileTreePointer *)0x47ccd1);
          *(uint *)(pCVar5 + 0x9c) = *(uint *)(pCVar5 + 0x9c) | 0x80;
          unaff_EBX = *(ECallback *)(this + 0x51c);
          unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x2;
          CHmsItem::CallbackSet
                    (*(CHmsItem **)(this_00 + 0x28),(CHmsItem *)0x2,unaff_EBX,
                     (CCallback *)in_stack_ffffffec);
          if (iVar2 == 1) {
LAB_0047cd01:
            this_01 = this + 0xe0;
          }
          else {
            if (iVar2 != 2) {
              if (iVar2 != 4) goto LAB_0047cd11;
              goto LAB_0047cd01;
            }
            this_01 = this + 0xd4;
          }
          unaff_EBX = 0x47cd11;
          in_stack_ffffffec = (CTrackManiaRace *)register0x00000010;
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (this_01,(TiXmlAttributeSet *)&stack0x00000000,
                     (TiXmlAttribute *)in_stack_fffffff0);
        }
LAB_0047cd11:
        pCVar11 = pCVar11 + 1;
      } while (pCVar11 < pCVar3);
    }
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       ((void *)(*(int *)(this + 0xc4) + 0x60),unaff_EBP);
    pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           ((void *)(*(int *)(this + 0xc4) + 0x60),pCVar9,unaff_EBX);
        iVar1 = *(int *)pSVar4;
        pCVar10 = pCVar9;
        do {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0xd4,pCVar10,(ulong)in_stack_ffffffec);
          in_stack_ffffffec = *(CTrackManiaRace **)pSVar4;
          unaff_EBX = 0x47cd77;
          pCVar7 = GetBlockFromCheckpointMobil
                             (this,in_stack_ffffffec,(CSceneMobil *)in_stack_fffffff0);
          if (((*(int *)(pCVar7 + 0x48) == iVar1) && (*(int *)(pCVar7 + 0x4c) == in_stack_00000014))
             && (*(int *)(pCVar7 + 0x50) == in_stack_00000018)) break;
          pCVar10 = pCVar10 + 1;
          in_stack_fffffff0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x47cd9e;
          pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xd4,in_stack_fffffff4);
        } while (pCVar10 < pCVar8);
        if (pCVar9 != pCVar10) {
          in_stack_fffffff0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x47cdb3;
          pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xd4,in_stack_fffffff4);
          if (pCVar10 < pCVar8) {
            in_stack_ffffffec = (CTrackManiaRace *)0x47cdc0;
            in_stack_fffffff0 = pCVar9;
            CFastBuffer<class_CGameFid*>::SwapElemsAt
                      (this + 0xd4,(CFastBuffer<struct_CVisionViewport::SDelayedToSort64b> *)pCVar9,
                       (ulong)pCVar10,(ulong)pCVar11);
            in_stack_fffffff4 = (CFastBuffer<class_CCrystalFace*> *)pCVar10;
          }
        }
        pCVar9 = pCVar9 + 1;
      } while (pCVar9 < pCVar6);
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRace::StopReplayRecordAndKeepCopy
// =================================================
void __thiscall
CTrackManiaRace::StopReplayRecordAndKeepCopy
          (CTrackManiaRace *this,CTrackManiaRace *param_1,int param_2)
{
{
  CGamePlayerInfo *pCVar1;
  CGameCtnReplayRecord *pCVar2;
  CGameCtnGhost *this_00;
  CGameCtnGhost *pCVar3;
  int iVar4;
  CSystemArchiveNod *this_01;
  CMwNod *unaff_EBX;
  uchar unaff_DI;
  CFastString *in_stack_ffffffc0;
  SHeaderCommunity *pSVar5;
  undefined1 *puVar6;
  CGameCtnReplayRecord *in_stack_ffffffcc;
  CGameCtnReplayRecord *this_02;
  CGameCtnReplayRecord *local_14;
  int *local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &DAT_00a88268;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((*(int *)(this + 0xb0) != 0) && (*(int *)(*(int *)(this + 0xb0) + 0x2c) != -1)) {
    pCVar1 = CGameRace::GetLocalPlayerInfo
                       ((CGameRace *)this,(CGameRace *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
    pCVar2 = (CGameCtnReplayRecord *)(uint)(byte)pCVar1[0x24];
    this_00 = CGameCtnReplayRecord::GhostGetByPlayerUid(local_14,pCVar2,unaff_DI);
    this_02 = (CGameCtnReplayRecord *)0x480746;
    (**(code **)(*local_10 + 0x7c))();
    if (this_00 != (CGameCtnGhost *)0x0) {
      puVar6 = &stack0xffffffe0;
      pSVar5 = (SHeaderCommunity *)0x48075b;
      pCVar3 = (CGameCtnGhost *)(**(code **)(*(int *)this + 0xa4))();
      unaff_EBX = (CMwNod *)0x0;
      CGameCtnGhost::SetContextSettings(this_00,pCVar3,in_stack_ffffffc0);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xffffffd8,pSVar5);
      if (local_c == (void *)0x0) {
        CGameCtnGhost::SetRaceTime
                  (this_00,*(CGameCtnGhost **)(pCVar1 + 0x2b0),*(ulong *)(pCVar1 + 0x2c4),
                   *(ulong *)(pCVar1 + 0x2d4),(ulong)puVar6);
      }
      else {
        CGameCtnGhost::SetRaceTime(this_00,(CGameCtnGhost *)0xffffffff,0xffffffff,0,(ulong)puVar6);
        *(undefined4 *)(this_00 + 0x10c) = 0;
      }
    }
    iVar4 = CGameCtnReplayRecord::IsAlmostEmpty(this_02,in_stack_ffffffcc);
    if (iVar4 == 0) {
      CSystemArchiveNod::Duplicate(this_01,(CPlugVisualVertexs *)&stack0xffffffe0);
      if (unaff_EBX != *(CMwNod **)(this + 0xb4)) {
        if (unaff_EBX != (CMwNod *)0x0) {
          CMwNod::MwAddRef(unaff_EBX,(CMwNod *)pCVar2);
        }
        if (*(CMwNod **)(this + 0xb4) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(this + 0xb4),(CMwNod *)pCVar2);
        }
        *(CMwNod **)(this + 0xb4) = unaff_EBX;
      }
    }
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CTrackManiaRace::SwitchToRace
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaRace::SwitchToRace
          (CTrackManiaRace *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3)
{
{
  CTrackManiaRace *this_00;
  CTrackManiaPlayerInfo *this_01;
  CGameNetwork *this_02;
  code *pcVar1;
  CGameRace *pCVar2;
  CTrackMania *pCVar3;
  CTrackManiaReplayRecord *this_03;
  CGameRace *extraout_EAX;
  CGameRace *pCVar4;
  CGameCtnBlock *pCVar5;
  CGameCtnBlock *pCVar6;
  CGameCtnBlock *this_04;
  EBlockType EVar7;
  CGameCtnFieldUnit *pCVar8;
  CGameCtnBlock *pCVar9;
  CGameCtnBlockUnitInfo *pCVar10;
  GmMat3 *pGVar11;
  SCasterCat *pSVar12;
  CGameCtnGhost *pCVar13;
  int iVar14;
  CGamePlayer *pCVar15;
  CMotionManager *pCVar16;
  CGamePlayerInfo *pCVar17;
  int iVar18;
  GmMat43 *unaff_EBX;
  CTrackManiaRace *unaff_EBP;
  CGameCtnReplayRecord *unaff_ESI;
  CTrackManiaReplayRecord *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar19;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar20;
  CFastBuffer<class_CCrystalFace*> *pCVar21;
  undefined3 in_stack_00000009;
  STmRaceLowFps *in_stack_00000010;
  CGameRace *in_stack_0000001c;
  CGameCtnBlock *in_stack_00000020;
  CGameCtnBlock *in_stack_0000002c;
  ulong uStack00000038;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000040;
  CGameRace *in_stack_ffffffa4;
  CGameRace *in_stack_ffffffa8;
  ulong in_stack_ffffffac;
  ulong in_stack_ffffffb0;
  CGameRace *in_stack_ffffffb4;
  CTrackManiaPlayer *pCVar22;
  CGameRace *pCVar23;
  CGameCtnGhost *pCVar24;
  CGameCtnGhost *pCVar25;
  CGameRace *pCVar26;
  STmRaceLowFps *pSVar27;
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *pCVar28;
  CGameRace *pCVar29;
  ulong uVar30;
  CGameCtnBlock *pCVar31;
  CGameCtnBlock *pCVar32;
  CGameCtnBlock *in_stack_ffffffe8;
  CGameCtnBlock *in_stack_ffffffec;
  CGameCtnBlock *in_stack_fffffff0;
  CGameCtnBlock *pCVar33;
  CMwCmdBufferCore *pCVar34;
  CGameCtnBlock *pCVar35;
  
  pCVar2 = param_1;
  pCVar35 = (CGameCtnBlock *)0xffffffff;
  pCVar33 = (CGameCtnBlock *)&LAB_00a8820b;
  pCVar3 = (CTrackMania *)(DAT_00cca150 ^ (uint)&stack0xffffffd8);
  ExceptionList = &stack0xfffffff4;
  pCVar22 = (CTrackManiaPlayer *)0x47effe;
  pCVar24 = (CGameCtnGhost *)_param_2;
  pSVar27 = in_stack_00000010;
  CGameRace::SwitchToRace((CGameRace *)this,param_1,param_2,param_3);
  pCVar26 = (CGameRace *)0x47f008;
  STmRaceLowFps::StopAndReset(&DAT_00d564c8,pSVar27);
  CTrackMania::UpdateWaterMap(*(CTrackMania **)(this + 0x18),pCVar3);
  pCVar28 = (CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *)0x47f017;
  this_03 = operator_new(0x4c);
  pCVar21 = (CFastBuffer<class_CCrystalFace*> *)0x0;
  if (this_03 == (CTrackManiaReplayRecord *)0x0) {
    pCVar4 = (CGameRace *)0x0;
    pCVar23 = param_1;
  }
  else {
    CTrackManiaReplayRecord::CTrackManiaReplayRecord(this_03,unaff_EDI);
    pCVar4 = extraout_EAX;
    pCVar23 = param_1;
  }
  param_1 = (CGameRace *)0xffffffff;
  pCVar29 = (CGameRace *)0x47f043;
  CGameRace::SetReplayRecord((CGameRace *)this,pCVar4,unaff_ESI);
  PrepareCheckpoints(this,unaff_EBP);
  pCVar6 = (CGameCtnBlock *)(this + 0x28c);
  GmIso4::SetIdentity(pCVar6,unaff_EBX);
  if ((*(int *)(*(int *)(this + 0x18) + 0x418) == 4) ||
     (*(int *)(*(int *)(this + 0x18) + 0x418) == 5)) {
    pCVar31 = in_stack_00000020;
    pCVar6 = CGameCtnChallenge::GetBlockFromPlayField
                       (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar2,
                        SUB41(in_stack_0000001c,0));
    pCVar5 = pCVar35;
    while (pCVar6 == (CGameCtnBlock *)0x0) {
      in_stack_0000001c = in_stack_0000001c + -1;
      pCVar6 = CGameCtnChallenge::GetBlockFromPlayField
                         (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar2,
                          SUB41(in_stack_0000001c,0));
    }
    pCVar29 = (CGameRace *)0x47f0ea;
    pCVar4 = pCVar2;
    this_04 = CGameCtnChallenge::GetBlockFromPlayField
                        (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar2,
                         SUB41(in_stack_0000001c,0));
    EVar7 = CGameCtnBlock::GetType(this_04,in_stack_00000020);
    if (((EVar7 == 0) ||
        (EVar7 = CGameCtnBlock::GetType(pCVar33,pCVar31), pCVar9 = in_stack_fffffff0, EVar7 == 1))
       && (in_stack_0000001c = in_stack_0000001c + 1, pCVar9 = in_stack_fffffff0,
          in_stack_0000001c < *(CGameRace **)(*(int *)(this + 0xc4) + 0xac))) {
      while( true ) {
        pCVar29 = (CGameRace *)0x47f138;
        pCVar4 = pCVar2;
        pCVar8 = CGameCtnChallenge::GetFieldUnit
                           (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar2,
                            SUB41(in_stack_0000001c,0));
        pCVar9 = in_stack_fffffff0;
        if (pCVar8 == (CGameCtnFieldUnit *)0x0) break;
        pCVar28 = (CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *)0x47f154;
        pCVar29 = pCVar2;
        pCVar4 = in_stack_0000001c;
        pCVar9 = CGameCtnChallenge::GetBlockFromPlayField
                           (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar2,
                            SUB41(in_stack_0000001c,0));
        if (((pCVar9 != (CGameCtnBlock *)0x0) && ((*(uint *)(pCVar9 + 0x60) & 0x1000) != 0)) ||
           (in_stack_0000001c = in_stack_0000001c + 1, pCVar9 = in_stack_fffffff0,
           *(CGameRace **)(*(int *)(this + 0xc4) + 0xac) <= in_stack_0000001c)) break;
      }
    }
    if ((*(uint *)(pCVar33 + 0x60) & 0x14000) != 0) {
      do {
        do {
          pCVar29 = (CGameRace *)0x47f1a1;
          pCVar4 = pCVar2;
          pCVar10 = CGameCtnChallenge::GetBlockUnitInfoFromPlayField
                              (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar2,
                               SUB41(in_stack_0000001c,0));
          if (((*(uint *)(this_04 + 0x60) & 0x4000) == 0) &&
             ((((*(uint *)(this_04 + 0x60) & 0x10000) == 0 || (*(int *)(pCVar10 + 0x40) == 0)) ||
              (*(int *)(*(int *)(pCVar10 + 0x40) + 0xe0) == 0)))) goto LAB_0047f24a;
          in_stack_0000001c = in_stack_0000001c + 1;
          if (*(CGameRace **)(*(CGameCtnChallenge **)(this + 0xc4) + 0xac) <= in_stack_0000001c)
          goto LAB_0047f24a;
          pCVar28 = (CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *)0x47f1f3;
          pCVar9 = CGameCtnChallenge::GetBlockFromPlayField
                             (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar2,
                              SUB41(in_stack_0000001c,0));
        } while (pCVar9 != (CGameCtnBlock *)0x0);
        pCVar26 = (CGameRace *)0x47f21f;
        pCVar28 = (CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *)param_3;
        in_stack_ffffffec =
             CGameCtnChallenge::GetBlockFromPlayField
                       (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)param_3,
                        SUB41(in_stack_00000010,0));
      } while (in_stack_ffffffec != (CGameCtnBlock *)0x0);
      goto LAB_0047f22b;
    }
LAB_0047f24a:
    uVar30 = 0x47f25a;
    iVar18 = CGameCtnChallenge::IsStartBlock
                       (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar33,pCVar31);
    pCVar35 = pCVar5;
    if (((iVar18 != 0) ||
        (iVar18 = CGameCtnChallenge::IsStartFinishBlock
                            (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar5,
                             in_stack_ffffffe8), iVar18 != 0)) ||
       (iVar18 = CGameCtnChallenge::IsCheckpointBlock
                           (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)pCVar5,
                            in_stack_ffffffec), pGVar11 = (GmMat3 *)in_stack_0000002c, iVar18 != 0))
    {
      pGVar11 = *(GmMat3 **)(pCVar5 + 0x54);
    }
    switch(pGVar11) {
    case (GmMat3 *)0x0:
      in_stack_0000002c = (CGameCtnBlock *)0x0;
      break;
    case (GmMat3 *)0x1:
      in_stack_0000002c = (CGameCtnBlock *)0x3;
      break;
    case (GmMat3 *)0x2:
      in_stack_0000002c = (CGameCtnBlock *)0x2;
      break;
    case (GmMat3 *)0x3:
      in_stack_0000002c = (CGameCtnBlock *)0x1;
    }
    pCVar31 = (CGameCtnBlock *)(this + 0x28c);
    pCVar6 = (CGameCtnBlock *)0x47f2c6;
    pCVar32 = pCVar31;
    CGameCtnBlock::GetSpawnLoc(pCVar5,pCVar31,(GmIso4 *)0x0,0,(ulong)pCVar9);
    GmMat3::SetRotateQuarterY(pCVar31,(GmMat3 *)in_stack_0000002c,(ulong)this_04);
  }
  else {
    pCVar31 = (CGameCtnBlock *)0x0;
    pCVar5 = CGameCtnChallenge::GetStartLine
                       (*(CGameCtnChallenge **)(this + 0xc4),(CGameCtnChallenge *)0x0,
                        (ulong)in_stack_ffffffe8);
    if (pCVar5 == (CGameCtnBlock *)0x0) {
LAB_0047f22b:
      CGameRace::SetStatus((CGameRace *)this,(CGameRace *)&DAT_0000000f,(EStatus)pCVar31);
      ExceptionList = _param_2;
      return;
    }
    pCVar32 = (CGameCtnBlock *)0x0;
    uVar30 = 0x47f088;
    CGameCtnBlock::GetSpawnLoc(pCVar5,pCVar6,(GmIso4 *)0x0,0,(ulong)in_stack_ffffffec);
    in_stack_0000002c = in_stack_fffffff0;
  }
  this_00 = this + 0x24;
  uStack00000038 =
       CFastBuffer<class_CCrystalFace*>::GetCount
                 (this_00,(CFastBuffer<class_CCrystalFace*> *)pCVar33);
  pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uStack00000038 != 0) {
    do {
      pSVar12 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          (this_00,pCVar19,(ulong)pCVar35);
      pCVar35 = (CGameCtnBlock *)0x1;
      CTrackManiaPlayerInfo::SetSpawnLoc
                (*(CTrackManiaPlayerInfo **)(*(int *)pSVar12 + 0x1c),
                 (CTrackManiaPlayerInfo *)(this + 0x28c),(GmIso4 *)0x1,(int)pCVar21);
      pCVar19 = pCVar19 + 1;
    } while (pCVar19 < in_stack_00000040);
  }
  pCVar34 = (CMwCmdBufferCore *)0xffffffff;
  InitNbLapsAndCheckpoints(this,(CTrackManiaRace *)0xffffffff,(ulong)pCVar35);
  pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
            CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar21);
  pCVar20 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar19 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar12 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          (this_00,pCVar20,(ulong)param_1);
      this_01 = *(CTrackManiaPlayerInfo **)(*(int *)pSVar12 + 0x1c);
      param_1 = (CGameRace *)0x47f33a;
      pCVar13 = (CGameCtnGhost *)
                CFastBuffer<class_CCrystalFace*>::GetCount(this_01 + 0x2f8,_param_2);
      pCVar25 = *(CGameCtnGhost **)(this + 0x2c4);
      if (pCVar13 != pCVar25) {
        param_1 = (CGameRace *)0x47f34c;
        CTrackManiaPlayerInfo::SetNbCheckpoints(this_01,pCVar25,param_3);
        _param_2 = (CFastBuffer<class_CCrystalFace*> *)pCVar25;
      }
      pCVar20 = pCVar20 + 1;
    } while (pCVar20 < pCVar19);
  }
  iVar18 = *(int *)(*(int *)(this + 0x18) + 0x78);
  if (*(int *)(iVar18 + 0x20) == 0) {
    iVar18 = *(int *)(iVar18 + 0x24);
  }
  else {
    iVar18 = *(int *)(iVar18 + 0x28);
  }
  this_02 = *(CGameNetwork **)(*(int *)(this + 0x18) + 300);
  if (((this_02 == (CGameNetwork *)0x0) ||
      (iVar14 = CGameNetwork::IsConnected(this_02,(CCrystalVertex *)param_1), iVar14 == 0)) ||
     (*(int *)(*(int *)(*(int *)(this + 0x18) + 300) + 0x1d4) != 0)) {
    iVar14 = 0x3f800000;
    pCVar34 = (CMwCmdBufferCore *)0x1;
  }
  else {
    param_1 = (CGameRace *)0x3f800000;
    iVar14 = 0;
  }
  CMwCmdBufferCore::StartSimulation(DAT_00d731e0,pCVar34,0,iVar14,(float)param_1);
  CInputPort::ClearInputs(*(CInputPort **)(this + 0x20),(CInputPort *)0x1,(int)_param_2);
  (**(code **)(**(int **)(this + 0x20) + 0x80))();
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x288) = 0;
  if (*(int **)(this + 0x518) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x518) + 0xa4))();
  }
  pcVar1 = *(code **)(*(int *)this + 0x168);
  *(undefined4 *)(this + 0x33c) = 0;
  *(undefined4 *)(this + 0x340) = 0;
  (*pcVar1)();
  pCVar15 = CGameRace::GetLocalPlayer((CGameRace *)this,in_stack_ffffffa4);
  iVar14 = *(int *)(pCVar15 + 0x28);
  pCVar15 = CGameRace::GetLocalPlayer((CGameRace *)this,in_stack_ffffffa8);
  CGamePlayerCameraSet::PlayerGameMobilIdSet
            (*(CGamePlayerCameraSet **)(pCVar15 + 0x20),*(CGamePlayerCameraSet **)(iVar14 + 0x18),
             in_stack_ffffffac);
  pCVar16 = CScene::GetManager(*(CScene **)(*(int *)(this + 0x30) + 0x14),(CScene *)0x8059000,
                               in_stack_ffffffb0);
  if (pCVar16 != (CMotionManager *)0x0) {
    (**(code **)(*(int *)pCVar16 + 0x8c))(*(undefined4 *)(*(int *)(this + 0x18) + 100));
  }
  *(undefined4 *)(this + 0x1f0) = 0;
  if ((*(int *)(this + 0x34) != 0) && (*(int *)(*(int *)(this + 0xc4) + 0x90) != 0)) {
    iVar14 = *(int *)(*(int *)(*(int *)(this + 0x34) + 0x74) + 0x30);
    *(uint *)(iVar14 + 0x174) = (uint)(*(int *)(iVar18 + 0x78) != 0);
    pCVar26 = *(CGameRace **)(*(int *)(*(int *)(this + 0xc4) + 0x90) + 0x7c);
    if (*(int *)(iVar18 + 0x78) == 2) {
      in_stack_0000002c = (CGameCtnBlock *)(float)*(int *)(iVar18 + 0x80);
      if (*(int *)(iVar18 + 0x80) < 0) {
        in_stack_0000002c = (CGameCtnBlock *)((float)in_stack_0000002c + _DAT_00c418d0);
      }
    }
    else {
      if (*(int *)(iVar18 + 0x78) != 1) goto LAB_0047f5b0;
      iVar18 = *(int *)(iVar18 + 0x7c);
      pCVar25 = _DAT_00b2f704;
      pCVar33 = _DAT_00b36acc;
      pCVar35 = _DAT_00b3d268;
      if (((iVar18 == 0) ||
          (pCVar25 = _DAT_00b3d270, pCVar33 = _DAT_00b3d274, pCVar35 = _DAT_00b3d26c, iVar18 == 1))
         || (pCVar25 = _DAT_00b3d27c, pCVar33 = _DAT_00b3d280, pCVar35 = _DAT_00b3d278, iVar18 == 2)
         ) {
        pCVar32 = pCVar35;
        pCVar24 = pCVar25;
        in_stack_0000002c = pCVar33;
      }
      pCVar28 = (CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *)
                (float)*(int *)(*(int *)(this + 0x18) + 0x1ac);
      if (*(int *)(*(int *)(this + 0x18) + 0x1ac) < 0) {
        pCVar28 = (CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *)
                  ((float)pCVar28 + _DAT_00c418d0);
      }
      if ((float)pCVar32 < (float)pCVar28 == ((float)pCVar32 == (float)pCVar28)) {
        if ((float)pCVar28 <= (float)pCVar24) {
          *(undefined4 *)(iVar14 + 0x174) = 0;
          goto LAB_0047f5b0;
        }
        in_stack_0000002c =
             (CGameCtnBlock *)
             ((float)in_stack_0000002c +
             (((float)_DAT_00b3d260 - (float)in_stack_0000002c) * ((float)pCVar32 - (float)pCVar28))
             / (float)pCVar32);
        pCVar32 = (CGameCtnBlock *)((float)pCVar32 - (float)pCVar28);
      }
    }
    *(float *)(iVar14 + 0x178) = (float)in_stack_0000002c * (float)pCVar26;
  }
LAB_0047f5b0:
  pCVar17 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_ffffffb4);
  if (((pCVar17 != (CGamePlayerInfo *)0x0) &&
      (pCVar17 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,pCVar23),
      *(int *)(pCVar17 + 0x70) == 0)) && (*(int *)(pCVar17 + 0x74) == 0)) {
    pCVar15 = CGameRace::GetLocalPlayer((CGameRace *)this,pCVar23);
    UnassignCamFreePrimaryActionKeys(this,(CTrackManiaRace *)pCVar15,pCVar22);
  }
  *(undefined4 *)(this + 0xcc) = 1;
  CGameRace::MediaClipStartCutScene((CGameRace *)this,(CGameRace *)0x0,0,0.0,(int)pCVar23);
  UpdateCams(this,(CGameCtnMediaClipViewer *)pCVar24);
  CGameRace::MediaClipStop((CGameRace *)this,pCVar26);
  if (((*(int **)(this + 0x510) != (int *)0x0) &&
      (iVar18 = (**(code **)(**(int **)(this + 0x510) + 0x10))(0x10005000), iVar18 != 0)) &&
     (0 < *(int *)(*(int *)(*(int *)(this + 0x18) + 0x68) + 0x14))) {
    *(undefined4 *)(*(int *)(this + 0x510) + 0x78) = 0;
    *(undefined4 *)(*(int *)(this + 0x510) + 0x7c) = 0;
    *(undefined4 *)(*(int *)(this + 0x510) + 0x80) = 0;
    CAudioSound::Play(*(CAudioSound **)(this + 0x510),_DAT_00b2c060,(EPlugVideoTimer)pCVar28,
                      (int)pCVar29,(ulong)pCVar4);
  }
  *(undefined4 *)(this + 0x338) = 0;
  *(undefined4 *)(this + 0x33c) = 0;
  *(undefined4 *)(this + 0x340) = 0;
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel
            (this + 0x3b0,pCVar28);
  *(undefined4 *)(this + 0x3ac) = 1;
  CMwStatsValue::SetSize((CMwStatsValue *)(this + 0x344),(CMwStatsValue *)0x0,(ulong)pCVar29);
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel
            (this + 0x430,
             (CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *)pCVar4);
  *(undefined4 *)(this + 0x42c) = 1;
  CMwStatsValue::SetSize((CMwStatsValue *)(this + 0x3c4),(CMwStatsValue *)0x0,uVar30);
  *(undefined4 *)(this + 0x4c8) = 0;
  *(undefined4 *)(this + 0x4c4) = 0;
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel
            (this + 0x4b0,
             (CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *)pCVar6);
  *(undefined4 *)(this + 0x4ac) = 1;
  CMwStatsValue::SetSize((CMwStatsValue *)(this + 0x444),(CMwStatsValue *)0x0,(ulong)pCVar32);
  *(undefined4 *)(this + 0x4cc) = 0;
  *(undefined4 *)(this + 0x4d0) = 0;
  *(undefined4 *)(this + 0x460) = 0;
  *(undefined4 *)(this + 0x4d4) = 0;
  *(undefined4 *)(this + 0x45c) = 0;
  *(undefined4 *)(this + 0x4d8) = 0;
  *(undefined4 *)(this + 0x458) = 0;
  *(undefined4 *)(this + 0x4dc) = 0;
  *(undefined4 *)(this + 0x4e8) = 0xfffffff6;
  *(undefined4 *)(this + 0x4e0) = 0;
  *(undefined4 *)(this + 0x4ec) = 0xffffffff;
  *(undefined4 *)(this + 0x4f0) = 0;
  *(undefined4 *)(this + 0x4f4) = 0;
  *(undefined4 *)(this + 0x4f8) = 0;
  *(undefined4 *)(this + 0x4fc) = 0;
  *(undefined4 *)(*(int *)(*(int *)(this + 0x18) + 0x178) + 0x38) = 0;
  ExceptionList = (void *)0x1;
  return;
}
}

// =================================================
// Function: CTrackManiaRace::UnassignCamFreePrimaryActionKeys
// =================================================
void __thiscall
CTrackManiaRace::UnassignCamFreePrimaryActionKeys
          (CTrackManiaRace *this,CTrackManiaRace *param_1,CTrackManiaPlayer *param_2)
{
{
  int iVar1;
  CGameControlCamera *this_00;
  ulong uVar2;
  SInputActionDesc *pSVar3;
  
  if (((param_1 != (CTrackManiaRace *)0x0) && (*(int *)(param_1 + 0x20) != 0)) &&
     (*(int **)(param_1 + 0x24) != (int *)0x0)) {
    uVar2 = 0x24032000;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x24) + 0x10))();
    if (iVar1 != 0) {
      this_00 = CGamePlayerCameraSet::CamPtrGet
                          (*(CGamePlayerCameraSet **)(param_1 + 0x20),
                           *(CGamePlayerCameraSet **)(*(int *)(param_1 + 0x24) + 0x38),uVar2);
      if (this_00 != (CGameControlCamera *)0x0) {
        pSVar3 = (SInputActionDesc *)0x306d000;
        iVar1 = (**(code **)(*(int *)this_00 + 0x10))();
        if (iVar1 != 0) {
          CGameControlCameraFree::SetKeysAction
                    ((CGameControlCameraFree *)this_00,(CGameControlCameraFree *)0x0,
                     (SInputActionDesc *)0x0,(SInputActionDesc *)0x0,(SInputActionDesc *)0x0,
                     (SInputActionDesc *)PTR_DAT_00cd3fac,(SInputActionDesc *)PTR_DAT_00cd3fb0,
                     (SInputActionDesc *)0x0,pSVar3);
        }
      }
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRace::UpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CTrackManiaRace::UpdateAsync(CTrackManiaRace *this,CInputPortDx8 *param_1)
{
{
  int *piVar1;
  SInputActionDesc *pSVar2;
  CGameRace *pCVar3;
  CSceneMobil *pCVar4;
  CMwId *pCVar5;
  CGamePlayerInfo *pCVar6;
  CTrackManiaPlayerInfo *pCVar7;
  CTrackManiaPlayer *pCVar8;
  CTrackManiaRace *pCVar9;
  int iVar10;
  ulong uVar11;
  CPlugMaterial *this_00;
  CTrackManiaNetworkServerInfo *pCVar12;
  CGameRace *pCVar13;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CPlugTree *pCVar15;
  SCasterCat *pSVar16;
  SPlugFaceCull *pSVar17;
  float *pfVar18;
  CSceneFx *pCVar19;
  SInputEvent *pSVar20;
  CGamePlayer *pCVar21;
  CGameControlCamera *pCVar22;
  CPlugAudio *this_01;
  uint uVar23;
  float fVar24;
  undefined *puVar25;
  CGameRace *unaff_EBX;
  int iVar26;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar27;
  CInputPortDx8 *unaff_EBP;
  CTrackManiaRace *unaff_ESI;
  CPlugAudio *unaff_EDI;
  STmRaceLowFps *pSVar28;
  ushort in_FPUControlWord;
  float10 fVar29;
  float10 fVar30;
  void *in_stack_00000018;
  CTrackManiaRace *pCVar31;
  code *pcVar32;
  CPlugVolumeProjector *pCVar33;
  GmFrustumIso4 *pGVar34;
  TiXmlAttribute *pTVar35;
  CFastBuffer<class_GxVertex2> *pCVar36;
  code *in_stack_ffffff74;
  code *pcVar37;
  GmIso4 *pGVar38;
  CTrackManiaRace *in_stack_ffffff78;
  CTrackManiaRace *pCVar39;
  CFastBuffer<class_CCrystalFace*> *pCVar40;
  ulong uVar41;
  CTrackManiaRace *in_stack_ffffff7c;
  CFastBuffer<class_CCrystalFace*> *pCVar42;
  SVolatileTreePointer *pSVar43;
  float fVar44;
  GmFrustumIso4 *pGVar45;
  CPlugFileVideo *in_stack_ffffff84;
  undefined4 in_stack_ffffff88;
  undefined2 uVar47;
  STmRaceLowFps *pSVar46;
  CTrackManiaRace *pCVar48;
  SInputActionDesc *pSVar49;
  SInputActionDesc *pSVar50;
  CFastBuffer<class_GxVertex2> *in_stack_ffffffa0;
  int iStack_5c;
  SPlugFaceCull *pSStack_58;
  float fStack_54;
  CFastBuffer<class_GxVertex2> *pCStack_48;
  float fStack_44;
  float afStack_40 [4];
  undefined1 auStack_30 [4];
  SPlugFaceCull aSStack_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uVar47 = (undefined2)((uint)in_stack_ffffff88 >> 0x10);
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a8823e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CGameRace::UpdateAsync((CGameRace *)this,(CInputPortDx8 *)(DAT_00cca150 ^ (uint)&stack0xffffff64))
  ;
  this_01 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_01 == (CPlugAudio *)0x0) {
    this_01 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar5 = CPlugAudio::MwGetId(this_01,unaff_EDI);
  pCVar31 = *(CTrackManiaRace **)pCVar5;
  pCVar42 = *(CFastBuffer<class_CCrystalFace*> **)(DAT_00d731e0 + 0x80);
  *(float *)(this + 0x278) =
       (float)_DAT_00b30a10 / (float)pCVar42 + *(float *)(this + 0x278) * (float)_DAT_00b362a8;
  UpdateCountDownIndex(this,unaff_ESI);
  STmRaceLowFps::UpdateAsync(&DAT_00d564c8,unaff_EBP);
  pCVar6 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,unaff_EBX);
  pSVar50 = *(SInputActionDesc **)(pCVar6 + 0x238);
  fVar29 = (float10)(**(code **)(**(int **)(*(int *)(pSVar50 + 0x28) + 0x14) + 0x134))();
  pCVar9 = (CTrackManiaRace *)(longlong)ROUND(ABS((float)fVar29));
  *(CTrackManiaRace **)(pCVar6 + 0x340) = pCVar9;
  if ((*(int *)(this + 0x270) == 0) || (999 < (uint)((int)pCVar31 - *(int *)(this + 0x270)))) {
    pCVar9 = (CTrackManiaRace *)(longlong)ROUND(*(float *)(this + 0x264) / (float)_DAT_00b3d2e0);
    *(CTrackManiaRace **)(this + 0x268) = pCVar9;
    *(undefined4 *)(this + 0x26c) = *(undefined4 *)(pCVar6 + 0x340);
  }
  pCVar48 = (CTrackManiaRace *)(in_FPUControlWord | 0xc00);
  pSVar46 = (STmRaceLowFps *)CONCAT22(uVar47,in_FPUControlWord);
  if ((*(int *)(pCVar6 + 0x70) == 0) && (*(int *)(pCVar6 + 0x74) == 0)) {
    pCVar7 = GetPlayingPlayerInfo(this,(CTrackManiaRace *)in_stack_ffffff74);
    if (*(CTrackManiaRace **)(pCVar7 + 0x2ac) < pCVar31) {
      pCVar8 = GetPlayingPlayer(this,in_stack_ffffff78);
      piVar1 = *(int **)(*(int *)(pCVar8 + 0x28) + 0x14);
      pCVar9 = pCVar31 + -*(int *)(this + 0x110);
      pCVar39 = (CTrackManiaRace *)0xa02b000;
      iVar10 = (**(code **)(*piVar1 + 0x10))();
      if ((((iVar10 != 0) && (piVar1[0x10c] == 0)) && (piVar1[0x10d] == 0)) && (piVar1[0x111] == 0))
      {
        *(SInputActionDesc **)(this + 0xfc) = pSVar50 + *(int *)(this + 0xfc);
      }
      uVar11 = GetCurrentStandardTime(this,pCVar39);
      if (2999 < uVar11) {
        fVar29 = (float10)(**(code **)(*piVar1 + 0x134))();
        fVar30 = (float10)(int)pCVar9;
        if ((int)pCVar9 < 0) {
          fVar30 = fVar30 + (float10)_DAT_00c418d0;
        }
        *(float *)(this + 0x104) = (float)(fVar30 * fVar29 + (float10)*(float *)(this + 0x104));
      }
      fVar29 = (float10)(**(code **)(*piVar1 + 0x134))();
      if ((float10)_DAT_00b3d2d8 <= fVar29) {
        *(CTrackManiaRace **)(this + 0x108) = pCVar9 + *(int *)(this + 0x108);
      }
      in_stack_ffffff78 = (CTrackManiaRace *)0x47fa23;
      fVar29 = (float10)(**(code **)(*piVar1 + 0x134))();
      if ((float10)_DAT_00b3d2d0 <= fVar29) {
        *(SInputActionDesc **)(this + 0x10c) = pSVar50 + *(int *)(this + 0x10c);
      }
      *(CTrackManiaRace **)(this + 0x110) = pCVar31;
    }
    if (((*(int *)(pCVar6 + 0x2dc) != 0) &&
        (iVar10 = CTrackMania::IsInStuntsMode
                            (*(CTrackMania **)(this + 0x18),(CTrackMania *)in_stack_ffffff78),
        iVar10 != 0)) &&
       (in_stack_ffffff78 = pCVar31, iVar10 = IsStuntTimeOver(this,pCVar31,(ulong)in_stack_ffffff7c)
       , iVar10 != 0)) {
      in_stack_ffffff7c = (CTrackManiaRace *)0x0;
      if (*(int *)(pCVar6 + 0x33c) == 0) {
        if (*(uint *)(*(int *)(*(int *)(this + 0xc4) + 0xb4) + 0x24) <
            (uint)((int)pCVar31 - *(int *)(pCVar6 + 0x2ac))) {
          in_stack_ffffff7c =
               pCVar31 + (-*(int *)(pCVar6 + 0x2ac) -
                         *(int *)(*(int *)(*(int *)(this + 0xc4) + 0xb4) + 0x24));
        }
      }
      else if (*(uint *)(*(int *)(*(int *)(this + 0xc4) + 0xb4) + 0x24) < *(uint *)(pCVar6 + 0x2b0))
      {
        in_stack_ffffff7c =
             (CTrackManiaRace *)
             (*(uint *)(pCVar6 + 0x2b0) - *(int *)(*(int *)(*(int *)(this + 0xc4) + 0xb4) + 0x24));
      }
      in_stack_ffffff78 = (CTrackManiaRace *)0x47fabb;
      uVar11 = GetTimePenalty(this,in_stack_ffffff7c,(ulong)pCVar42);
      if (uVar11 < *(uint *)(pCVar6 + 0x2dc)) {
        *(uint *)(pCVar6 + 0x2d4) = *(uint *)(pCVar6 + 0x2dc) - uVar11;
      }
      else {
        *(undefined4 *)(pCVar6 + 0x2d4) = 0;
      }
      if (*(CTrackManiaRaceInterface **)(this + 0x518) != (CTrackManiaRaceInterface *)0x0) {
        pCVar42 = (CFastBuffer<class_CCrystalFace*> *)0x47fae8;
        CTrackManiaRaceInterface::OnStuntTimeOverMessage
                  (*(CTrackManiaRaceInterface **)(this + 0x518),
                   (CTrackManiaRaceInterface *)in_stack_ffffff84);
      }
    }
    in_stack_ffffff74 = (code *)0x47faef;
    pCVar7 = GetPlayingPlayerInfo(this,in_stack_ffffff78);
    if (*(CTrackManiaRace **)(pCVar7 + 0x2ac) < pCVar31) {
      pCVar8 = GetPlayingPlayer(this,in_stack_ffffff7c);
      piVar1 = *(int **)(*(int *)(pCVar8 + 0x28) + 0x14);
      iVar26 = (int)pCVar31 - *(int *)(this + 0x110);
      pCVar39 = (CTrackManiaRace *)0xa02b000;
      iVar10 = (**(code **)(*piVar1 + 0x10))();
      if (((iVar10 != 0) && (piVar1[0x10c] == 0)) && ((piVar1[0x10d] == 0 && (piVar1[0x111] == 0))))
      {
        *(int *)(this + 0xfc) = *(int *)(this + 0xfc) + iVar26;
      }
      uVar11 = GetCurrentStandardTime(this,pCVar39);
      if (2999 < uVar11) {
        fVar29 = (float10)(**(code **)(*piVar1 + 0x134))();
        fVar30 = (float10)iVar26;
        if (iVar26 < 0) {
          fVar30 = fVar30 + (float10)_DAT_00c418d0;
        }
        *(float *)(this + 0x104) = (float)(fVar30 * fVar29 + (float10)*(float *)(this + 0x104));
        iStack_5c = iVar26;
      }
      fVar29 = (float10)(**(code **)(*piVar1 + 0x134))();
      if ((float10)_DAT_00b3d2d8 <= fVar29) {
        *(int *)(this + 0x108) = *(int *)(this + 0x108) + iVar26;
      }
      in_stack_ffffff7c = (CTrackManiaRace *)0x47fbaa;
      fVar29 = (float10)(**(code **)(*piVar1 + 0x134))();
      if ((float10)_DAT_00b3d2d0 <= fVar29) {
        *(int *)(this + 0x10c) = *(int *)(this + 0x10c) + iVar26;
      }
      *(CTrackManiaRace **)(this + 0x110) = pCVar31;
    }
    pCVar8 = GetPlayingPlayer(this,in_stack_ffffff7c);
    piVar1 = *(int **)(*(int *)(pCVar8 + 0x28) + 0x14);
    if ((piVar1 != (int *)0x0) && (iVar10 = (**(code **)(*piVar1 + 0x10))(), iVar10 != 0)) {
      iVar10 = (**(code **)(*piVar1 + 0x198))();
      pCVar42 = *(CFastBuffer<class_CCrystalFace*> **)(iVar10 + 0x78);
      in_stack_ffffff74 = (code *)PTR_DAT_00cd3f70;
      CInputPort::RumbleAdd
                (*(CInputPort **)(this + 0x20),(CInputDevice *)PTR_DAT_00cd3f78,
                 (ulong)PTR_DAT_00cd3f70,1.12104e-43,*(float *)(iVar10 + 0x7c));
    }
    in_stack_ffffff7c = (CTrackManiaRace *)0xa02b000;
    in_stack_ffffff78 = (CTrackManiaRace *)0x47fc28;
    iVar10 = (**(code **)(*piVar1 + 0x10))();
    if (iVar10 != 0) {
      CSceneVehicleCar::GetRouletteValue01((int)pCVar31 - piVar1[0x174],DAT_00d06a74);
      pCVar5 = (CMwId *)&stack0xffffff90;
      CFastMap<class_CMwId,float>::SetElem
                ((CFastMap<class_CMwId,float> *)&PTR_vftable_00ce1360,
                 (CFastMap<class_CMwId,float> *)(this + 0x50c),pCVar5,(float *)in_stack_ffffff74);
      _DAT_00d6e840 = pSVar50;
      _DAT_00d6e83c = 1.0;
      _DAT_00d6e844 = 0.0;
      _DAT_00d6e848 = 0x3f800000;
      in_stack_ffffff74 = (code *)0x47fc90;
      pSVar50 = _DAT_00d6e840;
      this_00 = CSysFidNodRef<class_CPlugMaterial>::GetNod
                          ((void *)(*(int *)(*(int *)(this + 0x18) + 0x28) + 0x114),
                           (CSysFidNodRef<class_CPlugMaterial> *)in_stack_ffffff78);
      if (this_00 != (CPlugMaterial *)0x0) {
        in_stack_ffffff78 = (CTrackManiaRace *)0x47fca1;
        iVar10 = CPlugFileImg::IsInSystemMemory
                           ((CPlugFileImg *)this_00,(CPlugFileImg *)in_stack_ffffff74);
        if (iVar10 == 0) {
          in_stack_ffffff7c = (CTrackManiaRace *)0x47fcac;
          CPlugFileImg::ReGenerateForceTexelLoading((CPlugFileImg *)this_00,(CPlugFileImg *)pCVar5);
        }
        pSVar50 = (SInputActionDesc *)0x0;
        pCVar9 = pCVar48;
        CPlugFileImg::FilterWrappedPixel
                  ((CPlugFileImg *)this_00,(CPlugFileImg *)&stack0xffffff88,
                   (GxBGRAColor_conflict *)&stack0xffffff94,(GxTexCoord *)0x1,4,0,0,2,
                   (EGxTexAddress)pCVar5);
        _DAT_00d6e844 = (float)_DAT_00b3d080;
        uVar23 = (uint)pCVar48 >> 8;
        _DAT_00d6e83c = (float)((uint)pCVar48 >> 0x10 & 0xff) * _DAT_00d6e844;
        pCVar48 = (CTrackManiaRace *)((uint)pCVar48 & 0xff);
        _DAT_00d6e840 = (SInputActionDesc *)((float)(uVar23 & 0xff) * _DAT_00d6e844);
        _DAT_00d6e844 = _DAT_00d6e844 * (float)(int)pCVar48;
      }
    }
  }
  if ((DAT_00d560d4 & 1) == 0) {
    DAT_00d560d4 = DAT_00d560d4 | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d560c8,(CFastBuffer<class_CPlugFileSndGen*> *)in_stack_ffffff74);
    in_stack_ffffff74 =
         `public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::__l70::
         _dynamic_atexit_destructor_for__PlayerOrGhosts__;
    _atexit(`public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::__l70::
            _dynamic_atexit_destructor_for__PlayerOrGhosts__);
  }
  pGVar34 = (GmFrustumIso4 *)&DAT_00d560c8;
  pcVar32 = (code *)0x47fd5b;
  GetPlayerOrGhosts(this,(CTrackManiaRace *)&DAT_00d560c8,
                    (CFastBuffer<struct_CTrackManiaRace::SPlayerOrGhost> *)in_stack_ffffff74);
  pSVar2 = *(SInputActionDesc **)(*(int *)(this + 0x18) + 0x78);
  pcVar37 = (code *)0x47fd70;
  pSVar49 = pSVar2;
  iVar10 = CGameNetwork::IsConnected
                     (*(CGameNetwork **)(*(int *)(this + 0x18) + 300),
                      (CCrystalVertex *)in_stack_ffffff78);
  if (iVar10 == 0) {
    pCVar13 = (CGameRace *)0x0;
  }
  else {
    in_stack_ffffff78 = (CTrackManiaRace *)0x47fd82;
    pCVar12 = CTrackManiaNetwork::GetServerInfo
                        (*(CTrackManiaNetwork **)(*(int *)(this + 0x18) + 300),
                         (CTrackManiaNetwork *)in_stack_ffffff7c);
    pCVar13 = *(CGameRace **)(pCVar12 + 0x254);
  }
  if (pCVar13 == (CGameRace *)0x1) {
    pCVar13 = (CGameRace *)0x3e8;
  }
  else {
    pCVar3 = *(CGameRace **)(pSVar2 + 0x16c);
    if (pCVar13 < pCVar3) {
      pCVar13 = pCVar3;
    }
  }
  pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
            CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d560c8,pCVar42);
  pCVar4 = *(CSceneMobil **)(*(int *)(iStack_5c + 0x28) + 0x14);
  iVar10 = (**(code **)(*(int *)pCVar4 + 0x78))();
  if (iVar10 == 0) {
    pCVar27 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar14 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                  (&DAT_00d560c8,pCVar27,(ulong)in_stack_ffffff84);
        in_stack_ffffff84 = (CPlugFileVideo *)0x0;
        (**(code **)(**(int **)(this + 0x18) + 0x8c))();
        pCVar27 = pCVar27 + 1;
      } while (pCVar27 < pCVar14);
    }
  }
  else {
    pSVar43 = (SVolatileTreePointer *)0x0;
    iVar10 = (**(code **)(*(int *)pCVar4 + 0x80))();
    pCVar42 = (CFastBuffer<class_CCrystalFace*> *)0x47fdfb;
    pCVar15 = CSceneMobil::GetTree(pCVar4,pSVar43);
    pCVar31 = *(CTrackManiaRace **)(pCVar15 + 0x44);
    pCVar9 = *(CTrackManiaRace **)(pCVar15 + 0x48);
    if ((float)pCVar9 < (float)pCVar31 != ((float)pCVar9 == (float)pCVar31)) {
      pCVar9 = pCVar31;
    }
    pCVar31 = *(CTrackManiaRace **)(pCVar15 + 0x40);
    if ((float)pCVar9 < (float)pCVar31 != ((float)pCVar9 == (float)pCVar31)) {
      pCVar9 = pCVar31;
    }
    fVar24 = (float)(uint)(*(int *)(*(int *)(this + 0x34) + 100) != -1);
    fVar44 = 6.611587e-39;
    fStack_44 = fVar24;
    (**(code **)(**(int **)(this + 0x18) + 0x84))();
    if (fVar24 == 0.0) {
      if (*(int *)(this + 0xd0) == 0) {
        pGVar45 = (GmFrustumIso4 *)(fVar44 * (float)_DAT_00b313b8);
      }
      else {
        pGVar45 = (GmFrustumIso4 *)(fVar44 * (float)_DAT_00b3d2b8);
      }
    }
    else if (*(int *)(this + 0xd0) == 0) {
      pGVar45 = (GmFrustumIso4 *)(fVar44 * (float)_DAT_00b3d2c0);
    }
    else {
      pGVar45 = (GmFrustumIso4 *)(fVar44 * (float)_DAT_00b3d2c8);
    }
    if ((DAT_00d560d4 & 2) == 0) {
      DAT_00d560d4 = DAT_00d560d4 | 2;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d560bc,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar32);
      pcVar32 = `public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::__l85::
                _dynamic_atexit_destructor_for__OppCloses__;
      _atexit(`public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::__l85::
              _dynamic_atexit_destructor_for__OppCloses__);
    }
    if ((DAT_00d560d4 & 4) == 0) {
      DAT_00d560d4 = DAT_00d560d4 | 4;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d560b0,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar32);
      pcVar32 = `public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::__l85::
                _dynamic_atexit_destructor_for__OppRemotes__;
      _atexit(`public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::__l85::
              _dynamic_atexit_destructor_for__OppRemotes__);
    }
    pCVar31 = (CTrackManiaRace *)0x47fefe;
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&DAT_00d560bc,(GmFrustumIso4 *)pcVar32);
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&DAT_00d560b0,pGVar34);
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pSStack_58 != (SPlugFaceCull *)0x0) {
      do {
        pSVar16 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                            (&DAT_00d560c8,pCVar14,(ulong)pcVar37);
        pCVar39 = *(CTrackManiaRace **)(pSVar16 + 4);
        pCVar9 = pCVar39;
        if ((*(int *)(pSVar16 + 8) == 0) || (pSStack_58 != (SPlugFaceCull *)0x0)) {
          if (*(int *)pSVar16 == 0) goto LAB_0047ffdc;
          iVar26 = *(int *)(*(int *)pSVar16 + 0x1c);
          if ((*(int *)(iVar26 + 0x70) == 0) && (*(int *)(iVar26 + 0x74) == 0)) {
            if (*(int *)(iVar26 + 0x148) == 0) {
              pcVar37 = (code *)0x1;
              (**(code **)(**(int **)(this + 0x18) + 0x8c))();
              pCVar31 = pCVar39;
            }
            else {
              if (iVar26 == *(int *)(this + 0x98)) {
                pcVar37 = (code *)0x47ffb7;
                pCVar6 = CGameRace::GetLocalPlayerInfo
                                   ((CGameRace *)this,(CGameRace *)in_stack_ffffff78);
                if ((*(int *)(pCVar6 + 0x70) != 0) || (*(int *)(pCVar6 + 0x74) != 0)) {
                  in_stack_ffffff78 = (CTrackManiaRace *)0x0;
                  pcVar37 = (code *)0x0;
                  pCVar31 = (CTrackManiaRace *)0x47ffd7;
                  (**(code **)(**(int **)(this + 0x18) + 0x8c))();
                  goto LAB_0048006e;
                }
              }
LAB_0047ffdc:
              in_stack_ffffff78 = (CTrackManiaRace *)0x47ffe5;
              iVar26 = (**(code **)(*(int *)pCVar39 + 0x78))();
              if (iVar26 != 0) {
                pTVar35 = (TiXmlAttribute *)0x0;
                iVar26 = (**(code **)(*(int *)pCVar39 + 0x80))();
                pSVar50 = (SInputActionDesc *)
                          (*(float *)(iVar10 + 0x24) - *(float *)(iVar26 + 0x24));
                pCVar9 = (CTrackManiaRace *)(*(float *)(iVar10 + 0x28) - *(float *)(iVar26 + 0x28));
                pCVar13 = (CGameRace *)(*(float *)(iVar10 + 0x2c) - *(float *)(iVar26 + 0x2c));
                fStack_54 = (float)pCVar13 * (float)pCVar13 +
                            (float)pSVar50 * (float)pSVar50 + (float)pCVar9 * (float)pCVar9;
                if ((float)in_stack_ffffff84 * (float)in_stack_ffffff84 <= fStack_54) {
                  puVar25 = &DAT_00d560b0;
                }
                else {
                  puVar25 = &DAT_00d560bc;
                }
                pCVar31 = (CTrackManiaRace *)0x48006e;
                CFastBuffer<class_CDx9TextureKeeper*>::Add
                          (puVar25,(TiXmlAttributeSet *)&stack0xffffff90,pTVar35);
              }
            }
          }
          else {
            pcVar37 = (code *)0x0;
            (**(code **)(**(int **)(this + 0x18) + 0x8c))();
            pCVar31 = pCVar39;
          }
        }
        else {
          pcVar37 = (code *)0x0;
          (**(code **)(**(int **)(this + 0x18) + 0x8c))();
          pCVar31 = pCVar39;
        }
LAB_0048006e:
        pCVar14 = pCVar14 + 1;
      } while (pCVar14 < pSStack_58);
    }
    if ((*(uint *)(this + 0x500) < 4) && (*(int *)(this + 0xf0) != 0)) {
      pSVar28 = (STmRaceLowFps *)0x1;
    }
    else {
      pSVar28 = (STmRaceLowFps *)0x1;
      if ((*(int *)(pCVar48 + 0x168) != 1) ||
         (uVar11 = CFastBuffer<class_CCrystalFace*>::GetCount
                             (&DAT_00d560bc,(CFastBuffer<class_CCrystalFace*> *)pcVar37),
         uVar11 == 0)) {
        pSVar28 = (STmRaceLowFps *)0x0;
      }
    }
    pSVar46 = pSVar28;
    pCVar6 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,(CGameRace *)pcVar37);
    if ((*(int *)(pCVar6 + 0x70) != 0) || (*(int *)(pCVar6 + 0x74) != 0)) {
      pSVar28 = (STmRaceLowFps *)0x0;
      pCVar48 = (CTrackManiaRace *)0x0;
    }
    if (DAT_00cd4054 == 0) {
      pcVar37 = (code *)0x4800e2;
      pCVar6 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,(CGameRace *)pCVar42);
      if (((*(int *)(pCVar6 + 0x70) != 0) || (*(int *)(pCVar6 + 0x74) != 0)) || (fStack_54 != 0.0))
      goto LAB_0048010b;
      pcVar37 = (code *)0x480104;
      CFastBuffer<class_CSceneMobil*>::Merge
                (&DAT_00d560bc,(CFastBuffer<class_CSceneMobil*> *)&DAT_00d560b0,
                 (CFastBuffer<class_CSceneMobil*> *)pCVar42);
      puVar25 = &DAT_00d560b0;
LAB_00480123:
      pCVar42 = (CFastBuffer<class_CCrystalFace*> *)0x480128;
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(puVar25,pGVar45);
    }
    else {
LAB_0048010b:
      if (pSVar28 == (STmRaceLowFps *)0x0) {
        pcVar37 = (code *)0x48011e;
        CFastBuffer<class_CSceneMobil*>::Merge
                  (&DAT_00d560b0,(CFastBuffer<class_CSceneMobil*> *)&DAT_00d560bc,
                   (CFastBuffer<class_CSceneMobil*> *)pCVar42);
        puVar25 = &DAT_00d560bc;
        goto LAB_00480123;
      }
    }
    pCVar40 = (CFastBuffer<class_CCrystalFace*> *)0x480132;
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d560bc,pCVar42);
    if (pCVar14 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      pCVar27 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      do {
        pCVar40 = (CFastBuffer<class_CCrystalFace*> *)0x48014b;
        pSVar16 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (&DAT_00d560bc,pCVar27,(ulong)pGVar45);
        pGVar45 = (GmFrustumIso4 *)0x480159;
        iVar10 = (**(code **)(**(int **)pSVar16 + 0x108))();
        if (iVar10 != 0) {
          pCVar40 = (CFastBuffer<class_CCrystalFace*> *)0x0;
          pcVar37 = (code *)0x0;
          (**(code **)(**(int **)(this + 0x18) + 0x8c))();
        }
        pCVar27 = pCVar27 + 1;
      } while (pCVar27 < pCVar14);
    }
    pCStack_48 = (CFastBuffer<class_GxVertex2> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (&DAT_00d560b0,(CFastBuffer<class_CCrystalFace*> *)pGVar45);
    if (in_stack_ffffffa0 < pCStack_48) {
      iVar10 = (*(int **)(*(int *)(this + 0x34) + 0x74))[0xc];
      uVar11 = 0;
      pCVar42 = (CFastBuffer<class_CCrystalFace*> *)0x4801a6;
      (**(code **)(**(int **)(*(int *)(this + 0x34) + 0x74) + 0x7c))();
      if ((DAT_00d560d4 & 8) == 0) {
        DAT_00d560d4 = DAT_00d560d4 | 8;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&DAT_00d560a4,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar37);
        pcVar37 = `public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::B::
                  _dynamic_atexit_destructor_for__Dists__;
        _atexit(`public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::B::
                _dynamic_atexit_destructor_for__Dists__);
      }
      if ((DAT_00d560d4 & 0x10) == 0) {
        DAT_00d560d4 = DAT_00d560d4 | 0x10;
        CFastRadixSort::CFastRadixSort(&DAT_00d5608c,(CFastRadixSort *)pcVar37);
        pcVar37 = `public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::B::
                  _dynamic_atexit_destructor_for__RadixSort__;
        _atexit(`public:_virtual_void___thiscall_CTrackManiaRace::UpdateAsync(void)'::B::
                _dynamic_atexit_destructor_for__RadixSort__);
      }
      pCVar33 = (CPlugVolumeProjector *)0x480233;
      pCVar36 = pCStack_48;
      CFastBuffer<float>::AllocSetCount(&DAT_00d560a4,pCStack_48,(ulong)pcVar37);
      in_stack_ffffffa0 =
           (CFastBuffer<class_GxVertex2> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d560a4,pCVar40);
      pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (in_stack_ffffffa0 != (CFastBuffer<class_GxVertex2> *)0x0) {
        do {
          pGVar38 = (GmIso4 *)0x48025b;
          pSVar16 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              (&DAT_00d560b0,pCVar14,(ulong)pCVar42);
          pCVar4 = *(CSceneMobil **)pSVar16;
          pCVar42 = (CFastBuffer<class_CCrystalFace*> *)0x0;
          uVar41 = 0x48026b;
          pSVar17 = (SPlugFaceCull *)(**(code **)(*(int *)pCVar4 + 0x80))();
          pCVar15 = CSceneMobil::GetTree(pCVar4,(SVolatileTreePointer *)pCVar31);
          GmIso4::SetMult(auStack_30,pSVar17,pSStack_58,(GmIso4 *)pCVar33);
          GmBoxAligned::SetMult
                    (&fStack_44,(SPlugFaceCull *)(pCVar15 + 0x34),aSStack_2c,(GmIso4 *)pCVar36);
          pCVar33 = (CPlugVolumeProjector *)afStack_40;
          pCVar31 = (CTrackManiaRace *)0x4802a7;
          iVar26 = GmFrustum::TestInter
                             ((void *)(iVar10 + 0x118),pCVar33,(GmBoxAligned *)0x0,pGVar38);
          if (iVar26 == 0) {
            pCVar36 = (CFastBuffer<class_GxVertex2> *)0x48030b;
            pSVar16 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                (&DAT_00d560a4,pCVar14,uVar41);
            pCVar3 = _DAT_00b3d074;
          }
          else {
            pCStack_48 = (CFastBuffer<class_GxVertex2> *)
                         (*(float *)(pSStack_58 + 0x24) - *(float *)(pSVar17 + 0x24));
            fStack_44 = *(float *)(pSStack_58 + 0x28) - *(float *)(pSVar17 + 0x28);
            afStack_40[0] = *(float *)(pSStack_58 + 0x2c) - *(float *)(pSVar17 + 0x2c);
            pCVar9 = (CTrackManiaRace *)
                     (afStack_40[0] * afStack_40[0] +
                     (float)pCStack_48 * (float)pCStack_48 + fStack_44 * fStack_44);
            pCVar36 = (CFastBuffer<class_GxVertex2> *)0x480300;
            pSVar16 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                (&DAT_00d560a4,pCVar14,uVar41);
            pCVar3 = pCVar13;
          }
          pCVar14 = pCVar14 + 1;
          *(CGameRace **)pSVar16 = pCVar3;
        } while (pCVar14 < in_stack_ffffffa0);
      }
      pfVar18 = (float *)CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d560a4,pCVar42);
      CFastRadixSort::Sort(&DAT_00d5608c,DAT_00d560a8,pfVar18,uVar11);
      iVar10 = DAT_00d56094;
      pCVar36 = (CFastBuffer<class_GxVertex2> *)0x0;
      if (in_stack_ffffffa0 != (CFastBuffer<class_GxVertex2> *)0x0) {
        pCVar36 = (CFastBuffer<class_GxVertex2> *)0x0;
        do {
          pCVar14 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar10 + (int)pCVar36 * 4);
          pSVar16 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              (&DAT_00d560a4,pCVar14,(ulong)in_stack_ffffff84);
          if (*(float *)pSVar16 == (float)_DAT_00b3d2b0) break;
          piVar1 = *(int **)(this + 0x18);
          in_stack_ffffff84 = (CPlugFileVideo *)0x0;
          CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](&DAT_00d560b0,pCVar14,1);
          (**(code **)(*piVar1 + 0x8c))();
          pCVar36 = pCVar36 + 1;
        } while (pCVar36 < in_stack_ffffffa0);
      }
      if (pCVar36 < pCStack_48) {
        do {
          pSVar16 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              (&DAT_00d560b0,
                               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                (iVar10 + (int)pCVar36 * 4),(ulong)in_stack_ffffff84);
          in_stack_ffffff84 = (CPlugFileVideo *)0x4803c2;
          iVar26 = (**(code **)(**(int **)pSVar16 + 0x108))();
          if (iVar26 != 0) {
            (**(code **)(**(int **)(this + 0x18) + 0x8c))();
          }
          pCVar36 = pCVar36 + 1;
        } while (pCVar36 < pCStack_48);
        *(CTrackManiaRace **)(this + 0xd0) = pCVar9;
        goto LAB_0048048b;
      }
    }
    else {
      pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCStack_48 != (CFastBuffer<class_GxVertex2> *)0x0) {
        do {
          iVar10 = **(int **)(this + 0x18);
          CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](&DAT_00d560b0,pCVar14,1);
          (**(code **)(iVar10 + 0x8c))();
          pCVar14 = pCVar14 + 1;
        } while (pCVar14 < pCStack_48);
      }
    }
    *(CTrackManiaRace **)(this + 0xd0) = pCVar9;
  }
LAB_0048048b:
  if (0 < *(int *)(*(int *)(*(int *)(this + 0x18) + 0x68) + 0x14)) {
    if ((*(int **)(this + 0x510) != (int *)0x0) &&
       (iVar10 = (**(code **)(**(int **)(this + 0x510) + 0x10))(), iVar10 != 0)) {
      (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x34) + 0x74) + 0x3c) + 0x90))();
      fVar29 = (float10)func_0x009c1b40();
      *(float *)(*(int *)(this + 0x510) + 0x78) = (float)fVar29 * (float)_DAT_00b3d2a8;
      *(undefined4 *)(*(int *)(this + 0x510) + 0x7c) = 0;
      *(undefined4 *)(*(int *)(this + 0x510) + 0x80) = 0;
    }
    if (*(int *)(this + 0x514) != 0) {
      pCVar19 = CScene3d::SceneFxFindFromClassId
                          (*(CScene3d **)(*(int *)(this + 0x30) + 0x14),(CScene3d *)0xa034000,0,
                           (CSceneFxNod **)in_stack_ffffff84);
      if (pCVar19 != (CSceneFx *)0x0) {
        if (DAT_00b3d2a0 < *(float *)(pCVar19 + 0xec)) {
          *(float *)(*(int *)(this + 0x514) + 0x3c) =
               (*(float *)(pCVar19 + 0xec) - (float)_DAT_00b3d298) * (float)_DAT_00b3d290;
          in_stack_ffffff84 = _DAT_00b2c060;
          CAudioSound::Play(*(CAudioSound **)(this + 0x514),_DAT_00b2c060,(EPlugVideoTimer)pSVar46,
                            (int)pCVar48,(ulong)pSVar49);
          goto LAB_004805b4;
        }
        *(undefined4 *)(*(int *)(this + 0x514) + 0x3c) = 0;
      }
      in_stack_ffffff84 = (CPlugFileVideo *)0x4805b4;
      CAudioSound::Stop(*(CAudioSound **)(this + 0x514),pSVar46);
    }
  }
LAB_004805b4:
  if ((pCVar13 != (CGameRace *)0x0) && (*(int *)(pCVar13 + 0x120) == 0)) {
    CGameApp::UpdateMusic(*(CGameApp **)(this + 0x18),(CGameApp *)in_stack_ffffff84);
  }
  if ((*(CInputPort **)(this + 0x20) != (CInputPort *)0x0) && (*(int *)(this + 0xa8) == 0)) {
    CInputPort::ReadCurMapLatestEventsFromHarware
              (*(CInputPort **)(this + 0x20),(CInputPort *)0x0,(int)in_stack_ffffff84);
    iVar10 = 0x4805fa;
    pSVar20 = CInputPort::GetActionState
                        (*(CInputPort **)(this + 0x20),(CInputPort *)PTR_DAT_00cd3f5c,
                         (SInputActionDesc *)pSVar46);
    if ((*(int *)(pSVar20 + 4) != 0) ||
       (((pSVar20 = CInputPort::GetActionState
                              (*(CInputPort **)(this + 0x20),(CInputPort *)PTR_DAT_00cd3f60,
                               (SInputActionDesc *)pCVar48), *(int *)(pSVar20 + 4) != 0 ||
         (pSVar20 = CInputPort::GetActionState
                              (*(CInputPort **)(this + 0x20),(CInputPort *)PTR_DAT_00cd3f58,pSVar49)
         , *(int *)(pSVar20 + 4) != 0)) ||
        (pSVar20 = CInputPort::GetActionState(*(CInputPort **)(this + 0x20),DAT_00d71440,pSVar50),
        *(int *)(pSVar20 + 4) != 0)))) {
      CGameRace::MediaClipStop((CGameRace *)this,(CGameRace *)pCVar9);
      pCVar21 = CGameRace::GetLocalPlayer((CGameRace *)this,pCVar13);
      pCVar22 = CGamePlayerCameraSet::CamPtrGetCur
                          (*(CGamePlayerCameraSet **)(pCVar21 + 0x20),
                           (CGamePlayerCameraSet *)in_stack_ffffffa0);
      (**(code **)(*(int *)pCVar22 + 0x90))();
      CInputPort::ClearInputs(*(CInputPort **)(this + 0x20),(CInputPort *)0x1,iVar10);
    }
  }
  pCVar9 = this + 0x4e8;
  uVar23 = *(uint *)pCVar9;
  *(uint *)pCVar9 = *(uint *)pCVar9 + 1;
  *(uint *)(this + 0x4ec) = *(int *)(this + 0x4ec) + (uint)(0xfffffffe < uVar23);
  CMwProfiler::GetTimeStamp((int64 *)(this + 0x4f8));
  if (*(int *)(this + 0x4e8) == 0 && *(int *)(this + 0x4ec) == 0) {
    *(undefined4 *)(this + 0x4f0) = *(undefined4 *)(this + 0x4f8);
    *(undefined4 *)(this + 0x4f4) = *(undefined4 *)(this + 0x4fc);
  }
  ExceptionList = in_stack_00000018;
  return;
}
}

// =================================================
// Function: CTrackManiaRace::UpdateCams
// =================================================
void __thiscall CTrackManiaRace::UpdateCams(CTrackManiaRace *this,CGameCtnMediaClipViewer *param_1)
{
{
  CGamePlayerCameraSet *this_00;
  CGamePlayerInfo *pCVar1;
  int iVar2;
  CGameControlCamera *pCVar3;
  SGameCamVal *pSVar4;
  CGameRace *unaff_ESI;
  CGameRace *unaff_EDI;
  void *in_stack_0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  CGameRace *in_stack_ffffff94;
  CGameRace *in_stack_ffffff98;
  CGamePlayerCameraSet *in_stack_ffffff9c;
  CGamePlayerCameraSet *in_stack_ffffffa0;
  CInputPortDx8 *in_stack_ffffffa4;
  SGameCamVal *in_stack_ffffffa8;
  CGameRace *in_stack_ffffffac;
  GmCamFreeVal *pGVar5;
  CFastStringInt *in_stack_ffffffb0;
  CGameRace *in_stack_ffffffb4;
  GmCamVal *in_stack_ffffffb8;
  CGameRace *in_stack_ffffffbc;
  GmCamVal *in_stack_ffffffc0;
  CGameControlCameraMaster aCStack_3c [8];
  CGameControlCameraMaster aCStack_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a87fd8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = CGameRace::GetLocalPlayerInfo
                     ((CGameRace *)this,(CGameRace *)(DAT_00cca150 ^ (uint)&stack0xffffff8c));
  if (pCVar1 == (CGamePlayerInfo *)0x0) {
    ExceptionList = in_stack_0000001c;
    return;
  }
  pCVar1 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,unaff_EDI);
  if (*(int *)(pCVar1 + 0x238) == 0) {
    ExceptionList = in_stack_0000001c;
    return;
  }
  pCVar1 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,unaff_ESI);
  if (*(int *)(*(int *)(pCVar1 + 0x238) + 0x20) == 0) {
    ExceptionList = in_stack_0000001c;
    return;
  }
  pCVar1 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_ffffff94);
  this_00 = *(CGamePlayerCameraSet **)(*(int *)(pCVar1 + 0x238) + 0x20);
  if ((*(int *)(this + 0x540) != 0) &&
     ((((iVar2 = CGameRace::MediaClipIsPlaying((CGameRace *)this,in_stack_ffffff98), iVar2 == 0 ||
        (*(int *)(*(int *)(this + 0xa0) + 0xbc) == 0)) &&
       (pCVar3 = CGamePlayerCameraSet::CamPtrGetCur(this_00,in_stack_ffffff9c),
       pCVar3 != (CGameControlCamera *)0x0)) &&
      (pCVar3 = CGamePlayerCameraSet::CamPtrGetCur(this_00,in_stack_ffffffa0),
      *(int *)(this + 0x544) != *(int *)(pCVar3 + 0x14))))) {
    pCVar3 = CGamePlayerCameraSet::CamPtrGetCur(this_00,(CGamePlayerCameraSet *)in_stack_ffffffa4);
    in_stack_ffffffa4 = (CInputPortDx8 *)0x47e2f5;
    (**(code **)(*(int *)pCVar3 + 0x90))();
  }
  *(undefined4 *)(this + 0x540) = 0;
  CGamePlayerCameraSet::UpdateAsync(this_00,in_stack_ffffffa4);
  SGameCamVal::SGameCamVal(&stack0xffffffb4,in_stack_ffffffa8);
  uStack00000020 = 0;
  iVar2 = CGameRace::MediaClipIsPlaying((CGameRace *)this,in_stack_ffffffac);
  if ((iVar2 == 0) || (*(int *)(*(CGameCtnMediaClipPlayer **)(this + 0xa0) + 0xbc) == 0)) {
    if (*(int *)(this + 0x50) == 1) goto LAB_0047e3d0;
    pGVar5 = (GmCamFreeVal *)&stack0xffffffbc;
    CGameControlCameraMaster::GetCamVal
              (*(CGameControlCameraMaster **)(this_00 + 0x18),pGVar5,(GmCamVal *)in_stack_ffffffb0);
  }
  else {
    pSVar4 = CGameCtnMediaClipPlayer::GetCamValDefined
                       (*(CGameCtnMediaClipPlayer **)(this + 0xa0),
                        (CGameCtnMediaClipPlayer *)in_stack_ffffffb0);
    pGVar5 = (GmCamFreeVal *)0x47e340;
    SGameCamVal::operator=(&stack0xffffffc0,(SNormalDec3N *)pSVar4,(GmVec3 *)in_stack_ffffffb4);
    *(undefined4 *)(this + 0x540) = 1;
    *(undefined4 *)(this + 0x544) = uStack00000020;
  }
  in_stack_ffffffb0 = (CFastStringInt *)0x47e370;
  iVar2 = CGameRace::MediaClipIsPlaying((CGameRace *)this,in_stack_ffffffb4);
  if ((iVar2 != 0) && (*(int *)(*(int *)(this + 0xa0) + 0x1c) != 0)) {
    in_stack_ffffffb0 = (CFastStringInt *)0x47e38f;
    CGameControlCameraMaster::ApplyGlobalEffectsOn
              (*(CGameControlCameraMaster **)(*(int *)(this + 0xa0) + 0x1c),aCStack_3c,
               in_stack_ffffffb8);
  }
  iVar2 = CGameRace::MediaClipIsPlayingGlobal((CGameRace *)this,in_stack_ffffffbc);
  if ((iVar2 != 0) && (*(int *)(*(int *)(this + 0xa4) + 0x1c) != 0)) {
    CGameControlCameraMaster::ApplyGlobalEffectsOn
              (*(CGameControlCameraMaster **)(*(int *)(this + 0xa4) + 0x1c),aCStack_34,
               in_stack_ffffffc0);
  }
  (**(code **)(*(int *)this_00 + 0x78))();
  CGameCamera::SetGameCamVal
            (*(CGameCamera **)(this + 0x34),(CGameCamera *)&stack0xffffffb8,(SGameCamVal *)pGVar5);
LAB_0047e3d0:
  uStack00000024 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(in_stack_ffffffb0);
  ExceptionList = in_stack_0000001c;
  return;
}
}

// =================================================
// Function: CTrackManiaRace::UpdateCountDownIndex
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaRace::UpdateCountDownIndex(CTrackManiaRace *this,CTrackManiaRace *param_1)
{
{
  CGameRace *pCVar1;
  CGameRace *pCVar2;
  CMwId *pCVar3;
  CGameRace *pCVar4;
  CGamePlayerInfo *pCVar5;
  int iVar6;
  CPlugAudio *this_00;
  void *this_01;
  CGameCtnBench *unaff_EBX;
  CGameCtnChallenge *pCVar7;
  CGameRace *unaff_EBP;
  CMwTimerAdapter *unaff_ESI;
  CPlugAudio *unaff_EDI;
  int unaff_retaddr;
  CGameRace *in_stack_00000008;
  CGameRace *in_stack_0000000c;
  int in_stack_00000010;
  CGameRace *in_stack_00000018;
  CGameRace *in_stack_00000028;
  CPlugSound *pCVar8;
  ulong in_stack_fffffff8;
  CGameRace *pCVar9;
  
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar3 = CPlugAudio::MwGetId(this_00,unaff_EDI);
  pCVar9 = *(CGameRace **)pCVar3;
  this_01 = *(void **)(DAT_00d731e0 + 0x14);
  if (this_01 == (void *)0x0) {
    this_01 = (void *)(DAT_00d731e0 + 0xa0);
  }
  pCVar4 = (CGameRace *)CMwTimerAdapter::GetTimeAtPreviousHumanTick(this_01,unaff_ESI);
  pCVar5 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,unaff_EBP);
  pCVar1 = *(CGameRace **)(pCVar5 + 0x2ac);
  pCVar2 = *(CGameRace **)(pCVar5 + 0x2a4);
  pCVar7 = (CGameCtnChallenge *)0xffffffff;
  if (((*(int *)(pCVar5 + 0x314) == 0) && (*(int *)(*(int *)(this + 0x18) + 0x418) != 4)) &&
     (*(int *)(*(int *)(this + 0x18) + 0x418) != 5)) {
    if (((pCVar2 < pCVar1) && (pCVar2 < pCVar4)) && (pCVar4 < pCVar1)) {
      pCVar7 = (CGameCtnChallenge *)
               ((uint)(((int)pCVar4 - (int)pCVar2) * 3) / (uint)((int)pCVar1 - (int)pCVar2));
      if (DAT_00d564cc == 0) {
        STmRaceLowFps::Start(&DAT_00d564c8,unaff_EBX);
      }
      if ((pCVar7 < (CGameCtnChallenge *)0x3) &&
         (in_stack_0000000c <= pCVar2 + (uint)((int)pCVar7 * ((int)pCVar1 - (int)pCVar2)) / 3)) {
        if (pCVar7 == (CGameCtnChallenge *)0x0) {
          pCVar8 = (CPlugSound *)0x1e;
        }
        else if (pCVar7 == (CGameCtnChallenge *)0x1) {
          pCVar8 = (CPlugSound *)&DAT_0000001d;
        }
        else {
          if (pCVar7 != (CGameCtnChallenge *)0x2) goto LAB_0047aee4;
          pCVar8 = (CPlugSound *)0x1c;
        }
        CGameApp::PlaySound(pCVar8);
      }
    }
  }
  else if ((*(int *)(pCVar5 + 0x314) == 1) && (pCVar4 < pCVar1 + 500)) {
    pCVar7 = (CGameCtnChallenge *)0x3;
  }
LAB_0047aee4:
  CGameCtnChallenge::SetStartLight(*(CGameCtnChallenge **)(this + 0xc4),pCVar7,in_stack_fffffff8);
  *(CGameCtnChallenge **)(this + 0x500) = pCVar7;
  if (pCVar7 == (CGameCtnChallenge *)0x0) {
    iVar6 = CGameRace::MediaClipIsPlaying((CGameRace *)this,pCVar9);
    if (iVar6 == 0) {
      CGameRace::MediaClipStartCutScene
                ((CGameRace *)this,(CGameRace *)0x1,
                 (EChallengeCutScene)
                 ((float)(in_stack_00000010 - (int)pCVar2) * (float)_DAT_00b30a18),0.0,unaff_retaddr
                );
    }
    iVar6 = CGameRace::MediaClipIsPlayingGlobal((CGameRace *)this,pCVar4);
    if (iVar6 == 0) {
      iVar6 = CGameRace::MediaClipIsPlayingIntro((CGameRace *)this,in_stack_00000008);
      if (iVar6 == 0) {
        CGameRace::MediaClipStartGlobal((CGameRace *)this,in_stack_00000028);
        return;
      }
    }
  }
  else if ((pCVar7 == (CGameCtnChallenge *)0x3) && (*(int *)(this + 0xa8) == 0)) {
    CGameRace::MediaClipStop((CGameRace *)this,in_stack_00000018);
    return;
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRace::Validate
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaRace::Validate
          (CTrackManiaRace *this,CTrackManiaRace *param_1,SMwFiberContext **param_2,
          STmValidateParam *param_3,ETmValidateResult *param_4,CFastStringInt *param_5,int param_6,
          int param_7,int param_8)
{
{
  int *piVar1;
  CMwId CVar2;
  CMwId *pCVar3;
  void *pvVar4;
  SMwFiberContext *extraout_EAX;
  SMwFiberContext *pSVar5;
  CFastString *pCVar6;
  CTrackManiaPlayerInfo *this_00;
  CMwNodRef<class_CGameCamera> *extraout_EAX_00;
  CMwNodRef<class_CGameCamera> *pCVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  CFastStringInt *pCVar8;
  uint uVar9;
  CGameDialogs *pCVar10;
  CGamePlayer *pCVar11;
  ulong uVar12;
  SCasterCat *pSVar13;
  int iVar14;
  CMwCmdBufferCore *this_01;
  uint uVar15;
  CGameRace *unaff_EBX;
  SStringParam *unaff_EBP;
  CFastStringInt *unaff_ESI;
  undefined4 unaff_EDI;
  CTrackManiaRace *pCVar16;
  int unaff_retaddr;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined4 uStack00000038;
  undefined4 uStack0000003c;
  CTrackManiaRace *in_stack_ffffff6c;
  CGameRace *in_stack_ffffff70;
  CGameRace *in_stack_ffffff74;
  CGameRace *in_stack_ffffff78;
  CGameDialogs *pCVar17;
  CFastStringInt *in_stack_ffffff7c;
  CGameRace *pCVar18;
  char *in_stack_ffffff80;
  CFastStringInt *pCVar19;
  char *this_02;
  SStringParam *pSVar20;
  SHeaderCommunity *pSVar21;
  _func___cdecl_void *p_Var22;
  EStatus EVar23;
  double dVar24;
  SContext *pSVar25;
  SNationConfig *pSVar26;
  undefined4 uVar27;
  ulong in_stack_ffffff9c;
  CFastStringInt *in_stack_ffffffa4;
  CMwId *in_stack_ffffffa8;
  CFastStringInt *in_stack_ffffffac;
  CMwId *in_stack_ffffffb0;
  CMwId *in_stack_ffffffb4;
  CMwId *in_stack_ffffffb8;
  CMwId *in_stack_ffffffbc;
  CMwId *in_stack_ffffffc0;
  CMwId *in_stack_ffffffc4;
  CGameRace *in_stack_ffffffc8;
  undefined4 local_34;
  char *local_30;
  char local_2c [8];
  SHeaderCommunity aSStack_24 [8];
  char acStack_1c [4];
  undefined1 auStack_18 [4];
  wchar_t *pwStack_14;
  undefined4 uStack_10;
  void *local_c;
  int *piStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  piStack_8 = (int *)&LAB_00a885eb;
  local_c = ExceptionList;
  dVar24 = (double)CONCAT44(unaff_EDI,(CPlugAudio *)(DAT_00cca150 ^ (uint)&stack0xffffff8c));
  ExceptionList = &local_c;
  this_01 = *(CMwCmdBufferCore **)(DAT_00d731e0 + 0x14);
  if (this_01 == (CMwCmdBufferCore *)0x0) {
    this_01 = DAT_00d731e0 + 0xa0;
  }
  this_02 = (char *)0x4827a0;
  pCVar3 = CPlugAudio::MwGetId((CPlugAudio *)this_01,
                               (CPlugAudio *)(DAT_00cca150 ^ (uint)&stack0xffffff8c));
  pCVar3 = *(CMwId **)pCVar3;
  if (*param_2 == (SMwFiberContext *)0xffffffff) {
    ExceptionList = local_4;
    return;
  }
  if (*param_2 == (SMwFiberContext *)0x0) {
    dVar24 = (double)CONCAT44((int)((ulonglong)dVar24 >> 0x20),0x28);
    this_02 = (char *)0x4827c2;
    pvVar4 = operator_new(0x28);
    if (pvVar4 == (void *)0x0) {
      pSVar5 = (SMwFiberContext *)0x0;
    }
    else {
      pSVar25 = (SContext *)((ulonglong)dVar24 >> 0x20);
      dVar24 = (double)CONCAT44(pSVar25,0x4827d0);
      `public:_void___thiscall_CTrackManiaRace::
      Validate(struct_SMwFiberContext*&,struct_STmValidateParam_const&,enum_ETmValidateResult&,class_CFastStringInt&,int,int,int)'
      ::__l5::SContext::SContext(pvVar4,pSVar25);
      pSVar5 = extraout_EAX;
    }
    *param_2 = pSVar5;
  }
  uVar9 = *(uint *)(*param_2 + 4);
  if (0x5b7 < uVar9) {
    if (uVar9 == 0x60d) {
      if (*(int *)(this + 0x288) == 0) {
        uVar27 = 0xffffffff;
        EVar23 = 0xffffffff;
        (**(code **)(*(int *)this + 0x168))();
        CGameRace::SetStatus((CGameRace *)this,(CGameRace *)0x3,EVar23);
        dVar24 = (double)CONCAT44(uVar27,0x24044000);
        iVar14 = (**(code **)(*(int *)this + 0x10))(0x24044000);
        if (iVar14 != 0) {
          dVar24 = 2.6915632276132102e-307;
          CTrackManiaNetwork::Hack_ResetAfterValidation
                    (*(CTrackManiaNetwork **)(*(int *)(this + 0x18) + 300),
                     (CTrackManiaNetwork *)unaff_ESI);
        }
      }
      *(undefined4 *)param_5 = *(undefined4 *)(*param_2 + 0x1c);
      local_34 = *(undefined4 *)(*param_2 + 0x24);
      local_30 = *(char **)(*param_2 + 0x20);
      pCVar8 = (CFastStringInt *)&local_34;
      local_2c[0] = '\0';
      local_2c[1] = '\0';
      local_2c[2] = '\0';
      local_2c[3] = '\0';
      pSVar20 = (SStringParam *)((ulonglong)dVar24 >> 0x20);
    }
    else {
      if (uVar9 != 0xffffffff) goto LAB_004831a4;
LAB_00483055:
      if (param_7 != 0) {
        dVar24 = (double)CONCAT44(0x483067,SUB84(dVar24,0));
        pCVar10 = CGameApp::GetBasicDialogs(*(CGameApp **)(this + 0x18),(CGameApp *)unaff_ESI);
        unaff_ESI = (CFastStringInt *)0x48306e;
        CGameDialogs::HideDialogs(pCVar10,(CGameCtnMenus *)unaff_EBP);
      }
      if (*(int *)(this + 0x32c) != 0) {
        dVar24 = (double)CONCAT44(0x483081,SUB84(dVar24,0));
        uVar12 = CFastBuffer<class_CCrystalFace*>::GetCount
                           (this + 0x24,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
        if (uVar12 != 0) {
          dVar24 = (double)CONCAT44(0x48308e,SUB84(dVar24,0));
          pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              (this + 0x24,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                               (ulong)unaff_EBP);
          iVar14 = *(int *)(*(int *)pSVar13 + 0x28);
          pCVar11 = CGameRace::GetLocalPlayer((CGameRace *)this,unaff_EBX);
          CGamePlayerCameraSet::PlayerGameMobilIdSet
                    (*(CGamePlayerCameraSet **)(pCVar11 + 0x20),
                     *(CGamePlayerCameraSet **)(iVar14 + 0x18),in_stack_ffffff9c);
        }
      }
      ValidateCleanup(this,in_stack_ffffff6c);
      CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_ffffff70);
      CGameRace::GetLocalPlayer((CGameRace *)this,in_stack_ffffff74);
      pCVar11 = CGameRace::GetLocalPlayer((CGameRace *)this,in_stack_ffffff78);
      CHmsItem::SetCollisionGroup
                (*(CHmsItem **)(*(int *)(*(int *)(pCVar11 + 0x28) + 0x14) + 0x28),(CHmsItem *)0x3,
                 (ECollisionGroup)in_stack_ffffff7c);
      CMwCmdBufferCore::SetSimulationRelativeSpeed
                (DAT_00d731e0,(CMwCmdBufferCore *)0x3f800000,(float)in_stack_ffffff80);
      CMwCmdBufferCore::SetSimulationCurrentTime
                (DAT_00d731e0,*(CMwCmdBufferCore **)(*param_2 + 0x10),(ulong)this_02);
      CInputPort::ClearInputs(*(CInputPort **)(this + 0x20),(CInputPort *)0x1,SUB84(dVar24,0));
      pCVar8 = (CFastStringInt *)&pwStack_14;
      *param_4 = 0;
      pwStack_14 = L"Validation interrupted";
      uStack_10 = 0x16;
      local_c = (void *)0x1;
      pSVar20 = (SStringParam *)((ulonglong)dVar24 >> 0x20);
    }
    CFastStringInt::SetString(param_5,pCVar8,pSVar20);
LAB_004831a4:
    pSVar5 = *param_2;
    if ((pSVar5 != (SMwFiberContext *)0xffffffff) && (pSVar5 != (SMwFiberContext *)0x0)) {
      (*(code *)**(undefined4 **)pSVar5)();
    }
    *param_2 = (SMwFiberContext *)0xffffffff;
    ExceptionList = local_4;
    return;
  }
  if (uVar9 == 0x5b7) {
    if (*(int *)(this + 0x330) == 0) goto LAB_00483055;
    if ((*(uint *)(*(int *)(this + 0x2fc) + 0xec) == 0xffffffff) ||
       (*(uint *)(this + 800) <= *(uint *)(*(int *)(this + 0x2fc) + 0xec))) goto LAB_00482dd5;
  }
  else {
    if (uVar9 == 0) {
      *(int *)(this + 0x32c) = param_8;
      p_Var22 = (_func___cdecl_void *)0x482aa6;
      STmValidateParam::operator=(this + 0x2fc,(SNormalDec3N *)param_4,(GmVec3 *)unaff_ESI);
      *(undefined4 *)(*param_2 + 0x1c) = 2;
      pSVar26 = (SNationConfig *)0x482abb;
      CFastStringInt::SetLength
                (*param_2 + 0x20,(CFastString *)0x0,(ulong)unaff_EBP,(int)unaff_EBX,
                 (char)in_stack_ffffff9c);
      (**(code **)(*(int *)this + 0x80))();
      pvVar4 = *(void **)(this + 0x300);
      CVar2 = CMwId::CreateFromLocalName((char *)&stack0x00000030);
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd3f70,
                 (SInputActionDesc *)CONCAT31(extraout_var,CVar2),pCVar3);
      OnAccessViolation_ConcatToCrashFileName(in_stack_ffffffa4);
      CVar2 = CMwId::CreateFromLocalName(&stack0xffffffbc);
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd3f74,
                 (SInputActionDesc *)CONCAT31(extraout_var_00,CVar2),(CMwId *)in_stack_ffffffa4);
      param_7 = -1;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffa8);
      CVar2 = CMwId::CreateFromLocalName(&stack0xffffffc4);
      param_7 = 2;
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd3f78,
                 (SInputActionDesc *)CONCAT31(extraout_var_01,CVar2),in_stack_ffffffa8);
      param_8 = -1;
      OnAccessViolation_ConcatToCrashFileName(in_stack_ffffffac);
      CVar2 = CMwId::CreateFromLocalName((char *)&local_34);
      param_8 = 3;
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd3f68,
                 (SInputActionDesc *)CONCAT31(extraout_var_02,CVar2),(CMwId *)in_stack_ffffffac);
      uStack00000024 = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffb0);
      CVar2 = CMwId::CreateFromLocalName(local_2c);
      uStack00000024 = 4;
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd3f64,
                 (SInputActionDesc *)CONCAT31(extraout_var_03,CVar2),in_stack_ffffffb0);
      uStack00000028 = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffb4);
      CVar2 = CMwId::CreateFromLocalName((char *)aSStack_24);
      uStack00000028 = 5;
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd3f6c,
                 (SInputActionDesc *)CONCAT31(extraout_var_04,CVar2),in_stack_ffffffb4);
      uStack0000002c = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffb8);
      CVar2 = CMwId::CreateFromLocalName(acStack_1c);
      uStack0000002c = 6;
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd3f60,
                 (SInputActionDesc *)CONCAT31(extraout_var_05,CVar2),in_stack_ffffffb8);
      uStack00000030 = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffbc);
      CVar2 = CMwId::CreateFromLocalName((char *)&pwStack_14);
      uStack00000030 = 7;
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd3f7c,
                 (SInputActionDesc *)CONCAT31(extraout_var_06,CVar2),in_stack_ffffffbc);
      uStack00000034 = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffc0);
      CVar2 = CMwId::CreateFromLocalName((char *)&local_c);
      uStack00000034 = 8;
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd400c,
                 (SInputActionDesc *)CONCAT31(extraout_var_07,CVar2),in_stack_ffffffc0);
      uStack00000038 = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffc4);
      CVar2 = CMwId::CreateFromLocalName((char *)&local_4);
      uStack00000038 = 9;
      CInputEventsStore::RegisterInput
                (pvVar4,(CInputEventsStore *)PTR_DAT_00cd4010,
                 (SInputActionDesc *)CONCAT31(extraout_var_08,CVar2),in_stack_ffffffc4);
      uStack0000003c = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffc8);
      *(undefined4 *)(this + 0x31c) = 0;
      *(undefined4 *)(this + 0x328) = 0;
      *(undefined4 *)(this + 0x318) = *(undefined4 *)(this + 0x304);
      *(undefined4 *)(this + 800) = 0;
      *(undefined4 *)(this + 0x324) = 0xffffffff;
      pCVar11 = CGameRace::GetLocalPlayer((CGameRace *)this,in_stack_ffffffc8);
      piVar1 = *(int **)(*(int *)(pCVar11 + 0x28) + 0x14);
      (**(code **)(*piVar1 + 0x13c))();
      CHmsItem::SetCollisionGroup
                ((CHmsItem *)piVar1[10],(CHmsItem *)0x0,(ECollisionGroup)in_stack_ffffff74);
      StopReplayRecordAndKeepCopy(this,(CTrackManiaRace *)0x1,(int)in_stack_ffffff78);
      if (param_2 != (SMwFiberContext **)0x0) {
        pCVar8 = (CFastStringInt *)
                 CClassicI18n::GetTranslatedStringInternal
                           ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Validating ...",
                            (wchar_t *)in_stack_ffffff7c);
        CFastStringInt::CFastStringInt(&stack0xffffffc8,pCVar8,(SStringParam *)in_stack_ffffff80);
        pCVar19 = (CFastStringInt *)0x0;
        pCVar8 = (CFastStringInt *)0x0;
        pCVar17 = (CGameDialogs *)&DAT_00d71d58;
        piStack_8 = (int *)0xa;
        pCVar10 = CGameApp::GetBasicDialogs(*(CGameApp **)(this + 0x18),(CGameApp *)&local_34);
        CGameDialogs::DoMessage(pCVar10,pCVar17,pCVar8,pCVar19,(CMwNod *)this_02,p_Var22);
        CGameCtnApp::SNationConfig::~SNationConfig(local_2c,pSVar26);
      }
      *(undefined4 *)(*param_2 + 4) = 0x56d;
      ExceptionList = local_4;
      return;
    }
    if (uVar9 != 0x56d) {
      if (uVar9 != 0x5ac) goto LAB_004831a4;
      goto LAB_00482fa6;
    }
    if ((*(int *)(this + 0x2fc) != 0) && (*(int *)(*(int *)(this + 0x2fc) + 0x168) != 0)) {
      iVar14 = 0x24044000;
      pCVar6 = (CFastString *)(**(code **)(*(int *)this + 0x10))();
      pSVar21 = aSStack_24;
      pSVar20 = (SStringParam *)0x48283e;
      (**(code **)(*(int *)this + 0xa4))();
      piStack_8 = (int *)&DAT_0000000b;
      CFastString::SetString
                ((CFastString *)(*param_2 + 0x14),(CFastStringInt *)&stack0xffffffc0,pSVar20);
      local_4 = (void *)0xffffffff;
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(local_2c + 4,pSVar21);
      CGamePlayground::UpdateFromSettings
                ((CGamePlayground *)this,(CGamePlayground *)(*(int *)(this + 0x2fc) + 0x168),pCVar6,
                 iVar14);
    }
    this_00 = operator_new(0x3b8);
    if (this_00 == (CTrackManiaPlayerInfo *)0x0) {
      pCVar7 = (CMwNodRef<class_CGameCamera> *)0x0;
    }
    else {
      CTrackManiaPlayerInfo::CTrackManiaPlayerInfo(this_00,(CTrackManiaPlayerInfo *)unaff_ESI);
      pCVar7 = extraout_EAX_00;
    }
    pCVar16 = this + 0x330;
    CMwNodRef<class_CGameCamera>::MwSetNod(pCVar16,pCVar7,(CGameCamera *)unaff_ESI);
    *(undefined1 *)(*(int *)pCVar16 + 0x24) = 0xfb;
    CGameNetwork::SetPlayerInfoType(*(CGameNetPlayerInfo **)pCVar16,0);
    local_30 = "*validation*";
    local_2c[0] = '\f';
    local_2c[1] = '\0';
    local_2c[2] = '\0';
    local_2c[3] = '\0';
    CFastString::SetString
              ((CFastString *)(*(int *)pCVar16 + 0x28),(CFastStringInt *)&local_30,unaff_EBP);
    iVar14 = *(int *)pCVar16;
    (**(code **)(*(int *)this + 0x98))();
    CTrackManiaPlayerInfo::SetSpawnLoc
              (*(CTrackManiaPlayerInfo **)pCVar16,(CTrackManiaPlayerInfo *)(this + 0x28c),
               (GmIso4 *)0x1,iVar14);
    unaff_EBP = (SStringParam *)0x0;
    *(undefined4 *)(this + 0x334) = *(undefined4 *)(param_6 + 0x14);
    unaff_ESI = (CFastStringInt *)&param_8;
    dVar24 = (double)CONCAT44(&param_7,in_stack_ffffffac);
    (**(code **)(*(int *)this + 0x110))();
    pCVar18 = *(CGameRace **)(*(int *)pCVar16 + 0x238);
    (**(code **)(*(int *)this + 0x164))();
    local_4 = *(void **)(*(int *)(*(int *)pCVar16 + 0x238) + 0x28);
    piStack_8 = *(int **)((int)local_4 + 0x14);
    if (*(int *)(this + 0x32c) != 0) {
      pCVar11 = CGameRace::GetLocalPlayer((CGameRace *)this,pCVar18);
      CGamePlayerCameraSet::PlayerGameMobilIdSet
                (*(CGamePlayerCameraSet **)(pCVar11 + 0x20),
                 *(CGamePlayerCameraSet **)(unaff_retaddr + 0x18),(ulong)this_00);
      (**(code **)(**(int **)(*(int *)(this + 0x34) + 0x74) + 0xb0))();
    }
    (**(code **)(*piStack_8 + 0x13c))(1);
    *(void **)(this + 0x314) = local_4;
    *(int *)(*param_2 + 0x10) = (int)((ulonglong)dVar24 >> 0x20);
    (**(code **)(*(int *)this + 0x84))();
    in_stack_ffffff7c = (CFastStringInt *)0x0;
    in_stack_ffffff78 = (CGameRace *)0x0;
    in_stack_ffffff74 = (CGameRace *)0x4829f9;
    CMwCmdBufferCore::StartSimulation
              (DAT_00d731e0,(CMwCmdBufferCore *)0x0,0,0x3f800000,(float)param_4);
    this_02 = (char *)0x0;
    in_stack_ffffff80 = (char *)0x482a02;
    CGameRace::SetStatus((CGameRace *)this,(CGameRace *)0x0,SUB84(dVar24,0));
    pSVar20 = (SStringParam *)((ulonglong)dVar24 >> 0x20);
    if ((*(uint *)(this + 0x308) != 0xffffffff) &&
       (*(uint *)(this + 0x304) < *(uint *)(this + 0x308))) {
      *(undefined4 *)(*param_2 + 0x1c) = 0;
      local_34 = 0x1b;
      local_30 = (char *)0x1;
      CFastStringInt::SetString(*param_2 + 0x20,(CFastStringInt *)&stack0xffffffc8,pSVar20);
      *(undefined4 *)(*param_2 + 4) = 0x5ac;
      ExceptionList = local_4;
      return;
    }
    if (*(int *)(this + 0x32c) == 0) {
      this_02 = (char *)0x482a74;
      CMwCmdBufferCore::SetSimulationRelativeSpeed(DAT_00d731e0,_DAT_00b3618c,(float)pSVar20);
      dVar24 = 2.12433246109751e-314;
      CMwCmdBufferCore::SetIsSimulationOnly(DAT_00d731e0,(CMwCmdBufferCore *)0x1,(int)unaff_ESI);
    }
LAB_00482dd5:
    if ((in_stack_ffffffa4 <
         (CFastStringInt *)(*(int *)(this + 0x318) + 100 + *(int *)(this + 0x314))) &&
       (*(int *)(*(int *)(this + 0x330) + 0x314) != 2)) {
      *(undefined4 *)(*param_2 + 4) = 0x5b7;
      ExceptionList = local_4;
      return;
    }
  }
  pCVar16 = this + 0x330;
  *(undefined4 *)(*param_2 + 0x1c) = 2;
  if ((float)_DAT_00b362c0 <= *(float *)(this + 0x31c)) {
    *(undefined4 *)(*param_2 + 0x1c) = 2;
    this_02 = *(char **)(this + 0x324);
    dVar24 = (double)*(float *)(this + 0x328);
    in_stack_ffffff7c = (CFastStringInt *)(*param_2 + 0x20);
    in_stack_ffffff80 = "Deviates : time=%d, dist=%.3g";
    in_stack_ffffff78 = (CGameRace *)0x482fa3;
    CFastStringInt::ConcatFormat(this_02,in_stack_ffffff7c,"Deviates : time=%d, dist=%.3g");
  }
  else if (((*(int *)(*(int *)pCVar16 + 0x314) == 2) || (*(int *)(this + 0xf4) != 0)) ||
          ((*(int *)(*(int *)(this + 0xc4) + 0xf4) != 0 && (*(int *)(this + 0xec) == 1)))) {
    *(undefined4 *)(*param_2 + 0x1c) = 1;
    if (*(int *)(this + 0x308) != -1) {
      iVar14 = *(int *)(*(int *)pCVar16 + 0x2a8);
      if (iVar14 == -1) {
        *(undefined4 *)(*param_2 + 0x1c) = 0;
        this_02 = (char *)(*param_2 + 0x20);
        dVar24 = (double)CONCAT44(*(void **)(this + 0x308),
                                  "Expecting %d RaceTime instead of unfinished race");
        in_stack_ffffff80 = (char *)0x482ebe;
        CFastStringInt::ConcatFormat
                  (*(void **)(this + 0x308),(CFastStringInt *)this_02,
                   "Expecting %d RaceTime instead of unfinished race");
      }
      else {
        uVar9 = *(int *)(this + 0x308) - iVar14;
        uVar15 = (int)uVar9 >> 0x1f;
        if (10 < (int)((uVar9 ^ uVar15) - uVar15)) {
          *(undefined4 *)(*param_2 + 0x1c) = 0;
          dVar24 = (double)CONCAT44(iVar14,*(void **)(this + 0x308));
          in_stack_ffffff80 = (char *)(*param_2 + 0x20);
          this_02 = "Expecting %d RaceTime instead of %d";
          in_stack_ffffff7c = (CFastStringInt *)0x482ef0;
          CFastStringInt::ConcatFormat
                    (*(void **)(this + 0x308),(CFastStringInt *)in_stack_ffffff80,
                     "Expecting %d RaceTime instead of %d");
        }
      }
    }
    if ((*(int *)(this + 0x30c) != -1) &&
       (iVar14 = *(int *)(*(int *)pCVar16 + 0x2a8), *(int *)(this + 0x30c) != iVar14)) {
      pSVar5 = *param_2;
      *(undefined4 *)(pSVar5 + 0x1c) = 0;
      dVar24 = (double)CONCAT44(iVar14,*(undefined4 *)(this + 0x30c));
      in_stack_ffffff80 = (char *)(*param_2 + 0x20);
      this_02 = "Expecting %d StuntsScore instead of %d";
      in_stack_ffffff7c = (CFastStringInt *)0x482f2a;
      CFastStringInt::ConcatFormat
                (pSVar5,(CFastStringInt *)in_stack_ffffff80,"Expecting %d StuntsScore instead of %d"
                );
    }
    if (((*(int *)(this + 0x2fc) != 0) &&
        (iVar14 = *(int *)(*(int *)(this + 0x2fc) + 0xec), iVar14 != -1)) &&
       (iVar14 != *(int *)(this + 800))) {
      *(undefined4 *)(*param_2 + 0x1c) = 0;
      dVar24 = (double)CONCAT44(*(undefined4 *)(this + 800),
                                *(void **)(*(int *)(this + 0x2fc) + 0xec));
      in_stack_ffffff80 = (char *)(*param_2 + 0x20);
      this_02 = "Expecting %d Respawns instead of %d";
      in_stack_ffffff7c = (CFastStringInt *)0x482f76;
      CFastStringInt::ConcatFormat
                (*(void **)(*(int *)(this + 0x2fc) + 0xec),(CFastStringInt *)in_stack_ffffff80,
                 "Expecting %d Respawns instead of %d");
    }
  }
  else {
    *(undefined4 *)(*param_2 + 0x1c) = 0;
    uVar27 = 0x482e6b;
    SStringParam::SStringParam
              (auStack_18,(SStringParam *)"Expecting completed race",(char *)unaff_ESI);
    unaff_ESI = (CFastStringInt *)&pwStack_14;
    dVar24 = (double)CONCAT44(0x482e7a,uVar27);
    CFastStringInt::Concat(*param_2 + 0x20,unaff_ESI,unaff_EBP);
  }
LAB_00482fa6:
  if (param_7 != 0) {
    dVar24 = (double)CONCAT44(0x482fb8,SUB84(dVar24,0));
    pCVar10 = CGameApp::GetBasicDialogs(*(CGameApp **)(this + 0x18),(CGameApp *)unaff_ESI);
    CGameDialogs::HideDialogs(pCVar10,(CGameCtnMenus *)unaff_EBP);
  }
  ValidateCleanup(this,in_stack_ffffff6c);
  if (*(int *)(*param_2 + 0x14) != 0) {
    CGamePlayground::UpdateFromSettings
              ((CGamePlayground *)this,(CGamePlayground *)(*param_2 + 0x14),(CFastString *)0x0,
               (int)in_stack_ffffff70);
  }
  pCVar11 = CGameRace::GetLocalPlayer((CGameRace *)this,in_stack_ffffff74);
  CHmsItem::SetCollisionGroup
            (*(CHmsItem **)(*(int *)(*(int *)(pCVar11 + 0x28) + 0x14) + 0x28),(CHmsItem *)0x3,
             (ECollisionGroup)in_stack_ffffff78);
  pCVar11 = CGameRace::GetLocalPlayer((CGameRace *)this,(CGameRace *)in_stack_ffffff7c);
  CHmsItem::SetDynamicType
            (*(CHmsItem **)(*(int *)(*(int *)(pCVar11 + 0x28) + 0x14) + 0x28),(CHmsItem *)0x2,
             (EDynamicType)in_stack_ffffff80);
  CMwCmdBufferCore::SetSimulationRelativeSpeed
            (DAT_00d731e0,(CMwCmdBufferCore *)0x3f800000,(float)this_02);
  CMwCmdBufferCore::SetSimulationCurrentTime
            (DAT_00d731e0,*(CMwCmdBufferCore **)(*param_2 + 0x10),SUB84(dVar24,0));
  CInputPort::ClearInputs
            (*(CInputPort **)(this + 0x20),(CInputPort *)0x1,(int)((ulonglong)dVar24 >> 0x20));
  *(undefined4 *)(*param_2 + 4) = 0x60d;
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CTrackManiaRace::ValidateCleanup
// =================================================
void __thiscall CTrackManiaRace::ValidateCleanup(CTrackManiaRace *this,CTrackManiaRace *param_1)
{
{
  CMwNod *unaff_ESI;
  int unaff_retaddr;
  
  if (*(int *)(this + 0x330) != 0) {
    (**(code **)(*(int *)this + 0xa0))(*(int *)(this + 0x330));
  }
  if (*(CMwNod **)(this + 0x330) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x330),unaff_ESI);
    *(undefined4 *)(this + 0x330) = 0;
  }
  STmValidateParam::Clear(this + 0x2fc,(TiXmlNode *)unaff_ESI);
  *(undefined4 *)(this + 0x31c) = 0;
  *(undefined4 *)(this + 800) = 0;
  CMwCmdBufferCore::SetIsSimulationOnly(DAT_00d731e0,(CMwCmdBufferCore *)0x0,unaff_retaddr);
  return;
}
}

