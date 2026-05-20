// Class implementation: CGameSafeFrame

// =================================================
// Function: CGameSafeFrame::GetAspectViewport
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameSafeFrame::GetAspectViewport
          (CGameSafeFrame *this,CGameSafeFrame *param_1,GmRectAligned *param_2)
{
{
  float fVar1;
  GmFrustumIso4 *unaff_ESI;
  float10 extraout_ST0;
  float *in_stack_0000000c;
  GmLensVal *in_stack_ffffffdc;
  float local_1c [2];
  float local_14;
  float local_10;
  float local_c;
  
  GetWindowSize(this,(CGameSafeFrame *)local_1c);
  GmLensVal::Reset(&local_14,unaff_ESI);
  GetLensVal(this,(CGameSafeFrame *)&local_10,in_stack_ffffffdc);
  local_1c[0] = ((local_c * (float)_DAT_00b36110) / (float)_DAT_00b36ab8) * (float)_DAT_00b313b8;
  __CItan();
  fVar1 = (float)*(int *)(this + 0x18);
  if (*(int *)(this + 0x18) < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  fVar1 = (local_10 / fVar1) * (float)extraout_ST0;
  local_14 = local_14 / local_10;
  in_stack_0000000c[1] = (*(float *)(this + 0x24) * fVar1 - fVar1) / *(float *)(this + 0x1c);
  in_stack_0000000c[3] = (*(float *)(this + 0x24) * fVar1 + fVar1) / *(float *)(this + 0x1c);
  *in_stack_0000000c =
       (*(float *)(this + 0x20) * fVar1 * local_14 - fVar1 * local_14) / *(float *)(this + 0x1c);
  in_stack_0000000c[2] =
       (fVar1 * local_14 + *(float *)(this + 0x20) * fVar1 * local_14) / *(float *)(this + 0x1c);
  return;
}
}

// =================================================
// Function: CGameSafeFrame::GetLensVal
// =================================================
void __thiscall
CGameSafeFrame::GetLensVal(CGameSafeFrame *this,CGameSafeFrame *param_1,GmLensVal *param_2)
{
{
  GmFrustumIso4 *unaff_ESI;
  undefined4 unaff_retaddr;
  GmFrustumIso4 *in_stack_ffffffbc;
  GmCamFreeVal local_3c [44];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  GmLocVal::Reset(&stack0xffffffbc,unaff_ESI);
  GmLensVal::Reset(&local_10,in_stack_ffffffbc);
  CSceneCamera::GetCamVal(*(CSceneCamera **)(this + 0x28),local_3c,(GmCamVal *)0x0);
  *(undefined4 *)param_2 = local_10;
  *(undefined4 *)(param_2 + 4) = local_c;
  *(undefined4 *)(param_2 + 8) = local_8;
  *(undefined4 *)(param_2 + 0xc) = local_4;
  *(undefined4 *)(param_2 + 0x10) = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CGameSafeFrame::GetWindowSize
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

GmVec2 __thiscall CGameSafeFrame::GetWindowSize(CGameSafeFrame *this,CGameSafeFrame *param_1)
{
{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar3 = *(int *)(this + 0x3c);
  fVar6 = (float)*(int *)(iVar3 + 0x2a4);
  if (*(int *)(iVar3 + 0x2a4) < 0) {
    fVar6 = fVar6 + _DAT_00c418d0;
  }
  fVar4 = (float)_DAT_00b313b8;
  fVar1 = *(float *)(this + 0x38);
  fVar2 = *(float *)(this + 0x30);
  fVar5 = (float)*(int *)(iVar3 + 0x2a8);
  if (*(int *)(iVar3 + 0x2a8) < 0) {
    fVar5 = fVar5 + _DAT_00c418d0;
  }
  *(float *)param_1 = fVar6 * (*(float *)(this + 0x34) - *(float *)(this + 0x2c)) * fVar4;
  *(float *)(param_1 + 4) = fVar5 * (fVar1 - fVar2) * fVar4;
  return SUB41(param_1,0);
}
}

// =================================================
// Function: CGameSafeFrame::SetVisible
// =================================================
void __thiscall CGameSafeFrame::SetVisible(CGameSafeFrame *this,CScene2d *param_1,int param_2)
{
{
  int unaff_ESI;
  SGmSmoothReal2 *unaff_EDI;
  ulong unaff_retaddr;
  
  *(CScene2d **)(this + 0x40) = param_1;
  Update(this,unaff_EDI,unaff_ESI,unaff_retaddr);
  *(CScene2d **)(this + 0x44) = param_1;
  if (*(CScene2d **)(this + 0x48) != (CScene2d *)0x0) {
    CScene2d::SetVisible(*(CScene2d **)(this + 0x48),param_1,(int)param_1);
  }
  return;
}
}

// =================================================
// Function: CGameSafeFrame::UpdateCameraFrustum
// =================================================
void __thiscall CGameSafeFrame::UpdateCameraFrustum(CGameSafeFrame *this,CGameSafeFrame *param_1)
{
{
  int iVar1;
  GmRectAligned *unaff_ESI;
  float local_10;
  CMwCmdScriptVarBool *local_c;
  int local_8;
  
  if (*(int *)(this + 0x44) != 0) {
    iVar1 = *(int *)(*(int *)(this + 0x28) + 0x30);
    GetAspectViewport(this,(CGameSafeFrame *)&local_10,unaff_ESI);
    if (*(int *)(iVar1 + 0x118) == 0) {
      local_10 = *(float *)(iVar1 + 0x124);
    }
    else {
      local_10 = *(float *)(iVar1 + 0x124) - *(float *)(iVar1 + 0x130);
    }
    GmFrustum::Set((int *)(iVar1 + 0x118),local_c,local_8);
  }
  return;
}
}

