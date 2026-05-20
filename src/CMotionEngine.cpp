// Class implementation: CMotionEngine

// =================================================
// Function: CMotionEngine::CMotionEngine
// =================================================
void __thiscall CMotionEngine::CMotionEngine(CMotionEngine *this,CMotionEngine *param_1)
{
{
  CMwEngine *unaff_ESI;
  
  CMwEngine::CMwEngine((CMwEngine *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  DAT_00d67490 = CMotionShader::InstallNewMotionOnShader;
  return;
}
}

// =================================================
// Function: CMotionEngine::CreateMotionFromNod
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CMotion * __cdecl CMotionEngine::CreateMotionFromNod(CMwNod *param_1,CMwNod *param_2)
{
{
  CMotionCmdBase *this;
  int iVar1;
  CMotionPlayer *pCVar2;
  CMotionPlayer *extraout_EAX;
  CMotionSkel *this_00;
  CMotionPlayer *extraout_EAX_00;
  CMotionPlayer *extraout_EAX_01;
  CSceneFxNod *extraout_EAX_02;
  CMotionPlayer *extraout_EAX_03;
  CMotionTrackTree *extraout_EAX_04;
  CMotionPlayer *extraout_EAX_05;
  CMotionEmitterParticles *extraout_EAX_06;
  int *piVar3;
  CMotionPath *pCVar4;
  CMotionPath *extraout_EAX_07;
  CMotionPlayer *extraout_EAX_08;
  CFuncPlug *pCVar5;
  undefined4 unaff_EBX;
  CMotionTrackTree *this_01;
  float unaff_ESI;
  CMotionPlayer *this_02;
  undefined2 in_FPUControlWord;
  float fVar6;
  undefined4 unaff_retaddr;
  CMotionParticleEmitterModel *pCVar7;
  CFuncTree *pCVar8;
  CPlugFileSnd *pCVar9;
  CMotionTrack *pCVar10;
  CMwNod *pCVar11;
  CSceneFx *pCVar12;
  CMotionTrackMobilMove *pCVar13;
  float fVar14;
  CMotionPlayer *pCVar15;
  CFuncPlug *pCVar16;
  longlong lStack_24;
  CMotionTrackMobilMove aCStack_20 [4];
  float afStack_1c [2];
  void *pvStack_14;
  undefined4 uStack_10;
  CMotionEmitterParticles *local_c;
  CMotionLight *pCStack_8;
  CMotionPlayer *pCStack_4;
  
  pCStack_4 = (CMotionPlayer *)0xffffffff;
  pCStack_8 = (CMotionLight *)&LAB_00a9809e;
  local_c = ExceptionList;
  lStack_24 = CONCAT44(aCStack_20,unaff_EBX);
  ExceptionList = &local_c;
  pCVar15 = (CMotionPlayer *)0x8033000;
  this_02 = (CMotionPlayer *)0x0;
  iVar1 = (**(code **)(*(int *)param_2 + 0x10))(0x8033000,DAT_00cca150 ^ (uint)&stack0xffffffd0);
  if (iVar1 != 0) {
    pCVar2 = operator_new(0x58);
    pCStack_8 = (CMotionLight *)0x0;
    if (pCVar2 != (CMotionPlayer *)0x0) {
      CMotionPlayer::CMotionPlayer(pCVar2,pCVar15);
      this_02 = extraout_EAX;
    }
    pCStack_8 = (CMotionLight *)0xffffffff;
    (**(code **)(*(int *)this_02 + 0x94))(unaff_retaddr);
    pCVar10 = (CMotionTrack *)&stack0xffffffd8;
    iVar1 = (**(code **)(*(int *)param_2 + 0x8c))();
    if (iVar1 != 0) {
      pCStack_4 = (CMotionPlayer *)CONCAT22(pCStack_4._2_2_,in_FPUControlWord);
      lStack_24 = (longlong)ROUND(unaff_ESI * (float)_DAT_00c418d8);
      CMotionCmdBase::SetPeriod(*(CMotionCmdBase **)(this_02 + 0x30),pCVar16,(float)pCVar10);
    }
    CMotionPlayer::AddTrack(this_02,(CMotionPlayer *)param_2,pCVar10);
    ExceptionList = pvStack_14;
    return (CMotion *)this_02;
  }
  pCVar2 = (CMotionPlayer *)0x5006000;
  iVar1 = (**(code **)(*(int *)param_2 + 0x10))();
  if (iVar1 != 0) {
    this_00 = operator_new(0x48);
    local_c = (CMotionEmitterParticles *)0x1;
    if (this_00 == (CMotionSkel *)0x0) {
      pCVar15 = (CMotionPlayer *)0x0;
    }
    else {
      CMotionSkel::CMotionSkel(this_00,(CMotionSkel *)pCVar2);
      pCVar15 = extraout_EAX_00;
    }
    local_c = (CMotionEmitterParticles *)0xffffffff;
    pCVar11 = param_2;
    (**(code **)(*(int *)pCVar15 + 0xa0))();
    pCStack_4 = operator_new(0x58);
    uStack_10 = 2;
    if (pCStack_4 != (CMotionPlayer *)0x0) {
      CMotionPlayer::CMotionPlayer(pCStack_4,(CMotionPlayer *)pCVar11);
      this_02 = extraout_EAX_01;
    }
    uStack_10 = 0xffffffff;
    (**(code **)(*(int *)this_02 + 0x94))(pCStack_8);
    iVar1 = (**(code **)(*(int *)pCVar15 + 0x8c))(&stack0xffffffd8);
    if (iVar1 != 0) {
      pCStack_4 = (CMotionPlayer *)CONCAT22(pCStack_4._2_2_,in_FPUControlWord);
      CMotionCmdBase::SetPeriod
                (*(CMotionCmdBase **)(this_02 + 0x30),
                 (CFuncPlug *)(longlong)ROUND((float)pCVar16 * (float)_DAT_00c418d8),(float)pCVar11)
      ;
    }
    CMotionPlayer::AddTrack(this_02,pCVar15,(CMotionTrack *)pCVar11);
    *(undefined4 *)(this_02 + 0x14) = *(undefined4 *)(param_2 + 0x1c);
    ExceptionList = pvStack_14;
    return (CMotion *)this_02;
  }
  pCVar12 = (CSceneFx *)0x5004000;
  iVar1 = (**(code **)(*(int *)param_2 + 0x10))();
  if (iVar1 == 0) {
    pCVar8 = (CFuncTree *)0x5018000;
    iVar1 = (**(code **)(*(int *)param_2 + 0x10))();
    if (iVar1 == 0) {
      pCVar7 = (CMotionParticleEmitterModel *)0x805b000;
      iVar1 = (**(code **)(*(int *)param_2 + 0x10))();
      if (iVar1 != 0) {
        local_c = operator_new(0x90);
        afStack_1c[1] = 9.80909e-45;
        if (local_c != (CMotionEmitterParticles *)0x0) {
          CMotionEmitterParticles::CMotionEmitterParticles
                    (local_c,(CMotionEmitterParticles *)pCVar7);
          this_02 = (CMotionPlayer *)extraout_EAX_06;
        }
        afStack_1c[1] = -NAN;
        CMotionEmitterParticles::SetEmitterModel
                  ((CMotionEmitterParticles *)this_02,(CMotionEmitterParticles *)param_2,pCVar7);
        (**(code **)(*(int *)this_02 + 0x94))(local_c);
        ExceptionList = pvStack_14;
        return (CMotion *)this_02;
      }
      iVar1 = (**(code **)(*(int *)param_2 + 0x10))(0xa008000);
      if (iVar1 == 0) {
        ExceptionList = pvStack_14;
        return (CMotion *)0x0;
      }
      iVar1 = (**(code **)(*(int *)param_2 + 0x14))();
      if ((iVar1 != 0) && (piVar3 = (int *)(**(code **)(*(int *)param_2 + 0x14))(), *piVar3 == -1))
      {
        ExceptionList = pvStack_14;
        return (CMotion *)0x0;
      }
      pCVar4 = operator_new(0x4c);
      local_c = (CMotionEmitterParticles *)0x8;
      if (pCVar4 == (CMotionPath *)0x0) {
        pCVar4 = (CMotionPath *)0x0;
      }
      else {
        CMotionPath::CMotionPath(pCVar4,(CMotionPath *)pCVar2);
        pCVar4 = extraout_EAX_07;
      }
      local_c = (CMotionEmitterParticles *)0xffffffff;
      pCVar9 = (CPlugFileSnd *)0x56bcab;
      CMotionPath::SetPath(pCVar4,(CSceneToySubway *)param_2,(CScenePath *)pCVar2);
      fVar14 = 7.965544e-39;
      pCVar2 = operator_new(0x58);
      pCStack_8 = (CMotionLight *)0x9;
      if (pCVar2 != (CMotionPlayer *)0x0) {
        CMotionPlayer::CMotionPlayer(pCVar2,pCVar15);
        this_02 = extraout_EAX_08;
      }
      pCStack_4 = (CMotionPlayer *)0xffffffff;
      (**(code **)(*(int *)this_02 + 0x94))(pCVar2);
      CMotionPlayer::AddTrack(this_02,(CMotionPlayer *)pCVar4,(CMotionTrack *)pCVar7);
      this = *(CMotionCmdBase **)(this_02 + 0x30);
      fVar6 = CScenePath::GetLength((CScenePath *)param_2,pCVar9);
      pCVar5 = (CFuncPlug *)CMwTimer::SecondsToMwTime(fVar6);
      CMotionCmdBase::SetPeriod(this,pCVar5,fVar14);
      ExceptionList = pvStack_14;
      return (CMotion *)this_02;
    }
    pCStack_8 = operator_new(0x38);
    pvStack_14 = (void *)0x5;
    if (pCStack_8 == (CMotionLight *)0x0) {
      this_01 = (CMotionTrackTree *)0x0;
    }
    else {
      CMotionLight::CMotionLight(pCStack_8,(CMotionLight *)pCVar8);
      this_01 = extraout_EAX_04;
    }
    pvStack_14 = (void *)0xffffffff;
    CMotionTrackTree::SetFuncTree(this_01,(CPlugTree *)param_2,pCVar8);
    pCStack_4 = operator_new(0x58);
    uStack_10 = 6;
    if (pCStack_4 != (CMotionPlayer *)0x0) {
      CMotionPlayer::CMotionPlayer(pCStack_4,(CMotionPlayer *)pCVar12);
      this_02 = extraout_EAX_05;
    }
    local_c = (CMotionEmitterParticles *)0xffffffff;
    pCVar13 = (CMotionTrackMobilMove *)pCStack_4;
    (**(code **)(*(int *)this_02 + 0x94))();
    iVar1 = (**(code **)(*(int *)this_01 + 0x8c))(afStack_1c);
    if (iVar1 == 0) goto LAB_0056bbc4;
    pCStack_4 = (CMotionPlayer *)CONCAT22(pCStack_4._2_2_,in_FPUControlWord);
    lStack_24 = (longlong)ROUND(afStack_1c[0] * (float)_DAT_00c418d8);
    pCVar5 = pCVar16;
  }
  else {
    pCStack_4 = operator_new(0x78);
    uStack_10 = 3;
    if (pCStack_4 == (CMotionPlayer *)0x0) {
      this_01 = (CMotionTrackTree *)0x0;
    }
    else {
      CMotionTrackMobilMove::CMotionTrackMobilMove
                ((CMotionTrackMobilMove *)pCStack_4,(CMotionTrackMobilMove *)pCVar12);
      this_01 = (CMotionTrackTree *)extraout_EAX_02;
    }
    uStack_10 = 0xffffffff;
    CSceneFxNod::FxSet((CSceneFxNod *)this_01,(CSceneFxNod *)param_2,pCVar12);
    pCVar15 = operator_new(0x58);
    local_c = (CMotionEmitterParticles *)0x4;
    if (pCVar15 != (CMotionPlayer *)0x0) {
      CMotionPlayer::CMotionPlayer(pCVar15,pCVar2);
      this_02 = extraout_EAX_03;
    }
    pCStack_8 = (CMotionLight *)0xffffffff;
    (**(code **)(*(int *)this_02 + 0x94))(pCVar15);
    pCVar13 = aCStack_20;
    iVar1 = (**(code **)(*(int *)this_01 + 0x8c))();
    if (iVar1 == 0) goto LAB_0056bbc4;
    pCStack_4 = (CMotionPlayer *)CONCAT22(pCStack_4._2_2_,in_FPUControlWord);
    pCVar5 = (CFuncPlug *)(longlong)ROUND((float)pCVar16 * (float)_DAT_00c418d8);
  }
  CMotionCmdBase::SetPeriod(*(CMotionCmdBase **)(this_02 + 0x30),pCVar5,(float)pCVar13);
LAB_0056bbc4:
  CMotionPlayer::AddTrack(this_02,(CMotionPlayer *)this_01,(CMotionTrack *)pCVar13);
  ExceptionList = pvStack_14;
  return (CMotion *)this_02;
}
}

