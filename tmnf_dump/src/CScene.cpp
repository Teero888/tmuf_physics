// Class implementation: CScene

// =================================================
// Function: CScene::CScene
// =================================================
void __thiscall CScene::CScene(CScene *this,CScene *param_1)
{
{
  undefined4 extraout_EAX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CMwNod *unaff_EDI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  CFastArray<class_CManoeuvre*> *in_stack_00000008;
  CScene *in_stack_0000000c;
  undefined1 uStack00000018;
  CSceneSoundManager *pCStack0000001c;
  void *in_stack_00000020;
  void *in_stack_00000024;
  undefined1 uStack00000028;
  CScene *pCVar1;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffff0;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar2;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar3;
  CMwCmdContainer *pCVar4;
  
  pCVar4 = (CMwCmdContainer *)0xffffffff;
  pCVar3 = (CFastBuffer<class_CPlugFileSndGen*> *)&LAB_00acc742;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x14,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x20,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x2c,in_stack_fffffff0);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x38,pCVar2);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x44,pCVar3);
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  uStack00000018 = 7;
  CMwCmdContainer::CMwCmdContainer((CMwCmdContainer *)(this + 0x58),pCVar4);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x7c,unaff_retaddr);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x88,(CFastBuffer<class_CPlugFileSndGen*> *)0x0);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x94,in_stack_00000008);
  uStack00000028 = 0xb;
  pCStack0000001c = operator_new(0x18);
  uStack00000028 = 0xc;
  if (pCStack0000001c != (CSceneSoundManager *)0x0) {
    CSceneSoundManager::CSceneSoundManager
              (pCStack0000001c,(CSceneSoundManager *)this,in_stack_0000000c);
    *(undefined4 *)(this + 0x9c) = extraout_EAX;
    ExceptionList = in_stack_00000024;
    return;
  }
  *(undefined4 *)(this + 0x9c) = 0;
  ExceptionList = in_stack_00000020;
  return;
}
}

// =================================================
// Function: CScene::CameraPropertiesUpdate
// =================================================
void __thiscall CScene::CameraPropertiesUpdate(CScene *this,CScene *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CSceneCamera *unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x38,pCVar3,unaff_ESI);
      unaff_ESI = 0x7ba9e4;
      CSceneCamera::SetSceneProperties(*(CSceneCamera **)pSVar2,unaff_EBX);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CScene::FindManagerFromClassId
// =================================================
ulong __thiscall CScene::FindManagerFromClassId(CScene *this,CScene *param_1,ulong param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x7c,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x7c,pCVar4,unaff_ESI);
      unaff_ESI = param_2;
      iVar3 = (**(code **)(**(int **)pSVar2 + 0x10))();
      if (iVar3 != 0) {
        return (ulong)pCVar4;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CScene::GetManager
// =================================================
CMotionManager * __thiscall CScene::GetManager(CScene *this,CScene *param_1,ulong param_2)
{
{
  CMotionManager *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong in_stack_0000000c;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x7c,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x7c,pCVar5,unaff_ESI);
      pCVar1 = *(CMotionManager **)pSVar3;
      unaff_ESI = in_stack_0000000c;
      iVar4 = (**(code **)(*(int *)pCVar1 + 0x10))();
      if (iVar4 != 0) {
        return pCVar1;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  return (CMotionManager *)0x0;
}
}

// =================================================
// Function: CScene::QueryManager
// =================================================
CMotionManager * __thiscall CScene::QueryManager(CScene *this,CScene *param_1,ulong param_2)
{
{
  CMwNod *pCVar1;
  int iVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  ulong uVar5;
  ulong unaff_EBX;
  CScene *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CMotionManager *pCStack0000000c;
  CMwNod *in_stack_00000010;
  int *in_stack_00000014;
  ulong uVar7;
  CScene *pCStack_4;
  
  iVar2 = CMwNod::StaticMwIsKindOf((ulong)param_1,0x804b000);
  if (iVar2 == 0) {
    return (CMotionManager *)0x0;
  }
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x94,unaff_ESI);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x94,pCVar6,unaff_EBX);
      unaff_EBX = *(ulong *)pSVar4;
      iVar2 = CMwNod::StaticMwIsKindOf((ulong)param_1,unaff_EBX);
      if (iVar2 != 0) {
        return (CMotionManager *)0x0;
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar3);
  }
  pCStack0000000c = GetManager(pCStack_4,param_1,unaff_EBX);
  if (pCStack0000000c != (CMotionManager *)0x0) goto LAB_007bb6bf;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(pCStack_4 + 0x88,unaff_EDI);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
