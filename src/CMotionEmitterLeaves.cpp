// Class implementation: CMotionEmitterLeaves

// =================================================
// Function: CMotionEmitterLeaves::OnAbsorbContact
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionEmitterLeaves::OnAbsorbContact
          (CMotionEmitterLeaves *this,CMotions *param_1,CHmsPhysicalContact *param_2)
{
{
  if (*(short *)(param_1 + 8) == 0xe) {
    *(undefined4 *)(this + 0x24) = _DAT_00b36ad4;
  }
  return;
}
}

