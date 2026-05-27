// Class implementation: CPfmCell

// =================================================
// Function: CPfmCell::CPfmCell
// =================================================
void __thiscall CPfmCell::CPfmCell(void *this,CPfmCell *param_1)
{
{
  code *pcVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00aecd28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = CPfmPlane::vftable;
  pcVar1 = GmLine2::GmLine2;
  local_4 = 0;
  _eh_vector_constructor_iterator_
            ((void *)((int)this + 0x50),0x2c,3,GmLine2::GmLine2,GmLine2::~GmLine2);
  *(undefined4 *)((int)this + 0xe4) = 0;
  *(int *)((int)this + 0xe0) = DAT_00d792f0;
  DAT_00d792f0 = DAT_00d792f0 + 1;
  *(undefined4 *)((int)this + 0xf4) = 0xff;
  ExceptionList = pcVar1;
  return;
}
}

// =================================================
// Function: CPfmCell::ComputeCellData
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CPfmCell::ComputeCellData(void *this,CPfmCell *param_1)
{
{
  CMwCmdScriptVarBool *pCVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float10 fVar8;
  float *pfVar9;
  
  pCVar1 = (CMwCmdScriptVarBool *)((int)this + 0x20);
  pfVar2 = (float *)((int)this + 0x2c);
  pfVar3 = (float *)((int)this + 0x38);
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x54) = *(undefined4 *)((int)this + 0x20);
  *(undefined4 *)((int)this + 0x58) = *(undefined4 *)((int)this + 0x28);
  *(float *)((int)this + 0x5c) = *pfVar2;
  *(undefined4 *)((int)this + 0x60) = *(undefined4 *)((int)this + 0x34);
  *(undefined4 *)((int)this + 0xa4) = 0;
  *(float *)((int)this + 0x80) = *pfVar2;
  *(undefined4 *)((int)this + 0x84) = *(undefined4 *)((int)this + 0x34);
  *(float *)((int)this + 0x88) = *pfVar3;
  *(undefined4 *)((int)this + 0x8c) = *(undefined4 *)((int)this + 0x40);
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(float *)((int)this + 0xac) = *pfVar3;
  *(undefined4 *)((int)this + 0xb0) = *(undefined4 *)((int)this + 0x40);
  *(undefined4 *)((int)this + 0xb4) = *(undefined4 *)((int)this + 0x20);
  *(undefined4 *)((int)this + 0xb8) = *(undefined4 *)((int)this + 0x28);
  pfVar9 = pfVar3;
  CPfmPlane::Set(this,pCVar1,(int)pfVar2);
  fVar4 = (float)_DAT_00b3d2c0;
  *(float *)((int)this + 0x44) = (*pfVar3 + *pfVar2 + *(float *)pCVar1) / fVar4;
  fVar7 = *(float *)((int)this + 0x30) + *(float *)((int)this + 0x24);
  *(float *)((int)this + 0x48) = (*(float *)((int)this + 0x3c) + fVar7) / fVar4;
  fVar6 = *(float *)((int)this + 0x34) + *(float *)((int)this + 0x28);
  *(float *)((int)this + 0x4c) = (*(float *)((int)this + 0x40) + fVar6) / fVar4;
  fVar5 = (float)_DAT_00b313b8;
  fVar4 = (*pfVar2 + *(float *)pCVar1) * fVar5;
  *(float *)((int)this + 0x100) = fVar4;
  *(float *)((int)this + 0x104) = fVar7 * fVar5;
  fVar6 = fVar6 * fVar5;
  *(float *)((int)this + 0x108) = fVar6;
  *(float *)((int)this + 0x10c) = (*pfVar2 + *pfVar3) * fVar5;
  *(float *)((int)this + 0x110) =
       (*(float *)((int)this + 0x3c) + *(float *)((int)this + 0x30)) * fVar5;
  *(float *)((int)this + 0x114) =
       (*(float *)((int)this + 0x40) + *(float *)((int)this + 0x34)) * fVar5;
  *(float *)((int)this + 0x118) = (*pfVar3 + *(float *)pCVar1) * fVar5;
  *(float *)((int)this + 0x11c) =
       (*(float *)((int)this + 0x3c) + *(float *)((int)this + 0x24)) * fVar5;
  *(float *)((int)this + 0x120) =
       (*(float *)((int)this + 0x40) + *(float *)((int)this + 0x28)) * fVar5;
  fVar8 = (float10)func_0x009c1b40(pfVar9);
  *(float *)((int)this + 0x124) = (float)fVar8;
  fVar8 = (float10)func_0x009c1b40();
  *(float *)((int)this + 0x128) = (float)fVar8;
  fVar8 = (float10)func_0x009c1b40();
  *(float *)((int)this + 300) = (float)fVar8;
  *(float *)((int)this + 0xf8) = fVar4;
  *(float *)((int)this + 0xfc) = fVar6;
  return;
}
}

