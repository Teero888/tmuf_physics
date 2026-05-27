// Class implementation: GmMat3

// =================================================
// Function: GmMat3::ArchiveGmMat3
// =================================================
void __thiscall GmMat3::ArchiveGmMat3(void *this,GmMat3 *param_1,CClassicArchive *param_2)
{
{
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  ulong in_stack_0000000c;
  ulong in_stack_00000010;
  ulong in_stack_00000014;
  
  CClassicArchive::DoReal((CClassicArchive *)param_1,this,(float *)0x1,unaff_EDI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 4),(float *)0x1,unaff_ESI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 8),(float *)0x1,unaff_EBX);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0xc),(float *)0x1,
             unaff_retaddr);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x10),(float *)0x1,
             (ulong)param_1);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x14),(float *)0x1,
             (ulong)param_2);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x18),(float *)0x1,
             in_stack_0000000c);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x1c),(float *)0x1,
             in_stack_00000010);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x20),(float *)0x1,
             in_stack_00000014);
  return;
}
}

// =================================================
// Function: GmMat3::GetLine
// =================================================
void __thiscall GmMat3::GetLine(void *this,GmMat3 *param_1,ulong param_2,GmVec3 *param_3)
{
{
  *(undefined4 *)param_2 = *(undefined4 *)((int)this + (int)param_1 * 4);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)((int)this + (int)param_1 * 4 + 0xc);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)((int)this + (int)param_1 * 4 + 0x18);
  return;
}
}

// =================================================
// Function: GmMat3::Inverse
// =================================================
void __thiscall GmMat3::Inverse(void *this,GmIso4 *param_1)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  fVar1 = *(float *)this;
  fVar2 = *(float *)((int)this + 4);
  fVar3 = *(float *)((int)this + 8);
  fVar4 = *(float *)((int)this + 0xc);
  fVar5 = *(float *)((int)this + 0x10);
  fVar6 = *(float *)((int)this + 0x14);
  fVar7 = *(float *)((int)this + 0x18);
  fVar8 = *(float *)((int)this + 0x1c);
  fVar9 = *(float *)((int)this + 0x20);
  fVar12 = fVar5 * fVar9 - fVar6 * fVar8;
  fVar13 = fVar3 * fVar8 - fVar2 * fVar9;
  fVar11 = fVar2 * fVar6 - fVar3 * fVar5;
  fVar10 = fVar13 * fVar4 + fVar12 * fVar1 + fVar11 * fVar7;
  if (fVar10 == 0.0) {
    return;
  }
  fVar10 = 1.0 / fVar10;
  *(float *)this = fVar10 * fVar12;
  *(float *)((int)this + 0xc) = fVar10 * (fVar7 * fVar6 - fVar4 * fVar9);
  *(float *)((int)this + 0x18) = fVar10 * (fVar4 * fVar8 - fVar7 * fVar5);
  *(float *)((int)this + 4) = fVar13 * fVar10;
  *(float *)((int)this + 0x10) = fVar10 * (fVar1 * fVar9 - fVar3 * fVar7);
  *(float *)((int)this + 0x1c) = fVar10 * (fVar2 * fVar7 - fVar1 * fVar8);
  *(float *)((int)this + 8) = fVar10 * fVar11;
  *(float *)((int)this + 0x14) = fVar10 * (fVar3 * fVar4 - fVar1 * fVar6);
  *(float *)((int)this + 0x20) = fVar10 * (fVar1 * fVar5 - fVar2 * fVar4);
  return;
}
}

