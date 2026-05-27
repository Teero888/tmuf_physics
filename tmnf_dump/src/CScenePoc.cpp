// Class implementation: CScenePoc

// =================================================
// Function: CScenePoc::CScenePoc
// =================================================
void __thiscall CScenePoc::CScenePoc(CScenePoc *this,CScenePoc *param_1)
{
{
  CSceneObject *unaff_ESI;
  
  CSceneObject::CSceneObject((CSceneObject *)this,unaff_ESI);
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined ***)this = vftable;
  return;
}
}

// =================================================
// Function: CScenePoc::SwitchOn
// =================================================
void __thiscall CScenePoc::SwitchOn(CScenePoc *this,CGameCtnMediaBlockTransitionFade *param_1)
{
{
                    /* WARNING: Could not recover jumptable at 0x007dd2db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0x30) + 0x84))();
  return;
}
}

