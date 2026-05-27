// Class implementation: CHmsCollisionManager_SZone

// =================================================
// Function: CHmsCollisionManager::SZone::AddCorpus
// =================================================
void __thiscall
CHmsCollisionManager::SZone::AddCorpus(void *this,SZone *param_1,CHmsCorpus *param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x48) + 0x18) >> 0xd & 0xf;
  if (uVar1 != 0) {
    SGroup::AddCorpus((void *)((int)this + uVar1 * 0x44 + -0x44),param_1,param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::ComputeCollision
// =================================================
int __cdecl
CHmsCollisionManager::SZone::ComputeCollision
          (LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)
{
{
  CMwNod *this;
  GmIso3 *pGVar1;
  int iVar2;
  undefined4 extraout_EAX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  GmBoxAligned *pGVar6;
  undefined4 uVar7;
  GmIso3 *unaff_EBX;
  CMwNod *pCVar8;
  GmIso4 *unaff_EBP;
  GmBoxAligned *unaff_ESI;
  undefined4 *puVar9;
  GmIso4 *unaff_EDI;
  CMwNod *pCVar10;
  int *piVar11;
  LocatedGmSurf *pLVar12;
  GmBoxAligned *pGVar13;
  int *piVar14;
  bool bVar15;
  GmBoxAligned *pGVar16;
  TiXmlAttributeSet *pTVar17;
  GmIso3 *in_stack_ffffff28;
  CGmCollisionBuffer *extraout_var;
  CGmCollisionBuffer *pCVar18;
  void *local_c8;
  void *pvStack_c4;
  GmBoxAligned *pGStack_c0;
  LocatedGmSurf *local_bc;
  int *local_b8;
  CMwNod *local_b4;
  CMwNod *local_b0;
  LocatedGmSurf *pLStack_ac;
  int **ppiStack_a8;
  GmBoxAligned *pGStack_a4;
  void *pvStack_a0;
  int **local_9c;
  undefined4 local_98;
  LocatedGmSurf *pLStack_94;
  undefined4 uStack_90;
  int *piStack_8c;
  int local_88 [11];
  CMwNod local_5c [4];
  LocatedGmSurf aLStack_58 [28];
  undefined1 local_3c [8];
  undefined1 local_34 [8];
  SPlugTreeLocatedPair aSStack_2c [12];
  undefined1 local_20 [4];
  CPlugVolumeProjector local_1c [4];
  SPlugTreeLocatedPair aSStack_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a9566e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = *(CMwNod **)param_1;
  iVar2 = *(int *)(param_1 + 8);
  if ((((byte)this[0x9c] & 0x80) != 0) && ((*(byte *)(iVar2 + 0x9c) & 0x80) != 0)) {
    GmBoxAligned::SetMult
              (local_3c,(SPlugFaceCull *)(this + 0x34),*(SPlugFaceCull **)(param_1 + 4),
               (GmIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffff18));
    pCVar18 = extraout_var;
    GmBoxAligned::SetMult
              (local_20,(SPlugFaceCull *)(iVar2 + 0x34),*(SPlugFaceCull **)(param_1 + 0xc),unaff_EDI
              );
    iVar2 = GmBoxAligned::TestInter(local_34,local_1c,unaff_ESI,unaff_EBP);
    if (iVar2 != 0) {
      local_c8 = (void *)0x0;
      iVar2 = 0xc;
      if (((byte)this[0x9c] & 4) == 0) {
        puVar9 = *(undefined4 **)(param_1 + 4);
        pCVar8 = local_5c;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined4 *)pCVar8 = *puVar9;
          puVar9 = puVar9 + 1;
          pCVar8 = pCVar8 + 4;
        }
      }
      else {
        pCVar8 = this + 0x5c;
        pCVar10 = local_5c;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined4 *)pCVar10 = *(undefined4 *)pCVar8;
          pCVar8 = pCVar8 + 4;
          pCVar10 = pCVar10 + 4;
        }
        GmIso4::Mult(local_5c,*(GmIso3 **)(param_1 + 4),unaff_EBX);
      }
      iVar2 = 0xc;
      if ((*(byte *)(local_b8 + 0x27) & 4) == 0) {
        piVar14 = *(int **)(param_1 + 0xc);
        piVar11 = local_88;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar11 = *piVar14;
          piVar14 = piVar14 + 1;
          piVar11 = piVar11 + 1;
        }
      }
      else {
        pGVar1 = *(GmIso3 **)(param_1 + 0xc);
        piVar14 = local_b8 + 0x17;
        piVar11 = local_88;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar11 = *piVar14;
          piVar14 = piVar14 + 1;
          piVar11 = piVar11 + 1;
        }
        GmIso4::Mult(local_88,pGVar1,in_stack_ffffff28);
      }
      pCVar8 = *(CMwNod **)(this + 0x8c);
      local_9c = (int **)local_b8[0x23];
      local_b4 = pCVar8;
      if ((pCVar8 != (CMwNod *)0x0) && (local_9c != (int **)0x0)) {
        local_bc = (LocatedGmSurf *)0x0;
        if ((*(char *)(*(int *)(*(int *)(pCVar8 + 0x14) + 0x34) + 6) == '\0') ||
           (*(char *)(*(int *)(*(int *)(pCVar8 + 0x14) + 0x34) + 6) == '\x01')) {
          if (*(int *)(this + 0x50) == 0) {
            pvStack_a0 = operator_new(0x14);
            if (pvStack_a0 == (void *)0x0) {
              uVar7 = 0;
            }
            else {
              SHmsSphereBufferContact::SHmsSphereBufferContact
                        (pvStack_a0,(SHmsSphereBufferContact *)in_stack_ffffff28);
              uVar7 = extraout_EAX;
            }
            *(undefined4 *)(this + 0x50) = uVar7;
            CMwNod::MwAddDependant
                      (this,*(CMwNod **)((int)pGStack_c0 + 0x19c),(CMwNod *)in_stack_ffffff28);
          }
          pLVar12 = *(LocatedGmSurf **)(this + 0x50);
          local_bc = pLVar12;
        }
        else {
          pLVar12 = *(LocatedGmSurf **)((int)pGStack_c0 + 400);
        }
        pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 (**(code **)(*(int *)pLVar12 + 8))();
        pLStack_ac = aLStack_58;
        pGStack_a4 = (GmBoxAligned *)local_88;
        ppiStack_a8 = local_9c;
        pTVar17 = (TiXmlAttributeSet *)pLVar12;
        local_b0 = pCVar8;
        pvStack_c4 = (void *)CPlugSurface::ComputeCollision
                                       ((LocatedGmSurf *)&local_b0,pLVar12,
                                        (CGmCollisionBuffer *)in_stack_ffffff28);
        if (pvStack_c4 != (void *)0x0) {
          if ((local_bc != (LocatedGmSurf *)0x0) && (*(int *)(local_bc + 0x10) == 0)) {
            pTVar17 = (TiXmlAttributeSet *)&local_bc;
            *(int *)(local_bc + 0x10) = 1;
            CFastBuffer<class_CDx9TextureKeeper*>::Add
                      ((void *)((int)pGStack_c0 + 0x1a0),pTVar17,(TiXmlAttribute *)in_stack_ffffff28
                      );
          }
          pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount
                             (pLVar12 + 4,(CFastBuffer<class_CCrystalFace*> *)pTVar17);
          pCVar8 = local_b4;
          for (; local_b4 = pCVar8, pCVar3 < pCVar4; pCVar3 = pCVar3 + 1) {
            pSVar5 = CFastBuffer<struct_SHmsPhysicalCollision>::operator[]
                               (pLVar12 + 4,pCVar3,(ulong)pTVar17);
            *(CMwNod **)(pSVar5 + 4) = this;
            *(int **)(pSVar5 + 0xc) = local_b8;
            *(undefined4 *)pSVar5 = *(undefined4 *)((int)pGStack_c0 + 0x188);
            *(undefined4 *)(pSVar5 + 8) = *(undefined4 *)((int)pGStack_c0 + 0x18c);
            *(undefined4 *)(pSVar5 + 0x48) = *(undefined4 *)((int)pGStack_c0 + 0x184);
            pCVar8 = local_b4;
          }
        }
      }
      pGVar6 = (GmBoxAligned *)(**(code **)(*local_b8 + 0x7c))();
      local_b4 = (CMwNod *)pGVar6;
      if ((pCVar8 != (CMwNod *)0x0) &&
         (pGVar13 = (GmBoxAligned *)0x0, pGVar6 != (GmBoxAligned *)0x0)) {
        pLStack_ac = aLStack_58;
        pGStack_a4 = (GmBoxAligned *)local_88;
        local_b0 = this;
        do {
          pGVar16 = pGVar13;
          pLStack_ac = (LocatedGmSurf *)(**(code **)(*local_b8 + 0x80))();
          iVar2 = ComputeCollisionTree1RootOnly(pvStack_c4,(SZone *)&local_b4,aSStack_2c,pGVar16);
          if ((iVar2 != 0) || (bVar15 = pvStack_c4 != (void *)0x0, pvStack_c4 = (void *)0x0, bVar15)
             ) {
            pvStack_c4 = (void *)0x1;
          }
          pGVar13 = pGVar13 + 1;
        } while (pGVar13 < pGVar6);
      }
      pGVar6 = (GmBoxAligned *)(**(code **)(*(int *)this + 0x7c))();
      pLVar12 = local_bc;
      pGStack_a4 = pGVar6;
      if ((pvStack_a0 != (void *)0x0) &&
         (pGVar13 = (GmBoxAligned *)0x0, pGVar6 != (GmBoxAligned *)0x0)) {
        local_b0 = local_5c;
        ppiStack_a8 = &piStack_8c;
        pLStack_ac = local_bc;
        do {
          pGVar16 = pGVar13;
          local_b8 = (int *)(**(code **)(*(int *)this + 0x80))();
          iVar2 = ComputeCollisionTree2RootOnly(local_c8,(SZone *)&local_b8,aSStack_18,pGVar16);
          if ((iVar2 != 0) || (bVar15 = local_c8 != (void *)0x0, local_c8 = (void *)0x0, bVar15)) {
            local_c8 = (void *)0x1;
          }
          pGVar13 = pGVar13 + 1;
        } while (pGVar13 < pGVar6);
      }
      pGStack_c0 = (GmBoxAligned *)0x0;
      if (pGVar6 == (GmBoxAligned *)0x0) {
        ExceptionList = param_1;
        return (int)local_c8;
      }
      do {
        piVar14 = (int *)0x0;
        if (local_b8 != (int *)0x0) {
          do {
            uVar7 = (**(code **)(*(int *)pLVar12 + 0x80))();
            local_98 = (**(code **)(*(int *)this + 0x80))();
            piStack_8c = local_88;
            pLStack_94 = aLStack_58;
            uStack_90 = uVar7;
            iVar2 = ComputeCollision((LocatedGmSurf *)&local_98,(LocatedGmSurf *)in_stack_ffffff28,
                                     pCVar18);
            if ((iVar2 != 0) || (bVar15 = local_c8 != (void *)0x0, local_c8 = (void *)0x0, bVar15))
            {
              local_c8 = (void *)0x1;
            }
            piVar14 = (int *)((int)piVar14 + 1);
            pGVar6 = pGStack_a4;
          } while (piVar14 < local_b8);
        }
        pGStack_c0 = pGStack_c0 + 1;
      } while (pGStack_c0 < pGVar6);
      ExceptionList = param_1;
      return (int)local_c8;
    }
  }
  ExceptionList = param_1;
  return 0;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::ComputeCollisionTree1RootOnly
