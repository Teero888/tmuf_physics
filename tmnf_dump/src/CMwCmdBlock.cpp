// Class implementation: CMwCmdBlock

// =================================================
// Function: CMwCmdBlock::CleanContext
// =================================================
void __thiscall CMwCmdBlock::CleanContext(CMwCmdBlock *this,CMwCmdBlock *param_1)
{
{
  int iVar1;
  ulong uVar2;
  
  iVar1 = *(int *)this;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this + 0x28,(CFastBuffer<class_CCrystalFace*> *)0x1);
  (**(code **)(iVar1 + 0x94))(uVar2 - 1);
  *(uint *)(this + 0x48) = *(uint *)(this + 0x48) & 0xfffffffb;
  return;
}
}

// =================================================
// Function: CMwCmdBlock::Run
// =================================================
void __thiscall CMwCmdBlock::Run(CMwCmdBlock *this,CMwCmdExpStringConcat *param_1)
{
{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  SNewTriangleVert *pSVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EDI;
  CMwCmdBlock *in_stack_00000008;
  
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_ESI);
  uVar1 = *(uint *)(this + 0x48);
  if (((uVar1 & 1) == 0) && ((uVar1 & 2) != 0)) {
    (**(code **)(*(int *)this + 0x90))();
  }
  else {
    *(uint *)(this + 0x48) = uVar1 & 0xfffffffe;
  }
  *(uint *)(this + 0x48) = *(uint *)(this + 0x48) & 0xfffffffb;
  uVar1 = *(uint *)(this + 0x44);
  while (uVar1 < uVar3) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x20,
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x44),
                        (ulong)unaff_EDI);
    unaff_EDI = (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)0x9412e4;
    (**(code **)(**(int **)pSVar4 + 0x78))();
    if (((byte)this[0x48] & 5) != 0) break;
    *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
    uVar2 = *(undefined4 *)(this + 0x44);
    pSVar5 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal>::SKey>::
             GetLastElem(this + 0x28,unaff_EDI);
    *(undefined4 *)pSVar5 = uVar2;
    uVar1 = *(uint *)(this + 0x44);
  }
  uVar1 = *(uint *)(this + 0x48);
  if ((uVar1 & 1) == 0) {
    *(undefined4 *)(this + 0x44) = 0;
    if ((uVar1 & 2) != 0) {
      CleanContext(this,in_stack_00000008);
      return;
    }
  }
  else if ((uVar1 & 2) != 0) {
    SaveContext(this,in_stack_00000008);
    return;
  }
  return;
}
}

// =================================================
// Function: CMwCmdBlock::SaveContext
// =================================================
void __thiscall CMwCmdBlock::SaveContext(CMwCmdBlock *this,CMwCmdBlock *param_1)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  SCasterCat *pSVar6;
  undefined4 *puStack00000008;
  int in_stack_0000000c;
  undefined4 *in_stack_00000014;
  ulong in_stack_fffffff8;
  SNormalDec3N *in_stack_fffffffc;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_EDI);
  pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (this + 0x28,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar1 - 1),
                      unaff_ESI);
  pSVar6 = pSVar2;
  puStack00000008 = (undefined4 *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EBP);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(pSVar2 + 4,unaff_EBX);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](this + 0x3c,pCVar5 + in_stack_0000000c,in_stack_fffffff8);
      pSVar4 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](pSVar2 + 4,pCVar5,(ulong)pSVar4);
      in_stack_fffffff8 = 0x940e42;
      CBlockVariable::operator=((CBlockVariable *)pSVar4,in_stack_fffffffc,(GmVec3 *)pSVar6);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar3);
    *in_stack_00000014 = *(undefined4 *)(this + 0x44);
    return;
  }
  *puStack00000008 = *(undefined4 *)(this + 0x44);
  return;
}
}

