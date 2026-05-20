// Class implementation: CVisionShaderKeeper

// =================================================
// Function: CVisionShaderKeeper::SetCanBeShared
// =================================================
void __thiscall
CVisionShaderKeeper::SetCanBeShared
          (CVisionShaderKeeper *this,CVisionShaderKeeper *param_1,int param_2)
{
{
  *(uint *)(this + 0x10) =
       *(uint *)(this + 0x10) ^
       ((uint)(param_1 != (CVisionShaderKeeper *)0x0) << 0xe ^ *(uint *)(this + 0x10)) & 0x4000;
  if (param_1 == (CVisionShaderKeeper *)0x0) {
    SetSaveBuffer(this,(CVisionShaderKeeper *)0x0,(CClassicBufferMemory *)param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: CVisionShaderKeeper::SetIndexToSort
// =================================================
void __thiscall
CVisionShaderKeeper::SetIndexToSort
          (CVisionShaderKeeper *this,CVisionShaderKeeper *param_1,ulong param_2)
{
{
  *(uint *)(this + 0x10) =
       *(uint *)(this + 0x10) ^ ((int)param_1 << 0xf ^ *(uint *)(this + 0x10)) & 0x1fff8000;
  return;
}
}

// =================================================
// Function: CVisionShaderKeeper::SetSaveBuffer
// =================================================
void __thiscall
CVisionShaderKeeper::SetSaveBuffer
          (CVisionShaderKeeper *this,CVisionShaderKeeper *param_1,CClassicBufferMemory *param_2)
{
{
  undefined4 unaff_retaddr;
  
  if (*(undefined4 **)(this + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 8))(1);
    *(undefined4 *)(this + 8) = unaff_retaddr;
    return;
  }
  *(CVisionShaderKeeper **)(this + 8) = param_1;
  return;
}
}

// =================================================
// Function: CVisionShaderKeeper::ShaderAddRef
// =================================================
ulong __thiscall
CVisionShaderKeeper::ShaderAddRef(CVisionShaderKeeper *this,CVisionShaderKeeper *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x10);
  uVar1 = (uVar1 + 1 ^ uVar1) & 0x3fff ^ uVar1;
  *(uint *)(this + 0x10) = uVar1;
  return uVar1 & 0x3fff;
}
}

// =================================================
// Function: CVisionShaderKeeper::ShaderRelease
// =================================================
ulong __thiscall
CVisionShaderKeeper::ShaderRelease
          (CVisionShaderKeeper *this,CVisionShaderKeeper *param_1,CPlugShader *param_2)
{
{
  uint uVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  void *this_00;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CPlugShader *in_stack_0000000c;
  CPlugShader *this_01;
  
  uVar1 = *(uint *)(this + 0x10);
  uVar1 = (uVar1 - 1 ^ uVar1) & 0x3fff ^ uVar1;
  *(uint *)(this + 0x10) = uVar1;
  if ((uVar1 & 0x3fff) == 0) {
    (*(code *)**(undefined4 **)this)(1);
    return 0;
  }
  if (param_1 == *(CVisionShaderKeeper **)(this + 0xc)) {
    this_00 = (void *)(DAT_00d75674 + 0x584);
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBP)
        ;
        if (((CPlugShader *)*(int *)pSVar3 != in_stack_0000000c) &&
           (*(CVisionShaderKeeper **)(*(int *)pSVar3 + 0x14) == this)) break;
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBP);
    this_01 = *(CPlugShader **)pSVar3;
    in_stack_0000000c = this_01;
    CPlugShader::SetDirty(this_01,(CPlugVertexStream *)0x1,1);
    uVar1 = *(uint *)(this + 0x10);
    *(uint *)(this + 0x10) = uVar1 & 0xffffc001 | 1;
    (**(code **)(*(int *)this + 8))();
    *(uint *)(this + 0x10) =
         *(uint *)(this + 0x10) ^ (*(uint *)(this + 0x10) ^ uVar1 & 0x3fff) & 0x3fff;
    CFastBuffer<struct_CGameRemoteBuffer::SUser*>::ReplaceByLastIfFound
              ((void *)(DAT_00d75674 + 0x590),
               (CFastBuffer<struct_CGameRemoteBuffer::SUser*> *)&param_2,(SUser **)this_01);
  }
  return *(uint *)(this + 0x10) & 0x3fff;
}
}

// =================================================
// Function: CVisionShaderKeeper::Undirty
// =================================================
void __thiscall CVisionShaderKeeper::Undirty(CVisionShaderKeeper *this,CDx9IndexBuffer *param_1)
{
{
  int unaff_EDI;
  
  *(CDx9IndexBuffer **)(this + 0xc) = param_1;
  (**(code **)(*(int *)param_1 + 0xac))();
  (**(code **)(*(int *)param_1 + 0xa8))();
  SetCanBeShared(this,(CVisionShaderKeeper *)(~(*(uint *)(param_1 + 0x20) >> 0x11) & 1),unaff_EDI);
  return;
}
}

