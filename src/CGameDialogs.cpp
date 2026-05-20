// Class implementation: CGameDialogs

// =================================================
// Function: CGameDialogs::AdjustQuadBgSize
// =================================================
void __cdecl CGameDialogs::AdjustQuadBgSize(CControlFrame *param_1,int param_2)
{
{
  CControlFrame *pCVar1;
  CControlFrame *pCVar2;
  ulong uVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  CControlText *unaff_EDI;
  int in_stack_0000000c;
  GxTexCoordSet *pGVar6;
  GmBoxAligned *pGVar7;
  CControlBase *pCVar8;
  GmBoxAligned *pGVar9;
  CControlGrid *local_20;
  CControlQuad *local_1c;
  GmBoxAligned aGStack_18 [16];
  CControlQuad *apCStack_8 [2];
  
  pCVar1 = param_1;
  CControlTools::ControlRetrieve<class_CControlLabel>
            ((CControlContainer *)param_1,"LabelMessage",(CControlLabel **)&param_1,1,1,1);
  CControlTools::ControlRetrieve<class_CControlQuad>
            ((CControlContainer *)pCVar1,"QuadBg",&local_1c,1,0,0);
  CControlTools::ControlRetrieve<class_CControlGrid>
            ((CControlContainer *)pCVar1,"GridContent",&local_20,1,0,1);
  pCVar2 = param_1;
  if (param_1 != (CControlFrame *)0x0) {
    uVar3 = CControlText::GetLineCount((CControlText *)param_1,unaff_EDI);
    if ((uVar3 == 1) || (in_stack_0000000c != 0)) {
      *(undefined4 *)(pCVar2 + 0x10c) = 1;
    }
    else {
      *(undefined4 *)(pCVar2 + 0x10c) = 0;
    }
    (**(code **)(*(int *)pCVar2 + 0x1a8))();
    if (local_20 != (CControlGrid *)0x0) {
      (**(code **)(*(int *)local_20 + 0x1dc))();
    }
  }
  if ((local_1c != (CControlQuad *)0x0) && (local_20 != (CControlGrid *)0x0)) {
    (**(code **)(*(int *)local_20 + 0x1dc))();
    pGVar9 = (GmBoxAligned *)0x0;
    pGVar7 = aGStack_18;
    (**(code **)(*(int *)local_20 + 0x1b4))();
    CControlQuad::AddMargin(local_1c,(CControlQuad *)&local_20,pGVar7);
    pCVar8 = (CControlBase *)&local_1c;
    pGVar6 = (GxTexCoordSet *)0x6095a7;
    CControlBase::SetControlSizeFromBox((CControlBase *)local_1c,pCVar8,pGVar9);
    uVar3 = 0x6095b3;
    (**(code **)(*(int *)local_1c + 0x1a8))();
    apCStack_8[0] = local_1c;
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastArray<class_CGameMenuFrame*>::Find
                       (pCVar1 + 0x144,(CFastArray<class_GxTexCoordSet> *)apCStack_8,pGVar6);
    if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      pSVar5 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](pCVar1 + 0x158,pCVar4,(ulong)pCVar8);
      *(undefined4 *)(pSVar5 + 0x24) = 0;
      pSVar5 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](pCVar1 + 0x158,pCVar4,uVar3);
      *(undefined4 *)(pSVar5 + 0x28) = 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x006095fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)pCVar1 + 0x1a8))();
  return;
}
}

// =================================================
// Function: CGameDialogs::DoMessage
// =================================================
void __thiscall
CGameDialogs::DoMessage
          (CGameDialogs *this,CGameDialogs *param_1,CFastStringInt *param_2,CFastStringInt *param_3,
          CMwNod *param_4,_func___cdecl_void *param_5)
{
{
  CControlBase *pCVar1;
  CMwId CVar2;
  CMwId *pCVar3;
  undefined3 extraout_var;
  CMotionPlayer *pCVar4;
  CFastStringInt *unaff_EDI;
  char local_14 [8];
  CControlBase *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00aa5968;
  local_c = ExceptionList;
  pCVar3 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  if (DAT_00d54244 == 0) {
    if (*(int *)(this + 0x70) != 0) {
      CVar2 = CMwId::CreateFromLocalName(local_14);
      local_4 = (void *)0x0;
      pCVar4 = CFastBuffer<class_CMotionPlayer*>::GetNodFromId
                         ((void *)(*(int *)(this + 0x70) + 0x68),
                          (CFastBuffer<class_CMotionPlayer*> *)CONCAT31(extraout_var,CVar2),pCVar3);
      OnAccessViolation_ConcatToCrashFileName(unaff_EDI);
      if (pCVar4 != (CMotionPlayer *)0x0) {
        CControlTools::ControlRetrieve<class_CControlBase>
                  ((CControlContainer *)pCVar4,"ButtonOk",&local_c,1,0,1);
        pCVar1 = local_c;
        CControlTools::ControlSetLabel(local_c,param_3);
        CControlTools::ControlSetVisible(pCVar1,(uint)(*(int *)param_3 != 0));
        CControlTools::ControlBind(pCVar1,(CMwNod *)this,"DoMessage_Ok");
        CControlTools::ControlGiveFocus(pCVar1);
        CControlTools::ControlRetrieveAndSetLabel
                  ((CControlContainer *)pCVar4,"LabelMessage",param_2,1,0);
        *(CMwNod **)(this + 0x40) = param_4;
        *(_func___cdecl_void **)(this + 0x44) = param_5;
        *(undefined4 *)(this + 0x14) = 0;
        ShowDialogs(this,(CGameCtnMenus *)pCVar4,(CControlFrame *)unaff_EDI);
        AdjustQuadBgSize((CControlFrame *)pCVar4,0);
      }
    }
  }
  else {
    *(undefined4 *)(this + 0x14) = 1;
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CGameDialogs::HideDialogs
// =================================================
void __thiscall CGameDialogs::HideDialogs(CGameDialogs *this,CGameCtnMenus *param_1)
{
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x70);
  if ((iVar1 != 0) && (*(int *)(this + 0x3c) == 0)) {
    if (*(int *)(this + 0x14) == 0) {
      *(undefined4 *)(this + 0x14) = 2;
    }
    if ((*(int *)(iVar1 + 0xb0) != 0) && (*(int **)(this + 0x74) != (int *)0x0)) {
      (**(code **)(**(int **)(this + 0x74) + 0x7c))(iVar1);
    }
  }
  return;
}
}

