// Class implementation: CMotionManagerMeteoPuffLull

// =================================================
// Function: CMotionManagerMeteoPuffLull::UpdateAsync
// =================================================
void __thiscall
CMotionManagerMeteoPuffLull::UpdateAsync(CMotionManagerMeteoPuffLull *this,CInputPortDx8 *param_1)
{
{
  float unaff_retaddr;
  EState in_stack_00000008;
  
  CFuncPuffLull::UpdateStateCurrent
            (*(CFuncPuffLull **)(this + 0x18),(CFuncPuffLull *)param_1,1,in_stack_00000008,
             unaff_retaddr);
  return;
}
}

