// Class implementation: CSceneFxCompo

// =================================================
// Function: CSceneFxCompo::ShaderAdd
// =================================================
int __thiscall
CSceneFxCompo::ShaderAdd(CSceneFxCompo *this,CVisionViewport *param_1,CPlugShader *param_2)
{
{
  CPlugShaderApply *pCVar1;
  CPlugShaderApply *this_00;
  CPlugShaderGeneric *extraout_EAX;
  ulong unaff_ESI;
  CPlugShaderGeneric *this_01;
  GxColor *unaff_EDI;
  CGameTournament *pCVar2;
  
  pCVar1 = (CPlugShaderApply *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  this_00 = operator_new(0xa8);
  if (this_00 == (CPlugShaderApply *)0x0) {
    this_01 = (CPlugShaderGeneric *)0x0;
  }
  else {
    CPlugShaderApply::CPlugShaderApply(this_00,pCVar1);
    this_01 = extraout_EAX;
  }
  CPlugShaderGeneric::SetVertexColor(this_01,(CPlugShaderGeneric *)0x1,0,unaff_EDI);
  CPlugShader::SetReceiverShadowGroupMask((CPlugShader *)this_01,(CPlugShader *)0x0,unaff_ESI);
  CHmsItem::SetIsForcePointDynamicCollisionResponse
            ((CHmsItem *)this_01,(CHmsItem *)0x0,(int)this_00);
  CFastBufferRef<class_CPlugShaderApply>::AddPtr
            (this + 0x38,(CFastBufferRef<class_CGameTournament> *)this_01,pCVar2);
  ExceptionList = param_2;
  return (int)this_01;
}
}

