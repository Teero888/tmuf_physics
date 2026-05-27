// Class implementation: CHmsZoneDynamic

// =================================================
// Function: CHmsZoneDynamic::AfterCollisionGroupChange
// =================================================
void __thiscall
CHmsZoneDynamic::AfterCollisionGroupChange
          (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2)
{
{
  CHmsCollisionManager::SZone::AddCorpus(*(void **)(this + 0x168),(SZone *)param_1,param_2);
  return;
}
}

// =================================================
// Function: CHmsZoneDynamic::BeforeCollisionGroupChange
// =================================================
void __thiscall
CHmsZoneDynamic::BeforeCollisionGroupChange
          (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2)
{
{
  CHmsCollisionManager::SZone::RemoveCorpus
            (*(void **)(this + 0x168),(CHmsZoneOverlay *)param_1,param_2);
  return;
}
}

// =================================================
// Function: CHmsZoneDynamic::ComputeCollisionResponse
// =================================================
/* WARNING: Removing unreachable block (ram,0x00549b89) */
/* WARNING: Removing unreachable block (ram,0x00549b9a) */
/* WARNING: Removing unreachable block (ram,0x00549bae) */
/* WARNING: Removing unreachable block (ram,0x00549ba3) */
/* WARNING: Removing unreachable block (ram,0x00549bb1) */
/* WARNING: Removing unreachable block (ram,0x00549bd4) */

