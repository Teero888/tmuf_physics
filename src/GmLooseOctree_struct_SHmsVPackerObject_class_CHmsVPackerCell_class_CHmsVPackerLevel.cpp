// Class implementation: GmLooseOctree_struct_SHmsVPackerObject_class_CHmsVPackerCell_class_CHmsVPackerLevel

// =================================================
// Function: AreChildrenEmpty
// =================================================
int __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
AreChildrenEmpty(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                       *param_1,SUserData param_2)
{
{
  int iVar1;
  
  iVar1 = AreChildrenEmpty(this,(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                 *)(((uint)param_1 & 0x1f) - 2),SUB41((uint)param_1 >> 5,0));
  return iVar1;
}
}

// =================================================
// Function: CellBecomeNotEmptyFlagParents
// =================================================
void __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
CellBecomeNotEmptyFlagParents
          (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
           *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 *param_1,SUserData *param_2)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  uint uVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  SUserData *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  uint unaff_retaddr;
  void *in_stack_0000000c;
  void *in_stack_00000014;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffe4;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  SCasterCat *local_8;
  uint local_4;
  
  STravelParent::STravelParent(local_18,(STravelParent *)this,param_1,unaff_EDI);
  this_00 = (void *)(local_14 + 100);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)local_10 + 1);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  if (pCVar5 < pCVar1) {
    local_14 = local_14 + 0x58;
    uVar4 = local_4;
    pSVar2 = local_8;
    do {
      uVar4 = uVar4 >> ((byte)*(undefined4 *)(pSVar2 + 0x14) & 0x1f);
      unaff_retaddr = unaff_retaddr >> ((byte)*(undefined4 *)(pSVar2 + 0x18) & 0x1f);
      pSVar2 = CFastArray<class_CHmsVPackerLevel>::operator[]
                         (in_stack_0000000c,pCVar5,(ulong)unaff_EBP);
      unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  (*(int *)(pSVar2 + 0x10) * (int)this_00 + *(int *)(pSVar2 + 4) * unaff_retaddr +
                   *(int *)pSVar2 + uVar4);
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (local_10,unaff_EBP,unaff_EBX);
      if (*(int *)pSVar3 != 0) {
        return;
      }
      *(undefined4 *)pSVar3 = 1;
      pCVar5 = pCVar5 + 1;
      unaff_EBX = 0x556c26;
      pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(in_stack_00000014,in_stack_ffffffe4);
    } while (pCVar5 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CellUpdateParentBBoxs
// =================================================
void __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
CellUpdateParentBBoxs
          (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
           *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 *param_1,CHmsVPackerCell *param_2,SUserData *param_3)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  GmRectAligned *unaff_EBP;
  SUserData *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EDI;
  uint unaff_retaddr;
  void *in_stack_00000010;
  GmRectAligned *in_stack_00000014;
  void *in_stack_00000020;
  GmVec2 *in_stack_ffffffe4;
  CHmsVPackerCell *in_stack_ffffffe8;
  int in_stack_ffffffec;
  void *local_10;
  SCasterCat *local_8;
  uint local_4;
  
  STravelParent::STravelParent
            (&stack0xffffffe8,(STravelParent *)this,
             (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *
             )param_2,unaff_ESI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)local_10 + 1);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(in_stack_ffffffec + 100),unaff_EBX);
  if (pCVar3 < pCVar1) {
    pCVar4 = (CFastBuffer<class_CCrystalFace*> *)(in_stack_ffffffec + 0x58);
    do {
      local_4 = local_4 >> ((byte)*(undefined4 *)(local_8 + 0x14) & 0x1f);
      unaff_retaddr = unaff_retaddr >> ((byte)*(undefined4 *)(local_8 + 0x18) & 0x1f);
      local_8 = CFastArray<class_CHmsVPackerLevel>::operator[]
                          (in_stack_00000010,pCVar3,(ulong)unaff_EDI);
      unaff_EDI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  (*(int *)(local_8 + 0x10) * (int)param_2 + *(int *)(local_8 + 4) * unaff_retaddr +
                   *(int *)local_8 + local_4);
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (local_10,unaff_EDI,(ulong)unaff_EBP);
      this_00 = *(void **)pSVar2;
      if ((void *)0x1 < this_00) {
        unaff_EDI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x557d0a;
        unaff_EBP = in_stack_00000014;
        GmBoxAligned::Union(this_00,in_stack_00000014,in_stack_ffffffe4);
        in_stack_ffffffe4 = (GmVec2 *)0x557d11;
        CHmsVPackerCell::BBoxHasChanged(this_00,in_stack_ffffffe8);
      }
      pCVar3 = pCVar3 + 1;
      in_stack_ffffffe8 = (CHmsVPackerCell *)0x557d1d;
      pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(in_stack_00000020,pCVar4);
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: GetCellFromUserData
// =================================================
CHmsVPackerCell ** __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
GetCellFromUserData(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                    *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                          *param_1,SUserData param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  if (((uint)param_1 & 0x1f) == 1) {
    return (CHmsVPackerCell **)(this + 0x60);
  }
  pSVar1 = CFastArray<class_CHmsVPackerLevel>::operator[]
                     (this + 100,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(((uint)param_1 & 0x1f) - 2)
                      ,unaff_EDI);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x58,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      (((uint)param_1 >> 0xe & 0x1ff) * *(int *)(pSVar1 + 4) +
                       ((uint)param_1 >> 0x17) * *(int *)(pSVar1 + 0x10) +
                       ((uint)param_1 >> 5 & 0x1ff) + *(int *)pSVar1),unaff_ESI);
  return (CHmsVPackerCell **)pSVar1;
}
}

