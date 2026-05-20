// Class implementation: SDx9Static

// =================================================
// Function: SDx9Static::FullScreenAddMode
// =================================================
void __thiscall
SDx9Static::FullScreenAddMode
          (void *this,SDx9Static *param_1,ulong param_2,ulong param_3,int param_4,ulong param_5)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SPackedDesc *pSVar3;
  CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
  *pCVar4;
  void *pvVar5;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastArray<struct_CDx9StateBlock::SPackedDesc> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  undefined1 *puVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00aea790;
  local_10 = ExceptionList;
  puVar7 = &stack0xffffffd8;
  ExceptionList = &local_10;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pvVar5 = (void *)((int)this + 0x78c);
  local_8 = 0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (pvVar5,(CFastBuffer<class_CCrystalFace*> *)
                             (DAT_00cca150 ^ (uint)&stack0xfffffffc));
  while ((pCVar6 < pCVar1 &&
         ((pSVar2 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                              (pvVar5,pCVar6,(ulong)unaff_EDI), *(SDx9Static **)pSVar2 != param_1 ||
          (*(ulong *)(pSVar2 + 4) != param_2))))) {
    pCVar6 = pCVar6 + 1;
  }
  if (pCVar6 == pCVar1) {
    pSVar3 = CFastArray<struct_CHmsViewport::SDisplayMode>::AddNewTailElem(pvVar5,unaff_EDI);
    *(SDx9Static **)pSVar3 = param_1;
    *(undefined4 *)(pSVar3 + 0x10) = 0;
    *(undefined4 *)(pSVar3 + 0x14) = 0;
    *(ulong *)(pSVar3 + 4) = param_2;
    pCVar4 = (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
              *)CFastBuffer<class_CCrystalFace*>::GetCount(pvVar5,unaff_ESI);
    unaff_EDI = (CFastArray<struct_CDx9StateBlock::SPackedDesc> *)0x983f85;
    CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
              ((void *)((int)this + 0x794),pCVar4,unaff_EBX);
    pCVar4 = (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
              *)CFastBuffer<class_CCrystalFace*>::GetCount
                          (pvVar5,(CFastBuffer<class_CCrystalFace*> *)pCVar1);
    CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
              ((void *)((int)this + 0x7b8),pCVar4,(ulong)puVar7);
  }
  if (param_3 == 0) {
    pvVar5 = (void *)((int)this + 0x794);
  }
  else {
    pvVar5 = (void *)((int)this + 0x7b8);
  }
  CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::AddInCat
            (pvVar5,(CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)&param_4,
             (CHmsCorpus **)pCVar6,(ulong)unaff_EDI);
  ExceptionList = local_10;
  return;
}
}

// =================================================
// Function: SDx9Static::FullScreenRetrieveModes
// =================================================
void __thiscall
SDx9Static::FullScreenRetrieveModes(void *this,SDx9Static *param_1,_D3DFORMAT param_2)
{
{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  SDx9Static **ppSVar4;
  uint uStack_34;
  SDx9Static *local_24;
  ulong local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00aea7b0;
  local_10 = ExceptionList;
  uStack_34 = DAT_00cca150 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  local_8 = 0;
  uVar1 = (**(code **)(**(int **)((int)this + 4) + 0x18))
                    (*(int **)((int)this + 4),*(undefined4 *)((int)this + 0xc),param_1);
  for (uVar3 = 0; uVar3 < uVar1; uVar3 = uVar3 + 1) {
    ppSVar4 = &local_24;
    (**(code **)(**(int **)((int)this + 4) + 0x1c))
              (*(int **)((int)this + 4),*(undefined4 *)((int)this + 0xc),param_1,uVar3);
    if ((local_18 == 0x16) || (local_18 == 0x15)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
    FullScreenAddMode(this,local_24,local_20,uVar2,local_1c,(ulong)ppSVar4);
  }
  ExceptionList = local_10;
  return;
}
}