void __thiscall
CHmsZoneDynamic::ComputeCollisionResponse(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1)
{
{
  float fVar1;
  int iVar2;
  int iVar3;
  void *this_00;
  SCasterCat *pSVar4;
  GmMat3 *pGVar5;
  uint uVar6;
  GmVec3 *unaff_EBX;
  CScenePoc *unaff_EBP;
  _func___cdecl_int_SKey_ptr_SKey_ptr *unaff_ESI;
  SCasterCat *unaff_EDI;
  GmMat3 *in_stack_ffffff28;
  GmMat3 *in_stack_ffffff2c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_c4;
  CHmsPhysicalContact *pCStack_c0;
  CHmsZoneDynamic *pCStack_b4;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_98;
  float fStack_94;
  float fStack_90;
  undefined4 uStack_8c;
  undefined2 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
  int iStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  CFastBuffer<struct_SHmsPhysicalCollision>::QSort
            (this + 0x15c,
             (CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *)
             sCompareCollision,unaff_ESI);
  pCStack_98 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               (**(code **)(*(int *)(this + 0x158) + 8))();
  local_c4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack_98 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<struct_SHmsPhysicalCollision>::operator[]
                         (this + 0x15c,local_c4,(ulong)unaff_EDI);
      fVar1 = *(float *)pSVar4;
      iVar2 = *(int *)(*(int *)((int)fVar1 + 0x48) + 0x24);
      iVar3 = *(int *)(pSVar4 + 8);
      uVar6 = (uint)((*(uint *)(*(int *)((int)fVar1 + 0x48) + 0x18) >> 0xd & 0xf) !=
                    **(uint **)(pSVar4 + 0x48));
      if (iVar2 == 0) {
        local_c4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      }
      else {
        local_c4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 8);
      }
      if (((*(uint **)(pSVar4 + 0x48))[uVar6 + 3] != 0) &&
         (local_c4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)) {
        uStack_8c = *(undefined4 *)(pSVar4 + 4);
        uStack_4c = *(undefined4 *)(pSVar4 + 0xc);
        uStack_88 = *(undefined2 *)(pSVar4 + 0x34);
        uStack_48 = *(undefined2 *)(pSVar4 + 0x36);
        uStack_58 = 0;
        uStack_5c = 0;
        uStack_60 = 0;
        uStack_54 = 0;
        uStack_64 = 0;
        uStack_68 = 0;
        fStack_90 = fVar1;
        iStack_50 = iVar3;
        if (((byte)(*(uint *)(*(int *)((int)fVar1 + 0x48) + 0x18) >> 0x11) & 3) < 2) {
          fStack_6c = 0.0;
          uStack_7c = 0;
          uStack_80 = 0;
          uStack_84 = 0;
          fStack_70 = 0.0;
          fStack_74 = 0.0;
          uStack_78 = 0;
        }
        else {
          fStack_6c = 0.0;
          uStack_84 = *(undefined4 *)(pSVar4 + 0x1c);
          uStack_80 = *(undefined4 *)(pSVar4 + 0x20);
          uStack_7c = *(undefined4 *)(pSVar4 + 0x24);
          if (*(int *)((int)fVar1 + 0x58) == 0) {
            pGVar5 = (GmMat3 *)((int)fVar1 + 0x18);
          }
          else {
            pGVar5 = (GmMat3 *)(*(int *)(*(int *)((int)fVar1 + 0x58) + 0x32c) + 0x10);
          }
          GmVec3::MultTranspose(&uStack_84,pGVar5,(GmMat3 *)unaff_EBP);
          if (*(int *)((int)fVar1 + 0x58) == 0) {
            unaff_EBP = (CScenePoc *)((int)fVar1 + 0x18);
          }
          else {
            unaff_EBP = (CScenePoc *)(*(int *)(*(int *)((int)fVar1 + 0x58) + 0x32c) + 0x10);
          }
          fStack_74 = *(float *)(pSVar4 + 0x28) - *(float *)(unaff_EBP + 0x24);
          fStack_70 = *(float *)(pSVar4 + 0x2c) - *(float *)(unaff_EBP + 0x28);
          fStack_6c = *(float *)(pSVar4 + 0x30) - *(float *)(unaff_EBP + 0x2c);
          unaff_EDI = (SCasterCat *)0x549964;
          GmVec3::MultTranspose(&fStack_74,(GmMat3 *)unaff_EBP,(GmMat3 *)unaff_EBX);
        }
      }
      iVar2 = *(int *)(*(int *)(iVar3 + 0x48) + 0x24);
      if (iVar2 == 0) {
        local_c4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      }
      else {
        local_c4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 8);
      }
      if ((*(int *)(*(int *)(pSVar4 + 0x48) + 0xc + (1 - uVar6) * 4) != 0) &&
         (local_c4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)) {
        uStack_38 = *(undefined4 *)(pSVar4 + 0xc);
        pCStack_c0 = (CHmsPhysicalContact *)&iStack_3c;
        uStack_34 = *(undefined2 *)(pSVar4 + 0x36);
        uStack_4 = 0;
        uStack_8 = 0;
        uStack_c = 0;
        uStack_10 = 0;
        uVar6 = *(uint *)(*(int *)(iVar3 + 0x48) + 0x18) >> 0x11;
        uStack_14 = 0;
        iStack_3c = iVar3;
        if (((byte)uVar6 & 3) == 1 || (uVar6 & 3) == 0) {
          fStack_18 = 0.0;
          uStack_28 = 0;
          uStack_2c = 0;
          uStack_30 = 0;
          fStack_1c = 0.0;
          fStack_20 = 0.0;
          uStack_24 = 0;
        }
        else {
          fStack_18 = 0.0;
          uStack_30 = *(undefined4 *)(pSVar4 + 0x1c);
          uStack_2c = *(undefined4 *)(pSVar4 + 0x20);
          uStack_28 = *(undefined4 *)(pSVar4 + 0x24);
          if (*(int *)(iVar3 + 0x58) == 0) {
            pGVar5 = (GmMat3 *)(iVar3 + 0x18);
          }
          else {
            pGVar5 = (GmMat3 *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x32c) + 0x10);
          }
          unaff_EBP = (CScenePoc *)0x549a7f;
          GmVec3::MultTranspose(&uStack_30,pGVar5,in_stack_ffffff28);
          if (*(int *)(iVar3 + 0x58) == 0) {
            in_stack_ffffff28 = (GmMat3 *)(iVar3 + 0x18);
          }
          else {
            in_stack_ffffff28 = (GmMat3 *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x32c) + 0x10);
          }
          fStack_20 = *(float *)(pSVar4 + 0x28) - *(float *)(in_stack_ffffff28 + 0x24);
          fStack_1c = *(float *)(pSVar4 + 0x2c) - *(float *)(in_stack_ffffff28 + 0x28);
          fStack_18 = *(float *)(pSVar4 + 0x30) - *(float *)(in_stack_ffffff28 + 0x2c);
          unaff_EBX = (GmVec3 *)0x549ac8;
          GmVec3::MultTranspose(&fStack_20,in_stack_ffffff28,in_stack_ffffff2c);
        }
      }
      if (*(int *)(*(int *)(pSVar4 + 0x48) + 8) == 0) {
        this_00 = *(void **)(*(int *)(pSVar4 + 8) + 0x58);
        if (*(void **)(*(int *)pSVar4 + 0x58) == (void *)0x0) {
          fStack_90 = 0.0;
          fStack_94 = 0.0;
          pCStack_98 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        }
        else {
          unaff_EBX = (GmVec3 *)&pCStack_98;
          unaff_EBP = (CScenePoc *)(pSVar4 + 0x28);
          unaff_EDI = (SCasterCat *)0x549b29;
          CHmsDyna::GetSpeed(*(void **)(*(int *)pSVar4 + 0x58),unaff_EBP,unaff_EBX);
        }
        if (this_00 == (void *)0x0) {
          fStack_9c = 0.0;
          fStack_a0 = 0.0;
          fStack_a4 = 0.0;
        }
        else {
          unaff_EBX = (GmVec3 *)&fStack_a4;
          unaff_EBP = (CScenePoc *)(pSVar4 + 0x28);
          unaff_EDI = (SCasterCat *)0x549b4f;
          CHmsDyna::GetSpeed(this_00,unaff_EBP,unaff_EBX);
        }
        if (pCStack_c0 != (CHmsPhysicalContact *)0x0) {
          uVar6 = *(uint *)(*(int *)(iVar3 + 0x48) + 0x18) >> 0x11;
          if (((byte)uVar6 & 3) != 1 && (uVar6 & 3) != 0) {
            iVar2 = *(int *)(*(int *)(pSVar4 + 8) + 0x58);
            if (iVar2 == 0) {
              pGVar5 = (GmMat3 *)(*(int *)(pSVar4 + 8) + 0x18);
            }
            else {
              pGVar5 = (GmMat3 *)(*(int *)(iVar2 + 0x32c) + 0x10);
            }
            *(float *)(pCStack_c0 + 0x24) = fStack_a4 - (float)pCStack_98;
            *(float *)(pCStack_c0 + 0x28) = fStack_a0 - fStack_94;
            *(float *)(pCStack_c0 + 0x2c) = fStack_9c - fStack_90;
            GmVec3::MultTranspose(pCStack_c0 + 0x24,pGVar5,in_stack_ffffff28);
          }
          unaff_EBP = *(CScenePoc **)(*(int *)(pSVar4 + 8) + 0x48);
          unaff_EDI = (SCasterCat *)0x549c4b;
          unaff_EBX = (GmVec3 *)pCStack_c0;
          (**(code **)(*(int *)local_c4 + 0xc))();
        }
      }
      else {
        unaff_EBP = (CScenePoc *)0x0;
        unaff_EBX = (GmVec3 *)pCStack_c0;
        SolveImpulse(pCStack_b4,(CHmsZoneDynamic *)pSVar4,(SHmsPhysicalCollision *)0x0,pCStack_c0,
                     (CHmsPhysicalContact *)in_stack_ffffff28);
        unaff_EDI = pSVar4;
      }
      local_c4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)local_c4 + 1);
      this = (CHmsZoneDynamic *)pCStack_c0;
    } while (local_c4 < pCStack_98);
  }
  return;
}
}

