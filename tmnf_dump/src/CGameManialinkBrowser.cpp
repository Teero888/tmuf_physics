// Class implementation: CGameManialinkBrowser

// =================================================
// Function: CGameManialinkBrowser::ApplyActiveAndEnabled
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameManialinkBrowser::ApplyActiveAndEnabled
          (CGameManialinkBrowser *this,CGameManialinkBrowser *param_1)
{
{
  int iVar1;
  CAudioSound *this_00;
  int iVar2;
  SCasterCat *pSVar3;
  CGameManialinkBrowser *this_01;
  CGameManialinkBrowser *unaff_ESI;
  CGameManialinkBrowser *unaff_EDI;
  ulong unaff_retaddr;
  STmRaceLowFps *in_stack_00000010;
  SStringParam *in_stack_fffffff4;
  CGameMenu *pCVar4;
  CGameMenu *in_stack_fffffff8;
  int in_stack_fffffffc;
  
  iVar2 = IsActive(this,unaff_EDI);
  if (*(int *)(this + 0x14) == 0) {
    return;
  }
  if (*(int *)(this + 0x24) == 0) {
    return;
  }
  if (iVar2 == 0) {
    ManialinkBrowser_CleanPage(this_01,unaff_ESI);
  }
  else if (*(int *)(this + 0x30) == 0) {
    if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x6c) ==
        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      SStringParam::SStringParam(&stack0xfffffff8,(SStringParam *)&DAT_00b2c878,(char *)unaff_ESI);
      CFastStringInt::SetString(this + 0x48,(CFastStringInt *)&stack0xfffffffc,in_stack_fffffff4);
    }
    else {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                         (this + 0x60,
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x6c),
                          (ulong)unaff_ESI);
      in_stack_fffffffc = *(int *)(pSVar3 + 4);
      unaff_retaddr = *(ulong *)pSVar3;
      CFastStringInt::SetString(this + 0x48,(CFastStringInt *)&stack0xfffffffc,in_stack_fffffff4);
    }
    *(undefined4 *)(this + 0x7c) = 2;
  }
  iVar1 = *(int *)(*(CGameApp_MenuContext **)(this + 0x14) + 0xb0);
  if (iVar1 != 0) {
    if (iVar2 == 0) {
      pCVar4 = (CGameMenu *)0x648a68;
      (**(code **)(**(int **)(this + 0x24) + 0x104))();
      CGameApp::HideMenu(*(CGameApp **)(this + 0xa0),*(CGameApp_MenuContext **)(this + 0x14),pCVar4)
      ;
      goto LAB_00648a9a;
    }
    if (iVar1 != 0) goto LAB_00648a9a;
  }
  if (iVar2 != 0) {
    CGameApp::ShowMenu(*(CGameApp **)(this + 0xa0),*(CGameApp_MenuContext **)(this + 0x14),
                       in_stack_fffffff8);
    in_stack_fffffff8 = (CGameMenu *)0x648a9a;
    (**(code **)(**(int **)(this + 0x24) + 0x100))();
  }
LAB_00648a9a:
  this_00 = *(CAudioSound **)(this + 0x44);
  if (this_00 != (CAudioSound *)0x0) {
    if (iVar2 == 0) {
      CAudioSound::Stop(this_00,in_stack_00000010);
      return;
    }
    CAudioSound::Play(this_00,_DAT_00b2c060,(EPlugVideoTimer)in_stack_fffffff8,in_stack_fffffffc,
                      unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CGameManialinkBrowser::IsActive
// =================================================
int __thiscall
CGameManialinkBrowser::IsActive(CGameManialinkBrowser *this,CGameManialinkBrowser *param_1)
{
{
  if (((*(int *)(this + 0x1c) != 0) && (*(int *)(this + 0x18) != 0)) && (*(int *)(this + 0x24) != 0)
     ) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CGameManialinkBrowser::ManialinkBrowser_CleanPage
// =================================================
void __thiscall
CGameManialinkBrowser::ManialinkBrowser_CleanPage
          (CGameManialinkBrowser *this,CGameManialinkBrowser *param_1)
{
{
  int iVar1;
  CGameCtnNetwork *this_00;
  CMwNod *unaff_EBX;
  CAudioSound *unaff_ESI;
  CGameCtnNetwork *pCVar2;
  ulong uVar3;
  
  if (*(CAudioPort **)(this + 0x44) != (CAudioPort *)0x0) {
    CAudioPort::RemoveSound
              (*(CAudioPort **)(*(int *)(this + 0xa0) + 0x68),*(CAudioPort **)(this + 0x44),
               unaff_ESI);
  }
  if (*(int *)(this + 0x34) != 0) {
    *(undefined4 *)(this + 0x34) = 0;
    **(undefined1 **)(this + 0x38) = 0;
  }
  *(undefined4 *)(this + 0x44) = 0;
  if (*(CMwNod **)(this + 0x40) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x40),unaff_EBX);
    *(undefined4 *)(this + 0x40) = 0;
  }
  if (*(CMwNod **)(this + 0x3c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x3c),unaff_EBX);
    *(undefined4 *)(this + 0x3c) = 0;
  }
  if (*(CMwNod **)(this + 0x2c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x2c),unaff_EBX);
    *(undefined4 *)(this + 0x2c) = 0;
  }
  if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x30),unaff_EBX);
    *(undefined4 *)(this + 0x30) = 0;
  }
  iVar1 = (**(code **)(**(int **)(this + 0xa0) + 0x118))();
  if (iVar1 != 0) {
    uVar3 = 2000;
    pCVar2 = (CGameCtnNetwork *)0x3e8;
    this_00 = (CGameCtnNetwork *)(**(code **)(**(int **)(this + 0xa0) + 0x118))();
    CGameCtnNetwork::PauseAllDataDownloads(this_00,pCVar2,uVar3,(ulong)unaff_EBX);
  }
  return;
}
}

// =================================================
// Function: CGameManialinkBrowser::SetIsEnabled
// =================================================
void __thiscall
CGameManialinkBrowser::SetIsEnabled(CGameManialinkBrowser *this,COalAudioPort *param_1,int param_2)
{
{
  int iVar1;
  CGameApp *unaff_ESI;
  CGameManialinkBrowser *unaff_EDI;
  
  if ((*(int *)(this + 0x9c) == 0) && (param_1 != (COalAudioPort *)0x0)) {
    iVar1 = CanBeEnabled(unaff_ESI);
    if (iVar1 != 0) {
      iVar1 = 1;
      goto LAB_00648bad;
    }
  }
  iVar1 = 0;
LAB_00648bad:
  if (iVar1 != *(int *)(this + 0x18)) {
    *(int *)(this + 0x18) = iVar1;
    ApplyActiveAndEnabled(this,unaff_EDI);
  }
  return;
}
}

