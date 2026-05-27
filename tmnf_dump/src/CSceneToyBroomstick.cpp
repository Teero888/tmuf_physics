// Class implementation: CSceneToyBroomstick

// =================================================
// Function: CSceneToyBroomstick::AbsorbContact
// =================================================
void __thiscall
CSceneToyBroomstick::AbsorbContact
          (CSceneToyBroomstick *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2,
          CHmsPhysicalContact *param_3)
{
{
  ulong *puVar1;
  void *this_00;
  CMwTimerAdapter *unaff_ESI;
  CHmsItem *unaff_retaddr;
  
  this_00 = *(void **)(DAT_00d731e0 + 0x14);
  if (this_00 == (void *)0x0) {
    this_00 = (void *)(DAT_00d731e0 + 0xa0);
  }
  puVar1 = CMwTimerAdapter::GetTickTime(this_00,unaff_ESI);
  if (*(ulong *)(this + 0x174) != *puVar1) {
    *(ulong *)(this + 0x174) = *puVar1;
    *(undefined4 *)(this + 0x180) = 0;
    *(undefined4 *)(this + 0x17c) = 0;
    *(undefined4 *)(this + 0x178) = 0;
  }
  *(float *)(this + 0x178) = *(float *)(this + 0x178) + *(float *)(param_2 + 0xc);
  *(float *)(this + 0x17c) = *(float *)(param_2 + 0x10) + *(float *)(this + 0x17c);
  *(float *)(this + 0x180) = *(float *)(param_2 + 0x14) + *(float *)(this + 0x180);
  CSceneToyCharacter::AbsorbContact
            ((CSceneToyCharacter *)this,(CSceneMobilAbsorbContact *)param_2,unaff_retaddr,
             (CHmsPhysicalContact *)param_1);
  return;
}
}

// =================================================
// Function: CSceneToyBroomstick::ComputeForces
// =================================================
void __thiscall
CSceneToyBroomstick::ComputeForces
          (CSceneToyBroomstick *this,CCallbackSceneToyBroomStickComputeForces *param_1,
          CHmsItem *param_2,float param_3)
{
{
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_retaddr;
  
  CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)(this + 0x188),unaff_ESI,unaff_retaddr)
  ;
  CHmsItem::SetAngularSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)(this + 300),(GmVec3 *)param_1);
  return;
}
}

// =================================================
// Function: CSceneToyBroomstick::UpdateAsync
// =================================================
void __thiscall CSceneToyBroomstick::UpdateAsync(CSceneToyBroomstick *this,CInputPortDx8 *param_1)
{
{
  CMwId *pCVar1;
  int iVar2;
  undefined4 *puVar3;
  CPlugAudio *this_00;
  GmVec3 *unaff_EBX;
  GmVec3 *unaff_ESI;
  CPlugAudio *unaff_EDI;
  CSceneToyBroomstick *pCVar4;
  
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar1 = CPlugAudio::MwGetId(this_00,unaff_EDI);
  *(undefined4 *)(this + 0x11c) = *(undefined4 *)pCVar1;
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)(this + 0x120),unaff_ESI);
  CHmsItem::GetAngularSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)(this + 300),unaff_EBX);
  iVar2 = (**(code **)(*(int *)this + 0x7c))(0);
  *(undefined4 *)(this + 0x138) = *(undefined4 *)(iVar2 + 0x24);
  *(undefined4 *)(this + 0x13c) = *(undefined4 *)(iVar2 + 0x28);
  *(undefined4 *)(this + 0x140) = *(undefined4 *)(iVar2 + 0x2c);
  puVar3 = (undefined4 *)(**(code **)(*(int *)this + 0x7c))(0);
  pCVar4 = this + 0x144;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pCVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    pCVar4 = pCVar4 + 4;
  }
  *(undefined4 *)(this + 0x170) = 0;
  *(undefined4 *)(this + 0x16c) = 0;
  *(undefined4 *)(this + 0x168) = 0;
  if (*(CMwCmdBlockMain **)(this + 0xd4) != (CMwCmdBlockMain *)0x0) {
    CMwCmdBlockMain::Run(*(CMwCmdBlockMain **)(this + 0xd4),(CMwCmdExpStringConcat *)this);
  }
  return;
}
}

