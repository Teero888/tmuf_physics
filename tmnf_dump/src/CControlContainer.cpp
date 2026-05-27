// Class implementation: CControlContainer

// =================================================
// Function: CControlContainer::CControlContainer
// =================================================
void __thiscall
CControlContainer::CControlContainer(CControlContainer *this,CControlContainer *param_1)
{
{
  ulong unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  CControlContainer *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ac67d4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CControlBase::CControlBase
            ((CControlBase *)this,(CControlBase *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined **)(this + 0x13c) = PTR_DAT_00bbf7d8;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x144,unaff_EDI);
  *(uint *)(this + 0xfc) = *(uint *)(this + 0xfc) & 0xfffffdd7 | 2;
  param_1 = (CControlContainer *)CONCAT31(param_1._1_3_,2);
  *(undefined4 *)(this + 0x128) = 0xffffffff;
  CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0x70),(CMwCmd *)&DAT_0000000e,unaff_ESI);
  CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0xf8),(CMwCmd *)0x10,(ulong)pCVar1);
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x140) = 0xffffffff;
  *(undefined4 *)(this + 0x120) = 1;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CControlContainer::CreateControl
// =================================================
CControlBase * __thiscall
CControlContainer::CreateControl
          (CControlContainer *this,CControlContainer *param_1,char *param_2,char *param_3,
          char *param_4,CMwNod *param_5,char *param_6,CControlStyle *param_7)
{
{
  char cVar1;
  char *pcVar2;
  char *extraout_EAX;
  CControlBase *pCVar3;
  undefined1 *puVar4;
  CControlStyle *unaff_ESI;
  char *local_1c;
  int local_18;
  undefined1 local_14 [8];
  void *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = &LAB_00ac69b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_1c = param_2;
  if (param_2 == (char *)0x0) {
    local_1c = "";
  }
  if (local_1c == (char *)0x0) {
    local_18 = 0;
  }
  else {
    pcVar2 = local_1c;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    local_18 = (int)pcVar2 - (int)(local_1c + 1);
  }
  CFastStringInt::CFastStringInt
            (local_14,(CFastStringInt *)&local_1c,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  pCVar3 = CreateControl(this,(CControlContainer *)param_2,extraout_EAX,param_4,(char *)param_5,
                         (CMwNod *)param_6,(char *)param_7,unaff_ESI);
  if (local_8 != PTR_DAT_00bbf7dc) {
    if ((local_8[-1] & 0x80) == 0) {
      puVar4 = local_8 + -2;
    }
    else {
      puVar4 = local_8 + -4;
    }
    operator_delete__(puVar4);
  }
  ExceptionList = local_4;
  return pCVar3;
}
}

// =================================================
// Function: CControlContainer::DisconnectFromModel
// =================================================
void __thiscall
CControlContainer::DisconnectFromModel(CControlContainer *this,CPlugSolid *param_1,int param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffe8;
  undefined1 local_14 [4];
  CFastBuffer<class_CControlContainer*> local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ac6858;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSceneMobil::SetModel
            ((CSceneMobil *)this,(CPlugSolid *)0x0,
             (CPlugSolid *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(local_14,unaff_EDI);
  InternalFindAnchorPoints(local_10,this,0);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(local_10,unaff_ESI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (&local_c,pCVar3,(ulong)in_stack_ffffffe8);
      pCVar3 = pCVar3 + 1;
      *(undefined4 *)(*(int *)pSVar2 + 300) = 0;
    } while (pCVar3 < pCVar1);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_c,in_stack_ffffffe8);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CControlContainer::GetChildFromId
// =================================================
CPlugTree * __thiscall
CControlContainer::GetChildFromId(CControlContainer *this,CPlugTree *param_1,CMwId *param_2)
{
{
  CControlContainer *this_00;
  SCasterCat *pSVar1;
  int iVar2;
  CPlugTree *pCVar3;
  CMwId *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CMwId *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000010;
  
  if ((param_2 == (CMwId *)0x0) || (*(int *)param_1 != *(int *)(this + 0x18))) {
    this_00 = this + 0x144;
    this = (CControlContainer *)
           CFastBuffer<class_CMotionPlayer*>::GetNodFromId
                     (this_00,(CFastBuffer<class_CMotionPlayer*> *)param_1,unaff_EDI);
    if (this == (CControlContainer *)0x0) {
      if (param_2 == (CMwId *)0x0) {
        return (CPlugTree *)0x0;
      }
      pCStack00000010 =
           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCStack00000010 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar4,(ulong)unaff_EBP);
          unaff_EBP = (CMwId *)0x7002000;
          iVar2 = (**(code **)(**(int **)pSVar1 + 0x10))();
          if (iVar2 != 0) {
            pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar4,(ulong)unaff_EBP);
            unaff_EBP = param_2;
            pCVar3 = GetChildFromId(*(CControlContainer **)pSVar1,param_1,param_2);
            if (pCVar3 != (CPlugTree *)0x0) {
              return pCVar3;
            }
          }
          pCVar4 = pCVar4 + 1;
        } while (pCVar4 < pCStack00000010);
      }
      this = (CControlContainer *)0x0;
    }
  }
  return (CPlugTree *)this;
}
}

