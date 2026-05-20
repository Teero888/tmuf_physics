// Class implementation: SVisualId

// =================================================
// Function: SVisualId::Reset
// =================================================
void __thiscall SVisualId::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  *(undefined4 *)this = 0xffffffff;
  *(undefined4 *)((int)this + 4) = 0;
  return;
}
}

// =================================================
// Function: SVisualId::SVisualId
// =================================================
void __thiscall SVisualId::SVisualId(void *this,SVisualId *param_1)
{
{
  CMwId *unaff_ESI;
  GmFrustumIso4 *unaff_retaddr;
  
  CMwId::CMwId(this,unaff_ESI);
  Reset(this,unaff_retaddr);
  return;
}
}

