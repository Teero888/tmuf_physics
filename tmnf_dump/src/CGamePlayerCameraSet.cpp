// Class implementation: CGamePlayerCameraSet

// =================================================
// Function: CGamePlayerCameraSet::CamGetCount
// =================================================
ulong __thiscall
CGamePlayerCameraSet::CamGetCount(CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1)
{
{
  ulong uVar1;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                    ((void *)(*(int *)(this + 0x18) + 0x5c),
                     (CFastBuffer<class_CCrystalFace*> *)param_1);
  return uVar1;
}
}

// =================================================
// Function: CGamePlayerCameraSet::CamGetCur
// =================================================
ulong __thiscall
CGamePlayerCameraSet::CamGetCur(CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1)
{
{
  return *(ulong *)(*(int *)(this + 0x18) + 0x6c);
}
}

// =================================================
// Function: CGamePlayerCameraSet::CamPtrGet
// =================================================
CGameControlCamera * __thiscall
CGamePlayerCameraSet::CamPtrGet
          (CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1,ulong param_2)
{
{
  ulong uVar1;
  CGameControlCamera *pCVar2;
  CGamePlayerCameraSet *unaff_ESI;
  ulong in_stack_0000000c;
  
  uVar1 = CamGetCount(this,unaff_ESI);
  if (uVar1 <= param_2) {
    return (CGameControlCamera *)0x0;
  }
  pCVar2 = CGameControlCameraMaster::CamGet
                     (*(CGameControlCameraMaster **)(this + 0x18),
                      (CGameControlCameraMaster *)param_2,in_stack_0000000c);
  return pCVar2;
}
}

// =================================================
// Function: CGamePlayerCameraSet::CamPtrGetCur
// =================================================
CGameControlCamera * __thiscall
CGamePlayerCameraSet::CamPtrGetCur(CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  ulong uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  int extraout_ECX;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CGamePlayerCameraSet *unaff_retaddr;
  
  uVar2 = CamGetCur(this,unaff_retaddr);
  if (uVar2 == 0xffffffff) {
    return (CGameControlCamera *)0x0;
  }
  this_00 = (void *)(*(int *)(extraout_ECX + 0x18) + 0x5c);
  pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
            (*(int *)(extraout_ECX + 0x18) + 0x6c);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (pCVar1 < pCVar3) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar1,unaff_ESI);
    return *(CGameControlCamera **)pSVar4;
  }
  return (CGameControlCamera *)0x0;
}
}

// =================================================
// Function: CGamePlayerCameraSet::CamSwitchTo
// =================================================
void __thiscall
CGamePlayerCameraSet::CamSwitchTo
          (CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1,ulong param_2)
{
{
  CGameControlCameraMaster *pCVar1;
  CGameControlCameraMaster *extraout_EDX;
  CGamePlayerCameraSet *unaff_ESI;
  bool bVar2;
  CGamePlayerCameraSet *unaff_retaddr;
  CGameControlCameraMaster *in_stack_0000000c;
  
  CamGetCount(this,unaff_ESI);
  pCVar1 = (CGameControlCameraMaster *)CamGetCur(this,unaff_retaddr);
  if (extraout_EDX != (CGameControlCameraMaster *)0x0) {
    if (in_stack_0000000c != (CGameControlCameraMaster *)0xffffffff) {
      if (in_stack_0000000c < extraout_EDX) {
        bVar2 = in_stack_0000000c == pCVar1;
        pCVar1 = in_stack_0000000c;
        if (bVar2) {
          return;
        }
      }
      else {
        pCVar1 = extraout_EDX + -1;
      }
    }
    if (pCVar1 != (CGameControlCameraMaster *)0xffffffff) {
      CGameControlCameraMaster::SwitchFromCurrentTo
                (*(CGameControlCameraMaster **)(this + 0x18),pCVar1,0,(ulong)param_1);
      return;
    }
    CGameControlCameraMaster::SwitchToNone
              (*(CGameControlCameraMaster **)(this + 0x18),(CGameControlCameraMaster *)param_1);
  }
  return;
}
}

// =================================================
// Function: CGamePlayerCameraSet::CamsReset
// =================================================
void __thiscall
CGamePlayerCameraSet::CamsReset(CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1)
{
{
  CGameControlCameraMaster *unaff_ESI;
  
  CGameControlCameraMaster::ResetAllCameras(*(CGameControlCameraMaster **)(this + 0x18),unaff_ESI);
  if (*(int **)(this + 0x1c) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e332b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x1c) + 0x90))();
    return;
  }
  return;
}
}

// =================================================
// Function: CGamePlayerCameraSet::PlayerGameMobilIdSet
// =================================================
void __thiscall
CGamePlayerCameraSet::PlayerGameMobilIdSet
          (CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1,ulong param_2)
{
{
  CGameControlCameraMaster *pCVar1;
  CGameControlCamera *this_00;
  int iVar2;
  CGameControlCameraMaster *pCVar3;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CGamePlayerCameraSet *unaff_EDI;
  ulong in_stack_0000000c;
  
  *(CGamePlayerCameraSet **)(this + 0x14) = param_1;
  pCVar1 = (CGameControlCameraMaster *)CamGetCount(this,unaff_EDI);
  if (pCVar1 != (CGameControlCameraMaster *)0x0) {
    pCVar3 = (CGameControlCameraMaster *)0x0;
    do {
      this_00 = CGameControlCameraMaster::CamGet
                          (*(CGameControlCameraMaster **)(this + 0x18),pCVar3,unaff_ESI);
      if (this_00 != (CGameControlCamera *)0x0) {
        CGameControlCamera::SetFollowedGameMobilId
                  (this_00,*(CGameControlCamera **)(this + 0x14),unaff_EBP);
        unaff_EBP = 0x3072000;
        unaff_ESI = 0x5e34a8;
        iVar2 = (**(code **)(*(int *)this_00 + 0x10))();
        if (iVar2 != 0) {
          (**(code **)(*(int *)this_00 + 0xb8))(*(undefined4 *)(this + 0x14));
        }
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  if (*(CGameControlCamera **)(this + 0x1c) == (CGameControlCamera *)0x0) {
    return;
  }
  CGameControlCamera::SetFollowedGameMobilId
            (*(CGameControlCamera **)(this + 0x1c),*(CGameControlCamera **)(this + 0x14),
             in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CGamePlayerCameraSet::UpdateAsync
// =================================================
void __thiscall CGamePlayerCameraSet::UpdateAsync(CGamePlayerCameraSet *this,CInputPortDx8 *param_1)
{
{
  int iVar1;
  CInputPortDx8 *unaff_ESI;
  
  CGameControlCameraMaster::UpdateAsync(*(CGameControlCameraMaster **)(this + 0x18),unaff_ESI);
  if (*(int **)(this + 0x1c) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(this + 0x1c) + 0x8c))();
    if (iVar1 != 0) {
      (**(code **)(**(int **)(this + 0x1c) + 0x7c))(*(undefined4 *)(DAT_00d731e0 + 0x80));
    }
  }
  return;
}
}

