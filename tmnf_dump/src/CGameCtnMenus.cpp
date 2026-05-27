// Class implementation: CGameCtnMenus

// =================================================
// Function: CGameCtnMenus::DialogCardGrid_Clean
// =================================================
void __thiscall CGameCtnMenus::DialogCardGrid_Clean(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  CMwId CVar1;
  CMwId *pCVar2;
  undefined3 extraout_var;
  CMotionPlayer *this_00;
  undefined3 extraout_var_00;
  CPlugTree *this_01;
  CFastStringInt *unaff_ESI;
  char local_14 [8];
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00aa9910;
  local_c = ExceptionList;
  pCVar2 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  if (*(int *)(this + 0x78c) != 0) {
    CVar1 = CMwId::CreateFromLocalName(local_14);
    local_4 = 0;
    this_00 = CFastBuffer<class_CMotionPlayer*>::GetNodFromId
                        ((void *)(*(int *)(this + 0x78c) + 0x68),
                         (CFastBuffer<class_CMotionPlayer*> *)CONCAT31(extraout_var,CVar1),pCVar2);
    OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
    CVar1 = CMwId::CreateFromLocalName((char *)&local_c);
    this_01 = CControlContainer::GetChildFromId
                        ((CControlContainer *)this_00,(CPlugTree *)CONCAT31(extraout_var_00,CVar1),
                         (CMwId *)0x1);
    OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
    if (this_01 != (CPlugTree *)0x0) {
      CGameControlGrid::Remote_Clean((CGameControlGrid *)this_01,(CGameControlGrid *)unaff_ESI);
      (**(code **)(*(int *)this_01 + 0x2b0))(0xffffffff);
    }
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CGameCtnMenus::DialogGrid_Clean
// =================================================
void __thiscall CGameCtnMenus::DialogGrid_Clean(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  CMwId CVar1;
  CMwId *pCVar2;
  undefined3 extraout_var;
  CMotionPlayer *pCVar3;
  CFastStringInt *unaff_ESI;
  char local_14 [8];
  CControlContainer *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00aa97d8;
  local_c = ExceptionList;
  pCVar2 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  if (*(int *)(this + 0x78c) != 0) {
    CVar1 = CMwId::CreateFromLocalName(local_14);
    local_4 = (void *)0x0;
    pCVar3 = CFastBuffer<class_CMotionPlayer*>::GetNodFromId
                       ((void *)(*(int *)(this + 0x78c) + 0x68),
                        (CFastBuffer<class_CMotionPlayer*> *)CONCAT31(extraout_var,CVar1),pCVar2);
    OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
    CControlTools::ControlRetrieve<class_CControlGrid>
              ((CControlContainer *)pCVar3,"GridContainer",(CControlGrid **)&local_c,1,0,1);
    CControlContainer::RemoveAllChilds(local_c,(CControlContainer *)unaff_ESI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CGameCtnMenus::DialogInGameMenu_OnAdvanced
// =================================================
void __thiscall
CGameCtnMenus::DialogInGameMenu_OnAdvanced(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  *(undefined4 *)(this + 0x700) = 0x43;
  return;
}
}

// =================================================
// Function: CGameCtnMenus::DialogLadderRankings_PushStep
// =================================================
void __thiscall
CGameCtnMenus::DialogLadderRankings_PushStep
          (CGameCtnMenus *this,CGameCtnMenus *param_1,CGameMasterServerRequestParams *param_2)
{
{
  SLoadedLight *pSVar1;
  undefined *puVar2;
  void *pvVar3;
  char *unaff_EBP;
  ulong *unaff_ESI;
  char *unaff_EDI;
  undefined4 uStack0000000c;
  void *in_stack_00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  CFastStringInt *in_stack_ffffffe4;
  char *in_stack_ffffffe8;
  ulong *in_stack_ffffffec;
  CFastString local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined *local_4;
  
  local_4 = (undefined *)0xffffffff;
  local_8 = &LAB_00aaaa18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 != (CGameCtnMenus *)0x0) {
    pSVar1 = CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStep>::AddNewElem
                       (this + 0x6b0,
                        (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                        (DAT_00cca150 ^ (uint)&stack0xffffffd8));
    CFastString::CFastString(local_10,(CFastString *)&DAT_00b47d40,unaff_EDI);
    CGameMasterServerRequestParams::GetParamAsNatural
              ((CGameMasterServerRequestParams *)param_1,(CGameMasterServerRequestParams *)&local_c,
               (CFastString *)pSVar1,unaff_ESI);
    if (local_4 != PTR_DAT_00bbf7d8) {
      puVar2 = local_4 + -1;
      if ((local_4[-1] & 0x80) != 0) {
        puVar2 = local_4 + -4;
      }
      operator_delete__(puVar2);
    }
    CFastString::CFastString((CFastString *)&local_8,(CFastString *)&DAT_00b2ef98,unaff_EBP);
    uStack0000000c = 1;
    CGameMasterServerRequestParams::GetParamAsStringInt
              ((CGameMasterServerRequestParams *)param_1,(CGameMasterServerRequestParams *)&local_4,
               (CFastString *)(pSVar1 + 4),in_stack_ffffffe4);
    in_stack_00000010 = (void *)0xffffffff;
    if (PTR_DAT_00bbf7d8 != (undefined *)0x0) {
      pvVar3 = (void *)0xffffffff;
      if ((bRamffffffff & 0x80) != 0) {
        pvVar3 = (void *)0xfffffffc;
      }
      operator_delete__(pvVar3);
    }
    CFastString::CFastString((CFastString *)&local_8,(CFastString *)&DAT_00b70dcc,in_stack_ffffffe8)
    ;
    uStack00000014 = 2;
    CGameMasterServerRequestParams::GetParamAsNatural
              ((CGameMasterServerRequestParams *)param_1,(CGameMasterServerRequestParams *)&local_4,
               (CFastString *)(pSVar1 + 0xc),in_stack_ffffffec);
    uStack00000018 = 0xffffffff;
    if (PTR_DAT_00bbf7d8 != (undefined *)0x0) {
      pvVar3 = (void *)0xffffffff;
      if ((bRamffffffff & 0x80) != 0) {
        pvVar3 = (void *)0xfffffffc;
      }
      operator_delete__(pvVar3);
    }
    CControlBase::SetReadOnly(*(CControlContainer **)(this + 0x6a4),"ButtonBack",0);
  }
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CGameCtnMenus::DialogPlayerProfile_DestroyVehicleScene
// =================================================
void __thiscall
CGameCtnMenus::DialogPlayerProfile_DestroyVehicleScene(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  CGameCtnMenus *this_00;
  int iVar1;
  CMwNod *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CHmsZoneVPacker *unaff_EBP;
  CHmsCorpusLight *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CSceneObject *unaff_EDI;
  CHmsZoneOverlay *unaff_retaddr;
  CMwNod *in_stack_00000008;
  
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (*(int *)(this + 0x620) != 0) {
    if (*(CSceneObject **)(this + 0x5a8) != (CSceneObject *)0x0) {
      CSceneObject::RemoveFromScene(*(CSceneObject **)(this + 0x5a8),unaff_EDI);
      *(undefined4 *)(this + 0x5a8) = 0;
    }
    this_00 = this + 0x5e0;
    pCVar2 = (CMwNod *)CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
    if (pCVar2 != (CMwNod *)0x0) {
      do {
        iVar1 = *(int *)(this + 0x5a4);
        if (iVar1 != 0) {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar4,(ulong)unaff_EBP);
          unaff_EBP = *(CHmsZoneVPacker **)pSVar3;
          CHmsZone::RemoveLight(*(CHmsZone **)(iVar1 + 0xa0),unaff_EBP,unaff_ESI);
        }
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,(ulong)unaff_EBP);
        if (*(int **)pSVar3 != (int *)0x0) {
          unaff_EBP = (CHmsZoneVPacker *)0x1;
          (**(code **)(**(int **)pSVar3 + 4))();
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,(GmFrustumIso4 *)unaff_ESI);
    if (*(int *)(this + 0x5a4) != 0) {
      CHmsViewport::OverlayRemove
                (*(CHmsViewport **)(*(int *)(this + 0x784) + 100),
                 *(CHmsViewport **)(*(int *)(this + 0x5a4) + 0xa0),unaff_retaddr);
      if (*(CMwNod **)(this + 0x5a4) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x5a4),pCVar2);
        *(undefined4 *)(this + 0x5a4) = 0;
      }
    }
    if (*(CMwNod **)(this + 0x61c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x61c),in_stack_00000008);
      *(undefined4 *)(this + 0x61c) = 0;
    }
    *(undefined4 *)(this + 0x620) = 0;
  }
  return;
}
}

// =================================================
// Function: CGameCtnMenus::DialogRefereeStatus_PushMessage
// =================================================
void __thiscall
CGameCtnMenus::DialogRefereeStatus_PushMessage
          (CGameCtnMenus *this,CGameCtnMenus *param_1,CFastStringInt *param_2)
{
{
  CGameCtnMenus *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int extraout_EAX;
  ulong uVar3;
  SCasterCat *this_01;
  int iVar4;
  undefined *puVar5;
  SStringParam *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  int iVar7;
  CFastStringInt *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  SStringParam *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  ulong unaff_EDI;
  void *unaff_retaddr;
  void *in_stack_00000010;
  SStringParam *in_stack_ffffffa8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_50;
  CGameCtnMenus *local_4c;
  void *pvStack_44;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_40;
  void *local_3c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined *local_24;
  undefined4 local_20;
  undefined *local_1c;
  undefined *puStack_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined *puStack_8;
  undefined *local_4;
  
  local_4 = (undefined *)0xffffffff;
  puStack_8 = &LAB_00aaa138;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = this + 0x560;
  local_4c = this_00;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)
                              (DAT_00cca150 ^ (uint)&stack0xffffff98));
  pCVar10 = pCVar1;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    while( true ) {
      iVar7 = DAT_00d71d58;
      local_50 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)DAT_00d71d58;
      local_4c = (CGameCtnMenus *)0x0;
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar10 + -1,unaff_EDI);
      if (iVar7 != *(int *)pSVar2) break;
      unaff_EDI = 0;
      CFastStringInt::Compare
                (pSVar2,(SParam_Fids *)&local_50,(SParam *)0x0,(int *)unaff_ESI,(int *)unaff_EBP);
      if ((extraout_EAX != 0) ||
         (pCVar10 = pCVar10 + -1, pCVar10 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0))
      break;
    }
  }
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
  for (uVar3 = CFastStringInt::FindFirst(param_2,(CFastStringInt *)&DAT_0000000a,0,unaff_EDI);
      uVar3 != 0xffffffff;
      uVar3 = CFastStringInt::FindFirst
                        (param_2,(CFastStringInt *)&DAT_0000000a,uVar3 + 1,(ulong)unaff_ESI)) {
    pCVar6 = pCVar6 + 1;
  }
  pCVar9 = pCVar6;
  if (pCVar1 <= pCVar6 + (int)pCVar10) {
    local_50 = pCVar6;
    if (pCVar1 <= pCVar6) {
      local_50 = pCVar1;
    }
    if (pCVar1 + -(int)pCVar10 < local_50) {
      pCVar8 = pCVar10 + ((int)local_50 - (int)pCVar1);
    }
    else {
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    }
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    local_40 = pCVar1 + -(int)local_50;
    pCVar9 = local_50;
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_40 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                           (pvStack_44,pCVar11 + (int)pCVar8,(ulong)unaff_ESI);
        this_01 = CFastBuffer<struct_SFastCat>::operator[](local_40,pCVar11,(ulong)unaff_EBP);
        local_34 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar2 + 4);
        local_30 = *(undefined4 *)pSVar2;
        unaff_EBP = (CFastStringInt *)&local_34;
        uStack_2c = 0;
        unaff_ESI = (SStringParam *)0x62fd76;
        CFastStringInt::SetString(this_01,unaff_EBP,unaff_EBX);
        pCVar11 = pCVar11 + 1;
        pCVar9 = local_50;
        pCVar10 = local_34;
      } while (pCVar11 < local_34);
    }
  }
  local_20 = 0;
  local_1c = PTR_DAT_00bbf7dc;
  local_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_c;
  local_50 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00b32c2c;
  local_4c = (CGameCtnMenus *)0x1;
  local_c = (void *)0x0;
  puStack_8 = PTR_DAT_00bbf7dc;
  CFastStringInt::SetString(local_40,(CFastStringInt *)&local_50,unaff_ESI);
  local_20 = 0;
  local_14 = 0xffffffff;
  local_10 = 0;
  local_c = (void *)0x0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  for (pCVar8 = pCVar6 + -(int)pCVar9;
      pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0; pCVar8 = pCVar8 + -1) {
    CFastStringInt::GetNextToken
              (in_stack_00000010,(CFastStringInt *)&local_20,(SFastTokenInt *)unaff_EBP);
    pCVar1 = pCVar6 + -(int)pCVar9;
  }
  if (pCVar1 < pCVar6) {
    iVar7 = (int)pCVar6 - (int)pCVar1;
    do {
      iVar4 = CFastStringInt::GetNextToken
                        (in_stack_00000010,(CFastStringInt *)&local_20,(SFastTokenInt *)unaff_EBP);
      pCVar1 = pCVar10;
      if (iVar4 != 0) {
        local_28 = local_14;
        pCVar1 = pCVar10 + 1;
        local_24 = puStack_18;
        local_20 = 0;
        pSVar2 = CFastBuffer<struct_SFastCat>::operator[](local_3c,pCVar10,(ulong)&local_28);
        unaff_EBP = (CFastStringInt *)0x62fe55;
        CFastStringInt::SetString(pSVar2,(CFastStringInt *)unaff_EBX,in_stack_ffffffa8);
      }
      iVar7 = iVar7 + -1;
      pCVar10 = pCVar1;
    } while (iVar7 != 0);
  }
  if (local_4 != PTR_DAT_00bbf7dc) {
    if ((local_4[-1] & 0x80) == 0) {
      puVar5 = local_4 + -2;
    }
    else {
      puVar5 = local_4 + -4;
    }
    operator_delete__(puVar5);
    puStack_8 = (undefined *)0x0;
    local_4 = PTR_DAT_00bbf7dc;
  }
  if (puStack_18 != PTR_DAT_00bbf7dc) {
    if ((puStack_18[-1] & 0x80) == 0) {
      puStack_18 = puStack_18 + -2;
    }
    else {
      puStack_18 = puStack_18 + -4;
    }
    operator_delete__(puStack_18);
  }
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CGameCtnMenus::HideDialogs
// =================================================
void __thiscall CGameCtnMenus::HideDialogs(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  CGameCtnMenus *unaff_ESI;
  CGameCtnMenus *unaff_retaddr;
  CGameCtnMenus *in_stack_00000010;
  
  DialogPlayerProfile_DestroyVehicleScene(this,unaff_ESI);
  DialogCardGrid_Clean(this,unaff_retaddr);
  DialogGrid_Clean(this,param_1);
  CGameCtnApp::HideDialogs(*(CGameCtnApp **)(this + 0x784),in_stack_00000010);
  return;
}
}

