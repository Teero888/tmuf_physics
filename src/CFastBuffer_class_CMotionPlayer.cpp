// Class implementation: CFastBuffer_class_CMotionPlayer

// =================================================
// Function: >::GetNodFromId
// =================================================
CMotionPlayer * __thiscall
CFastBuffer<class_CMotionPlayer*>::GetNodFromId
          (void *this,CFastBuffer<class_CMotionPlayer*> *param_1,CMwId *param_2)
{
{
  ulong uVar1;
  CMwId *unaff_ESI;
  
  uVar1 = CFastBuffer<class_CGameCtnCampaign*>::GetNodIndexFromId
                    (this,(CFastBuffer<class_CGameCtnCampaign*> *)param_1,unaff_ESI);
  if (uVar1 == 0xffffffff) {
    return (CMotionPlayer *)0x0;
  }
  return *(CMotionPlayer **)(*(int *)((int)this + 4) + uVar1 * 4);
}
}

