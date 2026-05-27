// Class implementation: CControlEffectMaster

// =================================================
// Function: CControlEffectMaster::CleanUp
// =================================================
void __thiscall
CControlEffectMaster::CleanUp
          (CControlEffectMaster *this,CControlEffectMotion *param_1,CControlBase *param_2,
          SParamEffect *param_3)
{
{
  int iVar1;
  void *this_00;
  SCasterCat *pSVar2;
  CControlEffect *pCVar3;
  int *piVar4;
  ulong uVar5;
  ulong unaff_EBX;
  CControlEffectMotion *unaff_EBP;
  CControlEffectMotion *pCVar6;
  SParamEffectMaster *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CControlBase *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CControlEffectMotion *pCVar9;
  CFastBuffer<class_CCrystalFace*> *pCVar10;
  
  ClearCurrentEffect(this,(CControlEffectMaster *)param_1,unaff_EDI);
  pCVar6 = *(CControlEffectMotion **)(param_1 + 0x11c);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (0 < *(int *)(pCVar6 + 0x28)) {
    pCVar9 = pCVar6 + 0x34;
    do {
      pCVar8 = pCVar7;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar9,pCVar7,(ulong)unaff_ESI);
      if (*(int *)pSVar2 != 0) {
        pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x77d0ae;
        pCVar3 = GetEffect((CControlEffectMaster *)param_1,(CControlEffectMaster *)pCVar7,
                           (EEffectMode)unaff_EBP);
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](pCVar9,pCVar7,unaff_EBX);
        unaff_EBX = *(ulong *)pSVar2;
        unaff_ESI = (SParamEffectMaster *)0x77d0c8;
        unaff_EBP = param_1;
        (**(code **)(*(int *)pCVar3 + 0x80))();
        pCVar6 = param_1;
      }
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar9,pCVar7,(ulong)pCVar8);
      pCVar7 = pCVar7 + 1;
      *(undefined4 *)pSVar2 = 0;
    } while ((int)pCVar7 < *(int *)(pCVar6 + 0x28));
  }
  pCVar9 = param_1;
  piVar4 = (int *)(**(code **)(*(int *)param_1 + 0x1b0))();
  iVar1 = *(int *)(pCVar6 + 0x50);
  pCVar6 = param_1 + 0x60;
  piVar4[0x27] = piVar4[0x27] ^ (piVar4[0x27] ^ *(uint *)(iVar1 + 0x9c)) & 0x40;
  piVar4[0x27] = piVar4[0x27] & 0xffffff77U | *(uint *)(iVar1 + 0x9c) & 8;
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (pCVar6,(CFastBuffer<class_CCrystalFace*> *)pCVar9);
  if (uVar5 != 0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar6,pCVar7,(ulong)unaff_ESI);
      unaff_ESI = *(SParamEffectMaster **)pSVar2;
      pCVar10 = (CFastBuffer<class_CCrystalFace*> *)0x77d157;
      (**(code **)(*piVar4 + 0xa0))();
      pCVar7 = pCVar7 + 1;
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(pCVar6,pCVar10);
    } while (pCVar7 < pCVar8);
  }
  this_00 = *(void **)(param_1 + 0x11c);
  if (this_00 != (void *)0x0) {
    SParamEffectMaster::~SParamEffectMaster(this_00,unaff_ESI);
    operator_delete(this_00);
  }
  *(undefined4 *)(param_1 + 0x11c) = 0;
  return;
}
}

// =================================================
// Function: CControlEffectMaster::ClearCurrentEffect
// =================================================
void __thiscall
CControlEffectMaster::ClearCurrentEffect
          (CControlEffectMaster *this,CControlEffectMaster *param_1,CControlBase *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x11c);
  if (*(int **)(iVar1 + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(iVar1 + 0x30) + 0x88))(param_1,*(undefined4 *)(iVar1 + 0x2c));
    *(undefined4 *)(iVar1 + 0x30) = 0;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  return;
}
}

