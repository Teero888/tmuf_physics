// Class implementation: GmMat4

// =================================================
// Function: GmMat4::ArchiveGmMat4
// =================================================
void __thiscall GmMat4::ArchiveGmMat4(void *this,GmMat4 *param_1,CClassicArchive *param_2)
{
{
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  ulong in_stack_0000000c;
  ulong in_stack_00000010;
  ulong in_stack_00000014;
  ulong in_stack_00000018;
  ulong in_stack_0000001c;
  ulong in_stack_00000020;
  ulong in_stack_00000024;
  ulong in_stack_00000028;
  ulong in_stack_0000002c;
  ulong in_stack_00000030;
  
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
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x24),(float *)0x1,
             in_stack_00000018);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x28),(float *)0x1,
             in_stack_0000001c);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x2c),(float *)0x1,
             in_stack_00000020);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x30),(float *)0x1,
             in_stack_00000024);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x34),(float *)0x1,
             in_stack_00000028);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x38),(float *)0x1,
             in_stack_0000002c);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x3c),(float *)0x1,
             in_stack_00000030);
  return;
}
}

// =================================================
// Function: GmMat4::Mult
// =================================================
void __thiscall GmMat4::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
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
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  
  fVar1 = *(float *)this;
  fVar2 = *(float *)((int)this + 0x10);
  fVar3 = *(float *)((int)this + 0x20);
  fVar4 = *(float *)((int)this + 0x30);
  fVar5 = *(float *)((int)this + 4);
  fVar6 = *(float *)((int)this + 0x14);
  fVar7 = *(float *)((int)this + 0x24);
  fVar8 = *(float *)((int)this + 0x34);
  fVar9 = *(float *)((int)this + 8);
  fVar10 = *(float *)((int)this + 0x18);
  fVar11 = *(float *)((int)this + 0x28);
  fVar12 = *(float *)((int)this + 0x38);
  fVar13 = *(float *)((int)this + 0xc);
  fVar14 = *(float *)((int)this + 0x1c);
  fVar15 = *(float *)((int)this + 0x2c);
  fVar16 = *(float *)((int)this + 0x3c);
  fVar17 = *(float *)param_1;
  fVar18 = *(float *)(param_1 + 4);
  fVar19 = *(float *)(param_1 + 8);
  fVar20 = *(float *)(param_1 + 0x24);
  fVar21 = *(float *)param_1;
  fVar22 = *(float *)(param_1 + 4);
  fVar23 = *(float *)(param_1 + 8);
  fVar24 = *(float *)(param_1 + 0x24);
  fVar25 = *(float *)param_1;
  fVar26 = *(float *)(param_1 + 4);
  fVar27 = *(float *)(param_1 + 8);
  fVar28 = *(float *)(param_1 + 0x24);
  *(float *)this =
       *(float *)(param_1 + 8) * fVar3 + *(float *)(param_1 + 4) * fVar2 + *(float *)param_1 * fVar1
       + fVar4 * *(float *)(param_1 + 0x24);
  *(float *)((int)this + 4) = fVar19 * fVar7 + fVar18 * fVar6 + fVar5 * fVar17 + fVar8 * fVar20;
  *(float *)((int)this + 8) = fVar23 * fVar11 + fVar22 * fVar10 + fVar21 * fVar9 + fVar12 * fVar24;
  *(float *)((int)this + 0xc) =
       fVar27 * fVar15 + fVar26 * fVar14 + fVar25 * fVar13 + fVar16 * fVar28;
  fVar17 = *(float *)(param_1 + 0xc);
  fVar18 = *(float *)(param_1 + 0x10);
  fVar19 = *(float *)(param_1 + 0x14);
  fVar20 = *(float *)(param_1 + 0x28);
  fVar21 = *(float *)(param_1 + 0xc);
  fVar22 = *(float *)(param_1 + 0x10);
  fVar23 = *(float *)(param_1 + 0x14);
  fVar24 = *(float *)(param_1 + 0x28);
  fVar25 = *(float *)(param_1 + 0xc);
  fVar26 = *(float *)(param_1 + 0x10);
  fVar27 = *(float *)(param_1 + 0x14);
  fVar28 = *(float *)(param_1 + 0x28);
  *(float *)((int)this + 0x10) =
       fVar4 * *(float *)(param_1 + 0x28) +
       *(float *)(param_1 + 0x14) * fVar3 +
       fVar2 * *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0xc) * fVar1;
  *(float *)((int)this + 0x14) = fVar8 * fVar20 + fVar19 * fVar7 + fVar6 * fVar18 + fVar17 * fVar5;
  *(float *)((int)this + 0x18) =
       fVar12 * fVar24 + fVar23 * fVar11 + fVar10 * fVar22 + fVar21 * fVar9;
  *(float *)((int)this + 0x1c) =
       fVar16 * fVar28 + fVar27 * fVar15 + fVar14 * fVar26 + fVar25 * fVar13;
  fVar17 = *(float *)(param_1 + 0x1c);
  fVar18 = *(float *)(param_1 + 0x18);
  fVar19 = *(float *)(param_1 + 0x20);
  fVar20 = *(float *)(param_1 + 0x2c);
  fVar21 = *(float *)(param_1 + 0x1c);
  fVar22 = *(float *)(param_1 + 0x18);
  fVar23 = *(float *)(param_1 + 0x20);
  fVar24 = *(float *)(param_1 + 0x2c);
  fVar25 = *(float *)(param_1 + 0x1c);
  fVar26 = *(float *)(param_1 + 0x18);
  fVar27 = *(float *)(param_1 + 0x20);
  fVar28 = *(float *)(param_1 + 0x2c);
  *(float *)((int)this + 0x20) =
       *(float *)(param_1 + 0x2c) * fVar4 +
       fVar3 * *(float *)(param_1 + 0x20) +
       *(float *)(param_1 + 0x18) * fVar1 + *(float *)(param_1 + 0x1c) * fVar2;
  *(float *)((int)this + 0x24) = fVar20 * fVar8 + fVar7 * fVar19 + fVar17 * fVar6 + fVar18 * fVar5;
  *(float *)((int)this + 0x28) =
       fVar24 * fVar12 + fVar11 * fVar23 + fVar22 * fVar9 + fVar21 * fVar10;
  *(float *)((int)this + 0x2c) =
       fVar28 * fVar16 + fVar15 * fVar27 + fVar26 * fVar13 + fVar25 * fVar14;
  *(float *)((int)this + 0x30) = fVar4;
  *(float *)((int)this + 0x34) = fVar8;
  *(float *)((int)this + 0x38) = fVar12;
  *(float *)((int)this + 0x3c) = fVar16;
  return;
}
}