// =================================================
// Function: GmMat3::IsIndirect
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall GmMat3::IsIndirect(void *this,GmMat3 *param_1)
{
{
  if (*(float *)((int)this + 0x20) *
      (*(float *)((int)this + 0x10) * *(float *)this -
      *(float *)((int)this + 0xc) * *(float *)((int)this + 4)) +
      *(float *)((int)this + 0x18) *
      (*(float *)((int)this + 0x14) * *(float *)((int)this + 4) -
      *(float *)((int)this + 0x10) * *(float *)((int)this + 8)) +
      *(float *)((int)this + 0x1c) *
      (*(float *)((int)this + 8) * *(float *)((int)this + 0xc) -
      *(float *)((int)this + 0x14) * *(float *)this) < _DAT_00c418e0) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmMat3::IsNearlyEqual
// =================================================
ulong __thiscall GmMat3::IsNearlyEqual(void *this,GmVec2 *param_1,GmVec2 *param_2)
{
{
  ulong uVar1;
  GmVec2 *unaff_ESI;
  GmVec2 *unaff_EDI;
  GmVec2 *unaff_retaddr;
  
  uVar1 = GmVec3::IsNearlyEqual(this,param_1,unaff_EDI);
  if (uVar1 != 0) {
    uVar1 = GmVec3::IsNearlyEqual((void *)((int)this + 0xc),param_1 + 0xc,unaff_ESI);
    if (uVar1 != 0) {
      uVar1 = GmVec3::IsNearlyEqual((void *)((int)this + 0x18),param_1 + 0x18,unaff_retaddr);
      if (uVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}
}

// =================================================
// Function: GmMat3::IsOrthogonal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall GmMat3::IsOrthogonal(void *this,GmMat3 *param_1)
{
{
  if (((ABS(*(float *)((int)this + 0x14) * *(float *)((int)this + 8) +
            *(float *)((int)this + 0xc) * *(float *)this +
            *(float *)((int)this + 0x10) * *(float *)((int)this + 4)) < _DAT_00b37b60) &&
      (ABS(*(float *)((int)this + 0x20) * *(float *)((int)this + 8) +
           *(float *)((int)this + 0x18) * *(float *)this +
           *(float *)((int)this + 0x1c) * *(float *)((int)this + 4)) < _DAT_00b37b60)) &&
     (ABS(*(float *)((int)this + 0x20) * *(float *)((int)this + 0x14) +
          *(float *)((int)this + 0xc) * *(float *)((int)this + 0x18) +
          *(float *)((int)this + 0x1c) * *(float *)((int)this + 0x10)) < _DAT_00b37b60)) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmMat3::IsOrthonormal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall GmMat3::IsOrthonormal(void *this,GmMat3 *param_1)
{
{
  ulong uVar1;
  GmMat3 *unaff_ESI;
  float10 fVar2;
  
  fVar2 = (float10)func_0x009c1b40();
  if (ABS((float)fVar2 - (float)_DAT_00b2c188) < _DAT_00b37b60) {
    fVar2 = (float10)func_0x009c1b40();
    if (ABS((float)fVar2 - (float)_DAT_00b2c188) < _DAT_00b37b60) {
      fVar2 = (float10)func_0x009c1b40();
      if (ABS((float)fVar2 - (float)_DAT_00b2c188) < _DAT_00b37b60) {
        uVar1 = IsOrthogonal(this,unaff_ESI);
        if (uVar1 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}
}

// =================================================
// Function: GmMat3::LeftMult
// =================================================
void __thiscall GmMat3::LeftMult(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2)
{
{
  SPlugFaceCull *extraout_ECX;
  void *this_00;
  int in_stack_ffffffdc;
  GmIso4 *in_stack_ffffffe0;
  
  Set(&stack0xffffffdc,this,in_stack_ffffffdc);
  SetMult(this_00,(SPlugFaceCull *)param_2,extraout_ECX,in_stack_ffffffe0);
  return;
}
}

// =================================================
// Function: GmMat3::Mult
// =================================================
void __thiscall GmMat3::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float local_24 [4];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar1 = *(float *)param_1;
  pfVar3 = this;
  pfVar4 = local_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  *(float *)this =
       local_24[0] * fVar1 + local_24[3] * *(float *)(param_1 + 4) +
       local_c * *(float *)(param_1 + 8);
  *(float *)((int)this + 4) =
       *(float *)(param_1 + 8) * local_8 +
       local_24[1] * *(float *)param_1 + local_14 * *(float *)(param_1 + 4);
  *(float *)((int)this + 8) =
       *(float *)(param_1 + 8) * local_4 +
       *(float *)(param_1 + 4) * local_10 + *(float *)param_1 * local_24[2];
  *(float *)((int)this + 0xc) =
       *(float *)(param_1 + 0x14) * local_c +
       local_24[0] * *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x10) * local_24[3];
  *(float *)((int)this + 0x10) =
       *(float *)(param_1 + 0x14) * local_8 +
       *(float *)(param_1 + 0xc) * local_24[1] + *(float *)(param_1 + 0x10) * local_14;
  *(float *)((int)this + 0x14) =
       *(float *)(param_1 + 0x14) * local_4 +
       *(float *)(param_1 + 0xc) * local_24[2] + *(float *)(param_1 + 0x10) * local_10;
  *(float *)((int)this + 0x18) =
       *(float *)(param_1 + 0x1c) * local_24[3] + *(float *)(param_1 + 0x18) * local_24[0] +
       *(float *)(param_1 + 0x20) * local_c;
  *(float *)((int)this + 0x1c) =
       *(float *)(param_1 + 0x20) * local_8 +
       local_14 * *(float *)(param_1 + 0x1c) + *(float *)(param_1 + 0x18) * local_24[1];
  *(float *)((int)this + 0x20) =
       *(float *)(param_1 + 0x20) * local_4 +
       *(float *)(param_1 + 0x18) * local_24[2] + *(float *)(param_1 + 0x1c) * local_10;
  return;
}
}

// =================================================
// Function: GmMat3::MultTranspose
// =================================================
void __thiscall GmMat3::MultTranspose(void *this,GmMat3 *param_1,GmMat3 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  
  fVar1 = *(float *)this;
  fVar2 = *(float *)((int)this + 0xc);
  fVar3 = *(float *)((int)this + 0x18);
  fVar4 = *(float *)((int)this + 4);
  fVar5 = *(float *)((int)this + 0x10);
  fVar6 = *(float *)((int)this + 0x1c);
  fVar7 = *(float *)((int)this + 8);
  fVar8 = *(float *)((int)this + 0x14);
  fVar9 = *(float *)((int)this + 0x20);
  fVar10 = *(float *)param_1;
  fVar11 = *(float *)(param_1 + 0xc);
  fVar12 = *(float *)(param_1 + 0x18);
  fVar13 = *(float *)(param_1 + 4);
  fVar14 = *(float *)(param_1 + 0x10);
  fVar15 = *(float *)(param_1 + 0x1c);
  fVar16 = *(float *)(param_1 + 8);
  fVar17 = *(float *)(param_1 + 0x14);
  fVar18 = *(float *)(param_1 + 0x20);
  *(float *)this = fVar12 * fVar3 + fVar2 * fVar11 + fVar1 * fVar10;
  *(float *)((int)this + 4) = fVar12 * fVar6 + fVar10 * fVar4 + fVar11 * fVar5;
  *(float *)((int)this + 8) = fVar8 * fVar11 + fVar7 * fVar10 + fVar9 * fVar12;
  *(float *)((int)this + 0xc) = fVar15 * fVar3 + fVar13 * fVar1 + fVar14 * fVar2;
  *(float *)((int)this + 0x10) = fVar15 * fVar6 + fVar13 * fVar4 + fVar14 * fVar5;
  *(float *)((int)this + 0x14) = fVar15 * fVar9 + fVar13 * fVar7 + fVar14 * fVar8;
  *(float *)((int)this + 0x18) = fVar18 * fVar3 + fVar17 * fVar2 + fVar16 * fVar1;
  *(float *)((int)this + 0x1c) = fVar18 * fVar6 + fVar16 * fVar4 + fVar17 * fVar5;
  *(float *)((int)this + 0x20) = fVar9 * fVar18 + fVar8 * fVar17 + fVar16 * fVar7;
  return;
}
}

// =================================================
// Function: GmMat3::OrthoNormalize
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmMat3::OrthoNormalize(void *this,GmMat3 *param_1)
{
{
  float fVar1;
  float10 fVar2;
  
  if (_DAT_00d1a840 <
      *(float *)((int)this + 8) * *(float *)((int)this + 8) +
      *(float *)this * *(float *)this + *(float *)((int)this + 4) * *(float *)((int)this + 4)) {
    fVar2 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar2;
    *(float *)this = fVar1 * *(float *)this;
    *(float *)((int)this + 4) = fVar1 * *(float *)((int)this + 4);
    *(float *)((int)this + 8) = fVar1 * *(float *)((int)this + 8);
  }
  *(float *)((int)this + 0x18) =
       *(float *)((int)this + 0x14) * *(float *)((int)this + 4) -
       *(float *)((int)this + 8) * *(float *)((int)this + 0x10);
  *(float *)((int)this + 0x1c) =
       *(float *)((int)this + 0xc) * *(float *)((int)this + 8) -
       *(float *)((int)this + 0x14) * *(float *)this;
  *(float *)((int)this + 0x20) =
       *(float *)this * *(float *)((int)this + 0x10) -
       *(float *)((int)this + 0xc) * *(float *)((int)this + 4);
  if (_DAT_00d1a840 <
      *(float *)((int)this + 0x20) * *(float *)((int)this + 0x20) +
      *(float *)((int)this + 0x18) * *(float *)((int)this + 0x18) +
      *(float *)((int)this + 0x1c) * *(float *)((int)this + 0x1c)) {
    fVar2 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar2;
    *(float *)((int)this + 0x18) = fVar1 * *(float *)((int)this + 0x18);
    *(float *)((int)this + 0x1c) = *(float *)((int)this + 0x1c) * fVar1;
    *(float *)((int)this + 0x20) = fVar1 * *(float *)((int)this + 0x20);
  }
  *(float *)((int)this + 0xc) =
       *(float *)((int)this + 0x1c) * *(float *)((int)this + 8) -
       *(float *)((int)this + 0x20) * *(float *)((int)this + 4);
  *(float *)((int)this + 0x10) =
       *(float *)this * *(float *)((int)this + 0x20) -
       *(float *)((int)this + 8) * *(float *)((int)this + 0x18);
  *(float *)((int)this + 0x14) =
       *(float *)((int)this + 0x18) * *(float *)((int)this + 4) -
       *(float *)((int)this + 0x1c) * *(float *)this;
  return;
}
}

// =================================================
// Function: GmMat3::RotateX
// =================================================
void __thiscall GmMat3::RotateX(void *this,GmIso4 *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  __CIsin();
  fVar1 = (float)extraout_ST0;
  __CIcos();
  fVar2 = (float)extraout_ST0_00;
  fVar4 = -fVar1;
  fVar3 = *(float *)((int)this + 0xc);
  *(float *)((int)this + 0xc) = fVar4 * *(float *)((int)this + 0x18) + fVar2 * fVar3;
  *(float *)((int)this + 0x18) = *(float *)((int)this + 0x18) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)((int)this + 0x10);
  *(float *)((int)this + 0x10) = fVar3 * fVar2 + *(float *)((int)this + 0x1c) * fVar4;
  *(float *)((int)this + 0x1c) = *(float *)((int)this + 0x1c) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)((int)this + 0x14);
  *(float *)((int)this + 0x14) = fVar3 * fVar2 + fVar4 * *(float *)((int)this + 0x20);
  *(float *)((int)this + 0x20) = *(float *)((int)this + 0x20) * fVar2 + fVar3 * fVar1;
  return;
}
}

// =================================================
// Function: GmMat3::RotateY
// =================================================
void __thiscall GmMat3::RotateY(void *this,GmIso4 *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  __CIsin();
  fVar1 = (float)extraout_ST0;
  __CIcos();
  fVar2 = (float)extraout_ST0_00;
  fVar4 = -fVar1;
  fVar3 = *(float *)this;
  *(float *)this = *(float *)((int)this + 0x18) * fVar1 + fVar2 * fVar3;
  *(float *)((int)this + 0x18) = *(float *)((int)this + 0x18) * fVar2 + fVar4 * fVar3;
  fVar3 = *(float *)((int)this + 4);
  *(float *)((int)this + 4) = fVar3 * fVar2 + *(float *)((int)this + 0x1c) * fVar1;
  *(float *)((int)this + 0x1c) = *(float *)((int)this + 0x1c) * fVar2 + fVar4 * fVar3;
  fVar3 = *(float *)((int)this + 8);
  *(float *)((int)this + 8) = fVar3 * fVar2 + *(float *)((int)this + 0x20) * fVar1;
  *(float *)((int)this + 0x20) = *(float *)((int)this + 0x20) * fVar2 + fVar4 * fVar3;
  return;
}
}

// =================================================
// Function: GmMat3::RotateZ
// =================================================
void __thiscall GmMat3::RotateZ(void *this,GmIso4 *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  __CIsin();
  fVar1 = (float)extraout_ST0;
  __CIcos();
  fVar2 = (float)extraout_ST0_00;
  fVar4 = -fVar1;
  fVar3 = *(float *)this;
  *(float *)this = fVar4 * *(float *)((int)this + 0xc) + fVar2 * fVar3;
  *(float *)((int)this + 0xc) = *(float *)((int)this + 0xc) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)((int)this + 4);
  *(float *)((int)this + 4) = fVar3 * fVar2 + *(float *)((int)this + 0x10) * fVar4;
  *(float *)((int)this + 0x10) = *(float *)((int)this + 0x10) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)((int)this + 8);
  *(float *)((int)this + 8) = fVar3 * fVar2 + fVar4 * *(float *)((int)this + 0x14);
  *(float *)((int)this + 0x14) = *(float *)((int)this + 0x14) * fVar2 + fVar3 * fVar1;
  return;
}
}

