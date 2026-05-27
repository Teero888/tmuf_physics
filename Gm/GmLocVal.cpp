// Class implementation: GmLocVal

// =================================================
// Function: GmLocVal::Reset
// =================================================
void __thiscall GmLocVal::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  GmMat43 *unaff_ESI;
  
  GmMat3::SetIdentity(this,unaff_ESI);
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  return;
}
}

// =================================================
// Function: GmLocVal::SetLinearInterp
// =================================================
void __thiscall
GmLocVal::SetLinearInterp
          (void *this,GmLensVal *param_1,GmLensVal *param_2,GmLensVal *param_3,float param_4)
{
{
  float unaff_retaddr;
  
  GmIso4::SetBlend(this,(SParam *)param_1,(SParam *)param_2,(SParam *)param_3,unaff_retaddr);
  return;
}
}

