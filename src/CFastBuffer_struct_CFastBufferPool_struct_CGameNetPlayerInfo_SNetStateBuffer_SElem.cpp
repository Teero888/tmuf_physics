// Class implementation: CFastBuffer_struct_CFastBufferPool_struct_CGameNetPlayerInfo_SNetStateBuffer_SElem

// =================================================
// Function: AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem>::
AllocSetCount(void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

// =================================================
// Function: SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem>::
SetSizeAtLeast(void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  void *unaff_ESI;
  SNormalDec3N *pSVar5;
  GmVec3 *this_00;
  GmVec3 *in_stack_ffffffc4;
  GmVec3 *local_28;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00abd8bb;
  local_c = ExceptionList;
  local_28 = (GmVec3 *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  uVar3 = *(uint *)((int)this + 8);
  iVar4 = 0;
  if (0 < (int)((int)param_1 - uVar3)) {
    if ((int)((int)param_1 - uVar3) <= (int)(uVar3 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar3 >> 1) + uVar3);
    }
    uVar3 = -(uint)((int)(ZEXT48(param_1) * 0x30 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0x30);
    puVar2 = operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_4 = 0;
    if (puVar2 != (undefined4 *)0x0) {
      local_28 = (GmVec3 *)(puVar2 + 1);
      *puVar2 = param_1;
      in_stack_ffffffc4 = local_28;
      _eh_vector_constructor_iterator_
                (local_28,0x30,(int)param_1,
                 CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem::SElem,
                 CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem::~SElem);
    }
    this_00 = local_28;
    if (*(int *)this != 0) {
      do {
        pSVar5 = (SNormalDec3N *)(*(int *)((int)this + 4) + iVar4);
        CGameNetPlayerInfo::SNetStateBuffer::operator=(this_00,pSVar5,in_stack_ffffffc4);
        *(undefined4 *)(this_00 + 0x2c) = *(undefined4 *)(pSVar5 + 0x2c);
        unaff_ESI = (void *)((int)unaff_ESI + 1);
        iVar4 = iVar4 + 0x30;
        param_1 = local_c;
        this_00 = this_00 + 0x30;
      } while (unaff_ESI < *(void **)this);
    }
    pvVar1 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    if (pvVar1 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar1,0x30,*(int *)((int)pvVar1 + -4),
                 CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem::~SElem);
      operator_delete__((void *)((int)pvVar1 + -4));
    }
    *(GmVec3 **)((int)this + 4) = local_28;
  }
  ExceptionList = unaff_ESI;
  return;
}
}