// =================================================
int __thiscall
CHmsCollisionManager::SZone::ComputeCollisionTree1RootOnly
          (void *this,SZone *param_1,SPlugTreeLocatedPair *param_2,GmBoxAligned *param_3)
{
{
  int *piVar1;
  LocatedGmSurf *pLVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  SCasterCat *pSVar5;
  GmBoxAligned *pGVar6;
  SHmsSphereBufferContact *unaff_EBX;
  GmIso3 *unaff_EBP;
  GmIso4 *unaff_ESI;
  int *piVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  GmBoxAligned *unaff_EDI;
  int *piVar9;
  LocatedGmSurf *pLVar10;
  GmBoxAligned *pGVar11;
  bool bVar12;
  void *unaff_retaddr;
  SPlugTreeLocatedPair *in_stack_00000010;
  int in_stack_00000014;
  GmBoxAligned *pGVar13;
  ulong uVar14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_80;
  CMwNod *local_78;
  LocatedGmSurf *local_74;
  int local_70;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_6c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_68;
  int iStack_64;
  undefined4 uStack_60;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_5c;
  undefined1 *puStack_58;
  undefined4 local_54;
  undefined1 *local_50 [7];
  undefined1 auStack_34 [4];
  int local_30;
  undefined1 auStack_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a9560b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = *(int **)(param_1 + 8);
  if ((*(byte *)(piVar1 + 0x27) & 0x80) != 0) {
    GmBoxAligned::SetMult
              (&local_54,(SPlugFaceCull *)(piVar1 + 0xd),*(SPlugFaceCull **)(param_1 + 0xc),
               (GmIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffff64));
    iVar3 = GmBoxAligned::TestInter(local_50,(CPlugVolumeProjector *)param_3,unaff_EDI,unaff_ESI);
    if (iVar3 != 0) {
      iVar3 = 0xc;
      if ((*(byte *)(piVar1 + 0x27) & 4) == 0) {
        piVar7 = *(int **)(param_1 + 0xc);
        piVar9 = &local_30;
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar9 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar9 = piVar9 + 1;
        }
      }
      else {
        piVar7 = piVar1 + 0x17;
        piVar9 = &local_30;
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar9 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar9 = piVar9 + 1;
        }
        GmIso4::Mult(&local_30,*(GmIso3 **)(in_stack_00000010 + 0xc),unaff_EBP);
      }
      local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)piVar1[0x23];
      local_70 = *(int *)(local_78 + 0x8c);
      if (local_6c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        iVar3 = *(int *)(*(int *)(local_70 + 0x14) + 0x34);
        local_74 = (LocatedGmSurf *)0x0;
        if ((*(char *)(iVar3 + 6) == '\0') || (*(char *)(iVar3 + 6) == '\x01')) {
          if (*(int *)(local_78 + 0x50) == 0) {
            local_68 = operator_new(0x14);
            if (local_68 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              uVar4 = 0;
            }
            else {
              SHmsSphereBufferContact::SHmsSphereBufferContact(local_68,unaff_EBX);
              uVar4 = extraout_EAX;
            }
            *(undefined4 *)(local_78 + 0x50) = uVar4;
            param_3 = (GmBoxAligned *)0xffffffff;
            CMwNod::MwAddDependant(local_78,*(CMwNod **)((int)this + 0x19c),(CMwNod *)unaff_EBX);
          }
          pLVar10 = *(LocatedGmSurf **)(local_78 + 0x50);
          local_74 = pLVar10;
        }
        else {
          pLVar10 = *(LocatedGmSurf **)((int)this + 400);
        }
        pLVar2 = local_74;
        local_68 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   (**(code **)(*(int *)pLVar10 + 8))();
        uStack_60 = *(undefined4 *)(in_stack_00000014 + 4);
        iStack_64 = local_70;
        puStack_58 = auStack_2c;
        pCStack_5c = local_6c;
        iVar3 = CPlugSurface::ComputeCollision
                          ((LocatedGmSurf *)&iStack_64,pLVar10,(CGmCollisionBuffer *)unaff_EBX);
        if (iVar3 != 0) {
          if ((pLVar2 != (LocatedGmSurf *)0x0) && (*(int *)(pLVar2 + 0x10) == 0)) {
            *(undefined4 *)(pLVar2 + 0x10) = 1;
            CFastBuffer<class_CDx9TextureKeeper*>::Add
                      ((void *)((int)this + 0x1a0),(TiXmlAttributeSet *)&local_74,
                       (TiXmlAttribute *)unaff_EBX);
          }
          uVar14 = 0x53a589;
          local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     (**(code **)(*(int *)pLVar10 + 8))();
          if (local_68 < local_6c) {
            pCVar8 = local_68;
            do {
              pSVar5 = CFastBuffer<struct_SHmsPhysicalCollision>::operator[]
                                 (pLVar10 + 4,pCVar8,uVar14);
              *(CMwNod **)(pSVar5 + 4) = local_78;
              *(int **)(pSVar5 + 0xc) = piVar1;
              *(undefined4 *)pSVar5 = *(undefined4 *)((int)this + 0x188);
              *(undefined4 *)(pSVar5 + 8) = *(undefined4 *)((int)this + 0x18c);
              pCVar8 = pCVar8 + 1;
              *(undefined4 *)(pSVar5 + 0x48) = *(undefined4 *)((int)this + 0x184);
            } while (pCVar8 < local_6c);
          }
        }
      }
      pGVar6 = (GmBoxAligned *)(**(code **)(*piVar1 + 0x7c))();
      pGVar11 = (GmBoxAligned *)0x0;
      if (pGVar6 == (GmBoxAligned *)0x0) {
        ExceptionList = unaff_retaddr;
        return (int)pCStack_80;
      }
      do {
        pGVar13 = pGVar11;
        local_54 = (**(code **)(*piVar1 + 0x80))();
        pCStack_5c = pCStack_80;
        puStack_58 = *(undefined1 **)(param_3 + 4);
        local_50[0] = auStack_34;
        iVar3 = ComputeCollisionTree1RootOnly(this,(SZone *)&pCStack_5c,in_stack_00000010,pGVar13);
        if ((iVar3 != 0) ||
           (bVar12 = pCStack_80 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
           pCStack_80 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0, bVar12)) {
          pCStack_80 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
        }
        pGVar11 = pGVar11 + 1;
      } while (pGVar11 < pGVar6);
      ExceptionList = unaff_retaddr;
      return (int)pCStack_80;
    }
  }
  ExceptionList = unaff_retaddr;
  return 0;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::ComputeCollisionTree2RootOnly
