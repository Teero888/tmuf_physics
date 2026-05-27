// Class implementation: CControlTools

// =================================================
// Function: CControlTools::Connect
// =================================================
void __thiscall CControlTools::Connect(void *this,CCrystalEdge *param_1)
{
{
  CControlBase *pCVar1;
  char *in_stack_00000008;
  CMwNod *in_stack_0000000c;
  char *in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  CControlBase *local_4;
  
  local_4 = this;
  ControlRetrieve<class_CControlBase>
            ((CControlContainer *)param_1,in_stack_00000008,&local_4,1,in_stack_0000001c,1);
  pCVar1 = local_4;
  ControlBind(local_4,in_stack_0000000c,in_stack_00000010);
  ControlSetVisible(pCVar1,(uint)(in_stack_00000014 == 0));
  if (((in_stack_0000000c != (CMwNod *)0x0) && (in_stack_00000014 == 0)) && (in_stack_00000018 == 0)
     ) {
    ControlSetReadOnlyAndDraw(pCVar1,0,0);
    return;
  }
  ControlSetReadOnlyAndDraw(pCVar1,1,0);
  return;
}
}

// =================================================
// Function: CControlTools::ControlBind
// =================================================
void __cdecl CControlTools::ControlBind(CControlBase *param_1,CMwNod *param_2,char *param_3)
{
{
  int iVar1;
  CControlBase *unaff_retaddr;
  char *pcVar2;
  
  if (param_1 != (CControlBase *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1 + 0x10))(0x30bd000);
    if (iVar1 != 0) {
      (**(code **)(*(int *)param_1 + 0x23c))(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x00768c0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)param_1 + 0x178))();
      return;
    }
    pcVar2 = (char *)0x309a000;
    iVar1 = (**(code **)(*(int *)param_1 + 0x10))();
    if (iVar1 != 0) {
      CControlBase::CreateStack(param_1,unaff_retaddr,(CMwNod *)param_1,pcVar2);
                    /* WARNING: Could not recover jumptable at 0x00768c3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)param_1 + 0x178))();
      return;
    }
    CControlBase::CreateStack(param_1,unaff_retaddr,(CMwNod *)param_1,pcVar2);
  }
  return;
}
}

// =================================================
// Function: CControlTools::ControlBindEvent
// =================================================
void __cdecl
CControlTools::ControlBindEvent
          (CControlBase *param_1,EEvent param_2,CMwNod *param_3,_func___cdecl_void_ulong *param_4,
          ulong param_5)
{
{
  CControlBase *this;
  CControlBase *unaff_ESI;
  EEvent EVar1;
  
  this = EventControlGet(unaff_ESI);
  if (this != (CControlBase *)0x0) {
    EVar1 = param_2;
    (**(code **)(*(int *)this + 0x1a0))();
    CControlBase::BindEvent(this,(CControlBase *)param_2,param_2,param_3,param_4,EVar1);
  }
  return;
}
}

// =================================================
// Function: CControlTools::ControlDraw
// =================================================
void __cdecl CControlTools::ControlDraw(CControlBase *param_1)
{
{
  if (param_1 != (CControlBase *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00768a20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1 + 0x1a8))();
    return;
  }
  return;
}
}

// =================================================
// Function: CControlTools::ControlGiveFocus
// =================================================
void __cdecl CControlTools::ControlGiveFocus(CControlBase *param_1)
{
{
  int iVar1;
  
  if (param_1 != (CControlBase *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1 + 0x10))(0x309a000);
    if (iVar1 != 0) {
      param_1 = *(CControlBase **)(param_1 + 0x1a8);
    }
    if (param_1 != (CControlBase *)0x0) {
      CControlBase::GiveFocus(param_1,0);
    }
  }
  return;
}
}

// =================================================
// Function: CControlTools::ControlRetrieve<class_CControlBase>
// =================================================
void __cdecl
CControlTools::ControlRetrieve<class_CControlBase>
          (CControlContainer *param_1,char *param_2,CControlBase **param_3,int param_4,int param_5,
          int param_6)
{
{
  CControlContainer *pCVar1;
  int iVar2;
  CMwId CVar3;
  CFastStringInt *pCVar4;
  undefined3 extraout_var;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_4;
  pCVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a845c8;
  local_c = ExceptionList;
  pCVar4 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  if ((param_1 != (CControlContainer *)0x0) && (param_4 != 0)) {
    ExceptionList = &local_c;
    CVar3 = CMwId::CreateFromLocalName((char *)&param_1);
    local_4 = 0;
    ControlRetrieve<class_CControlBase>
              (pCVar1,(char *)CONCAT31(extraout_var,CVar3),param_3,iVar2,param_5,param_6);
    local_4 = 0xffffffff;
    OnAccessViolation_ConcatToCrashFileName(pCVar4);
    ExceptionList = local_c;
    return;
  }
  *param_3 = (CControlBase *)0x0;
  return;
}
}

// =================================================
// Function: CControlTools::ControlRetrieve<class_CControlGrid>
// =================================================
void __cdecl
CControlTools::ControlRetrieve<class_CControlGrid>
          (CControlContainer *param_1,char *param_2,CControlGrid **param_3,int param_4,int param_5,
          int param_6)
{
{
  CControlContainer *pCVar1;
  int iVar2;
  CMwId CVar3;
  CFastStringInt *pCVar4;
  undefined3 extraout_var;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_4;
  pCVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00aa5808;
  local_c = ExceptionList;
  pCVar4 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  if ((param_1 != (CControlContainer *)0x0) && (param_4 != 0)) {
    ExceptionList = &local_c;
    CVar3 = CMwId::CreateFromLocalName((char *)&param_1);
    local_4 = 0;
    ControlRetrieve<class_CControlGrid>
              (pCVar1,(char *)CONCAT31(extraout_var,CVar3),param_3,iVar2,param_5,param_6);
    local_4 = 0xffffffff;
    OnAccessViolation_ConcatToCrashFileName(pCVar4);
    ExceptionList = local_c;
    return;
  }
  *param_3 = (CControlGrid *)0x0;
  return;
}
}

// =================================================
// Function: CControlTools::ControlRetrieve<class_CControlLabel>
// =================================================
void __cdecl
CControlTools::ControlRetrieve<class_CControlLabel>
          (CControlContainer *param_1,char *param_2,CControlLabel **param_3,int param_4,int param_5,
          int param_6)
{
{
  CControlContainer *pCVar1;
  int iVar2;
  CMwId CVar3;
  CFastStringInt *pCVar4;
  undefined3 extraout_var;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_4;
  pCVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a845f8;
  local_c = ExceptionList;
  pCVar4 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  if ((param_1 != (CControlContainer *)0x0) && (param_4 != 0)) {
    ExceptionList = &local_c;
    CVar3 = CMwId::CreateFromLocalName((char *)&param_1);
    local_4 = 0;
    ControlRetrieve<class_CControlLabel>
              (pCVar1,(char *)CONCAT31(extraout_var,CVar3),param_3,iVar2,param_5,param_6);
    local_4 = 0xffffffff;
    OnAccessViolation_ConcatToCrashFileName(pCVar4);
    ExceptionList = local_c;
    return;
  }
  *param_3 = (CControlLabel *)0x0;
  return;
}
}

// =================================================
// Function: CControlTools::ControlRetrieve<class_CControlQuad>
// =================================================
void __cdecl
CControlTools::ControlRetrieve<class_CControlQuad>
          (CControlContainer *param_1,char *param_2,CControlQuad **param_3,int param_4,int param_5,
          int param_6)
{
{
  CControlContainer *pCVar1;
  int iVar2;
  CMwId CVar3;
  CFastStringInt *pCVar4;
  undefined3 extraout_var;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_4;
  pCVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a84628;
  local_c = ExceptionList;
  pCVar4 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  if ((param_1 != (CControlContainer *)0x0) && (param_4 != 0)) {
    ExceptionList = &local_c;
    CVar3 = CMwId::CreateFromLocalName((char *)&param_1);
    local_4 = 0;
    ControlRetrieve<class_CControlQuad>
              (pCVar1,(char *)CONCAT31(extraout_var,CVar3),param_3,iVar2,param_5,param_6);
    local_4 = 0xffffffff;
    OnAccessViolation_ConcatToCrashFileName(pCVar4);
    ExceptionList = local_c;
    return;
  }
  *param_3 = (CControlQuad *)0x0;
  return;
}
}

// =================================================
// Function: CControlTools::ControlRetrieveAndSetLabel
// =================================================
void __cdecl
CControlTools::ControlRetrieveAndSetLabel
          (CControlContainer *param_1,char *param_2,CFastStringInt *param_3,int param_4,int param_5)
{
{
  CControlBase *local_4;
  
  ControlRetrieve<class_CControlBase>(param_1,param_2,&local_4,param_4,param_5,1);
  ControlSetLabel(local_4,param_3);
  return;
}
}

// =================================================
// Function: CControlTools::ControlRetrieveAndSetVisible
// =================================================
void __cdecl
CControlTools::ControlRetrieveAndSetVisible
          (CControlContainer *param_1,char *param_2,int param_3,int param_4,int param_5)
{
{
  CControlBase *local_4;
  
  ControlRetrieve<class_CControlBase>(param_1,param_2,&local_4,param_4,param_5,1);
  ControlSetVisible(local_4,param_3);
  return;
}
}

// =================================================
// Function: CControlTools::ControlSetLabel
// =================================================
void __cdecl CControlTools::ControlSetLabel(CControlBase *param_1,CFastStringInt *param_2)
{
{
  int iVar1;
  SStringParam *unaff_ESI;
  CFastStringInt *pCVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1 != (CControlBase *)0x0) {
    pCVar2 = (CFastStringInt *)0x7007000;
    iVar1 = (**(code **)(*(int *)param_1 + 0x10))();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)param_1 + 0x10))(0x7006000);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*(int *)param_1 + 0x10))(0x30bd000);
        if (iVar1 != 0) {
          uStack_c = *(undefined4 *)(param_2 + 4);
          uStack_8 = *(undefined4 *)param_2;
          uStack_4 = 0;
          if (*(int *)(param_1 + 0x178) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = *(int *)(param_1 + 0x1cc);
          }
          CFastStringInt::SetString((void *)(iVar1 + 0x18),(CFastStringInt *)&uStack_c,unaff_ESI);
        }
      }
      else {
        CControlLabel::SetLabel((CControlLabel *)param_1,(CControlButton *)param_1,pCVar2);
      }
    }
    else {
      CControlButton::SetLabel((CControlButton *)param_1,(CControlButton *)param_1,pCVar2);
    }
                    /* WARNING: Could not recover jumptable at 0x007690d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1 + 0x1a8))();
    return;
  }
  return;
}
}

// =================================================
// Function: CControlTools::ControlSetReadOnlyAndDraw
// =================================================
void __cdecl CControlTools::ControlSetReadOnlyAndDraw(CControlBase *param_1,int param_2,int param_3)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  SMwParamInfo *pSVar4;
  uint uVar5;
  ulong unaff_EBX;
  CControlBase *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CMwStack *pCVar8;
  
  if (param_1 != (CControlBase *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1 + 0x10))(0x309a000);
    if (iVar1 != 0) {
      uVar5 = (uint)(param_1 == (CControlBase *)0x0);
      (**(code **)(*(int *)param_1 + 0x238))();
      CGameControlCard::CardSetReadOnly
                ((CGameControlCard *)param_1,(CGameControlCard *)param_1,uVar5);
    }
    iVar1 = (**(code **)(*(int *)param_1 + 0x10))(0x7002000);
    if (iVar1 == 0) {
      pCVar8 = (CMwStack *)0x7009000;
      iVar1 = (**(code **)(*(int *)param_1 + 0x10))();
      pCVar6 = param_1;
      if (((iVar1 != 0) &&
          (pSVar4 = CControlBase::GetParamInfo(param_1,(CControlBase *)0x0,pCVar8),
          pSVar4 != (SMwParamInfo *)0x0)) && (((byte)pSVar4[0x14] & 0x22) == 0)) {
        pCVar6 = (CControlBase *)0x1;
      }
      uVar5 = *(uint *)(param_1 + 0xfc);
      *(uint *)(param_1 + 0xfc) = ((uint)(pCVar6 != (CControlBase *)0x0) * 2 ^ uVar5) & 2 ^ uVar5;
      if ((CControlBase *)(uVar5 >> 1 & 1) != pCVar6) {
                    /* WARNING: Could not recover jumptable at 0x00768e62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*(int *)param_1 + 0x1a8))();
        return;
      }
    }
    else if (param_1 != (CControlBase *)0x0) {
      pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x144,unaff_EDI);
      pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (param_1 + 0x144,pCVar7,unaff_EBX);
          unaff_EBX = param_3;
          ControlSetReadOnlyAndDraw(*(CControlBase **)pSVar3,(int)param_1,param_3);
          pCVar7 = pCVar7 + 1;
        } while (pCVar7 < pCVar2);
      }
    }
  }
  return;
}
}

// =================================================
// Function: CControlTools::ControlSetVisible
// =================================================
void __cdecl CControlTools::ControlSetVisible(CControlBase *param_1,int param_2)
{
{
  int iVar1;
  
  if (param_1 != (CControlBase *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1 + 0x108))();
    if (iVar1 != param_2) {
      if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00768a5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*(int *)param_1 + 0x100))();
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x00768a64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)param_1 + 0x104))();
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CControlTools::CreateRankText
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CControlTools::CreateRankText(ulong param_1,CFastStringInt *param_2,int param_3)
{
{
  ulong uVar1;
  ulong uVar2;
  SStringParamInt *pSVar3;
  SStringParam *unaff_ESI;
  uint uVar4;
  int unaff_EDI;
  void *in_stack_00000010;
  void *in_stack_00000014;
  void *in_stack_00000018;
  SStringParam *in_stack_ffffffac;
  SStringParamInt *pSVar5;
  SStringParamInt *pSVar6;
  CFastStringInt local_48 [4];
  undefined1 local_44 [4];
  CFastStringInt local_40 [4];
  undefined1 local_3c [4];
  CFastStringInt local_38 [4];
  undefined *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined *local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined *local_4;
  
  if ((_DAT_00d6c3b0 & 1) == 0) {
    _DAT_00d6c3b0 = _DAT_00d6c3b0 | 1;
    DAT_00d6c3a8 = (SStringParamInt *)0x0;
    DAT_00d6c3ac = (SStringParamInt *)PTR_DAT_00bbf7d8;
    _atexit(`void___cdecl_CControlTools::CreateRankText(unsigned_long,class_CFastStringInt&,int)'::
            __l2::_dynamic_atexit_destructor_for__RankTmp__);
  }
  if ((_DAT_00d6c3b0 & 2) == 0) {
    _DAT_00d6c3b0 = _DAT_00d6c3b0 | 2;
    DAT_00d6c3a0 = 0;
    DAT_00d6c3a4 = PTR_DAT_00bbf7dc;
    _atexit(`void___cdecl_CControlTools::CreateRankText(unsigned_long,class_CFastStringInt&,int)'::
            __l2::_dynamic_atexit_destructor_for__Rank__);
  }
  uVar1 = param_1;
  CFastString::SetNatural((CFastString *)&DAT_00d6c3a8,(CFastString *)param_1,1,0,0,0,1,unaff_EDI);
  pSVar5 = DAT_00d6c3ac;
  pSVar6 = DAT_00d6c3a8;
  CFastStringInt::SetString(&DAT_00d6c3a0,(CFastStringInt *)&stack0xffffffb0,unaff_ESI);
  if (in_stack_00000014 != (void *)0x0) {
    local_34 = DAT_00d6c3a4;
    local_30 = DAT_00d6c3a0;
    local_2c = 0;
    CFastStringInt::SetString(in_stack_00000010,(CFastStringInt *)&local_34,in_stack_ffffffac);
    return;
  }
  uVar2 = CClassicI18n::IsLanguageKindOf("en",&DAT_00d71d38);
  if (uVar2 != 0) {
    if ((10 < uVar1) && (uVar1 < 0xe)) {
      local_34 = DAT_00d6c3a4;
      local_30 = DAT_00d6c3a0;
      local_2c = 0;
      SStringParam::SStringParam
                (&stack0xffffffb4,(SStringParam *)&DAT_00b92b20,(char *)in_stack_ffffffac);
      CFastStringInt::SetCompose(in_stack_00000014,local_48,(SStringParam *)&local_30,pSVar5);
      return;
    }
    uVar4 = uVar1 % 10;
    if (uVar4 == 1) {
      local_4 = DAT_00d6c3a4;
      param_1 = 0;
      SStringParam::SStringParam(&local_34,(SStringParam *)&DAT_00b92b08,(char *)in_stack_ffffffac);
      CFastStringInt::SetCompose
                (in_stack_00000014,(CFastStringInt *)&local_30,(SStringParam *)&stack0x00000000,
                 pSVar5);
      return;
    }
    if (uVar4 != 2) {
      if (uVar4 != 3) {
        local_28 = DAT_00d6c3a4;
        local_24 = DAT_00d6c3a0;
        local_20 = 0;
        SStringParam::SStringParam
                  (&stack0xffffffb4,(SStringParam *)&DAT_00b92b20,(char *)in_stack_ffffffac);
        CFastStringInt::SetCompose(in_stack_00000014,local_48,(SStringParam *)&local_24,pSVar5);
        return;
      }
      local_1c = DAT_00d6c3a4;
      local_18 = DAT_00d6c3a0;
      local_14 = 0;
      SStringParam::SStringParam(local_44,(SStringParam *)&DAT_00b92b18,(char *)in_stack_ffffffac);
      CFastStringInt::SetCompose(in_stack_00000014,local_40,(SStringParam *)&local_18,pSVar5);
      return;
    }
    local_c = DAT_00d6c3a0;
    local_10 = DAT_00d6c3a4;
    local_8 = 0;
    SStringParam::SStringParam(local_3c,(SStringParam *)&DAT_00b92b10,(char *)in_stack_ffffffac);
    CFastStringInt::SetCompose(in_stack_00000014,local_38,(SStringParam *)&local_c,pSVar5);
    return;
  }
  if (uVar1 == 1) {
    pSVar3 = (SStringParamInt *)
             CClassicI18n::GetTranslatedStringInternal
                       ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)&DAT_00b92ae4,
                        (wchar_t *)in_stack_ffffffac);
    SStringParamInt::SStringParamInt(&local_30,pSVar3,(wchar_t *)pSVar5);
    CFastStringInt::SetString(in_stack_00000018,(CFastStringInt *)&local_2c,(SStringParam *)pSVar6);
    return;
  }
  if (uVar1 != 2) {
    if (uVar1 != 3) {
      local_4 = DAT_00d6c3a4;
      param_1 = 0;
      pSVar3 = (SStringParamInt *)
               CClassicI18n::GetTranslatedStringInternal
                         ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"%1th",
                          (wchar_t *)in_stack_ffffffac);
      SStringParamInt::SStringParamInt(&local_c,pSVar3,(wchar_t *)pSVar5);
      CFastStringInt::SetCompose
                (in_stack_00000018,(CFastStringInt *)&local_8,(SStringParam *)&param_1,pSVar6);
      return;
    }
    pSVar3 = (SStringParamInt *)
             CClassicI18n::GetTranslatedStringInternal
                       ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)&DAT_00b92af4,
                        (wchar_t *)in_stack_ffffffac);
    SStringParamInt::SStringParamInt(&local_18,pSVar3,(wchar_t *)pSVar5);
    CFastStringInt::SetString(in_stack_00000018,(CFastStringInt *)&local_14,(SStringParam *)pSVar6);
    return;
  }
  pSVar3 = (SStringParamInt *)
           CClassicI18n::GetTranslatedStringInternal
                     ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)&DAT_00b92aec,
                      (wchar_t *)in_stack_ffffffac);
  SStringParamInt::SStringParamInt(&local_24,pSVar3,(wchar_t *)pSVar5);
  CFastStringInt::SetString(in_stack_00000018,(CFastStringInt *)&local_20,(SStringParam *)pSVar6);
  return;
}
}

// =================================================
// Function: CControlTools::FixLocalUrl
// =================================================
void __cdecl CControlTools::FixLocalUrl(CFastString *param_1,CFastStringInt *param_2)
{
{
  SHeaderCommunity *unaff_ESI;
  SStringParam *unaff_EDI;
  void *unaff_retaddr;
  undefined4 local_1c;
  undefined *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00ac6a98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (((*(int *)param_1 != 0) && (2 < *(uint *)param_2)) && (**(short **)(param_2 + 4) == 0x2e)) {
    local_1c = 0;
    local_18 = PTR_DAT_00bbf7d8;
    local_4 = 0;
    CFastStringInt::GetUtf8
              (param_2,(CFastStringInt *)&local_1c,(CFastString *)0x0,
               DAT_00cca150 ^ (uint)&stack0xffffffdc);
    FixLocalUrl(param_1,(CFastStringInt *)&local_18);
    local_c = local_18;
    local_10 = local_14;
    CFastStringInt::SetUtf8(param_2,(CFastStringInt *)&local_10,unaff_EDI);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_14,unaff_ESI);
  }
  ExceptionList = unaff_retaddr;
  return;
}
}

