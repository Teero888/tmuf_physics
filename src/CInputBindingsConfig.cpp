// Class implementation: CInputBindingsConfig

// =================================================
// Function: CInputBindingsConfig::CInputBindingsConfig
// =================================================
void __thiscall
CInputBindingsConfig::CInputBindingsConfig(CInputBindingsConfig *this,CInputBindingsConfig *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000008;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000000c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000010;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x14,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x20,in_stack_00000008);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x2c,in_stack_0000000c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x38,in_stack_00000010);
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined **)(this + 0x48) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x4c) = 0;
  return;
}
}

// =================================================
// Function: CInputBindingsConfig::ClearActions
// =================================================
void __thiscall
CInputBindingsConfig::ClearActions(CInputBindingsConfig *this,CInputBindingsConfig *param_1)
{
{
  CFastBuffer<struct_SInputActionDesc_const*>::ResetAndFreeMemory
            (this + 0x20,(CFastBuffer<struct_SInputActionDesc_const*> *)param_1);
  return;
}
}

// =================================================
// Function: CInputBindingsConfig::ClearAllBindings
// =================================================
void __thiscall
CInputBindingsConfig::ClearAllBindings
          (CInputBindingsConfig *this,CInputBindingsConfig *param_1,CMwId *param_2)
{
{
  CInputBindingsConfig *pCVar1;
  CMwId *unaff_ESI;
  CInputBindingsConfig *pCVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CInputBindingsConfig *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI)
  ;
  pCVar2 = (CInputBindingsConfig *)0x0;
  if (pCVar1 != (CInputBindingsConfig *)0x0) {
    do {
      ClearBindings(this,pCVar2,(ulong)param_2,unaff_ESI);
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < pCVar1);
  }
  if (*(int *)param_2 == -1) {
    CFastBuffer<class_CMwId>::ResetAndFreeMemory
              (this + 0x2c,(CFastBuffer<struct_SInputActionDesc_const*> *)unaff_ESI);
    return;
  }
  CFastBuffer<unsigned_int>::RemoveIfFound
            (this + 0x2c,(CFastBuffer<unsigned_int> *)param_2,(uint *)unaff_ESI);
  return;
}
}

// =================================================
// Function: CInputBindingsConfig::ClearBindings
// =================================================
void __thiscall
CInputBindingsConfig::ClearBindings
          (CInputBindingsConfig *this,CInputBindingsConfig *param_1,ulong param_2,CMwId *param_3)
{
{
  CInputBindingsConfig *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x14;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (uVar1 != 0) {
    do {
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar4,unaff_EBP);
      if ((*(ulong *)pSVar2 == param_2) &&
         ((*(int *)param_3 == -1 || (*(int *)(pSVar2 + 4) == *(int *)param_3)))) {
        unaff_EBP = 1;
        CFastBuffer<struct_CInputBindingsConfig::SBinding>::ReplaceByLastAt
                  (this_00,(CFastBufferRef<class_CGameMobil> *)pCVar4,1,unaff_EBX);
        pCVar4 = pCVar4 + -1;
      }
      pCVar4 = pCVar4 + 1;
      unaff_EBX = 0x8f74b0;
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    } while (pCVar4 < pCVar3);
  }
  return;
}
}

// =================================================
// Function: CInputBindingsConfig::FindAction
// =================================================
ulong __thiscall
CInputBindingsConfig::FindAction
          (CInputBindingsConfig *this,CInputBindingsConfig *param_1,SInputActionDesc *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x20,pCVar3,unaff_ESI);
      if (param_2 == *(SInputActionDesc **)pSVar2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CInputBindingsConfig::GetBindings
// =================================================
void __thiscall
CInputBindingsConfig::GetBindings
          (CInputBindingsConfig *this,CInputBindingsConfig *param_1,ulong param_2,
          CFastBuffer<struct_CInputBindingsConfig::SBinding> *param_3,CMwId *param_4)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SLoadedLight *pSVar3;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_SInputActionDesc_const*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  void *in_stack_00000014;
  int *in_stack_00000018;
  
  CFastBuffer<struct_CInputBindingsConfig::SBinding>::ResetAndFreeMemory((void *)param_2,unaff_EDI);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x14,unaff_ESI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this + 0x14,pCVar4,unaff_EBP);
      if ((*(CMwId **)pSVar2 == param_4) &&
         ((*in_stack_00000018 == -1 || (*(int *)(pSVar2 + 4) == *in_stack_00000018)))) {
        unaff_EBP = 0x8f7b2c;
        pSVar3 = CFastBuffer<struct_CInputBindingsConfig::SBinding>::AddNewElem
                           (in_stack_00000014,unaff_EBX);
        *(undefined4 *)pSVar3 = *(undefined4 *)pSVar2;
        *(undefined4 *)(pSVar3 + 4) = *(undefined4 *)(pSVar2 + 4);
        *(undefined4 *)(pSVar3 + 8) = *(undefined4 *)(pSVar2 + 8);
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CInputBindingsConfig::Init
// =================================================
void __thiscall
CInputBindingsConfig::Init
          (CInputBindingsConfig *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
          CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  SCasterCat *pSVar1;
  ulong uVar2;
  CInputBindingsConfig *unaff_ESI;
  COalAudioPort *pCVar3;
  SStringParam *in_stack_fffffff8;
  
  ClearActions(this,unaff_ESI);
  uVar2 = *(ulong *)(param_2 + 4);
  pCVar3 = *(COalAudioPort **)param_2;
  CFastString::SetString
            ((CFastString *)(this + 0x44),(CFastStringInt *)&stack0xfffffffc,in_stack_fffffff8);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000013,uVar2);
  uVar2 = CAudioPort::GetNbMaxSounds(*(CAudioPort **)pSVar1,pCVar3);
  *(ulong *)(this + 0x4c) = uVar2;
  return;
}
}

// =================================================
// Function: CInputBindingsConfig::IsDeviceConfigured
// =================================================
int __thiscall
CInputBindingsConfig::IsDeviceConfigured
          (CInputBindingsConfig *this,CInputBindingsConfig *param_1,CMwId *param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x2c,pCVar4,unaff_ESI);
      if (iVar1 == *(int *)pSVar3) {
        return 1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return 0;
}
}

