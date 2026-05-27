// Class implementation: GmIso4

// =================================================
// Function: GmIso4::ArchiveGmIso4
// =================================================
void __thiscall GmIso4::ArchiveGmIso4(void *this,GmIso4 *param_1,CClassicArchive *param_2)
{
{
  ulong unaff_ESI;
  CClassicArchive *unaff_EDI;
  ulong unaff_retaddr;
  
  GmMat3::ArchiveGmMat3(this,(GmMat3 *)param_1,unaff_EDI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x24),(float *)0x1,unaff_ESI
            );
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x28),(float *)0x1,
             unaff_retaddr);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x2c),(float *)0x1,
             (ulong)param_1);
  return;
}
}

// =================================================
// Function: GmIso4::GetDir
// =================================================
CSystemFidsFolder * __thiscall
GmIso4::GetDir(void *this,CSystemDataFolders *param_1,ulong param_2,ulong param_3)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)((int)this + 0x14);
  uVar2 = *(undefined4 *)((int)this + 0x20);
  *(undefined4 *)param_1 = *(undefined4 *)((int)this + 8);
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 8) = uVar2;
  return (CSystemFidsFolder *)param_1;
}
}

// =================================================
// Function: GmIso4::GetPlaneEq
// =================================================
void __thiscall GmIso4::GetPlaneEq(void *this,GmIso4 *param_1,ulong param_2,GmVec4 *param_3)
{
{
  GmVec3 *unaff_ESI;
  float unaff_retaddr;
  undefined1 local_c [4];
  float local_8;
  float local_4;
  
  GmMat3::GetLine(this,(GmMat3 *)param_1,(ulong)local_c,unaff_ESI);
  *(float *)param_3 = local_8;
  *(float *)(param_3 + 4) = local_4;
  *(float *)(param_3 + 8) = unaff_retaddr;
  *(float *)(param_3 + 0xc) =
       (-local_8 * *(float *)((int)this + 0x24) - *(float *)((int)this + 0x28) * local_4) -
       *(float *)((int)this + 0x2c) * unaff_retaddr;
  return;
}
}

// =================================================
// Function: GmIso4::GetUp
// =================================================
void __thiscall GmIso4::GetUp(void *this,GmIso4 *param_1,GmVec3 *param_2)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)((int)this + 0x10);
  uVar2 = *(undefined4 *)((int)this + 0x1c);
  *(undefined4 *)param_1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 8) = uVar2;
  return;
}
}

