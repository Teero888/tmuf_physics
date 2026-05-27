// Class implementation: CFastBufferWheel_class_CPlugFileSndGen

// =================================================
// Function: >::Head
// =================================================
SBlockState * __thiscall
CFastBufferWheel<class_CPlugFileSndGen*>::Head
          (void *this,
          CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 0xc);
  if (*(uint *)((int)this + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 8);
  }
  return (SBlockState *)(*(int *)((int)this + 4) + uVar1 * 4);
}
}

// =================================================
// Function: >::InsertNewElemFromStart
// =================================================
SHistoryPoint * __thiscall
CFastBufferWheel<class_CPlugFileSndGen*>::InsertNewElemFromStart
          (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar2;
  uint uVar3;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar4;
  uint uVar5;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar6;
  uint uVar7;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar8;
  ulong unaff_EDI;
  uint uVar9;
  
  if ((*(int *)((int)this + 0x10) == 0) || (*(int *)this != *(int *)((int)this + 0x10))) {
    pCVar2 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8);
    pCVar8 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(*(int *)this + 1);
    if (pCVar2 < pCVar8) {
      CFastBuffer<int>::SetSizeAtLeast(this,pCVar8,unaff_EDI);
      pCVar4 = pCVar2 + -1;
      if (*(int *)((int)this + 0xc) <= (int)pCVar4) {
        do {
          iVar1 = (int)pCVar4 * 4;
          pCVar6 = pCVar4 + (*(int *)((int)this + 8) - (int)pCVar2);
          pCVar4 = pCVar4 + -1;
          *(undefined4 *)(*(int *)((int)this + 4) + (int)pCVar6 * 4) =
               *(undefined4 *)(*(int *)((int)this + 4) + iVar1);
        } while (*(int *)((int)this + 0xc) <= (int)pCVar4);
      }
      *(int *)((int)this + 0xc) =
           *(int *)((int)this + 0xc) + (*(int *)((int)this + 8) - (int)pCVar2);
    }
    else if (*(int *)((int)this + 0xc) == 0) {
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 0xc) = pCVar2;
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this = pCVar8;
  }
  else if (*(int *)((int)this + 0xc) == 0) {
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 8);
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  uVar5 = 0;
  if (param_2 != 0) {
    do {
      uVar3 = *(uint *)((int)this + 8);
      uVar9 = *(int *)((int)this + 0xc) + uVar5;
      uVar7 = uVar9 + 1;
      if (uVar3 <= uVar7) {
        uVar7 = uVar7 - uVar3;
      }
      if (uVar3 <= uVar9) {
        uVar9 = uVar9 - uVar3;
      }
      uVar5 = uVar5 + 1;
      *(undefined4 *)(*(int *)((int)this + 4) + uVar9 * 4) =
           *(undefined4 *)(*(int *)((int)this + 4) + uVar7 * 4);
    } while (uVar5 < param_2);
  }
  uVar5 = *(int *)((int)this + 0xc) + param_2;
  if (*(uint *)((int)this + 8) <= uVar5) {
    uVar5 = uVar5 - *(uint *)((int)this + 8);
  }
  return (SHistoryPoint *)(*(int *)((int)this + 4) + uVar5 * 4);
}
}

// =================================================
// Function: >::Pop
// =================================================
void __thiscall CFastBufferWheel<class_CPlugFileSndGen*>::Pop(void *this,SCharStyle *param_1)
{
{
  if (*(int *)this == 0) {
    return;
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  *(int *)this = *(int *)this + -1;
  if (*(uint *)((int)this + 8) <= *(uint *)((int)this + 0xc)) {
    *(undefined4 *)((int)this + 0xc) = 0;
  }
  return;
}
}

// =================================================
// Function: >::ReleaseAllWheel
// =================================================
void __thiscall
CFastBufferWheel<class_CPlugFileSndGen*>::ReleaseAllWheel
          (void *this,CFastBufferWheel<class_CPlugFileSndGen*> *param_1)
{
{
  uint uVar1;
  CMwNod *unaff_EDI;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = *(int *)((int)this + 0xc);
  if (*(int *)this != 0) {
    do {
      if (*(int *)(*(int *)((int)this + 4) + iVar2 * 4) != 0) {
        CMwNod::MwRelease(*(CMwNod **)(*(int *)((int)this + 4) + iVar2 * 4),unaff_EDI);
      }
      iVar2 = iVar2 + 1;
      uVar1 = uVar1 + 1;
      if (iVar2 == *(int *)((int)this + 8)) {
        iVar2 = 0;
      }
    } while (uVar1 < *(uint *)this);
  }
  _memset(*(void **)((int)this + 4),0,*(int *)((int)this + 8) * 4);
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel
            (this,(CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *)param_1);
  return;
}
}