// =================================================
// Function: GmMat4::Set
// =================================================
void __thiscall GmMat4::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x1c) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)this + 0x2c) = uVar1;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0x3f800000;
  return;
}
}

// =================================================
// Function: GmMat4::SetFrustumProjection
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmMat4::SetFrustumProjection(void *this,GmMat4 *param_1,GmFrustum *param_2,ulong param_3)
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
  float local_20;
  float local_c;
  
  if (*(int *)param_1 != 0) {
    fVar5 = *(float *)(param_1 + 4);
    local_c = (float)_DAT_00b33a58;
    fVar6 = *(float *)(param_1 + 8);
    fVar1 = local_c / (*(float *)(param_1 + 0x10) * local_c);
    if (param_2 == (GmFrustum *)0x0) {
      fVar2 = local_c / (*(float *)(param_1 + 0x18) * local_c);
    }
    else {
      fVar2 = 1.0 / (*(float *)(param_1 + 0x18) * local_c);
    }
    local_c = local_c / (*(float *)(param_1 + 0x14) * local_c);
    local_20 = -fVar2 * *(float *)(param_1 + 0xc);
    if (param_2 != (GmFrustum *)0x0) {
      local_20 = local_20 + (float)_DAT_00b313b8;
    }
    *(float *)this = fVar1;
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 8) = 0;
    *(float *)((int)this + 0xc) = -fVar1 * fVar5;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined4 *)((int)this + 0x18) = 0;
    *(float *)((int)this + 0x14) = local_c;
    *(float *)((int)this + 0x1c) = -local_c * fVar6;
    *(undefined4 *)((int)this + 0x20) = 0;
    *(undefined4 *)((int)this + 0x24) = 0;
    *(float *)((int)this + 0x28) = fVar2;
    *(float *)((int)this + 0x2c) = local_20;
    *(undefined4 *)((int)this + 0x30) = 0;
    *(undefined4 *)((int)this + 0x34) = 0;
    *(undefined4 *)((int)this + 0x38) = 0;
    *(undefined4 *)((int)this + 0x3c) = 0x3f800000;
    return;
  }
  fVar5 = *(float *)(param_1 + 0xc);
  fVar6 = *(float *)(param_1 + 0x18);
  fVar1 = *(float *)(param_1 + 4);
  fVar2 = *(float *)(param_1 + 8);
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_1 + 0x14);
  fVar7 = fVar3 - fVar1;
  fVar9 = fVar4 - fVar2;
  fVar8 = (float)_DAT_00b33a58;
  if (param_2 == (GmFrustum *)0x0) {
    fVar10 = 1.0 / (fVar6 - fVar5);
    param_2 = (GmFrustum *)(fVar10 * (fVar6 + fVar5));
    fVar6 = fVar6 * (float)_DAT_00b36290 * fVar5;
  }
  else {
    param_2 = (GmFrustum *)(fVar6 / (fVar6 - fVar5));
    fVar6 = -(float)param_2;
    fVar10 = fVar5;
  }
  *(float *)this = fVar8 / fVar7;
  *(undefined4 *)((int)this + 4) = 0;
  *(float *)((int)this + 8) = -((fVar3 + fVar1) / fVar7);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(float *)((int)this + 0x14) = fVar8 / fVar9;
  *(float *)((int)this + 0x18) = -((fVar4 + fVar2) / fVar9);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(GmFrustum **)((int)this + 0x28) = param_2;
  *(float *)((int)this + 0x2c) = fVar6 * fVar10;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0x3f800000;
  *(undefined4 *)((int)this + 0x3c) = 0;
  return;
}
}

