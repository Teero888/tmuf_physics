// Class implementation: CSystemData

// =================================================
// Function: CSystemData::CSystemData
// =================================================
void __thiscall CSystemData::CSystemData(CSystemData *this,CSystemData *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined **)(this + 0x18) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = DAT_00d52290;
  return;
}
}

// =================================================
// Function: CSystemData::Get
// =================================================
CMwNod * __thiscall
CSystemData::Get(CSystemData *this,CSystemData *param_1,CSystemFid *param_2,CSystemFid *param_3,
                ulong *param_4)
{
{
  CMwNodRef<class_CMwNod> *pCVar1;
  int iVar2;
  CSystemFidParameters *pCVar3;
  CSystemFidParameters *extraout_EAX;
  CSystemFidParameters *this_00;
  SHeaderCommunity *unaff_ESI;
  char *unaff_EDI;
  undefined4 *in_stack_00000014;
  SParam *pSVar4;
  SParam_Fids *pSVar5;
  undefined4 uStack_68;
  CSystemFidParameters *in_stack_ffffff9c;
  SParam_Fids aSStack_60 [4];
  SParam_Fid aSStack_5c [32];
  CSystemFidParameters local_3c [12];
  CFastBufferWheel<float> aCStack_30 [8];
  CSystemFidParameters aCStack_28 [4];
  CSystemFidParameters aCStack_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aec858;
  local_c = ExceptionList;
  pCVar3 = (CSystemFidParameters *)(DAT_00cca150 ^ (uint)&stack0xffffff88);
  if (((*(int *)param_3 == 0) || (param_1 == (CSystemData *)0x0)) || (param_2 == (CSystemFid *)0x0))
  {
    return (CMwNod *)0x0;
  }
  pCVar1 = (CMwNodRef<class_CMwNod> *)(this + 0x20);
  if (*(int *)(this + 0x20) == 0) {
    ExceptionList = &local_c;
    if (((DAT_00d79238 != (code *)0x0) && (iVar2 = *(int *)(this + 0x1c), iVar2 != 0)) &&
       ((*(int *)(iVar2 + 0x48) == 0 || (*(int *)(iVar2 + 100) == 0)))) {
      (*DAT_00d79238)(iVar2,*(undefined4 *)(this + 0x24));
    }
    if ((*(int *)(this + 0x1c) != 0) && (*(int *)(this + 0x14) != 0)) {
      CSystemFidParameters::CSystemFidParameters
                (local_3c,(CSystemFidParameters *)&DAT_00d55500,pCVar3);
      CFastString::CFastString((CFastString *)&uStack_68,(CFastString *)&DAT_00b2c98c,unaff_EDI);
      pSVar5 = (SParam_Fids *)*in_stack_00000014;
      pSVar4 = (SParam *)&stack0xffffff9c;
      CSystemFidParameters::SParam_Fid::SParam_Fid
                (aSStack_5c,(SParam_Fid *)param_3,*(CSystemFid **)(this + 0x1c));
      uStack_4 = CONCAT31(uStack_4._1_3_,2);
      CSystemFidParameters::AddParam(local_3c,extraout_EAX,pSVar4);
      CSystemFidParameters::SParam_Fids::~SParam_Fids(aSStack_60,pSVar5);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xffffff9c,unaff_ESI);
      CSystemFidParameters::Push(this_00,aCStack_30,(float *)0x1);
      CSystemFidParameters::RemappedLoadFromFid<class_CMwNod>(pCVar1,param_2,(CMwNod *)this);
      CSystemFidParameters::Pop(aCStack_28,(SCharStyle *)aCStack_28);
      uStack_68 = 0xa58c6a;
      CSystemFidParameters::~CSystemFidParameters(aCStack_24,in_stack_ffffff9c);
      ExceptionList = param_4;
      return *(CMwNod **)pCVar1;
    }
    CSystemArchiveNod::LoadFromFid<class_CMwNod>(pCVar1,param_2,7);
  }
  ExceptionList = local_c;
  return *(CMwNod **)pCVar1;
}
}

