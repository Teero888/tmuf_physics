// Class implementation: CFastArray_struct_CPlugVertexStream_SDataDecl

// =================================================
// Function: CFastArray<struct_CPlugVertexStream::SDataDecl>::AllocateMore
// =================================================
void __thiscall
CFastArray<struct_CPlugVertexStream::SDataDecl>::AllocateMore
          (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,ulong param_2)
{
{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  longlong lVar4;
  void *pvVar5;
  uint uVar6;
  
  uVar1 = *(uint *)this;
  lVar4 = ZEXT48(param_1 + uVar1) * 8;
  pvVar5 = operator_new__(-(uint)((int)((ulonglong)lVar4 >> 0x20) != 0) | (uint)lVar4);
  uVar6 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = *(int *)((int)this + 4);
      *(undefined4 *)((int)pvVar5 + uVar6 * 8) = *(undefined4 *)(iVar2 + uVar6 * 8);
      *(undefined4 *)((int)pvVar5 + uVar6 * 8 + 4) = *(undefined4 *)(iVar2 + 4 + uVar6 * 8);
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar1);
  }
  pvVar3 = *(void **)((int)this + 4);
  *(void **)((int)this + 4) = pvVar5;
  *(CFastArray<struct_CDx9DeviceCaps::SFormat> **)this = param_1 + uVar1;
  operator_delete__(pvVar3);
  return;
}
}

// =================================================
// Function: CFastArray<struct_CPlugVertexStream::SDataDecl>::InsertNewElemAt
// =================================================
SBitmapSpecular * __thiscall
CFastArray<struct_CPlugVertexStream::SDataDecl>::InsertNewElemAt
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *param_1,ulong param_2
          )
{
{
  int iVar1;
  void *pvVar2;
  CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *pCVar3;
  CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *pCVar4;
  
  pCVar4 = (CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)(*(int *)this + 1);
  pvVar2 = operator_new__(-(uint)((int)(ZEXT48(pCVar4) * 8 >> 0x20) != 0) |
                          (uint)(ZEXT48(pCVar4) * 8));
  pCVar3 = (CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)0x0;
  if (param_1 != (CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)0x0) {
    do {
      iVar1 = *(int *)((int)this + 4);
      *(undefined4 *)((int)pvVar2 + (int)pCVar3 * 8) = *(undefined4 *)(iVar1 + (int)pCVar3 * 8);
      *(undefined4 *)((int)pvVar2 + (int)pCVar3 * 8 + 4) =
           *(undefined4 *)(iVar1 + 4 + (int)pCVar3 * 8);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < param_1);
  }
  while (pCVar3 = pCVar3 + 1, pCVar3 < pCVar4) {
    iVar1 = *(int *)((int)this + 4);
    *(undefined4 *)((int)pvVar2 + (int)pCVar3 * 8) = *(undefined4 *)(iVar1 + -8 + (int)pCVar3 * 8);
    *(undefined4 *)((int)pvVar2 + (int)pCVar3 * 8 + 4) =
         *(undefined4 *)(iVar1 + -4 + (int)pCVar3 * 8);
  }
  operator_delete__(*(void **)((int)this + 4));
  *(void **)((int)this + 4) = pvVar2;
  *(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> **)this = pCVar4;
  return (SBitmapSpecular *)((int)pvVar2 + (int)param_1 * 8);
}
}

// =================================================
// Function: CFastArray<struct_CPlugVertexStream::SDataDecl>::QSort
// =================================================
void __thiscall
CFastArray<struct_CPlugVertexStream::SDataDecl>::QSort
          (void *this,CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *param_1,
          _func___cdecl_int_SKey_ptr_SKey_ptr *param_2)
{
{
  func_0x009c1270(*(undefined4 *)((int)this + 4),*(undefined4 *)this,8,param_1);
  return;
}
}

