// Class implementation: CGameControlCameraMaster

// =================================================
// Function: CGameControlCameraMaster::ApplyGlobalEffectsOn
// =================================================
void __thiscall
CGameControlCameraMaster::ApplyGlobalEffectsOn
          (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,GmCamVal *param_2)
{
{
                    /* WARNING: Could not recover jumptable at 0x00692dab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0x68) + 0x8c))();
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::CGameControlCameraMaster
// =================================================
void __thiscall
CGameControlCameraMaster::CGameControlCameraMaster
          (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1)
{
{
  CMwNod *extraout_EAX;
  GmFrustumIso4 *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *this_00;
  GmFrustumIso4 *unaff_retaddr;
  CGameControlCameraEffectGroup *pCStack0000000c;
  undefined1 uStack00000010;
  void *in_stack_00000018;
  undefined1 uStack0000001c;
  CGameControlCameraMaster *pCVar1;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffff0;
  SSwitch *pSVar2;
  CMwId *pCVar3;
  CGameControlCameraEffectGroup *pCVar4;
  
  pCVar4 = (CGameControlCameraEffectGroup *)0xffffffff;
  pCVar3 = (CMwId *)&LAB_00ab19b7;
  pSVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4),unaff_EDI);
  *(undefined ***)this = vftable;
  GmLocVal::Reset(this + 0x18,unaff_ESI);
  GmLensVal::Reset(this + 0x48,(GmFrustumIso4 *)pCVar1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x5c,in_stack_fffffff0);
  *(undefined4 *)(this + 0x68) = 0;
  uStack00000010 = 2;
  SSwitch::SSwitch(this + 0x74,pSVar2);
  CMwId::CMwId(this + 0x1bc,pCVar3);
  pCStack0000000c = operator_new(0x24);
  in_stack_00000018 = (void *)CONCAT31(in_stack_00000018._1_3_,4);
  if (pCStack0000000c == (CGameControlCameraEffectGroup *)0x0) {
    this_00 = (CMwNod *)0x0;
  }
  else {
    CGameControlCameraEffectGroup::CGameControlCameraEffectGroup(pCStack0000000c,pCVar4);
    this_00 = extraout_EAX;
  }
  uStack0000001c = 3;
  if (this_00 != *(CMwNod **)(this + 0x68)) {
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_00,(CMwNod *)unaff_retaddr);
    }
    if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x68),(CMwNod *)unaff_retaddr);
    }
    *(CMwNod **)(this + 0x68) = this_00;
  }
  Reset(this,unaff_retaddr);
  ExceptionList = in_stack_00000018;
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::CamGet
// =================================================
CGameControlCamera * __thiscall
CGameControlCameraMaster::CamGet
          (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,ulong param_2)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x5c,unaff_ESI);
  if (uVar1 <= param_2) {
    return (CGameControlCamera *)0x0;
  }
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x5c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                      unaff_retaddr);
  return *(CGameControlCamera **)pSVar2;
}
}

// =================================================
// Function: CGameControlCameraMaster::GetCamVal
// =================================================
void __thiscall
CGameControlCameraMaster::GetCamVal
          (CGameControlCameraMaster *this,GmCamFreeVal *param_1,GmCamVal *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  GmCamVal *unaff_EBX;
  SGameCamVal *unaff_EBP;
  SGameCamVal *unaff_ESI;
  CGameControlCameraMaster *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  GmCamFreeVal *pGVar6;
  CGameControlCamera *in_stack_0000000c;
  
  if (*(int *)(this + 0x70) != 0) {
    pCVar5 = this + 0xe8;
    pGVar6 = param_1;
    for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined4 *)pGVar6 = *(undefined4 *)pCVar5;
      pCVar5 = pCVar5 + 4;
      pGVar6 = pGVar6 + 4;
    }
    ApplyGlobalEffectsOn(this,(CGameControlCameraMaster *)param_1,(GmCamVal *)unaff_EDI);
    return;
  }
  pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x6c);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x5c,unaff_EDI);
    if (pCVar1 < pCVar2) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x5c,pCVar1,(ulong)unaff_ESI);
      CGameControlCamera::GetGameCamVal(*(CGameControlCamera **)pSVar3,in_stack_0000000c,unaff_EBP);
      ApplyGlobalEffectsOn(this,(CGameControlCameraMaster *)in_stack_0000000c,unaff_EBX);
      return;
    }
    CGameControlCamera::GetGameCamVal
              ((CGameControlCamera *)0x0,(CGameControlCamera *)param_2,unaff_ESI);
    ApplyGlobalEffectsOn(this,(CGameControlCameraMaster *)param_2,(GmCamVal *)unaff_EBP);
    return;
  }
  if (*(int *)(this + 0x14) != 0) {
    SGameCamVal::Reset(param_1,(GmFrustumIso4 *)unaff_EDI);
    pCVar5 = this + 0x18;
    pGVar6 = param_1;
    for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined4 *)pGVar6 = *(undefined4 *)pCVar5;
      pCVar5 = pCVar5 + 4;
      pGVar6 = pGVar6 + 4;
    }
    ApplyGlobalEffectsOn(this,(CGameControlCameraMaster *)param_1,(GmCamVal *)unaff_ESI);
    return;
  }
  SGameCamVal::Reset(param_1,(GmFrustumIso4 *)unaff_EDI);
  ApplyGlobalEffectsOn(this,(CGameControlCameraMaster *)param_1,(GmCamVal *)unaff_ESI);
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::Install
// =================================================
void __thiscall
CGameControlCameraMaster::Install(CGameControlCameraMaster *this,CMwCmdFiber *param_1)
{
{
  int iVar1;
  
  if (*(int **)(this + 0x68) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(this + 0x68) + 0x88))();
    if (iVar1 != 0) {
      (**(code **)(**(int **)(this + 0x68) + 0x7c))();
    }
                    /* WARNING: Could not recover jumptable at 0x00692cfb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x68) + 0x78))();
    return;
  }
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::ResetAllCameras
// =================================================
void __thiscall
CGameControlCameraMaster::ResetAllCameras
          (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x5c,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x5c,pCVar3,unaff_ESI);
      unaff_ESI = 0x693519;
      (**(code **)(**(int **)pSVar2 + 0x90))();
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::StopSwitching
// =================================================
void __thiscall
CGameControlCameraMaster::StopSwitching
          (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1)
{
{
  *(undefined4 *)(this + 0x70) = 0;
  SSwitch::Reset(this + 0x74,(GmFrustumIso4 *)param_1);
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::SwitchFromCurrentTo
// =================================================
int __thiscall
CGameControlCameraMaster::SwitchFromCurrentTo
          (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,ulong param_2,
          ulong param_3)
{
{
  ulong uVar1;
  CGameControlCamera *pCVar2;
  int extraout_EAX;
  int iVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  
  if (*(int *)(this + 0x6c) != -1) {
    iVar3 = (**(code **)(*(int *)this + 0x78))(*(int *)(this + 0x6c),param_1,0,0,0,0,param_2);
    return iVar3;
  }
  if (*(int *)(this + 0x14) == 0) {
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x5c,unaff_ESI);
    if (param_2 < uVar1) {
      *(ulong *)(this + 0x6c) = param_2;
      pCVar2 = CamGet(this,(CGameControlCameraMaster *)param_2,unaff_retaddr);
      (**(code **)(*(int *)pCVar2 + 0x88))();
      return 1;
    }
    return 0;
  }
  Switch(this,(CControlUiDockable *)(this + 0x18));
  return extraout_EAX;
}
}

// =================================================
// Function: CGameControlCameraMaster::SwitchToNone
// =================================================
void __thiscall
CGameControlCameraMaster::SwitchToNone
          (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1)
{
{
  CGameControlCameraMaster *unaff_ESI;
  
  StopSwitching(this,unaff_ESI);
  *(undefined4 *)(this + 0x6c) = 0xffffffff;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::Uninstall
// =================================================
void __thiscall
CGameControlCameraMaster::Uninstall(CGameControlCameraMaster *this,CMwCmdContainer *param_1)
{
{
  if (*(int **)(this + 0x68) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x68) + 0x7c))();
  }
  Reset(this,(GmFrustumIso4 *)param_1);
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::UpdateAsync
// =================================================
void __thiscall
CGameControlCameraMaster::UpdateAsync(CGameControlCameraMaster *this,CInputPortDx8 *param_1)
{
{
  void *this_00;
  CMwTimerAdapter *unaff_ESI;
  CGameControlCameraMaster *pCVar1;
  CGameControlCameraMaster *pCVar2;
  
  this_00 = *(void **)(DAT_00d731e0 + 0x14);
  if (this_00 == (void *)0x0) {
    this_00 = (void *)(DAT_00d731e0 + 0xa0);
  }
  pCVar2 = this;
  pCVar1 = (CGameControlCameraMaster *)CMwTimerAdapter::GetAsyncPeriod(this_00,unaff_ESI);
  UpdateCameras(this,pCVar1,(float)pCVar2);
  UpdateSwitchs(this,(CGameControlCameraMaster *)param_1,(float)pCVar1);
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::UpdateCameras
// =================================================
void __thiscall
CGameControlCameraMaster::UpdateCameras
          (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,float param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CGameControlCameraMaster *pCVar3;
  
  pCVar3 = param_1;
  (**(code **)(**(int **)(this + 0x68) + 0x80))();
  pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x6c);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x5c,pCVar1,unaff_EBX)
    ;
    if (*(int *)pSVar2 != 0) {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x5c,pCVar1,(ulong)pCVar3);
      (**(code **)(**(int **)pSVar2 + 0x7c))(param_2);
    }
    if (((*(int *)(this + 0x70) != 0) && (*(int *)(this + 0x84) != 0)) &&
       (*(int *)(this + 0x7c) != 0)) {
      (**(code **)(**(int **)(this + 0x7c) + 0x7c))(param_1);
    }
  }
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::UpdateSwitchs
// =================================================
void __thiscall
CGameControlCameraMaster::UpdateSwitchs
          (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,float param_2)
{
{
  int extraout_EAX;
  ulong unaff_ESI;
  int unaff_EDI;
  CGameControlCameraMaster *unaff_retaddr;
  float in_stack_0000000c;
  
  if (*(int *)(this + 0x70) != 0) {
    SSwitch::Update(this + 0x74,(SGmSmoothReal2 *)param_1,unaff_EDI,unaff_ESI);
    if (extraout_EAX != 0) {
      if (in_stack_0000000c < 0.0) {
        *(undefined4 *)(this + 0x6c) = *(undefined4 *)(this + 0x74);
      }
      StopSwitching(this,unaff_retaddr);
    }
  }
  return;
}
}

