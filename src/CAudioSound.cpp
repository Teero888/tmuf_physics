// Class implementation: CAudioSound

// =================================================
// Function: CAudioSound::CAudioSound
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CAudioSound::CAudioSound
          (CAudioSound *this,CAudioSound *param_1,CPlugSound *param_2,CAudioPort *param_3)
{
{
  int iVar1;
  CMwNod *unaff_EBX;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  int in_stack_00000018;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acaa13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4),unaff_EDI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x44) = 0;
  if (param_3 != (CAudioPort *)0x0) {
    CMwNod::MwAddRef((CMwNod *)param_3,unaff_ESI);
    if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x44),unaff_EBX);
    }
    *(CAudioPort **)(this + 0x44) = param_3;
  }
  *(undefined4 *)(this + 0x4c) = 0x3f800000;
  *(undefined4 *)(this + 0x74) = 0;
  iVar1 = *(int *)(in_stack_00000018 + 0x14);
  *(undefined4 *)(this + 0x54) = _DAT_00b2c060;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(uint *)(this + 0x48) = (uint)(iVar1 == 0);
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  *(undefined4 *)(this + 0x40) = 0x3f800000;
  ExceptionList = (void *)0x1;
  return;
}
}

// =================================================
// Function: CAudioSound::Play
// =================================================
void __thiscall
CAudioSound::Play(CAudioSound *this,CPlugFileVideo *param_1,EPlugVideoTimer param_2,int param_3,
                 ulong param_4)
{
{
  ulong *puVar1;
  CMwTimerAdapter *unaff_ESI;
  
  puVar1 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
  if ((*(int *)(this + 0x50) == 0) || (*(int *)(this + 0x50) + 0x4bU < *puVar1)) {
    *(ulong *)(this + 0x50) = *puVar1;
    *(EPlugVideoTimer *)(this + 0x54) = param_2;
    if (*(int **)(this + 0x74) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x74) + 4))();
    }
  }
  return;
}
}

// =================================================
// Function: CAudioSound::Stop
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CAudioSound::Stop(CAudioSound *this,STmRaceLowFps *param_1)
{
{
  undefined4 uVar1;
  
  if ((*(int *)(this + 0x50) != 0) && (*(int **)(this + 0x74) != (int *)0x0)) {
    (**(code **)(**(int **)(this + 0x74) + 8))();
  }
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = uVar1;
  return;
}
}

