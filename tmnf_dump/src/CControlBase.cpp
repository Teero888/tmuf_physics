// Class implementation: CControlBase

// =================================================
// Function: CControlBase::BindEvent
// =================================================
CMwCmd * __thiscall
CControlBase::BindEvent
          (CControlBase *this,CControlBase *param_1,EEvent param_2,CMwNod *param_3,
          _func___cdecl_void_ulong *param_4,ulong param_5)
{
{
  uint uVar1;
  CMwCmdFastCallUser *this_00;
  CMwCmd *extraout_EAX;
  CMwCmd *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ac62eb;
  local_c = ExceptionList;
  uVar1 = DAT_00cca150 ^ (uint)&stack0xffffffe8;
  ExceptionList = &local_c;
  this_00 = operator_new(0x28);
  pCVar2 = (CMwCmd *)0x0;
  local_4 = 0;
  if (this_00 != (CMwCmdFastCallUser *)0x0) {
    CMwCmdFastCallUser::CMwCmdFastCallUser
              (this_00,(CMwCmdFastCallUser *)param_2,param_3,param_4,uVar1);
    pCVar2 = extraout_EAX;
  }
  (**(code **)(*(int *)this + 0x198))(param_2,pCVar2);
  ExceptionList = this_00;
  return pCVar2;
}
}

// =================================================
// Function: CControlBase::CControlBase
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CControlBase::CControlBase(CControlBase *this,CControlBase *param_1)
{
{
  undefined4 uVar1;
  CMwCmdFastCall *pCVar2;
  SCasterCat *pSVar3;
  CMwId *unaff_EBX;
  ulong unaff_ESI;
  CMwStack *unaff_EDI;
  undefined1 uStack00000008;
  undefined1 uStack0000000c;
  void *in_stack_00000010;
  CControlBase *pCVar4;
  void *pvVar5;
  undefined1 *puVar6;
  
  puVar6 = &LAB_00ac643c;
  pvVar5 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar4 = this;
  CSceneToy::CSceneToy((CSceneToy *)this,(CSceneToy *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  CMwStack::CMwStack((CMwStack *)(this + 0xd4),unaff_EDI,unaff_ESI);
  *(undefined4 *)(this + 0xf0) = 0;
  *(undefined **)(this + 0xf4) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined **)(this + 0x104) = PTR_DAT_00bbf7dc;
  uStack00000008 = 5;
  *(undefined4 *)(this + 0x110) = 0;
  CMwId::CMwId(this + 0x114,unaff_EBX);
  uStack0000000c = 6;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0x90) = 1;
  *(undefined4 *)(this + 0xfc) = 0x268;
  pCVar2 = CMwCmdContainer::AddFastCall
                     ((CMwCmdContainer *)(this + 0x48),(CMwCmdContainer *)this,
                      (CMwNod *)CGameCtnMenus::_vcall__376__flat______,
                      (_func___cdecl_void *)&DAT_00000011,(ulong)pCVar4);
  *(CMwCmdFastCall **)(this + 0xf8) = pCVar2;
  pCVar2 = CMwCmdContainer::AddFastCall
                     ((CMwCmdContainer *)(this + 0x48),(CMwCmdContainer *)this,
                      (CMwNod *)CGameCtnMenus::_vcall__384__flat______,
                      (_func___cdecl_void *)&DAT_0000000c,(ulong)pvVar5);
  *(CMwCmdFastCall **)(this + 0x70) = pCVar2;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0xa0) = uVar1;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0xa4) = uVar1;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0xa8) = uVar1;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xc4) = uVar1;
  *(undefined4 *)(this + 200) = uVar1;
  *(undefined4 *)(this + 0xcc) = uVar1;
  if (DAT_00d6c2fc == 0) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000a,
                        (ulong)puVar6);
    DAT_00d6c2fc = *(int *)(*(int *)pSVar3 + 0x20);
  }
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0x108) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CControlBase::Clean
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CControlBase::Clean(CControlBase *this,CHmsOcclusion *param_1)
{
{
  undefined4 uVar1;
  CPlugTree *this_00;
  CPlugTree *unaff_ESI;
  CPlugTree *in_stack_00000008;
  CControlBase *in_stack_0000000c;
  SParamEffect *in_stack_00000010;
  
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0xc4) = _DAT_00b2c060;
  *(undefined4 *)(this + 200) = uVar1;
  *(undefined4 *)(this + 0xcc) = uVar1;
  CleanTree(this,(CPlugCrystal *)(this + 0xac),unaff_ESI);
  this_00 = GetControlDrawTree(this,(CControlBase *)0x1,(int)param_1);
  if (this_00 != (CPlugTree *)0x0) {
    CPlugTree::HideInvalidTrees(this_00,in_stack_00000008);
  }
  if (*(int *)(this + 0x11c) != 0) {
    CControlEffectMaster::CleanUp
              (*(CControlEffectMaster **)(*(int *)(this + 0x11c) + 4),(CControlEffectMotion *)this,
               in_stack_0000000c,in_stack_00000010);
  }
  return;
}
}

