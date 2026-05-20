// Class implementation: CMotionEmitterParticles

// =================================================
// Function: CMotionEmitterParticles::CMotionEmitterParticles
// =================================================
void __thiscall
CMotionEmitterParticles::CMotionEmitterParticles
          (CMotionEmitterParticles *this,CMotionEmitterParticles *param_1)
{
{
  GmFrustumIso4 *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a97d16;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMotionManaged::CMotionManaged
            ((CMotionManaged *)this,(CMotionManaged *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  CMotionManagerParticles::SEmitParams::Reset(this + 0x24,unaff_EDI);
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x7c) = 1;
  *(undefined4 *)(this + 0x84) = 0;
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CMotionEmitterParticles::SetEmitterModel
// =================================================
void __thiscall
CMotionEmitterParticles::SetEmitterModel
          (CMotionEmitterParticles *this,CMotionEmitterParticles *param_1,
          CMotionParticleEmitterModel *param_2)
{
{
  ulong unaff_ESI;
  CScene *unaff_EDI;
  CScene *unaff_retaddr;
  CMwNod *in_stack_0000000c;
  
  CMotionManaged::ReleaseManager((CMotionManaged *)this,unaff_EDI,unaff_ESI);
  if (in_stack_0000000c != *(CMwNod **)(this + 0x88)) {
    if (in_stack_0000000c != (CMwNod *)0x0) {
      CMwNod::MwAddRef(in_stack_0000000c,(CMwNod *)unaff_retaddr);
    }
    if (*(CMwNod **)(this + 0x88) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x88),(CMwNod *)unaff_retaddr);
    }
    *(CMwNod **)(this + 0x88) = in_stack_0000000c;
  }
  CMotionManaged::QueryManager((CMotionManaged *)this,unaff_retaddr,(ulong)param_1);
  return;
}
}

// =================================================
// Function: CMotionEmitterParticles::SetIsActive
// =================================================
void __thiscall
CMotionEmitterParticles::SetIsActive
          (CMotionEmitterParticles *this,CSceneObjectLink *param_1,int param_2)
{
{
  *(CSceneObjectLink **)(this + 0x8c) = param_1;
  return;
}
}

// =================================================
// Function: CMotionEmitterParticles::SetIsEventMode
// =================================================
void __thiscall
CMotionEmitterParticles::SetIsEventMode
          (CMotionEmitterParticles *this,CMotionEmitterParticles *param_1,int param_2)
{
{
  *(CMotionEmitterParticles **)(this + 0x80) = param_1;
  return;
}
}

