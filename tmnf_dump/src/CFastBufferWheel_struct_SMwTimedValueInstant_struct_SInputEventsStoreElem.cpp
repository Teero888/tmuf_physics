// Class implementation: CFastBufferWheel_struct_SMwTimedValueInstant_struct_SInputEventsStoreElem

// =================================================
// Function: CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>
// =================================================
void __thiscall
CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::
CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>
          (void *this,
          CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1,
          ulong param_2)
{
{
  ulong unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ae0308;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)this = 0;
  *(ulong *)((int)this + 0x10) = param_2;
  if (param_2 != 0) {
    CFastBuffer<struct_CFuncClouds::SHeightPoint>::InitSize
              (this,(CFastBuffer<struct_SMeshOctreeCell> *)param_2,unaff_ESI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::CopyFromWheel
// =================================================
/* WARNING: Variable defined which should be unmapped: param_1 */

void __thiscall
CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::CopyFromWheel
          (void *this,
          CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1,
          CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_2)
{
{
  int iVar1;
  int iVar2;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar3;
  ulong uVar4;
  uint uVar5;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  ulong unaff_retaddr;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)
           CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize(param_2,unaff_ESI);
  CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast(this,pCVar3,unaff_retaddr);
  uVar4 = CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize
                    (param_2,(CFastBuffer<struct_SCtnForcedMods::SEnvMod> *)param_1);
  *(ulong *)((int)this + 8) = uVar4;
  if (uVar4 != 0) {
    uVar5 = 0;
    do {
      iVar1 = *(int *)(param_2 + 4);
      iVar2 = *(int *)((int)this + 4);
      *(undefined4 *)(iVar2 + uVar5 * 8) = *(undefined4 *)(iVar1 + uVar5 * 8);
      *(undefined4 *)(iVar2 + 4 + uVar5 * 8) = *(undefined4 *)(iVar1 + 4 + uVar5 * 8);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)((int)this + 8));
  }
  *(undefined4 *)this = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return;
}
}

// =================================================
// Function: CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::Head
// =================================================
SBlockState * __thiscall
CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::Head
          (void *this,
          CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 0xc);
  if (*(uint *)((int)this + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 8);
  }
  return (SBlockState *)(*(int *)((int)this + 4) + uVar1 * 8);
}
}

// =================================================
// Function: CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::InsertFromStart
// =================================================
void __thiscall
CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::InsertFromStart
          (void *this,
          CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1,
          ulong param_2,SMwTimedValueInstant<struct_SInputEventsStoreElem> *param_3)
{
{
  undefined4 uVar1;
  SHistoryPoint *pSVar2;
  ulong unaff_retaddr;
  
  pSVar2 = CFastBufferWheel<class_GmVec2>::InsertNewElemFromStart
                     (this,(CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *)param_1,unaff_retaddr
                     );
  uVar1 = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)pSVar2 = *(undefined4 *)param_3;
  *(undefined4 *)(pSVar2 + 4) = uVar1;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::Tail
// =================================================
GmVec3 * __thiscall
CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::Tail
          (void *this,CFastBufferWheel<class_GmVec3> *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 0xc) + -1 + *(int *)this;
  if (*(uint *)((int)this + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 8);
  }
  return (GmVec3 *)(*(int *)((int)this + 4) + uVar1 * 8);
}
}