// =================================================
// Function: CControlBase::CleanTree
// =================================================
void __thiscall CControlBase::CleanTree(CControlBase *this,CPlugCrystal *param_1,CPlugTree *param_2)
{
{
  int *piVar1;
  
  piVar1 = *(int **)param_1;
  if (piVar1 != (int *)0x0) {
    if ((int *)piVar1[9] != (int *)0x0) {
      (**(code **)(*(int *)piVar1[9] + 0xa0))(piVar1);
      *(undefined4 *)param_1 = 0;
      return;
    }
    (**(code **)(*piVar1 + 4))(1);
    *(undefined4 *)param_1 = 0;
  }
  return;
}
}

// =================================================
// Function: CControlBase::CreateFromStack
// =================================================
CControlBase * __cdecl
CControlBase::CreateFromStack(CMwNod *param_1,char *param_2,CControlStyle *param_3,int param_4)
{
{
  CMwNod *extraout_EAX;
  ulong uVar1;
  undefined *puVar2;
  CControlBase *pCVar3;
  char *unaff_EBX;
  ulong unaff_ESI;
  CControlStyle *in_stack_0000001c;
  int in_stack_00000020;
  CFastString *in_stack_ffffffd0;
  CMwStack *in_stack_ffffffd4;
  CMwStack local_28 [8];
  undefined4 local_20;
  undefined *local_1c;
  CMwStack local_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ac6560;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 != (CMwNod *)0x0) {
    CMwStack::CMwStack(local_28,(CMwStack *)(DAT_00cca150 ^ (uint)&stack0xffffffc8),unaff_ESI);
    CFastString::CFastString((CFastString *)local_28,(CFastString *)param_4,unaff_EBX);
    param_2 = (char *)CONCAT31(param_2._1_3_,1);
    uVar1 = CMwStack::FillIndexFromText
                      ((CMwStack *)&local_1c,(CMwStack *)0xffffffff,(ulong)param_1,extraout_EAX,
                       in_stack_ffffffd0);
    if (local_1c != PTR_DAT_00bbf7d8) {
      puVar2 = local_1c + -1;
      if ((local_1c[-1] & 0x80) != 0) {
        puVar2 = local_1c + -4;
      }
      operator_delete__(puVar2);
      local_20 = 0;
      local_1c = PTR_DAT_00bbf7d8;
    }
    if (uVar1 == 0) {
      pCVar3 = CreateFromStack(param_1,(char *)local_18,in_stack_0000001c,in_stack_00000020);
      CMwStack::~CMwStack(local_18,in_stack_ffffffd4);
      ExceptionList = param_2;
      return pCVar3;
    }
    CMwStack::~CMwStack(local_18,in_stack_ffffffd4);
  }
  ExceptionList = param_2;
  return (CControlBase *)0x0;
}
}

