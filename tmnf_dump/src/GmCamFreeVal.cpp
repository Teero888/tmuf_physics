// Class implementation: GmCamFreeVal

// =================================================
// Function: GmCamFreeVal::GetCamVal
// =================================================
void __thiscall GmCamFreeVal::GetCamVal(void *this,GmCamFreeVal *param_1,GmCamVal *param_2)
{
{
  GmLocVal *unaff_EDI;
  
  GmLocFreeVal::GetLocVal(this,(GmLocFreeVal *)param_1,unaff_EDI);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)((int)this + 0x18);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)((int)this + 0x1c);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)((int)this + 0x20);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)((int)this + 0x24);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)((int)this + 0x28);
  return;
}
}

