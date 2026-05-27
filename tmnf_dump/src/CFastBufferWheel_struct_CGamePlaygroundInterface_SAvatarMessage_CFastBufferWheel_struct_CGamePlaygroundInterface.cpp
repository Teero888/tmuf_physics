// Class implementation: CFastBufferWheel_struct_CGamePlaygroundInterface_SAvatarMessage_CFastBufferWheel_struct_CGamePlaygroundInterface

// =================================================
// Function: CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>
// =================================================
void __thiscall
CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::
CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>
          (void *this,CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *param_1,
          ulong param_2)
{
{
  ulong unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00aa2088;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)this = 0;
  *(ulong *)((int)this + 0x10) = param_2;
  if (param_2 != 0) {
    CFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage>::InitSize
              (this,(CFastBuffer<struct_SMeshOctreeCell> *)param_2,unaff_ESI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: ~CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>
// =================================================
void __thiscall
CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::
~CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>
          (void *this,CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,0x18,*(int *)((int)pvVar1 + -4),
               CGamePlaygroundInterface::SAvatarMessage::~SAvatarMessage);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