// =================================================
// Function: CHmsZoneDynamic::ComputeCorpusForces
// =================================================
void __thiscall
CHmsZoneDynamic::ComputeCorpusForces
          (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2,float param_3)
{
{
  CHmsZoneDynamic *this_00;
  void *this_01;
  int *piVar1;
  float fVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  int iVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  GmVec3 *unaff_EBP;
  GmVec3 *unaff_ESI;
  CHmsDyna *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  float unaff_retaddr;
  int in_stack_0000001c;
  undefined4 in_stack_00000020;
  GmVec3 *in_stack_ffffffd0;
  GmVec3 *in_stack_ffffffd4;
  CHmsZoneDynamic *local_28;
  CHmsZoneDynamic *local_20;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  this_01 = *(void **)(param_1 + 0x58);
  if (this_01 != (void *)0x0) {
    CHmsDyna::ValidateDynamicState(this_01,unaff_EDI);
    if ((*(uint *)(*(int *)(param_1 + 0x48) + 0x18) & 0x100000) != 0) {
      local_14 = 0.0;
      local_10 = 0.0;
      local_c = 0.0;
      CHmsDyna::SetForce(this_01,(CHmsItem *)&local_14,unaff_ESI);
      local_10 = 0.0;
      local_c = 0.0;
      local_8 = 0.0;
      CHmsDyna::SetTorque(this_01,(CHmsItem *)&local_10,unaff_EBP);
      return;
    }
    local_18 = 0.0;
    this_00 = this + 0x7c;
    local_20 = (CHmsZoneDynamic *)0x0;
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    local_28 = this;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar6,(ulong)unaff_ESI);
        unaff_ESI = (GmVec3 *)&local_c;
        iVar5 = (**(code **)(**(int **)pSVar4 + 0x8c))(*(int *)((int)this_01 + 0x32c) + 0x34);
        if (iVar5 != 0) {
          local_28 = (CHmsZoneDynamic *)
                     (*(float *)(in_stack_ffffffd4 + 0x34) * *(float *)in_stack_ffffffd4);
          local_10 = (float)local_28 * local_10;
          local_c = local_c * (float)local_28;
          local_8 = (float)local_28 * local_8;
          local_18 = local_c + local_18;
          local_14 = local_8 + local_14;
        }
        pCVar6 = pCVar6 + 1;
        this = local_20;
      } while (pCVar6 < pCVar3);
    }
    CHmsDyna::GetLinearSpeed(this_01,(CHmsItem *)&local_4,unaff_ESI);
    fVar2 = -*(float *)(this + 0x11c) * *(float *)(local_28 + 0x28);
    local_18 = fVar2 * unaff_retaddr + local_18;
    local_14 = (float)param_1 * fVar2 + local_14;
    local_10 = fVar2 * (float)param_2 + local_10;
    CHmsDyna::SetForce(this_01,(CHmsItem *)&local_18,unaff_EBP);
    if (*(int *)((int)this_01 + 0x340) == 1) {
      CHmsDyna::GetAngularSpeed(this_01,(CHmsItem *)&local_8,in_stack_ffffffd0);
      local_14 = -*(float *)(this + 0x120) * *(float *)(local_28 + 0x2c);
      local_4 = local_14 * local_4;
      CHmsDyna::SetTorque(this_01,(CHmsItem *)&local_4,in_stack_ffffffd4);
    }
    iVar5 = *(int *)(*(int *)(in_stack_0000001c + 0x48) + 0x24);
    if ((iVar5 != 0) && (piVar1 = *(int **)(iVar5 + 0xc), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0xc))(*(int *)(in_stack_0000001c + 0x48),in_stack_00000020);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsZoneDynamic::IsPhysics
// =================================================
int __thiscall CHmsZoneDynamic::IsPhysics(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1)
{
{
  return *(uint *)(*(int *)(this + 0x138) + 0x18) & 1;
}
}

