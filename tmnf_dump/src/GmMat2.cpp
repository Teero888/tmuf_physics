// Class implementation: GmMat2

// =================================================
// Function: GmMat2::Mult
// =================================================
void __thiscall GmMat2::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  SetMult(this,(SPlugFaceCull *)&stack0xfffffff0,(SPlugFaceCull *)param_1,*(GmIso4 **)this);
  return;
}
}

// =================================================
// Function: GmMat2::Rotate
// =================================================
void __thiscall GmMat2::Rotate(void *this,GmMat2 *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  __CIsin();
  fVar1 = (float)extraout_ST0;
  __CIcos();
  fVar2 = (float)extraout_ST0_00;
  fVar3 = *(float *)this;
  *(float *)this = fVar2 * fVar3 - fVar1 * *(float *)((int)this + 8);
  *(float *)((int)this + 8) = fVar2 * *(float *)((int)this + 8) + fVar1 * fVar3;
  fVar3 = *(float *)((int)this + 4);
  *(float *)((int)this + 4) = fVar3 * fVar2 - *(float *)((int)this + 0xc) * fVar1;
  *(float *)((int)this + 0xc) = fVar3 * fVar1 + *(float *)((int)this + 0xc) * fVar2;
  return;
}
}

// =================================================
// Function: GmMat2::SetIdentity
// =================================================
void __thiscall GmMat2::SetIdentity(void *this,GmMat43 *param_1)
{
{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0x3f800000;
  return;
}
}

// =================================================
// Function: GmMat2::SetMult
// =================================================
void __thiscall
GmMat2::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  int iVar1;
  uint uVar2;
  GmMat2 *unaff_ESI;
  float unaff_retaddr;
  undefined1 local_10 [4];
  float local_c;
  float local_8;
  float local_4;
  
  SetTranspose(local_10,(GmMat2 *)param_1,unaff_ESI);
  uVar2 = 0;
  do {
    iVar1 = uVar2 * 8;
    uVar2 = uVar2 + 1;
    *(float *)this =
         *(float *)(param_3 + uVar2 * 8 + -4) * local_8 + *(float *)(param_3 + iVar1) * local_c;
    *(float *)((int)this + 4) =
         *(float *)(param_3 + uVar2 * 8 + -4) * unaff_retaddr +
         *(float *)(param_3 + uVar2 * 8 + -8) * local_4;
    this = (float *)((int)this + 8);
  } while (uVar2 < 2);
  return;
}
}

// =================================================
// Function: GmMat2::SetRotation
// =================================================
void __thiscall GmMat2::SetRotation(void *this,GmMat2 *param_1,float param_2)
{
{
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  __CIsin();
  __CIcos();
  *(float *)this = (float)extraout_ST0_00;
  *(float *)((int)this + 8) = -(float)extraout_ST0;
  *(float *)((int)this + 4) = (float)extraout_ST0;
  *(float *)((int)this + 0xc) = (float)extraout_ST0_00;
  return;
}
}

// =================================================
// Function: GmMat2::SetTranspose
// =================================================
void __thiscall GmMat2::SetTranspose(void *this,GmMat2 *param_1,GmMat2 *param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  pSVar1 = GmVec2::operator[](param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              unaff_EDI);
  *(undefined4 *)this = *(undefined4 *)pSVar1;
  pSVar1 = GmVec2::operator[](param_1 + 8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              unaff_ESI);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)pSVar1;
  pSVar1 = GmVec2::operator[](param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                              unaff_EBX);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)pSVar1;
  pSVar1 = GmVec2::operator[](param_1 + 8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                              unaff_retaddr);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)pSVar1;
  return;
}
}