// =================================================
// Function: CControlEffectMaster::GetEffect
// =================================================
CControlEffect * __thiscall
CControlEffectMaster::GetEffect
          (CControlEffectMaster *this,CControlEffectMaster *param_1,EEffectMode param_2)
{
{
  CMwRefBuffer *pCVar1;
  CMwNod *pCVar2;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  switch(param_1) {
  case (CControlEffectMaster *)0x0:
    return *(CControlEffect **)(this + 0x20);
  case (CControlEffectMaster *)0x1:
    return *(CControlEffect **)(this + 0x24);
  case (CControlEffectMaster *)0x2:
    return *(CControlEffect **)(this + 0x28);
  case (CControlEffectMaster *)0x3:
    return *(CControlEffect **)(this + 0x2c);
  case (CControlEffectMaster *)0x4:
    return *(CControlEffect **)(this + 0x30);
  case (CControlEffectMaster *)0x5:
    return *(CControlEffect **)(this + 0x38);
  case (CControlEffectMaster *)0x6:
    return *(CControlEffect **)(this + 0x3c);
  case (CControlEffectMaster *)0x7:
    return *(CControlEffect **)(this + 0x34);
  case (CControlEffectMaster *)0x8:
    return *(CControlEffect **)(this + 0x40);
  case (CControlEffectMaster *)0x9:
    return *(CControlEffect **)(this + 0x44);
  }
  if (*(CMwRefBuffer **)(this + 0x48) != (CMwRefBuffer *)0x0) {
    pCVar1 = (CMwRefBuffer *)CMwRefBuffer::GetCount(*(CMwRefBuffer **)(this + 0x48),unaff_EDI);
    if (pCVar1 < (CMwRefBuffer *)(param_1 + -10)) {
      return (CControlEffect *)0x0;
    }
    pCVar2 = CMwRefBuffer::GetFromIndex
                       (*(CMwRefBuffer **)(this + 0x48),(CMwRefBuffer *)(param_1 + -10),unaff_ESI);
    return (CControlEffect *)pCVar2;
  }
  return (CControlEffect *)0x0;
}
}