// =================================================
// Function: CHmsZoneDynamic::PhysicsStep2
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsZoneDynamic::PhysicsStep2(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1)
{
{
  void *this_00;
  int iVar1;
  int *piVar2;
  CHmsDyna *pCVar3;
  ulong uVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  ulong *puVar7;
  CHmsDyna *pCVar8;
  CSystemFileMemMapped *this_01;
  void *this_02;
  CHmsCorpus *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CHmsZoneDynamic *pCVar10;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CHmsZoneDynamic *this_03;
  CClassicBufferMemory *unaff_EDI;
  ushort in_FPUControlWord;
  float10 fVar11;
  float in_stack_ffffff6c;
  SZone *in_stack_ffffff70;
  CHmsZoneDynamic *in_stack_ffffff74;
  CHmsCorpus *in_stack_ffffff78;
  CHmsZoneDynamic *in_stack_ffffff7c;
  CHmsDyna *in_stack_ffffff80;
  float in_stack_ffffff84;
  SZone *in_stack_ffffff88;
  CHmsZoneDynamic *pCVar12;
  CHmsCorpus *pCVar13;
  float fVar14;
  SZone *pSVar15;
  CHmsCorpus *pCVar16;
  CHmsCorpus *pCVar17;
  CFastBuffer<class_CCrystalFace*> *pCVar18;
  SZone *in_stack_ffffffa0;
  CHmsZoneDynamic *in_stack_ffffffa4;
  CHmsDyna *pCVar19;
  CHmsItem *in_stack_ffffffac;
  CHmsCorpus *in_stack_ffffffb0;
  CHmsDyna *local_4c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_44;
  CHmsZoneDynamic *pCStack_40;
  void *pvStack_3c;
  longlong local_34;
  
  pSVar15 = (SZone *)&stack0xfffffffc;
  this_01 = *(CSystemFileMemMapped **)(DAT_00d731e0 + 0x14);
  if (this_01 == (CSystemFileMemMapped *)0x0) {
    this_01 = (CSystemFileMemMapped *)(DAT_00d731e0 + 0xa0);
  }
  pCVar12 = (CHmsZoneDynamic *)0x549cb6;
  uVar4 = CSystemFileMemMapped::GetActualSize(this_01,unaff_EDI);
  pCVar19 = (CHmsDyna *)((float)(int)uVar4 * (float)_DAT_00b30a18);
  pCVar13 = (CHmsCorpus *)0x549cd9;
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x140,unaff_ESI);
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar10 = this + 0x140;
  if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pCVar13 = (CHmsCorpus *)0x549cfc;
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar10,pCVar9,(ulong)pSVar15);
      pCVar10 = *(CHmsZoneDynamic **)pSVar6;
      if ((*(uint *)(*(int *)(pCVar10 + 0x48) + 0x18) & 0x1e000) == 0) {
        pCVar13 = (CHmsCorpus *)0x549d16;
        ComputeCorpusForces(this,pCVar10,in_stack_ffffffb0,(float)unaff_EBX);
        pSVar15 = (SZone *)0x549d26;
        unaff_EBX = (CHmsCorpus *)local_4c;
        CHmsDyna::DoPreCollisionDynamic
                  (*(void **)(pCVar10 + 0x58),local_4c,(float)in_stack_ffffffa0);
      }
      pCVar9 = pCVar9 + 1;
      pCVar10 = pCStack_40;
    } while (pCVar9 < pCVar5);
  }
  fVar14 = 7.770584e-39;
  CHmsCollisionManager::SZone::PrepareCollisions(*(void **)(this + 0x168),pSVar15);
  pCVar10 = (CHmsZoneDynamic *)0x0;
  do {
    if (*(int *)(pCVar10 + *(int *)(this + 0x168) + 0x40) == 0) {
      this_03 = pCVar10 + *(int *)(this + 0x168) + 0xc;
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this_03,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
      local_44 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        while( true ) {
          pCVar16 = (CHmsCorpus *)0x549d80;
          unaff_EBX = (CHmsCorpus *)local_44;
          pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_03,local_44,(ulong)in_stack_ffffffa0);
          pCVar10 = *(CHmsZoneDynamic **)pSVar6;
          this_00 = *(void **)(pCVar10 + 0x58);
          if (this_00 == (void *)0x0) {
            CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                      (this + 0x15c,(GmFrustumIso4 *)in_stack_ffffffa4);
            in_stack_ffffffa0 = (SZone *)(this + 0x158);
            unaff_EBX = (CHmsCorpus *)0x549fae;
            CHmsCollisionManager::SZone::DetectCollisionsCorpus
                      (*(void **)(this + 0x168),in_stack_ffffffa0,(CHmsCollisionBuffer *)pCVar10,
                       (CHmsCorpus *)pCVar19);
            pCVar19 = (CHmsDyna *)0x549fb5;
            ComputeCollisionResponse(this,(CHmsZoneDynamic *)in_stack_ffffffac);
            in_stack_ffffffa4 = pCVar10;
          }
          else {
            this_02 = *(void **)(DAT_00d731e0 + 0x14);
            if (this_02 == (void *)0x0) {
              this_02 = (void *)(DAT_00d731e0 + 0xa0);
            }
            iVar1 = *(int *)(pCVar10 + 0x48);
            in_stack_ffffffa0 = (SZone *)0x549da7;
            puVar7 = CMwTimerAdapter::GetTickTime(this_02,(CMwTimerAdapter *)in_stack_ffffffa4);
            *(ulong *)(iVar1 + 0x48) = *puVar7;
            if (*(int *)((int)this_00 + 0x33c) != 0) {
              CHmsDyna::CopyStateToTemp(this_00,pCVar19);
              in_stack_ffffffa4 = (CHmsZoneDynamic *)0x549dd9;
              CHmsDyna::GetLinearSpeed
                        (this_00,(CHmsItem *)&stack0xfffffffc,(GmVec3 *)in_stack_ffffffac);
              in_stack_ffffffac = (CHmsItem *)&stack0x0000000c;
              pCVar19 = (CHmsDyna *)0x549de5;
              CHmsDyna::GetAngularSpeed(this_00,in_stack_ffffffac,(GmVec3 *)in_stack_ffffffb0);
              fVar11 = (float10)func_0x009c1b40();
              pvStack_3c = (void *)(float)fVar11;
              in_stack_ffffffb0 = (CHmsCorpus *)0x549e55;
              fVar11 = (float10)func_0x009c1b40();
              unaff_EBX = (CHmsCorpus *)((float)fVar11 + fVar14);
              local_34 = (longlong)ROUND(((float)pCVar16 * (float)unaff_EBX) / (float)local_4c);
              pCVar8 = (CHmsDyna *)((int)(CHmsZoneDynamic *)local_34 + 1);
              if ((CHmsDyna *)0x3e8 < pCVar8) {
                pCVar8 = (CHmsDyna *)0x3e8;
              }
              pCVar17 = pCVar16;
              local_4c = (CHmsDyna *)(in_FPUControlWord | 0xc00);
              if ((CHmsDyna *)0x1 < pCVar8) {
                fVar14 = (float)(int)pCVar8;
                if ((int)pCVar8 < 0) {
                  fVar14 = fVar14 + _DAT_00c418d0;
                }
                unaff_EBX = (CHmsCorpus *)((float)pCVar16 / fVar14);
                pCVar3 = pCVar8;
                while (pCVar3 = pCVar3 + -1, local_4c = pCVar8, pCVar3 != (CHmsDyna *)0x0) {
                  ComputeCorpusForces(this,pCVar10,unaff_EBX,in_stack_ffffff6c);
                  CHmsDyna::DoPreCollisionDynamic
                            (this_00,(CHmsDyna *)in_stack_ffffff88,(float)in_stack_ffffff70);
                  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                            (this + 0x15c,(GmFrustumIso4 *)in_stack_ffffff74);
                  in_stack_ffffff70 = (SZone *)(this + 0x158);
                  in_stack_ffffff6c = 7.77125e-39;
                  in_stack_ffffff74 = pCVar10;
                  CHmsCollisionManager::SZone::DetectCollisionsCorpus
                            (*(void **)(this + 0x168),in_stack_ffffff70,
                             (CHmsCollisionBuffer *)pCVar10,in_stack_ffffff78);
                  in_stack_ffffff78 = (CHmsCorpus *)0x549f1c;
                  ComputeCollisionResponse(this,in_stack_ffffff7c);
                  in_stack_ffffff7c = (CHmsZoneDynamic *)0x549f23;
                  CHmsDyna::DoPostCollisionDynamic(this_00,in_stack_ffffff80);
                  pCVar16 = (CHmsCorpus *)((float)pCVar16 - (float)unaff_EBX);
                }
              }
              in_stack_ffffff78 = (CHmsCorpus *)0x549f4c;
              in_stack_ffffff7c = pCVar10;
              ComputeCorpusForces(this,pCVar10,pCVar16,in_stack_ffffff84);
              in_stack_ffffff80 = (CHmsDyna *)0x549f5b;
              CHmsDyna::DoPreCollisionDynamic(this_00,(CHmsDyna *)pCVar17,(float)in_stack_ffffff88);
              CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                        (this + 0x15c,(GmFrustumIso4 *)pCVar12);
              in_stack_ffffff88 = (SZone *)(this + 0x158);
              in_stack_ffffff84 = 7.77139e-39;
              CHmsCollisionManager::SZone::DetectCollisionsCorpus
                        (*(void **)(this + 0x168),in_stack_ffffff88,(CHmsCollisionBuffer *)pCVar10,
                         pCVar13);
              pCVar13 = (CHmsCorpus *)0x549f80;
              ComputeCollisionResponse(this,(CHmsZoneDynamic *)pCVar16);
              fVar14 = 7.77141e-39;
              CHmsDyna::DoPostCollisionDynamic(this_00,(CHmsDyna *)pCVar17);
              CHmsDyna::CopyTempToState(this_00,(CHmsDyna *)unaff_EBX);
              pCVar12 = pCVar10;
            }
          }
          local_44 = local_44 + 1;
          pCVar10 = pCStack_40;
          if (pCVar5 <= local_44) break;
          this_03 = (CHmsZoneDynamic *)local_34;
        }
      }
    }
    pCVar10 = pCVar10 + 0x44;
  } while (pCVar10 < (CHmsZoneDynamic *)0x154);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack_40 != (CHmsZoneDynamic *)0x0) {
    do {
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pvStack_3c,pCVar5,(ulong)unaff_EBX);
      pCVar18 = *(CFastBuffer<class_CCrystalFace*> **)(*(int *)pSVar6 + 0x48);
      if ((*(int *)(pCVar18 + 0x24) != 0) &&
         (piVar2 = *(int **)(*(int *)(pCVar18 + 0x24) + 0x10), piVar2 != (int *)0x0)) {
        (**(code **)(*piVar2 + 0xc))();
        unaff_EBX = (CHmsCorpus *)pCVar18;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCStack_40);
  }
  return;
}
}