// =================================================
// Function: GetContainingCell
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CHmsVPackerCell ** __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
GetContainingCell(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                  *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                        *param_1,GmBoxAligned *param_2,SUserData *param_3)
{
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float10 extraout_ST0;
  uint *in_stack_00000010;
  int local_18;
  
  fVar4 = *(float *)(this + 0x44) * *(float *)(param_1 + 0x10);
  fVar5 = *(float *)(this + 0x48) * *(float *)(param_1 + 0x14);
  if (fVar5 < fVar4 != (fVar5 == fVar4)) {
    fVar5 = fVar4;
  }
  fVar4 = *(float *)(this + 0x40) * *(float *)(param_1 + 0xc);
  if (fVar5 < fVar4 != (fVar5 == fVar4)) {
    fVar5 = fVar4;
  }
  if (1.0 <= fVar5) {
    __CIlog();
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             (int)ROUND((float)extraout_ST0 * _DAT_00d564f4 + (float)_DAT_00b313b8);
  }
  else {
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  }
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 100,unaff_EDI);
  if (pCVar8 < pCVar6) {
    pSVar7 = CFastArray<class_CHmsVPackerLevel>::operator[](this + 100,pCVar8,unaff_ESI);
    uVar1 = (uint)ROUND(*(float *)(pSVar7 + 0x20) *
                        (*(float *)param_1 - (*(float *)(this + 4) - *(float *)(this + 0x10))) -
                        (float)_DAT_00b313b8);
    uVar2 = (uint)ROUND(*(float *)(pSVar7 + 0x24) *
                        (*(float *)(param_1 + 4) - (*(float *)(this + 8) - *(float *)(this + 0x14)))
                        - (float)_DAT_00b313b8);
    iVar3 = (int)ROUND(*(float *)(pSVar7 + 0x28) *
                       (*(float *)(param_1 + 8) - (*(float *)(this + 0xc) - *(float *)(this + 0x18))
                       ) - (float)_DAT_00b313b8);
    if ((((-1 < (int)uVar1) && ((int)uVar1 < *(int *)(pSVar7 + 4))) && (-1 < (int)uVar2)) &&
       ((((int)uVar2 < *(int *)(pSVar7 + 8) && (-1 < iVar3)) && (iVar3 < *(int *)(pSVar7 + 0xc)))))
    {
      *in_stack_00000010 =
           ((uVar2 & 0x1ff | iVar3 << 9) << 9 | uVar1 & 0x1ff) << 5 | local_18 + 2U & 0x1f;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x58,
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                          (*(int *)(pSVar7 + 0x10) * iVar3 + *(int *)(pSVar7 + 4) * uVar2 +
                           *(int *)pSVar7 + uVar1),unaff_EBP);
      return (CHmsVPackerCell **)pSVar7;
    }
  }
  *in_stack_00000010 = *in_stack_00000010 & 0xffffffe1 | 1;
  return (CHmsVPackerCell **)(this + 0x60);
}
}

