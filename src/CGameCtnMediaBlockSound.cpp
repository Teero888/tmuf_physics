// Class implementation: CGameCtnMediaBlockSound

// =================================================
// Function: CGameCtnMediaBlockSound::GetValue
// =================================================
GmVec3 __thiscall
CGameCtnMediaBlockSound::GetValue
          (CGameCtnMediaBlockSound *this,CFuncColorGradient *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  SCasterCat *pSVar5;
  SCasterCat *pSVar6;
  float unaff_ESI;
  ulong unaff_EDI;
  CFuncColorGradient *pCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  undefined4 *local_c;
  float local_8;
  float *pfStack_4;
  
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&param_1;
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_c;
  local_c = (undefined4 *)0x0;
  local_8 = 0.0;
  pCVar7 = param_1;
  iVar4 = (**(code **)(*(int *)(this + 0x24) + 0x18))(param_1,pCVar8,&local_8,pCVar9,1);
  if (iVar4 == 0) {
    *local_c = 0x3f800000;
    local_c[1] = 0;
    local_c[4] = 0;
    local_c[3] = 0;
    local_c[2] = 0;
    return SUB41(local_c,0);
  }
  if ((0.0 <= unaff_ESI) && (unaff_ESI <= 1.0)) {
    pSVar5 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                       (this + 0x28,pCVar8,unaff_EDI);
    pSVar6 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                       (this + 0x28,pCVar9,(ulong)pCVar7);
    *pfStack_4 = local_8 * (*(float *)(pSVar6 + 4) - *(float *)(pSVar5 + 4)) +
                 *(float *)(pSVar5 + 4);
    pfStack_4[1] = *(float *)(pSVar5 + 8) +
                   local_8 * (*(float *)(pSVar6 + 8) - *(float *)(pSVar5 + 8));
    pfStack_4[2] = *(float *)(pSVar6 + 0xc) - *(float *)(pSVar5 + 0xc);
    pfStack_4[3] = *(float *)(pSVar6 + 0x10) - *(float *)(pSVar5 + 0x10);
    pfStack_4[4] = *(float *)(pSVar6 + 0x14) - *(float *)(pSVar5 + 0x14);
    fVar1 = pfStack_4[2];
    pfStack_4[2] = fVar1 * local_8;
    fVar2 = pfStack_4[3];
    pfStack_4[3] = fVar2 * local_8;
    fVar3 = pfStack_4[4];
    pfStack_4[4] = fVar3 * local_8;
    pfStack_4[2] = *(float *)(pSVar5 + 0xc) + fVar1 * local_8;
    pfStack_4[3] = *(float *)(pSVar5 + 0x10) + fVar2 * local_8;
    pfStack_4[4] = fVar3 * local_8 + *(float *)(pSVar5 + 0x14);
    return (GmVec3)((char)pSVar6 + '\x04');
  }
  return (GmVec3)0x0;
}
}

