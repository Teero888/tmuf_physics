// Class implementation: CPlugMaterial_SDeviceMat

// =================================================
// Function: CPlugMaterial::SDeviceMat::LoadShader
// =================================================
CPlugShader * __thiscall
CPlugMaterial::SDeviceMat::LoadShader(void *this,SDeviceMat *param_1,CPlugMaterialCustom *param_2)
{
{
  CPlugShader *this_00;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (*(CSystemFid **)((int)this + 0x14) == (CSystemFid *)0x0) {
    return (CPlugShader *)0x0;
  }
  this_00 = CPlugMaterialCustom::ShaderLoadFromFidParam
                      (*(CSystemFid **)((int)this + 0x14),(CPlugMaterialCustom *)param_1);
  if (this_00 != *(CPlugShader **)((int)this + 0x18)) {
    if (this_00 != (CPlugShader *)0x0) {
      CMwNod::MwAddRef((CMwNod *)this_00,unaff_EDI);
    }
    if (*(CMwNod **)((int)this + 0x18) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)((int)this + 0x18),unaff_ESI);
    }
    *(CPlugShader **)((int)this + 0x18) = this_00;
  }
  return *(CPlugShader **)((int)this + 0x18);
}
}

// =================================================
// Function: CPlugMaterial::SDeviceMat::ReleaseShaders
// =================================================
void __thiscall CPlugMaterial::SDeviceMat::ReleaseShaders(void *this,SDeviceMat *param_1)
{
{
  CMwNod *unaff_ESI;
  
  if ((*(int *)((int)this + 0x18) != 0) && (*(CMwNod **)((int)this + 0x18) != (CMwNod *)0x0)) {
    CMwNod::MwRelease(*(CMwNod **)((int)this + 0x18),unaff_ESI);
    *(undefined4 *)((int)this + 0x18) = 0;
  }
  return;
}
}

