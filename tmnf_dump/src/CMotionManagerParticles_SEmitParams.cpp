// Class implementation: CMotionManagerParticles_SEmitParams

// =================================================
// Function: CMotionManagerParticles::SEmitParams::Reset
// =================================================
void __thiscall CMotionManagerParticles::SEmitParams::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  GmMat43 *unaff_ESI;
  
  GmIso4::SetIdentity(this,unaff_ESI);
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x48) = 0x3f800000;
  *(undefined4 *)((int)this + 0x30) = 0x3f800000;
  *(undefined4 *)((int)this + 0x34) = 0x3f800000;
  *(undefined4 *)((int)this + 0x38) = 0x3f800000;
  *(undefined4 *)((int)this + 0x4c) = 0x3f800000;
  *(undefined4 *)((int)this + 0x50) = 0x3f800000;
  *(undefined4 *)((int)this + 0x54) = 0x3f800000;
  return;
}
}

