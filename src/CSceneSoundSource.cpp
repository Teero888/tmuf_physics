// Class implementation: CSceneSoundSource

// =================================================
// Function: CSceneSoundSource::GetIsPlaying
// =================================================
int __thiscall CSceneSoundSource::GetIsPlaying(CSceneSoundSource *this,CSceneSoundSource *param_1)
{
{
  int iVar1;
  CSceneSoundSource *unaff_retaddr;
  
  if (*(CHmsSoundSource **)(this + 0x30) != (CHmsSoundSource *)0x0) {
    iVar1 = CHmsSoundSource::GetIsPlaying(*(CHmsSoundSource **)(this + 0x30),unaff_retaddr);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSceneSoundSource::GetPlugSound
// =================================================
CPlugSound * __thiscall
CSceneSoundSource::GetPlugSound(CSceneSoundSource *this,CSceneSoundSource *param_1)
{
{
  if (*(int *)(this + 0x30) != 0) {
    return *(CPlugSound **)(*(int *)(this + 0x30) + 0x58);
  }
  return (CPlugSound *)0x0;
}
}

// =================================================
// Function: CSceneSoundSource::Play
// =================================================
void __thiscall
CSceneSoundSource::Play
          (CSceneSoundSource *this,CPlugFileVideo *param_1,EPlugVideoTimer param_2,int param_3,
          ulong param_4)
{
{
  *(undefined4 *)(*(int *)(this + 0x30) + 0x94) = 1;
  *(undefined4 *)(*(int *)(this + 0x30) + 0x98) = 0;
  return;
}
}

// =================================================
// Function: CSceneSoundSource::SetVolume
// =================================================
void __thiscall
CSceneSoundSource::SetVolume(CSceneSoundSource *this,CSceneSoundSource *param_1,float param_2)
{
{
  *(CSceneSoundSource **)(*(int *)(this + 0x30) + 0x70) = param_1;
  return;
}
}

// =================================================
// Function: CSceneSoundSource::Stop
// =================================================
void __thiscall CSceneSoundSource::Stop(CSceneSoundSource *this,STmRaceLowFps *param_1)
{
{
  *(undefined4 *)(*(int *)(this + 0x30) + 0x98) = 1;
  *(undefined4 *)(*(int *)(this + 0x30) + 0x94) = 0;
  return;
}
}

