// Class implementation: CHmsOcclusion

// =================================================
// Function: CHmsOcclusion::UpdateInput
// =================================================
void __thiscall CHmsOcclusion::UpdateInput(void *this,CGameCtnPainter *param_1)
{
{
  *(float *)((int)this + 0xc0) = 1.0 / *(float *)((int)this + 4);
  *(float *)((int)this + 0xc4) = 1.0 / *(float *)((int)this + 8);
  *(float *)((int)this + 200) = 1.0 / *(float *)((int)this + 0xc);
  Clean(this,(CHmsOcclusion *)param_1);
  return;
}
}

