// Class implementation: CTrackManiaEditor

// =================================================
// Function: CTrackManiaEditor::ButtonBackStepOnClick
// =================================================
void __thiscall
CTrackManiaEditor::ButtonBackStepOnClick(CTrackManiaEditor *this,CTrackManiaEditor *param_1)
{
{
  CFastStringInt *in_stack_fffffff8;
  
  if (*(int *)(this + 0x47c) != 0) {
    CTrackManiaEditorInterface::SetContextualHelpMessage
              (*(CTrackManiaEditorInterface **)(this + 0xb8),
               (CTrackManiaEditorInterface *)(this + 0x2ec),in_stack_fffffff8);
    return;
  }
  (**(code **)(*(int *)this + 0x8c))(&stack0xfffffff8);
  return;
}
}

// =================================================
// Function: CTrackManiaEditor::IsPuzzlePlaceType
// =================================================
int __thiscall
CTrackManiaEditor::IsPuzzlePlaceType(CTrackManiaEditor *this,CTrackManiaEditor *param_1)
{
{
  if ((*(int *)(this + 0x38) != 3) && (*(int *)(this + 0x38) != 6)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CTrackManiaEditor::Start
// =================================================
void __thiscall CTrackManiaEditor::Start(CTrackManiaEditor *this,CGameCtnBench *param_1)
{
{
  CGameCtnCollection *this_00;
  int iVar1;
  CGameCtnChallenge *this_01;
  CSceneMobil *pCVar2;
  int iVar3;
  CGameCtnCursor *this_02;
  int extraout_EAX;
  CSceneMobil *this_03;
  CMwNod *extraout_EAX_00;
  GmVec3 *extraout_EAX_01;
  CMwId *pCVar4;
  CMwNod *extraout_EAX_02;
  CMwNod *pCVar5;
  ECardinalDir EVar6;
  CSceneMobil *unaff_EBX;
  GmVec3 *pGVar7;
  CMwNod *unaff_EBP;
  CGameCtnEditorScenePocLink *unaff_ESI;
  CPlugSolid *unaff_EDI;
  CPlugSolid *pCStack00000008;
  CGameCtnEditorScenePocLink *pCStack0000000c;
  undefined4 uStack00000018;
  CGameCtnChallenge *pCVar8;
  CGameCtnEditorScenePocLink *pCVar9;
  SStartParameters *pSVar10;
  CMwId *pCVar11;
  CSceneObject *in_stack_ffffffb0;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a8ab8c;
  local_c = ExceptionList;
  pCVar2 = (CSceneMobil *)(DAT_00cca150 ^ (uint)&stack0xffffffa0);
  ExceptionList = &local_c;
  pSVar10 = *(SStartParameters **)(param_1 + 8);
  iVar3 = CGameCtnChallenge::IsEditableCoord
                    (*(CGameCtnChallenge **)(this + 0x20),*(CGameCtnChallenge **)param_1,
                     SUB41(*(undefined4 *)(param_1 + 4),0));
  if (iVar3 == 0) {
    CreateDefaultParams(this,(CTrackManiaEditor *)&stack0xffffffac,pSVar10);
    Start(this,(CGameCtnBench *)&stack0xffffffb0);
  }
  else {
    this_02 = operator_new(0xf8);
    local_8 = (undefined1 *)0x0;
    if (this_02 == (CGameCtnCursor *)0x0) {
      iVar3 = 0;
    }
    else {
      CGameCtnCursor::CGameCtnCursor(this_02,(CGameCtnCursor *)pSVar10);
      iVar3 = extraout_EAX;
    }
    *(int *)(this + 0xbc) = iVar3;
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)param_1;
    *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(*(int *)(this + 0xbc) + 0x3c) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(*(int *)(this + 0xbc) + 0xf4) = 1;
    *(undefined4 *)(this + 0x510) = *(undefined4 *)(param_1 + 0x10);
    local_4 = 0xffffffff;
    *(undefined4 *)(this + 0x514) = *(undefined4 *)(param_1 + 0x14);
    this_03 = operator_new(0x48);
    local_4 = 1;
    if (this_03 == (CSceneMobil *)0x0) {
      pCVar5 = (CMwNod *)0x0;
    }
    else {
      CSceneMobil::CSceneMobil(this_03,pCVar2);
      pCVar5 = extraout_EAX_00;
    }
    local_4 = 0xffffffff;
    *(CMwNod **)(this + 0x3d4) = pCVar5;
    CMwNod::MwAddRef(pCVar5,(CMwNod *)pCVar2);
    pCStack00000008 = operator_new(0x74);
    if (pCStack00000008 == (CPlugSolid *)0x0) {
      pGVar7 = (GmVec3 *)0x0;
    }
    else {
      CPlugSolid::CPlugSolid(pCStack00000008,unaff_EDI);
      pGVar7 = extraout_EAX_01;
    }
    (**(code **)(*(int *)pGVar7 + 0x4c))();
    (**(code **)(**(int **)(this + 0x3d4) + 0xd8))();
    (**(code **)(**(int **)(this + 0x3d4) + 0x104))();
    *(undefined4 *)(this + 0x3d8) = *(undefined4 *)param_1;
    *(undefined4 *)(this + 0x3dc) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 0x3e0) = *(undefined4 *)(param_1 + 8);
    (**(code **)(*(int *)this + 0xb0))();
    iVar3 = *(int *)(this + 0xbc);
    this_00 = *(CGameCtnCollection **)(*(CGameCtnChallenge **)(this + 0x20) + 0x90);
    pCVar11 = *(CMwId **)(iVar3 + 0x1c);
    pCVar4 = CGameCtnChallenge::GetRealZoneId
                       (*(CGameCtnChallenge **)(this + 0x20),*(CGameCtnChallenge **)(iVar3 + 0x14),
                        SUB41(*(undefined4 *)(iVar3 + 0x18),0));
    pCVar9 = (CGameCtnEditorScenePocLink *)0x4a0342;
    CGameCtnCollection::SetCurrentZone(this_00,(CGameCtnCollection *)pCVar4,pCVar11);
    iVar3 = 0x4a0351;
    CSceneMobil::SetTranslation(*(CSceneMobil **)(this + 0x3d4),(GmIso4 *)(param_1 + 0x1c),pGVar7);
    pCStack0000000c = operator_new(0xc0);
    if (pCStack0000000c == (CGameCtnEditorScenePocLink *)0x0) {
      pCVar5 = (CMwNod *)0x0;
    }
    else {
      CGameCtnEditorScenePocLink::CGameCtnEditorScenePocLink(pCStack0000000c,unaff_ESI);
      pCVar5 = extraout_EAX_02;
    }
    pCStack00000008 = (CPlugSolid *)0xffffffff;
    *(CMwNod **)(this + 0xc4) = pCVar5;
    CMwNod::MwAddRef(pCVar5,unaff_EBP);
    *(undefined4 *)(*(int *)(this + 0xc4) + 0x84) = 0;
    CGameCtnEditorScenePocLink::SetTarget
              (*(CGameCtnEditorScenePocLink **)(this + 0xc4),
               *(CGameCtnEditorScenePocLink **)(this + 0x3d4),unaff_EBX);
    *(undefined4 *)(*(int *)(this + 0xc4) + 0x74) = *(undefined4 *)(param_1 + 0x28);
    iVar1 = *(int *)(this + 0xc4);
    uStack00000018 = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(iVar1 + 0x7c) = uStack00000018;
    *(undefined4 *)(iVar1 + 0x80) = uStack00000018;
    *(undefined4 *)(*(int *)(this + 0xc4) + 0x78) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(this + 0x45c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(this + 0x460) = *(undefined4 *)(param_1 + 0x28);
    CSceneObjectLink::SetObject
              (*(CSceneObjectLink **)(this + 0xc4),
               *(CSceneObjectLink **)(*(int *)(this + 0x18) + 0x74),in_stack_ffffffb0);
    *(undefined4 *)(*(int *)(this + 0xc4) + 100) = 0;
    (**(code **)(**(int **)(this + 0xc4) + 0x78))();
    CSceneObjectLink::OnEnterScene
              (*(CSceneObjectLink **)(this + 0xc4),
               *(CSceneToyBroomstick **)(*(int *)(this + 0x14) + 0x14));
    EVar6 = CGameCtnEditorScenePocLink::GetForwardDirectionFromCurrentHAngle
                      (*(CGameCtnEditorScenePocLink **)(this + 0xc4),pCVar9);
    this_01 = *(CGameCtnChallenge **)(this + 0x20);
    *(ECardinalDir *)(this + 0x34) = EVar6;
    if (*(int *)(this + 0x38) != 3) {
      pCVar8 = *(CGameCtnChallenge **)(this_01 + 0xd4);
    }
    else {
      pCVar8 = *(CGameCtnChallenge **)(this_01 + 0xd4);
    }
    CGameCtnChallenge::SetIsBlockHelpers(this_01,pCVar8,(uint)(*(int *)(this + 0x38) != 3),iVar3);
    *(undefined4 *)(this + 0x8c) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(this + 0x508) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(this + 0x50c) = *(undefined4 *)(param_1 + 0x3c);
    *(undefined4 *)(this + 0x4e4) = *(undefined4 *)(param_1 + 0x40);
  }
  ExceptionList = local_c;
  return;
}
}

