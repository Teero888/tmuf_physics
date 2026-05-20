// Class implementation: CInputDevice

// =================================================
// Function: CInputDevice::RumbleAdd
// =================================================
void __thiscall
CInputDevice::RumbleAdd
          (CInputDevice *this,CInputDevice *param_1,ulong param_2,float param_3,float param_4)
{
{
  CInputDevice *this_00;
  CInputDevice *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  ulong *puVar4;
  CMwTimerAdapter *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CMwTimerAdapter *unaff_EDI;
  float *in_stack_fffffff4;
  CInputDevice *local_8;
  float local_4;
  
  if (param_1 == (CInputDevice *)0x0) {
    pCVar1 = (CInputDevice *)0x0;
  }
  else {
    puVar4 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_EDI);
    pCVar1 = param_1 + *puVar4;
  }
  local_4 = param_3;
  local_8 = pCVar1;
  if (param_1 == (CInputDevice *)0x0) {
    this_00 = this + 0x48;
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    if (uVar2 != 0) {
      unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x0;
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)unaff_EBX);
      if (*(int *)pSVar3 == 0) {
        unaff_EBX = (CMwTimerAdapter *)0x0;
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)in_stack_fffffff4);
        *(CInputDevice **)pSVar3 = pCVar1;
        *(ulong *)(pSVar3 + 4) = param_2;
        *(float *)(pSVar3 + 8) = param_3;
        goto LAB_008fce74;
      }
    }
    CFastBuffer<struct_CInputDevice::SRumble>::InsertElemAt
              (this_00,(CFastBuffer<struct_CInputDevice::SRumble> *)0x0,(ulong)&local_8,
               (SRumble *)unaff_ESI);
  }
  else {
    CFastBuffer<struct_CInputEventsStore::SCachedValue>::Add
              (this + 0x48,(TiXmlAttributeSet *)&local_8,(TiXmlAttribute *)unaff_ESI);
  }
LAB_008fce74:
  puVar4 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_EBX);
  RumbleCompute(this,(CInputDevice *)*puVar4,(ulong)&stack0x00000014,&param_4,in_stack_fffffff4);
  return;
}
}

// =================================================
// Function: CInputDevice::RumbleCompute
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CInputDevice::RumbleCompute
          (CInputDevice *this,CInputDevice *param_1,ulong param_2,float *param_3,float *param_4)
{
{
  CInputDevice *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong in_stack_ffffffc8;
  ulong in_stack_ffffffcc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffd0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  float fVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  float local_18;
  float local_14;
  float fStack_10;
  
  fVar5 = 0.0;
  local_18 = 0.0;
  this_00 = this + 0x48;
  local_14 = 0.0;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (uVar1 == 0) {
    local_18 = 0.0;
  }
  else {
    do {
      uVar1 = 0x8fcc89;
      pCVar4 = pCVar3;
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar3,(ulong)unaff_ESI);
      if (*(int *)pSVar2 == 0) {
LAB_008fcca9:
        pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,pCVar3,in_stack_ffffffc8);
        pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar2 + 4);
        if ((float)pCVar6 < (float)pCVar4 == ((float)pCVar6 == (float)pCVar4)) {
          pCVar4 = pCVar6;
        }
        pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,pCVar3,in_stack_ffffffcc);
        local_18 = SUB84((double)*(float *)(pSVar2 + 8),0);
        local_14 = (float)((ulonglong)(double)*(float *)(pSVar2 + 8) >> 0x20);
        in_stack_ffffffc8 = 0x8fccea;
        pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,pCVar3,(ulong)in_stack_ffffffd0);
        fVar5 = *(float *)(pSVar2 + 4) * (float)(double)CONCAT44(fStack_10,local_14) + (float)pCVar6
        ;
        in_stack_ffffffcc = 0x8fcd01;
        in_stack_ffffffd0 = pCVar3;
        pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this_00,pCVar3,uVar1);
        local_14 = *(float *)(pSVar2 + 4) + local_14;
      }
      else {
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x8fcc96;
        unaff_ESI = pCVar3;
        pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,pCVar3,unaff_EBX);
        if (param_1 <= *(CInputDevice **)pSVar2) goto LAB_008fcca9;
        unaff_EBX = 1;
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x8fcca4;
        unaff_ESI = pCVar3;
        CFastBuffer<struct_CNetConnection::SEmmissionElem>::RemoveAt
                  (this_00,(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)pCVar3,1,
                   (ulong)fVar5);
        pCVar3 = pCVar3 + -1;
      }
      pCVar3 = pCVar3 + 1;
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this_00,(CFastBuffer<class_CCrystalFace*> *)pCVar4);
    } while (pCVar3 < pCVar4);
    if (local_18 < 0.0 == (local_18 == 0.0)) {
      if (1.0 < local_18 != (local_18 == 1.0)) {
        local_18 = 1.0;
      }
    }
    else {
      local_18 = 0.0;
    }
  }
  *(float *)param_2 = local_18;
  local_14 = local_14 / (fStack_10 + (float)_DAT_00b362c0);
  if (local_14 < 0.0 != (local_14 == 0.0)) {
    *param_3 = 0.0;
    return;
  }
  if (_DAT_00b3d270 < local_14 == (_DAT_00b3d270 == local_14)) {
    *param_3 = local_14;
    return;
  }
  *param_3 = _DAT_00b3d270;
  return;
}
}

