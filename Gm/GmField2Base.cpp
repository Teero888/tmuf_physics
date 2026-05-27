// Class implementation: GmField2Base

// =================================================
// Function: GmField2Base::GetBoundingCoords
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
GmField2Base::GetBoundingCoords
          (GmField2Base *this,GmField2Base *param_1,GmVec2 *param_2,GmNat2 *param_3,GmNat2 *param_4,
          GmVec2 *param_5)
{
{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar2 = *(float *)(this + 0x14) * (*(float *)param_1 - *(float *)(this + 4));
  fVar3 = *(float *)(this + 0x18) * (*(float *)(param_1 + 4) - *(float *)(this + 8));
  if (fVar2 < 0.0) {
    return 0;
  }
  if (((fVar2 <= 1.0) && (0.0 <= fVar3)) && (fVar3 <= 1.0)) {
    fVar4 = (float)*(int *)(this + 0x1c);
    if (*(int *)(this + 0x1c) < 0) {
      fVar4 = fVar4 + _DAT_00c418d0;
    }
    iVar1 = (int)ROUND(fVar4 * fVar2 - (float)_DAT_00b313b8);
    fVar5 = (float)iVar1;
    *(int *)param_2 = iVar1;
    if (iVar1 < 0) {
      fVar5 = fVar5 + _DAT_00c418d0;
    }
    *(float *)param_4 = fVar4 * fVar2 - fVar5;
    if (*(uint *)(this + 0x1c) <= *(uint *)param_2) {
      *(uint *)param_2 = *(uint *)(this + 0x1c) - 1;
    }
    iVar1 = *(int *)param_2;
    *(uint *)param_3 = iVar1 + 1U;
    if (*(uint *)(this + 0x1c) <= iVar1 + 1U) {
      *(uint *)param_3 = *(uint *)(this + 0x1c) - 1;
    }
    fVar2 = (float)*(int *)(this + 0x20);
    if (*(int *)(this + 0x20) < 0) {
      fVar2 = fVar2 + _DAT_00c418d0;
    }
    iVar1 = (int)ROUND(fVar2 * fVar3 - (float)_DAT_00b313b8);
    fVar4 = (float)iVar1;
    *(int *)(param_2 + 4) = iVar1;
    if (iVar1 < 0) {
      fVar4 = fVar4 + _DAT_00c418d0;
    }
    *(float *)(param_4 + 4) = fVar2 * fVar3 - fVar4;
    if (*(uint *)(this + 0x20) <= *(uint *)(param_2 + 4)) {
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x20) - 1;
    }
    iVar1 = *(int *)(param_2 + 4);
    *(uint *)(param_3 + 4) = iVar1 + 1U;
    if (*(uint *)(this + 0x20) <= iVar1 + 1U) {
      *(uint *)(param_3 + 4) = *(uint *)(this + 0x20) - 1;
    }
    return 1;
  }
  return 0;
}
}

