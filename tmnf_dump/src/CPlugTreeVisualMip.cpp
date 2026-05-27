// Class implementation: CPlugTreeVisualMip

// =================================================
// Function: CPlugTreeVisualMip::AddLevel
// =================================================
void __thiscall
CPlugTreeVisualMip::AddLevel
          (CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1,CPlugTree *param_2,float param_3)
{
{
  CPlugTreeVisualMip *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int unaff_EBX;
  SFormat *unaff_EBP;
  SFormat *unaff_ESI;
  CFastArray<class_CControlBase*> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CPlugTreeVisualMip *unaff_retaddr;
  CPlugTree *in_stack_00000010;
  
  this_00 = this + 0xb4;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastArray<class_CControlBase*> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar3,
                          (ulong)unaff_ESI);
      if ((float)in_stack_00000010 < *(float *)pSVar2) break;
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  if (pCVar3 == (CFastArray<class_CControlBase*> *)pCVar1) {
    CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
              (this + 0xac,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&param_2,unaff_ESI);
    CFastArray<float>::AddTail
              (this_00,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&stack0x00000010,unaff_EBP);
  }
  else {
    CFastArray<class_CControlBase*>::InsertAt
              (this + 0xac,pCVar3,(ulong)&param_2,(CControlBase **)unaff_ESI);
    CFastArray<float>::InsertAt(this_00,pCVar3,(ulong)&stack0x00000010,(CControlBase **)unaff_EBP);
  }
  if (*(int *)(this + 0x14) != 0) {
    (**(code **)(*(int *)in_stack_00000010 + 0x78))(0);
  }
  CPlugTree::ConnectAsChild((CPlugTree *)this,in_stack_00000010,(CPlugTree *)0x1,unaff_EBX);
  if (*(int *)(this + 0xbc) == -1) {
    *(undefined4 *)(this + 0xbc) = 0;
  }
  SetDistributionFromFarZs(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugTreeVisualMip::CPlugTreeVisualMip
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugTreeVisualMip::CPlugTreeVisualMip(CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1)
{
{
  undefined4 uVar1;
  CPlugTree *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  CFastArray<class_CManoeuvre*> *in_stack_00000008;
  
  CPlugTree::CPlugTree((CPlugTree *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0xac,unaff_retaddr);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0xb4,(CFastArray<class_CManoeuvre*> *)param_1);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0xc4,in_stack_00000008);
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x1000;
  *(undefined4 *)(this + 0xcc) = 0;
  uVar1 = _DAT_00b3380c;
  *(undefined4 *)(this + 0xbc) = 0xffffffff;
  *(undefined4 *)(this + 0xd0) = uVar1;
  return;
}
}

// =================================================
// Function: CPlugTreeVisualMip::DeleteAllChilds
// =================================================
void __thiscall
CPlugTreeVisualMip::DeleteAllChilds(CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1)
{
{
  int iVar1;
  
  for (iVar1 = (**(code **)(*(int *)this + 0x7c))(); iVar1 != 0; iVar1 = iVar1 + -1) {
    (**(code **)(*(int *)this + 0x9c))(0);
  }
  return;
}
}

// =================================================
// Function: CPlugTreeVisualMip::GetMipOptimizedGroups
// =================================================
void __thiscall
CPlugTreeVisualMip::GetMipOptimizedGroups
          (CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1,int param_2,
          CFastBuffer<struct_SPlugTreeOptimGroup*> *param_3,SPlugTreeOptimCriteria *param_4,
          SPlugTreeOptimTravel *param_5)
{
{
  CPlugTreeVisualMip *unaff_retaddr;
  
  if (param_1 == (CPlugTreeVisualMip *)0x0) {
    (**(code **)(*(int *)this + 0xdc))(param_2,param_3,param_4);
  }
  else if (*(int *)(this + 0x90) == 0) {
    CPlugTree::GetChildCount((CPlugTree *)this,unaff_retaddr);
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugTreeVisualMip::SetDistributionFromFarZs
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugTreeVisualMip::SetDistributionFromFarZs(CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1)
{
{
  CPlugTreeVisualMip *pCVar1;
  float fVar2;
  float fVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  SCasterCat *pSVar8;
  SCasterCat *pSVar9;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  float unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000008;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack0000000c;
  void *in_stack_00000010;
  ulong uStack00000014;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000018;
  ulong in_stack_ffffffe8;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffec;
  ulong in_stack_fffffff0;
  float local_4;
  
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xac,unaff_EDI);
  if (pCVar7 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3) {
    CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
              (this + 0xc4,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_ESI);
    pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0xc4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP)
    ;
    *(undefined4 *)pSVar8 = 0;
    if (pCVar7 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2) {
      fVar2 = (float)_DAT_00baf470;
    }
    else {
      pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0xb4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          in_stack_ffffffe8);
      fVar2 = *(float *)pSVar8;
    }
    *(float *)(this + 0xcc) = fVar2;
    *(undefined4 *)(this + 0xd0) = _DAT_00b3d26c;
    return;
  }
  if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3) {
    pCVar1 = this + 0xb4;
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](pCVar1,pCVar7 + -2,unaff_ESI);
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP);
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(this + 0xc4);
    pCStack00000008 = pCVar11;
    CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
              (pCVar11,DAT_00d12c10,in_stack_ffffffe8);
    *(float *)(this + 0xcc) = unaff_retaddr;
    *(float *)(this + 0xd0) = 1.0 / local_4;
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
    uStack00000014 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar11,in_stack_ffffffec);
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (uStack00000014 != 0) {
      do {
        fVar2 = (float)(int)pCVar11;
        if ((int)pCVar11 < 0) {
          fVar2 = fVar2 + _DAT_00c418d0;
        }
        fVar3 = (float)(int)DAT_00d12c10;
        if ((int)DAT_00d12c10 < 0) {
          fVar3 = fVar3 + _DAT_00c418d0;
        }
        pCStack0000000c =
             (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             ((fVar2 * unaff_retaddr) / fVar3 + (float)param_1);
        pCVar6 = pCVar10 + 1;
        pCVar5 = pCStack00000008;
        pCVar4 = pCVar10 + 1;
        while ((pCStack00000008 = pCVar6, pCVar4 < pCVar7 &&
               (pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (pCVar1,pCVar10,in_stack_fffffff0), pCVar5 = pCStack00000008,
               *(float *)pSVar8 < (float)in_stack_00000010))) {
          pCStack0000000c = pCStack0000000c + 1;
          pCVar10 = pCVar10 + 1;
          pCVar6 = pCStack00000008;
          pCVar4 = pCStack0000000c;
        }
        pCStack00000008 = pCVar5;
        pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (in_stack_00000010,pCVar11,in_stack_fffffff0);
        pCVar11 = pCVar11 + 1;
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar8 = pCVar10;
      } while (pCVar11 < in_stack_00000018);
    }
    return;
  }
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this + 0xc4,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_EBX);
  pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0xc4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  pCVar1 = this + 0xb4;
  *(undefined4 *)pSVar8 = 1;
  pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)pSVar8;
  pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,in_stack_ffffffe8
                     );
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      (ulong)in_stack_ffffffec);
  *(float *)(this + 0xd0) = 1.0 / (*(float *)pSVar8 - *(float *)pSVar9);
  return;
}
}

// =================================================
// Function: CPlugTreeVisualMip::SetLevelFarZ
// =================================================
void __thiscall
CPlugTreeVisualMip::SetLevelFarZ
          (CPlugTreeVisualMip *this,CPlugTreeVisualMip *param_1,ulong param_2,float param_3)
{
{
  CPlugTreeVisualMip *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CPlugTreeVisualMip *unaff_retaddr;
  float in_stack_00000010;
  float in_stack_00000018;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xac,unaff_EDI);
  if (uVar1 < param_2) {
    return;
  }
  if ((param_2 == 0) ||
     (pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0xb4,
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 - 1),unaff_EBP)
     , *(float *)pSVar2 < in_stack_00000010)) {
    this_00 = this + 0xb4;
    uVar1 = 0x86b75b;
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 1) < pCVar3) {
      uVar1 = 0x86b767;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_2 + 1),
                          unaff_EBX);
      if (*(float *)pSVar2 <= in_stack_00000018) goto LAB_0086b786;
    }
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,uVar1);
    *(float *)pSVar2 = in_stack_00000010;
  }
LAB_0086b786:
  SetDistributionFromFarZs(this,unaff_retaddr);
  return;
}
}

