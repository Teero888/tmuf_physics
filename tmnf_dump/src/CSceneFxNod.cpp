// Class implementation: CSceneFxNod

// =================================================
// Function: CSceneFxNod::CameraCallBack
// =================================================
void __thiscall CSceneFxNod::CameraCallBack(CSceneFxNod *this,CSceneFxNod *param_1,int param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if (param_1 == (CSceneFxNod *)0x0) {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x20,pCVar4,unaff_ESI);
        iVar1 = *(int *)(*(int *)pSVar3 + 0x30);
        if (*(CSceneFxNod **)(iVar1 + 0x1b4) == this) {
          *(undefined4 *)(iVar1 + 0x1b4) = 0;
          *(undefined4 *)(iVar1 + 0x1b8) = 0;
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
  }
  else {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x20,pCVar4,unaff_ESI);
        iVar1 = *(int *)(*(int *)pSVar3 + 0x30);
        pCVar4 = pCVar4 + 1;
        *(CSceneFxNod **)(iVar1 + 0x1b4) = this;
        *(code **)(iVar1 + 0x1b8) = CameraFxCallBack;
      } while (pCVar4 < pCVar2);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CSceneFxNod::CanActive
// =================================================
int __thiscall CSceneFxNod::CanActive(CSceneFxNod *this,CSceneFxFlares *param_1,CHmsCamera *param_2)
{
{
  CSceneFxNod *this_00;
  CHmsViewport *pCVar1;
  int iVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CSceneFxNod *pCVar5;
  CSceneFxNod *unaff_EBP;
  CSystemWindow *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int in_stack_0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  
  if (*(int *)(this + 0x18) == 0) {
    pCVar1 = CHmsViewport::FindOrCreateViewport((CHmsViewport *)this,(CVisionEngine *)0x0,unaff_ESI)
    ;
    *(CHmsViewport **)(this + 0x18) = pCVar1;
  }
  if ((((*(int *)(this + 0x1c) != 0) && (*(int *)(this + 0x18) != 0)) &&
      (*(int *)(*(int *)(this + 0x1c) + 0x15c) != 0)) &&
     (((*(int **)(this + 0x30) == (int *)0x0 ||
       (iVar2 = (**(code **)(**(int **)(this + 0x30) + 0x80))(), iVar2 != 0)) &&
      ((in_stack_0000000c != 0 || (iVar2 = IsInit(this,(SVisualHandler *)param_1), iVar2 != 0))))))
  {
    pCVar5 = *(CSceneFxNod **)(this + 0x44);
    while( true ) {
      this_00 = pCVar5;
      if (this_00 == (CSceneFxNod *)0x0) {
        return 1;
      }
      pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this_00 + 0x34);
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x38,unaff_EDI);
      if (pCVar6 < pCVar3) {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00 + 0x38,pCVar6,(ulong)unaff_EBP);
        pCVar5 = *(CSceneFxNod **)pSVar4;
        unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)pCVar6;
      }
      else {
        pCVar5 = (CSceneFxNod *)0x0;
      }
      if (pCVar5 != this) break;
      pCVar5 = *(CSceneFxNod **)(this_00 + 0x44);
      this = this_00;
    }
    pCVar5 = NodInputGet(this_00,(CSceneFxNod *)unaff_EDI);
    iVar2 = IsActiveThisOrChild(pCVar5,unaff_EBP);
    return (uint)(iVar2 == 0);
  }
  return 0;
}
}

// =================================================
// Function: CSceneFxNod::FxSet
// =================================================
void __thiscall CSceneFxNod::FxSet(CSceneFxNod *this,CSceneFxNod *param_1,CSceneFx *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CSceneFxNod **)(this + 0x30)) {
    if (param_1 != (CSceneFxNod *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x30),unaff_ESI);
    }
    *(CSceneFxNod **)(this + 0x30) = param_1;
  }
  return;
}
}

// =================================================
// Function: CSceneFxNod::IsActiveThisOrChild
// =================================================
int __thiscall CSceneFxNod::IsActiveThisOrChild(CSceneFxNod *this,CSceneFxNod *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CSceneFxNod *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  
  do {
    if (*(int *)(this + 0x14) != 0) {
      return 1;
    }
    pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x34);
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EDI);
    if (pCVar1 < pCVar2) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x38,pCVar1,(ulong)unaff_ESI);
      this = *(CSceneFxNod **)pSVar3;
    }
    else {
      this = (CSceneFxNod *)0x0;
    }
    unaff_ESI = param_1;
    unaff_EDI = unaff_retaddr;
  } while (this != (CSceneFxNod *)0x0);
  return 0;
}
}

