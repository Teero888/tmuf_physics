// Class implementation: CTrackManiaEditorInterface

// =================================================
// Function: CTrackManiaEditorInterface::BackStep
// =================================================
int __thiscall
CTrackManiaEditorInterface::BackStep
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1)
{
{
  int iVar1;
  ulong uVar2;
  SNewTriangleVert *pSVar3;
  SCasterCat *pSVar4;
  CTrackManiaEditorInterface *unaff_EBX;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CTrackManiaEditor *unaff_EDI;
  CMwNodRef<class_CSceneObjectLink> *unaff_retaddr;
  CMwNodRef<class_CSceneObjectLink> *this_00;
  ulong in_stack_00000008;
  undefined4 uStack0000000c;
  CTrackManiaEditorInterface *in_stack_00000018;
  CTrackManiaEditorInterface *pCVar5;
  
  if ((*(int *)(this + 0x38) == 0) || (*(int *)(this + 0x38) != 1)) {
    return 0;
  }
  pCVar5 = this;
  iVar1 = CTrackManiaEditor::IsPuzzlePlaceType(*(CTrackManiaEditor **)(this + 0x34),unaff_EDI);
  if ((iVar1 != 0) &&
     (iVar1 = CFastBuffer<class_CAudioSound*>::IsEmpty(this + 0x3c,(SShaderCustom *)pCVar5),
     iVar1 != 0)) {
    return 0;
  }
  pCVar5 = this + 0x3c;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar5,unaff_ESI);
  if (uVar2 == 0) {
    *(undefined4 *)(this + 0x38) = 0;
    UpdateCurrentLevel(this,unaff_EBX);
    SelectIcon(this,*(CTrackManiaEditorInterface **)(this + 0x48),(ulong)unaff_retaddr);
    *(undefined4 *)(this + 0x48) = 0xffffffff;
    return 1;
  }
  pSVar3 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(pCVar5,unaff_EBP);
  uStack0000000c = *(undefined4 *)(*(int *)pSVar3 + 4);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar5,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 - 1),
                      (ulong)unaff_EBX);
  this_00 = *(CMwNodRef<class_CSceneObjectLink> **)pSVar4;
  if (this_00 != (CMwNodRef<class_CSceneObjectLink> *)0x0) {
    CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>(this_00,unaff_retaddr);
    operator_delete(this_00);
    unaff_retaddr = this_00;
  }
  CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt
            (pCVar5,(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)(uVar2 - 1),1,
             (ulong)unaff_retaddr);
  UpdateCurrentLevel(this,param_1);
  SelectIcon(this,in_stack_00000018,in_stack_00000008);
  return 1;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::GetCurrentArticle
// =================================================
CGameCtnArticle * __thiscall
CTrackManiaEditorInterface::GetCurrentArticle
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1)
{
{
  CTrackManiaEditorIcon *pCVar1;
  CTrackManiaEditorInterface *unaff_ESI;
  
  pCVar1 = GetCurrentIcon(this,unaff_ESI);
  if (((pCVar1 != (CTrackManiaEditorIcon *)0x0) && (*(int *)(pCVar1 + 0x14) == 0)) &&
     (*(int *)(this + 0x38) != 0)) {
    return *(CGameCtnArticle **)(pCVar1 + 0x18);
  }
  return (CGameCtnArticle *)0x0;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::GetCurrentIcon
// =================================================
CTrackManiaEditorIcon * __thiscall
CTrackManiaEditorInterface::GetCurrentIcon
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x74);
  if (-1 < (int)pCVar1) {
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x68,unaff_EDI);
    if ((int)pCVar1 < (int)uVar2) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x68,pCVar1,unaff_ESI);
      return (CTrackManiaEditorIcon *)**(undefined4 **)pSVar3;
    }
  }
  return (CTrackManiaEditorIcon *)0x0;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::SelectIcon