// =================================================
int __thiscall
CHmsCollisionManager::SZone::ComputeCollisionTree2RootOnly
          (void *this,SZone *param_1,SPlugTreeLocatedPair *param_2,GmBoxAligned *param_3)
{
{
  CMwNod *this_00;
  LocatedGmSurf *pLVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  SCasterCat *pSVar4;
  SHmsSphereBufferContact *unaff_EBX;
  GmIso3 *unaff_EBP;
  GmIso4 *unaff_ESI;
  CMwNod *pCVar5;
  undefined4 *puVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  GmBoxAligned *unaff_EDI;
  undefined4 *puVar8;
  LocatedGmSurf *pLVar9;
  GmBoxAligned *pGVar10;
  bool bVar11;
  void *unaff_retaddr;
  SPlugTreeLocatedPair *in_stack_00000010;
  int in_stack_00000014;
  GmBoxAligned *pGVar12;
  TiXmlAttributeSet *pTVar13;
  int iStack_80;
  int local_78;
  LocatedGmSurf *local_74;
  int local_70;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_6c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_68;
  int iStack_64;
  undefined1 *puStack_60;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_5c;
  undefined1 *puStack_58;
  int local_54;
  undefined4 local_50 [7];
  undefined1 auStack_34 [4];
  undefined4 local_30;
  undefined1 auStack_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a9563b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = *(CMwNod **)param_1;
  if (((byte)this_00[0x9c] & 0x80) != 0) {
    GmBoxAligned::SetMult
              (&local_54,(SPlugFaceCull *)(this_00 + 0x34),*(SPlugFaceCull **)(param_1 + 4),
               (GmIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffff64));
    iVar2 = GmBoxAligned::TestInter(local_50,(CPlugVolumeProjector *)param_3,unaff_EDI,unaff_ESI);
    if (iVar2 != 0) {
      iVar2 = 0xc;
      if (((byte)this_00[0x9c] & 4) == 0) {
        puVar6 = *(undefined4 **)(param_1 + 4);
        puVar8 = &local_30;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      else {
        pCVar5 = this_00 + 0x5c;
        puVar6 = &local_30;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *(undefined4 *)pCVar5;
          pCVar5 = pCVar5 + 4;
          puVar6 = puVar6 + 1;
        }
        GmIso4::Mult(&local_30,*(GmIso3 **)(in_stack_00000010 + 4),unaff_EBP);
      }
      local_70 = *(int *)(this_00 + 0x8c);
      local_6c = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(local_78 + 0x8c);
      if (local_70 != 0) {
        iVar2 = *(int *)(*(int *)(local_70 + 0x14) + 0x34);
        local_74 = (LocatedGmSurf *)0x0;
        if ((*(char *)(iVar2 + 6) == '\0') || (*(char *)(iVar2 + 6) == '\x01')) {
          if (*(int *)(this_00 + 0x50) == 0) {
            local_68 = operator_new(0x14);
            if (local_68 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              uVar3 = 0;
            }
            else {
              SHmsSphereBufferContact::SHmsSphereBufferContact(local_68,unaff_EBX);
              uVar3 = extraout_EAX;
            }
            *(undefined4 *)(this_00 + 0x50) = uVar3;
            CMwNod::MwAddDependant(this_00,*(CMwNod **)((int)this + 0x19c),(CMwNod *)unaff_EBX);
          }
          pLVar9 = *(LocatedGmSurf **)(this_00 + 0x50);
          local_74 = pLVar9;
        }
        else {
          pLVar9 = *(LocatedGmSurf **)((int)this + 400);
        }
        pLVar1 = local_74;
        local_68 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   (**(code **)(*(int *)pLVar9 + 8))();
        iStack_64 = local_70;
        puStack_60 = auStack_2c;
        pCStack_5c = local_6c;
        puStack_58 = *(undefined1 **)(in_stack_00000014 + 0xc);
        pTVar13 = (TiXmlAttributeSet *)pLVar9;
        iVar2 = CPlugSurface::ComputeCollision
                          ((LocatedGmSurf *)&iStack_64,pLVar9,(CGmCollisionBuffer *)unaff_EBX);
        if (iVar2 != 0) {
          if ((pLVar1 != (LocatedGmSurf *)0x0) && (*(int *)(pLVar1 + 0x10) == 0)) {
            pTVar13 = (TiXmlAttributeSet *)&local_74;
            *(undefined4 *)(pLVar1 + 0x10) = 1;
            CFastBuffer<class_CDx9TextureKeeper*>::Add
                      ((void *)((int)this + 0x1a0),pTVar13,(TiXmlAttribute *)unaff_EBX);
          }
          local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     CFastBuffer<class_CCrystalFace*>::GetCount
                               (pLVar9 + 4,(CFastBuffer<class_CCrystalFace*> *)pTVar13);
          pCVar7 = local_68;
          if (local_68 < local_6c) {
            do {
              pSVar4 = CFastBuffer<struct_SHmsPhysicalCollision>::operator[]
                                 (pLVar9 + 4,pCVar7,(ulong)pTVar13);
              *(CMwNod **)(pSVar4 + 4) = this_00;
              *(int *)(pSVar4 + 0xc) = local_78;
              *(undefined4 *)pSVar4 = *(undefined4 *)((int)this + 0x188);
              *(undefined4 *)(pSVar4 + 8) = *(undefined4 *)((int)this + 0x18c);
              pCVar7 = pCVar7 + 1;
              *(undefined4 *)(pSVar4 + 0x48) = *(undefined4 *)((int)this + 0x184);
            } while (pCVar7 < local_6c);
          }
        }
      }
      local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 (**(code **)(*(int *)this_00 + 0x7c))();
      pGVar10 = (GmBoxAligned *)0x0;
      if (local_6c == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        ExceptionList = unaff_retaddr;
        return iStack_80;
      }
      do {
        uVar3 = *(undefined4 *)(in_stack_00000010 + 0xc);
        pGVar12 = pGVar10;
        pCStack_5c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     (**(code **)(*(int *)this_00 + 0x80))();
        puStack_58 = auStack_34;
        local_54 = iStack_80;
        local_50[0] = uVar3;
        iVar2 = ComputeCollisionTree2RootOnly(this,(SZone *)&pCStack_5c,in_stack_00000010,pGVar12);
        if ((iVar2 != 0) || (bVar11 = iStack_80 != 0, iStack_80 = 0, bVar11)) {
          iStack_80 = 1;
        }
        pGVar10 = pGVar10 + 1;
      } while (pGVar10 < local_6c);
      ExceptionList = unaff_retaddr;
      return iStack_80;
    }
  }
  ExceptionList = unaff_retaddr;
  return 0;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::DetectCollisionBetween
// =================================================
void __thiscall
CHmsCollisionManager::SZone::DetectCollisionBetween
          (void *this,SZone *param_1,CHmsCorpus *param_2,CHmsCorpus *param_3)
{
{
  CGmCollisionBuffer *unaff_ESI;
  LocatedGmSurf *unaff_EDI;
  undefined4 local_10;
  SZone *local_c;
  undefined4 local_8;
  CHmsCorpus *local_4;
  
  *(SZone **)((int)this + 0x188) = param_1;
  *(CHmsCorpus **)((int)this + 0x18c) = param_2;
  if (*(int *)(param_2 + 0x58) == 0) {
    local_4 = param_2 + 0x18;
  }
  else {
    local_4 = (CHmsCorpus *)(*(int *)(*(int *)(param_2 + 0x58) + 0x32c) + 0x10);
  }
  local_8 = *(undefined4 *)(*(int *)(*(int *)(param_2 + 0x48) + 0x14) + 100);
  if (*(int *)(param_1 + 0x58) == 0) {
    local_c = param_1 + 0x18;
  }
  else {
    local_c = (SZone *)(*(int *)(*(int *)(param_1 + 0x58) + 0x32c) + 0x10);
  }
  local_10 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 100);
  ComputeCollision((LocatedGmSurf *)&local_10,unaff_EDI,unaff_ESI);
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::DetectCollisionBetweenTreeAndStaticCollisionTree
// =================================================
void __thiscall
CHmsCollisionManager::SZone::DetectCollisionBetweenTreeAndStaticCollisionTree
          (void *this,SZone *param_1,GmIso4 *param_2,CPlugTree *param_3)
{
{
  GmIso4 *this_00;
  CPlugTree *pCVar1;
  GmIso4 *pGVar2;
  int iVar3;
  CHmsCollisionBuffer *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  int iVar7;
  void *unaff_EBX;
  SZone *this_01;
  LocatedGmSurf *pLVar8;
  SZone *pSVar9;
  CMwNod *unaff_EBP;
  CMwNod *unaff_ESI;
  CPlugTree *pCVar10;
  SZone *pSVar11;
  LocatedGmSurf *pLVar12;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *puVar13;
  int *piVar14;
  CHmsCollisionBuffer *in_stack_00000010;
  LocatedGmSurf *in_stack_00000018;
  CPlugTree *pCVar15;
  ulong uVar16;
  GmIso4 *pGVar17;
  GmBoxAligned *pGVar18;
  int iStack_70;
  SZone *pSStack_6c;
  undefined4 uStack_64;
  undefined4 *puStack_60;
  int iStack_5c;
  int *piStack_58;
  undefined1 auStack_54 [20];
  SZone aSStack_40 [4];
  undefined4 local_3c [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  this_00 = param_2;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a955db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((char)*(uint *)(param_2 + 0x9c) < '\0') {
    iVar7 = 0xc;
    puVar13 = local_3c;
    pSVar9 = param_1;
    if ((*(uint *)(param_2 + 0x9c) & 4) == 0) {
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar13 = *(undefined4 *)pSVar9;
        pSVar9 = pSVar9 + 4;
        puVar13 = puVar13 + 1;
      }
    }
    else {
      pGVar17 = param_2 + 0x5c;
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar13 = *(undefined4 *)pGVar17;
        pGVar17 = pGVar17 + 4;
        puVar13 = puVar13 + 1;
      }
      GmIso4::Mult(local_3c,(GmIso3 *)param_1,(GmIso3 *)(DAT_00cca150 ^ (uint)&stack0xffffff7c));
    }
    pGVar17 = (GmIso4 *)0x53a193;
    pCVar1 = (CPlugTree *)(**(code **)(*(int *)this_00 + 0x7c))();
    pCVar10 = (CPlugTree *)0x0;
    if (pCVar1 != (CPlugTree *)0x0) {
      do {
        pCVar15 = pCVar10;
        pGVar2 = (GmIso4 *)(**(code **)(*(int *)this_00 + 0x80))();
        DetectCollisionBetweenTreeAndStaticCollisionTree(unaff_EBX,aSStack_40,pGVar2,pCVar15);
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < pCVar1);
    }
    if (*(int *)(this_00 + 0x8c) != 0) {
      GmBoxAligned::SetMult
                (auStack_54,(SPlugFaceCull *)(this_00 + 0x34),(SPlugFaceCull *)param_1,pGVar17);
      iVar7 = *(int *)(iStack_70 + 0x194);
      this_01 = (SZone *)(iVar7 + 0x30);
      pSVar11 = (SZone *)0x0;
      param_2 = (GmIso4 *)0x0;
      pGVar18 = (GmBoxAligned *)0x53a200;
      puStack_60 = (undefined4 *)CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_EDI);
      pSVar9 = this_01;
      if (puStack_60 != (undefined4 *)0x0) {
        do {
          piVar14 = (int *)((int)pSVar11 * 0x58 + *(int *)(pSVar9 + 4));
          iVar3 = GmBoxAligned::TestInter
                            (auStack_54,(CPlugVolumeProjector *)(piVar14 + 1),pGVar18,
                             (GmIso4 *)unaff_EDI);
          if (iVar3 == 0) {
            pSVar11 = pSVar11 + *piVar14;
          }
          else {
            if ((piVar14[0x13] != 0) && ((*(byte *)(piVar14[0x14] + 0x9c) & 0x80) != 0)) {
              in_stack_00000010 = (CHmsCollisionBuffer *)0x0;
              if ((*(char *)(*(int *)(*(int *)(*(int *)(this_00 + 0x8c) + 0x14) + 0x34) + 6) == '\0'
                  ) || (*(char *)(*(int *)(*(int *)(*(int *)(this_00 + 0x8c) + 0x14) + 0x34) + 6) ==
                        '\x01')) {
                if (*(int *)(this_00 + 0x50) == 0) {
                  pGVar18 = (GmBoxAligned *)0x53a289;
                  pCVar4 = operator_new(0x14);
                  param_1 = (SZone *)0x0;
                  in_stack_00000010 = pCVar4;
                  if (pCVar4 == (CHmsCollisionBuffer *)0x0) {
                    pCVar4 = (CHmsCollisionBuffer *)0x0;
                  }
                  else {
                    CHmsCollisionBuffer::CHmsCollisionBuffer
                              (pCVar4,(CHmsCollisionBuffer *)unaff_ESI);
                    *(undefined4 *)(pCVar4 + 0x10) = 0;
                  }
                  *(CHmsCollisionBuffer **)(this_00 + 0x50) = pCVar4;
                  unaff_ESI = *(CMwNod **)(iVar7 + 0x1cc);
                  param_2 = (GmIso4 *)0xffffffff;
                  unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x53a2d0;
                  CMwNod::MwAddDependant((CMwNod *)this_00,unaff_ESI,unaff_EBP);
                }
                pLVar8 = *(LocatedGmSurf **)(this_00 + 0x50);
                pLVar12 = pLVar8;
                in_stack_00000018 = pLVar8;
              }
              else {
                pLVar8 = *(LocatedGmSurf **)(pSStack_6c + 400);
                pLVar12 = (LocatedGmSurf *)0x0;
              }
              unaff_EBP = (CMwNod *)0x53a2e5;
              pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       (**(code **)(*(int *)pLVar8 + 8))();
              uStack_64 = *(undefined4 *)(this_00 + 0x8c);
              puStack_60 = local_3c;
              iStack_5c = piVar14[0x13];
              piStack_58 = piVar14 + 7;
              iVar3 = CPlugSurface::ComputeCollision
                                ((LocatedGmSurf *)&uStack_64,pLVar8,(CGmCollisionBuffer *)pGVar18);
              if (iVar3 != 0) {
                if ((pLVar12 != (LocatedGmSurf *)0x0) && (*(int *)(pLVar12 + 0x10) == 0)) {
                  *(undefined4 *)(pLVar12 + 0x10) = 1;
                  CFastBuffer<class_CDx9TextureKeeper*>::Add
                            ((void *)((int)this + 0x1a0),(TiXmlAttributeSet *)&param_2,
                             (TiXmlAttribute *)pGVar18);
                }
                uVar16 = 0x53a34c;
                param_2 = (GmIso4 *)(**(code **)(*(int *)pLVar8 + 8))();
                if (pCVar5 < param_2) {
                  do {
                    pSVar6 = CFastBuffer<struct_SHmsPhysicalCollision>::operator[]
                                       (pLVar8 + 4,pCVar5,uVar16);
                    *(GmIso4 **)(pSVar6 + 4) = this_00;
                    *(int *)(pSVar6 + 0xc) = piVar14[0x14];
                    *(undefined4 *)pSVar6 = *(undefined4 *)((int)this + 0x188);
                    *(int *)(pSVar6 + 8) = piVar14[0x15];
                    pCVar5 = pCVar5 + 1;
                    *(undefined4 *)(pSVar6 + 0x48) = *(undefined4 *)((int)this + 0x184);
                  } while (pCVar5 < param_2);
                }
              }
            }
            pSVar11 = param_1 + 1;
            pSVar9 = pSStack_6c;
          }
          param_1 = pSVar11;
        } while (pSVar11 < this_01);
      }
    }
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::DetectCollisionsCorpus
// =================================================
void __thiscall
CHmsCollisionManager::SZone::DetectCollisionsCorpus
          (void *this,SZone *param_1,CHmsCollisionBuffer *param_2,CHmsCorpus *param_3)
{
{
  CSystemData *this_00;
  CSystemData *pCVar1;
  CHmsCorpus *pCVar2;
  int iVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  CMwNod *pCVar6;
  SCasterCat *pSVar7;
  SZone *pSVar8;
  CHmsCollisionBuffer *unaff_EBX;
  SHmsSphereBufferContact *unaff_EBP;
  CHmsCorpus *unaff_ESI;
  CSystemData *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  void *this_02;
  CFastBuffer<class_CCrystalFace*> *pCVar11;
  CHmsCorpus *pCVar12;
  
  *(SZone **)((int)this + 400) = param_1;
  pCVar1 = *(CSystemData **)(param_2 + 0x54);
  this_00 = (CSystemData *)
            ((int)this + (*(uint *)(*(int *)(param_2 + 0x48) + 0x18) >> 0xd & 0xf) * 0x44 + -0x20);
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  param_3 = (CHmsCorpus *)0x0;
  this_01 = this_00;
  if (uVar4 != 0) {
    do {
      pCVar11 = (CFastBuffer<class_CCrystalFace*> *)0x53b230;
      pCVar12 = param_3;
      pSVar5 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                         (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3,
                          (ulong)unaff_ESI);
      *(undefined4 *)((int)this + 0x184) = *(undefined4 *)(pSVar5 + 4);
      pCVar2 = *(CHmsCorpus **)(pSVar5 + 0x10);
      pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar2 != (CHmsCorpus *)0x0) {
        do {
          pCVar6 = CFastRectTable<int>::Get
                             (pSVar5 + 8,this_00,(CSystemFid *)pCVar9,(CSystemFid *)pCVar11,
                              (ulong *)pCVar12);
          if (*(int *)pCVar6 != 0) {
            pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(*(int *)pSVar5 + 0xc),pCVar9,(ulong)unaff_ESI);
            unaff_ESI = *(CHmsCorpus **)pSVar7;
            pCVar11 = (CFastBuffer<class_CCrystalFace*> *)0x53b271;
            pCVar12 = (CHmsCorpus *)param_2;
            DetectCollisionBetween(this,(SZone *)param_2,unaff_ESI,(CHmsCorpus *)unaff_EBP);
          }
          pCVar9 = pCVar9 + 1;
        } while (pCVar9 < pCVar1);
      }
      iVar3 = *(int *)pSVar5;
      *(int *)((int)this + 0x194) = iVar3;
      uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar3 + 0x30),pCVar11);
      if (1 < uVar4) {
        *(CHmsCollisionBuffer **)((int)this + 0x188) = param_2;
        if (*(int *)(param_2 + 0x58) == 0) {
          pSVar8 = (SZone *)(param_2 + 0x18);
        }
        else {
          pSVar8 = (SZone *)(*(int *)(*(int *)(param_2 + 0x58) + 0x32c) + 0x10);
        }
        DetectCollisionBetweenTreeAndStaticCollisionTree
                  (this,pSVar8,*(GmIso4 **)(*(int *)(*(int *)(param_2 + 0x48) + 0x14) + 100),
                   (CPlugTree *)pCVar12);
      }
      param_3 = param_3 + 1;
      param_1 = (SZone *)param_2;
      this_01 = pCVar1;
    } while (param_3 < pCVar2);
  }
  this_02 = (void *)((int)this + 0x1a0);
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_02,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar9 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_02,pCVar10,(ulong)unaff_EBP);
      unaff_EBP = (SHmsSphereBufferContact *)param_1;
      SHmsSphereBufferContact::MergeAndAddToCollisions
                (*(void **)pSVar5,(SHmsSphereBufferContact *)param_1,unaff_EBX);
      pCVar10 = pCVar10 + 1;
    } while (pCVar10 < pCVar9);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_02,(GmFrustumIso4 *)unaff_EBP);
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::IntersectSegment
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CHmsCollisionManager::SZone::IntersectSegment
          (void *this,SZone *param_1,ECollisionGroup param_2,GmVec3 *param_3,GmVec3 *param_4,
          float *param_5,CPlugTree **param_6)
{
{
  GmVec3 *pGVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  SCasterCat *pSVar5;
  CPlugTree *pCVar6;
  int iVar7;
  float *unaff_EBX;
  uint uVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  GmIso4 *unaff_EBP;
  GmSurf *unaff_ESI;
  int *piVar10;
  GmVec3 *pGVar11;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  GmVec3 *in_stack_0000001c;
  float *in_stack_00000020;
  undefined4 *in_stack_00000024;
  float *in_stack_0000002c;
  int *in_stack_00000030;
  float local_8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_4;
  
  pGVar1 = param_3;
  uVar8 = 0;
  local_8 = *(float *)(param_3 + 4) + *(float *)(param_2 + 4);
  local_4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
            (*(float *)(param_3 + 8) + *(float *)(param_2 + 8));
  *(undefined4 *)param_4 = _DAT_00b55da0;
  pGVar11 = (GmVec3 *)((int)this + (int)param_1 * 0x44);
  param_3 = pGVar11;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(pGVar11 + -0x14,unaff_EDI);
  if (uVar2 != 0) {
    do {
      piVar10 = (int *)(uVar8 * 0x58 + *(int *)(param_4 + -0x10));
      uVar3 = GmBoxAligned::TestInterSegment
                        (piVar10 + 1,(GmRectAligned *)param_2,(GmVec2 *)&local_8,(GmVec2 *)unaff_ESI
                        );
      if (uVar3 == 0) {
        uVar8 = uVar8 + *piVar10;
      }
      else {
        if ((piVar10[0x13] != 0) &&
           (iVar4 = *(int *)(piVar10[0x13] + 0x14), *(int *)(iVar4 + 0x34) != 0)) {
          unaff_ESI = (GmSurf *)&param_3;
          iVar4 = GmSurf::ClipSegment(unaff_ESI,(GmSurfSphere *)param_2,pGVar1,
                                      *(GmVec3 **)(iVar4 + 0x34),(GmVec3 *)(piVar10 + 7),
                                      (float *)unaff_ESI);
          if ((iVar4 != 0) && ((float)in_stack_00000020 < *in_stack_0000002c)) {
            *in_stack_0000002c = (float)in_stack_00000020;
            in_stack_00000024 = (undefined4 *)0x1;
            if (in_stack_00000030 != (int *)0x0) {
              *in_stack_00000030 = piVar10[0x14];
            }
          }
        }
        uVar8 = uVar8 + 1;
      }
      pGVar11 = param_4;
    } while (uVar8 < uVar2);
  }
  pGVar11 = pGVar11 + -0x38;
  param_4 = pGVar11;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (pGVar11,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uVar2 != 0) {
    do {
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pGVar11,pCVar9,(ulong)unaff_EBP);
      iVar4 = *(int *)pSVar5;
      if (*(int *)(iVar4 + 0x58) == 0) {
        pCVar6 = (CPlugTree *)(iVar4 + 0x18);
      }
      else {
        pCVar6 = (CPlugTree *)(*(int *)(*(int *)(iVar4 + 0x58) + 0x32c) + 0x10);
      }
      unaff_EBP = (GmIso4 *)&param_4;
      iVar7 = IntersectSegmentTree
                        (local_4,(SZone *)param_2,pGVar1,
                         *(GmVec3 **)(*(int *)(*(int *)(iVar4 + 0x48) + 0x14) + 100),pCVar6,
                         unaff_EBP,unaff_EBX);
      if ((iVar7 != 0) && ((float)param_5 < *in_stack_00000020)) {
        *in_stack_00000020 = (float)param_5;
        param_6 = (CPlugTree **)0x1;
        if (in_stack_00000024 != (undefined4 *)0x0) {
          *in_stack_00000024 = *(undefined4 *)(*(int *)(*(int *)(iVar4 + 0x48) + 0x14) + 100);
        }
      }
      pCVar9 = pCVar9 + 1;
      pGVar11 = in_stack_0000001c;
    } while (pCVar9 < local_4);
  }
  return (int)param_4;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::IntersectSegment2
// =================================================
int __thiscall
CHmsCollisionManager::SZone::IntersectSegment2
          (void *this,SZone *param_1,ECollisionGroup param_2,GmVec3 *param_3,GmVec3 *param_4,
          int param_5,float *param_6,GmVec3 *param_7)
{
{
  GmVec3 *pGVar1;
  ulong uVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  int iVar5;
  CPlugTree *pCVar6;
  GmVec3 *unaff_EBX;
  undefined1 *unaff_EBP;
  uint uVar7;
  GmVec2 *unaff_ESI;
  int *piVar8;
  void *pvVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong uStack00000020;
  float *in_stack_00000024;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000028;
  float *in_stack_00000034;
  void *local_20;
  float local_14;
  void *local_10;
  float local_4;
  
  uVar7 = 0;
  local_14 = *(float *)(param_3 + 4) + *(float *)(param_2 + 4);
  local_10 = (void *)(*(float *)(param_3 + 8) + *(float *)(param_2 + 8));
  pvVar9 = (void *)((int)this + (int)param_1 * 0x44);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)pvVar9 + -0x14),unaff_EDI);
  pGVar1 = param_7;
  if (uVar2 != 0) {
    do {
      piVar8 = (int *)(uVar7 * 0x58 + *(int *)((int)local_20 + -0x10));
      uVar3 = GmBoxAligned::TestInterSegment
                        (piVar8 + 1,(GmRectAligned *)param_2,(GmVec2 *)&local_14,unaff_ESI);
      if (uVar3 == 0) {
        uVar7 = uVar7 + *piVar8;
      }
      else {
        if ((piVar8[0x13] != 0) &&
           (iVar5 = *(int *)(piVar8[0x13] + 0x14), *(int *)(iVar5 + 0x34) != 0)) {
          unaff_ESI = (GmVec2 *)(piVar8 + 7);
          iVar5 = GmSurf::ClipSegment2
                            ((GmSurf *)&param_3,(GmSurfMesh *)param_2,(GmVec3 *)param_5,
                             (GmVec3 *)param_6,(int)&param_3,&local_4,*(GmVec3 **)(iVar5 + 0x34));
          if (iVar5 != 0) {
            if (in_stack_00000028 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              *in_stack_00000034 = (float)in_stack_00000024;
              in_stack_00000028 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
            }
            else {
              if (*in_stack_00000034 <= (float)in_stack_00000024) goto LAB_00539e30;
              *in_stack_00000034 = (float)in_stack_00000024;
            }
            *(int *)pGVar1 = param_5;
            *(float **)(pGVar1 + 4) = param_6;
            *(GmVec3 **)(pGVar1 + 8) = param_7;
          }
        }
LAB_00539e30:
        uVar7 = uVar7 + 1;
      }
      pvVar9 = local_20;
    } while (uVar7 < uVar2);
  }
  uStack00000020 =
       CFastBuffer<class_CCrystalFace*>::GetCount
                 ((void *)((int)pvVar9 + -0x38),(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uStack00000020 != 0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)((int)pvVar9 + -0x38),pCVar10,(ulong)unaff_EBP);
      iVar5 = *(int *)pSVar4;
      if (*(int *)(iVar5 + 0x58) == 0) {
        pCVar6 = (CPlugTree *)(iVar5 + 0x18);
      }
      else {
        pCVar6 = (CPlugTree *)(*(int *)(*(int *)(iVar5 + 0x58) + 0x32c) + 0x10);
      }
      unaff_EBP = (undefined1 *)register0x00000010;
      iVar5 = IntersectSegmentTree2
                        (local_10,(SZone *)param_2,(GmVec3 *)param_6,param_7,
                         *(int *)(*(int *)(*(int *)(iVar5 + 0x48) + 0x14) + 100),pCVar6,
                         (GmIso4 *)&param_4,(float *)&stack0x00000000,unaff_EBX);
      if (iVar5 != 0) {
        if (param_6 == (float *)0x0) {
          *in_stack_00000024 = (float)param_5;
          param_6 = (float *)0x1;
        }
        else {
          if (*in_stack_00000024 <= (float)param_5) goto LAB_00539ef4;
          *in_stack_00000024 = (float)param_5;
        }
        *(SZone **)pGVar1 = param_1;
        *(undefined4 *)(pGVar1 + 4) = 0;
        *(GmVec3 **)(pGVar1 + 8) = param_3;
      }
