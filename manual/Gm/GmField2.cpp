// Class implementation: GmField2

// =================================================
// Function: GmField2::GetScaleAt
// =================================================
void __thiscall
GmField2::GetScaleAt(GmField2 *this,GmField2Compressed *param_1,GmVec2 *param_2,float *param_3)
{
{
  float fVar1;
  int iVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  int iVar4;
  GmVec2 *unaff_EDI;
  GmField2 *this_00;
  float unaff_retaddr;
  float *in_stack_0000001c;
  ulong in_stack_ffffffd8;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  iVar2 = GmField2Base::GetBoundingCoords
                    ((GmField2Base *)this,(GmField2Base *)param_1,(GmVec2 *)&local_20,
                     (GmNat2 *)&stack0xffffffd8,(GmNat2 *)&local_18,unaff_EDI);
  if (iVar2 == 0) {
    *param_3 = *(float *)(this + 0x24);
    return;
  }
  iVar2 = *(int *)(this + 0x1c);
  iVar4 = iVar2 * local_18;
  this_00 = this + 0x34;
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar4 + local_1c),
                      unaff_ESI);
  local_8 = *(undefined4 *)pSVar3;
  local_4 = *(float *)(pSVar3 + 4);
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar4 + local_20),
                      unaff_EBP);
  local_14 = *(undefined4 *)pSVar3;
  local_10 = *(undefined4 *)(pSVar3 + 4);
  iVar2 = iVar2 * local_18;
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar2 + local_1c),
                      unaff_EBX);
  fVar1 = *(float *)(pSVar3 + 4);
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar2 + local_18),
                      in_stack_ffffffd8);
  *in_stack_0000001c =
       local_4 * unaff_retaddr * *(float *)pSVar3 +
       unaff_retaddr * (1.0 - local_4) * fVar1 +
       (1.0 - local_4) * (1.0 - unaff_retaddr) * (float)param_1 +
       local_4 * (1.0 - unaff_retaddr) * local_c;
  return;
}
}

