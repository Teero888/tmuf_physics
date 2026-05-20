// Class implementation: CMotions

// =================================================
// Function: CMotions::AddMotion
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CMotion * __thiscall
CMotions::AddMotion(CMotions *this,CSceneObject *param_1,CMwNod *param_2,CMwId *param_3,int param_4)
{
{
  CMotions *this_00;
  char *pcVar1;
  int iVar2;
  CMotion *pCVar3;
  ulong uVar4;
  CMotionPlayer *extraout_EAX;
  undefined4 unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CMotionPlayer *this_01;
  undefined2 in_FPUControlWord;
  CMotionTrack *pCVar5;
  GxTexCoordSet *pGVar6;
  CMwNod *pCVar7;
  CFastArray<class_CMotion*> aCStack_20 [8];
  CFastArray<class_CMotion*> aCStack_1c [8];
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  CMotionPlayer *pCStack_4;
  
  pCStack_4 = (CMotionPlayer *)0xffffffff;
  puStack_8 = &LAB_00a99dfb;
  local_c = ExceptionList;
  aCStack_20._0_4_ = (CFuncPlug *)unaff_EBX;
  pcVar1 = (char *)(DAT_00cca150 ^ (uint)&stack0xffffffd8);
  ExceptionList = &local_c;
  pCVar7 = (CMwNod *)0x8001000;
  iVar2 = (**(code **)(*(int *)param_1 + 0x10))();
  if (iVar2 == 0) {
    pGVar6 = (GxTexCoordSet *)0x8033000;
    iVar2 = (**(code **)(*(int *)param_1 + 0x10))();
    if (iVar2 == 0) {
      ExceptionList = pvStack_14;
      return (CMotion *)0xffffffff;
    }
    pCStack_4 = operator_new(0x58);
    this_01 = (CMotionPlayer *)0x0;
    local_c = (void *)0x0;
    if (pCStack_4 != (CMotionPlayer *)0x0) {
      CMotionPlayer::CMotionPlayer(pCStack_4,(CMotionPlayer *)pGVar6);
      this_01 = extraout_EAX;
    }
    pCVar5 = *(CMotionTrack **)(this + 0x20);
    local_c = (void *)0xffffffff;
    (**(code **)(*(int *)this_01 + 0x94))();
    iVar2 = (**(code **)(*(int *)param_1 + 0x8c))(&stack0xffffffdc);
    if (iVar2 != 0) {
      puStack_8 = (undefined1 *)CONCAT22(puStack_8._2_2_,in_FPUControlWord);
      aCStack_20 = (CFastArray<class_CMotion*>  [8])
                   (longlong)ROUND((float)this_01 * (float)_DAT_00c418d8);
      CMotionCmdBase::SetPeriod(*(CMotionCmdBase **)(this_01 + 0x30),aCStack_20._0_4_,(float)pCVar5)
      ;
    }
    CMotionPlayer::AddTrack(this_01,(CMotionPlayer *)param_1,pCVar5);
  }
  else {
    pGVar6 = *(GxTexCoordSet **)(this + 0x20);
    aCStack_20._0_4_ = (CFuncPlug *)param_1;
    (**(code **)(*(int *)param_1 + 0x94))();
    this_01 = (CMotionPlayer *)param_1;
  }
  this_00 = this + 0x18;
  pCVar3 = (CMotion *)
           CFastArray<class_CGameMenuFrame*>::Find
                     (this_00,(CFastArray<class_GxTexCoordSet> *)&stack0xffffffdc,pGVar6);
  if (pCVar3 == (CMotion *)0xffffffff) {
    CMwNod::MwAddRef((CMwNod *)this_01,pCVar7);
    CFastArray<class_CMotion*>::AddTailWithUniqueId
              (this_00,(CFastArray<class_CMotion*> *)((int)register0x00000010 + -0x1c),
               (CMotion **)"NewMotion",pcVar1);
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    pCVar3 = (CMotion *)(uVar4 - 1);
  }
  ExceptionList = pCStack_4;
  return pCVar3;
}
}

// =================================================
// Function: CMotions::CMotions
// =================================================
void __thiscall CMotions::CMotions(CMotions *this,CMotions *param_1)
{
{
  CMotion *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  
  CMotion::CMotion((CMotion *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x18,unaff_retaddr);
  *(undefined4 *)(this + 0x20) = 0;
  return;
}
}

// =================================================
// Function: CMotions::OnAbsorbContact
// =================================================
void __thiscall
CMotions::OnAbsorbContact(CMotions *this,CMotions *param_1,CHmsPhysicalContact *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CHmsPhysicalContact *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x18,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x18,pCVar3,(ulong)unaff_EBP);
      unaff_EBP = param_2;
      (**(code **)(**(int **)pSVar2 + 0xb4))();
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CMotions::RemoveMotion
// =================================================
void __thiscall CMotions::RemoveMotion(CMotions *this,CSceneObject *param_1,CMotion *param_2)
{
{
  ulong unaff_retaddr;
  
  CFastArray<class_CCrystalEdge*>::RemoveElems
            (this + 0x18,(CFastArray<class_CCrystalEdge*> *)&param_1,(CCrystalEdge **)0x1,
             unaff_retaddr);
  CMwNod::MwRelease((CMwNod *)param_2,(CMwNod *)param_1);
  return;
}
}

// =================================================
// Function: CMotions::WantAbsorbContact
// =================================================
int __thiscall CMotions::WantAbsorbContact(CMotions *this,CMotions *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x18,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x18,pCVar4,unaff_ESI);
      unaff_ESI = 0x582f99;
      iVar3 = (**(code **)(**(int **)pSVar2 + 0xb0))();
      if (iVar3 != 0) {
        return 1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return 0;
}
}

