// Class implementation: CSceneToyCharacter

// =================================================
// Function: CSceneToyCharacter::AbsorbContact
// =================================================
void __thiscall
CSceneToyCharacter::AbsorbContact
          (CSceneToyCharacter *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2,
          CHmsPhysicalContact *param_3)
{
{
  float fVar1;
  undefined4 uVar2;
  float10 extraout_ST0;
  
  fVar1 = *(float *)(param_1 + 0xc);
  __CIsin();
  if ((*(int *)(this + 0xb8) != 0) || (uVar2 = 0, ABS(fVar1) < (float)extraout_ST0)) {
    uVar2 = 1;
  }
  *(undefined4 *)(this + 0xb8) = uVar2;
  if ((*(int *)(this + 0x8c) != 0) && (*(code **)(this + 0x90) != (code *)0x0)) {
    (**(code **)(this + 0x90))(param_1);
  }
  return;
}
}

// =================================================
// Function: CSceneToyCharacter::AfterContacts
// =================================================
void __thiscall
CSceneToyCharacter::AfterContacts
          (CSceneToyCharacter *this,CCallbackSceneVehicleBallAfterContacts *param_1,
          CHmsItem *param_2)
{
{
  GmVec3 GVar1;
  SCasterCat *pSVar2;
  SPlugFaceCull *pSVar3;
  CPlugTree *pCVar4;
  CGameCtnZone *pCVar5;
  int iVar6;
  ulong uVar7;
  undefined3 extraout_var;
  ulong *puVar8;
  void *pvVar9;
  GmIso4 *unaff_EBP;
  SVolatileTreePointer *unaff_ESI;
  ulong unaff_EDI;
  CMwId *in_stack_ffffffcc;
  GmVec2 *in_stack_ffffffd0;
  float in_stack_ffffffd4;
  CMwTimerAdapter *pCVar10;
  CMwTimerAdapter *pCVar11;
  float fStack_20;
  float fStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
  pSVar3 = (SPlugFaceCull *)(**(code **)(**(int **)pSVar2 + 0x78))();
  pCVar4 = CSceneMobil::GetTree((CSceneMobil *)this,unaff_ESI);
  GmBoxAligned::SetMult(&uStack_10,(SPlugFaceCull *)(pCVar4 + 0x34),pSVar3,unaff_EBP);
  uStack_18 = uStack_c;
  uStack_10 = uStack_4;
  *(undefined4 *)(this + 0xc0) = 0;
  pCVar11 = (CMwTimerAdapter *)(ABS((float)param_1) + fStack_8);
  pCVar10 = (CMwTimerAdapter *)(fStack_8 - ABS((float)param_1));
  pCVar5 = CHmsItem::GetZone(*(CHmsItem **)(this + 0x28),(CGameCtnCollection *)0x0,in_stack_ffffffcc
                            );
  iVar6 = (**(code **)(*(int *)pCVar5 + 0xa8))();
  fStack_1c = fStack_14;
  uStack_18 = uStack_c;
  uVar7 = GmMap2<unsigned_char>::IsInside
                    ((void *)(iVar6 + 0x154),(GmRectAligned *)&fStack_1c,in_stack_ffffffd0);
  if (((uVar7 != 0) || (*(char *)(iVar6 + 0x16c) != '\x01')) ||
     (*(float *)(iVar6 + 0x178) <= fStack_20)) {
    if ((*(float *)(iVar6 + 0x17c) < fStack_1c) && (fStack_20 < *(float *)(iVar6 + 0x178))) {
      uStack_18 = uStack_10;
      fStack_14 = fStack_8;
      GVar1 = GmMap2<unsigned_char>::GetValue
                        ((void *)(iVar6 + 0x154),(CFuncColorGradient *)&uStack_18,in_stack_ffffffd4)
      ;
      if (*(char *)CONCAT31(extraout_var,GVar1) == '\x01') {
        *(undefined4 *)(this + 0xc0) = 1;
      }
    }
  }
  else {
    *(undefined4 *)(this + 0xc0) = 1;
  }
  if (*(int *)(this + 0xb8) == 0) {
    pvVar9 = *(void **)(DAT_00d731e0 + 0x14);
    if (pvVar9 == (void *)0x0) {
      pvVar9 = (void *)(DAT_00d731e0 + 0xa0);
    }
    puVar8 = CMwTimerAdapter::GetTickTime(pvVar9,pCVar10);
    uVar7 = *puVar8;
    if (*(int *)(this + 0xc4) == -1) {
      *(ulong *)(this + 0xc4) = uVar7;
    }
    if (uVar7 - *(int *)(this + 0xc4) < 100) {
      SetIsOnGround(this,(CSceneToyCharacter *)0x1,(int)pCVar11);
    }
    else {
      SetIsOnGround(this,(CSceneToyCharacter *)0x0,(int)pCVar11);
    }
  }
  else {
    SetIsOnGround(this,(CSceneToyCharacter *)0x1,(int)pCVar10);
    *(undefined4 *)(this + 0xc4) = 0xffffffff;
  }
  pvVar9 = *(void **)(DAT_00d731e0 + 0x14);
  if (pvVar9 == (void *)0x0) {
    pvVar9 = (void *)(DAT_00d731e0 + 0xa0);
  }
  puVar8 = CMwTimerAdapter::GetTickTime(pvVar9,pCVar11);
  if (((*(int *)(this + 200) != 0) && (*(int *)(this + 0xbc) != 0)) &&
     (200 < *puVar8 - *(int *)(this + 0xcc))) {
    *(undefined4 *)(this + 200) = 0;
    *(undefined4 *)(this + 0xcc) = 0xffffffff;
  }
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  return;
}
}

