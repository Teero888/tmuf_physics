// Class implementation: CPlugMaterial

// =================================================
// Function: CPlugMaterial::AddMobil_GetMatFx
// =================================================
CPlugMaterialFx * __thiscall
CPlugMaterial::AddMobil_GetMatFx(CPlugMaterial *this,CPlugMaterialFxs *param_1)
{
{
  CPlugMaterialFx *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0085997b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = (CPlugMaterialFx *)(**(code **)(**(int **)(this + 0x1c) + 0x88))();
  return pCVar1;
}
}

// =================================================
// Function: CPlugMaterial::CPlugMaterial
// =================================================
void __thiscall
CPlugMaterial::CPlugMaterial(CPlugMaterial *this,CPlugMaterial *param_1,CPlugShader *param_2)
{
{
  CPlugMaterial *this_00;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  CVisionViewport *in_stack_00000014;
  CPlugMaterial *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5c7f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CPlug::CPlug((CPlug *)this,(CPlug *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x1c) = 0;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x20,unaff_EDI);
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x30,unaff_ESI);
  CommonConstructor(this,pCVar1);
  ShaderAdd(this_00,in_stack_00000014,(CPlugShader *)0x0);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CPlugMaterial::CommonConstructor
// =================================================
void __thiscall CPlugMaterial::CommonConstructor(CPlugMaterial *this,CPlugMaterial *param_1)
{
{
  *(undefined4 *)(this + 0x18) = 0;
  this[0x18] = (CPlugMaterial)0x0;
  *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xffeeffff | 0x800e0000;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CPlugMaterial::DoesContainShader
// =================================================
int __thiscall
CPlugMaterial::DoesContainShader
          (CPlugMaterial *this,CPlugMaterial *param_1,CPlugShader *param_2,ulong *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *in_stack_00000010;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                         (this + 0x20,pCVar3,unaff_ESI);
      if (*(CPlugShader **)(pSVar2 + 0x18) == param_2) {
        if (in_stack_00000010 != (undefined4 *)0x0) {
          *in_stack_00000010 = pCVar3;
        }
        return 1;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0;
}
}

// =================================================
// Function: CPlugMaterial::ForceParam
// =================================================
void __thiscall CPlugMaterial::ForceParam(CPlugMaterial *this,CPlugMaterial *param_1,EParam param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *this_00;
  SDeviceMat *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  int in_stack_00000010;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      this_00 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                          (this + 0x20,pCVar2,unaff_ESI);
      unaff_ESI = 0x8598a7;
      SDeviceMat::ReleaseShaders(this_00,unaff_EBP);
      pCVar2 = pCVar2 + 1;
      *(undefined4 *)(this_00 + 0x14) = *(undefined4 *)(this_00 + in_stack_00000010 * 4 + 4);
    } while (pCVar2 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CPlugMaterial::GetModifyMask
// =================================================
ulong __thiscall CPlugMaterial::GetModifyMask(CPlugMaterial *this,CPlugMaterialFxFur *param_1)
{
{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = 2;
  if (((byte)this[0x1a] & 1) != 0) {
    uVar2 = 3;
  }
  if (*(int **)(this + 0x1c) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(this + 0x1c) + 0x78))();
    uVar2 = uVar2 | uVar1;
  }
  return uVar2;
}
}

// =================================================
// Function: CPlugMaterial::GetSupportedDeviceMatIndex
// =================================================
ulong __thiscall
CPlugMaterial::GetSupportedDeviceMatIndex(CPlugMaterial *this,CPlugMaterial *param_1)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  uint uVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  if (uVar1 == 0) {
    return 0xffffffff;
  }
  uVar3 = DAT_00d123b8;
  if (DAT_00d123b8 >> 0x10 != 2) {
    uVar3 = CONCAT22((short)(DAT_00d123b8 >> 0x10),(ushort)(byte)DAT_00d123b8);
  }
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar1 - 1);
  while( true ) {
    if (pCVar4 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      return 0;
    }
    pSVar2 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[](this + 0x20,pCVar4,unaff_ESI);
    if (*(uint *)pSVar2 <= uVar3) break;
    pCVar4 = pCVar4 + -1;
  }
  return (ulong)pCVar4;
}
}

// =================================================
// Function: CPlugMaterial::GetSupportedShader
// =================================================
CPlugShader * __thiscall
CPlugMaterial::GetSupportedShader(CPlugMaterial *this,CPlugMaterial *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *this_00;
  CPlugShader *pCVar3;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  SDeviceMat *pSVar4;
  CPlugMaterial *unaff_EDI;
  CPlugMaterialCustom *unaff_retaddr;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           GetSupportedDeviceMatIndex(this,unaff_EDI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_ESI);
  if (pCVar2 <= pCVar1) {
    return (CPlugShader *)0x0;
  }
  this_00 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[](this + 0x20,pCVar1,unaff_EBX);
  if (*(int *)(this + 0x28) == 0) {
    pSVar4 = (SDeviceMat *)0x0;
  }
  else {
    pSVar4 = *(SDeviceMat **)(this + 0x2c);
  }
  if (*(CPlugShader **)(this_00 + 0x18) != (CPlugShader *)0x0) {
    return *(CPlugShader **)(this_00 + 0x18);
  }
  pCVar3 = SDeviceMat::LoadShader(this_00,pSVar4,unaff_retaddr);
  return pCVar3;
}
}