// =================================================
// Function: GmMat4::SetIdentity
// =================================================
void __thiscall GmMat4::SetIdentity(void *this,GmMat43 *param_1)
{
{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x14) = 0x3f800000;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x28) = 0x3f800000;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0x3f800000;
  return;
}
}

// =================================================
// Function: GmMat4::SetMult
// =================================================
void __thiscall
GmMat4::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  SCasterCat *pSVar1;
  float *extraout_EDX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  GmMat2 *unaff_EDI;
  float *pfVar4;
  undefined1 local_40 [8];
  undefined1 local_38 [56];
  
  SetTranspose(local_40,(GmMat2 *)param_1,unaff_EDI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  do {
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    operator[](param_3,pCVar2,(ulong)unaff_ESI);
    pfVar4 = this;
    do {
      unaff_ESI = pCVar3;
      pSVar1 = operator[](local_38,pCVar3,unaff_EBP);
      pCVar3 = pCVar3 + 1;
      this = pfVar4 + 1;
      *pfVar4 = *(float *)(pSVar1 + 0xc) * extraout_EDX[3] +
                *(float *)(pSVar1 + 8) * extraout_EDX[2] +
                *extraout_EDX * *(float *)pSVar1 + *(float *)(pSVar1 + 4) * extraout_EDX[1];
      pfVar4 = this;
    } while (pCVar3 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004);
    pCVar2 = pCVar2 + 1;
  } while (pCVar2 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004);
  return;
}
}

// =================================================
// Function: GmMat4::SetShadowPlaneProjection
// =================================================
void __thiscall
GmMat4::SetShadowPlaneProjection(void *this,GmMat4 *param_1,GmVec4 *param_2,GmVec4 *param_3)
{
{
  float fVar1;
  float fVar2;
  
  fVar2 = -(*(float *)(param_1 + 0xc) * *(float *)(param_2 + 0xc) +
           *(float *)(param_1 + 8) * *(float *)(param_2 + 8) +
           *(float *)(param_1 + 4) * *(float *)(param_2 + 4) + *(float *)param_1 * *(float *)param_2
           );
  fVar1 = *(float *)param_1;
  *(float *)this = fVar1 * *(float *)param_2;
  *(float *)((int)this + 4) = fVar1 * *(float *)(param_2 + 4);
  *(float *)((int)this + 8) = *(float *)(param_2 + 8) * fVar1;
  *(float *)((int)this + 0xc) = fVar1 * *(float *)(param_2 + 0xc);
  *(float *)this = fVar2 + *(float *)this;
  fVar1 = *(float *)(param_1 + 4);
  *(float *)((int)this + 0x10) = fVar1 * *(float *)param_2;
  *(float *)((int)this + 0x14) = fVar1 * *(float *)(param_2 + 4);
  *(float *)((int)this + 0x18) = *(float *)(param_2 + 8) * fVar1;
  *(float *)((int)this + 0x1c) = fVar1 * *(float *)(param_2 + 0xc);
  *(float *)((int)this + 0x14) = *(float *)((int)this + 0x14) + fVar2;
  fVar1 = *(float *)(param_1 + 8);
  *(float *)((int)this + 0x20) = fVar1 * *(float *)param_2;
  *(float *)((int)this + 0x24) = fVar1 * *(float *)(param_2 + 4);
  *(float *)((int)this + 0x28) = *(float *)(param_2 + 8) * fVar1;
  *(float *)((int)this + 0x2c) = fVar1 * *(float *)(param_2 + 0xc);
  *(float *)((int)this + 0x28) = fVar2 + *(float *)((int)this + 0x28);
  fVar1 = *(float *)(param_1 + 0xc);
  *(float *)((int)this + 0x30) = fVar1 * *(float *)param_2;
  *(float *)((int)this + 0x34) = fVar1 * *(float *)(param_2 + 4);
  *(float *)((int)this + 0x38) = *(float *)(param_2 + 8) * fVar1;
  *(float *)((int)this + 0x3c) = fVar1 * *(float *)(param_2 + 0xc);
  *(float *)((int)this + 0x3c) = fVar2 + *(float *)((int)this + 0x3c);
  return;
}
}