LAB_007bb664:
    in_stack_00000010 = CMwNod::CreateByMwClassId((ulong)param_1);
    param_1 = pCStack_4;
  }
  else {
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCStack_4 + 0x88,pCVar6,(ulong)unaff_EBP);
      pCVar1 = *(CMwNod **)pSVar4;
      unaff_EBP = param_1;
      iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))();
      if (iVar2 != 0) {
        in_stack_00000010 = pCVar1;
        CSystemArchiveNod::Duplicate
                  ((CSystemArchiveNod *)&stack0x00000010,(CPlugVisualVertexs *)&stack0x00000010);
        in_stack_00000014[5] = (int)pCVar1;
        break;
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar3);
    pCStack_4 = param_1;
    if (in_stack_00000010 == (CMwNod *)0x0) goto LAB_007bb664;
  }
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (param_1 + 0x7c,(TiXmlAttributeSet *)&stack0x00000010,(TiXmlAttribute *)unaff_EBP);
  uVar7 = 0xa003000;
  unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x7bb68c;
  iVar2 = (**(code **)(*(int *)param_1 + 0x10))();
  if (iVar2 != 0) {
    uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0xac,unaff_EDI);
    if (uVar5 != 0) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_1 + 0xac,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar7
                         );
      unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x7bb6bb;
      (**(code **)(*in_stack_00000014 + 0x84))(*(undefined4 *)pSVar4);
    }
  }
LAB_007bb6bf:
  *(int *)(pCStack0000000c + 0x18) = *(int *)(pCStack0000000c + 0x18) + 1;
  CMwNod::MwAddRef((CMwNod *)pCStack0000000c,(CMwNod *)unaff_EDI);
  return (CMotionManager *)in_stack_00000010;
}
}

// =================================================
// Function: CScene::ReleaseManager
// =================================================
void __thiscall CScene::ReleaseManager(CScene *this,CScene *param_1,ulong param_2)
{
{
  CMwNod *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CMwNod *unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           FindManagerFromClassId(this,param_1,unaff_ESI);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x7c,pCVar1,unaff_EDI)
    ;
    this_00 = *(CMwNod **)pSVar2;
    if (*(int *)(this_00 + 0x18) == 1) {
      CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt
                (this + 0x7c,(CFastBufferRef<class_CGameMobil> *)pCVar1,1,(ulong)unaff_EBX);
      unaff_EBX = (CMwNod *)0x0;
      (**(code **)(*(int *)this_00 + 0x84))();
    }
    *(int *)(this_00 + 0x18) = *(int *)(this_00 + 0x18) + -1;
    CMwNod::MwRelease(this_00,unaff_EBX);
  }
  return;
}
}

// =================================================
// Function: CScene::RemoveManagedMotion
// =================================================
void __thiscall
CScene::RemoveManagedMotion(CScene *this,CScene *param_1,ulong param_2,CMotion *param_3)
{
{
  CMotionManager *pCVar1;
  ulong unaff_retaddr;
  
  pCVar1 = GetManager(this,param_1,unaff_retaddr);
  if (pCVar1 != (CMotionManager *)0x0) {
    (**(code **)(*(int *)pCVar1 + 0x7c))();
  }
  return;
}
}

// =================================================
// Function: CScene::SeaGet
// =================================================
CSceneToySea * __thiscall CScene::SeaGet(CScene *this,CScene *param_1,CSceneSector *param_2)
{
{
  return *(CSceneToySea **)(this + 0x54);
}
}