// =================================================
// Function: GetNbObjectOutside
// =================================================
ulong __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
GetNbObjectOutside(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                   *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                         *param_1)
{
{
  ulong uVar1;
  
  if (*(uint *)(this + 0x60) < 2) {
    return 0;
  }
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                    ((void *)(*(uint *)(this + 0x60) + 0x18),
                     (CFastBuffer<class_CCrystalFace*> *)param_1);
  return uVar1;
}
}

// =================================================
// Function: class_CHmsVPackerLevel>
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
          (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
           *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 *param_1)
{
{
  undefined4 uVar1;
  CFastArray<class_CManoeuvre*> *pCVar2;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a973f6;
  local_c = ExceptionList;
  pCVar2 = (CFastArray<class_CManoeuvre*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x58,pCVar2);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 100,unaff_EDI);
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 4) = 0;
  uVar1 = _DAT_00b58be0;
  *(undefined4 *)(this + 0x10) = _DAT_00b58be0;
  *(undefined4 *)(this + 0x14) = uVar1;
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x54) = 0xffffffff;
  *(undefined4 *)(this + 0x50) = 0xffffffff;
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  Update(this,(SGmSmoothReal2 *)0x0,0,0);
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: class_CHmsVPackerLevel>::AddObject
// =================================================
void __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::AddObject
          (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
           *this,CSceneMobil *param_1,CSceneObject *param_2,CSceneObjectLink **param_3)
{
{
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar1;
  void *this_00;
  CHmsVPackerCell *extraout_EAX;
  CHmsVPackerCell *pCVar2;
  ulong uVar3;
  SUserData *unaff_EBX;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CHmsVPackerCell *unaff_ESI;
  SUserData *unaff_EDI;
  CSceneObject *pCVar5;
  TiXmlAttribute *unaff_retaddr;
  TiXmlAttributeSet *in_stack_00000014;
  
  pGVar4 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *)
           (*(int *)(param_1 + 0x58) + 0x4c);
  pCVar5 = (CSceneObject *)param_1;
  if (param_2 != (CSceneObject *)0x0) {
    pCVar5 = param_2;
  }
  pGVar1 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *)
           GetContainingCell(this,(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                   *)pCVar5,(GmBoxAligned *)pGVar4,unaff_EDI);
  if (*(CHmsVPackerCell **)pGVar1 < (CHmsVPackerCell *)0x2) {
    this_00 = operator_new(0x8c);
    if (this_00 == (void *)0x0) {
      pCVar2 = (CHmsVPackerCell *)0x0;
    }
    else {
      CHmsVPackerCell::CHmsVPackerCell(this_00,unaff_ESI);
      pCVar2 = extraout_EAX;
    }
    *(CHmsVPackerCell **)pGVar1 = pCVar2;
    if (pGVar1 != this + 0x60) {
      *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + 1;
    }
  }
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(*(CHmsVPackerCell **)pGVar1 + 0x18,unaff_EBP);
  if (uVar3 == 0) {
    if (pGVar1 != this + 0x60) {
      CellBecomeNotEmptyFlagParents(this,pGVar4,unaff_EBX);
    }
    pCVar2 = *(CHmsVPackerCell **)pGVar1;
    *(undefined4 *)pCVar2 = *(undefined4 *)pCVar5;
    *(undefined4 *)(pCVar2 + 4) = *(undefined4 *)(pCVar5 + 4);
    *(undefined4 *)(pCVar2 + 8) = *(undefined4 *)(pCVar5 + 8);
    *(undefined4 *)(pCVar2 + 0xc) = *(undefined4 *)(pCVar5 + 0xc);
    *(undefined4 *)(pCVar2 + 0x10) = *(undefined4 *)(pCVar5 + 0x10);
    *(undefined4 *)(pCVar2 + 0x14) = *(undefined4 *)(pCVar5 + 0x14);
    if (2 < ((byte)*(undefined4 *)pGVar4 & 0x1f)) {
      (**(code **)(*(int *)this + 0xc))(*(CHmsVPackerCell **)pGVar1,*(undefined4 *)pGVar4);
    }
  }
  else {
    GmBoxAligned::Union(*(CHmsVPackerCell **)pGVar1,(GmRectAligned *)pCVar5,(GmVec2 *)unaff_EBX);
  }
  CFastBuffer<struct_SHmsVPackerObject>::Add
            (*(CHmsVPackerCell **)pGVar1 + 0x18,in_stack_00000014,unaff_retaddr);
  CHmsVPackerCell::BBoxHasChanged(*(CHmsVPackerCell **)pGVar1,(CHmsVPackerCell *)param_1);
  if (1 < ((byte)*(undefined4 *)pGVar4 & 0x1f)) {
    CellUpdateParentBBoxs
              (this,*(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                      **)pGVar1,(CHmsVPackerCell *)pGVar4,(SUserData *)param_2);
  }
  if (pGVar1 != this + 0x60) {
    *(int *)(this + 0x70) = *(int *)(this + 0x70) + 1;
  }
  return;
}
}