// =================================================
// Function: GmIso4::Inverse
// =================================================
void __thiscall GmIso4::Inverse(void *this,GmIso4 *param_1)
{
{
  GmMat4 *unaff_ESI;
  GmIso3 *unaff_retaddr;
  
  GmMat3::Transpose(this,unaff_ESI);
  *(float *)((int)this + 0x24) = -*(float *)((int)this + 0x24);
  *(float *)((int)this + 0x28) = -*(float *)((int)this + 0x28);
  *(float *)((int)this + 0x2c) = -*(float *)((int)this + 0x2c);
  GmVec3::Mult((float *)((int)this + 0x24),this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: GmIso4::IsNearlyEqual
// =================================================
ulong __thiscall GmIso4::IsNearlyEqual(void *this,GmVec2 *param_1,GmVec2 *param_2)
{
{
  ulong uVar1;
  GmVec2 *unaff_ESI;
  GmVec2 *unaff_EDI;
  
  uVar1 = GmVec3::IsNearlyEqual((void *)((int)this + 0x24),param_1 + 0x24,unaff_EDI);
  if (uVar1 != 0) {
    uVar1 = GmMat3::IsNearlyEqual(this,param_1,unaff_ESI);
    if (uVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmIso4::LeftMult
// =================================================
void __thiscall GmIso4::LeftMult(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2)
{
{
  int iVar1;
  undefined4 *puVar2;
  GmIso4 *unaff_EDI;
  SPlugFaceCull *pSVar3;
  SPlugFaceCull local_30 [48];
  
  puVar2 = this;
  pSVar3 = local_30;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pSVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    pSVar3 = pSVar3 + 4;
  }
  SetMult(this,(SPlugFaceCull *)param_1,local_30,unaff_EDI);
  return;
}
}

// =================================================
// Function: GmIso4::Mult
// =================================================
void __thiscall GmIso4::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
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
       local_c * *(float *)(param_1 + 8) +
       local_24[3] * *(float *)(param_1 + 4) + local_24[0] * fVar1;
  *(float *)((int)this + 4) =
       local_8 * *(float *)(param_1 + 8) +
       local_14 * *(float *)(param_1 + 4) + local_24[1] * *(float *)param_1;
  *(float *)((int)this + 8) =
       local_4 * *(float *)(param_1 + 8) +
       local_10 * *(float *)(param_1 + 4) + *(float *)param_1 * local_24[2];
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
  GmVec3::Mult((void *)((int)this + 0x24),param_1,param_2);
  return;
}
}

// =================================================
// Function: GmIso4::MultInverse
// =================================================
void __thiscall GmIso4::MultInverse(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  int iVar1;
  GmIso3 *unaff_ESI;
  float *pfVar2;
  GmIso3 *unaff_EDI;
  float *pfVar3;
  float local_50 [4];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_30 = *(float *)param_1;
  local_20 = *(float *)(param_1 + 0x10);
  local_10 = *(float *)(param_1 + 0x20);
  local_2c = *(float *)(param_1 + 0xc);
  local_24 = *(float *)(param_1 + 4);
  local_28 = *(float *)(param_1 + 0x18);
  local_18 = *(float *)(param_1 + 8);
  local_1c = *(float *)(param_1 + 0x1c);
  local_14 = *(float *)(param_1 + 0x14);
  local_c = -*(float *)(param_1 + 0x24);
  local_8 = -*(float *)(param_1 + 0x28);
  local_4 = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult(&local_c,(GmIso3 *)&local_30,unaff_EDI);
  pfVar2 = this;
  pfVar3 = local_50;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  *(float *)this = local_38 * local_24 + local_28 * local_50[3] + local_2c * local_50[0];
  *(float *)((int)this + 4) = local_34 * local_24 + local_50[1] * local_2c + local_40 * local_28;
  *(float *)((int)this + 8) = local_30 * local_24 + local_3c * local_28 + local_50[2] * local_2c;
  *(float *)((int)this + 0xc) =
       local_38 * local_18 + local_50[3] * local_1c + local_50[0] * local_20;
  *(float *)((int)this + 0x10) = local_34 * local_18 + local_40 * local_1c + local_50[1] * local_20;
  *(float *)((int)this + 0x14) = local_30 * local_18 + local_3c * local_1c + local_50[2] * local_20;
  *(float *)((int)this + 0x18) =
       local_10 * local_50[3] + local_14 * local_50[0] + local_c * local_38;
  *(float *)((int)this + 0x1c) = local_34 * local_c + local_50[1] * local_14 + local_40 * local_10;
  *(float *)((int)this + 0x20) = local_c * local_30 + local_10 * local_3c + local_50[2] * local_14;
  GmVec3::Mult((void *)((int)this + 0x24),(GmIso3 *)&local_2c,unaff_ESI);
  return;
}
}

// =================================================
// Function: GmIso4::NUGetIso4AndScale
// =================================================
void __thiscall
GmIso4::NUGetIso4AndScale(void *this,GmIso4 *param_1,GmIso4 *param_2,GmVec3 *param_3)
{
{
  float fVar1;
  ulong uVar2;
  int iVar3;
  GmMat4 *unaff_EBX;
  GmMat3 *unaff_ESI;
  GmMat4 *unaff_EDI;
  GmIso4 *pGVar4;
  float10 fVar5;
  
  pGVar4 = param_1;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pGVar4 = *(undefined4 *)this;
    this = (undefined4 *)((int)this + 4);
    pGVar4 = pGVar4 + 4;
  }
  GmMat3::Transpose(param_1,unaff_EDI);
  fVar5 = (float10)func_0x009c1b40();
  *(float *)param_3 = (float)fVar5;
  fVar5 = (float10)func_0x009c1b40();
  *(float *)(param_3 + 4) = (float)fVar5;
  fVar5 = (float10)func_0x009c1b40();
  *(float *)(param_3 + 8) = (float)fVar5;
  fVar1 = 1.0 / *(float *)param_3;
  *(float *)param_1 = fVar1 * *(float *)param_1;
  *(float *)(param_1 + 4) = *(float *)(param_1 + 4) * fVar1;
  *(float *)(param_1 + 8) = fVar1 * *(float *)(param_1 + 8);
  fVar1 = 1.0 / *(float *)(param_3 + 4);
  *(float *)(param_1 + 0xc) = fVar1 * *(float *)(param_1 + 0xc);
  *(float *)(param_1 + 0x10) = fVar1 * *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 0x14) = fVar1 * *(float *)(param_1 + 0x14);
  fVar1 = 1.0 / *(float *)(param_3 + 8);
  *(float *)(param_1 + 0x18) = fVar1 * *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) * fVar1;
  *(float *)(param_1 + 0x20) = fVar1 * *(float *)(param_1 + 0x20);
  uVar2 = GmMat3::IsIndirect(param_1,unaff_ESI);
  if (uVar2 != 0) {
    *(float *)param_1 = -*(float *)param_1;
    *(float *)(param_1 + 4) = -*(float *)(param_1 + 4);
    *(float *)(param_1 + 8) = -*(float *)(param_1 + 8);
    *(float *)param_3 = -*(float *)param_3;
  }
  GmMat3::Transpose(param_1,unaff_EBX);
  return;
}
}

