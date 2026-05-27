// Class implementation: CMotionTimerLoop

// =================================================
// Function: CMotionTimerLoop::GetNormedTime
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CMotionTimerLoop::GetNormedTime(CMotionTimerLoop *this,CMotionTimerLoop *param_1)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)*(int *)(this + 0x18);
  if (*(int *)(this + 0x18) < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  fVar2 = (float)*(int *)(this + 0x20);
  if (*(int *)(this + 0x20) < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  return fVar1 / fVar2;
}
}

