// Class implementation: CGameApp

// =================================================
// Function: CGameApp::EnablePick
// =================================================
void __thiscall CGameApp::EnablePick(CGameApp *this,CGameApp *param_1)
{
{
  int iVar1;
  CGameApp *unaff_ESI;
  GmFrustumIso4 *unaff_retaddr;
  
  iVar1 = IsPickEnabled(this,unaff_ESI);
  if (iVar1 == 0) {
    CScenePickerManager::Reset(*(CScenePickerManager **)(this + 0x134),unaff_retaddr);
    *(undefined4 *)(*(int *)(this + 0x134) + 0x448) = 1;
                    /* WARNING: Could not recover jumptable at 0x0059d4f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x130) + 0x7c))();
    return;
  }
  return;
}
}

// =================================================
// Function: CGameApp::GetBasicDialogs
// =================================================
CGameDialogs * __thiscall CGameApp::GetBasicDialogs(CGameApp *this,CGameApp *param_1)
{
{
  return *(CGameDialogs **)(this + 0x110);
}
}

// =================================================
// Function: CGameApp::GetCurrentMenu
// =================================================
CGameMenu * __thiscall CGameApp::GetCurrentMenu(CGameApp *this,CGameApp *param_1)
{
{
  int iVar1;
  SNewTriangleVert *pSVar2;
  SShaderCustom *unaff_ESI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_retaddr;
  
  iVar1 = CFastBuffer<class_CAudioSound*>::IsEmpty(this + 200,unaff_ESI);
  if (iVar1 != 0) {
    return (CGameMenu *)0x0;
  }
  pSVar2 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(this + 200,unaff_retaddr);
  return *(CGameMenu **)pSVar2;
}
}

// =================================================
// Function: CGameApp::GetManialinkBrowser
// =================================================
CGameManialinkBrowser * __thiscall CGameApp::GetManialinkBrowser(CGameApp *this,CGameApp *param_1)
{
{
  return *(CGameManialinkBrowser **)(this + 0x10c);
}
}

// =================================================
// Function: CGameApp::GetNextMusic
// =================================================
CPlugMusic * __thiscall
CGameApp::GetNextMusic(CGameApp *this,CGameApp *param_1,EInterfaceMusic param_2)
{
{
  CGameApp *this_00;
  int iVar1;
  CGameCtnChapter *this_01;
  CPlugMusic *pCVar2;
  SCasterCat *pSVar3;
  ulong uVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  EDecorationMusic unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if ((int)param_1 < 3) {
    iVar1 = (**(code **)(*(int *)this + 0x84))();
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x90) == 0)) goto LAB_0059c21c;
    this_01 = CGameCtnCatalog::GetChapter
                        (*(CGameCtnCatalog **)(this + 0x24),
                         (CGameCtnChallenge *)(*(int *)(iVar1 + 0x90) + 0x44));
    if ((this_01 != (CGameCtnChapter *)0x0) &&
       (pCVar2 = CGameCtnChapter::LoadNextMusic(this_01,(CGameCtnChapter *)param_1,unaff_EBX),
       pCVar2 != (CPlugMusic *)0x0)) {
      return pCVar2;
    }
    if (*(int *)(iVar1 + 0x114) == 0) goto LAB_0059c21c;
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(*(int *)(iVar1 + 0x114) + 0x5c) + 0x54),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_EBX);
  }
  else {
    if (param_1 != (CGameApp *)0x3) goto LAB_0059c21c;
    this_00 = this + 0x184;
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    if (uVar4 == 0) goto LAB_0059c21c;
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    *(int *)(this + 400) = *(int *)(this + 400) + 1;
    if (pCVar5 <= *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 400)) {
      *(undefined4 *)(this + 400) = 0;
    }
    if (pCVar5 <= *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 400))
    goto LAB_0059c21c;
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 400),
                        unaff_EBP);
  }
  if (*(CPlugMusic **)pSVar3 != (CPlugMusic *)0x0) {
    return *(CPlugMusic **)pSVar3;
  }
LAB_0059c21c:
  if (*(int *)(this + 0x28) == 0) {
    return (CPlugMusic *)0x0;
  }
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 200),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_EBX);
  return *(CPlugMusic **)pSVar3;
}
}

// =================================================
// Function: CGameApp::GetPayingAccountType
// =================================================
EAccountType __thiscall CGameApp::GetPayingAccountType(CGameApp *this,CGameApp *param_1)
{
{
  int iVar1;
  CGameNetwork *unaff_ESI;
  CGameMasterServer *unaff_retaddr;
  
  iVar1 = CGameNetwork::IsMasterServerConnected(*(CGameNetwork **)(this + 300),unaff_ESI);
  if (iVar1 != 0) {
    iVar1 = CGameMasterServer::IsPayingAccountConnected
                      (*(CGameMasterServer **)(*(int *)(this + 300) + 0x1b0),unaff_retaddr);
    return (iVar1 != 0) + 1;
  }
  return 0;
}
}

// =================================================
// Function: CGameApp::GetSound
// =================================================
CAudioSound * __thiscall
CGameApp::GetSound(CGameApp *this,CGameApp *param_1,EInterfaceSound param_2)
{
{
  void *this_00;
  int iVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  SShaderCustom *unaff_EDI;
  
  iVar1 = (**(code **)(*(int *)this + 0x84))();
  if (((iVar1 != 0) && ((int)param_1 < 7)) && (*(int *)(iVar1 + 0x114) != 0)) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(*(int *)(iVar1 + 0x114) + 0x5c) + 0x5c),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,(ulong)unaff_EDI);
    if (*(CAudioSound **)pSVar2 != (CAudioSound *)0x0) {
      return *(CAudioSound **)pSVar2;
    }
  }
  if (*(int *)(this + 0x28) == 0) {
    return (CAudioSound *)0x0;
  }
  this_00 = (void *)(*(int *)(this + 0x28) + 0xd0);
  iVar1 = CFastArray<struct_SGameCtnIdentifier>::IsEmpty(this_00,unaff_EDI);
  if (iVar1 == 0) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_ESI)
    ;
    return *(CAudioSound **)pSVar2;
  }
  return (CAudioSound *)0x0;
}
}

// =================================================
// Function: CGameApp::HideMenu
// =================================================
void __thiscall CGameApp::HideMenu(CGameApp *this,CGameApp_MenuContext *param_1,CGameMenu *param_2)
{
{
  int iVar1;
  SShaderCustom *unaff_ESI;
  CGameApp *unaff_EDI;
  CPlugSound *unaff_retaddr;
  CGameApp *in_stack_fffffff0;
  ulong in_stack_fffffff4;
  CMwNod *pCVar2;
  
  if (param_1 == (CGameApp_MenuContext *)0x0) {
    in_stack_fffffff4 = 0x59d171;
    param_1 = (CGameApp_MenuContext *)GetCurrentMenu(this,unaff_EDI);
    if (param_1 == (CGameApp_MenuContext *)0x0) goto LAB_0059d1ad;
  }
  if (*(int *)(param_1 + 0x7c) != 0) {
    pCVar2 = (CMwNod *)0x59d18d;
    (**(code **)(*(int *)param_1 + 0x8c))();
    CGameMenu::SetGame((CGameMenu *)param_1,(CGameMenu *)0x0,in_stack_fffffff0);
    CFastBuffer<class_CGameCtnBlock*>::Remove
              (this + 200,
               (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)&stack0x00000000,
               in_stack_fffffff4);
    CMwNod::MwRelease((CMwNod *)param_1,pCVar2);
  }
LAB_0059d1ad:
  iVar1 = CFastBuffer<class_CAudioSound*>::IsEmpty(this + 200,unaff_ESI);
  if ((iVar1 != 0) && (*(CAudioPort **)(this + 0x68) != (CAudioPort *)0x0)) {
    CAudioPort::CleanPlayablePlugSounds
              (*(CAudioPort **)(this + 0x68),(CAudioPort *)0x0,0,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CGameApp::IsPayingInstall
// =================================================
int __thiscall CGameApp::IsPayingInstall(CGameApp *this,CGameApp *param_1)
{
{
  return DAT_00d54240;
}
}

// =================================================
// Function: CGameApp::IsPayingSolo
// =================================================
int __thiscall CGameApp::IsPayingSolo(CGameApp *this,CGameApp *param_1)
{
{
  int iVar1;
  EAccountType EVar2;
  CGameApp *this_00;
  CGameApp *unaff_retaddr;
  
  iVar1 = IsPayingInstall(this,unaff_retaddr);
  if (iVar1 != 0) {
    EVar2 = GetPayingAccountType(this_00,param_1);
    if (EVar2 != 1) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CGameApp::IsPickEnabled
// =================================================
int __thiscall CGameApp::IsPickEnabled(CGameApp *this,CGameApp *param_1)
{
{
  return *(uint *)(*(int *)(this + 0x130) + 0x18) & 1;
}
}

// =================================================
// Function: CGameApp::MediaContextCreate
// =================================================
CGameCtnMediaContext * __thiscall CGameApp::MediaContextCreate(CGameApp *this,CGameApp *param_1)
{
{
  CMwNod *pCVar1;
  CMwNod *this_00;
  CGameDialogs *this_01;
  CMwNod *unaff_EBX;
  CMwNod *unaff_EBP;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9b9fb;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_c;
  this_00 = operator_new(0x40);
  local_4 = 0;
  if (this_00 == (CMwNod *)0x0) {
    this_00 = (CMwNod *)0x0;
  }
  else {
    CMwNod::CMwNod(this_00,pCVar1,unaff_EDI);
    *(undefined ***)this_00 = CGameCtnMediaContext::vftable;
    *(undefined4 *)(this_00 + 0x14) = 0;
    *(undefined4 *)(this_00 + 0x18) = 0;
    *(undefined4 *)(this_00 + 0x1c) = 0;
    *(undefined4 *)(this_00 + 0x20) = 0;
    *(undefined4 *)(this_00 + 0x24) = 0;
    *(undefined4 *)(this_00 + 0x28) = 0;
    *(undefined4 *)(this_00 + 0x2c) = 0;
    *(undefined4 *)(this_00 + 0x30) = 0;
    *(undefined4 *)(this_00 + 0x34) = 0;
    *(undefined4 *)(this_00 + 0x38) = 0;
    *(undefined4 *)(this_00 + 0x3c) = 0;
  }
  pCVar1 = *(CMwNod **)(this + 0x170);
  if (pCVar1 != *(CMwNod **)(this_00 + 0x20)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_ESI);
    }
    if (*(CMwNod **)(this_00 + 0x20) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x20),unaff_ESI);
    }
    *(CMwNod **)(this_00 + 0x20) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(this + 0x174);
  if (pCVar1 != *(CMwNod **)(this_00 + 0x24)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_ESI);
    }
    if (*(CMwNod **)(this_00 + 0x24) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x24),unaff_ESI);
    }
    *(CMwNod **)(this_00 + 0x24) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(this + 0x6c);
  if (pCVar1 != *(CMwNod **)(this_00 + 0x14)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_ESI);
    }
    if (*(CMwNod **)(this_00 + 0x14) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x14),unaff_ESI);
    }
    *(CMwNod **)(this_00 + 0x14) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(this + 100);
  if (pCVar1 != *(CMwNod **)(this_00 + 0x18)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_ESI);
    }
    if (*(CMwNod **)(this_00 + 0x18) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x18),unaff_ESI);
    }
    *(CMwNod **)(this_00 + 0x18) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(this + 0x68);
  if (pCVar1 != *(CMwNod **)(this_00 + 0x1c)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_ESI);
    }
    if (*(CMwNod **)(this_00 + 0x1c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x1c),unaff_ESI);
    }
    *(CMwNod **)(this_00 + 0x1c) = pCVar1;
  }
  this_01 = GetBasicDialogs(this,(CGameApp *)unaff_ESI);
  if (this_01 != *(CGameDialogs **)(this_00 + 0x30)) {
    if (this_01 != (CGameDialogs *)0x0) {
      CMwNod::MwAddRef((CMwNod *)this_01,unaff_EBP);
    }
    if (*(CMwNod **)(this_00 + 0x30) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x30),unaff_EBX);
    }
    *(CGameDialogs **)(this_00 + 0x30) = this_01;
  }
  *(CGameApp **)(this_00 + 0x34) = this;
  *(undefined4 *)(this_00 + 0x38) = 0;
  *(undefined4 *)(this_00 + 0x3c) = 0;
  pCVar1 = (CMwNod *)(**(code **)(*(int *)this + 0x88))();
  if (pCVar1 != *(CMwNod **)(this_00 + 0x28)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_EBX);
    }
    if (*(CMwNod **)(this_00 + 0x28) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x28),unaff_EBX);
    }
    *(CMwNod **)(this_00 + 0x28) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(this + 0x178);
  if (pCVar1 != *(CMwNod **)(this_00 + 0x2c)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_EBX);
    }
    if (*(CMwNod **)(this_00 + 0x2c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this_00 + 0x2c),unaff_EBX);
    }
    *(CMwNod **)(this_00 + 0x2c) = pCVar1;
  }
  ExceptionList = (void *)0xffffffff;
  return (CGameCtnMediaContext *)this_00;
}
}

// =================================================
// Function: CGameApp::PlayMusic
// =================================================
/* WARNING: Removing unreachable block (ram,0x0059d906) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameApp::PlayMusic(CGameApp *this,CGameApp *param_1,EInterfaceMusic param_2,int param_3)
{
{
  int iVar1;
  bool bVar2;
  CPlugMusic *pCVar3;
  CAudioSound *pCVar4;
  int iVar5;
  int *extraout_EAX;
  int extraout_EAX_00;
  int *extraout_EAX_01;
  int extraout_EAX_02;
  CMwNod *unaff_EBX;
  EInterfaceMusic unaff_EBP;
  CGameApp *unaff_ESI;
  CMwNod *unaff_EDI;
  CAudioPort *this_00;
  CPlugMusic *in_stack_00000010;
  int *piVar6;
  CMwNod *pCVar7;
  int *in_stack_ffffffcc;
  int *in_stack_ffffffd0;
  undefined4 auStack_2c [2];
  undefined1 auStack_24 [4];
  undefined4 auStack_20 [2];
  int iStack_18;
  int local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00a9bcaa;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = (CAudioPort *)0x0;
  pCVar7 = (CMwNod *)0x0;
  if ((((param_2 == 0) && (*(CGameApp **)(this + 0x180) == param_1)) &&
      (*(int *)(this + 0x17c) != 0)) && (*(int *)(*(int *)(this + 0x17c) + 0x50) != 0)) {
    ExceptionList = (void *)0xffffffff;
    return;
  }
  local_4 = (void *)0x0;
  pCVar3 = GetNextMusic(this,param_1,(EInterfaceMusic)((uint)DAT_00cca150 ^ (uint)&stack0xffffffb8))
  ;
  if (pCVar3 == (CPlugMusic *)0x0) {
    if (param_2 == 0) goto LAB_0059daf4;
  }
  else {
    CMwNod::MwAddRef((CMwNod *)pCVar3,unaff_EDI);
    this_00 = (CAudioPort *)pCVar3;
    in_stack_00000010 = pCVar3;
  }
  StopMusics(this,(CGameApp *)0x0,(int)unaff_EDI);
  if (this_00 == (CAudioPort *)0x0) goto LAB_0059daf4;
  iVar5 = *(int *)(*(int *)(this_00 + 0x18) + 8);
  iVar1 = *(int *)(this + 0x17c);
  while (iVar1 == 0) {
    pCVar4 = CAudioPort::AddSound
                       (*(CAudioPort **)(this + 0x68),this_00,(CPlugSound *)0x1,0,(int)unaff_ESI);
    *(CAudioSound **)(this + 0x17c) = pCVar4;
    if (pCVar4 == (CAudioSound *)0x0) {
      unaff_ESI = (CGameApp *)in_stack_00000010;
      pCVar3 = GetNextMusic(this,(CGameApp *)in_stack_00000010,unaff_EBP);
      if (pCVar3 != (CPlugMusic *)this_00) {
        if (pCVar3 != (CPlugMusic *)0x0) {
          unaff_EBP = 0x59d974;
          CMwNod::MwAddRef((CMwNod *)pCVar3,unaff_EBX);
        }
        unaff_EBX = (CMwNod *)0x59d97b;
        CMwNod::MwRelease((CMwNod *)this_00,pCVar7);
        this_00 = (CAudioPort *)pCVar3;
      }
      if (*(int *)(*(int *)(this_00 + 0x18) + 8) == iVar5) break;
    }
    iVar1 = *(int *)(this + 0x17c);
  }
  pCVar4 = _DAT_00b2c05c;
  if (*(CAudioPort **)(this + 0x17c) == (CAudioPort *)0x0) goto LAB_0059daf4;
  *(int *)(this + 0x180) = param_3;
  CAudioPort::FadePlay
            (*(CAudioPort **)(this + 0x68),*(CAudioPort **)(this + 0x17c),pCVar4,(float)unaff_ESI);
  unaff_ESI = (CGameApp *)0x0;
  CAudioPort::AutoBalance_Add
            (*(CAudioPort **)(this + 0x68),*(CAudioPort **)(this + 0x17c),(CAudioSound *)0x0,
             unaff_EBP);
  if (((*(int *)(this + 0x180) == 3) && (this_00 != (CAudioPort *)0x0)) &&
     (*(int **)(this_00 + 0x18) != (int *)0x0)) {
    piVar6 = (int *)0x905a000;
    unaff_ESI = (CGameApp *)0x59d9ff;
    iVar5 = (**(code **)(**(int **)(this_00 + 0x18) + 0x10))();
    if (iVar5 == 0) goto LAB_0059da94;
    CFastStringInt::CFastStringInt(auStack_24,(CFastStringInt *)L"Menu",(SStringParam *)unaff_ESI);
    iStack_18 = extraout_EAX[1];
    local_14 = *extraout_EAX;
    local_10 = 0;
    auStack_2c[0] = 1;
    if (local_14 != *(int *)(*(int *)(this_00 + 0x18) + 0x44)) goto LAB_0059da94;
    unaff_ESI = (CGameApp *)0x0;
    CFastStringInt::Compare
              ((int *)(*(int *)(this_00 + 0x18) + 0x44),(SParam_Fids *)&iStack_18,(SParam *)0x0,
               piVar6,(int *)unaff_EBX);
    if (extraout_EAX_00 != 0) goto LAB_0059da94;
    CFastStringInt::CFastStringInt
              (auStack_20,(CFastStringInt *)L"Trackmania Nations",(SStringParam *)pCVar7);
    auStack_20[0] = 3;
    if ((*extraout_EAX_01 != *(int *)(*(int *)(this_00 + 0x18) + 0x34)) ||
       (CFastStringInt::Compare
                  ((int *)(*(int *)(this_00 + 0x18) + 0x34),(SParam_Fids *)&stack0x00000000,
                   (SParam *)0x0,in_stack_ffffffcc,in_stack_ffffffd0), extraout_EAX_02 != 0))
    goto LAB_0059da94;
    bVar2 = true;
  }
  else {
LAB_0059da94:
    bVar2 = false;
  }
  if (((uint)in_stack_ffffffd0 & 2) != 0) {
    in_stack_ffffffd0 = (int *)((uint)in_stack_ffffffd0 & 0xfffffffd);
    CGameCtnApp::SNationConfig::~SNationConfig(auStack_2c,(SNationConfig *)unaff_ESI);
  }
  if (((uint)in_stack_ffffffd0 & 1) != 0) {
    CGameCtnApp::SNationConfig::~SNationConfig(auStack_24,(SNationConfig *)unaff_ESI);
  }
  if (bVar2) {
    if (DAT_00ce8988 == 0) {
      (**(code **)(**(int **)(*(int *)(this + 0x17c) + 0x74) + 0x10))();
    }
    DAT_00ce8988 = 0;
  }
LAB_0059daf4:
  if (this_00 != (CAudioPort *)0x0) {
    CMwNod::MwRelease((CMwNod *)this_00,(CMwNod *)unaff_ESI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CGameApp::PlaySound
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CGameApp::PlaySound(CPlugSound *param_1)
{
{
  CAudioSound *this;
  int iVar1;
  CGameApp *in_ECX;
  EInterfaceSound unaff_ESI;
  int unaff_retaddr;
  undefined4 in_stack_00000008;
  EPlugVideoTimer EVar2;
  
  this = GetSound(in_ECX,(CGameApp *)param_1,unaff_ESI);
  if (this != (CAudioSound *)0x0) {
    EVar2 = 0x10007000;
    iVar1 = (**(code **)(*(int *)this + 0x10))();
    if (iVar1 != 0) {
      *(undefined4 *)(this + 0x78) = in_stack_00000008;
    }
    CAudioSound::Play(this,_DAT_00b2c060,EVar2,unaff_retaddr,(ulong)param_1);
  }
  return;
}
}

// =================================================
// Function: CGameApp::Profile_IsAvatarsEnabled
// =================================================
int __thiscall CGameApp::Profile_IsAvatarsEnabled(CGameApp *this,CGameApp *param_1)
{
{
  if (((*(int *)(this + 0x168) != 0) && (*(int *)(this + 0x78) != 0)) &&
     ((*(int *)(*(int *)(this + 0x168) + 0x160) == 0 ||
      (*(int *)(*(int *)(this + 0x78) + 0x1c8) != 0)))) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CGameApp::Profile_IsChatEnabled
// =================================================
int __thiscall CGameApp::Profile_IsChatEnabled(CGameApp *this,CGameApp *param_1)
{
{
  if (((*(int *)(this + 0x168) != 0) && (*(int *)(this + 0x78) != 0)) &&
     ((*(int *)(*(int *)(this + 0x168) + 0x164) == 0 ||
      (*(int *)(*(int *)(this + 0x78) + 0x1c8) != 0)))) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CGameApp::Profile_IsPackDescParentalLocked
// =================================================
int __thiscall
CGameApp::Profile_IsPackDescParentalLocked
          (CGameApp *this,CGameApp *param_1,CSystemPackDesc *param_2)
{
{
  int iVar1;
  CSystemPackDesc *unaff_retaddr;
  
  if ((((param_1 != (CGameApp *)0x0) && (*(int *)(this + 0x168) != 0)) &&
      (*(int *)(this + 0x78) != 0)) && (*(int *)(*(int *)(this + 0x78) + 0x1c8) != 0)) {
    if ((*(int *)(param_1 + 0x48) != 0) &&
       (iVar1 = CSystemPackManager::IsPackDescInCache
                          (DAT_00d54250,(CSystemPackManager *)param_1,unaff_retaddr), iVar1 == 0)) {
      return 0;
    }
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CGameApp::Profile_IsSkinsEnabled
// =================================================
int __thiscall
CGameApp::Profile_IsSkinsEnabled
          (CGameApp *this,CGameApp *param_1,int param_2,CSystemPackDesc *param_3)
{
{
  int iVar1;
  CSystemPackDesc *unaff_ESI;
  
  if ((*(int *)(this + 0x168) == 0) || (*(int *)(this + 0x78) == 0)) {
    return 1;
  }
  if ((*(int *)(*(int *)(this + 0x78) + 0x1c8) != 0) && (param_1 == (CGameApp *)0x0)) {
    if (param_2 != 0) {
      iVar1 = Profile_IsPackDescParentalLocked(this,(CGameApp *)param_2,unaff_ESI);
      if (iVar1 == 0) goto LAB_0059db8b;
    }
    return 0;
  }
LAB_0059db8b:
  return (uint)(*(int *)(*(int *)(this + 0x78) + 0x134) == 0);
}
}

// =================================================
// Function: CGameApp::SetCursorPos
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameApp::SetCursorPos(CGameApp *this,CGameApp *param_1,GmVec2 *param_2)
{
{
  int iVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float local_8;
  float local_4;
  
  local_8 = *(float *)param_1;
  local_4 = *(float *)(param_1 + 4);
  fVar4 = (float)_DAT_00b36288;
  fVar3 = (float)_DAT_00b55920;
  if (local_8 + fVar4 <= 1.0) {
    bVar2 = fVar3 <= local_8 - fVar4;
    if (!bVar2) {
      local_8 = _DAT_00b2c060;
    }
    uVar6 = (uint)bVar2;
  }
  else {
    uVar6 = 0;
    local_8 = 1.0;
  }
  fVar5 = 1.0;
  if ((1.0 < local_4 + fVar4) || (fVar5 = _DAT_00b2c060, local_4 - fVar4 < fVar3)) {
    local_4 = fVar5;
    uVar6 = 0;
  }
  *(uint *)(*(int *)(this + 0x134) + 0x448) = uVar6;
  iVar1 = *(int *)(this + 0x134);
  *(float *)(iVar1 + 0x450) = local_8;
  *(float *)(iVar1 + 0x454) = local_4;
  return;
}
}

// =================================================
// Function: CGameApp::ShowMenu
// =================================================
void __thiscall CGameApp::ShowMenu(CGameApp *this,CGameApp_MenuContext *param_1,CGameMenu *param_2)
{
{
  CGameApp *unaff_ESI;
  CMwNod *unaff_EDI;
  TiXmlAttribute *unaff_retaddr;
  
  CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
  CGameMenu::SetGame((CGameMenu *)param_1,(CGameMenu *)this,unaff_ESI);
  (**(code **)(*(int *)param_1 + 0x88))();
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            ((CFastBuffer<class_CGameMenu*> *)(this + 200),(TiXmlAttributeSet *)&stack0x0000000c,
             unaff_retaddr);
  ApplyMenuSortPriorities
            ((CFastBuffer<class_CGameMenu*> *)(this + 200),*(CHmsViewport **)(this + 100));
  return;
}
}

// =================================================
// Function: CGameApp::StopMusics
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameApp::StopMusics(CGameApp *this,CGameApp *param_1,int param_2)
{
{
  int unaff_ESI;
  
  if (*(CAudioPort **)(this + 0x17c) != (CAudioPort *)0x0) {
    CAudioPort::FadeStop
              (*(CAudioPort **)(this + 0x68),*(CAudioPort **)(this + 0x17c),_DAT_00b2c05c,1.4013e-45
               ,unaff_ESI);
    *(undefined4 *)(this + 0x17c) = 0;
  }
  *(undefined4 *)(this + 0x180) = 5;
  return;
}
}

// =================================================
// Function: CGameApp::UpdateMusic
// =================================================
void __thiscall CGameApp::UpdateMusic(CGameApp *this,CGameApp *param_1)
{
{
  int iVar1;
  int unaff_retaddr;
  
  iVar1 = *(int *)(this + 0x17c);
  if ((((iVar1 != 0) && (*(int *)(*(int *)(iVar1 + 0x44) + 0x24) == 0)) &&
      (*(int *)(iVar1 + 0x50) == 0)) && ((int)*(CGameApp **)(this + 0x180) < 5)) {
    PlayMusic(this,*(CGameApp **)(this + 0x180),1,unaff_retaddr);
  }
  return;
}
}

