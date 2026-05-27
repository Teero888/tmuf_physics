// Class implementation: CGameCamera

// =================================================
// Function: CGameCamera::SetGameCamVal
// =================================================
void __thiscall
CGameCamera::SetGameCamVal(CGameCamera *this,CGameCamera *param_1,SGameCamVal *param_2)
{
{
  int iVar1;
  CGameCamera *pCVar2;
  int unaff_EDI;
  CSceneCamera *pCVar3;
  
  pCVar2 = param_1;
  pCVar3 = (CSceneCamera *)(this + 0x14);
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar3 = *(undefined4 *)pCVar2;
    pCVar2 = pCVar2 + 4;
    pCVar3 = pCVar3 + 4;
  }
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(param_1 + 0x5c);
  CSceneCamera::SetCamVal
            (*(CSceneCamera **)(this + 0x74),(CSceneCamera *)(this + 0x14),(GmCamVal *)(this + 0x58)
             ,(GmVec3 *)0x0,unaff_EDI);
  return;
}
}