// =================================================
// Function: GmIso4::NUScaleSetInverse
// =================================================
void __thiscall GmIso4::NUScaleSetInverse(void *this,GmIso4 *param_1,GmIso4 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  GmIso3 *unaff_ESI;
  GmMat2 *unaff_EDI;
  
  GmMat3::SetTranspose(this,(GmMat2 *)param_1,unaff_EDI);
  fVar1 = 1.0 / (*(float *)((int)this + 8) * *(float *)((int)this + 8) +
                *(float *)this * *(float *)this +
                *(float *)((int)this + 4) * *(float *)((int)this + 4));
  fVar2 = 1.0 / (*(float *)((int)this + 0x14) * *(float *)((int)this + 0x14) +
                *(float *)((int)this + 0xc) * *(float *)((int)this + 0xc) +
                *(float *)((int)this + 0x10) * *(float *)((int)this + 0x10));
  fVar3 = 1.0 / (*(float *)((int)this + 0x20) * *(float *)((int)this + 0x20) +
                *(float *)((int)this + 0x18) * *(float *)((int)this + 0x18) +
                *(float *)((int)this + 0x1c) * *(float *)((int)this + 0x1c));
  *(float *)this = fVar1 * *(float *)this;
  *(float *)((int)this + 4) = fVar1 * *(float *)((int)this + 4);
  *(float *)((int)this + 8) = fVar1 * *(float *)((int)this + 8);
  *(float *)((int)this + 0xc) = fVar2 * *(float *)((int)this + 0xc);
  *(float *)((int)this + 0x10) = *(float *)((int)this + 0x10) * fVar2;
  *(float *)((int)this + 0x14) = fVar2 * *(float *)((int)this + 0x14);
  *(float *)((int)this + 0x18) = fVar3 * *(float *)((int)this + 0x18);
  *(float *)((int)this + 0x1c) = *(float *)((int)this + 0x1c) * fVar3;
  *(float *)((int)this + 0x20) = fVar3 * *(float *)((int)this + 0x20);
  *(float *)((int)this + 0x24) = -*(float *)(param_1 + 0x24);
  *(float *)((int)this + 0x28) = -*(float *)(param_1 + 0x28);
  *(float *)((int)this + 0x2c) = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((float *)((int)this + 0x24),this,unaff_ESI);
  return;
}
}

