// Class implementation: SParamEffectMaster

// =================================================
// Function: SParamEffectMaster::SParamEffectMaster
// =================================================
void __thiscall SParamEffectMaster::SParamEffectMaster(void *this,SParamEffectMaster *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *pCVar1;
  undefined4 extraout_EAX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CPlugTree *pCStack0000000c;
  undefined1 uStack00000010;
  void *in_stack_00000014;
  undefined1 uStack00000018;
  GmFrustumIso4 *pGVar2;
  GmFrustumIso4 *in_stack_fffffff0;
  CPlugTree *pCVar3;
  
  pCVar3 = ExceptionList;
  pCVar1 = (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &stack0xfffffff4;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  pGVar2 = this;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0xc),pCVar1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x18),unaff_EDI);
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x34),unaff_ESI);
  *(undefined4 *)((int)this + 0x50) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x54),unaff_EBP);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x60),unaff_EBX);
  uStack00000010 = 6;
  *(undefined4 *)((int)this + 8) = 7;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset((void *)((int)this + 0xc),pGVar2);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            ((void *)((int)this + 0x18),in_stack_fffffff0);
  *(undefined4 *)((int)this + 0x24) = 2;
  *(undefined4 *)((int)this + 0x40) = 1;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x6c) = 1;
  pCStack0000000c = operator_new(0xac);
  uStack00000018 = 7;
  if (pCStack0000000c == (CPlugTree *)0x0) {
    *(undefined4 *)((int)this + 0x50) = 0;
  }
  else {
    CPlugTree::CPlugTree(pCStack0000000c,pCVar3);
    *(undefined4 *)((int)this + 0x50) = extraout_EAX;
  }
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: SParamEffectMaster::~SParamEffectMaster
// =================================================
void __thiscall SParamEffectMaster::~SParamEffectMaster(void *this,SParamEffectMaster *param_1)
{
{
  undefined1 *puVar1;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar2;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  CMwNod *unaff_retaddr;
  void *in_stack_0000000c;
  undefined1 uStack00000010;
  undefined4 uStack00000014;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar3;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar4;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar5;
  CMwNod *pCVar6;
  
  pCVar5 = (CFastBuffer<class_CPlugFileGPUV*> *)&LAB_00ac817a;
  pCVar2 = (CFastBuffer<class_CPlugFileGPUV*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  pCVar6 = (CMwNod *)&DAT_00000006;
  puVar1 = &stack0xfffffff4;
  pCVar3 = this;
  pCVar4 = ExceptionList;
  if (*(int **)this != (int *)0x0) {
    ExceptionList = &stack0xfffffff4;
    (**(code **)(**(int **)this + 0x80))();
    puVar1 = ExceptionList;
  }
  ExceptionList = puVar1;
  if (*(int **)((int)this + 0x50) != (int *)0x0) {
    (**(code **)(**(int **)((int)this + 0x50) + 4))(1);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x60),pCVar2);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x54),unaff_ESI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x34),pCVar3);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x18),pCVar4);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0xc),pCVar5);
  uStack00000010 = 0;
  if (*(CMwNod **)((int)this + 4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)((int)this + 4),pCVar6);
  }
  uStack00000014 = 0xffffffff;
  if (*(CMwNod **)this != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)this,unaff_retaddr);
  }
  ExceptionList = in_stack_0000000c;
  return;
}
}

