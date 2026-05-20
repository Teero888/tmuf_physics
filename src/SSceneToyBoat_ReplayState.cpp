// Class implementation: SSceneToyBoat_ReplayState

// =================================================
// Function: SSceneToyBoat_ReplayState::SetFromBoat
// =================================================
void __thiscall
SSceneToyBoat_ReplayState::SetFromBoat
          (void *this,SSceneToyBoat_NetState *param_1,CSceneToyBoat *param_2)
{
{
  SCasterCat *pSVar1;
  CSceneToyBoat *pCVar2;
  CSceneToyBoat *pCVar3;
  CBoatSailState *pCVar4;
  int iVar5;
  ESailType unaff_EBX;
  CSceneToyBoat *unaff_EBP;
  CSceneToyBoat *unaff_ESI;
  undefined4 *puVar6;
  ulong unaff_EDI;
  undefined4 *puVar7;
  CBoatSailState *unaff_retaddr;
  ESailType in_stack_0000000c;
  CBoatSailState *in_stack_00000010;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(param_1 + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
  if (*(int *)(*(int *)pSVar1 + 0x58) == 0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6 = (undefined4 *)(*(int *)(*(int *)(*(int *)pSVar1 + 0x58) + 0x32c) + 0x10);
  }
  puVar7 = (undefined4 *)((int)this + 0x48);
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  *(undefined4 *)((int)this + 0x78) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)((int)this + 0x7c) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)((int)this + 0x80) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)((int)this + 0x88) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)((int)this + 0x84) = *(undefined4 *)(param_1 + 0xb8);
  pCVar2 = (CSceneToyBoat *)CSceneToyBoat::SailTypeCurGet((CSceneToyBoat *)param_1,unaff_ESI);
  pCVar3 = (CSceneToyBoat *)CSceneToyBoat::SailTypeNextGet((CSceneToyBoat *)param_1,unaff_EBP);
  pCVar4 = CSceneToyBoat::SailStateGet((CSceneToyBoat *)param_1,(CSceneToyBoat *)0x0,unaff_EBX);
  SSceneToyBoat_SailState::SetFromSail
            (this,(SSceneToyBoat_SailState *)0x0,(ESailType)pCVar4,unaff_retaddr);
  pCVar4 = CSceneToyBoat::SailStateGet((CSceneToyBoat *)param_1,pCVar2,(ESailType)param_1);
  SSceneToyBoat_SailState::SetFromSail
            ((void *)((int)this + 0x18),(SSceneToyBoat_SailState *)pCVar2,(ESailType)pCVar4,
             (CBoatSailState *)param_2);
  pCVar4 = CSceneToyBoat::SailStateGet((CSceneToyBoat *)param_1,pCVar3,in_stack_0000000c);
  SSceneToyBoat_SailState::SetFromSail
            ((void *)((int)this + 0x30),(SSceneToyBoat_SailState *)pCVar3,(ESailType)pCVar4,
             in_stack_00000010);
  return;
}
}

