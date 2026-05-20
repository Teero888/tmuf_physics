// Class implementation: CFastArray_struct_CSceneMobilSnow_SSnowFlakes

// =================================================
// Function: CFastArray<struct_CSceneMobilSnow::SSnowFlakes>::AllocateMore
// =================================================
void __thiscall
CFastArray<struct_CSceneMobilSnow::SSnowFlakes>::AllocateMore
          (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,ulong param_2)
{
{
  CFastArray<struct_CDx9DeviceCaps::SFormat> *pCVar1;
  void *pvVar2;
  longlong lVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *(int *)this;
  pCVar1 = param_1 + iVar7;
  lVar3 = ZEXT48(pCVar1) * 0x10;
  pvVar4 = operator_new__(-(uint)((int)((ulonglong)lVar3 >> 0x20) != 0) | (uint)lVar3);
  if (iVar7 != 0) {
    iVar6 = 0;
    do {
      iVar5 = *(int *)((int)this + 4) + iVar6;
      *(undefined4 *)(iVar6 + (int)pvVar4) = *(undefined4 *)(*(int *)((int)this + 4) + iVar6);
      *(undefined4 *)(iVar6 + 4 + (int)pvVar4) = *(undefined4 *)(iVar5 + 4);
      *(undefined4 *)(iVar6 + 8 + (int)pvVar4) = *(undefined4 *)(iVar5 + 8);
      *(undefined4 *)(iVar6 + 0xc + (int)pvVar4) = *(undefined4 *)(iVar5 + 0xc);
      iVar6 = iVar6 + 0x10;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  pvVar2 = *(void **)((int)this + 4);
  *(void **)((int)this + 4) = pvVar4;
  *(CFastArray<struct_CDx9DeviceCaps::SFormat> **)this = pCVar1;
  operator_delete__(pvVar2);
  return;
}
}