// =================================================
// Function: CControlBase::CreateStack
// =================================================
int __thiscall
CControlBase::CreateStack(CControlBase *this,CControlBase *param_1,CMwNod *param_2,char *param_3)
{
{
  CFastString CVar1;
  int extraout_EAX;
  CFastString *pCVar2;
  CMwNod *extraout_EAX_00;
  ulong uVar3;
  int iVar4;
  ulong unaff_EBP;
  SStringParam *unaff_ESI;
  int *unaff_EDI;
  ulong in_stack_00000010;
  undefined4 uStack00000014;
  undefined1 uStack00000018;
  undefined1 uStack0000001c;
  undefined4 uStack00000020;
  CMwStack *pCVar5;
  CMwStack *pCVar6;
  CFastString *in_stack_ffffffc8;
  CFastString *in_stack_ffffffcc;
  CFastString *pCVar7;
  CMwStack *in_stack_ffffffd8;
  CMwStack aCStack_24 [12];
  CMwStack local_18 [8];
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ac6530;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_2 == (CMwNod *)0x0) {
    param_2 = (CMwNod *)&DAT_00b2c878;
  }
  if (((*(int *)(this + 0xdc) != 0) || (*(int *)(this + 0xf0) == 0)) &&
     (*(CControlBase **)(this + 0xd0) == param_1)) {
    if (param_2 == (CMwNod *)0x0) {
      in_stack_ffffffcc = (CFastString *)0x0;
    }
    else {
      in_stack_ffffffcc = (CFastString *)param_2;
      do {
        CVar1 = *in_stack_ffffffcc;
        in_stack_ffffffcc = in_stack_ffffffcc + 1;
      } while (CVar1 != (CFastString)0x0);
      in_stack_ffffffcc = in_stack_ffffffcc + -(int)(param_2 + 1);
    }
    in_stack_ffffffc8 = (CFastString *)param_2;
    CFastString::Compare
              ((CFastString *)(this + 0xf0),(SParam_Fids *)&stack0xffffffc8,(SParam *)0x0,
               (int *)(DAT_00cca150 ^ (uint)&stack0xffffffb8),unaff_EDI);
    if (extraout_EAX == 0) {
      if (param_1 == (CControlBase *)0x0) {
        ExceptionList = local_4;
        return 0;
      }
      if (*(int *)(this + 0xf0) == 0) {
        ExceptionList = local_4;
        return 0;
      }
      ExceptionList = local_4;
      return 1;
    }
  }
  if (param_2 == (CMwNod *)0x0) {
    pCVar2 = (CFastString *)0x0;
  }
  else {
    pCVar2 = (CFastString *)param_2;
    do {
      CVar1 = *pCVar2;
      pCVar2 = pCVar2 + 1;
    } while (CVar1 != (CFastString)0x0);
    pCVar2 = pCVar2 + -(int)(param_2 + 1);
  }
  pCVar7 = (CFastString *)param_2;
  CFastString::SetString((CFastString *)(this + 0xf0),(CFastStringInt *)&stack0xffffffd0,unaff_ESI);
  pCVar6 = (CMwStack *)0x0;
  *(ulong *)(this + 0xd0) = in_stack_00000010;
  pCVar5 = (CMwStack *)0x763c02;
  CMwStack::SetSize((CMwStack *)(this + 0xd4),(CMwStatsValue *)0x0,unaff_EBP);
  if (((((byte)this[0xfc] & 0x20) != 0) && (*(int *)(this + 0xd0) != 0)) &&
     (*(CFastString *)param_2 != (CFastString)0x0)) {
    CMwStack::CMwStack(local_18,pCVar6,(ulong)in_stack_ffffffc8);
    uStack00000014 = 0;
    CFastString::CFastString
              ((CFastString *)local_18,(CFastString *)param_2,(char *)in_stack_ffffffcc);
    uStack00000018 = 1;
    uVar3 = CMwStack::FillIndexFromText
                      ((CMwStack *)&local_c,(CMwStack *)0xffffffff,in_stack_00000010,extraout_EAX_00
                       ,pCVar7);
    uStack0000001c = 0;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(local_10,(SHeaderCommunity *)pCVar2);
    if (uVar3 == 0) {
      iVar4 = (**(code **)(*(int *)this + 0x1c0))();
      if (iVar4 == 0) {
        do {
          CVar1 = *(CFastString *)param_2;
          param_2 = param_2 + 1;
        } while (CVar1 != (CFastString)0x0);
        CFastString::SetString
                  ((CFastString *)(this + 0xf0),(CFastStringInt *)&stack0xffffffd4,
                   (SStringParam *)pCVar5);
        *(char **)(this + 0xd0) = param_3;
      }
      CMwStack::~CMwStack(aCStack_24,pCVar5);
      ExceptionList = local_4;
      return iVar4;
    }
    uStack00000020 = 0xffffffff;
    CMwStack::~CMwStack((CMwStack *)&local_4,in_stack_ffffffd8);
  }
  ExceptionList = local_4;
  return 0;
}
}