// =================================================
// Function: CPfmCell::ForcePointToCellCollumn
// =================================================
int __thiscall CPfmCell::ForcePointToCellCollumn(void *this,CPfmCell *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  GmVec3 *unaff_ESI;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = *(undefined4 *)param_1;
  local_c = *(undefined4 *)(param_1 + 8);
  local_8 = local_10;
  local_4 = local_c;
  iVar1 = ForcePointToCellCollumn(this,(CPfmCell *)&local_10,unaff_ESI);
  if (iVar1 != 0) {
    *(undefined4 *)param_1 = local_c;
    *(undefined4 *)(param_1 + 8) = local_8;
  }
  return iVar1;
}
}

// =================================================
// Function: CPfmCell::Initialize
// =================================================
void __thiscall
CPfmCell::Initialize(void *this,CPfmCell *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4)
{
{
  CPfmCell *unaff_retaddr;
  
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + 0x30) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)((int)this + 0x34) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)((int)this + 0x38) = *(undefined4 *)param_3;
  *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)((int)this + 0x40) = *(undefined4 *)(param_3 + 8);
  *(undefined4 *)((int)this + 0xd4) = 0;
  *(undefined4 *)((int)this + 0xd8) = 0;
  *(undefined4 *)((int)this + 0xdc) = 0;
  ComputeCellData(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPfmCell::RequestLink
// =================================================
int __thiscall
CPfmCell::RequestLink
          (void *this,CPfmCell *param_1,GmVec3 *param_2,GmVec3 *param_3,CPfmCell *param_4)
{
{
  void *this_00;
  ulong uVar1;
  GmVec2 *unaff_EBX;
  GmVec2 *unaff_EBP;
  GmVec2 *unaff_ESI;
  GmVec2 *unaff_EDI;
  GmVec2 *unaff_retaddr;
  GmVec2 *in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  
  this_00 = (void *)((int)this + 0x20);
  uVar1 = GmVec3::IsNearlyEqual(this_00,(GmVec2 *)param_1,unaff_EDI);
  if (uVar1 == 0) {
    uVar1 = GmVec3::IsNearlyEqual((void *)((int)this + 0x2c),(GmVec2 *)param_1,unaff_ESI);
    if (uVar1 == 0) {
      uVar1 = GmVec3::IsNearlyEqual((void *)((int)this + 0x38),(GmVec2 *)param_1,unaff_EBP);
      if (uVar1 != 0) {
        uVar1 = GmVec3::IsNearlyEqual(this_00,in_stack_00000014,unaff_EBX);
        if (uVar1 != 0) goto LAB_00a5ad61;
        uVar1 = GmVec3::IsNearlyEqual((void *)((int)this + 0x2c),in_stack_00000014,unaff_retaddr);
        if (uVar1 != 0) {
          *(undefined4 *)((int)this + 0xd8) = in_stack_00000020;
          return 1;
        }
      }
    }
    else {
      uVar1 = GmVec3::IsNearlyEqual(this_00,(GmVec2 *)param_4,unaff_EBP);
      if (uVar1 != 0) {
        *(undefined4 *)((int)this + 0xd4) = in_stack_00000018;
        return 1;
      }
      uVar1 = GmVec3::IsNearlyEqual((void *)((int)this + 0x38),(GmVec2 *)param_4,unaff_EBX);
      if (uVar1 != 0) {
        *(undefined4 *)((int)this + 0xd8) = in_stack_0000001c;
        return 1;
      }
    }
  }
  else {
    uVar1 = GmVec3::IsNearlyEqual((void *)((int)this + 0x2c),(GmVec2 *)param_3,unaff_ESI);
    if (uVar1 != 0) {
      *(GmVec2 **)((int)this + 0xd4) = in_stack_00000014;
      return 1;
    }
    uVar1 = GmVec3::IsNearlyEqual((void *)((int)this + 0x38),(GmVec2 *)param_3,unaff_EBP);
    if (uVar1 != 0) {
LAB_00a5ad61:
      *(undefined4 *)((int)this + 0xdc) = in_stack_0000001c;
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CPfmCell::~CPfmCell
// =================================================
void __thiscall CPfmCell::~CPfmCell(void *this,CPfmCell *param_1)
{
{
  code *pcVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00aeccf8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pcVar1 = GmLine2::~GmLine2;
  local_4 = 0;
  _eh_vector_destructor_iterator_((void *)((int)this + 0x50),0x2c,3,GmLine2::~GmLine2);
  *(undefined ***)this = CPfmPlane::vftable;
  ExceptionList = pcVar1;
  return;
}
}

