// Class implementation: CAudioSoundSurface

// =================================================
// Function: CAudioSoundSurface::CAudioSoundSurface
// =================================================
void __thiscall
CAudioSoundSurface::CAudioSoundSurface
          (CAudioSoundSurface *this,CAudioSoundSurface *param_1,CPlugSoundSurface *param_2,
          CAudioPort *param_3)
{
{
  CAudioPort *unaff_ESI;
  
  CAudioSound::CAudioSound
            ((CAudioSound *)this,(CAudioSound *)param_1,(CPlugSound *)param_2,unaff_ESI);
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined ***)this = vftable;
  return;
}
}

