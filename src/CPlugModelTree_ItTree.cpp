// Class implementation: CPlugModelTree_ItTree

// =================================================
// Function: CPlugModelTree_ItTree::GetNextTree
// =================================================
CPlugModelTree * __thiscall
CPlugModelTree_ItTree::GetNextTree(void *this,CPlugModelTree_ItTree *param_1)
{
{
  CPlugModelTree *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  SNewTriangleVert *pSVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  int iVar5;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_retaddr;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  
  pCVar1 = *(CPlugModelTree **)((int)this + 0xc);
  *(undefined4 *)((int)this + 0xc) = 0;
  pCVar6 = this;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar1 + 0x30,unaff_EDI);
  if (uVar2 != 0) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this,(TiXmlAttributeSet *)&stack0x00000000,(TiXmlAttribute *)unaff_ESI);
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (pCVar1 + 0x30,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)unaff_EBP);
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)pSVar3;
    return pCVar1;
  }
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_ESI);
  if (uVar2 != 0) {
    iVar5 = *(int *)(pCVar1 + 0x2c);
    pSVar4 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(this,unaff_EBP);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar5 + 0x30),unaff_EBX);
    if (uVar2 <= *(int *)pSVar4 + 1U) {
      do {
        uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this,pCVar6);
        if (uVar2 < 2) {
          return pCVar1;
        }
        *(int *)this = *(int *)this + -1;
        iVar5 = *(int *)(iVar5 + 0x2c);
        pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x8a7c91;
        pSVar4 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(this,unaff_retaddr);
        unaff_retaddr =
             (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)0x8a7c9b;
        uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                          ((void *)(iVar5 + 0x30),(CFastBuffer<class_CCrystalFace*> *)param_1);
      } while (uVar2 <= *(int *)pSVar4 + 1U);
    }
    *(int *)pSVar4 = *(int *)pSVar4 + 1;
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar5 + 0x30),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar4,(ulong)pCVar6);
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)pSVar3;
  }
  return pCVar1;
}
}

