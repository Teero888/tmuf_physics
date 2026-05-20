// Class implementation: CPlugSurfaceMaterialData

// =================================================
// Function: CPlugSurfaceMaterialData::GetRestitutionCoefWith
// =================================================
float __thiscall
CPlugSurfaceMaterialData::GetRestitutionCoefWith
          (void *this,CPlugSurfaceMaterialData *param_1,CPlugSurfaceMaterialData *param_2)
{
{
  if (*(float *)((int)this + 4) <= 0.0) {
    if (0.0 < *(float *)(param_1 + 4)) {
      return *(float *)((int)this + 4);
    }
    return *(float *)(param_1 + 4) + *(float *)((int)this + 4);
  }
  if (0.0 < *(float *)(param_1 + 4)) {
    return *(float *)(param_1 + 4) * *(float *)((int)this + 4);
  }
  return *(float *)(param_1 + 4);
}
}

