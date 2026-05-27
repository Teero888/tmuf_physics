// Class implementation: SGpuConst

// =================================================
// Function: SGpuConst::~SGpuConst
// =================================================
void __thiscall SGpuConst::~SGpuConst(void *this,SGpuConst *param_1)
{
{
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  void *in_stack_0000000c;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar1;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar2;
  CFastBuffer<struct_CPlugFileGPU::SSampler> *pCVar3;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar4;
  
  pCVar3 = (CFastBuffer<struct_CPlugFileGPU::SSampler> *)&LAB_00addfe4;
  pCVar4 = (CFastBuffer<class_CPlugFileGPUV*> *)&DAT_00000004;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CFastBuffer<class_CMwId>::~CFastBuffer<class_CMwId>
            ((void *)((int)this + 0x3c),
             (CFastBuffer<class_CMwId> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x30),unaff_ESI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x24),pCVar1);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x18),pCVar2);
  in_stack_0000000c = (void *)((uint)in_stack_0000000c & 0xffffff00);
  CFastBuffer<struct_CPlugFileGPU::SSampler>::~CFastBuffer<struct_CPlugFileGPU::SSampler>
            ((void *)((int)this + 0xc),pCVar3);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this,pCVar4);
  ExceptionList = in_stack_0000000c;
  return;
}
}

