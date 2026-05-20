// Class implementation: CPlugShaderApply

// =================================================
// Function: CPlugShaderApply::AddTextureApply
// =================================================
CPlugBitmapApply * __thiscall
CPlugShaderApply::AddTextureApply
          (CPlugShaderApply *this,CPlugShaderApply *param_1,CPlugBitmap *param_2,EGxTexOp param_3,
          ulong param_4)
{
{
  EGxTexOp EVar1;
  CPlugBitmapApply *pCVar2;
  CPlugBitmapApply *this_00;
  CPlugBitmapApply *extraout_EAX;
  SFormat *unaff_ESI;
  EGxTexArg unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad6e0b;
  local_c = ExceptionList;
  pCVar2 = (CPlugBitmapApply *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
  if ((param_3 != 0xffffffff) && (EVar1 = *(EGxTexOp *)(this + 0x20), (EVar1 & 0xf) <= param_3)) {
    *(EGxTexOp *)(this + 0x20) = (param_3 + 1 ^ EVar1) & 0xf ^ EVar1;
  }
  this_00 = operator_new(0x40);
  local_4 = 0;
  if (this_00 == (CPlugBitmapApply *)0x0) {
    pCVar2 = (CPlugBitmapApply *)0x0;
  }
  else {
    CPlugBitmapApply::CPlugBitmapApply(this_00,pCVar2);
    pCVar2 = extraout_EAX;
  }
  CPlugBitmapApply::CreateBitmapApply
            (pCVar2,(CPlugBitmapApply *)this,(CPlugShader *)param_2,(CPlugBitmap *)param_3,
             (ulong)this_00,0,unaff_EDI);
  CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
            (this + 0x94,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&stack0x00000014,unaff_ESI);
  ExceptionList = (void *)0xffffffff;
  return pCVar2;
}
}

// =================================================
// Function: CPlugShaderApply::CPlugShaderApply
// =================================================
void __thiscall CPlugShaderApply::CPlugShaderApply(CPlugShaderApply *this,CPlugShaderApply *param_1)
{
{
  CPlugBitmap *extraout_EAX;
  CPlugBitmap *unaff_EBX;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  bool bVar1;
  void *in_stack_00000008;
  CPlugShaderApply *pCVar2;
  CMwNod *in_stack_fffffff0;
  void *local_c;
  CPlugBitmap *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = (CPlugBitmap *)&LAB_00ad6db1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar2 = this;
  CPlugShaderGeneric::CPlugShaderGeneric
            ((CPlugShaderGeneric *)this,
             (CPlugShaderGeneric *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x94,unaff_ESI);
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0x90) = 0x3f800000;
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) & 0xfec02001 | 0x6000001;
  bVar1 = DAT_00d6ec34 == (CPlugBitmap *)0x0;
  *(uint *)(this + 0xa0) = *(uint *)(this + 0xa0) & 0xffffff7f | 0x7f007f;
  this[0xa6] = (CPlugShaderApply)0x1;
  this[0xa5] = (CPlugShaderApply)0x1;
  this[0xa4] = (CPlugShaderApply)0x1;
  this[0xa7] = (CPlugShaderApply)0x1;
  if (bVar1) {
    local_8 = operator_new(0x78);
    if (local_8 == (CPlugBitmap *)0x0) {
      DAT_00d6ec34 = (CPlugBitmap *)0x0;
    }
    else {
      CPlugBitmap::CPlugBitmap(local_8,unaff_EBX);
      DAT_00d6ec34 = extraout_EAX;
    }
    in_stack_00000008 = (void *)CONCAT31(in_stack_00000008._1_3_,1);
    CPlugBitmap::GenerateChecker(DAT_00d6ec34,(CPlugBitmap *)0x0,(ulong)pCVar2);
  }
  CMwNod::MwAddRef((CMwNod *)DAT_00d6ec34,in_stack_fffffff0);
  ExceptionList = in_stack_00000008;
  return;
}
}

// =================================================
// Function: CPlugShaderApply::SetAlphaCmp_Pass
// =================================================
void __thiscall
CPlugShaderApply::SetAlphaCmp_Pass
          (CPlugShaderApply *this,CPlugShaderApply *param_1,EGxAlphaCmp param_2,uchar param_3)
{
{
  *(EGxAlphaCmp *)(this + 0x9c) =
       (((uint)param_1 & 7) << 10 | param_2 & 0xff) << 0xe | *(uint *)(this + 0x9c) & 0xf8c03fff;
  CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
  return;
}
}

// =================================================
// Function: CPlugShaderApply::SetBlendOpPC2
// =================================================
void __thiscall
CPlugShaderApply::SetBlendOpPC2(CPlugShaderApply *this,CPlugShaderApply *param_1,EGxBlendOp param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x9c);
  if ((CPlugShaderApply *)(uVar1 >> 10 & 7) != param_1) {
    *(uint *)(this + 0x9c) = ((int)param_1 << 10 ^ uVar1) & 0x1c00 ^ uVar1;
    (**(code **)(*(int *)this + 0xac))();
    CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
  }
  return;
}
}

// =================================================
// Function: CPlugShaderApply::SetBlending
// =================================================
void __thiscall
CPlugShaderApply::SetBlending
          (CPlugShaderApply *this,CPlugShaderPass *param_1,EGxBlendFactor param_2,
          EGxBlendFactor param_3)
{
{
  EGxBlendOp unaff_ESI;
  EGxBlendFactor unaff_retaddr;
  
  SetBlendOpPC2(this,(CPlugShaderApply *)0x0,unaff_ESI);
  SetBlending(this,*(CPlugShaderPass **)(&DAT_00d5282c + param_2 * 4),
              *(EGxBlendFactor *)(&DAT_00d52840 + param_2 * 4),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugShaderApply::SetForceIsAlphaBlend
// =================================================
void __thiscall
CPlugShaderApply::SetForceIsAlphaBlend(CPlugShaderApply *this,CPlugShaderApply *param_1,int param_2)
{
{
  *(uint *)(this + 0x9c) =
       *(uint *)(this + 0x9c) ^
       ((uint)(param_1 != (CPlugShaderApply *)0x0) << 0x1c ^ *(uint *)(this + 0x9c)) & 0x10000000;
  CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
  return;
}
}

