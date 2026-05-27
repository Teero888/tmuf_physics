// Class implementation: SPlugFaceCull

// =================================================
// Function: SPlugFaceCull::SetMult
// =================================================
void __thiscall
SPlugFaceCull::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  SPlugFaceCull *pSVar1;
  float *pfVar2;
  int iVar3;
  
  iVar3 = 2;
  pSVar1 = param_1 + 0x10;
  pfVar2 = (float *)((int)this + 4);
  do {
    iVar3 = iVar3 + -1;
    pfVar2[-1] = *(float *)(param_2 + 8) * *(float *)(pSVar1 + -8) +
                 *(float *)(pSVar1 + -0x10) * *(float *)param_2 +
                 *(float *)(pSVar1 + -0xc) * *(float *)(param_2 + 4) + *(float *)(param_2 + 0x24);
    *pfVar2 = *(float *)(pSVar1 + -8) * *(float *)(param_2 + 0x14) +
              *(float *)(param_2 + 0x10) * *(float *)(pSVar1 + -0xc) +
              *(float *)(pSVar1 + -0x10) * *(float *)(param_2 + 0xc) + *(float *)(param_2 + 0x28);
    pfVar2[1] = *(float *)(pSVar1 + -8) * *(float *)(param_2 + 0x20) +
                *(float *)(param_2 + 0x1c) * *(float *)(pSVar1 + -0xc) +
                *(float *)(pSVar1 + -0x10) * *(float *)(param_2 + 0x18) + *(float *)(param_2 + 0x2c)
    ;
    pfVar2[2] = *(float *)(pSVar1 + 4) * *(float *)(param_2 + 8) +
                *(float *)(pSVar1 + -4) * *(float *)param_2 +
                *(float *)pSVar1 * *(float *)(param_2 + 4);
    *(float *)(pSVar1 + 0x1c + (int)this + (-0x1c - (int)param_1)) =
         *(float *)(pSVar1 + 4) * *(float *)(param_2 + 0x14) +
         *(float *)(pSVar1 + -4) * *(float *)(param_2 + 0xc) +
         *(float *)(param_2 + 0x10) * *(float *)pSVar1;
    pfVar2[4] = *(float *)(pSVar1 + 4) * *(float *)(param_2 + 0x20) +
                *(float *)(pSVar1 + -4) * *(float *)(param_2 + 0x18) +
                *(float *)(param_2 + 0x1c) * *(float *)pSVar1;
    pfVar2[5] = *(float *)(pSVar1 + 8);
    pSVar1 = pSVar1 + 0x1c;
    pfVar2 = pfVar2 + 7;
  } while (iVar3 != 0);
  return;
}
}

