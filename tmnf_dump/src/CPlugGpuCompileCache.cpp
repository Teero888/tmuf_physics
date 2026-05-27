// Class implementation: CPlugGpuCompileCache

// =================================================
// Function: CPlugGpuCompileCache::CacheOrCompileHR
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl
CPlugGpuCompileCache::CacheOrCompileHR
          (CPlugFileGPU *param_1,CFastBuffer<struct_CPlugFileGPU::SDxDefine> *param_2,ulong param_3,
          STarget *param_4,EPlugGpuPipeline param_5,void *param_6,void *param_7,void *param_8,
          CPlugGpuCompileCache *param_9)
{
{
  ulong uVar1;
  ID3DXConstantTable **unaff_ESI;
  code *unaff_retaddr;
  
  if ((_DAT_00d706c0 & 1) == 0) {
    _DAT_00d706c0 = _DAT_00d706c0 | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d706b4,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_retaddr);
    unaff_retaddr =
         `public:_static_unsigned_long___cdecl_CPlugGpuCompileCache::
         CacheOrCompileHR(class_CPlugFileGPU*,class_CFastBuffer<struct_CPlugFileGPU::SDxDefine>_const&,unsigned_long,struct_CacheOrCompileHR::STarget_const&,enum_EPlugGpuPipeline,void*,void*,void*,class_CacheOrCompileHR*)'
         ::__l2::_dynamic_atexit_destructor_for__s_GpuDefines__;
    _atexit(`public:_static_unsigned_long___cdecl_CPlugGpuCompileCache::
            CacheOrCompileHR(class_CPlugFileGPU*,class_CFastBuffer<struct_CPlugFileGPU::SDxDefine>_const&,unsigned_long,struct_CacheOrCompileHR::STarget_const&,enum_EPlugGpuPipeline,void*,void*,void*,class_CacheOrCompileHR*)'
            ::__l2::_dynamic_atexit_destructor_for__s_GpuDefines__);
  }
  uVar1 = CompileInternal((CPlugFileGPU *)param_3,(ulong)param_4,(STarget *)param_5,
                          (EPlugGpuPipeline)param_6,param_7,param_8,unaff_ESI,
                          (CFastBuffer<struct_CPlugFileGPU::SDxDefine> *)unaff_retaddr);
  if ((-1 < (int)uVar1) && (*(int *)param_6 != 0)) {
    uVar1 = 0;
  }
  return uVar1;
}
}

