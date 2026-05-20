// Class implementation: CInputPort

// =================================================
// Function: CInputPort::ClearInputs
// =================================================
void __thiscall CInputPort::ClearInputs(CInputPort *this,CInputPort *param_1,int param_2)
{
{
  void *this_00;
  ulong uVar1;
  ulong unaff_ESI;
  CInputEventsStore *unaff_EDI;
  ulong unaff_retaddr;
  CMwTimerAdapter *in_stack_0000000c;
  int in_stack_00000010;
  int in_stack_0000001c;
  
  (**(code **)(*(int *)this + 0xa4))();
  CInputEventsStore::ClearStore(this + 0x40,unaff_EDI);
  CInputEventsStore::Lock
            (this + 0x40,(CDx9DynamicVB *)0x0,unaff_ESI,unaff_retaddr,(uchar **)param_1,
             (ulong *)param_2);
  *(undefined4 *)(this + 0x38) = 1;
  this_00 = *(void **)(DAT_00d731e0 + 0x14);
  if (this_00 == (void *)0x0) {
    this_00 = (void *)(DAT_00d731e0 + 0xa0);
  }
  uVar1 = CMwTimerAdapter::GetTime(this_00,in_stack_0000000c);
  *(ulong *)(this + 200) = uVar1;
  if ((in_stack_0000001c != 0) || (*(int *)(this + 0x8c) != 0)) {
    ReadCurMapLatestEventsFromHarware(this,(CInputPort *)0x1,in_stack_00000010);
  }
  return;
}
}

// =================================================
// Function: CInputPort::FindDevice
// =================================================
int __thiscall
CInputPort::FindDevice
          (CInputPort *this,CInputPort *param_1,CMwId *param_2,ulong *param_3,CInputDevice **param_4
          )
{
{
  CInputPort *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *in_stack_00000018;
  
  this_00 = this + 0x2c;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
      if (*(int *)(*(int *)pSVar3 + 0x34) == iVar1) {
        *param_4 = (CInputDevice *)pCVar4;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBP)
        ;
        *in_stack_00000018 = *(undefined4 *)pSVar3;
        return 1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return 0;
}
}

// =================================================
// Function: CInputPort::GetActionState
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

SInputEvent * __thiscall
CInputPort::GetActionState(CInputPort *this,CInputPort *param_1,SInputActionDesc *param_2)
{
{
  if ((_DAT_00d71484 & 1) == 0) {
    _DAT_00d71484 = _DAT_00d71484 | 1;
  }
  CInputEventsStore::GetState(this + 0x40,(CMwCmdFiber *)param_1);
  return (SInputEvent *)&DAT_00d7147c;
}
}

// =================================================
// Function: CInputPort::InternalGatherLatestInputs
// =================================================
void __thiscall CInputPort::InternalGatherLatestInputs(CInputPort *this,CInputPort *param_1)
{
{
  int unaff_ESI;
  
  (**(code **)(*(int *)this + 0xa4))();
  if (*(int *)(this + 0x8c) != 0) {
    ReadCurMapLatestEventsFromHarware(this,(CInputPort *)0x0,unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: CInputPort::OnFocusChanged
// =================================================
void __thiscall CInputPort::OnFocusChanged(CInputPort *this,CInputPort *param_1)
{
{
  int *piVar1;
  int iVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,unaff_EDI);
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x2c,pCVar8,unaff_ESI);
      piVar1 = *(int **)pSVar4;
      iVar2 = piVar1[7];
      unaff_ESI = 0x8f8357;
      iVar5 = (**(code **)(*piVar1 + 0x78))();
      if (iVar5 == 2) {
        uVar6 = (uint)(*(int *)(this + 0x90) == 0);
      }
      else if ((*(int *)(this + 0x90) == 0) || (*(int *)(this + 0x94) != 0)) {
        uVar6 = 1;
      }
      else {
        uVar6 = 0;
      }
      piVar1[7] = uVar6;
      if (uVar6 == 0) {
        if (iVar2 != 0) {
          pcVar7 = *(code **)(*piVar1 + 0x90);
LAB_008f83a9:
          (*pcVar7)();
        }
      }
      else if (iVar2 == 0) {
        pcVar7 = *(code **)(*piVar1 + 0x94);
        goto LAB_008f83a9;
      }
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar3);
  }
  *(undefined4 *)(this + 0x8c) = 1;
  return;
}
}

