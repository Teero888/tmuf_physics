// Class implementation: CFastBuffer_class_CFastStringInt

// =================================================
// Function: CFastBuffer<class_CFastStringInt>::InsertNewElemAt
// =================================================
SBitmapSpecular * __thiscall
CFastBuffer<class_CFastStringInt>::InsertNewElemAt
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *param_1,ulong param_2
          )
{
{
  undefined4 *puVar1;
  int iVar2;
  SStringParam *unaff_ESI;
  ulong unaff_EDI;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  while (iVar2 = iVar2 + -1, (int)param_2 <= iVar2) {
    local_8 = *(undefined4 *)(*(int *)((int)this + 4) + 4 + iVar2 * 8);
    puVar1 = (undefined4 *)(*(int *)((int)this + 4) + iVar2 * 8);
    local_4 = *puVar1;
    CFastStringInt::SetString(puVar1 + 2,(CFastStringInt *)&local_8,unaff_ESI);
  }
  return (SBitmapSpecular *)(*(int *)((int)this + 4) + param_2 * 8);
}
}

// =================================================
// Function: CFastBuffer<class_CFastStringInt>::~CFastBuffer<class_CFastStringInt>
// =================================================
void __thiscall
CFastBuffer<class_CFastStringInt>::~CFastBuffer<class_CFastStringInt>
          (void *this,CFastBuffer<class_CFastStringInt> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,8,*(int *)((int)pvVar1 + -4),CGameCtnApp::SNationConfig::~SNationConfig);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