// =================================================
// Function: CControlContainer::GetFocusedChild
// =================================================
CControlBase * __thiscall
CControlContainer::GetFocusedChild(CControlContainer *this,CControlContainer *param_1)
{
{
  CControlBase CVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_ESI;
  
  CVar1 = *(CControlBase *)(this + 0xfc);
  while( true ) {
    if (((byte)CVar1 & 0x80) == 0) {
      return (CControlBase *)0x0;
    }
    if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x128) ==
        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) break;
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((CControlBase *)(this + 0x144),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x128),unaff_ESI
                       );
    this = *(CControlContainer **)pSVar2;
    unaff_ESI = 0x7002000;
    iVar3 = (**(code **)(*(int *)this + 0x10))();
    if (iVar3 == 0) {
      return (CControlBase *)this;
    }
    CVar1 = *(CControlBase *)(this + 0xfc);
  }
  return (CControlBase *)this;
}
}

// =================================================
// Function: CControlContainer::GetFocusedChildIndex
// =================================================
ulong __thiscall
CControlContainer::GetFocusedChildIndex(CControlContainer *this,CControlContainer *param_1)
{
{
  ulong uVar1;
  
  if ((((byte)this[0xfc] & 0x80) == 0) || (uVar1 = *(ulong *)(this + 0x128), uVar1 == 0xffffffff)) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}
}

// =================================================
// Function: CControlContainer::GetRelativeLocation
// =================================================
int __thiscall
CControlContainer::GetRelativeLocation
          (CControlContainer *this,CControlContainer *param_1,GmIso4 *param_2,CControlBase *param_3)
{
{
  CControlContainer *pCVar1;
  int iVar2;
  GmMat43 *unaff_EBP;
  GmIso3 aGStack_30 [4];
  undefined1 local_2c [44];
  
  pCVar1 = (CControlContainer *)(param_2 + 0x6c);
  if (*(CControlContainer **)(param_2 + 0x6c) == this) {
    (**(code **)(*(int *)this + 0x1e8))(param_1,param_2);
    return 1;
  }
  GmIso4::SetIdentity(param_1,unaff_EBP);
  iVar2 = *(int *)pCVar1;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    (**(code **)(**(int **)pCVar1 + 0x1e8))(local_2c);
    GmIso4::Mult(param_1,aGStack_30,(GmIso3 *)param_2);
    param_2 = *(GmIso4 **)pCVar1;
    if (param_2 == (GmIso4 *)this) break;
    iVar2 = *(int *)(param_2 + 0x6c);
    pCVar1 = (CControlContainer *)(param_2 + 0x6c);
  }
  return 1;
}
}

// =================================================
// Function: CControlContainer::RemoveAllChilds
// =================================================
void __thiscall
CControlContainer::RemoveAllChilds(CControlContainer *this,CControlContainer *param_1)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  CFastArray<class_CFuncShader*> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastArray<class_GmVec4> *unaff_EDI;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ac68b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (local_14,(CFastArray<class_CManoeuvre*> *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  CFastArray<class_CControlBase*>::CopyFromFastArray
            (local_10,(CFastArray<class_GmVec4> *)(this + 0x144),unaff_EDI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&local_c,unaff_ESI);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      iVar1 = *(int *)this;
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](&local_8,pCVar3,0);
      (**(code **)(iVar1 + 0x1fc))();
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar2);
  }
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(&local_8,unaff_EBP);
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CControlContainer::SetLayoutDirty
// =================================================
void __thiscall
CControlContainer::SetLayoutDirty(CControlContainer *this,CControlContainer *param_1)
{
{
  do {
    if (*(int *)(this + 0x14c) != 0) {
      *(undefined4 *)(*(int *)(this + 0x14c) + 0x148) = 1;
    }
    *(undefined4 *)(this + 0x120) = 1;
    this = *(CControlContainer **)(this + 0x6c);
  } while (this != (CControlContainer *)0x0);
  return;
}
}

