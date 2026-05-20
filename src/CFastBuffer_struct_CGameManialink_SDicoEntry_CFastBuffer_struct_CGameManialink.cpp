// Class implementation: CFastBuffer_struct_CGameManialink_SDicoEntry_CFastBuffer_struct_CGameManialink

// =================================================
// Function: CFastBuffer<struct_CGameManialink::SDicoEntry>::~CFastBuffer<struct_CGameManialink::SDicoEntry>
// =================================================
void __thiscall
CFastBuffer<struct_CGameManialink::SDicoEntry>::~CFastBuffer<struct_CGameManialink::SDicoEntry>
          (void *this,CFastBuffer<struct_CGameManialink::SDicoEntry> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,8,*(int *)((int)pvVar1 + -4),CGameManialink::SDicoEntry::~SDicoEntry);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