// =================================================
// Function: GmMat3::Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmMat3::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float in_stack_0000000c;
  float in_stack_00000010;
  
  fVar1 = (float)_DAT_00b33a58;
  fVar3 = in_stack_0000000c * fVar1;
  fVar2 = in_stack_00000010 * fVar1;
  fVar4 = (float)param_2 * fVar1 * (float)param_1;
  *(float *)this = (1.0 - in_stack_0000000c * fVar3) - in_stack_00000010 * fVar2;
  *(float *)((int)this + 0xc) = fVar2 * (float)param_1 + (float)param_2 * fVar3;
  *(float *)((int)this + 0x18) = fVar2 * (float)param_2 - fVar3 * (float)param_1;
  *(float *)((int)this + 4) = (float)param_2 * fVar3 - fVar2 * (float)param_1;
  fVar1 = 1.0 - (float)param_2 * (float)param_2 * fVar1;
  *(float *)((int)this + 0x10) = fVar1 - in_stack_00000010 * fVar2;
  *(float *)((int)this + 0x1c) = fVar4 + in_stack_0000000c * fVar2;
  *(float *)((int)this + 8) = fVar3 * (float)param_1 + fVar2 * (float)param_2;
  *(float *)((int)this + 0x14) = in_stack_0000000c * fVar2 - fVar4;
  *(float *)((int)this + 0x20) = fVar1 - in_stack_0000000c * fVar3;
  return;
}
}

