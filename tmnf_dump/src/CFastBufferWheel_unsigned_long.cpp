// Class implementation: CFastBufferWheel_unsigned_long

// =================================================
// Function: CFastBufferWheel<unsigned_long>::CFastBufferWheel<unsigned_long>
// =================================================
void __thiscall
CFastBufferWheel<unsigned_long>::CFastBufferWheel<unsigned_long>
          (void *this,CFastBufferWheel<unsigned_long> *param_1,ulong param_2)
{
{
  ulong unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a91058;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)this = 0;
  *(ulong *)((int)this + 0x10) = param_2;
  if (param_2 != 0) {
    CFastBuffer<struct_CGameCampaignScores::SFilterInfos*>::InitSize
              (this,(CFastBuffer<struct_SMeshOctreeCell> *)param_2,unaff_ESI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<unsigned_long>::CopyFromWheel
// =================================================
void __thiscall
CFastBufferWheel<unsigned_long>::CopyFromWheel
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
  CFastBuffer<int>::SetSizeAtLeast(this,pCVar1,unaff_retaddr);
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
// Function: CFastBufferWheel<unsigned_long>::Pull
// =================================================
int __thiscall
CFastBufferWheel<unsigned_long>::Pull(void *this,CFastBufferWheel<float> *param_1,float *param_2)
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
  iVar2 = CFastBufferWheel<class_GmVec2>::Pull(this,unaff_retaddr,(float *)param_1);
  return iVar2;
}
}

// =================================================
// Function: CFastBufferWheel<unsigned_long>::SetCountLimit
// =================================================
void __thiscall
CFastBufferWheel<unsigned_long>::SetCountLimit
          (void *this,CFastBufferWheel<float> *param_1,ulong param_2)
{
{
  int iVar1;
  float *unaff_ESI;
  CFastBufferWheel<float> *in_stack_ffffffe0;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffe4;
  CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> local_18 [4];
  undefined1 auStack_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a91088;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 != *(CFastBufferWheel<float> **)((int)this + 0x10)) {
    CFastBufferWheel<unsigned_long>
              (&stack0xffffffe0,(CFastBufferWheel<unsigned_long> *)param_1,
               DAT_00cca150 ^ (uint)&stack0xffffffdc);
    iVar1 = Pull(this,(CFastBufferWheel<float> *)&param_2,unaff_ESI);
    while (iVar1 != 0) {
      CFastBufferWheel<class_CPlugFileSndGen*>::Push
                (local_18,(CFastBufferWheel<float> *)&stack0x0000000c,(float *)in_stack_ffffffe0);
      in_stack_ffffffe0 = (CFastBufferWheel<float> *)&stack0x00000010;
      iVar1 = Pull(this,in_stack_ffffffe0,(float *)in_stack_ffffffe4);
    }
    CopyFromWheel(this,local_18,
                  (CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *)
                  in_stack_ffffffe0);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (auStack_14,in_stack_ffffffe4);
  }
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<unsigned_long>::Tail
// =================================================
GmVec3 * __thiscall
CFastBufferWheel<unsigned_long>::Tail(void *this,CFastBufferWheel<class_GmVec3> *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 0xc) + -1 + *(int *)this;
  if (*(uint *)((int)this + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 8);
  }
  return (GmVec3 *)(*(int *)((int)this + 4) + uVar1 * 4);
}
}

