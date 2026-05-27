// Class implementation: CScene3d

// =================================================
// Function: CScene3d::SceneFxFindFromClassId
// =================================================
CSceneFx * __thiscall
CScene3d::SceneFxFindFromClassId
          (CScene3d *this,CScene3d *param_1,ulong param_2,CSceneFxNod **param_3)
{
{
  CSceneFxNod *pCVar1;
  ulong unaff_ESI;
  
  if (param_2 != 0) {
    *(undefined4 *)param_2 = 0;
  }
  if (*(CSceneFxNod **)(this + 0x158) != (CSceneFxNod *)0x0) {
    pCVar1 = CSceneFxNod::NodFindFromFxClassId
                       (*(CSceneFxNod **)(this + 0x158),(CSceneFxNod *)param_1,unaff_ESI);
    if (param_2 != 0) {
      *(CSceneFxNod **)param_2 = pCVar1;
    }
    if (pCVar1 != (CSceneFxNod *)0x0) {
      return *(CSceneFx **)(pCVar1 + 0x30);
    }
  }
  return (CSceneFx *)0x0;
}
}

// =================================================
// Function: CScene3d::SceneFxGlobalStartStop
// =================================================
void __thiscall CScene3d::SceneFxGlobalStartStop(CScene3d *this,CScene3d *param_1,int param_2)
{
{
  if ((*(int *)(this + 0x15c) != 0) != (param_1 != (CScene3d *)0x0)) {
    *(CScene3d **)(this + 0x15c) = param_1;
    if (*(CSceneFxNod **)(this + 0x158) != (CSceneFxNod *)0x0) {
      CSceneFxNod::UpdateAllActivityFromScene
                (*(CSceneFxNod **)(this + 0x158),(CSceneFxNod *)this,(CScene3d *)param_2);
      return;
    }
  }
  return;
}
}

