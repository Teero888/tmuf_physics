// Class implementation: CGameCtnMenuProfileScene

// =================================================
// Function: CGameCtnMenuProfileScene::UpdateAsync
// =================================================
/* WARNING: Removing unreachable block (ram,0x0072d097) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameCtnMenuProfileScene::UpdateAsync(CGameCtnMenuProfileScene *this,CInputPortDx8 *param_1)
{
{
  float fVar1;
  ulong *puVar2;
  GmMat43 *unaff_ESI;
  float fStack00000008;
  CMwTimerAdapter *in_stack_ffffff9c;
  float in_stack_ffffffa0;
  GmIso4 *pGVar3;
  undefined1 local_54 [4];
  float local_50;
  float local_4c;
  float local_48 [8];
  undefined1 auStack_28 [4];
  undefined1 local_24 [4];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(this + 0x1c) != 0) {
    GmMat3::SetIdentity(local_54,unaff_ESI);
    puVar2 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),in_stack_ffffff9c);
    pGVar3 = (GmIso4 *)(((float)(*puVar2 % 20000) / (float)_DAT_00b88e68) * (float)_DAT_00b59bb8);
    GmMat3::RotateY(&local_4c,pGVar3,in_stack_ffffffa0);
    fVar1 = *(float *)(this + 0x24);
    fStack00000008 = *(float *)(this + 0x2c);
    GmMat3::Set(local_24,(CMwCmdScriptVarBool *)local_48,(int)pGVar3);
    local_50 = *(float *)(this + 0x38) * local_18 +
               *(float *)(this + 0x34) * local_1c + *(float *)(this + 0x30) * local_20;
    local_4c = *(float *)(this + 0x38) * local_c +
               *(float *)(this + 0x34) * local_10 + *(float *)(this + 0x30) * local_14;
    local_48[0] = *(float *)(this + 0x38) * fVar1 +
                  *(float *)(this + 0x34) * local_4 + *(float *)(this + 0x30) * local_8;
    fStack00000008 = *(float *)(this + 0x34) + (fStack00000008 - local_4c);
    (**(code **)(**(int **)(this + 0x1c) + 0x88))(&local_20,0);
    if (*(int **)(this + 0x20) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x20) + 0x88))(auStack_28,0);
    }
  }
  return;
}
}

