// Class implementation: CFastBufferWheel_class_GmVec3

// =================================================
// Function: CFastBufferWheel<class_GmVec3>::CFastBufferWheel<class_GmVec3>
// =================================================
void __thiscall
CFastBufferWheel<class_GmVec3>::CFastBufferWheel<class_GmVec3>
          (void *this,CFastBufferWheel<class_GmVec3> *param_1,ulong param_2)
{
{
  ulong unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00acee98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)this = 0;
  *(ulong *)((int)this + 0x10) = param_2;
  if (param_2 != 0) {
    CFastBuffer<struct_CSceneTrafficGraph::SEdge>::InitSize
              (this,(CFastBuffer<struct_SMeshOctreeCell> *)param_2,unaff_ESI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<class_GmVec3>::CopyFromWheel
// =================================================
void __thiscall
CFastBufferWheel<class_GmVec3>::CopyFromWheel
          (void *this,
          CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1,
          CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_2)
{
{
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar1;
  ulong uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  ulong unaff_EBX;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  uint uVar6;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_retaddr;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_EDI);
  pCVar1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)
           CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize(param_2,unaff_ESI);
  CFastBuffer<class_GmVec3>::SetSizeAtLeast(this,pCVar1,unaff_EBX);
  uVar2 = CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize(param_2,unaff_retaddr);
  uVar6 = 0;
  *(ulong *)((int)this + 8) = uVar2;
  if (uVar2 != 0) {
    iVar5 = 0;
    do {
      iVar3 = *(int *)(param_2 + 4) + iVar5;
      puVar4 = (undefined4 *)(*(int *)((int)this + 4) + iVar5);
      *puVar4 = *(undefined4 *)(*(int *)(param_2 + 4) + iVar5);
      puVar4[1] = *(undefined4 *)(iVar3 + 4);
      uVar6 = uVar6 + 1;
      puVar4[2] = *(undefined4 *)(iVar3 + 8);
      iVar5 = iVar5 + 0xc;
    } while (uVar6 < *(uint *)((int)this + 8));
  }
  *(undefined4 *)this = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return;
}
}

// =================================================
// Function: CFastBufferWheel<class_GmVec3>::InsertNewElemFromStart
// =================================================
SHistoryPoint * __thiscall
CFastBufferWheel<class_GmVec3>::InsertNewElemFromStart
          (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2)
{
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar3;
  uint uVar4;
  uint uVar5;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar6;
  uint uVar7;
  int iVar8;
  ulong unaff_EBP;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar9;
  uint uVar10;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *unaff_retaddr;
  
  if ((*(int *)((int)this + 0x10) == 0) || (*(int *)this != *(int *)((int)this + 0x10))) {
    pCVar3 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8);
    pCVar9 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(*(int *)this + 1);
    if (pCVar3 < pCVar9) {
      CFastBuffer<class_GmVec3>::SetSizeAtLeast(this,pCVar9,unaff_EBP);
      pCVar6 = pCVar3 + -1;
      if (*(int *)((int)this + 0xc) <= (int)pCVar6) {
        iVar8 = (int)pCVar6 * 0xc;
        do {
          puVar1 = (undefined4 *)(iVar8 + *(int *)((int)this + 4));
          puVar2 = (undefined4 *)
                   (*(int *)((int)this + 4) +
                   (int)(pCVar6 + (*(int *)((int)this + 8) - (int)pCVar3)) * 0xc);
          *puVar2 = *puVar1;
          puVar2[1] = puVar1[1];
          pCVar6 = pCVar6 + -1;
          puVar2[2] = puVar1[2];
          iVar8 = iVar8 + -0xc;
          pCVar9 = unaff_retaddr;
        } while (*(int *)((int)this + 0xc) <= (int)pCVar6);
      }
      *(int *)((int)this + 0xc) =
           *(int *)((int)this + 0xc) + (*(int *)((int)this + 8) - (int)pCVar3);
    }
    else if (*(int *)((int)this + 0xc) == 0) {
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 0xc) = pCVar3;
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this = pCVar9;
  }
  else if (*(int *)((int)this + 0xc) == 0) {
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 8);
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  uVar10 = 0;
  if (param_2 != 0) {
    do {
      uVar4 = *(uint *)((int)this + 8);
      uVar7 = *(int *)((int)this + 0xc) + uVar10;
      uVar5 = uVar7 + 1;
      if (uVar4 <= uVar5) {
        uVar5 = uVar5 - uVar4;
      }
      if (uVar4 <= uVar7) {
        uVar7 = uVar7 - uVar4;
      }
      puVar1 = (undefined4 *)(*(int *)((int)this + 4) + uVar5 * 0xc);
      puVar2 = (undefined4 *)(*(int *)((int)this + 4) + uVar7 * 0xc);
      *puVar2 = *puVar1;
      puVar2[1] = puVar1[1];
      uVar10 = uVar10 + 1;
      puVar2[2] = puVar1[2];
    } while (uVar10 < param_2);
  }
  uVar10 = *(int *)((int)this + 0xc) + param_2;
  if (*(uint *)((int)this + 8) <= uVar10) {
    uVar10 = uVar10 - *(uint *)((int)this + 8);
  }
  return (SHistoryPoint *)(*(int *)((int)this + 4) + uVar10 * 0xc);
}
}

