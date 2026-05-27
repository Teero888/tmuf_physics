// Class implementation: CAudioSoundEngine

// =================================================
// Function: CAudioSoundEngine::CAudioSoundEngine
// =================================================
void __thiscall
CAudioSoundEngine::CAudioSoundEngine
          (CAudioSoundEngine *this,CAudioSoundEngine *param_1,CPlugSoundEngine *param_2,
          CAudioPort *param_3)
{
{
  CAudioPort *unaff_EDI;
  
  CAudioSound::CAudioSound
            ((CAudioSound *)this,(CAudioSound *)param_1,(CPlugSound *)param_2,unaff_EDI);
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(CPlugSoundEngine **)(this + 0x170) = param_2;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x16c) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined ***)this = vftable;
  return;
}
}

