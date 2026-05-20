// Class implementation: CSceneVehicleGlider

// =================================================
// Function: CSceneVehicleGlider::ComputeForces
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleGlider::ComputeForces
          (CSceneVehicleGlider *this,CCallbackSceneToyBroomStickComputeForces *param_1,
          CHmsItem *param_2,float param_3)
{
{
  bool bVar1;
  float fVar2;
  float fVar3;
  SCasterCat *pSVar4;
  GmMat3 *pGVar5;
  ulong unaff_EBX;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  float10 fVar6;
  float unaff_retaddr;
  GmVec3 *pGStack00000010;
  float fStack00000014;
  float fStack00000018;
  GmMat3 *in_stack_ffffff94;
  CHmsItem *pCVar7;
  GmVec3 *in_stack_ffffff9c;
  GmVec3 *in_stack_ffffffa0;
  GmVec3 *pGVar8;
  float local_54;
  GmVec3 *local_50;
  float local_4c;
  float local_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  GmVec3 *pGStack_24;
  float fStack_20;
  GmVec3 *pGStack_1c;
  float fStack_18;
  CHmsItem local_14 [4];
  float fStack_10;
  float afStack_c [3];
  
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)&local_54,unaff_EDI);
  local_54 = local_48;
  bVar1 = true;
  pCVar7 = (CHmsItem *)
           (local_48 * local_48 + local_4c * local_4c + (float)local_50 * (float)local_50);
  pGVar8 = local_50;
  if (_DAT_00ba4dd8 < (float)pCVar7) {
    if ((float)pCVar7 <= _DAT_00d0bf78) {
      bVar1 = false;
    }
    else {
      fVar6 = (float10)func_0x009c1b40();
      bVar1 = false;
      pCVar7 = (CHmsItem *)(1.0 / (float)fVar6);
      local_54 = (float)pCVar7 * local_54;
      pGVar8 = (GmVec3 *)((float)pCVar7 * (float)local_50);
    }
  }
  CHmsItem::GetAngularSpeed(*(CHmsItem **)(this + 0x28),local_14,unaff_ESI);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX);
  pGVar5 = (GmMat3 *)(**(code **)(**(int **)pSVar4 + 0x78))();
  if (!bVar1) {
    fVar2 = local_54 * 0.0;
    fStack_20 = ABS((float)local_50 * 0.0 + fVar2 + local_4c) * *(float *)(this + 0x410) *
                *(float *)(this + 0x40c) * *(float *)(this + 0x420) * ABS(fStack_40);
    in_stack_ffffffa0 = (GmVec3 *)(fStack_20 * 0.0);
    pGStack_24 = in_stack_ffffffa0;
    pGStack_1c = in_stack_ffffffa0;
    CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pGStack_24,
                       (GmVec3 *)in_stack_ffffff94,(GmVec3 *)pCVar7);
    pCVar7 = (CHmsItem *)&fStack_34;
    fVar3 = (float)_DAT_00b55920;
    pGVar8 = SUB84((double)fVar2,0);
    fStack_2c = (ABS(fStack_44 * (float)_PTR_00b2c178 +
                     local_48 + (float)(double)CONCAT44(local_50,local_54)) *
                 *(float *)(this + 0x410) + *(float *)(this + 0x418)) * *(float *)(this + 0x414) *
                *(float *)(this + 0x420) * ABS(fStack_3c);
    fStack_34 = fStack_2c * local_4c * fVar3;
    fStack_30 = local_48 * fVar3 * fStack_2c;
    fStack_2c = fStack_2c * fStack_44 * fVar3;
    in_stack_ffffff94 = (GmMat3 *)0x807fbc;
    CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),pCVar7,in_stack_ffffff9c,in_stack_ffffffa0);
  }
  fStack_30 = 0.0;
  fStack_2c = -*(float *)(this + 0x424) * *(float *)(this + 0x41c);
  fStack_28 = 0.0;
  GmVec3::MultTranspose(&fStack_30,pGVar5,in_stack_ffffff94);
  CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&fStack_2c,(GmVec3 *)pCVar7,
                     in_stack_ffffff9c);
  fStack_30 = -*(float *)(this + 0x400) * unaff_retaddr;
  fStack_18 = (*(float *)(this + 0x2e0) - *(float *)(this + 0x2e4)) * *(float *)(this + 0x3fc);
  afStack_c[0] = fStack_18 + fStack_30;
  local_54 = 0.0;
  afStack_c[1] = 0.0;
  afStack_c[2] = 0.0;
  CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)afStack_c,in_stack_ffffffa0);
  fStack_28 = -*(float *)(this + 0x408) * (float)param_2;
  pGStack_24 = (GmVec3 *)(-*(float *)(this + 0x3f8) * param_3);
  fStack_10 = -*(float *)(this + 0x2e8) * *(float *)(this + 0x404);
  afStack_c[0] = *(float *)(this + 0x3f4) * *(float *)(this + 0x2e8);
  pGStack00000010 = local_50;
  fStack00000014 = fStack_10 + fStack_28;
  fStack00000018 = afStack_c[0] + (float)pGStack_24;
  CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0x00000010,pGVar8);
  return;
}
}