// =================================================
int __thiscall
CTrackManiaEditorInterface::SelectIcon
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1,ulong param_2)
{
{
  CTrackManiaEditorInterface *this_00;
  uint *puVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  CTrackManiaEditorInterface *in_stack_0000000c;
  CTrackManiaEditorInterface *in_stack_00000010;
  
  this_00 = this + 0x68;
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (param_2 < uVar3) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_ESI)
    ;
    if (**(int **)pSVar4 != 0) {
      pCVar2 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x78);
      if (pCVar2 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2) {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                            unaff_EBP);
        if ((*(uint *)(*(int *)(*(int *)pSVar4 + 8) + 0xfc) & 0x2000) != 0) {
          return 0;
        }
      }
      uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
      if (((int)pCVar2 < (int)uVar3) && (-1 < (int)pCVar2)) {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar2,unaff_retaddr);
        puVar1 = (uint *)(*(int *)(*(int *)pSVar4 + 8) + 0xfc);
        *puVar1 = *puVar1 & 0xffffdfff;
      }
      *(ulong *)(this + 0x74) = param_2;
      *(ulong *)(this + 0x78) = param_2;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                          (ulong)param_1);
      if ((*(int *)(**(int **)pSVar4 + 0x14) == 0) && (*(int *)(this + 0x38) != 0)) {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                            param_2);
        puVar1 = (uint *)(*(int *)(*(int *)pSVar4 + 8) + 0xfc);
        *puVar1 = *puVar1 | 0x2000;
      }
      UpdateIconsStyle(this,in_stack_0000000c);
      UpdateAllocatedValue(this,in_stack_00000010);
      CControlTools::ControlSetReadOnlyAndDraw
                (*(CControlBase **)(*(int *)(this + 0x60) + 8),(uint)(*(int *)(this + 0x38) == 0),0)
      ;
      CControlTools::ControlDraw(*(CControlBase **)(*(int *)(this + 0x60) + 8));
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::SetContextualHelpMessage
// =================================================
void __thiscall
CTrackManiaEditorInterface::SetContextualHelpMessage
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1,
          CFastStringInt *param_2)
{
{
  CControlLabel *this_00;
  CFastStringInt *unaff_ESI;
  
  if ((*(int *)(this + 100) != 0) &&
     (this_00 = *(CControlLabel **)(*(int *)(this + 100) + 4), this_00 != (CControlLabel *)0x0)) {
    CControlLabel::SetLabel(this_00,(CControlButton *)param_1,unaff_ESI);
    (**(code **)(**(int **)(*(int *)(this + 100) + 4) + 0x1a8))();
  }
  return;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::Show
// =================================================
void __thiscall
CTrackManiaEditorInterface::Show(CTrackManiaEditorInterface *this,CSceneToyMotorbike *param_1)
{
{
  if (*(CScene2d **)(this + 0x28) != (CScene2d *)0x0) {
    CScene2d::SetVisibleInterface(*(CScene2d **)(this + 0x28),1);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::UpdateAllocatedValue
// =================================================
void __thiscall
CTrackManiaEditorInterface::UpdateAllocatedValue
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1)
{
{
  int iVar1;
  ulong uVar2;
  CGameCtnArticle *pCVar3;
  CTrackManiaEditorInterface *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  SStringParam *in_stack_fffffff8;
  
  iVar1 = *(int *)(this + 0x74);
  if (-1 < iVar1) {
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x68,unaff_EDI);
    if (iVar1 < (int)uVar2) {
      pCVar3 = GetCurrentArticle(this,unaff_ESI);
      iVar1 = *(int *)(this + 0x58);
      if (iVar1 != 0) {
        if (pCVar3 != (CGameCtnArticle *)0x0) {
          CFastString::SetNatural
                    ((CFastString *)(iVar1 + 0x10),
                     (CFastString *)(*(uint *)(pCVar3 + 0x80) ^ *(uint *)(pCVar3 + 0x7c)),1,0,0,0,1,
                     (int)in_stack_fffffff8);
          return;
        }
        CFastString::SetString
                  ((CFastString *)(iVar1 + 0x10),(CFastStringInt *)&stack0x00000000,
                   in_stack_fffffff8);
      }
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::UpdateAmount
// =================================================
void __thiscall
CTrackManiaEditorInterface::UpdateAmount
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1,
          CGameCtnArticle *param_2)
{
{
  CTrackManiaEditorInterface *this_00;
  CGameCtnArticle *pCVar1;
  CTrackManiaEditorInterface *pCVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CControlButton *extraout_EAX;
  undefined *puVar5;
  int unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EDI;
  undefined4 uStack0000000c;
  undefined *in_stack_0000001c;
  undefined1 uStack00000020;
  undefined1 uStack00000028;
  SStringParam *in_stack_ffffffd8;
  SStringParam *in_stack_ffffffdc;
  undefined *puVar7;
  SStringParam *in_stack_ffffffe0;
  ulong uVar8;
  undefined *puVar9;
  CFastStringInt *pCVar10;
  ulong uVar11;
  CTrackManiaEditorInterface *local_c;
  undefined1 *local_8;
  CGameCtnArticle *local_4;
  
  local_4 = (CGameCtnArticle *)0xffffffff;
  local_8 = &LAB_00a8e2a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = this + 0x68;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)
                              (DAT_00cca150 ^ (uint)&stack0xffffffc4));
  pCVar1 = param_2;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar6,(ulong)unaff_EDI);
      if ((*(int *)(**(int **)pSVar4 + 0x14) == 0) &&
         (unaff_EDI = pCVar6,
         pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this_00,pCVar6,unaff_ESI),
         *(CGameCtnArticle **)(**(int **)pSVar4 + 0x18) == pCVar1)) {
        if (pCVar6 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
          ExceptionList = local_8;
          return;
        }
        if (*(int *)(*(int *)(in_stack_ffffffe0 + 0x34) + 0x38) != 3) {
          ExceptionList = local_8;
          return;
        }
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar6,unaff_EBP)
        ;
        puVar7 = PTR_DAT_00bbf7d8;
        if (*(int *)(*(int *)pSVar4 + 0x10) == 0) {
          ExceptionList = local_8;
          return;
        }
        uVar11 = 0;
        uVar8 = 0;
        uStack0000000c = 1;
        pCVar10 = (CFastStringInt *)PTR_DAT_00bbf7d8;
        CFastString::SetNatural
                  ((CFastString *)&stack0xffffffec,
                   (CFastString *)(*(uint *)(pCVar1 + 0x80) ^ *(uint *)(pCVar1 + 0x7c)),1,0,0,0,1,
                   unaff_EBX);
        CFastString::SetNatural
                  ((CFastString *)&stack0xffffffe8,*(CFastString **)(pCVar1 + 0x84),1,0,0,0,1,
                   (int)this);
        local_4 = (CGameCtnArticle *)&DAT_00b2ce74;
        CFastString::Concat((CFastString *)&local_c,(CFastStringInt *)&local_4,in_stack_ffffffd8);
        pCVar2 = local_c;
        param_1 = (CTrackManiaEditorInterface *)puVar7;
        CFastString::Concat((CFastString *)&local_8,(CFastStringInt *)&stack0x00000000,
                            in_stack_ffffffdc);
        param_1 = pCVar2;
        param_2 = local_4;
        CFastStringInt::CFastStringInt
                  (&stack0x0000000c,(CFastStringInt *)&param_1,in_stack_ffffffe0);
        uStack00000020 = 2;
        puVar7 = (undefined *)0x4d53eb;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar6,uVar8);
        CControlLabel::SetLabel(*(CControlLabel **)(*(int *)pSVar4 + 0x10),extraout_EAX,pCVar10);
        uStack00000028 = 1;
        if (in_stack_0000001c != PTR_DAT_00bbf7dc) {
          if ((in_stack_0000001c[-1] & 0x80) == 0) {
            in_stack_0000001c = in_stack_0000001c + -2;
          }
          else {
            in_stack_0000001c = in_stack_0000001c + -4;
          }
          operator_delete__(in_stack_0000001c);
        }
        puVar9 = (undefined *)0x4d5426;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar6,uVar11);
        (**(code **)(**(int **)(*(int *)pSVar4 + 0x10) + 0x1a8))();
        if (puVar7 != PTR_DAT_00bbf7d8) {
          puVar5 = puVar7 + -1;
          if ((puVar7[-1] & 0x80) != 0) {
            puVar5 = puVar7 + -4;
          }
          operator_delete__(puVar5);
        }
        if (puVar9 == PTR_DAT_00bbf7d8) {
          ExceptionList = local_8;
          return;
        }
        puVar7 = puVar9 + -1;
        if ((puVar9[-1] & 0x80) != 0) {
          puVar7 = puVar9 + -4;
        }
        operator_delete__(puVar7);
        ExceptionList = local_8;
        return;
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar3);
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::UpdateCurrentLevel
// =================================================
void __thiscall
CTrackManiaEditorInterface::UpdateCurrentLevel
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1)
{
{
  CTrackManiaEditorInterface *this_00;
  ulong uVar1;
  int iVar2;
  SNewTriangleVert *pSVar3;
  SCasterCat *pSVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  undefined4 extraout_EAX_01;
  CTrackManiaEditorIcon *pCVar6;
  CFuncEnum *pCVar7;
  int extraout_EAX_02;
  int extraout_EAX_03;
  undefined4 extraout_EAX_04;
  SCasterCat *pSVar8;
  undefined4 extraout_EAX_05;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  CTrackManiaEditorInterface *pCVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CTrackManiaEditor *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_retaddr;
  CTrackManiaEditorIconPage *in_stack_00000008;
  CTrackManiaEditorIconPage *in_stack_0000000c;
  CTrackManiaEditorInterface *in_stack_00000010;
  ulong in_stack_00000014;
  undefined4 *in_stack_00000018;
  CFuncEnum *in_stack_0000001c;
  CFuncEnum *in_stack_00000020;
  ulong in_stack_00000024;
  int *in_stack_00000030;
  ulong in_stack_ffffffe4;
  CControlBase *pCVar11;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff8;
  CMwParamFastBuffer<class_CMwParamVec4> *in_stack_fffffffc;
  CMwParamFastBuffer<class_CMwParamVec4> *pCVar12;
  ulong uVar13;
  
  this_00 = this + 0x68;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  if (uVar1 == 0) {
    return;
  }
  if (*(int *)(this + 0x38) == 0) {
    iVar2 = CTrackManiaEditor::IsPuzzlePlaceType(*(CTrackManiaEditor **)(this + 0x34),unaff_EDI);
    if (iVar2 != 0) {
      return;
    }
    *(undefined4 *)(this + 0x70) = 0;
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this + 0x4c,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
      if (pCVar10 < pCVar5) {
        *(int *)(this + 0x70) = *(int *)(this + 0x70) + 1;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x4c,pCVar10,(ulong)unaff_EBX);
        unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d59e0;
        pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)in_stack_fffffff8);
        CTrackManiaEditorIconPage::GetIcon
                  (*(CTrackManiaEditorIconPage **)pSVar4,
                   (CMwParamFastBuffer<class_CMwParamVec4> *)0x0,(EMwIconList *)in_stack_fffffffc,
                   (EMwIconList *)unaff_retaddr);
        *(undefined4 *)*in_stack_00000018 = extraout_EAX_05;
        uVar13 = 0x4d59fe;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)param_1);
        (**(code **)(**(int **)(*(int *)pSVar4 + 4) + 0x100))();
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)in_stack_00000008);
        uVar1 = 0x4d5a22;
        CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 4),1);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x4c,pCVar10,(ulong)in_stack_0000000c);
        pCVar6 = CTrackManiaEditorIconPage::GetRepresentativeArticleIcon
                           (*(CTrackManiaEditorIconPage **)pSVar4,
                            (CTrackManiaEditorIconPage *)pSVar8);
        in_stack_0000000c = (CTrackManiaEditorIconPage *)0xffffffff;
        in_stack_00000008 = (CTrackManiaEditorIconPage *)0x4d5a43;
        pCVar7 = CGameCtnArticle::CreateIcon
                           (*(CGameCtnArticle **)(pCVar6 + 0x18),(CGameCtnArticle *)0xffffffff,1,
                            in_stack_00000014);
        in_stack_00000010 = (CTrackManiaEditorInterface *)0x4d5a4d;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)in_stack_00000018);
        (**(code **)(**(int **)(*(int *)pSVar4 + 8) + 0x1ac))();
        in_stack_00000014 = 0x4d5a64;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)in_stack_0000001c);
        in_stack_00000018 = (undefined4 *)0x4d5a6f;
        CControlButton::SetIcons
                  (*(CControlButton **)(*(int *)pSVar4 + 8),(CControlButton *)pCVar7,
                   in_stack_00000020);
        in_stack_0000001c = (CFuncEnum *)0x4d5a77;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,in_stack_00000024);
        in_stack_00000024 = 0x4d5a86;
        (**(code **)(**(int **)(*(int *)pSVar4 + 8) + 0x1a8))();
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar10,uVar13);
        unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5a9b;
        CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 8),1);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar10,uVar1);
        in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d5ab3;
        CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 0xc),1);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar10,0x4d5a2e)
        ;
        unaff_retaddr = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)pSVar4 + 0x10);
        in_stack_00000020 = (CFuncEnum *)pCVar10;
      }
      else {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)unaff_EBX);
        **(undefined4 **)pSVar4 = 0;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)in_stack_fffffff8);
        unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5983;
        CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 4),0);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)in_stack_fffffffc);
        unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d599b;
        CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 8),0);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)unaff_retaddr);
        in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d59b3;
        CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 0xc),0);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar10,(ulong)param_1);
        unaff_retaddr = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)pSVar4 + 0x10);
      }
      param_1 = (CTrackManiaEditorInterface *)0x0;
      in_stack_fffffffc = (CMwParamFastBuffer<class_CMwParamVec4> *)0x4d5acb;
      CControlTools::ControlSetVisible((CControlBase *)unaff_retaddr,0);
      pCVar10 = pCVar10 + 1;
    } while (pCVar10 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009);
  }
  else if (*(int *)(this + 0x38) == 1) {
    pCVar11 = (CControlBase *)0x4d54d8;
    iVar2 = CTrackManiaEditor::IsPuzzlePlaceType(*(CTrackManiaEditor **)(this + 0x34),unaff_EDI);
    pCVar9 = this + 0x3c;
    if (iVar2 == 0) {
      uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (pCVar9,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
      if (uVar1 == 0) {
        unaff_EBP = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x48);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x4c,unaff_EBP,(ulong)unaff_EBX);
        in_stack_00000008 = *(CTrackManiaEditorIconPage **)pSVar4;
      }
      else {
        unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d571d;
        pSVar3 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem
                           (pCVar9,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                    *)unaff_EBX);
        pCVar12 = *(CMwParamFastBuffer<class_CMwParamVec4> **)(*(int *)pSVar3 + 4);
        unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5729;
        uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar9,in_stack_fffffff8);
        if (uVar1 == 1) {
          unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d573a;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0x4c,
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x48),
                              (ulong)in_stack_fffffffc);
          in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d5742;
          CTrackManiaEditorIconPage::GetIcon
                    (*(CTrackManiaEditorIconPage **)pSVar4,pCVar12,(EMwIconList *)unaff_retaddr,
                     (EMwIconList *)param_1);
          in_stack_00000018 = *(undefined4 **)(extraout_EAX_02 + 0x14);
          in_stack_fffffffc = pCVar12;
        }
        else {
          pSVar3 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem
                             (pCVar9,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                      *)in_stack_fffffffc);
          in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d575f;
          CTrackManiaEditorIconPage::GetIcon
                    (*(CTrackManiaEditorIconPage **)(**(int **)pSVar3 + 0x14),pCVar12,
                     (EMwIconList *)unaff_retaddr,(EMwIconList *)param_1);
          in_stack_00000018 = *(undefined4 **)(extraout_EAX_03 + 0x14);
          in_stack_fffffffc = pCVar12;
        }
      }
      pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      *(undefined4 *)(this + 0x70) = 0;
      do {
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (unaff_retaddr + 0x1c,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
        if (pCVar10 < pCVar5) {
          *(int *)(this + 0x70) = *(int *)(this + 0x70) + 1;
          uVar1 = 0x4d5806;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)unaff_EBX);
          unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5812;
          unaff_EBX = pCVar10;
          CTrackManiaEditorIconPage::GetIcon
                    (in_stack_00000008,(CMwParamFastBuffer<class_CMwParamVec4> *)pCVar10,
                     (EMwIconList *)in_stack_fffffff8,(EMwIconList *)in_stack_fffffffc);
          **(undefined4 **)pSVar4 = extraout_EAX_04;
          in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d581f;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)unaff_retaddr);
          if (*(int *)(**(int **)pSVar4 + 0x14) == 0) {
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar10,(ulong)param_1);
            in_stack_fffffffc = (CMwParamFastBuffer<class_CMwParamVec4> *)0x4d583e;
            CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 4),0);
            unaff_retaddr = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5849;
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar10,(ulong)in_stack_00000008);
            pCVar9 = *(CTrackManiaEditorInterface **)(**(int **)pSVar4 + 0x18);
            param_1 = (CTrackManiaEditorInterface *)0x4d5858;
            UpdateAmount(this,pCVar9,(CGameCtnArticle *)in_stack_0000000c);
          }
          else {
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar10,(ulong)param_1);
            in_stack_fffffffc = (CMwParamFastBuffer<class_CMwParamVec4> *)0x4d586c;
            CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 4),1);
            unaff_retaddr = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5877;
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar10,(ulong)in_stack_00000008);
            pCVar6 = CTrackManiaEditorIconPage::GetRepresentativeArticleIcon
                               (*(CTrackManiaEditorIconPage **)(**(int **)pSVar4 + 0x14),
                                in_stack_0000000c);
            pCVar9 = *(CTrackManiaEditorInterface **)(pCVar6 + 0x18);
            param_1 = (CTrackManiaEditorInterface *)pCVar10;
          }
          in_stack_00000008 = (CTrackManiaEditorIconPage *)0x4d588e;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)in_stack_00000010);
          (**(code **)(**(int **)(*(int *)pSVar4 + 8) + 0x1ac))();
          CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                    (this_00,pCVar10,in_stack_00000014);
          in_stack_00000010 = (CTrackManiaEditorInterface *)0xffffffff;
          in_stack_0000000c = (CTrackManiaEditorIconPage *)0x4d58b4;
          pCVar7 = CGameCtnArticle::CreateIcon
                             ((CGameCtnArticle *)pCVar9,(CGameCtnArticle *)0xffffffff,1,
                              (int)in_stack_00000018);
          in_stack_00000014 = 0x4d58c3;
          CControlButton::SetIcons
                    (*(CControlButton **)(*in_stack_00000030 + 8),(CControlButton *)pCVar7,
                     in_stack_0000001c);
          in_stack_00000018 = (undefined4 *)0x4d58cb;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)in_stack_00000020);
          in_stack_00000020 = (CFuncEnum *)0x4d58da;
          (**(code **)(**(int **)(*(int *)pSVar4 + 8) + 0x1a8))();
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,in_stack_ffffffe4);
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 8),1);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)pCVar11);
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 0xc),1);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar10,uVar1);
          pCVar11 = *(CControlBase **)(*(int *)pSVar4 + 0x10);
          iVar2 = 0;
          in_stack_0000001c = (CFuncEnum *)pCVar10;
        }
        else {
          iVar2 = 0x4d5798;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)unaff_EBX);
          **(undefined4 **)pSVar4 = 0;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)in_stack_fffffff8);
          unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d57b5;
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 4),0);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)in_stack_fffffffc);
          unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d57cd;
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 8),0);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)unaff_retaddr);
          in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d57e5;
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 0xc),0);
          in_stack_fffffffc = (CMwParamFastBuffer<class_CMwParamVec4> *)0x4d57f0;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)param_1);
          unaff_retaddr =
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)pSVar4 + 0x10);
          param_1 = (CTrackManiaEditorInterface *)0x0;
        }
        in_stack_ffffffe4 = 0x4d591f;
        CControlTools::ControlSetVisible(pCVar11,iVar2);
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009);
    }
    else {
      uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (pCVar9,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
      if (uVar1 == 0) {
        unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x4c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)unaff_EBX);
        in_stack_00000008 = *(CTrackManiaEditorIconPage **)pSVar4;
      }
      else {
        unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d54f5;
        pSVar3 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem
                           (pCVar9,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                    *)unaff_EBX);
        pCVar12 = *(CMwParamFastBuffer<class_CMwParamVec4> **)(*(int *)pSVar3 + 4);
        unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5501;
        uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar9,in_stack_fffffff8);
        if (uVar1 == 1) {
          unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5512;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0x4c,
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x48),
                              (ulong)in_stack_fffffffc);
          in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d551a;
          CTrackManiaEditorIconPage::GetIcon
                    (*(CTrackManiaEditorIconPage **)pSVar4,pCVar12,(EMwIconList *)unaff_retaddr,
                     (EMwIconList *)param_1);
          in_stack_00000018 = *(undefined4 **)(extraout_EAX + 0x14);
          in_stack_fffffffc = pCVar12;
        }
        else {
          pSVar3 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem
                             (pCVar9,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                      *)in_stack_fffffffc);
          in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d5537;
          CTrackManiaEditorIconPage::GetIcon
                    (*(CTrackManiaEditorIconPage **)(**(int **)pSVar3 + 0x14),pCVar12,
                     (EMwIconList *)unaff_retaddr,(EMwIconList *)param_1);
          in_stack_00000018 = *(undefined4 **)(extraout_EAX_00 + 0x14);
          in_stack_fffffffc = pCVar12;
        }
      }
      pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      *(undefined4 *)(this + 0x70) = 0;
      do {
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (unaff_retaddr + 0x1c,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
        if (pCVar10 < pCVar5) {
          *(int *)(this + 0x70) = *(int *)(this + 0x70) + 1;
          uVar1 = 0x4d55e0;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)unaff_EBX);
          unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d55ec;
          unaff_EBX = pCVar10;
          CTrackManiaEditorIconPage::GetIcon
                    (in_stack_00000008,(CMwParamFastBuffer<class_CMwParamVec4> *)pCVar10,
                     (EMwIconList *)in_stack_fffffff8,(EMwIconList *)in_stack_fffffffc);
          **(undefined4 **)pSVar4 = extraout_EAX_01;
          in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d55f9;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)unaff_retaddr);
          if (*(int *)(**(int **)pSVar4 + 0x14) == 0) {
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar10,(ulong)param_1);
            in_stack_fffffffc = (CMwParamFastBuffer<class_CMwParamVec4> *)0x4d5618;
            CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 4),0);
            unaff_retaddr = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5623;
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar10,(ulong)in_stack_00000008);
            pCVar9 = *(CTrackManiaEditorInterface **)(**(int **)pSVar4 + 0x18);
            param_1 = (CTrackManiaEditorInterface *)0x4d5632;
            UpdateAmount(this,pCVar9,(CGameCtnArticle *)in_stack_0000000c);
          }
          else {
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar10,(ulong)param_1);
            in_stack_fffffffc = (CMwParamFastBuffer<class_CMwParamVec4> *)0x4d5646;
            CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 4),1);
            unaff_retaddr = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5651;
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar10,(ulong)in_stack_00000008);
            pCVar6 = CTrackManiaEditorIconPage::GetRepresentativeArticleIcon
                               (*(CTrackManiaEditorIconPage **)(**(int **)pSVar4 + 0x14),
                                in_stack_0000000c);
            pCVar9 = *(CTrackManiaEditorInterface **)(pCVar6 + 0x18);
            param_1 = (CTrackManiaEditorInterface *)pCVar10;
          }
          in_stack_00000008 = (CTrackManiaEditorIconPage *)0x4d5668;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)in_stack_00000010);
          (**(code **)(**(int **)(*(int *)pSVar4 + 8) + 0x1ac))();
          CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                    (this_00,pCVar10,in_stack_00000014);
          in_stack_00000010 = (CTrackManiaEditorInterface *)0xffffffff;
          in_stack_0000000c = (CTrackManiaEditorIconPage *)0x4d568e;
          pCVar7 = CGameCtnArticle::CreateIcon
                             ((CGameCtnArticle *)pCVar9,(CGameCtnArticle *)0xffffffff,1,
                              (int)in_stack_00000018);
          in_stack_00000014 = 0x4d569d;
          CControlButton::SetIcons
                    (*(CControlButton **)(*in_stack_00000030 + 8),(CControlButton *)pCVar7,
                     in_stack_0000001c);
          in_stack_00000018 = (undefined4 *)0x4d56a5;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)in_stack_00000020);
          in_stack_00000020 = (CFuncEnum *)0x4d56b4;
          (**(code **)(**(int **)(*(int *)pSVar4 + 8) + 0x1a8))();
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,in_stack_ffffffe4);
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 8),1);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)pCVar11);
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 0xc),1);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar10,uVar1);
          iVar2 = 1;
          in_stack_0000001c = (CFuncEnum *)pCVar10;
        }
        else {
          iVar2 = 0x4d5578;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)unaff_EBX);
          **(undefined4 **)pSVar4 = 0;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)in_stack_fffffff8);
          unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d5595;
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 4),0);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)in_stack_fffffffc);
          unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d55ad;
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 8),0);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)unaff_retaddr);
          in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4d55c5;
          CControlTools::ControlSetVisible(*(CControlBase **)(*(int *)pSVar4 + 0xc),0);
          in_stack_fffffffc = (CMwParamFastBuffer<class_CMwParamVec4> *)0x4d55d0;
          unaff_retaddr = pCVar10;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar10,(ulong)param_1);
          param_1 = (CTrackManiaEditorInterface *)0x0;
        }
        pCVar11 = *(CControlBase **)(*(int *)pSVar4 + 0x10);
        in_stack_ffffffe4 = 0x4d56f9;
        CControlTools::ControlSetVisible(pCVar11,iVar2);
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009);
    }
  }
  UpdateIconsStyle(this,(CTrackManiaEditorInterface *)unaff_EBP);
  UpdateSubButtonsSize(this,in_stack_00000010);
  return;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::UpdateIconsStyle