// =================================================
// Function: CControlBase::GetControl
// =================================================
CControlBase * __cdecl CControlBase::GetControl(CControlContainer *param_1,char *param_2)
{
{
  CControlContainer *this;
  CMwId CVar1;
  CFastStringInt *pCVar2;
  undefined3 extraout_var;
  CPlugTree *pCVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  this = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ac6318;
  local_c = ExceptionList;
  pCVar2 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xfffffff0);
  if (param_1 == (CControlContainer *)0x0) {
    return (CControlBase *)0x0;
  }
  ExceptionList = &local_c;
  CVar1 = CMwId::CreateFromLocalName((char *)&param_1);
  local_4 = 0;
  pCVar3 = CControlContainer::GetChildFromId
                     (this,(CPlugTree *)CONCAT31(extraout_var,CVar1),(CMwId *)0x1);
  local_4 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(pCVar2);
  ExceptionList = local_c;
  return (CControlBase *)pCVar3;
}
}

// =================================================
// Function: CControlBase::GetControlDrawTree
// =================================================
CPlugTree * __thiscall
CControlBase::GetControlDrawTree(CControlBase *this,CControlBase *param_1,int param_2)
{
{
  int iVar1;
  CPlugTree *pCVar2;
  CControlStyle *pCVar3;
  CControlBase *unaff_ESI;
  CControlBase *unaff_EDI;
  SParamEffect *unaff_retaddr;
  
  if (param_1 != (CControlBase *)0x0) {
    if (*(int *)(this + 0x11c) != 0) {
      return *(CPlugTree **)(*(int *)(this + 0x11c) + 0x50);
    }
    pCVar2 = (CPlugTree *)(**(code **)(*(int *)this + 0x1b0))(this);
    return pCVar2;
  }
  pCVar3 = GetStyle(this,unaff_EDI);
  if (pCVar3 == (CControlStyle *)0x0) {
    return (CPlugTree *)0x0;
  }
  if ((*(int *)(pCVar3 + 0x17c) == 0) || (*(int *)(this + 0x11c) != 0)) {
    iVar1 = *(int *)(this + 0x11c);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 4) == *(int *)(pCVar3 + 0x17c))) goto LAB_00764749;
    if (iVar1 != 0) {
      CControlEffectMaster::CleanUp
                (*(CControlEffectMaster **)(iVar1 + 4),(CControlEffectMotion *)this,unaff_ESI,
                 unaff_retaddr);
    }
  }
  CControlEffectMaster::Init
            (*(CControlEffectMaster **)(pCVar3 + 0x17c),(CLoadGeomDynaSprite *)this,
             (CPlugVisualSprite *)0x0,(CVisionViewportDx9 *)0x0,(ESpriteColor0 *)param_2);
LAB_00764749:
  if (*(int *)(this + 0x11c) != 0) {
    return *(CPlugTree **)(*(int *)(this + 0x11c) + 0x50);
  }
  pCVar2 = (CPlugTree *)(**(code **)(*(int *)this + 0x1b0))();
  return pCVar2;
}
}

// =================================================
// Function: CControlBase::GetControlSize
// =================================================
GmVec2 __thiscall CControlBase::GetControlSize(CControlBase *this,CControlBase *param_1)
{
{
  GmVec2 extraout_DL;
  
  GetControlSize(this,param_1);
  return extraout_DL;
}
}

