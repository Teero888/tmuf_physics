// Class implementation: CFastBuffer_struct_CHmsCollisionManager_SGroup_SAgainstGroup_CFastBuffer_struct_CHmsCollisionManager_SGroup

// =================================================
// Function: ~CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>
// =================================================
void __thiscall
CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>::
~CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>
          (void *this,CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,0x1c,*(int *)((int)pvVar1 + -4),
               CHmsCollisionManager::SGroup::SAgainstGroup::~SAgainstGroup);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