LAB_00539ef4:
      pCVar10 = pCVar10 + 1;
    } while (pCVar10 < in_stack_00000028);
  }
  return (int)param_4;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::IntersectSegment3
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CHmsCollisionManager::SZone::IntersectSegment3
          (void *this,SZone *param_1,ECollisionGroup param_2,GmVec3 *param_3,GmVec3 *param_4,
          float *param_5,ushort *param_6)
{
{
  void *pvVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  int iVar5;
  CPlugTree *pCVar6;
  ushort *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  float **unaff_EBP;
  GmVec2 *unaff_ESI;
  int *piVar8;
  void *pvVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 in_stack_0000001c;
  float *in_stack_00000020;
  undefined2 *in_stack_00000024;
  undefined4 in_stack_00000028;
  float *in_stack_0000002c;
  ushort *in_stack_00000034;
  float fVar10;
  float local_8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_4;
  
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  fVar10 = *(float *)param_3 + *(float *)param_2;
  local_8 = *(float *)(param_3 + 4) + *(float *)(param_2 + 4);
  local_4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
            (*(float *)(param_3 + 8) + *(float *)(param_2 + 8));
  *(undefined4 *)param_4 = _DAT_00b55da0;
  pvVar1 = (void *)((int)this + (int)param_1 * 0x44);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)pvVar1 + -0x14),unaff_EDI);
  pvVar9 = pvVar1;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      piVar8 = (int *)((int)pCVar7 * 0x58 + *(int *)(param_2 - 0x10));
      uVar3 = GmBoxAligned::TestInterSegment
                        (piVar8 + 1,(GmRectAligned *)param_2,(GmVec2 *)&local_8,unaff_ESI);
      if (uVar3 == 0) {
        pCVar7 = pCVar7 + *piVar8;
      }
      else {
        if ((piVar8[0x13] != 0) &&
           (iVar5 = *(int *)(piVar8[0x13] + 0x14), *(int *)(iVar5 + 0x34) != 0)) {
          unaff_ESI = (GmVec2 *)&param_4;
          iVar5 = GmSurf::ClipSegment3
                            ((GmSurf *)(piVar8 + 7),(GmSurfMesh *)param_2,param_3,
                             *(GmVec3 **)(iVar5 + 0x34),(float *)(piVar8 + 7),
                             (ushort *)&stack0xfffffff0);
          if ((iVar5 != 0) && ((float)pvVar1 < *in_stack_0000002c)) {
            pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     ((uint)in_stack_00000024 & 0xffff);
            *in_stack_0000002c = (float)pvVar1;
            in_stack_00000028 = 1;
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(piVar8[0x13] + 0x18),pCVar2,(ulong)fVar10);
            *in_stack_00000034 = (ushort)*(byte *)(*(int *)pSVar4 + 0x18);
          }
        }
        pCVar7 = pCVar7 + 1;
      }
      pvVar9 = (void *)param_2;
    } while (pCVar7 < pCVar2);
  }
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                    ((void *)((int)pvVar9 + -0x38),(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uVar3 != 0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)((int)pvVar9 + -0x38),pCVar2,(ulong)unaff_EBP);
      iVar5 = *(int *)pSVar4;
      if (*(int *)(iVar5 + 0x58) == 0) {
        pCVar6 = (CPlugTree *)(iVar5 + 0x18);
      }
      else {
        pCVar6 = (CPlugTree *)(*(int *)(*(int *)(iVar5 + 0x58) + 0x32c) + 0x10);
      }
      unaff_EBP = &param_5;
      iVar5 = IntersectSegmentTree3
                        (local_4,(SZone *)param_2,param_3,
                         *(GmVec3 **)(*(int *)(*(int *)(iVar5 + 0x48) + 0x14) + 100),pCVar6,
                         (GmIso4 *)&param_4,(float *)unaff_EBP,unaff_EBX);
      if ((iVar5 != 0) && ((float)param_5 < *in_stack_00000020)) {
        *in_stack_00000020 = (float)param_5;
        in_stack_0000001c = 1;
        *in_stack_00000024 = param_6._0_2_;
      }
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < local_4);
  }
  return (int)param_5;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::IntersectSegmentTree