// =================================================
// Function: GmIso4::RotateX
// =================================================
void __thiscall GmIso4::RotateX(void *this,GmIso4 *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  GmMat3::RotateX(this,param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: GmIso4::RotateY
// =================================================
void __thiscall GmIso4::RotateY(void *this,GmIso4 *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  GmMat3::RotateY(this,param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: GmIso4::RotateZ
// =================================================
void __thiscall GmIso4::RotateZ(void *this,GmIso4 *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  GmMat3::RotateZ(this,param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: GmIso4::Set
// =================================================
void __thiscall GmIso4::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  GmMat3::Set(this,*(CMwCmdScriptVarBool **)param_1,*(int *)(param_1 + 4));
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x18);
  return;
}
}

// =================================================
// Function: GmIso4::SetBlend
// =================================================
void __thiscall
GmIso4::SetBlend(void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float unaff_retaddr;
  
  *(float *)((int)this + 0x24) = *(float *)(param_2 + 0x24) - *(float *)(param_1 + 0x24);
  *(float *)((int)this + 0x28) = *(float *)(param_2 + 0x28) - *(float *)(param_1 + 0x28);
  *(float *)((int)this + 0x2c) = *(float *)(param_2 + 0x2c) - *(float *)(param_1 + 0x2c);
  fVar1 = (float)param_3 * *(float *)((int)this + 0x24);
  *(float *)((int)this + 0x24) = fVar1;
  fVar2 = *(float *)((int)this + 0x28) * (float)param_3;
  *(float *)((int)this + 0x28) = fVar2;
  fVar3 = *(float *)((int)this + 0x2c) * (float)param_3;
  *(float *)((int)this + 0x2c) = fVar3;
  *(float *)((int)this + 0x24) = *(float *)(param_1 + 0x24) + fVar1;
  *(float *)((int)this + 0x28) = fVar2 + *(float *)(param_1 + 0x28);
  *(float *)((int)this + 0x2c) = fVar3 + *(float *)(param_1 + 0x2c);
  GmMat3::SetBlend(this,param_1,param_2,param_3,unaff_retaddr);
  return;
}
}

// =================================================
// Function: GmIso4::SetColumn
// =================================================
void __thiscall GmIso4::SetColumn(void *this,GmIso4 *param_1,ulong param_2,GmVec4 *param_3)
{
{
  *(undefined4 *)((int)this + (int)param_1 * 0xc) = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + (int)param_1 * 0xc + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)((int)this + (int)param_1 * 0xc + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)((int)this + (int)param_1 * 4 + 0x24) = *(undefined4 *)(param_2 + 0xc);
  return;
}
}

// =================================================
// Function: GmIso4::SetIdentity
// =================================================
void __thiscall GmIso4::SetIdentity(void *this,GmMat43 *param_1)
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
// Function: GmIso4::SetInverse
// =================================================
void __thiscall GmIso4::SetInverse(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2)
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
  *(float *)((int)this + 0x24) = -*(float *)(param_1 + 0x24);
  *(float *)((int)this + 0x28) = -*(float *)(param_1 + 0x28);
  *(float *)((int)this + 0x2c) = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((float *)((int)this + 0x24),this,(GmIso3 *)param_2);
  return;
}
}

// =================================================
// Function: GmIso4::SetLookAt
// =================================================
void __thiscall
GmIso4::SetLookAt(void *this,GmIso4 *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4)
{
{
  ulong unaff_EDI;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)param_2 - *(float *)param_1;
  local_8 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_4 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  GmMat3::SetDOV(this,(GmMat3 *)&local_c,param_3,unaff_EDI);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: GmIso4::SetMult
// =================================================
void __thiscall
GmIso4::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
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
  *(float *)((int)this + 0x24) =
       *(float *)(param_1 + 0x2c) * *(float *)(param_2 + 8) +
       *(float *)(param_1 + 0x24) * *(float *)param_2 +
       *(float *)(param_1 + 0x28) * *(float *)(param_2 + 4) + *(float *)(param_2 + 0x24);
  *(float *)((int)this + 0x28) =
       *(float *)(param_2 + 0x14) * *(float *)(param_1 + 0x2c) +
       *(float *)(param_2 + 0xc) * *(float *)(param_1 + 0x24) +
       *(float *)(param_2 + 0x10) * *(float *)(param_1 + 0x28) + *(float *)(param_2 + 0x28);
  *(float *)((int)this + 0x2c) =
       *(float *)(param_2 + 0x20) * *(float *)(param_1 + 0x2c) +
       *(float *)(param_1 + 0x24) * *(float *)(param_2 + 0x18) +
       *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 0x28) + *(float *)(param_2 + 0x2c);
  return;
}
}