// =================================================
// Function: CGameCtnMenus::MenuChooseChallenge_ResetCurrentSelection
// =================================================
void __thiscall
CGameCtnMenus::MenuChooseChallenge_ResetCurrentSelection(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  GmFrustumIso4 *in_stack_00000008;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d69120,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (&DAT_00d69120,pCVar3,unaff_ESI);
      pCVar3 = pCVar3 + 1;
      *(undefined4 *)(*(int *)pSVar2 + 0x2c) = 0;
    } while (pCVar3 < pCVar1);
  }
  *(undefined4 *)(this + 0x13c) = 0;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x7bc,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CGameCtnMenus::MenuProfileAdvanced
// =================================================
void __thiscall CGameCtnMenus::MenuProfileAdvanced(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  CMwId CVar1;
  CMwId *pCVar2;
  undefined3 extraout_var;
  CMotionPlayer *this_00;
  undefined3 extraout_var_00;
  CPlugTree *pCVar3;
  int iVar4;
  CGameNetwork *this_01;
  undefined3 extraout_var_01;
  undefined4 *puVar5;
  void *this_02;
  void *this_03;
  void *this_04;
  void *this_05;
  CSystemPackDesc *unaff_EBX;
  CFastStringInt *unaff_EDI;
  CFastStringInt *pCVar6;
  void *in_stack_00000018;
  undefined4 uStack00000024;
  CGameNetwork *pCVar7;
  
  pCVar2 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &stack0xfffffff4;
  CVar1 = CMwId::CreateFromLocalName(&stack0xffffffe8);
  this_00 = CFastBuffer<class_CMotionPlayer*>::GetNodFromId
                      ((void *)(*(int *)(this + 0x788) + 0x68),
                       (CFastBuffer<class_CMotionPlayer*> *)CONCAT31(extraout_var,CVar1),pCVar2);
  OnAccessViolation_ConcatToCrashFileName(unaff_EDI);
  CVar1 = CMwId::CreateFromLocalName(&stack0xfffffff0);
  pCVar3 = CControlContainer::GetChildFromId
                     ((CControlContainer *)this_00,(CPlugTree *)CONCAT31(extraout_var_00,CVar1),
                      (CMwId *)0x1);
  pCVar6 = (CFastStringInt *)0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(unaff_EDI);
  if (pCVar3 != (CPlugTree *)0x0) {
    (**(code **)(*(int *)pCVar3 + 0x240))(this,MenuProfile_Launch);
    iVar4 = (**(code **)(*(int *)pCVar3 + 0x108))();
    if (iVar4 == 0) {
      (**(code **)(*(int *)pCVar3 + 0x100))();
    }
    (**(code **)(*(int *)pCVar3 + 0x238))(1);
    (**(code **)(*(int *)pCVar3 + 0x178))();
  }
  iVar4 = *(int *)(*(int *)(*(int *)(this + 0x784) + 0x78) + 0x1c8);
  CControlTools::Connect((void *)(uint)(iVar4 != 0),(CCrystalEdge *)this_00);
  CControlTools::Connect(*(void **)(*(int *)(this + 0x784) + 0x168),(CCrystalEdge *)this_00);
  if (iVar4 == 0) {
    iVar4 = CGameApp::Profile_IsSkinsEnabled
                      (*(CGameApp **)(this + 0x784),(CGameApp *)0x0,0,unaff_EBX);
    if (iVar4 != 0) {
      this_02 = (void *)0x0;
      goto LAB_00621da3;
    }
  }
  this_02 = (void *)0x1;
LAB_00621da3:
  CControlTools::Connect(this_02,(CCrystalEdge *)this_00);
  CControlTools::Connect(this_03,(CCrystalEdge *)this_00);
  CControlTools::Connect(*(void **)(this + 0x784),(CCrystalEdge *)this_00);
  CControlTools::Connect(this_04,(CCrystalEdge *)this_00);
  pCVar7 = (CGameNetwork *)0x0;
  this_01 = (CGameNetwork *)(**(code **)(**(int **)(this + 0x784) + 0x118))();
  CGameNetwork::IsMasterServerConnected(this_01,pCVar7);
  CControlTools::Connect(this_05,(CCrystalEdge *)this_00);
  CVar1 = CMwId::CreateFromLocalName((char *)&stack0x00000018);
  uStack00000024 = 2;
  pCVar3 = CControlContainer::GetChildFromId
                     ((CControlContainer *)this_00,(CPlugTree *)CONCAT31(extraout_var_01,CVar1),
                      (CMwId *)0x1);
  uStack00000024 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(pCVar6);
  if (pCVar3 != (CPlugTree *)0x0) {
    iVar4 = 0x621eaf;
    (**(code **)(*(int *)pCVar3 + 0x1a8))();
    CControlColorChooser::SetParamsFromRGB
              ((CControlColorChooser *)pCVar3,
               (CControlColorChooser *)(*(int *)(*(int *)(this + 0x784) + 0x168) + 0x23c),
               (GmVec3 *)0x0,0,0,0,iVar4);
    if (*(int *)(pCVar3 + 0x164) == 0) {
      puVar5 = operator_new(0xc);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = CCtrColorChooserCallbackInstance<class_CGameCtnMenus>::vftable;
        puVar5[1] = this;
        puVar5[2] = MenuProfileAdvanced_SetTrailColor;
      }
      *(undefined4 **)(pCVar3 + 0x164) = puVar5;
    }
  }
  (**(code **)(*(int *)this + 0x208))();
  ExceptionList = in_stack_00000018;
  return;
}
}

