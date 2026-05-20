// Class implementation: CFastBuffer_class_CGameCtnCampaign

// =================================================
// Function: >::GetNodIndexFromId
// =================================================
ulong __thiscall
CFastBuffer<class_CGameCtnCampaign*>::GetNodIndexFromId
          (void *this,CFastBuffer<class_CGameCtnCampaign*> *param_1,CMwId *param_2)
{
{
  uint uVar1;
  int *piVar2;
  ulong uVar3;
  
  uVar1 = *(uint *)this;
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)(**(code **)(**(int **)(*(int *)((int)this + 4) + uVar3 * 4) + 0x14))();
      if ((piVar2 != (int *)0x0) && (*piVar2 == *(int *)param_1)) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0xffffffff;
}
}