// =================================================
// Function: class_CHmsVPackerLevel>::CellDelete
// =================================================
void __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::CellDelete
          (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
           *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                 *param_1,SUserData *param_2)
{
{
  uint uVar1;
  int iVar2;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  uint uVar6;
  uint unaff_EBX;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar7;
  ulong unaff_EBP;
  CHmsVPackerCell *unaff_ESI;
  uint uVar8;
  SUserData unaff_DI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  undefined4 *in_stack_00000010;
  undefined4 *in_stack_00000018;
  CHmsVPackerCell *this_00;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar10;
  int iStack_4;
  
  pGVar10 = this;
  if (((byte)*(undefined4 *)param_1 & 0x1f) == 1) {
    pGVar3 = this + 0x60;
  }
  else {
    pGVar3 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *
             )GetCellFromUserData(this,*(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                         **)param_1,unaff_DI);
  }
  this_00 = *(CHmsVPackerCell **)pGVar3;
  if (this_00 != (CHmsVPackerCell *)0x0) {
    CHmsVPackerCell::~CHmsVPackerCell(this_00,unaff_ESI);
    operator_delete(this_00);
    unaff_ESI = this_00;
  }
  if ((*(uint *)param_1 & 0x1f) == 1) {
    *(CHmsVPackerCell **)pGVar3 = (CHmsVPackerCell *)0x0;
    *(undefined4 *)param_1 = 0;
    return;
  }
  if (((*(uint *)param_1 & 0x1f) != 2) &&
     (iVar2 = AreChildrenEmpty(this,*(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                      **)param_1,SUB41(unaff_ESI,0)), iVar2 == 0)) {
    *(CHmsVPackerCell **)pGVar3 = (CHmsVPackerCell *)0x1;
    *(undefined4 *)param_1 = 0;
    return;
  }
  *(CHmsVPackerCell **)pGVar3 = (CHmsVPackerCell *)0x0;
  pGVar3 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this + 100,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  uVar1 = *(uint *)param_1;
  pSVar4 = CFastArray<class_CHmsVPackerLevel>::operator[]
                     (this + 100,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uVar1 & 0x1f) - 2),
                      unaff_EBP);
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uVar1 & 0x1f) - 1);
  uVar6 = uVar1 >> 5 & 0x1ff;
  uVar8 = uVar1 >> 0xe & 0x1ff;
  pGVar7 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *)
           (uVar1 >> 0x17);
  if (pGVar3 <= pCVar9) {
    *in_stack_00000010 = 0;
    return;
  }
  do {
    uVar6 = uVar6 >> ((byte)*(undefined4 *)(pSVar4 + 0x14) & 0x1f);
    uVar8 = uVar8 >> ((byte)*(undefined4 *)(pSVar4 + 0x18) & 0x1f);
    pGVar7 = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *
             )((uint)pGVar7 >> ((byte)*(undefined4 *)(pSVar4 + 0x1c) & 0x1f));
    pSVar4 = CFastArray<class_CHmsVPackerLevel>::operator[]
                       ((void *)(iStack_4 + 100),pCVar9,unaff_EBX);
    pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(uVar6 + 0x58),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        (pGVar3 + *(int *)(pSVar4 + 0x10) * (int)pGVar7 +
                                  *(int *)(pSVar4 + 4) * uVar8 + *(int *)pSVar4),(ulong)pGVar10);
    if (1 < *(uint *)pSVar5) {
      *in_stack_00000018 = 0;
      return;
    }
    unaff_EBX = uVar8;
    pGVar10 = pGVar7;
    iVar2 = AreChildrenEmpty(pGVar3,(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                     *)pCVar9,SUB41(param_2,0));
    if (iVar2 == 0) break;
    pCVar9 = pCVar9 + 1;
    *(undefined4 *)pGVar3 = 0;
  } while (pCVar9 < param_2);
  *in_stack_00000010 = 0;
  return;
}
}