// =================================================
// Function: CSystemData::GetFid
// =================================================
CSystemFid * __thiscall
CSystemData::GetFid(CSystemData *this,CSystemData *param_1,CMwNod *param_2,CSystemFid *param_3,
                   ulong *param_4)
{
{
  int iVar1;
  char *pcVar2;
  CSystemFidFile *pCVar3;
  undefined1 *puVar4;
  CMwNod *unaff_EDI;
  CFastString local_14 [4];
  CSystemPackDesc aCStack_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00aec7b8;
  local_c = ExceptionList;
  pcVar2 = (char *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  if (*(int *)param_3 != 0) {
    if (((DAT_00d79238 != (code *)0x0) && (iVar1 = *(int *)(this + 0x1c), iVar1 != 0)) &&
       ((*(int *)(iVar1 + 0x48) == 0 || (*(int *)(iVar1 + 100) == 0)))) {
      (*DAT_00d79238)(iVar1,*(undefined4 *)(this + 0x24));
    }
    if (*(int *)(this + 0x1c) != 0) {
      CFastString::CFastString(local_14,(CFastString *)&DAT_00b2c98c,pcVar2);
      pCVar3 = CSystemPackManager::GetPackElem
                         (DAT_00d54250,*(CSystemPackManager **)(this + 0x1c),aCStack_10,
                          *(CFastString **)param_3,(ulong)param_3,(CSystemFid *)param_2,unaff_EDI);
      if (puStack_8 != PTR_DAT_00bbf7d8) {
        puVar4 = puStack_8 + -1;
        if ((puStack_8[-1] & 0x80) != 0) {
          puVar4 = puStack_8 + -4;
        }
        operator_delete__(puVar4);
      }
      ExceptionList = pvStack_4;
      return (CSystemFid *)pCVar3;
    }
  }
  ExceptionList = local_c;
  return (CSystemFid *)0x0;
}
}

// =================================================
// Function: CSystemData::Set
// =================================================
void __thiscall CSystemData::Set(CSystemData *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CMwCmdScriptVarBool **)(this + 0x20)) {
    if (param_1 != (CMwCmdScriptVarBool *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x20),unaff_ESI);
    }
    *(CMwCmdScriptVarBool **)(this + 0x20) = param_1;
  }
  return;
}
}

// =================================================
// Function: CSystemData::SetUpToDate
// =================================================
void __thiscall CSystemData::SetUpToDate(CSystemData *this,CSystemData *param_1,int param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x1c);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x68) == 0) {
      param_1 = (CSystemData *)0x1;
    }
    *(CSystemData **)(iVar1 + 100) = param_1;
  }
  return;
}
}

// =================================================
// Function: CSystemData::SetUrl
// =================================================
void __thiscall
CSystemData::SetUrl(CSystemData *this,CSystemData *param_1,CFastString *param_2,CFastString *param_3
                   )
{
{
  CMwNod *pCVar1;
  int extraout_EAX;
  CSystemPackDesc *this_00;
  SStringParam *unaff_EBX;
  int *unaff_ESI;
  int *unaff_EDI;
  CSystemFidsFolder *pCVar2;
  CFastString *in_stack_00000018;
  CMwNod *pCVar3;
  CMwNod *pCVar4;
  
  pCVar3 = *(CMwNod **)(param_1 + 4);
  pCVar4 = *(CMwNod **)param_1;
  if ((pCVar4 == *(CMwNod **)(this + 0x14)) &&
     (CFastString::Compare
                ((CFastString *)(this + 0x14),(SParam_Fids *)&stack0xfffffff8,(SParam *)0x0,
                 unaff_EDI,unaff_ESI), extraout_EAX == 0)) {
    return;
  }
  pCVar2 = *(CSystemFidsFolder **)(param_1 + 4);
  pCVar1 = *(CMwNod **)param_1;
  CFastString::SetString((CFastString *)(this + 0x14),(CFastStringInt *)&stack0x00000000,unaff_EBX);
  if (*(CMwNod **)(this + 0x1c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1c),pCVar3);
    *(undefined4 *)(this + 0x1c) = 0;
  }
  if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x20),pCVar4);
    *(undefined4 *)(this + 0x20) = 0;
  }
  if ((7 < *(uint *)param_1) &&
     (this_00 = CSystemPackManager::FindOrAddPackDescFromUrl
                          (DAT_00d54250,(CSystemPackManager *)param_1,in_stack_00000018,
                           (CFastString *)pCVar4,pCVar2),
     this_00 != *(CSystemPackDesc **)(this + 0x1c))) {
    if (this_00 != (CSystemPackDesc *)0x0) {
      CMwNod::MwAddRef((CMwNod *)this_00,pCVar1);
    }
    if (*(CMwNod **)(this + 0x1c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1c),(CMwNod *)param_2);
    }
    *(CSystemPackDesc **)(this + 0x1c) = this_00;
  }
  return;
}
}