// =================================================
// Function: GmMat4::SetShadowPlaneProjectionDirectional
// =================================================
void __thiscall
GmMat4::SetShadowPlaneProjectionDirectional
          (void *this,GmMat4 *param_1,GmVec3 *param_2,GmVec4 *param_3)
{
{
  SetShadowPlaneProjection(this,(GmMat4 *)&stack0xfffffff0,(GmVec4 *)param_2,*(GmVec4 **)param_1);
  return;
}
}

// =================================================
// Function: GmMat4::SetShadowPlaneProjectionPoint
// =================================================
void __thiscall
GmMat4::SetShadowPlaneProjectionPoint(void *this,GmMat4 *param_1,GmVec3 *param_2,GmVec4 *param_3)
{
{
  SetShadowPlaneProjection(this,(GmMat4 *)&stack0xfffffff0,(GmVec4 *)param_2,*(GmVec4 **)param_1);
  return;
}
}

// =================================================
// Function: GmMat4::SetTranspose
// =================================================
void __thiscall GmMat4::SetTranspose(void *this,GmMat2 *param_1,GmMat2 *param_2)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x30) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)this + 0x34) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)this + 0x38) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)((int)this + 0x3c) = 0x3f800000;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  return;
}
}

// =================================================
// Function: GmMat4::SetTransposeXY
// =================================================
void __thiscall GmMat4::SetTransposeXY(void *this,GmMat4 *param_1,GmIso3 *param_2)
{
{
  undefined4 uVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  pSVar2 = GmVec2::operator[](param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              unaff_EDI);
  *(undefined4 *)this = *(undefined4 *)pSVar2;
  pSVar2 = GmVec2::operator[](param_1 + 8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                              unaff_ESI);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)pSVar2;
  pSVar2 = GmVec2::operator[](param_1 + 8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              unaff_EBX);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)pSVar2;
  pSVar2 = GmVec2::operator[](param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                              unaff_retaddr);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)pSVar2;
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x30) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x34) = uVar1;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0x3f800000;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0x3f800000;
  *(undefined4 *)((int)this + 0x2c) = 0;
  return;
}
}

// =================================================
// Function: GmMat4::SetTransposeXY_TransZ
// =================================================
void __thiscall GmMat4::SetTransposeXY_TransZ(void *this,GmMat4 *param_1,GmIso3 *param_2)
{
{
  undefined4 uVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  pSVar2 = GmVec2::operator[](param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              unaff_EDI);
  *(undefined4 *)this = *(undefined4 *)pSVar2;
  pSVar2 = GmVec2::operator[](param_1 + 8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                              unaff_ESI);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)pSVar2;
  pSVar2 = GmVec2::operator[](param_1 + 8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              unaff_EBX);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)pSVar2;
  pSVar2 = GmVec2::operator[](param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                              unaff_retaddr);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)pSVar2;
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x24) = uVar1;
  *(undefined4 *)((int)this + 0x28) = 0x3f800000;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0x3f800000;
  return;
}
}

// =================================================
// Function: GmMat4::SetXY
// =================================================
void __thiscall GmMat4::SetXY(void *this,GmMat4 *param_1,GmIso3 *param_2)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = uVar1;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = uVar2;
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0x14) = uVar1;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = uVar2;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0x3f800000;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0x3f800000;
  return;
}
}

// =================================================
// Function: GmMat4::Transpose
// =================================================
void __thiscall GmMat4::Transpose(void *this,GmMat4 *param_1)
{
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)((int)this + 0x10);
  *(undefined4 *)((int)this + 0x10) = uVar1;
  uVar1 = *(undefined4 *)((int)this + 8);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 0x20);
  *(undefined4 *)((int)this + 0x20) = uVar1;
  uVar1 = *(undefined4 *)((int)this + 0xc);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 0x30);
  *(undefined4 *)((int)this + 0x30) = uVar1;
  uVar1 = *(undefined4 *)((int)this + 0x18);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)((int)this + 0x24);
  *(undefined4 *)((int)this + 0x24) = uVar1;
  uVar1 = *(undefined4 *)((int)this + 0x1c);
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)((int)this + 0x34);
  *(undefined4 *)((int)this + 0x34) = uVar1;
  uVar1 = *(undefined4 *)((int)this + 0x2c);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)((int)this + 0x38);
  *(undefined4 *)((int)this + 0x38) = uVar1;
  return;
}
}

