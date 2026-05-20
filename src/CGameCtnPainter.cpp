// Class implementation: CGameCtnPainter

// =================================================
// Function: CGameCtnPainter::GetActiveButtons
// =================================================
CFastBuffer<class_CControlButton*> * __thiscall
CGameCtnPainter::GetActiveButtons(CGameCtnPainter *this,CGameCtnPainter *param_1)
{
{
  CFastBuffer<class_CControlButton*> *pCVar1;
  
  switch(*(undefined4 *)(this + 0x14)) {
  case 1:
    return (CFastBuffer<class_CControlButton*> *)(this + 0x3d4);
  case 2:
    pCVar1 = (CFastBuffer<class_CControlButton*> *)(this + 0x3ec);
    if (*(int *)(this + 0x2ac) == 0) {
      return (CFastBuffer<class_CControlButton*> *)(this + 0x3bc);
    }
    break;
  case 3:
    pCVar1 = (CFastBuffer<class_CControlButton*> *)(this + 0x3ec);
    if (*(int *)(this + 0x2ac) == 0) {
      return (CFastBuffer<class_CControlButton*> *)(this + 0x3c8);
    }
    break;
  case 4:
    return (CFastBuffer<class_CControlButton*> *)(this + 0x3e0);
  default:
    pCVar1 = (CFastBuffer<class_CControlButton*> *)0x0;
  }
  return pCVar1;
}
}

// =================================================
// Function: CGameCtnPainter::GetActiveImages
// =================================================
CFastBuffer<class_CGameCtnPainter::CConstructionImage> * __thiscall
CGameCtnPainter::GetActiveImages(CGameCtnPainter *this,CGameCtnPainter *param_1)
{
{
  CFastBuffer<class_CGameCtnPainter::CConstructionImage> *pCVar1;
  
  switch(*(undefined4 *)(this + 0x14)) {
  case 1:
    return (CFastBuffer<class_CGameCtnPainter::CConstructionImage> *)(this + 0x398);
  case 2:
    pCVar1 = (CFastBuffer<class_CGameCtnPainter::CConstructionImage> *)(this + 0x3b0);
    if (*(int *)(this + 0x2ac) == 0) {
      return (CFastBuffer<class_CGameCtnPainter::CConstructionImage> *)(this + 0x38c);
    }
    break;
  case 3:
    pCVar1 = (CFastBuffer<class_CGameCtnPainter::CConstructionImage> *)(this + 0x3b0);
    if (*(int *)(this + 0x2ac) == 0) {
      return (CFastBuffer<class_CGameCtnPainter::CConstructionImage> *)(this + 0x380);
    }
    break;
  case 4:
    return (CFastBuffer<class_CGameCtnPainter::CConstructionImage> *)(this + 0x3a4);
  default:
    pCVar1 = (CFastBuffer<class_CGameCtnPainter::CConstructionImage> *)0x0;
  }
  return pCVar1;
}
}

