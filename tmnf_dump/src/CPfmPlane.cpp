// Class implementation: CPfmPlane

// =================================================
// Function: CPfmPlane::Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CPfmPlane::Set(CPfmPlane *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float10 fVar11;
  float *in_stack_0000000c;
  
  fVar1 = *(float *)param_2;
  fVar2 = *(float *)param_1;
  fVar9 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  fVar10 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  fVar3 = *in_stack_0000000c;
  fVar4 = *(float *)param_1;
  fVar5 = in_stack_0000000c[1];
  fVar6 = *(float *)(param_1 + 4);
  fVar7 = in_stack_0000000c[2];
  fVar8 = *(float *)(param_1 + 8);
  *(float *)(this + 4) = fVar9 * (fVar7 - fVar8) - fVar10 * (fVar5 - fVar6);
  *(float *)(this + 8) = (fVar3 - fVar4) * fVar10 - (fVar1 - fVar2) * (fVar7 - fVar8);
  *(float *)(this + 0xc) = (fVar5 - fVar6) * (fVar1 - fVar2) - fVar9 * (fVar3 - fVar4);
  if (_DAT_00d52518 <
      *(float *)(this + 0xc) * *(float *)(this + 0xc) +
      *(float *)(this + 4) * *(float *)(this + 4) + *(float *)(this + 8) * *(float *)(this + 8)) {
    fVar11 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar11;
    *(float *)(this + 4) = fVar1 * *(float *)(this + 4);
    *(float *)(this + 8) = *(float *)(this + 8) * fVar1;
    *(float *)(this + 0xc) = fVar1 * *(float *)(this + 0xc);
  }
  *(undefined4 *)(this + 0x10) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 8);
  *(float *)(this + 0x1c) =
       -(*(float *)(this + 0x18) * *(float *)(this + 0xc) +
        *(float *)(this + 0x10) * *(float *)(this + 4) +
        *(float *)(this + 0x14) * *(float *)(this + 8));
  return;
}
}

