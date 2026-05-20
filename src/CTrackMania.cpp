// Class implementation: CTrackMania

// =================================================
// Function: CTrackMania::CancelOfficialRecord
// =================================================
void __thiscall CTrackMania::CancelOfficialRecord(CTrackMania *this,CTrackMania *param_1)
{
{
  ulong unaff_retaddr;
  
  DoStopOfficialRecord(this,(CTrackMania *)0xfffffffe,0xfffffffe,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CTrackMania::DoStopOfficialRecord
// =================================================
void __thiscall
CTrackMania::DoStopOfficialRecord
          (CTrackMania *this,CTrackMania *param_1,ulong param_2,ulong param_3)
{
{
  int iVar1;
  CGameCtnMasterServer *this_00;
  CGameMasterServerRequest *this_01;
  SOldChars *unaff_ESI;
  SOldChars *unaff_EDI;
  SOfficialRecordState *unaff_retaddr;
  
  *(CTrackMania **)(this + 0x508) = param_1;
  *(ulong *)(this + 0x504) = param_2;
  *(undefined4 *)(this + 0x268) = 0;
  if (*(int *)(this + 0x270) != 0) {
    if (*(int *)(this + 0x540) != 0) {
      CFastStringBase<wchar_t>::AllocAtLeast
                (this + 0x540,(CFastStringBase<wchar_t> *)0x0,1,0,unaff_EDI);
      **(undefined2 **)(this + 0x544) = 0;
      *(undefined4 *)(this + 0x540) = 0;
    }
    if (*(int *)(this + 0x548) != 0) {
      CFastStringBase<wchar_t>::AllocAtLeast
                (this + 0x548,(CFastStringBase<wchar_t> *)0x0,1,0,unaff_ESI);
      **(undefined2 **)(this + 0x54c) = 0;
      *(undefined4 *)(this + 0x548) = 0;
    }
    this_00 = CGameCtnApp::GetMasterServer((CGameCtnApp *)this,(CGameCtnApp *)(this + 0x4f8));
    this_01 = CGameCtnMasterServer::StopOfficialRecord
                        (this_00,(CGameCtnMasterServer *)unaff_ESI,unaff_retaddr);
    if (this_01 != (CGameMasterServerRequest *)0x0) {
      CGameMasterServerRequest::SetRequestSuccessCallBack
                (this_01,(CGameMasterServerRequest *)this,(CMwNod *)_vcall__464__flat______,
                 (_func___cdecl_void_CGameMasterServerRequest_ptr *)param_1);
      CGameMasterServerRequest::SetRequestFailureCallBack
                (this_01,(CGameMasterServerRequest *)this,
                 (CMwNod *)CGameCtnMenus::_vcall__472__flat______,
                 (_func___cdecl_void_CGameMasterServerRequest_ptr *)param_2);
      return;
    }
    iVar1 = *(int *)this;
    CGameCtnApp::GetMasterServer((CGameCtnApp *)this,(CGameCtnApp *)param_1);
    (**(code **)(iVar1 + 0x1e0))();
  }
  return;
}
}

// =================================================
// Function: CTrackMania::GetPlayerInfo
// =================================================
int __thiscall
CTrackMania::GetPlayerInfo
          (CTrackMania *this,CTrackManiaNetwork *param_1,CFastString *param_2,
          SRpcPlayerInfo *param_3,CFastString *param_4)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 300) + 0x240),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_retaddr);
  return *(int *)pSVar1;
}
}

// =================================================
// Function: CTrackMania::GetServerInfo
// =================================================
CTrackManiaNetworkServerInfo * __thiscall
CTrackMania::GetServerInfo(CTrackMania *this,CTrackManiaNetwork *param_1)
{
{
  return *(CTrackManiaNetworkServerInfo **)(*(int *)(this + 300) + 0x23c);
}
}

// =================================================
// Function: CTrackMania::GetTMCurrentProfile
// =================================================
CTrackManiaPlayerProfile * __thiscall
CTrackMania::GetTMCurrentProfile(CTrackMania *this,CTrackMania *param_1)
{
{
  return *(CTrackManiaPlayerProfile **)(this + 0x168);
}
}

// =================================================
// Function: CTrackMania::GetTmBlockEditor
// =================================================
CTrackManiaEditor * __thiscall CTrackMania::GetTmBlockEditor(CTrackMania *this,CTrackMania *param_1)
{
{
  int iVar1;
  
  if (*(int **)(this + 0x414) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(this + 0x414) + 0x10))(0x24013000);
    if (iVar1 != 0) {
      return *(CTrackManiaEditor **)(this + 0x414);
    }
  }
  return (CTrackManiaEditor *)0x0;
}
}

