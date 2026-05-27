// Class implementation: CAudioSoundMulti

// =================================================
// Function: CAudioSoundMulti::CAudioSoundMulti
// =================================================
void __thiscall
CAudioSoundMulti::CAudioSoundMulti
          (CAudioSoundMulti *this,CAudioSoundMulti *param_1,CPlugSoundMulti *param_2,
          CAudioPort *param_3)
{
{
  CAudioPort *unaff_ESI;
  
  CAudioSound::CAudioSound
            ((CAudioSound *)this,(CAudioSound *)param_1,(CPlugSound *)param_2,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x78) = 0;
  return;
}
}

