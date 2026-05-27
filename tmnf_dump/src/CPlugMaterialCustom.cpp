// Class implementation: CPlugMaterialCustom

// =================================================
// Function: CPlugMaterialCustom::ShaderLoadFromFidParam
// =================================================
CPlugShader * __cdecl
CPlugMaterialCustom::ShaderLoadFromFidParam(CSystemFid *param_1,CPlugMaterialCustom *param_2)
{
{
  int iVar1;
  CSystemFidParameters *unaff_ESI;
  void *in_stack_00000010;
  undefined4 uStack00000014;
  CSystemFid *in_stack_0000001c;
  ulong in_stack_ffffffc0;
  ulong in_stack_ffffffc4;
  CSystemFidParameters *in_stack_ffffffd0;
  CSystemFidParameters local_2c [4];
  CPlugShader *local_28;
  CSystemFidParameters local_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad7618;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemFidParameters::CSystemFidParameters
            ((CSystemFidParameters *)&stack0xffffffc4,
             (CSystemFidParameters *)(DAT_00cca150 ^ (uint)&stack0xffffffbc),unaff_ESI);
  if (in_stack_00000010 != (void *)0x0) {
    iVar1 = *(int *)(*(int *)(*(int *)((int)in_stack_00000010 + 0x20) + 0x28) + 8);
    if (iVar1 != 0) {
      CSystemFidParameters::MergeForChildFid
                ((CSystemFidParameters *)&stack0xffffffcc,(CSystemFidParameters *)(iVar1 + 0x34),
                 (CSystemFidParameters *)0x0,(CSystemFid *)0x9002000,in_stack_ffffffc0);
    }
    CSystemFidParameters::MergeForChildFid
              ((CSystemFidParameters *)&stack0xffffffd0,
               (CSystemFidParameters *)((int)in_stack_00000010 + 0x54),(CSystemFidParameters *)0x0,
               (CSystemFid *)0x9002000,in_stack_ffffffc4);
    CSystemFidParameters::Push(local_2c,(CFastBufferWheel<float> *)local_2c,(float *)0x1);
  }
  CSystemArchiveNod::LoadFromFid((CMwNod **)&local_28,in_stack_0000001c,7);
  if (in_stack_00000010 != (void *)0x0) {
    CSystemFidParameters::Pop(local_24,(SCharStyle *)local_24);
  }
  uStack00000014 = 0xffffffff;
  CSystemFidParameters::~CSystemFidParameters(local_24,in_stack_ffffffd0);
  ExceptionList = in_stack_00000010;
  return local_28;
}
}

