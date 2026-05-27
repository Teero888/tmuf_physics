// Class implementation: CFastBuffer_struct_CFastBufferKey_class_CMwNodRef_class_GxFog_SKey

// =================================================
// Function: CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_GxFog>_>::SKey>::QFindPrev
// =================================================
ulong __thiscall
CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_GxFog>_>::SKey>::QFindPrev
          (void *this,CFastBuffer<class_CMwNodRef<class_CGameCalendarEvent>_> *param_1,
          CMwNodRef<class_CGameCalendarEvent> *param_2,
          _func___cdecl_int_CMwNodRef<class_CGameCalendarEvent>_ptr_CMwNodRef<class_CGameCalendarEvent>_ptr
          *param_3,int *param_4)
{
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iStack_4;
  
  uVar3 = *(int *)this - 1;
  if (*(int *)this == 0) {
    if (param_3 !=
        (_func___cdecl_int_CMwNodRef<class_CGameCalendarEvent>_ptr_CMwNodRef<class_CGameCalendarEvent>_ptr
         *)0x0) {
      *(undefined4 *)param_3 = 0;
    }
    return 0;
  }
  iVar2 = (*(code *)param_2)(param_1,*(undefined4 *)((int)this + 4));
  if (iVar2 < 1) {
    if (param_3 !=
        (_func___cdecl_int_CMwNodRef<class_CGameCalendarEvent>_ptr_CMwNodRef<class_CGameCalendarEvent>_ptr
         *)0x0) {
      *(uint *)param_3 = (uint)(iVar2 == 0);
    }
    return 0;
  }
  iStack_4 = (*(code *)param_2)(param_1,*(int *)((int)this + 4) + uVar3 * 8);
  if (iStack_4 < 0) {
    uVar1 = 0;
    uVar5 = uVar3;
    while (1 < uVar5) {
      uVar5 = uVar3 + uVar1 >> 1;
      iVar2 = (*(code *)param_2)(param_1,*(int *)((int)this + 4) + uVar5 * 8);
      uVar4 = uVar5;
      if (iVar2 < 1) {
        uVar4 = uVar1;
        uVar3 = uVar5;
        iStack_4 = iVar2;
      }
      uVar1 = uVar4;
      uVar5 = uVar3 - uVar4;
    }
    if (param_3 !=
        (_func___cdecl_int_CMwNodRef<class_CGameCalendarEvent>_ptr_CMwNodRef<class_CGameCalendarEvent>_ptr
         *)0x0) {
      *(uint *)param_3 = (uint)(iStack_4 == 0);
    }
  }
  else {
    if (param_3 !=
        (_func___cdecl_int_CMwNodRef<class_CGameCalendarEvent>_ptr_CMwNodRef<class_CGameCalendarEvent>_ptr
         *)0x0) {
      *(uint *)param_3 = (uint)(iStack_4 == 0);
    }
    if (iStack_4 != 0) {
      return *(ulong *)this;
    }
  }
  return uVar3;
}
}

