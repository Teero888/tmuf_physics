// Class implementation: CMwCmdBlockMain

// =================================================
// Function: CMwCmdBlockMain::Run
// =================================================
void __thiscall CMwCmdBlockMain::Run(CMwCmdBlockMain *this,CMwCmdExpStringConcat *param_1)
{
{
  CMwCmdExpStringConcat *unaff_ESI;
  
  CMwCmdBlock::Run((CMwCmdBlock *)this,unaff_ESI);
  *(uint *)(this + 0x48) = *(uint *)(this + 0x48) & 0xfffffffe;
  return;
}
}

// =================================================
// Function: CMwCmdBlockMain::Sleep
// =================================================
void __thiscall CMwCmdBlockMain::Sleep(CMwCmdBlockMain *this,CMwCmdBlock *param_1,ulong param_2)
{
{
  CPlugAudio *pCVar1;
  CPlugAudio *this_00;
  CMwId *pCVar2;
  CMwCmdFastCall *this_01;
  CMwCmd *extraout_EAX;
  CMwCmd *this_02;
  _func___cdecl_void *unaff_ESI;
  void *pvVar3;
  undefined1 *puVar4;
  
  pvVar3 = ExceptionList;
  puVar4 = &LAB_00ae500b;
  pCVar1 = (CPlugAudio *)(DAT_00cca150 ^ (uint)&stack0xfffffff0);
  ExceptionList = &stack0xfffffff4;
  if (DAT_00d35820 != 0) {
    *(uint *)(this + 0x48) = *(uint *)(this + 0x48) | 1;
    **(undefined4 **)(this + 0x70) = 1;
    this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
    if (this_00 == (CPlugAudio *)0x0) {
      this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
    }
    pCVar2 = CPlugAudio::MwGetId(this_00,pCVar1);
    *(undefined4 *)(*(int *)(this + 0x70) + 4) = *(undefined4 *)pCVar2;
    *(ulong *)(*(int *)(this + 0x70) + 8) = param_2;
    if (*(int *)(this + 0x6c) == 0) {
      this_01 = operator_new(0x24);
      if (this_01 == (CMwCmdFastCall *)0x0) {
        this_02 = (CMwCmd *)0x0;
      }
      else {
        CMwCmdFastCall::CMwCmdFastCall
                  (this_01,(CMwCmdFastCall *)this,(CMwNod *)CheckSleep,unaff_ESI,(ulong)pvVar3);
        this_02 = extraout_EAX;
      }
      *(CMwCmd **)(this + 0x6c) = this_02;
      CMwCmd::SetSchemeLocation(this_02,(CMwCmd *)&DAT_0000000e,(ulong)puVar4);
    }
    (**(code **)(**(int **)(this + 0x6c) + 0x7c))();
    ExceptionList = param_1;
    return;
  }
  (**(code **)(*(int *)this + 0xa4))(param_1);
  ExceptionList = unaff_ESI;
  return;
}
}

