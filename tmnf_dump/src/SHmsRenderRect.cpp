// Class implementation: SHmsRenderRect

// =================================================
// Function: SHmsRenderRect::ComputeTransfosFromRect
// =================================================
void __thiscall SHmsRenderRect::ComputeTransfosFromRect(void *this,SHmsRenderRect *param_1)
{
{
  GmScaleTrans2 *unaff_ESI;
  GmRectAligned *unaff_EDI;
  
  GmScaleTrans2::SetRect_ConvTo_Rectm1p1
            ((GmScaleTrans2 *)((int)this + 0x44),(GmScaleTrans2 *)((int)this + 0x24),unaff_EDI);
  GmScaleTrans2::SetInverse
            ((void *)((int)this + 0x34),(GmScaleTrans2 *)((int)this + 0x44),unaff_ESI);
  return;
}
}

// =================================================
// Function: SHmsRenderRect::CutScissorRect
// =================================================
void __thiscall
SHmsRenderRect::CutScissorRect(void *this,SHmsRenderRect *param_1,GmRectAligned *param_2)
{
{
  GmIso4 *unaff_ESI;
  SHmsRenderRect *unaff_retaddr;
  
  GmRectAligned::SetMult
            ((void *)((int)this + 0x24),(SPlugFaceCull *)param_1,(SPlugFaceCull *)((int)this + 0x44)
             ,unaff_ESI);
  ComputeTransfosFromRect(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: SHmsRenderRect::Reset
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall SHmsRenderRect::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  undefined4 uVar1;
  
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)((int)this + 0x24) = _DAT_00b2c060;
  *(undefined4 *)((int)this + 0x28) = uVar1;
  *(undefined4 *)((int)this + 0x2c) = 0x3f800000;
  *(undefined4 *)((int)this + 0x30) = 0x3f800000;
  *(undefined4 *)((int)this + 0x34) = 0x3f800000;
  *(undefined4 *)((int)this + 0x38) = 0x3f800000;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x44) = 0x3f800000;
  *(undefined4 *)((int)this + 0x48) = 0x3f800000;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0x3f800000;
  return;
}
}

// =================================================
// Function: SHmsRenderRect::SetRect
// =================================================
void __thiscall
SHmsRenderRect::SetRect
          (void *this,CDynaSpecular *param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5
          ,ulong param_6)
{
{
  SHmsRenderRect *unaff_retaddr;
  
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0x30) = *(undefined4 *)(param_1 + 0xc);
  ComputeTransfosFromRect(this,unaff_retaddr);
  return;
}
}