// =================================================
// Function: CInputPort::ReadCurMapLatestEventsFromHarware
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CInputPort::ReadCurMapLatestEventsFromHarware(CInputPort *this,CInputPort *param_1,int param_2)
{
{
  int iVar1;
  int *piVar2;
  ulong uVar3;
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  GmQuat *pGVar6;
  code *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CMwTimerAdapter *unaff_EDI;
  float unaff_retaddr;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *in_stack_0000000c;
  int in_stack_00000010;
  float in_stack_00000018;
  undefined4 in_stack_0000001c;
  ulong uVar9;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar10;
  ulong in_stack_ffffffec;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar11;
  CInputPort *pCVar12;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff4;
  SInputEvent *in_stack_fffffff8;
  ulong uVar13;
  
  *(undefined4 *)(this + 0x8c) = 0;
  if ((*(int *)(this + 0x20) != 0) && (iVar1 = *(int *)(this + 0x34), iVar1 != 2)) {
    pCVar12 = this;
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      ((void *)(*(int *)(this + 0x20) + 0x2c),unaff_ESI);
    if (param_2 == 0) {
      if (iVar1 == 0) {
        this_00 = *(void **)(DAT_00d731e0 + 0x14);
        if (this_00 == (void *)0x0) {
          this_00 = (void *)(DAT_00d731e0 + 0xa0);
        }
        uVar3 = CMwTimerAdapter::GetTime(this_00,unaff_EDI);
      }
      else {
        uVar3 = *(ulong *)(this + 0x38);
      }
    }
    else {
      in_stack_fffffff8 = (SInputEvent *)0x0;
    }
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,unaff_EBP);
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x2c,pCVar8,(ulong)unaff_EBX);
        unaff_EBX = (code *)0x8f8f34;
        (**(code **)(**(int **)pSVar5 + 0x88))();
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < pCVar4);
    }
    if ((_DAT_00d714a0 & 1) == 0) {
      _DAT_00d714a0 = _DAT_00d714a0 | 1;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d71494,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EBX);
      unaff_EBX = `public:_void___thiscall_CInputPort::ReadCurMapLatestEventsFromHarware(int)'::
                  __l14::_dynamic_atexit_destructor_for__EventStates__;
      _atexit(`public:_void___thiscall_CInputPort::ReadCurMapLatestEventsFromHarware(int)'::__l14::
              _dynamic_atexit_destructor_for__EventStates__);
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&DAT_00d71494,(GmFrustumIso4 *)unaff_EBX);
    iVar1 = param_2;
    uVar9 = 0x8f8f7b;
    CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast
              (&DAT_00d71494,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_2,
               in_stack_ffffffec);
    pCVar7 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0;
    if (iVar1 != 0) {
      do {
        pCVar10 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x8f8f91;
        pCVar11 = pCVar7;
        pGVar6 = CFastBufferCat<class_CFastString,struct_SFastCat>::GetElemInAll
                           ((void *)(*(int *)(this + 0x20) + 0x20),pCVar7,(ulong)pCVar12);
        in_stack_0000001c = *(undefined4 *)(pGVar6 + 4);
        piVar2 = *(int **)pGVar6;
        pCVar12 = (CInputPort *)0x8f8fa4;
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d71494,in_stack_fffffff4);
        pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        uVar13 = uVar3;
        if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar5 = CFastBuffer<struct_SFastCat>::operator[](&DAT_00d71494,pCVar8,uVar9);
            if (*(int **)pSVar5 == piVar2) break;
            pCVar8 = pCVar8 + 1;
          } while (pCVar8 < pCVar4);
        }
        if (pCVar8 == pCVar4) {
          CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem(&DAT_00d71494,pCVar10);
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[](&DAT_00d71494,pCVar8,(ulong)pCVar11);
          *(int **)pSVar5 = piVar2;
          iVar1 = *piVar2;
          pCVar10 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x8f8ff0;
          pCVar11 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)pCVar8;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[](&DAT_00d71494,pCVar8,(ulong)pCVar12);
          if (iVar1 == 0) {
LAB_008f9010:
            *(undefined4 *)(pSVar5 + 4) = 0;
          }
          else if (iVar1 == 1) {
            *(undefined4 *)(pSVar5 + 4) = 0;
          }
          else {
            if (iVar1 != 2) goto LAB_008f9010;
            *(undefined4 *)(pSVar5 + 4) = _DAT_00b2c060;
          }
        }
        uVar3 = uVar13;
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>::
                 GetCatIndexFromIndexInAll
                           ((void *)(*(int *)(uVar13 + 0x20) + 0x20),
                            (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)
                            pCVar7,(ulong)pCVar10);
        uVar9 = 0x8f902c;
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(uVar13 + 0x2c),pCVar4,(ulong)pCVar11);
        piVar2 = *(int **)pSVar5;
        if (piVar2[5] == 0) {
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[](&DAT_00d71494,pCVar8,(ulong)pCVar12);
          pCVar12 = (CInputPort *)&param_1;
          uVar9 = 0x8f9060;
          (**(code **)(*piVar2 + 0x8c))(in_stack_0000001c,&stack0x00000014);
          if (in_stack_00000010 == 0) {
            if (unaff_retaddr != 0.0) {
              *(float *)(pSVar5 + 4) = unaff_retaddr;
            }
          }
          else if (in_stack_00000010 == 1) {
            in_stack_00000018 = ABS(unaff_retaddr);
            if (ABS(*(float *)(pSVar5 + 4)) < in_stack_00000018) {
              if (unaff_retaddr < (float)_DAT_00b50948 == (unaff_retaddr == (float)_DAT_00b50948)) {
                in_stack_00000018 = unaff_retaddr;
                if ((float)_DAT_00b40f30 <= unaff_retaddr) {
                  in_stack_00000018 = _DAT_00b36adc;
                }
                *(float *)(pSVar5 + 4) = in_stack_00000018;
              }
              else {
                in_stack_00000018 = _DAT_00b36184;
                *(float *)(pSVar5 + 4) = _DAT_00b36184;
              }
            }
          }
          else if ((in_stack_00000010 == 2) && (_DAT_00b36158 < unaff_retaddr)) {
            *(float *)(pSVar5 + 4) = unaff_retaddr;
          }
        }
        pCVar7 = pCVar7 + 1;
        this = param_1;
      } while (pCVar7 < in_stack_0000000c);
    }
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (&DAT_00d71494,(CFastBuffer<class_CCrystalFace*> *)pCVar12);
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           (&DAT_00d71494,pCVar8,(ulong)in_stack_0000000c);
        CInputEventsStore::SetState(this + 0x40,(CInputEventsStore *)pSVar5,in_stack_fffffff8,uVar3)
        ;
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < pCVar4);
    }
  }
  return;
}
}