// =================================================
// Function: GmIso4::SetNUScaleTrans
// =================================================
void __thiscall GmIso4::SetNUScaleTrans(void *this,GmIso4 *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_2 + 8);
  return;
}
}

// =================================================
// Function: GmIso4::SetRotation
// =================================================
void __thiscall GmIso4::SetRotation(void *this,GmMat2 *param_1,float param_2)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  return;
}
}

// =================================================
// Function: GmIso4::SetTranslation
// =================================================
void __thiscall GmIso4::SetTranslation(void *this,GmIso4 *param_1,GmVec3 *param_2)
{
{
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: GmIso4::SetUScaleTrans
// =================================================
void __thiscall GmIso4::SetUScaleTrans(void *this,GmIso4 *param_1,float param_2,GmVec3 *param_3)
{
{
  *(GmIso4 **)((int)this + 0x20) = param_1;
  *(GmIso4 **)((int)this + 0x10) = param_1;
  *(GmIso4 **)this = param_1;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)((int)param_2 + 4);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)((int)param_2 + 8);
  return;
}
}

// =================================================
// Function: GmIso4::SetXY
// =================================================
void __thiscall GmIso4::SetXY(void *this,GmMat4 *param_1,GmIso3 *param_2)
{
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = uVar1;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0x10) = uVar1;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0x3f800000;
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x28) = uVar1;
  *(undefined4 *)((int)this + 0x2c) = 0;
  return;
}
}

// =================================================
// Function: GmIso4::SymmetryPlane
// =================================================
void __thiscall GmIso4::SymmetryPlane(void *this,GmIso4 *param_1,GmVec4 *param_2)
{
{
  float fVar1;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  GmMat3 *pGVar2;
  float unaff_retaddr;
  undefined1 local_c [4];
  float local_8;
  float local_4;
  
  pGVar2 = (GmMat3 *)0x0;
  do {
    GmMat3::GetLine(this,pGVar2,(ulong)local_c,unaff_EDI);
    unaff_EDI = (GmVec3 *)&local_8;
    fVar1 = local_4 * *(float *)(param_1 + 4) + local_8 * *(float *)param_1 +
            unaff_retaddr * *(float *)(param_1 + 8);
    fVar1 = fVar1 + fVar1;
    local_8 = local_8 - fVar1 * *(float *)param_1;
    local_4 = local_4 - fVar1 * *(float *)(param_1 + 4);
    unaff_retaddr = unaff_retaddr - fVar1 * *(float *)(param_1 + 8);
    GmMat3::SetLine(this,pGVar2,(ulong)unaff_EDI,unaff_ESI);
    pGVar2 = pGVar2 + 1;
  } while (pGVar2 < (GmMat3 *)0x3);
  fVar1 = *(float *)((int)this + 0x2c) * *(float *)(param_1 + 8) +
          *(float *)((int)this + 0x28) * *(float *)(param_1 + 4) +
          *(float *)((int)this + 0x24) * *(float *)param_1 + *(float *)(param_1 + 0xc);
  fVar1 = fVar1 + fVar1;
  *(float *)((int)this + 0x24) = *(float *)((int)this + 0x24) - fVar1 * *(float *)param_1;
  *(float *)((int)this + 0x28) = *(float *)((int)this + 0x28) - fVar1 * *(float *)(param_1 + 4);
  *(float *)((int)this + 0x2c) = *(float *)((int)this + 0x2c) - *(float *)(param_1 + 8) * fVar1;
  return;
}
}

// =================================================
// Function: GmIso4::UScaleSetInverse
// =================================================
void __thiscall GmIso4::UScaleSetInverse(void *this,GmIso4 *param_1,GmIso4 *param_2)
{
{
  GmIso3 *unaff_ESI;
  GmMat2 *unaff_EDI;
  GmIso3 *unaff_retaddr;
  
  GmMat3::SetTranspose(this,(GmMat2 *)param_1,unaff_EDI);
  GmMat3::Mult(this,(GmIso3 *)param_2,unaff_ESI);
  *(float *)((int)this + 0x24) = -*(float *)(param_1 + 0x24);
  *(float *)((int)this + 0x28) = -*(float *)(param_1 + 0x28);
  *(float *)((int)this + 0x2c) = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((float *)((int)this + 0x24),this,unaff_retaddr);
  return;
}
}