// =================================================
void __thiscall
CTrackManiaEditorInterface::UpdateIconsStyle
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1)
{
{
  CTrackManiaEditorInterface *this_00;
  uint *puVar1;
  int iVar2;
  int *piVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  
  this_00 = this + 0x68;
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
  if ((uVar4 != 0) &&
     (pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0, *(int *)(this + 0x70) != 0)) {
    do {
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar6,(ulong)unaff_ESI);
      iVar2 = **(int **)pSVar5;
      unaff_ESI = pCVar6;
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar6,unaff_EDI);
      if (iVar2 == 0) {
        puVar1 = (uint *)(*(int *)(*(int *)pSVar5 + 8) + 0xfc);
        *puVar1 = *puVar1 & 0xfffffffd;
      }
      else {
        piVar3 = *(int **)(*(int *)pSVar5 + 8);
        if (piVar3 != (int *)0x0) {
          if ((*(int *)(iVar2 + 0x14) == 0) && (*(int *)(this + 0x38) != 0)) {
            if (*(int *)(*(int *)(this + 0x34) + 0x38) == 3) {
              piVar3[0x3f] = piVar3[0x3f] ^
                             ((uint)(*(int *)(*(int *)(iVar2 + 0x18) + 0x80) ==
                                    *(int *)(*(int *)(iVar2 + 0x18) + 0x7c)) * 2 ^ piVar3[0x3f]) & 2
              ;
            }
            else {
              piVar3[0x3f] = piVar3[0x3f] & 0xfffffffd;
            }
          }
          else {
            piVar3[0x3f] = piVar3[0x3f] & 0xffffdffd;
          }
          unaff_EDI = 0x4d4e1f;
          (**(code **)(*piVar3 + 0x1a8))();
        }
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x70));
  }
  return;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::UpdateSubButtonsSize