// =================================================
int __thiscall
CHmsCollisionManager::SZone::IntersectSegmentTree
          (void *this,SZone *param_1,GmVec3 *param_2,GmVec3 *param_3,CPlugTree *param_4,
          GmIso4 *param_5,float *param_6)
{
{
  ulong uVar1;
  CPlugTree *pCVar2;
  GmVec3 *pGVar3;
  int iVar4;
  GmVec2 *unaff_EBP;
  GmIso4 *unaff_ESI;
  GmVec3 *pGVar5;
  CPlugTree *pCVar6;
  GmIso3 *unaff_EDI;
  undefined4 *puVar7;
  float in_stack_0000001c;
  float *in_stack_00000020;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000030;
  undefined4 *in_stack_00000034;
  CPlugTree *pCVar8;
  float *pfVar9;
  void *local_50;
  float local_4c;
  float local_48;
  undefined1 local_44 [28];
  undefined4 local_28;
  GmVec3 local_24 [36];
  
  if (((byte)param_3[0x9c] & 0x80) == 0) {
    return 0;
  }
  GmBoxAligned::SetMult
            (&local_48,(SPlugFaceCull *)(param_3 + 0x34),(SPlugFaceCull *)param_4,unaff_ESI);
  local_50 = (void *)(*(float *)param_3 + *(float *)param_2);
  local_4c = *(float *)(param_3 + 4) + *(float *)(param_2 + 4);
  local_48 = *(float *)(param_3 + 8) + *(float *)(param_2 + 8);
  uVar1 = GmBoxAligned::TestInterSegment
                    (local_44,(GmRectAligned *)param_2,(GmVec2 *)&local_50,unaff_EBP);
  if (uVar1 != 0) {
    iVar4 = 0xc;
    pCVar2 = param_4;
    puVar7 = &local_28;
    if (((byte)param_3[0x9c] & 4) == 0) {
      for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *(undefined4 *)pCVar2;
        pCVar2 = pCVar2 + 4;
        puVar7 = puVar7 + 1;
      }
    }
    else {
      pGVar5 = param_3 + 0x5c;
      for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *(undefined4 *)pGVar5;
        pGVar5 = pGVar5 + 4;
        puVar7 = puVar7 + 1;
      }
      GmIso4::Mult(&local_28,(GmIso3 *)param_6,unaff_EDI);
    }
    if (((*(int *)(param_3 + 0x8c) != 0) &&
        (iVar4 = *(int *)(*(int *)(param_3 + 0x8c) + 0x14), *(int *)(iVar4 + 0x34) != 0)) &&
       (iVar4 = GmSurf::ClipSegment((GmSurf *)&stack0x0000001c,(GmSurfSphere *)param_2,(GmVec3 *)0x0
                                    ,*(GmVec3 **)(iVar4 + 0x34),local_24,&stack0x0000001c),
       iVar4 != 0)) {
      *in_stack_00000034 = in_stack_00000030;
      in_stack_0000002c = 1;
    }
    pCVar2 = (CPlugTree *)(**(code **)(*(int *)param_3 + 0x7c))();
    pCVar6 = (CPlugTree *)0x0;
    if (pCVar2 != (CPlugTree *)0x0) {
      do {
        pfVar9 = &stack0x0000001c;
        pGVar5 = local_24;
        pCVar8 = pCVar6;
        pGVar3 = (GmVec3 *)(**(code **)(*(int *)param_3 + 0x80))();
        iVar4 = IntersectSegmentTree
                          (local_50,(SZone *)param_2,(GmVec3 *)param_4,pGVar3,pCVar8,
                           (GmIso4 *)pGVar5,pfVar9);
        if (iVar4 != 0) {
          if (param_6 == (float *)0x0) {
            *in_stack_00000020 = in_stack_0000001c;
            param_6 = (float *)0x1;
          }
          else if (in_stack_0000001c < *in_stack_00000020) {
            *in_stack_00000020 = in_stack_0000001c;
          }
        }
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < pCVar2);
    }
    return (int)param_6;
  }
  return 0;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::IntersectSegmentTree2