// =================================================
// Function: GmMat3::SetBlend
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmMat3::SetBlend(void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4)
{
{
  ulong uVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 *puVar2;
  float local_30;
  float local_2c;
  GmQuat *local_28;
  float local_24;
  GmQuat *local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined1 local_c [4];
  undefined1 local_8 [8];
  
  GmQuat::Set(&local_30,(CMwCmdScriptVarBool *)param_1,unaff_EDI);
  GmQuat::Set(local_c,(CMwCmdScriptVarBool *)param_3,unaff_ESI);
  puVar2 = local_8;
  GmQuat::SetSlerp(&local_18,local_28,SUB41(local_24,0),local_20,local_1c);
  if ((((ABS(local_2c - local_1c) < _DAT_00bbd770) &&
       (ABS((float)local_28 - local_18) < _DAT_00bbd770)) &&
      (ABS(local_24 - local_14) < _DAT_00bbd770)) &&
     (uVar1 = GmFunc::AreNearlyEqual(local_30,(float)local_20,_DAT_00bbd770), uVar1 != 0)) {
    Set(this,(CMwCmdScriptVarBool *)param_1,(int)puVar2);
    return;
  }
  Set(this,(CMwCmdScriptVarBool *)local_20,(int)local_1c);
  return;
}
}

