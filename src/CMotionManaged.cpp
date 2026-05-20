// Class implementation: CMotionManaged

// =================================================
// Function: CMotionManaged::CMotionManaged
// =================================================
void __thiscall CMotionManaged::CMotionManaged(CMotionManaged *this,CMotionManaged *param_1)
{
{
  CMotion *unaff_ESI;
  
  CMotion::CMotion((CMotion *)this,unaff_ESI);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x1c) = 1;
  return;
}
}

// =================================================
// Function: CMotionManaged::QueryManager
// =================================================
CMotionManager * __thiscall
CMotionManaged::QueryManager(CMotionManaged *this,CScene *param_1,ulong param_2)
{
{
  int iVar1;
  CScene *pCVar2;
  CMotionManager *pCVar3;
  undefined4 uVar4;
  ulong unaff_ESI;
  CMotionManaged *pCVar5;
  
  pCVar3 = *(CMotionManager **)(this + 0x18);
  *(undefined4 *)(this + 0x20) = 0;
  if ((pCVar3 != (CMotionManager *)0x0) && (*(int *)(pCVar3 + 0x14) != 0)) {
    iVar1 = (**(code **)(*(int *)this + 200))();
    if (iVar1 != 0) {
      pCVar5 = this;
      pCVar2 = (CScene *)(**(code **)(*(int *)this + 200))();
      pCVar3 = CScene::QueryManager(*(CScene **)(*(int *)(this + 0x18) + 0x14),pCVar2,(ulong)pCVar5)
      ;
      *(CMotionManager **)(this + 0x20) = pCVar3;
      return pCVar3;
    }
    iVar1 = (**(code **)(*(int *)this + 0xcc))();
    pCVar3 = (CMotionManager *)0x0;
    if (iVar1 != 0) {
      pCVar2 = (CScene *)(**(code **)(*(int *)this + 0xcc))();
      pCVar3 = CScene::QueryManager(*(CScene **)(*(int *)(this + 0x18) + 0x14),pCVar2,unaff_ESI);
      *(CMotionManager **)(this + 0x20) = pCVar3;
      (**(code **)(*(int *)pCVar3 + 0x78))(this);
      pCVar3 = (CMotionManager *)(**(code **)(**(int **)(this + 0x20) + 0x88))();
      if (pCVar3 == (CMotionManager *)0x0) {
        iVar1 = **(int **)(this + 0x20);
        uVar4 = (**(code **)(**(int **)(this + 0x18) + 0x78))();
        pCVar3 = (CMotionManager *)(**(code **)(iVar1 + 0x84))(uVar4);
      }
    }
  }
  return pCVar3;
}
}

// =================================================
// Function: CMotionManaged::ReleaseManager
// =================================================
void __thiscall CMotionManaged::ReleaseManager(CMotionManaged *this,CScene *param_1,ulong param_2)
{
{
  int iVar1;
  CScene *pCVar2;
  CMotion *unaff_ESI;
  ulong unaff_retaddr;
  CMotionManaged *pCVar3;
  
  if (*(int *)(this + 0x20) != 0) {
    if ((*(int *)(this + 0x18) != 0) && (*(int *)(*(int *)(this + 0x18) + 0x14) != 0)) {
      iVar1 = (**(code **)(*(int *)this + 200))();
      if (iVar1 != 0) {
        pCVar3 = this;
        pCVar2 = (CScene *)(**(code **)(*(int *)this + 200))();
        CScene::ReleaseManager(*(CScene **)(*(int *)(this + 0x18) + 0x14),pCVar2,(ulong)pCVar3);
        *(undefined4 *)(this + 0x20) = 0;
        return;
      }
      iVar1 = (**(code **)(*(int *)this + 0xcc))();
      if (iVar1 != 0) {
        pCVar3 = this;
        pCVar2 = (CScene *)(**(code **)(*(int *)this + 0xcc))();
        CScene::RemoveManagedMotion
                  (*(CScene **)(*(int *)(this + 0x18) + 0x14),pCVar2,(ulong)pCVar3,unaff_ESI);
        pCVar2 = (CScene *)(**(code **)(*(int *)this + 0xcc))();
        CScene::ReleaseManager(*(CScene **)(*(int *)(this + 0x18) + 0x14),pCVar2,unaff_retaddr);
      }
    }
    *(undefined4 *)(this + 0x20) = 0;
  }
  return;
}
}

