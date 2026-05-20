// Class implementation: GxFogBlender

// =================================================
// Function: GxFogBlender::BlendFogAtX_Wrap01
// =================================================
void __thiscall
GxFogBlender::BlendFogAtX_Wrap01
          (GxFogBlender *this,GxFogBlender *param_1,GxFog *param_2,float param_3)
{
{
  int iVar1;
  float fVar2;
  GxFogBlender *pGVar3;
  int iVar4;
  SCasterCat *pSVar5;
  ulong unaff_EBX;
  ulong unaff_ESI;
  float *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  GxFogBlender *pGStack_4;
  
  pGVar3 = param_1;
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(this + 0x14);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(this + 0x18);
  pGStack_4 = this;
  iVar4 = (*(code *)**(undefined4 **)(this + 0x1c))();
  if (iVar4 != 0) {
    CFastBufferKey<class_CMwNodRef<class_GxFog>_>::ComputeBlendCoefDichoWrap01
              ((CFastBufferKey<class_CMwNodRef<class_GxFog>_> *)(this + 0x1c),
               (CFastBufferKey<class_CMwNodRef<class_GxFog>_> *)param_2,(float)&param_1,
               (ulong *)&param_2,(ulong *)&pGStack_4,unaff_EDI);
    pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                       (this + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                        unaff_ESI);
    iVar4 = *(int *)(pSVar5 + 4);
    pSVar5 = CFastBuffer<struct_SFastCat>::operator[](this + 0x20,in_stack_00000010,unaff_EBX);
    iVar1 = *(int *)(pSVar5 + 4);
    fVar2 = 1.0 - (float)param_2;
    *(float *)(pGVar3 + 0x1c) =
         *(float *)(iVar1 + 0x1c) * (float)param_2 + fVar2 * *(float *)(iVar4 + 0x1c);
    *(float *)(pGVar3 + 0x20) =
         *(float *)(iVar1 + 0x20) * (float)param_2 + *(float *)(iVar4 + 0x20) * fVar2;
    *(float *)(pGVar3 + 0x24) =
         *(float *)(iVar1 + 0x24) * (float)param_2 + *(float *)(iVar4 + 0x24) * fVar2;
    *(float *)(pGVar3 + 0x28) =
         *(float *)(iVar1 + 0x28) * (float)param_2 + *(float *)(iVar4 + 0x28) * fVar2;
    *(float *)(pGVar3 + 0x2c) =
         *(float *)(iVar1 + 0x2c) * (float)param_2 + *(float *)(iVar4 + 0x2c) * fVar2;
    *(float *)(pGVar3 + 0x30) =
         *(float *)(iVar1 + 0x30) * (float)param_2 + *(float *)(iVar4 + 0x30) * fVar2;
    *(float *)(pGVar3 + 0x34) =
         *(float *)(iVar1 + 0x34) * (float)param_2 + *(float *)(iVar4 + 0x34) * fVar2;
    *(float *)(pGVar3 + 0x38) =
         *(float *)(iVar1 + 0x38) * (float)param_2 + *(float *)(iVar4 + 0x38) * fVar2;
    *(float *)(pGVar3 + 0x3c) =
         fVar2 * *(float *)(iVar4 + 0x3c) + *(float *)(iVar1 + 0x3c) * (float)param_2;
  }
  return;
}
}