// =================================================
// Function: CControlBase::GetOffsetFromAlign
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
CControlBase::GetOffsetFromAlign
          (GmVec2 *param_1,GmVec2 param_2,EAlignHorizontal param_3,EAlignVertical param_4)
{
{
  float fVar1;
  undefined3 in_stack_00000009;
  int in_stack_00000014;
  
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  fVar1 = (float)_DAT_00b313b8;
  if (param_4 == 1) {
    _param_2 = _param_2 * fVar1;
  }
  else if (param_4 != 2) goto LAB_0076202d;
  *(float *)param_1 = _param_2;
LAB_0076202d:
  if (in_stack_00000014 != 1) {
    if (in_stack_00000014 == 2) {
      *(EAlignHorizontal *)(param_1 + 4) = param_3;
      return;
    }
    if (in_stack_00000014 != 4) {
      return;
    }
  }
  *(float *)(param_1 + 4) = fVar1 * (float)param_3;
  return;
}
}

// =================================================
// Function: CControlBase::GetParamInfo
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

SMwParamInfo * __thiscall
CControlBase::GetParamInfo(CControlBase *this,CControlBase *param_1,CMwStack *param_2)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  CMwParam *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 == (CControlBase *)0x0) {
    param_1 = this + 0xd4;
  }
  if (*(int *)(param_1 + 4) == 0) {
    return (SMwParamInfo *)0x0;
  }
  iVar1 = **(int **)(param_1 + 0x14);
  if (iVar1 == 0) {
    return (SMwParamInfo *)**(undefined4 **)(param_1 + 0x10);
  }
  if ((iVar1 == 1) && ((*(int **)(param_1 + 0x14))[1] == 0)) {
    iVar1 = *(int *)(*(int *)(this + 0xe4) + 4);
    iVar2 = CMwParam::IsIndexed(*(CMwParam **)(iVar1 + 8),unaff_ESI);
    if (iVar2 == 0) {
      uVar3 = CMwStack::MakeInfoFromStack
                        ((CMwStack *)param_1,(CMwStack *)&DAT_00d00a9c,(SMwParamInfo *)0x0,unaff_EDI
                        );
      if (uVar3 != 0) {
        return (SMwParamInfo *)0x0;
      }
    }
    else {
      _DAT_00d00a9c = *(undefined4 *)(iVar1 + 0x24);
      _DAT_00d00aa0 = 0xffffffff;
      _DAT_00d00aa4 = 0;
      _DAT_00d00aa8 = 0xffffffff;
      _DAT_00d00aac = *(undefined4 *)(iVar1 + 0x10);
      _DAT_00d00ab0 = *(undefined4 *)(iVar1 + 0x1c);
      _DAT_00d00ab4 = *(undefined4 *)(iVar1 + 0x18);
      _DAT_00d00ab8 = *(undefined4 *)(iVar1 + 0x28);
    }
    return (SMwParamInfo *)&DAT_00d00a9c;
  }
  return (SMwParamInfo *)0x0;
}
}

// =================================================
// Function: CControlBase::GetStyle
// =================================================
CControlStyle * __thiscall CControlBase::GetStyle(CControlBase *this,CControlBase *param_1)
{
{
  CSystemFid *unaff_ESI;
  CSystemFid *unaff_EDI;
  CMwNod *pCStack00000008;
  
  pCStack00000008 =
       CStyleSheetElem<class_CControlStyle>::Get
                 (this + 0x110,(CSystemData *)this,unaff_EDI,unaff_ESI,(ulong *)this);
  if (pCStack00000008 == (CMwNod *)0x0) {
    CSystemArchiveNod::LoadResource(0x40000020,&stack0x00000008);
    CStyleSheetElem<class_CControlStyle>::Set
              (this + 0x110,(CMwCmdScriptVarBool *)this,(int)pCStack00000008);
    pCStack00000008 = (CMwNod *)param_1;
  }
  return (CControlStyle *)pCStack00000008;
}
}