// =================================================
// Function: CHmsZoneDynamic::SetPhysics
// =================================================
void __thiscall
CHmsZoneDynamic::SetPhysics(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,int param_2)
{
{
  if (param_1 != (CHmsZoneDynamic *)0x0) {
    if (*(int *)(this + 0x134) != 0) {
      (**(code **)(**(int **)(this + 0x134) + 0x7c))();
    }
    (**(code **)(**(int **)(this + 0x138) + 0x7c))();
    return;
  }
  if (*(int *)(this + 0x134) != 0) {
    (**(code **)(**(int **)(this + 0x134) + 0x80))();
  }
  (**(code **)(**(int **)(this + 0x138) + 0x80))();
  return;
}
}

// =================================================
// Function: CHmsZoneDynamic::SolveImpulse
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsZoneDynamic::SolveImpulse
          (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,SHmsPhysicalCollision *param_2,
          CHmsPhysicalContact *param_3,CHmsPhysicalContact *param_4)
{
{
  CHmsZoneDynamic *this_00;
  CHmsPhysicalContact *this_01;
  float *this_02;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  GmMat3 *pGVar8;
  float fVar9;
  void *this_03;
  uint uVar10;
  uint uVar11;
  GmMat3 *pGVar12;
  GmIso3 *unaff_EBX;
  CHmsPhysicalContact *this_04;
  float *this_05;
  GmMat3 *unaff_EBP;
  GmMat3 *unaff_ESI;
  CHmsZoneDynamic *pCVar13;
  CPlugSurfaceMaterialData *unaff_EDI;
  GmMat3 *pGVar14;
  float10 fVar15;
  CHmsZoneDynamic *in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  GmMat3 *in_stack_00000024;
  GmIso3 *pGVar16;
  GmMat3 *in_stack_ffffff74;
  GmMat3 *pGVar17;
  GmIso4 *in_stack_ffffff7c;
  float local_74;
  float fStack_70;
  float fStack_6c;
  float local_68;
  float fStack_64;
  void *local_58;
  int *local_54;
  float local_50;
  void *local_4c;
  void *local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float fStack_30;
  int local_2c;
  int iStack_28;
  int local_24;
  float local_20;
  float local_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar5 = *(float *)param_1;
  iVar6 = *(int *)(param_1 + 8);
  local_3c = (float)iVar6;
  local_38 = fVar5;
  CPlugSurfaceMaterialData::GetRestitutionCoefWith
            (&DAT_00d6eec0 + (uint)*(ushort *)(param_1 + 0x34) * 2,
             (CPlugSurfaceMaterialData *)(&DAT_00d6eec0 + (uint)*(ushort *)(param_1 + 0x36) * 2),
             unaff_EDI);
  local_58 = *(void **)(iVar6 + 0x58);
  pGVar14 = *(GmMat3 **)((int)fVar5 + 0x58);
  uVar10 = *(uint *)(*(int *)((int)fVar5 + 0x48) + 0x18) >> 0xb & 3;
  uVar11 = *(uint *)(*(int *)(iVar6 + 0x48) + 0x18) >> 0xb & 3;
  this_00 = param_1 + 0x10;
  if (uVar11 < uVar10) {
    local_44 = -*(float *)this_00;
    local_40 = -*(float *)(param_1 + 0x14);
    local_3c = -*(float *)(param_1 + 0x18);
    local_48 = (void *)0x0;
    local_4c = (void *)0x0;
    local_50 = 0.0;
  }
  else if (uVar10 < uVar11) {
    local_50 = *(float *)this_00;
    local_4c = *(void **)(param_1 + 0x14);
    local_48 = *(void **)(param_1 + 0x18);
    local_3c = 0.0;
    local_40 = 0.0;
    local_44 = 0.0;
  }
  else {
    local_54 = *(int **)(*(int *)(*(int *)((int)fVar5 + 0x48) + 0x14) + 0x18);
    fVar5 = *(float *)(*(int *)(*(int *)(iVar6 + 0x48) + 0x14) + 0x18);
    fVar1 = 1.0 / ((float)local_54 + fVar5);
    local_3c = fVar1 * -fVar5;
    local_44 = local_3c * *(float *)this_00;
    local_40 = local_3c * *(float *)(param_1 + 0x14);
    local_3c = local_3c * *(float *)(param_1 + 0x18);
    local_68 = fVar1 * (float)local_54;
    local_50 = local_68 * *(float *)this_00;
    local_4c = (void *)(local_68 * *(float *)(param_1 + 0x14));
    local_48 = (void *)(local_68 * *(float *)(param_1 + 0x18));
  }
  pGVar12 = pGVar14;
  if (pGVar14 == (GmMat3 *)0x0) {
    local_1c = 0.0;
    local_20 = 0.0;
    local_24 = 0;
  }
  else {
    CHmsDyna::GetSpeed(pGVar14,(CScenePoc *)(param_1 + 0x28),(GmVec3 *)&local_24);
  }
  if (local_58 == (void *)0x0) {
    local_4 = 0.0;
    local_8 = 0.0;
    local_c = 0.0;
  }
  else {
    CHmsDyna::GetSpeed(local_58,(CScenePoc *)(param_1 + 0x28),(GmVec3 *)&local_c);
  }
  pGVar8 = (GmMat3 *)(local_8 - local_20);
  fVar5 = local_4 - local_1c;
  pCVar13 = param_1;
  if (param_3 != (CHmsPhysicalContact *)0x0) {
    *(undefined4 *)(param_3 + 0x3c) = 1;
    if (*(int *)((int)local_34 + 0x58) == 0) {
      pGVar14 = (GmMat3 *)((int)local_34 + 0x18);
    }
    else {
      pGVar14 = (GmMat3 *)(*(int *)(*(int *)((int)local_34 + 0x58) + 0x32c) + 0x10);
    }
    this_01 = param_3 + 0x30;
    *(float *)this_01 = local_44;
    *(float *)(param_3 + 0x34) = local_40;
    *(float *)(param_3 + 0x38) = local_3c;
    GmVec3::MultTranspose(this_01,pGVar14,unaff_ESI);
    this_04 = param_3 + 0x24;
    *(float *)this_04 = -(float)pGVar8;
    *(float *)(param_3 + 0x28) = -fVar5;
    *(float *)(param_3 + 0x2c) = -local_74;
    GmVec3::MultTranspose(this_04,pGVar14,unaff_EBP);
    iVar6 = *(int *)(*(int *)(local_2c + 0x48) + 0x24);
    if ((iVar6 != 0) && (piVar7 = *(int **)(iVar6 + 8), piVar7 != (int *)0x0)) {
      (**(code **)(*piVar7 + 0xc))(*(int *)(local_2c + 0x48),in_stack_00000014);
    }
    GmVec3::Mult(this_04,(GmIso3 *)pGVar14,unaff_EBX);
    fStack_70 = -*(float *)(param_3 + 0x28);
    fStack_6c = -*(float *)(param_3 + 0x2c);
    local_38 = *(float *)(pGVar14 + 8) * *(float *)(param_3 + 0x38) +
               *(float *)pGVar14 * *(float *)this_01 +
               *(float *)(pGVar14 + 4) * *(float *)(param_3 + 0x34);
    local_34 = *(float *)(pGVar14 + 0x14) * *(float *)(param_3 + 0x38) +
               *(float *)(pGVar14 + 0xc) * *(float *)this_01 +
               *(float *)(pGVar14 + 0x10) * *(float *)(param_3 + 0x34);
    fStack_30 = *(float *)(pGVar14 + 0x20) * *(float *)(param_3 + 0x38) +
                *(float *)(pGVar14 + 0x18) * *(float *)this_01 +
                *(float *)(pGVar14 + 0x1c) * *(float *)(param_3 + 0x34);
    pCVar13 = in_stack_00000014;
    pGVar14 = pGVar8;
  }
  if (pGVar14 != (GmMat3 *)0x0) {
    CHmsDyna::AddReplacement(pGVar14,(CHmsDyna *)&local_38,(GmVec3 *)in_stack_ffffff74);
  }
  if (in_stack_0000001c != 0) {
    *(undefined4 *)(in_stack_0000001c + 0x3c) = 1;
    if (*(int *)(local_2c + 0x58) == 0) {
      pGVar14 = (GmMat3 *)(local_2c + 0x18);
    }
    else {
      pGVar14 = (GmMat3 *)(*(int *)(*(int *)(local_2c + 0x58) + 0x32c) + 0x10);
    }
    this_02 = (float *)(in_stack_0000001c + 0x30);
    *this_02 = local_44;
    *(float *)(in_stack_0000001c + 0x34) = local_40;
    *(float *)(in_stack_0000001c + 0x38) = local_3c;
    GmVec3::MultTranspose(this_02,pGVar14,in_stack_ffffff74);
    this_05 = (float *)(in_stack_0000001c + 0x24);
    *this_05 = fStack_70;
    *(float *)(in_stack_0000001c + 0x28) = fStack_6c;
    *(float *)(in_stack_0000001c + 0x2c) = local_68;
    pGVar16 = (GmIso3 *)0x548f53;
    in_stack_ffffff74 = pGVar14;
    GmVec3::MultTranspose(this_05,pGVar14,pGVar12);
    pGVar17 = *(GmMat3 **)(local_24 + 0x48);
    if ((*(int *)(pGVar17 + 0x24) != 0) &&
       (local_54 = *(int **)(*(int *)(pGVar17 + 0x24) + 8), local_54 != (int *)0x0)) {
      pGVar16 = (GmIso3 *)0x548f80;
      (**(code **)(*local_54 + 0xc))();
      in_stack_ffffff74 = pGVar17;
      pGVar12 = in_stack_00000024;
    }
    GmVec3::Mult(this_05,(GmIso3 *)pGVar14,pGVar16);
    local_44 = *(float *)(pGVar14 + 8) * *(float *)(in_stack_0000001c + 0x38) +
               *(float *)pGVar14 * *this_02 +
               *(float *)(pGVar14 + 4) * *(float *)(in_stack_0000001c + 0x34);
    local_40 = *(float *)(pGVar14 + 0x14) * *(float *)(in_stack_0000001c + 0x38) +
               *(float *)(pGVar14 + 0x10) * *(float *)(in_stack_0000001c + 0x34) +
               *(float *)(pGVar14 + 0xc) * *this_02;
    local_3c = *(float *)(pGVar14 + 0x20) * *(float *)(in_stack_0000001c + 0x38) +
               *(float *)(pGVar14 + 0x1c) * *(float *)(in_stack_0000001c + 0x34) +
               *(float *)(pGVar14 + 0x18) * *this_02;
    pCVar13 = in_stack_00000014;
    pGVar14 = pGVar8;
  }
  if (local_4c != (void *)0x0) {
    CHmsDyna::AddReplacement(local_4c,(CHmsDyna *)&local_44,(GmVec3 *)in_stack_ffffff74);
  }
  if (((in_stack_00000018 == 0) || (*(int *)(in_stack_00000018 + 0x3c) != 0)) &&
     ((in_stack_0000001c == 0 || (*(int *)(in_stack_0000001c + 0x3c) != 0)))) {
    fVar5 = (float)(&DAT_00d6eec0)[(uint)*(ushort *)(pCVar13 + 0x34) * 2] *
            (float)(&DAT_00d6eec0)[(uint)*(ushort *)(pCVar13 + 0x36) * 2];
    if (pGVar14 != (GmMat3 *)0x0) {
      local_50 = fStack_14 * *(float *)(param_1 + 0x20) + fStack_18 * *(float *)(param_1 + 0x1c) +
                 fStack_10 * *(float *)(param_1 + 0x24);
      local_58 = (void *)(local_50 * *(float *)(param_1 + 0x1c));
      local_54 = (int *)(*(float *)(param_1 + 0x20) * local_50);
      local_50 = local_50 * *(float *)(param_1 + 0x24);
      local_74 = fStack_18 - (float)local_58;
      fStack_70 = fStack_14 - (float)local_54;
      fStack_6c = fStack_10 - local_50;
      fVar15 = (float10)func_0x009c1b40();
      local_48 = (void *)(float)fVar15;
      fVar15 = (float10)func_0x009c1b40();
      if ((float)local_48 * fVar5 < (float)fVar15) {
        fVar1 = ((float)local_48 * fVar5) / (float)fVar15;
        local_74 = fVar1 * local_74;
        fStack_70 = fStack_70 * fVar1;
        fStack_6c = fVar1 * fStack_6c;
      }
      fVar4 = local_74 + (float)local_58;
      fVar2 = fStack_70 + (float)local_54;
      fVar3 = fStack_6c + local_50;
      fVar15 = (float10)func_0x009c1b40();
      fVar1 = (float)fVar15;
      if (_DAT_00b56fb4 < fVar1) {
        fVar9 = 1.0 / fVar1;
        local_68 = fVar9 * -fVar4;
        fVar4 = -fVar2 * fVar9;
        fVar9 = fVar9 * -fVar3;
        local_48 = (void *)(1.0 / **(float **)(pGVar14 + 0x108));
        if ((*(int *)(pGVar14 + 0x340) == 1) &&
           ((*(uint *)(*(int *)(iStack_28 + 0x48) + 0x1c) & 0x1000) == 0)) {
          fVar2 = *(float *)(param_1 + 0x2c);
          fVar3 = *(float *)(param_1 + 0x30);
          GmVec3::SetMult(&local_58,(SPlugFaceCull *)(*(float **)(pGVar14 + 0x108) + 0xe),
                          (SPlugFaceCull *)(*(int *)(pGVar14 + 0x32c) + 0x10),
                          (GmIso4 *)in_stack_ffffff74);
          fVar2 = fVar2 - (float)local_54;
          in_stack_ffffff74 = (GmMat3 *)(*(int *)(pGVar14 + 0x32c) + 0x7c);
          fVar3 = fVar3 - local_50;
          local_68 = local_68 - (float)local_4c;
          local_54 = (int *)(fVar5 * fVar3 - fVar9 * local_68);
          local_50 = fVar4 * local_68 - fVar2 * fVar5;
          local_4c = (void *)(fVar2 * fVar9 - fVar4 * fVar3);
          GmVec3::SetMult(&local_20,(SPlugFaceCull *)&local_54,(SPlugFaceCull *)in_stack_ffffff74,
                          (GmIso4 *)pGVar12);
          local_50 = fVar4 * fStack_18 - local_68 * fStack_14;
          local_4c = (void *)(fVar3 * fStack_14 - local_1c * fVar4);
          local_48 = (void *)(local_1c * local_68 - fVar3 * fStack_18);
          local_40 = (float)local_48 * (float)local_58 + local_50 * fVar9 + (float)local_4c * fVar5
                     + local_40;
        }
        local_4 = (((float)param_3 + 1.0) * fVar1) / (float)local_48;
        local_c = local_4 * local_68;
        local_8 = fVar4 * local_4;
        local_4 = local_4 * fVar9;
        if ((*(uint *)(*(int *)(iStack_28 + 0x48) + 0x1c) & 0x1000) == 0) {
          CHmsDyna::AddImpulse(pGVar14,(CHmsItem *)&local_c,(GmVec3 *)(param_1 + 0x28));
        }
        else {
          CHmsDyna::AddImpulse(pGVar14,(CHmsItem *)&local_c,(GmVec3 *)in_stack_ffffff74);
        }
      }
    }
    GmCollision::Neg(this_00,(GmCollision *)in_stack_ffffff74);
    this_03 = local_48;
    if (local_48 != (void *)0x0) {
      fVar5 = (float)param_2 * *(float *)(param_1 + 0x20) +
              (float)param_1 * *(float *)(param_1 + 0x1c) +
              (float)param_3 * *(float *)(param_1 + 0x24);
      local_54 = (int *)(fVar5 * *(float *)(param_1 + 0x1c));
      local_50 = *(float *)(param_1 + 0x20) * fVar5;
      local_4c = (void *)(fVar5 * *(float *)(param_1 + 0x24));
      fStack_70 = (float)param_1 - (float)local_54;
      fStack_6c = (float)param_2 - local_50;
      local_68 = (float)param_3 - (float)local_4c;
      fVar15 = (float10)func_0x009c1b40();
      local_48 = (void *)(float)fVar15;
      fVar15 = (float10)func_0x009c1b40();
      if ((float)local_48 * (float)local_58 < (float)fVar15) {
        fVar5 = ((float)local_48 * (float)local_58) / (float)fVar15;
        fStack_70 = fVar5 * fStack_70;
        fStack_6c = fStack_6c * fVar5;
        local_68 = fVar5 * local_68;
      }
      fVar1 = fStack_70 + (float)local_54;
      fVar4 = fStack_6c + local_50;
      fVar2 = local_68 + (float)local_4c;
      fVar15 = (float10)func_0x009c1b40();
      fVar5 = (float)fVar15;
      if (_DAT_00b56fb4 < fVar5) {
        fVar3 = 1.0 / fVar5;
        fStack_64 = fVar3 * -fVar1;
        fVar1 = -fVar4 * fVar3;
        fVar3 = fVar3 * -fVar2;
        local_48 = (void *)(1.0 / **(float **)((int)this_03 + 0x108));
        if ((*(int *)((int)this_03 + 0x340) == 1) &&
           ((*(uint *)(*(int *)(iStack_28 + 0x48) + 0x1c) & 0x1000) == 0)) {
          fVar4 = *(float *)(param_1 + 0x2c);
          fVar2 = *(float *)(param_1 + 0x30);
          GmVec3::SetMult(&local_20,(SPlugFaceCull *)(*(float **)((int)this_03 + 0x108) + 0xe),
                          (SPlugFaceCull *)(*(int *)((int)this_03 + 0x32c) + 0x10),(GmIso4 *)pGVar12
                         );
          pGVar12 = (GmMat3 *)(*(int *)((int)this_03 + 0x32c) + 0x7c);
          fVar2 = fVar2 - fStack_18;
          fStack_64 = fStack_64 - fStack_14;
          local_50 = (float)local_58 * fVar2 - fVar3 * fStack_64;
          local_4c = (void *)(fVar1 * fStack_64 - (fVar4 - local_1c) * (float)local_58);
          local_48 = (void *)((fVar4 - local_1c) * fVar3 - fVar1 * fVar2);
          GmVec3::SetMult(&local_1c,(SPlugFaceCull *)&local_50,(SPlugFaceCull *)pGVar12,
                          in_stack_ffffff7c);
          local_4c = (void *)(fVar1 * fStack_14 - fStack_64 * fStack_10);
          local_48 = (void *)(fVar2 * fStack_10 - fStack_18 * fVar1);
          local_44 = fStack_18 * fStack_64 - fVar2 * fStack_14;
          local_40 = local_44 * (float)local_54 +
                     (float)local_48 * (float)local_58 + (float)local_4c * fVar3 + local_40;
        }
        local_4 = (((float)param_4 + 1.0) * fVar5) / (float)local_48;
        local_8 = local_4 * fStack_64;
        local_4 = fVar1 * local_4;
        if ((*(uint *)(*(int *)(iStack_28 + 0x48) + 0x1c) & 0x1000) != 0) {
          CHmsDyna::AddImpulse(this_03,(CHmsItem *)&local_8,(GmVec3 *)pGVar12);
          return;
        }
        CHmsDyna::AddImpulse(this_03,(CHmsItem *)&local_8,(GmVec3 *)(param_1 + 0x28));
        return;
      }
    }
  }
  return;
}
}

