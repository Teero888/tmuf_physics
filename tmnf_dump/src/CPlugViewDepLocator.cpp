// Class implementation: CPlugViewDepLocator

// =================================================
// Function: CPlugViewDepLocator::AdaptFrustum
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugViewDepLocator::AdaptFrustum
          (CPlugViewDepLocator *this,CPlugViewDepLocator *param_1,GmIso4 *param_2,GmIso4 *param_3,
          GmFrustum *param_4,GmMat4 *param_5)
{
{
  CPlugViewDepLocator *this_00;
  float fVar1;
  ulong uVar2;
  float *unaff_EBX;
  GmIso4 *unaff_EBP;
  GmIso4 *unaff_ESI;
  GmIso4 *unaff_EDI;
  float10 fVar3;
  void *in_stack_00000034;
  GmIso4 *pGVar4;
  GmIso4 *in_stack_fffffee8;
  GmIso4 *pGVar5;
  GmIso4 *pGVar6;
  GmIso4 *in_stack_fffffef0;
  GmIso4 *in_stack_fffffef4;
  GmIso4 *pGVar7;
  GmIso4 *in_stack_fffffef8;
  GmIso4 *in_stack_fffffefc;
  GmIso4 *local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  GmIso4 *local_f0;
  GmIso4 *pGStack_ec;
  float local_e8;
  undefined4 local_e4;
  GmIso4 *local_e0;
  GmIso4 *local_dc;
  float local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  float local_c0;
  undefined4 local_bc;
  undefined8 local_ac;
  undefined1 local_a4 [4];
  double local_a0 [3];
  SPlugFaceCull aSStack_84 [12];
  SPlugFaceCull aSStack_78 [40];
  undefined1 auStack_50 [4];
  SPlugFaceCull aSStack_4c [4];
  SPlugFaceCull aSStack_48 [52];
  undefined1 auStack_14 [8];
  SPlugFaceCull aSStack_c [12];
  
  local_f4 = *(float *)(this + 0x18);
  pGVar4 = *(GmIso4 **)(this + 0x1c);
  if (*(int *)(this + 0x14) != 0) {
    local_f4 = _DAT_00d11c34 * (float)_DAT_00b313b8;
    pGVar4 = (GmIso4 *)((float)_DAT_00b313b8 * _DAT_00d11c38);
  }
  local_e8 = 1.0;
  local_e4 = 0;
  local_e0 = (GmIso4 *)0x0;
  local_c4 = 0;
  local_dc = (GmIso4 *)0x0;
  local_d8 = 0.0;
  local_d4 = 0;
  local_c0 = local_f4;
  local_d0 = 0;
  local_cc = 0;
  local_bc = 0;
  local_c8 = 0x3f800000;
  GmIso4::SetMult(local_a0,(SPlugFaceCull *)&local_e8,(SPlugFaceCull *)param_2,unaff_EDI);
  if (*(int *)param_4 == 0) {
    pGVar7 = (GmIso4 *)((*(float *)(param_2 + 0x28) - (float)local_f0) * (float)_DAT_00b313b8);
    pGVar5 = in_stack_fffffee8;
    pGVar6 = (GmIso4 *)(*(float *)(param_2 + 0x28) - (float)local_f0);
    if (((float)pGVar7 < (float)in_stack_fffffee8) &&
       (pGVar5 = pGVar7, pGVar6 = pGVar7,
       (float)pGVar7 < (float)local_f0 != ((float)pGVar7 == (float)local_f0))) {
      pGVar5 = local_f0;
    }
    local_100 = (GmIso4 *)0x0;
    local_fc = 1.0;
    local_f8 = 0.0;
    local_f4 = -(float)local_f0;
    in_stack_fffffef0 = (GmIso4 *)0x0;
    GmVec4::PlaneEqSetMult(&local_ac,(GmVec4 *)&local_100,(GmVec4 *)param_2,unaff_ESI);
    GmVec4::PlaneEqSetMult
              ((void *)((int)&local_ac + 4),(GmVec4 *)&stack0xfffffef4,(GmVec4 *)param_2,unaff_EBP);
    local_e0 = *(GmIso4 **)(param_4 + 0xc);
    local_e4 = *(undefined4 *)(param_4 + 0x18);
    in_stack_fffffef8 = (GmIso4 *)0x0;
    in_stack_fffffefc = *(GmIso4 **)(param_4 + 8);
    local_100 = (GmIso4 *)0x3f800000;
    local_ac = 0;
    pGVar7 = (GmIso4 *)
             ((float)in_stack_fffffefc * (float)in_stack_fffffefc + 0.0 + (float)_DAT_00b2c188);
    if (_DAT_00d18620 < (float)pGVar7) {
      fVar3 = (float10)func_0x009c1b40();
      pGVar7 = (GmIso4 *)(1.0 / (float)fVar3);
      in_stack_fffffef8 = (GmIso4 *)((float)_PTR_00b2c178 * (float)pGVar7);
      in_stack_fffffefc = (GmIso4 *)((float)in_stack_fffffefc * (float)pGVar7);
      local_100 = pGVar7;
    }
    local_f8 = 0.0;
    local_f4 = 0.0;
    local_f0 = (GmIso4 *)0x0;
    uVar2 = GmVec4::PlaneEqInterLine
                      (local_a4,(GmVec4 *)&local_f8,(GmVec3 *)&stack0xfffffef8,
                       (GmVec3 *)&stack0xfffffef0,unaff_EBX);
    in_stack_fffffef4 = local_dc;
    if ((uVar2 != 0) && ((float)local_dc <= (float)pGVar7)) {
      in_stack_fffffef4 = pGVar7;
    }
    if ((float)local_e0 < (float)in_stack_fffffef4) {
      in_stack_fffffef4 = local_e0;
    }
    local_f4 = (float)in_stack_fffffefc * (float)in_stack_fffffef4;
    local_f0 = (GmIso4 *)((float)local_100 * (float)in_stack_fffffef4);
    pGStack_ec = (GmIso4 *)((float)in_stack_fffffef4 * local_fc);
    GmVec3::SetMult(&stack0xfffffefc,(SPlugFaceCull *)&local_f4,(SPlugFaceCull *)param_2,pGVar4);
    local_f0 = local_100;
    pGStack_ec = local_e0;
    local_e8 = local_f8;
    GmVec3::SetMult(&local_100,(SPlugFaceCull *)&local_f0,(SPlugFaceCull *)param_2,pGVar5);
    local_dc = (GmIso4 *)(local_f8 / local_f4);
    *(GmIso4 **)(param_4 + 8) = local_dc;
    local_fc = 0.0;
    local_f8 = *(float *)(param_4 + 0x14);
    local_f4 = 1.0;
    local_d8 = local_f8 * local_f8 + (float)local_a0[0] + (float)_DAT_00b2c188;
    if (_DAT_00d18620 < local_d8) {
      fVar3 = (float10)func_0x009c1b40();
      local_f4 = 1.0 / (float)fVar3;
      local_fc = (float)_PTR_00b2c178 * local_f4;
      local_f8 = local_f4 * local_f8;
      local_d8 = local_f4;
    }
    GmVec3::Mult(&local_fc,(GmIso3 *)param_2,(GmIso3 *)pGVar6);
    if (((local_d8 < 0.0) && (fVar1 = (float)_DAT_00b30a10, fVar1 < *(float *)(param_4 + 0x14))) &&
       (fVar1 < local_f4)) {
      *(float *)(param_4 + 0x14) =
           *(float *)(param_2 + 0x14) * (float)local_f0 +
           *(float *)(param_2 + 0xc) * local_f8 + *(float *)(param_2 + 0x10) * fVar1;
    }
    if (*(float *)(param_4 + 0x14) < *(float *)(param_4 + 8)) {
      *(float *)(param_4 + 8) = *(float *)(param_4 + 0x14) - (float)_DAT_00b362c0;
    }
  }
  GmIso4::SetMult(auStack_14,(SPlugFaceCull *)param_2,aSStack_84,in_stack_fffffef0);
  GmMat4::SetFrustumProjection
            (auStack_50,(GmMat4 *)param_4,(GmFrustum *)0x1,(ulong)in_stack_fffffef4);
  GmMat4::SetMult(in_stack_00000034,aSStack_c,aSStack_4c,in_stack_fffffef8);
  this_00 = this + 0x20;
  GmMat4::SetMult(this_00,aSStack_78,aSStack_48,in_stack_fffffefc);
  fVar1 = (float)_DAT_00b313b8;
  *(float *)this_00 = (*(float *)(this + 0x50) - *(float *)this_00) * fVar1;
  *(float *)(this + 0x24) = (*(float *)(this + 0x54) - *(float *)(this + 0x24)) * fVar1;
  *(float *)(this + 0x28) = (*(float *)(this + 0x58) - *(float *)(this + 0x28)) * fVar1;
  *(float *)(this + 0x2c) = (*(float *)(this + 0x5c) - *(float *)(this + 0x2c)) * fVar1;
  *(float *)(this + 0x30) = (*(float *)(this + 0x50) + *(float *)(this + 0x30)) * fVar1;
  *(float *)(this + 0x34) = (*(float *)(this + 0x54) + *(float *)(this + 0x34)) * fVar1;
  *(float *)(this + 0x38) = (*(float *)(this + 0x58) + *(float *)(this + 0x38)) * fVar1;
  *(float *)(this + 0x3c) = fVar1 * (*(float *)(this + 0x5c) + *(float *)(this + 0x3c));
  return;
}
}

