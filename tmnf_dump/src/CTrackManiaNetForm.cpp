// Class implementation: CTrackManiaNetForm

// =================================================
// Function: CTrackManiaNetForm::CTrackManiaNetForm
// =================================================
void __thiscall
CTrackManiaNetForm::CTrackManiaNetForm(CTrackManiaNetForm *this,CTrackManiaNetForm *param_1)
{
{
  CFastArray<class_CManoeuvre*> *unaff_EBX;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CClassicBufferMemory *unaff_EDI;
  void *in_stack_00000008;
  undefined1 uStack0000000c;
  CTrackManiaNetForm *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a86993;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CGameNetForm::CGameNetForm
            ((CGameNetForm *)this,(CGameNetForm *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  CClassicBufferMemory::CClassicBufferMemory((CClassicBufferMemory *)(this + 0x24),unaff_EDI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x74,unaff_ESI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x84,unaff_EBX);
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined **)(this + 0x90) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined **)(this + 0x9c) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined **)(this + 0xb0) = PTR_DAT_00bbf7d8;
  uStack0000000c = 6;
  CClassicBufferMemory::Empty((CClassicBufferMemory *)(this + 0x24),(CClassicBufferMemory *)pCVar1);
  this[0x20] = (CTrackManiaNetForm)0xff;
  ExceptionList = in_stack_00000008;
  return;
}
}

// =================================================
// Function: CTrackManiaNetForm::~CTrackManiaNetForm
// =================================================
void __thiscall
CTrackManiaNetForm::~CTrackManiaNetForm(CTrackManiaNetForm *this,CTrackManiaNetForm *param_1)
{
{
  undefined *puVar1;
  CFastArray<class_CFuncShader*> *pCVar2;
  undefined *puVar3;
  CClassicBufferMemory *unaff_ESI;
  CFastArray<class_CFuncShader*> *unaff_EDI;
  undefined4 uStack00000008;
  CTrackManiaNetForm *pCVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a86918;
  local_c = ExceptionList;
  pCVar2 = (CFastArray<class_CFuncShader*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  puVar1 = *(undefined **)(this + 0xb0);
  local_4 = 0;
  pCVar4 = this;
  if (puVar1 != PTR_DAT_00bbf7d8) {
    puVar3 = puVar1 + -1;
    if ((puVar1[-1] & 0x80) != 0) {
      puVar3 = puVar1 + -4;
    }
    operator_delete__(puVar3);
    *(undefined4 *)(this + 0xac) = 0;
    *(undefined **)(this + 0xb0) = PTR_DAT_00bbf7d8;
  }
  puVar1 = *(undefined **)(this + 0x9c);
  if (puVar1 != PTR_DAT_00bbf7d8) {
    puVar3 = puVar1 + -1;
    if ((puVar1[-1] & 0x80) != 0) {
      puVar3 = puVar1 + -4;
    }
    operator_delete__(puVar3);
    *(undefined4 *)(this + 0x98) = 0;
    *(undefined **)(this + 0x9c) = PTR_DAT_00bbf7d8;
  }
  puVar1 = *(undefined **)(this + 0x90);
  if (puVar1 != PTR_DAT_00bbf7d8) {
    puVar3 = puVar1 + -1;
    if ((puVar1[-1] & 0x80) != 0) {
      puVar3 = puVar1 + -4;
    }
    operator_delete__(puVar3);
    *(undefined4 *)(this + 0x8c) = 0;
    *(undefined **)(this + 0x90) = PTR_DAT_00bbf7d8;
  }
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(this + 0x84,pCVar2);
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(this + 0x74,unaff_EDI);
  CClassicBufferMemory::~CClassicBufferMemory((CClassicBufferMemory *)(this + 0x24),unaff_ESI);
  uStack00000008 = 0xffffffff;
  CGameNetForm::~CGameNetForm((CGameNetForm *)this,(CGameNetForm *)pCVar4);
  ExceptionList = param_1;
  return;
}
}

