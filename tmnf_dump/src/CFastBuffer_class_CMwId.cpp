// Class implementation: CFastBuffer_class_CMwId

// =================================================
// Function: CFastBuffer<class_CMwId>::Add
// =================================================
void __thiscall
CFastBuffer<class_CMwId>::Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 4) = *(undefined4 *)param_2;
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1);
  return;
}
}

// =================================================
// Function: CFastBuffer<class_CMwId>::ResetAndFreeMemory
// =================================================
void __thiscall
CFastBuffer<class_CMwId>::ResetAndFreeMemory
          (void *this,CFastBuffer<struct_SInputActionDesc_const*> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,4,*(int *)((int)pvVar1 + -4),OnAccessViolation_ConcatToCrashFileName);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}
}

// =================================================
// Function: CFastBuffer<class_CMwId>::SetBuffer
// =================================================
void __thiscall
CFastBuffer<class_CMwId>::SetBuffer
          (void *this,CFastBuffer<class_GxVertex> *param_1,ulong param_2,GxVertex *param_3)
{
{
  void *pvVar1;
  undefined4 unaff_EDI;
  code *in_stack_fffffff4;
  undefined4 in_stack_fffffff8;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    in_stack_fffffff4 = OnAccessViolation_ConcatToCrashFileName;
    _eh_vector_destructor_iterator_
              (pvVar1,4,*(int *)((int)pvVar1 + -4),OnAccessViolation_ConcatToCrashFileName);
    operator_delete__((void *)((int)pvVar1 + -4));
    in_stack_fffffff8 = unaff_EDI;
  }
  *(undefined4 *)((int)this + 4) = in_stack_fffffff8;
  *(code **)this = in_stack_fffffff4;
  *(code **)((int)this + 8) = in_stack_fffffff4;
  return;
}
}

// =================================================
// Function: CFastBuffer<class_CMwId>::~CFastBuffer<class_CMwId>
// =================================================
void __thiscall
CFastBuffer<class_CMwId>::~CFastBuffer<class_CMwId>(void *this,CFastBuffer<class_CMwId> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,4,*(int *)((int)pvVar1 + -4),OnAccessViolation_ConcatToCrashFileName);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

