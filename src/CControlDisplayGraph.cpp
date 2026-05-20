// Class implementation: CControlDisplayGraph

// =================================================
// Function: CControlDisplayGraph::AdvanceOneStep
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CControlDisplayGraph::AdvanceOneStep
          (CControlDisplayGraph *this,CControlDisplayGraph *param_1,int param_2)
{
{
  void *this_00;
  int iVar1;
  float fVar2;
  ulong uVar3;
  SLoadedLight *pSVar4;
  uint uVar5;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if (param_1 != (CControlDisplayGraph *)0x0) {
    (**(code **)(*(int *)this + 0x178))();
  }
  if (*(int *)(this + 0x140) != 0) {
    uVar5 = (*(int *)(this + 0x14c) + 1U) % *(uint *)(this + 0x124);
    fVar2 = (float)(int)uVar5;
    if ((int)uVar5 < 0) {
      fVar2 = fVar2 + _DAT_00c418d0;
    }
    *(float *)(*(int *)(this + 0x154) + 0x14) = fVar2 * *(float *)(this + 0x148);
    *(undefined4 *)(*(int *)(this + 0x154) + 4) = *(undefined4 *)(*(int *)(this + 0x154) + 0x14);
    *(float *)(*(int *)(this + 0x154) + 0x1c) =
         (fVar2 * *(float *)(this + 0x148) + (float)_DAT_00b2c188) -
         (*(float *)(this + 0x148) + *(float *)(this + 0x148));
    *(undefined4 *)(*(int *)(this + 0x154) + 0xc) = *(undefined4 *)(*(int *)(this + 0x154) + 0x1c);
    *(uint *)(*(int *)(this + 0x144) + 0x50) = *(uint *)(*(int *)(this + 0x144) + 0x50) & 0xff7fffff
    ;
    this_00 = *(void **)(*(int *)(this + 0x144) + 0x74);
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    if (uVar3 < 0xb) {
      pSVar4 = CFastBuffer<class_GmInt4>::AddNewElem(this_00,unaff_EBX);
    }
    else {
      pSVar4 = (SLoadedLight *)
               CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos>::GetLastElem
                         (this_00,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                   *)unaff_EBX);
    }
    *(undefined4 *)pSVar4 = 0;
    *(undefined4 *)(pSVar4 + 8) = *(undefined4 *)(this + 0x120);
    iVar1 = *(int *)(this + 0x14c);
    *(int *)(pSVar4 + 4) = iVar1;
    *(int *)(pSVar4 + 0xc) = iVar1 + 1;
    *(uint *)(this + 0x14c) = uVar5;
  }
  return;
}
}