// =================================================
// Function: CSceneToyCharacter::ComputeForces
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneToyCharacter::ComputeForces
          (CSceneToyCharacter *this,CCallbackSceneToyBroomStickComputeForces *param_1,
          CHmsItem *param_2,float param_3)
{
{
  float fVar1;
  int iVar2;
  ulong *puVar3;
  void *this_00;
  GmVec3 *unaff_ESI;
  CHmsCorpus *unaff_EDI;
  CSceneToyCharacter *pCVar4;
  undefined8 uStack_10;
  float fStack_8;
  float fStack_4;
  
  iVar2 = (**(code **)(*(int *)this + 0x178))();
  if (_DAT_00ba3b14 <= ABS(*(float *)(this + 0x9c))) {
    GmQuat::SetYawPitchRoll(&uStack_10,*(GmQuat **)(this + 0x9c),0.0,0.0,(float)unaff_EDI);
    unaff_EDI = (CHmsCorpus *)((int)&uStack_10 + 4);
    CHmsItem::RotateOf(*(CHmsItem **)(this + 0x28),unaff_EDI,(GmMat3 *)unaff_ESI);
    *(undefined4 *)(this + 0x9c) = 0;
  }
  if ((_DAT_00ba3b14 <= ABS(*(float *)(this + 0x94))) ||
     (_DAT_00ba3b14 <= ABS(*(float *)(this + 0x98)))) {
    CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)&uStack_10,(GmVec3 *)unaff_EDI)
    ;
    if (*(int *)(this + 0xbc) == 0) {
      if (*(int *)(this + 200) == 0) goto LAB_007ff71a;
      this_00 = *(void **)(DAT_00d731e0 + 0x14);
      if (this_00 == (void *)0x0) {
        this_00 = (void *)(DAT_00d731e0 + 0xa0);
      }
      pCVar4 = (CSceneToyCharacter *)0x7ff670;
      puVar3 = CMwTimerAdapter::GetTickTime(this_00,(CMwTimerAdapter *)unaff_ESI);
      fVar1 = (float)*(int *)(iVar2 + 0x50);
      if (*(int *)(iVar2 + 0x50) < 0) {
        fVar1 = fVar1 + _DAT_00c418d0;
      }
      uStack_10 = (longlong)ROUND(fVar1 * *(float *)(this + 0x78));
      if (*puVar3 < (uint)((int)uStack_10 + *(int *)(this + 0xc4))) {
        *(float *)(this + 0xac) = param_3 * *(float *)(this + 0xac);
        *(float *)(this + 0xb0) = *(float *)(this + 0xb0) * param_3;
        *(float *)(this + 0xb4) = param_3 * *(float *)(this + 0xb4);
        fStack_8 = *(float *)(this + 0xac) + fStack_8;
        fStack_4 = *(float *)(this + 0xb0) + fStack_4;
      }
      unaff_ESI = (GmVec3 *)&fStack_8;
    }
    else {
      pCVar4 = this + 0xa0;
      *(float *)(this + 0xa4) = fStack_8;
    }
    CHmsItem::SetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)pCVar4,unaff_ESI);
  }
LAB_007ff71a:
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  return;
}
}

// =================================================
// Function: CSceneToyCharacter::SetIsOnGround
// =================================================
void __thiscall
CSceneToyCharacter::SetIsOnGround(CSceneToyCharacter *this,CSceneToyCharacter *param_1,int param_2)
{
{
  int iVar1;
  
  *(CSceneToyCharacter **)(this + 0xbc) = param_1;
  iVar1 = (**(code **)(*(int *)this + 0x178))();
  if (*(int *)(this + 0xbc) != 0) {
    *(undefined4 *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x40) = *(undefined4 *)(iVar1 + 0x20);
    return;
  }
  *(undefined4 *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x40) = *(undefined4 *)(iVar1 + 0x1c);
  return;
}
}

// =================================================
// Function: CSceneToyCharacter::TuningsSet
// =================================================
void __thiscall
CSceneToyCharacter::TuningsSet
          (CSceneToyCharacter *this,CSceneToyCharacter *param_1,CSceneToyCharacterTunings *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CSceneToyCharacter **)(this + 0x80)) {
    if (param_1 != (CSceneToyCharacter *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x80) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x80),unaff_ESI);
    }
    *(CSceneToyCharacter **)(this + 0x80) = param_1;
  }
  return;
}
}

