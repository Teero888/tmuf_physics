// Class implementation: CSceneCamera

// =================================================
// Function: CSceneCamera::GetCamVal
// =================================================
void __thiscall CSceneCamera::GetCamVal(CSceneCamera *this,GmCamFreeVal *param_1,GmCamVal *param_2)
{
{
  CHmsCamera::GetCamVal(*(CHmsCamera **)(this + 0x30),param_1,param_2);
  return;
}
}

// =================================================
// Function: CSceneCamera::SetCamVal
// =================================================
void __thiscall
CSceneCamera::SetCamVal
          (CSceneCamera *this,CSceneCamera *param_1,GmCamVal *param_2,GmVec3 *param_3,int param_4)
{
{
  CSceneCamera *pCVar1;
  int iVar2;
  
  iVar2 = 0;
  pCVar1 = param_1;
  (**(code **)(*(int *)this + 0x88))();
  CHmsCamera::SetCamVal
            (*(CHmsCamera **)(this + 0x30),param_1,(GmCamVal *)param_1,(GmVec3 *)pCVar1,iVar2);
  (**(code **)(*(int *)this + 0x8c))(param_2);
  return;
}
}

// =================================================
// Function: CSceneCamera::SetSceneProperties
// =================================================
void __thiscall CSceneCamera::SetSceneProperties(CSceneCamera *this,CSceneCamera *param_1)
{
{
  int iVar1;
  int iVar2;
  float unaff_EDI;
  
  iVar1 = *(int *)(this + 0x14);
  iVar2 = *(int *)(this + 0x30);
  GmFrustum::SetFarZ((void *)(iVar2 + 0x118),*(CHmsCamera **)(iVar1 + 0x148),unaff_EDI);
  iVar2 = *(int *)(iVar2 + 0x210);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar1 + 0x14c);
    *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar1 + 0x150);
    *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(iVar1 + 0x154);
  }
  return;
}
}

