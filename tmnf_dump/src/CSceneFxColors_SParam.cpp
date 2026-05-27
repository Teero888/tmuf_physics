// Class implementation: CSceneFxColors_SParam

// =================================================
// Function: CSceneFxColors::SParam::AddMult
// =================================================
void __thiscall
CSceneFxColors::SParam::AddMult(void *this,SParam *param_1,SParam *param_2,float param_3)
{
{
  float fVar1;
  float fVar2;
  
  *(float *)this = *(float *)this + (float)param_2 * *(float *)param_1;
  *(float *)((int)this + 4) = *(float *)(param_1 + 4) * (float)param_2 + *(float *)((int)this + 4);
  *(float *)((int)this + 8) = *(float *)(param_1 + 8) * (float)param_2 + *(float *)((int)this + 8);
  *(float *)((int)this + 0xc) =
       *(float *)(param_1 + 0xc) * (float)param_2 + *(float *)((int)this + 0xc);
  *(float *)((int)this + 0x10) =
       *(float *)(param_1 + 0x10) * (float)param_2 + *(float *)((int)this + 0x10);
  fVar1 = *(float *)(param_1 + 0x18);
  fVar2 = *(float *)(param_1 + 0x1c);
  *(float *)((int)this + 0x14) =
       *(float *)((int)this + 0x14) + (*(float *)(param_1 + 0x14) - 1.0) * (float)param_2;
  *(float *)((int)this + 0x18) = *(float *)((int)this + 0x18) + (fVar1 - 1.0) * (float)param_2;
  *(float *)((int)this + 0x1c) = (fVar2 - 1.0) * (float)param_2 + *(float *)((int)this + 0x1c);
  fVar1 = *(float *)(param_1 + 0x24);
  fVar2 = *(float *)(param_1 + 0x28);
  *(float *)((int)this + 0x20) =
       *(float *)((int)this + 0x20) + *(float *)(param_1 + 0x20) * (float)param_2;
  *(float *)((int)this + 0x24) = *(float *)((int)this + 0x24) + fVar1 * (float)param_2;
  *(float *)((int)this + 0x28) = *(float *)((int)this + 0x28) + fVar2 * (float)param_2;
  *(float *)((int)this + 0x2c) =
       (float)param_2 * *(float *)(param_1 + 0x2c) + *(float *)((int)this + 0x2c);
  return;
}
}

// =================================================
// Function: CSceneFxColors::SParam::SetBlend
// =================================================
void __thiscall
CSceneFxColors::SParam::SetBlend
          (void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4)
{
{
  GmIso4 *unaff_ESI;
  SPlugFaceCull *pSVar1;
  
  pSVar1 = (SPlugFaceCull *)(1.0 - (float)param_3);
  SetMult(this,(SPlugFaceCull *)param_1,pSVar1,unaff_ESI);
  AddMult(this,param_3,(SParam *)param_4,(float)pSVar1);
  return;
}
}

