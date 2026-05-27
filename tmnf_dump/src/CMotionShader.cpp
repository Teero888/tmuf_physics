// Class implementation: CMotionShader

// =================================================
// Function: CMotionShader::SetMaterial
// =================================================
void __thiscall
CMotionShader::SetMaterial(CMotionShader *this,CPlugMaterialCustom *param_1,CPlugMaterial *param_2)
{
{
  CPlugShader *pCVar1;
  CMwNod *unaff_ESI;
  CPlugMaterial *unaff_retaddr;
  
  if (*(CMwNod **)(this + 0x2c) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x2c),(CMwNod *)this,unaff_ESI);
  }
  *(CPlugMaterial **)(this + 0x2c) = param_2;
  if (param_2 != (CPlugMaterial *)0x0) {
    CMwNod::MwAddDependant((CMwNod *)param_2,(CMwNod *)this,(CMwNod *)unaff_retaddr);
  }
  if (*(undefined4 **)(this + 0x38) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x38))(1);
  }
  *(undefined4 *)(this + 0x38) = 0;
  if (*(CPlugMaterial **)(this + 0x2c) != (CPlugMaterial *)0x0) {
    pCVar1 = CPlugMaterial::GetSupportedShader(*(CPlugMaterial **)(this + 0x2c),unaff_retaddr);
    SetShader(this,(CPlugBitmapShader *)pCVar1,(CPlugShader *)param_1);
  }
  return;
}
}

// =================================================
// Function: CMotionShader::SetShader
// =================================================
void __thiscall
CMotionShader::SetShader(CMotionShader *this,CPlugBitmapShader *param_1,CPlugShader *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x30),(CMwNod *)this,unaff_ESI);
  }
  *(CPlugShader **)(this + 0x30) = param_2;
  if (param_2 != (CPlugShader *)0x0) {
    CMwNod::MwAddDependant((CMwNod *)param_2,(CMwNod *)this,unaff_retaddr);
  }
  if (*(undefined4 **)(this + 0x38) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x38))(1);
  }
  *(undefined4 *)(this + 0x38) = 0;
  return;
}
}