// =================================================
void __thiscall
CTrackManiaEditorInterface::UpdateSubButtonsSize
          (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1)
{
{
  CTrackManiaEditorInterface *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CPlugTree *this_01;
  int iVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  int *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_ESI;
  undefined4 *puVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CTrackManiaEditorInterface *pCVar7;
  GmScaleTrans2 *pGVar8;
  CPlugTree *pCVar9;
  GmIso4 *pGVar10;
  GmScaleTrans2 *pGVar11;
  GmVec3 *pGVar12;
  GmIso3 *pGVar13;
  CTrackManiaEditorInterface *in_stack_ffffff4c;
  int iStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  GmVec3 local_98 [12];
  undefined1 auStack_8c [8];
  undefined1 auStack_84 [4];
  undefined1 auStack_80 [4];
  CTrackManiaEditorInterface aCStack_7c [28];
  float fStack_60;
  GmScaleTrans2 aGStack_5c [12];
  GmIso3 aGStack_50 [24];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_28 [4];
  GmIso3 aGStack_24 [36];
  
  pCVar7 = this;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x68,unaff_EDI);
  if ((uVar1 != 0) &&
     (pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0, *(int *)(this + 0x70) != 0)) {
    do {
      this_00 = this + 0x68;
      pCVar9 = (CPlugTree *)0x4d49eb;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_ESI);
      if (**(int **)pSVar2 != 0) {
        if (*(int *)(this + 0x38) == 0) {
LAB_004d4a5f:
          this = in_stack_ffffff4c;
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar5,(ulong)unaff_EBP);
          unaff_EBP = *(int **)(*(int *)pSVar2 + 8);
          pGVar13 = (GmIso3 *)0x0;
          pGVar12 = local_98;
          pGVar11 = (GmScaleTrans2 *)0x4d4a7f;
          (**(code **)(*unaff_EBP + 0x1b4))();
          puVar6 = (undefined4 *)PTR_DAT_00cd73c4;
          pGVar8 = aGStack_5c;
          for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(undefined4 *)pGVar8 = *puVar6;
            puVar6 = puVar6 + 1;
            pGVar8 = pGVar8 + 4;
          }
          uStack_38 = uStack_a4;
          uStack_34 = uStack_a0;
          uStack_30 = uStack_9c;
          GmIso4::SetInverse(auStack_8c,aGStack_5c,pGVar11);
          fStack_60 = *(float *)(iStack_b0 + 0x14) + fStack_60;
          uStack_ac = 0;
          uStack_a8 = 0;
          uStack_a4 = 0;
          pGVar10 = *(GmIso4 **)(iStack_b0 + 0x18);
          pCVar9 = (CPlugTree *)0x4d4af4;
          GmIso4::SetUScaleTrans(auStack_28,pGVar10,(float)&uStack_ac,pGVar12);
          unaff_ESI = 0x4d4b05;
          GmIso4::Mult(auStack_84,aGStack_24,pGVar13);
          GmIso4::Mult(auStack_80,aGStack_50,(GmIso3 *)pCVar7);
        }
        else {
          pGVar10 = (GmIso4 *)0x4d4a04;
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar5,(ulong)unaff_EBX);
          if (*(int *)(**(int **)pSVar2 + 0x14) != 0) goto LAB_004d4a5f;
          unaff_ESI = 0x4d4a16;
          unaff_EBX = pCVar5;
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar5,(ulong)unaff_EBP);
          if (*(int *)(*(int *)pSVar2 + 4) == 0) goto LAB_004d4b30;
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar5,(ulong)pCVar7);
          unaff_EBP = *(int **)(*(int *)pSVar2 + 8);
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar5,(ulong)in_stack_ffffff4c);
          this = *(CTrackManiaEditorInterface **)(*(int *)pSVar2 + 4);
          iVar3 = (**(code **)(*(int *)this + 0x1b0))();
          puVar6 = (undefined4 *)(iVar3 + 0x5c);
          pCVar7 = aCStack_7c;
          for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined4 *)pCVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            pCVar7 = pCVar7 + 4;
          }
        }
        pCVar7 = aCStack_7c;
        unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4d4b25;
        this_01 = (CPlugTree *)(**(code **)(*unaff_EBP + 0x1b0))();
        CPlugTree::SetLocation(this_01,pCVar9,pGVar10);
        in_stack_ffffff4c = this;
      }