// =================================================
int __thiscall
CHmsCollisionManager::SZone::IntersectSegmentTree2
          (void *this,SZone *param_1,GmVec3 *param_2,GmVec3 *param_3,int param_4,CPlugTree *param_5,
          GmIso4 *param_6,float *param_7,GmVec3 *param_8)
{
{
  ulong uVar1;
  GmVec3 *pGVar2;
  int iVar3;
  GmVec2 *unaff_EBP;
  GmIso4 *unaff_ESI;
  float *pfVar4;
  CPlugTree *pCVar5;
  GmIso3 *unaff_EDI;
  float *pfVar6;
  GmVec3 *pGVar7;
  float *in_stack_00000024;
  float *in_stack_00000028;
  undefined4 in_stack_00000034;
  undefined4 in_stack_00000038;
  undefined4 *in_stack_0000003c;
  GmVec3 *pGVar8;
  GmIso4 *pGVar9;
  GmVec3 **ppGVar10;
  GmVec3 *pGVar11;
  void *local_50;
  float local_4c;
  float local_48;
  float local_44;
  float fStack_40;
  float local_30;
  float local_2c;
  float local_28;
  GmIso4 local_24 [36];
  
  if ((*(byte *)(param_4 + 0x9c) & 0x80) == 0) {
    return 0;
  }
  GmBoxAligned::SetMult
            (&local_48,(SPlugFaceCull *)(param_4 + 0x34),(SPlugFaceCull *)param_5,unaff_ESI);
  local_50 = (void *)(*(float *)param_3 + *(float *)param_2);
  local_4c = *(float *)(param_3 + 4) + *(float *)(param_2 + 4);
  local_48 = *(float *)(param_3 + 8) + *(float *)(param_2 + 8);
  uVar1 = GmBoxAligned::TestInterSegment
                    (&local_44,(GmRectAligned *)param_2,(GmVec2 *)&local_50,unaff_EBP);
  if (uVar1 == 0) {
    return 0;
  }
  iVar3 = 0xc;
  pCVar5 = param_5;
  pfVar4 = &local_28;
  if ((*(byte *)(param_4 + 0x9c) & 4) == 0) {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar4 = *(float *)pCVar5;
      pCVar5 = pCVar5 + 4;
      pfVar4 = pfVar4 + 1;
    }
  }
  else {
    pfVar4 = (float *)(param_4 + 0x5c);
    pfVar6 = &local_28;
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar6 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      pfVar6 = pfVar6 + 1;
    }
    GmIso4::Mult(&local_28,(GmIso3 *)param_7,unaff_EDI);
  }
  if (((*(int *)(param_4 + 0x8c) != 0) &&
      (iVar3 = *(int *)(*(int *)(param_4 + 0x8c) + 0x14), *(int *)(iVar3 + 0x34) != 0)) &&
     (iVar3 = GmSurf::ClipSegment2
                        ((GmSurf *)0x0,(GmSurfMesh *)param_2,(GmVec3 *)param_5,(GmVec3 *)0x0,
                         (int)&param_8,&local_48,*(GmVec3 **)(iVar3 + 0x34)), iVar3 != 0)) {
    *in_stack_0000003c = in_stack_00000038;
    in_stack_00000034 = 1;
    *in_stack_00000028 = local_30;
    in_stack_00000028[1] = local_2c;
    in_stack_00000028[2] = local_28;
  }
  pGVar2 = (GmVec3 *)(**(code **)(*(int *)param_4 + 0x7c))();
  pGVar7 = (GmVec3 *)0x0;
  if (pGVar2 != (GmVec3 *)0x0) {
    do {
      pGVar11 = (GmVec3 *)&local_48;
      ppGVar10 = &param_8;
      pGVar9 = local_24;
      pGVar8 = pGVar7;
      iVar3 = (**(code **)(*(int *)param_4 + 0x80))();
      iVar3 = IntersectSegmentTree2
                        (local_50,(SZone *)param_2,pGVar2,(GmVec3 *)param_5,iVar3,
                         (CPlugTree *)pGVar8,pGVar9,(float *)ppGVar10,pGVar11);
      if (iVar3 != 0) {
        if (param_7 == (float *)0x0) {
          *in_stack_00000024 = (float)param_8;
          param_7 = (float *)0x1;
        }
        else {
          if (*in_stack_00000024 <= (float)param_8) goto LAB_00537c87;
          *in_stack_00000024 = (float)param_8;
        }
        *in_stack_00000028 = local_48;
        in_stack_00000028[1] = local_44;
        in_stack_00000028[2] = fStack_40;
      }
LAB_00537c87:
      pGVar7 = pGVar7 + 1;
    } while (pGVar7 < pGVar2);
  }
  return (int)param_7;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::IntersectSegmentTree3
