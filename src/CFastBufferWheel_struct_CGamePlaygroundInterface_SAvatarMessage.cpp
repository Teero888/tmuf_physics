// Class implementation: CFastBufferWheel_struct_CGamePlaygroundInterface_SAvatarMessage

// =================================================
// Function: CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel
// =================================================
void __thiscall
CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel
          (void *this,CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *param_1)
{
{
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)this = 0;
  return;
}
}

// =================================================
// Function: CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::InsertNewElemFromStart
// =================================================
SHistoryPoint * __thiscall
CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::InsertNewElemFromStart
          (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2)
{
{
  undefined4 *puVar1;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar2;
  uint uVar3;
  int iVar4;
  CMwNod *this_00;
  uint uVar5;
  uint uVar6;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar7;
  int iVar8;
  GmVec3 *unaff_ESI;
  SNormalDec3N *unaff_EDI;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar9;
  uint uStack_c;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *local_8;
  undefined4 local_4;
  
  if ((*(int *)((int)this + 0x10) == 0) || (*(int *)this != *(int *)((int)this + 0x10))) {
    pCVar2 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8);
    pCVar7 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(*(int *)this + 1);
    if (pCVar2 < pCVar7) {
      CFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage>::SetSizeAtLeast
                (this,pCVar7,(ulong)unaff_EDI);
      pCVar9 = pCVar2 + -1;
      if (*(int *)((int)this + 0xc) <= (int)pCVar9) {
        iVar8 = (int)pCVar9 * 0x18;
        do {
          unaff_EDI = (SNormalDec3N *)(iVar8 + *(int *)((int)this + 4));
          CGamePlaygroundInterface::SAvatarMessage::operator=
                    ((void *)(*(int *)((int)this + 4) +
                             (int)(pCVar9 + (*(int *)((int)this + 8) - (int)pCVar2)) * 0x18),
                     unaff_EDI,unaff_ESI);
          pCVar9 = pCVar9 + -1;
          iVar8 = iVar8 + -0x18;
          pCVar7 = local_8;
        } while (*(int *)((int)this + 0xc) <= (int)pCVar9);
      }
      *(int *)((int)this + 0xc) =
           *(int *)((int)this + 0xc) + (*(int *)((int)this + 8) - (int)pCVar2);
    }
    else if (*(int *)((int)this + 0xc) == 0) {
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 0xc) = pCVar2;
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this = pCVar7;
  }
  else if (*(int *)((int)this + 0xc) == 0) {
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 8);
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  uStack_c = 0;
  if (param_2 != 0) {
    do {
      uVar6 = *(int *)((int)this + 0xc) + uStack_c;
      uVar3 = *(uint *)((int)this + 8);
      uVar5 = uVar6 + 1;
      if (uVar3 <= uVar5) {
        uVar5 = uVar5 - uVar3;
      }
      if (uVar3 <= uVar6) {
        uVar6 = uVar6 - uVar3;
      }
      iVar4 = *(int *)((int)this + 4);
      this_00 = *(CMwNod **)(iVar4 + uVar5 * 0x18);
      iVar8 = iVar4 + uVar5 * 0x18;
      puVar1 = (undefined4 *)(iVar4 + uVar6 * 0x18);
      if (this_00 != *(CMwNod **)(iVar4 + uVar6 * 0x18)) {
        if (this_00 != (CMwNod *)0x0) {
          unaff_EDI = (SNormalDec3N *)0x5e27ee;
          CMwNod::MwAddRef(this_00,(CMwNod *)unaff_ESI);
        }
        if ((CMwNod *)*puVar1 != (CMwNod *)0x0) {
          CMwNod::MwRelease((CMwNod *)*puVar1,(CMwNod *)unaff_EDI);
        }
        *puVar1 = this_00;
      }
      puVar1[1] = *(undefined4 *)(iVar8 + 4);
      local_8 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)(iVar8 + 8);
      uStack_c = *(int *)(iVar8 + 0xc);
      local_4 = 0;
      CFastStringInt::SetString(puVar1 + 2,(CFastStringInt *)&uStack_c,(SStringParam *)unaff_EDI);
      puVar1[4] = *(undefined4 *)(iVar8 + 0x10);
      uStack_c = uStack_c + 1;
      puVar1[5] = *(undefined4 *)(iVar8 + 0x14);
    } while (uStack_c < param_2);
  }
  uVar5 = *(int *)((int)this + 0xc) + param_2;
  if (*(uint *)((int)this + 8) <= uVar5) {
    uVar5 = uVar5 - *(uint *)((int)this + 8);
  }
  return (SHistoryPoint *)(*(int *)((int)this + 4) + uVar5 * 0x18);
}
}

// =================================================
// Function: CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::PushNewElem
// =================================================
SBlockState * __thiscall
CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::PushNewElem
          (void *this,
          CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1)
{
{
  SHistoryPoint *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = InsertNewElemFromStart
                     (this,(CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *)0x0,unaff_retaddr);
  return (SBlockState *)pSVar1;
}
}

// =================================================
// Function: CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::Tail
// =================================================
GmVec3 * __thiscall
CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::Tail
          (void *this,CFastBufferWheel<class_GmVec3> *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 0xc) + -1 + *(int *)this;
  if (*(uint *)((int)this + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 8);
  }
  return (GmVec3 *)(*(int *)((int)this + 4) + uVar1 * 0x18);
}
}

