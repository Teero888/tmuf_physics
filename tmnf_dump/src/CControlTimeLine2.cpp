// Class implementation: CControlTimeLine2

// =================================================
// Function: CControlTimeLine2::GetTreeXFromTime
// =================================================
void __thiscall
CControlTimeLine2::GetTreeXFromTime
          (CControlTimeLine2 *this,CControlTimeLine2 *param_1,float param_2,float *param_3,
          int *param_4)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = ((float)param_1 - *(float *)(this + 0x13c)) /
          (*(float *)(this + 0x140) - *(float *)(this + 0x13c));
  if ((fVar1 < 0.0) || (1.0 < fVar1)) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = 1.4013e-45;
  }
  *param_3 = fVar2;
  *(float *)param_2 = -fVar1 * *(float *)(this + 0x154);
  return;
}
}

// =================================================
// Function: CControlTimeLine2::TimeSet
// =================================================
void __thiscall
CControlTimeLine2::TimeSet(CControlTimeLine2 *this,CControlTimeLine2 *param_1,float param_2)
{
{
  CControlTimeLine *unaff_retaddr;
  
  *(CControlTimeLine2 **)(this + 0x138) = param_1;
  UpdateTimeVisual(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CControlTimeLine2::UpdateTimeVisual
// =================================================
void __thiscall
CControlTimeLine2::UpdateTimeVisual(CControlTimeLine2 *this,CControlTimeLine *param_1)
{
{
  uint *puVar1;
  int *unaff_ESI;
  GmVec3 *in_stack_fffffff0;
  undefined1 local_c [4];
  int local_8;
  float local_4;
  
  GetTreeXFromTime(this,*(CControlTimeLine2 **)(this + 0x138),(float)local_c,
                   (float *)&stack0xfffffff0,unaff_ESI);
  local_4 = -*(float *)(this + 0x158);
  CPlugTree::SetTranslation(*(CPlugTree **)(this + 0x280),(GmIso4 *)&local_8,in_stack_fffffff0);
  puVar1 = (uint *)(*(int *)(this + 0x280) + 0x9c);
  *puVar1 = *puVar1 ^ ((uint)(local_8 != 0) * 8 ^ *(uint *)(*(int *)(this + 0x280) + 0x9c)) & 8;
  (**(code **)(**(int **)(this + 0x280) + 0xbc))();
  return;
}
}