// =================================================
// Function: CControlBase::GetStyleSheetElem
// =================================================
CMwNod * __thiscall
CControlBase::GetStyleSheetElem
          (CControlBase *this,CControlStyleSheet *param_1,CMwId *param_2,CControlBase *param_3)
{
{
  CControlStyleSheet *this_00;
  CMwNod *pCVar1;
  CControlBase *unaff_ESI;
  
  this_00 = (CControlStyleSheet *)(**(code **)(*(int *)this + 0x1c8))();
  if (this_00 != (CControlStyleSheet *)0x0) {
    pCVar1 = CControlStyleSheet::GetStyleSheetElem(this_00,param_1,(CMwId *)this,unaff_ESI);
    return pCVar1;
  }
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CControlBase::GiveFocus
// =================================================
int __cdecl CControlBase::GiveFocus(CControlBase *param_1,int param_2)
{
{
  int iVar1;
  CControlBase *pCVar2;
  uint uVar3;
  CControlContainer *unaff_EDI;
  CControlBase *pCVar4;
  
  uVar3 = *(uint *)(param_1 + 0xfc);
  if ((((uVar3 & 2) == 0) && ((uVar3 & 0x4000) == 0)) && ((param_2 == 0 || ((uVar3 & 0x100) == 0))))
  {
    pCVar4 = *(CControlBase **)(param_1 + 0x6c);
    iVar1 = (**(code **)(*(int *)param_1 + 0x10))(0x7002000);
    if ((pCVar4 == (CControlBase *)0x0) && (pCVar4 = param_1, iVar1 == 0)) {
      uVar3 = *(uint *)(param_1 + 0xfc);
      if ((char)uVar3 < '\0') goto LAB_0076191b;
      (**(code **)(*(int *)param_1 + 0x17c))();
    }
    else if ((((byte)param_1[0xfc] & 0x80) == 0) ||
            ((iVar1 != 0 &&
             (pCVar2 = CControlContainer::GetFocusedChild((CControlContainer *)param_1,unaff_EDI),
             pCVar2 != param_1)))) {
      iVar1 = (**(code **)(*(int *)pCVar4 + 0x1f0))(param_1,param_2);
      return iVar1;
    }
    return 1;
  }
LAB_0076191b:
  if ((((uVar3 & 0x100) == 0) || (param_2 == 0)) || ((char)uVar3 < '\0')) {
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  *(uint *)(param_1 + 0xfc) =
       *(uint *)(param_1 + 0xfc) ^ (iVar1 << 0x11 ^ *(uint *)(param_1 + 0xfc)) & 0x20000;
  if (((uVar3 >> 0x11 & 1) == 0) && ((*(uint *)(param_1 + 0xfc) & 0x20000) != 0)) {
    (**(code **)(*(int *)param_1 + 0x1a8))();
  }
  return 0;
}
}

// =================================================
// Function: CControlBase::RecursiveSetVisualFocusForcedAndDraw
// =================================================
void __cdecl CControlBase::RecursiveSetVisualFocusForcedAndDraw(CControlBase *param_1,int param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  uint uVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  int unaff_retaddr;
  uint uVar6;
  
  if (param_1 != (CControlBase *)0x0) {
    uVar6 = *(uint *)(param_1 + 0xfc);
    uVar4 = (uint)((uVar6 >> 0x10 & 1) != (uint)(param_2 != 0));
    *(uint *)(param_1 + 0xfc) = ((uint)(param_2 != 0) << 0x10 ^ uVar6) & 0x10000 ^ uVar6;
    iVar1 = (**(code **)(*(int *)param_1 + 0x10))(0x7002000);
    if (iVar1 != 0) {
      uVar6 = 0x762143;
      pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x144,unaff_ESI);
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (param_1 + 0x144,pCVar5,uVar6);
          uVar6 = uVar4;
          RecursiveSetVisualFocusForcedAndDraw(*(CControlBase **)pSVar3,uVar4);
          pCVar5 = pCVar5 + 1;
        } while (pCVar5 < pCVar2);
      }
    }
    if (unaff_retaddr != 0) {
                    /* WARNING: Could not recover jumptable at 0x00762184. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)param_1 + 0x1a8))();
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CControlBase::RefreshSizeAndAlignment
// =================================================
void __thiscall CControlBase::RefreshSizeAndAlignment(CControlBase *this,CControlBase *param_1)
{
{
  CControlBase *unaff_ESI;
  
  RefreshSizeAndAlignmentNoDraw(this,unaff_ESI);
  (**(code **)(*(int *)this + 0x1ac))();
                    /* WARNING: Could not recover jumptable at 0x00762d2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x1a8))();
  return;
}
}

// =================================================
// Function: CControlBase::RefreshSizeAndAlignmentNoDraw
// =================================================
void __thiscall
CControlBase::RefreshSizeAndAlignmentNoDraw(CControlBase *this,CControlBase *param_1)
{
{
  undefined4 uStack_28;
  undefined4 uStack_24;
  CControlBase local_20 [8];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(float *)(this + 0xa0) < 0.0) {
    (**(code **)(*(int *)this + 0x1a8))();
    (**(code **)(*(int *)this + 0x1b4))(&uStack_18,0);
    *(undefined4 *)(this + 0x94) = uStack_18;
    *(undefined4 *)(this + 0x98) = uStack_14;
    *(undefined4 *)(this + 0x9c) = uStack_10;
    *(undefined4 *)(this + 0xa0) = uStack_c;
    *(undefined4 *)(this + 0xa4) = uStack_8;
    *(undefined4 *)(this + 0xa8) = uStack_4;
  }
  GetControlSize(this,local_20);
  uStack_28 = 0;
  uStack_24 = 0;
  (**(code **)(*(int *)this + 0x1b8))(&uStack_28);
  (**(code **)(*(int *)this + 0x1b8))(&uStack_24);
  return;
}
}

// =================================================
// Function: CControlBase::SetControlSizeFromBox
// =================================================
void __thiscall
CControlBase::SetControlSizeFromBox(CControlBase *this,CControlBase *param_1,GmBoxAligned *param_2)
{
{
  float local_18;
  float local_14;
  float local_c;
  float local_8;
  
  local_c = *(float *)param_1 - *(float *)(param_1 + 0xc);
  local_8 = *(float *)(param_1 + 4) - *(float *)(param_1 + 0x10);
  local_18 = (*(float *)param_1 + *(float *)(param_1 + 0xc)) - local_c;
  local_14 = (*(float *)(param_1 + 0x10) + *(float *)(param_1 + 4)) - local_8;
  (**(code **)(*(int *)this + 0x1b8))(&local_18);
  return;
}
}

// =================================================
// Function: CControlBase::SetReadOnly
// =================================================
void __cdecl CControlBase::SetReadOnly(CControlContainer *param_1,char *param_2,int param_3)
{
{
  uint uVar1;
  CControlBase *pCVar2;
  
  pCVar2 = GetControl(param_1,param_2);
  if (pCVar2 != (CControlBase *)0x0) {
    uVar1 = *(uint *)(pCVar2 + 0xfc);
    *(uint *)(pCVar2 + 0xfc) = ((uint)(param_3 != 0) * 2 ^ uVar1) & 2 ^ uVar1;
    if ((uVar1 >> 1 & 1) != param_3) {
                    /* WARNING: Could not recover jumptable at 0x007641ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)pCVar2 + 0x1a8))();
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CControlBase::SetSolid
// =================================================
void __thiscall
CControlBase::SetSolid(CControlBase *this,CSceneToyMotorbike *param_1,CPlugSolid *param_2)
{
{
  CMwNod *unaff_ESI;
  
  (**(code **)(*(int *)this + 0x1ac))();
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  if (*(CMwNod **)(this + 0xb4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xb4),unaff_ESI);
    *(undefined4 *)(this + 0xb4) = 0;
  }
  *(uint *)(this + 0xfc) =
       *(uint *)(this + 0xfc) ^
       ((uint)(param_1 != (CSceneToyMotorbike *)0x0) * 4 ^ *(uint *)(this + 0xfc)) & 4;
  CSceneMobil::SetSolid((CSceneMobil *)this,param_1,(CPlugSolid *)unaff_ESI);
  return;
}
}

