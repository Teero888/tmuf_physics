// Class implementation: CMotionParticleType

// =================================================
// Function: CMotionParticleType::GenerateSplashPart
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionParticleType::GenerateSplashPart
          (CMotionParticleType *this,CMotionParticleType *param_1,ulong param_2,GmVec3 *param_3,
          GmVec3 *param_4)
{
{
  float fVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  
  _rand();
  _rand();
  iVar2 = _rand();
  fVar1 = (((float)iVar2 / (float)_DAT_00b530f8 + (float)iVar2 / (float)_DAT_00b530f8) -
          (float)_DAT_00b2c188) * *(float *)(this + 0x154) + *(float *)(this + 0x150);
  __CIsin();
  __CIcos();
  *(float *)param_2 = fVar1 * (float)extraout_ST0_00;
  *(undefined4 *)(param_2 + 4) = 0;
  *(float *)(param_2 + 8) = fVar1 * (float)extraout_ST0;
  __CIsin();
  *(float *)param_3 = (float)extraout_ST0_01 * (float)extraout_ST0_00;
  __CIcos();
  *(float *)(param_3 + 4) = (float)extraout_ST0_02;
  *(float *)(param_3 + 8) = (float)extraout_ST0_01 * (float)extraout_ST0;
  iVar2 = _rand();
  fVar1 = (((float)iVar2 / (float)_DAT_00b530f8 + (float)iVar2 / (float)_DAT_00b530f8) -
          (float)_DAT_00b2c188) * *(float *)(this + 0x16c) + *(float *)(this + 0x168);
  *(float *)param_3 = fVar1 * *(float *)param_3;
  *(float *)(param_3 + 4) = *(float *)(param_3 + 4) * fVar1;
  *(float *)(param_3 + 8) = fVar1 * *(float *)(param_3 + 8);
  return;
}
}

// =================================================
// Function: CMotionParticleType::GetVertPerPartCount
// =================================================
ulong __thiscall
CMotionParticleType::GetVertPerPartCount(CMotionParticleType *this,CMotionParticleType *param_1)
{
{
  ulong uVar1;
  
  uVar1 = 2;
  if (*(int *)(this + 0x24) != 7) {
    uVar1 = *(ulong *)(this + 0x148);
  }
  return uVar1;
}
}