// =================================================
// Function: CSceneFxNod::NodFindFromFx
// =================================================
CSceneFxNod * __thiscall
CSceneFxNod::NodFindFromFx(CSceneFxNod *this,CSceneFxNod *param_1,CSceneFx *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CSceneFxNod *pCVar3;
  CSceneFx *unaff_EBP;
  CSceneFxNod *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if ((*(CSceneFxNod **)(this + 0x30) == (CSceneFxNod *)0x0) ||
     (*(CSceneFxNod **)(this + 0x30) != param_1)) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x38,pCVar4,(ulong)unaff_ESI);
        unaff_ESI = param_1;
        pCVar3 = NodFindFromFx(*(CSceneFxNod **)pSVar2,param_1,unaff_EBP);
        if (pCVar3 != (CSceneFxNod *)0x0) {
          return pCVar3;
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar1);
    }
    this = (CSceneFxNod *)0x0;
  }
  return this;
}
}

// =================================================
// Function: CSceneFxNod::NodFindFromFxClassId
// =================================================
CSceneFxNod * __thiscall
CSceneFxNod::NodFindFromFxClassId(CSceneFxNod *this,CSceneFxNod *param_1,ulong param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CSceneFxNod *pCVar4;
  CSceneFxNod *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if ((*(int **)(this + 0x30) != (int *)0x0) &&
     (iVar1 = (**(code **)(**(int **)(this + 0x30) + 0x10))(param_1), iVar1 != 0)) {
    return this;
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x38,pCVar5,(ulong)unaff_EBP);
      unaff_EBP = param_1;
      pCVar4 = NodFindFromFxClassId(*(CSceneFxNod **)pSVar3,param_1,unaff_ESI);
      if (pCVar4 != (CSceneFxNod *)0x0) {
        return pCVar4;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  return (CSceneFxNod *)0x0;
}
}

// =================================================
// Function: CSceneFxNod::NodInputGet
// =================================================
CSceneFxNod * __thiscall CSceneFxNod::NodInputGet(CSceneFxNod *this,CSceneFxNod *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x34);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EDI);
  if (pCVar1 < pCVar2) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x38,pCVar1,unaff_ESI)
    ;
    return *(CSceneFxNod **)pSVar3;
  }
  return (CSceneFxNod *)0x0;
}
}

// =================================================
// Function: CSceneFxNod::NodInputSel
// =================================================
int __thiscall CSceneFxNod::NodInputSel(CSceneFxNod *this,CSceneFxNod *param_1,CSceneFxNod *param_2)
{
{
  CSceneFxNod *pCVar1;
  int iVar2;
  CGameCtnMediaClip *unaff_ESI;
  CSceneFxNod *unaff_retaddr;
  
  pCVar1 = (CSceneFxNod *)
           CFastBufferRef<class_CGameCtnMediaClip>::FindPtr
                     (this + 0x38,(CFastBufferRef<class_CGameCtnMediaClip> *)param_1,unaff_ESI);
  if (pCVar1 == (CSceneFxNod *)0xffffffff) {
    return 0;
  }
  iVar2 = NodInputSel(this,pCVar1,unaff_retaddr);
  return iVar2;
}
}