// =================================================
// Function: GmMat3::SetDOV
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmMat3::SetDOV(void *this,GmMat3 *param_1,GmVec3 *param_2,ulong param_3)
{
{
  float fVar1;
  float fVar2;
  void *this_00;
  void *this_01;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  float10 fVar3;
  GmVec3 *pGVar4;
  double local_24;
  float fStack_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = 0.0;
  local_8 = 1.0;
  local_4 = 0.0;
  local_18 = *(float *)(param_1 + 8) - *(float *)(param_1 + 4) * 0.0;
  fVar1 = *(float *)param_1 * 0.0;
  local_14 = fVar1 - *(float *)(param_1 + 8) * 0.0;
  local_10 = *(float *)(param_1 + 4) * 0.0 - *(float *)param_1;
  if (param_2 == (GmVec3 *)0x0) {
    if (_DAT_00d1a840 <= local_10 * local_10 + local_18 * local_18 + local_14 * local_14) {
      SetDOVandUpV(this,param_1,(GmVec3 *)&local_c,unaff_EDI);
      return;
    }
    local_c = 1.0;
    local_8 = 0.0;
    local_4 = 0.0;
    SetDOVandUpV(this,param_1,(GmVec3 *)&local_c,unaff_EDI);
    return;
  }
  fVar2 = *(float *)(param_1 + 8) * 0.0 - *(float *)(param_1 + 4) * 0.0;
  local_1c = *(float *)(param_1 + 4) - fVar1;
  local_24 = (double)local_1c;
  if (local_18 * local_18 + local_14 * local_14 + local_10 * local_10 <=
      local_1c * local_1c +
      fVar2 * fVar2 + (fVar1 - *(float *)(param_1 + 8)) * (fVar1 - *(float *)(param_1 + 8))) {
    pGVar4 = (GmVec3 *)(*(float *)(param_1 + 4) * 0.0 - *(float *)(param_1 + 8) * 0.0);
    fStack_20 = *(float *)(param_1 + 8) - fVar1;
    local_1c = fVar1 - *(float *)(param_1 + 4);
    if (_DAT_00d1a840 < local_1c * local_1c + (float)pGVar4 * (float)pGVar4 + fStack_20 * fStack_20)
    {
      fVar3 = (float10)func_0x009c1b40();
      fVar1 = 1.0 / (float)fVar3;
      pGVar4 = (GmVec3 *)(fVar1 * (float)pGVar4);
      fStack_20 = fStack_20 * fVar1;
      local_1c = fVar1 * local_1c;
    }
    local_14 = *(float *)(param_1 + 4);
    local_18 = *(float *)param_1;
    local_10 = *(float *)(param_1 + 8);
    if (_DAT_00d1a840 < local_18 * local_18 + local_14 * local_14 + local_10 * local_10) {
      fVar3 = (float10)func_0x009c1b40();
      fVar1 = 1.0 / (float)fVar3;
      local_18 = fVar1 * local_18;
      local_14 = local_14 * fVar1;
      local_10 = fVar1 * local_10;
    }
    local_c = fStack_20 * local_10 - local_1c * local_14;
    local_8 = local_18 * local_1c - (float)pGVar4 * local_10;
    local_4 = (float)pGVar4 * local_14 - local_18 * fStack_20;
    SetLine(this,(GmMat3 *)0x0,(ulong)&local_c,unaff_EDI);
    SetLine(this_00,(GmMat3 *)0x1,(ulong)&fStack_20,unaff_ESI);
    SetLine(this_01,(GmMat3 *)0x2,(ulong)&local_10,pGVar4);
    return;
  }
  SetDOVandUpV(this,param_1,(GmVec3 *)&local_c,unaff_EDI);
  return;
}
}