// =================================================
// Function: CTrackMania::IsInHotSeatMode
// =================================================
int __thiscall CTrackMania::IsInHotSeatMode(CTrackMania *this,CTrackMania *param_1)
{
{
  if ((*(int *)(this + 0x418) != 0xe) && (*(int *)(this + 0x418) != 0xf)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CTrackMania::IsInSoloMode
// =================================================
int __thiscall CTrackMania::IsInSoloMode(CTrackMania *this,CTrackMania *param_1)
{
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x418);
  if ((((((iVar1 != 3) && (iVar1 != 0xc)) && (iVar1 != 0xd)) && ((iVar1 != 1 && (iVar1 != 7)))) &&
      ((iVar1 != 4 && ((iVar1 != 5 && (iVar1 != 10)))))) && (iVar1 != 9)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CTrackMania::IsInStuntsMode
// =================================================
int __thiscall CTrackMania::IsInStuntsMode(CTrackMania *this,CTrackMania *param_1)
{
{
  int iVar1;
  CTrackMania *this_00;
  int extraout_ECX;
  CTrackMania *unaff_retaddr;
  
  if ((*(int *)(this + 0x198) == 0) || (*(int *)(*(int *)(this + 0x198) + 0xf8) != 5)) {
    return 0;
  }
  iVar1 = IsInSoloMode(this,unaff_retaddr);
  if ((iVar1 == 0) &&
     ((iVar1 = IsInHotSeatMode(this_00,param_1), iVar1 == 0 &&
      (*(int *)(extraout_ECX + 0x418) != 0x13)))) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CTrackMania::SetChallengeType
// =================================================
void __thiscall
CTrackMania::SetChallengeType(CTrackMania *this,CTrackMania *param_1,EChallengeType param_2)
{
{
  *(CTrackMania **)(this + 0x418) = param_1;
  return;
}
}

// =================================================
// Function: CTrackMania::UpdateWaterMap
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CTrackMania::UpdateWaterMap(CTrackMania *this,CTrackMania *param_1)
{
{
  float fVar1;
  int *piVar2;
  bool bVar3;
  float fVar4;
  CGameCtnChallenge *pCVar5;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *pCVar7;
  undefined1 auVar8 [4];
  SCasterCat *pSVar9;
  int iVar10;
  CGameCtnZone *pCVar11;
  CGameCtnBlock *pCVar12;
  int iVar13;
  CHmsCorpus *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  int iVar15;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  CFastBuffer<class_CCrystalFace*> *pCVar17;
  CGameCtnChallenge *pCVar18;
  ulong unaff_EDI;
  CHmsItem *pCVar19;
  CGameCtnChallenge *pCVar20;
  GmVec4 *pGVar21;
  CFastBuffer<class_CCrystalFace*> *pCVar22;
  CFastBuffer<class_CCrystalFace*> *pCVar23;
  undefined1 auStack_58 [4];
  CFastBuffer<class_CCrystalFace*> *pCStack_54;
  CFastBuffer<class_CCrystalFace*> *pCStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  float fStack_44;
  CGameCtnChallenge *pCStack_40;
  CFastBuffer<class_CCrystalFace*> *pCStack_3c;
  int iStack_38;
  CGameCtnChallenge *pCStack_34;
  CFastBuffer<class_CCrystalFace*> *pCStack_30;
  CGameCtnChallenge *pCStack_2c;
  CFastBuffer<class_CCrystalFace*> *pCStack_28;
  undefined4 uStack_24;
  CGameCtnChallenge *pCStack_20;
  undefined4 uStack_1c;
  CFastBuffer<class_CCrystalFace*> *pCStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  
  auVar8 = (undefined1  [4])(**(code **)(*(int *)this + 0x84))();
  uStack_24 = *(undefined4 *)((int)auVar8 + 0xa8);
  iStack_38 = *(int *)((int)auVar8 + 0x114);
  pCStack_20 = *(CGameCtnChallenge **)((int)auVar8 + 0xac);
  iVar13 = *(int *)((int)auVar8 + 0x90);
  uStack_1c = *(undefined4 *)((int)auVar8 + 0xb0);
  auStack_58 = auVar8;
  pCStack_3c = (CFastBuffer<class_CCrystalFace*> *)iVar13;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(*(int *)(this + 0x170) + 0x14) + 0xac),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
  iVar10 = (**(code **)(**(int **)(*(int *)pSVar9 + 0x38) + 0xa8))();
  pCStack_50 = *(CFastBuffer<class_CCrystalFace*> **)(iVar13 + 0x7c);
  fStack_44 = *(float *)(iVar13 + 0xa0);
  if (fStack_44 == 0.0) {
    auStack_58[3] = 1;
    if (*(int *)(iVar13 + 0x9c) != 0) goto LAB_004bd8d9;
  }
  auStack_58 = (undefined1  [4])((uint)auStack_58 & 0xffffff);
LAB_004bd8d9:
  pCStack_40 = pCStack_20;
  pCStack_3c = pCStack_18;
  pCStack_30 = (CFastBuffer<class_CCrystalFace*> *)0x0;
  pCStack_2c = (CGameCtnChallenge *)0x0;
  uStack_4c = pCStack_50;
  iStack_48 = iVar10;
  GmMap2<unsigned_char>::Init
            ((void *)(iVar10 + 0x154),(CLoadGeomDynaSprite *)&pCStack_30,
             (CPlugVisualSprite *)&pCStack_50,(CVisionViewportDx9 *)&pCStack_40,
             (ESpriteColor0 *)(auStack_58 + 3));
  pCStack_50 = (CFastBuffer<class_CCrystalFace*> *)0x0;
  if (pCStack_18 != (CFastBuffer<class_CCrystalFace*> *)0x0) {
    do {
      pCVar18 = (CGameCtnChallenge *)0x0;
      pCVar17 = pCStack_50;
      if (pCStack_20 != (CGameCtnChallenge *)0x0) {
        do {
          pCVar23 = pCVar17;
          pCVar11 = CGameCtnChallenge::GetRealZone((CGameCtnChallenge *)auVar8,pCVar18,(GmNat3)0x0);
          if ((pCVar11 == (CGameCtnZone *)0x0) || (*(int *)(pCVar11 + 0x2c) == 0)) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          pCVar5 = pCStack_34;
          pCVar6 = pCStack_30;
          pCVar20 = pCVar18;
          pCVar7 = pCVar17;
          if ((iStack_48 != 0) &&
             (pCVar5 = pCVar18, pCVar6 = pCVar17, pCVar20 = pCStack_2c, pCVar7 = pCStack_28, bVar3))
          {
            pCVar20 = pCVar18;
            pCVar22 = pCVar17;
            pCVar12 = CGameCtnChallenge::GetGroundBlock
                                ((CGameCtnChallenge *)auVar8,pCVar18,(GmNat3)0x0);
            piVar2 = *(int **)(pCVar12 + 0x30);
            pGVar21 = (GmVec4 *)0x4bd992;
            iVar13 = (**(code **)(*piVar2 + 0x78))();
            pCVar19 = *(CHmsItem **)(iVar13 + 0x38);
            this_00 = CHmsItem::GetCorpus((CHmsItem *)piVar2[10],pCVar19,(CHmsZone *)pCVar20);
            iVar13 = CHmsCorpus::WaterGetPlaneEqInZone(this_00,(CHmsCorpus *)&pCStack_20,pGVar21);
            auVar8 = auStack_58;
            pCVar20 = pCStack_2c;
            pCVar7 = pCStack_28;
            if (iVar13 != 0) {
              pCVar19 = pCVar19 + 0xdc;
              pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        CFastBuffer<class_CCrystalFace*>::GetCount(pCVar19,pCVar23);
              pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              pCVar17 = pCStack_54;
              auVar8 = auStack_58;
              pCVar6 = pCStack_54;
              pCVar20 = pCStack_2c;
              pCVar7 = pCStack_28;
              if (pCVar14 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
                do {
                  pSVar9 = CFastBuffer<class_GxColor>::operator[](pCVar19,pCVar16,(ulong)pCVar22);
                  fStack_44 = *(float *)(pSVar9 + 8) * fStack_10 +
                              *(float *)pSVar9 * (float)pCStack_18 +
                              *(float *)(pSVar9 + 4) * fStack_14;
                  pCVar17 = pCStack_54;
                  auVar8 = auStack_58;
                  pCVar20 = pCStack_2c;
                  pCVar7 = pCStack_28;
                  if (((float)_DAT_00b44a20 <= fStack_44) &&
                     (fStack_44 = ABS(fStack_c - *(float *)(pSVar9 + 0xc)), pCVar6 = pCStack_54,
                     fStack_44 <= (float)_DAT_00b362c0)) break;
                  pCVar16 = pCVar16 + 1;
                  pCVar6 = pCStack_54;
                } while (pCVar16 < pCVar14);
              }
            }
          }
          pCStack_28 = pCVar7;
          pCStack_2c = pCVar20;
          pCStack_30 = pCVar6;
          pCStack_34 = pCVar5;
          GmMap2<unsigned_char>::SetValue
                    ((void *)((int)fStack_44 + 0x154),(CMwCmdAffectParamBool *)pCVar23);
          pCVar18 = pCVar18 + 1;
          iVar13 = iStack_38;
        } while (pCVar18 < pCStack_20);
      }
      pCStack_50 = pCVar17 + 1;
      iVar10 = iStack_48;
    } while (pCStack_50 < pCStack_18);
  }
  fVar1 = *(float *)(iVar13 + 0x98);
  iVar15 = *(int *)(*(int *)(pCStack_34 + 0x58) + 0x38) + 1;
  fVar4 = (float)iVar15;
  if (iVar15 < 0) {
    fVar4 = fVar4 + _DAT_00c418d0;
  }
  fVar4 = fVar4 * *(float *)(iVar13 + 0x80);
  *(float *)(iVar10 + 0x178) = *(float *)(iVar13 + 0x94) + fVar4;
  *(float *)(iVar10 + 0x17c) = fVar4 + fVar1;
  *(undefined4 *)(iVar10 + 0x180) = *(undefined4 *)(iVar13 + 0xa4);
  return;
}
}