// =================================================
// Function: class_CHmsVPackerLevel>::SubObject
// =================================================
CHmsVPackerCell ** __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::SubObject
          (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
           *this,CHmsZoneVPacker *param_1,SHmsVPackerObject *param_2)
{
{
  CFastBuffer<class_CCrystalFace*> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong uVar4;
  int iVar5;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  ulong unaff_EBP;
  SUserData *this_00;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  SUserData unaff_DI;
  SUserData *pSVar7;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
  *in_stack_00000010;
  int in_stack_00000014;
  undefined4 *in_stack_00000018;
  CHmsVPackerCell **in_stack_00000024;
  CHmsVPackerCell **in_stack_00000028;
  CFastBuffer<class_CCrystalFace*> *pCVar8;
  GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *pGVar9;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffffc;
  
  pCVar8 = *(CFastBuffer<class_CCrystalFace*> **)(param_1 + 0x58);
  pCVar1 = pCVar8 + 0x4c;
  pGVar9 = this;
  if (((byte)*(undefined4 *)pCVar1 & 0x1f) != 1) {
    param_2 = (SHmsVPackerObject *)
              GetCellFromUserData(this,*(GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                                         **)pCVar1,unaff_DI);
  }
  pSVar7 = *(SUserData **)param_2;
  this_00 = pSVar7 + 0x18;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CControlDisplayGraph::SGraph>::operator[]
                         (this_00,pCVar6,unaff_EBP);
      if (*(SUserData **)(pSVar3 + 0x58) == pSVar7) {
        if (in_stack_00000014 != 0) {
          pSVar3 = CFastBuffer<struct_CControlDisplayGraph::SGraph>::operator[]
                             (this_00,pCVar6,unaff_EBX);
          for (iVar5 = 0x1b;
              this = (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
                      *)param_2, iVar5 != 0; iVar5 = iVar5 + -1) {
            *in_stack_00000018 = *(undefined4 *)pSVar3;
            pSVar3 = pSVar3 + 4;
            in_stack_00000018 = in_stack_00000018 + 1;
          }
        }
        if (((byte)*(undefined4 *)pSVar7 & 0x1f) != 1) {
          *(int *)(this + 0x70) = *(int *)(this + 0x70) + -1;
          uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar1);
          if (uVar4 == 1) {
            *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + -1;
          }
        }
        CFastBuffer<struct_SHmsVPackerObject>::ReplaceByLastAt
                  (this_00,(CFastBufferRef<class_CGameMobil> *)pCVar6,1,(ulong)pCVar1);
        uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar8);
        if (((uVar4 == 0) &&
            (uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                               ((void *)(in_stack_00000014 + 0x5c),
                                (CFastBuffer<class_CCrystalFace*> *)pGVar9), uVar4 == 0)) &&
           (uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                              ((void *)(in_stack_00000014 + 0x68),in_stack_fffffffc), uVar4 == 0)) {
          CellDelete(this,in_stack_00000010,pSVar7);
          return in_stack_00000028;
        }
        *(undefined4 *)in_stack_00000010 = 0;
        return in_stack_00000024;
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar2);
  }
  return (CHmsVPackerCell **)&DAT_00d678d0;
}
}

// =================================================
// Function: class_CHmsVPackerLevel>::Update
// =================================================
float __thiscall
GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>::Update
          (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>
           *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3)
{
{
  float fVar1;
  
  fVar1 = Update(this,param_1,param_2,param_3);
  return fVar1;
}
}

