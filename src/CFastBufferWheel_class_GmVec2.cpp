// Class implementation: CFastBufferWheel_class_GmVec2

// =================================================
// Function: CFastBufferWheel<class_GmVec2>::CFastBufferWheel<class_GmVec2>
// =================================================
void __thiscall
CFastBufferWheel<class_GmVec2>::CFastBufferWheel<class_GmVec2>
          (void *this,CFastBufferWheel<class_GmVec2> *param_1,ulong param_2)
{
{
  ulong unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ace5c8;
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
// Function: CFastBufferWheel<class_GmVec2>::InsertNewElemFromStart
// =================================================
SHistoryPoint * __thiscall
CFastBufferWheel<class_GmVec2>::InsertNewElemFromStart
          (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2)
{
{
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar5;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar6;
  uint uVar7;
  uint uVar8;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar9;
  ulong unaff_EDI;
  uint uVar10;
  
  if ((*(int *)((int)this + 0x10) == 0) || (*(int *)this != *(int *)((int)this + 0x10))) {
    pCVar1 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8);
    pCVar9 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(*(int *)this + 1);
    if (pCVar1 < pCVar9) {
      CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast(this,pCVar9,unaff_EDI);
      pCVar6 = pCVar1 + -1;
      if (*(int *)((int)this + 0xc) <= (int)pCVar6) {
        do {
          iVar2 = *(int *)((int)this + 4);
          pCVar5 = pCVar6 + (*(int *)((int)this + 8) - (int)pCVar1);
          *(undefined4 *)(iVar2 + (int)pCVar5 * 8) = *(undefined4 *)(iVar2 + (int)pCVar6 * 8);
          iVar4 = (int)pCVar6 * 8;
          pCVar6 = pCVar6 + -1;
          *(undefined4 *)(iVar2 + 4 + (int)pCVar5 * 8) = *(undefined4 *)(iVar2 + 4 + iVar4);
        } while (*(int *)((int)this + 0xc) <= (int)pCVar6);
      }
      *(int *)((int)this + 0xc) =
           *(int *)((int)this + 0xc) + (*(int *)((int)this + 8) - (int)pCVar1);
    }
    else if (*(int *)((int)this + 0xc) == 0) {
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 0xc) = pCVar1;
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
      uVar3 = *(uint *)((int)this + 8);
      uVar8 = *(int *)((int)this + 0xc) + uVar10;
      uVar7 = uVar8 + 1;
      if (uVar3 <= uVar7) {
        uVar7 = uVar7 - uVar3;
      }
      if (uVar3 <= uVar8) {
        uVar8 = uVar8 - uVar3;
      }
      iVar4 = *(int *)((int)this + 4);
      *(undefined4 *)(iVar4 + uVar8 * 8) = *(undefined4 *)(iVar4 + uVar7 * 8);
      uVar10 = uVar10 + 1;
      *(undefined4 *)(iVar4 + 4 + uVar8 * 8) = *(undefined4 *)(iVar4 + 4 + uVar7 * 8);
    } while (uVar10 < param_2);
  }
  uVar10 = *(int *)((int)this + 0xc) + param_2;
  if (*(uint *)((int)this + 8) <= uVar10) {
    uVar10 = uVar10 - *(uint *)((int)this + 8);
  }
  return (SHistoryPoint *)(*(int *)((int)this + 4) + uVar10 * 8);
}
}

// =================================================
// Function: CFastBufferWheel<class_GmVec2>::Pull
// =================================================
int __thiscall
CFastBufferWheel<class_GmVec2>::Pull(void *this,CFastBufferWheel<float> *param_1,float *param_2)
{
{
  if (*(int *)this == 0) {
    return 0;
  }
  *(int *)this = *(int *)this + -1;
  return 1;
}
}

// =================================================
// Function: CFastBufferWheel<class_GmVec2>::Push
// =================================================
void __thiscall
CFastBufferWheel<class_GmVec2>::Push(void *this,CFastBufferWheel<float> *param_1,float *param_2)
{
{
  float fVar1;
  SHistoryPoint *pSVar2;
  ulong unaff_retaddr;
  
  pSVar2 = InsertNewElemFromStart
                     (this,(CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *)0x0,unaff_retaddr);
  fVar1 = param_2[1];
  *(float *)pSVar2 = *param_2;
  *(float *)(pSVar2 + 4) = fVar1;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<class_GmVec2>::SetCountLimit
// =================================================
void __thiscall
CFastBufferWheel<class_GmVec2>::SetCountLimit
          (void *this,CFastBufferWheel<float> *param_1,ulong param_2)
{
{
  int iVar1;
  void *unaff_EBP;
  float *unaff_ESI;
  CFastBufferWheel<float> *in_stack_ffffffcc;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffd0;
  CFastBufferWheel<float> local_2c [4];
  CFastBufferWheel<float> local_28 [4];
  CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> local_24 [4];
  undefined1 auStack_20 [12];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00ace858;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1 != *(CFastBufferWheel<float> **)((int)this + 0x10)) {
    CFastBufferWheel<class_GmVec2>
              (local_2c,(CFastBufferWheel<class_GmVec2> *)param_1,
               DAT_00cca150 ^ (uint)&stack0xffffffc8);
    local_8 = 0;
    iVar1 = Pull(this,(CFastBufferWheel<float> *)&stack0xffffffd0,unaff_ESI);
    while (iVar1 != 0) {
      Push(local_24,local_2c,(float *)in_stack_ffffffcc);
      in_stack_ffffffcc = local_28;
      iVar1 = Pull(this,in_stack_ffffffcc,(float *)in_stack_ffffffd0);
    }
    CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::CopyFromWheel
              (this,local_24,
               (CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *)
               in_stack_ffffffcc);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (auStack_20,in_stack_ffffffd0);
  }
  ExceptionList = unaff_EBP;
  return;
}
}

