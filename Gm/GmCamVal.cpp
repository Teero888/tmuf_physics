// Class implementation: GmCamVal

// =================================================
// Function: GmCamVal::SetLinearInterp
// =================================================
void __thiscall
GmCamVal::SetLinearInterp
          (void *this,GmLensVal *param_1,GmLensVal *param_2,GmLensVal *param_3,float param_4)
{
{
  float unaff_ESI;
  float unaff_EDI;
  
  GmLocVal::SetLinearInterp(this,param_1,param_2,param_3,unaff_EDI);
  GmLensVal::SetLinearInterp
            ((void *)((int)this + 0x30),param_1 + 0x30,param_2 + 0x30,(GmLensVal *)param_4,unaff_ESI
            );
  return;
}
}