// =================================================
// Function: CFastBufferWheel<class_GmVec3>::Pull
// =================================================
int __thiscall
CFastBufferWheel<class_GmVec3>::Pull(void *this,CFastBufferWheel<float> *param_1,float *param_2)
{
{
  GmVec3 *pGVar1;
  int iVar2;
  CFastBufferWheel<class_GmVec3> *unaff_ESI;
  CFastBufferWheel<float> *unaff_retaddr;
  
  if (*(int *)this == 0) {
    return 0;
  }
  pGVar1 = Tail(this,unaff_ESI);
  *param_2 = *(float *)pGVar1;
  param_2[1] = *(float *)(pGVar1 + 4);
  param_2[2] = *(float *)(pGVar1 + 8);
  iVar2 = CFastBufferWheel<class_GmVec2>::Pull(this,unaff_retaddr,(float *)param_1);
  return iVar2;
}
}

// =================================================
// Function: CFastBufferWheel<class_GmVec3>::Push
// =================================================
void __thiscall
CFastBufferWheel<class_GmVec3>::Push(void *this,CFastBufferWheel<float> *param_1,float *param_2)
{
{
  SHistoryPoint *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = InsertNewElemFromStart
                     (this,(CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *)0x0,unaff_retaddr);
  *(float *)pSVar1 = *param_2;
  *(float *)(pSVar1 + 4) = param_2[1];
  *(float *)(pSVar1 + 8) = param_2[2];
  return;
}
}

// =================================================
// Function: CFastBufferWheel<class_GmVec3>::SetCountLimit
// =================================================
void __thiscall
CFastBufferWheel<class_GmVec3>::SetCountLimit
          (void *this,CFastBufferWheel<float> *param_1,ulong param_2)
{
{
  int iVar1;
  float *unaff_ESI;
  CFastBufferWheel<float> *in_stack_ffffffd4;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffd8;
  CFastBufferWheel<float> local_24 [4];
  CFastBufferWheel<float> local_20 [8];
  CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> local_18 [4];
  undefined1 auStack_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aceec8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 != *(CFastBufferWheel<float> **)((int)this + 0x10)) {
    CFastBufferWheel<class_GmVec3>
              (local_20,(CFastBufferWheel<class_GmVec3> *)param_1,
               DAT_00cca150 ^ (uint)&stack0xffffffd0);
    iVar1 = Pull(this,(CFastBufferWheel<float> *)&stack0xffffffd8,unaff_ESI);
    while (iVar1 != 0) {
      Push(local_18,local_24,(float *)in_stack_ffffffd4);
      in_stack_ffffffd4 = local_20;
      iVar1 = Pull(this,in_stack_ffffffd4,(float *)in_stack_ffffffd8);
    }
    CopyFromWheel(this,local_18,
                  (CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *)
                  in_stack_ffffffd4);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (auStack_14,in_stack_ffffffd8);
  }
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<class_GmVec3>::Tail
// =================================================
GmVec3 * __thiscall
CFastBufferWheel<class_GmVec3>::Tail(void *this,CFastBufferWheel<class_GmVec3> *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 0xc) + -1 + *(int *)this;
  if (*(uint *)((int)this + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 8);
  }
  return (GmVec3 *)(*(int *)((int)this + 4) + uVar1 * 0xc);
}
}