// =================================================
// Function: GmMat3::SetDOVInverse
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall GmMat3::SetDOVInverse(void *this,GmMat3 *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  float10 fVar2;
  
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 8);
  if (*(float *)((int)this + 0x20) * *(float *)((int)this + 0x20) +
      *(float *)((int)this + 0x18) * *(float *)((int)this + 0x18) +
      *(float *)((int)this + 0x1c) * *(float *)((int)this + 0x1c) <= _DAT_00d1a840) {
    return 0;
  }
  fVar2 = (float10)func_0x009c1b40();
  fVar1 = 1.0 / (float)fVar2;
  *(float *)((int)this + 0x18) = fVar1 * *(float *)((int)this + 0x18);
  *(float *)((int)this + 0x1c) = *(float *)((int)this + 0x1c) * fVar1;
  *(float *)((int)this + 0x20) = fVar1 * *(float *)((int)this + 0x20);
  *(float *)this = *(float *)((int)this + 0x20) - *(float *)((int)this + 0x1c) * 0.0;
  *(float *)((int)this + 4) =
       *(float *)((int)this + 0x18) * 0.0 - *(float *)((int)this + 0x20) * 0.0;
  fVar1 = *(float *)((int)this + 0x1c) * 0.0 - *(float *)((int)this + 0x18);
  *(float *)((int)this + 8) = fVar1;
  fVar2 = (float10)func_0x009c1b40();
  if ((float)fVar2 < _DAT_00bbd770) {
    *(float *)((int)this + 0xc) =
         *(float *)((int)this + 0x1c) * 0.0 - *(float *)((int)this + 0x20) * 0.0;
    *(float *)((int)this + 0x10) = *(float *)((int)this + 0x20) - *(float *)((int)this + 0x18) * 0.0
    ;
    *(float *)((int)this + 0x14) = *(float *)((int)this + 0x18) * 0.0 - *(float *)((int)this + 0x1c)
    ;
    *(float *)this =
         *(float *)((int)this + 0x10) * *(float *)((int)this + 0x20) -
         *(float *)((int)this + 0x14) * *(float *)((int)this + 0x1c);
    *(float *)((int)this + 4) =
         *(float *)((int)this + 0x18) * *(float *)((int)this + 0x14) -
         *(float *)((int)this + 0x20) * *(float *)((int)this + 0xc);
    fVar1 = *(float *)((int)this + 0xc) * *(float *)((int)this + 0x1c) -
            *(float *)((int)this + 0x10) * *(float *)((int)this + 0x18);
    *(float *)((int)this + 8) = fVar1;
    if (_DAT_00d1a840 <
        *(float *)this * *(float *)this + *(float *)((int)this + 4) * *(float *)((int)this + 4) +
        fVar1 * fVar1) {
      fVar2 = (float10)func_0x009c1b40();
      fVar1 = 1.0 / (float)fVar2;
      *(float *)this = fVar1 * *(float *)this;
      *(float *)((int)this + 4) = *(float *)((int)this + 4) * fVar1;
      *(float *)((int)this + 8) = fVar1 * *(float *)((int)this + 8);
    }
    *(float *)((int)this + 0xc) =
         *(float *)((int)this + 8) * *(float *)((int)this + 0x1c) -
         *(float *)((int)this + 4) * *(float *)((int)this + 0x20);
    *(float *)((int)this + 0x10) =
         *(float *)((int)this + 0x20) * *(float *)this -
         *(float *)((int)this + 0x18) * *(float *)((int)this + 8);
    *(float *)((int)this + 0x14) =
         *(float *)((int)this + 4) * *(float *)((int)this + 0x18) -
         *(float *)this * *(float *)((int)this + 0x1c);
    return 1;
  }
  *(float *)((int)this + 0xc) =
       *(float *)((int)this + 0x1c) * fVar1 -
       *(float *)((int)this + 0x20) * *(float *)((int)this + 4);
  *(float *)((int)this + 0x10) =
       *(float *)((int)this + 0x20) * *(float *)this -
       *(float *)((int)this + 0x18) * *(float *)((int)this + 8);
  *(float *)((int)this + 0x14) =
       *(float *)((int)this + 0x18) * *(float *)((int)this + 4) -
       *(float *)((int)this + 0x1c) * *(float *)this;
  if (_DAT_00d1a840 <
      *(float *)((int)this + 0x14) * *(float *)((int)this + 0x14) +
      *(float *)((int)this + 0xc) * *(float *)((int)this + 0xc) +
      *(float *)((int)this + 0x10) * *(float *)((int)this + 0x10)) {
    fVar2 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar2;
    *(float *)((int)this + 0xc) = fVar1 * *(float *)((int)this + 0xc);
    *(float *)((int)this + 0x10) = *(float *)((int)this + 0x10) * fVar1;
    *(float *)((int)this + 0x14) = fVar1 * *(float *)((int)this + 0x14);
  }
  *(float *)this =
       *(float *)((int)this + 0x10) * *(float *)((int)this + 0x20) -
       *(float *)((int)this + 0x14) * *(float *)((int)this + 0x1c);
  *(float *)((int)this + 4) =
       *(float *)((int)this + 0x14) * *(float *)((int)this + 0x18) -
       *(float *)((int)this + 0x20) * *(float *)((int)this + 0xc);
  *(float *)((int)this + 8) =
       *(float *)((int)this + 0x1c) * *(float *)((int)this + 0xc) -
       *(float *)((int)this + 0x10) * *(float *)((int)this + 0x18);
  return 1;
}
}