// =================================================
int __thiscall
CHmsCollisionManager::SZone::IntersectSegmentTree3
          (void *this,SZone *param_1,GmVec3 *param_2,GmVec3 *param_3,CPlugTree *param_4,
          GmIso4 *param_5,float *param_6,ushort *param_7)
{
{
  float *pfVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  GmVec3 *pGVar4;
  int iVar5;
  GmVec2 *unaff_EBP;
  GmIso4 *unaff_ESI;
  CPlugTree *pCVar6;
  GmIso3 *unaff_EDI;
  undefined4 *puVar7;
  CPlugTree *in_stack_00000020;
  undefined2 *in_stack_00000024;
  undefined4 in_stack_0000002c;
  ushort in_stack_00000030;
  ushort *in_stack_0000003c;
  CPlugTree *pCVar8;
  GmSurf *pGVar9;
  CPlugTree **ppCVar10;
  ushort **ppuVar11;
  void *local_50;
  float fVar12;
  undefined1 local_44 [28];
  undefined4 local_28;
  GmSurf local_24 [36];
  
  pCVar6 = param_4;
  if (((byte)param_3[0x9c] & 0x80) == 0) {
    return 0;
  }
  GmBoxAligned::SetMult
            (&stack0xffffffb8,(SPlugFaceCull *)(param_3 + 0x34),(SPlugFaceCull *)param_4,unaff_ESI);
  local_50 = (void *)(*(float *)param_3 + *(float *)param_2);
  fVar12 = *(float *)(param_3 + 8) + *(float *)(param_2 + 8);
  uVar2 = GmBoxAligned::TestInterSegment
                    (local_44,(GmRectAligned *)param_2,(GmVec2 *)&local_50,unaff_EBP);
  if (uVar2 != 0) {
    param_5 = (GmIso4 *)0x0;
    iVar5 = 0xc;
    puVar7 = &local_28;
    if (((byte)param_3[0x9c] & 4) == 0) {
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *(undefined4 *)pCVar6;
        pCVar6 = pCVar6 + 4;
        puVar7 = puVar7 + 1;
      }
    }
    else {
      pGVar4 = param_3 + 0x5c;
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *(undefined4 *)pGVar4;
        pGVar4 = pGVar4 + 4;
        puVar7 = puVar7 + 1;
      }
      GmIso4::Mult(&local_28,(GmIso3 *)param_6,unaff_EDI);
    }
    pfVar1 = (float *)in_stack_00000020;
    if (((*(int *)(param_3 + 0x8c) != 0) &&
        (iVar5 = *(int *)(*(int *)(param_3 + 0x8c) + 0x14), *(int *)(iVar5 + 0x34) != 0)) &&
       (iVar5 = GmSurf::ClipSegment3
                          (local_24,(GmSurfMesh *)param_2,(GmVec3 *)param_5,
                           *(GmVec3 **)(iVar5 + 0x34),(float *)local_24,(ushort *)&param_4),
       iVar5 != 0)) {
      *(undefined2 **)in_stack_00000020 = in_stack_00000024;
      in_stack_0000002c = 1;
      local_50 = (void *)0x537dcd;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(param_3 + 0x8c) + 0x18),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uint)in_stack_00000030,
                          (ulong)fVar12);
      *in_stack_0000003c = (ushort)*(byte *)(*(int *)pSVar3 + 0x18);
    }
    in_stack_00000020 = (CPlugTree *)(**(code **)(*(int *)param_3 + 0x7c))();
    pCVar6 = (CPlugTree *)0x0;
    if (in_stack_00000020 != (CPlugTree *)0x0) {
      do {
        ppuVar11 = &param_7;
        ppCVar10 = &param_4;
        pGVar9 = local_24;
        pCVar8 = pCVar6;
        pGVar4 = (GmVec3 *)(**(code **)(*(int *)param_3 + 0x80))();
        iVar5 = IntersectSegmentTree3
                          (local_50,(SZone *)param_2,(GmVec3 *)param_4,pGVar4,pCVar8,
                           (GmIso4 *)pGVar9,(float *)ppCVar10,(ushort *)ppuVar11);
        if (iVar5 != 0) {
          if (param_6 == (float *)0x0) {
            *pfVar1 = (float)param_4;
            param_6 = (float *)0x1;
            *in_stack_00000024 = param_7._0_2_;
          }
          else if ((float)param_4 < *pfVar1) {
            *pfVar1 = (float)param_4;
            *in_stack_00000024 = param_7._0_2_;
          }
        }
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < in_stack_00000020);
    }
    return (int)param_6;
  }
  return 0;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::PrepareCollisions
