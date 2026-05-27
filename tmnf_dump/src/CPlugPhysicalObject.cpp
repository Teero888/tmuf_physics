// Class implementation: CPlugPhysicalObject

// =================================================
// Function: CPlugPhysicalObject::CPlugPhysicalObject
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CPlugPhysicalObject::CPlugPhysicalObject(void *this,CPlugPhysicalObject *param_1)
{
{
  undefined4 uVar1;
  float unaff_ESI;
  
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)((int)this + 0x28) = _DAT_00b3380c;
  uVar1 = _DAT_00b36144;
  *(undefined4 *)((int)this + 0x2c) = _DAT_00b36144;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x30) = uVar1;
  *(undefined4 *)((int)this + 0x34) = 0x3f800000;
  SetInertiaMatrixSphere(this,(CPlugPhysicalObject *)0x3f800000,unaff_ESI);
  return;
}
}

// =================================================
// Function: CPlugPhysicalObject::ComputeComPos
// =================================================
/* WARNING: Removing unreachable block (ram,0x008a160f) */
/* WARNING: Removing unreachable block (ram,0x008a1627) */
/* WARNING: Removing unreachable block (ram,0x008a1613) */
/* WARNING: Removing unreachable block (ram,0x008a1635) */
/* WARNING: Removing unreachable block (ram,0x008a163b) */
/* WARNING: Removing unreachable block (ram,0x008a1651) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugPhysicalObject::ComputeComPos(void *this,CPlugPhysicalObject *param_1,int param_2)
{
{
  CPlugTree *this_00;
  CPlugSurfaceGeom *this_01;
  CPlugTree *this_02;
  ulong uVar1;
  CPlugTree *unaff_EBX;
  CPlugSurfaceGeom *unaff_EBP;
  CPlugSurfaceGeom *unaff_ESI;
  ulong *unaff_EDI;
  float fVar2;
  float in_stack_0000000c;
  int local_50;
  void *local_4c;
  float local_48;
  int local_44;
  undefined4 local_40;
  float local_38;
  float local_34;
  float local_30;
  CPlugPhysicalObject *local_2c;
  float local_28;
  float local_24;
  
  this_00 = *(CPlugTree **)((int)this + 0x44);
  if (this_00 != (CPlugTree *)0x0) {
    local_40 = 0;
    local_44 = 0;
    local_48 = 0.0;
    local_4c = this;
    local_50 = CSystemFile_testerror(unaff_EBP,(void *)0x0);
    while (local_50 != -1) {
      this_02 = CPlugTree::GetAllTreeNext(this_00,(CPlugTree *)&local_50,unaff_EDI);
      if ((*(int *)(this_02 + 0x8c) != 0) && (((byte)this_02[0x9c] & 0x80) != 0)) {
        this_01 = *(CPlugSurfaceGeom **)(*(int *)(this_02 + 0x8c) + 0x14);
        unaff_EDI = (ulong *)0x8a154b;
        uVar1 = CPlugSurfaceGeom::GetWeightDistribCount(this_01,unaff_ESI);
        if (uVar1 != 0) {
          unaff_ESI = (CPlugSurfaceGeom *)0x0;
          unaff_EDI = (ulong *)0x1;
          CPlugTree::GetThisToRootTransfo(this_02,(CPlugTree *)&local_28,(GmIso4 *)0x1,0,unaff_EBX);
          unaff_EBX = (CPlugTree *)0x8a156a;
          fVar2 = CPlugSurfaceGeom::GetVolume(this_01,unaff_EBP);
          local_2c = param_1;
          local_28 = (float)param_2;
          local_24 = in_stack_0000000c;
          if (param_1 != (CPlugPhysicalObject *)0x0) {
            local_2c = (CPlugPhysicalObject *)(fVar2 * (float)param_1);
            local_28 = fVar2 * (float)param_2;
            local_24 = in_stack_0000000c * fVar2;
          }
          local_44 = local_44 + 1;
          local_38 = (float)local_2c + local_38;
          local_34 = local_28 + local_34;
          local_30 = local_24 + local_30;
          local_48 = fVar2 + local_48;
        }
      }
    }
  }
  return;
}
}

// =================================================
// Function: CPlugPhysicalObject::ComputeComPosAndInertiaMatrix
// =================================================
void __thiscall
CPlugPhysicalObject::ComputeComPosAndInertiaMatrix
          (void *this,CPlugPhysicalObject *param_1,float param_2,int param_3)
{
{
  int unaff_ESI;
  int unaff_EDI;
  
  ComputeComPos(this,(CPlugPhysicalObject *)param_2,unaff_EDI);
  ComputeInertiaMatrix(this,(CPlugPhysicalObject *)param_2,param_2,unaff_ESI);
  return;
}
}

// =================================================
// Function: CPlugPhysicalObject::ComputeInertiaMatrix
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugPhysicalObject::ComputeInertiaMatrix
          (void *this,CPlugPhysicalObject *param_1,float param_2,int param_3)
{
{
  CPlugSurfaceGeom *this_00;
  float fVar1;
  GmIso3 *pGVar2;
  CPlugTree *pCVar3;
  CPlugSurfaceGeom *pCVar4;
  CPlugSurfaceGeom *unaff_EBX;
  CPlugTree *unaff_EBP;
  GmMat43 *unaff_ESI;
  CPlugSurfaceGeom *pCVar5;
  ulong *unaff_EDI;
  CPlugSurfaceGeom *pCVar6;
  GmIso3 *in_stack_ffffff94;
  CPlugTree *pCStack_64;
  undefined1 local_54 [4];
  float local_50;
  CMwCmdScriptVarBool local_4c [4];
  float local_48;
  float local_44;
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
  float local_18 [6];
  
  pCVar3 = *(CPlugTree **)((int)this + 0x44);
  if (pCVar3 != (CPlugTree *)0x0) {
    pCVar6 = (CPlugSurfaceGeom *)0x0;
    GmMat3::SetIdentity(local_54,unaff_ESI);
    pGVar2 = (GmIso3 *)CSystemFile_testerror(unaff_EBX,pCVar6);
    if (pGVar2 != (GmIso3 *)0xffffffff) {
      do {
        pCVar3 = CPlugTree::GetAllTreeNext(pCVar3,(CPlugTree *)&stack0xffffff98,unaff_EDI);
        if ((*(int *)(pCVar3 + 0x8c) != 0) && (((byte)pCVar3[0x9c] & 0x80) != 0)) {
          this_00 = *(CPlugSurfaceGeom **)(*(int *)(pCVar3 + 0x8c) + 0x14);
          unaff_EDI = (ulong *)0x0;
          CPlugTree::GetThisToRootTransfo(pCVar3,(CPlugTree *)&local_28,(GmIso4 *)0x1,0,unaff_EBP);
          unaff_EBP = (CPlugTree *)0x8a1725;
          pCVar4 = (CPlugSurfaceGeom *)CPlugSurfaceGeom::GetWeightDistribCount(this_00,unaff_EBX);
          if (pCVar4 != (CPlugSurfaceGeom *)0x0) {
            unaff_EBX = (CPlugSurfaceGeom *)0x8a1736;
            local_50 = CPlugSurfaceGeom::GetVolume(this_00,pCVar6);
            fVar1 = (float)(int)pCVar4;
            if ((int)pCVar4 < 0) {
              fVar1 = fVar1 + _DAT_00c418d0;
            }
            local_50 = local_50 / fVar1;
            pCVar5 = (CPlugSurfaceGeom *)0x0;
            if (pCVar4 != (CPlugSurfaceGeom *)0x0) {
              do {
                unaff_EBP = (CPlugTree *)0x8a177d;
                unaff_EBX = pCVar5;
                CPlugSurfaceGeom::GetWeightDistrib
                          (this_00,pCVar5,(ulong)local_4c,(GmVec3 *)in_stack_ffffff94);
                in_stack_ffffff94 = (GmIso3 *)local_18;
                pCVar6 = (CPlugSurfaceGeom *)0x8a178b;
                GmVec3::Mult(&local_48,in_stack_ffffff94,pGVar2);
                local_44 = local_44 - *(float *)((int)this + 0x38);
                pCVar5 = pCVar5 + 1;
                local_40 = local_40 - *(float *)((int)this + 0x3c);
                local_3c = local_3c - *(float *)((int)this + 0x40);
                local_38 = local_38 + local_48 * (local_40 * local_40 + local_3c * local_3c);
                local_28 = local_28 + local_48 * (local_44 * local_44 + local_3c * local_3c);
                local_18[0] = local_18[0] + local_48 * (local_44 * local_44 + local_40 * local_40);
                fVar1 = local_44 * local_40 * local_48;
                local_34 = local_34 - fVar1;
                local_2c = local_2c - fVar1;
                fVar1 = local_48 * local_3c * local_44;
                local_30 = local_30 - fVar1;
                local_20 = local_20 - fVar1;
                fVar1 = local_48 * local_40 * local_3c;
                local_24 = local_24 - fVar1;
                local_1c = local_1c - fVar1;
              } while (pCVar5 < pCVar4);
            }
          }
        }
        pCVar3 = pCStack_64;
      } while (pGVar2 != (GmIso3 *)0xffffffff);
      if (_DAT_00bb5c20 <= (float)in_stack_ffffff94) {
        GmMat3::Mult(&local_50,(GmIso3 *)((*(float *)this * param_2) / (float)in_stack_ffffff94),
                     (GmIso3 *)unaff_EBX);
        GmMat3::Set((void *)((int)this + 4),local_4c,(int)pCVar6);
        GmMat3::Inverse((void *)((int)this + 4),(GmIso4 *)in_stack_ffffff94);
        return;
      }
    }
  }
  return;
}
}

// =================================================
// Function: CPlugPhysicalObject::CopyFrom
// =================================================
void __thiscall CPlugPhysicalObject::CopyFrom(void *this,SParam_Set *param_1,SParam *param_2)
{
{
  int unaff_EDI;
  
  *(undefined4 *)this = *(undefined4 *)param_1;
  GmMat3::Set((void *)((int)this + 4),(CMwCmdScriptVarBool *)(param_1 + 4),unaff_EDI);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)((int)this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)((int)this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)((int)this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)((int)this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  return;
}
}

// =================================================
// Function: CPlugPhysicalObject::SetComPos
// =================================================
void __thiscall
CPlugPhysicalObject::SetComPos(void *this,CPlugPhysicalObject *param_1,GmVec3 *param_2)
{
{
  *(undefined4 *)((int)this + 0x38) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0x40) = *(undefined4 *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: CPlugPhysicalObject::SetComPosAndInertiaMatrixFromTreeBoundingBox
// =================================================
void __thiscall
CPlugPhysicalObject::SetComPosAndInertiaMatrixFromTreeBoundingBox
          (void *this,CPlugPhysicalObject *param_1)
{
{
  int iVar1;
  GmVec3 *unaff_retaddr;
  
  if (*(int *)((int)this + 0x44) != 0) {
    iVar1 = *(int *)((int)this + 0x44);
    *(undefined4 *)((int)this + 0x38) = *(undefined4 *)(iVar1 + 0x34);
    *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)(iVar1 + 0x38);
    *(undefined4 *)((int)this + 0x40) = *(undefined4 *)(iVar1 + 0x3c);
    SetInertiaMatrixBox(this,*(CPlugPhysicalObject **)this,
                        (float)(*(int *)((int)this + 0x44) + 0x40),unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CPlugPhysicalObject::SetInertiaMatrixBox
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugPhysicalObject::SetInertiaMatrixBox
          (void *this,CPlugPhysicalObject *param_1,float param_2,GmVec3 *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  GmMat43 *unaff_EDI;
  float unaff_retaddr;
  
  fVar1 = *(float *)param_2 * (float)_DAT_00b33a58;
  fVar2 = *(float *)((int)param_2 + 4) * (float)_DAT_00b33a58;
  GmMat3::SetIdentity((float *)((int)this + 4),unaff_EDI);
  fVar3 = (float)param_3 * (float)_DAT_00b5b9d8;
  fVar2 = fVar2 * fVar2;
  fVar1 = fVar1 * fVar1;
  *(float *)((int)this + 4) = fVar3 / (fVar1 + fVar2);
  *(float *)((int)this + 0x14) = fVar3 / (unaff_retaddr * unaff_retaddr + fVar2);
  *(float *)((int)this + 0x24) = fVar3 / (fVar1 + unaff_retaddr * unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugPhysicalObject::SetInertiaMatrixSphere
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugPhysicalObject::SetInertiaMatrixSphere(void *this,CPlugPhysicalObject *param_1,float param_2)
{
{
  void *this_00;
  GmIso3 *unaff_ESI;
  GmMat43 *unaff_EDI;
  GmIso3 *unaff_retaddr;
  GmIso3 *pGStack0000000c;
  
  this_00 = (void *)((int)this + 4);
  GmMat3::SetIdentity(this_00,unaff_EDI);
  GmMat3::Mult(this_00,(GmIso3 *)
                       ((float)_DAT_00b3d2c0 / ((float)_DAT_00bb5c28 * param_2 * param_2 * param_2))
               ,unaff_ESI);
  pGStack0000000c = (GmIso3 *)(1.0 / *(float *)this);
  GmMat3::Mult(this_00,pGStack0000000c,unaff_retaddr);
  return;
}
}

