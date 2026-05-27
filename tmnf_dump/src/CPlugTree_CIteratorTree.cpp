// Class implementation: CPlugTree_CIteratorTree

// =================================================
// Function: CPlugTree::CIteratorTree::CIteratorTree
// =================================================
void __thiscall
CPlugTree::CIteratorTree::CIteratorTree
          (void *this,CIteratorTree *param_1,CPlugTree *param_2,EMode param_3)
{
{
  EMode unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a96fd8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  ResetItTree(this,(CIteratorTree *)param_2,(CPlugTree *)param_3,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CPlugTree::CIteratorTree::GetNextTree
// =================================================
CPlugModelTree * __thiscall
CPlugTree::CIteratorTree::GetNextTree(void *this,CPlugModelTree_ItTree *param_1)
{
{
  CPlugModelTree *pCVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  uint uVar5;
  SNewTriangleVert *pSVar6;
  CPlugModelTree_ItTree *unaff_EBP;
  CPlugTree *unaff_ESI;
  int *piVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_ffffffe8;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar8;
  CFastBuffer<class_CCrystalFace*> *pCVar9;
  void *pvStack_4;
  
  pCVar1 = *(CPlugModelTree **)((int)this + 0xc);
  *(undefined4 *)((int)this + 0xc) = 0;
  pvStack_4 = this;
  iVar2 = (**(code **)(*(int *)pCVar1 + 0x7c))();
  if (iVar2 == 0) {
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
    if (uVar4 != 0) {
      piVar7 = *(int **)(pCVar1 + 0x24);
      pCVar9 = (CFastBuffer<class_CCrystalFace*> *)0x84a025;
      uVar5 = (**(code **)(*piVar7 + 0x7c))();
      pSVar6 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(this,in_stack_ffffffe8);
      if (uVar5 <= *(int *)pSVar6 + 1U) {
        do {
          pCVar8 = (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
                   0x84a03e;
          uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this,pCVar9);
          if (uVar4 < 2) goto LAB_0084a07a;
          *(int *)this = *(int *)this + -1;
          piVar7 = (int *)piVar7[9];
          pCVar9 = (CFastBuffer<class_CCrystalFace*> *)0x84a052;
          uVar5 = (**(code **)(*piVar7 + 0x7c))();
          pSVar6 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(this,pCVar8);
        } while (uVar5 <= *(int *)pSVar6 + 1U);
      }
      *(int *)pSVar6 = *(int *)pSVar6 + 1;
      uVar3 = (**(code **)(*piVar7 + 0x80))(*(int *)pSVar6);
      *(undefined4 *)((int)this + 0xc) = uVar3;
    }
  }
  else {
    pvStack_4 = (void *)0x0;
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this,(TiXmlAttributeSet *)&pvStack_4,(TiXmlAttribute *)unaff_EDI);
    uVar3 = (**(code **)(*(int *)pCVar1 + 0x80))(0);
    *(undefined4 *)((int)this + 0xc) = uVar3;
  }
LAB_0084a07a:
  if (((*(int *)((int)this + 0x10) == 2) && (*(CPlugTree **)((int)this + 0xc) != (CPlugTree *)0x0))
     && (iVar2 = GetIsRooted(*(CPlugTree **)((int)this + 0xc),unaff_ESI), iVar2 != 0)) {
    GetNextTree(this,unaff_EBP);
  }
  return pCVar1;
}
}

// =================================================
// Function: CPlugTree::CIteratorTree::ResetItTree
// =================================================
void __thiscall
CPlugTree::CIteratorTree::ResetItTree
          (void *this,CIteratorTree *param_1,CPlugTree *param_2,EMode param_3)
{
{
  GmFrustumIso4 *unaff_ESI;
  CPlugModelTree_ItTree *unaff_retaddr;
  
  *(CPlugTree **)((int)this + 0x10) = param_2;
  *(CIteratorTree **)((int)this + 0xc) = param_1;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_ESI);
  if (*(int *)((int)this + 0x10) == 1) {
    GetNextTree(this,unaff_retaddr);
  }
  return;
}
}

