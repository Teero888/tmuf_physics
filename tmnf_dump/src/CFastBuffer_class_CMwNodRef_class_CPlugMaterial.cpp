// Class implementation: CFastBuffer_class_CMwNodRef_class_CPlugMaterial

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 4);
}
}

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::ArchiveCount
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::ArchiveCount
          (void *this,CFastArray<class_CPlugFileSnd*> *param_1,CClassicArchive *param_2)
{
{
  void *pvVar1;
  CFastBuffer<struct_SMeshOctreeCell> *pCVar2;
  ulong unaff_ESI;
  int unaff_EDI;
  
  CClassicArchive::DoNatural((CClassicArchive *)param_1,this,(ulong *)0x1,0,unaff_EDI);
  if (*(uint *)this != 0) {
    if ((0x10000000 < *(uint *)this) && (DAT_00d72e8c != (code *)0x0)) {
      (*DAT_00d72e8c)();
    }
    if (*(int *)(param_1 + 8) == 0) {
      pvVar1 = *(void **)((int)this + 4);
      pCVar2 = *(CFastBuffer<struct_SMeshOctreeCell> **)this;
      if (pvVar1 != (void *)0x0) {
        _eh_vector_destructor_iterator_
                  (pvVar1,4,*(int *)((int)pvVar1 + -4),
                   CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
        operator_delete__((void *)((int)pvVar1 + -4));
      }
      *(undefined4 *)((int)this + 4) = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)this = 0;
      InitSize(this,pCVar2,unaff_ESI);
      *(CFastBuffer<struct_SMeshOctreeCell> **)this = pCVar2;
    }
  }
  return;
}
}

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::ResetAndFreeMemory
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::ResetAndFreeMemory
          (void *this,CFastBuffer<struct_SInputActionDesc_const*> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,4,*(int *)((int)pvVar1 + -4),
               CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}
}

