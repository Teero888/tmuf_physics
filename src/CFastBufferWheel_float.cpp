// Class implementation: CFastBufferWheel_float

// =================================================
// Function: CFastBufferWheel<float>::CFastBufferWheel<float>
// =================================================
void __thiscall
CFastBufferWheel<float>::CFastBufferWheel<float>(void *this,CFastBufferWheel<float> *param_1)
{
{
  ulong unaff_ESI;
  CFastBuffer<struct_SMeshOctreeCell> *in_stack_00000008;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ae5188;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)this = 0;
  *(CFastBuffer<struct_SMeshOctreeCell> **)((int)this + 0x10) = in_stack_00000008;
  if (in_stack_00000008 != (CFastBuffer<struct_SMeshOctreeCell> *)0x0) {
    CFastBuffer<struct_CGameCampaignScores::SFilterInfos*>::InitSize
              (this,in_stack_00000008,unaff_ESI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<float>::CopyFromWheel
// =================================================
void __thiscall
CFastBufferWheel<float>::CopyFromWheel
          (void *this,
          CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1,
          CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_2)
{
{
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar1;
  ulong uVar2;
  uint uVar3;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  ulong unaff_retaddr;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_EDI);
  pCVar1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)
           CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize(param_2,unaff_ESI);
  CFastBuffer<float>::SetSizeAtLeast(this,pCVar1,unaff_retaddr);
  uVar2 = CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize
                    (param_2,(CFastBuffer<struct_SCtnForcedMods::SEnvMod> *)param_1);
  uVar3 = 0;
  *(ulong *)((int)this + 8) = uVar2;
  if (uVar2 != 0) {
    do {
      *(undefined4 *)(*(int *)((int)this + 4) + uVar3 * 4) =
           *(undefined4 *)(*(int *)(param_2 + 4) + uVar3 * 4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)((int)this + 8));
  }
  *(undefined4 *)this = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return;
}
}

// =================================================
// Function: CFastBufferWheel<float>::InsertNewElemFromStart
// =================================================
SHistoryPoint * __thiscall
CFastBufferWheel<float>::InsertNewElemFromStart
          (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar2;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar3;
  uint uVar4;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar5;
  uint uVar6;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar7;
  ulong unaff_EDI;
  uint uVar8;
  uint uVar9;
  
  if ((*(int *)((int)this + 0x10) == 0) || (*(int *)this != *(int *)((int)this + 0x10))) {
    pCVar2 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8);
    pCVar7 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(*(int *)this + 1);
    if (pCVar2 < pCVar7) {
      CFastBuffer<float>::SetSizeAtLeast(this,pCVar7,unaff_EDI);
      pCVar3 = pCVar2 + -1;
      if (*(int *)((int)this + 0xc) <= (int)pCVar3) {
        do {
          iVar1 = (int)pCVar3 * 4;
          pCVar5 = pCVar3 + (*(int *)((int)this + 8) - (int)pCVar2);
          pCVar3 = pCVar3 + -1;
          *(undefined4 *)(*(int *)((int)this + 4) + (int)pCVar5 * 4) =
               *(undefined4 *)(*(int *)((int)this + 4) + iVar1);
        } while (*(int *)((int)this + 0xc) <= (int)pCVar3);
      }
      *(int *)((int)this + 0xc) =
           *(int *)((int)this + 0xc) + (*(int *)((int)this + 8) - (int)pCVar2);
    }
    else if (*(int *)((int)this + 0xc) == 0) {
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 0xc) = pCVar2;
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this = pCVar7;
  }
  else if (*(int *)((int)this + 0xc) == 0) {
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 8);
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  uVar4 = 0;
  if (3 < (int)param_2) {
    do {
      uVar8 = *(int *)((int)this + 0xc) + uVar4;
      uVar9 = *(uint *)((int)this + 8);
      uVar6 = uVar8 + 1;
      if (uVar9 <= uVar6) {
        uVar6 = uVar6 - uVar9;
      }
      if (uVar9 <= uVar8) {
        uVar8 = uVar8 - uVar9;
      }
      *(undefined4 *)(*(int *)((int)this + 4) + uVar8 * 4) =
           *(undefined4 *)(*(int *)((int)this + 4) + uVar6 * 4);
      uVar8 = *(uint *)((int)this + 8);
      iVar1 = *(int *)((int)this + 0xc) + uVar4;
      uVar6 = iVar1 + 2;
      if (uVar8 <= uVar6) {
        uVar6 = uVar6 - uVar8;
      }
      uVar9 = iVar1 + 1;
      if (uVar8 <= uVar9) {
        uVar9 = uVar9 - uVar8;
      }
      *(undefined4 *)(*(int *)((int)this + 4) + uVar9 * 4) =
           *(undefined4 *)(*(int *)((int)this + 4) + uVar6 * 4);
      iVar1 = *(int *)((int)this + 0xc) + uVar4;
      uVar8 = *(uint *)((int)this + 8);
      uVar6 = iVar1 + 3;
      if (uVar8 <= uVar6) {
        uVar6 = uVar6 - uVar8;
      }
      uVar9 = iVar1 + 2;
      if (uVar8 <= uVar9) {
        uVar9 = uVar9 - uVar8;
      }
      *(undefined4 *)(*(int *)((int)this + 4) + uVar9 * 4) =
           *(undefined4 *)(*(int *)((int)this + 4) + uVar6 * 4);
      uVar8 = *(uint *)((int)this + 8);
      iVar1 = *(int *)((int)this + 0xc) + uVar4;
      uVar6 = iVar1 + 4;
      if (uVar8 <= uVar6) {
        uVar6 = uVar6 - uVar8;
      }
      uVar9 = iVar1 + 3;
      if (uVar8 <= uVar9) {
        uVar9 = uVar9 - uVar8;
      }
      uVar4 = uVar4 + 4;
      *(undefined4 *)(*(int *)((int)this + 4) + uVar9 * 4) =
           *(undefined4 *)(*(int *)((int)this + 4) + uVar6 * 4);
    } while (uVar4 < param_2 - 3);
  }
  for (; uVar4 < param_2; uVar4 = uVar4 + 1) {
    uVar8 = *(int *)((int)this + 0xc) + uVar4;
    uVar9 = *(uint *)((int)this + 8);
    uVar6 = uVar8 + 1;
    if (uVar9 <= uVar6) {
      uVar6 = uVar6 - uVar9;
    }
    if (uVar9 <= uVar8) {
      uVar8 = uVar8 - uVar9;
    }
    *(undefined4 *)(*(int *)((int)this + 4) + uVar8 * 4) =
         *(undefined4 *)(*(int *)((int)this + 4) + uVar6 * 4);
  }
  uVar4 = *(int *)((int)this + 0xc) + param_2;
  if (*(uint *)((int)this + 8) <= uVar4) {
    uVar4 = uVar4 - *(uint *)((int)this + 8);
  }
  return (SHistoryPoint *)(*(int *)((int)this + 4) + uVar4 * 4);
}
}

