// Class implementation: CFastBuffer_unsigned_short

// =================================================
// Function: CFastBuffer<unsigned_short>::Add
// =================================================
void __thiscall
CFastBuffer<unsigned_short>::Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(undefined2 *)(*(int *)((int)this + 4) + *(int *)this * 2) = *(undefined2 *)param_2;
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1);
  return;
}
}

// =================================================
// Function: CFastBuffer<unsigned_short>::CopyFromFastBuffer
// =================================================
void __thiscall
CFastBuffer<unsigned_short>::CopyFromFastBuffer
          (void *this,CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_1,
          CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_2)
{
{
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  GmFrustumIso4 *unaff_EDI;
  ulong unaff_retaddr;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_EDI);
  pCVar1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)
           CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize(param_2,unaff_ESI);
  SetSizeAtLeast(this,pCVar1,unaff_EBP);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EBX);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = operator[](param_2,pCVar4,unaff_retaddr);
      *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar4 * 2) = *(undefined2 *)pSVar3;
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this = pCVar2;
  return;
}
}

// =================================================
// Function: CFastBuffer<unsigned_short>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<unsigned_short>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((int)this + 8);
  if (0 < (int)((int)param_1 - uVar2)) {
    if ((int)((int)param_1 - uVar2) <= (int)(uVar2 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar2 >> 1) + uVar2);
    }
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 2 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 2));
    uVar2 = 0;
    if (*(int *)this != 0) {
      do {
        *(undefined2 *)((int)pvVar1 + uVar2 * 2) =
             *(undefined2 *)(*(int *)((int)this + 4) + uVar2 * 2);
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(void **)((int)this + 4) = pvVar1;
  }
  return;
}
}