// =================================================
// Function: GmMat3::SetDOVandLeftV
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmMat3::SetDOVandLeftV(void *this,GmMat3 *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  float fVar1;
  void *this_00;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  float10 fVar2;
  GmVec3 *pGVar3;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pGVar3 = (GmVec3 *)
           (*(float *)(param_1 + 4) * *(float *)(param_2 + 8) -
           *(float *)(param_1 + 8) * *(float *)(param_2 + 4));
  local_20 = *(float *)(param_1 + 8) * *(float *)param_2 -
             *(float *)param_1 * *(float *)(param_2 + 8);
  local_1c = *(float *)param_1 * *(float *)(param_2 + 4) -
             *(float *)param_2 * *(float *)(param_1 + 4);
  if (_DAT_00d1a840 < local_1c * local_1c + (float)pGVar3 * (float)pGVar3 + local_20 * local_20) {
    fVar2 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar2;
    pGVar3 = (GmVec3 *)(fVar1 * (float)pGVar3);
    local_20 = local_20 * fVar1;
    local_1c = fVar1 * local_1c;
  }
  local_18 = *(float *)param_1;
  local_14 = *(float *)(param_1 + 4);
  local_10 = *(float *)(param_1 + 8);
  if (_DAT_00d1a840 < local_14 * local_14 + local_18 * local_18 + local_10 * local_10) {
    fVar2 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar2;
    local_18 = fVar1 * local_18;
    local_14 = fVar1 * local_14;
    local_10 = fVar1 * local_10;
  }
  fStack_c = local_20 * local_10 - local_1c * local_14;
  fStack_8 = local_18 * local_1c - (float)pGVar3 * local_10;
  fStack_4 = (float)pGVar3 * local_14 - local_20 * local_18;
  SetLine(this,(GmMat3 *)0x0,(ulong)&fStack_c,unaff_EDI);
  SetLine(this,(GmMat3 *)0x1,(ulong)&local_20,unaff_ESI);
  SetLine(this_00,(GmMat3 *)0x2,(ulong)&local_10,pGVar3);
  return;
}
}

// =================================================
// Function: GmMat3::SetDOVandUpV
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmMat3::SetDOVandUpV(void *this,GmMat3 *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  void *this_00;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  float10 fVar4;
  GmVec3 *pGVar5;
  float local_20;
  float local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pGVar5 = (GmVec3 *)
           (*(float *)(param_1 + 8) * *(float *)(param_2 + 4) -
           *(float *)(param_1 + 4) * *(float *)(param_2 + 8));
  local_20 = *(float *)param_1 * *(float *)(param_2 + 8) -
             *(float *)param_2 * *(float *)(param_1 + 8);
  local_1c = *(float *)(param_1 + 4) * *(float *)param_2 -
             *(float *)param_1 * *(float *)(param_2 + 4);
  if (_DAT_00d1a840 < local_1c * local_1c + (float)pGVar5 * (float)pGVar5 + local_20 * local_20) {
    fVar4 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar4;
    pGVar5 = (GmVec3 *)(fVar1 * (float)pGVar5);
    local_20 = local_20 * fVar1;
    local_1c = fVar1 * local_1c;
  }
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 4);
  local_10 = *(float *)(param_1 + 8);
  if (_DAT_00d1a840 < fVar2 * fVar2 + fVar1 * fVar1 + local_10 * local_10) {
    fVar4 = (float10)func_0x009c1b40();
    fVar3 = 1.0 / (float)fVar4;
    fVar1 = fVar3 * fVar1;
    fVar2 = fVar3 * fVar2;
    local_10 = fVar3 * local_10;
  }
  fStack_c = local_1c * fVar2 - local_20 * local_10;
  fStack_8 = (float)pGVar5 * local_10 - fVar1 * local_1c;
  fStack_4 = local_20 * fVar1 - fVar2 * (float)pGVar5;
  SetLine(this,(GmMat3 *)0x0,(ulong)&stack0xffffffdc,unaff_EDI);
  SetLine(this,(GmMat3 *)0x1,(ulong)&fStack_8,unaff_ESI);
  SetLine(this_00,(GmMat3 *)0x2,(ulong)&local_10,pGVar5);
  return;
}
}

// =================================================
// Function: GmMat3::SetIdentity
// =================================================
void __thiscall GmMat3::SetIdentity(void *this,GmMat43 *param_1)
{
{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x10) = 0x3f800000;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0x3f800000;
  return;
}
}

// =================================================
// Function: GmMat3::SetLine
// =================================================
void __thiscall GmMat3::SetLine(void *this,GmMat3 *param_1,ulong param_2,GmVec3 *param_3)
{
{
  *(undefined4 *)((int)this + (int)param_1 * 4) = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + (int)param_1 * 4 + 0xc) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)((int)this + (int)param_1 * 4 + 0x18) = *(undefined4 *)(param_2 + 8);
  return;
}
}

