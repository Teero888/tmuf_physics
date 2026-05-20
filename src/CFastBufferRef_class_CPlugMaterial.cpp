// Class implementation: CFastBufferRef_class_CPlugMaterial

// =================================================
// Function: CFastBufferRef<class_CPlugMaterial>::AllocSetCount
// =================================================
void __thiscall
CFastBufferRef<class_CPlugMaterial>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  CFastBuffer<class_GxVertex2> *pCVar1;
  int iVar2;
  CMwNod *this_00;
  CMwNod *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<class_GxVertex2> *pCVar3;
  
  pCVar1 = *(CFastBuffer<class_GxVertex2> **)this;
  for (pCVar3 = param_1; pCVar3 < pCVar1; pCVar3 = pCVar3 + 1) {
    iVar2 = *(int *)((int)this + 4);
    this_00 = *(CMwNod **)(iVar2 + (int)pCVar3 * 4);
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwRelease(this_00,unaff_ESI);
      *(undefined4 *)(iVar2 + (int)pCVar3 * 4) = 0;
    }
  }
  CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::AllocSetCount(this,param_1,unaff_EDI);
  return;
}
}

// =================================================
// Function: CFastBufferRef<class_CPlugMaterial>::Reset
// =================================================
void __thiscall CFastBufferRef<class_CPlugMaterial>::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  int iVar1;
  CMwNod *this_00;
  CMwNod *unaff_ESI;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = *(int *)((int)this + 4);
      this_00 = *(CMwNod **)(iVar1 + uVar2 * 4);
      if (this_00 != (CMwNod *)0x0) {
        CMwNod::MwRelease(this_00,unaff_ESI);
        *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)this);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,param_1);
  return;
}
}

