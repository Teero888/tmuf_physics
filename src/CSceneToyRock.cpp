// Class implementation: CSceneToyRock

// =================================================
// Function: CSceneToyRock::UpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneToyRock::UpdateAsync(CSceneToyRock *this,CInputPortDx8 *param_1)
{
{
  float fVar1;
  int iVar2;
  CMwCmdScriptVarBool *pCVar3;
  CPlugAudio *this_00;
  CMwId *pCVar4;
  void *this_01;
  CPlugTree *pCVar5;
  int iVar6;
  float *unaff_EBX;
  CMwTimerAdapter *unaff_EBP;
  int unaff_ESI;
  float *pfVar7;
  int unaff_EDI;
  float *pfVar8;
  float fStack00000008;
  float fStack0000000c;
  float fStack00000010;
  CPlugAudio *pCVar9;
  int in_stack_ffffffbc;
  SVolatileTreePointer *in_stack_ffffffc0;
  int in_stack_ffffffc4;
  undefined1 auStack_38 [4];
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [24];
  
  if ((*(int *)(this + 0x78) != 0) && (iVar2 = (**(code **)(*(int *)this + 0x78))(), iVar2 != 0)) {
    CSceneToySea::SetSamplingTime_Async
              (*(CSceneToySea **)(this + 0x78),(CSceneToySea *)0x1,unaff_ESI);
    pCVar9 = (CPlugAudio *)0x0;
    pCVar3 = (CMwCmdScriptVarBool *)(**(code **)(*(int *)this + 0x7c))();
    this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
    if (this_00 == (CPlugAudio *)0x0) {
      this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
    }
    pCVar4 = CPlugAudio::MwGetId(this_00,pCVar9);
    iVar2 = *(int *)pCVar4;
    this_01 = *(void **)(DAT_00d731e0 + 0x14);
    if (this_01 == (void *)0x0) {
      this_01 = (void *)(DAT_00d731e0 + 0xa0);
    }
    fStack_2c = CMwTimerAdapter::GetAsyncPeriod(this_01,unaff_EBP);
    CSceneToySea::GetPointElevationAssiette
              (*(CSceneToySea **)(this + 0x78),*(CSceneToySeaHouleTable **)(pCVar3 + 0x24),
               *(float *)(pCVar3 + 0x2c),(float)auStack_38,unaff_EBX);
    CSceneToySea::SetSamplingTime_Async
              (*(CSceneToySea **)(this + 0x78),(CSceneToySea *)0x0,in_stack_ffffffbc);
    pCVar5 = CSceneMobil::GetTree((CSceneMobil *)this,in_stack_ffffffc0);
    fVar1 = (*(float *)(pCVar5 + 0x38) - *(float *)(pCVar5 + 0x44)) + *(float *)(pCVar3 + 0x28);
    fVar1 = (fStack_2c - fVar1) /
            ((*(float *)(pCVar5 + 0x44) + *(float *)(pCVar5 + 0x38) + *(float *)(pCVar3 + 0x28)) -
            fVar1);
    fStack_30 = 0.0;
    if ((fVar1 < 0.0 == (fVar1 == 0.0)) &&
       (fStack_30 = fVar1, !NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0))) {
      fStack_30 = 1.0;
    }
    fStack_28 = fStack_30 * (*(float *)(this + 0x88) + *(float *)(this + 0x88)) -
                *(float *)(this + 0x88);
    fStack_24 = fStack_28 -
                (*(float *)(this + 0x8c) +
                (*(float *)(this + 0x90) - *(float *)(this + 0x8c)) * fStack_30) *
                *(float *)(this + 0x80);
    *(float *)(this + 0x80) = *(float *)(this + 0x80) + fStack_20 * fStack_24;
    fStack00000008 = *(float *)(pCVar3 + 0x24) + *(float *)(this + 0x7c) * fStack_20;
    fStack0000000c = *(float *)(this + 0x80) * fStack_20 + *(float *)(pCVar3 + 0x28);
    fStack00000010 = *(float *)(pCVar3 + 0x2c) + fStack_20 * *(float *)(this + 0x84);
    GmMat3::Set(auStack_1c,pCVar3,in_stack_ffffffc4);
    (**(code **)(*(int *)this + 0x88))(auStack_18,0);
    if (((0.0 < fStack_34) && (*(float *)(this + 0x94) <= _DAT_00b41d80)) &&
       (*(int *)(this + 0x70) != 0)) {
      pfVar7 = &fStack_20;
      pfVar8 = (float *)(*(int *)(this + 0x70) + 0x24);
      for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar8 = *pfVar7;
        pfVar7 = pfVar7 + 1;
        pfVar8 = pfVar8 + 1;
      }
      *(float *)(*(int *)(this + 0x70) + 0x4c) = fStack_30;
      iVar6 = *(int *)(this + 0x70);
      *(undefined4 *)(iVar6 + 0x60) = *(undefined4 *)(this + 0x7c);
      *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(this + 0x80);
      *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(this + 0x84);
      CMotionEmitterParticles::SetIsActive
                (*(CMotionEmitterParticles **)(this + 0x70),(CSceneObjectLink *)0x1,unaff_EDI);
    }
    *(float *)(this + 0x94) = fStack_34;
    if (60000 < (uint)(iVar2 - *(int *)(this + 0x6c))) {
      (**(code **)(**(int **)(this + 0x14) + 0x7c))(this);
    }
  }
  return;
}
}

