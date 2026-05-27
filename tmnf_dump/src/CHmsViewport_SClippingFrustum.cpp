// Class implementation: CHmsViewport_SClippingFrustum

// =================================================
// Function: CHmsViewport::SClippingFrustum::ComputePlaneEqs
// =================================================
void __thiscall
CHmsViewport::SClippingFrustum::ComputePlaneEqs
          (void *this,SClippingFrustum *param_1,GmIso4 *param_2)
{
{
  GmIso4 *unaff_EDI;
  
  *(undefined4 *)((int)this + 0x1c) = 6;
  GmFrustum::GetPlaneEqs6(this,(GmFrustum *)((int)this + 0x20),(GmVec4 *)param_1,unaff_EDI);
  *(float *)((int)this + 0xc0) = ABS(*(float *)((int)this + 0x20));
  *(float *)((int)this + 0xc4) = ABS(*(float *)((int)this + 0x24));
  *(float *)((int)this + 200) = ABS(*(float *)((int)this + 0x28));
  *(float *)((int)this + 0xcc) = ABS(*(float *)((int)this + 0x30));
  *(float *)((int)this + 0xd0) = ABS(*(float *)((int)this + 0x34));
  *(float *)((int)this + 0xd4) = ABS(*(float *)((int)this + 0x38));
  *(float *)((int)this + 0xd8) = ABS(*(float *)((int)this + 0x40));
  *(float *)((int)this + 0xdc) = ABS(*(float *)((int)this + 0x44));
  *(float *)((int)this + 0xe0) = ABS(*(float *)((int)this + 0x48));
  *(float *)((int)this + 0xe4) = ABS(*(float *)((int)this + 0x50));
  *(float *)((int)this + 0xe8) = ABS(*(float *)((int)this + 0x54));
  *(float *)((int)this + 0xec) = ABS(*(float *)((int)this + 0x58));
  *(float *)((int)this + 0xf0) = ABS(*(float *)((int)this + 0x60));
  *(float *)((int)this + 0xf4) = ABS(*(float *)((int)this + 100));
  *(float *)((int)this + 0xf8) = ABS(*(float *)((int)this + 0x68));
  *(float *)((int)this + 0xfc) = ABS(*(float *)((int)this + 0x70));
  *(float *)((int)this + 0x100) = ABS(*(float *)((int)this + 0x74));
  *(float *)((int)this + 0x104) = ABS(*(float *)((int)this + 0x78));
  return;
}
}

// =================================================
// Function: CHmsViewport::SClippingFrustum::Set
// =================================================
void __thiscall
CHmsViewport::SClippingFrustum::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  GmIso4 *unaff_ESI;
  int unaff_EDI;
  GmVec4 *in_stack_0000000c;
  
  *(undefined4 *)((int)this + 0x1c) = 6;
  GmFrustum::Set(this,param_1,unaff_EDI);
  GmFrustum::GetPlaneEqs6(this,(GmFrustum *)((int)this + 0x20),in_stack_0000000c,unaff_ESI);
  *(float *)((int)this + 0xc0) = ABS(*(float *)((int)this + 0x20));
  *(float *)((int)this + 0xc4) = ABS(*(float *)((int)this + 0x24));
  *(float *)((int)this + 200) = ABS(*(float *)((int)this + 0x28));
  *(float *)((int)this + 0xcc) = ABS(*(float *)((int)this + 0x30));
  *(float *)((int)this + 0xd0) = ABS(*(float *)((int)this + 0x34));
  *(float *)((int)this + 0xd4) = ABS(*(float *)((int)this + 0x38));
  *(float *)((int)this + 0xd8) = ABS(*(float *)((int)this + 0x40));
  *(float *)((int)this + 0xdc) = ABS(*(float *)((int)this + 0x44));
  *(float *)((int)this + 0xe0) = ABS(*(float *)((int)this + 0x48));
  *(float *)((int)this + 0xe4) = ABS(*(float *)((int)this + 0x50));
  *(float *)((int)this + 0xe8) = ABS(*(float *)((int)this + 0x54));
  *(float *)((int)this + 0xec) = ABS(*(float *)((int)this + 0x58));
  *(float *)((int)this + 0xf0) = ABS(*(float *)((int)this + 0x60));
  *(float *)((int)this + 0xf4) = ABS(*(float *)((int)this + 100));
  *(float *)((int)this + 0xf8) = ABS(*(float *)((int)this + 0x68));
  *(float *)((int)this + 0xfc) = ABS(*(float *)((int)this + 0x70));
  *(float *)((int)this + 0x100) = ABS(*(float *)((int)this + 0x74));
  *(float *)((int)this + 0x104) = ABS(*(float *)((int)this + 0x78));
  return;
}
}