// =================================================
// Function: CSceneFxNod::PreLoad
// =================================================
void __thiscall CSceneFxNod::PreLoad(CSceneFxNod *this,CSceneFxCompo *param_1)
{
{
  if (DAT_00d54244 == 0) {
                    /* WARNING: Could not recover jumptable at 0x007b96b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x30) + 0x88))();
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneFxNod::StartStop
// =================================================
int __thiscall CSceneFxNod::StartStop(CSceneFxNod *this,CSceneFxNod *param_1,int param_2)
{
{
  bool bVar1;
  CSceneFxNod *this_00;
  CSceneFxNod *pCVar2;
  int iVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  CSceneFxNod *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CHmsCamera *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  
  if ((param_1 != (CSceneFxNod *)0x0) &&
     (iVar3 = CanActive(this,(CSceneFxFlares *)0x0,unaff_EDI), iVar3 == 0)) {
    return 0;
  }
  bVar1 = false;
  pCVar6 = *(CSceneFxNod **)(this + 0x44);
  pCVar2 = this;
  do {
    this_00 = pCVar6;
    if (this_00 == (CSceneFxNod *)0x0) {
LAB_007b9fe5:
      if (param_1 != (CSceneFxNod *)0x0) {
        PreLoad(this,(CSceneFxCompo *)unaff_ESI);
      }
      *(CSceneFxNod **)(this + 0x14) = param_1;
      if (!bVar1) {
        if (param_1 == (CSceneFxNod *)0x0) {
          CameraCallBack(this,(CSceneFxNod *)0x0,(int)unaff_ESI);
          pCVar7 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x34);
          unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x7ba013;
          pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EBX);
          if (pCVar7 < pCVar4) {
            unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x7ba01f;
            pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this + 0x38,pCVar7,unaff_EBP);
            this = *(CSceneFxNod **)pSVar5;
            unaff_EBX = (CFastBuffer<class_CCrystalFace*> *)pCVar7;
          }
          else {
            this = (CSceneFxNod *)0x0;
          }
          if (this == (CSceneFxNod *)0x0) {
            return 1;
          }
          while (*(int *)(this + 0x14) == 0) {
            pCVar7 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x34);
            pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_ESI);
            if (pCVar7 < pCVar4) {
              pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (this + 0x38,pCVar7,(ulong)unaff_EBX);
              this = *(CSceneFxNod **)pSVar5;
              unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)pCVar7;
            }
            else {
              this = (CSceneFxNod *)0x0;
            }
            if (this == (CSceneFxNod *)0x0) {
              return 1;
            }
          }
        }
        CameraCallBack(this,(CSceneFxNod *)0x1,(int)unaff_ESI);
      }
      return 1;
    }
    pCVar7 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this_00 + 0x34);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x38,unaff_ESI);
    if (pCVar7 < pCVar4) {
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00 + 0x38,pCVar7,(ulong)unaff_EBX);
      pCVar6 = *(CSceneFxNod **)pSVar5;
      unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)pCVar7;
    }
    else {
      pCVar6 = (CSceneFxNod *)0x0;
    }
    if ((pCVar6 != pCVar2) &&
       (iVar3 = NodInputSel(this_00,pCVar2,(CSceneFxNod *)unaff_ESI), iVar3 == 0)) {
      return 0;
    }
    param_1 = (CSceneFxNod *)param_2;
    if (*(int *)(this_00 + 0x14) != 0) {
      bVar1 = true;
      goto LAB_007b9fe5;
    }
    pCVar6 = *(CSceneFxNod **)(this_00 + 0x44);
    pCVar2 = this_00;
  } while( true );
}
}

// =================================================
// Function: CSceneFxNod::StartStopSafe
// =================================================
int __thiscall CSceneFxNod::StartStopSafe(CSceneFxNod *this,CSceneFxNod *param_1,int param_2)
{
{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  
  if ((*(int *)(this + 0x1c) == 0) || (*(int *)(*(int *)(this + 0x1c) + 0x15c) == 0)) {
    param_1 = (CSceneFxNod *)0x0;
  }
  else {
    piVar1 = *(int **)(this + 0x30);
    if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x7c))(), iVar2 != 0)) {
      if (param_1 == (CSceneFxNod *)0x0) {
        (**(code **)(*piVar1 + 0x90))(0x3f800000);
      }
      param_1 = (CSceneFxNod *)0x1;
    }
  }
  if (*(int *)(this + 0x14) == 0) {
    if (param_1 != (CSceneFxNod *)0x0) {
      iVar2 = StartStop(this,(CSceneFxNod *)0x1,unaff_ESI);
      return iVar2;
    }
  }
  else if (param_1 == (CSceneFxNod *)0x0) {
    iVar2 = StartStop(this,(CSceneFxNod *)0x0,unaff_ESI);
    return iVar2;
  }
  return 1;
}
}

// =================================================
// Function: CSceneFxNod::UpdateAllActivityFromScene
// =================================================
void __thiscall
CSceneFxNod::UpdateAllActivityFromScene(CSceneFxNod *this,CSceneFxNod *param_1,CScene3d *param_2)
{
{
  int *piVar1;
  int iVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  int unaff_EBP;
  CHmsCamera *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CSceneFxNod *unaff_EDI;
  CScene3d *unaff_retaddr;
  
  if ((*(int *)(this + 0x1c) != 0) ||
     (*(CSceneFxNod **)(this + 0x1c) = param_1, param_1 != (CSceneFxNod *)0x0)) {
    piVar1 = *(int **)(this + 0x30);
    if ((*(int *)(*(int *)(this + 0x1c) + 0x15c) != 0) &&
       (((iVar2 = CanActive(this,(CSceneFxFlares *)0x1,unaff_ESI), iVar2 != 0 &&
         (piVar1 != (int *)0x0)) && (iVar2 = (**(code **)(*piVar1 + 0x84))(), iVar2 != 0)))) {
      PreLoad(this,(CSceneFxCompo *)unaff_EDI);
    }
    StartStopSafe(this,(CSceneFxNod *)0x0,unaff_EBP);
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EBX);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x38,pCVar5,(ulong)unaff_EDI);
        unaff_EDI = *(CSceneFxNod **)(this + 0x1c);
        UpdateAllActivityFromScene(*(CSceneFxNod **)pSVar4,unaff_EDI,unaff_retaddr);
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar3);
    }
  }
  return;
}
}