// =================================================
// Function: CHmsZoneDynamic::UpdateCorpusFromDynamicState
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsZoneDynamic::UpdateCorpusFromDynamicState
          (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,CHmsCorpus *param_2,
          CClassicBufferMemory *param_3,ulong param_4,uchar param_5)
{
{
  longlong lVar1;
  void *this_00;
  float fVar2;
  ulong *puVar3;
  CHmsCollisionBuffer *pCVar4;
  void *this_01;
  uchar unaff_SI;
  CMwTimerAdapter *unaff_EDI;
  float10 fVar5;
  CHmsCollisionBuffer *pCVar6;
  undefined3 in_stack_00000015;
  CHmsDyna *pCStack00000018;
  CHmsDyna *in_stack_ffffffc0;
  SZone *in_stack_ffffffc4;
  CHmsCollisionBuffer *in_stack_ffffffc8;
  CHmsCorpus *in_stack_ffffffcc;
  CHmsZoneDynamic *pCVar7;
  CHmsDyna *in_stack_ffffffe0;
  float fVar8;
  GmFrustumIso4 *pGVar9;
  CHmsCorpus *in_stack_ffffffec;
  double dVar10;
  
  this_00 = *(void **)(param_1 + 0x58);
  if (this_00 != (void *)0x0) {
    this_01 = *(void **)(DAT_00d731e0 + 0x14);
    if (this_01 == (void *)0x0) {
      this_01 = (void *)(DAT_00d731e0 + 0xa0);
    }
    puVar3 = CMwTimerAdapter::GetTickTime(this_01,unaff_EDI);
    if (param_4 < *puVar3) {
      fVar8 = (float)(int)(*puVar3 - param_4) * (float)_DAT_00b30a18;
      pGVar9 = *(GmFrustumIso4 **)(*(int *)((int)this_00 + 0x108) + 0x30);
      pCVar7 = (CHmsZoneDynamic *)0x54a0a1;
      CHmsDyna::CHmsStateDyna::RestoreState
                (*(void **)((int)this_00 + 0x32c),(CHmsStateDyna *)param_3,_param_5,unaff_SI);
      dVar10 = (double)*(float *)(*(int *)((int)this_00 + 0x32c) + 0x58);
      fVar5 = (float10)func_0x009c1b40();
      pCStack00000018 = (CHmsDyna *)(float)fVar5;
      fVar5 = (float10)func_0x009c1b40();
      lVar1 = (longlong)
              ROUND(((float)pGVar9 * ((float)fVar5 + (float)pCStack00000018)) /
                    (float)in_stack_ffffffec);
      pCVar6 = (CHmsCollisionBuffer *)lVar1;
      pCVar4 = pCVar6 + 1;
      if ((CHmsCollisionBuffer *)0x2710 < pCVar4) {
        pCVar4 = (CHmsCollisionBuffer *)0x2710;
      }
      fVar2 = (float)(int)pCVar4;
      if ((int)pCVar4 < 0) {
        fVar2 = fVar2 + _DAT_00c418d0;
      }
      pCVar4 = pCVar4 + -1;
      pCStack00000018 = (CHmsDyna *)((float)pGVar9 / fVar2);
      if (pCVar4 != (CHmsCollisionBuffer *)0x0) {
        do {
          CHmsDyna::ValidateDynamicState(this_00,in_stack_ffffffc0);
          param_1 = (CHmsZoneDynamic *)((ulonglong)lVar1 >> 0x20);
          CHmsDyna::DoPreCollisionDynamic(this_00,(CHmsDyna *)param_1,(float)in_stack_ffffffc4);
          CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                    (this + 0x15c,(GmFrustumIso4 *)in_stack_ffffffc8);
          in_stack_ffffffc4 = (SZone *)(this + 0x158);
          in_stack_ffffffc0 = (CHmsDyna *)0x54a1c7;
          in_stack_ffffffc8 = pCVar6;
          CHmsCollisionManager::SZone::DetectCollisionsCorpus
                    (*(void **)(this + 0x168),in_stack_ffffffc4,pCVar6,in_stack_ffffffcc);
          in_stack_ffffffcc = (CHmsCorpus *)0x54a1ce;
          ComputeCollisionResponse(this,pCVar7);
          pCVar7 = (CHmsZoneDynamic *)0x54a1d5;
          CHmsDyna::DoPostCollisionDynamic(this_00,(CHmsDyna *)param_3);
          pCVar4 = pCVar4 + -1;
        } while (pCVar4 != (CHmsCollisionBuffer *)0x0);
      }
      CHmsDyna::ValidateDynamicState(this_00,in_stack_ffffffe0);
      CHmsDyna::DoPreCollisionDynamic(this_00,pCStack00000018,fVar8);
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x15c,pGVar9);
      CHmsCollisionManager::SZone::DetectCollisionsCorpus
                (*(void **)(this + 0x168),(SZone *)(this + 0x158),
                 (CHmsCollisionBuffer *)pCStack00000018,in_stack_ffffffec);
      ComputeCollisionResponse(this,SUB84(dVar10,0));
      CHmsDyna::DoPostCollisionDynamic(this_00,(CHmsDyna *)((ulonglong)dVar10 >> 0x20));
    }
  }
  return;
}
}

