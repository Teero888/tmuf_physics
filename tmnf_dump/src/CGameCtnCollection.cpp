// Class implementation: CGameCtnCollection

// =================================================
// Function: CGameCtnCollection::GetZone
// =================================================
CGameCtnZone * __thiscall
CGameCtnCollection::GetZone(CGameCtnCollection *this,CGameCtnCollection *param_1,CMwId *param_2)
{
{
  CGameCtnCollection *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x20;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
      if (*(int *)(*(int *)pSVar3 + 0x14) == iVar1) {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBP)
        ;
        return *(CGameCtnZone **)pSVar3;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return (CGameCtnZone *)0x0;
}
}

// =================================================
// Function: CGameCtnCollection::GetZoneFromLandBlockInfo
// =================================================
CGameCtnZone * __thiscall
CGameCtnCollection::GetZoneFromLandBlockInfo
          (CGameCtnCollection *this,CGameCtnCollection *param_1,CGameCtnBlockInfo *param_2)
{
{
  CGameCtnZone *pCVar1;
  int iVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x20,pCVar5,(ulong)unaff_ESI);
      pCVar1 = *(CGameCtnZone **)pSVar4;
      if (*(int *)(pCVar1 + 0x1c) == 0) {
        iVar2 = *(int *)(pCVar1 + 0x30);
LAB_0060da4e:
        if (iVar2 == in_stack_0000000c) {
          return pCVar1;
        }
      }
      else if (*(int *)(pCVar1 + 0x1c) == 1) {
        iVar2 = *(int *)(pCVar1 + 0x30);
        goto LAB_0060da4e;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar3);
  }
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,unaff_ESI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x2c,pCVar5,unaff_EBP);
      pCVar1 = *(CGameCtnZone **)pSVar4;
      if (*(int *)(pCVar1 + 0x1c) == 0) {
        iVar2 = *(int *)(pCVar1 + 0x30);
LAB_0060da96:
        if (iVar2 == in_stack_00000010) {
          return pCVar1;
        }
      }
      else if (*(int *)(pCVar1 + 0x1c) == 1) {
        iVar2 = *(int *)(pCVar1 + 0x30);
        goto LAB_0060da96;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar3);
  }
  return (CGameCtnZone *)0x0;
}
}

// =================================================
// Function: CGameCtnCollection::SetCurrentZone
// =================================================
void __thiscall
CGameCtnCollection::SetCurrentZone
          (CGameCtnCollection *this,CGameCtnCollection *param_1,CMwId *param_2)
{
{
  CGameCtnZone *pCVar1;
  CMwId *unaff_ESI;
  
  pCVar1 = GetZone(this,param_1,unaff_ESI);
  *(CGameCtnZone **)(this + 0x3c) = pCVar1;
  return;
}
}

