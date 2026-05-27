// Class implementation: GmSurfSphere

// =================================================
// Function: GmSurfSphere::ClipSegment
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
GmSurfSphere::ClipSegment
          (GmSurfSphere *this,GmSurfSphere *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,
          float *param_5)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  
  fVar1 = *(float *)param_1 - *(float *)param_3;
  fVar2 = *(float *)(param_1 + 4) - *(float *)(param_3 + 4);
  fVar3 = *(float *)(param_1 + 8) - *(float *)(param_3 + 8);
  fVar4 = fVar3 * *(float *)(param_2 + 8) +
          fVar2 * *(float *)(param_2 + 4) + fVar1 * *(float *)param_2;
  fVar5 = *(float *)(param_2 + 8) * *(float *)(param_2 + 8) +
          *(float *)param_2 * *(float *)param_2 + *(float *)(param_2 + 4) * *(float *)(param_2 + 4);
  if (0.0 <= fVar4 * fVar4 * (float)_DAT_00b3d2c8 -
             ((fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3) -
             *(float *)(this + 8) * *(float *)(this + 8)) * fVar5 * (float)_DAT_00b3d2c8) {
    fVar6 = (float10)func_0x009c1b40();
    fVar5 = (-fVar4 - (float)fVar6 * (float)_DAT_00b313b8) / fVar5;
    if ((0.0 <= fVar5) && (fVar5 <= 1.0)) {
      *(float *)param_4 = fVar5;
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmSurfSphere::GetSphereBoundingBox
// =================================================
void __thiscall
GmSurfSphere::GetSphereBoundingBox(GmSurfSphere *this,GmSurfSphere *param_1,GmBoxAligned *param_2)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(this + 8);
  uVar2 = *(undefined4 *)(this + 8);
  uVar3 = *(undefined4 *)(this + 8);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  return;
}
}

// =================================================
// Function: GmSurfSphere::GmSurfSphere
// =================================================
void __thiscall GmSurfSphere::GmSurfSphere(GmSurfSphere *this,GmSurfSphere *param_1)
{
{
  GmSurf *unaff_ESI;
  
  GmSurf::GmSurf((GmSurf *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  this[6] = (GmSurfSphere)0x0;
  return;
}
}

