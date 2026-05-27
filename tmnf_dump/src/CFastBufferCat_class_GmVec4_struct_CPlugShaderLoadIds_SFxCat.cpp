// Class implementation: CFastBufferCat_class_GmVec4_struct_CPlugShaderLoadIds_SFxCat

// =================================================
// Function: struct_CPlugShaderLoadIds::SFxCat>::AddCatOfElems
// =================================================
SFxCat * __thiscall
CFastBufferCat<class_GmVec4,struct_CPlugShaderLoadIds::SFxCat>::AddCatOfElems
          (void *this,CFastBufferCat<class_GmVec4,struct_CPlugShaderLoadIds::SFxCat> *param_1,
          ulong param_2)
{
{
  SLoadedLight *pSVar1;
  ulong uVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  ulong unaff_retaddr;
  int in_stack_0000000c;
  
  pSVar1 = CFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo>::AddNewElem(this,unaff_EDI);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0xc),unaff_ESI);
  *(ulong *)pSVar1 = uVar2;
  *(int *)(pSVar1 + 4) = in_stack_0000000c;
  CFastBuffer<class_GmVec4>::AllocSetCount
            ((void *)((int)this + 0xc),(CFastBuffer<class_GxVertex2> *)(uVar2 + in_stack_0000000c),
             unaff_retaddr);
  return (SFxCat *)pSVar1;
}
}

