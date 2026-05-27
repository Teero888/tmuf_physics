// Class implementation: SHmsSphereBufferContact

// =================================================
// Function: SHmsSphereBufferContact::MergeAndAddToCollisions
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SHmsSphereBufferContact::MergeAndAddToCollisions
          (void *this,SHmsSphereBufferContact *param_1,CHmsCollisionBuffer *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  SLoadedLight *pSVar4;
  SCasterCat *pSVar5;
  ulong uVar6;
  int iVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000000c;
  GmVec2 *pGVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  void *pvStack_14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_c;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 4),unaff_EDI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(**(code **)(*(int *)param_2 + 8))();
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_SHmsPhysicalCollision>::operator[]
                         (pvStack_14,pCVar8,(ulong)unaff_ESI);
      if (*(int *)(pSVar3 + 0x38) != 0) {
        unaff_ESI = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x53815a;
        pSVar4 = CFastBuffer<struct_SHmsPhysicalCollision>::AddNewElem
                           (param_2 + 4,
                            (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x53815a);
        for (iVar7 = 0x13; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)pSVar4 = *(undefined4 *)pSVar3;
          pSVar3 = pSVar3 + 4;
          pSVar4 = pSVar4 + 4;
        }
      }
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar1);
  }
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(**(code **)(*(int *)param_2 + 8))();
  pCStack_c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pGVar10 = (GmVec2 *)0x53819e;
      pCVar11 = pCStack_c;
      pSVar3 = CFastBuffer<struct_SHmsPhysicalCollision>::operator[]
                         (pvStack_14,pCStack_c,(ulong)unaff_ESI);
      if (*(int *)(pSVar3 + 0x38) == 0) {
        pCVar9 = pCVar2;
        if (pCVar2 < in_stack_0000000c) {
          do {
            pSVar5 = CFastBuffer<struct_SHmsPhysicalCollision>::operator[]
                               (param_2 + 4,pCVar9,(ulong)pGVar10);
            pGVar10 = (GmVec2 *)(pSVar5 + 0x3c);
            uVar6 = GmVec3::IsNearlyEqual(pSVar3 + 0x3c,pGVar10,(GmVec2 *)pCVar11);
            if ((uVar6 != 0) ||
               (_DAT_00d67530 <
                *(float *)(pSVar3 + 0x24) * *(float *)(pSVar5 + 0x24) +
                *(float *)(pSVar3 + 0x1c) * *(float *)(pSVar5 + 0x1c) +
                *(float *)(pSVar3 + 0x20) * *(float *)(pSVar5 + 0x20))) break;
            pCVar9 = pCVar9 + 1;
          } while (pCVar9 < pCVar8);
        }
        if (pCVar9 == pCVar8) {
          pSVar4 = CFastBuffer<struct_SHmsPhysicalCollision>::AddNewElem(param_2 + 4,unaff_ESI);
          for (iVar7 = 0x13; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined4 *)pSVar4 = *(undefined4 *)pSVar3;
            pSVar3 = pSVar3 + 4;
            pSVar4 = pSVar4 + 4;
          }
        }
      }
      pCStack_c = pCStack_c + 1;
    } while (pCStack_c < pCVar1);
  }
  *(undefined4 *)(unaff_retaddr + 0x10) = 0;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pvStack_14,(GmFrustumIso4 *)unaff_ESI)
  ;
  return;
}
}

// =================================================
// Function: SHmsSphereBufferContact::SHmsSphereBufferContact
// =================================================
void __thiscall
SHmsSphereBufferContact::SHmsSphereBufferContact(void *this,SHmsSphereBufferContact *param_1)
{
{
  CHmsCollisionBuffer *unaff_ESI;
  
  CHmsCollisionBuffer::CHmsCollisionBuffer(this,unaff_ESI);
  *(undefined4 *)((int)this + 0x10) = 0;
  return;
}
}

