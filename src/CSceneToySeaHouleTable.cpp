// Class implementation: CSceneToySeaHouleTable

// =================================================
// Function: CSceneToySeaHouleTable::GetPointElevation
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneToySeaHouleTable::GetPointElevation
          (CSceneToySeaHouleTable *this,CSceneToySeaHouleFixe *param_1,float param_2,float param_3,
          float *param_4)
{
{
  GmField2 *this_00;
  float fVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CSceneToySeaHouleFixe **unaff_EBX;
  float *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float in_stack_00000014;
  CSceneToySeaHouleFixe *local_8;
  float local_4;
  
  fVar1 = param_3;
  *(undefined4 *)param_3 = 0;
  this_00 = *(GmField2 **)(this + 0x78);
  if ((this_00 == (GmField2 *)0x0) || ((*(int *)(this + 0x7c) == 0 && (*(int *)(this + 0x70) != 0)))
     ) {
    if ((*(void **)(this + 0x70) == (void *)0x0) ||
       ((*(int *)(this + 0x7c) != 0 && (this_00 != (GmField2 *)0x0)))) {
      param_3 = 1.0;
      goto LAB_0082876b;
    }
    local_8 = param_1;
    local_4 = param_2;
    GmField2Compressed::GetScaleAt
              (*(void **)(this + 0x70),(GmField2Compressed *)&local_8,(GmVec2 *)&param_3,unaff_ESI);
  }
  else {
    local_8 = param_1;
    local_4 = param_2;
    GmField2::GetScaleAt(this_00,(GmField2Compressed *)&local_8,(GmVec2 *)&param_3,unaff_ESI);
  }
  param_4 = (float *)(*(float *)(this + 0x80) * (float)param_4);
  if ((float)param_4 < _DAT_00b41d80) {
    return;
  }
LAB_0082876b:
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x14,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x14,pCVar4,(ulong)unaff_EBX);
      unaff_EBX = &param_1;
      (**(code **)(**(int **)pSVar3 + 0x7c))(param_4,in_stack_00000014);
      pCVar4 = pCVar4 + 1;
      *(float *)fVar1 = *(float *)fVar1 + 0.0;
    } while (pCVar4 < pCVar2);
  }
  *(float *)fVar1 = *(float *)fVar1 * in_stack_00000014;
  return;
}
}

// =================================================
// Function: CSceneToySeaHouleTable::GetPointElevationAssiette
// =================================================
void __thiscall
CSceneToySeaHouleTable::GetPointElevationAssiette
          (CSceneToySeaHouleTable *this,CSceneToySeaHouleTable *param_1,float param_2,float param_3,
          float *param_4)
{
{
  GmField2 *this_00;
  float fVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  float *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float local_c;
  float local_8;
  float fStack_4;
  
  *(undefined4 *)param_3 = 0;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x14,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      local_c = 0.0;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x14,pCVar4,(ulong)unaff_ESI);
      if ((*(int **)pSVar3)[0xc] != 0) {
        unaff_ESI = &local_8;
        (**(code **)(**(int **)pSVar3 + 0x7c))(param_3,param_4);
        *param_4 = *param_4 + local_c;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  this_00 = *(GmField2 **)(this + 0x78);
  if ((this_00 == (GmField2 *)0x0) || ((*(int *)(this + 0x7c) == 0 && (*(int *)(this + 0x70) != 0)))
     ) {
    if ((*(void **)(this + 0x70) == (void *)0x0) ||
       ((*(int *)(this + 0x7c) != 0 && (this_00 != (GmField2 *)0x0)))) {
      fVar1 = 1.0;
    }
    else {
      fStack_4 = param_2;
      GmField2Compressed::GetScaleAt
                (*(void **)(this + 0x70),(GmField2Compressed *)&fStack_4,(GmVec2 *)&param_3,
                 unaff_ESI);
      fVar1 = *(float *)(this + 0x80) * (float)param_4;
    }
  }
  else {
    local_c = param_2;
    local_8 = param_3;
    GmField2::GetScaleAt(this_00,(GmField2Compressed *)&local_c,(GmVec2 *)&param_2,unaff_ESI);
    fVar1 = *(float *)(this + 0x80) * param_3;
  }
  *param_4 = *param_4 * fVar1;
  return;
}
}

// =================================================
// Function: CSceneToySeaHouleTable::SetSamplingTime
// =================================================
void __thiscall
CSceneToySeaHouleTable::SetSamplingTime
          (CSceneToySeaHouleTable *this,CSceneToySeaHouleTable *param_1,ulong param_2,int param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x14,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x14,pCVar3,unaff_EBX);
      unaff_EBX = param_3;
      if (param_3 == 0) {
        (**(code **)(**(int **)pSVar2 + 0x84))();
      }
      else {
        (**(code **)(**(int **)pSVar2 + 0x78))();
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