// =================================================
// Function: CInputPort::RumbleAdd
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CInputPort::RumbleAdd
          (CInputPort *this,CInputDevice *param_1,ulong param_2,float param_3,float param_4)
{
{
  int iVar1;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar2;
  float fVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  SSamplerState *pSVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  float unaff_ESI;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  int in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  float in_stack_00000020;
  float in_stack_00000024;
  float in_stack_ffffffe0;
  float fStack_c;
  CInputPort *pCStack_8;
  
  if (((*(int *)(this + 0x20) != 0) && (param_1 != (CInputDevice *)0x0)) &&
     (_DAT_00b41d80 < *(float *)(this + 0x28))) {
    func_0x009c2390();
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,unaff_EDI);
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (uVar4 != 0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x2c,pCVar8,(ulong)unaff_EBP);
        pCVar9 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar5;
        if (*(int *)(pCVar9 + 0x38) != 0) {
          iVar1 = *(int *)(this + 0x20);
          unaff_EBP = pCVar8;
          pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                             ((void *)(iVar1 + 0x20),pCVar8,(ulong)unaff_EBX);
          pCVar2 = *(CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                     **)(pSVar5 + 4);
          pCVar7 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                    *)0x0;
          this = pCStack_8;
          if (pCVar2 != (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                         *)0x0) {
            do {
              unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar7;
              unaff_EBX = pCVar8;
              pSVar6 = CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>::
                       GetElemInCat((void *)(iVar1 + 0x20),pCVar7,(ulong)pCVar8,(ulong)unaff_ESI);
              if ((in_stack_00000014 == *(int *)pSVar6) || (in_stack_00000018 == *(int *)pSVar6)) {
                unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                            (fStack_c * in_stack_00000020);
                fVar3 = (float)in_stack_0000001c;
                if (in_stack_0000001c < 0) {
                  fVar3 = fVar3 + _DAT_00c418d0;
                }
                pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                         (longlong)ROUND(fVar3 * (float)pCStack_8);
                unaff_EBP = pCVar9;
                unaff_ESI = in_stack_00000024;
                CInputDevice::RumbleAdd
                          ((CInputDevice *)param_2,(CInputDevice *)pCVar9,(ulong)unaff_EBX,
                           in_stack_00000024,in_stack_ffffffe0);
                break;
              }
              pCVar7 = pCVar7 + 1;
            } while (pCVar7 < pCVar2);
          }
        }
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < pCVar9);
    }
  }
  return;
}
}

// =================================================
// Function: CInputPort::UpdateAsync
// =================================================
void __thiscall CInputPort::UpdateAsync(CInputPort *this,CInputPortDx8 *param_1)
{
{
  ulong *puVar1;
  CMwTimerAdapter *unaff_ESI;
  CInputPort *in_stack_00000008;
  
  if (*(int *)(this + 0x98) != 0) {
    if (*(int *)(this + 0x90) != 0) goto LAB_008f91e8;
    puVar1 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
    if (*(int *)(this + 0x98) + 0x96U < *puVar1) {
      *(undefined4 *)(this + 0x90) = 1;
      *(undefined4 *)(this + 0x98) = 0;
      OnFocusChanged(this,in_stack_00000008);
      return;
    }
  }
  if (*(int *)(this + 0x90) == 0) {
    return;
  }
LAB_008f91e8:
  InternalGatherLatestInputs(this,in_stack_00000008);
  return;
}
}