// =================================================
// Function: CControlEffectMaster::Init
// =================================================
void __thiscall
CControlEffectMaster::Init
          (CControlEffectMaster *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
          CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  CControlEffectMaster *this_00;
  CControlEffectMaster *this_01;
  int *piVar1;
  SParamEffectMaster *pSVar2;
  void *this_02;
  int extraout_EAX;
  CControlEffect *pCVar3;
  int iVar4;
  SCasterCat *pSVar5;
  undefined4 uVar6;
  ulong uVar7;
  CMwCmdFastCall *this_03;
  CMwNod *extraout_EAX_00;
  TiXmlAttribute *unaff_ESI;
  CMwNod *this_04;
  TiXmlAttributeSet *unaff_EDI;
  CControlEffectMaster *pCVar8;
  CControlEffectMaster *pCStack_14;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ac81e6;
  local_c = ExceptionList;
  pSVar2 = (SParamEffectMaster *)(DAT_00cca150 ^ (uint)&stack0xffffffd8);
  ExceptionList = &local_c;
  this_02 = operator_new(0x70);
  pCVar8 = (CControlEffectMaster *)0x0;
  local_4 = 0;
  if (this_02 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    SParamEffectMaster::SParamEffectMaster(this_02,pSVar2);
    iVar4 = extraout_EAX;
  }
  *(int *)(param_2 + 0x11c) = iVar4;
  if (this != *(CControlEffectMaster **)(iVar4 + 4)) {
    if (this != (CControlEffectMaster *)0x0) {
      CMwNod::MwAddRef((CMwNod *)this,(CMwNod *)unaff_EDI);
    }
    if (*(CMwNod **)(iVar4 + 4) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(iVar4 + 4),(CMwNod *)unaff_EDI);
    }
    *(CControlEffectMaster **)(iVar4 + 4) = this;
  }
  this_01 = *(CControlEffectMaster **)(param_2 + 0x11c);
  *(undefined4 *)(this_01 + 0x28) = 10;
  local_c = (void *)0x0;
  this_00 = this_01 + 0x34;
  do {
    pCVar3 = GetEffect(this,pCVar8,(EEffectMode)unaff_EDI);
    unaff_EDI = (TiXmlAttributeSet *)&local_8;
    CFastBuffer<class_CDx9TextureKeeper*>::Add(this_00,unaff_EDI,unaff_ESI);
    if (pCVar3 != (CControlEffect *)0x0) {
      unaff_EDI = (TiXmlAttributeSet *)0x77cf2c;
      unaff_ESI = (TiXmlAttribute *)param_4;
      iVar4 = (**(code **)(*(int *)pCVar3 + 0x78))();
      if (iVar4 != 0) {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar8,
                            (ulong)unaff_EDI);
        unaff_EDI = (TiXmlAttributeSet *)param_3;
        uVar6 = (**(code **)(*(int *)pCVar3 + 0x7c))();
        *(undefined4 *)pSVar5 = uVar6;
      }
    }
    pCVar8 = pCVar8 + 1;
    this = pCStack_14;
  } while ((int)pCVar8 < 10);
  if (*(CMwRefBuffer **)(pCStack_14 + 0x48) != (CMwRefBuffer *)0x0) {
    uVar7 = CMwRefBuffer::GetCount
                      (*(CMwRefBuffer **)(pCStack_14 + 0x48),
                       (CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
    *(ulong *)(this_01 + 0x28) = *(int *)(this_01 + 0x28) + uVar7;
    pCVar8 = (CControlEffectMaster *)&DAT_0000000a;
    if (10 < *(uint *)(this_01 + 0x28)) {
      local_8 = (undefined1 *)0x0;
      do {
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (this_00,(TiXmlAttributeSet *)&local_c,(TiXmlAttribute *)unaff_EDI);
        unaff_EDI = (TiXmlAttributeSet *)pCVar8;
        pCVar3 = GetEffect(this_01,pCVar8,(EEffectMode)unaff_ESI);
        if (pCVar3 != (CControlEffect *)0x0) {
          unaff_EDI = (TiXmlAttributeSet *)0x77cfa8;
          unaff_ESI = (TiXmlAttribute *)param_4;
          iVar4 = (**(code **)(*(int *)pCVar3 + 0x78))();
          if (iVar4 != 0) {
            pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar8,
                                (ulong)unaff_EDI);
            unaff_EDI = (TiXmlAttributeSet *)param_3;
            uVar6 = (**(code **)(*(int *)pCVar3 + 0x7c))();
            *(undefined4 *)pSVar5 = uVar6;
          }
        }
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < *(CControlEffectMaster **)(this_01 + 0x28));
    }
  }
  if (param_3 == (CVisionViewportDx9 *)0x0) {
    this_03 = operator_new(0x24);
    if (this_03 == (CMwCmdFastCall *)0x0) {
      this_04 = (CMwNod *)0x0;
    }
    else {
      CMwCmdFastCall::CMwCmdFastCall
                (this_03,(CMwCmdFastCall *)param_2,(CMwNod *)CGameCtnMenus::_vcall__460__flat______,
                 (_func___cdecl_void *)unaff_EDI,(ulong)unaff_ESI);
      this_04 = extraout_EAX_00;
    }
    piVar1 = *(int **)(param_2 + 0x11c);
    if (this_04 != (CMwNod *)*piVar1) {
      if (this_04 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(this_04,(CMwNod *)unaff_EDI);
      }
      if ((CMwNod *)*piVar1 != (CMwNod *)0x0) {
        CMwNod::MwRelease((CMwNod *)*piVar1,(CMwNod *)unaff_EDI);
      }
      *piVar1 = (int)this_04;
    }
    CMwCmd::SetSchemeLocation((CMwCmd *)this_04,(CMwCmd *)&DAT_00000012,(ulong)unaff_EDI);
    (**(code **)(*(int *)this_04 + 0x7c))();
  }
  ExceptionList = local_8;
  return;
}
}

