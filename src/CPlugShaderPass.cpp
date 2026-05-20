// Class implementation: CPlugShaderPass

// =================================================
// Function: CPlugShaderPass::AttachShader
// =================================================
void __thiscall
CPlugShaderPass::AttachShader
          (CPlugShaderPass *this,CPlugShaderPass *param_1,CPlugShader *param_2,ulong param_3)
{
{
  *(CPlugShaderPass **)(this + 0x34) = param_1;
  *(uint *)(this + 0x38) =
       *(uint *)(this + 0x38) ^ ((int)param_2 << 10 ^ *(uint *)(this + 0x38)) & 0x3fc00;
  return;
}
}

// =================================================
// Function: CPlugShaderPass::CPlugShaderPass
// =================================================
void __thiscall CPlugShaderPass::CPlugShaderPass(CPlugShaderPass *this,CPlugShaderPass *param_1)
{
{
  CPlugShaderPass *pCVar1;
  CPlugShaderPass *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00adc704;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlug::CPlug((CPlug *)this,(CPlug *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  _eh_vector_constructor_iterator_
            (this + 0x14,8,2,CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>,
             CFastArray<struct_CPlugFileGPU::SSampler>::~CFastArray<struct_CPlugFileGPU::SSampler>);
  pCVar2 = this + 0x24;
  _eh_vector_constructor_iterator_
            (pCVar2,8,2,CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>,
             CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>);
  pCVar1 = this + 0x3c;
  _eh_vector_constructor_iterator_
            (pCVar1,4,2,CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>,
             CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0x4c,(CFastArray<class_CManoeuvre*> *)pCVar1);
  *(undefined4 *)(this + 0x38) = 1;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  ExceptionList = pCVar2;
  return;
}
}

// =================================================
// Function: CPlugShaderPass::LoadFxReplaceFromGpu
// =================================================
void __thiscall
CPlugShaderPass::LoadFxReplaceFromGpu
          (CPlugShaderPass *this,CPlugShaderPass *param_1,EPlugGpuPipeline param_2)
{
{
  if (*(int *)(*(int *)(this + (int)param_1 * 4 + 0x3c) + 0x2c) != 0) {
    CFastArray<struct_SPlugGpuLoadFx>::CopyFromFastArray
              (this + (int)param_1 * 8 + 0x14,
               (CFastArray<class_GmVec4> *)(*(int *)(this + (int)param_1 * 4 + 0x3c) + 0x54),
               (CFastArray<class_GmVec4> *)param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugShaderPass::SetBlending
// =================================================
void __thiscall
CPlugShaderPass::SetBlending
          (CPlugShaderPass *this,CPlugShaderPass *param_1,EGxBlendFactor param_2,
          EGxBlendFactor param_3)
{
{
  *(EGxBlendFactor *)(this + 0x38) =
       (param_2 & 0xf) << 4 | *(uint *)(this + 0x38) & 0xffffff00 | (uint)param_1 & 0xf;
  if (*(CPlugShader **)(this + 0x34) != (CPlugShader *)0x0) {
    CPlugShader::SetDirty(*(CPlugShader **)(this + 0x34),(CPlugVertexStream *)0x1,1);
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugShaderPass::SetFileGpu
// =================================================
void __thiscall
CPlugShaderPass::SetFileGpu
          (CPlugShaderPass *this,CPlugShaderPass *param_1,EPlugGpuPipeline param_2,
          CPlugFileGPU *param_3)
{
{
  int iVar1;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this_00;
  CFastArray<class_GmVec4> *unaff_EBX;
  ulong unaff_ESI;
  CMwNod *unaff_EDI;
  CFastArray<class_GmVec4> *unaff_retaddr;
  
  if (*(EPlugGpuPipeline *)(this + (int)param_1 * 4 + 0x3c) != param_2) {
    if (param_2 != 0) {
      if (*(int *)(param_2 + 0x2c) == 0) {
        iVar1 = (**(code **)(*(int *)param_2 + 0xa4))(1,0);
        if (iVar1 == 0) {
          *(uint *)(this + 0x38) = *(uint *)(this + 0x38) | 0x40000;
          return;
        }
      }
      CMwNod::MwAddReceiver((CMwNod *)param_2,(CMwNod *)this,unaff_EDI);
    }
    this_00 = (void *)0x0;
    if (*(CMwNod **)(this + (int)param_1 * 4 + 0x3c) != (CMwNod *)0x0) {
      CMwNod::MwSubReceiver(*(CMwNod **)(this + (int)param_1 * 4 + 0x3c),(CMwNod *)this,unaff_EDI);
      this_00 = extraout_ECX;
    }
    if (param_2 != *(EPlugGpuPipeline *)(this + (int)param_1 * 4 + 0x3c)) {
      if (param_2 != 0) {
        CMwNod::MwAddRef((CMwNod *)param_2,unaff_EDI);
      }
      this_00 = (void *)0x0;
      if (*(CMwNod **)(this + (int)param_1 * 4 + 0x3c) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + (int)param_1 * 4 + 0x3c),unaff_EDI);
        this_00 = extraout_ECX_00;
      }
      *(EPlugGpuPipeline *)(this + (int)param_1 * 4 + 0x3c) = param_2;
    }
    if (*(int *)(this + (int)param_1 * 4 + 0x3c) == 0) {
      CFastArray<struct_SPlugGpuLoadFx>::SetCount
                (this + (int)param_1 * 8 + 0x14,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,
                 (ulong)unaff_EDI);
      CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
                (this + (int)param_1 * 8 + 0x24,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,
                 unaff_ESI);
    }
    else {
      iVar1 = CFastArray<struct_SPlugGpuLoadFx>::AreEqual
                        (this_00,(CDx9StateBlock *)(this + (int)param_1 * 8 + 0x14),
                         (CDx9StateBlock *)(*(int *)(this + (int)param_1 * 4 + 0x3c) + 0x54));
      LoadFxReplaceFromGpu(this,param_1,(EPlugGpuPipeline)unaff_EBX);
      if (iVar1 == 0) {
        unaff_EBX = (CFastArray<class_GmVec4> *)(*(int *)(this + (int)param_1 * 4 + 0x3c) + 0x5c);
        CFastArray<class_GmVec4>::CopyFromFastArray
                  (this + (int)param_1 * 8 + 0x24,unaff_EBX,unaff_retaddr);
      }
    }
    if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
      CMwNod::MwSendMessage(*(CMwNod **)(this + 0x34),(CMwNod *)0x9002000,0,(ulong *)unaff_EBX);
      CPlugShader::SetDirty(*(CPlugShader **)(this + 0x34),(CPlugVertexStream *)0x1,1);
    }
  }
  return;
}
}

// =================================================
// Function: CPlugShaderPass::SetPixelShader
// =================================================
void __thiscall
CPlugShaderPass::SetPixelShader
          (CPlugShaderPass *this,CPlugShaderPass *param_1,CPlugFileGPUP *param_2)
{
{
  CPlugFileGPU *unaff_retaddr;
  
  SetFileGpu(this,(CPlugShaderPass *)0x1,(EPlugGpuPipeline)param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugShaderPass::SetVertexShader
// =================================================
void __thiscall
CPlugShaderPass::SetVertexShader
          (CPlugShaderPass *this,CPlugShaderPass *param_1,CPlugFileGPUV *param_2)
{
{
  CPlugFileGPU *unaff_retaddr;
  
  SetFileGpu(this,(CPlugShaderPass *)0x0,(EPlugGpuPipeline)param_1,unaff_retaddr);
  return;
}
}