// =================================================
// Function: GmMat3::SetMult
// =================================================
void __thiscall
GmMat3::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 0xc);
  fVar3 = *(float *)(param_1 + 0x18);
  fVar4 = *(float *)(param_1 + 4);
  fVar5 = *(float *)(param_1 + 0x10);
  fVar6 = *(float *)(param_1 + 0x1c);
  fVar7 = *(float *)(param_1 + 8);
  fVar8 = *(float *)(param_1 + 0x14);
  fVar9 = *(float *)(param_1 + 0x20);
  *(float *)this =
       fVar3 * *(float *)(param_2 + 8) + fVar2 * *(float *)(param_2 + 4) + fVar1 * *(float *)param_2
  ;
  *(float *)((int)this + 4) =
       fVar6 * *(float *)(param_2 + 8) + fVar5 * *(float *)(param_2 + 4) + fVar4 * *(float *)param_2
  ;
  *(float *)((int)this + 8) =
       fVar9 * *(float *)(param_2 + 8) + fVar8 * *(float *)(param_2 + 4) + *(float *)param_2 * fVar7
  ;
  *(float *)((int)this + 0xc) =
       *(float *)(param_2 + 0x14) * fVar3 +
       *(float *)(param_2 + 0xc) * fVar1 + *(float *)(param_2 + 0x10) * fVar2;
  *(float *)((int)this + 0x10) =
       *(float *)(param_2 + 0x14) * fVar6 +
       fVar4 * *(float *)(param_2 + 0xc) + *(float *)(param_2 + 0x10) * fVar5;
  *(float *)((int)this + 0x14) =
       *(float *)(param_2 + 0x14) * fVar9 +
       *(float *)(param_2 + 0xc) * fVar7 + *(float *)(param_2 + 0x10) * fVar8;
  *(float *)((int)this + 0x18) =
       *(float *)(param_2 + 0x1c) * fVar2 + *(float *)(param_2 + 0x18) * fVar1 +
       *(float *)(param_2 + 0x20) * fVar3;
  *(float *)((int)this + 0x1c) =
       *(float *)(param_2 + 0x20) * fVar6 +
       fVar5 * *(float *)(param_2 + 0x1c) + *(float *)(param_2 + 0x18) * fVar4;
  *(float *)((int)this + 0x20) =
       *(float *)(param_2 + 0x20) * fVar9 +
       *(float *)(param_2 + 0x18) * fVar7 + *(float *)(param_2 + 0x1c) * fVar8;
  return;
}
}

// =================================================
// Function: GmMat3::SetRotateQuarterY
// =================================================
void __thiscall GmMat3::SetRotateQuarterY(void *this,GmMat3 *param_1,ulong param_2)
{
{
  undefined4 uVar1;
  float fVar2;
  
  uVar1 = *(undefined4 *)(&DAT_00bbd760 + ((uint)param_1 & 3) * 4);
  fVar2 = *(float *)(&DAT_00bbd760 + ((uint)(param_1 + -1) & 3) * 4);
  *(undefined4 *)this = uVar1;
  *(undefined4 *)((int)this + 4) = 0;
  *(float *)((int)this + 8) = fVar2;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0x3f800000;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(float *)((int)this + 0x18) = -fVar2;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = uVar1;
  return;
}
}

// =================================================
// Function: GmMat3::SetTranspose
// =================================================
void __thiscall GmMat3::SetTranspose(void *this,GmMat2 *param_1,GmMat2 *param_2)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)(param_1 + 0x14);
  return;
}
}

// =================================================
// Function: GmMat3::SetUpVandDOV
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmMat3::SetUpVandDOV(void *this,GmMat3 *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  float fVar1;
  float fVar2;
  void *this_00;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  float10 fVar3;
  GmVec3 *pGVar4;
  float local_20;
  float local_1c;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pGVar4 = (GmVec3 *)
           (*(float *)(param_1 + 4) * *(float *)(param_2 + 8) -
           *(float *)(param_1 + 8) * *(float *)(param_2 + 4));
  local_20 = *(float *)(param_1 + 8) * *(float *)param_2 -
             *(float *)param_1 * *(float *)(param_2 + 8);
  local_1c = *(float *)param_1 * *(float *)(param_2 + 4) -
             *(float *)param_2 * *(float *)(param_1 + 4);
  if (_DAT_00d1a840 < local_1c * local_1c + (float)pGVar4 * (float)pGVar4 + local_20 * local_20) {
    fVar3 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar3;
    pGVar4 = (GmVec3 *)(fVar1 * (float)pGVar4);
    local_20 = local_20 * fVar1;
    local_1c = fVar1 * local_1c;
  }
  fVar1 = *(float *)param_1;
  local_14 = *(float *)(param_1 + 4);
  local_10 = *(float *)(param_1 + 8);
  if (_DAT_00d1a840 < local_14 * local_14 + fVar1 * fVar1 + local_10 * local_10) {
    fVar3 = (float10)func_0x009c1b40();
    fVar2 = 1.0 / (float)fVar3;
    fVar1 = fVar2 * fVar1;
    local_14 = fVar2 * local_14;
    local_10 = fVar2 * local_10;
  }
  fStack_c = local_20 * local_10 - local_1c * local_14;
  fStack_8 = fVar1 * local_1c - (float)pGVar4 * local_10;
  fStack_4 = (float)pGVar4 * local_14 - local_20 * fVar1;
  SetLine(this,(GmMat3 *)0x0,(ulong)&stack0xffffffdc,unaff_EDI);
  SetLine(this,(GmMat3 *)0x1,(ulong)&local_14,unaff_ESI);
  SetLine(this_00,(GmMat3 *)0x2,(ulong)&fStack_4,pGVar4);
  return;
}
}

// =================================================
// Function: GmMat3::Transpose
// =================================================
void __thiscall GmMat3::Transpose(void *this,GmMat4 *param_1)
{
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)((int)this + 0xc);
  *(undefined4 *)((int)this + 0xc) = uVar1;
  uVar1 = *(undefined4 *)((int)this + 8);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 0x18);
  *(undefined4 *)((int)this + 0x18) = uVar1;
  uVar1 = *(undefined4 *)((int)this + 0x14);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 0x1c);
  *(undefined4 *)((int)this + 0x1c) = uVar1;
  return;
}
}