// =================================================
// Function: CGameCtnMenus::MenuProfileAdvanced_SetTrailColor
// =================================================
void __thiscall
CGameCtnMenus::MenuProfileAdvanced_SetTrailColor
          (CGameCtnMenus *this,CGameCtnMenus *param_1,GmVec3 *param_2,int param_3)
{
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(this + 0x784) + 0x168);
  *(undefined4 *)(iVar1 + 0x23c) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x240) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x244) = *(undefined4 *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: CGameCtnMenus::MenuProfile_Clean
// =================================================
void __thiscall CGameCtnMenus::MenuProfile_Clean(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  CMwId CVar1;
  CMwId *pCVar2;
  undefined3 extraout_var;
  CMotionPlayer *pCVar3;
  CControlBase *pCVar4;
  CFastStringInt *unaff_EDI;
  CGameCtnMenus *local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00aabc18;
  local_c = ExceptionList;
  pCVar2 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  if (*(int *)(this + 0x788) != 0) {
    local_10 = this;
    CVar1 = CMwId::CreateFromLocalName((char *)&local_10);
    local_4 = (void *)0x0;
    pCVar3 = CFastBuffer<class_CMotionPlayer*>::GetNodFromId
                       ((void *)(*(int *)(this + 0x788) + 0x68),
                        (CFastBuffer<class_CMotionPlayer*> *)CONCAT31(extraout_var,CVar1),pCVar2);
    OnAccessViolation_ConcatToCrashFileName(unaff_EDI);
    if (*(int *)(this + 500) == 0) {
      pCVar4 = CControlBase::GetControl((CControlContainer *)pCVar3,"CardLeague");
      if (pCVar4 != (CControlBase *)0x0) {
        CControlBase::CreateStack(pCVar4,(CControlBase *)0x0,(CMwNod *)0x0,(char *)unaff_EDI);
        unaff_EDI = (CFastStringInt *)0x0;
        (**(code **)(*(int *)pCVar4 + 0x27c))();
      }
    }
    if (*(int *)(this + 0x1f8) == 0) {
      pCVar4 = CControlBase::GetControl((CControlContainer *)pCVar3,"GridGroups");
      if (pCVar4 != (CControlBase *)0x0) {
        (**(code **)(*(int *)pCVar4 + 0x2b0))(0xffffffff,1);
      }
    }
    MenuProfile_TagsAdmin_Clean(this,(CGameCtnMenus *)unaff_EDI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CGameCtnMenus::MenuProfile_OnAdvanced
// =================================================
void __thiscall CGameCtnMenus::MenuProfile_OnAdvanced(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  CGameCtnMenus *unaff_ESI;
  
  MenuProfile_Clean(this,unaff_ESI);
                    /* WARNING: Could not recover jumptable at 0x00642f73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x110))();
  return;
}
}

// =================================================
// Function: CGameCtnMenus::MenuProfile_TagsAdmin_Clean
// =================================================
void __thiscall
CGameCtnMenus::MenuProfile_TagsAdmin_Clean(CGameCtnMenus *this,CGameCtnMenus *param_1)
{
{
  CMwNod *unaff_ESI;
  
  if (*(CMwNod **)(this + 0x21c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x21c),unaff_ESI);
    *(undefined4 *)(this + 0x21c) = 0;
  }
  *(undefined4 *)(this + 0x220) = 0;
  return;
}
}