LAB_004d4b30:
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x70));
  }
  return;
}
}

// =================================================
// Function: CTrackManiaEditorInterface::UpdateToolTips
// =================================================
void __thiscall
CTrackManiaEditorInterface::UpdateToolTips
          (CTrackManiaEditorInterface *this,CGameCtnMediaTracker *param_1,int param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SStringParamInt *pSVar3;
  CControlContainer *unaff_ESI;
  SStringParam *unaff_retaddr;
  SStringParam *in_stack_fffffff4;
  wchar_t *in_stack_fffffff8;
  wchar_t *in_stack_fffffffc;
  
  if (*(CControlContainer **)(this + 0x84) != (CControlContainer *)0x0) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CControlContainer::GetFocusedChildIndex(*(CControlContainer **)(this + 0x84),unaff_ESI)
    ;
    if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      CFastStringInt::SetString(this + 0x1c,(CFastStringInt *)&stack0xfffffff8,in_stack_fffffff4);
      return;
    }
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 0x84) + 0x144),pCVar1,(ulong)in_stack_fffffff4);
    pSVar3 = (SStringParamInt *)
             CClassicI18n::GetTranslatedStringInternal
                       ((CClassicI18n *)&DAT_00d71d10,*(CClassicI18n **)(*(int *)pSVar2 + 0x104),
                        in_stack_fffffff8);
    SStringParamInt::SStringParamInt(&stack0x00000000,pSVar3,in_stack_fffffffc);
    CFastStringInt::SetString(this + 0x1c,(CFastStringInt *)&param_1,unaff_retaddr);
  }
  return;
}
}

