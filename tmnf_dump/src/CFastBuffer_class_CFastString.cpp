// Class implementation: CFastBuffer_class_CFastString

// =================================================
// Function: CFastBuffer<class_CFastString>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<class_CFastString>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 8);
}
}

// =================================================
// Function: CFastBuffer<class_CFastString>::InitSize
// =================================================
void __thiscall
CFastBuffer<class_CFastString>::InitSize
          (void *this,CFastBuffer<struct_SMeshOctreeCell> *param_1,ulong param_2)
{
{
  undefined4 *puVar1;
  uint uVar2;
  code *pcVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a81acb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(CFastBuffer<struct_SMeshOctreeCell> **)((int)this + 8) = param_1;
  uVar2 = -(uint)((int)(ZEXT48(param_1) * 8 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 8);
  puVar1 = operator_new__(-(uint)(0xfffffffb < uVar2) | uVar2 + 4);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    pcVar3 = CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity;
    *puVar1 = param_1;
    _eh_vector_constructor_iterator_
              (puVar1 + 1,8,(int)param_1,CGameMasterServer::SLadderResult::SLadderResult,
               CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity);
    *(undefined4 **)((int)this + 4) = puVar1 + 1;
    *(undefined4 *)this = 0;
    ExceptionList = pcVar3;
    return;
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CFastBuffer<class_CFastString>::RemoveAt
// =================================================
void __thiscall
CFastBuffer<class_CFastString>::RemoveAt
          (void *this,CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *param_1,
          ulong param_2,ulong param_3)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  SStringParam *unaff_EDI;
  int iVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = (*(int *)this - (int)param_1) - param_2;
  if (iVar2 != 0) {
    iVar4 = (int)param_1 * 8;
    iVar3 = (int)(param_1 + param_2) * 8;
    do {
      iVar1 = *(int *)((int)this + 4);
      local_8 = *(undefined4 *)(iVar3 + 4 + iVar1);
      local_4 = *(undefined4 *)(iVar3 + iVar1);
      CFastString::SetString((CFastString *)(iVar4 + iVar1),(CFastStringInt *)&local_8,unaff_EDI);
      iVar3 = iVar3 + 8;
      iVar4 = iVar4 + 8;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(ulong *)this = *(int *)this - param_3;
    return;
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

// =================================================
// Function: CFastBuffer<class_CFastString>::~CFastBuffer<class_CFastString>
// =================================================
void __thiscall
CFastBuffer<class_CFastString>::~CFastBuffer<class_CFastString>
          (void *this,CFastBuffer<class_CFastString> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,8,*(int *)((int)pvVar1 + -4),
               CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