// =================================================
// Function: CGameCtnPainter::StepImagesOnLeft
// =================================================
void __thiscall CGameCtnPainter::StepImagesOnLeft(CGameCtnPainter *this,CGameCtnPainter *param_1)
{
{
  int *piVar1;
  ulong uVar2;
  CFastBuffer<class_CGameCtnPainter::CConstructionImage> *this_00;
  SCasterCat *pSVar3;
  CControlGrid *pCVar4;
  CFastBuffer<class_CControlButton*> *this_01;
  byte bVar5;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CMwTimer *unaff_ESI;
  CGameCtnPainter *unaff_EDI;
  CControlContainer *in_stack_0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  ulong uVar7;
  
  if (*(int *)(this + 0x2c8) != 0) {
    if (*(int *)(this + 0x33c) == 0) {
      *(undefined4 *)(this + 0x33c) = 1;
      uVar2 = CMwTimer::GetElapsedTimeSinceInit((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
      *(ulong *)(this + 0x34c) = uVar2;
      *(ulong *)(this + 0x350) = uVar2;
    }
    this_00 = GetActiveImages(this,unaff_EDI);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
    *(uint *)(this + 0x2d0) = (*(int *)(this + 0x2d0) + -1 + uVar2) % uVar2;
    if (*(int *)(this + 0x300) != -1) {
      *(uint *)(this + 0x300) = (*(int *)(this + 0x300) + -1 + uVar2) % uVar2;
    }
    piVar1 = *(int **)(this + 0x2c8);
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (piVar1 + 0x51,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        unaff_EBX);
    pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar3;
    uVar7 = 0;
    (**(code **)(*piVar1 + 0x1fc))();
    bVar5 = 0;
    if ((byte)this[0x2d8] != 1 && -1 < (int)((byte)this[0x2d8] - 1)) {
      pCVar4 = (CControlGrid *)0x0;
      do {
        CControlGrid::SetChildSquare
                  (*(CControlGrid **)(this + 0x2c8),pCVar4,(ulong)pCVar4,0,(ulong)pCVar6);
        bVar5 = bVar5 + 1;
        pCVar4 = (CControlGrid *)(uint)bVar5;
      } while ((int)pCVar4 < (int)((byte)this[0x2d8] - 1));
    }
    param_1 = (CGameCtnPainter *)0x0;
    piVar1 = *(int **)(this + 0x2c8);
    this_01 = GetActiveButtons(this,(CGameCtnPainter *)
                                    ((((uint)(byte)this[0x2d8] - *(int *)(this + 0x2d0)) + -1 +
                                     uVar2) % uVar2));
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_01,pCVar6,uVar7);
    (**(code **)(*piVar1 + 0x1f8))(*(undefined4 *)pSVar3,&param_1);
    CControlContainer::SetLayoutDirty(*(CControlContainer **)(this + 0x2c8),in_stack_0000000c);
    return;
  }
  return;
}
}

// =================================================
// Function: CGameCtnPainter::StepImagesOnRight
// =================================================
void __thiscall CGameCtnPainter::StepImagesOnRight(CGameCtnPainter *this,CGameCtnPainter *param_1)
{
{
  int *piVar1;
  ulong uVar2;
  CFastBuffer<class_CGameCtnPainter::CConstructionImage> *this_00;
  SCasterCat *pSVar3;
  CFastBuffer<class_CControlButton*> *this_01;
  CGameCtnPainter CVar4;
  CGameCtnPainter *unaff_EBX;
  CMwTimer *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff4;
  ulong uVar6;
  
  if (*(int *)(this + 0x2c8) != 0) {
    if (*(int *)(this + 0x340) == 0) {
      *(undefined4 *)(this + 0x340) = 1;
      uVar2 = CMwTimer::GetElapsedTimeSinceInit((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
      *(ulong *)(this + 0x34c) = uVar2;
      *(ulong *)(this + 0x350) = uVar2;
    }
    this_00 = GetActiveImages(this,unaff_EBX);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_fffffff4);
    *(uint *)(this + 0x2d0) = (*(int *)(this + 0x2d0) + 1U) % uVar2;
    if (*(int *)(this + 0x300) != -1) {
      *(uint *)(this + 0x300) = (*(int *)(this + 0x300) + 1U) % uVar2;
    }
    piVar1 = *(int **)(this + 0x2c8);
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (piVar1 + 0x51,
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((byte)this[0x2d8] - 1),
                        unaff_EDI);
    pCVar5 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar3;
    uVar6 = 0;
    (**(code **)(*piVar1 + 0x1fc))();
    param_1 = (CGameCtnPainter *)0x0;
    piVar1 = *(int **)(this + 0x2c8);
    this_01 = GetActiveButtons(this,(CGameCtnPainter *)((uVar2 - *(int *)(this + 0x2d0)) % uVar2));
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_01,pCVar5,uVar6);
    (**(code **)(*piVar1 + 0x1f8))(*(undefined4 *)pSVar3,&param_1);
    uVar2 = 0;
    (**(code **)(**(int **)(this + 0x2c8) + 0x200))((byte)this[0x2d8] - 1);
    CVar4 = (CGameCtnPainter)0x0;
    if (this[0x2d8] != (CGameCtnPainter)0x0) {
      do {
        CControlGrid::SetChildSquare
                  (*(CControlGrid **)(this + 0x2c8),(CControlGrid *)(uint)(byte)CVar4,
                   (ulong)(uint)(byte)CVar4,0,uVar2);
        CVar4 = (CGameCtnPainter)((char)CVar4 + '\x01');
      } while ((byte)CVar4 < (byte)this[0x2d8]);
    }
    CControlContainer::SetLayoutDirty
              (*(CControlContainer **)(this + 0x2c8),(CControlContainer *)param_1);
    return;
  }
  return;
}
}