// =================================================
void __thiscall CHmsCollisionManager::SZone::PrepareCollisions(void *this,SZone *param_1)
{
{
  int iVar1;
  SGroup *unaff_EDI;
  void *this_00;
  int iVar2;
  
  iVar1 = 5;
  this_00 = this;
  do {
    iVar2 = iVar1;
    SGroup::ComputeNonStaticCorpusInfos(this_00,unaff_EDI);
    this_00 = (void *)((int)this_00 + 0x44);
    iVar1 = iVar2 + -1;
  } while (iVar1 != 0);
  iVar2 = iVar2 + 4;
  do {
    SGroup::ComputeIsToPerformCollisions(this,unaff_EDI);
    this = (void *)((int)this + 0x44);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::RemoveCorpus
// =================================================
void __thiscall
CHmsCollisionManager::SZone::RemoveCorpus(void *this,CHmsZoneOverlay *param_1,CHmsCorpus *param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x48) + 0x18) >> 0xd & 0xf;
  if (uVar1 != 0) {
    SGroup::RemoveCorpus((void *)((int)this + uVar1 * 0x44 + -0x44),param_1,param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::SZone
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsCollisionManager::SZone::SZone
          (void *this,SZone *param_1,ulong param_2,CHmsCollisionManager *param_3)
{
{
  int *piVar1;
  undefined4 uVar2;
  ulong uVar3;
  SLoadedLight *pSVar4;
  void *unaff_EBX;
  int iVar5;
  GmMap2<unsigned_char> *pGVar6;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar7;
  CFastBuffer<class_CCrystalFace*> *pCVar8;
  code *pcVar9;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9572f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pcVar9 = SGroup::SGroup;
  pCVar8 = (CFastBuffer<class_CCrystalFace*> *)&DAT_00000005;
  pCVar7 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_00000044;
  pGVar6 = this;
  _eh_vector_constructor_iterator_(this,0x44,5,SGroup::SGroup,SGroup::~SGroup);
  iVar5 = 0;
  GmMap2<unsigned_char>::GmMap2<unsigned_char>((void *)((int)this + 0x154),pGVar6);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x1a0),pCVar7);
  uVar2 = _DAT_00b55da4;
  *(undefined4 *)((int)this + 0x178) = _DAT_00b55da4;
  *(undefined4 *)((int)this + 0x17c) = uVar2;
  *(undefined4 *)((int)this + 0x19c) = local_4;
  *(undefined4 *)((int)this + 0x180) = uVar2;
  *(undefined1 **)((int)this + 0x198) = local_8;
  *(undefined4 *)((int)this + 0x80) = 1;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0xc4) = 2;
  *(undefined4 *)((int)this + 200) = 0;
  *(undefined4 *)((int)this + 0x108) = 3;
  *(undefined4 *)((int)this + 0x14c) = 4;
  *(undefined4 *)((int)this + 0x150) = 0;
  *(undefined4 *)((int)this + 0x10c) = 1;
  for (uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d67590,pCVar8); uVar3 != 0;
      uVar3 = uVar3 - 1) {
    piVar1 = (int *)(iVar5 + DAT_00d67594);
    pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>::AddNewElem
                       ((void *)((int)this + *piVar1 * 0x44 + -0x20),
                        (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pcVar9);
    *(int *)pSVar4 = (int)this + piVar1[1] * 0x44 + -0x44;
    *(int **)(pSVar4 + 4) = piVar1;
    if (*piVar1 != piVar1[1]) {
      pcVar9 = (code *)0x53b187;
      pSVar4 = CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>::AddNewElem
                         ((void *)((int)this + piVar1[1] * 0x44 + -0x20),
                          (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x53b187);
      *(int *)pSVar4 = (int)this + *piVar1 * 0x44 + -0x44;
      *(int **)(pSVar4 + 4) = piVar1;
    }
    iVar5 = iVar5 + 0x14;
  }
  ExceptionList = unaff_EBX;
  return;
}
}

// =================================================
// Function: CHmsCollisionManager::SZone::UpdateStaticCollisionTrees
// =================================================
void __thiscall
CHmsCollisionManager::SZone::UpdateStaticCollisionTrees(void *this,CHmsCollisionManager *param_1)
{
{
  int iVar1;
  
  iVar1 = 5;
  do {
    SGroup::UpdateStaticCollisionTrees(this,(CHmsCollisionManager *)0x1);
    this = (void *)((int)this + 0x44);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
}

