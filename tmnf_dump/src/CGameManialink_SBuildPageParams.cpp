// Class implementation: CGameManialink_SBuildPageParams

// =================================================
// Function: CGameManialink::SBuildPageParams::SBuildPageParams
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameManialink::SBuildPageParams::SBuildPageParams(void *this,SBuildPageParams *param_1)
{
{
  undefined4 uVar1;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar2;
  SStringParam *unaff_EDI;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00aa2193;
  local_c = ExceptionList;
  pCVar2 = (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_c;
  *(undefined4 *)this = 0;
  *(undefined **)((int)this + 4) = PTR_DAT_00bbf7d8;
  local_4 = (void *)0x0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x40),pCVar2);
  local_10 = DAT_00d71ca0;
  local_c = DAT_00d71c9c;
  CFastString::SetString(this,(CFastStringInt *)&local_10,unaff_EDI);
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  uVar1 = _DAT_00b2c068;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x34) = uVar1;
  *(undefined4 *)((int)this + 0x2c) = 0;
  uVar1 = _DAT_00b41140;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x38) = uVar1;
  *(undefined4 *)((int)this + 0x3c) = 1;
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CGameManialink::SBuildPageParams::~SBuildPageParams
// =================================================
void __thiscall
CGameManialink::SBuildPageParams::~SBuildPageParams(void *this,SBuildPageParams *param_1)
{
{
  undefined *puVar1;
  undefined *puVar2;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00aa2158;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0;
  CFastBuffer<struct_CGameManialink::SDicoEntry>::~CFastBuffer<struct_CGameManialink::SDicoEntry>
            ((void *)((int)this + 0x40),
             (CFastBuffer<struct_CGameManialink::SDicoEntry> *)
             (DAT_00cca150 ^ (uint)&stack0xffffffec));
  puVar1 = *(undefined **)((int)this + 4);
  if (puVar1 != PTR_DAT_00bbf7d8) {
    puVar2 = puVar1 + -1;
    if ((puVar1[-1] & 0x80) != 0) {
      puVar2 = puVar1 + -4;
    }
    operator_delete__(puVar2);
    *(undefined4 *)this = 0;
    *(undefined **)((int)this + 4) = PTR_DAT_00bbf7d8;
  }
  ExceptionList = local_8;
  return;
}
}

