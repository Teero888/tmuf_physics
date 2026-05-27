// Class implementation: CSceneVehicleCar

// =================================================
// Function: CSceneVehicleCar::AbsorbContact
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::AbsorbContact
          (CSceneVehicleCar *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2,
          CHmsPhysicalContact *param_3)
{
{
  GmVec3 *pGVar1;
  CSceneMobilAbsorbContact *pCVar2;
  int iVar3;
  CSceneMobilAbsorbContact *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  ulong unaff_EBX;
  CPlugTree *unaff_EBP;
  CHmsPhysicalContact *unaff_ESI;
  SSimulationWheel *unaff_EDI;
  float10 fVar7;
  float fVar8;
  float in_stack_00000010;
  float fStack00000018;
  ulong in_stack_ffffffd0;
  GmVec3 *in_stack_ffffffd4;
  GmMat3 *local_1c;
  float fVar9;
  float fStack_4;
  
  pCVar4 = param_1;
  if ((*(short *)(param_1 + 0x48) == 0xd) || (*(short *)(param_1 + 0x48) == 0x17)) {
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    return;
  }
  *(undefined4 *)(this + 0x5d4) = 1;
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           GetWheelFromSurfaceTree(this,*(CSceneVehicleCar **)(param_1 + 4),unaff_EBP);
  param_2 = (CHmsItem *)
            ABS(*(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x2c) +
                *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x24) +
                *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x28));
  if ((pCVar5 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) ||
     (*(float *)(param_1 + 0x10) <= (float)_DAT_00b43310)) {
    *(float *)(this + 0x678) = *(float *)(this + 0x678) + (float)param_2;
  }
  else {
    pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (this + 0x2e8,pCVar5,unaff_EBX);
    if (*(int *)(pSVar6 + 4) == 0) {
      *(float *)(this + 0x674) = *(float *)(this + 0x674) + (float)param_3;
    }
    else {
      *(float *)(this + 0x670) = (float)param_3 + *(float *)(this + 0x670);
    }
  }
  if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    this[0x201] = *(CSceneVehicleCar *)(param_1 + 0x48);
    pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (this + 0x2e8,pCVar5,(ulong)param_1);
    WheelAbsorbContact(this,(CSceneVehicleCar *)pSVar6,unaff_EDI,unaff_ESI);
    *(int *)(this + 0x67c) = *(int *)(this + 0x67c) + 1;
    return;
  }
  if ((*(float *)(param_1 + 0x10) < _DAT_00b66910) &&
     (pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)unaff_EDI),
     *(int *)(*(int *)pSVar6 + 0x354) == 5)) {
    in_stack_00000010 =
         *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x38) +
         *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x30) +
         *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x34);
    *(float *)(param_1 + 0x30) = in_stack_00000010 * *(float *)(param_1 + 0xc);
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x10) * in_stack_00000010;
    *(float *)(param_1 + 0x38) = in_stack_00000010 * *(float *)(param_1 + 0x14);
  }
  pGVar1 = (GmVec3 *)(param_1 + 0x18);
  *(float *)(this + 0x684) = *(float *)(this + 0x684) + *(float *)pGVar1;
  *(float *)(this + 0x688) = *(float *)(param_1 + 0x1c) + *(float *)(this + 0x688);
  *(float *)(this + 0x68c) = *(float *)(param_1 + 0x20) + *(float *)(this + 0x68c);
  *(float *)(this + 0x690) = *(float *)(param_1 + 0xc) + *(float *)(this + 0x690);
  *(float *)(this + 0x694) = *(float *)(param_1 + 0x10) + *(float *)(this + 0x694);
  *(float *)(this + 0x698) = *(float *)(param_1 + 0x14) + *(float *)(this + 0x698);
  *(int *)(this + 0x680) = *(int *)(this + 0x680) + 1;
  *(undefined4 *)(this + 0x5d8) = 1;
  iVar3 = *(int *)(this + 100);
  this[0x200] = *(CSceneVehicleCar *)(param_1 + 0x48);
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar3 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),
                      (ulong)unaff_EDI);
  if (*(int *)(*(int *)pSVar6 + 0x350) == 2) {
    in_stack_00000010 =
         *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x2c) +
         *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x24) +
         *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x28);
    if (in_stack_00000010 < _DAT_00c418e0) {
      if (*(short *)(param_1 + 0x48) == 4) {
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  ((void *)(iVar3 + 0x14),
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),
                   (ulong)unaff_ESI);
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar3 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),
                            in_stack_ffffffd0);
        fStack00000018 = *(float *)(*(int *)pSVar6 + 0x174);
      }
      else {
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  ((void *)(iVar3 + 0x14),
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),
                   (ulong)unaff_ESI);
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar3 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),
                            in_stack_ffffffd0);
        fStack00000018 = *(float *)(*(int *)pSVar6 + 0x170);
      }
      pCVar2 = param_1 + 0x24;
      in_stack_00000010 =
           *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x14) +
           *(float *)pCVar2 * *(float *)(param_1 + 0xc) +
           *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x10);
      param_2 = (CHmsItem *)(in_stack_00000010 * *(float *)(param_1 + 0xc));
      param_3 = (CHmsPhysicalContact *)(*(float *)(param_1 + 0x10) * in_stack_00000010);
      in_stack_00000010 = in_stack_00000010 * *(float *)(param_1 + 0x14);
      fStack_4 = *(float *)pCVar2 - (float)param_2;
      fVar8 = *(float *)(param_1 + 0x28) - (float)param_3;
      param_1 = (CSceneMobilAbsorbContact *)(*(float *)(param_1 + 0x2c) - in_stack_00000010);
      fVar7 = (float10)func_0x009c1b40();
      fVar9 = (float)fVar7;
      fVar7 = (float10)func_0x009c1b40();
      if (fVar9 * fStack00000018 < (float)fVar7) {
        fVar9 = (fVar9 * fStack00000018) / (float)fVar7;
        fStack_4 = fVar9 * fStack_4;
        fVar8 = fVar8 * fVar9;
        param_1 = (CSceneMobilAbsorbContact *)(fVar9 * (float)param_1);
      }
      fStack00000018 =
           -((float)param_1 + in_stack_00000010) * -((float)param_1 + in_stack_00000010) +
           -(fStack_4 + (float)param_2) * -(fStack_4 + (float)param_2) +
           -(fVar8 + (float)param_3) * -(fVar8 + (float)param_3);
      fVar7 = (float10)func_0x009c1b40();
      if (_DAT_00b9ef4c < (float)fVar7) {
        fStack00000018 = 1.0 / (float)fVar7;
        iVar3 = *(int *)(*(int *)(this + 0x28) + 0x14);
        param_2 = (CHmsItem *)(*(float *)pGVar1 - *(float *)(iVar3 + 0x50));
        param_3 = (CHmsPhysicalContact *)(*(float *)(pCVar4 + 0x1c) - *(float *)(iVar3 + 0x54));
        in_stack_00000010 = *(float *)(pCVar4 + 0x20) - *(float *)(iVar3 + 0x58);
        SDynaMath::ComputeImpulse
                  (&stack0xfffffff0,*(CSceneVehicleSpeedBoat **)(iVar3 + 0x18),(float)(iVar3 + 0x1c)
                   ,local_1c,(float)pCVar2,(GmVec3 *)&stack0xfffffff0,(GmVec3 *)&param_2,
                   (GmVec3 *)&fStack_4,in_stack_ffffffd4);
        AddVehicleImpulse(this,(CSceneVehicleCar *)&stack0x0000001c,pGVar1);
        *(undefined4 *)(pCVar4 + 0x3c) = 0;
        return;
      }
    }
    *(undefined4 *)(pCVar4 + 0x3c) = 0;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::AddStateForPrediction
// =================================================
void __thiscall
CSceneVehicleCar::AddStateForPrediction
          (CSceneVehicleCar *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3
          ,ulong param_4)
{
{
  ulong uVar1;
  int *piVar2;
  uint uVar3;
  CClassicBufferMemory *unaff_retaddr;
  ulong uVar4;
  undefined1 auStack_28 [36];
  CSceneToyBoat *pCStack_4;
  
  piVar2 = (int *)(**(code **)(*(int *)this + 8))();
  uVar1 = param_3;
  uVar4 = param_3;
  uVar3 = (**(code **)(*piVar2 + 4))(param_3,auStack_28);
  CHmsItem::AddStateForPrediction
            (*(CHmsItem **)(this + 0x28),pCStack_4,unaff_retaddr,uVar3 & 0xff,uVar4);
  if (uVar1 == 6) {
    (**(code **)(*(int *)pCStack_4 + 4))(&param_2,2);
    return;
  }
  if (uVar1 == 9) {
    (**(code **)(*(int *)pCStack_4 + 4))(auStack_28,0x23);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::AddVehicleCentralForce
// =================================================
void __thiscall
CSceneVehicleCar::AddVehicleCentralForce
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2)
{
{
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  
  CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)param_1,unaff_EDI,unaff_ESI);
  *(float *)(this + 0x818) = *(float *)(this + 0x818) + *(float *)param_1;
  *(float *)(this + 0x81c) = *(float *)(param_1 + 4) + *(float *)(this + 0x81c);
  *(float *)(this + 0x820) = *(float *)(param_1 + 8) + *(float *)(this + 0x820);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::AddVehicleForce
// =================================================
void __thiscall
CSceneVehicleCar::AddVehicleForce
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  GmVec3 *unaff_EDI;
  
  CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)param_1,param_2,unaff_EDI);
  *(float *)(this + 0x818) = *(float *)(this + 0x818) + *(float *)param_1;
  *(float *)(this + 0x81c) = *(float *)(param_1 + 4) + *(float *)(this + 0x81c);
  *(float *)(this + 0x820) = *(float *)(param_1 + 8) + *(float *)(this + 0x820);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::AddVehicleImpulse
// =================================================
void __thiscall
CSceneVehicleCar::AddVehicleImpulse
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2)
{
{
  GmVec3 *unaff_EDI;
  
  CHmsItem::AddImpulse(*(CHmsItem **)(this + 0x28),(CHmsItem *)param_1,unaff_EDI);
  *(float *)(this + 0x824) = *(float *)(this + 0x824) + *(float *)param_1;
  *(float *)(this + 0x828) = *(float *)(param_1 + 4) + *(float *)(this + 0x828);
  *(float *)(this + 0x82c) = *(float *)(param_1 + 8) + *(float *)(this + 0x82c);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::AddVehicleTorque
// =================================================
void __thiscall
CSceneVehicleCar::AddVehicleTorque(CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2)
{
{
  CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)param_1,param_2);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::AfterContacts
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::AfterContacts
          (CSceneVehicleCar *this,CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2)
{
{
  float fVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  int iVar6;
  int extraout_ECX;
  int extraout_ECX_00;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  GmVec3 *unaff_ESI;
  CSceneVehicleCar *pCVar8;
  float *pfVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CSceneVehicleCar *pCVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float fVar12;
  float fVar13;
  float unaff_retaddr;
  ulong in_stack_ffffffd8;
  ulong in_stack_ffffffdc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_1c;
  ulong local_14;
  uint uStack_10;
  float fStack_8;
  float local_4;
  
  pCVar8 = this + 0x3a0;
  pCVar10 = this + 0x2f8;
  for (iVar6 = 0x2a; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined4 *)pCVar10 = *(undefined4 *)pCVar8;
    pCVar8 = pCVar8 + 4;
    pCVar10 = pCVar10 + 4;
  }
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uVar2 != 0) {
    do {
      pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar7,(ulong)unaff_ESI);
      pCVar7 = pCVar7 + 1;
      pSVar4 = pSVar3 + 0x1d0;
      pSVar3 = pSVar3 + 0x16c;
      for (iVar6 = 0x19; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined4 *)pSVar3 = *(undefined4 *)pSVar4;
        pSVar4 = pSVar4 + 4;
        pSVar3 = pSVar3 + 4;
      }
    } while (pCVar7 < local_1c);
  }
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)&fStack_8,unaff_ESI);
  *(CCallbackSceneVehicleBallAfterContacts **)(this + 0x3a0) = param_1;
  *(float *)(this + 0x3a4) = local_4;
  *(undefined4 *)(this + 0x420) = *(undefined4 *)(this + 0x5b4);
  *(uint *)(this + 0x3b4) = (uint)(*(int *)(this + 0x600) != 0);
  *(undefined4 *)(this + 0x3b8) = *(undefined4 *)(this + 0x5f0);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP);
  pCVar8 = this + 0x3d4;
  pfVar9 = (float *)(*(int *)pSVar4 + 0x18);
  pCVar10 = pCVar8;
  for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(float *)pCVar10 = *pfVar9;
    pfVar9 = pfVar9 + 1;
    pCVar10 = pCVar10 + 4;
  }
  *(undefined4 *)(this + 0x404) = *(undefined4 *)(this + 0xb0);
  *(undefined4 *)(this + 0x408) = *(undefined4 *)(this + 0xb8);
  *(float *)(this + 0x40c) =
       (float)param_1 * *(float *)(this + 0x3d8) + unaff_retaddr * *(float *)pCVar8 +
       (float)param_2 * *(float *)(this + 0x3dc);
  *(float *)(this + 0x410) =
       *(float *)(this + 1000) * (float)param_2 +
       *(float *)(this + 0x3e0) * unaff_retaddr + *(float *)(this + 0x3e4) * (float)param_1;
  *(float *)(this + 0x414) =
       (float)param_2 * *(float *)(this + 0x3f4) +
       *(float *)(this + 0x3f0) * (float)param_1 + *(float *)(this + 0x3ec) * unaff_retaddr;
  *(undefined4 *)(this + 0x3bc) = *(undefined4 *)(this + 0x6a0);
  *(undefined4 *)(this + 0x424) = *(undefined4 *)(this + 0x5d4);
  *(undefined4 *)(this + 0x3c0) = *(undefined4 *)(this + 0x624);
  *(undefined4 *)(this + 0x3a8) = *(undefined4 *)(this + 0x58);
  *(undefined4 *)(this + 0x3b0) = *(undefined4 *)(this + 0x54);
  *(undefined4 *)(this + 0x3ac) = *(undefined4 *)(this + 0x50);
  *(undefined4 *)(this + 0x428) = *(undefined4 *)(this + 0x2e4);
  *(undefined4 *)(this + 0x42c) = *(undefined4 *)(this + 0x748);
  *(undefined4 *)(this + 0x3c4) = *(undefined4 *)(this + 0x21c);
  *(undefined4 *)(this + 0x3c8) = *(undefined4 *)(this + 0x230);
  *(undefined4 *)(this + 0x3cc) = *(undefined4 *)(this + 0x240);
  *(undefined4 *)(this + 0x3d0) = *(undefined4 *)(this + 0x23c);
  if (*(int *)(this + 0x680) == 0) {
    *(undefined4 *)(this + 0x434) = 0;
    *(undefined4 *)(this + 0x438) = 0;
    *(undefined4 *)(this + 0x440) = 0;
  }
  else {
    if (_DAT_00d06a80 <
        *(float *)(this + 0x698) * *(float *)(this + 0x698) +
        *(float *)(this + 0x690) * *(float *)(this + 0x690) +
        *(float *)(this + 0x694) * *(float *)(this + 0x694)) {
      fVar11 = (float10)func_0x009c1b40();
      fVar12 = 1.0 / (float)fVar11;
      *(float *)(this + 0x690) = fVar12 * *(float *)(this + 0x690);
      *(float *)(this + 0x694) = fVar12 * *(float *)(this + 0x694);
      *(float *)(this + 0x698) = fVar12 * *(float *)(this + 0x698);
    }
    *(float *)(this + 0x690) = -*(float *)(this + 0x690);
    *(float *)(this + 0x694) = -*(float *)(this + 0x694);
    *(float *)(this + 0x698) = -*(float *)(this + 0x698);
    fVar12 = (float)*(int *)(this + 0x680);
    if (*(int *)(this + 0x680) < 0) {
      fVar12 = fVar12 + _DAT_00c418d0;
    }
    fVar12 = 1.0 / fVar12;
    *(float *)(this + 0x684) = fVar12 * *(float *)(this + 0x684);
    *(float *)(this + 0x688) = *(float *)(this + 0x688) * fVar12;
    *(float *)(this + 0x68c) = fVar12 * *(float *)(this + 0x68c);
    fStack_8 = *(float *)(this + 0x694);
    uStack_10 = 0;
    if (_DAT_00d06a80 <
        fStack_8 * fStack_8 + *(float *)(this + 0x690) * *(float *)(this + 0x690) + 0.0) {
      fVar11 = (float10)func_0x009c1b40();
      fStack_8 = (1.0 / (float)fVar11) * fStack_8;
    }
    __CIatan2();
    *(float *)(this + 0x440) = ABS((float)extraout_ST0) / (float)_DAT_00b36110;
    fStack_8 = *(float *)(this + 0x694);
    local_4 = *(float *)(this + 0x698);
    if (_DAT_00d06a80 < fStack_8 * fStack_8 + 0.0 + local_4 * local_4) {
      fVar11 = (float10)func_0x009c1b40();
      fStack_8 = (1.0 / (float)fVar11) * fStack_8;
      local_4 = (1.0 / (float)fVar11) * local_4;
    }
    __CIatan2();
    *(float *)(this + 0x438) = ABS((float)extraout_ST0_00) / (float)_DAT_00b36110;
    *(uint *)(this + 0x43c) = (uint)(0.0 < local_4);
    *(undefined4 *)(this + 0x434) = 1;
  }
  *(uint *)(this + 0x430) = (uint)(*(int *)(this + 0x67c) != 0);
  *(undefined4 *)(this + 0x444) = *(undefined4 *)(this + 0x5e4);
  *(undefined4 *)(this + 0x67c) = 0;
  *(undefined4 *)(this + 0x680) = 0;
  *(undefined4 *)(this + 0x68c) = 0;
  *(undefined4 *)(this + 0x688) = 0;
  *(undefined4 *)(this + 0x684) = 0;
  *(undefined4 *)(this + 0x698) = 0;
  *(undefined4 *)(this + 0x694) = 0;
  *(undefined4 *)(this + 0x690) = 0;
  local_14 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EBX);
  if (local_14 != 0) {
    do {
      pSVar5 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          in_stack_ffffffd8);
      *(undefined4 *)(pSVar5 + 0x1d0) = *(undefined4 *)(pSVar5 + 0xb4);
      *(undefined4 *)(pSVar5 + 0x1d4) = *(undefined4 *)(pSVar5 + 0x150);
      pSVar4 = pSVar5 + 0xc0;
      pSVar3 = pSVar5 + 0x200;
      for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined4 *)pSVar3 = *(undefined4 *)pSVar4;
        pSVar4 = pSVar4 + 4;
        pSVar3 = pSVar3 + 4;
      }
      *(undefined4 *)(pSVar5 + 0x1e0) = *(undefined4 *)(pSVar5 + 0x124);
      *(undefined2 *)(pSVar5 + 0x1dc) = *(undefined2 *)(pSVar5 + 0x128);
      *(undefined4 *)(pSVar5 + 0x1d8) = *(undefined4 *)(pSVar5 + 0x154);
      *(undefined4 *)(pSVar5 + 0x1e4) = *(undefined4 *)(pSVar5 + 300);
      *(undefined4 *)(pSVar5 + 500) = *(undefined4 *)(pSVar5 + 100);
      *(undefined4 *)(pSVar5 + 0x1f8) = *(undefined4 *)(pSVar5 + 0x68);
      *(undefined4 *)(pSVar5 + 0x1fc) = *(undefined4 *)(pSVar5 + 0x6c);
      *(float *)(pSVar5 + 0x1f8) = *(float *)(pSVar5 + 0x1f8) - *(float *)(pSVar5 + 8);
      *(float *)(pSVar5 + 0x1e8) =
           *(float *)(this + 0x3dc) * *(float *)(pSVar5 + 0x1fc) +
           *(float *)(pSVar5 + 0x1f8) * *(float *)(this + 0x3d8) +
           *(float *)pCVar8 * *(float *)(pSVar5 + 500) + *(float *)(this + 0x3f8);
      *(float *)(pSVar5 + 0x1ec) =
           *(float *)(this + 1000) * *(float *)(pSVar5 + 0x1fc) +
           *(float *)(this + 0x3e0) * *(float *)(pSVar5 + 500) +
           *(float *)(pSVar5 + 0x1f8) * *(float *)(this + 0x3e4) + *(float *)(this + 0x3fc);
      *(float *)(pSVar5 + 0x1f0) =
           *(float *)(this + 0x3f4) * *(float *)(pSVar5 + 0x1fc) +
           *(float *)(this + 0x3ec) * *(float *)(pSVar5 + 500) +
           *(float *)(pSVar5 + 0x1f8) * *(float *)(this + 0x3f0) + *(float *)(this + 0x400);
      *(undefined4 *)(pSVar5 + 0x224) = *(undefined4 *)(pSVar5 + 0x15c);
      *(undefined4 *)(pSVar5 + 0x228) = *(undefined4 *)(pSVar5 + 0x160);
      *(undefined4 *)(pSVar5 + 0x22c) = *(undefined4 *)(pSVar5 + 0x164);
      *(undefined4 *)(pSVar5 + 0x230) = *(undefined4 *)(pSVar5 + 0x168);
      local_14 = local_14 + 1;
    } while (local_14 < uStack_10);
  }
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x6c,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uint)(byte)this[0x201],
                      in_stack_ffffffd8);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x68) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar4,in_stack_ffffffdc);
  iVar6 = *(int *)pSVar4;
  if (*(int *)(this + 0x5d4) == 0) {
    fVar12 = 0.0;
  }
  else {
    fVar13 = *(float *)(iVar6 + 0x30) * ABS(*(float *)(this + 0x3a0));
    fVar12 = *(float *)(iVar6 + 0x34);
    if (fVar13 <= fVar12) {
      fVar12 = fVar13;
    }
  }
  fStack_8 = ABS(*(float *)(this + 0x3a0)) / *(float *)(iVar6 + 0x3c);
  fVar12 = *(float *)(iVar6 + 0x40) * fVar12;
  fVar13 = _DAT_00b9f1bc;
  if (fVar12 < _DAT_00b9f1bc != (fVar12 == _DAT_00b9f1bc)) {
    fVar13 = fVar12;
  }
  fVar12 = SmoothValue(*(float *)(this + 0x418),fStack_8,_DAT_00b31460);
  *(float *)(extraout_ECX + 0x78) = fVar12;
  fVar13 = SmoothValue(*(float *)(extraout_ECX + 0x7c),fVar13,_DAT_00b9f1b8);
  *(float *)(extraout_ECX_00 + 0x7c) = fVar13;
  if ((1 < *(uint *)(this + 0x1fc)) ||
     ((1 < *(uint *)(this + 0x654) && (*(int *)(this + 0x658) != 0)))) {
    fVar1 = _DAT_00b313ac;
    if (_DAT_00b313ac <= fVar12) {
      fVar1 = fVar12;
    }
    *(float *)(extraout_ECX_00 + 0x78) = fVar1;
    if (1.0 <= fVar13) {
      *(float *)(extraout_ECX_00 + 0x7c) = fVar13;
      return;
    }
    *(undefined4 *)(extraout_ECX_00 + 0x7c) = 0x3f800000;
    return;
  }
  if ((*(uint *)(this + 0x1fc) == 0) &&
     ((*(uint *)(this + 0x654) == 0 || (*(int *)(this + 0x658) == 0)))) {
    return;
  }
  fVar1 = _DAT_00b9f1b4;
  if (_DAT_00b9f1b4 <= fVar12) {
    fVar1 = fVar12;
  }
  *(float *)(extraout_ECX_00 + 0x78) = fVar1;
  if (_DAT_00b9f1b0 <= fVar13) {
    *(float *)(extraout_ECX_00 + 0x7c) = fVar13;
    return;
  }
  *(float *)(extraout_ECX_00 + 0x7c) = _DAT_00b9f1b0;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ApplyFrictionForces
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::ApplyFrictionForces
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  SCasterCat *pSVar4;
  int iVar5;
  ulong *puVar6;
  void *this_00;
  CSceneVehicleCar *unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  float10 fVar7;
  float *in_stack_0000000c;
  float fStack00000010;
  float in_stack_00000014;
  float fStack00000018;
  CSceneVehicleCarTuning *in_stack_0000001c;
  float fStack00000020;
  ulong uVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  GmVec3 *pGVar10;
  float in_stack_ffffffe4;
  GmVec3 *in_stack_ffffffe8;
  float fVar11;
  float in_stack_ffffffec;
  float fVar12;
  GmVec3 *in_stack_fffffff0;
  
  iVar1 = *(int *)(this + 100);
  pCVar9 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
  uVar8 = 0x7bed27;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),pCVar9,unaff_ESI);
  if (*(int *)(*(int *)pSVar4 + 0x354) != 4) {
    pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7bed42;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_EBP
                       );
    if (*(int *)(*(int *)pSVar4 + 0x354) != 5) goto LAB_007bed65;
  }
  if ((*(int *)(this + 0x5e4) != 0) && (iVar5 = IsGroundContact(this,unaff_EBX), iVar5 == 0)) {
    return;
  }
LAB_007bed65:
  pfVar3 = in_stack_0000000c;
  if (*(int *)(this + 0x5c4) == 0) {
    fVar12 = *(float *)(this + 0x50);
  }
  else {
    fVar12 = *(float *)(this + 0x54);
  }
  if ((fVar12 < _DAT_00b9ef4c) || (*(int *)(this + 0x60c) != 0)) {
    in_stack_fffffff0 = (GmVec3 *)*in_stack_0000000c;
    in_stack_0000000c =
         (float *)(in_stack_0000000c[2] * in_stack_0000000c[2] +
                  (float)in_stack_fffffff0 * (float)in_stack_fffffff0 +
                  in_stack_0000000c[1] * in_stack_0000000c[1]);
    if (_DAT_00d06a80 < (float)in_stack_0000000c) {
      pGVar10 = (GmVec3 *)0x7bedf7;
      fVar7 = (float10)func_0x009c1b40();
      fVar12 = 1.0 / (float)fVar7;
      in_stack_ffffffe4 = fVar12 * in_stack_ffffffe4;
      fVar11 = (float)in_stack_ffffffe8 * fVar12;
      fVar12 = fVar12 * in_stack_ffffffec;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),uVar8);
      param_1 = (CSceneVehicleCar *)-*(float *)(*(int *)pSVar4 + 0x58);
      in_stack_ffffffe8 = (GmVec3 *)((float)param_1 * fVar11);
      in_stack_ffffffec = fVar12 * (float)param_1;
      in_stack_fffffff0 = (GmVec3 *)((float)param_1 * (float)in_stack_fffffff0);
      if (*(int *)(this + 0x60c) == 0) {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                            (ulong)pCVar9);
        param_2 = (GmVec3 *)-*(float *)(*(int *)pSVar4 + 0x5c);
        in_stack_ffffffec = (float)param_2 * *pfVar3 + in_stack_ffffffec;
        in_stack_fffffff0 = (GmVec3 *)(pfVar3[1] * (float)param_2 + (float)in_stack_fffffff0);
      }
      AddVehicleCentralForce(this,(CSceneVehicleCar *)&stack0xffffffec,pGVar10);
    }
  }
  iVar1 = *(int *)(this + 100);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_EDI);
  if (*(int *)(*(int *)pSVar4 + 0x354) < 4) {
    if (*(int *)(this + 0x5dc) != 0) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          (ulong)unaff_EBX);
      fStack00000018 =
           CSceneVehicleCarTuning::GetLateralContactSlowDownFromSpeed
                     (*(CSceneVehicleCarTuning **)pSVar4,(CSceneVehicleCarTuning *)pfVar3[2],
                      in_stack_ffffffe4);
      fStack00000018 = -fStack00000018;
      param_2 = (GmVec3 *)(fStack00000018 * *pfVar3);
      in_stack_0000000c = (float *)(pfVar3[1] * fStack00000018);
      fStack00000010 = fStack00000018 * pfVar3[2];
      AddVehicleCentralForce(this,(CSceneVehicleCar *)&param_2,in_stack_ffffffe8);
      return;
    }
  }
  else {
    this_00 = *(void **)(DAT_00d731e0 + 0x14);
    if (this_00 == (void *)0x0) {
      this_00 = (void *)(DAT_00d731e0 + 0xa0);
    }
    puVar6 = CMwTimerAdapter::GetTickTime(this_00,(CMwTimerAdapter *)unaff_EBX);
    uVar2 = *puVar6;
    if (*(int *)(this + 0x5dc) != 0) {
      *(uint *)(this + 0x5e0) = uVar2;
    }
    if (*(uint *)(this + 0x5e0) <= uVar2) {
      iVar1 = *(int *)(this + 100);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          (ulong)in_stack_ffffffe4);
      if (uVar2 - *(int *)(this + 0x5e0) < *(uint *)(*(int *)pSVar4 + 0x1e8)) {
        fStack00000018 = pfVar3[1] * pfVar3[1] + *pfVar3 * *pfVar3 + pfVar3[2] * pfVar3[2];
        fVar7 = (float10)func_0x009c1b40();
        fStack00000018 = (float)fVar7;
        if (_DAT_00b9ef4c < fStack00000018) {
          fStack00000010 = 1.0 / fStack00000018;
          param_2 = (GmVec3 *)(fStack00000010 * *pfVar3);
          in_stack_0000000c = (float *)(pfVar3[1] * fStack00000010);
          fStack00000010 = fStack00000010 * pfVar3[2];
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar1 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                              (ulong)in_stack_ffffffe8);
          fStack00000020 =
               CSceneVehicleCarTuning::M5GetLateralContactSlowDownFromSpeed
                         (*(CSceneVehicleCarTuning **)pSVar4,in_stack_0000001c,in_stack_ffffffec);
          fStack00000020 = -fStack00000020;
          param_1 = (CSceneVehicleCar *)(fStack00000020 * fStack00000010);
          param_2 = (GmVec3 *)(in_stack_00000014 * fStack00000020);
          in_stack_0000000c = (float *)(fStack00000020 * fStack00000018);
          AddVehicleCentralForce(this,(CSceneVehicleCar *)&param_1,in_stack_fffffff0);
          return;
        }
      }
    }
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ApplyWaterForces
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CSceneVehicleCar::ApplyWaterForces(CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  GmVec3 GVar2;
  SCasterCat *pSVar3;
  GmMat3 *pGVar4;
  CGameCtnZone *pCVar5;
  int iVar6;
  ulong uVar7;
  undefined3 extraout_var;
  GmVec2 *unaff_EBX;
  CMwId *unaff_EBP;
  GmIso4 *unaff_ESI;
  ulong unaff_EDI;
  float10 fVar8;
  float unaff_retaddr;
  float in_stack_0000000c;
  float in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  float in_stack_0000001c;
  float *in_stack_0000003c;
  float in_stack_ffffff84;
  GmVec3 *in_stack_ffffff88;
  GmIso4 *pGVar9;
  float fVar10;
  float in_stack_ffffff94;
  float fVar11;
  float in_stack_ffffff98;
  GmVec3 **ppGVar12;
  GmMat3 *pGVar13;
  GmVec3 *pGVar14;
  CSceneVehicleCar *in_stack_ffffff9c;
  GmVec3 *pGVar15;
  float fVar16;
  GmMat3 *in_stack_ffffffa8;
  GmVec3 *pGVar17;
  CFuncColorGradient *pCVar18;
  CSceneVehicleCarTuning *in_stack_ffffffb0;
  float fStack_4c;
  GmVec3 *pGStack_48;
  undefined1 auStack_44 [4];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  GmVec3 *pGStack_18;
  float fStack_14;
  float fStack_10;
  GmMat3 *pGStack_c;
  float fStack_8;
  float fStack_4;
  
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
  pGVar4 = (GmMat3 *)(**(code **)(**(int **)pSVar3 + 0x78))();
  GmBoxAligned::SetMult
            (&fStack_14,(SPlugFaceCull *)(this + 0x1dc),(SPlugFaceCull *)pGVar4,unaff_ESI);
  fStack_1c = fStack_10;
  fStack_14 = fStack_8;
  fVar10 = ABS(unaff_retaddr) + (float)pGStack_c;
  pGVar9 = (GmIso4 *)((float)pGStack_c - ABS(unaff_retaddr));
  pCVar5 = CHmsItem::GetZone(*(CHmsItem **)(this + 0x28),(CGameCtnCollection *)0x0,unaff_EBP);
  iVar6 = (**(code **)(*(int *)pCVar5 + 0xa8))();
  uVar7 = GmMap2<unsigned_char>::IsInside
                    ((void *)(iVar6 + 0x154),(GmRectAligned *)&stack0xffffffa0,unaff_EBX);
  fVar11 = in_stack_ffffff94;
  if (((uVar7 != 0) || (*(char *)(iVar6 + 0x16c) != '\x01')) ||
     (pGVar15 = pGStack_18, fVar16 = fStack_10, *(float *)(iVar6 + 0x178) <= in_stack_ffffff94)) {
    if (in_stack_ffffff98 <= *(float *)(iVar6 + 0x17c)) {
      return 0;
    }
    if (*(float *)(iVar6 + 0x178) <= in_stack_ffffff94) {
      return 0;
    }
    in_stack_ffffff94 = in_stack_ffffff98;
    fVar16 = fStack_14;
    in_stack_ffffffa8 = pGStack_c;
    GVar2 = GmMap2<unsigned_char>::GetValue
                      ((void *)(iVar6 + 0x154),(CFuncColorGradient *)&stack0xffffffa4,
                       in_stack_ffffff84);
    pGVar15 = pGStack_18;
    if (*(char *)CONCAT31(extraout_var,GVar2) != '\x01') {
      return 0;
    }
  }
  pGVar14 = (GmVec3 *)(*(float *)(iVar6 + 0x178) - in_stack_ffffff94);
  if ((float)pGVar14 <= _DAT_00b31460) {
    return 0;
  }
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)&fStack_4c,in_stack_ffffff88);
  GmVec3::SetMult(&pGStack_18,(SPlugFaceCull *)&pGStack_48,(SPlugFaceCull *)pGVar4,pGVar9);
  iVar1 = *(int *)(this + 100);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                      (ulong)fVar10);
  pCVar18 = *(CFuncColorGradient **)(*(int *)pSVar3 + 0x208);
  if (((*(int *)(this + 0x5d4) != 0) || ((float)_DAT_00b41ea8 <= fVar16)) ||
     ((in_stack_ffffffa8 = (GmMat3 *)(*(float *)(iVar6 + 0x178) - (float)in_stack_ffffffa8),
      _DAT_00c418e0 <= (float)in_stack_ffffffa8 || (_DAT_00b574fc <= (float)pGStack_c))))
  goto LAB_007c2bef;
  if ((float)in_stack_ffffffb0 <= (float)pCVar18 * (float)pCVar18) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        (ulong)fVar11);
    fStack_4c = *(float *)(*(int *)pSVar3 + 0x20c) * *(float *)(*(int *)pSVar3 + 0x20c);
    if (fStack_34 * fStack_34 + fStack_3c * fStack_3c + fStack_38 * fStack_38 <= fStack_4c)
    goto LAB_007c2bef;
    in_stack_ffffffa8 = (GmMat3 *)0x0;
LAB_007c2b35:
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        (ulong)pGVar14);
    ppGVar12 = &pGStack_48;
    CFuncKeysReal::GetValue(*(CFuncKeysReal **)(*(int *)pSVar3 + 0x210),pCVar18,(float)auStack_44);
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 100) + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                         (*(int *)(this + 100) + 0x24),(ulong)ppGVar12);
    pGVar13 = (GmMat3 *)&pGStack_48;
    CFuncKeysReal::GetValue(*(CFuncKeysReal **)(*(int *)pSVar3 + 0x214),pCVar18,(float)&fStack_4c);
    param_2 = (GmVec3 *)(-(float)in_stack_ffffffb0 * fStack_4);
    GmVec3::MultTranspose(&stack0x00000000,pGVar4,pGVar13);
    CSceneVehicle::WaterSplash
              ((CSceneVehicle *)this,(CSceneVehicle *)&fStack_8,(GmVec3 *)in_stack_ffffff9c);
    in_stack_ffffff9c = (CSceneVehicleCar *)&param_2;
    pGVar14 = (GmVec3 *)0x7c2bde;
    AddVehicleImpulse(this,in_stack_ffffff9c,pGVar15);
  }
  else {
    fVar8 = (float10)func_0x009c1b40();
    fStack_4c = (float)fVar8;
    in_stack_ffffffa8 = (GmMat3 *)(-fStack_4c / fStack_8);
    if (!NAN((float)in_stack_ffffffa8) &&
        0.0 < (float)in_stack_ffffffa8 != ((float)in_stack_ffffffa8 == 0.0)) goto LAB_007c2b35;
  }
  if (0.0 <= (float)in_stack_ffffffa8) {
    return 0;
  }
LAB_007c2bef:
  pGStack_48 = (GmVec3 *)(fStack_34 * fStack_34 + fStack_3c * fStack_3c + fStack_38 * fStack_38);
  fVar8 = (float10)func_0x009c1b40();
  pGVar17 = (GmVec3 *)(float)fVar8;
  param_2 = (GmVec3 *)0x0;
  pGStack_48 = pGVar17;
  if (_DAT_00b9ef4c < (float)pGVar17) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 100) + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                         (*(int *)(this + 100) + 0x24),(ulong)pGVar14);
    pGVar14 = (GmVec3 *)in_stack_ffffffb0;
    in_stack_ffffffb0 = (CSceneVehicleCarTuning *)pGVar14;
    fStack_40 = CSceneVehicleCarTuning::GetWaterFrictionFromSpeed
                          (*(CSceneVehicleCarTuning **)pSVar3,(CSceneVehicleCarTuning *)pGVar14,
                           (float)in_stack_ffffff9c);
    fStack_40 = -fStack_40;
    param_2 = (GmVec3 *)(fStack_40 * fStack_34);
    in_stack_0000000c = fStack_30 * fStack_40;
    in_stack_00000010 = fStack_40 * fStack_2c;
  }
  CHmsItem::GetAngularSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)&fStack_30,pGVar14);
  iVar6 = *(int *)(this + 100);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar6 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar6 + 0x24),
                      (ulong)in_stack_ffffff9c);
  fStack_40 = -*(float *)(*(int *)pSVar3 + 0x21c);
  fStack_10 = fStack_40 * fStack_28;
  pGStack_c = (GmMat3 *)(fStack_24 * fStack_40);
  fStack_8 = fStack_40 * fStack_20;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar6 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar6 + 0x24),
                      (ulong)pGVar15);
  fStack_3c = fStack_20 * fStack_20 + fStack_24 * fStack_24 + fStack_1c * fStack_1c;
  fVar8 = (float10)func_0x009c1b40();
  fVar10 = -(float)fVar8 * *(float *)(*(int *)pSVar3 + 0x220);
  fStack_38 = fStack_20 * fVar10;
  fStack_34 = fVar10 * fStack_1c;
  pGStack_c = (GmMat3 *)(fVar10 * fStack_24 + (float)pGStack_c);
  fStack_8 = fStack_38 + fStack_8;
  fStack_4 = fStack_34 + fStack_4;
  fStack_3c = 0.0;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar6 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar6 + 0x24),
                      (ulong)fVar16);
  fStack_34 = -*(float *)(*(int *)pSVar3 + 0x204);
  fStack_30 = 0.0;
  GmVec3::MultTranspose(&fStack_38,pGVar4,in_stack_ffffffa8);
  fStack_10 = (fStack_34 + in_stack_00000014) - *in_stack_0000003c;
  pGStack_c = (GmMat3 *)((fStack_30 + in_stack_00000018) - in_stack_0000003c[1]);
  fStack_8 = (fStack_2c + in_stack_0000001c) - in_stack_0000003c[2];
  AddVehicleCentralForce(this,(CSceneVehicleCar *)&fStack_10,pGVar17);
  AddVehicleTorque(this,(CSceneVehicleCar *)&stack0x00000000,(GmVec3 *)in_stack_ffffffb0);
  return 1;
}
}

// =================================================
// Function: CSceneVehicleCar::CSceneVehicleCar
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneVehicleCar::CSceneVehicleCar(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  CSceneVehicleCar *this_00;
  GmFrustumIso4 *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  void *in_stack_00000010;
  CSceneVehicleCar *pCVar3;
  CCallback *pCVar4;
  GmFrustumIso4 *pGVar5;
  CCallback *pCVar6;
  GmFrustumIso4 *pGVar7;
  code *pcVar8;
  SEngine *pSVar9;
  code *pcVar10;
  
  pSVar9 = (SEngine *)0xffffffff;
  pGVar7 = (GmFrustumIso4 *)&LAB_00acc9ee;
  pGVar5 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar3 = this;
  CSceneVehicle::CSceneVehicle
            ((CSceneVehicle *)this,(CSceneVehicle *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x2e8,unaff_EDI);
  SVehicleCarState::Reset(this + 0x2f8,unaff_ESI);
  SVehicleCarState::Reset(this + 0x3a0,(GmFrustumIso4 *)pCVar3);
  SVehicleCarState::Reset(this + 0x448,pGVar5);
  SVehicleCarState::Reset(this + 0x4f0,pGVar7);
  SEngine::SEngine(this + 0x59c,pSVar9);
  *(undefined4 *)(this + 0x728) = 0;
  pcVar10 = SPlugGpuLoadFx::~SPlugGpuLoadFx;
  *(undefined4 *)(this + 0x730) = 0;
  pcVar8 = SDynaPart::SDynaPart;
  *(undefined4 *)(this + 0x724) = 0x3f800000;
  pCVar6 = (CCallback *)&DAT_00000004;
  pCVar4 = (CCallback *)&DAT_00000030;
  *(undefined4 *)(this + 0x734) = 0;
  *(undefined4 *)(this + 0x738) = 0;
  *(undefined4 *)(this + 0x718) = 0x3f800000;
  *(undefined4 *)(this + 0x71c) = 1000;
  *(undefined4 *)(this + 0x720) = 1000;
  pCVar3 = this + 0x750;
  *(undefined4 *)(this + 0x72c) = 0;
  _eh_vector_constructor_iterator_
            (pCVar3,0x30,4,SDynaPart::SDynaPart,SPlugGpuLoadFx::~SPlugGpuLoadFx);
  CSceneMobil::EnableAbsorbContactCallback((CSceneMobil *)this,(CSceneMobil *)0x1,(int)pCVar3);
  CHmsItem::CallbackSet(*(CHmsItem **)(this + 0x28),(CHmsItem *)0x3,0xd06a84,pCVar4);
  CHmsItem::CallbackSet(*(CHmsItem **)(this + 0x28),(CHmsItem *)&DAT_00000004,0xd06a88,pCVar6);
  *(uint *)(this + 0x2f4) = *(uint *)(this + 0x2f4) & 0xfffffff7 | 7;
  VehicleBlockSpeedSet(this,(CSceneVehicleCar *)0x1,(int)pcVar8);
  VehicleBlockSpeed2Set(this_00,(CSceneMobil *)0x1,(int)pcVar10);
  *(undefined4 *)(this + 0x840) = 0x3f800000;
  *(undefined4 *)(this + 0x74c) = 1;
  *(undefined4 *)(this + 0x810) = 0;
  *(undefined4 *)(this + 0x814) = _DAT_00b9f20c;
  *(undefined4 *)(this + 0x2e0) = _DAT_00b9f208;
  uVar2 = _DAT_00b36194;
  *(undefined4 *)(this + 0x5cc) = _DAT_00b36194;
  *(undefined4 *)(this + 0x6dc) = 0;
  *(undefined4 *)(this + 0x6d8) = 0;
  *(undefined4 *)(this + 0x6d4) = 0;
  *(undefined4 *)(this + 0x6ec) = 0x3f800000;
  *(undefined4 *)(this + 0x6f0) = _DAT_00b313ac;
  *(undefined4 *)(this + 0x86c) = 0;
  *(undefined4 *)(this + 0x870) = 0;
  *(undefined4 *)(this + 0x874) = 0;
  *(undefined4 *)(this + 0x848) = 0;
  *(undefined4 *)(this + 0x84c) = 0;
  *(undefined4 *)(this + 0x850) = 0;
  *(undefined4 *)(this + 0x854) = 0;
  *(undefined4 *)(this + 0x858) = 0;
  *(undefined4 *)(this + 0x85c) = 0;
  *(undefined4 *)(this + 0x860) = 0;
  *(undefined4 *)(this + 0x864) = 0;
  *(undefined4 *)(this + 0x868) = 0;
  *(undefined4 *)(this + 0x844) = 0;
  *(undefined4 *)(this + 0x1e4) = 0;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1dc) = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x1e8) = _DAT_00b2c060;
  *(undefined4 *)(this + 0x1ec) = uVar1;
  *(undefined4 *)(this + 0x1f0) = uVar1;
  *(undefined4 *)(this + 0x834) = 0;
  *(undefined4 *)(this + 0x838) = 0;
  *(undefined4 *)(this + 0x244) = uVar2;
  *(undefined4 *)(this + 0x83c) = 0;
  *(undefined4 *)(this + 0x24c) = _DAT_00b5a4cc;
  *(undefined4 *)(this + 0x250) = 0x3f800000;
  uVar1 = _DAT_00b2f720;
  *(undefined4 *)(this + 0x214) = _DAT_00b2f720;
  uVar2 = _DAT_00b36acc;
  *(undefined4 *)(this + 0x218) = _DAT_00b36acc;
  *(undefined4 *)(this + 0x22c) = uVar2;
  *(undefined4 *)(this + 0x228) = uVar1;
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::Chunk
// =================================================
void __thiscall
CSceneVehicleCar::Chunk
          (CSceneVehicleCar *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CSceneVehicleCar *this_00;
  int iVar1;
  CFuncSegment *this_01;
  CClassicArchive *this_02;
  CSceneVehicleCar *pCVar2;
  SCasterCat *pSVar3;
  CMwNodRef<class_CGameCamera> *extraout_EAX;
  SCasterCat *pSVar4;
  ulong uVar5;
  SLoadedLight *this_03;
  SLoadedLight *pSVar6;
  CClassicArchive *unaff_EBX;
  void *pvVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CClassicArchive *pCVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CClassicArchive *unaff_EDI;
  CMwId *unaff_retaddr;
  SCasterCat *pSVar11;
  void *in_stack_00000010;
  CMwNod *in_stack_00000014;
  undefined1 in_stack_00000018;
  uint in_stack_00000020;
  undefined1 in_stack_00000024;
  int in_stack_ffffff7c;
  CClassicArchive *in_stack_ffffff80;
  CClassicArchive *in_stack_ffffff84;
  CClassicArchive *pCVar12;
  ulong in_stack_ffffff8c;
  CMwNodRef<class_CGameCamera> *pCVar13;
  CClassicArchive *in_stack_ffffff90;
  ulong uVar14;
  CMwId *in_stack_ffffff94;
  CClassicArchive *pCVar15;
  CClassicArchive *in_stack_ffffff98;
  CClassicArchive *in_stack_ffffff9c;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffa0;
  CFastStringInt *pCVar16;
  CFastCrypt<unsigned_long> *pCVar17;
  CClassicArchive **ppCVar18;
  void *this_04;
  CClassicArchive *pCVar19;
  CClassicArchive *pCVar20;
  CFastStringInt *pCVar21;
  CClassicArchive *pCVar22;
  CClassicArchive *in_stack_ffffffc0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffc4;
  CMwNod *this_05;
  CMwNod *in_stack_ffffffc8;
  CMwId *in_stack_ffffffcc;
  int in_stack_ffffffd0;
  CClassicArchive local_28 [8];
  uint local_20 [2];
  SCasterCat *local_18;
  undefined1 local_14 [4];
  CClassicArchive local_10 [4];
  CClassicArchive *local_c;
  SCasterCat *pSStack_8;
  undefined4 local_4;
  
  this_01 = param_1;
  local_4 = 0xffffffff;
  pSStack_8 = (SCasterCat *)&LAB_00accc1b;
  local_c = ExceptionList;
  pCVar2 = (CSceneVehicleCar *)(DAT_00cca150 ^ (uint)&stack0xffffffb0);
  ExceptionList = &local_c;
  if (param_2 < (CClassicArchive *)0xa02b00c) {
    if (param_2 == (CClassicArchive *)0xa02b00b) {
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x28c),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_01,(CClassicArchive *)(this + 0x298),
                 (CMwNodRef<class_CMwRefBuffer> *)unaff_EDI);
      ExceptionList = pSStack_8;
      return;
    }
    switch(param_2) {
    case (CClassicArchive *)0xa02b000:
      CreateOldStruct(this,pCVar2);
      pCVar19 = param_2;
      pCVar20 = (CClassicArchive *)0x0;
      pCVar17 = (CFastCrypt<unsigned_long> *)0x1;
      CClassicArchive::DoNatural(param_2,(CClassicArchive *)&param_3,(ulong *)0x1,0,(int)unaff_EDI);
      iVar1 = *(int *)(this + 0x60);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar1 + 0x14),unaff_ESI);
      pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                             ((void *)(iVar1 + 0x14),pCVar10,(ulong)pCVar19);
          CMwId::Archive(pSVar4,pCVar17,pCVar20);
          pCVar10 = pCVar10 + 1;
        } while (pCVar10 < pCVar8);
        ExceptionList = pSStack_8;
        return;
      }
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b001:
      CreateOldStruct(this,pCVar2);
      pCVar20 = param_2;
      CClassicArchive::DoNatural
                (param_2,(CClassicArchive *)&stack0xffffffd4,(ulong *)0x1,0,(int)unaff_EDI);
      pvVar7 = (void *)(*(int *)(this + 0x60) + 0x14);
      pCVar21 = (CFastStringInt *)0x0;
      in_stack_00000010 = pvVar7;
      pSVar4 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::operator[]
                         ((void *)(*(int *)(this + 0x60) + 0x20),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)unaff_ESI);
      pCVar19 = (CClassicArchive *)0x7c825c;
      pCVar16 = (CFastStringInt *)CFastBuffer<class_CCrystalFace*>::GetCount(pvVar7,unaff_EBP);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar16 != (CFastStringInt *)0x0) {
        pSVar4 = pSVar4 + 0x24;
        do {
          uVar5 = 0x7c827f;
          pSVar11 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                              (pvVar7,pCVar8,(ulong)pCVar21);
          uVar14 = 0x7c828b;
          pSVar3 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                             (in_stack_ffffffcc,pCVar8,(ulong)pCVar19);
          CMwId::CMwId(&stack0x00000010,(CMwId *)unaff_EBP);
          param_3 = 0;
          CMwId::Archive(&stack0x00000014,(CFastCrypt<unsigned_long> *)pCVar20,unaff_EBX);
          unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x1;
          pCVar19 = (CClassicArchive *)local_20;
          pCVar21 = (CFastStringInt *)0x7c82b8;
          CClassicArchive::DoNatural(pCVar20,pCVar19,(ulong *)0x1,0,(int)in_stack_ffffffc0);
          unaff_EBX = (CClassicArchive *)0x7c82c0;
          in_stack_ffffffc0 = pCVar20;
          CMwId::Archive(pSVar11,(CFastCrypt<unsigned_long> *)pCVar20,
                         (CClassicArchive *)in_stack_ffffffc4);
          if (*(int *)pSVar11 != -1) {
            local_c = (CClassicArchive *)0x0;
            pSStack_8 = (SCasterCat *)PTR_DAT_00bbf7d8;
            in_stack_00000018 = 1;
            CMwId::GetName(pSVar11,(CTrackManiaEditorIconPage *)&local_c);
            in_stack_ffffffc0 = (CClassicArchive *)0x7c82f5;
            SStringParam::SStringParam
                      (&local_4,(SStringParam *)&DAT_00b9f210,(char *)in_stack_ffffffc8);
            in_stack_ffffffc4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c8303;
            CFastString::Concat((CFastString *)&pSStack_8,(CFastStringInt *)&stack0x00000000,
                                (SStringParam *)in_stack_ffffffcc);
            in_stack_ffffffc8 = (CMwNod *)0x7c830f;
            CMwId::SetLocalName(pSVar3,unaff_retaddr,pCVar16);
            in_stack_00000024 = 0;
            pCVar16 = (CFastStringInt *)0x7c831d;
            CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                      (&stack0x00000000,(SHeaderCommunity *)pSVar4);
            in_stack_ffffffcc = unaff_retaddr;
          }
          CClassicArchive::DoBool(pCVar20,(CClassicArchive *)(pSVar11 + 4),(int *)0x1,uVar5);
          CClassicArchive::DoBool(pCVar20,(CClassicArchive *)(pSVar11 + 8),(int *)0x1,uVar14);
          if (*(int *)(pCVar20 + 8) == 0) {
            *(undefined4 *)(pSVar11 + 4) = 1;
          }
          unaff_retaddr = (CMwId *)0xffffffff;
          OnAccessViolation_ConcatToCrashFileName(pCVar21);
          pCVar8 = pCVar8 + 1;
          pvVar7 = (void *)param_3;
        } while (pCVar8 < in_stack_ffffffc4);
        ExceptionList = pSStack_8;
        return;
      }
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b002:
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&local_18,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar2);
      pCVar19 = param_2;
      CFastBuffer<class_CPlugMaterial*>::ArchiveFastBufferNod
                (local_14,(CFastBuffer<class_CPlugMaterial*> *)param_2,unaff_EDI);
      CFastBuffer<class_CMwNod*>::AddRefAll(local_10,(CFastBuffer<class_CMwNod*> *)unaff_ESI);
      CFastBuffer<class_CSystemPackDesc*>::ReleaseAll
                (&local_c,(CFastBuffer<class_CSystemPackDesc*> *)unaff_EBP);
      CClassicArchive::DoNatural
                (pCVar19,(CClassicArchive *)&stack0x00000014,(ulong *)0x1,0,(int)unaff_EBX);
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (&local_4,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffffc0);
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b003:
      param_2 = *(CClassicArchive **)(this + 100);
      (**(code **)(*(int *)param_1 + 4))();
      if (*(int *)(this_01 + 8) == 0) {
        CSceneVehicle::TuningsSet
                  ((CSceneVehicle *)this,(CSceneToyCharacter *)param_3,
                   (CSceneToyCharacterTunings *)unaff_EDI);
        ExceptionList = pSStack_8;
        return;
      }
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b004:
      param_2 = (CClassicArchive *)0x0;
      (**(code **)(*(int *)param_1 + 4))();
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b005:
      ppCVar18 = &param_2;
      param_2 = (CClassicArchive *)0x0;
      uVar5 = 0x7c8420;
      (**(code **)(*(int *)param_1 + 4))();
      local_18 = (SCasterCat *)0x0;
      local_20[1] = 0;
      local_20[0] = 0;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_01,(CClassicArchive *)local_20,(float *)0x1,uVar5);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_01,(CClassicArchive *)&local_18,(float *)0x1,
                 (ulong)ppCVar18);
      CClassicArchive::DoReal((CClassicArchive *)this_01,local_10,(float *)0x1,(ulong)pCVar2);
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b006:
      this_05 = (CMwNod *)0x0;
      param_2 = (CClassicArchive *)0x0;
      local_4 = 5;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffc4,
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_01,(CClassicArchive *)&stack0xffffffc4,
                 (CMwNodRef<class_CMwRefBuffer> *)unaff_EDI);
      pCVar19 = (CClassicArchive *)&stack0x00000010;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_01,pCVar19,(CMwNodRef<class_CMwRefBuffer> *)unaff_ESI);
      param_2 = (CClassicArchive *)CONCAT31(param_2._1_3_,4);
      if (in_stack_00000014 != (CMwNod *)0x0) {
        CMwNod::MwRelease(in_stack_00000014,(CMwNod *)unaff_EBP);
      }
      if (this_05 != (CMwNod *)0x0) {
        CMwNod::MwRelease(this_05,(CMwNod *)pCVar19);
      }
      if (in_stack_ffffffc8 != (CMwNod *)0x0) {
        CMwNod::MwRelease(in_stack_ffffffc8,(CMwNod *)pCVar19);
        ExceptionList = pSStack_8;
        return;
      }
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b007:
      ppCVar18 = &param_2;
      param_2 = (CClassicArchive *)0x0;
      uVar5 = 0x7c84fc;
      (**(code **)(*(int *)param_1 + 4))();
      CClassicArchive::DoReal
                ((CClassicArchive *)this_01,(CClassicArchive *)local_20,(float *)0x1,uVar5);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_01,(CClassicArchive *)&local_18,(float *)0x1,
                 (ulong)ppCVar18);
      CClassicArchive::DoReal((CClassicArchive *)this_01,local_10,(float *)0x1,(ulong)pCVar2);
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b008:
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x68),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      if (*(int *)(this_01 + 8) == 0) {
        CSceneVehicle::BuildVehicleMaterialsRemap((CSceneVehicle *)this,(CSceneVehicle *)unaff_EDI);
        ExceptionList = pSStack_8;
        return;
      }
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b009:
      CreateOldStruct(this,pCVar2);
      pCVar20 = param_2;
      this_04 = (void *)0x1;
      pCVar19 = (CClassicArchive *)&stack0xffffffd4;
      pCVar12 = (CClassicArchive *)0x7c856b;
      CClassicArchive::DoNatural(param_2,pCVar19,(ulong *)0x1,0,(int)unaff_EDI);
      pvVar7 = (void *)(*(int *)(this + 0x60) + 0x14);
      pCVar16 = (CFastStringInt *)0x0;
      uVar14 = 0x7c857f;
      in_stack_00000010 = pvVar7;
      CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::operator[]
                ((void *)(*(int *)(this + 0x60) + 0x20),
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)unaff_ESI);
      uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(pvVar7,unaff_EBP);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (uVar5 != 0) {
        do {
          pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                             (pvVar7,pCVar8,in_stack_ffffff8c);
          pSVar11 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                              (this_04,pCVar8,(ulong)in_stack_ffffff90);
          CMwId::CMwId(local_14,in_stack_ffffff94);
          local_18 = (SCasterCat *)&DAT_00000006;
          CMwId::Archive(local_10,(CFastCrypt<unsigned_long> *)pCVar20,in_stack_ffffff98);
          in_stack_ffffff94 = (CMwId *)0x1;
          in_stack_ffffff90 = (CClassicArchive *)&stack0xffffffbc;
          in_stack_ffffff8c = 0x7c85e5;
          CClassicArchive::DoNatural
                    (pCVar20,in_stack_ffffff90,(ulong *)0x1,0,(int)in_stack_ffffff9c);
          in_stack_ffffff98 = (CClassicArchive *)0x7c85ed;
          CMwId::Archive(pSVar4,(CFastCrypt<unsigned_long> *)pCVar20,pCVar12);
          CMwId::Archive(pSVar11,(CFastCrypt<unsigned_long> *)pCVar20,pCVar19);
          in_stack_ffffff9c = (CClassicArchive *)0x7c8602;
          CClassicArchive::DoBool(pCVar20,(CClassicArchive *)(pSVar4 + 4),(int *)0x1,(ulong)this_04)
          ;
          this_04 = (void *)0x1;
          pCVar19 = (CClassicArchive *)(pSVar4 + 8);
          pCVar12 = (CClassicArchive *)0x7c860f;
          CClassicArchive::DoBool(pCVar20,pCVar19,(int *)0x1,uVar14);
          uVar14 = 0x7c8620;
          OnAccessViolation_ConcatToCrashFileName(pCVar16);
          pCVar8 = pCVar8 + 1;
          pvVar7 = (void *)param_3;
        } while (pCVar8 < in_stack_ffffffc4);
        ExceptionList = pSStack_8;
        return;
      }
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b00a:
      CClassicArchive::DoReal
                ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(float *)0x1,(ulong)pCVar2);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_01,(CClassicArchive *)&param_3,(float *)0x1,
                 (ulong)unaff_EDI);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_01,(CClassicArchive *)(this + 0x2e0),(float *)0x1,
                 (ulong)unaff_ESI);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_01,(CClassicArchive *)(this + 0x5cc),(float *)0x1,
                 (ulong)unaff_EBP);
      ExceptionList = pSStack_8;
      return;
    }
  }
  else if (param_2 < (CClassicArchive *)0xa02b012) {
    if (param_2 == (CClassicArchive *)0xa02b011) {
      ExceptionList = pSStack_8;
      return;
    }
    switch(param_2) {
    case (CClassicArchive *)0xa02b00c:
      CClassicArchive::DoReal
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x2e0),(float *)0x1,
                 (ulong)pCVar2);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_01,(CClassicArchive *)(this + 0x5cc),(float *)0x1,
                 (ulong)unaff_EDI);
      GmBoxAligned::ArchiveABox(this + 0x1dc,(GmBoxAligned *)this_01,(CClassicArchive *)unaff_ESI);
      ExceptionList = pSStack_8;
      return;
    case (CClassicArchive *)0xa02b00d:
    case (CClassicArchive *)0xa02b00e:
    case (CClassicArchive *)0xa02b00f:
    case (CClassicArchive *)0xa02b010:
      ExceptionList = pSStack_8;
      return;
    }
  }
  else if (param_2 < (CClassicArchive *)0xa02b015) {
    if (param_2 == (CClassicArchive *)0xa02b014) {
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x60),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      ExceptionList = pSStack_8;
      return;
    }
    if (param_2 == (CClassicArchive *)0xa02b012) {
      ExceptionList = pSStack_8;
      return;
    }
    if (param_2 == (CClassicArchive *)0xa02b013) {
      pCVar19 = (CClassicArchive *)&DAT_00000050;
      pCVar16 = (CFastStringInt *)0x7c8723;
      param_2 = operator_new(0x50);
      local_4 = 7;
      if (param_2 == (CClassicArchive *)0x0) {
        pCVar13 = (CMwNodRef<class_CGameCamera> *)0x0;
      }
      else {
        pCVar19 = (CClassicArchive *)0x7c873d;
        CSceneVehicleStruct::CSceneVehicleStruct
                  ((CSceneVehicleStruct *)param_2,(CSceneVehicleStruct *)pCVar2);
        pCVar13 = extraout_EAX;
      }
      this_00 = this + 0x60;
      local_20[0] = 0xffffffff;
      pCVar12 = (CClassicArchive *)0x7c8754;
      CMwNodRef<class_CGameCamera>::MwSetNod(this_00,pCVar13,(CGameCamera *)in_stack_ffffff90);
      pCVar20 = (CClassicArchive *)(*(int *)this_00 + 0x14);
      pCVar22 = pCVar20;
      CFastBuffer<struct_CSceneVehicleStruct::SVisualVehicle>::AddNewElem
                ((void *)(*(int *)this_00 + 0x20),
                 (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)in_stack_ffffff94);
      uVar14 = 0x7c8771;
      pSVar4 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::operator[]
                         ((void *)(*(int *)this_00 + 0x20),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)in_stack_ffffff98);
      this_02 = local_c;
      pCVar15 = (CClassicArchive *)0x7c8783;
      pCVar9 = local_c;
      pSStack_8 = pSVar4;
      CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::ArchiveCount
                (pCVar20,(CFastArray<class_CPlugFileSnd*> *)local_c,in_stack_ffffff9c);
      uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar20,in_stack_ffffffa0);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pSVar11 = pSVar4;
      if (uVar5 != 0) {
        do {
          uVar5 = 0x7c87ac;
          pCVar10 = pCVar8;
          pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                             (pCVar20,pCVar8,(ulong)pCVar16);
          pSVar3 = pSVar4;
          this_03 = CFastBuffer<struct_CSceneVehicleStruct::SVisualWheel>::AddNewElem
                              (pSVar11 + 0x24,
                               (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar19);
          CMwId::CMwId(&stack0xffffffc0,(CMwId *)pCVar2);
          pSVar11 = (SCasterCat *)&DAT_00000008;
          CMwId::Archive(&stack0xffffffc4,(CFastCrypt<unsigned_long> *)this_02,pCVar22);
          pCVar22 = (CClassicArchive *)0x0;
          pCVar2 = (CSceneVehicleCar *)0x1;
          pCVar19 = (CClassicArchive *)&stack0xffffffcc;
          pCVar16 = (CFastStringInt *)0x7c87e7;
          CClassicArchive::DoNatural(this_02,pCVar19,(ulong *)0x1,0,(int)unaff_ESI);
          in_stack_00000010 = (void *)0x0;
          pCVar20 = in_stack_ffffffc0;
          if (in_stack_ffffffd0 != 0) {
            do {
              pSVar6 = CFastBuffer<struct_CSceneVehicleStruct::SVisualArm>::AddNewElem
                                 (in_stack_00000014 + 0x30,
                                  (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_EBP)
              ;
              CMwId::Archive(pSVar6 + 0x1c,(CFastCrypt<unsigned_long> *)this_02,unaff_EBX);
              unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x7c8817;
              CClassicArchive::DoBool
                        (this_02,(CClassicArchive *)pSVar6,(int *)0x1,(ulong)in_stack_ffffffc0);
              in_stack_ffffffc0 = (CClassicArchive *)0x1;
              unaff_EBX = (CClassicArchive *)(pSVar6 + 4);
              unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x7c8824;
              CClassicArchive::DoBool(this_02,unaff_EBX,(int *)0x1,(ulong)in_stack_ffffffc4);
              in_stack_00000020 = in_stack_00000020 + 1;
              pSVar4 = local_18;
              pCVar20 = in_stack_ffffffc0;
            } while (in_stack_00000020 < local_20[0]);
          }
          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this_03 + 0x20) = pCVar8;
          CClassicArchive::DoNatural
                    (this_02,(CClassicArchive *)&stack0xffffffa4,(ulong *)0x1,0,in_stack_ffffff7c);
          CMwId::Archive(pSVar4,(CFastCrypt<unsigned_long> *)this_02,in_stack_ffffff80);
          CMwId::Archive(this_03,(CFastCrypt<unsigned_long> *)this_02,in_stack_ffffff84);
          in_stack_ffffff80 = (CClassicArchive *)(this_03 + 4);
          in_stack_ffffff7c = 0x7c8869;
          CClassicArchive::DoBool(this_02,in_stack_ffffff80,(int *)0x1,(ulong)pCVar12);
          CMwId::Archive(this_03 + 0x10,(CFastCrypt<unsigned_long> *)this_02,
                         (CClassicArchive *)pCVar13);
          pCVar12 = (CClassicArchive *)(this_03 + 0x14);
          in_stack_ffffff84 = (CClassicArchive *)0x7c887f;
          CClassicArchive::DoBool(this_02,pCVar12,(int *)0x1,uVar14);
          CMwId::Archive(this_03 + 8,(CFastCrypt<unsigned_long> *)this_02,pCVar15);
          pCVar13 = (CMwNodRef<class_CGameCamera> *)0x7c8895;
          CClassicArchive::DoBool
                    (this_02,(CClassicArchive *)(this_03 + 0xc),(int *)0x1,(ulong)pCVar9);
          uVar14 = 0x7c88a2;
          CClassicArchive::DoBool(this_02,(CClassicArchive *)(pSVar4 + 4),(int *)0x1,uVar5);
          pCVar9 = (CClassicArchive *)(pSVar4 + 8);
          pCVar15 = (CClassicArchive *)0x7c88af;
          CClassicArchive::DoBool(this_02,pCVar9,(int *)0x1,(ulong)pCVar10);
          local_c = (CClassicArchive *)0xffffffff;
          OnAccessViolation_ConcatToCrashFileName(pCVar16);
          pSVar4 = (SCasterCat *)&DAT_00000008;
          pCVar8 = pCVar8 + 1;
          in_stack_ffffffc0 = pCVar20;
        } while (pCVar8 < pSVar3);
      }
      CMwId::Archive(pSVar4 + 4,(CFastCrypt<unsigned_long> *)this_02,(CClassicArchive *)pCVar16);
      CMwId::Archive(pSVar4 + 0xc,(CFastCrypt<unsigned_long> *)this_02,pCVar19);
      CClassicArchive::DoNatural(this_02,local_28,(ulong *)0x1,0,(int)pCVar2);
      ExceptionList = pSStack_8;
      return;
    }
  }
  else if (param_2 == (CClassicArchive *)0xffffffff) {
    ExceptionList = pSStack_8;
    return;
  }
  CSceneVehicle::Chunk((CSceneVehicle *)this,param_1,param_2,(ulong)pCVar2);
  ExceptionList = pSStack_8;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ComputeAirControl
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::ComputeAirControl
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2,ulong param_3,
          int param_4,int param_5)
{
{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  ulong uVar5;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  float10 fVar8;
  float in_stack_00000018;
  float in_stack_0000001c;
  GmVec3 *pGVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffe8;
  ulong in_stack_ffffffec;
  GmVec3 *pGVar10;
  float local_c;
  float local_8;
  float fStack_4;
  
  iVar2 = *(int *)(this + 100);
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar2 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),unaff_EDI);
  if (((*(int *)(*(int *)pSVar6 + 0x354) == 4) ||
      (pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar2 + 0x14),
                           *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                           unaff_ESI), *(int *)(*(int *)pSVar6 + 0x354) == 5)) &&
     (*(int *)(this + 0x5e4) != 0)) {
    return;
  }
  uVar5 = param_3;
  pGVar10 = (GmVec3 *)-*(float *)param_3;
  local_c = -*(float *)(param_3 + 4);
  local_8 = -*(float *)(param_3 + 8);
  if (in_stack_00000018 != 0.0) {
    *(int *)(this + 0x614) = param_4;
    *(undefined4 *)(this + 0x618) = *(undefined4 *)param_3;
    *(undefined4 *)(this + 0x61c) = *(undefined4 *)(param_3 + 4);
    *(undefined4 *)(this + 0x620) = *(undefined4 *)(param_3 + 8);
    goto LAB_007bf480;
  }
  if (*(int *)(this + 0x5d4) != 0) {
    *(undefined4 *)(this + 0x618) = *(undefined4 *)param_3;
    *(undefined4 *)(this + 0x61c) = *(undefined4 *)(param_3 + 4);
    *(undefined4 *)(this + 0x620) = *(undefined4 *)(param_3 + 8);
    goto LAB_007bf480;
  }
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar2 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),unaff_EBX);
  if (*(uint *)(*(int *)pSVar6 + 0x364) <= (uint)(param_5 - *(int *)(this + 0x614)))
  goto LAB_007bf480;
  bVar3 = false;
  param_2 = *(GmVec3 **)(uVar5 + 8);
  if (((_DAT_00b9ef4c < *(float *)(this + 0x58)) && (*(float *)(this + 0x61c) < 0.0)) ||
     ((*(float *)(this + 0x58) < _DAT_00b574fc && (0.0 < *(float *)(this + 0x61c))))) {
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),unaff_EBP
                       );
    in_stack_00000018 = ABS(*(float *)(uVar5 + 4));
    if (*(float *)(*(int *)pSVar6 + 0x368) < in_stack_00000018) {
      bVar3 = true;
      goto LAB_007bf388;
    }
  }
  else {
    if ((*(float *)(this + 0x58) <= _DAT_00b9ef4c) || (*(float *)(this + 0x61c) <= 0.0)) {
      if ((*(float *)(this + 0x58) < _DAT_00b574fc) && (*(float *)(this + 0x61c) < 0.0)) {
        bVar3 = true;
      }
    }
    else {
      bVar3 = true;
    }
LAB_007bf388:
    *(undefined4 *)(this + 0x61c) = *(undefined4 *)(uVar5 + 4);
  }
  param_2 = *(GmVec3 **)(this + 0x61c);
  pGVar9 = *(GmVec3 **)(iVar2 + 0x24);
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar2 + 0x14),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar9,
                      (ulong)in_stack_ffffffe8);
  if (*(int *)(*(int *)pSVar6 + 0x354) == 4) {
LAB_007bf3c9:
    if ((*(float *)(this + 0x54) <= _DAT_00b9ef4c) || (uVar1 = 0, *(float *)(this + 0x618) <= 0.0))
    {
      uVar1 = *(undefined4 *)uVar5;
    }
    *(undefined4 *)(this + 0x618) = uVar1;
    fStack_4 = *(float *)(this + 0x618);
  }
  else {
    in_stack_ffffffe8 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24);
    pGVar9 = (GmVec3 *)0x7bf3be;
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),in_stack_ffffffe8,in_stack_ffffffec);
    if (*(int *)(*(int *)pSVar6 + 0x354) == 5) goto LAB_007bf3c9;
  }
  if (bVar3) {
    fVar4 = (float)_DAT_00b3d2c0;
    pGVar10 = (GmVec3 *)((float)pGVar10 * fVar4);
    local_c = local_c * fVar4;
    local_8 = fVar4 * local_8;
  }
  if (param_5 == 0) {
    param_4 = 0;
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                        (ulong)pGVar9);
    pGVar9 = (GmVec3 *)&param_5;
    param_4 = (int)ABS(*(float *)(uVar5 + 8));
    CFuncKeysReal::GetValue
              (*(CFuncKeysReal **)(*(int *)pSVar6 + 0x36c),(CFuncColorGradient *)param_4,
               (float)&param_4);
    local_8 = local_8 * (float)param_3;
  }
  SetVehicleAngularSpeed(this,(CSceneVehicleCar *)&fStack_4,pGVar9);
LAB_007bf480:
  if (in_stack_00000018 == 0.0) {
    param_5 = (int)(local_8 * local_8 + local_c * local_c + fStack_4 * fStack_4);
    fVar8 = (float10)func_0x009c1b40();
    param_5 = (int)(float)fVar8;
    if (_DAT_00b9ef4c <= (float)param_5) {
      iVar2 = *(int *)(this + 100);
      in_stack_00000018 = 1.0 / (float)param_5;
      param_2 = (GmVec3 *)(in_stack_00000018 * fStack_4);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          (ulong)in_stack_ffffffe8);
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          in_stack_ffffffec);
      in_stack_0000001c =
           in_stack_0000001c * *(float *)(*(int *)pSVar7 + 0x158) +
           in_stack_0000001c * in_stack_0000001c * *(float *)(*(int *)pSVar6 + 0x15c);
      param_2 = (GmVec3 *)(in_stack_0000001c * (float)param_2);
      param_3 = (ulong)((float)param_3 * in_stack_0000001c);
      param_4 = (int)(in_stack_0000001c * (float)param_4);
      AddVehicleTorque(this,(CSceneVehicleCar *)&param_2,pGVar10);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ComputeAsyncState
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::ComputeAsyncState(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  uint uVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  SCasterCat *pSVar6;
  CMwId *pCVar7;
  SMwSchemeTimedProperties *pSVar8;
  SCasterCat *pSVar9;
  CMwCmdBufferCore *pCVar10;
  ulong uVar11;
  int iVar12;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  CSceneMobil *unaff_EBP;
  CPlugAudio *unaff_ESI;
  CSceneVehicleCar *pCVar14;
  uint uVar15;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CSceneVehicleCar *pCVar16;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar17;
  float10 extraout_ST0;
  float fVar18;
  GmIso4 *in_stack_00000008;
  float in_stack_0000000c;
  SParam *in_stack_00000010;
  float fStack0000001c;
  float in_stack_00000020;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000028;
  float in_stack_fffffff4;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff8;
  SParam *in_stack_fffffffc;
  
  pCVar14 = this + 0x448;
  pCVar16 = this + 0x4f0;
  for (iVar12 = 0x2a; iVar12 != 0; iVar12 = iVar12 + -1) {
    *(undefined4 *)pCVar16 = *(undefined4 *)pCVar14;
    pCVar14 = pCVar14 + 4;
    pCVar16 = pCVar16 + 4;
  }
  fVar5 = (float)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
  pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (fVar5 != 0.0) {
    do {
      pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar13,(ulong)unaff_ESI);
      pCVar13 = pCVar13 + 1;
      pSVar9 = pSVar6 + 0x298;
      pSVar6 = pSVar6 + 0x234;
      for (iVar12 = 0x19; iVar12 != 0; iVar12 = iVar12 + -1) {
        *(undefined4 *)pSVar6 = *(undefined4 *)pSVar9;
        pSVar9 = pSVar9 + 4;
        pSVar6 = pSVar6 + 4;
      }
    } while (pCVar13 < param_1);
  }
  pCVar10 = *(CMwCmdBufferCore **)(DAT_00d731e0 + 0x14);
  if (pCVar10 == (CMwCmdBufferCore *)0x0) {
    pCVar10 = DAT_00d731e0 + 0xa0;
  }
  pCVar7 = CPlugAudio::MwGetId((CPlugAudio *)pCVar10,unaff_ESI);
  uVar15 = *(uint *)pCVar7;
  if (*(int *)(this + 0x78) != 0) {
    if (DAT_00d67524 < uVar15) {
      uVar15 = uVar15 - DAT_00d67524;
    }
    else {
      uVar15 = 0;
    }
  }
  iVar12 = CSceneMobil::IsZombie((CSceneMobil *)this,unaff_EBP);
  if (iVar12 == 0) {
    pSVar8 = CMwCmdBufferCore::GetSchemeProperies
                       (DAT_00d731e0,(CMwCmdBufferCore *)&DAT_0000008c,unaff_EBX);
    fVar18 = *(float *)pSVar8;
    iVar12 = (uVar15 / (uint)fVar18) * (int)fVar18;
    if (iVar12 - uVar15 == 0) {
      param_1 = (CSceneVehicleCar *)0x3f800000;
    }
    else {
      iVar12 = uVar15 - iVar12;
      fVar3 = (float)iVar12;
      if (iVar12 < 0) {
        fVar3 = fVar3 + _DAT_00c418d0;
      }
      fVar4 = (float)(int)fVar18;
      if ((int)fVar18 < 0) {
        fVar4 = fVar4 + _DAT_00c418d0;
      }
      param_1 = (CSceneVehicleCar *)(fVar3 / fVar4);
      in_stack_0000000c = fVar18;
    }
LAB_007be845:
    if (0.0 <= (float)param_1) {
      if ((float)param_1 <= 1.0) {
        if ((float)param_1 == 0.0) goto LAB_007be87e;
        if ((float)param_1 != 1.0) {
          SVehicleCarState::SetBlend
                    (this + 0x448,(SParam *)(this + 0x2f8),(SParam *)(this + 0x3a0),
                     (SParam *)param_1,in_stack_fffffff4);
          goto LAB_007be8d0;
        }
      }
      else {
        param_1 = (CSceneVehicleCar *)0x3f800000;
      }
LAB_007be89f:
      SVehicleCarState::Set
                (this + 0x448,(CMwCmdScriptVarBool *)(this + 0x3a0),(int)in_stack_fffffff4);
      goto LAB_007be8d0;
    }
    param_1 = (CSceneVehicleCar *)0x0;
  }
  else {
    uVar1 = *(uint *)(*(int *)(this + 0x28) + 0x4c);
    if (uVar1 == 0xffffffff) {
      fVar5 = 0.0;
    }
    else {
      uVar2 = *(uint *)(*(int *)(this + 0x28) + 0x48);
      if (uVar1 == uVar2) {
        fVar5 = 0.0;
      }
      else {
        if (uVar2 <= uVar15) {
          if (uVar15 <= uVar1) {
            fVar5 = (float)(int)(uVar15 - uVar2);
            if ((int)(uVar15 - uVar2) < 0) {
              fVar5 = fVar5 + _DAT_00c418d0;
            }
            in_stack_00000008 = (GmIso4 *)(uVar1 - uVar2);
            fVar18 = (float)(int)in_stack_00000008;
            if ((int)in_stack_00000008 < 0) {
              fVar18 = fVar18 + _DAT_00c418d0;
            }
            fVar5 = fVar5 / fVar18;
            goto LAB_007be845;
          }
          fVar5 = 1.0;
          goto LAB_007be89f;
        }
        fVar5 = 0.0;
      }
    }
  }
LAB_007be87e:
  SVehicleCarState::Set(this + 0x448,(CMwCmdScriptVarBool *)(this + 0x2f8),(int)in_stack_fffffff4);
LAB_007be8d0:
  pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
            CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,in_stack_fffffff8);
  pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar13 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar9 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar17,(ulong)in_stack_fffffffc);
      in_stack_fffffffc = in_stack_00000010;
      SSimulationWheel::SState::SetBlend
                (pSVar9 + 0x298,(SParam *)(pSVar9 + 0x16c),(SParam *)(pSVar9 + 0x1d0),
                 in_stack_00000010,fVar5);
      if (*(int *)(this + 0x78) != 0) {
        pCVar10 = *(CMwCmdBufferCore **)(DAT_00d731e0 + 0x14);
        if (pCVar10 == (CMwCmdBufferCore *)0x0) {
          pCVar10 = DAT_00d731e0 + 0xa0;
        }
        fVar5 = 1.1379459e-38;
        fVar18 = CMwTimerAdapter::GetAsyncPeriod(pCVar10,(CMwTimerAdapter *)in_stack_fffffffc);
        *(float *)(pSVar9 + 0x29c) = in_stack_00000020;
        in_stack_00000020 =
             (*(float *)(this + 0x448) / *(float *)(pSVar9 + 8)) * fVar18 + in_stack_00000020;
        *(float *)(pSVar9 + 0x29c) = in_stack_00000020;
        if ((in_stack_00000020 < 0.0) || ((float)_DAT_00b9efd8 <= in_stack_00000020)) {
          fVar18 = (float)_DAT_00b9efd8;
          param_1 = (CSceneVehicleCar *)0x7be9bd;
          __CIfmod();
          fStack0000001c = (float)extraout_ST0;
          if (fStack0000001c < 0.0) {
            fStack0000001c = fStack0000001c + (fVar18 - 0.0);
          }
          in_stack_00000020 = fStack0000001c + (float)_PTR_00b2c178;
        }
        *(float *)(pSVar9 + 0x29c) = in_stack_00000020;
      }
      pCVar17 = pCVar17 + 1;
    } while (pCVar17 < pCVar13);
  }
  uVar11 = CFastBuffer<class_CCrystalFace*>::GetCount
                     (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffffc);
  if (uVar11 != 0) {
    pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar9 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar13,(ulong)fVar5);
      *(undefined4 *)(pSVar9 + 700) = *(undefined4 *)(pSVar9 + 100);
      *(undefined4 *)(pSVar9 + 0x2c0) = *(undefined4 *)(pSVar9 + 0x68);
      *(undefined4 *)(pSVar9 + 0x2c4) = *(undefined4 *)(pSVar9 + 0x6c);
      *(float *)(pSVar9 + 0x2c0) = *(float *)(pSVar9 + 0x2c0) - *(float *)(pSVar9 + 8);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 0x28) + 0x34),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)param_1);
      iVar12 = *(int *)pSVar6;
      *(float *)(pSVar9 + 0x2b0) =
           *(float *)(iVar12 + 0x20) * *(float *)(pSVar9 + 0x2c4) +
           *(float *)(pSVar9 + 700) * *(float *)(iVar12 + 0x18) +
           *(float *)(iVar12 + 0x1c) * *(float *)(pSVar9 + 0x2c0) + *(float *)(iVar12 + 0x3c);
      *(float *)(pSVar9 + 0x2b4) =
           *(float *)(iVar12 + 0x2c) * *(float *)(pSVar9 + 0x2c4) +
           *(float *)(iVar12 + 0x28) * *(float *)(pSVar9 + 0x2c0) +
           *(float *)(iVar12 + 0x24) * *(float *)(pSVar9 + 700) + *(float *)(iVar12 + 0x40);
      *(float *)(pSVar9 + 0x2b8) =
           *(float *)(iVar12 + 0x38) * *(float *)(pSVar9 + 0x2c4) +
           *(float *)(iVar12 + 0x34) * *(float *)(pSVar9 + 0x2c0) +
           *(float *)(iVar12 + 0x30) * *(float *)(pSVar9 + 700) + *(float *)(iVar12 + 0x44);
      fVar5 = 1.1380049e-38;
      GmMat3::Set(pSVar9 + 0x2c8,(CMwCmdScriptVarBool *)(pSVar9 + 0x40),(int)in_stack_00000008);
      in_stack_00000008 = *(GmIso4 **)(pSVar9 + 0x2a0);
      param_1 = (CSceneVehicleCar *)0x7beb03;
      GmMat3::RotateY(pSVar9 + 0x2c8,in_stack_00000008,in_stack_0000000c);
      pCVar13 = pCVar13 + 1;
    } while (pCVar13 < in_stack_00000028);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ComputeForces
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::ComputeForces
          (CSceneVehicleCar *this,CCallbackSceneToyBroomStickComputeForces *param_1,
          CHmsItem *param_2,float param_3)
{
{
  CHmsItem *pCVar1;
  undefined4 uVar2;
  int iVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  void *this_00;
  CSceneVehicleCar *unaff_EBX;
  GmVec3 *unaff_EBP;
  CSceneVehicleCar *unaff_ESI;
  CMwTimerAdapter *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float fVar13;
  float unaff_retaddr;
  GmVec3 *in_stack_00000010;
  ulong *in_stack_00000014;
  float in_stack_00000018;
  undefined4 in_stack_0000001c;
  float in_stack_00000020;
  float in_stack_00000024;
  float in_stack_00000028;
  float in_stack_00000030;
  SRealTimeState *in_stack_00000034;
  SRealTimeState *in_stack_00000038;
  float in_stack_0000003c;
  CSceneVehicleCar *in_stack_00000040;
  CSceneVehicleCar *in_stack_00000044;
  CCallbackSceneToyBroomStickComputeForces *in_stack_00000048;
  GmVec3 *in_stack_ffffff88;
  GmVec3 *in_stack_ffffff8c;
  GmVec3 *in_stack_ffffff90;
  GmVec3 *in_stack_ffffff94;
  SBlendableVals *in_stack_ffffff98;
  GmVec3 *in_stack_ffffff9c;
  GmVec3 *pGVar14;
  GmVec3 *in_stack_ffffffa0;
  GmVec3 *in_stack_ffffffa4;
  GmVec3 *in_stack_ffffffa8;
  SBlendableVals *in_stack_ffffffac;
  SBlendableVals in_stack_ffffffb0;
  ulong uVar15;
  CSceneVehicleCar *pCVar16;
  CSceneVehicleCar *pCVar17;
  float *pfVar18;
  double dVar19;
  float *pfVar20;
  GmVec3 *in_stack_ffffffc4;
  CSceneVehicleCar *pCVar21;
  GmVec3 *in_stack_ffffffc8;
  CFuncColorGradient *in_stack_ffffffcc;
  GmVec3 *pGVar22;
  GmVec3 *in_stack_ffffffd0;
  GmVec3 *in_stack_ffffffd4;
  GmVec3 *pGVar23;
  float fVar24;
  GmVec3 *pGVar25;
  float fVar26;
  GmVec3 *pGVar27;
  float fVar28;
  undefined4 uVar29;
  ulong uVar30;
  ulong in_stack_fffffff0;
  ulong *in_stack_fffffff4;
  ulong *puVar31;
  CSceneVehicleCar *in_stack_fffffff8;
  CSceneVehicleCar *pCVar32;
  CSceneVehicleCar *pCVar33;
  float in_stack_fffffffc;
  
  pGVar25 = *(GmVec3 **)(this + 0x824);
  pGVar27 = *(GmVec3 **)(this + 0x828);
  uVar29 = *(undefined4 *)(this + 0x82c);
  pCVar21 = *(CSceneVehicleCar **)(this + 0x81c);
  pGVar23 = *(GmVec3 **)(this + 0x820);
  *(undefined4 *)(this + 0x820) = 0;
  *(undefined4 *)(this + 0x81c) = 0;
  *(undefined4 *)(this + 0x818) = 0;
  *(undefined4 *)(this + 0x82c) = 0;
  *(undefined4 *)(this + 0x828) = 0;
  *(undefined4 *)(this + 0x824) = 0;
  if ((((byte)this[0x2f4] & 0x30) == 0) && (0.0 <= *(float *)(this + 0x1e8))) {
    CreateFakeContacts(this,unaff_ESI);
    IntegrateVehicle(this,(CSceneVehicleCar *)param_2,(float)unaff_EBP);
    this_00 = *(void **)(DAT_00d731e0 + 0x14);
    if (this_00 == (void *)0x0) {
      this_00 = (void *)(DAT_00d731e0 + 0xa0);
    }
    CMwTimerAdapter::GetTickTime(this_00,unaff_EDI);
    iVar3 = IsGroundContact(this,unaff_EBX);
    iVar8 = *(int *)(*(int *)(this + 0x28) + 0x14);
    iVar7 = *(int *)(this + 100);
    pCVar10 = (CFastBuffer<class_CCrystalFace*> *)(iVar8 + 0x18);
    if (iVar3 == 0) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar7 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar7 + 0x24),
                          (ulong)in_stack_ffffff88);
      pCVar17 = *(CSceneVehicleCar **)(*(int *)pSVar4 + 0x164);
    }
    else {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar7 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar7 + 0x24),
                          (ulong)in_stack_ffffff88);
      pCVar17 = *(CSceneVehicleCar **)(*(int *)pSVar4 + 0x160);
    }
    *(CSceneVehicleCar **)(iVar8 + 0x4c) = pCVar17;
    if (iVar3 == 0) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)in_stack_ffffff8c);
      uVar2 = *(undefined4 *)(*(int *)pSVar4 + 0x154);
    }
    else {
      uVar2 = 0;
    }
    *(undefined4 *)(iVar8 + 0x40) = uVar2;
    if (((byte)this[0x2f4] & 2) != 0) {
      pCVar16 = (CSceneVehicleCar *)0x0;
      CHmsItem::GetLinearSpeed
                (*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0xffffffcc,in_stack_ffffff90);
      if (((byte)this[0x2f4] & 8) == 0) {
        CHmsItem::GetAngularSpeed
                  (*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0xffffffe8,in_stack_ffffff94);
        CHmsItem::GetForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0xffffffe0,
                           (GmVec3 *)in_stack_ffffff98);
        *(undefined4 *)(this + 0x5b0) = 0;
        ApplyFrictionForces(this,(CSceneVehicleCar *)&stack0xffffffd8,in_stack_ffffff9c);
        fVar13 = *(float *)(this + 0x2e0) * *(float *)(this + 0x2e0);
        pGVar22 = (GmVec3 *)
                  ((float)pGVar25 * (float)pGVar25 +
                  (float)pCVar21 * (float)pCVar21 + (float)pGVar23 * (float)pGVar23);
        pCVar32 = in_stack_fffffff8;
        if ((fVar13 < (float)pGVar22) && (_DAT_00d06a80 < fVar13)) {
          dVar19 = (double)*(float *)(this + 0x2e0);
          pGVar14 = (GmVec3 *)0x7c6c03;
          fVar12 = (float10)func_0x009c1b40();
          in_stack_ffffffc8 =
               (GmVec3 *)((float)(double)CONCAT44(SUB84(dVar19,0),pCVar16) / (float)fVar12);
          pGVar23 = (GmVec3 *)((float)in_stack_ffffffc8 * (float)pGVar23);
          SetVehicleLinearSpeed(this,(CSceneVehicleCar *)&stack0xffffffd8,pGVar14);
          pCVar32 = in_stack_fffffff8;
        }
        in_stack_00000018 = 1.0;
        in_stack_0000001c = 0x3f800000;
        in_stack_00000020 = 1.0;
        in_stack_00000024 = 1.0;
        uVar15 = 0;
        ComputeVehicleGroundMaterialVals
                  (this,(CSceneVehicleCar *)&stack0x00000018,(SBlendableVals *)&stack0xffffffb0,
                   (int *)in_stack_ffffffa0);
        pfVar20 = (float *)0x3f800000;
        pfVar18 = (float *)0x3f800000;
        GetSlopeAdherence(this,(CSceneVehicleCar *)&stack0xffffffec,(GmVec3 *)&stack0xffffffbc,
                          (float *)&stack0xffffffb8,(float *)in_stack_ffffffa4);
        iVar8 = *(int *)(this + 100);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar8 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                            (ulong)in_stack_ffffffa8);
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar8 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                            (ulong)in_stack_ffffffac);
        fVar13 = ABS((float)in_stack_fffffff4) * *(float *)(*(int *)pSVar4 + 0x70) +
                 *(float *)(*(int *)pSVar5 + 0x6c);
        if (_DAT_00b9ef4c <= fVar13) {
          fVar13 = GmFunc::AsinSafe(1.0 / fVar13);
          in_stack_ffffffa4 = in_stack_ffffffc4;
          in_stack_ffffffa0 = pGVar23;
        }
        else {
          fVar13 = 0.0;
          in_stack_ffffffa4 = in_stack_ffffffc4;
          in_stack_ffffffa0 = pGVar23;
        }
        fVar13 = -*(float *)(this + 0x5e8) * fVar13;
        *(undefined4 *)(this + 0x70c) = uVar29;
        *(ulong *)(this + 0x710) = in_stack_fffffff0;
        *(ulong **)(this + 0x714) = in_stack_fffffff4;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar8 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                            uVar15);
        pCVar21 = (CSceneVehicleCar *)in_stack_ffffffa4;
        pGVar23 = in_stack_ffffffa0;
        if (*(int *)(*(int *)pSVar4 + 0x354) == 3) {
          in_stack_ffffffac = (SBlendableVals *)&stack0xffffffdc;
          in_stack_ffffffa8 = (GmVec3 *)&stack0x0000002c;
          in_stack_ffffff9c = (GmVec3 *)&param_2;
          in_stack_ffffff98 = (SBlendableVals *)&stack0xfffffff0;
          ComputeForcesModel4(this,in_stack_00000040,(float)&stack0xfffffffc,pGVar22,
                              (float)in_stack_ffffffc8,(float)in_stack_ffffff98,in_stack_ffffff9c,
                              in_stack_ffffffa0,(float)in_stack_ffffffa4,(int)in_stack_ffffffa8,
                              in_stack_ffffffac,(int *)&stack0xffffffd8,(float *)pCVar16);
        }
        else {
          in_stack_ffffffa8 = in_stack_ffffffc8;
          in_stack_ffffff98 = (SBlendableVals *)pGVar22;
          in_stack_ffffffa4 = pGVar25;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                              (ulong)pCVar16);
          in_stack_ffffffc8 = in_stack_ffffffa8;
          pGVar25 = in_stack_ffffffa4;
          if (*(int *)(*(int *)pSVar4 + 0x354) == 4) {
            in_stack_ffffffac = (SBlendableVals *)&stack0x00000030;
            in_stack_ffffffa0 = (GmVec3 *)&param_3;
            in_stack_ffffff9c = (GmVec3 *)&stack0xfffffff4;
            pGVar22 = (GmVec3 *)in_stack_ffffff98;
            ComputeForcesModel5(this,in_stack_00000044,(float)&stack0x00000000,in_stack_ffffffd0,
                                (float)in_stack_ffffff98,(float)in_stack_ffffff9c,in_stack_ffffffa0,
                                in_stack_ffffffa4,(float)in_stack_ffffffa8,(int)in_stack_ffffffac,
                                (SBlendableVals *)&stack0xffffffe0,(int *)&stack0xffffffdc,pfVar18);
          }
          else {
            in_stack_ffffffac = in_stack_ffffff98;
            in_stack_ffffff9c = in_stack_ffffffd0;
            in_stack_ffffff98 = (SBlendableVals *)in_stack_ffffffd4;
            in_stack_ffffffa8 = pGVar27;
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar8 + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                                (ulong)pfVar18);
            pGVar22 = (GmVec3 *)in_stack_ffffffac;
            in_stack_ffffffd0 = in_stack_ffffff9c;
            in_stack_ffffffd4 = (GmVec3 *)in_stack_ffffff98;
            pGVar27 = in_stack_ffffffa8;
            if (*(int *)(*(int *)pSVar4 + 0x354) == 5) {
              in_stack_ffffffa4 = (GmVec3 *)&stack0x00000010;
              in_stack_ffffffa0 = (GmVec3 *)&stack0xfffffff8;
              ComputeForcesModel6(this,(CSceneVehicleCar *)in_stack_00000048,(float)&param_1,
                                  (GmVec3 *)in_stack_ffffff98,(float)in_stack_ffffff9c,
                                  (float)in_stack_ffffffa0,in_stack_ffffffa4,in_stack_ffffffa8,
                                  (float)in_stack_ffffffac,(int)&stack0x00000034,
                                  (SBlendableVals *)&stack0xffffffe4,(int *)&stack0xffffffe0,pfVar20
                                 );
            }
            else {
              in_stack_ffffffa4 = (GmVec3 *)&stack0x00000010;
              in_stack_ffffffa0 = (GmVec3 *)&stack0xfffffff8;
              ComputeForcesModel3(this,(CSceneVehicleCar *)in_stack_00000048,(float)&param_1,
                                  (GmVec3 *)in_stack_ffffff98,(float)in_stack_ffffff9c,
                                  (float)in_stack_ffffffa0,in_stack_ffffffa4,in_stack_ffffffa8,
                                  (float)in_stack_ffffffac,(int)&stack0x00000034,
                                  (SBlendableVals *)&stack0xffffffe4,(int *)&stack0xffffffe0,pfVar20
                                 );
            }
          }
        }
        pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        uVar30 = 0;
        uVar15 = 0;
        pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,pCVar10);
        if (pCVar9 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                               (this + 0x2e8,pCVar11,(ulong)pCVar21);
            if ((*(int *)(pSVar4 + 0x124) != 0) && (pGVar23 = (GmVec3 *)0x1, *(int *)pSVar4 != 0)) {
              in_stack_fffffff4 = (ulong *)0x1;
            }
            pCVar11 = pCVar11 + 1;
          } while (pCVar11 < pCVar9);
          if (pGVar23 != (GmVec3 *)0x0) {
            pCVar21 = *(CSceneVehicleCar **)(*(int *)(this + 100) + 0x24);
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(*(int *)(this + 100) + 0x14),
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar21,
                                (ulong)in_stack_ffffffc8);
            *(float *)(this + 0x5b0) =
                 -*(float *)(this + 0x54) * *(float *)(this + 0x5a8) -
                 *(float *)(*(int *)pSVar4 + 0x58) * *(float *)(this + 0x5ac);
          }
          if ((in_stack_fffffff0 != 0) &&
             (pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(*(int *)(this + 100) + 0x14),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (*(int *)(this + 100) + 0x24),(ulong)pCVar21),
             *(float *)(*(int *)pSVar4 + 0xa4) < 0.0)) {
            pCVar21 = (CSceneVehicleCar *)&param_1;
            param_1 = (CCallbackSceneToyBroomStickComputeForces *)0x0;
            SetVehicleLinearSpeed(this,pCVar21,in_stack_ffffffc8);
          }
        }
        pCVar16 = (CSceneVehicleCar *)&stack0x00000018;
        in_stack_ffffffb0 = (SBlendableVals)0xa4;
        pCVar17 = pCVar32;
        puVar31 = in_stack_fffffff4;
        pCVar33 = pCVar32;
        ComputeAirControl(this,pCVar16,(GmVec3 *)pCVar32,(ulong)in_stack_fffffff4,in_stack_fffffff0,
                          (int)pCVar21);
        if (_DAT_00b9ef4c < *(float *)(this + 0x5c)) {
          iVar8 = *(int *)(this + 0x74c);
          if (iVar8 == 1) {
            if ((in_stack_fffffff4 != (ulong *)0x0) &&
               (*(CSceneVehicleCar **)(this + 0x610) < pCVar32)) {
              fVar24 = -(float)in_stack_00000010;
              fVar26 = -(float)in_stack_00000014;
              fVar28 = -in_stack_00000018;
              if (_DAT_00d06a80 < fVar28 * fVar28 + fVar26 * fVar26 + fVar24 * fVar24) {
                pCVar21 = (CSceneVehicleCar *)0x7c708a;
                fVar12 = (float10)func_0x009c1b40();
                in_stack_fffffffc = 1.0 / (float)fVar12;
                fVar13 = in_stack_fffffffc * fVar13;
                fVar24 = fVar24 * in_stack_fffffffc;
                fVar26 = in_stack_fffffffc * fVar26;
              }
              pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(*(int *)(this + 100) + 0x14),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (*(int *)(this + 100) + 0x24),(ulong)pCVar21);
              unaff_retaddr = *(float *)(*(int *)pSVar4 + 0x104);
              pGVar23 = (GmVec3 *)(unaff_retaddr * fVar24);
              pGVar25 = (GmVec3 *)(fVar26 * unaff_retaddr);
              pGVar27 = (GmVec3 *)(unaff_retaddr * fVar28);
              AddVehicleImpulse(this,(CSceneVehicleCar *)&stack0xffffffe0,in_stack_ffffffc8);
              *(CSceneVehicleCar **)(this + 0x610) = pCVar32 + 100;
            }
          }
          else if (iVar8 == 2) {
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(*(int *)(this + 100) + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                 (*(int *)(this + 100) + 0x24),(ulong)in_stack_ffffffc8);
            *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(*(int *)pSVar4 + 0x108);
          }
          else if (iVar8 == 3) {
            *(undefined4 *)(this + 0x600) = 1;
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(*(int *)(this + 100) + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                 (*(int *)(this + 100) + 0x24),(ulong)in_stack_ffffffc8);
            *(undefined4 *)(this + 0x5f4) = *(undefined4 *)(*(int *)pSVar4 + 0xf0);
          }
        }
        iVar8 = *(int *)(this + 100);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar8 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                            (ulong)pGVar22);
        if (*(float *)(*(int *)pSVar4 + 0x39c) < *(float *)(this + 0x670)) {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                              (ulong)in_stack_ffffffd0);
          uVar6 = *(uint *)(this + 0x654);
          if (*(float *)(this + 0x670) <= *(float *)(*(int *)pSVar4 + 0x398)) {
            if (uVar6 == 0) {
              uVar6 = 1;
            }
          }
          else if (uVar6 < 2) {
            uVar6 = 2;
          }
          *(uint *)(this + 0x654) = uVar6;
        }
        in_stack_ffffffcc = (CFuncColorGradient *)0x7c7185;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar8 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                            (ulong)in_stack_ffffffd4);
        if (*(float *)(*(int *)pSVar4 + 0x39c) < *(float *)(this + 0x674)) {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                              uVar15);
          uVar6 = *(uint *)(this + 0x658);
          if (*(float *)(this + 0x674) <= *(float *)(*(int *)pSVar4 + 0x398)) {
            if (uVar6 == 0) {
              uVar6 = 1;
            }
          }
          else if (uVar6 < 2) {
            uVar6 = 2;
          }
          *(uint *)(this + 0x658) = uVar6;
        }
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar8 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                            (ulong)fVar13);
        if (*(float *)(*(int *)pSVar4 + 0x3a0) < *(float *)(this + 0x678)) {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                              (ulong)pGVar23);
          uVar6 = *(uint *)(this + 0x1fc);
          if (*(float *)(this + 0x678) <= *(float *)(*(int *)pSVar4 + 0x28)) {
            if (uVar6 == 0) {
              uVar6 = 1;
            }
          }
          else if (uVar6 < 2) {
            uVar6 = 2;
          }
          *(uint *)(this + 0x1fc) = uVar6;
        }
        if (*(uint *)(this + 0x660) < *(uint *)(this + 0x658)) {
          *(uint *)(this + 0x660) = *(uint *)(this + 0x658);
          this[0x66c] = this[0x201];
        }
        if (*(uint *)(this + 0x664) < *(uint *)(this + 0x654)) {
          *(uint *)(this + 0x664) = *(uint *)(this + 0x654);
          this[0x66c] = this[0x201];
        }
        if (*(uint *)(this + 0x668) < *(uint *)(this + 0x1fc)) {
          *(uint *)(this + 0x668) = *(uint *)(this + 0x1fc);
          this[0x66d] = this[0x200];
        }
        pCVar21 = (CSceneVehicleCar *)&stack0xfffffffc;
        *(CSceneVehicleCar **)(this + 0x650) = pCVar32;
        iVar7 = IsGroundContactId(this,(CSceneVehicleCar *)&DAT_00000007,(uchar)SUB41(pCVar21,0),
                                  (GmVec3 *)&stack0xfffffff4,(ulong *)pGVar25);
        if (iVar7 != 0) {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                              (ulong)pGVar27);
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                              uVar30);
          in_stack_00000028 = *(float *)(*(int *)pSVar4 + 0xf0) * (float)in_stack_00000010;
          pCVar21 = pCVar32;
          EnableTurbo(this,pCVar32,*(ulong *)(*(int *)pSVar5 + 0xf8),(ulong)in_stack_00000028,
                      1.4013e-45,(ETurboType)unaff_retaddr,in_stack_fffffff0);
        }
        iVar8 = IsGroundContactId(this,(CSceneVehicleCar *)&DAT_0000001a,(uchar)SUB41(&param_3,0),
                                  (GmVec3 *)&param_1,puVar31);
        if (iVar8 != 0) {
          iVar8 = *(int *)(this + 100);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                              (ulong)pCVar33);
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                              (ulong)in_stack_fffffffc);
          in_stack_00000038 =
               (SRealTimeState *)(*(float *)(*(int *)pSVar4 + 0xf4) * in_stack_00000020);
          EnableTurbo(this,pCVar32,*(ulong *)(*(int *)pSVar5 + 0xfc),(ulong)in_stack_00000038,
                      1.4013e-45,(ETurboType)in_stack_00000010,(ulong)unaff_retaddr);
        }
        in_stack_fffffff8 = (CSceneVehicleCar *)0x1e;
        iVar8 = IsGroundContactId(this,(CSceneVehicleCar *)0x1e,(uchar)SUB41(&stack0x0000001c,0),
                                  (GmVec3 *)&stack0x00000014,(ulong *)param_1);
        if (iVar8 != 0) {
          iVar8 = *(int *)(this + 100);
          param_1 = *(CCallbackSceneToyBroomStickComputeForces **)(iVar8 + 0x24);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                              (ulong)param_2);
          param_2 = *(CHmsItem **)(iVar8 + 0x24);
          param_1 = (CCallbackSceneToyBroomStickComputeForces *)0x7c73a5;
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar8 + 0x14),
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                              (ulong)param_3);
          param_1 = (CCallbackSceneToyBroomStickComputeForces *)
                    (*(float *)(*(int *)pSVar4 + 0xf0) * in_stack_00000030);
          param_3 = in_stack_00000020;
          param_2 = (CHmsItem *)0x2;
          in_stack_fffffff8 = (CSceneVehicleCar *)0x7c73d5;
          in_stack_00000048 = param_1;
          EnableTurbo(this,pCVar32,*(ulong *)(*(int *)pSVar5 + 0xf8),(ulong)param_1,2.8026e-45,
                      (ETurboType)in_stack_00000020,(ulong)in_stack_00000010);
        }
        in_stack_00000010 = (GmVec3 *)&stack0x00000024;
        param_3 = (float)&stack0x0000002c;
        param_2 = (CHmsItem *)&DAT_0000001d;
        param_1 = (CCallbackSceneToyBroomStickComputeForces *)0x7c73e8;
        iVar8 = IsGroundContactId(this,(CSceneVehicleCar *)&DAT_0000001d,param_3._0_1_,
                                  in_stack_00000010,in_stack_00000014);
        if (iVar8 != 0) {
          *(undefined4 *)(this + 0x60c) = 1;
        }
        in_stack_00000010 = (GmVec3 *)0x7c73fe;
        UpdateTurbo(this,pCVar32,(ulong)in_stack_00000018);
        in_stack_00000018 = 1.1429226e-38;
        (**(code **)(*(int *)this + 0x1a4))();
      }
      else {
        CHmsItem::SetLinearSpeed
                  (*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0xffffffd0,in_stack_ffffff94);
      }
      pCVar1 = (CHmsItem *)(this + 0x6d4);
      CHmsItem::GetForce(*(CHmsItem **)(this + 0x28),pCVar1,(GmVec3 *)in_stack_ffffff98);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)in_stack_ffffff9c);
      fVar13 = 1.0 / *(float *)(*(int *)pSVar4 + 0x228);
      *(float *)pCVar1 = fVar13 * *(float *)pCVar1;
      *(float *)(this + 0x6d8) = fVar13 * *(float *)(this + 0x6d8);
      *(float *)(this + 0x6dc) = fVar13 * *(float *)(this + 0x6dc);
      iVar8 = *(int *)(this + 100);
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                ((void *)(iVar8 + 0x14),
                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                 (ulong)in_stack_ffffffa0);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar8 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar8 + 0x24),
                          (ulong)in_stack_ffffffa4);
      CFuncKeysReal::GetValue(*(CFuncKeysReal **)(*(int *)pSVar4 + 0x380),in_stack_ffffffcc,0.0);
      fVar13 = *(float *)(this + 0x624) +
               (float)in_stack_00000034 * ((float)extraout_ST0 + (float)pCVar21);
      *(float *)(this + 0x624) = fVar13;
      fVar24 = 0.0;
      if ((fVar13 < 0.0 == (fVar13 == 0.0)) &&
         (fVar24 = fVar13, !NAN(fVar13) && 1.0 < fVar13 != (fVar13 == 1.0))) {
        fVar24 = 1.0;
      }
      *(float *)(this + 0x624) = fVar24;
      GmSpring<float>::Integrate(this + 0x228,in_stack_00000034,(float)in_stack_ffffffa8);
      fVar24 = in_stack_00000018 + (float)in_stack_00000038 * param_3;
      fVar26 = -*(float *)(this + 0x244);
      fVar13 = *(float *)(this + 0x244);
      if ((fVar26 < fVar24) && (fVar26 = fVar24, fVar13 < fVar24 != (fVar13 == fVar24))) {
        fVar26 = fVar13;
      }
      fVar13 = *(float *)(this + 0x230);
      fVar28 = -*(float *)(this + 0x250);
      fVar24 = *(float *)(this + 0x250);
      if ((fVar28 < fVar13) && (fVar28 = fVar13, fVar24 < fVar13 != (fVar24 == fVar13))) {
        fVar28 = fVar24;
      }
      *(float *)(this + 0x230) = fVar28;
      fVar24 = *(float *)(this + 0x238) +
               (fVar26 / *(float *)(this + 0x244)) * *(float *)(this + 0x24c);
      fVar26 = -*(float *)(this + 0x24c);
      fVar13 = *(float *)(this + 0x24c);
      if ((fVar26 < fVar24) && (fVar26 = fVar24, fVar13 < fVar24 != (fVar13 == fVar24))) {
        fVar26 = fVar13;
      }
      *(float *)(this + 0x238) = fVar26;
      GmSpring<float>::Integrate(this + 0x214,in_stack_00000038,(float)in_stack_ffffffac);
      fVar24 = -in_stack_00000018 * in_stack_0000003c - in_stack_00000024;
      fVar26 = -*(float *)(this + 0x244);
      fVar13 = *(float *)(this + 0x244);
      if ((fVar26 < fVar24) && (fVar26 = fVar24, fVar13 < fVar24 != (fVar13 == fVar24))) {
        fVar26 = fVar13;
      }
      fVar13 = *(float *)(this + 0x21c);
      fVar28 = -*(float *)(this + 0x250);
      fVar24 = *(float *)(this + 0x250);
      if ((fVar28 < fVar13) && (fVar28 = fVar13, fVar24 < fVar13 != (fVar24 == fVar13))) {
        fVar28 = fVar24;
      }
      *(float *)(this + 0x21c) = fVar28;
      fVar24 = *(float *)(this + 0x224) +
               (fVar26 / *(float *)(this + 0x244)) * *(float *)(this + 0x24c);
      fVar26 = -*(float *)(this + 0x24c);
      fVar13 = *(float *)(this + 0x24c);
      if ((fVar26 < fVar24) && (fVar26 = fVar24, fVar13 < fVar24 != (fVar13 == fVar24))) {
        fVar26 = fVar13;
      }
      *(float *)(this + 0x224) = fVar26;
      iVar8 = IsAllWheelGroundContactId
                        (this,(CSceneVehicleCar *)&DAT_00000006,(uchar)in_stack_ffffffb0);
      fVar13 = _DAT_00b2c060;
      if (iVar8 != 0) {
        fVar13 = 1.0;
      }
      CFuncKeysReal::GetValue
                (*(CFuncKeysReal **)(*(int *)(this + 0x60) + 0x48),
                 (CFuncColorGradient *)ABS((float)in_stack_fffffff8 * (float)_DAT_00b3d2a8),0.0);
      fVar24 = (float)extraout_ST0_00 * (float)in_stack_00000040 * fVar13 + *(float *)(this + 0x23c)
      ;
      fVar26 = 0.0;
      if ((fVar24 < 0.0 == (fVar24 == 0.0)) &&
         (fVar26 = fVar24, !NAN(fVar24) && 1.0 < fVar24 != (fVar24 == 1.0))) {
        fVar26 = 1.0;
      }
      *(float *)(this + 0x23c) = fVar26;
      CFuncKeysReal::GetValue
                (*(CFuncKeysReal **)(*(int *)(this + 0x60) + 0x44),
                 (CFuncColorGradient *)ABS((float)in_stack_fffffff8 * (float)_DAT_00b3d2a8),0.0);
      fVar13 = (float)extraout_ST0_01 * (float)in_stack_00000040 * fVar13 + *(float *)(this + 0x240)
      ;
      fVar24 = 0.0;
      if ((fVar13 < 0.0 == (fVar13 == 0.0)) &&
         (fVar24 = fVar13, !NAN(fVar13) && 1.0 < fVar13 != (fVar13 == 1.0))) {
        fVar24 = 1.0;
      }
      *(float *)(this + 0x240) = fVar24;
      pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)pCVar16);
      pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar9 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                             (this + 0x2e8,pCVar11,(ulong)pCVar17);
          *(undefined4 *)(pSVar4 + 0x124) = 0;
          *(undefined4 *)(pSVar4 + 0x140) = 0;
          *(undefined4 *)(pSVar4 + 0x110) = 0;
          *(undefined4 *)(pSVar4 + 0x10c) = 0;
          pCVar11 = pCVar11 + 1;
          *(undefined4 *)(pSVar4 + 0x108) = 0;
          *(undefined4 *)(pSVar4 + 0x14c) = 0;
          *(undefined4 *)(pSVar4 + 0x148) = 0;
          *(undefined4 *)(pSVar4 + 0x144) = 0;
          *(undefined2 *)(pSVar4 + 0x128) = 0;
          *(undefined4 *)(pSVar4 + 0x15c) = 0;
        } while (pCVar11 < pCVar9);
      }
      *(undefined4 *)(this + 0x670) = 0;
      *(undefined4 *)(this + 0x5d8) = 0;
      *(undefined4 *)(this + 0x674) = 0;
      *(undefined4 *)(this + 0x5d4) = 0;
      *(undefined4 *)(this + 0x678) = 0;
      *(undefined4 *)(this + 0x5dc) = 0;
    }
    return;
  }
  CHmsItem::SetLinearSpeed
            (*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0xffffffe4,(GmVec3 *)unaff_ESI);
  CHmsItem::SetAngularSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0xffffffe8,unaff_EBP);
  CHmsItem::SetForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0xffffffec,in_stack_ffffff88);
  CHmsItem::SetTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0xfffffff0,in_stack_ffffff8c);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ComputeForcesModel3
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::ComputeForcesModel3
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3,
          float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9,
          SBlendableVals *param_10,int *param_11,float *param_12)
{
{
  int iVar1;
  CSceneVehicleCarTuning *this_00;
  bool bVar2;
  CSceneVehicleCar *pCVar3;
  CSceneVehicleCarTuning *pCVar4;
  GmVec3 *pGVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  SCasterCat *pSVar8;
  int iVar9;
  SCasterCat *pSVar10;
  GmVec3 *pGVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  GmVec3 *unaff_EBP;
  float unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float10 fVar12;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float fVar13;
  float fVar14;
  undefined4 uStack00000034;
  float in_stack_00000038;
  int *in_stack_0000003c;
  float in_stack_00000040;
  float in_stack_00000044;
  float in_stack_00000048;
  float fStack0000004c;
  float in_stack_00000050;
  float in_stack_00000054;
  float in_stack_00000058;
  int *in_stack_0000005c;
  float in_stack_00000060;
  float *in_stack_00000064;
  float *in_stack_00000068;
  int *in_stack_0000006c;
  float in_stack_00000070;
  undefined4 in_stack_00000074;
  float in_stack_00000078;
  SBlendableVals *pSStack00000080;
  ulong in_stack_ffffff64;
  float in_stack_ffffff68;
  ulong in_stack_ffffff6c;
  GmVec3 *in_stack_ffffff70;
  ulong in_stack_ffffff74;
  ulong in_stack_ffffff78;
  ulong in_stack_ffffff7c;
  float fVar15;
  ulong uVar16;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar17;
  GmVec3 *pGVar18;
  float fVar19;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff94;
  float fVar20;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff98;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar21;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffa0;
  float in_stack_ffffffa8;
  float *pfVar22;
  undefined4 in_stack_ffffffac;
  undefined4 uVar23;
  undefined4 in_stack_ffffffb0;
  double dVar24;
  SCasterCat *in_stack_ffffffb4;
  float in_stack_ffffffb8;
  float in_stack_ffffffbc;
  float in_stack_ffffffc0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffc4;
  float in_stack_ffffffc8;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffcc;
  float in_stack_ffffffd0;
  GmVec3 *in_stack_ffffffd4;
  float in_stack_ffffffd8;
  float in_stack_ffffffdc;
  GmVec3 *in_stack_ffffffe0;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pGVar5 = param_6;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
  dVar24 = (double)CONCAT44(in_stack_ffffffb0,in_stack_ffffffac);
  pCVar21 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar7 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar21,(ulong)unaff_ESI);
      uVar23 = SUB84(dVar24,0);
      fVar15 = 1.1723283e-38;
      pSVar10 = pSVar7;
      WheelAddForceToVehicle(this,(CSceneVehicleCar *)pSVar7,(SSimulationWheel *)param_4,unaff_EBP);
      unaff_ESI = 1.1723305e-38;
      pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x6c,
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                          (uint)*(ushort *)(pSVar7 + 0x128),(ulong)unaff_EBX);
      unaff_EBX = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar8;
      unaff_EBP = (GmVec3 *)0x7fa7dc;
      pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 0x68) + 0x14),unaff_EBX,(ulong)in_stack_ffffff94)
      ;
      iVar9 = *(int *)pSVar8 + 0x14;
      dVar24 = (double)CONCAT44(iVar9,uVar23);
      if (*(int *)(pSVar7 + 0x124) != 0) {
        iVar1 = *(int *)(this + 100);
        in_stack_ffffff94 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
        unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fa801;
        pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x14),in_stack_ffffff94,(ulong)in_stack_ffffff98);
        dVar24 = (double)CONCAT44(iVar9,uVar23);
        fVar13 = *(float *)(*(int *)pSVar8 + 0xa4);
        if (!NAN(fVar13) && 0.0 < fVar13 != (fVar13 == 0.0)) {
          in_stack_ffffff98 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
          in_stack_ffffff94 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fa822;
          pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar1 + 0x14),in_stack_ffffff98,(ulong)pCVar21);
          dVar24 = (double)CONCAT44(iVar9,uVar23);
          if (*(int *)(*(int *)pSVar8 + 0x354) != 0) {
            pCVar21 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
            in_stack_ffffff98 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fa83d;
            pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar1 + 0x14),pCVar21,(ulong)in_stack_ffffffa0);
            dVar24 = (double)CONCAT44(iVar9,uVar23);
            if (*(int *)(*(int *)pSVar8 + 0x354) == 1) {
              if (*(int *)(pSVar7 + 300) == 0) {
                fStack_c = 1.0;
              }
              else {
                in_stack_ffffffa0 =
                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
                pCVar21 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fa861;
                pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   ((void *)(iVar1 + 0x14),in_stack_ffffffa0,(ulong)pCVar6);
                fStack_c = *(float *)(*(int *)pSVar8 + 0xb0);
              }
              pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(iVar1 + 0x14),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24)
                                  ,in_stack_ffffff64);
              fVar13 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed
                                 (*(CSceneVehicleCarTuning **)pSVar8,
                                  *(CSceneVehicleCarTuning **)(param_6 + 8),in_stack_ffffff68);
              fVar13 = *(float *)(pSVar10 + 0xc) * fStack_c * fVar13 * fStack_4;
              fVar14 = *(float *)(pSVar7 + 0x148) - *(float *)(pSVar7 + 0x14c) * 0.0;
              fVar19 = *(float *)(pSVar7 + 0x14c) * 0.0 - *(float *)(pSVar7 + 0x144);
              fVar20 = *(float *)(pSVar7 + 0x144) * 0.0 - *(float *)(pSVar7 + 0x148) * 0.0;
              fStack_4 = fVar20 * fVar20 + fVar14 * fVar14 + fVar19 * fVar19;
              if (fStack_4 <= _DAT_00d0ac60) {
                unaff_EBP = (GmVec3 *)0x3f800000;
                in_stack_ffffff94 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
                unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              }
              else {
                fVar12 = (float10)func_0x009c1b40();
                fStack_4 = 1.0 / (float)fVar12;
                unaff_EBP = (GmVec3 *)(fStack_4 * fVar14);
                unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fStack_4 * fVar19);
                in_stack_ffffff94 =
                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fStack_4 * fVar20);
              }
              if (*(int *)(pSVar7 + 4) != 0) {
                __CIcos();
                fStack_4 = (float)extraout_ST0;
                in_stack_ffffffb8 = fStack_4 * (float)unaff_EBP;
                in_stack_ffffffbc = fStack_4 * (float)unaff_EBX;
                in_stack_ffffffc0 = fStack_4 * (float)in_stack_ffffff94;
                __CIsin();
                in_stack_ffffffb4 = (SCasterCat *)-(float)extraout_ST0_00;
                fStack_4 = (float)_PTR_00b2c178 * (float)in_stack_ffffffb4;
                unaff_EBP = (GmVec3 *)(in_stack_ffffffb8 + fStack_4);
                unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                            (fStack_4 + in_stack_ffffffbc);
                in_stack_ffffff94 =
                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     ((float)in_stack_ffffffb4 + in_stack_ffffffc0);
              }
              in_stack_ffffffc4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_6;
              iVar9 = *(int *)(this + 100);
              in_stack_ffffffc8 = *(float *)(param_6 + 4);
              in_stack_ffffffcc = *(CFastBuffer<class_CCrystalFace*> **)(param_6 + 8);
              in_stack_ffffff64 = 0x7faa50;
              pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(iVar9 + 0x14),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24)
                                  ,in_stack_ffffff6c);
              pCVar3 = (CSceneVehicleCar *)
                       (-*(float *)(*(int *)pSVar8 + 0xa4) * (float)_DAT_00b313b8 *
                       (in_stack_ffffffd0 * (float)in_stack_ffffff98 +
                       (float)in_stack_ffffffcc * (float)in_stack_ffffff94 +
                       in_stack_ffffffc8 * (float)unaff_EBX));
              unaff_ESI = ABS((float)pCVar3);
              if (unaff_ESI <= fVar15) {
                *(undefined4 *)(pSVar7 + 300) = 0;
              }
              else {
                pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   ((void *)(iVar9 + 0x14),
                                    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (iVar9 + 0x24),(ulong)in_stack_ffffff70);
                unaff_EBP = *(GmVec3 **)(*(int *)pSVar8 + 0xb4);
                pSVar8 = pSVar10;
                if ((float)param_1 <= 0.0) {
                  pSVar8 = (SCasterCat *)-(float)pSVar10;
                }
                *(undefined4 *)(pSVar7 + 300) = 1;
                pCVar3 = (CSceneVehicleCar *)
                         ((1.0 - (float)unaff_EBP) * (float)pSVar8 +
                         (float)unaff_EBP * (float)param_1);
                param_1 = pCVar3;
              }
              if (*(int *)(pSVar7 + 300) != 0) {
                *(undefined4 *)param_5 = 1;
              }
              pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       ((float)unaff_EBX * (float)pCVar3);
              in_stack_ffffffa8 = (float)in_stack_ffffff94 * (float)pCVar3;
              in_stack_ffffff68 = 1.1724596e-38;
              AddVehicleCentralForce(this,(CSceneVehicleCar *)&stack0xffffffa4,in_stack_ffffff70);
              iVar9 = *(int *)(this + 100);
              in_stack_ffffff6c = 0x7fab76;
              pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(iVar9 + 0x14),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24)
                                  ,in_stack_ffffff74);
              this_00 = *(CSceneVehicleCarTuning **)pSVar7;
              in_stack_ffffff70 = (GmVec3 *)0x7fab84;
              pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(iVar9 + 0x14),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24)
                                  ,in_stack_ffffff78);
              pCVar4 = (CSceneVehicleCarTuning *)ABS((float)in_stack_ffffffa0);
              in_stack_ffffff74 = 0x7faba5;
              fVar13 = CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle
                                 (*(CSceneVehicleCarTuning **)pSVar7,pCVar4,fVar13);
              dVar24 = (double)fVar13;
              in_stack_ffffff78 = 0x7fabb7;
              fVar15 = CSceneVehicleCarTuning::GetRolloverLateralFromSpeed
                                 (this_00,*(CSceneVehicleCarTuning **)(param_6 + 8),fVar15);
              param_5 = fVar15 * (float)pCVar4 *
                        (float)(double)CONCAT44(in_stack_ffffffb4,(int)((ulonglong)dVar24 >> 0x20));
              fStack_8 = -param_5;
              fStack_18 = in_stack_ffffffc0 * fStack_8 - in_stack_ffffffbc * 0.0;
              fStack_14 = in_stack_ffffffb8 * 0.0 - in_stack_ffffffc0 * 0.0;
              fStack_10 = in_stack_ffffffbc * 0.0 - fStack_8 * in_stack_ffffffb8;
              in_stack_ffffff7c = 0x7fac1e;
              AddVehicleTorque(this,(CSceneVehicleCar *)&fStack_18,(GmVec3 *)pSVar10);
            }
          }
        }
      }
      pCVar21 = pCVar21 + 1;
    } while (pCVar21 < pCVar6);
  }
  if (param_9 == 0) {
    return;
  }
  pCVar17 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)(this + 100) + 0x24);
  uVar16 = 0x7fac51;
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(*(int *)(this + 100) + 0x14),pCVar17,(ulong)unaff_ESI);
  if (*(int *)(*(int *)pSVar10 + 0x354) != 1) {
    return;
  }
  param_9 = (int)(*(float *)(param_6 + 8) * *(float *)(param_6 + 8) +
                 *(float *)param_6 * *(float *)param_6 +
                 *(float *)(param_6 + 4) * *(float *)(param_6 + 4));
  fVar12 = (float10)func_0x009c1b40();
  param_9 = (int)(float)fVar12;
  if (*(int *)(this + 0x60c) == 0) {
    if (*(float *)(this + 0x5cc) <= (float)param_9) {
      if ((float)_DAT_00b362c0 < *(float *)(this + 0x50)) goto LAB_007facea;
    }
    else if (*(float *)(this + 0x54) <= (float)_DAT_00b362c0) {
LAB_007facea:
      *(undefined4 *)(this + 0x5c4) = 0;
    }
    else {
      *(undefined4 *)(this + 0x5c4) = 1;
    }
  }
  pGVar11 = (GmVec3 *)
            CFastBuffer<class_CCrystalFace*>::GetCount
                      (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
  param_6 = (GmVec3 *)0x0;
  if (pGVar11 != (GmVec3 *)0x0) {
    do {
      fVar15 = 1.1725218e-38;
      in_stack_ffffffb4 =
           CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (this + 0x2e8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_6,
                      (ulong)unaff_EBX);
      iVar9 = *(int *)(in_stack_ffffffb4 + 4);
      if (iVar9 == 0) {
        fVar13 = -*(float *)(this + 0x840);
      }
      else {
        fVar13 = *(float *)(this + 0x840);
      }
      fVar13 = fVar13 * (float)_DAT_00b313b8;
      iVar1 = *(int *)(this + 100);
      in_stack_ffffffc8 = fVar13 * *(float *)(param_10 + 4) + *(float *)pGVar5;
      in_stack_ffffffcc = (CFastBuffer<class_CCrystalFace*> *)(*(float *)(pGVar5 + 4) + 0.0);
      in_stack_ffffffd0 = *(float *)(pGVar5 + 8) + 0.0;
      pGVar18 = (GmVec3 *)0x7fad8b;
      pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar1 + 0x14),
                           *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                           (ulong)in_stack_ffffff94);
      param_12 = *(float **)(*(int *)pSVar10 + 0x74);
      if ((float)param_10 <= (float)param_12) {
        param_12 = (float *)(((float)param_10 / (float)param_12) * (float)_DAT_00b36110 *
                            (float)_DAT_00b313b8);
        __CIsin();
        pfVar22 = (float *)(float)extraout_ST0_01;
        param_12 = pfVar22;
      }
      else {
        pfVar22 = (float *)0x3f800000;
      }
      unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fadf5;
      pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar1 + 0x14),
                           *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                           (ulong)in_stack_ffffff98);
      in_stack_ffffff94 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fae05;
      fVar14 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed
                         (*(CSceneVehicleCarTuning **)pSVar10,
                          *(CSceneVehicleCarTuning **)(pGVar5 + 8),(float)pCVar21);
      iVar1 = *(int *)(this + 100);
      in_stack_0000003c = (int *)(fVar14 * *(float *)((int)in_stack_00000040 + 0xc));
      pCVar21 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
      in_stack_ffffff98 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fae25;
      pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar1 + 0x14),pCVar21,(ulong)in_stack_ffffffa0);
      in_stack_0000003c =
           (int *)(-*(float *)(*(int *)pSVar10 + 0xa4) * (float)_DAT_00b313b8 *
                  ((float)in_stack_ffffffe0 * 0.0 + in_stack_ffffffd8 + in_stack_ffffffdc * 0.0));
      in_stack_ffffffb8 = ABS((float)in_stack_0000003c);
      if (in_stack_00000040 < in_stack_ffffffb8) {
        pCVar21 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fae8d;
        pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            ((void *)(iVar1 + 0x14),
                             *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                             (ulong)pCVar6);
        pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
        in_stack_ffffffa0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fae9b;
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x14),pCVar6,(ulong)pfVar22);
        in_stack_00000048 =
             *(float *)(*(int *)pSVar7 + 0xe4) * in_stack_ffffffc0 +
             (1.0 - *(float *)(*(int *)pSVar10 + 0xe4)) * in_stack_00000048;
        bVar2 = in_stack_00000044 <= 0.0;
        in_stack_00000044 = in_stack_00000048;
        if (bVar2) {
          in_stack_00000044 = -in_stack_00000048;
        }
      }
      pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar1 + 0x14),
                           *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                           in_stack_ffffff7c);
      dVar24 = (double)CONCAT44(fVar13,pfVar22);
      fVar13 = *(float *)(*(int *)pSVar10 + 0x98);
      if (pCVar21 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        if (*(int *)(in_stack_ffffffa0 + 300) == 0) {
          in_stack_ffffff98 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
        }
        else {
          pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              ((void *)(iVar1 + 0x14),
                               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                               uVar16);
          in_stack_ffffff98 =
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)pSVar10 + 0x9c);
        }
        in_stack_ffffff7c = 0x7faf60;
        pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            ((void *)(iVar1 + 0x14),
                             *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                             (ulong)pCVar17);
        dVar24 = (double)param_8;
        uVar16 = 0x7faf7b;
        fVar15 = CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed
                           (*(CSceneVehicleCarTuning **)pSVar10,
                            *(CSceneVehicleCarTuning **)(pGVar5 + 8),fVar15);
        param_9 = (int)((float)(double)CONCAT44(iVar9,(int)((ulonglong)dVar24 >> 0x20)) -
                       (float)param_10 * (float)pCVar21 * *(float *)(this + 0x5e8) * fVar15 *
                       (float)in_stack_ffffffa0);
      }
      fStack_18 = (float)param_9 * 0.0;
      fStack_10 = fStack_18 * 0.0 - (float)pCVar6 * fStack_18;
      fStack_c = (float)param_9 * (float)pCVar6 - fStack_18 * 0.0;
      fStack_8 = fStack_18 * 0.0 - (float)param_9 * 0.0;
      pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fb00c;
      param_9 = (int)fStack_18;
      fStack_14 = fStack_18;
      AddVehicleTorque(this,(CSceneVehicleCar *)&fStack_10,pGVar18);
      in_stack_ffffffa8 = SUB84(dVar24,0);
      dVar24 = (double)CONCAT44(iVar9,(int)((ulonglong)dVar24 >> 0x20));
      param_6 = (GmVec3 *)((int)(fVar13 * (float)param_6) + 1);
    } while (param_6 < pGVar11);
  }
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(*(int *)(this + 100) + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                        (*(int *)(this + 100) + 0x24),(ulong)unaff_EBX);
  param_10 = (SBlendableVals *)
             CSceneVehicleCarTuning::GetAccelFromSpeed
                       (*(CSceneVehicleCarTuning **)pSVar10,*(CSceneVehicleCarTuning **)(pGVar5 + 8)
                        ,(float)in_stack_ffffff94);
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(*(int *)(this + 100) + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                        (*(int *)(this + 100) + 0x24),(ulong)in_stack_ffffff98);
  fVar15 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed
                     (*(CSceneVehicleCarTuning **)pSVar10,*(CSceneVehicleCarTuning **)(pGVar5 + 8),
                      (float)pCVar21);
  iVar9 = *(int *)(this + 100);
  param_10 = (SBlendableVals *)(fVar15 * *(float *)((int)in_stack_00000040 + 0xc));
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar9 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                       (ulong)in_stack_ffffffa0);
  in_stack_0000003c =
       (int *)ABS(*(float *)(*(int *)pSVar10 + 0xa4) * (float)_DAT_00b313b8 * *(float *)pGVar5);
  if ((float)param_11 < (float)in_stack_0000003c) {
    in_stack_0000003c = param_11;
  }
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar9 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                       (ulong)pCVar6);
  param_12 = (float *)ABS(*(float *)(this + 0x5e8));
  iVar1 = *(int *)pSVar10;
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar9 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                       (ulong)in_stack_ffffffa8);
  fStack0000004c =
       CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed
                 (*(CSceneVehicleCarTuning **)pSVar10,*(CSceneVehicleCarTuning **)(pGVar5 + 8),
                  SUB84(dVar24,0));
  fStack0000004c = *(float *)(iVar1 + 0x7c) * in_stack_00000048 * in_stack_00000038 * fStack0000004c
  ;
  if (*(int *)(this + 0x5c4) == 0) {
    in_stack_00000048 = 0.0;
  }
  else {
    in_stack_00000048 = _DAT_00b2c060;
  }
  if (*(int *)(this + 0x600) == 0) {
    in_stack_00000038 = 0.0;
  }
  else {
    in_stack_00000038 = *(float *)(this + 0x5f4);
  }
  fVar15 = (in_stack_00000040 - fStack0000004c) *
           (*(float *)(this + 0x50) * *(float *)((int)in_stack_00000050 + 4) +
            in_stack_00000048 * *(float *)((int)in_stack_00000050 + 4) * *(float *)(this + 0x54) +
           in_stack_00000038);
  if (*(int *)(this + 0x60c) != 0) {
    if (*(int *)(this + 0x600) == 0) {
      fVar15 = in_stack_00000040 * 0.0;
    }
    else {
      fVar15 = in_stack_00000040 * *(float *)(this + 0x5f4);
    }
  }
  in_stack_00000040 = fVar15;
  in_stack_00000048 = 0.0;
  if (0.0 < *(float *)(pGVar5 + 8)) {
    iVar9 = *(int *)(this + 100);
    pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                        ((void *)(iVar9 + 0x14),
                         *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                         (ulong)((ulonglong)dVar24 >> 0x20));
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar9 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                        (ulong)in_stack_ffffffb4);
    in_stack_00000050 =
         (*(float *)(*(int *)pSVar10 + 0x44) * *(float *)(pGVar5 + 8) +
         *(float *)(*(int *)pSVar7 + 0x40)) * *(float *)(this + 0x54);
    if (*in_stack_0000005c == 0) {
      pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar9 + 0x14),
                           *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                           (ulong)in_stack_ffffffb8);
      in_stack_00000044 = *(float *)(*(int *)pSVar10 + 0x4c);
    }
    else {
      pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar9 + 0x14),
                           *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                           (ulong)in_stack_ffffffb8);
      in_stack_00000044 = *(float *)(*(int *)pSVar10 + 0x48);
    }
    in_stack_00000044 = (float)in_stack_0000005c[2] * in_stack_00000044;
    if (in_stack_00000044 < in_stack_00000054) {
      in_stack_00000054 = in_stack_00000044;
      pCVar21 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount
                          (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)pGVar11);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar21 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar10 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                              (this + 0x2e8,pCVar6,(ulong)in_stack_ffffffc0);
          pCVar6 = pCVar6 + 1;
          *(undefined4 *)(pSVar10 + 300) = 1;
        } while (pCVar6 < pCVar21);
      }
    }
  }
  if (*(float *)(pGVar5 + 8) < 0.0) {
    if (*(int *)(this + 0x60c) == 0) goto LAB_007fb44c;
    iVar9 = *(int *)(this + 100);
    pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                        ((void *)(iVar9 + 0x14),
                         *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                         (ulong)in_stack_ffffffc0);
    uVar16 = 0x7fb33b;
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar9 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                        (ulong)in_stack_ffffffc4);
    in_stack_00000060 =
         (*(float *)(*(int *)pSVar10 + 0x40) -
         *(float *)(*(int *)pSVar7 + 0x44) * *(float *)(pGVar5 + 8)) * *(float *)(this + 0x50);
    if (*in_stack_0000006c == 0) {
      in_stack_ffffffc4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24);
      in_stack_ffffffc0 = 1.17275e-38;
      pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar9 + 0x14),in_stack_ffffffc4,(ulong)in_stack_ffffffc8);
      in_stack_00000070 = *(float *)(*(int *)pSVar10 + 0x4c);
    }
    else {
      in_stack_ffffffc4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24);
      in_stack_ffffffc0 = 1.1727474e-38;
      pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar9 + 0x14),in_stack_ffffffc4,(ulong)in_stack_ffffffc8);
      in_stack_00000070 = *(float *)(*(int *)pSVar10 + 0x48);
    }
    in_stack_00000070 = (float)in_stack_0000006c[2] * in_stack_00000070;
    if (in_stack_00000070 < (float)in_stack_00000064) {
      in_stack_ffffffc8 = 1.1727611e-38;
      in_stack_00000064 = (float *)in_stack_00000070;
      pCVar21 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,in_stack_ffffffcc);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar21 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar10 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                              (this + 0x2e8,pCVar6,uVar16);
          pCVar6 = pCVar6 + 1;
          *(undefined4 *)(pSVar10 + 300) = 1;
        } while (pCVar6 < pCVar21);
      }
    }
    in_stack_00000058 = -in_stack_00000058;
  }
  if ((*(int *)(this + 0x60c) != 0) && (ABS(*(float *)(pGVar5 + 8)) < 1.0)) {
    in_stack_00000058 = ABS(*(float *)(pGVar5 + 8)) * in_stack_00000058;
  }
LAB_007fb44c:
  *in_stack_00000068 = in_stack_00000058;
  iVar9 = *(int *)(this + 100);
  in_stack_00000064 = (float *)(in_stack_00000050 - in_stack_00000058);
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar9 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                       (ulong)in_stack_ffffffc0);
  pfVar22 = in_stack_00000064;
  in_stack_0000005c = (int *)(*(float *)(*(int *)pSVar10 + 0x30) * *in_stack_00000064);
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar9 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                       (ulong)in_stack_ffffffc4);
  in_stack_00000068 = (float *)(*(float *)(*(int *)pSVar10 + 0x2c) * *pfVar22);
  if ((float)in_stack_00000068 < *(float *)(pGVar5 + 8)) {
    pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                        ((void *)(iVar9 + 0x14),
                         *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                         (ulong)in_stack_ffffffc8);
    in_stack_00000070 = -*(float *)(*(int *)pSVar10 + 0x60);
  }
  if (*(float *)(pGVar5 + 8) < -(float)in_stack_00000064) {
    pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                        ((void *)(iVar9 + 0x14),
                         *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                         (ulong)in_stack_ffffffcc);
    in_stack_00000074 = *(undefined4 *)(*(int *)pSVar10 + 0x60);
  }
  in_stack_00000038 = in_stack_00000070 * in_stack_00000058;
  param_12 = (float *)0x0;
  uStack00000034 = 0;
  in_stack_00000070 = in_stack_00000038;
  AddVehicleCentralForce(this,(CSceneVehicleCar *)&param_12,(GmVec3 *)in_stack_ffffffcc);
  param_9 = 0;
  param_8 = 0.0;
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(*(int *)(this + 100) + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                        (*(int *)(this + 100) + 0x24),(ulong)in_stack_ffffffd0);
  param_8 = -in_stack_00000078 * *(float *)(*(int *)pSVar10 + 0xc0);
  AddVehicleTorque(this,(CSceneVehicleCar *)&param_8,in_stack_ffffffd4);
  iVar9 = *(int *)(this + 100);
  pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar9 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                       (ulong)in_stack_ffffffd8);
  pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar9 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                      (ulong)in_stack_ffffffdc);
  param_10 = (SBlendableVals *)
             ((-*(float *)(*(int *)pSVar10 + 100) * in_stack_00000064[2]) /
             *(float *)(*(int *)pSVar7 + 0x160));
  param_8 = 0.0;
  param_9 = 0;
  pSStack00000080 = param_10;
  AddVehicleCentralForce(this,(CSceneVehicleCar *)&param_8,in_stack_ffffffe0);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ComputeForcesModel4
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::ComputeForcesModel4
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3,
          float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9,
          SBlendableVals *param_10,int *param_11,float *param_12)
{
{
  int iVar1;
  bool bVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  float unaff_EBX;
  GmVec3 *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  float10 fVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float fVar8;
  float fVar9;
  int *in_stack_ffffff18;
  int *in_stack_ffffff1c;
  GmVec3 *in_stack_ffffff20;
  GmVec3 *in_stack_ffffff24;
  ulong in_stack_ffffff28;
  float in_stack_ffffff2c;
  ulong in_stack_ffffff34;
  float fVar10;
  ulong in_stack_ffffff44;
  GmVec3 *in_stack_ffffff4c;
  GmVec3 *pGVar11;
  float in_stack_ffffff50;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff54;
  CSceneVehicleCarTuning *pCVar12;
  ulong uVar13;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff58;
  float fVar14;
  GmVec3 *pGVar15;
  float fVar16;
  CSceneVehicleCarTuning *pCVar17;
  float fVar18;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar19;
  float fVar20;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar21;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined4 local_64;
  undefined4 uStack_60;
  float local_5c;
  float fStack_58;
  float local_54 [3];
  SBlendableVals *pSStack_48;
  SBlendableVals *pSStack_44;
  undefined4 uStack_38;
  float fStack_34;
  GmVec3 *pGStack_30;
  int iStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_c;
  
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar6,(ulong)param_3);
      WheelAddForceToVehicle
                (this,(CSceneVehicleCar *)pSVar4,(SSimulationWheel *)unaff_ESI,unaff_EBP);
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar3);
  }
  iVar1 = *(int *)(this + 0x640);
  local_5c = (float)(uint)(iVar1 != 0);
  local_64 = 0;
  if (param_9 == 0) goto LAB_007fc108;
  fStack_6c = *(float *)(param_6 + 8) * *(float *)(param_6 + 8) +
              *(float *)param_6 * *(float *)param_6 +
              *(float *)(param_6 + 4) * *(float *)(param_6 + 4);
  fVar7 = (float10)func_0x009c1b40();
  pGVar15 = (GmVec3 *)(float)fVar7;
  if (*(int *)(this + 0x60c) == 0) {
    if (*(float *)(this + 0x5cc) <= (float)pGVar15) {
      if ((float)_DAT_00b362c0 < *(float *)(this + 0x50)) goto LAB_007fb6d4;
    }
    else if (*(float *)(this + 0x54) <= (float)_DAT_00b362c0) {
LAB_007fb6d4:
      *(undefined4 *)(this + 0x5c4) = 0;
    }
    else {
      *(undefined4 *)(this + 0x5c4) = 1;
    }
  }
  if ((iVar1 == 1) && (ABS(*(float *)(this + 0x5e8)) < _DAT_00ba38fc)) {
    __CIatan2();
    *(undefined4 *)(this + 0x640) = 2;
    *(float *)(this + 0x638) = (float)extraout_ST0;
  }
  if ((*(int *)(this + 0x640) != 0) && (*(int *)(this + 0x640) == 1)) {
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(*(int *)(this + 100) + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)(this + 100) + 0x24),
               (ulong)in_stack_ffffff18);
  }
  __CIsin();
  fVar9 = (float)extraout_ST0_00;
  __CIcos();
  fVar18 = (float)extraout_ST0_01;
  fVar20 = 0.0;
  unaff_EBP = (GmVec3 *)-fVar9;
  fVar14 = 0.0;
  fVar16 = 0.0;
  fVar8 = *(float *)param_6 * fVar9 + *(float *)(param_6 + 4) * 0.0 +
          *(float *)(param_6 + 8) * fVar18;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           (*(float *)(param_6 + 8) * 0.0 + *(float *)param_6 + *(float *)(param_6 + 4) * 0.0);
  pGVar11 = in_stack_ffffff4c;
  GetLateralFriction(this,(CSceneVehicleCar *)param_6,(GmVec3 *)&stack0xffffff6c,pGStack_30,
                     pSStack_48,(float)in_stack_ffffff4c,(int)&stack0xffffff28,
                     (float *)&stack0xffffff2c,in_stack_ffffff18);
  GetLateralFriction(this,(CSceneVehicleCar *)param_6,(GmVec3 *)&stack0xffffff64,pGStack_30,
                     pSStack_44,(float)in_stack_ffffff4c,(int)&stack0xffffff44,local_54,
                     in_stack_ffffff1c);
  fStack_6c = (float)pGVar15 * (float)_DAT_00b313b8;
  fStack_74 = fStack_6c * (float)unaff_EBP;
  fStack_70 = unaff_EBX * fStack_6c;
  fStack_6c = fStack_6c * fStack_84;
  fVar10 = (float)_DAT_00b313b8 * (float)pCVar6;
  local_5c = fVar10 * fVar16;
  fStack_58 = fVar18 * fVar10;
  local_54[0] = fVar10 * fVar20;
  AddVehicleCentralForce(this,(CSceneVehicleCar *)&fStack_74,in_stack_ffffff20);
  AddVehicleCentralForce(this,(CSceneVehicleCar *)&fStack_58,in_stack_ffffff24);
  iVar1 = *(int *)(this + 100);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                      in_stack_ffffff28);
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                      (ulong)in_stack_ffffff2c);
  pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
            (-*(float *)(iStack_28 + 4) * *(float *)(*(int *)pSVar4 + 0x1a0) -
            ABS(*(float *)(iStack_28 + 4)) * *(float *)(iStack_28 + 4) *
            *(float *)(*(int *)pSVar5 + 0x1a4));
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((float)_PTR_00b2c178 * (float)pCVar19)
  ;
  pCVar17 = (CSceneVehicleCarTuning *)pCVar3;
  pCVar21 = pCVar3;
  AddVehicleTorque(this,(CSceneVehicleCar *)&stack0xffffff68,pGVar15);
  if ((*(int *)(this + 0x640) != 2) ||
     (fVar9 = ABS(*(float *)(this + 0x638)), fVar9 <= _DAT_00ba38fc)) {
LAB_007fba9d:
    in_stack_ffffff58 =
         (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)ABS(*(float *)(this + 0x5e8));
    if (_DAT_00ba38fc < (float)in_stack_ffffff58) {
      pGVar11 = (GmVec3 *)0x3f800000;
      if (unaff_EBX != 0.0) {
        pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)(this + 100) + 0x24);
        fVar10 = 1.1730225e-38;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(this + 100) + 0x14),pCVar3,in_stack_ffffff44);
        pGVar11 = *(GmVec3 **)(*(int *)pSVar4 + 0x1b8);
      }
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)fVar10);
      pCVar12 = (CSceneVehicleCarTuning *)ABS((float)in_stack_ffffff58);
      fVar18 = CSceneVehicleCarTuning::M4GetSteerRadiusFromSpeed
                         (*(CSceneVehicleCarTuning **)pSVar4,pCVar12,(float)pCVar3);
      in_stack_ffffff54 =
           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fVar18 * (float)pCVar12);
      if (_DAT_00ba38fc < (float)in_stack_ffffff54) {
        iVar1 = *(int *)(this + 100);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                            in_stack_ffffff44);
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                            (ulong)pCVar6);
        fStack_78 = (-(float)pCVar17 * fVar14 * *(float *)(*(int *)pSVar4 + 0x19c) *
                     *(float *)(*(int *)pSVar5 + 0x1a0) * ABS(*(float *)(this + 0x5e8))) / fVar9;
        fStack_7c = (float)_PTR_00b2c178 * fStack_78;
        goto LAB_007fbbd1;
      }
    }
  }
  else {
    iVar1 = *(int *)(this + 100);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        in_stack_ffffff34);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             ABS(*(float *)(*(int *)pSVar4 + 0x1d0));
    if ((float)pCVar6 <= _DAT_00ba38fc) goto LAB_007fba9d;
    pCVar6 = _DAT_00b2c060;
    if (*(int *)(this + 0x5c4) == 0) {
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
    }
    in_stack_ffffff54 = _DAT_00b2c060;
    if (0.0 < *(float *)(this + 0x638)) {
      in_stack_ffffff54 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
    }
    in_stack_ffffff50 = fVar14;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        (ulong)fVar8);
    pCVar12 = *(CSceneVehicleCarTuning **)pSVar4;
    fVar18 = in_stack_ffffff50;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        (ulong)fVar10);
    iVar1 = *(int *)pSVar4;
    pCVar17 = (CSceneVehicleCarTuning *)ABS((float)in_stack_ffffff58);
    fVar8 = CSceneVehicleCarTuning::M4GetSteerRadiusFromSpeed(pCVar12,pCVar17,(float)pCVar3);
    pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              (fVar8 / (*(float *)(iVar1 + 0x1d0) * (float)in_stack_ffffff58));
    if (_DAT_00ba38fc < (float)pCVar19) {
      iVar1 = *(int *)(this + 100);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          in_stack_ffffff44);
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          (ulong)pCVar6);
      fStack_78 = (-((float)pCVar17 * fVar9) * fVar18 * *(float *)(*(int *)pSVar4 + 0x19c) *
                  *(float *)(*(int *)pSVar5 + 0x1a0)) / (float)unaff_EBP;
      fStack_7c = (float)_PTR_00b2c178 * fStack_78;
LAB_007fbbd1:
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&fStack_7c;
      in_stack_ffffff44 = 0x7fbbe4;
      fStack_74 = fStack_7c;
      AddVehicleTorque(this,(CSceneVehicleCar *)pCVar6,pGVar11);
    }
  }
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 100) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                       (*(int *)(this + 100) + 0x24),in_stack_ffffff44);
  fVar9 = CSceneVehicleCarTuning::GetAccelFromSpeed
                    (*(CSceneVehicleCarTuning **)pSVar4,pCVar17,(float)pCVar6);
  pCVar3 = _DAT_00b2c060;
  if (*(int *)(this + 0x5c4) == 0) {
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  }
  if (*(int *)(this + 0x600) == 0) {
    fVar18 = 0.0;
  }
  else {
    fVar18 = *(float *)(this + 0x5f4);
  }
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           (fVar9 * (*(float *)(param_1 + 4) * *(float *)(this + 0x50) +
                     *(float *)(param_1 + 4) * (float)pCVar3 * *(float *)(this + 0x54) + fVar18));
  if (*(int *)(this + 0x60c) != 0) {
    if (*(int *)(this + 0x600) == 0) {
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fVar9 * 0.0);
    }
    else {
      pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x5f4);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fVar9 * (float)pCVar3);
    }
  }
  pGVar15 = (GmVec3 *)0x0;
  if (0.0 < (float)pCVar19) {
    iVar1 = *(int *)(this + 100);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar1 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),(ulong)pGVar11);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar1 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
               (ulong)in_stack_ffffff50);
    if (*(int *)param_2 == 0) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          (ulong)in_stack_ffffff54);
      pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)pSVar4 + 0x4c);
    }
    else {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          (ulong)in_stack_ffffff54);
      pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)pSVar4 + 0x48);
    }
    pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              (*(float *)((int)param_4 + 8) * (float)pCVar6);
    if ((float)pCVar19 < (float)pCVar21) {
      fStack_7c = 1.4013e-45;
      pCVar21 = pCVar19;
    }
  }
  if ((unaff_EBX < 0.0) && (*(int *)(this + 0x60c) != 0)) {
    iVar1 = *(int *)(this + 100);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar1 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
               (ulong)in_stack_ffffff58);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar1 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),(ulong)pCVar3);
    if (*(int *)param_2 == 0) {
      pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
      in_stack_ffffff58 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fbdc4;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),pCVar3,(ulong)fVar9);
      unaff_EBP = *(GmVec3 **)(*(int *)pSVar4 + 0x4c);
    }
    else {
      pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
      in_stack_ffffff58 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fbdb4;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),pCVar3,(ulong)fVar9);
      unaff_EBP = *(GmVec3 **)(*(int *)pSVar4 + 0x48);
    }
    unaff_EBX = *(float *)(param_7 + 8) * (float)unaff_EBP;
    if (unaff_EBX < fStack_84) {
      fStack_70 = 1.4013e-45;
      fStack_84 = unaff_EBX;
    }
    fStack_84 = -fStack_84;
  }
  if ((*(int *)(this + 0x60c) != 0) &&
     (pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)ABS(unaff_EBX),
     (float)pCVar19 < 1.0)) {
    pCVar21 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((float)pCVar19 * (float)pCVar21);
  }
  if (fStack_7c == 0.0) {
    if (fStack_74 != 0.0) goto LAB_007fbe97;
  }
  else if (fStack_74 == 0.0) {
    *(undefined4 *)(this + 0x638) = 0;
    pCVar6 = _DAT_00b2c060;
    if (0.0 < *(float *)(this + 0x5e8)) {
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
    }
    *(undefined4 *)(this + 0x640) = 1;
    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x63c) = pCVar6;
  }
  else {
LAB_007fbe97:
    iVar1 = *(int *)(this + 100);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        (ulong)in_stack_ffffff58);
    pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              (*(float *)(*(int *)pSVar4 + 0x1cc) * *(float *)(this + 0x5e8) * fStack_c +
              *(float *)(this + 0x638));
    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x638) = pCVar19;
    in_stack_ffffff58 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
    uVar13 = 0x7fbedb;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),in_stack_ffffff58,(ulong)pCVar3);
    unaff_EBP = (GmVec3 *)ABS((float)pCVar21);
    if (*(float *)(*(int *)pSVar4 + 0x1d8) < (float)unaff_EBP) {
      bVar2 = 0.0 < (float)pCVar21;
      pCVar21 = _DAT_00b2c060;
      if (bVar2) {
        pCVar21 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
      }
      pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
      in_stack_ffffff58 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fbf21;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),pCVar3,(ulong)fVar9);
      *(float *)(this + 0x638) = *(float *)(*(int *)pSVar4 + 0x1d8) * (float)unaff_EBP;
    }
    bVar2 = false;
    if ((*(float *)(this + 0x63c) <= 0.0) || (0.0 <= *(float *)(this + 0x638))) {
      if ((*(float *)(this + 0x63c) < 0.0) && (0.0 < *(float *)(this + 0x638))) {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
    }
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),uVar13);
    fStack_78 = ABS(fStack_78);
    if (((fStack_78 < *(float *)(*(int *)pSVar4 + 0x1b0)) &&
        (fStack_78 = ABS(*(float *)(this + 0x5e8)), fStack_78 < _DAT_00ba38fc)) || (bVar2)) {
      fStack_7c = 0.0;
      *(undefined4 *)(this + 0x638) = 0;
      *(undefined4 *)(this + 0x640) = 0;
    }
    else {
      fStack_7c = 1.4013e-45;
    }
  }
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_6 = pCVar21;
  iVar1 = *(int *)(this + 100);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                      (ulong)in_stack_ffffff58);
  unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)
              (*(float *)(*(int *)pSVar4 + 0x30) * *(float *)param_5);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                      (ulong)pCVar3);
  fStack_70 = *(float *)(*(int *)pSVar4 + 0x2c) * *(float *)param_5;
  if (fStack_70 < fStack_80) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        (ulong)fVar9);
    fStack_84 = -*(float *)(*(int *)pSVar4 + 0x60);
  }
  if (fStack_7c < -unaff_EBX) {
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar1 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),(ulong)pGVar15);
  }
  fStack_1c = fStack_84 * param_2;
  fStack_24 = fStack_1c * fStack_58;
  fStack_20 = (float)_PTR_00b2c178 * fStack_1c;
  fStack_1c = fStack_1c * fStack_78;
  AddVehicleCentralForce(this,(CSceneVehicleCar *)&fStack_24,pGVar15);
  pGStack_30 = (GmVec3 *)0x0;
  fStack_34 = 0.0;
  uStack_38 = 0;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 100) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                       (*(int *)(this + 100) + 0x24),(ulong)pCVar6);
  fStack_34 = -fStack_7c * *(float *)(*(int *)pSVar4 + 0xc0);
  AddVehicleTorque(this,(CSceneVehicleCar *)&fStack_34,(GmVec3 *)pCVar19);
LAB_007fc108:
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_ESI);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    *(undefined4 *)(this + 0x628) = uStack_60;
    return;
  }
  do {
    pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (this + 0x2e8,pCVar6,(ulong)unaff_EBP);
    pCVar6 = pCVar6 + 1;
    *(float *)(pSVar4 + 300) = local_5c;
  } while (pCVar6 < pCVar3);
  *(float *)(this + 0x628) = local_5c;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ComputeForcesModel5
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::ComputeForcesModel5
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3,
          float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9,
          SBlendableVals *param_10,int *param_11,float *param_12)
{
{
  int iVar1;
  CSceneVehicleCarTuning *this_00;
  uint uVar2;
  uint uVar3;
  int iVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  SCasterCat *pSVar8;
  ulong *puVar9;
  void *this_01;
  CSceneVehicleCarTuning *unaff_EBX;
  GmVec3 *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  GmVec3 *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float unaff_retaddr;
  int in_stack_0000003c;
  undefined4 uStack00000044;
  float fStack00000048;
  float fStack0000004c;
  undefined4 uStack0000006c;
  undefined4 uStack00000070;
  float fStack00000074;
  int in_stack_0000007c;
  int in_stack_00000090;
  float in_stack_00000098;
  int *in_stack_0000009c;
  float *in_stack_000000a4;
  float *in_stack_000000a8;
  int *in_stack_000000ac;
  ulong in_stack_ffffff44;
  float in_stack_ffffff48;
  ulong in_stack_ffffff4c;
  GmVec3 *in_stack_ffffff50;
  ulong in_stack_ffffff54;
  ulong uVar18;
  CFastBuffer<class_CCrystalFace*> *pCVar19;
  float fVar20;
  GmVec3 *pGVar21;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff70;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff74;
  float in_stack_ffffff78;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff80;
  ulong in_stack_ffffff88;
  float in_stack_ffffff8c;
  float fVar22;
  GmVec3 *in_stack_ffffff94;
  float fVar23;
  float in_stack_ffffffa4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar24;
  float in_stack_ffffffac;
  double dVar25;
  undefined4 in_stack_ffffffb0;
  float in_stack_ffffffb8;
  float in_stack_ffffffbc;
  float in_stack_ffffffc0;
  float in_stack_ffffffc4;
  float in_stack_ffffffc8;
  float in_stack_ffffffcc;
  float in_stack_ffffffd0;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffd8;
  float in_stack_ffffffdc;
  float in_stack_ffffffe0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffe4;
  float fVar26;
  float in_stack_fffffff8;
  GmVec3 *pGVar27;
  float in_stack_fffffffc;
  
  uVar18 = 0x7fc189;
  iVar4 = ApplyWaterForces(this,(CSceneVehicleCar *)param_2,unaff_EDI);
  fVar12 = *(float *)(this + 0x628);
  *(int *)(this + 0x5e4) = iVar4;
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_ESI);
  pCVar24 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar24,(ulong)unaff_EBP);
      WheelAddForceToVehicle
                (this,(CSceneVehicleCar *)pSVar6,(SSimulationWheel *)param_5,(GmVec3 *)unaff_EBX);
      unaff_EBP = (GmVec3 *)0x7fc1f0;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x6c,
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                          (uint)*(ushort *)(pSVar6 + 0x128),(ulong)in_stack_ffffff70);
      in_stack_ffffff70 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar7;
      unaff_EBX = (CSceneVehicleCarTuning *)0x7fc1fe;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 0x68) + 0x14),in_stack_ffffff70,
                          (ulong)in_stack_ffffff74);
      dVar25 = (double)CONCAT44(in_stack_ffffffac,pCVar24);
      iVar4 = *(int *)pSVar7;
      if (*(int *)(pSVar6 + 0x124) != 0) {
        iVar1 = *(int *)(this + 100);
        in_stack_ffffff74 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
        in_stack_ffffff70 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fc21f;
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x14),in_stack_ffffff74,(ulong)in_stack_ffffff78);
        dVar25 = (double)CONCAT44(in_stack_ffffffac,pCVar24);
        fVar14 = *(float *)(*(int *)pSVar7 + 0xa4);
        if (!NAN(fVar14) && 0.0 < fVar14 != (fVar14 == 0.0)) {
          fVar14 = unaff_retaddr;
          if (*(int *)(pSVar6 + 300) != 0) {
            in_stack_ffffff74 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fc249;
            CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar1 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                       (ulong)fVar12);
            fVar14 = unaff_retaddr;
          }
          pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar1 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                              in_stack_ffffff44);
          fVar12 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed
                             (*(CSceneVehicleCarTuning **)pSVar7,
                              *(CSceneVehicleCarTuning **)((int)in_stack_fffffffc + 8),
                              in_stack_ffffff48);
          in_stack_ffffff70 =
               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               (*(float *)(iVar4 + 0x20) * in_stack_fffffff8 * fVar12 * (float)in_stack_ffffff74);
          in_stack_ffffff78 = *(float *)(pSVar6 + 0x148) - *(float *)(pSVar6 + 0x14c) * 0.0;
          fVar12 = *(float *)(pSVar6 + 0x14c) * 0.0 - *(float *)(pSVar6 + 0x144);
          fVar20 = *(float *)(pSVar6 + 0x144) * 0.0 - *(float *)(pSVar6 + 0x148) * 0.0;
          pCVar19 = (CFastBuffer<class_CCrystalFace*> *)
                    (fVar20 * fVar20 + fVar12 * fVar12 + in_stack_ffffff78 * in_stack_ffffff78);
          if ((float)pCVar19 <= _DAT_00d0ac60) {
            in_stack_ffffff78 = 1.0;
            in_stack_ffffff80 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            fVar12 = 0.0;
          }
          else {
            fVar11 = (float10)func_0x009c1b40();
            pCVar19 = (CFastBuffer<class_CCrystalFace*> *)(1.0 / (float)fVar11);
            in_stack_ffffff78 = (float)pCVar19 * in_stack_ffffff78;
            fVar12 = (float)pCVar19 * fVar12;
            in_stack_ffffff80 =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((float)pCVar19 * fVar20);
          }
          if (*(int *)(pSVar6 + 4) != 0) {
            __CIcos();
            in_stack_ffffffbc = (float)extraout_ST0;
            in_stack_ffffff78 = in_stack_ffffffbc * in_stack_ffffff78;
            in_stack_ffffffb8 = in_stack_ffffffbc * fVar12;
            in_stack_ffffffbc = in_stack_ffffffbc * (float)in_stack_ffffff80;
            __CIsin();
            in_stack_ffffffdc = -(float)extraout_ST0_00;
            pCVar19 = (CFastBuffer<class_CCrystalFace*> *)((float)_PTR_00b2c178 * in_stack_ffffffdc)
            ;
            in_stack_ffffff78 = in_stack_ffffff78 + (float)pCVar19;
            fVar12 = (float)pCVar19 + in_stack_ffffffb8;
            in_stack_ffffff80 =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 (in_stack_ffffffdc + in_stack_ffffffbc);
            in_stack_ffffffd8 = pCVar19;
          }
          iVar4 = *(int *)(this + 100);
          fVar20 = *(float *)((int)fVar14 + 4);
          in_stack_ffffffa4 = *(float *)((int)fVar14 + 8);
          in_stack_ffffff44 = 0x7fc41e;
          unaff_retaddr = fVar14;
          pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar4 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                              in_stack_ffffff4c);
          pGVar27 = (GmVec3 *)
                    (-*(float *)(*(int *)pSVar7 + 0xa4) * (float)_DAT_00b313b8 *
                    ((float)pCVar24 * (float)pCVar5 +
                    in_stack_ffffffa4 * (float)in_stack_ffffff80 + fVar20 * fVar12));
          fVar20 = ABS((float)pGVar27);
          if (fVar20 <= (float)in_stack_ffffff74) {
            *(undefined4 *)(pSVar6 + 300) = 0;
            pGVar21 = pGVar27;
          }
          else {
            pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar4 + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                                (ulong)in_stack_ffffff50);
            pGVar21 = *(GmVec3 **)(*(int *)pSVar7 + 0xb4);
            fVar12 = in_stack_ffffff78;
            if ((float)unaff_EBP <= 0.0) {
              fVar12 = -in_stack_ffffff78;
            }
            *(undefined4 *)(pSVar6 + 300) = 1;
            pGVar27 = (GmVec3 *)
                      ((1.0 - (float)pGVar21) * fVar12 + (float)pGVar21 * (float)unaff_EBP);
            unaff_EBP = pGVar27;
          }
          if (*(int *)(pSVar6 + 300) != 0) {
            *(undefined4 *)param_6 = 1;
          }
          in_stack_ffffffcc = (float)in_stack_ffffff80 * (float)pGVar27;
          in_stack_ffffffd0 = (float)pGVar27 * (float)pCVar5;
          in_stack_ffffff48 = 1.1733823e-38;
          AddVehicleCentralForce(this,(CSceneVehicleCar *)&stack0xffffffc8,in_stack_ffffff50);
          iVar4 = *(int *)(this + 100);
          in_stack_ffffff4c = 0x7fc52f;
          pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar4 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                              in_stack_ffffff54);
          this_00 = *(CSceneVehicleCarTuning **)pSVar6;
          in_stack_ffffff50 = (GmVec3 *)0x7fc53d;
          pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar4 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                              uVar18);
          unaff_EBX = (CSceneVehicleCarTuning *)ABS(in_stack_ffffff8c);
          in_stack_ffffff54 = 0x7fc558;
          fVar13 = CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle
                             (*(CSceneVehicleCarTuning **)pSVar6,unaff_EBX,(float)pCVar19);
          dVar25 = (double)fVar13;
          uVar18 = 0x7fc56a;
          fVar14 = CSceneVehicleCarTuning::GetRolloverLateralFromSpeed
                             (this_00,*(CSceneVehicleCarTuning **)((int)fVar14 + 8),fVar20);
          in_stack_ffffff74 =
               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               (fVar14 * param_4 *
               (float)(double)CONCAT44(in_stack_ffffffb0,(int)((ulonglong)dVar25 >> 0x20)));
          in_stack_fffffffc = -(float)in_stack_ffffff74;
          in_stack_ffffffc0 = (float)in_stack_ffffffe4 * in_stack_fffffffc - in_stack_ffffffe0 * 0.0
          ;
          in_stack_ffffffc4 = in_stack_ffffffdc * 0.0 - (float)in_stack_ffffffe4 * 0.0;
          in_stack_ffffffc8 = in_stack_ffffffe0 * 0.0 - in_stack_fffffffc * in_stack_ffffffdc;
          AddVehicleTorque(this,(CSceneVehicleCar *)&stack0xffffffc0,pGVar21);
        }
      }
      in_stack_ffffffac = (float)((ulonglong)dVar25 >> 0x20);
      pCVar24 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(SUB84(dVar25,0) + 1);
    } while (pCVar24 < pCVar5);
  }
  if (param_10 == (SBlendableVals *)0x0) {
    *(float *)(this + 0x628) = in_stack_ffffffac;
    return;
  }
  fVar11 = (float10)func_0x009c1b40();
  fVar12 = (float)fVar11;
  if (*(int *)(this + 0x60c) == 0) {
    if (*(float *)(this + 0x5cc) <= fVar12) {
      if ((float)_DAT_00b362c0 < *(float *)(this + 0x50)) goto LAB_007fc67c;
    }
    else if (*(float *)(this + 0x54) <= (float)_DAT_00b362c0) {
LAB_007fc67c:
      *(undefined4 *)(this + 0x5c4) = 0;
    }
    else {
      *(undefined4 *)(this + 0x5c4) = 1;
    }
  }
  pCVar24 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  do {
    pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (this + 0x2e8,pCVar24,(ulong)unaff_EBP);
    fVar14 = *(float *)(pSVar6 + 4);
    if (fVar14 == 0.0) {
      fVar20 = -*(float *)(this + 0x840);
    }
    else {
      fVar20 = *(float *)(this + 0x840);
    }
    fVar20 = fVar20 * (float)_DAT_00b313b8;
    iVar4 = *(int *)(this + 100);
    fVar13 = fVar20 * *(float *)(param_9 + 4) + *(float *)param_7;
    fVar16 = *(float *)(param_7 + 8) + 0.0;
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar4 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                        (ulong)unaff_EBX);
    if ((float)in_stack_ffffffe4 <= *(float *)(*(int *)pSVar7 + 0x74)) {
      __CIsin();
      fVar17 = (float)extraout_ST0_01;
      fVar26 = in_stack_ffffffbc;
    }
    else {
      fVar17 = 1.0;
      fVar26 = in_stack_ffffffbc;
    }
    unaff_EBP = (GmVec3 *)0x7fc761;
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar4 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                        (ulong)in_stack_ffffff70);
    unaff_EBX = (CSceneVehicleCarTuning *)0x7fc771;
    fVar15 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed
                       (*(CSceneVehicleCarTuning **)pSVar7,*(CSceneVehicleCarTuning **)(param_7 + 8)
                        ,(float)in_stack_ffffff74);
    fVar15 = fVar15 * *(float *)(in_stack_0000003c + 0xc);
    iVar4 = *(int *)(this + 100);
    in_stack_ffffff74 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24);
    in_stack_ffffff70 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fc78e;
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar4 + 0x14),in_stack_ffffff74,(ulong)fVar12);
    fVar22 = -*(float *)(*(int *)pSVar7 + 0xa4) * (float)_DAT_00b313b8 *
             (fVar15 * 0.0 + (float)pCVar24 + in_stack_ffffffac * 0.0);
    fVar23 = ABS(fVar22);
    in_stack_ffffffbc = fVar26;
    if ((float)pSVar6 < fVar23) {
      in_stack_ffffff74 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fc7eb;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar4 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                          (ulong)fVar20);
      fVar12 = 1.1734845e-38;
      pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar4 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                          (ulong)in_stack_ffffff80);
      in_stack_ffffffbc =
           fVar26 * (1.0 - *(float *)(*(int *)pSVar7 + 0xe4)) +
           in_stack_ffffffa4 * *(float *)(*(int *)pSVar8 + 0xe4);
      pCVar24 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fVar26 + (float)pCVar24);
      in_stack_ffffffac = in_stack_ffffffa4 + in_stack_ffffffac;
      in_stack_ffffffa4 = _DAT_00b2c060;
      if (-1 < (int)fVar13) {
        in_stack_ffffffa4 = 1.0;
      }
      in_stack_ffffffc8 = 1.4013e-45;
      fVar14 = param_2;
    }
    in_stack_ffffff80 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24);
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar4 + 0x14),in_stack_ffffff80,(ulong)pCVar5);
    fVar23 = *(float *)(*(int *)pSVar7 + 0x98) * fVar23;
    if (fVar14 != 0.0) {
      if (*(int *)((int)in_stack_ffffffd0 + 300) == 0) {
        in_stack_ffffffc4 = 1.0;
      }
      else {
        in_stack_ffffff80 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fc8c4;
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar4 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                            in_stack_ffffff88);
        in_stack_ffffffc4 = *(float *)(*(int *)pSVar7 + 0x9c);
      }
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7fc8e0;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar4 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                          (ulong)fVar17);
      dVar25 = (double)in_stack_ffffffa4;
      in_stack_ffffff88 = 0x7fc8f8;
      fVar14 = CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed
                         (*(CSceneVehicleCarTuning **)pSVar7,
                          *(CSceneVehicleCarTuning **)(param_7 + 8),fVar22);
      in_stack_ffffffd8 = SUB84(dVar25,0);
      pCVar24 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                ((float)(double)CONCAT44(in_stack_ffffffe0,(int)((ulonglong)dVar25 >> 0x20)) -
                (float)pSVar6 * fVar15 * *(float *)(this + 0x5e8) * fVar14 * in_stack_ffffffcc);
    }
    fVar14 = (float)pCVar24 * 0.0;
    fVar13 = fVar14 * 0.0 - in_stack_ffffffa4 * fVar14;
    fVar20 = (float)pCVar24 * in_stack_ffffffa4 - fVar14 * 0.0;
    in_stack_ffffffe4 = pCVar24;
    AddVehicleTorque(this,(CSceneVehicleCar *)&stack0xfffffff0,in_stack_ffffff94);
    in_stack_ffffffd8 = in_stack_ffffffd8 + 1;
  } while (in_stack_ffffffd8 < (CFastBuffer<class_CCrystalFace*> *)&DAT_00000004);
  this_01 = *(void **)(DAT_00d731e0 + 0x14);
  if (this_01 == (void *)0x0) {
    this_01 = (void *)(DAT_00d731e0 + 0xa0);
  }
  puVar9 = CMwTimerAdapter::GetTickTime(this_01,(CMwTimerAdapter *)unaff_EBP);
  uVar2 = *puVar9;
  if (in_stack_ffffffe0 != 0.0) {
    *(uint *)(this + 0x62c) = uVar2;
    if (pSVar6 == (SCasterCat *)0x0) {
      *(uint *)(this + 0x630) = uVar2;
    }
    *(uint *)(this + 0x634) = uVar2 - *(int *)(this + 0x630);
  }
  fVar12 = 1.0;
  if ((uVar2 == *(uint *)(this + 0x62c)) && (_DAT_00ba38fc < in_stack_ffffffc0)) {
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 100) + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                         (*(int *)(this + 100) + 0x24),(ulong)fVar23);
    in_stack_ffffffb8 =
         ((in_stack_ffffffc8 - in_stack_ffffffc4) / in_stack_ffffffc4) /
         *(float *)(*(int *)pSVar7 + 0x200);
    in_stack_ffffffc8 = 0.0;
    if ((in_stack_ffffffb8 < 0.0 == (in_stack_ffffffb8 == 0.0)) &&
       (in_stack_ffffffc8 = in_stack_ffffffb8,
       !NAN(in_stack_ffffffb8) && 1.0 < in_stack_ffffffb8 != (in_stack_ffffffb8 == 1.0))) {
      in_stack_ffffffc8 = 1.0;
    }
    fVar15 = 1.0 - in_stack_ffffffc8;
  }
  pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 100) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                       (*(int *)(this + 100) + 0x24),(ulong)fVar16);
  fVar16 = CSceneVehicleCarTuning::M5GetSlippingAccelFromSpeed
                     (*(CSceneVehicleCarTuning **)pSVar7,*(CSceneVehicleCarTuning **)(param_7 + 8),
                      in_stack_ffffffa4);
  pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 100) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                       (*(int *)(this + 100) + 0x24),(ulong)pCVar24);
  fVar17 = CSceneVehicleCarTuning::M5GetAccelFromSpeed
                     (*(CSceneVehicleCarTuning **)pSVar7,*(CSceneVehicleCarTuning **)(param_7 + 8),
                      fVar12);
  pGVar27 = (GmVec3 *)((1.0 - fVar16) * in_stack_ffffffc8 + fVar17 * fVar16);
  fVar12 = ABS(*(float *)(this + 0x58));
  if (_DAT_00ba38fc < fVar12) {
    *(uint *)(this + 0x648) = uVar2;
    *(float *)(this + 0x64c) = in_stack_ffffffe0;
  }
  uVar3 = *(uint *)(this + 0x648);
  uVar18 = 0;
  if (uVar3 <= uVar2) {
    iVar4 = *(int *)(this + 100);
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar4 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                        (ulong)fVar15);
    if ((uVar2 - uVar3 < *(uint *)(*(int *)pSVar7 + 0x1fc)) && (*(int *)(this + 0x64c) != 0)) {
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                ((void *)(iVar4 + 0x14),
                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),(ulong)pSVar6);
    }
  }
  iVar4 = *(int *)(this + 100);
  CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
            ((void *)(iVar4 + 0x14),
             *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
             (ulong)in_stack_ffffffb8);
  CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
            ((void *)(iVar4 + 0x14),
             *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
             (ulong)in_stack_ffffffbc);
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar4 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                      (ulong)fVar16);
  iVar1 = *(int *)pSVar6;
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar4 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                      (ulong)in_stack_ffffffc4);
  fVar16 = CSceneVehicleCarTuning::M5GetSteerSlowDownFromSpeed
                     (*(CSceneVehicleCarTuning **)pSVar6,
                      *(CSceneVehicleCarTuning **)(in_stack_0000007c + 8),fVar12);
  fVar16 = *(float *)(iVar1 + 0x7c) * fVar13 * fVar16;
  fVar12 = _DAT_00b2c060;
  if (*(int *)(this + 0x5c4) == 0) {
    fVar12 = 0.0;
  }
  if (*(int *)(this + 0x600) == 0) {
    fVar26 = 0.0;
  }
  else {
    fVar26 = *(float *)(this + 0x5f4);
  }
  pCVar19 = (CFastBuffer<class_CCrystalFace*> *)
            (((*(float *)(in_stack_00000090 + 4) * *(float *)(this + 0x50) +
              *(float *)(in_stack_00000090 + 4) * fVar12 * *(float *)(this + 0x54)) * param_5 +
             fVar14 * fVar26) - fVar16);
  if (*(int *)(this + 0x60c) != 0) {
    if (*(int *)(this + 0x600) == 0) {
      fVar12 = 0.0;
      pCVar19 = (CFastBuffer<class_CCrystalFace*> *)(fVar14 * 0.0);
    }
    else {
      fVar12 = *(float *)(this + 0x5f4);
      pCVar19 = (CFastBuffer<class_CCrystalFace*> *)(fVar14 * fVar12);
    }
  }
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (0.0 < *(float *)(in_stack_0000007c + 8)) {
    iVar4 = *(int *)(this + 100);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar4 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
               (ulong)in_stack_ffffffcc);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar4 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),(ulong)fVar17);
    if (*in_stack_0000009c == 0) {
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar4 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),uVar18)
      ;
      pCVar19 = *(CFastBuffer<class_CCrystalFace*> **)(*(int *)pSVar6 + 0x4c);
    }
    else {
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar4 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),uVar18)
      ;
      pCVar19 = *(CFastBuffer<class_CCrystalFace*> **)(*(int *)pSVar6 + 0x48);
    }
    fVar17 = (float)in_stack_0000009c[2] * (float)pCVar19;
    fVar13 = fVar17;
    if (fVar17 < fVar14) {
      pCVar24 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,in_stack_ffffffd8);
      pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      in_stack_0000007c = in_stack_00000090;
      fVar14 = fVar17;
      if (pCVar24 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                             (this + 0x2e8,pCVar10,(ulong)fVar12);
          pCVar10 = pCVar10 + 1;
          *(undefined4 *)(pSVar6 + 300) = 1;
          in_stack_0000007c = in_stack_00000090;
          fVar14 = fVar17;
        } while (pCVar10 < pCVar24);
      }
    }
  }
  iVar4 = in_stack_0000007c;
  if (*(float *)(in_stack_0000007c + 8) < 0.0) {
    if (*(int *)(this + 0x60c) == 0) goto LAB_007fce6d;
    iVar4 = *(int *)(this + 100);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar4 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),(ulong)fVar12);
    uVar18 = 0x7fcd7e;
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar4 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),(ulong)pCVar5);
    if (*in_stack_000000ac == 0) {
      pCVar5 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24);
      fVar12 = 1.1736916e-38;
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar4 + 0x14),pCVar5,(ulong)fVar16);
      pGVar27 = *(GmVec3 **)(*(int *)pSVar6 + 0x4c);
    }
    else {
      pCVar5 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24);
      fVar12 = 1.1736889e-38;
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar4 + 0x14),pCVar5,(ulong)fVar16);
      pGVar27 = *(GmVec3 **)(*(int *)pSVar6 + 0x48);
    }
    unaff_retaddr = (float)in_stack_000000ac[2] * (float)pGVar27;
    if (unaff_retaddr < in_stack_fffffffc) {
      fVar16 = 1.1737004e-38;
      pCVar24 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,pCVar19);
      if (pCVar24 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        param_12 = (float *)0x1;
        pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        do {
          pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                             (this + 0x2e8,pCVar10,uVar18);
          pCVar10 = pCVar10 + 1;
          *(undefined4 *)(pSVar6 + 300) = 1;
        } while (pCVar10 < pCVar24);
      }
    }
    fVar13 = -fVar13;
    iVar4 = in_stack_00000090;
  }
  if ((*(int *)(this + 0x60c) != 0) && (fVar20 = ABS(*(float *)(iVar4 + 8)), fVar20 < 1.0)) {
    fVar13 = fVar20 * fVar13;
  }
LAB_007fce6d:
  *in_stack_000000a8 = fVar13;
  iVar1 = *(int *)(this + 100);
  fVar13 = (float)pGVar27 - fVar13;
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                      (ulong)fVar12);
  fVar12 = *(float *)(*(int *)pSVar6 + 0x30);
  fVar17 = *in_stack_000000a4;
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                      (ulong)pCVar5);
  fVar26 = *(float *)(*(int *)pSVar6 + 0x2c) * *in_stack_000000a4;
  if (fVar26 < *(float *)(iVar4 + 8)) {
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        (ulong)fVar16);
    fVar26 = -*(float *)(*(int *)pSVar6 + 0x60);
  }
  if (*(float *)(iVar4 + 8) < -(float)param_12) {
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        (ulong)pCVar19);
    unaff_retaddr = *(float *)(*(int *)pSVar6 + 0x60);
  }
  fStack0000004c = fVar26 * in_stack_00000098;
  uStack00000044 = 0;
  fStack00000048 = 0.0;
  fVar16 = fStack0000004c;
  AddVehicleCentralForce(this,(CSceneVehicleCar *)&stack0x00000044,(GmVec3 *)pCVar19);
  if (fVar12 * fVar17 == 0.0) {
    iVar4 = *(int *)(this + 100);
    uStack00000044 = 0;
    fVar16 = unaff_retaddr;
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar4 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                        (ulong)fVar14);
    if (*(float *)(*(int *)pSVar6 + 500) < ABS((float)param_1)) {
      unaff_retaddr = _DAT_00b2c060;
      if (-1 < (int)param_1) {
        unaff_retaddr = 1.0;
      }
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar4 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                          (ulong)fVar13);
      param_1 = (CSceneVehicleCar *)(*(float *)(*(int *)pSVar6 + 500) * (float)param_1);
    }
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar4 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                        (ulong)fVar20);
    fStack00000048 = -param_2 * *(float *)(*(int *)pSVar6 + 0xc0);
    AddVehicleTorque(this,(CSceneVehicleCar *)&stack0x00000048,pGVar27);
  }
  iVar4 = *(int *)(this + 100);
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar4 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                      (ulong)fVar16);
  pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar4 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x24),
                      (ulong)unaff_retaddr);
  fStack00000074 =
       (-*(float *)(*(int *)pSVar6 + 100) * (float)in_stack_000000ac[2]) /
       *(float *)(*(int *)pSVar7 + 0x160);
  uStack0000006c = 0;
  uStack00000070 = 0;
  AddVehicleCentralForce(this,(CSceneVehicleCar *)&stack0x0000006c,(GmVec3 *)param_1);
  *(float *)(this + 0x628) = fStack0000004c;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ComputeForcesModel6
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::ComputeForcesModel6
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3,
          float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9,
          SBlendableVals *param_10,int *param_11,float *param_12)
{
{
  int iVar1;
  CFastBuffer<class_CCrystalFace*> *pCVar2;
  SCasterCat *pSVar3;
  undefined4 *puVar4;
  GmVec3 *pGVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  void *pvVar8;
  ulong *puVar9;
  float *pfVar10;
  SCasterCat *pSVar11;
  ulong uVar12;
  int iVar13;
  undefined4 unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  GmVec3 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar15;
  ulong unaff_EDI;
  CSceneVehicleCar *pCVar16;
  uint uVar17;
  int *piVar18;
  float10 fVar19;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST0_05;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  int in_stack_00000038;
  undefined4 *in_stack_0000003c;
  GmIso3 *in_stack_fffffe7c;
  ulong uVar24;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffe88;
  GmIso4 *in_stack_fffffe8c;
  CSceneVehicleCarTuning *in_stack_fffffe90;
  GmVec3 *in_stack_fffffe94;
  SSimulationWheel *pSVar25;
  ulong in_stack_fffffe98;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffea0;
  float in_stack_fffffea4;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffea8;
  CSceneVehicleCar *in_stack_fffffeac;
  CSceneVehicleCarTuning *pCVar26;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffeb0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffeb4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar27;
  CSceneVehicleCarTuning *pCVar28;
  float fVar29;
  GmVec3 *pGVar30;
  CSceneVehicleCar *pCVar31;
  CFastBuffer<class_CCrystalFace*> *pCVar32;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar33;
  float fVar34;
  ulong uVar35;
  SPlugFaceCull *pSVar36;
  SPlugFaceCull *pSVar37;
  undefined8 in_stack_fffffecc;
  ulonglong uVar38;
  double dVar39;
  undefined8 uVar40;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffed4;
  GmVec3 *pGVar41;
  GmVec3 *in_stack_fffffedc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffee0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffee4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffee8;
  double dVar42;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffef0;
  SCasterCat *pSStack_10c;
  int *piStack_108;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_104;
  CFastBuffer<class_CCrystalFace*> *pCStack_100;
  float fStack_fc;
  float fStack_f8;
  undefined8 uStack_f4;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_d8;
  SCasterCat *pSStack_d4;
  float fStack_d0;
  float *pfStack_cc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_c8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_c4;
  undefined1 auStack_c0 [8];
  float fStack_b8;
  float *pfStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  undefined8 uStack_9c;
  SCasterCat *pSStack_94;
  SCasterCat *pSStack_90;
  float fStack_8c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *apCStack_88 [3];
  undefined8 uStack_7c;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  GmVec3 *pGStack_24;
  SSimulationWheel *pSStack_20;
  int *piStack_1c;
  float fStack_14;
  int iStack_c;
  float fStack_4;
  
  uVar38 = CONCAT44((int)((ulonglong)in_stack_fffffecc >> 0x20),unaff_EBX);
  pCVar28 = (CSceneVehicleCarTuning *)0x7c3e99;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
  puVar4 = (undefined4 *)(**(code **)(**(int **)pSVar3 + 0x78))();
  pCVar16 = this + 0x6a4;
  for (iVar13 = 0xc; iVar13 != 0; iVar13 = iVar13 + -1) {
    *(undefined4 *)pCVar16 = *puVar4;
    puVar4 = puVar4 + 1;
    pCVar16 = pCVar16 + 4;
  }
  fStack_34 = *(float *)(this + 0x6b4);
  pGVar30 = (GmVec3 *)0x7c3ecc;
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3;
  pGVar5 = (GmVec3 *)ApplyWaterForces(this,(CSceneVehicleCar *)param_3,unaff_ESI);
  pCVar16 = this + 0x2e8;
  *(GmVec3 **)(this + 0x5e4) = pGVar5;
  pCVar33 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c3eeb;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(pCVar16,unaff_EBP);
  pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pCVar33 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c3efb;
      pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar16,pCVar14,(ulong)uVar38);
      if ((*(int *)(pSVar3 + 0x124) == 0) || (*(short *)(pSVar3 + 0x128) != 6)) {
        pSStack_10c = (SCasterCat *)0x0;
      }
      pCVar14 = pCVar14 + 1;
    } while (pCVar14 < pCVar6);
  }
  fStack_fc = *(float *)(this + 0x628);
  pSStack_d4 = (SCasterCat *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x50);
  fStack_e8 = 0.0;
  if (*(int *)(this + 0x69c) != 2) {
    pvVar8 = *(void **)(DAT_00d731e0 + 0x14);
    if (pvVar8 == (void *)0x0) {
      pvVar8 = (void *)(DAT_00d731e0 + 0xa0);
    }
    uVar35 = 0x7c4839;
    pfVar10 = (float *)CMwTimerAdapter::GetTickTime
                                 (pvVar8,(CMwTimerAdapter *)
                                         (CFastBuffer<class_CCrystalFace*> *)uVar38);
    fVar29 = *pfVar10;
    if (*(int *)(this + 0x69c) == 1) {
      fVar23 = *(float *)(this + 0x6f4);
      if ((uint)fVar23 <= (uint)fVar29) {
        pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)(this + 100) + 0x24);
        uVar24 = (ulong)(uVar38 >> 0x20);
        uVar38 = CONCAT44(uVar24,pCVar6);
        uVar35 = 0x7c4861;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(this + 100) + 0x14),pCVar6,uVar24);
        if ((uint)((int)fVar29 - (int)fVar23) < *(uint *)(*(int *)pSVar3 + 0x298)) {
          fStack_e0 = 1.4013e-45;
          goto LAB_007c4889;
        }
      }
      *(float *)(this + 0x6f8) = fVar29;
      *(undefined4 *)(this + 0x69c) = 3;
    }
LAB_007c4889:
    if (*(int *)(this + 0x69c) == 3) {
      fVar23 = *(float *)(this + 0x6f8);
      if ((uint)fVar23 <= (uint)fVar29) {
        pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)(this + 100) + 0x24);
        uVar38 = CONCAT44(pCVar6,0x7c48ab);
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(this + 100) + 0x14),pCVar6,(ulong)in_stack_fffffed4);
        if ((uint)((int)fVar29 - (int)fVar23) < *(uint *)(*(int *)pSVar3 + 0x2a8)) {
          in_stack_fffffed4 = (CFastBuffer<class_CCrystalFace*> *)0x7c48be;
          pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount
                             (pCVar16,(CFastBuffer<class_CCrystalFace*> *)pGVar5);
          pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            do {
              uVar24 = (ulong)(uVar38 >> 0x20);
              uVar38 = CONCAT44(uVar24,pCVar14);
              uVar35 = 0x7c48ce;
              pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                                 (pCVar16,pCVar14,uVar24);
              pCVar14 = pCVar14 + 1;
              *(undefined4 *)(pSVar3 + 300) = 1;
            } while (pCVar14 < pCVar6);
          }
          goto LAB_007c48ef;
        }
      }
      *(undefined4 *)(this + 0x69c) = 0;
      *(undefined4 *)(this + 0x6a0) = 0;
    }
LAB_007c48ef:
    fVar23 = (float)uVar38;
    pCVar31 = (CSceneVehicleCar *)0x7c48f6;
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(pCVar16,in_stack_fffffed4);
    pCStack_d8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (this + 0x2e8,pCStack_d8,(ulong)pGVar5);
        pCVar31 = (CSceneVehicleCar *)0x7c4932;
        WheelAddForceToVehicle
                  (this,(CSceneVehicleCar *)pSVar3,(SSimulationWheel *)param_9,in_stack_fffffedc);
        pGVar5 = (GmVec3 *)0x7c4942;
        pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this + 0x6c,
                             (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                             (uint)*(ushort *)(pSVar3 + 0x128),(ulong)in_stack_fffffee0);
        in_stack_fffffee0 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar11;
        in_stack_fffffedc = (GmVec3 *)0x7c4950;
        pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            ((void *)(*(int *)(this + 0x68) + 0x14),in_stack_fffffee0,
                             (ulong)in_stack_fffffee4);
        iVar13 = *(int *)pSVar11;
        if (*(int *)(pSVar3 + 0x124) != 0) {
          iVar1 = *(int *)(this + 100);
          in_stack_fffffee4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
          in_stack_fffffee0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c4971;
          pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              ((void *)(iVar1 + 0x14),in_stack_fffffee4,(ulong)in_stack_fffffee8);
          fVar34 = 0.0;
          fVar22 = *(float *)(*(int *)pSVar11 + 0xa4);
          if (!NAN(fVar22) && 0.0 < fVar22 != (fVar22 == 0.0)) {
            fStack_4c = *(float *)(pSVar3 + 0x108) - *pfStack_b4;
            fStack_48 = *(float *)(pSVar3 + 0x10c) - pfStack_b4[1];
            fStack_44 = *(float *)(pSVar3 + 0x110) - pfStack_b4[2];
            pSStack_d4 = (SCasterCat *)
                         (*(float *)(pSVar3 + 0x148) - *(float *)(pSVar3 + 0x14c) * 0.0);
            fStack_d0 = *(float *)(pSVar3 + 0x14c) * 0.0 - *(float *)(pSVar3 + 0x144);
            pfStack_cc = (float *)(*(float *)(pSVar3 + 0x144) * 0.0 -
                                  *(float *)(pSVar3 + 0x148) * 0.0);
            fStack_e4 = (float)pfStack_cc * (float)pfStack_cc +
                        fStack_d0 * fStack_d0 + (float)pSStack_d4 * (float)pSStack_d4;
            if (fStack_e4 <= _DAT_00d06a80) {
              pSStack_d4 = (SCasterCat *)0x3f800000;
              fStack_d0 = 0.0;
            }
            else {
              fVar19 = (float10)func_0x009c1b40();
              fStack_f8 = 1.0 / (float)fVar19;
              fStack_e8 = fStack_f8 * fStack_e8;
              fStack_e4 = fStack_f8 * fStack_e4;
              fVar34 = fStack_f8 * fStack_e0;
            }
            fStack_e0 = fVar34;
            if (*(int *)(pSVar3 + 4) != 0) {
              __CIcos();
              fStack_f8 = (float)extraout_ST0_00;
              uStack_9c._4_4_ = fStack_f8 * fStack_e8;
              pSStack_94 = (SCasterCat *)(fStack_f8 * fStack_e4);
              pSStack_90 = (SCasterCat *)(fStack_f8 * fStack_e0);
              __CIsin();
              fStack_70 = -(float)extraout_ST0_01;
              fStack_f8 = (float)_PTR_00b2c178 * fStack_70;
              uStack_7c = (double)CONCAT44(fStack_f8,(float)uStack_7c);
              fStack_e8 = uStack_9c._4_4_ + fStack_f8;
              fStack_e4 = fStack_f8 + (float)pSStack_94;
              fStack_e0 = fStack_70 + (float)pSStack_90;
              fStack_74 = fStack_f8;
            }
            pSStack_d4 = (SCasterCat *)*param_11;
            fStack_d0 = (float)param_11[1];
            pfStack_cc = (float *)param_11[2];
            pSStack_10c = (SCasterCat *)
                          ((float)pfStack_cc * fStack_e0 +
                          fStack_d0 * fStack_e4 + (float)pSStack_d4 * fStack_e8);
            uVar40 = CONCAT44(0x7c4ba0,fVar23);
            pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                ((void *)(iVar1 + 0x14),
                                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                                 (ulong)pGVar5);
            fStack_60 = -*(float *)(*(int *)pSVar11 + 0x228);
            fStack_68 = fStack_60 * *(float *)(this + 0x6d4);
            fStack_64 = *(float *)(this + 0x6d8) * fStack_60;
            fStack_60 = fStack_60 * *(float *)(this + 0x6dc);
            uStack_7c = (double)fStack_68;
            unique0x0000aa00 = (double)fStack_64;
            uStack_f4 = (double)fStack_60;
            pGVar41 = (GmVec3 *)0x7c4c11;
            pSStack_94 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   ((void *)(iVar1 + 0x14),
                                    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (iVar1 + 0x24),(ulong)in_stack_fffffedc);
            uStack_f4._4_4_ =
                 (float)((float10)(double)CONCAT44(fStack_ec,uStack_f4._4_4_) *
                         (float10)(double)CONCAT44(fStack_ec,uStack_f4._4_4_) +
                        (float10)(double)CONCAT44(fStack_74,uStack_7c._4_4_) *
                        (float10)(double)CONCAT44(fStack_74,uStack_7c._4_4_) +
                        (float10)(double)CONCAT44(pfStack_b4,fStack_b8) *
                        (float10)(double)CONCAT44(pfStack_b4,fStack_b8));
            fVar19 = (float10)func_0x009c1b40();
            if ((float)fVar19 < *(float *)((int)*pfStack_cc + 0x234)) {
              pSStack_94 = (SCasterCat *)0x0;
              uStack_9c._4_4_ = 0.0;
              uStack_9c._0_4_ = 0.0;
            }
            fStack_d0 = (float)_DAT_00b55920;
            pCStack_d8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                         ((fStack_8c * (float)pSStack_94 - (float)apCStack_88[0] * uStack_9c._4_4_)
                         * fStack_d0);
            pSStack_d4 = (SCasterCat *)
                         (((float)uStack_9c * (float)apCStack_88[0] -
                          (float)pSStack_90 * (float)pSStack_94) * fStack_d0);
            fStack_d0 = fStack_d0 *
                        (uStack_9c._4_4_ * (float)pSStack_90 - fStack_8c * (float)uStack_9c);
            in_stack_fffffea0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c4d1a;
            pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                ((void *)(iVar1 + 0x14),
                                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                                 (ulong)in_stack_fffffea8);
            in_stack_fffffedc = (GmVec3 *)(*(float *)(*(int *)pSVar11 + 0x23c) * (float)pfStack_cc);
            pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                ((void *)(iVar1 + 0x14),
                                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                                 (ulong)in_stack_fffffeac);
            in_stack_fffffeac = (CSceneVehicleCar *)&fStack_d0;
            fStack_d0 = *(float *)(*(int *)pSVar11 + 0x238) * fStack_d0;
            pfStack_cc = (float *)0x0;
            in_stack_fffffea8 = (CFastBuffer<class_CCrystalFace*> *)0x7c4d72;
            pCStack_c8 = in_stack_fffffee0;
            AddVehicleTorque(this,in_stack_fffffeac,(GmVec3 *)in_stack_fffffeb0);
            if (*(int *)(this + 0x69c) == 1) {
              in_stack_fffffeac = (CSceneVehicleCar *)0x7c4d8a;
              pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  ((void *)(*(int *)(this + 100) + 0x14),
                                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                    (*(int *)(this + 100) + 0x24),(ulong)in_stack_fffffeb4);
              in_stack_fffffeb0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c4da1;
              fStack_64 = CSceneVehicleCarTuning::M6GetBurnoutRolloverFromSpeed
                                    (*(CSceneVehicleCarTuning **)pSVar11,
                                     *(CSceneVehicleCarTuning **)(param_3 + 8),(float)pCVar28);
              fStack_60 = 0.0;
              uStack_5c = 0;
              in_stack_fffffeb4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c4dc7;
              AddVehicleTorque(this,(CSceneVehicleCar *)&fStack_64,pGVar30);
            }
            pGVar5 = (GmVec3 *)0x3f800000;
            if (*(int *)(this + 0x69c) == 1) {
              iVar1 = *(int *)(this + 100);
              pSStack_10c = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                      ((void *)(iVar1 + 0x14),
                                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                        (iVar1 + 0x24),(ulong)pCVar7);
              pCVar7 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
              pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  ((void *)(iVar1 + 0x14),pCVar7,(ulong)pCVar33);
              fStack_d0 = (float)(*(int *)(*piStack_108 + 0x298) * 2);
              pCVar33 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c4e4c;
              __CIcos();
              in_stack_fffffee0 =
                   (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   ((*(float *)(*(int *)pSVar11 + 0x2a0) - 1.0) * (float)extraout_ST0_02 + 1.0);
            }
            pCVar28 = (CSceneVehicleCarTuning *)0x7c4e77;
            pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                ((void *)(*(int *)(this + 100) + 0x14),
                                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                  (*(int *)(this + 100) + 0x24),(ulong)pCVar7);
            pGVar30 = (GmVec3 *)0x7c4e8a;
            CSceneVehicleCarTuning::M6GetModulationFromDamperAbsorbVal
                      (*(CSceneVehicleCarTuning **)pSVar11,
                       *(CSceneVehicleCarTuning **)(pSVar3 + 0xb4),(float)pCVar33);
            if (*(int *)(pSVar3 + 300) == 0) {
              in_stack_fffffee8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
LAB_007c4ee4:
              pSStack_d4 = (SCasterCat *)0x3f800000;
            }
            else {
              pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  ((void *)(*(int *)(this + 100) + 0x14),
                                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                    (*(int *)(this + 100) + 0x24),uVar35);
              in_stack_fffffee8 =
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)pSVar11 + 0xb0);
              if (*(float *)(this + 0x54) <= (float)_DAT_00b362c0) goto LAB_007c4ee4;
              pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  ((void *)(*(int *)(this + 100) + 0x14),
                                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                    (*(int *)(this + 100) + 0x24),uVar35);
              pSStack_d4 = *(SCasterCat **)(*(int *)pSVar11 + 0x244);
            }
            pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c4ef9;
            pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                ((void *)(*(int *)(this + 100) + 0x14),
                                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                  (*(int *)(this + 100) + 0x24),uVar35);
            pCVar33 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c4f10;
            fVar23 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed
                               (*(CSceneVehicleCarTuning **)pSVar11,
                                *(CSceneVehicleCarTuning **)((int)param_8 + 8),(float)uVar40);
            iVar1 = *(int *)(this + 100);
            piStack_108 = (int *)(*(float *)(iVar13 + 0x20) * (float)param_7 * fVar23 *
                                  (float)in_stack_fffffef0 * (float)pfStack_cc * (float)pCStack_100)
            ;
            uVar35 = 0x7c4f3b;
            pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                ((void *)(iVar1 + 0x14),
                                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                                 (ulong)((ulonglong)uVar40 >> 0x20));
            pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      (-*(float *)(*(int *)pSVar11 + 0xa4) * (float)_DAT_00b313b8 *
                       (float)in_stack_fffffef0 * (float)pCVar6);
            in_stack_fffffef0 =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)ABS((float)pCVar14);
            pCVar6 = pCVar14;
            if ((float)in_stack_fffffef0 <= fVar29) {
              *(undefined4 *)(pSVar3 + 300) = 0;
            }
            else {
              pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  ((void *)(iVar1 + 0x14),
                                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                    (iVar1 + 0x24),(ulong)pGVar41);
              pSStack_10c = *(SCasterCat **)(*(int *)pSVar11 + 0xb4);
              piStack_108 = (int *)pCStack_100;
              if ((float)in_stack_fffffef0 <= 0.0) {
                piStack_108 = (int *)-(float)pCStack_100;
              }
              *(undefined4 *)(pSVar3 + 300) = 1;
              pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        ((1.0 - (float)pSStack_10c) * (float)piStack_108 +
                        (float)pSStack_10c * (float)in_stack_fffffef0);
              in_stack_fffffef0 = pCVar14;
            }
            if (*(int *)(pSVar3 + 300) != 0) {
              *in_stack_0000003c = 1;
            }
            pSStack_90 = (SCasterCat *)((float)pCVar14 * fStack_ec);
            fStack_8c = (float)pCVar14 * fStack_e8;
            apCStack_88[0] =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fStack_e4 * (float)pCVar14);
            dVar39 = unique0x1000392f;
            if ((piStack_108 != (int *)0x0) && (_DAT_00b3d620 < *(float *)(param_10 + 8))) {
              uStack_2c = 0;
              fStack_30 = 0.0;
              fStack_34 = 0.0;
              uStack_50 = 0;
              uStack_54 = 0;
              uStack_58 = 0;
              fStack_b8 = *(float *)param_10;
              pfStack_b4 = *(float **)(param_10 + 4);
              fStack_b0 = *(float *)(param_10 + 8);
              in_stack_fffffef0 =
                   (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   (fStack_b0 * fStack_b0 +
                   fStack_b8 * fStack_b8 + (float)pfStack_b4 * (float)pfStack_b4);
              if (_DAT_00d06a80 < (float)in_stack_fffffef0) {
                fVar19 = (float10)func_0x009c1b40();
                in_stack_fffffef0 =
                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(1.0 / (float)fVar19);
                fStack_b8 = (float)in_stack_fffffef0 * fStack_b8;
              }
              fVar23 = (float)_DAT_00b362c0;
              if (fVar23 < *(float *)(this + 0x54)) {
                fStack_38 = (float)_DAT_00b362b8;
                fStack_40 = *(float *)param_10 * fStack_38;
                fStack_3c = *(float *)(param_10 + 4) * fStack_38;
                fStack_38 = fStack_38 * *(float *)(param_10 + 8);
                AddVehicleCentralForce(this,(CSceneVehicleCar *)&fStack_40,pGVar41);
                fVar23 = (float)_DAT_00b362c0;
              }
              if (((*(int *)(this + 0x60c) == 0) && (fVar23 < *(float *)(this + 0x50))) &&
                 (auStack_c0 = (undefined1  [8])CONCAT44(auStack_c0._4_4_,auStack_c0._0_4_),
                 *(float *)(this + 0x54) < fVar23 != (*(float *)(this + 0x54) == fVar23))) {
                iVar13 = *(int *)(this + 100);
                pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   ((void *)(iVar13 + 0x14),
                                    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (iVar13 + 0x24),(ulong)pGVar41);
                in_stack_fffffef0 =
                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)ABS((float)pfStack_b4);
                auStack_c0 = (undefined1  [8])
                             (double)((float)in_stack_fffffef0 * (float)_DAT_00b48cb8 +
                                     (float)_DAT_00b2c188);
                pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    ((void *)(iVar13 + 0x14),
                                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                      (iVar13 + 0x24),(ulong)pGVar5);
                fVar23 = (ABS(*(float *)(param_10 + 8)) + (float)_DAT_00b2c188) *
                         (ABS(*(float *)(param_10 + 8)) + (float)_DAT_00b2c188);
                uStack_7c = (double)fVar23;
                piStack_108 = (int *)((*(float *)(*(int *)pSVar3 + 0x348) * *(float *)(this + 0x50)
                                       * (float)_DAT_00b38328 * (float)pSStack_10c *
                                       (float)(double)CONCAT44(fStack_b8,auStack_c0._4_4_) *
                                      *(float *)(*(int *)pSVar11 + 0x344)) / fVar23);
                pGVar41 = (GmVec3 *)0x7c51f4;
                pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   ((void *)(iVar13 + 0x14),
                                    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (iVar13 + 0x24),(ulong)in_stack_fffffedc);
                pGVar5 = (GmVec3 *)0x7c5202;
                pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    ((void *)(iVar13 + 0x14),
                                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                      (iVar13 + 0x24),(ulong)in_stack_fffffee0);
                pGStack_24 = (GmVec3 *)
                             ((*(float *)(*(int *)pSVar3 + 0x33c) * fStack_a8) /
                             (*(float *)(*(int *)pSVar11 + 0x340) * *(float *)(this + 0x50) +
                             (float)_DAT_00b2c188));
                pSStack_20 = (SSimulationWheel *)0x0;
                piStack_1c = (int *)pCStack_100;
                in_stack_fffffedc = (GmVec3 *)0x7c5248;
                pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   ((void *)(iVar13 + 0x14),
                                    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (iVar13 + 0x24),(ulong)in_stack_fffffee4);
                in_stack_fffffee0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c5256;
                pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    ((void *)(iVar13 + 0x14),
                                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                      (iVar13 + 0x24),(ulong)in_stack_fffffee8);
                fStack_f8 = (*(float *)(*(int *)pSVar3 + 0x348) * *(float *)(this + 0x50) *
                             fStack_fc * (float)(double)CONCAT44(fStack_a8,fStack_ac) *
                            *(float *)(*(int *)pSVar11 + 0x344)) /
                            (float)(double)CONCAT44(fStack_68,fStack_6c);
                in_stack_fffffee4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c5288;
                pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   ((void *)(iVar13 + 0x14),
                                    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (iVar13 + 0x24),(ulong)pCVar6);
                pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24);
                in_stack_fffffee8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c5296;
                pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    ((void *)(iVar13 + 0x14),pCVar6,(ulong)in_stack_fffffef0);
                fStack_38 = (uStack_9c._4_4_ * (float)_DAT_00b55920 *
                            *(float *)(*(int *)pSVar3 + 0x33c)) /
                            (*(float *)(*(int *)pSVar11 + 0x340) * *(float *)(this + 0x50) +
                            (float)_DAT_00b2c188);
                fStack_34 = 0.0;
                fStack_30 = uStack_f4._4_4_;
              }
              pSStack_10c = (SCasterCat *)
                            CFastBuffer<class_CCrystalFace*>::GetCount
                                      (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)pGVar41);
              pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              dVar39 = (double)CONCAT44(fStack_b8,auStack_c0._4_4_);
              if (pSStack_10c != (SCasterCat *)0x0) {
                do {
                  pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                                     (this + 0x2e8,pCVar14,(ulong)pGVar41);
                  if (((pCVar14 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) ||
                      (pCVar14 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1)) &&
                     ((*(float *)(this + 0x54) < (float)_DAT_00b362c0 !=
                       (*(float *)(this + 0x54) == (float)_DAT_00b362c0) &&
                      (*(int *)(pSVar3 + 300) != 0)))) {
                    pGVar41 = (GmVec3 *)(pSVar3 + 0xa8);
                    AddVehicleForce(this,(CSceneVehicleCar *)&fStack_30,pGVar41,pGVar5);
                  }
                  if (((pCVar14 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2) ||
                      (pCVar14 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3)) &&
                     ((*(float *)(this + 0x54) < (float)_DAT_00b362c0 !=
                       (*(float *)(this + 0x54) == (float)_DAT_00b362c0) &&
                      (*(int *)(pSVar3 + 300) != 0)))) {
                    pGVar5 = (GmVec3 *)(pSVar3 + 0xa8);
                    pGVar41 = (GmVec3 *)&uStack_50;
                    AddVehicleForce(this,(CSceneVehicleCar *)pGVar41,pGVar5,in_stack_fffffedc);
                  }
                  pCVar14 = pCVar14 + 1;
                } while (pCVar14 < in_stack_fffffef0);
                pCVar31 = (CSceneVehicleCar *)&pSStack_90;
                fVar23 = 1.1417575e-38;
                AddVehicleCentralForce(this,pCVar31,pGVar41);
                goto LAB_007c53a5;
              }
            }
            pCVar31 = (CSceneVehicleCar *)&pSStack_90;
            fVar23 = 1.1417602e-38;
            unique0x10004537 = dVar39;
            AddVehicleCentralForce(this,pCVar31,pGVar41);
          }
        }
LAB_007c53a5:
        pCStack_d8 = pCStack_d8 + 1;
      } while (pCStack_d8 < pCVar6);
    }
    if (in_stack_00000038 == 0) {
      if (*(int *)(this + 0x69c) == 1) {
        *(float *)(this + 0x6f8) = fStack_fc;
        *(undefined4 *)(this + 0x69c) = 3;
      }
    }
    else {
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               ((float)param_11[2] * (float)param_11[2] +
               (float)*param_11 * (float)*param_11 + (float)param_11[1] * (float)param_11[1]);
      pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c53f5;
      fVar19 = (float10)func_0x009c1b40();
      dVar39 = _DAT_00b362c0;
      fStack_ec = (float)fVar19;
      if ((((*(int *)(this + 0x60c) == 0) && ((float)_DAT_00b362c0 < *(float *)(this + 0x54))) &&
          (*(float *)(this + 0x50) < (float)_DAT_00b362c0)) && (*(int *)(this + 0x69c) == 1)) {
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x6f8) = in_stack_fffffeb4;
        *(undefined4 *)(this + 0x69c) = 3;
      }
      fVar29 = (float)dVar39;
      if (*(int *)(this + 0x60c) == 0) {
        if ((fVar29 < *(float *)(this + 0x50)) && (fVar29 < *(float *)(this + 0x54))) {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(*(int *)(this + 100) + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                               (*(int *)(this + 100) + 0x24),(ulong)in_stack_fffffe88);
          if (((float)param_11[2] < *(float *)(*(int *)pSVar3 + 600)) && (_DAT_00b2c05c < fStack_6c)
             ) {
            *(undefined4 *)(this + 0x69c) = 1;
            *(undefined4 *)(this + 0x6a0) = 1;
            *(CSceneVehicleCarTuning **)(this + 0x6f4) = pCVar28;
          }
          fVar29 = (float)_DAT_00b362c0;
        }
        if ((fVar29 < *(float *)(this + 0x50)) && (fVar29 < *(float *)(this + 0x54))) {
          iVar13 = *(int *)(this + 100);
          uVar35 = 0x7c5506;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar13 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                              (ulong)in_stack_fffffe88);
          if ((float)param_11[2] < *(float *)(*(int *)pSVar3 + 0x254)) {
            in_stack_fffffe88 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24);
            uVar24 = 0x7c552a;
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar13 + 0x14),in_stack_fffffe88,(ulong)in_stack_fffffe8c);
            if ((*(float *)(*(int *)pSVar3 + 600) < (float)param_11[2]) &&
               (_DAT_00b9ef4c <= ABS(fStack_14))) {
              *(undefined4 *)(this + 0x69c) = 2;
              in_stack_fffffeb4 = _DAT_00b2c060;
              if (-1 < (int)fStack_14) {
                in_stack_fffffeb4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
              }
              pCVar16 = this + 0x6fc;
              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x708) = in_stack_fffffeb4
              ;
              *(undefined4 *)(this + 0x704) = 0;
              *(undefined4 *)(this + 0x700) = 0;
              *(float *)pCVar16 = 0.0;
              in_stack_fffffe8c = (GmIso4 *)0x7c55b1;
              uVar12 = CFastBuffer<class_CCrystalFace*>::GetCount
                                 (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffe88
                                 );
              pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              if (uVar12 != 0) {
                do {
                  in_stack_fffffe8c = (GmIso4 *)0x7c55cc;
                  pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                                     (this + 0x2e8,pCVar7,(ulong)in_stack_fffffe94);
                  if (*(int *)(pSVar3 + 0x124) != 0) {
                    *(float *)pCVar16 = *(float *)(pSVar3 + 0x144) + *(float *)pCVar16;
                    *(float *)(this + 0x700) = *(float *)(pSVar3 + 0x148) + *(float *)(this + 0x700)
                    ;
                    *(float *)(this + 0x704) = *(float *)(pSVar3 + 0x14c) + *(float *)(this + 0x704)
                    ;
                  }
                  pCVar7 = pCVar7 + 1;
                } while (pCVar7 < in_stack_fffffeac);
              }
              if (*(float *)(this + 0x704) * *(float *)(this + 0x704) +
                  *(float *)pCVar16 * *(float *)pCVar16 +
                  *(float *)(this + 0x700) * *(float *)(this + 0x700) <= _DAT_00d06a80) {
                *(undefined4 *)(this + 0x69c) = 0;
                fVar29 = 0.0;
                *(float *)pCVar16 = 0.0;
                *(undefined4 *)(this + 0x700) = 0x3f800000;
              }
              else {
                fVar19 = (float10)func_0x009c1b40();
                fVar29 = 1.0 / (float)fVar19;
                *(float *)pCVar16 = fVar29 * *(float *)pCVar16;
                *(float *)(this + 0x700) = *(float *)(this + 0x700) * fVar29;
                fVar29 = fVar29 * *(float *)(this + 0x704);
              }
              *(float *)(this + 0x704) = fVar29;
              fStack_dc = *(float *)(this + 0x1dc) - *(float *)pSStack_10c;
              pCStack_d8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                           (*(float *)(this + 0x1e0) - *(float *)(pSStack_10c + 4));
              pSStack_d4 = (SCasterCat *)(*(float *)(this + 0x1e4) - *(float *)(pSStack_10c + 8));
              in_stack_fffffef0 =
                   (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   (*(float *)(this + 0x1f0) +
                   *(float *)(this + 0x1e8) * 0.0 + *(float *)(this + 0x1ec) * 0.0);
              in_stack_fffffee8 =
                   (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   ((float)in_stack_fffffef0 * 0.0);
              auStack_c0._4_4_ = (float)in_stack_fffffee8 + fStack_dc;
              fStack_b8 = (float)in_stack_fffffee8 + (float)pCStack_d8;
              pfStack_b4 = (float *)((float)in_stack_fffffef0 + (float)pSStack_d4);
              in_stack_fffffea8 =
                   (CFastBuffer<class_CCrystalFace*> *)
                   ((float)pfStack_b4 * (float)pfStack_b4 +
                   (float)auStack_c0._4_4_ * (float)auStack_c0._4_4_ + fStack_b8 * fStack_b8);
              pCVar6 = in_stack_fffffee8;
              fVar19 = (float10)func_0x009c1b40();
              *(float *)(this + 0x6ec) = (float)fVar19;
              in_stack_fffffea0 = _DAT_00b2c060;
              if (-1 < iStack_28) {
                in_stack_fffffea0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
              }
              fVar29 = (float)in_stack_fffffea0 *
                       (*(float *)(this + 0x700) * (float)param_11[2] -
                       *(float *)(this + 0x704) * (float)param_11[1]);
              pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       ((float)in_stack_fffffea0 *
                       (*(float *)(this + 0x704) * (float)*param_11 -
                       *(float *)pCVar16 * (float)param_11[2]));
              pCVar33 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        ((float)in_stack_fffffea0 *
                        (*(float *)pCVar16 * (float)param_11[1] -
                        *(float *)(this + 0x700) * (float)*param_11));
              in_stack_fffffe90 =
                   (CSceneVehicleCarTuning *)
                   ((float)pCVar7 * (float)pCVar7 + fVar29 * fVar29 +
                   (float)pCVar33 * (float)pCVar33);
              if (_DAT_00d06a80 < (float)in_stack_fffffe90) {
                fVar19 = (float10)func_0x009c1b40();
                in_stack_fffffe90 = (CSceneVehicleCarTuning *)(1.0 / (float)fVar19);
                pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                         ((float)in_stack_fffffe90 * (float)pCVar7);
                pCVar33 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                          ((float)in_stack_fffffe90 * (float)pCVar33);
              }
              GmVec3::Mult(pCVar16,(GmIso3 *)(this + 0x6a4),in_stack_fffffe7c);
              if (*(float *)(this + 0x700) < _DAT_00b2c05c) {
                *(undefined4 *)(this + 0x69c) = 0;
                *(float *)pCVar16 = 0.0;
                *(undefined4 *)(this + 0x700) = 0x3f800000;
                *(undefined4 *)(this + 0x704) = 0;
              }
              fStack_e4 = 0.0;
              fStack_e0 = 0.0;
              fStack_dc = 1.0;
              in_stack_fffffe94 = pGStack_24;
              GmVec3::GetAngle((GmVec3 *)&fStack_e4,(GmVec3 *)&stack0xfffffec0);
              iVar13 = *(int *)(this + 100);
              pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(iVar13 + 0x14),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (iVar13 + 0x24),uVar35);
              if (*(float *)(*(int *)pSVar3 + 0x290) < (float)in_stack_fffffea8) {
LAB_007c59f6:
                *(undefined4 *)(this + 0x69c) = 0;
              }
              else {
                pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   ((void *)(iVar13 + 0x14),
                                    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (iVar13 + 0x24),uVar24);
                if ((float)in_stack_fffffeac < -*(float *)(*(int *)pSVar3 + 0x294))
                goto LAB_007c59f6;
                GmVec3::SetMult(&fStack_dc,(SPlugFaceCull *)&stack0xfffffec8,
                                (SPlugFaceCull *)(this + 0x6a4),(GmIso4 *)in_stack_fffffe88);
                GmVec3::SetMult(apCStack_88,(SPlugFaceCull *)pSStack_10c,
                                (SPlugFaceCull *)(this + 0x6a4),in_stack_fffffe8c);
                in_stack_fffffe88 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c5960;
                pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   ((void *)(*(int *)(this + 100) + 0x14),
                                    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (*(int *)(this + 100) + 0x24),(ulong)in_stack_fffffe90);
                in_stack_fffffe90 = (CSceneVehicleCarTuning *)param_11[2];
                in_stack_fffffe8c = (GmIso4 *)0x7c5970;
                fVar29 = CSceneVehicleCarTuning::M6GetBurnoutRadiusFromSpeed
                                   (*(CSceneVehicleCarTuning **)pSVar3,in_stack_fffffe90,
                                    (float)in_stack_fffffe94);
                fVar29 = fVar29 + *(float *)(this + 0x6ec);
                *(float *)(this + 0x6f0) = fVar29;
                *(float *)(this + 0x6e0) = fVar29 * (float)pfStack_cc;
                *(float *)(this + 0x6e4) = fVar29 * (float)pCStack_c8;
                *(float *)(this + 0x6e8) = fVar29 * (float)pCStack_c4;
                *(float *)(this + 0x6e0) = (float)uStack_7c + *(float *)(this + 0x6e0);
                *(float *)(this + 0x6e4) = *(float *)(this + 0x6e4) + uStack_7c._4_4_;
                *(float *)(this + 0x6e8) = fStack_74 + *(float *)(this + 0x6e8);
              }
              *(uint *)(this + 0x6a0) = (uint)(*(int *)(this + 0x69c) == 2);
            }
          }
          fVar29 = (float)_DAT_00b362c0;
        }
      }
      fVar22 = _DAT_00b313ac;
      if (*(int *)(this + 0x69c) == 0) {
        if (((fVar29 < *(float *)(this + 0x54)) && ((float)param_11[2] < *(float *)(this + 0x5cc)))
           && (ABS((float)*param_11) < _DAT_00b313ac)) {
          *(undefined4 *)(this + 0x5c4) = 1;
        }
        if ((fVar29 < *(float *)(this + 0x50)) &&
           ((0.0 < (float)param_11[2] || (fVar22 < ABS((float)*param_11))))) {
          *(undefined4 *)(this + 0x5c4) = 0;
        }
        if ((*(float *)(this + 0x50) < fVar29) && (*(float *)(this + 0x54) < fVar29)) {
          fVar29 = (float)param_11[2];
          if ((!NAN(fVar29) && 0.0 < fVar29 != (fVar29 == 0.0)) ||
             (ABS((float)param_11[2]) < fVar22)) {
            *(undefined4 *)(this + 0x5c4) = 0;
          }
          else {
            *(undefined4 *)(this + 0x5c4) = 1;
          }
        }
        if ((0.0 < (float)param_11[2]) && (*(int *)(this + 0x600) != 0)) goto LAB_007c5b0e;
      }
      else {
LAB_007c5b0e:
        *(undefined4 *)(this + 0x5c4) = 0;
      }
      fVar29 = -(float)*param_11;
      pCVar15 = _DAT_00b2c060;
      if (-1 < (int)fVar29) {
        pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
      }
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)in_stack_fffffe88);
      fVar22 = CSceneVehicleCarTuning::M6GetRolloverLateralFromSpeedRatio
                         (*(CSceneVehicleCarTuning **)pSVar3,
                          (CSceneVehicleCarTuning *)in_stack_fffffea8,(float)in_stack_fffffe8c);
      in_stack_fffffeb4 =
           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fVar22 * (float)in_stack_fffffeb4);
      pSStack_90 = (SCasterCat *)0x0;
      fStack_8c = 0.0;
      apCStack_88[0] = in_stack_fffffeb4;
      AddVehicleTorque(this,(CSceneVehicleCar *)&pSStack_90,(GmVec3 *)in_stack_fffffe90);
      pCVar27 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pCVar32 = (CFastBuffer<class_CCrystalFace*> *)0x0;
      pCStack_100 = (CFastBuffer<class_CCrystalFace*> *)
                    CFastBuffer<class_CCrystalFace*>::GetCount
                              (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffe94);
      pCStack_104 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCStack_100 != (CFastBuffer<class_CCrystalFace*> *)0x0) {
        pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)ABS(fStack_dc);
        do {
          pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                             (this + 0x2e8,pCStack_104,in_stack_fffffe98);
          iVar13 = *(int *)(pSVar3 + 4);
          if (iVar13 == 0) {
            fVar23 = -*(float *)(this + 0x840);
          }
          else {
            fVar23 = *(float *)(this + 0x840);
          }
          iVar1 = *(int *)(this + 100);
          uStack_f4._4_4_ =
               *(float *)(iStack_c + 4) * fVar23 * (float)_DAT_00b313b8 + (float)*param_11;
          fStack_ec = (float)param_11[1] + 0.0;
          fStack_e8 = (float)param_11[2] + 0.0;
          pGVar30 = (GmVec3 *)0x7c5c5f;
          auStack_c0._4_4_ = pSVar3;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar1 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                              (ulong)fVar29);
          pCVar32 = *(CFastBuffer<class_CCrystalFace*> **)(*(int *)pSVar3 + 0x74);
          if (_DAT_00b36134 <= (float)pCVar27) {
            if ((float)pSStack_d4 <= (float)pCVar32) {
              __CIsin();
              pCStack_100 = (CFastBuffer<class_CCrystalFace*> *)(float)extraout_ST0_03;
              pCVar32 = pCStack_100;
            }
            else {
              pCStack_100 = (CFastBuffer<class_CCrystalFace*> *)0x3f800000;
            }
          }
          else {
            pCStack_100 = (CFastBuffer<class_CCrystalFace*> *)0x0;
          }
          in_stack_fffffe98 = 0x7c5ccc;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar1 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                              (ulong)in_stack_fffffea0);
          fVar29 = 1.1420913e-38;
          fVar23 = CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed
                             (*(CSceneVehicleCarTuning **)pSVar3,
                              (CSceneVehicleCarTuning *)param_11[2],(float)in_stack_fffffeb4);
          iVar1 = *(int *)(this + 100);
          fVar23 = fVar23 * *(float *)(param_3 + 0xc);
          in_stack_fffffeb4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
          in_stack_fffffea0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c5cf9;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar1 + 0x14),in_stack_fffffeb4,(ulong)in_stack_fffffea8);
          fVar22 = (float)pCStack_d8 * 0.0 + fStack_e0 + fStack_dc * 0.0;
          pCVar33 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                    (-*(float *)(*(int *)pSVar3 + 0xa4) * (float)_DAT_00b313b8 * fVar22);
          pCStack_104 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)ABS((float)pCVar33);
          if ((float)pCVar31 < (float)pCStack_104) {
            in_stack_fffffeb4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c5d56;
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar1 + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                                (ulong)pCVar15);
            fVar23 = (float)pCVar14 * (1.0 - *(float *)(*(int *)pSVar3 + 0xe4));
            pCVar31 = (CSceneVehicleCar *)((float)pCStack_100 + (float)pCVar31);
            pCVar14 = _DAT_00b2c060;
            if (-1 < (int)fVar22) {
              pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
            }
            pCStack_104 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
            pCStack_100 = (CFastBuffer<class_CCrystalFace*> *)
                          (fVar23 + (float)pCStack_100 * *(float *)(*(int *)pSVar3 + 0xe4));
            fVar23 = fVar22;
          }
          pCVar15 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
          in_stack_fffffea8 = (CFastBuffer<class_CCrystalFace*> *)0x7c5dda;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar1 + 0x14),pCVar15,(ulong)in_stack_fffffeb0);
          fStack_fc = *(float *)(*(int *)pSVar3 + 0x98) * fVar23;
          if (iVar13 != 0) {
            pCVar6 = _DAT_00b2c060;
            if (*(int *)(this + 0x5c4) == 0) {
              pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
            }
            if (*(int *)((int)fStack_a4 + 300) == 0) {
              pCVar31 = (CSceneVehicleCar *)0x3f800000;
            }
            else {
              pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c5e25;
              pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(iVar1 + 0x14),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24)
                                  ,(ulong)pCVar27);
              pCVar31 = *(CSceneVehicleCar **)(*(int *)pSVar3 + 0x9c);
            }
            in_stack_fffffeb0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c5e41;
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar1 + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                                (ulong)pCVar28);
            uStack_9c = (double)(float)uStack_f4;
            pCVar28 = (CSceneVehicleCarTuning *)param_11[2];
            pCVar27 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c5e5c;
            fVar22 = CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed
                               (*(CSceneVehicleCarTuning **)pSVar3,pCVar28,(float)pCVar32);
            uStack_f4._4_4_ =
                 (float)(double)CONCAT44(pSStack_94,uStack_9c._4_4_) -
                 (float)in_stack_fffffee4 * fStack_e0 * *(float *)(this + 0x5e8) * fVar22 *
                 (float)pCVar6;
          }
          pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   ((float)in_stack_fffffee4 * 0.0);
          fStack_d0 = (float)pCVar6 * 0.0 - (float)pCVar6 * (float)pCVar33;
          pfStack_cc = (float *)((float)in_stack_fffffee4 * (float)pCVar33 - (float)pCVar6 * 0.0);
          pCStack_c8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       ((float)pCVar6 * 0.0 - (float)in_stack_fffffee4 * 0.0);
          in_stack_fffffee8 = in_stack_fffffee4;
          in_stack_fffffef0 = pCVar6;
          pCStack_c4 = pCVar6;
          AddVehicleTorque(this,(CSceneVehicleCar *)&fStack_d0,pGVar30);
          pCStack_104 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)pCStack_104 + 1);
        } while (pCStack_104 < pCStack_100);
      }
      if (in_stack_fffffee4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x62c) = pCVar33;
        if (pCVar31 == (CSceneVehicleCar *)0x0) {
          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x630) = pCVar33;
        }
        *(int *)(this + 0x634) = (int)pCVar33 - *(int *)(this + 0x630);
      }
      if ((pCVar33 == *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x62c)) &&
         (_DAT_00b9ef4c < (float)pCVar7)) {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(this + 100) + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                             (*(int *)(this + 100) + 0x24),in_stack_fffffe98);
        pCVar2 = (CFastBuffer<class_CCrystalFace*> *)
                 ((((float)pCVar32 - (float)pCVar33) / (float)pCVar33) /
                 *(float *)(*(int *)pSVar3 + 0x200));
        pCVar32 = (CFastBuffer<class_CCrystalFace*> *)0x0;
        if (((float)pCVar2 < 0.0 == ((float)pCVar2 == 0.0)) &&
           (pCVar32 = pCVar2, !NAN((float)pCVar2) && 1.0 < (float)pCVar2 != ((float)pCVar2 == 1.0)))
        {
          pCVar32 = (CFastBuffer<class_CCrystalFace*> *)0x3f800000;
        }
        fVar23 = 1.0 - (float)pCVar32;
      }
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),in_stack_fffffe98);
      fVar29 = CSceneVehicleCarTuning::M5GetSlippingAccelFromSpeed
                         (*(CSceneVehicleCarTuning **)pSVar3,(CSceneVehicleCarTuning *)param_11[2],
                          fVar29);
      iVar13 = *(int *)(this + 100);
      if (*(int *)(this + 0x5c4) == 0) {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar13 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                            (ulong)in_stack_fffffea0);
        fVar22 = CSceneVehicleCarTuning::M5GetAccelFromSpeed
                           (*(CSceneVehicleCarTuning **)pSVar3,(CSceneVehicleCarTuning *)param_11[2]
                            ,(float)in_stack_fffffeb4);
      }
      else {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar13 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                            (ulong)in_stack_fffffea0);
        fVar22 = CSceneVehicleCarTuning::M6GetRearGearAccelFromSpeed
                           (*(CSceneVehicleCarTuning **)pSVar3,(CSceneVehicleCarTuning *)param_11[2]
                            ,(float)in_stack_fffffeb4);
      }
      if (*(int *)(this + 0x2e4) == 1) {
        fStack_b0 = 0.0;
      }
      else {
        fStack_b0 = (1.0 - fVar29) * (float)in_stack_fffffee0 + fVar22 * fVar29;
      }
      iVar13 = *(int *)(this + 100);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar13 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                          (ulong)in_stack_fffffea8);
      iVar1 = *(int *)pSVar3;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar13 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                          (ulong)pCVar15);
      pCVar26 = (CSceneVehicleCarTuning *)param_11[2];
      fVar29 = CSceneVehicleCarTuning::M5GetSteerSlowDownFromSpeed
                         (*(CSceneVehicleCarTuning **)pSVar3,pCVar26,(float)in_stack_fffffeb0);
      iVar13 = *(int *)(this + 0x69c);
      pGVar30 = (GmVec3 *)(*(float *)(iVar1 + 0x7c) * (float)pCVar6 * fVar29);
      fStack_e8 = 1.0;
      fStack_ec = 0.0;
      if (iVar13 == 1) {
        iVar1 = *(int *)(this + 100);
        pCVar26 = (CSceneVehicleCarTuning *)0x7c60c8;
        in_stack_fffffef0 =
             (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                        (ulong)pCVar27);
        pCVar27 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24);
        in_stack_fffffeb0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c60d8;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x14),pCVar27,(ulong)pCVar28);
        fStack_dc = (float)((int)in_stack_fffffee8 - *(int *)(this + 0x6f4));
        pCVar28 = (CSceneVehicleCarTuning *)0x7c6127;
        __CIsin();
        fStack_e0 = (*(float *)(*(int *)pSVar3 + 0x29c) - 1.0) * (float)extraout_ST0_04 + 1.0;
      }
      piVar18 = param_11;
      if (iVar13 == 3) {
        iVar13 = *(int *)(this + 100);
        uVar17 = (int)in_stack_fffffee8 - *(int *)(this + 0x6f8);
        pCVar27 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c6169;
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  ((void *)(iVar13 + 0x14),
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                   (ulong)pCVar32);
        pCVar28 = (CSceneVehicleCarTuning *)0x7c6177;
        pSStack_d4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar13 + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                                (ulong)pCVar7);
        __CIsin();
        pCStack_d8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     ((*(float *)(*(int *)pSStack_d4 + 0x2ac) - 1.0) * (float)extraout_ST0_05 + 1.0)
        ;
        pCVar32 = (CFastBuffer<class_CCrystalFace*> *)0x7c61e9;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar13 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                            (ulong)pCVar33);
        uVar17 = uVar17 / *(uint *)(*(int *)pSVar3 + 0x2a8);
        fVar29 = (float)(int)uVar17;
        if ((int)uVar17 < 0) {
          fVar29 = fVar29 + _DAT_00c418d0;
        }
        pCStack_100 = (CFastBuffer<class_CCrystalFace*> *)(fVar29 - (float)_DAT_00b2c188);
        pCVar33 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24);
        pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c621d;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar13 + 0x14),pCVar33,(ulong)pGVar30);
        fStack_fc = fStack_fc * fStack_fc;
        pSStack_d4 = (SCasterCat *)(fStack_fc * *(float *)(*(int *)pSVar3 + 0x2b8));
        piVar18 = (int *)param_8;
      }
      pCVar6 = _DAT_00b2c060;
      if (*(int *)(this + 0x5c4) == 0) {
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      }
      if (*(int *)(this + 0x600) == 0) {
        fStack_b8 = 0.0;
      }
      else {
        fStack_b8 = *(float *)(this + 0x5f4);
      }
      pCVar14 = _DAT_00b2c060;
      if (*(int *)(this + 0x5c4) == 0) {
        pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
      }
      pGVar5 = (GmVec3 *)
               (fStack_e4 +
               (fStack_e0 *
                ((float)in_stack_fffffedc * fStack_b8 +
                (*(float *)(this + 0x50) * *(float *)((int)param_8 + 4) +
                (float)pCVar6 * *(float *)((int)param_8 + 4) * *(float *)(this + 0x54)) *
                (float)uStack_9c) - (float)pCVar31 * (float)pCVar14));
      if (fVar23 != 0.0) {
        pGVar5 = (GmVec3 *)((float)pGVar5 * (float)_DAT_00b313b8);
      }
      if (*(int *)(this + 0x60c) != 0) {
        if (*(int *)(this + 0x600) == 0) {
          pGVar5 = (GmVec3 *)((float)in_stack_fffffedc * 0.0);
        }
        else {
          pGVar5 = (GmVec3 *)((float)in_stack_fffffedc * *(float *)(this + 0x5f4));
        }
      }
      fVar29 = 0.0;
      if (0.0 < (float)piVar18[2]) {
        in_stack_fffffedc = (GmVec3 *)0x3f800000;
        pCVar28 = (CSceneVehicleCarTuning *)0x7c6348;
        uVar35 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,pCVar32);
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (uVar35 != 0) {
          do {
            pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                               (this + 0x2e8,pCVar6,(ulong)in_stack_fffffeb0);
            if (*(int *)(pSVar3 + 300) != 0) {
              in_stack_fffffeb0 =
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)(this + 100) + 0x24)
              ;
              CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                        ((void *)(*(int *)(this + 100) + 0x14),in_stack_fffffeb0,(ulong)pCVar27);
            }
            pCVar6 = pCVar6 + 1;
          } while (pCVar6 < in_stack_fffffee8);
        }
        iVar13 = *(int *)(this + 100);
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  ((void *)(iVar13 + 0x14),
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                   (ulong)in_stack_fffffeb0);
        pCVar26 = (CSceneVehicleCarTuning *)0x7c63a8;
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  ((void *)(iVar13 + 0x14),
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                   (ulong)pCVar27);
        if (*(int *)param_8 == 0) {
          pCVar27 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24);
          in_stack_fffffeb0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c63ec;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar13 + 0x14),pCVar27,(ulong)pCVar28);
          fVar23 = *(float *)(*(int *)pSVar3 + 0x4c);
        }
        else {
          pCVar27 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24);
          in_stack_fffffeb0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c63d9;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar13 + 0x14),pCVar27,(ulong)pCVar28);
          fVar23 = *(float *)(*(int *)pSVar3 + 0x48);
        }
        fVar23 = *(float *)((int)param_8 + 8) * fVar23;
        if (fVar23 < fVar29) {
          pCVar28 = (CSceneVehicleCarTuning *)0x7c6429;
          pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,pCVar32);
          pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          fVar29 = fVar23;
          if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            uStack_f4._0_4_ = 1.4013e-45;
            do {
              in_stack_fffffeb0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c644c;
              pCVar27 = pCVar14;
              pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                                 (this + 0x2e8,pCVar14,(ulong)pCVar28);
              pCVar14 = pCVar14 + 1;
              *(undefined4 *)(pSVar3 + 300) = 1;
              fVar29 = fVar23;
            } while (pCVar14 < pCVar6);
          }
        }
      }
      if (((float)piVar18[2] < 0.0) && ((float)_DAT_00b362c0 < *(float *)(this + 0x50))) {
        if (*(int *)(this + 0x60c) == 0) {
          iVar13 = *(int *)(this + 100);
          pCVar27 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7c649d;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar13 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                              (ulong)pCVar32);
          pCVar32 = *(CFastBuffer<class_CCrystalFace*> **)(iVar13 + 0x24);
          pCVar28 = (CSceneVehicleCarTuning *)0x7c64ab;
          pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              ((void *)(iVar13 + 0x14),
                               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar32,
                               (ulong)pCVar7);
          if ((*(float *)(*(int *)pSVar11 + 0x22c) <
               -(float)in_stack_fffffedc * *(float *)(*(int *)pSVar3 + 0x228) * (float)piVar18[2])
             && (_DAT_00b2c05c < fStack_34)) {
            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x6f4) = in_stack_fffffef0;
            *(undefined4 *)(this + 0x69c) = 1;
            *(undefined4 *)(this + 0x6a0) = 1;
          }
        }
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)pCVar26);
        pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                               (this + 0x2e8,pCVar14,(ulong)in_stack_fffffeb0);
            if (*(int *)(pSVar3 + 300) != 0) {
              in_stack_fffffeb0 =
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)(this + 100) + 0x24)
              ;
              CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                        ((void *)(*(int *)(this + 100) + 0x14),in_stack_fffffeb0,(ulong)pCVar27);
            }
            pCVar14 = pCVar14 + 1;
          } while (pCVar14 < pCVar6);
        }
        iVar13 = *(int *)(this + 100);
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  ((void *)(iVar13 + 0x14),
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                   (ulong)in_stack_fffffeb0);
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  ((void *)(iVar13 + 0x14),
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                   (ulong)pCVar27);
        if (*(int *)param_8 == 0) {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar13 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                              (ulong)pCVar28);
          fVar23 = *(float *)(*(int *)pSVar3 + 0x24c);
        }
        else {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar13 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                              (ulong)pCVar28);
          fVar23 = *(float *)(*(int *)pSVar3 + 0x248);
        }
        fVar23 = *(float *)((int)param_8 + 8) * fVar23;
        if (fVar23 < fVar29) {
          uVar35 = 0x7c65ff;
          pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,pCVar32);
          pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          fVar29 = fVar23;
          if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            uStack_f4._0_4_ = 1.4013e-45;
            do {
              pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                                 (this + 0x2e8,pCVar14,uVar35);
              pCVar14 = pCVar14 + 1;
              *(undefined4 *)(pSVar3 + 300) = 1;
              fVar29 = fVar23;
            } while (pCVar14 < pCVar6);
          }
        }
      }
      *(float *)param_10 = fVar29;
      pSStack_10c = (SCasterCat *)piVar18[2];
      pCVar6 = _DAT_00b2c060;
      if (-1 < (int)pSStack_10c) {
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
      }
      iVar13 = *(int *)(this + 100);
      uVar40 = CONCAT44(pCVar31,pCVar6);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar13 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                          (ulong)pCVar32);
      pCStack_d8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   (*(float *)(*(int *)pSVar3 + 0x30) * *(float *)param_9);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar13 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                          (ulong)pCVar7);
      if (*(float *)(*(int *)pSVar3 + 0x2c) * *(float *)param_9 < (float)piVar18[2]) {
        if (0.0 <= (float)in_stack_fffffef0) {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar13 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                              (ulong)pCVar33);
          pSStack_10c = (SCasterCat *)-*(float *)(*(int *)pSVar3 + 0x60);
        }
        else {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar13 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                              (ulong)pCVar33);
          pSStack_10c = (SCasterCat *)((float)pSStack_10c - *(float *)(*(int *)pSVar3 + 0x60));
        }
      }
      if ((float)piVar18[2] < -fStack_d0) {
        if ((float)pSStack_10c <= 0.0) {
          CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                    ((void *)(iVar13 + 0x14),
                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                     (ulong)pGVar30);
        }
        else {
          CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                    ((void *)(iVar13 + 0x14),
                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                     (ulong)pGVar30);
        }
      }
      uStack_9c._0_4_ = 0.0;
      uStack_9c._4_4_ = 0.0;
      pSStack_94 = (SCasterCat *)((float)pSStack_10c * (float)param_6);
      AddVehicleCentralForce(this,(CSceneVehicleCar *)&uStack_9c,pGVar30);
      iVar13 = *(int *)(this + 100);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar13 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                          (ulong)uVar40);
      pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(iVar13 + 0x14),
                           *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                           (ulong)((ulonglong)uVar40 >> 0x20));
      uStack_f4._0_4_ =
           (-*(float *)(*(int *)pSVar3 + 100) * *(float *)(param_7 + 8)) /
           *(float *)(*(int *)pSVar11 + 0x160);
      uStack_9c._0_4_ = 0.0;
      uStack_9c._4_4_ = 0.0;
      pSStack_94 = (SCasterCat *)(float)uStack_f4;
      AddVehicleCentralForce(this,(CSceneVehicleCar *)&uStack_9c,pGVar5);
    }
    *(float *)(this + 0x628) = fStack_dc;
    goto LAB_007c67f9;
  }
  if (((*(float *)(this + 0x50) < (float)_DAT_00b362c0) ||
      (*(float *)(this + 0x54) < (float)_DAT_00b362c0)) || (ABS((float)param_10) < _DAT_00b9ef4c)) {
LAB_007c47de:
    *(undefined4 *)(this + 0x69c) = 0;
  }
  else {
    pCVar6 = _DAT_00b2c060;
    if (-1 < (int)param_10) {
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
    }
    if ((((*(float *)(this + 0x708) != (float)pCVar6) || (*(int *)(this + 0x5dc) != 0)) ||
        ((0 < *(int *)(this + 0x5d8) ||
         ((param_11 == (int *)0x0 || (in_stack_fffffedc != (GmVec3 *)0x0)))))) ||
       (*(int *)(this + 0x60c) != 0)) goto LAB_007c47de;
    fStack_ec = 0.0;
    uStack_f4._4_4_ = 0.0;
    uStack_f4._0_4_ = 0.0;
    uVar35 = 0x7c4016;
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (pCVar16,(CFastBuffer<class_CCrystalFace*> *)uVar38);
    pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar14 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar16,pCVar15,(ulong)pCVar7);
        fStack_fc = *(float *)(pSVar3 + 0x144) + fStack_fc;
        pCVar15 = pCVar15 + 1;
        fStack_f8 = *(float *)(pSVar3 + 0x148) + fStack_f8;
        uStack_f4._0_4_ = *(float *)(pSVar3 + 0x14c) + (float)uStack_f4;
      } while (pCVar15 < pCVar14);
    }
    if (fStack_f8 * fStack_f8 + fStack_fc * fStack_fc + (float)uStack_f4 * (float)uStack_f4 <=
        _DAT_00d06a80) {
      uStack_f4._0_4_ = 0.0;
      fStack_fc = 0.0;
      fStack_f8 = 1.0;
    }
    else {
      fVar19 = (float10)func_0x009c1b40();
      fVar29 = 1.0 / (float)fVar19;
      fStack_fc = fVar29 * fStack_fc;
      fStack_f8 = fStack_f8 * fVar29;
      uStack_f4._0_4_ = fVar29 * (float)uStack_f4;
    }
    fVar29 = 1.1410888e-38;
    GmVec3::SetMult(&fStack_38,(SPlugFaceCull *)&fStack_fc,(SPlugFaceCull *)(this + 0x6a4),
                    (GmIso4 *)pCVar33);
    pCVar31 = (CSceneVehicleCar *)0x7c40fe;
    GmVec3::GetAngle((GmVec3 *)&fStack_34,(GmVec3 *)(this + 0x6fc));
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 100) + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                         (*(int *)(this + 100) + 0x24),uVar35);
    if ((float)in_stack_fffffedc <= *(float *)(*(int *)pSVar3 + 0x28c)) {
      GmIso4::SetInverse(&pGStack_24,(GmScaleTrans2 *)(this + 0x6a4),(GmScaleTrans2 *)uVar38);
      pSVar37 = (SPlugFaceCull *)&pSStack_20;
      pSVar36 = (SPlugFaceCull *)(this + 0x6e0);
      fVar34 = 1.1411063e-38;
      GmVec3::SetMult(&fStack_dc,pSVar36,pSVar37,(GmIso4 *)(uVar38 >> 0x20));
      fStack_ac = (float)pCStack_d8 - *pfStack_cc;
      fStack_a8 = (float)pSStack_d4 - pfStack_cc[1];
      fStack_a4 = fStack_d0 - pfStack_cc[2];
      dVar39 = (double)CONCAT44(0x7c41c6,pSVar37);
      fVar19 = (float10)func_0x009c1b40();
      fVar23 = (float)fVar19;
      pSStack_10c = (SCasterCat *)(float)uStack_f4;
      piStack_108 = (int *)uStack_f4._4_4_;
      pCVar32 = in_stack_fffffea8;
      fVar22 = fStack_f8;
      if (_DAT_00d06a80 < (float)in_stack_fffffea8) {
        fVar19 = (float10)func_0x009c1b40();
        in_stack_fffffea8 = (CFastBuffer<class_CCrystalFace*> *)(1.0 / (float)fVar19);
        pSStack_10c = (SCasterCat *)((float)uStack_f4 * (float)in_stack_fffffea8);
        piStack_108 = (int *)((float)in_stack_fffffea8 * uStack_f4._4_4_);
        fVar22 = (float)in_stack_fffffea8 * fStack_f8;
      }
      iVar13 = *(int *)(this + 100);
      fVar20 = (float)((ulonglong)dVar39 >> 0x20);
      pCStack_100 = (CFastBuffer<class_CCrystalFace*> *)
                    (fVar22 * fVar20 - (float)pSVar36 * (float)piStack_108);
      fStack_fc = (float)pSStack_10c * (float)pSVar36 - SUB84(dVar39,0) * fVar22;
      fVar20 = fStack_fc * *(float *)(pGStack_24 + 8) +
               (SUB84(dVar39,0) * (float)piStack_108 - fVar20 * (float)pSStack_10c) *
               *(float *)pGStack_24 + (float)pCStack_100 * *(float *)(pGStack_24 + 4);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar13 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                          (ulong)in_stack_fffffe88);
      fVar21 = ABS(in_stack_fffffea4);
      if (*(float *)(*(int *)pSVar3 + 0x284) < fVar21) {
        *(undefined4 *)(this + 0x69c) = 0;
      }
      if ((*(float *)(this + 0x6ec) < (float)in_stack_fffffeb4) ||
         (pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar13 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                              (ulong)in_stack_fffffe8c), fVar29 < *(float *)(*(int *)pSVar3 + 0x280)
         )) {
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  ((void *)(iVar13 + 0x14),
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                   (ulong)in_stack_fffffe8c);
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  ((void *)(iVar13 + 0x14),
                   *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                   (ulong)in_stack_fffffe90);
        dVar39 = (double)(float)in_stack_fffffeac;
        __CIexp();
        in_stack_fffffea4 =
             ((float)((float10)dVar39 * (float10)dVar39) / (float)pCVar31) * (float)extraout_ST0;
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 (in_stack_fffffea4 * (float)pCStack_100);
        fVar22 = in_stack_fffffea4 * fStack_fc;
        AddVehicleCentralForce(this,(CSceneVehicleCar *)&stack0xfffffee8,in_stack_fffffe94);
      }
      else {
        *(undefined4 *)(this + 0x69c) = 0;
      }
      pSVar25 = (SSimulationWheel *)0x7c4408;
      pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(pCVar16,in_stack_fffffea8);
      pCVar33 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar3 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                             (pCVar16,pCVar33,(ulong)pSVar25);
          pSVar25 = pSStack_20;
          WheelAddForceToVehicle
                    (this,(CSceneVehicleCar *)pSVar3,pSStack_20,(GmVec3 *)in_stack_fffffea8);
          pCVar33 = pCVar33 + 1;
          *(undefined4 *)(pSVar3 + 300) = 0;
        } while (pCVar33 < pCVar7);
      }
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)fVar21);
      pCVar28 = *(CSceneVehicleCarTuning **)pSVar3;
      pGVar30 = (GmVec3 *)GmFunc::Sign(fStack_4,fVar20);
      fVar20 = CSceneVehicleCarTuning::M6GetLateralSpeedFromBurnoutRadius
                         (pCVar28,(CSceneVehicleCarTuning *)pSVar36,fVar20);
      fVar34 = -fVar34 * fVar20 - (float)pCVar31;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)in_stack_fffffea4);
      fVar29 = *(float *)(*(int *)pSVar3 + 0x264) * fVar29;
      pCStack_c8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fVar29 * fStack_e4);
      pCStack_c4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fVar29 * fStack_e0);
      auStack_c0._0_4_ = fVar29 * fStack_dc;
      AddVehicleCentralForce(this,(CSceneVehicleCar *)&pCStack_c8,(GmVec3 *)pCVar32);
      pCStack_100 = (CFastBuffer<class_CCrystalFace*> *)0x0;
      fStack_fc = 0.0;
      fStack_f8 = 1.0;
      fVar21 = GmVec3::GetAngle((GmVec3 *)&pCStack_100,(GmVec3 *)&fStack_ec);
      fVar20 = (float)_DAT_00b36110;
      iVar13 = GmFunc::IsANumber(fVar21 / fVar20);
      if (iVar13 == 0) {
LAB_007c4700:
        *(undefined4 *)(this + 0x69c) = 0;
      }
      else {
        iVar13 = *(int *)(this + 100);
        dVar42 = (double)(SUB84(dVar39,0) * (fVar21 / fVar20) * (float)_DAT_00b36110);
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar13 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                            (ulong)pCVar7);
        fVar20 = (float)((ulonglong)dVar39 >> 0x20);
        if ((float)(double)CONCAT44(pCVar6,(int)((ulonglong)dVar42 >> 0x20)) <
            -*(float *)(*(int *)pSVar3 + 0x294)) goto LAB_007c4700;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar13 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                            (ulong)fVar23);
        fVar23 = (float)((ulonglong)dVar42 >> 0x20);
        if (*(float *)(*(int *)pSVar3 + 0x290) < (float)(double)CONCAT44(fVar22,pCVar6))
        goto LAB_007c4700;
        if ((float)pCStack_100 <= 0.0) {
          if (*(float *)(param_3 + 4) <= 0.0) {
            CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar13 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                       (ulong)fVar34);
            pSVar36 = (SPlugFaceCull *)((float)pSVar36 * (float)pSVar36);
          }
          else {
            CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar13 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                       (ulong)fVar34);
          }
        }
        else if (0.0 <= *(float *)(param_3 + 4)) {
          CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                    ((void *)(iVar13 + 0x14),
                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                     (ulong)fVar34);
          pSVar36 = (SPlugFaceCull *)((float)pSVar36 * (float)pSVar36);
        }
        else {
          CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                    ((void *)(iVar13 + 0x14),
                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                     (ulong)fVar34);
        }
        if (fStack_fc <= 0.0) {
          if (0.0 < fVar20 / (float)in_stack_fffffee0) {
            CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((void *)(iVar13 + 0x14),
                       *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                       (ulong)fVar29);
          }
        }
        else if (fVar20 / (float)in_stack_fffffee0 < 0.0) {
          CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                    ((void *)(iVar13 + 0x14),
                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                     (ulong)fVar29);
        }
        fVar34 = 1.1412973e-38;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar13 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar13 + 0x24),
                            (ulong)pCVar31);
        pCVar31 = (CSceneVehicleCar *)&fStack_ec;
        fStack_e8 = *(float *)(*(int *)pSVar3 + 0x268) * (float)uStack_f4 + (float)pCVar6 + fVar23;
        fStack_ec = (float)_PTR_00b2c178 * fStack_e8;
        fVar29 = 1.1413069e-38;
        fStack_e4 = fStack_ec;
        AddVehicleTorque(this,pCVar31,pGVar30);
      }
      fVar23 = ABS(*(float *)param_2);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)fVar34);
      fVar29 = CSceneVehicleCarTuning::M6GetDonutRolloverFromSpeed
                         (*(CSceneVehicleCarTuning **)pSVar3,(CSceneVehicleCarTuning *)pSVar36,
                          fVar29);
      fVar22 = GmFunc::Sign(*(float *)param_2,(float)pCVar31);
      fStack_8c = -fVar22 * fVar29;
      pSStack_94 = (SCasterCat *)((float)_PTR_00b2c178 * fStack_8c);
      uVar38 = ZEXT48(pSStack_94);
      pSStack_90 = pSStack_94;
      AddVehicleTorque(this,(CSceneVehicleCar *)&pSStack_94,(GmVec3 *)pCVar31);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)pGVar30);
      fStack_64 = CSceneVehicleCarTuning::M6GetBurnoutRolloverFromSpeed
                            (*(CSceneVehicleCarTuning **)pSVar3,
                             *(CSceneVehicleCarTuning **)((int)param_2 + 8),fVar23);
      fStack_60 = 0.0;
      uStack_5c = 0;
      AddVehicleTorque(this,(CSceneVehicleCar *)&fStack_64,(GmVec3 *)pSVar36);
    }
    else {
      *(undefined4 *)(this + 0x69c) = 0;
    }
  }
  if (*(int *)(this + 0x69c) != 2) {
    *(undefined4 *)(this + 0x69c) = 1;
    pvVar8 = *(void **)(DAT_00d731e0 + 0x14);
    if (pvVar8 == (void *)0x0) {
      pvVar8 = (void *)(DAT_00d731e0 + 0xa0);
    }
    puVar9 = CMwTimerAdapter::GetTickTime(pvVar8,(CMwTimerAdapter *)uVar38);
    *(ulong *)(this + 0x6f4) = *puVar9;
  }
LAB_007c67f9:
  *(int *)(this + 0x70c) = *param_11;
  *(int *)(this + 0x710) = param_11[1];
  *(int *)(this + 0x714) = param_11[2];
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::ComputeVehicleGroundMaterialVals
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::ComputeVehicleGroundMaterialVals
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SBlendableVals *param_2,int *param_3)
{
{
  CSceneVehicleCar *this_00;
  int iVar1;
  float fVar2;
  SBlendableVals *pSVar3;
  SCasterCat *pSVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  ulong unaff_EBP;
  int iVar5;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *in_stack_0000001c;
  CSceneVehicleCar *pCVar6;
  
  *(undefined4 *)param_2 = 0;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  this_00 = this + 0x2e8;
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar5 = 0;
  pCVar6 = this;
  pSVar3 = (SBlendableVals *)CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  param_2 = (SBlendableVals *)0x0;
  if (pSVar3 != (SBlendableVals *)0x0) {
    do {
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                          unaff_ESI);
      if (*(int *)(pSVar4 + 0x124) != 0) {
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP)
        ;
        unaff_ESI = 0x7c286f;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x6c,
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                            (uint)*(ushort *)(pSVar4 + 0x128),(ulong)unaff_EBX);
        unaff_EBX = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar4;
        unaff_EBP = 0x7c287d;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(this + 0x68) + 0x14),unaff_EBX,(ulong)pCVar6);
        iVar1 = *(int *)pSVar4;
        iVar5 = iVar5 + 1;
        *(float *)param_1 = *(float *)(iVar1 + 0x14) + *(float *)param_1;
        *(float *)(param_1 + 4) = *(float *)(iVar1 + 0x18) + *(float *)(param_1 + 4);
        *(float *)(param_1 + 8) = *(float *)(iVar1 + 0x1c) + *(float *)(param_1 + 8);
        *(float *)(param_1 + 0xc) = *(float *)(iVar1 + 0x20) + *(float *)(param_1 + 0xc);
        *in_stack_0000001c = 1;
      }
      param_2 = param_2 + 1;
    } while (param_2 < pSVar3);
    if (iVar5 != 0) {
      fVar2 = (float)iVar5;
      if (iVar5 < 0) {
        fVar2 = fVar2 + _DAT_00c418d0;
      }
      fVar2 = 1.0 / fVar2;
      *(float *)param_1 = fVar2 * *(float *)param_1;
      *(float *)(param_1 + 4) = *(float *)(param_1 + 4) * fVar2;
      *(float *)(param_1 + 8) = fVar2 * *(float *)(param_1 + 8);
      *(float *)(param_1 + 0xc) = fVar2 * *(float *)(param_1 + 0xc);
    }
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::CreateDefaultData
// =================================================
void __thiscall CSceneVehicleCar::CreateDefaultData(CSceneVehicleCar *this,CCrystal *param_1)
{
{
  CSceneVehicleTunings *this_00;
  CSceneToyCharacter *extraout_EAX;
  CSceneVehicleCarTuning *this_01;
  CMwNod *extraout_EAX_00;
  SLoadedLight *pSVar1;
  CSceneVehicleStruct *this_02;
  CMwNod *extraout_EAX_01;
  CFastBuffer<class_GxVertex2> *pCVar2;
  CMwNod *unaff_EBX;
  CMwNod *pCVar3;
  CMwNod *unaff_EBP;
  CSceneToyCharacter *pCVar4;
  CSceneVehicleCarTuning *unaff_ESI;
  CSceneVehicleTunings *unaff_EDI;
  int iVar5;
  undefined4 uStack00000010;
  undefined4 uStack00000014;
  void *in_stack_00000020;
  CSceneVehicleCar *pCVar6;
  GmFrustumIso4 *pGVar7;
  
  pGVar7 = (GmFrustumIso4 *)0xffffffff;
  ExceptionList = &stack0xfffffff4;
  pCVar6 = this;
  CSceneVehicle::CreateDefaultData
            ((CSceneVehicle *)this,(CCrystal *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  this_00 = operator_new(0x28);
  pCVar3 = (CMwNod *)0x0;
  if (this_00 == (CSceneVehicleTunings *)0x0) {
    pCVar4 = (CSceneToyCharacter *)0x0;
  }
  else {
    CSceneVehicleTunings::CSceneVehicleTunings(this_00,unaff_EDI);
    pCVar4 = extraout_EAX;
  }
  this_01 = operator_new(0x3ac);
  if (this_01 != (CSceneVehicleCarTuning *)0x0) {
    CSceneVehicleCarTuning::CSceneVehicleCarTuning(this_01,unaff_ESI);
    pCVar3 = extraout_EAX_00;
  }
  pSVar1 = CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_>::AddNewElem
                     (pCVar4 + 0x14,
                      (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_ESI);
  if (pCVar3 != *(CMwNod **)pSVar1) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3,unaff_EBP);
    }
    if (*(CMwNod **)pSVar1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)pSVar1,unaff_EBX);
    }
    *(CMwNod **)pSVar1 = pCVar3;
  }
  CSceneVehicle::TuningsSet((CSceneVehicle *)this,pCVar4,(CSceneToyCharacterTunings *)unaff_EBX);
  this_02 = operator_new(0x50);
  uStack00000010 = 2;
  if (this_02 == (CSceneVehicleStruct *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  }
  else {
    CSceneVehicleStruct::CSceneVehicleStruct(this_02,(CSceneVehicleStruct *)pCVar6);
    pCVar3 = extraout_EAX_01;
  }
  uStack00000014 = 0xffffffff;
  if (pCVar3 != *(CMwNod **)(this + 0x60)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3,(CMwNod *)this_00);
    }
    if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x60),(CMwNod *)this_00);
    }
    *(CMwNod **)(this + 0x60) = pCVar3;
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            ((void *)(*(int *)(this + 0x60) + 0x14),(GmFrustumIso4 *)this_00);
  iVar5 = 4;
  do {
    pSVar1 = CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::AddNewElem
                       ((void *)(*(int *)(this + 0x60) + 0x14),
                        (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)this_01);
    this_01 = (CSceneVehicleCarTuning *)0x7c8032;
    CSceneVehicleStruct::SSimulationWheel::Reset(pSVar1,pGVar7);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  pCVar2 = (CFastBuffer<class_GxVertex2> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(*(int *)(this + 0x60) + 0x14),
                      (CFastBuffer<class_CCrystalFace*> *)this_01);
  CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::AllocSetCount
            (this + 0x2e8,pCVar2,(ulong)this_02);
  ExceptionList = in_stack_00000020;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::CreateFakeContacts
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::CreateFakeContacts(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  ulonglong uVar1;
  byte bVar2;
  int iVar3;
  CPlugBitmap *this_00;
  CPlugFileImg *this_01;
  float fVar4;
  CPlugFileImg *this_02;
  SCasterCat *pSVar5;
  SCasterCat *pSVar6;
  int iVar7;
  SPlugFaceCull *pSVar8;
  byte *pbVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  GmVec3 *unaff_EDI;
  undefined2 in_FPUControlWord;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  CHmsItem *pCVar10;
  ulong uVar11;
  CHmsPhysicalContact *pCVar12;
  undefined1 *puVar13;
  ulong in_stack_ffffff60;
  CPlugFileImg *in_stack_ffffff64;
  undefined2 uVar14;
  longlong in_stack_ffffff68;
  undefined8 uStack_88;
  undefined1 auStack_78 [4];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_74;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_70;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined2 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_1c;
  CHmsItem local_14 [12];
  float fStack_8;
  
  puVar13 = &stack0xfffffffc;
  pCVar10 = local_14;
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),pCVar10,unaff_EDI);
  local_70 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_ESI);
  local_74 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  uStack_88._4_4_ = this;
  if (local_70 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      uVar11 = 0x7c3c4f;
      pSVar5 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (uStack_88._4_4_ + 0x2e8,local_74,(ulong)puVar13);
      if (*(int *)(pSVar5 + 0x124) != 0) {
        pCVar12 = (CHmsPhysicalContact *)0x7c3c6e;
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (uStack_88._4_4_ + 0x6c,
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                            (uint)*(ushort *)(pSVar5 + 0x128),(ulong)unaff_EBX);
        unaff_EBX = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar6;
        puVar13 = (undefined1 *)0x7c3c7c;
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(uStack_88._4_4_ + 0x68) + 0x14),unaff_EBX,
                            in_stack_ffffff60);
        iVar3 = *(int *)pSVar6;
        this_00 = *(CPlugBitmap **)(iVar3 + 0x24);
        if (this_00 == (CPlugBitmap *)0x0) {
          return;
        }
        in_stack_ffffff60 = 0x7c3c91;
        iVar7 = CPlugFileImg::IsInSystemMemory(*(CPlugFileImg **)(this_00 + 0x48),in_stack_ffffff64)
        ;
        if ((iVar7 == 0) &&
           (iVar7 = CPlugBitmap::ReGenerate(this_00,(CPlugFileVideo *)in_stack_ffffff68), iVar7 == 0
           )) {
          return;
        }
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(uStack_88._4_4_ + 0x28) + 0x34),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)((ulonglong)in_stack_ffffff68 >> 0x20));
        pSVar8 = (SPlugFaceCull *)(**(code **)(**(int **)pSVar6 + 0x78))();
        GmVec3::SetMult(auStack_78,(SPlugFaceCull *)(pSVar5 + 0x34),pSVar8,(GmIso4 *)pCVar10);
        __CIfmod();
        fVar4 = (float)*(int *)(*(int *)(this_00 + 0x48) + 0x18);
        if (*(int *)(*(int *)(this_00 + 0x48) + 0x18) < 0) {
          fVar4 = fVar4 + _DAT_00c418d0;
        }
        this_01 = *(CPlugFileImg **)(this_00 + 0x48);
        uVar14 = (undefined2)((uint)ABS((float)extraout_ST0) >> 0x10);
        uVar1 = (ulonglong)ROUND(fVar4 * (ABS((float)extraout_ST0) / *(float *)(iVar3 + 0x28)));
        uStack_88._0_4_ = (CPlugFileImg *)uVar1;
        this_02 = (CPlugFileImg *)uStack_88;
        __CIfmod();
        fVar4 = (float)*(int *)(this_01 + 0x1c);
        if (*(int *)(this_01 + 0x1c) < 0) {
          fVar4 = fVar4 + _DAT_00c418d0;
        }
        in_stack_ffffff64 = (CPlugFileImg *)CONCAT22(uVar14,in_FPUControlWord);
        in_stack_ffffff68 =
             (longlong)ROUND(fVar4 * (ABS((float)extraout_ST0_00) / *(float *)(iVar3 + 0x2c)));
        pCVar10 = (CHmsItem *)in_stack_ffffff68;
        pbVar9 = CPlugFileImg::GetPixel(this_01,(CPlugFileImg *)uStack_88,(ulong)pCVar10,uVar11);
        bVar2 = *pbVar9;
        if (bVar2 != 0) {
          uStack_88 = (ulonglong)CONCAT14(bVar2,(CPlugFileImg *)uStack_88);
          uVar1 = uStack_88;
          uStack_88._4_4_ = (CSceneVehicleCar *)(uint)bVar2;
          fStack_3c = ((float)(int)uStack_88._4_4_ / (float)_DAT_00b55d50) * fStack_8 *
                      *(float *)(iVar3 + 0x30);
          if (*(float *)(iVar3 + 0x34) < fStack_3c) {
            fStack_3c = *(float *)(iVar3 + 0x34);
          }
          in_stack_ffffff68 = CONCAT44((int)((ulonglong)in_stack_ffffff68 >> 0x20),fStack_3c);
          uStack_4c = *(undefined4 *)(pSVar5 + 0x34);
          uStack_1c = *(undefined2 *)(pSVar5 + 0x128);
          uStack_48 = *(undefined4 *)(pSVar5 + 0x38);
          uStack_44 = *(undefined4 *)(pSVar5 + 0x3c);
          uStack_58 = 0;
          uStack_5c = 0;
          uStack_64 = 0;
          uStack_54 = 0x3f800000;
          uStack_24 = 0;
          uStack_60 = 0;
          uStack_20 = 0;
          uStack_50 = 0;
          uStack_40 = 0;
          fStack_3c = -fStack_3c;
          uStack_38 = 0;
          uStack_2c = 0;
          uStack_30 = 0;
          uStack_34 = 0;
          WheelAbsorbContact((CSceneVehicleCar *)this_02,(CSceneVehicleCar *)pSVar5,
                             (SSimulationWheel *)&uStack_64,pCVar12);
          pCVar10 = (CHmsItem *)pSVar5;
        }
        uStack_88 = uVar1;
      }
      local_74 = local_74 + 1;
    } while (local_74 < local_70);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::CreateOldStruct
// =================================================
void __thiscall CSceneVehicleCar::CreateOldStruct(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  int iVar1;
  CSceneVehicleStruct *pCVar2;
  CSceneVehicleStruct *this_00;
  CMwNod *extraout_EAX;
  SLoadedLight *pSVar3;
  CFastBuffer<class_GxVertex2> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CMwNod *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CMwNod *unaff_EDI;
  void *in_stack_0000000c;
  void *pvVar8;
  
  pCVar2 = (CSceneVehicleStruct *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  pvVar8 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  this_00 = operator_new(0x50);
  if (this_00 == (CSceneVehicleStruct *)0x0) {
    this_01 = (CMwNod *)0x0;
  }
  else {
    CSceneVehicleStruct::CSceneVehicleStruct(this_00,pCVar2);
    this_01 = extraout_EAX;
  }
  if (this_01 != *(CMwNod **)(this + 0x60)) {
    if (this_01 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_01,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x60),unaff_EDI);
    }
    *(CMwNod **)(this + 0x60) = this_01;
  }
  iVar1 = *(int *)(this + 0x60);
  CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::AllocSetCount
            ((void *)(iVar1 + 0x14),(CFastBuffer<class_GxVertex2> *)&DAT_00000004,(ulong)unaff_EDI);
  pSVar3 = CFastBuffer<struct_CSceneVehicleStruct::SVisualVehicle>::AddNewElem
                     ((void *)(*(int *)(this + 0x60) + 0x20),unaff_ESI);
  pSVar3 = pSVar3 + 0x24;
  pCVar4 = (CFastBuffer<class_GxVertex2> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar1 + 0x14),unaff_EBP);
  CFastBuffer<struct_CSceneVehicleStruct::SVisualWheel>::AllocSetCount(pSVar3,pCVar4,unaff_EBX);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (pSVar3,(CFastBuffer<class_CCrystalFace*> *)this_00);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar6 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[](pSVar3,pCVar7,(ulong)pvVar8);
      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar6 + 0x20) = pCVar7;
      pCVar7 = pCVar7 + 1;
      *(undefined4 *)(pSVar6 + 4) = 1;
      *(undefined4 *)(pSVar6 + 0xc) = 1;
      *(undefined4 *)(pSVar6 + 0x14) = 1;
    } while (pCVar7 < pCVar5);
  }
  ExceptionList = in_stack_0000000c;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::EnableTurbo
// =================================================
void __thiscall
CSceneVehicleCar::EnableTurbo
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,ulong param_2,ulong param_3,
          float param_4,ETurboType param_5,ulong param_6)
{
{
  ulong unaff_EBX;
  int unaff_EBP;
  EPlugVideoTimer unaff_ESI;
  CPlugFileVideo *unaff_EDI;
  float fVar1;
  float in_stack_0000001c;
  float fStack00000020;
  int in_stack_00000024;
  
  if (*(float *)(this + 0x600) != param_4) {
    *(CSceneVehicleCar **)(this + 0x5f8) = param_1;
    if (*(CSceneSoundSource **)(this + 0x26c) != (CSceneSoundSource *)0x0) {
      CSceneSoundSource::Play
                (*(CSceneSoundSource **)(this + 0x26c),unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX);
    }
    *(undefined4 *)(this + 0x604) = 0;
  }
  if (param_4 != 1.4013e-45) {
    if ((param_4 != 2.8026e-45) || (*(int *)(this + 0x604) == in_stack_00000024)) goto LAB_007bd023;
    fStack00000020 = GetRouletteValue01((int)param_1 - *(int *)(this + 0x5d0),DAT_00d06a74);
    *(float *)(this + 0x608) = fStack00000020;
    fVar1 = GetRouletteBoostFactorFromValue01(fStack00000020);
    in_stack_0000001c = fVar1 * in_stack_0000001c;
    *(int *)(this + 0x604) = in_stack_00000024;
  }
  *(float *)(this + 0x5f4) = in_stack_0000001c;
LAB_007bd023:
  *(CSceneVehicleCar **)(this + 0x5fc) = param_1 + param_6;
  *(float *)(this + 0x600) = param_4;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::EngineIntegrate
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::EngineIntegrate
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,float param_3)
{
{
  float fVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  undefined4 uVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  SCasterCat *pSVar8;
  ulong unaff_EBX;
  ulong unaff_EBP;
  int iVar9;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  float10 fVar11;
  float unaff_retaddr;
  float in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  float in_stack_0000001c;
  float in_stack_00000020;
  float in_stack_00000024;
  float in_stack_00000028;
  float in_stack_0000002c;
  int in_stack_00000030;
  float in_stack_00000034;
  float fStack0000003c;
  ulong uVar12;
  ulong uVar13;
  ulong in_stack_fffffff4;
  ulong in_stack_fffffff8;
  float fVar14;
  ulong in_stack_fffffffc;
  
  uVar12 = (ulong)((float)_DAT_00b362c0 < (float)param_1);
  uVar13 = 1;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar7 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar10,unaff_EBP);
      if (*(int *)(pSVar7 + 0x124) != 0) {
        in_stack_fffffff8 = 0;
        break;
      }
      pCVar10 = pCVar10 + 1;
    } while (pCVar10 < pCVar6);
  }
  if (0.0 < *(float *)(this + 0x5c0)) {
    *(float *)(this + 0x5c0) = *(float *)(this + 0x5c0) - param_3;
  }
  if ((in_stack_fffffff4 != 0) || (0.0 < *(float *)(this + 0x5c0))) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  iVar2 = *(int *)(this + 100);
  pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar2 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),unaff_EBP);
  if (*(int *)(*(int *)pSVar7 + 0x354) != 5) {
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),unaff_EBX
                       );
    fVar14 = *(float *)(*(int *)pSVar7 + 0x2c) * (float)_DAT_00b43310;
    iVar9 = *(int *)(this + 0x5c8);
    if (iVar9 < 2) {
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    }
    else {
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar9 + -1);
    }
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),unaff_ESI
                       );
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(*(int *)pSVar7 + 0x2d4),pCVar6,uVar12);
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),uVar13);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(*(int *)pSVar7 + 0x2e0),pCVar6,in_stack_fffffff4);
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                        (ulong)fVar14);
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)pSVar7 + 0x2c4),pCVar6,in_stack_fffffffc);
    fVar11 = (float10)func_0x009c1b40();
    uVar5 = _DAT_00b80d18;
    fVar14 = ((float)fVar11 / in_stack_00000018) * *(float *)pSVar7;
    if (in_stack_00000030 == 0) {
      fVar14 = *(float *)(this + 0x5c0);
      if ((!NAN(fVar14) && 0.0 < fVar14 != (fVar14 == 0.0)) &&
         (*(float *)(this + 0x5c0) <= in_stack_00000034 + in_stack_00000034)) {
        *(float *)(this + 0x5b4) =
             *(float *)(this + 0x5b4) -
             *(float *)(this + 0x59c) * in_stack_00000034 * (float)_DAT_00b9efb8;
      }
    }
    else {
      in_stack_00000028 = fVar14;
      if (*(int *)(this + 0x5c4) == 0) {
        if (iVar9 == 0) {
          *(undefined4 *)(this + 0x5c8) = 1;
          *(undefined4 *)(this + 0x5c0) = uVar5;
        }
        else {
          if ((fVar14 <= in_stack_00000020) || (4 < iVar9)) {
            if ((in_stack_00000024 <= fVar14) || (iVar9 < 2)) goto LAB_007be202;
            iVar9 = iVar9 + -1;
          }
          else {
            iVar9 = iVar9 + 1;
          }
          *(int *)(this + 0x5c8) = iVar9;
          *(undefined4 *)(this + 0x5c0) = uVar5;
        }
      }
      else if (iVar9 != 0) {
        *(undefined4 *)(this + 0x5c8) = 0;
        *(undefined4 *)(this + 0x5c0) = uVar5;
      }
    }
LAB_007be202:
    fVar14 = _DAT_00b36ae8;
    if (in_stack_00000030 != 0) {
      fVar14 = _DAT_00b3d274;
    }
    *(float *)(this + 0x5b4) =
         (*(float *)(this + 0x59c) * in_stack_00000028 - *(float *)(this + 0x5b4)) *
         in_stack_00000034 * fVar14 + *(float *)(this + 0x5b4);
    goto LAB_007be257;
  }
  if (bVar4) {
    if (in_stack_fffffff4 == 0) {
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          unaff_EBX);
      *(float *)(this + 0x5b4) =
           *(float *)(this + 0x5b4) - *(float *)(*(int *)pSVar7 + 0x2f4) * in_stack_00000014;
    }
    else {
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          unaff_EBX);
      *(float *)(this + 0x5b4) =
           *(float *)(*(int *)pSVar7 + 0x2f0) * in_stack_00000014 + *(float *)(this + 0x5b4);
    }
    goto LAB_007be257;
  }
  if ((*(int *)(this + 0x69c) == 1) || (*(int *)(this + 0x69c) == 2)) {
    param_3 = 1.4013e-45;
    if (*(int *)(this + 0x5c8) == 0) goto LAB_007bd83d;
    *(undefined4 *)(this + 0x2e4) = 4;
  }
  else {
    param_3 = 0.0;
LAB_007bd83d:
    if (*(int *)(this + 0x2e4) == 4) {
      *(undefined4 *)(this + 0x2e4) = 0;
    }
  }
  iVar9 = *(int *)(this + 0x2e4);
  if (iVar9 == 2) {
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),unaff_EBX
                       );
    if ((*(float *)(*(int *)pSVar7 + 0x32c) < *(float *)(this + 0x714)) ||
       (pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar2 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                            unaff_ESI),
       *(float *)(this + 0x714) < *(float *)(*(int *)pSVar7 + 0x330))) {
      *(undefined4 *)(this + 0x744) = 1;
    }
    else {
      *(undefined4 *)(this + 0x744) = 0;
    }
    *(undefined4 *)(this + 0x5bc) = 0x3f800000;
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),uVar12);
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)pSVar7 + 0x2c4),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,uVar13);
    pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                        in_stack_fffffff4);
    pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)pSVar8 + 0x304),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,in_stack_fffffff8);
    in_stack_00000010 = ABS(*(float *)(this + 0x714));
    *(float *)(this + 0x5b8) =
         *(float *)pSVar8 * (float)_PTR_00b2c178 + in_stack_00000010 * *(float *)pSVar7;
    if (*(int *)(this + 0x744) == 0) {
      if (param_3 != 0.0) {
LAB_007bdd33:
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar2 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                            in_stack_fffffffc);
        fVar14 = *(float *)(*(int *)pSVar7 + 0x324);
        goto LAB_007bdd44;
      }
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          in_stack_fffffffc);
      fVar14 = *(float *)(this + 0x5b4) - *(float *)(*(int *)pSVar7 + 0x328) * in_stack_0000002c;
    }
    else {
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          in_stack_fffffffc);
      fVar14 = *(float *)(this + 0x5b4) - *(float *)(*(int *)pSVar7 + 0x328) * in_stack_0000002c;
    }
    *(float *)(this + 0x5b4) = fVar14;
    if (fVar14 <= *(float *)(this + 0x5b8)) {
      fVar14 = *(float *)(this + 0x5b8);
      *(undefined4 *)(this + 0x2e4) = 0;
      *(undefined4 *)(this + 0x744) = 0;
      goto LAB_007bdd4e;
    }
  }
  else {
    if (iVar9 == 3) {
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          unaff_EBX);
      if ((*(float *)(this + 0x714) < *(float *)(*(int *)pSVar7 + 0x338)) ||
         (pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar2 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                              unaff_ESI),
         *(float *)(*(int *)pSVar7 + 0x334) < *(float *)(this + 0x714))) {
        *(undefined4 *)(this + 0x744) = 1;
      }
      else {
        *(undefined4 *)(this + 0x744) = 0;
      }
      *(undefined4 *)(this + 0x5bc) = 0x3f800000;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),uVar12)
      ;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)pSVar7 + 0x2c4),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar13);
      pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          in_stack_fffffff4);
      pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)pSVar8 + 0x304),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_fffffff8);
      in_stack_00000010 = ABS(*(float *)(this + 0x714));
      *(float *)(this + 0x5b8) =
           *(float *)pSVar8 * (float)_PTR_00b2c178 + in_stack_00000010 * *(float *)pSVar7;
      if (*(int *)(this + 0x744) == 0) {
        if (param_3 != 0.0) goto LAB_007bdd33;
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar2 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                            in_stack_fffffffc);
        fVar14 = *(float *)(this + 0x5b4) - *(float *)(*(int *)pSVar7 + 0x328) * in_stack_0000002c;
      }
      else {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar2 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                            in_stack_fffffffc);
        fVar14 = *(float *)(this + 0x5b4) - *(float *)(*(int *)pSVar7 + 0x328) * in_stack_0000002c;
      }
      *(float *)(this + 0x5b4) = fVar14;
      if (*(float *)(this + 0x5b8) < fVar14) goto LAB_007bdd54;
      fVar14 = *(float *)(this + 0x5b8);
      *(undefined4 *)(this + 0x2e4) = 0;
      *(undefined4 *)(this + 0x744) = 0;
    }
    else {
      if (iVar9 != 4) {
        iVar9 = *(int *)(this + 0x628);
        if ((iVar9 == 0) || (in_stack_fffffff4 == 0)) {
          fVar14 = 1.0;
        }
        else {
          fVar14 = _DAT_00b9efd0;
          if (*(float *)(this + 0x5bc) < _DAT_00b9efd0) {
            fVar14 = ((float)_DAT_00b9efc8 - *(float *)(this + 0x5bc)) * (float)_DAT_00b5b8e0 *
                     in_stack_00000010 + *(float *)(this + 0x5bc);
          }
        }
        pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x5c8);
        *(float *)(this + 0x5bc) = fVar14;
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar2 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                            unaff_EBX);
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)pSVar7 + 0x2c4),pCVar6,unaff_ESI);
        unaff_retaddr = ABS(*(float *)(this + 0x714) * *(float *)(this + 0x5bc));
        *(float *)(this + 0x5b8) = unaff_retaddr * *(float *)pSVar7;
        if (*(int *)(this + 0x5c4) == 0) {
LAB_007bd927:
          if (pCVar6 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
LAB_007bd92b:
            *(undefined4 *)(this + 0x5b8) = 0;
          }
        }
        else {
          if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) goto LAB_007bd92b;
          if (*(int *)(this + 0x5c4) == 0) goto LAB_007bd927;
        }
        if (*(float *)(this + 0x5b8) <= *(float *)(this + 0x5b4)) {
          if (in_stack_fffffffc == 0) {
            pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar2 + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                                uVar12);
            fVar14 = *(float *)(this + 0x5b4);
            fVar1 = *(float *)(*(int *)pSVar7 + 0x328);
          }
          else if ((iVar9 == 0) || (in_stack_00000014 != 0.0)) {
            pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar2 + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                                uVar12);
            fVar14 = *(float *)(this + 0x5b4);
            fVar1 = *(float *)(*(int *)pSVar7 + 0x31c);
          }
          else {
            pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar2 + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                                uVar12);
            fVar14 = *(float *)(this + 0x5b4);
            fVar1 = *(float *)(*(int *)pSVar7 + 0x2f4);
          }
          *(float *)(this + 0x5b4) = fVar14 - fVar1 * in_stack_0000001c;
          if (*(float *)(this + 0x5b4) < *(float *)(this + 0x5b8)) {
            *(undefined4 *)(this + 0x2e4) = 0;
          }
        }
        else {
          pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar2 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                              uVar12);
          fVar14 = *(float *)(*(int *)pSVar7 + 800) * in_stack_0000001c + *(float *)(this + 0x5b4);
          *(float *)(this + 0x5b4) = fVar14;
          if (*(float *)(this + 0x5b8) < fVar14) {
            *(undefined4 *)(this + 0x2e4) = 0;
          }
        }
        goto LAB_007bdd54;
      }
      fVar14 = *(float *)(this + 0x59c);
      *(float *)(this + 0x5b8) = fVar14;
      *(float *)(this + 0x5bc) = _DAT_00b9efd0;
      if (fVar14 <= *(float *)(this + 0x5b4)) {
        if (*(float *)(this + 0x5b4) <= fVar14) goto LAB_007bdd54;
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar2 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                            unaff_EBX);
        fVar14 = *(float *)(*(int *)pSVar7 + 0x2f4);
      }
      else {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar2 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                            unaff_EBX);
        fVar14 = *(float *)(*(int *)pSVar7 + 0x2ec);
      }
LAB_007bdd44:
      fVar14 = fVar14 * in_stack_0000002c + *(float *)(this + 0x5b4);
    }
LAB_007bdd4e:
    *(float *)(this + 0x5b4) = fVar14;
  }
LAB_007bdd54:
  pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar2 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                      (ulong)unaff_retaddr);
  if ((((*(float *)(this + 0x714) <= *(float *)(*(int *)pSVar7 + 0x330)) ||
       (pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar2 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                            (ulong)param_1),
       *(float *)(*(int *)pSVar7 + 0x32c) <= *(float *)(this + 0x714))) ||
      (in_stack_00000018 == 0.0)) ||
     ((*(int *)(this + 0x5c4) != 0 || (*(int *)(this + 0x2e4) != 0)))) {
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                        (ulong)param_2);
    uVar5 = _DAT_00b9efc0;
    if (*(float *)(*(int *)pSVar7 + 0x338) < *(float *)(this + 0x714)) {
      param_2 = *(float *)(iVar2 + 0x24);
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,(ulong)param_3);
      uVar5 = _DAT_00b9efc0;
      if (((*(float *)(this + 0x714) < *(float *)(*(int *)pSVar7 + 0x334)) &&
          (in_stack_00000020 != 0.0)) &&
         ((*(int *)(this + 0x5c4) != 0 && (*(int *)(this + 0x2e4) == 0)))) {
        *(undefined4 *)(this + 0x2e4) = 3;
        *(undefined4 *)(this + 0x744) = 0;
        uVar5 = _DAT_00b9efc0;
        if (*(int *)(this + 0x5c8) != 0) {
          *(undefined4 *)(this + 0x5c8) = 0;
          *(undefined4 *)(this + 0x5c0) = uVar5;
        }
      }
    }
  }
  else {
    *(undefined4 *)(this + 0x2e4) = 2;
    *(undefined4 *)(this + 0x744) = 0;
    uVar5 = _DAT_00b9efc0;
    if (*(int *)(this + 0x5c8) == 0) {
      *(undefined4 *)(this + 0x5c0) = _DAT_00b9efc0;
      *(undefined4 *)(this + 0x5c8) = 1;
    }
  }
  if ((*(int *)(this + 0x2e4) == 0) || (*(int *)(this + 0x2e4) == 1)) {
    if (*(int *)(this + 0x5c4) == 0) {
      if (*(int *)(this + 0x5c8) == 0) {
        *(undefined4 *)(this + 0x2e4) = 1;
        fVar14 = (float)_DAT_00c418d8;
        *(undefined4 *)(this + 0x748) = 0;
        if (*(float *)(this + 0x5b4) < fVar14) {
          *(undefined4 *)(this + 0x5c0) = uVar5;
          *(undefined4 *)(this + 0x5c8) = 1;
        }
      }
      pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x5c8);
      if (0 < (int)pCVar6) {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar2 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                            (ulong)param_2);
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)pSVar7 + 0x2d4),pCVar6,(ulong)param_3);
        fStack0000003c = *(float *)pSVar7 * *(float *)(this + 0x59c);
        if ((*(float *)(this + 0x5b8) <= fStack0000003c) || (4 < (int)pCVar6)) {
          pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar2 + 0x14),
                              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                              (ulong)in_stack_00000010);
          pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(*(int *)pSVar7 + 0x2e0),pCVar6,(ulong)in_stack_00000014);
          if ((*(float *)(this + 0x5b8) < *(float *)pSVar7 * *(float *)(this + 0x59c)) &&
             (1 < (int)pCVar6)) {
            *(undefined4 *)(this + 0x5c0) = _DAT_00b9efc0;
            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x5c8) = pCVar6 + -1;
            *(undefined4 *)(this + 0x2e4) = 1;
            *(undefined4 *)(this + 0x748) = 1;
          }
        }
        else {
          *(undefined4 *)(this + 0x5c0) = _DAT_00b9efc0;
          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x5c8) = pCVar6 + 1;
          *(undefined4 *)(this + 0x2e4) = 1;
          *(undefined4 *)(this + 0x748) = 0;
        }
      }
    }
    else if (*(int *)(this + 0x5c8) != 0) {
      *(undefined4 *)(this + 0x2e4) = 1;
      fVar14 = (float)_DAT_00c418d8;
      *(undefined4 *)(this + 0x748) = 1;
      if (*(float *)(this + 0x5b4) < fVar14) {
        *(undefined4 *)(this + 0x5c8) = 0;
        if (in_stack_00000030 != 0) {
          uVar5 = _DAT_00b989dc;
        }
        *(undefined4 *)(this + 0x5c0) = uVar5;
      }
    }
  }
LAB_007be257:
  fVar14 = *(float *)(this + 0x5b4);
  fVar1 = *(float *)(this + 0x59c);
  fVar3 = 0.0;
  if ((fVar14 < 0.0 == (fVar14 == 0.0)) && (fVar3 = fVar14, fVar1 < fVar14 != (fVar1 == fVar14))) {
    *(float *)(this + 0x5b4) = fVar1;
    return;
  }
  *(float *)(this + 0x5b4) = fVar3;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::GetChunkInfo
// =================================================
ulong __thiscall
CSceneVehicleCar::GetChunkInfo(CSceneVehicleCar *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 < (CFuncSegment *)0xa02b00c) {
    if (param_1 != (CFuncSegment *)0xa02b00b) {
      switch(param_1) {
      case (CFuncSegment *)0xa02b000:
      case (CFuncSegment *)0xa02b001:
      case (CFuncSegment *)0xa02b002:
      case (CFuncSegment *)0xa02b003:
      case (CFuncSegment *)0xa02b004:
      case (CFuncSegment *)0xa02b005:
      case (CFuncSegment *)0xa02b006:
      case (CFuncSegment *)0xa02b007:
      case (CFuncSegment *)0xa02b008:
      case (CFuncSegment *)0xa02b009:
      case (CFuncSegment *)0xa02b00a:
        break;
      default:
        goto switchD_007bc738_default;
      }
    }
  }
  else {
    if ((CFuncSegment *)0xa02b011 < param_1) {
      if (param_1 < (CFuncSegment *)0xa02b015) {
        if (param_1 == (CFuncSegment *)0xa02b014) {
          return 1;
        }
        if (param_1 == (CFuncSegment *)0xa02b012) {
          return 1;
        }
        if (param_1 == (CFuncSegment *)0xa02b013) {
          return 1;
        }
      }
      else if (param_1 == (CFuncSegment *)0xffffffff) {
        return 0xffffffff;
      }
switchD_007bc738_default:
      uVar1 = CSceneVehicle::GetChunkInfo((CSceneVehicle *)this,param_1,param_2);
      return uVar1;
    }
    if (param_1 != (CFuncSegment *)0xa02b011) {
      switch(param_1) {
      case (CFuncSegment *)0xa02b00c:
        return 3;
      case (CFuncSegment *)0xa02b00d:
      case (CFuncSegment *)0xa02b00e:
      case (CFuncSegment *)0xa02b00f:
      case (CFuncSegment *)0xa02b010:
        break;
      default:
        goto switchD_007bc738_default;
      }
    }
  }
  return 1;
}
}

// =================================================
// Function: CSceneVehicleCar::GetLateralFriction
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::GetLateralFriction
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2,GmVec3 *param_3,
          SBlendableVals *param_4,float param_5,int param_6,float *param_7,int *param_8)
{
{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  SCasterCat *pSVar5;
  SCasterCat *pSVar6;
  ulong unaff_ESI;
  ulong unaff_EDI;
  float fVar7;
  ulong unaff_retaddr;
  float in_stack_00000024;
  float in_stack_00000028;
  float *in_stack_0000002c;
  undefined4 *in_stack_00000030;
  
  iVar3 = *(int *)(this + 100);
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar3 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),unaff_EDI);
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar3 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),unaff_ESI);
  fVar4 = ABS((float)param_3);
  fVar7 = *(float *)(*(int *)pSVar5 + 0x1a8);
  fVar1 = *(float *)(*(int *)pSVar6 + 0x1ac);
  if (param_7 == (float *)0x0) {
    iVar2 = 0x3f800000;
  }
  else {
    pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar3 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),
                        (ulong)this);
    iVar2 = *(int *)(*(int *)pSVar5 + 0x1c0);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar3 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),
                      unaff_retaddr);
  fVar7 = CSceneVehicleCarTuning::M4GetMaxFrictionForceFromSpeed
                    (*(CSceneVehicleCarTuning **)pSVar5,(CSceneVehicleCarTuning *)param_6,
                     -(float)param_3 * fVar7 - fVar1 * fVar4 * (float)param_3);
  fVar7 = *(float *)(iVar2 + 0xc) * in_stack_00000024 * fVar7 * in_stack_00000028;
  if (ABS(fVar4) <= fVar7) {
    *in_stack_00000030 = 0;
    *in_stack_0000002c = (float)param_6;
    return;
  }
  fVar1 = _DAT_00b2c060;
  if (-1 < (int)fVar4) {
    fVar1 = 1.0;
  }
  *in_stack_00000030 = 1;
  *in_stack_0000002c = fVar7 * fVar1;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::GetMaxSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CSceneVehicleCar::GetMaxSpeed(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  SCasterCat *pSVar1;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 100) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                       (*(int *)(this + 100) + 0x24),(ulong)this);
  return *(float *)(*(int *)pSVar1 + 0x2c) * (float)_DAT_00b3d2a8;
}
}

// =================================================
// Function: CSceneVehicleCar::GetMwClassId
// =================================================
ulong __thiscall CSceneVehicleCar::GetMwClassId(CSceneVehicleCar *this,CControlStyle *param_1)
{
{
  return 0xa02b000;
}
}

// =================================================
// Function: CSceneVehicleCar::GetRouletteBoostFactorFromValue01
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl CSceneVehicleCar::GetRouletteBoostFactorFromValue01(float param_1)
{
{
  return param_1 + (float)_DAT_00b2c188;
}
}

// =================================================
// Function: CSceneVehicleCar::GetRouletteCurrentBoostFactor
// =================================================
float __thiscall
CSceneVehicleCar::GetRouletteCurrentBoostFactor(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  float fVar1;
  
  fVar1 = GetRouletteBoostFactorFromValue01(*(float *)(this + 0x608));
  return fVar1;
}
}

// =================================================
// Function: CSceneVehicleCar::GetRouletteValue01
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl CSceneVehicleCar::GetRouletteValue01(ulong param_1,ulong param_2)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)(int)(param_1 % param_2);
  if ((int)(param_1 % param_2) < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  fVar2 = (float)(int)param_2;
  if ((int)param_2 < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  if (fVar1 / fVar2 < _DAT_00b9ef60) {
    return 0.0;
  }
  if (fVar1 / fVar2 < (float)_DAT_00b9ef58) {
    return _DAT_00b31460;
  }
  return 1.0;
}
}

// =================================================
// Function: CSceneVehicleCar::GetSlopeAdherence
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::GetSlopeAdherence
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2,float *param_3,
          float *param_4)
{
{
  float fVar1;
  float fVar2;
  int iVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float fStack00000014;
  float in_stack_00000018;
  float *in_stack_0000001c;
  ulong in_stack_ffffffec;
  float fStack_8;
  
  if (_DAT_00d06a80 <
      *(float *)(param_1 + 8) * *(float *)(param_1 + 8) +
      *(float *)param_1 * *(float *)param_1 + *(float *)(param_1 + 4) * *(float *)(param_1 + 4)) {
    iVar3 = *(int *)(this + 100);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)(iVar3 + 0x14),
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),unaff_ESI);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar3 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),unaff_EBX
                       );
    fVar1 = *(float *)(*(int *)pSVar4 + 0xd8);
    fVar2 = *(float *)(param_1 + 4);
    fVar5 = (float10)func_0x009c1b40();
    fVar2 = ABS(fVar2 / (float)fVar5);
    *param_4 = fVar2;
    if (fStack_8 <= fVar2) {
      if (fVar2 <= fVar1) {
        __CIcos();
        fVar2 = 1.0 - (float)extraout_ST0;
      }
      else {
        fVar2 = 1.0;
      }
    }
    else {
      fVar2 = 0.0;
    }
    *param_4 = fVar2;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar3 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),unaff_EDI
                       );
    fStack00000014 = *(float *)(*(int *)pSVar4 + 0xdc);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar3 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x24),
                        in_stack_ffffffec);
    fVar2 = *(float *)(*(int *)pSVar4 + 0xe0);
    fVar1 = ABS(*(float *)(param_1 + 4) / fVar1);
    *in_stack_0000001c = fVar1;
    if (fVar1 < in_stack_00000018) {
      *in_stack_0000001c = 0.0;
      return;
    }
    if (fVar2 < fVar1) {
      *in_stack_0000001c = 1.0;
      return;
    }
    fStack00000014 =
         ((fVar1 - in_stack_00000018) / (fVar2 - in_stack_00000018)) * (float)_DAT_00b36110 *
         (float)_DAT_00b313b8;
    __CIcos();
    *in_stack_0000001c = 1.0 - (float)extraout_ST0_00;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CSceneVehicleCar::GetUidChunkFromIndex
          (CSceneVehicleCar *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if ((CMwCmdExpIso4Ident *)&DAT_0000000d < param_1) {
    return (uint)(param_1 + -0xe) | 0xa02b000;
  }
  if ((CMwCmdExpIso4Ident *)&DAT_0000000c < param_1) {
    return (uint)(param_1 + -0xd) | 0xa060000;
  }
  if ((CMwCmdExpIso4Ident *)&DAT_00000005 < param_1) {
    return (uint)(param_1 + -6) | 0xa011000;
  }
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0xa005000;
}
}

// =================================================
// Function: CSceneVehicleCar::GetWheelFromSurfaceTree
// =================================================
ulong __thiscall
CSceneVehicleCar::GetWheelFromSurfaceTree
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,CPlugTree *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar3,unaff_ESI);
      if (*(CPlugTree **)(pSVar2 + 0xc) == param_2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CSceneVehicleCar::HasSavedStateChanged
// =================================================
int __thiscall
CSceneVehicleCar::HasSavedStateChanged(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  int iVar1;
  GmIso4 *unaff_retaddr;
  
  iVar1 = CHmsItem::IsStateDifferentFrom
                    (*(CHmsItem **)(this + 0x28),(CHmsItem *)(this + 0x848),unaff_retaddr);
  return iVar1;
}
}

// =================================================
// Function: CSceneVehicleCar::IntegrateVehicle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::IntegrateVehicle(CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2)
{
{
  CSceneVehicleCar *pCVar1;
  int iVar2;
  float fVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  GmIso4 *pGVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  SRealTimeState *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  ulong unaff_ESI;
  GmVec3 *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  float in_stack_0000000c;
  CFuncColorGradient *in_stack_00000010;
  float in_stack_00000014;
  float in_stack_0000001c;
  float in_stack_00000020;
  float fVar9;
  float fVar10;
  CMwCmdScriptVarBool *in_stack_ffffffe0;
  ulong in_stack_ffffffe4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffe8;
  CSceneVehicleCar **ppCVar11;
  undefined4 *puVar12;
  undefined4 local_c;
  float local_8;
  float local_4;
  
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)&local_c,unaff_EDI);
  if (((byte)this[0x2f4] & 1) != 0) {
    iVar2 = *(int *)(this + 100);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),unaff_ESI
                       );
    pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                        (ulong)unaff_EBP);
    ppCVar11 = (CSceneVehicleCar **)ABS(param_2);
    puVar12 = (undefined4 *)
              ((float)ppCVar11 * *(float *)(*(int *)pSVar4 + 0x70) +
              *(float *)(*(int *)pSVar5 + 0x6c));
    unaff_EBP = (SRealTimeState *)0x7c3967;
    pGVar6 = (GmIso4 *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EBX);
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pGVar6 != (GmIso4 *)0x0) {
      do {
        fVar9 = 1.1408245e-38;
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (this + 0x2e8,pCVar7,(ulong)in_stack_ffffffe0);
        in_stack_ffffffe0 = (CMwCmdScriptVarBool *)(pSVar4 + 0x10);
        fVar10 = 1.1408272e-38;
        GmMat3::Set(pSVar4 + 0xc0,in_stack_ffffffe0,in_stack_ffffffe4);
        if (*(int *)(pSVar4 + 4) == 0) {
          fVar3 = 0.0;
        }
        else {
          if (_DAT_00b9ef4c <= local_4) {
            pGVar6 = (GmIso4 *)(-*(float *)(this + 0x5e8) / local_4);
          }
          else {
            pGVar6 = (GmIso4 *)0x0;
          }
          in_stack_ffffffe0 = (CMwCmdScriptVarBool *)0x7c39e1;
          GmMat3::RotateY(pSVar4 + 0xc0,pGVar6,(float)in_stack_ffffffe8);
          iVar2 = *(int *)(this + 100);
          local_4 = _DAT_00b36198;
          in_stack_ffffffe8 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24);
          in_stack_ffffffe4 = 0x7c39fa;
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar2 + 0x14),in_stack_ffffffe8,(ulong)ppCVar11);
          if (*(int *)(*(int *)pSVar5 + 0x378) != 0) {
            param_2 = 0.0;
            pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar2 + 0x14),
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                                (ulong)puVar12);
            puVar12 = &stack0x0000000c;
            in_stack_00000010 =
                 (CFuncColorGradient *)(ABS(in_stack_00000020) * (float)_DAT_00b3d2a8);
            ppCVar11 = &param_1;
            in_stack_ffffffe4 = 0x7c3a50;
            in_stack_ffffffe8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_00000010;
            CFuncKeysReal::GetValue
                      (*(CFuncKeysReal **)(*(int *)pSVar5 + 0x378),in_stack_00000010,(float)ppCVar11
                      );
          }
          in_stack_0000000c = ((float)pGVar6 * (float)_DAT_00b36110) / (float)_DAT_00b36ab8;
          fVar3 = -*(float *)(this + 0x5e8) * in_stack_0000000c;
        }
        *(float *)(pSVar4 + 0x158) = fVar3;
        WheelUpdateSpeedFromVehicleSpeed
                  (this,(CSceneVehicleCar *)pSVar4,(SSimulationWheel *)param_1,in_stack_0000000c,
                   fVar9);
        unaff_EBP = (SRealTimeState *)in_stack_00000010;
        SSimulationWheel::SRealTimeState::Integrate
                  (pSVar4 + 0xb4,(SRealTimeState *)in_stack_00000010,fVar10);
        pCVar7 = pCVar7 + 1;
      } while (pCVar7 < pGVar6);
    }
  }
  if (((byte)this[0x2f4] & 2) != 0) {
    fVar9 = 1.1408694e-38;
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffe0);
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (this + 0x2e8,pCVar8,(ulong)in_stack_0000000c);
        WheelIntegrate(this,(CSceneVehicleCar *)pSVar4,(SSimulationWheel *)unaff_EBP,fVar9);
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < pCVar7);
    }
  }
  if (((byte)this[0x2f4] & 4) != 0) {
    if (*(int *)(this + 0x60c) == 0) {
      if (*(int *)(this + 0x5c4) == 0) {
        pCVar1 = *(CSceneVehicleCar **)(this + 0x50);
      }
      else {
        pCVar1 = *(CSceneVehicleCar **)(this + 0x54);
      }
      EngineIntegrate(this,pCVar1,in_stack_00000014,(float)in_stack_ffffffe0);
    }
    else {
      *(undefined4 *)(this + 0x5b4) = 0;
    }
  }
  iVar2 = *(int *)(this + 100);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar2 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                      (ulong)in_stack_ffffffe0);
  if (0.0 < *(float *)(*(int *)pSVar4 + 0x94)) {
    local_c = _DAT_00b2c060;
    if (*(float *)(this + 0x5e8) - *(float *)(this + 0x58) < (float)_PTR_00b2c178) {
      local_c = 0x3f800000;
    }
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar2 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                        in_stack_ffffffe4);
    fVar9 = *(float *)(*(int *)pSVar4 + 0x94) * local_8 * in_stack_0000001c +
            *(float *)(this + 0x5e8);
    in_stack_0000001c = fVar9;
    if (*(float *)(this + 0x58) <= *(float *)(this + 0x5e8)) {
      if (*(float *)(this + 0x58) <= fVar9) goto LAB_007c3bd5;
    }
    else if (fVar9 <= *(float *)(this + 0x58)) goto LAB_007c3bd5;
  }
  fVar9 = *(float *)(this + 0x58);
LAB_007c3bd5:
  *(float *)(this + 0x5e8) = fVar9;
  (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 100) + 0xbc))(0);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::IsAllWheelGroundContactId
// =================================================
int __thiscall
CSceneVehicleCar::IsAllWheelGroundContactId
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,uchar param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  byte in_stack_0000000c;
  
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar4,unaff_ESI);
      if (*(int *)(pSVar2 + 0x124) == 0) {
        pCVar3 = pCVar3 + 1;
      }
      else if (*(ushort *)(pSVar2 + 0x128) != (ushort)in_stack_0000000c) {
        return 0;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return (uint)(pCVar3 < pCVar1);
}
}

// =================================================
// Function: CSceneVehicleCar::IsGroundContact
// =================================================
int __thiscall CSceneVehicleCar::IsGroundContact(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar3,unaff_ESI);
      if (*(int *)(pSVar2 + 0x124) != 0) {
        return 1;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicleCar::IsGroundContactId
// =================================================
int __thiscall
CSceneVehicleCar::IsGroundContactId
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,uchar param_2,GmVec3 *param_3,
          ulong *param_4)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *in_stack_00000014;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar3,unaff_ESI);
      if ((*(int *)(pSVar2 + 0x124) != 0) && (*(ushort *)(pSVar2 + 0x128) == (ushort)param_2)) {
        *param_4 = *(ulong *)(pSVar2 + 0x130);
        param_4[1] = *(ulong *)(pSVar2 + 0x134);
        param_4[2] = *(ulong *)(pSVar2 + 0x138);
        *in_stack_00000014 = *(undefined4 *)(pSVar2 + 0x13c);
        return 1;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicleCar::IsRubberBall
// =================================================
int __thiscall CSceneVehicleCar::IsRubberBall(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  return *(int *)(this + 0x844);
}
}

// =================================================
// Function: CSceneVehicleCar::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall
CSceneVehicleCar::MwGetClassInfo(CSceneVehicleCar *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6cff8;
}
}

// =================================================
// Function: CSceneVehicleCar::MwIsKindOf
// =================================================
int __thiscall
CSceneVehicleCar::MwIsKindOf(CSceneVehicleCar *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((((param_1 != (CMwCmdAffectParam *)0xa02b000) && (param_1 != (CMwCmdAffectParam *)0xa060000))
      && (param_1 != (CMwCmdAffectParam *)0xa011000)) && (param_1 != (CMwCmdAffectParam *)0xa005000)
     ) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CSceneVehicleCar::MwNewCSceneVehicleCar
// =================================================
CMwNod * __cdecl CSceneVehicleCar::MwNewCSceneVehicleCar(void)
{
{
  CSceneVehicleCar *pCVar1;
  CMwNod *extraout_EAX;
  CSceneVehicleCar *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00acca7b;
  local_c = ExceptionList;
  pCVar1 = (CSceneVehicleCar *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x878);
  local_4 = 0;
  if (local_10 != (CSceneVehicleCar *)0x0) {
    CSceneVehicleCar(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CSceneVehicleCar::NewSolidInstance
// =================================================
void __thiscall CSceneVehicleCar::NewSolidInstance(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  int iVar1;
  CPlugSolid *pCVar2;
  CPlugSolid *unaff_EDI;
  
  pCVar2 = *(CPlugSolid **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x68);
  if (pCVar2 != (CPlugSolid *)0x0) {
    iVar1 = *(int *)this;
    pCVar2 = CPlugSolid::CreateModelInstance(pCVar2,unaff_EDI);
    (**(code **)(iVar1 + 0xd8))(pCVar2);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::OnEnterScene
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneVehicleCar::OnEnterScene(CSceneVehicleCar *this,CSceneToyBroomstick *param_1)
{
{
  float fVar1;
  CHmsViewport *pCVar2;
  int iVar3;
  SCasterCat *pSVar4;
  CHmsViewport *pCVar5;
  CHmsViewport *extraout_ECX;
  CHmsViewport *extraout_ECX_00;
  ulong unaff_EBX;
  CHmsItem *unaff_ESI;
  CSceneToyBroomstick *unaff_EDI;
  CSystemWindow *unaff_retaddr;
  CHmsCorpus *in_stack_00000008;
  CSceneVehicleCar *pCVar6;
  
  pCVar6 = this;
  CSceneVehicle::OnEnterScene((CSceneVehicle *)this,unaff_EDI);
  (**(code **)(*(int *)this + 0x130))();
  CHmsItem::PickDisable(*(CHmsItem **)(this + 0x28),unaff_ESI);
  *(undefined4 *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x44) = 0;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX);
  pCVar2 = *(CHmsViewport **)pSVar4;
  iVar3 = *(int *)(pCVar2 + 0x58);
  pCVar5 = extraout_ECX;
  if (iVar3 != 0) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 100) + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                         (*(int *)(this + 100) + 0x24),(ulong)pCVar6);
    fVar1 = *(float *)(*(int *)pSVar4 + 0x14c);
    *(float *)(iVar3 + 0xc4) = fVar1;
    *(uint *)(iVar3 + 0xc0) = (uint)(_DAT_00b9ef4c < fVar1);
    pCVar5 = extraout_ECX_00;
  }
  pCVar5 = CHmsViewport::FindOrCreateViewport(pCVar5,(CVisionEngine *)0x0,unaff_retaddr);
  if (pCVar5 != (CHmsViewport *)0x0) {
    CHmsViewport::LoadResourceCorpus(pCVar5,pCVar2,in_stack_00000008);
                    /* WARNING: Could not recover jumptable at 0x007bcf89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pCVar5 + 0xa4))();
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::OnNodLoaded
// =================================================
void __thiscall CSceneVehicleCar::OnNodLoaded(CSceneVehicleCar *this,CDx9DeviceCaps *param_1)
{
{
  CDx9DeviceCaps *unaff_ESI;
  CSceneVehicle *in_stack_00000008;
  
  CSceneVehicle::OnNodLoaded((CSceneVehicle *)this,unaff_ESI);
  (**(code **)(*(int *)this + 0x130))();
  CSceneVehicle::RetrieveLoadedLinkedSounds((CSceneVehicle *)this,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::RestoreStaticState
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::RestoreStaticState
          (CSceneVehicleCar *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,int param_3,
          ulong param_4,ulong param_5,int param_6)
{
{
  CHmsCorpus *pCVar1;
  byte bVar2;
  int *piVar3;
  SCasterCat *pSVar4;
  int iVar5;
  SState *pSVar6;
  SCasterCat *pSVar7;
  int iVar8;
  int iVar9;
  void *this_00;
  uint uVar10;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CSceneVehicleCar *pCVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  GmVec3 *unaff_EBP;
  ulong unaff_ESI;
  int iVar13;
  undefined4 *puVar14;
  SState *unaff_EDI;
  SState *pSVar15;
  SVehicleSimpleState_ReplayAfter040104 *pSVar16;
  CSceneVehicleCar *pCVar17;
  float10 extraout_ST0;
  float fVar18;
  CClassicBufferMemory *unaff_retaddr;
  int in_stack_0000001c;
  uint in_stack_00000024;
  uint in_stack_00000028;
  ulong in_stack_ffffff9c;
  ulong in_stack_ffffffa0;
  CHmsCorpus *pCVar19;
  CHmsCorpus *pCVar20;
  ulong uVar21;
  CHmsCorpus **ppCVar22;
  undefined1 *puVar23;
  SState *pSVar24;
  SPlugFaceCull *this_01;
  SState *pSVar25;
  SPlugFaceCull *pSVar26;
  GmIso4 *pGVar27;
  SPlugFaceCull *in_stack_ffffffd0;
  SPlugFaceCull *in_stack_ffffffd4;
  undefined4 uVar28;
  GmVec3 *in_stack_ffffffd8;
  undefined4 auStack_24 [3];
  uint uStack_18;
  CSceneVehicleCar CStack_11;
  CSceneVehicleCar aCStack_10 [4];
  SCasterCat *pSStack_c;
  int iStack_8;
  CHmsCorpus *pCStack_4;
  
  piVar3 = (int *)(**(code **)(*(int *)this + 8))();
  pSVar6 = (SState *)&stack0xffffffd4;
  pSVar26 = (SPlugFaceCull *)param_4;
  bVar2 = (**(code **)(*piVar3 + 4))();
  pCVar1 = pCStack_4;
  param_2 = (CClassicBufferMemory *)CONCAT31(param_2._1_3_,bVar2);
  if (unaff_EBX == (CFastBuffer<class_CCrystalFace*> *)0x0) {
    pCVar19 = (CHmsCorpus *)0x7cf3f9;
    pCVar20 = pCStack_4;
    CHmsItem::RestoreStaticState
              (*(CHmsItem **)(this + 0x28),(CSceneToyBoat *)pCStack_4,unaff_retaddr,(int)param_1,
               (uint)bVar2,(ulong)pSVar26,(int)pSVar6);
    unaff_retaddr = param_2;
  }
  else {
    in_stack_ffffffa0 = 0x7cf3e0;
    pCVar19 = pCStack_4;
    pCVar20 = (CHmsCorpus *)unaff_retaddr;
    CHmsItem::OldRestoreStaticState
              (*(CHmsItem **)(this + 0x28),pCStack_4,unaff_retaddr,(int)param_1,bVar2,param_3);
  }
  if (param_4 < 2) {
    (**(code **)(*(int *)pCVar1 + 4))(&stack0xffffffcb,1);
    bVar2 = (byte)((uint)unaff_EBP >> 0x18);
  }
  else {
    bVar2 = (byte)param_4;
    unaff_EBP = (GmVec3 *)CONCAT13(bVar2,(int3)unaff_EBP);
  }
  if (bVar2 == 0) {
    return;
  }
  if ((bVar2 == 2) || (bVar2 == 1)) {
    pSVar24 = (SState *)&DAT_00000016;
    puVar23 = &stack0xffffffd4;
    (**(code **)(*(int *)pCVar1 + 4))();
    if (unaff_retaddr != (CClassicBufferMemory *)0x0) {
      pCVar11 = this + 0x2e8;
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                          (ulong)puVar23);
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)(pSVar4 + 0x16c));
      SVehicleSimpleState_ReplayAfter211003::RestoreFromStruct
                (auStack_24,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x2f8),
                 (SVehicleCarState *)(pSVar4 + 0x16c),pSVar24,(SState *)pSVar26,pSVar6,unaff_EDI);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 0x28) + 0x34),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
      puVar14 = (undefined4 *)(*(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x328) + 0x10);
      pCVar17 = this + 0x32c;
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined4 *)pCVar17 = *puVar14;
        puVar14 = puVar14 + 1;
        pCVar17 = pCVar17 + 4;
      }
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)param_4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)unaff_EBP);
      iVar5 = *(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x328);
      *(undefined4 *)(this + 0x364) = *(undefined4 *)(iVar5 + 0x40);
      *(undefined4 *)(this + 0x368) = *(undefined4 *)(iVar5 + 0x44);
      *(undefined4 *)(this + 0x36c) = *(undefined4 *)(iVar5 + 0x48);
      if ((*(int *)(this + 0x78) != 0) &&
         (uVar21 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar11,unaff_EBX), uVar21 != 0)) {
        do {
          pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                             (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              (ulong)in_stack_ffffffd0);
          in_stack_ffffffd0 = (SPlugFaceCull *)(pSVar4 + 400);
          *(undefined4 *)in_stack_ffffffd0 = *(undefined4 *)(pSVar4 + 100);
          *(undefined4 *)(pSVar4 + 0x194) = *(undefined4 *)(pSVar4 + 0x68);
          *(undefined4 *)(pSVar4 + 0x198) = *(undefined4 *)(pSVar4 + 0x6c);
          *(float *)(pSVar4 + 0x194) = *(float *)(pSVar4 + 0x194) - *(float *)(pSVar4 + 8);
          GmVec3::Mult(in_stack_ffffffd0,
                       (GmIso3 *)(*(int *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 100) + 0x5c),
                       (GmIso3 *)in_stack_ffffffd4);
          in_stack_ffffffd4 = (SPlugFaceCull *)(this + 0x32c);
          GmVec3::SetMult(pSVar4 + 0x184,in_stack_ffffffd0,in_stack_ffffffd4,
                          (GmIso4 *)in_stack_ffffffd8);
          in_stack_00000024 = in_stack_00000024 + 1;
        } while (in_stack_00000024 < in_stack_00000028);
      }
      iVar5 = CSceneVehicle::UpdateEvent
                        ((CSceneVehicle *)this,(CSceneVehicle *)0x0,*(EVehicleEvent *)(this + 0x35c)
                         ,(ulong)in_stack_ffffffd0);
      if (iVar5 != 0) {
        (**(code **)(*(int *)this + 0x164))();
      }
      iVar5 = CSceneVehicle::UpdateEvent
                        ((CSceneVehicle *)this,(CSceneVehicle *)0x1,*(EVehicleEvent *)(this + 0x360)
                         ,(ulong)in_stack_ffffffd4);
      if (iVar5 == 0) {
        return;
      }
      CSceneVehicle::WaterSplash
                ((CSceneVehicle *)this,(CSceneVehicle *)(this + 0x364),in_stack_ffffffd8);
      return;
    }
    pCVar11 = this + 0x2e8;
    pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,(ulong)puVar23
                       );
    pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                        (ulong)(pSVar4 + 0x1d0));
    pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                        (ulong)(pSVar4 + 0x1d0));
    pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)(pSVar4 + 0x1d0));
    SVehicleSimpleState_ReplayAfter211003::RestoreFromStruct
              (auStack_24,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x3a0),
               (SVehicleCarState *)(pSVar4 + 0x1d0),pSVar24,(SState *)pSVar26,pSVar6,unaff_EDI);
    iVar5 = *(int *)(this + 0x28);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar5 + 0x34),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                        ,unaff_ESI);
    puVar14 = (undefined4 *)(*(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x32c) + 0x10);
    pCVar11 = this + 0x3d4;
    for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined4 *)pCVar11 = *puVar14;
      puVar14 = puVar14 + 1;
      pCVar11 = pCVar11 + 4;
    }
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar5 + 0x34),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                        ,(ulong)unaff_EBP);
    iVar5 = *(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x32c);
LAB_007cff2c:
    *(undefined4 *)(this + 0x40c) = *(undefined4 *)(iVar5 + 0x40);
    *(undefined4 *)(this + 0x410) = *(undefined4 *)(iVar5 + 0x44);
    *(undefined4 *)(this + 0x414) = *(undefined4 *)(iVar5 + 0x48);
    return;
  }
  if (bVar2 == 4) {
    pSVar24 = (SState *)0x1c;
    puVar23 = &stack0xffffffd4;
    (**(code **)(*(int *)pCVar1 + 4))();
    pCVar11 = this + 0x2e8;
    pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,(ulong)puVar23
                       );
    if (unaff_retaddr != (CClassicBufferMemory *)0x0) {
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)(pSVar4 + 0x16c));
      SVehicleSimpleState_ReplayAfter040104::RestoreFromStruct
                (auStack_24,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x2f8),
                 (SVehicleCarState *)(pSVar4 + 0x16c),pSVar24,(SState *)pSVar26,pSVar6,unaff_EDI);
      iVar5 = *(int *)(this + 0x28);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar5 + 0x34),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
      puVar14 = (undefined4 *)(*(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x328) + 0x10);
      pCVar11 = this + 0x32c;
      for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined4 *)pCVar11 = *puVar14;
        puVar14 = puVar14 + 1;
        pCVar11 = pCVar11 + 4;
      }
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar5 + 0x34),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)unaff_EBP);
      iVar5 = *(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x328);
      *(undefined4 *)(this + 0x364) = *(undefined4 *)(iVar5 + 0x40);
      *(undefined4 *)(this + 0x368) = *(undefined4 *)(iVar5 + 0x44);
      *(undefined4 *)(this + 0x36c) = *(undefined4 *)(iVar5 + 0x48);
      iVar5 = CSceneVehicle::UpdateEvent
                        ((CSceneVehicle *)this,(CSceneVehicle *)0x0,*(EVehicleEvent *)(this + 0x35c)
                         ,(ulong)unaff_EBX);
      if (iVar5 != 0) {
        (**(code **)(*(int *)this + 0x164))();
      }
      iVar5 = CSceneVehicle::UpdateEvent
                        ((CSceneVehicle *)this,(CSceneVehicle *)0x1,*(EVehicleEvent *)(this + 0x360)
                         ,(ulong)in_stack_ffffffd0);
      if (iVar5 == 0) {
        return;
      }
      CSceneVehicle::WaterSplash
                ((CSceneVehicle *)this,(CSceneVehicle *)(this + 0x364),(GmVec3 *)in_stack_ffffffd4);
      return;
    }
    pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                        (ulong)(pSVar4 + 0x1d0));
    pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                        (ulong)(pSVar4 + 0x1d0));
    pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                       (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)(pSVar4 + 0x1d0));
    SVehicleSimpleState_ReplayAfter040104::RestoreFromStruct
              (auStack_24,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x3a0),
               (SVehicleCarState *)(pSVar4 + 0x1d0),pSVar24,(SState *)pSVar26,pSVar6,unaff_EDI);
    iVar5 = *(int *)(this + 0x28);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar5 + 0x34),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                        ,unaff_ESI);
    puVar14 = (undefined4 *)(*(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x32c) + 0x10);
    pCVar11 = this + 0x3d4;
    for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined4 *)pCVar11 = *puVar14;
      puVar14 = puVar14 + 1;
      pCVar11 = pCVar11 + 4;
    }
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar5 + 0x34),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                        ,(ulong)unaff_EBP);
    iVar5 = *(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x32c);
    goto LAB_007cff2c;
  }
  if ((((bVar2 == 5) || (bVar2 == 7)) || (bVar2 == 8)) || (bVar2 == 9)) {
    if (unaff_retaddr == (CClassicBufferMemory *)0x0) {
      switch(bVar2 - 5) {
      case 0:
      case 2:
        pSVar25 = (SState *)0x1e;
        pSVar24 = (SState *)&stack0xffffffd4;
        pSVar15 = (SState *)0x7cfb97;
        (**(code **)(*(int *)pCVar1 + 4))();
        pCVar11 = this + 0x2e8;
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                            (ulong)pCVar19);
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                            (ulong)(pSVar4 + 0x1d0));
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                            (ulong)(pSVar4 + 0x1d0));
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)(pSVar4 + 0x1d0));
        SVehicleSimpleState_ReplayAfter040104::RestoreFromStruct
                  (&stack0xffffffd0,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x3a0),
                   (SVehicleCarState *)(pSVar4 + 0x1d0),(SState *)pCVar20,pSVar15,pSVar24,pSVar25);
        break;
      case 3:
        pSVar25 = (SState *)0x22;
        pSVar24 = (SState *)&stack0xffffffd4;
        pSVar15 = (SState *)0x7cfbfe;
        (**(code **)(*(int *)pCVar1 + 4))();
        pCVar11 = this + 0x2e8;
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                            (ulong)pCVar19);
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                            (ulong)(pSVar4 + 0x1d0));
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                            (ulong)(pSVar4 + 0x1d0));
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)(pSVar4 + 0x1d0));
        SVehicleSimpleState_ReplayAfter081205::RestoreFromStruct
                  (&stack0xffffffd0,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x3a0),
                   (SVehicleCarState *)(pSVar4 + 0x1d0),(SState *)pCVar20,pSVar15,pSVar24,pSVar25);
        break;
      case 4:
        pSVar25 = (SState *)&DAT_00000023;
        pSVar24 = (SState *)&stack0xffffffd4;
        pSVar15 = (SState *)0x7cfc62;
        (**(code **)(*(int *)pCVar1 + 4))();
        pCVar11 = this + 0x2e8;
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                            (ulong)pCVar19);
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                            (ulong)(pSVar4 + 0x1d0));
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                            (ulong)(pSVar4 + 0x1d0));
        pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)(pSVar4 + 0x1d0));
        SVehicleSimpleState_ReplayAfter170806::RestoreFromStruct
                  (&stack0xffffffd0,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x3a0),
                   (SVehicleCarState *)(pSVar4 + 0x1d0),(SState *)pCVar20,pSVar15,pSVar24,pSVar25);
      }
      iVar5 = *(int *)(this + 0x28);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar5 + 0x34),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)pSVar26);
      puVar14 = (undefined4 *)(*(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x32c) + 0x10);
      pCVar11 = this + 0x3d4;
      for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined4 *)pCVar11 = *puVar14;
        puVar14 = puVar14 + 1;
        pCVar11 = pCVar11 + 4;
      }
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar5 + 0x34),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)pSVar6);
      iVar5 = *(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x32c);
      goto LAB_007cff2c;
    }
    switch(bVar2 - 5) {
    case 0:
    case 2:
      pSVar25 = (SState *)0x1e;
      pSVar24 = (SState *)&stack0xffffffd4;
      pSVar15 = (SState *)0x7cf948;
      (**(code **)(*(int *)pCVar1 + 4))();
      pCVar11 = this + 0x2e8;
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                          (ulong)pCVar19);
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)(pSVar4 + 0x16c));
      SVehicleSimpleState_ReplayAfter040104::RestoreFromStruct
                (&stack0xffffffd0,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x2f8),
                 (SVehicleCarState *)(pSVar4 + 0x16c),(SState *)pCVar20,pSVar15,pSVar24,pSVar25);
      uVar10 = uStack_18 >> 0x14;
      *(uint *)(this + 0x654) = uStack_18 >> 0x12 & 3;
      *(uint *)(this + 0x1fc) = uStack_18 >> 0x16 & 3;
      this[0x200] = CStack_11;
      this[0x201] = aCStack_10[0];
      goto LAB_007cfadb;
    default:
      goto switchD_007cf931_caseD_1;
    case 3:
      pSVar25 = (SState *)0x22;
      pSVar24 = (SState *)&stack0xffffffd4;
      pSVar15 = (SState *)0x7cf9e9;
      (**(code **)(*(int *)pCVar1 + 4))();
      pCVar11 = this + 0x2e8;
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                          (ulong)pCVar19);
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)(pSVar4 + 0x16c));
      SVehicleSimpleState_ReplayAfter081205::RestoreFromStruct
                (&stack0xffffffd0,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x2f8),
                 (SVehicleCarState *)(pSVar4 + 0x16c),(SState *)pCVar20,pSVar15,pSVar24,pSVar25);
      break;
    case 4:
      pSVar25 = (SState *)&DAT_00000023;
      pSVar24 = (SState *)&stack0xffffffd4;
      pSVar15 = (SState *)0x7cfa4d;
      (**(code **)(*(int *)pCVar1 + 4))();
      pCVar11 = this + 0x2e8;
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                          (ulong)pCVar19);
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                          (ulong)(pSVar4 + 0x16c));
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)(pSVar4 + 0x16c));
      SVehicleSimpleState_ReplayAfter170806::RestoreFromStruct
                (&stack0xffffffd0,(SVehicleSimpleState_ReplayAfter040104 *)(this + 0x2f8),
                 (SVehicleCarState *)(pSVar4 + 0x16c),(SState *)pCVar20,pSVar15,pSVar24,pSVar25);
    }
    *(uint *)(this + 0x1fc) = (byte)pSStack_c >> 4 & 3;
    *(uint *)(this + 0x654) = (uint)pSStack_c & 3;
    uVar10 = (uint)((byte)pSStack_c >> 2);
    this[0x201] = SUB21((ushort)auStack_24[2]._1_2_ >> 8,0);
    this[0x200] = SUB21(auStack_24[2]._1_2_,0);
LAB_007cfadb:
    *(uint *)(this + 0x658) = uVar10 & 3;
switchD_007cf931_caseD_1:
    iVar5 = *(int *)(this + 0x28);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar5 + 0x34),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                        ,(ulong)pSVar26);
    puVar14 = (undefined4 *)(*(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x328) + 0x10);
    pCVar11 = this + 0x32c;
    for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined4 *)pCVar11 = *puVar14;
      puVar14 = puVar14 + 1;
      pCVar11 = pCVar11 + 4;
    }
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar5 + 0x34),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                        ,(ulong)pSVar6);
    iVar5 = *(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x328);
    *(undefined4 *)(this + 0x364) = *(undefined4 *)(iVar5 + 0x40);
    *(undefined4 *)(this + 0x368) = *(undefined4 *)(iVar5 + 0x44);
    *(undefined4 *)(this + 0x36c) = *(undefined4 *)(iVar5 + 0x48);
    iVar5 = CSceneVehicle::UpdateEvent
                      ((CSceneVehicle *)this,(CSceneVehicle *)0x0,*(EVehicleEvent *)(this + 0x35c),
                       (ulong)unaff_EDI);
    if (iVar5 != 0) {
      (**(code **)(*(int *)this + 0x164))();
    }
    iVar5 = CSceneVehicle::UpdateEvent
                      ((CSceneVehicle *)this,(CSceneVehicle *)0x1,*(EVehicleEvent *)(this + 0x360),
                       unaff_ESI);
    if (iVar5 == 0) goto LAB_007cf906;
  }
  else {
    if ((bVar2 != 3) && (bVar2 != 6)) {
      return;
    }
    this_01 = (SPlugFaceCull *)0x2;
    ppCVar22 = &pCStack_4;
    uVar21 = 0x7cf60a;
    (**(code **)(*(int *)pCVar1 + 4))();
    if (unaff_retaddr == (CClassicBufferMemory *)0x0) {
      pCVar17 = this + 0x2e8;
      pCVar11 = this + 0x3a0;
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar17,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          in_stack_ffffff9c);
      pSVar15 = (SState *)(pSVar4 + 0x1d0);
      pSStack_c = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                            (pCVar17,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                             in_stack_ffffffa0);
      pSStack_c = pSStack_c + 0x1d0;
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar17,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                          (ulong)pCVar19);
      pSVar24 = (SState *)(pSVar4 + 0x1d0);
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                          (ulong)pCVar20);
      pSVar6 = (SState *)(pSVar4 + 0x1d0);
    }
    else {
      pCVar17 = this + 0x2e8;
      pCVar11 = this + 0x2f8;
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar17,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          in_stack_ffffff9c);
      pSVar15 = (SState *)(pSVar4 + 0x16c);
      pSStack_c = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                            (pCVar17,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                             in_stack_ffffffa0);
      pSStack_c = pSStack_c + 0x16c;
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar17,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                          (ulong)pCVar19);
      pSVar24 = (SState *)(pSVar4 + 0x16c);
      pSVar4 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                          (ulong)pCVar20);
      pSVar6 = (SState *)(pSVar4 + 0x16c);
    }
    iVar5 = *(int *)(this + 0x378);
    SVehicleSimpleNetState::RestoreFromStruct
              (aCStack_10,(SVehicleSimpleState_ReplayAfter040104 *)pCVar11,
               *(SVehicleCarState **)(this + 0x59c),pSVar15,(SState *)pCStack_4,pSVar24,pSVar6);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 0x28) + 0x34),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar21);
    iVar8 = *(int *)(*(int *)pSVar4 + 0x58);
    if (iStack_8 == 0) {
      iVar13 = *(int *)(iVar8 + 0x32c);
    }
    else {
      iVar13 = *(int *)(iVar8 + 0x328);
    }
    puVar14 = (undefined4 *)(iVar13 + 0x10);
    pSVar16 = (SVehicleSimpleState_ReplayAfter040104 *)(pCVar11 + 0x34);
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined4 *)pSVar16 = *puVar14;
      puVar14 = puVar14 + 1;
      pSVar16 = pSVar16 + 4;
    }
    if ((iStack_8 == 0) || (*(int *)(this + 0x78) != 0)) {
      iVar8 = *(int *)(iVar8 + 0x32c);
    }
    else {
      iVar8 = *(int *)(iVar8 + 0x328);
    }
    *(undefined4 *)(pCVar11 + 0x6c) = *(undefined4 *)(iVar8 + 0x40);
    *(undefined4 *)(pCVar11 + 0x70) = *(undefined4 *)(iVar8 + 0x44);
    *(undefined4 *)(pCVar11 + 0x74) = *(undefined4 *)(iVar8 + 0x48);
    uVar28 = *(undefined4 *)(pCVar11 + 0x74);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 0x28) + 0x34),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)ppCVar22);
    GmVec3::MultTranspose(&stack0xffffffd0,(GmMat3 *)(*(int *)pSVar4 + 0x18),(GmMat3 *)this_01);
    *(undefined4 *)pCVar11 = auStack_24[0];
    *(undefined4 *)(pCVar11 + 4) = uVar28;
    if (*(int *)(this + 0x78) != 0) {
      param_2 = (CClassicBufferMemory *)(*(float *)(this + 0x378) - (float)param_3);
      GmFunc::Min(this_00,(GmVector3<unsigned_long> *)ABS((float)param_2),
                  (GmVector3<unsigned_long> *)
                  (((*(float *)(this + 0x59c) - *(float *)(this + 0x378)) / *(float *)(this + 0x59c)
                   ) * (float)_DAT_00b2f710 + (float)_DAT_00b9f5f8));
      this_01 = (SPlugFaceCull *)0x7cf7e3;
      pSVar26 = (SPlugFaceCull *)param_4;
      fVar18 = GmFunc::Sign((float)param_4,(float)extraout_ST0);
      *(float *)(this + 0x378) = fVar18 + (float)param_5;
    }
    param_5 = (uint)param_1 >> 8 & 1;
    *(uint *)(pCVar11 + 0x68) = ((uint)param_1 & 0xff) >> 6;
    if (*(int *)(this + 0x78) != 0) {
      pGVar27 = (GmIso4 *)0x7cf819;
      param_5 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
      pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (param_5 != 0) {
        do {
          pSVar7 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                             (this + 0x2e8,pCVar12,(ulong)this_01);
          pSVar4 = pSVar7 + 0x16c;
          if (iVar5 == 0) {
            pSVar4 = pSVar7 + 0x1d0;
          }
          this_01 = (SPlugFaceCull *)(pSVar4 + 0x24);
          *(undefined4 *)this_01 = *(undefined4 *)(pSVar7 + 100);
          *(undefined4 *)(pSVar4 + 0x28) = *(undefined4 *)(pSVar7 + 0x68);
          *(undefined4 *)(pSVar4 + 0x2c) = *(undefined4 *)(pSVar7 + 0x6c);
          *(float *)(pSVar4 + 0x28) = *(float *)(pSVar4 + 0x28) - *(float *)(pSVar7 + 8);
          GmVec3::Mult(this_01,(GmIso3 *)
                               (*(int *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 100) + 0x5c),
                       (GmIso3 *)pSVar26);
          pSVar26 = (SPlugFaceCull *)(this + 0x32c);
          GmVec3::SetMult(pSVar4 + 0x18,this_01,pSVar26,pGVar27);
          pCVar12 = pCVar12 + 1;
        } while (pCVar12 < param_4);
      }
    }
    if (param_2 == (CClassicBufferMemory *)0x0) {
      return;
    }
    iVar5 = CSceneVehicle::UpdateEvent
                      ((CSceneVehicle *)this,(CSceneVehicle *)0x0,*(EVehicleEvent *)(this + 0x35c),
                       (ulong)unaff_EDI);
    if (iVar5 != 0) {
      (**(code **)(*(int *)this + 0x164))();
    }
    iVar5 = CSceneVehicle::UpdateEvent
                      ((CSceneVehicle *)this,(CSceneVehicle *)0x1,*(EVehicleEvent *)(this + 0x360),
                       unaff_ESI);
    if (iVar5 == 0) goto LAB_007cf906;
    if (in_stack_0000001c != 0) {
      *(undefined4 *)(this + 0x658) = 2;
      this[0x201] = (CSceneVehicleCar)0x10;
      *(ulong *)(this + 0x650) = param_5;
      return;
    }
  }
  CSceneVehicle::WaterSplash((CSceneVehicle *)this,(CSceneVehicle *)(this + 0x364),unaff_EBP);
LAB_007cf906:
  *(ulong *)(this + 0x650) = param_5;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::SaveState
// =================================================
void __thiscall
CSceneVehicleCar::SaveState
          (CSceneVehicleCar *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,
          ulong *param_3,ulong param_4)
{
{
  CSceneVehicleCar *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CSceneMobil *unaff_EBP;
  ulong unaff_ESI;
  ulong *unaff_EDI;
  SState *unaff_retaddr;
  byte in_stack_00000034;
  float in_stack_ffffffdc;
  SState *in_stack_ffffffe0;
  int in_stack_ffffffe4;
  SState *in_stack_ffffffe8;
  int in_stack_ffffffec;
  SState *in_stack_fffffff0;
  int in_stack_fffffff4;
  SState *in_stack_fffffff8;
  undefined1 *puVar4;
  int in_stack_fffffffc;
  int iVar5;
  
  *(undefined4 *)param_2 = *(undefined4 *)(*(int *)(this + 0x28) + 0x48);
  if (param_3 != (ulong *)&DAT_00000006) {
    if (param_3 == (ulong *)&DAT_00000009) {
      CHmsItem::SaveState(*(CHmsItem **)(this + 0x28),param_1,(CClassicBufferMemory *)0x1,unaff_EDI,
                          unaff_ESI);
      pCVar1 = this + 0x2e8;
      pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                          (ulong)unaff_EBP);
      pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                          (ulong)(pSVar2 + 0x16c));
      pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                          (ulong)(pSVar2 + 0x16c));
      pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)(pSVar2 + 0x16c));
      SVehicleSimpleState_ReplayAfter170806::SaveToStruct
                (&stack0xfffffff4,(SVehicleSimpleNetState *)(this + 0x2f8),
                 (SVehicleCarState *)(pSVar2 + 0x16c),in_stack_ffffffdc,(ulong)in_stack_ffffffe0,
                 in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec,in_stack_fffffff0,
                 in_stack_fffffff4,in_stack_fffffff8,in_stack_fffffffc,unaff_retaddr,(int)param_1);
      in_stack_00000034 =
           (((byte)this[0x668] & 3) * '\x04' | (byte)this[0x660] & 3) * '\x04' |
           (byte)this[0x664] & 3 | in_stack_00000034 & 0xc0;
      (**(code **)(*(int *)param_1 + 8))();
    }
    goto LAB_007cf2e5;
  }
  CHmsItem::SaveState(*(CHmsItem **)(this + 0x28),param_1,(CClassicBufferMemory *)0x0,unaff_EDI,
                      unaff_ESI);
  iVar3 = CSceneMobil::IsZombie((CSceneMobil *)this,unaff_EBP);
  if (iVar3 == 0) {
    if (*(uint *)(this + 0xbc) < *(uint *)(this + 0x360)) {
      *(uint *)(this + 0xbc) = *(uint *)(this + 0x360);
      *(undefined4 *)(this + 0xc4) = 0;
    }
    else {
      if (((uint)(*(int *)(this + 0x664) + *(int *)(this + 0x660)) < 3) &&
         (*(int *)(this + 0x668) == 0)) goto LAB_007cf1f4;
      *(undefined4 *)(this + 0xc4) = 1;
    }
    *(int *)(this + 0xc0) = *(int *)(this + 0xc0) + 1;
  }
LAB_007cf1f4:
  pCVar1 = this + 0x2e8;
  pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                      (ulong)in_stack_ffffffdc);
  pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                      *(ulong *)(pSVar2 + 4));
  pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                      (ulong)(pSVar2 + 0x16c));
  pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                      *(ulong *)(pSVar2 + 4));
  pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      (ulong)(pSVar2 + 0x16c));
  pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      *(ulong *)(pSVar2 + 4));
  pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      (ulong)(pSVar2 + 0x16c));
  pSVar2 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      *(ulong *)(pSVar2 + 4));
  SVehicleSimpleNetState::SaveToStruct
            (&stack0x00000030,(SVehicleSimpleNetState *)(this + 0x2f8),
             *(SVehicleCarState **)(this + 0x59c),*(float *)(this + 0xc0),*(ulong *)(this + 0xc4),
             (int)(pSVar2 + 0x16c),in_stack_ffffffe0,in_stack_ffffffe4,in_stack_ffffffe8,
             in_stack_ffffffec,in_stack_fffffff0,in_stack_fffffff4,in_stack_fffffff8,
             in_stack_fffffffc);
  iVar5 = 2;
  puVar4 = &stack0x00000034;
  (**(code **)(*(int *)param_1 + 8))();
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)puVar4);
  iVar3 = *(int *)(*(int *)(*(int *)pSVar2 + 0x58) + 0x328);
  *(undefined4 *)(this + 0x86c) = *(undefined4 *)(iVar3 + 0x34);
  *(undefined4 *)(this + 0x870) = *(undefined4 *)(iVar3 + 0x38);
  *(undefined4 *)(this + 0x874) = *(undefined4 *)(iVar3 + 0x3c);
  GmMat3::Set(this + 0x848,(CMwCmdScriptVarBool *)(iVar3 + 0x10),iVar5);
LAB_007cf2e5:
  *(undefined4 *)(this + 0x664) = 0;
  *(undefined4 *)(this + 0x660) = 0;
  *(undefined4 *)(this + 0x668) = 0;
  this[0x66d] = (CSceneVehicleCar)0x0;
  this[0x66c] = (CSceneVehicleCar)0x0;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::SetVehicleAngularSpeed
// =================================================
void __thiscall
CSceneVehicleCar::SetVehicleAngularSpeed
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2)
{
{
  CHmsItem::SetAngularSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)param_1,param_2);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::SetVehicleLinearSpeed
// =================================================
void __thiscall
CSceneVehicleCar::SetVehicleLinearSpeed
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,GmVec3 *param_2)
{
{
  CHmsItem::SetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)param_1,param_2);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::UpdateParamsFromTuning
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::UpdateParamsFromTuning(CSceneVehicleCar *this,CSceneToyCharacter *param_1)
{
{
  void *this_00;
  float fVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  GmVec3 *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *this_01;
  float in_stack_0000000c;
  ulong in_stack_ffffffa0;
  ulong in_stack_ffffffa4;
  CMwNodRef<class_CGameCamera> *in_stack_ffffffa8;
  CMwNodRef<class_CGameCamera> *in_stack_ffffffac;
  CMwNodRef<class_CGameCamera> *pCVar9;
  float in_stack_ffffffb4;
  float fVar10;
  GmVec3 *pGVar11;
  float in_stack_ffffffb8;
  float fVar12;
  float in_stack_ffffffbc;
  float fVar13;
  float in_stack_ffffffc0;
  float fVar14;
  GmVec3 *pGVar15;
  float in_stack_ffffffc4;
  float fVar16;
  float in_stack_ffffffc8;
  float fVar17;
  float in_stack_ffffffcc;
  float in_stack_ffffffd0;
  float fStack_c;
  float local_8;
  
  if (*(int *)(*(int *)(this + 0x28) + 0x14) != 0) {
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EDI);
    if (uVar4 != 0) {
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EBP);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pCVar9 = in_stack_ffffffac;
      fVar12 = in_stack_ffffffb8;
      fVar13 = in_stack_ffffffbc;
      fVar14 = in_stack_ffffffc0;
      fVar16 = in_stack_ffffffc4;
      fVar17 = in_stack_ffffffc8;
      if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                             (this + 0x2e8,pCVar8,(ulong)unaff_EBX);
          if ((*(int *)(pSVar6 + 0xc) != 0) &&
             (iVar2 = *(int *)(*(int *)(pSVar6 + 0xc) + 0x8c), iVar2 != 0)) {
            this_00 = (void *)(iVar2 + 0x18);
            unaff_EBX = (CFastBuffer<class_CCrystalFace*> *)0x7c0009;
            uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                              (this_00,(CFastBuffer<class_CCrystalFace*> *)0x7c0009);
            if (uVar4 == 1) {
              unaff_EBX = (CFastBuffer<class_CCrystalFace*> *)0x7c001d;
              pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(*(int *)(this + 100) + 0x14),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (*(int *)(this + 100) + 0x24),in_stack_ffffffa0);
              pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (&DAT_00d6efb8,
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (*(int *)pSVar7 + 0x16c),in_stack_ffffffa4);
              in_stack_ffffffa0 = 0;
              unaff_ESI = (GmVec3 *)0x7c003c;
              pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                  *(ulong *)pSVar7);
              in_stack_ffffffa4 = 0x7c0043;
              CMwNodRef<class_CGameCamera>::MwSetNod(pSVar7,in_stack_ffffffa8,(CGameCamera *)pCVar9)
              ;
            }
          }
          in_stack_ffffffcc = *(float *)(pSVar6 + 0x34);
          in_stack_ffffffd0 = *(float *)(pSVar6 + 0x38);
          fVar1 = *(float *)(pSVar6 + 0x3c);
          in_stack_ffffffa8 = *(CMwNodRef<class_CGameCamera> **)(pSVar6 + 8);
          fStack_c = in_stack_ffffffd0 - *(float *)(pSVar6 + 8);
          in_stack_ffffffac = in_stack_ffffffa8;
          fVar10 = in_stack_ffffffcc;
          in_stack_ffffffb8 = in_stack_ffffffd0;
          in_stack_ffffffbc = fVar1;
          in_stack_ffffffc0 = in_stack_ffffffcc;
          in_stack_ffffffc4 = in_stack_ffffffd0;
          in_stack_ffffffc8 = fVar1;
          if (pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            if ((float)pCVar9 < (float)in_stack_ffffffa8) {
              pCVar9 = in_stack_ffffffa8;
            }
            if (in_stack_ffffffcc < fVar14) {
              fVar14 = in_stack_ffffffcc;
            }
            if (in_stack_ffffffd0 < fVar16) {
              fVar16 = in_stack_ffffffd0;
            }
            if (fVar1 < fVar17) {
              fVar17 = fVar1;
            }
            if (in_stack_ffffffb4 < in_stack_ffffffcc) {
              in_stack_ffffffb4 = in_stack_ffffffcc;
            }
            if (fVar12 < in_stack_ffffffd0) {
              fVar12 = in_stack_ffffffd0;
            }
            in_stack_ffffffac = pCVar9;
            fVar10 = in_stack_ffffffb4;
            in_stack_ffffffb8 = fVar12;
            in_stack_ffffffbc = fVar13;
            in_stack_ffffffc0 = fVar14;
            in_stack_ffffffc4 = fVar16;
            in_stack_ffffffc8 = fVar17;
            if (fVar13 < fVar1) {
              in_stack_ffffffbc = fVar1;
            }
          }
          pCVar8 = pCVar8 + 1;
          pCVar9 = in_stack_ffffffac;
          in_stack_ffffffb4 = fVar10;
          fVar12 = in_stack_ffffffb8;
          fVar13 = in_stack_ffffffbc;
          fVar14 = in_stack_ffffffc0;
          fVar16 = in_stack_ffffffc4;
          fVar17 = in_stack_ffffffc8;
        } while (pCVar8 < pCVar5);
      }
      uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EBX);
      fVar12 = (float)(int)uVar4;
      if ((int)uVar4 < 0) {
        fVar12 = fVar12 + _DAT_00c418d0;
      }
      pGVar11 = (GmVec3 *)(1.0 / fVar12);
      GmBoxAligned::SetMinMax
                (&fStack_c,(GmBoxAligned *)&stack0xffffffc4,(GmVec3 *)&stack0xffffffb8,unaff_ESI);
      iVar2 = *(int *)(this + 100);
      *(float *)(this + 0x840) = in_stack_0000000c + in_stack_0000000c;
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                ((void *)(iVar2 + 0x14),
                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                 in_stack_ffffffa0);
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                ((void *)(iVar2 + 0x14),
                 *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                 in_stack_ffffffa4);
      pGVar15 = (GmVec3 *)(in_stack_ffffffc0 * local_8);
      iVar3 = *(int *)(*(int *)(this + 0x28) + 0x14);
      this_01 = (undefined4 *)(iVar3 + 0x18);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          (ulong)in_stack_ffffffa8);
      *this_01 = *(undefined4 *)(*(int *)pSVar6 + 0x130);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)in_stack_ffffffac);
      *(undefined4 *)(iVar3 + 0x4c) = *(undefined4 *)(*(int *)pSVar6 + 0x160);
      *(undefined4 *)(iVar3 + 0x40) = 0;
      *(undefined4 *)(iVar3 + 0x44) = 0;
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),(ulong)pCVar5);
      *(undefined4 *)(iVar3 + 0x48) = *(undefined4 *)(*(int *)pSVar6 + 0x168);
      CPlugPhysicalObject::SetComPos(this_01,(CPlugPhysicalObject *)&fStack_c,pGVar11);
      iVar2 = *(int *)(this + 100);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          (ulong)in_stack_ffffffb8);
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          (ulong)in_stack_ffffffbc);
      CPlugPhysicalObject::SetInertiaMatrixBox
                (this_01,*(CPlugPhysicalObject **)(*(int *)pSVar7 + 0x134),
                 (float)(*(int *)pSVar6 + 0x138),pGVar15);
      iVar2 = *(int *)(this + 100);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          (ulong)in_stack_ffffffc4);
      *(undefined4 *)(this + 0x718) = *(undefined4 *)(*(int *)pSVar6 + 0x7c);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          (ulong)in_stack_ffffffc8);
      *(undefined4 *)(this + 0x71c) = *(undefined4 *)(*(int *)pSVar6 + 0x88);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          (ulong)in_stack_ffffffcc);
      *(undefined4 *)(this + 0x720) = *(undefined4 *)(*(int *)pSVar6 + 0x8c);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          (ulong)in_stack_ffffffd0);
      *(undefined4 *)(this + 0x59c) = *(undefined4 *)(*(int *)pSVar6 + 0x2d0);
    }
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::UpdateTurbo
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::UpdateTurbo(CSceneVehicleCar *this,CSceneVehicleCar *param_1,ulong param_2)
{
{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (*(int *)(this + 0x600) != 0) {
    if (*(CSceneVehicleCar **)(this + 0x5fc) < param_1) {
      *(undefined4 *)(this + 0x600) = 0;
    }
    if (*(int *)(this + 0x600) != 0) {
      iVar3 = (int)param_1 - *(int *)(this + 0x5f8);
      fVar1 = (float)iVar3;
      if (iVar3 < 0) {
        fVar1 = fVar1 + _DAT_00c418d0;
      }
      iVar3 = *(int *)(this + 0x5fc) - *(int *)(this + 0x5f8);
      fVar2 = (float)iVar3;
      if (iVar3 < 0) {
        fVar2 = fVar2 + _DAT_00c418d0;
      }
      *(float *)(this + 0x5f0) = fVar1 / fVar2;
      return;
    }
  }
  *(undefined4 *)(this + 0x5f0) = 0;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::VehicleAsyncWorldSpeedGet
// =================================================
void __thiscall
CSceneVehicleCar::VehicleAsyncWorldSpeedGet
          (CSceneVehicleCar *this,CSceneVehicle *param_1,GmVec3 *param_2)
{
{
  *(undefined4 *)param_1 = *(undefined4 *)(this + 0x4b4);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(this + 0x4b8);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(this + 0x4bc);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::VehicleBlockSpeed2Set
// =================================================
void __thiscall
CSceneVehicleCar::VehicleBlockSpeed2Set(CSceneVehicleCar *this,CSceneMobil *param_1,int param_2)
{
{
  *(uint *)(this + 0x2f4) =
       *(uint *)(this + 0x2f4) ^
       ((uint)(param_1 != (CSceneMobil *)0x0) << 5 ^ *(uint *)(this + 0x2f4)) & 0x20;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::VehicleBlockSpeedSet
// =================================================
void __thiscall
CSceneVehicleCar::VehicleBlockSpeedSet(CSceneVehicleCar *this,CSceneVehicleCar *param_1,int param_2)
{
{
  *(uint *)(this + 0x2f4) =
       *(uint *)(this + 0x2f4) ^
       ((uint)(param_1 != (CSceneVehicleCar *)0x0) << 4 ^ *(uint *)(this + 0x2f4)) & 0x10;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::VehicleFreeWheelingSet
// =================================================
void __thiscall
CSceneVehicleCar::VehicleFreeWheelingSet
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,int param_2)
{
{
  *(CSceneVehicleCar **)(this + 0x60c) = param_1;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::VehicleInitFromSolid
// =================================================
void __thiscall
CSceneVehicleCar::VehicleInitFromSolid(CSceneVehicleCar *this,CSceneVehicle *param_1)
{
{
  CSceneVehicleCar *this_00;
  undefined4 uVar1;
  int iVar2;
  CFastBuffer<class_GxVertex2> *pCVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  CPlugTree *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  ulong unaff_EBP;
  CLoadGeomDynaSprite *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CPlugTree *pCVar8;
  CSceneVehicle *in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  CVisionViewportDx9 *pCVar9;
  ESpriteColor0 *in_stack_ffffffc8;
  CSceneVehicleCar *pCVar10;
  CLoadGeomDynaSprite *local_28;
  CPlugTree local_14 [20];
  
  if (*(int *)(this + 0x60) == 0) {
    return;
  }
  pCVar9 = *(CVisionViewportDx9 **)(*(int *)(this + 0x28) + 0x14);
  pCVar8 = (CPlugTree *)(*(int *)(this + 0x60) + 0x14);
  this_00 = this + 0x2e8;
  pCVar6 = pCVar8;
  pCVar10 = this;
  pCVar3 = (CFastBuffer<class_GxVertex2> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(pCVar8,unaff_EDI);
  CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::AllocSetCount(this_00,pCVar3,unaff_EBP);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar5 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this_00,pCVar7,(ulong)unaff_ESI);
      pCVar6 = (CPlugTree *)
               CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (pCVar8,pCVar7,(ulong)pCVar6);
      *(undefined4 *)pSVar5 = *(undefined4 *)(pCVar6 + 4);
      *(undefined4 *)(pSVar5 + 4) = *(undefined4 *)(pCVar6 + 8);
      unaff_ESI = local_28;
      CSceneVehicle::SSurfaceHandler::Init
                (pSVar5 + 0xc,local_28,(CPlugVisualSprite *)pCVar6,pCVar9,in_stack_ffffffc8);
      pCVar8 = *(CPlugTree **)(pSVar5 + 0xc);
      if (pCVar8 == (CPlugTree *)0x0) {
LAB_007c33cb:
        *(undefined4 *)(pSVar5 + 0xb0) = 0;
        *(undefined4 *)(pSVar5 + 0xac) = 0;
        *(undefined4 *)(pSVar5 + 0xa8) = 0;
        pCVar8 = (CPlugTree *)pCVar10;
      }
      else {
        if ((*(int *)(pCVar8 + 0x8c) != 0) &&
           (iVar2 = *(int *)(*(int *)(pCVar8 + 0x8c) + 0x14), iVar2 != 0)) {
          iVar2 = *(int *)(iVar2 + 0x34);
          if (*(char *)(iVar2 + 6) == '\0') {
            uVar1 = *(undefined4 *)(iVar2 + 8);
          }
          else {
            if (*(char *)(iVar2 + 6) != '\x01') goto LAB_007c3399;
            uVar1 = *(undefined4 *)(iVar2 + 0xc);
          }
          *(undefined4 *)(pSVar5 + 8) = uVar1;
        }
LAB_007c3399:
        if (pCVar8 == (CPlugTree *)0x0) goto LAB_007c33cb;
        in_stack_ffffffc8 = (ESpriteColor0 *)0x0;
        pCVar9 = (CVisionViewportDx9 *)0x1;
        pCVar6 = local_14;
        unaff_ESI = (CLoadGeomDynaSprite *)0x7c33ab;
        CPlugTree::GetThisToRootTransfo(pCVar8,pCVar6,(GmIso4 *)0x1,0,(CPlugTree *)pCVar10);
        *(undefined4 *)(pSVar5 + 0xa8) = in_stack_00000014;
        *(undefined4 *)(pSVar5 + 0xac) = in_stack_00000018;
        *(undefined4 *)(pSVar5 + 0xb0) = in_stack_0000001c;
        pCVar8 = (CPlugTree *)pCVar10;
      }
      pCVar7 = pCVar7 + 1;
      this = (CSceneVehicleCar *)local_28;
      pCVar10 = (CSceneVehicleCar *)pCVar8;
    } while (pCVar7 < pCVar4);
  }
  (**(code **)(*(int *)this + 0x174))();
  CSceneVehicle::VehicleInitFromSolid((CSceneVehicle *)this,in_stack_00000010);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::VehicleReset
// =================================================
void __thiscall CSceneVehicleCar::VehicleReset(CSceneVehicleCar *this,CSceneVehicleBall *param_1)
{
{
  SCasterCat *pSVar1;
  GmFrustumIso4 *unaff_EBX;
  GmFrustumIso4 *unaff_EBP;
  int iVar2;
  GmFrustumIso4 *unaff_ESI;
  CSceneVehicleBall *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CSceneVehicleCar *pCVar4;
  GmMat43 *unaff_retaddr;
  SCasterCat *in_stack_00000008;
  GmFrustumIso4 *in_stack_0000000c;
  ulong in_stack_00000010;
  ulong uStack00000018;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000020;
  
  pCVar4 = this;
  CSceneVehicle::VehicleReset((CSceneVehicle *)this,unaff_EDI);
  SVehicleCarState::Reset(this + 0x448,unaff_ESI);
  SVehicleCarState::Reset(this + 0x4f0,unaff_EBP);
  SVehicleCarState::Reset(this + 0x2f8,unaff_EBX);
  SVehicleCarState::Reset(this + 0x3a0,(GmFrustumIso4 *)pCVar4);
  *(undefined4 *)(this + 0x404) = *(undefined4 *)(this + 0xb0);
  *(undefined4 *)(this + 0x35c) = *(undefined4 *)(this + 0xb0);
  *(undefined4 *)(this + 0x408) = *(undefined4 *)(this + 0xb8);
  *(undefined4 *)(this + 0x360) = *(undefined4 *)(this + 0xb8);
  *(undefined4 *)(this + 0x5e8) = 0;
  *(undefined4 *)(this + 0x5f0) = 0;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(this + 0xb8);
  *(undefined4 *)(this + 0x600) = 0;
  *(undefined4 *)(this + 0x610) = 0;
  *(undefined4 *)(this + 0x5d4) = 0;
  *(undefined4 *)(this + 0x5d8) = 0;
  *(undefined4 *)(this + 0x5dc) = 0;
  *(undefined4 *)(this + 0x614) = 0;
  *(undefined4 *)(this + 0x620) = 0;
  *(undefined4 *)(this + 0x61c) = 0;
  *(undefined4 *)(this + 0x618) = 0;
  *(undefined4 *)(this + 0x5f4) = 0;
  *(undefined4 *)(this + 0x628) = 0;
  *(undefined4 *)(this + 0x638) = 0;
  *(undefined4 *)(this + 0x640) = 0;
  *(undefined4 *)(this + 0x63c) = 0;
  *(undefined4 *)(this + 0x5e0) = 0xffffffff;
  *(undefined4 *)(this + 0x644) = 0;
  *(undefined4 *)(this + 0x648) = 0xffffffff;
  *(undefined4 *)(this + 0x62c) = 0xffffffff;
  *(undefined4 *)(this + 0x630) = 0xffffffff;
  *(undefined4 *)(this + 0x5e4) = 0;
  *(undefined4 *)(this + 0x6a0) = 0;
  *(undefined4 *)(this + 0x6f4) = 0xffffffff;
  *(undefined4 *)(this + 0x6f8) = 0xffffffff;
  GmIso4::SetIdentity(this + 0x6a4,unaff_retaddr);
  *(undefined4 *)(this + 0x704) = 0;
  *(undefined4 *)(this + 0x700) = 0;
  *(undefined4 *)(this + 0x6fc) = 0;
  *(undefined4 *)(this + 0x714) = 0;
  *(undefined4 *)(this + 0x710) = 0;
  *(undefined4 *)(this + 0x70c) = 0;
  *(undefined4 *)(this + 0x624) = 0;
  *(undefined4 *)(this + 0x69c) = 0;
  *(undefined4 *)(this + 0x2e4) = 0;
  *(undefined4 *)(this + 0x744) = 0;
  *(undefined4 *)(this + 0x728) = 0;
  *(undefined4 *)(this + 0x730) = 0;
  *(undefined4 *)(this + 0x724) = 0x3f800000;
  *(undefined4 *)(this + 0x734) = 0;
  *(undefined4 *)(this + 0x738) = 0;
  *(undefined4 *)(this + 500) = 0;
  *(undefined4 *)(this + 0x73c) = 0;
  *(undefined4 *)(this + 0x740) = 0xffffffff;
  *(undefined4 *)(this + 0x654) = 0;
  *(undefined4 *)(this + 0x658) = 0;
  *(undefined4 *)(this + 0x1fc) = 0;
  this[0x201] = (CSceneVehicleCar)0x0;
  this[0x200] = (CSceneVehicleCar)0x0;
  *(undefined4 *)(this + 0x210) = 0;
  *(undefined4 *)(this + 0x660) = 0;
  *(undefined4 *)(this + 0x664) = 0;
  *(undefined4 *)(this + 0x668) = 0;
  *(undefined4 *)(this + 0x670) = 0;
  this[0x66c] = (CSceneVehicleCar)0x0;
  *(undefined4 *)(this + 0x674) = 0;
  this[0x66d] = (CSceneVehicleCar)0x0;
  *(undefined4 *)(this + 0x678) = 0;
  *(undefined4 *)(this + 0x650) = 0;
  *(undefined4 *)(this + 0x65c) = 0;
  *(undefined4 *)(this + 0x820) = 0;
  *(undefined4 *)(this + 0x81c) = 0;
  *(undefined4 *)(this + 0x818) = 0;
  *(undefined4 *)(this + 0x82c) = 0;
  *(undefined4 *)(this + 0x828) = 0;
  *(undefined4 *)(this + 0x824) = 0;
  uStack00000018 =
       CFastBuffer<class_CCrystalFace*>::GetCount
                 (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)param_1);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uStack00000018 != 0) {
    do {
      in_stack_00000008 =
           CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (this + 0x2e8,pCVar3,(ulong)in_stack_00000008);
      WheelReset(this,(CSceneVehicleCar *)in_stack_00000008,(SSimulationWheel *)in_stack_0000000c);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < in_stack_00000020);
  }
  SEngine::Reset(this + 0x59c,(GmFrustumIso4 *)in_stack_00000008);
  pCVar4 = this + 0x750;
  iVar2 = 4;
  do {
    SDynaPart::Reset(pCVar4,in_stack_0000000c);
    pCVar4 = pCVar4 + 0x30;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = *(int *)(*(int *)(this + 0x28) + 0x14);
  if (iVar2 != 0) {
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 100) + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                         (*(int *)(this + 100) + 0x24),in_stack_00000010);
    *(undefined4 *)(iVar2 + 0x4c) = *(undefined4 *)(*(int *)pSVar1 + 0x160);
    *(undefined4 *)(iVar2 + 0x40) = 0;
  }
  *(undefined4 *)(this + 0x68c) = 0;
  *(undefined4 *)(this + 0x688) = 0;
  *(undefined4 *)(this + 0x684) = 0;
  *(undefined4 *)(this + 0x698) = 0;
  *(undefined4 *)(this + 0x694) = 0;
  *(undefined4 *)(this + 0x690) = 0;
  *(undefined4 *)(this + 0x680) = 0;
  *(undefined4 *)(this + 0x67c) = 0;
  *(undefined4 *)(this + 0x810) = 0;
  *(undefined4 *)(this + 0x834) = 0;
  *(undefined4 *)(this + 0x838) = 0;
  *(undefined4 *)(this + 0x83c) = 0;
  *(undefined4 *)(this + 0x60c) = 0;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::VehicleStateAsyncGet
// =================================================
SVehicleState * __thiscall
CSceneVehicleCar::VehicleStateAsyncGet(CSceneVehicleCar *this,CSceneVehicleBall *param_1)
{
{
  return (SVehicleState *)(this + 0x448);
}
}

// =================================================
// Function: CSceneVehicleCar::VehicleStatePrevAsyncGet
// =================================================
SVehicleState * __thiscall
CSceneVehicleCar::VehicleStatePrevAsyncGet(CSceneVehicleCar *this,CSceneVehicleBall *param_1)
{
{
  return (SVehicleState *)(this + 0x4f0);
}
}

// =================================================
// Function: CSceneVehicleCar::VehicleUpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::VehicleUpdateAsync(CSceneVehicleCar *this,CSceneVehicleBall *param_1)
{
{
  SCasterCat *this_00;
  undefined4 uVar1;
  int iVar2;
  GmIso4 *pGVar3;
  float fVar4;
  SCasterCat *pSVar5;
  SCasterCat *pSVar6;
  GmScaleTrans2 *pGVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CMwId *pCVar9;
  uint uVar10;
  void *pvVar11;
  uint uVar12;
  int iVar13;
  CPlugAudio *this_01;
  code *pcVar14;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar15;
  SCasterCat *this_02;
  SCasterCat *unaff_EBP;
  CSceneMobil *unaff_ESI;
  undefined4 *puVar16;
  CSceneVehicleCar *unaff_EDI;
  SCasterCat *pSVar17;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar18;
  float fVar19;
  GmIso4 *pGVar20;
  float fVar21;
  CSceneVehicleBall *in_stack_00000034;
  GmMat43 *pGVar22;
  GmIso3 *pGVar23;
  CMwTimerAdapter *in_stack_ffffff40;
  GmIso3 *in_stack_ffffff44;
  GmIso4 *in_stack_ffffff4c;
  SCasterCat *pSVar24;
  int in_stack_ffffff50;
  GmIso4 *pGVar25;
  SVisualHandler *pSVar26;
  SVisualHandler *pSVar27;
  ulong uVar28;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff58;
  GmMat3 *pGVar29;
  SCasterCat *in_stack_ffffff5c;
  SVisualHandler *in_stack_ffffff60;
  CPlugFileVideo *pCVar30;
  GmIso4 *in_stack_ffffff64;
  EPlugVideoTimer EVar31;
  GmIso3 *in_stack_ffffff68;
  GmIso3 *in_stack_ffffff6c;
  GmMat43 *in_stack_ffffff70;
  GmMat43 *pGVar32;
  GmMat43 *in_stack_ffffff74;
  SCasterCat *pSVar33;
  SCasterCat *in_stack_ffffff80;
  CSceneVehicleCar *local_78;
  SCasterCat *pSStack_74;
  float fStack_70;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_6c;
  int local_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float local_54;
  float fStack_50;
  float fStack_4c;
  undefined4 local_48;
  float fStack_44;
  float fStack_40;
  float local_3c [3];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined4 local_24 [2];
  undefined1 local_1c [4];
  undefined1 auStack_18 [4];
  SPlugFaceCull aSStack_14 [4];
  undefined1 local_10 [4];
  undefined4 local_c;
  float local_8;
  float local_4;
  
  if ((DAT_00d06e00 == 0) || (*(int *)(this + 0x4c) == 0)) {
    return;
  }
  ComputeAsyncState(this,unaff_EDI);
  pGVar22 = (GmMat43 *)0x7c1a6f;
  fVar4 = (float)CSceneMobil::IsZombie((CSceneMobil *)this,unaff_ESI);
  pSVar5 = (SCasterCat *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2e8,unaff_EBX);
  pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pSVar33 = pSVar5;
  if (pSVar5 != (SCasterCat *)0x0) {
    do {
      pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar15,(ulong)unaff_EBP);
      if (in_stack_ffffff50 != 0) {
        fVar19 = *(float *)(pSVar6 + 0x298);
        pSVar5 = pSVar6 + 0x10;
        pSVar17 = pSVar6 + 0x40;
        for (iVar13 = 0xc; iVar13 != 0; iVar13 = iVar13 + -1) {
          *(undefined4 *)pSVar17 = *(undefined4 *)pSVar5;
          pSVar5 = pSVar5 + 4;
          pSVar17 = pSVar17 + 4;
        }
        pSVar5 = (SCasterCat *)((float)_PTR_00b2c178 * -fVar19);
        *(float *)(pSVar6 + 100) = *(float *)(pSVar6 + 100) + (float)pSVar5;
        *(float *)(pSVar6 + 0x68) = -fVar19 + *(float *)(pSVar6 + 0x68);
        *(float *)(pSVar6 + 0x6c) = (float)pSVar5 + *(float *)(pSVar6 + 0x6c);
        unaff_EBP = (SCasterCat *)0x7c1b04;
        in_stack_ffffff80 = pSVar5;
        CSceneVehicle::SSurfaceHandler::UpdateSurface(pSVar6 + 0xc,(SSurfaceHandler *)0x7c1b04);
        in_stack_ffffff5c = pSVar5;
      }
      pCVar15 = pCVar15 + 1;
    } while (pCVar15 < pSVar5);
  }
  if (*(CPlugShaderGeneric **)(this + 0x2d4) != (CPlugShaderGeneric *)0x0) {
    in_stack_ffffff58 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x468);
    pGVar22 = (GmMat43 *)0x1;
    in_stack_ffffff4c = (GmIso4 *)0x3f800000;
    in_stack_ffffff64 = (GmIso4 *)((float)in_stack_ffffff58 * 1.0 + 0.0);
    in_stack_ffffff68 = (GmIso3 *)((float)in_stack_ffffff58 * 1.0 + 0.0);
    in_stack_ffffff6c = (GmIso3 *)((float)in_stack_ffffff58 * 1.0 + 0.0);
    CPlugShaderGeneric::SetEmissive
              (*(CPlugShaderGeneric **)(this + 0x2d4),(CPlugShaderGeneric *)0x1,
               (int)&stack0xffffff64,(GmVec3 *)0x0,(int)unaff_EBP);
  }
  pGVar23 = (GmIso3 *)0x7c1b9c;
  iVar13 = CSceneVehicle::SVisualHandler::IsInit(this + 0x104,(SVisualHandler *)unaff_EBP);
  pGVar3 = (GmIso4 *)0x3f800000;
  pGVar20 = (GmIso4 *)0x0;
  if (iVar13 != 0) {
    pGVar25 = *(GmIso4 **)(this + 0x460);
    if (*(int *)(this + 0x45c) != 0) {
      if (_DAT_00b36144 <= (float)pGVar25) {
        if ((_DAT_00b36134 <= (float)pGVar25) && (pGVar3 = pGVar20, (float)pGVar25 < 1.0)) {
          __CIsin();
          pGVar25 = (GmIso4 *)(float)extraout_ST0_00;
          pGVar3 = (GmIso4 *)(1.0 - (float)pGVar25);
        }
      }
      else {
        __CIsin();
        pGVar25 = (GmIso4 *)(float)extraout_ST0;
        pGVar3 = pGVar25;
      }
      pvVar11 = *(void **)(DAT_00d731e0 + 0x14);
      in_stack_ffffff60 = (SVisualHandler *)((float)pGVar3 * (float)_DAT_00b9f200);
      if (pvVar11 == (void *)0x0) {
        pvVar11 = (void *)(DAT_00d731e0 + 0xa0);
      }
      unaff_EBP = (SCasterCat *)0x7c1c78;
      fVar19 = CMwTimerAdapter::GetRelativeSpeed(pvVar11,in_stack_ffffff40);
      pSVar33 = (SCasterCat *)ABS(fVar19);
      pGVar20 = in_stack_ffffff64;
      if (_DAT_00b9ef4c <= (float)pSVar33) {
        unaff_EBP = (SCasterCat *)((float)in_stack_ffffff64 - (float)_DAT_00b9f1f8);
        pGVar23 = (GmIso3 *)0x7c1cc0;
        pSVar33 = unaff_EBP;
        pGVar20 = (GmIso4 *)
                  GmFunc::RandReal((float)unaff_EBP,(float)in_stack_ffffff64 + (float)_DAT_00b9f1f8)
        ;
      }
    }
    GmIso4::SetIdentity(local_1c,(GmMat43 *)in_stack_ffffff44);
    GmMat3::RotateX(auStack_18,(GmIso4 *)-(float)in_stack_ffffff68,fVar4);
    in_stack_ffffff44 = (GmIso3 *)aSStack_14;
    GmIso4::SetMult(this + 0x13c,(SPlugFaceCull *)in_stack_ffffff44,(SPlugFaceCull *)(this + 0x10c),
                    in_stack_ffffff4c);
    CSceneVehicle::SVisualHandler::UpdateVisual(this + 0x104,(SVisualHandler *)pGVar25);
    in_stack_ffffff64 = pGVar20;
  }
  pSStack_74 = (SCasterCat *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this + 0xe0,(CFastBuffer<class_CCrystalFace*> *)pSVar33);
  pSVar33 = (SCasterCat *)0x0;
  if (pSStack_74 != (SCasterCat *)0x0) {
    do {
      pSVar26 = (SVisualHandler *)0x7c1d43;
      pSVar5 = CFastBuffer<struct_CSceneVehicle::SVisualWheel>::operator[]
                         (this + 0xe0,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pSVar33,
                          (ulong)in_stack_ffffff58);
      in_stack_ffffff58 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar5;
      pSVar27 = (SVisualHandler *)0x7c1d53;
      pSVar6 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,in_stack_ffffff58,(ulong)in_stack_ffffff5c);
      pSVar33 = pSVar5 + 8;
      in_stack_ffffff5c = (SCasterCat *)0x7c1d61;
      iVar13 = CSceneVehicle::SVisualHandler::IsInit(pSVar33,in_stack_ffffff60);
      if (iVar13 != 0) {
        pSVar17 = pSVar5 + 0x40;
        GmIso4::SetIdentity(pSVar17,pGVar22);
        in_stack_ffffff64 = *(GmIso4 **)(pSVar6 + 0x29c);
        in_stack_ffffff60 = (SVisualHandler *)0x7c1d80;
        GmMat3::RotateX(pSVar17,in_stack_ffffff64,(float)in_stack_ffffff68);
        if (*(int *)(pSVar5 + 4) != 0) {
          in_stack_ffffff68 = (GmIso3 *)(pSVar6 + 0x2c8);
          in_stack_ffffff64 = (GmIso4 *)0x7c1d94;
          GmMat3::Mult(pSVar17,in_stack_ffffff68,in_stack_ffffff6c);
        }
        if (*(int *)(pSVar5 + 0x70) == 0) {
          GmIso4::Mult(pSVar17,(GmIso3 *)(pSVar5 + 0x10),(GmIso3 *)pGVar22);
          *(float *)(pSVar5 + 0x68) =
               (*(float *)(pSVar6 + 0x68) - *(float *)(pSVar6 + 0x38)) + *(float *)(pSVar5 + 0x68);
        }
      }
      pSVar17 = pSVar5 + 0x74;
      iVar13 = CSceneVehicle::SVisualHandler::IsInit(pSVar17,(SVisualHandler *)pGVar22);
      if (iVar13 != 0) {
        pGVar22 = (GmMat43 *)0x7c1dce;
        GmIso4::SetIdentity(pSVar5 + 0xac,(GmMat43 *)unaff_EBP);
        if (*(int *)(pSVar5 + 0xdc) == 0) {
          pGVar22 = (GmMat43 *)0x7c1de2;
          GmIso4::Mult(pSVar5 + 0xac,(GmIso3 *)(pSVar5 + 0x7c),pGVar23);
          *(float *)(pSVar5 + 0xd4) =
               (*(float *)(pSVar6 + 0x68) - *(float *)(pSVar6 + 0x38)) + *(float *)(pSVar5 + 0xd4);
        }
      }
      this_02 = pSVar5 + 0x14c;
      pGVar23 = (GmIso3 *)0x7c1e05;
      pSVar24 = this_02;
      iVar13 = CSceneVehicle::SVisualHandler::IsInit(this_02,(SVisualHandler *)unaff_EBP);
      if (iVar13 != 0) {
        this_00 = pSVar5 + 0x184;
        unaff_EBP = (SCasterCat *)0x7c1e16;
        GmIso4::SetIdentity(this_00,(GmMat43 *)pSVar24);
        this_02 = in_stack_ffffff5c;
        if (*(int *)(pSVar5 + 4) != 0) {
          unaff_EBP = (SCasterCat *)0x7c1e2a;
          GmMat3::Mult(this_00,(GmIso3 *)(pSVar6 + 0x2c8),in_stack_ffffff44);
          this_02 = in_stack_ffffff5c;
        }
        in_stack_ffffff44 = (GmIso3 *)(pSVar5 + 0x154);
        GmIso4::Mult(this_00,in_stack_ffffff44,(GmIso3 *)pSVar17);
        *(float *)(pSVar5 + 0x1ac) =
             (*(float *)(pSVar6 + 0x68) - *(float *)(pSVar6 + 0x38)) + *(float *)(pSVar5 + 0x1ac);
        in_stack_ffffff5c = this_02;
      }
      CSceneVehicle::SVisualHandler::UpdateVisual(in_stack_ffffff68,(SVisualHandler *)pSVar24);
      CSceneVehicle::SVisualHandler::UpdateVisual(in_stack_ffffff68,pSVar26);
      CSceneVehicle::SVisualHandler::UpdateVisual(this_02,pSVar27);
      pSVar33 = pSVar33 + 1;
    } while (pSVar33 < pSStack_74);
  }
  uVar28 = 0x7c1e83;
  CSceneVehicle::VisualUpdateAsync((CSceneVehicle *)this,(CSceneVehicle *)in_stack_ffffff58);
  pGVar29 = (GmMat3 *)0x7c1e8e;
  pGVar7 = (GmScaleTrans2 *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this + 0xd4,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff5c);
  if (pGVar7 != (GmScaleTrans2 *)0x0) {
    pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pGVar29 = (GmMat3 *)0x7c1ebc;
      pSVar33 = CFastBuffer<struct_CSceneVehicle::SVisualArm>::operator[]
                          (this + 0xd4,pCVar15,(ulong)in_stack_ffffff60);
      if (*(int *)pSVar33 != 0) {
        iVar13 = *(int *)(pSVar33 + 0x7c);
        iVar2 = *(int *)(pSVar33 + 0xe8);
        fStack_44 = *(float *)(iVar13 + 100) * *(float *)(pSVar33 + 0x15c) +
                    *(float *)(pSVar33 + 0x154) * *(float *)(iVar13 + 0x5c) +
                    *(float *)(iVar13 + 0x60) * *(float *)(pSVar33 + 0x158) +
                    *(float *)(iVar13 + 0x80);
        fStack_40 = *(float *)(iVar13 + 0x70) * *(float *)(pSVar33 + 0x15c) +
                    *(float *)(iVar13 + 0x6c) * *(float *)(pSVar33 + 0x158) +
                    *(float *)(iVar13 + 0x68) * *(float *)(pSVar33 + 0x154) +
                    *(float *)(iVar13 + 0x84);
        local_3c[0] = *(float *)(iVar13 + 0x7c) * *(float *)(pSVar33 + 0x15c) +
                      *(float *)(iVar13 + 0x78) * *(float *)(pSVar33 + 0x158) +
                      *(float *)(iVar13 + 0x74) * *(float *)(pSVar33 + 0x154) +
                      *(float *)(iVar13 + 0x88);
        local_54 = *(float *)(iVar2 + 100) * *(float *)(pSVar33 + 0x168) +
                   *(float *)(iVar2 + 0x5c) * *(float *)(pSVar33 + 0x160) +
                   *(float *)(iVar2 + 0x60) * *(float *)(pSVar33 + 0x164) + *(float *)(iVar2 + 0x80)
        ;
        fStack_50 = *(float *)(iVar2 + 0x70) * *(float *)(pSVar33 + 0x168) +
                    *(float *)(iVar2 + 0x68) * *(float *)(pSVar33 + 0x160) +
                    *(float *)(iVar2 + 0x6c) * *(float *)(pSVar33 + 0x164) +
                    *(float *)(iVar2 + 0x84);
        fStack_4c = *(float *)(iVar2 + 0x7c) * *(float *)(pSVar33 + 0x168) +
                    *(float *)(iVar2 + 0x74) * *(float *)(pSVar33 + 0x160) +
                    *(float *)(iVar2 + 0x78) * *(float *)(pSVar33 + 0x164) +
                    *(float *)(iVar2 + 0x88);
        pSStack_74 = (SCasterCat *)(local_54 - fStack_44);
        fStack_70 = fStack_50 - fStack_40;
        pCStack_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fStack_4c - local_3c[0]);
        in_stack_ffffff74 =
             (GmMat43 *)
             ((float)pCStack_6c * (float)pCStack_6c +
             (float)pSStack_74 * (float)pSStack_74 + fStack_70 * fStack_70);
        in_stack_ffffff60 = (SVisualHandler *)0x7c2005;
        fVar18 = (float10)func_0x009c1b40();
        in_stack_ffffff70 = (GmMat43 *)(float)fVar18;
        if (_DAT_00b9ef4c <= (float)in_stack_ffffff70) {
          pGVar32 = (GmMat43 *)(1.0 / (float)in_stack_ffffff70);
          pGVar29 = (GmMat3 *)&local_78;
          local_78 = (CSceneVehicleCar *)((float)pGVar32 * (float)local_78);
          pSStack_74 = (SCasterCat *)((float)pSStack_74 * (float)pGVar32);
          fStack_70 = (float)pGVar32 * fStack_70;
          local_c = local_48;
          local_8 = fStack_44;
          local_4 = fStack_40;
          local_3c[0] = 0.0;
          local_3c[1] = 1.0;
          local_3c[2] = 0.0;
          uVar28 = 0x7c209a;
          pGVar22 = in_stack_ffffff70;
          GmMat3::SetDOVandUpV(local_30,pGVar29,(GmVec3 *)local_3c,(GmVec3 *)in_stack_ffffff60);
          in_stack_ffffff70 = pGVar32;
          if (*(int *)(pSVar33 + 4) != 0) {
            pGVar29 = (GmMat3 *)0x7c20b0;
            GmMat3::GetLine(local_2c,(GmMat3 *)0x2,(ulong)&local_64,(GmVec3 *)in_stack_ffffff64);
            pGVar22 = (GmMat43 *)((float)in_stack_ffffff80 / *(float *)(pSVar33 + 0x16c));
            in_stack_ffffff64 = (GmIso4 *)&fStack_60;
            in_stack_ffffff60 = (SVisualHandler *)0x2;
            fStack_60 = (float)pGVar22 * fStack_60;
            fStack_5c = fStack_5c * (float)pGVar22;
            fStack_58 = (float)pGVar22 * fStack_58;
            GmMat3::SetLine(local_28,(GmMat3 *)0x2,(ulong)in_stack_ffffff64,
                            (GmVec3 *)in_stack_ffffff68);
            in_stack_ffffff70 = pGVar32;
          }
          if (*(int *)(pSVar33 + 8) != 0) {
            pCVar15 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar33 + 0xc);
            pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     CFastBuffer<class_CCrystalFace*>::GetCount
                               (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff6c);
            if (pCVar15 < pCVar8) {
              pSVar5 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                                 (this + 0x2e8,pCVar15,(ulong)in_stack_ffffff70);
              GmIso4::SetIdentity(&stack0x00000014,in_stack_ffffff74);
              in_stack_ffffff70 = (GmMat43 *)0x7c2134;
              GmMat3::RotateZ(&stack0x00000018,*(GmIso4 **)(pSVar5 + 0x29c),(float)pGVar22);
              in_stack_ffffff74 = (GmMat43 *)0x7c2147;
              GmMat3::Mult(&stack0x0000001c,(GmIso3 *)(pSVar5 + 0x2c8),(GmIso3 *)pGVar7);
              pGVar7 = (GmScaleTrans2 *)&stack0x00000020;
              GmIso4::LeftMult(local_10,pGVar7,(GmScaleTrans2 *)in_stack_ffffff80);
              in_stack_ffffff6c = (GmIso3 *)pCVar15;
            }
          }
          puVar16 = local_24;
          pSVar5 = pSVar33 + 0x48;
          for (iVar13 = 0xc; iVar13 != 0; iVar13 = iVar13 + -1) {
            *(undefined4 *)pSVar5 = *puVar16;
            puVar16 = puVar16 + 1;
            pSVar5 = pSVar5 + 4;
          }
          in_stack_ffffff68 = (GmIso3 *)0x7c216e;
          CSceneVehicle::SVisualHandler::UpdateVisual
                    (pSVar33 + 0x10,(SVisualHandler *)in_stack_ffffff6c);
          pCVar15 = pCStack_6c;
        }
      }
      pCVar15 = pCVar15 + 1;
    } while (pCVar15 < pGVar7);
  }
  if (*(int *)(this + 0x7c) != 0) goto LAB_007c27e7;
  iVar13 = CSceneMobil::IsZombie((CSceneMobil *)this,(CSceneMobil *)in_stack_ffffff60);
  local_78 = this + 0x448;
  if (iVar13 == 0) {
    local_78 = this + 0x2f8;
  }
  this_01 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_01 == (CPlugAudio *)0x0) {
    this_01 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar30 = (CPlugFileVideo *)0x7c21c7;
  pCVar9 = CPlugAudio::MwGetId(this_01,(CPlugAudio *)in_stack_ffffff64);
  if ((*(int *)(*(int *)(this + 0x28) + 0x4c) == -1) ||
     (iVar13 = 1, *(uint *)pCVar9 <= *(int *)(*(int *)(this + 0x28) + 0x4c) + 500U)) {
    iVar13 = 0;
  }
  uVar10 = (uint)(byte)this[0x201];
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_64 = 0;
  fStack_44 = 0.0;
  local_78 = (CSceneVehicleCar *)0x0;
  local_54 = 0.0;
  EVar31 = 0x7c221d;
  pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
            CFastBuffer<class_CCrystalFace*>::GetCount
                      (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff68);
  if (pCVar15 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar5 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                         (this + 0x2e8,pCVar8,uVar28);
      pSVar33 = pSVar5 + 0x16c;
      if (in_stack_ffffff6c == (GmIso3 *)0x0) {
        pSVar33 = pSVar5 + 0x298;
      }
      if (*(int *)(pSVar33 + 0x10) != 0) {
        if (*(int *)(pSVar5 + 4) == 0) {
          local_54 = (float)((int)local_54 + 1);
          in_stack_ffffff70 = (GmMat43 *)(uint)*(ushort *)(pSVar33 + 0xc);
        }
        else {
          local_64 = local_64 + 1;
          in_stack_ffffff74 = (GmMat43 *)(uint)*(ushort *)(pSVar33 + 0xc);
        }
        if ((*(int *)(pSVar33 + 0x14) != 0) || (*(int *)(this + 0x6a0) != 0)) {
          if (*(int *)(pSVar5 + 4) == 0) {
            pSStack_74 = pSStack_74 + 1;
          }
          else {
            iVar13 = iVar13 + 1;
          }
        }
      }
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar15);
  }
  fVar4 = (float)_DAT_00b3d2a8;
  if ((*(int *)(this + 0x270) != 0) && (iVar2 = *(int *)(*(int *)(this + 0x270) + 0x30), iVar2 != 0)
     ) {
    if (local_64 == 0) {
      *(undefined4 *)(iVar2 + 0x78) = 0;
      *(undefined4 *)(*(int *)(*(int *)(this + 0x270) + 0x30) + 0x90) = 0;
    }
    else {
      *(float *)(iVar2 + 0x78) = ABS(*(float *)pGVar7 * fVar4);
      fVar19 = (float)iVar13;
      if (iVar13 < 0) {
        fVar19 = fVar19 + _DAT_00c418d0;
      }
      fVar21 = (float)(int)pCVar15;
      if ((int)pCVar15 < 0) {
        fVar21 = fVar21 + _DAT_00c418d0;
      }
      in_stack_ffffff6c = (GmIso3 *)(fVar19 / fVar21);
      *(GmIso3 **)(*(int *)(*(int *)(this + 0x270) + 0x30) + 0x90) = in_stack_ffffff6c;
    }
    *(GmMat43 **)(*(int *)(*(int *)(this + 0x270) + 0x30) + 0x88) = in_stack_ffffff74;
  }
  if ((*(int *)(this + 0x264) != 0) && (iVar2 = *(int *)(*(int *)(this + 0x264) + 0x30), iVar2 != 0)
     ) {
    if (local_54 == 0.0) {
      if (in_stack_ffffff70 == (GmMat43 *)&DAT_0000000d) {
        *(undefined4 *)(iVar2 + 0x78) = *(undefined4 *)(this + 500);
        *(undefined4 *)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x90) = 0;
      }
      else {
        *(undefined4 *)(iVar2 + 0x78) = 0;
        *(undefined4 *)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x90) = 0;
      }
    }
    else {
      *(float *)(iVar2 + 0x78) = ABS(fVar4 * *(float *)pGVar7);
      fVar4 = (float)(int)(pSStack_74 + iVar13);
      if ((int)(pSStack_74 + iVar13) < 0) {
        fVar4 = fVar4 + _DAT_00c418d0;
      }
      fVar19 = (float)(int)pCVar15;
      if ((int)pCVar15 < 0) {
        fVar19 = fVar19 + _DAT_00c418d0;
      }
      in_stack_ffffff6c = (GmIso3 *)(fVar4 / fVar19);
      *(GmIso3 **)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x90) = in_stack_ffffff6c;
    }
    *(GmMat43 **)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x88) = in_stack_ffffff70;
  }
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)&fStack_60,(GmVec3 *)pGVar29);
  if ((*(int *)(this + 0x268) != 0) &&
     (iVar13 = *(int *)(*(int *)(this + 0x268) + 0x30), iVar13 != 0)) {
    if ((*(int *)(this + 0x5c4) == 0) || (fVar4 = _DAT_00b2c060, *(int *)(this + 0x5c8) != 0)) {
      fVar4 = 1.0;
    }
    if ((*(int *)(this + 0x60c) == 0) && (in_stack_ffffff6c == (GmIso3 *)0x0)) {
      in_stack_ffffff6c = (GmIso3 *)(*(float *)(uVar10 + 0x80) * fVar4);
    }
    else {
      in_stack_ffffff6c = (GmIso3 *)0x0;
    }
    if (*(int *)(this + 0x78) == 0) {
      *(GmIso3 **)(iVar13 + 0x78) = in_stack_ffffff6c;
    }
    else {
      pvVar11 = *(void **)(DAT_00d731e0 + 0x14);
      if (pvVar11 == (void *)0x0) {
        pvVar11 = (void *)(DAT_00d731e0 + 0xa0);
      }
      fVar21 = CMwTimerAdapter::GetAsyncPeriod(pvVar11,(CMwTimerAdapter *)pCVar30);
      fVar4 = (float)in_stack_ffffff70 - *(float *)(iVar13 + 0x78);
      fVar19 = ABS(fVar4);
      if (fVar21 * (float)_DAT_00b9f1f0 <= fVar19) {
        fVar19 = fVar21 * (float)_DAT_00b9f1f0;
      }
      if (NAN(fVar4) || 0.0 < fVar4 == (fVar4 == 0.0)) {
        fVar19 = -fVar19;
      }
      *(float *)(iVar13 + 0x78) = fVar19 + *(float *)(iVar13 + 0x78);
    }
    uVar1 = 0;
    if (*(int *)(this + 0x60c) == 0) {
      if (0.0 < fStack_50 == (fStack_50 == 0.0)) {
        uVar1 = *(undefined4 *)(this + 0x54);
      }
      else {
        uVar1 = *(undefined4 *)(this + 0x50);
      }
    }
    *(undefined4 *)(iVar13 + 0x7c) = uVar1;
    fVar4 = _DAT_00b2c060;
    if (*(int *)(this + 0x5e4) != 0) {
      fVar4 = 1.0;
    }
    *(float *)(iVar13 + 0x80) = fVar4;
  }
  if ((*(int *)(this + 0x288) != 0) &&
     (iVar13 = *(int *)(*(int *)(this + 0x288) + 0x30), iVar13 != 0)) {
    fVar18 = (float10)func_0x009c1b40();
    *(float *)(iVar13 + 0x78) = (float)fVar18 * (float)_DAT_00b3d2a8;
    uVar1 = 0;
    if (*(int *)(this + 0x60c) == 0) {
      if (NAN(fStack_50) || 0.0 < fStack_50 == (fStack_50 == 0.0)) {
        uVar1 = *(undefined4 *)(this + 0x54);
      }
      else {
        uVar1 = *(undefined4 *)(this + 0x50);
      }
    }
    *(undefined4 *)(*(int *)(*(int *)(this + 0x288) + 0x30) + 0x7c) = uVar1;
  }
  if (((((*(int *)(this + 0x60c) != 0) ||
        (*(CSceneSoundSource **)(this + 0x284) == (CSceneSoundSource *)0x0)) ||
       (*(int *)(this + 0x2e4) != 2)) ||
      ((*(int *)(this + 0x744) != 0 || (*(float *)(this + 0x50) <= (float)_DAT_00b41ea8)))) ||
     (*(int *)(this + 0x5e4) != 0)) {
    *(undefined4 *)(this + 0x83c) = 0;
  }
  else {
    if (*(int *)(this + 0x83c) == 0) {
      CSceneSoundSource::Play
                (*(CSceneSoundSource **)(this + 0x284),pCVar30,EVar31,(int)in_stack_ffffff68,
                 (ulong)in_stack_ffffff6c);
    }
    *(undefined4 *)(this + 0x83c) = 1;
  }
  if ((*(float *)(this + 0x54) <= (float)_DAT_00b41ea8) || (*(int *)(this + 0x5e4) != 0)) {
    *(undefined4 *)(this + 0x838) = 0;
  }
  else {
    if ((*(CSceneSoundSource **)(this + 0x280) != (CSceneSoundSource *)0x0) &&
       (*(int *)(this + 0x838) == 0)) {
      CSceneSoundSource::Play
                (*(CSceneSoundSource **)(this + 0x280),pCVar30,EVar31,(int)in_stack_ffffff68,
                 (ulong)in_stack_ffffff6c);
    }
    *(undefined4 *)(this + 0x838) = 1;
  }
  if (((*(int *)(this + 0x5c4) != 0) || (*(float *)(this + 0x54) <= (float)_DAT_00b41ea8)) ||
     (*(int *)(this + 0x5e4) != 0)) {
    if (*(int **)(this + 0x274) != (int *)0x0) {
      pcVar14 = *(code **)(**(int **)(this + 0x274) + 0xb4);
      goto LAB_007c26b6;
    }
  }
  else if (*(int **)(this + 0x274) != (int *)0x0) {
    pcVar14 = *(code **)(**(int **)(this + 0x274) + 0xb0);
LAB_007c26b6:
    (*pcVar14)();
  }
  if (((*(int *)(this + 0x27c) != 0) &&
      (iVar13 = *(int *)(this + 0x5c8), *(int *)(this + 0x834) != iVar13)) &&
     (*(int *)(this + 0x5e4) == 0)) {
    *(int *)(this + 0x834) = iVar13;
    *(undefined4 *)(*(int *)(*(int *)(this + 0x27c) + 0x30) + 0x84) =
         *(undefined4 *)(&DAT_00b9f1c8 + iVar13 * 4);
    CSceneSoundSource::Play
              (*(CSceneSoundSource **)(this + 0x27c),pCVar30,EVar31,(int)in_stack_ffffff68,
               (ulong)in_stack_ffffff6c);
  }
  if (*(int *)(this + 0x65c) != *(int *)(this + 0x650)) {
    *(int *)(this + 0x65c) = *(int *)(this + 0x650);
    if (((*(int *)(this + 0x264) != 0) &&
        (iVar13 = *(int *)(*(int *)(this + 0x264) + 0x30), iVar13 != 0)) &&
       ((*(int *)(this + 0x5e4) == 0 || (this[0x201] == (CSceneVehicleCar)0xd)))) {
      uVar10 = *(uint *)(this + 0x658);
      if (*(uint *)(this + 0x658) <= *(uint *)(iVar13 + 0x8c)) {
        uVar10 = *(uint *)(iVar13 + 0x8c);
      }
      *(uint *)(iVar13 + 0x8c) = uVar10;
    }
    if (((*(int *)(this + 0x270) != 0) &&
        (iVar13 = *(int *)(*(int *)(this + 0x270) + 0x30), iVar13 != 0)) &&
       ((*(int *)(this + 0x5e4) == 0 || (this[0x201] == (CSceneVehicleCar)0xd)))) {
      uVar10 = *(uint *)(this + 0x654);
      if (*(uint *)(this + 0x654) <= *(uint *)(iVar13 + 0x8c)) {
        uVar10 = *(uint *)(iVar13 + 0x8c);
      }
      *(uint *)(iVar13 + 0x8c) = uVar10;
    }
    if (((*(int *)(this + 0x278) != 0) &&
        (iVar13 = *(int *)(*(int *)(this + 0x278) + 0x30), iVar13 != 0)) &&
       ((*(int *)(this + 0x5e4) == 0 || (this[0x200] == (CSceneVehicleCar)0xd)))) {
      *(uint *)(iVar13 + 0x88) = (uint)(byte)this[0x200];
      uVar10 = *(uint *)(*(int *)(*(int *)(this + 0x278) + 0x30) + 0x8c);
      uVar12 = *(uint *)(this + 0x1fc);
      if (*(uint *)(this + 0x1fc) <= uVar10) {
        uVar12 = uVar10;
      }
      *(uint *)(*(int *)(*(int *)(this + 0x278) + 0x30) + 0x8c) = uVar12;
    }
    *(undefined4 *)(this + 0x658) = 0;
    *(undefined4 *)(this + 0x654) = 0;
    *(undefined4 *)(this + 0x1fc) = 0;
  }
LAB_007c27e7:
  CSceneVehicle::VehicleUpdateAsync((CSceneVehicle *)this,in_stack_00000034);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::VirtualParam_Get
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CSceneVehicleCar::VirtualParam_Get
          (CSceneVehicleCar *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  CMwValueStd *unaff_EDI;
  float10 fVar5;
  float fVar6;
  undefined4 unaff_retaddr;
  undefined4 uStack_4;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0xa02b009) {
    if (uVar3 == 0xa02b008) {
      *(CSceneVehicleCar **)param_2 = this + 0x5a4;
      return 0;
    }
    switch(uVar3) {
    case 0xa02b001:
      *(CSceneVehicleCar **)param_2 = this + 0x5c8;
      return 0;
    case 0xa02b002:
      *(CSceneVehicleCar **)param_2 = this + 0x5c4;
      return 0;
    case 0xa02b003:
      if (*(float *)(this + 0x5c0) <= 0.0) {
        *(CMwStack **)param_2 = param_2 + 4;
        *(undefined4 *)(param_2 + 4) = 0;
        return 0;
      }
      *(CMwStack **)param_2 = param_2 + 4;
      *(undefined4 *)(param_2 + 4) = 1;
      return 0;
    case 0xa02b004:
      *(CSceneVehicleCar **)param_2 = this + 0x5b4;
      return 0;
    case 0xa02b005:
      *(CSceneVehicleCar **)param_2 = this + 0x59c;
      return 0;
    case 0xa02b006:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x5cc) * (float)_DAT_00b3d2a8;
      return 0;
    case 0xa02b007:
      *(CSceneVehicleCar **)param_2 = this + 0x5a0;
      return 0;
    }
  }
  else {
    if (0xa02b00c < uVar3) {
      if (uVar3 == 0xa02b012) {
        *(undefined4 **)param_2 = &DAT_00d06a74;
      }
      else if (uVar3 != 0xffffffff) goto switchD_007bfa9c_default;
      return 0;
    }
    if (uVar3 == 0xa02b00c) {
      fVar5 = (float10)(**(code **)(*(int *)this + 0x134))();
      param_1 = (CPlugBlendShapes *)(float)fVar5;
      if ((float)param_1 < _DAT_00b313ac) {
        param_1 = (CPlugBlendShapes *)0x0;
      }
      uStack_4 = (undefined4)((ulonglong)(double)(float)param_1 >> 0x20);
      *(CMwStack **)param_2 = param_2 + 4;
      fVar6 = GetMaxSpeed(this,(CSceneVehicleCar *)unaff_EDI);
      *(float *)(param_2 + 4) = (float)(double)CONCAT44(unaff_retaddr,uStack_4) / fVar6;
      return 0;
    }
    if (uVar3 == 0xa02b009) {
      *(CSceneVehicleCar **)param_2 = this + 0x5a8;
      return 0;
    }
    if (uVar3 == 0xa02b00a) {
      *(CSceneVehicleCar **)param_2 = this + 0x5ac;
      return 0;
    }
    if (uVar3 == 0xa02b00b) {
      fVar5 = (float10)(**(code **)(*(int *)this + 0x134))();
      param_1 = (CPlugBlendShapes *)(float)fVar5;
      if ((float)param_1 < _DAT_00b313ac) {
        param_1 = (CPlugBlendShapes *)0x0;
      }
      *(CPlugBlendShapes **)(param_2 + 4) = param_1;
      *(CMwStack **)param_2 = param_2 + 4;
      return 0;
    }
  }
switchD_007bfa9c_default:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = CSceneVehicle::VirtualParam_Get((CSceneVehicle *)this,param_1,param_2,unaff_EDI);
  return uVar4;
}
}

// =================================================
// Function: CSceneVehicleCar::VirtualParam_Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CSceneVehicleCar::VirtualParam_Set
          (CSceneVehicleCar *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (0xa02b009 < uVar3) {
    if (uVar3 == 0xa02b00a) {
      *(undefined4 *)(this + 0x5ac) = *(undefined4 *)param_2;
    }
    else {
      if (uVar3 == 0xa02b012) {
        DAT_00d06a74 = *(undefined4 *)param_2;
        return 0;
      }
      if (uVar3 != 0xffffffff) goto switchD_007bcdc1_default;
    }
    return 0;
  }
  if (uVar3 == 0xa02b009) {
    *(undefined4 *)(this + 0x5a8) = *(undefined4 *)param_2;
    return 0;
  }
  switch(uVar3) {
  case 0xa02b005:
    *(undefined4 *)(this + 0x59c) = *(undefined4 *)param_2;
    return 0;
  case 0xa02b006:
    *(float *)(this + 0x5cc) = *(float *)param_2 / (float)_DAT_00b3d2a8;
    return 0;
  case 0xa02b007:
    *(undefined4 *)(this + 0x5a0) = *(undefined4 *)param_2;
    return 0;
  case 0xa02b008:
    *(undefined4 *)(this + 0x5a4) = *(undefined4 *)param_2;
    return 0;
  }
switchD_007bcdc1_default:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = CSceneVehicle::VirtualParam_Set((CSceneVehicle *)this,param_1,param_2,param_3);
  return uVar4;
}
}

// =================================================
// Function: CSceneVehicleCar::WheelAbsorbContact
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::WheelAbsorbContact
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2,
          CHmsPhysicalContact *param_3)
{
{
  GmVec3 *pGVar1;
  float fVar2;
  SSimulationWheel *pSVar3;
  CSceneVehicleCar *pCVar4;
  SSimulationWheel *pSVar5;
  int iVar6;
  SCasterCat *pSVar7;
  GmMat3 *pGVar8;
  GmVec3 *unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  float10 extraout_ST0;
  CSceneVehicleCar *in_stack_00000010;
  GmMat3 *pGStack00000014;
  GmMat3 *pGVar9;
  CSceneVehicleCar *pCStack_30;
  CSceneVehicleCar *pCStack_2c;
  float fStack_18;
  float fStack_14;
  CSceneVehicleCar *pCStack_10;
  CSceneVehicleCar *pCStack_c;
  CSceneVehicleCar *pCStack_8;
  float fStack_4;
  
  pSVar5 = param_2;
  pGVar1 = (GmVec3 *)(param_2 + 0xc);
  pSVar3 = (SSimulationWheel *)ABS(*(float *)(param_2 + 0xc));
  param_2 = pSVar3;
  __CIsin();
  param_2 = (SSimulationWheel *)(float)extraout_ST0;
  *(uint *)(param_1 + 0x124) = (uint)((float)pSVar3 < (float)param_2);
  if ((float)pSVar3 < (float)param_2 == 0) {
    *(undefined4 *)(this + 0x5dc) = 1;
    *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(pSVar5 + 0x18);
    *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(pSVar5 + 0x1c);
    *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(pSVar5 + 0x20);
    *(undefined4 *)(param_1 + 0x15c) = 1;
  }
  if (*(int *)(param_1 + 0x124) != 0) {
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 1;
    *(float *)(param_1 + 0x144) = *(float *)(param_1 + 0x144) + *(float *)pGVar1;
    *(float *)(param_1 + 0x148) = *(float *)(pSVar5 + 0x10) + *(float *)(param_1 + 0x148);
    *(float *)(param_1 + 0x14c) = *(float *)(pSVar5 + 0x14) + *(float *)(param_1 + 0x14c);
    *(undefined2 *)(param_1 + 0x128) = *(undefined2 *)(pSVar5 + 0x48);
  }
  *(undefined4 *)(pSVar5 + 0x3c) = 0;
  if (*(int **)(pSVar5 + 0x40) != (int *)0x0) {
    iVar6 = (**(code **)(**(int **)(pSVar5 + 0x40) + 0x78))();
    fStack_18 = *(float *)(iVar6 + 8);
    fStack_14 = *(float *)(iVar6 + 0x14);
    pCStack_10 = *(CSceneVehicleCar **)(iVar6 + 0x20);
    *(float *)(param_1 + 0x130) = fStack_18;
    *(float *)(param_1 + 0x134) = fStack_14;
    *(CSceneVehicleCar **)(param_1 + 0x138) = pCStack_10;
    *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(pSVar5 + 0x40);
    pGVar9 = (GmMat3 *)0x0;
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 0x28) + 0x34),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
    unaff_EDI = 0x7c1303;
    pGVar8 = (GmMat3 *)(**(code **)(**(int **)pSVar7 + 0x78))();
    GmVec3::MultTranspose(param_1 + 0x130,pGVar8,pGVar9);
  }
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(pSVar5 + 0x18);
  *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(pSVar5 + 0x1c);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(pSVar5 + 0x20);
  pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 100) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                       (*(int *)(this + 100) + 0x24),unaff_EDI);
  param_2 = (SSimulationWheel *)(*(int *)(*(int *)pSVar7 + 0x350) + -2);
  if (param_2 == (SSimulationWheel *)0x0) {
    param_3 = (CHmsPhysicalContact *)
              (*(float *)(pSVar5 + 0x38) * 0.0 +
              *(float *)(pSVar5 + 0x34) + *(float *)(pSVar5 + 0x30) * 0.0);
    if ((float)param_3 <= 0.0) {
      param_2 = (SSimulationWheel *)0x1;
    }
    else {
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(pSVar3 + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(pSVar3 + 100) + 0x24),unaff_ESI);
      pCStack_c = in_stack_00000010;
      if ((_DAT_00b574fc <= *(float *)(*(int *)pSVar7 + 0x11c)) &&
         (pCVar4 = (CSceneVehicleCar *)
                   (*(float *)(param_1 + 0xb4) - *(float *)(*(int *)pSVar7 + 0x11c)),
         (float)pCVar4 <= (float)in_stack_00000010)) {
        param_3 = (CHmsPhysicalContact *)0x1;
        pCStack_c = pCVar4;
      }
      pCStack_2c = *(CSceneVehicleCar **)(param_1 + 0xbc);
      in_stack_00000010 = pCStack_c;
      if ((float)pCStack_c < (float)pCStack_2c != ((float)pCStack_c == (float)pCStack_2c)) {
        in_stack_00000010 = pCStack_2c;
      }
      *(CSceneVehicleCar **)(param_1 + 0xbc) = in_stack_00000010;
      in_stack_00000010 = (CSceneVehicleCar *)((float)_PTR_00b2c178 * (float)pCStack_c);
      *(float *)(pSVar5 + 0x30) = *(float *)(pSVar5 + 0x30) - (float)in_stack_00000010;
      *(float *)(pSVar5 + 0x34) = *(float *)(pSVar5 + 0x34) - (float)pCStack_c;
      *(float *)(pSVar5 + 0x38) = *(float *)(pSVar5 + 0x38) - (float)in_stack_00000010;
      pCStack_10 = in_stack_00000010;
      pCStack_8 = in_stack_00000010;
    }
    if (*(int *)(param_1 + 0x124) == 0) {
      if (*(short *)(pSVar5 + 0x48) == 4) {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(pCStack_30 + 100) + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                             (*(int *)(pCStack_30 + 100) + 0x24),unaff_EBP);
        fVar2 = *(float *)(*(int *)pSVar7 + 0x178);
        pCStack_30 = pCStack_2c;
      }
      else {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(pCStack_30 + 100) + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                             (*(int *)(pCStack_30 + 100) + 0x24),unaff_EBP);
        fVar2 = *(float *)(*(int *)pSVar7 + 0x17c);
      }
      pGStack00000014 = (GmMat3 *)-fVar2;
      in_stack_00000010 =
           (CSceneVehicleCar *)
           (*(float *)(pSVar5 + 0x14) * *(float *)(pSVar5 + 0x2c) +
           *(float *)pGVar1 * *(float *)(pSVar5 + 0x24) +
           *(float *)(pSVar5 + 0x10) * *(float *)(pSVar5 + 0x28));
      if ((float)in_stack_00000010 < _DAT_00c418e0) {
        pCStack_c = *(CSceneVehicleCar **)(pSVar5 + 0x18);
        iVar6 = *(int *)(*(int *)(pCStack_30 + 0x28) + 0x14);
        fStack_4 = *(float *)(pSVar5 + 0x20);
        pCStack_8 = *(CSceneVehicleCar **)(iVar6 + 0x54);
        param_2 = (SSimulationWheel *)(fStack_4 - *(float *)(iVar6 + 0x58));
        SDynaMath::ComputeImpulse
                  ((void *)(iVar6 + 0x1c),*(CSceneVehicleSpeedBoat **)(iVar6 + 0x18),
                   (float)(iVar6 + 0x1c),pGStack00000014,(float)(pSVar5 + 0x24),
                   (GmVec3 *)&stack0xffffffdc,(GmVec3 *)&stack0x00000000,(GmVec3 *)&fStack_18,
                   unaff_EBX);
        AddVehicleImpulse(pCStack_30,(CSceneVehicleCar *)&param_2,(GmVec3 *)&stack0x00000014);
        return;
      }
    }
    else {
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(pCStack_30 + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(pCStack_30 + 100) + 0x24),unaff_EBP);
      if (*(short *)(pSVar5 + 0x48) == 4) {
        fVar2 = *(float *)(*(int *)pSVar7 + 0x18c);
      }
      else {
        fVar2 = *(float *)(*(int *)pSVar7 + 0x184);
      }
      pCStack_8 = *(CSceneVehicleCar **)(pSVar5 + 0x28);
      pGStack00000014 = (GmMat3 *)-fVar2;
      pCStack_c = *(CSceneVehicleCar **)(pSVar5 + 0x24);
      fStack_4 = *(float *)(pSVar5 + 0x2c);
      fVar2 = *(float *)(pSVar5 + 0x14) * fStack_4 +
              *(float *)pGVar1 * (float)pCStack_c + *(float *)(pSVar5 + 0x10) * (float)pCStack_8;
      if (fVar2 < 0.0) {
        fStack_18 = *(float *)pGVar1 * fVar2;
        fStack_14 = *(float *)(pSVar5 + 0x10) * fVar2;
        pCStack_10 = (CSceneVehicleCar *)(fVar2 * *(float *)(pSVar5 + 0x14));
        fVar2 = (float)pCStack_10 * 0.0 + fStack_14 + fStack_18 * 0.0;
        if ((in_stack_00000010 != (CSceneVehicleCar *)0x0) || (0.0 <= fVar2)) {
          iVar6 = *(int *)(*(int *)(pCStack_2c + 0x28) + 0x14);
          param_2 = (SSimulationWheel *)(*(float *)(pSVar5 + 0x20) - *(float *)(iVar6 + 0x58));
          SDynaMath::ComputeImpulse
                    (&pCStack_c,*(CSceneVehicleSpeedBoat **)(iVar6 + 0x18),(float)(iVar6 + 0x1c),
                     pGStack00000014,(float)&pCStack_c,pGVar1,(GmVec3 *)&stack0x00000000,
                     (GmVec3 *)&fStack_18,unaff_EBX);
          AddVehicleImpulse(pCStack_2c,(CSceneVehicleCar *)&param_2,(GmVec3 *)(pSVar5 + 0x18));
          return;
        }
        in_stack_00000010 =
             (CSceneVehicleCar *)
             (*(float *)(pSVar5 + 0x14) * (*(float *)(pSVar5 + 0x2c) - fVar2 * 0.0) +
             *(float *)pGVar1 * (*(float *)(pSVar5 + 0x24) - fVar2 * 0.0) +
             *(float *)(pSVar5 + 0x10) * (*(float *)(pSVar5 + 0x28) - fVar2));
        if ((float)in_stack_00000010 < 0.0) {
          pCStack_c = *(CSceneVehicleCar **)(param_1 + 100);
          pCStack_8 = *(CSceneVehicleCar **)(param_1 + 0x68);
          iVar6 = *(int *)(*(int *)(pCStack_2c + 0x28) + 0x14);
          fStack_4 = *(float *)(param_1 + 0x6c);
          param_2 = (SSimulationWheel *)(fStack_4 - *(float *)(iVar6 + 0x58));
          SDynaMath::ComputeImpulse
                    (&stack0xffffffdc,*(CSceneVehicleSpeedBoat **)(iVar6 + 0x18),
                     (float)(iVar6 + 0x1c),pGStack00000014,(float)&stack0xffffffdc,pGVar1,
                     (GmVec3 *)&stack0x00000000,(GmVec3 *)&fStack_18,unaff_EBX);
          AddVehicleImpulse(pCStack_2c,(CSceneVehicleCar *)&param_2,(GmVec3 *)&stack0x00000014);
          return;
        }
      }
    }
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::WheelAddForceToVehicle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::WheelAddForceToVehicle
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2,
          GmVec3 *param_3)
{
{
  int iVar1;
  int iVar2;
  SSimulationWheel *pSVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  SCasterCat *pSStack00000010;
  SSimulationWheel *in_stack_00000014;
  GmVec3 *in_stack_ffffffdc;
  float local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  iVar1 = *(int *)(this + 100);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_EDI);
  pSVar3 = param_2;
  iVar2 = *(int *)(*(int *)pSVar4 + 0x350);
  if (iVar2 == 0) {
    if (*(int *)(param_2 + 0x124) != 0) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          unaff_ESI);
      pSStack00000010 =
           CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_EBP);
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          unaff_EBX);
      local_10 = *(float *)(*(int *)in_stack_00000014 + 0x114) * *(float *)(*(int *)pSVar4 + 0x128)
                 * (*(float *)(*(int *)pSVar5 + 0x124) - *(float *)(pSVar3 + 0xb4));
      in_stack_00000014 = (SSimulationWheel *)((float)_PTR_00b2c178 * local_10);
      local_14 = (float)in_stack_00000014;
      local_c = (float)in_stack_00000014;
      AddVehicleForce(this,(CSceneVehicleCar *)&local_14,(GmVec3 *)(pSVar3 + 0xa8),in_stack_ffffffdc
                     );
    }
  }
  else if (iVar2 == 1) {
    if (*(int *)(param_2 + 0x124) != 0) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          unaff_ESI);
      pSStack00000010 =
           CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar1 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_EBP);
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),
                          unaff_EBX);
      param_2 = (SSimulationWheel *)
                ((*(float *)(*(int *)pSVar4 + 0x124) - *(float *)(pSVar3 + 0xb4)) *
                 *(float *)(*(int *)in_stack_00000014 + 0x114) -
                *(float *)(*(int *)pSVar5 + 0x118) * *(float *)(pSVar3 + 0xb8));
      param_1 = (CSceneVehicleCar *)0x0;
      param_3 = (GmVec3 *)0x0;
      in_stack_00000014 = param_2;
      AddVehicleForce(this,(CSceneVehicleCar *)&param_1,(GmVec3 *)(pSVar3 + 0xa8),in_stack_ffffffdc)
      ;
      return;
    }
  }
  else if ((iVar2 == 2) && (*(int *)(param_2 + 0x124) != 0)) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_ESI
                       );
    pSStack00000010 =
         CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                   ((void *)(iVar1 + 0x14),
                    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_EBP);
    pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_EBX
                       );
    in_stack_00000014 =
         (SSimulationWheel *)
         ((*(float *)(*(int *)pSVar4 + 0x124) - *(float *)(pSVar3 + 0xb4)) *
          *(float *)(*(int *)in_stack_00000014 + 0x114) -
         *(float *)(*(int *)pSVar5 + 0x118) * *(float *)(pSVar3 + 0xb8));
    local_8 = 0;
    local_4 = (float)in_stack_00000014;
    AddVehicleForce(this,(CSceneVehicleCar *)&local_8,(GmVec3 *)(pSVar3 + 0xa8),in_stack_ffffffdc);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::WheelGetAsyncGroundContactPos
// =================================================
GmVec3 * __thiscall
CSceneVehicleCar::WheelGetAsyncGroundContactPos
          (CSceneVehicleCar *this,CSceneVehicle *param_1,ulong param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (this + 0x2e8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  return (GmVec3 *)(pSVar1 + 700);
}
}

// =================================================
// Function: CSceneVehicleCar::WheelGetContactMaterial
// =================================================
ushort __thiscall
CSceneVehicleCar::WheelGetContactMaterial
          (CSceneVehicleCar *this,CSceneVehicle *param_1,ulong param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (this + 0x2e8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  if (*(int *)(pSVar1 + 0x2a8) != 0) {
    return *(ushort *)(pSVar1 + 0x2a4);
  }
  return 0xffff;
}
}

// =================================================
// Function: CSceneVehicleCar::WheelGetCount
// =================================================
ulong __thiscall CSceneVehicleCar::WheelGetCount(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  ulong uVar1;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this + 0x2e8,(CFastBuffer<class_CCrystalFace*> *)param_1);
  return uVar1;
}
}

// =================================================
// Function: CSceneVehicleCar::WheelIntegrate
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::WheelIntegrate
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2,float param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  SCasterCat *pSVar8;
  int iVar9;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  SSimulationWheel *pSVar10;
  ulong unaff_EDI;
  SSimulationWheel *pSVar11;
  float in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  SSurfaceHandler *in_stack_fffffff4;
  SSurfaceHandler *in_stack_fffffff8;
  
  iVar9 = *(int *)(this + 100);
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(iVar9 + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),unaff_EDI);
  iVar5 = *(int *)(*(int *)pSVar6 + 0x350);
  if (iVar5 == 0) {
    *(float *)(param_2 + 0xb4) = *(float *)(param_2 + 0xb4) - *(float *)(param_2 + 0xbc);
    *(undefined4 *)(param_2 + 0xbc) = 0;
    iVar9 = *(int *)(this + 100);
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar9 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),unaff_EBP
                       );
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar9 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),unaff_ESI
                       );
    pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar9 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),unaff_EBX
                       );
    fVar1 = *(float *)(*(int *)pSVar6 + 0x124);
    fVar2 = *(float *)(param_2 + 0xb4);
    fVar3 = *(float *)(*(int *)pSVar7 + 0x114);
    fVar4 = *(float *)(*(int *)pSVar8 + 0x118);
    pSVar10 = param_2 + 0x10;
    pSVar11 = param_2 + 0x40;
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined4 *)pSVar11 = *(undefined4 *)pSVar10;
      pSVar10 = pSVar10 + 4;
      pSVar11 = pSVar11 + 4;
    }
    fVar1 = *(float *)(param_2 + 0xb8) +
            in_stack_00000018 * ((fVar1 - fVar2) * fVar3 - fVar4 * *(float *)(param_2 + 0xb8));
    *(float *)(param_2 + 0xb8) = fVar1;
    fVar1 = fVar1 * in_stack_00000018 + *(float *)(param_2 + 0xb4);
    *(float *)(param_2 + 0xb4) = fVar1;
    fVar1 = -fVar1;
    param_3 = (float)_PTR_00b2c178 * fVar1;
    *(float *)(param_2 + 100) = *(float *)(param_2 + 100) + param_3;
    fVar1 = fVar1 + *(float *)(param_2 + 0x68);
  }
  else {
    if (iVar5 != 1) {
      if (iVar5 == 2) {
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar9 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                            unaff_ESI);
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar9 + 0x14),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),
                            unaff_EBX);
        fVar1 = *(float *)(*(int *)pSVar6 + 0x124);
        fVar2 = *(float *)(*(int *)pSVar7 + 0x194);
        pSVar10 = param_2 + 0x10;
        pSVar11 = param_2 + 0x40;
        for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined4 *)pSVar11 = *(undefined4 *)pSVar10;
          pSVar10 = pSVar10 + 4;
          pSVar11 = pSVar11 + 4;
        }
        fVar1 = fVar2 * in_stack_00000014 * (fVar1 - in_stack_00000010) + in_stack_00000010;
        *(float *)(param_2 + 0xb8) = (fVar1 - *(float *)(param_2 + 0xb4)) / in_stack_00000014;
        *(float *)(param_2 + 0xb4) = fVar1;
        *(undefined4 *)(param_2 + 0xbc) = 0;
        fVar2 = (float)_PTR_00b2c178 * -fVar1;
        *(float *)(param_2 + 100) = fVar2 + *(float *)(param_2 + 100);
        *(float *)(param_2 + 0x68) = *(float *)(param_2 + 0x68) + -fVar1;
        *(float *)(param_2 + 0x6c) = fVar2 + *(float *)(param_2 + 0x6c);
        CSceneVehicle::SSurfaceHandler::UpdateSurface(param_2 + 0xc,in_stack_fffffff4);
        return;
      }
      goto LAB_007bd6c6;
    }
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar9 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),unaff_ESI
                       );
    pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar9 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar9 + 0x24),unaff_EBX
                       );
    fVar1 = *(float *)(*(int *)pSVar6 + 0x124);
    fVar2 = *(float *)(*(int *)pSVar7 + 0x194);
    pSVar10 = param_2 + 0x10;
    pSVar11 = param_2 + 0x40;
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined4 *)pSVar11 = *(undefined4 *)pSVar10;
      pSVar10 = pSVar10 + 4;
      pSVar11 = pSVar11 + 4;
    }
    fVar1 = fVar2 * in_stack_00000014 * (fVar1 - in_stack_00000010) + in_stack_00000010;
    *(float *)(param_2 + 0xb8) = (fVar1 - *(float *)(param_2 + 0xb4)) / in_stack_00000014;
    *(float *)(param_2 + 0xb4) = fVar1;
    *(undefined4 *)(param_2 + 0xbc) = 0;
    *(float *)(param_2 + 100) = (float)_PTR_00b2c178 * -fVar1 + *(float *)(param_2 + 100);
    fVar1 = *(float *)(param_2 + 0x68) + -fVar1;
  }
  *(float *)(param_2 + 0x68) = fVar1;
  *(float *)(param_2 + 0x6c) = *(float *)(param_2 + 0x6c) + param_3;
LAB_007bd6c6:
  CSceneVehicle::SSurfaceHandler::UpdateSurface(param_2 + 0xc,in_stack_fffffff8);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::WheelIsSliding
// =================================================
int __thiscall
CSceneVehicleCar::WheelIsSliding(CSceneVehicleCar *this,CSceneVehicleCar *param_1,ulong param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::operator[]
                     (this + 0x2e8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  if ((*(int *)(pSVar1 + 0x2ac) != 0) && (*(int *)(pSVar1 + 0x2a8) != 0)) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicleCar::WheelReset
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::WheelReset
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2)
{
{
  float fVar1;
  GmFrustumIso4 *pGVar2;
  SCasterCat *pSVar3;
  GmFrustumIso4 *unaff_ESI;
  ulong unaff_EDI;
  GmFrustumIso4 *pGVar4;
  SSurfaceHandler *in_stack_fffffff4;
  GmFrustumIso4 *pGVar5;
  GmFrustumIso4 *pGVar6;
  
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 100) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                       (*(int *)(this + 100) + 0x24),unaff_EDI);
  fVar1 = *(float *)(*(int *)pSVar3 + 0x124);
  *(float *)(param_1 + 0xb4) = fVar1;
  pGVar6 = (GmFrustumIso4 *)-fVar1;
  pGVar2 = (GmFrustumIso4 *)((float)_PTR_00b2c178 * (float)pGVar6);
  pGVar4 = pGVar2;
  pGVar5 = pGVar2;
  CSceneVehicle::SSurfaceHandler::Reset(param_1 + 0xc,unaff_ESI);
  *(float *)(param_1 + 100) = *(float *)(param_1 + 100) + (float)pGVar6;
  *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x68) + (float)pGVar4;
  *(float *)(param_1 + 0x6c) = *(float *)(param_1 + 0x6c) + (float)param_1;
  CSceneVehicle::SSurfaceHandler::UpdateSurface(param_1 + 0xc,in_stack_fffffff4);
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  GmIso4::SetIdentity(param_1 + 0xe4,(GmMat43 *)pGVar5);
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined2 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  SSimulationWheel::SState::Reset(param_1 + 0x234,pGVar6);
  SSimulationWheel::SState::Reset(param_1 + 0x298,pGVar4);
  SSimulationWheel::SState::Reset(param_1 + 0x16c,(GmFrustumIso4 *)param_1);
  SSimulationWheel::SState::Reset(param_1 + 0x1d0,pGVar2);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed
          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2,float param_3,
          float param_4)
{
{
  float fVar1;
  CSceneVehicleCar *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  
  pCVar2 = param_1;
  fVar1 = _DAT_00b9ef4c;
  if (*(int *)(param_1 + 0x124) != 0) {
    if ((*(int *)(this + 0x6a0) != 0) && (*(int *)(this + 0x73c) == 0)) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 100) + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (*(int *)(this + 100) + 0x24),unaff_ESI);
      *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(*(int *)pSVar3 + 700);
      return;
    }
    *(float *)(param_1 + 0x120) = (float)param_2 / *(float *)(param_1 + 8);
    return;
  }
  param_2 = (SSimulationWheel *)0x0;
  param_1 = (CSceneVehicleCar *)0x0;
  if (*(float *)(this + 0x54) <= _DAT_00b9ef4c) {
    if (((*(float *)(this + 0x50) <= _DAT_00b9ef4c) || (*(int *)(this + 0x73c) != 0)) ||
       (*(int *)(this + 0x60c) != 0)) {
      *(float *)(pCVar2 + 0x120) = *(float *)(pCVar2 + 0x120) * (float)_DAT_00b9f1c0;
    }
    else {
      param_1 = (CSceneVehicleCar *)(*(float *)(this + 0x50) * (float)_DAT_00b2f718);
      param_2 = _DAT_00b36adc;
    }
  }
  else {
    param_1 = (CSceneVehicleCar *)(1.0 - *(float *)(this + 0x54));
    if ((float)param_1 < 0.0 == ((float)param_1 == 0.0)) {
      if (NAN((float)param_1) || 1.0 < (float)param_1 == ((float)param_1 == 1.0)) {
        param_2 = _DAT_00b36184;
      }
      else {
        param_1 = (CSceneVehicleCar *)0x3f800000;
        param_2 = _DAT_00b36184;
      }
    }
    else {
      param_1 = (CSceneVehicleCar *)0x0;
      param_2 = _DAT_00b36184;
    }
  }
  if (fVar1 <= ABS((float)param_2)) {
    fVar1 = (float)param_2 * param_3 + *(float *)(pCVar2 + 0x120);
    *(float *)(pCVar2 + 0x120) = fVar1;
    if ((0.0 < (float)param_2) && ((float)param_1 < fVar1)) {
      *(CSceneVehicleCar **)(pCVar2 + 0x120) = param_1;
      return;
    }
    if (((float)param_2 < 0.0) && (fVar1 < (float)param_1)) {
      *(CSceneVehicleCar **)(pCVar2 + 0x120) = param_1;
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::_vector_deleting_destructor_
// =================================================
void * __thiscall
CSceneVehicleCar::_vector_deleting_destructor_
          (CSceneVehicleCar *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CSceneVehicleCar *unaff_ESI;
  
  ~CSceneVehicleCar(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CSceneVehicleCar::~CSceneVehicleCar
// =================================================
void __thiscall
CSceneVehicleCar::~CSceneVehicleCar(CSceneVehicleCar *this,CSceneVehicleCar *param_1)
{
{
  CSceneToyCharacterTunings *pCVar1;
  CSceneVehicleCar *pCVar2;
  CSceneVehicle *pCVar3;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00acc93e;
  local_c = ExceptionList;
  pCVar1 = (CSceneToyCharacterTunings *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 2;
  CSceneVehicle::TuningsSet((CSceneVehicle *)this,(CSceneToyCharacter *)0x0,pCVar1);
  pCVar3 = (CSceneVehicle *)&DAT_00000030;
  pCVar2 = this + 0x750;
  _eh_vector_destructor_iterator_(pCVar2,0x30,4,SPlugGpuLoadFx::~SPlugGpuLoadFx);
  local_10 = (void *)((uint)this & 0xffffff00);
  CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::
  ~CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>
            (this + 0x2e8,(CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel> *)pCVar2);
  local_c = (void *)0xffffffff;
  CSceneVehicle::~CSceneVehicle((CSceneVehicle *)this,pCVar3);
  ExceptionList = local_10;
  return;
}
}

