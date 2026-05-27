// Class implementation: CFastBuffer_struct_CGamePlaygroundInterface_SAvatarMessage

// =================================================
// Function: CFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage>::InitSize
// =================================================
void __thiscall
CFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage>::InitSize
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
  puStack_8 = &LAB_00aa1ffb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(CFastBuffer<struct_SMeshOctreeCell> **)((int)this + 8) = param_1;
  uVar2 = -(uint)((int)(ZEXT48(param_1) * 0x18 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0x18);
  puVar1 = operator_new__(-(uint)(0xfffffffb < uVar2) | uVar2 + 4);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    pcVar3 = CGamePlaygroundInterface::SAvatarMessage::~SAvatarMessage;
    *puVar1 = param_1;
    _eh_vector_constructor_iterator_
              (puVar1 + 1,0x18,(int)param_1,CGamePlaygroundInterface::SAvatarMessage::SAvatarMessage
               ,CGamePlaygroundInterface::SAvatarMessage::~SAvatarMessage);
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
// Function: CFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  void *pvVar2;
  uint *puVar3;
  uint uVar4;
  GmVec3 *unaff_EBX;
  uint uVar5;
  int iVar6;
  GmVec3 *in_stack_ffffffcc;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00aa202b;
  local_c = ExceptionList;
  pvVar2 = (void *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  uVar4 = *(uint *)((int)this + 8);
  uVar5 = 0;
  if (0 < (int)((int)param_1 - uVar4)) {
    if ((int)((int)param_1 - uVar4) <= (int)(uVar4 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar4 >> 1) + uVar4);
    }
    uVar4 = -(uint)((int)(ZEXT48(param_1) * 0x18 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0x18);
    puVar3 = operator_new__(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
    local_4 = 0;
    if (puVar3 != (uint *)0x0) {
      unaff_EBX = (GmVec3 *)(puVar3 + 1);
      *puVar3 = (uint)param_1;
      in_stack_ffffffcc = unaff_EBX;
      _eh_vector_constructor_iterator_
                (unaff_EBX,0x18,(int)param_1,
                 CGamePlaygroundInterface::SAvatarMessage::SAvatarMessage,
                 CGamePlaygroundInterface::SAvatarMessage::~SAvatarMessage);
    }
    if (*(int *)this != 0) {
      iVar6 = 0;
      do {
        CGamePlaygroundInterface::SAvatarMessage::operator=
                  (unaff_EBX + iVar6,(SNormalDec3N *)(*(int *)((int)this + 4) + iVar6),
                   in_stack_ffffffcc);
        uVar5 = uVar5 + 1;
        iVar6 = iVar6 + 0x18;
      } while (uVar5 < *(uint *)this);
    }
    pvVar1 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    if (pvVar1 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar1,0x18,*(int *)((int)pvVar1 + -4),
                 CGamePlaygroundInterface::SAvatarMessage::~SAvatarMessage);
      operator_delete__((void *)((int)pvVar1 + -4));
    }
    *(GmVec3 **)((int)this + 4) = unaff_EBX;
  }
  ExceptionList = pvVar2;
  return;
}
}

