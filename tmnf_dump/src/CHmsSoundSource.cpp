// Class implementation: CHmsSoundSource

// =================================================
// Function: CHmsSoundSource::GetIsPlaying
// =================================================
int __thiscall CHmsSoundSource::GetIsPlaying(CHmsSoundSource *this,CSceneSoundSource *param_1)
{
{
  if (((*(int *)(this + 0x94) == 0) && (*(int *)(this + 0x54) == 0)) && (*(int *)(this + 0xa0) == 0)
     ) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CHmsSoundSource::ResetSoundParams
// =================================================
void __thiscall CHmsSoundSource::ResetSoundParams(CHmsSoundSource *this,CHmsSoundSource *param_1)
{
{
  *(undefined4 *)(this + 0x70) = 0x3f800000;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x74) = 0x3f800000;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  return;
}
}