// =================================================
// Function: CFastBufferWheel<float>::Pull
// =================================================
int __thiscall
CFastBufferWheel<float>::Pull(void *this,CFastBufferWheel<float> *param_1,float *param_2)
{
{
  GmVec3 *pGVar1;
  int iVar2;
  CFastBufferWheel<class_GmVec3> *unaff_ESI;
  CFastBufferWheel<float> *unaff_retaddr;
  
  if (*(int *)this == 0) {
    return 0;
  }
  pGVar1 = CFastBufferWheel<unsigned_long>::Tail(this,unaff_ESI);
  *param_2 = *(float *)pGVar1;
  iVar2 = CFastBufferWheel<class_GmVec2>::Pull(this,unaff_retaddr,(float *)param_1);
  return iVar2;
}
}

// =================================================
// Function: CFastBufferWheel<float>::Push
// =================================================
void __thiscall
CFastBufferWheel<float>::Push(void *this,CFastBufferWheel<float> *param_1,float *param_2)
{
{
  SHistoryPoint *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = InsertNewElemFromStart
                     (this,(CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *)0x0,unaff_retaddr);
  *(float *)pSVar1 = *param_2;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<float>::SetCountLimit
// =================================================
void __thiscall
CFastBufferWheel<float>::SetCountLimit(void *this,CFastBufferWheel<float> *param_1,ulong param_2)
{
{
  float *pfVar1;
  int iVar2;
  CFastBufferWheel<float> *unaff_ESI;
  void *unaff_retaddr;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffe0;
  CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> local_1c [4];
  undefined1 auStack_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae51e8;
  local_c = ExceptionList;
  pfVar1 = (float *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  if (param_1 != *(CFastBufferWheel<float> **)((int)this + 0x10)) {
    CFastBufferWheel<float>(&stack0xffffffe0,param_1);
    local_4 = 0;
    iVar2 = Pull(this,(CFastBufferWheel<float> *)&param_1,pfVar1);
    while (iVar2 != 0) {
      Push(local_1c,(CFastBufferWheel<float> *)&param_2,(float *)unaff_ESI);
      unaff_ESI = (CFastBufferWheel<float> *)&stack0x0000000c;
      iVar2 = Pull(this,unaff_ESI,(float *)in_stack_ffffffe0);
    }
    CopyFromWheel(this,local_1c,
                  (CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *)
                  unaff_ESI);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (auStack_18,in_stack_ffffffe0);
  }
  ExceptionList = unaff_retaddr;
  return;
}
}

