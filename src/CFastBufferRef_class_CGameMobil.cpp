// Class implementation: CFastBufferRef_class_CGameMobil

// =================================================
// Function: CFastBufferRef<class_CGameMobil>::ReplaceByLastAt
// =================================================
void __thiscall
CFastBufferRef<class_CGameMobil>::ReplaceByLastAt
          (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3)
{
{
  CMwNod *pCVar1;
  int iVar2;
  CFastBufferRef<class_CGameMobil> *pCVar3;
  int iVar4;
  CFastBufferRef<class_CGameMobil> *pCVar5;
  CMwNod *unaff_EDI;
  int iVar6;
  
  pCVar3 = param_1;
  for (pCVar5 = param_1; pCVar5 < param_1 + param_2; pCVar5 = pCVar5 + 1) {
    iVar4 = *(int *)((int)this + 4);
    pCVar1 = *(CMwNod **)(iVar4 + (int)pCVar5 * 4);
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(pCVar1,unaff_EDI);
      *(undefined4 *)(iVar4 + (int)pCVar5 * 4) = 0;
      pCVar3 = (CFastBufferRef<class_CGameMobil> *)param_2;
    }
  }
  pCVar5 = (CFastBufferRef<class_CGameMobil> *)((*(int *)this - (int)pCVar3) - param_2);
  if (param_2 <= pCVar5) {
    pCVar5 = (CFastBufferRef<class_CGameMobil> *)param_2;
  }
  if (pCVar5 != (CFastBufferRef<class_CGameMobil> *)0x0) {
    iVar4 = (*(int *)this - (int)pCVar5) * 4;
    iVar6 = (int)param_1 * 4;
    param_1 = pCVar5;
    do {
      iVar2 = *(int *)((int)this + 4);
      pCVar1 = *(CMwNod **)(iVar2 + iVar4);
      if (pCVar1 != *(CMwNod **)(iVar6 + iVar2)) {
        if (pCVar1 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(pCVar1,unaff_EDI);
        }
        if (*(CMwNod **)(iVar6 + iVar2) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(iVar6 + iVar2),unaff_EDI);
        }
        *(CMwNod **)(iVar6 + iVar2) = pCVar1;
      }
      iVar2 = *(int *)((int)this + 4);
      pCVar1 = *(CMwNod **)(iVar2 + iVar4);
      if (pCVar1 != (CMwNod *)0x0) {
        CMwNod::MwRelease(pCVar1,unaff_EDI);
        *(undefined4 *)(iVar2 + iVar4) = 0;
      }
      iVar6 = iVar6 + 4;
      iVar4 = iVar4 + 4;
      param_1 = param_1 + -1;
    } while (param_1 != (CFastBufferRef<class_CGameMobil> *)0x0);
    *(ulong *)this = *(int *)this - param_2;
    return;
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

