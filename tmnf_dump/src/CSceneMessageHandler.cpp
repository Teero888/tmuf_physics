// Class implementation: CSceneMessageHandler

// =================================================
// Function: CSceneMessageHandler::AbsorbContact
// =================================================
void __thiscall
CSceneMessageHandler::AbsorbContact
          (CSceneMessageHandler *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2,
          CHmsPhysicalContact *param_3)
{
{
  int iVar1;
  void *this_00;
  ulong *puVar2;
  CMwTimerAdapter *unaff_EDI;
  
  *(CSceneMobilAbsorbContact **)(this + 0x28) = param_1;
  this_00 = *(void **)(DAT_00d731e0 + 0x14);
  if (this_00 == (void *)0x0) {
    this_00 = (void *)(DAT_00d731e0 + 0xa0);
  }
  puVar2 = CMwTimerAdapter::GetTickTime(this_00,unaff_EDI);
  *(ulong *)(this + 0x2c) = *puVar2;
  if (*(CMwCmdBlockMain **)(this + 0x20) != (CMwCmdBlockMain *)0x0) {
    iVar1 = *(int *)(param_3 + 0x40);
    *(int *)(this + 0x30) = iVar1;
    *(undefined4 *)(this + 0x34) = *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x40);
    *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_3 + 0xc);
    *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_3 + 0x10);
    *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_3 + 0x14);
    *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_3 + 0x18);
    *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_3 + 0x1c);
    *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_3 + 0x20);
    CMwCmdBlockMain::Run(*(CMwCmdBlockMain **)(this + 0x20),(CMwCmdExpStringConcat *)this);
    *(undefined4 *)(this + 0x30) = 0;
    *(undefined4 *)(this + 0x34) = 0;
  }
  *(undefined4 *)(this + 0x28) = 0;
  return;
}
}

// =================================================
// Function: CSceneMessageHandler::OnStillFocus
// =================================================
void __thiscall
CSceneMessageHandler::OnStillFocus
          (CSceneMessageHandler *this,CSceneMessageHandler *param_1,CSceneMobil *param_2,
          CSceneInfoFocus *param_3,CSceneInfoFocus *param_4)
{
{
  CPlugAudio *this_00;
  CMwId *pCVar1;
  CPlugAudio *unaff_ESI;
  
  *(CSceneMessageHandler **)(this + 0x28) = param_1;
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar1 = CPlugAudio::MwGetId(this_00,unaff_ESI);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)pCVar1;
  if ((((byte)param_3[0x1c] & 4) != 0) &&
     (*(CMwCmdBlockMain **)(this + 0x1c) != (CMwCmdBlockMain *)0x0)) {
    CMwCmdBlockMain::Run(*(CMwCmdBlockMain **)(this + 0x1c),(CMwCmdExpStringConcat *)this);
  }
  *(undefined4 *)(this + 0x28) = 0;
  return;
}
}

// =================================================
// Function: CSceneMessageHandler::SetOnContactScript
// =================================================
void __thiscall
CSceneMessageHandler::SetOnContactScript
          (CSceneMessageHandler *this,CSceneMessageHandler *param_1,CMwCmdBlockMain *param_2)
{
{
  CMwNod *unaff_EDI;
  
  if (param_1 != (CSceneMessageHandler *)0x0) {
    CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    unaff_EDI = (CMwNod *)0xa01f000;
    (**(code **)(*(int *)param_1 + 0xac))();
  }
  if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x20),unaff_EDI);
  }
  *(CSceneMessageHandler **)(this + 0x20) = param_1;
  *(uint *)(this + 0x18) = (uint)(param_1 != (CSceneMessageHandler *)0x0);
  return;
}
}

