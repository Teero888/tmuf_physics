// Class implementation: CFastBuffer_struct_CSceneVehicle_SVisualWheel

// =================================================
// Function: CFastBuffer<struct_CSceneVehicle::SVisualWheel>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicle::SVisualWheel>::AllocSetCount
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
// Function: CFastBuffer<struct_CSceneVehicle::SVisualWheel>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicle::SVisualWheel>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  uint uVar1;
  GmVec3 *pGVar2;
  uint uVar3;
  void *unaff_ESI;
  int iVar4;
  GmVec3 *in_stack_ffffffcc;
  void *local_c;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)&LAB_00accc7b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = *(uint *)((int)this + 8);
  uVar3 = 0;
  if (0 < (int)((int)param_1 - uVar1)) {
    if ((int)((int)param_1 - uVar1) <= (int)(uVar1 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar1 >> 1) + uVar1);
    }
    pGVar2 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 0x1b8 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 0x1b8));
    local_4 = 0;
    if (pGVar2 == (GmVec3 *)0x0) {
      pGVar2 = (GmVec3 *)0x0;
    }
    else {
      in_stack_ffffffcc = pGVar2;
      _vector_constructor_iterator_
                (pGVar2,0x1b8,(int)param_1,CSceneVehicle::SVisualWheel::SVisualWheel);
    }
    if (*(int *)this != 0) {
      iVar4 = 0;
      do {
        CSceneVehicle::SVisualWheel::operator=
                  (pGVar2 + iVar4,(SNormalDec3N *)(*(int *)((int)this + 4) + iVar4),
                   in_stack_ffffffcc);
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x1b8;
        param_1 = local_8;
      } while (uVar3 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(GmVec3 **)((int)this + 4) = pGVar2;
  }
  ExceptionList = unaff_ESI;
  return;
}
}

