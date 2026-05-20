// Class implementation: CSceneLight

// =================================================
// Function: CSceneLight::CSceneLight
// =================================================
void __thiscall CSceneLight::CSceneLight(CSceneLight *this,CSceneLight *param_1)
{
{
  int extraout_EAX;
  int iVar1;
  CHmsLight *unaff_ESI;
  CSceneLight *pCVar2;
  CHmsLight *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acdb53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar2 = this;
  CScenePoc::CScenePoc((CScenePoc *)this,(CScenePoc *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  local_c = operator_new(0x90);
  if (local_c == (CHmsLight *)0x0) {
    iVar1 = 0;
  }
  else {
    CHmsLight::CHmsLight(local_c,unaff_ESI);
    iVar1 = extraout_EAX;
  }
  *(CSceneLight **)(iVar1 + 100) = this;
  *(int *)(this + 0x30) = iVar1;
  CScenePoc::SwitchOn((CScenePoc *)this,(CGameCtnMediaBlockTransitionFade *)pCVar2);
  ExceptionList = (void *)0x1;
  return;
}
}

// =================================================
// Function: CSceneLight::GetKindLight
// =================================================
ESceneLight __thiscall CSceneLight::GetKindLight(CSceneLight *this,CSceneLight *param_1)
{
{
  ESceneLight EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x007d309e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = (**(code **)(**(int **)(*(int *)(this + 0x30) + 0x88) + 0x78))();
  return EVar1;
}
}

// =================================================
// Function: CSceneLight::SetLight
// =================================================
void __thiscall CSceneLight::SetLight(CSceneLight *this,CMotionLight *param_1,GxLight *param_2)
{
{
  CHmsLight::SetGxLight(*(CHmsLight **)(this + 0x30),(CHmsLight *)param_1,param_2);
  return;
}
}

// =================================================
// Function: CSceneLight::SetLightUpdate
// =================================================
void __thiscall
CSceneLight::SetLightUpdate(CSceneLight *this,CSceneLight *param_1,ESceneLightUpdate param_2)
{
{
  CHmsLight::SetUpdateType(*(CHmsLight **)(this + 0x30),(CHmsLight *)param_1,param_2);
  return;
}
}

