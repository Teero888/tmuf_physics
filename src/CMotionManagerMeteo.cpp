// Class implementation: CMotionManagerMeteo

// =================================================
// Function: CMotionManagerMeteo::StreamGetDirectionAndIntensityAt
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerMeteo::StreamGetDirectionAndIntensityAt
          (CMotionManagerMeteo *this,CMotionManagerMeteo *param_1,GmVec2 *param_2,float *param_3,
          float *param_4)
{
{
  float fVar1;
  float *unaff_EBX;
  float *unaff_EDI;
  uint uVar2;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 fVar3;
  float10 extraout_ST0_02;
  float *in_stack_00000014;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8 [2];
  
  if (*(int *)(this + 0x2c) == 0) {
    *(undefined4 *)param_2 = 0;
    *param_3 = 0.0;
    return;
  }
  uVar2 = (int)ROUND(*(float *)(this + 0xf0) * (float)_DAT_00b3d2c8 - (float)_DAT_00b313b8) &
          0x80000003;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
  }
  GmField2Compressed::GetScaleAndRotationAt
            (*(void **)(this + uVar2 * 4 + 0x2c),(GmField2Compressed *)param_1,(GmVec2 *)&local_18,
             &local_14,unaff_EDI);
  GmField2Compressed::GetScaleAndRotationAt
            (*(void **)(this + (uVar2 + 1 & 3) * 4 + 0x2c),(GmField2Compressed *)param_1,
             (GmVec2 *)&local_c,local_8,unaff_EBX);
  __CIsin();
  __CIcos();
  fVar1 = (float)extraout_ST0 * local_10;
  __CIsin();
  local_10 = (float)extraout_ST0_00 * local_8[0];
  __CIcos();
  local_c = (float)extraout_ST0_01 * local_8[0];
  local_18 = fVar1 + local_14 * (local_c - fVar1);
  fVar3 = (float10)func_0x009c1b40();
  __CIatan2();
  *in_stack_00000014 = *(float *)(this + 0xb4) * (float)fVar3;
  *param_4 = (float)extraout_ST0_02;
  return;
}
}

// =================================================
// Function: CMotionManagerMeteo::UpdateAsync
// =================================================
void __thiscall CMotionManagerMeteo::UpdateAsync(CMotionManagerMeteo *this,CInputPortDx8 *param_1)
{
{
  CInputPortDx8 *pCVar1;
  CClassicBufferMemory *unaff_ESI;
  
  if (*(CSystemFileMemMapped **)(this + 0x1c) != (CSystemFileMemMapped *)0x0) {
    pCVar1 = (CInputPortDx8 *)
             CSystemFileMemMapped::GetActualSize(*(CSystemFileMemMapped **)(this + 0x1c),unaff_ESI);
    if (*(int *)(this + 0x20) == -1) {
      *(CInputPortDx8 **)(this + 0x20) = pCVar1;
    }
    if (*(CMotionManagerMeteoPuffLull **)(this + 300) != (CMotionManagerMeteoPuffLull *)0x0) {
      CMotionManagerMeteoPuffLull::UpdateAsync(*(CMotionManagerMeteoPuffLull **)(this + 300),pCVar1)
      ;
    }
  }
  return;
}
}

// =================================================
// Function: CMotionManagerMeteo::WindGetDirectionAndIntensityAt
// =================================================
void __thiscall
CMotionManagerMeteo::WindGetDirectionAndIntensityAt
          (CMotionManagerMeteo *this,CMotionManagerMeteo *param_1,GmVec2 *param_2,float *param_3,
          float *param_4,CMotionWindBlocker *param_5)
{
{
  WindGetDirectionAndIntensityAt
            (this,param_1,param_2,param_3,(float *)&param_3,(CMotionWindBlocker *)&param_4);
  return;
}
}

